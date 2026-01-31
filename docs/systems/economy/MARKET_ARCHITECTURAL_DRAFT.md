# Market System - Architectural Draft

> **EVE-Inspired Player-Driven Economy**  
> Order book system with InventorySubsystem integration

**Status:** Draft  
**Priority:** High  
**Milestone:** 4 - Industrial Loop  
**Dependencies:** Inventory System, Economy Backend

---

## Overview

The Echoes market system implements a player-driven economy using an order book model similar to EVE Online. Players create buy and sell orders that are matched automatically when price conditions are met. The system integrates tightly with the InventorySubsystem to ensure item ownership and transfers are handled correctly.

---

## Core Concepts

### Order Book Model

**Concept:** All trade happens through orders, not direct player-to-player trades.

```
┌────────────────────────────────────────────────────────┐
│                    Order Book                           │
├────────────────────────────────────────────────────────┤
│  SELL ORDERS (Ask)                                     │
│  ┌──────────────────────────────────────────┐         │
│  │ Price    │ Quantity │ Location  │ Expires│         │
│  ├──────────┼──────────┼───────────┼────────┤         │
│  │ 105 ISK  │ 1,000    │ Jita      │ 30d    │ ← Best  │
│  │ 106 ISK  │ 5,000    │ Jita      │ 15d    │         │
│  │ 110 ISK  │ 2,500    │ Amarr     │ 7d     │         │
│  └──────────┴──────────┴───────────┴────────┘         │
│                                                         │
│  ═══════════════ SPREAD ═══════════════                │
│                                                         │
│  BUY ORDERS (Bid)                                      │
│  ┌──────────────────────────────────────────┐         │
│  │ 100 ISK  │ 2,000    │ Jita      │ 30d    │ ← Best  │
│  │ 98 ISK   │ 10,000   │ Jita      │ 20d    │         │
│  │ 95 ISK   │ 8,000    │ Dodixie   │ 10d    │         │
│  └──────────┴──────────┴───────────┴────────┘         │
└────────────────────────────────────────────────────────┘
```

**Key Terms:**
- **Ask (Sell Order):** Player offers to sell item at specified price
- **Bid (Buy Order):** Player offers to buy item at specified price
- **Spread:** Difference between best ask and best bid
- **Fill:** Order is matched and executed
- **Partial Fill:** Only part of order quantity is matched

---

## Database Schema

### MarketOrders Table

```sql
CREATE TABLE MarketOrders (
    order_id UUID PRIMARY KEY DEFAULT gen_random_uuid(),
    character_id UUID NOT NULL,
    region_id INT NOT NULL,
    station_id INT NOT NULL,
    type_id INT NOT NULL,              -- Item type being traded
    order_type VARCHAR(10) NOT NULL,   -- 'BUY' or 'SELL'
    price DECIMAL(15, 2) NOT NULL,     -- Price per unit (ISK)
    quantity_total INT NOT NULL,       -- Original quantity
    quantity_remaining INT NOT NULL,   -- Unfilled quantity
    min_volume INT DEFAULT 1,          -- Minimum buy quantity per fill
    duration_days INT NOT NULL,        -- Order lifetime (1, 3, 7, 14, 30, 90 days)
    escrow_isk DECIMAL(20, 2),         -- ISK held in escrow (buy orders)
    broker_fee DECIMAL(15, 2),         -- Fee paid to create order
    transaction_tax_rate DECIMAL(5, 4), -- Tax rate for this order
    range_km INT,                      -- Buy order range (station, solar system, region)
    issued_at TIMESTAMP DEFAULT NOW(),
    expires_at TIMESTAMP NOT NULL,
    state VARCHAR(20) DEFAULT 'ACTIVE', -- ACTIVE, FILLED, CANCELLED, EXPIRED
    
    CONSTRAINT fk_character FOREIGN KEY (character_id) 
        REFERENCES Characters(character_id),
    CONSTRAINT fk_region FOREIGN KEY (region_id) 
        REFERENCES Regions(region_id),
    CONSTRAINT fk_station FOREIGN KEY (station_id) 
        REFERENCES Stations(station_id),
    CONSTRAINT fk_type FOREIGN KEY (type_id) 
        REFERENCES AssetTypes(type_id),
    CONSTRAINT valid_order_type CHECK (order_type IN ('BUY', 'SELL')),
    CONSTRAINT valid_state CHECK (state IN ('ACTIVE', 'FILLED', 'CANCELLED', 'EXPIRED')),
    CONSTRAINT positive_price CHECK (price > 0),
    CONSTRAINT positive_quantity CHECK (quantity_total > 0 AND quantity_remaining >= 0)
);

-- Indexes for performance
CREATE INDEX idx_market_orders_active ON MarketOrders(state) 
    WHERE state = 'ACTIVE';
CREATE INDEX idx_market_orders_type_region ON MarketOrders(type_id, region_id, state);
CREATE INDEX idx_market_orders_character ON MarketOrders(character_id, state);
CREATE INDEX idx_market_orders_expires ON MarketOrders(expires_at) 
    WHERE state = 'ACTIVE';
```

