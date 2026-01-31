using Echoes.API.Models.DTOs.Inventory;
using Echoes.API.Models.Entities.Inventory;

namespace Echoes.API.Services.Inventory
{
    public interface IInventoryService
    {
        // Asset operations
        Task<AssetDto?> GetAssetAsync(Guid assetId);
        Task<AssetListResponse> GetAssetsInContainerAsync(Guid containerId, int? locationFlag = null);
        Task<AssetListResponse> GetAssetsByOwnerAsync(Guid ownerId);
        Task<AssetDto> CreateAssetAsync(CreateAssetRequest request, Guid actorId);
        Task<AssetDto> UpdateAssetAsync(Guid assetId, UpdateAssetRequest request, Guid actorId);
        Task<bool> DeleteAssetAsync(Guid assetId, Guid actorId);
        Task<bool> MoveAssetAsync(MoveAssetRequest request, Guid actorId);
        Task<bool> StackAssetsAsync(Guid targetAssetId, Guid sourceAssetId, Guid actorId);

        // Volume calculations
        Task<decimal> CalculateContainerUsedVolumeAsync(Guid containerId);
        Task<bool> CanFitInContainerAsync(Guid containerId, int typeId, long quantity);

        // Hangar operations
        Task<ContainerDto> GetOrCreatePersonalHangarAsync(Guid ownerId, int stationId);
    }
}
