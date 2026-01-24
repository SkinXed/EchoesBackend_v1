using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using Echoes.API.Data;
using Echoes.API.Models.Entities.Inventory;
using EchoesOfImperial.Shared.DTOs;
using System.Security.Claims;

namespace Echoes.API.Controllers;

/// <summary>
/// Web Inventory / Redeem Queue Controller
/// Manages purchased items before they are redeemed in-game
/// </summary>
[Authorize] // Only for logged-in users
[ApiController]
[Route("api/[controller]")]
public class InventoryController : ControllerBase
{
    private readonly DatabaseContext _context;
    private readonly ILogger<InventoryController> _logger;

    public InventoryController(DatabaseContext context, ILogger<InventoryController> logger)
    {
        _context = context;
        _logger = logger;
    }

    /// <summary>
    /// Get current user's web inventory (unredeemed items)
    /// </summary>
    /// <param name="includeRedeemed">Include already redeemed items (default: false)</param>
    /// <returns>List of inventory items</returns>
    [HttpGet]
    public async Task<ActionResult<List<WebInventoryItemDTO>>> GetMyInventory([FromQuery] bool includeRedeemed = false)
    {
        try
        {
            // Extract user ID from JWT token
            var userIdClaim = User.FindFirst(ClaimTypes.NameIdentifier)?.Value 
                ?? User.FindFirst("sub")?.Value;
            
            if (string.IsNullOrEmpty(userIdClaim) || !Guid.TryParse(userIdClaim, out var userId))
            {
                return Unauthorized(new { error = "Invalid token" });
            }

            // Get character ID from claims
            var characterIdClaim = User.FindFirst("CharacterId")?.Value;
            if (string.IsNullOrEmpty(characterIdClaim) || !Guid.TryParse(characterIdClaim, out var characterId))
            {
                return Unauthorized(new { error = "Invalid token - no character ID" });
            }

            // Query inventory items
            var query = _context.PlayerInventoryItems
                .Include(i => i.ShopItem)
                .Where(i => i.PlayerId == characterId);

            if (!includeRedeemed)
            {
                query = query.Where(i => !i.IsRedeemed);
            }

            var items = await query
                .OrderByDescending(i => i.AcquiredDate)
                .Select(i => new WebInventoryItemDTO
                {
                    Id = i.Id,
                    ItemName = i.ShopItem != null ? i.ShopItem.Name : "Unknown Item",
                    Category = i.ShopItem != null ? i.ShopItem.Category.ToString() : "Unknown",
                    Quantity = i.Quantity,
                    ImageUrl = i.ShopItem != null ? i.ShopItem.ImageUrl : null,
                    EstimatedValue = i.ShopItem != null ? i.ShopItem.Price * i.Quantity : 0,
                    AcquiredDate = i.AcquiredDate,
                    IsRedeemed = i.IsRedeemed,
                    RedeemedDate = i.RedeemedDate
                })
                .ToListAsync();

            return Ok(items);
        }
        catch (Exception ex)
        {
            _logger.LogError(ex, "Error retrieving inventory");
            return StatusCode(500, new { error = "Internal server error" });
        }
    }

