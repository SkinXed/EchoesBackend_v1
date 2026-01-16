// Controllers/Management/ServerManagementController.cs
// Handles server administration and management endpoints
// Refactored from GameServerController for separation of concerns

using Echoes.API.Data;
using Echoes.API.Models.DTOs.Server;
using Echoes.API.Models.Entities.GameServer;
using Echoes.API.Services;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;

namespace Echoes.API.Controllers.Management
{
    /// <summary>
    /// Controller for server management and administration operations.
    /// Handles server registration, heartbeats, statistics, and monitoring.
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
        /// Registers a new game server instance with the API.
        /// Called by game servers on startup to announce their availability.
        /// </summary>
        /// <param name="request">Server registration details including IP, ports, and capacity</param>
        /// <returns>Registration confirmation with server ID and type</returns>
        /// <response code="200">Server registered successfully</response>
        /// <response code="400">Invalid registration request</response>
        /// <response code="500">Internal server error</response>
        [HttpPost("register")]
        [ProducesResponseType(typeof(object), 200)]
        [ProducesResponseType(typeof(object), 400)]
        [ProducesResponseType(typeof(object), 500)]
        public async Task<ActionResult> RegisterServer([FromBody] RegisterServerRequest request)
        {
            try
            {
                _logger.LogInformation("Server registration request from {InstanceId}", request.InstanceId);
                
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
                _logger.LogWarning(ex, "Invalid registration request from {InstanceId}", request.InstanceId);
                return BadRequest(new { success = false, error = ex.Message });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error registering server {InstanceId}", request.InstanceId);
                return StatusCode(500, new { success = false, error = "Internal server error" });
            }
        }

        /// <summary>
        /// Updates server heartbeat and metrics.
        /// Called periodically by game servers to report their status.
        /// </summary>
        /// <param name="request">Heartbeat data including status, player count, and resource usage</param>
        /// <returns>Heartbeat acknowledgment with next heartbeat interval</returns>
        /// <response code="200">Heartbeat processed successfully</response>
        /// <response code="404">Server not found</response>
        /// <response code="500">Internal server error</response>
        [HttpPost("heartbeat")]
        [ProducesResponseType(typeof(object), 200)]
        [ProducesResponseType(typeof(object), 404)]
        [ProducesResponseType(typeof(object), 500)]
        public async Task<ActionResult> Heartbeat([FromBody] HeartbeatRequest request)
        {
            try
            {
                var success = await _gameServerService.UpdateHeartbeatAsync(request);

                if (!success)
                {
                    _logger.LogWarning("Heartbeat failed: Server {InstanceId} not found", request.InstanceId);
                    return NotFound(new { success = false, error = "Server not found" });
                }

                return Ok(new
                {
                    success = true,
                    timestamp = DateTime.UtcNow,
                    nextHeartbeatInSeconds = 30
                });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error processing heartbeat from {InstanceId}", request.InstanceId);
                return StatusCode(500, new { success = false, error = "Internal server error" });
            }
        }

        /// <summary>
        /// Unregisters a game server instance.
        /// Called when a server is shutting down gracefully.
        /// </summary>
        /// <param name="instanceId">Unique identifier of the server to unregister</param>
        /// <returns>Unregistration confirmation</returns>
        /// <response code="200">Server unregistered successfully</response>
        /// <response code="404">Server not found</response>
        /// <response code="500">Internal server error</response>
        [HttpDelete("unregister/{instanceId}")]
        [ProducesResponseType(typeof(object), 200)]
        [ProducesResponseType(typeof(object), 404)]
        [ProducesResponseType(typeof(object), 500)]
        public async Task<ActionResult> UnregisterServer(string instanceId)
        {
            try
            {
                _logger.LogInformation("Unregistering server {InstanceId}", instanceId);
                
                var success = await _gameServerService.UnregisterServerAsync(instanceId);

                if (!success)
                {
                    _logger.LogWarning("Unregister failed: Server {InstanceId} not found", instanceId);
                    return NotFound(new { success = false, error = "Server not found" });
                }

                return Ok(new
                {
                    success = true,
                    message = $"Server {instanceId} unregistered successfully"
                });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error unregistering server {InstanceId}", instanceId);
                return StatusCode(500, new { success = false, error = "Internal server error" });
            }
        }

        /// <summary>
        /// Retrieves overall server cluster statistics.
        /// Provides metrics about total servers, capacity, and utilization.
        /// </summary>
        /// <returns>Server cluster statistics</returns>
        /// <response code="200">Statistics retrieved successfully</response>
        /// <response code="500">Internal server error</response>
        [HttpGet("stats")]
        [ProducesResponseType(typeof(ServerStatsResponse), 200)]
        [ProducesResponseType(typeof(object), 500)]
        public async Task<ActionResult<ServerStatsResponse>> GetStats()
        {
            try
            {
                var servers = await _context.GameServers
                    .Where(s => s.LastHeartbeat > DateTime.UtcNow.AddMinutes(-5))
                    .ToListAsync();

                var stats = new ServerStatsResponse
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
                return StatusCode(500, new { success = false, error = "Internal server error" });
            }
        }

        /// <summary>
        /// Lists all registered game servers with optional filtering.
        /// Supports filtering by type, region, system, and online status.
        /// </summary>
        /// <param name="type">Filter by server type: "dedicated", "regional", or "all"</param>
        /// <param name="regionId">Filter by specific region ID</param>
        /// <param name="systemId">Filter by specific solar system ID</param>
        /// <param name="onlineOnly">Include only servers that are currently online</param>
        /// <returns>List of servers matching the filters</returns>
        /// <response code="200">Server list retrieved successfully</response>
        /// <response code="500">Internal server error</response>
        [HttpGet("list")]
        [ProducesResponseType(typeof(ServerListResponse), 200)]
        [ProducesResponseType(typeof(object), 500)]
        public async Task<ActionResult<ServerListResponse>> GetServers(
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

                // Filter online only
                if (onlineOnly == true)
                    query = query.Where(s => s.LastHeartbeat > DateTime.UtcNow.AddMinutes(-2));

                var servers = await query
                    .Select(s => new ServerListItem
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

                var response = new ServerListResponse
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
                return StatusCode(500, new { success = false, error = "Internal server error" });
            }
        }
    }
}
