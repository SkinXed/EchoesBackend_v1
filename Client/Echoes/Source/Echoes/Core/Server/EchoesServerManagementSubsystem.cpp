// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesServerManagementSubsystem.h"
#include "HttpModule.h"
#include "Interfaces/IHttpResponse.h"
#include "Json.h"
#include "JsonUtilities.h"
#include "Misc/ConfigCacheIni.h"
#include "HAL/PlatformProcess.h"
#include "HAL/PlatformMemory.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "GameFramework/GameModeBase.h"
#include "TimerManager.h"

// Define custom log category
DEFINE_LOG_CATEGORY(LogEchoesServer);

void UEchoesServerManagementSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	// Get HTTP module
	Http = &FHttpModule::Get();

	UE_LOG(LogEchoesServer, Log, TEXT("EchoesServerManagementSubsystem initialized"));

	// Only proceed if this is a dedicated server
	if (!IsDedicatedServer())
	{
		UE_LOG(LogEchoesServer, Warning, TEXT("Not a dedicated server, skipping server registration"));
		return;
	}

	// Generate unique instance ID if not set
	if (ServerInstanceId.IsEmpty())
	{
		ServerInstanceId = FGuid::NewGuid().ToString();
		UE_LOG(LogEchoesServer, Log, TEXT("Generated new InstanceId: %s"), *ServerInstanceId);
	}

	// ==================== Parse Command Line Parameters ====================
	
	// Get server type from command line (default: DedicatedSystem)
	ServerType = TEXT("DedicatedSystem");
	FString CommandLineServerType;
	if (FParse::Value(FCommandLine::Get(), TEXT("ServerType="), CommandLineServerType))
	{
		ServerType = CommandLineServerType;
		UE_LOG(LogEchoesServer, Log, TEXT("Using ServerType from command line: %s"), *ServerType);
	}

	// Get region ID from command line (for RegionalCluster mode)
	FString RegionIdStr;
	if (FParse::Value(FCommandLine::Get(), TEXT("RegionId="), RegionIdStr))
	{
		FGuid::Parse(RegionIdStr, CurrentRegionId);
		UE_LOG(LogEchoesServer, Log, TEXT("Using RegionId from command line: %s"), *RegionIdStr);
		
		// If RegionId is provided, force RegionalCluster mode
		if (CurrentRegionId.IsValid())
		{
			ServerType = TEXT("RegionalCluster");
			UE_LOG(LogEchoesServer, Log, TEXT("Switching to RegionalCluster mode due to RegionId parameter"));
		}
	}

	// Get solar system ID from command line (for DedicatedSystem mode)
	FString SystemIdStr;
	FGuid SystemId;
	if (FParse::Value(FCommandLine::Get(), TEXT("SystemId="), SystemIdStr))
	{
		FGuid::Parse(SystemIdStr, SystemId);
		CurrentSolarSystemId = SystemId;
		UE_LOG(LogEchoesServer, Log, TEXT("Using SolarSystemId from command line: %s"), *SystemIdStr);
	}

	// Get game port from command line or use default
	int32 Port = 7777;
	FParse::Value(FCommandLine::Get(), TEXT("Port="), Port);
	GamePort = Port;

	// Log configuration
	UE_LOG(LogEchoesServer, Log, TEXT("╔══════════════════════════════════════════════════════════╗"));
	UE_LOG(LogEchoesServer, Log, TEXT("║    SERVER CONFIGURATION                                  ║"));
	UE_LOG(LogEchoesServer, Log, TEXT("╚══════════════════════════════════════════════════════════╝"));
	UE_LOG(LogEchoesServer, Log, TEXT("Server Type: %s"), *ServerType);
	UE_LOG(LogEchoesServer, Log, TEXT("Instance ID: %s"), *ServerInstanceId);
	UE_LOG(LogEchoesServer, Log, TEXT("Game Port: %d"), GamePort);
	
	if (IsRegionalCluster())
	{
		UE_LOG(LogEchoesServer, Log, TEXT("Region ID: %s"), *CurrentRegionId.ToString());
	}
	else
	{
		UE_LOG(LogEchoesServer, Log, TEXT("Solar System ID: %s"), *SystemId.ToString());
	}

	// Register with backend
	ServerOnly_Register(ServerInstanceId, Port, SystemId);
}

