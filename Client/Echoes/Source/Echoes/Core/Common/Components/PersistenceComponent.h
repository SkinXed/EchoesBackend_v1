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
 * Handles character state persistence for crash recovery
 * Server-only component that saves player position, rotation, and ship stats to backend
 * 
 * Features:
 * - Logout Save: Guaranteed save when player disconnects gracefully
 * - Heartbeat Save: Auto-save every 60 seconds (configurable)
 * - Dirty Flag: Only save when position changed >1m or stats changed (traffic optimization)
 * - HTTP Integration: Sends PUT requests to backend API with X-Server-Secret authentication
 * 
 * Attach this component to ship pawns (AEPawn/AEchoesShipPawn)
 * Server spawns and manages this component automatically
 * 
 * Naming Convention:
 * - ServerOnly_ prefix: Methods that only run on server
 * - Common_ prefix: Data structures/methods that run on any context
 * - ClientRPC_ prefix: Client RPC calls (optional for notifications)
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

	/** Backend API base URL */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Persistence|Config")
	FString ApiBaseUrl = TEXT("http://localhost:5116/api");

	/** Server secret for X-Server-Secret header authentication */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Persistence|Config")
	FString ServerSecret = TEXT("UE5-Server-Secret-Change-Me-In-Production");

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

protected:
	// ==================== Core Persistence Logic ====================

	/**
	 * Collect current state from owner actor
	 * Gathers: Position (GetActorLocation), Rotation (GetActorRotation), Stats (ShipStateComponent)
	 * @return Current state data
	 */
	UFUNCTION()
	FCommon_StateData ServerOnly_CollectCurrentState();

	/**
	 * Save state to backend via HTTP PUT request
	 * Sends async HTTP request to PUT /api/persistence/state/{characterId}
	 * @param StateData - State data to save
	 */
	UFUNCTION()
	void ServerOnly_SaveToBackend(const FCommon_StateData& StateData);

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

	// ==================== HTTP Callbacks ====================

	/**
	 * Callback for successful state save
	 * @param Response - HTTP response body
	 */
	void OnSaveSuccess(const FString& Response);

	/**
	 * Callback for failed state save
	 * @param Error - Error message
	 */
	void OnSaveError(const FString& Error);

	// ==================== Internal State ====================

	/** Last saved state for dirty flag comparison */
	FCommon_StateData LastSavedState;

	/** Accumulated time since last heartbeat save */
	float TimeSinceLastHeartbeat;

	/** Cached reference to ship stats component */
	UPROPERTY()
	UEchoesStatsComponent* CachedStatsComponent;

	/** Whether a save is currently in progress */
	bool bSaveInProgress;

	/** Number of successful saves */
	int32 SaveCount;

	/** Number of failed saves */
	int32 FailCount;
};
