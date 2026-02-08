// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesPersistenceSubsystem.h"
#include "EchoesAuthSubsystem.h"
#include "EchoesIdentitySubsystem.h"
#include "EchoesInventorySubsystem.h"
#include "EchoesMarketSubsystem.h"
#include "HttpModule.h"
#include "Interfaces/IHttpResponse.h"
#include "Json.h"
#include "Misc/ConfigCacheIni.h"

DEFINE_LOG_CATEGORY(LogEchoesPersistence);

void UEchoesPersistenceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	Http = &FHttpModule::Get();
	SyncState = EPersistenceSyncState::Idle;

	// Bind to market subsystem events when it becomes available
	BindToMarketSubsystem();

	UE_LOG(LogEchoesPersistence, Log, TEXT("EchoesPersistenceSubsystem initialized"));
}

void UEchoesPersistenceSubsystem::Deinitialize()
{
	Super::Deinitialize();

	SyncState = EPersistenceSyncState::Idle;
	CachedState = FPersistenceCharacterState();

	UE_LOG(LogEchoesPersistence, Log, TEXT("EchoesPersistenceSubsystem deinitialized"));
}

// ==================== Server-Only Functions ====================

void UEchoesPersistenceSubsystem::ServerOnly_ForceSaveState()
{
	if (SyncState == EPersistenceSyncState::Syncing)
	{
		UE_LOG(LogEchoesPersistence, Warning, TEXT("[SYNC] Sync already in progress, skipping duplicate request"));
		return;
	}

	if (!Http)
	{
		UE_LOG(LogEchoesPersistence, Error, TEXT("[SYNC] HTTP module not available"));
		OnSyncFailed.Broadcast(TEXT("HTTP module not available"));
		return;
	}

	SyncState = EPersistenceSyncState::Syncing;

	UE_LOG(LogEchoesPersistence, Log, TEXT("[SYNC BEGIN] Forcing full state sync from backend"));

	// GET /api/character/me — returns latest character state including wallet
	FString Url = GetApiBaseUrl() + TEXT("/character/me");

	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = Http->CreateRequest();
	HttpRequest->SetVerb(TEXT("GET"));
	HttpRequest->SetURL(Url);
	HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	HttpRequest->SetHeader(TEXT("Authorization"), TEXT("Bearer ") + GetAuthToken());
	HttpRequest->SetHeader(TEXT("X-Server-Secret"), GetServerSecret());

	HttpRequest->OnProcessRequestComplete().BindUObject(
		this,
		&UEchoesPersistenceSubsystem::OnCharacterStateReceived,
		true /* bRefreshInventory */);

	if (!HttpRequest->ProcessRequest())
	{
		SyncState = EPersistenceSyncState::Error;
		UE_LOG(LogEchoesPersistence, Error, TEXT("[SYNC FAIL] Failed to send state sync request"));
		OnSyncFailed.Broadcast(TEXT("Failed to send sync request"));
	}
}

void UEchoesPersistenceSubsystem::ServerOnly_ForceSaveStateForCharacter(const FGuid& CharacterId)
{
	if (!CharacterId.IsValid())
	{
		UE_LOG(LogEchoesPersistence, Error, TEXT("[SYNC] Invalid CharacterId"));
		return;
	}

	UE_LOG(LogEchoesPersistence, Log, TEXT("[SYNC] Force save state for CharacterId=%s"), *CharacterId.ToString());
	ServerOnly_ForceSaveState();
}

void UEchoesPersistenceSubsystem::ServerOnly_SyncWallet()
{
	if (SyncState == EPersistenceSyncState::Syncing)
	{
		UE_LOG(LogEchoesPersistence, Warning, TEXT("[WALLET SYNC] Sync already in progress, skipping"));
		return;
	}

	if (!Http)
	{
		UE_LOG(LogEchoesPersistence, Error, TEXT("[WALLET SYNC] HTTP module not available"));
		OnSyncFailed.Broadcast(TEXT("HTTP module not available"));
		return;
	}

	SyncState = EPersistenceSyncState::Syncing;

	UE_LOG(LogEchoesPersistence, Log, TEXT("[WALLET SYNC BEGIN] Syncing wallet from backend"));

	// GET /api/character/me — lightweight wallet check (no inventory refresh)
	FString Url = GetApiBaseUrl() + TEXT("/character/me");

	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = Http->CreateRequest();
	HttpRequest->SetVerb(TEXT("GET"));
	HttpRequest->SetURL(Url);
	HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	HttpRequest->SetHeader(TEXT("Authorization"), TEXT("Bearer ") + GetAuthToken());
	HttpRequest->SetHeader(TEXT("X-Server-Secret"), GetServerSecret());

	HttpRequest->OnProcessRequestComplete().BindUObject(
		this,
		&UEchoesPersistenceSubsystem::OnCharacterStateReceived,
		false /* bRefreshInventory */);

	if (!HttpRequest->ProcessRequest())
	{
		SyncState = EPersistenceSyncState::Error;
		UE_LOG(LogEchoesPersistence, Error, TEXT("[WALLET SYNC FAIL] Failed to send wallet sync request"));
		OnSyncFailed.Broadcast(TEXT("Failed to send wallet sync request"));
	}
}

