using Echoes.API.Data;
using Echoes.API.Models.DTOs.Combat;
using Echoes.API.Services.Combat;
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
        private readonly IKillmailService _killmailService;

        public CombatController(
            ILogger<CombatController> logger,
            IConfiguration configuration,
            IKillmailService killmailService)
        {
            _logger = logger;
            _configuration = configuration;
            _killmailService = killmailService;
        }

        /// <summary>
        /// Validate X-Server-Secret header
        /// </summary>
        private bool ValidateServerSecret()
        {
            if (!Request.Headers.TryGetValue("X-Server-Secret", out var serverSecret))
                return false;

            var expectedSecret = _configuration["ServerSecret"];
            if (string.IsNullOrEmpty(expectedSecret) || expectedSecret == "MySuperSecretKey")
                return false;

            return serverSecret == expectedSecret;
        }

        /// <summary>
        /// Report killmail from game server
        /// POST /api/combat/killmail
        /// Requires X-Server-Secret header for authentication
        /// </summary>
        [HttpPost("killmail")]
        public async Task<IActionResult> ReportKill([FromBody] KillmailReportRequest request)
        {
            try
            {
                if (!ValidateServerSecret())
                {
                    _logger.LogWarning("Killmail request with invalid or missing X-Server-Secret");
                    return Unauthorized(new { error = "Invalid server secret" });
                }

                if (request == null)
                {
                    return BadRequest(new { error = "Request body is required" });
                }

                if (request.VictimId == Guid.Empty || request.FinalStrikerId == Guid.Empty)
                {
                    return BadRequest(new { error = "VictimId and FinalStrikerId are required" });
                }

                _logger.LogInformation(
                    "Killmail received: Victim={VictimId}, Killer={KillerId}, System={SystemId}, Ship={ShipType}",
                    request.VictimId, request.FinalStrikerId, request.SolarSystemId, request.ShipTypeName);

                var result = await _killmailService.ProcessKillmailAsync(request);

                return Ok(result);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error processing killmail");
                return StatusCode(500, new { error = "Internal server error" });
            }
        }

        /// <summary>
        /// Get a specific killmail by ID
        /// GET /api/combat/killmail/{killmailId}
        /// </summary>
        [HttpGet("killmail/{killmailId}")]
        public async Task<IActionResult> GetKillmail(Guid killmailId)
        {
            try
            {
                if (!ValidateServerSecret())
                {
                    return Unauthorized(new { error = "Invalid server secret" });
                }

                var killmail = await _killmailService.GetKillmailAsync(killmailId);
                if (killmail == null)
                {
                    return NotFound(new { error = "Killmail not found" });
                }

                return Ok(killmail);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error retrieving killmail {KillmailId}", killmailId);
                return StatusCode(500, new { error = "Internal server error" });
            }
        }

        /// <summary>
        /// Get killmails for a character
        /// GET /api/combat/character/{characterId}/killmails
        /// </summary>
        [HttpGet("character/{characterId}/killmails")]
        public async Task<IActionResult> GetCharacterKillmails(Guid characterId, [FromQuery] int page = 1, [FromQuery] int pageSize = 20)
        {
            try
            {
                if (!ValidateServerSecret())
                {
                    return Unauthorized(new { error = "Invalid server secret" });
                }

                if (pageSize > 100) pageSize = 100;
                if (page < 1) page = 1;

                var killmails = await _killmailService.GetCharacterKillmailsAsync(characterId, page, pageSize);
                return Ok(killmails);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error retrieving killmails for character {CharacterId}", characterId);
                return StatusCode(500, new { error = "Internal server error" });
            }
        }

        /// <summary>
        /// Get killmails for a solar system
        /// GET /api/combat/system/{systemId}/killmails
        /// </summary>
        [HttpGet("system/{systemId}/killmails")]
        public async Task<IActionResult> GetSystemKillmails(Guid systemId, [FromQuery] int page = 1, [FromQuery] int pageSize = 20)
        {
            try
            {
                if (!ValidateServerSecret())
                {
                    return Unauthorized(new { error = "Invalid server secret" });
                }

                if (pageSize > 100) pageSize = 100;
                if (page < 1) page = 1;

                var killmails = await _killmailService.GetSystemKillmailsAsync(systemId, page, pageSize);
                return Ok(killmails);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error retrieving killmails for system {SystemId}", systemId);
                return StatusCode(500, new { error = "Internal server error" });
            }
        }
    }
}
