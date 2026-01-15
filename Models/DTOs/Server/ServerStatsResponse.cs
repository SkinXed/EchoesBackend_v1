// Controllers/Management/ServerManagementController.cs - Server Stats Response DTO
// Created for improved type safety and documentation

namespace Echoes.API.Models.DTOs.Server
{
    /// <summary>
    /// Response model for server statistics and metrics.
    /// Provides an overview of all game servers in the cluster.
    /// </summary>
    public class ServerStatsResponse
    {
        /// <summary>
        /// Total number of registered servers.
        /// </summary>
        public int TotalServers { get; set; }

        /// <summary>
        /// Number of servers currently online and ready.
        /// </summary>
        public int OnlineServers { get; set; }

        /// <summary>
        /// Number of servers in starting state.
        /// </summary>
        public int StartingServers { get; set; }

        /// <summary>
        /// Total number of players across all servers.
        /// </summary>
        public int TotalPlayers { get; set; }

        /// <summary>
        /// Maximum player capacity across all servers.
        /// </summary>
        public int MaxCapacity { get; set; }

        /// <summary>
        /// Overall utilization percentage (0-100).
        /// </summary>
        public int Utilization { get; set; }

        /// <summary>
        /// Breakdown of servers by type.
        /// </summary>
        public ServerTypeBreakdown ByType { get; set; } = new();

        /// <summary>
        /// Average load percentage across all servers.
        /// </summary>
        public int AverageLoad { get; set; }

        /// <summary>
        /// Timestamp when these stats were generated.
        /// </summary>
        public DateTime LastUpdated { get; set; }
    }

    /// <summary>
    /// Breakdown of server counts by type.
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
