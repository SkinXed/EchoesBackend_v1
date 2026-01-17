using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Echoes.API.Models.Entities.Universe
{
    [Table("Moons")]
    public class Moon 
    {
        [Key]
        public Guid Id { get; set; }

        [Required]
        [MaxLength(200)]
        public string Name { get; set; }

        [ForeignKey("Planet")]
        public Guid PlanetId { get; set; }
        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;
        // Новые поля
        public long Radius { get; set; } = 100; // км
        public long OrbitDistance { get; set; } // км
        public long OrbitPeriod { get; set; } // Часы
        public bool HasResources { get; set; } = false;

        // Position coordinates
        public long PositionX { get; set; }
        public long PositionY { get; set; }
        public long PositionZ { get; set; }

        // Навигационные свойства
        public virtual Planet Planet { get; set; }
        public virtual ICollection<PlanetResource> Resources { get; set; } = new List<PlanetResource>();
    }
}