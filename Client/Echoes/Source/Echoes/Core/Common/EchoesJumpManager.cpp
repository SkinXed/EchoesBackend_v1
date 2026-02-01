// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesJumpManager.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/Character.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "EchoesWorldGenerator.h"

UEchoesJumpManager::UEchoesJumpManager()
{
	PrimaryComponentTick.bCanEverTick = false;
	bWantsInitializeComponent = true;
}

void UEchoesJumpManager::BeginPlay()
{
	Super::BeginPlay();

	// Get reference to world generator
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEchoesWorldGenerator::StaticClass(), FoundActors);
	if (FoundActors.Num() > 0)
	{
		WorldGenerator = Cast<AEchoesWorldGenerator>(FoundActors[0]);
	}

	UE_LOG(LogTemp, Log, TEXT("EchoesJumpManager initialized"));
}

// ==================== Jump Execution ====================

bool UEchoesJumpManager::InitiateIntraServerJump(
	APlayerController* PlayerController,
	const FVector& TargetLocation,
	const FGuid& TargetSystemId)
{
	if (!GetOwner()->HasAuthority())
	{
		UE_LOG(LogTemp, Error, TEXT("InitiateIntraServerJump called on client!"));
		return false;
	}

	if (!PlayerController)
	{
		UE_LOG(LogTemp, Error, TEXT("InitiateIntraServerJump: Invalid PlayerController"));
		return false;
	}

	// Check if player is already jumping
	if (JumpingPlayers.Contains(PlayerController))
	{
		UE_LOG(LogTemp, Warning, TEXT("Player '%s' is already jumping"), *PlayerController->GetName());
		return false;
	}

	UE_LOG(LogTemp, Log, TEXT("╔══════════════════════════════════════════════════════════╗"));
	UE_LOG(LogTemp, Log, TEXT("║    INITIATING INTRA-SERVER JUMP                         ║"));
	UE_LOG(LogTemp, Log, TEXT("╚══════════════════════════════════════════════════════════╝"));
	UE_LOG(LogTemp, Log, TEXT("Player: %s"), *PlayerController->GetName());
	UE_LOG(LogTemp, Log, TEXT("Target Location: [%.0f, %.0f, %.0f]"), 
		TargetLocation.X, TargetLocation.Y, TargetLocation.Z);
	UE_LOG(LogTemp, Log, TEXT("Target System ID: %s"), *TargetSystemId.ToString());

	// Validate target location
	if (!ValidateTargetLocation(TargetLocation))
	{
		UE_LOG(LogTemp, Error, TEXT("Target location validation failed"));
		return false;
	}

	// ==================== PHASE 1: INITIATION ====================
	UE_LOG(LogTemp, Log, TEXT("PHASE 1: Initiation - Starting client-side effects"));

	// Mark player as jumping
	JumpingPlayers.Add(PlayerController, EJumpState::Initiating);

	// Apply jump state (invulnerable, can't shoot)
	ApplyJumpState(PlayerController, EJumpState::Jumping);

	// Start client-side visual sequence (fade out, warp tunnel)
	ClientRPC_StartJumpSequence(TransitionTime);

	// Wait for transition, then perform teleportation
	FTimerHandle TransitionTimer;
	FTimerDelegate TransitionDelegate;
	
	// Use weak pointer to avoid crashes if this component is destroyed
	TWeakObjectPtr<UEchoesJumpManager> WeakThis(this);
	TWeakObjectPtr<APlayerController> WeakPlayerController(PlayerController);
	
	TransitionDelegate.BindLambda([WeakThis, WeakPlayerController, TargetLocation, TargetSystemId]()
	{
		// Validate all pointers
		if (!WeakThis.IsValid() || !WeakPlayerController.IsValid())
		{
			UE_LOG(LogTemp, Error, TEXT("JumpManager or PlayerController became invalid during jump"));
			return;
		}
		
		APlayerController* PlayerController = WeakPlayerController.Get();
		UEchoesJumpManager* This = WeakThis.Get();

		// ==================== PHASE 2: THE SHIFT ====================
		UE_LOG(LogTemp, Log, TEXT("PHASE 2: The Shift - Performing teleportation"));

		// Perform the actual teleportation
		This->ServerOnly_PerformIntraServerJump(PlayerController, TargetLocation);

		// Force replication flush
		This->ForceReplicationFlush(PlayerController);

		// Notify backend of location change
		This->NotifyBackendLocationChange(PlayerController, TargetSystemId);

		// Update jump state
		if (This->JumpingPlayers.Contains(PlayerController))
		{
			This->JumpingPlayers[PlayerController] = EJumpState::Arriving;
		}

		// ==================== PHASE 3: ARRIVAL ====================
		UE_LOG(LogTemp, Log, TEXT("PHASE 3: Arrival - Waiting for asset loading"));

		// Wait for assets to load, then complete jump
		FTimerHandle ArrivalTimer;
		if (This->GetWorld())
		{
			// Use weak pointer for safe timer callback
			TWeakObjectPtr<UEchoesJumpManager> WeakThisForTimer(This);
			TWeakObjectPtr<APlayerController> WeakPCForTimer(PlayerController);
			
			This->GetWorld()->GetTimerManager().SetTimer(
				ArrivalTimer,
				FTimerDelegate::CreateLambda([WeakThisForTimer, WeakPCForTimer, TargetSystemId]()
				{
					if (WeakThisForTimer.IsValid() && WeakPCForTimer.IsValid())
					{
						WeakThisForTimer->OnArrivalTimerComplete(WeakPCForTimer.Get(), TargetSystemId);
					}
				}),
				This->AssetLoadWaitTime,
				false);

			This->JumpTimerHandles.Add(PlayerController, ArrivalTimer);
		}
	});

	GetWorld()->GetTimerManager().SetTimer(TransitionTimer, TransitionDelegate, TransitionTime * 0.5f, false);
	JumpTimerHandles.Add(PlayerController, TransitionTimer);

	return true;
}

