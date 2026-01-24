using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Echoes.API.Models.Entities.Universe
{
    [Table("Stargates")]
    public class Stargate
    {
        [Required]
        [MaxLength(200)]
        public string Name { get; set; } = string.Empty;

        // Новые поля
        [ForeignKey("SourceSolarSystem")]
        public Guid SourceSolarSystemId { get; set; }

        [ForeignKey("DestinationSolarSystem")]
        public Guid DestinationSolarSystemId { get; set; }
        public Guid Id { get; set; }
        // --- ДОБАВЛЕНО: Координаты врат внутри системы ---
        public long PositionX { get; set; }
        public long PositionY { get; set; }
        public long PositionZ { get; set; }
        // -------------------------------------------------
        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;
        public bool IsOperational { get; set; } = true;
        public int JumpCost { get; set; } = 100;

        [MaxLength(100)]
        public string Model { get; set; } = "Stargate_01";

        // Навигационные свойства
        public virtual SolarSystem SourceSolarSystem { get; set; } = null!;
        public virtual SolarSystem DestinationSolarSystem { get; set; } = null!;
        //public object TargetSystemId { get; internal set; }
        //public object TargetSystem { get; internal set; }
        //public bool IsActive { get; internal set; }
    }
}