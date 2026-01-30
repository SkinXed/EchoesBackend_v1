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
	UE_LOG(LogTemp, Log, TEXT("User logged out"));

	// Clear token and session data
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
				CharInfo.WalletBalance = CharObj->GetNumberField(TEXT("walletBalance"));
				
				if (CharObj->HasField(TEXT("currentShipId")) && !CharObj->GetField(TEXT("currentShipId"))->IsNull())
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
	OutData.SecurityStatus = JsonObject->GetNumberField(TEXT("securityStatus"));
	
	if (JsonObject->HasField(TEXT("currentShipId")) && !JsonObject->GetField(TEXT("currentShipId"))->IsNull())
	{
		OutData.CurrentShipId = JsonObject->GetNumberField(TEXT("currentShipId"));
	}
	
	if (JsonObject->HasField(TEXT("corporationId")))
	{
		FGuid::Parse(JsonObject->GetStringField(TEXT("corporationId")), OutData.CorporationId);
	}
	
	OutData.RaceId = JsonObject->GetIntegerField(TEXT("raceId"));
	OutData.TotalSkillPoints = JsonObject->GetIntegerField(TEXT("totalSkillPoints"));
	OutData.UnallocatedSkillPoints = JsonObject->GetIntegerField(TEXT("unallocatedSkillPoints"));
	OutData.IsOnline = JsonObject->GetBoolField(TEXT("isOnline"));
	OutData.IsDocked = JsonObject->GetBoolField(TEXT("isDocked"));
	OutData.InWarp = JsonObject->GetBoolField(TEXT("inWarp"));

	if (JsonObject->HasField(TEXT("lastLogin")) && !JsonObject->GetField(TEXT("lastLogin"))->IsNull())
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
