using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using Echoes.API.Models.Enums;

namespace Echoes.API.Models.Entities.Character
{
    /// <summary>
    /// Клоны персонажа
    /// </summary>
    [Table("character_clones")]
    public class CharacterClone
    {
        [Key]
        [Column("clone_id")]
        public Guid CloneId { get; set; } = Guid.NewGuid();
        
        [Required]
        [Column("character_id")]
        public Guid CharacterId { get; set; }
        
        [Required]
        [Column("clone_type")]
        public CloneType CloneType { get; set; }
        
        [Required]
        [Column("name")]
        public string Name { get; set; } = string.Empty;
        
        [Column("description")]
        public string? Description { get; set; }
        
        [Required]
        [Column("location_id")]
        public Guid LocationId { get; set; }
        
        [Column("solar_system_id")]
        public int? SolarSystemId { get; set; }
        
        [Column("station_id")]
        public int? StationId { get; set; }
        
        [Column("implants")]
        public string ImplantsJson { get; set; } = string.Empty; // List<Guid> of implant AssetIds
        
        [Column("skill_points")]
        public long SkillPoints { get; set; } = 0;
        
        [Column("max_skill_points")]
        public long MaxSkillPoints { get; set; } = 5000000; // 5M SP для альфа
        
        [Column("is_jump_clone")]
        public bool IsJumpClone { get; set; }
        
        [Column("jump_cooldown_until")]
        public DateTime? JumpCooldownUntil { get; set; }
        
        [Column("is_active")]
        public bool IsActive { get; set; }
        
        [Column("created_at")]
        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;
        
        [Column("updated_at")]
        public DateTime UpdatedAt { get; set; } = DateTime.UtcNow;
        
        // Навигационные свойства
        [ForeignKey("CharacterId")]
        public virtual Character Character { get; set; } = null!;
        
        // Методы
        [NotMapped]
        public List<Guid> ImplantIds
        {
            get => string.IsNullOrEmpty(ImplantsJson) ? 
                new List<Guid>() : 
                System.Text.Json.JsonSerializer.Deserialize<List<Guid>>(ImplantsJson)!;
            set => ImplantsJson = System.Text.Json.JsonSerializer.Serialize(value);
        }
        
        public bool CanJump()
        {
            if (!IsJumpClone)
                return false;
                
            return !JumpCooldownUntil.HasValue || JumpCooldownUntil.Value < DateTime.UtcNow;
        }
        
        public bool CanInstallImplant()
        {
            return ImplantIds.Count < 10; // Максимум 10 имплантов
        }
        
        public void AddImplant(Guid implantAssetId)
        {
            if (CanInstallImplant() && !ImplantIds.Contains(implantAssetId))
            {
                ImplantIds.Add(implantAssetId);
            }
        }
        
        public void RemoveImplant(Guid implantAssetId)
        {
            ImplantIds.Remove(implantAssetId);
        }
        
        public bool HasImplant(Guid implantAssetId)
        {
            return ImplantIds.Contains(implantAssetId);
        }
    }
}
