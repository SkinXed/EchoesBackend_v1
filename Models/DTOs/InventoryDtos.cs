namespace Echoes.API.Models.DTOs
{
    /// <summary>
    /// DTO for ship instance (list view)
    /// Mirrored in UE5 as FEchoesShipInstance
    /// </summary>
    public class ShipInstanceDto
    {
        public Guid InstanceId { get; set; }
        public string Name { get; set; } = string.Empty;
        public int ShipTypeId { get; set; }
        public string ShipTypeName { get; set; } = string.Empty;
        public float Mass { get; set; }
        public Guid? LocationSystemId { get; set; }
        public string LocationName { get; set; } = string.Empty;
        public bool IsActive { get; set; }
        public bool IsDocked { get; set; }
        public int ModuleCount { get; set; }
    }

    /// <summary>
    /// DTO for module instance
    /// Mirrored in UE5 as FEchoesModule
    /// </summary>
    public class ModuleInstanceDto
    {
        public Guid InstanceId { get; set; }
        public int ModuleTypeId { get; set; }
        public string TypeName { get; set; } = string.Empty;
        public string Slot { get; set; } = string.Empty;
        public int SlotIndex { get; set; }
        public bool IsOnline { get; set; }
        public float Mass { get; set; }
        public float ThrustBonus { get; set; }
        public float InertiaModifier { get; set; }
        public float RotationBonus { get; set; }
        public float MaxVelocityModifier { get; set; }
    }

    /// <summary>
    /// DTO for detailed ship fitting
    /// Mirrored in UE5 as FEchoesShipFitting
    /// </summary>
    public class ShipFittingDto
    {
        public Guid ShipInstanceId { get; set; }
        public string ShipName { get; set; } = string.Empty;
        public int ShipTypeId { get; set; }
        public string ShipTypeName { get; set; } = string.Empty;
        public float BaseMass { get; set; }
        public float TotalMass { get; set; }
        public float Thrust { get; set; }
        public float MaxVelocity { get; set; }
        public float InertiaMultiplier { get; set; }
        public float RotationTorque { get; set; }
        public List<ModuleInstanceDto> Modules { get; set; } = new();
    }

    /// <summary>
    /// Request to activate a ship
    /// </summary>
    public class ActivateShipRequest
    {
        public Guid ShipInstanceId { get; set; }
    }

    /// <summary>
    /// Request to fit a module to a ship
    /// </summary>
    public class FitModuleRequest
    {
        public string SlotType { get; set; } = string.Empty; // High, Mid, Low, Rig
        public int SlotIndex { get; set; }
    }
}
