// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EchoesShipTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesShipTypes() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ECHOES_API UEnum* Z_Construct_UEnum_Echoes_EWarpState();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FEchoesShipStats();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EWarpState ****************************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EWarpState;
static UEnum* EWarpState_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EWarpState.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EWarpState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Echoes_EWarpState, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("EWarpState"));
	}
	return Z_Registration_Info_UEnum_EWarpState.OuterSingleton;
}
template<> ECHOES_API UEnum* StaticEnum<EWarpState>()
{
	return EWarpState_StaticEnum();
}
struct Z_Construct_UEnum_Echoes_EWarpState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Aligning.DisplayName", "Aligning" },
		{ "Aligning.Name", "EWarpState::Aligning" },
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Warp state enum - mirrors ship warp lifecycle\n * Used by movement component to track warp progression\n */" },
#endif
		{ "Exiting.DisplayName", "Exiting" },
		{ "Exiting.Name", "EWarpState::Exiting" },
		{ "Idle.DisplayName", "Idle" },
		{ "Idle.Name", "EWarpState::Idle" },
		{ "ModuleRelativePath", "Core/Common/Types/EchoesShipTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Warp state enum - mirrors ship warp lifecycle\nUsed by movement component to track warp progression" },
#endif
		{ "Warping.DisplayName", "Warping" },
		{ "Warping.Name", "EWarpState::Warping" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EWarpState::Idle", (int64)EWarpState::Idle },
		{ "EWarpState::Aligning", (int64)EWarpState::Aligning },
		{ "EWarpState::Warping", (int64)EWarpState::Warping },
		{ "EWarpState::Exiting", (int64)EWarpState::Exiting },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Echoes_EWarpState_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	"EWarpState",
	"EWarpState",
	Z_Construct_UEnum_Echoes_EWarpState_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_Echoes_EWarpState_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_Echoes_EWarpState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_Echoes_EWarpState_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_Echoes_EWarpState()
{
	if (!Z_Registration_Info_UEnum_EWarpState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EWarpState.InnerSingleton, Z_Construct_UEnum_Echoes_EWarpState_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EWarpState.InnerSingleton;
}
// ********** End Enum EWarpState ******************************************************************

// ********** Begin ScriptStruct FEchoesShipStats **************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FEchoesShipStats;
class UScriptStruct* FEchoesShipStats::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FEchoesShipStats.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FEchoesShipStats.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FEchoesShipStats, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("EchoesShipStats"));
	}
	return Z_Registration_Info_UScriptStruct_FEchoesShipStats.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FEchoesShipStats_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Ship statistics struct\n * MIRRORS C# ShipStatsDto - Keep in sync with backend!\n * Used to initialize ship physics from backend data\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesShipTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ship statistics struct\nMIRRORS C# ShipStatsDto - Keep in sync with backend!\nUsed to initialize ship physics from backend data" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalMass_MetaData[] = {
		{ "Category", "Ship Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Total mass including base mass and all module masses (kg) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesShipTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Total mass including base mass and all module masses (kg)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BaseMass_MetaData[] = {
		{ "Category", "Ship Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Base mass without modules (kg) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesShipTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Base mass without modules (kg)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Thrust_MetaData[] = {
		{ "Category", "Ship Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Thrust force in Newtons */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesShipTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Thrust force in Newtons" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RotationSpeed_MetaData[] = {
		{ "Category", "Ship Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum rotation speed in degrees per second */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesShipTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum rotation speed in degrees per second" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WarpSpeed_MetaData[] = {
		{ "Category", "Ship Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum warp speed multiplier (AU/s) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesShipTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum warp speed multiplier (AU/s)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InertiaMultiplier_MetaData[] = {
		{ "Category", "Ship Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Inertia multiplier affecting acceleration/deceleration */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesShipTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Inertia multiplier affecting acceleration/deceleration" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxVelocity_MetaData[] = {
		{ "Category", "Ship Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum velocity in meters per second */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesShipTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum velocity in meters per second" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Agility_MetaData[] = {
		{ "Category", "Ship Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Agility modifier (lower is more agile) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesShipTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Agility modifier (lower is more agile)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShipId_MetaData[] = {
		{ "Category", "Ship Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Ship instance ID from backend */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesShipTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ship instance ID from backend" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShipName_MetaData[] = {
		{ "Category", "Ship Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Ship instance name */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesShipTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ship instance name" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShipTypeId_MetaData[] = {
		{ "Category", "Ship Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Ship type ID from backend */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesShipTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ship type ID from backend" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShipTypeName_MetaData[] = {
		{ "Category", "Ship Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Ship type name */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesShipTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ship type name" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TotalMass;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BaseMass;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Thrust;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RotationSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WarpSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InertiaMultiplier;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxVelocity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Agility;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ShipId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ShipName;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ShipTypeId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ShipTypeName;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FEchoesShipStats>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FEchoesShipStats_Statics::NewProp_TotalMass = { "TotalMass", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesShipStats, TotalMass), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalMass_MetaData), NewProp_TotalMass_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FEchoesShipStats_Statics::NewProp_BaseMass = { "BaseMass", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesShipStats, BaseMass), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BaseMass_MetaData), NewProp_BaseMass_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FEchoesShipStats_Statics::NewProp_Thrust = { "Thrust", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesShipStats, Thrust), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Thrust_MetaData), NewProp_Thrust_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FEchoesShipStats_Statics::NewProp_RotationSpeed = { "RotationSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesShipStats, RotationSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RotationSpeed_MetaData), NewProp_RotationSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FEchoesShipStats_Statics::NewProp_WarpSpeed = { "WarpSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesShipStats, WarpSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WarpSpeed_MetaData), NewProp_WarpSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FEchoesShipStats_Statics::NewProp_InertiaMultiplier = { "InertiaMultiplier", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesShipStats, InertiaMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InertiaMultiplier_MetaData), NewProp_InertiaMultiplier_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FEchoesShipStats_Statics::NewProp_MaxVelocity = { "MaxVelocity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesShipStats, MaxVelocity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxVelocity_MetaData), NewProp_MaxVelocity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FEchoesShipStats_Statics::NewProp_Agility = { "Agility", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesShipStats, Agility), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Agility_MetaData), NewProp_Agility_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FEchoesShipStats_Statics::NewProp_ShipId = { "ShipId", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesShipStats, ShipId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShipId_MetaData), NewProp_ShipId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FEchoesShipStats_Statics::NewProp_ShipName = { "ShipName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesShipStats, ShipName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShipName_MetaData), NewProp_ShipName_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FEchoesShipStats_Statics::NewProp_ShipTypeId = { "ShipTypeId", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesShipStats, ShipTypeId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShipTypeId_MetaData), NewProp_ShipTypeId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FEchoesShipStats_Statics::NewProp_ShipTypeName = { "ShipTypeName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesShipStats, ShipTypeName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShipTypeName_MetaData), NewProp_ShipTypeName_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FEchoesShipStats_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesShipStats_Statics::NewProp_TotalMass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesShipStats_Statics::NewProp_BaseMass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesShipStats_Statics::NewProp_Thrust,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesShipStats_Statics::NewProp_RotationSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesShipStats_Statics::NewProp_WarpSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesShipStats_Statics::NewProp_InertiaMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesShipStats_Statics::NewProp_MaxVelocity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesShipStats_Statics::NewProp_Agility,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesShipStats_Statics::NewProp_ShipId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesShipStats_Statics::NewProp_ShipName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesShipStats_Statics::NewProp_ShipTypeId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesShipStats_Statics::NewProp_ShipTypeName,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEchoesShipStats_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FEchoesShipStats_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"EchoesShipStats",
	Z_Construct_UScriptStruct_FEchoesShipStats_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEchoesShipStats_Statics::PropPointers),
	sizeof(FEchoesShipStats),
	alignof(FEchoesShipStats),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEchoesShipStats_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FEchoesShipStats_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FEchoesShipStats()
{
	if (!Z_Registration_Info_UScriptStruct_FEchoesShipStats.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FEchoesShipStats.InnerSingleton, Z_Construct_UScriptStruct_FEchoesShipStats_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FEchoesShipStats.InnerSingleton;
}
// ********** End ScriptStruct FEchoesShipStats ****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Types_EchoesShipTypes_h__Script_Echoes_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EWarpState_StaticEnum, TEXT("EWarpState"), &Z_Registration_Info_UEnum_EWarpState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1203776617U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FEchoesShipStats::StaticStruct, Z_Construct_UScriptStruct_FEchoesShipStats_Statics::NewStructOps, TEXT("EchoesShipStats"), &Z_Registration_Info_UScriptStruct_FEchoesShipStats, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FEchoesShipStats), 2315152803U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Types_EchoesShipTypes_h__Script_Echoes_3893100305(TEXT("/Script/Echoes"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Types_EchoesShipTypes_h__Script_Echoes_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Types_EchoesShipTypes_h__Script_Echoes_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Types_EchoesShipTypes_h__Script_Echoes_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Types_EchoesShipTypes_h__Script_Echoes_Statics::EnumInfo));
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
