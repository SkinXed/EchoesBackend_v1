// Copyright Epic Games, Inc. All Rights Reserved.

#include "EWorldContainer.h"
#include "Http.h"
#include "Json.h"
#include "JsonUtilities.h"
#include "Engine/World.h"

AEWorldContainer::AEWorldContainer()
{
	// Set this actor to not tick (it's not needed for containers)
	PrimaryActorTick.bCanEverTick = false;

	// This is a server-only actor
	bReplicates = false;
	SetReplicatingMovement(false);

	// Initialize state
	CurrentInventoryJson = TEXT("{}");
	bRegistrationInProgress = false;
	bInventoryUpdateInProgress = false;
	bHasPendingUpdate = false;
}

void AEWorldContainer::BeginPlay()
{
	Super::BeginPlay();

	// Only run on server
	if (!GetWorld() || !GetWorld()->GetAuthGameMode())
	{
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("EWorldContainer: BeginPlay on server"));

	// If this container was spawned from database, don't register again
	if (bLoadedFromDatabase)
	{
		UE_LOG(LogTemp, Log, TEXT("EWorldContainer: Loaded from database, ObjectId=%s"),
			*ObjectId.ToString(EGuidFormats::Digits));
		return;
	}

	// New container - register to backend
	ServerOnly_RegisterToBackend();
}

void AEWorldContainer::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	// Only run on server
	if (GetWorld() && GetWorld()->GetAuthGameMode())
	{
		// Optional: Unregister from backend on destruction
		// For now, we let expired containers be cleaned up by background service
		// If immediate cleanup is needed, uncomment:
		// ServerOnly_UnregisterFromBackend();

		UE_LOG(LogTemp, Log, TEXT("EWorldContainer: EndPlay, ObjectId=%s"),
			*ObjectId.ToString(EGuidFormats::Digits));
	}

	Super::EndPlay(EndPlayReason);
}

void AEWorldContainer::InitializeFromDatabase(const FWorldObjectData& Data)
{
	bLoadedFromDatabase = true;
	ObjectId = Data.Id;
	TemplateId = Data.TemplateId;
	SystemId = Data.SystemId;
	CurrentInventoryJson = Data.InventoryJson;

	// Set actor location and rotation
	SetActorLocation(Data.Position);
	SetActorRotation(Data.Rotation);

	UE_LOG(LogTemp, Log, TEXT("EWorldContainer: Initialized from database, ObjectId=%s"),
		*ObjectId.ToString(EGuidFormats::Digits));
}

FWorldObjectData AEWorldContainer::GetWorldObjectData() const
{
	FWorldObjectData Data;
	Data.Id = ObjectId;
	Data.TemplateId = TemplateId;
	Data.SystemId = SystemId;
	Data.Position = GetActorLocation();
	Data.Rotation = GetActorRotation().Quaternion();
	Data.InventoryJson = CurrentInventoryJson;
	
	return Data;
}

void AEWorldContainer::ServerOnly_UpdateInventory(const FString& NewInventoryJson)
{
	if (!GetWorld() || !GetWorld()->GetAuthGameMode())
	{
		UE_LOG(LogTemp, Warning, TEXT("EWorldContainer: UpdateInventory called on client, ignoring"));
		return;
	}

	if (!ObjectId.IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("EWorldContainer: Cannot update inventory, object not registered yet"));
		return;
	}

	CurrentInventoryJson = NewInventoryJson;

	// If update is in progress, queue this update
	if (bInventoryUpdateInProgress)
	{
		PendingInventoryUpdate = NewInventoryJson;
		bHasPendingUpdate = true;
		UE_LOG(LogTemp, Verbose, TEXT("EWorldContainer: Inventory update queued"));
		return;
	}

	ServerOnly_SendInventoryUpdate();
}

