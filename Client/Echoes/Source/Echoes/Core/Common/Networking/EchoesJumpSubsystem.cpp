// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesJumpSubsystem.h"
#include "EchoesPersistenceSubsystem.h"
#include "HttpModule.h"
#include "Interfaces/IHttpResponse.h"
#include "JsonObjectConverter.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

void UEchoesJumpSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	// Load configuration from DefaultGame.ini
	ApiBaseUrl = TEXT("http://localhost:5116/api");
	ServerSecret = TEXT("UE5-Server-Secret-Change-Me-In-Production");
	bEnableDebugLogging = true;

	UE_LOG(LogTemp, Log, TEXT("UEchoesJumpSubsystem initialized - API: %s"), *ApiBaseUrl);
}

void UEchoesJumpSubsystem::Deinitialize()
{
	UE_LOG(LogTemp, Log, TEXT("UEchoesJumpSubsystem deinitialized"));
	Super::Deinitialize();
}

void UEchoesJumpSubsystem::ServerOnly_RequestJump(
	FGuid CharacterId,
	FGuid StargateId,
	FGuid SourceSystemId,
	FGuid DestinationSystemId,
	APawn* PlayerPawn)
{
	// This should only be called on the server
	if (!GetWorld() || !GetWorld()->IsServer())
	{
		UE_LOG(LogTemp, Error, TEXT("ServerOnly_RequestJump called on client! This is a server-only function."));
		return;
	}

	if (!CharacterId.IsValid() || !StargateId.IsValid() || !DestinationSystemId.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("ServerOnly_RequestJump called with invalid GUIDs"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("ServerOnly_RequestJump - Character: %s, Stargate: %s, Destination: %s"),
		*CharacterId.ToString(), *StargateId.ToString(), *DestinationSystemId.ToString());

	// Step 1: Save character state immediately before jump
	// This ensures the destination server has the latest state
	if (PlayerPawn)
	{
		if (!SaveCharacterStateBeforeJump(CharacterId, PlayerPawn))
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to save character state before jump - proceeding anyway"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No pawn provided for state save before jump"));
	}

	// Step 2: Request jump ticket from backend
	FJumpRequestData RequestData;
	RequestData.CharacterId = CharacterId;
	RequestData.StargateId = StargateId;
	RequestData.SourceSystemId = SourceSystemId;
	RequestData.DestinationSystemId = DestinationSystemId;

	SendJumpRequest(RequestData, PlayerPawn);
}

void UEchoesJumpSubsystem::SendJumpRequest(const FJumpRequestData& RequestData, APawn* PlayerPawn)
{
	// Create HTTP request
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = FHttpModule::Get().CreateRequest();

	// Build URL
	FString Url = FString::Printf(TEXT("%s/jump/request"), *ApiBaseUrl);
	HttpRequest->SetURL(Url);
	HttpRequest->SetVerb(TEXT("POST"));
	HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	HttpRequest->SetHeader(TEXT("X-Server-Secret"), ServerSecret);

	// Build JSON payload
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	JsonObject->SetStringField(TEXT("characterId"), RequestData.CharacterId.ToString());
	JsonObject->SetStringField(TEXT("stargateId"), RequestData.StargateId.ToString());
	JsonObject->SetStringField(TEXT("sourceSystemId"), RequestData.SourceSystemId.ToString());
	JsonObject->SetStringField(TEXT("destinationSystemId"), RequestData.DestinationSystemId.ToString());

	// Serialize JSON
	FString OutputString;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&OutputString);
	FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);

	HttpRequest->SetContentAsString(OutputString);

	// Bind callback
	HttpRequest->OnProcessRequestComplete().BindUObject(this, &UEchoesJumpSubsystem::OnJumpRequestComplete_Internal, PlayerPawn);

	// Send request
	if (!HttpRequest->ProcessRequest())
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to send jump request to %s"), *Url);
		
		// Broadcast failure
		FJumpResponseData FailureResponse;
		FailureResponse.bSuccess = false;
		FailureResponse.Message = TEXT("Failed to send request to backend");
		OnJumpRequestComplete.Broadcast(false, FailureResponse);
	}
	else
	{
		if (bEnableDebugLogging)
		{
			UE_LOG(LogTemp, Log, TEXT("Jump request sent to %s"), *Url);
		}
	}
}

