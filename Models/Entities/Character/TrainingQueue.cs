using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using Echoes.API.Models.Enums;

namespace Echoes.API.Models.Entities.Character
{
    /// <summary>
    /// Очередь тренировки навыков
    /// </summary>
    [Table("training_queues")]
    public class TrainingQueue
    {
        [Key]
        [Column("queue_id")]
        public Guid QueueId { get; set; } = Guid.NewGuid();
        
        [Required]
        [Column("character_id")]
        public Guid CharacterId { get; set; }
        
        [Required]
        [Column("character_skill_id")]
        public Guid CharacterSkillId { get; set; }
        
        [Required]
        [Column("target_level")]
        public SkillLevel TargetLevel { get; set; }
        
        [Required]
        [Column("queue_position")]
        public int QueuePosition { get; set; }
        
        [Required]
        [Column("status")]
        public TrainingQueueStatus Status { get; set; } = TrainingQueueStatus.Waiting;
        
        [Column("started_at")]
        public DateTime? StartedAt { get; set; }
        
        [Column("finished_at")]
        public DateTime? FinishedAt { get; set; }
        
        [Column("estimated_finish_at")]
        public DateTime? EstimatedFinishAt { get; set; }
        
        [Column("paused_at")]
        public DateTime? PausedAt { get; set; }
        
        [Column("paused_duration")]
        public long PausedDurationSeconds { get; set; } = 0;
        
        [Column("created_at")]
        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;
        
        [Column("updated_at")]
        public DateTime UpdatedAt { get; set; } = DateTime.UtcNow;
        
        // Навигационные свойства
        [ForeignKey("CharacterId")]
        public virtual Character Character { get; set; } = null!;
        
        [ForeignKey("CharacterSkillId")]
        public virtual CharacterSkillEnhanced CharacterSkill { get; set; } = null!;
        
        // Методы
        public bool IsTraining()
        {
            return Status == TrainingQueueStatus.Training && StartedAt.HasValue;
        }
        
        public bool IsCompleted()
        {
            return Status == TrainingQueueStatus.Completed && FinishedAt.HasValue;
        }
        
        public TimeSpan GetRemainingTime()
        {
            if (!IsTraining() || !EstimatedFinishAt.HasValue || !StartedAt.HasValue)
                return TimeSpan.Zero;
                
            var now = DateTime.UtcNow;
            if (PausedAt.HasValue)
            {
                // Calculate remaining time at pause + time already paused
                var remainingAtPause = EstimatedFinishAt.Value - PausedAt.Value;
                return remainingAtPause;
            }
            
            var remaining = EstimatedFinishAt.Value - now;
            return remaining > TimeSpan.Zero ? remaining : TimeSpan.Zero;
        }
        
        public long GetTotalTrainingTimeSeconds()
        {
            if (!StartedAt.HasValue || !FinishedAt.HasValue)
                return 0;
                
            return (long)(FinishedAt.Value - StartedAt.Value).TotalSeconds - PausedDurationSeconds;
        }
    }
}
