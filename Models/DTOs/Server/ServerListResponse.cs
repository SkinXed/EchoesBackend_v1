// Controllers/Management/ServerManagementController.cs - Server List Item DTO
// Created for improved type safety and documentation

using Echoes.API.Models.Entities.GameServer;

namespace Echoes.API.Models.DTOs.Server
{
    /// <summary>
    /// Response model for a single server in the server list.
    /// Contains summary information about a game server instance.
    /// </summary>
    public class ServerListItem
    {
        /// <summary>
        /// Database ID of the server.
        /// </summary>
        public Guid Id { get; set; }

        /// <summary>
        /// Unique instance identifier.
        /// </summary>
        public string InstanceId { get; set; } = string.Empty;

        /// <summary>
        /// Public IP address.
        /// </summary>
        public string PublicIP { get; set; } = string.Empty;

        /// <summary>
        /// Game port number.
        /// </summary>
        public int GamePort { get; set; }

        /// <summary>
        /// Web/HTTP API port number.
        /// </summary>
        public int WebPort { get; set; }

        /// <summary>
        /// Current server status.
        /// </summary>
        public ServerStatus Status { get; set; }

        /// <summary>
        /// Number of players currently online.
        /// </summary>
        public int OnlinePlayers { get; set; }

        /// <summary>
        /// Maximum player capacity.
        /// </summary>
        public int MaxPlayers { get; set; }

        /// <summary>
        /// Load percentage (0-100).
        /// </summary>
        public int LoadPercentage { get; set; }

        /// <summary>
        /// Last heartbeat timestamp.
        /// </summary>
        public DateTime LastHeartbeat { get; set; }

        /// <summary>
        /// Server type: "RegionalCluster", "DedicatedSystem", or "Unknown".
        /// </summary>
        public string Type { get; set; } = string.Empty;

        /// <summary>
        /// Location name (system name or region name).
        /// </summary>
        public string LocationName { get; set; } = string.Empty;

        /// <summary>
        /// Optional: Solar System ID for dedicated servers.
        /// </summary>
        public Guid? SolarSystemId { get; set; }

        /// <summary>
        /// Optional: Region ID for regional servers.
        /// </summary>
        public Guid? RegionId { get; set; }

        /// <summary>
        /// Server uptime in minutes.
        /// </summary>
        public int UptimeMinutes { get; set; }

        /// <summary>
        /// Server health status: "Healthy" or "Stressed".
        /// </summary>
        public string Health { get; set; } = string.Empty;
    }

    /// <summary>
    /// Response model for server list query.
    /// Contains a collection of servers matching the query filters.
    /// </summary>
    public class ServerListResponse
    {
        /// <summary>
        /// List of servers.
        /// </summary>
        public List<ServerListItem> Servers { get; set; } = new();

        /// <summary>
        /// Total number of servers returned.
        /// </summary>
        public int Total { get; set; }

        /// <summary>
        /// Number of online servers.
        /// </summary>
        public int Online { get; set; }

        /// <summary>
        /// Timestamp when this list was generated.
        /// </summary>
        public DateTime Timestamp { get; set; }
    }
}
