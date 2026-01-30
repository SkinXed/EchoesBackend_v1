// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Echoes/Core/Common/EchoesShipMovementComponent.h"
#include "Echoes/Core/Common/EchoesShipTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesShipMovementComponent() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ECHOES_API UClass* Z_Construct_UClass_UEchoesShipMovementComponent();
ECHOES_API UClass* Z_Construct_UClass_UEchoesShipMovementComponent_NoRegister();
ECHOES_API UEnum* Z_Construct_UEnum_Echoes_EWarpState();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FEchoesShipStats();
ENGINE_API UClass* Z_Construct_UClass_UMovementComponent();
ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UEchoesShipMovementComponent Function CancelWarp *************************
struct Z_Construct_UFunction_UEchoesShipMovementComponent_CancelWarp_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Warp" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Cancel current warp */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesShipMovementComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cancel current warp" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesShipMovementComponent_CancelWarp_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesShipMovementComponent, nullptr, "CancelWarp", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesShipMovementComponent_CancelWarp_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesShipMovementComponent_CancelWarp_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesShipMovementComponent_CancelWarp()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesShipMovementComponent_CancelWarp_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesShipMovementComponent::execCancelWarp)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CancelWarp();
	P_NATIVE_END;
}
// ********** End Class UEchoesShipMovementComponent Function CancelWarp ***************************

// ********** Begin Class UEchoesShipMovementComponent Function CanEnterWarp ***********************
struct Z_Construct_UFunction_UEchoesShipMovementComponent_CanEnterWarp_Statics
{
	struct EchoesShipMovementComponent_eventCanEnterWarp_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Warp" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Check if ship can warp (alignment threshold) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesShipMovementComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if ship can warp (alignment threshold)" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UEchoesShipMovementComponent_CanEnterWarp_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((EchoesShipMovementComponent_eventCanEnterWarp_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UEchoesShipMovementComponent_CanEnterWarp_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EchoesShipMovementComponent_eventCanEnterWarp_Parms), &Z_Construct_UFunction_UEchoesShipMovementComponent_CanEnterWarp_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesShipMovementComponent_CanEnterWarp_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesShipMovementComponent_CanEnterWarp_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesShipMovementComponent_CanEnterWarp_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesShipMovementComponent_CanEnterWarp_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesShipMovementComponent, nullptr, "CanEnterWarp", Z_Construct_UFunction_UEchoesShipMovementComponent_CanEnterWarp_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesShipMovementComponent_CanEnterWarp_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesShipMovementComponent_CanEnterWarp_Statics::EchoesShipMovementComponent_eventCanEnterWarp_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesShipMovementComponent_CanEnterWarp_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesShipMovementComponent_CanEnterWarp_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesShipMovementComponent_CanEnterWarp_Statics::EchoesShipMovementComponent_eventCanEnterWarp_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesShipMovementComponent_CanEnterWarp()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesShipMovementComponent_CanEnterWarp_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesShipMovementComponent::execCanEnterWarp)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->CanEnterWarp();
	P_NATIVE_END;
}
// ********** End Class UEchoesShipMovementComponent Function CanEnterWarp *************************

// ********** Begin Class UEchoesShipMovementComponent Function Common_CalculateAlignTime **********
struct Z_Construct_UFunction_UEchoesShipMovementComponent_Common_CalculateAlignTime_Statics
{
	struct EchoesShipMovementComponent_eventCommon_CalculateAlignTime_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ship Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Calculate alignment time using EVE formula: (Inertia * Mass) / 500,000 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesShipMovementComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Calculate alignment time using EVE formula: (Inertia * Mass) / 500,000" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UEchoesShipMovementComponent_Common_CalculateAlignTime_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesShipMovementComponent_eventCommon_CalculateAlignTime_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesShipMovementComponent_Common_CalculateAlignTime_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesShipMovementComponent_Common_CalculateAlignTime_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesShipMovementComponent_Common_CalculateAlignTime_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesShipMovementComponent_Common_CalculateAlignTime_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesShipMovementComponent, nullptr, "Common_CalculateAlignTime", Z_Construct_UFunction_UEchoesShipMovementComponent_Common_CalculateAlignTime_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesShipMovementComponent_Common_CalculateAlignTime_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesShipMovementComponent_Common_CalculateAlignTime_Statics::EchoesShipMovementComponent_eventCommon_CalculateAlignTime_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesShipMovementComponent_Common_CalculateAlignTime_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesShipMovementComponent_Common_CalculateAlignTime_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesShipMovementComponent_Common_CalculateAlignTime_Statics::EchoesShipMovementComponent_eventCommon_CalculateAlignTime_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesShipMovementComponent_Common_CalculateAlignTime()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesShipMovementComponent_Common_CalculateAlignTime_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesShipMovementComponent::execCommon_CalculateAlignTime)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->Common_CalculateAlignTime();
	P_NATIVE_END;
}
// ********** End Class UEchoesShipMovementComponent Function Common_CalculateAlignTime ************

