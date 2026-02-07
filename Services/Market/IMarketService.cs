using Echoes.API.Models.DTOs.Market;

namespace Echoes.API.Services.Market
{
    public interface IMarketService
    {
        /// <summary>
        /// Получить стакан ордеров для товара в регионе
        /// </summary>
        Task<MarketOrderBookDto> GetRegionOrdersAsync(Guid regionId, int itemId);

        /// <summary>
        /// Создать новый рыночный ордер (Buy или Sell)
        /// </summary>
        Task<CreateOrderResultDto> CreateOrderAsync(CreateOrderRequest request);

        /// <summary>
        /// Исполнить сделку по существующему ордеру
        /// </summary>
        Task<ExecuteTradeResultDto> ExecuteTradeAsync(ExecuteTradeRequest request);

        /// <summary>
        /// Получить ордера персонажа
        /// </summary>
        Task<List<MarketOrderDto>> GetCharacterOrdersAsync(Guid characterId);

        /// <summary>
        /// Рассчитать налоги для предполагаемой сделки
        /// </summary>
        TaxInfoDto CalculateTaxes(decimal price, int quantity);
    }
}
