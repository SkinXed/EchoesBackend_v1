// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TargetingComponent.generated.h"

/**
 * Target lock state enumeration
 * Represents the current state of a target lock
 */
UENUM(BlueprintType)
enum class ETargetLockState : uint8
{
	/** No lock in progress */
	None UMETA(DisplayName = "None"),
	
	/** Lock acquisition in progress */
	Locking UMETA(DisplayName = "Locking"),
	
	/** Lock acquired and maintained */
	Locked UMETA(DisplayName = "Locked"),
	
	/** Lock lost (target out of range or destroyed) */
	Lost UMETA(DisplayName = "Lost")
};

/**
 * Target lock entry structure
 * Stores information about a single target lock
 */
USTRUCT(BlueprintType)
struct FTargetLockEntry
{
	GENERATED_BODY()

	/** Target actor being locked */
	UPROPERTY(BlueprintReadOnly, Category = "Targeting")
	AActor* TargetActor;

	/** Lock acquisition progress (0.0 to 1.0) */
	UPROPERTY(BlueprintReadOnly, Category = "Targeting")
	float Progress;

	/** Current state of the lock */
	UPROPERTY(BlueprintReadOnly, Category = "Targeting")
	ETargetLockState State;

	/** Time when lock started */
	UPROPERTY(BlueprintReadOnly, Category = "Targeting")
	float LockStartTime;

	/** Required time to complete lock */
	UPROPERTY(BlueprintReadOnly, Category = "Targeting")
	float RequiredLockTime;

	/** Constructor */
	FTargetLockEntry()
		: TargetActor(nullptr)
		, Progress(0.0f)
		, State(ETargetLockState::None)
		, LockStartTime(0.0f)
		, RequiredLockTime(0.0f)
	{
	}
};

// Delegates for Blueprint events
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLockStarted, AActor*, Target);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLockCompleted, AActor*, Target);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLockLost, AActor*, Target);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLockProgress, AActor*, Target, float, Progress);

/**
 * UTargetingComponent
 * 
 * EVE-like target lock system for ship-to-ship combat
 * Manages acquisition and maintenance of target locks with server authority
 * 
 * Architecture:
 * - ActorComponent: Attached to ship pawns
 * - Server-authoritative: Server controls all lock timers and validation
 * - Client-initiated: Client requests lock, server validates and processes
 * - Multiple targets: Supports locking multiple targets simultaneously
 * 
 * Lock Acquisition:
 * 1. Client calls ServerRPC_StartLock(Target)
 * 2. Server validates distance and signature radius
 * 3. Server calculates lock time: T = k / (ScanResolution × ln(TargetSize))
 * 4. Server ticks lock progress
 * 5. Server notifies client when lock completes
 * 
 * Network Model:
 * - ServerRPC_: Client requests from server
 * - ClientRPC_: Server notifies client
 * - Common_: Shared calculation functions
 * 
 * Usage:
 * // Attach to ship pawn
 * TargetingComp = CreateDefaultSubobject<UTargetingComponent>(TEXT("Targeting"));
 * 
 * // Request lock (client)
 * TargetingComp->ServerRPC_StartLock(EnemyShip);
 * 
 * // Bind UI events
 * TargetingComp->OnLockStarted.AddDynamic(this, &UWidget::HandleLockStarted);
 * TargetingComp->OnLockCompleted.AddDynamic(this, &UWidget::HandleLockCompleted);
 */
