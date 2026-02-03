using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using Echoes.API.Data;
using Echoes.API.Models.Entities.Shop;
using Echoes.API.Models.Entities.Inventory;
using Echoes.API.Models.Entities.Character;
using Echoes.API.Models.Enums;
using EchoesOfImperial.Shared.DTOs;
using System.Security.Claims;

namespace Echoes.API.Controllers;

[Authorize] // Requires authentication (any logged-in Pilot or Admin)
[ApiController]
[Route("api/[controller]")]
public class ShopController : ControllerBase
{
    private readonly DatabaseContext _context;
    private readonly ILogger<ShopController> _logger;

    public ShopController(DatabaseContext context, ILogger<ShopController> logger)
    {
        _context = context;
        _logger = logger;
    }

    /// <summary>
    /// Get all active shop items, optionally filtered by category
    /// </summary>
    /// <param name="category">Optional category filter (Equipment, Credits, VipStatus, Consumables, Cosmetic)</param>
    /// <returns>List of shop items</returns>
    [HttpGet]
    public async Task<ActionResult<List<ShopItem>>> GetShopItems([FromQuery] ShopItemCategory? category = null)
    {
        try
        {
            var query = _context.ShopItems.Where(item => item.IsActive);

            if (category.HasValue)
            {
                query = query.Where(item => item.Category == category.Value);
            }

            var items = await query
                .OrderBy(item => item.Category)
                .ThenBy(item => item.Price)
                .ToListAsync();

            return Ok(items);
        }
        catch (Exception ex)
        {
            _logger.LogError(ex, "Error retrieving shop items");
            return StatusCode(500, new { error = "Internal server error" });
        }
    }

    /// <summary>
    /// Get all available shop categories with item counts
    /// </summary>
    /// <returns>List of categories with counts</returns>
    [HttpGet("categories")]
    public async Task<ActionResult> GetCategories()
    {
        try
        {
            var categories = await _context.ShopItems
                .Where(item => item.IsActive)
                .GroupBy(item => item.Category)
                .Select(g => new
                {
                    Category = g.Key,
                    CategoryName = g.Key.ToString(),
                    ItemCount = g.Count()
                })
                .OrderBy(c => c.Category)
                .ToListAsync();

            return Ok(categories);
        }
        catch (Exception ex)
        {
            _logger.LogError(ex, "Error retrieving shop categories");
            return StatusCode(500, new { error = "Internal server error" });
        }
    }

    /// <summary>
    /// Get a specific shop item by ID
    /// </summary>
    /// <param name="id">Item ID</param>
    /// <returns>Shop item details</returns>
    [HttpGet("{id}")]
    public async Task<ActionResult<ShopItem>> GetShopItem(Guid id)
    {
        try
        {
            var item = await _context.ShopItems.FindAsync(id);

            if (item == null || !item.IsActive)
            {
                return NotFound(new { error = "Item not found" });
            }

            return Ok(item);
        }
        catch (Exception ex)
        {
            _logger.LogError(ex, "Error retrieving shop item {ItemId}", id);
            return StatusCode(500, new { error = "Internal server error" });
        }
    }

    /// <summary>
    /// Create a new shop item (Admin only)
    /// </summary>
    /// <param name="request">Shop item data</param>
    /// <returns>Created shop item</returns>
    [HttpPost]
    [Authorize(Roles = "Admin")]
    public async Task<ActionResult<ShopItemDto>> CreateShopItem([FromBody] ShopItemCreateDto request)
    {
        try
        {
            // Get admin username for logging
            var userName = User.FindFirst(ClaimTypes.Name)?.Value ?? User.FindFirst("username")?.Value ?? "Admin";

            // Parse category
            if (!Enum.TryParse<ShopItemCategory>(request.Category, true, out var category))
            {
                return BadRequest(new { error = "Invalid category. Must be one of: Equipment, Credits, VipStatus, Consumables, Cosmetic" });
            }

            var shopItem = new ShopItem
            {
                Id = Guid.NewGuid(),
                Name = request.Name,
                Description = request.Description,
                Price = request.Price,
                Category = category,
                ImageUrl = request.ImageUrl,
                CreatedAt = DateTime.UtcNow,
                IsActive = true
            };

            _context.ShopItems.Add(shopItem);
            await _context.SaveChangesAsync();

            _logger.LogInformation("[ADMIN] {UserName} created shop item: {ItemName} (Price: {Price})", 
                userName, shopItem.Name, shopItem.Price);

            var result = new ShopItemDto
            {
                Id = shopItem.Id,
                Name = shopItem.Name,
                Description = shopItem.Description,
                Price = shopItem.Price,
                ImageUrl = shopItem.ImageUrl,
                Category = shopItem.Category.ToString(),
                IsActive = shopItem.IsActive,
                CreatedAt = shopItem.CreatedAt
            };

            return CreatedAtAction(nameof(GetShopItem), new { id = shopItem.Id }, result);
        }
        catch (Exception ex)
        {
            _logger.LogError(ex, "Error creating shop item");
            return StatusCode(500, new { error = "Failed to create shop item" });
        }
    }

