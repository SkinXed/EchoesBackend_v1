using System.ComponentModel.DataAnnotations;

namespace Echoes.API.Models.DTOs
{
    /// <summary>
    /// Request DTO for saving character state from UE5 server
    /// </summary>
    public class SaveCharacterStateRequest
    {
        /// <summary>
        /// Solar system ID where character is located
        /// </summary>
        public Guid? LastSystemId { get; set; }

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
        [Required]
        public float RotW { get; set; } = 1.0f;

        [Required]
        public float RotX { get; set; }

        [Required]
        public float RotY { get; set; }

        [Required]
        public float RotZ { get; set; }

        /// <summary>
        /// Current ship stats
        /// </summary>
        [Required]
        [Range(0, float.MaxValue)]
        public float CurrentShield { get; set; }

        [Required]
        [Range(0, float.MaxValue)]
        public float CurrentArmor { get; set; }

        [Required]
        [Range(0, float.MaxValue)]
        public float CurrentHull { get; set; }

        [Required]
        [Range(0, float.MaxValue)]
        public float CurrentCapacitor { get; set; }

        /// <summary>
        /// Sequence number for optimistic concurrency control
        /// Higher values indicate more recent updates
        /// </summary>
        public long SequenceNumber { get; set; }
    }

    /// <summary>
    /// Response DTO for state save operation
    /// </summary>
    public class SaveCharacterStateResponse
    {
        public bool Success { get; set; }
        public string Message { get; set; } = string.Empty;
        public DateTime LastUpdated { get; set; }
    }

    /// <summary>
    /// Response DTO for getting character state
    /// </summary>
    public class GetCharacterStateResponse
    {
        public Guid CharacterId { get; set; }
        public Guid? LastSystemId { get; set; }
        
        // Position
        public double PosX { get; set; }
        public double PosY { get; set; }
        public double PosZ { get; set; }
        
        // Rotation
        public float RotW { get; set; }
        public float RotX { get; set; }
        public float RotY { get; set; }
        public float RotZ { get; set; }
        
        // Stats
        public float CurrentShield { get; set; }
        public float CurrentArmor { get; set; }
        public float CurrentHull { get; set; }
        public float CurrentCapacitor { get; set; }
        
        public DateTime LastUpdated { get; set; }
        public long SequenceNumber { get; set; }
    }

    /// <summary>
    /// Request DTO for bulk saving character states from UE5 server
    /// Contains array of character state updates
    /// </summary>
    public class BulkSaveCharacterStateRequest
    {
        /// <summary>
        /// Array of character state updates
        /// Maximum recommended size: 50 items per request
        /// </summary>
        [Required]
        public List<BulkCharacterStateItem> States { get; set; } = new List<BulkCharacterStateItem>();
    }

    /// <summary>
    /// Individual character state item for bulk save operations
    /// </summary>
    public class BulkCharacterStateItem
    {
        /// <summary>
        /// Character ID to save state for
        /// </summary>
        [Required]
        public Guid CharacterId { get; set; }

        /// <summary>
        /// Sequence number for optimistic concurrency control
        /// Higher values indicate more recent updates
        /// </summary>
        [Required]
        public long SequenceNumber { get; set; }

        /// <summary>
        /// Solar system ID where character is located
        /// </summary>
        public Guid? LastSystemId { get; set; }

        // Position in 3D space
        [Required]
        public double PosX { get; set; }

        [Required]
        public double PosY { get; set; }

        [Required]
        public double PosZ { get; set; }

        // Rotation quaternion
        [Required]
        public float RotW { get; set; } = 1.0f;

        [Required]
        public float RotX { get; set; }

        [Required]
        public float RotY { get; set; }

        [Required]
        public float RotZ { get; set; }

        // Ship stats
        [Required]
        [Range(0, float.MaxValue)]
        public float CurrentShield { get; set; }

        [Required]
        [Range(0, float.MaxValue)]
        public float CurrentArmor { get; set; }

        [Required]
        [Range(0, float.MaxValue)]
        public float CurrentHull { get; set; }

        [Required]
        [Range(0, float.MaxValue)]
        public float CurrentCapacitor { get; set; }
    }

    /// <summary>
    /// Response DTO for bulk save operation
    /// </summary>
    public class BulkSaveCharacterStateResponse
    {
        /// <summary>
        /// Overall success status
        /// </summary>
        public bool Success { get; set; }

        /// <summary>
        /// Number of states successfully saved
        /// </summary>
        public int SavedCount { get; set; }

        /// <summary>
        /// Number of states skipped due to old sequence numbers
        /// </summary>
        public int SkippedCount { get; set; }

        /// <summary>
        /// Number of states that failed validation or processing
        /// </summary>
        public int FailedCount { get; set; }

        /// <summary>
        /// Optional message describing the operation result
        /// </summary>
        public string Message { get; set; } = string.Empty;

        /// <summary>
        /// Timestamp when the bulk operation completed
        /// </summary>
        public DateTime CompletedAt { get; set; } = DateTime.UtcNow;

        /// <summary>
        /// List of character IDs that were skipped due to old sequence numbers
        /// </summary>
        public List<Guid> SkippedCharacterIds { get; set; } = new List<Guid>();
    }
}
