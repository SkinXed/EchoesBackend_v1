// Copyright Epic Games, Inc. All Rights Reserved.

#include "WorldObjectManager.h"
#include "Http.h"
#include "Json.h"
#include "JsonUtilities.h"
#include "Engine/World.h"
#include "GameFramework/GameModeBase.h"

UWorldObjectManager::UWorldObjectManager()
{
	PrimaryComponentTick.bCanEverTick = false;
	bQueryInProgress = false;
	bWorldObjectsLoaded = false;
}

void UWorldObjectManager::BeginPlay()
{
	Super::BeginPlay();

	// Only run on server
	if (!GetWorld() || !GetWorld()->GetAuthGameMode())
	{
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("WorldObjectManager: BeginPlay on server"));

	// Auto-load if configured
	if (bAutoLoadOnBeginPlay)
	{
		ServerOnly_LoadWorldObjects();
	}
}

void UWorldObjectManager::ServerOnly_LoadWorldObjects()
{
	if (!GetWorld() || !GetWorld()->GetAuthGameMode())
	{
		UE_LOG(LogTemp, Warning, TEXT("WorldObjectManager: LoadWorldObjects called on client"));
		return;
	}

	if (bWorldObjectsLoaded)
	{
		UE_LOG(LogTemp, Warning, TEXT("WorldObjectManager: World objects already loaded"));
		return;
	}

	if (!SystemId.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("WorldObjectManager: Cannot load, SystemId is invalid"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("WorldObjectManager: Loading world objects for system %s"),
		*SystemId.ToString(EGuidFormats::Digits));

	ServerOnly_QueryBackend();
}

void UWorldObjectManager::ServerOnly_QueryBackend()
{
	if (bQueryInProgress)
	{
		UE_LOG(LogTemp, Warning, TEXT("WorldObjectManager: Query already in progress"));
		return;
	}

	bQueryInProgress = true;

	// Create HTTP request
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();

	FString FullUrl = FString::Printf(TEXT("%s/persistence/world-objects/system/%s"),
		*ApiBaseUrl, *SystemId.ToString(EGuidFormats::Digits));
	Request->SetURL(FullUrl);
	Request->SetVerb(TEXT("GET"));
	Request->SetHeader(TEXT("X-Server-Secret"), ServerSecret);

	// Bind response callback
	Request->OnProcessRequestComplete().BindLambda(
		[this](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
		{
			bQueryInProgress = false;

			if (!bWasSuccessful || !Response.IsValid())
			{
				UE_LOG(LogTemp, Error, TEXT("WorldObjectManager: Query HTTP request failed"));
				OnQueryError(TEXT("Network error"));
				return;
			}

			int32 ResponseCode = Response->GetResponseCode();
			FString ResponseBody = Response->GetContentAsString();

			if (ResponseCode >= 200 && ResponseCode < 300)
			{
				UE_LOG(LogTemp, Log, TEXT("WorldObjectManager: Query successful"));
				OnQuerySuccess(ResponseBody);
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("WorldObjectManager: Query failed with code %d: %s"),
					ResponseCode, *ResponseBody);
				OnQueryError(FString::Printf(TEXT("HTTP %d: %s"), ResponseCode, *ResponseBody));
			}
		}
	);

	// Execute request
	Request->ProcessRequest();

	UE_LOG(LogTemp, Log, TEXT("WorldObjectManager: Sending query to %s"), *FullUrl);
}

void UWorldObjectManager::ServerOnly_SpawnContainer(const FWorldObjectData& Data)
{
	if (!GetWorld())
	{
		UE_LOG(LogTemp, Error, TEXT("WorldObjectManager: Cannot spawn, no world"));
		return;
	}

	// Use configured container class or default
	TSubclassOf<AEWorldContainer> ClassToSpawn = ContainerClass;
	if (!ClassToSpawn)
	{
		ClassToSpawn = AEWorldContainer::StaticClass();
	}

	// Spawn container at saved position
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	AEWorldContainer* Container = GetWorld()->SpawnActor<AEWorldContainer>(
		ClassToSpawn,
		Data.Position,
		Data.Rotation.Rotator(),
		SpawnParams);

	if (Container)
	{
		// Initialize from database
		Container->InitializeFromDatabase(Data);
		
		// Configure container
		Container->ApiBaseUrl = ApiBaseUrl;
		Container->ServerSecret = ServerSecret;

		// Track spawned container
		SpawnedContainers.Add(Container);

		UE_LOG(LogTemp, Log, TEXT("WorldObjectManager: Spawned container at (%.1f, %.1f, %.1f), ObjectId=%s"),
			Data.Position.X, Data.Position.Y, Data.Position.Z,
			*Data.Id.ToString(EGuidFormats::Digits));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("WorldObjectManager: Failed to spawn container"));
	}
}

void UWorldObjectManager::OnQuerySuccess(const FString& Response)
{
	// Parse response
	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response);

	if (!FJsonSerializer::Deserialize(Reader, JsonObject) || !JsonObject.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("WorldObjectManager: Failed to parse query response"));
		return;
	}

	// Get objects array
	const TArray<TSharedPtr<FJsonValue>>* ObjectsArray;
	if (!JsonObject->TryGetArrayField(TEXT("Objects"), ObjectsArray))
	{
		UE_LOG(LogTemp, Error, TEXT("WorldObjectManager: No 'Objects' field in response"));
		return;
	}

	int32 TotalCount = JsonObject->GetIntegerField(TEXT("TotalCount"));
	UE_LOG(LogTemp, Log, TEXT("WorldObjectManager: Received %d world objects"), TotalCount);

	// Spawn each container
	for (const TSharedPtr<FJsonValue>& ObjectValue : *ObjectsArray)
	{
		TSharedPtr<FJsonObject> ObjectJson = ObjectValue->AsObject();
		if (!ObjectJson.IsValid())
		{
			continue;
		}

		// Parse world object data
		FWorldObjectData Data;
		
		FString IdString = ObjectJson->GetStringField(TEXT("Id"));
		FGuid::Parse(IdString, Data.Id);

		Data.TemplateId = ObjectJson->GetIntegerField(TEXT("TemplateId"));

		FString SystemIdString = ObjectJson->GetStringField(TEXT("SystemId"));
		FGuid::Parse(SystemIdString, Data.SystemId);

		Data.Position.X = ObjectJson->GetNumberField(TEXT("PosX"));
		Data.Position.Y = ObjectJson->GetNumberField(TEXT("PosY"));
		Data.Position.Z = ObjectJson->GetNumberField(TEXT("PosZ"));

		Data.Rotation.W = ObjectJson->GetNumberField(TEXT("RotW"));
		Data.Rotation.X = ObjectJson->GetNumberField(TEXT("RotX"));
		Data.Rotation.Y = ObjectJson->GetNumberField(TEXT("RotY"));
		Data.Rotation.Z = ObjectJson->GetNumberField(TEXT("RotZ"));

		Data.InventoryJson = ObjectJson->GetStringField(TEXT("InventoryJson"));

		// Spawn container
		ServerOnly_SpawnContainer(Data);
	}

	bWorldObjectsLoaded = true;
	UE_LOG(LogTemp, Log, TEXT("WorldObjectManager: Finished spawning %d containers"), SpawnedContainers.Num());
}

void UWorldObjectManager::OnQueryError(const FString& Error)
{
	UE_LOG(LogTemp, Error, TEXT("WorldObjectManager: Query error: %s"), *Error);
	// Mark as loaded even on error to prevent retry loops
	bWorldObjectsLoaded = true;
}
