// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MoonActor.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeMoonActor() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ECHOES_API UClass* Z_Construct_UClass_AMoonActor();
ECHOES_API UClass* Z_Construct_UClass_AMoonActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_USplineComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AMoonActor Function ClientOnly_DrawOrbit *********************************
struct Z_Construct_UFunction_AMoonActor_ClientOnly_DrawOrbit_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Moon|Orbit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Create and draw the orbital path around parent planet (client-only)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/MoonActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Create and draw the orbital path around parent planet (client-only)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMoonActor_ClientOnly_DrawOrbit_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AMoonActor, nullptr, "ClientOnly_DrawOrbit", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMoonActor_ClientOnly_DrawOrbit_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMoonActor_ClientOnly_DrawOrbit_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AMoonActor_ClientOnly_DrawOrbit()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMoonActor_ClientOnly_DrawOrbit_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMoonActor::execClientOnly_DrawOrbit)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientOnly_DrawOrbit();
	P_NATIVE_END;
}
// ********** End Class AMoonActor Function ClientOnly_DrawOrbit ***********************************

// ********** Begin Class AMoonActor Function GetMoonId ********************************************
struct Z_Construct_UFunction_AMoonActor_GetMoonId_Statics
{
	struct MoonActor_eventGetMoonId_Parms
	{
		FGuid ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Moon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ==================== Getters ====================\n" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/MoonActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "==================== Getters ====================" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMoonActor_GetMoonId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MoonActor_eventGetMoonId_Parms, ReturnValue), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMoonActor_GetMoonId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMoonActor_GetMoonId_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMoonActor_GetMoonId_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMoonActor_GetMoonId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AMoonActor, nullptr, "GetMoonId", Z_Construct_UFunction_AMoonActor_GetMoonId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMoonActor_GetMoonId_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMoonActor_GetMoonId_Statics::MoonActor_eventGetMoonId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMoonActor_GetMoonId_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMoonActor_GetMoonId_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AMoonActor_GetMoonId_Statics::MoonActor_eventGetMoonId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMoonActor_GetMoonId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMoonActor_GetMoonId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMoonActor::execGetMoonId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGuid*)Z_Param__Result=P_THIS->GetMoonId();
	P_NATIVE_END;
}
// ********** End Class AMoonActor Function GetMoonId **********************************************

// ********** Begin Class AMoonActor Function GetMoonName ******************************************
struct Z_Construct_UFunction_AMoonActor_GetMoonName_Statics
{
	struct MoonActor_eventGetMoonName_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Moon" },
		{ "ModuleRelativePath", "Core/Common/Actor/MoonActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AMoonActor_GetMoonName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MoonActor_eventGetMoonName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMoonActor_GetMoonName_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMoonActor_GetMoonName_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMoonActor_GetMoonName_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMoonActor_GetMoonName_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AMoonActor, nullptr, "GetMoonName", Z_Construct_UFunction_AMoonActor_GetMoonName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMoonActor_GetMoonName_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMoonActor_GetMoonName_Statics::MoonActor_eventGetMoonName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMoonActor_GetMoonName_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMoonActor_GetMoonName_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AMoonActor_GetMoonName_Statics::MoonActor_eventGetMoonName_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMoonActor_GetMoonName()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMoonActor_GetMoonName_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMoonActor::execGetMoonName)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GetMoonName();
	P_NATIVE_END;
}
// ********** End Class AMoonActor Function GetMoonName ********************************************

// ********** Begin Class AMoonActor Function GetMoonType ******************************************
struct Z_Construct_UFunction_AMoonActor_GetMoonType_Statics
{
	struct MoonActor_eventGetMoonType_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Moon" },
		{ "ModuleRelativePath", "Core/Common/Actor/MoonActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AMoonActor_GetMoonType_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MoonActor_eventGetMoonType_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMoonActor_GetMoonType_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMoonActor_GetMoonType_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMoonActor_GetMoonType_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMoonActor_GetMoonType_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AMoonActor, nullptr, "GetMoonType", Z_Construct_UFunction_AMoonActor_GetMoonType_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMoonActor_GetMoonType_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMoonActor_GetMoonType_Statics::MoonActor_eventGetMoonType_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMoonActor_GetMoonType_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMoonActor_GetMoonType_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AMoonActor_GetMoonType_Statics::MoonActor_eventGetMoonType_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMoonActor_GetMoonType()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMoonActor_GetMoonType_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMoonActor::execGetMoonType)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GetMoonType();
	P_NATIVE_END;
}
// ********** End Class AMoonActor Function GetMoonType ********************************************

// ********** Begin Class AMoonActor Function GetOrbitRadius ***************************************
struct Z_Construct_UFunction_AMoonActor_GetOrbitRadius_Statics
{
	struct MoonActor_eventGetOrbitRadius_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Moon" },
		{ "ModuleRelativePath", "Core/Common/Actor/MoonActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AMoonActor_GetOrbitRadius_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MoonActor_eventGetOrbitRadius_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMoonActor_GetOrbitRadius_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMoonActor_GetOrbitRadius_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMoonActor_GetOrbitRadius_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMoonActor_GetOrbitRadius_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AMoonActor, nullptr, "GetOrbitRadius", Z_Construct_UFunction_AMoonActor_GetOrbitRadius_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMoonActor_GetOrbitRadius_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMoonActor_GetOrbitRadius_Statics::MoonActor_eventGetOrbitRadius_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMoonActor_GetOrbitRadius_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMoonActor_GetOrbitRadius_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AMoonActor_GetOrbitRadius_Statics::MoonActor_eventGetOrbitRadius_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMoonActor_GetOrbitRadius()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMoonActor_GetOrbitRadius_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMoonActor::execGetOrbitRadius)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetOrbitRadius();
	P_NATIVE_END;
}
// ********** End Class AMoonActor Function GetOrbitRadius *****************************************

// ********** Begin Class AMoonActor Function InitializeMoon ***************************************
struct Z_Construct_UFunction_AMoonActor_InitializeMoon_Statics
{
	struct MoonActor_eventInitializeMoon_Parms
	{
		FGuid InMoonId;
		FString InName;
		FString InType;
		float InOrbitRadius;
		int32 InSeed;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Moon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Initialize moon from configuration data\n\x09 * Called by WorldGenerator after spawning\n\x09 * \n\x09 * @param InMoonId - Unique moon ID from database\n\x09 * @param InName - Moon name\n\x09 * @param InType - Moon type (e.g., \"Rocky\", \"Ice\", \"Volcanic\")\n\x09 * @param InOrbitRadius - Distance from parent planet in km\n\x09 * @param InSeed - Seed for procedural variation\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/MoonActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Initialize moon from configuration data\nCalled by WorldGenerator after spawning\n\n@param InMoonId - Unique moon ID from database\n@param InName - Moon name\n@param InType - Moon type (e.g., \"Rocky\", \"Ice\", \"Volcanic\")\n@param InOrbitRadius - Distance from parent planet in km\n@param InSeed - Seed for procedural variation" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InMoonId_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InType_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_InMoonId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_InName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_InType;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InOrbitRadius;
	static const UECodeGen_Private::FIntPropertyParams NewProp_InSeed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMoonActor_InitializeMoon_Statics::NewProp_InMoonId = { "InMoonId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MoonActor_eventInitializeMoon_Parms, InMoonId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InMoonId_MetaData), NewProp_InMoonId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AMoonActor_InitializeMoon_Statics::NewProp_InName = { "InName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MoonActor_eventInitializeMoon_Parms, InName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InName_MetaData), NewProp_InName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AMoonActor_InitializeMoon_Statics::NewProp_InType = { "InType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MoonActor_eventInitializeMoon_Parms, InType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InType_MetaData), NewProp_InType_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AMoonActor_InitializeMoon_Statics::NewProp_InOrbitRadius = { "InOrbitRadius", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MoonActor_eventInitializeMoon_Parms, InOrbitRadius), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AMoonActor_InitializeMoon_Statics::NewProp_InSeed = { "InSeed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MoonActor_eventInitializeMoon_Parms, InSeed), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMoonActor_InitializeMoon_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMoonActor_InitializeMoon_Statics::NewProp_InMoonId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMoonActor_InitializeMoon_Statics::NewProp_InName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMoonActor_InitializeMoon_Statics::NewProp_InType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMoonActor_InitializeMoon_Statics::NewProp_InOrbitRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMoonActor_InitializeMoon_Statics::NewProp_InSeed,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMoonActor_InitializeMoon_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMoonActor_InitializeMoon_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AMoonActor, nullptr, "InitializeMoon", Z_Construct_UFunction_AMoonActor_InitializeMoon_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMoonActor_InitializeMoon_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMoonActor_InitializeMoon_Statics::MoonActor_eventInitializeMoon_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMoonActor_InitializeMoon_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMoonActor_InitializeMoon_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AMoonActor_InitializeMoon_Statics::MoonActor_eventInitializeMoon_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMoonActor_InitializeMoon()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMoonActor_InitializeMoon_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMoonActor::execInitializeMoon)
{
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_InMoonId);
	P_GET_PROPERTY(FStrProperty,Z_Param_InName);
	P_GET_PROPERTY(FStrProperty,Z_Param_InType);
	P_GET_PROPERTY(FFloatProperty,Z_Param_InOrbitRadius);
	P_GET_PROPERTY(FIntProperty,Z_Param_InSeed);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializeMoon(Z_Param_Out_InMoonId,Z_Param_InName,Z_Param_InType,Z_Param_InOrbitRadius,Z_Param_InSeed);
	P_NATIVE_END;
}
// ********** End Class AMoonActor Function InitializeMoon *****************************************

// ********** Begin Class AMoonActor Function OnRep_MoonData ***************************************
struct Z_Construct_UFunction_AMoonActor_OnRep_MoonData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Common/Actor/MoonActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMoonActor_OnRep_MoonData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AMoonActor, nullptr, "OnRep_MoonData", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMoonActor_OnRep_MoonData_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMoonActor_OnRep_MoonData_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AMoonActor_OnRep_MoonData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMoonActor_OnRep_MoonData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMoonActor::execOnRep_MoonData)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_MoonData();
	P_NATIVE_END;
}
// ********** End Class AMoonActor Function OnRep_MoonData *****************************************

// ********** Begin Class AMoonActor Function SetOrbitParameters ***********************************
struct Z_Construct_UFunction_AMoonActor_SetOrbitParameters_Statics
{
	struct MoonActor_eventSetOrbitParameters_Parms
	{
		float InOrbitRadius;
		FVector InParentLocation;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Moon|Orbit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Set orbit parameters for this moon (called by WorldGenerator)\n\x09 * @param InOrbitRadius - Distance from parent planet in km\n\x09 * @param InParentLocation - Parent planet's world location\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/MoonActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set orbit parameters for this moon (called by WorldGenerator)\n@param InOrbitRadius - Distance from parent planet in km\n@param InParentLocation - Parent planet's world location" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InParentLocation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InOrbitRadius;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InParentLocation;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AMoonActor_SetOrbitParameters_Statics::NewProp_InOrbitRadius = { "InOrbitRadius", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MoonActor_eventSetOrbitParameters_Parms, InOrbitRadius), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMoonActor_SetOrbitParameters_Statics::NewProp_InParentLocation = { "InParentLocation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MoonActor_eventSetOrbitParameters_Parms, InParentLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InParentLocation_MetaData), NewProp_InParentLocation_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMoonActor_SetOrbitParameters_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMoonActor_SetOrbitParameters_Statics::NewProp_InOrbitRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMoonActor_SetOrbitParameters_Statics::NewProp_InParentLocation,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMoonActor_SetOrbitParameters_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMoonActor_SetOrbitParameters_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AMoonActor, nullptr, "SetOrbitParameters", Z_Construct_UFunction_AMoonActor_SetOrbitParameters_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMoonActor_SetOrbitParameters_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMoonActor_SetOrbitParameters_Statics::MoonActor_eventSetOrbitParameters_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMoonActor_SetOrbitParameters_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMoonActor_SetOrbitParameters_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AMoonActor_SetOrbitParameters_Statics::MoonActor_eventSetOrbitParameters_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMoonActor_SetOrbitParameters()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMoonActor_SetOrbitParameters_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMoonActor::execSetOrbitParameters)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InOrbitRadius);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_InParentLocation);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetOrbitParameters(Z_Param_InOrbitRadius,Z_Param_Out_InParentLocation);
	P_NATIVE_END;
}
// ********** End Class AMoonActor Function SetOrbitParameters *************************************

