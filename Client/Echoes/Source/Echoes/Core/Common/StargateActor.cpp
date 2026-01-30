// Copyright Epic Games, Inc. All Rights Reserved.

#include "StargateActor.h"
#include "Net/UnrealNetwork.h"
#include "Components/StaticMeshComponent.h"
#include "Components/AudioComponent.h"
#include "Components/BoxComponent.h"
#include "NiagaraComponent.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"

AStargateActor::AStargateActor()
{
	PrimaryActorTick.bCanEverTick = true;

	// Enable replication
	bReplicates = true;
	bAlwaysRelevant = true;

	// Create root component
	USceneComponent* RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = RootComp;

	// Create gate mesh component
	GateMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GateMesh"));
	GateMeshComponent->SetupAttachment(RootComponent);
	GateMeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	// Create jump trigger zone (box component for controlled activation area)
	JumpTriggerZone = CreateDefaultSubobject<UBoxComponent>(TEXT("JumpTriggerZone"));
	JumpTriggerZone->SetupAttachment(RootComponent);
	JumpTriggerZone->SetBoxExtent(FVector(5000.0f, 5000.0f, 5000.0f)); // 50m x 50m x 50m
	JumpTriggerZone->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	JumpTriggerZone->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	JumpTriggerZone->SetCollisionResponseToAllChannels(ECR_Ignore);
	JumpTriggerZone->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	JumpTriggerZone->SetGenerateOverlapEvents(true);

	// Create portal VFX component
	PortalVFXComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("PortalVFX"));
	PortalVFXComponent->SetupAttachment(GateMeshComponent);
	PortalVFXComponent->SetAutoActivate(true);

	// Create destination marker VFX
	DestinationFXComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("DestinationFX"));
	DestinationFXComponent->SetupAttachment(GateMeshComponent);
	DestinationFXComponent->SetAutoActivate(true);

	// Create ambient audio component
	AmbientAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("AmbientAudio"));
	AmbientAudioComponent->SetupAttachment(GateMeshComponent);
	AmbientAudioComponent->bAutoActivate = true;

	CurrentRotationAngle = 0.0f;
}

void AStargateActor::BeginPlay()
{
	Super::BeginPlay();

	if (!HasAuthority())
	{
		ApplyVisualConfiguration();
	}
	else
	{
		// Server: Bind jump trigger overlap event
		if (JumpTriggerZone)
		{
			JumpTriggerZone->OnComponentBeginOverlap.AddDynamic(
				this,
				&AStargateActor::OnJumpTriggerBeginOverlap);
			UE_LOG(LogTemp, Log, TEXT("Stargate '%s': Jump trigger zone activated"), *GateName);
		}
	}
}

void AStargateActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Update ring rotation animation
	if (VisualData.RingRotationSpeed > 0.0f)
	{
		UpdateRingRotation(DeltaTime);
	}
}

void AStargateActor::InitializeStargate(
	const FGuid& InGateId,
	const FString& InName,
	const FGuid& InTargetSystemId,
	const FString& InTargetSystemName,
	bool bInIsOperational,
	const FStargateVisualRow& InVisualData)
{
	if (!HasAuthority())
	{
		UE_LOG(LogTemp, Warning, TEXT("InitializeStargate called on client - ignoring"));
		return;
	}

	GateId = InGateId;
	GateName = InName;
	TargetSystemId = InTargetSystemId;
	TargetSystemName = InTargetSystemName;
	bIsOperational = bInIsOperational;
	VisualData = InVisualData;

	UE_LOG(LogTemp, Log, TEXT("Initializing Stargate: %s -> %s (Operational: %s)"),
		*GateName, *TargetSystemName, bIsOperational ? TEXT("Yes") : TEXT("No"));

	ApplyVisualConfiguration();
}

void AStargateActor::ApplyVisualConfiguration()
{
	// Set gate mesh and materials
	// In production: Load async with UStreamableManager

	// Enable/disable portal VFX based on operational status
	if (PortalVFXComponent)
	{
		if (bIsOperational && !VisualData.PortalVFX.IsNull())
		{
			PortalVFXComponent->SetVisibility(true);
		}
		else
		{
			PortalVFXComponent->SetVisibility(false);
		}
	}

	// Set destination marker VFX
	if (DestinationFXComponent)
	{
		if (bIsOperational && !VisualData.DestinationFX.IsNull())
		{
			DestinationFXComponent->SetVisibility(true);
		}
		else
		{
			DestinationFXComponent->SetVisibility(false);
		}
	}

	// Set ambient audio
	if (AmbientAudioComponent && bIsOperational)
	{
		// In production: Load async
		AmbientAudioComponent->SetActive(true);
	}
	else if (AmbientAudioComponent)
	{
		AmbientAudioComponent->SetActive(false);
	}
}

