using System.ComponentModel.DataAnnotations;

namespace Echoes.API.Models.DTOs.Fitting
{
    /// <summary>
    /// DTO for ship fitting response
    /// Maps directly to UE5 FCommon_ShipFittingData structure
    /// </summary>
    public class FittingResponse
    {
        /// <summary>
        /// Character ID this fitting belongs to
        /// </summary>
        public int CharacterId { get; set; }

        /// <summary>
        /// Ship ID/Item ID
        /// </summary>
        public long ShipItemId { get; set; }

        /// <summary>
        /// Ship type name
        /// </summary>
        public string ShipTypeName { get; set; } = string.Empty;

        /// <summary>
        /// High slots (weapons, utility)
        /// </summary>
        public List<ItemSlotResponse> HighSlots { get; set; } = new();

        /// <summary>
        /// Medium slots (shields, propulsion, EWAR)
        /// </summary>
        public List<ItemSlotResponse> MidSlots { get; set; } = new();

        /// <summary>
        /// Low slots (armor, damage mods, engineering)
        /// </summary>
        public List<ItemSlotResponse> LowSlots { get; set; } = new();

        /// <summary>
        /// Rig slots (permanent modifications)
        /// </summary>
        public List<ItemSlotResponse> RigSlots { get; set; } = new();

        // Resource Usage
        public float PowergridUsed { get; set; }
        public float PowergridMax { get; set; }
        public float CPUUsed { get; set; }
        public float CPUMax { get; set; }

        // Calculated Stats
        public float TotalDPS { get; set; }
        public float AlphaStrike { get; set; }
        public float EffectiveHP { get; set; }
        public float MaxSpeed { get; set; }
        public float WarpSpeed { get; set; }
        public float ScanResolution { get; set; }
        public float SignatureRadius { get; set; }
    }

    /// <summary>
    /// DTO for individual equipment slot
    /// Maps directly to UE5 FCommon_ItemSlot structure
    /// </summary>
    public class ItemSlotResponse
    {
        public int SlotIndex { get; set; }
        public string SlotType { get; set; } = "None"; // High, Mid, Low, Rig, Subsystem, None
        public int ItemID { get; set; }
        public string ItemName { get; set; } = "Empty";
        public int Quantity { get; set; }
        public float Cooldown { get; set; }
        public string ModuleState { get; set; } = "Offline"; // Offline, Active, Overload, Cooldown, Damaged
        public bool IsActive { get; set; }
        public bool CanActivate { get; set; }
        public float PowergridRequired { get; set; }
        public float CPURequired { get; set; }
        public float CapacitorCost { get; set; }
    }
}
