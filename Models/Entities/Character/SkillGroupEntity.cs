using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Echoes.API.Models.Entities.Character
{
    /// <summary>
    /// Группы навыков
    /// </summary>
    [Table("skill_groups")]
    public class SkillGroupEntity
    {
        [Key]
        [Column("skill_group_id")]
        public int SkillGroupId { get; set; }
        
        [Required]
        [Column("name")]
        [MaxLength(100)]
        public string Name { get; set; } = string.Empty;
        
        [Column("description")]
        public string? Description { get; set; }
        
        [Column("config_json", TypeName = "text")]
        public string ConfigJson { get; set; } = "{}";
        
        [Column("created_at")]
        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;
        
        [Column("updated_at")]
        public DateTime UpdatedAt { get; set; } = DateTime.UtcNow;
        
        // Навигационные свойства
        public virtual ICollection<Skill> Skills { get; set; } = new List<Skill>();
    }
}
