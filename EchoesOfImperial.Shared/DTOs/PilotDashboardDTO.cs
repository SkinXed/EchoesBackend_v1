namespace EchoesOfImperial.Shared.DTOs;

public class PilotDashboardDTO
{
    public Guid PilotId { get; set; }
    public string PilotName { get; set; } = string.Empty;
    public string CorpName { get; set; } = "Freelancer"; // Default
    public long Credits { get; set; } // Currency (long for large numbers like in EVE)
    public string CurrentSystem { get; set; } = "Jita"; // Example
    public string CurrentShip { get; set; } = "Ibis";
}
