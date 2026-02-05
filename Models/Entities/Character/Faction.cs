using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Echoes.API.Models.Entities.Character
{
    /// <summary>
    /// Фракции персонажей
    /// </summary>
    [Table("factions")]
    public class Faction
    {
        [Key]
        [Column("faction_id")]
        public int FactionId { get; set; }
        
        [Required]
        [Column("name")]
        [MaxLength(100)]
        public string Name { get; set; } = string.Empty;
        
        [Column("config_json", TypeName = "text")]
        public string ConfigJson { get; set; } = "{}";
        
        [Column("description")]
        public string? Description { get; set; }
        
        [Column("created_at")]
        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;
        
        [Column("updated_at")]
        public DateTime UpdatedAt { get; set; } = DateTime.UtcNow;
        
        // Навигационные свойства
        public virtual ICollection<Character> Characters { get; set; } = new List<Character>();
    }
}
