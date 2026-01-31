# AEchoesItemActor Implementation Guide

## Overview

AEchoesItemActor is a universal actor class for representing items and containers in the game world. It supports dynamic mesh loading, physics simulation, player interaction, replication, and auto-cleanup.

## Architecture

```
AEchoesItemActor
├── UStaticMeshComponent (Root)
│   ├── Dynamic mesh loading
│   ├── Physics simulation
│   └── Collision
├── USphereComponent (Interaction)
│   ├── Overlap detection
│   └── Range validation
└── UEchoesInventoryComponent (Storage)
    ├── StorageId
    ├── Capacity
    └── Items
```

## Components

### 1. UStaticMeshComponent (MeshComponent)

**Purpose**: Visual representation in 3D space

**Configuration**:
- Collision: QueryAndPhysics
- Physics: Enabled after mesh load
- Gravity: Disabled (space environment)
- Drag: Zero linear damping (vacuum)
- Rotation: Slight angular damping (0.1)

**Dynamic Loading**:
- Mesh loaded async via `TSoftObjectPtr`
- No freeze on spawn
- Physics enabled after load

### 2. USphereComponent (InteractionSphere)

**Purpose**: Interaction range detection

**Configuration**:
- Radius: `InteractionDistance` (default 250m)
- Collision: Query only
- Overlaps: Pawn channel only

**Usage**:
- Detects when players are in range
- Used by interaction system
- Adjustable per instance

### 3. UEchoesInventoryComponent (InventoryComponent)

**Purpose**: Item storage for containers

**Configuration**:
- Initialized with `InstanceId` from database
- Capacity based on item definition
- Synced with backend

**Conditional**:
- Only active if `bIsContainer = true`
- Null for single items (not containers)

## Initialization Flow

### Server-Side Spawn

```cpp
// Example: Player jettisons cargo
void APlayerController::JettisonCargo(FGuid AssetId, int64 Quantity)
{
    if (!HasAuthority())
        return;

    // Spawn item actor in front of ship
    FVector SpawnLocation = GetPawn()->GetActorLocation() + 
                           GetPawn()->GetActorForwardVector() * 5000.0f;
    
    FActorSpawnParameters SpawnParams;
    SpawnParams.Owner = this;
    
    AEchoesItemActor* ItemActor = GetWorld()->SpawnActor<AEchoesItemActor>(
        AEchoesItemActor::StaticClass(),
        SpawnLocation,
        FRotator::ZeroRotator,
        SpawnParams
    );
    
    if (ItemActor)
    {
        // Initialize with item data
        ItemActor->ServerOnly_InitializeItem("34", AssetId, Quantity);
        
        // Set lifetime (2 hours)
        ItemActor->SetLifetime(7200.0f);
    }
}
```

### Initialization Steps

1. **Spawn Actor** (server-side)
2. **Call ServerOnly_InitializeItem**
   - Sets ItemId, InstanceId, Quantity
   - Triggers replication
3. **LoadItemDefinition**
   - Gets definition from subsystem
   - Starts async mesh load
4. **OnMeshLoaded**
   - Sets mesh on component
   - Enables physics
   - Applies random velocity
5. **OnItemInitialized** (Blueprint event)
   - Custom initialization logic

### Client-Side Replication

1. **ItemId Replicates**
2. **OnRep_ItemId Fires**
3. **LoadItemDefinition** on client
4. **Mesh Loads** async on client
5. **Visual Appears** when ready

## Interaction System

### IEchoesInteractableInterface Implementation

```cpp
// Check if player can interact
bool CanInteract(APawn* Interactor)
{
    // Distance check
    if (!IsWithinInteractionRange(Interactor))
        return false;
    
    // Must be a container
    return bIsContainer && InventoryComponent != nullptr;
}

// Get interaction prompt
FText GetInteractionPrompt()
{
    if (CachedDefinition)
        return FText::Format(TEXT("Open {0} [E]"), CachedDefinition->DisplayName);
    
    return TEXT("Open Container [E]");
}

// Handle interaction
FEchoesInteractionResult OnInteract(APawn* Interactor)
{
    // Server validates distance
    // Opens inventory UI for player
    // Returns success/failure
}
```

