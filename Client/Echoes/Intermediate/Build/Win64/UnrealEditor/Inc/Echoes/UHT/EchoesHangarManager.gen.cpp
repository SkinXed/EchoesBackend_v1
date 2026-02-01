// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Core/Server/EchoesHangarManager.h"
#include "Core/Common/Networking/EchoesInventorySubsystem.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesHangarManager() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ECHOES_API UClass* Z_Construct_UClass_AEchoesHangarManager();
ECHOES_API UClass* Z_Construct_UClass_AEchoesHangarManager_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UEchoesInventorySubsystem_NoRegister();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FEchoesShipFitting();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AEchoesHangarManager Function ClearShipPreview ***************************
struct Z_Construct_UFunction_AEchoesHangarManager_ClearShipPreview_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Hangar" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Clear current ship preview */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesHangarManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Clear current ship preview" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesHangarManager_ClearShipPreview_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesHangarManager, nullptr, "ClearShipPreview", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesHangarManager_ClearShipPreview_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesHangarManager_ClearShipPreview_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AEchoesHangarManager_ClearShipPreview()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesHangarManager_ClearShipPreview_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesHangarManager::execClearShipPreview)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClearShipPreview();
	P_NATIVE_END;
}
// ********** End Class AEchoesHangarManager Function ClearShipPreview *****************************

// ********** Begin Class AEchoesHangarManager Function InitializeHangar ***************************
struct Z_Construct_UFunction_AEchoesHangarManager_InitializeHangar_Statics
{
	struct EchoesHangarManager_eventInitializeHangar_Parms
	{
		FString CharacterId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Hangar" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Initialize hangar for specific character */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesHangarManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Initialize hangar for specific character" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_CharacterId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AEchoesHangarManager_InitializeHangar_Statics::NewProp_CharacterId = { "CharacterId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesHangarManager_eventInitializeHangar_Parms, CharacterId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterId_MetaData), NewProp_CharacterId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesHangarManager_InitializeHangar_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesHangarManager_InitializeHangar_Statics::NewProp_CharacterId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesHangarManager_InitializeHangar_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesHangarManager_InitializeHangar_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesHangarManager, nullptr, "InitializeHangar", Z_Construct_UFunction_AEchoesHangarManager_InitializeHangar_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesHangarManager_InitializeHangar_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesHangarManager_InitializeHangar_Statics::EchoesHangarManager_eventInitializeHangar_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesHangarManager_InitializeHangar_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesHangarManager_InitializeHangar_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesHangarManager_InitializeHangar_Statics::EchoesHangarManager_eventInitializeHangar_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesHangarManager_InitializeHangar()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesHangarManager_InitializeHangar_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesHangarManager::execInitializeHangar)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_CharacterId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializeHangar(Z_Param_CharacterId);
	P_NATIVE_END;
}
// ********** End Class AEchoesHangarManager Function InitializeHangar *****************************

// ********** Begin Class AEchoesHangarManager Function OnFittingChanged ***************************
struct Z_Construct_UFunction_AEchoesHangarManager_OnFittingChanged_Statics
{
	struct EchoesHangarManager_eventOnFittingChanged_Parms
	{
		FEchoesShipFitting NewFitting;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Called when fitting changes (from inventory subsystem) */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesHangarManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when fitting changes (from inventory subsystem)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NewFitting_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_NewFitting;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEchoesHangarManager_OnFittingChanged_Statics::NewProp_NewFitting = { "NewFitting", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesHangarManager_eventOnFittingChanged_Parms, NewFitting), Z_Construct_UScriptStruct_FEchoesShipFitting, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NewFitting_MetaData), NewProp_NewFitting_MetaData) }; // 2094547099
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesHangarManager_OnFittingChanged_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesHangarManager_OnFittingChanged_Statics::NewProp_NewFitting,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesHangarManager_OnFittingChanged_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesHangarManager_OnFittingChanged_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesHangarManager, nullptr, "OnFittingChanged", Z_Construct_UFunction_AEchoesHangarManager_OnFittingChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesHangarManager_OnFittingChanged_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesHangarManager_OnFittingChanged_Statics::EchoesHangarManager_eventOnFittingChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00480401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesHangarManager_OnFittingChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesHangarManager_OnFittingChanged_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesHangarManager_OnFittingChanged_Statics::EchoesHangarManager_eventOnFittingChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesHangarManager_OnFittingChanged()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesHangarManager_OnFittingChanged_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesHangarManager::execOnFittingChanged)
{
	P_GET_STRUCT_REF(FEchoesShipFitting,Z_Param_Out_NewFitting);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnFittingChanged(Z_Param_Out_NewFitting);
	P_NATIVE_END;
}
// ********** End Class AEchoesHangarManager Function OnFittingChanged *****************************

