// Copyright Epic Games, Inc. All Rights Reserved.

#include "StationActor.h"
#include "Net/UnrealNetwork.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "NiagaraComponent.h"
#include "GameFramework/PlayerController.h"
#include "Core/Common/EchoesGameStateSubsystem.h"
#include "Kismet/GameplayStatics.h"

AStationActor::AStationActor()
{
	PrimaryActorTick.bCanEverTick = false;

	// Enable replication
	bReplicates = true;
	bAlwaysRelevant = true;

	// Create root component
	USceneComponent* RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = RootComp;

	// Create base mesh component
	BaseMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	BaseMeshComponent->SetupAttachment(RootComponent);
	BaseMeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	// Create docking zone (sphere component for docking detection)
	DockingZone = CreateDefaultSubobject<USphereComponent>(TEXT("DockingZone"));
	DockingZone->SetupAttachment(RootComponent);
	DockingZone->SetSphereRadius(10000.0f); // 100m docking radius
	DockingZone->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	DockingZone->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	DockingZone->SetCollisionResponseToAllChannels(ECR_Ignore);
	DockingZone->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	DockingZone->SetGenerateOverlapEvents(true);

	// Create navigation lights component
	LightsComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("NavigationLights"));
	LightsComponent->SetupAttachment(BaseMeshComponent);
	LightsComponent->SetAutoActivate(true);
}

void AStationActor::BeginPlay()
{
	Super::BeginPlay();

	if (!HasAuthority())
	{
		ApplyVisualConfiguration();
	}
	else
	{
		// Server: Bind docking zone overlap event
		if (DockingZone)
		{
			DockingZone->OnComponentBeginOverlap.AddDynamic(
				this,
				&AStationActor::OnDockingZoneBeginOverlap);
			UE_LOG(LogTemp, Log, TEXT("Station '%s': Docking zone activated"), *StationName);
		}
	}
}

void AStationActor::InitializeStation(
	const FGuid& InStationId,
	const FString& InName,
	const FString& InStationType,
	int32 InSeed,
	const FStationVisualRow& InVisualData)
{
	if (!HasAuthority())
	{
		UE_LOG(LogTemp, Warning, TEXT("InitializeStation called on client - ignoring"));
		return;
	}

	StationId = InStationId;
	StationName = InName;
	StationType = InStationType;
	Seed = InSeed;
	VisualData = InVisualData;

	UE_LOG(LogTemp, Log, TEXT("Initializing Station: %s (Type: %s, Seed: %d)"),
		*StationName, *StationType, Seed);

	ApplyVisualConfiguration();
	ApplySeedVariation();
}

void AStationActor::ApplyVisualConfiguration()
{
	// Set base mesh and materials
	// In production: Load async with UStreamableManager
	
	// Set navigation lights
	if (LightsComponent && !VisualData.LightsPattern.IsNull())
	{
		LightsComponent->SetVisibility(true);
	}
	else if (LightsComponent)
	{
		LightsComponent->SetVisibility(false);
	}
}

void AStationActor::ApplySeedVariation()
{
	if (!HasAuthority())
	{
		return;
	}

	FRandomStream RandomStream(Seed);

	// Apply scale variation
	float ScaleVariation = RandomStream.FRandRange(VisualData.ScaleRange.X, VisualData.ScaleRange.Y);
	BaseMeshComponent->SetRelativeScale3D(FVector(ScaleVariation));

	// Random rotation
	FRotator RandomRotation(0.0f, RandomStream.FRandRange(0.0f, 360.0f), 0.0f);
	BaseMeshComponent->SetRelativeRotation(RandomRotation);

	UE_LOG(LogTemp, Verbose, TEXT("Applied seed variation to station %s: Rotation=%.1f, Scale=%.2f"),
		*StationName, RandomRotation.Yaw, ScaleVariation);
}

void AStationActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AStationActor, StationId);
	DOREPLIFETIME(AStationActor, StationName);
	DOREPLIFETIME(AStationActor, StationType);
	DOREPLIFETIME(AStationActor, Seed);
}

void AStationActor::OnRep_StationData()
{
	ApplyVisualConfiguration();
}

