using Echoes.API.Models.Entities.Character;
using Echoes.API.Models.Entities.Universe;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace EchoesBackend_v1.Models.Entities.Session;

/// <summary>
/// Represents an active player session on a game server.
/// Used for tracking combat status, preventing duplicate logins, and session management.
/// </summary>
[Table("player_sessions")]
public class PlayerSession
{
    /// <summary>
    /// Unique identifier for this session
    /// </summary>
    [Key]
    [Column("session_id")]
    public Guid SessionId { get; set; } = Guid.NewGuid();

    /// <summary>
    /// Character associated with this session
    /// </summary>
    [Required]
    [Column("character_id")]
    public Guid CharacterId { get; set; }

    /// <summary>
    /// Current solar system the character is in
    /// </summary>
    [Column("current_system_id")]
    public Guid? CurrentSystemId { get; set; }

    /// <summary>
    /// Server address (IP:Port) where the session is active
    /// </summary>
    [Required]
    [MaxLength(100)]
    [Column("server_address")]
    public string ServerAddress { get; set; } = string.Empty;

    /// <summary>
    /// When the session was established
    /// </summary>
    [Column("connected_at")]
    public DateTime ConnectedAt { get; set; } = DateTime.UtcNow;

    /// <summary>
    /// Last heartbeat received from server
    /// </summary>
    [Column("last_heartbeat")]
    public DateTime LastHeartbeat { get; set; } = DateTime.UtcNow;

    /// <summary>
    /// Whether the session is currently active
    /// </summary>
    [Column("is_active")]
    public bool IsActive { get; set; } = true;

    /// <summary>
    /// Player remains in combat state until this time
    /// NULL means not in combat
    /// </summary>
    [Column("combat_until")]
    public DateTime? CombatUntil { get; set; }

    /// <summary>
    /// Player has aggression flag until this time
    /// NULL means no aggression
    /// </summary>
    [Column("aggression_until")]
    public DateTime? AggressionUntil { get; set; }

    /// <summary>
    /// When the session ended (for historical tracking)
    /// </summary>
    [Column("disconnected_at")]
    public DateTime? DisconnectedAt { get; set; }

    /// <summary>
    /// Additional metadata (JSON format)
    /// </summary>
    [Column("metadata", TypeName = "jsonb")]
    public string? Metadata { get; set; }

    // Navigation properties
    [ForeignKey(nameof(CharacterId))]
    public virtual Character? Character { get; set; }

    [ForeignKey(nameof(CurrentSystemId))]
    public virtual SolarSystem? CurrentSystem { get; set; }

    /// <summary>
    /// Check if the session is in combat
    /// </summary>
    public bool IsInCombat()
    {
        return CombatUntil.HasValue && CombatUntil.Value > DateTime.UtcNow;
    }

    /// <summary>
    /// Check if the session has aggression
    /// </summary>
    public bool HasAggression()
    {
        return AggressionUntil.HasValue && AggressionUntil.Value > DateTime.UtcNow;
    }

    /// <summary>
    /// Check if the session is timed out (no heartbeat for 2 minutes)
    /// </summary>
    public bool IsTimedOut()
    {
        return (DateTime.UtcNow - LastHeartbeat).TotalMinutes > 2;
    }

    /// <summary>
    /// Enter combat state (typically 60 seconds)
    /// </summary>
    public void EnterCombat(int durationSeconds = 60)
    {
        var newCombatEnd = DateTime.UtcNow.AddSeconds(durationSeconds);
        if (!CombatUntil.HasValue || newCombatEnd > CombatUntil.Value)
        {
            CombatUntil = newCombatEnd;
        }
    }

    /// <summary>
    /// Set aggression flag (typically 15 minutes)
    /// </summary>
    public void SetAggression(int durationSeconds = 900)
    {
        var newAggressionEnd = DateTime.UtcNow.AddSeconds(durationSeconds);
        if (!AggressionUntil.HasValue || newAggressionEnd > AggressionUntil.Value)
        {
            AggressionUntil = newAggressionEnd;
        }
    }

    /// <summary>
    /// Update heartbeat timestamp
    /// </summary>
    public void UpdateHeartbeat()
    {
        LastHeartbeat = DateTime.UtcNow;
    }

    /// <summary>
    /// End the session
    /// </summary>
    public void EndSession()
    {
        IsActive = false;
        DisconnectedAt = DateTime.UtcNow;
    }
}
