using Echoes.API.Models.Entities.Universe;
using System.Text.Json.Serialization;
using static Echoes.API.Models.Entities.Universe.UniverseGenerationConfig;

namespace Echoes.API.Models.Config
{
    public class UniverseConfig
    {
        // Звезды
        public StarConfig StarConfig { get; set; } = new();
        // Основные настройки
        public int RegionCount { get; set; } = 50;
        public int MinConstellationsPerRegion { get; set; } = 20;
        public int MaxConstellationsPerRegion { get; set; } = 100;

        // Системы
        public int MinSystemsPerConstellation { get; set; } = 30;
        public int MaxSystemsPerConstellation { get; set; } = 200;

        // Планеты
        public int MinPlanetsPerSystem { get; set; } = 5;
        public int MaxPlanetsPerSystem { get; set; } = 50;

        // Станции
        public StationConfig StationConfig { get; set; } = new();

        // Врата
        public StargateConfig StargateConfig { get; set; } = new();

        // Размеры вселенной
        public UniverseSizeConfig SizeConfig { get; set; } = new();

        // Распределение типов регионов
        public RegionDistribution RegionDistribution { get; set; } = new();

        // Настройки имен и названий
        public NamingConfig NamingConfig { get; set; } = new();

        // Настройки ресурсов
        public ResourcesConfig ResourcesConfig { get; set; } = new();

        // Производительность
        public PerformanceConfig PerformanceConfig { get; set; } = new();

        // Фракции/империи
        public FactionsConfig FactionsConfig { get; set; } = new();

        public bool UseSeedBasedGeneration { get; set; }
        public string? Seed { get; set; }
        public string? SeedVersion { get; set; }
        public string? GeneratorVersion { get; set; }
        public bool ForceRegeneration { get; set; }
        // Аномалии и червоточины
        public AnomalyConfig? AnomalyConfig { get; set; }
        public WormholeConfig? WormholeConfig { get; set; }


    }


    public class StationConfig
    {
        public bool EnableStations { get; set; } = true;

        // Количество станций по уровню безопасности
        public int HighSecMinStations { get; set; } = 3;
        public int HighSecMaxStations { get; set; } = 10;
        public int MidSecMinStations { get; set; } = 1;
        public int MidSecMaxStations { get; set; } = 5;
        public int LowSecMinStations { get; set; } = 0;
        public int LowSecMaxStations { get; set; } = 3;
        public int NullSecMinStations { get; set; } = 0;
        public int NullSecMaxStations { get; set; } = 2;

        // Емкость станций
        public int MinDockingCapacity { get; set; } = 1000;
        public int MaxDockingCapacity { get; set; } = 10000;
    }

    public class StargateConfig
    {
        public bool EnableStargates { get; set; } = true;
        public int MinConnectionsPerSystem { get; set; } = 3;
        public int MaxConnectionsPerSystem { get; set; } = 10;
        public float OperationalRate { get; set; } = 0.95f;
        public string DefaultStargateModel { get; set; } = "Stargate_01";
        public bool EnableWormholes { get; internal set; }
    }

    public class UniverseSizeConfig
    {
        // Координаты в метрах
        public long RegionSpreadX { get; set; } = 10_000_000_000;
        public long RegionSpreadY { get; set; } = 10_000_000_000;
        public long RegionSpreadZ { get; set; } = 1_000_000_000;

        public long ConstellationSpread { get; set; } = 1_000_000_000;
        public long SystemSpread { get; set; } = 100_000_000;
        public long PlanetOrbitBase { get; set; } = 10_000_000;
        public long PlanetOrbitStep { get; set; } = 50_000_000;
    }

    public class RegionDistribution
    {
        public int EmpirePercent { get; set; } = 40;
        public int LowSecPercent { get; set; } = 30;
        public int NullSecPercent { get; set; } = 25;
        public int WormholePercent { get; set; } = 5;

        public float EmpireMinSecurity { get; set; } = 0.6f;
        public float EmpireMaxSecurity { get; set; } = 1.0f;
        public float LowSecMinSecurity { get; set; } = 0.1f;
        public float LowSecMaxSecurity { get; set; } = 0.6f;
        public float NullSecMinSecurity { get; set; } = -1.0f;
        public float NullSecMaxSecurity { get; set; } = 0.1f;
        public float WormholeSecurity { get; set; } = -0.5f;
    }

    public class NamingConfig
    {
        // Генерация имен регионов
        public List<string> RegionNamePrefixes { get; set; } = new()
        {
            "New ", "Old ", "Great ", "Prime ", "Alpha ", "Beta ", "Gamma ", "Delta ",
            "Upper ", "Lower ", "North ", "South ", "East ", "West ", "Central ", "Deep "
        };

