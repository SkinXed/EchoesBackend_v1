// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Core/Server/EchoesServerDiscoveryTypes.h"
#include "EchoesWorldVisualTypes.h"
#include "Engine/DataTable.h"
#include "Engine/StreamableManager.h"
#include "EchoesWorldGenerator.generated.h"

class UEchoesServerManagementSubsystem;
class APlanetActor;
class AStarActor;
class AStationActor;
class AStargateActor;

/**
 * AEchoesWorldGenerator
 * 
 * Master world generation system for Echoes universe
 * Builds solar systems based on JSON configuration from backend
 * 
 * Architecture:
 * - Subscribes to OnServerConfigReceived delegate from UEchoesServerManagementSubsystem
 * - Server-only generation (HasAuthority())
 * - Uses Data Tables for visual asset mapping
 * - Implements coordinate scaling (UniverseToWorldScale)
 * - Async asset loading with UStreamableManager
 * - Seed-based procedural variation
 * - Full replication support
 * 
 * Workflow:
 * 1. BeginPlay: Subscribe to OnServerConfigReceived
 * 2. OnConfigReceived: Parse configuration and spawn celestial objects
 * 3. For each object:
 *    - Look up visual data in corresponding DataTable
 *    - Convert coordinates using UniverseToWorldScale
 *    - Spawn replicated actor
 *    - Initialize with configuration data
 */
UCLASS()
class ECHOES_API AEchoesWorldGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	AEchoesWorldGenerator();

protected:
	virtual void BeginPlay() override;

public:
	// ==================== Configuration ====================

	/**
	 * Universe to World Scale Constant
	 * Converts database coordinates (km or AU) to Unreal Units (cm)
	 * 
	 * Default: 1 km = 100 cm (1:100,000 scale)
	 * This prevents floating-point precision issues at astronomical distances
	 * 
	 * Example: Planet at 150,000,000 km (1 AU) -> 150,000 cm (1,500 m) in Unreal
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation|Scale")
	float UniverseToWorldScale = 0.0001f; // 1 km = 0.1 cm

	/**
	 * Data Tables for visual asset mapping
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation|DataTables")
	UDataTable* PlanetDataTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation|DataTables")
	UDataTable* StarDataTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation|DataTables")
	UDataTable* StationDataTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation|DataTables")
	UDataTable* StargateDataTable;

	/**
	 * Actor classes to spawn
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation|ActorClasses")
	TSubclassOf<APlanetActor> PlanetActorClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation|ActorClasses")
	TSubclassOf<AStarActor> StarActorClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation|ActorClasses")
	TSubclassOf<AStationActor> StationActorClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation|ActorClasses")
	TSubclassOf<AStargateActor> StargateActorClass;

	// ==================== Generation Control ====================

	/**
	 * Manual trigger for world generation (for testing)
	 * In production, this is called automatically via OnServerConfigReceived
	 */
	UFUNCTION(BlueprintCallable, Category = "Generation", meta = (DevelopmentOnly))
	void ServerOnly_GenerateWorld(const FServerSystemConfig& Config);

	/**
	 * Clear all spawned actors
	 */
	UFUNCTION(BlueprintCallable, Category = "Generation", meta = (DevelopmentOnly))
	void ServerOnly_ClearWorld();

protected:
	// ==================== Callback Handler ====================

	/**
	 * Called when server configuration is received from backend
	 * Triggers world generation process
	 */
	UFUNCTION()
	void OnServerConfigReceived(const FServerSystemConfig& Config);

	// ==================== Generation Functions ====================

	/**
	 * Spawn star at system center
	 */
	void SpawnStar(const FServerSystemConfig& Config);

	/**
	 * Spawn all planets in the system
	 */
	void SpawnPlanets(const TArray<FPlanetConfig>& Planets);

	/**
	 * Spawn all stations in the system
	 */
	void SpawnStations(const TArray<FStationConfig>& Stations);

	/**
	 * Spawn all stargates in the system
	 */
	void SpawnStargates(const TArray<FStargateConfig>& Stargates);

	// ==================== Helper Functions ====================

	/**
	 * Convert database coordinates (km) to Unreal world coordinates (cm)
	 */
	UFUNCTION(BlueprintPure, Category = "Generation|Helpers")
	FVector ConvertCoordinates(int64 X, int64 Y, int64 Z) const;

	/**
	 * Look up visual data from data table by type
	 */
	FPlanetVisualRow* GetPlanetVisualData(const FString& PlanetType);
	FStarVisualRow* GetStarVisualData(const FString& StarClass);
	FStationVisualRow* GetStationVisualData(const FString& StationType);
	FStargateVisualRow* GetStargateVisualData(const FString& Model);

	/**
	 * Generate seed from GUID for procedural variation
	 */
	int32 GenerateSeedFromGuid(const FGuid& Guid) const;

	/**
	 * Async load assets before spawning (optimization)
	 */
	void AsyncLoadAssetsForConfig(const FServerSystemConfig& Config);

private:
	// ==================== Spawned Actors Tracking ====================

	UPROPERTY()
	TArray<AActor*> SpawnedActors;

	/** Reference to server management subsystem */
	UPROPERTY()
	UEchoesServerManagementSubsystem* ServerManagementSubsystem;

	/** Streamable manager for async asset loading */
	FStreamableManager StreamableManager;

	/** Whether world has been generated */
	bool bWorldGenerated;
};
