using Echoes.API.Data;
using EchoesBackend_v1.Models.DTOs;
using EchoesBackend_v1.Models.Entities.Session;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Configuration;

namespace EchoesBackend_v1.Controllers;

/// <summary>
/// Manages player sessions including combat status and connection tracking
/// </summary>
[ApiController]
[Route("api/[controller]")]
public class SessionController : ControllerBase
{
    private readonly DatabaseContext _context;
    private readonly IConfiguration _configuration;
    private readonly ILogger<SessionController> _logger;

    public SessionController(
        DatabaseContext context,
        IConfiguration configuration,
        ILogger<SessionController> logger)
    {
        _context = context;
        _configuration = configuration;
        _logger = logger;
    }

    /// <summary>
    /// Start a new player session
    /// </summary>
    [HttpPost("connect")]
    public async Task<ActionResult<StartSessionResponse>> StartSession([FromBody] StartSessionRequest request)
    {
        // Validate X-Server-Secret
        if (!ValidateServerSecret())
        {
            _logger.LogWarning("Unauthorized session start attempt");
            return Unauthorized(new StartSessionResponse
            {
                Success = false,
                Message = "Unauthorized: Invalid server secret"
            });
        }

        try
        {
            // Check if character exists
            var characterExists = await _context.Characters.AnyAsync(c => c.Id == request.CharacterId);
            if (!characterExists)
            {
                return NotFound(new StartSessionResponse
                {
                    Success = false,
                    Message = "Character not found"
                });
            }

            // Check if system exists (if provided)
            if (request.CurrentSystemId != Guid.Empty)
            {
                var systemExists = await _context.SolarSystems.AnyAsync(s => s.Id == request.CurrentSystemId);
                if (!systemExists)
                {
                    return NotFound(new StartSessionResponse
                    {
                        Success = false,
                        Message = "Solar system not found"
                    });
                }
            }

            // Check for existing active session
            var existingSession = await _context.PlayerSessions
                .Where(s => s.CharacterId == request.CharacterId && s.IsActive)
                .FirstOrDefaultAsync();

            if (existingSession != null)
            {
                // Check if session is timed out
                if (existingSession.IsTimedOut())
                {
                    _logger.LogInformation(
                        "Cleaning up timed out session {SessionId} for character {CharacterId}",
                        existingSession.SessionId, request.CharacterId);
                    
                    existingSession.EndSession();
                }
                else
                {
                    _logger.LogWarning(
                        "Character {CharacterId} already has active session {SessionId} on server {ServerAddress}",
                        request.CharacterId, existingSession.SessionId, existingSession.ServerAddress);

                    return Conflict(new StartSessionResponse
                    {
                        Success = false,
                        Message = "Character already has an active session",
                        ExistingSession = new ExistingSessionInfo
                        {
                            SessionId = existingSession.SessionId,
                            ServerAddress = existingSession.ServerAddress,
                            ConnectedAt = existingSession.ConnectedAt,
                            LastHeartbeat = existingSession.LastHeartbeat,
                            IsTimedOut = existingSession.IsTimedOut()
                        }
                    });
                }
            }

            // Create new session
            var newSession = new PlayerSession
            {
                SessionId = Guid.NewGuid(),
                CharacterId = request.CharacterId,
                CurrentSystemId = request.CurrentSystemId,
                ServerAddress = request.ServerAddress,
                ConnectedAt = DateTime.UtcNow,
                LastHeartbeat = DateTime.UtcNow,
                IsActive = true,
                Metadata = request.Metadata
            };

            _context.PlayerSessions.Add(newSession);
            await _context.SaveChangesAsync();

            _logger.LogInformation(
                "Started session {SessionId} for character {CharacterId} on server {ServerAddress}",
                newSession.SessionId, request.CharacterId, request.ServerAddress);

            return Ok(new StartSessionResponse
            {
                Success = true,
                Message = "Session started successfully",
                SessionId = newSession.SessionId,
                ConnectedAt = newSession.ConnectedAt
            });
        }
        catch (Exception ex)
        {
            _logger.LogError(ex, "Error starting session for character {CharacterId}", request.CharacterId);
            return StatusCode(500, new StartSessionResponse
            {
                Success = false,
                Message = "Internal server error"
            });
        }
    }

    /// <summary>
    /// Update session heartbeat
    /// </summary>
    [HttpPut("{sessionId}/heartbeat")]
    public async Task<ActionResult<HeartbeatResponse>> UpdateHeartbeat(
        Guid sessionId,
        [FromBody] HeartbeatRequest request)
    {
        // Validate X-Server-Secret
        if (!ValidateServerSecret())
        {
            return Unauthorized();
        }

        try
        {
            var session = await _context.PlayerSessions.FindAsync(sessionId);
            if (session == null)
            {
                return NotFound(new HeartbeatResponse
                {
                    Success = false,
                    Message = "Session not found"
                });
            }

            if (!session.IsActive)
            {
                return BadRequest(new HeartbeatResponse
                {
                    Success = false,
                    Message = "Session is not active"
                });
            }

            // Update heartbeat
            session.UpdateHeartbeat();

            // Update system if provided
            if (request.CurrentSystemId.HasValue)
            {
                session.CurrentSystemId = request.CurrentSystemId.Value;
            }

            await _context.SaveChangesAsync();

            return Ok(new HeartbeatResponse
            {
                Success = true,
                Message = "Heartbeat updated",
                LastHeartbeat = session.LastHeartbeat,
                IsInCombat = session.IsInCombat(),
                HasAggression = session.HasAggression(),
                CombatUntil = session.CombatUntil,
                AggressionUntil = session.AggressionUntil
            });
        }
        catch (Exception ex)
        {
            _logger.LogError(ex, "Error updating heartbeat for session {SessionId}", sessionId);
            return StatusCode(500, new HeartbeatResponse
            {
                Success = false,
                Message = "Internal server error"
            });
        }
    }

