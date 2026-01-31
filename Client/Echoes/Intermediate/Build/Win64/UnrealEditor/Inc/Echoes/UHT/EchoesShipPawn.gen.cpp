// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Core/Client/EchoesShipPawn.h"
#include "Core/Common/EchoesShipTypes.h"
#include "Core/Common/Networking/EchoesInventorySubsystem.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesShipPawn() {}

// ********** Begin Cross Module References ********************************************************
ECHOES_API UClass* Z_Construct_UClass_AEchoesShipPawn();
ECHOES_API UClass* Z_Construct_UClass_AEchoesShipPawn_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UEchoesShipMovementComponent_NoRegister();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FEchoesShipFitting();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FEchoesShipStats();
ENGINE_API UClass* Z_Construct_UClass_APawn();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AEchoesShipPawn Function Common_InitializeFromStats **********************
struct Z_Construct_UFunction_AEchoesShipPawn_Common_InitializeFromStats_Statics
{
	struct EchoesShipPawn_eventCommon_InitializeFromStats_Parms
	{
		FEchoesShipStats Stats;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ship" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Initialize ship from backend stats (Common - can be called on any side) */" },
#endif
		{ "ModuleRelativePath", "Core/Client/EchoesShipPawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Initialize ship from backend stats (Common - can be called on any side)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Stats_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Stats;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEchoesShipPawn_Common_InitializeFromStats_Statics::NewProp_Stats = { "Stats", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesShipPawn_eventCommon_InitializeFromStats_Parms, Stats), Z_Construct_UScriptStruct_FEchoesShipStats, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Stats_MetaData), NewProp_Stats_MetaData) }; // 652073936
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesShipPawn_Common_InitializeFromStats_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesShipPawn_Common_InitializeFromStats_Statics::NewProp_Stats,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesShipPawn_Common_InitializeFromStats_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesShipPawn_Common_InitializeFromStats_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesShipPawn, nullptr, "Common_InitializeFromStats", Z_Construct_UFunction_AEchoesShipPawn_Common_InitializeFromStats_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesShipPawn_Common_InitializeFromStats_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesShipPawn_Common_InitializeFromStats_Statics::EchoesShipPawn_eventCommon_InitializeFromStats_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesShipPawn_Common_InitializeFromStats_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesShipPawn_Common_InitializeFromStats_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesShipPawn_Common_InitializeFromStats_Statics::EchoesShipPawn_eventCommon_InitializeFromStats_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesShipPawn_Common_InitializeFromStats()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesShipPawn_Common_InitializeFromStats_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesShipPawn::execCommon_InitializeFromStats)
{
	P_GET_STRUCT_REF(FEchoesShipStats,Z_Param_Out_Stats);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Common_InitializeFromStats(Z_Param_Out_Stats);
	P_NATIVE_END;
}
// ********** End Class AEchoesShipPawn Function Common_InitializeFromStats ************************

// ********** Begin Class AEchoesShipPawn Function GetShipStats ************************************
struct Z_Construct_UFunction_AEchoesShipPawn_GetShipStats_Statics
{
	struct EchoesShipPawn_eventGetShipStats_Parms
	{
		FEchoesShipStats ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ship" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Get current ship stats */" },
#endif
		{ "ModuleRelativePath", "Core/Client/EchoesShipPawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get current ship stats" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEchoesShipPawn_GetShipStats_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesShipPawn_eventGetShipStats_Parms, ReturnValue), Z_Construct_UScriptStruct_FEchoesShipStats, METADATA_PARAMS(0, nullptr) }; // 652073936
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesShipPawn_GetShipStats_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesShipPawn_GetShipStats_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesShipPawn_GetShipStats_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesShipPawn_GetShipStats_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesShipPawn, nullptr, "GetShipStats", Z_Construct_UFunction_AEchoesShipPawn_GetShipStats_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesShipPawn_GetShipStats_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesShipPawn_GetShipStats_Statics::EchoesShipPawn_eventGetShipStats_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesShipPawn_GetShipStats_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesShipPawn_GetShipStats_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesShipPawn_GetShipStats_Statics::EchoesShipPawn_eventGetShipStats_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesShipPawn_GetShipStats()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesShipPawn_GetShipStats_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesShipPawn::execGetShipStats)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FEchoesShipStats*)Z_Param__Result=P_THIS->GetShipStats();
	P_NATIVE_END;
}
// ********** End Class AEchoesShipPawn Function GetShipStats **************************************

