// Создать новый файл в Entities/Universe/:
public class UniverseMetadata
{
    public Guid Id { get; set; }
    public string Seed { get; set; }
    public int SeedVersion { get; set; }
    public string GeneratorVersion { get; set; }
    public DateTime GeneratedAt { get; set; }
    public string ConfigSnapshot { get; set; }
    public string DataHash { get; set; }
    public UniverseGenerationStatus Status { get; set; }
}

public enum UniverseGenerationStatus
{
    Generating,
    Completed,
    Failed
}