void UEchoesServerManagementSubsystem::Deinitialize()
{
	Super::Deinitialize();

	// Stop heartbeat timer
	ServerOnly_StopHeartbeat();

	// Gracefully unregister from backend
	if (bIsRegistered)
	{
		ServerOnly_Unregister();
	}

	// Clear state
	bIsRegistered = false;
	ServerInstanceId.Empty();
	ServerId = FGuid();

	UE_LOG(LogEchoesServer, Log, TEXT("EchoesServerManagementSubsystem deinitialized"));
}

// ==================== Server Registration ====================

void UEchoesServerManagementSubsystem::ServerOnly_Register(
	const FString& InstanceId,
	int32 GamePort,
	const FGuid& SolarSystemId)
{
	if (!IsDedicatedServer())
	{
		UE_LOG(LogEchoesServer, Warning, TEXT("ServerOnly_Register called on non-dedicated server"));
		return;
	}

	if (!Http)
	{
		UE_LOG(LogEchoesServer, Error, TEXT("HTTP module not available"));
		return;
	}

	// Validate server secret is configured
	FString Secret = GetServerSecret();
	if (Secret.IsEmpty())
	{
		UE_LOG(LogEchoesServer, Error, TEXT("Cannot register: ServerSecret not configured in DefaultGame.ini"));
		return;
	}

	// Store parameters
	ServerInstanceId = InstanceId;
	this->GamePort = GamePort;
	CurrentSolarSystemId = SolarSystemId;

	UE_LOG(LogEchoesServer, Log, TEXT("Starting server registration handshake..."));
	UE_LOG(LogEchoesServer, Log, TEXT("  InstanceId: %s"), *InstanceId);
	UE_LOG(LogEchoesServer, Log, TEXT("  GamePort: %d"), GamePort);
	UE_LOG(LogEchoesServer, Log, TEXT("  ServerType: %s"), *ServerType);
	
	if (IsRegionalCluster())
	{
		UE_LOG(LogEchoesServer, Log, TEXT("  RegionId: %s"), *CurrentRegionId.ToString());
	}
	else
	{
		UE_LOG(LogEchoesServer, Log, TEXT("  SolarSystemId: %s"), *SolarSystemId.ToString());
	}

	// Create registration request
	FRegisterServerRequest Request;
	Request.InstanceId = InstanceId;
	
	// Get public IP address
	// TODO: Implement proper public IP detection (query external service or use UPnP)
	// For now, use localhost for development/testing
	Request.PublicIP = TEXT("127.0.0.1");
	
	Request.GamePort = GamePort;
	Request.WebPort = GamePort + 1; // TODO: Make WebPort independently configurable
	Request.MaxPlayers = 100;
	Request.GameVersion = TEXT("1.0.0");

	// Set mode-specific parameters
	if (IsRegionalCluster())
	{
		Request.RegionId = CurrentRegionId;
		Request.ServerType = TEXT("RegionalCluster");
	}
	else
	{
		Request.SolarSystemId = SolarSystemId;
		Request.ServerType = TEXT("DedicatedSystem");
	}

	// Get hostname
	Request.Hostname = FPlatformProcess::ComputerName();

	// Convert to JSON
	FString JsonString;
	if (!FJsonObjectConverter::UStructToJsonObjectString(Request, JsonString))
	{
		UE_LOG(LogEchoesServer, Error, TEXT("Failed to serialize registration request"));
		return;
	}

	// Create HTTP request
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = 
		CreateAuthenticatedRequest(TEXT("POST"), TEXT("/api/server-management/register"));
	HttpRequest->SetContentAsString(JsonString);

	// Bind response handler
	HttpRequest->OnProcessRequestComplete().BindUObject(
		this,
		&UEchoesServerManagementSubsystem::OnRegisterResponseReceived);

	// Send request
	if (!HttpRequest->ProcessRequest())
	{
		UE_LOG(LogEchoesServer, Error, TEXT("Failed to process registration request"));
	}
	else
	{
		UE_LOG(LogEchoesServer, Log, TEXT("Registration request sent to: %s"), *HttpRequest->GetURL());
	}
}

