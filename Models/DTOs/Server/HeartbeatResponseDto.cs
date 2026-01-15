namespace Echoes.API.Models.DTOs.Server
{
    /// <summary>
    /// Response DTO for heartbeat requests.
    /// Acknowledges receipt of heartbeat and provides timing information.
    /// </summary>
    public class HeartbeatResponseDto
    {
        /// <summary>
        /// Indicates whether the heartbeat was successfully processed.
        /// </summary>
        public bool Success { get; set; }

        /// <summary>
        /// Server timestamp when the heartbeat was received.
        /// </summary>
        public DateTime Timestamp { get; set; }

        /// <summary>
        /// Recommended number of seconds before sending the next heartbeat.
        /// </summary>
        public int NextHeartbeatInSeconds { get; set; }
    }
}
