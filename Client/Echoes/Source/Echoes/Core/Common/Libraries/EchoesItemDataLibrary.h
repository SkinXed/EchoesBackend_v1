// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/DataTable.h"
#include "Core/Common/Types/EchoesItemDefinitions.h"
#include "EchoesItemDataLibrary.generated.h"

/**
 * FCompleteModuleData
 * 
 * Combined data structure containing both base item definition
 * and weapon/module-specific attributes
 * 
 * Used by Common_GetCompleteModuleData to return all relevant
 * data for a module in a single call
 */
USTRUCT(BlueprintType)
struct ECHOES_API FCompleteModuleData
{
	GENERATED_BODY()

	/** Base item definition (name, icon, volume, etc.) */
	UPROPERTY(BlueprintReadWrite, Category = "Module Data")
	FEchoesItemDefinitionRow ItemDefinition;

	/** Weapon/module specific attributes (damage, range, etc.) */
	UPROPERTY(BlueprintReadWrite, Category = "Module Data")
	FWeaponAttributesRow WeaponAttributes;

	/** Whether the item was found in the definitions table */
	UPROPERTY(BlueprintReadWrite, Category = "Module Data")
	bool bItemFound = false;

	/** Whether weapon attributes were found (only for modules) */
	UPROPERTY(BlueprintReadWrite, Category = "Module Data")
	bool bWeaponAttributesFound = false;

	/** Whether this is a valid module with both definitions */
	UPROPERTY(BlueprintReadWrite, Category = "Module Data")
	bool bIsCompleteModule = false;

	FCompleteModuleData()
		: bItemFound(false)
		, bWeaponAttributesFound(false)
		, bIsCompleteModule(false)
	{
	}
};

/**
 * UEchoesItemDataLibrary
 * 
 * Blueprint Function Library for accessing item and module data
 * Provides Common_ helper functions to query data tables and combine information
 * 
 * Naming Convention: All functions use Common_ prefix to indicate
 * they are pure calculation/data access functions
 * 
 * Usage:
 * 1. Configure data table references in Project Settings or Game Instance
 * 2. Call SetDataTableReferences() to initialize the library
 * 3. Use Common_GetItemDefinition() for base item data
 * 4. Use Common_GetWeaponAttributes() for weapon stats
 * 5. Use Common_GetCompleteModuleData() for combined data
 */