// ********** Begin Class AEchoesShipPawn Function HandleShipFittingFailed *************************
struct Z_Construct_UFunction_AEchoesShipPawn_HandleShipFittingFailed_Statics
{
	struct EchoesShipPawn_eventHandleShipFittingFailed_Parms
	{
		FString Error;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Client/EchoesShipPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Error_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_Error;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AEchoesShipPawn_HandleShipFittingFailed_Statics::NewProp_Error = { "Error", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesShipPawn_eventHandleShipFittingFailed_Parms, Error), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Error_MetaData), NewProp_Error_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesShipPawn_HandleShipFittingFailed_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesShipPawn_HandleShipFittingFailed_Statics::NewProp_Error,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesShipPawn_HandleShipFittingFailed_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesShipPawn_HandleShipFittingFailed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesShipPawn, nullptr, "HandleShipFittingFailed", Z_Construct_UFunction_AEchoesShipPawn_HandleShipFittingFailed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesShipPawn_HandleShipFittingFailed_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesShipPawn_HandleShipFittingFailed_Statics::EchoesShipPawn_eventHandleShipFittingFailed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesShipPawn_HandleShipFittingFailed_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesShipPawn_HandleShipFittingFailed_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesShipPawn_HandleShipFittingFailed_Statics::EchoesShipPawn_eventHandleShipFittingFailed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesShipPawn_HandleShipFittingFailed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesShipPawn_HandleShipFittingFailed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesShipPawn::execHandleShipFittingFailed)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Error);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleShipFittingFailed(Z_Param_Error);
	P_NATIVE_END;
}
// ********** End Class AEchoesShipPawn Function HandleShipFittingFailed ***************************

// ********** Begin Class AEchoesShipPawn Function HandleShipFittingReceived ***********************
struct Z_Construct_UFunction_AEchoesShipPawn_HandleShipFittingReceived_Statics
{
	struct EchoesShipPawn_eventHandleShipFittingReceived_Parms
	{
		FEchoesShipFitting Fitting;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Client/EchoesShipPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Fitting_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Fitting;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEchoesShipPawn_HandleShipFittingReceived_Statics::NewProp_Fitting = { "Fitting", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesShipPawn_eventHandleShipFittingReceived_Parms, Fitting), Z_Construct_UScriptStruct_FEchoesShipFitting, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Fitting_MetaData), NewProp_Fitting_MetaData) }; // 2094547099
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesShipPawn_HandleShipFittingReceived_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesShipPawn_HandleShipFittingReceived_Statics::NewProp_Fitting,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesShipPawn_HandleShipFittingReceived_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesShipPawn_HandleShipFittingReceived_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesShipPawn, nullptr, "HandleShipFittingReceived", Z_Construct_UFunction_AEchoesShipPawn_HandleShipFittingReceived_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesShipPawn_HandleShipFittingReceived_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesShipPawn_HandleShipFittingReceived_Statics::EchoesShipPawn_eventHandleShipFittingReceived_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00480401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesShipPawn_HandleShipFittingReceived_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesShipPawn_HandleShipFittingReceived_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesShipPawn_HandleShipFittingReceived_Statics::EchoesShipPawn_eventHandleShipFittingReceived_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesShipPawn_HandleShipFittingReceived()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesShipPawn_HandleShipFittingReceived_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesShipPawn::execHandleShipFittingReceived)
{
	P_GET_STRUCT_REF(FEchoesShipFitting,Z_Param_Out_Fitting);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleShipFittingReceived(Z_Param_Out_Fitting);
	P_NATIVE_END;
}
// ********** End Class AEchoesShipPawn Function HandleShipFittingReceived *************************