void UEchoesJumpSubsystem::OnJumpRequestComplete_Internal(
	FHttpRequestPtr Request,
	FHttpResponsePtr Response,
	bool bWasSuccessful,
	APawn* PlayerPawn)
{
	FJumpResponseData ResponseData;

	if (!bWasSuccessful || !Response.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Jump request failed - no response from server"));
		ResponseData.bSuccess = false;
		ResponseData.Message = TEXT("No response from backend server");
		OnJumpRequestComplete.Broadcast(false, ResponseData);
		return;
	}

	const int32 ResponseCode = Response->GetResponseCode();
	const FString ResponseBody = Response->GetContentAsString();

	if (bEnableDebugLogging)
	{
		UE_LOG(LogTemp, Log, TEXT("Jump request response [%d]: %s"), ResponseCode, *ResponseBody);
	}

	// Parse JSON response
	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(ResponseBody);

	if (!FJsonSerializer::Deserialize(Reader, JsonObject) || !JsonObject.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to parse jump response JSON"));
		ResponseData.bSuccess = false;
		ResponseData.Message = TEXT("Invalid response format");
		OnJumpRequestComplete.Broadcast(false, ResponseData);
		return;
	}

	// Extract response data
	ResponseData.bSuccess = JsonObject->GetBoolField(TEXT("success"));
	ResponseData.Message = JsonObject->GetStringField(TEXT("message"));

	if (ResponseData.bSuccess)
	{
		// Jump approved - extract ticket and destination info
		ResponseData.TicketId = JsonObject->GetStringField(TEXT("ticketId"));
		ResponseData.DestinationServerAddress = JsonObject->GetStringField(TEXT("destinationServerAddress"));

		// Extract destination system info
		const TSharedPtr<FJsonObject>* DestSystemObj;
		if (JsonObject->TryGetObjectField(TEXT("destinationSystem"), DestSystemObj))
		{
			ResponseData.DestinationSystemName = (*DestSystemObj)->GetStringField(TEXT("systemName"));
		}

		UE_LOG(LogTemp, Log, TEXT("Jump approved! Ticket: %s, Destination: %s"),
			*ResponseData.TicketId, *ResponseData.DestinationServerAddress);

		// Build travel URL with ticket
		FString TravelURL = BuildTravelURL(ResponseData.DestinationServerAddress, ResponseData.TicketId);

		// Get player controller to send client RPC
		if (PlayerPawn)
		{
			APlayerController* PC = Cast<APlayerController>(PlayerPawn->GetController());
			if (PC)
			{
				// Send client RPC to initiate travel
				ClientRPC_TravelToSystem(TravelURL, ResponseData.TicketId, ResponseData.DestinationSystemName);

				// Broadcast success
				OnJumpRequestComplete.Broadcast(true, ResponseData);
				OnJumpInitiated.Broadcast(TravelURL, ResponseData.TicketId);
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("Failed to get player controller for client RPC"));
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("No pawn provided - cannot send client RPC"));
		}
	}
	else
	{
		// Jump denied
		if (JsonObject->HasField(TEXT("denialReason")))
		{
			ResponseData.DenialReason = JsonObject->GetStringField(TEXT("denialReason"));
		}

		UE_LOG(LogTemp, Warning, TEXT("Jump denied: %s (Reason: %s)"),
			*ResponseData.Message, *ResponseData.DenialReason);

		OnJumpRequestComplete.Broadcast(false, ResponseData);
	}
}

void UEchoesJumpSubsystem::ClientRPC_TravelToSystem_Implementation(
	const FString& TravelURL,
	const FString& TicketId,
	const FString& SystemName)
{
	UE_LOG(LogTemp, Log, TEXT("ClientRPC_TravelToSystem - Traveling to: %s (System: %s, Ticket: %s)"),
		*TravelURL, *SystemName, *TicketId);

	// Get player controller
	APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (PC)
	{
		// Initiate client travel to new server
		PC->ClientTravel(TravelURL, TRAVEL_Absolute);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to get player controller for client travel"));
	}
}

void UEchoesJumpSubsystem::ServerOnly_ValidateJumpTicket(
	const FString& TicketId,
	FGuid CharacterId,
	FGuid SystemId,
	const FOnJumpRequestComplete& OnComplete)
{
	// This should only be called on the server
	if (!GetWorld() || !GetWorld()->IsServer())
	{
		UE_LOG(LogTemp, Error, TEXT("ServerOnly_ValidateJumpTicket called on client!"));
		return;
	}

	if (TicketId.IsEmpty() || !CharacterId.IsValid() || !SystemId.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("ServerOnly_ValidateJumpTicket called with invalid parameters"));
		FJumpResponseData FailureResponse;
		FailureResponse.bSuccess = false;
		FailureResponse.Message = TEXT("Invalid validation parameters");
		OnComplete.ExecuteIfBound(false, FailureResponse);
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("ServerOnly_ValidateJumpTicket - Ticket: %s, Character: %s, System: %s"),
		*TicketId, *CharacterId.ToString(), *SystemId.ToString());

	SendTicketValidationRequest(TicketId, CharacterId, SystemId, OnComplete);
}

