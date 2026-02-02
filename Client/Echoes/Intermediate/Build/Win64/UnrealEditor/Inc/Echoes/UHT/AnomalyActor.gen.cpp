// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AnomalyActor.h"
#include "EchoesWorldVisualTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeAnomalyActor() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ECHOES_API UClass* Z_Construct_UClass_AAnomalyActor();
ECHOES_API UClass* Z_Construct_UClass_AAnomalyActor_NoRegister();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FAnomalyVisualRow();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UAudioComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
NIAGARA_API UClass* Z_Construct_UClass_UNiagaraComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AAnomalyActor Function ActivateScanningSignature *************************
struct Z_Construct_UFunction_AAnomalyActor_ActivateScanningSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Anomaly" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Activate scanning signature (called when player scans)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/AnomalyActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Activate scanning signature (called when player scans)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AAnomalyActor_ActivateScanningSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AAnomalyActor, nullptr, "ActivateScanningSignature", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AAnomalyActor_ActivateScanningSignature_Statics::Function_MetaDataParams), Z_Construct_UFunction_AAnomalyActor_ActivateScanningSignature_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AAnomalyActor_ActivateScanningSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AAnomalyActor_ActivateScanningSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AAnomalyActor::execActivateScanningSignature)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ActivateScanningSignature();
	P_NATIVE_END;
}
// ********** End Class AAnomalyActor Function ActivateScanningSignature ***************************

// ********** Begin Class AAnomalyActor Function DeactivateScanningSignature ***********************
struct Z_Construct_UFunction_AAnomalyActor_DeactivateScanningSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Anomaly" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Deactivate scanning signature\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/AnomalyActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Deactivate scanning signature" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AAnomalyActor_DeactivateScanningSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AAnomalyActor, nullptr, "DeactivateScanningSignature", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AAnomalyActor_DeactivateScanningSignature_Statics::Function_MetaDataParams), Z_Construct_UFunction_AAnomalyActor_DeactivateScanningSignature_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AAnomalyActor_DeactivateScanningSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AAnomalyActor_DeactivateScanningSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AAnomalyActor::execDeactivateScanningSignature)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DeactivateScanningSignature();
	P_NATIVE_END;
}
// ********** End Class AAnomalyActor Function DeactivateScanningSignature *************************

// ********** Begin Class AAnomalyActor Function GetAnomalyDifficulty ******************************
struct Z_Construct_UFunction_AAnomalyActor_GetAnomalyDifficulty_Statics
{
	struct AnomalyActor_eventGetAnomalyDifficulty_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Anomaly" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the anomaly difficulty\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/AnomalyActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the anomaly difficulty" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AAnomalyActor_GetAnomalyDifficulty_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AnomalyActor_eventGetAnomalyDifficulty_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AAnomalyActor_GetAnomalyDifficulty_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AAnomalyActor_GetAnomalyDifficulty_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AAnomalyActor_GetAnomalyDifficulty_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AAnomalyActor_GetAnomalyDifficulty_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AAnomalyActor, nullptr, "GetAnomalyDifficulty", Z_Construct_UFunction_AAnomalyActor_GetAnomalyDifficulty_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AAnomalyActor_GetAnomalyDifficulty_Statics::PropPointers), sizeof(Z_Construct_UFunction_AAnomalyActor_GetAnomalyDifficulty_Statics::AnomalyActor_eventGetAnomalyDifficulty_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AAnomalyActor_GetAnomalyDifficulty_Statics::Function_MetaDataParams), Z_Construct_UFunction_AAnomalyActor_GetAnomalyDifficulty_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AAnomalyActor_GetAnomalyDifficulty_Statics::AnomalyActor_eventGetAnomalyDifficulty_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AAnomalyActor_GetAnomalyDifficulty()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AAnomalyActor_GetAnomalyDifficulty_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AAnomalyActor::execGetAnomalyDifficulty)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GetAnomalyDifficulty();
	P_NATIVE_END;
}
// ********** End Class AAnomalyActor Function GetAnomalyDifficulty ********************************

