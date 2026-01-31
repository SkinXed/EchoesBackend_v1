# UEchoesInventoryComponent Implementation

## Overview

UEchoesInventoryComponent is an Actor Component that provides inventory storage and management functionality for the Echoes MMO game. It can be attached to any Actor (ships, stations, containers) to give them inventory capabilities.

## Architecture

### Component Structure
- **Type**: UActorComponent (can be attached to any Actor)
- **Replication**: Supports server-authoritative inventory operations
- **Communication**: HTTP REST API calls to backend inventory service

### Key Features

1. **Storage Management**
   - StorageId (FGuid): Links to backend Container entity
   - Capacity (float): Maximum volume in cubic meters
   - UsedVolume (float): Currently used volume
   - Support for unlimited capacity (stations, warehouses)

2. **Item Operations**
   - FetchItems(): Retrieve items from backend
   - ServerOnly_MoveItem(): Server-authoritative item transfer with distance validation
   - Automatic cache updates and UI synchronization

3. **Distance Validation**
   - Configurable MaxTransferDistance (default: 2500 meters)
   - Client-side distance checks before server requests
   - Prevents unrealistic item transfers

4. **Visual Synchronization**
   - OnInventoryUpdated multicast delegate
   - Automatic trigger after successful operations
   - UI widgets can bind to receive updates

## Usage

### 1. Attach Component to Actor

```cpp
// In your Ship/Station Actor constructor
InventoryComponent = CreateDefaultSubobject<UEchoesInventoryComponent>(TEXT("InventoryComponent"));
```

### 2. Initialize on Spawn

```cpp
// When spawning from database
void APlayerShip::InitializeFromDatabase(const FShipData& ShipData)
{
    // Initialize inventory with container ID from database
    InventoryComponent->InitializeStorage(ShipData.CargoHoldId, ShipData.CargoCapacity);
    
    // Fetch initial items
    InventoryComponent->FetchItems(
        FOnItemsFetched::CreateUObject(this, &APlayerShip::OnItemsLoaded),
        FOnInventoryOperationFailure::CreateUObject(this, &APlayerShip::OnInventoryError)
    );
}
```

### 3. Server-Side Item Transfer

```cpp
// On server, move item between containers
void APlayerController::MoveItemToContainer(FGuid AssetId, AActor* TargetActor)
{
    if (!HasAuthority())
    {
        return; // Must be called on server
    }
    
    UEchoesInventoryComponent* SourceInventory = GetPawn()->FindComponentByClass<UEchoesInventoryComponent>();
    
    SourceInventory->ServerOnly_MoveItem(
        AssetId,
        TargetActor,
        GetPawn(),
        0, // Move entire stack
        FOnItemMoveSuccess::CreateUObject(this, &APlayerController::OnMoveSuccess),
        FOnInventoryOperationFailure::CreateUObject(this, &APlayerController::OnMoveFailure)
    );
}
```

### 4. UI Binding

```cpp
// In your UMG Widget
void UInventoryWidget::NativeConstruct()
{
    Super::NativeConstruct();
    
    UEchoesInventoryComponent* Inventory = GetOwningPlayerPawn()->FindComponentByClass<UEchoesInventoryComponent>();
    if (Inventory)
    {
        // Bind to inventory updates
        Inventory->OnInventoryUpdated.AddDynamic(this, &UInventoryWidget::OnInventoryChanged);
        
        // Fetch initial data
        Inventory->FetchItems(
            FOnItemsFetched::CreateUObject(this, &UInventoryWidget::PopulateInventory),
            FOnInventoryOperationFailure::CreateUObject(this, &UInventoryWidget::ShowError)
        );
    }
}

void UInventoryWidget::OnInventoryChanged(const FEchoesContainerItems& Items)
{
    // Refresh UI
    PopulateInventory(Items);
}
```

## Backend Integration

### Endpoints Used

1. **GET /api/inventory/container/{containerId}**
   - Fetches all items in a container
   - Returns: AssetListResponse with items, total count, and volume

2. **POST /api/inventory/move**
   - Moves items between containers
   - Request body: MoveItemBetweenContainersRequest
   - Validates capacity and ownership

### Data Flow

1. UE5 Client → UEchoesInventoryComponent → HTTP Request → ASP.NET Backend
2. Backend validates request → Updates database → Returns response
3. Component receives response → Updates cache → Broadcasts OnInventoryUpdated
4. UI widgets receive delegate call → Refresh display

## Configuration

### Component Properties

```cpp
UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory|Storage")
FGuid StorageId; // Set on initialization

UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory|Storage")
float Capacity = 0.0f; // 0 = unlimited

UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory|Transfer")
float MaxTransferDistance = 250000.0f; // In Unreal units (cm)
```

### API Configuration

The component uses GetApiBaseUrl() which returns:
- Default: http://localhost:5116
- Should be configured via game settings or config file

## Persistence

### Database Initialization

When spawning entities from the database:

```cpp
// Ship spawn
void UGameMode::SpawnPlayerShip(const FShipInstanceData& Data)
{
    APlayerShip* Ship = GetWorld()->SpawnActor<APlayerShip>(ShipClass);
    
    // Initialize inventory with DB container ID
    Ship->InventoryComponent->InitializeStorage(
        Data.CargoContainerId,  // From containers table
        Data.CargoCapacity      // From ship_types or ship_instances
    );
}

// Station spawn
void UGameMode::SpawnStation(const FStationData& Data)
{
    AStation* Station = GetWorld()->SpawnActor<AStation>(StationClass);
    
    // Stations typically have unlimited storage
    Station->InventoryComponent->InitializeStorage(
        Data.StorageContainerId,
        0.0f  // Unlimited capacity
    );
}
```

### Container Creation

Containers must be created in the database before use:

```sql
INSERT INTO containers (container_id, owner_id, container_type, max_volume)
VALUES (
    'ship-cargo-guid',
    'player-guid',
    'ShipCargo',
    1000.0  -- 1000 m³ capacity
);
```

## Security

### Server Authority

- All item transfers use ServerOnly_ prefix
- Distance validation happens before backend request
- Backend validates ownership and capacity
- Asset audit logs track all operations

### Authentication

- Requires JWT token from UEchoesAuthSubsystem
- Token automatically attached to HTTP requests
- Backend validates token and extracts actor ID

## Performance Considerations

1. **Caching**: Items are cached locally after fetch
2. **Lazy Loading**: Items fetched on-demand, not on spawn
3. **Batch Operations**: Consider batching multiple moves for efficiency
4. **Distance Checks**: Fast local calculation before expensive HTTP request

## Error Handling

All operations use callbacks for success/failure:

```cpp
FOnInventoryOperationFailure::CreateLambda([](const FString& Error)
{
    UE_LOG(LogTemp, Error, TEXT("Inventory operation failed: %s"), *Error);
    // Show error to player
});
```

Common errors:
- "Storage ID is not initialized" - Call InitializeStorage() first
- "Target too far away" - Reduce distance or increase MaxTransferDistance
- "Authentication required" - Player not logged in
- "Server error: 400" - Invalid request or capacity exceeded

## Testing

### Manual Testing

1. Spawn ship with inventory component
2. Initialize with test container ID
3. Fetch items and verify display
4. Attempt item transfer within/beyond range
5. Verify UI updates after successful move

### Integration Testing

- Requires running backend server
- Mock JWT token for testing
- Test data in database containers/assets tables

## Future Enhancements

- Bulk transfer operations
- Item preview before transfer
- Drag-and-drop UI support
- Automatic sorting/stacking
- Container linking (fleet cargo)
- Market integration
