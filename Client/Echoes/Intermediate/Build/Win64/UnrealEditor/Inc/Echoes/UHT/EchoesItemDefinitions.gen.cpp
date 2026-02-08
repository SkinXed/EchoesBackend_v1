// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EchoesItemDefinitions.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesItemDefinitions() {}

// ********** Begin Cross Module References ********************************************************
ECHOES_API UEnum* Z_Construct_UEnum_Echoes_EEchoesItemCategory();
ECHOES_API UEnum* Z_Construct_UEnum_Echoes_EEchoesSlotType();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FEchoesItemDefinitionRow();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FWeaponAttributesRow();
ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTableRowBase();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EEchoesSlotType ***********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EEchoesSlotType;
static UEnum* EEchoesSlotType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EEchoesSlotType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EEchoesSlotType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Echoes_EEchoesSlotType, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("EEchoesSlotType"));
	}
	return Z_Registration_Info_UEnum_EEchoesSlotType.OuterSingleton;
}
template<> ECHOES_API UEnum* StaticEnum<EEchoesSlotType>()
{
	return EEchoesSlotType_StaticEnum();
}
struct Z_Construct_UEnum_Echoes_EEchoesSlotType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Forward declaration of ESlotType from ShipFittingInterface\n * This enum defines fitting slot types: High, Mid, Low, Rig, Subsystem\n */" },
#endif
		{ "High.Comment", "/** High slots - Weapons, offensive modules */" },
		{ "High.DisplayName", "High Slot" },
		{ "High.Name", "EEchoesSlotType::High" },
		{ "High.ToolTip", "High slots - Weapons, offensive modules" },
		{ "Low.Comment", "/** Low slots - Armor, damage mods, engine upgrades */" },
		{ "Low.DisplayName", "Low Slot" },
		{ "Low.Name", "EEchoesSlotType::Low" },
		{ "Low.ToolTip", "Low slots - Armor, damage mods, engine upgrades" },
		{ "Mid.Comment", "/** Medium slots - Shields, propulsion, electronic warfare */" },
		{ "Mid.DisplayName", "Mid Slot" },
		{ "Mid.Name", "EEchoesSlotType::Mid" },
		{ "Mid.ToolTip", "Medium slots - Shields, propulsion, electronic warfare" },
		{ "ModuleRelativePath", "Core/Common/Types/EchoesItemDefinitions.h" },
		{ "None.Comment", "/** Not fittable / Invalid */" },
		{ "None.DisplayName", "None" },
		{ "None.Name", "EEchoesSlotType::None" },
		{ "None.ToolTip", "Not fittable / Invalid" },
		{ "Rig.Comment", "/** Rig slots - Permanent ship modifications */" },
		{ "Rig.DisplayName", "Rig Slot" },
		{ "Rig.Name", "EEchoesSlotType::Rig" },
		{ "Rig.ToolTip", "Rig slots - Permanent ship modifications" },
		{ "Subsystem.Comment", "/** Subsystem slots - T3 ship subsystems */" },
		{ "Subsystem.DisplayName", "Subsystem Slot" },
		{ "Subsystem.Name", "EEchoesSlotType::Subsystem" },
		{ "Subsystem.ToolTip", "Subsystem slots - T3 ship subsystems" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Forward declaration of ESlotType from ShipFittingInterface\nThis enum defines fitting slot types: High, Mid, Low, Rig, Subsystem" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EEchoesSlotType::High", (int64)EEchoesSlotType::High },
		{ "EEchoesSlotType::Mid", (int64)EEchoesSlotType::Mid },
		{ "EEchoesSlotType::Low", (int64)EEchoesSlotType::Low },
		{ "EEchoesSlotType::Rig", (int64)EEchoesSlotType::Rig },
		{ "EEchoesSlotType::Subsystem", (int64)EEchoesSlotType::Subsystem },
		{ "EEchoesSlotType::None", (int64)EEchoesSlotType::None },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Echoes_EEchoesSlotType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	"EEchoesSlotType",
	"EEchoesSlotType",
	Z_Construct_UEnum_Echoes_EEchoesSlotType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_Echoes_EEchoesSlotType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_Echoes_EEchoesSlotType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_Echoes_EEchoesSlotType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_Echoes_EEchoesSlotType()
{
	if (!Z_Registration_Info_UEnum_EEchoesSlotType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EEchoesSlotType.InnerSingleton, Z_Construct_UEnum_Echoes_EEchoesSlotType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EEchoesSlotType.InnerSingleton;
}
// ********** End Enum EEchoesSlotType *************************************************************

// ********** Begin Enum EEchoesItemCategory *******************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EEchoesItemCategory;
static UEnum* EEchoesItemCategory_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EEchoesItemCategory.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EEchoesItemCategory.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Echoes_EEchoesItemCategory, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("EEchoesItemCategory"));
	}
	return Z_Registration_Info_UEnum_EEchoesItemCategory.OuterSingleton;
}
template<> ECHOES_API UEnum* StaticEnum<EEchoesItemCategory>()
{
	return EEchoesItemCategory_StaticEnum();
}
struct Z_Construct_UEnum_Echoes_EEchoesItemCategory_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Ammo.DisplayName", "Ammunition" },
		{ "Ammo.Name", "EEchoesItemCategory::Ammo" },
		{ "Blueprint.DisplayName", "Blueprint" },
		{ "Blueprint.Name", "EEchoesItemCategory::Blueprint" },
		{ "BlueprintType", "true" },
		{ "Charge.DisplayName", "Charge" },
		{ "Charge.Name", "EEchoesItemCategory::Charge" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Item category enumeration\n * Categorizes items for filtering and organization\n */" },
#endif
		{ "Commodity.DisplayName", "Commodity" },
		{ "Commodity.Name", "EEchoesItemCategory::Commodity" },
		{ "Component.DisplayName", "Component" },
		{ "Component.Name", "EEchoesItemCategory::Component" },
		{ "Drone.DisplayName", "Drone" },
		{ "Drone.Name", "EEchoesItemCategory::Drone" },
		{ "Fighter.DisplayName", "Fighter" },
		{ "Fighter.Name", "EEchoesItemCategory::Fighter" },
		{ "Implant.DisplayName", "Implant" },
		{ "Implant.Name", "EEchoesItemCategory::Implant" },
		{ "MAX.Hidden", "" },
		{ "MAX.Name", "EEchoesItemCategory::MAX" },
		{ "Mineral.DisplayName", "Mineral" },
		{ "Mineral.Name", "EEchoesItemCategory::Mineral" },
		{ "Module.DisplayName", "Module" },
		{ "Module.Name", "EEchoesItemCategory::Module" },
		{ "ModuleRelativePath", "Core/Common/Types/EchoesItemDefinitions.h" },
		{ "None.DisplayName", "None" },
		{ "None.Name", "EEchoesItemCategory::None" },
		{ "Ore.DisplayName", "Ore" },
		{ "Ore.Name", "EEchoesItemCategory::Ore" },
		{ "Rig.DisplayName", "Rig" },
		{ "Rig.Name", "EEchoesItemCategory::Rig" },
		{ "Ship.DisplayName", "Ship" },
		{ "Ship.Name", "EEchoesItemCategory::Ship" },
		{ "Skill.DisplayName", "Skill" },
		{ "Skill.Name", "EEchoesItemCategory::Skill" },
		{ "Structure.DisplayName", "Structure" },
		{ "Structure.Name", "EEchoesItemCategory::Structure" },
		{ "Subsystem.DisplayName", "Subsystem" },
		{ "Subsystem.Name", "EEchoesItemCategory::Subsystem" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Item category enumeration\nCategorizes items for filtering and organization" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EEchoesItemCategory::None", (int64)EEchoesItemCategory::None },
		{ "EEchoesItemCategory::Ore", (int64)EEchoesItemCategory::Ore },
		{ "EEchoesItemCategory::Mineral", (int64)EEchoesItemCategory::Mineral },
		{ "EEchoesItemCategory::Module", (int64)EEchoesItemCategory::Module },
		{ "EEchoesItemCategory::Ammo", (int64)EEchoesItemCategory::Ammo },
		{ "EEchoesItemCategory::Ship", (int64)EEchoesItemCategory::Ship },
		{ "EEchoesItemCategory::Blueprint", (int64)EEchoesItemCategory::Blueprint },
		{ "EEchoesItemCategory::Component", (int64)EEchoesItemCategory::Component },
		{ "EEchoesItemCategory::Commodity", (int64)EEchoesItemCategory::Commodity },
		{ "EEchoesItemCategory::Implant", (int64)EEchoesItemCategory::Implant },
		{ "EEchoesItemCategory::Skill", (int64)EEchoesItemCategory::Skill },
		{ "EEchoesItemCategory::Charge", (int64)EEchoesItemCategory::Charge },
		{ "EEchoesItemCategory::Drone", (int64)EEchoesItemCategory::Drone },
		{ "EEchoesItemCategory::Fighter", (int64)EEchoesItemCategory::Fighter },
		{ "EEchoesItemCategory::Structure", (int64)EEchoesItemCategory::Structure },
		{ "EEchoesItemCategory::Subsystem", (int64)EEchoesItemCategory::Subsystem },
		{ "EEchoesItemCategory::Rig", (int64)EEchoesItemCategory::Rig },
		{ "EEchoesItemCategory::MAX", (int64)EEchoesItemCategory::MAX },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Echoes_EEchoesItemCategory_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	"EEchoesItemCategory",
	"EEchoesItemCategory",
	Z_Construct_UEnum_Echoes_EEchoesItemCategory_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_Echoes_EEchoesItemCategory_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_Echoes_EEchoesItemCategory_Statics::Enum_MetaDataParams), Z_Construct_UEnum_Echoes_EEchoesItemCategory_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_Echoes_EEchoesItemCategory()
{
	if (!Z_Registration_Info_UEnum_EEchoesItemCategory.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EEchoesItemCategory.InnerSingleton, Z_Construct_UEnum_Echoes_EEchoesItemCategory_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EEchoesItemCategory.InnerSingleton;
}
// ********** End Enum EEchoesItemCategory *********************************************************

// ********** Begin ScriptStruct FEchoesItemDefinitionRow ******************************************
static_assert(std::is_polymorphic<FEchoesItemDefinitionRow>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FEchoesItemDefinitionRow cannot be polymorphic unless super FTableRowBase is polymorphic");
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FEchoesItemDefinitionRow;
class UScriptStruct* FEchoesItemDefinitionRow::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FEchoesItemDefinitionRow.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FEchoesItemDefinitionRow.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FEchoesItemDefinitionRow, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("EchoesItemDefinitionRow"));
	}
	return Z_Registration_Info_UScriptStruct_FEchoesItemDefinitionRow.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * FEchoesItemDefinitionRow\n * \n * Data table row structure for item definitions\n * Maps database item IDs to visual assets and metadata\n * \n * Usage:\n * - Create Data Table asset in Unreal Editor based on this struct\n * - Row names should match database TypeId (as string)\n * - Fill in visual assets (icons, meshes) and metadata\n * - Reference table in UEchoesInventorySubsystem\n * \n * Example Data Table Setup:\n * Row Name: \"34\" (Tritanium TypeId)\n * DisplayName: \"Tritanium\"\n * Description: \"The most common ore in space...\"\n * Icon: T_Icon_Tritanium\n * WorldMesh: SM_Ore_Tritanium\n * UnitVolume: 0.01\n * UnitMass: 0.01\n * Category: Ore\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesItemDefinitions.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "FEchoesItemDefinitionRow\n\nData table row structure for item definitions\nMaps database item IDs to visual assets and metadata\n\nUsage:\n- Create Data Table asset in Unreal Editor based on this struct\n- Row names should match database TypeId (as string)\n- Fill in visual assets (icons, meshes) and metadata\n- Reference table in UEchoesInventorySubsystem\n\nExample Data Table Setup:\nRow Name: \"34\" (Tritanium TypeId)\nDisplayName: \"Tritanium\"\nDescription: \"The most common ore in space...\"\nIcon: T_Icon_Tritanium\nWorldMesh: SM_Ore_Tritanium\nUnitVolume: 0.01\nUnitMass: 0.01\nCategory: Ore" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DisplayName_MetaData[] = {
		{ "Category", "Item Definition" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Localized display name for the item\n\x09 * Supports localization for different languages\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesItemDefinitions.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Localized display name for the item\nSupports localization for different languages" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[] = {
		{ "Category", "Item Definition" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Localized description of the item\n\x09 * Displayed in tooltips and detail panels\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesItemDefinitions.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Localized description of the item\nDisplayed in tooltips and detail panels" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Icon_MetaData[] = {
		{ "Category", "Item Definition|Visual" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Icon texture for UI display (ListView, tooltips, etc.)\n\x09 * Soft reference for async loading to prevent freezes\n\x09 * Recommended size: 64x64 or 128x128\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesItemDefinitions.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Icon texture for UI display (ListView, tooltips, etc.)\nSoft reference for async loading to prevent freezes\nRecommended size: 64x64 or 128x128" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldMesh_MetaData[] = {
		{ "Category", "Item Definition|Visual" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * 3D mesh for world representation\n\x09 * Used when item is ejected into space or displayed in 3D\n\x09 * Soft reference for streaming\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesItemDefinitions.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "3D mesh for world representation\nUsed when item is ejected into space or displayed in 3D\nSoft reference for streaming" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UnitVolume_MetaData[] = {
		{ "Category", "Item Definition|Physics" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Volume of a single unit (in cubic meters)\n\x09 * Used for cargo capacity calculations\n\x09 * TotalVolume = Quantity * UnitVolume\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesItemDefinitions.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Volume of a single unit (in cubic meters)\nUsed for cargo capacity calculations\nTotalVolume = Quantity * UnitVolume" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UnitMass_MetaData[] = {
		{ "Category", "Item Definition|Physics" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Mass of a single unit (in kilograms)\n\x09 * Used for physics and ship mass calculations\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesItemDefinitions.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Mass of a single unit (in kilograms)\nUsed for physics and ship mass calculations" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Category_MetaData[] = {
		{ "Category", "Item Definition" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Item category for organization and filtering\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesItemDefinitions.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Item category for organization and filtering" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MarketGroupId_MetaData[] = {
		{ "Category", "Item Definition|Market" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Optional: Market group ID for market categorization\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesItemDefinitions.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional: Market group ID for market categorization" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TechLevel_MetaData[] = {
		{ "Category", "Item Definition|Meta" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Optional: Tech level of the item (0-5, where 5 is highest tech)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesItemDefinitions.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional: Tech level of the item (0-5, where 5 is highest tech)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MetaLevel_MetaData[] = {
		{ "Category", "Item Definition|Meta" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Optional: Meta level (0 = regular, 1+ = special variants)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesItemDefinitions.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional: Meta level (0 = regular, 1+ = special variants)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsStackable_MetaData[] = {
		{ "Category", "Item Definition" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Whether this item can be stacked in inventory\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesItemDefinitions.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether this item can be stacked in inventory" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxStackSize_MetaData[] = {
		{ "Category", "Item Definition" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Maximum stack size (0 = unlimited)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesItemDefinitions.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum stack size (0 = unlimited)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FitSlot_MetaData[] = {
		{ "Category", "Item Definition|Fitting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Fitting slot type for modules/equipment\n\x09 * Determines which slot on a ship this module can be fitted to\n\x09 * None = Not a fittable module (ore, minerals, etc.)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesItemDefinitions.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fitting slot type for modules/equipment\nDetermines which slot on a ship this module can be fitted to\nNone = Not a fittable module (ore, minerals, etc.)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PowergridRequired_MetaData[] = {
		{ "Category", "Item Definition|Fitting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Powergrid requirement for fitting this module\n\x09 * Only applicable to modules (Category == Module)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesItemDefinitions.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Powergrid requirement for fitting this module\nOnly applicable to modules (Category == Module)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CPURequired_MetaData[] = {
		{ "Category", "Item Definition|Fitting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * CPU requirement for fitting this module\n\x09 * Only applicable to modules (Category == Module)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesItemDefinitions.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "CPU requirement for fitting this module\nOnly applicable to modules (Category == Module)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FTextPropertyParams NewProp_DisplayName;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Description;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_Icon;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_WorldMesh;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_UnitVolume;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_UnitMass;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Category_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Category;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MarketGroupId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_TechLevel;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MetaLevel;
	static void NewProp_bIsStackable_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsStackable;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxStackSize;
	static const UECodeGen_Private::FBytePropertyParams NewProp_FitSlot_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_FitSlot;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PowergridRequired;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CPURequired;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FEchoesItemDefinitionRow>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::NewProp_DisplayName = { "DisplayName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesItemDefinitionRow, DisplayName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DisplayName_MetaData), NewProp_DisplayName_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesItemDefinitionRow, Description), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Description_MetaData), NewProp_Description_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::NewProp_Icon = { "Icon", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesItemDefinitionRow, Icon), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Icon_MetaData), NewProp_Icon_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::NewProp_WorldMesh = { "WorldMesh", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesItemDefinitionRow, WorldMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldMesh_MetaData), NewProp_WorldMesh_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::NewProp_UnitVolume = { "UnitVolume", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesItemDefinitionRow, UnitVolume), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UnitVolume_MetaData), NewProp_UnitVolume_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::NewProp_UnitMass = { "UnitMass", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesItemDefinitionRow, UnitMass), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UnitMass_MetaData), NewProp_UnitMass_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::NewProp_Category_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::NewProp_Category = { "Category", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesItemDefinitionRow, Category), Z_Construct_UEnum_Echoes_EEchoesItemCategory, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Category_MetaData), NewProp_Category_MetaData) }; // 3886991834
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::NewProp_MarketGroupId = { "MarketGroupId", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesItemDefinitionRow, MarketGroupId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MarketGroupId_MetaData), NewProp_MarketGroupId_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::NewProp_TechLevel = { "TechLevel", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesItemDefinitionRow, TechLevel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TechLevel_MetaData), NewProp_TechLevel_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::NewProp_MetaLevel = { "MetaLevel", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesItemDefinitionRow, MetaLevel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MetaLevel_MetaData), NewProp_MetaLevel_MetaData) };
void Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::NewProp_bIsStackable_SetBit(void* Obj)
{
	((FEchoesItemDefinitionRow*)Obj)->bIsStackable = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::NewProp_bIsStackable = { "bIsStackable", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FEchoesItemDefinitionRow), &Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::NewProp_bIsStackable_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsStackable_MetaData), NewProp_bIsStackable_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::NewProp_MaxStackSize = { "MaxStackSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesItemDefinitionRow, MaxStackSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxStackSize_MetaData), NewProp_MaxStackSize_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::NewProp_FitSlot_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::NewProp_FitSlot = { "FitSlot", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesItemDefinitionRow, FitSlot), Z_Construct_UEnum_Echoes_EEchoesSlotType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FitSlot_MetaData), NewProp_FitSlot_MetaData) }; // 3231457299
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::NewProp_PowergridRequired = { "PowergridRequired", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesItemDefinitionRow, PowergridRequired), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PowergridRequired_MetaData), NewProp_PowergridRequired_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::NewProp_CPURequired = { "CPURequired", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesItemDefinitionRow, CPURequired), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CPURequired_MetaData), NewProp_CPURequired_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::NewProp_DisplayName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::NewProp_Description,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::NewProp_Icon,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::NewProp_WorldMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::NewProp_UnitVolume,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::NewProp_UnitMass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::NewProp_Category_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::NewProp_Category,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::NewProp_MarketGroupId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::NewProp_TechLevel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::NewProp_MetaLevel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::NewProp_bIsStackable,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::NewProp_MaxStackSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::NewProp_FitSlot_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::NewProp_FitSlot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::NewProp_PowergridRequired,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::NewProp_CPURequired,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	Z_Construct_UScriptStruct_FTableRowBase,
	&NewStructOps,
	"EchoesItemDefinitionRow",
	Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::PropPointers),
	sizeof(FEchoesItemDefinitionRow),
	alignof(FEchoesItemDefinitionRow),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FEchoesItemDefinitionRow()
{
	if (!Z_Registration_Info_UScriptStruct_FEchoesItemDefinitionRow.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FEchoesItemDefinitionRow.InnerSingleton, Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FEchoesItemDefinitionRow.InnerSingleton;
}
// ********** End ScriptStruct FEchoesItemDefinitionRow ********************************************

// ********** Begin ScriptStruct FWeaponAttributesRow **********************************************
static_assert(std::is_polymorphic<FWeaponAttributesRow>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FWeaponAttributesRow cannot be polymorphic unless super FTableRowBase is polymorphic");
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FWeaponAttributesRow;
class UScriptStruct* FWeaponAttributesRow::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FWeaponAttributesRow.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FWeaponAttributesRow.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FWeaponAttributesRow, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("WeaponAttributesRow"));
	}
	return Z_Registration_Info_UScriptStruct_FWeaponAttributesRow.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FWeaponAttributesRow_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * FWeaponAttributesRow\n * \n * Weapon-specific attributes data table row\n * Separated from main item table to avoid bloating with module-specific data\n * \n * Usage:\n * - Create separate Data Table for weapon/module attributes\n * - Row names should match TypeId (same as FEchoesItemDefinitionRow)\n * - Only populate rows for modules/weapons\n * - Use Common_GetWeaponAttributes() helper to fetch this data\n * \n * Example Data Table Setup:\n * Row Name: \"2048\" (Light Neutron Blaster TypeId)\n * Damage: 55.0\n * OptimalRange: 2000.0 (2km)\n * Falloff: 8000.0 (8km)\n * TrackingSpeed: 0.4\n * ActivationCost: 5.0 (GJ)\n * AmmoTypeId: 256 (Antimatter Charge S)\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesItemDefinitions.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "FWeaponAttributesRow\n\nWeapon-specific attributes data table row\nSeparated from main item table to avoid bloating with module-specific data\n\nUsage:\n- Create separate Data Table for weapon/module attributes\n- Row names should match TypeId (same as FEchoesItemDefinitionRow)\n- Only populate rows for modules/weapons\n- Use Common_GetWeaponAttributes() helper to fetch this data\n\nExample Data Table Setup:\nRow Name: \"2048\" (Light Neutron Blaster TypeId)\nDamage: 55.0\nOptimalRange: 2000.0 (2km)\nFalloff: 8000.0 (8km)\nTrackingSpeed: 0.4\nActivationCost: 5.0 (GJ)\nAmmoTypeId: 256 (Antimatter Charge S)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Damage_MetaData[] = {
		{ "Category", "Weapon Attributes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Base damage per hit/cycle\n\x09 * Actual damage depends on ammo type and target resistances\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesItemDefinitions.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Base damage per hit/cycle\nActual damage depends on ammo type and target resistances" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OptimalRange_MetaData[] = {
		{ "Category", "Weapon Attributes|Range" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Optimal range in centimeters (UE units)\n\x09 * Full damage applied up to this distance\n\x09 * Example: 200000.0 = 2km optimal\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesItemDefinitions.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optimal range in centimeters (UE units)\nFull damage applied up to this distance\nExample: 200000.0 = 2km optimal" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Falloff_MetaData[] = {
		{ "Category", "Weapon Attributes|Range" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Falloff range in centimeters (UE units)\n\x09 * Damage decreases from Optimal to Optimal+Falloff\n\x09 * Example: 800000.0 = 8km falloff\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesItemDefinitions.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Falloff range in centimeters (UE units)\nDamage decreases from Optimal to Optimal+Falloff\nExample: 800000.0 = 8km falloff" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TrackingSpeed_MetaData[] = {
		{ "Category", "Weapon Attributes|Accuracy" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Tracking speed (radians per second)\n\x09 * Affects ability to hit small/fast targets\n\x09 * Higher = better tracking\n\x09 * Example: 0.4 = good tracking for medium weapons\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesItemDefinitions.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Tracking speed (radians per second)\nAffects ability to hit small/fast targets\nHigher = better tracking\nExample: 0.4 = good tracking for medium weapons" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActivationCost_MetaData[] = {
		{ "Category", "Weapon Attributes|Activation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Capacitor energy cost per activation (in GJ)\n\x09 * Deducted from ship's capacitor when fired\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesItemDefinitions.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Capacitor energy cost per activation (in GJ)\nDeducted from ship's capacitor when fired" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActivationTime_MetaData[] = {
		{ "Category", "Weapon Attributes|Activation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Activation time / Cycle time (in seconds)\n\x09 * Time between shots or duration of active cycle\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesItemDefinitions.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Activation time / Cycle time (in seconds)\nTime between shots or duration of active cycle" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AmmoTypeId_MetaData[] = {
		{ "Category", "Weapon Attributes|Ammo" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Ammo type ID required for this weapon\n\x09 * 0 = No ammo required (energy weapons)\n\x09 * >0 = Specific ammo TypeId required\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesItemDefinitions.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ammo type ID required for this weapon\n0 = No ammo required (energy weapons)\n>0 = Specific ammo TypeId required" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AmmoConsumptionPerCycle_MetaData[] = {
		{ "Category", "Weapon Attributes|Ammo" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Ammo consumption per shot/cycle\n\x09 * Default: 1 ammo per activation\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesItemDefinitions.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ammo consumption per shot/cycle\nDefault: 1 ammo per activation" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxAmmoCapacity_MetaData[] = {
		{ "Category", "Weapon Attributes|Ammo" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Maximum ammo capacity in weapon\n\x09 * For weapons that load ammo (missiles, projectiles)\n\x09 * 0 = Uses ship cargo (energy weapons)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesItemDefinitions.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum ammo capacity in weapon\nFor weapons that load ammo (missiles, projectiles)\n0 = Uses ship cargo (energy weapons)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DamageMultiplier_MetaData[] = {
		{ "Category", "Weapon Attributes|Damage" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Damage multiplier for this weapon\n\x09 * Applied on top of base damage (for special variants)\n\x09 * Default: 1.0 (no modification)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesItemDefinitions.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Damage multiplier for this weapon\nApplied on top of base damage (for special variants)\nDefault: 1.0 (no modification)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RateOfFireMultiplier_MetaData[] = {
		{ "Category", "Weapon Attributes|Activation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Rate of fire modifier\n\x09 * Values < 1.0 = faster firing, > 1.0 = slower\n\x09 * Default: 1.0 (standard rate)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesItemDefinitions.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Rate of fire modifier\nValues < 1.0 = faster firing, > 1.0 = slower\nDefault: 1.0 (standard rate)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Damage;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OptimalRange;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Falloff;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TrackingSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ActivationCost;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ActivationTime;
	static const UECodeGen_Private::FIntPropertyParams NewProp_AmmoTypeId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_AmmoConsumptionPerCycle;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxAmmoCapacity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DamageMultiplier;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RateOfFireMultiplier;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FWeaponAttributesRow>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FWeaponAttributesRow_Statics::NewProp_Damage = { "Damage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWeaponAttributesRow, Damage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Damage_MetaData), NewProp_Damage_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FWeaponAttributesRow_Statics::NewProp_OptimalRange = { "OptimalRange", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWeaponAttributesRow, OptimalRange), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OptimalRange_MetaData), NewProp_OptimalRange_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FWeaponAttributesRow_Statics::NewProp_Falloff = { "Falloff", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWeaponAttributesRow, Falloff), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Falloff_MetaData), NewProp_Falloff_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FWeaponAttributesRow_Statics::NewProp_TrackingSpeed = { "TrackingSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWeaponAttributesRow, TrackingSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TrackingSpeed_MetaData), NewProp_TrackingSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FWeaponAttributesRow_Statics::NewProp_ActivationCost = { "ActivationCost", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWeaponAttributesRow, ActivationCost), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActivationCost_MetaData), NewProp_ActivationCost_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FWeaponAttributesRow_Statics::NewProp_ActivationTime = { "ActivationTime", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWeaponAttributesRow, ActivationTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActivationTime_MetaData), NewProp_ActivationTime_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FWeaponAttributesRow_Statics::NewProp_AmmoTypeId = { "AmmoTypeId", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWeaponAttributesRow, AmmoTypeId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AmmoTypeId_MetaData), NewProp_AmmoTypeId_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FWeaponAttributesRow_Statics::NewProp_AmmoConsumptionPerCycle = { "AmmoConsumptionPerCycle", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWeaponAttributesRow, AmmoConsumptionPerCycle), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AmmoConsumptionPerCycle_MetaData), NewProp_AmmoConsumptionPerCycle_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FWeaponAttributesRow_Statics::NewProp_MaxAmmoCapacity = { "MaxAmmoCapacity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWeaponAttributesRow, MaxAmmoCapacity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxAmmoCapacity_MetaData), NewProp_MaxAmmoCapacity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FWeaponAttributesRow_Statics::NewProp_DamageMultiplier = { "DamageMultiplier", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWeaponAttributesRow, DamageMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DamageMultiplier_MetaData), NewProp_DamageMultiplier_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FWeaponAttributesRow_Statics::NewProp_RateOfFireMultiplier = { "RateOfFireMultiplier", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWeaponAttributesRow, RateOfFireMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RateOfFireMultiplier_MetaData), NewProp_RateOfFireMultiplier_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FWeaponAttributesRow_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWeaponAttributesRow_Statics::NewProp_Damage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWeaponAttributesRow_Statics::NewProp_OptimalRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWeaponAttributesRow_Statics::NewProp_Falloff,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWeaponAttributesRow_Statics::NewProp_TrackingSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWeaponAttributesRow_Statics::NewProp_ActivationCost,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWeaponAttributesRow_Statics::NewProp_ActivationTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWeaponAttributesRow_Statics::NewProp_AmmoTypeId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWeaponAttributesRow_Statics::NewProp_AmmoConsumptionPerCycle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWeaponAttributesRow_Statics::NewProp_MaxAmmoCapacity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWeaponAttributesRow_Statics::NewProp_DamageMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWeaponAttributesRow_Statics::NewProp_RateOfFireMultiplier,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWeaponAttributesRow_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FWeaponAttributesRow_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	Z_Construct_UScriptStruct_FTableRowBase,
	&NewStructOps,
	"WeaponAttributesRow",
	Z_Construct_UScriptStruct_FWeaponAttributesRow_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWeaponAttributesRow_Statics::PropPointers),
	sizeof(FWeaponAttributesRow),
	alignof(FWeaponAttributesRow),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWeaponAttributesRow_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FWeaponAttributesRow_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FWeaponAttributesRow()
{
	if (!Z_Registration_Info_UScriptStruct_FWeaponAttributesRow.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FWeaponAttributesRow.InnerSingleton, Z_Construct_UScriptStruct_FWeaponAttributesRow_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FWeaponAttributesRow.InnerSingleton;
}
// ********** End ScriptStruct FWeaponAttributesRow ************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Types_EchoesItemDefinitions_h__Script_Echoes_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EEchoesSlotType_StaticEnum, TEXT("EEchoesSlotType"), &Z_Registration_Info_UEnum_EEchoesSlotType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3231457299U) },
		{ EEchoesItemCategory_StaticEnum, TEXT("EEchoesItemCategory"), &Z_Registration_Info_UEnum_EEchoesItemCategory, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3886991834U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FEchoesItemDefinitionRow::StaticStruct, Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::NewStructOps, TEXT("EchoesItemDefinitionRow"), &Z_Registration_Info_UScriptStruct_FEchoesItemDefinitionRow, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FEchoesItemDefinitionRow), 132594848U) },
		{ FWeaponAttributesRow::StaticStruct, Z_Construct_UScriptStruct_FWeaponAttributesRow_Statics::NewStructOps, TEXT("WeaponAttributesRow"), &Z_Registration_Info_UScriptStruct_FWeaponAttributesRow, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FWeaponAttributesRow), 27770086U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Types_EchoesItemDefinitions_h__Script_Echoes_1655653859(TEXT("/Script/Echoes"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Types_EchoesItemDefinitions_h__Script_Echoes_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Types_EchoesItemDefinitions_h__Script_Echoes_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Types_EchoesItemDefinitions_h__Script_Echoes_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Types_EchoesItemDefinitions_h__Script_Echoes_Statics::EnumInfo));
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
