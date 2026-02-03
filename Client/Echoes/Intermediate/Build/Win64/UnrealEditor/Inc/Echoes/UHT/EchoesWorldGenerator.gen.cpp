// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EchoesWorldGenerator.h"
#include "EchoesServerDiscoveryTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesWorldGenerator() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ECHOES_API UClass* Z_Construct_UClass_AAnomalyActor_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_AAsteroidBeltActor_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_AEchoesWorldGenerator();
ECHOES_API UClass* Z_Construct_UClass_AEchoesWorldGenerator_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_AMoonActor_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_APlanetActor_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_AStarActor_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_AStargateActor_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_AStationActor_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_AWormholeActor_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UEchoesServerManagementSubsystem_NoRegister();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FServerRegionalClusterConfig();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FServerSystemConfig();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UDataTable_NoRegister();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AEchoesWorldGenerator Function CalculateSystemGlobalOffset ***************
struct Z_Construct_UFunction_AEchoesWorldGenerator_CalculateSystemGlobalOffset_Statics
{
	struct EchoesWorldGenerator_eventCalculateSystemGlobalOffset_Parms
	{
		int64 PosX;
		int64 PosY;
		int64 PosZ;
		FVector ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generation|Helpers" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Calculate global offset for a system based on its DB coordinates\n\x09 * Uses RegionDistanceScale to separate systems by billions of units\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/World/EchoesWorldGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Calculate global offset for a system based on its DB coordinates\nUses RegionDistanceScale to separate systems by billions of units" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FInt64PropertyParams NewProp_PosX;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_PosY;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_PosZ;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_AEchoesWorldGenerator_CalculateSystemGlobalOffset_Statics::NewProp_PosX = { "PosX", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesWorldGenerator_eventCalculateSystemGlobalOffset_Parms, PosX), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_AEchoesWorldGenerator_CalculateSystemGlobalOffset_Statics::NewProp_PosY = { "PosY", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesWorldGenerator_eventCalculateSystemGlobalOffset_Parms, PosY), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_AEchoesWorldGenerator_CalculateSystemGlobalOffset_Statics::NewProp_PosZ = { "PosZ", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesWorldGenerator_eventCalculateSystemGlobalOffset_Parms, PosZ), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEchoesWorldGenerator_CalculateSystemGlobalOffset_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesWorldGenerator_eventCalculateSystemGlobalOffset_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesWorldGenerator_CalculateSystemGlobalOffset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesWorldGenerator_CalculateSystemGlobalOffset_Statics::NewProp_PosX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesWorldGenerator_CalculateSystemGlobalOffset_Statics::NewProp_PosY,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesWorldGenerator_CalculateSystemGlobalOffset_Statics::NewProp_PosZ,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesWorldGenerator_CalculateSystemGlobalOffset_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWorldGenerator_CalculateSystemGlobalOffset_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesWorldGenerator_CalculateSystemGlobalOffset_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesWorldGenerator, nullptr, "CalculateSystemGlobalOffset", Z_Construct_UFunction_AEchoesWorldGenerator_CalculateSystemGlobalOffset_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWorldGenerator_CalculateSystemGlobalOffset_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesWorldGenerator_CalculateSystemGlobalOffset_Statics::EchoesWorldGenerator_eventCalculateSystemGlobalOffset_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54880401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWorldGenerator_CalculateSystemGlobalOffset_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesWorldGenerator_CalculateSystemGlobalOffset_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesWorldGenerator_CalculateSystemGlobalOffset_Statics::EchoesWorldGenerator_eventCalculateSystemGlobalOffset_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesWorldGenerator_CalculateSystemGlobalOffset()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesWorldGenerator_CalculateSystemGlobalOffset_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesWorldGenerator::execCalculateSystemGlobalOffset)
{
	P_GET_PROPERTY(FInt64Property,Z_Param_PosX);
	P_GET_PROPERTY(FInt64Property,Z_Param_PosY);
	P_GET_PROPERTY(FInt64Property,Z_Param_PosZ);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector*)Z_Param__Result=P_THIS->CalculateSystemGlobalOffset(Z_Param_PosX,Z_Param_PosY,Z_Param_PosZ);
	P_NATIVE_END;
}
// ********** End Class AEchoesWorldGenerator Function CalculateSystemGlobalOffset *****************

