using System.Text.Json;
using Echoes.API.Data;
using Echoes.API.Models.DTOs.Combat;
using Echoes.API.Models.Entities.Character;
using Microsoft.EntityFrameworkCore;

namespace Echoes.API.Services.Combat
{
    public class KillmailService : IKillmailService
    {
        private readonly DatabaseContext _context;
        private readonly ILogger<KillmailService> _logger;

        public KillmailService(DatabaseContext context, ILogger<KillmailService> logger)
        {
            _context = context;
            _logger = logger;
        }

        public async Task<KillmailResultDto> ProcessKillmailAsync(KillmailReportRequest request)
        {
            await using var transaction = await _context.Database
                .BeginTransactionAsync(System.Data.IsolationLevel.Serializable);

            try
            {
                // Build the JSON data for the killmail
                var killmailData = new
                {
                    request.Attackers,
                    request.DroppedItems,
                    request.DestroyedItems
                };

                var killmail = new Killmail
                {
                    Id = Guid.NewGuid(),
                    VictimId = request.VictimId,
                    FinalStrikerId = request.FinalStrikerId,
                    SolarSystemId = request.SolarSystemId,
                    ShipTypeId = request.ShipTypeId,
                    ShipTypeName = request.ShipTypeName,
                    TotalLossValue = request.TotalLossValue,
                    KillmailDataJson = JsonSerializer.Serialize(killmailData),
                    KilledAt = DateTime.UtcNow
                };

                _context.Killmails.Add(killmail);

                // Update victim stats
                var victim = await _context.Characters.FindAsync(request.VictimId);
                if (victim != null)
                {
                    victim.TotalDeaths++;
                    victim.TotalShipsLost++;
                    victim.TotalISKLost += request.TotalLossValue;
                    _logger.LogInformation("Updated victim stats: CharacterId={VictimId}, Deaths={Deaths}, ShipsLost={ShipsLost}",
                        request.VictimId, victim.TotalDeaths, victim.TotalShipsLost);
                }

                // Update killer stats (final striker)
                var killer = await _context.Characters.FindAsync(request.FinalStrikerId);
                if (killer != null)
                {
                    killer.TotalKills++;
                    killer.TotalShipsDestroyed++;
                    _logger.LogInformation("Updated killer stats: CharacterId={KillerId}, Kills={Kills}, ShipsDestroyed={Destroyed}",
                        request.FinalStrikerId, killer.TotalKills, killer.TotalShipsDestroyed);
                }

                // Update all attackers' kill counts (except final striker to avoid double-counting)
                foreach (var attacker in request.Attackers)
                {
                    if (attacker.CharacterId != request.FinalStrikerId)
                    {
                        var attackerChar = await _context.Characters.FindAsync(attacker.CharacterId);
                        if (attackerChar != null)
                        {
                            attackerChar.TotalKills++;
                        }
                    }
                }

                await _context.SaveChangesAsync();
                await transaction.CommitAsync();

                _logger.LogInformation(
                    "Killmail processed: Id={KillmailId}, Victim={VictimId}, Killer={KillerId}, Ship={ShipType}, Loss={LossValue:N2} ISK",
                    killmail.Id, request.VictimId, request.FinalStrikerId, request.ShipTypeName, request.TotalLossValue);

                return new KillmailResultDto
                {
                    KillmailId = killmail.Id,
                    VictimId = killmail.VictimId,
                    FinalStrikerId = killmail.FinalStrikerId,
                    TotalLossValue = killmail.TotalLossValue,
                    KilledAt = killmail.KilledAt,
                    Message = "Killmail recorded successfully"
                };
            }
            catch (Exception ex)
            {
                await transaction.RollbackAsync();
                _logger.LogError(ex, "Failed to process killmail for VictimId={VictimId}", request.VictimId);
                throw;
            }
        }

        public async Task<KillmailSummaryDto?> GetKillmailAsync(Guid killmailId)
        {
            var killmail = await _context.Killmails
                .Include(k => k.Victim)
                .FirstOrDefaultAsync(k => k.Id == killmailId);

            if (killmail == null) return null;

            return MapToSummary(killmail);
        }

        public async Task<List<KillmailSummaryDto>> GetCharacterKillmailsAsync(Guid characterId, int page = 1, int pageSize = 20)
        {
            var killmails = await _context.Killmails
                .Include(k => k.Victim)
                .Where(k => k.VictimId == characterId || k.FinalStrikerId == characterId)
                .OrderByDescending(k => k.KilledAt)
                .Skip((page - 1) * pageSize)
                .Take(pageSize)
                .ToListAsync();

            return killmails.Select(MapToSummary).ToList();
        }

        public async Task<List<KillmailSummaryDto>> GetSystemKillmailsAsync(Guid solarSystemId, int page = 1, int pageSize = 20)
        {
            var killmails = await _context.Killmails
                .Include(k => k.Victim)
                .Where(k => k.SolarSystemId == solarSystemId)
                .OrderByDescending(k => k.KilledAt)
                .Skip((page - 1) * pageSize)
                .Take(pageSize)
                .ToListAsync();

            return killmails.Select(MapToSummary).ToList();
        }

        private KillmailSummaryDto MapToSummary(Killmail killmail)
        {
            var summary = new KillmailSummaryDto
            {
                KillmailId = killmail.Id,
                VictimId = killmail.VictimId,
                VictimName = killmail.Victim?.Name ?? "Unknown",
                FinalStrikerId = killmail.FinalStrikerId,
                SolarSystemId = killmail.SolarSystemId,
                ShipTypeId = killmail.ShipTypeId,
                ShipTypeName = killmail.ShipTypeName,
                TotalLossValue = killmail.TotalLossValue,
                KilledAt = killmail.KilledAt
            };

            // Parse JSON data for attackers and items
            try
            {
                using var doc = JsonDocument.Parse(killmail.KillmailDataJson);
                var root = doc.RootElement;

                if (root.TryGetProperty("Attackers", out var attackersEl))
                {
                    summary.Attackers = JsonSerializer.Deserialize<List<KillmailAttackerDto>>(attackersEl.GetRawText()) ?? new();
                    summary.AttackerCount = summary.Attackers.Count;
                }

                if (root.TryGetProperty("DroppedItems", out var droppedEl))
                {
                    summary.DroppedItems = JsonSerializer.Deserialize<List<KillmailItemDto>>(droppedEl.GetRawText()) ?? new();
                }

                if (root.TryGetProperty("DestroyedItems", out var destroyedEl))
                {
                    summary.DestroyedItems = JsonSerializer.Deserialize<List<KillmailItemDto>>(destroyedEl.GetRawText()) ?? new();
                }
            }
            catch (JsonException ex)
            {
                _logger.LogWarning(ex, "Failed to parse KillmailDataJson for KillmailId={KillmailId}", killmail.Id);
            }

            return summary;
        }
    }
}
