using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Echoes.API.Models.Entities.Inventory
{
    [Table("asset_logs")]
    public class AssetLog
    {
        [Key]
        [Column("log_id")]
        [DatabaseGenerated(DatabaseGeneratedOption.Identity)]
        public long LogId { get; set; }

        [Column("asset_id")]
        public Guid? AssetId { get; set; }

        [Required]
        [Column("actor_id")]
        public Guid ActorId { get; set; }

        [Required]
        [MaxLength(50)]
        [Column("action_type")]
        public string ActionType { get; set; } = string.Empty;

        [Column("old_location_id")]
        public Guid? OldLocationId { get; set; }

        [Column("new_location_id")]
        public Guid? NewLocationId { get; set; }

        [Column("old_quantity")]
        public long? OldQuantity { get; set; }

        [Column("new_quantity")]
        public long? NewQuantity { get; set; }

        [Column("old_flag")]
        public int? OldFlag { get; set; }

        [Column("new_flag")]
        public int? NewFlag { get; set; }

        [Column("reason")]
        public string? Reason { get; set; }

        [Column("ip_address")]
        public string? IpAddress { get; set; }

        [Column("user_agent")]
        public string? UserAgent { get; set; }

        [Column("created_at")]
        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;

        // Navigation properties
        [ForeignKey(nameof(AssetId))]
        public virtual Asset? Asset { get; set; }
    }
}
