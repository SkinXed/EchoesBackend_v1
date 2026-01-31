// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "UI/EchoesContextMenuWidget.h"
#include "EchoesInventoryEntryWidget.generated.h"

class UTextBlock;
class UImage;
class UEchoesInventoryItemObject;

/**
 * UEchoesInventoryEntryWidget
 * 
 * Entry widget for inventory list items
 * Implements IUserObjectListEntry to work with UListView
 * Displays item icon, name, quantity, and volume
 * 
 * Usage in UMG:
 * - Create a widget blueprint based on this class
 * - Add UImage for icon (name it "ItemIcon")
 * - Add UTextBlock for name (name it "ItemNameText")
 * - Add UTextBlock for quantity (name it "QuantityText")
 * - Add UTextBlock for volume (name it "VolumeText")
 * - Set this blueprint as Entry Widget Class in ListView
 */
UCLASS()
class ECHOES_API UEchoesInventoryEntryWidget : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

public:
	// IUserObjectListEntry interface
	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;
	// End of IUserObjectListEntry interface

	// UUserWidget interface
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual void NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation*& OutOperation) override;
	// End of UUserWidget interface

	/**
	 * Set the item data to display
	 * Called automatically by ListView when item is set
	 * @param ItemObject - The inventory item object to display
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Inventory|UI")
	void SetItemData(UEchoesInventoryItemObject* ItemObject);

protected:
	/**
	 * Called when the entry is selected
	 * Override in derived classes for custom selection behavior
	 */
	virtual void OnEntrySelected();

	/**
	 * Called when the entry is deselected
	 * Override in derived classes for custom deselection behavior
	 */
	virtual void OnEntryDeselected();

	/**
	 * Called when drag is about to start
	 * Override in derived classes to customize drag behavior
	 * @return True to allow drag, false to cancel
	 */
	virtual bool HandleDragStarting(UEchoesInventoryItemObject* ItemObject, bool bIsShiftHeld);

	/**
	 * Called when context menu is requested
	 * Override in derived classes to customize available actions
	 * @param ItemObject - Item for which context menu is requested
	 * @param OutActions - Array of actions to display in menu
	 */
	virtual void OnContextMenuRequested(UEchoesInventoryItemObject* ItemObject, TArray<FContextMenuAction>& OutActions);

	/**
	 * Called when context menu action is executed
	 * Override in derived classes to handle custom actions
	 * @param ItemObject - Item the action was performed on
	 * @param ActionId - ID of the action executed
	 */
	virtual void OnContextMenuActionExecuted(UEchoesInventoryItemObject* ItemObject, const FString& ActionId);

	/**
	 * Update the visual display with item data
	 * Override this in derived classes to customize appearance
	 */
	virtual void UpdateDisplay(UEchoesInventoryItemObject* ItemObject);

	/**
	 * Called when icon is asynchronously loaded
	 * Override in derived classes to handle icon updates
	 */
	virtual void OnIconLoaded(UTexture2D* LoadedIcon);

	// Widget bindings (can be set in UMG)
	
	/** Image widget for item icon */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Echoes|Inventory|UI")
	UImage* ItemIcon;

	/** Text block for item name */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Echoes|Inventory|UI")
	UTextBlock* ItemNameText;

	/** Text block for quantity */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Echoes|Inventory|UI")
	UTextBlock* QuantityText;

	/** Text block for volume */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Echoes|Inventory|UI")
	UTextBlock* VolumeText;

	/** Optional: Placeholder icon shown while loading */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Echoes|Inventory|UI")
	UTexture2D* PlaceholderIcon;

	/** Context menu widget class */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Echoes|Inventory|UI")
	TSubclassOf<class UEchoesContextMenuWidget> ContextMenuClass;

	/** Quantity selector widget class */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Echoes|Inventory|UI")
	TSubclassOf<class UEchoesQuantitySelectorWidget> QuantitySelectorClass;

private:
	/** Current item object being displayed */
	UPROPERTY()
	UEchoesInventoryItemObject* CurrentItemObject;

	/**
	 * Start async icon loading for current item
	 */
	void StartAsyncIconLoad();

	/**
	 * Handle icon loaded callback
	 */
	UFUNCTION()
	void HandleIconLoaded(UTexture2D* LoadedIcon);

	/**
	 * Create visual widget for drag operation
	 * @return Widget to display during drag
	 */
	UUserWidget* CreateDragVisual();

	/**
	 * Create drag operation with specified quantity
	 * Helper method to avoid code duplication
	 */
	void CreateDragOperationWithQuantity(
		const FGeometry& InGeometry,
		const FPointerEvent& InMouseEvent,
		UDragDropOperation*& OutOperation,
		int64 Quantity);

	/**
	 * Show context menu for current item
	 */
	void ShowContextMenu();

	/**
	 * Get default actions for item based on type
	 * @param ItemObject - Item to get actions for
	 * @return Array of available actions
	 */
	TArray<FContextMenuAction> GetDefaultActionsForItem(UEchoesInventoryItemObject* ItemObject);

	/**
	 * Handle context menu action selected
	 * @param ActionId - ID of selected action
	 */
	UFUNCTION()
	void HandleContextMenuAction(const FString& ActionId);

	/**
	 * Handle quantity selected for drag operation
	 * @param SelectedQuantity - Quantity selected by user
	 */
	UFUNCTION()
	void OnDragQuantitySelected(int64 SelectedQuantity);

	/**
	 * Handle quantity selection cancelled for drag operation
	 */
	UFUNCTION()
	void OnDragQuantityCancelled();

	/**
	 * Handle quantity selected for jettison operation
	 * @param SelectedQuantity - Quantity selected by user
	 */
	UFUNCTION()
	void OnJettisonQuantitySelected(int64 SelectedQuantity);

	/**
	 * Handle quantity selection cancelled for jettison operation
	 */
	UFUNCTION()
	void OnJettisonQuantityCancelled();

	/** Stored data for pending drag operation */
	FPointerEvent PendingDragEvent;
	FGeometry PendingDragGeometry;
	bool bWaitingForDragQuantity;
};
