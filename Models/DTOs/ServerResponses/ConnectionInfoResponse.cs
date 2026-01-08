namespace Echoes.API.DTOs.ServerResponses
{
    public class ConnectionInfoResponse
    {
        public string PublicIP { get; set; } = string.Empty;
        public int GamePort { get; set; }
        public string ServerInstanceId { get; set; } = string.Empty;
        public Guid RegionId { get; set; }
        public string NodeType { get; set; } = string.Empty; // "DedicatedSystem", "RegionalCluster" или "Fallback"
        public bool RequiresReconnect { get; set; }
        public Guid? CurrentSystemId { get; set; }

        // Для балансировки нагрузки
        public int ServerLoadPercentage { get; set; }
        public int Priority { get; set; }

        // Вспомогательные свойства для клиента
        public string ConnectionString => $"{PublicIP}:{GamePort}";
        public bool IsConnectable => ServerLoadPercentage < 95 && !string.IsNullOrEmpty(PublicIP) && GamePort > 0;
    }
}