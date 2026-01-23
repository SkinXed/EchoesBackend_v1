using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Echoes.API.Models.Entities.Inventory
{
    /// <summary>
    /// Enhanced ItemType entity matching the inventory system database schema
    /// </summary>
    [Table("item_types")]
    public class ItemTypeEntity
    {
        [Key]
        [Column("type_id")]
        [DatabaseGenerated(DatabaseGeneratedOption.Identity)]
        public int TypeId { get; set; }

        [Column("group_id")]
        public int? GroupId { get; set; }

        [Required]
        [MaxLength(200)]
        [Column("name")]
        public string Name { get; set; } = string.Empty;

        [Column("description")]
        public string? Description { get; set; }

        [Column("base_volume")]
        public decimal BaseVolume { get; set; }

        [Column("packaged_volume")]
        public decimal PackagedVolume { get; set; }

        [Column("is_stackable")]
        public bool IsStackable { get; set; } = true;

        [Column("max_stack_size")]
        public int MaxStackSize { get; set; } = 1000000;

        [Column("is_online")]
        public bool IsOnline { get; set; } = false;

        [Column("mass")]
        public decimal? Mass { get; set; }

        [Column("capacity")]
        public decimal? Capacity { get; set; }

        [Column("market_group_id")]
        public int? MarketGroupId { get; set; }

        [MaxLength(100)]
        [Column("icon_id")]
        public string? IconId { get; set; }

        [Column("meta_level")]
        public int MetaLevel { get; set; } = 0;

        [Column("tech_level")]
        public int TechLevel { get; set; } = 1;

        [Column("created_at")]
        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;

        [Column("updated_at")]
        public DateTime UpdatedAt { get; set; } = DateTime.UtcNow;

        // Navigation properties
        [ForeignKey(nameof(GroupId))]
        public virtual ItemGroup? Group { get; set; }

        public virtual Ship? Ship { get; set; }
        public virtual Module? Module { get; set; }
        public virtual ICollection<Asset> Assets { get; set; } = new List<Asset>();
    }
}
