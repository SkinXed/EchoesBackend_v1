// Controllers/Gameplay/GameServerController.cs - Connection Request DTO
// Refactored for improved type safety and documentation

using System.ComponentModel.DataAnnotations;

namespace Echoes.API.Models.DTOs.Server
{
    /// <summary>
    /// Request model for player connection to a game server.
    /// Used when a player wants to travel to a different solar system.
    /// </summary>
    public class ConnectionRequest
    {
        /// <summary>
        /// Unique identifier of the player requesting connection.
        /// </summary>
        [Required]
        public string PlayerId { get; set; } = string.Empty;

        /// <summary>
        /// Solar system ID where the player is currently located.
        /// </summary>
        [Required]
        public Guid CurrentSystemId { get; set; }

        /// <summary>
        /// Solar system ID where the player wants to travel.
        /// </summary>
        [Required]
        public Guid TargetSystemId { get; set; }

        /// <summary>
        /// Server instance ID where the player is currently connected.
        /// </summary>
        [Required]
        public string CurrentServerId { get; set; } = string.Empty;
    }
}
