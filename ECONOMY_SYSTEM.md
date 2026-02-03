# Economy & Trade System - Echoes of Imperial

## Overview
The Echoes of Imperial economy system provides a complete marketplace where pilots can purchase items, ships, and services using their in-game currency (ISK/Credits). All transactions are logged and protected by atomic database operations.

---

## Purchase Flow

### 1. Client Request
```
Client (Blazor) → HTTP POST /api/shop/purchase/{itemId}
                → JWT Token (Authorization header)
```

### 2. Backend Validation
```
┌─────────────────────────────────────────┐
│  ShopController.PurchaseItem()          │
├─────────────────────────────────────────┤
│  1. Extract Character ID from JWT       │
│  2. Find Character in Database          │
│  3. Find ShopItem by ID                 │
│  4. Verify Item IsActive = true         │
│  5. Check WalletBalance >= Price        │
└─────────────────────────────────────────┘
         │
         ├─── [INSUFFICIENT FUNDS]
         │    └─→ 400 BadRequest
         │        {
         │          error: "Imperial Treasury: Insufficient Funds",
         │          currentBalance: 100000,
         │          requiredAmount: 500000,
         │          deficit: 400000
         │        }
         │
         └─── [SUFFICIENT FUNDS]
              └─→ Continue to Transaction
```

### 3. Database Transaction (Atomic)
```sql
BEGIN TRANSACTION

  -- Step 1: Deduct from Wallet
  UPDATE characters 
  SET wallet_balance = wallet_balance - @price
  WHERE id = @characterId;

  -- Step 2: Create Inventory Item
  INSERT INTO player_inventory_items 
  (id, player_id, shop_item_id, quantity, acquired_date, is_redeemed)
  VALUES 
  (@guid, @characterId, @itemId, 1, @now, false);

  -- Step 3: Log Transaction
  INSERT INTO wallet_transactions
  (transaction_id, wallet_id, transaction_type, amount, new_balance, 
   description, reference_id, reference_type, created_at)
  VALUES
  (@txId, @characterId, 2, -@price, @newBalance,
   'Purchased {ItemName} from Imperial Store', @itemId, 'ShopPurchase', @now);

COMMIT TRANSACTION
```

**Transaction Guarantees:**
- ✅ **Atomicity**: All 3 steps succeed or all rollback
- ✅ **Isolation**: Prevents race conditions (double-purchase)
- ✅ **Durability**: Changes are permanent once committed
- ✅ **Consistency**: Balance always matches transaction history

### 4. Response to Client
```json
{
  "success": true,
  "message": "Imperial Treasury: Purchase completed successfully",
  "item": {
    "id": "550e8400-e29b-41d4-a716-446655440000",
    "name": "Quantum Drive Module",
    "price": 500000
  },
  "previousBalance": 1000000,
  "newBalance": 500000,
  "transactionId": 638123456789012345
}
```

### 5. Client UI Update
```
┌──────────────────────────────────────┐
│  ✓ Purchase Successful!              │
│                                      │
│  Item: Quantum Drive Module          │
│  Price: 500,000 ₡                    │
│                                      │
│  Previous Balance: 1,000,000 ₡       │
│  New Balance: 500,000 ₡              │
│                                      │
│  Imperial Treasury: Transaction      │
│  completed.                          │
└──────────────────────────────────────┘
```

---

## Database Schema

### ShopItems Table
```sql
CREATE TABLE shop_items (
    id UUID PRIMARY KEY,
    name VARCHAR(200) NOT NULL,
    description TEXT,
    price BIGINT NOT NULL,           -- Cost in credits
    category VARCHAR(50) NOT NULL,   -- Equipment, Credits, VipStatus, etc.
    image_url VARCHAR(500),
    is_active BOOLEAN DEFAULT TRUE,
    created_at TIMESTAMP DEFAULT NOW()
);
```

**Categories:**
- `Equipment` - Ships, modules, weapons
- `Credits` - ISK/credit bundles
- `VipStatus` - Premium subscriptions
- `Consumables` - Boosters, ammunition
- `Cosmetic` - Ship skins, character customization

### Characters Table (Wallet Integration)
```sql
CREATE TABLE characters (
    id UUID PRIMARY KEY,
    name VARCHAR(50) NOT NULL,
    account_id UUID NOT NULL,
    wallet_balance BIGINT DEFAULT 1000000,  -- Starting balance: 1M ISK
    -- ... other character fields
);
```

