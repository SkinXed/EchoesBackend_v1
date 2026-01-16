using Echoes.API.Models.Entities.Universe;

namespace Echoes.API.Models.DTOs.Game
{
    public class GenerationResponse
    {
        public bool Success { get; set; }
        public string Message { get; set; } = string.Empty;
        public Guid? GenerationId { get; set; }
        public bool? ForceRegeneration { get; set; }
        public bool? ClearExisting { get; set; }
        public UniverseStats? Stats { get; set; }
        public DateTime Timestamp { get; set; }
    }

    public class GenerationStatusDto
    {
        public Guid Id { get; set; }
        public string Status { get; set; } = string.Empty;
        public string? Message { get; set; }
        public int? Progress { get; set; }
        public DateTime StartedAt { get; set; }
        public DateTime? CompletedAt { get; set; }
        public UniverseStats? Stats { get; set; }
    }

    public class GenerationStatusResponse
    {
        public bool Success { get; set; }
        public GenerationStatusDto Status { get; set; } = new();
        public DateTime Timestamp { get; set; }
    }

    public class UniverseStatsResponse
    {
        public bool Success { get; set; }
        public UniverseStats Stats { get; set; } = new();
        public DateTime Timestamp { get; set; }
    }
}