// ********** Begin Class AEchoesShipPawn Function InitializeShipStats *****************************
struct Z_Construct_UFunction_AEchoesShipPawn_InitializeShipStats_Statics
{
	struct EchoesShipPawn_eventInitializeShipStats_Parms
	{
		FEchoesShipStats Stats;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ship" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Legacy function name for backward compatibility */" },
#endif
		{ "ModuleRelativePath", "Core/Client/EchoesShipPawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Legacy function name for backward compatibility" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Stats_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Stats;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEchoesShipPawn_InitializeShipStats_Statics::NewProp_Stats = { "Stats", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesShipPawn_eventInitializeShipStats_Parms, Stats), Z_Construct_UScriptStruct_FEchoesShipStats, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Stats_MetaData), NewProp_Stats_MetaData) }; // 652073936
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesShipPawn_InitializeShipStats_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesShipPawn_InitializeShipStats_Statics::NewProp_Stats,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesShipPawn_InitializeShipStats_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesShipPawn_InitializeShipStats_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesShipPawn, nullptr, "InitializeShipStats", Z_Construct_UFunction_AEchoesShipPawn_InitializeShipStats_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesShipPawn_InitializeShipStats_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesShipPawn_InitializeShipStats_Statics::EchoesShipPawn_eventInitializeShipStats_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesShipPawn_InitializeShipStats_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesShipPawn_InitializeShipStats_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesShipPawn_InitializeShipStats_Statics::EchoesShipPawn_eventInitializeShipStats_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesShipPawn_InitializeShipStats()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesShipPawn_InitializeShipStats_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesShipPawn::execInitializeShipStats)
{
	P_GET_STRUCT_REF(FEchoesShipStats,Z_Param_Out_Stats);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializeShipStats(Z_Param_Out_Stats);
	P_NATIVE_END;
}
// ********** End Class AEchoesShipPawn Function InitializeShipStats *******************************

// ********** Begin Class AEchoesShipPawn Function OnFittingReceived *******************************
struct Z_Construct_UFunction_AEchoesShipPawn_OnFittingReceived_Statics
{
	struct EchoesShipPawn_eventOnFittingReceived_Parms
	{
		FEchoesShipStats Stats;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Handle fitting received from inventory subsystem */" },
#endif
		{ "ModuleRelativePath", "Core/Client/EchoesShipPawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handle fitting received from inventory subsystem" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Stats_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Stats;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEchoesShipPawn_OnFittingReceived_Statics::NewProp_Stats = { "Stats", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesShipPawn_eventOnFittingReceived_Parms, Stats), Z_Construct_UScriptStruct_FEchoesShipStats, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Stats_MetaData), NewProp_Stats_MetaData) }; // 652073936
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesShipPawn_OnFittingReceived_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesShipPawn_OnFittingReceived_Statics::NewProp_Stats,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesShipPawn_OnFittingReceived_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesShipPawn_OnFittingReceived_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesShipPawn, nullptr, "OnFittingReceived", Z_Construct_UFunction_AEchoesShipPawn_OnFittingReceived_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesShipPawn_OnFittingReceived_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesShipPawn_OnFittingReceived_Statics::EchoesShipPawn_eventOnFittingReceived_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00480401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesShipPawn_OnFittingReceived_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesShipPawn_OnFittingReceived_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesShipPawn_OnFittingReceived_Statics::EchoesShipPawn_eventOnFittingReceived_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesShipPawn_OnFittingReceived()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesShipPawn_OnFittingReceived_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesShipPawn::execOnFittingReceived)
{
	P_GET_STRUCT_REF(FEchoesShipStats,Z_Param_Out_Stats);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnFittingReceived(Z_Param_Out_Stats);
	P_NATIVE_END;
}
// ********** End Class AEchoesShipPawn Function OnFittingReceived *********************************

