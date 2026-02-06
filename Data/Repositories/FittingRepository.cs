using Echoes.API.Data;
using Echoes.API.Models.DTOs.Fitting;
using Microsoft.EntityFrameworkCore;
using Npgsql;

namespace Echoes.API.Data.Repositories
{
    /// <summary>
    /// Repository for ship fitting data
    /// Handles database queries for character equipment/fitting
    /// </summary>
    public class FittingRepository
    {
        private readonly DatabaseContext _context;
        private readonly ILogger<FittingRepository> _logger;

        public FittingRepository(DatabaseContext context, ILogger<FittingRepository> logger)
        {
            _context = context;
            _logger = logger;
        }

        /// <summary>
        /// Get character's ship fitting from database
        /// Returns complete fitting data with all equipped modules
        /// </summary>
        /// <param name="characterId">Character ID (Guid as string)</param>
        /// <returns>Complete fitting data or null if not found</returns>
        public async Task<FittingResponse?> GetCharacterFittingAsync(string characterId)
        {
            try
            {
                _logger.LogInformation("Fetching fitting data for character {CharacterId}", characterId);

                // Validate character ID format
                if (!Guid.TryParse(characterId, out var charGuid))
                {
                    _logger.LogWarning("Invalid character ID format: {CharacterId}", characterId);
                    return null;
                }

                // Get character and active ship
                var character = await _context.Characters
                    .Include(c => c.ActiveShip)
                    .ThenInclude(ship => ship!.ItemType)
                    .FirstOrDefaultAsync(c => c.Id == charGuid);

                if (character == null)
                {
                    _logger.LogWarning("Character not found: {CharacterId}", characterId);
                    return null;
                }

                if (character.ActiveShip == null || character.ActiveShipItemId == null)
                {
                    _logger.LogWarning("Character {CharacterId} has no active ship", characterId);
                    return null;
                }

                // Get all modules fitted to the active ship
                var fittedModules = await _context.InventoryItems
                    .Include(i => i.ItemType)
                    .Where(i => i.FittedToShipId == character.ActiveShipItemId)
                    .ToListAsync();

                _logger.LogInformation("Found {Count} fitted modules for character {CharacterId}", 
                    fittedModules.Count, characterId);

                // Build fitting response
                var response = new FittingResponse
                {
                    CharacterId = 0, // Will be set from parsed characterId if needed
                    ShipItemId = character.ActiveShipItemId.Value,
                    ShipTypeName = character.ActiveShip.ItemType?.Name ?? "Unknown Ship",
                    
                    // Resource limits (these should come from ship type data in production)
                    PowergridMax = 100.0f,
                    CPUMax = 100.0f,
                    
                    // Default stats (calculated from ship base + modules in production)
                    MaxSpeed = 100.0f,
                    WarpSpeed = 3.0f,
                    ScanResolution = 100.0f,
                    SignatureRadius = 50.0f
                };

                // Group modules by slot type
                float powerUsed = 0;
                float cpuUsed = 0;

                foreach (var module in fittedModules)
                {
                    var slotResponse = new ItemSlotResponse
                    {
                        SlotIndex = module.FittedSlotIndex ?? 0,
                        SlotType = DetermineSlotType(module.FittedSlotType),
                        ItemID = (int)(module.ItemTypeId % int.MaxValue), // Convert long to int safely
                        ItemName = module.ItemType?.Name ?? "Unknown Module",
                        Quantity = module.Quantity,
                        Cooldown = 0.0f,
                        ModuleState = "Offline",
                        IsActive = false,
                        CanActivate = true,
                        PowergridRequired = GetModulePowergrid(module.ItemType?.Name ?? ""),
                        CPURequired = GetModuleCPU(module.ItemType?.Name ?? ""),
                        CapacitorCost = GetModuleCapCost(module.ItemType?.Name ?? "")
                    };

                    powerUsed += slotResponse.PowergridRequired;
                    cpuUsed += slotResponse.CPURequired;

                    // Add to appropriate slot array based on slot type
                    switch (module.FittedSlotType?.ToLower())
                    {
                        case "high":
                            response.HighSlots.Add(slotResponse);
                            break;
                        case "mid":
                        case "medium":
                            response.MidSlots.Add(slotResponse);
                            break;
                        case "low":
                            response.LowSlots.Add(slotResponse);
                            break;
                        case "rig":
                            response.RigSlots.Add(slotResponse);
                            break;
                        default:
                            _logger.LogWarning("Unknown slot type: {SlotType} for module {ModuleName}", 
                                module.FittedSlotType, module.ItemType?.Name);
                            break;
                    }
                }

                response.PowergridUsed = powerUsed;
                response.CPUUsed = cpuUsed;

                // Calculate stats (simplified for now)
                response.TotalDPS = CalculateDPS(response.HighSlots);
                response.AlphaStrike = CalculateAlphaStrike(response.HighSlots);
                response.EffectiveHP = CalculateEHP(response.MidSlots, response.LowSlots);

                _logger.LogInformation("Successfully built fitting response for character {CharacterId}: " +
                    "{HighCount} high, {MidCount} mid, {LowCount} low, {RigCount} rig slots",
                    characterId, response.HighSlots.Count, response.MidSlots.Count, 
                    response.LowSlots.Count, response.RigSlots.Count);

                return response;
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error fetching fitting data for character {CharacterId}", characterId);
                throw;
            }
        }

