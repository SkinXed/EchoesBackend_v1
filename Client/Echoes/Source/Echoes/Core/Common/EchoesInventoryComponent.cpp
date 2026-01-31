// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesInventoryComponent.h"
#include "Networking/EchoesAuthSubsystem.h"
#include "HttpModule.h"
#include "Interfaces/IHttpResponse.h"
#include "JsonObjectConverter.h"
#include "Kismet/GameplayStatics.h"

UEchoesInventoryComponent::UEchoesInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UEchoesInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
	
	// Initialize with empty cache
	CachedItems = FEchoesContainerItems();
}

void UEchoesInventoryComponent::InitializeStorage(const FGuid& InStorageId, float InCapacity)
{
	StorageId = InStorageId;
	Capacity = InCapacity;
	UsedVolume = 0.0f;
	
	UE_LOG(LogTemp, Log, TEXT("EchoesInventoryComponent: Initialized storage ID=%s, Capacity=%.2f"),
		*StorageId.ToString(), Capacity);
}

void UEchoesInventoryComponent::FetchItems(
	FOnItemsFetched OnSuccess,
	FOnInventoryOperationFailure OnFailure)
{
	if (!StorageId.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("EchoesInventoryComponent: Cannot fetch items - StorageId is invalid"));
		OnFailure.ExecuteIfBound(TEXT("Storage ID is not initialized"));
		return;
	}

	// Get auth token
	FString Token = GetAuthToken();
	if (Token.IsEmpty())
	{
		UE_LOG(LogTemp, Error, TEXT("EchoesInventoryComponent: No auth token available"));
		OnFailure.ExecuteIfBound(TEXT("Authentication required"));
		return;
	}

	// Create HTTP request
	FString Url = FString::Printf(TEXT("%s/api/inventory/container/%s"),
		*GetApiBaseUrl(),
		*StorageId.ToString());

	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();
	Request->SetVerb(TEXT("GET"));
	Request->SetURL(Url);
	Request->SetHeader(TEXT("Authorization"), FString::Printf(TEXT("Bearer %s"), *Token));
	Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));

	// Bind response handler
	Request->OnProcessRequestComplete().BindUObject(
		this,
		&UEchoesInventoryComponent::OnItemsFetchResponse,
		OnSuccess,
		OnFailure);

	// Send request
	if (!Request->ProcessRequest())
	{
		UE_LOG(LogTemp, Error, TEXT("EchoesInventoryComponent: Failed to send fetch items request"));
		OnFailure.ExecuteIfBound(TEXT("Failed to send request"));
	}
}

bool UEchoesInventoryComponent::CanFitItem(float ItemVolume) const
{
	if (Capacity <= 0.0f)
	{
		return true; // Unlimited capacity
	}
	
	return (UsedVolume + ItemVolume) <= Capacity;
}

