using Microsoft.AspNetCore.Mvc;
using Echoes.API.Data;
using Echoes.API.Models.Entities.Universe;
using Microsoft.EntityFrameworkCore;

namespace Echoes.API.Controllers
{
    /// <summary>
    /// Stargate Controller - Query stargate information (legacy endpoint)
    /// For jump operations, use JumpController
    /// </summary>
    [ApiController]
    [Route("api/[controller]")]
    public class StargateController : ControllerBase
    {
        private readonly DatabaseContext _context;
        private readonly ILogger<StargateController> _logger;

        public StargateController(DatabaseContext context, ILogger<StargateController> logger)
        {
            _context = context;
            _logger = logger;
        }

        /// <summary>
        /// Get all stargates in a system
        /// GET /api/stargate/system/{systemId}
        /// </summary>
        [HttpGet("system/{systemId}")]
        public async Task<IActionResult> GetSystemStargates(Guid systemId)
        {
            try
            {
                var stargates = await _context.Stargates
                    .Include(sg => sg.DestinationSolarSystem)
                    .Where(sg => sg.SourceSolarSystemId == systemId)
                    .Select(sg => new
                    {
                        sg.Id,
                        sg.Name,
                        DestinationSystem = sg.DestinationSolarSystem != null ? new
                        {
                            sg.DestinationSolarSystem.Id,
                            sg.DestinationSolarSystem.Name,
                            sg.DestinationSolarSystem.SecurityStatus
                        } : null,
                        sg.IsOperational,
                        sg.JumpCost,
                        sg.Model
                    })
                    .ToListAsync();

                return Ok(stargates);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error getting system stargates");
                return StatusCode(500, new { message = "Internal server error" });
            }
        }
    }
}