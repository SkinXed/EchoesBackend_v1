// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PlanetActor.h"
#include "EchoesWorldVisualTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodePlanetActor() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ECHOES_API UClass* Z_Construct_UClass_APlanetActor();
ECHOES_API UClass* Z_Construct_UClass_APlanetActor_NoRegister();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FPlanetVisualRow();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Class APlanetActor Function ApplySeedVariation *********************************
struct Z_Construct_UFunction_APlanetActor_ApplySeedVariation_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Planet" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Apply seed-based variation to visual appearance\n\x09 * Uses the seed to:\n\x09 * - Select one material from the array\n\x09 * - Adjust rotation\n\x09 * - Modify atmosphere intensity\n\x09 * - Randomize texture parameters\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/PlanetActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Apply seed-based variation to visual appearance\nUses the seed to:\n- Select one material from the array\n- Adjust rotation\n- Modify atmosphere intensity\n- Randomize texture parameters" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APlanetActor_ApplySeedVariation_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_APlanetActor, nullptr, "ApplySeedVariation", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APlanetActor_ApplySeedVariation_Statics::Function_MetaDataParams), Z_Construct_UFunction_APlanetActor_ApplySeedVariation_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_APlanetActor_ApplySeedVariation()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APlanetActor_ApplySeedVariation_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APlanetActor::execApplySeedVariation)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ApplySeedVariation();
	P_NATIVE_END;
}
// ********** End Class APlanetActor Function ApplySeedVariation ***********************************

// ********** Begin Class APlanetActor Function GetPlanetId ****************************************
struct Z_Construct_UFunction_APlanetActor_GetPlanetId_Statics
{
	struct PlanetActor_eventGetPlanetId_Parms
	{
		FGuid ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Planet" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ==================== Getters ====================\n" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/PlanetActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "==================== Getters ====================" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_APlanetActor_GetPlanetId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PlanetActor_eventGetPlanetId_Parms, ReturnValue), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APlanetActor_GetPlanetId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlanetActor_GetPlanetId_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_APlanetActor_GetPlanetId_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APlanetActor_GetPlanetId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_APlanetActor, nullptr, "GetPlanetId", Z_Construct_UFunction_APlanetActor_GetPlanetId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APlanetActor_GetPlanetId_Statics::PropPointers), sizeof(Z_Construct_UFunction_APlanetActor_GetPlanetId_Statics::PlanetActor_eventGetPlanetId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APlanetActor_GetPlanetId_Statics::Function_MetaDataParams), Z_Construct_UFunction_APlanetActor_GetPlanetId_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_APlanetActor_GetPlanetId_Statics::PlanetActor_eventGetPlanetId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_APlanetActor_GetPlanetId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APlanetActor_GetPlanetId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APlanetActor::execGetPlanetId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGuid*)Z_Param__Result=P_THIS->GetPlanetId();
	P_NATIVE_END;
}
// ********** End Class APlanetActor Function GetPlanetId ******************************************

