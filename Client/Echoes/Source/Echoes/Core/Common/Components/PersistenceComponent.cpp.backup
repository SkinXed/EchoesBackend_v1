// Copyright Epic Games, Inc. All Rights Reserved.

#include "PersistenceComponent.h"
#include "EchoesStatsComponent.h"
#include "GameFramework/Actor.h"
#include "Http.h"
#include "Json.h"
#include "JsonUtilities.h"
#include "Engine/World.h"

UPersistenceComponent::UPersistenceComponent()
{
	// Enable tick for heartbeat timer
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.TickGroup = TG_PrePhysics;

	// This is a server-only component
	SetIsReplicatedByDefault(false);

	// Initialize state
	TimeSinceLastHeartbeat = 0.0f;
	CachedStatsComponent = nullptr;
	bSaveInProgress = false;
	SaveCount = 0;
	FailCount = 0;
}

void UPersistenceComponent::BeginPlay()
{
	Super::BeginPlay();

	// Only run on server
	if (!GetWorld() || !GetWorld()->GetAuthGameMode())
	{
		SetComponentTickEnabled(false);
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("PersistenceComponent: BeginPlay on server for Character %s"), 
		*CharacterId.ToString(EGuidFormats::Digits));

	// Cache stats component reference
	AActor* Owner = GetOwner();
	if (Owner)
	{
		CachedStatsComponent = Owner->FindComponentByClass<UEchoesStatsComponent>();
		if (!CachedStatsComponent)
		{
			UE_LOG(LogTemp, Warning, TEXT("PersistenceComponent: No EchoesStatsComponent found on owner %s"), 
				*Owner->GetName());
		}
	}

	// Initial state capture
	LastSavedState = ServerOnly_CollectCurrentState();
}

void UPersistenceComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	// Only run on server
	if (GetWorld() && GetWorld()->GetAuthGameMode())
	{
		// Logout Save: Guaranteed save on disconnect/logout
		UE_LOG(LogTemp, Log, TEXT("PersistenceComponent: EndPlay triggered, performing logout save for Character %s"), 
			*CharacterId.ToString(EGuidFormats::Digits));

		// Force save regardless of dirty flag
		FCommon_StateData CurrentState = ServerOnly_CollectCurrentState();
		ServerOnly_SaveToBackend(CurrentState);
	}

	Super::EndPlay(EndPlayReason);
}

void UPersistenceComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Only run on server
	if (!GetWorld() || !GetWorld()->GetAuthGameMode())
	{
		return;
	}

	// Heartbeat timer
	if (bEnableHeartbeat)
	{
		TimeSinceLastHeartbeat += DeltaTime;
		if (TimeSinceLastHeartbeat >= HeartbeatInterval)
		{
			ServerOnly_OnHeartbeatTimer();
			TimeSinceLastHeartbeat = 0.0f;
		}
	}
}

void UPersistenceComponent::Common_SetCharacterId(const FGuid& InCharacterId)
{
	CharacterId = InCharacterId;
	UE_LOG(LogTemp, Log, TEXT("PersistenceComponent: Character ID set to %s"), 
		*CharacterId.ToString(EGuidFormats::Digits));
}

void UPersistenceComponent::ServerOnly_TriggerSave()
{
	if (!GetWorld() || !GetWorld()->GetAuthGameMode())
	{
		UE_LOG(LogTemp, Warning, TEXT("PersistenceComponent: TriggerSave called on client, ignoring"));
		return;
	}

	FCommon_StateData CurrentState = ServerOnly_CollectCurrentState();
	
	// Check dirty flag if enabled
	if (bEnableDirtyFlag && !ServerOnly_IsDirty(CurrentState))
	{
		UE_LOG(LogTemp, Verbose, TEXT("PersistenceComponent: State not dirty, skipping save"));
		return;
	}

	ServerOnly_SaveToBackend(CurrentState);
}

FCommon_StateData UPersistenceComponent::ServerOnly_CollectCurrentState()
{
	FCommon_StateData State;

	AActor* Owner = GetOwner();
	if (!Owner)
	{
		UE_LOG(LogTemp, Error, TEXT("PersistenceComponent: No owner actor, cannot collect state"));
		return State;
	}

	// Collect position and rotation
	State.Position = Owner->GetActorLocation();
	State.Rotation = Owner->GetActorRotation().Quaternion();

	// Collect stats from EchoesStatsComponent
	if (CachedStatsComponent)
	{
		State.CurrentShield = CachedStatsComponent->ShieldCurrent;
		State.CurrentArmor = CachedStatsComponent->ArmorCurrent;
		State.CurrentHull = CachedStatsComponent->StructureCurrent;
		
		// TODO: Capacitor should come from ship power/capacitor component when available
		// For now, using DefaultCapacitorValue which can be configured per ship class
		State.CurrentCapacitor = DefaultCapacitorValue;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PersistenceComponent: No stats component, using default values"));
		State.CurrentShield = 0.0f;
		State.CurrentArmor = 0.0f;
		State.CurrentHull = 0.0f;
		State.CurrentCapacitor = 0.0f;
	}

	// TODO: Get LastSystemId from game mode or world state
	// For now, leaving as default (invalid GUID)

	return State;
}

