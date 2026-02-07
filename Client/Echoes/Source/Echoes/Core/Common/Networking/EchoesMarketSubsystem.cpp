// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesMarketSubsystem.h"
#include "HttpModule.h"
#include "Interfaces/IHttpResponse.h"
#include "Json.h"
#include "JsonUtilities.h"
#include "Misc/ConfigCacheIni.h"
#include "TimerManager.h"
#include "Engine/World.h"

DEFINE_LOG_CATEGORY(LogEchoesMarket);

void UEchoesMarketSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	Http = &FHttpModule::Get();
	TransactionState = EMarketTransactionState::Idle;

	UE_LOG(LogEchoesMarket, Log, TEXT("EchoesMarketSubsystem initialized"));
}

void UEchoesMarketSubsystem::Deinitialize()
{
	Super::Deinitialize();

	CachedOrders.Empty();
	TransactionState = EMarketTransactionState::Idle;

	UE_LOG(LogEchoesMarket, Log, TEXT("EchoesMarketSubsystem deinitialized"));
}

// ==================== Server-Only Market Functions ====================

void UEchoesMarketSubsystem::ServerOnly_FetchMarketOrders(const FMarketFilter& Filter)
{
	if (!Http)
	{
		UE_LOG(LogEchoesMarket, Error, TEXT("HTTP module not available"));
		OnMarketRequestFailed.Broadcast(TEXT("HTTP module not available"));
		return;
	}

	if (!Filter.RegionId.IsValid() || Filter.ItemId <= 0)
	{
		UE_LOG(LogEchoesMarket, Error, TEXT("Invalid filter - RegionId or ItemId is empty"));
		OnMarketRequestFailed.Broadcast(TEXT("Invalid filter parameters"));
		return;
	}

	// Build URL: GET /api/market/region/{regionId}/{itemId}
	FString Url = GetApiBaseUrl() + FString::Printf(
		TEXT("/market/region/%s/%d"),
		*Filter.RegionId.ToString(),
		Filter.ItemId);

	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = Http->CreateRequest();
	HttpRequest->SetVerb(TEXT("GET"));
	HttpRequest->SetURL(Url);
	HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	HttpRequest->SetHeader(TEXT("X-Server-Secret"), GetServerSecret());

	HttpRequest->OnProcessRequestComplete().BindUObject(
		this,
		&UEchoesMarketSubsystem::OnFetchOrdersResponseReceived,
		Filter);

	if (!HttpRequest->ProcessRequest())
	{
		UE_LOG(LogEchoesMarket, Error, TEXT("Failed to send fetch orders request"));
		OnMarketRequestFailed.Broadcast(TEXT("Failed to send request"));
	}
	else
	{
		UE_LOG(LogEchoesMarket, Log, TEXT("Fetch orders request sent to: %s"), *Url);
	}
}

