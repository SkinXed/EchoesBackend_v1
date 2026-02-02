// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "StarActor.h"
#include "EchoesWorldVisualTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeStarActor() {}

// ********** Begin Cross Module References ********************************************************
ECHOES_API UClass* Z_Construct_UClass_AStarActor();
ECHOES_API UClass* Z_Construct_UClass_AStarActor_NoRegister();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FStarVisualRow();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UParticleSystemComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPointLightComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
NIAGARA_API UClass* Z_Construct_UClass_UNiagaraComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AStarActor Function GetLuminosity ****************************************
struct Z_Construct_UFunction_AStarActor_GetLuminosity_Statics
{
	struct StarActor_eventGetLuminosity_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Star" },
		{ "ModuleRelativePath", "Core/Common/Actor/StarActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AStarActor_GetLuminosity_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StarActor_eventGetLuminosity_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AStarActor_GetLuminosity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStarActor_GetLuminosity_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AStarActor_GetLuminosity_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AStarActor_GetLuminosity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AStarActor, nullptr, "GetLuminosity", Z_Construct_UFunction_AStarActor_GetLuminosity_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AStarActor_GetLuminosity_Statics::PropPointers), sizeof(Z_Construct_UFunction_AStarActor_GetLuminosity_Statics::StarActor_eventGetLuminosity_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AStarActor_GetLuminosity_Statics::Function_MetaDataParams), Z_Construct_UFunction_AStarActor_GetLuminosity_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AStarActor_GetLuminosity_Statics::StarActor_eventGetLuminosity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AStarActor_GetLuminosity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AStarActor_GetLuminosity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AStarActor::execGetLuminosity)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetLuminosity();
	P_NATIVE_END;
}
// ********** End Class AStarActor Function GetLuminosity ******************************************

// ********** Begin Class AStarActor Function GetStarClass *****************************************
struct Z_Construct_UFunction_AStarActor_GetStarClass_Statics
{
	struct StarActor_eventGetStarClass_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Star" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ==================== Getters ====================\n" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/StarActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "==================== Getters ====================" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AStarActor_GetStarClass_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StarActor_eventGetStarClass_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AStarActor_GetStarClass_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStarActor_GetStarClass_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AStarActor_GetStarClass_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AStarActor_GetStarClass_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AStarActor, nullptr, "GetStarClass", Z_Construct_UFunction_AStarActor_GetStarClass_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AStarActor_GetStarClass_Statics::PropPointers), sizeof(Z_Construct_UFunction_AStarActor_GetStarClass_Statics::StarActor_eventGetStarClass_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AStarActor_GetStarClass_Statics::Function_MetaDataParams), Z_Construct_UFunction_AStarActor_GetStarClass_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AStarActor_GetStarClass_Statics::StarActor_eventGetStarClass_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AStarActor_GetStarClass()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AStarActor_GetStarClass_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AStarActor::execGetStarClass)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GetStarClass();
	P_NATIVE_END;
}
// ********** End Class AStarActor Function GetStarClass *******************************************

