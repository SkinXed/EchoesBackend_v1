using Echoes.API.Models.Enums;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Echoes.API.Models.Entities.Universe
{
    [Table("Stations")]
    public class Station    
    {
        [Required]
        [MaxLength(200)]
        public string Name { get; set; } = string.Empty;

        [ForeignKey("SolarSystem")]
        public Guid SolarSystemId { get; set; }

        public StationType Type { get; set; }

        public long PositionX { get; set; }
        public long PositionY { get; set; }
        public long PositionZ { get; set; }
        public Guid Id { get; set; }
        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;
        public int DockingCapacity { get; set; } = 1000;

        // Новые поля
        public bool IsOperational { get; set; } = true;
        public int? FactionId { get; set; }

        [MaxLength(500)]
        public string Services { get; set; } = "Docking,Repair,Refuel";

        // Навигационные свойства
        public virtual SolarSystem SolarSystem { get; set; } = null!;
    }
}