// ********** Begin Class AEchoesWorldGenerator Function ConvertCoordinates ************************
struct Z_Construct_UFunction_AEchoesWorldGenerator_ConvertCoordinates_Statics
{
	struct EchoesWorldGenerator_eventConvertCoordinates_Parms
	{
		int64 X;
		int64 Y;
		int64 Z;
		FVector ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generation|Helpers" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Convert database coordinates (km) to Unreal world coordinates (cm)\n\x09 * Note: This is for objects WITHIN a system, not system positions\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/World/EchoesWorldGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Convert database coordinates (km) to Unreal world coordinates (cm)\nNote: This is for objects WITHIN a system, not system positions" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FInt64PropertyParams NewProp_X;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_Y;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_Z;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_AEchoesWorldGenerator_ConvertCoordinates_Statics::NewProp_X = { "X", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesWorldGenerator_eventConvertCoordinates_Parms, X), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_AEchoesWorldGenerator_ConvertCoordinates_Statics::NewProp_Y = { "Y", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesWorldGenerator_eventConvertCoordinates_Parms, Y), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_AEchoesWorldGenerator_ConvertCoordinates_Statics::NewProp_Z = { "Z", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesWorldGenerator_eventConvertCoordinates_Parms, Z), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEchoesWorldGenerator_ConvertCoordinates_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesWorldGenerator_eventConvertCoordinates_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesWorldGenerator_ConvertCoordinates_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesWorldGenerator_ConvertCoordinates_Statics::NewProp_X,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesWorldGenerator_ConvertCoordinates_Statics::NewProp_Y,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesWorldGenerator_ConvertCoordinates_Statics::NewProp_Z,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesWorldGenerator_ConvertCoordinates_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWorldGenerator_ConvertCoordinates_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesWorldGenerator_ConvertCoordinates_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesWorldGenerator, nullptr, "ConvertCoordinates", Z_Construct_UFunction_AEchoesWorldGenerator_ConvertCoordinates_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWorldGenerator_ConvertCoordinates_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesWorldGenerator_ConvertCoordinates_Statics::EchoesWorldGenerator_eventConvertCoordinates_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54880401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWorldGenerator_ConvertCoordinates_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesWorldGenerator_ConvertCoordinates_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesWorldGenerator_ConvertCoordinates_Statics::EchoesWorldGenerator_eventConvertCoordinates_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesWorldGenerator_ConvertCoordinates()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesWorldGenerator_ConvertCoordinates_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesWorldGenerator::execConvertCoordinates)
{
	P_GET_PROPERTY(FInt64Property,Z_Param_X);
	P_GET_PROPERTY(FInt64Property,Z_Param_Y);
	P_GET_PROPERTY(FInt64Property,Z_Param_Z);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector*)Z_Param__Result=P_THIS->ConvertCoordinates(Z_Param_X,Z_Param_Y,Z_Param_Z);
	P_NATIVE_END;
}
// ********** End Class AEchoesWorldGenerator Function ConvertCoordinates **************************