// ********** Begin Class AEchoesShipPawn Function OnRep_ShipStats *********************************
struct Z_Construct_UFunction_AEchoesShipPawn_OnRep_ShipStats_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Called when ship stats are replicated from server to client */" },
#endif
		{ "ModuleRelativePath", "Core/Client/EchoesShipPawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when ship stats are replicated from server to client" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesShipPawn_OnRep_ShipStats_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesShipPawn, nullptr, "OnRep_ShipStats", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesShipPawn_OnRep_ShipStats_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesShipPawn_OnRep_ShipStats_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AEchoesShipPawn_OnRep_ShipStats()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesShipPawn_OnRep_ShipStats_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesShipPawn::execOnRep_ShipStats)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_ShipStats();
	P_NATIVE_END;
}
// ********** End Class AEchoesShipPawn Function OnRep_ShipStats ***********************************

// ********** Begin Class AEchoesShipPawn Function ServerRPC_RequestShipInitialization *************
struct EchoesShipPawn_eventServerRPC_RequestShipInitialization_Parms
{
	FString ShipId;
};
static FName NAME_AEchoesShipPawn_ServerRPC_RequestShipInitialization = FName(TEXT("ServerRPC_RequestShipInitialization"));
void AEchoesShipPawn::ServerRPC_RequestShipInitialization(const FString& ShipId)
{
	EchoesShipPawn_eventServerRPC_RequestShipInitialization_Parms Parms;
	Parms.ShipId=ShipId;
	UFunction* Func = FindFunctionChecked(NAME_AEchoesShipPawn_ServerRPC_RequestShipInitialization);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AEchoesShipPawn_ServerRPC_RequestShipInitialization_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ship" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Server RPC to request ship initialization with ownership verification */" },
