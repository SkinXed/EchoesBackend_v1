// Controllers/Gameplay/GameServerController.cs
// Handles gameplay-related endpoints for clients
// Refactored from GameServerController for separation of concerns

using Echoes.API.Data;
using Echoes.API.Models.DTOs.Server;
using Echoes.API.Services;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;

namespace Echoes.API.Controllers.Gameplay
{
    /// <summary>
    /// Controller for gameplay operations and client connection management.
    /// Handles system data retrieval and server connection requests.
    /// </summary>
    [ApiController]
    [Route("api/gameserver")]
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
        }

        /// <summary>
        /// Retrieves detailed information about a solar system.
        /// Used by game clients to get system data including planets and stargates.
        /// </summary>
        /// <param name="systemId">Unique identifier of the solar system</param>
        /// <returns>Detailed solar system information</returns>
        /// <response code="200">System data retrieved successfully</response>
        /// <response code="404">Solar system not found</response>
        /// <response code="500">Internal server error</response>
        [HttpGet("systems/{systemId}")]
        [ProducesResponseType(typeof(object), 200)]
        [ProducesResponseType(typeof(object), 404)]
        [ProducesResponseType(typeof(object), 500)]
        public async Task<ActionResult> GetSystemData(Guid systemId)
        {
            try
            {
                var system = await _context.SolarSystems
                    .Include(s => s.Constellation)
                    .ThenInclude(c => c.Region)
                    .Include(s => s.Planets)
                    .Include(s => s.Stargates)
                    .ThenInclude(sg => sg.DestinationSolarSystem)
                    .FirstOrDefaultAsync(s => s.Id == systemId);

                if (system == null)
                {
                    _logger.LogWarning("Solar system {SystemId} not found", systemId);
                    return NotFound(new { success = false, error = "Solar system not found" });
                }

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
                _logger.LogError(ex, "Error getting system data for {SystemId}", systemId);
                return StatusCode(500, new { success = false, error = "Internal server error" });
            }
        }

        /// <summary>
        /// Retrieves connection information for a specific solar system.
        /// Returns the best available server for the requested system.
        /// </summary>
        /// <param name="systemId">Unique identifier of the solar system</param>
        /// <returns>Server connection information</returns>
        /// <response code="200">Connection info retrieved successfully</response>
        /// <response code="400">Invalid system ID</response>
        /// <response code="500">Internal server error</response>
        [HttpGet("for-system/{systemId}")]
        [ProducesResponseType(typeof(object), 200)]
        [ProducesResponseType(typeof(object), 400)]
        [ProducesResponseType(typeof(object), 500)]
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
                _logger.LogWarning(ex, "Invalid request for system {SystemId}", systemId);
                return BadRequest(new { success = false, error = ex.Message });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error finding server for system {SystemId}", systemId);
                return StatusCode(500, new
                {
                    success = false,
                    error = "Internal server error"
                });
            }
        }

        /// <summary>
        /// Requests a connection to a game server for a specific solar system.
        /// Used when a player wants to travel to a different system.
        /// </summary>
        /// <param name="request">Connection request with player and target system information</param>
        /// <returns>Server connection details and instructions</returns>
        /// <response code="200">Connection info retrieved successfully</response>
        /// <response code="400">Invalid connection request</response>
        /// <response code="500">Internal server error</response>
        [HttpPost("request-connection")]
        [ProducesResponseType(typeof(object), 200)]
        [ProducesResponseType(typeof(object), 400)]
        [ProducesResponseType(typeof(object), 500)]
        public async Task<ActionResult> RequestConnection([FromBody] ConnectionRequest request)
        {
            try
            {
                if (string.IsNullOrEmpty(request.PlayerId))
                {
                    _logger.LogWarning("Connection request missing PlayerId");
                    return BadRequest(new { success = false, error = "PlayerId is required" });
                }

                var connectionInfo = await _gameServerService.GetConnectionForSystemAsync(request.TargetSystemId);

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
                return StatusCode(500, new { success = false, error = "Internal server error" });
            }
        }

        /// <summary>
        /// Health check endpoint for API connectivity.
        /// Returns basic server information and timestamp.
        /// </summary>
        /// <returns>API status information</returns>
        /// <response code="200">API is operational</response>
        [HttpGet("handshake")]
        [ProducesResponseType(typeof(object), 200)]
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