// ********** Begin Class AEchoesWorldGenerator Function GetSystemGlobalOffset *********************
struct Z_Construct_UFunction_AEchoesWorldGenerator_GetSystemGlobalOffset_Statics
{
	struct EchoesWorldGenerator_eventGetSystemGlobalOffset_Parms
	{
		FGuid SystemId;
		FVector ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generation|RegionalCluster" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the global offset for a specific system\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/World/EchoesWorldGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the global offset for a specific system" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SystemId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_SystemId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEchoesWorldGenerator_GetSystemGlobalOffset_Statics::NewProp_SystemId = { "SystemId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesWorldGenerator_eventGetSystemGlobalOffset_Parms, SystemId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SystemId_MetaData), NewProp_SystemId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEchoesWorldGenerator_GetSystemGlobalOffset_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesWorldGenerator_eventGetSystemGlobalOffset_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesWorldGenerator_GetSystemGlobalOffset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesWorldGenerator_GetSystemGlobalOffset_Statics::NewProp_SystemId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesWorldGenerator_GetSystemGlobalOffset_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWorldGenerator_GetSystemGlobalOffset_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesWorldGenerator_GetSystemGlobalOffset_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesWorldGenerator, nullptr, "GetSystemGlobalOffset", Z_Construct_UFunction_AEchoesWorldGenerator_GetSystemGlobalOffset_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWorldGenerator_GetSystemGlobalOffset_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesWorldGenerator_GetSystemGlobalOffset_Statics::EchoesWorldGenerator_eventGetSystemGlobalOffset_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWorldGenerator_GetSystemGlobalOffset_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesWorldGenerator_GetSystemGlobalOffset_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesWorldGenerator_GetSystemGlobalOffset_Statics::EchoesWorldGenerator_eventGetSystemGlobalOffset_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesWorldGenerator_GetSystemGlobalOffset()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesWorldGenerator_GetSystemGlobalOffset_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesWorldGenerator::execGetSystemGlobalOffset)
{
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_SystemId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector*)Z_Param__Result=P_THIS->GetSystemGlobalOffset(Z_Param_Out_SystemId);
	P_NATIVE_END;
}
// ********** End Class AEchoesWorldGenerator Function GetSystemGlobalOffset ***********************

// ********** Begin Class AEchoesWorldGenerator Function IsRegionalCluster *************************
struct Z_Construct_UFunction_AEchoesWorldGenerator_IsRegionalCluster_Statics
{
	struct EchoesWorldGenerator_eventIsRegionalCluster_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generation|RegionalCluster" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if this is a regional cluster server\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/World/EchoesWorldGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if this is a regional cluster server" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_AEchoesWorldGenerator_IsRegionalCluster_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((EchoesWorldGenerator_eventIsRegionalCluster_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AEchoesWorldGenerator_IsRegionalCluster_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EchoesWorldGenerator_eventIsRegionalCluster_Parms), &Z_Construct_UFunction_AEchoesWorldGenerator_IsRegionalCluster_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesWorldGenerator_IsRegionalCluster_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesWorldGenerator_IsRegionalCluster_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWorldGenerator_IsRegionalCluster_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesWorldGenerator_IsRegionalCluster_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesWorldGenerator, nullptr, "IsRegionalCluster", Z_Construct_UFunction_AEchoesWorldGenerator_IsRegionalCluster_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWorldGenerator_IsRegionalCluster_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesWorldGenerator_IsRegionalCluster_Statics::EchoesWorldGenerator_eventIsRegionalCluster_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWorldGenerator_IsRegionalCluster_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesWorldGenerator_IsRegionalCluster_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesWorldGenerator_IsRegionalCluster_Statics::EchoesWorldGenerator_eventIsRegionalCluster_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesWorldGenerator_IsRegionalCluster()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesWorldGenerator_IsRegionalCluster_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesWorldGenerator::execIsRegionalCluster)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsRegionalCluster();
	P_NATIVE_END;
}
// ********** End Class AEchoesWorldGenerator Function IsRegionalCluster ***************************

// ********** Begin Class AEchoesWorldGenerator Function IsSystemOnThisServer **********************
struct Z_Construct_UFunction_AEchoesWorldGenerator_IsSystemOnThisServer_Statics
{
	struct EchoesWorldGenerator_eventIsSystemOnThisServer_Parms
	{
		FGuid SystemId;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generation|RegionalCluster" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if a system ID is hosted on this server\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/World/EchoesWorldGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if a system ID is hosted on this server" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SystemId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_SystemId;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEchoesWorldGenerator_IsSystemOnThisServer_Statics::NewProp_SystemId = { "SystemId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesWorldGenerator_eventIsSystemOnThisServer_Parms, SystemId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SystemId_MetaData), NewProp_SystemId_MetaData) };
void Z_Construct_UFunction_AEchoesWorldGenerator_IsSystemOnThisServer_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((EchoesWorldGenerator_eventIsSystemOnThisServer_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AEchoesWorldGenerator_IsSystemOnThisServer_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EchoesWorldGenerator_eventIsSystemOnThisServer_Parms), &Z_Construct_UFunction_AEchoesWorldGenerator_IsSystemOnThisServer_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesWorldGenerator_IsSystemOnThisServer_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesWorldGenerator_IsSystemOnThisServer_Statics::NewProp_SystemId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesWorldGenerator_IsSystemOnThisServer_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWorldGenerator_IsSystemOnThisServer_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesWorldGenerator_IsSystemOnThisServer_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesWorldGenerator, nullptr, "IsSystemOnThisServer", Z_Construct_UFunction_AEchoesWorldGenerator_IsSystemOnThisServer_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWorldGenerator_IsSystemOnThisServer_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesWorldGenerator_IsSystemOnThisServer_Statics::EchoesWorldGenerator_eventIsSystemOnThisServer_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWorldGenerator_IsSystemOnThisServer_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesWorldGenerator_IsSystemOnThisServer_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesWorldGenerator_IsSystemOnThisServer_Statics::EchoesWorldGenerator_eventIsSystemOnThisServer_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesWorldGenerator_IsSystemOnThisServer()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesWorldGenerator_IsSystemOnThisServer_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesWorldGenerator::execIsSystemOnThisServer)
{
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_SystemId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsSystemOnThisServer(Z_Param_Out_SystemId);
	P_NATIVE_END;
}
// ********** End Class AEchoesWorldGenerator Function IsSystemOnThisServer ************************

// ********** Begin Class AEchoesWorldGenerator Function OnRegionalClusterConfigReceived ***********
struct Z_Construct_UFunction_AEchoesWorldGenerator_OnRegionalClusterConfigReceived_Statics
{
	struct EchoesWorldGenerator_eventOnRegionalClusterConfigReceived_Parms
	{
		FServerRegionalClusterConfig RegionalConfig;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Called when regional cluster configuration is received from backend\n\x09 * Triggers multi-system world generation (RegionalCluster mode)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/World/EchoesWorldGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when regional cluster configuration is received from backend\nTriggers multi-system world generation (RegionalCluster mode)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RegionalConfig_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_RegionalConfig;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEchoesWorldGenerator_OnRegionalClusterConfigReceived_Statics::NewProp_RegionalConfig = { "RegionalConfig", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesWorldGenerator_eventOnRegionalClusterConfigReceived_Parms, RegionalConfig), Z_Construct_UScriptStruct_FServerRegionalClusterConfig, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RegionalConfig_MetaData), NewProp_RegionalConfig_MetaData) }; // 3659141395
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesWorldGenerator_OnRegionalClusterConfigReceived_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesWorldGenerator_OnRegionalClusterConfigReceived_Statics::NewProp_RegionalConfig,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWorldGenerator_OnRegionalClusterConfigReceived_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesWorldGenerator_OnRegionalClusterConfigReceived_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesWorldGenerator, nullptr, "OnRegionalClusterConfigReceived", Z_Construct_UFunction_AEchoesWorldGenerator_OnRegionalClusterConfigReceived_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWorldGenerator_OnRegionalClusterConfigReceived_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesWorldGenerator_OnRegionalClusterConfigReceived_Statics::EchoesWorldGenerator_eventOnRegionalClusterConfigReceived_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00480401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWorldGenerator_OnRegionalClusterConfigReceived_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesWorldGenerator_OnRegionalClusterConfigReceived_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesWorldGenerator_OnRegionalClusterConfigReceived_Statics::EchoesWorldGenerator_eventOnRegionalClusterConfigReceived_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesWorldGenerator_OnRegionalClusterConfigReceived()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesWorldGenerator_OnRegionalClusterConfigReceived_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesWorldGenerator::execOnRegionalClusterConfigReceived)
{
	P_GET_STRUCT_REF(FServerRegionalClusterConfig,Z_Param_Out_RegionalConfig);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRegionalClusterConfigReceived(Z_Param_Out_RegionalConfig);
	P_NATIVE_END;
}
// ********** End Class AEchoesWorldGenerator Function OnRegionalClusterConfigReceived *************

// ********** Begin Class AEchoesWorldGenerator Function OnServerConfigReceived ********************
struct Z_Construct_UFunction_AEchoesWorldGenerator_OnServerConfigReceived_Statics
{
	struct EchoesWorldGenerator_eventOnServerConfigReceived_Parms
	{
		FServerSystemConfig Config;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Called when server configuration is received from backend\n\x09 * Triggers world generation process (DedicatedSystem mode)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/World/EchoesWorldGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when server configuration is received from backend\nTriggers world generation process (DedicatedSystem mode)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Config_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Config;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEchoesWorldGenerator_OnServerConfigReceived_Statics::NewProp_Config = { "Config", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesWorldGenerator_eventOnServerConfigReceived_Parms, Config), Z_Construct_UScriptStruct_FServerSystemConfig, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Config_MetaData), NewProp_Config_MetaData) }; // 1674105224
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesWorldGenerator_OnServerConfigReceived_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesWorldGenerator_OnServerConfigReceived_Statics::NewProp_Config,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWorldGenerator_OnServerConfigReceived_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesWorldGenerator_OnServerConfigReceived_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesWorldGenerator, nullptr, "OnServerConfigReceived", Z_Construct_UFunction_AEchoesWorldGenerator_OnServerConfigReceived_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWorldGenerator_OnServerConfigReceived_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesWorldGenerator_OnServerConfigReceived_Statics::EchoesWorldGenerator_eventOnServerConfigReceived_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00480401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWorldGenerator_OnServerConfigReceived_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesWorldGenerator_OnServerConfigReceived_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesWorldGenerator_OnServerConfigReceived_Statics::EchoesWorldGenerator_eventOnServerConfigReceived_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesWorldGenerator_OnServerConfigReceived()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesWorldGenerator_OnServerConfigReceived_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesWorldGenerator::execOnServerConfigReceived)
{
	P_GET_STRUCT_REF(FServerSystemConfig,Z_Param_Out_Config);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnServerConfigReceived(Z_Param_Out_Config);
	P_NATIVE_END;
}
// ********** End Class AEchoesWorldGenerator Function OnServerConfigReceived **********************

// ********** Begin Class AEchoesWorldGenerator Function ServerOnly_ClearWorld *********************
struct Z_Construct_UFunction_AEchoesWorldGenerator_ServerOnly_ClearWorld_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Clear all spawned actors\n\x09 */" },
#endif
		{ "DevelopmentOnly", "" },
		{ "ModuleRelativePath", "Core/Common/World/EchoesWorldGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Clear all spawned actors" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesWorldGenerator_ServerOnly_ClearWorld_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesWorldGenerator, nullptr, "ServerOnly_ClearWorld", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWorldGenerator_ServerOnly_ClearWorld_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesWorldGenerator_ServerOnly_ClearWorld_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AEchoesWorldGenerator_ServerOnly_ClearWorld()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesWorldGenerator_ServerOnly_ClearWorld_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesWorldGenerator::execServerOnly_ClearWorld)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerOnly_ClearWorld();
	P_NATIVE_END;
}
// ********** End Class AEchoesWorldGenerator Function ServerOnly_ClearWorld ***********************

