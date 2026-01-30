// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesShipStatsSubsystem.h"
#include "Http.h"
#include "Json.h"
#include "JsonUtilities.h"

void UEchoesShipStatsSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    
    UE_LOG(LogTemp, Log, TEXT("EchoesShipStatsSubsystem initialized. API URL: %s"), *ApiBaseUrl);
}

void UEchoesShipStatsSubsystem::Deinitialize()
{
    Super::Deinitialize();
    
    UE_LOG(LogTemp, Log, TEXT("EchoesShipStatsSubsystem deinitialized"));
}

void UEchoesShipStatsSubsystem::FetchShipStats(
    FGuid ShipInstanceId,
    const FOnShipStatsFetched& OnSuccess,
    const FOnApiError& OnError)
{
    FString Endpoint = FString::Printf(TEXT("/ship/%s/stats"), *ShipInstanceId.ToString(EGuidFormats::Digits));
    
    MakeAuthenticatedRequest(
        Endpoint,
        TEXT("GET"),
        TEXT(""),
        [this, OnSuccess](const FString& Response)
        {
            // Parse JSON response
            FEchoesShipStats Stats;
            if (ParseShipStatsJson(Response, Stats))
            {
                OnSuccess.ExecuteIfBound(Stats);
            }
            else
            {
                UE_LOG(LogTemp, Error, TEXT("Failed to parse ship stats JSON"));
            }
        },
        [OnError](const FString& Error)
        {
            OnError.ExecuteIfBound(Error);
        }
    );
}

void UEchoesShipStatsSubsystem::AddModule(
    FGuid ShipInstanceId,
    int32 ModuleTypeId,
    float Mass,
    FString Slot,
    const FOnModuleAdded& OnSuccess,
    const FOnApiError& OnError)
{
    FString Endpoint = FString::Printf(TEXT("/ship/%s/modules"), *ShipInstanceId.ToString(EGuidFormats::Digits));
    
    // Create JSON body
    TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
    JsonObject->SetNumberField(TEXT("moduleTypeId"), ModuleTypeId);
    JsonObject->SetNumberField(TEXT("mass"), Mass);
    JsonObject->SetStringField(TEXT("slot"), Slot);
    
    FString Content;
    TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&Content);
    FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);
    
    MakeAuthenticatedRequest(
        Endpoint,
        TEXT("POST"),
        Content,
        [OnSuccess](const FString& Response)
        {
            OnSuccess.ExecuteIfBound(true);
        },
        [OnError](const FString& Error)
        {
            OnError.ExecuteIfBound(Error);
        }
    );
}

void UEchoesShipStatsSubsystem::MakeAuthenticatedRequest(
    const FString& Endpoint,
    const FString& Verb,
    const FString& Content,
    TFunction<void(const FString&)> OnSuccess,
    TFunction<void(const FString&)> OnError)
{
    // Create HTTP request
    TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();
    
    FString FullUrl = ApiBaseUrl + Endpoint;
    Request->SetURL(FullUrl);
    Request->SetVerb(Verb);
    
    // Add authentication header
    Request->SetHeader(TEXT("X-Server-Secret"), ServerSecret);
    Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
    
    // Set content if provided
    if (!Content.IsEmpty())
    {
        Request->SetContentAsString(Content);
    }
    
    // Bind response callback
    Request->OnProcessRequestComplete().BindLambda(
        [OnSuccess, OnError](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
        {
            if (!bWasSuccessful || !Response.IsValid())
            {
                UE_LOG(LogTemp, Error, TEXT("HTTP request failed"));
                OnError(TEXT("Network error"));
                return;
            }
            
            int32 ResponseCode = Response->GetResponseCode();
            FString ResponseBody = Response->GetContentAsString();
            
            if (ResponseCode >= 200 && ResponseCode < 300)
            {
                UE_LOG(LogTemp, Log, TEXT("HTTP request successful: %d"), ResponseCode);
                OnSuccess(ResponseBody);
            }
            else
            {
                UE_LOG(LogTemp, Error, TEXT("HTTP request failed with code %d: %s"), 
                    ResponseCode, *ResponseBody);
                OnError(FString::Printf(TEXT("HTTP %d: %s"), ResponseCode, *ResponseBody));
            }
        }
    );
    
    // Execute request
    Request->ProcessRequest();
    
    UE_LOG(LogTemp, Log, TEXT("Sending %s request to: %s"), *Verb, *FullUrl);
}

bool UEchoesShipStatsSubsystem::ParseShipStatsJson(const FString& JsonString, FEchoesShipStats& OutStats)
{
    TSharedPtr<FJsonObject> JsonObject;
    TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(JsonString);
    
    if (!FJsonSerializer::Deserialize(Reader, JsonObject) || !JsonObject.IsValid())
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to parse JSON: %s"), *JsonString);
        return false;
    }
    
    // Parse fields (camelCase from backend)
    OutStats.TotalMass = JsonObject->GetNumberField(TEXT("totalMass"));
    OutStats.BaseMass = JsonObject->GetNumberField(TEXT("baseMass"));
    OutStats.Thrust = JsonObject->GetNumberField(TEXT("thrust"));
    OutStats.RotationSpeed = JsonObject->GetNumberField(TEXT("rotationSpeed"));
    OutStats.WarpSpeed = JsonObject->GetNumberField(TEXT("warpSpeed"));
    OutStats.InertiaMultiplier = JsonObject->GetNumberField(TEXT("inertiaMultiplier"));
    OutStats.MaxVelocity = JsonObject->GetNumberField(TEXT("maxVelocity"));
    OutStats.Agility = JsonObject->GetNumberField(TEXT("agility"));
    
    // Parse GUID
    FString ShipIdString = JsonObject->GetStringField(TEXT("shipId"));
    FGuid::Parse(ShipIdString, OutStats.ShipId);
    
    OutStats.ShipName = JsonObject->GetStringField(TEXT("shipName"));
    OutStats.ShipTypeId = JsonObject->GetIntegerField(TEXT("shipTypeId"));
    OutStats.ShipTypeName = JsonObject->GetStringField(TEXT("shipTypeName"));
    
    UE_LOG(LogTemp, Log, TEXT("Parsed ship stats: %s (Mass: %f, Thrust: %f)"), 
        *OutStats.ShipName, OutStats.TotalMass, OutStats.Thrust);
    
    return true;
}
