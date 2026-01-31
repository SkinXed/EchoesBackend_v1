// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Echoes/Core/Common/AsteroidBeltActor.h"
#include "Echoes/Core/Common/EchoesWorldVisualTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeAsteroidBeltActor() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ECHOES_API UClass* Z_Construct_UClass_AAsteroidBeltActor();
ECHOES_API UClass* Z_Construct_UClass_AAsteroidBeltActor_NoRegister();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FAsteroidBeltVisualRow();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UAudioComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UHierarchicalInstancedStaticMeshComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
NIAGARA_API UClass* Z_Construct_UClass_UNiagaraComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AAsteroidBeltActor Function GetBeltId ************************************
struct Z_Construct_UFunction_AAsteroidBeltActor_GetBeltId_Statics
{
	struct AsteroidBeltActor_eventGetBeltId_Parms
	{
		FGuid ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "AsteroidBelt" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the belt's unique ID\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/AsteroidBeltActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the belt's unique ID" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AAsteroidBeltActor_GetBeltId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AsteroidBeltActor_eventGetBeltId_Parms, ReturnValue), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AAsteroidBeltActor_GetBeltId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AAsteroidBeltActor_GetBeltId_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AAsteroidBeltActor_GetBeltId_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AAsteroidBeltActor_GetBeltId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AAsteroidBeltActor, nullptr, "GetBeltId", Z_Construct_UFunction_AAsteroidBeltActor_GetBeltId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AAsteroidBeltActor_GetBeltId_Statics::PropPointers), sizeof(Z_Construct_UFunction_AAsteroidBeltActor_GetBeltId_Statics::AsteroidBeltActor_eventGetBeltId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AAsteroidBeltActor_GetBeltId_Statics::Function_MetaDataParams), Z_Construct_UFunction_AAsteroidBeltActor_GetBeltId_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AAsteroidBeltActor_GetBeltId_Statics::AsteroidBeltActor_eventGetBeltId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AAsteroidBeltActor_GetBeltId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AAsteroidBeltActor_GetBeltId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AAsteroidBeltActor::execGetBeltId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGuid*)Z_Param__Result=P_THIS->GetBeltId();
	P_NATIVE_END;
}
// ********** End Class AAsteroidBeltActor Function GetBeltId **************************************

// ********** Begin Class AAsteroidBeltActor Function GetBeltName **********************************
struct Z_Construct_UFunction_AAsteroidBeltActor_GetBeltName_Statics
{
	struct AsteroidBeltActor_eventGetBeltName_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "AsteroidBelt" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the belt's name\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/AsteroidBeltActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the belt's name" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AAsteroidBeltActor_GetBeltName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AsteroidBeltActor_eventGetBeltName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AAsteroidBeltActor_GetBeltName_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AAsteroidBeltActor_GetBeltName_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AAsteroidBeltActor_GetBeltName_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AAsteroidBeltActor_GetBeltName_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AAsteroidBeltActor, nullptr, "GetBeltName", Z_Construct_UFunction_AAsteroidBeltActor_GetBeltName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AAsteroidBeltActor_GetBeltName_Statics::PropPointers), sizeof(Z_Construct_UFunction_AAsteroidBeltActor_GetBeltName_Statics::AsteroidBeltActor_eventGetBeltName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AAsteroidBeltActor_GetBeltName_Statics::Function_MetaDataParams), Z_Construct_UFunction_AAsteroidBeltActor_GetBeltName_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AAsteroidBeltActor_GetBeltName_Statics::AsteroidBeltActor_eventGetBeltName_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AAsteroidBeltActor_GetBeltName()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AAsteroidBeltActor_GetBeltName_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AAsteroidBeltActor::execGetBeltName)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GetBeltName();
	P_NATIVE_END;
}
// ********** End Class AAsteroidBeltActor Function GetBeltName ************************************

// ********** Begin Class AAsteroidBeltActor Function InitializeAsteroidBelt ***********************
struct Z_Construct_UFunction_AAsteroidBeltActor_InitializeAsteroidBelt_Statics
{
	struct AsteroidBeltActor_eventInitializeAsteroidBelt_Parms
	{
		FGuid BeltId;
		FString BeltName;
		int32 Seed;
		float BeltRadius;
		int32 AsteroidCount;
		FAsteroidBeltVisualRow VisualData;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "AsteroidBelt" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Initialize asteroid belt from server configuration\n\x09 * \n\x09 * @param BeltId - Unique identifier of the belt\n\x09 * @param BeltName - Name of the belt\n\x09 * @param Seed - Procedural generation seed (from database)\n\x09 * @param BeltRadius - Radius of the belt in world units\n\x09 * @param AsteroidCount - Number of asteroids to spawn\n\x09 * @param VisualData - Visual configuration from data table\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/AsteroidBeltActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Initialize asteroid belt from server configuration\n\n@param BeltId - Unique identifier of the belt\n@param BeltName - Name of the belt\n@param Seed - Procedural generation seed (from database)\n@param BeltRadius - Radius of the belt in world units\n@param AsteroidCount - Number of asteroids to spawn\n@param VisualData - Visual configuration from data table" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BeltId_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BeltName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VisualData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_BeltId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_BeltName;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Seed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BeltRadius;
	static const UECodeGen_Private::FIntPropertyParams NewProp_AsteroidCount;
	static const UECodeGen_Private::FStructPropertyParams NewProp_VisualData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AAsteroidBeltActor_InitializeAsteroidBelt_Statics::NewProp_BeltId = { "BeltId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AsteroidBeltActor_eventInitializeAsteroidBelt_Parms, BeltId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BeltId_MetaData), NewProp_BeltId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AAsteroidBeltActor_InitializeAsteroidBelt_Statics::NewProp_BeltName = { "BeltName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AsteroidBeltActor_eventInitializeAsteroidBelt_Parms, BeltName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BeltName_MetaData), NewProp_BeltName_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AAsteroidBeltActor_InitializeAsteroidBelt_Statics::NewProp_Seed = { "Seed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AsteroidBeltActor_eventInitializeAsteroidBelt_Parms, Seed), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AAsteroidBeltActor_InitializeAsteroidBelt_Statics::NewProp_BeltRadius = { "BeltRadius", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AsteroidBeltActor_eventInitializeAsteroidBelt_Parms, BeltRadius), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AAsteroidBeltActor_InitializeAsteroidBelt_Statics::NewProp_AsteroidCount = { "AsteroidCount", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AsteroidBeltActor_eventInitializeAsteroidBelt_Parms, AsteroidCount), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AAsteroidBeltActor_InitializeAsteroidBelt_Statics::NewProp_VisualData = { "VisualData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AsteroidBeltActor_eventInitializeAsteroidBelt_Parms, VisualData), Z_Construct_UScriptStruct_FAsteroidBeltVisualRow, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VisualData_MetaData), NewProp_VisualData_MetaData) }; // 816970460
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AAsteroidBeltActor_InitializeAsteroidBelt_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AAsteroidBeltActor_InitializeAsteroidBelt_Statics::NewProp_BeltId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AAsteroidBeltActor_InitializeAsteroidBelt_Statics::NewProp_BeltName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AAsteroidBeltActor_InitializeAsteroidBelt_Statics::NewProp_Seed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AAsteroidBeltActor_InitializeAsteroidBelt_Statics::NewProp_BeltRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AAsteroidBeltActor_InitializeAsteroidBelt_Statics::NewProp_AsteroidCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AAsteroidBeltActor_InitializeAsteroidBelt_Statics::NewProp_VisualData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AAsteroidBeltActor_InitializeAsteroidBelt_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AAsteroidBeltActor_InitializeAsteroidBelt_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AAsteroidBeltActor, nullptr, "InitializeAsteroidBelt", Z_Construct_UFunction_AAsteroidBeltActor_InitializeAsteroidBelt_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AAsteroidBeltActor_InitializeAsteroidBelt_Statics::PropPointers), sizeof(Z_Construct_UFunction_AAsteroidBeltActor_InitializeAsteroidBelt_Statics::AsteroidBeltActor_eventInitializeAsteroidBelt_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AAsteroidBeltActor_InitializeAsteroidBelt_Statics::Function_MetaDataParams), Z_Construct_UFunction_AAsteroidBeltActor_InitializeAsteroidBelt_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AAsteroidBeltActor_InitializeAsteroidBelt_Statics::AsteroidBeltActor_eventInitializeAsteroidBelt_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AAsteroidBeltActor_InitializeAsteroidBelt()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AAsteroidBeltActor_InitializeAsteroidBelt_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AAsteroidBeltActor::execInitializeAsteroidBelt)
{
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_BeltId);
	P_GET_PROPERTY(FStrProperty,Z_Param_BeltName);
	P_GET_PROPERTY(FIntProperty,Z_Param_Seed);
	P_GET_PROPERTY(FFloatProperty,Z_Param_BeltRadius);
	P_GET_PROPERTY(FIntProperty,Z_Param_AsteroidCount);
	P_GET_STRUCT_REF(FAsteroidBeltVisualRow,Z_Param_Out_VisualData);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializeAsteroidBelt(Z_Param_Out_BeltId,Z_Param_BeltName,Z_Param_Seed,Z_Param_BeltRadius,Z_Param_AsteroidCount,Z_Param_Out_VisualData);
	P_NATIVE_END;
}
// ********** End Class AAsteroidBeltActor Function InitializeAsteroidBelt *************************

