// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesAuthSubsystem.h"
#include "HttpModule.h"
#include "Interfaces/IHttpResponse.h"
#include "Json.h"
#include "JsonUtilities.h"
#include "Misc/ConfigCacheIni.h"

void UEchoesAuthSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	// Get HTTP module
	Http = &FHttpModule::Get();

	UE_LOG(LogTemp, Log, TEXT("EchoesAuthSubsystem initialized"));
}

void UEchoesAuthSubsystem::Deinitialize()
{
	Super::Deinitialize();

	// Clear sensitive data
	JWTToken.Empty();
	CurrentAuthResponse = FAuthResponse();

	UE_LOG(LogTemp, Log, TEXT("EchoesAuthSubsystem deinitialized"));
}

// ==================== Auth Functions ====================

void UEchoesAuthSubsystem::Auth_Login(
	const FAuthRequest& Request,
	FOnLoginSuccess OnSuccess,
	FOnLoginFailure OnFailure)
{
	if (!Http)
	{
		UE_LOG(LogTemp, Error, TEXT("HTTP module not available"));
		OnFailure.ExecuteIfBound(TEXT("HTTP module not available"));
		return;
	}

	// Create HTTP request
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = Http->CreateRequest();
	HttpRequest->SetVerb(TEXT("POST"));
	HttpRequest->SetURL(GetApiBaseUrl() + TEXT("/auth/login"));
	HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));

	// Create JSON payload
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	JsonObject->SetStringField(TEXT("emailOrUsername"), Request.EmailOrUsername);
	JsonObject->SetStringField(TEXT("password"), Request.Password);

	FString JsonString;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&JsonString);
	FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);

	HttpRequest->SetContentAsString(JsonString);

	// Bind response handler
	HttpRequest->OnProcessRequestComplete().BindUObject(
		this,
		&UEchoesAuthSubsystem::OnLoginResponseReceived,
		OnSuccess,
		OnFailure);

	// Send request
	if (!HttpRequest->ProcessRequest())
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to process login request"));
		OnFailure.ExecuteIfBound(TEXT("Failed to send request"));
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Login request sent to: %s"), *HttpRequest->GetURL());
	}
}

void UEchoesAuthSubsystem::Auth_Register(
	const FString& Username,
	const FString& Email,
	const FString& Password,
	FOnRegisterSuccess OnSuccess,
	FOnRegisterFailure OnFailure)
{
	if (!Http)
	{
		UE_LOG(LogTemp, Error, TEXT("HTTP module not available"));
		OnFailure.ExecuteIfBound(TEXT("HTTP module not available"));
		return;
	}

	// Create HTTP request
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = Http->CreateRequest();
	HttpRequest->SetVerb(TEXT("POST"));
	HttpRequest->SetURL(GetApiBaseUrl() + TEXT("/auth/register"));
	HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));

	// Create JSON payload
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	JsonObject->SetStringField(TEXT("username"), Username);
	JsonObject->SetStringField(TEXT("email"), Email);
	JsonObject->SetStringField(TEXT("password"), Password);

	FString JsonString;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&JsonString);
	FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);

	HttpRequest->SetContentAsString(JsonString);

	// Bind response handler
	HttpRequest->OnProcessRequestComplete().BindUObject(
		this,
		&UEchoesAuthSubsystem::OnRegisterResponseReceived,
		OnSuccess,
		OnFailure);

	// Send request
	if (!HttpRequest->ProcessRequest())
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to process registration request"));
		OnFailure.ExecuteIfBound(TEXT("Failed to send request"));
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Registration request sent to: %s"), *HttpRequest->GetURL());
	}
}

void UEchoesAuthSubsystem::Auth_Logout()
{
	UE_LOG(LogTemp, Log, TEXT("User logged out - clearing in-memory token"));

	// Clear token and session data from memory only
	JWTToken.Empty();
	CurrentAuthResponse = FAuthResponse();
}

