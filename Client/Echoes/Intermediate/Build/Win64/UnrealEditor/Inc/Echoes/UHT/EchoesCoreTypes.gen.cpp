// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EchoesCoreTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesCoreTypes() {}

// ********** Begin Cross Module References ********************************************************
ECHOES_API UEnum* Z_Construct_UEnum_Echoes_ECosmosDamageType();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FCosmosDefenseLayer();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum ECosmosDamageType *********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ECosmosDamageType;
static UEnum* ECosmosDamageType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ECosmosDamageType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ECosmosDamageType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Echoes_ECosmosDamageType, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("ECosmosDamageType"));
	}
	return Z_Registration_Info_UEnum_ECosmosDamageType.OuterSingleton;
}
template<> ECHOES_API UEnum* StaticEnum<ECosmosDamageType>()
{
	return ECosmosDamageType_StaticEnum();
}
struct Z_Construct_UEnum_Echoes_ECosmosDamageType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Cosmos damage type enum\n * Represents the five damage types in EVE-like combat system\n * Each type can have different resistances on defense layers\n */" },
#endif
		{ "EM.Comment", "/** Electromagnetic damage - typically effective against shields */" },
		{ "EM.DisplayName", "Electromagnetic" },
		{ "EM.Name", "ECosmosDamageType::EM" },
		{ "EM.ToolTip", "Electromagnetic damage - typically effective against shields" },
		{ "Explosive.Comment", "/** Explosive damage - explosive ordnance damage */" },
		{ "Explosive.DisplayName", "Explosive" },
		{ "Explosive.Name", "ECosmosDamageType::Explosive" },
		{ "Explosive.ToolTip", "Explosive damage - explosive ordnance damage" },
		{ "Kinetic.Comment", "/** Kinetic damage - physical projectile damage */" },
		{ "Kinetic.DisplayName", "Kinetic" },
		{ "Kinetic.Name", "ECosmosDamageType::Kinetic" },
		{ "Kinetic.ToolTip", "Kinetic damage - physical projectile damage" },
		{ "ModuleRelativePath", "Core/Common/EchoesCoreTypes.h" },
		{ "Omni.Comment", "/** Omni damage - pure damage that bypasses all resistances */" },
		{ "Omni.DisplayName", "Omni (Pure)" },
		{ "Omni.Name", "ECosmosDamageType::Omni" },
		{ "Omni.ToolTip", "Omni damage - pure damage that bypasses all resistances" },
		{ "Thermal.Comment", "/** Thermal damage - heat-based damage */" },
		{ "Thermal.DisplayName", "Thermal" },
		{ "Thermal.Name", "ECosmosDamageType::Thermal" },
		{ "Thermal.ToolTip", "Thermal damage - heat-based damage" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cosmos damage type enum\nRepresents the five damage types in EVE-like combat system\nEach type can have different resistances on defense layers" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ECosmosDamageType::EM", (int64)ECosmosDamageType::EM },
		{ "ECosmosDamageType::Thermal", (int64)ECosmosDamageType::Thermal },
		{ "ECosmosDamageType::Kinetic", (int64)ECosmosDamageType::Kinetic },
		{ "ECosmosDamageType::Explosive", (int64)ECosmosDamageType::Explosive },
		{ "ECosmosDamageType::Omni", (int64)ECosmosDamageType::Omni },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Echoes_ECosmosDamageType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	"ECosmosDamageType",
	"ECosmosDamageType",
	Z_Construct_UEnum_Echoes_ECosmosDamageType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_Echoes_ECosmosDamageType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_Echoes_ECosmosDamageType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_Echoes_ECosmosDamageType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_Echoes_ECosmosDamageType()
{
	if (!Z_Registration_Info_UEnum_ECosmosDamageType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ECosmosDamageType.InnerSingleton, Z_Construct_UEnum_Echoes_ECosmosDamageType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ECosmosDamageType.InnerSingleton;
}
// ********** End Enum ECosmosDamageType ***********************************************************

// ********** Begin ScriptStruct FCosmosDefenseLayer ***********************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FCosmosDefenseLayer;
class UScriptStruct* FCosmosDefenseLayer::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FCosmosDefenseLayer.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FCosmosDefenseLayer.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FCosmosDefenseLayer, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("CosmosDefenseLayer"));
	}
	return Z_Registration_Info_UScriptStruct_FCosmosDefenseLayer.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FCosmosDefenseLayer_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Cosmos defense layer structure\n * Represents a single defense layer (Shield, Armor, or Structure) with resistances\n * \n * Damage Mitigation Formula:\n * MitigatedDamage = RawDamage * (1.0 - Resistance)\n * \n * Example: 100 damage with 0.5 (50%) resistance = 100 * (1.0 - 0.5) = 50 damage taken\n * \n * Resistance Range: 0.0 (0% mitigation) to 1.0 (100% mitigation, immune)\n * Typical EVE values: 0.0 to 0.75 (0% to 75% mitigation)\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesCoreTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cosmos defense layer structure\nRepresents a single defense layer (Shield, Armor, or Structure) with resistances\n\nDamage Mitigation Formula:\nMitigatedDamage = RawDamage * (1.0 - Resistance)\n\nExample: 100 damage with 0.5 (50%) resistance = 100 * (1.0 - 0.5) = 50 damage taken\n\nResistance Range: 0.0 (0% mitigation) to 1.0 (100% mitigation, immune)\nTypical EVE values: 0.0 to 0.75 (0% to 75% mitigation)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Current_MetaData[] = {
		{ "Category", "Defense Layer" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current hit points for this layer */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesCoreTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current hit points for this layer" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Max_MetaData[] = {
		{ "Category", "Defense Layer" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum hit points for this layer */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesCoreTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum hit points for this layer" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ResistEM_MetaData[] = {
		{ "Category", "Defense Layer|Resistances" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Electromagnetic damage resistance (0.0 to 1.0) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesCoreTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Electromagnetic damage resistance (0.0 to 1.0)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ResistThermal_MetaData[] = {
		{ "Category", "Defense Layer|Resistances" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Thermal damage resistance (0.0 to 1.0) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesCoreTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Thermal damage resistance (0.0 to 1.0)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ResistKinetic_MetaData[] = {
		{ "Category", "Defense Layer|Resistances" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Kinetic damage resistance (0.0 to 1.0) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesCoreTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Kinetic damage resistance (0.0 to 1.0)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ResistExplosive_MetaData[] = {
		{ "Category", "Defense Layer|Resistances" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Explosive damage resistance (0.0 to 1.0) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesCoreTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Explosive damage resistance (0.0 to 1.0)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Current;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Max;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ResistEM;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ResistThermal;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ResistKinetic;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ResistExplosive;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCosmosDefenseLayer>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCosmosDefenseLayer_Statics::NewProp_Current = { "Current", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCosmosDefenseLayer, Current), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Current_MetaData), NewProp_Current_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCosmosDefenseLayer_Statics::NewProp_Max = { "Max", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCosmosDefenseLayer, Max), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Max_MetaData), NewProp_Max_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCosmosDefenseLayer_Statics::NewProp_ResistEM = { "ResistEM", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCosmosDefenseLayer, ResistEM), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ResistEM_MetaData), NewProp_ResistEM_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCosmosDefenseLayer_Statics::NewProp_ResistThermal = { "ResistThermal", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCosmosDefenseLayer, ResistThermal), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ResistThermal_MetaData), NewProp_ResistThermal_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCosmosDefenseLayer_Statics::NewProp_ResistKinetic = { "ResistKinetic", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCosmosDefenseLayer, ResistKinetic), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ResistKinetic_MetaData), NewProp_ResistKinetic_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCosmosDefenseLayer_Statics::NewProp_ResistExplosive = { "ResistExplosive", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCosmosDefenseLayer, ResistExplosive), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ResistExplosive_MetaData), NewProp_ResistExplosive_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCosmosDefenseLayer_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCosmosDefenseLayer_Statics::NewProp_Current,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCosmosDefenseLayer_Statics::NewProp_Max,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCosmosDefenseLayer_Statics::NewProp_ResistEM,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCosmosDefenseLayer_Statics::NewProp_ResistThermal,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCosmosDefenseLayer_Statics::NewProp_ResistKinetic,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCosmosDefenseLayer_Statics::NewProp_ResistExplosive,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCosmosDefenseLayer_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCosmosDefenseLayer_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"CosmosDefenseLayer",
	Z_Construct_UScriptStruct_FCosmosDefenseLayer_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCosmosDefenseLayer_Statics::PropPointers),
	sizeof(FCosmosDefenseLayer),
	alignof(FCosmosDefenseLayer),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCosmosDefenseLayer_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FCosmosDefenseLayer_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FCosmosDefenseLayer()
{
	if (!Z_Registration_Info_UScriptStruct_FCosmosDefenseLayer.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FCosmosDefenseLayer.InnerSingleton, Z_Construct_UScriptStruct_FCosmosDefenseLayer_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FCosmosDefenseLayer.InnerSingleton;
}
// ********** End ScriptStruct FCosmosDefenseLayer *************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesCoreTypes_h__Script_Echoes_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ ECosmosDamageType_StaticEnum, TEXT("ECosmosDamageType"), &Z_Registration_Info_UEnum_ECosmosDamageType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4170051619U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FCosmosDefenseLayer::StaticStruct, Z_Construct_UScriptStruct_FCosmosDefenseLayer_Statics::NewStructOps, TEXT("CosmosDefenseLayer"), &Z_Registration_Info_UScriptStruct_FCosmosDefenseLayer, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FCosmosDefenseLayer), 3062971545U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesCoreTypes_h__Script_Echoes_2150427229(TEXT("/Script/Echoes"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesCoreTypes_h__Script_Echoes_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesCoreTypes_h__Script_Echoes_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesCoreTypes_h__Script_Echoes_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesCoreTypes_h__Script_Echoes_Statics::EnumInfo));
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
