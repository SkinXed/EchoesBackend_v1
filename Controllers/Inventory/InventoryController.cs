using Echoes.API.Models.DTOs.Inventory;
using Echoes.API.Services.Inventory;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;

namespace Echoes.API.Controllers.Inventory
{
    [ApiController]
    [Route("api/[controller]")]
    [Authorize(Policy = "PlayerAccess")]
    public class InventoryController : ControllerBase
    {
        private readonly IInventoryService _inventoryService;
        private readonly ILogger<InventoryController> _logger;

        public InventoryController(IInventoryService inventoryService, ILogger<InventoryController> logger)
        {
            _inventoryService = inventoryService;
            _logger = logger;
        }

        /// <summary>
        /// Get asset by ID
        /// </summary>
        [HttpGet("{assetId}")]
        public async Task<ActionResult<AssetDto>> GetAsset(Guid assetId)
        {
            var asset = await _inventoryService.GetAssetAsync(assetId);
            if (asset == null)
            {
                return NotFound();
            }

            return Ok(asset);
        }

        /// <summary>
        /// Get assets in a container
        /// </summary>
        [HttpGet("container/{containerId}")]
        public async Task<ActionResult<AssetListResponse>> GetAssetsInContainer(Guid containerId, [FromQuery] int? locationFlag = null)
        {
            var response = await _inventoryService.GetAssetsInContainerAsync(containerId, locationFlag);
            return Ok(response);
        }

        /// <summary>
        /// Get all assets owned by a player
        /// </summary>
        [HttpGet("owner/{ownerId}")]
        public async Task<ActionResult<AssetListResponse>> GetAssetsByOwner(Guid ownerId)
        {
            var response = await _inventoryService.GetAssetsByOwnerAsync(ownerId);
            return Ok(response);
        }

        /// <summary>
        /// Create a new asset
        /// </summary>
        [HttpPost]
        public async Task<ActionResult<AssetDto>> CreateAsset([FromBody] CreateAssetRequest request)
        {
            try
            {
                var actorId = GetActorId();
                var asset = await _inventoryService.CreateAssetAsync(request, actorId);
                return CreatedAtAction(nameof(GetAsset), new { assetId = asset.AssetId }, asset);
            }
            catch (InvalidOperationException ex)
            {
                return BadRequest(new { error = ex.Message });
            }
        }

        /// <summary>
        /// Update an asset
        /// </summary>
        [HttpPut("{assetId}")]
        public async Task<ActionResult<AssetDto>> UpdateAsset(Guid assetId, [FromBody] UpdateAssetRequest request)
        {
            try
            {
                var actorId = GetActorId();
                var asset = await _inventoryService.UpdateAssetAsync(assetId, request, actorId);
                return Ok(asset);
            }
            catch (InvalidOperationException ex)
            {
                return BadRequest(new { error = ex.Message });
            }
        }

        /// <summary>
        /// Delete an asset
        /// </summary>
        [HttpDelete("{assetId}")]
        public async Task<ActionResult> DeleteAsset(Guid assetId)
        {
            var actorId = GetActorId();
            var result = await _inventoryService.DeleteAssetAsync(assetId, actorId);
            if (!result)
            {
                return NotFound();
            }

            return NoContent();
        }

        /// <summary>
        /// Move an asset to another container
        /// </summary>
        [HttpPost("move")]
        public async Task<ActionResult> MoveAsset([FromBody] MoveAssetRequest request)
        {
            try
            {
                var actorId = GetActorId();
                var result = await _inventoryService.MoveAssetAsync(request, actorId);
                if (!result)
                {
                    return NotFound();
                }

                return Ok(new { message = "Asset moved successfully" });
            }
            catch (InvalidOperationException ex)
            {
                return BadRequest(new { error = ex.Message });
            }
        }

        /// <summary>
        /// Stack two assets together
        /// </summary>
        [HttpPost("stack")]
        public async Task<ActionResult> StackAssets([FromQuery] Guid targetAssetId, [FromQuery] Guid sourceAssetId)
        {
            try
            {
                var actorId = GetActorId();
                var result = await _inventoryService.StackAssetsAsync(targetAssetId, sourceAssetId, actorId);
                if (!result)
                {
                    return NotFound();
                }

                return Ok(new { message = "Assets stacked successfully" });
            }
            catch (InvalidOperationException ex)
            {
                return BadRequest(new { error = ex.Message });
            }
        }

        /// <summary>
        /// Calculate used volume in a container
        /// </summary>
        [HttpGet("container/{containerId}/volume")]
        public async Task<ActionResult<object>> CalculateVolume(Guid containerId)
        {
            var volume = await _inventoryService.CalculateContainerUsedVolumeAsync(containerId);
            return Ok(new { containerId, usedVolume = volume });
        }

        /// <summary>
        /// Get personal hangar storage ID for the authenticated player at a specific station
        /// Returns the container ID of the player's personal hangar at the station
        /// If hangar doesn't exist, creates it automatically
        /// </summary>
        [HttpGet("hangar/{stationId}")]
        public async Task<ActionResult<object>> GetPersonalHangar(int stationId)
        {
            try
            {
                var actorId = GetActorId();
                var hangar = await _inventoryService.GetOrCreatePersonalHangarAsync(actorId, stationId);
                
                return Ok(new 
                { 
                    storageId = hangar.ContainerId,
                    name = hangar.Name,
                    maxVolume = hangar.MaxVolume,
                    usedVolume = hangar.UsedVolume,
                    availableVolume = hangar.AvailableVolume
                });
            }
            catch (InvalidOperationException ex)
            {
                return BadRequest(new { error = ex.Message });
            }
        }

        private Guid GetActorId()
        {
            // Extract actor ID from JWT claims
            var userIdClaim = User.FindFirst("sub") ?? User.FindFirst("userId") ?? User.FindFirst("id");
            if (userIdClaim != null && Guid.TryParse(userIdClaim.Value, out var userId))
            {
                return userId;
            }

            // If no valid user claim, throw unauthorized exception
            throw new UnauthorizedAccessException("Unable to determine actor ID from authentication token");
        }
    }
}
