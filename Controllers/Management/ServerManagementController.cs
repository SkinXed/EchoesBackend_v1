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

                return Ok(response);
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
                    return NotFound(new { error = "Server not found" });

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
                _logger.LogError(ex, "Error processing heartbeat");
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
        /// </summary>
        /// <param name="request">Configuration request including instance ID and solar system ID.</param>
        /// <returns>Configuration data for the requested solar system.</returns>
        [HttpPost("config")]
        public async Task<ActionResult<ServerConfigResponseDto>> GetServerConfig([FromBody] ServerConfigRequestDto request)
        {
            try
            {
                _logger.LogInformation("Config requested by {InstanceId} for System: {SystemId}", request.InstanceId, request.SolarSystemId);

                if (string.IsNullOrEmpty(request.SolarSystemId) || !Guid.TryParse(request.SolarSystemId, out var systemGuid))
                {
                    return BadRequest(new { error = "Valid SolarSystemId is required for DedicatedSystem mode" });
                }

                var system = await _context.SolarSystems
                    .Include(s => s.Planets)
                    .Include(s => s.Stargates)
                    .ThenInclude(sg => sg.DestinationSolarSystem)
                    .FirstOrDefaultAsync(s => s.Id == systemGuid);

                if (system == null)
                {
                    return NotFound(new { error = $"Solar System {systemGuid} not found" });
                }

                // Map data to format expected by UE5
                var configDto = new ServerSystemConfigDto
                {
                    SystemId = system.Id,
                    SystemName = system.Name,
                    SolarRadius = system.SolarRadius,
                    SolarMass = system.SolarMass,
                    Temperature = system.Temperature,
                    
                    Planets = system.Planets.Select(p => new PlanetConfigDto
                    {
                        Id = p.Id,
                        Name = p.Name,
                        Type = p.Type,
                        OrbitDistance = p.OrbitDistance,
                        Radius = p.Radius
                    }).ToList(),

                    Stargates = system.Stargates.Select(sg => new StargateConfigDto
                    {
                        Id = sg.Id,
                        Name = sg.Name,
                        TargetSystemId = sg.DestinationSolarSystemId,
                        TargetSystemName = sg.DestinationSolarSystem?.Name ?? "Unknown",
                        PositionX = sg.PositionX,
                        PositionY = sg.PositionY,
                        PositionZ = sg.PositionZ
                    }).ToList()
                };

                return Ok(new ServerConfigResponseDto { Config = configDto });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error generating server config");
                return StatusCode(500, new { error = "Internal server error" });
            }
        }
    }
}