### Player Interaction Flow

```
Player Presses E Near Container
    ↓
Client → Server RPC: InteractWithObject()
    ↓
Server: CanInteract() validation
    ├─ Distance check
    ├─ Container check
    └─ Permissions check
    ↓
Server: OnInteract() execution
    ├─ Log interaction
    ├─ Update access list
    └─ Return result
    ↓
Server → Client: OpenInventoryUI()
    ↓
Client: Show UEchoesInventoryWidget
    ├─ SetTargetActor(ItemActor)
    ├─ Display container inventory
    └─ Enable item transfers
```

## Usage Examples

### Jettison Cargo

```cpp
// Player jettisons 100 Tritanium ore
void APlayerShip::JettisonCargo(UEchoesInventoryItemObject* ItemObject, int64 Quantity)
{
    if (!HasAuthority())
        return;

    // Get spawn location (in front of ship)
    FVector SpawnLoc = GetActorLocation() + GetActorForwardVector() * 10000.0f;
    FRotator SpawnRot = FRotator::ZeroRotator;

    // Spawn container
    AEchoesItemActor* Container = GetWorld()->SpawnActor<AEchoesItemActor>(
        AEchoesItemActor::StaticClass(), SpawnLoc, SpawnRot
    );

    if (Container)
    {
        // Initialize as cargo container
        FGuid NewContainerId = FGuid::NewGuid();
        Container->ServerOnly_InitializeItem("CargoContainer", NewContainerId, 1);
        
        // Set 2 hour lifetime
        Container->SetLifetime(7200.0f);
        
        // Move items from ship to container (via backend API)
        // This would trigger the item transfer logic we implemented earlier
        MoveItemToContainer(ItemObject->GetAssetId(), Container, Quantity);
    }
}
```

### Spawn Wreck with Loot

```cpp
// NPC ship destroyed, spawn wreck with loot
void AEnemyShip::OnDestroyed()
{
    if (!HasAuthority())
        return;

    // Spawn wreck at ship location
    AEchoesItemActor* Wreck = GetWorld()->SpawnActor<AEchoesItemActor>(
        AEchoesItemActor::StaticClass(),
        GetActorLocation(),
        GetActorRotation()
    );

    if (Wreck)
    {
        // Initialize as wreck (could be ship hull ID)
        FGuid WreckId = FGuid::NewGuid();
        Wreck->ServerOnly_InitializeItem("ShipWreck_Frigate", WreckId, 1);
        
        // Longer lifetime for wrecks (24 hours)
        Wreck->SetLifetime(86400.0f);
        
        // Populate wreck inventory via backend
        // ...
    }
}
```

### Spawn Deployable Container

```cpp
// Player deploys a cargo container
void APlayerShip::DeployCargoContainer()
{
    if (!HasAuthority())
        return;

    FVector SpawnLoc = GetActorLocation() + FVector(0, 0, -5000.0f);

    AEchoesItemActor* Container = GetWorld()->SpawnActor<AEchoesItemActor>(
        AEchoesItemActor::StaticClass(), SpawnLoc, FRotator::ZeroRotator
    );

    if (Container)
    {
        FGuid ContainerId = FGuid::NewGuid();
        Container->ServerOnly_InitializeItem("SecureContainer", ContainerId, 1);
        
        // Permanent (no lifetime)
        Container->SetLifetime(0.0f);
        
        // Can be anchored (no physics)
        Container->bEnablePhysics = false;
    }
}
```

### Player Loots Container

