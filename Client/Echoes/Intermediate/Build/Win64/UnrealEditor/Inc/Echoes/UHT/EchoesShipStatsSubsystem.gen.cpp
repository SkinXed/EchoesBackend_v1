// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EchoesShipStatsSubsystem.h"
#include "EchoesShipTypes.h"
#include "Engine/GameInstance.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesShipStatsSubsystem() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ECHOES_API UClass* Z_Construct_UClass_UEchoesShipStatsSubsystem();
ECHOES_API UClass* Z_Construct_UClass_UEchoesShipStatsSubsystem_NoRegister();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnApiError__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnModuleAdded__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnShipStatsFetched__DelegateSignature();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FEchoesShipStats();
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FOnShipStatsFetched ***************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnShipStatsFetched__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnShipStatsFetched_Parms
	{
		FEchoesShipStats Stats;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Delegate types for async callbacks (must be declared before class)\n" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesShipStatsSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Delegate types for async callbacks (must be declared before class)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Stats_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Stats;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_Echoes_OnShipStatsFetched__DelegateSignature_Statics::NewProp_Stats = { "Stats", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnShipStatsFetched_Parms, Stats), Z_Construct_UScriptStruct_FEchoesShipStats, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Stats_MetaData), NewProp_Stats_MetaData) }; // 2315152803
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnShipStatsFetched__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnShipStatsFetched__DelegateSignature_Statics::NewProp_Stats,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnShipStatsFetched__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnShipStatsFetched__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnShipStatsFetched__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnShipStatsFetched__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnShipStatsFetched__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnShipStatsFetched__DelegateSignature_Statics::_Script_Echoes_eventOnShipStatsFetched_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00520000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnShipStatsFetched__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnShipStatsFetched__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnShipStatsFetched__DelegateSignature_Statics::_Script_Echoes_eventOnShipStatsFetched_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnShipStatsFetched__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnShipStatsFetched__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnShipStatsFetched_DelegateWrapper(const FScriptDelegate& OnShipStatsFetched, FEchoesShipStats const& Stats)
{
	struct _Script_Echoes_eventOnShipStatsFetched_Parms
	{
		FEchoesShipStats Stats;
	};
	_Script_Echoes_eventOnShipStatsFetched_Parms Parms;
	Parms.Stats=Stats;
	OnShipStatsFetched.ProcessDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnShipStatsFetched *****************************************************

// ********** Begin Delegate FOnModuleAdded ********************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnModuleAdded__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnModuleAdded_Parms
	{
		bool bSuccess;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesShipStatsSubsystem.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bSuccess_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
void Z_Construct_UDelegateFunction_Echoes_OnModuleAdded__DelegateSignature_Statics::NewProp_bSuccess_SetBit(void* Obj)
{
	((_Script_Echoes_eventOnModuleAdded_Parms*)Obj)->bSuccess = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_Echoes_OnModuleAdded__DelegateSignature_Statics::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_Echoes_eventOnModuleAdded_Parms), &Z_Construct_UDelegateFunction_Echoes_OnModuleAdded__DelegateSignature_Statics::NewProp_bSuccess_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnModuleAdded__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnModuleAdded__DelegateSignature_Statics::NewProp_bSuccess,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnModuleAdded__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnModuleAdded__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnModuleAdded__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnModuleAdded__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnModuleAdded__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnModuleAdded__DelegateSignature_Statics::_Script_Echoes_eventOnModuleAdded_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnModuleAdded__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnModuleAdded__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnModuleAdded__DelegateSignature_Statics::_Script_Echoes_eventOnModuleAdded_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnModuleAdded__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnModuleAdded__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnModuleAdded_DelegateWrapper(const FScriptDelegate& OnModuleAdded, bool bSuccess)
{
	struct _Script_Echoes_eventOnModuleAdded_Parms
	{
		bool bSuccess;
	};
	_Script_Echoes_eventOnModuleAdded_Parms Parms;
	Parms.bSuccess=bSuccess ? true : false;
	OnModuleAdded.ProcessDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnModuleAdded **********************************************************

// ********** Begin Delegate FOnApiError ***********************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnApiError__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnApiError_Parms
	{
		FString ErrorMessage;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesShipStatsSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_Echoes_OnApiError__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnApiError_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ErrorMessage_MetaData), NewProp_ErrorMessage_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnApiError__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnApiError__DelegateSignature_Statics::NewProp_ErrorMessage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnApiError__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnApiError__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnApiError__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnApiError__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnApiError__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnApiError__DelegateSignature_Statics::_Script_Echoes_eventOnApiError_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnApiError__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnApiError__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnApiError__DelegateSignature_Statics::_Script_Echoes_eventOnApiError_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnApiError__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnApiError__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnApiError_DelegateWrapper(const FScriptDelegate& OnApiError, const FString& ErrorMessage)
{
	struct _Script_Echoes_eventOnApiError_Parms
	{
		FString ErrorMessage;
	};
	_Script_Echoes_eventOnApiError_Parms Parms;
	Parms.ErrorMessage=ErrorMessage;
	OnApiError.ProcessDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnApiError *************************************************************

// ********** Begin Class UEchoesShipStatsSubsystem Function AddModule *****************************
struct Z_Construct_UFunction_UEchoesShipStatsSubsystem_AddModule_Statics
{
	struct EchoesShipStatsSubsystem_eventAddModule_Parms
	{
		FGuid ShipInstanceId;
		int32 ModuleTypeId;
		float Mass;
		FString Slot;
		FScriptDelegate OnSuccess;
		FScriptDelegate OnError;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ship Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Add module to ship\n     * POST /api/ship/{id}/modules\n     */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesShipStatsSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Add module to ship\nPOST /api/ship/{id}/modules" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnSuccess_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnError_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ShipInstanceId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ModuleTypeId;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Mass;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Slot;
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnSuccess;
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnError;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesShipStatsSubsystem_AddModule_Statics::NewProp_ShipInstanceId = { "ShipInstanceId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesShipStatsSubsystem_eventAddModule_Parms, ShipInstanceId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UEchoesShipStatsSubsystem_AddModule_Statics::NewProp_ModuleTypeId = { "ModuleTypeId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesShipStatsSubsystem_eventAddModule_Parms, ModuleTypeId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UEchoesShipStatsSubsystem_AddModule_Statics::NewProp_Mass = { "Mass", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesShipStatsSubsystem_eventAddModule_Parms, Mass), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEchoesShipStatsSubsystem_AddModule_Statics::NewProp_Slot = { "Slot", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesShipStatsSubsystem_eventAddModule_Parms, Slot), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UEchoesShipStatsSubsystem_AddModule_Statics::NewProp_OnSuccess = { "OnSuccess", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesShipStatsSubsystem_eventAddModule_Parms, OnSuccess), Z_Construct_UDelegateFunction_Echoes_OnModuleAdded__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnSuccess_MetaData), NewProp_OnSuccess_MetaData) }; // 1220523253
const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UEchoesShipStatsSubsystem_AddModule_Statics::NewProp_OnError = { "OnError", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesShipStatsSubsystem_eventAddModule_Parms, OnError), Z_Construct_UDelegateFunction_Echoes_OnApiError__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnError_MetaData), NewProp_OnError_MetaData) }; // 790282548
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesShipStatsSubsystem_AddModule_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesShipStatsSubsystem_AddModule_Statics::NewProp_ShipInstanceId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesShipStatsSubsystem_AddModule_Statics::NewProp_ModuleTypeId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesShipStatsSubsystem_AddModule_Statics::NewProp_Mass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesShipStatsSubsystem_AddModule_Statics::NewProp_Slot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesShipStatsSubsystem_AddModule_Statics::NewProp_OnSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesShipStatsSubsystem_AddModule_Statics::NewProp_OnError,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesShipStatsSubsystem_AddModule_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesShipStatsSubsystem_AddModule_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesShipStatsSubsystem, nullptr, "AddModule", Z_Construct_UFunction_UEchoesShipStatsSubsystem_AddModule_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesShipStatsSubsystem_AddModule_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesShipStatsSubsystem_AddModule_Statics::EchoesShipStatsSubsystem_eventAddModule_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesShipStatsSubsystem_AddModule_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesShipStatsSubsystem_AddModule_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesShipStatsSubsystem_AddModule_Statics::EchoesShipStatsSubsystem_eventAddModule_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesShipStatsSubsystem_AddModule()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesShipStatsSubsystem_AddModule_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesShipStatsSubsystem::execAddModule)
{
	P_GET_STRUCT(FGuid,Z_Param_ShipInstanceId);
	P_GET_PROPERTY(FIntProperty,Z_Param_ModuleTypeId);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Mass);
	P_GET_PROPERTY(FStrProperty,Z_Param_Slot);
	P_GET_PROPERTY_REF(FDelegateProperty,Z_Param_Out_OnSuccess);
	P_GET_PROPERTY_REF(FDelegateProperty,Z_Param_Out_OnError);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AddModule(Z_Param_ShipInstanceId,Z_Param_ModuleTypeId,Z_Param_Mass,Z_Param_Slot,FOnModuleAdded(Z_Param_Out_OnSuccess),FOnApiError(Z_Param_Out_OnError));
	P_NATIVE_END;
}
// ********** End Class UEchoesShipStatsSubsystem Function AddModule *******************************

