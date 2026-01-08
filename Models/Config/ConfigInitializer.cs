using Echoes.API.Data;
using Echoes.API.Models.Config;
using Microsoft.Extensions.Logging;
using System;
using System.Text.Json;
using System.Threading.Tasks;

using Microsoft.EntityFrameworkCore;
using Echoes.API.Models.Entities.Universe;

public class ConfigInitializer
{
    private readonly DatabaseContext _context;
    private readonly ILogger<ConfigInitializer> _logger;

    public ConfigInitializer(DatabaseContext context, ILogger<ConfigInitializer> logger)
    {
        _context = context;
        _logger = logger;
    }

    public async Task InitializePresetsAsync()
    {
        if (await _context.UniverseGenerationConfigs.AnyAsync())
        {
            _logger.LogInformation("Пресеты уже существуют");
            return;
        }

        var presets = new[]
        {
            CreatePreset("UltraSmall", "Очень маленькая вселенная для тестирования", 1, 1, 2, 3, 5, 1, 3),
            CreatePreset("Small", "Маленькая вселенная для разработки", 3, 2, 5, 5, 10, 1, 5),
            CreatePreset("Medium", "Средняя вселенная для альфа-теста", 10, 3, 8, 10, 20, 3, 8),
            CreatePreset("Large", "Большая вселенная для бета-теста", 50, 5, 12, 20, 40, 5, 12),
            CreatePreset("UltraLarge", "Очень большая вселенная", 200, 8, 15, 30, 60, 8, 15),
            CreatePreset("Massive", "Массивная вселенная для продакшена", 1000, 10, 20, 50, 100, 10, 20),
            CreatePreset("Dev-Small", "Тестовая вселенная с детерминированным seed", 1, 1, 2, 3, 5, 1, 3,
                "echoes-dev-test", true),
            CreatePreset("Alpha-v1", "Альфа-версия вселенной", 5, 2, 5, 8, 15, 2, 6,
                "echoes-alpha-v1", true),
            CreatePreset("Production-v1", "Продакшен вселенная", 100, 5, 10, 30, 50, 5, 12,
                "echoes-production-v1", true)
        };

        await _context.UniverseGenerationConfigs.AddRangeAsync(presets);
        await _context.SaveChangesAsync();

        _logger.LogInformation($"✅ Создано {presets.Length} пресетов конфигураций");
    }

    private UniverseGenerationConfig CreatePreset(string name, string description,
        int regionCount, int minConstellations, int maxConstellations,
        int minSystems, int maxSystems, int minPlanets, int maxPlanets,
        string? seed = null, bool useSeed = false)
    {
        var config = new UniverseConfig
        {
            RegionCount = regionCount,
            MinConstellationsPerRegion = minConstellations,
            MaxConstellationsPerRegion = maxConstellations,
            MinSystemsPerConstellation = minSystems,
            MaxSystemsPerConstellation = maxSystems,
            MinPlanetsPerSystem = minPlanets,
            MaxPlanetsPerSystem = maxPlanets,
            StationConfig = new StationConfig { EnableStations = true },
            StargateConfig = new StargateConfig { EnableStargates = true },
            ResourcesConfig = new ResourcesConfig { EnableResources = true },
            StarConfig = new StarConfig { EnableStarVariety = true }
        };
        // Если UniverseConfig не содержит свойства Seed, не присваивайте его

        return new UniverseGenerationConfig
        {
            Id = Guid.NewGuid(),
            ConfigName = name,
            Description = description,
            ConfigJson = JsonSerializer.Serialize(config),
            UniverseSeed = seed,
            UseSeedBasedGeneration = useSeed,
            IsPreset = true,
            IsActive = false,
            Tags = "preset," + (useSeed ? "seed-based" : "random"),
            RegionCount = regionCount,
            CreatedAt = DateTime.UtcNow
        };
    }
}