void UEchoesMarketSubsystem::ServerOnly_ExecuteTrade(const FGuid& CharacterId, const FGuid& OrderId, int32 Quantity, const FGuid& CurrentStationId)
{
	if (!Http)
	{
		UE_LOG(LogEchoesMarket, Error, TEXT("HTTP module not available"));
		OnMarketRequestFailed.Broadcast(TEXT("HTTP module not available"));
		return;
	}

	if (!OrderId.IsValid() || Quantity <= 0 || !CharacterId.IsValid())
	{
		UE_LOG(LogEchoesMarket, Error, TEXT("Invalid trade parameters: OrderId=%s, CharacterId=%s, Quantity=%d"),
			*OrderId.ToString(), *CharacterId.ToString(), Quantity);
		OnMarketRequestFailed.Broadcast(TEXT("Invalid trade parameters"));
		return;
	}

	// Prevent duplicate trade requests
	if (TransactionState == EMarketTransactionState::InFlight)
	{
		UE_LOG(LogEchoesMarket, Warning, TEXT("Trade request rejected - another trade is in flight"));
		OnMarketRequestFailed.Broadcast(TEXT("A trade is already in progress. Please wait."));
		return;
	}

	if (TransactionState == EMarketTransactionState::UnknownState)
	{
		UE_LOG(LogEchoesMarket, Warning, TEXT("Trade request rejected - previous trade in unknown state. Sync wallet first."));
		OnMarketRequestFailed.Broadcast(TEXT("Previous trade status unknown. Please sync your wallet before retrying."));
		return;
	}

	// Mark transaction as in-flight
	TransactionState = EMarketTransactionState::InFlight;

	UE_LOG(LogEchoesMarket, Log, TEXT("[TRADE BEGIN] CharacterId=%s, OrderId=%s, Quantity=%d, StationId=%s"),
		*CharacterId.ToString(), *OrderId.ToString(), Quantity, *CurrentStationId.ToString());

	// Build JSON payload (mirrors C# ExecuteTradeRequest, PascalCase)
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	JsonObject->SetStringField(TEXT("CharacterId"), CharacterId.ToString());
	JsonObject->SetStringField(TEXT("OrderId"), OrderId.ToString());
	JsonObject->SetNumberField(TEXT("Quantity"), Quantity);
	JsonObject->SetStringField(TEXT("CurrentStationId"), CurrentStationId.ToString());

	FString JsonString;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&JsonString);
	FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);

	// POST /api/market/execute
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = Http->CreateRequest();
	HttpRequest->SetVerb(TEXT("POST"));
	HttpRequest->SetURL(GetApiBaseUrl() + TEXT("/market/execute"));
	HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	HttpRequest->SetHeader(TEXT("X-Server-Secret"), GetServerSecret());
	HttpRequest->SetContentAsString(JsonString);

	HttpRequest->OnProcessRequestComplete().BindUObject(
		this,
		&UEchoesMarketSubsystem::OnExecuteTradeResponseReceived,
		CharacterId);

	if (!HttpRequest->ProcessRequest())
	{
		TransactionState = EMarketTransactionState::Idle;
		UE_LOG(LogEchoesMarket, Error, TEXT("[TRADE FAIL] Failed to send execute trade HTTP request"));
		OnMarketRequestFailed.Broadcast(TEXT("Failed to send request"));
	}
	else
	{
		UE_LOG(LogEchoesMarket, Log, TEXT("[TRADE SENT] Awaiting API response for OrderId=%s"),
			*OrderId.ToString());

		// Start timeout timer
		if (UWorld* World = GetGameInstance()->GetWorld())
		{
			World->GetTimerManager().SetTimer(
				TradeTimeoutTimerHandle,
				this,
				&UEchoesMarketSubsystem::OnTradeTimeout,
				TradeTimeoutSeconds,
				false);
		}
	}
}

