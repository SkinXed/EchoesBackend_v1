namespace Echoes.API.Models.DTOs.Inventory
{
    public class ContainerDto
    {
        public Guid ContainerId { get; set; }
        public Guid? ParentContainerId { get; set; }
        public Guid OwnerId { get; set; }
        public string ContainerType { get; set; } = string.Empty;
        public string? Name { get; set; }
        public decimal? MaxVolume { get; set; }
        public decimal UsedVolume { get; set; }
        public decimal? AvailableVolume => MaxVolume.HasValue ? MaxVolume.Value - UsedVolume : null;
        public bool IsAccessible { get; set; }
        public int AccessLevel { get; set; }
        public DateTime CreatedAt { get; set; }
    }

    public class CreateContainerRequest
    {
        public Guid OwnerId { get; set; }
        public string ContainerType { get; set; } = string.Empty;
        public string? Name { get; set; }
        public decimal? MaxVolume { get; set; }
        public Guid? ParentContainerId { get; set; }
        public int? SolarSystemId { get; set; }
        public int? StationId { get; set; }
    }

    public class UpdateContainerRequest
    {
        public string? Name { get; set; }
        public bool? IsAccessible { get; set; }
        public int? AccessLevel { get; set; }
    }

    public class ContainerContentsDto
    {
        public ContainerDto Container { get; set; } = null!;
        public List<AssetDto> Assets { get; set; } = new();
        public List<ContainerDto> ChildContainers { get; set; } = new();
    }
}