// ********** Begin Class APlanetActor Function GetPlanetName **************************************
struct Z_Construct_UFunction_APlanetActor_GetPlanetName_Statics
{
	struct PlanetActor_eventGetPlanetName_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Planet" },
		{ "ModuleRelativePath", "Core/Common/Actor/PlanetActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_APlanetActor_GetPlanetName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PlanetActor_eventGetPlanetName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APlanetActor_GetPlanetName_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlanetActor_GetPlanetName_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_APlanetActor_GetPlanetName_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APlanetActor_GetPlanetName_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_APlanetActor, nullptr, "GetPlanetName", Z_Construct_UFunction_APlanetActor_GetPlanetName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APlanetActor_GetPlanetName_Statics::PropPointers), sizeof(Z_Construct_UFunction_APlanetActor_GetPlanetName_Statics::PlanetActor_eventGetPlanetName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APlanetActor_GetPlanetName_Statics::Function_MetaDataParams), Z_Construct_UFunction_APlanetActor_GetPlanetName_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_APlanetActor_GetPlanetName_Statics::PlanetActor_eventGetPlanetName_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_APlanetActor_GetPlanetName()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APlanetActor_GetPlanetName_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APlanetActor::execGetPlanetName)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GetPlanetName();
	P_NATIVE_END;
}
// ********** End Class APlanetActor Function GetPlanetName ****************************************

// ********** Begin Class APlanetActor Function GetPlanetType **************************************
struct Z_Construct_UFunction_APlanetActor_GetPlanetType_Statics
{
	struct PlanetActor_eventGetPlanetType_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Planet" },
		{ "ModuleRelativePath", "Core/Common/Actor/PlanetActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_APlanetActor_GetPlanetType_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PlanetActor_eventGetPlanetType_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APlanetActor_GetPlanetType_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlanetActor_GetPlanetType_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_APlanetActor_GetPlanetType_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APlanetActor_GetPlanetType_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_APlanetActor, nullptr, "GetPlanetType", Z_Construct_UFunction_APlanetActor_GetPlanetType_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APlanetActor_GetPlanetType_Statics::PropPointers), sizeof(Z_Construct_UFunction_APlanetActor_GetPlanetType_Statics::PlanetActor_eventGetPlanetType_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APlanetActor_GetPlanetType_Statics::Function_MetaDataParams), Z_Construct_UFunction_APlanetActor_GetPlanetType_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_APlanetActor_GetPlanetType_Statics::PlanetActor_eventGetPlanetType_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_APlanetActor_GetPlanetType()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APlanetActor_GetPlanetType_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APlanetActor::execGetPlanetType)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GetPlanetType();
	P_NATIVE_END;
}
// ********** End Class APlanetActor Function GetPlanetType ****************************************

// ********** Begin Class APlanetActor Function GetRadius ******************************************
struct Z_Construct_UFunction_APlanetActor_GetRadius_Statics
{
	struct PlanetActor_eventGetRadius_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Planet" },
		{ "ModuleRelativePath", "Core/Common/Actor/PlanetActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_APlanetActor_GetRadius_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PlanetActor_eventGetRadius_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APlanetActor_GetRadius_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlanetActor_GetRadius_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_APlanetActor_GetRadius_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APlanetActor_GetRadius_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_APlanetActor, nullptr, "GetRadius", Z_Construct_UFunction_APlanetActor_GetRadius_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APlanetActor_GetRadius_Statics::PropPointers), sizeof(Z_Construct_UFunction_APlanetActor_GetRadius_Statics::PlanetActor_eventGetRadius_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APlanetActor_GetRadius_Statics::Function_MetaDataParams), Z_Construct_UFunction_APlanetActor_GetRadius_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_APlanetActor_GetRadius_Statics::PlanetActor_eventGetRadius_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_APlanetActor_GetRadius()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APlanetActor_GetRadius_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APlanetActor::execGetRadius)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetRadius();
	P_NATIVE_END;
}
// ********** End Class APlanetActor Function GetRadius ********************************************

// ********** Begin Class APlanetActor Function GetSeed ********************************************
struct Z_Construct_UFunction_APlanetActor_GetSeed_Statics
{
	struct PlanetActor_eventGetSeed_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Planet" },
		{ "ModuleRelativePath", "Core/Common/Actor/PlanetActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_APlanetActor_GetSeed_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PlanetActor_eventGetSeed_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APlanetActor_GetSeed_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlanetActor_GetSeed_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_APlanetActor_GetSeed_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APlanetActor_GetSeed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_APlanetActor, nullptr, "GetSeed", Z_Construct_UFunction_APlanetActor_GetSeed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APlanetActor_GetSeed_Statics::PropPointers), sizeof(Z_Construct_UFunction_APlanetActor_GetSeed_Statics::PlanetActor_eventGetSeed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APlanetActor_GetSeed_Statics::Function_MetaDataParams), Z_Construct_UFunction_APlanetActor_GetSeed_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_APlanetActor_GetSeed_Statics::PlanetActor_eventGetSeed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_APlanetActor_GetSeed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APlanetActor_GetSeed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APlanetActor::execGetSeed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetSeed();
	P_NATIVE_END;
}
// ********** End Class APlanetActor Function GetSeed **********************************************

// ********** Begin Class APlanetActor Function InitializePlanet ***********************************
struct Z_Construct_UFunction_APlanetActor_InitializePlanet_Statics
{
	struct PlanetActor_eventInitializePlanet_Parms
	{
		FGuid InPlanetId;
		FString InName;
		FString InType;
		float InRadius;
		int32 InSeed;
		FPlanetVisualRow InVisualData;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Planet" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Initialize planet from configuration data\n\x09 * Called by WorldGenerator after spawning\n\x09 * \n\x09 * @param InPlanetId - Unique planet ID from database\n\x09 * @param InName - Planet name\n\x09 * @param InType - Planet type (e.g., \"Lava\", \"Oceanic\", \"Barren\")\n\x09 * @param InRadius - Planet radius in km\n\x09 * @param InSeed - Seed for procedural variation\n\x09 * @param InVisualData - Visual configuration from data table\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/PlanetActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Initialize planet from configuration data\nCalled by WorldGenerator after spawning\n\n@param InPlanetId - Unique planet ID from database\n@param InName - Planet name\n@param InType - Planet type (e.g., \"Lava\", \"Oceanic\", \"Barren\")\n@param InRadius - Planet radius in km\n@param InSeed - Seed for procedural variation\n@param InVisualData - Visual configuration from data table" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InPlanetId_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InType_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InVisualData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_InPlanetId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_InName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_InType;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InRadius;
	static const UECodeGen_Private::FIntPropertyParams NewProp_InSeed;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InVisualData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_APlanetActor_InitializePlanet_Statics::NewProp_InPlanetId = { "InPlanetId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PlanetActor_eventInitializePlanet_Parms, InPlanetId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InPlanetId_MetaData), NewProp_InPlanetId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_APlanetActor_InitializePlanet_Statics::NewProp_InName = { "InName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PlanetActor_eventInitializePlanet_Parms, InName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InName_MetaData), NewProp_InName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_APlanetActor_InitializePlanet_Statics::NewProp_InType = { "InType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PlanetActor_eventInitializePlanet_Parms, InType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InType_MetaData), NewProp_InType_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_APlanetActor_InitializePlanet_Statics::NewProp_InRadius = { "InRadius", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PlanetActor_eventInitializePlanet_Parms, InRadius), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_APlanetActor_InitializePlanet_Statics::NewProp_InSeed = { "InSeed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PlanetActor_eventInitializePlanet_Parms, InSeed), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_APlanetActor_InitializePlanet_Statics::NewProp_InVisualData = { "InVisualData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PlanetActor_eventInitializePlanet_Parms, InVisualData), Z_Construct_UScriptStruct_FPlanetVisualRow, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InVisualData_MetaData), NewProp_InVisualData_MetaData) }; // 3120595805
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APlanetActor_InitializePlanet_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlanetActor_InitializePlanet_Statics::NewProp_InPlanetId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlanetActor_InitializePlanet_Statics::NewProp_InName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlanetActor_InitializePlanet_Statics::NewProp_InType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlanetActor_InitializePlanet_Statics::NewProp_InRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlanetActor_InitializePlanet_Statics::NewProp_InSeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlanetActor_InitializePlanet_Statics::NewProp_InVisualData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_APlanetActor_InitializePlanet_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APlanetActor_InitializePlanet_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_APlanetActor, nullptr, "InitializePlanet", Z_Construct_UFunction_APlanetActor_InitializePlanet_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APlanetActor_InitializePlanet_Statics::PropPointers), sizeof(Z_Construct_UFunction_APlanetActor_InitializePlanet_Statics::PlanetActor_eventInitializePlanet_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APlanetActor_InitializePlanet_Statics::Function_MetaDataParams), Z_Construct_UFunction_APlanetActor_InitializePlanet_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_APlanetActor_InitializePlanet_Statics::PlanetActor_eventInitializePlanet_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_APlanetActor_InitializePlanet()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APlanetActor_InitializePlanet_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APlanetActor::execInitializePlanet)
{
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_InPlanetId);
	P_GET_PROPERTY(FStrProperty,Z_Param_InName);
	P_GET_PROPERTY(FStrProperty,Z_Param_InType);
	P_GET_PROPERTY(FFloatProperty,Z_Param_InRadius);
	P_GET_PROPERTY(FIntProperty,Z_Param_InSeed);
	P_GET_STRUCT_REF(FPlanetVisualRow,Z_Param_Out_InVisualData);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializePlanet(Z_Param_Out_InPlanetId,Z_Param_InName,Z_Param_InType,Z_Param_InRadius,Z_Param_InSeed,Z_Param_Out_InVisualData);
	P_NATIVE_END;
}
// ********** End Class APlanetActor Function InitializePlanet *************************************

// ********** Begin Class APlanetActor Function OnRep_PlanetData ***********************************
struct Z_Construct_UFunction_APlanetActor_OnRep_PlanetData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Common/Actor/PlanetActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APlanetActor_OnRep_PlanetData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_APlanetActor, nullptr, "OnRep_PlanetData", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APlanetActor_OnRep_PlanetData_Statics::Function_MetaDataParams), Z_Construct_UFunction_APlanetActor_OnRep_PlanetData_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_APlanetActor_OnRep_PlanetData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APlanetActor_OnRep_PlanetData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APlanetActor::execOnRep_PlanetData)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_PlanetData();
	P_NATIVE_END;
}
// ********** End Class APlanetActor Function OnRep_PlanetData *************************************

// ********** Begin Class APlanetActor *************************************************************
void APlanetActor::StaticRegisterNativesAPlanetActor()
{
	UClass* Class = APlanetActor::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ApplySeedVariation", &APlanetActor::execApplySeedVariation },
		{ "GetPlanetId", &APlanetActor::execGetPlanetId },
		{ "GetPlanetName", &APlanetActor::execGetPlanetName },
		{ "GetPlanetType", &APlanetActor::execGetPlanetType },
		{ "GetRadius", &APlanetActor::execGetRadius },
		{ "GetSeed", &APlanetActor::execGetSeed },
		{ "InitializePlanet", &APlanetActor::execInitializePlanet },
		{ "OnRep_PlanetData", &APlanetActor::execOnRep_PlanetData },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_APlanetActor;
UClass* APlanetActor::GetPrivateStaticClass()
{
	using TClass = APlanetActor;
	if (!Z_Registration_Info_UClass_APlanetActor.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("PlanetActor"),
			Z_Registration_Info_UClass_APlanetActor.InnerSingleton,
			StaticRegisterNativesAPlanetActor,
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
	return Z_Registration_Info_UClass_APlanetActor.InnerSingleton;
}
UClass* Z_Construct_UClass_APlanetActor_NoRegister()
{
	return APlanetActor::GetPrivateStaticClass();
}
struct Z_Construct_UClass_APlanetActor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * APlanetActor\n * \n * Represents a planet in the Echoes universe\n * Spawned by AEchoesWorldGenerator based on backend configuration\n * Supports seed-based visual variation and procedural generation\n * \n * Features:\n * - Server-side spawning with replication\n * - Seed-based variation for unique appearance\n * - Async asset loading for optimization\n * - Atmosphere and cloud layers\n * - Material parameter randomization\n */" },
#endif
		{ "IncludePath", "Core/Common/Actor/PlanetActor.h" },
		{ "ModuleRelativePath", "Core/Common/Actor/PlanetActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "APlanetActor\n\nRepresents a planet in the Echoes universe\nSpawned by AEchoesWorldGenerator based on backend configuration\nSupports seed-based visual variation and procedural generation\n\nFeatures:\n- Server-side spawning with replication\n- Seed-based variation for unique appearance\n- Async asset loading for optimization\n- Atmosphere and cloud layers\n- Material parameter randomization" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlanetMeshComponent_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Planet mesh component */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/Actor/PlanetActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Planet mesh component" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CloudLayerComponent_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Cloud layer mesh component (optional) */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/Actor/PlanetActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cloud layer mesh component (optional)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AtmosphereComponent_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Atmosphere mesh component (optional) */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/Actor/PlanetActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Atmosphere mesh component (optional)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RingComponent_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Ring mesh component (optional, for gas giants) */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/Actor/PlanetActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ring mesh component (optional, for gas giants)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlanetId_MetaData[] = {
		{ "Category", "Planet" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Unique planet ID from database */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/PlanetActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Unique planet ID from database" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlanetName_MetaData[] = {
		{ "Category", "Planet" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Planet name */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/PlanetActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Planet name" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlanetType_MetaData[] = {
		{ "Category", "Planet" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Planet type (e.g., \"Lava\", \"Oceanic\", \"Barren\") */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/PlanetActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Planet type (e.g., \"Lava\", \"Oceanic\", \"Barren\")" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Radius_MetaData[] = {
		{ "Category", "Planet" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Planet radius in km */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/PlanetActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Planet radius in km" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Seed_MetaData[] = {
		{ "Category", "Planet" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Seed for procedural variation */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/PlanetActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Seed for procedural variation" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VisualData_MetaData[] = {
		{ "Category", "Planet" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Visual configuration data */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/PlanetActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Visual configuration data" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlanetMeshComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CloudLayerComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AtmosphereComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RingComponent;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PlanetId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_PlanetName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_PlanetType;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Radius;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Seed;
	static const UECodeGen_Private::FStructPropertyParams NewProp_VisualData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_APlanetActor_ApplySeedVariation, "ApplySeedVariation" }, // 698242928
		{ &Z_Construct_UFunction_APlanetActor_GetPlanetId, "GetPlanetId" }, // 735537990
		{ &Z_Construct_UFunction_APlanetActor_GetPlanetName, "GetPlanetName" }, // 3184214214
		{ &Z_Construct_UFunction_APlanetActor_GetPlanetType, "GetPlanetType" }, // 3563501123
		{ &Z_Construct_UFunction_APlanetActor_GetRadius, "GetRadius" }, // 443128008
		{ &Z_Construct_UFunction_APlanetActor_GetSeed, "GetSeed" }, // 3271480025
		{ &Z_Construct_UFunction_APlanetActor_InitializePlanet, "InitializePlanet" }, // 2301507822
		{ &Z_Construct_UFunction_APlanetActor_OnRep_PlanetData, "OnRep_PlanetData" }, // 2063678419
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APlanetActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APlanetActor_Statics::NewProp_PlanetMeshComponent = { "PlanetMeshComponent", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlanetActor, PlanetMeshComponent), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlanetMeshComponent_MetaData), NewProp_PlanetMeshComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APlanetActor_Statics::NewProp_CloudLayerComponent = { "CloudLayerComponent", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlanetActor, CloudLayerComponent), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CloudLayerComponent_MetaData), NewProp_CloudLayerComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APlanetActor_Statics::NewProp_AtmosphereComponent = { "AtmosphereComponent", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlanetActor, AtmosphereComponent), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AtmosphereComponent_MetaData), NewProp_AtmosphereComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APlanetActor_Statics::NewProp_RingComponent = { "RingComponent", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlanetActor, RingComponent), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RingComponent_MetaData), NewProp_RingComponent_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_APlanetActor_Statics::NewProp_PlanetId = { "PlanetId", "OnRep_PlanetData", (EPropertyFlags)0x0020080100000034, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlanetActor, PlanetId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlanetId_MetaData), NewProp_PlanetId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_APlanetActor_Statics::NewProp_PlanetName = { "PlanetName", "OnRep_PlanetData", (EPropertyFlags)0x0020080100000034, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlanetActor, PlanetName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlanetName_MetaData), NewProp_PlanetName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_APlanetActor_Statics::NewProp_PlanetType = { "PlanetType", "OnRep_PlanetData", (EPropertyFlags)0x0020080100000034, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlanetActor, PlanetType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlanetType_MetaData), NewProp_PlanetType_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_APlanetActor_Statics::NewProp_Radius = { "Radius", "OnRep_PlanetData", (EPropertyFlags)0x0020080100000034, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlanetActor, Radius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Radius_MetaData), NewProp_Radius_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_APlanetActor_Statics::NewProp_Seed = { "Seed", "OnRep_PlanetData", (EPropertyFlags)0x0020080100000034, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlanetActor, Seed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Seed_MetaData), NewProp_Seed_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_APlanetActor_Statics::NewProp_VisualData = { "VisualData", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlanetActor, VisualData), Z_Construct_UScriptStruct_FPlanetVisualRow, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VisualData_MetaData), NewProp_VisualData_MetaData) }; // 3120595805
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APlanetActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlanetActor_Statics::NewProp_PlanetMeshComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlanetActor_Statics::NewProp_CloudLayerComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlanetActor_Statics::NewProp_AtmosphereComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlanetActor_Statics::NewProp_RingComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlanetActor_Statics::NewProp_PlanetId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlanetActor_Statics::NewProp_PlanetName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlanetActor_Statics::NewProp_PlanetType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlanetActor_Statics::NewProp_Radius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlanetActor_Statics::NewProp_Seed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlanetActor_Statics::NewProp_VisualData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APlanetActor_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_APlanetActor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APlanetActor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_APlanetActor_Statics::ClassParams = {
	&APlanetActor::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_APlanetActor_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_APlanetActor_Statics::PropPointers),
	0,
	0x009001A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APlanetActor_Statics::Class_MetaDataParams), Z_Construct_UClass_APlanetActor_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_APlanetActor()
{
	if (!Z_Registration_Info_UClass_APlanetActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APlanetActor.OuterSingleton, Z_Construct_UClass_APlanetActor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_APlanetActor.OuterSingleton;
}
#if VALIDATE_CLASS_REPS
void APlanetActor::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static FName Name_PlanetId(TEXT("PlanetId"));
	static FName Name_PlanetName(TEXT("PlanetName"));
	static FName Name_PlanetType(TEXT("PlanetType"));
	static FName Name_Radius(TEXT("Radius"));
	static FName Name_Seed(TEXT("Seed"));
	const bool bIsValid = true
		&& Name_PlanetId == ClassReps[(int32)ENetFields_Private::PlanetId].Property->GetFName()
		&& Name_PlanetName == ClassReps[(int32)ENetFields_Private::PlanetName].Property->GetFName()
		&& Name_PlanetType == ClassReps[(int32)ENetFields_Private::PlanetType].Property->GetFName()
		&& Name_Radius == ClassReps[(int32)ENetFields_Private::Radius].Property->GetFName()
		&& Name_Seed == ClassReps[(int32)ENetFields_Private::Seed].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in APlanetActor"));
}
#endif
DEFINE_VTABLE_PTR_HELPER_CTOR(APlanetActor);
APlanetActor::~APlanetActor() {}
// ********** End Class APlanetActor ***************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_PlanetActor_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_APlanetActor, APlanetActor::StaticClass, TEXT("APlanetActor"), &Z_Registration_Info_UClass_APlanetActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APlanetActor), 2085936617U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_PlanetActor_h__Script_Echoes_94852668(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_PlanetActor_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_PlanetActor_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
