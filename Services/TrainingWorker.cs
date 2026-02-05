using Echoes.API.Data;
using Echoes.API.Services;
using Microsoft.EntityFrameworkCore;

namespace Echoes.API.Services
{
    /// <summary>
    /// Background worker that automatically completes finished skill training
    /// </summary>
    public class TrainingWorker : BackgroundService
    {
        private readonly ILogger<TrainingWorker> _logger;
        private readonly IServiceProvider _serviceProvider;
        private readonly TimeSpan _checkInterval = TimeSpan.FromMinutes(1); // Check every minute

        public TrainingWorker(ILogger<TrainingWorker> logger, IServiceProvider serviceProvider)
        {
            _logger = logger;
            _serviceProvider = serviceProvider;
        }

        protected override async Task ExecuteAsync(CancellationToken stoppingToken)
        {
            _logger.LogInformation("TrainingWorker started at {Time}", DateTime.UtcNow);

            while (!stoppingToken.IsCancellationRequested)
            {
                try
                {
                    await ProcessCompletedTrainingsAsync(stoppingToken);
                }
                catch (Exception ex)
                {
                    _logger.LogError(ex, "Error processing completed trainings");
                }

                await Task.Delay(_checkInterval, stoppingToken);
            }

            _logger.LogInformation("TrainingWorker stopped at {Time}", DateTime.UtcNow);
        }

        private async Task ProcessCompletedTrainingsAsync(CancellationToken cancellationToken)
        {
            using var scope = _serviceProvider.CreateScope();
            var trainingService = scope.ServiceProvider.GetRequiredService<TrainingService>();

            try
            {
                var completedTrainings = await trainingService.GetCompletedTrainingsAsync();

                if (completedTrainings.Any())
                {
                    _logger.LogInformation("Found {Count} completed trainings to process", completedTrainings.Count);

                    foreach (var training in completedTrainings)
                    {
                        if (cancellationToken.IsCancellationRequested)
                            break;

                        var (success, message, _) = await trainingService.CompleteTrainingAsync(
                            training.CharacterId,
                            training.SkillId
                        );

                        if (success)
                        {
                            _logger.LogInformation(
                                "Auto-completed training for character {CharacterId}, skill {SkillId}: {Message}",
                                training.CharacterId, training.SkillId, message);
                        }
                        else
                        {
                            _logger.LogWarning(
                                "Failed to auto-complete training for character {CharacterId}, skill {SkillId}: {Message}",
                                training.CharacterId, training.SkillId, message);
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error in ProcessCompletedTrainingsAsync");
            }
        }
    }
}
