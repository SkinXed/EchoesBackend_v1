using Echoes.API.Models.Entities.GameServer;

namespace Echoes.API.Models.DTOs.Server
{
    /// <summary>
    /// Response DTO for a single server in the server list.
    /// Contains essential information about a game server instance.
    /// </summary>
    public class ServerListItemDto
    {
        /// <summary>
        /// Database ID of the game server.
        /// </summary>
        public Guid Id { get; set; }

        /// <summary>
        /// Unique instance identifier for this server.
        /// </summary>
        public string InstanceId { get; set; } = string.Empty;

        /// <summary>
        /// Public IP address of the server.
        /// </summary>
        public string PublicIP { get; set; } = string.Empty;

        /// <summary>
        /// Game port for client connections.
        /// </summary>
        public int GamePort { get; set; }

        /// <summary>
        /// Web/API port for server management.
        /// </summary>
        public int WebPort { get; set; }

        /// <summary>
        /// Current operational status of the server.
        /// </summary>
        public ServerStatus Status { get; set; }

        /// <summary>
        /// Number of players currently online on this server.
        /// </summary>
        public int OnlinePlayers { get; set; }

        /// <summary>
        /// Maximum player capacity for this server.
        /// </summary>
        public int MaxPlayers { get; set; }

        /// <summary>
        /// Current load as a percentage (0-100).
        /// </summary>
        public int LoadPercentage { get; set; }

        /// <summary>
        /// Timestamp of the last heartbeat received from this server.
        /// </summary>
        public DateTime LastHeartbeat { get; set; }

        /// <summary>
        /// Type of server: "DedicatedSystem", "RegionalCluster", or "Unknown".
        /// </summary>
        public string Type { get; set; } = string.Empty;

        /// <summary>
        /// Name of the location this server is responsible for (system or region name).
        /// </summary>
        public string LocationName { get; set; } = string.Empty;

        /// <summary>
        /// Solar System ID if this is a dedicated system server.
        /// </summary>
        public Guid? SolarSystemId { get; set; }

        /// <summary>
        /// Region ID if this is a regional cluster server.
        /// </summary>
        public Guid? RegionId { get; set; }

        /// <summary>
        /// How long the server has been running in minutes.
        /// </summary>
        public int UptimeMinutes { get; set; }

        /// <summary>
        /// Health status of the server: "Healthy" or "Stressed".
        /// </summary>
        public string Health { get; set; } = string.Empty;
    }
}
