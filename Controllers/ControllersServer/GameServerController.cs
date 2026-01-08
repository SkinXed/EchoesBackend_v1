// Target framework: .NET 8.0 
// Required namespaces and dependencies
using Echoes.API.Data;
using Echoes.API.DTOs.ServerRequests;
using Echoes.API.Models.DTOs.ServerRequests;
using Echoes.API.Models.Entities.GameServer;
using Echoes.API.Models.Entities.Universe;
using Echoes.API.Services;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;

namespace Echoes.API.Controllers
{
    [ApiController]
    [Route("api/[controller]")]
    public class GameServerController : ControllerBase
    {
        private readonly DatabaseContext _context;
        private readonly IGameServerService _gameServerService;
        private readonly ILogger<GameServerController> _logger;

        public GameServerController(
            DatabaseContext context,
            IGameServerService gameServerService,
            ILogger<GameServerController> logger)
        {
            _context = context;
            _gameServerService = gameServerService;
            _logger = logger;

            {
                _context = context;
                _gameServerService = gameServerService;
                _logger = logger;
            }
        }

        [HttpPost("register")]
        public async Task<ActionResult> RegisterServer([FromBody] RegisterServerRequest request)
        {
            try
            {
                var server = await _gameServerService.RegisterServerAsync(request);

                return Ok(new
                {
                    success = true,
                    serverId = server.Id,
                    instanceId = server.InstanceId,
                    nodeType = server.RegionId.HasValue ? "RegionalCluster" : "DedicatedSystem",
                    message = "Server registered successfully"
                });
            }
            catch (ArgumentException ex)
            {
                return BadRequest(new { error = ex.Message });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error registering server");
                return StatusCode(500, new { error = "Internal server error" });
            }
        }
        [HttpPost("heartbeat")]
        public async Task<ActionResult> Heartbeat([FromBody] HeartbeatRequest request)
        {
            try
            {
                var success = await _gameServerService.UpdateHeartbeatAsync(request);

                if (!success)
                    return NotFound(new { error = "Server not found" });

                return Ok(new
                {
                    success = true,
                    timestamp = DateTime.UtcNow,
                    nextHeartbeatInSeconds = 30
                });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error processing heartbeat");
                return StatusCode(500, new { error = "Internal server error" });
            }
        }

        [HttpGet("systems/{systemId}")]
        public async Task<ActionResult> GetSystemData(Guid systemId)
        {
            try
            {
                var system = await _context.SolarSystems
                    .Include(s => s.Constellation)
                    .ThenInclude(c => c.Region)
                    .Include(s => s.Planets)
                    .Include(s => s.Stargates)
                    .ThenInclude(sg => sg.DestinationSolarSystem) // Важно: подгружаем DestinationSolarSystem
                    .FirstOrDefaultAsync(s => s.Id == systemId);

                if (system == null)
                    return NotFound(new { error = "Solar system not found" });

                return Ok(new
                {
                    system.Id,
                    system.Name,
                    system.SecurityStatus,
                    system.PositionX,
                    system.PositionY,
                    system.PositionZ,
                    system.Temperature,
                    system.SolarRadius,
                    system.SolarMass,
                    system.Luminosity,
                    Planets = system.Planets.Select(p => new
                    {
                        p.Id,
                        p.Name,
                        p.Type,
                        p.OrbitDistance,
                        p.Radius,
                        p.Mass,
                        p.Temperature,
                        p.HasAtmosphere,
                        p.AtmosphereType,
                        p.HasRings,
                        p.MoonCount
                    }),
                    Stargates = system.Stargates.Select(g => new
                    {
                        g.Id,
                        g.Name,
                        g.PositionX,
                        g.PositionY,
                        g.PositionZ,
                        TargetSystemId = g.DestinationSolarSystemId,
                        TargetSystemName = g.DestinationSolarSystem != null ? g.DestinationSolarSystem.Name : "Unknown"
                    }),
                    ConstellationName = system.Constellation?.Name,
                    RegionName = system.Constellation?.Region?.Name
                });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error getting system data");
                return StatusCode(500, new { error = "Internal server error" });
            }
        }

        [HttpGet("for-system/{systemId}")]
        public async Task<ActionResult> GetServerForSystem(Guid systemId)
        {
            try
            {
                var connectionInfo = await _gameServerService.GetConnectionForSystemAsync(systemId);

                return Ok(new
                {
                    connectionInfo.PublicIP,
                    connectionInfo.GamePort,
                    connectionInfo.ServerInstanceId,
                    connectionInfo.RegionId,
                    Type = connectionInfo.NodeType,
                    connectionInfo.RequiresReconnect,
                    connectionInfo.CurrentSystemId,
                    Load = connectionInfo.ServerLoadPercentage,
                    Priority = connectionInfo.Priority,
                    Timestamp = DateTime.UtcNow
                });
            }
            catch (ArgumentException ex)
            {
                return BadRequest(new { error = ex.Message });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error finding server for system {SystemId}", systemId);
                return StatusCode(500, new
                {
                    error = "Internal server error",
                    details = ex.Message
                });
            }
        }

        [HttpPost("request-connection")]
        public async Task<ActionResult> RequestConnection([FromBody] ConnectionRequest request)
        {
            try
            {
                if (string.IsNullOrEmpty(request.PlayerId))
                    return BadRequest(new { error = "PlayerId is required" });

                var connectionInfo = await _gameServerService.GetConnectionForSystemAsync(request.TargetSystemId);

                // Логируем запрос игрока
                _logger.LogInformation(
                    "Player {PlayerId} requesting connection to {SystemId} -> Server: {ServerId} (Type: {Type})",
                    request.PlayerId, request.TargetSystemId,
                    connectionInfo.ServerInstanceId, connectionInfo.NodeType);

                return Ok(new
                {
                    success = true,
                    connection = new
                    {
                        connectionInfo.PublicIP,
                        connectionInfo.GamePort,
                        connectionInfo.ServerInstanceId,
                        connectionInfo.NodeType,
                        connectionInfo.RequiresReconnect,
                        connectionInfo.CurrentSystemId
                    },
                    instructions = connectionInfo.RequiresReconnect
                        ? "ClientTravel required to different server"
                        : "Local teleport within current server",
                    timestamp = DateTime.UtcNow
                });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error in RequestConnection for player {PlayerId}", request.PlayerId);
                return StatusCode(500, new { error = ex.Message });
            }
        }