void UEchoesAuthSubsystem::ServerRPC_VerifySession(
	const FGuid& CharacterId,
	TFunction<void(const FCharacterData&)> OnSuccess,
	TFunction<void(const FString&)> OnFailure)
{
	if (!Http)
	{
		UE_LOG(LogTemp, Error, TEXT("HTTP module not available"));
		if (OnFailure)
		{
			OnFailure(TEXT("HTTP module not available"));
		}
		return;
	}

	// Create HTTP request
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = Http->CreateRequest();
	HttpRequest->SetVerb(TEXT("GET"));
	HttpRequest->SetURL(GetApiBaseUrl() + FString::Printf(TEXT("/character/%s"), *CharacterId.ToString()));
	HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	HttpRequest->SetHeader(TEXT("X-Server-Secret"), GetServerSecret());
	HttpRequest->SetHeader(TEXT("Authorization"), TEXT("Bearer ") + JWTToken);

	// Bind response handler
	HttpRequest->OnProcessRequestComplete().BindUObject(
		this,
		&UEchoesAuthSubsystem::OnVerifySessionResponseReceived,
		OnSuccess,
		OnFailure);

	// Send request
	if (!HttpRequest->ProcessRequest())
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to process session verification request"));
		if (OnFailure)
		{
			OnFailure(TEXT("Failed to send request"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Session verification request sent for character: %s"), *CharacterId.ToString());
	}
}

// ==================== HTTP Response Handlers ====================

void UEchoesAuthSubsystem::OnLoginResponseReceived(
	FHttpRequestPtr Request,
	FHttpResponsePtr Response,
	bool bWasSuccessful,
	FOnLoginSuccess OnSuccess,
	FOnLoginFailure OnFailure)
{
	if (!bWasSuccessful || !Response.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Login request failed"));
		OnFailure.ExecuteIfBound(TEXT("Request failed"));
		return;
	}

	const int32 ResponseCode = Response->GetResponseCode();
	const FString ResponseBody = Response->GetContentAsString();

	UE_LOG(LogTemp, Log, TEXT("Login response received: Code=%d, Body=%s"), ResponseCode, *ResponseBody);

	if (ResponseCode == 200)
	{
		// Parse response
		FAuthResponse AuthResponse;
		if (ParseAuthResponse(ResponseBody, AuthResponse))
		{
			// Store token and session data
			JWTToken = AuthResponse.Token;
			CurrentAuthResponse = AuthResponse;

			UE_LOG(LogTemp, Log, TEXT("Login successful! AccountId=%s, CharacterId=%s, Characters=%d"),
				*AuthResponse.AccountId.ToString(),
				*AuthResponse.CharacterId.ToString(),
				AuthResponse.Characters.Num());

			OnSuccess.ExecuteIfBound(AuthResponse);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to parse login response"));
			OnFailure.ExecuteIfBound(TEXT("Failed to parse response"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Login failed with code: %d"), ResponseCode);
		OnFailure.ExecuteIfBound(FString::Printf(TEXT("Login failed: %d"), ResponseCode));
	}
}

void UEchoesAuthSubsystem::OnRegisterResponseReceived(
	FHttpRequestPtr Request,
	FHttpResponsePtr Response,
	bool bWasSuccessful,
	FOnRegisterSuccess OnSuccess,
	FOnRegisterFailure OnFailure)
{
	if (!bWasSuccessful || !Response.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Registration request failed"));
		OnFailure.ExecuteIfBound(TEXT("Request failed"));
		return;
	}

	const int32 ResponseCode = Response->GetResponseCode();
	const FString ResponseBody = Response->GetContentAsString();

	UE_LOG(LogTemp, Log, TEXT("Registration response received: Code=%d, Body=%s"), ResponseCode, *ResponseBody);

	if (ResponseCode == 200)
	{
		// Parse response
		FAuthResponse AuthResponse;
		if (ParseAuthResponse(ResponseBody, AuthResponse))
		{
			// Store token and session data
			JWTToken = AuthResponse.Token;
			CurrentAuthResponse = AuthResponse;

			UE_LOG(LogTemp, Log, TEXT("Registration successful! AccountId=%s, CharacterId=%s"),
				*AuthResponse.AccountId.ToString(),
				*AuthResponse.CharacterId.ToString());

			OnSuccess.ExecuteIfBound(AuthResponse);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to parse registration response"));
			OnFailure.ExecuteIfBound(TEXT("Failed to parse response"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Registration failed with code: %d"), ResponseCode);
		OnFailure.ExecuteIfBound(FString::Printf(TEXT("Registration failed: %d"), ResponseCode));
	}
}

void UEchoesAuthSubsystem::OnVerifySessionResponseReceived(
	FHttpRequestPtr Request,
	FHttpResponsePtr Response,
	bool bWasSuccessful,
	TFunction<void(const FCharacterData&)> OnSuccess,
	TFunction<void(const FString&)> OnFailure)
{
	if (!bWasSuccessful || !Response.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Session verification request failed"));
		if (OnFailure)
		{
			OnFailure(TEXT("Request failed"));
		}
		return;
	}

	const int32 ResponseCode = Response->GetResponseCode();
	const FString ResponseBody = Response->GetContentAsString();

	UE_LOG(LogTemp, Log, TEXT("Session verification response: Code=%d"), ResponseCode);

	if (ResponseCode == 200)
	{
		// Parse character data
		FCharacterData CharacterData;
		if (ParseCharacterData(ResponseBody, CharacterData))
		{
			UE_LOG(LogTemp, Log, TEXT("Session verified! Character=%s"), *CharacterData.Name);

			if (OnSuccess)
			{
				OnSuccess(CharacterData);
			}
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to parse character data"));
			if (OnFailure)
			{
				OnFailure(TEXT("Failed to parse response"));
			}
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Session verification failed with code: %d"), ResponseCode);
		if (OnFailure)
		{
			OnFailure(FString::Printf(TEXT("Verification failed: %d"), ResponseCode));
		}
	}
}

// ==================== Helper Functions ====================

bool UEchoesAuthSubsystem::ParseAuthResponse(const FString& JsonString, FAuthResponse& OutResponse)
{
	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(JsonString);

	if (!FJsonSerializer::Deserialize(Reader, JsonObject) || !JsonObject.IsValid())
	{
		return false;
	}

	// Parse basic fields
	OutResponse.Success = JsonObject->GetBoolField(TEXT("success"));
	OutResponse.Token = JsonObject->GetStringField(TEXT("token"));
	
	FGuid::Parse(JsonObject->GetStringField(TEXT("accountId")), OutResponse.AccountId);
	FGuid::Parse(JsonObject->GetStringField(TEXT("characterId")), OutResponse.CharacterId);
	
	OutResponse.CharacterName = JsonObject->GetStringField(TEXT("characterName"));
	
	FGuid::Parse(JsonObject->GetStringField(TEXT("sessionId")), OutResponse.SessionId);
	
	FDateTime::Parse(JsonObject->GetStringField(TEXT("expiresAt")), OutResponse.ExpiresAt);

	// Parse characters array
	const TArray<TSharedPtr<FJsonValue>>* CharactersArray;
	if (JsonObject->TryGetArrayField(TEXT("characters"), CharactersArray))
	{
		for (const TSharedPtr<FJsonValue>& CharValue : *CharactersArray)
		{
			const TSharedPtr<FJsonObject>& CharObj = CharValue->AsObject();
			if (CharObj.IsValid())
			{
				FCharacterInfo CharInfo;
				FGuid::Parse(CharObj->GetStringField(TEXT("characterId")), CharInfo.CharacterId);
				CharInfo.Name = CharObj->GetStringField(TEXT("name"));
				if (CharObj->HasField(TEXT("raceId")))
				{
					CharInfo.RaceId = CharObj->GetIntegerField(TEXT("raceId"));
				}
				if (CharObj->HasField(TEXT("raceName")))
				{
					CharInfo.RaceName = CharObj->GetStringField(TEXT("raceName"));
				}
				CharInfo.WalletBalance = CharObj->GetNumberField(TEXT("walletBalance"));
				CharInfo.Credits = CharObj->HasField(TEXT("credits"))
					? CharObj->GetNumberField(TEXT("credits"))
					: CharInfo.WalletBalance;
				if (CharObj->HasField(TEXT("totalSkillPoints")))
				{
					CharInfo.ExperiencePoints = CharObj->GetIntegerField(TEXT("totalSkillPoints"));
				}
				
				if (CharObj->HasField(TEXT("currentShipId")) && !CharObj->GetField<EJson::None>(TEXT("currentShipId"))->IsNull())
				{
					CharInfo.CurrentShipId = CharObj->GetNumberField(TEXT("currentShipId"));
				}
				
				CharInfo.IsMain = CharObj->GetBoolField(TEXT("isMain"));
				CharInfo.IsOnline = CharObj->GetBoolField(TEXT("isOnline"));

				OutResponse.Characters.Add(CharInfo);
			}
		}
	}

	return true;
}

bool UEchoesAuthSubsystem::ParseCharacterData(const FString& JsonString, FCharacterData& OutData)
{
	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(JsonString);

	if (!FJsonSerializer::Deserialize(Reader, JsonObject) || !JsonObject.IsValid())
	{
		return false;
	}

	// Parse fields
	FGuid::Parse(JsonObject->GetStringField(TEXT("characterId")), OutData.CharacterId);
	OutData.Name = JsonObject->GetStringField(TEXT("name"));
	FGuid::Parse(JsonObject->GetStringField(TEXT("accountId")), OutData.AccountId);
	OutData.WalletBalance = JsonObject->GetNumberField(TEXT("walletBalance"));
	OutData.Credits = JsonObject->HasField(TEXT("credits"))
		? JsonObject->GetNumberField(TEXT("credits"))
		: OutData.WalletBalance;
	OutData.SecurityStatus = JsonObject->GetNumberField(TEXT("securityStatus"));
	
	if (JsonObject->HasField(TEXT("currentShipId")) && !JsonObject->GetField<EJson::None>(TEXT("currentShipId"))->IsNull())
	{
		OutData.CurrentShipId = JsonObject->GetNumberField(TEXT("currentShipId"));
	}
	
	if (JsonObject->HasField(TEXT("corporationId")))
	{
		FGuid::Parse(JsonObject->GetStringField(TEXT("corporationId")), OutData.CorporationId);
	}
	
	OutData.RaceId = JsonObject->GetIntegerField(TEXT("raceId"));
	OutData.TotalSkillPoints = JsonObject->GetIntegerField(TEXT("totalSkillPoints"));
	OutData.ExperiencePoints = OutData.TotalSkillPoints;
	OutData.UnallocatedSkillPoints = JsonObject->GetIntegerField(TEXT("unallocatedSkillPoints"));
	OutData.IsOnline = JsonObject->GetBoolField(TEXT("isOnline"));
	OutData.IsDocked = JsonObject->GetBoolField(TEXT("isDocked"));
	OutData.InWarp = JsonObject->GetBoolField(TEXT("inWarp"));

	if (JsonObject->HasField(TEXT("lastLogin")) && !JsonObject->GetField<EJson::None>(TEXT("lastLogin"))->IsNull())
	{
		FDateTime::Parse(JsonObject->GetStringField(TEXT("lastLogin")), OutData.LastLogin);
	}

	return true;
}

FString UEchoesAuthSubsystem::GetApiBaseUrl() const
{
	FString ApiBaseUrl;
	
	// Try to read from config
	if (GConfig->GetString(
		TEXT("/Script/Echoes.EchoesAuthSubsystem"),
		TEXT("ApiBaseUrl"),
		ApiBaseUrl,
		GGameIni))
	{
		return ApiBaseUrl;
	}

	// Default to localhost
	return TEXT("http://localhost:5116/api");
}

FString UEchoesAuthSubsystem::GetServerSecret() const
{
	FString ServerSecret;
	
	// Try to read from config
	if (GConfig->GetString(
		TEXT("/Script/Echoes.EchoesAuthSubsystem"),
		TEXT("ServerSecret"),
		ServerSecret,
		GGameIni))
	{
		return ServerSecret;
	}

	// Default secret (should be changed in production)
	return TEXT("UE5-Server-Secret-Change-Me-In-Production");
}

// ==================== Character Operations ====================

void UEchoesAuthSubsystem::CreateCharacter(const FString& CharacterName, int32 RaceId)
{
	if (!Http)
	{
		UE_LOG(LogTemp, Error, TEXT("HTTP module not available"));
		OnCharacterCreationFailed.Broadcast(TEXT("HTTP module not available"));
		return;
	}

	if (JWTToken.IsEmpty())
	{
		UE_LOG(LogTemp, Error, TEXT("Not authenticated"));
		OnCharacterCreationFailed.Broadcast(TEXT("Not authenticated"));
		return;
	}

	// Create HTTP request
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = Http->CreateRequest();
	HttpRequest->SetVerb(TEXT("POST"));
	HttpRequest->SetURL(GetApiBaseUrl() + TEXT("/character"));
	HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	HttpRequest->SetHeader(TEXT("Authorization"), FString::Printf(TEXT("Bearer %s"), *JWTToken));

	// Create JSON body
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());
	JsonObject->SetStringField(TEXT("name"), CharacterName);
	JsonObject->SetNumberField(TEXT("raceId"), RaceId);
	JsonObject->SetNumberField(TEXT("portraitId"), 1);

	FString JsonString;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&JsonString);
	FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);

	HttpRequest->SetContentAsString(JsonString);

	// Bind response callback
	HttpRequest->OnProcessRequestComplete().BindUObject(
		this,
		&UEchoesAuthSubsystem::OnCreateCharacterResponseReceived);

	// Send request
	HttpRequest->ProcessRequest();
	UE_LOG(LogTemp, Log, TEXT("Creating character: %s (RaceId: %d)"), *CharacterName, RaceId);
}

void UEchoesAuthSubsystem::DeleteCharacter(const FGuid& CharacterId)
{
	if (!Http)
	{
		UE_LOG(LogTemp, Error, TEXT("HTTP module not available"));
		OnCharacterDeletionFailed.Broadcast(TEXT("HTTP module not available"));
		return;
	}

	if (JWTToken.IsEmpty())
	{
		UE_LOG(LogTemp, Error, TEXT("Not authenticated"));
		OnCharacterDeletionFailed.Broadcast(TEXT("Not authenticated"));
		return;
	}

	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = Http->CreateRequest();
	HttpRequest->SetVerb(TEXT("DELETE"));
	HttpRequest->SetURL(GetApiBaseUrl() + FString::Printf(TEXT("/character/%s"), *CharacterId.ToString()));
	HttpRequest->SetHeader(TEXT("Authorization"), FString::Printf(TEXT("Bearer %s"), *JWTToken));

	HttpRequest->OnProcessRequestComplete().BindUObject(
		this,
		&UEchoesAuthSubsystem::OnDeleteCharacterResponseReceived,
		CharacterId);

	HttpRequest->ProcessRequest();
	UE_LOG(LogTemp, Log, TEXT("Deleting character: %s"), *CharacterId.ToString());
}

void UEchoesAuthSubsystem::OnCreateCharacterResponseReceived(
	FHttpRequestPtr Request,
	FHttpResponsePtr Response,
	bool bWasSuccessful)
{
	if (!bWasSuccessful || !Response.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Character creation request failed"));
		OnCharacterCreationFailed.Broadcast(TEXT("Network error"));
		return;
	}

	int32 ResponseCode = Response->GetResponseCode();
	FString ResponseContent = Response->GetContentAsString();

	if (ResponseCode == 201 || ResponseCode == 200)
	{
		// Parse character data
		TSharedPtr<FJsonObject> JsonObject;
		TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(ResponseContent);

		if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
		{
			FCharacterData CharacterData;
			if (ParseCharacterData(ResponseContent, CharacterData))
			{
				UE_LOG(LogTemp, Log, TEXT("Character created successfully: %s"), *CharacterData.Name);
				OnCharacterCreated.Broadcast(CharacterData);
				
				// Refresh character list
				FetchCharacterList();
			}
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Character creation failed: %d - %s"), ResponseCode, *ResponseContent);
		
		// Try to parse error message
		TSharedPtr<FJsonObject> JsonObject;
		TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(ResponseContent);
		FString ErrorMsg = TEXT("Character creation failed");
		
		if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
		{
			if (JsonObject->HasField(TEXT("error")))
			{
				ErrorMsg = JsonObject->GetStringField(TEXT("error"));
			}
		}

		OnCharacterCreationFailed.Broadcast(ErrorMsg);
	}
}

void UEchoesAuthSubsystem::OnDeleteCharacterResponseReceived(
	FHttpRequestPtr Request,
	FHttpResponsePtr Response,
	bool bWasSuccessful,
	FGuid CharacterId)
{
	if (!bWasSuccessful || !Response.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Character deletion request failed"));
		OnCharacterDeletionFailed.Broadcast(TEXT("Network error"));
		return;
	}

	int32 ResponseCode = Response->GetResponseCode();
	FString ResponseContent = Response->GetContentAsString();

	if (ResponseCode == 200 || ResponseCode == 204)
	{
		CurrentAuthResponse.Characters.RemoveAll([CharacterId](const FCharacterInfo& Info)
		{
			return Info.CharacterId == CharacterId;
		});

		UE_LOG(LogTemp, Log, TEXT("Character deleted successfully: %s"), *CharacterId.ToString());
		OnCharacterDeleted.Broadcast(CharacterId);
		FetchCharacterList();
		return;
	}

	UE_LOG(LogTemp, Error, TEXT("Character deletion failed: %d - %s"), ResponseCode, *ResponseContent);

	FString ErrorMsg = TEXT("Character deletion failed");
	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(ResponseContent);
	if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
	{
		if (JsonObject->HasField(TEXT("error")))
		{
			ErrorMsg = JsonObject->GetStringField(TEXT("error"));
		}
	}

	OnCharacterDeletionFailed.Broadcast(ErrorMsg);
}

void UEchoesAuthSubsystem::FetchCharacterList()
{
	if (!Http)
	{
		UE_LOG(LogTemp, Error, TEXT("HTTP module not available"));
		return;
	}

	if (JWTToken.IsEmpty())
	{
		UE_LOG(LogTemp, Error, TEXT("Not authenticated"));
		return;
	}

	// Create HTTP request
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = Http->CreateRequest();
	HttpRequest->SetVerb(TEXT("GET"));
	HttpRequest->SetURL(GetApiBaseUrl() + TEXT("/character/list"));
	HttpRequest->SetHeader(TEXT("Authorization"), FString::Printf(TEXT("Bearer %s"), *JWTToken));

	// Bind response callback
	HttpRequest->OnProcessRequestComplete().BindUObject(
		this,
		&UEchoesAuthSubsystem::OnFetchCharacterListResponseReceived);

	// Send request
	HttpRequest->ProcessRequest();
	UE_LOG(LogTemp, Log, TEXT("Fetching character list"));
}

void UEchoesAuthSubsystem::OnFetchCharacterListResponseReceived(
	FHttpRequestPtr Request,
	FHttpResponsePtr Response,
	bool bWasSuccessful)
{
	if (!bWasSuccessful || !Response.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Character list fetch failed"));
		return;
	}

	int32 ResponseCode = Response->GetResponseCode();
	FString ResponseContent = Response->GetContentAsString();

	if (ResponseCode == 200)
	{
		// Parse character array
		TArray<TSharedPtr<FJsonValue>> JsonArray;
		TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(ResponseContent);

		if (FJsonSerializer::Deserialize(Reader, JsonArray))
		{
			CurrentAuthResponse.Characters.Empty();

			for (const TSharedPtr<FJsonValue>& JsonValue : JsonArray)
			{
				TSharedPtr<FJsonObject> CharObj = JsonValue->AsObject();
				if (CharObj.IsValid())
				{
					FCharacterInfo CharInfo;
					
					FString CharIdStr = CharObj->GetStringField(TEXT("characterId"));
					FGuid::Parse(CharIdStr, CharInfo.CharacterId);
					
					CharInfo.Name = CharObj->GetStringField(TEXT("name"));
					if (CharObj->HasField(TEXT("raceId")))
					{
						CharInfo.RaceId = CharObj->GetIntegerField(TEXT("raceId"));
					}
					if (CharObj->HasField(TEXT("raceName")))
					{
						CharInfo.RaceName = CharObj->GetStringField(TEXT("raceName"));
					}
					CharInfo.WalletBalance = (int64)CharObj->GetNumberField(TEXT("walletBalance"));
					CharInfo.Credits = CharObj->HasField(TEXT("credits"))
						? (int64)CharObj->GetNumberField(TEXT("credits"))
						: CharInfo.WalletBalance;
					if (CharObj->HasField(TEXT("totalSkillPoints")))
					{
						CharInfo.ExperiencePoints = CharObj->GetIntegerField(TEXT("totalSkillPoints"));
					}
					CharInfo.IsMain = CharObj->GetBoolField(TEXT("isMain"));
					CharInfo.IsOnline = CharObj->GetBoolField(TEXT("isOnline"));
					if (CharObj->HasField(TEXT("currentShipId")) && !CharObj->GetField<EJson::None>(TEXT("currentShipId"))->IsNull())
					{
						CharInfo.CurrentShipId = CharObj->GetNumberField(TEXT("currentShipId"));
					}

					CurrentAuthResponse.Characters.Add(CharInfo);
				}
			}

			UE_LOG(LogTemp, Log, TEXT("Fetched %d characters"), CurrentAuthResponse.Characters.Num());
			OnCharacterListUpdated.Broadcast(CurrentAuthResponse.Characters);
		}
	}
}

void UEchoesAuthSubsystem::ConnectToWorld(const FGuid& CharacterId)
{
	if (!Http)
	{
		UE_LOG(LogTemp, Error, TEXT("HTTP module not available"));
		OnConnectInfoFailed.Broadcast(TEXT("HTTP module not available"));
		return;
	}

	if (JWTToken.IsEmpty())
	{
		UE_LOG(LogTemp, Error, TEXT("Not authenticated"));
		OnConnectInfoFailed.Broadcast(TEXT("Not authenticated"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("╔══════════════════════════════════════════════════════════╗"));
	UE_LOG(LogTemp, Log, TEXT("║    INITIATING SERVER CONNECTION                         ║"));
	UE_LOG(LogTemp, Log, TEXT("╚══════════════════════════════════════════════════════════╝"));
	UE_LOG(LogTemp, Log, TEXT("Character: %s"), *CharacterId.ToString());
	UE_LOG(LogTemp, Log, TEXT("NOTE: This begins async flow:"));
	UE_LOG(LogTemp, Log, TEXT("  1. Client: Request server info from backend API"));
	UE_LOG(LogTemp, Log, TEXT("  2. Client: Perform ClientTravel with Token + CharacterId"));
	UE_LOG(LogTemp, Log, TEXT("  3. Server: Receive connection, validate token with API"));
	UE_LOG(LogTemp, Log, TEXT("  4. Server: If valid, spawn player and load character widget"));

	// Create HTTP request
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = Http->CreateRequest();
	HttpRequest->SetVerb(TEXT("GET"));
	HttpRequest->SetURL(GetApiBaseUrl() + FString::Printf(TEXT("/character/%s/connect-info"), *CharacterId.ToString()));
	HttpRequest->SetHeader(TEXT("Authorization"), FString::Printf(TEXT("Bearer %s"), *JWTToken));

	// Bind response callback
	HttpRequest->OnProcessRequestComplete().BindUObject(
		this,
		&UEchoesAuthSubsystem::OnConnectInfoResponseReceived,
		CharacterId);

	// Send request
	HttpRequest->ProcessRequest();
	UE_LOG(LogTemp, Log, TEXT("✓ Requesting connect info for character: %s"), *CharacterId.ToString());
}

void UEchoesAuthSubsystem::OnConnectInfoResponseReceived(
	FHttpRequestPtr Request,
	FHttpResponsePtr Response,
	bool bWasSuccessful,
	FGuid CharacterId)
{
	if (!bWasSuccessful || !Response.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Connect info request failed"));
		OnConnectInfoFailed.Broadcast(TEXT("Network error"));
		return;
	}

	int32 ResponseCode = Response->GetResponseCode();
	FString ResponseContent = Response->GetContentAsString();

	if (ResponseCode == 200)
	{
		// Parse connect info
		TSharedPtr<FJsonObject> JsonObject;
		TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(ResponseContent);

		if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
		{
			FString ServerIP = JsonObject->GetStringField(TEXT("serverIP"));
			int32 ServerPort = (int32)JsonObject->GetNumberField(TEXT("serverPort"));

			UE_LOG(LogTemp, Log, TEXT("╔══════════════════════════════════════════════════════════╗"));
			UE_LOG(LogTemp, Log, TEXT("║    SERVER INFO RECEIVED - INITIATING CLIENT TRAVEL      ║"));
			UE_LOG(LogTemp, Log, TEXT("╚══════════════════════════════════════════════════════════╝"));
			UE_LOG(LogTemp, Log, TEXT("Connect info: %s:%d"), *ServerIP, ServerPort);
			UE_LOG(LogTemp, Log, TEXT("IMPORTANT: Token validation happens SERVER-SIDE"));
			UE_LOG(LogTemp, Log, TEXT("           Character widget loads AFTER validation"));

			// Update current character ID
			CurrentAuthResponse.CharacterId = CharacterId;

			// Broadcast event
			OnConnectInfoReceived.Broadcast(ServerIP, ServerPort);

			// Perform ClientTravel with Token and CharacterId in URL
			// Server will extract these in PostLogin and validate with backend API
			if (UWorld* World = GetWorld())
			{
				if (APlayerController* PC = World->GetFirstPlayerController())
				{
					FString ConnectURL = FString::Printf(TEXT("%s:%d?Token=%s&CharacterId=%s"),
						*ServerIP, ServerPort, *JWTToken, *CharacterId.ToString());

					UE_LOG(LogTemp, Log, TEXT("✓ Traveling to dedicated server..."));
					UE_LOG(LogTemp, Log, TEXT("  Next: Server validates token and spawns player"));
					PC->ClientTravel(ConnectURL, TRAVEL_Absolute);
				}
				else
				{
					UE_LOG(LogTemp, Error, TEXT("Failed to get PlayerController"));
					OnConnectInfoFailed.Broadcast(TEXT("PlayerController not available"));
				}
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("Failed to get World"));
				OnConnectInfoFailed.Broadcast(TEXT("World not available"));
			}
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to parse connect info response"));
			OnConnectInfoFailed.Broadcast(TEXT("Invalid server response"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Connect info failed: %d - %s"), ResponseCode, *ResponseContent);
		OnConnectInfoFailed.Broadcast(TEXT("Failed to get connection info"));
	}
}

void UEchoesAuthSubsystem::SetAuthSession(
	const FString& Token,
	const FGuid& AccountId,
	const FGuid& CharacterId,
	const FString& CharacterName,
	const TArray<FCharacterInfo>& Characters)
{
	JWTToken = Token;
	CurrentAuthResponse = FAuthResponse();
	CurrentAuthResponse.Success = true;
	CurrentAuthResponse.Token = Token;
	CurrentAuthResponse.AccountId = AccountId;
	CurrentAuthResponse.CharacterId = CharacterId;
	CurrentAuthResponse.CharacterName = CharacterName;
	CurrentAuthResponse.Characters = Characters;

	UE_LOG(LogTemp, Log, TEXT("AuthSubsystem: Session cached. Characters=%d"), Characters.Num());
}
