namespace Echoes.API.Models.DTOs.Server
{
    /// <summary>
    /// Response DTO containing a list of game servers with metadata.
    /// Used for server list and monitoring endpoints.
    /// </summary>
    public class ServerListResponseDto
    {
        /// <summary>
        /// List of game server information.
        /// </summary>
        public List<ServerListItemDto> Servers { get; set; } = new List<ServerListItemDto>();

        /// <summary>
        /// Total count of servers in the list.
        /// </summary>
        public int Total { get; set; }

        /// <summary>
        /// Count of servers currently online (Ready status).
        /// </summary>
        public int Online { get; set; }

        /// <summary>
        /// Timestamp when this list was generated.
        /// </summary>
        public DateTime Timestamp { get; set; }
    }
}
