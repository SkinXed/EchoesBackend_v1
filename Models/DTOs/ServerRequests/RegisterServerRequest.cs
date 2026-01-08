using Echoes.API.Models.Entities.GameServer;
using Echoes.API.Models.Enums;
using System.Net;

namespace Echoes.API.DTOs.ServerRequests
{
    public class RegisterServerRequest
    {
        public string InstanceId { get; set; } = string.Empty;
        public string PublicIP { get; set; } = "127.0.0.1";
        public int GamePort { get; set; } = 7777;
        public int WebPort { get; set; } = 7778;
        public Guid? SolarSystemId { get; set; }
        public Guid? RegionId { get; set; }
        public int MaxPlayers { get; set; } = 100;
        public string? GeoRegion { get; set; } = "EU";
        public string? GameVersion { get; set; } = "1.0.0";
        public string? Hostname { get; set; }
        public string? ServerTags { get; set; }

        public void Validate()
        {
            if (string.IsNullOrEmpty(InstanceId))
                throw new ArgumentException("InstanceId is required");

            if (string.IsNullOrEmpty(PublicIP))
                throw new ArgumentException("PublicIP is required");

            if (GamePort <= 0)
                throw new ArgumentException("Invalid GamePort");

            // ИСПРАВЛЕНИЕ: Разрешаем указывать оба ID.
            // Если указаны оба, приоритет будет у RegionId (сервер считается региональным),
            // но SolarSystemId будет указывать на его текущее местоположение (стартовый хаб).
            if (!SolarSystemId.HasValue && !RegionId.HasValue)
                throw new ArgumentException("Must specify either SolarSystemId (Dedicated) or RegionId (Cluster)");
        }
    }
}