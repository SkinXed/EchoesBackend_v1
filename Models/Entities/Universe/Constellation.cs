using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Echoes.API.Models.Entities.Universe
{
    [Table("Constellations")]
    public class Constellation 
    {
        public Guid Id { get; set; } // Добавьте это свойство

        [Required]
        [MaxLength(200)]
        public string Name { get; set; }

        [ForeignKey("Region")]
        public Guid RegionId { get; set; }

        [Range(-1.0f, 1.0f)]
        public float AverageSecurity { get; set; }

        public long PositionX { get; set; }
        public long PositionY { get; set; }
        public long PositionZ { get; set; }

        // Новые поля
        public int? FactionId { get; set; }
        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;


        // Навигационные свойства
        public virtual Region Region { get; set; }
        public virtual ICollection<SolarSystem> SolarSystems { get; set; } = new List<SolarSystem>();
    }
}