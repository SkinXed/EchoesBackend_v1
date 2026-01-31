// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesIdentitySubsystem.h"
#include "EchoesAuthSubsystem.h"
#include "HttpModule.h"
#include "Interfaces/IHttpResponse.h"
#include "JsonObjectConverter.h"
#include "Misc/ConfigCacheIni.h"

void UEchoesIdentitySubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	Http = &FHttpModule::Get();

	UE_LOG(LogTemp, Log, TEXT("EchoesIdentitySubsystem initialized"));
}

void UEchoesIdentitySubsystem::Deinitialize()
{
	Identity_ClearSelection();

	Super::Deinitialize();

	UE_LOG(LogTemp, Log, TEXT("EchoesIdentitySubsystem deinitialized"));
}

void UEchoesIdentitySubsystem::Identity_FetchCharacter(
	FOnCharacterDataReceived OnSuccess,
	FOnCharacterDataFailure OnFailure)
{
	// Get JWT token from Auth subsystem
	FString Token = GetAuthToken();
	if (Token.IsEmpty())
	{
		UE_LOG(LogTemp, Error, TEXT("Cannot fetch character: No valid JWT token"));
		OnFailure.ExecuteIfBound(TEXT("Not logged in"));
		return;
	}

	// Create HTTP request
	TSharedRef<IHttpRequest> Request = Http->CreateRequest();
	Request->SetVerb(TEXT("GET"));
	Request->SetURL(GetApiBaseUrl() + TEXT("/character/me"));
	Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	Request->SetHeader(TEXT("Authorization"), TEXT("Bearer ") + Token);

	// Bind response handler
	Request->OnProcessRequestComplete().BindUObject(
		this,
		&UEchoesIdentitySubsystem::OnCharacterDataReceived,
		OnSuccess,
		OnFailure);

	// Send request
	if (!Request->ProcessRequest())
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to send character data request"));
		OnFailure.ExecuteIfBound(TEXT("Failed to send request"));
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Fetching character data from backend..."));
	}
}

void UEchoesIdentitySubsystem::Identity_SelectCharacter(const FGuid& CharacterId)
{
	if (!CharacterId.IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("Attempted to select invalid character ID"));
		return;
	}

	// Update selected character ID
	SelectedCharacter.CharacterId = CharacterId;

	UE_LOG(LogTemp, Log, TEXT("Selected character: %s"), *CharacterId.ToString());

	// Broadcast delegate
	OnCharacterSelected.Broadcast();
}

void UEchoesIdentitySubsystem::Identity_ClearSelection()
{
	SelectedCharacter = FEchoesCharacter();
	UE_LOG(LogTemp, Log, TEXT("Character selection cleared"));
}

void UEchoesIdentitySubsystem::ServerRPC_NotifyCharacterReady(
	const FGuid& CharacterId,
	TFunction<void()> OnSuccess,
	TFunction<void(const FString&)> OnFailure)
{
	// This would typically notify the UE Server that a character is ready
	// For now, we'll just validate the character exists
	
	FString Token = GetAuthToken();
	if (Token.IsEmpty())
	{
		UE_LOG(LogTemp, Error, TEXT("Cannot notify character ready: No valid JWT token"));
		if (OnFailure)
		{
			OnFailure(TEXT("Not logged in"));
		}
		return;
	}

	// Create HTTP request to validate character
	TSharedRef<IHttpRequest> Request = Http->CreateRequest();
	Request->SetVerb(TEXT("GET"));
	Request->SetURL(GetApiBaseUrl() + FString::Printf(TEXT("/character/%s"), *CharacterId.ToString()));
	Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	Request->SetHeader(TEXT("Authorization"), TEXT("Bearer ") + Token);

	// Bind response handler
	Request->OnProcessRequestComplete().BindLambda(
		[OnSuccess, OnFailure](FHttpRequestPtr Req, FHttpResponsePtr Response, bool bWasSuccessful)
		{
			if (!bWasSuccessful || !Response.IsValid())
			{
				UE_LOG(LogTemp, Error, TEXT("Character ready notification failed"));
				if (OnFailure)
				{
					OnFailure(TEXT("Request failed"));
				}
				return;
			}

			if (Response->GetResponseCode() == 200)
			{
				UE_LOG(LogTemp, Log, TEXT("Character validated and ready"));
				if (OnSuccess)
				{
					OnSuccess();
				}
			}
			else
			{
				FString ErrorMsg = FString::Printf(TEXT("HTTP %d: %s"), 
					Response->GetResponseCode(), 
					*Response->GetContentAsString());
				UE_LOG(LogTemp, Error, TEXT("Character validation failed: %s"), *ErrorMsg);
				if (OnFailure)
				{
					OnFailure(ErrorMsg);
				}
			}
		});

	// Send request
	if (!Request->ProcessRequest())
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to send character ready notification"));
		if (OnFailure)
		{
			OnFailure(TEXT("Failed to send request"));
		}
	}
}

