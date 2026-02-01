// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/DragDropOperation.h"
#include "EchoesInventoryComponent.h"
#include "EchoesInventoryDragDrop.generated.h"

/**
 * UEchoesInventoryDragDrop
 * 
 * Drag and drop operation for inventory items
 * Carries item data and source storage information
 * Provides visual feedback during drag
 * 
 * Features:
 * - Holds inventory item data
 * - Tracks source storage ID
 * - Supports partial quantity for stack splitting
 * - Visual feedback with item icon
 * 
 * Usage:
 * - Create when drag starts in inventory entry widget
 * - Set item data and source storage
 * - Set quantity (defaults to full stack)
 * - Receive in drop target (inventory widget)
 */
UCLASS()
class ECHOES_API UEchoesInventoryDragDrop : public UDragDropOperation
{
	GENERATED_BODY()

public:
	/**
	 * Initialize the drag operation with item data
	 * @param InItemData - The item being dragged
	 * @param InSourceStorageId - Storage ID where item originates
	 * @param InSourceActor - Actor containing the source inventory
	 * @param InQuantity - Quantity to move (0 = all)
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Inventory|DragDrop")
	void InitializeDragOperation(
		const FEchoesInventoryItem& InItemData,
		const FGuid& InSourceStorageId,
		AActor* InSourceActor,
		int64 InQuantity = 0);

	/**
	 * Get the item data being dragged
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Inventory|DragDrop")
	FEchoesInventoryItem GetItemData() const { return ItemData; }

	/**
	 * Get the source storage ID
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Inventory|DragDrop")
	FGuid GetSourceStorageId() const { return SourceStorageId; }

	/**
	 * Get the source actor
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Inventory|DragDrop")
	AActor* GetSourceActor() const { return SourceActor; }

	/**
	 * Get the quantity being moved
	 * @return Quantity to move (0 means all/full stack)
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Inventory|DragDrop")
	int64 GetQuantity() const { return Quantity; }

	/**
	 * Set the quantity being moved (for stack splitting)
	 * @param InQuantity - New quantity to move
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Inventory|DragDrop")
	void SetQuantity(int64 InQuantity);

	/**
	 * Check if this is a partial stack move
	 * @return True if quantity is less than total item quantity
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Inventory|DragDrop")
	bool IsPartialStack() const;

protected:
	/** The inventory item being dragged */
	UPROPERTY(BlueprintReadOnly, Category = "Echoes|Inventory|DragDrop")
	FEchoesInventoryItem ItemData;

	/** Storage ID where the item originates */
	UPROPERTY(BlueprintReadOnly, Category = "Echoes|Inventory|DragDrop")
	FGuid SourceStorageId;

	/** Actor containing the source inventory component */
	UPROPERTY(BlueprintReadOnly, Category = "Echoes|Inventory|DragDrop")
	AActor* SourceActor;

	/** Quantity being moved (0 = all) */
	UPROPERTY(BlueprintReadOnly, Category = "Echoes|Inventory|DragDrop")
	int64 Quantity;
};
