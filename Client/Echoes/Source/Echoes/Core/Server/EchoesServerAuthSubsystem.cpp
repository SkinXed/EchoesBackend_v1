// Copyright Epic Games, Inc. All Rights Reserved.

#include "Core/Server/EchoesServerAuthSubsystem.h"
#include "HttpModule.h"
#include "Interfaces/IHttpResponse.h"
#include "Json.h"
#include "JsonUtilities.h"
#include "Misc/ConfigCacheIni.h"

void UEchoesServerAuthSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	// Get HTTP module
	Http = &FHttpModule::Get();

	UE_LOG(LogTemp, Log, TEXT("EchoesServerAuthSubsystem initialized"));
}

void UEchoesServerAuthSubsystem::Deinitialize()
{
	Super::Deinitialize();

	UE_LOG(LogTemp, Log, TEXT("EchoesServerAuthSubsystem deinitialized"));
}

void UEchoesServerAuthSubsystem::ValidateClientToken(
	const FString& Token,
	TFunction<void(const FGuid& CharacterId, const FGuid& AccountId)> OnSuccess,
	TFunction<void(const FString& Error)> OnFailure
)
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

	if (Token.IsEmpty())
	{
		UE_LOG(LogTemp, Error, TEXT("Token is empty"));
		if (OnFailure)
		{
			OnFailure(TEXT("Token is required"));
		}
		return;
	}

	// Create HTTP request
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = Http->CreateRequest();
	HttpRequest->SetVerb(TEXT("POST"));
	HttpRequest->SetURL(GetApiBaseUrl() + TEXT("/auth/validate-token"));
	HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));

	// Create JSON payload
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	JsonObject->SetStringField(TEXT("token"), Token);

	FString JsonString;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&JsonString);
	FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);

	HttpRequest->SetContentAsString(JsonString);

	// Bind response handler
	HttpRequest->OnProcessRequestComplete().BindUObject(
		this,
		&UEchoesServerAuthSubsystem::OnValidateTokenResponseReceived,
		OnSuccess,
		OnFailure
	);

	// Send request
	if (!HttpRequest->ProcessRequest())
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to process token validation request"));
		if (OnFailure)
		{
			OnFailure(TEXT("Failed to send request"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Token validation request sent to Backend API"));
	}
}

void UEchoesServerAuthSubsystem::OnValidateTokenResponseReceived(
	FHttpRequestPtr Request,
	FHttpResponsePtr Response,
	bool bWasSuccessful,
	TFunction<void(const FGuid&, const FGuid&)> OnSuccess,
	TFunction<void(const FString&)> OnFailure
)
{
	if (!bWasSuccessful || !Response.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Token validation request failed"));
		if (OnFailure)
		{
			OnFailure(TEXT("Network error"));
		}
		return;
	}

	const int32 ResponseCode = Response->GetResponseCode();
	const FString ResponseBody = Response->GetContentAsString();

	UE_LOG(LogTemp, Log, TEXT("Token validation response: Code=%d"), ResponseCode);

	if (ResponseCode == 200)
	{
		// Parse response
		TSharedPtr<FJsonObject> JsonObject;
		TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(ResponseBody);

		if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
		{
			bool bIsValid = JsonObject->GetBoolField(TEXT("isValid"));

			if (bIsValid)
			{
				// Extract character and account IDs
				FString CharacterIdStr = JsonObject->GetStringField(TEXT("characterId"));
				FString AccountIdStr = JsonObject->GetStringField(TEXT("accountId"));

				FGuid CharacterId;
				FGuid AccountId;

				if (FGuid::Parse(CharacterIdStr, CharacterId) && FGuid::Parse(AccountIdStr, AccountId))
				{
					UE_LOG(LogTemp, Log, TEXT("✓ Token validated successfully: Character=%s, Account=%s"),
						*CharacterId.ToString(), *AccountId.ToString());

					if (OnSuccess)
					{
						OnSuccess(CharacterId, AccountId);
					}
				}
				else
				{
					UE_LOG(LogTemp, Error, TEXT("Failed to parse GUIDs from response"));
					if (OnFailure)
					{
						OnFailure(TEXT("Invalid response format"));
					}
				}
			}
			else
			{
				// Token is invalid
				FString ErrorMsg = JsonObject->HasField(TEXT("error"))
					? JsonObject->GetStringField(TEXT("error"))
					: TEXT("Token validation failed");

				UE_LOG(LogTemp, Warning, TEXT("✗ Token validation failed: %s"), *ErrorMsg);

				if (OnFailure)
				{
					OnFailure(ErrorMsg);
				}
			}
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to parse validation response"));
			if (OnFailure)
			{
				OnFailure(TEXT("Failed to parse response"));
			}
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Token validation failed with code: %d"), ResponseCode);
		if (OnFailure)
		{
			OnFailure(FString::Printf(TEXT("Server error: %d"), ResponseCode));
		}
	}
}

FString UEchoesServerAuthSubsystem::GetApiBaseUrl() const
{
	FString ApiBaseUrl;
	
	// Try to read from config
	if (GConfig->GetString(
		TEXT("/Script/Echoes.EchoesServerAuthSubsystem"),
		TEXT("ApiBaseUrl"),
		ApiBaseUrl,
		GGameIni))
	{
		return ApiBaseUrl;
	}

	// Default to localhost
	return TEXT("http://localhost:5116/api");
}