        public List<string> RegionNameSuffixes { get; set; } = new()
        {
            " Region", " Sector", " Expanse", " Domain", " Territory", " Space",
            " Cluster", " Nebula", " Void", " Reach", " Frontier", " Expanse", " Wastes"
        };

        public List<string> RegionNameWords { get; set; } = new()
        {
            "Acheron", "Borealis", "Caelum", "Draco", "Eridanus", "Fornax",
            "Gemini", "Hydra", "Icarus", "Juno", "Kraken", "Lyra", "Mira",
            "Nyx", "Orion", "Pegasus", "Quasar", "Rigel", "Sirius", "Taurus",
            "Ursa", "Vega", "Wolf", "Xanadu", "Ymir", "Zenith",
            "Nova", "Supernova", "Pulsar", "Quasar", "Nebula", "Galaxy",
            "Stellar", "Cosmic", "Celestial", "Astral", "Void", "Abyss",
            "Echo", "Reverb", "Harmony", "Melody", "Chord", "Note",
            "Iron", "Steel", "Carbon", "Silicon", "Plasma", "Quantum"
        };

        // Генерация имен констелляций
        public List<string> ConstellationNamePrefixes { get; set; } = new()
        {
            "", "New ", "Old ", "Great ", "Lost ", "Forgotten ", "Ancient ",
            "Silent ", "Dark ", "Bright ", "Shining ", "Golden ", "Silver "
        };

        public List<string> ConstellationNameSuffixes { get; set; } = new()
        {
            " Cluster", " Group", " Assembly", " Formation", " Alignment",
            " Constellation", " Stars", " System", " Gathering"
        };

        public List<string> ConstellationNameWords { get; set; } = new()
        {
            "Dragon", "Phoenix", "Griffin", "Basilisk", "Chimera", "Leviathan",
            "Sphinx", "Minotaur", "Centaur", "Cyclops", "Hydra", "Kraken",
            "Oracle", "Prophet", "Seer", "Vision", "Dream", "Nightmare",
            "Guardian", "Protector", "Sentinel", "Warden", "Keeper", "Watcher",
            "Vortex", "Whirlpool", "Maelstrom", "Typhoon", "Hurricane", "Tempest",
            "Horizon", "Zenith", "Nadir", "Apex", "Vertex", "Pinnacle"
        };

        // Генерация имен систем
        public List<string> SystemNamePrefixes { get; set; } = new()
        {
            "", "New ", "Old ", "Upper ", "Lower ", "North ", "South ", "East ", "West ",
            "Great ", "Prime ", "Alpha ", "Beta ", "Gamma ", "Delta ", "Epsilon ", "Zeta ",
            "Major ", "Minor ", "Inner ", "Outer ", "Deep ", "Far ", "Near ", "Distant "
        };

        public List<string> SystemNameSuffixes { get; set; } = new()
        {
            "", " Prime", " Secundus", " Tertius", " Quarta", " Quintus",
            " System", " Star", " Sun", " World", " Colony", " Outpost",
            " Base", " Station", " Hub", " Center", " Point", " Terminus"
        };

        public List<string> SystemNameWords { get; set; } = new()
        {
            "Jita", "Amarr", "Dodixie", "Rens", "Hek", "Niarja", "Uedama",
            "Perimeter", "Rancer", "Tama", "Nourvakaiken", "Senda", "Maurasi",
            "Cistuvaert", "Algogille", "Akes", "Adirain", "Outart", "Esescama",
            "Abrat", "Odette", "Clellinon", "Akimamur", "Karan", "Nishah",
            "Mod", "Jonar", "Orvan", "Helu", "Roushzar", "Serren", "Hakisalki",
            "Arlulf", "Meimungen", "Half", "Ansila", "Hageken", "Aldali", "Tzvi"
        };

        // Станции
        public List<string> StationNamePrefixes { get; set; } = new()
        {
            "Central", "Main", "Orbital", "Deep Space", "Trade", "Military",
            "Research", "Industrial", "Mining", "Refinery", "Shipyard", "Citadel",
            "Fortress", "Outpost", "Colony", "Settlement", "Habitat", "Platform"
        };

        public List<string> StationNameSuffixes { get; set; } = new()
        {
            " Station", " Hub", " Complex", " Base", " Terminal", " Port",
            " Depot", " Yard", " Facility", " Center", " Nexus", " Gateway",
            " Anchor", " Beacon", " Relay", " Array", " Tower"
        };

