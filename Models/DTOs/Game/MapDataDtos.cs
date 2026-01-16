namespace Echoes.API.Models.DTOs.Game
{
    public class MapDataDto
    {
        public Guid Id { get; set; }
        public string Name { get; set; } = string.Empty;
        public long X { get; set; }
        public long Y { get; set; }
        public long Z { get; set; }
        public float Security { get; set; }
        public Guid RegionId { get; set; }
        public string RegionName { get; set; } = string.Empty;
        public Guid ConstellationId { get; set; }
        public string ConstellationName { get; set; } = string.Empty;
        public string StarClass { get; set; } = string.Empty;
        public bool HasStations { get; set; }
        public bool HasAsteroidBelts { get; set; }
    }

    public class StargateConnectionDto
    {
        public Guid SourceSystemId { get; set; }
        public Guid DestinationSystemId { get; set; }
        public double JumpCost { get; set; }
    }

    public class MapDataResponse
    {
        public List<MapDataDto> Systems { get; set; } = new();
        public List<StargateConnectionDto> Stargates { get; set; } = new();
        public DateTime GeneratedAt { get; set; }
        public int TotalSystems { get; set; }
    }
}
