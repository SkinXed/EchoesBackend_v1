// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Echoes/Core/Common/WormholeActor.h"
#include "Echoes/Core/Common/EchoesWorldVisualTypes.h"
#include "Engine/HitResult.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeWormholeActor() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
ECHOES_API UClass* Z_Construct_UClass_AWormholeActor();
ECHOES_API UClass* Z_Construct_UClass_AWormholeActor_NoRegister();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FWormholeVisualRow();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UAudioComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
NIAGARA_API UClass* Z_Construct_UClass_UNiagaraComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AWormholeActor Function CanAccommodateShip *******************************
struct Z_Construct_UFunction_AWormholeActor_CanAccommodateShip_Statics
{
	struct WormholeActor_eventCanAccommodateShip_Parms
	{
		float ShipMass;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Wormhole" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if wormhole can accommodate ship of given mass\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/WormholeActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if wormhole can accommodate ship of given mass" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ShipMass;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AWormholeActor_CanAccommodateShip_Statics::NewProp_ShipMass = { "ShipMass", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WormholeActor_eventCanAccommodateShip_Parms, ShipMass), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AWormholeActor_CanAccommodateShip_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((WormholeActor_eventCanAccommodateShip_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AWormholeActor_CanAccommodateShip_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(WormholeActor_eventCanAccommodateShip_Parms), &Z_Construct_UFunction_AWormholeActor_CanAccommodateShip_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AWormholeActor_CanAccommodateShip_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWormholeActor_CanAccommodateShip_Statics::NewProp_ShipMass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWormholeActor_CanAccommodateShip_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AWormholeActor_CanAccommodateShip_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AWormholeActor_CanAccommodateShip_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AWormholeActor, nullptr, "CanAccommodateShip", Z_Construct_UFunction_AWormholeActor_CanAccommodateShip_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AWormholeActor_CanAccommodateShip_Statics::PropPointers), sizeof(Z_Construct_UFunction_AWormholeActor_CanAccommodateShip_Statics::WormholeActor_eventCanAccommodateShip_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AWormholeActor_CanAccommodateShip_Statics::Function_MetaDataParams), Z_Construct_UFunction_AWormholeActor_CanAccommodateShip_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AWormholeActor_CanAccommodateShip_Statics::WormholeActor_eventCanAccommodateShip_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AWormholeActor_CanAccommodateShip()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AWormholeActor_CanAccommodateShip_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AWormholeActor::execCanAccommodateShip)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_ShipMass);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->CanAccommodateShip(Z_Param_ShipMass);
	P_NATIVE_END;
}
// ********** End Class AWormholeActor Function CanAccommodateShip *********************************

// ********** Begin Class AWormholeActor Function GetStabilityPercentage ***************************
struct Z_Construct_UFunction_AWormholeActor_GetStabilityPercentage_Statics
{
	struct WormholeActor_eventGetStabilityPercentage_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Wormhole" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get stability percentage (0.0 to 1.0)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/WormholeActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get stability percentage (0.0 to 1.0)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AWormholeActor_GetStabilityPercentage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WormholeActor_eventGetStabilityPercentage_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AWormholeActor_GetStabilityPercentage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWormholeActor_GetStabilityPercentage_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AWormholeActor_GetStabilityPercentage_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AWormholeActor_GetStabilityPercentage_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AWormholeActor, nullptr, "GetStabilityPercentage", Z_Construct_UFunction_AWormholeActor_GetStabilityPercentage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AWormholeActor_GetStabilityPercentage_Statics::PropPointers), sizeof(Z_Construct_UFunction_AWormholeActor_GetStabilityPercentage_Statics::WormholeActor_eventGetStabilityPercentage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AWormholeActor_GetStabilityPercentage_Statics::Function_MetaDataParams), Z_Construct_UFunction_AWormholeActor_GetStabilityPercentage_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AWormholeActor_GetStabilityPercentage_Statics::WormholeActor_eventGetStabilityPercentage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AWormholeActor_GetStabilityPercentage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AWormholeActor_GetStabilityPercentage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AWormholeActor::execGetStabilityPercentage)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetStabilityPercentage();
	P_NATIVE_END;
}
// ********** End Class AWormholeActor Function GetStabilityPercentage *****************************