### MarketTransactions Table

```sql
CREATE TABLE MarketTransactions (
    transaction_id UUID PRIMARY KEY DEFAULT gen_random_uuid(),
    buy_order_id UUID NOT NULL,
    sell_order_id UUID NOT NULL,
    buyer_id UUID NOT NULL,
    seller_id UUID NOT NULL,
    type_id INT NOT NULL,
    quantity INT NOT NULL,
    price_per_unit DECIMAL(15, 2) NOT NULL,
    total_price DECIMAL(20, 2) NOT NULL,
    transaction_tax DECIMAL(15, 2) NOT NULL,
    broker_fee DECIMAL(15, 2) NOT NULL,
    station_id INT NOT NULL,
    timestamp TIMESTAMP DEFAULT NOW(),
    
    CONSTRAINT fk_buy_order FOREIGN KEY (buy_order_id) 
        REFERENCES MarketOrders(order_id),
    CONSTRAINT fk_sell_order FOREIGN KEY (sell_order_id) 
        REFERENCES MarketOrders(order_id),
    CONSTRAINT fk_buyer FOREIGN KEY (buyer_id) 
        REFERENCES Characters(character_id),
    CONSTRAINT fk_seller FOREIGN KEY (seller_id) 
        REFERENCES Characters(character_id)
);

CREATE INDEX idx_market_transactions_buyer ON MarketTransactions(buyer_id, timestamp DESC);
CREATE INDEX idx_market_transactions_seller ON MarketTransactions(seller_id, timestamp DESC);
CREATE INDEX idx_market_transactions_type ON MarketTransactions(type_id, station_id, timestamp DESC);
```

### MarketPriceHistory Table

```sql
CREATE TABLE MarketPriceHistory (
    history_id BIGSERIAL PRIMARY KEY,
    type_id INT NOT NULL,
    region_id INT NOT NULL,
    date DATE NOT NULL,
    average_price DECIMAL(15, 2),
    highest_price DECIMAL(15, 2),
    lowest_price DECIMAL(15, 2),
    volume_traded BIGINT,
    order_count INT,
    
    CONSTRAINT fk_type FOREIGN KEY (type_id) 
        REFERENCES AssetTypes(type_id),
    CONSTRAINT fk_region FOREIGN KEY (region_id) 
        REFERENCES Regions(region_id),
    UNIQUE(type_id, region_id, date)
);

CREATE INDEX idx_price_history_type_date ON MarketPriceHistory(type_id, region_id, date DESC);
```

---

## Order Matching Logic

### Sell Order Matching

**Player wants to sell immediately (Market Sell):**

```cpp
void MatchSellOrder(Guid SellerId, int TypeId, int Quantity, int StationId)
{
    // 1. Find best buy orders (highest price first)
    var buyOrders = await _db.MarketOrders
        .Where(o => o.TypeId == TypeId &&
                    o.OrderType == "BUY" &&
                    o.State == "ACTIVE" &&
                    o.StationId == StationId &&
                    o.QuantityRemaining > 0)
        .OrderByDescending(o => o.Price)
        .ToListAsync();
    
    int remainingQuantity = Quantity;
    
    foreach (var buyOrder in buyOrders)
    {
        if (remainingQuantity <= 0) break;
        
        // Calculate fill quantity
        int fillQuantity = Math.Min(remainingQuantity, buyOrder.QuantityRemaining);
        
        // Execute transaction
        await ExecuteTransaction(
            buyOrderId: buyOrder.OrderId,
            sellerId: SellerId,
            buyerId: buyOrder.CharacterId,
            quantity: fillQuantity,
            pricePerUnit: buyOrder.Price
        );
        
        // Update quantities
        buyOrder.QuantityRemaining -= fillQuantity;
        remainingQuantity -= fillQuantity;
        
        // Mark order as filled if complete
        if (buyOrder.QuantityRemaining == 0)
        {
            buyOrder.State = "FILLED";
        }
    }
    
    // If items remain unsold, create sell order
    if (remainingQuantity > 0)
    {
        throw new Exception($"No buy orders available for {remainingQuantity} items");
    }
    
    await _db.SaveChangesAsync();
}
```

