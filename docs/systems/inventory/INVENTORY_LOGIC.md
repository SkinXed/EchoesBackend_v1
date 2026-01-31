# Inventory Logic - Volume Mathematics and Item Movement

> **EVE-Inspired Inventory System**  
> Volume-based storage with strict capacity management

---

## Overview

The Echoes inventory system uses **volume** as the primary constraint for storage, matching EVE Online's approach. Every item has a volume, and every container has a maximum capacity.

---

## Core Concepts

### 1. Volume Mathematics

**Fundamental Formula:**
```
V_total = Σ (Quantity_i × UnitVolume_i)
```

Where:
- `V_total` = Total volume occupied
- `Quantity_i` = Number of items in stack i
- `UnitVolume_i` = Volume of one unit of item type i

### 2. Storage Hierarchy

```
Character
├─ Personal Hangar (Station-based)
│  ├─ Container 1
│  │  └─ Items
│  └─ Container 2
│     └─ Items
├─ Ship Cargo Hold
│  └─ Items
├─ Ship Modules (Fitted)
│  ├─ High Slots
│  ├─ Mid Slots
│  └─ Low Slots
└─ Active Ship
```

---

## Database Schema

### Assets Table

**Purpose:** Represents individual item stacks in the world

```sql
CREATE TABLE Assets (
    asset_id UUID PRIMARY KEY DEFAULT gen_random_uuid(),
    type_id INT NOT NULL,              -- FK to AssetTypes
    owner_id UUID NOT NULL,            -- FK to Characters
    location_id UUID NOT NULL,         -- FK to Containers or Ships
    quantity INT NOT NULL DEFAULT 1,
    is_singleton BOOLEAN DEFAULT FALSE, -- True for unique items (fitted modules)
    created_at TIMESTAMP DEFAULT NOW(),
    updated_at TIMESTAMP DEFAULT NOW(),
    
    CONSTRAINT fk_owner FOREIGN KEY (owner_id) REFERENCES Characters(character_id),
    CONSTRAINT fk_type FOREIGN KEY (type_id) REFERENCES AssetTypes(type_id),
    CONSTRAINT positive_quantity CHECK (quantity > 0)
);
```

### AssetTypes Table

**Purpose:** Defines item types and their properties

```sql
CREATE TABLE AssetTypes (
    type_id INT PRIMARY KEY,
    name VARCHAR(255) NOT NULL,
    description TEXT,
    category VARCHAR(100) NOT NULL,    -- Weapon, Armor, Cargo, etc.
    unit_volume DECIMAL(12, 4) NOT NULL, -- m³ per unit
    mass DECIMAL(12, 4) NOT NULL,        -- kg per unit
    max_stack_size INT DEFAULT 1,        -- For stackable items
    is_stackable BOOLEAN DEFAULT FALSE,
    
    CONSTRAINT positive_volume CHECK (unit_volume > 0),
    CONSTRAINT positive_mass CHECK (mass > 0)
);
```

### Containers Table

**Purpose:** Represents storage locations (ships, cargo holds, hangars)

```sql
CREATE TABLE Containers (
    container_id UUID PRIMARY KEY DEFAULT gen_random_uuid(),
    owner_id UUID NOT NULL,           -- FK to Characters
    container_type VARCHAR(50) NOT NULL, -- 'Hangar', 'ShipCargo', etc.
    max_volume DECIMAL(12, 4) NOT NULL, -- Maximum m³ capacity
    used_volume DECIMAL(12, 4) DEFAULT 0, -- Currently occupied m³
    location_system_id INT,            -- FK to Systems (if in space)
    location_station_id INT,           -- FK to Stations (if docked)
    created_at TIMESTAMP DEFAULT NOW(),
    
    CONSTRAINT fk_owner FOREIGN KEY (owner_id) REFERENCES Characters(character_id),
    CONSTRAINT valid_volume CHECK (used_volume >= 0 AND used_volume <= max_volume)
);
```

---

## Volume Calculations

### Backend Service (C#)

