// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesPersistenceSubsystem.h"
#include "Http.h"
#include "Json.h"
#include "JsonUtilities.h"
#include "Engine/World.h"
#include "TimerManager.h"

void UEchoesPersistenceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	TotalSaveCount = 0;
	TotalFailCount = 0;
	bSaveInProgress = false;

	UE_LOG(LogTemp, Log, TEXT("EchoesPersistenceSubsystem: Initialized. API URL: %s"), *ApiBaseUrl);

	// Get world reference
	CachedWorld = GetWorld();
	if (CachedWorld)
	{
		// Start queue processing timer
		CachedWorld->GetTimerManager().SetTimer(
			QueueProcessTimerHandle,
			this,
			&UEchoesPersistenceSubsystem::ProcessSaveQueue,
			QueueProcessInterval,
			true // Loop
		);

		UE_LOG(LogTemp, Log, TEXT("EchoesPersistenceSubsystem: Queue processing timer started (%.1f seconds)"), 
			QueueProcessInterval);
	}
}

void UEchoesPersistenceSubsystem::Deinitialize()
{
	// Clear timer
	if (CachedWorld && QueueProcessTimerHandle.IsValid())
	{
		CachedWorld->GetTimerManager().ClearTimer(QueueProcessTimerHandle);
	}

	// Process any remaining queued saves before shutdown
	if (SaveQueue.Num() > 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("EchoesPersistenceSubsystem: Shutting down with %d queued saves"), 
			SaveQueue.Num());

		// Try to send high priority saves
		for (const FPersistenceSaveRequest& Request : SaveQueue)
		{
			if (Request.bHighPriority)
			{
				SendSaveRequest(Request);
			}
		}
	}

	UE_LOG(LogTemp, Log, TEXT("EchoesPersistenceSubsystem: Deinitialized. Total Saves: %d, Failures: %d"),
		TotalSaveCount, TotalFailCount);

	Super::Deinitialize();
}

bool UEchoesPersistenceSubsystem::ServerOnly_QueueStateSave(
	const FGuid& CharacterId, 
	const FCommon_StateData& StateData)
{
	// Check queue size
	if (SaveQueue.Num() >= MaxQueueSize)
	{
		UE_LOG(LogTemp, Warning, TEXT("EchoesPersistenceSubsystem: Queue full (%d), dropping oldest request"),
			MaxQueueSize);

		// Remove oldest non-priority request
		for (int32 i = 0; i < SaveQueue.Num(); i++)
		{
			if (!SaveQueue[i].bHighPriority)
			{
				SaveQueue.RemoveAt(i);
				break;
			}
		}
	}

	// Create save request
	FPersistenceSaveRequest Request;
	Request.CharacterId = CharacterId;
	Request.StateData = StateData;
	Request.bHighPriority = false;
	Request.QueuedTime = FDateTime::UtcNow();

	SaveQueue.Add(Request);

	UE_LOG(LogTemp, Verbose, TEXT("EchoesPersistenceSubsystem: Queued save for character %s (Queue: %d)"),
		*CharacterId.ToString(EGuidFormats::Digits), SaveQueue.Num());

	return true;
}

void UEchoesPersistenceSubsystem::ServerOnly_SaveStateImmediate(
	const FGuid& CharacterId,
	const FCommon_StateData& StateData)
{
	UE_LOG(LogTemp, Log, TEXT("EchoesPersistenceSubsystem: Immediate save requested for character %s"),
		*CharacterId.ToString(EGuidFormats::Digits));

	// Create high priority request
	FPersistenceSaveRequest Request;
	Request.CharacterId = CharacterId;
	Request.StateData = StateData;
	Request.bHighPriority = true;
	Request.QueuedTime = FDateTime::UtcNow();
	Request.SequenceNumber = Request.QueuedTime.GetTicks();

	// Send immediately (bypass queue)
	SendSaveRequest(Request);
}

