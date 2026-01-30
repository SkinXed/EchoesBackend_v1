using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using Echoes.API.Data;
using Echoes.API.Models.DTOs;
using System.Security.Claims;

namespace Echoes.API.Controllers.Inventory;

/// <summary>
/// Ship Inventory Controller
/// Manages player ships and fittings
/// </summary>
[Authorize]
[ApiController]
[Route("api/inventory")]
public class ShipInventoryController : ControllerBase
{
    private readonly DatabaseContext _context;
    private readonly ILogger<ShipInventoryController> _logger;

    public ShipInventoryController(
        DatabaseContext context,
        ILogger<ShipInventoryController> logger)
    {
        _context = context;
        _logger = logger;
    }

    /// <summary>
    /// Get all ships for current character
    /// GET /api/inventory/ships
    /// </summary>
    [HttpGet("ships")]
    [ProducesResponseType(StatusCodes.Status200OK)]
    [ProducesResponseType(StatusCodes.Status401Unauthorized)]
    public async Task<ActionResult<List<ShipInstanceDto>>> GetShips()
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

            var ships = await _context.ShipInstances
                .Include(s => s.ShipType)
                .Include(s => s.FittedModules)
                .Where(s => s.CharacterId == characterId)
                .Select(s => new ShipInstanceDto
                {
                    InstanceId = s.Id,
                    Name = s.Name,
                    ShipTypeId = s.ShipTypeId,
                    ShipTypeName = s.ShipType.Name,
                    Mass = s.ShipType.BaseMass,
                    LocationSystemId = s.LocationSystemId,
                    LocationName = "", // TODO: Get from system data
                    IsActive = s.IsActive,
                    IsDocked = s.IsDocked,
                    ModuleCount = s.FittedModules.Count
                })
                .ToListAsync();

            _logger.LogInformation("Retrieved {Count} ships for character {CharacterId}", 
                ships.Count, characterId);