        /// <summary>
        /// Determine slot type from database string
        /// </summary>
        private string DetermineSlotType(string? slotType)
        {
            return slotType?.ToLower() switch
            {
                "high" => "High",
                "mid" or "medium" => "Mid",
                "low" => "Low",
                "rig" => "Rig",
                "subsystem" => "Subsystem",
                _ => "None"
            };
        }

        /// <summary>
        /// Get module powergrid requirement (placeholder - should come from item_types table)
        /// </summary>
        private float GetModulePowergrid(string moduleName)
        {
            // TODO: Get from database item_types table
            // For now, return estimated values based on module type
            if (moduleName.Contains("Weapon") || moduleName.Contains("Turret") || moduleName.Contains("Launcher"))
                return 15.0f;
            if (moduleName.Contains("Shield") || moduleName.Contains("Armor"))
                return 10.0f;
            return 5.0f;
        }

        /// <summary>
        /// Get module CPU requirement (placeholder - should come from item_types table)
        /// </summary>
        private float GetModuleCPU(string moduleName)
        {
            // TODO: Get from database item_types table
            if (moduleName.Contains("Weapon") || moduleName.Contains("Turret") || moduleName.Contains("Launcher"))
                return 20.0f;
            if (moduleName.Contains("Shield") || moduleName.Contains("Armor"))
                return 15.0f;
            return 10.0f;
        }

        /// <summary>
        /// Get module capacitor cost (placeholder - should come from item_types table)
        /// </summary>
        private float GetModuleCapCost(string moduleName)
        {
            // TODO: Get from database item_types table
            if (moduleName.Contains("Weapon") || moduleName.Contains("Turret") || moduleName.Contains("Launcher"))
                return 50.0f;
            if (moduleName.Contains("Shield") || moduleName.Contains("Repairer"))
                return 40.0f;
            return 25.0f;
        }

        /// <summary>
        /// Calculate total DPS from weapon modules
        /// </summary>
        private float CalculateDPS(List<ItemSlotResponse> highSlots)
        {
            // Simplified calculation - should use actual weapon stats from database
            float totalDPS = 0;
            foreach (var slot in highSlots)
            {
                if (slot.ItemName.Contains("Weapon") || slot.ItemName.Contains("Turret") || 
                    slot.ItemName.Contains("Launcher"))
                {
                    totalDPS += 100.0f; // Placeholder DPS per weapon
                }
            }
            return totalDPS;
        }

        /// <summary>
        /// Calculate alpha strike damage
        /// </summary>
        private float CalculateAlphaStrike(List<ItemSlotResponse> highSlots)
        {
            // Simplified - should use actual weapon damage from database
            float totalAlpha = 0;
            foreach (var slot in highSlots)
            {
                if (slot.ItemName.Contains("Weapon") || slot.ItemName.Contains("Turret") || 
                    slot.ItemName.Contains("Launcher"))
                {
                    totalAlpha += 500.0f; // Placeholder alpha per weapon
                }
            }
            return totalAlpha;
        }

        /// <summary>
        /// Calculate effective HP from tank modules
        /// </summary>
        private float CalculateEHP(List<ItemSlotResponse> midSlots, List<ItemSlotResponse> lowSlots)
        {
            // Simplified - should calculate with resistances
            float baseHP = 10000.0f;
            
            // Add bonuses from shield modules
            foreach (var slot in midSlots)
            {
                if (slot.ItemName.Contains("Shield"))
                    baseHP += 2000.0f;
            }
            
            // Add bonuses from armor modules
            foreach (var slot in lowSlots)
            {
                if (slot.ItemName.Contains("Armor"))
                    baseHP += 1500.0f;
            }
            
            return baseHP;
        }
    }
}
