// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesWorldGenerator.h"
#include "Core/Server/EchoesServerManagementSubsystem.h"
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
			// Subscribe to OnServerConfigReceived delegate
			ServerManagementSubsystem->OnServerConfigReceived.AddDynamic(
				this,
				&AEchoesWorldGenerator::OnServerConfigReceived);

			UE_LOG(LogTemp, Log, TEXT("EchoesWorldGenerator: Successfully subscribed to OnServerConfigReceived"));
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

void AEchoesWorldGenerator::ServerOnly_GenerateWorld(const FServerSystemConfig& Config)
{
	if (!HasAuthority())
	{
		UE_LOG(LogTemp, Warning, TEXT("ServerOnly_GenerateWorld called on client - ignoring"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Beginning world generation for system: %s"), *Config.SystemName);

	// Optional: Async load assets before spawning (optimization)
	// AsyncLoadAssetsForConfig(Config);

	// Spawn star at system center
	SpawnStar(Config);

	// Spawn all planets
	SpawnPlanets(Config.Planets);

	// Spawn all stations
	SpawnStations(Config.Stations);

	// Spawn all stargates
	SpawnStargates(Config.Stargates);

	// Spawn all asteroid belts
	SpawnAsteroidBelts(Config.AsteroidBelts);

	// Spawn all anomalies
	SpawnAnomalies(Config.Anomalies);

	// Spawn all wormholes
	SpawnWormholes(Config.Wormholes);

	UE_LOG(LogTemp, Log, TEXT("World generation completed. Total actors spawned: %d"), SpawnedActors.Num());
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

void AEchoesWorldGenerator::SpawnStar(const FServerSystemConfig& Config)
{
	if (!StarActorClass)
	{
		UE_LOG(LogTemp, Error, TEXT("StarActorClass is not set!"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Spawning star: %s (Class: %s)"), *Config.SystemName, *Config.StarClass);

	// Star is always at origin (0,0,0)
	FVector StarLocation = FVector::ZeroVector;
	FRotator StarRotation = FRotator::ZeroRotator;

	// Spawn parameters
	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	// Spawn star actor
	AStarActor* Star = GetWorld()->SpawnActor<AStarActor>(
		StarActorClass,
		StarLocation,
		StarRotation,
		SpawnParams);

	if (Star)
	{
		// Get visual data from data table
		FStarVisualRow* VisualData = GetStarVisualData(Config.StarClass);
		if (!VisualData)
		{
			UE_LOG(LogTemp, Warning, TEXT("No visual data found for star class: %s"), *Config.StarClass);
			// Use default visual data
			VisualData = new FStarVisualRow();
		}

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

void AEchoesWorldGenerator::SpawnPlanets(const TArray<FPlanetConfig>& Planets)
{
	if (!PlanetActorClass)
	{
		UE_LOG(LogTemp, Error, TEXT("PlanetActorClass is not set!"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Spawning %d planets..."), Planets.Num());

	for (const FPlanetConfig& PlanetConfig : Planets)
	{
		// Convert coordinates from km to Unreal units
		FVector PlanetLocation = ConvertCoordinates(
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
			PlanetActorClass,
			PlanetLocation,
			PlanetRotation,
			SpawnParams);

		if (Planet)
		{
			// Get visual data from data table
			FPlanetVisualRow* VisualData = GetPlanetVisualData(PlanetConfig.Type);
			if (!VisualData)
			{
				UE_LOG(LogTemp, Warning, TEXT("No visual data found for planet type: %s"), *PlanetConfig.Type);
				VisualData = new FPlanetVisualRow();
			}

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

void AEchoesWorldGenerator::SpawnStations(const TArray<FStationConfig>& Stations)
{
	if (!StationActorClass)
	{
		UE_LOG(LogTemp, Error, TEXT("StationActorClass is not set!"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Spawning %d stations..."), Stations.Num());

	for (const FStationConfig& StationConfig : Stations)
	{
		// Convert coordinates
		FVector StationLocation = ConvertCoordinates(
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
			StationActorClass,
			StationLocation,
			StationRotation,
			SpawnParams);

		if (Station)
		{
			// Get visual data from data table
			FStationVisualRow* VisualData = GetStationVisualData(StationConfig.StationType);
			if (!VisualData)
			{
				UE_LOG(LogTemp, Warning, TEXT("No visual data found for station type: %s"), *StationConfig.StationType);
				VisualData = new FStationVisualRow();
			}

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

void AEchoesWorldGenerator::SpawnStargates(const TArray<FStargateConfig>& Stargates)
{
	if (!StargateActorClass)
	{
		UE_LOG(LogTemp, Error, TEXT("StargateActorClass is not set!"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Spawning %d stargates..."), Stargates.Num());

	for (const FStargateConfig& GateConfig : Stargates)
	{
		// Convert coordinates
		FVector GateLocation = ConvertCoordinates(
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
			StargateActorClass,
			GateLocation,
			GateRotation,
			SpawnParams);

		if (Stargate)
		{
			// Get visual data from data table
			FStargateVisualRow* VisualData = GetStargateVisualData(GateConfig.Model);
			if (!VisualData)
			{
				UE_LOG(LogTemp, Warning, TEXT("No visual data found for stargate model: %s"), *GateConfig.Model);
				VisualData = new FStargateVisualRow();
			}

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

FVector AEchoesWorldGenerator::ConvertCoordinates(int64 X, int64 Y, int64 Z) const
{
	// Convert from km to Unreal Units (cm)
	// UniverseToWorldScale is the scaling factor
	// Example: 1 km = 0.1 cm (1:1,000,000 scale)
	
	float WorldX = static_cast<float>(X) * UniverseToWorldScale * 100000.0f; // km to cm
	float WorldY = static_cast<float>(Y) * UniverseToWorldScale * 100000.0f;
	float WorldZ = static_cast<float>(Z) * UniverseToWorldScale * 100000.0f;

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

void AEchoesWorldGenerator::SpawnAsteroidBelts(const TArray<FAsteroidBeltConfig>& AsteroidBelts)
{
	if (!AsteroidBeltActorClass)
	{
		UE_LOG(LogTemp, Error, TEXT("AsteroidBeltActorClass is not set!"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Spawning %d asteroid belts..."), AsteroidBelts.Num());

	for (const FAsteroidBeltConfig& BeltConfig : AsteroidBelts)
	{
		// Convert coordinates
		FVector BeltLocation = ConvertCoordinates(
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
			AsteroidBeltActorClass,
			BeltLocation,
			BeltRotation,
			SpawnParams);

		if (AsteroidBelt)
		{
			// Get visual data from data table
			FAsteroidBeltVisualRow* VisualData = GetAsteroidBeltVisualData(TEXT("Default"));
			FAsteroidBeltVisualRow DefaultVisualData;
			if (!VisualData)
			{
				UE_LOG(LogTemp, Warning, TEXT("No visual data found for asteroid belt, using defaults"));
				VisualData = &DefaultVisualData;
			}

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

void AEchoesWorldGenerator::SpawnAnomalies(const TArray<FAnomalyConfig>& Anomalies)
{
	if (!AnomalyActorClass)
	{
		UE_LOG(LogTemp, Error, TEXT("AnomalyActorClass is not set!"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Spawning %d anomalies..."), Anomalies.Num());

	for (const FAnomalyConfig& AnomalyConfig : Anomalies)
	{
		// Convert coordinates
		FVector AnomalyLocation = ConvertCoordinates(
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
			AnomalyActorClass,
			AnomalyLocation,
			AnomalyRotation,
			SpawnParams);

		if (Anomaly)
		{
			// Get visual data from data table based on anomaly type
			FAnomalyVisualRow* VisualData = GetAnomalyVisualData(AnomalyConfig.Type);
			FAnomalyVisualRow DefaultVisualData;
			if (!VisualData)
			{
				UE_LOG(LogTemp, Warning, TEXT("No visual data found for anomaly type: %s, using defaults"), *AnomalyConfig.Type);
				VisualData = &DefaultVisualData;
			}

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

void AEchoesWorldGenerator::SpawnWormholes(const TArray<FWormholeConfig>& Wormholes)
{
	if (!WormholeActorClass)
	{
		UE_LOG(LogTemp, Error, TEXT("WormholeActorClass is not set!"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Spawning %d wormholes..."), Wormholes.Num());

	for (const FWormholeConfig& WormholeConfig : Wormholes)
	{
		// Convert coordinates
		FVector WormholeLocation = ConvertCoordinates(
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
			WormholeActorClass,
			WormholeLocation,
			WormholeRotation,
			SpawnParams);

		if (Wormhole)
		{
			// Get visual data from data table
			FWormholeVisualRow* VisualData = GetWormholeVisualData(TEXT("Default"));
			FWormholeVisualRow DefaultVisualData;
			if (!VisualData)
			{
				UE_LOG(LogTemp, Warning, TEXT("No visual data found for wormhole, using defaults"));
				VisualData = &DefaultVisualData;
			}

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
