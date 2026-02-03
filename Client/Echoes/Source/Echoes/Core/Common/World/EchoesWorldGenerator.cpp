// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesWorldGenerator.h"
#include "EchoesServerManagementSubsystem.h"
#include "PlanetActor.h"
#include "StarActor.h"
#include "StationActor.h"
#include "StargateActor.h"
#include "AsteroidBeltActor.h"
#include "AnomalyActor.h"
#include "WormholeActor.h"
#include "Engine/World.h"
#include "Engine/DataTable.h"
#include "Kismet/GameplayStatics.h"

AEchoesWorldGenerator::AEchoesWorldGenerator()
{
	PrimaryActorTick.bCanEverTick = false;

	// Enable replication
	bReplicates = true;
	bAlwaysRelevant = true;

	bWorldGenerated = false;
	bIsRegionalCluster = false;
}

void AEchoesWorldGenerator::BeginPlay()
{
	Super::BeginPlay();

	// Only proceed on server
	if (!HasAuthority())
	{
		UE_LOG(LogTemp, Verbose, TEXT("EchoesWorldGenerator: Running on client, skipping initialization"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("EchoesWorldGenerator: Initializing on server"));

	// Get reference to server management subsystem
	UGameInstance* GameInstance = GetWorld()->GetGameInstance();
	if (GameInstance)
	{
		ServerManagementSubsystem = GameInstance->GetSubsystem<UEchoesServerManagementSubsystem>();
		if (ServerManagementSubsystem)
		{
			// Subscribe to both delegates
			ServerManagementSubsystem->OnServerConfigReceived.AddDynamic(
				this,
				&AEchoesWorldGenerator::OnServerConfigReceived);

			ServerManagementSubsystem->OnRegionalClusterConfigReceived.AddDynamic(
				this,
				&AEchoesWorldGenerator::OnRegionalClusterConfigReceived);

			UE_LOG(LogTemp, Log, TEXT("EchoesWorldGenerator: Successfully subscribed to config delegates"));

			// CRITICAL FIX: Check if config was already received before we subscribed
			// This prevents race condition where HTTP response arrives before BeginPlay
			if (ServerManagementSubsystem->IsServerRegistered() && ServerManagementSubsystem->HasCachedConfig())
			{
				UE_LOG(LogTemp, Warning, TEXT("EchoesWorldGenerator: Server already registered with cached config, triggering generation now"));
				
				if (ServerManagementSubsystem->IsRegionalCluster())
				{
					// Regional cluster mode - get cached config
					const FServerRegionalClusterConfig& CachedRegionalConfig = ServerManagementSubsystem->GetRegionalConfig();
					UE_LOG(LogTemp, Log, TEXT("EchoesWorldGenerator: Found cached regional config with %d systems"), CachedRegionalConfig.Systems.Num());
					OnRegionalClusterConfigReceived(CachedRegionalConfig);
				}
				else
				{
					// Dedicated system mode - get cached config
					const FServerSystemConfig& CachedSystemConfig = ServerManagementSubsystem->GetSystemConfig();
					UE_LOG(LogTemp, Log, TEXT("EchoesWorldGenerator: Found cached system config for %s"), *CachedSystemConfig.SystemName);
					OnServerConfigReceived(CachedSystemConfig);
				}
			}
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("EchoesWorldGenerator: Failed to get ServerManagementSubsystem"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("EchoesWorldGenerator: GameInstance is null"));
	}
}

void AEchoesWorldGenerator::OnServerConfigReceived(const FServerSystemConfig& Config)
{
	if (!HasAuthority())
	{
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("╔══════════════════════════════════════════════════════════╗"));
	UE_LOG(LogTemp, Log, TEXT("║    ECHOES WORLD GENERATOR - SERVER CONFIG RECEIVED      ║"));
	UE_LOG(LogTemp, Log, TEXT("╚══════════════════════════════════════════════════════════╝"));
	UE_LOG(LogTemp, Log, TEXT("System: %s"), *Config.SystemName);
	UE_LOG(LogTemp, Log, TEXT("Star Class: %s"), *Config.StarClass);
	UE_LOG(LogTemp, Log, TEXT("Planets: %d"), Config.Planets.Num());
	UE_LOG(LogTemp, Log, TEXT("Stations: %d"), Config.Stations.Num());
	UE_LOG(LogTemp, Log, TEXT("Stargates: %d"), Config.Stargates.Num());
	UE_LOG(LogTemp, Log, TEXT("Asteroid Belts: %d"), Config.AsteroidBelts.Num());
	UE_LOG(LogTemp, Log, TEXT("Anomalies: %d"), Config.Anomalies.Num());
	UE_LOG(LogTemp, Log, TEXT("Wormholes: %d"), Config.Wormholes.Num());

	// Clear any existing world
	if (bWorldGenerated)
	{
		ServerOnly_ClearWorld();
	}

	// Generate the world
	ServerOnly_GenerateWorld(Config);

	bWorldGenerated = true;

	UE_LOG(LogTemp, Log, TEXT("╔══════════════════════════════════════════════════════════╗"));
	UE_LOG(LogTemp, Log, TEXT("║        WORLD GENERATION COMPLETE                        ║"));
	UE_LOG(LogTemp, Log, TEXT("╚══════════════════════════════════════════════════════════╝"));
}

void AEchoesWorldGenerator::OnRegionalClusterConfigReceived(const FServerRegionalClusterConfig& RegionalConfig)
{
	if (!HasAuthority())
	{
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("╔══════════════════════════════════════════════════════════╗"));
	UE_LOG(LogTemp, Log, TEXT("║   ECHOES WORLD GENERATOR - REGIONAL CLUSTER CONFIG      ║"));
	UE_LOG(LogTemp, Log, TEXT("╚══════════════════════════════════════════════════════════╝"));
	UE_LOG(LogTemp, Log, TEXT("Region: %s (%s)"), *RegionalConfig.RegionName, *RegionalConfig.RegionCode);
	UE_LOG(LogTemp, Log, TEXT("Systems: %d"), RegionalConfig.Systems.Num());
	UE_LOG(LogTemp, Log, TEXT("Total Planets: %d"), RegionalConfig.TotalPlanets);
	UE_LOG(LogTemp, Log, TEXT("Total Stargates: %d"), RegionalConfig.TotalStargates);
	UE_LOG(LogTemp, Log, TEXT("Total Stations: %d"), RegionalConfig.TotalStations);

	// Generate the regional cluster
	ServerOnly_GenerateRegionalCluster(RegionalConfig);

	bWorldGenerated = true;

	UE_LOG(LogTemp, Log, TEXT("╔══════════════════════════════════════════════════════════╗"));
	UE_LOG(LogTemp, Log, TEXT("║    REGIONAL CLUSTER GENERATION COMPLETE                 ║"));
	UE_LOG(LogTemp, Log, TEXT("╚══════════════════════════════════════════════════════════╝"));
}

void AEchoesWorldGenerator::ServerOnly_GenerateWorld(const FServerSystemConfig& Config)
{
	if (!HasAuthority())
	{
		UE_LOG(LogTemp, Warning, TEXT("ServerOnly_GenerateWorld called on client - ignoring"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Beginning world generation for system: %s"), *Config.SystemName);

	bIsRegionalCluster = false;

	// Generate single system at origin
	GenerateSingleSystem(Config, FVector::ZeroVector);

	UE_LOG(LogTemp, Log, TEXT("World generation completed. Total actors spawned: %d"), SpawnedActors.Num());
}

void AEchoesWorldGenerator::ServerOnly_GenerateRegionalCluster(const FServerRegionalClusterConfig& RegionalConfig)
{
	if (!HasAuthority())
	{
		UE_LOG(LogTemp, Warning, TEXT("ServerOnly_GenerateRegionalCluster called on client - ignoring"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Beginning regional cluster generation for region: %s"), *RegionalConfig.RegionName);

	bIsRegionalCluster = true;
	CachedRegionalConfig = RegionalConfig;

	// Clear system offsets map
	SystemOffsets.Empty();

	// Iterate through all systems in the region
	for (const FServerSystemConfig& SystemConfig : RegionalConfig.Systems)
	{
		// Calculate global offset for this system based on its DB coordinates
		FVector SystemOffset = CalculateSystemGlobalOffset(
			SystemConfig.PositionX,
			SystemConfig.PositionY,
			SystemConfig.PositionZ
		);

		// Store offset for later lookups (for stargate jumps)
		SystemOffsets.Add(SystemConfig.SystemId, SystemOffset);

		UE_LOG(LogTemp, Log, TEXT("╔══════════════════════════════════════════════════════════╗"));
		UE_LOG(LogTemp, Log, TEXT("║    GENERATING SYSTEM: %-35s║"), *SystemConfig.SystemName);
		UE_LOG(LogTemp, Log, TEXT("╚══════════════════════════════════════════════════════════╝"));
		UE_LOG(LogTemp, Log, TEXT("  DB Coordinates: [%lld, %lld, %lld]"), 
			SystemConfig.PositionX, SystemConfig.PositionY, SystemConfig.PositionZ);
		UE_LOG(LogTemp, Log, TEXT("  Global Offset: [%.0f, %.0f, %.0f]"), 
			SystemOffset.X, SystemOffset.Y, SystemOffset.Z);
		UE_LOG(LogTemp, Log, TEXT("  Planets: %d, Stations: %d, Stargates: %d"), 
			SystemConfig.Planets.Num(), SystemConfig.Stations.Num(), SystemConfig.Stargates.Num());

		// Generate this system at its calculated offset
		GenerateSingleSystem(SystemConfig, SystemOffset);
	}

	UE_LOG(LogTemp, Log, TEXT("Regional cluster generation completed. Total actors spawned: %d"), SpawnedActors.Num());
	UE_LOG(LogTemp, Log, TEXT("Systems generated: %d"), RegionalConfig.Systems.Num());
}

void AEchoesWorldGenerator::GenerateSingleSystem(const FServerSystemConfig& Config, const FVector& SystemOffset)
{
	if (!HasAuthority())
	{
		return;
	}

	// Optional: Async load assets before spawning (optimization)
	// AsyncLoadAssetsForConfig(Config);

	// Spawn star at system center (with offset)
	SpawnStar(Config, SystemOffset);

	// Spawn all objects in the system (with offset)
	SpawnPlanets(Config.Planets, SystemOffset);
	SpawnStations(Config.Stations, SystemOffset);
	SpawnStargates(Config.Stargates, SystemOffset);
	SpawnAsteroidBelts(Config.AsteroidBelts, SystemOffset);
	SpawnAnomalies(Config.Anomalies, SystemOffset);
	SpawnWormholes(Config.Wormholes, SystemOffset);
}

void AEchoesWorldGenerator::ServerOnly_ClearWorld()
{
	if (!HasAuthority())
	{
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Clearing world. Destroying %d actors"), SpawnedActors.Num());

	for (AActor* Actor : SpawnedActors)
	{
		if (Actor && IsValid(Actor))
		{
			Actor->Destroy();
		}
	}

	SpawnedActors.Empty();
	bWorldGenerated = false;
}

void AEchoesWorldGenerator::SpawnStar(const FServerSystemConfig& Config, const FVector& SystemOffset)
{
	UE_LOG(LogTemp, Log, TEXT("Spawning star: %s (Class: %s)"), *Config.SystemName, *Config.StarClass);

	// Star is at system offset (which is ZeroVector for single-system mode)
	FVector StarLocation = SystemOffset;
	FRotator StarRotation = FRotator::ZeroRotator;

	// Get visual data from data table
	FStarVisualRow* VisualData = GetStarVisualData(Config.StarClass);
	FStarVisualRow DefaultVisualData; // Stack allocation for default
	
	if (!VisualData)
	{
		UE_LOG(LogTemp, Warning, TEXT("No visual data found for star class: %s, using defaults"), *Config.StarClass);
		VisualData = &DefaultVisualData;
	}

	TSubclassOf<AStarActor> SpawnClass = StarActorClass;
	if (!VisualData->ActorClass.IsNull())
	{
		UClass* LoadedClass = VisualData->ActorClass.LoadSynchronous();
		if (LoadedClass && LoadedClass->IsChildOf(AStarActor::StaticClass()))
		{
			SpawnClass = LoadedClass;
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Star visual actor class is not a StarActor. Using default class."));
		}
	}

	if (!SpawnClass)
	{
		UE_LOG(LogTemp, Error, TEXT("StarActorClass is not set!"));
		return;
	}

	// Spawn parameters
	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	// Spawn star actor
	AStarActor* Star = GetWorld()->SpawnActor<AStarActor>(
		SpawnClass,
		StarLocation,
		StarRotation,
		SpawnParams);

	if (Star && IsValid(Star))
	{
		// Initialize star
		Star->InitializeStar(
			Config.StarClass,
			Config.Temperature,
			Config.Luminosity,
			Config.SolarRadius,
			*VisualData);

		SpawnedActors.Add(Star);

		UE_LOG(LogTemp, Log, TEXT("✓ Star spawned successfully at origin"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("✗ Failed to spawn star!"));
	}
}

void AEchoesWorldGenerator::SpawnPlanets(const TArray<FPlanetConfig>& Planets, const FVector& SystemOffset)
{
	UE_LOG(LogTemp, Log, TEXT("Spawning %d planets..."), Planets.Num());

	for (const FPlanetConfig& PlanetConfig : Planets)
	{
		// Get visual data from data table
		FPlanetVisualRow* VisualData = GetPlanetVisualData(PlanetConfig.Type);
		FPlanetVisualRow DefaultVisualData; // Stack allocation for default
		
		if (!VisualData)
		{
			UE_LOG(LogTemp, Warning, TEXT("No visual data found for planet type: %s, using defaults"), *PlanetConfig.Type);
			VisualData = &DefaultVisualData;
		}

		TSubclassOf<APlanetActor> SpawnClass = PlanetActorClass;
		if (!VisualData->ActorClass.IsNull())
		{
			UClass* LoadedClass = VisualData->ActorClass.LoadSynchronous();
			if (LoadedClass && LoadedClass->IsChildOf(APlanetActor::StaticClass()))
			{
				SpawnClass = LoadedClass;
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Planet visual actor class is not a PlanetActor. Using default class."));
			}
		}

		if (!SpawnClass)
		{
			UE_LOG(LogTemp, Error, TEXT("PlanetActorClass is not set!"));
			continue;
		}

		// Convert coordinates from km to Unreal units
		FVector PlanetLocation = SystemOffset + ConvertCoordinates(
			PlanetConfig.PositionX,
			PlanetConfig.PositionY,
			PlanetConfig.PositionZ);

		FRotator PlanetRotation = FRotator::ZeroRotator;

		// Spawn parameters
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

		// Spawn planet actor
		APlanetActor* Planet = GetWorld()->SpawnActor<APlanetActor>(
			SpawnClass,
			PlanetLocation,
			PlanetRotation,
			SpawnParams);

		if (Planet && IsValid(Planet))
		{
			// Generate seed from planet ID for variation
			int32 Seed = GenerateSeedFromGuid(PlanetConfig.Id);

			// Initialize planet
			Planet->InitializePlanet(
				PlanetConfig.Id,
				PlanetConfig.Name,
				PlanetConfig.Type,
				PlanetConfig.Radius,
				Seed,
				*VisualData);

			SpawnedActors.Add(Planet);

			UE_LOG(LogTemp, Log, TEXT("✓ Planet spawned: %s (Type: %s) at (%s)"),
				*PlanetConfig.Name, *PlanetConfig.Type, *PlanetLocation.ToString());
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("✗ Failed to spawn planet: %s"), *PlanetConfig.Name);
		}
	}
}

void AEchoesWorldGenerator::SpawnStations(const TArray<FStationConfig>& Stations, const FVector& SystemOffset)
{
	UE_LOG(LogTemp, Log, TEXT("Spawning %d stations..."), Stations.Num());

	for (const FStationConfig& StationConfig : Stations)
	{
		// Get visual data from data table
		FStationVisualRow* VisualData = GetStationVisualData(StationConfig.StationType);
		FStationVisualRow DefaultVisualData; // Stack allocation for default
		
		if (!VisualData)
		{
			UE_LOG(LogTemp, Warning, TEXT("No visual data found for station type: %s, using defaults"), *StationConfig.StationType);
			VisualData = &DefaultVisualData;
		}

		TSubclassOf<AStationActor> SpawnClass = StationActorClass;
		if (!VisualData->ActorClass.IsNull())
		{
			UClass* LoadedClass = VisualData->ActorClass.LoadSynchronous();
			if (LoadedClass && LoadedClass->IsChildOf(AStationActor::StaticClass()))
			{
				SpawnClass = LoadedClass;
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Station visual actor class is not a StationActor. Using default class."));
			}
		}

		if (!SpawnClass)
		{
			UE_LOG(LogTemp, Error, TEXT("StationActorClass is not set!"));
			continue;
		}

		// Convert coordinates
		FVector StationLocation = SystemOffset + ConvertCoordinates(
			StationConfig.PositionX,
			StationConfig.PositionY,
			StationConfig.PositionZ);

		FRotator StationRotation = FRotator::ZeroRotator;

		// Spawn parameters
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

		// Spawn station actor
		AStationActor* Station = GetWorld()->SpawnActor<AStationActor>(
			SpawnClass,
			StationLocation,
			StationRotation,
			SpawnParams);

		if (Station && IsValid(Station))
		{
			// Generate seed
			int32 Seed = GenerateSeedFromGuid(StationConfig.Id);

			// Initialize station
			Station->InitializeStation(
				StationConfig.Id,
				StationConfig.Name,
				StationConfig.StationType,
				Seed,
				*VisualData);

			SpawnedActors.Add(Station);

			UE_LOG(LogTemp, Log, TEXT("✓ Station spawned: %s (Type: %s) at (%s)"),
				*StationConfig.Name, *StationConfig.StationType, *StationLocation.ToString());
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("✗ Failed to spawn station: %s"), *StationConfig.Name);
		}
	}
}

void AEchoesWorldGenerator::SpawnStargates(const TArray<FStargateConfig>& Stargates, const FVector& SystemOffset)
{
	UE_LOG(LogTemp, Log, TEXT("Spawning %d stargates..."), Stargates.Num());

	for (const FStargateConfig& GateConfig : Stargates)
	{
		// Get visual data from data table
		FStargateVisualRow* VisualData = GetStargateVisualData(GateConfig.Model);
		FStargateVisualRow DefaultVisualData; // Stack allocation for default
		
		if (!VisualData)
		{
			UE_LOG(LogTemp, Warning, TEXT("No visual data found for stargate model: %s, using defaults"), *GateConfig.Model);
			VisualData = &DefaultVisualData;
		}

		TSubclassOf<AStargateActor> SpawnClass = StargateActorClass;
		if (!VisualData->ActorClass.IsNull())
		{
			UClass* LoadedClass = VisualData->ActorClass.LoadSynchronous();
			if (LoadedClass && LoadedClass->IsChildOf(AStargateActor::StaticClass()))
			{
				SpawnClass = LoadedClass;
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Stargate visual actor class is not a StargateActor. Using default class."));
			}
		}

		if (!SpawnClass)
		{
			UE_LOG(LogTemp, Error, TEXT("StargateActorClass is not set!"));
			continue;
		}

		// Convert coordinates
		FVector GateLocation = SystemOffset + ConvertCoordinates(
			static_cast<int64>(GateConfig.PositionX * 1000.0f), // Convert to km if in AU
			static_cast<int64>(GateConfig.PositionY * 1000.0f),
			static_cast<int64>(GateConfig.PositionZ * 1000.0f));

		FRotator GateRotation = FRotator::ZeroRotator;

		// Spawn parameters
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

		// Spawn stargate actor
		AStargateActor* Stargate = GetWorld()->SpawnActor<AStargateActor>(
			SpawnClass,
			GateLocation,
			GateRotation,
			SpawnParams);

		if (Stargate && IsValid(Stargate))
		{
			// Initialize stargate
			Stargate->InitializeStargate(
				GateConfig.Id,
				GateConfig.Name,
				GateConfig.TargetSystemId,
				GateConfig.TargetSystemName,
				GateConfig.IsOperational,
				*VisualData);

			SpawnedActors.Add(Stargate);

			UE_LOG(LogTemp, Log, TEXT("✓ Stargate spawned: %s -> %s at (%s)"),
				*GateConfig.Name, *GateConfig.TargetSystemName, *GateLocation.ToString());
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("✗ Failed to spawn stargate: %s"), *GateConfig.Name);
		}
	}
}

void AEchoesWorldGenerator::SpawnAsteroidBelts(const TArray<FAsteroidBeltConfig>& AsteroidBelts, const FVector& SystemOffset)
{
	UE_LOG(LogTemp, Log, TEXT("Spawning %d asteroid belts..."), AsteroidBelts.Num());

	for (const FAsteroidBeltConfig& BeltConfig : AsteroidBelts)
	{
		// Get visual data from data table
		FAsteroidBeltVisualRow* VisualData = GetAsteroidBeltVisualData(TEXT("Default"));
		FAsteroidBeltVisualRow DefaultVisualData;
		if (!VisualData)
		{
			UE_LOG(LogTemp, Warning, TEXT("No visual data found for asteroid belt, using defaults"));
			VisualData = &DefaultVisualData;
		}

		TSubclassOf<AAsteroidBeltActor> SpawnClass = AsteroidBeltActorClass;
		if (!VisualData->ActorClass.IsNull())
		{
			UClass* LoadedClass = VisualData->ActorClass.LoadSynchronous();
			if (LoadedClass && LoadedClass->IsChildOf(AAsteroidBeltActor::StaticClass()))
			{
				SpawnClass = LoadedClass;
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Asteroid belt visual actor class is not an AsteroidBeltActor. Using default class."));
			}
		}

		if (!SpawnClass)
		{
			UE_LOG(LogTemp, Error, TEXT("AsteroidBeltActorClass is not set!"));
			continue;
		}

		// Convert coordinates
		FVector BeltLocation = SystemOffset + ConvertCoordinates(
			BeltConfig.PositionX,
			BeltConfig.PositionY,
			BeltConfig.PositionZ);

		FRotator BeltRotation = FRotator::ZeroRotator;

		// Spawn parameters
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		// Spawn asteroid belt actor
		AAsteroidBeltActor* AsteroidBelt = GetWorld()->SpawnActor<AAsteroidBeltActor>(
			SpawnClass,
			BeltLocation,
			BeltRotation,
			SpawnParams);

		if (AsteroidBelt && IsValid(AsteroidBelt))
		{
			// Generate seed from belt ID
			int32 Seed = GenerateSeedFromGuid(BeltConfig.Id);

			// Calculate belt radius from database value or use default
			// Default: 100,000 km = 100,000,000 m in world space
			float BeltRadius = 100000.0f * UniverseToWorldScale * 100000.0f;

			// Initialize asteroid belt
			AsteroidBelt->InitializeAsteroidBelt(
				BeltConfig.Id,
				BeltConfig.Name,
				Seed,
				BeltRadius,
				1000, // Default asteroid count
				*VisualData);

			SpawnedActors.Add(AsteroidBelt);

			UE_LOG(LogTemp, Log, TEXT("✓ Asteroid Belt spawned: %s at (%s)"),
				*BeltConfig.Name, *BeltLocation.ToString());
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("✗ Failed to spawn asteroid belt: %s"), *BeltConfig.Name);
		}
	}
}

void AEchoesWorldGenerator::SpawnAnomalies(const TArray<FAnomalyConfig>& Anomalies, const FVector& SystemOffset)
{
	UE_LOG(LogTemp, Log, TEXT("Spawning %d anomalies..."), Anomalies.Num());

	for (const FAnomalyConfig& AnomalyConfig : Anomalies)
	{
		// Get visual data from data table based on anomaly type
		FAnomalyVisualRow* VisualData = GetAnomalyVisualData(AnomalyConfig.Type);
		FAnomalyVisualRow DefaultVisualData;
		if (!VisualData)
		{
			UE_LOG(LogTemp, Warning, TEXT("No visual data found for anomaly type: %s, using defaults"), *AnomalyConfig.Type);
			VisualData = &DefaultVisualData;
		}

		TSubclassOf<AAnomalyActor> SpawnClass = AnomalyActorClass;
		if (!VisualData->ActorClass.IsNull())
		{
			UClass* LoadedClass = VisualData->ActorClass.LoadSynchronous();
			if (LoadedClass && LoadedClass->IsChildOf(AAnomalyActor::StaticClass()))
			{
				SpawnClass = LoadedClass;
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Anomaly visual actor class is not an AnomalyActor. Using default class."));
			}
		}

		if (!SpawnClass)
		{
			UE_LOG(LogTemp, Error, TEXT("AnomalyActorClass is not set!"));
			continue;
		}

		// Convert coordinates
		FVector AnomalyLocation = SystemOffset + ConvertCoordinates(
			AnomalyConfig.PositionX,
			AnomalyConfig.PositionY,
			AnomalyConfig.PositionZ);

		FRotator AnomalyRotation = FRotator::ZeroRotator;

		// Spawn parameters
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		// Spawn anomaly actor
		AAnomalyActor* Anomaly = GetWorld()->SpawnActor<AAnomalyActor>(
			SpawnClass,
			AnomalyLocation,
			AnomalyRotation,
			SpawnParams);

		if (Anomaly && IsValid(Anomaly))
		{
			// Generate seed from anomaly ID
			int32 Seed = GenerateSeedFromGuid(AnomalyConfig.Id);

			// Initialize anomaly
			Anomaly->InitializeAnomaly(
				AnomalyConfig.Id,
				AnomalyConfig.Name,
				AnomalyConfig.Type,
				AnomalyConfig.Difficulty,
				Seed,
				*VisualData);

			SpawnedActors.Add(Anomaly);

			UE_LOG(LogTemp, Log, TEXT("✓ Anomaly spawned: %s (Type: %s, Difficulty: %s) at (%s)"),
				*AnomalyConfig.Name, *AnomalyConfig.Type, *AnomalyConfig.Difficulty, *AnomalyLocation.ToString());
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("✗ Failed to spawn anomaly: %s"), *AnomalyConfig.Name);
		}
	}
}

void AEchoesWorldGenerator::SpawnWormholes(const TArray<FWormholeConfig>& Wormholes, const FVector& SystemOffset)
{
	UE_LOG(LogTemp, Log, TEXT("Spawning %d wormholes..."), Wormholes.Num());

	for (const FWormholeConfig& WormholeConfig : Wormholes)
	{
		// Get visual data from data table
		FWormholeVisualRow* VisualData = GetWormholeVisualData(TEXT("Default"));
		FWormholeVisualRow DefaultVisualData;
		if (!VisualData)
		{
			UE_LOG(LogTemp, Warning, TEXT("No visual data found for wormhole, using defaults"));
			VisualData = &DefaultVisualData;
		}

		TSubclassOf<AWormholeActor> SpawnClass = WormholeActorClass;
		if (!VisualData->ActorClass.IsNull())
		{
			UClass* LoadedClass = VisualData->ActorClass.LoadSynchronous();
			if (LoadedClass && LoadedClass->IsChildOf(AWormholeActor::StaticClass()))
			{
				SpawnClass = LoadedClass;
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Wormhole visual actor class is not a WormholeActor. Using default class."));
			}
		}

		if (!SpawnClass)
		{
			UE_LOG(LogTemp, Error, TEXT("WormholeActorClass is not set!"));
			continue;
		}

		// Convert coordinates
		FVector WormholeLocation = SystemOffset + ConvertCoordinates(
			WormholeConfig.PositionX,
			WormholeConfig.PositionY,
			WormholeConfig.PositionZ);

		FRotator WormholeRotation = FRotator::ZeroRotator;

		// Spawn parameters
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		// Spawn wormhole actor
		AWormholeActor* Wormhole = GetWorld()->SpawnActor<AWormholeActor>(
			SpawnClass,
			WormholeLocation,
			WormholeRotation,
			SpawnParams);

		if (Wormhole && IsValid(Wormhole))
		{
			// Generate seed from wormhole ID
			int32 Seed = GenerateSeedFromGuid(WormholeConfig.Id);

			// Initialize wormhole
			Wormhole->InitializeWormhole(
				WormholeConfig.Id,
				WormholeConfig.Name,
				WormholeConfig.TargetSystemId,
				Seed,
				*VisualData);

			SpawnedActors.Add(Wormhole);

			UE_LOG(LogTemp, Log, TEXT("✓ Wormhole spawned: %s -> System %s at (%s)"),
				*WormholeConfig.Name, *WormholeConfig.TargetSystemId.ToString(), *WormholeLocation.ToString());
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("✗ Failed to spawn wormhole: %s"), *WormholeConfig.Name);
		}
	}
}

FVector AEchoesWorldGenerator::ConvertCoordinates(int64 X, int64 Y, int64 Z) const
{
	// Convert from km to Unreal Units (cm)
	// CRITICAL FIX: Use double precision to avoid jitter at large distances
	// UniverseToWorldScale is the scaling factor
	// Formula: km * UniverseToWorldScale * 100000 (km to cm conversion factor)
	// Example: 1 km * 0.0001 * 100000 = 10 cm (1:10,000,000 scale)
	
	// Convert to double first to maintain precision for large coordinates
	double WorldX = static_cast<double>(X) * static_cast<double>(UniverseToWorldScale) * 100000.0; // km to cm
	double WorldY = static_cast<double>(Y) * static_cast<double>(UniverseToWorldScale) * 100000.0;
	double WorldZ = static_cast<double>(Z) * static_cast<double>(UniverseToWorldScale) * 100000.0;

	// FVector supports double precision in UE5 (Large World Coordinates)
	return FVector(WorldX, WorldY, WorldZ);
}

FPlanetVisualRow* AEchoesWorldGenerator::GetPlanetVisualData(const FString& PlanetType)
{
	if (!PlanetDataTable)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlanetDataTable is not set!"));
		return nullptr;
	}

	// Look up row by planet type name
	FName RowName = FName(*PlanetType);
	FPlanetVisualRow* Row = PlanetDataTable->FindRow<FPlanetVisualRow>(RowName, TEXT("GetPlanetVisualData"));
	
	if (!Row)
	{
		// Try with "Default" row as fallback
		Row = PlanetDataTable->FindRow<FPlanetVisualRow>(FName(TEXT("Default")), TEXT("GetPlanetVisualData"));
	}

	return Row;
}

FStarVisualRow* AEchoesWorldGenerator::GetStarVisualData(const FString& StarClass)
{
	if (!StarDataTable)
	{
		UE_LOG(LogTemp, Warning, TEXT("StarDataTable is not set!"));
		return nullptr;
	}

	// Look up row by star class
	FName RowName = FName(*StarClass);
	FStarVisualRow* Row = StarDataTable->FindRow<FStarVisualRow>(RowName, TEXT("GetStarVisualData"));
	
	if (!Row)
	{
		// Try with "Default" row as fallback
		Row = StarDataTable->FindRow<FStarVisualRow>(FName(TEXT("Default")), TEXT("GetStarVisualData"));
	}

	return Row;
}

FStationVisualRow* AEchoesWorldGenerator::GetStationVisualData(const FString& StationType)
{
	if (!StationDataTable)
	{
		UE_LOG(LogTemp, Warning, TEXT("StationDataTable is not set!"));
		return nullptr;
	}

	FName RowName = FName(*StationType);
	FStationVisualRow* Row = StationDataTable->FindRow<FStationVisualRow>(RowName, TEXT("GetStationVisualData"));
	
	if (!Row)
	{
		Row = StationDataTable->FindRow<FStationVisualRow>(FName(TEXT("Default")), TEXT("GetStationVisualData"));
	}

	return Row;
}

FStargateVisualRow* AEchoesWorldGenerator::GetStargateVisualData(const FString& Model)
{
	if (!StargateDataTable)
	{
		UE_LOG(LogTemp, Warning, TEXT("StargateDataTable is not set!"));
		return nullptr;
	}

	FName RowName = FName(*Model);
	FStargateVisualRow* Row = StargateDataTable->FindRow<FStargateVisualRow>(RowName, TEXT("GetStargateVisualData"));
	
	if (!Row)
	{
		Row = StargateDataTable->FindRow<FStargateVisualRow>(FName(TEXT("Default")), TEXT("GetStargateVisualData"));
	}

	return Row;
}

int32 AEchoesWorldGenerator::GenerateSeedFromGuid(const FGuid& Guid) const
{
	// Convert GUID to a consistent integer seed
	// Use XOR of all 4 components for better distribution
	return Guid.A ^ Guid.B ^ Guid.C ^ Guid.D;
}

void AEchoesWorldGenerator::AsyncLoadAssetsForConfig(const FServerSystemConfig& Config)
{
	// TODO: Implement async asset loading with UStreamableManager
	// This would load all required assets before spawning actors
	// 
	// Example implementation:
	// TArray<FSoftObjectPath> AssetsToLoad;
	// 
	// // Collect all asset paths from data tables
	// for (const FPlanetConfig& Planet : Config.Planets)
	// {
	//     FPlanetVisualRow* VisualData = GetPlanetVisualData(Planet.Type);
	//     if (VisualData)
	//     {
	//         if (!VisualData->Mesh.IsNull())
	//             AssetsToLoad.Add(VisualData->Mesh.ToSoftObjectPath());
	//         // Add other assets...
	//     }
	// }
	// 
	// // Request async load
	// StreamableManager.RequestAsyncLoad(AssetsToLoad, FStreamableDelegate::CreateUObject(
	//     this, &AEchoesWorldGenerator::OnAssetsLoaded));

	UE_LOG(LogTemp, Verbose, TEXT("Async asset loading not yet implemented - using direct references"));
}

FAsteroidBeltVisualRow* AEchoesWorldGenerator::GetAsteroidBeltVisualData(const FString& BeltType)
{
	if (!AsteroidBeltDataTable)
	{
		UE_LOG(LogTemp, Warning, TEXT("AsteroidBeltDataTable is not set!"));
		return nullptr;
	}

	FName RowName = FName(*BeltType);
	FAsteroidBeltVisualRow* Row = AsteroidBeltDataTable->FindRow<FAsteroidBeltVisualRow>(RowName, TEXT("GetAsteroidBeltVisualData"));
	
	if (!Row)
	{
		Row = AsteroidBeltDataTable->FindRow<FAsteroidBeltVisualRow>(FName(TEXT("Default")), TEXT("GetAsteroidBeltVisualData"));
	}

	return Row;
}

FAnomalyVisualRow* AEchoesWorldGenerator::GetAnomalyVisualData(const FString& AnomalyType)
{
	if (!AnomalyDataTable)
	{
		UE_LOG(LogTemp, Warning, TEXT("AnomalyDataTable is not set!"));
		return nullptr;
	}

	FName RowName = FName(*AnomalyType);
	FAnomalyVisualRow* Row = AnomalyDataTable->FindRow<FAnomalyVisualRow>(RowName, TEXT("GetAnomalyVisualData"));
	
	if (!Row)
	{
		Row = AnomalyDataTable->FindRow<FAnomalyVisualRow>(FName(TEXT("Default")), TEXT("GetAnomalyVisualData"));
	}

	return Row;
}

FWormholeVisualRow* AEchoesWorldGenerator::GetWormholeVisualData(const FString& WormholeClass)
{
	if (!WormholeDataTable)
	{
		UE_LOG(LogTemp, Warning, TEXT("WormholeDataTable is not set!"));
		return nullptr;
	}

	FName RowName = FName(*WormholeClass);
	FWormholeVisualRow* Row = WormholeDataTable->FindRow<FWormholeVisualRow>(RowName, TEXT("GetWormholeVisualData"));
	
	if (!Row)
	{
		Row = WormholeDataTable->FindRow<FWormholeVisualRow>(FName(TEXT("Default")), TEXT("GetWormholeVisualData"));
	}

	return Row;
}

// ==================== Regional Cluster Helpers ====================

FVector AEchoesWorldGenerator::CalculateSystemGlobalOffset(int64 PosX, int64 PosY, int64 PosZ) const
{
	// Convert DB coordinates to world coordinates using RegionDistanceScale
	// Uses double precision to handle large distances (LWC support)
	double OffsetX = static_cast<double>(PosX) * RegionDistanceScale;
	double OffsetY = static_cast<double>(PosY) * RegionDistanceScale;
	double OffsetZ = static_cast<double>(PosZ) * RegionDistanceScale;

	return FVector(OffsetX, OffsetY, OffsetZ);
}

bool AEchoesWorldGenerator::IsSystemOnThisServer(const FGuid& SystemId) const
{
	if (!bIsRegionalCluster)
	{
		// Single system mode - check against current system
		return false; // TODO: Compare with current system ID
	}

	// Regional cluster mode - check if system is in our cached config
	return SystemOffsets.Contains(SystemId);
}

FVector AEchoesWorldGenerator::GetSystemGlobalOffset(const FGuid& SystemId) const
{
	const FVector* Offset = SystemOffsets.Find(SystemId);
	if (Offset)
	{
		return *Offset;
	}

	UE_LOG(LogTemp, Warning, TEXT("System ID not found in SystemOffsets map: %s"), *SystemId.ToString());
	return FVector::ZeroVector;
}
