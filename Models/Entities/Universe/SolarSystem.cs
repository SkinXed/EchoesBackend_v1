using Echoes.API.Models.Entities.GameServer;
using Echoes.API.Models.Enums;
using Echoes.Server.Models.Entities.Universe;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Echoes.API.Models.Entities.Universe
{
    [Table("SolarSystems")]
    public class SolarSystem : BaseEntity
    {
        public Guid Id { get; set; } // Добавьте это свойство
        [Required]
        [MaxLength(200)]
        public string Name { get; set; }

        [ForeignKey("Constellation")]
        public Guid ConstellationId { get; set; }

        [Range(-1.0f, 1.0f)]
        public float SecurityStatus { get; set; }
        public bool IsActive { get; set; } = true;
        public long PositionX { get; set; }
        public long PositionY { get; set; }
        public long PositionZ { get; set; }

        // Звездные характеристики
        public StarClass StarClass { get; set; } = StarClass.G;
        public StarLuminosityClass LuminosityClass { get; set; } = StarLuminosityClass.V;
        public StarTemperature TemperatureClass { get; set; } = StarTemperature.Moderate;

        [Range(1000, 50000)]
        public int Temperature { get; set; } = 5778; // K (температура Солнца)

        [Range(0.1f, 1000.0f)]
        public float SolarRadius { get; set; } = 1.0f; // Относительно радиуса Солнца

        [Range(0.01f, 100.0f)]
        public float SolarMass { get; set; } = 1.0f; // Относительно массы Солнца

        [Range(0.001f, 1000000.0f)]
        public float Luminosity { get; set; } = 1.0f; // Относительно светимости Солнца

        [Range(0, 10)]
        public int NumberOfStars { get; set; } = 1;

        // Другие поля
        public long Radius { get; set; } = 10_000_000; // 10 млн км
        public int? FactionId { get; set; }
        public bool HasAsteroidBelts { get; set; } = true;
        public bool HasStations { get; set; } = true;

        [MaxLength(1000)]
        public string Description { get; set; }

       // public DateTime CreatedAt { get; set; } = DateTime.UtcNow;

        // Навигационные свойства
        public virtual Constellation Constellation { get; set; }
        public virtual ICollection<Planet> Planets { get; set; } = new List<Planet>();
        public virtual ICollection<Station> Stations { get; set; } = new List<Station>();
        public virtual ICollection<Stargate> Stargates { get; set; } = new List<Stargate>();
        public virtual ICollection<AsteroidBelt> AsteroidBelts { get; set; } = new List<AsteroidBelt>();
        // Аномалии в этой системе
        public virtual ICollection<Anomaly> Anomalies { get; set; } = new List<Anomaly>();

        // Вормхолы, исходящие ИЗ этой системы
        public virtual ICollection<Wormhole> SourceWormholes { get; set; } = new List<Wormhole>();

        // Вормхолы, ведущие В эту систему
        public virtual ICollection<Wormhole> TargetWormholes { get; set; } = new List<Wormhole>();
        public Guid RegionId { get; set; }

        public virtual GameServerNode? PrimaryServer { get; set; }
    }
}