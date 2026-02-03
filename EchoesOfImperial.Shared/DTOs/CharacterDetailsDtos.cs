using System.ComponentModel.DataAnnotations;

namespace EchoesOfImperial.Shared.DTOs;

/// <summary>
/// Detailed character profile DTO for profile page
/// </summary>
public class CharacterDetailsDto
{
    // Basic Info
    public Guid Id { get; set; }
    public string Name { get; set; } = string.Empty;
    public Guid AccountId { get; set; }
    public DateTime CreatedAt { get; set; }
    public DateTime? LastLogin { get; set; }
    public DateTime? LastLogout { get; set; }
    
    // Status
    public bool IsMain { get; set; }
    public bool IsOnline { get; set; }
    public bool IsDocked { get; set; }
    public bool InWarp { get; set; }
    public float SecurityStatus { get; set; }
    
    // Faction & Corporation
    public int RaceId { get; set; }
    public string RaceName { get; set; } = string.Empty;
    public int BloodlineId { get; set; }
    public int AncestryId { get; set; }
    public Guid? CorporationId { get; set; }
    public string? CorporationName { get; set; }
    public long CorporationRole { get; set; }
    
    // Attributes
    public int Perception { get; set; }
    public int Memory { get; set; }
    public int Willpower { get; set; }
    public int Intelligence { get; set; }
    public int Charisma { get; set; }
    
    // Financial
    public long WalletBalance { get; set; }
    public decimal TotalISKEarned { get; set; }
    public decimal TotalISKLost { get; set; }
    
    // Skills
    public int TotalSkillPoints { get; set; }
    public int UnallocatedSkillPoints { get; set; }
    public DateTime? SkillTrainingEnd { get; set; }
    public string? CurrentTrainingSkill { get; set; }
    
    // Combat Stats
    public int TotalKills { get; set; }
    public int TotalDeaths { get; set; }
    public int TotalShipsDestroyed { get; set; }
    public int TotalShipsLost { get; set; }
    
    // Ship
    public long? ActiveShipItemId { get; set; }
    public string? ActiveShipName { get; set; }
    public string? ActiveShipType { get; set; }
    
    // Clones
    public Guid? ActiveCloneId { get; set; }
    public int JumpCloneCount { get; set; }
    public int MaxJumpClones { get; set; }
    public DateTime CloneExpiration { get; set; }
    
    // Gameplay Stats
    public long TotalPlayTimeSeconds { get; set; }
}
