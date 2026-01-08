using Echoes.API.Models.Entities.Universe;
using Echoes.API.Models.Enums;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Echoes.API.Models.Entities.Character
{
    [Table("character_locations")]
    public class CharacterLocation 
    {
        [Key]
        public Guid Id { get; set; }

        [ForeignKey(nameof(Character))]
        public Guid CharacterId { get; set; }

        // Тип локации
        // public LocationType LocationType { get; set; } = LocationType.Docked;

        // Если в космосе
        [ForeignKey(nameof(SolarSystem))]
        public Guid? SolarSystemId { get; set; }

        public double PositionX { get; set; }
        public double PositionY { get; set; }
        public double PositionZ { get; set; }

        // Ориентация (кватернион)
        public float RotationX { get; set; }
        public float RotationY { get; set; }
        public float RotationZ { get; set; }
        public float RotationW { get; set; } = 1.0f;

        // Скорость
        public float VelocityX { get; set; }
        public float VelocityY { get; set; }
        public float VelocityZ { get; set; }

        // Если на станции/в доке
        [ForeignKey(nameof(Station))]
        public Guid? StationId { get; set; }

        // Если в корабле
        [ForeignKey(nameof(Ship))]
        public long? ShipItemId { get; set; }

        // EVE: статусы
        public bool IsDocked { get; set; } = true;
        public bool InWarp { get; set; } = false;
        public bool IsCloaked { get; set; } = false;
        public DateTime? WarpEndTime { get; set; }

        // Навигационные свойства
        public virtual Character Character { get; set; } = null!;
        public virtual Universe.SolarSystem? SolarSystem { get; set; }
        public virtual Universe.Station? Station { get; set; }
        public virtual Inventory.InventoryItem? Ship { get; set; }
        public LocationType LocationType { get; set; }
        public DateTime? LastUpdate { get; internal set; }
        //public object LocationType { get; internal set; }
    }
}