void UEchoesServerManagementSubsystem::ServerOnly_Heartbeat()
{
	if (!IsDedicatedServer() || !bIsRegistered)
	{
		return;
	}

	if (!Http)
	{
		UE_LOG(LogEchoesServer, Error, TEXT("HTTP module not available"));
		return;
	}

	// Collect metrics
	float CPUUsage = 0.0f;
	int64 MemoryUsageMB = 0;
	int32 PlayersCount = 0;
	CollectServerMetrics(CPUUsage, MemoryUsageMB, PlayersCount);

	// Create heartbeat request
	FHeartbeatRequest Request;
	Request.InstanceId = ServerInstanceId;
	Request.Status = 1; // Ready
	Request.OnlinePlayers = PlayersCount;
	Request.CPUUsage = CPUUsage;
	Request.MemoryUsageMB = MemoryUsageMB;
	Request.NetworkInKbps = 0.0f; // TODO: Implement network monitoring
	Request.NetworkOutKbps = 0.0f;

	// Convert to JSON
	FString JsonString;
	if (!FJsonObjectConverter::UStructToJsonObjectString(Request, JsonString))
	{
		UE_LOG(LogEchoesServer, Error, TEXT("Failed to serialize heartbeat request"));
		return;
	}

	// Create HTTP request
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = 
		CreateAuthenticatedRequest(TEXT("POST"), TEXT("/api/server-management/heartbeat"));
	HttpRequest->SetContentAsString(JsonString);

	// Bind response handler
	HttpRequest->OnProcessRequestComplete().BindUObject(
		this,
		&UEchoesServerManagementSubsystem::OnHeartbeatResponseReceived);

	// Send request
	if (!HttpRequest->ProcessRequest())
	{
		UE_LOG(LogEchoesServer, Error, TEXT("Failed to process heartbeat request"));
	}
	else
	{
		UE_LOG(LogEchoesServer, Verbose, TEXT("Heartbeat sent: Players=%d, CPU=%.1f%%, Memory=%lldMB"),
			PlayersCount, CPUUsage, MemoryUsageMB);
	}
}

void UEchoesServerManagementSubsystem::ServerOnly_GetConfig()
{
	if (!IsDedicatedServer() || !bIsRegistered)
	{
		UE_LOG(LogEchoesServer, Warning, TEXT("Cannot get config: server not registered"));
		return;
	}

	if (!Http)
	{
		UE_LOG(LogEchoesServer, Error, TEXT("HTTP module not available"));
		return;
	}

	UE_LOG(LogEchoesServer, Log, TEXT("Requesting universe configuration from backend..."));

	// Create config request
	FServerConfigRequest Request;
	Request.InstanceId = ServerInstanceId;
	Request.ServerType = TEXT("DedicatedSystem");
	Request.SolarSystemId = CurrentSolarSystemId.ToString();

	// Convert to JSON
	FString JsonString;
	if (!FJsonObjectConverter::UStructToJsonObjectString(Request, JsonString))
	{
		UE_LOG(LogEchoesServer, Error, TEXT("Failed to serialize config request"));
		return;
	}

	// Create HTTP request
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = 
		CreateAuthenticatedRequest(TEXT("POST"), TEXT("/api/server-management/config"));
	HttpRequest->SetContentAsString(JsonString);

	// Bind response handler
	HttpRequest->OnProcessRequestComplete().BindUObject(
		this,
		&UEchoesServerManagementSubsystem::OnConfigResponseReceived);

	// Send request
	if (!HttpRequest->ProcessRequest())
	{
		UE_LOG(LogEchoesServer, Error, TEXT("Failed to process config request"));
	}
	else
	{
		UE_LOG(LogEchoesServer, Log, TEXT("Config request sent to: %s"), *HttpRequest->GetURL());
	}
}

void UEchoesServerManagementSubsystem::ServerOnly_Unregister()
{
	if (!IsDedicatedServer() || !bIsRegistered)
	{
		return;
	}

	if (!Http)
	{
		UE_LOG(LogEchoesServer, Error, TEXT("HTTP module not available"));
		return;
	}

	UE_LOG(LogEchoesServer, Log, TEXT("Unregistering server from backend..."));

	// Create HTTP request
	FString Endpoint = FString::Printf(TEXT("/api/server-management/unregister/%s"), *ServerInstanceId);
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = 
		CreateAuthenticatedRequest(TEXT("DELETE"), Endpoint);

	// Bind response handler
	HttpRequest->OnProcessRequestComplete().BindUObject(
		this,
		&UEchoesServerManagementSubsystem::OnUnregisterResponseReceived);

	// Send request
	if (!HttpRequest->ProcessRequest())
	{
		UE_LOG(LogEchoesServer, Error, TEXT("Failed to process unregister request"));
	}
	else
	{
		UE_LOG(LogEchoesServer, Log, TEXT("Unregister request sent to: %s"), *HttpRequest->GetURL());
	}
}