```cpp
// Player approaches and interacts with container
void APlayerController::InteractWithTarget()
{
    // Trace to find interactable
    FHitResult HitResult;
    if (GetWorld()->LineTraceSingleByChannel(HitResult, ...))
    {
        AActor* HitActor = HitResult.GetActor();
        
        // Check if interactable
        if (HitActor->Implements<UEchoesInteractableInterface>())
        {
            IEchoesInteractableInterface* Interactable = Cast<IEchoesInteractableInterface>(HitActor);
            
            if (Interactable->CanInteract(GetPawn()))
            {
                // Execute interaction (server RPC in real implementation)
                FEchoesInteractionResult Result = Interactable->Execute_OnInteract(HitActor, GetPawn());
                
                if (Result.bSuccess)
                {
                    // Open inventory UI
                    ShowContainerInventory(Cast<AEchoesItemActor>(HitActor));
                }
            }
        }
    }
}

void APlayerController::ShowContainerInventory(AEchoesItemActor* Container)
{
    if (!Container)
        return;

    // Create or get inventory widget
    UEchoesInventoryWidget* Widget = GetInventoryWidget();
    
    if (Widget)
    {
        // Show container's inventory
        Widget->SetTargetActor(Container);
        Widget->AddToViewport();
    }
}
```

## Physics Configuration

### Space Environment

```cpp
// Physics settings for realistic space drift
MeshComponent->SetSimulatePhysics(true);
MeshComponent->SetEnableGravity(false);      // No gravity in space
MeshComponent->SetLinearDamping(0.0f);       // No air resistance
MeshComponent->SetAngularDamping(0.1f);      // Slight rotation damping
```

### Mass Calculation

```cpp
// Mass from item definition
float UnitMass = Definition->UnitMass;  // kg per unit
int64 Quantity = 100;                   // 100 units
float TotalMass = UnitMass * Quantity;  // Total mass

MeshComponent->SetMassOverrideInKg(NAME_None, TotalMass, true);
```

### Random Velocity

```cpp
// Apply on spawn for realistic drift
void ApplyRandomVelocity()
{
    FVector RandomDir = FMath::VRand(); // Random direction
    float Speed = FMath::FRandRange(30.0f, 100.0f); // 30-100 cm/s
    
    FVector Velocity = RandomDir * Speed;
    MeshComponent->SetPhysicsLinearVelocity(Velocity);
    
    // Rotation
    FVector AngularVel = FMath::VRand() * 0.3f;
    MeshComponent->SetPhysicsAngularVelocityInDegrees(AngularVel);
}
```

## Replication

### Replicated Properties

```cpp
UPROPERTY(ReplicatedUsing = OnRep_ItemId)
FString ItemId;                 // Item type ID

UPROPERTY(Replicated)
FGuid InstanceId;               // Instance ID

UPROPERTY(Replicated)
int64 Quantity;                 // Quantity
```

### Replication Flow

```
Server: InitializeItem()
    ↓
Set ItemId, InstanceId, Quantity
    ↓
Properties Replicate to Clients
    ↓
Client: OnRep_ItemId()
    ↓
Client: LoadItemDefinition()
    ↓
Client: AsyncLoadMesh()
    ↓
Client: Visual Appears
```

### Network Optimization

```cpp
// Set relevancy
bAlwaysRelevant = false;        // Only relevant when near
NetCullDistanceSquared = 1500000000.0f; // ~12km relevancy

// Update frequency
NetUpdateFrequency = 1.0f;      // 1 update/sec (static items)
MinNetUpdateFrequency = 0.1f;   // Min 0.1 updates/sec
```

## Lifetime Management

### Auto-Despawn

```cpp
// Set lifetime on initialization
ItemActor->SetLifetime(7200.0f);  // 2 hours

// Timer automatically destroys actor
// Can be extended:
ItemActor->SetLifetime(10800.0f); // Extend to 3 hours

// Make permanent:
ItemActor->SetLifetime(0.0f);     // Never despawn
```

### Lifetime Query

```cpp
// Check remaining time
float Remaining = ItemActor->GetRemainingLifetime();
if (Remaining > 0.0f)
{
    UE_LOG(LogTemp, Log, TEXT("Container expires in %.0f seconds"), Remaining);
}
else if (Remaining < 0.0f)
{
    // Infinite lifetime
}
```

### Cleanup Logic

```cpp
void OnLifetimeExpired()
{
    // Log for debugging
    UE_LOG(LogTemp, Log, TEXT("Container %s expired"), *GetName());
    
    // Server destroys actor
    Destroy();
    
    // Note: Inventory data should be cleaned from database
    // via backend API before destroying
}
```

## HISM Optimization

### Problem: Many Items in Space