// ==================== State Accessors ====================

float UEchoesPersistenceSubsystem::GetTimeSinceLastSync() const
{
	if (!CachedState.bIsValid)
	{
		return -1.0f;
	}

	const FTimespan Elapsed = FDateTime::UtcNow() - CachedState.LastSyncTime;
	return static_cast<float>(Elapsed.GetTotalSeconds());
}

bool UEchoesPersistenceSubsystem::IsStateValid(float MaxAgeSeconds) const
{
	if (!CachedState.bIsValid)
	{
		return false;
	}

	const float Age = GetTimeSinceLastSync();
	return Age >= 0.0f && Age < MaxAgeSeconds;
}

// ==================== HTTP Response Handlers ====================

void UEchoesPersistenceSubsystem::OnCharacterStateReceived(
	FHttpRequestPtr Request,
	FHttpResponsePtr Response,
	bool bWasSuccessful,
	bool bRefreshInventory)
{
	if (!bWasSuccessful || !Response.IsValid())
	{
		SyncState = EPersistenceSyncState::Error;
		UE_LOG(LogEchoesPersistence, Error, TEXT("[SYNC FAIL] State sync request failed (network error)"));
		OnSyncFailed.Broadcast(TEXT("Network error during state sync"));
		return;
	}

	const int32 ResponseCode = Response->GetResponseCode();
	const FString ResponseBody = Response->GetContentAsString();

	if (ResponseCode == 200)
	{
		// Parse CharacterDataDto (PascalCase from ASP.NET backend)
		TSharedPtr<FJsonObject> JsonObject;
		TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(ResponseBody);

		if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
		{
			const int64 OldBalance = CachedState.WalletBalance;

			// Update cached state
			FGuid::Parse(JsonObject->GetStringField(TEXT("CharacterId")), CachedState.CharacterId);
			CachedState.WalletBalance = static_cast<int64>(JsonObject->GetNumberField(TEXT("WalletBalance")));
			CachedState.LastSyncTime = FDateTime::UtcNow();
			CachedState.bIsValid = true;

			if (JsonObject->HasField(TEXT("IsDocked")))
			{
				CachedState.IsDocked = JsonObject->GetBoolField(TEXT("IsDocked"));
			}

			SyncState = EPersistenceSyncState::Idle;

			UE_LOG(LogEchoesPersistence, Log,
				TEXT("[SYNC SUCCESS] CharacterId=%s, Wallet=%lld ISK, IsDocked=%s"),
				*CachedState.CharacterId.ToString(),
				CachedState.WalletBalance,
				CachedState.IsDocked ? TEXT("true") : TEXT("false"));

			// Broadcast state synced
			OnStateSynced.Broadcast(CachedState);

			// Notify if wallet balance changed
			if (CachedState.bIsValid && OldBalance != CachedState.WalletBalance)
			{
				UE_LOG(LogEchoesPersistence, Log,
					TEXT("[WALLET CHANGE] %lld ISK -> %lld ISK (delta: %+lld ISK)"),
					OldBalance, CachedState.WalletBalance,
					CachedState.WalletBalance - OldBalance);
				OnWalletBalanceChanged.Broadcast(OldBalance, CachedState.WalletBalance);
			}

			// Trigger inventory refresh if requested (full sync mode)
			if (bRefreshInventory)
			{
				if (UGameInstance* GI = GetGameInstance())
				{
					if (UEchoesInventorySubsystem* InvSub = GI->GetSubsystem<UEchoesInventorySubsystem>())
					{
						UE_LOG(LogEchoesPersistence, Log, TEXT("[SYNC] Triggering inventory cache clear for refresh"));
						InvSub->Inventory_ClearCache();
					}
				}
			}
		}
		else
		{
			SyncState = EPersistenceSyncState::Error;
			UE_LOG(LogEchoesPersistence, Error, TEXT("[SYNC FAIL] Failed to parse character state JSON"));
			OnSyncFailed.Broadcast(TEXT("Failed to parse character state"));
		}
	}
	else
	{
		SyncState = EPersistenceSyncState::Error;

		FString ErrorMsg = FString::Printf(TEXT("State sync failed: %d"), ResponseCode);
		TSharedPtr<FJsonObject> JsonObject;
		TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(ResponseBody);
		if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
		{
			if (JsonObject->HasField(TEXT("error")))
			{
				ErrorMsg = JsonObject->GetStringField(TEXT("error"));
			}
		}

		UE_LOG(LogEchoesPersistence, Error, TEXT("[SYNC FAIL] Code=%d - %s"), ResponseCode, *ErrorMsg);
		OnSyncFailed.Broadcast(ErrorMsg);
	}
}

