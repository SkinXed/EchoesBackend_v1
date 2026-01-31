// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Core/Common/EchoesInventoryComponent.h"
#include "EchoesInventoryWidget.generated.h"

class UListView;
class UEchoesInventoryItemObject;
class AActor;

/**
 * UEchoesInventoryWidget
 * 
 * Main inventory UI widget using ListView
 * Displays contents of a UEchoesInventoryComponent
 * 
 * Features:
 * - Automatic binding to owner's or target actor's inventory component
 * - Event-driven updates via OnInventoryUpdated delegate
 * - ListView-based display for efficient rendering
 * - Selection support
 * - Drag-and-drop preparation
 * 
 * Usage:
 * - Create widget blueprint based on this class
 * - Add UListView widget (name it "InventoryListView")
 * - Set entry widget class in ListView properties
 * - Optionally set TargetActor to view another actor's inventory
 * - Call RefreshInventory() to manually refresh
 */
UCLASS()
class ECHOES_API UEchoesInventoryWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UEchoesInventoryWidget(const FObjectInitializer& ObjectInitializer);

	// UUserWidget interface
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	virtual bool NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;
	// End of UUserWidget interface

	/**
	 * Manually refresh the inventory display
	 * This will fetch items from the component and update the list
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Inventory|UI")
	void RefreshInventory();

	/**
	 * Set the target actor whose inventory to display
	 * If not set, will use the owning player's pawn
	 * @param NewTargetActor - Actor with UEchoesInventoryComponent
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Inventory|UI")
	void SetTargetActor(AActor* NewTargetActor);

	/**
	 * Get the currently selected item
	 * @return Selected inventory item object, or nullptr if none selected
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Inventory|UI")
	UEchoesInventoryItemObject* GetSelectedItem() const;

	/**
	 * Request to move the selected item to another container
	 * This is a UI stub that should trigger ServerOnly_MoveItem on the component
	 * @param TargetContainerActor - The target actor to move items to
	 * @param Quantity - Amount to move (0 = all)
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Inventory|UI")
	void UI_RequestMoveItem(AActor* TargetContainerActor, int64 Quantity = 0);

	/**
	 * Get the inventory component we're currently displaying
	 * @return The inventory component, or nullptr if not found
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Inventory|UI")
	UEchoesInventoryComponent* GetInventoryComponent() const { return InventoryComponent; }

protected:
	/**
	 * Called when inventory is updated from the component
	 * @param Items - New inventory items
	 */
	UFUNCTION()
	void OnInventoryUpdated(const FEchoesContainerItems& Items);

	/**
	 * Populate the list view with inventory items
	 * @param Items - Items to display
	 */
	UFUNCTION()
	void PopulateInventoryList(const FEchoesContainerItems& Items);

	/**
	 * Handle item selection changed
	 * @param ItemObject - Selected item object
	 */
	UFUNCTION()
	void OnItemSelectionChanged(UObject* ItemObject);

	/**
	 * Blueprint event called when inventory is refreshed
	 * Override in Blueprint for custom behavior
	 */
	UFUNCTION(BlueprintImplementableEvent, Category = "Echoes|Inventory|UI")
	void OnInventoryRefreshed();

	/**
	 * Blueprint event called when an item is selected
	 * Override in Blueprint for custom selection behavior
	 * @param ItemObject - The selected item
	 */
	UFUNCTION(BlueprintImplementableEvent, Category = "Echoes|Inventory|UI")
	void OnItemSelected(UEchoesInventoryItemObject* ItemObject);

	/**
	 * Blueprint event called when move request fails
	 * Override in Blueprint to show error message
	 * @param ErrorMessage - Error message to display
	 */
	UFUNCTION(BlueprintImplementableEvent, Category = "Echoes|Inventory|UI")
	void OnMoveRequestFailed(const FString& ErrorMessage);

	// Widget bindings

	/** ListView widget for displaying inventory items */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Echoes|Inventory|UI")
	UListView* InventoryListView;

	/** Optional target actor to display inventory from (if not owner) */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Echoes|Inventory|UI")
	AActor* TargetActor;

	/** Whether to auto-refresh on construct */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Echoes|Inventory|UI")
	bool bAutoRefreshOnConstruct = true;

private:
	/** Cached inventory component reference */
	UPROPERTY()
	UEchoesInventoryComponent* InventoryComponent;

	/** Actor we're currently viewing inventory from */
	UPROPERTY()
	AActor* CurrentViewedActor;

	/**
	 * Find and bind to inventory component
	 * @return True if component was found and bound
	 */
	bool FindAndBindInventoryComponent();

	/**
	 * Unbind from current inventory component
	 */
	void UnbindInventoryComponent();

	UFUNCTION()
	void HandleMoveSuccess();

	UFUNCTION()
	void HandleMoveFailure(const FString& Error);

	UFUNCTION()
	void HandleFetchFailure(const FString& Error);
};