void AStargateActor::UpdateRingRotation(float DeltaTime)
{
	if (!GateMeshComponent)
	{
		return;
	}

	// Update rotation angle
	CurrentRotationAngle += VisualData.RingRotationSpeed * DeltaTime;
	if (CurrentRotationAngle >= 360.0f)
	{
		CurrentRotationAngle -= 360.0f;
	}

	// Apply rotation to gate mesh
	FRotator NewRotation = GateMeshComponent->GetRelativeRotation();
	NewRotation.Roll = CurrentRotationAngle;
	GateMeshComponent->SetRelativeRotation(NewRotation);
}

void AStargateActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AStargateActor, GateId);
	DOREPLIFETIME(AStargateActor, GateName);
	DOREPLIFETIME(AStargateActor, TargetSystemId);
	DOREPLIFETIME(AStargateActor, TargetSystemName);
	DOREPLIFETIME(AStargateActor, bIsOperational);
}

void AStargateActor::OnRep_GateData()
{
	ApplyVisualConfiguration();
}

void AStargateActor::OnJumpTriggerBeginOverlap(
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

	// Check if gate is operational
	if (!bIsOperational)
	{
		UE_LOG(LogTemp, Warning, TEXT("Stargate '%s' is not operational"), *GateName);
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
		return; // Not a player-controlled pawn (might be AI or uncontrolled)
	}

	UE_LOG(LogTemp, Log, TEXT("Player '%s' entered stargate '%s' trigger zone"),
		*PC->GetName(), *GateName);

	// Check if ship is ready to jump
	if (IsShipReadyToJump(Pawn))
	{
		// Initiate jump sequence
		ServerRPC_RequestJump(PC);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Ship not ready to jump through stargate '%s'"), *GateName);
		// TODO: Send message to client about why jump failed
	}
}

bool AStargateActor::ServerRPC_RequestJump_Validate(APlayerController* PlayerController)
{
	// Basic validation
	return PlayerController != nullptr && bIsOperational;
}

void AStargateActor::ServerRPC_RequestJump_Implementation(APlayerController* PlayerController)
{
	if (!HasAuthority())
	{
		return;
	}

	if (!PlayerController)
	{
		UE_LOG(LogTemp, Error, TEXT("ServerRPC_RequestJump: Invalid PlayerController"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Jump request validated for player '%s' through gate '%s'"),
		*PlayerController->GetName(), *GateName);

	// Initiate jump to target system
	InitiateJumpToTarget(PlayerController);
}

bool AStargateActor::IsShipReadyToJump(AActor* Ship) const
{
	if (!Ship)
	{
		return false;
	}

	// TODO: Implement comprehensive readiness checks:
	// 1. Check if ship is in combat (has active attackers)
	// 2. Check if ship has sufficient energy/fuel
	// 3. Check if ship is docked (should be undocked)
	// 4. Check if ship has cooldown active
	// 5. Check if player has permission to use this gate

	// For now, basic check - ship must be a pawn
	APawn* Pawn = Cast<APawn>(Ship);
	if (!Pawn)
	{
		return false;
	}

	// Ship is ready
	return true;
}

void AStargateActor::InitiateJumpToTarget(APlayerController* PlayerController)
{
	if (!HasAuthority())
	{
		return;
	}

	if (!PlayerController)
	{
		UE_LOG(LogTemp, Error, TEXT("InitiateJumpToTarget: Invalid PlayerController"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("╔══════════════════════════════════════════════════════════╗"));
	UE_LOG(LogTemp, Log, TEXT("║    INITIATING JUMP TO TARGET SYSTEM                     ║"));
	UE_LOG(LogTemp, Log, TEXT("╚══════════════════════════════════════════════════════════╝"));
	UE_LOG(LogTemp, Log, TEXT("Player: %s"), *PlayerController->GetName());
	UE_LOG(LogTemp, Log, TEXT("Source Gate: %s"), *GateName);
	UE_LOG(LogTemp, Log, TEXT("Target System: %s (%s)"), *TargetSystemName, *TargetSystemId.ToString());

	// TODO: Implement actual jump logic:
	// 1. Query backend for target system server IP/Port
	// 2. Send player to target server via ClientTravel
	// 3. Apply jump costs (fuel, ISK, etc.)
	// 4. Play jump animation/effects
	// 5. Update player location in backend database

	// Placeholder: For now, just log the jump
	UE_LOG(LogTemp, Warning, TEXT("⚠ Jump logic not fully implemented - would travel to system %s"),
		*TargetSystemId.ToString());

	// Example of what would happen in production:
	// FString TargetServerURL = GetTargetServerURL(TargetSystemId);
	// PlayerController->ClientTravel(TargetServerURL, ETravelType::TRAVEL_Absolute);
}
