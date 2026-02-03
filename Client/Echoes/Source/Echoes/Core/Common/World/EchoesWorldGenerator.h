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
class AMoonActor;
class AStarActor;
class AStationActor;
class AStargateActor;
class AAsteroidBeltActor;
class AAnomalyActor;
class AWormholeActor;

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
	 * Default: 1 km = 0.0001 * 100000 cm = 10 cm (1:10,000,000 scale)
	 * This prevents floating-point precision issues at astronomical distances
	 * 
	 * IMPORTANT: ConvertCoordinates uses DOUBLE PRECISION to avoid jitter
	 * 
	 * Example: Planet at 150,000,000 km (1 AU) -> 1,500,000,000 cm (15,000 km) in Unreal
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation|Scale")
	float UniverseToWorldScale = 0.0001f; // 1 km = 10 cm (configurable)

	/**
	 * Regional distance scale for separating multiple systems
	 * Each system gets offset by its DB coordinates * this scale
	 * 
	 * Default: 1,000,000,000 (1 billion units)
	 * Prevents visual and physics interference between systems
	 * Supports Large World Coordinates (LWC) with double precision
	 * 
	 * Example: System at DB coords (10, 0, 0) -> offset (10B, 0, 0) Unreal Units
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation|Scale")
	double RegionDistanceScale = 1000000000.0; // 1 billion units between systems

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation|DataTables")
	UDataTable* AsteroidBeltDataTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation|DataTables")
	UDataTable* AnomalyDataTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation|DataTables")
	UDataTable* WormholeDataTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation|DataTables")
	UDataTable* MoonDataTable;

	/**
	 * Actor classes to spawn
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation|ActorClasses")
	TSubclassOf<APlanetActor> PlanetActorClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation|ActorClasses")
	TSubclassOf<AMoonActor> MoonActorClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation|ActorClasses")
	TSubclassOf<AStarActor> StarActorClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation|ActorClasses")
	TSubclassOf<AStationActor> StationActorClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation|ActorClasses")
	TSubclassOf<AStargateActor> StargateActorClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation|ActorClasses")
	TSubclassOf<AAsteroidBeltActor> AsteroidBeltActorClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation|ActorClasses")
	TSubclassOf<AAnomalyActor> AnomalyActorClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation|ActorClasses")
	TSubclassOf<AWormholeActor> WormholeActorClass;

	// ==================== Generation Control ====================

	/**
	 * Manual trigger for world generation (for testing)
	 * In production, this is called automatically via OnServerConfigReceived
	 */
	UFUNCTION(BlueprintCallable, Category = "Generation", meta = (DevelopmentOnly))
	void ServerOnly_GenerateWorld(const FServerSystemConfig& Config);

	/**
	 * Manual trigger for regional cluster world generation (for testing)
	 * In production, this is called automatically via OnRegionalClusterConfigReceived
	 */
	UFUNCTION(BlueprintCallable, Category = "Generation", meta = (DevelopmentOnly))
	void ServerOnly_GenerateRegionalCluster(const FServerRegionalClusterConfig& RegionalConfig);

	/**
	 * Clear all spawned actors
	 */
	UFUNCTION(BlueprintCallable, Category = "Generation", meta = (DevelopmentOnly))
	void ServerOnly_ClearWorld();

