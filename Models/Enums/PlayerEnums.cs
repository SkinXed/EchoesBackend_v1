namespace Nebula.Inventory.API.Models.Enums
{
    /// <summary>
    /// Расы персонажей
    /// </summary>
    public enum PlayerRace : int
    {
        Amarr = 0,
        Caldari = 1,
        Gallente = 2,
        Minmatar = 3,
        Jove = 4,
        Pirate = 5,
        CONCORD = 6
    }
    
    /// <summary>
    /// Корпорации/Фракции
    /// </summary>
    public enum PlayerFaction : int
    {
        Neutral = 0,
        AmarrEmpire = 1,
        CaldariState = 2,
        GallenteFederation = 3,
        MinmatarRepublic = 4,
        AngelCartel = 101,
        BloodRaiders = 102,
        Guristas = 103,
        SanshasNation = 104,
        Serpentis = 105,
        Sleepers = 106,
        RogueDrones = 107,
        CONCORD = 201,
        SistersOfEVE = 202
    }
    
    /// <summary>
    /// Статус безопасности игрока
    /// </summary>
    public enum PlayerSecurityStatus : int
    {
        Criminal = -10,     // -10.0 и ниже
        VeryLow = -5,      // -5.0 до -9.9
        Low = -1,          // -1.0 до -4.9
        Neutral = 0,       // -0.9 до 0.9
        Positive = 1,      // 1.0 до 4.9
        Good = 5,          // 5.0 и выше
        HighSecOnly = 10   // 10.0 (только хайсек)
    }
    
    /// <summary>
    /// Типы валюты
    /// </summary>
    public enum CurrencyType : int
    {
        ISK = 0,           // Основная валюта
        PLEX = 1,          // PLEX (30 дней игры)
        Aurum = 2,         // Премьер валюта
        LoyaltyPoints = 3, // Очки лояльности
        SkillPoints = 4,   // Очки навыков
        ResearchPoints = 5 // Очки исследования
    }
    
    /// <summary>
    /// Типы навыков
    /// </summary>
    public enum SkillType : int
    {
        Standard = 0,      // Обычные навыки
        Fleet = 1,         // Флотские навыки
        Corporation = 2,   // Корпоративные
        Specialization = 3, // Специализация
        Capital = 4,       // Капитальные корабли
        Subsystem = 5,     // Субсистемы
        Implant = 6        // Импланты
    }
    
    /// <summary>
    /// Группы навыков
    /// </summary>
    public enum SkillGroup : int
    {
        // Боевые
        Gunnery = 0,
        Missiles = 1,
        Drones = 2,
        Navigation = 3,
        Targeting = 4,
        
        // Инженерные
        Engineering = 10,
        Electronics = 11,
        Mechanics = 12,
        Shield = 13,
        Armor = 14,
        
        // Корабли
        SpaceshipCommand = 20,
        Frigate = 21,
        Cruiser = 22,
        Battleship = 23,
        Industrial = 24,
        Capital = 25,
        
        // Производство
        Industry = 30,
        Science = 31,
        Research = 32,
        
        // Социальные
        Social = 40,
        Trade = 41,
        CorporationManagement = 42
    }
    
    /// <summary>
    /// Уровни навыков (0-5)
    /// </summary>
    public enum SkillLevel : int
    {
        Level0 = 0,
        Level1 = 1,
        Level2 = 2,
        Level3 = 3,
        Level4 = 4,
        Level5 = 5
    }
    
    /// <summary>
    /// Типы имплантов
    /// </summary>
    public enum ImplantType : int
    {
        Cybernetic = 0,    // Кибернетика
        Booster = 1,       // Бустеры
        Neural = 2,        // Нейро-импланты
        Clone = 3,         // Клоновые
        Omega = 4          // Омега-импланты
    }
    
    /// <summary>
    /// Слоты имплантов
    /// </summary>
    public enum ImplantSlot : int
    {
        Slot1 = 0,    // Перцепция
        Slot2 = 1,    // Память
        Slot3 = 2,    // Воля
        Slot4 = 3,    // Интеллект
        Slot5 = 4,    // Харизма
        Slot6 = 5,    // Омега-слот
        Slot7 = 6,    // High-grade слот
        Slot8 = 7,    // Low-grade слот
        Slot9 = 8,    // Миди-слот
        Slot10 = 9    // Special слот
    }
    
    /// <summary>
    /// Типы клонов
    /// </summary>
    public enum CloneType : int
    {
        Alpha = 0,         // Альфа-клон (бесплатный)
        Omega = 1,         // Омега-клон (подписка)
        Medical = 2,       // Медицинский клон
        JumpClone = 3,     // Прыжковый клон
        Special = 4        // Специальный клон
    }
    
    /// <summary>
    /// Атрибуты персонажа
    /// </summary>
    public enum CharacterAttribute : int
    {
        Perception = 0,    // Перцепция
        Memory = 1,        // Память
        Willpower = 2,     // Воля
        Intelligence = 3,  // Интеллект
        Charisma = 4       // Харизма
    }
    
    /// <summary>
    /// Направления тренировки навыков
    /// </summary>
    public enum TrainingQueueStatus : int
    {
        Waiting = 0,
        Training = 1,
        Paused = 2,
        Completed = 3,
        Cancelled = 4
    }
}
