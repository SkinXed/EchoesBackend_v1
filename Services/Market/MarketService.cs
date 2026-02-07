using System.Data;
using Echoes.API.Data;
using Echoes.API.Models.DTOs.Market;
using Echoes.API.Models.Entities.Market;
using Echoes.API.Models.Enums;
using Microsoft.EntityFrameworkCore;

namespace Echoes.API.Services.Market
{
    public class MarketService : IMarketService
    {
        private readonly DatabaseContext _context;
        private readonly ILogger<MarketService> _logger;

        // Налоговые ставки (EVE Online-style)
        private const decimal BrokerFeeRate = 0.03m;       // 3% broker fee
        private const decimal TransactionTaxRate = 0.04m;   // 4% transaction tax

        public MarketService(DatabaseContext context, ILogger<MarketService> logger)
        {
            _context = context;
            _logger = logger;
        }

        public async Task<MarketOrderBookDto> GetRegionOrdersAsync(Guid regionId, int itemId)
        {
            var orders = await _context.MarketOrders
                .Include(o => o.Station)
                .Where(o => o.RegionId == regionId
                         && o.ItemId == itemId
                         && o.Status == MarketOrderStatus.Active
                         && o.RemainingQuantity > 0)
                .ToListAsync();

            var result = new MarketOrderBookDto
            {
                RegionId = regionId,
                ItemId = itemId,
                BuyOrders = orders
                    .Where(o => o.IsBuyOrder)
                    .OrderByDescending(o => o.Price)
                    .Select(MapToDto)
                    .ToList(),
                SellOrders = orders
                    .Where(o => !o.IsBuyOrder)
                    .OrderBy(o => o.Price)
                    .Select(MapToDto)
                    .ToList()
            };

            return result;
        }

