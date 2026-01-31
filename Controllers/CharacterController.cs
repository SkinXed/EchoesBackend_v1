using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using Echoes.API.Data;
using Echoes.API.Models.DTOs;
using Echoes.API.Models.Entities.Character;
using System.Security.Claims;

namespace Echoes.API.Controllers;

/// <summary>
/// Character management controller
/// Handles character data retrieval and updates
/// </summary>
[Authorize]
[ApiController]
[Route("api/[controller]")]
public class CharacterController : ControllerBase
{
    private readonly DatabaseContext _context;
    private readonly ILogger<CharacterController> _logger;
    private readonly IConfiguration _configuration;

    public CharacterController(
        DatabaseContext context,
        ILogger<CharacterController> logger,
        IConfiguration configuration)
    {
        _context = context;
        _logger = logger;
        _configuration = configuration;
    }

    /// <summary>
    /// Validates the X-Server-Secret header for server-to-server authentication
    /// </summary>
    private bool ValidateServerSecret()
    {
        if (!Request.Headers.TryGetValue("X-Server-Secret", out var headerSecret))
        {
            return false;
        }

        var configuredSecret = _configuration["ServerSecret"] ?? "default-server-secret-change-me";
        return headerSecret == configuredSecret;
    }

    /// <summary>
    /// Get current character data (from JWT token)
    /// GET /api/character/me
    /// </summary>
    /// <returns>Character data with current ship info</returns>
    [HttpGet("me")]
    [ProducesResponseType(StatusCodes.Status200OK)]
    [ProducesResponseType(StatusCodes.Status401Unauthorized)]
    [ProducesResponseType(StatusCodes.Status404NotFound)]
    public async Task<ActionResult<CharacterDataDto>> GetMyCharacter()
    {
        try
        {
            // Extract character ID from JWT token
            var characterIdClaim = User.FindFirst("CharacterId")?.Value
                ?? User.FindFirst(ClaimTypes.NameIdentifier)?.Value;

            if (string.IsNullOrEmpty(characterIdClaim) || !Guid.TryParse(characterIdClaim, out var characterId))
            {
                return Unauthorized(new { error = "Invalid token - no character ID" });
            }

            var character = await _context.Characters
                .Include(c => c.Account)
                .Include(c => c.ActiveShip)
                .FirstOrDefaultAsync(c => c.Id == characterId);

            if (character == null)
            {
                return NotFound(new { error = "Character not found" });
            }

            var characterData = new CharacterDataDto
            {
                CharacterId = character.Id,
                Name = character.Name,
                AccountId = character.AccountId,
                WalletBalance = character.WalletBalance,
                SecurityStatus = character.SecurityStatus,
                CurrentShipId = character.ActiveShipItemId,
                CorporationId = character.CorporationId,
                RaceId = character.RaceId,
                TotalSkillPoints = character.TotalSkillPoints,
                UnallocatedSkillPoints = character.UnallocatedSkillPoints,
                IsOnline = character.IsOnline,
                IsDocked = character.IsDocked,
                InWarp = character.InWarp,
                LastLogin = character.LastLogin
            };

            return Ok(characterData);
        }
        catch (Exception ex)
        {
            _logger.LogError(ex, "Error retrieving character data");
            return StatusCode(500, new { error = "Internal server error" });
        }
    }

    /// <summary>
    /// Get character by ID (for UE Server with X-Server-Secret)
    /// GET /api/character/{id}
    /// </summary>
    [HttpGet("{id}")]
    [ProducesResponseType(StatusCodes.Status200OK)]
    [ProducesResponseType(StatusCodes.Status401Unauthorized)]
    [ProducesResponseType(StatusCodes.Status404NotFound)]
    public async Task<ActionResult<CharacterDataDto>> GetCharacter(Guid id)
    {
        // Check for server secret if not authenticated as user
        if (!User.Identity?.IsAuthenticated ?? false)
        {
            if (!ValidateServerSecret())
            {
                return Unauthorized(new { error = "Invalid or missing X-Server-Secret header" });
            }
        }

        try
        {
            var character = await _context.Characters
                .Include(c => c.Account)
                .Include(c => c.ActiveShip)
                .FirstOrDefaultAsync(c => c.Id == id);

            if (character == null)
            {
                return NotFound(new { error = "Character not found" });
            }

            var characterData = new CharacterDataDto
            {
                CharacterId = character.Id,
                Name = character.Name,
                AccountId = character.AccountId,
                WalletBalance = character.WalletBalance,
                SecurityStatus = character.SecurityStatus,
                CurrentShipId = character.ActiveShipItemId,
                CorporationId = character.CorporationId,
                RaceId = character.RaceId,
                TotalSkillPoints = character.TotalSkillPoints,
                UnallocatedSkillPoints = character.UnallocatedSkillPoints,
                IsOnline = character.IsOnline,
                IsDocked = character.IsDocked,
                InWarp = character.InWarp,
                LastLogin = character.LastLogin
            };

            return Ok(characterData);
        }
        catch (Exception ex)
        {
            _logger.LogError(ex, "Error retrieving character {CharacterId}", id);
            return StatusCode(500, new { error = "Internal server error" });
        }
    }

