// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesMarketToastWidget.h"
#include "Components/TextBlock.h"
#include "Components/Border.h"
#include "TimerManager.h"

void UEchoesMarketToastWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// Set default background
	if (ToastBackground)
	{
		ToastBackground->SetBrushColor(SuccessColor);
	}
}

void UEchoesMarketToastWidget::ShowTradeConfirmation(const FMarketTradeResult& TradeResult)
{
	if (MessageText)
	{
		// Format: "Bought 10 x Tritanium for 1,250.00 ISK"
		FString ItemDisplay = TradeResult.ItemName.IsEmpty()
			? FString::Printf(TEXT("item #%d"), TradeResult.ItemId)
			: TradeResult.ItemName;

		FString ToastMsg = FString::Printf(
			TEXT("Bought %d x %s for %.2f ISK"),
			TradeResult.QuantityTraded,
			*ItemDisplay,
			TradeResult.TotalPrice);

		MessageText->SetText(FText::FromString(ToastMsg));
	}

	if (ToastBackground)
	{
		ToastBackground->SetBrushColor(SuccessColor);
	}

	SetVisibility(ESlateVisibility::HitTestInvisible);

	// Auto-dismiss after duration
	if (UWorld* World = GetWorld())
	{
		World->GetTimerManager().SetTimer(
			DismissTimerHandle,
			this,
			&UEchoesMarketToastWidget::DismissToast,
			DisplayDuration,
			false);
	}
}

void UEchoesMarketToastWidget::ShowMessage(const FString& Message, bool bIsError)
{
	if (MessageText)
	{
		MessageText->SetText(FText::FromString(Message));
	}

	if (ToastBackground)
	{
		ToastBackground->SetBrushColor(bIsError ? ErrorColor : SuccessColor);
	}

	SetVisibility(ESlateVisibility::HitTestInvisible);

	// Auto-dismiss after duration
	if (UWorld* World = GetWorld())
	{
		World->GetTimerManager().SetTimer(
			DismissTimerHandle,
			this,
			&UEchoesMarketToastWidget::DismissToast,
			DisplayDuration,
			false);
	}
}

void UEchoesMarketToastWidget::DismissToast()
{
	// Trigger Blueprint fade-out animation (implement custom animation in BP)
	OnToastFadeOut();

	// Collapse immediately — for animated fade-out, override OnToastFadeOut in Blueprint
	SetVisibility(ESlateVisibility::Collapsed);
}
