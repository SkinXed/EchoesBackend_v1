// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EchoesMarketStructures.h"
#include "EchoesMarketOrderObject.generated.h"

/**
 * UEchoesMarketOrderObject
 * 
 * Data wrapper for FMarketOrderDto to be used with UListView
 * Wraps the market order struct so it can be used with UMG ListView (Entry Widget pooling)
 * Allows displaying thousands of orders without FPS drops
 * 
 * Usage:
 * - Create instances for each order in the order book
 * - Add to ListView as items
 * - OrderEntryWidget retrieves data via getter methods
 */
UCLASS(BlueprintType)
class ECHOES_API UEchoesMarketOrderObject : public UObject
{
	GENERATED_BODY()

public:
	/**
	 * Initialize the object with market order data
	 * @param InOrderData - The market order data to wrap
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Market|UI")
	void InitializeWithData(const FMarketOrderDto& InOrderData);

	/**
	 * Get the wrapped market order data
	 * @return The wrapped market order
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Market|UI")
	FMarketOrderDto GetOrderData() const { return OrderData; }

	/**
	 * Get the order ID
	 * @return Order GUID
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Market|UI")
	FGuid GetOrderId() const { return OrderData.OrderId; }

	/**
	 * Check if this is a buy order
	 * @return True if buy order, false if sell
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Market|UI")
	bool IsBuyOrder() const { return OrderData.IsBuyOrder; }

	/**
	 * Get formatted price string (e.g., "1,250.50 ISK")
	 * @return Formatted price string
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Market|UI")
	FString GetFormattedPrice() const;

	/**
	 * Get the remaining quantity
	 * @return Remaining quantity available
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Market|UI")
	int32 GetRemainingQuantity() const { return OrderData.RemainingQuantity; }

	/**
	 * Get the station name
	 * @return Station name where order is placed
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Market|UI")
	FString GetStationName() const { return OrderData.StationName; }

	/**
	 * Get formatted time since issued (e.g., "2h 15m ago")
	 * @return Formatted time string
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Market|UI")
	FString GetFormattedIssuedTime() const;

	/**
	 * Get the item ID
	 * @return Item type ID
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Market|UI")
	int32 GetItemId() const { return OrderData.ItemId; }

	/**
	 * Get the original price value
	 * @return Price as double
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Market|UI")
	double GetPrice() const { return OrderData.Price; }

	// ==================== Sorting Helpers ====================

	/**
	 * Compare by price (for TArray::Sort)
	 * @param Other - Other order to compare
	 * @return True if this price is less than other
	 */
	bool ComparePriceAscending(const UEchoesMarketOrderObject& Other) const
	{
		return OrderData.Price < Other.OrderData.Price;
	}

	/**
	 * Compare by quantity (for TArray::Sort)
	 * @param Other - Other order to compare
	 * @return True if this quantity is less than other
	 */
	bool CompareQuantityAscending(const UEchoesMarketOrderObject& Other) const
	{
		return OrderData.RemainingQuantity < Other.OrderData.RemainingQuantity;
	}

protected:
	/** The wrapped market order data */
	UPROPERTY()
	FMarketOrderDto OrderData;
};
