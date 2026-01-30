using Echoes.API.Data;
using Echoes.API.Models.DTOs;
using Echoes.API.Models.Entities.Inventory;
using Microsoft.EntityFrameworkCore;

namespace Echoes.API.Services.Ship
{
    /// <summary>
    /// Service for calculating ship statistics with fitted modules
    /// Implements the formula: TotalMass = BaseMass + Σ ModMass
    /// Also applies module bonuses for thrust, inertia, rotation, and velocity
    /// </summary>
    public class ShipFittingService : IShipFittingService
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
        /// Implements: TotalMass = BaseMass + Σ ModuleMass
        /// TotalThrust = BaseThrust + Σ ThrustBonus
        /// TotalInertia = BaseInertia * Π InertiaModifier
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

            // Get online modules only
            var onlineModules = shipInstance.FittedModules.Where(m => m.IsOnline).ToList();

            // Calculate total mass: BaseMass + Σ ModuleMass
            var moduleMass = onlineModules.Sum(m => m.Mass);
            var totalMass = shipInstance.ShipType.BaseMass + moduleMass;

            // Calculate total thrust: BaseThrust + Σ ThrustBonus (additive)
            var thrustBonus = onlineModules.Sum(m => m.ThrustBonus);
            var totalThrust = shipInstance.ShipType.Thrust + thrustBonus;

            // Calculate total inertia: BaseInertia * Π InertiaModifier (multiplicative)
            // Lower inertia = better agility, so modules with < 1.0 improve performance
            var inertiaMultiplier = shipInstance.ShipType.InertiaMultiplier;
            foreach (var module in onlineModules)
            {
                inertiaMultiplier *= module.InertiaModifier;
            }

            // Calculate total rotation: BaseRotation + Σ RotationBonus (additive)
            var rotationBonus = onlineModules.Sum(m => m.RotationBonus);
            var totalRotation = shipInstance.ShipType.RotationSpeed + rotationBonus;

            // Calculate max velocity: BaseVelocity * Π MaxVelocityModifier (multiplicative)
            var maxVelocityModifier = 1.0m;
            foreach (var module in onlineModules)
            {
                maxVelocityModifier *= module.MaxVelocityModifier;
            }
            var totalMaxVelocity = shipInstance.ShipType.MaxVelocity * maxVelocityModifier;

            _logger.LogInformation(
                "Calculated stats for ship {ShipId}: " +
                "Mass={BaseMass}+{ModuleMass}={TotalMass}, " +
                "Thrust={BaseThrust}+{ThrustBonus}={TotalThrust}, " +
                "Inertia={BaseInertia}*mods={FinalInertia}",
                shipInstanceId, 
                shipInstance.ShipType.BaseMass, moduleMass, totalMass,
                shipInstance.ShipType.Thrust, thrustBonus, totalThrust,
                shipInstance.ShipType.InertiaMultiplier, inertiaMultiplier);

            return new ShipStatsDto
            {
                ShipId = shipInstance.Id,
                ShipName = shipInstance.Name,
                ShipTypeId = shipInstance.ShipTypeId,
                ShipTypeName = shipInstance.ShipType.Name,
                BaseMass = (float)shipInstance.ShipType.BaseMass,
                TotalMass = (float)totalMass,
                Thrust = (float)totalThrust,
                RotationSpeed = (float)totalRotation,
                WarpSpeed = (float)shipInstance.ShipType.WarpSpeed,
                InertiaMultiplier = (float)inertiaMultiplier,
                MaxVelocity = (float)totalMaxVelocity,
                Agility = (float)shipInstance.ShipType.BaseAgility
            };
        }

        /// <summary>
        /// Add a module to a ship instance with bonuses
        /// </summary>
        public async Task<bool> AddModuleAsync(
            Guid shipInstanceId, 
            int moduleTypeId, 
            float mass, 
            string slot, 
            int slotIndex = 0,
            float thrustBonus = 0, 
            float inertiaModifier = 1.0f, 
            float rotationBonus = 0, 
            float maxVelocityModifier = 1.0f)
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
                IsOnline = true,
                ThrustBonus = (decimal)thrustBonus,
                InertiaModifier = (decimal)inertiaModifier,
                RotationBonus = (decimal)rotationBonus,
                MaxVelocityModifier = (decimal)maxVelocityModifier
            };

            _context.ShipInstanceModules.Add(module);
            await _context.SaveChangesAsync();

            _logger.LogInformation(
                "Added module {ModuleTypeId} to ship {ShipId}: Mass={Mass}, Thrust={Thrust}, Inertia={Inertia}",
                moduleTypeId, shipInstanceId, mass, thrustBonus, inertiaModifier);
            
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

        /// <summary>
        /// Update module bonuses for an existing module
        /// </summary>
        public async Task<bool> UpdateModuleBonusesAsync(
            Guid moduleId, 
            float thrustBonus, 
            float inertiaModifier, 
            float rotationBonus, 
            float maxVelocityModifier)
        {
            var module = await _context.ShipInstanceModules.FindAsync(moduleId);
            if (module == null)
            {
                _logger.LogWarning("Cannot update bonuses: Module {ModuleId} not found", moduleId);
                return false;
            }

            module.ThrustBonus = (decimal)thrustBonus;
            module.InertiaModifier = (decimal)inertiaModifier;
            module.RotationBonus = (decimal)rotationBonus;
            module.MaxVelocityModifier = (decimal)maxVelocityModifier;

            await _context.SaveChangesAsync();

            _logger.LogInformation(
                "Updated bonuses for module {ModuleId}: Thrust={Thrust}, Inertia={Inertia}, Rotation={Rotation}, MaxVel={MaxVel}",
                moduleId, thrustBonus, inertiaModifier, rotationBonus, maxVelocityModifier);

            return true;
        }
    }
}