// ==================== Server-Side Jump Logic ====================

void UEchoesJumpManager::ServerOnly_PerformIntraServerJump(
	APlayerController* PlayerController,
	const FVector& NewLocation)
{
	if (!GetOwner()->HasAuthority())
	{
		return;
	}

	if (!PlayerController || !IsValid(PlayerController))
	{
		UE_LOG(LogTemp, Error, TEXT("Invalid PlayerController in ServerOnly_PerformIntraServerJump"));
		return;
	}

	APawn* PlayerPawn = PlayerController->GetPawn();
	if (!PlayerPawn || !IsValid(PlayerPawn))
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to get valid player pawn for teleportation"));
		return;
	}

	// Teleport with physics handling
	// ETeleportType::TeleportPhysics ensures physics state is properly reset
	bool bSuccess = PlayerPawn->SetActorLocationAndRotation(
		NewLocation,
		PlayerPawn->GetActorRotation(),
		false, // No sweep (we already validated)
		nullptr,
		ETeleportType::TeleportPhysics // Critical: Reset physics state
	);

	if (bSuccess)
	{
		UE_LOG(LogTemp, Log, TEXT("✓ Teleportation successful"));
		UE_LOG(LogTemp, Log, TEXT("  New Location: [%.0f, %.0f, %.0f]"), 
			PlayerPawn->GetActorLocation().X,
			PlayerPawn->GetActorLocation().Y,
			PlayerPawn->GetActorLocation().Z);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("✗ Teleportation failed"));
	}
}