// ********** Begin Class AMoonActor ***************************************************************
void AMoonActor::StaticRegisterNativesAMoonActor()
{
	UClass* Class = AMoonActor::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ClientOnly_DrawOrbit", &AMoonActor::execClientOnly_DrawOrbit },
		{ "GetMoonId", &AMoonActor::execGetMoonId },
		{ "GetMoonName", &AMoonActor::execGetMoonName },
		{ "GetMoonType", &AMoonActor::execGetMoonType },
		{ "GetOrbitRadius", &AMoonActor::execGetOrbitRadius },
		{ "InitializeMoon", &AMoonActor::execInitializeMoon },
		{ "OnRep_MoonData", &AMoonActor::execOnRep_MoonData },
		{ "SetOrbitParameters", &AMoonActor::execSetOrbitParameters },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_AMoonActor;
UClass* AMoonActor::GetPrivateStaticClass()
{
	using TClass = AMoonActor;
	if (!Z_Registration_Info_UClass_AMoonActor.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("MoonActor"),
			Z_Registration_Info_UClass_AMoonActor.InnerSingleton,
			StaticRegisterNativesAMoonActor,
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
	return Z_Registration_Info_UClass_AMoonActor.InnerSingleton;
}
UClass* Z_Construct_UClass_AMoonActor_NoRegister()
{
	return AMoonActor::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AMoonActor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * AMoonActor\n * \n * Represents a moon/satellite in the Echoes universe\n * Spawned by AEchoesWorldGenerator as children of planets\n * \n * Features:\n * - Server-side spawning with replication\n * - Orbital visualization around parent planet\n * - Seed-based variation for unique appearance\n */" },
#endif
		{ "IncludePath", "Core/Common/Actor/MoonActor.h" },
		{ "ModuleRelativePath", "Core/Common/Actor/MoonActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "AMoonActor\n\nRepresents a moon/satellite in the Echoes universe\nSpawned by AEchoesWorldGenerator as children of planets\n\nFeatures:\n- Server-side spawning with replication\n- Orbital visualization around parent planet\n- Seed-based variation for unique appearance" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoonMeshComponent_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Moon mesh component */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/Actor/MoonActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Moon mesh component" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OrbitSplineComponent_MetaData[] = {
		{ "Category", "Components|Orbit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Orbit spline component (client-only, for visual orbit path) */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/Actor/MoonActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Orbit spline component (client-only, for visual orbit path)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoonId_MetaData[] = {
		{ "Category", "Moon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Unique moon ID from database */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/MoonActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Unique moon ID from database" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoonName_MetaData[] = {
		{ "Category", "Moon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Moon name */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/MoonActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Moon name" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoonType_MetaData[] = {
		{ "Category", "Moon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Moon type (e.g., \"Rocky\", \"Ice\", \"Volcanic\") */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/MoonActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Moon type (e.g., \"Rocky\", \"Ice\", \"Volcanic\")" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OrbitRadius_MetaData[] = {
		{ "Category", "Moon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Orbit radius (distance from parent planet) in km */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/MoonActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Orbit radius (distance from parent planet) in km" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Seed_MetaData[] = {
		{ "Category", "Moon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Seed for procedural variation */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/MoonActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Seed for procedural variation" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ParentLocation_MetaData[] = {
		{ "Category", "Moon|Orbit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Parent planet's world location (for orbit visualization) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/MoonActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Parent planet's world location (for orbit visualization)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MoonMeshComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OrbitSplineComponent;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MoonId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_MoonName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_MoonType;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OrbitRadius;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Seed;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ParentLocation;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AMoonActor_ClientOnly_DrawOrbit, "ClientOnly_DrawOrbit" }, // 4100869485
		{ &Z_Construct_UFunction_AMoonActor_GetMoonId, "GetMoonId" }, // 3939145787
		{ &Z_Construct_UFunction_AMoonActor_GetMoonName, "GetMoonName" }, // 951170997
		{ &Z_Construct_UFunction_AMoonActor_GetMoonType, "GetMoonType" }, // 953890926
		{ &Z_Construct_UFunction_AMoonActor_GetOrbitRadius, "GetOrbitRadius" }, // 483736577
		{ &Z_Construct_UFunction_AMoonActor_InitializeMoon, "InitializeMoon" }, // 3380101653
		{ &Z_Construct_UFunction_AMoonActor_OnRep_MoonData, "OnRep_MoonData" }, // 517017240
		{ &Z_Construct_UFunction_AMoonActor_SetOrbitParameters, "SetOrbitParameters" }, // 1460424661
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMoonActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMoonActor_Statics::NewProp_MoonMeshComponent = { "MoonMeshComponent", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMoonActor, MoonMeshComponent), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoonMeshComponent_MetaData), NewProp_MoonMeshComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMoonActor_Statics::NewProp_OrbitSplineComponent = { "OrbitSplineComponent", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMoonActor, OrbitSplineComponent), Z_Construct_UClass_USplineComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OrbitSplineComponent_MetaData), NewProp_OrbitSplineComponent_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AMoonActor_Statics::NewProp_MoonId = { "MoonId", "OnRep_MoonData", (EPropertyFlags)0x0020080100000034, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMoonActor, MoonId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoonId_MetaData), NewProp_MoonId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AMoonActor_Statics::NewProp_MoonName = { "MoonName", "OnRep_MoonData", (EPropertyFlags)0x0020080100000034, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMoonActor, MoonName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoonName_MetaData), NewProp_MoonName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AMoonActor_Statics::NewProp_MoonType = { "MoonType", "OnRep_MoonData", (EPropertyFlags)0x0020080100000034, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMoonActor, MoonType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoonType_MetaData), NewProp_MoonType_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMoonActor_Statics::NewProp_OrbitRadius = { "OrbitRadius", "OnRep_MoonData", (EPropertyFlags)0x0020080100000034, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMoonActor, OrbitRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OrbitRadius_MetaData), NewProp_OrbitRadius_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AMoonActor_Statics::NewProp_Seed = { "Seed", "OnRep_MoonData", (EPropertyFlags)0x0020080100000034, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMoonActor, Seed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Seed_MetaData), NewProp_Seed_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AMoonActor_Statics::NewProp_ParentLocation = { "ParentLocation", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMoonActor, ParentLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ParentLocation_MetaData), NewProp_ParentLocation_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMoonActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMoonActor_Statics::NewProp_MoonMeshComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMoonActor_Statics::NewProp_OrbitSplineComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMoonActor_Statics::NewProp_MoonId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMoonActor_Statics::NewProp_MoonName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMoonActor_Statics::NewProp_MoonType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMoonActor_Statics::NewProp_OrbitRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMoonActor_Statics::NewProp_Seed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMoonActor_Statics::NewProp_ParentLocation,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMoonActor_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AMoonActor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMoonActor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMoonActor_Statics::ClassParams = {
	&AMoonActor::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AMoonActor_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AMoonActor_Statics::PropPointers),
	0,
	0x009001A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMoonActor_Statics::Class_MetaDataParams), Z_Construct_UClass_AMoonActor_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AMoonActor()
{
	if (!Z_Registration_Info_UClass_AMoonActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMoonActor.OuterSingleton, Z_Construct_UClass_AMoonActor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMoonActor.OuterSingleton;
}
#if VALIDATE_CLASS_REPS
void AMoonActor::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static FName Name_MoonId(TEXT("MoonId"));
	static FName Name_MoonName(TEXT("MoonName"));
	static FName Name_MoonType(TEXT("MoonType"));
	static FName Name_OrbitRadius(TEXT("OrbitRadius"));
	static FName Name_Seed(TEXT("Seed"));
	const bool bIsValid = true
		&& Name_MoonId == ClassReps[(int32)ENetFields_Private::MoonId].Property->GetFName()
		&& Name_MoonName == ClassReps[(int32)ENetFields_Private::MoonName].Property->GetFName()
		&& Name_MoonType == ClassReps[(int32)ENetFields_Private::MoonType].Property->GetFName()
		&& Name_OrbitRadius == ClassReps[(int32)ENetFields_Private::OrbitRadius].Property->GetFName()
		&& Name_Seed == ClassReps[(int32)ENetFields_Private::Seed].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in AMoonActor"));
}
#endif
DEFINE_VTABLE_PTR_HELPER_CTOR(AMoonActor);
AMoonActor::~AMoonActor() {}
// ********** End Class AMoonActor *****************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_MoonActor_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMoonActor, AMoonActor::StaticClass, TEXT("AMoonActor"), &Z_Registration_Info_UClass_AMoonActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMoonActor), 2575404797U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_MoonActor_h__Script_Echoes_3188782866(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_MoonActor_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_MoonActor_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
