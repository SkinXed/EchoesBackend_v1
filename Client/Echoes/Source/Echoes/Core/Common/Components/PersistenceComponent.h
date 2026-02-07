// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Http.h"
#include "PersistenceComponent.generated.h"

class UEchoesStatsComponent;

/**
 * Structure for character state data
 * Common_ prefix indicates it's used on both client and server
 * Mirrors SaveCharacterStateRequest DTO from backend
 */
USTRUCT(BlueprintType)
struct FCommon_StateData
{
	GENERATED_BODY()

	/** Last solar system ID (nullable) */
	UPROPERTY(BlueprintReadWrite, Category = "State")
	FGuid LastSystemId;

	/** Position in 3D space */
	UPROPERTY(BlueprintReadWrite, Category = "State")
	FVector Position;

	/** Rotation (quaternion) */
	UPROPERTY(BlueprintReadWrite, Category = "State")
	FQuat Rotation;

	/** Current shield hit points */
	UPROPERTY(BlueprintReadWrite, Category = "State")
	float CurrentShield;

	/** Current armor hit points */
	UPROPERTY(BlueprintReadWrite, Category = "State")
	float CurrentArmor;

	/** Current hull (structure) hit points */
	UPROPERTY(BlueprintReadWrite, Category = "State")
	float CurrentHull;

	/** Current capacitor energy */
	UPROPERTY(BlueprintReadWrite, Category = "State")
	float CurrentCapacitor;

	FCommon_StateData()
		: Position(FVector::ZeroVector)
		, Rotation(FQuat::Identity)
		, CurrentShield(0.0f)
		, CurrentArmor(0.0f)
		, CurrentHull(0.0f)
		, CurrentCapacitor(0.0f)
	{
	}
};

/**
 * UPersistenceComponent
 * 
 * Lightweight component for collecting character state data
 * Refactored to use UEchoesPersistenceSubsystem for HTTP communication
 * 
 * Architecture:
 * - Component: Collects state data (position, rotation, stats)
 * - Subsystem: Handles HTTP requests, queuing, authentication
 * - PlayerController: Triggers final save on logout
 * 
 * Features:
 * - Heartbeat Save: Auto-save every 60 seconds (calls subsystem)
 * - Dirty Flag: Only save when position changed >1m or stats changed
 * - Data Collection: Gathers position, rotation, and stats from ship
 * 
 * Note: This component NO LONGER handles HTTP requests directly.
 * All network communication goes through UEchoesPersistenceSubsystem.
 * 
 * Naming Convention:
 * - ServerOnly_ prefix: Methods that only run on server
 * - Common_ prefix: Data structures/methods that run on any context
 */
UCLASS(ClassGroup=(Echoes), meta=(BlueprintSpawnableComponent))
class ECHOES_API UPersistenceComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// ==================== Component Lifecycle ====================
	
	UPersistenceComponent();

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// ==================== Configuration ====================

	/** Character ID for this persistence instance */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Persistence|Config")
	FGuid CharacterId;

	/** Heartbeat save interval in seconds (auto-save timer) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Persistence|Config")
	float HeartbeatInterval = 60.0f;

	/** Minimum position change in centimeters to trigger dirty flag */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Persistence|Config")
	float DirtyPositionThreshold = 100.0f; // 1 meter in UE units (cm)

	/** Whether to enable heartbeat auto-save */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Persistence|Config")
	bool bEnableHeartbeat = true;

	/** Whether to enable dirty flag optimization */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Persistence|Config")
	bool bEnableDirtyFlag = true;

	/**
	 * Default capacitor value to use when actual capacitor component is not available
	 * This is a temporary fallback until ship power/capacitor component is implemented
	 * Typical values: Frigate ~1000-1500, Cruiser ~2000-3000, Battleship ~5000-7000
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Persistence|Config")
	float DefaultCapacitorValue = 1000.0f;

	// ==================== Public Interface ====================

	/**
	 * Manually trigger a state save
	 * Can be called from game logic for explicit save points
	 */
	UFUNCTION(BlueprintCallable, Category = "Persistence")
	void ServerOnly_TriggerSave();

	/**
	 * Set character ID for this component
	 * Should be called during initialization
	 */
	UFUNCTION(BlueprintCallable, Category = "Persistence")
	void Common_SetCharacterId(const FGuid& InCharacterId);

	/**
	 * Collect current state from owner actor
	 * Public so PlayerController can call it on logout
	 * Gathers: Position (GetActorLocation), Rotation (GetActorRotation), Stats (ShipStateComponent)
	 * @return Current state data
	 */
	UFUNCTION(BlueprintCallable, Category = "Persistence")
	FCommon_StateData ServerOnly_CollectCurrentState();

protected:
	// ==================== Core Persistence Logic ====================

	/**
	 * Check if state has changed enough to trigger a save (dirty flag logic)
	 * @param NewState - New state to compare against last saved state
	 * @return True if state is dirty and should be saved
	 */
	UFUNCTION()
	bool ServerOnly_IsDirty(const FCommon_StateData& NewState) const;

	// ==================== Trigger System ====================

	/**
	 * Heartbeat save timer callback
	 * Called every HeartbeatInterval seconds
	 */
	UFUNCTION()
	void ServerOnly_OnHeartbeatTimer();

	// ==================== Internal State ====================

	/** Last saved state for dirty flag comparison */
	FCommon_StateData LastSavedState;

	/** Accumulated time since last heartbeat save */
	float TimeSinceLastHeartbeat;

	/** Cached reference to ship stats component */
	UPROPERTY()
	UEchoesStatsComponent* CachedStatsComponent;

	/** Cached reference to persistence subsystem */
	UPROPERTY()
	class UEchoesPersistenceSubsystem* PersistenceSubsystem;
};
