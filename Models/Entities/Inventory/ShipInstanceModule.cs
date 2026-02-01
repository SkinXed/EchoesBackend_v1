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
        public Guid? ShipInstanceId { get; set; }

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

        // Module bonuses/modifiers
        
        /// <summary>
        /// Thrust bonus in Newtons (additive)
        /// </summary>
        [Column("thrust_bonus")]
        public decimal ThrustBonus { get; set; } = 0;

        /// <summary>
        /// Inertia modifier (multiplicative, < 1.0 improves agility)
        /// </summary>
        [Column("inertia_modifier")]
        public decimal InertiaModifier { get; set; } = 1.0m;

        /// <summary>
        /// Rotation torque bonus in degrees/sec (additive)
        /// </summary>
        [Column("rotation_bonus")]
        public decimal RotationBonus { get; set; } = 0;

        /// <summary>
        /// Max velocity modifier (multiplicative)
        /// </summary>
        [Column("max_velocity_modifier")]
        public decimal MaxVelocityModifier { get; set; } = 1.0m;

        [Column("created_at")]
        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;

        // Navigation properties
        public virtual ShipInstance? ShipInstance { get; set; } = null!;
    }
}
