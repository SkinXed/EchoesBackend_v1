using Echoes.API.Data;
using Echoes.API.Models.DTOs.Server;
using Echoes.API.Models.Entities.GameServer;
using Echoes.API.Services;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;

namespace Echoes.API.Controllers.Management
{
    /// <summary>
    /// Controller for game server management operations.
    /// Handles server registration, heartbeat, monitoring, and cluster management.
    /// Supports both DedicatedSystem and RegionalCluster deployment modes.
    /// </summary>
    [ApiController]
    [Route("api/server-management")]
    public class ServerManagementController : ControllerBase
    {
        private readonly DatabaseContext _context;
        private readonly IGameServerService _gameServerService;
        private readonly ILogger<ServerManagementController> _logger;

        public ServerManagementController(
            DatabaseContext context,
            IGameServerService gameServerService,
            ILogger<ServerManagementController> logger)
        {
            _context = context;
            _gameServerService = gameServerService;
            _logger = logger;
        }

        /// <summary>
        /// Register a new game server instance with the backend.
        /// Must be called when a game server starts up.
        /// </summary>
        /// <param name="request">Server registration details.</param>
        /// <returns>Registration confirmation with server ID.</returns>
        [HttpPost("register")]
        public async Task<ActionResult<RegisterServerResponseDto>> RegisterServer([FromBody] RegisterServerRequestDto request)
        {
            try
            {
                // Map DTO to existing service model
                var serviceRequest = new Echoes.API.DTOs.ServerRequests.RegisterServerRequest
                {
                    InstanceId = request.InstanceId,
                    PublicIP = request.PublicIP,
                    GamePort = request.GamePort,
                    WebPort = request.WebPort,
                    SolarSystemId = request.SolarSystemId,
                    RegionId = request.RegionId,
                    MaxPlayers = request.MaxPlayers,
                    GeoRegion = request.GeoRegion,
                    GameVersion = request.GameVersion,
                    Hostname = request.Hostname,
                    ServerTags = request.ServerTags
                };

                var server = await _gameServerService.RegisterServerAsync(serviceRequest);

                var response = new RegisterServerResponseDto
                {
                    Success = true,
                    ServerId = server.Id,
                    InstanceId = server.InstanceId,
                    NodeType = server.RegionId.HasValue ? "RegionalCluster" : "DedicatedSystem",
                    Message = "Server registered successfully"
                };

                _logger.LogInformation(
                    "Server {InstanceId} registered successfully. Type: {NodeType}, Players: {MaxPlayers}",
                    server.InstanceId, response.NodeType, server.MaxPlayers);

                return Ok(response);
            }
            catch (ArgumentException ex)
            {
                _logger.LogWarning(ex, "Validation error registering server");
                return BadRequest(new { error = ex.Message });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error registering server");
                return StatusCode(500, new { error = "Internal server error" });
            }
        }

        /// <summary>
        /// Update server status via heartbeat.
        /// Game servers should call this endpoint periodically (e.g., every 30 seconds).
        /// </summary>
        /// <param name="request">Heartbeat data including current status and metrics.</param>
        /// <returns>Acknowledgment with timing information.</returns>
        [HttpPost("heartbeat")]
        public async Task<ActionResult<HeartbeatResponseDto>> Heartbeat([FromBody] HeartbeatRequestDto request)
        {
            try
            {
                // Validate instance ID
                if (string.IsNullOrEmpty(request.InstanceId))
                {
                    return BadRequest(new { error = "InstanceId is required" });
                }

                // Map DTO to existing service model
                var serviceRequest = new Echoes.API.DTOs.ServerRequests.HeartbeatRequest
                {
                    InstanceId = request.InstanceId,
                    Status = request.Status,
                    OnlinePlayers = request.OnlinePlayers,
                    CPUUsage = request.CPUUsage,
                    MemoryUsageMB = request.MemoryUsageMB,
                    NetworkInKbps = request.NetworkInKbps,
                    NetworkOutKbps = request.NetworkOutKbps
                };

                var success = await _gameServerService.UpdateHeartbeatAsync(serviceRequest);

                if (!success)
                {
                    _logger.LogWarning("Heartbeat received from unregistered server: {InstanceId}", request.InstanceId);
                    return NotFound(new { error = "Server not found" });
                }

                var response = new HeartbeatResponseDto
                {
                    Success = true,
                    Timestamp = DateTime.UtcNow,
                    NextHeartbeatInSeconds = 30
                };

                return Ok(response);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error processing heartbeat from {InstanceId}", request?.InstanceId);
                return StatusCode(500, new { error = "Internal server error" });
            }
        }