void UEchoesMarketSubsystem::ServerOnly_CreateOrder(const FMarketOrderDto& NewOrder)
{
	if (!Http)
	{
		UE_LOG(LogEchoesMarket, Error, TEXT("HTTP module not available"));
		OnMarketRequestFailed.Broadcast(TEXT("HTTP module not available"));
		return;
	}

	UE_LOG(LogEchoesMarket, Log, TEXT("[ORDER CREATE] %s %dx item #%d @ %.2f ISK by CharacterId=%s"),
		NewOrder.IsBuyOrder ? TEXT("BUY") : TEXT("SELL"),
		NewOrder.Quantity, NewOrder.ItemId, NewOrder.Price,
		*NewOrder.CharacterId.ToString());

	// Build JSON payload (mirrors C# CreateOrderRequest, PascalCase)
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	JsonObject->SetStringField(TEXT("CharacterId"), NewOrder.CharacterId.ToString());
	JsonObject->SetNumberField(TEXT("ItemId"), NewOrder.ItemId);
	JsonObject->SetBoolField(TEXT("IsBuyOrder"), NewOrder.IsBuyOrder);
	JsonObject->SetNumberField(TEXT("Price"), NewOrder.Price);
	JsonObject->SetNumberField(TEXT("Quantity"), NewOrder.Quantity);
	JsonObject->SetStringField(TEXT("StationId"), NewOrder.StationId.ToString());
	JsonObject->SetNumberField(TEXT("Duration"), NewOrder.Duration);

	FString JsonString;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&JsonString);
	FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);

	// POST /api/market/orders
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = Http->CreateRequest();
	HttpRequest->SetVerb(TEXT("POST"));
	HttpRequest->SetURL(GetApiBaseUrl() + TEXT("/market/orders"));
	HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	HttpRequest->SetHeader(TEXT("X-Server-Secret"), GetServerSecret());
	HttpRequest->SetContentAsString(JsonString);

	HttpRequest->OnProcessRequestComplete().BindUObject(
		this,
		&UEchoesMarketSubsystem::OnCreateOrderResponseReceived);

	if (!HttpRequest->ProcessRequest())
	{
		UE_LOG(LogEchoesMarket, Error, TEXT("[ORDER FAIL] Failed to send create order request"));
		OnMarketRequestFailed.Broadcast(TEXT("Failed to send request"));
	}
}

void UEchoesMarketSubsystem::ServerOnly_CancelOrder(const FGuid& OrderId, const FGuid& CharacterId)
{
	if (!Http)
	{
		UE_LOG(LogEchoesMarket, Error, TEXT("HTTP module not available"));
		OnMarketRequestFailed.Broadcast(TEXT("HTTP module not available"));
		return;
	}

	if (!OrderId.IsValid())
	{
		UE_LOG(LogEchoesMarket, Error, TEXT("Invalid OrderId for cancellation"));
		OnMarketRequestFailed.Broadcast(TEXT("Invalid order ID"));
		return;
	}

	UE_LOG(LogEchoesMarket, Log, TEXT("[ORDER CANCEL] OrderId=%s by CharacterId=%s"),
		*OrderId.ToString(), *CharacterId.ToString());

	// DELETE /api/market/orders/{orderId}?characterId={characterId}
	FString Url = GetApiBaseUrl() + FString::Printf(
		TEXT("/market/orders/%s?characterId=%s"),
		*OrderId.ToString(),
		*CharacterId.ToString());

	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = Http->CreateRequest();
	HttpRequest->SetVerb(TEXT("DELETE"));
	HttpRequest->SetURL(Url);
	HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	HttpRequest->SetHeader(TEXT("X-Server-Secret"), GetServerSecret());

	HttpRequest->OnProcessRequestComplete().BindUObject(
		this,
		&UEchoesMarketSubsystem::OnCancelOrderResponseReceived);

	if (!HttpRequest->ProcessRequest())
	{
		UE_LOG(LogEchoesMarket, Error, TEXT("[CANCEL FAIL] Failed to send cancel order request"));
		OnMarketRequestFailed.Broadcast(TEXT("Failed to send request"));
	}
}

// ==================== Transaction State ====================

void UEchoesMarketSubsystem::ResetTransactionState()
{
	UE_LOG(LogEchoesMarket, Log, TEXT("Transaction state reset from %d to Idle"),
		static_cast<int32>(TransactionState));
	TransactionState = EMarketTransactionState::Idle;
}

void UEchoesMarketSubsystem::OnTradeTimeout()
{
	if (TransactionState == EMarketTransactionState::InFlight)
	{
		UE_LOG(LogEchoesMarket, Warning, TEXT("[TRADE TIMEOUT] Trade request timed out after %.0fs. Marking as UnknownState."),
			TradeTimeoutSeconds);
		TransactionState = EMarketTransactionState::UnknownState;
		OnTradeError.Broadcast(0, TEXT("Trade request timed out. Please sync your wallet before retrying."));
		OnMarketRequestFailed.Broadcast(TEXT("Trade request timed out"));
	}
}

