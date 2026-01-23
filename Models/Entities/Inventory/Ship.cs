using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Echoes.API.Models.Entities.Inventory
{
    [Table("ships")]
    public class Ship
    {
        [Key]
        [Column("ship_type_id")]
        [ForeignKey(nameof(ItemType))]
        public int ShipTypeId { get; set; }

        [Required]
        [MaxLength(200)]
        [Column("name")]
        public string Name { get; set; } = string.Empty;

        [Column("description")]
        public string? Description { get; set; }

        [Required]
        [MaxLength(50)]
        [Column("ship_size")]
        public string ShipSize { get; set; } = string.Empty;

        [Column("tech_level")]
        public int TechLevel { get; set; } = 1;

        [MaxLength(50)]
        [Column("race")]
        public string? Race { get; set; }

        [Column("high_slots")]
        public int HighSlots { get; set; } = 0;

        [Column("medium_slots")]
        public int MediumSlots { get; set; } = 0;

        [Column("low_slots")]
        public int LowSlots { get; set; } = 0;

        [Column("rig_slots")]
        public int RigSlots { get; set; } = 0;

        [Column("subsystem_slots")]
        public int SubsystemSlots { get; set; } = 0;

        [Column("drone_capacity")]
        public int DroneCapacity { get; set; } = 0;

        [Column("drone_bandwidth")]
        public int DroneBandwidth { get; set; } = 0;

        [Column("base_cpu")]
        public decimal BaseCpu { get; set; } = 0;

        [Column("base_powergrid")]
        public decimal BasePowergrid { get; set; } = 0;

        [Column("base_capacitor")]
        public decimal BaseCapacitor { get; set; } = 0;

        [Column("base_shield_hp")]
        public decimal BaseShieldHp { get; set; } = 0;

        [Column("base_armor_hp")]
        public decimal BaseArmorHp { get; set; } = 0;

        [Column("base_structure_hp")]
        public decimal BaseStructureHp { get; set; } = 0;

        [Column("base_speed")]
        public decimal BaseSpeed { get; set; } = 0;

        [Column("base_agility")]
        public decimal BaseAgility { get; set; } = 0;

        [Column("base_signature_radius")]
        public decimal BaseSignatureRadius { get; set; } = 0;

        [Column("base_cargo_capacity")]
        public decimal BaseCargoCapacity { get; set; } = 0;

        [Column("shield_resistance_em")]
        public decimal ShieldResistanceEm { get; set; } = 0;

        [Column("shield_resistance_thermal")]
        public decimal ShieldResistanceThermal { get; set; } = 0;

        [Column("shield_resistance_kinetic")]
        public decimal ShieldResistanceKinetic { get; set; } = 0;

        [Column("shield_resistance_explosive")]
        public decimal ShieldResistanceExplosive { get; set; } = 0;

        [Column("armor_resistance_em")]
        public decimal ArmorResistanceEm { get; set; } = 0;

        [Column("armor_resistance_thermal")]
        public decimal ArmorResistanceThermal { get; set; } = 0;

        [Column("armor_resistance_kinetic")]
        public decimal ArmorResistanceKinetic { get; set; } = 0;

        [Column("armor_resistance_explosive")]
        public decimal ArmorResistanceExplosive { get; set; } = 0;

        [Column("structure_resistance_em")]
        public decimal StructureResistanceEm { get; set; } = 0;

        [Column("structure_resistance_thermal")]
        public decimal StructureResistanceThermal { get; set; } = 0;

        [Column("structure_resistance_kinetic")]
        public decimal StructureResistanceKinetic { get; set; } = 0;

        [Column("structure_resistance_explosive")]
        public decimal StructureResistanceExplosive { get; set; } = 0;

        [Column("ship_bonuses", TypeName = "jsonb")]
        public string ShipBonuses { get; set; } = "{}";

        [Column("created_at")]
        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;

        [Column("updated_at")]
        public DateTime UpdatedAt { get; set; } = DateTime.UtcNow;

        // Navigation properties
        public virtual ItemTypeEntity ItemType { get; set; } = null!;
    }
}
