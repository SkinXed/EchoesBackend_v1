// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EchoesJumpManager.generated.h"

class APlayerController;
class AEchoesWorldGenerator;

/**
 * Player state during jump
 */
UENUM(BlueprintType)
enum class EJumpState : uint8
{
	None UMETA(DisplayName = "None"),
	Initiating UMETA(DisplayName = "Initiating"),
	Jumping UMETA(DisplayName = "Jumping"),
	Arriving UMETA(DisplayName = "Arriving")
};

/**
 * UEchoesJumpManager
 * 
 * Manages seamless intra-server jumps between star systems in Regional Clusters
 * Handles three-phase jump system: Initiation → Shift → Arrival
 * 
 * Architecture:
 * - Component attached to GameMode
 * - Server authoritative with client RPCs for visual effects
 * - Integrates with backend for location persistence
 * - Handles physics teleportation safely
 * - Manages player state during jump (invulnerable, input blocked)
 * 
 * Three-Phase Jump System:
 * 1. Initiation (ClientOnly): Fade out, warp tunnel effect, block input
 * 2. The Shift (ServerOnly): Instant teleportation with physics handling
 * 3. Arrival (ClientOnly): Asset loading check, fade in, unblock input
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ECHOES_API UEchoesJumpManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	UEchoesJumpManager();

protected:
	virtual void BeginPlay() override;

public:
	// ==================== Configuration ====================

	/**
	 * Transition time for fade effects (seconds)
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Jump|Configuration")
	float TransitionTime = 2.0f;

	/**
	 * Time to wait for asset loading at destination (seconds)
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Jump|Configuration")
	float AssetLoadWaitTime = 1.0f;

	/**
	 * Maximum distance for collision check (cm)
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Jump|Configuration")
	float CollisionCheckRadius = 10000.0f; // 100m

	// ==================== Jump Execution ====================

	/**
	 * Initiate an intra-server jump
	 * Called by Stargate when target system is on this server
	 * 
	 * @param PlayerController - Player requesting the jump
	 * @param TargetLocation - Destination coordinates in world space
	 * @param TargetSystemId - GUID of target system (for backend update)
	 * @return true if jump initiated successfully
	 */
	UFUNCTION(BlueprintCallable, Category = "Jump|Execution", meta = (BlueprintAuthorityOnly))
	bool InitiateIntraServerJump(
		APlayerController* PlayerController,
		const FVector& TargetLocation,
		const FGuid& TargetSystemId);

protected:
	// ==================== Server-Side Jump Logic ====================

	/**
	 * Perform the actual teleportation on server
	 * Uses ETeleportType::TeleportPhysics for safe physics handling
	 */
	void ServerOnly_PerformIntraServerJump(
		APlayerController* PlayerController,
		const FVector& NewLocation);

	/**
	 * Validate target location (collision check, bounds check)
	 */
	bool ValidateTargetLocation(const FVector& TargetLocation) const;

	/**
	 * Update player location in backend database
	 */
	void NotifyBackendLocationChange(
		APlayerController* PlayerController,
		const FGuid& SystemId);

	/**
	 * Apply jump state to player (invulnerable, can't shoot)
	 */
	void ApplyJumpState(APlayerController* PlayerController, EJumpState NewState);

	/**
	 * Remove jump state from player (restore normal state)
	 */
	void RemoveJumpState(APlayerController* PlayerController);

	// ==================== Client-Side Visual Effects ====================

	/**
	 * Start jump sequence on client
	 * Triggers fade out, warp tunnel effect, blocks input
	 */
	UFUNCTION(Client, Reliable)
	void ClientRPC_StartJumpSequence(float TransitionDuration);

	/**
	 * End jump sequence on client
	 * Triggers fade in, unblocks input, removes effects
	 */
	UFUNCTION(Client, Reliable)
	void ClientRPC_EndJumpSequence();

	/**
	 * Update jump progress on client (for HUD/effects)
	 */
	UFUNCTION(Client, Reliable)
	void ClientRPC_UpdateJumpProgress(float Progress);

	// ==================== Network Optimization ====================

	/**
	 * Force replication update for new location
	 * Updates relevant actors list after teleportation
	 */
	void ForceReplicationFlush(APlayerController* PlayerController);

	/**
	 * Preload assets for destination system
	 */
	void PreloadDestinationAssets(const FGuid& SystemId);

	// ==================== Timer Callbacks ====================

	/**
	 * Called after teleportation to handle arrival phase
	 */
	void OnArrivalTimerComplete(APlayerController* PlayerController, FGuid TargetSystemId);

private:
	// ==================== State Tracking ====================

	/** Map of players currently jumping */
	UPROPERTY()
	TMap<APlayerController*, EJumpState> JumpingPlayers;

	/** Timer handles for jump sequences */
	TMap<APlayerController*, FTimerHandle> JumpTimerHandles;

	/** Reference to world generator for asset management */
	UPROPERTY()
	AEchoesWorldGenerator* WorldGenerator;
};
