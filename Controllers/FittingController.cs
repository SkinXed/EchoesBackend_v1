using Microsoft.AspNetCore.Mvc;
using Echoes.API.Data.Repositories;
using Echoes.API.Models.DTOs.Fitting;

namespace Echoes.API.Controllers
{
    /// <summary>
    /// Fitting Controller - Handles ship fitting/equipment operations from UE5 Server
    /// Provides fitting data from PostgreSQL database to UE5 game servers
    /// </summary>
    [ApiController]
    [Route("api/fitting")]
    public class FittingController : ControllerBase
    {
        private readonly FittingRepository _fittingRepository;
        private readonly ILogger<FittingController> _logger;
        private readonly IConfiguration _configuration;

        public FittingController(
            FittingRepository fittingRepository,
            ILogger<FittingController> logger,
            IConfiguration configuration)
        {
            _fittingRepository = fittingRepository;
            _logger = logger;
            _configuration = configuration;
        }

        /// <summary>
        /// Get character's ship fitting
        /// GET /api/fitting/{characterId}
        /// Requires X-Server-Secret header for authentication
        /// Returns complete fitting data with all equipped modules
        /// </summary>
        /// <param name="characterId">Character ID (Guid as string)</param>
        /// <returns>Complete fitting data in JSON format matching FCommon_ShipFittingData</returns>
        [HttpGet("{characterId}")]
        public async Task<IActionResult> GetFitting(string characterId)
        {
            try
            {
                _logger.LogInformation("Fitting request received for character {CharacterId}", characterId);

                // Security validation - check X-Server-Secret header
                if (!Request.Headers.TryGetValue("X-Server-Secret", out var serverSecret))
                {
                    _logger.LogWarning("Fitting request for {CharacterId} received without X-Server-Secret header", 
                        characterId);
                    return Unauthorized(new { message = "Missing X-Server-Secret header" });
                }

                // Get expected secret from configuration
                var expectedSecret = _configuration["ServerSecret"];
                
                // Fail securely if secret is not configured or is set to the insecure default
                if (string.IsNullOrEmpty(expectedSecret) || expectedSecret == "MySuperSecretKey")
                {
                    _logger.LogError("ServerSecret is not configured or is set to insecure default value");
                    return StatusCode(500, new { message = "Server configuration error" });
                }

                // Validate secret
                if (serverSecret != expectedSecret)
                {
                    _logger.LogWarning("Invalid X-Server-Secret for fitting request: {CharacterId}", characterId);
                    return Unauthorized(new { message = "Invalid X-Server-Secret" });
                }

                // Validate character ID format
                if (string.IsNullOrWhiteSpace(characterId))
                {
                    _logger.LogWarning("Empty character ID received");
                    return BadRequest(new { message = "Character ID is required" });
                }

                // Get fitting data from repository
                var fitting = await _fittingRepository.GetCharacterFittingAsync(characterId);

                if (fitting == null)
                {
                    _logger.LogWarning("Fitting not found for character {CharacterId}", characterId);
                    return NotFound(new { 
                        message = "Character not found or has no active ship",
                        characterId = characterId
                    });
                }

                _logger.LogInformation("Successfully retrieved fitting for character {CharacterId}: " +
                    "{HighCount} high, {MidCount} mid, {LowCount} low, {RigCount} rig slots, " +
                    "PG: {PGUsed}/{PGMax}, CPU: {CPUUsed}/{CPUMax}",
                    characterId,
                    fitting.HighSlots.Count,
                    fitting.MidSlots.Count,
                    fitting.LowSlots.Count,
                    fitting.RigSlots.Count,
                    fitting.PowergridUsed,
                    fitting.PowergridMax,
                    fitting.CPUUsed,
                    fitting.CPUMax);

                return Ok(fitting);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error processing fitting request for character {CharacterId}", characterId);
                return StatusCode(500, new { 
                    message = "Internal server error while retrieving fitting",
                    error = ex.Message
                });
            }
        }

        /// <summary>
        /// Health check endpoint for fitting service
        /// GET /api/fitting/health
        /// </summary>
        [HttpGet("health")]
        public IActionResult Health()
        {
            return Ok(new { 
                status = "healthy", 
                service = "FittingController",
                timestamp = DateTime.UtcNow
            });
        }
    }
}
