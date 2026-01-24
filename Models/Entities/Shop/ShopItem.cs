using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using Echoes.API.Models.Enums;

namespace Echoes.API.Models.Entities.Shop;

[Table("shop_items")]
public class ShopItem
{
    [Key]
    [Column("id")]
    public Guid Id { get; set; } = Guid.NewGuid();
    
    [Required]
    [Column("name")]
    [MaxLength(200)]
    public string Name { get; set; } = string.Empty;
    
    [Column("description")]
    [MaxLength(1000)]
    public string Description { get; set; } = string.Empty;
    
    [Required]
    [Column("price")]
    public long Price { get; set; }
    
    [Column("category")]
    public ShopItemCategory Category { get; set; } = ShopItemCategory.Equipment;
    
    [Column("image_url")]
    [MaxLength(500)]
    public string? ImageUrl { get; set; }
    
    [Column("created_at")]
    public DateTime CreatedAt { get; set; } = DateTime.UtcNow;
    
    [Column("is_active")]
    public bool IsActive { get; set; } = true;
}
