// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EchoesMarketStructures.generated.h"

/**
 * Market order DTO (mirrors C# MarketOrderDto from ASP.NET backend)
 * Used to display market orders in the UI order book
 */
USTRUCT(BlueprintType)
struct FMarketOrderDto
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Market")
	FGuid OrderId;

	UPROPERTY(BlueprintReadWrite, Category = "Market")
	FGuid CharacterId;

	UPROPERTY(BlueprintReadWrite, Category = "Market")
	int32 ItemId = 0;

	/** Item display name (resolved client-side from item type registry) */
	UPROPERTY(BlueprintReadWrite, Category = "Market")
	FString ItemName;

	UPROPERTY(BlueprintReadWrite, Category = "Market")
	bool IsBuyOrder = false;

	UPROPERTY(BlueprintReadWrite, Category = "Market")
	double Price = 0.0;

	UPROPERTY(BlueprintReadWrite, Category = "Market")
	int32 Quantity = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Market")
	int32 RemainingQuantity = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Market")
	FGuid StationId;

	UPROPERTY(BlueprintReadWrite, Category = "Market")
	FString StationName;

	UPROPERTY(BlueprintReadWrite, Category = "Market")
	FGuid RegionId;

	UPROPERTY(BlueprintReadWrite, Category = "Market")
	int32 Duration = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Market")
	FString Status;

	UPROPERTY(BlueprintReadWrite, Category = "Market")
	double BrokerFee = 0.0;

	UPROPERTY(BlueprintReadWrite, Category = "Market")
	FDateTime IssuedAt;
};

/**
 * Market filter structure for querying orders
 * Used by UEchoesMarketSubsystem to filter order book requests
 */
USTRUCT(BlueprintType)
struct FMarketFilter
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Market")
	FGuid RegionId;

	UPROPERTY(BlueprintReadWrite, Category = "Market")
	int32 ItemId = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Market")
	bool bShowOnlyBuyOrders = false;

	UPROPERTY(BlueprintReadWrite, Category = "Market")
	bool bShowOnlySellOrders = false;
};

/**
 * Result of a successful trade execution
 * Used for UI notifications (toast) and inventory sync
 */
USTRUCT(BlueprintType)
struct FMarketTradeResult
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Market")
	FGuid OrderId;

	UPROPERTY(BlueprintReadWrite, Category = "Market")
	FGuid TransactionId;

	UPROPERTY(BlueprintReadWrite, Category = "Market")
	int32 QuantityTraded = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Market")
	double TotalPrice = 0.0;

	UPROPERTY(BlueprintReadWrite, Category = "Market")
	double TransactionTax = 0.0;

	UPROPERTY(BlueprintReadWrite, Category = "Market")
	int32 ItemId = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Market")
	FString ItemName;

	UPROPERTY(BlueprintReadWrite, Category = "Market")
	FString Message;
};

/** Trade transaction state for timeout/reliability tracking */
UENUM(BlueprintType)
enum class EMarketTransactionState : uint8
{
	Idle,
	InFlight,
	UnknownState
};
