// Copyright Epic Games, Inc. All Rights Reserved.

#include "Core/Server/EchoesServerAuthSubsystem.h"
#include "HttpModule.h"
#include "Interfaces/IHttpResponse.h"
#include "Json.h"
#include "JsonUtilities.h"
#include "Misc/ConfigCacheIni.h"
#include "EchoesPlayerController.h"

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

FString UEchoesServerAuthSubsystem::GetApiBaseUrl() const
{
    FString BaseUrl;

    // Try to read from config
    if (GConfig->GetString(
        TEXT("/Script/Echoes.EchoesServerAuthSubsystem"),
        TEXT("ApiBaseUrl"),
        BaseUrl,
        GGameIni))
    {
        return BaseUrl;
    }

    // Default to localhost
    return TEXT("http://localhost:5116/api");
}

void UEchoesServerAuthSubsystem::ValidateClientToken(
    const FString& Token,
    TFunction<void(const FGuid& CharacterId, const FGuid& AccountId)> OnSuccess,
    TFunction<void(const FString& Error)> OnFailure
)
{
    if (!Http)
    {
        if (OnFailure) OnFailure(TEXT("HTTP module not available"));
        return;
    }

    if (Token.IsEmpty())
    {
        if (OnFailure) OnFailure(TEXT("Token is required"));
        return;
    }

    TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = Http->CreateRequest();
    HttpRequest->SetVerb(TEXT("POST"));
    HttpRequest->SetURL(GetApiBaseUrl() + TEXT("/auth/validate-token"));
    HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));

    TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
    JsonObject->SetStringField(TEXT("token"), Token);

    FString JsonString;
    TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&JsonString);
    FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);

    HttpRequest->SetContentAsString(JsonString);

    TWeakObjectPtr<UEchoesServerAuthSubsystem> WeakThis(this);
    HttpRequest->OnProcessRequestComplete().BindLambda(
        [WeakThis, OnSuccess, OnFailure](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
        {
            if (!WeakThis.IsValid()) return;
            WeakThis->OnValidateTokenResponseReceived(Request, Response, bWasSuccessful, OnSuccess, OnFailure);
        }
    );

    if (!HttpRequest->ProcessRequest())
    {
        if (OnFailure) OnFailure(TEXT("Failed to send request"));
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
        if (OnFailure) OnFailure(TEXT("Network error"));
        return;
    }

    const int32 ResponseCode = Response->GetResponseCode();
    const FString ResponseBody = Response->GetContentAsString();

    if (ResponseCode == 200)
    {
        TSharedPtr<FJsonObject> JsonObject;
        TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(ResponseBody);

        if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
        {
            bool bIsValid = JsonObject->GetBoolField(TEXT("isValid"));

            if (bIsValid)
            {
                FString CharacterIdStr = JsonObject->GetStringField(TEXT("characterId"));
                FString AccountIdStr = JsonObject->GetStringField(TEXT("accountId"));

                FGuid CharacterId, AccountId;
                if (FGuid::Parse(CharacterIdStr, CharacterId) && FGuid::Parse(AccountIdStr, AccountId))
                {
                    if (OnSuccess) OnSuccess(CharacterId, AccountId);
                }
                else
                {
                    if (OnFailure) OnFailure(TEXT("Invalid GUID format"));
                }
            }
            else
            {
                FString ErrorMsg = JsonObject->GetStringField(TEXT("error"));
                if (OnFailure) OnFailure(ErrorMsg.IsEmpty() ? TEXT("Token invalid") : ErrorMsg);
            }
        }
        else
        {
            if (OnFailure) OnFailure(TEXT("Failed to parse JSON response"));
        }
    }
    else
    {
        if (OnFailure) OnFailure(FString::Printf(TEXT("Server error: %d"), ResponseCode));
    }
}

void UEchoesServerAuthSubsystem::FetchCharacterList(
    const FString& Token,
    FOnCharacterListReceived OnSuccess,
    FOnAuthFailure OnFailure
)
{
    if (!Http) return;

    TSharedRef<IHttpRequest> Request = Http->CreateRequest();
    // Используем GetApiBaseUrl() вместо переменной ApiBaseUrl
    Request->SetURL(GetApiBaseUrl() + TEXT("/character/list"));
    Request->SetVerb(TEXT("GET"));
    Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
    Request->SetHeader(TEXT("Authorization"), TEXT("Bearer ") + Token);

    // Используем WeakThis для безопасности
    TWeakObjectPtr<UEchoesServerAuthSubsystem> WeakThis(this);

    Request->OnProcessRequestComplete().BindLambda(
        [WeakThis, OnSuccess, OnFailure](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
        {
            if (!WeakThis.IsValid()) return;

            if (!bWasSuccessful || !Response.IsValid())
            {
                OnFailure.ExecuteIfBound(TEXT("Network connection failed"));
                return;
            }

            if (Response->GetResponseCode() != 200)
            {
                OnFailure.ExecuteIfBound(FString::Printf(TEXT("API Error: %d"), Response->GetResponseCode()));
                return;
            }

            TArray<FCharacterInfo> ResultCharacters;
            TSharedPtr<FJsonValue> JsonValue;
            TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());

            if (FJsonSerializer::Deserialize(Reader, JsonValue) && JsonValue.IsValid())
            {
                const TArray<TSharedPtr<FJsonValue>>* JsonArray;
                if (JsonValue->TryGetArray(JsonArray))
                {
                    for (const TSharedPtr<FJsonValue>& Val : *JsonArray)
                    {
                        const TSharedPtr<FJsonObject> Obj = Val->AsObject();
                        if (Obj.IsValid())
                        {
                            FCharacterInfo Info;

                            // Маппинг полей из C# CharacterListDto (camelCase)
                            // ID
                            FString IdStr = Obj->GetStringField(TEXT("characterId"));
                            if (IdStr.IsEmpty()) IdStr = Obj->GetStringField(TEXT("id")); // Fallback
                            FGuid::Parse(IdStr, Info.CharacterId);

                            // Basic Info
                            Info.Name = Obj->GetStringField(TEXT("name"));
                            Info.RaceId = Obj->GetIntegerField(TEXT("raceId"));

                            // Status
                            Info.IsOnline = Obj->GetBoolField(TEXT("isOnline"));
                            Info.IsDocked = Obj->GetBoolField(TEXT("isDocked"));

                            // Wallet / Credits
                            Info.Credits = (int64)Obj->GetNumberField(TEXT("credits"));

                            ResultCharacters.Add(Info);
                        }
                    }
                }
                OnSuccess.ExecuteIfBound(ResultCharacters);
            }
            else
            {
                OnFailure.ExecuteIfBound(TEXT("Failed to parse character list JSON"));
            }
        });

    Request->ProcessRequest();
}