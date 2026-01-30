using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using Echoes.API.Models.Entities.Character;

namespace Echoes.API.Models.Entities.Inventory
{
    /// <summary>
    /// Represents a player-owned ship instance
    /// </summary>
    [Table("ship_instances")]
    public class ShipInstance
    {
        [Key]
        public Guid Id { get; set; }

        [Required]
        [MaxLength(100)]
        [Column("name")]
        public string Name { get; set; } = string.Empty;

        /// <summary>
        /// Reference to the ship type (static data)
        /// </summary>
        [Column("ship_type_id")]
        [ForeignKey(nameof(ShipType))]
        public int ShipTypeId { get; set; }

        /// <summary>
        /// Owner character ID
        /// </summary>
        [Column("character_id")]
        [ForeignKey(nameof(Character))]
        public Guid CharacterId { get; set; }

        /// <summary>
        /// Current location system ID
        /// </summary>
        [Column("location_system_id")]
        public Guid? LocationSystemId { get; set; }

        /// <summary>
        /// Whether the ship is currently active/undocked
        /// </summary>
        [Column("is_active")]
        public bool IsActive { get; set; } = true;

        /// <summary>
        /// Whether the ship is docked
        /// </summary>
        [Column("is_docked")]
        public bool IsDocked { get; set; } = true;

        [Column("created_at")]
        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;

        [Column("updated_at")]
        public DateTime? UpdatedAt { get; set; }

        // Navigation properties
        public virtual Ship ShipType { get; set; } = null!;
        public virtual Character.Character Character { get; set; } = null!;
        public virtual ICollection<ShipInstanceModule> FittedModules { get; set; } = new List<ShipInstanceModule>();
    }
}