        /// <summary>
        /// Unregister a game server instance.
        /// Should be called when a server is shutting down gracefully.
        /// </summary>
        /// <param name="instanceId">Unique instance ID of the server to unregister.</param>
        /// <returns>Confirmation of unregistration.</returns>
        [HttpDelete("unregister/{instanceId}")]
        public async Task<ActionResult> UnregisterServer(string instanceId)
        {
            try
            {
                if (string.IsNullOrEmpty(instanceId))
                {
                    return BadRequest(new { error = "InstanceId is required" });
                }

                var success = await _gameServerService.UnregisterServerAsync(instanceId);

                if (!success)
                {
                    _logger.LogWarning("Unregister request for non-existent server: {InstanceId}", instanceId);
                    return NotFound(new { error = "Server not found" });
                }

                _logger.LogInformation("Server {InstanceId} unregistered successfully", instanceId);

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

        /// <summary>
        /// List all registered game servers with optional filtering.
        /// Used for monitoring and management dashboards.
        /// </summary>
        /// <param name="type">Filter by server type: "dedicated", "regional", or "all".</param>
        /// <param name="regionId">Filter by specific region ID.</param>
        /// <param name="systemId">Filter by specific solar system ID.</param>
        /// <param name="onlineOnly">If true, only return servers with recent heartbeat.</param>
        /// <returns>List of game servers matching the filters.</returns>
        [HttpGet("list")]
        public async Task<ActionResult<ServerListResponseDto>> GetServers(
            [FromQuery] string? type = null,
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

                // Filter by type
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

                // Filter by region
                if (regionId.HasValue)
                    query = query.Where(s => s.RegionId == regionId);

                // Filter by system
                if (systemId.HasValue)
                    query = query.Where(s => s.SolarSystemId == systemId);

                // Only online servers
                if (onlineOnly == true)
                    query = query.Where(s => s.LastHeartbeat > DateTime.UtcNow.AddMinutes(-2));

                var servers = await query
                    .Select(s => new ServerListItemDto
                    {
                        Id = s.Id,
                        InstanceId = s.InstanceId,
                        PublicIP = s.PublicIP,
                        GamePort = s.GamePort,
                        WebPort = s.WebPort,
                        Status = s.Status,
                        OnlinePlayers = s.OnlinePlayers,
                        MaxPlayers = s.MaxPlayers,
                        LoadPercentage = (int)((float)s.OnlinePlayers / s.MaxPlayers * 100),
                        LastHeartbeat = s.LastHeartbeat,
                        Type = s.RegionId != null ? "RegionalCluster" :
                               s.SolarSystemId != null ? "DedicatedSystem" : "Unknown",
                        LocationName = s.SolarSystem != null ? s.SolarSystem.Name :
                                      (s.Region != null ? s.Region.Name : "Unknown"),
                        SolarSystemId = s.SolarSystemId,
                        RegionId = s.RegionId,
                        UptimeMinutes = (int)(DateTime.UtcNow - s.CreatedAt).TotalMinutes,
                        Health = s.CPUUsage < 80 && s.MemoryUsageMB < 8192 ? "Healthy" : "Stressed"
                    })
                    .OrderByDescending(s => s.Status == ServerStatus.Ready)
                    .ThenBy(s => s.LoadPercentage)
                    .ToListAsync();

                var response = new ServerListResponseDto
                {
                    Servers = servers,
                    Total = servers.Count,
                    Online = servers.Count(s => s.Status == ServerStatus.Ready),
                    Timestamp = DateTime.UtcNow
                };

                _logger.LogInformation(
                    "Server list retrieved: Total={Total}, Online={Online}, Type={Type}",
                    response.Total, response.Online, type ?? "all");

                return Ok(response);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error getting server list");
                return StatusCode(500, new { error = ex.Message });
            }
        }

        /// <summary>
        /// Get aggregated statistics about all game servers.
        /// Provides metrics for monitoring dashboards.
        /// </summary>
        /// <returns>Server statistics including player counts and capacity.</returns>
        [HttpGet("stats")]
        public async Task<ActionResult<ServerStatsDto>> GetStats()
        {
            try
            {
                var servers = await _context.GameServers
                    .Where(s => s.LastHeartbeat > DateTime.UtcNow.AddMinutes(-5))
                    .ToListAsync();

                if (servers.Count == 0)
                {
                    return Ok(new ServerStatsDto
                    {
                        TotalServers = 0,
                        OnlineServers = 0,
                        StartingServers = 0,
                        TotalPlayers = 0,
                        MaxCapacity = 0,
                        Utilization = 0,
                        ByType = new ServerTypeBreakdown { Dedicated = 0, Regional = 0 },
                        AverageLoad = 0,
                        LastUpdated = DateTime.UtcNow
                    });
                }

                var stats = new ServerStatsDto
                {
                    TotalServers = servers.Count,
                    OnlineServers = servers.Count(s => s.Status == ServerStatus.Ready),
                    StartingServers = servers.Count(s => s.Status == ServerStatus.Starting),
                    TotalPlayers = servers.Sum(s => s.OnlinePlayers),
                    MaxCapacity = servers.Sum(s => s.MaxPlayers),
                    Utilization = servers.Count > 0
                        ? (int)((float)servers.Sum(s => s.OnlinePlayers) / servers.Sum(s => s.MaxPlayers) * 100)
                        : 0,
                    ByType = new ServerTypeBreakdown
                    {
                        Dedicated = servers.Count(s => s.SolarSystemId != null),
                        Regional = servers.Count(s => s.RegionId != null)
                    },
                    AverageLoad = servers.Count > 0
                        ? (int)servers.Average(s => (float)s.OnlinePlayers / s.MaxPlayers * 100)
                        : 0,
                    LastUpdated = DateTime.UtcNow
                };

                _logger.LogInformation(
                    "Server stats calculated: Total={Total}, Online={Online}, Players={Players}/{Capacity}",
                    stats.TotalServers, stats.OnlineServers, stats.TotalPlayers, stats.MaxCapacity);

                return Ok(stats);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error getting server stats");
                return StatusCode(500, new { error = ex.Message });
            }
        }

        /// <summary>
        /// Provides configuration for a game server instance (system data, stargates, etc.)
        /// Supports both DedicatedSystem and RegionalCluster modes.
        /// </summary>
        /// <param name="request">Configuration request including instance ID and solar system ID or region ID.</param>
        /// <returns>Configuration data for the requested solar system or region.</returns>
        [HttpPost("config")]
        public async Task<ActionResult> GetServerConfig([FromBody] ServerConfigRequestDto request)
        {
            try
            {
                // Validate required fields
                if (string.IsNullOrEmpty(request.InstanceId))
                {
                    return BadRequest(new { error = "InstanceId is required" });
                }

                if (string.IsNullOrEmpty(request.ServerType))
                {
                    return BadRequest(new { error = "ServerType is required" });
                }

                _logger.LogInformation(
                    "Config requested by {InstanceId} (Type: {ServerType}) for System/Region: {LocationId}",
                    request.InstanceId, request.ServerType, request.SolarSystemId ?? request.RegionId?.ToString());

                if (string.Equals(request.ServerType, "DedicatedSystem", StringComparison.OrdinalIgnoreCase))
                {
                    return await GetDedicatedSystemConfig(request);
                }
                else if (string.Equals(request.ServerType, "RegionalCluster", StringComparison.OrdinalIgnoreCase))
                {
                    return await GetRegionalClusterConfig(request);
                }
                else
                {
                    return BadRequest(new { error = "ServerType must be 'DedicatedSystem' or 'RegionalCluster'" });
                }
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error generating server config");
                return StatusCode(500, new { error = "Internal server error" });
            }
        }

        /// <summary>
        /// Get configuration for a single solar system (DedicatedSystem mode).
        /// Each server hosts one complete solar system.
        /// </summary>
        private async Task<ActionResult> GetDedicatedSystemConfig(ServerConfigRequestDto request)
        {
            if (string.IsNullOrEmpty(request.SolarSystemId) || !Guid.TryParse(request.SolarSystemId, out var systemGuid))
            {
                return BadRequest(new { error = "Valid SolarSystemId is required" });
            }

            var system = await _context.SolarSystems
                .Include(s => s.Constellation).ThenInclude(c => c.Region)
                .Include(s => s.Planets).ThenInclude(p => p.Moons)
                .Include(s => s.Planets).ThenInclude(p => p.Resources)
                .Include(s => s.Stargates).ThenInclude(sg => sg.DestinationSolarSystem)
                .Include(s => s.Stations)
                .Include(s => s.AsteroidBelts).ThenInclude(ab => ab.Resources)
                .Include(s => s.Anomalies)
                .Include(s => s.SourceWormholes)
                .Include(s => s.TargetWormholes)
                .FirstOrDefaultAsync(s => s.Id == systemGuid);

            if (system == null)
            {
                return NotFound(new { error = $"Solar System {systemGuid} not found" });
            }

            var configDto = new ServerSystemConfigDto
            {
                SystemId = system.Id,
                SystemName = system.Name,
                SolarRadius = system.SolarRadius,
                SolarMass = system.SolarMass,
                Temperature = system.Temperature,
                Luminosity = system.Luminosity,
                SecurityStatus = system.SecurityStatus,
                // --- ВАЖНО: Заполняем StarClass ---
                StarClass = system.StarClass.ToString(),

                ConstellationId = system.ConstellationId,
                ConstellationName = system.Constellation?.Name ?? "Unknown",
                RegionId = system.Constellation?.RegionId,
                RegionName = system.Constellation?.Region?.Name ?? "Unknown",
                PositionX = system.PositionX,
                PositionY = system.PositionY,
                PositionZ = system.PositionZ,

                Planets = system.Planets.Select(p => new PlanetConfigDto
                {
                    Id = p.Id,
                    Name = p.Name,
                    Type = p.Type.ToString(),
                    OrbitDistance = p.OrbitDistance,
                    Radius = p.Radius,
                    PositionX = p.PositionX,
                    PositionY = p.PositionY,
                    PositionZ = p.PositionZ,
                    Moons = p.Moons.Select(m => new MoonConfigDto
                    {
                        Id = m.Id,
                        Name = m.Name,
                        Radius = m.Radius,
                        PositionX = m.PositionX,
                        PositionY = m.PositionY,
                        PositionZ = m.PositionZ
                    }).ToList(),
                    Resources = p.Resources.Select(r => new ResourceConfigDto
                    {
                        Id = r.Id,
                        ResourceType = r.ResourceType.ToString(),
                        Quantity = r.Quantity,
                        Richness = r.Quality
                    }).ToList()
                }).ToList(),

                Stargates = system.Stargates.Select(sg => new StargateConfigDto
                {
                    Id = sg.Id,
                    Name = sg.Name,
                    TargetSystemId = sg.DestinationSolarSystemId,
                    TargetSystemName = sg.DestinationSolarSystem?.Name ?? "Unknown",
                    PositionX = sg.PositionX,
                    PositionY = sg.PositionY,
                    PositionZ = sg.PositionZ,
                    IsOperational = sg.IsOperational,
                   
                    JumpCost = sg.JumpCost,
                    Model = sg.Model ?? "DefaultGate"
                }).ToList(),

                Stations = system.Stations.Select(st => new StationConfigDto
                {
                    Id = st.Id,
                    Name = st.Name,
                    PositionX = st.PositionX,
                    PositionY = st.PositionY,
                    PositionZ = st.PositionZ,
                    StationType = st.Type.ToString()
                }).ToList(),

                AsteroidBelts = system.AsteroidBelts.Select(ab => new AsteroidBeltConfigDto
                {
                    Id = ab.Id,
                    Name = ab.Name,
                    PositionX = ab.PositionX,
                    PositionY = ab.PositionY,
                    PositionZ = ab.PositionZ,
                    Resources = ab.Resources.Select(r => new ResourceConfigDto
                    {
                        Id = r.Id,
                        ResourceType = r.ResourceType.ToString(),
                        Quantity = r.Quantity,
                        Richness = r.Quality
                    }).ToList()
                }).ToList(),

                // --- ВАЖНО: Заполняем Аномалии и Червоточины ---
                Anomalies = system.Anomalies.Select(a => new AnomalyConfigDto
                {
                    Id = a.Id,
                    Name = a.Name,
                    Type = a.Type.ToString(),
                    Difficulty = a.Difficulty.ToString(),
                    PositionX = a.PositionX,
                    PositionY = a.PositionY,
                    PositionZ = a.PositionZ
                }).ToList(),

                Wormholes = system.TargetWormholes.Select(w => new WormholeConfigDto
                {
                    Id = w.Id,
                    Name = w.Name,
                    TargetSystemId = w.TargetSystemId,
                    PositionX = w.PositionX,
                    PositionY = w.PositionY,
                    PositionZ = w.PositionZ
                }).ToList()
            };

            _logger.LogInformation(
                "Sending DedicatedSystem config for {SystemName}: {PlanetCount} planets, {StargateCount} stargates, {StationCount} stations",
                system.Name, system.Planets.Count, system.Stargates.Count, system.Stations.Count);

            return Ok(new ServerConfigResponseDto { Config = configDto });
        }


        /// <summary>
        /// Get configuration for a region (RegionalCluster mode).
        /// Server hosts all systems within a region for load balancing.
        /// This is optimized for multi-system server instances.
        /// </summary>
        private async Task<ActionResult> GetRegionalClusterConfig(ServerConfigRequestDto request)
        {
            // Validate RegionId
            if (!request.RegionId.HasValue)
            {
                return BadRequest(new { error = "RegionId is required for RegionalCluster mode" });
            }

            var region = await _context.Regions
                .Include(r => r.Constellations)
                    .ThenInclude(c => c.SolarSystems)
                        .ThenInclude(s => s.Constellation)
                .Include(r => r.Constellations)
                    .ThenInclude(c => c.SolarSystems)
                        .ThenInclude(s => s.Planets)
                            .ThenInclude(p => p.Moons)
                .Include(r => r.Constellations)
                    .ThenInclude(c => c.SolarSystems)
                        .ThenInclude(s => s.Planets)
                            .ThenInclude(p => p.Resources)
                .Include(r => r.Constellations)
                    .ThenInclude(c => c.SolarSystems)
                        .ThenInclude(s => s.Stargates)
                            .ThenInclude(sg => sg.DestinationSolarSystem)
                .Include(r => r.Constellations)
                    .ThenInclude(c => c.SolarSystems)
                        .ThenInclude(s => s.Stations)
                .Include(r => r.Constellations)
                    .ThenInclude(c => c.SolarSystems)
                        .ThenInclude(s => s.AsteroidBelts)
                            .ThenInclude(ab => ab.Resources)
                .FirstOrDefaultAsync(r => r.Id == request.RegionId);

            if (region == null)
            {
                return NotFound(new { error = $"Region {request.RegionId} not found" });
            }

            // Flatten all systems from all constellations in the region
            var allSystems = region.Constellations
                .SelectMany(c => c.SolarSystems)
                .ToList();

            if (allSystems.Count == 0)
            {
                return BadRequest(new { error = $"Region {region.Name} contains no solar systems" });
            }

            // Build regional cluster configuration
            var systemConfigs = allSystems.Select(system => new ServerSystemConfigDto
            {
                SystemId = system.Id,
                SystemName = system.Name,
                SolarRadius = system.SolarRadius,
                SolarMass = system.SolarMass,
                Temperature = system.Temperature,
                Luminosity = system.Luminosity,
                SecurityStatus = system.SecurityStatus,
                ConstellationId = system.ConstellationId,
                ConstellationName = system.Constellation?.Name ?? "Unknown",
                RegionId = region.Id,
                RegionName = region.Name,
                PositionX = system.PositionX,
                PositionY = system.PositionY,
                PositionZ = system.PositionZ,

                Planets = system.Planets.Select(p => new PlanetConfigDto
                {
                    Id = p.Id,
                    Name = p.Name,
                    Type = p.Type,
                    OrbitDistance = p.OrbitDistance,
                    Radius = p.Radius,
                    PositionX = p.PositionX,
                    PositionY = p.PositionY,
                    PositionZ = p.PositionZ,
                    Moons = p.Moons.Select(m => new MoonConfigDto
                    {
                        Id = m.Id,
                        Name = m.Name,
                        Radius = m.Radius,
                        PositionX = m.PositionX,
                        PositionY = m.PositionY,
                        PositionZ = m.PositionZ
                    }).ToList(),
                    Resources = p.Resources.Select(r => new ResourceConfigDto
                    {
                        Id = r.Id,
                        ResourceType = r.ResourceType,
                        Quantity = r.Quantity,
                        Richness = r.Quality
                    }).ToList()
                }).ToList(),

                Stargates = system.Stargates.Select(sg => new StargateConfigDto
                {
                    Id = sg.Id,
                    Name = sg.Name,
                    TargetSystemId = sg.DestinationSolarSystemId,
                    TargetSystemName = sg.DestinationSolarSystem?.Name ?? "Unknown",
                    PositionX = sg.PositionX,
                    PositionY = sg.PositionY,
                    PositionZ = sg.PositionZ,
                    IsOperational = sg.IsOperational
                }).ToList(),

                Stations = system.Stations.Select(st => new StationConfigDto
                {
                    Id = st.Id,
                    Name = st.Name,
                    PositionX = st.PositionX,
                    PositionY = st.PositionY,
                    PositionZ = st.PositionZ,
                    StationType = st.Type.ToString()
                }).ToList(),

                AsteroidBelts = system.AsteroidBelts.Select(ab => new AsteroidBeltConfigDto
                {
                    Id = ab.Id,
                    Name = ab.Name,
                    PositionX = ab.PositionX,
                    PositionY = ab.PositionY,
                    PositionZ = ab.PositionZ,
                    Resources = ab.Resources.Select(r => new ResourceConfigDto
                    {
                        Id = r.Id,
                        ResourceType = r.ResourceType,
                        Quantity = r.Quantity,
                        Richness = r.Quality
                    }).ToList()
                }).ToList()
            }).ToList();

            var regionalConfig = new ServerRegionalClusterConfigDto
            {
                RegionId = region.Id,
                RegionName = region.Name,
                RegionCode = region.RegionCode,
                AverageSecurity = region.AverageSecurity,
                ConstellationCount = region.Constellations.Count,
                SystemCount = allSystems.Count,
                TotalPlanets = allSystems.Sum(s => s.Planets.Count),
                TotalStargates = allSystems.Sum(s => s.Stargates.Count),
                TotalStations = allSystems.Sum(s => s.Stations.Count),
                Systems = systemConfigs
            };

            _logger.LogInformation(
                "Sending RegionalCluster config for {RegionName}: {ConstellationCount} constелляций, " +
                "{SystemCount} систем, {PlanetCount} планет, {StargateCount} старательных врат, {StationCount} станций",
                region.Name, region.Constellations.Count, allSystems.Count,
                regionalConfig.TotalPlanets, regionalConfig.TotalStargates, regionalConfig.TotalStations);

            return Ok(new ServerRegionalClusterConfigResponseDto { Config = regionalConfig });
        }
    }
}