```csharp
public class InventoryService : IInventoryService
{
    private readonly ApplicationDbContext _db;
    
    /// <summary>
    /// Calculates total volume of all assets in a container
    /// Formula: V = Σ (Quantity × UnitVolume)
    /// </summary>
    public async Task<decimal> CalculateContainerVolumeAsync(Guid containerId)
    {
        var assets = await _db.Assets
            .Where(a => a.LocationId == containerId)
            .Include(a => a.Type)
            .ToListAsync();
        
        decimal totalVolume = 0;
        foreach (var asset in assets)
        {
            totalVolume += asset.Quantity * asset.Type.UnitVolume;
        }
        
        return totalVolume;
    }
    
    /// <summary>
    /// Validates if adding items would exceed container capacity
    /// </summary>
    public async Task<bool> CanAddItemsAsync(Guid containerId, int typeId, int quantity)
    {
        var container = await _db.Containers.FindAsync(containerId);
        var itemType = await _db.AssetTypes.FindAsync(typeId);
        
        if (container == null || itemType == null)
            return false;
        
        // Calculate volume to add
        decimal volumeToAdd = quantity * itemType.UnitVolume;
        
        // Check if it fits
        decimal availableVolume = container.MaxVolume - container.UsedVolume;
        return volumeToAdd <= availableVolume;
    }
    
    /// <summary>
    /// Updates container's used volume (materialized for performance)
    /// </summary>
    public async Task RecalculateContainerVolumeAsync(Guid containerId)
    {
        var container = await _db.Containers.FindAsync(containerId);
        if (container == null) return;
        
        decimal actualVolume = await CalculateContainerVolumeAsync(containerId);
        
        container.UsedVolume = actualVolume;
        container.UpdatedAt = DateTime.UtcNow;
        
        await _db.SaveChangesAsync();
    }
}
```

### UE5 Client (C++)

```cpp
float UEchoesInventoryComponent::CalculateUsedVolume() const
{
    float TotalVolume = 0.0f;
    
    for (const FEchoesInventoryItem& Item : CachedItems)
    {
        TotalVolume += Item.Quantity * Item.UnitVolume;
    }
    
    return TotalVolume;
}

bool UEchoesInventoryComponent::CanAddItem(int32 TypeId, int32 Quantity) const
{
    // Get item type info
    FEchoesAssetType ItemType = GetAssetTypeInfo(TypeId);
    
    // Calculate volume needed
    float VolumeNeeded = Quantity * ItemType.UnitVolume;
    
    // Check available space
    float AvailableVolume = MaxVolume - CalculateUsedVolume();
    
    return VolumeNeeded <= AvailableVolume;
}
```

---

## Item Movement Rules

### 1. Basic Movement

**Process:**
```
1. Validate Source:
   - Item exists in source container
   - Player owns item
   - Quantity available

2. Validate Destination:
   - Destination container exists
   - Player has access
   - Sufficient volume available

3. Execute Move:
   - Update asset location_id
   - Recalculate source used_volume
   - Recalculate destination used_volume
   - Log transaction

4. Replicate:
   - Notify clients
   - Update UI
```