    /// <summary>
    /// Update an existing shop item (Admin only)
    /// </summary>
    /// <param name="id">Item ID</param>
    /// <param name="request">Updated shop item data</param>
    /// <returns>Updated shop item</returns>
    [HttpPut("{id}")]
    [Authorize(Roles = "Admin")]
    public async Task<ActionResult<ShopItemDto>> UpdateShopItem(Guid id, [FromBody] ShopItemCreateDto request)
    {
        try
        {
            var userName = User.FindFirst(ClaimTypes.Name)?.Value ?? User.FindFirst("username")?.Value ?? "Admin";

            var shopItem = await _context.ShopItems.FindAsync(id);
            if (shopItem == null)
            {
                return NotFound(new { error = "Shop item not found" });
            }

            // Parse category
            if (!Enum.TryParse<ShopItemCategory>(request.Category, true, out var category))
            {
                return BadRequest(new { error = "Invalid category. Must be one of: Equipment, Credits, VipStatus, Consumables, Cosmetic" });
            }

            shopItem.Name = request.Name;
            shopItem.Description = request.Description;
            shopItem.Price = request.Price;
            shopItem.Category = category;
            shopItem.ImageUrl = request.ImageUrl;

            await _context.SaveChangesAsync();

            _logger.LogInformation("[ADMIN] {UserName} updated shop item: {ItemName} (ID: {ItemId})", 
                userName, shopItem.Name, shopItem.Id);

            var result = new ShopItemDto
            {
                Id = shopItem.Id,
                Name = shopItem.Name,
                Description = shopItem.Description,
                Price = shopItem.Price,
                ImageUrl = shopItem.ImageUrl,
                Category = shopItem.Category.ToString(),
                IsActive = shopItem.IsActive,
                CreatedAt = shopItem.CreatedAt
            };

            return Ok(result);
        }
        catch (Exception ex)
        {
            _logger.LogError(ex, "Error updating shop item {ItemId}", id);
            return StatusCode(500, new { error = "Failed to update shop item" });
        }
    }

    /// <summary>
    /// Deactivate a shop item (Admin only)
    /// </summary>
    /// <param name="id">Item ID</param>
    /// <returns>Success message</returns>
    [HttpDelete("{id}")]
    [Authorize(Roles = "Admin")]
    public async Task<ActionResult> DeleteShopItem(Guid id)
    {
        try
        {
            var userName = User.FindFirst(ClaimTypes.Name)?.Value ?? User.FindFirst("username")?.Value ?? "Admin";

            var shopItem = await _context.ShopItems.FindAsync(id);
            if (shopItem == null)
            {
                return NotFound(new { error = "Shop item not found" });
            }

            // Soft delete by setting IsActive to false
            shopItem.IsActive = false;
            await _context.SaveChangesAsync();

            _logger.LogInformation("[ADMIN] {UserName} deactivated shop item: {ItemName} (ID: {ItemId})", 
                userName, shopItem.Name, shopItem.Id);

            return Ok(new { message = "Shop item deactivated successfully" });
        }
        catch (Exception ex)
        {
            _logger.LogError(ex, "Error deleting shop item {ItemId}", id);
            return StatusCode(500, new { error = "Failed to delete shop item" });
        }
    }