    /// <summary>
    /// Get inventory statistics
    /// </summary>
    /// <returns>Inventory stats</returns>
    [HttpGet("stats")]
    public async Task<ActionResult> GetInventoryStats()
    {
        try
        {
            var userIdClaim = User.FindFirst(ClaimTypes.NameIdentifier)?.Value 
                ?? User.FindFirst("sub")?.Value;
            
            if (string.IsNullOrEmpty(userIdClaim) || !Guid.TryParse(userIdClaim, out var userId))
            {
                return Unauthorized(new { error = "Invalid token" });
            }

            var characterIdClaim = User.FindFirst("CharacterId")?.Value;
            if (string.IsNullOrEmpty(characterIdClaim) || !Guid.TryParse(characterIdClaim, out var characterId))
            {
                return Unauthorized(new { error = "Invalid token" });
            }

            var totalItems = await _context.PlayerInventoryItems
                .Where(i => i.PlayerId == characterId)
                .CountAsync();

            var unredeemedItems = await _context.PlayerInventoryItems
                .Where(i => i.PlayerId == characterId && !i.IsRedeemed)
                .CountAsync();

            var redeemedItems = totalItems - unredeemedItems;

            var totalValue = await _context.PlayerInventoryItems
                .Include(i => i.ShopItem)
                .Where(i => i.PlayerId == characterId && !i.IsRedeemed)
                .SumAsync(i => i.ShopItem != null ? i.ShopItem.Price * i.Quantity : 0);

            return Ok(new
            {
                TotalItems = totalItems,
                UnredeemedItems = unredeemedItems,
                RedeemedItems = redeemedItems,
                TotalValue = totalValue
            });
        }
        catch (Exception ex)
        {
            _logger.LogError(ex, "Error retrieving inventory stats");
            return StatusCode(500, new { error = "Internal server error" });
        }
    }

    /// <summary>
    /// Purchase an item (TEST endpoint - adds item to inventory without payment processing)
    /// </summary>
    /// <param name="request">Purchase request</param>
    /// <returns>Purchase result</returns>
    [HttpPost("purchase")]
    public async Task<ActionResult<PurchaseResponseDTO>> PurchaseItem([FromBody] PurchaseItemRequestDTO request)
    {
        try
        {
            // Extract user/character ID
            var userIdClaim = User.FindFirst(ClaimTypes.NameIdentifier)?.Value 
                ?? User.FindFirst("sub")?.Value;
            
            if (string.IsNullOrEmpty(userIdClaim) || !Guid.TryParse(userIdClaim, out var userId))
            {
                return Unauthorized(new PurchaseResponseDTO 
                { 
                    Success = false, 
                    Message = "Invalid token" 
                });
            }

            var characterIdClaim = User.FindFirst("CharacterId")?.Value;
            if (string.IsNullOrEmpty(characterIdClaim) || !Guid.TryParse(characterIdClaim, out var characterId))
            {
                return Unauthorized(new PurchaseResponseDTO 
                { 
                    Success = false, 
                    Message = "Invalid token - no character ID" 
                });
            }

            // Validate shop item exists
            var shopItem = await _context.ShopItems.FindAsync(request.ShopItemId);
            if (shopItem == null || !shopItem.IsActive)
            {
                return NotFound(new PurchaseResponseDTO 
                { 
                    Success = false, 
                    Message = "Shop item not found or not available" 
                });
            }

            // Validate quantity
            if (request.Quantity <= 0)
            {
                return BadRequest(new PurchaseResponseDTO 
                { 
                    Success = false, 
                    Message = "Quantity must be greater than 0" 
                });
            }

            // Create inventory item
            var inventoryItem = new PlayerInventoryItem
            {
                Id = Guid.NewGuid(),
                PlayerId = characterId,
                ShopItemId = request.ShopItemId,
                Quantity = request.Quantity,
                AcquiredDate = DateTime.UtcNow,
                IsRedeemed = false,
                Notes = "Test purchase from web shop"
            };

            _context.PlayerInventoryItems.Add(inventoryItem);
            await _context.SaveChangesAsync();

            _logger.LogInformation(
                "User {UserId} purchased {Quantity}x {ItemName} (ID: {ItemId})",
                characterId, request.Quantity, shopItem.Name, inventoryItem.Id);

            return Ok(new PurchaseResponseDTO
            {
                Success = true,
                Message = $"Successfully purchased {request.Quantity}x {shopItem.Name}. Item added to your web inventory.",
                InventoryItemId = inventoryItem.Id
            });
        }
        catch (Exception ex)
        {
            _logger.LogError(ex, "Error processing purchase");
            return StatusCode(500, new PurchaseResponseDTO 
            { 
                Success = false, 
                Message = "Internal server error" 
            });
        }
    }