void UEchoesIdentitySubsystem::OnCharacterDataReceived(
	FHttpRequestPtr Request,
	FHttpResponsePtr Response,
	bool bWasSuccessful,
	FOnCharacterDataReceived OnSuccess,
	FOnCharacterDataFailure OnFailure)
{
	if (!bWasSuccessful || !Response.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Character data request failed"));
		OnFailure.ExecuteIfBound(TEXT("Request failed"));
		return;
	}

	int32 ResponseCode = Response->GetResponseCode();
	FString ResponseContent = Response->GetContentAsString();

	UE_LOG(LogTemp, Log, TEXT("Character data response: HTTP %d"), ResponseCode);

	if (ResponseCode == 200)
	{
		FEchoesCharacter CharacterData;
		if (ParseCharacterData(ResponseContent, CharacterData))
		{
			// Store selected character
			SelectedCharacter = CharacterData;
			SelectedCharacter.ISK = CharacterData.WalletBalance; // Alias for EVE-style

			UE_LOG(LogTemp, Log, TEXT("Successfully parsed character data: %s"), *CharacterData.Name);
			OnSuccess.ExecuteIfBound(CharacterData);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to parse character data"));
			OnFailure.ExecuteIfBound(TEXT("Failed to parse response"));
		}
	}
	else if (ResponseCode == 401)
	{
		UE_LOG(LogTemp, Error, TEXT("Unauthorized: Invalid or expired token"));
		OnFailure.ExecuteIfBound(TEXT("Authentication failed"));
	}
	else if (ResponseCode == 404)
	{
		UE_LOG(LogTemp, Error, TEXT("Character not found"));
		OnFailure.ExecuteIfBound(TEXT("Character not found"));
	}
	else
	{
		FString ErrorMsg = FString::Printf(TEXT("HTTP %d: %s"), ResponseCode, *ResponseContent);
		UE_LOG(LogTemp, Error, TEXT("Character data request failed: %s"), *ErrorMsg);
		OnFailure.ExecuteIfBound(ErrorMsg);
	}
}

