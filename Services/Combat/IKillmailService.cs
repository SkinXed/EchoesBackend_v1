using Echoes.API.Models.DTOs.Combat;

namespace Echoes.API.Services.Combat
{
    public interface IKillmailService
    {
        /// <summary>
        /// Process and store a killmail report from the game server
        /// Updates victim/killer stats, stores full killmail data
        /// </summary>
        Task<KillmailResultDto> ProcessKillmailAsync(KillmailReportRequest request);

        /// <summary>
        /// Get a specific killmail by ID
        /// </summary>
        Task<KillmailSummaryDto?> GetKillmailAsync(Guid killmailId);

        /// <summary>
        /// Get recent killmails for a character (as victim or attacker)
        /// </summary>
        Task<List<KillmailSummaryDto>> GetCharacterKillmailsAsync(Guid characterId, int page = 1, int pageSize = 20);

        /// <summary>
        /// Get recent killmails for a solar system
        /// </summary>
        Task<List<KillmailSummaryDto>> GetSystemKillmailsAsync(Guid solarSystemId, int page = 1, int pageSize = 20);
    }
}