**Wallet Balance Rules:**
- Initial balance: 1,000,000 ISK (1M)
- Type: `BIGINT` (range: -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807)
- Allows negative balance (for debt/loans in future)
- Updated via atomic transactions only

### PlayerInventoryItems Table (Redeem Queue)
```sql
CREATE TABLE player_inventory_items (
    id UUID PRIMARY KEY,
    player_id UUID NOT NULL,              -- Owner character
    shop_item_id UUID NOT NULL,           -- Reference to shop_items
    quantity INT DEFAULT 1,
    acquired_date TIMESTAMP DEFAULT NOW(),
    is_redeemed BOOLEAN DEFAULT FALSE,    -- false = pending, true = claimed
    redeemed_date TIMESTAMP,
    notes VARCHAR(500),
    
    FOREIGN KEY (shop_item_id) REFERENCES shop_items(id)
);
```

**Redeem Flow:**
1. Purchase creates item with `is_redeemed = false`
2. Player logs into game (Unreal Engine 5 client)
3. UE5 client calls API to list unredeemed items
4. Player claims items in-game
5. API sets `is_redeemed = true`, `redeemed_date = NOW()`
6. Items appear in player's hangar/inventory

### WalletTransactions Table (Audit Log)
```sql
CREATE TABLE wallet_transactions (
    transaction_id BIGINT PRIMARY KEY,
    wallet_id UUID NOT NULL,              -- Character/wallet ID
    transaction_type INT NOT NULL,        -- See WalletTransactionType enum
    amount DECIMAL(18, 2) NOT NULL,       -- Negative for expenses
    new_balance DECIMAL(18, 2) NOT NULL,  -- Balance after transaction
    description VARCHAR(500),
    reference_id UUID,                    -- Related entity ID
    reference_type VARCHAR(50),           -- e.g., "ShopPurchase"
    created_at TIMESTAMP DEFAULT NOW(),
    
    FOREIGN KEY (wallet_id) REFERENCES character_wallets(wallet_id)
);
```

**Transaction Types (WalletTransactionType enum):**
```csharp
public enum WalletTransactionType
{
    Deposit = 0,
    Withdrawal = 1,
    MarketBuy = 2,      // ← Shop purchases use this
    MarketSell = 3,
    Contract = 4,
    Bounty = 5,
    Mission = 6,
    Corporation = 7,
    Insurance = 8,
    Manufacturing = 9,
    Research = 10,
    PlayerTrade = 11,
    Duel = 12,
    KillRight = 13
}
```

---

## Security Features

### 1. Authentication & Authorization
```csharp
[Authorize] // Requires valid JWT token
[HttpPost("purchase/{id}")]
public async Task<ActionResult> PurchaseItem(Guid id)
```
- ✅ Only authenticated users can purchase
- ✅ Character ID extracted from JWT token
- ✅ No manual character selection (prevents impersonation)

### 2. Admin-Only Item Management
```csharp
[Authorize(Roles = "Admin")]
[HttpPost] // Create item
[HttpPut("{id}")] // Update item
[HttpDelete("{id}")] // Deactivate item
```
- ✅ Only admins can add/edit/remove items
- ✅ Logged in format: `[ADMIN] {username} created shop item: {name}`

### 3. Race Condition Prevention
```csharp
using var transaction = await _context.Database.BeginTransactionAsync();
// ... database operations ...
await transaction.CommitAsync(); // Atomic
```
- ✅ Database transaction isolation
- ✅ Prevents double-purchase (rapid button clicks)
- ✅ Rollback on any error (funds remain safe)

### 4. Balance Validation
```csharp
if (character.WalletBalance < shopItem.Price)
{
    return BadRequest(new { 
        error = "Imperial Treasury: Insufficient Funds",
        deficit = shopItem.Price - character.WalletBalance
    });
}
```
- ✅ Server-side validation (never trust client)
- ✅ Detailed error with exact deficit
- ✅ Transaction aborted before any changes

---

## API Endpoints

### Public Endpoints (Authenticated)

#### Get All Shop Items
```
GET /api/shop
Authorization: Bearer {jwt_token}
```
**Response:**
```json
[
  {
    "id": "550e8400-e29b-41d4-a716-446655440000",
    "name": "Quantum Drive Module",
    "description": "Advanced propulsion system for faster-than-light travel",
    "price": 500000,
    "category": "Equipment",
    "imageUrl": "https://cdn.example.com/items/quantum-drive.png",
    "isActive": true,
    "createdAt": "2026-02-03T12:00:00Z"
  }
]
```

