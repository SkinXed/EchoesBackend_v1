namespace Echoes.API.Models.DTOs.Game
{
    public class SystemOverviewDto
    {
        public Guid Id { get; set; }
        public string Name { get; set; } = string.Empty;
        public float Security { get; set; }
        public string Constellation { get; set; } = string.Empty;
        public string Region { get; set; } = string.Empty;
        public long PositionX { get; set; }
        public long PositionY { get; set; }
        public long PositionZ { get; set; }
        public int PlanetCount { get; set; }
        public bool HasStations { get; set; }
        public bool HasAsteroidBelts { get; set; }
    }

    public class PaginatedResponse<T>
    {
        public List<T> Items { get; set; } = new();
        public int Page { get; set; }
        public int PageSize { get; set; }
        public int TotalCount { get; set; }
        public int TotalPages { get; set; }
        public DateTime Timestamp { get; set; }
    }

    public class SystemDetailDto
    {
        public Guid Id { get; set; }
        public string Name { get; set; } = string.Empty;
        public float SecurityStatus { get; set; }
        public string? Description { get; set; }
        public ConstellationDto Constellation { get; set; } = new();
        public RegionDto Region { get; set; } = new();
        public StarInfoDto StarInfo { get; set; } = new();
        public PositionDto Position { get; set; } = new();
        public List<PlanetOverviewDto> Planets { get; set; } = new();
        public List<StationOverviewDto> Stations { get; set; } = new();
        public List<StargateDto> Stargates { get; set; } = new();
    }

    public class ConstellationDto
    {
        public Guid Id { get; set; }
        public string Name { get; set; } = string.Empty;
    }

    public class RegionDto
    {
        public Guid Id { get; set; }
        public string Name { get; set; } = string.Empty;
        public string Type { get; set; } = string.Empty;
    }

    public class StarInfoDto
    {
        public string StarClass { get; set; } = string.Empty;
        public string LuminosityClass { get; set; } = string.Empty;
        public double Temperature { get; set; }
        public double SolarRadius { get; set; }
        public double SolarMass { get; set; }
        public double Luminosity { get; set; }
    }

    public class PositionDto
    {
        public long X { get; set; }
        public long Y { get; set; }
        public long Z { get; set; }
    }

    public class PlanetOverviewDto
    {
        public Guid Id { get; set; }
        public string Name { get; set; } = string.Empty;
        public string Type { get; set; } = string.Empty;
        public double Radius { get; set; }
        public long OrbitDistance { get; set; }
        public PositionDto Position { get; set; } = new();
    }

    public class StationOverviewDto
    {
        public Guid Id { get; set; }
        public string Name { get; set; } = string.Empty;
        public string Type { get; set; } = string.Empty;
        public int DockingCapacity { get; set; }
        public List<string> Services { get; set; } = new();
    }

    public class StargateDto
    {
        public Guid Id { get; set; }
        public string Name { get; set; } = string.Empty;
        public PositionDto Position { get; set; } = new();
        public StargateDestinationDto? DestinationSystem { get; set; }
        public bool IsOperational { get; set; }
        public double JumpCost { get; set; }
    }

    public class StargateDestinationDto
    {
        public Guid Id { get; set; }
        public string Name { get; set; } = string.Empty;
    }

    public class SystemDetailResponse
    {
        public bool Success { get; set; }
        public SystemDetailDto System { get; set; } = new();
        public SystemObjectCountsDto ObjectCounts { get; set; } = new();
        public DateTime Timestamp { get; set; }
    }

    public class SystemObjectCountsDto
    {
        public int Planets { get; set; }
        public int Stations { get; set; }
        public int Stargates { get; set; }
    }
}
