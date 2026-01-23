using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Echoes.API.Models.Entities.Inventory
{
    [Table("assets")]
    public class Asset
    {
        [Key]
        [Column("asset_id")]
        public Guid AssetId { get; set; } = Guid.NewGuid();

        [Required]
        [Column("type_id")]
        public int TypeId { get; set; }

        [Required]
        [Column("owner_id")]
        public Guid OwnerId { get; set; }

        [Required]
        [Column("location_id")]
        public Guid LocationId { get; set; }

        [Column("location_flag")]
        public int LocationFlag { get; set; }

        [Column("quantity")]
        public long Quantity { get; set; }

        [Column("is_singleton")]
        public bool IsSingleton { get; set; } = false;

        [Column("is_online")]
        public bool IsOnline { get; set; } = false;

        [Column("is_bpc")]
        public bool IsBpc { get; set; } = false;

        [Column("material_efficiency")]
        public int MaterialEfficiency { get; set; } = 0;

        [Column("time_efficiency")]
        public int TimeEfficiency { get; set; } = 0;

        [Column("runs")]
        public int Runs { get; set; } = -1;

        [Column("damage")]
        public decimal Damage { get; set; } = 0.0m;

        [Column("meta_data", TypeName = "jsonb")]
        public string? MetaData { get; set; }

        [Column("created_at")]
        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;

        [Column("updated_at")]
        public DateTime UpdatedAt { get; set; } = DateTime.UtcNow;

        // Navigation properties
        [ForeignKey(nameof(TypeId))]
        public virtual ItemTypeEntity ItemType { get; set; } = null!;

        [ForeignKey(nameof(LocationId))]
        public virtual Container Location { get; set; } = null!;

        public virtual ICollection<AssetLog> AssetLogs { get; set; } = new List<AssetLog>();
    }
}
