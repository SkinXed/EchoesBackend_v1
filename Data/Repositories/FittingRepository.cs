using Echoes.API.Data;
using Echoes.API.Models.DTOs.Fitting;
using Echoes.API.Models.Entities.Inventory;
using Microsoft.EntityFrameworkCore;

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

                // Get character
                var character = await _context.Characters
                    .FirstOrDefaultAsync(c => c.Id == charGuid);

                if (character == null)
                {
                    _logger.LogWarning("Character not found: {CharacterId}", characterId);
                    return null;
                }

                // Find active ship fitting for this character via Asset ownership
                var activeFitting = await _context.ShipFittings
                    .Include(sf => sf.ShipAsset)
                        .ThenInclude(a => a.ItemType)
                    .Include(sf => sf.FittedModules)
                        .ThenInclude(fm => fm.ModuleAsset)
                            .ThenInclude(a => a.ItemType)
                    .Where(sf => sf.ShipAsset.OwnerId == charGuid && sf.IsActive)
                    .FirstOrDefaultAsync();

                if (activeFitting == null)
                {
                    _logger.LogWarning("Character {CharacterId} has no active ship fitting", characterId);
                    return null;
                }

                _logger.LogInformation("Found {Count} fitted modules for character {CharacterId}", 
                    activeFitting.FittedModules.Count, characterId);

                // Build fitting response
                var response = new FittingResponse
                {
                    CharacterId = 0,
                    ShipItemId = character.ActiveShipItemId ?? 0,
                    ShipTypeName = activeFitting.ShipAsset.ItemType?.Name ?? "Unknown Ship",
                    
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

                foreach (var module in activeFitting.FittedModules)
                {
                    var slotTypeName = MapSlotType(module.SlotType);
                    var moduleName = module.ModuleAsset?.ItemType?.Name ?? "Unknown Module";

                    var slotResponse = new ItemSlotResponse
                    {
                        SlotIndex = module.SlotNumber,
                        SlotType = DetermineSlotType(slotTypeName),
                        ItemID = module.ModuleAsset?.ItemType?.TypeId ?? 0,
                        ItemName = moduleName,
                        Quantity = 1,
                        Cooldown = 0.0f,
                        ModuleState = module.IsOnline ? "Active" : "Offline",
                        IsActive = module.IsOnline,
                        CanActivate = true,
                        PowergridRequired = GetModulePowergrid(moduleName),
                        CPURequired = GetModuleCPU(moduleName),
                        CapacitorCost = GetModuleCapCost(moduleName)
                    };

                    powerUsed += slotResponse.PowergridRequired;
                    cpuUsed += slotResponse.CPURequired;

                    // Add to appropriate slot array based on slot type
                    switch (slotTypeName)
                    {
                        case "high":
                            response.HighSlots.Add(slotResponse);
                            break;
                        case "mid":
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
                                module.SlotType, moduleName);
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
        /// Map integer slot type from FittedModule to string name
        /// </summary>
        private string MapSlotType(int slotType)
        {
            return slotType switch
            {
                0 => "high",
                1 => "mid",
                2 => "low",
                3 => "rig",
                4 => "subsystem",
                _ => "unknown"
            };
        }

        /// <summary>
        /// Determine display slot type name
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