        public async Task<CreateOrderResultDto> CreateOrderAsync(CreateOrderRequest request)
        {
            if (request.Price <= 0)
                throw new ArgumentException("Price must be greater than zero");
            if (request.Quantity <= 0)
                throw new ArgumentException("Quantity must be greater than zero");
            if (request.Duration < 1 || request.Duration > 365)
                throw new ArgumentException("Duration must be between 1 and 365 days");

            // Используем Serializable транзакцию для предотвращения double-spend
            await using var transaction = await _context.Database.BeginTransactionAsync(IsolationLevel.Serializable);
            try
            {
                // Проверяем существование станции и получаем RegionId
                var station = await _context.Stations
                    .Include(s => s.SolarSystem)
                    .FirstOrDefaultAsync(s => s.Id == request.StationId);

                if (station == null)
                    throw new InvalidOperationException("Station not found");

                var regionId = station.SolarSystem.RegionId;

                // Получаем ISK-кошелек персонажа
                var wallet = await _context.CharacterWallets
                    .FirstOrDefaultAsync(w => w.CharacterId == request.CharacterId
                                           && w.CurrencyType == CurrencyType.ISK
                                           && w.IsPrimary);

                if (wallet == null)
                    throw new InvalidOperationException("Character wallet not found");

                // Рассчитываем broker fee
                decimal totalOrderValue = request.Price * request.Quantity;
                decimal brokerFee = Math.Round(totalOrderValue * BrokerFeeRate, 2);

                if (request.IsBuyOrder)
                {
                    // Buy Order: списываем залог (escrow) + broker fee
                    decimal totalDeduction = totalOrderValue + brokerFee;
                    if (wallet.Balance < totalDeduction)
                        throw new InvalidOperationException(
                            $"Insufficient funds. Required: {totalDeduction:F2} ISK (escrow: {totalOrderValue:F2} + broker fee: {brokerFee:F2}), available: {wallet.Balance:F2} ISK");

                    wallet.Balance -= totalDeduction;
                    wallet.BalanceUpdatedAt = DateTime.UtcNow;

                    // Записываем транзакции
                    _context.WalletTransactions.Add(new Models.Entities.Character.WalletTransaction
                    {
                        WalletId = wallet.WalletId,
                        TransactionType = WalletTransactionType.MarketEscrow,
                        Amount = totalOrderValue,
                        NewBalance = wallet.Balance + brokerFee,
                        Description = $"Market escrow for buy order: {request.Quantity}x item #{request.ItemId}",
                        CreatedAt = DateTime.UtcNow
                    });
                    _context.WalletTransactions.Add(new Models.Entities.Character.WalletTransaction
                    {
                        WalletId = wallet.WalletId,
                        TransactionType = WalletTransactionType.BrokerFee,
                        Amount = brokerFee,
                        NewBalance = wallet.Balance,
                        Description = $"Broker fee for buy order: {request.Quantity}x item #{request.ItemId}",
                        CreatedAt = DateTime.UtcNow
                    });
                }
                else
                {
                    // Sell Order: списываем только broker fee (предмет блокируется)
                    if (wallet.Balance < brokerFee)
                        throw new InvalidOperationException(
                            $"Insufficient funds for broker fee. Required: {brokerFee:F2} ISK, available: {wallet.Balance:F2} ISK");

                    wallet.Balance -= brokerFee;
                    wallet.BalanceUpdatedAt = DateTime.UtcNow;

                    _context.WalletTransactions.Add(new Models.Entities.Character.WalletTransaction
                    {
                        WalletId = wallet.WalletId,
                        TransactionType = WalletTransactionType.BrokerFee,
                        Amount = brokerFee,
                        NewBalance = wallet.Balance,
                        Description = $"Broker fee for sell order: {request.Quantity}x item #{request.ItemId}",
                        CreatedAt = DateTime.UtcNow
                    });
                }

                // Создаем ордер
                var order = new MarketOrder
                {
                    CharacterId = request.CharacterId,
                    ItemId = request.ItemId,
                    IsBuyOrder = request.IsBuyOrder,
                    Price = request.Price,
                    Quantity = request.Quantity,
                    RemainingQuantity = request.Quantity,
                    StationId = request.StationId,
                    RegionId = regionId,
                    Duration = request.Duration,
                    Status = MarketOrderStatus.Active,
                    BrokerFee = brokerFee,
                    IssuedAt = DateTime.UtcNow
                };

                _context.MarketOrders.Add(order);
                await _context.SaveChangesAsync();
                await transaction.CommitAsync();

                _logger.LogInformation(
                    "Market order created: {OrderId} by {CharacterId} - {Type} {Quantity}x item #{ItemId} @ {Price} ISK",
                    order.Id, request.CharacterId,
                    request.IsBuyOrder ? "BUY" : "SELL",
                    request.Quantity, request.ItemId, request.Price);

                return new CreateOrderResultDto
                {
                    OrderId = order.Id,
                    BrokerFee = brokerFee,
                    EscrowAmount = request.IsBuyOrder ? totalOrderValue : 0,
                    Message = $"{(request.IsBuyOrder ? "Buy" : "Sell")} order created successfully"
                };
            }
            catch
            {
                await transaction.RollbackAsync();
                throw;
            }
        }

