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
    }
}
