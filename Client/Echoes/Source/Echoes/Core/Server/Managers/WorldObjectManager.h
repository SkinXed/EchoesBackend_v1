// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Http.h"
#include "EWorldContainer.h"
#include "WorldObjectManager.generated.h"

/**
 * UWorldObjectManager
 * 
 * Manages world object persistence for a solar system
 * Server-only component that queries backend for existing world objects on startup
 * and spawns them back into the world
 * 
 * Usage:
 * 1. Attach to GameMode or World State actor
 * 2. Set SystemId to current solar system
 * 3. On BeginPlay, queries backend and spawns all containers/debris
 * 4. New containers auto-register themselves via AEWorldContainer
 * 
 * Features:
 * - Queries backend for existing world objects on startup
 * - Spawns containers from database
 * - Tracks spawned objects for management
 * - Can manually trigger refresh
 */
UCLASS(ClassGroup=(Echoes), meta=(BlueprintSpawnableComponent))
class ECHOES_API UWorldObjectManager : public UActorComponent
{
	GENERATED_BODY()

public:
	UWorldObjectManager();

	virtual void BeginPlay() override;

	// ==================== Configuration ====================

	/** Backend API base URL */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WorldObject|Config")
	FString ApiBaseUrl = TEXT("http://localhost:5116/api");

	/** Server secret for X-Server-Secret header authentication */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WorldObject|Config")
	FString ServerSecret = TEXT("UE5-Server-Secret-Change-Me-In-Production");

	/** Solar system ID to query world objects for */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WorldObject|Config")
	FGuid SystemId;

	/** Container actor class to spawn */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WorldObject|Config")
	TSubclassOf<AEWorldContainer> ContainerClass;

	/** Whether to auto-load on BeginPlay */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WorldObject|Config")
	bool bAutoLoadOnBeginPlay = true;

	// ==================== Public Interface ====================

	/**
	 * Load world objects from backend and spawn them
	 * Can be called manually or automatically on BeginPlay
	 */
	UFUNCTION(BlueprintCallable, Category = "WorldObject")
	void ServerOnly_LoadWorldObjects();

	/**
	 * Get all spawned world objects
	 * @return Array of spawned container actors
	 */
	UFUNCTION(BlueprintPure, Category = "WorldObject")
	TArray<AEWorldContainer*> GetSpawnedContainers() const { return SpawnedContainers; }

	/**
	 * Get count of spawned containers
	 * @return Number of containers currently spawned
	 */
	UFUNCTION(BlueprintPure, Category = "WorldObject")
	int32 GetContainerCount() const { return SpawnedContainers.Num(); }

protected:
	// ==================== Core Logic ====================

	/**
	 * Query backend for world objects in this system
	 */
	UFUNCTION()
	void ServerOnly_QueryBackend();

	/**
	 * Spawn a container from database data
	 * @param Data - World object data from backend
	 */
	UFUNCTION()
	void ServerOnly_SpawnContainer(const FWorldObjectData& Data);

	// ==================== HTTP Callbacks ====================

	/**
	 * Callback for successful query
	 */
	void OnQuerySuccess(const FString& Response);

	/**
	 * Callback for failed query
	 */
	void OnQueryError(const FString& Error);

	// ==================== Internal State ====================

	/** List of containers spawned by this manager */
	UPROPERTY()
	TArray<AEWorldContainer*> SpawnedContainers;

	/** Whether query is in progress */
	bool bQueryInProgress;

	/** Whether world objects have been loaded */
	bool bWorldObjectsLoaded;
};
