using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Echoes.API.Models.Entities.Inventory
{
    [Table("ship_fittings")]
    public class ShipFitting
    {
        [Key]
        [Column("fitting_id")]
        public Guid FittingId { get; set; } = Guid.NewGuid();

        [Required]
        [Column("ship_asset_id")]
        public Guid ShipAssetId { get; set; }

        [Required]
        [MaxLength(200)]
        [Column("name")]
        public string Name { get; set; } = string.Empty;

        [Column("description")]
        public string? Description { get; set; }

        [Column("is_active")]
        public bool IsActive { get; set; } = false;

        [Column("created_at")]
        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;

        [Column("updated_at")]
        public DateTime UpdatedAt { get; set; } = DateTime.UtcNow;

        // Navigation properties
        [ForeignKey(nameof(ShipAssetId))]
        public virtual Asset ShipAsset { get; set; } = null!;

        public virtual ICollection<FittedModule> FittedModules { get; set; } = new List<FittedModule>();
    }
}
