// Copyright Epic Games, Inc. All Rights Reserved.

#include "UI/EchoesQuantitySelectorWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/Slider.h"
#include "Components/EditableTextBox.h"

UEchoesQuantitySelectorWidget::UEchoesQuantitySelectorWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, MaxQuantity(1)
	, SelectedQuantity(1)
	, bUpdatingValue(false)
{
}

void UEchoesQuantitySelectorWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// Bind button events
	if (ConfirmButton)
	{
		ConfirmButton->OnClicked.AddDynamic(this, &UEchoesQuantitySelectorWidget::OnConfirmClicked);
	}

	if (CancelButton)
	{
		CancelButton->OnClicked.AddDynamic(this, &UEchoesQuantitySelectorWidget::OnCancelClicked);
	}

	// Bind slider event
	if (QuantitySlider)
	{
		QuantitySlider->OnValueChanged.AddDynamic(this, &UEchoesQuantitySelectorWidget::OnSliderValueChanged);
	}

	// Bind text input event
	if (QuantityInput)
	{
		QuantityInput->OnTextCommitted.AddDynamic(this, &UEchoesQuantitySelectorWidget::OnQuantityTextCommitted);
	}

	UE_LOG(LogTemp, Log, TEXT("Quantity selector widget constructed"));
}

void UEchoesQuantitySelectorWidget::NativeDestruct()
{
	// Unbind events
	if (ConfirmButton)
	{
		ConfirmButton->OnClicked.RemoveDynamic(this, &UEchoesQuantitySelectorWidget::OnConfirmClicked);
	}

	if (CancelButton)
	{
		CancelButton->OnClicked.RemoveDynamic(this, &UEchoesQuantitySelectorWidget::OnCancelClicked);
	}

	if (QuantitySlider)
	{
		QuantitySlider->OnValueChanged.RemoveDynamic(this, &UEchoesQuantitySelectorWidget::OnSliderValueChanged);
	}

	if (QuantityInput)
	{
		QuantityInput->OnTextCommitted.RemoveDynamic(this, &UEchoesQuantitySelectorWidget::OnQuantityTextCommitted);
	}

	Super::NativeDestruct();
}

void UEchoesQuantitySelectorWidget::InitializeSelector(int64 InMaxQuantity, const FString& InItemName)
{
	MaxQuantity = FMath::Max(InMaxQuantity, (int64)1);
	ItemName = InItemName;
	
	// Start with half the stack by default
	SelectedQuantity = FMath::Max(MaxQuantity / 2, (int64)1);

	// Configure slider
	if (QuantitySlider)
	{
		QuantitySlider->SetMinValue(1.0f);
		QuantitySlider->SetMaxValue(static_cast<float>(MaxQuantity));
		QuantitySlider->SetValue(static_cast<float>(SelectedQuantity));
	}

	// Update all displays
	UpdateDisplay();

	// Trigger Blueprint event
	OnSelectorInitialized();

	UE_LOG(LogTemp, Log, TEXT("Quantity selector initialized: Item=%s, Max=%lld, Initial=%lld"),
		*ItemName, MaxQuantity, SelectedQuantity);
}

void UEchoesQuantitySelectorWidget::OnConfirmClicked()
{
	UE_LOG(LogTemp, Log, TEXT("Quantity confirmed: %lld"), SelectedQuantity);
	
	// Broadcast selection
	OnQuantitySelected.Broadcast(SelectedQuantity);
	
	// Close widget
	RemoveFromParent();
}

void UEchoesQuantitySelectorWidget::OnCancelClicked()
{
	UE_LOG(LogTemp, Log, TEXT("Quantity selection cancelled"));
	
	// Broadcast cancellation
	OnQuantitySelectionCancelled.Broadcast();
	
	// Close widget
	RemoveFromParent();
}

void UEchoesQuantitySelectorWidget::OnSliderValueChanged(float Value)
{
	if (bUpdatingValue)
	{
		return;
	}

	// Update selected quantity from slider
	SelectedQuantity = static_cast<int64>(FMath::RoundToInt(Value));
	SelectedQuantity = FMath::Clamp(SelectedQuantity, (int64)1, MaxQuantity);

	// Update other UI elements
	UpdateDisplay();

	UE_LOG(LogTemp, Verbose, TEXT("Slider changed: %lld"), SelectedQuantity);
}

void UEchoesQuantitySelectorWidget::OnQuantityTextCommitted(const FText& Text, ETextCommit::Type CommitMethod)
{
	if (bUpdatingValue)
	{
		return;
	}

	// Parse quantity from text
	FString QuantityStr = Text.ToString();
	if (QuantityStr.IsNumeric())
	{
		int64 NewQuantity = FCString::Atoi64(*QuantityStr);
		SelectedQuantity = FMath::Clamp(NewQuantity, (int64)1, MaxQuantity);

		// Update other UI elements
		UpdateDisplay();

		UE_LOG(LogTemp, Verbose, TEXT("Text input changed: %lld"), SelectedQuantity);
	}
	else
	{
		// Invalid input, reset to current value
		UpdateDisplay();
	}
}

void UEchoesQuantitySelectorWidget::UpdateDisplay()
{
	bUpdatingValue = true;

	// Update slider
	if (QuantitySlider)
	{
		QuantitySlider->SetValue(static_cast<float>(SelectedQuantity));
	}

	// Update text input
	if (QuantityInput)
	{
		QuantityInput->SetText(FText::AsNumber(SelectedQuantity));
	}

	// Update selected quantity display
	if (SelectedQuantityText)
	{
		SelectedQuantityText->SetText(FText::AsNumber(SelectedQuantity));
	}

	// Update max quantity display
	if (MaxQuantityText)
	{
		MaxQuantityText->SetText(FText::AsNumber(MaxQuantity));
	}

	// Update item name display
	if (ItemNameText)
	{
		ItemNameText->SetText(FText::FromString(ItemName));
	}

	bUpdatingValue = false;
}