        public List<string> StationNameWords { get; set; } = new()
        {
            "Perim", "Trade", "4-4", "Jita", "Amarr", "Dodixie", "Rens",
            "Hek", "Tash-Murkon", "Caldari", "Gallente", "Minmatar", "Amarr",
            "Concord", "Navy", "Corp", "Mercenary", "Pioneer", "Explorer"
        };

        // Планеты
        public List<string> PlanetNamePrefixes { get; set; } = new()
        {
            "", "New ", "Old ", "Great ", "Big ", "Small ", "Distant ", "Near ",
            "Alpha ", "Beta ", "Gamma ", "Delta ", "Prime ", "Second ", "Third "
        };

        public List<string> PlanetNameSuffixes { get; set; } = new()
        {
            "", " I", " II", " III", " IV", " V", " VI", " VII", " VIII", " IX", " X",
            " Prime", " Secundus", " Major", " Minor", " A", " B", " C", " D"
        };

        public List<string> PlanetNameWords { get; set; } = new()
        {
            "Terra", "Gaia", "Eden", "Arcadia", "Avalon", "Camelot", "Olympus",
            "Valhalla", "Nirvana", "Shangri-La", "Utopia", "Dystopia", "Pandora",
            "Vulcan", "Mercury", "Venus", "Mars", "Jupiter", "Saturn", "Uranus",
            "Neptune", "Pluto", "Charon", "Titan", "Europa", "Io", "Ganymede",
            "Callisto", "Triton", "Oberon", "Titania", "Rhea", "Iapetus", "Miranda"
        };

        // Типы планет (описания)
        public List<string> PlanetTypes { get; set; } = new()
        {
            "Barren", "Gas Giant", "Ice", "Lava", "Oceanic", "Plasma", "Storm",
            "Temperate", "Toxic", "Volcanic", "Desert", "Arid", "Tundra", "Jungle",
            "Terrestrial", "Rocky", "Metallic", "Crystalline", "Fungal", "Swamp"
        };

        // Луны
        public List<string> MoonNameSuffixes { get; set; } = new()
        {
            " Moon", " Satellite", " Companion", " - Moon 1", " - Moon 2", " - Moon 3",
            " - Moon 4", " - Moon 5", " - Moon 6", " - Moon 7", " - Moon 8", " - Moon 9"
        };
    }

    public class ResourcesConfig
    {
        public bool EnableResources { get; set; } = true;

        public List<ResourceTypeConfig> ResourceTypes { get; set; } = new()
        {
            new ResourceTypeConfig { Name = "Tritanium", BaseAmount = 10000, Rarity = 0.8f, Color = "#4A90E2" },
            new ResourceTypeConfig { Name = "Pyerite", BaseAmount = 5000, Rarity = 0.6f, Color = "#FFD700" },
            new ResourceTypeConfig { Name = "Mexallon", BaseAmount = 3000, Rarity = 0.4f, Color = "#C0C0C0" },
            new ResourceTypeConfig { Name = "Isogen", BaseAmount = 1000, Rarity = 0.3f, Color = "#00FF00" },
            new ResourceTypeConfig { Name = "Nocxium", BaseAmount = 500, Rarity = 0.2f, Color = "#FF4500" },
            new ResourceTypeConfig { Name = "Zydrine", BaseAmount = 200, Rarity = 0.1f, Color = "#8A2BE2" },
            new ResourceTypeConfig { Name = "Megacyte", BaseAmount = 100, Rarity = 0.05f, Color = "#DC143C" },
            new ResourceTypeConfig { Name = "Morphite", BaseAmount = 50, Rarity = 0.02f, Color = "#FF1493" },
            new ResourceTypeConfig { Name = "Helium", BaseAmount = 50000, Rarity = 0.9f, Color = "#87CEEB" },
            new ResourceTypeConfig { Name = "Hydrogen", BaseAmount = 80000, Rarity = 0.95f, Color = "#ADD8E6" }
        };

        public List<string> AsteroidBeltNames { get; set; } = new()
        {
            "Asteroid Belt Alpha", "Asteroid Belt Beta", "Asteroid Belt Gamma",
            "Asteroid Belt Delta", "Asteroid Belt Epsilon", "Asteroid Belt Zeta",
            "Asteroid Field", "Rocks", "Debris Field", "Ore Cluster",
            "Mining Zone", "Resource Rich Area", "Asteroid Cluster"
        };

        public int MinAsteroidBeltsPerSystem { get; set; } = 0;
        public int MaxAsteroidBeltsPerSystem { get; set; } = 10;
        public int MinResourcesPerBelt { get; set; } = 3;
        public int MaxResourcesPerBelt { get; set; } = 10;
    }