UCLASS(ClassGroup=(Echoes), meta=(BlueprintSpawnableComponent))
class ECHOES_API UTargetingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UTargetingComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// ==================== Configuration ====================

	/** Maximum lock range in cm (default: 25000m = 2500000cm) */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Targeting|Config")
	float MaxLockRange;

	/** Scan resolution of this ship (affects lock speed) */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Targeting|Config")
	float ScanResolution;

	/** Lock time formula constant (k in T = k / (ScanResolution × ln(TargetSize))) */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Targeting|Config")
	float LockTimeConstant;

	/** Maximum number of simultaneous locks */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Targeting|Config")
	int32 MaxSimultaneousLocks;

	// ==================== Target Lock Management ====================

	/** Array of current target locks */
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Targeting")
	TArray<FTargetLockEntry> TargetLocks;

	// ==================== Server RPC Functions ====================

	/**
	 * Request target lock acquisition (Client → Server)
	 * Server validates distance and signature radius, then starts lock timer
	 * 
	 * @param Target - Actor to lock onto
	 * 
	 * Validation:
	 * - Server authority check
	 * - Target exists and is valid
	 * - Target within MaxLockRange
	 * - Not already locked/locking this target
	 * - Available lock slot (< MaxSimultaneousLocks)
	 * - Target has signature radius (for lock time calculation)
	 * 
	 * Success:
	 * - Adds target to TargetLocks array
	 * - Calculates required lock time
	 * - Notifies client via ClientRPC_OnLockStarted
	 * - Broadcasts OnLockStarted event
	 */
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "Targeting")
	void ServerRPC_StartLock(AActor* Target);

	/**
	 * Request target lock cancellation (Client → Server)
	 * 
	 * @param Target - Actor to cancel lock on
	 */
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "Targeting")
	void ServerRPC_CancelLock(AActor* Target);

	/**
	 * Clear all locks (Client → Server)
	 */
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "Targeting")
	void ServerRPC_ClearAllLocks();

	// ==================== Client RPC Functions ====================

	/**
	 * Notify client that lock has started (Server → Client)
	 * 
	 * @param Target - Actor being locked
	 */
	UFUNCTION(Client, Reliable, Category = "Targeting")
	void ClientRPC_OnLockStarted(AActor* Target);

	/**
	 * Notify client that lock has completed (Server → Client)
	 * 
	 * @param Target - Actor that was locked
	 */
	UFUNCTION(Client, Reliable, Category = "Targeting")
	void ClientRPC_OnLockCompleted(AActor* Target);

	/**
	 * Notify client that lock was lost (Server → Client)
	 * 
	 * @param Target - Actor that lost lock
	 */
	UFUNCTION(Client, Reliable, Category = "Targeting")
	void ClientRPC_OnLockLost(AActor* Target);

	// ==================== Common Calculation Functions ====================

	/**
	 * Calculate required lock time for target (Pure function)
	 * Formula: T = k / (ScanResolution × ln(TargetSize))
	 * 
	 * @param Target - Target actor
	 * @return Required lock time in seconds
	 * 
	 * Notes:
	 * - Uses target's signature radius if available
	 * - Falls back to bounding box size if no signature
	 * - Returns 0.0 if target is invalid
	 */
	UFUNCTION(BlueprintPure, Category = "Targeting")
	float Common_CalculateLockTime(AActor* Target) const;

	/**
	 * Get target's signature radius (Pure function)
	 * 
	 * @param Target - Target actor
	 * @return Signature radius in meters
	 */
	UFUNCTION(BlueprintPure, Category = "Targeting")
	float Common_GetTargetSignatureRadius(AActor* Target) const;

	/**
	 * Check if target is within lock range (Pure function)
	 * 
	 * @param Target - Target actor
	 * @return True if within MaxLockRange
	 */
	UFUNCTION(BlueprintPure, Category = "Targeting")
	bool Common_IsTargetInRange(AActor* Target) const;

	/**
	 * Get lock progress for specific target (Pure function)
	 * 
	 * @param Target - Target actor
	 * @return Lock progress (0.0 to 1.0), or -1.0 if not found
	 */
	UFUNCTION(BlueprintPure, Category = "Targeting")
	float Common_GetLockProgress(AActor* Target) const;

	/**
	 * Get lock state for specific target (Pure function)
	 * 
	 * @param Target - Target actor
	 * @return Lock state, or None if not found
	 */
	UFUNCTION(BlueprintPure, Category = "Targeting")
	ETargetLockState Common_GetLockState(AActor* Target) const;

	/**
	 * Check if target is locked (Pure function)
	 * 
	 * @param Target - Target actor
	 * @return True if target is fully locked
	 */
	UFUNCTION(BlueprintPure, Category = "Targeting")
	bool Common_IsTargetLocked(AActor* Target) const;

	/**
	 * Get all locked targets (Pure function)
	 * 
	 * @return Array of locked target actors
	 */
	UFUNCTION(BlueprintPure, Category = "Targeting")
	TArray<AActor*> Common_GetLockedTargets() const;

	/**
	 * Get number of available lock slots (Pure function)
	 * 
	 * @return Number of remaining lock slots
	 */
	UFUNCTION(BlueprintPure, Category = "Targeting")
	int32 Common_GetAvailableLockSlots() const;

	// ==================== Blueprint Events ====================

	/** Fired when target lock acquisition starts */
	UPROPERTY(BlueprintAssignable, Category = "Targeting|Events")
	FOnLockStarted OnLockStarted;

	/** Fired when target lock is completed */
	UPROPERTY(BlueprintAssignable, Category = "Targeting|Events")
	FOnLockCompleted OnLockCompleted;

	/** Fired when target lock is lost */
	UPROPERTY(BlueprintAssignable, Category = "Targeting|Events")
	FOnLockLost OnLockLost;

	/** Fired when lock progress updates (per tick) */
	UPROPERTY(BlueprintAssignable, Category = "Targeting|Events")
	FOnLockProgress OnLockProgress;

protected:
	// ==================== Internal Functions ====================

	/**
	 * Update lock timers and progress (Server only)
	 * Called from TickComponent
	 */
	void UpdateLockTimers(float DeltaTime);

	/**
	 * Find target lock entry by actor
	 * 
	 * @param Target - Target actor to find
	 * @return Pointer to entry, or nullptr if not found
	 */
	FTargetLockEntry* FindLockEntry(AActor* Target);

	/**
	 * Find target lock entry by actor (const version)
	 * 
	 * @param Target - Target actor to find
	 * @return Pointer to entry, or nullptr if not found
	 */
	const FTargetLockEntry* FindLockEntry(AActor* Target) const;

	/**
	 * Remove target lock entry
	 * 
	 * @param Target - Target actor to remove
	 * @return True if entry was removed
	 */
	bool RemoveLockEntry(AActor* Target);

	/**
	 * Validate target is still lockable (distance, alive, etc.)
	 * 
	 * @param Target - Target actor to validate
	 * @return True if target is still valid for locking
	 */
	bool ValidateTarget(AActor* Target) const;
};
