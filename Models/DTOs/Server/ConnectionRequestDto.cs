using System.ComponentModel.DataAnnotations;

namespace Echoes.API.Models.DTOs.Server
{
    /// <summary>
    /// Request DTO for requesting a connection to a game server.
    /// Used by clients to find the appropriate game server for a target solar system.
    /// </summary>
    public class ConnectionRequestDto
    {
        /// <summary>
        /// Unique identifier of the player requesting the connection.
        /// </summary>
        [Required]
        [MaxLength(100)]
        public string PlayerId { get; set; } = string.Empty;

        /// <summary>
        /// Solar System ID where the player is currently located.
        /// </summary>
        [Required]
        public Guid CurrentSystemId { get; set; }

        /// <summary>
        /// Solar System ID where the player wants to travel.
        /// </summary>
        [Required]
        public Guid TargetSystemId { get; set; }

        /// <summary>
        /// Instance ID of the server the player is currently connected to.
        /// Empty string if not currently connected to any server.
        /// </summary>
        [MaxLength(50)]
        public string CurrentServerId { get; set; } = string.Empty;
    }
}
