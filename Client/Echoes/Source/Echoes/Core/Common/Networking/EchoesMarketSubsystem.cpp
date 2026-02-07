// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesMarketSubsystem.h"
#include "HttpModule.h"
#include "Interfaces/IHttpResponse.h"
#include "Json.h"
#include "JsonUtilities.h"
#include "Misc/ConfigCacheIni.h"

void UEchoesMarketSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	Http = &FHttpModule::Get();

	UE_LOG(LogTemp, Log, TEXT("EchoesMarketSubsystem initialized"));
}

void UEchoesMarketSubsystem::Deinitialize()
{
	Super::Deinitialize();

	CachedOrders.Empty();

	UE_LOG(LogTemp, Log, TEXT("EchoesMarketSubsystem deinitialized"));
}

// ==================== Server-Only Market Functions ====================

void UEchoesMarketSubsystem::ServerOnly_FetchMarketOrders(const FMarketFilter& Filter)
{
	if (!Http)
	{
		UE_LOG(LogTemp, Error, TEXT("Market: HTTP module not available"));
		OnMarketRequestFailed.Broadcast(TEXT("HTTP module not available"));
		return;
	}

	if (!Filter.RegionId.IsValid() || Filter.ItemId <= 0)
	{
		UE_LOG(LogTemp, Error, TEXT("Market: Invalid filter - RegionId or ItemId is empty"));
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
		UE_LOG(LogTemp, Error, TEXT("Market: Failed to send fetch orders request"));
		OnMarketRequestFailed.Broadcast(TEXT("Failed to send request"));
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Market: Fetch orders request sent to: %s"), *Url);
	}
}

void UEchoesMarketSubsystem::ServerOnly_ExecuteTrade(const FGuid& OrderId, int32 Quantity)
{
	if (!Http)
	{
		UE_LOG(LogTemp, Error, TEXT("Market: HTTP module not available"));
		OnMarketRequestFailed.Broadcast(TEXT("HTTP module not available"));
		return;
	}

	if (!OrderId.IsValid() || Quantity <= 0)
	{
		UE_LOG(LogTemp, Error, TEXT("Market: Invalid trade parameters"));
		OnMarketRequestFailed.Broadcast(TEXT("Invalid trade parameters"));
		return;
	}

	// Build JSON payload (mirrors C# ExecuteTradeRequest, PascalCase)
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	JsonObject->SetStringField(TEXT("OrderId"), OrderId.ToString());
	JsonObject->SetNumberField(TEXT("Quantity"), Quantity);

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
		&UEchoesMarketSubsystem::OnExecuteTradeResponseReceived);

	if (!HttpRequest->ProcessRequest())
	{
		UE_LOG(LogTemp, Error, TEXT("Market: Failed to send execute trade request"));
		OnMarketRequestFailed.Broadcast(TEXT("Failed to send request"));
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Market: Execute trade request sent for OrderId=%s, Quantity=%d"),
			*OrderId.ToString(), Quantity);
	}
}

void UEchoesMarketSubsystem::ServerOnly_CreateOrder(const FMarketOrderDto& NewOrder)
{
	if (!Http)
	{
		UE_LOG(LogTemp, Error, TEXT("Market: HTTP module not available"));
		OnMarketRequestFailed.Broadcast(TEXT("HTTP module not available"));
		return;
	}

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
		UE_LOG(LogTemp, Error, TEXT("Market: Failed to send create order request"));
		OnMarketRequestFailed.Broadcast(TEXT("Failed to send request"));
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Market: Create order request sent - %s %dx item #%d @ %.2f ISK"),
			NewOrder.IsBuyOrder ? TEXT("BUY") : TEXT("SELL"),
			NewOrder.Quantity, NewOrder.ItemId, NewOrder.Price);
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
		UE_LOG(LogTemp, Error, TEXT("Market: Fetch orders request failed"));
		OnMarketRequestFailed.Broadcast(TEXT("Request failed"));
		return;
	}

	const int32 ResponseCode = Response->GetResponseCode();
	const FString ResponseBody = Response->GetContentAsString();

	UE_LOG(LogTemp, Log, TEXT("Market: Fetch orders response: Code=%d"), ResponseCode);

	if (ResponseCode == 200)
	{
		// Parse the MarketOrderBookDto JSON (PascalCase from backend)
		TSharedPtr<FJsonObject> JsonObject;
		TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(ResponseBody);

		if (!FJsonSerializer::Deserialize(Reader, JsonObject) || !JsonObject.IsValid())
		{
			UE_LOG(LogTemp, Error, TEXT("Market: Failed to parse order book JSON"));
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

		UE_LOG(LogTemp, Log, TEXT("Market: Received %d orders (Buy+Sell)"), AllOrders.Num());
		OnMarketDataReceived.Broadcast(AllOrders);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Market: Fetch orders failed with code: %d - %s"), ResponseCode, *ResponseBody);
		OnMarketRequestFailed.Broadcast(FString::Printf(TEXT("Server error: %d"), ResponseCode));
	}
}