// ==================== Cache ====================

bool UEchoesMarketSubsystem::IsCacheValid() const
{
	if (CachedOrders.Num() == 0)
	{
		return false;
	}

	const FTimespan Elapsed = FDateTime::UtcNow() - CacheTimestamp;
	return Elapsed.GetTotalSeconds() < CacheDurationSeconds;
}

// ==================== HTTP Response Handlers ====================

void UEchoesMarketSubsystem::OnFetchOrdersResponseReceived(
	FHttpRequestPtr Request,
	FHttpResponsePtr Response,
	bool bWasSuccessful,
	FMarketFilter Filter)
{
	if (!bWasSuccessful || !Response.IsValid())
	{
		UE_LOG(LogEchoesMarket, Error, TEXT("Fetch orders request failed (network error)"));
		OnMarketRequestFailed.Broadcast(TEXT("Request failed"));
		return;
	}

	const int32 ResponseCode = Response->GetResponseCode();
	const FString ResponseBody = Response->GetContentAsString();

	UE_LOG(LogEchoesMarket, Log, TEXT("Fetch orders response: Code=%d"), ResponseCode);

	if (ResponseCode == 200)
	{
		// Parse the MarketOrderBookDto JSON (PascalCase from backend)
		TSharedPtr<FJsonObject> JsonObject;
		TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(ResponseBody);

		if (!FJsonSerializer::Deserialize(Reader, JsonObject) || !JsonObject.IsValid())
		{
			UE_LOG(LogEchoesMarket, Error, TEXT("Failed to parse order book JSON"));
			OnMarketRequestFailed.Broadcast(TEXT("Failed to parse response"));
			return;
		}

		TArray<FMarketOrderDto> AllOrders;

		// Parse BuyOrders array
		const TArray<TSharedPtr<FJsonValue>>* BuyOrdersArray;
		if (JsonObject->TryGetArrayField(TEXT("BuyOrders"), BuyOrdersArray))
		{
			for (const TSharedPtr<FJsonValue>& Value : *BuyOrdersArray)
			{
				const TSharedPtr<FJsonObject>& OrderObj = Value->AsObject();
				if (OrderObj.IsValid())
				{
					FMarketOrderDto Order;
					if (ParseMarketOrder(OrderObj, Order))
					{
						if (!Filter.bShowOnlySellOrders)
						{
							AllOrders.Add(Order);
						}
					}
				}
			}
		}

		// Parse SellOrders array
		const TArray<TSharedPtr<FJsonValue>>* SellOrdersArray;
		if (JsonObject->TryGetArrayField(TEXT("SellOrders"), SellOrdersArray))
		{
			for (const TSharedPtr<FJsonValue>& Value : *SellOrdersArray)
			{
				const TSharedPtr<FJsonObject>& OrderObj = Value->AsObject();
				if (OrderObj.IsValid())
				{
					FMarketOrderDto Order;
					if (ParseMarketOrder(OrderObj, Order))
					{
						if (!Filter.bShowOnlyBuyOrders)
						{
							AllOrders.Add(Order);
						}
					}
				}
			}
		}

		// Update cache
		CachedOrders = AllOrders;
		CacheTimestamp = FDateTime::UtcNow();

		UE_LOG(LogEchoesMarket, Log, TEXT("Received %d orders (Buy+Sell) for region=%s item=%d"),
			AllOrders.Num(), *Filter.RegionId.ToString(), Filter.ItemId);
		OnMarketDataReceived.Broadcast(AllOrders);
	}
	else
	{
		FString ErrorMsg = ExtractErrorMessage(ResponseBody, ResponseCode, TEXT("Fetch orders failed"));
		UE_LOG(LogEchoesMarket, Error, TEXT("Fetch orders failed: Code=%d - %s"), ResponseCode, *ErrorMsg);
		OnMarketRequestFailed.Broadcast(ErrorMsg);
	}
}