void UEchoesPersistenceSubsystem::ProcessSaveQueue()
{
	// Don't process if save is in progress or queue is empty
	if (bSaveInProgress || SaveQueue.Num() == 0)
	{
		return;
	}

	// Check if bulk save is enabled
	if (bEnableBulkSave && SaveQueue.Num() > 1)
	{
		// Use bulk processing for efficiency
		ServerOnly_ProcessQueueBulk(MaxBulkBatchSize);
		return;
	}

	// Fallback to single request processing (legacy or single item)
	// Get next request (prioritize high priority requests)
	FPersistenceSaveRequest Request;
	int32 RequestIndex = -1;

	// First, look for high priority requests
	for (int32 i = 0; i < SaveQueue.Num(); i++)
	{
		if (SaveQueue[i].bHighPriority)
		{
			Request = SaveQueue[i];
			RequestIndex = i;
			break;
		}
	}

	// If no high priority, get oldest request
	if (RequestIndex == -1 && SaveQueue.Num() > 0)
	{
		Request = SaveQueue[0];
		RequestIndex = 0;
	}

	// Remove from queue
	if (RequestIndex >= 0)
	{
		SaveQueue.RemoveAt(RequestIndex);
		SendSaveRequest(Request);
	}
}

void UEchoesPersistenceSubsystem::ServerOnly_ProcessQueueBulk(int32 MaxBatchCount)
{
	if (bSaveInProgress || SaveQueue.Num() == 0)
	{
		return;
	}

	// Determine batch size (up to MaxBatchCount or queue size, whichever is smaller)
	int32 BatchSize = FMath::Min(SaveQueue.Num(), MaxBatchCount);
	
	// Collect requests for bulk processing
	TArray<FPersistenceSaveRequest> BatchRequests;
	BatchRequests.Reserve(BatchSize);

	// Prioritize high priority requests first
	for (int32 i = SaveQueue.Num() - 1; i >= 0 && BatchRequests.Num() < BatchSize; i--)
	{
		if (SaveQueue[i].bHighPriority)
		{
			BatchRequests.Add(SaveQueue[i]);
			SaveQueue.RemoveAt(i);
		}
	}

	// Fill remaining batch with normal priority requests (oldest first)
	while (BatchRequests.Num() < BatchSize && SaveQueue.Num() > 0)
	{
		BatchRequests.Add(SaveQueue[0]);
		SaveQueue.RemoveAt(0);
	}

	if (BatchRequests.Num() == 0)
	{
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("EchoesPersistenceSubsystem: Processing bulk save with %d requests"), 
		BatchRequests.Num());

	// Send bulk request
	SendBulkSaveRequest(BatchRequests);
}

void UEchoesPersistenceSubsystem::SendSaveRequest(const FPersistenceSaveRequest& Request)
{
	if (!Request.CharacterId.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("EchoesPersistenceSubsystem: Invalid Character ID, cannot save"));
		return;
	}

	bSaveInProgress = true;

	// Build JSON payload with sequence number
	FString JsonPayload = BuildJsonPayload(Request.StateData, Request.SequenceNumber);

	// Create HTTP request
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = FHttpModule::Get().CreateRequest();

	FString Endpoint = FString::Printf(TEXT("/persistence/state/%s"), 
		*Request.CharacterId.ToString(EGuidFormats::Digits));
	FString FullUrl = ApiBaseUrl + Endpoint;

	HttpRequest->SetURL(FullUrl);
	HttpRequest->SetVerb(TEXT("PUT"));
	HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	HttpRequest->SetHeader(TEXT("X-Server-Secret"), ServerSecret);
	HttpRequest->SetContentAsString(JsonPayload);

	// Bind response callback
	FGuid CharacterId = Request.CharacterId; // Capture for lambda
	HttpRequest->OnProcessRequestComplete().BindLambda(
		[this, CharacterId](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
		{
			bSaveInProgress = false;

			if (!bWasSuccessful || !Response.IsValid())
			{
				TotalFailCount++;
				UE_LOG(LogTemp, Error, TEXT("EchoesPersistenceSubsystem: HTTP request failed for character %s"),
					*CharacterId.ToString(EGuidFormats::Digits));
				OnSaveError(CharacterId, TEXT("Network error"));
				return;
			}

			int32 ResponseCode = Response->GetResponseCode();
			FString ResponseBody = Response->GetContentAsString();

			if (ResponseCode >= 200 && ResponseCode < 300)
			{
				TotalSaveCount++;
				UE_LOG(LogTemp, Verbose, TEXT("EchoesPersistenceSubsystem: Save successful for character %s (Total: %d)"),
					*CharacterId.ToString(EGuidFormats::Digits), TotalSaveCount);
				OnSaveSuccess(CharacterId, ResponseBody);
			}
			else
			{
				TotalFailCount++;
				UE_LOG(LogTemp, Error, TEXT("EchoesPersistenceSubsystem: HTTP request failed with code %d: %s"),
					ResponseCode, *ResponseBody);
				OnSaveError(CharacterId, FString::Printf(TEXT("HTTP %d: %s"), ResponseCode, *ResponseBody));
			}
		}
	);

	// Execute request
	HttpRequest->ProcessRequest();

	UE_LOG(LogTemp, Verbose, TEXT("EchoesPersistenceSubsystem: Sending save request to %s"), *FullUrl);
}

