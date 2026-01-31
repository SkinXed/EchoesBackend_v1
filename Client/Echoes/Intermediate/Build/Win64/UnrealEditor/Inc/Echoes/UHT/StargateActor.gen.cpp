// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Echoes/Core/Common/StargateActor.h"
#include "Echoes/Core/Common/EchoesWorldVisualTypes.h"
#include "Engine/HitResult.h"
#include "UObject/CoreNet.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeStargateActor() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ECHOES_API UClass* Z_Construct_UClass_AStargateActor();
ECHOES_API UClass* Z_Construct_UClass_AStargateActor_NoRegister();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FStargateVisualRow();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APlayerController_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UAudioComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
NIAGARA_API UClass* Z_Construct_UClass_UNiagaraComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AStargateActor Function GetGateId ****************************************
struct Z_Construct_UFunction_AStargateActor_GetGateId_Statics
{
	struct StargateActor_eventGetGateId_Parms
	{
		FGuid ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Stargate" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ==================== Getters ====================\n" },
#endif
		{ "ModuleRelativePath", "Core/Common/StargateActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "==================== Getters ====================" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AStargateActor_GetGateId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StargateActor_eventGetGateId_Parms, ReturnValue), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AStargateActor_GetGateId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStargateActor_GetGateId_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AStargateActor_GetGateId_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AStargateActor_GetGateId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AStargateActor, nullptr, "GetGateId", Z_Construct_UFunction_AStargateActor_GetGateId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AStargateActor_GetGateId_Statics::PropPointers), sizeof(Z_Construct_UFunction_AStargateActor_GetGateId_Statics::StargateActor_eventGetGateId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AStargateActor_GetGateId_Statics::Function_MetaDataParams), Z_Construct_UFunction_AStargateActor_GetGateId_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AStargateActor_GetGateId_Statics::StargateActor_eventGetGateId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AStargateActor_GetGateId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AStargateActor_GetGateId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AStargateActor::execGetGateId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGuid*)Z_Param__Result=P_THIS->GetGateId();
	P_NATIVE_END;
}
// ********** End Class AStargateActor Function GetGateId ******************************************

// ********** Begin Class AStargateActor Function GetGateName **************************************
struct Z_Construct_UFunction_AStargateActor_GetGateName_Statics
{
	struct StargateActor_eventGetGateName_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Stargate" },
		{ "ModuleRelativePath", "Core/Common/StargateActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AStargateActor_GetGateName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StargateActor_eventGetGateName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AStargateActor_GetGateName_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStargateActor_GetGateName_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AStargateActor_GetGateName_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AStargateActor_GetGateName_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AStargateActor, nullptr, "GetGateName", Z_Construct_UFunction_AStargateActor_GetGateName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AStargateActor_GetGateName_Statics::PropPointers), sizeof(Z_Construct_UFunction_AStargateActor_GetGateName_Statics::StargateActor_eventGetGateName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AStargateActor_GetGateName_Statics::Function_MetaDataParams), Z_Construct_UFunction_AStargateActor_GetGateName_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AStargateActor_GetGateName_Statics::StargateActor_eventGetGateName_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AStargateActor_GetGateName()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AStargateActor_GetGateName_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AStargateActor::execGetGateName)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GetGateName();
	P_NATIVE_END;
}
// ********** End Class AStargateActor Function GetGateName ****************************************

// ********** Begin Class AStargateActor Function GetTargetSystemId ********************************
struct Z_Construct_UFunction_AStargateActor_GetTargetSystemId_Statics
{
	struct StargateActor_eventGetTargetSystemId_Parms
	{
		FGuid ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Stargate" },
		{ "ModuleRelativePath", "Core/Common/StargateActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AStargateActor_GetTargetSystemId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StargateActor_eventGetTargetSystemId_Parms, ReturnValue), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AStargateActor_GetTargetSystemId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStargateActor_GetTargetSystemId_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AStargateActor_GetTargetSystemId_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AStargateActor_GetTargetSystemId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AStargateActor, nullptr, "GetTargetSystemId", Z_Construct_UFunction_AStargateActor_GetTargetSystemId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AStargateActor_GetTargetSystemId_Statics::PropPointers), sizeof(Z_Construct_UFunction_AStargateActor_GetTargetSystemId_Statics::StargateActor_eventGetTargetSystemId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AStargateActor_GetTargetSystemId_Statics::Function_MetaDataParams), Z_Construct_UFunction_AStargateActor_GetTargetSystemId_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AStargateActor_GetTargetSystemId_Statics::StargateActor_eventGetTargetSystemId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AStargateActor_GetTargetSystemId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AStargateActor_GetTargetSystemId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AStargateActor::execGetTargetSystemId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGuid*)Z_Param__Result=P_THIS->GetTargetSystemId();
	P_NATIVE_END;
}
// ********** End Class AStargateActor Function GetTargetSystemId **********************************

// ********** Begin Class AStargateActor Function GetTargetSystemName ******************************
struct Z_Construct_UFunction_AStargateActor_GetTargetSystemName_Statics
{
	struct StargateActor_eventGetTargetSystemName_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Stargate" },
		{ "ModuleRelativePath", "Core/Common/StargateActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AStargateActor_GetTargetSystemName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StargateActor_eventGetTargetSystemName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AStargateActor_GetTargetSystemName_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStargateActor_GetTargetSystemName_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AStargateActor_GetTargetSystemName_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AStargateActor_GetTargetSystemName_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AStargateActor, nullptr, "GetTargetSystemName", Z_Construct_UFunction_AStargateActor_GetTargetSystemName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AStargateActor_GetTargetSystemName_Statics::PropPointers), sizeof(Z_Construct_UFunction_AStargateActor_GetTargetSystemName_Statics::StargateActor_eventGetTargetSystemName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AStargateActor_GetTargetSystemName_Statics::Function_MetaDataParams), Z_Construct_UFunction_AStargateActor_GetTargetSystemName_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AStargateActor_GetTargetSystemName_Statics::StargateActor_eventGetTargetSystemName_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AStargateActor_GetTargetSystemName()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AStargateActor_GetTargetSystemName_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AStargateActor::execGetTargetSystemName)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GetTargetSystemName();
	P_NATIVE_END;
}
// ********** End Class AStargateActor Function GetTargetSystemName ********************************

// ********** Begin Class AStargateActor Function InitializeStargate *******************************
struct Z_Construct_UFunction_AStargateActor_InitializeStargate_Statics
{
	struct StargateActor_eventInitializeStargate_Parms
	{
		FGuid InGateId;
		FString InName;
		FGuid InTargetSystemId;
		FString InTargetSystemName;
		bool bInIsOperational;
		FStargateVisualRow InVisualData;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Stargate" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ==================== Initialization ====================\n" },
#endif
		{ "ModuleRelativePath", "Core/Common/StargateActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "==================== Initialization ====================" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InGateId_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InTargetSystemId_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InTargetSystemName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InVisualData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_InGateId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_InName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InTargetSystemId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_InTargetSystemName;
	static void NewProp_bInIsOperational_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInIsOperational;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InVisualData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AStargateActor_InitializeStargate_Statics::NewProp_InGateId = { "InGateId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StargateActor_eventInitializeStargate_Parms, InGateId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InGateId_MetaData), NewProp_InGateId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AStargateActor_InitializeStargate_Statics::NewProp_InName = { "InName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StargateActor_eventInitializeStargate_Parms, InName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InName_MetaData), NewProp_InName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AStargateActor_InitializeStargate_Statics::NewProp_InTargetSystemId = { "InTargetSystemId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StargateActor_eventInitializeStargate_Parms, InTargetSystemId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InTargetSystemId_MetaData), NewProp_InTargetSystemId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AStargateActor_InitializeStargate_Statics::NewProp_InTargetSystemName = { "InTargetSystemName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StargateActor_eventInitializeStargate_Parms, InTargetSystemName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InTargetSystemName_MetaData), NewProp_InTargetSystemName_MetaData) };
void Z_Construct_UFunction_AStargateActor_InitializeStargate_Statics::NewProp_bInIsOperational_SetBit(void* Obj)
{
	((StargateActor_eventInitializeStargate_Parms*)Obj)->bInIsOperational = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AStargateActor_InitializeStargate_Statics::NewProp_bInIsOperational = { "bInIsOperational", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(StargateActor_eventInitializeStargate_Parms), &Z_Construct_UFunction_AStargateActor_InitializeStargate_Statics::NewProp_bInIsOperational_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AStargateActor_InitializeStargate_Statics::NewProp_InVisualData = { "InVisualData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StargateActor_eventInitializeStargate_Parms, InVisualData), Z_Construct_UScriptStruct_FStargateVisualRow, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InVisualData_MetaData), NewProp_InVisualData_MetaData) }; // 2349172136
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AStargateActor_InitializeStargate_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStargateActor_InitializeStargate_Statics::NewProp_InGateId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStargateActor_InitializeStargate_Statics::NewProp_InName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStargateActor_InitializeStargate_Statics::NewProp_InTargetSystemId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStargateActor_InitializeStargate_Statics::NewProp_InTargetSystemName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStargateActor_InitializeStargate_Statics::NewProp_bInIsOperational,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStargateActor_InitializeStargate_Statics::NewProp_InVisualData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AStargateActor_InitializeStargate_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AStargateActor_InitializeStargate_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AStargateActor, nullptr, "InitializeStargate", Z_Construct_UFunction_AStargateActor_InitializeStargate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AStargateActor_InitializeStargate_Statics::PropPointers), sizeof(Z_Construct_UFunction_AStargateActor_InitializeStargate_Statics::StargateActor_eventInitializeStargate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AStargateActor_InitializeStargate_Statics::Function_MetaDataParams), Z_Construct_UFunction_AStargateActor_InitializeStargate_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AStargateActor_InitializeStargate_Statics::StargateActor_eventInitializeStargate_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AStargateActor_InitializeStargate()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AStargateActor_InitializeStargate_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AStargateActor::execInitializeStargate)
{
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_InGateId);
	P_GET_PROPERTY(FStrProperty,Z_Param_InName);
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_InTargetSystemId);
	P_GET_PROPERTY(FStrProperty,Z_Param_InTargetSystemName);
	P_GET_UBOOL(Z_Param_bInIsOperational);
	P_GET_STRUCT_REF(FStargateVisualRow,Z_Param_Out_InVisualData);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializeStargate(Z_Param_Out_InGateId,Z_Param_InName,Z_Param_Out_InTargetSystemId,Z_Param_InTargetSystemName,Z_Param_bInIsOperational,Z_Param_Out_InVisualData);
	P_NATIVE_END;
}
// ********** End Class AStargateActor Function InitializeStargate *********************************

// ********** Begin Class AStargateActor Function IsOperational ************************************
struct Z_Construct_UFunction_AStargateActor_IsOperational_Statics
{
	struct StargateActor_eventIsOperational_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Stargate" },
		{ "ModuleRelativePath", "Core/Common/StargateActor.h" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_AStargateActor_IsOperational_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((StargateActor_eventIsOperational_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AStargateActor_IsOperational_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(StargateActor_eventIsOperational_Parms), &Z_Construct_UFunction_AStargateActor_IsOperational_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AStargateActor_IsOperational_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStargateActor_IsOperational_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AStargateActor_IsOperational_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AStargateActor_IsOperational_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AStargateActor, nullptr, "IsOperational", Z_Construct_UFunction_AStargateActor_IsOperational_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AStargateActor_IsOperational_Statics::PropPointers), sizeof(Z_Construct_UFunction_AStargateActor_IsOperational_Statics::StargateActor_eventIsOperational_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AStargateActor_IsOperational_Statics::Function_MetaDataParams), Z_Construct_UFunction_AStargateActor_IsOperational_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AStargateActor_IsOperational_Statics::StargateActor_eventIsOperational_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AStargateActor_IsOperational()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AStargateActor_IsOperational_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AStargateActor::execIsOperational)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsOperational();
	P_NATIVE_END;
}
// ********** End Class AStargateActor Function IsOperational **************************************

// ********** Begin Class AStargateActor Function IsShipReadyToJump ********************************
struct Z_Construct_UFunction_AStargateActor_IsShipReadyToJump_Statics
{
	struct StargateActor_eventIsShipReadyToJump_Parms
	{
		AActor* Ship;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Stargate" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if ship is ready to jump (not in combat, has energy, etc.)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/StargateActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if ship is ready to jump (not in combat, has energy, etc.)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Ship;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AStargateActor_IsShipReadyToJump_Statics::NewProp_Ship = { "Ship", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StargateActor_eventIsShipReadyToJump_Parms, Ship), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AStargateActor_IsShipReadyToJump_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((StargateActor_eventIsShipReadyToJump_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AStargateActor_IsShipReadyToJump_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(StargateActor_eventIsShipReadyToJump_Parms), &Z_Construct_UFunction_AStargateActor_IsShipReadyToJump_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AStargateActor_IsShipReadyToJump_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStargateActor_IsShipReadyToJump_Statics::NewProp_Ship,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStargateActor_IsShipReadyToJump_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AStargateActor_IsShipReadyToJump_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AStargateActor_IsShipReadyToJump_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AStargateActor, nullptr, "IsShipReadyToJump", Z_Construct_UFunction_AStargateActor_IsShipReadyToJump_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AStargateActor_IsShipReadyToJump_Statics::PropPointers), sizeof(Z_Construct_UFunction_AStargateActor_IsShipReadyToJump_Statics::StargateActor_eventIsShipReadyToJump_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AStargateActor_IsShipReadyToJump_Statics::Function_MetaDataParams), Z_Construct_UFunction_AStargateActor_IsShipReadyToJump_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AStargateActor_IsShipReadyToJump_Statics::StargateActor_eventIsShipReadyToJump_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AStargateActor_IsShipReadyToJump()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AStargateActor_IsShipReadyToJump_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AStargateActor::execIsShipReadyToJump)
{
	P_GET_OBJECT(AActor,Z_Param_Ship);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsShipReadyToJump(Z_Param_Ship);
	P_NATIVE_END;
}
// ********** End Class AStargateActor Function IsShipReadyToJump **********************************

// ********** Begin Class AStargateActor Function OnJumpTriggerBeginOverlap ************************
struct Z_Construct_UFunction_AStargateActor_OnJumpTriggerBeginOverlap_Statics
{
	struct StargateActor_eventOnJumpTriggerBeginOverlap_Parms
	{
		UPrimitiveComponent* OverlappedComponent;
		AActor* OtherActor;
		UPrimitiveComponent* OtherComp;
		int32 OtherBodyIndex;
		bool bFromSweep;
		FHitResult SweepResult;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Called when ship enters jump trigger zone\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/StargateActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when ship enters jump trigger zone" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OverlappedComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SweepResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OverlappedComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherComp;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OtherBodyIndex;
	static void NewProp_bFromSweep_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFromSweep;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SweepResult;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AStargateActor_OnJumpTriggerBeginOverlap_Statics::NewProp_OverlappedComponent = { "OverlappedComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StargateActor_eventOnJumpTriggerBeginOverlap_Parms, OverlappedComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OverlappedComponent_MetaData), NewProp_OverlappedComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AStargateActor_OnJumpTriggerBeginOverlap_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StargateActor_eventOnJumpTriggerBeginOverlap_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AStargateActor_OnJumpTriggerBeginOverlap_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StargateActor_eventOnJumpTriggerBeginOverlap_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OtherComp_MetaData), NewProp_OtherComp_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AStargateActor_OnJumpTriggerBeginOverlap_Statics::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StargateActor_eventOnJumpTriggerBeginOverlap_Parms, OtherBodyIndex), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AStargateActor_OnJumpTriggerBeginOverlap_Statics::NewProp_bFromSweep_SetBit(void* Obj)
{
	((StargateActor_eventOnJumpTriggerBeginOverlap_Parms*)Obj)->bFromSweep = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AStargateActor_OnJumpTriggerBeginOverlap_Statics::NewProp_bFromSweep = { "bFromSweep", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(StargateActor_eventOnJumpTriggerBeginOverlap_Parms), &Z_Construct_UFunction_AStargateActor_OnJumpTriggerBeginOverlap_Statics::NewProp_bFromSweep_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AStargateActor_OnJumpTriggerBeginOverlap_Statics::NewProp_SweepResult = { "SweepResult", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StargateActor_eventOnJumpTriggerBeginOverlap_Parms, SweepResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SweepResult_MetaData), NewProp_SweepResult_MetaData) }; // 267591329
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AStargateActor_OnJumpTriggerBeginOverlap_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStargateActor_OnJumpTriggerBeginOverlap_Statics::NewProp_OverlappedComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStargateActor_OnJumpTriggerBeginOverlap_Statics::NewProp_OtherActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStargateActor_OnJumpTriggerBeginOverlap_Statics::NewProp_OtherComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStargateActor_OnJumpTriggerBeginOverlap_Statics::NewProp_OtherBodyIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStargateActor_OnJumpTriggerBeginOverlap_Statics::NewProp_bFromSweep,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStargateActor_OnJumpTriggerBeginOverlap_Statics::NewProp_SweepResult,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AStargateActor_OnJumpTriggerBeginOverlap_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AStargateActor_OnJumpTriggerBeginOverlap_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AStargateActor, nullptr, "OnJumpTriggerBeginOverlap", Z_Construct_UFunction_AStargateActor_OnJumpTriggerBeginOverlap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AStargateActor_OnJumpTriggerBeginOverlap_Statics::PropPointers), sizeof(Z_Construct_UFunction_AStargateActor_OnJumpTriggerBeginOverlap_Statics::StargateActor_eventOnJumpTriggerBeginOverlap_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AStargateActor_OnJumpTriggerBeginOverlap_Statics::Function_MetaDataParams), Z_Construct_UFunction_AStargateActor_OnJumpTriggerBeginOverlap_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AStargateActor_OnJumpTriggerBeginOverlap_Statics::StargateActor_eventOnJumpTriggerBeginOverlap_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AStargateActor_OnJumpTriggerBeginOverlap()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AStargateActor_OnJumpTriggerBeginOverlap_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AStargateActor::execOnJumpTriggerBeginOverlap)
{
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent);
	P_GET_OBJECT(AActor,Z_Param_OtherActor);
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp);
	P_GET_PROPERTY(FIntProperty,Z_Param_OtherBodyIndex);
	P_GET_UBOOL(Z_Param_bFromSweep);
	P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnJumpTriggerBeginOverlap(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult);
	P_NATIVE_END;
}
// ********** End Class AStargateActor Function OnJumpTriggerBeginOverlap **************************

// ********** Begin Class AStargateActor Function OnRep_GateData ***********************************
struct Z_Construct_UFunction_AStargateActor_OnRep_GateData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Common/StargateActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AStargateActor_OnRep_GateData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AStargateActor, nullptr, "OnRep_GateData", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AStargateActor_OnRep_GateData_Statics::Function_MetaDataParams), Z_Construct_UFunction_AStargateActor_OnRep_GateData_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AStargateActor_OnRep_GateData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AStargateActor_OnRep_GateData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AStargateActor::execOnRep_GateData)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_GateData();
	P_NATIVE_END;
}
// ********** End Class AStargateActor Function OnRep_GateData *************************************

// ********** Begin Class AStargateActor Function ServerRPC_RequestJump ****************************
struct StargateActor_eventServerRPC_RequestJump_Parms
{
	APlayerController* PlayerController;
};
static FName NAME_AStargateActor_ServerRPC_RequestJump = FName(TEXT("ServerRPC_RequestJump"));
void AStargateActor::ServerRPC_RequestJump(APlayerController* PlayerController)
{
	StargateActor_eventServerRPC_RequestJump_Parms Parms;
	Parms.PlayerController=PlayerController;
	UFunction* Func = FindFunctionChecked(NAME_AStargateActor_ServerRPC_RequestJump);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AStargateActor_ServerRPC_RequestJump_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Server RPC to request jump to target system\n\x09 * Validates ship readiness and initiates travel\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/StargateActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Server RPC to request jump to target system\nValidates ship readiness and initiates travel" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AStargateActor_ServerRPC_RequestJump_Statics::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StargateActor_eventServerRPC_RequestJump_Parms, PlayerController), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AStargateActor_ServerRPC_RequestJump_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStargateActor_ServerRPC_RequestJump_Statics::NewProp_PlayerController,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AStargateActor_ServerRPC_RequestJump_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AStargateActor_ServerRPC_RequestJump_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AStargateActor, nullptr, "ServerRPC_RequestJump", Z_Construct_UFunction_AStargateActor_ServerRPC_RequestJump_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AStargateActor_ServerRPC_RequestJump_Statics::PropPointers), sizeof(StargateActor_eventServerRPC_RequestJump_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AStargateActor_ServerRPC_RequestJump_Statics::Function_MetaDataParams), Z_Construct_UFunction_AStargateActor_ServerRPC_RequestJump_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(StargateActor_eventServerRPC_RequestJump_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AStargateActor_ServerRPC_RequestJump()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AStargateActor_ServerRPC_RequestJump_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AStargateActor::execServerRPC_RequestJump)
{
	P_GET_OBJECT(APlayerController,Z_Param_PlayerController);
	P_FINISH;
	P_NATIVE_BEGIN;
	if (!P_THIS->ServerRPC_RequestJump_Validate(Z_Param_PlayerController))
	{
		RPC_ValidateFailed(TEXT("ServerRPC_RequestJump_Validate"));
		return;
	}
	P_THIS->ServerRPC_RequestJump_Implementation(Z_Param_PlayerController);
	P_NATIVE_END;
}
// ********** End Class AStargateActor Function ServerRPC_RequestJump ******************************

// ********** Begin Class AStargateActor ***********************************************************
void AStargateActor::StaticRegisterNativesAStargateActor()
{
	UClass* Class = AStargateActor::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetGateId", &AStargateActor::execGetGateId },
		{ "GetGateName", &AStargateActor::execGetGateName },
		{ "GetTargetSystemId", &AStargateActor::execGetTargetSystemId },
		{ "GetTargetSystemName", &AStargateActor::execGetTargetSystemName },
		{ "InitializeStargate", &AStargateActor::execInitializeStargate },
		{ "IsOperational", &AStargateActor::execIsOperational },
		{ "IsShipReadyToJump", &AStargateActor::execIsShipReadyToJump },
		{ "OnJumpTriggerBeginOverlap", &AStargateActor::execOnJumpTriggerBeginOverlap },
		{ "OnRep_GateData", &AStargateActor::execOnRep_GateData },
		{ "ServerRPC_RequestJump", &AStargateActor::execServerRPC_RequestJump },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_AStargateActor;
UClass* AStargateActor::GetPrivateStaticClass()
{
	using TClass = AStargateActor;
	if (!Z_Registration_Info_UClass_AStargateActor.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("StargateActor"),
			Z_Registration_Info_UClass_AStargateActor.InnerSingleton,
			StaticRegisterNativesAStargateActor,
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
	return Z_Registration_Info_UClass_AStargateActor.InnerSingleton;
}
UClass* Z_Construct_UClass_AStargateActor_NoRegister()
{
	return AStargateActor::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AStargateActor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * AStargateActor\n * \n * Represents a stargate in the Echoes universe\n * Provides jump capability to other solar systems\n */" },
#endif
		{ "IncludePath", "Core/Common/StargateActor.h" },
		{ "ModuleRelativePath", "Core/Common/StargateActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "AStargateActor\n\nRepresents a stargate in the Echoes universe\nProvides jump capability to other solar systems" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GateMeshComponent_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ==================== Components ====================\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/StargateActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "==================== Components ====================" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PortalVFXComponent_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/StargateActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DestinationFXComponent_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/StargateActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AmbientAudioComponent_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/StargateActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JumpTriggerZone_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Jump trigger zone - detects ships entering for jump */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/StargateActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Jump trigger zone - detects ships entering for jump" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GateId_MetaData[] = {
		{ "Category", "Stargate" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ==================== Gate Data (Replicated) ====================\n" },
#endif
		{ "ModuleRelativePath", "Core/Common/StargateActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "==================== Gate Data (Replicated) ====================" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GateName_MetaData[] = {
		{ "Category", "Stargate" },
		{ "ModuleRelativePath", "Core/Common/StargateActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetSystemId_MetaData[] = {
		{ "Category", "Stargate" },
		{ "ModuleRelativePath", "Core/Common/StargateActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetSystemName_MetaData[] = {
		{ "Category", "Stargate" },
		{ "ModuleRelativePath", "Core/Common/StargateActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsOperational_MetaData[] = {
		{ "Category", "Stargate" },
		{ "ModuleRelativePath", "Core/Common/StargateActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VisualData_MetaData[] = {
		{ "Category", "Stargate" },
		{ "ModuleRelativePath", "Core/Common/StargateActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_GateMeshComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PortalVFXComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DestinationFXComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AmbientAudioComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpTriggerZone;
	static const UECodeGen_Private::FStructPropertyParams NewProp_GateId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_GateName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetSystemId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_TargetSystemName;
	static void NewProp_bIsOperational_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsOperational;
	static const UECodeGen_Private::FStructPropertyParams NewProp_VisualData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AStargateActor_GetGateId, "GetGateId" }, // 2457784306
		{ &Z_Construct_UFunction_AStargateActor_GetGateName, "GetGateName" }, // 2536640805
		{ &Z_Construct_UFunction_AStargateActor_GetTargetSystemId, "GetTargetSystemId" }, // 2013758584
		{ &Z_Construct_UFunction_AStargateActor_GetTargetSystemName, "GetTargetSystemName" }, // 1592363934
		{ &Z_Construct_UFunction_AStargateActor_InitializeStargate, "InitializeStargate" }, // 2782464364
		{ &Z_Construct_UFunction_AStargateActor_IsOperational, "IsOperational" }, // 2953087208
		{ &Z_Construct_UFunction_AStargateActor_IsShipReadyToJump, "IsShipReadyToJump" }, // 456374390
		{ &Z_Construct_UFunction_AStargateActor_OnJumpTriggerBeginOverlap, "OnJumpTriggerBeginOverlap" }, // 524114548
		{ &Z_Construct_UFunction_AStargateActor_OnRep_GateData, "OnRep_GateData" }, // 2712804769
		{ &Z_Construct_UFunction_AStargateActor_ServerRPC_RequestJump, "ServerRPC_RequestJump" }, // 1171365877
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AStargateActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AStargateActor_Statics::NewProp_GateMeshComponent = { "GateMeshComponent", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStargateActor, GateMeshComponent), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GateMeshComponent_MetaData), NewProp_GateMeshComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AStargateActor_Statics::NewProp_PortalVFXComponent = { "PortalVFXComponent", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStargateActor, PortalVFXComponent), Z_Construct_UClass_UNiagaraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PortalVFXComponent_MetaData), NewProp_PortalVFXComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AStargateActor_Statics::NewProp_DestinationFXComponent = { "DestinationFXComponent", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStargateActor, DestinationFXComponent), Z_Construct_UClass_UNiagaraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DestinationFXComponent_MetaData), NewProp_DestinationFXComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AStargateActor_Statics::NewProp_AmbientAudioComponent = { "AmbientAudioComponent", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStargateActor, AmbientAudioComponent), Z_Construct_UClass_UAudioComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AmbientAudioComponent_MetaData), NewProp_AmbientAudioComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AStargateActor_Statics::NewProp_JumpTriggerZone = { "JumpTriggerZone", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStargateActor, JumpTriggerZone), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpTriggerZone_MetaData), NewProp_JumpTriggerZone_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AStargateActor_Statics::NewProp_GateId = { "GateId", "OnRep_GateData", (EPropertyFlags)0x0020080100000034, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStargateActor, GateId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GateId_MetaData), NewProp_GateId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AStargateActor_Statics::NewProp_GateName = { "GateName", "OnRep_GateData", (EPropertyFlags)0x0020080100000034, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStargateActor, GateName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GateName_MetaData), NewProp_GateName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AStargateActor_Statics::NewProp_TargetSystemId = { "TargetSystemId", "OnRep_GateData", (EPropertyFlags)0x0020080100000034, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStargateActor, TargetSystemId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetSystemId_MetaData), NewProp_TargetSystemId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AStargateActor_Statics::NewProp_TargetSystemName = { "TargetSystemName", "OnRep_GateData", (EPropertyFlags)0x0020080100000034, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStargateActor, TargetSystemName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetSystemName_MetaData), NewProp_TargetSystemName_MetaData) };
void Z_Construct_UClass_AStargateActor_Statics::NewProp_bIsOperational_SetBit(void* Obj)
{
	((AStargateActor*)Obj)->bIsOperational = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AStargateActor_Statics::NewProp_bIsOperational = { "bIsOperational", "OnRep_GateData", (EPropertyFlags)0x0020080100000034, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AStargateActor), &Z_Construct_UClass_AStargateActor_Statics::NewProp_bIsOperational_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsOperational_MetaData), NewProp_bIsOperational_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AStargateActor_Statics::NewProp_VisualData = { "VisualData", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStargateActor, VisualData), Z_Construct_UScriptStruct_FStargateVisualRow, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VisualData_MetaData), NewProp_VisualData_MetaData) }; // 2349172136
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AStargateActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStargateActor_Statics::NewProp_GateMeshComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStargateActor_Statics::NewProp_PortalVFXComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStargateActor_Statics::NewProp_DestinationFXComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStargateActor_Statics::NewProp_AmbientAudioComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStargateActor_Statics::NewProp_JumpTriggerZone,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStargateActor_Statics::NewProp_GateId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStargateActor_Statics::NewProp_GateName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStargateActor_Statics::NewProp_TargetSystemId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStargateActor_Statics::NewProp_TargetSystemName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStargateActor_Statics::NewProp_bIsOperational,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStargateActor_Statics::NewProp_VisualData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AStargateActor_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AStargateActor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AStargateActor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AStargateActor_Statics::ClassParams = {
	&AStargateActor::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AStargateActor_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AStargateActor_Statics::PropPointers),
	0,
	0x009001A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AStargateActor_Statics::Class_MetaDataParams), Z_Construct_UClass_AStargateActor_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AStargateActor()
{
	if (!Z_Registration_Info_UClass_AStargateActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AStargateActor.OuterSingleton, Z_Construct_UClass_AStargateActor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AStargateActor.OuterSingleton;
}
#if VALIDATE_CLASS_REPS
void AStargateActor::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static FName Name_GateId(TEXT("GateId"));
	static FName Name_GateName(TEXT("GateName"));
	static FName Name_TargetSystemId(TEXT("TargetSystemId"));
	static FName Name_TargetSystemName(TEXT("TargetSystemName"));
	static FName Name_bIsOperational(TEXT("bIsOperational"));
	const bool bIsValid = true
		&& Name_GateId == ClassReps[(int32)ENetFields_Private::GateId].Property->GetFName()
		&& Name_GateName == ClassReps[(int32)ENetFields_Private::GateName].Property->GetFName()
		&& Name_TargetSystemId == ClassReps[(int32)ENetFields_Private::TargetSystemId].Property->GetFName()
		&& Name_TargetSystemName == ClassReps[(int32)ENetFields_Private::TargetSystemName].Property->GetFName()
		&& Name_bIsOperational == ClassReps[(int32)ENetFields_Private::bIsOperational].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in AStargateActor"));
}
#endif
DEFINE_VTABLE_PTR_HELPER_CTOR(AStargateActor);
AStargateActor::~AStargateActor() {}
// ********** End Class AStargateActor *************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_StargateActor_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AStargateActor, AStargateActor::StaticClass, TEXT("AStargateActor"), &Z_Registration_Info_UClass_AStargateActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AStargateActor), 1842996685U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_StargateActor_h__Script_Echoes_804605748(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_StargateActor_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_StargateActor_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
