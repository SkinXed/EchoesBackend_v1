using Echoes.API.Models.Entities.Universe;
using ModelsUniverseStats = Echoes.API.Models.Entities.Universe.UniverseStats;

namespace Echoes.API.Services.UniverseGeneration
{
    /// <summary>
    /// Wrapper service that implements IUniverseGenerationService using IUniverseGenerator
    /// </summary>
    public class UniverseGenerationService : IUniverseGenerationService
    {
        private readonly IUniverseGenerator _universeGenerator;

        public UniverseGenerationService(IUniverseGenerator universeGenerator)
        {
            _universeGenerator = universeGenerator;
        }

        public async Task<ModelsUniverseStats> GetUniverseStatsAsync()
        {
            var generatorStats = await _universeGenerator.GetUniverseStatsAsync();
            
            // Convert from generator's UniverseStats to Models.Entities.Universe.UniverseStats
            return new ModelsUniverseStats
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
        }

        public Task ClearUniverseAsync()
        {
            return _universeGenerator.ClearUniverseAsync();
        }
    }
}
