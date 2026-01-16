using Echoes.API.Data;
using Echoes.API.Models.Config;
using Echoes.API.Models.DTOs;
using Echoes.API.Models.Entities.Universe;
using Echoes.API.Services.UniverseGeneration;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.Infrastructure;
using Microsoft.Extensions.Logging;
using Microsoft.Extensions.Options;

namespace Echoes.API.Controllers
{
    [ApiController]
    [Route("api/[controller]")]
    public class UniverseController : ControllerBase
    {
        private readonly DatabaseContext _context;
        private readonly ILogger<UniverseController> _logger;
        private readonly ILogger<UniverseGenerator> _universeGeneratorLogger;

        public UniverseController(
            DatabaseContext context,
            ILogger<UniverseController> logger,
            ILogger<UniverseGenerator> universeGeneratorLogger)
        {
            _context = context;
            _logger = logger;
            _universeGeneratorLogger = universeGeneratorLogger;
        }

        // GET: api/universe/systems
        [HttpGet("systems")]
        public async Task<IActionResult> GetAllSystems()
        {
            try
            {
                var systems = await _context.SolarSystems
                    .Include(s => s.Constellation)
                    .ThenInclude(c => c.Region)
                    .Select(s => new
                    {
                        s.Id,
                        s.Name,
                        Security = s.SecurityStatus,
                        Constellation = s.Constellation.Name,
                        Region = s.Constellation.Region.Name,
                        s.PositionX,
                        s.PositionY,
                        s.PositionZ
                    })
                    .ToListAsync();

                return Ok(systems);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error getting all systems");
                return StatusCode(500, new { message = "Internal server error" });
            }
        }

        // GET: api/universe/region/{regionId}/systems
        [HttpGet("region/{regionId}/systems")]
        public async Task<IActionResult> GetSystemsByRegion(Guid regionId)
        {
            try
            {
                _logger.LogInformation("Getting systems for region {RegionId}", regionId);

                // Проверяем существует ли регион
                var regionExists = await _context.Regions.AnyAsync(r => r.Id == regionId);
                if (!regionExists)
                    return NotFound(new { message = $"Region {regionId} not found" });

                // Получаем все системы региона
                var systems = await _context.SolarSystems
                    .Where(s => s.Constellation.RegionId == regionId)
                    .Include(s => s.Planets)
                    .Include(s => s.Stargates)
                    .ThenInclude(sg => sg.DestinationSolarSystem)
                    .Select(s => new
                    {
                        s.Id,
                        s.Name,
                        s.SecurityStatus,
                        s.PositionX,
                        s.PositionY,
                        s.PositionZ,
                        Planets = s.Planets.Select(p => new
                        {
                            p.Id,
                            p.Name,
                            p.Type,
                            p.Radius,
                            p.OrbitDistance,
                            p.PositionX,
                            p.PositionY,
                            p.PositionZ
                        }),
                        Stargates = s.Stargates.Select(sg => new
                        {
                            sg.Id,
                            sg.Name,
                            sg.DestinationSolarSystemId,
                            sg.PositionX,
                            sg.PositionY,
                            sg.PositionZ,
                            TargetSystemName = sg.DestinationSolarSystem != null
                                ? sg.DestinationSolarSystem.Name
                                : "Unknown"
                        })
                    })
                    .ToListAsync();

                if (!systems.Any())
                    return NotFound(new { message = $"No systems found for region {regionId}" });

                return Ok(new
                {
                    RegionId = regionId,
                    Systems = systems,
                    TotalSystems = systems.Count,
                    Timestamp = DateTime.UtcNow
                });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error getting region systems for region {RegionId}", regionId);
                return StatusCode(500, new { message = "Internal server error" });
            }
        }