void AStationActor::OnDockingZoneBeginOverlap(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	// Server-only logic
	if (!HasAuthority())
	{
		return;
	}

	// Check if overlapping actor is a player pawn
	APawn* Pawn = Cast<APawn>(OtherActor);
	if (!Pawn)
	{
		return; // Not a pawn
	}

	// Get player controller
	APlayerController* PC = Cast<APlayerController>(Pawn->GetController());
	if (!PC)
	{
		return; // Not a player-controlled pawn
	}

	UE_LOG(LogTemp, Log, TEXT("Player '%s' entered station '%s' docking zone"),
		*PC->GetName(), *StationName);

	// Check access rights and initiate docking
	if (HasDockingAccess(PC))
	{
		// Server is already executing, call directly instead of RPC
		InitiateDocking(PC);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player '%s' denied docking access to station '%s'"),
			*PC->GetName(), *StationName);
		// TODO: Send message to client about denied access
	}
}

bool AStationActor::ServerRPC_RequestDocking_Validate(APlayerController* PlayerController)
{
	// Basic validation
	return PlayerController != nullptr;
}

void AStationActor::ServerRPC_RequestDocking_Implementation(APlayerController* PlayerController)
{
	if (!HasAuthority())
	{
		return;
	}

	if (!PlayerController)
	{
		UE_LOG(LogTemp, Error, TEXT("ServerRPC_RequestDocking: Invalid PlayerController"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Docking request validated for player '%s' at station '%s'"),
		*PlayerController->GetName(), *StationName);

	// Initiate docking sequence
	InitiateDocking(PlayerController);
}

bool AStationActor::HasDockingAccess(APlayerController* PlayerController) const
{
	if (!PlayerController)
	{
		return false;
	}

	// TODO: Implement comprehensive access checks:
	// 1. Check player faction standings
	// 2. Check if station allows public docking
	// 3. Check if player is in corporation that owns station
	// 4. Check if player has special docking rights
	// 5. Check if player is not marked as hostile

	// For now, allow all docking
	return true;
}

void AStationActor::InitiateDocking(APlayerController* PlayerController)
{
	if (!HasAuthority())
	{
		return;
	}

	if (!PlayerController)
	{
		UE_LOG(LogTemp, Error, TEXT("InitiateDocking: Invalid PlayerController"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("╔══════════════════════════════════════════════════════════╗"));
	UE_LOG(LogTemp, Log, TEXT("║    INITIATING DOCKING SEQUENCE                          ║"));
	UE_LOG(LogTemp, Log, TEXT("╚══════════════════════════════════════════════════════════╝"));
	UE_LOG(LogTemp, Log, TEXT("Player: %s"), *PlayerController->GetName());
	UE_LOG(LogTemp, Log, TEXT("Station: %s (Type: %s)"), *StationName, *StationType);

	// Get game state subsystem
	UGameInstance* GameInstance = GetWorld()->GetGameInstance();
	if (GameInstance)
	{
		UEchoesGameStateSubsystem* GameStateSubsystem = GameInstance->GetSubsystem<UEchoesGameStateSubsystem>();
		if (GameStateSubsystem)
		{
			// TODO: Get character ID from player state/controller
			// For now, skip state transition if character ID not available
			FString CharacterId = TEXT(""); // Placeholder
			if (!CharacterId.IsEmpty())
			{
				GameStateSubsystem->TransitionToHangar(CharacterId);
				UE_LOG(LogTemp, Log, TEXT("✓ Player state transitioned to Hangar"));
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("⚠ Character ID not available, skipping state transition"));
			}
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("✗ Failed to get GameStateSubsystem"));
		}
	}

	// Notify backend about docking
	NotifyBackendDocking(PlayerController);

	// TODO: Implement docking sequence:
	// 1. Play docking animation
	// 2. Disable ship controls
	// 3. Transition to hangar level/UI
	// 4. Save ship position for undocking

	UE_LOG(LogTemp, Warning, TEXT("⚠ Docking sequence not fully implemented"));
}

void AStationActor::NotifyBackendDocking(APlayerController* PlayerController)
{
	if (!HasAuthority())
	{
		return;
	}

	if (!PlayerController)
	{
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Notifying backend: Player '%s' docked at station '%s' (%s)"),
		*PlayerController->GetName(), *StationName, *StationId.ToString());

	// TODO: Implement backend notification:
	// 1. Send HTTP request to backend API
	// 2. Update character location in database
	// 3. Set character status to "Docked"
	// 4. Store station ID in character location data

	// Example endpoint: POST /api/character/{characterId}/location
	// Body: { "locationType": "Docked", "stationId": "guid", "timestamp": "utc" }

	UE_LOG(LogTemp, Warning, TEXT("⚠ Backend notification not implemented"));
}