// ********** Begin Class AWormholeActor Function GetTargetSystemId ********************************
struct Z_Construct_UFunction_AWormholeActor_GetTargetSystemId_Statics
{
	struct WormholeActor_eventGetTargetSystemId_Parms
	{
		FGuid ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Wormhole" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the target system ID\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/WormholeActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the target system ID" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AWormholeActor_GetTargetSystemId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WormholeActor_eventGetTargetSystemId_Parms, ReturnValue), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AWormholeActor_GetTargetSystemId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWormholeActor_GetTargetSystemId_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AWormholeActor_GetTargetSystemId_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AWormholeActor_GetTargetSystemId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AWormholeActor, nullptr, "GetTargetSystemId", Z_Construct_UFunction_AWormholeActor_GetTargetSystemId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AWormholeActor_GetTargetSystemId_Statics::PropPointers), sizeof(Z_Construct_UFunction_AWormholeActor_GetTargetSystemId_Statics::WormholeActor_eventGetTargetSystemId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AWormholeActor_GetTargetSystemId_Statics::Function_MetaDataParams), Z_Construct_UFunction_AWormholeActor_GetTargetSystemId_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AWormholeActor_GetTargetSystemId_Statics::WormholeActor_eventGetTargetSystemId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AWormholeActor_GetTargetSystemId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AWormholeActor_GetTargetSystemId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AWormholeActor::execGetTargetSystemId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGuid*)Z_Param__Result=P_THIS->GetTargetSystemId();
	P_NATIVE_END;
}
// ********** End Class AWormholeActor Function GetTargetSystemId **********************************

// ********** Begin Class AWormholeActor Function GetWormholeId ************************************
struct Z_Construct_UFunction_AWormholeActor_GetWormholeId_Statics
{
	struct WormholeActor_eventGetWormholeId_Parms
	{
		FGuid ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Wormhole" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the wormhole's unique ID\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/WormholeActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the wormhole's unique ID" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AWormholeActor_GetWormholeId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WormholeActor_eventGetWormholeId_Parms, ReturnValue), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AWormholeActor_GetWormholeId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWormholeActor_GetWormholeId_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AWormholeActor_GetWormholeId_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AWormholeActor_GetWormholeId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AWormholeActor, nullptr, "GetWormholeId", Z_Construct_UFunction_AWormholeActor_GetWormholeId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AWormholeActor_GetWormholeId_Statics::PropPointers), sizeof(Z_Construct_UFunction_AWormholeActor_GetWormholeId_Statics::WormholeActor_eventGetWormholeId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AWormholeActor_GetWormholeId_Statics::Function_MetaDataParams), Z_Construct_UFunction_AWormholeActor_GetWormholeId_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AWormholeActor_GetWormholeId_Statics::WormholeActor_eventGetWormholeId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AWormholeActor_GetWormholeId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AWormholeActor_GetWormholeId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AWormholeActor::execGetWormholeId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGuid*)Z_Param__Result=P_THIS->GetWormholeId();
	P_NATIVE_END;
}
// ********** End Class AWormholeActor Function GetWormholeId **************************************

// ********** Begin Class AWormholeActor Function GetWormholeName **********************************
struct Z_Construct_UFunction_AWormholeActor_GetWormholeName_Statics
{
	struct WormholeActor_eventGetWormholeName_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Wormhole" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the wormhole's name\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/WormholeActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the wormhole's name" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AWormholeActor_GetWormholeName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WormholeActor_eventGetWormholeName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AWormholeActor_GetWormholeName_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWormholeActor_GetWormholeName_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AWormholeActor_GetWormholeName_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AWormholeActor_GetWormholeName_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AWormholeActor, nullptr, "GetWormholeName", Z_Construct_UFunction_AWormholeActor_GetWormholeName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AWormholeActor_GetWormholeName_Statics::PropPointers), sizeof(Z_Construct_UFunction_AWormholeActor_GetWormholeName_Statics::WormholeActor_eventGetWormholeName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AWormholeActor_GetWormholeName_Statics::Function_MetaDataParams), Z_Construct_UFunction_AWormholeActor_GetWormholeName_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AWormholeActor_GetWormholeName_Statics::WormholeActor_eventGetWormholeName_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AWormholeActor_GetWormholeName()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AWormholeActor_GetWormholeName_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AWormholeActor::execGetWormholeName)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GetWormholeName();
	P_NATIVE_END;
}
// ********** End Class AWormholeActor Function GetWormholeName ************************************

