using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Echoes.API.Models.Entities.Universe
{
    [Table("AsteroidBelts")]
    public class AsteroidBelt 
    {
        [Required]
        [MaxLength(200)]
        public string Name { get; set; }
        public Guid Id { get; set; }
        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;
        [ForeignKey("SolarSystem")]
        public Guid SolarSystemId { get; set; }

        public long PositionX { get; set; }
        public long PositionY { get; set; }
        public long PositionZ { get; set; }

        // Новые поля
        public long Radius { get; set; } = 100_000; // 100 тыс км
        public float Density { get; set; } = 0.5f; // 0-1
        public int AsteroidCount { get; set; } = 1000;

        // Навигационные свойства
        public virtual SolarSystem SolarSystem { get; set; }
        public virtual ICollection<PlanetResource> Resources { get; set; } = new List<PlanetResource>();
    }
}