void UEchoesMarketSubsystem::OnExecuteTradeResponseReceived(
	FHttpRequestPtr Request,
	FHttpResponsePtr Response,
	bool bWasSuccessful)
{
	if (!bWasSuccessful || !Response.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Market: Execute trade request failed"));
		OnMarketRequestFailed.Broadcast(TEXT("Request failed"));
		return;
	}

	const int32 ResponseCode = Response->GetResponseCode();
	const FString ResponseBody = Response->GetContentAsString();

	if (ResponseCode == 200)
	{
		// Parse ExecuteTradeResultDto (PascalCase)
		TSharedPtr<FJsonObject> JsonObject;
		TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(ResponseBody);

		if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
		{
			FGuid OrderId;
			FGuid::Parse(JsonObject->GetStringField(TEXT("OrderId")), OrderId);
			int32 QuantityTraded = JsonObject->GetIntegerField(TEXT("QuantityTraded"));
			double TotalPrice = JsonObject->GetNumberField(TEXT("TotalPrice"));
			double TransactionTax = JsonObject->GetNumberField(TEXT("TransactionTax"));

			UE_LOG(LogTemp, Log, TEXT("Market: Trade executed! OrderId=%s, Qty=%d, Total=%.2f ISK, Tax=%.2f ISK"),
				*OrderId.ToString(), QuantityTraded, TotalPrice, TransactionTax);

			OnMarketTradeExecuted.Broadcast(OrderId, QuantityTraded);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Market: Failed to parse trade result JSON"));
			OnMarketRequestFailed.Broadcast(TEXT("Failed to parse trade response"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Market: Execute trade failed with code: %d - %s"), ResponseCode, *ResponseBody);

		// Try to extract error message
		FString ErrorMsg = FString::Printf(TEXT("Trade failed: %d"), ResponseCode);
		TSharedPtr<FJsonObject> JsonObject;
		TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(ResponseBody);
		if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
		{
			if (JsonObject->HasField(TEXT("error")))
			{
				ErrorMsg = JsonObject->GetStringField(TEXT("error"));
			}
		}

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
		UE_LOG(LogTemp, Error, TEXT("Market: Create order request failed"));
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

			UE_LOG(LogTemp, Log, TEXT("Market: Order created! OrderId=%s, BrokerFee=%.2f ISK, Escrow=%.2f ISK"),
				*OrderId.ToString(), BrokerFee, EscrowAmount);

			OnMarketOrderCreated.Broadcast(OrderId);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Market: Failed to parse create order result JSON"));
			OnMarketRequestFailed.Broadcast(TEXT("Failed to parse order response"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Market: Create order failed with code: %d - %s"), ResponseCode, *ResponseBody);

		// Try to extract error message
		FString ErrorMsg = FString::Printf(TEXT("Order creation failed: %d"), ResponseCode);
		TSharedPtr<FJsonObject> JsonObject;
		TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(ResponseBody);
		if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
		{
			if (JsonObject->HasField(TEXT("error")))
			{
				ErrorMsg = JsonObject->GetStringField(TEXT("error"));
			}
		}

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
