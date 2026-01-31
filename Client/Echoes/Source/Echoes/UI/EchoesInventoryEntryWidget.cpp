// Copyright Epic Games, Inc. All Rights Reserved.

#include "UI/EchoesInventoryEntryWidget.h"
#include "UI/EchoesInventoryItemObject.h"
#include "Core/Common/Networking/EchoesInventorySubsystem.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Engine/Texture2D.h"
#include "Engine/GameInstance.h"

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

	// Update text displays - use item definition data if available
	if (ItemNameText)
	{
		ItemNameText->SetText(ItemObject->GetDisplayName());
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
		// Use calculated volume from item definition
		VolumeText->SetText(FText::FromString(ItemObject->GetFormattedTotalVolume()));
	}

	// Set placeholder icon while loading the real one
	if (ItemIcon)
	{
		if (PlaceholderIcon)
		{
			ItemIcon->SetBrushFromTexture(PlaceholderIcon);
		}
		
		// Start async icon loading
		StartAsyncIconLoad();
	}

	// Call the Blueprint implementable event for custom display updates
	UpdateDisplay(ItemObject);
}

void UEchoesInventoryEntryWidget::StartAsyncIconLoad()
{
	if (!CurrentItemObject)
	{
		return;
	}

	// Check if item has definition with icon
	const FEchoesItemDefinitionRow* Definition = CurrentItemObject->GetItemDefinition();
	if (!Definition || Definition->Icon.IsNull())
	{
		UE_LOG(LogTemp, Verbose, TEXT("EchoesInventoryEntryWidget: No icon defined for item %d"), CurrentItemObject->GetTypeId());
		return;
	}

	// If icon is already loaded, use it immediately
	if (Definition->Icon.IsValid())
	{
		if (ItemIcon)
		{
			ItemIcon->SetBrushFromTexture(Definition->Icon.Get());
		}
		OnIconLoaded(Definition->Icon.Get());
		return;
	}

	// Get inventory subsystem for async loading
	UGameInstance* GameInstance = GetGameInstance();
	if (!GameInstance)
	{
		return;
	}

	UEchoesInventorySubsystem* InventorySubsystem = GameInstance->GetSubsystem<UEchoesInventorySubsystem>();
	if (!InventorySubsystem)
	{
		UE_LOG(LogTemp, Warning, TEXT("EchoesInventoryEntryWidget: No inventory subsystem available"));
		return;
	}

	// Start async load
	FString ItemIdStr = FString::FromInt(CurrentItemObject->GetTypeId());
	InventorySubsystem->AsyncLoadItemIcon(
		ItemIdStr,
		FOnIconLoaded::CreateUObject(this, &UEchoesInventoryEntryWidget::HandleIconLoaded)
	);
}

void UEchoesInventoryEntryWidget::HandleIconLoaded(UTexture2D* LoadedIcon)
{
	if (LoadedIcon && ItemIcon)
	{
		ItemIcon->SetBrushFromTexture(LoadedIcon);
		UE_LOG(LogTemp, Verbose, TEXT("EchoesInventoryEntryWidget: Icon loaded for item %d"), 
			CurrentItemObject ? CurrentItemObject->GetTypeId() : 0);
	}

	// Notify Blueprint
	OnIconLoaded(LoadedIcon);
}

void UEchoesInventoryEntryWidget::UpdateDisplay_Implementation(UEchoesInventoryItemObject* ItemObject)
{
	// Default implementation - can be overridden in Blueprint
	// Base implementation already handled text updates in SetItemData
	
	// Icon loading would typically be handled here or in Blueprint
	// For now, we leave this as a Blueprint override point
}