void UEchoesInventoryComponent::ServerOnly_MoveItem(
	const FGuid& AssetId,
	AActor* TargetActor,
	AActor* SourceActor,
	int64 Quantity,
	FOnItemMoveSuccess OnSuccess,
	FOnInventoryOperationFailure OnFailure)
{
	// Validate this is server
	if (!GetWorld() || GetWorld()->GetNetMode() == NM_Client)
	{
		UE_LOG(LogTemp, Error, TEXT("EchoesInventoryComponent: ServerOnly_MoveItem called on client"));
		OnFailure.ExecuteIfBound(TEXT("This operation must be executed on the server"));
		return;
	}

	// Validate parameters
	if (!AssetId.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("EchoesInventoryComponent: Invalid AssetId"));
		OnFailure.ExecuteIfBound(TEXT("Invalid asset ID"));
		return;
	}

	if (!TargetActor || !SourceActor)
	{
		UE_LOG(LogTemp, Error, TEXT("EchoesInventoryComponent: Null actors provided"));
		OnFailure.ExecuteIfBound(TEXT("Source and target actors required"));
		return;
	}

	// Get target inventory component
	UEchoesInventoryComponent* TargetInventory = TargetActor->FindComponentByClass<UEchoesInventoryComponent>();
	if (!TargetInventory)
	{
		UE_LOG(LogTemp, Error, TEXT("EchoesInventoryComponent: Target actor has no inventory component"));
		OnFailure.ExecuteIfBound(TEXT("Target has no inventory"));
		return;
	}

	// Check distance between source and target
	if (!IsWithinTransferDistance(SourceActor, TargetActor))
	{
		float Distance = FVector::Dist(SourceActor->GetActorLocation(), TargetActor->GetActorLocation());
		UE_LOG(LogTemp, Warning, TEXT("EchoesInventoryComponent: Transfer distance exceeded. Distance=%.2f, Max=%.2f"),
			Distance / 100.0f, MaxTransferDistance / 100.0f); // Convert to meters for log
		OnFailure.ExecuteIfBound(FString::Printf(TEXT("Target too far away (%.0fm)"), Distance / 100.0f));
		return;
	}

	// Get auth token
	FString Token = GetAuthToken();
	if (Token.IsEmpty())
	{
		UE_LOG(LogTemp, Error, TEXT("EchoesInventoryComponent: No auth token available"));
		OnFailure.ExecuteIfBound(TEXT("Authentication required"));
		return;
	}

	// Create request payload
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());
	JsonObject->SetStringField(TEXT("assetId"), AssetId.ToString());
	JsonObject->SetStringField(TEXT("targetLocationId"), TargetInventory->StorageId.ToString());
	JsonObject->SetNumberField(TEXT("targetFlag"), 0); // Default to Cargo flag
	
	if (Quantity > 0)
	{
		JsonObject->SetNumberField(TEXT("splitQuantity"), Quantity);
	}

	FString JsonString;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&JsonString);
	FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);

	// Create HTTP request
	FString Url = FString::Printf(TEXT("%s/api/inventory/operations/move"), *GetApiBaseUrl());

	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();
	Request->SetVerb(TEXT("POST"));
	Request->SetURL(Url);
	Request->SetHeader(TEXT("Authorization"), FString::Printf(TEXT("Bearer %s"), *Token));
	Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	Request->SetContentAsString(JsonString);

	// Bind response handler
	Request->OnProcessRequestComplete().BindUObject(
		this,
		&UEchoesInventoryComponent::OnItemMoveResponse,
		OnSuccess,
		OnFailure);

	// Send request
	if (!Request->ProcessRequest())
	{
		UE_LOG(LogTemp, Error, TEXT("EchoesInventoryComponent: Failed to send move item request"));
		OnFailure.ExecuteIfBound(TEXT("Failed to send request"));
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("EchoesInventoryComponent: Move request sent - Asset=%s, Source=%s, Target=%s"),
			*AssetId.ToString(),
			*StorageId.ToString(),
			*TargetInventory->StorageId.ToString());
	}
}

void UEchoesInventoryComponent::OnItemsFetchResponse(
	FHttpRequestPtr Request,
	FHttpResponsePtr Response,
	bool bWasSuccessful,
	FOnItemsFetched OnSuccess,
	FOnInventoryOperationFailure OnFailure)
{
	if (!bWasSuccessful || !Response.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("EchoesInventoryComponent: Items fetch failed - no response"));
		OnFailure.ExecuteIfBound(TEXT("Network error"));
		return;
	}

	int32 ResponseCode = Response->GetResponseCode();
	FString ResponseBody = Response->GetContentAsString();

	if (ResponseCode == 200)
	{
		FEchoesContainerItems Items;
		if (ParseItemsList(ResponseBody, Items))
		{
			CachedItems = Items;
			UsedVolume = Items.TotalVolume;
			
			UE_LOG(LogTemp, Log, TEXT("EchoesInventoryComponent: Fetched %d items, total volume: %.2f"),
				Items.TotalCount, Items.TotalVolume);
			
			OnSuccess.ExecuteIfBound(Items);
			
			// Trigger update delegate for UI
			OnInventoryUpdated.Broadcast(Items);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("EchoesInventoryComponent: Failed to parse items response"));
			OnFailure.ExecuteIfBound(TEXT("Failed to parse response"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("EchoesInventoryComponent: Items fetch failed - HTTP %d: %s"),
			ResponseCode, *ResponseBody);
		OnFailure.ExecuteIfBound(FString::Printf(TEXT("Server error: %d"), ResponseCode));
	}
}

