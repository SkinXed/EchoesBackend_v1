// Copyright Epic Games, Inc. All Rights Reserved.

#include "CombatServerSubsystem.h"
#include "HttpModule.h"
#include "Interfaces/IHttpResponse.h"
#include "Json.h"
#include "JsonUtilities.h"
#include "Misc/ConfigCacheIni.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

// Define custom log category
DEFINE_LOG_CATEGORY(LogEchoesCombat);

void UCombatServerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	LoadConfig();

	// Default backend URL if not configured
	if (BackendURL.IsEmpty() || BackendURL.Equals(TEXT("http:")))
	{
		BackendURL = TEXT("http://localhost:5116");
	}
	if (BackendURL.EndsWith(TEXT("/")))
	{
		BackendURL.LeftChopInline(1);
	}
	if (!BackendURL.StartsWith(TEXT("http://")) && !BackendURL.StartsWith(TEXT("https://")))
	{
		BackendURL = TEXT("http://") + BackendURL;
	}

	// Get HTTP module
	Http = &FHttpModule::Get();

	UE_LOG(LogEchoesCombat, Log, TEXT("CombatServerSubsystem initialized. API: %s"), *GetApiBaseUrl());

	// Only proceed if this is a dedicated server
	if (!IsDedicatedServer())
	{
		UE_LOG(LogEchoesCombat, Warning, TEXT("Not a dedicated server, combat reporting disabled"));
		return;
	}

	UE_LOG(LogEchoesCombat, Log, TEXT("Combat reporting enabled for dedicated server"));
}

void UCombatServerSubsystem::Deinitialize()
{
	Super::Deinitialize();
	UE_LOG(LogEchoesCombat, Log, TEXT("CombatServerSubsystem deinitialized"));
}

void UCombatServerSubsystem::ServerOnly_ReportKill(
	int32 VictimID,
	int32 KillerID,
	int32 SolarSystemID,
	const FString& ShipType)
{
	// Safety check - only run on dedicated server
	if (!IsDedicatedServer())
	{
		UE_LOG(LogEchoesCombat, Warning, TEXT("ServerOnly_ReportKill called on non-dedicated server"));
		return;
	}

	UE_LOG(LogEchoesCombat, Log, 
		TEXT("Reporting kill: Victim=%d, Killer=%d, System=%d, Ship=%s"),
		VictimID, KillerID, SolarSystemID, *ShipType);

	// ==================== Build JSON Payload ====================
	
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	JsonObject->SetNumberField(TEXT("victimId"), VictimID);
	JsonObject->SetNumberField(TEXT("killerId"), KillerID);
	JsonObject->SetNumberField(TEXT("solarSystemId"), SolarSystemID);
	JsonObject->SetStringField(TEXT("shipType"), ShipType);

	// Serialize JSON to string
	FString JsonPayload;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&JsonPayload);
	if (!FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer))
	{
		UE_LOG(LogEchoesCombat, Error, TEXT("Failed to serialize killmail JSON"));
		return;
	}

	UE_LOG(LogEchoesCombat, Verbose, TEXT("Killmail JSON: %s"), *JsonPayload);

	// ==================== Create HTTP Request ====================
	
	FString Endpoint = GetKillmailEndpoint();
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = CreateAuthenticatedRequest(TEXT("POST"), Endpoint);
	
	// Set request body
	Request->SetContentAsString(JsonPayload);
	Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));

	// Set response callback
	Request->OnProcessRequestComplete().BindUObject(
		this,
		&UCombatServerSubsystem::OnKillmailResponseReceived);

	// Send request
	if (!Request->ProcessRequest())
	{
		UE_LOG(LogEchoesCombat, Error, TEXT("Failed to send killmail request"));
	}
	else
	{
		UE_LOG(LogEchoesCombat, Log, TEXT("Killmail request sent to: %s"), *Endpoint);
	}
}

void UCombatServerSubsystem::OnKillmailResponseReceived(
	FHttpRequestPtr Request,
	FHttpResponsePtr Response,
	bool bWasSuccessful)
{
	if (!bWasSuccessful || !Response.IsValid())
	{
		UE_LOG(LogEchoesCombat, Error, TEXT("Killmail request failed - no response"));
		return;
	}

	int32 ResponseCode = Response->GetResponseCode();
	FString ResponseBody = Response->GetContentAsString();

	UE_LOG(LogEchoesCombat, Log, 
		TEXT("Killmail response: Code=%d, Body=%s"),
		ResponseCode, *ResponseBody);

	if (ResponseCode == 200)
	{
		// Success - parse response
		TSharedPtr<FJsonObject> JsonObject;
		TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(ResponseBody);
		
		if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
		{
			bool bSuccess = JsonObject->GetBoolField(TEXT("success"));
			FString Message = JsonObject->GetStringField(TEXT("message"));
			
			UE_LOG(LogEchoesCombat, Log, 
				TEXT("Killmail recorded: Success=%d, Message=%s"),
				bSuccess, *Message);
		}
	}
	else if (ResponseCode == 401)
	{
		// Unauthorized - invalid server secret
		UE_LOG(LogEchoesCombat, Error, 
			TEXT("Killmail request unauthorized - check X-Server-Secret configuration"));
	}
	else
	{
		// Other error
		UE_LOG(LogEchoesCombat, Error, 
			TEXT("Killmail request failed with code %d: %s"),
			ResponseCode, *ResponseBody);
	}
}

// ==================== Helper Functions ====================

FString UCombatServerSubsystem::GetApiBaseUrl() const
{
	return BackendURL;
}

FString UCombatServerSubsystem::GetServerSecret() const
{
	// Return configured secret or fallback to placeholder
	if (!ServerSecret.IsEmpty())
	{
		return ServerSecret;
	}
	return TEXT("MySuperSecretKey");
}

FString UCombatServerSubsystem::GetKillmailEndpoint() const
{
	// Use configured endpoint or fallback to default
	if (!KillmailEndpoint.IsEmpty())
	{
		return GetApiBaseUrl() + KillmailEndpoint;
	}
	return GetApiBaseUrl() + TEXT("/api/combat/killmail");
}

bool UCombatServerSubsystem::IsDedicatedServer() const
{
	UWorld* World = GetWorld();
	if (!World)
	{
		return false;
	}
	return World->GetNetMode() == NM_DedicatedServer;
}

TSharedRef<IHttpRequest, ESPMode::ThreadSafe> UCombatServerSubsystem::CreateAuthenticatedRequest(
	const FString& Verb,
	const FString& Endpoint)
{
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = Http->CreateRequest();
	Request->SetVerb(Verb);
	Request->SetURL(Endpoint);
	
	// Add server secret header for authentication
	Request->SetHeader(TEXT("X-Server-Secret"), GetServerSecret());
	
	return Request;
}
