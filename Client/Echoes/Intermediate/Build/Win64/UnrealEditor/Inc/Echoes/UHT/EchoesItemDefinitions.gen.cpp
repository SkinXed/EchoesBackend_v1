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
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FEchoesItemDefinitionRow();
ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTableRowBase();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

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

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Types_EchoesItemDefinitions_h__Script_Echoes_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EEchoesItemCategory_StaticEnum, TEXT("EEchoesItemCategory"), &Z_Registration_Info_UEnum_EEchoesItemCategory, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3886991834U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FEchoesItemDefinitionRow::StaticStruct, Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics::NewStructOps, TEXT("EchoesItemDefinitionRow"), &Z_Registration_Info_UScriptStruct_FEchoesItemDefinitionRow, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FEchoesItemDefinitionRow), 590939204U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Types_EchoesItemDefinitions_h__Script_Echoes_3810466379(TEXT("/Script/Echoes"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Types_EchoesItemDefinitions_h__Script_Echoes_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Types_EchoesItemDefinitions_h__Script_Echoes_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Types_EchoesItemDefinitions_h__Script_Echoes_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Types_EchoesItemDefinitions_h__Script_Echoes_Statics::EnumInfo));
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
