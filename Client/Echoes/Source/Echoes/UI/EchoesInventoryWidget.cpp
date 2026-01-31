// Copyright Epic Games, Inc. All Rights Reserved.

#include "UI/EchoesInventoryWidget.h"
#include "UI/EchoesInventoryItemObject.h"
#include "UI/EchoesInventoryDragDrop.h"
#include "Components/ListView.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

UEchoesInventoryWidget::UEchoesInventoryWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	InventoryComponent = nullptr;
	CurrentViewedActor = nullptr;
	TargetActor = nullptr;
	bAutoRefreshOnConstruct = true;
}

void UEchoesInventoryWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// Bind to ListView selection events
	if (InventoryListView)
	{
		InventoryListView->OnItemSelectionChanged().AddUObject(this, &UEchoesInventoryWidget::OnItemSelectionChanged);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("EchoesInventoryWidget: InventoryListView not bound! Make sure it's named 'InventoryListView' in UMG."));
	}

	// Find and bind to inventory component
	if (FindAndBindInventoryComponent())
	{
		// Auto-refresh if enabled
		if (bAutoRefreshOnConstruct)
		{
			RefreshInventory();
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("EchoesInventoryWidget: Failed to find inventory component on construct"));
	}
}

void UEchoesInventoryWidget::NativeDestruct()
{
	// Unbind from inventory component
	UnbindInventoryComponent();

	Super::NativeDestruct();
}

bool UEchoesInventoryWidget::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
	// Check if this is an inventory drag drop operation
	UEchoesInventoryDragDrop* DragDropOp = Cast<UEchoesInventoryDragDrop>(InOperation);
	if (!DragDropOp)
	{
		UE_LOG(LogTemp, Verbose, TEXT("Drop operation is not an inventory drag drop"));
		return Super::NativeOnDrop(InGeometry, InDragDropEvent, InOperation);
	}

	// Check if we have a valid target inventory component
	if (!InventoryComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("Cannot drop item: no target inventory component"));
		OnMoveRequestFailed(TEXT("No target inventory component"));
		return false;
	}

	// Get source information from drag operation
	FEchoesInventoryItem ItemData = DragDropOp->GetItemData();
	FGuid SourceStorageId = DragDropOp->GetSourceStorageId();
	AActor* SourceActor = DragDropOp->GetSourceActor();
	int64 Quantity = DragDropOp->GetQuantity();

	// Get target storage ID
	FGuid TargetStorageId = InventoryComponent->StorageId;
	AActor* TargetActorLocal = CurrentViewedActor;

	// Validate drop
	if (!SourceActor || !TargetActorLocal)
	{
		UE_LOG(LogTemp, Warning, TEXT("Cannot drop item: invalid source or target actor"));
		OnMoveRequestFailed(TEXT("Invalid source or target actor"));
		return false;
	}

	// Don't allow dropping on same container
	if (SourceStorageId == TargetStorageId)
	{
		UE_LOG(LogTemp, Verbose, TEXT("Cannot drop item on same container"));
		return false;
	}

	UE_LOG(LogTemp, Log, TEXT("Item dropped: %s, Quantity: %lld, Source: %s, Target: %s"),
		*ItemData.TypeName, Quantity, *SourceStorageId.ToString(), *TargetStorageId.ToString());

	// Call ServerOnly_MoveItem on the source component
	// We need to find the source component
	UEchoesInventoryComponent* SourceComponent = SourceActor->FindComponentByClass<UEchoesInventoryComponent>();
	if (!SourceComponent)
	{
		UE_LOG(LogTemp, Error, TEXT("Cannot find source inventory component"));
		OnMoveRequestFailed(TEXT("Source inventory component not found"));
		return false;
	}

	FOnItemMoveSuccess OnSuccess;
	OnSuccess.BindDynamic(this, &UEchoesInventoryWidget::HandleMoveSuccess);

	FOnInventoryOperationFailure OnFailure;
	OnFailure.BindDynamic(this, &UEchoesInventoryWidget::HandleMoveFailure);

	// Execute the move
	SourceComponent->ServerOnly_MoveItem(
		ItemData.AssetId,
		TargetActorLocal,
		SourceActor,
		Quantity,
		OnSuccess,
		OnFailure
	);

	return true;
}

void UEchoesInventoryWidget::RefreshInventory()
{
	if (!InventoryComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("EchoesInventoryWidget: Cannot refresh - no inventory component"));
		return;
	}

	FOnItemsFetched OnSuccess;
	OnSuccess.BindDynamic(this, &UEchoesInventoryWidget::PopulateInventoryList);

	FOnInventoryOperationFailure OnFailure;
	OnFailure.BindDynamic(this, &UEchoesInventoryWidget::HandleFetchFailure);

	// Fetch items from component
	InventoryComponent->FetchItems(OnSuccess, OnFailure);
}

void UEchoesInventoryWidget::SetTargetActor(AActor* NewTargetActor)
{
	if (TargetActor == NewTargetActor)
	{
		return;
	}

	// Unbind from old component
	UnbindInventoryComponent();

	// Set new target
	TargetActor = NewTargetActor;

	// Find and bind to new component
	if (FindAndBindInventoryComponent())
	{
		RefreshInventory();
	}
}

UEchoesInventoryItemObject* UEchoesInventoryWidget::GetSelectedItem() const
{
	if (!InventoryListView)
	{
		return nullptr;
	}

	UObject* SelectedObject = InventoryListView->GetSelectedItem();
	return Cast<UEchoesInventoryItemObject>(SelectedObject);
}

