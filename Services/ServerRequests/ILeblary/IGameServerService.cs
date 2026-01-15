using Echoes.API.Models.DTOs.Server;
using Echoes.API.Models.Entities.GameServer;

namespace Echoes.API.Services
{
    public interface IGameServerService
    {
        Task<GameServerNode> RegisterServerAsync(RegisterServerRequest request);
        Task<bool> UpdateHeartbeatAsync(HeartbeatRequest request);
        Task<ConnectionInfoResponse> GetConnectionForSystemAsync(Guid systemId);
        Task<List<GameServerNode>> GetAllServersAsync();
        Task<bool> UnregisterServerAsync(string instanceId);
        
    }
}