    /// <summary>
    /// Purchase a shop item with wallet balance
    /// POST /api/shop/purchase/{id}
    /// </summary>
    /// <param name="id">Item ID to purchase</param>
    /// <returns>Purchase result with updated balance</returns>
    [HttpPost("purchase/{id}")]
    public async Task<ActionResult> PurchaseItem(Guid id)
    {
        // Use IDbContextTransaction for atomicity
        using var transaction = await _context.Database.BeginTransactionAsync();
        
        try
        {
            // 1. Get character ID from JWT token
            var characterIdClaim = User.FindFirst("CharacterId")?.Value;
            if (string.IsNullOrEmpty(characterIdClaim) || !Guid.TryParse(characterIdClaim, out var characterId))
            {
                _logger.LogWarning("[PURCHASE FAILED] Invalid or missing character ID in token");
                return Unauthorized(new { error = "Imperial Treasury: Authentication required" });
            }

            // 2. Find character in database
            var character = await _context.Characters
                .Include(c => c.Wallets)
                .FirstOrDefaultAsync(c => c.Id == characterId);

            if (character == null)
            {
                _logger.LogWarning("[PURCHASE FAILED] Character not found: {CharacterId}", characterId);
                return NotFound(new { error = "Imperial Treasury: Pilot record not found" });
            }

            // 3. Find shop item
            var shopItem = await _context.ShopItems.FindAsync(id);
            if (shopItem == null || !shopItem.IsActive)
            {
                _logger.LogWarning("[PURCHASE FAILED] Item not found or unavailable: {ItemId}", id);
                return NotFound(new { error = "Imperial Treasury: Item not available" });
            }

            // 4. Check sufficient funds
            if (character.WalletBalance < shopItem.Price)
            {
                _logger.LogInformation("[PURCHASE DENIED] {CharacterName} insufficient funds for {ItemName}. Has: {Balance}, Needs: {Price}", 
                    character.Name, shopItem.Name, character.WalletBalance, shopItem.Price);
                return BadRequest(new { 
                    error = "Imperial Treasury: Insufficient Funds",
                    currentBalance = character.WalletBalance,
                    requiredAmount = shopItem.Price,
                    deficit = shopItem.Price - character.WalletBalance
                });
            }

            // 5. Deduct from wallet balance
            var oldBalance = character.WalletBalance;
            character.WalletBalance -= shopItem.Price;

            // 6. Create player inventory item (redeem queue for in-game)
            var inventoryItem = new PlayerInventoryItem
            {
                Id = Guid.NewGuid(),
                PlayerId = characterId,
                ShopItemId = id,
                Quantity = 1,
                AcquiredDate = DateTime.UtcNow,
                IsRedeemed = false,
                Notes = $"Purchased from Imperial Store"
            };

            _context.PlayerInventoryItems.Add(inventoryItem);

            // 7. Create wallet transaction for history
            var walletTransaction = new WalletTransaction
            {
                TransactionId = DateTime.UtcNow.Ticks,
                WalletId = characterId, // Use character ID as wallet ID for now
                TransactionType = WalletTransactionType.MarketBuy,
                Amount = -(decimal)shopItem.Price,
                NewBalance = (decimal)character.WalletBalance,
                Description = $"Purchased {shopItem.Name} from Imperial Store",
                ReferenceId = id,
                ReferenceType = "ShopPurchase",
                CreatedAt = DateTime.UtcNow
            };

            _context.WalletTransactions.Add(walletTransaction);

            // 8. Save changes
            await _context.SaveChangesAsync();

            // 9. Commit transaction
            await transaction.CommitAsync();

            _logger.LogInformation("[PURCHASE SUCCESS] {CharacterName} purchased {ItemName} for {Price} credits. New balance: {NewBalance}", 
                character.Name, shopItem.Name, shopItem.Price, character.WalletBalance);

            return Ok(new { 
                success = true,
                message = "Imperial Treasury: Purchase completed successfully",
                item = new {
                    id = shopItem.Id,
                    name = shopItem.Name,
                    price = shopItem.Price
                },
                previousBalance = oldBalance,
                newBalance = character.WalletBalance,
                transactionId = walletTransaction.TransactionId
            });
        }
        catch (Exception ex)
        {
            // Rollback transaction on any error
            await transaction.RollbackAsync();
            
            _logger.LogError(ex, "[PURCHASE ERROR] Failed to process purchase for item {ItemId}", id);
            return StatusCode(500, new { 
                error = "Imperial Treasury: Transaction failed. Your funds remain secure.",
                details = ex.Message 
            });
        }
    }
}
