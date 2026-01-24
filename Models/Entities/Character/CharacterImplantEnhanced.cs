using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using Echoes.API.Models.Enums;
using Echoes.API.Models.Entities.Inventory;

namespace Echoes.API.Models.Entities.Character
{
    /// <summary>
    /// Импланты персонажа (Enhanced version)
    /// </summary>
    [Table("character_implants_enhanced")]
    public class CharacterImplantEnhanced
    {
        [Key]
        [Column("implant_id")]
        public Guid ImplantId { get; set; } = Guid.NewGuid();
        
        [Required]
        [Column("character_id")]
        public Guid CharacterId { get; set; }
        
        [Required]
        [Column("asset_id")]
        public Guid AssetId { get; set; }
        
        [Required]
        [Column("implant_type")]
        public ImplantType ImplantType { get; set; }
        
        [Required]
        [Column("slot")]
        public ImplantSlot Slot { get; set; }
        
        [Column("is_active")]
        public bool IsActive { get; set; } = true;
        
        [Column("effects")]
        public string EffectsJson { get; set; } = string.Empty;
        
        [Column("expires_at")]
        public DateTime? ExpiresAt { get; set; }
        
        [Column("installed_at")]
        public DateTime InstalledAt { get; set; } = DateTime.UtcNow;
        
        [Column("created_at")]
        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;
        
        // Навигационные свойства
        [ForeignKey("CharacterId")]
        public virtual Character Character { get; set; } = null!;
        
        [ForeignKey("AssetId")]
        public virtual Asset Asset { get; set; } = null!;
        
        // Методы
        [NotMapped]
        public Dictionary<CharacterAttribute, int> AttributeBonuses
        {
            get
            {
                var effects = string.IsNullOrEmpty(EffectsJson) ? 
                    new Dictionary<string, decimal>() : 
                    System.Text.Json.JsonSerializer.Deserialize<Dictionary<string, decimal>>(EffectsJson)!;
                    
                var bonuses = new Dictionary<CharacterAttribute, int>();
                
                foreach (var effect in effects)
                {
                    if (Enum.TryParse<CharacterAttribute>(effect.Key, out var attribute))
                    {
                        bonuses[attribute] = (int)effect.Value;
                    }
                }
                
                return bonuses;
            }
        }
        
        public bool IsExpired()
        {
            return ExpiresAt.HasValue && ExpiresAt.Value < DateTime.UtcNow;
        }
        
        public int GetAttributeBonus(CharacterAttribute attribute)
        {
            return AttributeBonuses.TryGetValue(attribute, out var bonus) ? bonus : 0;
        }
    }
}