### Buy Order Matching

**Player wants to buy immediately (Market Buy):**

```cpp
void MatchBuyOrder(Guid BuyerId, int TypeId, int Quantity, int StationId)
{
    // 1. Find best sell orders (lowest price first)
    var sellOrders = await _db.MarketOrders
        .Where(o => o.TypeId == TypeId &&
                    o.OrderType == "SELL" &&
                    o.State == "ACTIVE" &&
                    o.StationId == StationId &&
                    o.QuantityRemaining > 0)
        .OrderBy(o => o.Price)
        .ToListAsync();
    
    int remainingQuantity = Quantity;
    decimal totalCost = 0;
    
    foreach (var sellOrder in sellOrders)
    {
        if (remainingQuantity <= 0) break;
        
        int fillQuantity = Math.Min(remainingQuantity, sellOrder.QuantityRemaining);
        decimal cost = fillQuantity * sellOrder.Price;
        
        // Check buyer has enough ISK
        if (totalCost + cost > buyer.WalletBalance)
        {
            throw new Exception("Insufficient ISK");
        }
        
        // Execute transaction
        await ExecuteTransaction(
            sellOrderId: sellOrder.OrderId,
            buyerId: BuyerId,
            sellerId: sellOrder.CharacterId,
            quantity: fillQuantity,
            pricePerUnit: sellOrder.Price
        );
        
        sellOrder.QuantityRemaining -= fillQuantity;
        remainingQuantity -= fillQuantity;
        totalCost += cost;
        
        if (sellOrder.QuantityRemaining == 0)
        {
            sellOrder.State = "FILLED";
        }
    }
    
    if (remainingQuantity > 0)
    {
        throw new Exception($"Insufficient sell orders for {remainingQuantity} items");
    }
    
    await _db.SaveChangesAsync();
}
```

---

## Transaction Execution

### ExecuteTransaction Method

```cpp
async Task ExecuteTransaction(
    Guid buyOrderId, 
    Guid sellOrderId,
    Guid buyerId,
    Guid sellerId,
    int typeId,
    int quantity,
    decimal pricePerUnit,
    int stationId)
{
    decimal totalPrice = quantity * pricePerUnit;
    decimal transactionTax = totalPrice * 0.01m; // 1% sales tax
    decimal brokerFee = totalPrice * 0.005m; // 0.5% broker fee
    
    // 1. Move ISK from buyer to seller
    var buyer = await _db.Characters.FindAsync(buyerId);
    var seller = await _db.Characters.FindAsync(sellerId);
    
    buyer.WalletBalance -= totalPrice;
    seller.WalletBalance += (totalPrice - transactionTax);
    
    // 2. Transfer items using InventorySubsystem
    await TransferItems(
        fromCharacterId: sellerId,
        toCharacterId: buyerId,
        typeId: typeId,
        quantity: quantity,
        fromStationId: stationId,
        toStationId: stationId
    );
    
    // 3. Record transaction
    var transaction = new MarketTransaction
    {
        BuyOrderId = buyOrderId,
        SellOrderId = sellOrderId,
        BuyerId = buyerId,
        SellerId = sellerId,
        TypeId = typeId,
        Quantity = quantity,
        PricePerUnit = pricePerUnit,
        TotalPrice = totalPrice,
        TransactionTax = transactionTax,
        BrokerFee = brokerFee,
        StationId = stationId,
        Timestamp = DateTime.UtcNow
    };
    
    _db.MarketTransactions.Add(transaction);
    
    // 4. Update price history (aggregate daily)
    await UpdatePriceHistory(typeId, stationId, pricePerUnit, quantity);
    
    await _db.SaveChangesAsync();
}
```

---

## InventorySubsystem Integration

### Item Transfer Flow

```
┌──────────────────────────────────────────────────────────┐
│              Market Transaction Flow                      │
└──────────────────────────────────────────────────────────┘

SELL ORDER CREATION:
1. Player lists item for sale
2. Check: Item exists in inventory? ✓
3. Check: Item at correct station? ✓
4. Move item to "Market Escrow" container
5. Create sell order in MarketOrders table
6. Item locked (cannot be moved/used)

BUY ORDER CREATION:
1. Player creates buy order
2. Check: Sufficient ISK? ✓
3. Calculate escrow amount (price × quantity)
4. Deduct escrow from wallet
5. Create buy order with escrow_isk field
6. ISK locked until order filled/cancelled

TRANSACTION EXECUTION:
1. Order matcher finds matching orders
2. Update MarketOrders (quantity_remaining)
3. Create MarketTransaction record
4. Transfer ISK: Buyer → Seller
5. Transfer Items: Seller escrow → Buyer hangar
6. Apply taxes and fees
7. Update wallet balances
8. Notify both parties
```

