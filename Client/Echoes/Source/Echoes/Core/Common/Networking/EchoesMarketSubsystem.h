// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Http.h"
#include "EchoesMarketStructures.h"
#include "EchoesMarketSubsystem.generated.h"

/** Custom log category for market trade auditing */
DECLARE_LOG_CATEGORY_EXTERN(LogEchoesMarket, Log, All);

// ==================== Delegates ====================

/** Fired when market order data is received from the backend */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMarketDataReceived, const TArray<FMarketOrderDto>&, Orders);

/** Fired when a market API request fails */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMarketRequestFailed, const FString&, ErrorMessage);

/** Fired when an order is successfully created */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMarketOrderCreated, const FGuid&, OrderId);

/** Fired when a trade is successfully executed (detailed result for UI/inventory sync) */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMarketTradeExecuted, const FGuid&, OrderId, int32, QuantityTraded);

/** Fired when a trade is confirmed with full result data (for toast notification and inventory sync) */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTradeConfirmed, const FMarketTradeResult&, TradeResult);

/** Fired when a trade fails with error details */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTradeError, int32, HttpStatusCode, const FString&, ErrorMessage);

/** Fired when an order is successfully cancelled */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMarketOrderCancelled, const FGuid&, OrderId, double, EscrowRefunded);

/** Fired when inventory/wallet sync is needed after a trade */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMarketInventorySyncRequired, const FGuid&, CharacterId);

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
 * - Tracks transaction state to prevent duplicate requests and handle timeouts
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
	 * Includes CharacterId and CurrentStationId for backend validation
	 * Prevents duplicate requests while a trade is in flight
	 * 
	 * @param CharacterId - Character performing the trade
	 * @param OrderId - ID of the order to trade against
	 * @param Quantity - Number of items to buy/sell
	 * @param CurrentStationId - Station where player is currently docked (for location validation)
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Market")
	void ServerOnly_ExecuteTrade(const FGuid& CharacterId, const FGuid& OrderId, int32 Quantity, const FGuid& CurrentStationId);

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

	// ==================== Transaction State ====================

	/**
	 * Get the current trade transaction state
	 * @return Current state (Idle, InFlight, UnknownState)
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Market")
	EMarketTransactionState GetTransactionState() const { return TransactionState; }

	/**
	 * Reset transaction state to Idle (use after confirming wallet sync in UnknownState)
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Market")
	void ResetTransactionState();

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

	/** Fired when a trade is confirmed with full result data */
	UPROPERTY(BlueprintAssignable, Category = "Echoes|Market")
	FOnTradeConfirmed OnTradeConfirmed;

	/** Fired when a trade fails with detailed error info */
	UPROPERTY(BlueprintAssignable, Category = "Echoes|Market")
	FOnTradeError OnTradeError;

	/** Fired when an order is cancelled successfully */
	UPROPERTY(BlueprintAssignable, Category = "Echoes|Market")
	FOnMarketOrderCancelled OnMarketOrderCancelled;

	/** Fired when inventory/wallet needs to be resynced after a trade */
	UPROPERTY(BlueprintAssignable, Category = "Echoes|Market")
	FOnMarketInventorySyncRequired OnInventorySyncRequired;

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
		bool bWasSuccessful,
		FGuid CharacterId);

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

	/** Extract error message from JSON response body */
	FString ExtractErrorMessage(const FString& ResponseBody, int32 ResponseCode, const FString& DefaultPrefix);

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

	/** HTTP request timeout for trade operations (seconds) */
	static constexpr float TradeTimeoutSeconds = 30.0f;

	/** Current trade transaction state */
	EMarketTransactionState TransactionState = EMarketTransactionState::Idle;

	/** Timer handle for trade timeout detection */
	FTimerHandle TradeTimeoutTimerHandle;

	/** Handle trade request timeout */
	void OnTradeTimeout();
};
