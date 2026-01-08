using System;
using System.Threading;
using System.Threading.Tasks;
using Echoes.API.Data;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Diagnostics.HealthChecks;
using Microsoft.Extensions.Logging;

namespace Echoes.API.Health
{
    public class DatabaseHealthCheck : IHealthCheck
    {
        private readonly DatabaseContext _context;
        private readonly ILogger<DatabaseHealthCheck> _logger;

        public DatabaseHealthCheck(DatabaseContext context, ILogger<DatabaseHealthCheck> logger)
        {
            _context = context;
            _logger = logger;
        }

        public async Task<HealthCheckResult> CheckHealthAsync(
            HealthCheckContext context,
            CancellationToken cancellationToken = default)
        {
            try
            {
                //
                var canConnect = await _context.Database.CanConnectAsync(cancellationToken);

                if (canConnect)
                {
                    // ????????? ??????? ??????
                    var hasTables = await _context.Regions.AnyAsync(cancellationToken) ||
                                   await _context.UniverseGenerationConfigs.AnyAsync(cancellationToken);

                    if (hasTables)
                    {
                        return HealthCheckResult.Healthy("Database is healthy and contains data");
                    }
                    else
                    {
                        return HealthCheckResult.Degraded("Database is connected but has no data");
                    }
                }
                else
                {
                    return HealthCheckResult.Unhealthy("Cannot connect to database");
                }
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Database health check failed");
                return HealthCheckResult.Unhealthy($"Database health check failed: {ex.Message}");
            }
        }
    }
}
