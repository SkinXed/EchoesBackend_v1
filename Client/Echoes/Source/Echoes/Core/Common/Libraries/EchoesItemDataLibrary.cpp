// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesItemDataLibrary.h"
#include "Engine/DataTable.h"

// Initialize static members
TMap<int32, FEchoesItemDefinitionRow> UEchoesItemDataLibrary::ItemDefinitionCache;
TMap<int32, FWeaponAttributesRow> UEchoesItemDataLibrary::WeaponAttributesCache;
UDataTable* UEchoesItemDataLibrary::ItemDefinitionsDataTable = nullptr;
UDataTable* UEchoesItemDataLibrary::WeaponAttributesDataTable = nullptr;
bool UEchoesItemDataLibrary::bIsInitialized = false;

void UEchoesItemDataLibrary::SetDataTableReferences(UDataTable* ItemDefinitionsTable, UDataTable* WeaponAttributesTable)
{
	ItemDefinitionsDataTable = ItemDefinitionsTable;
	WeaponAttributesDataTable = WeaponAttributesTable;
	bIsInitialized = (ItemDefinitionsTable != nullptr);

	// Clear cache when references change
	ClearCache();

	if (bIsInitialized)
	{
		UE_LOG(LogTemp, Log, TEXT("EchoesItemDataLibrary: Initialized with data tables"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("EchoesItemDataLibrary: ItemDefinitionsTable is null - library not fully initialized"));
	}
}

bool UEchoesItemDataLibrary::Common_GetItemDefinition(int32 TypeId, FEchoesItemDefinitionRow& OutItemDefinition)
{
	if (!EnsureInitialized())
	{
		return false;
	}

	return GetOrCacheItemDefinition(TypeId, OutItemDefinition);
}

bool UEchoesItemDataLibrary::Common_GetWeaponAttributes(int32 TypeId, FWeaponAttributesRow& OutWeaponAttributes)
{
	if (!EnsureInitialized())
	{
		return false;
	}

	return GetOrCacheWeaponAttributes(TypeId, OutWeaponAttributes);
}

FCompleteModuleData UEchoesItemDataLibrary::Common_GetCompleteModuleData(int32 TypeId)
{
	FCompleteModuleData Result;

	if (!EnsureInitialized())
	{
		return Result;
	}

	// Get base item definition
	Result.bItemFound = GetOrCacheItemDefinition(TypeId, Result.ItemDefinition);

	// If item found and it's a module, try to get weapon attributes
	if (Result.bItemFound && Result.ItemDefinition.Category == EEchoesItemCategory::Module)
	{
		Result.bWeaponAttributesFound = GetOrCacheWeaponAttributes(TypeId, Result.WeaponAttributes);
		Result.bIsCompleteModule = Result.bWeaponAttributesFound;
	}

	return Result;
}

bool UEchoesItemDataLibrary::Common_IsFittableModule(int32 TypeId)
{
	FEchoesItemDefinitionRow ItemDef;
	if (Common_GetItemDefinition(TypeId, ItemDef))
	{
		return ItemDef.FitSlot != EEchoesSlotType::None;
	}
	return false;
}

EEchoesSlotType UEchoesItemDataLibrary::Common_GetFitSlot(int32 TypeId)
{
	FEchoesItemDefinitionRow ItemDef;
	if (Common_GetItemDefinition(TypeId, ItemDef))
	{
		return ItemDef.FitSlot;
	}
	return EEchoesSlotType::None;
}

float UEchoesItemDataLibrary::Common_GetPowergridRequired(int32 TypeId)
{
	FEchoesItemDefinitionRow ItemDef;
	if (Common_GetItemDefinition(TypeId, ItemDef))
	{
		return ItemDef.PowergridRequired;
	}
	return 0.0f;
}

float UEchoesItemDataLibrary::Common_GetCPURequired(int32 TypeId)
{
	FEchoesItemDefinitionRow ItemDef;
	if (Common_GetItemDefinition(TypeId, ItemDef))
	{
		return ItemDef.CPURequired;
	}
	return 0.0f;
}

FText UEchoesItemDataLibrary::Common_GetItemName(int32 TypeId)
{
	FEchoesItemDefinitionRow ItemDef;
	if (Common_GetItemDefinition(TypeId, ItemDef))
	{
		return ItemDef.DisplayName;
	}
	return FText::FromString(TEXT("Unknown Item"));
}

UTexture2D* UEchoesItemDataLibrary::Common_GetItemIcon(int32 TypeId)
{
	FEchoesItemDefinitionRow ItemDef;
	if (Common_GetItemDefinition(TypeId, ItemDef))
	{
		// Resolve soft object pointer to actual texture
		if (!ItemDef.Icon.IsNull())
		{
			return ItemDef.Icon.LoadSynchronous();
		}
	}
	return nullptr;
}

bool UEchoesItemDataLibrary::Common_ItemExists(int32 TypeId)
{
	FEchoesItemDefinitionRow ItemDef;
	return Common_GetItemDefinition(TypeId, ItemDef);
}

void UEchoesItemDataLibrary::ClearCache()
{
	ItemDefinitionCache.Empty();
	WeaponAttributesCache.Empty();
	UE_LOG(LogTemp, Log, TEXT("EchoesItemDataLibrary: Cache cleared"));
}

bool UEchoesItemDataLibrary::EnsureInitialized()
{
	if (!bIsInitialized || ItemDefinitionsDataTable == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("EchoesItemDataLibrary: Library not initialized! Call SetDataTableReferences first."));
		return false;
	}
	return true;
}

