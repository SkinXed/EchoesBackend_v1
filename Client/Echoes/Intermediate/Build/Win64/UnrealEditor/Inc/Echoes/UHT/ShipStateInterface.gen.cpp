// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ShipStateInterface.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeShipStateInterface() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ECHOES_API UClass* Z_Construct_UClass_UShipStateInterface();
ECHOES_API UClass* Z_Construct_UClass_UShipStateInterface_NoRegister();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FCommon_ShipDataStruct();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FCommon_ShipDataStruct ********************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FCommon_ShipDataStruct;
class UScriptStruct* FCommon_ShipDataStruct::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FCommon_ShipDataStruct.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FCommon_ShipDataStruct.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FCommon_ShipDataStruct, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("Common_ShipDataStruct"));
	}
	return Z_Registration_Info_UScriptStruct_FCommon_ShipDataStruct.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FCommon_ShipDataStruct_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Ship data structure for HUD display\n * Contains all relevant ship information for UI updates\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipStateInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ship data structure for HUD display\nContains all relevant ship information for UI updates" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShieldCurrent_MetaData[] = {
		{ "Category", "Ship Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Shield current value */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipStateInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shield current value" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShieldMax_MetaData[] = {
		{ "Category", "Ship Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Shield maximum value */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipStateInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shield maximum value" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ArmorCurrent_MetaData[] = {
		{ "Category", "Ship Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Armor current value */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipStateInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Armor current value" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ArmorMax_MetaData[] = {
		{ "Category", "Ship Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Armor maximum value */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipStateInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Armor maximum value" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StructureCurrent_MetaData[] = {
		{ "Category", "Ship Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Structure (Hull) current value */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipStateInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Structure (Hull) current value" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StructureMax_MetaData[] = {
		{ "Category", "Ship Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Structure (Hull) maximum value */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipStateInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Structure (Hull) maximum value" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CapacitorCurrent_MetaData[] = {
		{ "Category", "Ship Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Capacitor current value (energy for modules) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipStateInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Capacitor current value (energy for modules)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CapacitorMax_MetaData[] = {
		{ "Category", "Ship Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Capacitor maximum value */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipStateInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Capacitor maximum value" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Velocity_MetaData[] = {
		{ "Category", "Ship Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current velocity in cm/s */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipStateInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current velocity in cm/s" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Speed_MetaData[] = {
		{ "Category", "Ship Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current speed in m/s */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipStateInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current speed in m/s" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxSpeed_MetaData[] = {
		{ "Category", "Ship Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum speed in m/s */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipStateInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum speed in m/s" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LockedTargetsCount_MetaData[] = {
		{ "Category", "Ship Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Number of locked targets */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipStateInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Number of locked targets" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxLockedTargets_MetaData[] = {
		{ "Category", "Ship Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum number of targets that can be locked */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipStateInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum number of targets that can be locked" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[] = {
		{ "Category", "Ship Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current location in world space */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipStateInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current location in world space" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rotation_MetaData[] = {
		{ "Category", "Ship Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current rotation */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipStateInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current rotation" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShipName_MetaData[] = {
		{ "Category", "Ship Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Ship name */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipStateInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ship name" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShipType_MetaData[] = {
		{ "Category", "Ship Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Ship type/class */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipStateInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ship type/class" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ShieldCurrent;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ShieldMax;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ArmorCurrent;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ArmorMax;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_StructureCurrent;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_StructureMax;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CapacitorCurrent;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CapacitorMax;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Velocity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Speed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxSpeed;
	static const UECodeGen_Private::FIntPropertyParams NewProp_LockedTargetsCount;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxLockedTargets;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Rotation;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ShipName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ShipType;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCommon_ShipDataStruct>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCommon_ShipDataStruct_Statics::NewProp_ShieldCurrent = { "ShieldCurrent", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ShipDataStruct, ShieldCurrent), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShieldCurrent_MetaData), NewProp_ShieldCurrent_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCommon_ShipDataStruct_Statics::NewProp_ShieldMax = { "ShieldMax", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ShipDataStruct, ShieldMax), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShieldMax_MetaData), NewProp_ShieldMax_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCommon_ShipDataStruct_Statics::NewProp_ArmorCurrent = { "ArmorCurrent", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ShipDataStruct, ArmorCurrent), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ArmorCurrent_MetaData), NewProp_ArmorCurrent_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCommon_ShipDataStruct_Statics::NewProp_ArmorMax = { "ArmorMax", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ShipDataStruct, ArmorMax), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ArmorMax_MetaData), NewProp_ArmorMax_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCommon_ShipDataStruct_Statics::NewProp_StructureCurrent = { "StructureCurrent", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ShipDataStruct, StructureCurrent), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StructureCurrent_MetaData), NewProp_StructureCurrent_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCommon_ShipDataStruct_Statics::NewProp_StructureMax = { "StructureMax", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ShipDataStruct, StructureMax), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StructureMax_MetaData), NewProp_StructureMax_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCommon_ShipDataStruct_Statics::NewProp_CapacitorCurrent = { "CapacitorCurrent", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ShipDataStruct, CapacitorCurrent), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CapacitorCurrent_MetaData), NewProp_CapacitorCurrent_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCommon_ShipDataStruct_Statics::NewProp_CapacitorMax = { "CapacitorMax", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ShipDataStruct, CapacitorMax), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CapacitorMax_MetaData), NewProp_CapacitorMax_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCommon_ShipDataStruct_Statics::NewProp_Velocity = { "Velocity", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ShipDataStruct, Velocity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Velocity_MetaData), NewProp_Velocity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCommon_ShipDataStruct_Statics::NewProp_Speed = { "Speed", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ShipDataStruct, Speed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Speed_MetaData), NewProp_Speed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCommon_ShipDataStruct_Statics::NewProp_MaxSpeed = { "MaxSpeed", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ShipDataStruct, MaxSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxSpeed_MetaData), NewProp_MaxSpeed_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FCommon_ShipDataStruct_Statics::NewProp_LockedTargetsCount = { "LockedTargetsCount", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ShipDataStruct, LockedTargetsCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LockedTargetsCount_MetaData), NewProp_LockedTargetsCount_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FCommon_ShipDataStruct_Statics::NewProp_MaxLockedTargets = { "MaxLockedTargets", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ShipDataStruct, MaxLockedTargets), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxLockedTargets_MetaData), NewProp_MaxLockedTargets_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCommon_ShipDataStruct_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ShipDataStruct, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Location_MetaData), NewProp_Location_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCommon_ShipDataStruct_Statics::NewProp_Rotation = { "Rotation", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ShipDataStruct, Rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rotation_MetaData), NewProp_Rotation_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FCommon_ShipDataStruct_Statics::NewProp_ShipName = { "ShipName", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ShipDataStruct, ShipName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShipName_MetaData), NewProp_ShipName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FCommon_ShipDataStruct_Statics::NewProp_ShipType = { "ShipType", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ShipDataStruct, ShipType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShipType_MetaData), NewProp_ShipType_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCommon_ShipDataStruct_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ShipDataStruct_Statics::NewProp_ShieldCurrent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ShipDataStruct_Statics::NewProp_ShieldMax,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ShipDataStruct_Statics::NewProp_ArmorCurrent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ShipDataStruct_Statics::NewProp_ArmorMax,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ShipDataStruct_Statics::NewProp_StructureCurrent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ShipDataStruct_Statics::NewProp_StructureMax,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ShipDataStruct_Statics::NewProp_CapacitorCurrent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ShipDataStruct_Statics::NewProp_CapacitorMax,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ShipDataStruct_Statics::NewProp_Velocity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ShipDataStruct_Statics::NewProp_Speed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ShipDataStruct_Statics::NewProp_MaxSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ShipDataStruct_Statics::NewProp_LockedTargetsCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ShipDataStruct_Statics::NewProp_MaxLockedTargets,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ShipDataStruct_Statics::NewProp_Location,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ShipDataStruct_Statics::NewProp_Rotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ShipDataStruct_Statics::NewProp_ShipName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ShipDataStruct_Statics::NewProp_ShipType,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCommon_ShipDataStruct_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCommon_ShipDataStruct_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"Common_ShipDataStruct",
	Z_Construct_UScriptStruct_FCommon_ShipDataStruct_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCommon_ShipDataStruct_Statics::PropPointers),
	sizeof(FCommon_ShipDataStruct),
	alignof(FCommon_ShipDataStruct),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCommon_ShipDataStruct_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FCommon_ShipDataStruct_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FCommon_ShipDataStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FCommon_ShipDataStruct.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FCommon_ShipDataStruct.InnerSingleton, Z_Construct_UScriptStruct_FCommon_ShipDataStruct_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FCommon_ShipDataStruct.InnerSingleton;
}
// ********** End ScriptStruct FCommon_ShipDataStruct **********************************************

// ********** Begin Interface UShipStateInterface Function GetCurrentTarget ************************
struct ShipStateInterface_eventGetCurrentTarget_Parms
{
	AActor* ReturnValue;

	/** Constructor, initializes return property only **/
	ShipStateInterface_eventGetCurrentTarget_Parms()
		: ReturnValue(NULL)
	{
	}
};
AActor* IShipStateInterface::GetCurrentTarget() const
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetCurrentTarget instead.");
	ShipStateInterface_eventGetCurrentTarget_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UShipStateInterface_GetCurrentTarget = FName(TEXT("GetCurrentTarget"));
AActor* IShipStateInterface::Execute_GetCurrentTarget(const UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UShipStateInterface::StaticClass()));
	ShipStateInterface_eventGetCurrentTarget_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UShipStateInterface_GetCurrentTarget);
	if (Func)
	{
		const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (const IShipStateInterface*)(O->GetNativeInterfaceAddress(UShipStateInterface::StaticClass())))
	{
		Parms.ReturnValue = I->GetCurrentTarget_Implementation();
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UShipStateInterface_GetCurrentTarget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ship State" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get ship's current target (if any)\n\x09 * \n\x09 * @return Currently targeted actor, or nullptr if none\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipStateInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get ship's current target (if any)\n\n@return Currently targeted actor, or nullptr if none" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UShipStateInterface_GetCurrentTarget_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStateInterface_eventGetCurrentTarget_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UShipStateInterface_GetCurrentTarget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStateInterface_GetCurrentTarget_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStateInterface_GetCurrentTarget_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShipStateInterface_GetCurrentTarget_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UShipStateInterface, nullptr, "GetCurrentTarget", Z_Construct_UFunction_UShipStateInterface_GetCurrentTarget_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStateInterface_GetCurrentTarget_Statics::PropPointers), sizeof(ShipStateInterface_eventGetCurrentTarget_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStateInterface_GetCurrentTarget_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShipStateInterface_GetCurrentTarget_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(ShipStateInterface_eventGetCurrentTarget_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UShipStateInterface_GetCurrentTarget()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShipStateInterface_GetCurrentTarget_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IShipStateInterface::execGetCurrentTarget)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AActor**)Z_Param__Result=P_THIS->GetCurrentTarget_Implementation();
	P_NATIVE_END;
}
// ********** End Interface UShipStateInterface Function GetCurrentTarget **************************

// ********** Begin Interface UShipStateInterface Function GetShipData *****************************
struct ShipStateInterface_eventGetShipData_Parms
{
	FCommon_ShipDataStruct ReturnValue;
};
FCommon_ShipDataStruct IShipStateInterface::GetShipData() const
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetShipData instead.");
	ShipStateInterface_eventGetShipData_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UShipStateInterface_GetShipData = FName(TEXT("GetShipData"));
FCommon_ShipDataStruct IShipStateInterface::Execute_GetShipData(const UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UShipStateInterface::StaticClass()));
	ShipStateInterface_eventGetShipData_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UShipStateInterface_GetShipData);
	if (Func)
	{
		const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (const IShipStateInterface*)(O->GetNativeInterfaceAddress(UShipStateInterface::StaticClass())))
	{
		Parms.ReturnValue = I->GetShipData_Implementation();
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UShipStateInterface_GetShipData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ship State" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get current ship data for HUD display\n\x09 * \n\x09 * @return Ship data structure with all relevant information\n\x09 * \n\x09 * Note: This is called frequently by HUD, should be lightweight\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipStateInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get current ship data for HUD display\n\n@return Ship data structure with all relevant information\n\nNote: This is called frequently by HUD, should be lightweight" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UShipStateInterface_GetShipData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStateInterface_eventGetShipData_Parms, ReturnValue), Z_Construct_UScriptStruct_FCommon_ShipDataStruct, METADATA_PARAMS(0, nullptr) }; // 4016673077
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UShipStateInterface_GetShipData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStateInterface_GetShipData_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStateInterface_GetShipData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShipStateInterface_GetShipData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UShipStateInterface, nullptr, "GetShipData", Z_Construct_UFunction_UShipStateInterface_GetShipData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStateInterface_GetShipData_Statics::PropPointers), sizeof(ShipStateInterface_eventGetShipData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStateInterface_GetShipData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShipStateInterface_GetShipData_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(ShipStateInterface_eventGetShipData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UShipStateInterface_GetShipData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShipStateInterface_GetShipData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IShipStateInterface::execGetShipData)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FCommon_ShipDataStruct*)Z_Param__Result=P_THIS->GetShipData_Implementation();
	P_NATIVE_END;
}
// ********** End Interface UShipStateInterface Function GetShipData *******************************

// ********** Begin Interface UShipStateInterface Function IsShipAlive *****************************
struct ShipStateInterface_eventIsShipAlive_Parms
{
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	ShipStateInterface_eventIsShipAlive_Parms()
		: ReturnValue(false)
	{
	}
};
bool IShipStateInterface::IsShipAlive() const
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_IsShipAlive instead.");
	ShipStateInterface_eventIsShipAlive_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UShipStateInterface_IsShipAlive = FName(TEXT("IsShipAlive"));
bool IShipStateInterface::Execute_IsShipAlive(const UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UShipStateInterface::StaticClass()));
	ShipStateInterface_eventIsShipAlive_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UShipStateInterface_IsShipAlive);
	if (Func)
	{
		const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (const IShipStateInterface*)(O->GetNativeInterfaceAddress(UShipStateInterface::StaticClass())))
	{
		Parms.ReturnValue = I->IsShipAlive_Implementation();
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UShipStateInterface_IsShipAlive_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ship State" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if ship is currently alive\n\x09 * \n\x09 * @return True if ship has structure > 0\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipStateInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if ship is currently alive\n\n@return True if ship has structure > 0" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UShipStateInterface_IsShipAlive_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ShipStateInterface_eventIsShipAlive_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UShipStateInterface_IsShipAlive_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ShipStateInterface_eventIsShipAlive_Parms), &Z_Construct_UFunction_UShipStateInterface_IsShipAlive_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UShipStateInterface_IsShipAlive_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStateInterface_IsShipAlive_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStateInterface_IsShipAlive_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShipStateInterface_IsShipAlive_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UShipStateInterface, nullptr, "IsShipAlive", Z_Construct_UFunction_UShipStateInterface_IsShipAlive_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStateInterface_IsShipAlive_Statics::PropPointers), sizeof(ShipStateInterface_eventIsShipAlive_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStateInterface_IsShipAlive_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShipStateInterface_IsShipAlive_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(ShipStateInterface_eventIsShipAlive_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UShipStateInterface_IsShipAlive()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShipStateInterface_IsShipAlive_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IShipStateInterface::execIsShipAlive)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsShipAlive_Implementation();
	P_NATIVE_END;
}
// ********** End Interface UShipStateInterface Function IsShipAlive *******************************

// ********** Begin Interface UShipStateInterface **************************************************
void UShipStateInterface::StaticRegisterNativesUShipStateInterface()
{
	UClass* Class = UShipStateInterface::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetCurrentTarget", &IShipStateInterface::execGetCurrentTarget },
		{ "GetShipData", &IShipStateInterface::execGetShipData },
		{ "IsShipAlive", &IShipStateInterface::execIsShipAlive },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UShipStateInterface;
UClass* UShipStateInterface::GetPrivateStaticClass()
{
	using TClass = UShipStateInterface;
	if (!Z_Registration_Info_UClass_UShipStateInterface.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ShipStateInterface"),
			Z_Registration_Info_UClass_UShipStateInterface.InnerSingleton,
			StaticRegisterNativesUShipStateInterface,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UShipStateInterface.InnerSingleton;
}
UClass* Z_Construct_UClass_UShipStateInterface_NoRegister()
{
	return UShipStateInterface::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UShipStateInterface_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipStateInterface.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UShipStateInterface_GetCurrentTarget, "GetCurrentTarget" }, // 1363691670
		{ &Z_Construct_UFunction_UShipStateInterface_GetShipData, "GetShipData" }, // 3768895107
		{ &Z_Construct_UFunction_UShipStateInterface_IsShipAlive, "IsShipAlive" }, // 128000946
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IShipStateInterface>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UShipStateInterface_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UShipStateInterface_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UShipStateInterface_Statics::ClassParams = {
	&UShipStateInterface::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x000840A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UShipStateInterface_Statics::Class_MetaDataParams), Z_Construct_UClass_UShipStateInterface_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UShipStateInterface()
{
	if (!Z_Registration_Info_UClass_UShipStateInterface.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UShipStateInterface.OuterSingleton, Z_Construct_UClass_UShipStateInterface_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UShipStateInterface.OuterSingleton;
}
UShipStateInterface::UShipStateInterface(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UShipStateInterface);
// ********** End Interface UShipStateInterface ****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipStateInterface_h__Script_Echoes_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FCommon_ShipDataStruct::StaticStruct, Z_Construct_UScriptStruct_FCommon_ShipDataStruct_Statics::NewStructOps, TEXT("Common_ShipDataStruct"), &Z_Registration_Info_UScriptStruct_FCommon_ShipDataStruct, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FCommon_ShipDataStruct), 4016673077U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UShipStateInterface, UShipStateInterface::StaticClass, TEXT("UShipStateInterface"), &Z_Registration_Info_UClass_UShipStateInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UShipStateInterface), 3284171369U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipStateInterface_h__Script_Echoes_647500270(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipStateInterface_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipStateInterface_h__Script_Echoes_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipStateInterface_h__Script_Echoes_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipStateInterface_h__Script_Echoes_Statics::ScriptStructInfo),
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
