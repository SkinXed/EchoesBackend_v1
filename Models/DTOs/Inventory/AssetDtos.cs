namespace Echoes.API.Models.DTOs.Inventory
{
    public class AssetDto
    {
        public Guid AssetId { get; set; }
        public int TypeId { get; set; }
        public string? TypeName { get; set; }
        public Guid OwnerId { get; set; }
        public Guid LocationId { get; set; }
        public int LocationFlag { get; set; }
        public long Quantity { get; set; }
        public bool IsSingleton { get; set; }
        public bool IsOnline { get; set; }
        public bool IsBpc { get; set; }
        public decimal Damage { get; set; }
        public DateTime CreatedAt { get; set; }
        public DateTime UpdatedAt { get; set; }
    }

    public class CreateAssetRequest
    {
        public int TypeId { get; set; }
        public Guid OwnerId { get; set; }
        public Guid LocationId { get; set; }
        public int LocationFlag { get; set; } = 0;
        public long Quantity { get; set; } = 1;
        public bool IsSingleton { get; set; } = false;
    }

    public class UpdateAssetRequest
    {
        public Guid? LocationId { get; set; }
        public int? LocationFlag { get; set; }
        public long? Quantity { get; set; }
        public bool? IsOnline { get; set; }
        public decimal? Damage { get; set; }
    }

    public class MoveAssetRequest
    {
        public Guid AssetId { get; set; }
        public Guid TargetLocationId { get; set; }
        public int? TargetFlag { get; set; }
        public string? Reason { get; set; }
    }

    public class AssetListResponse
    {
        public List<AssetDto> Assets { get; set; } = new();
        public int TotalCount { get; set; }
        public decimal TotalVolume { get; set; }
    }

    public class MoveItemBetweenContainersRequest
    {
        public Guid AssetId { get; set; }
        public Guid SourceLocationId { get; set; }
        public Guid TargetLocationId { get; set; }
        public long? Quantity { get; set; }
        public string? Reason { get; set; }
    }
}