// ********** Begin Class AWormholeActor Function InitializeWormhole *******************************
struct Z_Construct_UFunction_AWormholeActor_InitializeWormhole_Statics
{
	struct WormholeActor_eventInitializeWormhole_Parms
	{
		FGuid WormholeId;
		FString WormholeName;
		FGuid TargetSystemId;
		int32 Seed;
		FWormholeVisualRow VisualData;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Wormhole" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Initialize wormhole from server configuration\n\x09 * \n\x09 * @param WormholeId - Unique identifier of the wormhole\n\x09 * @param WormholeName - Name of the wormhole\n\x09 * @param TargetSystemId - Destination solar system ID\n\x09 * @param Seed - Procedural generation seed\n\x09 * @param VisualData - Visual configuration from data table\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/WormholeActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Initialize wormhole from server configuration\n\n@param WormholeId - Unique identifier of the wormhole\n@param WormholeName - Name of the wormhole\n@param TargetSystemId - Destination solar system ID\n@param Seed - Procedural generation seed\n@param VisualData - Visual configuration from data table" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WormholeId_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WormholeName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetSystemId_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VisualData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_WormholeId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_WormholeName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetSystemId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Seed;
	static const UECodeGen_Private::FStructPropertyParams NewProp_VisualData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AWormholeActor_InitializeWormhole_Statics::NewProp_WormholeId = { "WormholeId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WormholeActor_eventInitializeWormhole_Parms, WormholeId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WormholeId_MetaData), NewProp_WormholeId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AWormholeActor_InitializeWormhole_Statics::NewProp_WormholeName = { "WormholeName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WormholeActor_eventInitializeWormhole_Parms, WormholeName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WormholeName_MetaData), NewProp_WormholeName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AWormholeActor_InitializeWormhole_Statics::NewProp_TargetSystemId = { "TargetSystemId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WormholeActor_eventInitializeWormhole_Parms, TargetSystemId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetSystemId_MetaData), NewProp_TargetSystemId_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AWormholeActor_InitializeWormhole_Statics::NewProp_Seed = { "Seed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WormholeActor_eventInitializeWormhole_Parms, Seed), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AWormholeActor_InitializeWormhole_Statics::NewProp_VisualData = { "VisualData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WormholeActor_eventInitializeWormhole_Parms, VisualData), Z_Construct_UScriptStruct_FWormholeVisualRow, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VisualData_MetaData), NewProp_VisualData_MetaData) }; // 949240393
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AWormholeActor_InitializeWormhole_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWormholeActor_InitializeWormhole_Statics::NewProp_WormholeId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWormholeActor_InitializeWormhole_Statics::NewProp_WormholeName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWormholeActor_InitializeWormhole_Statics::NewProp_TargetSystemId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWormholeActor_InitializeWormhole_Statics::NewProp_Seed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWormholeActor_InitializeWormhole_Statics::NewProp_VisualData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AWormholeActor_InitializeWormhole_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AWormholeActor_InitializeWormhole_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AWormholeActor, nullptr, "InitializeWormhole", Z_Construct_UFunction_AWormholeActor_InitializeWormhole_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AWormholeActor_InitializeWormhole_Statics::PropPointers), sizeof(Z_Construct_UFunction_AWormholeActor_InitializeWormhole_Statics::WormholeActor_eventInitializeWormhole_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AWormholeActor_InitializeWormhole_Statics::Function_MetaDataParams), Z_Construct_UFunction_AWormholeActor_InitializeWormhole_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AWormholeActor_InitializeWormhole_Statics::WormholeActor_eventInitializeWormhole_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AWormholeActor_InitializeWormhole()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AWormholeActor_InitializeWormhole_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AWormholeActor::execInitializeWormhole)
{
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_WormholeId);
	P_GET_PROPERTY(FStrProperty,Z_Param_WormholeName);
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_TargetSystemId);
	P_GET_PROPERTY(FIntProperty,Z_Param_Seed);
	P_GET_STRUCT_REF(FWormholeVisualRow,Z_Param_Out_VisualData);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializeWormhole(Z_Param_Out_WormholeId,Z_Param_WormholeName,Z_Param_Out_TargetSystemId,Z_Param_Seed,Z_Param_Out_VisualData);
	P_NATIVE_END;
}
// ********** End Class AWormholeActor Function InitializeWormhole *********************************

