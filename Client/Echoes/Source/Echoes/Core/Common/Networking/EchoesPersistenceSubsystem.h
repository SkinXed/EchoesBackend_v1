// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "EchoesPersistenceSubsystem.generated.h"
// Forward declare the state struct from PersistenceComponent to avoid include order issues
struct FCommon_StateData;

// Forward-declare HTTP types to avoid including Http.h in the header (keeps generated.h last)
class IHttpRequest;
class IHttpResponse;
class FHttpModule;
using FHttpRequestPtr = TSharedPtr<IHttpRequest, ESPMode::ThreadSafe>;
using FHttpResponsePtr = TSharedPtr<IHttpResponse, ESPMode::ThreadSafe>;



/** Custom log category for persistence operations */
DECLARE_LOG_CATEGORY_EXTERN(LogEchoesPersistence, Log, All);

// Forward declarations
class UEchoesIdentitySubsystem;
class UEchoesInventorySubsystem;
class UEchoesMarketSubsystem;

// ==================== Structures ====================

/**
 * Snapshot of persisted character state from backend
 * Mirrors the data returned by GET /api/character/me
 */
USTRUCT(BlueprintType)
struct FPersistenceCharacterState
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Persistence")
	FGuid CharacterId;

	UPROPERTY(BlueprintReadOnly, Category = "Persistence")
	int64 WalletBalance = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Persistence")
	bool IsDocked = true;

	UPROPERTY(BlueprintReadOnly, Category = "Persistence")
	FDateTime LastSyncTime;

	UPROPERTY(BlueprintReadOnly, Category = "Persistence")
	bool bIsValid = false;
};

/** Sync operation state */
UENUM(BlueprintType)
enum class EPersistenceSyncState : uint8
{
	Idle,
	Syncing,
	Error
};

// ==================== Delegates ====================

/** Fired when character state is successfully synced from backend */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPersistenceStateSynced, const FPersistenceCharacterState&, State);

/** Fired when a persistence sync operation fails */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPersistenceSyncFailed, const FString&, ErrorMessage);

/** Fired when wallet balance changes after sync */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWalletBalanceChanged, int64, OldBalance, int64, NewBalance);

/**
 * UEchoesPersistenceSubsystem
 * 
 * State persistence and synchronization subsystem for Echoes MMO
 * Provides centralized wallet/inventory state refresh from ASP.NET backend
 * 
 * Architecture:
 * - GameInstanceSubsystem: Persists across level transitions
 * - ServerOnly_ prefix: Methods intended for UE5 dedicated server
 * - Reads ApiBaseUrl and X-Server-Secret from config (DefaultGame.ini)
 * - Coordinates with IdentitySubsystem (character data), InventorySubsystem (items),
 *   and MarketSubsystem (post-trade sync)
 * 
 * Key Features:
 * - ServerOnly_ForceSaveState(): Immediately syncs character state from backend
 * - Auto-subscribes to MarketSubsystem.OnInventorySyncRequired for post-trade sync
 * - Tracks last sync time and wallet delta for UI notifications
 * - Prevents duplicate sync requests while one is in-flight
 */
UCLASS()
class ECHOES_API UEchoesPersistenceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	// Subsystem lifecycle
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// ==================== Server-Only Persistence Functions ====================

	/**
	 * Force synchronize character state from the backend database
	 * Fetches latest wallet balance and character state via GET /api/character/me
	 * Triggers inventory cache refresh via InventorySubsystem
	 * Prevents duplicate requests while a sync is in-flight
	 * 
	 * Call this after any operation that mutates server-side state (trades, purchases, etc.)
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Persistence")
	void ServerOnly_ForceSaveState();

	/**
	 * Force sync for a specific character by ID
	 * Used by MarketSubsystem.OnInventorySyncRequired delegate
	 * 
	 * @param CharacterId - Character whose state needs syncing
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Persistence")
	void ServerOnly_ForceSaveStateForCharacter(const FGuid& CharacterId);

	/**
	 * Sync only the wallet balance (lightweight, no inventory refresh)
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Persistence")
	void ServerOnly_SyncWallet();

	/** Public queue API - used by UPersistenceComponent to enqueue saves */
	bool ServerOnly_QueueStateSave(const FGuid& CharacterId, const FCommon_StateData& StateData);

	/** Immediate save API - used for logout/high-priority saves */
	void ServerOnly_SaveStateImmediate(const FGuid& CharacterId, const FCommon_StateData& StateData);

	// ==================== State Accessors ====================

	/**
	 * Get the last synced character state
	 * @return Cached persistence state (may be stale if not recently synced)
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Persistence")
	FPersistenceCharacterState GetCachedState() const { return CachedState; }

	/**
	 * Get the current sync state
	 * @return Current sync operation state
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Persistence")
	EPersistenceSyncState GetSyncState() const { return SyncState; }

	/**
	 * Get time since last successful sync
	 * @return Seconds since last sync, or -1 if never synced
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Persistence")
	float GetTimeSinceLastSync() const;

	/**
	 * Check if cached state is valid and not stale
	 * @param MaxAgeSeconds - Maximum age in seconds before considered stale (default: 60)
	 * @return True if state is valid and within max age
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Persistence")
	bool IsStateValid(float MaxAgeSeconds = 60.0f) const;

	// ==================== Delegates ====================

	/** Fired when character state is synced from backend */
	UPROPERTY(BlueprintAssignable, Category = "Echoes|Persistence")
	FOnPersistenceStateSynced OnStateSynced;

	/** Fired when sync fails */
	UPROPERTY(BlueprintAssignable, Category = "Echoes|Persistence")
	FOnPersistenceSyncFailed OnSyncFailed;

	/** Fired when wallet balance changes */
	UPROPERTY(BlueprintAssignable, Category = "Echoes|Persistence")
	FOnWalletBalanceChanged OnWalletBalanceChanged;

protected:
	// ==================== HTTP Response Handlers ====================

	void OnCharacterStateReceived(
		FHttpRequestPtr Request,
		FHttpResponsePtr Response,
		bool bWasSuccessful,
		bool bRefreshInventory);

	// ==================== Helper Functions ====================

	/** Get JWT token from Auth subsystem */
	FString GetAuthToken() const;

	/** Get API base URL from configuration */
	FString GetApiBaseUrl() const;

	/** Get server secret from configuration */
	FString GetServerSecret() const;

	/** Subscribe to market subsystem events */
	void BindToMarketSubsystem();

private:
	/** HTTP module reference */
	FHttpModule* Http = nullptr;

	/** Cached character persistence state */
	UPROPERTY()
	FPersistenceCharacterState CachedState;

	/** Current sync operation state */
	EPersistenceSyncState SyncState = EPersistenceSyncState::Idle;

	/** Handler for OnInventorySyncRequired from MarketSubsystem */
	UFUNCTION()
	void HandleMarketInventorySync(const FGuid& CharacterId);
};
