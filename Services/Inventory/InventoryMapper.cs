using Echoes.API.Models.DTOs.Inventory;
using Echoes.API.Models.Entities.Inventory;

namespace Echoes.API.Services.Inventory
{
    /// <summary>
    /// Utility class for mapping between inventory entities and DTOs
    /// </summary>
    public static class InventoryMapper
    {
        /// <summary>
        /// Maps an Asset entity to AssetDto
        /// </summary>
        public static AssetDto MapToAssetDto(Asset asset, ItemTypeEntity? itemType = null)
        {
            return new AssetDto
            {
                AssetId = asset.AssetId,
                TypeId = asset.TypeId,
                TypeName = itemType?.Name ?? asset.ItemType?.Name,
                OwnerId = asset.OwnerId,
                LocationId = asset.LocationId,
                LocationFlag = asset.LocationFlag,
                Quantity = asset.Quantity,
                IsSingleton = asset.IsSingleton,
                IsOnline = asset.IsOnline,
                IsBpc = asset.IsBpc,
                Damage = asset.Damage,
                CreatedAt = asset.CreatedAt,
                UpdatedAt = asset.UpdatedAt
            };
        }

        /// <summary>
        /// Maps a Container entity to ContainerDto
        /// </summary>
        public static ContainerDto MapToContainerDto(Container container)
        {
            return new ContainerDto
            {
                ContainerId = container.ContainerId,
                ParentContainerId = container.ParentContainerId,
                OwnerId = container.OwnerId,
                ContainerType = container.ContainerType,
                Name = container.Name,
                MaxVolume = container.MaxVolume,
                UsedVolume = container.UsedVolume,
                IsAccessible = container.IsAccessible,
                AccessLevel = container.AccessLevel,
                CreatedAt = container.CreatedAt
            };
        }
    }
}
