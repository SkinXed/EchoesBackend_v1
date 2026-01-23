using Echoes.API.Models.DTOs.Inventory;
using Echoes.API.Models.Enums;
using Echoes.API.Services.Inventory;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;

namespace Echoes.API.Controllers.Inventory
{
    /// <summary>
    /// Controller for advanced inventory operations (split, merge, bulk moves)
    /// </summary>
    [ApiController]
    [Route("api/inventory/operations")]
    [Authorize(Policy = "PlayerAccess")]
    public class InventoryOperationsController : ControllerBase
    {
        private readonly IInventoryOperationsService _operationsService;
        private readonly ILogger<InventoryOperationsController> _logger;

        public InventoryOperationsController(
            IInventoryOperationsService operationsService,
            ILogger<InventoryOperationsController> logger)
        {
            _operationsService = operationsService;
            _logger = logger;
        }

        /// <summary>
        /// Split a stack of items into two stacks
        /// </summary>
        [HttpPost("split")]
        public async Task<ActionResult<InventoryItemDTO>> SplitStack([FromBody] SplitStackRequest request)
        {
            try
            {
                var actorId = GetActorId();
                var result = await _operationsService.SplitStackAsync(request, actorId);
                return Ok(result);
            }
            catch (ArgumentException ex)
            {
                return BadRequest(new { error = ex.Message });
            }
            catch (InvalidOperationException ex)
            {
                return BadRequest(new { error = ex.Message });
            }
        }

        /// <summary>
        /// Merge multiple stacks of the same item type into one
        /// </summary>
        [HttpPost("merge")]
        public async Task<ActionResult<InventoryItemDTO>> MergeStacks([FromBody] MergeStacksRequest request)
        {
            try
            {
                var actorId = GetActorId();
                var result = await _operationsService.MergeStacksAsync(request, actorId);
                return Ok(result);
            }
            catch (ArgumentException ex)
            {
                return BadRequest(new { error = ex.Message });
            }
            catch (InvalidOperationException ex)
            {
                return BadRequest(new { error = ex.Message });
            }
        }

        /// <summary>
        /// Move an item to a different location with optional split
        /// </summary>
        [HttpPost("move")]
        public async Task<ActionResult<InventoryItemDTO>> MoveItem([FromBody] MoveItemRequest request)
        {
            try
            {
                var actorId = GetActorId();
                var result = await _operationsService.MoveItemAsync(request, actorId);
                return Ok(result);
            }
            catch (ArgumentException ex)
            {
                return BadRequest(new { error = ex.Message });
            }
            catch (InvalidOperationException ex)
            {
                return BadRequest(new { error = ex.Message });
            }
        }

        /// <summary>
        /// Get all items in a container with a specific flag
        /// </summary>
        [HttpGet("container/{containerId}/flag/{flag}")]
        public async Task<ActionResult<List<InventoryItemDTO>>> GetItemsByFlag(
            Guid containerId,
            InventoryFlag flag)
        {
            try
            {
                var result = await _operationsService.GetItemsByFlagAsync(containerId, flag);
                return Ok(result);
            }
            catch (InvalidOperationException ex)
            {
                return BadRequest(new { error = ex.Message });
            }
        }

        /// <summary>
        /// Get enhanced container contents with items grouped by flag
        /// </summary>
        [HttpGet("container/{containerId}/enhanced")]
        public async Task<ActionResult<ContainerContentsDTO>> GetEnhancedContainerContents(Guid containerId)
        {
            try
            {
                var result = await _operationsService.GetEnhancedContainerContentsAsync(containerId);
                return Ok(result);
            }
            catch (InvalidOperationException ex)
            {
                return NotFound(new { error = ex.Message });
            }
        }

        private Guid GetActorId()
        {
            var userIdClaim = User.FindFirst("sub") ?? User.FindFirst("userId") ?? User.FindFirst("id");
            if (userIdClaim != null && Guid.TryParse(userIdClaim.Value, out var userId))
            {
                return userId;
            }

            throw new UnauthorizedAccessException("Unable to determine actor ID from authentication token");
        }
    }
}