void UEchoesMarketSubsystem::OnExecuteTradeResponseReceived(
	FHttpRequestPtr Request,
	FHttpResponsePtr Response,
	bool bWasSuccessful,
	FGuid CharacterId)
{
	// Clear timeout timer
	if (UGameInstance* GI = GetGameInstance())
	{
		if (UWorld* World = GI->GetWorld())
		{
			World->GetTimerManager().ClearTimer(TradeTimeoutTimerHandle);
		}
	}

	if (!bWasSuccessful || !Response.IsValid())
	{
		UE_LOG(LogEchoesMarket, Error, TEXT("[TRADE FAIL] Execute trade request failed (network error). CharacterId=%s"),
			*CharacterId.ToString());
		TransactionState = EMarketTransactionState::UnknownState;
		OnTradeError.Broadcast(0, TEXT("Network error during trade. Status unknown."));
		OnMarketRequestFailed.Broadcast(TEXT("Trade request failed - network error"));
		return;
	}

	const int32 ResponseCode = Response->GetResponseCode();
	const FString ResponseBody = Response->GetContentAsString();

	UE_LOG(LogEchoesMarket, Log, TEXT("[TRADE RESPONSE] Code=%d, CharacterId=%s"), ResponseCode, *CharacterId.ToString());

	if (ResponseCode == 200)
	{
		// SUCCESS: Parse ExecuteTradeResultDto (PascalCase)
		TransactionState = EMarketTransactionState::Idle;

		TSharedPtr<FJsonObject> JsonObject;
		TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(ResponseBody);

		if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
		{
			FMarketTradeResult TradeResult;
			FGuid::Parse(JsonObject->GetStringField(TEXT("OrderId")), TradeResult.OrderId);
			TradeResult.QuantityTraded = JsonObject->GetIntegerField(TEXT("QuantityTraded"));
			TradeResult.TotalPrice = JsonObject->GetNumberField(TEXT("TotalPrice"));
			TradeResult.TransactionTax = JsonObject->GetNumberField(TEXT("TransactionTax"));

			if (JsonObject->HasField(TEXT("Message")))
			{
				TradeResult.Message = JsonObject->GetStringField(TEXT("Message"));
			}

			UE_LOG(LogEchoesMarket, Log,
				TEXT("[TRADE SUCCESS] OrderId=%s, Qty=%d, Total=%.2f ISK, Tax=%.2f ISK, CharacterId=%s"),
				*TradeResult.OrderId.ToString(), TradeResult.QuantityTraded,
				TradeResult.TotalPrice, TradeResult.TransactionTax,
				*CharacterId.ToString());

			// Broadcast all trade events
			OnMarketTradeExecuted.Broadcast(TradeResult.OrderId, TradeResult.QuantityTraded);
			OnTradeConfirmed.Broadcast(TradeResult);

			// Signal that inventory and wallet need to be resynced
			UE_LOG(LogEchoesMarket, Log, TEXT("[SYNC] Requesting inventory/wallet sync for CharacterId=%s"),
				*CharacterId.ToString());
			OnInventorySyncRequired.Broadcast(CharacterId);
		}
		else
		{
			UE_LOG(LogEchoesMarket, Error, TEXT("[TRADE FAIL] Failed to parse trade result JSON"));
			OnMarketRequestFailed.Broadcast(TEXT("Failed to parse trade response"));
		}
	}
	else
	{
		// ERROR: Trade was rejected by backend
		TransactionState = EMarketTransactionState::Idle;

		FString ErrorMsg = ExtractErrorMessage(ResponseBody, ResponseCode, TEXT("Trade failed"));

		UE_LOG(LogEchoesMarket, Warning, TEXT("[TRADE REJECTED] Code=%d, Error=%s, CharacterId=%s"),
			ResponseCode, *ErrorMsg, *CharacterId.ToString());

		OnTradeError.Broadcast(ResponseCode, ErrorMsg);
		OnMarketRequestFailed.Broadcast(ErrorMsg);
	}
}