// ********** Begin Class AStarActor Function GetTemperature ***************************************
struct Z_Construct_UFunction_AStarActor_GetTemperature_Statics
{
	struct StarActor_eventGetTemperature_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Star" },
		{ "ModuleRelativePath", "Core/Common/Actor/StarActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AStarActor_GetTemperature_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StarActor_eventGetTemperature_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AStarActor_GetTemperature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStarActor_GetTemperature_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AStarActor_GetTemperature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AStarActor_GetTemperature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AStarActor, nullptr, "GetTemperature", Z_Construct_UFunction_AStarActor_GetTemperature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AStarActor_GetTemperature_Statics::PropPointers), sizeof(Z_Construct_UFunction_AStarActor_GetTemperature_Statics::StarActor_eventGetTemperature_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AStarActor_GetTemperature_Statics::Function_MetaDataParams), Z_Construct_UFunction_AStarActor_GetTemperature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AStarActor_GetTemperature_Statics::StarActor_eventGetTemperature_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AStarActor_GetTemperature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AStarActor_GetTemperature_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AStarActor::execGetTemperature)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetTemperature();
	P_NATIVE_END;
}
// ********** End Class AStarActor Function GetTemperature *****************************************

// ********** Begin Class AStarActor Function InitializeStar ***************************************
struct Z_Construct_UFunction_AStarActor_InitializeStar_Statics
{
	struct StarActor_eventInitializeStar_Parms
	{
		FString InStarClass;
		float InTemperature;
		float InLuminosity;
		float InRadius;
		FStarVisualRow InVisualData;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Star" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Initialize star from configuration data\n\x09 * \n\x09 * @param InStarClass - Star classification (e.g., \"G2V\", \"M5\", \"K0\")\n\x09 * @param InTemperature - Surface temperature in Kelvin\n\x09 * @param InLuminosity - Luminosity relative to Sol\n\x09 * @param InRadius - Star radius in km\n\x09 * @param InVisualData - Visual configuration from data table\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/StarActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Initialize star from configuration data\n\n@param InStarClass - Star classification (e.g., \"G2V\", \"M5\", \"K0\")\n@param InTemperature - Surface temperature in Kelvin\n@param InLuminosity - Luminosity relative to Sol\n@param InRadius - Star radius in km\n@param InVisualData - Visual configuration from data table" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InStarClass_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InVisualData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_InStarClass;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InTemperature;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InLuminosity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InRadius;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InVisualData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AStarActor_InitializeStar_Statics::NewProp_InStarClass = { "InStarClass", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StarActor_eventInitializeStar_Parms, InStarClass), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InStarClass_MetaData), NewProp_InStarClass_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AStarActor_InitializeStar_Statics::NewProp_InTemperature = { "InTemperature", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StarActor_eventInitializeStar_Parms, InTemperature), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AStarActor_InitializeStar_Statics::NewProp_InLuminosity = { "InLuminosity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StarActor_eventInitializeStar_Parms, InLuminosity), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AStarActor_InitializeStar_Statics::NewProp_InRadius = { "InRadius", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StarActor_eventInitializeStar_Parms, InRadius), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AStarActor_InitializeStar_Statics::NewProp_InVisualData = { "InVisualData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StarActor_eventInitializeStar_Parms, InVisualData), Z_Construct_UScriptStruct_FStarVisualRow, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InVisualData_MetaData), NewProp_InVisualData_MetaData) }; // 3346617476
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AStarActor_InitializeStar_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStarActor_InitializeStar_Statics::NewProp_InStarClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStarActor_InitializeStar_Statics::NewProp_InTemperature,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStarActor_InitializeStar_Statics::NewProp_InLuminosity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStarActor_InitializeStar_Statics::NewProp_InRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStarActor_InitializeStar_Statics::NewProp_InVisualData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AStarActor_InitializeStar_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AStarActor_InitializeStar_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AStarActor, nullptr, "InitializeStar", Z_Construct_UFunction_AStarActor_InitializeStar_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AStarActor_InitializeStar_Statics::PropPointers), sizeof(Z_Construct_UFunction_AStarActor_InitializeStar_Statics::StarActor_eventInitializeStar_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AStarActor_InitializeStar_Statics::Function_MetaDataParams), Z_Construct_UFunction_AStarActor_InitializeStar_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AStarActor_InitializeStar_Statics::StarActor_eventInitializeStar_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AStarActor_InitializeStar()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AStarActor_InitializeStar_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AStarActor::execInitializeStar)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InStarClass);
	P_GET_PROPERTY(FFloatProperty,Z_Param_InTemperature);
	P_GET_PROPERTY(FFloatProperty,Z_Param_InLuminosity);
	P_GET_PROPERTY(FFloatProperty,Z_Param_InRadius);
	P_GET_STRUCT_REF(FStarVisualRow,Z_Param_Out_InVisualData);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializeStar(Z_Param_InStarClass,Z_Param_InTemperature,Z_Param_InLuminosity,Z_Param_InRadius,Z_Param_Out_InVisualData);
	P_NATIVE_END;
}
// ********** End Class AStarActor Function InitializeStar *****************************************

