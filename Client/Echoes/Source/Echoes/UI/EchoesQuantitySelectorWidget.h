// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EchoesQuantitySelectorWidget.generated.h"

class UButton;
class UTextBlock;
class USlider;
class UEditableTextBox;

// Delegate for quantity selection
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnQuantitySelected, int64, SelectedQuantity);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnQuantitySelectionCancelled);

/**
 * UEchoesQuantitySelectorWidget
 * 
 * Modal widget for selecting quantity when splitting item stacks
 * Displays when Shift+Drag is used on stackable items
 * 
 * Features:
 * - Slider for quick selection
 * - Text input for precise amount
 * - Min: 1, Max: item quantity
 * - Confirm/Cancel buttons
 * 
 * Usage:
 * - Create when Shift held during drag start
 * - Set max quantity from item
 * - Wait for user confirmation or cancellation
 * - Use selected quantity in drag operation
 */
UCLASS()
class ECHOES_API UEchoesQuantitySelectorWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UEchoesQuantitySelectorWidget(const FObjectInitializer& ObjectInitializer);

	// UUserWidget interface
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	// End of UUserWidget interface

	/**
	 * Initialize the selector with max quantity
	 * @param InMaxQuantity - Maximum quantity available
	 * @param InItemName - Name of item being split
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Inventory|UI")
	void InitializeSelector(int64 InMaxQuantity, const FString& InItemName);

	/**
	 * Get the currently selected quantity
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Inventory|UI")
	int64 GetSelectedQuantity() const { return SelectedQuantity; }

	/**
	 * Called when quantity is confirmed
	 */
	UPROPERTY(BlueprintAssignable, Category = "Echoes|Inventory|UI")
	FOnQuantitySelected OnQuantitySelected;

	/**
	 * Called when selection is cancelled
	 */
	UPROPERTY(BlueprintAssignable, Category = "Echoes|Inventory|UI")
	FOnQuantitySelectionCancelled OnQuantitySelectionCancelled;

protected:
	/**
	 * Handle confirm button clicked
	 */
	UFUNCTION()
	void OnConfirmClicked();

	/**
	 * Handle cancel button clicked
	 */
	UFUNCTION()
	void OnCancelClicked();

	/**
	 * Handle slider value changed
	 */
	UFUNCTION()
	void OnSliderValueChanged(float Value);

	/**
	 * Handle text committed in quantity input
	 */
	UFUNCTION()
	void OnQuantityTextCommitted(const FText& Text, ETextCommit::Type CommitMethod);

	/**
	 * Update all UI elements to reflect current quantity
	 */
	void UpdateDisplay();

	/**
	 * Blueprint event called when selector is initialized
	 */
	UFUNCTION(BlueprintImplementableEvent, Category = "Echoes|Inventory|UI")
	void OnSelectorInitialized();

	// Widget bindings

	/** Confirm button */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Echoes|Inventory|UI")
	UButton* ConfirmButton;

	/** Cancel button */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Echoes|Inventory|UI")
	UButton* CancelButton;

	/** Quantity slider */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Echoes|Inventory|UI")
	USlider* QuantitySlider;

	/** Quantity text input */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Echoes|Inventory|UI")
	UEditableTextBox* QuantityInput;

	/** Display for selected quantity */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Echoes|Inventory|UI")
	UTextBlock* SelectedQuantityText;

	/** Display for max quantity */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Echoes|Inventory|UI")
	UTextBlock* MaxQuantityText;

	/** Display for item name */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Echoes|Inventory|UI")
	UTextBlock* ItemNameText;

private:
	/** Maximum quantity available */
	int64 MaxQuantity;

	/** Currently selected quantity */
	int64 SelectedQuantity;

	/** Name of item being split */
	FString ItemName;

	/** Flag to prevent recursive updates */
	bool bUpdatingValue;
};
