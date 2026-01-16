namespace Echoes.API.Models.DTOs.Game
{
    public class NearbySystemDto
    {
        public Guid Id { get; set; }
        public string Name { get; set; } = string.Empty;
        public int DistanceInJumps { get; set; }
        public float SecurityStatus { get; set; }
        public bool HasStations { get; set; }
        public bool HasAsteroidBelts { get; set; }
    }

    public class CentralSystemDto
    {
        public Guid Id { get; set; }
        public string Name { get; set; } = string.Empty;
        public float SecurityStatus { get; set; }
    }

    public class NearbySystemsResponse
    {
        public bool Success { get; set; }
        public CentralSystemDto CentralSystem { get; set; } = new();
        public IEnumerable<NearbySystemDto> NearbySystems { get; set; } = new List<NearbySystemDto>();
        public int MaxJumps { get; set; }
        public int TotalNearby { get; set; }
        public DateTime Timestamp { get; set; }
    }
}
