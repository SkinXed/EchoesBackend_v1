// Controllers/Management/ServerManagementController.cs - Server Registration Request DTO
// Refactored for improved type safety and documentation

using System.ComponentModel.DataAnnotations;

namespace Echoes.API.Models.DTOs.Server
{
    /// <summary>
    /// Request model for registering a new game server instance.
    /// Used by game servers to announce their availability and configuration.
    /// </summary>
    public class RegisterServerRequest
    {
        /// <summary>
        /// Unique identifier for this server instance.
        /// Should be unique across all server instances (e.g., machine name + process ID).
        /// </summary>
        /// <example>GameServer-EU-01-PID12345</example>
        [Required]
        public string InstanceId { get; set; } = string.Empty;

        /// <summary>
        /// Public IP address where the game server can be reached by clients.
        /// </summary>
        /// <example>192.168.1.100</example>
        [Required]
        public string PublicIP { get; set; } = "127.0.0.1";

        /// <summary>
        /// Port number for game client connections.
        /// </summary>
        /// <example>7777</example>
        [Range(1, 65535)]
        public int GamePort { get; set; } = 7777;

        /// <summary>
        /// Port number for web/HTTP API connections.
        /// </summary>
        /// <example>7778</example>
        [Range(1, 65535)]
        public int WebPort { get; set; } = 7778;

        /// <summary>
        /// Optional: Solar System ID for dedicated system servers.
        /// If set, this server handles only this specific solar system.
        /// Mutually exclusive with RegionId for primary assignment.
        /// </summary>
        public Guid? SolarSystemId { get; set; }

        /// <summary>
        /// Optional: Region ID for regional cluster servers.
        /// If set, this server handles multiple systems within the region.
        /// Takes priority over SolarSystemId if both are specified.
        /// </summary>
        public Guid? RegionId { get; set; }

        /// <summary>
        /// Maximum number of concurrent players this server can handle.
        /// </summary>
        /// <example>100</example>
        [Range(1, 10000)]
        public int MaxPlayers { get; set; } = 100;

        /// <summary>
        /// Geographic region for server location (for latency optimization).
        /// </summary>
        /// <example>EU, US-East, US-West, Asia-Pacific</example>
        public string GeoRegion { get; set; } = "EU";

        /// <summary>
        /// Game version running on this server.
        /// </summary>
        /// <example>1.0.0</example>
        public string GameVersion { get; set; } = "1.0.0";

        /// <summary>
        /// Optional: Server hostname or machine name.
        /// </summary>
        public string? Hostname { get; set; }

        /// <summary>
        /// Optional: Comma-separated tags for server classification.
        /// </summary>
        /// <example>pvp,hardcore,experimental</example>
        public string? ServerTags { get; set; }

        /// <summary>
        /// Validates the registration request.
        /// </summary>
        /// <exception cref="ArgumentException">Thrown when validation fails.</exception>
        public void Validate()
        {
            if (string.IsNullOrWhiteSpace(InstanceId))
                throw new ArgumentException("InstanceId is required");

            if (string.IsNullOrWhiteSpace(PublicIP))
                throw new ArgumentException("PublicIP is required");

            if (GamePort <= 0 || GamePort > 65535)
                throw new ArgumentException("Invalid GamePort");

            if (!SolarSystemId.HasValue && !RegionId.HasValue)
                throw new ArgumentException("Must specify either SolarSystemId (Dedicated) or RegionId (Cluster)");
        }
    }
}
