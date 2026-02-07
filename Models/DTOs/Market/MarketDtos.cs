using Echoes.API.Models.Enums;

namespace Echoes.API.Models.DTOs.Market
{
    // ========== Response DTOs ==========

    /// <summary>
    /// DTO для отображения рыночного ордера (FMarketOrder в UE5)
    /// </summary>
    public class MarketOrderDto
    {
        public Guid OrderId { get; set; }
        public Guid CharacterId { get; set; }
        public int ItemId { get; set; }
        public bool IsBuyOrder { get; set; }
        public decimal Price { get; set; }
        public int Quantity { get; set; }
        public int RemainingQuantity { get; set; }
        public Guid StationId { get; set; }
        public string StationName { get; set; } = string.Empty;
        public Guid RegionId { get; set; }
        public int Duration { get; set; }
        public string Status { get; set; } = string.Empty;
        public decimal BrokerFee { get; set; }
        public DateTime IssuedAt { get; set; }
    }

    /// <summary>
    /// Стакан ордеров для товара в регионе
    /// </summary>
    public class MarketOrderBookDto
    {
        public Guid RegionId { get; set; }
        public int ItemId { get; set; }
        public List<MarketOrderDto> BuyOrders { get; set; } = new();
        public List<MarketOrderDto> SellOrders { get; set; } = new();
    }

    /// <summary>
    /// Результат создания ордера
    /// </summary>
    public class CreateOrderResultDto
    {
        public Guid OrderId { get; set; }
        public decimal BrokerFee { get; set; }
        public decimal EscrowAmount { get; set; }
        public string Message { get; set; } = string.Empty;
    }

    /// <summary>
    /// Результат исполнения сделки
    /// </summary>
    public class ExecuteTradeResultDto
    {
        public Guid OrderId { get; set; }
        public int QuantityTraded { get; set; }
        public decimal TotalPrice { get; set; }
        public decimal TransactionTax { get; set; }
        public string Message { get; set; } = string.Empty;
    }

    /// <summary>
    /// Информация о налогах
    /// </summary>
    public class TaxInfoDto
    {
        public decimal BrokerFeeRate { get; set; }
        public decimal TransactionTaxRate { get; set; }
        public decimal EstimatedBrokerFee { get; set; }
        public decimal EstimatedTransactionTax { get; set; }
    }

    /// <summary>
    /// Результат отмены ордера
    /// </summary>
    public class CancelOrderResultDto
    {
        public Guid OrderId { get; set; }
        public decimal EscrowRefunded { get; set; }
        public string Message { get; set; } = string.Empty;
    }

    // ========== Request DTOs ==========

    /// <summary>
    /// Запрос на создание рыночного ордера
    /// </summary>
    public class CreateOrderRequest
    {
        public Guid CharacterId { get; set; }
        public int ItemId { get; set; }
        public bool IsBuyOrder { get; set; }
        public decimal Price { get; set; }
        public int Quantity { get; set; }
        public Guid StationId { get; set; }
        public int Duration { get; set; } = 90;
    }

    /// <summary>
    /// Запрос на исполнение сделки по существующему ордеру
    /// </summary>
    public class ExecuteTradeRequest
    {
        public Guid CharacterId { get; set; }
        public Guid OrderId { get; set; }
        public int Quantity { get; set; }
    }
}
