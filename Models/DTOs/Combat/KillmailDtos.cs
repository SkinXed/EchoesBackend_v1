using System.ComponentModel.DataAnnotations;

namespace Echoes.API.Models.DTOs.Combat
{
    // ========== Request DTOs ==========

    /// <summary>
    /// Full killmail report from UE5 game server
    /// Sent by CombatServerSubsystem via POST /api/combat/killmail
    /// </summary>
    public class KillmailReportRequest
    {
        [Required]
        public Guid VictimId { get; set; }

        [Required]
        public Guid FinalStrikerId { get; set; }

        [Required]
        public Guid SolarSystemId { get; set; }

        [Required]
        public int ShipTypeId { get; set; }

        public string ShipTypeName { get; set; } = string.Empty;

        /// <summary>
        /// Total estimated loss value calculated by the game server
        /// </summary>
        public decimal TotalLossValue { get; set; }

        /// <summary>
        /// List of all attackers who participated in the kill
        /// </summary>
        public List<KillmailAttackerDto> Attackers { get; set; } = new();

        /// <summary>
        /// Items that survived destruction (50% chance) — placed in wreck
        /// </summary>
        public List<KillmailItemDto> DroppedItems { get; set; } = new();

        /// <summary>
        /// Items that were destroyed (50% chance)
        /// </summary>
        public List<KillmailItemDto> DestroyedItems { get; set; } = new();
    }

    /// <summary>
    /// Attacker entry in a killmail
    /// </summary>
    public class KillmailAttackerDto
    {
        public Guid CharacterId { get; set; }
        public string CharacterName { get; set; } = string.Empty;
        public Guid? CorporationId { get; set; }
        public int ShipTypeId { get; set; }
        public string ShipTypeName { get; set; } = string.Empty;
        public string WeaponTypeName { get; set; } = string.Empty;
        public double DamageDealt { get; set; }
        public bool IsFinalBlow { get; set; }
    }

    /// <summary>
    /// Item entry in a killmail (dropped or destroyed)
    /// </summary>
    public class KillmailItemDto
    {
        public int ItemTypeId { get; set; }
        public string ItemName { get; set; } = string.Empty;
        public int Quantity { get; set; }

        /// <summary>
        /// Estimated value per unit (from market average or base price)
        /// </summary>
        public decimal EstimatedValue { get; set; }

        /// <summary>
        /// Where the item was located: "Cargo", "HighSlot", "MidSlot", "LowSlot", "RigSlot"
        /// </summary>
        public string Location { get; set; } = string.Empty;
    }

    // ========== Response DTOs ==========

    /// <summary>
    /// Response after killmail is stored
    /// </summary>
    public class KillmailResultDto
    {
        public Guid KillmailId { get; set; }
        public Guid VictimId { get; set; }
        public Guid FinalStrikerId { get; set; }
        public decimal TotalLossValue { get; set; }
        public DateTime KilledAt { get; set; }
        public string Message { get; set; } = string.Empty;
    }

    /// <summary>
    /// Killmail summary for display (zkillboard-style)
    /// </summary>
    public class KillmailSummaryDto
    {
        public Guid KillmailId { get; set; }
        public Guid VictimId { get; set; }
        public string VictimName { get; set; } = string.Empty;
        public Guid FinalStrikerId { get; set; }
        public string FinalStrikerName { get; set; } = string.Empty;
        public Guid SolarSystemId { get; set; }
        public string SolarSystemName { get; set; } = string.Empty;
        public int ShipTypeId { get; set; }
        public string ShipTypeName { get; set; } = string.Empty;
        public decimal TotalLossValue { get; set; }
        public DateTime KilledAt { get; set; }
        public int AttackerCount { get; set; }
        public List<KillmailAttackerDto> Attackers { get; set; } = new();
        public List<KillmailItemDto> DroppedItems { get; set; } = new();
        public List<KillmailItemDto> DestroyedItems { get; set; } = new();
    }
}
