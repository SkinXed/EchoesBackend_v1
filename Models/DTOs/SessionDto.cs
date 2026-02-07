using System.ComponentModel.DataAnnotations;

namespace EchoesBackend_v1.Models.DTOs;

/// <summary>
/// Request to start a new player session
/// </summary>
public class StartSessionRequest
{
    [Required]
    public Guid CharacterId { get; set; }

    [Required]
    public Guid CurrentSystemId { get; set; }

    [Required]
    [MaxLength(100)]
    public string ServerAddress { get; set; } = string.Empty;

    /// <summary>
    /// Optional metadata about the connection
    /// </summary>
    public string? Metadata { get; set; }
}

/// <summary>
/// Response after starting a session
/// </summary>
public class StartSessionResponse
{
    public bool Success { get; set; }
    public string Message { get; set; } = string.Empty;
    public Guid? SessionId { get; set; }
    public DateTime? ConnectedAt { get; set; }

    /// <summary>
    /// If there was an existing active session, its details
    /// </summary>
    public ExistingSessionInfo? ExistingSession { get; set; }
}

/// <summary>
/// Information about an existing session (for conflict resolution)
/// </summary>
public class ExistingSessionInfo
{
    public Guid SessionId { get; set; }
    public string ServerAddress { get; set; } = string.Empty;
    public DateTime ConnectedAt { get; set; }
    public DateTime LastHeartbeat { get; set; }
    public bool IsTimedOut { get; set; }
}

/// <summary>
/// Request to update session heartbeat
/// </summary>
public class HeartbeatRequest
{
    public Guid? CurrentSystemId { get; set; }
}

/// <summary>
/// Response after heartbeat update
/// </summary>
public class HeartbeatResponse
{
    public bool Success { get; set; }
    public string Message { get; set; } = string.Empty;
    public DateTime LastHeartbeat { get; set; }
    public bool IsInCombat { get; set; }
    public bool HasAggression { get; set; }
    public DateTime? CombatUntil { get; set; }
    public DateTime? AggressionUntil { get; set; }
}

/// <summary>
/// Request to enter combat state
/// </summary>
public class EnterCombatRequest
{
    /// <summary>
    /// Combat duration in seconds (default: 60)
    /// </summary>
    [Range(1, 3600)]
    public int DurationSeconds { get; set; } = 60;

    /// <summary>
    /// Whether to also set aggression flag
    /// </summary>
    public bool SetAggression { get; set; } = false;

    /// <summary>
    /// Aggression duration in seconds (default: 900 = 15 minutes)
    /// </summary>
    [Range(1, 3600)]
    public int AggressionDurationSeconds { get; set; } = 900;
}

/// <summary>
/// Response after entering combat
/// </summary>
public class EnterCombatResponse
{
    public bool Success { get; set; }
    public string Message { get; set; } = string.Empty;
    public DateTime CombatUntil { get; set; }
    public DateTime? AggressionUntil { get; set; }
}

/// <summary>
/// Response after ending a session
/// </summary>
public class EndSessionResponse
{
    public bool Success { get; set; }
    public string Message { get; set; } = string.Empty;
    public DateTime? DisconnectedAt { get; set; }
    public TimeSpan? SessionDuration { get; set; }
}

/// <summary>
/// Session status information
/// </summary>
public class SessionStatusResponse
{
    public bool HasActiveSession { get; set; }
    public Guid? SessionId { get; set; }
    public Guid? CharacterId { get; set; }
    public Guid? CurrentSystemId { get; set; }
    public string? ServerAddress { get; set; }
    public DateTime? ConnectedAt { get; set; }
    public DateTime? LastHeartbeat { get; set; }
    public bool IsActive { get; set; }
    public bool IsInCombat { get; set; }
    public bool HasAggression { get; set; }
    public DateTime? CombatUntil { get; set; }
    public DateTime? AggressionUntil { get; set; }
    public bool IsTimedOut { get; set; }
    public TimeSpan? SessionDuration { get; set; }
}
