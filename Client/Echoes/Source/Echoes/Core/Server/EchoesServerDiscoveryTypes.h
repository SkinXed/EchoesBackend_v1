// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EchoesServerDiscoveryTypes.generated.h"

/**
 * Server registration request (mirrors C# RegisterServerRequestDto)
 */
USTRUCT(BlueprintType)
struct FRegisterServerRequest
{
	GENERATED_BODY()

	/** Unique identifier for this server instance (GUID) */
	UPROPERTY(BlueprintReadWrite, Category = "Server")
	FString InstanceId;

	/** Public IP address where the game server can be reached by clients */
	UPROPERTY(BlueprintReadWrite, Category = "Server")
	FString PublicIP = TEXT("127.0.0.1");

	/** Port number for game client connections */
	UPROPERTY(BlueprintReadWrite, Category = "Server")
	int32 GamePort = 7777;

	/** Port number for web/API connections to the game server */
	UPROPERTY(BlueprintReadWrite, Category = "Server")
	int32 WebPort = 7778;

	/** Optional: Solar System ID if this is a dedicated server for a specific system */
	UPROPERTY(BlueprintReadWrite, Category = "Server")
	FGuid SolarSystemId;

	/** Optional: Region ID if this is a regional cluster server handling multiple systems */
	UPROPERTY(BlueprintReadWrite, Category = "Server")
	FGuid RegionId;

	/** Node type: "DedicatedSystem" or "RegionalCluster" */
	UPROPERTY(BlueprintReadWrite, Category = "Server")
	FString ServerType;

	/** Maximum number of concurrent players this server can handle */
	UPROPERTY(BlueprintReadWrite, Category = "Server")
	int32 MaxPlayers = 100;

	/** Geographic region code for this server (e.g., "EU", "US", "ASIA") */
	UPROPERTY(BlueprintReadWrite, Category = "Server")
	FString GeoRegion = TEXT("EU");

	/** Game version running on this server */
	UPROPERTY(BlueprintReadWrite, Category = "Server")
	FString GameVersion = TEXT("1.0.0");

	/** Hostname of the machine running the server */
	UPROPERTY(BlueprintReadWrite, Category = "Server")
	FString Hostname;

	/** Comma-separated tags for server filtering and categorization */
	UPROPERTY(BlueprintReadWrite, Category = "Server")
	FString ServerTags;
};

/**
 * Server registration response (mirrors C# RegisterServerResponseDto)
 */
USTRUCT(BlueprintType)
struct FRegisterServerResponse
{
	GENERATED_BODY()

	/** Whether registration was successful */
	UPROPERTY(BlueprintReadWrite, Category = "Server")
	bool Success = false;

	/** Unique server ID assigned by backend */
	UPROPERTY(BlueprintReadWrite, Category = "Server")
	FGuid ServerId;

	/** Instance ID that was registered */
	UPROPERTY(BlueprintReadWrite, Category = "Server")
	FString InstanceId;

	/** Node type: "DedicatedSystem" or "RegionalCluster" */
	UPROPERTY(BlueprintReadWrite, Category = "Server")
	FString NodeType;

	/** Response message from backend */
	UPROPERTY(BlueprintReadWrite, Category = "Server")
	FString Message;
};

/**
 * Heartbeat request (mirrors C# HeartbeatRequestDto)
 */
USTRUCT(BlueprintType)
struct FHeartbeatRequest
{
	GENERATED_BODY()

	/** Unique identifier of the server instance sending the heartbeat */
	UPROPERTY(BlueprintReadWrite, Category = "Server")
	FString InstanceId;

	/** Current operational status of the game server (0=Starting, 1=Ready, 2=Stopping, 3=Error) */
	UPROPERTY(BlueprintReadWrite, Category = "Server")
	int32 Status = 1;

	/** Number of players currently connected to the server */
	UPROPERTY(BlueprintReadWrite, Category = "Server")
	int32 OnlinePlayers = 0;