    public class ResourceTypeConfig
    {
        public string Name { get; set; } = "";
        public string DisplayName { get; set; } = "";
        public string Description { get; set; } = "";
        public int BaseAmount { get; set; } = 1000;
        public float Rarity { get; set; } = 0.5f; // 0-1
        public string Color { get; set; } = "#FFFFFF";
        public bool IsGas { get; set; } = false;
        public bool IsOre { get; set; } = true;
        public bool IsIce { get; set; } = false;

        [JsonIgnore]
        public string FullName => string.IsNullOrEmpty(DisplayName) ? Name : DisplayName;
    }

    public class PerformanceConfig
    {
        public bool EnableProgressLogging { get; set; } = true;
        public int LogProgressNRegions { get; set; } = 5;
        public int LogProgressEveryNConstellations { get; set; } = 100;
        public int LogProgressEveryNSystems { get; set; } = 1000;
        public bool UseBatchSaving { get; set; } = true;
        public int BatchSize { get; set; } = 1000;
        public int SaveCheckpointEvery { get; set; } = 10000;
        public bool UseParallelProcessing { get; set; } = false;
    }

    public class FactionsConfig
    {
        public List<FactionConfig> Factions { get; set; } = new()
        {
            new FactionConfig
            {
                Id = 1,
                Name = "Caldari State",
                Description = "Corporation-driven militaristic faction",
                Color = "#1E90FF",
                HomeRegionName = "The Forge",
                SecurityBonus = 0.1f
            },
            new FactionConfig
            {
                Id = 2,
                Name = "Gallente Federation",
                Description = "Democratic and innovative faction",
                Color = "#32CD32",
                HomeRegionName = "Essence",
                SecurityBonus = 0.05f
            },
            new FactionConfig
            {
                Id = 3,
                Name = "Amarr Empire",
                Description = "Religious and traditionalist faction",
                Color = "#FFD700",
                HomeRegionName = "Domain",
                SecurityBonus = 0.15f
            },
            new FactionConfig
            {
                Id = 4,
                Name = "Minmatar Republic",
                Description = "Nomadic and resilient faction",
                Color = "#DC143C",
                HomeRegionName = "Heimatar",
                SecurityBonus = -0.05f
            },
            new FactionConfig
            {
                Id = 5,
                Name = "Pirate Factions",
                Description = "Various outlaw groups",
                Color = "#8B0000",
                HomeRegionName = null,
                SecurityBonus = -0.3f
            }
        };

        public bool AssignFactionsToRegions { get; set; } = true;
        public float FactionInfluenceRadius { get; set; } = 0.7f;
    }

    public class FactionConfig
    {
        public int Id { get; set; }
        public string Name { get; set; } = "";
        public string Description { get; set; } = "";
        public string Color { get; set; } = "#FFFFFF";
        public string? HomeRegionName { get; set; }
        public float SecurityBonus { get; set; } = 0.0f;
    }
    public class StarConfig
    {
        public bool EnableStarVariety { get; set; } = true;

        // Распределение звездных классов (в процентах)
        public StarClassDistribution ClassDistribution { get; set; } = new();

        // Множители для игры
        public StarEffectMultipliers EffectMultipliers { get; set; } = new();

        // Настройки визуализации
        public StarVisualConfig VisualConfig { get; set; } = new();
    }

    public class StarClassDistribution
    {
        public float ClassO_Percent { get; set; } = 0.00003f;    // 0.00003%
        public float ClassB_Percent { get; set; } = 0.13f;       // 0.13%
        public float ClassA_Percent { get; set; } = 0.6f;        // 0.6%
        public float ClassF_Percent { get; set; } = 3.0f;        // 3%
        public float ClassG_Percent { get; set; } = 7.6f;        // 7.6% (Солнце)
        public float ClassK_Percent { get; set; } = 12.1f;       // 12.1%
        public float ClassM_Percent { get; set; } = 76.45f;      // 76.45%
        public float BrownDwarf_Percent { get; set; } = 0.1f;    // 0.1%
        public float WhiteDwarf_Percent { get; set; } = 0.01f;   // 0.01%
        public float NeutronStar_Percent { get; set; } = 0.001f; // 0.001%
        public float BlackHole_Percent { get; set; } = 0.0001f;  // 0.0001%
        public float Giant_Percent { get; set; } = 0.01f;        // 0.01%

        public List<string> SpecialStarNames { get; set; } = new()
    {
        "Pulsar", "Quasar", "Magnetar", "Wolf-Rayet", "Carbon Star",
        "T Tauri", "Herbig Ae/Be", "FU Orionis", "R Coronae Borealis"
    };
    }

