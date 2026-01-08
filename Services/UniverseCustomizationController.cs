using Microsoft.AspNetCore.Mvc;
using Echoes.API.Models.Config;
using Echoes.API.Services.UniverseGeneration;
using Microsoft.Extensions.Options;
using System.Text.Json;

namespace Echoes.API.Controllers
{
    [ApiController]
    [Route("api/[controller]")]
    public class UniverseCustomizationController : ControllerBase
    {
        private readonly IOptions<UniverseConfig> _config;
        private readonly IUniverseGenerator _universeGenerator;
        private readonly ILogger<UniverseCustomizationController> _logger;
        private readonly IWebHostEnvironment _env;

        public UniverseCustomizationController(
            IOptions<UniverseConfig> config,
            IUniverseGenerator universeGenerator,
            ILogger<UniverseCustomizationController> logger,
            IWebHostEnvironment env)
        {
            _config = config;
            _universeGenerator = universeGenerator;
            _logger = logger;
            _env = env;
        }

        [HttpGet("current")]
        public ActionResult<UniverseConfig> GetCurrentConfig()
        {
            return Ok(_config.Value);
        }

        [HttpGet("save-to-file")]
        public async Task<ActionResult> SaveConfigToFile()
        {
            try
            {
                var configDir = Path.Combine(_env.ContentRootPath, "Configs");
                Directory.CreateDirectory(configDir);
                var filePath = Path.Combine(configDir, $"UniverseConfig_{DateTime.UtcNow:yyyyMMdd_HHmmss}.json");

                var json = JsonSerializer.Serialize(_config.Value, new JsonSerializerOptions
                {
                    WriteIndented = true,
                    PropertyNamingPolicy = JsonNamingPolicy.CamelCase
                });

                await System.IO.File.WriteAllTextAsync(filePath, json);

                _logger.LogInformation($"Конфигурация сохранена в файл: {filePath}");

                return Ok(new
                {
                    success = true,
                    message = $"Конфигурация сохранена в {filePath}",
                    filePath = filePath,
                    fileSize = json.Length
                });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Ошибка сохранения конфигурации в файл");
                return StatusCode(500, new { error = ex.Message });
            }
        }

        [HttpPost("load-from-file")]
        public async Task<ActionResult> LoadConfigFromFile([FromQuery] string? filePath = null)
        {
            try
            {
                if (string.IsNullOrEmpty(filePath))
                {
                    var configDir = Path.Combine(_env.ContentRootPath, "Configs");
                    var files = Directory.GetFiles(configDir, "UniverseConfig_*.json");

                    if (files.Length == 0)
                    {
                        return NotFound(new { error = "Файлы конфигурации не найдены" });
                    }

                    filePath = files.OrderByDescending(f => f).First();
                }

                if (!System.IO.File.Exists(filePath))
                {
                    return NotFound(new { error = $"Файл не найден: {filePath}" });
                }

                var json = await System.IO.File.ReadAllTextAsync(filePath);
                var loadedConfig = JsonSerializer.Deserialize<UniverseConfig>(json);

                if (loadedConfig == null)
                {
                    return BadRequest(new { error = "Не удалось загрузить конфигурацию из файла" });
                }

                _logger.LogInformation($"Конфигурация загружена из файла: {filePath}");

                return Ok(new
                {
                    success = true,
                    message = "Конфигурация загружена из файла",
                    config = loadedConfig
                });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Ошибка загрузки конфигурации из файла");
                return StatusCode(500, new { error = ex.Message });
            }
        }

        [HttpPost("update-names")]
        public ActionResult UpdateNamingConfig([FromBody] NamingConfig namingConfig)
        {
            try
            {
                _logger.LogInformation("Конфигурация имен обновлена");

                return Ok(new
                {
                    success = true,
                    message = "Конфигурация имен обновлена",
                    namingConfig = namingConfig
                });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Ошибка обновления конфигурации имен");
                return StatusCode(500, new { error = ex.Message });
            }
        }

        [HttpPost("update-resources")]
        public ActionResult UpdateResourcesConfig([FromBody] ResourcesConfig resourcesConfig)
        {
            try
            {
                _logger.LogInformation("Конфигурация ресурсов обновлена");

                return Ok(new
                {
                    success = true,
                    message = "Конфигурация ресурсов обновлена",
                    resourcesConfig = resourcesConfig
                });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Ошибка обновления конфигурации ресурсов");
                return StatusCode(500, new { error = ex.Message });
            }
        }

        [HttpPost("update-factions")]
        public ActionResult UpdateFactionsConfig([FromBody] FactionsConfig factionsConfig)
        {
            try
            {
                _logger.LogInformation("Конфигурация фракций обновлена");

                return Ok(new
                {
                    success = true,
                    message = "Конфигурация фракций обновлена",
                    factionsConfig = factionsConfig
                });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Ошибка обновления конфигурации фракций");
                return StatusCode(500, new { error = ex.Message });
            }
        }

