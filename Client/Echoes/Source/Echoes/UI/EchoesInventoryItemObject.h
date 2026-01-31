// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Core/Common/EchoesInventoryComponent.h"
#include "Core/Common/EchoesItemDefinitions.h"
#include "EchoesInventoryItemObject.generated.h"

// Forward declarations
class UEchoesInventorySubsystem;
class UTexture2D;

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

	/**
	 * Get the item definition from subsystem
	 * Returns visual assets and metadata
	 * @return Item definition, or nullptr if not found
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Inventory|UI")
	const FEchoesItemDefinitionRow* GetItemDefinition() const { return CachedDefinition; }

	/**
	 * Get the display name from item definition (localized)
	 * Falls back to TypeName if definition not found
	 * @return Display name
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Inventory|UI")
	FText GetDisplayName() const;

	/**
	 * Get the description from item definition (localized)
	 * @return Description text
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Inventory|UI")
	FText GetDescription() const;

	/**
	 * Get calculated total volume (Quantity * UnitVolume from definition)
	 * Uses definition's UnitVolume if available, otherwise uses ItemData.Volume
	 * @return Total volume in m³
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Inventory|UI")
	float GetCalculatedTotalVolume() const;

	/**
	 * Get unit volume from item definition
	 * @return Volume per unit in m³
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Inventory|UI")
	float GetUnitVolume() const;

	/**
	 * Get total mass (Quantity * UnitMass from definition)
	 * @return Total mass in kg
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Inventory|UI")
	float GetTotalMass() const;

	/**
	 * Check if item definition is loaded
	 * @return True if definition was found and cached
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Inventory|UI")
	bool HasDefinition() const { return CachedDefinition != nullptr; }

protected:
	/** The wrapped inventory item data */
	UPROPERTY()
	FEchoesInventoryItem ItemData;

	/** Cached item definition from subsystem */
	const FEchoesItemDefinitionRow* CachedDefinition;

	/** Reference to inventory subsystem for fetching definitions */
	UPROPERTY()
	UEchoesInventorySubsystem* InventorySubsystem;

	/**
	 * Fetch item definition from subsystem
	 * Called during initialization
	 */
	void FetchItemDefinition();
};
