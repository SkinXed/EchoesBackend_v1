using Echoes.API.Data;
using Echoes.API.Models.Entities.Character;
using Echoes.API.Models.Enums;
using Microsoft.EntityFrameworkCore;

namespace Echoes.API.Services
{
    /// <summary>
    /// Service for managing character skill training
    /// </summary>
    public class TrainingService
    {
        private readonly DatabaseContext _context;
        private readonly ILogger<TrainingService> _logger;

        public TrainingService(DatabaseContext context, ILogger<TrainingService> logger)
        {
            _context = context;
            _logger = logger;
        }

        /// <summary>
        /// Start training a skill to a target level
        /// </summary>
        public async Task<(bool Success, string Message, CharacterSkillEnhanced? Skill)> StartTrainingAsync(
            Guid characterId, int skillId, SkillLevel targetLevel)
        {
            try
            {
                // Load character with attributes
                var character = await _context.Characters
                    .FirstOrDefaultAsync(c => c.Id == characterId);

                if (character == null)
                    return (false, "Character not found", null);

                // Load skill definition
                var skill = await _context.Skills
                    .FirstOrDefaultAsync(s => s.SkillId == skillId);

                if (skill == null)
                    return (false, "Skill not found", null);

                // Check if character already has this skill or create new
                var characterSkill = await _context.CharacterSkillsEnhanced
                    .Include(cs => cs.Skill)
                    .FirstOrDefaultAsync(cs => cs.CharacterId == characterId && cs.SkillId == skillId);

                if (characterSkill == null)
                {
                    // Create new skill entry
                    characterSkill = new CharacterSkillEnhanced
                    {
                        CharacterSkillId = Guid.NewGuid(),
                        CharacterId = characterId,
                        SkillId = skillId,
                        SkillLevel = SkillLevel.Level0,
                        SkillPoints = 0,
                        SkillPointsToNextLevel = skill.GetSkillPointsForLevel(SkillLevel.Level1),
                        IsActive = false
                    };
                    _context.CharacterSkillsEnhanced.Add(characterSkill);
                    await _context.SaveChangesAsync();
                    
                    // Reload with skill navigation
                    characterSkill = await _context.CharacterSkillsEnhanced
                        .Include(cs => cs.Skill)
                        .FirstOrDefaultAsync(cs => cs.CharacterSkillId == characterSkill.CharacterSkillId);
                    
                    if (characterSkill == null)
                        return (false, "Failed to reload skill after creation", null);
                }

                // Validate target level
                if (targetLevel <= characterSkill.SkillLevel)
                    return (false, "Target level must be higher than current level", null);

                if ((int)targetLevel > 5)
                    return (false, "Maximum skill level is 5", null);

                // Check if already training
                if (characterSkill.IsActive)
                    return (false, "Skill is already being trained", null);

                // Check if any other skill is being trained
                var hasActiveTraining = await _context.CharacterSkillsEnhanced
                    .AnyAsync(cs => cs.CharacterId == characterId && cs.IsActive && cs.SkillId != skillId);

                if (hasActiveTraining)
                    return (false, "Another skill is already being trained", null);

                // Calculate required SP and training time
                long currentSP = characterSkill.SkillPoints;
                long targetSP = skill.GetSkillPointsForLevel(targetLevel);
                long requiredSP = targetSP - currentSP;

                if (requiredSP <= 0)
                {
                    // Already have enough SP, just advance the level
                    characterSkill.SkillLevel = targetLevel;
                    characterSkill.SkillPoints = targetSP;
                    characterSkill.SkillPointsToNextLevel = targetLevel < SkillLevel.Level5 
                        ? skill.GetSkillPointsForLevel(targetLevel + 1) 
                        : targetSP;
                    characterSkill.UpdatedAt = DateTime.UtcNow;
                    await _context.SaveChangesAsync();
                    return (true, "Skill level advanced", characterSkill);
                }

                // Calculate training time (EVE formula: Time = SP / (Primary + Secondary/2))
                int primaryAttr = character.GetAttribute(skill.PrimaryAttribute);
                int secondaryAttr = character.GetAttribute(skill.SecondaryAttribute);
                double attributeSum = primaryAttr + (secondaryAttr / 2.0);
                
                // SP per minute = attributeSum
                double trainingMinutes = requiredSP / attributeSum;
                TimeSpan trainingTime = TimeSpan.FromMinutes(trainingMinutes);

                // Set training parameters
                characterSkill.TrainedLevel = targetLevel;
                characterSkill.TrainingStartedAt = DateTime.UtcNow;
                characterSkill.TrainingFinishedAt = DateTime.UtcNow.Add(trainingTime);
                characterSkill.IsActive = true;
                characterSkill.SkillPointsToNextLevel = targetSP;
                characterSkill.UpdatedAt = DateTime.UtcNow;

                await _context.SaveChangesAsync();

                _logger.LogInformation(
                    "Started training skill {SkillId} for character {CharacterId} to level {TargetLevel}, finish at {FinishTime}",
                    skillId, characterId, targetLevel, characterSkill.TrainingFinishedAt);

                return (true, $"Training started. Will complete in {trainingTime.TotalHours:F1} hours", characterSkill);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error starting training for character {CharacterId}, skill {SkillId}", characterId, skillId);
                return (false, $"Error starting training: {ex.Message}", null);
            }
        }

