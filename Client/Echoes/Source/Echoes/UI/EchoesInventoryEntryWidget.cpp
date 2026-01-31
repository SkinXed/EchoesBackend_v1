// Copyright Epic Games, Inc. All Rights Reserved.

#include "UI/EchoesInventoryEntryWidget.h"
#include "UI/EchoesInventoryItemObject.h"
#include "UI/EchoesInventoryDragDrop.h"
#include "UI/EchoesQuantitySelectorWidget.h"
#include "UI/EchoesInventoryWidget.h"
#include "UI/EchoesContextMenuWidget.h"
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

	if (!CurrentItemObject)
	{
		return Reply;
	}

	// Handle right mouse button for context menu
	if (InMouseEvent.IsMouseButtonDown(EKeys::RightMouseButton))
	{
		ShowContextMenu();
		return FReply::Handled();
	}

	// Handle left mouse button for dragging
	if (InMouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton))
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

	// Handle stack splitting if Shift held and item is stackable with quantity > 1
	if (bIsShiftHeld && bIsStackable && TotalQuantity > 1)
	{
		// Check if quantity selector class is set
		if (!QuantitySelectorClass)
		{
			UE_LOG(LogTemp, Warning, TEXT("Quantity selector class not set, using default half-stack"));
			// Fall back to half-stack
			CreateDragOperationWithQuantity(InGeometry, InMouseEvent, OutOperation, TotalQuantity / 2);
			return;
		}

		// Store pending drag data
		PendingDragGeometry = InGeometry;
		PendingDragEvent = InMouseEvent;
		bWaitingForDragQuantity = true;

		// Create quantity selector
		UEchoesQuantitySelectorWidget* QuantitySelector = CreateWidget<UEchoesQuantitySelectorWidget>(
			GetWorld(), QuantitySelectorClass);
		
		if (!QuantitySelector)
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to create quantity selector widget"));
			bWaitingForDragQuantity = false;
			return;
		}

		// Initialize selector
		QuantitySelector->InitializeSelector(TotalQuantity, CurrentItemObject->GetItemName());

		// Bind to delegates
		QuantitySelector->OnQuantitySelected.AddDynamic(this, &UEchoesInventoryEntryWidget::OnDragQuantitySelected);
		QuantitySelector->OnQuantitySelectionCancelled.AddDynamic(this, &UEchoesInventoryEntryWidget::OnDragQuantityCancelled);

		// Add to viewport as modal (high Z-order)
		QuantitySelector->AddToViewport(1000);

		UE_LOG(LogTemp, Log, TEXT("Quantity selector shown for drag operation"));

		// Don't create drag operation yet - wait for user input
		return;
	}

	// Normal drag (no shift or not stackable) - use full quantity
	CreateDragOperationWithQuantity(InGeometry, InMouseEvent, OutOperation, TotalQuantity);
}

void UEchoesInventoryEntryWidget::CreateDragOperationWithQuantity(
	const FGeometry& InGeometry,
	const FPointerEvent& InMouseEvent,
	UDragDropOperation*& OutOperation,
	int64 Quantity)
{
	if (!CurrentItemObject)
	{
		return;
	}

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

	// Create drag drop operation
	UEchoesInventoryDragDrop* DragDropOp = NewObject<UEchoesInventoryDragDrop>();
	DragDropOp->InitializeDragOperation(
		CurrentItemObject->GetItemData(),
		SourceStorageId,
		SourceActor,
		Quantity
	);

	// Set default drag visual (create a simple widget showing the item)
	DragDropOp->DefaultDragVisual = CreateDragVisual();
	DragDropOp->Pivot = EDragPivot::MouseDown;

	OutOperation = DragDropOp;

	UE_LOG(LogTemp, Log, TEXT("Drag operation created: Item=%s, Quantity=%lld"),
		*CurrentItemObject->GetItemName(), Quantity);
}

void UEchoesInventoryEntryWidget::OnDragQuantitySelected(int64 SelectedQuantity)
{
	bWaitingForDragQuantity = false;

	UE_LOG(LogTemp, Log, TEXT("Drag quantity selected: %lld"), SelectedQuantity);

	// Note: In Unreal, we can't resume a drag operation after it's been paused
	// The proper implementation would require Blueprint to handle this
	// For now, we log that the quantity was selected
	// Blueprint should create the drag operation manually with this quantity
	
	// In a full implementation, Blueprint would:
	// 1. Receive OnDragQuantitySelected event
	// 2. Create UEchoesInventoryDragDrop with SelectedQuantity
	// 3. Begin drag operation programmatically
}

