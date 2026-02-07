using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using Echoes.API.Data;
using Echoes.API.Models.DTOs;
using Echoes.API.Models.Entities.Universe;

namespace Echoes.API.Controllers
{
    /// <summary>
    /// World Objects Controller - Manages persistent world objects (containers, debris)
    /// Server-only API for world object persistence across server restarts
    /// </summary>
    [ApiController]
    [Route("api/persistence/world-objects")]
    public class WorldObjectsController : ControllerBase
    {
        private readonly DatabaseContext _context;
        private readonly ILogger<WorldObjectsController> _logger;
        private readonly IConfiguration _configuration;

        public WorldObjectsController(
            DatabaseContext context,
            ILogger<WorldObjectsController> logger,
            IConfiguration configuration)
        {
            _context = context;
            _logger = logger;
            _configuration = configuration;
        }

        /// <summary>
        /// Register a new world object (container, debris, etc.)
        /// POST /api/persistence/world-objects
        /// Requires X-Server-Secret header for authentication
        /// </summary>
        [HttpPost]
        public async Task<ActionResult<WorldObjectResponse>> RegisterWorldObject(
            [FromBody] RegisterWorldObjectRequest request)
        {
            try
            {
                // Security validation - check X-Server-Secret header
                if (!Request.Headers.TryGetValue("X-Server-Secret", out var serverSecret))
                {
                    _logger.LogWarning("World object registration received without X-Server-Secret header");
                    return Unauthorized(new { message = "Missing X-Server-Secret header" });
                }

                // Get expected secret from configuration
                var expectedSecret = _configuration["ServerSecret"];

                // Fail securely if secret is not configured
                if (string.IsNullOrEmpty(expectedSecret))
                {
                    _logger.LogError("ServerSecret is not configured");
                    return StatusCode(500, new { message = "Server configuration error" });
                }

                if (serverSecret != expectedSecret)
                {
                    _logger.LogWarning("World object registration received with invalid X-Server-Secret");
                    return Unauthorized(new { message = "Invalid server secret" });
                }

                // Validate solar system exists
                var systemExists = await _context.SolarSystems.AnyAsync(s => s.Id == request.SystemId);
                if (!systemExists)
                {
                    _logger.LogWarning("World object registration for non-existent system {SystemId}", request.SystemId);
                    return NotFound(new { message = "Solar system not found" });
                }

                // Create world object
                var worldObject = new WorldObject
                {
                    Id = Guid.NewGuid(),
                    TemplateId = request.TemplateId,
                    SystemId = request.SystemId,
                    PosX = request.PosX,
                    PosY = request.PosY,
                    PosZ = request.PosZ,
                    RotW = request.RotW,
                    RotX = request.RotX,
                    RotY = request.RotY,
                    RotZ = request.RotZ,
                    InventoryJson = request.InventoryJson,
                    ExpirationTime = request.ExpirationTime,
                    CreatedAt = DateTime.UtcNow
                };

                _context.WorldObjects.Add(worldObject);
                await _context.SaveChangesAsync();

                _logger.LogInformation(
                    "World object registered: Id={Id}, Template={TemplateId}, System={SystemId}",
                    worldObject.Id, worldObject.TemplateId, worldObject.SystemId);

                return CreatedAtAction(
                    nameof(GetWorldObject),
                    new { id = worldObject.Id },
                    MapToResponse(worldObject));
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error registering world object");
                return StatusCode(500, new { message = "Internal server error" });
            }
        }

        /// <summary>
        /// Get all world objects in a solar system
        /// GET /api/persistence/world-objects/system/{systemId}
        /// Requires X-Server-Secret header for authentication
        /// </summary>
        [HttpGet("system/{systemId}")]
        public async Task<ActionResult<WorldObjectListResponse>> GetWorldObjectsBySystem(Guid systemId)
        {
            try
            {
                // Security validation - check X-Server-Secret header
                if (!Request.Headers.TryGetValue("X-Server-Secret", out var serverSecret))
                {
                    _logger.LogWarning("World objects query received without X-Server-Secret header");
                    return Unauthorized(new { message = "Missing X-Server-Secret header" });
                }

                // Get expected secret from configuration
                var expectedSecret = _configuration["ServerSecret"];

                // Fail securely if secret is not configured
                if (string.IsNullOrEmpty(expectedSecret))
                {
                    _logger.LogError("ServerSecret is not configured");
                    return StatusCode(500, new { message = "Server configuration error" });
                }

                if (serverSecret != expectedSecret)
                {
                    _logger.LogWarning("World objects query received with invalid X-Server-Secret");
                    return Unauthorized(new { message = "Invalid server secret" });
                }

                // Get all non-expired world objects in system
                var worldObjects = await _context.WorldObjects
                    .Where(w => w.SystemId == systemId)
                    .Where(w => w.ExpirationTime == null || w.ExpirationTime > DateTime.UtcNow)
                    .ToListAsync();

                _logger.LogInformation(
                    "Retrieved {Count} world objects for system {SystemId}",
                    worldObjects.Count, systemId);

                return Ok(new WorldObjectListResponse
                {
                    TotalCount = worldObjects.Count,
                    Objects = worldObjects.Select(MapToResponse).ToList()
                });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error retrieving world objects for system {SystemId}", systemId);
                return StatusCode(500, new { message = "Internal server error" });
            }
        }

