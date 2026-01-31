// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Core/Common/StationActor.h"
#include "Core/Common/EchoesWorldVisualTypes.h"
#include "Engine/HitResult.h"
#include "UObject/CoreNet.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeStationActor() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ECHOES_API UClass* Z_Construct_UClass_AStationActor();
ECHOES_API UClass* Z_Construct_UClass_AStationActor_NoRegister();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FStationVisualRow();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APlayerController_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
NIAGARA_API UClass* Z_Construct_UClass_UNiagaraComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AStationActor Function ClientRPC_OpenStationMenu *************************
struct StationActor_eventClientRPC_OpenStationMenu_Parms
{
	FString InStationName;
	FString InStationType;
	FGuid InHangarStorageId;
};
static FName NAME_AStationActor_ClientRPC_OpenStationMenu = FName(TEXT("ClientRPC_OpenStationMenu"));
void AStationActor::ClientRPC_OpenStationMenu(const FString& InStationName, const FString& InStationType, FGuid const& InHangarStorageId)
{
	StationActor_eventClientRPC_OpenStationMenu_Parms Parms;
	Parms.InStationName=InStationName;
	Parms.InStationType=InStationType;
	Parms.InHangarStorageId=InHangarStorageId;
	UFunction* Func = FindFunctionChecked(NAME_AStationActor_ClientRPC_OpenStationMenu);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AStationActor_ClientRPC_OpenStationMenu_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Client RPC to open station menu on player's screen\n\x09 * Called after successful docking\n\x09 * \n\x09 * @param InStationName - Name of the station\n\x09 * @param InStationType - Type of the station\n\x09 * @param InHangarStorageId - Storage ID of player's personal hangar\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/StationActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Client RPC to open station menu on player's screen\nCalled after successful docking\n\n@param InStationName - Name of the station\n@param InStationType - Type of the station\n@param InHangarStorageId - Storage ID of player's personal hangar" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InStationName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InStationType_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InHangarStorageId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_InStationName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_InStationType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InHangarStorageId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AStationActor_ClientRPC_OpenStationMenu_Statics::NewProp_InStationName = { "InStationName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StationActor_eventClientRPC_OpenStationMenu_Parms, InStationName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InStationName_MetaData), NewProp_InStationName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AStationActor_ClientRPC_OpenStationMenu_Statics::NewProp_InStationType = { "InStationType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StationActor_eventClientRPC_OpenStationMenu_Parms, InStationType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InStationType_MetaData), NewProp_InStationType_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AStationActor_ClientRPC_OpenStationMenu_Statics::NewProp_InHangarStorageId = { "InHangarStorageId", nullptr, (EPropertyFlags)0x0010000008000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StationActor_eventClientRPC_OpenStationMenu_Parms, InHangarStorageId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InHangarStorageId_MetaData), NewProp_InHangarStorageId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AStationActor_ClientRPC_OpenStationMenu_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStationActor_ClientRPC_OpenStationMenu_Statics::NewProp_InStationName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStationActor_ClientRPC_OpenStationMenu_Statics::NewProp_InStationType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStationActor_ClientRPC_OpenStationMenu_Statics::NewProp_InHangarStorageId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AStationActor_ClientRPC_OpenStationMenu_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AStationActor_ClientRPC_OpenStationMenu_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AStationActor, nullptr, "ClientRPC_OpenStationMenu", Z_Construct_UFunction_AStationActor_ClientRPC_OpenStationMenu_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AStationActor_ClientRPC_OpenStationMenu_Statics::PropPointers), sizeof(StationActor_eventClientRPC_OpenStationMenu_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01820CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AStationActor_ClientRPC_OpenStationMenu_Statics::Function_MetaDataParams), Z_Construct_UFunction_AStationActor_ClientRPC_OpenStationMenu_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(StationActor_eventClientRPC_OpenStationMenu_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AStationActor_ClientRPC_OpenStationMenu()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AStationActor_ClientRPC_OpenStationMenu_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AStationActor::execClientRPC_OpenStationMenu)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InStationName);
	P_GET_PROPERTY(FStrProperty,Z_Param_InStationType);
	P_GET_STRUCT(FGuid,Z_Param_InHangarStorageId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientRPC_OpenStationMenu_Implementation(Z_Param_InStationName,Z_Param_InStationType,Z_Param_InHangarStorageId);
	P_NATIVE_END;
}
// ********** End Class AStationActor Function ClientRPC_OpenStationMenu ***************************

// ********** Begin Class AStationActor Function GetStationId **************************************
struct Z_Construct_UFunction_AStationActor_GetStationId_Statics
{
	struct StationActor_eventGetStationId_Parms
	{
		FGuid ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Station" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ==================== Getters ====================\n" },
#endif
		{ "ModuleRelativePath", "Core/Common/StationActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "==================== Getters ====================" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AStationActor_GetStationId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StationActor_eventGetStationId_Parms, ReturnValue), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AStationActor_GetStationId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStationActor_GetStationId_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AStationActor_GetStationId_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AStationActor_GetStationId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AStationActor, nullptr, "GetStationId", Z_Construct_UFunction_AStationActor_GetStationId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AStationActor_GetStationId_Statics::PropPointers), sizeof(Z_Construct_UFunction_AStationActor_GetStationId_Statics::StationActor_eventGetStationId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AStationActor_GetStationId_Statics::Function_MetaDataParams), Z_Construct_UFunction_AStationActor_GetStationId_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AStationActor_GetStationId_Statics::StationActor_eventGetStationId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AStationActor_GetStationId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AStationActor_GetStationId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AStationActor::execGetStationId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGuid*)Z_Param__Result=P_THIS->GetStationId();
	P_NATIVE_END;
}
// ********** End Class AStationActor Function GetStationId ****************************************

// ********** Begin Class AStationActor Function GetStationName ************************************
struct Z_Construct_UFunction_AStationActor_GetStationName_Statics
{
	struct StationActor_eventGetStationName_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Station" },
		{ "ModuleRelativePath", "Core/Common/StationActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AStationActor_GetStationName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StationActor_eventGetStationName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AStationActor_GetStationName_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStationActor_GetStationName_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AStationActor_GetStationName_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AStationActor_GetStationName_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AStationActor, nullptr, "GetStationName", Z_Construct_UFunction_AStationActor_GetStationName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AStationActor_GetStationName_Statics::PropPointers), sizeof(Z_Construct_UFunction_AStationActor_GetStationName_Statics::StationActor_eventGetStationName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AStationActor_GetStationName_Statics::Function_MetaDataParams), Z_Construct_UFunction_AStationActor_GetStationName_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AStationActor_GetStationName_Statics::StationActor_eventGetStationName_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AStationActor_GetStationName()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AStationActor_GetStationName_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AStationActor::execGetStationName)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GetStationName();
	P_NATIVE_END;
}
// ********** End Class AStationActor Function GetStationName **************************************

// ********** Begin Class AStationActor Function GetStationType ************************************
struct Z_Construct_UFunction_AStationActor_GetStationType_Statics
{
	struct StationActor_eventGetStationType_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Station" },
		{ "ModuleRelativePath", "Core/Common/StationActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AStationActor_GetStationType_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StationActor_eventGetStationType_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AStationActor_GetStationType_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStationActor_GetStationType_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AStationActor_GetStationType_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AStationActor_GetStationType_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AStationActor, nullptr, "GetStationType", Z_Construct_UFunction_AStationActor_GetStationType_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AStationActor_GetStationType_Statics::PropPointers), sizeof(Z_Construct_UFunction_AStationActor_GetStationType_Statics::StationActor_eventGetStationType_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AStationActor_GetStationType_Statics::Function_MetaDataParams), Z_Construct_UFunction_AStationActor_GetStationType_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AStationActor_GetStationType_Statics::StationActor_eventGetStationType_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AStationActor_GetStationType()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AStationActor_GetStationType_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AStationActor::execGetStationType)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GetStationType();
	P_NATIVE_END;
}
// ********** End Class AStationActor Function GetStationType **************************************

// ********** Begin Class AStationActor Function HandleHangarFailure *******************************
struct Z_Construct_UFunction_AStationActor_HandleHangarFailure_Statics
{
	struct StationActor_eventHandleHangarFailure_Parms
	{
		FString Error;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Called when ship fitting fetch fails */" },
#endif
		{ "ModuleRelativePath", "Core/Common/StationActor.h" },
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
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AStationActor_HandleHangarFailure_Statics::NewProp_Error = { "Error", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StationActor_eventHandleHangarFailure_Parms, Error), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Error_MetaData), NewProp_Error_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AStationActor_HandleHangarFailure_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStationActor_HandleHangarFailure_Statics::NewProp_Error,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AStationActor_HandleHangarFailure_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AStationActor_HandleHangarFailure_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AStationActor, nullptr, "HandleHangarFailure", Z_Construct_UFunction_AStationActor_HandleHangarFailure_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AStationActor_HandleHangarFailure_Statics::PropPointers), sizeof(Z_Construct_UFunction_AStationActor_HandleHangarFailure_Statics::StationActor_eventHandleHangarFailure_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AStationActor_HandleHangarFailure_Statics::Function_MetaDataParams), Z_Construct_UFunction_AStationActor_HandleHangarFailure_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AStationActor_HandleHangarFailure_Statics::StationActor_eventHandleHangarFailure_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AStationActor_HandleHangarFailure()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AStationActor_HandleHangarFailure_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AStationActor::execHandleHangarFailure)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Error);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleHangarFailure(Z_Param_Error);
	P_NATIVE_END;
}
// ********** End Class AStationActor Function HandleHangarFailure *********************************

// ********** Begin Class AStationActor Function HandleHangarReceived ******************************
struct Z_Construct_UFunction_AStationActor_HandleHangarReceived_Statics
{
	struct StationActor_eventHandleHangarReceived_Parms
	{
		FGuid HangarStorageId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Called when ship fitting is successfully fetched */" },
#endif
		{ "ModuleRelativePath", "Core/Common/StationActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when ship fitting is successfully fetched" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HangarStorageId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_HangarStorageId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AStationActor_HandleHangarReceived_Statics::NewProp_HangarStorageId = { "HangarStorageId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StationActor_eventHandleHangarReceived_Parms, HangarStorageId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HangarStorageId_MetaData), NewProp_HangarStorageId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AStationActor_HandleHangarReceived_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStationActor_HandleHangarReceived_Statics::NewProp_HangarStorageId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AStationActor_HandleHangarReceived_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AStationActor_HandleHangarReceived_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AStationActor, nullptr, "HandleHangarReceived", Z_Construct_UFunction_AStationActor_HandleHangarReceived_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AStationActor_HandleHangarReceived_Statics::PropPointers), sizeof(Z_Construct_UFunction_AStationActor_HandleHangarReceived_Statics::StationActor_eventHandleHangarReceived_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C80401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AStationActor_HandleHangarReceived_Statics::Function_MetaDataParams), Z_Construct_UFunction_AStationActor_HandleHangarReceived_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AStationActor_HandleHangarReceived_Statics::StationActor_eventHandleHangarReceived_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AStationActor_HandleHangarReceived()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AStationActor_HandleHangarReceived_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AStationActor::execHandleHangarReceived)
{
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_HangarStorageId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleHangarReceived(Z_Param_Out_HangarStorageId);
	P_NATIVE_END;
}
// ********** End Class AStationActor Function HandleHangarReceived ********************************

// ********** Begin Class AStationActor Function HasDockingAccess **********************************
struct Z_Construct_UFunction_AStationActor_HasDockingAccess_Statics
{
	struct StationActor_eventHasDockingAccess_Parms
	{
		APlayerController* PlayerController;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Station" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if player has access rights to dock at this station\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/StationActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if player has access rights to dock at this station" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AStationActor_HasDockingAccess_Statics::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StationActor_eventHasDockingAccess_Parms, PlayerController), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AStationActor_HasDockingAccess_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((StationActor_eventHasDockingAccess_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AStationActor_HasDockingAccess_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(StationActor_eventHasDockingAccess_Parms), &Z_Construct_UFunction_AStationActor_HasDockingAccess_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AStationActor_HasDockingAccess_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStationActor_HasDockingAccess_Statics::NewProp_PlayerController,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStationActor_HasDockingAccess_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AStationActor_HasDockingAccess_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AStationActor_HasDockingAccess_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AStationActor, nullptr, "HasDockingAccess", Z_Construct_UFunction_AStationActor_HasDockingAccess_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AStationActor_HasDockingAccess_Statics::PropPointers), sizeof(Z_Construct_UFunction_AStationActor_HasDockingAccess_Statics::StationActor_eventHasDockingAccess_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AStationActor_HasDockingAccess_Statics::Function_MetaDataParams), Z_Construct_UFunction_AStationActor_HasDockingAccess_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AStationActor_HasDockingAccess_Statics::StationActor_eventHasDockingAccess_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AStationActor_HasDockingAccess()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AStationActor_HasDockingAccess_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AStationActor::execHasDockingAccess)
{
	P_GET_OBJECT(APlayerController,Z_Param_PlayerController);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->HasDockingAccess(Z_Param_PlayerController);
	P_NATIVE_END;
}
// ********** End Class AStationActor Function HasDockingAccess ************************************

// ********** Begin Class AStationActor Function InitializeStation *********************************
struct Z_Construct_UFunction_AStationActor_InitializeStation_Statics
{
	struct StationActor_eventInitializeStation_Parms
	{
		FGuid InStationId;
		FString InName;
		FString InStationType;
		int32 InSeed;
		FStationVisualRow InVisualData;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Station" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ==================== Initialization ====================\n" },
#endif
		{ "ModuleRelativePath", "Core/Common/StationActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "==================== Initialization ====================" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InStationId_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InStationType_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InVisualData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_InStationId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_InName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_InStationType;
	static const UECodeGen_Private::FIntPropertyParams NewProp_InSeed;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InVisualData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AStationActor_InitializeStation_Statics::NewProp_InStationId = { "InStationId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StationActor_eventInitializeStation_Parms, InStationId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InStationId_MetaData), NewProp_InStationId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AStationActor_InitializeStation_Statics::NewProp_InName = { "InName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StationActor_eventInitializeStation_Parms, InName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InName_MetaData), NewProp_InName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AStationActor_InitializeStation_Statics::NewProp_InStationType = { "InStationType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StationActor_eventInitializeStation_Parms, InStationType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InStationType_MetaData), NewProp_InStationType_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AStationActor_InitializeStation_Statics::NewProp_InSeed = { "InSeed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StationActor_eventInitializeStation_Parms, InSeed), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AStationActor_InitializeStation_Statics::NewProp_InVisualData = { "InVisualData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StationActor_eventInitializeStation_Parms, InVisualData), Z_Construct_UScriptStruct_FStationVisualRow, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InVisualData_MetaData), NewProp_InVisualData_MetaData) }; // 1509157565
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AStationActor_InitializeStation_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStationActor_InitializeStation_Statics::NewProp_InStationId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStationActor_InitializeStation_Statics::NewProp_InName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStationActor_InitializeStation_Statics::NewProp_InStationType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStationActor_InitializeStation_Statics::NewProp_InSeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStationActor_InitializeStation_Statics::NewProp_InVisualData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AStationActor_InitializeStation_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AStationActor_InitializeStation_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AStationActor, nullptr, "InitializeStation", Z_Construct_UFunction_AStationActor_InitializeStation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AStationActor_InitializeStation_Statics::PropPointers), sizeof(Z_Construct_UFunction_AStationActor_InitializeStation_Statics::StationActor_eventInitializeStation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AStationActor_InitializeStation_Statics::Function_MetaDataParams), Z_Construct_UFunction_AStationActor_InitializeStation_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AStationActor_InitializeStation_Statics::StationActor_eventInitializeStation_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AStationActor_InitializeStation()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AStationActor_InitializeStation_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AStationActor::execInitializeStation)
{
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_InStationId);
	P_GET_PROPERTY(FStrProperty,Z_Param_InName);
	P_GET_PROPERTY(FStrProperty,Z_Param_InStationType);
	P_GET_PROPERTY(FIntProperty,Z_Param_InSeed);
	P_GET_STRUCT_REF(FStationVisualRow,Z_Param_Out_InVisualData);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializeStation(Z_Param_Out_InStationId,Z_Param_InName,Z_Param_InStationType,Z_Param_InSeed,Z_Param_Out_InVisualData);
	P_NATIVE_END;
}
// ********** End Class AStationActor Function InitializeStation ***********************************

// ********** Begin Class AStationActor Function OnDockingZoneBeginOverlap *************************
struct Z_Construct_UFunction_AStationActor_OnDockingZoneBeginOverlap_Statics
{
	struct StationActor_eventOnDockingZoneBeginOverlap_Parms
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
		{ "Comment", "/**\n\x09 * Called when ship enters docking zone\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/StationActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when ship enters docking zone" },
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
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AStationActor_OnDockingZoneBeginOverlap_Statics::NewProp_OverlappedComponent = { "OverlappedComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StationActor_eventOnDockingZoneBeginOverlap_Parms, OverlappedComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OverlappedComponent_MetaData), NewProp_OverlappedComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AStationActor_OnDockingZoneBeginOverlap_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StationActor_eventOnDockingZoneBeginOverlap_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AStationActor_OnDockingZoneBeginOverlap_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StationActor_eventOnDockingZoneBeginOverlap_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OtherComp_MetaData), NewProp_OtherComp_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AStationActor_OnDockingZoneBeginOverlap_Statics::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StationActor_eventOnDockingZoneBeginOverlap_Parms, OtherBodyIndex), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AStationActor_OnDockingZoneBeginOverlap_Statics::NewProp_bFromSweep_SetBit(void* Obj)
{
	((StationActor_eventOnDockingZoneBeginOverlap_Parms*)Obj)->bFromSweep = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AStationActor_OnDockingZoneBeginOverlap_Statics::NewProp_bFromSweep = { "bFromSweep", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(StationActor_eventOnDockingZoneBeginOverlap_Parms), &Z_Construct_UFunction_AStationActor_OnDockingZoneBeginOverlap_Statics::NewProp_bFromSweep_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AStationActor_OnDockingZoneBeginOverlap_Statics::NewProp_SweepResult = { "SweepResult", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StationActor_eventOnDockingZoneBeginOverlap_Parms, SweepResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SweepResult_MetaData), NewProp_SweepResult_MetaData) }; // 267591329
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AStationActor_OnDockingZoneBeginOverlap_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStationActor_OnDockingZoneBeginOverlap_Statics::NewProp_OverlappedComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStationActor_OnDockingZoneBeginOverlap_Statics::NewProp_OtherActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStationActor_OnDockingZoneBeginOverlap_Statics::NewProp_OtherComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStationActor_OnDockingZoneBeginOverlap_Statics::NewProp_OtherBodyIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStationActor_OnDockingZoneBeginOverlap_Statics::NewProp_bFromSweep,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStationActor_OnDockingZoneBeginOverlap_Statics::NewProp_SweepResult,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AStationActor_OnDockingZoneBeginOverlap_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AStationActor_OnDockingZoneBeginOverlap_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AStationActor, nullptr, "OnDockingZoneBeginOverlap", Z_Construct_UFunction_AStationActor_OnDockingZoneBeginOverlap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AStationActor_OnDockingZoneBeginOverlap_Statics::PropPointers), sizeof(Z_Construct_UFunction_AStationActor_OnDockingZoneBeginOverlap_Statics::StationActor_eventOnDockingZoneBeginOverlap_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AStationActor_OnDockingZoneBeginOverlap_Statics::Function_MetaDataParams), Z_Construct_UFunction_AStationActor_OnDockingZoneBeginOverlap_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AStationActor_OnDockingZoneBeginOverlap_Statics::StationActor_eventOnDockingZoneBeginOverlap_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AStationActor_OnDockingZoneBeginOverlap()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AStationActor_OnDockingZoneBeginOverlap_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AStationActor::execOnDockingZoneBeginOverlap)
{
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent);
	P_GET_OBJECT(AActor,Z_Param_OtherActor);
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp);
	P_GET_PROPERTY(FIntProperty,Z_Param_OtherBodyIndex);
	P_GET_UBOOL(Z_Param_bFromSweep);
	P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnDockingZoneBeginOverlap(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult);
	P_NATIVE_END;
}
// ********** End Class AStationActor Function OnDockingZoneBeginOverlap ***************************

// ********** Begin Class AStationActor Function OnRep_StationData *********************************
struct Z_Construct_UFunction_AStationActor_OnRep_StationData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Common/StationActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AStationActor_OnRep_StationData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AStationActor, nullptr, "OnRep_StationData", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AStationActor_OnRep_StationData_Statics::Function_MetaDataParams), Z_Construct_UFunction_AStationActor_OnRep_StationData_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AStationActor_OnRep_StationData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AStationActor_OnRep_StationData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AStationActor::execOnRep_StationData)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_StationData();
	P_NATIVE_END;
}
// ********** End Class AStationActor Function OnRep_StationData ***********************************

// ********** Begin Class AStationActor Function ServerRPC_RequestDocking **************************
struct StationActor_eventServerRPC_RequestDocking_Parms
{
	APlayerController* PlayerController;
};
static FName NAME_AStationActor_ServerRPC_RequestDocking = FName(TEXT("ServerRPC_RequestDocking"));
void AStationActor::ServerRPC_RequestDocking(APlayerController* PlayerController)
{
	StationActor_eventServerRPC_RequestDocking_Parms Parms;
	Parms.PlayerController=PlayerController;
	UFunction* Func = FindFunctionChecked(NAME_AStationActor_ServerRPC_RequestDocking);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AStationActor_ServerRPC_RequestDocking_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Server RPC to request docking at this station\n\x09 * Validates access rights and initiates docking sequence\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/StationActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Server RPC to request docking at this station\nValidates access rights and initiates docking sequence" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AStationActor_ServerRPC_RequestDocking_Statics::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StationActor_eventServerRPC_RequestDocking_Parms, PlayerController), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AStationActor_ServerRPC_RequestDocking_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStationActor_ServerRPC_RequestDocking_Statics::NewProp_PlayerController,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AStationActor_ServerRPC_RequestDocking_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AStationActor_ServerRPC_RequestDocking_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AStationActor, nullptr, "ServerRPC_RequestDocking", Z_Construct_UFunction_AStationActor_ServerRPC_RequestDocking_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AStationActor_ServerRPC_RequestDocking_Statics::PropPointers), sizeof(StationActor_eventServerRPC_RequestDocking_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AStationActor_ServerRPC_RequestDocking_Statics::Function_MetaDataParams), Z_Construct_UFunction_AStationActor_ServerRPC_RequestDocking_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(StationActor_eventServerRPC_RequestDocking_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AStationActor_ServerRPC_RequestDocking()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AStationActor_ServerRPC_RequestDocking_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AStationActor::execServerRPC_RequestDocking)
{
	P_GET_OBJECT(APlayerController,Z_Param_PlayerController);
	P_FINISH;
	P_NATIVE_BEGIN;
	if (!P_THIS->ServerRPC_RequestDocking_Validate(Z_Param_PlayerController))
	{
		RPC_ValidateFailed(TEXT("ServerRPC_RequestDocking_Validate"));
		return;
	}
	P_THIS->ServerRPC_RequestDocking_Implementation(Z_Param_PlayerController);
	P_NATIVE_END;
}
// ********** End Class AStationActor Function ServerRPC_RequestDocking ****************************

// ********** Begin Class AStationActor Function ServerRPC_RequestUndock ***************************
struct StationActor_eventServerRPC_RequestUndock_Parms
{
	APlayerController* PlayerController;
};
static FName NAME_AStationActor_ServerRPC_RequestUndock = FName(TEXT("ServerRPC_RequestUndock"));
void AStationActor::ServerRPC_RequestUndock(APlayerController* PlayerController)
{
	StationActor_eventServerRPC_RequestUndock_Parms Parms;
	Parms.PlayerController=PlayerController;
	UFunction* Func = FindFunctionChecked(NAME_AStationActor_ServerRPC_RequestUndock);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AStationActor_ServerRPC_RequestUndock_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Server RPC to request undocking from station\n\x09 * Called from client when player clicks Undock button\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/StationActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Server RPC to request undocking from station\nCalled from client when player clicks Undock button" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AStationActor_ServerRPC_RequestUndock_Statics::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StationActor_eventServerRPC_RequestUndock_Parms, PlayerController), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AStationActor_ServerRPC_RequestUndock_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStationActor_ServerRPC_RequestUndock_Statics::NewProp_PlayerController,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AStationActor_ServerRPC_RequestUndock_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AStationActor_ServerRPC_RequestUndock_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AStationActor, nullptr, "ServerRPC_RequestUndock", Z_Construct_UFunction_AStationActor_ServerRPC_RequestUndock_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AStationActor_ServerRPC_RequestUndock_Statics::PropPointers), sizeof(StationActor_eventServerRPC_RequestUndock_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AStationActor_ServerRPC_RequestUndock_Statics::Function_MetaDataParams), Z_Construct_UFunction_AStationActor_ServerRPC_RequestUndock_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(StationActor_eventServerRPC_RequestUndock_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AStationActor_ServerRPC_RequestUndock()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AStationActor_ServerRPC_RequestUndock_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AStationActor::execServerRPC_RequestUndock)
{
	P_GET_OBJECT(APlayerController,Z_Param_PlayerController);
	P_FINISH;
	P_NATIVE_BEGIN;
	if (!P_THIS->ServerRPC_RequestUndock_Validate(Z_Param_PlayerController))
	{
		RPC_ValidateFailed(TEXT("ServerRPC_RequestUndock_Validate"));
		return;
	}
	P_THIS->ServerRPC_RequestUndock_Implementation(Z_Param_PlayerController);
	P_NATIVE_END;
}
// ********** End Class AStationActor Function ServerRPC_RequestUndock *****************************

// ********** Begin Class AStationActor ************************************************************
void AStationActor::StaticRegisterNativesAStationActor()
{
	UClass* Class = AStationActor::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ClientRPC_OpenStationMenu", &AStationActor::execClientRPC_OpenStationMenu },
		{ "GetStationId", &AStationActor::execGetStationId },
		{ "GetStationName", &AStationActor::execGetStationName },
		{ "GetStationType", &AStationActor::execGetStationType },
		{ "HandleHangarFailure", &AStationActor::execHandleHangarFailure },
		{ "HandleHangarReceived", &AStationActor::execHandleHangarReceived },
		{ "HasDockingAccess", &AStationActor::execHasDockingAccess },
		{ "InitializeStation", &AStationActor::execInitializeStation },
		{ "OnDockingZoneBeginOverlap", &AStationActor::execOnDockingZoneBeginOverlap },
		{ "OnRep_StationData", &AStationActor::execOnRep_StationData },
		{ "ServerRPC_RequestDocking", &AStationActor::execServerRPC_RequestDocking },
		{ "ServerRPC_RequestUndock", &AStationActor::execServerRPC_RequestUndock },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_AStationActor;
UClass* AStationActor::GetPrivateStaticClass()
{
	using TClass = AStationActor;
	if (!Z_Registration_Info_UClass_AStationActor.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("StationActor"),
			Z_Registration_Info_UClass_AStationActor.InnerSingleton,
			StaticRegisterNativesAStationActor,
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
	return Z_Registration_Info_UClass_AStationActor.InnerSingleton;
}
UClass* Z_Construct_UClass_AStationActor_NoRegister()
{
	return AStationActor::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AStationActor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * AStationActor\n * \n * Represents a space station in the Echoes universe\n * Supports modular construction and faction customization\n */" },
#endif
		{ "IncludePath", "Core/Common/StationActor.h" },
		{ "ModuleRelativePath", "Core/Common/StationActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "AStationActor\n\nRepresents a space station in the Echoes universe\nSupports modular construction and faction customization" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BaseMeshComponent_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ==================== Components ====================\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/StationActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "==================== Components ====================" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LightsComponent_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/StationActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DockingZone_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Docking zone - detects ships requesting to dock */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/StationActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Docking zone - detects ships requesting to dock" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StationId_MetaData[] = {
		{ "Category", "Station" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ==================== Station Data (Replicated) ====================\n" },
#endif
		{ "ModuleRelativePath", "Core/Common/StationActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "==================== Station Data (Replicated) ====================" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StationName_MetaData[] = {
		{ "Category", "Station" },
		{ "ModuleRelativePath", "Core/Common/StationActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StationType_MetaData[] = {
		{ "Category", "Station" },
		{ "ModuleRelativePath", "Core/Common/StationActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Seed_MetaData[] = {
		{ "Category", "Station" },
		{ "ModuleRelativePath", "Core/Common/StationActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VisualData_MetaData[] = {
		{ "Category", "Station" },
		{ "ModuleRelativePath", "Core/Common/StationActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BaseMeshComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LightsComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DockingZone;
	static const UECodeGen_Private::FStructPropertyParams NewProp_StationId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_StationName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_StationType;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Seed;
	static const UECodeGen_Private::FStructPropertyParams NewProp_VisualData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AStationActor_ClientRPC_OpenStationMenu, "ClientRPC_OpenStationMenu" }, // 1968481489
		{ &Z_Construct_UFunction_AStationActor_GetStationId, "GetStationId" }, // 724220845
		{ &Z_Construct_UFunction_AStationActor_GetStationName, "GetStationName" }, // 3095192526
		{ &Z_Construct_UFunction_AStationActor_GetStationType, "GetStationType" }, // 3584134899
		{ &Z_Construct_UFunction_AStationActor_HandleHangarFailure, "HandleHangarFailure" }, // 3147242742
		{ &Z_Construct_UFunction_AStationActor_HandleHangarReceived, "HandleHangarReceived" }, // 288522190
		{ &Z_Construct_UFunction_AStationActor_HasDockingAccess, "HasDockingAccess" }, // 347559422
		{ &Z_Construct_UFunction_AStationActor_InitializeStation, "InitializeStation" }, // 3630069563
		{ &Z_Construct_UFunction_AStationActor_OnDockingZoneBeginOverlap, "OnDockingZoneBeginOverlap" }, // 2257829724
		{ &Z_Construct_UFunction_AStationActor_OnRep_StationData, "OnRep_StationData" }, // 1374244659
		{ &Z_Construct_UFunction_AStationActor_ServerRPC_RequestDocking, "ServerRPC_RequestDocking" }, // 3397108270
		{ &Z_Construct_UFunction_AStationActor_ServerRPC_RequestUndock, "ServerRPC_RequestUndock" }, // 3489060149
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AStationActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AStationActor_Statics::NewProp_BaseMeshComponent = { "BaseMeshComponent", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStationActor, BaseMeshComponent), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BaseMeshComponent_MetaData), NewProp_BaseMeshComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AStationActor_Statics::NewProp_LightsComponent = { "LightsComponent", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStationActor, LightsComponent), Z_Construct_UClass_UNiagaraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LightsComponent_MetaData), NewProp_LightsComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AStationActor_Statics::NewProp_DockingZone = { "DockingZone", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStationActor, DockingZone), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DockingZone_MetaData), NewProp_DockingZone_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AStationActor_Statics::NewProp_StationId = { "StationId", "OnRep_StationData", (EPropertyFlags)0x0020080100000034, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStationActor, StationId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StationId_MetaData), NewProp_StationId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AStationActor_Statics::NewProp_StationName = { "StationName", "OnRep_StationData", (EPropertyFlags)0x0020080100000034, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStationActor, StationName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StationName_MetaData), NewProp_StationName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AStationActor_Statics::NewProp_StationType = { "StationType", "OnRep_StationData", (EPropertyFlags)0x0020080100000034, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStationActor, StationType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StationType_MetaData), NewProp_StationType_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AStationActor_Statics::NewProp_Seed = { "Seed", "OnRep_StationData", (EPropertyFlags)0x0020080100000034, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStationActor, Seed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Seed_MetaData), NewProp_Seed_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AStationActor_Statics::NewProp_VisualData = { "VisualData", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStationActor, VisualData), Z_Construct_UScriptStruct_FStationVisualRow, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VisualData_MetaData), NewProp_VisualData_MetaData) }; // 1509157565
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AStationActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStationActor_Statics::NewProp_BaseMeshComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStationActor_Statics::NewProp_LightsComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStationActor_Statics::NewProp_DockingZone,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStationActor_Statics::NewProp_StationId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStationActor_Statics::NewProp_StationName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStationActor_Statics::NewProp_StationType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStationActor_Statics::NewProp_Seed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStationActor_Statics::NewProp_VisualData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AStationActor_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AStationActor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AStationActor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AStationActor_Statics::ClassParams = {
	&AStationActor::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AStationActor_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AStationActor_Statics::PropPointers),
	0,
	0x009001A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AStationActor_Statics::Class_MetaDataParams), Z_Construct_UClass_AStationActor_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AStationActor()
{
	if (!Z_Registration_Info_UClass_AStationActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AStationActor.OuterSingleton, Z_Construct_UClass_AStationActor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AStationActor.OuterSingleton;
}
#if VALIDATE_CLASS_REPS
void AStationActor::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static FName Name_StationId(TEXT("StationId"));
	static FName Name_StationName(TEXT("StationName"));
	static FName Name_StationType(TEXT("StationType"));
	static FName Name_Seed(TEXT("Seed"));
	const bool bIsValid = true
		&& Name_StationId == ClassReps[(int32)ENetFields_Private::StationId].Property->GetFName()
		&& Name_StationName == ClassReps[(int32)ENetFields_Private::StationName].Property->GetFName()
		&& Name_StationType == ClassReps[(int32)ENetFields_Private::StationType].Property->GetFName()
		&& Name_Seed == ClassReps[(int32)ENetFields_Private::Seed].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in AStationActor"));
}
#endif
DEFINE_VTABLE_PTR_HELPER_CTOR(AStationActor);
AStationActor::~AStationActor() {}
// ********** End Class AStationActor **************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_StationActor_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AStationActor, AStationActor::StaticClass, TEXT("AStationActor"), &Z_Registration_Info_UClass_AStationActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AStationActor), 300704525U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_StationActor_h__Script_Echoes_3951727151(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_StationActor_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_StationActor_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