// ==================== HTTP Response Handlers ====================

void UEchoesServerManagementSubsystem::OnRegisterResponseReceived(
	FHttpRequestPtr Request,
	FHttpResponsePtr Response,
	bool bWasSuccessful)
{
	if (!bWasSuccessful || !Response.IsValid())
	{
		UE_LOG(LogEchoesServer, Error, TEXT("Registration failed: Request unsuccessful"));
		return;
	}

	const int32 ResponseCode = Response->GetResponseCode();
	const FString ResponseBody = Response->GetContentAsString();

	UE_LOG(LogEchoesServer, Log, TEXT("Registration response received (Code: %d)"), ResponseCode);

	if (ResponseCode == 200)
	{
		// Parse response
		FRegisterServerResponse RegisterResponse;
		if (FJsonObjectConverter::JsonObjectStringToUStruct(ResponseBody, &RegisterResponse))
		{
			if (RegisterResponse.Success)
			{
				// Store server ID and mark as registered
				ServerId = RegisterResponse.ServerId;
				NodeType = RegisterResponse.NodeType;
				bIsRegistered = true;

				UE_LOG(LogEchoesServer, Log, TEXT("✓ SERVER REGISTRATION SUCCESSFUL"));
				UE_LOG(LogEchoesServer, Log, TEXT("  ServerId: %s"), *ServerId.ToString());
				UE_LOG(LogEchoesServer, Log, TEXT("  NodeType: %s"), *NodeType);
				UE_LOG(LogEchoesServer, Log, TEXT("  Message: %s"), *RegisterResponse.Message);

				// Start heartbeat timer
				ServerOnly_StartHeartbeat();

				// Request universe configuration
				ServerOnly_GetConfig();
			}
			else
			{
				UE_LOG(LogEchoesServer, Error, TEXT("Registration failed: %s"), *RegisterResponse.Message);
			}
		}
		else
		{
			UE_LOG(LogEchoesServer, Error, TEXT("Failed to parse registration response: %s"), *ResponseBody);
		}
	}
	else
	{
		UE_LOG(LogEchoesServer, Error, TEXT("Registration failed with code %d: %s"), 
			ResponseCode, *ResponseBody);
	}
}

void UEchoesServerManagementSubsystem::OnHeartbeatResponseReceived(
	FHttpRequestPtr Request,
	FHttpResponsePtr Response,
	bool bWasSuccessful)
{
	if (!bWasSuccessful || !Response.IsValid())
	{
		UE_LOG(LogEchoesServer, Warning, TEXT("Heartbeat failed: Request unsuccessful"));
		return;
	}

	const int32 ResponseCode = Response->GetResponseCode();
	const FString ResponseBody = Response->GetContentAsString();

	if (ResponseCode == 200)
	{
		// Parse response
		FHeartbeatResponse HeartbeatResponse;
		if (FJsonObjectConverter::JsonObjectStringToUStruct(ResponseBody, &HeartbeatResponse))
		{
			if (HeartbeatResponse.Success)
			{
				UE_LOG(LogEchoesServer, Verbose, TEXT("Heartbeat acknowledged by backend"));
			}
		}
	}
	else if (ResponseCode == 404)
	{
		// Server not found in backend - trigger re-registration
		UE_LOG(LogEchoesServer, Warning, TEXT("Heartbeat returned 404 - Server not found in backend"));
		UE_LOG(LogEchoesServer, Log, TEXT("Initiating re-registration procedure..."));
		
		bIsRegistered = false;
		ServerOnly_Register(ServerInstanceId, GamePort, CurrentSolarSystemId);
	}
	else
	{
		UE_LOG(LogEchoesServer, Warning, TEXT("Heartbeat failed with code %d: %s"), 
			ResponseCode, *ResponseBody);
	}
}

