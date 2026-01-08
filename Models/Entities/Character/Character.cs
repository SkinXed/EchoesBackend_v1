using Echoes.API.Models.Entities.Inventory;
using Echoes.API.Models.Entities.Universe;
//using Echoes.API.Models.Entities.Corporation; // Добавьте эту строку
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Echoes.API.Models.Entities.Character
{
    [Table("characters")]
    public class Character 
    {
        [Key]
        public Guid Id { get; set; }

        [Required]
        [MaxLength(50)]
        public string Name { get; set; } = string.Empty;

        [ForeignKey(nameof(Account))]
        public Guid AccountId { get; set; }

        // EVE-статистика
        public long WalletBalance { get; set; } = 1000000; // 1M ISK стартовых
        public float SecurityStatus { get; set; } = 0.0f;
        public DateTime CloneExpiration { get; set; } = DateTime.UtcNow.AddDays(30);

        // Корпорация
        [ForeignKey("CorporationId")]
        public Guid? CorporationId { get; set; }
        public long CorporationRole { get; set; } = 0;

        // Фракция и раса (как в EVE)
        public int RaceId { get; set; } = 1; // Amarr, Caldari, etc
        public int BloodlineId { get; set; } = 1;
        public int AncestryId { get; set; } = 1;

        // Игровой прогресс
        public int TotalSkillPoints { get; set; } = 0;
        public int UnallocatedSkillPoints { get; set; } = 0;
        public DateTime? SkillTrainingEnd { get; set; }

        // Активный корабль
        [ForeignKey(nameof(ActiveShip))]
        public long? ActiveShipItemId { get; set; }

        // Текущая локация
        //public Guid? CurrentLocationId { get; set; }

        // Настройки
        public string SettingsJson { get; set; } = "{}";

        // Флаги
        public bool IsMain { get; set; } = true;
        public bool IsOnline { get; set; } = false;
        public bool IsDocked { get; set; } = true;
        public bool InWarp { get; set; } = false;

        // Навигационные свойства
        public virtual Account Account { get; set; } = null!;
        public virtual CharacterLocation? CurrentLocation { get; set; }
        public virtual InventoryItem? ActiveShip { get; set; }
        public virtual ICollection<CharacterSkill> Skills { get; set; } = new List<CharacterSkill>();
        public virtual ICollection<InventoryItem> InventoryItems { get; set; } = new List<InventoryItem>();
        public virtual ICollection<CharacterImplant> Implants { get; set; } = new List<CharacterImplant>();
        public virtual ICollection<CharacterStanding> Standings { get; set; } = new List<CharacterStanding>();
        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;
        public DateTime LastLogin { get; internal set; }
        //public virtual ICollection<Corporation.Corporation>? Corporations { get; set; } // Если CEO
    }

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

    [Table("character_implants")]
    public class CharacterImplant 
    {
        [Key]
        public Guid Id { get; set; }

        [ForeignKey(nameof(Character))]
        public Guid CharacterId { get; set; }

        public int Slot { get; set; } // 1-10 как в EVE
        public int TypeId { get; set; }

        public virtual Character Character { get; set; } = null!;
    }

    [Table("character_standings")]
    public class CharacterStanding 
    {
        [Key]
        public Guid Id { get; set; }

        [ForeignKey(nameof(Character))]
        public Guid CharacterId { get; set; }

        public int TargetId { get; set; } // ID фракции, корпорации, персонажа
        public string TargetType { get; set; } = "Faction"; // Faction, Corporation, Character
        public float Standing { get; set; } = 0.0f; // -10 to 10

        public virtual Character Character { get; set; } = null!;
    }
}