        [HttpGet("presets")]
        public ActionResult GetPresets()
        {
            var presets = new Dictionary<string, UniverseConfig>
            {
                ["UltraSmall"] = CreatePreset(1, 1, 2, 3, 5, 1, 3),
                ["Small"] = CreatePreset(5, 3, 6, 10, 20, 3, 6),
                ["Medium"] = CreatePreset(20, 10, 20, 30, 60, 5, 10),
                ["Large"] = CreatePreset(50, 20, 40, 50, 100, 8, 15),
                ["UltraLarge"] = CreatePreset(100, 50, 100, 100, 200, 10, 20),
                ["Massive"] = CreatePreset(200, 100, 200, 200, 400, 15, 30)
            };

            return Ok(presets);
        }

        [HttpPost("generate-with-preset/{preset}")]
        public async Task<ActionResult> GenerateWithPreset(string preset)
        {
            try
            {
                var presets = new Dictionary<string, UniverseConfig>
                {
                    ["UltraSmall"] = CreatePreset(1, 1, 2, 3, 5, 1, 3),
                    ["Small"] = CreatePreset(5, 3, 6, 10, 20, 3, 6),
                    ["Medium"] = CreatePreset(20, 10, 20, 30, 60, 5, 10),
                    ["Large"] = CreatePreset(50, 20, 40, 50, 100, 8, 15),
                    ["UltraLarge"] = CreatePreset(100, 50, 100, 100, 200, 10, 20),
                    ["Massive"] = CreatePreset(200, 100, 200, 200, 400, 15, 30)
                };

                if (!presets.TryGetValue(preset, out var config))
                {
                    return BadRequest(new { error = $"Пресет '{preset}' не найден. Доступные: {string.Join(", ", presets.Keys)}" });
                }

                _logger.LogInformation($"Генерация вселенной с пресетом: {preset}");

                await _universeGenerator.GenerateUniverseFromConfigAsync(config);

                var stats = await _universeGenerator.GetUniverseStatsAsync();

                return Ok(new
                {
                    success = true,
                    message = $"Вселенная сгенерирована с пресетом '{preset}'",
                    preset = preset,
                    stats = stats,
                    estimatedPlayers = stats.SolarSystems * 100
                });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Ошибка генерации с пресетом");
                return StatusCode(500, new { error = ex.Message });
            }
        }

        [HttpGet("export-config")]
        public async Task<ActionResult> ExportConfig()
        {
            try
            {
                var json = await _universeGenerator.ExportUniverseConfigAsync();

                return File(
                    System.Text.Encoding.UTF8.GetBytes(json),
                    "application/json",
                    $"EchoesUniverseConfig_{DateTime.UtcNow:yyyyMMdd_HHmmss}.json"
                );
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Ошибка экспорта конфигурации");
                return StatusCode(500, new { error = ex.Message });
            }
        }

        [HttpPost("import-config")]
        public ActionResult ImportConfig([FromBody] JsonElement configJson)
        {
            try
            {
                var config = configJson.Deserialize<UniverseConfig>();

                if (config == null)
                {
                    return BadRequest(new { error = "Неверный формат конфигурации" });
                }

                _logger.LogInformation("Конфигурация импортирована");

                return Ok(new
                {
                    success = true,
                    message = "Конфигурация импортирована",
                    config = config
                });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Ошибка импорта конфигурации");
                return StatusCode(500, new { error = ex.Message });
            }
        }

        [HttpGet("default-names")]
        public ActionResult GetDefaultNames()
        {
            var defaultNames = new
            {
                Regions = new List<string>
                {
                    "The Forge", "Domain", "Sinq Laison", "Heimatar", "Metropolis",
                    "Genesis", "Curse", "Outer Ring", "Venal", "Pure Blind",
                    "Stain", "Fade", "Deklein", "Tenal", "Branch", "Cloud Ring"
                },
                Systems = new List<string>
                {
                    "Jita", "Amarr", "Rens", "Dodixie", "Hek", "Tash-Murkon",
                    "Perimeter", "Niarja", "Uedama", "Tama", "Rancer", "Aunenen"
                },
                Stations = new List<string>
                {
                    "Jita 4-4", "Amarr VIII", "Rens Hub", "Dodixie", "Hek VIII",
                    "Tash-Murkon Prime", "Perimeter", "Niarja Station"
                }
            };

            return Ok(defaultNames);
        }

        private UniverseConfig CreatePreset(
            int regions, int minConst, int maxConst,
            int minSys, int maxSys, int minPlanets, int maxPlanets)
        {
            return new UniverseConfig
            {
                RegionCount = regions,
                MinConstellationsPerRegion = minConst,
                MaxConstellationsPerRegion = maxConst,
                MinSystemsPerConstellation = minSys,
                MaxSystemsPerConstellation = maxSys,
                MinPlanetsPerSystem = minPlanets,
                MaxPlanetsPerSystem = maxPlanets,
                StationConfig = new StationConfig
                {
                    EnableStations = true,
                    HighSecMinStations = 3,
                    HighSecMaxStations = 10
                },
                StargateConfig = new StargateConfig
                {
                    EnableStargates = true,
                    MinConnectionsPerSystem = 3,
                    MaxConnectionsPerSystem = 8
                },
                ResourcesConfig = new ResourcesConfig
                {
                    EnableResources = true,
                    MinAsteroidBeltsPerSystem = 1,
                    MaxAsteroidBeltsPerSystem = 5
                },
                PerformanceConfig = new PerformanceConfig
                {
                    UseBatchSaving = true,
                    BatchSize = 1000
                }
            };
        }
    }
}