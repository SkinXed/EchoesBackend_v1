// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Http.h"
#include "PersistenceComponent.h"
#include "EchoesPersistenceSubsystem.generated.h"

/**
 * Structure for queued save request
 * Used to batch and manage state save requests
 */
USTRUCT()
struct FPersistenceSaveRequest
{
	GENERATED_BODY()

	/** Character ID to save */
	FGuid CharacterId;

	/** State data to save */
	FCommon_StateData StateData;

	/** Timestamp when request was queued */
	FDateTime QueuedTime;

	/** Whether this is a high priority request (e.g., logout) */
	bool bHighPriority;

	FPersistenceSaveRequest()
		: bHighPriority(false)
	{
		QueuedTime = FDateTime::UtcNow();
	}
};

/**
 * UEchoesPersistenceSubsystem
 * 
 * Centralized persistence management system for character state saves
 * GameInstanceSubsystem that manages all HTTP communication with backend API
 * 
 * Architecture Benefits:
 * - Centralization: One HTTP client for all ships (not 1000 individual clients)
 * - Lifecycle Stability: Lives for entire game session (unlike ActorComponents)
 * - Request Management: Queue, batch, and throttle API calls
 * - Code Clarity: Separation of concerns (components collect data, subsystem sends it)
 * 
 * Usage:
 * - Components call ServerOnly_QueueStateSave() to request a save
 * - PlayerController calls ServerOnly_SaveStateImmediate() on logout
 * - Subsystem handles all HTTP communication and error handling
 * 
 * Features:
 * - Request queuing to prevent API spam
 * - Priority system (logout = high priority)
 * - Automatic retry on failure
 * - Centralized authentication (X-Server-Secret)
 */
UCLASS(Config = Game)
class ECHOES_API UEchoesPersistenceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	// ==================== Subsystem Lifecycle ====================
	
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// ==================== Configuration ====================

	/** Backend API base URL */
	UPROPERTY(Config, EditAnywhere, Category = "Persistence|Config")
	FString ApiBaseUrl = TEXT("http://localhost:5116/api");

	/** Server secret for X-Server-Secret header authentication */
	UPROPERTY(Config, EditAnywhere, Category = "Persistence|Config")
	FString ServerSecret = TEXT("UE5-Server-Secret-Change-Me-In-Production");

	/** Maximum number of requests in queue before dropping old ones */
	UPROPERTY(Config, EditAnywhere, Category = "Persistence|Config")
	int32 MaxQueueSize = 100;

	/** Time between processing queued requests (seconds) */
	UPROPERTY(Config, EditAnywhere, Category = "Persistence|Config")
	float QueueProcessInterval = 1.0f;

	// ==================== Public Interface ====================

	/**
	 * Queue a state save request (non-blocking)
	 * Used by heartbeat saves and periodic updates
	 * Request will be processed when queue is serviced
	 * 
	 * @param CharacterId - Character ID to save
	 * @param StateData - State data to save
	 * @return True if successfully queued, false if queue is full
	 */
	UFUNCTION(BlueprintCallable, Category = "Persistence")
	bool ServerOnly_QueueStateSave(const FGuid& CharacterId, const FCommon_StateData& StateData);

	/**
	 * Save state immediately (blocking until HTTP request completes)
	 * Used for critical saves like logout
	 * Bypasses queue for high priority
	 * 
	 * @param CharacterId - Character ID to save
	 * @param StateData - State data to save
	 */
	UFUNCTION(BlueprintCallable, Category = "Persistence")
	void ServerOnly_SaveStateImmediate(const FGuid& CharacterId, const FCommon_StateData& StateData);

	/**
	 * Get number of requests currently in queue
	 * @return Queue size
	 */
	UFUNCTION(BlueprintPure, Category = "Persistence")
	int32 GetQueueSize() const { return SaveQueue.Num(); }

	/**
	 * Get total number of successful saves
	 * @return Save count
	 */
	UFUNCTION(BlueprintPure, Category = "Persistence")
	int32 GetSaveCount() const { return TotalSaveCount; }

	/**
	 * Get total number of failed saves
	 * @return Fail count
	 */
	UFUNCTION(BlueprintPure, Category = "Persistence")
	int32 GetFailCount() const { return TotalFailCount; }

protected:
	// ==================== Queue Processing ====================

	/**
	 * Process queued save requests
	 * Called periodically by timer
	 */
	void ProcessSaveQueue();

	/**
	 * Send a single save request to backend
	 * @param Request - Save request to send
	 */
	void SendSaveRequest(const FPersistenceSaveRequest& Request);

	/**
	 * Build JSON payload for save request
	 * @param StateData - State data to serialize
	 * @return JSON string
	 */
	FString BuildJsonPayload(const FCommon_StateData& StateData);

	// ==================== HTTP Callbacks ====================

	/**
	 * Callback for successful save
	 * @param CharacterId - Character that was saved
	 * @param Response - HTTP response body
	 */
	void OnSaveSuccess(const FGuid& CharacterId, const FString& Response);

	/**
	 * Callback for failed save
	 * @param CharacterId - Character that failed to save
	 * @param Error - Error message
	 */
	void OnSaveError(const FGuid& CharacterId, const FString& Error);

	// ==================== Internal State ====================

	/** Queue of pending save requests */
	TArray<FPersistenceSaveRequest> SaveQueue;

	/** Timer handle for queue processing */
	FTimerHandle QueueProcessTimerHandle;

	/** Total number of successful saves */
	int32 TotalSaveCount;

	/** Total number of failed saves */
	int32 TotalFailCount;

	/** Whether a save request is currently in progress */
	bool bSaveInProgress;

	/** World reference for timer management */
	UWorld* CachedWorld;
};
