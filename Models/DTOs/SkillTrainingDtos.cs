using Echoes.API.Models.Enums;

namespace Echoes.API.Models.DTOs
{
    /// <summary>
    /// Enhanced DTO for character skill information with training progress
    /// </summary>
    public class CharacterSkillEnhancedDto
    {
        public Guid CharacterSkillId { get; set; }
        public int SkillId { get; set; }
        public string SkillName { get; set; } = string.Empty;
        public string SkillGroupName { get; set; } = string.Empty;
        public SkillLevel SkillLevel { get; set; }
        public long SkillPoints { get; set; }
        public long SkillPointsToNextLevel { get; set; }
        public SkillLevel? TrainedLevel { get; set; }
        public bool IsActive { get; set; }
        public DateTime? TrainingStartedAt { get; set; }
        public DateTime? TrainingFinishedAt { get; set; }
        public double ProgressPercent { get; set; }
        public TimeSpan? TimeRemaining { get; set; }
    }

    /// <summary>
    /// Request to start training a skill
    /// </summary>
    public class StartTrainingRequest
    {
        public Guid CharacterId { get; set; }
        public int SkillId { get; set; }
        public SkillLevel TargetLevel { get; set; }
    }

    /// <summary>
    /// Request to pause or cancel training
    /// </summary>
    public class PauseTrainingRequest
    {
        public Guid CharacterId { get; set; }
        public int SkillId { get; set; }
    }

    /// <summary>
    /// Response for training operations
    /// </summary>
    public class TrainingOperationResponse
    {
        public bool Success { get; set; }
        public string Message { get; set; } = string.Empty;
        public CharacterSkillEnhancedDto? Skill { get; set; }
    }
}