### Integration Code

```cpp
public interface IInventoryMarketService
{
    // Move item to market escrow (sell order creation)
    Task<bool> MoveToMarketEscrow(
        Guid characterId, 
        Guid assetId, 
        int quantity,
        int stationId
    );
    
    // Transfer sold item to buyer
    Task<bool> TransferSoldItem(
        Guid sellerId,
        Guid buyerId,
        int typeId,
        int quantity,
        int stationId
    );
    
    // Return escrowed item (order cancelled)
    Task<bool> ReturnFromEscrow(
        Guid characterId,
        Guid orderId
    );
    
    // Check item availability for sale
    Task<bool> CanSellItem(
        Guid characterId,
        int typeId,
        int quantity,
        int stationId
    );
}

public class InventoryMarketService : IInventoryMarketService
{
    private readonly ApplicationDbContext _db;
    private readonly IInventoryService _inventory;
    
    public async Task<bool> MoveToMarketEscrow(
        Guid characterId, 
        Guid assetId, 
        int quantity,
        int stationId)
    {
        // Get asset
        var asset = await _db.Assets
            .FirstOrDefaultAsync(a => a.AssetId == assetId && 
                                     a.OwnerId == characterId);
        
        if (asset == null || asset.Quantity < quantity)
            return false;
        
        // Check asset is at correct station
        var container = await _db.Containers
            .FirstOrDefaultAsync(c => c.ContainerId == asset.LocationId);
        
        if (container.LocationStationId != stationId)
            return false;
        
        // Get or create market escrow container
        var escrowContainer = await GetOrCreateMarketEscrow(characterId, stationId);
        
        // Move item to escrow
        if (asset.Quantity == quantity)
        {
            // Move entire stack
            asset.LocationId = escrowContainer.ContainerId;
        }
        else
        {
            // Split stack
            var escrowAsset = new Asset
            {
                TypeId = asset.TypeId,
                OwnerId = characterId,
                LocationId = escrowContainer.ContainerId,
                Quantity = quantity
            };
            _db.Assets.Add(escrowAsset);
            
            asset.Quantity -= quantity;
        }
        
        await _db.SaveChangesAsync();
        return true;
    }
    
    public async Task<bool> TransferSoldItem(
        Guid sellerId,
        Guid buyerId,
        int typeId,
        int quantity,
        int stationId)
    {
        // Get seller's market escrow
        var sellerEscrow = await GetMarketEscrow(sellerId, stationId);
        
        // Get buyer's hangar
        var buyerHangar = await GetOrCreateHangar(buyerId, stationId);
        
        // Find escrowed asset
        var asset = await _db.Assets
            .FirstOrDefaultAsync(a => a.OwnerId == sellerId &&
                                     a.TypeId == typeId &&
                                     a.LocationId == sellerEscrow.ContainerId);
        
        if (asset == null || asset.Quantity < quantity)
            return false;
        
        // Transfer to buyer
        if (asset.Quantity == quantity)
        {
            // Transfer entire stack
            asset.OwnerId = buyerId;
            asset.LocationId = buyerHangar.ContainerId;
        }
        else
        {
            // Transfer partial stack
            var transferAsset = new Asset
            {
                TypeId = asset.TypeId,
                OwnerId = buyerId,
                LocationId = buyerHangar.ContainerId,
                Quantity = quantity
            };
            _db.Assets.Add(transferAsset);
            
            asset.Quantity -= quantity;
        }
        
        await _db.SaveChangesAsync();
        return true;
    }
}
```

---

## Fees and Taxes

### Broker Fees

**Formula:**
```
BrokerFee = OrderValue × BrokerFeeRate

BrokerFeeRate = BaseRate × (1 - StandingModifier) × (1 - SkillModifier)

Where:
- BaseRate = 3.0% (default)
- StandingModifier = (StationOwnerStanding / 10) × 0.3 (max 30% reduction)
- SkillModifier = BrokerRelationsSkill × 0.05 (max 25% reduction at level V)
```

**Example:**
```
Order: 1,000 units @ 100 ISK = 100,000 ISK
Base rate: 3%
Standing: 5.0 (-15% modifier)
Skill: Level 3 (-15% modifier)

BrokerFee = 100,000 × 0.03 × 0.85 × 0.85 = 2,167.5 ISK
```

### Sales Tax

**Formula:**
```
SalesTax = TransactionValue × SalesTaxRate

SalesTaxRate = BaseTaxRate × (1 - SkillModifier)

Where:
- BaseTaxRate = 1.0% (default)
- SkillModifier = AccountingSkill × 0.1 (max 50% reduction at level V)
```

