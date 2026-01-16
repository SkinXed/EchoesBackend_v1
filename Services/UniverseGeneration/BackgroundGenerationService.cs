using Echoes.API.Data;
using Echoes.API.Models.Config;
using Echoes.API.Models.DTOs.Game;
using Echoes.API.Models.Entities.Universe;
using Microsoft.Extensions.Options;
using System.Collections.Concurrent;
using ModelsUniverseStats = Echoes.API.Models.Entities.Universe.UniverseStats;

namespace Echoes.API.Services.UniverseGeneration
{
    /// <summary>
    /// Service for managing background universe generation tasks
    /// </summary>
    public class BackgroundGenerationService : IBackgroundGenerationService
    {
        private readonly IServiceScopeFactory _scopeFactory;
        private readonly ILogger<BackgroundGenerationService> _logger;
        private readonly ConcurrentDictionary<Guid, GenerationStatusDto> _generationStatus = new();

        public BackgroundGenerationService(
            IServiceScopeFactory scopeFactory,
            ILogger<BackgroundGenerationService> logger)
        {
            _scopeFactory = scopeFactory;
            _logger = logger;
        }

        public Task<Guid> StartUniverseGenerationAsync(bool clearFirst, bool force)
        {
            var generationId = Guid.NewGuid();

            // Initialize status
            _generationStatus[generationId] = new GenerationStatusDto
            {
                Id = generationId,
                Status = "Running",
                Message = "Universe generation started",
                Progress = 0,
                StartedAt = DateTime.UtcNow
            };

            // Start background task
            Task.Run(async () =>
            {
                using var scope = _scopeFactory.CreateScope();
                var context = scope.ServiceProvider.GetRequiredService<DatabaseContext>();
                var universeGeneratorLogger = scope.ServiceProvider.GetRequiredService<ILogger<UniverseGenerator>>();
                var universeConfig = scope.ServiceProvider.GetRequiredService<IOptions<UniverseConfig>>();

                try
                {
                    _logger.LogInformation("🏁 Starting background universe generation {GenerationId}...", generationId);

                    var generator = new UniverseGenerator(context, universeGeneratorLogger, universeConfig);

                    if (clearFirst)
                    {
                        _logger.LogInformation("🧹 Clearing existing universe...");
                        _generationStatus[generationId].Message = "Clearing existing universe";
                        _generationStatus[generationId].Progress = 10;
                        await generator.ClearUniverseAsync();
                    }

                    _logger.LogInformation("🌌 Generating new universe...");
                    _generationStatus[generationId].Message = "Generating universe";
                    _generationStatus[generationId].Progress = 30;
                    await generator.GenerateUniverseAsync();

                    // Get statistics
                    var generatorStats = await generator.GetUniverseStatsAsync();
                    
                    // Convert to Models.Entities.Universe.UniverseStats
                    var stats = new ModelsUniverseStats
                    {
                        Regions = generatorStats.Regions,
                        Constellations = generatorStats.Constellations,
                        SolarSystems = generatorStats.SolarSystems,
                        Planets = generatorStats.Planets,
                        Stations = generatorStats.Stations,
                        Stargates = generatorStats.Stargates,
                        AsteroidBelts = generatorStats.AsteroidBelts,
                        Anomalies = generatorStats.Anomalies,
                        Wormholes = generatorStats.Wormholes
                    };

                    _generationStatus[generationId].Status = "Completed";
                    _generationStatus[generationId].Message = "Universe generation completed successfully";
                    _generationStatus[generationId].Progress = 100;
                    _generationStatus[generationId].CompletedAt = DateTime.UtcNow;
                    _generationStatus[generationId].Stats = stats;

                    _logger.LogInformation($"✅ Background generation {generationId} completed successfully! Generated: {stats.SolarSystems} systems, {stats.Planets} planets");
                }
                catch (Exception ex)
                {
                    _logger.LogError(ex, "❌ Error in background generation {GenerationId}", generationId);
                    _generationStatus[generationId].Status = "Failed";
                    _generationStatus[generationId].Message = $"Generation failed: {ex.Message}";
                    _generationStatus[generationId].CompletedAt = DateTime.UtcNow;
                }
            });

            return Task.FromResult(generationId);
        }

        public Task<GenerationStatusDto?> GetGenerationStatusAsync(Guid generationId)
        {
            if (_generationStatus.TryGetValue(generationId, out var status))
            {
                return Task.FromResult<GenerationStatusDto?>(status);
            }

            return Task.FromResult<GenerationStatusDto?>(null);
        }
    }
}
