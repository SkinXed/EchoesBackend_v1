using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using Echoes.API.Models.Enums; // ОБЯЗАТЕЛЬНО: Подключаем Enums

namespace Echoes.API.Models.Entities.Universe
{
    [Table("Planets")]
    public class Planet
    {
        [Key] // Явно указываем первичный ключ
        public Guid Id { get; set; }

        [Required]
        [MaxLength(200)]
        public string Name { get; set; } = string.Empty;

        [ForeignKey("SolarSystem")]
        public Guid SolarSystemId { get; set; }

        [MaxLength(50)]
        public string Type { get; set; } = string.Empty; // Можно переделать на Enum PlanetType, но пока пусть строка

        public long Radius { get; set; } = 1000; // км
        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;

        // === ИСПРАВЛЕННЫЕ ПОЛЯ ===
        public long OrbitDistance { get; set; } // Расстояние от звезды
        public long OrbitPeriod { get; set; } // Часы

        public bool HasAtmosphere { get; set; } = false;

        // Было object -> стало Enum
        public AtmosphereType AtmosphereType { get; set; } = AtmosphereType.None;

        public int Temperature { get; set; } = 20; // °C
        public float Gravity { get; set; } = 1.0f; // g

        public bool HasMoons { get; set; } = false;

        // Было object -> стало int
        public int MoonCount { get; set; } = 0;

        public bool IsColonizable { get; set; } = false;
        public int? FactionId { get; set; }

        [MaxLength(1000)]
        public string Description { get; set; } = string.Empty;

        // Координаты (Internal set можно оставить, если ты их задаешь только при генерации)
        public long PositionX { get; set; }
        public long PositionY { get; set; }
        public long PositionZ { get; set; }

        // Было object -> стало double (или float)
        // Используем double для массы (например, 1.0 = Земля, или в кг)
        public double Mass { get; set; }

        public bool HasRings { get; set; }

        // Навигационные свойства
        public virtual SolarSystem SolarSystem { get; set; } = null!;
        public virtual ICollection<Moon> Moons { get; set; } = new List<Moon>();
        public virtual ICollection<PlanetResource> Resources { get; set; } = new List<PlanetResource>();
    }
}