        /// <summary>
        /// Pause training and save progress
        /// </summary>
        public async Task<(bool Success, string Message, CharacterSkillEnhanced? Skill)> PauseTrainingAsync(
            Guid characterId, int skillId)
        {
            try
            {
                var characterSkill = await _context.CharacterSkillsEnhanced
                    .Include(cs => cs.Skill)
                    .Include(cs => cs.Character)
                    .FirstOrDefaultAsync(cs => cs.CharacterId == characterId && cs.SkillId == skillId);

                if (characterSkill == null)
                    return (false, "Skill not found", null);

                if (!characterSkill.IsActive)
                    return (false, "Skill is not being trained", null);

                // Calculate gained SP based on elapsed time
                var now = DateTime.UtcNow;
                var elapsedTime = now - characterSkill.TrainingStartedAt!.Value;
                
                int primaryAttr = characterSkill.Character.GetAttribute(characterSkill.Skill.PrimaryAttribute);
                int secondaryAttr = characterSkill.Character.GetAttribute(characterSkill.Skill.SecondaryAttribute);
                double attributeSum = primaryAttr + (secondaryAttr / 2.0);
                
                // Calculate SP gained (SP per minute * elapsed minutes)
                long gainedSP = (long)(attributeSum * elapsedTime.TotalMinutes);
                
                // Update skill points
                characterSkill.SkillPoints = Math.Min(
                    characterSkill.SkillPoints + gainedSP,
                    characterSkill.SkillPointsToNextLevel
                );

                // Reset training state
                characterSkill.IsActive = false;
                characterSkill.TrainedLevel = null;
                characterSkill.TrainingStartedAt = null;
                characterSkill.TrainingFinishedAt = null;
                characterSkill.UpdatedAt = now;

                await _context.SaveChangesAsync();

                _logger.LogInformation(
                    "Paused training for skill {SkillId}, character {CharacterId}, gained {GainedSP} SP",
                    skillId, characterId, gainedSP);

                return (true, $"Training paused. Gained {gainedSP} skill points", characterSkill);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error pausing training for character {CharacterId}, skill {SkillId}", characterId, skillId);
                return (false, $"Error pausing training: {ex.Message}", null);
            }
        }