            return Ok(ships);
        }
        catch (Exception ex)
        {
            _logger.LogError(ex, "Error retrieving ships");
            return StatusCode(500, new { error = "Internal server error" });
        }
    }

    /// <summary>
    /// Get detailed ship fitting
    /// GET /api/inventory/ship/{id}/fitting
    /// </summary>
    [HttpGet("ship/{id}/fitting")]
    [ProducesResponseType(StatusCodes.Status200OK)]
    [ProducesResponseType(StatusCodes.Status401Unauthorized)]
    [ProducesResponseType(StatusCodes.Status404NotFound)]
    public async Task<ActionResult<ShipFittingDto>> GetShipFitting(Guid id)
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

            var ship = await _context.ShipInstances
                .Include(s => s.ShipType)
                .Include(s => s.FittedModules)
                .FirstOrDefaultAsync(s => s.Id == id && s.CharacterId == characterId);

            if (ship == null)
            {
                return NotFound(new { error = "Ship not found or does not belong to you" });
            }

            // Calculate total mass and bonuses
            float totalMass = ship.ShipType.BaseMass;
            float totalThrust = ship.ShipType.BaseThrust;
            float inertiaMod = ship.ShipType.BaseInertiaMultiplier;
            float rotationBonus = 0f;
            float maxVelMod = 1.0f;

            var modules = new List<ModuleInstanceDto>();

            foreach (var module in ship.FittedModules)
            {
                totalMass += module.Mass;
                totalThrust += module.ThrustBonus;
                inertiaMod *= module.InertiaModifier;
                rotationBonus += module.RotationBonus;
                maxVelMod *= module.MaxVelocityModifier;

                modules.Add(new ModuleInstanceDto
                {
                    InstanceId = module.Id,
                    ModuleTypeId = module.ModuleTypeId,
                    TypeName = $"Module Type {module.ModuleTypeId}", // TODO: Get from module type data
                    Slot = module.Slot,
                    SlotIndex = module.SlotIndex,
                    IsOnline = module.IsOnline,
                    Mass = module.Mass,
                    ThrustBonus = module.ThrustBonus,
                    InertiaModifier = module.InertiaModifier,
                    RotationBonus = module.RotationBonus,
                    MaxVelocityModifier = module.MaxVelocityModifier
                });
            }

            var fitting = new ShipFittingDto
            {
                ShipInstanceId = ship.Id,
                ShipName = ship.Name,
                ShipTypeId = ship.ShipTypeId,
                ShipTypeName = ship.ShipType.Name,
                BaseMass = ship.ShipType.BaseMass,
                TotalMass = totalMass,
                Thrust = totalThrust,
                MaxVelocity = ship.ShipType.BaseMaxVelocity * maxVelMod,
                InertiaMultiplier = inertiaMod,
                RotationTorque = ship.ShipType.BaseRotationTorque + rotationBonus,
                Modules = modules
            };

            _logger.LogInformation("Retrieved fitting for ship {ShipId}", id);

            return Ok(fitting);
        }
        catch (Exception ex)
        {
            _logger.LogError(ex, "Error retrieving ship fitting for {ShipId}", id);
            return StatusCode(500, new { error = "Internal server error" });
        }
    }

    /// <summary>
    /// Verify ship ownership (for UE Server validation)
    /// GET /api/inventory/ship/{id}/ownership
    /// </summary>
    [HttpGet("ship/{id}/ownership")]
    [ProducesResponseType(StatusCodes.Status200OK)]
    [ProducesResponseType(StatusCodes.Status401Unauthorized)]
    [ProducesResponseType(StatusCodes.Status403Forbidden)]
    [ProducesResponseType(StatusCodes.Status404NotFound)]
    public async Task<ActionResult> VerifyShipOwnership(Guid id)
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

            // Check if ship exists
            var ship = await _context.ShipInstances
                .FirstOrDefaultAsync(s => s.Id == id);

            if (ship == null)
            {
                return NotFound(new 
                { 
                    shipId = id,
                    characterId = characterId,
                    isOwned = false,
                    error = "Ship not found"
                });
            }

            // Check ownership
            bool isOwned = ship.CharacterId == characterId;

            if (!isOwned)
            {
                _logger.LogWarning("Character {CharacterId} attempted to access ship {ShipId} owned by {OwnerId}", 
                    characterId, id, ship.CharacterId);
                
                return StatusCode(StatusCodes.Status403Forbidden, new 
                { 
                    shipId = id,
                    characterId = characterId,
                    isOwned = false,
                    error = "Ship does not belong to this character"
                });
            }

            _logger.LogInformation("Verified ownership of ship {ShipId} for character {CharacterId}", 
                id, characterId);

            return Ok(new 
            { 
                shipId = id,
                characterId = characterId,
                isOwned = true,
                shipName = ship.Name
            });
        }
        catch (Exception ex)
        {
            _logger.LogError(ex, "Error verifying ship ownership for {ShipId}", id);
            return StatusCode(500, new { error = "Internal server error" });
        }
    }

    /// <summary>
    /// Activate a ship (set as current active ship)
    /// POST /api/inventory/ship/{id}/activate
    /// </summary>
    [HttpPost("ship/{id}/activate")]
    [ProducesResponseType(StatusCodes.Status200OK)]
    [ProducesResponseType(StatusCodes.Status401Unauthorized)]
    [ProducesResponseType(StatusCodes.Status404NotFound)]
    public async Task<ActionResult> ActivateShip(Guid id)
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

            // Verify ship belongs to character
            var ship = await _context.ShipInstances
                .FirstOrDefaultAsync(s => s.Id == id && s.CharacterId == characterId);

            if (ship == null)
            {
                return NotFound(new { error = "Ship not found or does not belong to you" });
            }

            // Deactivate all other ships for this character
            var otherShips = await _context.ShipInstances
                .Where(s => s.CharacterId == characterId && s.Id != id)
                .ToListAsync();

            foreach (var otherShip in otherShips)
            {
                otherShip.IsActive = false;
            }

            // Activate the selected ship
            ship.IsActive = true;

            // Update character's active ship
            var character = await _context.Characters
                .FirstOrDefaultAsync(c => c.Id == characterId);

            if (character != null)
            {
                character.ActiveShipItemId = (long)id.GetHashCode(); // Simplified conversion
            }

            await _context.SaveChangesAsync();

            _logger.LogInformation("Activated ship {ShipId} for character {CharacterId}", 
                id, characterId);

            return Ok(new 
            { 
                success = true, 
                message = $"Ship {ship.Name} activated",
                shipId = id
            });
        }
        catch (Exception ex)
        {
            _logger.LogError(ex, "Error activating ship {ShipId}", id);
            return StatusCode(500, new { error = "Internal server error" });
        }
    }
}
