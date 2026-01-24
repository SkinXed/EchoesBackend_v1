# Web Inventory (Redeem Queue) Implementation

## Overview

Implemented a "Web Inventory" or "Redeem Queue" system - a common pattern in MMO games where purchases made on the website are stored in an intermediate database table before being redeemed in the actual game.

## Architecture Pattern

### Why Web Inventory?

In MMO architecture where Web Server is separated from Game Server:

1. **Player can be offline** - Items purchased on website are stored safely
2. **Ship safety** - Prevents item loss if ship is destroyed during purchase
3. **Location independence** - Player can be in any system when purchasing
4. **Asynchronous processing** - Decouples web purchases from game state

### Flow Diagram

```
Player → Web Shop → Purchase → Web Inventory (PostgreSQL)
                                      ↓
                              Player logs into game
                                      ↓
                              Views Redeem Queue
                                      ↓
                              Clicks "Redeem"
                                      ↓
                              Item transferred to in-game inventory
```

## Implementation Details

### 1. Database Entity

**File**: `Models/Entities/Inventory/PlayerInventoryItem.cs`

```csharp
[Table("player_inventory_items")]
public class PlayerInventoryItem
{
    public Guid Id { get; set; }
    public Guid PlayerId { get; set; }        // Owner (Character ID)
    public Guid ShopItemId { get; set; }      // Reference to shop item
    public virtual ShopItem? ShopItem { get; set; }
    public int Quantity { get; set; } = 1;    // Stack size
    public DateTime AcquiredDate { get; set; }
    public bool IsRedeemed { get; set; } = false;  // false = on web, true = in-game
    public DateTime? RedeemedDate { get; set; }
    public string? Notes { get; set; }
}
```

**Added to DatabaseContext**:
```csharp
public DbSet<PlayerInventoryItem> PlayerInventoryItems { get; set; }
```

### 2. Shared DTOs

**File**: `EchoesOfImperial.Shared/DTOs/InventoryDTOs.cs`

- **InventoryItemDTO** - Display inventory item
- **PurchaseItemRequestDTO** - Purchase request
- **RedeemItemRequestDTO** - Redeem request  
- **PurchaseResponseDTO** - Purchase result

### 3. API Controller

**File**: `Controllers/InventoryController.cs`

All endpoints require `[Authorize]` - JWT authentication.

#### GET /api/inventory

Get current user's web inventory.

**Query Parameters**:
- `includeRedeemed` (bool, default: false) - Include already redeemed items

**Response**: List of `InventoryItemDTO`

```json
[
  {
    "id": "guid",
    "itemName": "Bronze VIP (30 Days)",
    "category": "VipStatus",
    "quantity": 1,
    "imageUrl": "https://...",
    "estimatedValue": 500,
    "acquiredDate": "2026-01-24T05:50:00Z",
    "isRedeemed": false,
    "redeemedDate": null
  }
]
```

#### GET /api/inventory/stats

Get inventory statistics.

**Response**:
```json
{
  "totalItems": 5,
  "unredeemedItems": 3,
  "redeemedItems": 2,
  "totalValue": 1500
}
```

#### POST /api/inventory/purchase

Purchase an item (TEST endpoint - no payment processing yet).

**Request Body**:
```json
{
  "shopItemId": "item-guid",
  "quantity": 1
}
```

**Response**:
```json
{
  "success": true,
  "message": "Successfully purchased 1x Bronze VIP (30 Days). Item added to your web inventory.",
  "inventoryItemId": "new-inventory-guid"
}
```

**Behavior**:
- Validates shop item exists and is active
- Validates quantity > 0
- Creates inventory record with `IsRedeemed = false`
- Returns inventory item ID

#### POST /api/inventory/redeem

Redeem an item from web inventory (mark as redeemed).

**Request Body**:
```json
{
  "inventoryItemId": "inventory-guid"
}
```

**Response**:
```json
{
  "success": true,
  "message": "Successfully redeemed 1x Bronze VIP (30 Days). Item will be available in-game.",
  "itemName": "Bronze VIP (30 Days)"
}
```

**Behavior**:
- Validates item belongs to user
- Checks item not already redeemed
- Sets `IsRedeemed = true` and `RedeemedDate = now`
- In real game: would trigger API call to game server to add item

#### DELETE /api/inventory/{id}

Delete a redeemed item from history (cleanup).

**Response**:
```json
{
  "success": true,
  "message": "Inventory item deleted"
}
```

**Behavior**:
- Only allows deletion of redeemed items
- Prevents deletion of unredeemed items (player must redeem or contact support)

## Security

1. **JWT Required**: All endpoints require valid JWT token
2. **User Isolation**: Players can only access their own inventory
3. **Character Binding**: Uses `CharacterId` from JWT claims
4. **Ownership Validation**: All operations validate item ownership
5. **Redemption Lock**: Prevents double-redemption

## Testing Guide

### 1. Purchase an Item

