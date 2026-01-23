using System.Text.Json.Serialization;
using Echoes.API.Models.Enums;

namespace Echoes.API.Models.DTOs.Inventory
{
    /// <summary>
    /// Request to move an item to a different location
    /// </summary>
    public class MoveItemRequest
    {
        public Guid AssetId { get; set; }
        public Guid TargetLocationId { get; set; }
        public InventoryFlag TargetFlag { get; set; } = InventoryFlag.Cargo;
        
        [JsonPropertyName("splitQuantity")]
        public long? SplitQuantity { get; set; }
        
        public bool Validate()
        {
            return AssetId != Guid.Empty && 
                   TargetLocationId != Guid.Empty &&
                   (!SplitQuantity.HasValue || SplitQuantity.Value > 0);
        }
    }
    
    /// <summary>
    /// Request to split a stack of items
    /// </summary>
    public class SplitStackRequest
    {
        public Guid AssetId { get; set; }
        public long SplitQuantity { get; set; }
        public Guid? TargetLocationId { get; set; }
        public InventoryFlag? TargetFlag { get; set; }
        
        public bool Validate()
        {
            return AssetId != Guid.Empty && 
                   SplitQuantity > 0;
        }
    }
    
    /// <summary>
    /// Request to merge multiple stacks of the same item
    /// </summary>
    public class MergeStacksRequest
    {
        public List<Guid> AssetIds { get; set; } = new();
        public Guid TargetLocationId { get; set; }
        public InventoryFlag TargetFlag { get; set; } = InventoryFlag.Cargo;
        
        public bool Validate()
        {
            return AssetIds.Count >= 2 && 
                   AssetIds.All(id => id != Guid.Empty) &&
                   TargetLocationId != Guid.Empty;
        }
    }
    
    /// <summary>
    /// Enhanced ItemType DTO with category and group information
    /// </summary>
    public class ItemTypeDTO
    {
        public int TypeId { get; set; }
        public string Name { get; set; } = string.Empty;
        public string Description { get; set; } = string.Empty;
        public decimal Volume { get; set; }
        public decimal PackagedVolume { get; set; }
        public bool IsStackable { get; set; }
        public int MaxStackSize { get; set; }
        public string IconId { get; set; } = string.Empty;
        public int MetaLevel { get; set; }
        public int TechLevel { get; set; }
        public string Category { get; set; } = string.Empty;
        public string Group { get; set; } = string.Empty;
    }
    
    /// <summary>
    /// Enhanced inventory item DTO with flag and computed properties
    /// </summary>
    public class InventoryItemDTO
    {
        public Guid AssetId { get; set; }
        public ItemTypeDTO ItemType { get; set; } = new();
        public Guid OwnerId { get; set; }
        public Guid LocationId { get; set; }
        public InventoryFlag Flag { get; set; }
        public long Quantity { get; set; }
        public bool IsSingleton { get; set; }
        public bool IsOnline { get; set; }
        public decimal Damage { get; set; }
        public decimal TotalVolume { get; set; }
        public DateTime CreatedAt { get; set; }
        public DateTime UpdatedAt { get; set; }
        
        [JsonIgnore]
        public bool CanStack => ItemType.IsStackable && !IsSingleton;
    }
    
    /// <summary>
    /// Enhanced container DTO with computed properties
    /// </summary>
    public class ContainerDTO
    {
        public Guid ContainerId { get; set; }
        public Guid? ParentContainerId { get; set; }
        public Guid OwnerId { get; set; }
        public string ContainerType { get; set; } = string.Empty;
        public string Name { get; set; } = string.Empty;
        public decimal? MaxVolume { get; set; }
        public decimal UsedVolume { get; set; }
        
        [JsonIgnore]
        public decimal AvailableVolume => MaxVolume.HasValue ? MaxVolume.Value - UsedVolume : decimal.MaxValue;
        
        [JsonIgnore]
        public decimal FillPercentage => MaxVolume.HasValue && MaxVolume.Value > 0 ? 
            (UsedVolume / MaxVolume.Value) * 100 : 0;
            
        public bool IsAccessible { get; set; }
        public int AccessLevel { get; set; }
        public DateTime CreatedAt { get; set; }
        public DateTime UpdatedAt { get; set; }
    }
    
    /// <summary>
    /// Enhanced container contents DTO with grouped items
    /// </summary>
    public class ContainerContentsDTO
    {
        public ContainerDTO Container { get; set; } = new();
        public List<InventoryItemDTO> Items { get; set; } = new();
        public Dictionary<InventoryFlag, List<InventoryItemDTO>> ItemsByFlag { get; set; } = new();
        public List<ContainerDTO> ChildContainers { get; set; } = new();
    }
}
