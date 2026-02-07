// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesStargate.h"
#include "Core/Common/Networking/EchoesJumpSubsystem.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

AEchoesStargate::AEchoesStargate()
{
	PrimaryActorTick.bCanEverTick = true;

	// Create root component
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	// Create stargate mesh
	StargateMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StargateMesh"));
	StargateMesh->SetupAttachment(RootComponent);
	StargateMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// Create trigger volume
	TriggerVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerVolume"));
	TriggerVolume->SetupAttachment(RootComponent);
	TriggerVolume->SetBoxExtent(FVector(500.0f, 500.0f, 500.0f)); // 10m cube
	TriggerVolume->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	TriggerVolume->SetCollisionResponseToAllChannels(ECR_Ignore);
	TriggerVolume->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	TriggerVolume->SetCollisionResponseToChannel(ECC_Vehicle, ECR_Overlap);

	// Default values
	bIsOperational = true;
	JumpCooldownSeconds = 10.0f;
	bRequireConfirmation = false;
	MinJumpDistance = 100.0f;  // 1 meter
	MaxJumpDistance = 5000.0f; // 50 meters
	StargateName = TEXT("Stargate");

	// Enable replication
	bReplicates = true;
	SetReplicateMovement(false); // Stargates don't move
}

void AEchoesStargate::BeginPlay()
{
	Super::BeginPlay();

	// Only set up triggers on server
	if (HasAuthority())
	{
		// Bind overlap events
		TriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &AEchoesStargate::OnTriggerBeginOverlap);
		TriggerVolume->OnComponentEndOverlap.AddDynamic(this, &AEchoesStargate::OnTriggerEndOverlap);

		UE_LOG(LogTemp, Log, TEXT("Stargate '%s' initialized - Destination: %s, Operational: %s"),
			*StargateName, *DestinationSystemId.ToString(), bIsOperational ? TEXT("Yes") : TEXT("No"));
	}

	// Play idle effect
	PlayIdleEffect();
}

void AEchoesStargate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEchoesStargate::OnTriggerBeginOverlap(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	// Only process on server
	if (!HasAuthority())
	{
		return;
	}

	// Ignore self
	if (OtherActor == this || !OtherActor)
	{
		return;
	}

	// Check if stargate is operational
	if (!bIsOperational)
	{
		UE_LOG(LogTemp, Warning, TEXT("Stargate '%s' is not operational"), *StargateName);
		OnJumpFailed(OtherActor, TEXT("Stargate offline"));
		return;
	}

	// Check if actor is valid for jumping
	// This would typically check for player ships/pawns
	// For now, we just check if it has a controller (is player-controlled)
	APawn* Pawn = Cast<APawn>(OtherActor);
	if (!Pawn || !Pawn->GetController())
	{
		// Not a player-controlled entity
		return;
	}

	// Check if ship can jump (cooldown, etc.)
	if (!CanShipJump(OtherActor))
	{
		UE_LOG(LogTemp, Warning, TEXT("Ship cannot jump - cooldown or distance check failed"));
		OnJumpFailed(OtherActor, TEXT("Cooldown active or invalid position"));
		return;
	}

	// Get character ID
	FGuid CharacterId = GetCharacterIdFromShip(OtherActor);
	if (!CharacterId.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to get character ID from ship"));
		OnJumpFailed(OtherActor, TEXT("Invalid character"));
		return;
	}

	// If confirmation is required, we would show UI here
	// For now, we auto-jump
	if (bRequireConfirmation)
	{
		// TODO: Send RPC to client to show jump confirmation UI
		// For now, we just jump immediately
		UE_LOG(LogTemp, Log, TEXT("Jump confirmation required - auto-confirming for now"));
	}

	// Initiate jump
	ServerOnly_InitiateJump(OtherActor, CharacterId);
}

void AEchoesStargate::OnTriggerEndOverlap(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	// Could be used for cleanup or canceling pending jumps
}

