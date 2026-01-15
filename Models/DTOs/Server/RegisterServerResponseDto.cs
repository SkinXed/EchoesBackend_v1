namespace Echoes.API.Models.DTOs.Server
{
    /// <summary>
    /// Response DTO for server registration requests.
    /// Returned after a game server successfully registers with the backend.
    /// </summary>
    public class RegisterServerResponseDto
    {
        /// <summary>
        /// Indicates whether the registration was successful.
        /// </summary>
        public bool Success { get; set; }

        /// <summary>
        /// Database ID assigned to the registered server.
        /// </summary>
        public Guid ServerId { get; set; }

        /// <summary>
        /// Instance ID of the registered server (echoed back from request).
        /// </summary>
        public string InstanceId { get; set; } = string.Empty;

        /// <summary>
        /// Type of server node that was registered: "RegionalCluster" or "DedicatedSystem".
        /// </summary>
        public string NodeType { get; set; } = string.Empty;

        /// <summary>
        /// Human-readable message about the registration result.
        /// </summary>
        public string Message { get; set; } = string.Empty;
    }
}
