using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Echoes.API.Models.Entities.Inventory
{
    [Table("modules")]
    public class Module
    {
        [Key]
        [Column("module_type_id")]
        [ForeignKey(nameof(ItemType))]
        public int ModuleTypeId { get; set; }

        [Required]
        [MaxLength(200)]
        [Column("name")]
        public string Name { get; set; } = string.Empty;

        [Column("description")]
        public string? Description { get; set; }

        [Column("module_category")]
        public int ModuleCategory { get; set; }

        [Column("slot_type")]
        public int SlotType { get; set; }

        [Column("required_cpu")]
        public decimal RequiredCpu { get; set; } = 0;

        [Column("required_powergrid")]
        public decimal RequiredPowergrid { get; set; } = 0;

        [Column("required_capacitor")]
        public decimal RequiredCapacitor { get; set; } = 0;

        [Column("required_skills", TypeName = "jsonb")]
        public string RequiredSkills { get; set; } = "{}";

        [Column("module_effects", TypeName = "jsonb")]
        public string ModuleEffects { get; set; } = "{}";

        [Column("activation_cost")]
        public decimal ActivationCost { get; set; } = 0;

        [Column("activation_duration")]
        public decimal ActivationDuration { get; set; } = 0;

        [Column("cooldown_time")]
        public decimal CooldownTime { get; set; } = 0;

        [Column("max_group_fitted")]
        public int? MaxGroupFitted { get; set; }

        [Column("meta_level")]
        public int MetaLevel { get; set; } = 0;

        [Column("tech_level")]
        public int TechLevel { get; set; } = 1;

        [MaxLength(50)]
        [Column("race")]
        public string? Race { get; set; }

        [Column("created_at")]
        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;

        [Column("updated_at")]
        public DateTime UpdatedAt { get; set; } = DateTime.UtcNow;

        // Navigation properties
        public virtual ItemTypeEntity ItemType { get; set; } = null!;
    }
}