        public async Task<ExecuteTradeResultDto> ExecuteTradeAsync(ExecuteTradeRequest request)
        {
            if (request.Quantity <= 0)
                throw new ArgumentException("Quantity must be greater than zero");

            // Используем Serializable транзакцию для предотвращения double-spend
            await using var transaction = await _context.Database.BeginTransactionAsync(IsolationLevel.Serializable);
            try
            {
                // Получаем ордер с блокировкой
                var order = await _context.MarketOrders
                    .Include(o => o.Station)
                    .FirstOrDefaultAsync(o => o.Id == request.OrderId
                                           && o.Status == MarketOrderStatus.Active
                                           && o.RemainingQuantity > 0);

                if (order == null)
                    throw new InvalidOperationException("Order not found or already fulfilled");

                if (order.CharacterId == request.CharacterId)
                    throw new InvalidOperationException("Cannot trade with your own order");

                int quantityToTrade = Math.Min(request.Quantity, order.RemainingQuantity);
                decimal totalPrice = order.Price * quantityToTrade;
                decimal transactionTax = Math.Round(totalPrice * TransactionTaxRate, 2);

                // Получаем кошельки обоих участников
                var buyerWallet = await GetPrimaryIskWalletAsync(
                    order.IsBuyOrder ? order.CharacterId : request.CharacterId);
                var sellerWallet = await GetPrimaryIskWalletAsync(
                    order.IsBuyOrder ? request.CharacterId : order.CharacterId);

                if (buyerWallet == null || sellerWallet == null)
                    throw new InvalidOperationException("Wallet not found for one of the participants");

                if (order.IsBuyOrder)
                {
                    // Покупатель = владелец ордера (деньги уже в escrow)
                    // Продавец = request.CharacterId — получает деньги минус налог
                    decimal sellerReceives = totalPrice - transactionTax;

                    sellerWallet.Balance += sellerReceives;
                    sellerWallet.BalanceUpdatedAt = DateTime.UtcNow;

                    _context.WalletTransactions.Add(new Models.Entities.Character.WalletTransaction
                    {
                        WalletId = sellerWallet.WalletId,
                        TransactionType = WalletTransactionType.MarketSell,
                        Amount = sellerReceives,
                        NewBalance = sellerWallet.Balance,
                        Description = $"Sold {quantityToTrade}x item #{order.ItemId} @ {order.Price} ISK",
                        ReferenceId = order.Id,
                        ReferenceType = "MarketOrder",
                        CreatedAt = DateTime.UtcNow
                    });

                    // Транзакция налога для продавца
                    _context.WalletTransactions.Add(new Models.Entities.Character.WalletTransaction
                    {
                        WalletId = sellerWallet.WalletId,
                        TransactionType = WalletTransactionType.TransactionTax,
                        Amount = transactionTax,
                        NewBalance = sellerWallet.Balance,
                        Description = $"Transaction tax on sale of {quantityToTrade}x item #{order.ItemId}",
                        ReferenceId = order.Id,
                        ReferenceType = "MarketOrder",
                        CreatedAt = DateTime.UtcNow
                    });

                    // Покупателю записываем транзакцию покупки (деньги уже были в escrow)
                    _context.WalletTransactions.Add(new Models.Entities.Character.WalletTransaction
                    {
                        WalletId = buyerWallet.WalletId,
                        TransactionType = WalletTransactionType.MarketBuy,
                        Amount = totalPrice,
                        NewBalance = buyerWallet.Balance,
                        Description = $"Bought {quantityToTrade}x item #{order.ItemId} @ {order.Price} ISK (from escrow)",
                        ReferenceId = order.Id,
                        ReferenceType = "MarketOrder",
                        CreatedAt = DateTime.UtcNow
                    });

                    // Если частичное исполнение — возвращаем неиспользованный escrow
                    if (quantityToTrade < order.RemainingQuantity)
                    {
                        // Escrow уже списан за полное количество; при полном исполнении всё нормально
                        // Возврат escrow произойдет при отмене/истечении оставшейся части
                    }
                }
                else
                {
                    // Sell Order: Покупатель = request.CharacterId — платит деньги
                    // Продавец = владелец ордера — получает деньги минус налог
                    if (buyerWallet.Balance < totalPrice)
                        throw new InvalidOperationException(
                            $"Insufficient funds. Required: {totalPrice:F2} ISK, available: {buyerWallet.Balance:F2} ISK");

                    buyerWallet.Balance -= totalPrice;
                    buyerWallet.BalanceUpdatedAt = DateTime.UtcNow;

                    decimal sellerReceives = totalPrice - transactionTax;
                    sellerWallet.Balance += sellerReceives;
                    sellerWallet.BalanceUpdatedAt = DateTime.UtcNow;

                    // Транзакция покупателя
                    _context.WalletTransactions.Add(new Models.Entities.Character.WalletTransaction
                    {
                        WalletId = buyerWallet.WalletId,
                        TransactionType = WalletTransactionType.MarketBuy,
                        Amount = totalPrice,
                        NewBalance = buyerWallet.Balance,
                        Description = $"Bought {quantityToTrade}x item #{order.ItemId} @ {order.Price} ISK",
                        ReferenceId = order.Id,
                        ReferenceType = "MarketOrder",
                        CreatedAt = DateTime.UtcNow
                    });

                    // Транзакция продавца
                    _context.WalletTransactions.Add(new Models.Entities.Character.WalletTransaction
                    {
                        WalletId = sellerWallet.WalletId,
                        TransactionType = WalletTransactionType.MarketSell,
                        Amount = sellerReceives,
                        NewBalance = sellerWallet.Balance,
                        Description = $"Sold {quantityToTrade}x item #{order.ItemId} @ {order.Price} ISK",
                        ReferenceId = order.Id,
                        ReferenceType = "MarketOrder",
                        CreatedAt = DateTime.UtcNow
                    });

                    // Транзакция налога для продавца
                    _context.WalletTransactions.Add(new Models.Entities.Character.WalletTransaction
                    {
                        WalletId = sellerWallet.WalletId,
                        TransactionType = WalletTransactionType.TransactionTax,
                        Amount = transactionTax,
                        NewBalance = sellerWallet.Balance,
                        Description = $"Transaction tax on sale of {quantityToTrade}x item #{order.ItemId}",
                        ReferenceId = order.Id,
                        ReferenceType = "MarketOrder",
                        CreatedAt = DateTime.UtcNow
                    });
                }

                // Обновляем ордер
                order.RemainingQuantity -= quantityToTrade;
                order.UpdatedAt = DateTime.UtcNow;
                if (order.RemainingQuantity == 0)
                    order.Status = MarketOrderStatus.Fulfilled;

                await _context.SaveChangesAsync();
                await transaction.CommitAsync();

                _logger.LogInformation(
                    "Trade executed: Order {OrderId}, {Quantity}x item #{ItemId} @ {Price} ISK, tax: {Tax} ISK",
                    order.Id, quantityToTrade, order.ItemId, order.Price, transactionTax);

                return new ExecuteTradeResultDto
                {
                    OrderId = order.Id,
                    QuantityTraded = quantityToTrade,
                    TotalPrice = totalPrice,
                    TransactionTax = transactionTax,
                    Message = $"Trade executed: {quantityToTrade}x item #{order.ItemId} @ {order.Price} ISK"
                };
            }
            catch
            {
                await transaction.RollbackAsync();
                throw;
            }
        }