bool UEchoesJumpManager::ValidateTargetLocation(const FVector& TargetLocation) const
{
	if (!GetWorld())
	{
		return false;
	}

	// Check if location is within valid world bounds
	// For LWC support, we don't have strict bounds, but check for NaN/Inf
	const bool bIsFinite = FMath::IsFinite(TargetLocation.X) && FMath::IsFinite(TargetLocation.Y) && FMath::IsFinite(TargetLocation.Z);
	if (!TargetLocation.ContainsNaN() && bIsFinite)
	{
		// Perform collision check at target location
		FCollisionShape SphereShape = FCollisionShape::MakeSphere(CollisionCheckRadius);
		
		bool bHasBlockingHit = GetWorld()->OverlapBlockingTestByChannel(
			TargetLocation,
			FQuat::Identity,
			ECC_Pawn,
			SphereShape
		);

		if (bHasBlockingHit)
		{
			UE_LOG(LogTemp, Warning, TEXT("Target location has blocking collision"));
			// Allow jump anyway but log warning
			// In production, might want to offset location or reject jump
		}

		return true;
	}

	UE_LOG(LogTemp, Error, TEXT("Target location is invalid (NaN or Infinite)"));
	return false;
}

void UEchoesJumpManager::NotifyBackendLocationChange(
	APlayerController* PlayerController,
	const FGuid& SystemId)
{
	if (!GetOwner()->HasAuthority())
	{
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Notifying backend of location change"));
	UE_LOG(LogTemp, Log, TEXT("  Player: %s"), *PlayerController->GetName());
	UE_LOG(LogTemp, Log, TEXT("  New System ID: %s"), *SystemId.ToString());

	// TODO: Implement backend API call
	// POST /api/character/update-location
	// Body: { "characterId": "guid", "systemId": "guid", "timestamp": "utc" }

	// For now, just log
	UE_LOG(LogTemp, Warning, TEXT("⚠ Backend notification not yet implemented"));
	UE_LOG(LogTemp, Warning, TEXT("Would call: POST /api/character/update-location"));
}

void UEchoesJumpManager::ApplyJumpState(APlayerController* PlayerController, EJumpState NewState)
{
	if (!GetOwner()->HasAuthority())
	{
		return;
	}

	if (!PlayerController || !IsValid(PlayerController))
	{
		return;
	}

	APawn* PlayerPawn = PlayerController->GetPawn();
	if (!PlayerPawn || !IsValid(PlayerPawn))
	{
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Applying jump state to player: %s"), 
		*UEnum::GetValueAsString(NewState));

	// Make player invulnerable during jump
	// TODO: Implement proper damage immunity system
	// For now, we would set a flag or damage modifier

	// Disable player input during jump
	// TODO: This should be done on client side in ClientRPC_StartJumpSequence
	
	// Disable weapons/abilities
	// TODO: Implement weapon/ability system integration
}

void UEchoesJumpManager::RemoveJumpState(APlayerController* PlayerController)
{
	if (!GetOwner()->HasAuthority())
	{
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Removing jump state from player"));

	// Remove invulnerability
	// Re-enable input (done on client)
	// Re-enable weapons/abilities
	
	// Remove from tracking map
	JumpingPlayers.Remove(PlayerController);
	JumpTimerHandles.Remove(PlayerController);
}

// ==================== Client-Side Visual Effects ====================

void UEchoesJumpManager::ClientRPC_StartJumpSequence_Implementation(float TransitionDuration)
{
	UE_LOG(LogTemp, Log, TEXT("CLIENT: Starting jump sequence (Fade Out)"));
	UE_LOG(LogTemp, Log, TEXT("  Transition Duration: %.2f seconds"), TransitionDuration);

	// Get player controller
	APlayerController* PC = Cast<APlayerController>(GetWorld()->GetFirstPlayerController());
	if (!PC)
	{
		return;
	}

	// Start fade to black
	PC->PlayerCameraManager->StartCameraFade(
		0.0f,      // From Alpha
		1.0f,      // To Alpha
		TransitionDuration * 0.5f, // Duration
		FLinearColor::Black,
		false,     // Should fade audio
		true       // Hold when finished
	);

	// Disable player input
	PC->DisableInput(PC);

	// TODO: Play warp tunnel effect
	// TODO: Play audio effects

	UE_LOG(LogTemp, Log, TEXT("✓ Jump sequence started on client"));
}

void UEchoesJumpManager::ClientRPC_EndJumpSequence_Implementation()
{
	UE_LOG(LogTemp, Log, TEXT("CLIENT: Ending jump sequence (Fade In)"));

	// Get player controller
	APlayerController* PC = Cast<APlayerController>(GetWorld()->GetFirstPlayerController());
	if (!PC)
	{
		return;
	}

	// Fade from black
	PC->PlayerCameraManager->StartCameraFade(
		1.0f,      // From Alpha
		0.0f,      // To Alpha
		TransitionTime * 0.5f, // Duration
		FLinearColor::Black,
		false,     // Should fade audio
		false      // Don't hold
	);

	// Re-enable player input
	PC->EnableInput(PC);

	// TODO: Remove warp tunnel effect
	// TODO: Play arrival audio

	UE_LOG(LogTemp, Log, TEXT("✓ Jump sequence ended on client"));
}

void UEchoesJumpManager::ClientRPC_UpdateJumpProgress_Implementation(float Progress)
{
	// Update HUD or effects based on progress
	// Progress: 0.0 to 1.0
	UE_LOG(LogTemp, Verbose, TEXT("CLIENT: Jump progress: %.0f%%"), Progress * 100.0f);
}

// ==================== Network Optimization ====================

void UEchoesJumpManager::ForceReplicationFlush(APlayerController* PlayerController)
{
	if (!GetOwner()->HasAuthority())
	{
		return;
	}

	if (!PlayerController || !IsValid(PlayerController))
	{
		UE_LOG(LogTemp, Warning, TEXT("Invalid PlayerController in ForceReplicationFlush"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Forcing replication flush for player at new location"));

	// Force update of relevant actors list
	// This ensures the client receives updates for actors in new system
	APawn* PlayerPawn = PlayerController->GetPawn();
	if (PlayerPawn && IsValid(PlayerPawn))
	{
		PlayerPawn->ForceNetUpdate();
	}
}

void UEchoesJumpManager::PreloadDestinationAssets(const FGuid& SystemId)
{
	UE_LOG(LogTemp, Log, TEXT("Preloading assets for destination system: %s"), *SystemId.ToString());

	// TODO: Use FStreamableManager to async load destination system assets
	// This would load planet meshes, station models, etc. before completing the jump
	
	// Example:
	// if (WorldGenerator)
	// {
	//     WorldGenerator->AsyncLoadSystemAssets(SystemId);
	// }
	
	UE_LOG(LogTemp, Warning, TEXT("⚠ Asset preloading not yet implemented"));
}

// ==================== Timer Callbacks ====================

void UEchoesJumpManager::OnArrivalTimerComplete(APlayerController* PlayerController, FGuid TargetSystemId)
{
	if (!GetOwner()->HasAuthority())
	{
		return;
	}

	if (!PlayerController || !IsValid(PlayerController))
	{
		UE_LOG(LogTemp, Error, TEXT("PlayerController invalid at arrival"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("╔══════════════════════════════════════════════════════════╗"));
	UE_LOG(LogTemp, Log, TEXT("║    JUMP COMPLETE - ARRIVAL PHASE                        ║"));
	UE_LOG(LogTemp, Log, TEXT("╚══════════════════════════════════════════════════════════╝"));

	// End client-side visual sequence
	ClientRPC_EndJumpSequence();

	// Remove jump state from player
	RemoveJumpState(PlayerController);

	UE_LOG(LogTemp, Log, TEXT("✓ INTRA-SERVER JUMP COMPLETE"));
	UE_LOG(LogTemp, Log, TEXT("  Player: %s"), *PlayerController->GetName());
	UE_LOG(LogTemp, Log, TEXT("  Target System: %s"), *TargetSystemId.ToString());
}
