using System.ComponentModel.DataAnnotations;
using Echoes.API.Models.Entities.GameServer;

namespace Echoes.API.Models.DTOs.Server
{
    /// <summary>
    /// Request DTO for server heartbeat updates.
    /// Game servers send this periodically to indicate they are still running and provide status updates.
    /// </summary>
    public class HeartbeatRequestDto
    {
        /// <summary>
        /// Unique identifier of the server instance sending the heartbeat.
        /// Must match the InstanceId used during registration.
        /// </summary>
        [Required]
        [MaxLength(50)]
        public string InstanceId { get; set; } = string.Empty;

        /// <summary>
        /// Current operational status of the game server.
        /// </summary>
        [Required]
        public ServerStatus Status { get; set; }

        /// <summary>
        /// Number of players currently connected to the server.
        /// </summary>
        [Required]
        [Range(0, int.MaxValue)]
        public int OnlinePlayers { get; set; }

        /// <summary>
        /// Current CPU usage percentage (0-100).
        /// </summary>
        [Range(0, 100)]
        public float CPUUsage { get; set; }

        /// <summary>
        /// Current memory usage in megabytes.
        /// </summary>
        [Range(0, long.MaxValue)]
        public long MemoryUsageMB { get; set; }

        /// <summary>
        /// Incoming network traffic in kilobits per second.
        /// </summary>
        [Range(0, float.MaxValue)]
        public float NetworkInKbps { get; set; }

        /// <summary>
        /// Outgoing network traffic in kilobits per second.
        /// </summary>
        [Range(0, float.MaxValue)]
        public float NetworkOutKbps { get; set; }
    }
}
