using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using Echoes.API.Models.Enums;

namespace Echoes.API.Models.Entities.Character
{
    /// <summary>
    /// Справочник навыков
    /// </summary>
    [Table("skills")]
    public class Skill
    {
        [Key]
        [Column("skill_id")]
        public int SkillId { get; set; }
        
        [Required]
        [Column("name")]
        public string Name { get; set; } = string.Empty;
        
        [Column("description")]
        public string Description { get; set; } = string.Empty;
        
        [Required]
        [Column("skill_group_id")]
        [ForeignKey(nameof(SkillGroup))]
        public int SkillGroupId { get; set; }
        
        [Required]
        [Column("skill_type")]
        public SkillType SkillType { get; set; } = SkillType.Standard;
        
        [Required]
        [Column("rank")]
        public decimal Rank { get; set; } = 1.0m;
        
        [Column("primary_attribute")]
        public CharacterAttribute PrimaryAttribute { get; set; }
        
        [Column("secondary_attribute")]
        public CharacterAttribute SecondaryAttribute { get; set; }
        
        [Column("required_skills")]
        public string RequiredSkillsJson { get; set; } = string.Empty; // SkillId -> Level
        
        [Column("bonus_effects")]
        public string BonusEffectsJson { get; set; } = string.Empty;
        
        [Column("icon_id")]
        public string? IconId { get; set; }
        
        [Column("market_group_id")]
        public int? MarketGroupId { get; set; }
        
        [Column("created_at")]
        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;
        
        [Column("updated_at")]
        public DateTime UpdatedAt { get; set; } = DateTime.UtcNow;
        
        // Навигационные свойства
        public virtual SkillGroupEntity SkillGroup { get; set; } = null!;
        public virtual ICollection<CharacterSkillEnhanced> CharacterSkills { get; set; } = new List<CharacterSkillEnhanced>();
        
        // Методы
        [NotMapped]
        public Dictionary<int, SkillLevel> RequiredSkills
        {
            get => string.IsNullOrEmpty(RequiredSkillsJson) ? 
                new Dictionary<int, SkillLevel>() : 
                System.Text.Json.JsonSerializer.Deserialize<Dictionary<int, SkillLevel>>(RequiredSkillsJson)!;
            set => RequiredSkillsJson = System.Text.Json.JsonSerializer.Serialize(value);
        }
        
        [NotMapped]
        public Dictionary<string, decimal> BonusEffects
        {
            get => string.IsNullOrEmpty(BonusEffectsJson) ? 
                new Dictionary<string, decimal>() : 
                System.Text.Json.JsonSerializer.Deserialize<Dictionary<string, decimal>>(BonusEffectsJson)!;
            set => BonusEffectsJson = System.Text.Json.JsonSerializer.Serialize(value);
        }
        
        public long CalculateTrainingTime(int primaryAttribute, int secondaryAttribute)
        {
            // Формула из EVE: Time = SP / (Primary + Secondary/2)
            long spForLevel5 = GetSkillPointsForLevel(SkillLevel.Level5);
            double attributeSum = primaryAttribute + (secondaryAttribute / 2.0);
            
            if (attributeSum <= 0)
                return long.MaxValue;
                
            return (long)(spForLevel5 / attributeSum);
        }
        
        public long GetSkillPointsForLevel(SkillLevel level)
        {
            // Level 0 means no training
            if (level == SkillLevel.Level0)
                return 0;
                
            double basePoints = 250 * Math.Pow(2.5, (int)level - 1);
            return (long)(basePoints * (double)Rank);
        }
    }
}