// ********** Begin Class AWormholeActor Function InitiateJump *************************************
struct Z_Construct_UFunction_AWormholeActor_InitiateJump_Statics
{
	struct WormholeActor_eventInitiateJump_Parms
	{
		AActor* Ship;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintAuthorityOnly", "" },
		{ "Category", "Wormhole" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Initiate jump sequence for a ship\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/WormholeActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Initiate jump sequence for a ship" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Ship;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AWormholeActor_InitiateJump_Statics::NewProp_Ship = { "Ship", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WormholeActor_eventInitiateJump_Parms, Ship), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AWormholeActor_InitiateJump_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWormholeActor_InitiateJump_Statics::NewProp_Ship,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AWormholeActor_InitiateJump_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AWormholeActor_InitiateJump_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AWormholeActor, nullptr, "InitiateJump", Z_Construct_UFunction_AWormholeActor_InitiateJump_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AWormholeActor_InitiateJump_Statics::PropPointers), sizeof(Z_Construct_UFunction_AWormholeActor_InitiateJump_Statics::WormholeActor_eventInitiateJump_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AWormholeActor_InitiateJump_Statics::Function_MetaDataParams), Z_Construct_UFunction_AWormholeActor_InitiateJump_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AWormholeActor_InitiateJump_Statics::WormholeActor_eventInitiateJump_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AWormholeActor_InitiateJump()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AWormholeActor_InitiateJump_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AWormholeActor::execInitiateJump)
{
	P_GET_OBJECT(AActor,Z_Param_Ship);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitiateJump(Z_Param_Ship);
	P_NATIVE_END;
}
// ********** End Class AWormholeActor Function InitiateJump ***************************************

// ********** Begin Class AWormholeActor Function OnTriggerBeginOverlap ****************************
struct Z_Construct_UFunction_AWormholeActor_OnTriggerBeginOverlap_Statics
{
	struct WormholeActor_eventOnTriggerBeginOverlap_Parms
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
		{ "Comment", "/**\n\x09 * Called when a ship enters the wormhole trigger zone\n\x09 * Server will initiate jump to target system\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/WormholeActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when a ship enters the wormhole trigger zone\nServer will initiate jump to target system" },
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
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AWormholeActor_OnTriggerBeginOverlap_Statics::NewProp_OverlappedComponent = { "OverlappedComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WormholeActor_eventOnTriggerBeginOverlap_Parms, OverlappedComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OverlappedComponent_MetaData), NewProp_OverlappedComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AWormholeActor_OnTriggerBeginOverlap_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WormholeActor_eventOnTriggerBeginOverlap_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AWormholeActor_OnTriggerBeginOverlap_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WormholeActor_eventOnTriggerBeginOverlap_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OtherComp_MetaData), NewProp_OtherComp_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AWormholeActor_OnTriggerBeginOverlap_Statics::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WormholeActor_eventOnTriggerBeginOverlap_Parms, OtherBodyIndex), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AWormholeActor_OnTriggerBeginOverlap_Statics::NewProp_bFromSweep_SetBit(void* Obj)
{
	((WormholeActor_eventOnTriggerBeginOverlap_Parms*)Obj)->bFromSweep = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AWormholeActor_OnTriggerBeginOverlap_Statics::NewProp_bFromSweep = { "bFromSweep", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(WormholeActor_eventOnTriggerBeginOverlap_Parms), &Z_Construct_UFunction_AWormholeActor_OnTriggerBeginOverlap_Statics::NewProp_bFromSweep_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AWormholeActor_OnTriggerBeginOverlap_Statics::NewProp_SweepResult = { "SweepResult", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WormholeActor_eventOnTriggerBeginOverlap_Parms, SweepResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SweepResult_MetaData), NewProp_SweepResult_MetaData) }; // 267591329
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AWormholeActor_OnTriggerBeginOverlap_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWormholeActor_OnTriggerBeginOverlap_Statics::NewProp_OverlappedComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWormholeActor_OnTriggerBeginOverlap_Statics::NewProp_OtherActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWormholeActor_OnTriggerBeginOverlap_Statics::NewProp_OtherComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWormholeActor_OnTriggerBeginOverlap_Statics::NewProp_OtherBodyIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWormholeActor_OnTriggerBeginOverlap_Statics::NewProp_bFromSweep,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWormholeActor_OnTriggerBeginOverlap_Statics::NewProp_SweepResult,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AWormholeActor_OnTriggerBeginOverlap_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AWormholeActor_OnTriggerBeginOverlap_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AWormholeActor, nullptr, "OnTriggerBeginOverlap", Z_Construct_UFunction_AWormholeActor_OnTriggerBeginOverlap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AWormholeActor_OnTriggerBeginOverlap_Statics::PropPointers), sizeof(Z_Construct_UFunction_AWormholeActor_OnTriggerBeginOverlap_Statics::WormholeActor_eventOnTriggerBeginOverlap_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AWormholeActor_OnTriggerBeginOverlap_Statics::Function_MetaDataParams), Z_Construct_UFunction_AWormholeActor_OnTriggerBeginOverlap_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AWormholeActor_OnTriggerBeginOverlap_Statics::WormholeActor_eventOnTriggerBeginOverlap_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AWormholeActor_OnTriggerBeginOverlap()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AWormholeActor_OnTriggerBeginOverlap_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AWormholeActor::execOnTriggerBeginOverlap)
{
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent);
	P_GET_OBJECT(AActor,Z_Param_OtherActor);
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp);
	P_GET_PROPERTY(FIntProperty,Z_Param_OtherBodyIndex);
	P_GET_UBOOL(Z_Param_bFromSweep);
	P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnTriggerBeginOverlap(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult);
	P_NATIVE_END;
}
// ********** End Class AWormholeActor Function OnTriggerBeginOverlap ******************************

// ********** Begin Class AWormholeActor Function ProcessShipPassage *******************************
struct Z_Construct_UFunction_AWormholeActor_ProcessShipPassage_Statics
{
	struct WormholeActor_eventProcessShipPassage_Parms
	{
		AActor* Ship;
		float ShipMass;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Wormhole" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Process ship passing through wormhole\n\x09 * Reduces remaining mass and lifetime\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/WormholeActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Process ship passing through wormhole\nReduces remaining mass and lifetime" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Ship;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ShipMass;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AWormholeActor_ProcessShipPassage_Statics::NewProp_Ship = { "Ship", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WormholeActor_eventProcessShipPassage_Parms, Ship), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AWormholeActor_ProcessShipPassage_Statics::NewProp_ShipMass = { "ShipMass", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WormholeActor_eventProcessShipPassage_Parms, ShipMass), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AWormholeActor_ProcessShipPassage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWormholeActor_ProcessShipPassage_Statics::NewProp_Ship,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWormholeActor_ProcessShipPassage_Statics::NewProp_ShipMass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AWormholeActor_ProcessShipPassage_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AWormholeActor_ProcessShipPassage_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AWormholeActor, nullptr, "ProcessShipPassage", Z_Construct_UFunction_AWormholeActor_ProcessShipPassage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AWormholeActor_ProcessShipPassage_Statics::PropPointers), sizeof(Z_Construct_UFunction_AWormholeActor_ProcessShipPassage_Statics::WormholeActor_eventProcessShipPassage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AWormholeActor_ProcessShipPassage_Statics::Function_MetaDataParams), Z_Construct_UFunction_AWormholeActor_ProcessShipPassage_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AWormholeActor_ProcessShipPassage_Statics::WormholeActor_eventProcessShipPassage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AWormholeActor_ProcessShipPassage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AWormholeActor_ProcessShipPassage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AWormholeActor::execProcessShipPassage)
{
	P_GET_OBJECT(AActor,Z_Param_Ship);
	P_GET_PROPERTY(FFloatProperty,Z_Param_ShipMass);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ProcessShipPassage(Z_Param_Ship,Z_Param_ShipMass);
	P_NATIVE_END;
}
// ********** End Class AWormholeActor Function ProcessShipPassage *********************************

// ********** Begin Class AWormholeActor Function TriggerCollapse **********************************
struct Z_Construct_UFunction_AWormholeActor_TriggerCollapse_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintAuthorityOnly", "" },
		{ "Category", "Wormhole" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Trigger wormhole collapse\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/WormholeActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Trigger wormhole collapse" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AWormholeActor_TriggerCollapse_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AWormholeActor, nullptr, "TriggerCollapse", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AWormholeActor_TriggerCollapse_Statics::Function_MetaDataParams), Z_Construct_UFunction_AWormholeActor_TriggerCollapse_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AWormholeActor_TriggerCollapse()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AWormholeActor_TriggerCollapse_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AWormholeActor::execTriggerCollapse)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->TriggerCollapse();
	P_NATIVE_END;
}
// ********** End Class AWormholeActor Function TriggerCollapse ************************************

// ********** Begin Class AWormholeActor ***********************************************************
void AWormholeActor::StaticRegisterNativesAWormholeActor()
{
	UClass* Class = AWormholeActor::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "CanAccommodateShip", &AWormholeActor::execCanAccommodateShip },
		{ "GetStabilityPercentage", &AWormholeActor::execGetStabilityPercentage },
		{ "GetTargetSystemId", &AWormholeActor::execGetTargetSystemId },
		{ "GetWormholeId", &AWormholeActor::execGetWormholeId },
		{ "GetWormholeName", &AWormholeActor::execGetWormholeName },
		{ "InitializeWormhole", &AWormholeActor::execInitializeWormhole },
		{ "InitiateJump", &AWormholeActor::execInitiateJump },
		{ "OnTriggerBeginOverlap", &AWormholeActor::execOnTriggerBeginOverlap },
		{ "ProcessShipPassage", &AWormholeActor::execProcessShipPassage },
		{ "TriggerCollapse", &AWormholeActor::execTriggerCollapse },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_AWormholeActor;
UClass* AWormholeActor::GetPrivateStaticClass()
{
	using TClass = AWormholeActor;
	if (!Z_Registration_Info_UClass_AWormholeActor.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("WormholeActor"),
			Z_Registration_Info_UClass_AWormholeActor.InnerSingleton,
			StaticRegisterNativesAWormholeActor,
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
	return Z_Registration_Info_UClass_AWormholeActor.InnerSingleton;
}
UClass* Z_Construct_UClass_AWormholeActor_NoRegister()
{
	return AWormholeActor::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AWormholeActor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * AWormholeActor\n * \n * Represents a wormhole connection between solar systems\n * Features spatial distortion effects and jump trigger zones\n * Color and effects vary based on destination system\n * \n * Key Features:\n * - Unique visual appearance based on TargetSystemId\n * - Trigger zone for initiating jumps to target system\n * - Spatial distortion post-process effects\n * - Entry/exit sound effects\n * - Stability indicators (VFX intensity)\n */" },
#endif
		{ "IncludePath", "Core/Common/WormholeActor.h" },
		{ "ModuleRelativePath", "Core/Common/WormholeActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "AWormholeActor\n\nRepresents a wormhole connection between solar systems\nFeatures spatial distortion effects and jump trigger zones\nColor and effects vary based on destination system\n\nKey Features:\n- Unique visual appearance based on TargetSystemId\n- Trigger zone for initiating jumps to target system\n- Spatial distortion post-process effects\n- Entry/exit sound effects\n- Stability indicators (VFX intensity)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RootSceneComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Root scene component */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/WormholeActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Root scene component" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EntranceMeshComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Entrance structure mesh (optional) */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/WormholeActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Entrance structure mesh (optional)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WormholeVFXComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Main wormhole VFX (event horizon) */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/WormholeActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Main wormhole VFX (event horizon)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InstabilityVFXComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Instability VFX (for unstable wormholes) */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/WormholeActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Instability VFX (for unstable wormholes)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AmbientAudioComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Ambient audio component */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/WormholeActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ambient audio component" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EntranceSoundComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Entrance sound component */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/WormholeActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Entrance sound component" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TriggerSphere_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Trigger sphere for jump detection */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/WormholeActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Trigger sphere for jump detection" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WormholeId_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Wormhole" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Unique ID of this wormhole */" },
#endif
		{ "ModuleRelativePath", "Core/Common/WormholeActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Unique ID of this wormhole" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WormholeName_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Wormhole" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Name of the wormhole */" },
#endif
		{ "ModuleRelativePath", "Core/Common/WormholeActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Name of the wormhole" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetSystemId_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Wormhole" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Target system ID (where this wormhole leads) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/WormholeActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Target system ID (where this wormhole leads)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GenerationSeed_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Wormhole" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Procedural generation seed */" },
#endif
		{ "ModuleRelativePath", "Core/Common/WormholeActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Procedural generation seed" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WormholeColor_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Wormhole" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Unique color for this wormhole */" },
#endif
		{ "ModuleRelativePath", "Core/Common/WormholeActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Unique color for this wormhole" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MassCapacity_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Wormhole|Instability" },
		{ "ClampMin", "1.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum mass capacity (in metric tons) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/WormholeActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum mass capacity (in metric tons)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentMassUsed_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Wormhole|Instability" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current mass that has passed through */" },
#endif
		{ "ModuleRelativePath", "Core/Common/WormholeActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current mass that has passed through" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RemainingLifetime_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Wormhole|Instability" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Remaining lifetime in seconds */" },
#endif
		{ "ModuleRelativePath", "Core/Common/WormholeActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Remaining lifetime in seconds" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InitialLifetime_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Wormhole|Instability" },
		{ "ClampMin", "1.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Initial lifetime when wormhole was created */" },
#endif
		{ "ModuleRelativePath", "Core/Common/WormholeActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Initial lifetime when wormhole was created" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsCollapsing_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Wormhole|Instability" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether wormhole is collapsing */" },
#endif
		{ "ModuleRelativePath", "Core/Common/WormholeActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether wormhole is collapsing" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RootSceneComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EntranceMeshComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WormholeVFXComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InstabilityVFXComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AmbientAudioComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EntranceSoundComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TriggerSphere;
	static const UECodeGen_Private::FStructPropertyParams NewProp_WormholeId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_WormholeName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetSystemId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_GenerationSeed;
	static const UECodeGen_Private::FStructPropertyParams NewProp_WormholeColor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MassCapacity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentMassUsed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RemainingLifetime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InitialLifetime;
	static void NewProp_bIsCollapsing_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsCollapsing;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AWormholeActor_CanAccommodateShip, "CanAccommodateShip" }, // 538234996
		{ &Z_Construct_UFunction_AWormholeActor_GetStabilityPercentage, "GetStabilityPercentage" }, // 3585443758
		{ &Z_Construct_UFunction_AWormholeActor_GetTargetSystemId, "GetTargetSystemId" }, // 3731896944
		{ &Z_Construct_UFunction_AWormholeActor_GetWormholeId, "GetWormholeId" }, // 1635689240
		{ &Z_Construct_UFunction_AWormholeActor_GetWormholeName, "GetWormholeName" }, // 2746880348
		{ &Z_Construct_UFunction_AWormholeActor_InitializeWormhole, "InitializeWormhole" }, // 4246918955
		{ &Z_Construct_UFunction_AWormholeActor_InitiateJump, "InitiateJump" }, // 1104662810
		{ &Z_Construct_UFunction_AWormholeActor_OnTriggerBeginOverlap, "OnTriggerBeginOverlap" }, // 1473668778
		{ &Z_Construct_UFunction_AWormholeActor_ProcessShipPassage, "ProcessShipPassage" }, // 3370129835
		{ &Z_Construct_UFunction_AWormholeActor_TriggerCollapse, "TriggerCollapse" }, // 2497143244
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AWormholeActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWormholeActor_Statics::NewProp_RootSceneComponent = { "RootSceneComponent", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWormholeActor, RootSceneComponent), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RootSceneComponent_MetaData), NewProp_RootSceneComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWormholeActor_Statics::NewProp_EntranceMeshComponent = { "EntranceMeshComponent", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWormholeActor, EntranceMeshComponent), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EntranceMeshComponent_MetaData), NewProp_EntranceMeshComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWormholeActor_Statics::NewProp_WormholeVFXComponent = { "WormholeVFXComponent", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWormholeActor, WormholeVFXComponent), Z_Construct_UClass_UNiagaraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WormholeVFXComponent_MetaData), NewProp_WormholeVFXComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWormholeActor_Statics::NewProp_InstabilityVFXComponent = { "InstabilityVFXComponent", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWormholeActor, InstabilityVFXComponent), Z_Construct_UClass_UNiagaraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InstabilityVFXComponent_MetaData), NewProp_InstabilityVFXComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWormholeActor_Statics::NewProp_AmbientAudioComponent = { "AmbientAudioComponent", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWormholeActor, AmbientAudioComponent), Z_Construct_UClass_UAudioComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AmbientAudioComponent_MetaData), NewProp_AmbientAudioComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWormholeActor_Statics::NewProp_EntranceSoundComponent = { "EntranceSoundComponent", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWormholeActor, EntranceSoundComponent), Z_Construct_UClass_UAudioComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EntranceSoundComponent_MetaData), NewProp_EntranceSoundComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWormholeActor_Statics::NewProp_TriggerSphere = { "TriggerSphere", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWormholeActor, TriggerSphere), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TriggerSphere_MetaData), NewProp_TriggerSphere_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AWormholeActor_Statics::NewProp_WormholeId = { "WormholeId", nullptr, (EPropertyFlags)0x0040000000020035, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWormholeActor, WormholeId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WormholeId_MetaData), NewProp_WormholeId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AWormholeActor_Statics::NewProp_WormholeName = { "WormholeName", nullptr, (EPropertyFlags)0x0040000000020035, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWormholeActor, WormholeName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WormholeName_MetaData), NewProp_WormholeName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AWormholeActor_Statics::NewProp_TargetSystemId = { "TargetSystemId", nullptr, (EPropertyFlags)0x0040000000020035, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWormholeActor, TargetSystemId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetSystemId_MetaData), NewProp_TargetSystemId_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AWormholeActor_Statics::NewProp_GenerationSeed = { "GenerationSeed", nullptr, (EPropertyFlags)0x0040000000020015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWormholeActor, GenerationSeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GenerationSeed_MetaData), NewProp_GenerationSeed_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AWormholeActor_Statics::NewProp_WormholeColor = { "WormholeColor", nullptr, (EPropertyFlags)0x0040000000020015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWormholeActor, WormholeColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WormholeColor_MetaData), NewProp_WormholeColor_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AWormholeActor_Statics::NewProp_MassCapacity = { "MassCapacity", nullptr, (EPropertyFlags)0x0040000000000025, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWormholeActor, MassCapacity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MassCapacity_MetaData), NewProp_MassCapacity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AWormholeActor_Statics::NewProp_CurrentMassUsed = { "CurrentMassUsed", nullptr, (EPropertyFlags)0x0040000000020035, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWormholeActor, CurrentMassUsed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentMassUsed_MetaData), NewProp_CurrentMassUsed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AWormholeActor_Statics::NewProp_RemainingLifetime = { "RemainingLifetime", nullptr, (EPropertyFlags)0x0040000000020035, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWormholeActor, RemainingLifetime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RemainingLifetime_MetaData), NewProp_RemainingLifetime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AWormholeActor_Statics::NewProp_InitialLifetime = { "InitialLifetime", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWormholeActor, InitialLifetime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InitialLifetime_MetaData), NewProp_InitialLifetime_MetaData) };
void Z_Construct_UClass_AWormholeActor_Statics::NewProp_bIsCollapsing_SetBit(void* Obj)
{
	((AWormholeActor*)Obj)->bIsCollapsing = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AWormholeActor_Statics::NewProp_bIsCollapsing = { "bIsCollapsing", nullptr, (EPropertyFlags)0x0040000000020035, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AWormholeActor), &Z_Construct_UClass_AWormholeActor_Statics::NewProp_bIsCollapsing_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsCollapsing_MetaData), NewProp_bIsCollapsing_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AWormholeActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWormholeActor_Statics::NewProp_RootSceneComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWormholeActor_Statics::NewProp_EntranceMeshComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWormholeActor_Statics::NewProp_WormholeVFXComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWormholeActor_Statics::NewProp_InstabilityVFXComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWormholeActor_Statics::NewProp_AmbientAudioComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWormholeActor_Statics::NewProp_EntranceSoundComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWormholeActor_Statics::NewProp_TriggerSphere,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWormholeActor_Statics::NewProp_WormholeId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWormholeActor_Statics::NewProp_WormholeName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWormholeActor_Statics::NewProp_TargetSystemId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWormholeActor_Statics::NewProp_GenerationSeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWormholeActor_Statics::NewProp_WormholeColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWormholeActor_Statics::NewProp_MassCapacity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWormholeActor_Statics::NewProp_CurrentMassUsed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWormholeActor_Statics::NewProp_RemainingLifetime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWormholeActor_Statics::NewProp_InitialLifetime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWormholeActor_Statics::NewProp_bIsCollapsing,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AWormholeActor_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AWormholeActor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AWormholeActor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AWormholeActor_Statics::ClassParams = {
	&AWormholeActor::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AWormholeActor_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AWormholeActor_Statics::PropPointers),
	0,
	0x009001A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AWormholeActor_Statics::Class_MetaDataParams), Z_Construct_UClass_AWormholeActor_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AWormholeActor()
{
	if (!Z_Registration_Info_UClass_AWormholeActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AWormholeActor.OuterSingleton, Z_Construct_UClass_AWormholeActor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AWormholeActor.OuterSingleton;
}
#if VALIDATE_CLASS_REPS
void AWormholeActor::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static FName Name_WormholeId(TEXT("WormholeId"));
	static FName Name_WormholeName(TEXT("WormholeName"));
	static FName Name_TargetSystemId(TEXT("TargetSystemId"));
	static FName Name_MassCapacity(TEXT("MassCapacity"));
	static FName Name_CurrentMassUsed(TEXT("CurrentMassUsed"));
	static FName Name_RemainingLifetime(TEXT("RemainingLifetime"));
	static FName Name_bIsCollapsing(TEXT("bIsCollapsing"));
	const bool bIsValid = true
		&& Name_WormholeId == ClassReps[(int32)ENetFields_Private::WormholeId].Property->GetFName()
		&& Name_WormholeName == ClassReps[(int32)ENetFields_Private::WormholeName].Property->GetFName()
		&& Name_TargetSystemId == ClassReps[(int32)ENetFields_Private::TargetSystemId].Property->GetFName()
		&& Name_MassCapacity == ClassReps[(int32)ENetFields_Private::MassCapacity].Property->GetFName()
		&& Name_CurrentMassUsed == ClassReps[(int32)ENetFields_Private::CurrentMassUsed].Property->GetFName()
		&& Name_RemainingLifetime == ClassReps[(int32)ENetFields_Private::RemainingLifetime].Property->GetFName()
		&& Name_bIsCollapsing == ClassReps[(int32)ENetFields_Private::bIsCollapsing].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in AWormholeActor"));
}
#endif
DEFINE_VTABLE_PTR_HELPER_CTOR(AWormholeActor);
AWormholeActor::~AWormholeActor() {}
// ********** End Class AWormholeActor *************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_WormholeActor_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AWormholeActor, AWormholeActor::StaticClass, TEXT("AWormholeActor"), &Z_Registration_Info_UClass_AWormholeActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AWormholeActor), 1309416509U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_WormholeActor_h__Script_Echoes_732306454(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_WormholeActor_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_WormholeActor_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