If you have 1000+ ore chunks floating in space, individual actors are expensive.

### Solution: Hierarchical Instanced Static Mesh

```cpp
UCLASS()
class AEchoesItemManager : public AActor
{
    GENERATED_BODY()

public:
    // One HISM component per item type
    UPROPERTY()
    TMap<FString, UHierarchicalInstancedStaticMeshComponent*> ItemMeshes;

    void SpawnItemInstance(const FString& ItemId, FVector Location, int64 Quantity)
    {
        // Get or create HISM component for this item type
        UHierarchicalInstancedStaticMeshComponent* HISM = ItemMeshes.FindOrAdd(ItemId);
        
        if (!HISM)
        {
            HISM = NewObject<UHierarchicalInstancedStaticMeshComponent>(this);
            HISM->RegisterComponent();
            
            // Load mesh async
            UEchoesInventorySubsystem* InvSys = GetGameInstance()->GetSubsystem<UEchoesInventorySubsystem>();
            InvSys->AsyncLoadItemWorldMesh(ItemId, FOnWorldMeshLoaded::CreateLambda(
                [HISM](UStaticMesh* Mesh)
                {
                    if (Mesh)
                    {
                        HISM->SetStaticMesh(Mesh);
                    }
                }
            ));
            
            ItemMeshes.Add(ItemId, HISM);
        }
        
        // Add instance
        FTransform Transform;
        Transform.SetLocation(Location);
        Transform.SetRotation(FQuat(FMath::VRand(), FMath::FRandRange(0, 360)));
        
        int32 InstanceIndex = HISM->AddInstance(Transform);
        
        // Store metadata (quantity, etc.) in separate array indexed by InstanceIndex
    }
    
    void RemoveItemInstance(const FString& ItemId, int32 InstanceIndex)
    {
        if (UHierarchicalInstancedStaticMeshComponent** HISM = ItemMeshes.Find(ItemId))
        {
            (*HISM)->RemoveInstance(InstanceIndex);
        }
    }
};
```

**Benefits**:
- 1000+ items with minimal performance cost
- One draw call per item type
- Automatic LOD and culling
- Reduced CPU overhead

**Tradeoffs**:
- No individual physics per instance
- No individual inventories
- Best for visual-only items (ore chunks, debris)

### When to Use HISM

**Use HISM for**:
- Visual-only items (ore fields)
- Debris fields
- Asteroid fields
- Non-interactable decorations

**Use AEchoesItemActor for**:
- Loot containers (with inventory)
- Interactable objects
- Items needing physics
- Items with unique state

## LOD (Level of Detail)

### Mesh LOD Configuration

```cpp
// When importing static mesh
LOD 0: Full detail
  Vertices: 5000
  Distance: 0 - 1000m
  
LOD 1: Medium detail
  Vertices: 2000
  Distance: 1000 - 5000m
  
LOD 2: Low detail
  Vertices: 500
  Distance: 5000 - 10000m
  
LOD 3: Very low / Billboard
  Vertices: 100
  Distance: 10000m+
```

### Auto LOD in Code

```cpp
// Set LOD distances
TArray<float> LODDistances = {1000.0f, 5000.0f, 10000.0f};
for (int32 i = 0; i < LODDistances.Num(); i++)
{
    MeshComponent->SetLODDistanceFactor(LODDistances[i]);
}

// Force LOD update
MeshComponent->MarkRenderStateDirty();
```

## Replication Best Practices

### Property Replication

```cpp
void AEchoesItemActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    // Always replicate
    DOREPLIFETIME(AEchoesItemActor, ItemId);
    DOREPLIFETIME(AEchoesItemActor, InstanceId);
    DOREPLIFETIME(AEchoesItemActor, Quantity);
    
    // Optional: Replicate only to owner
    // DOREPLIFETIME_CONDITION(AEchoesItemActor, SomeProperty, COND_OwnerOnly);
}
```

### OnRep Functions

```cpp
UFUNCTION()
void OnRep_ItemId()
{
    // Called when ItemId changes on client
    LoadItemDefinition();
}
```

### Relevancy

