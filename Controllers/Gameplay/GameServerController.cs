using Echoes.API.Data;
using Echoes.API.Models.DTOs.Server;
using Echoes.API.Services;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;

namespace Echoes.API.Controllers.Gameplay
{
    /// <summary>
    /// Controller for gameplay and client-facing game server operations.
    /// Handles system information retrieval and connection requests from game clients.
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
        /// Get detailed information about a solar system.
        /// Includes planets, stargates, and constellation/region data.
        /// </summary>
        /// <param name="systemId">The unique identifier of the solar system.</param>
        /// <returns>Detailed solar system information.</returns>
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
                    .ThenInclude(sg => sg.DestinationSolarSystem)
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
                _logger.LogError(ex, "Error getting system data for {SystemId}", systemId);
                return StatusCode(500, new { error = "Internal server error" });
            }
        }

        /// <summary>
        /// Get the game server connection information for a specific solar system.
        /// Returns the best available server for the requested system.
        /// </summary>
        /// <param name="systemId">The unique identifier of the solar system.</param>
        /// <returns>Connection information for the appropriate game server.</returns>
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

        /// <summary>
        /// Request connection information for a player to travel to a target system.
        /// Determines if reconnection to a different server is needed.
        /// </summary>
        /// <param name="request">Connection request details including player and system IDs.</param>
        /// <returns>Connection information and instructions.</returns>
        [HttpPost("request-connection")]
        public async Task<ActionResult> RequestConnection([FromBody] ConnectionRequestDto request)
        {
            try
            {
                if (string.IsNullOrEmpty(request.PlayerId))
                    return BadRequest(new { error = "PlayerId is required" });

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
                return StatusCode(500, new { error = ex.Message });
            }
        }

        /// <summary>
        /// Handshake endpoint for basic connectivity and status checks.
        /// </summary>
        /// <returns>Basic API status information.</returns>
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