#### Get Item by ID
```
GET /api/shop/{id}
Authorization: Bearer {jwt_token}
```

#### Get Categories
```
GET /api/shop/categories
Authorization: Bearer {jwt_token}
```
**Response:**
```json
{
  "Equipment": 45,
  "Consumables": 23,
  "Cosmetic": 12
}
```

#### Purchase Item
```
POST /api/shop/purchase/{id}
Authorization: Bearer {jwt_token}
```
**Success Response (200 OK):**
```json
{
  "success": true,
  "message": "Imperial Treasury: Purchase completed successfully",
  "item": {
    "id": "550e8400-e29b-41d4-a716-446655440000",
    "name": "Quantum Drive Module",
    "price": 500000
  },
  "previousBalance": 1000000,
  "newBalance": 500000,
  "transactionId": 638123456789012345
}
```

**Error Response (400 Bad Request - Insufficient Funds):**
```json
{
  "error": "Imperial Treasury: Insufficient Funds",
  "currentBalance": 100000,
  "requiredAmount": 500000,
  "deficit": 400000
}
```

**Error Response (404 Not Found):**
```json
{
  "error": "Imperial Treasury: Item not available"
}
```

**Error Response (401 Unauthorized):**
```json
{
  "error": "Imperial Treasury: Authentication required"
}
```

### Admin Endpoints

#### Create Shop Item
```
POST /api/shop
Authorization: Bearer {jwt_token}
X-User-Role: Admin

{
  "name": "Quantum Drive Module",
  "description": "Advanced propulsion system",
  "price": 500000,
  "category": "Equipment",
  "imageUrl": "https://cdn.example.com/items/quantum-drive.png"
}
```

#### Update Shop Item
```
PUT /api/shop/{id}
Authorization: Bearer {jwt_token}
X-User-Role: Admin
```

#### Deactivate Shop Item
```
DELETE /api/shop/{id}
Authorization: Bearer {jwt_token}
X-User-Role: Admin
```
(Soft delete: sets `IsActive = false`)

---

## Testing Checklist

### Balance Tests
- [ ] Purchase item with sufficient funds → Balance decreases by price
- [ ] Purchase item with insufficient funds → 400 error, no balance change
- [ ] Check `wallet_transactions` table for purchase record
- [ ] Verify `new_balance` in transaction matches character balance

### Inventory Tests
- [ ] After purchase, item appears in `player_inventory_items`
- [ ] `is_redeemed` field is `false` initially
- [ ] `shop_item_id` correctly references purchased item
- [ ] `player_id` matches authenticated character

### Security Tests
- [ ] Purchase without JWT token → 401 Unauthorized
- [ ] Purchase with invalid character ID → 404 Not Found
- [ ] Rapid double-click purchase → Only 1 transaction (race condition handled)
- [ ] Admin-only endpoints reject non-admin users

### Transaction Rollback Tests
- [ ] Simulate database error after balance deduction → Full rollback
- [ ] Verify no orphan records in any table
- [ ] Character balance unchanged on error

### UI Tests
- [ ] Successful purchase shows new balance
- [ ] Insufficient funds shows deficit amount
- [ ] Purchase button disabled during transaction (prevent double-click)
- [ ] Error messages display in user-friendly format

---

## Future Enhancements

### Multi-Currency Support
- Implement `CharacterWallet` table for multiple currency types
- Support ISK, PLEX, Aurum, Loyalty Points, Skill Points
- Update purchase flow to specify currency type

### Market System
- Player-to-player trading
- Buy/sell orders
- Market history and price tracking

### Transaction History UI
- View all purchases in account panel
- Filter by date, type, amount
- Export transaction CSV

### Refund System
- Request refund within 24 hours
- Admin approval workflow
- Restore balance and remove item

### Bundle Purchases
- Buy multiple items in single transaction
- Apply discounts for bundles
- Reduce transaction overhead

---

## Support

For technical issues or questions:
- **Backend API**: `Controllers/ShopController.cs`
- **Frontend UI**: `EchoesOfImperial.Client/Pages/Shop.razor`
- **Database Models**: `Models/Entities/Shop/ShopItem.cs`

**Imperial Treasury Status**: ✅ OPERATIONAL
