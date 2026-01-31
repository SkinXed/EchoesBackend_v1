// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
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
	 * Override in Blueprint for custom selection behavior
	 */
	UFUNCTION(BlueprintImplementableEvent, Category = "Echoes|Inventory|UI")
	void OnEntrySelected();

	/**
	 * Called when the entry is deselected
	 * Override in Blueprint for custom deselection behavior
	 */
	UFUNCTION(BlueprintImplementableEvent, Category = "Echoes|Inventory|UI")
	void OnEntryDeselected();

	/**
	 * Blueprint event called when drag is about to start
	 * Override in Blueprint to customize drag behavior
	 * @return True to allow drag, false to cancel
	 */
	UFUNCTION(BlueprintImplementableEvent, Category = "Echoes|Inventory|UI")
	bool OnDragStarting(UEchoesInventoryItemObject* ItemObject, bool bIsShiftHeld);

	/**
	 * Blueprint event called when drag is cancelled
	 * Override in Blueprint for custom behavior
	 */
	UFUNCTION(BlueprintImplementableEvent, Category = "Echoes|Inventory|UI")
	void OnDragCancelled();

	/**
	 * Update the visual display with item data
	 * Override this in Blueprint to customize appearance
	 */
	UFUNCTION(BlueprintNativeEvent, Category = "Echoes|Inventory|UI")
	void UpdateDisplay(UEchoesInventoryItemObject* ItemObject);

	/**
	 * Called when icon is asynchronously loaded
	 * Override in Blueprint to handle icon updates
	 */
	UFUNCTION(BlueprintImplementableEvent, Category = "Echoes|Inventory|UI")
	void OnIconLoaded(UTexture2D* LoadedIcon);

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
};
