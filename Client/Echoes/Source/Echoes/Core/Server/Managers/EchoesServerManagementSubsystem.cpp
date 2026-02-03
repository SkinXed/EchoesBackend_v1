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
	 LoadConfig();

	 if (BackendURL.IsEmpty() || BackendURL.Equals(TEXT("http:")))
	 {
		  BackendURL = TEXT("http://localhost:5116");
	 }
	 if (BackendURL.EndsWith(TEXT("/")))
	 {
		  BackendURL.LeftChopInline(1);
	 }
	 if
		  (
		  !BackendURL.StartsWith(TEXT("http://")) &&
		  !BackendURL.StartsWith(TEXT("https://"))
	 )
	 {
		  BackendURL = TEXT("http://") + BackendURL;
	 }
	


	// Get HTTP module
	Http = &FHttpModule::Get();

	UE_LOG(LogEchoesServer, Log, TEXT("EchoesServerManagementSubsystem initialized. API: %s"), *GetApiBaseUrl());

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
	int32 InGamePort,
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
	GamePort = InGamePort;
	CurrentSolarSystemId = SolarSystemId;

	UE_LOG(LogEchoesServer, Log, TEXT("Starting server registration handshake..."));
	UE_LOG(LogEchoesServer, Log, TEXT("  InstanceId: %s"), *InstanceId);
	UE_LOG(LogEchoesServer, Log, TEXT("  GamePort: %d"), InGamePort);
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
	
	Request.GamePort = InGamePort;
	Request.WebPort = InGamePort + 1; // TODO: Make WebPort independently configurable
	Request.MaxPlayers = 100;
	Request.GameVersion = TEXT("1.0.0");

	// Set mode-specific parameters
	if (IsRegionalCluster())
	{
		if (!CurrentRegionId.IsValid())
		{
			UE_LOG(LogEchoesServer, Error, TEXT("Cannot register: RegionId is invalid"));
			return;
		}

		Request.RegionId = CurrentRegionId;
		Request.ServerType = TEXT("RegionalCluster");
	}
	else
	{
		if (!SolarSystemId.IsValid())
		{
			UE_LOG(LogEchoesServer, Error, TEXT("Cannot register: SolarSystemId is invalid"));
			return;
		}

		Request.SolarSystemId = SolarSystemId;
		Request.ServerType = TEXT("DedicatedSystem");
	}

	// Get hostname
	Request.Hostname = FPlatformProcess::ComputerName();

	// Convert to JSON (manual to ensure GUIDs are strings)
	TSharedPtr<FJsonObject> JsonObject = MakeShared<FJsonObject>();
	JsonObject->SetStringField(TEXT("instanceId"), Request.InstanceId);
	JsonObject->SetStringField(TEXT("publicIP"), Request.PublicIP);
	JsonObject->SetNumberField(TEXT("gamePort"), Request.GamePort);
	JsonObject->SetNumberField(TEXT("webPort"), Request.WebPort);
	JsonObject->SetNumberField(TEXT("maxPlayers"), Request.MaxPlayers);
	JsonObject->SetStringField(TEXT("geoRegion"), Request.GeoRegion);
	JsonObject->SetStringField(TEXT("gameVersion"), Request.GameVersion);
	JsonObject->SetStringField(TEXT("hostname"), Request.Hostname);

	if (!Request.ServerTags.IsEmpty())
	{
		JsonObject->SetStringField(TEXT("serverTags"), Request.ServerTags);
	}

	if (IsRegionalCluster())
	{
		JsonObject->SetStringField(TEXT("regionId"), CurrentRegionId.ToString(EGuidFormats::DigitsWithHyphensLower));
	}
	else
	{
		JsonObject->SetStringField(TEXT("solarSystemId"), SolarSystemId.ToString(EGuidFormats::DigitsWithHyphensLower));
	}

	FString JsonString;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&JsonString);
	if (!FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer))
	{
		UE_LOG(LogEchoesServer, Error, TEXT("Failed to serialize registration request"));
		return;
	}

	// Create HTTP request
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = 
		CreateAuthenticatedRequest(TEXT("POST"), GetRegisterEndpoint());
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
		CreateAuthenticatedRequest(TEXT("POST"), GetHeartbeatEndpoint());
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

	// Build JSON manually to ensure GUIDs are represented as strings
	TSharedPtr<FJsonObject> JsonObject = MakeShared<FJsonObject>();
	JsonObject->SetStringField(TEXT("instanceId"), ServerInstanceId);
	JsonObject->SetStringField(TEXT("serverType"), ServerType);

	if (IsRegionalCluster())
	{
		if (!CurrentRegionId.IsValid())
		{
			UE_LOG(LogEchoesServer, Error, TEXT("Cannot request config: CurrentRegionId is invalid"));
			return;
		}
		JsonObject->SetStringField(TEXT("regionId"), CurrentRegionId.ToString(EGuidFormats::DigitsWithHyphensLower));
	}
	else
	{
		if (!CurrentSolarSystemId.IsValid())
		{
			UE_LOG(LogEchoesServer, Error, TEXT("Cannot request config: CurrentSolarSystemId is invalid"));
			return;
		}
		JsonObject->SetStringField(TEXT("solarSystemId"), CurrentSolarSystemId.ToString(EGuidFormats::DigitsWithHyphensLower));
	}

	FString JsonString;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&JsonString);
	if (!FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer))
	{
		UE_LOG(LogEchoesServer, Error, TEXT("Failed to serialize config request"));
		return;
	}

	// Create HTTP request
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = 
		CreateAuthenticatedRequest(TEXT("POST"), GetConfigEndpoint());
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
	FString Endpoint = FString::Printf(TEXT("%s/%s"), *GetUnregisterEndpoint(), *ServerInstanceId);
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
		// Manually parse JSON because FJsonObjectConverter has trouble importing into FGuid properties
		TSharedPtr<FJsonObject> JsonObj;
		TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(ResponseBody);
		if (!FJsonSerializer::Deserialize(Reader, JsonObj) || !JsonObj.IsValid())
		{
			UE_LOG(LogEchoesServer, Error, TEXT("Failed to deserialize registration response JSON: %s"), *ResponseBody);
			return;
		}

		bool bSuccess = false;
		if (JsonObj->TryGetBoolField(TEXT("Success"), bSuccess) && bSuccess)
		{
			// Read ServerId as string and parse to FGuid
			FString ServerIdStr;
			if (JsonObj->TryGetStringField(TEXT("ServerId"), ServerIdStr))
			{
				FGuid ParsedServerId;
				if (FGuid::Parse(ServerIdStr, ParsedServerId))
				{
					ServerId = ParsedServerId;
				}
				else
				{
					UE_LOG(LogEchoesServer, Warning, TEXT("Failed to parse ServerId GUID from response: %s"), *ServerIdStr);
				}
			}

			// InstanceId may be returned as string (sometimes without GUID formatting)
			FString InstanceIdStr;
			if (JsonObj->TryGetStringField(TEXT("InstanceId"), InstanceIdStr))
			{
				ServerInstanceId = InstanceIdStr;
			}

			// NodeType and Message
			FString NodeTypeStr;
			if (JsonObj->TryGetStringField(TEXT("NodeType"), NodeTypeStr))
			{
				ServerType = NodeTypeStr;
			}

			FString MessageStr;
			if (JsonObj->TryGetStringField(TEXT("Message"), MessageStr))
			{
				UE_LOG(LogEchoesServer, Log, TEXT("✓ SERVER REGISTRATION SUCCESSFUL"));
				UE_LOG(LogEchoesServer, Log, TEXT("  ServerId: %s"), *ServerId.ToString());
				UE_LOG(LogEchoesServer, Log, TEXT("  ServerType: %s"), *ServerType);
				UE_LOG(LogEchoesServer, Log, TEXT("  Message: %s"), *MessageStr);
			}
			else
			{
				UE_LOG(LogEchoesServer, Log, TEXT("✓ SERVER REGISTRATION SUCCESSFUL (no message provided)"));
			}

			bIsRegistered = true;

			// Start heartbeat timer
			ServerOnly_StartHeartbeat();

			// Request universe configuration
			ServerOnly_GetConfig();
		}
		else
		{
			// Try to retrieve message or entire body for debugging
			FString ErrMsg;
			if (!JsonObj->TryGetStringField(TEXT("Message"), ErrMsg))
			{
				ErrMsg = ResponseBody;
			}
			UE_LOG(LogEchoesServer, Error, TEXT("Registration failed: %s"), *ErrMsg);
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

	if (ResponseCode != 200)
	{
		UE_LOG(LogEchoesServer, Error, TEXT("Config request failed with code %d: %s"), 
			ResponseCode, *ResponseBody);
		return;
	}

	TSharedPtr<FJsonObject> RootObj;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(ResponseBody);
	if (!FJsonSerializer::Deserialize(Reader, RootObj) || !RootObj.IsValid())
	{
		UE_LOG(LogEchoesServer, Error, TEXT("Failed to deserialize config response JSON: %s"), *ResponseBody);
		return;
	}

	TSharedPtr<FJsonObject> ConfigObj = RootObj->GetObjectField(TEXT("Config"));
	if (!ConfigObj.IsValid())
	{
		UE_LOG(LogEchoesServer, Error, TEXT("Config object missing in response: %s"), *ResponseBody);
		return;
	}

	auto ParseGuid = [](const FString& Str, FGuid& OutGuid)
	{
		return FGuid::Parse(Str, OutGuid);
	};

	auto ParseMoon = [&](const TSharedPtr<FJsonObject>& MoonObj) -> FMoonConfig
	{
		FMoonConfig Moon;
		FString IdStr;
		if (MoonObj->TryGetStringField(TEXT("Id"), IdStr)) ParseGuid(IdStr, Moon.Id);
		MoonObj->TryGetStringField(TEXT("Name"), Moon.Name);
		int64 Val64 = 0;
		if (MoonObj->TryGetNumberField(TEXT("Radius"), Val64)) Moon.Radius = Val64;
		if (MoonObj->TryGetNumberField(TEXT("PositionX"), Val64)) Moon.PositionX = Val64;
		if (MoonObj->TryGetNumberField(TEXT("PositionY"), Val64)) Moon.PositionY = Val64;
		if (MoonObj->TryGetNumberField(TEXT("PositionZ"), Val64)) Moon.PositionZ = Val64;
		return Moon;
	};

	auto ParseResource = [&](const TSharedPtr<FJsonObject>& ResObj) -> FResourceConfig
	{
		FResourceConfig R;
		FString IdStr;
		if (ResObj->TryGetStringField(TEXT("Id"), IdStr)) ParseGuid(IdStr, R.Id);
		ResObj->TryGetStringField(TEXT("ResourceType"), R.ResourceType);
		double Num = 0;
		if (ResObj->TryGetNumberField(TEXT("Quantity"), Num)) R.Quantity = (int32)Num;
		if (ResObj->TryGetNumberField(TEXT("Richness"), Num)) R.Richness = (float)Num;
		return R;
	};

	auto ParsePlanet = [&](const TSharedPtr<FJsonObject>& PlanetObj) -> FPlanetConfig
	{
		FPlanetConfig P;
		FString IdStr;
		if (PlanetObj->TryGetStringField(TEXT("Id"), IdStr)) ParseGuid(IdStr, P.Id);
		PlanetObj->TryGetStringField(TEXT("Name"), P.Name);
		PlanetObj->TryGetStringField(TEXT("Type"), P.Type);
		double Num = 0;
		if (PlanetObj->TryGetNumberField(TEXT("OrbitDistance"), Num)) P.OrbitDistance = (float)Num;
		if (PlanetObj->TryGetNumberField(TEXT("Radius"), Num)) P.Radius = (float)Num;
		int64 Val64 = 0;
		if (PlanetObj->TryGetNumberField(TEXT("PositionX"), Val64)) P.PositionX = Val64;
		if (PlanetObj->TryGetNumberField(TEXT("PositionY"), Val64)) P.PositionY = Val64;
		if (PlanetObj->TryGetNumberField(TEXT("PositionZ"), Val64)) P.PositionZ = Val64;

		const TArray<TSharedPtr<FJsonValue>>* MoonsArray;
		if (PlanetObj->TryGetArrayField(TEXT("Moons"), MoonsArray))
		{
			for (const TSharedPtr<FJsonValue>& Val : *MoonsArray)
			{
				if (Val.IsValid() && Val->Type == EJson::Object)
				{
					P.Moons.Add(ParseMoon(Val->AsObject()));
				}
			}
		}

		const TArray<TSharedPtr<FJsonValue>>* ResArray;
		if (PlanetObj->TryGetArrayField(TEXT("Resources"), ResArray))
		{
			for (const TSharedPtr<FJsonValue>& Val : *ResArray)
			{
				if (Val.IsValid() && Val->Type == EJson::Object)
				{
					P.Resources.Add(ParseResource(Val->AsObject()));
				}
			}
		}

		return P;
	};

	auto ParseStargate = [&](const TSharedPtr<FJsonObject>& GateObj) -> FStargateConfig
	{
		FStargateConfig G;
		FString IdStr;
		if (GateObj->TryGetStringField(TEXT("Id"), IdStr)) ParseGuid(IdStr, G.Id);
		GateObj->TryGetStringField(TEXT("Name"), G.Name);
		FString TargetIdStr;
		if (GateObj->TryGetStringField(TEXT("TargetSystemId"), TargetIdStr)) ParseGuid(TargetIdStr, G.TargetSystemId);
		GateObj->TryGetStringField(TEXT("TargetSystemName"), G.TargetSystemName);
		double Num = 0;
		if (GateObj->TryGetNumberField(TEXT("PositionX"), Num)) G.PositionX = (float)Num;
		if (GateObj->TryGetNumberField(TEXT("PositionY"), Num)) G.PositionY = (float)Num;
		if (GateObj->TryGetNumberField(TEXT("PositionZ"), Num)) G.PositionZ = (float)Num;
		bool bOp = false;
		if (GateObj->TryGetBoolField(TEXT("IsOperational"), bOp)) G.IsOperational = bOp;
		double JumpCostNum = 0;
		if (GateObj->TryGetNumberField(TEXT("JumpCost"), JumpCostNum)) G.JumpCost = (int32)JumpCostNum;
		GateObj->TryGetStringField(TEXT("Model"), G.Model);
		return G;
	};

	auto ParseStation = [&](const TSharedPtr<FJsonObject>& StObj) -> FStationConfig
	{
		FStationConfig S;
		FString IdStr;
		if (StObj->TryGetStringField(TEXT("Id"), IdStr)) ParseGuid(IdStr, S.Id);
		StObj->TryGetStringField(TEXT("Name"), S.Name);
		int64 Val64 = 0;
		if (StObj->TryGetNumberField(TEXT("PositionX"), Val64)) S.PositionX = Val64;
		if (StObj->TryGetNumberField(TEXT("PositionY"), Val64)) S.PositionY = Val64;
		if (StObj->TryGetNumberField(TEXT("PositionZ"), Val64)) S.PositionZ = Val64;
		StObj->TryGetStringField(TEXT("StationType"), S.StationType);
		return S;
	};

	auto ParseAsteroid = [&](const TSharedPtr<FJsonObject>& AbObj) -> FAsteroidBeltConfig
	{
		FAsteroidBeltConfig A;
		FString IdStr;
		if (AbObj->TryGetStringField(TEXT("Id"), IdStr)) ParseGuid(IdStr, A.Id);
		AbObj->TryGetStringField(TEXT("Name"), A.Name);
		int64 Val64 = 0;
		if (AbObj->TryGetNumberField(TEXT("PositionX"), Val64)) A.PositionX = Val64;
		if (AbObj->TryGetNumberField(TEXT("PositionY"), Val64)) A.PositionY = Val64;
		if (AbObj->TryGetNumberField(TEXT("PositionZ"), Val64)) A.PositionZ = Val64;
		const TArray<TSharedPtr<FJsonValue>>* ResArray;
		if (AbObj->TryGetArrayField(TEXT("Resources"), ResArray))
		{
			for (const TSharedPtr<FJsonValue>& Val : *ResArray)
			{
				if (Val.IsValid() && Val->Type == EJson::Object)
				{
					A.Resources.Add(ParseResource(Val->AsObject()));
				}
			}
		}
		return A;
	};

	auto ParseAnomaly = [&](const TSharedPtr<FJsonObject>& AnObj) -> FAnomalyConfig
	{
		FAnomalyConfig An;
		FString IdStr;
		if (AnObj->TryGetStringField(TEXT("Id"), IdStr)) ParseGuid(IdStr, An.Id);
		AnObj->TryGetStringField(TEXT("Name"), An.Name);
		AnObj->TryGetStringField(TEXT("Type"), An.Type);
		AnObj->TryGetStringField(TEXT("Difficulty"), An.Difficulty);
		int64 Val64 = 0;
		if (AnObj->TryGetNumberField(TEXT("PositionX"), Val64)) An.PositionX = Val64;
		if (AnObj->TryGetNumberField(TEXT("PositionY"), Val64)) An.PositionY = Val64;
		if (AnObj->TryGetNumberField(TEXT("PositionZ"), Val64)) An.PositionZ = Val64;
		return An;
	};

	auto ParseWormhole = [&](const TSharedPtr<FJsonObject>& WhObj) -> FWormholeConfig
	{
		FWormholeConfig W;
		FString IdStr;
		if (WhObj->TryGetStringField(TEXT("Id"), IdStr)) ParseGuid(IdStr, W.Id);
		WhObj->TryGetStringField(TEXT("Name"), W.Name);
		FString TargetIdStr;
		if (WhObj->TryGetStringField(TEXT("TargetSystemId"), TargetIdStr)) ParseGuid(TargetIdStr, W.TargetSystemId);
		int64 Val64 = 0;
		if (WhObj->TryGetNumberField(TEXT("PositionX"), Val64)) W.PositionX = Val64;
		if (WhObj->TryGetNumberField(TEXT("PositionY"), Val64)) W.PositionY = Val64;
		if (WhObj->TryGetNumberField(TEXT("PositionZ"), Val64)) W.PositionZ = Val64;
		return W;
	};

	if (IsRegionalCluster())
	{
		FServerRegionalClusterConfig Regional;
		FString Rid;
		if (ConfigObj->TryGetStringField(TEXT("RegionId"), Rid)) ParseGuid(Rid, Regional.RegionId);
		ConfigObj->TryGetStringField(TEXT("RegionName"), Regional.RegionName);
		ConfigObj->TryGetStringField(TEXT("RegionCode"), Regional.RegionCode);
		double Tmp = 0;
		if (ConfigObj->TryGetNumberField(TEXT("AverageSecurity"), Tmp)) Regional.AverageSecurity = (float)Tmp;
		if (ConfigObj->TryGetNumberField(TEXT("ConstellationCount"), Tmp)) Regional.ConstellationCount = (int32)Tmp;
		if (ConfigObj->TryGetNumberField(TEXT("SystemCount"), Tmp)) Regional.SystemCount = (int32)Tmp;
		if (ConfigObj->TryGetNumberField(TEXT("TotalPlanets"), Tmp)) Regional.TotalPlanets = (int32)Tmp;
		if (ConfigObj->TryGetNumberField(TEXT("TotalStargates"), Tmp)) Regional.TotalStargates = (int32)Tmp;
		if (ConfigObj->TryGetNumberField(TEXT("TotalStations"), Tmp)) Regional.TotalStations = (int32)Tmp;

		const TArray<TSharedPtr<FJsonValue>>* SystemsArray;
		if (ConfigObj->TryGetArrayField(TEXT("Systems"), SystemsArray))
		{
			for (const TSharedPtr<FJsonValue>& Val : *SystemsArray)
			{
				if (Val.IsValid() && Val->Type == EJson::Object)
				{
					TSharedPtr<FJsonObject> SysObj = Val->AsObject();
					FServerSystemConfig Sys;
					FString IdStr;
					if (SysObj->TryGetStringField(TEXT("SystemId"), IdStr)) ParseGuid(IdStr, Sys.SystemId);
					SysObj->TryGetStringField(TEXT("SystemName"), Sys.SystemName);
					double dd = 0;
					if (SysObj->TryGetNumberField(TEXT("SolarRadius"), dd)) Sys.SolarRadius = (float)dd;
					if (SysObj->TryGetNumberField(TEXT("SolarMass"), dd)) Sys.SolarMass = (float)dd;
					if (SysObj->TryGetNumberField(TEXT("Temperature"), dd)) Sys.Temperature = (float)dd;
					if (SysObj->TryGetNumberField(TEXT("Luminosity"), dd)) Sys.Luminosity = (float)dd;
					if (SysObj->TryGetNumberField(TEXT("SecurityStatus"), dd)) Sys.SecurityStatus = (float)dd;
					SysObj->TryGetStringField(TEXT("StarClass"), Sys.StarClass);
					FString CId;
					if (SysObj->TryGetStringField(TEXT("ConstellationId"), CId)) ParseGuid(CId, Sys.ConstellationId);
					SysObj->TryGetStringField(TEXT("ConstellationName"), Sys.ConstellationName);
					FString RegId;
					if (SysObj->TryGetStringField(TEXT("RegionId"), RegId)) ParseGuid(RegId, Sys.RegionId);
					SysObj->TryGetStringField(TEXT("RegionName"), Sys.RegionName);
					int64 v64 = 0;
					if (SysObj->TryGetNumberField(TEXT("PositionX"), v64)) Sys.PositionX = v64;
					if (SysObj->TryGetNumberField(TEXT("PositionY"), v64)) Sys.PositionY = v64;
					if (SysObj->TryGetNumberField(TEXT("PositionZ"), v64)) Sys.PositionZ = v64;

					const TArray<TSharedPtr<FJsonValue>>* PlanetsArray;
					if (SysObj->TryGetArrayField(TEXT("Planets"), PlanetsArray))
					{
						for (const TSharedPtr<FJsonValue>& Pv : *PlanetsArray)
						{
							if (Pv.IsValid() && Pv->Type == EJson::Object) Sys.Planets.Add(ParsePlanet(Pv->AsObject()));
						}
					}

					const TArray<TSharedPtr<FJsonValue>>* GatesArray;
					if (SysObj->TryGetArrayField(TEXT("Stargates"), GatesArray))
					{
						for (const TSharedPtr<FJsonValue>& Gv : *GatesArray)
						{
							if (Gv.IsValid() && Gv->Type == EJson::Object) Sys.Stargates.Add(ParseStargate(Gv->AsObject()));
						}
					}

					const TArray<TSharedPtr<FJsonValue>>* StationsArray;
					if (SysObj->TryGetArrayField(TEXT("Stations"), StationsArray))
					{
						for (const TSharedPtr<FJsonValue>& Sv : *StationsArray)
						{
							if (Sv.IsValid() && Sv->Type == EJson::Object) Sys.Stations.Add(ParseStation(Sv->AsObject()));
						}
					}

					const TArray<TSharedPtr<FJsonValue>>* AbArray;
					if (SysObj->TryGetArrayField(TEXT("AsteroidBelts"), AbArray))
					{
						for (const TSharedPtr<FJsonValue>& Av : *AbArray)
						{
							if (Av.IsValid() && Av->Type == EJson::Object) Sys.AsteroidBelts.Add(ParseAsteroid(Av->AsObject()));
						}
					}

					const TArray<TSharedPtr<FJsonValue>>* AnArray;
					if (SysObj->TryGetArrayField(TEXT("Anomalies"), AnArray))
					{
						for (const TSharedPtr<FJsonValue>& Av : *AnArray)
						{
							if (Av.IsValid() && Av->Type == EJson::Object) Sys.Anomalies.Add(ParseAnomaly(Av->AsObject()));
						}
					}

					const TArray<TSharedPtr<FJsonValue>>* WhArray;
					if (SysObj->TryGetArrayField(TEXT("Wormholes"), WhArray))
					{
						for (const TSharedPtr<FJsonValue>& Wv : *WhArray)
						{
							if (Wv.IsValid() && Wv->Type == EJson::Object) Sys.Wormholes.Add(ParseWormhole(Wv->AsObject()));
						}
					}

					Regional.Systems.Add(Sys);
				}
			}
		}

		CachedRegionalConfig = Regional;
		OnRegionalClusterConfigReceived.Broadcast(CachedRegionalConfig);
	}
	else
	{
		FServerSystemConfig Sys;
		FString SysIdStr;
		if (ConfigObj->TryGetStringField(TEXT("SystemId"), SysIdStr)) ParseGuid(SysIdStr, Sys.SystemId);
		ConfigObj->TryGetStringField(TEXT("SystemName"), Sys.SystemName);
		double dd = 0;
		if (ConfigObj->TryGetNumberField(TEXT("SolarRadius"), dd)) Sys.SolarRadius = (float)dd;
		if (ConfigObj->TryGetNumberField(TEXT("SolarMass"), dd)) Sys.SolarMass = (float)dd;
		if (ConfigObj->TryGetNumberField(TEXT("Temperature"), dd)) Sys.Temperature = (float)dd;
		if (ConfigObj->TryGetNumberField(TEXT("Luminosity"), dd)) Sys.Luminosity = (float)dd;
		if (ConfigObj->TryGetNumberField(TEXT("SecurityStatus"), dd)) Sys.SecurityStatus = (float)dd;
		ConfigObj->TryGetStringField(TEXT("StarClass"), Sys.StarClass);
		FString CId;
		if (ConfigObj->TryGetStringField(TEXT("ConstellationId"), CId)) ParseGuid(CId, Sys.ConstellationId);
		ConfigObj->TryGetStringField(TEXT("ConstellationName"), Sys.ConstellationName);
		FString RId;
		if (ConfigObj->TryGetStringField(TEXT("RegionId"), RId)) ParseGuid(RId, Sys.RegionId);
		ConfigObj->TryGetStringField(TEXT("RegionName"), Sys.RegionName);
		int64 v64 = 0;
		if (ConfigObj->TryGetNumberField(TEXT("PositionX"), v64)) Sys.PositionX = v64;
		if (ConfigObj->TryGetNumberField(TEXT("PositionY"), v64)) Sys.PositionY = v64;
		if (ConfigObj->TryGetNumberField(TEXT("PositionZ"), v64)) Sys.PositionZ = v64;

		const TArray<TSharedPtr<FJsonValue>>* PlanetsArray;
		if (ConfigObj->TryGetArrayField(TEXT("Planets"), PlanetsArray))
		{
			for (const TSharedPtr<FJsonValue>& Pv : *PlanetsArray)
			{
				if (Pv.IsValid() && Pv->Type == EJson::Object) Sys.Planets.Add(ParsePlanet(Pv->AsObject()));
			}
		}

		const TArray<TSharedPtr<FJsonValue>>* GatesArray;
		if (ConfigObj->TryGetArrayField(TEXT("Stargates"), GatesArray))
		{
			for (const TSharedPtr<FJsonValue>& Gv : *GatesArray)
			{
				if (Gv.IsValid() && Gv->Type == EJson::Object) Sys.Stargates.Add(ParseStargate(Gv->AsObject()));
			}
		}

		const TArray<TSharedPtr<FJsonValue>>* StationsArray;
		if (ConfigObj->TryGetArrayField(TEXT("Stations"), StationsArray))
		{
			for (const TSharedPtr<FJsonValue>& Sv : *StationsArray)
			{
				if (Sv.IsValid() && Sv->Type == EJson::Object) Sys.Stations.Add(ParseStation(Sv->AsObject()));
			}
		}

		const TArray<TSharedPtr<FJsonValue>>* AbArray;
		if (ConfigObj->TryGetArrayField(TEXT("AsteroidBelts"), AbArray))
		{
			for (const TSharedPtr<FJsonValue>& Av : *AbArray)
			{
				if (Av.IsValid() && Av->Type == EJson::Object) Sys.AsteroidBelts.Add(ParseAsteroid(Av->AsObject()));
			}
		}

		const TArray<TSharedPtr<FJsonValue>>* AnArray;
		if (ConfigObj->TryGetArrayField(TEXT("Anomalies"), AnArray))
		{
			for (const TSharedPtr<FJsonValue>& Av : *AnArray)
			{
				if (Av.IsValid() && Av->Type == EJson::Object) Sys.Anomalies.Add(ParseAnomaly(Av->AsObject()));
			}
		}

		const TArray<TSharedPtr<FJsonValue>>* WhArray;
		if (ConfigObj->TryGetArrayField(TEXT("Wormholes"), WhArray))
		{
			for (const TSharedPtr<FJsonValue>& Wv : *WhArray)
			{
				if (Wv.IsValid() && Wv->Type == EJson::Object) Sys.Wormholes.Add(ParseWormhole(Wv->AsObject()));
			}
		}

		CachedConfig = Sys;
		OnServerConfigReceived.Broadcast(CachedConfig);
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
	return TEXT("http://localhost:5116");
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

FString UEchoesServerManagementSubsystem::GetRegisterEndpoint() const
{
	// Try to get from config first
	if (!RegisterEndpoint.IsEmpty())
	{
		return RegisterEndpoint;
	}

	// Default fallback
	return TEXT("/api/server-management/register");
}

FString UEchoesServerManagementSubsystem::GetHeartbeatEndpoint() const
{
	// Try to get from config first
	if (!HeartbeatEndpoint.IsEmpty())
	{
		return HeartbeatEndpoint;
	}

	// Default fallback
	return TEXT("/api/server-management/heartbeat");
}

FString UEchoesServerManagementSubsystem::GetConfigEndpoint() const
{
	// Try to get from config first
	if (!ConfigEndpoint.IsEmpty())
	{
		return ConfigEndpoint;
	}

	// Default fallback
	return TEXT("/api/server-management/config");
}

FString UEchoesServerManagementSubsystem::GetUnregisterEndpoint() const
{
	// Try to get from config first
	if (!UnregisterEndpoint.IsEmpty())
	{
		return UnregisterEndpoint;
	}

	// Default fallback
	return TEXT("/api/server-management/unregister");
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