void UEchoesPersistenceSubsystem::SendBulkSaveRequest(const TArray<FPersistenceSaveRequest>& Requests)
{
	if (Requests.Num() == 0)
	{
		return;
	}

	bSaveInProgress = true;

	// Build bulk JSON payload
	FString JsonPayload = BuildBulkJsonPayload(Requests);

	// Create HTTP request
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = FHttpModule::Get().CreateRequest();

	FString Endpoint = TEXT("/persistence/state/bulk");
	FString FullUrl = ApiBaseUrl + Endpoint;

	HttpRequest->SetURL(FullUrl);
	HttpRequest->SetVerb(TEXT("POST"));
	HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	HttpRequest->SetHeader(TEXT("X-Server-Secret"), ServerSecret);
	HttpRequest->SetContentAsString(JsonPayload);

	// Bind response callback
	int32 RequestCount = Requests.Num();
	HttpRequest->OnProcessRequestComplete().BindLambda(
		[this, RequestCount](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
		{
			bSaveInProgress = false;

			if (!bWasSuccessful || !Response.IsValid())
			{
				TotalFailCount += RequestCount;
				UE_LOG(LogTemp, Error, TEXT("EchoesPersistenceSubsystem: Bulk HTTP request failed"));
				OnBulkSaveError(TEXT("Network error"));
				return;
			}

			int32 ResponseCode = Response->GetResponseCode();
			FString ResponseBody = Response->GetContentAsString();

			if (ResponseCode >= 200 && ResponseCode < 300)
			{
				// Parse response to get actual save count
				TSharedPtr<FJsonObject> JsonObject;
				TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(ResponseBody);
				
				if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
				{
					int32 SavedCount = JsonObject->GetIntegerField(TEXT("savedCount"));
					int32 SkippedCount = JsonObject->GetIntegerField(TEXT("skippedCount"));
					int32 FailedCount = JsonObject->GetIntegerField(TEXT("failedCount"));
					
					TotalSaveCount += SavedCount;
					TotalFailCount += FailedCount;
					
					UE_LOG(LogTemp, Log, TEXT("EchoesPersistenceSubsystem: Bulk save completed - Saved: %d, Skipped: %d, Failed: %d"),
						SavedCount, SkippedCount, FailedCount);
				}
				else
				{
					TotalSaveCount += RequestCount;
					UE_LOG(LogTemp, Log, TEXT("EchoesPersistenceSubsystem: Bulk save successful for %d requests"), RequestCount);
				}
				
				OnBulkSaveSuccess(ResponseBody);
			}
			else
			{
				TotalFailCount += RequestCount;
				UE_LOG(LogTemp, Error, TEXT("EchoesPersistenceSubsystem: Bulk HTTP request failed with code %d: %s"),
					ResponseCode, *ResponseBody);
				OnBulkSaveError(FString::Printf(TEXT("HTTP %d: %s"), ResponseCode, *ResponseBody));
			}
		}
	);

	// Execute request
	HttpRequest->ProcessRequest();

	UE_LOG(LogTemp, Verbose, TEXT("EchoesPersistenceSubsystem: Sending bulk save request to %s with %d items"), 
		*FullUrl, Requests.Num());
}

FString UEchoesPersistenceSubsystem::BuildJsonPayload(const FCommon_StateData& StateData, int64 SequenceNumber)
{
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

	// Sequence number for optimistic concurrency control
	JsonObject->SetNumberField(TEXT("sequenceNumber"), static_cast<double>(SequenceNumber));

	// Serialize to JSON string
	FString Content;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&Content);
	FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);

	return Content;
}