```bash
# First, get a shop item ID
curl -X GET "https://localhost:5115/api/shop?category=VipStatus" \
  -H "Authorization: ******"

# Purchase the item (test - no payment)
curl -X POST "https://localhost:5115/api/inventory/purchase" \
  -H "Authorization: ******" \
  -H "Content-Type: application/json" \
  -d '{
    "shopItemId": "item-guid-from-shop",
    "quantity": 1
  }'
```

### 2. View Inventory

```bash
# View unredeemed items only
curl -X GET "https://localhost:5115/api/inventory" \
  -H "Authorization: ******"

# View all items (including redeemed)
curl -X GET "https://localhost:5115/api/inventory?includeRedeemed=true" \
  -H "Authorization: ******"
```

### 3. Get Stats

```bash
curl -X GET "https://localhost:5115/api/inventory/stats" \
  -H "Authorization: ******"
```

### 4. Redeem an Item

```bash
curl -X POST "https://localhost:5115/api/inventory/redeem" \
  -H "Authorization: ******" \
  -H "Content-Type: application/json" \
  -d '{
    "inventoryItemId": "inventory-guid-from-your-inventory"
  }'
```

### 5. Delete Redeemed Item

```bash
curl -X DELETE "https://localhost:5115/api/inventory/redeemed-item-guid" \
  -H "Authorization: ******"
```

## Integration with Game Server

### Current Implementation (Web-only)

Currently, the redeem endpoint only marks items as redeemed in the database. This is sufficient for testing and web-only scenarios.

### Future Game Server Integration

When integrating with Unreal Engine 5 game server:

**Option 1: Polling**
- Game server periodically polls `/api/inventory?includeRedeemed=false`
- For each unredeemed item, adds to in-game inventory
- Calls `/api/inventory/redeem` to mark as complete

**Option 2: Webhook/Event**
- When player redeems, API sends webhook to game server
- Game server adds item to in-game inventory
- Game server confirms completion

**Option 3: Direct RPC**
- Redeem endpoint calls game server RPC directly
- Game server adds item immediately
- Returns success/failure to web

### Recommended Approach

For production MMO:

```csharp
[HttpPost("redeem")]
public async Task<ActionResult> RedeemItem([FromBody] RedeemItemRequestDTO request)
{
    // ... validation code ...
    
    // Call game server
    var gameServerResult = await _gameServerService.AddItemToPlayerInventory(
        characterId, 
        inventoryItem.ShopItemId, 
        inventoryItem.Quantity
    );
    
    if (gameServerResult.Success)
    {
        inventoryItem.IsRedeemed = true;
        inventoryItem.RedeemedDate = DateTime.UtcNow;
        await _context.SaveChangesAsync();
        
        return Ok(new { success = true });
    }
    else
    {
        return StatusCode(500, new { error = "Failed to add item in-game" });
    }
}
```

## Database Migration

To apply this schema to your database:

```bash
# Add migration
dotnet ef migrations add AddWebInventory

# Apply migration
dotnet ef database update
```

Or with the in-memory database, it will auto-create on next run.

## Use Cases

### Purchase Flow

1. Player browses web shop
2. Player purchases VIP status or credits
3. Payment processed (Stripe, PayPal, etc.)
4. Item added to `PlayerInventoryItems` with `IsRedeemed = false`
5. Player sees item in web inventory

### Redeem Flow

1. Player logs into game
2. Game shows notification: "You have 3 items waiting"
3. Player opens inventory UI
4. Player clicks "Redeem All" or redeems individually
5. Game calls `/api/inventory/redeem` for each item
6. Items appear in game inventory immediately

### Edge Cases Handled

- **Offline Purchase**: Player can purchase while offline
- **Ship Loss**: Player's ship destroyed doesn't affect web inventory
- **Multiple Characters**: Each character has separate inventory (via PlayerId)
- **Double Redemption**: Prevented by `IsRedeemed` flag
- **Item Deletion**: Only redeemed items can be deleted (keeps unredeemed safe)

## Future Enhancements

1. **Payment Integration**
   - Stripe/PayPal webhooks
   - Transaction receipts
   - Refund handling

2. **Gift System**
   - Transfer inventory items to other players
   - Gift codes/vouchers

3. **Expiration**
   - Time-limited items (event items)
   - Auto-expire after X days

4. **Bundles**
   - Multi-item packages
   - Bulk redemption

5. **Transaction History**
   - Purchase logs
   - Redemption logs
   - Audit trail

6. **Admin Tools**
   - Grant items to players
   - Revoke items
   - View all inventories

## Performance Considerations

- **Indexing**: Index on `PlayerId` and `IsRedeemed` for fast queries
- **Pagination**: Consider pagination for players with many items
- **Caching**: Cache unredeemed count for quick notifications
- **Cleanup**: Periodic job to delete old redeemed items

## Commit

Commit: `21f05d6` - "Implement Web Inventory (Redeem Queue) system for purchased items"

Files changed:
- `Models/Entities/Inventory/PlayerInventoryItem.cs` (new)
- `EchoesOfImperial.Shared/DTOs/InventoryDTOs.cs` (new)
- `Controllers/InventoryController.cs` (new)
- `Data/DatabaseContext.cs` (modified)
