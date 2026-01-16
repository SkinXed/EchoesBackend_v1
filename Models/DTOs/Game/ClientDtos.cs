namespace Echoes.API.Models.DTOs.Game
{
    public class ClientSystemDto
    {
        public Guid SystemId { get; set; }
        public string SystemName { get; set; } = string.Empty;
        public double SolarRadius { get; set; }
        public double SolarMass { get; set; }
        public double Temperature { get; set; }
        public float SecurityStatus { get; set; }
        public List<ClientPlanetDto> Planets { get; set; } = new();
        public List<ClientStargateDto> Stargates { get; set; } = new();
    }

    public class ClientPlanetDto
    {
        public Guid Id { get; set; }
        public string Name { get; set; } = string.Empty;
        public string Type { get; set; } = string.Empty;
        public long OrbitDistance { get; set; }
        public double Radius { get; set; }
        public long PositionX { get; set; }
        public long PositionY { get; set; }
        public long PositionZ { get; set; }
    }

    public class ClientStargateDto
    {
        public Guid Id { get; set; }
        public string Name { get; set; } = string.Empty;
        public Guid TargetSystemId { get; set; }
        public string TargetSystemName { get; set; } = string.Empty;
        public long PositionX { get; set; }
        public long PositionY { get; set; }
        public long PositionZ { get; set; }
    }

    public class ClientSystemObjectsResponse
    {
        public bool Success { get; set; }
        public ClientSystemDto System { get; set; } = new();
        public DateTime Timestamp { get; set; }
    }
}