**Paid by:** Seller (deducted from sale proceeds)

### Relist Fee

**When modifying order:** 0-100% of original broker fee, depending on change magnitude

---

## API Endpoints

### Create Order

```
POST /api/market/orders/create
Body: {
    "characterId": "guid",
    "typeId": 12345,
    "orderType": "SELL",
    "price": 105.50,
    "quantity": 1000,
    "stationId": 60003760,
    "duration": 30
}

Response: {
    "success": true,
    "orderId": "guid",
    "brokerFee": 2167.50,
    "escrowAmount": 105500.00
}
```

### Get Order Book

```
GET /api/market/orders?typeId=12345&regionId=10000002

Response: {
    "typeId": 12345,
    "typeName": "Tritanium",
    "sellOrders": [
        {
            "orderId": "guid",
            "price": 105.00,
            "quantity": 1000,
            "stationId": 60003760,
            "stationName": "Jita IV - Moon 4"
        }
    ],
    "buyOrders": [
        {
            "orderId": "guid",
            "price": 100.00,
            "quantity": 5000,
            "stationId": 60003760
        }
    ]
}
```

### Execute Market Transaction

```
POST /api/market/transactions/execute
Body: {
    "characterId": "guid",
    "transactionType": "BUY",
    "typeId": 12345,
    "quantity": 500,
    "stationId": 60003760
}

Response: {
    "success": true,
    "quantityFilled": 500,
    "averagePrice": 104.75,
    "totalCost": 52375.00,
    "salesTax": 523.75,
    "transactionIds": ["guid1", "guid2"]
}
```

---

## Performance Considerations

### Order Book Caching

```cpp
public class MarketOrderCache
{
    private readonly IMemoryCache _cache;
    private const int CacheDurationSeconds = 60;
    
    public async Task<List<MarketOrder>> GetOrderBook(int typeId, int regionId)
    {
        string cacheKey = $"orderbook_{typeId}_{regionId}";
        
        if (_cache.TryGetValue(cacheKey, out List<MarketOrder> orders))
        {
            return orders;
        }
        
        // Query database
        orders = await QueryOrderBook(typeId, regionId);
        
        // Cache for 1 minute
        _cache.Set(cacheKey, orders, TimeSpan.FromSeconds(CacheDurationSeconds));
        
        return orders;
    }
    
    public void InvalidateOrderBook(int typeId, int regionId)
    {
        string cacheKey = $"orderbook_{typeId}_{regionId}";
        _cache.Remove(cacheKey);
    }
}
```

### Query Optimization

```sql
-- Materialized view for best prices
CREATE MATERIALIZED VIEW MarketBestPrices AS
SELECT 
    type_id,
    region_id,
    MIN(CASE WHEN order_type = 'SELL' THEN price END) as best_sell_price,
    MAX(CASE WHEN order_type = 'BUY' THEN price END) as best_buy_price
FROM MarketOrders
WHERE state = 'ACTIVE' AND quantity_remaining > 0
GROUP BY type_id, region_id;

-- Refresh every 5 minutes
REFRESH MATERIALIZED VIEW CONCURRENTLY MarketBestPrices;
```

---

## Testing Checklist

### Functional Tests
- [ ] Create sell order moves item to escrow
- [ ] Create buy order locks ISK in escrow
- [ ] Market buy matches best sell orders
- [ ] Market sell matches best buy orders
- [ ] Partial fills update quantities correctly
- [ ] Completed orders marked as FILLED
- [ ] Broker fees calculated correctly
- [ ] Sales tax applied to seller

### Integration Tests
- [ ] InventorySubsystem transfer works
- [ ] Wallet balances update correctly
- [ ] Transaction logs created
- [ ] Price history updated

### Edge Cases
- [ ] Insufficient ISK for buy order
- [ ] Item not in inventory for sell order
- [ ] Order expiration handling
- [ ] Concurrent order matching (race conditions)
- [ ] Order cancellation refunds

---

## Future Enhancements

1. **Advanced Order Types**
   - Immediate-or-Cancel (IOC)
   - Fill-or-Kill (FOK)
   - Stop-loss orders
   - Trailing stops

2. **Contract System**
   - Item exchange contracts
   - Courier contracts
   - Auction contracts

3. **Market Analytics**
   - Price trend charts
   - Volume analysis
   - Market depth visualization
   - Alert system for price changes

---

**Status:** Draft  
**Last Updated:** 2026-01-31  
**Document Owner:** Economy Team  
**Implementation Estimate:** 8-12 weeks