    /// <summary>
    /// Redeem an item (mark as redeemed - in real game, this would transfer to in-game inventory)
    /// </summary>
    /// <param name="request">Redeem request</param>
    /// <returns>Redeem result</returns>
    [HttpPost("redeem")]
    public async Task<ActionResult> RedeemItem([FromBody] RedeemItemRequestDTO request)
    {
        try
        {
            var userIdClaim = User.FindFirst(ClaimTypes.NameIdentifier)?.Value 
                ?? User.FindFirst("sub")?.Value;
            
            if (string.IsNullOrEmpty(userIdClaim) || !Guid.TryParse(userIdClaim, out var userId))
            {
                return Unauthorized(new { error = "Invalid token" });
            }

            var characterIdClaim = User.FindFirst("CharacterId")?.Value;
            if (string.IsNullOrEmpty(characterIdClaim) || !Guid.TryParse(characterIdClaim, out var characterId))
            {
                return Unauthorized(new { error = "Invalid token" });
            }

            // Find inventory item
            var inventoryItem = await _context.PlayerInventoryItems
                .Include(i => i.ShopItem)
                .FirstOrDefaultAsync(i => i.Id == request.InventoryItemId && i.PlayerId == characterId);

            if (inventoryItem == null)
            {
                return NotFound(new { error = "Inventory item not found or does not belong to you" });
            }

            if (inventoryItem.IsRedeemed)
            {
                return BadRequest(new { error = "Item has already been redeemed" });
            }

            // Mark as redeemed
            inventoryItem.IsRedeemed = true;
            inventoryItem.RedeemedDate = DateTime.UtcNow;
            await _context.SaveChangesAsync();

            _logger.LogInformation(
                "User {UserId} redeemed item {ItemName} (Inventory ID: {InventoryId})",
                characterId, inventoryItem.ShopItem?.Name ?? "Unknown", inventoryItem.Id);

            return Ok(new 
            { 
                success = true, 
                message = $"Successfully redeemed {inventoryItem.Quantity}x {inventoryItem.ShopItem?.Name ?? "item"}. Item will be available in-game.",
                itemName = inventoryItem.ShopItem?.Name ?? "Unknown"
            });
        }
        catch (Exception ex)
        {
            _logger.LogError(ex, "Error redeeming item");
            return StatusCode(500, new { error = "Internal server error" });
        }
    }

    /// <summary>
    /// Delete a redeemed item from history (cleanup)
    /// </summary>
    /// <param name="id">Inventory item ID</param>
    /// <returns>Delete result</returns>
    [HttpDelete("{id}")]
    public async Task<ActionResult> DeleteInventoryItem(Guid id)
    {
        try
        {
            var userIdClaim = User.FindFirst(ClaimTypes.NameIdentifier)?.Value 
                ?? User.FindFirst("sub")?.Value;
            
            if (string.IsNullOrEmpty(userIdClaim) || !Guid.TryParse(userIdClaim, out var userId))
            {
                return Unauthorized(new { error = "Invalid token" });
            }

            var characterIdClaim = User.FindFirst("CharacterId")?.Value;
            if (string.IsNullOrEmpty(characterIdClaim) || !Guid.TryParse(characterIdClaim, out var characterId))
            {
                return Unauthorized(new { error = "Invalid token" });
            }

            var inventoryItem = await _context.PlayerInventoryItems
                .FirstOrDefaultAsync(i => i.Id == id && i.PlayerId == characterId);

            if (inventoryItem == null)
            {
                return NotFound(new { error = "Inventory item not found" });
            }

            // Only allow deletion of redeemed items
            if (!inventoryItem.IsRedeemed)
            {
                return BadRequest(new { error = "Cannot delete unredeemed items. Redeem or contact support." });
            }

            _context.PlayerInventoryItems.Remove(inventoryItem);
            await _context.SaveChangesAsync();

            return Ok(new { success = true, message = "Inventory item deleted" });
        }
        catch (Exception ex)
        {
            _logger.LogError(ex, "Error deleting inventory item");
            return StatusCode(500, new { error = "Internal server error" });
        }
    }
}
