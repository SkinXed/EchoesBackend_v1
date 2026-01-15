namespace Echoes.API.Models.DTOs.Server
{
    /// <summary>
    /// Response DTO containing connection information for a game server.
    /// Returned when a client requests connection details for a solar system.
    /// </summary>
    public class ConnectionInfoResponseDto
    {
        /// <summary>
        /// Public IP address of the game server.
        /// </summary>
        public string PublicIP { get; set; } = string.Empty;

        /// <summary>
        /// Port number for game client connections.
        /// </summary>
        public int GamePort { get; set; }

        /// <summary>
        /// Unique instance identifier of the game server.
        /// </summary>
        public string ServerInstanceId { get; set; } = string.Empty;

        /// <summary>
        /// Region ID if this is a regional cluster server.
        /// Null for dedicated system servers.
        /// </summary>
        public Guid? RegionId { get; set; }

        /// <summary>
        /// Type of server node: "DedicatedSystem", "RegionalCluster", or "Fallback".
        /// </summary>
        public string NodeType { get; set; } = string.Empty;

        /// <summary>
        /// Indicates whether the client needs to disconnect and reconnect to a different server.
        /// True if target system is on a different server than current connection.
        /// </summary>
        public bool RequiresReconnect { get; set; }

        /// <summary>
        /// Solar System ID that this server connection info is for.
        /// </summary>
        public Guid? CurrentSystemId { get; set; }

        /// <summary>
        /// Current server load as a percentage (0-100).
        /// Used for load balancing decisions.
        /// </summary>
        public int ServerLoadPercentage { get; set; }

        /// <summary>
        /// Priority value for this server (higher is better).
        /// Used when multiple servers are available for the same system.
        /// </summary>
        public int Priority { get; set; }

        /// <summary>
        /// Full connection string in the format "IP:Port".
        /// </summary>
        public string ConnectionString => $"{PublicIP}:{GamePort}";

        /// <summary>
        /// Indicates whether this server is in a state that allows new connections.
        /// Checks load percentage and validates IP/port configuration.
        /// </summary>
        public bool IsConnectable => ServerLoadPercentage < 95 && !string.IsNullOrEmpty(PublicIP) && GamePort > 0;
    }
}
