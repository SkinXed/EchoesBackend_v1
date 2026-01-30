using Echoes.API.Data;
using Echoes.API.Models.DTOs;
using Echoes.API.Models.Entities.Inventory;
using Microsoft.EntityFrameworkCore;

namespace Echoes.API.Services.Ship
{
    /// <summary>
    /// Service for calculating ship statistics with fitted modules
    /// Implements the formula: TotalMass = BaseMass + Σ ModMass
    /// </summary>
    public class ShipFittingService
    {
        private readonly DatabaseContext _context;
        private readonly ILogger<ShipFittingService> _logger;

        public ShipFittingService(DatabaseContext context, ILogger<ShipFittingService> logger)
        {
            _context = context;
            _logger = logger;
        }

        /// <summary>
        /// Calculate final ship statistics including all fitted modules
        /// </summary>
        /// <param name="shipInstanceId">Ship instance ID</param>
        /// <returns>Calculated ship statistics or null if ship not found</returns>
        public async Task<ShipStatsDto?> CalculateShipStatsAsync(Guid shipInstanceId)
        {
            var shipInstance = await _context.ShipInstances
                .Include(s => s.ShipType)
                .Include(s => s.FittedModules)
                .FirstOrDefaultAsync(s => s.Id == shipInstanceId && s.IsActive);

            if (shipInstance == null)
            {
                _logger.LogWarning("Ship instance {ShipInstanceId} not found or inactive", shipInstanceId);
                return null;
            }

            if (shipInstance.ShipType == null)
            {
                _logger.LogError("Ship instance {ShipInstanceId} has no ship type configured", shipInstanceId);
                return null;
            }

            // Calculate total mass: BaseMass + Σ ModMass
            var moduleMass = shipInstance.FittedModules
                .Where(m => m.IsOnline)
                .Sum(m => m.Mass);

            var totalMass = shipInstance.ShipType.BaseMass + moduleMass;

            _logger.LogInformation(
                "Calculated stats for ship instance {ShipInstanceId}: BaseMass={BaseMass}, ModuleMass={ModuleMass}, TotalMass={TotalMass}",
                shipInstanceId, shipInstance.ShipType.BaseMass, moduleMass, totalMass);

            return new ShipStatsDto
            {
                ShipId = shipInstance.Id,
                ShipName = shipInstance.Name,
                ShipTypeId = shipInstance.ShipTypeId,
                ShipTypeName = shipInstance.ShipType.Name,
                BaseMass = (float)shipInstance.ShipType.BaseMass,
                TotalMass = (float)totalMass,
                Thrust = (float)shipInstance.ShipType.Thrust,
                RotationSpeed = (float)shipInstance.ShipType.RotationSpeed,
                WarpSpeed = (float)shipInstance.ShipType.WarpSpeed,
                InertiaMultiplier = (float)shipInstance.ShipType.InertiaMultiplier,
                MaxVelocity = (float)shipInstance.ShipType.MaxVelocity,
                Agility = (float)shipInstance.ShipType.BaseAgility
            };
        }

        /// <summary>
        /// Add a module to a ship instance
        /// </summary>
        public async Task<bool> AddModuleAsync(Guid shipInstanceId, int moduleTypeId, float mass, string slot, int slotIndex = 0)
        {
            var shipInstance = await _context.ShipInstances.FindAsync(shipInstanceId);
            if (shipInstance == null)
            {
                _logger.LogWarning("Cannot add module: Ship instance {ShipInstanceId} not found", shipInstanceId);
                return false;
            }

            var module = new ShipInstanceModule
            {
                Id = Guid.NewGuid(),
                ShipInstanceId = shipInstanceId,
                ModuleTypeId = moduleTypeId,
                Mass = (decimal)mass,
                Slot = slot,
                SlotIndex = slotIndex,
                IsOnline = true
            };

            _context.ShipInstanceModules.Add(module);
            await _context.SaveChangesAsync();

            _logger.LogInformation("Added module {ModuleTypeId} to ship instance {ShipInstanceId}", moduleTypeId, shipInstanceId);
            return true;
        }

        /// <summary>
        /// Remove a module from a ship instance
        /// </summary>
        public async Task<bool> RemoveModuleAsync(Guid moduleId)
        {
            var module = await _context.ShipInstanceModules.FindAsync(moduleId);
            if (module == null)
            {
                return false;
            }

            _context.ShipInstanceModules.Remove(module);
            await _context.SaveChangesAsync();

            _logger.LogInformation("Removed module {ModuleId} from ship instance {ShipInstanceId}", moduleId, module.ShipInstanceId);
            return true;
        }
    }
}
