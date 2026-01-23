using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Echoes.API.Models.Entities.Inventory
{
    [Table("containers")]
    public class Container
    {
        [Key]
        [Column("container_id")]
        public Guid ContainerId { get; set; } = Guid.NewGuid();

        [Column("parent_container_id")]
        public Guid? ParentContainerId { get; set; }

        [Required]
        [Column("owner_id")]
        public Guid OwnerId { get; set; }

        [Required]
        [MaxLength(50)]
        [Column("container_type")]
        public string ContainerType { get; set; } = string.Empty;

        [MaxLength(200)]
        [Column("name")]
        public string? Name { get; set; }

        [Column("max_volume")]
        public decimal? MaxVolume { get; set; }

        [Column("used_volume")]
        public decimal UsedVolume { get; set; } = 0;

        [Column("location_x")]
        public decimal? LocationX { get; set; }

        [Column("location_y")]
        public decimal? LocationY { get; set; }

        [Column("location_z")]
        public decimal? LocationZ { get; set; }

        [Column("solar_system_id")]
        public int? SolarSystemId { get; set; }

        [Column("station_id")]
        public int? StationId { get; set; }

        [Column("is_accessible")]
        public bool IsAccessible { get; set; } = true;

        [Column("access_level")]
        public int AccessLevel { get; set; } = 0;

        [Column("created_at")]
        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;

        [Column("updated_at")]
        public DateTime UpdatedAt { get; set; } = DateTime.UtcNow;

        // Navigation properties
        [ForeignKey(nameof(ParentContainerId))]
        public virtual Container? ParentContainer { get; set; }

        public virtual ICollection<Container> ChildContainers { get; set; } = new List<Container>();
        public virtual ICollection<Asset> Assets { get; set; } = new List<Asset>();
    }
}
