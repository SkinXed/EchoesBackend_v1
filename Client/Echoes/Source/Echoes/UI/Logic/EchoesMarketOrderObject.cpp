// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesMarketOrderObject.h"

void UEchoesMarketOrderObject::InitializeWithData(const FMarketOrderDto& InOrderData)
{
	OrderData = InOrderData;
}

FString UEchoesMarketOrderObject::GetFormattedPrice() const
{
	// Format with thousands separators and 2 decimal places
	// e.g., 1250.5 -> "1,250.50 ISK"
	FString PriceStr = FString::Printf(TEXT("%.2f"), OrderData.Price);

	// Insert thousands separators
	int32 DecimalPos = PriceStr.Find(TEXT("."));
	if (DecimalPos == INDEX_NONE)
	{
		DecimalPos = PriceStr.Len();
	}

	for (int32 i = DecimalPos - 3; i > 0; i -= 3)
	{
		PriceStr.InsertAt(i, TEXT(","));
	}

	return PriceStr + TEXT(" ISK");
}

FString UEchoesMarketOrderObject::GetFormattedIssuedTime() const
{
	const FTimespan Elapsed = FDateTime::UtcNow() - OrderData.IssuedAt;

	if (Elapsed.GetTotalDays() >= 1.0)
	{
		int32 Days = FMath::FloorToInt(Elapsed.GetTotalDays());
		return FString::Printf(TEXT("%dd ago"), Days);
	}
	else if (Elapsed.GetTotalHours() >= 1.0)
	{
		int32 Hours = FMath::FloorToInt(Elapsed.GetTotalHours());
		int32 Minutes = Elapsed.GetMinutes();
		return FString::Printf(TEXT("%dh %dm ago"), Hours, Minutes);
	}
	else
	{
		int32 Minutes = FMath::Max(1, FMath::FloorToInt(Elapsed.GetTotalMinutes()));
		return FString::Printf(TEXT("%dm ago"), Minutes);
	}
}