// ********** Begin Class AAnomalyActor Function GetAnomalyId **************************************
struct Z_Construct_UFunction_AAnomalyActor_GetAnomalyId_Statics
{
	struct AnomalyActor_eventGetAnomalyId_Parms
	{
		FGuid ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Anomaly" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the anomaly's unique ID\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/AnomalyActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the anomaly's unique ID" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AAnomalyActor_GetAnomalyId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AnomalyActor_eventGetAnomalyId_Parms, ReturnValue), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AAnomalyActor_GetAnomalyId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AAnomalyActor_GetAnomalyId_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AAnomalyActor_GetAnomalyId_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AAnomalyActor_GetAnomalyId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AAnomalyActor, nullptr, "GetAnomalyId", Z_Construct_UFunction_AAnomalyActor_GetAnomalyId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AAnomalyActor_GetAnomalyId_Statics::PropPointers), sizeof(Z_Construct_UFunction_AAnomalyActor_GetAnomalyId_Statics::AnomalyActor_eventGetAnomalyId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AAnomalyActor_GetAnomalyId_Statics::Function_MetaDataParams), Z_Construct_UFunction_AAnomalyActor_GetAnomalyId_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AAnomalyActor_GetAnomalyId_Statics::AnomalyActor_eventGetAnomalyId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AAnomalyActor_GetAnomalyId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AAnomalyActor_GetAnomalyId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AAnomalyActor::execGetAnomalyId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGuid*)Z_Param__Result=P_THIS->GetAnomalyId();
	P_NATIVE_END;
}
// ********** End Class AAnomalyActor Function GetAnomalyId ****************************************

// ********** Begin Class AAnomalyActor Function GetAnomalyName ************************************
struct Z_Construct_UFunction_AAnomalyActor_GetAnomalyName_Statics
{
	struct AnomalyActor_eventGetAnomalyName_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Anomaly" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the anomaly's name\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/AnomalyActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the anomaly's name" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AAnomalyActor_GetAnomalyName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AnomalyActor_eventGetAnomalyName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AAnomalyActor_GetAnomalyName_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AAnomalyActor_GetAnomalyName_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AAnomalyActor_GetAnomalyName_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AAnomalyActor_GetAnomalyName_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AAnomalyActor, nullptr, "GetAnomalyName", Z_Construct_UFunction_AAnomalyActor_GetAnomalyName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AAnomalyActor_GetAnomalyName_Statics::PropPointers), sizeof(Z_Construct_UFunction_AAnomalyActor_GetAnomalyName_Statics::AnomalyActor_eventGetAnomalyName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AAnomalyActor_GetAnomalyName_Statics::Function_MetaDataParams), Z_Construct_UFunction_AAnomalyActor_GetAnomalyName_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AAnomalyActor_GetAnomalyName_Statics::AnomalyActor_eventGetAnomalyName_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AAnomalyActor_GetAnomalyName()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AAnomalyActor_GetAnomalyName_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AAnomalyActor::execGetAnomalyName)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GetAnomalyName();
	P_NATIVE_END;
}
// ********** End Class AAnomalyActor Function GetAnomalyName **************************************

// ********** Begin Class AAnomalyActor Function GetAnomalyType ************************************
struct Z_Construct_UFunction_AAnomalyActor_GetAnomalyType_Statics
{
	struct AnomalyActor_eventGetAnomalyType_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Anomaly" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the anomaly type\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/AnomalyActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the anomaly type" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AAnomalyActor_GetAnomalyType_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AnomalyActor_eventGetAnomalyType_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AAnomalyActor_GetAnomalyType_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AAnomalyActor_GetAnomalyType_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AAnomalyActor_GetAnomalyType_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AAnomalyActor_GetAnomalyType_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AAnomalyActor, nullptr, "GetAnomalyType", Z_Construct_UFunction_AAnomalyActor_GetAnomalyType_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AAnomalyActor_GetAnomalyType_Statics::PropPointers), sizeof(Z_Construct_UFunction_AAnomalyActor_GetAnomalyType_Statics::AnomalyActor_eventGetAnomalyType_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AAnomalyActor_GetAnomalyType_Statics::Function_MetaDataParams), Z_Construct_UFunction_AAnomalyActor_GetAnomalyType_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AAnomalyActor_GetAnomalyType_Statics::AnomalyActor_eventGetAnomalyType_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AAnomalyActor_GetAnomalyType()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AAnomalyActor_GetAnomalyType_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AAnomalyActor::execGetAnomalyType)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GetAnomalyType();
	P_NATIVE_END;
}
// ********** End Class AAnomalyActor Function GetAnomalyType **************************************