**Backend Implementation:**
```csharp
public async Task<IActionResult> MoveItemAsync(MoveItemDto request)
{
    // 1. Validate source
    var asset = await _db.Assets
        .Include(a => a.Type)
        .FirstOrDefaultAsync(a => a.AssetId == request.AssetId);
    
    if (asset == null)
        return NotFound("Asset not found");
    
    if (asset.OwnerId != request.CharacterId)
        return Unauthorized("Not your item");
    
    if (asset.Quantity < request.Quantity)
        return BadRequest("Insufficient quantity");
    
    // 2. Validate destination
    var destContainer = await _db.Containers
        .FirstOrDefaultAsync(c => c.ContainerId == request.DestinationId);
    
    if (destContainer == null)
        return NotFound("Destination container not found");
    
    // Check volume
    decimal volumeToMove = request.Quantity * asset.Type.UnitVolume;
    decimal availableVolume = destContainer.MaxVolume - destContainer.UsedVolume;
    
    if (volumeToMove > availableVolume)
        return BadRequest($"Insufficient space. Need {volumeToMove:F2}m³, have {availableVolume:F2}m³");
    
    // 3. Execute move
    if (request.Quantity == asset.Quantity)
    {
        // Move entire stack
        asset.LocationId = request.DestinationId;
    }
    else
    {
        // Split stack
        var newAsset = new Asset
        {
            TypeId = asset.TypeId,
            OwnerId = asset.OwnerId,
            LocationId = request.DestinationId,
            Quantity = request.Quantity
        };
        _db.Assets.Add(newAsset);
        
        asset.Quantity -= request.Quantity;
    }
    
    // Update container volumes
    await RecalculateContainerVolumeAsync(asset.LocationId);
    await RecalculateContainerVolumeAsync(request.DestinationId);
    
    // Log transaction
    var log = new AssetLog
    {
        AssetId = asset.AssetId,
        ActorId = request.CharacterId,
        ActionType = "Move",
        FromLocation = asset.LocationId,
        ToLocation = request.DestinationId,
        Quantity = request.Quantity,
        Timestamp = DateTime.UtcNow
    };
    _db.AssetLogs.Add(log);
    
    await _db.SaveChangesAsync();
    
    return Ok(new { Success = true });
}
```

### 2. Stack Merging

**Rule:** When moving stackable items to a container that already has the same type, merge stacks automatically.

```csharp
public async Task<bool> TryMergeStacksAsync(Guid containerId, int typeId)
{
    var stacks = await _db.Assets
        .Where(a => a.LocationId == containerId && a.TypeId == typeId)
        .Include(a => a.Type)
        .ToListAsync();
    
    if (stacks.Count <= 1) return false;
    
    var itemType = stacks[0].Type;
    if (!itemType.IsStackable) return false;
    
    // Merge all into first stack
    var primaryStack = stacks[0];
    
    for (int i = 1; i < stacks.Count; i++)
    {
        int spaceInPrimary = itemType.MaxStackSize - primaryStack.Quantity;
        int amountToMerge = Math.Min(spaceInPrimary, stacks[i].Quantity);
        
        primaryStack.Quantity += amountToMerge;
        stacks[i].Quantity -= amountToMerge;
        
        // Delete empty stacks
        if (stacks[i].Quantity == 0)
        {
            _db.Assets.Remove(stacks[i]);
        }
        
        // Stop if primary is full
        if (primaryStack.Quantity >= itemType.MaxStackSize)
        {
            break;
        }
    }
    
    await _db.SaveChangesAsync();
    return true;
}
```

### 3. Stack Splitting

**Rule:** Split a stack into multiple stacks

```csharp
public async Task<IActionResult> SplitStackAsync(SplitStackDto request)
{
    var asset = await _db.Assets
        .Include(a => a.Type)
        .FirstOrDefaultAsync(a => a.AssetId == request.AssetId);
    
    if (asset == null)
        return NotFound("Asset not found");
    
    if (!asset.Type.IsStackable)
        return BadRequest("Item is not stackable");
    
    if (request.SplitQuantity >= asset.Quantity)
        return BadRequest("Split quantity must be less than total");
    
    // Create new stack
    var newAsset = new Asset
    {
        TypeId = asset.TypeId,
        OwnerId = asset.OwnerId,
        LocationId = asset.LocationId,
        Quantity = request.SplitQuantity
    };
    _db.Assets.Add(newAsset);
    
    // Reduce original stack
    asset.Quantity -= request.SplitQuantity;
    
    await _db.SaveChangesAsync();
    
    return Ok(new 
    { 
        OriginalStackId = asset.AssetId,
        OriginalQuantity = asset.Quantity,
        NewStackId = newAsset.AssetId,
        NewQuantity = newAsset.Quantity
    });
}
```

---

## Distance Validation

### Rule: Can only interact with inventory within range