protected:
	// ==================== Callback Handlers ====================

	/**
	 * Called when server configuration is received from backend
	 * Triggers world generation process (DedicatedSystem mode)
	 */
	UFUNCTION()
	void OnServerConfigReceived(const FServerSystemConfig& Config);

	/**
	 * Called when regional cluster configuration is received from backend
	 * Triggers multi-system world generation (RegionalCluster mode)
	 */
	UFUNCTION()
	void OnRegionalClusterConfigReceived(const FServerRegionalClusterConfig& RegionalConfig);

	// ==================== Generation Functions ====================

	/**
	 * Generate a single solar system at the given offset
	 */
	void GenerateSingleSystem(const FServerSystemConfig& Config, const FVector& SystemOffset);

	/**
	 * Spawn star at system center (with optional offset)
	 */
	void SpawnStar(const FServerSystemConfig& Config, const FVector& SystemOffset = FVector::ZeroVector);

	/**
	 * Spawn all planets in the system (with optional offset)
	 */
	void SpawnPlanets(const TArray<FPlanetConfig>& Planets, const FVector& SystemOffset = FVector::ZeroVector);

	/**
	 * Spawn all stations in the system (with optional offset)
	 */
	void SpawnStations(const TArray<FStationConfig>& Stations, const FVector& SystemOffset = FVector::ZeroVector);

	/**
	 * Spawn all stargates in the system (with optional offset)
	 */
	void SpawnStargates(const TArray<FStargateConfig>& Stargates, const FVector& SystemOffset = FVector::ZeroVector);

	/**
	 * Spawn all asteroid belts in the system (with optional offset)
	 */
	void SpawnAsteroidBelts(const TArray<FAsteroidBeltConfig>& AsteroidBelts, const FVector& SystemOffset = FVector::ZeroVector);

	/**
	 * Spawn all anomalies in the system (with optional offset)
	 */
	void SpawnAnomalies(const TArray<FAnomalyConfig>& Anomalies, const FVector& SystemOffset = FVector::ZeroVector);

	/**
	 * Spawn all wormholes in the system (with optional offset)
	 */
	void SpawnWormholes(const TArray<FWormholeConfig>& Wormholes, const FVector& SystemOffset = FVector::ZeroVector);

	// ==================== Helper Functions ====================

	/**
	 * Calculate global offset for a system based on its DB coordinates
	 * Uses RegionDistanceScale to separate systems by billions of units
	 */
	UFUNCTION(BlueprintPure, Category = "Generation|Helpers")
	FVector CalculateSystemGlobalOffset(int64 PosX, int64 PosY, int64 PosZ) const;

	/**
	 * Convert database coordinates (km) to Unreal world coordinates (cm)
	 * Note: This is for objects WITHIN a system, not system positions
	 */
	UFUNCTION(BlueprintPure, Category = "Generation|Helpers")
	FVector ConvertCoordinates(int64 X, int64 Y, int64 Z) const;

	/**
	 * Look up visual data from data table by type
	 */
	FPlanetVisualRow* GetPlanetVisualData(const FString& PlanetType);
	FMoonVisualRow* GetMoonVisualData(const FString& MoonType);
	FStarVisualRow* GetStarVisualData(const FString& StarClass);
	FStationVisualRow* GetStationVisualData(const FString& StationType);
	FStargateVisualRow* GetStargateVisualData(const FString& Model);
	FAsteroidBeltVisualRow* GetAsteroidBeltVisualData(const FString& BeltType);
	FAnomalyVisualRow* GetAnomalyVisualData(const FString& AnomalyType);
	FWormholeVisualRow* GetWormholeVisualData(const FString& WormholeClass);

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

	/** Whether this is a regional cluster server */
	bool bIsRegionalCluster;

	/** Cached regional cluster config for system lookups */
	FServerRegionalClusterConfig CachedRegionalConfig;

	/** Map of system IDs to their global offsets for fast lookup */
	TMap<FGuid, FVector> SystemOffsets;

public:
	/**
	 * Check if a system ID is hosted on this server
	 */
	UFUNCTION(BlueprintPure, Category = "Generation|RegionalCluster")
	bool IsSystemOnThisServer(const FGuid& SystemId) const;

	/**
	 * Get the global offset for a specific system
	 */
	UFUNCTION(BlueprintPure, Category = "Generation|RegionalCluster")
	FVector GetSystemGlobalOffset(const FGuid& SystemId) const;

	/**
	 * Check if this is a regional cluster server
	 */
	UFUNCTION(BlueprintPure, Category = "Generation|RegionalCluster")
	bool IsRegionalCluster() const { return bIsRegionalCluster; }
};
