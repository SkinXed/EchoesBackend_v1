// Исправленная строка 406 (и другие мелкие исправления)
using Microsoft.EntityFrameworkCore;
using Echoes.API.Data;
using Echoes.API.DTOs.ServerRequests;
using Echoes.API.DTOs.ServerResponses;
using Echoes.API.Models.Entities.GameServer;
using Echoes.API.Models.Entities.Universe;
using System.Net;
using Microsoft.EntityFrameworkCore.Storage;

namespace Echoes.API.Services
{
    public class GameServerService : IGameServerService
    {
        private readonly DatabaseContext _context;
        private readonly ILogger<GameServerService> _logger;
        private readonly object _balanceLock = new object();
        private readonly Dictionary<string, DateTime> _registrationAttempts = new();
        private readonly object _registrationLock = new();

        public GameServerService(DatabaseContext context, ILogger<GameServerService> logger)
        {
            _context = context;
            _logger = logger;
        }

        public async Task<GameServerNode> RegisterServerAsync(RegisterServerRequest request)
        {
            request.Validate();

            // Защита от слишком частых регистраций (не чаще чем раз в 5 секунд для одного InstanceId)
            lock (_registrationLock)
            {
                if (_registrationAttempts.TryGetValue(request.InstanceId, out var lastAttempt))
                {
                    var timeSinceLastAttempt = DateTime.UtcNow - lastAttempt;
                    if (timeSinceLastAttempt.TotalSeconds < 5)
                    {
                        _logger.LogWarning("Registration throttled for {InstanceId}. Last attempt: {TimeAgo} sec ago",
                            request.InstanceId, timeSinceLastAttempt.TotalSeconds);
                        throw new InvalidOperationException($"Registration throttled. Please wait 5 seconds between attempts.");
                    }
                }
                _registrationAttempts[request.InstanceId] = DateTime.UtcNow;
            }

            // Используем стратегию выполнения с повторными попытками
            var strategy = _context.Database.CreateExecutionStrategy();

            return await strategy.ExecuteAsync(async () =>
            {
                using var transaction = await _context.Database.BeginTransactionAsync();

                try
                {
                    // ЛОКАЛЬНАЯ ФУНКЦИЯ ДЛЯ БЕЗОПАСНОГО УДАЛЕНИЯ
                    async Task SafeRemoveAsync(GameServerNode entity, string reason)
                    {
                        try
                        {
                            _context.GameServers.Remove(entity);
                            await _context.SaveChangesAsync();
                            _logger.LogInformation("{Reason}. Removed Instance: {InstanceId}", reason, entity.InstanceId);
                        }
                        catch (DbUpdateConcurrencyException)
                        {
                            // Сервер уже удален параллельным запросом
                            _logger.LogWarning("Concurrency: Entity {InstanceId} was already deleted", entity.InstanceId);
                            _context.Entry(entity).State = EntityState.Detached;
                        }
                    }

                    // 1. ПРОВЕРКА: возможно, этот сервер уже зарегистрирован?
                    var existingServerWithSameId = await _context.GameServers
                        .FirstOrDefaultAsync(s => s.InstanceId == request.InstanceId);

                    if (existingServerWithSameId != null)
                    {
                        // Обновляем существующую запись вместо создания новой
                        _logger.LogInformation("Server {InstanceId} already exists, updating heartbeat", request.InstanceId);

                        existingServerWithSameId.LastHeartbeat = DateTime.UtcNow;
                        existingServerWithSameId.UpdatedAt = DateTime.UtcNow;

                        if (existingServerWithSameId.Status == ServerStatus.Starting)
                        {
                            existingServerWithSameId.Status = ServerStatus.Ready;
                        }

                        await _context.SaveChangesAsync();
                        await transaction.CommitAsync();

                        return existingServerWithSameId;
                    }

                    // 2. ПРОВЕРКА: есть ли сервер на том же IP:Port?
                    var serverOnSameAddress = await _context.GameServers
                        .FirstOrDefaultAsync(s => s.PublicIP == request.PublicIP &&
                                                 s.GamePort == request.GamePort);

                    if (serverOnSameAddress != null)
                    {
                        // Если это тот же физический сервер (перезапуск), используем его запись
                        _logger.LogInformation("Server at {IP}:{Port} already exists as {ExistingId}. Updating...",
                            request.PublicIP, request.GamePort, serverOnSameAddress.InstanceId);

                        // Обновляем InstanceId на новый и обновляем данные
                        serverOnSameAddress.InstanceId = request.InstanceId;
                        serverOnSameAddress.SolarSystemId = request.SolarSystemId;
                        serverOnSameAddress.RegionId = request.RegionId;
                        serverOnSameAddress.MaxPlayers = request.MaxPlayers;
                        serverOnSameAddress.GeoRegion = request.GeoRegion ?? "EU";
                        serverOnSameAddress.GameVersion = request.GameVersion ?? "1.0.0";
                        serverOnSameAddress.Hostname = request.Hostname ?? Environment.MachineName;
                        serverOnSameAddress.LastHeartbeat = DateTime.UtcNow;
                        serverOnSameAddress.Status = ServerStatus.Starting;
                        serverOnSameAddress.UpdatedAt = DateTime.UtcNow;

                        await _context.SaveChangesAsync();
                        await transaction.CommitAsync();

                        _logger.LogInformation("Updated existing server record: {InstanceId}", request.InstanceId);
                        return serverOnSameAddress;
                    }

                    // 3. Если это Dedicate-сервер для системы, удаляем старого владельца этой системы
                    if (request.SolarSystemId.HasValue)
                    {
                        var existingSystemServer = await _context.GameServers
                            .Where(s => s.SolarSystemId == request.SolarSystemId &&
                                       s.InstanceId != request.InstanceId)
                            .FirstOrDefaultAsync();

                        if (existingSystemServer != null)
                        {
                            bool isAlive = existingSystemServer.LastHeartbeat > DateTime.UtcNow.AddMinutes(-5);
                            string reason = isAlive
                                ? $"Overwriting ACTIVE server for System {request.SolarSystemId}"
                                : $"Removing DEAD server for System {request.SolarSystemId}";

                            await SafeRemoveAsync(existingSystemServer, reason);
                        }
                    }

                    // 4. Для региональных серверов - проверка лимитов
                    if (request.RegionId.HasValue)
                    {
                        const int MAX_SERVERS_PER_REGION = 5;
                        var regionalServersCount = await _context.GameServers
                            .CountAsync(s => s.RegionId == request.RegionId);

                        if (regionalServersCount >= MAX_SERVERS_PER_REGION)
                        {
                            var serverToRemove = await _context.GameServers
                                .Where(s => s.RegionId == request.RegionId)
                                .OrderBy(s => s.OnlinePlayers)
                                .ThenBy(s => s.CreatedAt)
                                .FirstOrDefaultAsync();

                            if (serverToRemove != null)
                            {
                                await SafeRemoveAsync(serverToRemove, "Auto-scaling regional servers");
                            }
                        }
                    }

                    // 5. СОЗДАНИЕ НОВОЙ ЗАПИСИ
                    var server = new GameServerNode
                    {
                        Id = Guid.NewGuid(),
                        InstanceId = request.InstanceId,
                        PublicIP = request.PublicIP,
                        GamePort = request.GamePort,
                        WebPort = request.WebPort,
                        SolarSystemId = request.SolarSystemId,
                        RegionId = request.RegionId,
                        Status = ServerStatus.Starting,
                        MaxPlayers = request.MaxPlayers,
                        GeoRegion = request.GeoRegion ?? "EU",
                        GameVersion = request.GameVersion ?? "1.0.0",
                        Hostname = request.Hostname ?? Environment.MachineName,
                        ServerTags = request.ServerTags,
                        StartupArguments = Environment.CommandLine,
                        LastHeartbeat = DateTime.UtcNow,
                        OnlinePlayers = 0,
                        CPUUsage = 0,
                        MemoryUsageMB = 0,
                        NetworkInKbps = 0,
                        NetworkOutKbps = 0,
                        CreatedAt = DateTime.UtcNow,
                        UpdatedAt = DateTime.UtcNow
                    };

                    _context.GameServers.Add(server);
                    await _context.SaveChangesAsync();
                    await transaction.CommitAsync();

                    string serverType = request.SolarSystemId.HasValue ? "DEDICATED" : "REGIONAL";
                    string location = request.SolarSystemId.HasValue
                        ? $"System: {request.SolarSystemId}"
                        : $"Region: {request.RegionId}";

                    _logger.LogInformation(
                        "Registered {Type} server: {InstanceId} for {Location} ({IP}:{Port})",
                        serverType, server.InstanceId, location, server.PublicIP, server.GamePort);

                    return server;
                }
                catch (Exception ex)
                {
                    await transaction.RollbackAsync();
                    _logger.LogError(ex, "Failed to register server {InstanceId}", request.InstanceId);

                    // Убираем из кэша при ошибке
                    lock (_registrationLock)
                    {
                        _registrationAttempts.Remove(request.InstanceId);
                    }

                    throw;
                }
            });
        }

      