    /// <summary>
    /// Enter combat state
    /// </summary>
    [HttpPost("{sessionId}/combat")]
    public async Task<ActionResult<EnterCombatResponse>> EnterCombat(
        Guid sessionId,
        [FromBody] EnterCombatRequest request)
    {
        // Validate X-Server-Secret
        if (!ValidateServerSecret())
        {
            return Unauthorized();
        }

        try
        {
            var session = await _context.PlayerSessions.FindAsync(sessionId);
            if (session == null)
            {
                return NotFound(new EnterCombatResponse
                {
                    Success = false,
                    Message = "Session not found"
                });
            }

            if (!session.IsActive)
            {
                return BadRequest(new EnterCombatResponse
                {
                    Success = false,
                    Message = "Session is not active"
                });
            }

            // Enter combat
            session.EnterCombat(request.DurationSeconds);

            // Set aggression if requested
            if (request.SetAggression)
            {
                session.SetAggression(request.AggressionDurationSeconds);
            }

            await _context.SaveChangesAsync();

            _logger.LogInformation(
                "Session {SessionId} entered combat until {CombatUntil}",
                sessionId, session.CombatUntil);

            return Ok(new EnterCombatResponse
            {
                Success = true,
                Message = "Entered combat state",
                CombatUntil = session.CombatUntil!.Value,
                AggressionUntil = session.AggressionUntil
            });
        }
        catch (Exception ex)
        {
            _logger.LogError(ex, "Error entering combat for session {SessionId}", sessionId);
            return StatusCode(500, new EnterCombatResponse
            {
                Success = false,
                Message = "Internal server error",
                CombatUntil = DateTime.UtcNow
            });
        }
    }

    /// <summary>
    /// End a player session
    /// </summary>
    [HttpDelete("{sessionId}")]
    public async Task<ActionResult<EndSessionResponse>> EndSession(Guid sessionId)
    {
        // Validate X-Server-Secret
        if (!ValidateServerSecret())
        {
            return Unauthorized();
        }

        try
        {
            var session = await _context.PlayerSessions.FindAsync(sessionId);
            if (session == null)
            {
                return NotFound(new EndSessionResponse
                {
                    Success = false,
                    Message = "Session not found"
                });
            }

            var sessionDuration = DateTime.UtcNow - session.ConnectedAt;
            
            session.EndSession();
            await _context.SaveChangesAsync();

            _logger.LogInformation(
                "Ended session {SessionId} for character {CharacterId}. Duration: {Duration}",
                sessionId, session.CharacterId, sessionDuration);

            return Ok(new EndSessionResponse
            {
                Success = true,
                Message = "Session ended successfully",
                DisconnectedAt = session.DisconnectedAt,
                SessionDuration = sessionDuration
            });
        }
        catch (Exception ex)
        {
            _logger.LogError(ex, "Error ending session {SessionId}", sessionId);
            return StatusCode(500, new EndSessionResponse
            {
                Success = false,
                Message = "Internal server error"
            });
        }
    }

    /// <summary>
    /// Get session status for a character
    /// </summary>
    [HttpGet("character/{characterId}")]
    public async Task<ActionResult<SessionStatusResponse>> GetCharacterSession(Guid characterId)
    {
        // Validate X-Server-Secret
        if (!ValidateServerSecret())
        {
            return Unauthorized();
        }

        try
        {
            var session = await _context.PlayerSessions
                .Where(s => s.CharacterId == characterId && s.IsActive)
                .FirstOrDefaultAsync();

            if (session == null)
            {
                return Ok(new SessionStatusResponse
                {
                    HasActiveSession = false
                });
            }

            var sessionDuration = DateTime.UtcNow - session.ConnectedAt;

            return Ok(new SessionStatusResponse
            {
                HasActiveSession = true,
                SessionId = session.SessionId,
                CharacterId = session.CharacterId,
                CurrentSystemId = session.CurrentSystemId,
                ServerAddress = session.ServerAddress,
                ConnectedAt = session.ConnectedAt,
                LastHeartbeat = session.LastHeartbeat,
                IsActive = session.IsActive,
                IsInCombat = session.IsInCombat(),
                HasAggression = session.HasAggression(),
                CombatUntil = session.CombatUntil,
                AggressionUntil = session.AggressionUntil,
                IsTimedOut = session.IsTimedOut(),
                SessionDuration = sessionDuration
            });
        }
        catch (Exception ex)
        {
            _logger.LogError(ex, "Error getting session for character {CharacterId}", characterId);
            return StatusCode(500, new SessionStatusResponse
            {
                HasActiveSession = false
            });
        }
    }

    /// <summary>
    /// Validate X-Server-Secret header
    /// </summary>
    private bool ValidateServerSecret()
    {
        var headerSecret = Request.Headers["X-Server-Secret"].FirstOrDefault();
        var configSecret = _configuration["Server:Secret"];

        if (string.IsNullOrEmpty(headerSecret) || string.IsNullOrEmpty(configSecret))
        {
            return false;
        }

        return headerSecret == configSecret;
    }
}
