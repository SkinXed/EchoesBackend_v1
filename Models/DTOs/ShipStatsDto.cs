namespace Echoes.API.Models.DTOs
{
    /// <summary>
    /// DTO for ship statistics response
    /// Mirrored in UE5 as FEchoesShipStats
    /// </summary>
    public class ShipStatsDto
    {
        /// <summary>
        /// Total mass including base mass and all module masses (in kg)
        /// </summary>
        public float TotalMass { get; set; }

        /// <summary>
        /// Base mass without modules (in kg)
        /// </summary>
        public float BaseMass { get; set; }

        /// <summary>
        /// Thrust force in Newtons
        /// </summary>
        public float Thrust { get; set; }

        /// <summary>
        /// Maximum rotation speed in degrees per second
        /// </summary>
        public float RotationSpeed { get; set; }

        /// <summary>
        /// Maximum warp speed multiplier (AU/s)
        /// </summary>
        public float WarpSpeed { get; set; }

        /// <summary>
        /// Inertia multiplier affecting acceleration/deceleration
        /// </summary>
        public float InertiaMultiplier { get; set; }

        /// <summary>
        /// Maximum velocity in meters per second
        /// </summary>
        public float MaxVelocity { get; set; }

        /// <summary>
        /// Agility modifier (lower is more agile)
        /// </summary>
        public float Agility { get; set; }

        /// <summary>
        /// Ship instance ID
        /// </summary>
        public Guid ShipId { get; set; }

        /// <summary>
        /// Ship instance name
        /// </summary>
        public string ShipName { get; set; } = string.Empty;

        /// <summary>
        /// Ship type ID
        /// </summary>
        public int ShipTypeId { get; set; }

        /// <summary>
        /// Ship type name
        /// </summary>
        public string ShipTypeName { get; set; } = string.Empty;
    }
}
