namespace Echoes.API.Models.DTOs.Game
{
    public class SearchResultDto
    {
        public Guid Id { get; set; }
        public string Name { get; set; } = string.Empty;
        public string Type { get; set; } = string.Empty;
        public float? SecurityStatus { get; set; }
        public string? Region { get; set; }
        public string? Constellation { get; set; }
        public string? ParentSystem { get; set; }
    }

    public class SearchResponse
    {
        public bool Success { get; set; }
        public string Query { get; set; } = string.Empty;
        public List<SearchResultDto> Results { get; set; } = new();
        public int TotalResults { get; set; }
        public DateTime Timestamp { get; set; }
    }
}
