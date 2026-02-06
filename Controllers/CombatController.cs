using Microsoft.AspNetCore.Mvc;
using System.ComponentModel.DataAnnotations;

namespace Echoes.API.Controllers
{
    /// <summary>
    /// Combat Controller - Handles combat-related operations from game servers
    /// Mirrors UE5 CombatServerSubsystem
    /// </summary>
    [ApiController]
    [Route("api/combat")]
    public class CombatController : ControllerBase
    {
        private readonly ILogger<CombatController> _logger;
        private readonly IConfiguration _configuration;

        public CombatController(
            ILogger<CombatController> logger,
            IConfiguration configuration)
        {
            _logger = logger;
            _configuration = configuration;
        }

        /// <summary>
        /// Report killmail from game server
        /// POST /api/combat/killmail
        /// Requires X-Server-Secret header for authentication
        /// </summary>
        [HttpPost("killmail")]
        public IActionResult ReportKill([FromBody] KillmailRequest request)
        {
            try
            {
                // Security validation - check X-Server-Secret header
                if (!Request.Headers.TryGetValue("X-Server-Secret", out var serverSecret))
                {
                    _logger.LogWarning("Killmail request received without X-Server-Secret header");
                    return Unauthorized(new { message = "Missing X-Server-Secret header" });
                }

                // Get expected secret from configuration
                var expectedSecret = _configuration["ServerSecret"] ?? "MySuperSecretKey";
                
                if (serverSecret != expectedSecret)
                {
                    _logger.LogWarning("Killmail request received with invalid X-Server-Secret");
                    return Unauthorized(new { message = "Invalid server secret" });
                }

                // Validate request data
                if (request == null)
                {
                    return BadRequest(new { message = "Request body is required" });
                }

                // Log killmail data
                _logger.LogInformation(
                    "Killmail received: Victim={VictimId}, Killer={KillerId}, System={SolarSystemId}, Ship={ShipType}",
                    request.VictimId,
                    request.KillerId,
                    request.SolarSystemId,
                    request.ShipType);

                // TODO: Store killmail in database
                // TODO: Broadcast killmail to interested clients
                // TODO: Update player statistics
                // TODO: Process bounty/insurance claims

                // Return success response
                return Ok(new
                {
                    success = true,
                    message = "Killmail recorded successfully",
                    killmailId = Guid.NewGuid(), // Placeholder - would be actual DB ID
                    timestamp = DateTime.UtcNow
                });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error processing killmail");
                return StatusCode(500, new { message = "Internal server error" });
            }
        }
    }

    /// <summary>
    /// DTO for killmail data from game server
    /// Field names must match JSON sent from UE5 CombatServerSubsystem
    /// </summary>
    public class KillmailRequest
    {
        /// <summary>
        /// Character ID of the victim (killed player)
        /// </summary>
        [Required]
        public int VictimId { get; set; }

        /// <summary>
        /// Character ID of the killer (attacking player)
        /// </summary>
        [Required]
        public int KillerId { get; set; }

        /// <summary>
        /// Solar system ID where the kill occurred
        /// </summary>
        [Required]
        public int SolarSystemId { get; set; }

        /// <summary>
        /// Type of ship that was destroyed
        /// </summary>
        [Required]
        [StringLength(100)]
        public string ShipType { get; set; } = string.Empty;
    }
}
