// File: DTOs/ServerRequests/HeartbeatRequest.cs
using Echoes.API.Models.Entities.GameServer;

namespace Echoes.API.DTOs.ServerRequests
{
    public class HeartbeatRequest
    {
        public string InstanceId { get; set; } = string.Empty;
        public ServerStatus Status { get; set; }
        public int OnlinePlayers { get; set; }
        public float CPUUsage { get; set; }
        public long MemoryUsageMB { get; set; }
        public float NetworkInKbps { get; set; }
        public float NetworkOutKbps { get; set; }
    }
}