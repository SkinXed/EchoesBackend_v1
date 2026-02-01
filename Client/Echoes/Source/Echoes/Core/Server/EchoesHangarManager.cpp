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

void AEchoesHangarManager::InitializeHangar(const FString& CharacterId)
{
	CurrentCharacterId = CharacterId;
	
	UE_LOG(LogTemp, Log, TEXT("HangarManager: Initializing for character: %s"), *CharacterId);

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
