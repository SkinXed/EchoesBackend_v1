using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using Echoes.API.Models.Enums;

namespace Echoes.API.Models.Entities.Character
{
    /// <summary>
    /// Навыки персонажа (Enhanced version)
    /// </summary>
    [Table("character_skills_enhanced")]
    public class CharacterSkillEnhanced
    {
        [Key]
        [Column("character_skill_id")]
        public Guid CharacterSkillId { get; set; } = Guid.NewGuid();
        
        [Required]
        [Column("character_id")]
        public Guid CharacterId { get; set; }
        
        [Required]
        [Column("skill_id")]
        public int SkillId { get; set; }
        
        [Required]
        [Column("skill_level")]
        public SkillLevel SkillLevel { get; set; } = SkillLevel.Level0;
        
        [Required]
        [Column("skill_points")]
        public long SkillPoints { get; set; } = 0;
        
        [Required]
        [Column("skill_points_to_next_level")]
        public long SkillPointsToNextLevel { get; set; }
        
        [Column("trained_level")]
        public SkillLevel? TrainedLevel { get; set; }
        
        [Column("training_started_at")]
        public DateTime? TrainingStartedAt { get; set; }
        
        [Column("training_finished_at")]
        public DateTime? TrainingFinishedAt { get; set; }
        
        [Column("is_active")]
        public bool IsActive { get; set; } = true;
        
        [Column("created_at")]
        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;
        
        [Column("updated_at")]
        public DateTime UpdatedAt { get; set; } = DateTime.UtcNow;
        
        // Навигационные свойства
        [ForeignKey("CharacterId")]
        public virtual Character Character { get; set; } = null!;
        
        [ForeignKey("SkillId")]
        public virtual Skill Skill { get; set; } = null!;
        
        // Методы
        public bool CanTrainToLevel(SkillLevel targetLevel)
        {
            return targetLevel > SkillLevel && (int)targetLevel <= 5;
        }
        
        public long GetSkillPointsForLevel(SkillLevel level)
        {
            // Формула из EVE: SP = 250 * (2.5^(level-1)) * Rank
            double basePoints = 250 * Math.Pow(2.5, (int)level - 1);
            return (long)(basePoints * (double)Skill.Rank);
        }
        
        public long GetSkillPointsRemaining()
        {
            return SkillPointsToNextLevel - SkillPoints;
        }
        
        public double GetTrainingProgress()
        {
            if (SkillPointsToNextLevel <= 0)
                return 100.0;
                
            return (double)SkillPoints / SkillPointsToNextLevel * 100.0;
        }
        
        public TimeSpan GetTrainingTimeRemaining()
        {
            if (!TrainingFinishedAt.HasValue || !TrainingStartedAt.HasValue)
                return TimeSpan.Zero;
                
            return TrainingFinishedAt.Value - DateTime.UtcNow;
        }
    }
}