        [HttpGet("list")]
        public async Task<ActionResult> GetServers(
            [FromQuery] string? type = null, // "dedicated", "regional", "all"
            [FromQuery] Guid? regionId = null,
            [FromQuery] Guid? systemId = null,
            [FromQuery] bool? onlineOnly = true)
        {
            try
            {
                var query = _context.GameServers
                    .Include(s => s.SolarSystem)
                    .Include(s => s.Region)
                    .AsQueryable();

                // Фильтр по типу
                if (!string.IsNullOrEmpty(type))
                {
                    switch (type.ToLower())
                    {
                        case "dedicated":
                            query = query.Where(s => s.SolarSystemId != null);
                            break;
                        case "regional":
                            query = query.Where(s => s.RegionId != null);
                            break;
                    }
                }

                // Фильтр по региону
                if (regionId.HasValue)
                    query = query.Where(s => s.RegionId == regionId);

                // Фильтр по системе
                if (systemId.HasValue)
                    query = query.Where(s => s.SolarSystemId == systemId);

                // Только онлайн серверы
                if (onlineOnly == true)
                    query = query.Where(s => s.LastHeartbeat > DateTime.UtcNow.AddMinutes(-2));

                var servers = await query
    .Select(s => new
    {
        s.Id,
        s.InstanceId,
        s.PublicIP,
        s.GamePort,
        s.WebPort,
        s.Status,
        s.OnlinePlayers,
        s.MaxPlayers,
        LoadPercentage = (int)((float)s.OnlinePlayers / s.MaxPlayers * 100),
        s.LastHeartbeat,

        // --- ИСПРАВЛЕНИЕ 1: Сначала проверяем Регион ---
        // Если у сервера есть RegionId, он считается Региональным Кластером,
        // даже если он сейчас привязан к конкретной системе (хабу).
        Type = s.RegionId != null ? "RegionalCluster" :
               s.SolarSystemId != null ? "DedicatedSystem" : "Unknown",

        LocationName = s.SolarSystem != null ? s.SolarSystem.Name :
                      (s.Region != null ? s.Region.Name : "Unknown"),

        SolarSystemId = s.SolarSystemId,

        // --- ВАЖНО ---
        // Это поле будет в JSON. Если оно null в базе, сериализатор может его скрыть.
        RegionId = s.RegionId,

        UptimeMinutes = (int)(DateTime.UtcNow - s.CreatedAt).TotalMinutes,
        Health = s.CPUUsage < 80 && s.MemoryUsageMB < 8192 ? "Healthy" : "Stressed"
    })
    .OrderByDescending(s => s.Status == ServerStatus.Ready)
    .ThenBy(s => s.LoadPercentage)
    .ToListAsync();

                return Ok(new
                {
                    servers,
                    total = servers.Count,
                    online = servers.Count(s => s.Status == ServerStatus.Ready),
                    timestamp = DateTime.UtcNow
                });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error getting server list");
                return StatusCode(500, new { error = ex.Message });
            }
        }

        [HttpDelete("unregister/{instanceId}")]
        public async Task<ActionResult> UnregisterServer(string instanceId)
        {
            try
            {
                var success = await _gameServerService.UnregisterServerAsync(instanceId);

                if (!success)
                    return NotFound(new { error = "Server not found" });

                return Ok(new
                {
                    success = true,
                    message = $"Server {instanceId} unregistered successfully"
                });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error unregistering server {InstanceId}", instanceId);
                return StatusCode(500, new { error = ex.Message });
            }
        }

        [HttpGet("stats")]
        public async Task<ActionResult> GetStats()
        {
            try
            {
                var servers = await _context.GameServers
                    .Where(s => s.LastHeartbeat > DateTime.UtcNow.AddMinutes(-5))
                    .ToListAsync();

                var stats = new
                {
                    TotalServers = servers.Count,
                    OnlineServers = servers.Count(s => s.Status == ServerStatus.Ready),
                    StartingServers = servers.Count(s => s.Status == ServerStatus.Starting),
                    TotalPlayers = servers.Sum(s => s.OnlinePlayers),
                    MaxCapacity = servers.Sum(s => s.MaxPlayers),
                    Utilization = servers.Count > 0
                        ? (int)((float)servers.Sum(s => s.OnlinePlayers) / servers.Sum(s => s.MaxPlayers) * 100)
                        : 0,
                    ByType = new
                    {
                        Dedicated = servers.Count(s => s.SolarSystemId != null),
                        Regional = servers.Count(s => s.RegionId != null)
                    },
                    AverageLoad = servers.Count > 0
                        ? (int)servers.Average(s => (float)s.OnlinePlayers / s.MaxPlayers * 100)
                        : 0,
                    LastUpdated = DateTime.UtcNow
                };

                return Ok(stats);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error getting server stats");
                return StatusCode(500, new { error = ex.Message });
            }
        
    }
    [HttpGet("handshake")]
        public IActionResult Handshake()
        {
            return Ok(new
            {
                status = "ok",
                serverTime = DateTime.UtcNow,
                version = "1.0.0",
                message = "Echoes API Ready"
            });
        }
    }
}