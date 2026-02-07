// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "EchoesMarketStructures.h"
#include "EchoesMarketOrderEntryWidget.generated.h"

class UTextBlock;
class UBorder;
class UEchoesMarketOrderObject;

/**
 * UEchoesMarketOrderEntryWidget
 * 
 * Entry widget for market order ListView items (EVE Online-style order book row)
 * Implements IUserObjectListEntry for efficient ListView pooling
 * Displays: Price, Quantity, Station, Time
 * Color-coded: Green for buy orders, Red for sell orders
 * Hover effects for detailed tax/fee information
 * 
 * Usage in UMG:
 * - Create a widget blueprint based on this class
 * - Add UTextBlock widgets with matching names (PriceText, QuantityText, etc.)
 * - Add UBorder for RowBackground (hover highlight)
 * - Set this blueprint as Entry Widget Class in ListView
 */
UCLASS()
class ECHOES_API UEchoesMarketOrderEntryWidget : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

public:
	// IUserObjectListEntry interface
	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;
	// End of IUserObjectListEntry interface

	// UUserWidget interface
	virtual void NativeConstruct() override;
	virtual void NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual void NativeOnMouseLeave(const FPointerEvent& InMouseEvent) override;
	// End of UUserWidget interface

	/**
	 * Set the order data to display
	 * Called automatically by ListView when item is set
	 * @param OrderObject - The market order object to display
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Market|UI")
	void SetOrderData(UEchoesMarketOrderObject* OrderObject);

protected:
	/**
	 * Update the visual display with order data
	 * Applies color coding based on buy/sell type
	 */
	virtual void UpdateDisplay(UEchoesMarketOrderObject* OrderObject);

	/**
	 * Get the color for order text based on type
	 * @param bIsBuyOrder - True for buy order, false for sell
	 * @return Green for buy, Red for sell
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Market|UI")
	static FSlateColor GetOrderTypeColor(bool bIsBuyOrder);

	// ==================== Widget Bindings ====================

	/** Text block for price display */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Echoes|Market|UI")
	UTextBlock* PriceText;

	/** Text block for remaining quantity */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Echoes|Market|UI")
	UTextBlock* QuantityText;

	/** Text block for station name */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Echoes|Market|UI")
	UTextBlock* StationText;

	/** Text block for time since issued */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Echoes|Market|UI")
	UTextBlock* TimeText;

	/** Background border for hover highlight effect */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Echoes|Market|UI")
	UBorder* RowBackground;

	// ==================== Hover Styling ====================

	/** Normal background color */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Echoes|Market|UI|Style")
	FLinearColor NormalBackgroundColor = FLinearColor(0.02f, 0.02f, 0.05f, 0.8f);

	/** Hovered background color */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Echoes|Market|UI|Style")
	FLinearColor HoveredBackgroundColor = FLinearColor(0.08f, 0.08f, 0.15f, 0.9f);

	/** Buy order text color (green) */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Echoes|Market|UI|Style")
	FLinearColor BuyOrderColor = FLinearColor(0.2f, 0.8f, 0.2f, 1.0f);

	/** Sell order text color (red) */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Echoes|Market|UI|Style")
	FLinearColor SellOrderColor = FLinearColor(0.9f, 0.2f, 0.2f, 1.0f);

	/** Blueprint event for showing tooltip with tax/fee details on hover */
	UFUNCTION(BlueprintImplementableEvent, Category = "Echoes|Market|UI")
	void OnOrderHovered(const FMarketOrderDto& OrderData);

	/** Blueprint event for hiding tooltip */
	UFUNCTION(BlueprintImplementableEvent, Category = "Echoes|Market|UI")
	void OnOrderUnhovered();

private:
	/** Current order object being displayed */
	UPROPERTY()
	UEchoesMarketOrderObject* CurrentOrderObject = nullptr;
};
