using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using Echoes.API.Data;
using Echoes.API.Models.DTOs;
using Echoes.API.Models.Entities.Character;

namespace Echoes.API.Controllers
{
    /// <summary>
    /// Persistence Controller - Handles character state persistence from UE5 game servers
    /// Protects against data loss during logout or server crashes
    /// </summary>
    [ApiController]
    [Route("api/persistence")]
    public class PersistenceController : ControllerBase
    {
        private readonly DatabaseContext _context;
        private readonly ILogger<PersistenceController> _logger;
        private readonly IConfiguration _configuration;

        public PersistenceController(
            DatabaseContext context,
            ILogger<PersistenceController> logger,
            IConfiguration configuration)
        {
            _context = context;
            _logger = logger;
            _configuration = configuration;
        }

        /// <summary>
        /// Save or update character state from UE5 server
        /// PUT /api/persistence/state/{characterId}
        /// Requires X-Server-Secret header for authentication
        /// </summary>
        [HttpPut("state/{characterId}")]
        public async Task<ActionResult<SaveCharacterStateResponse>> SaveCharacterState(
            Guid characterId,
            [FromBody] SaveCharacterStateRequest request)
        {
            try
            {
                // Security validation - check X-Server-Secret header
                if (!Request.Headers.TryGetValue("X-Server-Secret", out var serverSecret))
                {
                    _logger.LogWarning("State save request received without X-Server-Secret header for character {CharacterId}", characterId);
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

                if (serverSecret != expectedSecret)
                {
                    _logger.LogWarning("State save request received with invalid X-Server-Secret for character {CharacterId}", characterId);
                    return Unauthorized(new { message = "Invalid server secret" });
                }

                // Validate character exists
                var characterExists = await _context.Characters.AnyAsync(c => c.Id == characterId);
                if (!characterExists)
                {
                    _logger.LogWarning("State save request for non-existent character {CharacterId}", characterId);
                    return NotFound(new { message = "Character not found" });
                }

                // Find existing state or create new one
                var state = await _context.CharacterStates
                    .FirstOrDefaultAsync(s => s.CharacterId == characterId);

                if (state == null)
                {
                    // Create new state
                    state = new CharacterState
                    {
                        Id = Guid.NewGuid(),
                        CharacterId = characterId
                    };
                    _context.CharacterStates.Add(state);
                    _logger.LogInformation("Creating new character state for character {CharacterId}", characterId);
                }
                else
                {
                    _logger.LogDebug("Updating existing character state for character {CharacterId}", characterId);
                }

                // Update state values
                state.LastSystemId = request.LastSystemId;
                state.PosX = request.PosX;
                state.PosY = request.PosY;
                state.PosZ = request.PosZ;
                state.RotW = request.RotW;
                state.RotX = request.RotX;
                state.RotY = request.RotY;
                state.RotZ = request.RotZ;
                state.CurrentShield = request.CurrentShield;
                state.CurrentArmor = request.CurrentArmor;
                state.CurrentHull = request.CurrentHull;
                state.CurrentCapacitor = request.CurrentCapacitor;
                state.LastUpdated = DateTime.UtcNow;

                await _context.SaveChangesAsync();

                _logger.LogInformation(
                    "Character state saved successfully for {CharacterId} at position ({PosX}, {PosY}, {PosZ})",
                    characterId, request.PosX, request.PosY, request.PosZ);

                return Ok(new SaveCharacterStateResponse
                {
                    Success = true,
                    Message = "Character state saved successfully",
                    LastUpdated = state.LastUpdated
                });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error saving character state for {CharacterId}", characterId);
                return StatusCode(500, new { message = "Internal server error" });
            }
        }

        /// <summary>
        /// Get character state for recovery on login
        /// GET /api/persistence/state/{characterId}
        /// Requires X-Server-Secret header for authentication
        /// </summary>
        [HttpGet("state/{characterId}")]
        public async Task<ActionResult<GetCharacterStateResponse>> GetCharacterState(Guid characterId)
        {
            try
            {
                // Security validation - check X-Server-Secret header
                if (!Request.Headers.TryGetValue("X-Server-Secret", out var serverSecret))
                {
                    _logger.LogWarning("State get request received without X-Server-Secret header for character {CharacterId}", characterId);
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

                if (serverSecret != expectedSecret)
                {
                    _logger.LogWarning("State get request received with invalid X-Server-Secret for character {CharacterId}", characterId);
                    return Unauthorized(new { message = "Invalid server secret" });
                }

                // Find character state
                var state = await _context.CharacterStates
                    .FirstOrDefaultAsync(s => s.CharacterId == characterId);

                if (state == null)
                {
                    _logger.LogInformation("No saved state found for character {CharacterId}", characterId);
                    return NotFound(new { message = "Character state not found" });
                }

                _logger.LogInformation("Character state retrieved successfully for {CharacterId}", characterId);

                return Ok(new GetCharacterStateResponse
                {
                    CharacterId = state.CharacterId,
                    LastSystemId = state.LastSystemId,
                    PosX = state.PosX,
                    PosY = state.PosY,
                    PosZ = state.PosZ,
                    RotW = state.RotW,
                    RotX = state.RotX,
                    RotY = state.RotY,
                    RotZ = state.RotZ,
                    CurrentShield = state.CurrentShield,
                    CurrentArmor = state.CurrentArmor,
                    CurrentHull = state.CurrentHull,
                    CurrentCapacitor = state.CurrentCapacitor,
                    LastUpdated = state.LastUpdated
                });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error retrieving character state for {CharacterId}", characterId);
                return StatusCode(500, new { message = "Internal server error" });
            }
        }
    }
}
