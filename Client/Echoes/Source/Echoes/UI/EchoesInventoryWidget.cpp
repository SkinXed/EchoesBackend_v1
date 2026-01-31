// Copyright Epic Games, Inc. All Rights Reserved.

#include "UI/EchoesInventoryWidget.h"
#include "UI/EchoesInventoryItemObject.h"
#include "Components/ListView.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"

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

void UEchoesInventoryWidget::RefreshInventory()
{
	if (!InventoryComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("EchoesInventoryWidget: Cannot refresh - no inventory component"));
		return;
	}

	// Fetch items from component
	InventoryComponent->FetchItems(
		FOnItemsFetched::CreateUObject(this, &UEchoesInventoryWidget::PopulateInventoryList),
		FOnInventoryOperationFailure::CreateLambda([](const FString& Error)
		{
			UE_LOG(LogTemp, Error, TEXT("EchoesInventoryWidget: Failed to fetch items: %s"), *Error);
		})
	);
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

	// Call ServerOnly_MoveItem on the inventory component
	// This should only be called on the server in a real game
	InventoryComponent->ServerOnly_MoveItem(
		SelectedItem->GetAssetId(),
		TargetContainerActor,
		SourceActor,
		Quantity,
		FOnItemMoveSuccess::CreateLambda([this]()
		{
			UE_LOG(LogTemp, Log, TEXT("EchoesInventoryWidget: Item move successful"));
			// Items will be auto-refreshed by the OnInventoryUpdated delegate
		}),
		FOnInventoryOperationFailure::CreateLambda([this](const FString& Error)
		{
			UE_LOG(LogTemp, Error, TEXT("EchoesInventoryWidget: Item move failed: %s"), *Error);
			OnMoveRequestFailed(Error);
		})
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
