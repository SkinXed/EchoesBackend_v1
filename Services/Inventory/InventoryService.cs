using Echoes.API.Data;
using Echoes.API.Models.DTOs.Inventory;
using Echoes.API.Models.Entities.Inventory;
using Microsoft.EntityFrameworkCore;

namespace Echoes.API.Services.Inventory
{
    public class InventoryService : IInventoryService
    {
        private readonly DatabaseContext _context;
        private readonly ILogger<InventoryService> _logger;

        public InventoryService(DatabaseContext context, ILogger<InventoryService> logger)
        {
            _context = context;
            _logger = logger;
        }

        public async Task<AssetDto?> GetAssetAsync(Guid assetId)
        {
            var asset = await _context.Assets
                .Include(a => a.ItemType)
                .FirstOrDefaultAsync(a => a.AssetId == assetId);

            return asset == null ? null : MapToAssetDto(asset);
        }

        public async Task<AssetListResponse> GetAssetsInContainerAsync(Guid containerId, int? locationFlag = null)
        {
            var query = _context.Assets
                .Include(a => a.ItemType)
                .Where(a => a.LocationId == containerId);

            if (locationFlag.HasValue)
            {
                query = query.Where(a => a.LocationFlag == locationFlag.Value);
            }

            var assets = await query.ToListAsync();
            var totalVolume = assets.Sum(a => a.ItemType.BaseVolume * a.Quantity);

            return new AssetListResponse
            {
                Assets = assets.Select(a => MapToAssetDto(a)).ToList(),
                TotalCount = assets.Count,
                TotalVolume = totalVolume
            };
        }

        public async Task<AssetListResponse> GetAssetsByOwnerAsync(Guid ownerId)
        {
            var assets = await _context.Assets
                .Include(a => a.ItemType)
                .Where(a => a.OwnerId == ownerId)
                .ToListAsync();

            var totalVolume = assets.Sum(a => a.ItemType.BaseVolume * a.Quantity);

            return new AssetListResponse
            {
                Assets = assets.Select(a => MapToAssetDto(a)).ToList(),
                TotalCount = assets.Count,
                TotalVolume = totalVolume
            };
        }

        public async Task<AssetDto> CreateAssetAsync(CreateAssetRequest request, Guid actorId)
        {
            // Verify item type exists
            var itemType = await _context.ItemTypesInventory.FindAsync(request.TypeId);
            if (itemType == null)
            {
                throw new InvalidOperationException($"Item type {request.TypeId} not found");
            }

            // Verify container exists
            var container = await _context.Containers.FindAsync(request.LocationId);
            if (container == null)
            {
                throw new InvalidOperationException($"Container {request.LocationId} not found");
            }

            // Check if asset can fit
            var canFit = await CanFitInContainerAsync(request.LocationId, request.TypeId, request.Quantity);
            if (!canFit)
            {
                throw new InvalidOperationException("Not enough space in container");
            }

            var asset = new Asset
            {
                TypeId = request.TypeId,
                OwnerId = request.OwnerId,
                LocationId = request.LocationId,
                LocationFlag = request.LocationFlag,
                Quantity = request.Quantity,
                IsSingleton = request.IsSingleton
            };

            _context.Assets.Add(asset);

            // Log the creation
            await LogAssetActionAsync(asset.AssetId, actorId, "CREATE", null, request.LocationId, null, request.Quantity);

            await _context.SaveChangesAsync();

            return MapToAssetDto(asset, itemType);
        }

        public async Task<AssetDto> UpdateAssetAsync(Guid assetId, UpdateAssetRequest request, Guid actorId)
        {
            var asset = await _context.Assets
                .Include(a => a.ItemType)
                .FirstOrDefaultAsync(a => a.AssetId == assetId);

            if (asset == null)
            {
                throw new InvalidOperationException($"Asset {assetId} not found");
            }

            var oldLocationId = asset.LocationId;
            var oldQuantity = asset.Quantity;

            if (request.LocationId.HasValue)
            {
                asset.LocationId = request.LocationId.Value;
            }

            if (request.LocationFlag.HasValue)
            {
                asset.LocationFlag = request.LocationFlag.Value;
            }

            if (request.Quantity.HasValue)
            {
                asset.Quantity = request.Quantity.Value;
            }

            if (request.IsOnline.HasValue)
            {
                asset.IsOnline = request.IsOnline.Value;
            }

            if (request.Damage.HasValue)
            {
                asset.Damage = request.Damage.Value;
            }

            asset.UpdatedAt = DateTime.UtcNow;

            // Log the update
            await LogAssetActionAsync(assetId, actorId, "UPDATE", oldLocationId, asset.LocationId, oldQuantity, asset.Quantity);

            await _context.SaveChangesAsync();

            return MapToAssetDto(asset);
        }