// ==================== Helper Functions ====================

FString UEchoesPersistenceSubsystem::GetAuthToken() const
{
	if (UGameInstance* GI = GetGameInstance())
	{
		if (UEchoesAuthSubsystem* AuthSub = GI->GetSubsystem<UEchoesAuthSubsystem>())
		{
			return AuthSub->Auth_GetToken();
		}
	}
	return FString();
}

FString UEchoesPersistenceSubsystem::GetApiBaseUrl() const
{
	FString ApiBaseUrl;

	if (GConfig->GetString(
		TEXT("/Script/Echoes.EchoesPersistenceSubsystem"),
		TEXT("ApiBaseUrl"),
		ApiBaseUrl,
		GGameIni))
	{
		return ApiBaseUrl;
	}

	// Default to localhost
	return TEXT("http://localhost:5116/api");
}

FString UEchoesPersistenceSubsystem::GetServerSecret() const
{
	FString ServerSecret;

	if (GConfig->GetString(
		TEXT("/Script/Echoes.EchoesPersistenceSubsystem"),
		TEXT("ServerSecret"),
		ServerSecret,
		GGameIni))
	{
		return ServerSecret;
	}

	// Default secret (should be changed in production)
	return TEXT("UE5-Server-Secret-Change-Me-In-Production");
}

void UEchoesPersistenceSubsystem::BindToMarketSubsystem()
{
	if (UGameInstance* GI = GetGameInstance())
	{
		if (UEchoesMarketSubsystem* MarketSub = GI->GetSubsystem<UEchoesMarketSubsystem>())
		{
			MarketSub->OnInventorySyncRequired.AddDynamic(this, &UEchoesPersistenceSubsystem::HandleMarketInventorySync);
			UE_LOG(LogEchoesPersistence, Log, TEXT("Bound to MarketSubsystem.OnInventorySyncRequired"));
		}
	}
}

void UEchoesPersistenceSubsystem::HandleMarketInventorySync(const FGuid& CharacterId)
{
	UE_LOG(LogEchoesPersistence, Log, TEXT("[MARKET SYNC] Received sync request for CharacterId=%s"),
		*CharacterId.ToString());
	ServerOnly_ForceSaveStateForCharacter(CharacterId);
}

bool UEchoesPersistenceSubsystem::ServerOnly_QueueStateSave(const FGuid& CharacterId, const FCommon_StateData& StateData)
{
	// Basic validation
	if (!CharacterId.IsValid())
	{
		UE_LOG(LogEchoesPersistence, Warning, TEXT("QueueStateSave: Invalid CharacterId"));
		return false;
	}

	// In this simplified stub we just log and return true to indicate queued
	UE_LOG(LogEchoesPersistence, Verbose, TEXT("QueueStateSave: Queued save for Character %s"), *CharacterId.ToString());
	// TODO: Push into real queue implementation
	return true;
}

void UEchoesPersistenceSubsystem::ServerOnly_SaveStateImmediate(const FGuid& CharacterId, const FCommon_StateData& StateData)
{
	if (!CharacterId.IsValid())
	{
		UE_LOG(LogEchoesPersistence, Warning, TEXT("SaveStateImmediate: Invalid CharacterId"));
		return;
	}

	UE_LOG(LogEchoesPersistence, Log, TEXT("SaveStateImmediate: Immediate save requested for Character %s"), *CharacterId.ToString());
	// TODO: Implement immediate HTTP save logic - for now, perform a queued save as fallback
	ServerOnly_QueueStateSave(CharacterId, StateData);
}