void UEchoesServerManagementSubsystem::OnConfigResponseReceived(
	FHttpRequestPtr Request,
	FHttpResponsePtr Response,
	bool bWasSuccessful)
{
	if (!bWasSuccessful || !Response.IsValid())
	{
		UE_LOG(LogEchoesServer, Error, TEXT("Config request failed: Request unsuccessful"));
		return;
	}

	const int32 ResponseCode = Response->GetResponseCode();
	const FString ResponseBody = Response->GetContentAsString();

	UE_LOG(LogEchoesServer, Log, TEXT("Config response received (Code: %d)"), ResponseCode);

	if (ResponseCode == 200)
	{
		// Check server type and parse appropriate response
		if (IsRegionalCluster())
		{
			// Parse regional cluster response
			FServerRegionalClusterConfigResponse RegionalResponse;
			if (FJsonObjectConverter::JsonObjectStringToUStruct(ResponseBody, &RegionalResponse))
			{
				// Cache regional configuration
				CachedRegionalConfig = RegionalResponse.Config;

				UE_LOG(LogEchoesServer, Log, TEXT("╔══════════════════════════════════════════════════════════╗"));
				UE_LOG(LogEchoesServer, Log, TEXT("║    REGIONAL CLUSTER CONFIGURATION RECEIVED              ║"));
				UE_LOG(LogEchoesServer, Log, TEXT("╚══════════════════════════════════════════════════════════╝"));
				UE_LOG(LogEchoesServer, Log, TEXT("  Region: %s (%s)"), *CachedRegionalConfig.RegionName, *CachedRegionalConfig.RegionCode);
				UE_LOG(LogEchoesServer, Log, TEXT("  Systems: %d"), CachedRegionalConfig.Systems.Num());
				UE_LOG(LogEchoesServer, Log, TEXT("  Total Planets: %d"), CachedRegionalConfig.TotalPlanets);
				UE_LOG(LogEchoesServer, Log, TEXT("  Total Stargates: %d"), CachedRegionalConfig.TotalStargates);
				UE_LOG(LogEchoesServer, Log, TEXT("  Total Stations: %d"), CachedRegionalConfig.TotalStations);
				UE_LOG(LogEchoesServer, Log, TEXT("  Average Security: %.2f"), CachedRegionalConfig.AverageSecurity);

				// Log individual systems
				for (const FServerSystemConfig& System : CachedRegionalConfig.Systems)
				{
					UE_LOG(LogEchoesServer, Log, TEXT("    - %s [%.0f, %.0f, %.0f]"), 
						*System.SystemName,
						(float)System.PositionX,
						(float)System.PositionY,
						(float)System.PositionZ);
				}

				// Broadcast to listeners (e.g., WorldGenerator)
				OnRegionalClusterConfigReceived.Broadcast(CachedRegionalConfig);
			}
			else
			{
				UE_LOG(LogEchoesServer, Error, TEXT("Failed to parse regional cluster config response: %s"), *ResponseBody);
			}
		}
		else
		{
			// Parse single system response (DedicatedSystem mode)
			FServerConfigResponse ConfigResponse;
			if (FJsonObjectConverter::JsonObjectStringToUStruct(ResponseBody, &ConfigResponse))
			{
				// Cache configuration
				CachedConfig = ConfigResponse.Config;

				UE_LOG(LogEchoesServer, Log, TEXT("✓ UNIVERSE CONFIGURATION RECEIVED"));
				UE_LOG(LogEchoesServer, Log, TEXT("  System: %s"), *CachedConfig.SystemName);
				UE_LOG(LogEchoesServer, Log, TEXT("  Planets: %d"), CachedConfig.Planets.Num());
				UE_LOG(LogEchoesServer, Log, TEXT("  Stargates: %d"), CachedConfig.Stargates.Num());
				UE_LOG(LogEchoesServer, Log, TEXT("  Stations: %d"), CachedConfig.Stations.Num());
				UE_LOG(LogEchoesServer, Log, TEXT("  Anomalies: %d"), CachedConfig.Anomalies.Num());
				UE_LOG(LogEchoesServer, Log, TEXT("  Wormholes: %d"), CachedConfig.Wormholes.Num());

				// Broadcast to listeners (e.g., WorldGenerator)
				OnServerConfigReceived.Broadcast(CachedConfig);
			}
			else
			{
				UE_LOG(LogEchoesServer, Error, TEXT("Failed to parse config response: %s"), *ResponseBody);
			}
		}
	}
	else
	{
		UE_LOG(LogEchoesServer, Error, TEXT("Config request failed with code %d: %s"), 
			ResponseCode, *ResponseBody);
	}
}

void UEchoesServerManagementSubsystem::OnUnregisterResponseReceived(
	FHttpRequestPtr Request,
	FHttpResponsePtr Response,
	bool bWasSuccessful)
{
	if (!bWasSuccessful || !Response.IsValid())
	{
		UE_LOG(LogEchoesServer, Warning, TEXT("Unregister failed: Request unsuccessful"));
		return;
	}

	const int32 ResponseCode = Response->GetResponseCode();
	const FString ResponseBody = Response->GetContentAsString();

	if (ResponseCode == 200)
	{
		UE_LOG(LogEchoesServer, Log, TEXT("✓ Server unregistered successfully"));
		bIsRegistered = false;
	}
	else
	{
		UE_LOG(LogEchoesServer, Warning, TEXT("Unregister failed with code %d: %s"), 
			ResponseCode, *ResponseBody);
	}
}

