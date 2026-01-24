using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Authorization;
using Microsoft.EntityFrameworkCore;
using Echoes.API.Data;
using EchoesOfImperial.Shared.DTOs;
using System.Security.Claims;

namespace Echoes.API.Controllers;

[Authorize] // Requires valid JWT
[ApiController]
[Route("api/[controller]")]
public class PilotController : ControllerBase
{
    private readonly DatabaseContext _context;
    private readonly ILogger<PilotController> _logger;

    public PilotController(DatabaseContext context, ILogger<PilotController> logger)
    {
        _context = context;
        _logger = logger;
    }

    /// <summary>
    /// Get dashboard data for the authenticated pilot
    /// </summary>
    [HttpGet("dashboard")]
    public async Task<ActionResult<PilotDashboardDTO>> GetDashboard()
    {
        try
        {
            // Extract user ID from JWT token claims
            var userIdClaim = User.FindFirst(ClaimTypes.NameIdentifier)?.Value 
                ?? User.FindFirst("sub")?.Value;
            
            if (string.IsNullOrEmpty(userIdClaim) || !Guid.TryParse(userIdClaim, out var userId))
            {
                _logger.LogWarning("Failed to extract user ID from token");
                return Unauthorized(new { error = "Invalid token" });
            }

            // Get character ID from claims
            var characterIdClaim = User.FindFirst("CharacterId")?.Value;
            if (string.IsNullOrEmpty(characterIdClaim) || !Guid.TryParse(characterIdClaim, out var characterId))
            {
                _logger.LogWarning("Failed to extract character ID from token");
                return Unauthorized(new { error = "Invalid token" });
            }

            // Fetch character data from database
            var character = await _context.Characters
                .Include(c => c.CurrentLocation)
                .FirstOrDefaultAsync(c => c.Id == characterId && c.AccountId == userId);

            if (character == null)
            {
                _logger.LogWarning("Character not found for user {UserId}, character {CharacterId}", userId, characterId);
                return NotFound(new { error = "Pilot not found" });
            }

            // Get current system name
            var currentSystem = "Unknown System";
            if (character.CurrentLocation != null)
            {
                var system = await _context.SolarSystems
                    .FirstOrDefaultAsync(s => s.Id == character.CurrentLocation.SolarSystemId);
                if (system != null)
                {
                    currentSystem = system.Name;
                }
            }

            // Get current ship info (placeholder - will be implemented later with actual ship system)
            var currentShip = "Ibis"; // Default starter ship

            // Return pilot dashboard data
            return Ok(new PilotDashboardDTO
            {
                PilotId = character.Id,
                PilotName = character.Name,
                CorpName = "Freelancer", // Will be implemented with corporation system
                Credits = character.WalletBalance,
                CurrentSystem = currentSystem,
                CurrentShip = currentShip
            });
        }
        catch (Exception ex)
        {
            _logger.LogError(ex, "Error retrieving pilot dashboard");
            return StatusCode(500, new { error = "Internal server error" });
        }
    }
}