// ********** Begin Class AEchoesWorldGenerator Function ServerOnly_GenerateRegionalCluster ********
struct Z_Construct_UFunction_AEchoesWorldGenerator_ServerOnly_GenerateRegionalCluster_Statics
{
	struct EchoesWorldGenerator_eventServerOnly_GenerateRegionalCluster_Parms
	{
		FServerRegionalClusterConfig RegionalConfig;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Manual trigger for regional cluster world generation (for testing)\n\x09 * In production, this is called automatically via OnRegionalClusterConfigReceived\n\x09 */" },
#endif
		{ "DevelopmentOnly", "" },
		{ "ModuleRelativePath", "Core/Common/World/EchoesWorldGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Manual trigger for regional cluster world generation (for testing)\nIn production, this is called automatically via OnRegionalClusterConfigReceived" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RegionalConfig_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_RegionalConfig;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEchoesWorldGenerator_ServerOnly_GenerateRegionalCluster_Statics::NewProp_RegionalConfig = { "RegionalConfig", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesWorldGenerator_eventServerOnly_GenerateRegionalCluster_Parms, RegionalConfig), Z_Construct_UScriptStruct_FServerRegionalClusterConfig, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RegionalConfig_MetaData), NewProp_RegionalConfig_MetaData) }; // 3659141395
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesWorldGenerator_ServerOnly_GenerateRegionalCluster_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesWorldGenerator_ServerOnly_GenerateRegionalCluster_Statics::NewProp_RegionalConfig,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWorldGenerator_ServerOnly_GenerateRegionalCluster_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesWorldGenerator_ServerOnly_GenerateRegionalCluster_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesWorldGenerator, nullptr, "ServerOnly_GenerateRegionalCluster", Z_Construct_UFunction_AEchoesWorldGenerator_ServerOnly_GenerateRegionalCluster_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWorldGenerator_ServerOnly_GenerateRegionalCluster_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesWorldGenerator_ServerOnly_GenerateRegionalCluster_Statics::EchoesWorldGenerator_eventServerOnly_GenerateRegionalCluster_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWorldGenerator_ServerOnly_GenerateRegionalCluster_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesWorldGenerator_ServerOnly_GenerateRegionalCluster_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesWorldGenerator_ServerOnly_GenerateRegionalCluster_Statics::EchoesWorldGenerator_eventServerOnly_GenerateRegionalCluster_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesWorldGenerator_ServerOnly_GenerateRegionalCluster()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesWorldGenerator_ServerOnly_GenerateRegionalCluster_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesWorldGenerator::execServerOnly_GenerateRegionalCluster)
{
	P_GET_STRUCT_REF(FServerRegionalClusterConfig,Z_Param_Out_RegionalConfig);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerOnly_GenerateRegionalCluster(Z_Param_Out_RegionalConfig);
	P_NATIVE_END;
}
// ********** End Class AEchoesWorldGenerator Function ServerOnly_GenerateRegionalCluster **********

