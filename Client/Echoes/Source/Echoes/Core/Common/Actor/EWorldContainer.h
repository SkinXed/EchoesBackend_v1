// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Http.h"
#include "EWorldContainer.generated.h"

/**
 * Structure for world object data
 * Mirrors RegisterWorldObjectRequest and WorldObjectResponse from backend
 */
USTRUCT(BlueprintType)
struct FWorldObjectData
{
	GENERATED_BODY()

	/** Unique ID for this world object (from backend) */
	UPROPERTY(BlueprintReadWrite, Category = "WorldObject")
	FGuid Id;

	/** Template ID for the object type */
	UPROPERTY(BlueprintReadWrite, Category = "WorldObject")
	int32 TemplateId;

	/** Solar system ID */
	UPROPERTY(BlueprintReadWrite, Category = "WorldObject")
	FGuid SystemId;

	/** Position in 3D space */
	UPROPERTY(BlueprintReadWrite, Category = "WorldObject")
	FVector Position;

	/** Rotation (quaternion) */
	UPROPERTY(BlueprintReadWrite, Category = "WorldObject")
	FQuat Rotation;

	/** JSON serialized inventory contents */
	UPROPERTY(BlueprintReadWrite, Category = "WorldObject")
	FString InventoryJson;

	/** Expiration time (optional) */
	UPROPERTY(BlueprintReadWrite, Category = "WorldObject")
	FDateTime ExpirationTime;

	FWorldObjectData()
		: TemplateId(0)
		, Position(FVector::ZeroVector)
		, Rotation(FQuat::Identity)
		, InventoryJson(TEXT("{}"))
	{
	}
};

/**
 * AEWorldContainer
 * 
 * Container actor for items dropped in space
 * Server-only actor that persists across server restarts via backend API
 * 
 * Features:
 * - Auto-registration to backend on spawn (BeginPlay)
 * - Real-time inventory sync to backend on changes
 * - Cleanup on destruction or expiration
 * - Spawned from database on server startup via WorldManager
 * 
 * Usage:
 * 1. Spawn container in space
 * 2. Component automatically registers to backend
 * 3. When inventory changes, call UpdateInventory()
 * 4. Container persists across server restarts
 * 5. Cleanup service removes expired containers
 */
UCLASS()
class ECHOES_API AEWorldContainer : public AActor
{
	GENERATED_BODY()

public:
	AEWorldContainer();

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	// ==================== Configuration ====================

	/** Backend API base URL */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WorldObject|Config")
	FString ApiBaseUrl = TEXT("http://localhost:5116/api");

	/** Server secret for X-Server-Secret header authentication */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WorldObject|Config")
	FString ServerSecret = TEXT("UE5-Server-Secret-Change-Me-In-Production");

	/** Template ID for this container type */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WorldObject|Config")
	int32 TemplateId = 1;

	/** Solar system ID where this container exists */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WorldObject|Config")
	FGuid SystemId;

	/** Optional expiration time (hours from now, 0 = never expires) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WorldObject|Config")
	float ExpirationHours = 24.0f;

	/** Whether this container was spawned from database (vs newly created) */
	UPROPERTY(BlueprintReadOnly, Category = "WorldObject|State")
	bool bLoadedFromDatabase = false;

	// ==================== Public Interface ====================

	/**
	 * Update container inventory and sync to backend
	 * Call this whenever items are added/removed from container
	 * @param NewInventoryJson - Updated inventory JSON
	 */
	UFUNCTION(BlueprintCallable, Category = "WorldObject")
	void ServerOnly_UpdateInventory(const FString& NewInventoryJson);

	/**
	 * Get world object data for this container
	 * @return Current world object data
	 */
	UFUNCTION(BlueprintPure, Category = "WorldObject")
	FWorldObjectData GetWorldObjectData() const;

	/**
	 * Initialize container from database data
	 * Called by WorldManager when spawning from database
	 * @param Data - World object data from database
	 */
	UFUNCTION(BlueprintCallable, Category = "WorldObject")
	void InitializeFromDatabase(const FWorldObjectData& Data);

	/**
	 * Get the backend object ID
	 * @return Object ID in backend database
	 */
	UFUNCTION(BlueprintPure, Category = "WorldObject")
	FGuid GetObjectId() const { return ObjectId; }

protected:
	// ==================== Core Logic ====================

	/**
	 * Register this container to backend database
	 * Called automatically in BeginPlay for new containers
	 */
	UFUNCTION()
	void ServerOnly_RegisterToBackend();

	/**
	 * Unregister this container from backend database
	 * Called optionally in EndPlay if needed
	 */
	UFUNCTION()
	void ServerOnly_UnregisterFromBackend();

	/**
	 * Send inventory update to backend
	 */
	UFUNCTION()
	void ServerOnly_SendInventoryUpdate();

	// ==================== HTTP Callbacks ====================

	/**
	 * Callback for successful registration
	 */
	void OnRegistrationSuccess(const FString& Response);

	/**
	 * Callback for failed registration
	 */
	void OnRegistrationError(const FString& Error);

	/**
	 * Callback for successful inventory update
	 */
	void OnInventoryUpdateSuccess(const FString& Response);

	/**
	 * Callback for failed inventory update
	 */
	void OnInventoryUpdateError(const FString& Error);

	// ==================== Internal State ====================

	/** Object ID in backend database */
	FGuid ObjectId;

	/** Current inventory JSON */
	FString CurrentInventoryJson;

	/** Whether registration is in progress */
	bool bRegistrationInProgress;

	/** Whether inventory update is in progress */
	bool bInventoryUpdateInProgress;

	/** Pending inventory update (queued if update in progress) */
	FString PendingInventoryUpdate;

	/** Whether there's a pending inventory update */
	bool bHasPendingUpdate;
};