        /// <summary>
        /// Get a specific world object by ID
        /// GET /api/persistence/world-objects/{id}
        /// Requires X-Server-Secret header for authentication
        /// </summary>
        [HttpGet("{id}")]
        public async Task<ActionResult<WorldObjectResponse>> GetWorldObject(Guid id)
        {
            try
            {
                // Security validation - check X-Server-Secret header
                if (!Request.Headers.TryGetValue("X-Server-Secret", out var serverSecret))
                {
                    _logger.LogWarning("World object get received without X-Server-Secret header");
                    return Unauthorized(new { message = "Missing X-Server-Secret header" });
                }

                // Get expected secret from configuration
                var expectedSecret = _configuration["ServerSecret"];

                // Fail securely if secret is not configured
                if (string.IsNullOrEmpty(expectedSecret))
                {
                    _logger.LogError("ServerSecret is not configured");
                    return StatusCode(500, new { message = "Server configuration error" });
                }

                if (serverSecret != expectedSecret)
                {
                    _logger.LogWarning("World object get received with invalid X-Server-Secret");
                    return Unauthorized(new { message = "Invalid server secret" });
                }

                var worldObject = await _context.WorldObjects.FindAsync(id);
                if (worldObject == null)
                {
                    return NotFound(new { message = "World object not found" });
                }

                return Ok(MapToResponse(worldObject));
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error retrieving world object {Id}", id);
                return StatusCode(500, new { message = "Internal server error" });
            }
        }

        /// <summary>
        /// Update world object inventory
        /// PUT /api/persistence/world-objects/{id}/inventory
        /// Requires X-Server-Secret header for authentication
        /// </summary>
        [HttpPut("{id}/inventory")]
        public async Task<ActionResult<WorldObjectResponse>> UpdateWorldObjectInventory(
            Guid id,
            [FromBody] UpdateWorldObjectInventoryRequest request)
        {
            try
            {
                // Security validation - check X-Server-Secret header
                if (!Request.Headers.TryGetValue("X-Server-Secret", out var serverSecret))
                {
                    _logger.LogWarning("World object inventory update received without X-Server-Secret header");
                    return Unauthorized(new { message = "Missing X-Server-Secret header" });
                }

                // Get expected secret from configuration
                var expectedSecret = _configuration["ServerSecret"];

                // Fail securely if secret is not configured
                if (string.IsNullOrEmpty(expectedSecret))
                {
                    _logger.LogError("ServerSecret is not configured");
                    return StatusCode(500, new { message = "Server configuration error" });
                }

                if (serverSecret != expectedSecret)
                {
                    _logger.LogWarning("World object inventory update received with invalid X-Server-Secret");
                    return Unauthorized(new { message = "Invalid server secret" });
                }

                var worldObject = await _context.WorldObjects.FindAsync(id);
                if (worldObject == null)
                {
                    return NotFound(new { message = "World object not found" });
                }

                // Update inventory
                worldObject.InventoryJson = request.InventoryJson;
                worldObject.LastUpdated = DateTime.UtcNow;

                await _context.SaveChangesAsync();

                _logger.LogInformation("World object inventory updated: Id={Id}", id);

                return Ok(MapToResponse(worldObject));
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error updating world object inventory {Id}", id);
                return StatusCode(500, new { message = "Internal server error" });
            }
        }

        /// <summary>
        /// Delete a world object
        /// DELETE /api/persistence/world-objects/{id}
        /// Requires X-Server-Secret header for authentication
        /// </summary>
        [HttpDelete("{id}")]
        public async Task<IActionResult> DeleteWorldObject(Guid id)
        {
            try
            {
                // Security validation - check X-Server-Secret header
                if (!Request.Headers.TryGetValue("X-Server-Secret", out var serverSecret))
                {
                    _logger.LogWarning("World object delete received without X-Server-Secret header");
                    return Unauthorized(new { message = "Missing X-Server-Secret header" });
                }

                // Get expected secret from configuration
                var expectedSecret = _configuration["ServerSecret"];

                // Fail securely if secret is not configured
                if (string.IsNullOrEmpty(expectedSecret))
                {
                    _logger.LogError("ServerSecret is not configured");
                    return StatusCode(500, new { message = "Server configuration error" });
                }

                if (serverSecret != expectedSecret)
                {
                    _logger.LogWarning("World object delete received with invalid X-Server-Secret");
                    return Unauthorized(new { message = "Invalid server secret" });
                }

                var worldObject = await _context.WorldObjects.FindAsync(id);
                if (worldObject == null)
                {
                    return NotFound(new { message = "World object not found" });
                }

                _context.WorldObjects.Remove(worldObject);
                await _context.SaveChangesAsync();

                _logger.LogInformation("World object deleted: Id={Id}", id);

                return NoContent();
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error deleting world object {Id}", id);
                return StatusCode(500, new { message = "Internal server error" });
            }
        }

        private static WorldObjectResponse MapToResponse(WorldObject worldObject)
        {
            return new WorldObjectResponse
            {
                Id = worldObject.Id,
                TemplateId = worldObject.TemplateId,
                SystemId = worldObject.SystemId,
                PosX = worldObject.PosX,
                PosY = worldObject.PosY,
                PosZ = worldObject.PosZ,
                RotW = worldObject.RotW,
                RotX = worldObject.RotX,
                RotY = worldObject.RotY,
                RotZ = worldObject.RotZ,
                InventoryJson = worldObject.InventoryJson,
                ExpirationTime = worldObject.ExpirationTime,
                CreatedAt = worldObject.CreatedAt,
                LastUpdated = worldObject.LastUpdated
            };
        }
    }
}