**Backend Validation:**
```csharp
public async Task<bool> IsWithinInteractionRangeAsync(Guid characterId, Guid containerId)
{
    var character = await _db.Characters.FindAsync(characterId);
    var container = await _db.Containers.FindAsync(containerId);
    
    if (character == null || container == null)
        return false;
    
    // Same station = always accessible
    if (character.CurrentStationId != null && 
        character.CurrentStationId == container.LocationStationId)
    {
        return true;
    }
    
    // In space - check distance
    if (character.CurrentSystemId == container.LocationSystemId)
    {
        // Would need position data - simplified here
        // In real implementation, check 3D distance
        float distance = CalculateDistance(character.Position, container.Position);
        float maxRange = 2500.0f; // 2.5km interaction range
        
        return distance <= maxRange;
    }
    
    return false;
}
```

**UE5 Client Prediction:**
```cpp
bool UEchoesInventoryComponent::ServerOnly_ValidateDistance(AActor* SourceActor, 
                                                             AActor* TargetActor)
{
    if (!SourceActor || !TargetActor)
        return false;
    
    float Distance = FVector::Dist(
        SourceActor->GetActorLocation(),
        TargetActor->GetActorLocation()
    );
    
    const float MaxInteractionRange = 250000.0f; // 2.5km in cm
    
    return Distance <= MaxInteractionRange;
}
```

---

## Special Cases

### 1. Fitted Modules

**Rule:** Fitted modules are stored as singleton assets with `is_singleton = true`

```sql
-- A fitted 1600mm Armor Plate
INSERT INTO Assets (type_id, owner_id, location_id, quantity, is_singleton)
VALUES (1005, 'character-guid', 'ship-guid', 1, TRUE);
```

**Volume Impact:**
- Fitted modules add **mass** to ship (affects acceleration)
- Fitted modules do NOT occupy cargo volume
- Modules in cargo DO occupy volume

### 2. Ship Cargo Holds

**Container Type:** `ShipCargo`

```csharp
public async Task<ContainerDto> GetShipCargoAsync(Guid shipInstanceId)
{
    // Each ship instance has a cargo container
    var cargoContainer = await _db.Containers
        .FirstOrDefaultAsync(c => 
            c.ContainerType == "ShipCargo" && 
            c.LocationId == shipInstanceId
        );
    
    if (cargoContainer == null)
    {
        // Create cargo container if doesn't exist
        var ship = await _db.ShipInstances
            .Include(s => s.ShipType)
            .FirstOrDefaultAsync(s => s.Id == shipInstanceId);
        
        cargoContainer = new Container
        {
            OwnerId = ship.CharacterId,
            ContainerType = "ShipCargo",
            MaxVolume = ship.ShipType.CargoCapacity,
            LocationId = shipInstanceId
        };
        _db.Containers.Add(cargoContainer);
        await _db.SaveChangesAsync();
    }
    
    return MapToDto(cargoContainer);
}
```

### 3. Station Hangars

**Container Type:** `StationHangar`

```csharp
public async Task<ContainerDto> GetStationHangarAsync(Guid characterId, int stationId)
{
    var hangar = await _db.Containers
        .FirstOrDefaultAsync(c => 
            c.OwnerId == characterId &&
            c.ContainerType == "StationHangar" &&
            c.LocationStationId == stationId
        );
    
    if (hangar == null)
    {
        // Create hangar for this character at this station
        hangar = new Container
        {
            OwnerId = characterId,
            ContainerType = "StationHangar",
            MaxVolume = 10000.0m, // 10,000 m³ default
            LocationStationId = stationId
        };
        _db.Containers.Add(hangar);
        await _db.SaveChangesAsync();
    }
    
    return MapToDto(hangar);
}
```

---

## UI Display

### Inventory Window

**Layout:**
```
┌─────────────────────────────────────────┐
│ Inventory: Ship Cargo                  │
├─────────────────────────────────────────┤
│ Capacity: 1,250 / 2,000 m³ (62.5%)    │
│ [████████████░░░░░░░] Progress Bar     │
├─────────────────────────────────────────┤
│ Item Name          Qty    Volume       │
│ ─────────────────────────────────────  │
│ Veldspar Ore       500    500 m³       │
│ 1600mm Armor Plate  1     500 m³       │
│ Small Shield Ext.   10    250 m³       │
│                                         │
└─────────────────────────────────────────┘
```