// ********** Begin Class UEchoesShipMovementComponent Function InitializeShipStats ****************
struct Z_Construct_UFunction_UEchoesShipMovementComponent_InitializeShipStats_Statics
{
	struct EchoesShipMovementComponent_eventInitializeShipStats_Parms
	{
		FEchoesShipStats NewStats;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ship Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Initialize ship stats (typically from backend API response) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesShipMovementComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Initialize ship stats (typically from backend API response)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NewStats_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_NewStats;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesShipMovementComponent_InitializeShipStats_Statics::NewProp_NewStats = { "NewStats", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesShipMovementComponent_eventInitializeShipStats_Parms, NewStats), Z_Construct_UScriptStruct_FEchoesShipStats, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NewStats_MetaData), NewProp_NewStats_MetaData) }; // 652073936
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesShipMovementComponent_InitializeShipStats_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesShipMovementComponent_InitializeShipStats_Statics::NewProp_NewStats,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesShipMovementComponent_InitializeShipStats_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesShipMovementComponent_InitializeShipStats_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesShipMovementComponent, nullptr, "InitializeShipStats", Z_Construct_UFunction_UEchoesShipMovementComponent_InitializeShipStats_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesShipMovementComponent_InitializeShipStats_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesShipMovementComponent_InitializeShipStats_Statics::EchoesShipMovementComponent_eventInitializeShipStats_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesShipMovementComponent_InitializeShipStats_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesShipMovementComponent_InitializeShipStats_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesShipMovementComponent_InitializeShipStats_Statics::EchoesShipMovementComponent_eventInitializeShipStats_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesShipMovementComponent_InitializeShipStats()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesShipMovementComponent_InitializeShipStats_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesShipMovementComponent::execInitializeShipStats)
{
	P_GET_STRUCT_REF(FEchoesShipStats,Z_Param_Out_NewStats);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializeShipStats(Z_Param_Out_NewStats);
	P_NATIVE_END;
}
// ********** End Class UEchoesShipMovementComponent Function InitializeShipStats ******************