void AEchoesStargate::ServerOnly_InitiateJump(AActor* Ship, FGuid CharacterId)
{
	// This should only be called on server
	if (!HasAuthority())
	{
		UE_LOG(LogTemp, Error, TEXT("ServerOnly_InitiateJump called on client!"));
		return;
	}

	if (!Ship || !CharacterId.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Invalid parameters for ServerOnly_InitiateJump"));
		return;
	}

	// Get jump subsystem
	UEchoesJumpSubsystem* JumpSys = GetJumpSubsystem();
	if (!JumpSys)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to get jump subsystem"));
		OnJumpFailed(Ship, TEXT("System error"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Initiating jump for character %s through stargate '%s'"),
		*CharacterId.ToString(), *StargateName);

	// Play jump effect
	PlayJumpEffect(Ship);

	// Record jump time for cooldown
	LastJumpTimes.Add(Ship, GetWorld()->GetTimeSeconds());

	// Get pawn for state collection
	APawn* Pawn = Cast<APawn>(Ship);

	// Request jump from subsystem
	JumpSys->ServerOnly_RequestJump(
		CharacterId,
		StargateId,
		SourceSystemId,
		DestinationSystemId,
		Pawn);

	// Broadcast jump initiated event
	OnJumpInitiated(Ship, TEXT("Unknown System")); // System name would come from database
}

bool AEchoesStargate::CanShipJump(AActor* Ship) const
{
	if (!Ship)
	{
		return false;
	}

	// Check cooldown
	const float* LastJumpTime = LastJumpTimes.Find(Ship);
	if (LastJumpTime)
	{
		const float TimeSinceLastJump = GetWorld()->GetTimeSeconds() - *LastJumpTime;
		if (TimeSinceLastJump < JumpCooldownSeconds)
		{
			return false;
		}
	}

	// Check distance from stargate center
	const float Distance = FVector::Distance(GetActorLocation(), Ship->GetActorLocation());
	if (Distance < MinJumpDistance || Distance > MaxJumpDistance)
	{
		return false;
	}

	// TODO: Add checks for:
	// - Ship in combat
	// - Ship has aggression timer
	// - Ship has sufficient fuel/energy
	// - Destination system is accessible

	return true;
}

FGuid AEchoesStargate::GetCharacterIdFromShip_Implementation(AActor* Ship) const
{
	// This is a placeholder implementation
	// In production, you would:
	// 1. Get the pawn's controller
	// 2. Get the player state or character component
	// 3. Extract the character ID
	
	// For now, return invalid GUID - needs game-specific implementation
	UE_LOG(LogTemp, Warning, TEXT("GetCharacterIdFromShip_Implementation needs game-specific implementation"));
	
	// Example implementation (needs to be adapted):
	/*
	APawn* Pawn = Cast<APawn>(Ship);
	if (Pawn)
	{
		APlayerController* PC = Cast<APlayerController>(Pawn->GetController());
		if (PC && PC->PlayerState)
		{
			// Get character ID from player state
			// AEchoesPlayerState* PS = Cast<AEchoesPlayerState>(PC->PlayerState);
			// if (PS)
			// {
			//     return PS->GetCharacterId();
			// }
		}
	}
	*/

	return FGuid();
}

void AEchoesStargate::PlayJumpEffect_Implementation(AActor* Ship)
{
	// Placeholder for visual effects
	// Override in Blueprint for actual effects like:
	// - Particle systems
	// - Sound effects
	// - Camera shake
	// - Flash/warp animation

	UE_LOG(LogTemp, Log, TEXT("Playing jump effect for ship at stargate '%s'"), *StargateName);
}

void AEchoesStargate::PlayIdleEffect_Implementation()
{
	// Placeholder for idle visual effects
	// Override in Blueprint for actual effects like:
	// - Rotating gate
	// - Particle effects
	// - Ambient sounds
	// - Pulsing lights

	// Only play on clients or in standalone
	if (GetWorld()->GetNetMode() != NM_DedicatedServer)
	{
		UE_LOG(LogTemp, Verbose, TEXT("Playing idle effect for stargate '%s'"), *StargateName);
	}
}

UEchoesJumpSubsystem* AEchoesStargate::GetJumpSubsystem()
{
	if (!JumpSubsystem)
	{
		UGameInstance* GameInstance = GetWorld()->GetGameInstance();
		if (GameInstance)
		{
			JumpSubsystem = GameInstance->GetSubsystem<UEchoesJumpSubsystem>();
		}
	}
	return JumpSubsystem;
}
