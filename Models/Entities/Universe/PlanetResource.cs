using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Echoes.API.Models.Entities.Universe
{
    [Table("PlanetResources")]
    public class PlanetResource
    {
        [ForeignKey("Planet")]
        public Guid? PlanetId { get; set; }

        [ForeignKey("Moon")]
        public Guid? MoonId { get; set; }
        public Guid Id { get; set; }
        
        [ForeignKey("AsteroidBelt")]
        public Guid? AsteroidBeltId { get; set; }

        [Required]
        [MaxLength(100)]
        public string ResourceType { get; set; }

        public int Quantity { get; set; } = 1000;
        public float Quality { get; set; } = 1.0f;
        public DateTime? LastHarvested { get; set; }

        // Навигационные свойства
        public virtual Planet Planet { get; set; }
        public virtual Moon Moon { get; set; }
        public virtual AsteroidBelt AsteroidBelt { get; set; }
    }
}