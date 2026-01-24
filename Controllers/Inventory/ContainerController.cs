using Echoes.API.Models.DTOs.Inventory;
using Echoes.API.Services.Inventory;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;

namespace Echoes.API.Controllers.Inventory
{
    [ApiController]
    [Route("api/[controller]")]
    [Authorize(Policy = "PlayerAccess")]
    public class ContainerController : ControllerBase
    {
        private readonly IContainerService _containerService;
        private readonly ILogger<ContainerController> _logger;

        public ContainerController(IContainerService containerService, ILogger<ContainerController> logger)
        {
            _containerService = containerService;
            _logger = logger;
        }

        /// <summary>
        /// Get container by ID
        /// </summary>
        [HttpGet("{containerId}")]
        public async Task<ActionResult<ContainerDto>> GetContainer(Guid containerId)
        {
            var container = await _containerService.GetContainerAsync(containerId);
            if (container == null)
            {
                return NotFound();
            }

            return Ok(container);
        }

        /// <summary>
        /// Get container contents (assets and child containers)
        /// </summary>
        [HttpGet("{containerId}/contents")]
        public async Task<ActionResult<ContainerContentsDto>> GetContainerContents(Guid containerId)
        {
            var contents = await _containerService.GetContainerContentsAsync(containerId);
            if (contents == null)
            {
                return NotFound();
            }

            return Ok(contents);
        }

        /// <summary>
        /// Get all containers owned by a player
        /// </summary>
        [HttpGet("owner/{ownerId}")]
        public async Task<ActionResult<List<ContainerDto>>> GetContainersByOwner(Guid ownerId)
        {
            var containers = await _containerService.GetContainersByOwnerAsync(ownerId);
            return Ok(containers);
        }

        /// <summary>
        /// Create a new container
        /// </summary>
        [HttpPost]
        public async Task<ActionResult<ContainerDto>> CreateContainer([FromBody] CreateContainerRequest request)
        {
            try
            {
                var container = await _containerService.CreateContainerAsync(request);
                return CreatedAtAction(nameof(GetContainer), new { containerId = container.ContainerId }, container);
            }
            catch (InvalidOperationException ex)
            {
                return BadRequest(new { error = ex.Message });
            }
        }

        /// <summary>
        /// Update a container
        /// </summary>
        [HttpPut("{containerId}")]
        public async Task<ActionResult<ContainerDto>> UpdateContainer(Guid containerId, [FromBody] UpdateContainerRequest request)
        {
            try
            {
                var container = await _containerService.UpdateContainerAsync(containerId, request);
                return Ok(container);
            }
            catch (InvalidOperationException ex)
            {
                return BadRequest(new { error = ex.Message });
            }
        }

        /// <summary>
        /// Delete a container
        /// </summary>
        [HttpDelete("{containerId}")]
        public async Task<ActionResult> DeleteContainer(Guid containerId)
        {
            try
            {
                var result = await _containerService.DeleteContainerAsync(containerId);
                if (!result)
                {
                    return NotFound();
                }

                return NoContent();
            }
            catch (InvalidOperationException ex)
            {
                return BadRequest(new { error = ex.Message });
            }
        }
    }
}
