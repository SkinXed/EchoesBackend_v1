using Echoes.API.Models.Entities.Universe;
using ModelsUniverseStats = Echoes.API.Models.Entities.Universe.UniverseStats;

namespace Echoes.API.Services.UniverseGeneration
{
    /// <summary>
    /// Service for universe generation operations
    /// </summary>
    public interface IUniverseGenerationService
    {
        /// <summary>
        /// Get universe statistics
        /// </summary>
        Task<ModelsUniverseStats> GetUniverseStatsAsync();

        /// <summary>
        /// Clear the entire universe
        /// </summary>
        Task ClearUniverseAsync();
    }
}
