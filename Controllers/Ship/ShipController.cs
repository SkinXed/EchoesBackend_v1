using Echoes.API.Services.Ship;
using Microsoft.AspNetCore.Mvc;

namespace Echoes.API.Controllers.Ship
{
    /// <summary>
    /// Ship controller for managing ship stats and fitting
    /// Secured for UE Server access only via X-Server-Secret header
    /// </summary>
    [ApiController]
    [Route("api/[controller]")]
    public class ShipController : ControllerBase
    {
        private readonly IShipFittingService _fittingService;
        private readonly ILogger<ShipController> _logger;
        private readonly IConfiguration _configuration;

        public ShipController(
            IShipFittingService fittingService,
            ILogger<ShipController> logger,
            IConfiguration configuration)
        {
            _fittingService = fittingService;
            _logger = logger;
            _configuration = configuration;
        }

        /// <summary>
        /// Validates the X-Server-Secret header for server-to-server authentication
        /// </summary>
        private bool ValidateServerSecret()
        {
            if (!Request.Headers.TryGetValue("X-Server-Secret", out var headerSecret))
            {
                _logger.LogWarning("Missing X-Server-Secret header");
                return false;
            }

            var configuredSecret = _configuration["ServerSecret"] ?? "default-server-secret-change-me";
            
            if (headerSecret != configuredSecret)
            {
                _logger.LogWarning("Invalid X-Server-Secret provided");
                return false;
            }

            return true;
        }

        /// <summary>
        /// Get ship statistics with calculated total mass
        /// GET /api/ship/{id}/stats
        /// Requires X-Server-Secret header
        /// </summary>
        /// <param name="id">Ship instance ID</param>
        /// <returns>Ship statistics including calculated total mass</returns>
        [HttpGet("{id}/stats")]
        [ProducesResponseType(StatusCodes.Status200OK)]
        [ProducesResponseType(StatusCodes.Status401Unauthorized)]
        [ProducesResponseType(StatusCodes.Status404NotFound)]
        public async Task<IActionResult> GetShipStats(Guid id)
        {
            // Validate server secret
            if (!ValidateServerSecret())
            {
                return Unauthorized(new { error = "Invalid or missing X-Server-Secret header" });
            }

            var stats = await _fittingService.CalculateShipStatsAsync(id);

            if (stats == null)
            {
                return NotFound(new { error = $"Ship instance {id} not found or has no stats" });
            }

            _logger.LogInformation("Returned stats for ship instance {ShipId} to UE Server", id);

            return Ok(stats);
        }

        /// <summary>
        /// Add a module to a ship
        /// POST /api/ship/{id}/modules
        /// Requires X-Server-Secret header
        /// </summary>
        [HttpPost("{id}/modules")]
        [ProducesResponseType(StatusCodes.Status200OK)]
        [ProducesResponseType(StatusCodes.Status401Unauthorized)]
        [ProducesResponseType(StatusCodes.Status400BadRequest)]
        public async Task<IActionResult> AddModule(
            Guid id,
            [FromBody] AddModuleRequest request)
        {
            if (!ValidateServerSecret())
            {
                return Unauthorized(new { error = "Invalid or missing X-Server-Secret header" });
            }

            var success = await _fittingService.AddModuleAsync(
                id,
                request.ModuleTypeId,
                request.Mass,
                request.Slot,
                request.SlotIndex,
                request.ThrustBonus,
                request.InertiaModifier,
                request.RotationBonus,
                request.MaxVelocityModifier);

            if (!success)
            {
                return BadRequest(new { error = "Failed to add module" });
            }

            return Ok(new { message = "Module added successfully" });
        }

        /// <summary>
        /// Update module bonuses
        /// PUT /api/ship/modules/{moduleId}/bonuses
        /// Requires X-Server-Secret header
        /// </summary>
        [HttpPut("modules/{moduleId}/bonuses")]
        [ProducesResponseType(StatusCodes.Status200OK)]
        [ProducesResponseType(StatusCodes.Status401Unauthorized)]
        [ProducesResponseType(StatusCodes.Status404NotFound)]
        public async Task<IActionResult> UpdateModuleBonuses(
            Guid moduleId,
            [FromBody] UpdateModuleBonusesRequest request)
        {
            if (!ValidateServerSecret())
            {
                return Unauthorized(new { error = "Invalid or missing X-Server-Secret header" });
            }

            var success = await _fittingService.UpdateModuleBonusesAsync(
                moduleId,
                request.ThrustBonus,
                request.InertiaModifier,
                request.RotationBonus,
                request.MaxVelocityModifier);

            if (!success)
            {
                return NotFound(new { error = "Module not found" });
            }

            return Ok(new { message = "Module bonuses updated successfully" });
        }

        /// <summary>
        /// Remove a module from a ship
        /// DELETE /api/ship/modules/{moduleId}
        /// Requires X-Server-Secret header
        /// </summary>
        [HttpDelete("modules/{moduleId}")]
        [ProducesResponseType(StatusCodes.Status200OK)]
        [ProducesResponseType(StatusCodes.Status401Unauthorized)]
        [ProducesResponseType(StatusCodes.Status404NotFound)]
        public async Task<IActionResult> RemoveModule(Guid moduleId)
        {
            if (!ValidateServerSecret())
            {
                return Unauthorized(new { error = "Invalid or missing X-Server-Secret header" });
            }

            var success = await _fittingService.RemoveModuleAsync(moduleId);

            if (!success)
            {
                return NotFound(new { error = "Module not found" });
            }

            return Ok(new { message = "Module removed successfully" });
        }
    }

    /// <summary>
    /// Request model for adding a module
    /// </summary>
    public class AddModuleRequest
    {
        public int ModuleTypeId { get; set; }
        public float Mass { get; set; }
        public string Slot { get; set; } = string.Empty;
        public int SlotIndex { get; set; } = 0;
        public float ThrustBonus { get; set; } = 0;
        public float InertiaModifier { get; set; } = 1.0f;
        public float RotationBonus { get; set; } = 0;
        public float MaxVelocityModifier { get; set; } = 1.0f;
    }

    /// <summary>
    /// Request model for updating module bonuses
    /// </summary>
    public class UpdateModuleBonusesRequest
    {
        public float ThrustBonus { get; set; }
        public float InertiaModifier { get; set; }
        public float RotationBonus { get; set; }
        public float MaxVelocityModifier { get; set; }
    }
}