// ********** Begin Class UEchoesShipMovementComponent Function InitiateWarp ***********************
struct Z_Construct_UFunction_UEchoesShipMovementComponent_InitiateWarp_Statics
{
	struct EchoesShipMovementComponent_eventInitiateWarp_Parms
	{
		FVector TargetLocation;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Warp" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Initiate warp to target location */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesShipMovementComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Initiate warp to target location" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetLocation;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesShipMovementComponent_InitiateWarp_Statics::NewProp_TargetLocation = { "TargetLocation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesShipMovementComponent_eventInitiateWarp_Parms, TargetLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesShipMovementComponent_InitiateWarp_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesShipMovementComponent_InitiateWarp_Statics::NewProp_TargetLocation,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesShipMovementComponent_InitiateWarp_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesShipMovementComponent_InitiateWarp_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesShipMovementComponent, nullptr, "InitiateWarp", Z_Construct_UFunction_UEchoesShipMovementComponent_InitiateWarp_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesShipMovementComponent_InitiateWarp_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesShipMovementComponent_InitiateWarp_Statics::EchoesShipMovementComponent_eventInitiateWarp_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesShipMovementComponent_InitiateWarp_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesShipMovementComponent_InitiateWarp_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesShipMovementComponent_InitiateWarp_Statics::EchoesShipMovementComponent_eventInitiateWarp_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesShipMovementComponent_InitiateWarp()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesShipMovementComponent_InitiateWarp_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesShipMovementComponent::execInitiateWarp)
{
	P_GET_STRUCT(FVector,Z_Param_TargetLocation);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitiateWarp(Z_Param_TargetLocation);
	P_NATIVE_END;
}
// ********** End Class UEchoesShipMovementComponent Function InitiateWarp *************************

// ********** Begin Class UEchoesShipMovementComponent Function SetMouseFollowEnabled **************
struct Z_Construct_UFunction_UEchoesShipMovementComponent_SetMouseFollowEnabled_Statics
{
	struct EchoesShipMovementComponent_eventSetMouseFollowEnabled_Parms
	{
		bool bEnabled;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Enable/disable mouse follow */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesShipMovementComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Enable/disable mouse follow" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_bEnabled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UEchoesShipMovementComponent_SetMouseFollowEnabled_Statics::NewProp_bEnabled_SetBit(void* Obj)
{
	((EchoesShipMovementComponent_eventSetMouseFollowEnabled_Parms*)Obj)->bEnabled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UEchoesShipMovementComponent_SetMouseFollowEnabled_Statics::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EchoesShipMovementComponent_eventSetMouseFollowEnabled_Parms), &Z_Construct_UFunction_UEchoesShipMovementComponent_SetMouseFollowEnabled_Statics::NewProp_bEnabled_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesShipMovementComponent_SetMouseFollowEnabled_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesShipMovementComponent_SetMouseFollowEnabled_Statics::NewProp_bEnabled,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesShipMovementComponent_SetMouseFollowEnabled_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesShipMovementComponent_SetMouseFollowEnabled_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesShipMovementComponent, nullptr, "SetMouseFollowEnabled", Z_Construct_UFunction_UEchoesShipMovementComponent_SetMouseFollowEnabled_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesShipMovementComponent_SetMouseFollowEnabled_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesShipMovementComponent_SetMouseFollowEnabled_Statics::EchoesShipMovementComponent_eventSetMouseFollowEnabled_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesShipMovementComponent_SetMouseFollowEnabled_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesShipMovementComponent_SetMouseFollowEnabled_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesShipMovementComponent_SetMouseFollowEnabled_Statics::EchoesShipMovementComponent_eventSetMouseFollowEnabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesShipMovementComponent_SetMouseFollowEnabled()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesShipMovementComponent_SetMouseFollowEnabled_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesShipMovementComponent::execSetMouseFollowEnabled)
{
	P_GET_UBOOL(Z_Param_bEnabled);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetMouseFollowEnabled(Z_Param_bEnabled);
	P_NATIVE_END;
}
// ********** End Class UEchoesShipMovementComponent Function SetMouseFollowEnabled ****************

// ********** Begin Class UEchoesShipMovementComponent Function SetMovementInput *******************
struct Z_Construct_UFunction_UEchoesShipMovementComponent_SetMovementInput_Statics
{
	struct EchoesShipMovementComponent_eventSetMovementInput_Parms
	{
		FVector Input;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Set movement input (WASD) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesShipMovementComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set movement input (WASD)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Input;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesShipMovementComponent_SetMovementInput_Statics::NewProp_Input = { "Input", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesShipMovementComponent_eventSetMovementInput_Parms, Input), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesShipMovementComponent_SetMovementInput_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesShipMovementComponent_SetMovementInput_Statics::NewProp_Input,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesShipMovementComponent_SetMovementInput_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesShipMovementComponent_SetMovementInput_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesShipMovementComponent, nullptr, "SetMovementInput", Z_Construct_UFunction_UEchoesShipMovementComponent_SetMovementInput_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesShipMovementComponent_SetMovementInput_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesShipMovementComponent_SetMovementInput_Statics::EchoesShipMovementComponent_eventSetMovementInput_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesShipMovementComponent_SetMovementInput_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesShipMovementComponent_SetMovementInput_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesShipMovementComponent_SetMovementInput_Statics::EchoesShipMovementComponent_eventSetMovementInput_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesShipMovementComponent_SetMovementInput()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesShipMovementComponent_SetMovementInput_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesShipMovementComponent::execSetMovementInput)
{
	P_GET_STRUCT(FVector,Z_Param_Input);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetMovementInput(Z_Param_Input);
	P_NATIVE_END;
}
// ********** End Class UEchoesShipMovementComponent Function SetMovementInput *********************

// ********** Begin Class UEchoesShipMovementComponent Function SetTargetDirection *****************
struct Z_Construct_UFunction_UEchoesShipMovementComponent_SetTargetDirection_Statics
{
	struct EchoesShipMovementComponent_eventSetTargetDirection_Parms
	{
		FVector Direction;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Set target direction for mouse follow */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesShipMovementComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set target direction for mouse follow" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Direction;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesShipMovementComponent_SetTargetDirection_Statics::NewProp_Direction = { "Direction", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesShipMovementComponent_eventSetTargetDirection_Parms, Direction), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesShipMovementComponent_SetTargetDirection_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesShipMovementComponent_SetTargetDirection_Statics::NewProp_Direction,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesShipMovementComponent_SetTargetDirection_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesShipMovementComponent_SetTargetDirection_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesShipMovementComponent, nullptr, "SetTargetDirection", Z_Construct_UFunction_UEchoesShipMovementComponent_SetTargetDirection_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesShipMovementComponent_SetTargetDirection_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesShipMovementComponent_SetTargetDirection_Statics::EchoesShipMovementComponent_eventSetTargetDirection_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesShipMovementComponent_SetTargetDirection_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesShipMovementComponent_SetTargetDirection_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesShipMovementComponent_SetTargetDirection_Statics::EchoesShipMovementComponent_eventSetTargetDirection_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesShipMovementComponent_SetTargetDirection()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesShipMovementComponent_SetTargetDirection_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesShipMovementComponent::execSetTargetDirection)
{
	P_GET_STRUCT(FVector,Z_Param_Direction);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetTargetDirection(Z_Param_Direction);
	P_NATIVE_END;
}
// ********** End Class UEchoesShipMovementComponent Function SetTargetDirection *******************

// ********** Begin Class UEchoesShipMovementComponent *********************************************
void UEchoesShipMovementComponent::StaticRegisterNativesUEchoesShipMovementComponent()
{
	UClass* Class = UEchoesShipMovementComponent::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "CancelWarp", &UEchoesShipMovementComponent::execCancelWarp },
		{ "CanEnterWarp", &UEchoesShipMovementComponent::execCanEnterWarp },
		{ "Common_CalculateAlignTime", &UEchoesShipMovementComponent::execCommon_CalculateAlignTime },
		{ "InitializeShipStats", &UEchoesShipMovementComponent::execInitializeShipStats },
		{ "InitiateWarp", &UEchoesShipMovementComponent::execInitiateWarp },
		{ "SetMouseFollowEnabled", &UEchoesShipMovementComponent::execSetMouseFollowEnabled },
		{ "SetMovementInput", &UEchoesShipMovementComponent::execSetMovementInput },
		{ "SetTargetDirection", &UEchoesShipMovementComponent::execSetTargetDirection },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UEchoesShipMovementComponent;
UClass* UEchoesShipMovementComponent::GetPrivateStaticClass()
{
	using TClass = UEchoesShipMovementComponent;
	if (!Z_Registration_Info_UClass_UEchoesShipMovementComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesShipMovementComponent"),
			Z_Registration_Info_UClass_UEchoesShipMovementComponent.InnerSingleton,
			StaticRegisterNativesUEchoesShipMovementComponent,
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
	return Z_Registration_Info_UClass_UEchoesShipMovementComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UEchoesShipMovementComponent_NoRegister()
{
	return UEchoesShipMovementComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UEchoesShipMovementComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * EVE-like ship movement component\n * Implements physics-based movement with thrust, rotation, and warp mechanics\n * Follows naming convention: Common_ for shared methods, ServerRPC_/ClientRPC_ for network\n */" },
#endif
		{ "IncludePath", "Core/Common/EchoesShipMovementComponent.h" },
		{ "ModuleRelativePath", "Core/Common/EchoesShipMovementComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "EVE-like ship movement component\nImplements physics-based movement with thrust, rotation, and warp mechanics\nFollows naming convention: Common_ for shared methods, ServerRPC_/ClientRPC_ for network" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShipStats_MetaData[] = {
		{ "Category", "Ship Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current ship stats loaded from backend */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesShipMovementComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current ship stats loaded from backend" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MovementInput_MetaData[] = {
		{ "Category", "Movement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current movement input (-1 to 1 for each axis) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesShipMovementComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current movement input (-1 to 1 for each axis)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetDirection_MetaData[] = {
		{ "Category", "Movement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Target direction vector for alignment (e.g., from mouse cursor) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesShipMovementComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Target direction vector for alignment (e.g., from mouse cursor)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bMouseFollowEnabled_MetaData[] = {
		{ "Category", "Movement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether mouse follow is active */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesShipMovementComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether mouse follow is active" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WarpState_MetaData[] = {
		{ "Category", "Warp" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current warp state */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesShipMovementComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current warp state" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WarpTargetLocation_MetaData[] = {
		{ "Category", "Warp" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Target location for warp */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesShipMovementComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Target location for warp" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PDController_kP_MetaData[] = {
		{ "Category", "Movement|Config|PD Controller" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** PD Controller Proportional gain for alignment torque */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesShipMovementComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "PD Controller Proportional gain for alignment torque" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PDController_kD_MetaData[] = {
		{ "Category", "Movement|Config|PD Controller" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** PD Controller Derivative gain for damping */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesShipMovementComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "PD Controller Derivative gain for damping" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RotationInterpSpeed_MetaData[] = {
		{ "Category", "Movement|Config" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Rotation interpolation speed for alignment (deprecated, use PD controller) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesShipMovementComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Rotation interpolation speed for alignment (deprecated, use PD controller)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WarpAlignmentThreshold_MetaData[] = {
		{ "Category", "Warp|Config" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Alignment threshold in degrees to enter warp */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesShipMovementComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Alignment threshold in degrees to enter warp" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WarpSpeedThreshold_MetaData[] = {
		{ "Category", "Warp|Config" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Percentage of max speed required before entering warp */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesShipMovementComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Percentage of max speed required before entering warp" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WarpVelocityAlignmentThreshold_MetaData[] = {
		{ "Category", "Warp|Config" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Velocity vector alignment threshold (dot product) for warp entry */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesShipMovementComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Velocity vector alignment threshold (dot product) for warp entry" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WarpSpeedMultiplier_MetaData[] = {
		{ "Category", "Warp|Config" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Warp speed multiplier when in warp */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesShipMovementComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Warp speed multiplier when in warp" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DampingFactor_MetaData[] = {
		{ "Category", "Movement|Config" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Damping factor when no input (0-1) - DEPRECATED, use linear damping */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesShipMovementComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Damping factor when no input (0-1) - DEPRECATED, use linear damping" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinVelocityForDamping_MetaData[] = {
		{ "Category", "Movement|Config" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Minimum velocity threshold to apply damping */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesShipMovementComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Minimum velocity threshold to apply damping" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AlignTimeConstant_MetaData[] = {
		{ "Category", "Movement|Config" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Constant for align time calculation (EVE formula) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesShipMovementComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Constant for align time calculation (EVE formula)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PrimitiveComponent_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Cached primitive component for physics */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/EchoesShipMovementComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cached primitive component for physics" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ShipStats;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MovementInput;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetDirection;
	static void NewProp_bMouseFollowEnabled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bMouseFollowEnabled;
	static const UECodeGen_Private::FBytePropertyParams NewProp_WarpState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_WarpState;
	static const UECodeGen_Private::FStructPropertyParams NewProp_WarpTargetLocation;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PDController_kP;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PDController_kD;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RotationInterpSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WarpAlignmentThreshold;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WarpSpeedThreshold;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WarpVelocityAlignmentThreshold;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WarpSpeedMultiplier;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DampingFactor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinVelocityForDamping;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AlignTimeConstant;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PrimitiveComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UEchoesShipMovementComponent_CancelWarp, "CancelWarp" }, // 1373705936
		{ &Z_Construct_UFunction_UEchoesShipMovementComponent_CanEnterWarp, "CanEnterWarp" }, // 150054134
		{ &Z_Construct_UFunction_UEchoesShipMovementComponent_Common_CalculateAlignTime, "Common_CalculateAlignTime" }, // 1294058708
		{ &Z_Construct_UFunction_UEchoesShipMovementComponent_InitializeShipStats, "InitializeShipStats" }, // 992875871
		{ &Z_Construct_UFunction_UEchoesShipMovementComponent_InitiateWarp, "InitiateWarp" }, // 81575054
		{ &Z_Construct_UFunction_UEchoesShipMovementComponent_SetMouseFollowEnabled, "SetMouseFollowEnabled" }, // 3927419169
		{ &Z_Construct_UFunction_UEchoesShipMovementComponent_SetMovementInput, "SetMovementInput" }, // 3908016168
		{ &Z_Construct_UFunction_UEchoesShipMovementComponent_SetTargetDirection, "SetTargetDirection" }, // 3826064608
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEchoesShipMovementComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEchoesShipMovementComponent_Statics::NewProp_ShipStats = { "ShipStats", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesShipMovementComponent, ShipStats), Z_Construct_UScriptStruct_FEchoesShipStats, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShipStats_MetaData), NewProp_ShipStats_MetaData) }; // 652073936
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEchoesShipMovementComponent_Statics::NewProp_MovementInput = { "MovementInput", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesShipMovementComponent, MovementInput), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MovementInput_MetaData), NewProp_MovementInput_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEchoesShipMovementComponent_Statics::NewProp_TargetDirection = { "TargetDirection", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesShipMovementComponent, TargetDirection), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetDirection_MetaData), NewProp_TargetDirection_MetaData) };
void Z_Construct_UClass_UEchoesShipMovementComponent_Statics::NewProp_bMouseFollowEnabled_SetBit(void* Obj)
{
	((UEchoesShipMovementComponent*)Obj)->bMouseFollowEnabled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UEchoesShipMovementComponent_Statics::NewProp_bMouseFollowEnabled = { "bMouseFollowEnabled", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UEchoesShipMovementComponent), &Z_Construct_UClass_UEchoesShipMovementComponent_Statics::NewProp_bMouseFollowEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bMouseFollowEnabled_MetaData), NewProp_bMouseFollowEnabled_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UEchoesShipMovementComponent_Statics::NewProp_WarpState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UEchoesShipMovementComponent_Statics::NewProp_WarpState = { "WarpState", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesShipMovementComponent, WarpState), Z_Construct_UEnum_Echoes_EWarpState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WarpState_MetaData), NewProp_WarpState_MetaData) }; // 3995642217
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEchoesShipMovementComponent_Statics::NewProp_WarpTargetLocation = { "WarpTargetLocation", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesShipMovementComponent, WarpTargetLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WarpTargetLocation_MetaData), NewProp_WarpTargetLocation_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEchoesShipMovementComponent_Statics::NewProp_PDController_kP = { "PDController_kP", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesShipMovementComponent, PDController_kP), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PDController_kP_MetaData), NewProp_PDController_kP_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEchoesShipMovementComponent_Statics::NewProp_PDController_kD = { "PDController_kD", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesShipMovementComponent, PDController_kD), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PDController_kD_MetaData), NewProp_PDController_kD_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEchoesShipMovementComponent_Statics::NewProp_RotationInterpSpeed = { "RotationInterpSpeed", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesShipMovementComponent, RotationInterpSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RotationInterpSpeed_MetaData), NewProp_RotationInterpSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEchoesShipMovementComponent_Statics::NewProp_WarpAlignmentThreshold = { "WarpAlignmentThreshold", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesShipMovementComponent, WarpAlignmentThreshold), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WarpAlignmentThreshold_MetaData), NewProp_WarpAlignmentThreshold_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEchoesShipMovementComponent_Statics::NewProp_WarpSpeedThreshold = { "WarpSpeedThreshold", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesShipMovementComponent, WarpSpeedThreshold), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WarpSpeedThreshold_MetaData), NewProp_WarpSpeedThreshold_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEchoesShipMovementComponent_Statics::NewProp_WarpVelocityAlignmentThreshold = { "WarpVelocityAlignmentThreshold", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesShipMovementComponent, WarpVelocityAlignmentThreshold), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WarpVelocityAlignmentThreshold_MetaData), NewProp_WarpVelocityAlignmentThreshold_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEchoesShipMovementComponent_Statics::NewProp_WarpSpeedMultiplier = { "WarpSpeedMultiplier", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesShipMovementComponent, WarpSpeedMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WarpSpeedMultiplier_MetaData), NewProp_WarpSpeedMultiplier_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEchoesShipMovementComponent_Statics::NewProp_DampingFactor = { "DampingFactor", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesShipMovementComponent, DampingFactor), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DampingFactor_MetaData), NewProp_DampingFactor_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEchoesShipMovementComponent_Statics::NewProp_MinVelocityForDamping = { "MinVelocityForDamping", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesShipMovementComponent, MinVelocityForDamping), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinVelocityForDamping_MetaData), NewProp_MinVelocityForDamping_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEchoesShipMovementComponent_Statics::NewProp_AlignTimeConstant = { "AlignTimeConstant", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesShipMovementComponent, AlignTimeConstant), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AlignTimeConstant_MetaData), NewProp_AlignTimeConstant_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesShipMovementComponent_Statics::NewProp_PrimitiveComponent = { "PrimitiveComponent", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesShipMovementComponent, PrimitiveComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PrimitiveComponent_MetaData), NewProp_PrimitiveComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEchoesShipMovementComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesShipMovementComponent_Statics::NewProp_ShipStats,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesShipMovementComponent_Statics::NewProp_MovementInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesShipMovementComponent_Statics::NewProp_TargetDirection,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesShipMovementComponent_Statics::NewProp_bMouseFollowEnabled,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesShipMovementComponent_Statics::NewProp_WarpState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesShipMovementComponent_Statics::NewProp_WarpState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesShipMovementComponent_Statics::NewProp_WarpTargetLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesShipMovementComponent_Statics::NewProp_PDController_kP,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesShipMovementComponent_Statics::NewProp_PDController_kD,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesShipMovementComponent_Statics::NewProp_RotationInterpSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesShipMovementComponent_Statics::NewProp_WarpAlignmentThreshold,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesShipMovementComponent_Statics::NewProp_WarpSpeedThreshold,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesShipMovementComponent_Statics::NewProp_WarpVelocityAlignmentThreshold,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesShipMovementComponent_Statics::NewProp_WarpSpeedMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesShipMovementComponent_Statics::NewProp_DampingFactor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesShipMovementComponent_Statics::NewProp_MinVelocityForDamping,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesShipMovementComponent_Statics::NewProp_AlignTimeConstant,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesShipMovementComponent_Statics::NewProp_PrimitiveComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesShipMovementComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UEchoesShipMovementComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UMovementComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesShipMovementComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEchoesShipMovementComponent_Statics::ClassParams = {
	&UEchoesShipMovementComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UEchoesShipMovementComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesShipMovementComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesShipMovementComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UEchoesShipMovementComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEchoesShipMovementComponent()
{
	if (!Z_Registration_Info_UClass_UEchoesShipMovementComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEchoesShipMovementComponent.OuterSingleton, Z_Construct_UClass_UEchoesShipMovementComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEchoesShipMovementComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UEchoesShipMovementComponent);
UEchoesShipMovementComponent::~UEchoesShipMovementComponent() {}
// ********** End Class UEchoesShipMovementComponent ***********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesShipMovementComponent_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEchoesShipMovementComponent, UEchoesShipMovementComponent::StaticClass, TEXT("UEchoesShipMovementComponent"), &Z_Registration_Info_UClass_UEchoesShipMovementComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEchoesShipMovementComponent), 751704119U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesShipMovementComponent_h__Script_Echoes_2560901498(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesShipMovementComponent_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesShipMovementComponent_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
