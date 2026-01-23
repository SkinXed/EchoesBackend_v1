using Echoes.API.Data;
using Echoes.API.Models.DTOs.Inventory;
using Echoes.API.Models.Entities.Inventory;
using Echoes.API.Models.Enums;
using Microsoft.EntityFrameworkCore;

namespace Echoes.API.Services.Inventory
{
    /// <summary>
    /// Service for advanced inventory operations (split, merge, bulk operations)
    /// </summary>
    public interface IInventoryOperationsService
    {
        Task<InventoryItemDTO> SplitStackAsync(SplitStackRequest request, Guid actorId);
        Task<InventoryItemDTO> MergeStacksAsync(MergeStacksRequest request, Guid actorId);
        Task<InventoryItemDTO> MoveItemAsync(MoveItemRequest request, Guid actorId);
        Task<List<InventoryItemDTO>> GetItemsByFlagAsync(Guid containerId, InventoryFlag flag);
        Task<ContainerContentsDTO> GetEnhancedContainerContentsAsync(Guid containerId);
    }

    public class InventoryOperationsService : IInventoryOperationsService
    {
        private readonly DatabaseContext _context;
        private readonly ILogger<InventoryOperationsService> _logger;

        public InventoryOperationsService(DatabaseContext context, ILogger<InventoryOperationsService> logger)
        {
            _context = context;
            _logger = logger;
        }

        public async Task<InventoryItemDTO> SplitStackAsync(SplitStackRequest request, Guid actorId)
        {
            if (!request.Validate())
            {
                throw new ArgumentException("Invalid split stack request");
            }

            var sourceAsset = await _context.Assets
                .Include(a => a.ItemType)
                .ThenInclude(it => it.Group)
                .ThenInclude(g => g!.Category)
                .FirstOrDefaultAsync(a => a.AssetId == request.AssetId);

            if (sourceAsset == null)
            {
                throw new InvalidOperationException($"Asset {request.AssetId} not found");
            }

            if (!sourceAsset.ItemType.IsStackable || sourceAsset.IsSingleton)
            {
                throw new InvalidOperationException("Cannot split non-stackable items");
            }

            if (request.SplitQuantity >= sourceAsset.Quantity)
            {
                throw new InvalidOperationException("Split quantity must be less than current quantity");
            }

            // Create new asset with split quantity
            var newAsset = new Asset
            {
                TypeId = sourceAsset.TypeId,
                OwnerId = sourceAsset.OwnerId,
                LocationId = request.TargetLocationId ?? sourceAsset.LocationId,
                LocationFlag = request.TargetFlag.HasValue ? (int)request.TargetFlag.Value : sourceAsset.LocationFlag,
                Quantity = request.SplitQuantity,
                IsSingleton = false,
                IsOnline = false
            };

            // Reduce source quantity
            sourceAsset.Quantity -= request.SplitQuantity;
            sourceAsset.UpdatedAt = DateTime.UtcNow;

            _context.Assets.Add(newAsset);
            await _context.SaveChangesAsync();

            // Log the split operation
            var log = new AssetLog
            {
                AssetId = newAsset.AssetId,
                ActorId = actorId,
                ActionType = "SPLIT",
                OldLocationId = sourceAsset.LocationId,
                NewLocationId = newAsset.LocationId,
                OldQuantity = sourceAsset.Quantity + request.SplitQuantity,
                NewQuantity = request.SplitQuantity,
                Reason = $"Split from {sourceAsset.AssetId}"
            };
            _context.AssetLogs.Add(log);
            await _context.SaveChangesAsync();

            return MapToInventoryItemDTO(newAsset);
        }

