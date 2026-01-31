# Station Menu & Personal Hangar Implementation

## Overview

This document describes the implementation of the station interaction system, including the station menu widget and personal hangar functionality for the Echoes MMO project.

## Architecture

### Backend Components

#### 1. Personal Hangar Endpoint
**File**: `Controllers/Inventory/InventoryController.cs`

**Endpoint**: `GET /api/inventory/hangar/{stationId}`

**Purpose**: Retrieves or creates a personal hangar container for the authenticated player at the specified station.

**Response**:
```json
{
  "storageId": "guid",
  "name": "Personal Hangar - Station 1",
  "maxVolume": null,
  "usedVolume": 0.0,
  "availableVolume": null
}
```

**Implementation**:
- Checks for existing hangar container for the player at the station
- If not found, creates a new unlimited-capacity hangar
- Returns the container GUID that can be used with inventory operations

#### 2. Undocking Endpoint
**File**: `Controllers/CharacterController.cs`

**Endpoint**: `POST /api/character/undock`

**Purpose**: Updates the character's docked status to allow undocking from a station.

**Response**:
```json
{
  "message": "Undocked successfully",
  "isDocked": false,
  "activeShipId": "guid"
}
```

#### 3. Hangar Service Logic
**File**: `Services/Inventory/InventoryService.cs`

**Method**: `GetOrCreatePersonalHangarAsync(Guid ownerId, int stationId)`

**Features**:
- Queries database for existing hangar
- Creates new hangar if not found
- Logs all operations for debugging
- Returns ContainerDto for client consumption

### Client Components

#### 1. Station Menu Widget
**Files**: 
- `Client/Echoes/Source/Echoes/UI/EchoesStationMenuWidget.h`
- `Client/Echoes/Source/Echoes/UI/EchoesStationMenuWidget.cpp`

**Class**: `UEchoesStationMenuWidget : public UUserWidget`

**Features**:
- Three main buttons: Inventory, Undock, Repair
- Displays station name and type
- Delegates for Blueprint event handling
- Initialized via `InitializeStationMenu()` method

**Usage**:
```cpp
// In Blueprint or C++
UEchoesStationMenuWidget* MenuWidget = CreateWidget<UEchoesStationMenuWidget>(PlayerController, MenuWidgetClass);
MenuWidget->InitializeStationMenu(StationId, StationName, StationType, HangarStorageId);
MenuWidget->AddToViewport();
```

**Delegate Bindings**:
- `OnInventoryButtonClicked` - Opens hangar inventory
- `OnUndockButtonClicked` - Initiates undocking
- `OnRepairButtonClicked` - Opens repair services (stub)

#### 2. Inventory Subsystem Extension
**File**: `Client/Echoes/Source/Echoes/Core/Common/Networking/EchoesInventorySubsystem.h`

**Method**: `Inventory_RequestPersonalHangar(int32 StationId, FOnHangarReceived OnSuccess, FOnInventoryFailure OnFailure)`

**Purpose**: Asynchronously requests the personal hangar storage ID from the backend.

**Delegate Types**:
```cpp
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnHangarReceived, const FGuid&, HangarStorageId);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnInventoryFailure, const FString&, ErrorMessage);
```

#### 3. Station Actor Integration
**File**: `Client/Echoes/Source/Echoes/Core/Common/StationActor.cpp`

**Docking Flow**:
1. Player enters docking zone (overlap event)
2. Server validates docking access
3. `InitiateDocking()` is called
4. Requests personal hangar from backend
5. `ClientRPC_OpenStationMenu()` is called with station data
6. Client displays station menu widget

**Undocking Flow**:
1. Player clicks Undock button in station menu
2. Blueprint/Widget calls `ServerRPC_RequestUndock()`
3. Server calls `InitiateUndocking()`
4. Backend is notified via undock endpoint
5. Player ship is spawned in space
6. Ship controls are enabled

**RPC Methods**:
- `ClientRPC_OpenStationMenu()` - Opens menu on client
- `ServerRPC_RequestUndock()` - Handles undock request on server

## Data Flow

### Docking Sequence

```
1. Player Ship → Station Docking Zone (Overlap)
   ↓
2. StationActor::OnDockingZoneBeginOverlap() [Server]
   ↓
3. StationActor::InitiateDocking() [Server]
   ↓
4. HTTP GET /api/inventory/hangar/{stationId}
   ↓
5. Backend: InventoryService::GetOrCreatePersonalHangarAsync()
   ↓
6. Response: { storageId: "guid", ... }
   ↓
7. StationActor::ClientRPC_OpenStationMenu() [Client]
   ↓
8. Blueprint creates and displays W_StationMenu widget
   ↓
9. Widget::InitializeStationMenu(stationData, hangarStorageId)
```

### Undocking Sequence

```
1. Player clicks Undock button in station menu
   ↓
2. Widget broadcasts OnUndockButtonClicked delegate
   ↓
3. Blueprint/GameMode calls StationActor::ServerRPC_RequestUndock() [Server]
   ↓
4. StationActor::InitiateUndocking() [Server]
   ↓
5. HTTP POST /api/character/undock
   ↓
6. Backend updates character.IsDocked = false
   ↓
7. Server spawns player ship near station
   ↓
8. Player possesses ship and can fly away
```

## Database Schema