void UEchoesMarketSubsystem::OnCreateOrderResponseReceived(
	FHttpRequestPtr Request,
	FHttpResponsePtr Response,
	bool bWasSuccessful)
{
	if (!bWasSuccessful || !Response.IsValid())
	{
		UE_LOG(LogEchoesMarket, Error, TEXT("[ORDER FAIL] Create order request failed (network error)"));
		OnMarketRequestFailed.Broadcast(TEXT("Request failed"));
		return;
	}

	const int32 ResponseCode = Response->GetResponseCode();
	const FString ResponseBody = Response->GetContentAsString();

	if (ResponseCode == 200)
	{
		// Parse CreateOrderResultDto (PascalCase)
		TSharedPtr<FJsonObject> JsonObject;
		TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(ResponseBody);

		if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
		{
			FGuid OrderId;
			FGuid::Parse(JsonObject->GetStringField(TEXT("OrderId")), OrderId);
			double BrokerFee = JsonObject->GetNumberField(TEXT("BrokerFee"));
			double EscrowAmount = JsonObject->GetNumberField(TEXT("EscrowAmount"));

			UE_LOG(LogEchoesMarket, Log,
				TEXT("[ORDER CREATED] OrderId=%s, BrokerFee=%.2f ISK, Escrow=%.2f ISK"),
				*OrderId.ToString(), BrokerFee, EscrowAmount);

			OnMarketOrderCreated.Broadcast(OrderId);
		}
		else
		{
			UE_LOG(LogEchoesMarket, Error, TEXT("[ORDER FAIL] Failed to parse create order result JSON"));
			OnMarketRequestFailed.Broadcast(TEXT("Failed to parse order response"));
		}
	}
	else
	{
		FString ErrorMsg = ExtractErrorMessage(ResponseBody, ResponseCode, TEXT("Order creation failed"));
		UE_LOG(LogEchoesMarket, Error, TEXT("[ORDER REJECTED] Code=%d - %s"), ResponseCode, *ErrorMsg);
		OnMarketRequestFailed.Broadcast(ErrorMsg);
	}
}

void UEchoesMarketSubsystem::OnCancelOrderResponseReceived(
	FHttpRequestPtr Request,
	FHttpResponsePtr Response,
	bool bWasSuccessful)
{
	if (!bWasSuccessful || !Response.IsValid())
	{
		UE_LOG(LogEchoesMarket, Error, TEXT("[CANCEL FAIL] Cancel order request failed (network error)"));
		OnMarketRequestFailed.Broadcast(TEXT("Request failed"));
		return;
	}

	const int32 ResponseCode = Response->GetResponseCode();
	const FString ResponseBody = Response->GetContentAsString();

	if (ResponseCode == 200)
	{
		// Parse CancelOrderResultDto (PascalCase)
		TSharedPtr<FJsonObject> JsonObject;
		TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(ResponseBody);

		if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
		{
			FGuid OrderId;
			FGuid::Parse(JsonObject->GetStringField(TEXT("OrderId")), OrderId);
			double EscrowRefunded = JsonObject->GetNumberField(TEXT("EscrowRefunded"));

			UE_LOG(LogEchoesMarket, Log,
				TEXT("[ORDER CANCELLED] OrderId=%s, EscrowRefunded=%.2f ISK"),
				*OrderId.ToString(), EscrowRefunded);

			OnMarketOrderCancelled.Broadcast(OrderId, EscrowRefunded);
		}
		else
		{
			UE_LOG(LogEchoesMarket, Error, TEXT("[CANCEL FAIL] Failed to parse cancel order result JSON"));
			OnMarketRequestFailed.Broadcast(TEXT("Failed to parse cancel response"));
		}
	}
	else
	{
		FString ErrorMsg = ExtractErrorMessage(ResponseBody, ResponseCode, TEXT("Order cancellation failed"));
		UE_LOG(LogEchoesMarket, Error, TEXT("[CANCEL REJECTED] Code=%d - %s"), ResponseCode, *ErrorMsg);
		OnMarketRequestFailed.Broadcast(ErrorMsg);
	}
}