        public async Task<InventoryItemDTO> MergeStacksAsync(MergeStacksRequest request, Guid actorId)
        {
            if (!request.Validate())
            {
                throw new ArgumentException("Invalid merge stacks request");
            }

            var assets = await _context.Assets
                .Include(a => a.ItemType)
                .ThenInclude(it => it.Group)
                .ThenInclude(g => g!.Category)
                .Where(a => request.AssetIds.Contains(a.AssetId))
                .ToListAsync();

            if (assets.Count != request.AssetIds.Count)
            {
                throw new InvalidOperationException("Some assets not found");
            }

            // Verify all are same type and stackable
            var firstType = assets.First().TypeId;
            if (assets.Any(a => a.TypeId != firstType))
            {
                throw new InvalidOperationException("Cannot merge different item types");
            }

            if (assets.Any(a => !a.ItemType.IsStackable || a.IsSingleton))
            {
                throw new InvalidOperationException("Cannot merge non-stackable items");
            }

            // Create merged asset
            var totalQuantity = assets.Sum(a => a.Quantity);
            var mergedAsset = new Asset
            {
                TypeId = firstType,
                OwnerId = assets.First().OwnerId,
                LocationId = request.TargetLocationId,
                LocationFlag = (int)request.TargetFlag,
                Quantity = totalQuantity,
                IsSingleton = false,
                IsOnline = false
            };

            _context.Assets.Add(mergedAsset);

            // Remove old assets
            _context.Assets.RemoveRange(assets);
            await _context.SaveChangesAsync();

            // Log the merge
            var log = new AssetLog
            {
                AssetId = mergedAsset.AssetId,
                ActorId = actorId,
                ActionType = "MERGE",
                NewLocationId = request.TargetLocationId,
                NewQuantity = totalQuantity,
                Reason = $"Merged {assets.Count} stacks"
            };
            _context.AssetLogs.Add(log);
            await _context.SaveChangesAsync();

            return MapToInventoryItemDTO(mergedAsset);
        }

        public async Task<InventoryItemDTO> MoveItemAsync(MoveItemRequest request, Guid actorId)
        {
            if (!request.Validate())
            {
                throw new ArgumentException("Invalid move item request");
            }

            var asset = await _context.Assets
                .Include(a => a.ItemType)
                .ThenInclude(it => it.Group)
                .ThenInclude(g => g!.Category)
                .FirstOrDefaultAsync(a => a.AssetId == request.AssetId);

            if (asset == null)
            {
                throw new InvalidOperationException($"Asset {request.AssetId} not found");
            }

            // Handle split move if specified
            if (request.SplitQuantity.HasValue)
            {
                if (!asset.ItemType.IsStackable || asset.IsSingleton)
                {
                    throw new InvalidOperationException("Cannot split non-stackable items");
                }

                if (request.SplitQuantity.Value >= asset.Quantity)
                {
                    throw new InvalidOperationException("Split quantity must be less than current quantity");
                }

                // Create new asset with split quantity at target
                var newAsset = new Asset
                {
                    TypeId = asset.TypeId,
                    OwnerId = asset.OwnerId,
                    LocationId = request.TargetLocationId,
                    LocationFlag = (int)request.TargetFlag,
                    Quantity = request.SplitQuantity.Value,
                    IsSingleton = false,
                    IsOnline = false
                };

                asset.Quantity -= request.SplitQuantity.Value;
                asset.UpdatedAt = DateTime.UtcNow;

                _context.Assets.Add(newAsset);
                await _context.SaveChangesAsync();

                // Log
                var log = new AssetLog
                {
                    AssetId = newAsset.AssetId,
                    ActorId = actorId,
                    ActionType = "SPLIT_MOVE",
                    OldLocationId = asset.LocationId,
                    NewLocationId = request.TargetLocationId,
                    NewQuantity = request.SplitQuantity.Value
                };
                _context.AssetLogs.Add(log);
                await _context.SaveChangesAsync();

                return MapToInventoryItemDTO(newAsset);
            }
            else
            {
                // Move entire stack
                var oldLocation = asset.LocationId;
                var oldFlag = asset.LocationFlag;

                asset.LocationId = request.TargetLocationId;
                asset.LocationFlag = (int)request.TargetFlag;
                asset.UpdatedAt = DateTime.UtcNow;

                await _context.SaveChangesAsync();

                // Log
                var log = new AssetLog
                {
                    AssetId = asset.AssetId,
                    ActorId = actorId,
                    ActionType = "MOVE",
                    OldLocationId = oldLocation,
                    NewLocationId = request.TargetLocationId,
                    OldFlag = oldFlag,
                    NewFlag = asset.LocationFlag
                };
                _context.AssetLogs.Add(log);
                await _context.SaveChangesAsync();

                return MapToInventoryItemDTO(asset);
            }
        }

