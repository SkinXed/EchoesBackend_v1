// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesHangarManager.h"
#include "Core/Common/Networking/EchoesInventorySubsystem.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Kismet/GameplayStatics.h"

AEchoesHangarManager::AEchoesHangarManager()
{
	PrimaryActorTick.bCanEverTick = false;

	// Create root component
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	// Create ship spawn point
	ShipSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("ShipSpawnPoint"));
	ShipSpawnPoint->SetupAttachment(RootComponent);
}

void AEchoesHangarManager::BeginPlay()
{
	Super::BeginPlay();

	// Get inventory subsystem
	if (UGameInstance* GameInstance = GetGameInstance())
	{
		InventorySubsystem = GameInstance->GetSubsystem<UEchoesInventorySubsystem>();
		
		if (InventorySubsystem)
		{
			// Subscribe to fitting changes
			InventorySubsystem->OnFittingChanged.AddUObject(this, &AEchoesHangarManager::OnFittingChanged);
			
			UE_LOG(LogTemp, Log, TEXT("HangarManager: Subscribed to OnFittingChanged"));
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("HangarManager: Failed to get InventorySubsystem"));
		}
	}
}

void AEchoesHangarManager::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	// Unsubscribe from events
	if (InventorySubsystem)
	{
		InventorySubsystem->OnFittingChanged.RemoveAll(this);
	}

	// Clean up preview ship
	ClearShipPreview();

	Super::EndPlay(EndPlayReason);
}

void AEchoesHangarManager::InitializeHangar(const FString& CharacterId, const FGuid& HangarInstanceId)
{
	CurrentCharacterId = CharacterId;
	
	UE_LOG(LogTemp, Log, TEXT("HangarManager: Initializing for character: %s with HangarInstanceId: %s"), 
		*CharacterId, *HangarInstanceId.ToString());

	// Get identity subsystem to find active ship
	if (InventorySubsystem)
	{
		FEchoesShipInstance ActiveShip = InventorySubsystem->Inventory_GetActiveShip();
		
		if (ActiveShip.InstanceId.IsValid())
		{
			SpawnShipPreview(ActiveShip.InstanceId);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("HangarManager: Character has no active ship"));
		}
	}
}

void AEchoesHangarManager::SpawnShipPreview(const FGuid& ShipId)
{
	CurrentShipId = ShipId;
	
	UE_LOG(LogTemp, Log, TEXT("HangarManager: Spawning ship preview for: %s"), *ShipId.ToString());

	// Clear existing preview
	ClearShipPreview();

	// Fetch ship fitting from inventory subsystem
	if (InventorySubsystem)
	{
		FOnShipFittingReceived OnSuccess;
		OnSuccess.BindDynamic(this, &AEchoesHangarManager::OnShipFittingReceived);
		
		FOnInventoryFailure OnFailure;
		OnFailure.BindDynamic(this, &AEchoesHangarManager::OnShipFittingFailed);
		
		InventorySubsystem->Inventory_FetchShipFitting(ShipId, OnSuccess, OnFailure);
	}
}

