using Microsoft.EntityFrameworkCore;
using Echoes.API.Data;

namespace Echoes.API.Services
{
    /// <summary>
    /// Background service that periodically cleans up expired world objects
    /// Runs every 5 minutes to remove objects past their ExpirationTime
    /// </summary>
    public class WorldObjectCleanupService : BackgroundService
    {
        private readonly IServiceProvider _serviceProvider;
        private readonly ILogger<WorldObjectCleanupService> _logger;
        private readonly TimeSpan _cleanupInterval = TimeSpan.FromMinutes(5);

        public WorldObjectCleanupService(
            IServiceProvider serviceProvider,
            ILogger<WorldObjectCleanupService> logger)
        {
            _serviceProvider = serviceProvider;
            _logger = logger;
        }

        protected override async Task ExecuteAsync(CancellationToken stoppingToken)
        {
            _logger.LogInformation("WorldObjectCleanupService started");

            // Wait a bit before first cleanup to allow server to fully start
            await Task.Delay(TimeSpan.FromMinutes(1), stoppingToken);

            while (!stoppingToken.IsCancellationRequested)
            {
                try
                {
                    await CleanupExpiredObjectsAsync(stoppingToken);
                }
                catch (Exception ex)
                {
                    _logger.LogError(ex, "Error during world object cleanup");
                }

                // Wait for next cleanup cycle
                try
                {
                    await Task.Delay(_cleanupInterval, stoppingToken);
                }
                catch (TaskCanceledException)
                {
                    // Service is stopping, exit gracefully
                    break;
                }
            }

            _logger.LogInformation("WorldObjectCleanupService stopped");
        }

        private async Task CleanupExpiredObjectsAsync(CancellationToken cancellationToken)
        {
            using var scope = _serviceProvider.CreateScope();
            var context = scope.ServiceProvider.GetRequiredService<DatabaseContext>();

            var now = DateTime.UtcNow;

            // Find all expired objects
            var expiredObjects = await context.WorldObjects
                .Where(w => w.ExpirationTime != null && w.ExpirationTime <= now)
                .ToListAsync(cancellationToken);

            if (expiredObjects.Count == 0)
            {
                _logger.LogDebug("No expired world objects to clean up");
                return;
            }

            _logger.LogInformation(
                "Cleaning up {Count} expired world objects",
                expiredObjects.Count);

            // Remove expired objects
            context.WorldObjects.RemoveRange(expiredObjects);
            await context.SaveChangesAsync(cancellationToken);

            _logger.LogInformation(
                "Successfully cleaned up {Count} expired world objects",
                expiredObjects.Count);
        }
    }
}
