using Microsoft.AspNetCore.Mvc;
using Echoes.API.Data;
using Echoes.API.Models.Entities.Universe;
using Microsoft.EntityFrameworkCore;

namespace Echoes.API.Controllers
{
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

        // GET: api/stargate/system/{systemId}
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

        // POST: api/stargate/jump
        [HttpPost("jump")]
        public async Task<IActionResult> ExecuteJump([FromBody] JumpRequest request)
        {
            try
            {
                var stargate = await _context.Stargates
                    .Include(sg => sg.DestinationSolarSystem)
                    .FirstOrDefaultAsync(sg => sg.Id == request.StargateId);

                if (stargate == null)
                {
                    return NotFound(new { message = "Stargate not found" });
                }

                if (!stargate.IsOperational)
                {
                    return BadRequest(new { message = "Stargate is not operational" });
                }

                if (stargate.DestinationSolarSystem == null)
                {
                    return BadRequest(new { message = "Destination system not found" });
                }

                // Здесь можно добавить логику проверки прав доступа, стоимости и т.д.

                return Ok(new
                {
                    message = "Jump initiated",
                    destinationSystem = new
                    {
                        stargate.DestinationSolarSystem.Id,
                        stargate.DestinationSolarSystem.Name,
                        stargate.DestinationSolarSystem.SecurityStatus
                    },
                    jumpCost = stargate.JumpCost,
                    estimatedTime = 30 // секунд
                });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error executing jump");
                return StatusCode(500, new { message = ex.Message });
            }
        }

        public class JumpRequest
        {
            public Guid StargateId { get; set; }
            public Guid CharacterId { get; set; }
        }
    }
}