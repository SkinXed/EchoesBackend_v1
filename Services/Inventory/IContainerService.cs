using Echoes.API.Models.DTOs.Inventory;

namespace Echoes.API.Services.Inventory
{
    public interface IContainerService
    {
        Task<ContainerDto?> GetContainerAsync(Guid containerId);
        Task<ContainerContentsDto?> GetContainerContentsAsync(Guid containerId);
        Task<List<ContainerDto>> GetContainersByOwnerAsync(Guid ownerId);
        Task<ContainerDto> CreateContainerAsync(CreateContainerRequest request);
        Task<ContainerDto> UpdateContainerAsync(Guid containerId, UpdateContainerRequest request);
        Task<bool> DeleteContainerAsync(Guid containerId);
    }
}