        /// <summary>
        /// Cancel training without saving progress
        /// </summary>
        public async Task<(bool Success, string Message)> CancelTrainingAsync(Guid characterId, int skillId)
        {
            try
            {
                var characterSkill = await _context.CharacterSkillsEnhanced
                    .FirstOrDefaultAsync(cs => cs.CharacterId == characterId && cs.SkillId == skillId);

                if (characterSkill == null)
                    return (false, "Skill not found");

                if (!characterSkill.IsActive)
                    return (false, "Skill is not being trained");

                // Reset training state without saving progress
                characterSkill.IsActive = false;
                characterSkill.TrainedLevel = null;
                characterSkill.TrainingStartedAt = null;
                characterSkill.TrainingFinishedAt = null;
                characterSkill.UpdatedAt = DateTime.UtcNow;

                await _context.SaveChangesAsync();

                _logger.LogInformation(
                    "Cancelled training for skill {SkillId}, character {CharacterId}",
                    skillId, characterId);

                return (true, "Training cancelled");
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error cancelling training for character {CharacterId}, skill {SkillId}", characterId, skillId);
                return (false, $"Error cancelling training: {ex.Message}");
            }
        }

        /// <summary>
        /// Complete training and advance skill level
        /// </summary>
        public async Task<(bool Success, string Message, CharacterSkillEnhanced? Skill)> CompleteTrainingAsync(
            Guid characterId, int skillId)
        {
            try
            {
                var characterSkill = await _context.CharacterSkillsEnhanced
                    .Include(cs => cs.Skill)
                    .FirstOrDefaultAsync(cs => cs.CharacterId == characterId && cs.SkillId == skillId);

                if (characterSkill == null)
                    return (false, "Skill not found", null);

                if (!characterSkill.IsActive)
                    return (false, "Skill is not being trained", null);

                if (!characterSkill.TrainedLevel.HasValue)
                    return (false, "No target level set", null);

                var targetLevel = characterSkill.TrainedLevel.Value;

                // Set skill points to target level
                characterSkill.SkillPoints = characterSkill.SkillPointsToNextLevel;
                characterSkill.SkillLevel = targetLevel;

                // Update SkillPointsToNextLevel for next level
                if (targetLevel < SkillLevel.Level5)
                {
                    characterSkill.SkillPointsToNextLevel = 
                        characterSkill.Skill.GetSkillPointsForLevel(targetLevel + 1);
                }
                else
                {
                    // Already at max level
                    characterSkill.SkillPointsToNextLevel = characterSkill.SkillPoints;
                }

                // Reset training state
                characterSkill.IsActive = false;
                characterSkill.TrainedLevel = null;
                characterSkill.TrainingStartedAt = null;
                characterSkill.TrainingFinishedAt = null;
                characterSkill.UpdatedAt = DateTime.UtcNow;

                await _context.SaveChangesAsync();

                _logger.LogInformation(
                    "Completed training for skill {SkillId}, character {CharacterId}, reached level {Level}",
                    skillId, characterId, targetLevel);

                return (true, $"Training completed. Skill reached level {(int)targetLevel}", characterSkill);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error completing training for character {CharacterId}, skill {SkillId}", characterId, skillId);
                return (false, $"Error completing training: {ex.Message}", null);
            }
        }

        /// <summary>
        /// Get all skills for a character with training progress
        /// </summary>
        public async Task<List<CharacterSkillEnhanced>> GetCharacterSkillsAsync(Guid characterId)
        {
            return await _context.CharacterSkillsEnhanced
                .Include(cs => cs.Skill)
                .ThenInclude(s => s.SkillGroup)
                .Where(cs => cs.CharacterId == characterId)
                .OrderBy(cs => cs.Skill.SkillGroup.Name)
                .ThenBy(cs => cs.Skill.Name)
                .ToListAsync();
        }

        /// <summary>
        /// Get skills that need to be completed (for background worker)
        /// </summary>
        public async Task<List<CharacterSkillEnhanced>> GetCompletedTrainingsAsync()
        {
            var now = DateTime.UtcNow;
            return await _context.CharacterSkillsEnhanced
                .Include(cs => cs.Skill)
                .Include(cs => cs.Character)
                .Where(cs => cs.IsActive && cs.TrainingFinishedAt <= now)
                .ToListAsync();
        }
    }
}
