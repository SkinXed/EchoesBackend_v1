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

                // Fail securely if secret is not configured
                if (string.IsNullOrEmpty(expectedSecret))
                {
                    _logger.LogError("ServerSecret is not configured");
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
                    
                    // Check sequence number - skip if incoming is older (only if SequenceNumber is provided and > 0)
                    if (request.SequenceNumber > 0 && request.SequenceNumber <= state.SequenceNumber)
                    {
                        _logger.LogWarning(
                            "Skipping character {CharacterId} - incoming sequence {Incoming} <= existing {Existing}",
                            characterId, request.SequenceNumber, state.SequenceNumber);
                        return Ok(new SaveCharacterStateResponse
                        {
                            Success = false,
                            Message = "State update skipped - older sequence number",
                            LastUpdated = state.LastUpdated
                        });
                    }
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
                state.SequenceNumber = request.SequenceNumber > 0 ? request.SequenceNumber : state.SequenceNumber;
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

                // Fail securely if secret is not configured
                if (string.IsNullOrEmpty(expectedSecret))
                {
                    _logger.LogError("ServerSecret is not configured");
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

        /// <summary>
        /// Bulk save character states from UE5 server
        /// POST /api/persistence/state/bulk
        /// Requires X-Server-Secret header for authentication
        /// Processes up to 50 character state updates in a single request
        /// Uses sequence numbers to prevent race conditions
        /// </summary>
        [HttpPost("state/bulk")]
        public async Task<ActionResult<BulkSaveCharacterStateResponse>> BulkSaveCharacterState(
            [FromBody] BulkSaveCharacterStateRequest request)
        {
            try
            {
                // Security validation - check X-Server-Secret header
                if (!Request.Headers.TryGetValue("X-Server-Secret", out var serverSecret))
                {
                    _logger.LogWarning("Bulk state save request received without X-Server-Secret header");
                    return Unauthorized(new { message = "Missing X-Server-Secret header" });
                }

                // Get expected secret from configuration
                var expectedSecret = _configuration["ServerSecret"];

                // Fail securely if secret is not configured
                if (string.IsNullOrEmpty(expectedSecret))
                {
                    _logger.LogError("ServerSecret is not configured");
                    return StatusCode(500, new { message = "Server configuration error" });
                }

                if (serverSecret != expectedSecret)
                {
                    _logger.LogWarning("Bulk state save request received with invalid X-Server-Secret");
                    return Unauthorized(new { message = "Invalid server secret" });
                }

                // Validate request
                if (request.States == null || request.States.Count == 0)
                {
                    return BadRequest(new { message = "No states provided" });
                }

                // Log bulk operation start
                _logger.LogInformation("Processing bulk save for {Count} character states", request.States.Count);

                var response = new BulkSaveCharacterStateResponse
                {
                    SavedCount = 0,
                    SkippedCount = 0,
                    FailedCount = 0
                };

                // Get all character IDs from the request
                var characterIds = request.States.Select(s => s.CharacterId).Distinct().ToList();

                // Validate all characters exist in a single query
                var existingCharacterIds = await _context.Characters
                    .Where(c => characterIds.Contains(c.Id))
                    .Select(c => c.Id)
                    .ToListAsync();

                // Get existing states for all characters in a single query
                var existingStates = await _context.CharacterStates
                    .Where(s => characterIds.Contains(s.CharacterId))
                    .ToDictionaryAsync(s => s.CharacterId);

                // Process each state update
                foreach (var stateItem in request.States)
                {
                    try
                    {
                        // Check if character exists
                        if (!existingCharacterIds.Contains(stateItem.CharacterId))
                        {
                            _logger.LogWarning("Bulk save: Character {CharacterId} not found", stateItem.CharacterId);
                            response.FailedCount++;
                            continue;
                        }

                        // Check if state exists for this character
                        if (existingStates.TryGetValue(stateItem.CharacterId, out var existingState))
                        {
                            // Check sequence number - skip if incoming is older
                            if (stateItem.SequenceNumber <= existingState.SequenceNumber)
                            {
                                _logger.LogDebug(
                                    "Bulk save: Skipping character {CharacterId} - incoming sequence {Incoming} <= existing {Existing}",
                                    stateItem.CharacterId, stateItem.SequenceNumber, existingState.SequenceNumber);
                                response.SkippedCount++;
                                response.SkippedCharacterIds.Add(stateItem.CharacterId);
                                continue;
                            }

                            // Update existing state
                            existingState.LastSystemId = stateItem.LastSystemId;
                            existingState.PosX = stateItem.PosX;
                            existingState.PosY = stateItem.PosY;
                            existingState.PosZ = stateItem.PosZ;
                            existingState.RotW = stateItem.RotW;
                            existingState.RotX = stateItem.RotX;
                            existingState.RotY = stateItem.RotY;
                            existingState.RotZ = stateItem.RotZ;
                            existingState.CurrentShield = stateItem.CurrentShield;
                            existingState.CurrentArmor = stateItem.CurrentArmor;
                            existingState.CurrentHull = stateItem.CurrentHull;
                            existingState.CurrentCapacitor = stateItem.CurrentCapacitor;
                            existingState.SequenceNumber = stateItem.SequenceNumber;
                            existingState.LastUpdated = DateTime.UtcNow;
                        }
                        else
                        {
                            // Create new state
                            var newState = new CharacterState
                            {
                                Id = Guid.NewGuid(),
                                CharacterId = stateItem.CharacterId,
                                LastSystemId = stateItem.LastSystemId,
                                PosX = stateItem.PosX,
                                PosY = stateItem.PosY,
                                PosZ = stateItem.PosZ,
                                RotW = stateItem.RotW,
                                RotX = stateItem.RotX,
                                RotY = stateItem.RotY,
                                RotZ = stateItem.RotZ,
                                CurrentShield = stateItem.CurrentShield,
                                CurrentArmor = stateItem.CurrentArmor,
                                CurrentHull = stateItem.CurrentHull,
                                CurrentCapacitor = stateItem.CurrentCapacitor,
                                SequenceNumber = stateItem.SequenceNumber,
                                LastUpdated = DateTime.UtcNow
                            };
                            _context.CharacterStates.Add(newState);
                            existingStates[stateItem.CharacterId] = newState;
                        }

                        response.SavedCount++;
                    }
                    catch (Exception ex)
                    {
                        _logger.LogError(ex, "Error processing bulk save for character {CharacterId}", stateItem.CharacterId);
                        response.FailedCount++;
                    }
                }

                // Save all changes in a single transaction
                await _context.SaveChangesAsync();

                // Set response status
                response.Success = response.FailedCount == 0;
                response.Message = $"Bulk save completed: {response.SavedCount} saved, {response.SkippedCount} skipped (old sequence), {response.FailedCount} failed";

                _logger.LogInformation(
                    "Bulk save completed: {SavedCount} saved, {SkippedCount} skipped, {FailedCount} failed",
                    response.SavedCount, response.SkippedCount, response.FailedCount);

                return Ok(response);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error in bulk save character state");
                return StatusCode(500, new { message = "Internal server error" });
            }
        }
    }
}
