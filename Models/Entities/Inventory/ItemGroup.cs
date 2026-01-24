using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Echoes.API.Models.Entities.Inventory
{
    [Table("item_groups")]
    public class ItemGroup
    {
        [Key]
        [Column("group_id")]
        [DatabaseGenerated(DatabaseGeneratedOption.Identity)]
        public int GroupId { get; set; }

        [Column("category_id")]
        public int? CategoryId { get; set; }

        [Required]
        [MaxLength(100)]
        [Column("name")]
        public string Name { get; set; } = string.Empty;

        [Column("volume_multiplier")]
        public decimal VolumeMultiplier { get; set; } = 1.0m;

        [Column("created_at")]
        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;

        // Navigation properties
        [ForeignKey(nameof(CategoryId))]
        public virtual ItemCategory? Category { get; set; }

        public virtual ICollection<ItemTypeEntity> ItemTypes { get; set; } = new List<ItemTypeEntity>();
    }
}
