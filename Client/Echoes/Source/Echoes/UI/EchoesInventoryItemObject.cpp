// Copyright Epic Games, Inc. All Rights Reserved.

#include "UI/EchoesInventoryItemObject.h"

void UEchoesInventoryItemObject::InitializeWithData(const FEchoesInventoryItem& InItemData)
{
	ItemData = InItemData;
}

FString UEchoesInventoryItemObject::GetFormattedVolume() const
{
	return FString::Printf(TEXT("%.1f m³"), ItemData.Volume);
}

FString UEchoesInventoryItemObject::GetFormattedTotalVolume() const
{
	// Format with thousand separators
	FNumberFormattingOptions NumberFormat;
	NumberFormat.MinimumFractionalDigits = 1;
	NumberFormat.MaximumFractionalDigits = 1;
	
	FText FormattedNumber = FText::AsNumber(ItemData.TotalVolume, &NumberFormat);
	return FString::Printf(TEXT("%s m³"), *FormattedNumber.ToString());
}
