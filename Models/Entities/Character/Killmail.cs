using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Echoes.API.Models.Entities.Character
{
    /// <summary>
    /// Killmail entity — record of a ship destruction event
    /// Stores victim, attackers, dropped/destroyed items, and total loss value
    /// </summary>
    [Table("killmails")]
    public class Killmail
    {
        [Key]
        public Guid Id { get; set; } = Guid.NewGuid();

        /// <summary>
        /// Character who lost their ship
        /// </summary>
        [ForeignKey(nameof(Victim))]
        public Guid VictimId { get; set; }

        /// <summary>
        /// Character who dealt the final blow
        /// </summary>
        public Guid FinalStrikerId { get; set; }

        /// <summary>
        /// Solar system where the kill occurred
        /// </summary>
        public Guid SolarSystemId { get; set; }

        /// <summary>
        /// Ship type ID of the destroyed vessel
        /// </summary>
        public int ShipTypeId { get; set; }

        /// <summary>
        /// Ship type name for display purposes
        /// </summary>
        [MaxLength(100)]
        public string ShipTypeName { get; set; } = string.Empty;

        /// <summary>
        /// Total estimated value of all items lost (dropped + destroyed)
        /// Based on market averages or base item values
        /// </summary>
        [Column(TypeName = "decimal(18,2)")]
        public decimal TotalLossValue { get; set; }

        /// <summary>
        /// Full JSON report of all attackers, dropped items, and destroyed items
        /// Structure: { Attackers: [...], DroppedItems: [...], DestroyedItems: [...] }
        /// </summary>
        [Column(TypeName = "jsonb")]
        public string KillmailDataJson { get; set; } = "{}";

        /// <summary>
        /// Timestamp when the kill occurred
        /// </summary>
        public DateTime KilledAt { get; set; } = DateTime.UtcNow;

        // Navigation
        public virtual Character Victim { get; set; } = null!;
    }
}