void AEWorldContainer::ServerOnly_RegisterToBackend()
{
	if (bRegistrationInProgress)
	{
		UE_LOG(LogTemp, Warning, TEXT("EWorldContainer: Registration already in progress"));
		return;
	}

	if (!SystemId.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("EWorldContainer: Cannot register, SystemId is invalid"));
		return;
	}

	bRegistrationInProgress = true;

	// Build JSON payload
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	JsonObject->SetNumberField(TEXT("templateId"), TemplateId);
	JsonObject->SetStringField(TEXT("systemId"), SystemId.ToString(EGuidFormats::Digits));

	// Position
	FVector Position = GetActorLocation();
	JsonObject->SetNumberField(TEXT("posX"), Position.X);
	JsonObject->SetNumberField(TEXT("posY"), Position.Y);
	JsonObject->SetNumberField(TEXT("posZ"), Position.Z);

	// Rotation (quaternion)
	FQuat Rotation = GetActorRotation().Quaternion();
	JsonObject->SetNumberField(TEXT("rotW"), Rotation.W);
	JsonObject->SetNumberField(TEXT("rotX"), Rotation.X);
	JsonObject->SetNumberField(TEXT("rotY"), Rotation.Y);
	JsonObject->SetNumberField(TEXT("rotZ"), Rotation.Z);

	// Inventory
	JsonObject->SetStringField(TEXT("inventoryJson"), CurrentInventoryJson);

	// Expiration time (if set)
	if (ExpirationHours > 0)
	{
		FDateTime ExpirationTime = FDateTime::UtcNow() + FTimespan::FromHours(ExpirationHours);
		JsonObject->SetStringField(TEXT("expirationTime"), ExpirationTime.ToIso8601());
	}

	// Serialize to JSON string
	FString Content;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&Content);
	FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);

	// Create HTTP request
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();

	FString FullUrl = ApiBaseUrl + TEXT("/persistence/world-objects");
	Request->SetURL(FullUrl);
	Request->SetVerb(TEXT("POST"));
	Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	Request->SetHeader(TEXT("X-Server-Secret"), ServerSecret);
	Request->SetContentAsString(Content);

	// Bind response callback
	Request->OnProcessRequestComplete().BindLambda(
		[this](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
		{
			bRegistrationInProgress = false;

			if (!bWasSuccessful || !Response.IsValid())
			{
				UE_LOG(LogTemp, Error, TEXT("EWorldContainer: Registration HTTP request failed"));
				OnRegistrationError(TEXT("Network error"));
				return;
			}

			int32 ResponseCode = Response->GetResponseCode();
			FString ResponseBody = Response->GetContentAsString();

			if (ResponseCode >= 200 && ResponseCode < 300)
			{
				UE_LOG(LogTemp, Log, TEXT("EWorldContainer: Registration successful"));
				OnRegistrationSuccess(ResponseBody);
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("EWorldContainer: Registration failed with code %d: %s"),
					ResponseCode, *ResponseBody);
				OnRegistrationError(FString::Printf(TEXT("HTTP %d: %s"), ResponseCode, *ResponseBody));
			}
		}
	);

	// Execute request
	Request->ProcessRequest();

	UE_LOG(LogTemp, Log, TEXT("EWorldContainer: Sending registration request to %s"), *FullUrl);
}