// ********** Begin Class AAnomalyActor Function InitializeAnomaly *********************************
struct Z_Construct_UFunction_AAnomalyActor_InitializeAnomaly_Statics
{
	struct AnomalyActor_eventInitializeAnomaly_Parms
	{
		FGuid AnomalyId;
		FString AnomalyName;
		FString AnomalyType;
		FString AnomalyDifficulty;
		int32 Seed;
		FAnomalyVisualRow VisualData;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Anomaly" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Initialize anomaly from server configuration\n\x09 * \n\x09 * @param AnomalyId - Unique identifier of the anomaly\n\x09 * @param AnomalyName - Name of the anomaly\n\x09 * @param AnomalyType - Type (Combat/Relic/Data/Gas/Ore)\n\x09 * @param AnomalyDifficulty - Difficulty level (Easy/Medium/Hard/Elite)\n\x09 * @param Seed - Procedural generation seed\n\x09 * @param VisualData - Visual configuration from data table\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/AnomalyActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Initialize anomaly from server configuration\n\n@param AnomalyId - Unique identifier of the anomaly\n@param AnomalyName - Name of the anomaly\n@param AnomalyType - Type (Combat/Relic/Data/Gas/Ore)\n@param AnomalyDifficulty - Difficulty level (Easy/Medium/Hard/Elite)\n@param Seed - Procedural generation seed\n@param VisualData - Visual configuration from data table" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AnomalyId_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AnomalyName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AnomalyType_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AnomalyDifficulty_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VisualData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_AnomalyId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_AnomalyName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_AnomalyType;
	static const UECodeGen_Private::FStrPropertyParams NewProp_AnomalyDifficulty;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Seed;
	static const UECodeGen_Private::FStructPropertyParams NewProp_VisualData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AAnomalyActor_InitializeAnomaly_Statics::NewProp_AnomalyId = { "AnomalyId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AnomalyActor_eventInitializeAnomaly_Parms, AnomalyId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AnomalyId_MetaData), NewProp_AnomalyId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AAnomalyActor_InitializeAnomaly_Statics::NewProp_AnomalyName = { "AnomalyName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AnomalyActor_eventInitializeAnomaly_Parms, AnomalyName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AnomalyName_MetaData), NewProp_AnomalyName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AAnomalyActor_InitializeAnomaly_Statics::NewProp_AnomalyType = { "AnomalyType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AnomalyActor_eventInitializeAnomaly_Parms, AnomalyType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AnomalyType_MetaData), NewProp_AnomalyType_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AAnomalyActor_InitializeAnomaly_Statics::NewProp_AnomalyDifficulty = { "AnomalyDifficulty", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AnomalyActor_eventInitializeAnomaly_Parms, AnomalyDifficulty), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AnomalyDifficulty_MetaData), NewProp_AnomalyDifficulty_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AAnomalyActor_InitializeAnomaly_Statics::NewProp_Seed = { "Seed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AnomalyActor_eventInitializeAnomaly_Parms, Seed), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AAnomalyActor_InitializeAnomaly_Statics::NewProp_VisualData = { "VisualData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AnomalyActor_eventInitializeAnomaly_Parms, VisualData), Z_Construct_UScriptStruct_FAnomalyVisualRow, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VisualData_MetaData), NewProp_VisualData_MetaData) }; // 1127289124
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AAnomalyActor_InitializeAnomaly_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AAnomalyActor_InitializeAnomaly_Statics::NewProp_AnomalyId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AAnomalyActor_InitializeAnomaly_Statics::NewProp_AnomalyName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AAnomalyActor_InitializeAnomaly_Statics::NewProp_AnomalyType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AAnomalyActor_InitializeAnomaly_Statics::NewProp_AnomalyDifficulty,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AAnomalyActor_InitializeAnomaly_Statics::NewProp_Seed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AAnomalyActor_InitializeAnomaly_Statics::NewProp_VisualData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AAnomalyActor_InitializeAnomaly_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AAnomalyActor_InitializeAnomaly_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AAnomalyActor, nullptr, "InitializeAnomaly", Z_Construct_UFunction_AAnomalyActor_InitializeAnomaly_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AAnomalyActor_InitializeAnomaly_Statics::PropPointers), sizeof(Z_Construct_UFunction_AAnomalyActor_InitializeAnomaly_Statics::AnomalyActor_eventInitializeAnomaly_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AAnomalyActor_InitializeAnomaly_Statics::Function_MetaDataParams), Z_Construct_UFunction_AAnomalyActor_InitializeAnomaly_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AAnomalyActor_InitializeAnomaly_Statics::AnomalyActor_eventInitializeAnomaly_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AAnomalyActor_InitializeAnomaly()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AAnomalyActor_InitializeAnomaly_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AAnomalyActor::execInitializeAnomaly)
{
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_AnomalyId);
	P_GET_PROPERTY(FStrProperty,Z_Param_AnomalyName);
	P_GET_PROPERTY(FStrProperty,Z_Param_AnomalyType);
	P_GET_PROPERTY(FStrProperty,Z_Param_AnomalyDifficulty);
	P_GET_PROPERTY(FIntProperty,Z_Param_Seed);
	P_GET_STRUCT_REF(FAnomalyVisualRow,Z_Param_Out_VisualData);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializeAnomaly(Z_Param_Out_AnomalyId,Z_Param_AnomalyName,Z_Param_AnomalyType,Z_Param_AnomalyDifficulty,Z_Param_Seed,Z_Param_Out_VisualData);
	P_NATIVE_END;
}
// ********** End Class AAnomalyActor Function InitializeAnomaly ***********************************