void UEchoesInventoryComponent::OnItemMoveResponse(
	FHttpRequestPtr Request,
	FHttpResponsePtr Response,
	bool bWasSuccessful,
	FOnItemMoveSuccess OnSuccess,
	FOnInventoryOperationFailure OnFailure)
{
	if (!bWasSuccessful || !Response.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("EchoesInventoryComponent: Item move failed - no response"));
		OnFailure.ExecuteIfBound(TEXT("Network error"));
		return;
	}

	int32 ResponseCode = Response->GetResponseCode();
	FString ResponseBody = Response->GetContentAsString();

	if (ResponseCode == 200)
	{
		UE_LOG(LogTemp, Log, TEXT("EchoesInventoryComponent: Item move successful"));
		
		// Refresh items to update cache
		FetchItems(
			FOnItemsFetched::CreateLambda([this, OnSuccess](const FEchoesContainerItems& Items)
			{
				// Items updated, trigger delegate
				OnInventoryUpdated.Broadcast(Items);
				OnSuccess.ExecuteIfBound();
			}),
			FOnInventoryOperationFailure::CreateLambda([this, OnSuccess](const FString& Error)
			{
				UE_LOG(LogTemp, Warning, TEXT("EchoesInventoryComponent: Failed to refresh after move: %s"), *Error);
				// Still report success since the move itself succeeded
				// Just log the warning and proceed with success
				OnSuccess.ExecuteIfBound();
			})
		);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("EchoesInventoryComponent: Item move failed - HTTP %d: %s"),
			ResponseCode, *ResponseBody);
		OnFailure.ExecuteIfBound(FString::Printf(TEXT("Server error: %d"), ResponseCode));
	}
}

bool UEchoesInventoryComponent::ParseItemsList(const FString& JsonString, FEchoesContainerItems& OutItems)
{
	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(JsonString);

	if (!FJsonSerializer::Deserialize(Reader, JsonObject) || !JsonObject.IsValid())
	{
		return false;
	}

	// Parse response
	OutItems.Items.Empty();
	OutItems.TotalCount = JsonObject->GetIntegerField(TEXT("totalCount"));
	OutItems.TotalVolume = JsonObject->GetNumberField(TEXT("totalVolume"));

	const TArray<TSharedPtr<FJsonValue>>* ItemsArray;
	if (JsonObject->TryGetArrayField(TEXT("assets"), ItemsArray))
	{
		for (const TSharedPtr<FJsonValue>& ItemValue : *ItemsArray)
		{
			TSharedPtr<FJsonObject> ItemObject = ItemValue->AsObject();
			if (!ItemObject.IsValid())
			{
				continue;
			}

			FEchoesInventoryItem Item;
			
			// Parse asset ID
			FString AssetIdStr = ItemObject->GetStringField(TEXT("assetId"));
			FGuid::Parse(AssetIdStr, Item.AssetId);

			// Parse item type
			TSharedPtr<FJsonObject> ItemTypeObject = ItemObject->GetObjectField(TEXT("itemType"));
			if (ItemTypeObject.IsValid())
			{
				Item.TypeId = ItemTypeObject->GetIntegerField(TEXT("typeId"));
				Item.TypeName = ItemTypeObject->GetStringField(TEXT("name"));
				Item.Volume = ItemTypeObject->GetNumberField(TEXT("volume"));
				Item.IsStackable = ItemTypeObject->GetBoolField(TEXT("isStackable"));
			}

			Item.Quantity = ItemObject->GetNumberField(TEXT("quantity"));
			Item.TotalVolume = ItemObject->GetNumberField(TEXT("totalVolume"));

			OutItems.Items.Add(Item);
		}
	}

	return true;
}

FString UEchoesInventoryComponent::GetAuthToken() const
{
	UGameInstance* GameInstance = GetWorld() ? GetWorld()->GetGameInstance() : nullptr;
	if (!GameInstance)
	{
		return FString();
	}

	UEchoesAuthSubsystem* AuthSubsystem = GameInstance->GetSubsystem<UEchoesAuthSubsystem>();
	if (!AuthSubsystem)
	{
		return FString();
	}

	return AuthSubsystem->Auth_GetToken();
}

FString UEchoesInventoryComponent::GetApiBaseUrl() const
{
	// Default to localhost for development
	// This should be configurable via game settings
	return TEXT("http://localhost:5116");
}

bool UEchoesInventoryComponent::IsWithinTransferDistance(AActor* ActorA, AActor* ActorB) const
{
	if (!ActorA || !ActorB)
	{
		return false;
	}

	float Distance = FVector::Dist(ActorA->GetActorLocation(), ActorB->GetActorLocation());
	return Distance <= MaxTransferDistance;
}
