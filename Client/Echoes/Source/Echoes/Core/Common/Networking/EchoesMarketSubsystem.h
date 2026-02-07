// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Http.h"
#include "EchoesMarketStructures.h"
#include "EchoesMarketSubsystem.generated.h"

// ==================== Delegates ====================

/** Fired when market order data is received from the backend */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMarketDataReceived, const TArray<FMarketOrderDto>&, Orders);

/** Fired when a market API request fails */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMarketRequestFailed, const FString&, ErrorMessage);

/** Fired when an order is successfully created */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMarketOrderCreated, const FGuid&, OrderId);

/** Fired when a trade is successfully executed */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMarketTradeExecuted, const FGuid&, OrderId, int32, QuantityTraded);

/** Fired when an order is successfully cancelled */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMarketOrderCancelled, const FGuid&, OrderId, double, EscrowRefunded);

/**
 * UEchoesMarketSubsystem
 * 
 * Market networking subsystem for Echoes MMO (EVE-style market)
 * Communicates with ASP.NET Core MarketController
 * 
 * Architecture:
 * - GameInstanceSubsystem: Persists across level transitions
 * - ServerOnly_ prefix: Methods intended for UE5 dedicated server
 * - Reads ApiBaseUrl and X-Server-Secret from config (DefaultGame.ini)
 * - Caches market data to avoid excessive API requests
 */
UCLASS()
class ECHOES_API UEchoesMarketSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	// Subsystem lifecycle
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// ==================== Server-Only Market Functions ====================

	/**
	 * Fetch market orders for a region/item (order book)
	 * Sends HTTP GET to /api/market/region/{regionId}/{itemId}
	 * Results broadcast via OnMarketDataReceived delegate
	 * 
	 * @param Filter - Market filter with RegionId, ItemId, and display options
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Market")
	void ServerOnly_FetchMarketOrders(const FMarketFilter& Filter);

	/**
	 * Execute a trade on an existing market order
	 * Sends HTTP POST to /api/market/execute
	 * 
	 * @param OrderId - ID of the order to trade against
	 * @param Quantity - Number of items to buy/sell
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Market")
	void ServerOnly_ExecuteTrade(const FGuid& OrderId, int32 Quantity);

	/**
	 * Create a new market order (buy or sell)
	 * Sends HTTP POST to /api/market/orders
	 * 
	 * @param NewOrder - Order details (CharacterId, ItemId, IsBuyOrder, Price, Quantity, StationId)
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Market")
	void ServerOnly_CreateOrder(const FMarketOrderDto& NewOrder);

	/**
	 * Cancel an active market order
	 * Sends HTTP DELETE to /api/market/orders/{orderId}?characterId={characterId}
	 * Refunds remaining escrow for buy orders
	 * 
	 * @param OrderId - ID of the order to cancel
	 * @param CharacterId - ID of the character who owns the order
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Market")
	void ServerOnly_CancelOrder(const FGuid& OrderId, const FGuid& CharacterId);

	// ==================== Cached Data Access ====================

	/**
	 * Get cached market orders (avoids re-fetching on each UI open)
	 * @return Last fetched array of market orders
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Market")
	TArray<FMarketOrderDto> GetCachedMarketOrders() const { return CachedOrders; }

	/**
	 * Check if cached data is still valid
	 * @return True if cache exists and has not expired
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Market")
	bool IsCacheValid() const;

	// ==================== Delegates ====================

	/** Fired when market order data is received */
	UPROPERTY(BlueprintAssignable, Category = "Echoes|Market")
	FOnMarketDataReceived OnMarketDataReceived;

	/** Fired when a market API request fails */
	UPROPERTY(BlueprintAssignable, Category = "Echoes|Market")
	FOnMarketRequestFailed OnMarketRequestFailed;

	/** Fired when an order is created successfully */
	UPROPERTY(BlueprintAssignable, Category = "Echoes|Market")
	FOnMarketOrderCreated OnMarketOrderCreated;

	/** Fired when a trade is executed successfully */
	UPROPERTY(BlueprintAssignable, Category = "Echoes|Market")
	FOnMarketTradeExecuted OnMarketTradeExecuted;

	/** Fired when an order is cancelled successfully */
	UPROPERTY(BlueprintAssignable, Category = "Echoes|Market")
	FOnMarketOrderCancelled OnMarketOrderCancelled;

protected:
	// ==================== HTTP Response Handlers ====================

	void OnFetchOrdersResponseReceived(
		FHttpRequestPtr Request,
		FHttpResponsePtr Response,
		bool bWasSuccessful,
		FMarketFilter Filter);

	void OnExecuteTradeResponseReceived(
		FHttpRequestPtr Request,
		FHttpResponsePtr Response,
		bool bWasSuccessful);

	void OnCreateOrderResponseReceived(
		FHttpRequestPtr Request,
		FHttpResponsePtr Response,
		bool bWasSuccessful);

	void OnCancelOrderResponseReceived(
		FHttpRequestPtr Request,
		FHttpResponsePtr Response,
		bool bWasSuccessful);

	// ==================== Helper Functions ====================

	/** Parse a single market order from JSON object */
	bool ParseMarketOrder(const TSharedPtr<FJsonObject>& JsonObject, FMarketOrderDto& OutOrder);

	/** Get API base URL from configuration */
	FString GetApiBaseUrl() const;

	/** Get server secret from configuration */
	FString GetServerSecret() const;

private:
	/** HTTP module reference */
	FHttpModule* Http = nullptr;

	/** Cached market orders to reduce API calls */
	UPROPERTY()
	TArray<FMarketOrderDto> CachedOrders;

	/** Timestamp of last cache update */
	FDateTime CacheTimestamp;

	/** Cache validity duration in seconds */
	static constexpr float CacheDurationSeconds = 30.0f;
};