FString UEchoesPersistenceSubsystem::BuildBulkJsonPayload(const TArray<FPersistenceSaveRequest>& Requests)
{
	// Build bulk JSON payload
	TSharedPtr<FJsonObject> RootObject = MakeShareable(new FJsonObject);
	TArray<TSharedPtr<FJsonValue>> StatesArray;

	for (const FPersistenceSaveRequest& Request : Requests)
	{
		TSharedPtr<FJsonObject> StateObject = MakeShareable(new FJsonObject);

		// Character ID
		StateObject->SetStringField(TEXT("characterId"), Request.CharacterId.ToString(EGuidFormats::Digits));

		// Sequence number
		StateObject->SetNumberField(TEXT("sequenceNumber"), static_cast<double>(Request.SequenceNumber));

		// LastSystemId (nullable GUID)
		if (Request.StateData.LastSystemId.IsValid())
		{
			StateObject->SetStringField(TEXT("lastSystemId"), 
				Request.StateData.LastSystemId.ToString(EGuidFormats::Digits));
		}

		// Position
		StateObject->SetNumberField(TEXT("posX"), Request.StateData.Position.X);
		StateObject->SetNumberField(TEXT("posY"), Request.StateData.Position.Y);
		StateObject->SetNumberField(TEXT("posZ"), Request.StateData.Position.Z);

		// Rotation (quaternion)
		StateObject->SetNumberField(TEXT("rotW"), Request.StateData.Rotation.W);
		StateObject->SetNumberField(TEXT("rotX"), Request.StateData.Rotation.X);
		StateObject->SetNumberField(TEXT("rotY"), Request.StateData.Rotation.Y);
		StateObject->SetNumberField(TEXT("rotZ"), Request.StateData.Rotation.Z);

		// Stats
		StateObject->SetNumberField(TEXT("currentShield"), Request.StateData.CurrentShield);
		StateObject->SetNumberField(TEXT("currentArmor"), Request.StateData.CurrentArmor);
		StateObject->SetNumberField(TEXT("currentHull"), Request.StateData.CurrentHull);
		StateObject->SetNumberField(TEXT("currentCapacitor"), Request.StateData.CurrentCapacitor);

		// Add to array
		StatesArray.Add(MakeShareable(new FJsonValueObject(StateObject)));
	}

	// Set states array in root object
	RootObject->SetArrayField(TEXT("states"), StatesArray);

	// Serialize to JSON string
	FString Content;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&Content);
	FJsonSerializer::Serialize(RootObject.ToSharedRef(), Writer);

	return Content;
}

void UEchoesPersistenceSubsystem::OnSaveSuccess(const FGuid& CharacterId, const FString& Response)
{
	// Success callback - can be extended for additional logic
	UE_LOG(LogTemp, Verbose, TEXT("EchoesPersistenceSubsystem: Save confirmed for character %s"),
		*CharacterId.ToString(EGuidFormats::Digits));
}

void UEchoesPersistenceSubsystem::OnBulkSaveSuccess(const FString& Response)
{
	// Success callback for bulk save
	UE_LOG(LogTemp, Verbose, TEXT("EchoesPersistenceSubsystem: Bulk save confirmed"));
}

void UEchoesPersistenceSubsystem::OnSaveError(const FGuid& CharacterId, const FString& Error)
{
	// Error callback - can be extended for retry logic
	UE_LOG(LogTemp, Error, TEXT("EchoesPersistenceSubsystem: Save error for character %s: %s"),
		*CharacterId.ToString(EGuidFormats::Digits), *Error);
}

void UEchoesPersistenceSubsystem::OnBulkSaveError(const FString& Error)
{
	// Error callback for bulk save
	UE_LOG(LogTemp, Error, TEXT("EchoesPersistenceSubsystem: Bulk save error: %s"), *Error);
}
