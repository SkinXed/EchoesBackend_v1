// File: DTOs/ServerRequests/ConnectionRequest.cs
namespace Echoes.API.Models.DTOs.ServerRequests
{
    public class ConnectionRequest
    {
        public string PlayerId { get; set; } = string.Empty;
        public Guid CurrentSystemId { get; set; }
        public Guid TargetSystemId { get; set; }
        public string CurrentServerId { get; set; } = string.Empty;
    }
}