        private async Task NotifyPlayersAboutMigrationAsync(string oldServerId, string newServerId)
        {
            try
            {
                _logger.LogInformation("Migration notification: {OldServer} -> {NewServer}",
                    oldServerId, newServerId);

                // Здесь можно реализовать реальное оповещение
                // Пока просто логируем
                await Task.CompletedTask; // Добавляем await для устранения warning
            }
            catch (Exception ex)
            {
                _logger.LogWarning(ex, "Failed to send migration notifications");
            }
        }

        private async Task PublishServerRegisteredEventAsync(GameServerNode server)
        {
            try
            {
                // Отправляем событие в систему мониторинга или брокер сообщений
                var eventData = new
                {
                    EventType = "ServerRegistered",
                    Timestamp = DateTime.UtcNow,
                    ServerId = server.Id,
                    InstanceId = server.InstanceId,
                    Location = server.SolarSystemId?.ToString() ?? server.RegionId?.ToString(),
                    Type = server.SolarSystemId.HasValue ? "Dedicated" : "Regional",
                    Address = $"{server.PublicIP}:{server.GamePort}",
                    MaxPlayers = server.MaxPlayers,
                    Hostname = server.Hostname,
                    Version = server.GameVersion
                };

                // TODO: Реализовать отправку через SignalR, Redis Pub/Sub или RabbitMQ
                // await _eventPublisher.PublishAsync("server.registered", eventData);

                _logger.LogDebug("Server registered event: {@Event}", eventData);

                await Task.CompletedTask; // Добавляем await для устранения warning
            }
            catch (Exception ex)
            {
                _logger.LogWarning(ex, "Failed to publish server registered event");
            }
        }

