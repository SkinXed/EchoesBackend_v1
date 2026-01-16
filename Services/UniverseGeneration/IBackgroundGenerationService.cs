using Echoes.API.Models.DTOs.Game;

namespace Echoes.API.Services.UniverseGeneration
{
    /// <summary>
    /// Service for background universe generation
    /// </summary>
    public interface IBackgroundGenerationService
    {
        /// <summary>
        /// Start universe generation in background
        /// </summary>
        Task<Guid> StartUniverseGenerationAsync(bool clearFirst, bool force);

        /// <summary>
        /// Get status of a background generation job
        /// </summary>
        Task<GenerationStatusDto?> GetGenerationStatusAsync(Guid generationId);
    }
}