// ********** Begin Class UEchoesShipStatsSubsystem Function FetchShipStats ************************
struct Z_Construct_UFunction_UEchoesShipStatsSubsystem_FetchShipStats_Statics
{
	struct EchoesShipStatsSubsystem_eventFetchShipStats_Parms
	{
		FGuid ShipInstanceId;
		FScriptDelegate OnSuccess;
		FScriptDelegate OnError;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ship Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Fetch ship stats from backend\n     * GET /api/ship/{id}/stats\n     * @param ShipInstanceId - Ship instance GUID\n     * @param OnSuccess - Called when stats are successfully fetched\n     * @param OnError - Called on error\n     */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesShipStatsSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fetch ship stats from backend\nGET /api/ship/{id}/stats\n@param ShipInstanceId - Ship instance GUID\n@param OnSuccess - Called when stats are successfully fetched\n@param OnError - Called on error" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnSuccess_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnError_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ShipInstanceId;
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnSuccess;
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnError;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesShipStatsSubsystem_FetchShipStats_Statics::NewProp_ShipInstanceId = { "ShipInstanceId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesShipStatsSubsystem_eventFetchShipStats_Parms, ShipInstanceId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UEchoesShipStatsSubsystem_FetchShipStats_Statics::NewProp_OnSuccess = { "OnSuccess", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesShipStatsSubsystem_eventFetchShipStats_Parms, OnSuccess), Z_Construct_UDelegateFunction_Echoes_OnShipStatsFetched__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnSuccess_MetaData), NewProp_OnSuccess_MetaData) }; // 2989218571
const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UEchoesShipStatsSubsystem_FetchShipStats_Statics::NewProp_OnError = { "OnError", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesShipStatsSubsystem_eventFetchShipStats_Parms, OnError), Z_Construct_UDelegateFunction_Echoes_OnApiError__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnError_MetaData), NewProp_OnError_MetaData) }; // 790282548
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesShipStatsSubsystem_FetchShipStats_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesShipStatsSubsystem_FetchShipStats_Statics::NewProp_ShipInstanceId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesShipStatsSubsystem_FetchShipStats_Statics::NewProp_OnSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesShipStatsSubsystem_FetchShipStats_Statics::NewProp_OnError,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesShipStatsSubsystem_FetchShipStats_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesShipStatsSubsystem_FetchShipStats_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesShipStatsSubsystem, nullptr, "FetchShipStats", Z_Construct_UFunction_UEchoesShipStatsSubsystem_FetchShipStats_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesShipStatsSubsystem_FetchShipStats_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesShipStatsSubsystem_FetchShipStats_Statics::EchoesShipStatsSubsystem_eventFetchShipStats_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesShipStatsSubsystem_FetchShipStats_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesShipStatsSubsystem_FetchShipStats_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesShipStatsSubsystem_FetchShipStats_Statics::EchoesShipStatsSubsystem_eventFetchShipStats_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesShipStatsSubsystem_FetchShipStats()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesShipStatsSubsystem_FetchShipStats_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesShipStatsSubsystem::execFetchShipStats)
{
	P_GET_STRUCT(FGuid,Z_Param_ShipInstanceId);
	P_GET_PROPERTY_REF(FDelegateProperty,Z_Param_Out_OnSuccess);
	P_GET_PROPERTY_REF(FDelegateProperty,Z_Param_Out_OnError);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->FetchShipStats(Z_Param_ShipInstanceId,FOnShipStatsFetched(Z_Param_Out_OnSuccess),FOnApiError(Z_Param_Out_OnError));
	P_NATIVE_END;
}
// ********** End Class UEchoesShipStatsSubsystem Function FetchShipStats **************************