void UEchoesJumpSubsystem::SendTicketValidationRequest(
	const FString& TicketId,
	FGuid CharacterId,
	FGuid SystemId,
	const FOnJumpRequestComplete& Callback)
{
	// Create HTTP request
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = FHttpModule::Get().CreateRequest();

	// Build URL
	FString Url = FString::Printf(TEXT("%s/jump/redeem"), *ApiBaseUrl);
	HttpRequest->SetURL(Url);
	HttpRequest->SetVerb(TEXT("POST"));
	HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	HttpRequest->SetHeader(TEXT("X-Server-Secret"), ServerSecret);

	// Build JSON payload
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	JsonObject->SetStringField(TEXT("ticketId"), TicketId);
	JsonObject->SetStringField(TEXT("characterId"), CharacterId.ToString());
	JsonObject->SetStringField(TEXT("systemId"), SystemId.ToString());

	// Serialize JSON
	FString OutputString;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&OutputString);
	FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);

	HttpRequest->SetContentAsString(OutputString);

	// Bind callback
	HttpRequest->OnProcessRequestComplete().BindUObject(this, &UEchoesJumpSubsystem::OnTicketValidationComplete_Internal, Callback);

	// Send request
	if (!HttpRequest->ProcessRequest())
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to send ticket validation request to %s"), *Url);
		
		FJumpResponseData FailureResponse;
		FailureResponse.bSuccess = false;
		FailureResponse.Message = TEXT("Failed to send validation request");
		Callback.ExecuteIfBound(false, FailureResponse);
	}
	else
	{
		if (bEnableDebugLogging)
		{
			UE_LOG(LogTemp, Log, TEXT("Ticket validation request sent to %s"), *Url);
		}
	}
}

void UEchoesJumpSubsystem::OnTicketValidationComplete_Internal(
	FHttpRequestPtr Request,
	FHttpResponsePtr Response,
	bool bWasSuccessful,
	FOnJumpRequestComplete Callback)
{
	FJumpResponseData ResponseData;

	if (!bWasSuccessful || !Response.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Ticket validation failed - no response from server"));
		ResponseData.bSuccess = false;
		ResponseData.Message = TEXT("No response from backend server");
		Callback.ExecuteIfBound(false, ResponseData);
		return;
	}

	const int32 ResponseCode = Response->GetResponseCode();
	const FString ResponseBody = Response->GetContentAsString();

	if (bEnableDebugLogging)
	{
		UE_LOG(LogTemp, Log, TEXT("Ticket validation response [%d]: %s"), ResponseCode, *ResponseBody);
	}

	// Parse JSON response
	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(ResponseBody);

	if (!FJsonSerializer::Deserialize(Reader, JsonObject) || !JsonObject.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to parse validation response JSON"));
		ResponseData.bSuccess = false;
		ResponseData.Message = TEXT("Invalid response format");
		Callback.ExecuteIfBound(false, ResponseData);
		return;
	}

	// Extract validation result
	ResponseData.bSuccess = JsonObject->GetBoolField(TEXT("valid"));
	ResponseData.Message = JsonObject->GetStringField(TEXT("message"));

	if (ResponseData.bSuccess)
	{
		UE_LOG(LogTemp, Log, TEXT("Ticket validated successfully: %s"), *ResponseData.Message);
	}
	else
	{
		if (JsonObject->HasField(TEXT("invalidReason")))
		{
			ResponseData.DenialReason = JsonObject->GetStringField(TEXT("invalidReason"));
		}
		UE_LOG(LogTemp, Warning, TEXT("Ticket validation failed: %s (Reason: %s)"),
			*ResponseData.Message, *ResponseData.DenialReason);
	}

	Callback.ExecuteIfBound(ResponseData.bSuccess, ResponseData);
}

FString UEchoesJumpSubsystem::BuildTravelURL(const FString& ServerAddress, const FString& TicketId) const
{
	// Format: IP:Port?Ticket=GUID
	return FString::Printf(TEXT("%s?Ticket=%s"), *ServerAddress, *TicketId);
}

bool UEchoesJumpSubsystem::SaveCharacterStateBeforeJump(FGuid CharacterId, APawn* PlayerPawn)
{
	// Get persistence subsystem
	UEchoesPersistenceSubsystem* PersistenceSubsystem = GetGameInstance()->GetSubsystem<UEchoesPersistenceSubsystem>();
	if (!PersistenceSubsystem)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to get persistence subsystem"));
		return false;
	}

	// Get persistence component from pawn
	// Note: The actual implementation would need to collect state from the ship/pawn
	// For now, we'll just call the subsystem's immediate save method
	// This is a placeholder - actual implementation needs to collect state data

	UE_LOG(LogTemp, Log, TEXT("Saving character state before jump for character: %s"), *CharacterId.ToString());

	// TODO: Collect actual state data from pawn components
	// This would typically involve:
	// 1. Get position/rotation from pawn
	// 2. Get stats from ship state component
	// 3. Build FCommon_StateData struct
	// 4. Call PersistenceSubsystem->ServerOnly_SaveStateImmediate(CharacterId, StateData)

	// For now, we just log the attempt
	UE_LOG(LogTemp, Warning, TEXT("State save before jump - implementation requires state collection from pawn components"));

	return true; // Return true to not block jumps during development
}