void UEchoesInventoryEntryWidget::OnDragQuantityCancelled()
{
	bWaitingForDragQuantity = false;
	UE_LOG(LogTemp, Log, TEXT("Drag quantity selection cancelled"));
	OnDragCancelled();
}

void UEchoesInventoryEntryWidget::OnJettisonQuantitySelected(int64 SelectedQuantity)
{
	if (!CurrentItemObject)
	{
		UE_LOG(LogTemp, Error, TEXT("No current item for jettison"));
		return;
	}

	// Get inventory component
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
		return;
	}

	UEchoesInventoryComponent* Component = InventoryWidget->GetInventoryComponent();
	if (!Component)
	{
		UE_LOG(LogTemp, Error, TEXT("Could not find inventory component"));
		return;
	}

	// Jettison item with selected quantity
	Component->ServerOnly_JettisonItem(
		CurrentItemObject->GetAssetId(),
		SelectedQuantity,
		FOnItemMoveSuccess::CreateLambda([SelectedQuantity]()
		{
			UE_LOG(LogTemp, Log, TEXT("Jettisoned %lld items successfully"), SelectedQuantity);
		}),
		FOnInventoryOperationFailure::CreateLambda([](const FString& Error)
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to jettison item: %s"), *Error);
		})
	);
}

void UEchoesInventoryEntryWidget::OnJettisonQuantityCancelled()
{
	UE_LOG(LogTemp, Log, TEXT("Jettison quantity selection cancelled"));
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

void UEchoesInventoryEntryWidget::ShowContextMenu()
{
	if (!CurrentItemObject)
	{
		UE_LOG(LogTemp, Warning, TEXT("Cannot show context menu: no current item"));
		return;
	}

	if (!ContextMenuClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("Cannot show context menu: ContextMenuClass not set"));
		return;
	}

	// Get available actions for this item
	TArray<FContextMenuAction> Actions = GetDefaultActionsForItem(CurrentItemObject);
	
	// Allow Blueprint to modify actions
	OnContextMenuRequested(CurrentItemObject, Actions);

	if (Actions.Num() == 0)
	{
		UE_LOG(LogTemp, Log, TEXT("No actions available for item: %s"), *CurrentItemObject->GetItemName());
		return;
	}

	// Get inventory widget and component
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
		UE_LOG(LogTemp, Error, TEXT("Could not find parent inventory widget for context menu"));
		return;
	}

	UEchoesInventoryComponent* Component = InventoryWidget->GetInventoryComponent();
	if (!Component)
	{
		UE_LOG(LogTemp, Error, TEXT("Could not find inventory component for context menu"));
		return;
	}

	AActor* SourceActor = Component->GetOwner();
	FGuid SourceStorageId = Component->StorageId;

	// Create context menu
	UEchoesContextMenuWidget* ContextMenu = CreateWidget<UEchoesContextMenuWidget>(GetWorld(), ContextMenuClass);
	if (!ContextMenu)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to create context menu widget"));
		return;
	}

	// Initialize menu
	ContextMenu->InitializeMenu(CurrentItemObject, SourceStorageId, SourceActor, Actions);

	// Bind to action selected delegate
	ContextMenu->OnActionSelected.AddDynamic(this, &UEchoesInventoryEntryWidget::HandleContextMenuAction);

	// Add to viewport
	ContextMenu->AddToViewport(999); // High Z-order

	UE_LOG(LogTemp, Log, TEXT("Context menu shown for item: %s, Actions: %d"),
		*CurrentItemObject->GetItemName(), Actions.Num());
}

