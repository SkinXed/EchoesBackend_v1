namespace Echoes.API.Models.DTOs.Game
{
    public class RegionSystemDto
    {
        public Guid Id { get; set; }
        public string Name { get; set; } = string.Empty;
        public float SecurityStatus { get; set; }
        public long PositionX { get; set; }
        public long PositionY { get; set; }
        public long PositionZ { get; set; }
        public List<PlanetOverviewDto> Planets { get; set; } = new();
        public List<StargateOverviewDto> Stargates { get; set; } = new();
    }

    public class StargateOverviewDto
    {
        public Guid Id { get; set; }
        public string Name { get; set; } = string.Empty;
        public Guid DestinationSystemId { get; set; }
        public PositionDto Position { get; set; } = new();
        public string TargetSystemName { get; set; } = string.Empty;
    }

    public class RegionSystemsResponse
    {
        public bool Success { get; set; }
        public Guid RegionId { get; set; }
        public List<RegionSystemDto> Systems { get; set; } = new();
        public int TotalSystems { get; set; }
        public DateTime Timestamp { get; set; }
    }
}
