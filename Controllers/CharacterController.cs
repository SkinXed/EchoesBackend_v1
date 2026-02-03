using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using Echoes.API.Data;
using Echoes.API.Models.DTOs;
using Echoes.API.Models.Entities.Character;
using Echoes.API.Models.Entities.Inventory;
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
                Credits = character.WalletBalance,
                SecurityStatus = character.SecurityStatus,
                CurrentShipId = character.ActiveShipItemId,
                CorporationId = character.CorporationId,
                RaceId = character.RaceId,
                TotalSkillPoints = character.TotalSkillPoints,
                ExperiencePoints = character.TotalSkillPoints,
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
                Credits = character.WalletBalance,
                SecurityStatus = character.SecurityStatus,
                CurrentShipId = character.ActiveShipItemId,
                CorporationId = character.CorporationId,
                RaceId = character.RaceId,
                TotalSkillPoints = character.TotalSkillPoints,
                ExperiencePoints = character.TotalSkillPoints,
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

            var characterRows = await _context.Characters
                .Where(c => c.AccountId == accountId)
                .Select(c => new
                {
                    c.Id,
                    c.Name,
                    c.RaceId,
                    c.WalletBalance,
                    Credits = c.WalletBalance,
                    c.TotalSkillPoints,
                    c.IsMain,
                    c.IsOnline,
                    c.IsDocked,
                    c.HomeStationId,
                    c.CreatedAt,
                    c.LastLogin
                })
                .ToListAsync();

            var characters = characterRows
                .Select(c => new CharacterListDto
                {
                    CharacterId = c.Id,
                    Name = c.Name,
                    RaceId = c.RaceId,
                    RaceName = GetRaceName(c.RaceId),
                    WalletBalance = c.WalletBalance,
                    Credits = c.Credits,
                    TotalSkillPoints = c.TotalSkillPoints,
                    IsMain = c.IsMain,
                    IsOnline = c.IsOnline,
                    IsDocked = c.IsDocked,
                    HomeStationId = c.HomeStationId,
                    CreatedAt = c.CreatedAt,
                    LastLogin = c.LastLogin
                })
                .ToList();

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

            var existingCount = await _context.Characters.CountAsync(c => c.AccountId == accountId);
            if (existingCount >= 3)
            {
                return BadRequest(new { error = "Character limit reached (max 3)" });
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
            
            // Validate faction ID (1-4 for the main factions)
            if (request.FactionId < 1 || request.FactionId > 4)
            {
                return BadRequest(new { error = "Invalid faction ID. Must be 1 (Solaris), 2 (Krios), 3 (Acheron), or 4 (Valerion)" });
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

            // Determine starting location based on FactionId
            Guid startingSystemId;
            Guid startingStationId;
            
            switch (request.FactionId)
            {
                case 1: // Solaris - Genesis/Apex Terminal
                    startingSystemId = Echoes.API.Services.UniverseGeneration.UniverseGenerator.GENESIS_SYSTEM_ID;
                    startingStationId = Echoes.API.Services.UniverseGeneration.UniverseGenerator.APEX_TERMINAL_STATION_ID;
                    break;
                case 2: // Krios - Zenith/Vertex Hub
                    startingSystemId = Echoes.API.Services.UniverseGeneration.UniverseGenerator.ZENITH_SYSTEM_ID;
                    startingStationId = Echoes.API.Services.UniverseGeneration.UniverseGenerator.VERTEX_HUB_STATION_ID;
                    break;
                case 3: // Acheron - Nadir/Obelisk Bastion
                    startingSystemId = Echoes.API.Services.UniverseGeneration.UniverseGenerator.NADIR_SYSTEM_ID;
                    startingStationId = Echoes.API.Services.UniverseGeneration.UniverseGenerator.OBELISK_BASTION_STATION_ID;
                    break;
                case 4: // Valerion - Aegis/Sanctuary Anchor
                    startingSystemId = Echoes.API.Services.UniverseGeneration.UniverseGenerator.AEGIS_SYSTEM_ID;
                    startingStationId = Echoes.API.Services.UniverseGeneration.UniverseGenerator.SANCTUARY_ANCHOR_STATION_ID;
                    break;
                default:
                    return BadRequest(new { error = "Invalid faction ID" });
            }
            
            // Verify starting station exists
            var startingStation = await _context.Stations
                .FirstOrDefaultAsync(s => s.Id == startingStationId);

            if (startingStation == null)
            {
                return BadRequest(new { error = $"Starting station not found for faction {request.FactionId}. Please ensure the universe has been generated." });
            }

            // Verify solar system exists
            var solarSystemExists = await _context.SolarSystems
                .AnyAsync(s => s.Id == startingSystemId);

            if (!solarSystemExists)
            {
                return BadRequest(new { error = $"Starting system not found for faction {request.FactionId}. Please ensure the universe has been generated." });
            }

            // Create new character
            var character = new Models.Entities.Character.Character
            {
                Id = Guid.NewGuid(),
                AccountId = accountId,
                Name = request.Name,
                RaceId = request.RaceId,
                BloodlineId = request.BloodlineId,
                AncestryId = request.AncestryId,
                HomeStationId = startingStationId, // Use faction-based starting station
                WalletBalance = raceConfig.StartingISK,
                SecurityStatus = 0.0f,
                TotalSkillPoints = 0,
                UnallocatedSkillPoints = raceConfig.StartingSkillPoints,
                IsOnline = false,
                IsDocked = true, // All new characters start docked
                InWarp = false,
                CreatedAt = DateTime.UtcNow,
                LastLogin = DateTime.UtcNow
            };

            _context.Characters.Add(character);

            // Create character location at faction's home station
            var characterLocation = new CharacterLocation
            {
                Id = Guid.NewGuid(),
                CharacterId = character.Id,
                StationId = startingStationId, // Use faction-based starting station
                SolarSystemId = startingSystemId, // Use faction-based starting system
                LocationType = Models.Enums.LocationType.Docked,
                IsDocked = true,
                InWarp = false,
                HangarInstanceId = Guid.NewGuid(), // Create unique hangar instance for this character
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
                Credits = character.WalletBalance,
                SecurityStatus = character.SecurityStatus,
                CurrentShipId = character.ActiveShipItemId,
                TotalSkillPoints = character.TotalSkillPoints,
                ExperiencePoints = character.TotalSkillPoints,
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
                        // Create new location with hangar instance
                        var hangarInstanceId = Guid.NewGuid();
                        
                        var newLocation = new CharacterLocation
                        {
                            Id = Guid.NewGuid(),
                            CharacterId = id,
                            StationId = homeStation.Id,
                            SolarSystemId = homeStation.SolarSystemId,
                            PositionX = homeStation.PositionX,
                            PositionY = homeStation.PositionY,
                            PositionZ = homeStation.PositionZ,
                            IsDocked = true,
                            InWarp = false,
                            HangarInstanceId = hangarInstanceId,
                            LocationType = Models.Enums.LocationType.Docked,
                            LastUpdate = DateTime.UtcNow
                        };
                        
                        _context.CharacterLocations.Add(newLocation);
                        await _context.SaveChangesAsync();
                        
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
                            PositionZ = homeStation.PositionZ,
                            HangarInstanceId = hangarInstanceId
                        });
                    }
                }

                return NotFound(new { error = "Character location not found" });
            }

            // Ensure HangarInstanceId exists for existing location
            if (!location.HangarInstanceId.HasValue)
            {
                location.HangarInstanceId = Guid.NewGuid();
                _context.CharacterLocations.Update(location);
                await _context.SaveChangesAsync();
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
                PositionZ = location.PositionZ,
                HangarInstanceId = location.HangarInstanceId.Value
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
    /// Get character connection info for regional server
    /// GET /api/character/{id}/connect-info
    /// </summary>
    [HttpGet("{id}/connect-info")]
    [ProducesResponseType(StatusCodes.Status200OK)]
    [ProducesResponseType(StatusCodes.Status404NotFound)]
    [ProducesResponseType(StatusCodes.Status401Unauthorized)]
    public async Task<ActionResult<CharacterConnectInfoDto>> GetCharacterConnectInfo(Guid id)
    {
        try
        {
            // Check authentication
            var characterIdClaim = User.FindFirst("CharacterId")?.Value;
            if (string.IsNullOrEmpty(characterIdClaim) || !Guid.TryParse(characterIdClaim, out var tokenCharacterId))
            {
                return Unauthorized(new { error = "Invalid token - no character ID" });
            }

            // Verify the character belongs to the authenticated user
            if (tokenCharacterId != id)
            {
                return Unauthorized(new { error = "Not authorized to access this character" });
            }

            var character = await _context.Characters
                .Include(c => c.CurrentLocation)
                .ThenInclude(cl => cl!.SolarSystem)
                .FirstOrDefaultAsync(c => c.Id == id);

            if (character == null)
            {
                return NotFound(new { error = "Character not found" });
            }

            // Get solar system for regional server assignment
            var solarSystem = character.CurrentLocation?.SolarSystem;
            string serverIP = "127.0.0.1"; // Default to localhost
            int serverPort = 7777; // Default game port

            // TODO: In production, query game server assignment based on solar system
            // For now, return default local server
            if (solarSystem != null)
            {
                // Logic to determine which regional server handles this system
                // This would query a ServerNodes table or configuration
                _logger.LogInformation("Character {CharacterId} connecting to system {SystemId}", 
                    id, solarSystem.Id);
            }

            var connectInfo = new CharacterConnectInfoDto
            {
                CharacterId = id,
                CharacterName = character.Name,
                ServerIP = serverIP,
                ServerPort = serverPort,
                SystemId = solarSystem?.Id ?? Guid.Empty,
                SystemName = solarSystem?.Name ?? "Unknown",
                IsDocked = character.IsDocked,
                StationId = character.CurrentLocation?.StationId,
                ConnectionToken = Guid.NewGuid().ToString() // Generate one-time connection token
            };

            return Ok(connectInfo);
        }
        catch (Exception ex)
        {
            _logger.LogError(ex, "Error retrieving character connect info {CharacterId}", id);
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

    /// <summary>
    /// Delete a character for the authenticated account
    /// DELETE /api/character/{id}
    /// </summary>
    [HttpDelete("{id}")]
    [ProducesResponseType(StatusCodes.Status200OK)]
    [ProducesResponseType(StatusCodes.Status400BadRequest)]
    [ProducesResponseType(StatusCodes.Status401Unauthorized)]
    [ProducesResponseType(StatusCodes.Status404NotFound)]
    public async Task<ActionResult> DeleteCharacter(Guid id)
    {
        try
        {
            var accountIdClaim = User.FindFirst(ClaimTypes.NameIdentifier)?.Value;

            if (string.IsNullOrEmpty(accountIdClaim) || !Guid.TryParse(accountIdClaim, out var accountId))
            {
                return Unauthorized(new { error = "Invalid token - no account ID" });
            }

            var character = await _context.Characters
                .FirstOrDefaultAsync(c => c.Id == id && c.AccountId == accountId);

            if (character == null)
            {
                return NotFound(new { error = "Character not found" });
            }

            if (character.IsOnline)
            {
                return BadRequest(new { error = "Cannot delete an online character" });
            }

            var executionStrategy = _context.Database.CreateExecutionStrategy();
            await executionStrategy.ExecuteAsync(async () =>
            {
                await using var transaction = await _context.Database.BeginTransactionAsync();

                _context.AccountSessions.RemoveRange(_context.AccountSessions.Where(s => s.CharacterId == id));

                _context.CharacterContracts.RemoveRange(
                    _context.CharacterContracts.Where(c => c.IssuerId == id || c.AssigneeId == id || c.AcceptorId == id));

                _context.CharacterLocations.RemoveRange(_context.CharacterLocations.Where(cl => cl.CharacterId == id));

                _context.Set<CharacterClone>().RemoveRange(_context.Set<CharacterClone>().Where(c => c.CharacterId == id));
                _context.Set<CharacterSkill>().RemoveRange(_context.Set<CharacterSkill>().Where(s => s.CharacterId == id));
                _context.Set<CharacterSkillEnhanced>().RemoveRange(_context.Set<CharacterSkillEnhanced>().Where(s => s.CharacterId == id));
                _context.Set<CharacterImplant>().RemoveRange(_context.Set<CharacterImplant>().Where(i => i.CharacterId == id));
                _context.Set<CharacterImplantEnhanced>().RemoveRange(_context.Set<CharacterImplantEnhanced>().Where(i => i.CharacterId == id));
                _context.Set<CharacterStanding>().RemoveRange(_context.Set<CharacterStanding>().Where(s => s.CharacterId == id));
                _context.Set<TrainingQueue>().RemoveRange(_context.Set<TrainingQueue>().Where(q => q.CharacterId == id));

                var walletIds = await _context.Set<CharacterWallet>()
                    .Where(w => w.CharacterId == id)
                    .Select(w => w.WalletId)
                    .ToListAsync();

                if (walletIds.Count > 0)
                {
                    _context.Set<WalletTransaction>().RemoveRange(
                        _context.Set<WalletTransaction>().Where(t => walletIds.Contains(t.WalletId)));
                }

                _context.Set<CharacterWallet>().RemoveRange(_context.Set<CharacterWallet>().Where(w => w.CharacterId == id));

                var shipInstanceIds = await _context.ShipInstances
                    .Where(s => s.CharacterId == id)
                    .Select(s => s.Id)
                    .ToListAsync();

                if (shipInstanceIds.Count > 0)
                {
                    _context.ShipInstanceModules.RemoveRange(
                        _context.ShipInstanceModules.Where(m => m.ShipInstanceId != null && shipInstanceIds.Contains(m.ShipInstanceId.Value)));
                }

                _context.ShipInstances.RemoveRange(_context.ShipInstances.Where(s => s.CharacterId == id));

                character.ActiveShipItemId = null;
                await _context.Database.ExecuteSqlInterpolatedAsync($"DELETE FROM inventory_items WHERE \"CharacterId\" = {id}");
                _context.Set<InventoryItem>().RemoveRange(_context.Set<InventoryItem>().Where(i => i.OwnerId == id));
                
                _context.Characters.Remove(character);
                await _context.SaveChangesAsync();
                await transaction.CommitAsync();
            });

            _logger.LogInformation("Deleted character {CharacterId} for account {AccountId}", id, accountId);

            return Ok(new { message = "Character deleted" });
        }
        catch (Exception ex)
        {
            _logger.LogError(ex, "Error deleting character {CharacterId}", id);
            return StatusCode(500, new { error = "Internal server error" });
        }
    }
}
