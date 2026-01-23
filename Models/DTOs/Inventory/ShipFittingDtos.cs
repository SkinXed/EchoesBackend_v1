namespace Echoes.API.Models.DTOs.Inventory
{
    public class ShipFittingDto
    {
        public Guid FittingId { get; set; }
        public Guid ShipAssetId { get; set; }
        public string Name { get; set; } = string.Empty;
        public string? Description { get; set; }
        public bool IsActive { get; set; }
        public List<FittedModuleDto> Modules { get; set; } = new();
        public DateTime CreatedAt { get; set; }
    }

    public class FittedModuleDto
    {
        public Guid FittedModuleId { get; set; }
        public Guid ModuleAssetId { get; set; }
        public int ModuleTypeId { get; set; }
        public string? ModuleName { get; set; }
        public int SlotNumber { get; set; }
        public int SlotType { get; set; }
        public bool IsOnline { get; set; }
        public int? AmmoTypeId { get; set; }
        public int AmmoQuantity { get; set; }
    }

    public class CreateFittingRequest
    {
        public Guid ShipAssetId { get; set; }
        public string Name { get; set; } = string.Empty;
        public string? Description { get; set; }
    }

    public class FitModuleRequest
    {
        public Guid FittingId { get; set; }
        public Guid ModuleAssetId { get; set; }
        public int SlotNumber { get; set; }
        public int SlotType { get; set; }
    }

    public class UnfitModuleRequest
    {
        public Guid FittedModuleId { get; set; }
    }

    public class LoadAmmoRequest
    {
        public Guid FittedModuleId { get; set; }
        public int AmmoTypeId { get; set; }
        public int Quantity { get; set; }
    }
}