        // GET: api/universe/systems/{id}
        [HttpGet("systems/{id}")]
        public async Task<IActionResult> GetSystem(Guid id)
        {
            try
            {
                var system = await _context.SolarSystems
                    .Include(s => s.Constellation)
                    .ThenInclude(c => c.Region)
                    .Include(s => s.Planets)
                    .Include(s => s.Stations)
                    .Include(s => s.Stargates)
                    .ThenInclude(sg => sg.DestinationSolarSystem)
                    .FirstOrDefaultAsync(s => s.Id == id);

                if (system == null)
                {
                    return NotFound(new { message = "Solar system not found" });
                }

                var result = new
                {
                    system.Id,
                    system.Name,
                    system.SecurityStatus,
                    system.Description,
                    Constellation = new
                    {
                        system.Constellation.Id,
                        system.Constellation.Name
                    },
                    Region = new
                    {
                        system.Constellation.Region.Id,
                        system.Constellation.Region.Name,
                        system.Constellation.Region.Type
                    },
                    StarInfo = new
                    {
                        system.StarClass,
                        system.LuminosityClass,
                        system.Temperature,
                        system.SolarRadius,
                        system.SolarMass,
                        system.Luminosity
                    },
                    Position = new
                    {
                        system.PositionX,
                        system.PositionY,
                        system.PositionZ
                    },
                    Planets = system.Planets.Select(p => new
                    {
                        p.Id,
                        p.Name,
                        p.Type,
                        p.Radius,
                        p.OrbitDistance,
                        // ДОБАВЛЯЕМ КООРДИНАТЫ
                        p.PositionX,
                        p.PositionY,
                        p.PositionZ
                    }),
                    Stations = system.Stations.Select(st => new
                    {
                        st.Id,
                        st.Name,
                        st.Type,
                        st.DockingCapacity,
                        st.Services
                    }),
                    Stargates = system.Stargates.Select(sg => new
                    {
                        sg.Id,
                        sg.Name,
                        // ДОБАВЛЯЕМ КООРДИНАТЫ
                        Position = new { X = sg.PositionX, Y = sg.PositionY, Z = sg.PositionZ },
                        DestinationSystem = sg.DestinationSolarSystem != null ? new
                        {
                            sg.DestinationSolarSystem.Id,
                            sg.DestinationSolarSystem.Name
                        } : null,
                        sg.IsOperational,
                        sg.JumpCost
                    })
                };

                return Ok(result);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error getting system");
                return StatusCode(500, new { message = "Internal server error" });
            }
        }

        /// <summary>
        /// Get system objects (planets and stargates) for UE5 game servers.
        /// Returns system configuration in format expected by C++ client.
        /// </summary>
        /// <param name="systemId">Solar system ID</param>
        /// <returns>System objects with success status</returns>
        [HttpGet("system/{systemId}/objects")]
        public async Task<IActionResult> GetSystemObjects(Guid systemId)
        {
            try
            {
                // Load system with planets and stargates (including destination system names)
                var system = await _context.SolarSystems
                    .Include(s => s.Planets)
                    .Include(s => s.Stargates)
                    .ThenInclude(sg => sg.DestinationSolarSystem)
                    .FirstOrDefaultAsync(s => s.Id == systemId);

                if (system == null)
                    return NotFound(new { success = false, message = "System not found" });

                // Format response identical to ServerSystemConfigDto structure,
                // but wrapped in { success: true, system: ... } as required by C++ client
                var response = new
                {
                    success = true,
                    system = new
                    {
                        SystemId = system.Id,
                        SystemName = system.Name,
                        SolarRadius = system.SolarRadius,
                        SolarMass = system.SolarMass,
                        Temperature = system.Temperature,
                        Planets = system.Planets.Select(p => new
                        {
                            Id = p.Id,
                            Name = p.Name,
                            Type = p.Type,
                            OrbitDistance = p.OrbitDistance,
                            Radius = p.Radius
                        }),
                        Stargates = system.Stargates.Select(sg => new
                        {
                            Id = sg.Id,
                            Name = sg.Name,
                            TargetSystemId = sg.DestinationSolarSystemId,
                            TargetSystemName = sg.DestinationSolarSystem?.Name ?? "Unknown",
                            PositionX = sg.PositionX,
                            PositionY = sg.PositionY,
                            PositionZ = sg.PositionZ
                        })
                    }
                };

                return Ok(response);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error getting system objects for {SystemId}", systemId);
                return StatusCode(500, new { success = false, error = "Internal server error" });
            }
        }