```cpp
// In constructor
bAlwaysRelevant = false;              // Not always relevant
NetCullDistanceSquared = 1500000000.0f; // ~12km

// Custom relevancy (advanced)
bool IsNetRelevantFor(const AActor* RealViewer, const AActor* ViewTarget, const FVector& SrcLocation) const override
{
    // Only relevant within 10km
    float DistSquared = (SrcLocation - GetActorLocation()).SizeSquared();
    return DistSquared < 10000000000.0f; // 10km²
}
```

## Advanced Features

### Container Types

```cpp
// Different container types with different properties

// Secure Container (long lifetime, large capacity)
ItemActor->ServerOnly_InitializeItem("SecureContainer", ContainerId, 1);
ItemActor->SetLifetime(0.0f); // Permanent
ItemActor->bEnablePhysics = false; // Anchored

// Jetcan (short lifetime, small capacity)
ItemActor->ServerOnly_InitializeItem("Jetcan", ContainerId, 1);
ItemActor->SetLifetime(1800.0f); // 30 minutes
ItemActor->bEnablePhysics = true; // Drifts

// Wreck (medium lifetime, random loot)
ItemActor->ServerOnly_InitializeItem("Wreck_Frigate", WreckId, 1);
ItemActor->SetLifetime(7200.0f); // 2 hours
ItemActor->bEnablePhysics = true;
ItemActor->bApplyRandomVelocity = true; // Drifts from explosion
```

### Access Control

```cpp
// Advanced: Check if player has access rights
bool CanInteract_Implementation(APawn* Interactor) const override
{
    // Distance check
    if (!IsWithinInteractionRange(Interactor))
        return false;
    
    // Owner check (for secure containers)
    if (bOwnerOnly)
    {
        APawn* OwnerPawn = Cast<APawn>(GetOwner());
        if (OwnerPawn != Interactor)
            return false;
    }
    
    // Corporation check (for corp containers)
    if (bCorpOnly)
    {
        // Check corp membership
        // ...
    }
    
    return true;
}
```

### Visual Effects

```cpp
// Highlight when player is in range
void AEchoesItemActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
    Super::NotifyActorBeginOverlap(OtherActor);
    
    if (APawn* Pawn = Cast<APawn>(OtherActor))
    {
        // Player entered interaction range
        if (CanInteract(Pawn))
        {
            // Show outline or glow
            MeshComponent->SetRenderCustomDepth(true);
            MeshComponent->SetCustomDepthStencilValue(1);
        }
    }
}

void AEchoesItemActor::NotifyActorEndOverlap(AActor* OtherActor)
{
    Super::NotifyActorEndOverlap(OtherActor);
    
    // Remove highlight
    MeshComponent->SetRenderCustomDepth(false);
}
```

## Testing

### Spawn Test

```cpp
// Test spawning various item types
void TestItemSpawning()
{
    TArray<FString> TestItems = {"34", "56", "123"}; // Different items
    
    for (int32 i = 0; i < TestItems.Num(); i++)
    {
        FVector Loc = FVector(i * 10000.0f, 0, 0);
        
        AEchoesItemActor* Item = GetWorld()->SpawnActor<AEchoesItemActor>(
            AEchoesItemActor::StaticClass(), Loc, FRotator::ZeroRotator
        );
        
        if (Item)
        {
            Item->ServerOnly_InitializeItem(TestItems[i], FGuid::NewGuid(), 100);
        }
    }
}
```

### Interaction Test

```cpp
// Test interaction system
void TestInteraction()
{
    // Find nearest item actor
    TArray<AActor*> FoundActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEchoesItemActor::StaticClass(), FoundActors);
    
    for (AActor* Actor : FoundActors)
    {
        AEchoesItemActor* ItemActor = Cast<AEchoesItemActor>(Actor);
        
        if (ItemActor && ItemActor->CanInteract(GetPawn()))
        {
            FEchoesInteractionResult Result = ItemActor->Execute_OnInteract(ItemActor, GetPawn());
            
            UE_LOG(LogTemp, Log, TEXT("Interaction: %s - %s"),
                Result.bSuccess ? TEXT("Success") : TEXT("Failed"),
                *Result.Message);
        }
    }
}
```