        public async Task<List<InventoryItemDTO>> GetItemsByFlagAsync(Guid containerId, InventoryFlag flag)
        {
            var assets = await _context.Assets
                .Include(a => a.ItemType)
                .ThenInclude(it => it.Group)
                .ThenInclude(g => g!.Category)
                .Where(a => a.LocationId == containerId && a.LocationFlag == (int)flag)
                .ToListAsync();

            return assets.Select(MapToInventoryItemDTO).ToList();
        }

        public async Task<ContainerContentsDTO> GetEnhancedContainerContentsAsync(Guid containerId)
        {
            var container = await _context.Containers.FindAsync(containerId);
            if (container == null)
            {
                throw new InvalidOperationException($"Container {containerId} not found");
            }

            var assets = await _context.Assets
                .Include(a => a.ItemType)
                .ThenInclude(it => it.Group)
                .ThenInclude(g => g!.Category)
                .Where(a => a.LocationId == containerId)
                .ToListAsync();

            var childContainers = await _context.Containers
                .Where(c => c.ParentContainerId == containerId)
                .ToListAsync();

            var items = assets.Select(MapToInventoryItemDTO).ToList();

            // Group items by flag
            var itemsByFlag = items
                .GroupBy(i => i.Flag)
                .ToDictionary(g => g.Key, g => g.ToList());

            return new ContainerContentsDTO
            {
                Container = MapToContainerDTO(container),
                Items = items,
                ItemsByFlag = itemsByFlag,
                ChildContainers = childContainers.Select(MapToContainerDTO).ToList()
            };
        }

        private static InventoryItemDTO MapToInventoryItemDTO(Asset asset)
        {
            return new InventoryItemDTO
            {
                AssetId = asset.AssetId,
                ItemType = new ItemTypeDTO
                {
                    TypeId = asset.ItemType.TypeId,
                    Name = asset.ItemType.Name,
                    Description = asset.ItemType.Description ?? string.Empty,
                    Volume = asset.ItemType.BaseVolume,
                    PackagedVolume = asset.ItemType.PackagedVolume,
                    IsStackable = asset.ItemType.IsStackable,
                    MaxStackSize = asset.ItemType.MaxStackSize,
                    IconId = asset.ItemType.IconId ?? string.Empty,
                    MetaLevel = asset.ItemType.MetaLevel,
                    TechLevel = asset.ItemType.TechLevel,
                    Category = asset.ItemType.Group?.Category?.Name ?? string.Empty,
                    Group = asset.ItemType.Group?.Name ?? string.Empty
                },
                OwnerId = asset.OwnerId,
                LocationId = asset.LocationId,
                Flag = (InventoryFlag)asset.LocationFlag,
                Quantity = asset.Quantity,
                IsSingleton = asset.IsSingleton,
                IsOnline = asset.IsOnline,
                Damage = asset.Damage,
                TotalVolume = asset.ItemType.BaseVolume * asset.Quantity,
                CreatedAt = asset.CreatedAt,
                UpdatedAt = asset.UpdatedAt
            };
        }

        private static ContainerDTO MapToContainerDTO(Container container)
        {
            return new ContainerDTO
            {
                ContainerId = container.ContainerId,
                ParentContainerId = container.ParentContainerId,
                OwnerId = container.OwnerId,
                ContainerType = container.ContainerType,
                Name = container.Name ?? string.Empty,
                MaxVolume = container.MaxVolume,
                UsedVolume = container.UsedVolume,
                IsAccessible = container.IsAccessible,
                AccessLevel = container.AccessLevel,
                CreatedAt = container.CreatedAt,
                UpdatedAt = container.UpdatedAt
            };
        }
    }
}
