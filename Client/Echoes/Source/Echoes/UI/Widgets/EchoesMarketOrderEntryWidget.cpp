// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesMarketOrderEntryWidget.h"
#include "EchoesMarketOrderObject.h"
#include "EchoesMarketStructures.h"
#include "Components/TextBlock.h"
#include "Components/Border.h"

void UEchoesMarketOrderEntryWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// Set default background
	if (RowBackground)
	{
		RowBackground->SetBrushColor(NormalBackgroundColor);
	}
}

void UEchoesMarketOrderEntryWidget::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	UEchoesMarketOrderObject* OrderObject = Cast<UEchoesMarketOrderObject>(ListItemObject);
	if (OrderObject)
	{
		SetOrderData(OrderObject);
	}
}

void UEchoesMarketOrderEntryWidget::NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseEnter(InGeometry, InMouseEvent);

	// Hover highlight
	if (RowBackground)
	{
		RowBackground->SetBrushColor(HoveredBackgroundColor);
	}

	// Trigger Blueprint event for tooltip display
	if (CurrentOrderObject)
	{
		OnOrderHovered(CurrentOrderObject->GetOrderData());
	}
}

void UEchoesMarketOrderEntryWidget::NativeOnMouseLeave(const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseLeave(InMouseEvent);

	// Remove hover highlight
	if (RowBackground)
	{
		RowBackground->SetBrushColor(NormalBackgroundColor);
	}

	OnOrderUnhovered();
}

void UEchoesMarketOrderEntryWidget::SetOrderData(UEchoesMarketOrderObject* OrderObject)
{
	CurrentOrderObject = OrderObject;

	if (OrderObject)
	{
		UpdateDisplay(OrderObject);
	}
}

void UEchoesMarketOrderEntryWidget::UpdateDisplay(UEchoesMarketOrderObject* OrderObject)
{
	if (!OrderObject)
		return;

	const FSlateColor TypeColor = OrderObject->IsBuyOrder()
		? FSlateColor(BuyOrderColor)
		: FSlateColor(SellOrderColor);

	// Price
	if (PriceText)
	{
		PriceText->SetText(FText::FromString(OrderObject->GetFormattedPrice()));
		PriceText->SetColorAndOpacity(TypeColor);
	}

	// Quantity
	if (QuantityText)
	{
		QuantityText->SetText(FText::AsNumber(OrderObject->GetRemainingQuantity()));
		QuantityText->SetColorAndOpacity(TypeColor);
	}

	// Station
	if (StationText)
	{
		FString Station = OrderObject->GetStationName();
		if (Station.IsEmpty())
		{
			Station = TEXT("Unknown Station");
		}
		StationText->SetText(FText::FromString(Station));
	}

	// Time
	if (TimeText)
	{
		TimeText->SetText(FText::FromString(OrderObject->GetFormattedIssuedTime()));
	}
}

FSlateColor UEchoesMarketOrderEntryWidget::GetOrderTypeColor(bool bIsBuyOrder)
{
	// Green for buy orders, red for sell orders (EVE Online convention)
	// Note: For instance-specific colors, use BuyOrderColor/SellOrderColor properties in UpdateDisplay
	return bIsBuyOrder
		? FSlateColor(FLinearColor(0.2f, 0.8f, 0.2f, 1.0f))
		: FSlateColor(FLinearColor(0.9f, 0.2f, 0.2f, 1.0f));
}
