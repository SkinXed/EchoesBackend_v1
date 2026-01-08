using Echoes.API.Data;
using Echoes.API.Models.Config;
using Echoes.API.Services.UniverseGeneration;
using Microsoft.AspNetCore.Mvc;
using System.Text.Json;
using Microsoft.EntityFrameworkCore;

namespace Echoes.API.Controllers
{
    [ApiController]
    [Route("api/[controller]")]
    public class UniverseConfigController : ControllerBase
    {
        private readonly DatabaseContext _context;
        private readonly IUniverseGenerator _generator;
        private readonly ILogger<UniverseConfigController> _logger;

        public UniverseConfigController(
            DatabaseContext context,
            IUniverseGenerator generator,
            ILogger<UniverseConfigController> logger)
        {
            _context = context;
            _generator = generator;
            _logger = logger;
        }

        [HttpGet("configs")]
        public async Task<IActionResult> GetConfigs()
        {
            var configs = await _context.UniverseGenerationConfigs
                .OrderByDescending(c => c.LastUsedAt)
                .ThenByDescending(c => c.CreatedAt)
                .Select(c => new
                {
                    c.Id,
                    c.ConfigName,
                    c.Description,
                    c.IsPreset,
                    c.IsActive,
                    c.Tags,
                    c.RegionCount,
                    c.SystemCount,
                    c.PlanetCount,
                    c.CreatedAt,
                    c.LastUsedAt,
                    c.UsageCount,
                    c.UseSeedBasedGeneration,
                    c.UniverseSeed
                })
                .ToListAsync();

            return Ok(configs);
        }

        [HttpGet("configs/{id}")]
        public async Task<IActionResult> GetConfig(Guid id)
        {
            var config = await _context.UniverseGenerationConfigs
                .FirstOrDefaultAsync(c => c.Id == id);

            if (config == null)
                return NotFound($"Конфигурация с ID {id} не найдена");

            return Ok(new
            {
                config.Id,
                config.ConfigName,
                config.Description,
                config.ConfigJson,
                config.IsPreset,
                config.IsActive,
                config.Tags,
                config.RegionCount,
                config.SystemCount,
                config.PlanetCount,
                config.CreatedAt,
                config.LastUsedAt,
                config.UsageCount,
                config.UseSeedBasedGeneration,
                config.UniverseSeed,
                config.SeedVersion
            });
        }

        [HttpPost("configs/save")]
        public async Task<IActionResult> SaveConfig([FromBody] SaveConfigRequest request)
        {
            try
            {
                var universeConfig = JsonSerializer.Deserialize<UniverseConfig>(request.ConfigJson);
                if (universeConfig == null)
                    return BadRequest("Неверный формат конфигурации");

                var savedConfig = await _generator.SaveConfigAsync(
                    universeConfig,
                    request.Name,
                    request.Description);

                return Ok(new
                {
                    message = "Конфигурация сохранена",
                    configId = savedConfig.Id
                });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Ошибка сохранения конфигурации");
                return StatusCode(500, "Ошибка сохранения конфигурации");
            }
        }

        [HttpPost("configs/{id}/activate")]
        public async Task<IActionResult> ActivateConfig(Guid id)
        {
            try
            {
                var result = await _generator.ActivateConfigAsync(id);
                if (!result)
                    return NotFound($"Конфигурация с ID {id} не найдена");

                return Ok(new { message = "Конфигурация активирована" });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Ошибка активации конфигурации");
                return StatusCode(500, "Ошибка активации конфигурации");
            }
        }

        [HttpPost("configs/{id}/generate")]
        public async Task<IActionResult> GenerateFromConfig(Guid id)
        {
            try
            {
                var config = await _context.UniverseGenerationConfigs
                    .FirstOrDefaultAsync(c => c.Id == id);

                if (config == null)
                    return NotFound($"Конфигурация с ID {id} не найдена");

                var universeConfig = JsonSerializer.Deserialize<UniverseConfig>(config.ConfigJson);
                if (universeConfig == null)
                    return BadRequest("Неверный формат сохраненной конфигурации");

                await _generator.GenerateUniverseFromConfigAsync(universeConfig);

                return Ok(new
                {
                    message = "Вселенная сгенерирована из конфигурации",
                    configName = config.ConfigName
                });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Ошибка генерации из конфигурации");
                return StatusCode(500, "Ошибка генерации из конфигурации");
            }
        }

        [HttpDelete("configs/{id}")]
        public async Task<IActionResult> DeleteConfig(Guid id)
        {
            try
            {
                var result = await _generator.DeleteConfigAsync(id);
                if (!result)
                    return NotFound($"Конфигурация с ID {id} не найдена или является активной");

                return Ok(new { message = "Конфигурация удалена" });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Ошибка удаления конфигурации");
                return StatusCode(500, "Ошибка удаления конфигурации");
            }
        }
    }

    public class SaveConfigRequest
    {
        public string ConfigJson { get; set; } = string.Empty;
        public string? Name { get; set; }
        public string? Description { get; set; }
    }
}