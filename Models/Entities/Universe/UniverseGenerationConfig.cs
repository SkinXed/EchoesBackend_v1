// UniverseGenerationConfig.cs
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Echoes.API.Models.Entities.Universe
{
    [Table("universe_generation_configs")]
    public class UniverseGenerationConfig
    {
        [Key]
        public Guid Id { get; set; }

        [Required]
        [MaxLength(255)]
        public string ConfigName { get; set; } = "default";

        [Required]
        [MaxLength(500)]
        public string Description { get; set; } = "Конфигурация генерации вселенной";

        [Required]
        [Column(TypeName = "jsonb")]
        public string ConfigJson { get; set; } = "{}";

        public string? UniverseSeed { get; set; }

        public bool UseSeedBasedGeneration { get; set; } = false;

        public int SeedVersion { get; set; } = 1;

        [Required]
        [MaxLength(50)]
        public string GeneratorVersion { get; set; } = "1.0.0";

        public bool IsPreset { get; set; } = true;

        public bool IsActive { get; set; } = false;

        public string? Tags { get; set; } // Например: "dev,test,small"

        public int RegionCount { get; set; }
        public int SystemCount { get; set; }
        public int PlanetCount { get; set; }
        /// <summary>
        /// Конфигурация генерации аномалий
        /// </summary>
        public AnomalyConfig Anomalies { get; set; } = new();

        /// <summary>
        /// Конфигурация генерации вормхолов
        /// </summary>
        public WormholeConfig Wormholes { get; set; } = new();

        /// <summary>
        /// Сид для генератора случайных чисел
        /// </summary>
        public int RandomSeed { get; set; } = Environment.TickCount;

        [MaxLength(50)]
        public string? PresetType { get; set; } // UltraSmall, Small, Medium, Large и т.д.

        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;
        public DateTime? LastUsedAt { get; set; }
        public int UsageCount { get; set; } = 0;

        // Статистика генерации
        public long? GenerationTimeMs { get; set; }
        public string? GenerationStats { get; set; } // JSON статистики

        // Связи
        public virtual ICollection<Region> Regions { get; set; } = new List<Region>();

        /// <summary>
        /// Константы для конвертации единиц измерения
        /// </summary>
        public class Constants
        {
            /// <summary>
            /// 1 Астрономическая единица в метрах
            /// </summary>
            public const long AU_TO_METERS = 149597870700L;

            /// <summary>
            /// 1 Световой год в метрах
            /// </summary>
            public const long LIGHTYEAR_TO_METERS = 9460730472580800L;
        }
    }
    /// <summary>
    /// Конфигурация генерации аномалий
    /// </summary>
    public class AnomalyConfig


    {
        /// <summary>
        /// Минимальное количество аномалий на систему
        /// </summary>
        public int MinPerSystem { get; set; } = 2;

        /// <summary>
        /// Максимальное количество аномалий на систему
        /// </summary>
        public int MaxPerSystem { get; set; } = 10;

        /// <summary>
        /// Шанс появления аномалии определенного типа
        /// Сумма всех значений должна быть 1.0
        /// </summary>
        public Dictionary<string, double> TypeChances { get; set; } = new()
        {
            { "Combat", 0.40 },   // 40% боевых
            { "Ore", 0.25 },      // 25% рудных
            { "Data", 0.15 },     // 15% дата
            { "Relic", 0.10 },    // 10% реликтовых
            { "Gas", 0.08 },      // 8% газовых
            { "Expedition", 0.02 } // 2% экспедиционных
        };

        /// <summary>
        /// Распределение сложности в зависимости от security статуса
        /// </summary>
        public Dictionary<string, Dictionary<string, double>> DifficultyBySecurity { get; set; } = new()
        {
            // HighSec (0.5 - 1.0)
            ["1.0"] = new() { { "Easy", 0.70 }, { "Medium", 0.25 }, { "Hard", 0.05 }, { "Elite", 0.00 } },
            ["0.9"] = new() { { "Easy", 0.65 }, { "Medium", 0.30 }, { "Hard", 0.05 }, { "Elite", 0.00 } },
            ["0.8"] = new() { { "Easy", 0.60 }, { "Medium", 0.35 }, { "Hard", 0.05 }, { "Elite", 0.00 } },
            ["0.7"] = new() { { "Easy", 0.55 }, { "Medium", 0.40 }, { "Hard", 0.05 }, { "Elite", 0.00 } },
            ["0.6"] = new() { { "Easy", 0.50 }, { "Medium", 0.45 }, { "Hard", 0.05 }, { "Elite", 0.00 } },
            ["0.5"] = new() { { "Easy", 0.45 }, { "Medium", 0.50 }, { "Hard", 0.05 }, { "Elite", 0.00 } },

            // LowSec (0.1 - 0.4)
            ["0.4"] = new() { { "Easy", 0.30 }, { "Medium", 0.55 }, { "Hard", 0.15 }, { "Elite", 0.00 } },
            ["0.3"] = new() { { "Easy", 0.20 }, { "Medium", 0.60 }, { "Hard", 0.20 }, { "Elite", 0.00 } },
            ["0.2"] = new() { { "Easy", 0.10 }, { "Medium", 0.60 }, { "Hard", 0.30 }, { "Elite", 0.00 } },
            ["0.1"] = new() { { "Easy", 0.05 }, { "Medium", 0.55 }, { "Hard", 0.40 }, { "Elite", 0.00 } },

            // NullSec (0.0 - -1.0)
            ["0.0"] = new() { { "Easy", 0.00 }, { "Medium", 0.40 }, { "Hard", 0.55 }, { "Elite", 0.05 } },
            ["-0.1"] = new() { { "Easy", 0.00 }, { "Medium", 0.35 }, { "Hard", 0.60 }, { "Elite", 0.05 } },
            ["-0.2"] = new() { { "Easy", 0.00 }, { "Medium", 0.30 }, { "Hard", 0.65 }, { "Elite", 0.05 } },
            ["-0.3"] = new() { { "Easy", 0.00 }, { "Medium", 0.25 }, { "Hard", 0.70 }, { "Elite", 0.05 } },
            ["-0.4"] = new() { { "Easy", 0.00 }, { "Medium", 0.20 }, { "Hard", 0.75 }, { "Elite", 0.05 } },
            ["-0.5"] = new() { { "Easy", 0.00 }, { "Medium", 0.15 }, { "Hard", 0.80 }, { "Elite", 0.05 } },
            ["-1.0"] = new() { { "Easy", 0.00 }, { "Medium", 0.10 }, { "Hard", 0.85 }, { "Elite", 0.05 } }
        };

        /// <summary>
        /// Минимальное расстояние от центра системы (в AU)
        /// </summary>
        public double MinDistanceFromCenterAU { get; set; } = 20.0;

        /// <summary>
        /// Максимальное расстояние от центра системы (в AU)
        /// </summary>
        public double MaxDistanceFromCenterAU { get; set; } = 50.0;

        /// <summary>
        /// Минимальное расстояние между аномалиями (в AU)
        /// </summary>
        public double MinDistanceBetweenAnomaliesAU { get; set; } = 5.0;

        /// <summary>
        /// Время жизни аномалии в часах
        /// </summary>
        public int LifetimeHours { get; set; } = 24;

        /// <summary>
        /// Префиксы для названий боевых аномалий
        /// </summary>
        public List<string> CombatNamePrefixes { get; set; } = new()
        {
            "Hidden", "Forgotten", "Secret", "Abandoned", "Dark",
            "Shadow", "Ghost", "Lost", "Ancient", "Cursed"
        };

        /// <summary>
        /// Суффиксы для названий боевых аномалий
        /// </summary>
        public List<string> CombatNameSuffixes { get; set; } = new()
        {
            "Guristas Base", "Sansha Nest", "Blood Raider Temple",
            "Angel Hideout", "Serpentis Lab", "Rogue Drone Hive",
            "Mercenary Camp", "Pirate Den", "Cultist Shrine", "Marauder Outpost"
        };
        public bool EnableAnomalies { get; internal set; }
    }

    /// <summary>
    /// Конфигурация генерации вормхолов
    /// </summary>
    public class WormholeConfig
    {
        /// <summary>
        /// Базовый шанс появления вормхола в системе
        /// </summary>
        public double ChancePerSystem { get; set; } = 0.05; // 5%

        /// <summary>
        /// Максимальное количество вормхолов в системе
        /// </summary>
        public int MaxPerSystem { get; set; } = 2;

        /// <summary>
        /// Минимальное расстояние между системами для вормхола (в световых годах)
        /// </summary>
        public double MinDistanceLightYears { get; set; } = 10.0;

        /// <summary>
        /// Максимальное расстояние между системами для вормхола (в световых годах)
        /// </summary>
        public double MaxDistanceLightYears { get; set; } = 1000.0;

        /// <summary>
        /// Шансы появления вормхолов разных классов
        /// </summary>
        public Dictionary<string, double> ClassChances { get; set; } = new()
        {
            { "C1", 0.35 },  // 35%
            { "C2", 0.25 },  // 25%
            { "C3", 0.15 },  // 15%
            { "C4", 0.10 },  // 10%
            { "C5", 0.08 },  // 8%
            { "C6", 0.05 },  // 5%
            { "K162", 0.02 } // 2% (выходные)
        };

        /// <summary>
        /// Масса вормхолов по классам (в мегатоннах)
        /// </summary>
        public Dictionary<string, double> MassByClass { get; set; } = new()
        {
            { "C1", 3000000.0 },   // 3M кг
            { "C2", 2000000.0 },   // 2M кг
            { "C3", 1500000.0 },   // 1.5M кг
            { "C4", 1000000.0 },   // 1M кг
            { "C5", 750000.0 },    // 750K кг
            { "C6", 500000.0 },    // 500K кг
            { "K162", 1000000.0 }  // 1M кг
        };

        /// <summary>
        /// Максимальный размер корабля по классам
        /// </summary>
        public Dictionary<string, string> MaxShipSizeByClass { get; set; } = new()
        {
            { "C1", "Large" },     // До линкоров
            { "C2", "Large" },
            { "C3", "Medium" },    // До крейсеров
            { "C4", "Medium" },
            { "C5", "Small" },     // До фрегатов
            { "C6", "Small" },
            { "K162", "Large" }    // Все размеры
        };

        /// <summary>
        /// Время жизни вормхолов в часах
        /// </summary>
        public Dictionary<string, int> LifetimeHoursByClass { get; set; } = new()
        {
            { "C1", 72 },   // 3 дня
            { "C2", 48 },   // 2 дня
            { "C3", 36 },   // 1.5 дня
            { "C4", 24 },   // 1 день
            { "C5", 16 },   // 16 часов
            { "C6", 12 },   // 12 часов
            { "K162", 48 }  // 2 дня
        };

        /// <summary>
        /// Имена вормхолов по классам
        /// </summary>
        public Dictionary<string, List<string>> NamesByClass { get; set; } = new()
        {
            { "C1", new List<string> { "U210", "B041", "N766", "Q003" } },
            { "C2", new List<string> { "L005", "M001", "H900", "Z142" } },
            { "C3", new List<string> { "V911", "T405", "R259", "P060" } },
            { "C4", new List<string> { "X702", "W237", "Y689", "A982" } },
            { "C5", new List<string> { "D364", "F175", "G845", "J521" } },
            { "C6", new List<string> { "K346", "S279", "C128", "E555" } },
            { "K162", new List<string> { "K162" } }
        };
        public bool EnableWormholes { get; internal set; }
    }
}