    /// <summary>
    /// Create a new character for the authenticated account
    /// POST /api/character
    /// </summary>
    [HttpPost]
    [ProducesResponseType(StatusCodes.Status201Created)]
    [ProducesResponseType(StatusCodes.Status400BadRequest)]
    [ProducesResponseType(StatusCodes.Status401Unauthorized)]
    public async Task<ActionResult<CharacterDataDto>> CreateCharacter([FromBody] CreateCharacterRequest request)
    {
        try
        {
            // Extract account ID from JWT token
            var accountIdClaim = User.FindFirst("AccountId")?.Value
                ?? User.FindFirst(ClaimTypes.NameIdentifier)?.Value;

            if (string.IsNullOrEmpty(accountIdClaim) || !Guid.TryParse(accountIdClaim, out var accountId))
            {
                return Unauthorized(new { error = "Invalid token - no account ID" });
            }

            // Validate input
            if (string.IsNullOrWhiteSpace(request.Name) || request.Name.Length < 3 || request.Name.Length > 50)
            {
                return BadRequest(new { error = "Character name must be between 3 and 50 characters" });
            }

            // Check if name is already taken
            var existingCharacter = await _context.Characters
                .AnyAsync(c => c.Name.ToLower() == request.Name.ToLower());

            if (existingCharacter)
            {
                return BadRequest(new { error = "Character name already taken" });
            }

            // Validate race
            var validRaces = new[] { "Caldari", "Gallente", "Amarr", "Minmatar" };
            if (!validRaces.Contains(request.Race))
            {
                return BadRequest(new { error = "Invalid race. Must be one of: Caldari, Gallente, Amarr, Minmatar" });
            }

            // Get or create default starting ship (Rookie Ship)
            var rookieShip = await _context.Items
                .FirstOrDefaultAsync(i => i.Name.Contains("Rookie") && i.Category == "Ship");

            // Create new character
            var character = new Models.Entities.Character.Character
            {
                Id = Guid.NewGuid(),
                AccountId = accountId,
                Name = request.Name,
                Race = request.Race,
                PortraitId = request.PortraitId > 0 ? request.PortraitId : 1,
                WalletBalance = 5000000, // Starting ISK
                SecurityStatus = 0.0,
                TotalSkillPoints = 0,
                UnallocatedSkillPoints = 50000, // Starting skill points
                IsOnline = false,
                IsDocked = true,
                InWarp = false,
                CreatedAt = DateTime.UtcNow,
                LastLogin = DateTime.UtcNow
            };

            _context.Characters.Add(character);
            await _context.SaveChangesAsync();

            _logger.LogInformation("Created new character {CharacterName} for account {AccountId}", 
                character.Name, accountId);

            var characterData = new CharacterDataDto
            {
                CharacterId = character.Id,
                Name = character.Name,
                AccountId = character.AccountId,
                WalletBalance = character.WalletBalance,
                SecurityStatus = character.SecurityStatus,
                CurrentShipId = character.ActiveShipItemId,
                TotalSkillPoints = character.TotalSkillPoints,
                UnallocatedSkillPoints = character.UnallocatedSkillPoints,
                IsOnline = character.IsOnline,
                IsDocked = character.IsDocked
            };

            return CreatedAtAction(nameof(GetCharacter), new { id = character.Id }, characterData);
        }
        catch (Exception ex)
        {
            _logger.LogError(ex, "Error creating character");
            return StatusCode(500, new { error = "Internal server error" });
        }
    }

    /// <summary>
    /// Undock character from station
    /// POST /api/character/undock
    /// </summary>
    [HttpPost("undock")]
    [ProducesResponseType(StatusCodes.Status200OK)]
    [ProducesResponseType(StatusCodes.Status400BadRequest)]
    [ProducesResponseType(StatusCodes.Status401Unauthorized)]
    public async Task<ActionResult> Undock()
    {
        try
        {
            // Extract character ID from JWT token
            var characterIdClaim = User.FindFirst("CharacterId")?.Value
                ?? User.FindFirst(ClaimTypes.NameIdentifier)?.Value;

            if (string.IsNullOrEmpty(characterIdClaim) || !Guid.TryParse(characterIdClaim, out var characterId))
            {
                return Unauthorized(new { error = "Invalid token - no character ID" });
            }

            var character = await _context.Characters
                .Include(c => c.ActiveShip)
                .FirstOrDefaultAsync(c => c.Id == characterId);

            if (character == null)
            {
                return NotFound(new { error = "Character not found" });
            }

            if (!character.IsDocked)
            {
                return BadRequest(new { error = "Character is not docked" });
            }

            if (character.ActiveShipItemId == null)
            {
                return BadRequest(new { error = "No active ship selected" });
            }

            // Update character state to undocked
            character.IsDocked = false;
            character.InWarp = false;
            await _context.SaveChangesAsync();

            _logger.LogInformation("Character {CharacterId} undocked from station", characterId);

            return Ok(new { 
                message = "Undocked successfully",
                isDocked = false,
                activeShipId = character.ActiveShipItemId
            });
        }
        catch (Exception ex)
        {
            _logger.LogError(ex, "Error undocking character");
            return StatusCode(500, new { error = "Internal server error" });
        }
    }
}