// ********** Begin Class AEchoesWorldGenerator Function ServerOnly_GenerateWorld ******************
struct Z_Construct_UFunction_AEchoesWorldGenerator_ServerOnly_GenerateWorld_Statics
{
	struct EchoesWorldGenerator_eventServerOnly_GenerateWorld_Parms
	{
		FServerSystemConfig Config;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Manual trigger for world generation (for testing)\n\x09 * In production, this is called automatically via OnServerConfigReceived\n\x09 */" },
#endif
		{ "DevelopmentOnly", "" },
		{ "ModuleRelativePath", "Core/Common/World/EchoesWorldGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Manual trigger for world generation (for testing)\nIn production, this is called automatically via OnServerConfigReceived" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Config_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Config;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEchoesWorldGenerator_ServerOnly_GenerateWorld_Statics::NewProp_Config = { "Config", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesWorldGenerator_eventServerOnly_GenerateWorld_Parms, Config), Z_Construct_UScriptStruct_FServerSystemConfig, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Config_MetaData), NewProp_Config_MetaData) }; // 1674105224
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesWorldGenerator_ServerOnly_GenerateWorld_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesWorldGenerator_ServerOnly_GenerateWorld_Statics::NewProp_Config,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWorldGenerator_ServerOnly_GenerateWorld_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesWorldGenerator_ServerOnly_GenerateWorld_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesWorldGenerator, nullptr, "ServerOnly_GenerateWorld", Z_Construct_UFunction_AEchoesWorldGenerator_ServerOnly_GenerateWorld_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWorldGenerator_ServerOnly_GenerateWorld_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesWorldGenerator_ServerOnly_GenerateWorld_Statics::EchoesWorldGenerator_eventServerOnly_GenerateWorld_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWorldGenerator_ServerOnly_GenerateWorld_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesWorldGenerator_ServerOnly_GenerateWorld_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesWorldGenerator_ServerOnly_GenerateWorld_Statics::EchoesWorldGenerator_eventServerOnly_GenerateWorld_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesWorldGenerator_ServerOnly_GenerateWorld()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesWorldGenerator_ServerOnly_GenerateWorld_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesWorldGenerator::execServerOnly_GenerateWorld)
{
	P_GET_STRUCT_REF(FServerSystemConfig,Z_Param_Out_Config);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerOnly_GenerateWorld(Z_Param_Out_Config);
	P_NATIVE_END;
}
// ********** End Class AEchoesWorldGenerator Function ServerOnly_GenerateWorld ********************

// ********** Begin Class AEchoesWorldGenerator ****************************************************
void AEchoesWorldGenerator::StaticRegisterNativesAEchoesWorldGenerator()
{
	UClass* Class = AEchoesWorldGenerator::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "CalculateSystemGlobalOffset", &AEchoesWorldGenerator::execCalculateSystemGlobalOffset },
		{ "ConvertCoordinates", &AEchoesWorldGenerator::execConvertCoordinates },
		{ "GetSystemGlobalOffset", &AEchoesWorldGenerator::execGetSystemGlobalOffset },
		{ "IsRegionalCluster", &AEchoesWorldGenerator::execIsRegionalCluster },
		{ "IsSystemOnThisServer", &AEchoesWorldGenerator::execIsSystemOnThisServer },
		{ "OnRegionalClusterConfigReceived", &AEchoesWorldGenerator::execOnRegionalClusterConfigReceived },
		{ "OnServerConfigReceived", &AEchoesWorldGenerator::execOnServerConfigReceived },
		{ "ServerOnly_ClearWorld", &AEchoesWorldGenerator::execServerOnly_ClearWorld },
		{ "ServerOnly_GenerateRegionalCluster", &AEchoesWorldGenerator::execServerOnly_GenerateRegionalCluster },
		{ "ServerOnly_GenerateWorld", &AEchoesWorldGenerator::execServerOnly_GenerateWorld },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_AEchoesWorldGenerator;
