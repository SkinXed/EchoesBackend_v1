using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using Echoes.API.Data;
using Echoes.API.Models.Entities.Shop;

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
    /// Get all active shop items
    /// </summary>
    /// <returns>List of shop items</returns>
    [HttpGet]
    public async Task<ActionResult<List<ShopItem>>> GetShopItems()
    {
        try
        {
            var items = await _context.ShopItems
                .Where(item => item.IsActive)
                .OrderBy(item => item.Name)
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
}