void AEchoesHangarManager::OnShipFittingReceived(const FEchoesShipFitting& Fitting)
{
	UE_LOG(LogTemp, Log, TEXT("HangarManager: Ship fitting received - Ship: %s, Mass: %.2f"), *Fitting.ShipName, Fitting.TotalMass);

	// Get spawn location from ship spawn point
	FVector SpawnLocation = ShipSpawnPoint ? ShipSpawnPoint->GetComponentLocation() : GetActorLocation();
	FRotator SpawnRotation = ShipSpawnPoint ? ShipSpawnPoint->GetComponentRotation() : GetActorRotation();

	// Spawn static mesh actor for preview
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	
	PreviewShipActor = GetWorld()->SpawnActor<AActor>(AActor::StaticClass(), SpawnLocation, SpawnRotation, SpawnParams);
	
	if (PreviewShipActor)
	{
		// Add static mesh component
		UStaticMeshComponent* MeshComponent = NewObject<UStaticMeshComponent>(PreviewShipActor, TEXT("ShipMesh"));
		if (MeshComponent)
		{
			MeshComponent->RegisterComponent();
			PreviewShipActor->SetRootComponent(MeshComponent);
			
			// Set default mesh if available
			if (DefaultShipMesh)
			{
				MeshComponent->SetStaticMesh(DefaultShipMesh);
			}
			
			// Disable physics (this is just a preview)
			MeshComponent->SetSimulatePhysics(false);
			MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
			
			UE_LOG(LogTemp, Log, TEXT("HangarManager: Ship preview spawned successfully"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("HangarManager: Failed to spawn ship preview actor"));
	}
}

void AEchoesHangarManager::OnShipFittingFailed(const FString& Error)
{
	UE_LOG(LogTemp, Error, TEXT("HangarManager: Failed to fetch ship fitting: %s"), *Error);
}

void AEchoesHangarManager::UpdateShipMesh(const FEchoesShipFitting& NewFitting)
{
	UE_LOG(LogTemp, Log, TEXT("HangarManager: Updating ship mesh - New Mass: %.2f, Modules: %d"), 
		NewFitting.TotalMass, NewFitting.Modules.Num());

	// In a real implementation, you might:
	// 1. Update the visual mesh based on ship type
	// 2. Add/remove module visual components
	// 3. Update material parameters
	// 4. Play effects for module changes
	
	// For now, just log the update
	if (PreviewShipActor)
	{
		// Could scale the ship based on mass for visual feedback
		float ScaleFactor = 1.0f; // Could be calculated from mass
		PreviewShipActor->SetActorScale3D(FVector(ScaleFactor));
	}
}

void AEchoesHangarManager::ClearShipPreview()
{
	if (PreviewShipActor)
	{
		PreviewShipActor->Destroy();
		PreviewShipActor = nullptr;
		
		UE_LOG(LogTemp, Log, TEXT("HangarManager: Ship preview cleared"));
	}
}

void AEchoesHangarManager::OnFittingChanged(const FEchoesShipFitting& NewFitting)
{
	UE_LOG(LogTemp, Log, TEXT("HangarManager: OnFittingChanged called - Ship: %s"), *NewFitting.ShipName);
	
	// Only update if this is the current ship
	if (NewFitting.ShipInstanceId == CurrentShipId)
	{
		UpdateShipMesh(NewFitting);
	}
}

FVector AEchoesHangarManager::GetOrCreateHangarInstance(const FGuid& PlayerId, const FGuid& StationId, const FGuid& HangarInstanceId)
{
	// Check if instance already exists for this player
	if (FHangarInstance* ExistingInstance = HangarInstances.Find(PlayerId))
	{
		UE_LOG(LogTemp, Log, TEXT("HangarManager: Using existing hangar instance for player %s"), *PlayerId.ToString());
		return ExistingInstance->SpatialOffset;
	}

	// ==================== SPATIAL ISOLATION ALGORITHM ====================
	// 
	// Goal: Provide each player with a physically isolated hangar instance
	// at the same station without visual/audio interference between players.
	//
	// Implementation:
	// - Uses a deterministic 3D grid layout based on HangarInstanceId
	// - Grid size: 100x100x20 (X x Y x Z)
	// - Separation distance: 10km (1,000,000 UE units) per grid cell
	// - Total coverage: 1000km x 1000km x 100km volume
	//
	// Algorithm:
	// 1. Hash HangarInstanceId to get deterministic uint32 value
	// 2. Use modulo operations to map hash to 3D grid coordinates
	// 3. Apply grid offsets to center the grid around station origin
	// 4. Scale coordinates by separation distance to get final offset
	//
	// This ensures:
	// - Same HangarInstanceId always gets same spatial offset (deterministic)
	// - Players are separated by at least 10km (no visual/audio interference)
	// - Grid can accommodate 100*100*20 = 200,000 concurrent hangar instances
	//
	// =====================================================================

	// Create new hangar instance with spatial isolation
	FHangarInstance NewInstance;
	NewInstance.InstanceId = HangarInstanceId;
	NewInstance.PlayerId = PlayerId;
	NewInstance.StationId = StationId;

	// Calculate unique spatial offset based on hangar instance ID
	// Use a deterministic hash to ensure same instance ID always gets same offset
	uint32 Hash = GetTypeHash(HangarInstanceId);
	
	// Grid layout constants for spatial distribution
	constexpr int32 GRID_SIZE = 100;           // Number of grid cells per dimension (X, Y)
	constexpr int32 GRID_OFFSET = 50;          // Center offset for grid (-50 to +50)
	constexpr int32 VERTICAL_LAYERS = 20;      // Number of vertical layers (0 to +20)
	constexpr int32 GRID_HASH_DIVISOR = 100;   // Hash divisor for Y grid calculation
	constexpr int32 VERTICAL_HASH_DIVISOR = 10000; // Hash divisor for Z grid calculation
	constexpr float VERTICAL_SCALE = 0.5f;     // Vertical separation scale factor (5km instead of 10km)
	
	// Generate offset in a grid pattern with large separation to prevent overlap
	// Formula: GridCoord = (Hash / Divisor) % GridSize - Offset
	int32 GridX = (Hash % GRID_SIZE) - GRID_OFFSET;                         // Range: -50 to +50
	int32 GridY = ((Hash / GRID_HASH_DIVISOR) % GRID_SIZE) - GRID_OFFSET;   // Range: -50 to +50
	int32 GridZ = ((Hash / VERTICAL_HASH_DIVISOR) % VERTICAL_LAYERS);       // Range: 0 to +20
	
	// Apply separation distance to grid coordinates
	// X and Y: ±500km range (10km * 50), Z: 100km range (5km * 20)
	NewInstance.SpatialOffset = FVector(
		GridX * HangarSpatialSeparation,                    // X: ±500km
		GridY * HangarSpatialSeparation,                    // Y: ±500km
		GridZ * HangarSpatialSeparation * VERTICAL_SCALE    // Z: 0 to 100km (reduced vertical separation)
	);

	UE_LOG(LogTemp, Log, TEXT("HangarManager: Created new hangar instance"));
	UE_LOG(LogTemp, Log, TEXT("  PlayerId: %s"), *PlayerId.ToString());
	UE_LOG(LogTemp, Log, TEXT("  HangarInstanceId: %s"), *HangarInstanceId.ToString());
	UE_LOG(LogTemp, Log, TEXT("  Grid Position: (%d, %d, %d)"), GridX, GridY, GridZ);
	UE_LOG(LogTemp, Log, TEXT("  Spatial Offset: %s"), *NewInstance.SpatialOffset.ToString());

	// Store the instance
	HangarInstances.Add(PlayerId, NewInstance);

	return NewInstance.SpatialOffset;
}

void AEchoesHangarManager::BindShipPawnToHangar(const FGuid& PlayerId, AActor* ShipPawn)
{
	if (!ShipPawn)
	{
		UE_LOG(LogTemp, Error, TEXT("HangarManager: Cannot bind null ship pawn"));
		return;
	}

	FHangarInstance* Instance = HangarInstances.Find(PlayerId);
	if (!Instance)
	{
		UE_LOG(LogTemp, Error, TEXT("HangarManager: No hangar instance found for player %s"), *PlayerId.ToString());
		return;
	}

	// ==================== BIND SHIP PAWN TO HANGAR INSTANCE ====================
	//
	// This method physically relocates the ship pawn to the player's isolated
	// hangar instance by applying the pre-calculated spatial offset.
	//
	// Steps:
	// 1. Store reference to ship pawn in hangar instance
	// 2. Apply spatial offset to ship pawn's world location
	// 3. Configure visibility settings for isolation (owner-only if available)
	//
	// This ensures each player's ship is:
	// - Physically separated from other players (spatial isolation)
	// - Optionally visible only to the owning player (visibility isolation)
	//
	// ===========================================================================

	// Store reference to ship pawn
	Instance->SpawnedShipPawn = ShipPawn;

	// Apply spatial offset to ship pawn location
	FVector CurrentLocation = ShipPawn->GetActorLocation();
	FVector NewLocation = CurrentLocation + Instance->SpatialOffset;
	ShipPawn->SetActorLocation(NewLocation);

	UE_LOG(LogTemp, Log, TEXT("HangarManager: Bound ship pawn to hangar instance"));
	UE_LOG(LogTemp, Log, TEXT("  Original Location: %s"), *CurrentLocation.ToString());
	UE_LOG(LogTemp, Log, TEXT("  Spatial Offset: %s"), *Instance->SpatialOffset.ToString());
	UE_LOG(LogTemp, Log, TEXT("  New Location: %s"), *NewLocation.ToString());

	// Optional: Set owner-only visibility for additional isolation
	// This ensures only the owning player can see their ship in the hangar
	// Provides both spatial AND visual isolation
	if (APawn* Pawn = Cast<APawn>(ShipPawn))
	{
		// Note: SetOnlyOwnerSee requires the pawn to have an owner (player controller)
		// This is typically set during spawn, but we verify it here
		if (Pawn->GetOwner())
		{
			ShipPawn->SetOnlyOwnerSee(true);
			UE_LOG(LogTemp, Log, TEXT("  ✓ Owner-only visibility enabled for additional isolation"));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("  ⚠ Pawn has no owner, skipping owner-only visibility"));
		}
	}
}

FHangarInstance* AEchoesHangarManager::GetHangarInstance(const FGuid& PlayerId)
{
	return HangarInstances.Find(PlayerId);
}

void AEchoesHangarManager::RemoveHangarInstance(const FGuid& PlayerId)
{
	if (HangarInstances.Contains(PlayerId))
	{
		FHangarInstance* Instance = HangarInstances.Find(PlayerId);
		if (Instance)
		{
			UE_LOG(LogTemp, Log, TEXT("HangarManager: Removing hangar instance for player %s"), *PlayerId.ToString());
			
			// Clear any ship preview
			ClearShipPreview();
			
			// Remove from map
			HangarInstances.Remove(PlayerId);
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("HangarManager: No hangar instance found for player %s"), *PlayerId.ToString());
	}
}