    public class StarEffectMultipliers
    {
        // Влияние на планетную систему
        public float ClassO_PlanetChance { get; set; } = 0.1f;   // Мало планет
        public float ClassG_PlanetChance { get; set; } = 0.8f;   // Оптимально для планет
        public float ClassM_PlanetChance { get; set; } = 0.6f;   // Умеренный шанс

        // Влияние на ресурсы
        public float MetalRichMultiplier { get; set; } = 2.0f;   // Металлические звезды
        public float GasRichMultiplier { get; set; } = 3.0f;     // Газовые гиганты рядом
        public float IceRichMultiplier { get; set; } = 1.5f;     // Ледяные миры

        // Влияние на опасность
        public float RadiationMultiplier { get; set; } = 5.0f;   // Радиация от нейтронных звезд
        public float GravityMultiplier { get; set; } = 10.0f;    // Гравитация черных дыр
        public float HeatMultiplier { get; set; } = 8.0f;        // Жара от голубых гигантов
    }

    public class StarVisualConfig
    {
        // Цвета звезд по классам
        public Dictionary<string, string> StarColors { get; set; } = new()
        {
            ["O"] = "#9BB0FF", // Голубой
            ["B"] = "#AABFFF", // Бело-голубой
            ["A"] = "#CAD7FF", // Белый
            ["F"] = "#F8F7FF", // Желто-белый
            ["G"] = "#FFF4EA", // Желтый (Солнце)
            ["K"] = "#FFD2A1", // Оранжевый
            ["M"] = "#FFCC6F", // Красный
            ["L"] = "#FF8C6F", // Красноватый
            ["T"] = "#FF6B6B", // Красный (коричневый карлик)
            ["Y"] = "#FF4D4D", // Темно-красный
            ["WhiteDwarf"] = "#FFFFFF", // Белый
            ["NeutronStar"] = "#00FFFF", // Голубоватый
            ["BlackHole"] = "#000000", // Черный (аккреционный диск)
            ["RedGiant"] = "#FF6B6B", // Красный
            ["BlueGiant"] = "#4D79FF"  // Голубой
        };

        // Размеры звезд (относительно Солнца)
        public Dictionary<string, float> StarSizes { get; set; } = new()
        {
            ["O"] = 6.6f,
            ["B"] = 3.8f,
            ["A"] = 1.7f,
            ["F"] = 1.3f,
            ["G"] = 1.0f,
            ["K"] = 0.8f,
            ["M"] = 0.4f,
            ["WhiteDwarf"] = 0.01f,
            ["NeutronStar"] = 0.00001f,
            ["RedGiant"] = 100.0f,
            ["BlueGiant"] = 25.0f
        };

        // Эффекты для UE5
        public bool EnableLensFlare { get; set; } = true;
        public bool EnableCorona { get; set; } = true;
        public bool EnableSolarFlares { get; set; } = true;
        public float BaseBrightness { get; set; } = 1.0f;
    }
    // === ДОБАВИТЬ ЭТО В КОНЕЦ ФАЙЛА (перед закрывающей скобкой namespace) ===

    public class AnomalyConfig
    {
        public bool EnableAnomalies { get; set; } = true;
        public int MinPerSystem { get; set; } = 2;
        public int MaxPerSystem { get; set; } = 8;
        public int LifetimeHours { get; set; } = 24;
        public double MinDistanceFromCenterAU { get; set; } = 20;
        public double MaxDistanceFromCenterAU { get; set; } = 60;
        public double MinDistanceBetweenAnomaliesAU { get; set; } = 2;

        public Dictionary<string, double> TypeChances { get; set; } = new();
        public Dictionary<string, Dictionary<string, double>> DifficultyBySecurity { get; set; } = new();

        public List<string> CombatNamePrefixes { get; set; } = new();
        public List<string> CombatNameSuffixes { get; set; } = new();
    }

    public class WormholeConfig
    {
        public bool EnableWormholes { get; set; } = true;
        public double ChancePerSystem { get; set; } = 0.3;
        public double MinDistanceLightYears { get; set; } = 10;
        public double MaxDistanceLightYears { get; set; } = 500;

        public Dictionary<string, double> ClassChances { get; set; } = new();
        public Dictionary<string, double> MassByClass { get; set; } = new();
        public Dictionary<string, int> LifetimeHoursByClass { get; set; } = new();
        public Dictionary<string, string> MaxShipSizeByClass { get; set; } = new();
        public Dictionary<string, List<string>> NamesByClass { get; set; } = new();
    }
}