        public async Task<bool> DeleteAssetAsync(Guid assetId, Guid actorId)
        {
            var asset = await _context.Assets.FindAsync(assetId);
            if (asset == null)
            {
                return false;
            }

            // Log the deletion
            await LogAssetActionAsync(assetId, actorId, "DELETE", asset.LocationId, null, asset.Quantity, null);

            _context.Assets.Remove(asset);
            await _context.SaveChangesAsync();

            return true;
        }

        public async Task<bool> MoveAssetAsync(MoveAssetRequest request, Guid actorId)
        {
            var asset = await _context.Assets
                .Include(a => a.ItemType)
                .FirstOrDefaultAsync(a => a.AssetId == request.AssetId);

            if (asset == null)
            {
                return false;
            }

            // Check if it can fit in target container
            var canFit = await CanFitInContainerAsync(request.TargetLocationId, asset.TypeId, asset.Quantity);
            if (!canFit)
            {
                throw new InvalidOperationException("Not enough space in target container");
            }

            var oldLocationId = asset.LocationId;
            asset.LocationId = request.TargetLocationId;

            if (request.TargetFlag.HasValue)
            {
                asset.LocationFlag = request.TargetFlag.Value;
            }

            asset.UpdatedAt = DateTime.UtcNow;

            // Log the move
            await LogAssetActionAsync(request.AssetId, actorId, "MOVE", oldLocationId, request.TargetLocationId, null, null, request.Reason);

            await _context.SaveChangesAsync();

            return true;
        }

        public async Task<bool> StackAssetsAsync(Guid targetAssetId, Guid sourceAssetId, Guid actorId)
        {
            var targetAsset = await _context.Assets.FindAsync(targetAssetId);
            var sourceAsset = await _context.Assets.FindAsync(sourceAssetId);

            if (targetAsset == null || sourceAsset == null)
            {
                return false;
            }

            // Verify they are the same type and stackable
            if (targetAsset.TypeId != sourceAsset.TypeId || targetAsset.IsSingleton || sourceAsset.IsSingleton)
            {
                throw new InvalidOperationException("Assets cannot be stacked");
            }

            targetAsset.Quantity += sourceAsset.Quantity;
            targetAsset.UpdatedAt = DateTime.UtcNow;

            // Log the stack
            await LogAssetActionAsync(targetAssetId, actorId, "STACK", null, null, targetAsset.Quantity - sourceAsset.Quantity, targetAsset.Quantity);

            _context.Assets.Remove(sourceAsset);
            await _context.SaveChangesAsync();

            return true;
        }

        public async Task<decimal> CalculateContainerUsedVolumeAsync(Guid containerId)
        {
            var totalVolume = await _context.Assets
                .Where(a => a.LocationId == containerId)
                .Include(a => a.ItemType)
                .SumAsync(a => a.ItemType.BaseVolume * a.Quantity);

            return totalVolume;
        }

        public async Task<bool> CanFitInContainerAsync(Guid containerId, int typeId, long quantity)
        {
            var container = await _context.Containers.FindAsync(containerId);
            if (container == null || container.MaxVolume == null)
            {
                return true; // Unlimited space (e.g., station hangar)
            }

            var itemType = await _context.ItemTypesInventory.FindAsync(typeId);
            if (itemType == null)
            {
                return false;
            }

            var requiredVolume = itemType.BaseVolume * quantity;
            var availableVolume = container.MaxVolume.Value - container.UsedVolume;

            return requiredVolume <= availableVolume;
        }

        private async Task LogAssetActionAsync(
            Guid assetId,
            Guid actorId,
            string actionType,
            Guid? oldLocationId,
            Guid? newLocationId,
            long? oldQuantity,
            long? newQuantity,
            string? reason = null)
        {
            var log = new AssetLog
            {
                AssetId = assetId,
                ActorId = actorId,
                ActionType = actionType,
                OldLocationId = oldLocationId,
                NewLocationId = newLocationId,
                OldQuantity = oldQuantity,
                NewQuantity = newQuantity,
                Reason = reason
            };

            _context.AssetLogs.Add(log);
        }

        private static AssetDto MapToAssetDto(Asset asset, ItemTypeEntity? itemType = null)
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
    }
}
