using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Echoes.API.Models.Entities.Inventory
{
    [Table("fitted_modules")]
    public class FittedModule
    {
        [Key]
        [Column("fitted_module_id")]
        public Guid FittedModuleId { get; set; } = Guid.NewGuid();

        [Required]
        [Column("fitting_id")]
        public Guid FittingId { get; set; }

        [Required]
        [Column("module_asset_id")]
        public Guid ModuleAssetId { get; set; }

        [Column("slot_number")]
        public int SlotNumber { get; set; }

        [Column("slot_type")]
        public int SlotType { get; set; }

        [Column("is_online")]
        public bool IsOnline { get; set; } = true;

        [Column("ammo_type_id")]
        public int? AmmoTypeId { get; set; }

        [Column("ammo_quantity")]
        public int AmmoQuantity { get; set; } = 0;

        [Column("created_at")]
        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;

        // Navigation properties
        [ForeignKey(nameof(FittingId))]
        public virtual ShipFitting Fitting { get; set; } = null!;

        [ForeignKey(nameof(ModuleAssetId))]
        public virtual Asset ModuleAsset { get; set; } = null!;

        [ForeignKey(nameof(AmmoTypeId))]
        public virtual ItemTypeEntity? AmmoType { get; set; }
    }
}