        public async Task<bool> UpdateHeartbeatAsync(HeartbeatRequest request)
        {
            var server = await _context.GameServers
                .FirstOrDefaultAsync(s => s.InstanceId == request.InstanceId);

            if (server == null)
            {
                _logger.LogWarning("Heartbeat failed: Server {InstanceId} not found", request.InstanceId);
                return false;
            }

            server.LastHeartbeat = DateTime.UtcNow;
            server.Status = request.Status;
            server.OnlinePlayers = request.OnlinePlayers;
            server.CPUUsage = request.CPUUsage;
            server.MemoryUsageMB = request.MemoryUsageMB;
            server.NetworkInKbps = request.NetworkInKbps;
            server.NetworkOutKbps = request.NetworkOutKbps;
            server.UpdatedAt = DateTime.UtcNow;

            // Автоматически помечаем как Ready при наличии игроков
            if (server.Status == ServerStatus.Starting && server.OnlinePlayers > 0)
            {
                server.Status = ServerStatus.Ready;
                _logger.LogInformation("Server {InstanceId} auto-promoted to Ready (Players: {Players})",
                    request.InstanceId, server.OnlinePlayers);
            }

            await _context.SaveChangesAsync();
            return true;
        }


        public async Task<ConnectionInfoResponse> GetConnectionForSystemAsync(Guid systemId)
        {
            try
            {
                _logger.LogInformation("Searching connection for system {SystemId}", systemId);

                // 1. Проверяем, существует ли система
                var systemInfo = await _context.SolarSystems
                    .Include(s => s.Constellation)
                    .ThenInclude(c => c.Region)
                    .FirstOrDefaultAsync(s => s.Id == systemId);

                if (systemInfo == null)
                    throw new ArgumentException($"System {systemId} not found in database");

                // 2. ЭТАП A: Ищем выделенный сервер для системы
                var dedicatedServer = await _context.GameServers
                    .Where(s => s.SolarSystemId == systemId &&
                               s.Status == ServerStatus.Ready &&
                               s.LastHeartbeat > DateTime.UtcNow.AddMinutes(-2) &&
                               s.OnlinePlayers < s.MaxPlayers)
                    .OrderBy(s => (float)s.OnlinePlayers / s.MaxPlayers)
                    .FirstOrDefaultAsync();

                if (dedicatedServer != null)
                {
                    _logger.LogInformation("Found DEDICATED server for system {SystemId}: {ServerId} ({IP}:{Port})",
                        systemId, dedicatedServer.InstanceId, dedicatedServer.PublicIP, dedicatedServer.GamePort);

                    return CreateConnectionResponse(dedicatedServer, systemId, "DedicatedSystem");
                }

                // 3. ЭТАП Б: Получаем ID региона через Constellation
                var regionId = systemInfo.Constellation?.RegionId;

                if (!regionId.HasValue)
                {
                    // Попробуем найти регион через прямое поле RegionId
                    if (systemInfo.RegionId != Guid.Empty)
                    {
                        regionId = systemInfo.RegionId;
                    }
                    else
                    {
                        throw new Exception($"Region not found for system {systemId}");
                    }
                }

                // 4. ЭТАП В: Ищем региональный сервер
                var regionalServers = await _context.GameServers
                    .Where(s => s.RegionId == regionId &&
                               s.Status == ServerStatus.Ready &&
                               s.LastHeartbeat > DateTime.UtcNow.AddMinutes(-2) &&
                               s.OnlinePlayers < s.MaxPlayers)
                    .ToListAsync();

                if (regionalServers.Any())
                {
                    var bestRegionalServer = regionalServers
                        .Select(s => new
                        {
                            Server = s,
                            Score = CalculateServerScore(s)
                        })
                        .OrderByDescending(x => x.Score)
                        .FirstOrDefault();

                    if (bestRegionalServer != null)
                    {
                        _logger.LogInformation("Found REGIONAL server for system {SystemId} (Region: {RegionId}): {ServerId}",
                            systemId, regionId, bestRegionalServer.Server.InstanceId);

                        return CreateConnectionResponse(bestRegionalServer.Server, systemId, "RegionalCluster");
                    }
                }

                // 5. ЭТАП Г: Ищем любой доступный сервер (fallback)
                var fallbackServer = await _context.GameServers
                    .Where(s => s.Status == ServerStatus.Ready &&
                               s.LastHeartbeat > DateTime.UtcNow.AddMinutes(-2) &&
                               s.OnlinePlayers < s.MaxPlayers)
                    .OrderBy(s => (float)s.OnlinePlayers / s.MaxPlayers)
                    .FirstOrDefaultAsync();

                if (fallbackServer != null)
                {
                    _logger.LogWarning("Using FALLBACK server for system {SystemId}: {ServerId} ({IP}:{Port})",
                        systemId, fallbackServer.InstanceId, fallbackServer.PublicIP, fallbackServer.GamePort);

                    return CreateConnectionResponse(fallbackServer, systemId, "Fallback");
                }

                throw new Exception($"No available servers for system {systemId}");
            }
            catch (ArgumentException ex)
            {
                _logger.LogError(ex, "System {SystemId} not found", systemId);
                throw;
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error finding connection for system {SystemId}", systemId);
                throw;
            }
        }

