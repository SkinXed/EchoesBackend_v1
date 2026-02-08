// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EchoesKillmailStructures.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesKillmailStructures() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FDateTime();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FDamageMapEntry();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FKillmailAttacker();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FKillmailData();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FKillmailItem();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FKillmailAttacker *************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FKillmailAttacker;
class UScriptStruct* FKillmailAttacker::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FKillmailAttacker.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FKillmailAttacker.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FKillmailAttacker, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("KillmailAttacker"));
	}
	return Z_Registration_Info_UScriptStruct_FKillmailAttacker.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FKillmailAttacker_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Single attacker entry in a killmail\n * Represents one player who participated in a ship destruction\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesKillmailStructures.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Single attacker entry in a killmail\nRepresents one player who participated in a ship destruction" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterId_MetaData[] = {
		{ "Category", "Killmail" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesKillmailStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterName_MetaData[] = {
		{ "Category", "Killmail" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesKillmailStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CorporationId_MetaData[] = {
		{ "Category", "Killmail" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesKillmailStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShipTypeId_MetaData[] = {
		{ "Category", "Killmail" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesKillmailStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShipTypeName_MetaData[] = {
		{ "Category", "Killmail" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesKillmailStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WeaponTypeName_MetaData[] = {
		{ "Category", "Killmail" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesKillmailStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DamageDealt_MetaData[] = {
		{ "Category", "Killmail" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesKillmailStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IsFinalBlow_MetaData[] = {
		{ "Category", "Killmail" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesKillmailStructures.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_CharacterId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_CharacterName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CorporationId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ShipTypeId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ShipTypeName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_WeaponTypeName;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_DamageDealt;
	static void NewProp_IsFinalBlow_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_IsFinalBlow;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FKillmailAttacker>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FKillmailAttacker_Statics::NewProp_CharacterId = { "CharacterId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FKillmailAttacker, CharacterId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterId_MetaData), NewProp_CharacterId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FKillmailAttacker_Statics::NewProp_CharacterName = { "CharacterName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FKillmailAttacker, CharacterName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterName_MetaData), NewProp_CharacterName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FKillmailAttacker_Statics::NewProp_CorporationId = { "CorporationId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FKillmailAttacker, CorporationId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CorporationId_MetaData), NewProp_CorporationId_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FKillmailAttacker_Statics::NewProp_ShipTypeId = { "ShipTypeId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FKillmailAttacker, ShipTypeId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShipTypeId_MetaData), NewProp_ShipTypeId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FKillmailAttacker_Statics::NewProp_ShipTypeName = { "ShipTypeName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FKillmailAttacker, ShipTypeName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShipTypeName_MetaData), NewProp_ShipTypeName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FKillmailAttacker_Statics::NewProp_WeaponTypeName = { "WeaponTypeName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FKillmailAttacker, WeaponTypeName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WeaponTypeName_MetaData), NewProp_WeaponTypeName_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FKillmailAttacker_Statics::NewProp_DamageDealt = { "DamageDealt", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FKillmailAttacker, DamageDealt), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DamageDealt_MetaData), NewProp_DamageDealt_MetaData) };
void Z_Construct_UScriptStruct_FKillmailAttacker_Statics::NewProp_IsFinalBlow_SetBit(void* Obj)
{
	((FKillmailAttacker*)Obj)->IsFinalBlow = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FKillmailAttacker_Statics::NewProp_IsFinalBlow = { "IsFinalBlow", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FKillmailAttacker), &Z_Construct_UScriptStruct_FKillmailAttacker_Statics::NewProp_IsFinalBlow_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IsFinalBlow_MetaData), NewProp_IsFinalBlow_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FKillmailAttacker_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FKillmailAttacker_Statics::NewProp_CharacterId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FKillmailAttacker_Statics::NewProp_CharacterName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FKillmailAttacker_Statics::NewProp_CorporationId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FKillmailAttacker_Statics::NewProp_ShipTypeId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FKillmailAttacker_Statics::NewProp_ShipTypeName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FKillmailAttacker_Statics::NewProp_WeaponTypeName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FKillmailAttacker_Statics::NewProp_DamageDealt,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FKillmailAttacker_Statics::NewProp_IsFinalBlow,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FKillmailAttacker_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FKillmailAttacker_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"KillmailAttacker",
	Z_Construct_UScriptStruct_FKillmailAttacker_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FKillmailAttacker_Statics::PropPointers),
	sizeof(FKillmailAttacker),
	alignof(FKillmailAttacker),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FKillmailAttacker_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FKillmailAttacker_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FKillmailAttacker()
{
	if (!Z_Registration_Info_UScriptStruct_FKillmailAttacker.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FKillmailAttacker.InnerSingleton, Z_Construct_UScriptStruct_FKillmailAttacker_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FKillmailAttacker.InnerSingleton;
}
// ********** End ScriptStruct FKillmailAttacker ***************************************************

// ********** Begin ScriptStruct FKillmailItem *****************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FKillmailItem;
class UScriptStruct* FKillmailItem::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FKillmailItem.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FKillmailItem.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FKillmailItem, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("KillmailItem"));
	}
	return Z_Registration_Info_UScriptStruct_FKillmailItem.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FKillmailItem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Single item entry in a killmail (dropped or destroyed)\n * Used for both the 50/50 drop roll results\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesKillmailStructures.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Single item entry in a killmail (dropped or destroyed)\nUsed for both the 50/50 drop roll results" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemTypeId_MetaData[] = {
		{ "Category", "Killmail" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesKillmailStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemName_MetaData[] = {
		{ "Category", "Killmail" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesKillmailStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Quantity_MetaData[] = {
		{ "Category", "Killmail" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesKillmailStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EstimatedValue_MetaData[] = {
		{ "Category", "Killmail" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesKillmailStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[] = {
		{ "Category", "Killmail" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Where this item was: Cargo, HighSlot, MidSlot, LowSlot, RigSlot */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesKillmailStructures.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Where this item was: Cargo, HighSlot, MidSlot, LowSlot, RigSlot" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ItemTypeId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ItemName;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Quantity;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_EstimatedValue;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Location;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FKillmailItem>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FKillmailItem_Statics::NewProp_ItemTypeId = { "ItemTypeId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FKillmailItem, ItemTypeId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemTypeId_MetaData), NewProp_ItemTypeId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FKillmailItem_Statics::NewProp_ItemName = { "ItemName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FKillmailItem, ItemName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemName_MetaData), NewProp_ItemName_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FKillmailItem_Statics::NewProp_Quantity = { "Quantity", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FKillmailItem, Quantity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Quantity_MetaData), NewProp_Quantity_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FKillmailItem_Statics::NewProp_EstimatedValue = { "EstimatedValue", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FKillmailItem, EstimatedValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EstimatedValue_MetaData), NewProp_EstimatedValue_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FKillmailItem_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FKillmailItem, Location), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Location_MetaData), NewProp_Location_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FKillmailItem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FKillmailItem_Statics::NewProp_ItemTypeId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FKillmailItem_Statics::NewProp_ItemName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FKillmailItem_Statics::NewProp_Quantity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FKillmailItem_Statics::NewProp_EstimatedValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FKillmailItem_Statics::NewProp_Location,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FKillmailItem_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FKillmailItem_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"KillmailItem",
	Z_Construct_UScriptStruct_FKillmailItem_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FKillmailItem_Statics::PropPointers),
	sizeof(FKillmailItem),
	alignof(FKillmailItem),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FKillmailItem_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FKillmailItem_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FKillmailItem()
{
	if (!Z_Registration_Info_UScriptStruct_FKillmailItem.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FKillmailItem.InnerSingleton, Z_Construct_UScriptStruct_FKillmailItem_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FKillmailItem.InnerSingleton;
}
// ********** End ScriptStruct FKillmailItem *******************************************************

// ********** Begin ScriptStruct FKillmailData *****************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FKillmailData;
class UScriptStruct* FKillmailData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FKillmailData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FKillmailData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FKillmailData, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("KillmailData"));
	}
	return Z_Registration_Info_UScriptStruct_FKillmailData.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FKillmailData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Full killmail data for a ship destruction event\n * Mirrors the backend KillmailReportRequest DTO\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesKillmailStructures.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Full killmail data for a ship destruction event\nMirrors the backend KillmailReportRequest DTO" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_KillmailId_MetaData[] = {
		{ "Category", "Killmail" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesKillmailStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VictimId_MetaData[] = {
		{ "Category", "Killmail" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesKillmailStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VictimName_MetaData[] = {
		{ "Category", "Killmail" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesKillmailStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FinalStrikerId_MetaData[] = {
		{ "Category", "Killmail" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesKillmailStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FinalStrikerName_MetaData[] = {
		{ "Category", "Killmail" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesKillmailStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SolarSystemId_MetaData[] = {
		{ "Category", "Killmail" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesKillmailStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SolarSystemName_MetaData[] = {
		{ "Category", "Killmail" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesKillmailStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShipTypeId_MetaData[] = {
		{ "Category", "Killmail" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesKillmailStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShipTypeName_MetaData[] = {
		{ "Category", "Killmail" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesKillmailStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalLossValue_MetaData[] = {
		{ "Category", "Killmail" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesKillmailStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Attackers_MetaData[] = {
		{ "Category", "Killmail" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesKillmailStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DroppedItems_MetaData[] = {
		{ "Category", "Killmail" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesKillmailStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DestroyedItems_MetaData[] = {
		{ "Category", "Killmail" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesKillmailStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_KilledAt_MetaData[] = {
		{ "Category", "Killmail" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesKillmailStructures.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_KillmailId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_VictimId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_VictimName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_FinalStrikerId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FinalStrikerName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SolarSystemId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SolarSystemName;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ShipTypeId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ShipTypeName;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_TotalLossValue;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Attackers_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Attackers;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DroppedItems_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_DroppedItems;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DestroyedItems_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_DestroyedItems;
	static const UECodeGen_Private::FStructPropertyParams NewProp_KilledAt;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FKillmailData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FKillmailData_Statics::NewProp_KillmailId = { "KillmailId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FKillmailData, KillmailId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_KillmailId_MetaData), NewProp_KillmailId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FKillmailData_Statics::NewProp_VictimId = { "VictimId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FKillmailData, VictimId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VictimId_MetaData), NewProp_VictimId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FKillmailData_Statics::NewProp_VictimName = { "VictimName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FKillmailData, VictimName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VictimName_MetaData), NewProp_VictimName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FKillmailData_Statics::NewProp_FinalStrikerId = { "FinalStrikerId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FKillmailData, FinalStrikerId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FinalStrikerId_MetaData), NewProp_FinalStrikerId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FKillmailData_Statics::NewProp_FinalStrikerName = { "FinalStrikerName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FKillmailData, FinalStrikerName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FinalStrikerName_MetaData), NewProp_FinalStrikerName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FKillmailData_Statics::NewProp_SolarSystemId = { "SolarSystemId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FKillmailData, SolarSystemId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SolarSystemId_MetaData), NewProp_SolarSystemId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FKillmailData_Statics::NewProp_SolarSystemName = { "SolarSystemName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FKillmailData, SolarSystemName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SolarSystemName_MetaData), NewProp_SolarSystemName_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FKillmailData_Statics::NewProp_ShipTypeId = { "ShipTypeId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FKillmailData, ShipTypeId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShipTypeId_MetaData), NewProp_ShipTypeId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FKillmailData_Statics::NewProp_ShipTypeName = { "ShipTypeName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FKillmailData, ShipTypeName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShipTypeName_MetaData), NewProp_ShipTypeName_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FKillmailData_Statics::NewProp_TotalLossValue = { "TotalLossValue", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FKillmailData, TotalLossValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalLossValue_MetaData), NewProp_TotalLossValue_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FKillmailData_Statics::NewProp_Attackers_Inner = { "Attackers", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FKillmailAttacker, METADATA_PARAMS(0, nullptr) }; // 996054030
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FKillmailData_Statics::NewProp_Attackers = { "Attackers", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FKillmailData, Attackers), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Attackers_MetaData), NewProp_Attackers_MetaData) }; // 996054030
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FKillmailData_Statics::NewProp_DroppedItems_Inner = { "DroppedItems", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FKillmailItem, METADATA_PARAMS(0, nullptr) }; // 4119519826
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FKillmailData_Statics::NewProp_DroppedItems = { "DroppedItems", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FKillmailData, DroppedItems), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DroppedItems_MetaData), NewProp_DroppedItems_MetaData) }; // 4119519826
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FKillmailData_Statics::NewProp_DestroyedItems_Inner = { "DestroyedItems", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FKillmailItem, METADATA_PARAMS(0, nullptr) }; // 4119519826
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FKillmailData_Statics::NewProp_DestroyedItems = { "DestroyedItems", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FKillmailData, DestroyedItems), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DestroyedItems_MetaData), NewProp_DestroyedItems_MetaData) }; // 4119519826
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FKillmailData_Statics::NewProp_KilledAt = { "KilledAt", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FKillmailData, KilledAt), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_KilledAt_MetaData), NewProp_KilledAt_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FKillmailData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FKillmailData_Statics::NewProp_KillmailId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FKillmailData_Statics::NewProp_VictimId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FKillmailData_Statics::NewProp_VictimName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FKillmailData_Statics::NewProp_FinalStrikerId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FKillmailData_Statics::NewProp_FinalStrikerName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FKillmailData_Statics::NewProp_SolarSystemId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FKillmailData_Statics::NewProp_SolarSystemName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FKillmailData_Statics::NewProp_ShipTypeId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FKillmailData_Statics::NewProp_ShipTypeName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FKillmailData_Statics::NewProp_TotalLossValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FKillmailData_Statics::NewProp_Attackers_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FKillmailData_Statics::NewProp_Attackers,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FKillmailData_Statics::NewProp_DroppedItems_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FKillmailData_Statics::NewProp_DroppedItems,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FKillmailData_Statics::NewProp_DestroyedItems_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FKillmailData_Statics::NewProp_DestroyedItems,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FKillmailData_Statics::NewProp_KilledAt,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FKillmailData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FKillmailData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"KillmailData",
	Z_Construct_UScriptStruct_FKillmailData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FKillmailData_Statics::PropPointers),
	sizeof(FKillmailData),
	alignof(FKillmailData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FKillmailData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FKillmailData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FKillmailData()
{
	if (!Z_Registration_Info_UScriptStruct_FKillmailData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FKillmailData.InnerSingleton, Z_Construct_UScriptStruct_FKillmailData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FKillmailData.InnerSingleton;
}
// ********** End ScriptStruct FKillmailData *******************************************************

// ********** Begin ScriptStruct FDamageMapEntry ***************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDamageMapEntry;
class UScriptStruct* FDamageMapEntry::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FDamageMapEntry.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FDamageMapEntry.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDamageMapEntry, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("DamageMapEntry"));
	}
	return Z_Registration_Info_UScriptStruct_FDamageMapEntry.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FDamageMapEntry_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Entry in the damage map: tracks how much damage each attacker dealt\n * Used by ServerOnly_HandleDestruction to determine attackers list\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesKillmailStructures.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Entry in the damage map: tracks how much damage each attacker dealt\nUsed by ServerOnly_HandleDestruction to determine attackers list" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackerId_MetaData[] = {
		{ "Category", "Killmail" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesKillmailStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackerName_MetaData[] = {
		{ "Category", "Killmail" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesKillmailStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackerCorporationId_MetaData[] = {
		{ "Category", "Killmail" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesKillmailStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackerShipTypeId_MetaData[] = {
		{ "Category", "Killmail" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesKillmailStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackerShipTypeName_MetaData[] = {
		{ "Category", "Killmail" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesKillmailStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LastWeaponUsed_MetaData[] = {
		{ "Category", "Killmail" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesKillmailStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalDamage_MetaData[] = {
		{ "Category", "Killmail" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesKillmailStructures.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_AttackerId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_AttackerName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AttackerCorporationId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_AttackerShipTypeId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_AttackerShipTypeName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_LastWeaponUsed;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_TotalDamage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDamageMapEntry>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FDamageMapEntry_Statics::NewProp_AttackerId = { "AttackerId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDamageMapEntry, AttackerId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackerId_MetaData), NewProp_AttackerId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDamageMapEntry_Statics::NewProp_AttackerName = { "AttackerName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDamageMapEntry, AttackerName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackerName_MetaData), NewProp_AttackerName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FDamageMapEntry_Statics::NewProp_AttackerCorporationId = { "AttackerCorporationId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDamageMapEntry, AttackerCorporationId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackerCorporationId_MetaData), NewProp_AttackerCorporationId_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDamageMapEntry_Statics::NewProp_AttackerShipTypeId = { "AttackerShipTypeId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDamageMapEntry, AttackerShipTypeId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackerShipTypeId_MetaData), NewProp_AttackerShipTypeId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDamageMapEntry_Statics::NewProp_AttackerShipTypeName = { "AttackerShipTypeName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDamageMapEntry, AttackerShipTypeName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackerShipTypeName_MetaData), NewProp_AttackerShipTypeName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDamageMapEntry_Statics::NewProp_LastWeaponUsed = { "LastWeaponUsed", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDamageMapEntry, LastWeaponUsed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LastWeaponUsed_MetaData), NewProp_LastWeaponUsed_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FDamageMapEntry_Statics::NewProp_TotalDamage = { "TotalDamage", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDamageMapEntry, TotalDamage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalDamage_MetaData), NewProp_TotalDamage_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDamageMapEntry_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDamageMapEntry_Statics::NewProp_AttackerId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDamageMapEntry_Statics::NewProp_AttackerName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDamageMapEntry_Statics::NewProp_AttackerCorporationId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDamageMapEntry_Statics::NewProp_AttackerShipTypeId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDamageMapEntry_Statics::NewProp_AttackerShipTypeName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDamageMapEntry_Statics::NewProp_LastWeaponUsed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDamageMapEntry_Statics::NewProp_TotalDamage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDamageMapEntry_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDamageMapEntry_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"DamageMapEntry",
	Z_Construct_UScriptStruct_FDamageMapEntry_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDamageMapEntry_Statics::PropPointers),
	sizeof(FDamageMapEntry),
	alignof(FDamageMapEntry),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDamageMapEntry_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDamageMapEntry_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDamageMapEntry()
{
	if (!Z_Registration_Info_UScriptStruct_FDamageMapEntry.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDamageMapEntry.InnerSingleton, Z_Construct_UScriptStruct_FDamageMapEntry_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FDamageMapEntry.InnerSingleton;
}
// ********** End ScriptStruct FDamageMapEntry *****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Structures_EchoesKillmailStructures_h__Script_Echoes_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FKillmailAttacker::StaticStruct, Z_Construct_UScriptStruct_FKillmailAttacker_Statics::NewStructOps, TEXT("KillmailAttacker"), &Z_Registration_Info_UScriptStruct_FKillmailAttacker, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FKillmailAttacker), 996054030U) },
		{ FKillmailItem::StaticStruct, Z_Construct_UScriptStruct_FKillmailItem_Statics::NewStructOps, TEXT("KillmailItem"), &Z_Registration_Info_UScriptStruct_FKillmailItem, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FKillmailItem), 4119519826U) },
		{ FKillmailData::StaticStruct, Z_Construct_UScriptStruct_FKillmailData_Statics::NewStructOps, TEXT("KillmailData"), &Z_Registration_Info_UScriptStruct_FKillmailData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FKillmailData), 1177097489U) },
		{ FDamageMapEntry::StaticStruct, Z_Construct_UScriptStruct_FDamageMapEntry_Statics::NewStructOps, TEXT("DamageMapEntry"), &Z_Registration_Info_UScriptStruct_FDamageMapEntry, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDamageMapEntry), 3494423854U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Structures_EchoesKillmailStructures_h__Script_Echoes_1502064163(TEXT("/Script/Echoes"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Structures_EchoesKillmailStructures_h__Script_Echoes_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Structures_EchoesKillmailStructures_h__Script_Echoes_Statics::ScriptStructInfo),
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
