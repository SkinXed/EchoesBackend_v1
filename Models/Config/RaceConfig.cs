using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Echoes.API.Models.Config
{
    /// <summary>
    /// Race configuration entity
    /// Defines starting location, station, and ship for each race
    /// </summary>
    [Table("race_configs")]
    public class RaceConfig
    {
        [Key]
        public int RaceId { get; set; }

        [Required]
        [MaxLength(50)]
        public string RaceName { get; set; } = string.Empty;

        [MaxLength(500)]
        public string Description { get; set; } = string.Empty;

        /// <summary>
        /// Starting solar system ID for this race
        /// </summary>
        public Guid StartingSystemId { get; set; }

        /// <summary>
        /// Starting station ID where new characters spawn
        /// </summary>
        public Guid StartingStationId { get; set; }

        /// <summary>
        /// Default ship type ID (from Items table)
        /// </summary>
        public int DefaultShipTypeId { get; set; }

        /// <summary>
        /// Race bonuses description
        /// </summary>
        [MaxLength(1000)]
        public string RaceBonuses { get; set; } = string.Empty;

        /// <summary>
        /// Starting skill points for this race
        /// </summary>
        public int StartingSkillPoints { get; set; } = 50000;

        /// <summary>
        /// Starting credits for this race
        /// </summary>
        public long StartingCredits { get; set; } = 5000000;

        public DateTime CreatedAt { get; set; } = DateTime.UtcNow;
        public DateTime UpdatedAt { get; set; } = DateTime.UtcNow;
    }
}
