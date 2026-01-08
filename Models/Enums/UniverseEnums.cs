namespace Echoes.API.Models.Enums
      
{
    public enum RegionType

    {
        Empire = 1,      // High security (0.5-1.0)
        LowSec = 2,      // Low security (0.1-0.4)
        NullSec = 3,     // Null security (-1.0 - 0.0)
        Wormhole = 4,    // Wormhole space
        Pochven = 5,     // Special region like Triglavian space
    }

    /// <summary>
    /// Состав атмосферы
    /// </summary>
    public enum AtmosphereType
    {
        None = 0,           // Нет атмосферы
        NitrogenOxygen = 1, // Азотно-кислородная (Земная)
        CarbonDioxide = 2,  // Углекислый газ (Венера/Марс)
        HydrogenHelium = 3, // Водородно-гелиевая (Газовые гиганты)
        Methane = 4,        // Метановая (Титан)
        Ammonia = 5,        // Аммиачная
        SulfurDioxide = 6,  // Сернистый газ (Вулканическая)
        Toxic = 7,          // Токсичная смесь
        Corrosive = 8       // Коррозийная
    }
    /// <summary>
    /// Статус безопасности региона
    /// </summary>

    public enum SecurityStatus
    {
        NullSec = -1,
        LowSec = 0,
        HighSec = 1
    }
    /// <summary>
    /// Эффекты солнечной системы
    /// </summary>
    public enum SolarSystemEffect
    {
        None = 0,
        BlackHole = 1,
        RedGiant = 2,
        NeutronStar = 3,
        Pulsar = 4,
        WolfRayet = 5,
        Magnetar = 6,
        CataclysmicVariable = 7
    }
    
    /// <summary>
    /// Тип планеты
    /// </summary>  
    public enum PlanetType
    {
        Barren = 1,
        Gas = 2,
        Ice = 3,
        Lava = 4,
        Oceanic = 5,
        Plasma = 6,
        Storm = 7,
        Temperate = 8
    }
    /// <summary>
    /// Размер врата
    /// </summary>
    public enum StargateSize
    {
        Small = 1,      // Frigates, destroyers
        Medium = 2,     // Cruisers, battlecruisers
        Large = 3,      // Battleships
        XLarge = 4,     // Capital ships
        XXLarge = 5     // Supercapitals
    }
    /// <summary>
    /// Тип локации игрока
    /// </summary>
    public enum LocationType
    {
        InSpace = 0,    // В космосе (на корабле)
        Docked = 1,     // Пристыкован к станции
        InWarp = 2,     // В варпе
        Jumping = 3,    // Прыгает через врата
        Cyno = 4,       // В циносфере
        Cloaked = 5,    // Замаскирован
        Dead = 6,       // Мёртв (в клоне)
    }
    public enum AnomalyType
    {
        /// <summary>
        /// Боевая аномалия (NPC пираты)
        /// </summary>
        Combat = 1,

        /// <summary>
        /// Рудная аномалия (добыча руды)
        /// </summary>
        Ore = 2,

        /// <summary>
        /// Дата-аномалия (сканирование, хакерство)
        /// </summary>
        Data = 3,

        /// <summary>
        /// Реликтовая аномалия (артефакты, редкие ресурсы)
        /// </summary>
        Relic = 4,

        /// <summary>
        /// Газовая аномалия (добыча газа)
        /// </summary>
        Gas = 5,

        /// <summary>
        /// Экспедиционная аномалия (продвинутый PvE)
        /// </summary>
        Expedition = 6
    }

    /// <summary>
    /// Сложность аномалии
    /// </summary>
    public enum AnomalyDifficulty
    {
        /// <summary>
        /// Легкая (новичок)
        /// </summary>
        Easy = 1,

        /// <summary>
        /// Средняя (опытный игрок)
        /// </summary>
        Medium = 2,

        /// <summary>
        /// Сложная (группа игроков)
        /// </summary>
        Hard = 3,

        /// <summary>
        /// Элитная (эскадра)
        /// </summary>
        Elite = 4
    }

    /// <summary>
    /// Размер корабля, который может пройти через вормхол
    /// </summary>
    public enum WormholeShipSize
    {
        /// <summary>
        /// Малый (фрегаты, эсминцы)
        /// </summary>
        Small = 1,

        /// <summary>
        /// Средний (крейсеры, хэви-крейсеры)
        /// </summary>
        Medium = 2,

        /// <summary>
        /// Крупный (линкоры, дредноуты)
        /// </summary>
        Large = 3,

        /// <summary>
        /// Капитальный (титаны, суперкариеры)
        /// </summary>
        Capital = 4
    }

    /// <summary>
    /// Класс вормхола (определяет стабильность и свойства)
    /// </summary>
    public enum WormholeClass
    {
        /// <summary>
        /// Класс 1 (вход в high-sec)
        /// </summary>
        C1 = 1,

        /// <summary>
        /// Класс 2 (средняя сложность)
        /// </summary>
        C2 = 2,

        /// <summary>
        /// Класс 3 (сложные)
        /// </summary>
        C3 = 3,

        /// <summary>
        /// Класс 4 (очень сложные)
        /// </summary>
        C4 = 4,

        /// <summary>
        /// Класс 5 (элитные)
        /// </summary>
        C5 = 5,

        /// <summary>
        /// Класс 6 (сверхэлитные)
        /// </summary>
        C6 = 6,

        /// <summary>
        /// Специальный класс (выходные вормхолы)
        /// </summary>
        K162 = 7
    }
}
