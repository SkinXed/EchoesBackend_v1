namespace Echoes.API.Models.DTOs.Inventory
{
    public class ItemTypeDto
    {
        public int TypeId { get; set; }
        public string Name { get; set; } = string.Empty;
        public string? Description { get; set; }
        public int? GroupId { get; set; }
        public string? GroupName { get; set; }
        public decimal BaseVolume { get; set; }
        public decimal PackagedVolume { get; set; }
        public bool IsStackable { get; set; }
        public int MaxStackSize { get; set; }
        public decimal? Mass { get; set; }
        public decimal? Capacity { get; set; }
        public int MetaLevel { get; set; }
        public int TechLevel { get; set; }
    }

    public class ShipTypeDto : ItemTypeDto
    {
        public string ShipSize { get; set; } = string.Empty;
        public string? Race { get; set; }
        public int HighSlots { get; set; }
        public int MediumSlots { get; set; }
        public int LowSlots { get; set; }
        public int RigSlots { get; set; }
        public decimal BaseCpu { get; set; }
        public decimal BasePowergrid { get; set; }
        public decimal BaseCargoCapacity { get; set; }
        public decimal BaseShieldHp { get; set; }
        public decimal BaseArmorHp { get; set; }
        public decimal BaseStructureHp { get; set; }
    }

    public class ModuleTypeDto : ItemTypeDto
    {
        public int ModuleCategory { get; set; }
        public int SlotType { get; set; }
        public decimal RequiredCpu { get; set; }
        public decimal RequiredPowergrid { get; set; }
        public decimal ActivationCost { get; set; }
        public decimal ActivationDuration { get; set; }
    }
}
