// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Core/Common/EchoesInventoryComponent.h"
#include "EchoesInventoryItemObject.generated.h"

/**
 * UEchoesInventoryItemObject
 * 
 * Data wrapper for FEchoesInventoryItem to be used with UListView
 * This UObject wraps the inventory item struct so it can be used with UMG ListView
 * 
 * Usage:
 * - Create instances for each item in inventory
 * - Add to ListView as items
 * - Entry widgets retrieve data via getter methods
 */
UCLASS(BlueprintType)
class ECHOES_API UEchoesInventoryItemObject : public UObject
{
	GENERATED_BODY()

public:
	/**
	 * Initialize the object with inventory item data
	 * @param InItemData - The inventory item data to wrap
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Inventory|UI")
	void InitializeWithData(const FEchoesInventoryItem& InItemData);

	/**
	 * Get the wrapped inventory item data
	 * @return The wrapped inventory item
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Inventory|UI")
	FEchoesInventoryItem GetItemData() const { return ItemData; }

	/**
	 * Get the item type name
	 * @return Item type name
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Inventory|UI")
	FString GetItemName() const { return ItemData.TypeName; }

	/**
	 * Get the item quantity
	 * @return Item quantity
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Inventory|UI")
	int64 GetQuantity() const { return ItemData.Quantity; }

	/**
	 * Get formatted volume string (e.g., "120.5 m³")
	 * @return Formatted volume string
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Inventory|UI")
	FString GetFormattedVolume() const;

	/**
	 * Get formatted total volume string (e.g., "1,205.0 m³")
	 * @return Formatted total volume string
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Inventory|UI")
	FString GetFormattedTotalVolume() const;

	/**
	 * Get the asset ID
	 * @return Asset GUID
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Inventory|UI")
	FGuid GetAssetId() const { return ItemData.AssetId; }

	/**
	 * Check if item is stackable
	 * @return True if stackable
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Inventory|UI")
	bool IsStackable() const { return ItemData.IsStackable; }

	/**
	 * Get the type ID
	 * @return Type ID
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Inventory|UI")
	int32 GetTypeId() const { return ItemData.TypeId; }

protected:
	/** The wrapped inventory item data */
	UPROPERTY()
	FEchoesInventoryItem ItemData;
};
