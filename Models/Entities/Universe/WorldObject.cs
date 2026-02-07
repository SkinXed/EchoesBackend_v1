using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Echoes.API.Models.Entities.Universe
{
    /// <summary>
    /// World object entity for persistent objects dropped in space
    /// Includes containers, debris, and other spawned items
    /// </summary>
    [Table("world_objects")]
    public class WorldObject
    {
        [Key]
        public Guid Id { get; set; }

        /// <summary>
        /// Template ID for the object type (e.g., container type, debris type)
        /// </summary>
        [Required]
        public int TemplateId { get; set; }

        /// <summary>
        /// Solar system where this object exists
        /// </summary>
        [ForeignKey(nameof(SolarSystem))]
        [Required]
        public Guid SystemId { get; set; }

        /// <summary>
        /// Position in 3D space (X coordinate)
        /// </summary>
        [Required]
        public double PosX { get; set; }

        /// <summary>
        /// Position in 3D space (Y coordinate)
        /// </summary>
        [Required]
        public double PosY { get; set; }

        /// <summary>
        /// Position in 3D space (Z coordinate)
        /// </summary>
        [Required]
        public double PosZ { get; set; }

        /// <summary>
        /// Rotation quaternion W component
        /// </summary>
        public float RotW { get; set; } = 1.0f;

        /// <summary>
        /// Rotation quaternion X component
        /// </summary>
        public float RotX { get; set; }

        /// <summary>
        /// Rotation quaternion Y component
        /// </summary>
        public float RotY { get; set; }

        /// <summary>
        /// Rotation quaternion Z component
        /// </summary>
        public float RotZ { get; set; }

        /// <summary>
        /// JSON serialized inventory contents
        /// For containers: list of items with quantities
        /// For debris: loot table or empty
        /// </summary>
        [Column(TypeName = "jsonb")]
        public string InventoryJson { get; set; } = "{}";

        /// <summary>
        /// When this object expires and should be cleaned up
        /// Null means never expires
        /// </summary>
        public DateTime? ExpirationTime { get; set; }

        /// <summary>
        /// When this object was created
        /// </summary>
        [Required]
        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;

        /// <summary>
        /// Last time this object was updated (e.g., inventory change)
        /// </summary>
        public DateTime? LastUpdated { get; set; }

        // Navigation properties
        public virtual SolarSystem SolarSystem { get; set; } = null!;
    }
}
