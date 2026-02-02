// Copyright Epic Games, Inc. All Rights Reserved.

#include "StargateActor.h"
#include "Net/UnrealNetwork.h"
#include "Components/StaticMeshComponent.h"
#include "Components/AudioComponent.h"
#include "Components/BoxComponent.h"
#include "NiagaraComponent.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "EchoesWorldGenerator.h"
#include "EchoesServerGameMode.h"
#include "EchoesJumpManager.h"

AStargateActor::AStargateActor()
{
	PrimaryActorTick.bCanEverTick = true;

	// Enable replication
	bReplicates = true;
	bAlwaysRelevant = false; // Stargates can be culled based on distance

	// Set network cull distance for regional clusters
	// 5 million units = reasonable visibility range for stargates
	SetNetCullDistanceSquared(25000000000000.0); // 5 million units squared

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
	JumpTriggerZone->SetBoxExtent(FVector(5000.0f, 5000.0f, 5000.0f)); // 100m x 100m x 100m (half-extents)
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
	// Apply base scale from visual data
	if (GateMeshComponent)
	{
		GateMeshComponent->SetRelativeScale3D(VisualData.ActorScale);
	}

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
		// Server is already executing, call directly instead of RPC
		InitiateJumpToTarget(PC);
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

	// Get World Generator to check if target system is on this server
	AEchoesWorldGenerator* WorldGenerator = nullptr;
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEchoesWorldGenerator::StaticClass(), FoundActors);
	if (FoundActors.Num() > 0)
	{
		WorldGenerator = Cast<AEchoesWorldGenerator>(FoundActors[0]);
	}

	if (WorldGenerator && WorldGenerator->IsSystemOnThisServer(TargetSystemId))
	{
		// ==================== LOCAL JUMP (Intra-Server) ====================
		UE_LOG(LogTemp, Log, TEXT("✓ Target system is ON THIS SERVER - performing LOCAL jump via JumpManager"));

		// Get the target gate location
		FVector TargetGateLocation = GetTargetGateLocationOnServer(TargetSystemId);
		
		// Get JumpManager from GameMode
		AGameModeBase* GameMode = GetWorld()->GetAuthGameMode();
		AEchoesServerGameMode* EchoesGameMode = Cast<AEchoesServerGameMode>(GameMode);
		
		if (EchoesGameMode && IsValid(EchoesGameMode))
		{
			UEchoesJumpManager* JumpManager = EchoesGameMode->GetJumpManager();
			if (JumpManager && IsValid(JumpManager))
			{
				// Use JumpManager for seamless transition
				bool bJumpInitiated = JumpManager->InitiateIntraServerJump(
					PlayerController,
					TargetGateLocation,
					TargetSystemId
				);

				if (bJumpInitiated)
				{
					UE_LOG(LogTemp, Log, TEXT("✓ Jump initiated via JumpManager"));
				}
				else
				{
					UE_LOG(LogTemp, Error, TEXT("✗ Failed to initiate jump via JumpManager"));
				}
			}
			else
			{
				// Fallback: Direct teleportation (old method)
				UE_LOG(LogTemp, Warning, TEXT("⚠ JumpManager not available, using direct teleportation"));
				
				APawn* PlayerPawn = PlayerController->GetPawn();
				if (PlayerPawn && IsValid(PlayerPawn))
				{
					PlayerPawn->SetActorLocation(TargetGateLocation);
					UE_LOG(LogTemp, Log, TEXT("✓ Player teleported to target gate (fallback method)"));
				}
			}
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("✗ GameMode not available or invalid"));
		}
	}
	else
	{
		// ==================== CROSS-SERVER JUMP (Inter-Server) ====================
		UE_LOG(LogTemp, Log, TEXT("⚠ Target system is NOT on this server - performing CROSS-SERVER jump (client travel)"));

		// TODO: Query backend for target server IP/Port
		// FString TargetServerURL = GetTargetServerURLFromBackend(TargetSystemId);
		
		// Placeholder: For now, just log the jump
		UE_LOG(LogTemp, Warning, TEXT("⚠ Cross-server jump logic not fully implemented"));
		UE_LOG(LogTemp, Warning, TEXT("Would query backend for server hosting system: %s"), *TargetSystemId.ToString());
		UE_LOG(LogTemp, Warning, TEXT("Then call: PlayerController->ClientTravel(TargetServerURL, TRAVEL_Absolute)"));

		// Example of what would happen in production:
		// PlayerController->ClientTravel(TargetServerURL, ETravelType::TRAVEL_Absolute);
	}
}

FVector AStargateActor::GetTargetGateLocationOnServer(const FGuid& InTargetSystemId)
{
	// Get World Generator to look up system offset and find target gate
	AEchoesWorldGenerator* WorldGenerator = nullptr;
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEchoesWorldGenerator::StaticClass(), FoundActors);
	if (FoundActors.Num() > 0)
	{
		WorldGenerator = Cast<AEchoesWorldGenerator>(FoundActors[0]);
	}

	if (!WorldGenerator)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to find WorldGenerator for gate location lookup"));
		return FVector::ZeroVector;
	}

	// Get system offset for target system
	FVector TargetSystemOffset = WorldGenerator->GetSystemGlobalOffset(InTargetSystemId);

	// Find the target stargate in the target system that connects back to our system
	// For now, we'll just return the system offset (star location)
	// TODO: Find the actual stargate actor that leads back to our system
	TArray<AActor*> AllGates;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AStargateActor::StaticClass(), AllGates);

	for (AActor* GateActor : AllGates)
	{
		AStargateActor* Gate = Cast<AStargateActor>(GateActor);
		if (Gate && Gate->GetTargetSystemId() == InTargetSystemId)
		{
			// Found a gate that leads to target system - use its target location
			// In a proper implementation, we'd find the gate IN the target system
			// For now, offset from system center
			return TargetSystemOffset + FVector(10000.0f, 0.0f, 0.0f); // 100m offset from system center
		}
	}

	// Default: Return target system center (star location)
	UE_LOG(LogTemp, Warning, TEXT("Could not find specific target gate, using system center"));
	return TargetSystemOffset;
}
