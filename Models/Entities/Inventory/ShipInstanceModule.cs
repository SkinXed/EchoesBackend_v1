using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Echoes.API.Models.Entities.Inventory
{
    /// <summary>
    /// Represents a module fitted to a ship instance
    /// </summary>
    [Table("ship_instance_modules")]
    public class ShipInstanceModule
    {
        [Key]
        public Guid Id { get; set; }

        [Column("ship_instance_id")]
        [ForeignKey(nameof(ShipInstance))]
        public Guid ShipInstanceId { get; set; }

        /// <summary>
        /// Module type ID from static data
        /// </summary>
        [Column("module_type_id")]
        public int ModuleTypeId { get; set; }

        /// <summary>
        /// Additional mass contributed by this module in kilograms
        /// </summary>
        [Column("mass")]
        public decimal Mass { get; set; }

        /// <summary>
        /// Module slot (High, Mid, Low, Rig, etc.)
        /// </summary>
        [MaxLength(20)]
        [Column("slot")]
        public string Slot { get; set; } = string.Empty;

        /// <summary>
        /// Slot index (0-based)
        /// </summary>
        [Column("slot_index")]
        public int SlotIndex { get; set; }

        /// <summary>
        /// Whether this module is currently online
        /// </summary>
        [Column("is_online")]
        public bool IsOnline { get; set; } = true;

        [Column("created_at")]
        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;

        // Navigation properties
        public virtual ShipInstance ShipInstance { get; set; } = null!;
    }
}