// ********** Begin Class AEchoesHangarManager Function OnShipFittingFailed ************************
struct Z_Construct_UFunction_AEchoesHangarManager_OnShipFittingFailed_Statics
{
	struct EchoesHangarManager_eventOnShipFittingFailed_Parms
	{
		FString Error;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Called when ship fitting fetch fails */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesHangarManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when ship fitting fetch fails" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Error_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_Error;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AEchoesHangarManager_OnShipFittingFailed_Statics::NewProp_Error = { "Error", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesHangarManager_eventOnShipFittingFailed_Parms, Error), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Error_MetaData), NewProp_Error_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesHangarManager_OnShipFittingFailed_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesHangarManager_OnShipFittingFailed_Statics::NewProp_Error,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesHangarManager_OnShipFittingFailed_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesHangarManager_OnShipFittingFailed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesHangarManager, nullptr, "OnShipFittingFailed", Z_Construct_UFunction_AEchoesHangarManager_OnShipFittingFailed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesHangarManager_OnShipFittingFailed_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesHangarManager_OnShipFittingFailed_Statics::EchoesHangarManager_eventOnShipFittingFailed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesHangarManager_OnShipFittingFailed_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesHangarManager_OnShipFittingFailed_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesHangarManager_OnShipFittingFailed_Statics::EchoesHangarManager_eventOnShipFittingFailed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesHangarManager_OnShipFittingFailed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesHangarManager_OnShipFittingFailed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesHangarManager::execOnShipFittingFailed)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Error);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnShipFittingFailed(Z_Param_Error);
	P_NATIVE_END;
}
// ********** End Class AEchoesHangarManager Function OnShipFittingFailed **************************

// ********** Begin Class AEchoesHangarManager Function OnShipFittingReceived **********************
struct Z_Construct_UFunction_AEchoesHangarManager_OnShipFittingReceived_Statics
{
	struct EchoesHangarManager_eventOnShipFittingReceived_Parms
	{
		FEchoesShipFitting Fitting;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Called when ship fitting is successfully fetched */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesHangarManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when ship fitting is successfully fetched" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Fitting_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Fitting;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEchoesHangarManager_OnShipFittingReceived_Statics::NewProp_Fitting = { "Fitting", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesHangarManager_eventOnShipFittingReceived_Parms, Fitting), Z_Construct_UScriptStruct_FEchoesShipFitting, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Fitting_MetaData), NewProp_Fitting_MetaData) }; // 2094547099
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesHangarManager_OnShipFittingReceived_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesHangarManager_OnShipFittingReceived_Statics::NewProp_Fitting,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesHangarManager_OnShipFittingReceived_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesHangarManager_OnShipFittingReceived_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesHangarManager, nullptr, "OnShipFittingReceived", Z_Construct_UFunction_AEchoesHangarManager_OnShipFittingReceived_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesHangarManager_OnShipFittingReceived_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesHangarManager_OnShipFittingReceived_Statics::EchoesHangarManager_eventOnShipFittingReceived_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00480401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesHangarManager_OnShipFittingReceived_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesHangarManager_OnShipFittingReceived_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesHangarManager_OnShipFittingReceived_Statics::EchoesHangarManager_eventOnShipFittingReceived_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesHangarManager_OnShipFittingReceived()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesHangarManager_OnShipFittingReceived_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesHangarManager::execOnShipFittingReceived)
{
	P_GET_STRUCT_REF(FEchoesShipFitting,Z_Param_Out_Fitting);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnShipFittingReceived(Z_Param_Out_Fitting);
	P_NATIVE_END;
}
// ********** End Class AEchoesHangarManager Function OnShipFittingReceived ************************

// ********** Begin Class AEchoesHangarManager Function SpawnShipPreview ***************************
struct Z_Construct_UFunction_AEchoesHangarManager_SpawnShipPreview_Statics
{
	struct EchoesHangarManager_eventSpawnShipPreview_Parms
	{
		FGuid ShipId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Hangar" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Spawn ship preview mesh at target point */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesHangarManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Spawn ship preview mesh at target point" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShipId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ShipId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEchoesHangarManager_SpawnShipPreview_Statics::NewProp_ShipId = { "ShipId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesHangarManager_eventSpawnShipPreview_Parms, ShipId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShipId_MetaData), NewProp_ShipId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesHangarManager_SpawnShipPreview_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesHangarManager_SpawnShipPreview_Statics::NewProp_ShipId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesHangarManager_SpawnShipPreview_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesHangarManager_SpawnShipPreview_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesHangarManager, nullptr, "SpawnShipPreview", Z_Construct_UFunction_AEchoesHangarManager_SpawnShipPreview_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesHangarManager_SpawnShipPreview_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesHangarManager_SpawnShipPreview_Statics::EchoesHangarManager_eventSpawnShipPreview_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesHangarManager_SpawnShipPreview_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesHangarManager_SpawnShipPreview_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesHangarManager_SpawnShipPreview_Statics::EchoesHangarManager_eventSpawnShipPreview_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesHangarManager_SpawnShipPreview()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesHangarManager_SpawnShipPreview_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesHangarManager::execSpawnShipPreview)
{
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_ShipId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SpawnShipPreview(Z_Param_Out_ShipId);
	P_NATIVE_END;
}
// ********** End Class AEchoesHangarManager Function SpawnShipPreview *****************************

// ********** Begin Class AEchoesHangarManager Function UpdateShipMesh *****************************
struct Z_Construct_UFunction_AEchoesHangarManager_UpdateShipMesh_Statics
{
	struct EchoesHangarManager_eventUpdateShipMesh_Parms
	{
		FEchoesShipFitting NewFitting;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Hangar" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Update ship mesh when fitting changes */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesHangarManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Update ship mesh when fitting changes" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NewFitting_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_NewFitting;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEchoesHangarManager_UpdateShipMesh_Statics::NewProp_NewFitting = { "NewFitting", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesHangarManager_eventUpdateShipMesh_Parms, NewFitting), Z_Construct_UScriptStruct_FEchoesShipFitting, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NewFitting_MetaData), NewProp_NewFitting_MetaData) }; // 2094547099
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesHangarManager_UpdateShipMesh_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesHangarManager_UpdateShipMesh_Statics::NewProp_NewFitting,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesHangarManager_UpdateShipMesh_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesHangarManager_UpdateShipMesh_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesHangarManager, nullptr, "UpdateShipMesh", Z_Construct_UFunction_AEchoesHangarManager_UpdateShipMesh_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesHangarManager_UpdateShipMesh_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesHangarManager_UpdateShipMesh_Statics::EchoesHangarManager_eventUpdateShipMesh_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesHangarManager_UpdateShipMesh_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesHangarManager_UpdateShipMesh_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesHangarManager_UpdateShipMesh_Statics::EchoesHangarManager_eventUpdateShipMesh_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesHangarManager_UpdateShipMesh()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesHangarManager_UpdateShipMesh_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesHangarManager::execUpdateShipMesh)
{
	P_GET_STRUCT_REF(FEchoesShipFitting,Z_Param_Out_NewFitting);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UpdateShipMesh(Z_Param_Out_NewFitting);
	P_NATIVE_END;
}
// ********** End Class AEchoesHangarManager Function UpdateShipMesh *******************************

// ********** Begin Class AEchoesHangarManager *****************************************************
void AEchoesHangarManager::StaticRegisterNativesAEchoesHangarManager()
{
	UClass* Class = AEchoesHangarManager::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ClearShipPreview", &AEchoesHangarManager::execClearShipPreview },
		{ "InitializeHangar", &AEchoesHangarManager::execInitializeHangar },
		{ "OnFittingChanged", &AEchoesHangarManager::execOnFittingChanged },
		{ "OnShipFittingFailed", &AEchoesHangarManager::execOnShipFittingFailed },
		{ "OnShipFittingReceived", &AEchoesHangarManager::execOnShipFittingReceived },
		{ "SpawnShipPreview", &AEchoesHangarManager::execSpawnShipPreview },
		{ "UpdateShipMesh", &AEchoesHangarManager::execUpdateShipMesh },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_AEchoesHangarManager;
UClass* AEchoesHangarManager::GetPrivateStaticClass()
{
	using TClass = AEchoesHangarManager;
	if (!Z_Registration_Info_UClass_AEchoesHangarManager.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesHangarManager"),
			Z_Registration_Info_UClass_AEchoesHangarManager.InnerSingleton,
			StaticRegisterNativesAEchoesHangarManager,
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
	return Z_Registration_Info_UClass_AEchoesHangarManager.InnerSingleton;
}
UClass* Z_Construct_UClass_AEchoesHangarManager_NoRegister()
{
	return AEchoesHangarManager::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AEchoesHangarManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * AEchoesHangarManager\n * \n * Manages the hangar scene, spawning and updating the ship preview.\n * Subscribes to inventory subsystem to react to fitting changes.\n */" },
#endif
		{ "IncludePath", "Core/Server/EchoesHangarManager.h" },
		{ "ModuleRelativePath", "Core/Server/EchoesHangarManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "AEchoesHangarManager\n\nManages the hangar scene, spawning and updating the ship preview.\nSubscribes to inventory subsystem to react to fitting changes." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShipSpawnPoint_MetaData[] = {
		{ "Category", "Hangar" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Target point where ship preview spawns */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Server/EchoesHangarManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Target point where ship preview spawns" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultShipMesh_MetaData[] = {
		{ "Category", "Hangar" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Default ship mesh for preview (can be overridden) */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesHangarManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Default ship mesh for preview (can be overridden)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewShipActor_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current spawned ship preview actor */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesHangarManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current spawned ship preview actor" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentCharacterId_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current character ID being managed */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesHangarManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current character ID being managed" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentShipId_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current ship ID being displayed */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesHangarManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current ship ID being displayed" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InventorySubsystem_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Cached inventory subsystem reference */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesHangarManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cached inventory subsystem reference" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ShipSpawnPoint;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DefaultShipMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PreviewShipActor;
	static const UECodeGen_Private::FStrPropertyParams NewProp_CurrentCharacterId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentShipId;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InventorySubsystem;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AEchoesHangarManager_ClearShipPreview, "ClearShipPreview" }, // 2927305687
		{ &Z_Construct_UFunction_AEchoesHangarManager_InitializeHangar, "InitializeHangar" }, // 676511314
		{ &Z_Construct_UFunction_AEchoesHangarManager_OnFittingChanged, "OnFittingChanged" }, // 2204439808
		{ &Z_Construct_UFunction_AEchoesHangarManager_OnShipFittingFailed, "OnShipFittingFailed" }, // 407317452
		{ &Z_Construct_UFunction_AEchoesHangarManager_OnShipFittingReceived, "OnShipFittingReceived" }, // 1449995402
		{ &Z_Construct_UFunction_AEchoesHangarManager_SpawnShipPreview, "SpawnShipPreview" }, // 2195280110
		{ &Z_Construct_UFunction_AEchoesHangarManager_UpdateShipMesh, "UpdateShipMesh" }, // 2741030222
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEchoesHangarManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEchoesHangarManager_Statics::NewProp_ShipSpawnPoint = { "ShipSpawnPoint", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesHangarManager, ShipSpawnPoint), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShipSpawnPoint_MetaData), NewProp_ShipSpawnPoint_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEchoesHangarManager_Statics::NewProp_DefaultShipMesh = { "DefaultShipMesh", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesHangarManager, DefaultShipMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultShipMesh_MetaData), NewProp_DefaultShipMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEchoesHangarManager_Statics::NewProp_PreviewShipActor = { "PreviewShipActor", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesHangarManager, PreviewShipActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewShipActor_MetaData), NewProp_PreviewShipActor_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AEchoesHangarManager_Statics::NewProp_CurrentCharacterId = { "CurrentCharacterId", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesHangarManager, CurrentCharacterId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentCharacterId_MetaData), NewProp_CurrentCharacterId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AEchoesHangarManager_Statics::NewProp_CurrentShipId = { "CurrentShipId", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesHangarManager, CurrentShipId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentShipId_MetaData), NewProp_CurrentShipId_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEchoesHangarManager_Statics::NewProp_InventorySubsystem = { "InventorySubsystem", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesHangarManager, InventorySubsystem), Z_Construct_UClass_UEchoesInventorySubsystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InventorySubsystem_MetaData), NewProp_InventorySubsystem_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEchoesHangarManager_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesHangarManager_Statics::NewProp_ShipSpawnPoint,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesHangarManager_Statics::NewProp_DefaultShipMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesHangarManager_Statics::NewProp_PreviewShipActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesHangarManager_Statics::NewProp_CurrentCharacterId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesHangarManager_Statics::NewProp_CurrentShipId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesHangarManager_Statics::NewProp_InventorySubsystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEchoesHangarManager_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AEchoesHangarManager_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEchoesHangarManager_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AEchoesHangarManager_Statics::ClassParams = {
	&AEchoesHangarManager::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AEchoesHangarManager_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AEchoesHangarManager_Statics::PropPointers),
	0,
	0x009001A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEchoesHangarManager_Statics::Class_MetaDataParams), Z_Construct_UClass_AEchoesHangarManager_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AEchoesHangarManager()
{
	if (!Z_Registration_Info_UClass_AEchoesHangarManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEchoesHangarManager.OuterSingleton, Z_Construct_UClass_AEchoesHangarManager_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AEchoesHangarManager.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AEchoesHangarManager);
AEchoesHangarManager::~AEchoesHangarManager() {}
// ********** End Class AEchoesHangarManager *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_EchoesHangarManager_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AEchoesHangarManager, AEchoesHangarManager::StaticClass, TEXT("AEchoesHangarManager"), &Z_Registration_Info_UClass_AEchoesHangarManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEchoesHangarManager), 2809628049U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_EchoesHangarManager_h__Script_Echoes_4187046004(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_EchoesHangarManager_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_EchoesHangarManager_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
