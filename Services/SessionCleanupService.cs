using Echoes.API.Data;
using Microsoft.EntityFrameworkCore;

namespace EchoesBackend_v1.Services;

/// <summary>
/// Background service that cleans up timed-out player sessions
/// Runs every 2 minutes to mark sessions as inactive if no heartbeat received
/// </summary>
public class SessionCleanupService : BackgroundService
{
    private readonly IServiceProvider _serviceProvider;
    private readonly ILogger<SessionCleanupService> _logger;
    private readonly TimeSpan _cleanupInterval = TimeSpan.FromMinutes(2);
    private readonly TimeSpan _sessionTimeout = TimeSpan.FromMinutes(2);

    public SessionCleanupService(
        IServiceProvider serviceProvider,
        ILogger<SessionCleanupService> logger)
    {
        _serviceProvider = serviceProvider;
        _logger = logger;
    }

    protected override async Task ExecuteAsync(CancellationToken stoppingToken)
    {
        _logger.LogInformation("Session Cleanup Service started");

        while (!stoppingToken.IsCancellationRequested)
        {
            try
            {
                await CleanupTimedOutSessions(stoppingToken);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error in session cleanup service");
            }

            await Task.Delay(_cleanupInterval, stoppingToken);
        }

        _logger.LogInformation("Session Cleanup Service stopped");
    }

    private async Task CleanupTimedOutSessions(CancellationToken cancellationToken)
    {
        using var scope = _serviceProvider.CreateScope();
        var context = scope.ServiceProvider.GetRequiredService<DatabaseContext>();

        var timeoutThreshold = DateTime.UtcNow.Add(-_sessionTimeout);

        // Find all active sessions with stale heartbeats
        var timedOutSessions = await context.PlayerSessions
            .Where(s => s.IsActive && s.LastHeartbeat < timeoutThreshold)
            .ToListAsync(cancellationToken);

        if (timedOutSessions.Any())
        {
            _logger.LogInformation(
                "Found {Count} timed-out sessions to clean up",
                timedOutSessions.Count);

            foreach (var session in timedOutSessions)
            {
                session.EndSession();
                _logger.LogInformation(
                    "Cleaned up session {SessionId} for character {CharacterId} (last heartbeat: {LastHeartbeat})",
                    session.SessionId, session.CharacterId, session.LastHeartbeat);
            }

            await context.SaveChangesAsync(cancellationToken);
        }

        // Also clean up very old inactive sessions (older than 7 days)
        var oldSessionThreshold = DateTime.UtcNow.AddDays(-7);
        var oldSessions = await context.PlayerSessions
            .Where(s => !s.IsActive && s.DisconnectedAt < oldSessionThreshold)
            .ToListAsync(cancellationToken);

        if (oldSessions.Any())
        {
            _logger.LogInformation(
                "Removing {Count} old inactive sessions",
                oldSessions.Count);

            context.PlayerSessions.RemoveRange(oldSessions);
            await context.SaveChangesAsync(cancellationToken);
        }
    }
}
