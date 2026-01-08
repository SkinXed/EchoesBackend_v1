using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using Echoes.API.Models.Entities.Universe;

namespace Echoes.API.Models.Entities.GameServer
{
    [Table("game_servers")]
    public class GameServerNode : BaseEntity
    {
        [Key]
        public new Guid Id { get; set; }

        [Required]
        [MaxLength(50)]
        public string InstanceId { get; set; } = string.Empty;

        // Сетевые данные
        [Required]
        [MaxLength(45)]
        public string PublicIP { get; set; } = "127.0.0.1";

        public int GamePort { get; set; } = 7777;
        public int WebPort { get; set; } = 7778;

        // Одна система (для обратной совместимости)
        [ForeignKey(nameof(SolarSystem))]
        public Guid? SolarSystemId { get; set; }

        // ИЛИ регион (для многосистемности)
        [ForeignKey(nameof(Region))]
        public Guid? RegionId { get; set; }

        // Статус сервера
        public ServerStatus Status { get; set; } = ServerStatus.Starting;

        // Игроки
        public int OnlinePlayers { get; set; } = 0;
        public int MaxPlayers { get; set; } = 1000;

        // Нагрузка
        public float CPUUsage { get; set; } = 0;
        public long MemoryUsageMB { get; set; } = 0;
        public float NetworkInKbps { get; set; } = 0;
        public float NetworkOutKbps { get; set; } = 0;

        // Последний heartbeat
        public DateTime LastHeartbeat { get; set; } = DateTime.UtcNow;

        // Регион для геораспределения
        [MaxLength(10)]
        public string GeoRegion { get; set; } = "EU";

        // Версия
        [MaxLength(20)]
        public string GameVersion { get; set; } = "1.0.0";

        // Новые поля для метаданных
        [MaxLength(100)]
        public string? Hostname { get; set; }

        public string? StartupArguments { get; set; }

        [MaxLength(200)]
        public string? ServerTags { get; set; }

        // Навигационные свойства
        public virtual Universe.SolarSystem? SolarSystem { get; set; }
        public virtual Universe.Region? Region { get; set; }
    }

    public enum ServerStatus
    {
        Starting = 0,
        Ready = 1,
        Full = 2,
        ShuttingDown = 3,
        Maintenance = 4,
        Crashed = 99
    }
}