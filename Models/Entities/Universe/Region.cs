using Echoes.API.Models.Enums;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Echoes.API.Models.Entities.Universe
{
    [Table("Regions")]
    public class Region 
    {
        public Guid Id { get; set; } // Добавьте это свойство

        [Required]
        [MaxLength(200)]
        public string Name { get; set; }

        [MaxLength(50)]
        public string RegionCode { get; set; }

        public RegionType Type { get; set; }

        [Range(-1.0f, 1.0f)]
        public float AverageSecurity { get; set; }

        public long PositionX { get; set; }
        public long PositionY { get; set; }
        public long PositionZ { get; set; }

        // Новые поля
        public int? FactionId { get; set; }

        [MaxLength(500)]
        public string Description { get; set; }

        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;

        // Навигационные свойства
        public virtual ICollection<Constellation> Constellations { get; set; } = new List<Constellation>();
    }
}