// ********** Begin Class AAsteroidBeltActor *******************************************************
void AAsteroidBeltActor::StaticRegisterNativesAAsteroidBeltActor()
{
	UClass* Class = AAsteroidBeltActor::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetBeltId", &AAsteroidBeltActor::execGetBeltId },
		{ "GetBeltName", &AAsteroidBeltActor::execGetBeltName },
		{ "InitializeAsteroidBelt", &AAsteroidBeltActor::execInitializeAsteroidBelt },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_AAsteroidBeltActor;
UClass* AAsteroidBeltActor::GetPrivateStaticClass()
{
	using TClass = AAsteroidBeltActor;
	if (!Z_Registration_Info_UClass_AAsteroidBeltActor.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("AsteroidBeltActor"),
			Z_Registration_Info_UClass_AAsteroidBeltActor.InnerSingleton,
			StaticRegisterNativesAAsteroidBeltActor,
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
	return Z_Registration_Info_UClass_AAsteroidBeltActor.InnerSingleton;
}
UClass* Z_Construct_UClass_AAsteroidBeltActor_NoRegister()
{
	return AAsteroidBeltActor::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AAsteroidBeltActor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * AAsteroidBeltActor\n * \n * Represents an asteroid belt in a solar system\n * Uses Hierarchical Instanced Static Mesh Component (HISM) for efficient rendering\n * Supports procedural placement based on seed for deterministic generation\n * Individual asteroids have collision for mining gameplay\n * \n * Key Features:\n * - Optimized rendering with HISM (thousands of asteroids with minimal performance cost)\n * - Procedural distribution using seed from database\n * - Resource information for mining gameplay\n * - Collision detection for asteroid-ship interactions\n * - VFX for dust clouds and ambient effects\n */" },
#endif
		{ "IncludePath", "Core/Common/AsteroidBeltActor.h" },
		{ "ModuleRelativePath", "Core/Common/AsteroidBeltActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "AAsteroidBeltActor\n\nRepresents an asteroid belt in a solar system\nUses Hierarchical Instanced Static Mesh Component (HISM) for efficient rendering\nSupports procedural placement based on seed for deterministic generation\nIndividual asteroids have collision for mining gameplay\n\nKey Features:\n- Optimized rendering with HISM (thousands of asteroids with minimal performance cost)\n- Procedural distribution using seed from database\n- Resource information for mining gameplay\n- Collision detection for asteroid-ship interactions\n- VFX for dust clouds and ambient effects" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RootSceneComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Root scene component */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/AsteroidBeltActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Root scene component" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AsteroidInstances_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Hierarchical Instanced Static Mesh Component for asteroids (highly optimized) */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/AsteroidBeltActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Hierarchical Instanced Static Mesh Component for asteroids (highly optimized)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DustCloudComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional: Niagara component for dust cloud effects */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/AsteroidBeltActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional: Niagara component for dust cloud effects" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AmbientAudioComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Audio component for ambient sound */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/AsteroidBeltActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Audio component for ambient sound" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BeltId_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "AsteroidBelt" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Unique ID of this asteroid belt */" },
#endif
		{ "ModuleRelativePath", "Core/Common/AsteroidBeltActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Unique ID of this asteroid belt" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BeltName_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "AsteroidBelt" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Name of the asteroid belt */" },
#endif
		{ "ModuleRelativePath", "Core/Common/AsteroidBeltActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Name of the asteroid belt" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GenerationSeed_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "AsteroidBelt" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Procedural generation seed */" },
#endif
		{ "ModuleRelativePath", "Core/Common/AsteroidBeltActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Procedural generation seed" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Radius_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "AsteroidBelt" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Belt radius in world units */" },
#endif
		{ "ModuleRelativePath", "Core/Common/AsteroidBeltActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Belt radius in world units" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AsteroidCount_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "AsteroidBelt" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Number of asteroids in the belt */" },
#endif
		{ "ModuleRelativePath", "Core/Common/AsteroidBeltActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Number of asteroids in the belt" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RootSceneComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AsteroidInstances;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DustCloudComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AmbientAudioComponent;
	static const UECodeGen_Private::FStructPropertyParams NewProp_BeltId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_BeltName;
	static const UECodeGen_Private::FIntPropertyParams NewProp_GenerationSeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Radius;
	static const UECodeGen_Private::FIntPropertyParams NewProp_AsteroidCount;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AAsteroidBeltActor_GetBeltId, "GetBeltId" }, // 2108119204
		{ &Z_Construct_UFunction_AAsteroidBeltActor_GetBeltName, "GetBeltName" }, // 818061847
		{ &Z_Construct_UFunction_AAsteroidBeltActor_InitializeAsteroidBelt, "InitializeAsteroidBelt" }, // 1536594701
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAsteroidBeltActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAsteroidBeltActor_Statics::NewProp_RootSceneComponent = { "RootSceneComponent", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AAsteroidBeltActor, RootSceneComponent), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RootSceneComponent_MetaData), NewProp_RootSceneComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAsteroidBeltActor_Statics::NewProp_AsteroidInstances = { "AsteroidInstances", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AAsteroidBeltActor, AsteroidInstances), Z_Construct_UClass_UHierarchicalInstancedStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AsteroidInstances_MetaData), NewProp_AsteroidInstances_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAsteroidBeltActor_Statics::NewProp_DustCloudComponent = { "DustCloudComponent", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AAsteroidBeltActor, DustCloudComponent), Z_Construct_UClass_UNiagaraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DustCloudComponent_MetaData), NewProp_DustCloudComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAsteroidBeltActor_Statics::NewProp_AmbientAudioComponent = { "AmbientAudioComponent", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AAsteroidBeltActor, AmbientAudioComponent), Z_Construct_UClass_UAudioComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AmbientAudioComponent_MetaData), NewProp_AmbientAudioComponent_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AAsteroidBeltActor_Statics::NewProp_BeltId = { "BeltId", nullptr, (EPropertyFlags)0x0040000000020035, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AAsteroidBeltActor, BeltId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BeltId_MetaData), NewProp_BeltId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AAsteroidBeltActor_Statics::NewProp_BeltName = { "BeltName", nullptr, (EPropertyFlags)0x0040000000020035, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AAsteroidBeltActor, BeltName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BeltName_MetaData), NewProp_BeltName_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AAsteroidBeltActor_Statics::NewProp_GenerationSeed = { "GenerationSeed", nullptr, (EPropertyFlags)0x0040000000020015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AAsteroidBeltActor, GenerationSeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GenerationSeed_MetaData), NewProp_GenerationSeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AAsteroidBeltActor_Statics::NewProp_Radius = { "Radius", nullptr, (EPropertyFlags)0x0040000000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AAsteroidBeltActor, Radius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Radius_MetaData), NewProp_Radius_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AAsteroidBeltActor_Statics::NewProp_AsteroidCount = { "AsteroidCount", nullptr, (EPropertyFlags)0x0040000000020015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AAsteroidBeltActor, AsteroidCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AsteroidCount_MetaData), NewProp_AsteroidCount_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AAsteroidBeltActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAsteroidBeltActor_Statics::NewProp_RootSceneComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAsteroidBeltActor_Statics::NewProp_AsteroidInstances,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAsteroidBeltActor_Statics::NewProp_DustCloudComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAsteroidBeltActor_Statics::NewProp_AmbientAudioComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAsteroidBeltActor_Statics::NewProp_BeltId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAsteroidBeltActor_Statics::NewProp_BeltName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAsteroidBeltActor_Statics::NewProp_GenerationSeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAsteroidBeltActor_Statics::NewProp_Radius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAsteroidBeltActor_Statics::NewProp_AsteroidCount,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AAsteroidBeltActor_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AAsteroidBeltActor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AAsteroidBeltActor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AAsteroidBeltActor_Statics::ClassParams = {
	&AAsteroidBeltActor::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AAsteroidBeltActor_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AAsteroidBeltActor_Statics::PropPointers),
	0,
	0x009001A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AAsteroidBeltActor_Statics::Class_MetaDataParams), Z_Construct_UClass_AAsteroidBeltActor_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AAsteroidBeltActor()
{
	if (!Z_Registration_Info_UClass_AAsteroidBeltActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AAsteroidBeltActor.OuterSingleton, Z_Construct_UClass_AAsteroidBeltActor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AAsteroidBeltActor.OuterSingleton;
}
#if VALIDATE_CLASS_REPS
void AAsteroidBeltActor::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static FName Name_BeltId(TEXT("BeltId"));
	static FName Name_BeltName(TEXT("BeltName"));
	const bool bIsValid = true
		&& Name_BeltId == ClassReps[(int32)ENetFields_Private::BeltId].Property->GetFName()
		&& Name_BeltName == ClassReps[(int32)ENetFields_Private::BeltName].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in AAsteroidBeltActor"));
}
#endif
DEFINE_VTABLE_PTR_HELPER_CTOR(AAsteroidBeltActor);
AAsteroidBeltActor::~AAsteroidBeltActor() {}
// ********** End Class AAsteroidBeltActor *********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_AsteroidBeltActor_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AAsteroidBeltActor, AAsteroidBeltActor::StaticClass, TEXT("AAsteroidBeltActor"), &Z_Registration_Info_UClass_AAsteroidBeltActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AAsteroidBeltActor), 2962751562U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_AsteroidBeltActor_h__Script_Echoes_1617245266(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_AsteroidBeltActor_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_AsteroidBeltActor_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
