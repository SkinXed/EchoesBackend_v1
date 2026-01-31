// Copyright Epic Games, Inc. All Rights Reserved.

#include "UI/EchoesInventoryEntryWidget.h"
#include "UI/EchoesInventoryItemObject.h"
#include "UI/EchoesInventoryDragDrop.h"
#include "UI/EchoesQuantitySelectorWidget.h"
#include "UI/EchoesInventoryWidget.h"
#include "Core/Common/Networking/EchoesInventorySubsystem.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Engine/Texture2D.h"
#include "Engine/GameInstance.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Blueprint/SlateBlueprintLibrary.h"

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

FReply UEchoesInventoryEntryWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	FReply Reply = Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);

	// Only handle left mouse button for dragging
	if (InMouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton) && CurrentItemObject)
	{
		// Check if Shift is held
		bool bIsShiftHeld = InMouseEvent.IsShiftDown();

		// Ask Blueprint if drag should start
		if (OnDragStarting(CurrentItemObject, bIsShiftHeld))
		{
			// Detect drag if pressed
			Reply = Reply.DetectDrag(TakeWidget(), EKeys::LeftMouseButton);
			UE_LOG(LogTemp, Verbose, TEXT("Drag detection started for item: %s (Shift: %d)"),
				*CurrentItemObject->GetItemName(), bIsShiftHeld);
		}
	}

	return Reply;
}

void UEchoesInventoryEntryWidget::NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation*& OutOperation)
{
	Super::NativeOnDragDetected(InGeometry, InMouseEvent, OutOperation);

	if (!CurrentItemObject)
	{
		UE_LOG(LogTemp, Warning, TEXT("Drag detected but no current item object"));
		return;
	}

	// Check if Shift is held for stack splitting
	bool bIsShiftHeld = InMouseEvent.IsShiftDown();
	bool bIsStackable = CurrentItemObject->IsStackable();
	int64 TotalQuantity = CurrentItemObject->GetQuantity();

	// Get the inventory widget to find source storage
	UEchoesInventoryWidget* InventoryWidget = nullptr;
	UWidget* ParentWidget = GetParent();
	while (ParentWidget)
	{
		InventoryWidget = Cast<UEchoesInventoryWidget>(ParentWidget);
		if (InventoryWidget)
		{
			break;
		}
		ParentWidget = ParentWidget->GetParent();
	}

	if (!InventoryWidget)
	{
		UE_LOG(LogTemp, Error, TEXT("Could not find parent inventory widget"));
		OnDragCancelled();
		return;
	}

	// Get source actor and component
	UEchoesInventoryComponent* SourceComponent = InventoryWidget->GetInventoryComponent();
	if (!SourceComponent)
	{
		UE_LOG(LogTemp, Error, TEXT("Source inventory component not found"));
		OnDragCancelled();
		return;
	}

	AActor* SourceActor = SourceComponent->GetOwner();
	FGuid SourceStorageId = SourceComponent->StorageId;

	// Handle stack splitting if Shift held and item is stackable with quantity > 1
	int64 QuantityToMove = TotalQuantity;
	
	if (bIsShiftHeld && bIsStackable && TotalQuantity > 1)
	{
		// TODO: Open quantity selector widget
		// For now, just use half the stack
		QuantityToMove = FMath::Max(TotalQuantity / 2, (int64)1);
		
		UE_LOG(LogTemp, Log, TEXT("Stack split: moving %lld of %lld"), QuantityToMove, TotalQuantity);
		
		// In a full implementation, we would:
		// 1. Create and show W_QuantitySelector widget
		// 2. Wait for user input
		// 3. Use selected quantity
		// For now, we proceed with half the stack
	}

	// Create drag drop operation
	UEchoesInventoryDragDrop* DragDropOp = NewObject<UEchoesInventoryDragDrop>();
	DragDropOp->InitializeDragOperation(
		CurrentItemObject->GetItemData(),
		SourceStorageId,
		SourceActor,
		QuantityToMove
	);

	// Set default drag visual (create a simple widget showing the item)
	DragDropOp->DefaultDragVisual = CreateDragVisual();
	DragDropOp->Pivot = EDragPivot::MouseDown;

	OutOperation = DragDropOp;

	UE_LOG(LogTemp, Log, TEXT("Drag operation created: Item=%s, Quantity=%lld"),
		*CurrentItemObject->GetItemName(), QuantityToMove);
}

UUserWidget* UEchoesInventoryEntryWidget::CreateDragVisual()
{
	// Create a simple visual feedback widget
	// In a full implementation, this would be a proper widget blueprint
	// For now, we create a basic widget with the item icon

	UUserWidget* DragVisual = CreateWidget<UUserWidget>(GetWorld(), GetClass());
	if (DragVisual)
	{
		// Copy the current visual state
		// This is a simplified version - Blueprint can customize this
		UE_LOG(LogTemp, Verbose, TEXT("Created drag visual widget"));
	}

	return DragVisual;
}
