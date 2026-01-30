using Echoes.API.Models.DTOs;

namespace Echoes.API.Services.Ship
{
    /// <summary>
    /// Interface for ship fitting service
    /// Provides methods to calculate ship statistics with fitted modules
    /// </summary>
    public interface IShipFittingService
    {
        /// <summary>
        /// Calculate final ship statistics including all fitted modules
        /// Implements: TotalMass = BaseMass + Σ ModuleMass
        /// Thrust and inertia are also modified by modules
        /// </summary>
        /// <param name="shipInstanceId">Ship instance ID</param>
        /// <returns>Calculated ship statistics or null if ship not found</returns>
        Task<ShipStatsDto?> CalculateShipStatsAsync(Guid shipInstanceId);

        /// <summary>
        /// Add a module to a ship instance with bonuses
        /// </summary>
        Task<bool> AddModuleAsync(Guid shipInstanceId, int moduleTypeId, float mass, string slot, int slotIndex = 0, 
            float thrustBonus = 0, float inertiaModifier = 1.0f, float rotationBonus = 0, float maxVelocityModifier = 1.0f);

        /// <summary>
        /// Remove a module from a ship instance
        /// </summary>
        Task<bool> RemoveModuleAsync(Guid moduleId);

        /// <summary>
        /// Update module bonuses for an existing module
        /// </summary>
        Task<bool> UpdateModuleBonusesAsync(Guid moduleId, float thrustBonus, float inertiaModifier, float rotationBonus, float maxVelocityModifier);
    }
}
