using Echoes.API.Models.DTOs;
using Echoes.API.Models.Enums;
using Echoes.API.Services;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;

namespace Echoes.API.Controllers
{
    /// <summary>
    /// Controller for managing character skill training
    /// </summary>
    [ApiController]
    [Route("api/[controller]")]
    [Authorize]
    public class SkillTrainingController : ControllerBase
    {
        private readonly TrainingService _trainingService;
        private readonly ILogger<SkillTrainingController> _logger;

        public SkillTrainingController(TrainingService trainingService, ILogger<SkillTrainingController> logger)
        {
            _trainingService = trainingService;
            _logger = logger;
        }

        /// <summary>
        /// Get all skills for a character with training progress
        /// </summary>
        [HttpGet("character/{characterId}")]
        public async Task<ActionResult<List<CharacterSkillEnhancedDto>>> GetCharacterSkills(Guid characterId)
        {
            try
            {
                var skills = await _trainingService.GetCharacterSkillsAsync(characterId);
                
                var skillDtos = skills.Select(s => new CharacterSkillEnhancedDto
                {
                    CharacterSkillId = s.CharacterSkillId,
                    SkillId = s.SkillId,
                    SkillName = s.Skill?.Name ?? "Unknown",
                    SkillGroupName = s.Skill?.SkillGroup?.Name ?? "Unknown",
                    SkillLevel = s.SkillLevel,
                    SkillPoints = s.SkillPoints,
                    SkillPointsToNextLevel = s.SkillPointsToNextLevel,
                    TrainedLevel = s.TrainedLevel,
                    IsActive = s.IsActive,
                    TrainingStartedAt = s.TrainingStartedAt,
                    TrainingFinishedAt = s.TrainingFinishedAt,
                    ProgressPercent = s.GetTrainingProgress(),
                    TimeRemaining = s.GetTrainingTimeRemaining()
                }).ToList();

                return Ok(skillDtos);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error getting skills for character {CharacterId}", characterId);
                return StatusCode(500, "Error retrieving character skills");
            }
        }

        /// <summary>
        /// Start training a skill
        /// </summary>
        [HttpPost("start")]
        public async Task<ActionResult<TrainingOperationResponse>> StartTraining([FromBody] StartTrainingRequest request)
        {
            try
            {
                var (success, message, skill) = await _trainingService.StartTrainingAsync(
                    request.CharacterId,
                    request.SkillId,
                    request.TargetLevel
                );

                var response = new TrainingOperationResponse
                {
                    Success = success,
                    Message = message,
                    Skill = skill != null ? new CharacterSkillEnhancedDto
                    {
                        CharacterSkillId = skill.CharacterSkillId,
                        SkillId = skill.SkillId,
                        SkillName = skill.Skill?.Name ?? "Unknown",
                        SkillGroupName = skill.Skill?.SkillGroup?.Name ?? "Unknown",
                        SkillLevel = skill.SkillLevel,
                        SkillPoints = skill.SkillPoints,
                        SkillPointsToNextLevel = skill.SkillPointsToNextLevel,
                        TrainedLevel = skill.TrainedLevel,
                        IsActive = skill.IsActive,
                        TrainingStartedAt = skill.TrainingStartedAt,
                        TrainingFinishedAt = skill.TrainingFinishedAt,
                        ProgressPercent = skill.GetTrainingProgress(),
                        TimeRemaining = skill.GetTrainingTimeRemaining()
                    } : null
                };

                return success ? Ok(response) : BadRequest(response);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error starting training");
                return StatusCode(500, new TrainingOperationResponse
                {
                    Success = false,
                    Message = "Error starting training"
                });
            }
        }

        /// <summary>
        /// Pause training and save progress
        /// </summary>
        [HttpPost("pause")]
        public async Task<ActionResult<TrainingOperationResponse>> PauseTraining([FromBody] PauseTrainingRequest request)
        {
            try
            {
                var (success, message, skill) = await _trainingService.PauseTrainingAsync(
                    request.CharacterId,
                    request.SkillId
                );

                var response = new TrainingOperationResponse
                {
                    Success = success,
                    Message = message,
                    Skill = skill != null ? new CharacterSkillEnhancedDto
                    {
                        CharacterSkillId = skill.CharacterSkillId,
                        SkillId = skill.SkillId,
                        SkillName = skill.Skill?.Name ?? "Unknown",
                        SkillGroupName = skill.Skill?.SkillGroup?.Name ?? "Unknown",
                        SkillLevel = skill.SkillLevel,
                        SkillPoints = skill.SkillPoints,
                        SkillPointsToNextLevel = skill.SkillPointsToNextLevel,
                        TrainedLevel = skill.TrainedLevel,
                        IsActive = skill.IsActive,
                        TrainingStartedAt = skill.TrainingStartedAt,
                        TrainingFinishedAt = skill.TrainingFinishedAt,
                        ProgressPercent = skill.GetTrainingProgress(),
                        TimeRemaining = skill.GetTrainingTimeRemaining()
                    } : null
                };

                return success ? Ok(response) : BadRequest(response);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error pausing training");
                return StatusCode(500, new TrainingOperationResponse
                {
                    Success = false,
                    Message = "Error pausing training"
                });
            }
        }

        /// <summary>
        /// Cancel training without saving progress
        /// </summary>
        [HttpPost("cancel")]
        public async Task<ActionResult<TrainingOperationResponse>> CancelTraining([FromBody] PauseTrainingRequest request)
        {
            try
            {
                var (success, message) = await _trainingService.CancelTrainingAsync(
                    request.CharacterId,
                    request.SkillId
                );

                var response = new TrainingOperationResponse
                {
                    Success = success,
                    Message = message
                };

                return success ? Ok(response) : BadRequest(response);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error cancelling training");
                return StatusCode(500, new TrainingOperationResponse
                {
                    Success = false,
                    Message = "Error cancelling training"
                });
            }
        }
    }
}
