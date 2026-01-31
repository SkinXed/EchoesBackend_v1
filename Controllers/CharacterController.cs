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
    /// Get all characters for the authenticated account
    /// GET /api/character/list
    /// </summary>
    [HttpGet("list")]
    [ProducesResponseType(StatusCodes.Status200OK)]
    [ProducesResponseType(StatusCodes.Status401Unauthorized)]
    public async Task<ActionResult<List<CharacterListDto>>> GetCharacters()
    {
        try
        {
            // Extract account ID from JWT token
            var accountIdClaim = User.FindFirst(ClaimTypes.NameIdentifier)?.Value;

            if (string.IsNullOrEmpty(accountIdClaim) || !Guid.TryParse(accountIdClaim, out var accountId))
            {
                return Unauthorized(new { error = "Invalid token - no account ID" });
            }

            var characters = await _context.Characters
                .Where(c => c.AccountId == accountId)
                .Select(c => new CharacterListDto
                {
                    CharacterId = c.Id,
                    Name = c.Name,
                    RaceId = c.RaceId,
                    RaceName = GetRaceName(c.RaceId),
                    WalletBalance = c.WalletBalance,
                    IsMain = c.IsMain,
                    IsOnline = c.IsOnline,
                    IsDocked = c.IsDocked,
                    HomeStationId = c.HomeStationId,
                    CreatedAt = c.CreatedAt,
                    LastLogin = c.LastLogin
                })
                .ToListAsync();

            return Ok(characters);
        }
        catch (Exception ex)
        {
            _logger.LogError(ex, "Error retrieving characters");
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
            var accountIdClaim = User.FindFirst(ClaimTypes.NameIdentifier)?.Value;

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

            // Validate race ID (1-4 for the main races)
            if (request.RaceId < 1 || request.RaceId > 4)
            {
                return BadRequest(new { error = "Invalid race ID. Must be 1 (Caldari), 2 (Gallente), 3 (Amarr), or 4 (Minmatar)" });
            }

            // Get race configuration
            var raceConfig = await _context.RaceConfigs
                .FirstOrDefaultAsync(rc => rc.RaceId == request.RaceId);

            if (raceConfig == null)
            {
                return BadRequest(new { error = $"Race configuration not found for RaceId {request.RaceId}" });
            }

            // Get or create default starting ship
            var startingShip = await _context.ItemTypesInventory
                .FirstOrDefaultAsync(i => i.TypeId == raceConfig.DefaultShipTypeId);

            // Create new character
            var character = new Models.Entities.Character.Character
            {
                Id = Guid.NewGuid(),
                AccountId = accountId,
                Name = request.Name,
                RaceId = request.RaceId,
                BloodlineId = request.BloodlineId,
                AncestryId = request.AncestryId,
                HomeStationId = raceConfig.StartingStationId,
                WalletBalance = raceConfig.StartingISK,
                SecurityStatus = 0.0f,
                TotalSkillPoints = 0,
                UnallocatedSkillPoints = raceConfig.StartingSkillPoints,
                IsOnline = false,
                IsDocked = true,
                InWarp = false,
                CreatedAt = DateTime.UtcNow,
                LastLogin = DateTime.UtcNow
            };

            _context.Characters.Add(character);

            // Create character location at home station
            // Note: Position coordinates will be set from station data when character spawns
            var characterLocation = new CharacterLocation
            {
                Id = Guid.NewGuid(),
                CharacterId = character.Id,
                StationId = raceConfig.StartingStationId,
                SolarSystemId = raceConfig.StartingSystemId,
                LocationType = Models.Enums.LocationType.Docked,
                IsDocked = true,
                InWarp = false,
                LastUpdate = DateTime.UtcNow
            };

            _context.CharacterLocations.Add(characterLocation);

            // TODO: Create default ship in inventory
            // This should be implemented when inventory system is finalized

            await _context.SaveChangesAsync();

            _logger.LogInformation("Created new character {CharacterName} (Race: {RaceId}) for account {AccountId}", 
                character.Name, character.RaceId, accountId);

            var characterData = new CharacterDataDto
            {
                CharacterId = character.Id,
                Name = character.Name,
                AccountId = character.AccountId,
                RaceId = character.RaceId,
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
    /// Get character location (for spawn logic)
    /// GET /api/character/{id}/location
    /// </summary>
    [HttpGet("{id}/location")]
    [ProducesResponseType(StatusCodes.Status200OK)]
    [ProducesResponseType(StatusCodes.Status404NotFound)]
    public async Task<ActionResult<CharacterLocationDto>> GetCharacterLocation(Guid id)
    {
        // Check for server secret if not authenticated as user
        if (!(User.Identity?.IsAuthenticated ?? false))
        {
            if (!ValidateServerSecret())
            {
                return Unauthorized(new { error = "Invalid or missing X-Server-Secret header" });
            }
        }

        try
        {
            var character = await _context.Characters
                .FirstOrDefaultAsync(c => c.Id == id);

            if (character == null)
            {
                return NotFound(new { error = "Character not found" });
            }

            var location = await _context.CharacterLocations
                .Include(cl => cl.Station)
                .Include(cl => cl.SolarSystem)
                .FirstOrDefaultAsync(cl => cl.CharacterId == id);

            if (location == null)
            {
                // If no location exists, create one at home station
                if (character.HomeStationId.HasValue)
                {
                    var homeStation = await _context.Stations
                        .Include(s => s.SolarSystem)
                        .FirstOrDefaultAsync(s => s.Id == character.HomeStationId.Value);

                    if (homeStation != null)
                    {
                        return Ok(new CharacterLocationDto
                        {
                            CharacterId = id,
                            IsDocked = true,
                            InWarp = false,
                            StationId = homeStation.Id,
                            StationName = homeStation.Name,
                            SolarSystemId = homeStation.SolarSystemId,
                            SolarSystemName = homeStation.SolarSystem?.Name ?? "Unknown",
                            PositionX = homeStation.PositionX,
                            PositionY = homeStation.PositionY,
                            PositionZ = homeStation.PositionZ
                        });
                    }
                }

                return NotFound(new { error = "Character location not found" });
            }

            var locationDto = new CharacterLocationDto
            {
                CharacterId = id,
                IsDocked = location.IsDocked,
                InWarp = location.InWarp,
                StationId = location.StationId,
                StationName = location.Station?.Name,
                SolarSystemId = location.SolarSystemId,
                SolarSystemName = location.SolarSystem?.Name,
                PositionX = location.PositionX,
                PositionY = location.PositionY,
                PositionZ = location.PositionZ
            };

            return Ok(locationDto);
        }
        catch (Exception ex)
        {
            _logger.LogError(ex, "Error retrieving character location {CharacterId}", id);
            return StatusCode(500, new { error = "Internal server error" });
        }
    }

    // Helper method to get race name
    private string GetRaceName(int raceId)
    {
        return raceId switch
        {
            1 => "Caldari",
            2 => "Gallente",
            3 => "Amarr",
            4 => "Minmatar",
            _ => "Unknown"
        };
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
