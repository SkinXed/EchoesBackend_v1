// Создать новый файл в Entities/Universe/:
public class UniverseMetadata
{
    public Guid Id { get; set; }
    public string Seed { get; set; } = string.Empty;
    public int SeedVersion { get; set; }
    public string GeneratorVersion { get; set; } = string.Empty;
    public DateTime GeneratedAt { get; set; }
    public string ConfigSnapshot { get; set; } = string.Empty;
    public string DataHash { get; set; } = string.Empty;
    public UniverseGenerationStatus Status { get; set; }
}

public enum UniverseGenerationStatus
{
    Generating,
    Completed,
    Failed
}