void AEWorldContainer::ServerOnly_SendInventoryUpdate()
{
	if (!ObjectId.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("EWorldContainer: Cannot update inventory, object not registered"));
		return;
	}

	if (bInventoryUpdateInProgress)
	{
		UE_LOG(LogTemp, Warning, TEXT("EWorldContainer: Inventory update already in progress"));
		return;
	}

	bInventoryUpdateInProgress = true;

	// Build JSON payload
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	JsonObject->SetStringField(TEXT("inventoryJson"), CurrentInventoryJson);

	// Serialize to JSON string
	FString Content;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&Content);
	FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);

	// Create HTTP request
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();

	FString FullUrl = FString::Printf(TEXT("%s/persistence/world-objects/%s/inventory"),
		*ApiBaseUrl, *ObjectId.ToString(EGuidFormats::Digits));
	Request->SetURL(FullUrl);
	Request->SetVerb(TEXT("PUT"));
	Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	Request->SetHeader(TEXT("X-Server-Secret"), ServerSecret);
	Request->SetContentAsString(Content);

	// Bind response callback
	Request->OnProcessRequestComplete().BindLambda(
		[this](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
		{
			bInventoryUpdateInProgress = false;

			if (!bWasSuccessful || !Response.IsValid())
			{
				UE_LOG(LogTemp, Error, TEXT("EWorldContainer: Inventory update HTTP request failed"));
				OnInventoryUpdateError(TEXT("Network error"));
				return;
			}

			int32 ResponseCode = Response->GetResponseCode();
			FString ResponseBody = Response->GetContentAsString();

			if (ResponseCode >= 200 && ResponseCode < 300)
			{
				UE_LOG(LogTemp, Log, TEXT("EWorldContainer: Inventory update successful"));
				OnInventoryUpdateSuccess(ResponseBody);
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("EWorldContainer: Inventory update failed with code %d: %s"),
					ResponseCode, *ResponseBody);
				OnInventoryUpdateError(FString::Printf(TEXT("HTTP %d: %s"), ResponseCode, *ResponseBody));
			}

			// Process pending update if any
			if (bHasPendingUpdate)
			{
				bHasPendingUpdate = false;
				CurrentInventoryJson = PendingInventoryUpdate;
				ServerOnly_SendInventoryUpdate();
			}
		}
	);

	// Execute request
	Request->ProcessRequest();

	UE_LOG(LogTemp, Log, TEXT("EWorldContainer: Sending inventory update to %s"), *FullUrl);
}

void AEWorldContainer::ServerOnly_UnregisterFromBackend()
{
	if (!ObjectId.IsValid())
	{
		return;
	}

	// Create HTTP request
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();

	FString FullUrl = FString::Printf(TEXT("%s/persistence/world-objects/%s"),
		*ApiBaseUrl, *ObjectId.ToString(EGuidFormats::Digits));
	Request->SetURL(FullUrl);
	Request->SetVerb(TEXT("DELETE"));
	Request->SetHeader(TEXT("X-Server-Secret"), ServerSecret);

	// Bind response callback
	Request->OnProcessRequestComplete().BindLambda(
		[this](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
		{
			if (bWasSuccessful && Response.IsValid() && Response->GetResponseCode() == 204)
			{
				UE_LOG(LogTemp, Log, TEXT("EWorldContainer: Unregistration successful"));
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("EWorldContainer: Unregistration failed or not found"));
			}
		}
	);

	// Execute request
	Request->ProcessRequest();

	UE_LOG(LogTemp, Log, TEXT("EWorldContainer: Sending unregistration request"));
}

void AEWorldContainer::OnRegistrationSuccess(const FString& Response)
{
	// Parse response to get object ID
	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response);

	if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
	{
		FString IdString = JsonObject->GetStringField(TEXT("Id"));
		if (FGuid::Parse(IdString, ObjectId))
		{
			UE_LOG(LogTemp, Log, TEXT("EWorldContainer: Registered with ObjectId=%s"),
				*ObjectId.ToString(EGuidFormats::Digits));
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("EWorldContainer: Failed to parse ObjectId from response"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("EWorldContainer: Failed to parse registration response"));
	}
}

void AEWorldContainer::OnRegistrationError(const FString& Error)
{
	UE_LOG(LogTemp, Error, TEXT("EWorldContainer: Registration error: %s"), *Error);
	// Could retry registration here or handle error
}

void AEWorldContainer::OnInventoryUpdateSuccess(const FString& Response)
{
	UE_LOG(LogTemp, Verbose, TEXT("EWorldContainer: Inventory update confirmed"));
}

void AEWorldContainer::OnInventoryUpdateError(const FString& Error)
{
	UE_LOG(LogTemp, Error, TEXT("EWorldContainer: Inventory update error: %s"), *Error);
	// Could retry update here or handle error
}
