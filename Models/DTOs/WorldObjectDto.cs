using System.ComponentModel.DataAnnotations;

namespace Echoes.API.Models.DTOs
{
    /// <summary>
    /// Request DTO for registering a new world object
    /// </summary>
    public class RegisterWorldObjectRequest
    {
        /// <summary>
        /// Template ID for the object type
        /// </summary>
        [Required]
        [Range(1, int.MaxValue)]
        public int TemplateId { get; set; }

        /// <summary>
        /// Solar system ID where object is located
        /// </summary>
        [Required]
        public Guid SystemId { get; set; }

        /// <summary>
        /// Position in 3D space
        /// </summary>
        [Required]
        public double PosX { get; set; }

        [Required]
        public double PosY { get; set; }

        [Required]
        public double PosZ { get; set; }

        /// <summary>
        /// Rotation quaternion
        /// </summary>
        public float RotW { get; set; } = 1.0f;
        public float RotX { get; set; }
        public float RotY { get; set; }
        public float RotZ { get; set; }

        /// <summary>
        /// JSON serialized inventory contents
        /// </summary>
        public string InventoryJson { get; set; } = "{}";

        /// <summary>
        /// Optional expiration time (UTC)
        /// </summary>
        public DateTime? ExpirationTime { get; set; }
    }

    /// <summary>
    /// Request DTO for updating world object inventory
    /// </summary>
    public class UpdateWorldObjectInventoryRequest
    {
        /// <summary>
        /// Updated JSON serialized inventory contents
        /// </summary>
        [Required]
        public string InventoryJson { get; set; } = "{}";
    }

    /// <summary>
    /// Response DTO for world object operations
    /// </summary>
    public class WorldObjectResponse
    {
        public Guid Id { get; set; }
        public int TemplateId { get; set; }
        public Guid SystemId { get; set; }
        
        // Position
        public double PosX { get; set; }
        public double PosY { get; set; }
        public double PosZ { get; set; }
        
        // Rotation
        public float RotW { get; set; }
        public float RotX { get; set; }
        public float RotY { get; set; }
        public float RotZ { get; set; }
        
        // Inventory
        public string InventoryJson { get; set; } = "{}";
        
        // Metadata
        public DateTime? ExpirationTime { get; set; }
        public DateTime CreatedAt { get; set; }
        public DateTime? LastUpdated { get; set; }
    }

    /// <summary>
    /// Response DTO for world object list
    /// </summary>
    public class WorldObjectListResponse
    {
        public int TotalCount { get; set; }
        public List<WorldObjectResponse> Objects { get; set; } = new();
    }
}