// ********** Begin Class AAnomalyActor ************************************************************
void AAnomalyActor::StaticRegisterNativesAAnomalyActor()
{
	UClass* Class = AAnomalyActor::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ActivateScanningSignature", &AAnomalyActor::execActivateScanningSignature },
		{ "DeactivateScanningSignature", &AAnomalyActor::execDeactivateScanningSignature },
		{ "GetAnomalyDifficulty", &AAnomalyActor::execGetAnomalyDifficulty },
		{ "GetAnomalyId", &AAnomalyActor::execGetAnomalyId },
		{ "GetAnomalyName", &AAnomalyActor::execGetAnomalyName },
		{ "GetAnomalyType", &AAnomalyActor::execGetAnomalyType },
		{ "InitializeAnomaly", &AAnomalyActor::execInitializeAnomaly },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_AAnomalyActor;
UClass* AAnomalyActor::GetPrivateStaticClass()
{
	using TClass = AAnomalyActor;
	if (!Z_Registration_Info_UClass_AAnomalyActor.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("AnomalyActor"),
			Z_Registration_Info_UClass_AAnomalyActor.InnerSingleton,
			StaticRegisterNativesAAnomalyActor,
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
	return Z_Registration_Info_UClass_AAnomalyActor.InnerSingleton;
}
UClass* Z_Construct_UClass_AAnomalyActor_NoRegister()
{
	return AAnomalyActor::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AAnomalyActor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * AAnomalyActor\n * \n * Represents a cosmic anomaly in a solar system\n * Supports different types: Combat, Relic, Data, Gas, Ore\n * Features scanning signature system for exploration gameplay\n * Configurable difficulty levels affect visuals and rewards\n * \n * Key Features:\n * - Type-specific visual configurations (Combat/Relic/Data/Gas)\n * - Scanning signature VFX (visible when scanned)\n * - Difficulty-based icons and effects\n * - Trigger zones for interaction\n * - Support for loot/reward systems\n */" },
#endif
		{ "IncludePath", "Core/Common/Actor/AnomalyActor.h" },
		{ "ModuleRelativePath", "Core/Common/Actor/AnomalyActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "AAnomalyActor\n\nRepresents a cosmic anomaly in a solar system\nSupports different types: Combat, Relic, Data, Gas, Ore\nFeatures scanning signature system for exploration gameplay\nConfigurable difficulty levels affect visuals and rewards\n\nKey Features:\n- Type-specific visual configurations (Combat/Relic/Data/Gas)\n- Scanning signature VFX (visible when scanned)\n- Difficulty-based icons and effects\n- Trigger zones for interaction\n- Support for loot/reward systems" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RootSceneComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Root scene component */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/Actor/AnomalyActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Root scene component" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CenterMeshComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Central structure mesh */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/Actor/AnomalyActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Central structure mesh" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SignatureVFXComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Scanning signature VFX */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/Actor/AnomalyActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Scanning signature VFX" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TypeVFXComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Type-specific VFX (combat beams, data streams, gas clouds) */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/Actor/AnomalyActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Type-specific VFX (combat beams, data streams, gas clouds)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AmbientAudioComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Ambient audio component */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/Actor/AnomalyActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ambient audio component" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WarningAudioComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Warning audio component */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/Actor/AnomalyActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Warning audio component" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TriggerSphere_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Trigger sphere for interaction detection */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/Actor/AnomalyActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Trigger sphere for interaction detection" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AnomalyId_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Anomaly" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Unique ID of this anomaly */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/AnomalyActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Unique ID of this anomaly" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AnomalyName_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Anomaly" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Name of the anomaly */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/AnomalyActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Name of the anomaly" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AnomalyType_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Anomaly" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Type of anomaly (Combat/Relic/Data/Gas/Ore) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/AnomalyActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Type of anomaly (Combat/Relic/Data/Gas/Ore)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AnomalyDifficulty_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Anomaly" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Difficulty level (Easy/Medium/Hard/Elite) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/AnomalyActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Difficulty level (Easy/Medium/Hard/Elite)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GenerationSeed_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Anomaly" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Procedural generation seed */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/AnomalyActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Procedural generation seed" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSignatureActive_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Anomaly" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether signature is currently visible (scanned) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/AnomalyActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether signature is currently visible (scanned)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RootSceneComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CenterMeshComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SignatureVFXComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TypeVFXComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AmbientAudioComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WarningAudioComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TriggerSphere;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AnomalyId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_AnomalyName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_AnomalyType;
	static const UECodeGen_Private::FStrPropertyParams NewProp_AnomalyDifficulty;
	static const UECodeGen_Private::FIntPropertyParams NewProp_GenerationSeed;
	static void NewProp_bSignatureActive_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSignatureActive;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AAnomalyActor_ActivateScanningSignature, "ActivateScanningSignature" }, // 3113792925
		{ &Z_Construct_UFunction_AAnomalyActor_DeactivateScanningSignature, "DeactivateScanningSignature" }, // 3865618010
		{ &Z_Construct_UFunction_AAnomalyActor_GetAnomalyDifficulty, "GetAnomalyDifficulty" }, // 2321957606
		{ &Z_Construct_UFunction_AAnomalyActor_GetAnomalyId, "GetAnomalyId" }, // 4181011891
		{ &Z_Construct_UFunction_AAnomalyActor_GetAnomalyName, "GetAnomalyName" }, // 3537045982
		{ &Z_Construct_UFunction_AAnomalyActor_GetAnomalyType, "GetAnomalyType" }, // 1604774164
		{ &Z_Construct_UFunction_AAnomalyActor_InitializeAnomaly, "InitializeAnomaly" }, // 3928338507
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAnomalyActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAnomalyActor_Statics::NewProp_RootSceneComponent = { "RootSceneComponent", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AAnomalyActor, RootSceneComponent), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RootSceneComponent_MetaData), NewProp_RootSceneComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAnomalyActor_Statics::NewProp_CenterMeshComponent = { "CenterMeshComponent", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AAnomalyActor, CenterMeshComponent), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CenterMeshComponent_MetaData), NewProp_CenterMeshComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAnomalyActor_Statics::NewProp_SignatureVFXComponent = { "SignatureVFXComponent", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AAnomalyActor, SignatureVFXComponent), Z_Construct_UClass_UNiagaraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SignatureVFXComponent_MetaData), NewProp_SignatureVFXComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAnomalyActor_Statics::NewProp_TypeVFXComponent = { "TypeVFXComponent", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AAnomalyActor, TypeVFXComponent), Z_Construct_UClass_UNiagaraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TypeVFXComponent_MetaData), NewProp_TypeVFXComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAnomalyActor_Statics::NewProp_AmbientAudioComponent = { "AmbientAudioComponent", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AAnomalyActor, AmbientAudioComponent), Z_Construct_UClass_UAudioComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AmbientAudioComponent_MetaData), NewProp_AmbientAudioComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAnomalyActor_Statics::NewProp_WarningAudioComponent = { "WarningAudioComponent", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AAnomalyActor, WarningAudioComponent), Z_Construct_UClass_UAudioComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WarningAudioComponent_MetaData), NewProp_WarningAudioComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAnomalyActor_Statics::NewProp_TriggerSphere = { "TriggerSphere", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AAnomalyActor, TriggerSphere), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TriggerSphere_MetaData), NewProp_TriggerSphere_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AAnomalyActor_Statics::NewProp_AnomalyId = { "AnomalyId", nullptr, (EPropertyFlags)0x0040000000020035, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AAnomalyActor, AnomalyId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AnomalyId_MetaData), NewProp_AnomalyId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AAnomalyActor_Statics::NewProp_AnomalyName = { "AnomalyName", nullptr, (EPropertyFlags)0x0040000000020035, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AAnomalyActor, AnomalyName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AnomalyName_MetaData), NewProp_AnomalyName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AAnomalyActor_Statics::NewProp_AnomalyType = { "AnomalyType", nullptr, (EPropertyFlags)0x0040000000020035, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AAnomalyActor, AnomalyType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AnomalyType_MetaData), NewProp_AnomalyType_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AAnomalyActor_Statics::NewProp_AnomalyDifficulty = { "AnomalyDifficulty", nullptr, (EPropertyFlags)0x0040000000020035, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AAnomalyActor, AnomalyDifficulty), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AnomalyDifficulty_MetaData), NewProp_AnomalyDifficulty_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AAnomalyActor_Statics::NewProp_GenerationSeed = { "GenerationSeed", nullptr, (EPropertyFlags)0x0040000000020015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AAnomalyActor, GenerationSeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GenerationSeed_MetaData), NewProp_GenerationSeed_MetaData) };
void Z_Construct_UClass_AAnomalyActor_Statics::NewProp_bSignatureActive_SetBit(void* Obj)
{
	((AAnomalyActor*)Obj)->bSignatureActive = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AAnomalyActor_Statics::NewProp_bSignatureActive = { "bSignatureActive", nullptr, (EPropertyFlags)0x0040000000020035, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AAnomalyActor), &Z_Construct_UClass_AAnomalyActor_Statics::NewProp_bSignatureActive_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSignatureActive_MetaData), NewProp_bSignatureActive_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AAnomalyActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAnomalyActor_Statics::NewProp_RootSceneComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAnomalyActor_Statics::NewProp_CenterMeshComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAnomalyActor_Statics::NewProp_SignatureVFXComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAnomalyActor_Statics::NewProp_TypeVFXComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAnomalyActor_Statics::NewProp_AmbientAudioComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAnomalyActor_Statics::NewProp_WarningAudioComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAnomalyActor_Statics::NewProp_TriggerSphere,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAnomalyActor_Statics::NewProp_AnomalyId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAnomalyActor_Statics::NewProp_AnomalyName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAnomalyActor_Statics::NewProp_AnomalyType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAnomalyActor_Statics::NewProp_AnomalyDifficulty,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAnomalyActor_Statics::NewProp_GenerationSeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAnomalyActor_Statics::NewProp_bSignatureActive,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AAnomalyActor_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AAnomalyActor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AAnomalyActor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AAnomalyActor_Statics::ClassParams = {
	&AAnomalyActor::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AAnomalyActor_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AAnomalyActor_Statics::PropPointers),
	0,
	0x009001A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AAnomalyActor_Statics::Class_MetaDataParams), Z_Construct_UClass_AAnomalyActor_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AAnomalyActor()
{
	if (!Z_Registration_Info_UClass_AAnomalyActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AAnomalyActor.OuterSingleton, Z_Construct_UClass_AAnomalyActor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AAnomalyActor.OuterSingleton;
}
#if VALIDATE_CLASS_REPS
void AAnomalyActor::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static FName Name_AnomalyId(TEXT("AnomalyId"));
	static FName Name_AnomalyName(TEXT("AnomalyName"));
	static FName Name_AnomalyType(TEXT("AnomalyType"));
	static FName Name_AnomalyDifficulty(TEXT("AnomalyDifficulty"));
	static FName Name_bSignatureActive(TEXT("bSignatureActive"));
	const bool bIsValid = true
		&& Name_AnomalyId == ClassReps[(int32)ENetFields_Private::AnomalyId].Property->GetFName()
		&& Name_AnomalyName == ClassReps[(int32)ENetFields_Private::AnomalyName].Property->GetFName()
		&& Name_AnomalyType == ClassReps[(int32)ENetFields_Private::AnomalyType].Property->GetFName()
		&& Name_AnomalyDifficulty == ClassReps[(int32)ENetFields_Private::AnomalyDifficulty].Property->GetFName()
		&& Name_bSignatureActive == ClassReps[(int32)ENetFields_Private::bSignatureActive].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in AAnomalyActor"));
}
#endif
DEFINE_VTABLE_PTR_HELPER_CTOR(AAnomalyActor);
AAnomalyActor::~AAnomalyActor() {}
// ********** End Class AAnomalyActor **************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_AnomalyActor_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AAnomalyActor, AAnomalyActor::StaticClass, TEXT("AAnomalyActor"), &Z_Registration_Info_UClass_AAnomalyActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AAnomalyActor), 2474699564U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_AnomalyActor_h__Script_Echoes_1432113553(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_AnomalyActor_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_AnomalyActor_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