### Lifetime Test

```cpp
// Test auto-despawn
void TestLifetime()
{
    AEchoesItemActor* Item = SpawnTestItem();
    
    // Set 60 second lifetime for testing
    Item->SetLifetime(60.0f);
    
    // Check remaining time
    float Remaining = Item->GetRemainingLifetime();
    UE_LOG(LogTemp, Log, TEXT("Item will despawn in %.0f seconds"), Remaining);
    
    // After 60 seconds, item should be destroyed automatically
}
```

## Performance Considerations

### Spawning Performance

**Problem**: Spawning 100 containers causes freeze while loading meshes

**Solution**: Async mesh loading
```cpp
// Meshes load in background
// No freeze on spawn
// Visual appears when ready
```

**Batch Spawning**:
```cpp
void SpawnLootField(TArray<FLootItem>& Items)
{
    for (const FLootItem& Item : Items)
    {
        // Stagger spawns
        FTimerHandle Handle;
        GetWorldTimerManager().SetTimer(Handle, [this, Item]()
        {
            SpawnLootItem(Item);
        }, 0.1f * Items.IndexOfByKey(Item), false);
    }
}
```

### Memory Management

**Soft References**:
- WorldMesh as `TSoftObjectPtr`
- Only loaded when spawned
- Auto-unloaded when destroyed

**Actor Pooling** (Advanced):
```cpp
// Instead of Destroy(), deactivate and pool
void ReturnToPool(AEchoesItemActor* Item)
{
    Item->SetActorHiddenInGame(true);
    Item->SetActorEnableCollision(false);
    Item->SetActorTickEnabled(false);
    
    ItemPool.Add(Item);
}

AEchoesItemActor* GetFromPool()
{
    if (ItemPool.Num() > 0)
    {
        AEchoesItemActor* Item = ItemPool.Pop();
        Item->SetActorHiddenInGame(false);
        Item->SetActorEnableCollision(true);
        return Item;
    }
    
    return SpawnNewItem();
}
```

### Culling

```cpp
// Automatically cull distant items
// Unreal handles this via NetCullDistanceSquared

// Manual culling for non-networked sessions
void CullDistantItems(FVector PlayerLocation)
{
    TArray<AActor*> Items;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEchoesItemActor::StaticClass(), Items);
    
    for (AActor* Actor : Items)
    {
        float Dist = FVector::Dist(PlayerLocation, Actor->GetActorLocation());
        
        if (Dist > 50000.0f) // 500m
        {
            Actor->SetActorHiddenInGame(true);
        }
        else
        {
            Actor->SetActorHiddenInGame(false);
        }
    }
}
```

## Blueprint Integration

### Blueprint Events

```cpp
// Override in Blueprint for custom behavior

Event OnItemInitialized()
{
    // Called after initialization
    // Play spawn effect
    // Add to tracked items list
}

Event OnPlayerInteracted(Pawn Interactor)
{
    // Called when player interacts
    // Play open sound
    // Show notification
}
```

### Blueprint Usage

```cpp
// Spawn from Blueprint
Event SpawnLootContainer
{
    Spawn Actor: EchoesItemActor
    Location: Player Forward + 1000cm
    
    ↓
    
    ServerOnly InitializeItem
    Item ID: "CargoContainer"
    Instance ID: New Guid
    Quantity: 1
    
    ↓
    
    Set Lifetime: 7200
}
```

## Collision Configuration

### Mesh Collision

```cpp
// Container collision
MeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
MeshComponent->SetCollisionObjectType(ECC_PhysicsBody);
MeshComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Block);
MeshComponent->SetCollisionResponseToChannel(ECC_Vehicle, ECR_Block);
```

### Interaction Collision

```cpp
// Interaction sphere (overlap only)
InteractionSphere->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
InteractionSphere->SetCollisionResponseToAllChannels(ECR_Ignore);
InteractionSphere->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
```

## Complete Example

### Full Jettison System