        // GET: api/universe/map-data
        [HttpGet("map-data")]
        public async Task<IActionResult> GetMapData()
        {
            try
            {
                var mapData = await _context.SolarSystems
                    .Include(s => s.Constellation)
                    .ThenInclude(c => c.Region)
                    .Select(s => new
                    {
                        Id = s.Id,
                        Name = s.Name,
                        X = s.PositionX,
                        Y = s.PositionY,
                        Z = s.PositionZ,
                        Security = s.SecurityStatus,
                        RegionId = s.Constellation.Region.Id,
                        RegionName = s.Constellation.Region.Name,
                        ConstellationId = s.Constellation.Id,
                        ConstellationName = s.Constellation.Name,
                        StarClass = s.StarClass.ToString(),
                        HasStations = s.HasStations,
                        HasAsteroidBelts = s.HasAsteroidBelts
                    })
                    .ToListAsync();

                var stargates = await _context.Stargates
                    .Where(sg => sg.IsOperational)
                    .Select(sg => new
                    {
                        SourceSystemId = sg.SourceSolarSystemId,
                        DestinationSystemId = sg.DestinationSolarSystemId,
                        JumpCost = sg.JumpCost
                    })
                    .ToListAsync();

                return Ok(new
                {
                    Systems = mapData,
                    Stargates = stargates,
                    GeneratedAt = DateTime.UtcNow
                });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error getting map data");
                return StatusCode(500, new { message = "Internal server error" });
            }
        }

        // POST: api/universe/generate-test
        [HttpPost("generate-test")]
        public async Task<IActionResult> GenerateTestUniverse()
        {
            try
            {
                var generator = new UniverseGenerator(
                    _context,
                    _universeGeneratorLogger,
                    Microsoft.Extensions.Options.Options.Create(new Models.Config.UniverseConfig())
                );

                await generator.GenerateTestUniverseAsync();

                return Ok(new { message = "Test universe generated successfully" });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error generating test universe");
                return StatusCode(500, new { message = ex.Message });
            }
        }
        // Запуск генерации вселенной в фоне
        // POST: api/universe/Generate-Echoes
        [HttpPost("Generate-Echoes")]
        public IActionResult GenerateUniverse(
    // Получаем scope factory для создания нового скоупа
    [FromServices] IServiceScopeFactory scopeFactory,
    // Query параметр force для принудительной перегенерации
    [FromQuery] bool force = false,
    
    [FromQuery] bool clearFirst = true)
        {
            // Проверяем, существует ли уже вселенная
            var hasExistingUniverse = _context.SolarSystems.Any();

            if (hasExistingUniverse && !force)
            {
                return Conflict(new
                {
                    message = "Вселенная уже существует. Используйте ?force=true для принудительной перегенерации.",
                    stats = new
                    {
                        Systems = _context.SolarSystems.Count(),
                        Planets = _context.Planets.Count()
                    }
                });
            }

            Task.Run(async () =>
            {
                using (var scope = scopeFactory.CreateScope())
                {
                    var scopedContext = scope.ServiceProvider.GetRequiredService<DatabaseContext>();
                    var universeGeneratorLogger = scope.ServiceProvider.GetRequiredService<ILogger<UniverseGenerator>>();
                    var universeConfig = scope.ServiceProvider.GetRequiredService<IOptions<UniverseConfig>>();

                    try
                    {
                        universeGeneratorLogger.LogInformation("🏁 Запуск фоновой генерации вселенной...");

                        var generator = new UniverseGenerator(scopedContext, universeGeneratorLogger, universeConfig);

                        if (clearFirst)
                        {
                            universeGeneratorLogger.LogInformation("🧹 Очистка существующей вселенной...");
                            await generator.ClearUniverseAsync();
                        }

                        universeGeneratorLogger.LogInformation("🌌 Генерация новой вселенной...");
                        await generator.GenerateUniverseAsync();

                        // Получаем статистику
                        var stats = await generator.GetUniverseStatsAsync();

                        universeGeneratorLogger.LogInformation($"✅ Фоновая генерация завершена успешно! Сгенерировано: {stats.SolarSystems} систем, {stats.Planets} планет");
                    }
                    catch (Exception ex)
                    {
                        universeGeneratorLogger.LogError(ex, "❌ Ошибка в фоновой генерации");
                    }
                }
            });

            return Accepted(new
            {
                message = "Генерация запущена в фоне.",
                forceRegeneration = force,
                clearExisting = clearFirst
            });
        }