	/** Current CPU usage percentage (0-100) */
	UPROPERTY(BlueprintReadWrite, Category = "Server")
	float CPUUsage = 0.0f;

	/** Current memory usage in megabytes */
	UPROPERTY(BlueprintReadWrite, Category = "Server")
	int64 MemoryUsageMB = 0;

	/** Incoming network traffic in kilobits per second */
	UPROPERTY(BlueprintReadWrite, Category = "Server")
	float NetworkInKbps = 0.0f;

	/** Outgoing network traffic in kilobits per second */
	UPROPERTY(BlueprintReadWrite, Category = "Server")
	float NetworkOutKbps = 0.0f;
};

/**
 * Heartbeat response (mirrors C# HeartbeatResponseDto)
 */
USTRUCT(BlueprintType)
struct FHeartbeatResponse
{
	GENERATED_BODY()

	/** Whether heartbeat was successful */
	UPROPERTY(BlueprintReadWrite, Category = "Server")
	bool Success = false;

	/** Timestamp of heartbeat acknowledgment */
	UPROPERTY(BlueprintReadWrite, Category = "Server")
	FDateTime Timestamp;

	/** Seconds until next heartbeat should be sent */
	UPROPERTY(BlueprintReadWrite, Category = "Server")
	int32 NextHeartbeatInSeconds = 30;
};

/**
 * Resource configuration (mirrors C# ResourceConfigDto)
 */
USTRUCT(BlueprintType)
struct FResourceConfig
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	FGuid Id;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	FString ResourceType;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	int32 Quantity = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	float Richness = 0.0f;
};

/**
 * Moon configuration (mirrors C# MoonConfigDto)
 */
USTRUCT(BlueprintType)
struct FMoonConfig
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	FGuid Id;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	FString Name;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	int64 Radius = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	int64 PositionX = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	int64 PositionY = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	int64 PositionZ = 0;
};

/**
 * Planet configuration (mirrors C# PlanetConfigDto)
 */
USTRUCT(BlueprintType)
struct FPlanetConfig
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	FGuid Id;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	FString Name;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	FString Type;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	float OrbitDistance = 0.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	float Radius = 0.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	int64 PositionX = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	int64 PositionY = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	int64 PositionZ = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	TArray<FMoonConfig> Moons;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	TArray<FResourceConfig> Resources;
};

/**
 * Stargate configuration (mirrors C# StargateConfigDto)
 */
USTRUCT(BlueprintType)
struct FStargateConfig
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	FGuid Id;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	FString Name;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	FGuid TargetSystemId;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	FString TargetSystemName;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	float PositionX = 0.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	float PositionY = 0.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	float PositionZ = 0.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	bool IsOperational = true;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	int32 JumpCost = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	FString Model;
};

/**
 * Station configuration (mirrors C# StationConfigDto)
 */
USTRUCT(BlueprintType)
struct FStationConfig
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	FGuid Id;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	FString Name;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	int64 PositionX = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	int64 PositionY = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	int64 PositionZ = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	FString StationType;
};

/**
 * Asteroid belt configuration (mirrors C# AsteroidBeltConfigDto)
 */
USTRUCT(BlueprintType)
struct FAsteroidBeltConfig
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	FGuid Id;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	FString Name;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	int64 PositionX = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	int64 PositionY = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	int64 PositionZ = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	TArray<FResourceConfig> Resources;
};

/**
 * Anomaly configuration (mirrors C# AnomalyConfigDto)
 */
USTRUCT(BlueprintType)
struct FAnomalyConfig
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	FGuid Id;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	FString Name;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	FString Type;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	FString Difficulty;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	int64 PositionX = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	int64 PositionY = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	int64 PositionZ = 0;
};

/**
 * Wormhole configuration (mirrors C# WormholeConfigDto)
 */
USTRUCT(BlueprintType)
struct FWormholeConfig
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	FGuid Id;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	FString Name;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	FGuid TargetSystemId;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	int64 PositionX = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	int64 PositionY = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	int64 PositionZ = 0;
};