// ********** Begin Class AStarActor Function OnRep_StarData ***************************************
struct Z_Construct_UFunction_AStarActor_OnRep_StarData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Common/Actor/StarActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AStarActor_OnRep_StarData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AStarActor, nullptr, "OnRep_StarData", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AStarActor_OnRep_StarData_Statics::Function_MetaDataParams), Z_Construct_UFunction_AStarActor_OnRep_StarData_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AStarActor_OnRep_StarData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AStarActor_OnRep_StarData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AStarActor::execOnRep_StarData)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_StarData();
	P_NATIVE_END;
}
// ********** End Class AStarActor Function OnRep_StarData *****************************************

// ********** Begin Class AStarActor ***************************************************************
void AStarActor::StaticRegisterNativesAStarActor()
{
	UClass* Class = AStarActor::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetLuminosity", &AStarActor::execGetLuminosity },
		{ "GetStarClass", &AStarActor::execGetStarClass },
		{ "GetTemperature", &AStarActor::execGetTemperature },
		{ "InitializeStar", &AStarActor::execInitializeStar },
		{ "OnRep_StarData", &AStarActor::execOnRep_StarData },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_AStarActor;
UClass* AStarActor::GetPrivateStaticClass()
{
	using TClass = AStarActor;
	if (!Z_Registration_Info_UClass_AStarActor.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("StarActor"),
			Z_Registration_Info_UClass_AStarActor.InnerSingleton,
			StaticRegisterNativesAStarActor,
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
	return Z_Registration_Info_UClass_AStarActor.InnerSingleton;
}
UClass* Z_Construct_UClass_AStarActor_NoRegister()
{
	return AStarActor::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AStarActor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * AStarActor\n * \n * Represents a star in the Echoes universe\n * Central light source for the solar system\n * Spawned by AEchoesWorldGenerator based on backend configuration\n */" },
#endif
		{ "IncludePath", "Core/Common/Actor/StarActor.h" },
		{ "ModuleRelativePath", "Core/Common/Actor/StarActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "AStarActor\n\nRepresents a star in the Echoes universe\nCentral light source for the solar system\nSpawned by AEchoesWorldGenerator based on backend configuration" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StarMeshComponent_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Star mesh component */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/Actor/StarActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Star mesh component" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StarLightComponent_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Point light for illumination */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/Actor/StarActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Point light for illumination" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CoronaParticleComponent_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Corona particle system (Legacy Cascade) */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/Actor/StarActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Corona particle system (Legacy Cascade)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CoronaNiagaraComponent_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Corona VFX (Niagara) */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/Actor/StarActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Corona VFX (Niagara)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StarClass_MetaData[] = {
		{ "Category", "Star" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Star classification (e.g., \"G2V\" for Sun-like) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/StarActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Star classification (e.g., \"G2V\" for Sun-like)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Temperature_MetaData[] = {
		{ "Category", "Star" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Surface temperature in Kelvin */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/StarActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Surface temperature in Kelvin" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Luminosity_MetaData[] = {
		{ "Category", "Star" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Luminosity relative to Sol (1.0 = Sun) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/StarActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Luminosity relative to Sol (1.0 = Sun)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Radius_MetaData[] = {
		{ "Category", "Star" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Star radius in km */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/StarActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Star radius in km" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VisualData_MetaData[] = {
		{ "Category", "Star" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Visual configuration data */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/StarActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Visual configuration data" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StarMeshComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StarLightComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CoronaParticleComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CoronaNiagaraComponent;
	static const UECodeGen_Private::FStrPropertyParams NewProp_StarClass;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Temperature;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Luminosity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Radius;
	static const UECodeGen_Private::FStructPropertyParams NewProp_VisualData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AStarActor_GetLuminosity, "GetLuminosity" }, // 1965264837
		{ &Z_Construct_UFunction_AStarActor_GetStarClass, "GetStarClass" }, // 3453151592
		{ &Z_Construct_UFunction_AStarActor_GetTemperature, "GetTemperature" }, // 3057400580
		{ &Z_Construct_UFunction_AStarActor_InitializeStar, "InitializeStar" }, // 201940487
		{ &Z_Construct_UFunction_AStarActor_OnRep_StarData, "OnRep_StarData" }, // 1102302679
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AStarActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AStarActor_Statics::NewProp_StarMeshComponent = { "StarMeshComponent", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStarActor, StarMeshComponent), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StarMeshComponent_MetaData), NewProp_StarMeshComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AStarActor_Statics::NewProp_StarLightComponent = { "StarLightComponent", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStarActor, StarLightComponent), Z_Construct_UClass_UPointLightComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StarLightComponent_MetaData), NewProp_StarLightComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AStarActor_Statics::NewProp_CoronaParticleComponent = { "CoronaParticleComponent", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStarActor, CoronaParticleComponent), Z_Construct_UClass_UParticleSystemComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CoronaParticleComponent_MetaData), NewProp_CoronaParticleComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AStarActor_Statics::NewProp_CoronaNiagaraComponent = { "CoronaNiagaraComponent", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStarActor, CoronaNiagaraComponent), Z_Construct_UClass_UNiagaraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CoronaNiagaraComponent_MetaData), NewProp_CoronaNiagaraComponent_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AStarActor_Statics::NewProp_StarClass = { "StarClass", "OnRep_StarData", (EPropertyFlags)0x0020080100000034, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStarActor, StarClass), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StarClass_MetaData), NewProp_StarClass_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AStarActor_Statics::NewProp_Temperature = { "Temperature", "OnRep_StarData", (EPropertyFlags)0x0020080100000034, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStarActor, Temperature), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Temperature_MetaData), NewProp_Temperature_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AStarActor_Statics::NewProp_Luminosity = { "Luminosity", "OnRep_StarData", (EPropertyFlags)0x0020080100000034, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStarActor, Luminosity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Luminosity_MetaData), NewProp_Luminosity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AStarActor_Statics::NewProp_Radius = { "Radius", "OnRep_StarData", (EPropertyFlags)0x0020080100000034, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStarActor, Radius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Radius_MetaData), NewProp_Radius_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AStarActor_Statics::NewProp_VisualData = { "VisualData", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStarActor, VisualData), Z_Construct_UScriptStruct_FStarVisualRow, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VisualData_MetaData), NewProp_VisualData_MetaData) }; // 3346617476
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AStarActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStarActor_Statics::NewProp_StarMeshComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStarActor_Statics::NewProp_StarLightComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStarActor_Statics::NewProp_CoronaParticleComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStarActor_Statics::NewProp_CoronaNiagaraComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStarActor_Statics::NewProp_StarClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStarActor_Statics::NewProp_Temperature,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStarActor_Statics::NewProp_Luminosity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStarActor_Statics::NewProp_Radius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStarActor_Statics::NewProp_VisualData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AStarActor_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AStarActor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AStarActor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AStarActor_Statics::ClassParams = {
	&AStarActor::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AStarActor_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AStarActor_Statics::PropPointers),
	0,
	0x009001A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AStarActor_Statics::Class_MetaDataParams), Z_Construct_UClass_AStarActor_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AStarActor()
{
	if (!Z_Registration_Info_UClass_AStarActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AStarActor.OuterSingleton, Z_Construct_UClass_AStarActor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AStarActor.OuterSingleton;
}
#if VALIDATE_CLASS_REPS
void AStarActor::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static FName Name_StarClass(TEXT("StarClass"));
	static FName Name_Temperature(TEXT("Temperature"));
	static FName Name_Luminosity(TEXT("Luminosity"));
	static FName Name_Radius(TEXT("Radius"));
	const bool bIsValid = true
		&& Name_StarClass == ClassReps[(int32)ENetFields_Private::StarClass].Property->GetFName()
		&& Name_Temperature == ClassReps[(int32)ENetFields_Private::Temperature].Property->GetFName()
		&& Name_Luminosity == ClassReps[(int32)ENetFields_Private::Luminosity].Property->GetFName()
		&& Name_Radius == ClassReps[(int32)ENetFields_Private::Radius].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in AStarActor"));
}
#endif
DEFINE_VTABLE_PTR_HELPER_CTOR(AStarActor);
AStarActor::~AStarActor() {}
// ********** End Class AStarActor *****************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_StarActor_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AStarActor, AStarActor::StaticClass, TEXT("AStarActor"), &Z_Registration_Info_UClass_AStarActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AStarActor), 3825171588U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_StarActor_h__Script_Echoes_1254375079(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_StarActor_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_StarActor_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