```cpp
// 1. Player jettisons cargo from ship
void APlayerShip::JettisonItem(FGuid AssetId, int64 Quantity)
{
    if (!HasAuthority())
        return;

    // Calculate spawn location
    FVector SpawnLoc = GetActorLocation() + GetActorForwardVector() * 10000.0f;
    FRotator SpawnRot = FMath::VRand().Rotation();

    // Spawn container actor
    AEchoesItemActor* Container = GetWorld()->SpawnActor<AEchoesItemActor>(
        AEchoesItemActor::StaticClass(),
        SpawnLoc,
        SpawnRot
    );

    if (!Container)
        return;

    // Initialize container
    FGuid ContainerId = FGuid::NewGuid();
    Container->ServerOnly_InitializeItem("Jetcan", ContainerId, 1);
    Container->SetLifetime(1800.0f); // 30 minutes

    // Create container in backend database
    // POST /api/inventory/container/create
    // ...

    // Move items from ship to container
    InventoryComponent->ServerOnly_MoveItem(
        AssetId,
        Container,
        this,
        Quantity,
        FOnItemMoveSuccess::CreateLambda([this]()
        {
            UE_LOG(LogTemp, Log, TEXT("Item jettisoned successfully"));
        }),
        FOnInventoryOperationFailure::CreateLambda([](const FString& Error)
        {
            UE_LOG(LogTemp, Error, TEXT("Jettison failed: %s"), *Error);
        })
    );
}

// 2. Player finds and loots container
void APlayerController::LootContainer(AEchoesItemActor* Container)
{
    if (!Container || !Container->CanInteract(GetPawn()))
        return;

    // Server RPC to interact
    ServerInteractWithContainer(Container);
}

void APlayerController::ServerInteractWithContainer_Implementation(AEchoesItemActor* Container)
{
    if (!Container)
        return;

    // Validate interaction
    FEchoesInteractionResult Result = Container->Execute_OnInteract(Container, GetPawn());
    
    if (Result.bSuccess)
    {
        // Open inventory UI on client
        ClientOpenContainerInventory(Container);
    }
}

void APlayerController::ClientOpenContainerInventory_Implementation(AEchoesItemActor* Container)
{
    // Show inventory widget
    UEchoesInventoryWidget* Widget = CreateWidget<UEchoesInventoryWidget>(this, InventoryWidgetClass);
    if (Widget)
    {
        Widget->SetTargetActor(Container);
        Widget->AddToViewport();
    }
}
```

## Configuration

### Project Settings

```ini
[/Script/Echoes.EchoesItemActor]
DefaultInteractionDistance=25000.0
DefaultLifetime=7200.0
EnablePhysicsByDefault=true
MaxRandomVelocity=100.0
```

### Per-Instance Settings

```cpp
// Override defaults per instance
Container->InteractionDistance = 50000.0f; // 500m range
Container->Lifetime = 3600.0f;             // 1 hour
Container->bEnablePhysics = false;         // Anchored
Container->bApplyRandomVelocity = false;   // Static
```

## Requirements Checklist

- [x] Base Structure
  - [x] Inherit from AActor
  - [x] UStaticMeshComponent (visual)
  - [x] USphereComponent (interaction collision)
  - [x] UEchoesInventoryComponent (storage)
- [x] Dynamic Visualization
  - [x] InitializeItem(ItemId, InstanceId) method
  - [x] Async mesh loading via subsystem
  - [x] TSoftObjectPtr support
  - [x] OnMeshLoaded callback
- [x] Interaction Logic
  - [x] IEchoesInteractableInterface implementation
  - [x] Distance validation
  - [x] Loot logic (open inventory)
  - [x] Jettison support with lifetime
- [x] Replication
  - [x] ItemId replication
  - [x] InstanceId replication
  - [x] Quantity replication
  - [x] OnRep_ItemId handler
  - [x] Inventory component sync
  - [x] Distance-based access
- [x] Physics
  - [x] Simulate physics support
  - [x] Space environment (no gravity)
  - [x] Random drift velocity
  - [x] Mass calculation from definition

## Next Steps

1. Test spawning in UE5 editor
2. Create sample containers
3. Test interaction system
4. Test replication in multiplayer
5. Profile performance with many items
6. Implement HISM manager for optimization
7. Add visual effects (glow, outline)
8. Create admin tools for spawning
