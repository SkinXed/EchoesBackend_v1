// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EchoesMarketStructures.h"
#include "EchoesMarketToastWidget.generated.h"

class UTextBlock;
class UBorder;

/**
 * UEchoesMarketToastWidget
 * 
 * Toast notification widget for market trade confirmations
 * Shows "Bought [Quantity] x [ItemName] for [Price] ISK" popup
 * Auto-fades after a configurable duration
 * 
 * Usage:
 * - Create a widget blueprint based on this class
 * - Bind text blocks (MessageText) and background (ToastBackground)
 * - Call ShowTradeConfirmation() with a FMarketTradeResult
 * - Widget auto-removes after DisplayDuration seconds
 */
UCLASS()
class ECHOES_API UEchoesMarketToastWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	/**
	 * Show a trade confirmation toast
	 * @param TradeResult - Result of the executed trade
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Market|UI")
	void ShowTradeConfirmation(const FMarketTradeResult& TradeResult);

	/**
	 * Show a generic market message toast
	 * @param Message - Message text to display
	 * @param bIsError - True for error styling, false for success
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Market|UI")
	void ShowMessage(const FString& Message, bool bIsError = false);

	/** Duration the toast stays visible (seconds) */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Echoes|Market|UI|Style")
	float DisplayDuration = 5.0f;

protected:
	// ==================== Widget Bindings ====================

	/** Main message text */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Echoes|Market|UI")
	UTextBlock* MessageText;

	/** Background border for color styling */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Echoes|Market|UI")
	UBorder* ToastBackground;

	// ==================== Style Properties ====================

	/** Success background color */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Echoes|Market|UI|Style")
	FLinearColor SuccessColor = FLinearColor(0.05f, 0.3f, 0.05f, 0.9f);

	/** Error background color */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Echoes|Market|UI|Style")
	FLinearColor ErrorColor = FLinearColor(0.4f, 0.05f, 0.05f, 0.9f);

	/** Blueprint event for custom fade-out animation */
	UFUNCTION(BlueprintImplementableEvent, Category = "Echoes|Market|UI")
	void OnToastFadeOut();

private:
	/** Timer for auto-dismiss */
	FTimerHandle DismissTimerHandle;

	/** Auto-dismiss callback */
	void DismissToast();
};
