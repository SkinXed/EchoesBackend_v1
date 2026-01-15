namespace Echoes.API.Models.DTOs.Server
{
    /// <summary>
    /// Response DTO containing aggregated statistics about all game servers.
    /// Provides high-level metrics for monitoring and dashboard purposes.
    /// </summary>
    public class ServerStatsDto
    {
        /// <summary>
        /// Total number of registered game servers (online and offline).
        /// </summary>
        public int TotalServers { get; set; }

        /// <summary>
        /// Number of servers currently in Ready status.
        /// </summary>
        public int OnlineServers { get; set; }

        /// <summary>
        /// Number of servers currently starting up.
        /// </summary>
        public int StartingServers { get; set; }

        /// <summary>
        /// Total number of players across all online servers.
        /// </summary>
        public int TotalPlayers { get; set; }

        /// <summary>
        /// Maximum total player capacity across all servers.
        /// </summary>
        public int MaxCapacity { get; set; }

        /// <summary>
        /// Overall utilization percentage (0-100) across all servers.
        /// </summary>
        public int Utilization { get; set; }

        /// <summary>
        /// Breakdown of servers by type.
        /// </summary>
        public ServerTypeBreakdown ByType { get; set; } = new ServerTypeBreakdown();

        /// <summary>
        /// Average load percentage across all online servers.
        /// </summary>
        public int AverageLoad { get; set; }

        /// <summary>
        /// Timestamp when these statistics were generated.
        /// </summary>
        public DateTime LastUpdated { get; set; }
    }

    /// <summary>
    /// Breakdown of server counts by server type.
    /// </summary>
    public class ServerTypeBreakdown
    {
        /// <summary>
        /// Number of dedicated system servers.
        /// </summary>
        public int Dedicated { get; set; }

        /// <summary>
        /// Number of regional cluster servers.
        /// </summary>
        public int Regional { get; set; }
    }
}
