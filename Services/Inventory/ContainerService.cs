using Echoes.API.Data;
using Echoes.API.Models.DTOs.Inventory;
using Echoes.API.Models.Entities.Inventory;
using Microsoft.EntityFrameworkCore;

namespace Echoes.API.Services.Inventory
{
    public class ContainerService : IContainerService
    {
        private readonly DatabaseContext _context;
        private readonly ILogger<ContainerService> _logger;

        public ContainerService(DatabaseContext context, ILogger<ContainerService> logger)
        {
            _context = context;
            _logger = logger;
        }

        public async Task<ContainerDto?> GetContainerAsync(Guid containerId)
        {
            var container = await _context.Containers.FindAsync(containerId);
            return container == null ? null : MapToContainerDto(container);
        }

        public async Task<ContainerContentsDto?> GetContainerContentsAsync(Guid containerId)
        {
            var container = await _context.Containers.FindAsync(containerId);
            if (container == null)
            {
                return null;
            }

            var assets = await _context.Assets
                .Include(a => a.ItemType)
                .Where(a => a.LocationId == containerId)
                .ToListAsync();

            var childContainers = await _context.Containers
                .Where(c => c.ParentContainerId == containerId)
                .ToListAsync();

            return new ContainerContentsDto
            {
                Container = MapToContainerDto(container),
                Assets = assets.Select(a => new AssetDto
                {
                    AssetId = a.AssetId,
                    TypeId = a.TypeId,
                    TypeName = a.ItemType?.Name,
                    OwnerId = a.OwnerId,
                    LocationId = a.LocationId,
                    LocationFlag = a.LocationFlag,
                    Quantity = a.Quantity,
                    IsSingleton = a.IsSingleton,
                    IsOnline = a.IsOnline,
                    IsBpc = a.IsBpc,
                    Damage = a.Damage,
                    CreatedAt = a.CreatedAt,
                    UpdatedAt = a.UpdatedAt
                }).ToList(),
                ChildContainers = childContainers.Select(MapToContainerDto).ToList()
            };
        }

        public async Task<List<ContainerDto>> GetContainersByOwnerAsync(Guid ownerId)
        {
            var containers = await _context.Containers
                .Where(c => c.OwnerId == ownerId)
                .ToListAsync();

            return containers.Select(MapToContainerDto).ToList();
        }

        public async Task<ContainerDto> CreateContainerAsync(CreateContainerRequest request)
        {
            var container = new Container
            {
                OwnerId = request.OwnerId,
                ContainerType = request.ContainerType,
                Name = request.Name,
                MaxVolume = request.MaxVolume,
                ParentContainerId = request.ParentContainerId,
                SolarSystemId = request.SolarSystemId,
                StationId = request.StationId
            };

            _context.Containers.Add(container);
            await _context.SaveChangesAsync();

            return MapToContainerDto(container);
        }

        public async Task<ContainerDto> UpdateContainerAsync(Guid containerId, UpdateContainerRequest request)
        {
            var container = await _context.Containers.FindAsync(containerId);
            if (container == null)
            {
                throw new InvalidOperationException($"Container {containerId} not found");
            }

            if (request.Name != null)
            {
                container.Name = request.Name;
            }

            if (request.IsAccessible.HasValue)
            {
                container.IsAccessible = request.IsAccessible.Value;
            }

            if (request.AccessLevel.HasValue)
            {
                container.AccessLevel = request.AccessLevel.Value;
            }

            container.UpdatedAt = DateTime.UtcNow;

            await _context.SaveChangesAsync();

            return MapToContainerDto(container);
        }

        public async Task<bool> DeleteContainerAsync(Guid containerId)
        {
            var container = await _context.Containers.FindAsync(containerId);
            if (container == null)
            {
                return false;
            }

            // Check if container is empty
            var hasAssets = await _context.Assets.AnyAsync(a => a.LocationId == containerId);
            if (hasAssets)
            {
                throw new InvalidOperationException("Cannot delete non-empty container");
            }

            _context.Containers.Remove(container);
            await _context.SaveChangesAsync();

            return true;
        }

        private static ContainerDto MapToContainerDto(Container container)
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
