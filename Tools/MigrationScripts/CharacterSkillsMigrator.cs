using Echoes.API.Data;
using Echoes.API.Models.Entities.Character;
using Echoes.API.Models.Enums;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Logging;

namespace Echoes.API.Tools.MigrationScripts
{
    /// <summary>
    /// Migrates data from character_skills to character_skills_enhanced table
    /// 
    /// IMPORTANT: Run this ONLY after:
    /// 1. Database backup is taken
    /// 2. The AddFactionsAndSkillGroups migration has been applied
    /// 3. All existing skills have been assigned proper SkillGroupId values
    /// 
    /// Usage:
    /// - Add this class to your project
    /// - Call MigrateCharacterSkillsAsync from your startup or a migration endpoint
    /// - Or run via CLI tool
    /// </summary>
    public class CharacterSkillsMigrator
    {
        private readonly DatabaseContext _context;
        private readonly ILogger<CharacterSkillsMigrator> _logger;

        public CharacterSkillsMigrator(DatabaseContext context, ILogger<CharacterSkillsMigrator> logger)
        {
            _context = context;
            _logger = logger;
        }

        /// <summary>
        /// Migrate all character skills from old table to enhanced table
        /// </summary>
        public async Task<(int Migrated, int Skipped, int Errors)> MigrateCharacterSkillsAsync()
        {
            int migrated = 0;
            int skipped = 0;
            int errors = 0;

            try
            {
                _logger.LogInformation("Starting character skills migration...");

                // Get all old character skills
                var oldSkills = await _context.Set<CharacterSkill>()
                    .AsNoTracking()
                    .ToListAsync();

                _logger.LogInformation("Found {Count} old character skills to migrate", oldSkills.Count);

                // Load all skill definitions for SP calculations
                var skillDefinitions = await _context.Skills
                    .AsNoTracking()
                    .ToDictionaryAsync(s => s.SkillId, s => s);

                foreach (var oldSkill in oldSkills)
                {
                    try
                    {
                        // Check if already exists in enhanced table
                        var existing = await _context.CharacterSkillsEnhanced
                            .FirstOrDefaultAsync(cs => 
                                cs.CharacterId == oldSkill.CharacterId && 
                                cs.SkillId == oldSkill.SkillId);

                        if (existing != null)
                        {
                            _logger.LogDebug(
                                "Skill already exists in enhanced table for character {CharacterId}, skill {SkillId}",
                                oldSkill.CharacterId, oldSkill.SkillId);
                            skipped++;
                            continue;
                        }

                        // Get skill definition
                        if (!skillDefinitions.TryGetValue(oldSkill.SkillId, out var skillDef))
                        {
                            _logger.LogWarning(
                                "Skill definition not found for skill {SkillId}, skipping",
                                oldSkill.SkillId);
                            skipped++;
                            continue;
                        }

                        // Convert Level to SkillLevel enum
                        SkillLevel skillLevel = oldSkill.Level switch
                        {
                            0 => SkillLevel.Level0,
                            1 => SkillLevel.Level1,
                            2 => SkillLevel.Level2,
                            3 => SkillLevel.Level3,
                            4 => SkillLevel.Level4,
                            5 => SkillLevel.Level5,
                            _ => SkillLevel.Level0
                        };

                        // Calculate SkillPointsToNextLevel
                        long skillPointsToNextLevel;
                        if (skillLevel >= SkillLevel.Level5)
                        {
                            // Already at max level
                            skillPointsToNextLevel = oldSkill.Skillpoints;
                        }
                        else
                        {
                            var nextLevel = (SkillLevel)((int)skillLevel + 1);
                            skillPointsToNextLevel = skillDef.GetSkillPointsForLevel(nextLevel);
                        }

                        // Create enhanced skill record
                        var enhancedSkill = new CharacterSkillEnhanced
                        {
                            CharacterSkillId = Guid.NewGuid(),
                            CharacterId = oldSkill.CharacterId,
                            SkillId = oldSkill.SkillId,
                            SkillLevel = skillLevel,
                            SkillPoints = oldSkill.Skillpoints,
                            SkillPointsToNextLevel = skillPointsToNextLevel,
                            TrainedLevel = null, // Will be set if active training
                            TrainingStartedAt = oldSkill.TrainingStart,
                            TrainingFinishedAt = oldSkill.TrainingEnd,
                            IsActive = oldSkill.IsActive,
                            CreatedAt = DateTime.UtcNow,
                            UpdatedAt = DateTime.UtcNow
                        };

                        // If there's active training, set trained level
                        if (oldSkill.IsActive && oldSkill.TrainingEnd.HasValue)
                        {
                            // Assume training to next level
                            if (skillLevel < SkillLevel.Level5)
                            {
                                enhancedSkill.TrainedLevel = (SkillLevel)((int)skillLevel + 1);
                            }
                        }

                        _context.CharacterSkillsEnhanced.Add(enhancedSkill);
                        migrated++;

                        // Batch save every 100 records
                        if (migrated % 100 == 0)
                        {
                            await _context.SaveChangesAsync();
                            _logger.LogInformation("Migrated {Count} skills so far...", migrated);
                        }
                    }
                    catch (Exception ex)
                    {
                        _logger.LogError(
                            ex,
                            "Error migrating skill for character {CharacterId}, skill {SkillId}",
                            oldSkill.CharacterId,
                            oldSkill.SkillId);
                        errors++;
                    }
                }

                // Save remaining
                await _context.SaveChangesAsync();

                _logger.LogInformation(
                    "Migration completed: {Migrated} migrated, {Skipped} skipped, {Errors} errors",
                    migrated, skipped, errors);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Fatal error during migration");
                throw;
            }

            return (migrated, skipped, errors);
        }

        /// <summary>
        /// Verify migration by comparing counts
        /// </summary>
        public async Task<bool> VerifyMigrationAsync()
        {
            try
            {
                var oldCount = await _context.Set<CharacterSkill>().CountAsync();
                var newCount = await _context.CharacterSkillsEnhanced.CountAsync();

                _logger.LogInformation(
                    "Migration verification: Old table has {OldCount} records, new table has {NewCount} records",
                    oldCount, newCount);

                return newCount >= oldCount;
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error verifying migration");
                return false;
            }
        }
    }

    /// <summary>
    /// Extension methods to help with migration
    /// </summary>
    public static class MigrationExtensions
    {
        /// <summary>
        /// Register the migrator in dependency injection
        /// </summary>
        public static IServiceCollection AddCharacterSkillsMigrator(this IServiceCollection services)
        {
            services.AddScoped<CharacterSkillsMigrator>();
            return services;
        }
    }
}