// ==================== Helper Functions ====================

bool UEchoesMarketSubsystem::ParseMarketOrder(const TSharedPtr<FJsonObject>& JsonObject, FMarketOrderDto& OutOrder)
{
	if (!JsonObject.IsValid())
	{
		return false;
	}

	// Parse fields using PascalCase (matches ASP.NET backend JSON serialization)
	FGuid::Parse(JsonObject->GetStringField(TEXT("OrderId")), OutOrder.OrderId);
	FGuid::Parse(JsonObject->GetStringField(TEXT("CharacterId")), OutOrder.CharacterId);
	OutOrder.ItemId = JsonObject->GetIntegerField(TEXT("ItemId"));
	OutOrder.IsBuyOrder = JsonObject->GetBoolField(TEXT("IsBuyOrder"));
	OutOrder.Price = JsonObject->GetNumberField(TEXT("Price"));
	OutOrder.Quantity = JsonObject->GetIntegerField(TEXT("Quantity"));
	OutOrder.RemainingQuantity = JsonObject->GetIntegerField(TEXT("RemainingQuantity"));
	FGuid::Parse(JsonObject->GetStringField(TEXT("StationId")), OutOrder.StationId);

	if (JsonObject->HasField(TEXT("StationName")))
	{
		OutOrder.StationName = JsonObject->GetStringField(TEXT("StationName"));
	}

	FGuid::Parse(JsonObject->GetStringField(TEXT("RegionId")), OutOrder.RegionId);
	OutOrder.Duration = JsonObject->GetIntegerField(TEXT("Duration"));

	if (JsonObject->HasField(TEXT("Status")))
	{
		OutOrder.Status = JsonObject->GetStringField(TEXT("Status"));
	}

	OutOrder.BrokerFee = JsonObject->GetNumberField(TEXT("BrokerFee"));

	if (JsonObject->HasField(TEXT("IssuedAt")) && !JsonObject->GetField<EJson::None>(TEXT("IssuedAt"))->IsNull())
	{
		FDateTime::Parse(JsonObject->GetStringField(TEXT("IssuedAt")), OutOrder.IssuedAt);
	}

	return true;
}

FString UEchoesMarketSubsystem::ExtractErrorMessage(const FString& ResponseBody, int32 ResponseCode, const FString& DefaultPrefix)
{
	FString ErrorMsg = FString::Printf(TEXT("%s: %d"), *DefaultPrefix, ResponseCode);

	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(ResponseBody);
	if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
	{
		if (JsonObject->HasField(TEXT("error")))
		{
			ErrorMsg = JsonObject->GetStringField(TEXT("error"));
		}
	}

	return ErrorMsg;
}

FString UEchoesMarketSubsystem::GetApiBaseUrl() const
{
	FString ApiBaseUrl;

	if (GConfig->GetString(
		TEXT("/Script/Echoes.EchoesMarketSubsystem"),
		TEXT("ApiBaseUrl"),
		ApiBaseUrl,
		GGameIni))
	{
		return ApiBaseUrl;
	}

	// Default to localhost
	return TEXT("http://localhost:5116/api");
}

FString UEchoesMarketSubsystem::GetServerSecret() const
{
	FString ServerSecret;

	if (GConfig->GetString(
		TEXT("/Script/Echoes.EchoesMarketSubsystem"),
		TEXT("ServerSecret"),
		ServerSecret,
		GGameIni))
	{
		return ServerSecret;
	}

	// Default secret (should be changed in production)
	return TEXT("UE5-Server-Secret-Change-Me-In-Production");
}
