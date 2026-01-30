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
}