// ********** Begin Class UEchoesShipStatsSubsystem ************************************************
void UEchoesShipStatsSubsystem::StaticRegisterNativesUEchoesShipStatsSubsystem()
{
	UClass* Class = UEchoesShipStatsSubsystem::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "AddModule", &UEchoesShipStatsSubsystem::execAddModule },
		{ "FetchShipStats", &UEchoesShipStatsSubsystem::execFetchShipStats },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UEchoesShipStatsSubsystem;
UClass* UEchoesShipStatsSubsystem::GetPrivateStaticClass()
{
	using TClass = UEchoesShipStatsSubsystem;
	if (!Z_Registration_Info_UClass_UEchoesShipStatsSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesShipStatsSubsystem"),
			Z_Registration_Info_UClass_UEchoesShipStatsSubsystem.InnerSingleton,
			StaticRegisterNativesUEchoesShipStatsSubsystem,
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
	return Z_Registration_Info_UClass_UEchoesShipStatsSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UEchoesShipStatsSubsystem_NoRegister()
{
	return UEchoesShipStatsSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UEchoesShipStatsSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Subsystem for communicating with Ship Controller API\n * \"\xd0\x97\xd0\xb5\xd1\x80\xd0\xba\xd0\xb0\xd0\xbb\xd1\x8c\xd0\xbd\xd0\xbe\xd1\x81\xd1\x82\xd1\x8c\" - Mirrors backend ShipController\n * \n * Handles fetching ship stats from ASP.NET Core backend\n */" },
#endif
		{ "IncludePath", "Core/Common/Networking/EchoesShipStatsSubsystem.h" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesShipStatsSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Subsystem for communicating with Ship Controller API\n\"\xd0\x97\xd0\xb5\xd1\x80\xd0\xba\xd0\xb0\xd0\xbb\xd1\x8c\xd0\xbd\xd0\xbe\xd1\x81\xd1\x82\xd1\x8c\" - Mirrors backend ShipController\n\nHandles fetching ship stats from ASP.NET Core backend" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ApiBaseUrl_MetaData[] = {
		{ "Category", "API" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Backend API URL */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesShipStatsSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Backend API URL" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ServerSecret_MetaData[] = {
		{ "Category", "API" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Server secret for authentication */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesShipStatsSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Server secret for authentication" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ApiBaseUrl;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ServerSecret;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UEchoesShipStatsSubsystem_AddModule, "AddModule" }, // 2813125537
		{ &Z_Construct_UFunction_UEchoesShipStatsSubsystem_FetchShipStats, "FetchShipStats" }, // 3577768632
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEchoesShipStatsSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UEchoesShipStatsSubsystem_Statics::NewProp_ApiBaseUrl = { "ApiBaseUrl", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesShipStatsSubsystem, ApiBaseUrl), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ApiBaseUrl_MetaData), NewProp_ApiBaseUrl_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UEchoesShipStatsSubsystem_Statics::NewProp_ServerSecret = { "ServerSecret", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesShipStatsSubsystem, ServerSecret), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ServerSecret_MetaData), NewProp_ServerSecret_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEchoesShipStatsSubsystem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesShipStatsSubsystem_Statics::NewProp_ApiBaseUrl,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesShipStatsSubsystem_Statics::NewProp_ServerSecret,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesShipStatsSubsystem_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UEchoesShipStatsSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesShipStatsSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEchoesShipStatsSubsystem_Statics::ClassParams = {
	&UEchoesShipStatsSubsystem::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UEchoesShipStatsSubsystem_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesShipStatsSubsystem_Statics::PropPointers),
	0,
	0x001000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesShipStatsSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UEchoesShipStatsSubsystem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEchoesShipStatsSubsystem()
{
	if (!Z_Registration_Info_UClass_UEchoesShipStatsSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEchoesShipStatsSubsystem.OuterSingleton, Z_Construct_UClass_UEchoesShipStatsSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEchoesShipStatsSubsystem.OuterSingleton;
}
UEchoesShipStatsSubsystem::UEchoesShipStatsSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UEchoesShipStatsSubsystem);
UEchoesShipStatsSubsystem::~UEchoesShipStatsSubsystem() {}
// ********** End Class UEchoesShipStatsSubsystem **************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesShipStatsSubsystem_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEchoesShipStatsSubsystem, UEchoesShipStatsSubsystem::StaticClass, TEXT("UEchoesShipStatsSubsystem"), &Z_Registration_Info_UClass_UEchoesShipStatsSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEchoesShipStatsSubsystem), 2883835510U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesShipStatsSubsystem_h__Script_Echoes_2453616879(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesShipStatsSubsystem_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesShipStatsSubsystem_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
