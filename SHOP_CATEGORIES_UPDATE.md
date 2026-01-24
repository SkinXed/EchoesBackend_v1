# Shop Categories & Items Update

## Summary

Added shop categories and expanded test items for purchase functionality testing as requested.

## Changes Made

### 1. Shop Item Categories

**New Enum**: `Models/Enums/ShopEnums.cs`

```csharp
public enum ShopItemCategory : int
{
    Equipment = 0,      // Ships, weapons, modules
    Credits = 1,        // Credit packages
    VipStatus = 2,      // VIP membership/subscriptions
    Consumables = 3,    // Repair kits, boosters, etc.
    Cosmetic = 4        // Skins, decorations
}
```

### 2. ShopItem Entity Update

**Modified**: `Models/Entities/Shop/ShopItem.cs`

Added Category field:
```csharp
[Column("category")]
public ShopItemCategory Category { get; set; } = ShopItemCategory.Equipment;
```

### 3. Expanded Shop Items (10 Total)

**Modified**: `Services/DbInitializer.cs`

#### Equipment Category (3 items)
- **Frigate Hull - Imperial Vanguard** - 500,000 credits
  - Lightweight frigate for reconnaissance
- **Plasma Cannon MK-VII** - 1,200,000 credits
  - High-energy plasma weapon
- **Repair Nanites (Advanced)** - 350,000 credits (moved to Consumables)
  - Self-replicating repair nanobots

#### Credits Category (3 items - NEW)
- **Credit Package - Starter** - $1.00 (100 price units)
  - Grants 100,000 in-game credits instantly
- **Credit Package - Professional** - $5.00 (500 price units)
  - Grants 500,000 in-game credits instantly
- **Credit Package - Admiral** - $20.00 (2000 price units)
  - Grants 2,000,000 credits + 10% bonus

#### VIP Status Category (3 items - NEW)
- **VIP Status - Bronze (30 Days)** - $5.00
  - Benefits: +10% credit earnings, priority support, Bronze badge, VIP chat
- **VIP Status - Silver (30 Days)** - $10.00
  - Benefits: +20% credits, +10% XP, priority support, Silver badge, VIP lounge, 2 free respawns/day
- **VIP Status - Gold (30 Days)** - $20.00
  - Benefits: +30% credits, +20% XP, 24/7 support, Gold badge, VIP lounge, 5 free respawns/day, early access, gold ship skin

### 4. Enhanced Shop Controller

**Modified**: `Controllers/ShopController.cs`

#### New Features:

**Category Filtering**:
```csharp
[HttpGet]
public async Task<ActionResult<List<ShopItem>>> GetShopItems([FromQuery] ShopItemCategory? category = null)
```

**Category List Endpoint**:
```csharp
[HttpGet("categories")]
public async Task<ActionResult> GetCategories()
```
Returns list of all categories with item counts.

## API Endpoints

### Get Shop Items
```http
GET /api/shop
Authorization: ******
```
Returns all active shop items, ordered by category then price.

### Get Shop Items by Category
```http
GET /api/shop?category=VipStatus
GET /api/shop?category=Credits
GET /api/shop?category=Equipment
Authorization: ******
```

### Get Categories
```http
GET /api/shop/categories
Authorization: ******
```
Returns:
```json
[
  {
    "category": 0,
    "categoryName": "Equipment",
    "itemCount": 2
  },
  {
    "category": 1,
    "categoryName": "Credits",
    "itemCount": 3
  },
  {
    "category": 2,
    "categoryName": "VipStatus",
    "itemCount": 3
  },
  {
    "category": 3,
    "categoryName": "Consumables",
    "itemCount": 1
  }
]
```

### Get Specific Item
```http
GET /api/shop/{id}
Authorization: ******
```

## Testing Guide

### Test Category Filtering
```bash
# Get all VIP items
curl -X GET "https://localhost:5115/api/shop?category=VipStatus" \
  -H "Authorization: ******"

# Get all credit packages
curl -X GET "https://localhost:5115/api/shop?category=Credits" \
  -H "Authorization: ******"

# Get all items
curl -X GET "https://localhost:5115/api/shop" \
  -H "Authorization: ******"
```

### Test Category List
```bash
curl -X GET "https://localhost:5115/api/shop/categories" \
  -H "Authorization: ******"
```

## Database Changes

On first run (or when shop is empty), the DbInitializer will seed:
- 2 Equipment items
- 3 Credits items
- 3 VIP Status items
- 1 Consumables item

Total: **10 test items** for purchase testing

## Price Notes

- **Equipment items**: Priced in in-game credits (e.g., 500,000)
- **Credit packages**: Priced in real money units (e.g., 100 = $1.00, 500 = $5.00)
- **VIP items**: Priced in real money units (e.g., 500 = $5.00)

Note: The Price field stores integers. For real money items, recommend storing cents (e.g., 500 = $5.00) and displaying with appropriate formatting on the client side.

## Future Enhancements

Possible additions:
1. Purchase history tracking
2. Inventory management for purchased items
3. VIP expiration tracking
4. Credit transaction logging
5. Special offers and discounts
6. Bundle packages
7. Seasonal items
8. Limited-time offers

## Commit

Commit: `b05f008` - "Add shop categories: VIP Status, Credits, Equipment with test items"

Files changed:
- `Models/Enums/ShopEnums.cs` (new)
- `Models/Entities/Shop/ShopItem.cs` (modified)
- `Services/DbInitializer.cs` (modified)
- `Controllers/ShopController.cs` (modified)