/**
 * Solar system configuration (mirrors C# ServerSystemConfigDto)
 */
USTRUCT(BlueprintType)
struct FServerSystemConfig
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	FGuid SystemId;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	FString SystemName;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	float SolarRadius = 0.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	float SolarMass = 0.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	float Temperature = 0.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	float Luminosity = 0.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	float SecurityStatus = 0.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	FString StarClass;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	FGuid ConstellationId;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	FString ConstellationName;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	FGuid RegionId;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	FString RegionName;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	int64 PositionX = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	int64 PositionY = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	int64 PositionZ = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	TArray<FPlanetConfig> Planets;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	TArray<FStargateConfig> Stargates;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	TArray<FStationConfig> Stations;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	TArray<FAsteroidBeltConfig> AsteroidBelts;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	TArray<FAnomalyConfig> Anomalies;

	UPROPERTY(BlueprintReadWrite, Category = "Universe")
	TArray<FWormholeConfig> Wormholes;
};

/**
 * Regional cluster configuration (mirrors C# ServerRegionalClusterConfigDto)
 * Contains all solar systems within a region for multi-system servers
 */
USTRUCT(BlueprintType)
struct FServerRegionalClusterConfig
{
	GENERATED_BODY()

	/** Unique identifier of the region */
	UPROPERTY(BlueprintReadWrite, Category = "Region")
	FGuid RegionId;

	/** Name of the region */
	UPROPERTY(BlueprintReadWrite, Category = "Region")
	FString RegionName;

	/** Region code identifier */
	UPROPERTY(BlueprintReadWrite, Category = "Region")
	FString RegionCode;

	/** Average security status across the region */
	UPROPERTY(BlueprintReadWrite, Category = "Region")
	float AverageSecurity = 0.0f;

	/** Number of constellations in this region */
	UPROPERTY(BlueprintReadWrite, Category = "Region")
	int32 ConstellationCount = 0;

	/** Number of solar systems in this region */
	UPROPERTY(BlueprintReadWrite, Category = "Region")
	int32 SystemCount = 0;

	/** Total number of planets across all systems in the region */
	UPROPERTY(BlueprintReadWrite, Category = "Region")
	int32 TotalPlanets = 0;

	/** Total number of stargates across all systems in the region */
	UPROPERTY(BlueprintReadWrite, Category = "Region")
	int32 TotalStargates = 0;

	/** Total number of stations across all systems in the region */
	UPROPERTY(BlueprintReadWrite, Category = "Region")
	int32 TotalStations = 0;

	/** List of all solar systems in this region */
	UPROPERTY(BlueprintReadWrite, Category = "Region")
	TArray<FServerSystemConfig> Systems;
};

/**
 * Server configuration request (mirrors C# ServerConfigRequestDto)
 */
USTRUCT(BlueprintType)
struct FServerConfigRequest
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Server")
	FString InstanceId;

	UPROPERTY(BlueprintReadWrite, Category = "Server")
	FString ServerType;

	UPROPERTY(BlueprintReadWrite, Category = "Server")
	FString SolarSystemId;

	UPROPERTY(BlueprintReadWrite, Category = "Server")
	FGuid RegionId;

	UPROPERTY(BlueprintReadWrite, Category = "Server")
	FString ClusterId;

	UPROPERTY(BlueprintReadWrite, Category = "Server")
	FString GeoRegion;
};

/**
 * Server configuration response wrapper (mirrors C# ServerConfigResponseDto)
 */
USTRUCT(BlueprintType)
struct FServerConfigResponse
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Server")
	FServerSystemConfig Config;
};

/**
 * Regional cluster configuration response wrapper (mirrors C# ServerRegionalClusterConfigResponseDto)
 */
USTRUCT(BlueprintType)
struct FServerRegionalClusterConfigResponse
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Server")
	FServerRegionalClusterConfig Config;
};
