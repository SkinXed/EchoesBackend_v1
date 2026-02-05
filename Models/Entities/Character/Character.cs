using Echoes.API.Models.Entities.Inventory;
using Echoes.API.Models.Entities.Universe;
using Echoes.API.Models.Enums;
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
        [Column("faction_id")]
        [ForeignKey(nameof(Faction))]
        public int FactionId { get; set; }
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
        
        /// <summary>
        /// Home station ID where character spawns by default (assigned based on race)
        /// </summary>
        [ForeignKey("HomeStationId")]
        public Guid? HomeStationId { get; set; }

        // Настройки
        public string SettingsJson { get; set; } = "{}";

        // Флаги
        public bool IsMain { get; set; } = true;
        public bool IsOnline { get; set; } = false;
        public bool IsDocked { get; set; } = true;
        public bool InWarp { get; set; } = false;
        
        // Дополнительные атрибуты персонажа (EVE Online)
        public int Perception { get; set; } = 20;
        public int Memory { get; set; } = 20;
        public int Willpower { get; set; } = 20;
        public int Intelligence { get; set; } = 20;
        public int Charisma { get; set; } = 20;
        
        // Статистика
        public decimal TotalISKEarned { get; set; } = 0;
        public decimal TotalISKLost { get; set; } = 0;
        public int TotalShipsDestroyed { get; set; } = 0;
        public int TotalShipsLost { get; set; } = 0;
        public int TotalKills { get; set; } = 0;
        public int TotalDeaths { get; set; } = 0;
        
        // Клоны
        public Guid? ActiveCloneId { get; set; }
        public int JumpCloneCount { get; set; } = 0;
        public int MaxJumpClones { get; set; } = 1;
        
        // Статус
        public DateTime? LastLogin { get; set; }
        public DateTime? LastLogout { get; set; }
        public long TotalPlayTimeSeconds { get; set; } = 0;

        // Навигационные свойства
        public virtual Account Account { get; set; } = null!;
        public virtual Faction Faction { get; set; } = null!;
        public virtual CharacterLocation? CurrentLocation { get; set; }
        public virtual InventoryItem? ActiveShip { get; set; }
        public virtual ICollection<CharacterSkill> Skills { get; set; } = new List<CharacterSkill>();
        public virtual ICollection<InventoryItem> InventoryItems { get; set; } = new List<InventoryItem>();
        public virtual ICollection<CharacterImplant> Implants { get; set; } = new List<CharacterImplant>();
        public virtual ICollection<CharacterStanding> Standings { get; set; } = new List<CharacterStanding>();
        
        // Новые навигационные свойства для расширенных функций
        public virtual ICollection<CharacterWallet> Wallets { get; set; } = new List<CharacterWallet>();
        public virtual ICollection<CharacterSkillEnhanced> SkillsEnhanced { get; set; } = new List<CharacterSkillEnhanced>();
        public virtual ICollection<CharacterImplantEnhanced> ImplantsEnhanced { get; set; } = new List<CharacterImplantEnhanced>();
        public virtual ICollection<CharacterClone> Clones { get; set; } = new List<CharacterClone>();
        public virtual ICollection<TrainingQueue> TrainingQueues { get; set; } = new List<TrainingQueue>();
        public virtual ICollection<CharacterContract> IssuedContracts { get; set; } = new List<CharacterContract>();
        
        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;
        //public virtual ICollection<Corporation.Corporation>? Corporations { get; set; } // Если CEO
        
        // Методы
        public int GetAttribute(CharacterAttribute attribute)
        {
            return attribute switch
            {
                CharacterAttribute.Perception => Perception,
                CharacterAttribute.Memory => Memory,
                CharacterAttribute.Willpower => Willpower,
                CharacterAttribute.Intelligence => Intelligence,
                CharacterAttribute.Charisma => Charisma,
                _ => 0
            };
        }
        
        public void SetAttribute(CharacterAttribute attribute, int value)
        {
            switch (attribute)
            {
                case CharacterAttribute.Perception:
                    Perception = Math.Clamp(value, 1, 50);
                    break;
                case CharacterAttribute.Memory:
                    Memory = Math.Clamp(value, 1, 50);
                    break;
                case CharacterAttribute.Willpower:
                    Willpower = Math.Clamp(value, 1, 50);
                    break;
                case CharacterAttribute.Intelligence:
                    Intelligence = Math.Clamp(value, 1, 50);
                    break;
                case CharacterAttribute.Charisma:
                    Charisma = Math.Clamp(value, 1, 50);
                    break;
            }
        }
        
        public decimal GetTotalWalletBalance()
        {
            return Wallets?.Sum(w => w.Balance) ?? 0;
        }
        
        public decimal GetWalletBalance(CurrencyType currencyType)
        {
            return Wallets?.FirstOrDefault(w => w.CurrencyType == currencyType)?.Balance ?? 0;
        }
        
        public bool CanAfford(decimal amount, CurrencyType currencyType = CurrencyType.ISK)
        {
            return GetWalletBalance(currencyType) >= amount;
        }
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