        private int CalculateServerScore(GameServerNode server)
        {
            int score = 1000;

            float loadPercentage = server.MaxPlayers > 0
                ? (float)server.OnlinePlayers / server.MaxPlayers
                : 1.0f;

            score -= (int)(loadPercentage * 500);

            var uptime = DateTime.UtcNow - server.CreatedAt;

            if (uptime.TotalMinutes > 30) score += 100;
            if (uptime.TotalHours > 1) score += 200;
            if (uptime.TotalHours > 24) score += 300;

            if (server.CPUUsage < 30) score += 100;
            if (server.CPUUsage < 10) score += 150;
            if (server.MemoryUsageMB < 4096) score += 50;

            if (server.GeoRegion == "EU") score += 50;

            if (server.Status == ServerStatus.Starting) score -= 100;
            if (server.Status == ServerStatus.Maintenance) score -= 200;

            if (uptime.TotalMinutes < 10) score += 50;

            return Math.Max(100, score);
        }

        private ConnectionInfoResponse CreateConnectionResponse(
            GameServerNode server,
            Guid systemId,
            string nodeType)
        {
            var loadPercentage = server.MaxPlayers > 0
                ? (int)((float)server.OnlinePlayers / server.MaxPlayers * 100)
                : 0;

            return new ConnectionInfoResponse
            {
                PublicIP = server.PublicIP,
                GamePort = server.GamePort,
                ServerInstanceId = server.InstanceId,
                RegionId = server.RegionId ?? Guid.Empty,
                NodeType = nodeType,
                RequiresReconnect = nodeType != "DedicatedSystem",
                CurrentSystemId = systemId,
                ServerLoadPercentage = loadPercentage,
                Priority = CalculateServerScore(server)
            };
        }

        public async Task<List<GameServerNode>> GetAllServersAsync()
        {
            return await _context.GameServers
                .Include(s => s.SolarSystem)
                .Include(s => s.Region)
                .Where(s => s.LastHeartbeat > DateTime.UtcNow.AddMinutes(-5))
                .OrderByDescending(s => s.Status)
                .ThenBy(s => s.OnlinePlayers)
                .ToListAsync();
        }

        public async Task<bool> UnregisterServerAsync(string instanceId)
        {
            var server = await _context.GameServers
                .FirstOrDefaultAsync(s => s.InstanceId == instanceId);

            if (server == null)
                return false;

            _context.GameServers.Remove(server);
            await _context.SaveChangesAsync();

            _logger.LogInformation("Unregistered server: {InstanceId}", instanceId);
            return true;
        }

    }

}
