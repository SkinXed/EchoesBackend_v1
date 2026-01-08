using Echoes.API.Models.Enums;

namespace Echoes.API.Models.DTOs
{
    public class StarSystemDto
    {
        public Guid Id { get; set; }
        public string Name { get; set; }
        public float SecurityStatus { get; set; }
        public StarInfoDto StarInfo { get; set; }
        public SystemStatisticsDto Statistics { get; set; }
        public List<StargateDto> Stargates { get; set; }
        public List<StationDto> Stations { get; set; }
    }

    public class StarInfoDto
    {
        public StarClass StarClass { get; set; }
        public string StarClassDescription { get; set; }
        public StarLuminosityClass LuminosityClass { get; set; }
        public string LuminosityClassDescription { get; set; }
        public StarTemperature TemperatureClass { get; set; }
        public int Temperature { get; set; } // K
        public float SolarRadius { get; set; } // Относительно Солнца
        public float SolarMass { get; set; } // Относительно Солнца
        public float Luminosity { get; set; } // Относительно Солнца
        public int NumberOfStars { get; set; }
        public string Color { get; set; }
        public float SizeMultiplier { get; set; }

        // Для UE5
        public bool HasLensFlare { get; set; }
        public bool HasCorona { get; set; }
        public bool HasSolarFlares { get; set; }
        public float Brightness { get; set; }
    }

    public class SystemStatisticsDto
    {
        public int PlanetCount { get; set; }
        public int MoonCount { get; set; }
        public int AsteroidBeltCount { get; set; }
        public int StationCount { get; set; }
        public bool HasResources { get; set; }
        public bool IsColonizable { get; set; }
        public string Faction { get; set; }
        public float RadiationLevel { get; set; } // 0-1
        public float GravityLevel { get; set; }   // 0-1
        public float HeatLevel { get; set; }      // 0-1
    }

    public class StargateDto
    {
        public Guid Id { get; set; }
        public string Name { get; set; }
        public Guid DestinationSystemId { get; set; }
        public string DestinationSystemName { get; set; }
        public bool IsOperational { get; set; }
        public int JumpCost { get; set; }
    }

    public class StationDto
    {
        public Guid Id { get; set; }
        public string Name { get; set; }
        public string Type { get; set; }
        public int DockingCapacity { get; set; }
        public string Services { get; set; }
        public bool IsOperational { get; set; }
    }

    public class StarClassInfoDto
    {
        public StarClass StarClass { get; set; }
        public string Name { get; set; }
        public string Description { get; set; }
        public string Color { get; set; }
        public float TypicalTemperature { get; set; } // K
        public float TypicalMass { get; set; } // Солнечные массы
        public float TypicalRadius { get; set; } // Солнечные радиусы
        public float TypicalLuminosity { get; set; } // Относительно Солнца
        public float Rarity { get; set; } // Процент от всех звезд
        public float PlanetChance { get; set; } // Шанс образования планет
        public string[] NotableSystems { get; set; }
    }
}