#endif
		{ "ModuleRelativePath", "Core/Client/EchoesShipPawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Server RPC to request ship initialization with ownership verification" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShipId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ShipId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AEchoesShipPawn_ServerRPC_RequestShipInitialization_Statics::NewProp_ShipId = { "ShipId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesShipPawn_eventServerRPC_RequestShipInitialization_Parms, ShipId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShipId_MetaData), NewProp_ShipId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesShipPawn_ServerRPC_RequestShipInitialization_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesShipPawn_ServerRPC_RequestShipInitialization_Statics::NewProp_ShipId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesShipPawn_ServerRPC_RequestShipInitialization_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesShipPawn_ServerRPC_RequestShipInitialization_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesShipPawn, nullptr, "ServerRPC_RequestShipInitialization", Z_Construct_UFunction_AEchoesShipPawn_ServerRPC_RequestShipInitialization_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesShipPawn_ServerRPC_RequestShipInitialization_Statics::PropPointers), sizeof(EchoesShipPawn_eventServerRPC_RequestShipInitialization_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesShipPawn_ServerRPC_RequestShipInitialization_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesShipPawn_ServerRPC_RequestShipInitialization_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(EchoesShipPawn_eventServerRPC_RequestShipInitialization_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesShipPawn_ServerRPC_RequestShipInitialization()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesShipPawn_ServerRPC_RequestShipInitialization_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesShipPawn::execServerRPC_RequestShipInitialization)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ShipId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerRPC_RequestShipInitialization_Implementation(Z_Param_ShipId);
	P_NATIVE_END;
}
// ********** End Class AEchoesShipPawn Function ServerRPC_RequestShipInitialization ***************

// ********** Begin Class AEchoesShipPawn **********************************************************
void AEchoesShipPawn::StaticRegisterNativesAEchoesShipPawn()
{
	UClass* Class = AEchoesShipPawn::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "Common_InitializeFromStats", &AEchoesShipPawn::execCommon_InitializeFromStats },
		{ "GetShipStats", &AEchoesShipPawn::execGetShipStats },
		{ "HandleShipFittingFailed", &AEchoesShipPawn::execHandleShipFittingFailed },
		{ "HandleShipFittingReceived", &AEchoesShipPawn::execHandleShipFittingReceived },
		{ "InitializeShipStats", &AEchoesShipPawn::execInitializeShipStats },
		{ "OnFittingReceived", &AEchoesShipPawn::execOnFittingReceived },
		{ "OnRep_ShipStats", &AEchoesShipPawn::execOnRep_ShipStats },
		{ "ServerRPC_RequestShipInitialization", &AEchoesShipPawn::execServerRPC_RequestShipInitialization },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_AEchoesShipPawn;
UClass* AEchoesShipPawn::GetPrivateStaticClass()
{
	using TClass = AEchoesShipPawn;
	if (!Z_Registration_Info_UClass_AEchoesShipPawn.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesShipPawn"),
			Z_Registration_Info_UClass_AEchoesShipPawn.InnerSingleton,
			StaticRegisterNativesAEchoesShipPawn,
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
	return Z_Registration_Info_UClass_AEchoesShipPawn.InnerSingleton;
}
UClass* Z_Construct_UClass_AEchoesShipPawn_NoRegister()
{
	return AEchoesShipPawn::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AEchoesShipPawn_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Ship pawn with physics-based movement and camera\n * Client-side implementation with Enhanced Input\n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Core/Client/EchoesShipPawn.h" },
		{ "ModuleRelativePath", "Core/Client/EchoesShipPawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ship pawn with physics-based movement and camera\nClient-side implementation with Enhanced Input" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShipMesh_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Ship mesh with physics simulation */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Client/EchoesShipPawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ship mesh with physics simulation" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShipMovement_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Custom ship movement component */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Client/EchoesShipPawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Custom ship movement component" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpringArm_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Spring arm for camera (provides lag and smoothing) */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Client/EchoesShipPawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Spring arm for camera (provides lag and smoothing)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Camera_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Camera component */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Client/EchoesShipPawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Camera component" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InputMapping_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Input Mapping Context */" },
#endif
		{ "ModuleRelativePath", "Core/Client/EchoesShipPawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Input Mapping Context" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveAction_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Move action (WASD) */" },
#endif
		{ "ModuleRelativePath", "Core/Client/EchoesShipPawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Move action (WASD)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LookAction_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Look action (Mouse) */" },
#endif
		{ "ModuleRelativePath", "Core/Client/EchoesShipPawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Look action (Mouse)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MouseFollowAction_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Mouse follow toggle action */" },
#endif
		{ "ModuleRelativePath", "Core/Client/EchoesShipPawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Mouse follow toggle action" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WarpAction_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Warp action */" },
#endif
		{ "ModuleRelativePath", "Core/Client/EchoesShipPawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Warp action" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FreeLookAction_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Free look action (Alt key) */" },
#endif
		{ "ModuleRelativePath", "Core/Client/EchoesShipPawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Free look action (Alt key)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraDistance_MetaData[] = {
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Camera distance from ship */" },
#endif
		{ "ModuleRelativePath", "Core/Client/EchoesShipPawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Camera distance from ship" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraLagSpeed_MetaData[] = {
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Camera lag speed (provides mass feel on acceleration) */" },
#endif
		{ "ModuleRelativePath", "Core/Client/EchoesShipPawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Camera lag speed (provides mass feel on acceleration)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableCameraLag_MetaData[] = {
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether camera lag is enabled */" },
#endif
		{ "ModuleRelativePath", "Core/Client/EchoesShipPawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether camera lag is enabled" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraPitch_MetaData[] = {
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Camera pitch angle (degrees) */" },
#endif
		{ "ModuleRelativePath", "Core/Client/EchoesShipPawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Camera pitch angle (degrees)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MouseSensitivity_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Mouse sensitivity for camera control */" },
#endif
		{ "ModuleRelativePath", "Core/Client/EchoesShipPawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Mouse sensitivity for camera control" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bFreeLookActive_MetaData[] = {
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether free look is currently active */" },
#endif
		{ "ModuleRelativePath", "Core/Client/EchoesShipPawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether free look is currently active" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReplicatedShipStats_MetaData[] = {
		{ "Category", "Ship" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Replicated ship stats - authoritative on server */" },
#endif
		{ "ModuleRelativePath", "Core/Client/EchoesShipPawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Replicated ship stats - authoritative on server" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ShipMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ShipMovement;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpringArm;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Camera;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InputMapping;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MoveAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LookAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MouseFollowAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WarpAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FreeLookAction;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CameraDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CameraLagSpeed;
	static void NewProp_bEnableCameraLag_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableCameraLag;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CameraPitch;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MouseSensitivity;
	static void NewProp_bFreeLookActive_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFreeLookActive;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReplicatedShipStats;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AEchoesShipPawn_Common_InitializeFromStats, "Common_InitializeFromStats" }, // 2490362803
		{ &Z_Construct_UFunction_AEchoesShipPawn_GetShipStats, "GetShipStats" }, // 1312928224
		{ &Z_Construct_UFunction_AEchoesShipPawn_HandleShipFittingFailed, "HandleShipFittingFailed" }, // 2708423049
		{ &Z_Construct_UFunction_AEchoesShipPawn_HandleShipFittingReceived, "HandleShipFittingReceived" }, // 1989409304
		{ &Z_Construct_UFunction_AEchoesShipPawn_InitializeShipStats, "InitializeShipStats" }, // 1082518863
		{ &Z_Construct_UFunction_AEchoesShipPawn_OnFittingReceived, "OnFittingReceived" }, // 3142198698
		{ &Z_Construct_UFunction_AEchoesShipPawn_OnRep_ShipStats, "OnRep_ShipStats" }, // 636055126
		{ &Z_Construct_UFunction_AEchoesShipPawn_ServerRPC_RequestShipInitialization, "ServerRPC_RequestShipInitialization" }, // 2229126264
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEchoesShipPawn>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEchoesShipPawn_Statics::NewProp_ShipMesh = { "ShipMesh", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesShipPawn, ShipMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShipMesh_MetaData), NewProp_ShipMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEchoesShipPawn_Statics::NewProp_ShipMovement = { "ShipMovement", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesShipPawn, ShipMovement), Z_Construct_UClass_UEchoesShipMovementComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShipMovement_MetaData), NewProp_ShipMovement_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEchoesShipPawn_Statics::NewProp_SpringArm = { "SpringArm", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesShipPawn, SpringArm), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpringArm_MetaData), NewProp_SpringArm_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEchoesShipPawn_Statics::NewProp_Camera = { "Camera", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesShipPawn, Camera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Camera_MetaData), NewProp_Camera_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEchoesShipPawn_Statics::NewProp_InputMapping = { "InputMapping", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesShipPawn, InputMapping), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InputMapping_MetaData), NewProp_InputMapping_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEchoesShipPawn_Statics::NewProp_MoveAction = { "MoveAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesShipPawn, MoveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveAction_MetaData), NewProp_MoveAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEchoesShipPawn_Statics::NewProp_LookAction = { "LookAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesShipPawn, LookAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LookAction_MetaData), NewProp_LookAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEchoesShipPawn_Statics::NewProp_MouseFollowAction = { "MouseFollowAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesShipPawn, MouseFollowAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MouseFollowAction_MetaData), NewProp_MouseFollowAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEchoesShipPawn_Statics::NewProp_WarpAction = { "WarpAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesShipPawn, WarpAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WarpAction_MetaData), NewProp_WarpAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEchoesShipPawn_Statics::NewProp_FreeLookAction = { "FreeLookAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesShipPawn, FreeLookAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FreeLookAction_MetaData), NewProp_FreeLookAction_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEchoesShipPawn_Statics::NewProp_CameraDistance = { "CameraDistance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesShipPawn, CameraDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraDistance_MetaData), NewProp_CameraDistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEchoesShipPawn_Statics::NewProp_CameraLagSpeed = { "CameraLagSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesShipPawn, CameraLagSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraLagSpeed_MetaData), NewProp_CameraLagSpeed_MetaData) };
void Z_Construct_UClass_AEchoesShipPawn_Statics::NewProp_bEnableCameraLag_SetBit(void* Obj)
{
	((AEchoesShipPawn*)Obj)->bEnableCameraLag = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AEchoesShipPawn_Statics::NewProp_bEnableCameraLag = { "bEnableCameraLag", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AEchoesShipPawn), &Z_Construct_UClass_AEchoesShipPawn_Statics::NewProp_bEnableCameraLag_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableCameraLag_MetaData), NewProp_bEnableCameraLag_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEchoesShipPawn_Statics::NewProp_CameraPitch = { "CameraPitch", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesShipPawn, CameraPitch), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraPitch_MetaData), NewProp_CameraPitch_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEchoesShipPawn_Statics::NewProp_MouseSensitivity = { "MouseSensitivity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesShipPawn, MouseSensitivity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MouseSensitivity_MetaData), NewProp_MouseSensitivity_MetaData) };
void Z_Construct_UClass_AEchoesShipPawn_Statics::NewProp_bFreeLookActive_SetBit(void* Obj)
{
	((AEchoesShipPawn*)Obj)->bFreeLookActive = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AEchoesShipPawn_Statics::NewProp_bFreeLookActive = { "bFreeLookActive", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AEchoesShipPawn), &Z_Construct_UClass_AEchoesShipPawn_Statics::NewProp_bFreeLookActive_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bFreeLookActive_MetaData), NewProp_bFreeLookActive_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AEchoesShipPawn_Statics::NewProp_ReplicatedShipStats = { "ReplicatedShipStats", "OnRep_ShipStats", (EPropertyFlags)0x0020080100000034, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesShipPawn, ReplicatedShipStats), Z_Construct_UScriptStruct_FEchoesShipStats, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReplicatedShipStats_MetaData), NewProp_ReplicatedShipStats_MetaData) }; // 652073936
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEchoesShipPawn_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesShipPawn_Statics::NewProp_ShipMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesShipPawn_Statics::NewProp_ShipMovement,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesShipPawn_Statics::NewProp_SpringArm,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesShipPawn_Statics::NewProp_Camera,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesShipPawn_Statics::NewProp_InputMapping,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesShipPawn_Statics::NewProp_MoveAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesShipPawn_Statics::NewProp_LookAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesShipPawn_Statics::NewProp_MouseFollowAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesShipPawn_Statics::NewProp_WarpAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesShipPawn_Statics::NewProp_FreeLookAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesShipPawn_Statics::NewProp_CameraDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesShipPawn_Statics::NewProp_CameraLagSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesShipPawn_Statics::NewProp_bEnableCameraLag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesShipPawn_Statics::NewProp_CameraPitch,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesShipPawn_Statics::NewProp_MouseSensitivity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesShipPawn_Statics::NewProp_bFreeLookActive,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesShipPawn_Statics::NewProp_ReplicatedShipStats,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEchoesShipPawn_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AEchoesShipPawn_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APawn,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEchoesShipPawn_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AEchoesShipPawn_Statics::ClassParams = {
	&AEchoesShipPawn::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AEchoesShipPawn_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AEchoesShipPawn_Statics::PropPointers),
	0,
	0x009001A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEchoesShipPawn_Statics::Class_MetaDataParams), Z_Construct_UClass_AEchoesShipPawn_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AEchoesShipPawn()
{
	if (!Z_Registration_Info_UClass_AEchoesShipPawn.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEchoesShipPawn.OuterSingleton, Z_Construct_UClass_AEchoesShipPawn_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AEchoesShipPawn.OuterSingleton;
}
#if VALIDATE_CLASS_REPS
void AEchoesShipPawn::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static FName Name_ReplicatedShipStats(TEXT("ReplicatedShipStats"));
	const bool bIsValid = true
		&& Name_ReplicatedShipStats == ClassReps[(int32)ENetFields_Private::ReplicatedShipStats].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in AEchoesShipPawn"));
}
#endif
DEFINE_VTABLE_PTR_HELPER_CTOR(AEchoesShipPawn);
AEchoesShipPawn::~AEchoesShipPawn() {}
// ********** End Class AEchoesShipPawn ************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Client_EchoesShipPawn_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AEchoesShipPawn, AEchoesShipPawn::StaticClass, TEXT("AEchoesShipPawn"), &Z_Registration_Info_UClass_AEchoesShipPawn, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEchoesShipPawn), 3513169178U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Client_EchoesShipPawn_h__Script_Echoes_4191918352(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Client_EchoesShipPawn_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Client_EchoesShipPawn_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