UCLASS()
class ECHOES_API UEchoesItemDataLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/**
	 * Initialize data table references for the library
	 * Must be called before using any other functions
	 * 
	 * @param ItemDefinitionsTable - Data table containing FEchoesItemDefinitionRow entries
	 * @param WeaponAttributesTable - Data table containing FWeaponAttributesRow entries
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Item Data")
	static void SetDataTableReferences(UDataTable* ItemDefinitionsTable, UDataTable* WeaponAttributesTable);

	/**
	 * Get base item definition by TypeId
	 * Returns item name, icon, volume, mass, category, etc.
	 * 
	 * @param TypeId - Database item type ID
	 * @param OutItemDefinition - Output structure with item data
	 * @return True if item was found, false otherwise
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Item Data", meta = (CompactNodeTitle = "Get Item Definition"))
	static bool Common_GetItemDefinition(int32 TypeId, FEchoesItemDefinitionRow& OutItemDefinition);

	/**
	 * Get weapon/module attributes by TypeId
	 * Returns damage, range, tracking, capacitor cost, etc.
	 * Only populated for modules/weapons
	 * 
	 * @param TypeId - Database item type ID
	 * @param OutWeaponAttributes - Output structure with weapon stats
	 * @return True if weapon attributes were found, false otherwise
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Item Data", meta = (CompactNodeTitle = "Get Weapon Attributes"))
	static bool Common_GetWeaponAttributes(int32 TypeId, FWeaponAttributesRow& OutWeaponAttributes);

	/**
	 * Get complete module data (base + weapon attributes)
	 * Combines both data tables into a single result
	 * 
	 * First looks up base item data (icon, name, fit slot)
	 * Then looks up weapon attributes if item is a module
	 * 
	 * @param TypeId - Database item type ID
	 * @return Complete module data structure with validity flags
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Item Data", meta = (CompactNodeTitle = "Get Complete Module Data"))
	static FCompleteModuleData Common_GetCompleteModuleData(int32 TypeId);

	/**
	 * Check if an item is a fittable module
	 * Returns true if item has a FitSlot other than None
	 * 
	 * @param TypeId - Database item type ID
	 * @return True if item can be fitted to a ship
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Item Data", meta = (CompactNodeTitle = "Is Fittable Module"))
	static bool Common_IsFittableModule(int32 TypeId);

	/**
	 * Get the fit slot type for an item
	 * Returns None if item is not fittable
	 * 
	 * @param TypeId - Database item type ID
	 * @return Slot type (High, Mid, Low, Rig, Subsystem, or None)
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Item Data", meta = (CompactNodeTitle = "Get Fit Slot"))
	static EEchoesSlotType Common_GetFitSlot(int32 TypeId);

	/**
	 * Get powergrid requirement for a module
	 * Returns 0 if not a module or module not found
	 * 
	 * @param TypeId - Database item type ID
	 * @return Powergrid requirement in MW
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Item Data", meta = (CompactNodeTitle = "Get PG Required"))
	static float Common_GetPowergridRequired(int32 TypeId);

	/**
	 * Get CPU requirement for a module
	 * Returns 0 if not a module or module not found
	 * 
	 * @param TypeId - Database item type ID
	 * @return CPU requirement in tf
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Item Data", meta = (CompactNodeTitle = "Get CPU Required"))
	static float Common_GetCPURequired(int32 TypeId);

	/**
	 * Get item display name
	 * Returns "Unknown Item" if not found
	 * 
	 * @param TypeId - Database item type ID
	 * @return Localized display name
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Item Data", meta = (CompactNodeTitle = "Get Item Name"))
	static FText Common_GetItemName(int32 TypeId);

	/**
	 * Get item icon texture
	 * Returns nullptr if not found or icon not set
	 * 
	 * @param TypeId - Database item type ID
	 * @return Icon texture (soft object ptr resolved)
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Item Data", meta = (CompactNodeTitle = "Get Item Icon"))
	static UTexture2D* Common_GetItemIcon(int32 TypeId);

	/**
	 * Check if item exists in database
	 * 
	 * @param TypeId - Database item type ID
	 * @return True if item definition exists
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Item Data", meta = (CompactNodeTitle = "Item Exists"))
	static bool Common_ItemExists(int32 TypeId);

	/**
	 * Clear cached data
	 * Call this when data tables are reloaded or changed
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Item Data")
	static void ClearCache();

private:
	/** Cache for item definitions (TypeId -> Row data) */
	static TMap<int32, FEchoesItemDefinitionRow> ItemDefinitionCache;

	/** Cache for weapon attributes (TypeId -> Weapon data) */
	static TMap<int32, FWeaponAttributesRow> WeaponAttributesCache;

	/** Reference to item definitions data table */
	static UDataTable* ItemDefinitionsDataTable;

	/** Reference to weapon attributes data table */
	static UDataTable* WeaponAttributesDataTable;

	/** Whether the library has been initialized */
	static bool bIsInitialized;

	/**
	 * Internal helper to ensure data tables are loaded
	 * Logs error if not initialized
	 */
	static bool EnsureInitialized();

	/**
	 * Internal helper to get or cache item definition
	 */
	static bool GetOrCacheItemDefinition(int32 TypeId, FEchoesItemDefinitionRow& OutDefinition);

	/**
	 * Internal helper to get or cache weapon attributes
	 */
	static bool GetOrCacheWeaponAttributes(int32 TypeId, FWeaponAttributesRow& OutAttributes);
};