        // GET: api/universe/stats
        [HttpGet("stats")]
        public async Task<IActionResult> GetUniverseStats()
        {
            try
            {
                var stats = new
                {
                    Regions = await _context.Regions.CountAsync(),
                    Constellations = await _context.Constellations.CountAsync(),
                    SolarSystems = await _context.SolarSystems.CountAsync(),
                    Planets = await _context.Planets.CountAsync(),
                    Moons = await _context.Moons.CountAsync(),
                    Stations = await _context.Stations.CountAsync(),
                    Stargates = await _context.Stargates.CountAsync(),
                    AsteroidBelts = await _context.AsteroidBelts.CountAsync()
                };

                return Ok(stats);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error getting universe stats");
                return StatusCode(500, new { message = "Internal server error" });
            }
        }


        [HttpPost("test-wormholes")]
        public async Task<IActionResult> TestWormholes()
        {
            try
            {
                _logger.LogInformation("🧪 ТЕСТОВЫЙ МЕТОД ДЛЯ ЧЕРВОТОЧИН");

                // 1. Очищаем только червоточины
                await _context.Wormholes.ExecuteDeleteAsync();
                _logger.LogInformation("🧪 Очищены существующие червоточины");

                // 2. Проверяем, есть ли системы
                var systemCount = await _context.SolarSystems.CountAsync();
                _logger.LogInformation($"🧪 Систем в базе: {systemCount}");

                if (systemCount == 0)
                {
                    return BadRequest(new { error = "Нет систем в базе. Сначала сгенерируйте вселенную." });
                }

                // 3. Создаем простую тестовую конфигурацию
                var testConfig = new UniverseConfig
                {
                    WormholeConfig = new Models.Config.WormholeConfig
                    {
                        EnableWormholes = true,
                        ChancePerSystem = 1.0,
                        MinDistanceLightYears = 1,
                        MaxDistanceLightYears = 100
                    }
                };

                var generator = new UniverseGenerator(
                    _context,
                    _universeGeneratorLogger,
                    Microsoft.Extensions.Options.Options.Create(testConfig)
                );

                // 4. Запускаем тестовую генерацию
                var count = await generator.GenerateWormholesAsync(testConfig);

                // 5. Проверяем результат
                var actualCount = await _context.Wormholes.CountAsync();
                var sample = await _context.Wormholes
                    .Include(w => w.SourceSystem)
                    .Include(w => w.TargetSystem)
                    .FirstOrDefaultAsync();

                return Ok(new
                {
                    message = "Тест завершен",
                    expectedCount = count,
                    actualCount = actualCount,
                    sample = sample != null ? new
                    {
                        id = sample.Id,
                        name = sample.Name,
                        signature = sample.Signature,
                        sourceSystem = sample.SourceSystem?.Name,
                        targetSystem = sample.TargetSystem?.Name
                    } : null
                });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "❌ Ошибка тестирования червоточин");
                return BadRequest(new
                {
                    error = ex.Message,
                    inner = ex.InnerException?.Message,
                    stackTrace = ex.StackTrace
                });
            }
        }
    }
}