void UEchoesInventoryWidget::UI_RequestMoveItem(AActor* TargetContainerActor, int64 Quantity)
{
	if (!InventoryComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("EchoesInventoryWidget: Cannot move item - no inventory component"));
		OnMoveRequestFailed(TEXT("No inventory component"));
		return;
	}

	if (!TargetContainerActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("EchoesInventoryWidget: Cannot move item - no target actor"));
		OnMoveRequestFailed(TEXT("No target actor specified"));
		return;
	}

	UEchoesInventoryItemObject* SelectedItem = GetSelectedItem();
	if (!SelectedItem)
	{
		UE_LOG(LogTemp, Warning, TEXT("EchoesInventoryWidget: Cannot move item - no item selected"));
		OnMoveRequestFailed(TEXT("No item selected"));
		return;
	}

	// Get source actor (the actor we're viewing inventory from)
	AActor* SourceActor = CurrentViewedActor;
	if (!SourceActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("EchoesInventoryWidget: Cannot move item - no source actor"));
		OnMoveRequestFailed(TEXT("No source actor"));
		return;
	}

	FOnItemMoveSuccess OnSuccess;
	OnSuccess.BindDynamic(this, &UEchoesInventoryWidget::HandleMoveSuccess);

	FOnInventoryOperationFailure OnFailure;
	OnFailure.BindDynamic(this, &UEchoesInventoryWidget::HandleMoveFailure);

	// Call ServerOnly_MoveItem on the inventory component
	// This should only be called on the server in a real game
	InventoryComponent->ServerOnly_MoveItem(
		SelectedItem->GetAssetId(),
		TargetContainerActor,
		SourceActor,
		Quantity,
		OnSuccess,
		OnFailure
	);
}

void UEchoesInventoryWidget::OnInventoryUpdated(const FEchoesContainerItems& Items)
{
	// Inventory was updated, refresh the list
	PopulateInventoryList(Items);
	OnInventoryRefreshed();
}

void UEchoesInventoryWidget::PopulateInventoryList(const FEchoesContainerItems& Items)
{
	if (!InventoryListView)
	{
		UE_LOG(LogTemp, Error, TEXT("EchoesInventoryWidget: Cannot populate list - InventoryListView is null"));
		return;
	}

	// Clear existing items
	InventoryListView->ClearListItems();

	// Create item objects for each inventory item
	for (const FEchoesInventoryItem& Item : Items.Items)
	{
		UEchoesInventoryItemObject* ItemObject = NewObject<UEchoesInventoryItemObject>(this);
		if (ItemObject)
		{
			ItemObject->InitializeWithData(Item);
			InventoryListView->AddItem(ItemObject);
		}
	}

	UE_LOG(LogTemp, Log, TEXT("EchoesInventoryWidget: Populated list with %d items"), Items.Items.Num());
	
	// Trigger Blueprint event
	OnInventoryRefreshed();
}

void UEchoesInventoryWidget::OnItemSelectionChanged(UObject* ItemObject)
{
	UEchoesInventoryItemObject* SelectedItem = Cast<UEchoesInventoryItemObject>(ItemObject);
	if (SelectedItem)
	{
		UE_LOG(LogTemp, Log, TEXT("EchoesInventoryWidget: Item selected: %s"), *SelectedItem->GetItemName());
		OnItemSelected(SelectedItem);
	}
}

bool UEchoesInventoryWidget::FindAndBindInventoryComponent()
{
	AActor* ActorToView = TargetActor;

	// If no target actor specified, try to get the owning player's pawn
	if (!ActorToView)
	{
		APlayerController* PC = GetOwningPlayer();
		if (PC)
		{
			ActorToView = PC->GetPawn();
		}
	}

	if (!ActorToView)
	{
		UE_LOG(LogTemp, Warning, TEXT("EchoesInventoryWidget: No actor to view inventory from"));
		return false;
	}

	// Find inventory component on the actor
	UEchoesInventoryComponent* NewComponent = ActorToView->FindComponentByClass<UEchoesInventoryComponent>();
	if (!NewComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("EchoesInventoryWidget: Actor %s has no UEchoesInventoryComponent"), *ActorToView->GetName());
		return false;
	}

	// Bind to the component's update delegate
	NewComponent->OnInventoryUpdated.AddDynamic(this, &UEchoesInventoryWidget::OnInventoryUpdated);

	InventoryComponent = NewComponent;
	CurrentViewedActor = ActorToView;

	UE_LOG(LogTemp, Log, TEXT("EchoesInventoryWidget: Bound to inventory component on %s"), *ActorToView->GetName());

	return true;
}

void UEchoesInventoryWidget::UnbindInventoryComponent()
{
	if (InventoryComponent)
	{
		InventoryComponent->OnInventoryUpdated.RemoveDynamic(this, &UEchoesInventoryWidget::OnInventoryUpdated);
		InventoryComponent = nullptr;
	}

	CurrentViewedActor = nullptr;
}

void UEchoesInventoryWidget::HandleMoveSuccess()
{
	UE_LOG(LogTemp, Log, TEXT("EchoesInventoryWidget: Item move successful"));
}

void UEchoesInventoryWidget::HandleMoveFailure(const FString& Error)
{
	UE_LOG(LogTemp, Error, TEXT("EchoesInventoryWidget: Item move failed: %s"), *Error);
	OnMoveRequestFailed(Error);
}

void UEchoesInventoryWidget::HandleFetchFailure(const FString& Error)
{
	UE_LOG(LogTemp, Error, TEXT("EchoesInventoryWidget: Failed to fetch items: %s"), *Error);
}