// ==================== Helper Functions ====================

FString UEchoesServerManagementSubsystem::GetApiBaseUrl() const
{
	// Try to get from config first
	if (!BackendURL.IsEmpty())
	{
		return BackendURL;
	}

	// Default fallback
	return TEXT("http://localhost:5000");
}

FString UEchoesServerManagementSubsystem::GetServerSecret() const
{
	// Get from config
	if (!ServerSecret.IsEmpty())
	{
		return ServerSecret;
	}

	// Error: No server secret configured
	UE_LOG(LogEchoesServer, Error, TEXT("ServerSecret not configured in DefaultGame.ini! Server authentication will fail."));
	return TEXT("");
}

bool UEchoesServerManagementSubsystem::IsDedicatedServer() const
{
	UGameInstance* GameInstance = GetGameInstance();
	if (!GameInstance)
	{
		return false;
	}

	UWorld* World = GameInstance->GetWorld();
	if (!World)
	{
		return false;
	}

	return World->GetNetMode() == NM_DedicatedServer;
}

void UEchoesServerManagementSubsystem::CollectServerMetrics(
	float& OutCPUUsage,
	int64& OutMemoryUsageMB,
	int32& OutPlayersCount)
{
	// Get memory usage
	FPlatformMemoryStats MemStats = FPlatformMemory::GetStats();
	OutMemoryUsageMB = MemStats.UsedPhysical / (1024 * 1024);

	// CPU usage: Not implemented - return 0 to indicate unknown
	// TODO: Implement platform-specific CPU usage monitoring
	// Windows: Use Performance Counters or GetSystemTimes()
	// Linux: Parse /proc/stat
	OutCPUUsage = 0.0f;

	// Get player count
	OutPlayersCount = 0;
	UGameInstance* GameInstance = GetGameInstance();
	if (GameInstance)
	{
		UWorld* World = GameInstance->GetWorld();
		if (World)
		{
			AGameModeBase* GameMode = World->GetAuthGameMode();
			if (GameMode)
			{
				OutPlayersCount = GameMode->GetNumPlayers();
			}
		}
	}
}

void UEchoesServerManagementSubsystem::ServerOnly_StartHeartbeat()
{
	UGameInstance* GameInstance = GetGameInstance();
	if (!GameInstance)
	{
		UE_LOG(LogEchoesServer, Error, TEXT("Cannot start heartbeat: GameInstance is null"));
		return;
	}

	// Clear existing timer if any
	if (HeartbeatTimerHandle.IsValid())
	{
		GameInstance->GetTimerManager().ClearTimer(HeartbeatTimerHandle);
	}

	// Start heartbeat timer (30 seconds interval)
	GameInstance->GetTimerManager().SetTimer(
		HeartbeatTimerHandle,
		this,
		&UEchoesServerManagementSubsystem::ServerOnly_Heartbeat,
		30.0f,
		true // Loop
	);

	UE_LOG(LogEchoesServer, Log, TEXT("Heartbeat timer started (30 second interval)"));
}

void UEchoesServerManagementSubsystem::ServerOnly_StopHeartbeat()
{
	UGameInstance* GameInstance = GetGameInstance();
	if (!GameInstance)
	{
		return;
	}

	if (HeartbeatTimerHandle.IsValid())
	{
		GameInstance->GetTimerManager().ClearTimer(HeartbeatTimerHandle);
		HeartbeatTimerHandle.Invalidate();
		UE_LOG(LogEchoesServer, Log, TEXT("Heartbeat timer stopped"));
	}
}

TSharedRef<IHttpRequest, ESPMode::ThreadSafe> UEchoesServerManagementSubsystem::CreateAuthenticatedRequest(
	const FString& Verb,
	const FString& Endpoint)
{
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = Http->CreateRequest();
	HttpRequest->SetVerb(Verb);
	HttpRequest->SetURL(GetApiBaseUrl() + Endpoint);
	HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	
	// Add authentication header
	HttpRequest->SetHeader(TEXT("X-Server-Secret"), GetServerSecret());

	return HttpRequest;
}
