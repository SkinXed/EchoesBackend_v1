using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Echoes.API.Models.Entities.Character
{
    /// <summary>
    /// Character state persistence for position, rotation, and combat stats
    /// Protects against data loss during logout or server crashes
    /// </summary>
    [Table("character_states")]
    public class CharacterState
    {
        [Key]
        public Guid Id { get; set; }

        /// <summary>
        /// Character ID this state belongs to
        /// </summary>
        [ForeignKey(nameof(Character))]
        [Required]
        public Guid CharacterId { get; set; }

        /// <summary>
        /// Last solar system the character was in
        /// </summary>
        [ForeignKey(nameof(SolarSystem))]
        public Guid? LastSystemId { get; set; }

        // Position in 3D space
        public double PosX { get; set; }
        public double PosY { get; set; }
        public double PosZ { get; set; }

        // Rotation (quaternion)
        public float RotW { get; set; } = 1.0f;
        public float RotX { get; set; }
        public float RotY { get; set; }
        public float RotZ { get; set; }

        // Ship stats - Shield, Armor, Hull
        public float CurrentShield { get; set; }
        public float CurrentArmor { get; set; }
        public float CurrentHull { get; set; }

        // Capacitor energy
        public float CurrentCapacitor { get; set; }

        /// <summary>
        /// Sequence number for optimistic concurrency control
        /// Used to prevent race conditions when multiple updates arrive out of order
        /// Higher values indicate more recent updates
        /// </summary>
        public long SequenceNumber { get; set; }

        /// <summary>
        /// Last time this state was updated
        /// </summary>
        public DateTime LastUpdated { get; set; } = DateTime.UtcNow;

        // Navigation properties
        public virtual Character Character { get; set; } = null!;
        public virtual Universe.SolarSystem? SolarSystem { get; set; }
    }
}