bool UEchoesIdentitySubsystem::ParseCharacterData(const FString& JsonString, FEchoesCharacter& OutCharacter)
{
	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(JsonString);

	if (!FJsonSerializer::Deserialize(Reader, JsonObject) || !JsonObject.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to deserialize character JSON"));
		return false;
	}

	// Parse character data
	FString CharacterIdStr;
	if (JsonObject->TryGetStringField(TEXT("characterId"), CharacterIdStr))
	{
		FGuid::Parse(CharacterIdStr, OutCharacter.CharacterId);
	}

	JsonObject->TryGetStringField(TEXT("name"), OutCharacter.Name);

	FString AccountIdStr;
	if (JsonObject->TryGetStringField(TEXT("accountId"), AccountIdStr))
	{
		FGuid::Parse(AccountIdStr, OutCharacter.AccountId);
	}

	JsonObject->TryGetNumberField(TEXT("walletBalance"), OutCharacter.WalletBalance);
	OutCharacter.ISK = OutCharacter.WalletBalance; // Alias

	double SecurityStatusDouble = 0.0;
	if (JsonObject->TryGetNumberField(TEXT("securityStatus"), SecurityStatusDouble))
	{
		OutCharacter.SecurityStatus = static_cast<float>(SecurityStatusDouble);
	}

	JsonObject->TryGetNumberField(TEXT("currentShipId"), OutCharacter.CurrentShipId);

	FString CorporationIdStr;
	if (JsonObject->TryGetStringField(TEXT("corporationId"), CorporationIdStr))
	{
		FGuid::Parse(CorporationIdStr, OutCharacter.CorporationId);
	}

	int32 RaceIdInt = 0;
	if (JsonObject->TryGetNumberField(TEXT("raceId"), RaceIdInt))
	{
		OutCharacter.RaceId = RaceIdInt;
	}

	int32 TotalSkillPointsInt = 0;
	if (JsonObject->TryGetNumberField(TEXT("totalSkillPoints"), TotalSkillPointsInt))
	{
		OutCharacter.TotalSkillPoints = TotalSkillPointsInt;
	}

	int32 UnallocatedSkillPointsInt = 0;
	if (JsonObject->TryGetNumberField(TEXT("unallocatedSkillPoints"), UnallocatedSkillPointsInt))
	{
		OutCharacter.UnallocatedSkillPoints = UnallocatedSkillPointsInt;
	}

	JsonObject->TryGetBoolField(TEXT("isOnline"), OutCharacter.IsOnline);
	JsonObject->TryGetBoolField(TEXT("isDocked"), OutCharacter.IsDocked);
	JsonObject->TryGetBoolField(TEXT("inWarp"), OutCharacter.InWarp);

	FString LastLoginStr;
	if (JsonObject->TryGetStringField(TEXT("lastLogin"), LastLoginStr))
	{
		FDateTime::ParseIso8601(*LastLoginStr, OutCharacter.LastLogin);
	}

	// Portrait URL might not be in the response, but we'll support it
	JsonObject->TryGetStringField(TEXT("portraitURL"), OutCharacter.PortraitURL);

	return true;
}

FString UEchoesIdentitySubsystem::GetAuthToken() const
{
	// Get Auth subsystem from same game instance
	auto AuthSubsystem = GetGameInstance()->GetSubsystem<UEchoesAuthSubsystem>();
	if (AuthSubsystem)
	{
		return AuthSubsystem->Auth_GetToken();
	}

	UE_LOG(LogTemp, Error, TEXT("Auth subsystem not found"));
	return FString();
}

FString UEchoesIdentitySubsystem::GetApiBaseUrl() const
{
	FString ApiBaseUrl;
	if (GConfig)
	{
		GConfig->GetString(
			TEXT("/Script/Echoes.EchoesAuthSubsystem"),
			TEXT("ApiBaseUrl"),
			ApiBaseUrl,
			GGameIni);
	}

	if (ApiBaseUrl.IsEmpty())
	{
		ApiBaseUrl = TEXT("http://localhost:5116/api");
		UE_LOG(LogTemp, Warning, TEXT("Using default API base URL: %s"), *ApiBaseUrl);
	}

	return ApiBaseUrl;
}

// ==================== UI Wrapper Functions ====================