bool UEchoesItemDataLibrary::GetOrCacheItemDefinition(int32 TypeId, FEchoesItemDefinitionRow& OutDefinition)
{
	// Check cache first
	if (FEchoesItemDefinitionRow* CachedRow = ItemDefinitionCache.Find(TypeId))
	{
		OutDefinition = *CachedRow;
		return true;
	}

	// Not in cache, query data table
	if (ItemDefinitionsDataTable)
	{
		// Convert TypeId to FName for row lookup
		FName RowName = FName(*FString::FromInt(TypeId));
		
		// Get row from data table
		FEchoesItemDefinitionRow* RowData = ItemDefinitionsDataTable->FindRow<FEchoesItemDefinitionRow>(RowName, TEXT("GetOrCacheItemDefinition"));
		
		if (RowData)
		{
			// Cache the result
			ItemDefinitionCache.Add(TypeId, *RowData);
			OutDefinition = *RowData;
			return true;
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("EchoesItemDataLibrary: Item definition not found for TypeId: %d"), TypeId);
		}
	}

	return false;
}

bool UEchoesItemDataLibrary::GetOrCacheWeaponAttributes(int32 TypeId, FWeaponAttributesRow& OutAttributes)
{
	// Check cache first
	if (FWeaponAttributesRow* CachedRow = WeaponAttributesCache.Find(TypeId))
	{
		OutAttributes = *CachedRow;
		return true;
	}

	// Not in cache, query data table (if available)
	if (WeaponAttributesDataTable)
	{
		// Convert TypeId to FName for row lookup
		FName RowName = FName(*FString::FromInt(TypeId));
		
		// Get row from data table
		FWeaponAttributesRow* RowData = WeaponAttributesDataTable->FindRow<FWeaponAttributesRow>(RowName, TEXT("GetOrCacheWeaponAttributes"));
		
		if (RowData)
		{
			// Cache the result
			WeaponAttributesCache.Add(TypeId, *RowData);
			OutAttributes = *RowData;
			return true;
		}
		else
		{
			// Not an error - not all items have weapon attributes (ore, minerals, etc.)
			UE_LOG(LogTemp, Verbose, TEXT("EchoesItemDataLibrary: Weapon attributes not found for TypeId: %d (this is normal for non-weapon items)"), TypeId);
		}
	}

	return false;
}