**Color Coding:**
- **Green:** < 70% capacity
- **Yellow:** 70-90% capacity
- **Red:** > 90% capacity
- **Flashing Red:** 100% capacity

---

## Performance Optimization

### 1. Materialized Volume

**Problem:** Calculating volume for every query is expensive

**Solution:** Store `used_volume` in Containers table, update on changes

```csharp
// Trigger to keep used_volume synchronized
CREATE OR REPLACE FUNCTION update_container_volume()
RETURNS TRIGGER AS $$
BEGIN
    UPDATE Containers
    SET used_volume = (
        SELECT COALESCE(SUM(a.quantity * at.unit_volume), 0)
        FROM Assets a
        JOIN AssetTypes at ON a.type_id = at.type_id
        WHERE a.location_id = NEW.location_id
    )
    WHERE container_id = NEW.location_id;
    
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER asset_volume_update
AFTER INSERT OR UPDATE OR DELETE ON Assets
FOR EACH ROW
EXECUTE FUNCTION update_container_volume();
```

### 2. Client-Side Caching

**UE5:** Cache inventory items, update on backend response

```cpp
void UEchoesInventoryComponent::Server_RefreshInventory_Implementation()
{
    // Call backend API
    FString Url = FString::Printf(TEXT("%s/api/inventory/container/%s"), 
                                  *ApiBaseUrl, *ContainerId.ToString());
    
    auto Request = FHttpModule::Get().CreateRequest();
    Request->SetURL(Url);
    Request->SetVerb("GET");
    Request->SetHeader("Authorization", FString::Printf(TEXT("Bearer %s"), *JwtToken));
    
    Request->OnProcessRequestComplete().BindLambda([this](
        FHttpRequestPtr Request,
        FHttpResponsePtr Response,
        bool bSuccess)
    {
        if (bSuccess && Response->GetResponseCode() == 200)
        {
            // Parse JSON and update cache
            TArray<FEchoesInventoryItem> Items = ParseInventoryResponse(Response->GetContentAsString());
            CachedItems = Items;
            
            // Broadcast update
            OnInventoryUpdated.Broadcast();
        }
    });
    
    Request->ProcessRequest();
}
```

---

## Transaction Logging

### AssetLogs Table

**Purpose:** Audit trail for all item movements

```sql
CREATE TABLE AssetLogs (
    log_id BIGSERIAL PRIMARY KEY,
    asset_id UUID NOT NULL,
    actor_id UUID NOT NULL,          -- Character who performed action
    action_type VARCHAR(50) NOT NULL, -- 'Move', 'Create', 'Delete', 'Split', 'Merge'
    from_location UUID,
    to_location UUID,
    quantity INT NOT NULL,
    timestamp TIMESTAMP DEFAULT NOW(),
    
    CONSTRAINT fk_asset FOREIGN KEY (asset_id) REFERENCES Assets(asset_id),
    CONSTRAINT fk_actor FOREIGN KEY (actor_id) REFERENCES Characters(character_id)
);

-- Index for querying logs by character
CREATE INDEX idx_assetlogs_actor ON AssetLogs(actor_id, timestamp DESC);

-- Index for querying logs by asset
CREATE INDEX idx_assetlogs_asset ON AssetLogs(asset_id, timestamp DESC);
```

---

## Summary

**Key Principles:**
1. **Volume-based storage:** `V = Σ (Qty × UnitVolume)`
2. **Strict capacity enforcement:** No exceeding max_volume
3. **Server-authoritative:** All moves validated by backend
4. **Audit trail:** Every movement logged
5. **Distance validation:** Range checks for space interactions

**Data Flow:**
```
Client Request → Server Validation → Backend API → Database Update → 
Response → Server Apply → Replicate to Clients → UI Update
```

---

**Last Updated:** 2026-01-31  
**Status:** Implemented  
**Version:** 1.0
