using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using Echoes.API.Models.Entities.Shop;

namespace Echoes.API.Models.Entities.Inventory;

/// <summary>
/// Web Inventory / Redeem Queue
/// Stores items purchased on the website before they are redeemed in-game
/// </summary>
[Table("player_inventory_items")]
public class PlayerInventoryItem
{
    [Key]
    [Column("id")]
    public Guid Id { get; set; } = Guid.NewGuid();

    [Required]
    [Column("player_id")]
    public Guid PlayerId { get; set; } // Owner (linked to Account/Character)

    [Required]
    [Column("shop_item_id")]
    public Guid ShopItemId { get; set; } // Reference to shop item
    
    [ForeignKey("ShopItemId")]
    public virtual ShopItem? ShopItem { get; set; } // Navigation property

    [Column("quantity")]
    public int Quantity { get; set; } = 1; // Stack size

    [Column("acquired_date")]
    public DateTime AcquiredDate { get; set; } = DateTime.UtcNow;
    
    [Column("is_redeemed")]
    public bool IsRedeemed { get; set; } = false; // false = on web, true = redeemed in-game
    
    [Column("redeemed_date")]
    public DateTime? RedeemedDate { get; set; }
    
    [Column("notes")]
    [MaxLength(500)]
    public string? Notes { get; set; } // Optional purchase notes or metadata
}
