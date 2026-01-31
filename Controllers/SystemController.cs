using Microsoft.AspNetCore.Mvc;
using Echoes.API.Data;

namespace Echoes.API.Controllers
{
    [ApiController]
    [Route("api/[controller]")]
    public class SystemController : ControllerBase
    {
        private readonly DatabaseContext _context;
        private readonly ILogger<SystemController> _logger;

        public SystemController(DatabaseContext context, ILogger<SystemController> logger)
        {
            _context = context;
            _logger = logger;
        }

        /// <summary>
        /// Health check endpoint for API status verification
        /// GET /api/system/status
        /// </summary>
        [HttpGet("status")]
        [ProducesResponseType(StatusCodes.Status200OK)]
        public ActionResult<object> GetStatus()
        {
            try
            {
                // Check database connection
                bool dbConnected = _context.Database.CanConnect();

                return Ok(new
                {
                    status = "online",
                    timestamp = DateTime.UtcNow,
                    database = dbConnected ? "connected" : "disconnected",
                    version = "1.0.0"
                });
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error checking system status");
                return Ok(new
                {
                    status = "degraded",
                    timestamp = DateTime.UtcNow,
                    database = "error",
                    error = ex.Message
                });
            }
        }
    }
}
