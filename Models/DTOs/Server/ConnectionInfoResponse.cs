// Controllers/Gameplay/GameServerController.cs - Connection Info Response DTO
// Refactored for improved type safety and documentation

namespace Echoes.API.Models.DTOs.Server
{
    /// <summary>
    /// Response model containing connection information for a game server.
    /// Returned when a client requests connection to a specific solar system.
    /// </summary>
    public class ConnectionInfoResponse
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
        /// Unique identifier of the server instance.
        /// </summary>
        public string ServerInstanceId { get; set; } = string.Empty;

        /// <summary>
        /// Region ID this server belongs to (for regional servers).
        /// </summary>
        public Guid RegionId { get; set; }

        /// <summary>
        /// Type of server node: "DedicatedSystem", "RegionalCluster", or "Fallback".
        /// </summary>
        public string NodeType { get; set; } = string.Empty;

        /// <summary>
        /// Indicates whether the client needs to reconnect to a different server.
        /// True for regional/fallback servers, false for dedicated system servers.
        /// </summary>
        public bool RequiresReconnect { get; set; }

        /// <summary>
        /// Solar system ID this connection is for.
        /// </summary>
        public Guid? CurrentSystemId { get; set; }

        /// <summary>
        /// Current server load as a percentage (0-100).
        /// </summary>
        public int ServerLoadPercentage { get; set; }

        /// <summary>
        /// Priority score for server selection (higher is better).
        /// </summary>
        public int Priority { get; set; }

        /// <summary>
        /// Connection string in format IP:Port.
        /// </summary>
        public string ConnectionString => $"{PublicIP}:{GamePort}";

        /// <summary>
        /// Indicates whether this server is connectable (not overloaded and has valid address).
        /// </summary>
        public bool IsConnectable => ServerLoadPercentage < 95 && !string.IsNullOrEmpty(PublicIP) && GamePort > 0;
    }
}
