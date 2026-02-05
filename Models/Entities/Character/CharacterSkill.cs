using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Echoes.API.Models.Entities.Character
{
    [Table("character_skills")]
    public class CharacterSkill 
    {
        [Key]
        public Guid Id { get; set; }

        [ForeignKey(nameof(Character))]
        public Guid CharacterId { get; set; }

        public int SkillId { get; set; } // ID из статики
        public int Level { get; set; } = 0;
        public int Skillpoints { get; set; } = 0;

        // Тренировка
        public bool IsActive { get; set; } = false;
        public DateTime? TrainingStart { get; set; }
        public DateTime? TrainingEnd { get; set; }

        public virtual Character Character { get; set; } = null!;
    }
}