        public async Task<List<MarketOrderDto>> GetCharacterOrdersAsync(Guid characterId)
        {
            var orders = await _context.MarketOrders
                .Include(o => o.Station)
                .Where(o => o.CharacterId == characterId)
                .OrderByDescending(o => o.IssuedAt)
                .ToListAsync();

            return orders.Select(MapToDto).ToList();
        }

        public TaxInfoDto CalculateTaxes(decimal price, int quantity)
        {
            decimal totalValue = price * quantity;
            return new TaxInfoDto
            {
                BrokerFeeRate = BrokerFeeRate,
                TransactionTaxRate = TransactionTaxRate,
                EstimatedBrokerFee = Math.Round(totalValue * BrokerFeeRate, 2),
                EstimatedTransactionTax = Math.Round(totalValue * TransactionTaxRate, 2)
            };
        }

        private async Task<Models.Entities.Character.CharacterWallet?> GetPrimaryIskWalletAsync(Guid characterId)
        {
            return await _context.CharacterWallets
                .FirstOrDefaultAsync(w => w.CharacterId == characterId
                                       && w.CurrencyType == CurrencyType.ISK
                                       && w.IsPrimary);
        }

        private static MarketOrderDto MapToDto(MarketOrder order)
        {
            return new MarketOrderDto
            {
                OrderId = order.Id,
                CharacterId = order.CharacterId,
                ItemId = order.ItemId,
                IsBuyOrder = order.IsBuyOrder,
                Price = order.Price,
                Quantity = order.Quantity,
                RemainingQuantity = order.RemainingQuantity,
                StationId = order.StationId,
                StationName = order.Station?.Name ?? string.Empty,
                RegionId = order.RegionId,
                Duration = order.Duration,
                Status = order.Status.ToString(),
                BrokerFee = order.BrokerFee,
                IssuedAt = order.IssuedAt
            };
        }
    }
}