UClass* AEchoesWorldGenerator::GetPrivateStaticClass()
{
	using TClass = AEchoesWorldGenerator;
	if (!Z_Registration_Info_UClass_AEchoesWorldGenerator.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesWorldGenerator"),
			Z_Registration_Info_UClass_AEchoesWorldGenerator.InnerSingleton,
			StaticRegisterNativesAEchoesWorldGenerator,
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
	return Z_Registration_Info_UClass_AEchoesWorldGenerator.InnerSingleton;
}
UClass* Z_Construct_UClass_AEchoesWorldGenerator_NoRegister()
{
	return AEchoesWorldGenerator::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AEchoesWorldGenerator_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * AEchoesWorldGenerator\n * \n * Master world generation system for Echoes universe\n * Builds solar systems based on JSON configuration from backend\n * \n * Architecture:\n * - Subscribes to OnServerConfigReceived delegate from UEchoesServerManagementSubsystem\n * - Server-only generation (HasAuthority())\n * - Uses Data Tables for visual asset mapping\n * - Implements coordinate scaling (UniverseToWorldScale)\n * - Async asset loading with UStreamableManager\n * - Seed-based procedural variation\n * - Full replication support\n * \n * Workflow:\n * 1. BeginPlay: Subscribe to OnServerConfigReceived\n * 2. OnConfigReceived: Parse configuration and spawn celestial objects\n * 3. For each object:\n *    - Look up visual data in corresponding DataTable\n *    - Convert coordinates using UniverseToWorldScale\n *    - Spawn replicated actor\n *    - Initialize with configuration data\n */" },
#endif
		{ "IncludePath", "Core/Common/World/EchoesWorldGenerator.h" },
		{ "ModuleRelativePath", "Core/Common/World/EchoesWorldGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "AEchoesWorldGenerator\n\nMaster world generation system for Echoes universe\nBuilds solar systems based on JSON configuration from backend\n\nArchitecture:\n- Subscribes to OnServerConfigReceived delegate from UEchoesServerManagementSubsystem\n- Server-only generation (HasAuthority())\n- Uses Data Tables for visual asset mapping\n- Implements coordinate scaling (UniverseToWorldScale)\n- Async asset loading with UStreamableManager\n- Seed-based procedural variation\n- Full replication support\n\nWorkflow:\n1. BeginPlay: Subscribe to OnServerConfigReceived\n2. OnConfigReceived: Parse configuration and spawn celestial objects\n3. For each object:\n   - Look up visual data in corresponding DataTable\n   - Convert coordinates using UniverseToWorldScale\n   - Spawn replicated actor\n   - Initialize with configuration data" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UniverseToWorldScale_MetaData[] = {
		{ "Category", "Generation|Scale" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Universe to World Scale Constant\n\x09 * Converts database coordinates (km or AU) to Unreal Units (cm)\n\x09 * \n\x09 * Default: 1 km = 0.0001 * 100000 cm = 10 cm (1:10,000,000 scale)\n\x09 * This prevents floating-point precision issues at astronomical distances\n\x09 * \n\x09 * IMPORTANT: ConvertCoordinates uses DOUBLE PRECISION to avoid jitter\n\x09 * \n\x09 * Example: Planet at 150,000,000 km (1 AU) -> 1,500,000,000 cm (15,000 km) in Unreal\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/World/EchoesWorldGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Universe to World Scale Constant\nConverts database coordinates (km or AU) to Unreal Units (cm)\n\nDefault: 1 km = 0.0001 * 100000 cm = 10 cm (1:10,000,000 scale)\nThis prevents floating-point precision issues at astronomical distances\n\nIMPORTANT: ConvertCoordinates uses DOUBLE PRECISION to avoid jitter\n\nExample: Planet at 150,000,000 km (1 AU) -> 1,500,000,000 cm (15,000 km) in Unreal" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RegionDistanceScale_MetaData[] = {
		{ "Category", "Generation|Scale" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Regional distance scale for separating multiple systems\n\x09 * Each system gets offset by its DB coordinates * this scale\n\x09 * \n\x09 * Default: 1,000,000,000 (1 billion units)\n\x09 * Prevents visual and physics interference between systems\n\x09 * Supports Large World Coordinates (LWC) with double precision\n\x09 * \n\x09 * Example: System at DB coords (10, 0, 0) -> offset (10B, 0, 0) Unreal Units\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/World/EchoesWorldGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Regional distance scale for separating multiple systems\nEach system gets offset by its DB coordinates * this scale\n\nDefault: 1,000,000,000 (1 billion units)\nPrevents visual and physics interference between systems\nSupports Large World Coordinates (LWC) with double precision\n\nExample: System at DB coords (10, 0, 0) -> offset (10B, 0, 0) Unreal Units" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlanetDataTable_MetaData[] = {
		{ "Category", "Generation|DataTables" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Data Tables for visual asset mapping\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/World/EchoesWorldGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Data Tables for visual asset mapping" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StarDataTable_MetaData[] = {
		{ "Category", "Generation|DataTables" },
		{ "ModuleRelativePath", "Core/Common/World/EchoesWorldGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StationDataTable_MetaData[] = {
		{ "Category", "Generation|DataTables" },
		{ "ModuleRelativePath", "Core/Common/World/EchoesWorldGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StargateDataTable_MetaData[] = {
		{ "Category", "Generation|DataTables" },
		{ "ModuleRelativePath", "Core/Common/World/EchoesWorldGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AsteroidBeltDataTable_MetaData[] = {
		{ "Category", "Generation|DataTables" },
		{ "ModuleRelativePath", "Core/Common/World/EchoesWorldGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AnomalyDataTable_MetaData[] = {
		{ "Category", "Generation|DataTables" },
		{ "ModuleRelativePath", "Core/Common/World/EchoesWorldGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WormholeDataTable_MetaData[] = {
		{ "Category", "Generation|DataTables" },
		{ "ModuleRelativePath", "Core/Common/World/EchoesWorldGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoonDataTable_MetaData[] = {
		{ "Category", "Generation|DataTables" },
		{ "ModuleRelativePath", "Core/Common/World/EchoesWorldGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlanetActorClass_MetaData[] = {
		{ "Category", "Generation|ActorClasses" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Actor classes to spawn\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/World/EchoesWorldGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Actor classes to spawn" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoonActorClass_MetaData[] = {
		{ "Category", "Generation|ActorClasses" },
		{ "ModuleRelativePath", "Core/Common/World/EchoesWorldGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StarActorClass_MetaData[] = {
		{ "Category", "Generation|ActorClasses" },
		{ "ModuleRelativePath", "Core/Common/World/EchoesWorldGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StationActorClass_MetaData[] = {
		{ "Category", "Generation|ActorClasses" },
		{ "ModuleRelativePath", "Core/Common/World/EchoesWorldGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StargateActorClass_MetaData[] = {
		{ "Category", "Generation|ActorClasses" },
		{ "ModuleRelativePath", "Core/Common/World/EchoesWorldGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AsteroidBeltActorClass_MetaData[] = {
		{ "Category", "Generation|ActorClasses" },
		{ "ModuleRelativePath", "Core/Common/World/EchoesWorldGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AnomalyActorClass_MetaData[] = {
		{ "Category", "Generation|ActorClasses" },
		{ "ModuleRelativePath", "Core/Common/World/EchoesWorldGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WormholeActorClass_MetaData[] = {
		{ "Category", "Generation|ActorClasses" },
		{ "ModuleRelativePath", "Core/Common/World/EchoesWorldGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnedActors_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ==================== Spawned Actors Tracking ====================\n" },
#endif
		{ "ModuleRelativePath", "Core/Common/World/EchoesWorldGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "==================== Spawned Actors Tracking ====================" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ServerManagementSubsystem_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Reference to server management subsystem */" },
#endif
		{ "ModuleRelativePath", "Core/Common/World/EchoesWorldGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Reference to server management subsystem" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_UniverseToWorldScale;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_RegionDistanceScale;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlanetDataTable;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StarDataTable;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StationDataTable;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StargateDataTable;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AsteroidBeltDataTable;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AnomalyDataTable;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WormholeDataTable;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MoonDataTable;
	static const UECodeGen_Private::FClassPropertyParams NewProp_PlanetActorClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_MoonActorClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_StarActorClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_StationActorClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_StargateActorClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_AsteroidBeltActorClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_AnomalyActorClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_WormholeActorClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpawnedActors_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_SpawnedActors;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ServerManagementSubsystem;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AEchoesWorldGenerator_CalculateSystemGlobalOffset, "CalculateSystemGlobalOffset" }, // 813554391
		{ &Z_Construct_UFunction_AEchoesWorldGenerator_ConvertCoordinates, "ConvertCoordinates" }, // 1536993781
		{ &Z_Construct_UFunction_AEchoesWorldGenerator_GetSystemGlobalOffset, "GetSystemGlobalOffset" }, // 569495849
		{ &Z_Construct_UFunction_AEchoesWorldGenerator_IsRegionalCluster, "IsRegionalCluster" }, // 3799502681
		{ &Z_Construct_UFunction_AEchoesWorldGenerator_IsSystemOnThisServer, "IsSystemOnThisServer" }, // 1455589772
		{ &Z_Construct_UFunction_AEchoesWorldGenerator_OnRegionalClusterConfigReceived, "OnRegionalClusterConfigReceived" }, // 977793651
		{ &Z_Construct_UFunction_AEchoesWorldGenerator_OnServerConfigReceived, "OnServerConfigReceived" }, // 2692976101
		{ &Z_Construct_UFunction_AEchoesWorldGenerator_ServerOnly_ClearWorld, "ServerOnly_ClearWorld" }, // 2369405539
		{ &Z_Construct_UFunction_AEchoesWorldGenerator_ServerOnly_GenerateRegionalCluster, "ServerOnly_GenerateRegionalCluster" }, // 2905640590
		{ &Z_Construct_UFunction_AEchoesWorldGenerator_ServerOnly_GenerateWorld, "ServerOnly_GenerateWorld" }, // 944296355
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEchoesWorldGenerator>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEchoesWorldGenerator_Statics::NewProp_UniverseToWorldScale = { "UniverseToWorldScale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesWorldGenerator, UniverseToWorldScale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UniverseToWorldScale_MetaData), NewProp_UniverseToWorldScale_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_AEchoesWorldGenerator_Statics::NewProp_RegionDistanceScale = { "RegionDistanceScale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesWorldGenerator, RegionDistanceScale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RegionDistanceScale_MetaData), NewProp_RegionDistanceScale_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEchoesWorldGenerator_Statics::NewProp_PlanetDataTable = { "PlanetDataTable", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesWorldGenerator, PlanetDataTable), Z_Construct_UClass_UDataTable_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlanetDataTable_MetaData), NewProp_PlanetDataTable_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEchoesWorldGenerator_Statics::NewProp_StarDataTable = { "StarDataTable", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesWorldGenerator, StarDataTable), Z_Construct_UClass_UDataTable_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StarDataTable_MetaData), NewProp_StarDataTable_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEchoesWorldGenerator_Statics::NewProp_StationDataTable = { "StationDataTable", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesWorldGenerator, StationDataTable), Z_Construct_UClass_UDataTable_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StationDataTable_MetaData), NewProp_StationDataTable_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEchoesWorldGenerator_Statics::NewProp_StargateDataTable = { "StargateDataTable", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesWorldGenerator, StargateDataTable), Z_Construct_UClass_UDataTable_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StargateDataTable_MetaData), NewProp_StargateDataTable_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEchoesWorldGenerator_Statics::NewProp_AsteroidBeltDataTable = { "AsteroidBeltDataTable", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesWorldGenerator, AsteroidBeltDataTable), Z_Construct_UClass_UDataTable_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AsteroidBeltDataTable_MetaData), NewProp_AsteroidBeltDataTable_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEchoesWorldGenerator_Statics::NewProp_AnomalyDataTable = { "AnomalyDataTable", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesWorldGenerator, AnomalyDataTable), Z_Construct_UClass_UDataTable_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AnomalyDataTable_MetaData), NewProp_AnomalyDataTable_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEchoesWorldGenerator_Statics::NewProp_WormholeDataTable = { "WormholeDataTable", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesWorldGenerator, WormholeDataTable), Z_Construct_UClass_UDataTable_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WormholeDataTable_MetaData), NewProp_WormholeDataTable_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEchoesWorldGenerator_Statics::NewProp_MoonDataTable = { "MoonDataTable", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesWorldGenerator, MoonDataTable), Z_Construct_UClass_UDataTable_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoonDataTable_MetaData), NewProp_MoonDataTable_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AEchoesWorldGenerator_Statics::NewProp_PlanetActorClass = { "PlanetActorClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesWorldGenerator, PlanetActorClass), Z_Construct_UClass_UClass, Z_Construct_UClass_APlanetActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlanetActorClass_MetaData), NewProp_PlanetActorClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AEchoesWorldGenerator_Statics::NewProp_MoonActorClass = { "MoonActorClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesWorldGenerator, MoonActorClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AMoonActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoonActorClass_MetaData), NewProp_MoonActorClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AEchoesWorldGenerator_Statics::NewProp_StarActorClass = { "StarActorClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesWorldGenerator, StarActorClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AStarActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StarActorClass_MetaData), NewProp_StarActorClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AEchoesWorldGenerator_Statics::NewProp_StationActorClass = { "StationActorClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesWorldGenerator, StationActorClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AStationActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StationActorClass_MetaData), NewProp_StationActorClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AEchoesWorldGenerator_Statics::NewProp_StargateActorClass = { "StargateActorClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesWorldGenerator, StargateActorClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AStargateActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StargateActorClass_MetaData), NewProp_StargateActorClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AEchoesWorldGenerator_Statics::NewProp_AsteroidBeltActorClass = { "AsteroidBeltActorClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesWorldGenerator, AsteroidBeltActorClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AAsteroidBeltActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AsteroidBeltActorClass_MetaData), NewProp_AsteroidBeltActorClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AEchoesWorldGenerator_Statics::NewProp_AnomalyActorClass = { "AnomalyActorClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesWorldGenerator, AnomalyActorClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AAnomalyActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AnomalyActorClass_MetaData), NewProp_AnomalyActorClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AEchoesWorldGenerator_Statics::NewProp_WormholeActorClass = { "WormholeActorClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesWorldGenerator, WormholeActorClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AWormholeActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WormholeActorClass_MetaData), NewProp_WormholeActorClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEchoesWorldGenerator_Statics::NewProp_SpawnedActors_Inner = { "SpawnedActors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AEchoesWorldGenerator_Statics::NewProp_SpawnedActors = { "SpawnedActors", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesWorldGenerator, SpawnedActors), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnedActors_MetaData), NewProp_SpawnedActors_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEchoesWorldGenerator_Statics::NewProp_ServerManagementSubsystem = { "ServerManagementSubsystem", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesWorldGenerator, ServerManagementSubsystem), Z_Construct_UClass_UEchoesServerManagementSubsystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ServerManagementSubsystem_MetaData), NewProp_ServerManagementSubsystem_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEchoesWorldGenerator_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesWorldGenerator_Statics::NewProp_UniverseToWorldScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesWorldGenerator_Statics::NewProp_RegionDistanceScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesWorldGenerator_Statics::NewProp_PlanetDataTable,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesWorldGenerator_Statics::NewProp_StarDataTable,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesWorldGenerator_Statics::NewProp_StationDataTable,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesWorldGenerator_Statics::NewProp_StargateDataTable,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesWorldGenerator_Statics::NewProp_AsteroidBeltDataTable,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesWorldGenerator_Statics::NewProp_AnomalyDataTable,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesWorldGenerator_Statics::NewProp_WormholeDataTable,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesWorldGenerator_Statics::NewProp_MoonDataTable,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesWorldGenerator_Statics::NewProp_PlanetActorClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesWorldGenerator_Statics::NewProp_MoonActorClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesWorldGenerator_Statics::NewProp_StarActorClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesWorldGenerator_Statics::NewProp_StationActorClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesWorldGenerator_Statics::NewProp_StargateActorClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesWorldGenerator_Statics::NewProp_AsteroidBeltActorClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesWorldGenerator_Statics::NewProp_AnomalyActorClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesWorldGenerator_Statics::NewProp_WormholeActorClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesWorldGenerator_Statics::NewProp_SpawnedActors_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesWorldGenerator_Statics::NewProp_SpawnedActors,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesWorldGenerator_Statics::NewProp_ServerManagementSubsystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEchoesWorldGenerator_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AEchoesWorldGenerator_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEchoesWorldGenerator_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AEchoesWorldGenerator_Statics::ClassParams = {
	&AEchoesWorldGenerator::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AEchoesWorldGenerator_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AEchoesWorldGenerator_Statics::PropPointers),
	0,
	0x009001A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEchoesWorldGenerator_Statics::Class_MetaDataParams), Z_Construct_UClass_AEchoesWorldGenerator_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AEchoesWorldGenerator()
{
	if (!Z_Registration_Info_UClass_AEchoesWorldGenerator.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEchoesWorldGenerator.OuterSingleton, Z_Construct_UClass_AEchoesWorldGenerator_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AEchoesWorldGenerator.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AEchoesWorldGenerator);
AEchoesWorldGenerator::~AEchoesWorldGenerator() {}
// ********** End Class AEchoesWorldGenerator ******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_World_EchoesWorldGenerator_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AEchoesWorldGenerator, AEchoesWorldGenerator::StaticClass, TEXT("AEchoesWorldGenerator"), &Z_Registration_Info_UClass_AEchoesWorldGenerator, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEchoesWorldGenerator), 79128700U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_World_EchoesWorldGenerator_h__Script_Echoes_3790713074(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_World_EchoesWorldGenerator_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_World_EchoesWorldGenerator_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