bool UPersistenceComponent::ServerOnly_IsDirty(const FCommon_StateData& NewState) const
{
	// Check position change
	float PositionDelta = FVector::Dist(NewState.Position, LastSavedState.Position);
	if (PositionDelta >= DirtyPositionThreshold)
	{
		return true;
	}

	// Check stats changes
	const float StatEpsilon = 0.1f; // Allow small floating point differences
	if (FMath::Abs(NewState.CurrentShield - LastSavedState.CurrentShield) > StatEpsilon ||
		FMath::Abs(NewState.CurrentArmor - LastSavedState.CurrentArmor) > StatEpsilon ||
		FMath::Abs(NewState.CurrentHull - LastSavedState.CurrentHull) > StatEpsilon ||
		FMath::Abs(NewState.CurrentCapacitor - LastSavedState.CurrentCapacitor) > StatEpsilon)
	{
		return true;
	}

	return false;
}

void UPersistenceComponent::ServerOnly_SaveToBackend(const FCommon_StateData& StateData)
{
	if (bSaveInProgress)
	{
		UE_LOG(LogTemp, Warning, TEXT("PersistenceComponent: Save already in progress, skipping"));
		return;
	}

	if (!CharacterId.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("PersistenceComponent: Invalid Character ID, cannot save"));
		return;
	}

	bSaveInProgress = true;

	// Build JSON payload
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);

	// LastSystemId (nullable GUID)
	if (StateData.LastSystemId.IsValid())
	{
		JsonObject->SetStringField(TEXT("lastSystemId"), StateData.LastSystemId.ToString(EGuidFormats::Digits));
	}

	// Position
	JsonObject->SetNumberField(TEXT("posX"), StateData.Position.X);
	JsonObject->SetNumberField(TEXT("posY"), StateData.Position.Y);
	JsonObject->SetNumberField(TEXT("posZ"), StateData.Position.Z);

	// Rotation (quaternion)
	JsonObject->SetNumberField(TEXT("rotW"), StateData.Rotation.W);
	JsonObject->SetNumberField(TEXT("rotX"), StateData.Rotation.X);
	JsonObject->SetNumberField(TEXT("rotY"), StateData.Rotation.Y);
	JsonObject->SetNumberField(TEXT("rotZ"), StateData.Rotation.Z);

	// Stats
	JsonObject->SetNumberField(TEXT("currentShield"), StateData.CurrentShield);
	JsonObject->SetNumberField(TEXT("currentArmor"), StateData.CurrentArmor);
	JsonObject->SetNumberField(TEXT("currentHull"), StateData.CurrentHull);
	JsonObject->SetNumberField(TEXT("currentCapacitor"), StateData.CurrentCapacitor);

	// Serialize to JSON string
	FString Content;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&Content);
	FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);

	// Create HTTP request
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();

	FString Endpoint = FString::Printf(TEXT("/persistence/state/%s"), 
		*CharacterId.ToString(EGuidFormats::Digits));
	FString FullUrl = ApiBaseUrl + Endpoint;

	Request->SetURL(FullUrl);
	Request->SetVerb(TEXT("PUT"));
	Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	Request->SetHeader(TEXT("X-Server-Secret"), ServerSecret);
	Request->SetContentAsString(Content);

	// Bind response callback
	Request->OnProcessRequestComplete().BindLambda(
		[this, StateData](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
		{
			bSaveInProgress = false;

			if (!bWasSuccessful || !Response.IsValid())
			{
				FailCount++;
				UE_LOG(LogTemp, Error, TEXT("PersistenceComponent: HTTP request failed"));
				OnSaveError(TEXT("Network error"));
				return;
			}

			int32 ResponseCode = Response->GetResponseCode();
			FString ResponseBody = Response->GetContentAsString();

			if (ResponseCode >= 200 && ResponseCode < 300)
			{
				SaveCount++;
				LastSavedState = StateData; // Update last saved state
				UE_LOG(LogTemp, Log, TEXT("PersistenceComponent: State saved successfully (Total: %d)"), SaveCount);
				OnSaveSuccess(ResponseBody);
			}
			else
			{
				FailCount++;
				UE_LOG(LogTemp, Error, TEXT("PersistenceComponent: HTTP request failed with code %d: %s"), 
					ResponseCode, *ResponseBody);
				OnSaveError(FString::Printf(TEXT("HTTP %d: %s"), ResponseCode, *ResponseBody));
			}
		}
	);

	// Execute request
	Request->ProcessRequest();

	UE_LOG(LogTemp, Log, TEXT("PersistenceComponent: Sending state save request to %s"), *FullUrl);
	UE_LOG(LogTemp, Verbose, TEXT("PersistenceComponent: Payload: %s"), *Content);
}

void UPersistenceComponent::ServerOnly_OnHeartbeatTimer()
{
	UE_LOG(LogTemp, Verbose, TEXT("PersistenceComponent: Heartbeat timer triggered"));

	FCommon_StateData CurrentState = ServerOnly_CollectCurrentState();

	// Check dirty flag if enabled
	if (bEnableDirtyFlag && !ServerOnly_IsDirty(CurrentState))
	{
		UE_LOG(LogTemp, Verbose, TEXT("PersistenceComponent: State not dirty, skipping heartbeat save"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("PersistenceComponent: Performing heartbeat save"));
	ServerOnly_SaveToBackend(CurrentState);
}

void UPersistenceComponent::OnSaveSuccess(const FString& Response)
{
	// Parse response if needed
	// For now, just log success
	UE_LOG(LogTemp, Log, TEXT("PersistenceComponent: Save successful"));
	
	// Optional: Notify client via RPC for UI feedback
	// ClientRPC_NotifyPersistenceStatus(true, TEXT("Saved"));
}

void UPersistenceComponent::OnSaveError(const FString& Error)
{
	UE_LOG(LogTemp, Error, TEXT("PersistenceComponent: Save error: %s"), *Error);
	
	// Optional: Notify client via RPC for UI feedback
	// ClientRPC_NotifyPersistenceStatus(false, Error);
}