### Container Table
```sql
CREATE TABLE containers (
    container_id UUID PRIMARY KEY,
    owner_id UUID NOT NULL,
    container_type VARCHAR(50) NOT NULL,  -- 'Hangar' for personal hangars
    name VARCHAR(200),
    max_volume DECIMAL NULL,              -- NULL for unlimited
    used_volume DECIMAL DEFAULT 0,
    station_id INT,                       -- Links to station
    is_accessible BOOLEAN DEFAULT true,
    access_level INT DEFAULT 0,
    created_at TIMESTAMP DEFAULT NOW(),
    updated_at TIMESTAMP DEFAULT NOW()
);

-- Index for fast hangar lookup
CREATE INDEX idx_containers_owner_station 
ON containers(owner_id, station_id, container_type);
```

## Blueprint Integration

### Creating W_StationMenu Widget Blueprint

1. **Create Widget Blueprint**:
   - Parent Class: `UEchoesStationMenuWidget`
   - Name: `W_StationMenu`

2. **Add UI Elements**:
   - `InventoryButton` (UButton)
   - `UndockButton` (UButton)
   - `RepairButton` (UButton)
   - `StationNameText` (UTextBlock)
   - `StationTypeText` (UTextBlock)

3. **Bind Delegates**:
   ```cpp
   // In Blueprint Event Graph
   Event OnInventoryButtonClicked → Open W_HangarInventory widget
   Event OnUndockButtonClicked → Call ServerRPC_RequestUndock
   Event OnRepairButtonClicked → Show "Not Implemented" message
   ```

4. **Override ClientRPC_OpenStationMenu** in BP_StationActor:
   ```cpp
   Event ClientRPC_OpenStationMenu
      → Create Widget: W_StationMenu
      → Call InitializeStationMenu(StationName, StationType, HangarStorageId)
      → Add to Viewport
      → Set Input Mode: UI Only
      → Show Mouse Cursor
   ```

## UI Refresh System

### Inventory Updates

The system uses delegates to automatically refresh UI when items are moved:

1. **Component-Level Delegate**:
   ```cpp
   // In UEchoesInventoryComponent
   UPROPERTY(BlueprintAssignable)
   FOnInventoryUpdated OnInventoryUpdated;
   ```

2. **Triggered by**:
   - `ServerOnly_MoveItem()` - After successful move
   - `FetchItems()` - After backend response
   - Manual `RefreshInventory()` calls

3. **Widget Binding**:
   ```cpp
   void UEchoesInventoryWidget::NativeConstruct()
   {
       if (InventoryComponent)
       {
           InventoryComponent->OnInventoryUpdated.AddDynamic(
               this, &UEchoesInventoryWidget::OnInventoryUpdated
           );
       }
   }
   ```

### Dual-Panel Inventory

For ship cargo + hangar view:

1. Left Panel: Ship cargo (uses ship's InventoryComponent)
2. Right Panel: Station hangar (uses hangar StorageId)
3. Both panels bind to respective `OnInventoryUpdated` delegates
4. Move item → Both panels automatically refresh

## TODO & Future Enhancements

### Immediate TODOs
- [ ] Map Station GUIDs to integer IDs for backend compatibility
- [ ] Implement full ship spawning on undock
- [ ] Add docking/undocking animations
- [ ] Implement repair services
- [ ] Add station services menu (market, fitting, etc.)

### Future Features
- [ ] Station market integration
- [ ] Ship fitting service in station
- [ ] Corp hangar access
- [ ] Station manufacturing
- [ ] Contract creation in station
- [ ] Clone bay services

## Testing

### Manual Testing Checklist

1. **Docking**:
   - [ ] Fly ship to station
   - [ ] Enter docking zone
   - [ ] Verify station menu opens
   - [ ] Check station name/type display
   - [ ] Verify hangar storage ID is valid

2. **Inventory**:
   - [ ] Click Inventory button
   - [ ] Verify hangar inventory loads
   - [ ] Move item from ship to hangar
   - [ ] Verify both inventories refresh
   - [ ] Check volume calculations

3. **Undocking**:
   - [ ] Click Undock button
   - [ ] Verify ship spawns near station
   - [ ] Check ship controls are enabled
   - [ ] Verify character state updated

### Backend API Testing

```bash
# Test hangar endpoint
curl -X GET "http://localhost:5000/api/inventory/hangar/1" \
  -H "Authorization: Bearer YOUR_JWT_TOKEN"

# Expected response:
# {
#   "storageId": "guid",
#   "name": "Personal Hangar - Station 1",
#   "maxVolume": null,
#   "usedVolume": 0.0,
#   "availableVolume": null
# }

# Test undock endpoint
curl -X POST "http://localhost:5000/api/character/undock" \
  -H "Authorization: Bearer YOUR_JWT_TOKEN"

# Expected response:
# {
#   "message": "Undocked successfully",
#   "isDocked": false,
#   "activeShipId": "guid"
# }
```

## Troubleshooting

### Common Issues

1. **Station menu doesn't open**:
   - Check ClientRPC is being called on client
   - Verify Blueprint overrides ClientRPC_OpenStationMenu
   - Check widget class is set correctly

2. **Hangar storage ID is empty**:
   - Verify JWT token is valid
   - Check backend logs for errors
   - Ensure station ID mapping is correct

3. **Undocking doesn't work**:
   - Verify ServerRPC is being called on server
   - Check character has active ship
   - Review ship spawning logic

4. **Inventory doesn't refresh**:
   - Check delegates are properly bound
   - Verify OnInventoryUpdated is being broadcast
   - Ensure widget is listening to correct component

## Performance Considerations

- Hangar queries are indexed by (owner_id, station_id, container_type)
- Container creation is lazy (only created when needed)
- Inventory fetches are paginated and cached client-side
- Delegates minimize unnecessary UI updates

## Security

- All endpoints require JWT authentication
- Hangar access is restricted to owner only
- Server validates all undocking requests
- Distance checks prevent remote undocking