void UEchoesIdentitySubsystem::UI_CreateCharacter(
	const FString& CharacterName,
	const FString& Race,
	int32 PortraitId,
	FOnIdentityCharacterCreated OnSuccess,
	FOnCharacterDataFailure OnFailure)
{
	if (!Http)
	{
		UE_LOG(LogTemp, Error, TEXT("EchoesIdentitySubsystem: HTTP module not initialized"));
		OnFailure.ExecuteIfBound(TEXT("HTTP module not initialized"));
		return;
	}

	// Get JWT token from Auth subsystem
	FString Token = GetAuthToken();
	if (Token.IsEmpty())
	{
		UE_LOG(LogTemp, Error, TEXT("EchoesIdentitySubsystem: No JWT token available"));
		OnFailure.ExecuteIfBound(TEXT("Not authenticated"));
		return;
	}

	// Validate input
	if (CharacterName.IsEmpty() || CharacterName.Len() < 3)
	{
		UE_LOG(LogTemp, Warning, TEXT("EchoesIdentitySubsystem: Character name too short"));
		OnFailure.ExecuteIfBound(TEXT("Character name must be at least 3 characters"));
		return;
	}

	// Validate race
	TArray<FString> ValidRaces = { TEXT("Caldari"), TEXT("Gallente"), TEXT("Amarr"), TEXT("Minmatar") };
	if (!ValidRaces.Contains(Race))
	{
		UE_LOG(LogTemp, Warning, TEXT("EchoesIdentitySubsystem: Invalid race: %s"), *Race);
		OnFailure.ExecuteIfBound(TEXT("Invalid race selection"));
		return;
	}

	// Prepare request URL
	FString ApiUrl = GetApiBaseUrl();
	FString Url = FString::Printf(TEXT("%s/character"), *ApiUrl);

	// Create HTTP request
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = Http->CreateRequest();
	Request->SetVerb(TEXT("POST"));
	Request->SetURL(Url);
	Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	Request->SetHeader(TEXT("Authorization"), FString::Printf(TEXT("Bearer %s"), *Token));

	// Prepare request body
	FString RequestBody = FString::Printf(
		TEXT("{\"name\":\"%s\",\"race\":\"%s\",\"portraitId\":%d}"),
		*CharacterName, *Race, PortraitId);
	Request->SetContentAsString(RequestBody);

	// Bind response handler
	Request->OnProcessRequestComplete().BindUObject(
		this,
		&UEchoesIdentitySubsystem::OnCharacterCreationReceived,
		OnSuccess,
		OnFailure);

	// Send request
	if (Request->ProcessRequest())
	{
		UE_LOG(LogTemp, Log, TEXT("EchoesIdentitySubsystem: Creating character '%s' with race %s"),
			*CharacterName, *Race);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("EchoesIdentitySubsystem: Failed to send character creation request"));
		OnFailure.ExecuteIfBound(TEXT("Failed to send request"));
	}
}

void UEchoesIdentitySubsystem::OnCharacterCreationReceived(
	FHttpRequestPtr Request,
	FHttpResponsePtr Response,
	bool bWasSuccessful,
	FOnIdentityCharacterCreated OnSuccess,
	FOnCharacterDataFailure OnFailure)
{
	if (!bWasSuccessful || !Response.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("EchoesIdentitySubsystem: Character creation request failed"));
		OnFailure.ExecuteIfBound(TEXT("Request failed"));
		return;
	}

	int32 ResponseCode = Response->GetResponseCode();
	FString ResponseContent = Response->GetContentAsString();

	UE_LOG(LogTemp, Log, TEXT("EchoesIdentitySubsystem: Character creation response: %d - %s"),
		ResponseCode, *ResponseContent);

	if (ResponseCode == 201) // Created
	{
		// Parse character data from response
		FEchoesCharacter NewCharacter;
		if (ParseCharacterData(ResponseContent, NewCharacter))
		{
			// Automatically select the new character
			SelectedCharacter = NewCharacter;

			UE_LOG(LogTemp, Log, TEXT("EchoesIdentitySubsystem: Character '%s' created successfully with ID %s"),
				*NewCharacter.Name, *NewCharacter.CharacterId.ToString());

			// Call success callback
			OnSuccess.ExecuteIfBound(NewCharacter);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("EchoesIdentitySubsystem: Failed to parse character creation response"));
			OnFailure.ExecuteIfBound(TEXT("Failed to parse response"));
		}
	}
	else if (ResponseCode == 400)
	{
		UE_LOG(LogTemp, Warning, TEXT("EchoesIdentitySubsystem: Invalid character creation request: %s"), *ResponseContent);
		OnFailure.ExecuteIfBound(TEXT("Invalid character data (name may be taken)"));
	}
	else if (ResponseCode == 401)
	{
		UE_LOG(LogTemp, Warning, TEXT("EchoesIdentitySubsystem: Unauthorized - token may be expired"));
		OnFailure.ExecuteIfBound(TEXT("Unauthorized"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("EchoesIdentitySubsystem: Unexpected response code: %d"), ResponseCode);
		OnFailure.ExecuteIfBound(FString::Printf(TEXT("Server error: %d"), ResponseCode));
	}
}
