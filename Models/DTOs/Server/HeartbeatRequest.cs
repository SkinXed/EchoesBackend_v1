// Controllers/Management/ServerManagementController.cs - Server Heartbeat Request DTO
// Refactored for improved type safety and documentation

using System.ComponentModel.DataAnnotations;
using Echoes.API.Models.Entities.GameServer;

namespace Echoes.API.Models.DTOs.Server
{
    /// <summary>
    /// Request model for server heartbeat updates.
    /// Sent periodically by game servers to report their status and metrics.
    /// </summary>
    public class HeartbeatRequest
    {
        /// <summary>
        /// Unique identifier of the server instance sending the heartbeat.
        /// </summary>
        [Required]
        public string InstanceId { get; set; } = string.Empty;

        /// <summary>
        /// Current operational status of the server.
        /// </summary>
        [Required]
        public ServerStatus Status { get; set; }

        /// <summary>
        /// Number of players currently connected to the server.
        /// </summary>
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
        /// Network incoming traffic in kilobits per second.
        /// </summary>
        [Range(0, float.MaxValue)]
        public float NetworkInKbps { get; set; }

        /// <summary>
        /// Network outgoing traffic in kilobits per second.
        /// </summary>
        [Range(0, float.MaxValue)]
        public float NetworkOutKbps { get; set; }
    }
}