TArray<FContextMenuAction> UEchoesInventoryEntryWidget::GetDefaultActionsForItem(UEchoesInventoryItemObject* ItemObject)
{
	TArray<FContextMenuAction> Actions;

	if (!ItemObject)
	{
		return Actions;
	}

	// Always available: Jettison (drop item)
	Actions.Add(FContextMenuAction(
		FText::FromString(TEXT("Jettison")),
		TEXT("jettison"),
		true
	));

	// Check if item can be used/equipped
	// This is a simplified check - full implementation would check item category
	const FEchoesItemDefinitionRow* Definition = ItemObject->GetItemDefinition();
	if (Definition)
	{
		// If it's a module or equipment, show Use/Fit option
		FString Category = Definition->Category.ToString();
		if (Category.Contains(TEXT("Module")) || Category.Contains(TEXT("Equipment")))
		{
			Actions.Add(FContextMenuAction(
				FText::FromString(TEXT("Fit to Ship")),
				TEXT("fit"),
				false // Disabled for now (stub)
			));
		}
	}

	// Stack All option (available for stackable items)
	if (ItemObject->IsStackable())
	{
		Actions.Add(FContextMenuAction(
			FText::FromString(TEXT("Stack All")),
			TEXT("stack_all"),
			true
		));
	}

	// Additional actions can be added based on item type
	// Examples: Repackage, Trash, Split Stack, etc.

	return Actions;
}

void UEchoesInventoryEntryWidget::HandleContextMenuAction(const FString& ActionId)
{
	if (!CurrentItemObject)
	{
		UE_LOG(LogTemp, Error, TEXT("Context menu action but no current item"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Handling context menu action: %s for item: %s"),
		*ActionId, *CurrentItemObject->GetItemName());

	// Get inventory component
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
		return;
	}

	UEchoesInventoryComponent* Component = InventoryWidget->GetInventoryComponent();
	if (!Component)
	{
		UE_LOG(LogTemp, Error, TEXT("Could not find inventory component"));
		return;
	}

	// Execute action
	if (ActionId == TEXT("jettison"))
	{
		// Check if item has quantity > 1, show quantity selector
		if (CurrentItemObject->IsStackable() && CurrentItemObject->GetQuantity() > 1 && QuantitySelectorClass)
		{
			// Show quantity selector
			UEchoesQuantitySelectorWidget* QuantitySelector = CreateWidget<UEchoesQuantitySelectorWidget>(
				GetWorld(), QuantitySelectorClass);
			
			if (QuantitySelector)
			{
				QuantitySelector->InitializeSelector(
					CurrentItemObject->GetQuantity(),
					CurrentItemObject->GetItemName()
				);

				// Bind to delegates
				QuantitySelector->OnQuantitySelected.AddDynamic(this, &UEchoesInventoryEntryWidget::OnJettisonQuantitySelected);
				QuantitySelector->OnQuantitySelectionCancelled.AddDynamic(this, &UEchoesInventoryEntryWidget::OnJettisonQuantityCancelled);

				// Add to viewport as modal
				QuantitySelector->AddToViewport(1000);

				UE_LOG(LogTemp, Log, TEXT("Quantity selector shown for jettison"));
				return;
			}
		}

		// Jettison entire stack
		Component->ServerOnly_JettisonItem(
			CurrentItemObject->GetAssetId(),
			0, // 0 = all quantity
			FOnItemMoveSuccess::CreateLambda([this]()
			{
				UE_LOG(LogTemp, Log, TEXT("Item jettisoned successfully"));
			}),
			FOnInventoryOperationFailure::CreateLambda([this](const FString& Error)
			{
				UE_LOG(LogTemp, Error, TEXT("Failed to jettison item: %s"), *Error);
			})
		);
	}
	else if (ActionId == TEXT("fit"))
	{
		// Fit to ship (stub)
		UE_LOG(LogTemp, Warning, TEXT("Fit to ship not implemented yet"));
	}
	else if (ActionId == TEXT("stack_all"))
	{
		// Stack all items of this type
		Component->ServerOnly_StackAll(
			CurrentItemObject->GetTypeId(),
			FOnItemMoveSuccess::CreateLambda([this]()
			{
				UE_LOG(LogTemp, Log, TEXT("Items stacked successfully"));
			}),
			FOnInventoryOperationFailure::CreateLambda([this](const FString& Error)
			{
				UE_LOG(LogTemp, Error, TEXT("Failed to stack items: %s"), *Error);
			})
		);
	}

	// Notify Blueprint
	OnContextMenuActionExecuted(CurrentItemObject, ActionId);
}

void UEchoesInventoryEntryWidget::OnContextMenuRequested_Implementation(UEchoesInventoryItemObject* ItemObject, TArray<FContextMenuAction>& OutActions)
{
	// Default implementation - Blueprint can override to customize actions
}
