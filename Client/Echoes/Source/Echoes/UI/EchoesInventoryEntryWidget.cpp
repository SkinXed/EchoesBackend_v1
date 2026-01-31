// Copyright Epic Games, Inc. All Rights Reserved.

#include "UI/EchoesInventoryEntryWidget.h"
#include "UI/EchoesInventoryItemObject.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"

void UEchoesInventoryEntryWidget::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	// This is called automatically by ListView when an item is assigned to this entry
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);

	UEchoesInventoryItemObject* ItemObject = Cast<UEchoesInventoryItemObject>(ListItemObject);
	if (ItemObject)
	{
		SetItemData(ItemObject);
	}
}

void UEchoesInventoryEntryWidget::SetItemData(UEchoesInventoryItemObject* ItemObject)
{
	if (!ItemObject)
	{
		UE_LOG(LogTemp, Warning, TEXT("EchoesInventoryEntryWidget: SetItemData called with null ItemObject"));
		return;
	}

	CurrentItemObject = ItemObject;

	// Update text displays
	if (ItemNameText)
	{
		ItemNameText->SetText(FText::FromString(ItemObject->GetItemName()));
	}

	if (QuantityText)
	{
		FText QuantityDisplay;
		if (ItemObject->IsStackable())
		{
			QuantityDisplay = FText::Format(
				FText::FromString(TEXT("x{0}")),
				FText::AsNumber(ItemObject->GetQuantity())
			);
		}
		else
		{
			QuantityDisplay = FText::FromString(TEXT("x1"));
		}
		QuantityText->SetText(QuantityDisplay);
	}

	if (VolumeText)
	{
		VolumeText->SetText(FText::FromString(ItemObject->GetFormattedTotalVolume()));
	}

	// Call the Blueprint implementable event for custom display updates
	UpdateDisplay(ItemObject);
}

void UEchoesInventoryEntryWidget::UpdateDisplay_Implementation(UEchoesInventoryItemObject* ItemObject)
{
	// Default implementation - can be overridden in Blueprint
	// Base implementation already handled text updates in SetItemData
	
	// Icon loading would typically be handled here or in Blueprint
	// For now, we leave this as a Blueprint override point
}
