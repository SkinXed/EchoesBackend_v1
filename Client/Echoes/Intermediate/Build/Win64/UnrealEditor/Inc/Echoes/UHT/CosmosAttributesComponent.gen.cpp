// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CosmosAttributesComponent.h"
#include "EchoesCoreTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeCosmosAttributesComponent() {}

// ********** Begin Cross Module References ********************************************************
ECHOES_API UClass* Z_Construct_UClass_UCosmosAttributesComponent();
ECHOES_API UClass* Z_Construct_UClass_UCosmosAttributesComponent_NoRegister();
ECHOES_API UEnum* Z_Construct_UEnum_Echoes_ECosmosDamageType();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnAttributesChanged__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnCosmosDeath__DelegateSignature();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FCosmosDefenseLayer();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FOnAttributesChanged **************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnAttributesChanged__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Delegate for attributes changed event - used for UI updates\n * Fires on clients when any replicated attribute changes\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/CosmosAttributesComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Delegate for attributes changed event - used for UI updates\nFires on clients when any replicated attribute changes" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnAttributesChanged__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnAttributesChanged__DelegateSignature", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnAttributesChanged__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnAttributesChanged__DelegateSignature_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UDelegateFunction_Echoes_OnAttributesChanged__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnAttributesChanged__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnAttributesChanged_DelegateWrapper(const FMulticastScriptDelegate& OnAttributesChanged)
{
	OnAttributesChanged.ProcessMulticastDelegate<UObject>(NULL);
}
// ********** End Delegate FOnAttributesChanged ****************************************************

// ********** Begin Delegate FOnCosmosDeath ********************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnCosmosDeath__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnCosmosDeath_Parms
	{
		AActor* Victim;
		AActor* Killer;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Delegate for death event\n * @param Victim - The actor that died (owner of this component)\n * @param Killer - The actor that dealt the killing blow (can be nullptr)\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/CosmosAttributesComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Delegate for death event\n@param Victim - The actor that died (owner of this component)\n@param Killer - The actor that dealt the killing blow (can be nullptr)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Victim;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Killer;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_Echoes_OnCosmosDeath__DelegateSignature_Statics::NewProp_Victim = { "Victim", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnCosmosDeath_Parms, Victim), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_Echoes_OnCosmosDeath__DelegateSignature_Statics::NewProp_Killer = { "Killer", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnCosmosDeath_Parms, Killer), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnCosmosDeath__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnCosmosDeath__DelegateSignature_Statics::NewProp_Victim,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnCosmosDeath__DelegateSignature_Statics::NewProp_Killer,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnCosmosDeath__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnCosmosDeath__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnCosmosDeath__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnCosmosDeath__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnCosmosDeath__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnCosmosDeath__DelegateSignature_Statics::_Script_Echoes_eventOnCosmosDeath_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnCosmosDeath__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnCosmosDeath__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnCosmosDeath__DelegateSignature_Statics::_Script_Echoes_eventOnCosmosDeath_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnCosmosDeath__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnCosmosDeath__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnCosmosDeath_DelegateWrapper(const FMulticastScriptDelegate& OnCosmosDeath, AActor* Victim, AActor* Killer)
{
	struct _Script_Echoes_eventOnCosmosDeath_Parms
	{
		AActor* Victim;
		AActor* Killer;
	};
	_Script_Echoes_eventOnCosmosDeath_Parms Parms;
	Parms.Victim=Victim;
	Parms.Killer=Killer;
	OnCosmosDeath.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnCosmosDeath **********************************************************

// ********** Begin Class UCosmosAttributesComponent Function ClientOnly_OnRep_Stats ***************
struct Z_Construct_UFunction_UCosmosAttributesComponent_ClientOnly_OnRep_Stats_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Called on clients when any defense stat is replicated\n\x09 * Triggers UI update via OnAttributesChanged delegate\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/CosmosAttributesComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called on clients when any defense stat is replicated\nTriggers UI update via OnAttributesChanged delegate" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCosmosAttributesComponent_ClientOnly_OnRep_Stats_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCosmosAttributesComponent, nullptr, "ClientOnly_OnRep_Stats", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCosmosAttributesComponent_ClientOnly_OnRep_Stats_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCosmosAttributesComponent_ClientOnly_OnRep_Stats_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UCosmosAttributesComponent_ClientOnly_OnRep_Stats()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCosmosAttributesComponent_ClientOnly_OnRep_Stats_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCosmosAttributesComponent::execClientOnly_OnRep_Stats)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientOnly_OnRep_Stats();
	P_NATIVE_END;
}
// ********** End Class UCosmosAttributesComponent Function ClientOnly_OnRep_Stats *****************

// ********** Begin Class UCosmosAttributesComponent Function Common_GetArmorPct *******************
struct Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetArmorPct_Statics
{
	struct CosmosAttributesComponent_eventCommon_GetArmorPct_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cosmos" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get armor percentage (Blueprint Pure)\n\x09 * @return Armor percentage from 0.0 to 1.0\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/CosmosAttributesComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get armor percentage (Blueprint Pure)\n@return Armor percentage from 0.0 to 1.0" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetArmorPct_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CosmosAttributesComponent_eventCommon_GetArmorPct_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetArmorPct_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetArmorPct_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetArmorPct_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetArmorPct_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCosmosAttributesComponent, nullptr, "Common_GetArmorPct", Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetArmorPct_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetArmorPct_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetArmorPct_Statics::CosmosAttributesComponent_eventCommon_GetArmorPct_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetArmorPct_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetArmorPct_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetArmorPct_Statics::CosmosAttributesComponent_eventCommon_GetArmorPct_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetArmorPct()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetArmorPct_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCosmosAttributesComponent::execCommon_GetArmorPct)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->Common_GetArmorPct();
	P_NATIVE_END;
}
// ********** End Class UCosmosAttributesComponent Function Common_GetArmorPct *********************

// ********** Begin Class UCosmosAttributesComponent Function Common_GetHullPct ********************
struct Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetHullPct_Statics
{
	struct CosmosAttributesComponent_eventCommon_GetHullPct_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cosmos" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get structure/hull percentage (Blueprint Pure)\n\x09 * @return Structure percentage from 0.0 to 1.0\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/CosmosAttributesComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get structure/hull percentage (Blueprint Pure)\n@return Structure percentage from 0.0 to 1.0" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetHullPct_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CosmosAttributesComponent_eventCommon_GetHullPct_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetHullPct_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetHullPct_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetHullPct_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetHullPct_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCosmosAttributesComponent, nullptr, "Common_GetHullPct", Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetHullPct_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetHullPct_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetHullPct_Statics::CosmosAttributesComponent_eventCommon_GetHullPct_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetHullPct_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetHullPct_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetHullPct_Statics::CosmosAttributesComponent_eventCommon_GetHullPct_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetHullPct()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetHullPct_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCosmosAttributesComponent::execCommon_GetHullPct)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->Common_GetHullPct();
	P_NATIVE_END;
}
// ********** End Class UCosmosAttributesComponent Function Common_GetHullPct **********************

// ********** Begin Class UCosmosAttributesComponent Function Common_GetOverallHealthPct ***********
struct Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetOverallHealthPct_Statics
{
	struct CosmosAttributesComponent_eventCommon_GetOverallHealthPct_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cosmos" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get overall health percentage (all layers combined)\n\x09 * @return Overall health percentage from 0.0 to 1.0\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/CosmosAttributesComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get overall health percentage (all layers combined)\n@return Overall health percentage from 0.0 to 1.0" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetOverallHealthPct_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CosmosAttributesComponent_eventCommon_GetOverallHealthPct_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetOverallHealthPct_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetOverallHealthPct_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetOverallHealthPct_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetOverallHealthPct_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCosmosAttributesComponent, nullptr, "Common_GetOverallHealthPct", Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetOverallHealthPct_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetOverallHealthPct_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetOverallHealthPct_Statics::CosmosAttributesComponent_eventCommon_GetOverallHealthPct_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetOverallHealthPct_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetOverallHealthPct_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetOverallHealthPct_Statics::CosmosAttributesComponent_eventCommon_GetOverallHealthPct_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetOverallHealthPct()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetOverallHealthPct_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCosmosAttributesComponent::execCommon_GetOverallHealthPct)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->Common_GetOverallHealthPct();
	P_NATIVE_END;
}
// ********** End Class UCosmosAttributesComponent Function Common_GetOverallHealthPct *************

// ********** Begin Class UCosmosAttributesComponent Function Common_GetShieldPct ******************
struct Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetShieldPct_Statics
{
	struct CosmosAttributesComponent_eventCommon_GetShieldPct_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cosmos" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get shield percentage (Blueprint Pure)\n\x09 * @return Shield percentage from 0.0 to 1.0\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/CosmosAttributesComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get shield percentage (Blueprint Pure)\n@return Shield percentage from 0.0 to 1.0" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetShieldPct_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CosmosAttributesComponent_eventCommon_GetShieldPct_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetShieldPct_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetShieldPct_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetShieldPct_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetShieldPct_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCosmosAttributesComponent, nullptr, "Common_GetShieldPct", Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetShieldPct_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetShieldPct_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetShieldPct_Statics::CosmosAttributesComponent_eventCommon_GetShieldPct_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetShieldPct_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetShieldPct_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetShieldPct_Statics::CosmosAttributesComponent_eventCommon_GetShieldPct_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetShieldPct()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetShieldPct_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCosmosAttributesComponent::execCommon_GetShieldPct)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->Common_GetShieldPct();
	P_NATIVE_END;
}
// ********** End Class UCosmosAttributesComponent Function Common_GetShieldPct ********************

// ********** Begin Class UCosmosAttributesComponent Function IsAlive ******************************
struct Z_Construct_UFunction_UCosmosAttributesComponent_IsAlive_Statics
{
	struct CosmosAttributesComponent_eventIsAlive_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cosmos" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if the actor is alive\n\x09 * @return True if Structure > 0\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/CosmosAttributesComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if the actor is alive\n@return True if Structure > 0" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UCosmosAttributesComponent_IsAlive_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((CosmosAttributesComponent_eventIsAlive_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCosmosAttributesComponent_IsAlive_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CosmosAttributesComponent_eventIsAlive_Parms), &Z_Construct_UFunction_UCosmosAttributesComponent_IsAlive_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCosmosAttributesComponent_IsAlive_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCosmosAttributesComponent_IsAlive_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCosmosAttributesComponent_IsAlive_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCosmosAttributesComponent_IsAlive_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCosmosAttributesComponent, nullptr, "IsAlive", Z_Construct_UFunction_UCosmosAttributesComponent_IsAlive_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCosmosAttributesComponent_IsAlive_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCosmosAttributesComponent_IsAlive_Statics::CosmosAttributesComponent_eventIsAlive_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCosmosAttributesComponent_IsAlive_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCosmosAttributesComponent_IsAlive_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCosmosAttributesComponent_IsAlive_Statics::CosmosAttributesComponent_eventIsAlive_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCosmosAttributesComponent_IsAlive()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCosmosAttributesComponent_IsAlive_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCosmosAttributesComponent::execIsAlive)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsAlive();
	P_NATIVE_END;
}
// ********** End Class UCosmosAttributesComponent Function IsAlive ********************************

// ********** Begin Class UCosmosAttributesComponent Function ServerOnly_ApplyDamage ***************
struct Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_ApplyDamage_Statics
{
	struct CosmosAttributesComponent_eventServerOnly_ApplyDamage_Parms
	{
		float RawDamage;
		ECosmosDamageType DmgType;
		AActor* Instigator;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cosmos" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Apply damage to this actor with resistance mitigation (Server Only)\n\x09 * Implements EVE-like damage cascade with per-layer resistances\n\x09 * \n\x09 * @param RawDamage - Raw damage amount before mitigation\n\x09 * @param DmgType - Type of damage (EM, Thermal, Kinetic, Explosive, Omni)\n\x09 * @param Instigator - Actor that caused the damage (for kill attribution)\n\x09 * @return True if damage was applied, false if invalid or actor already dead\n\x09 * \n\x09 * Damage Mitigation Process:\n\x09 * 1. Calculate mitigated damage for Shield: RawDamage * (1.0 - Shield.ResistEM/Thermal/etc)\n\x09 * 2. Apply to Shield, calculate overflow\n\x09 * 3. If overflow > 0, calculate mitigated damage for Armor with Armor's resistances\n\x09 * 4. Apply to Armor, calculate overflow\n\x09 * 5. If overflow > 0, calculate mitigated damage for Structure with Structure's resistances\n\x09 * 6. Apply to Structure\n\x09 * 7. If Structure <= 0, trigger OnDeath event\n\x09 * \n\x09 * Example:\n\x09 * - 100 Thermal damage\n\x09 * - Shield: 50 HP, 25% Thermal resist \xe2\x86\x92 Takes 75 damage (100 * 0.75), depleted, 25 overflow\n\x09 * - Armor: 100 HP, 50% Thermal resist \xe2\x86\x92 Takes 12.5 damage (25 * 0.5), 87.5 HP remaining\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/CosmosAttributesComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Apply damage to this actor with resistance mitigation (Server Only)\nImplements EVE-like damage cascade with per-layer resistances\n\n@param RawDamage - Raw damage amount before mitigation\n@param DmgType - Type of damage (EM, Thermal, Kinetic, Explosive, Omni)\n@param Instigator - Actor that caused the damage (for kill attribution)\n@return True if damage was applied, false if invalid or actor already dead\n\nDamage Mitigation Process:\n1. Calculate mitigated damage for Shield: RawDamage * (1.0 - Shield.ResistEM/Thermal/etc)\n2. Apply to Shield, calculate overflow\n3. If overflow > 0, calculate mitigated damage for Armor with Armor's resistances\n4. Apply to Armor, calculate overflow\n5. If overflow > 0, calculate mitigated damage for Structure with Structure's resistances\n6. Apply to Structure\n7. If Structure <= 0, trigger OnDeath event\n\nExample:\n- 100 Thermal damage\n- Shield: 50 HP, 25% Thermal resist \xe2\x86\x92 Takes 75 damage (100 * 0.75), depleted, 25 overflow\n- Armor: 100 HP, 50% Thermal resist \xe2\x86\x92 Takes 12.5 damage (25 * 0.5), 87.5 HP remaining" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RawDamage;
	static const UECodeGen_Private::FBytePropertyParams NewProp_DmgType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_DmgType;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Instigator;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_ApplyDamage_Statics::NewProp_RawDamage = { "RawDamage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CosmosAttributesComponent_eventServerOnly_ApplyDamage_Parms, RawDamage), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_ApplyDamage_Statics::NewProp_DmgType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_ApplyDamage_Statics::NewProp_DmgType = { "DmgType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CosmosAttributesComponent_eventServerOnly_ApplyDamage_Parms, DmgType), Z_Construct_UEnum_Echoes_ECosmosDamageType, METADATA_PARAMS(0, nullptr) }; // 4170051619
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_ApplyDamage_Statics::NewProp_Instigator = { "Instigator", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CosmosAttributesComponent_eventServerOnly_ApplyDamage_Parms, Instigator), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_ApplyDamage_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((CosmosAttributesComponent_eventServerOnly_ApplyDamage_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_ApplyDamage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CosmosAttributesComponent_eventServerOnly_ApplyDamage_Parms), &Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_ApplyDamage_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_ApplyDamage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_ApplyDamage_Statics::NewProp_RawDamage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_ApplyDamage_Statics::NewProp_DmgType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_ApplyDamage_Statics::NewProp_DmgType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_ApplyDamage_Statics::NewProp_Instigator,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_ApplyDamage_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_ApplyDamage_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_ApplyDamage_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCosmosAttributesComponent, nullptr, "ServerOnly_ApplyDamage", Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_ApplyDamage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_ApplyDamage_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_ApplyDamage_Statics::CosmosAttributesComponent_eventServerOnly_ApplyDamage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_ApplyDamage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_ApplyDamage_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_ApplyDamage_Statics::CosmosAttributesComponent_eventServerOnly_ApplyDamage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_ApplyDamage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_ApplyDamage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCosmosAttributesComponent::execServerOnly_ApplyDamage)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_RawDamage);
	P_GET_ENUM(ECosmosDamageType,Z_Param_DmgType);
	P_GET_OBJECT(AActor,Z_Param_Instigator);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ServerOnly_ApplyDamage(Z_Param_RawDamage,ECosmosDamageType(Z_Param_DmgType),Z_Param_Instigator);
	P_NATIVE_END;
}
// ********** End Class UCosmosAttributesComponent Function ServerOnly_ApplyDamage *****************

// ********** Begin Class UCosmosAttributesComponent Function ServerOnly_RestoreAll ****************
struct Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_RestoreAll_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cosmos" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Fully restore all defense layers to maximum (Server Only)\n\x09 * Useful for respawn or repair mechanics\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/CosmosAttributesComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fully restore all defense layers to maximum (Server Only)\nUseful for respawn or repair mechanics" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_RestoreAll_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCosmosAttributesComponent, nullptr, "ServerOnly_RestoreAll", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_RestoreAll_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_RestoreAll_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_RestoreAll()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_RestoreAll_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCosmosAttributesComponent::execServerOnly_RestoreAll)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerOnly_RestoreAll();
	P_NATIVE_END;
}
// ********** End Class UCosmosAttributesComponent Function ServerOnly_RestoreAll ******************

// ********** Begin Class UCosmosAttributesComponent Function ServerOnly_SetLayerResistances *******
struct Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_SetLayerResistances_Statics
{
	struct CosmosAttributesComponent_eventServerOnly_SetLayerResistances_Parms
	{
		int32 LayerIndex;
		float EM;
		float Thermal;
		float Kinetic;
		float Explosive;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cosmos" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Set resistances for a specific layer (Server Only)\n\x09 * Useful for module-based resistance bonuses\n\x09 * \n\x09 * @param LayerIndex - 0=Shield, 1=Armor, 2=Structure\n\x09 * @param EM - EM resistance (0.0 to 1.0)\n\x09 * @param Thermal - Thermal resistance (0.0 to 1.0)\n\x09 * @param Kinetic - Kinetic resistance (0.0 to 1.0)\n\x09 * @param Explosive - Explosive resistance (0.0 to 1.0)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/CosmosAttributesComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set resistances for a specific layer (Server Only)\nUseful for module-based resistance bonuses\n\n@param LayerIndex - 0=Shield, 1=Armor, 2=Structure\n@param EM - EM resistance (0.0 to 1.0)\n@param Thermal - Thermal resistance (0.0 to 1.0)\n@param Kinetic - Kinetic resistance (0.0 to 1.0)\n@param Explosive - Explosive resistance (0.0 to 1.0)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_LayerIndex;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_EM;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Thermal;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Kinetic;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Explosive;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_SetLayerResistances_Statics::NewProp_LayerIndex = { "LayerIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CosmosAttributesComponent_eventServerOnly_SetLayerResistances_Parms, LayerIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_SetLayerResistances_Statics::NewProp_EM = { "EM", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CosmosAttributesComponent_eventServerOnly_SetLayerResistances_Parms, EM), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_SetLayerResistances_Statics::NewProp_Thermal = { "Thermal", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CosmosAttributesComponent_eventServerOnly_SetLayerResistances_Parms, Thermal), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_SetLayerResistances_Statics::NewProp_Kinetic = { "Kinetic", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CosmosAttributesComponent_eventServerOnly_SetLayerResistances_Parms, Kinetic), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_SetLayerResistances_Statics::NewProp_Explosive = { "Explosive", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CosmosAttributesComponent_eventServerOnly_SetLayerResistances_Parms, Explosive), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_SetLayerResistances_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_SetLayerResistances_Statics::NewProp_LayerIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_SetLayerResistances_Statics::NewProp_EM,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_SetLayerResistances_Statics::NewProp_Thermal,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_SetLayerResistances_Statics::NewProp_Kinetic,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_SetLayerResistances_Statics::NewProp_Explosive,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_SetLayerResistances_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_SetLayerResistances_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCosmosAttributesComponent, nullptr, "ServerOnly_SetLayerResistances", Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_SetLayerResistances_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_SetLayerResistances_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_SetLayerResistances_Statics::CosmosAttributesComponent_eventServerOnly_SetLayerResistances_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_SetLayerResistances_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_SetLayerResistances_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_SetLayerResistances_Statics::CosmosAttributesComponent_eventServerOnly_SetLayerResistances_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_SetLayerResistances()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_SetLayerResistances_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCosmosAttributesComponent::execServerOnly_SetLayerResistances)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_LayerIndex);
	P_GET_PROPERTY(FFloatProperty,Z_Param_EM);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Thermal);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Kinetic);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Explosive);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerOnly_SetLayerResistances(Z_Param_LayerIndex,Z_Param_EM,Z_Param_Thermal,Z_Param_Kinetic,Z_Param_Explosive);
	P_NATIVE_END;
}
// ********** End Class UCosmosAttributesComponent Function ServerOnly_SetLayerResistances *********

// ********** Begin Class UCosmosAttributesComponent ***********************************************
void UCosmosAttributesComponent::StaticRegisterNativesUCosmosAttributesComponent()
{
	UClass* Class = UCosmosAttributesComponent::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ClientOnly_OnRep_Stats", &UCosmosAttributesComponent::execClientOnly_OnRep_Stats },
		{ "Common_GetArmorPct", &UCosmosAttributesComponent::execCommon_GetArmorPct },
		{ "Common_GetHullPct", &UCosmosAttributesComponent::execCommon_GetHullPct },
		{ "Common_GetOverallHealthPct", &UCosmosAttributesComponent::execCommon_GetOverallHealthPct },
		{ "Common_GetShieldPct", &UCosmosAttributesComponent::execCommon_GetShieldPct },
		{ "IsAlive", &UCosmosAttributesComponent::execIsAlive },
		{ "ServerOnly_ApplyDamage", &UCosmosAttributesComponent::execServerOnly_ApplyDamage },
		{ "ServerOnly_RestoreAll", &UCosmosAttributesComponent::execServerOnly_RestoreAll },
		{ "ServerOnly_SetLayerResistances", &UCosmosAttributesComponent::execServerOnly_SetLayerResistances },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UCosmosAttributesComponent;
UClass* UCosmosAttributesComponent::GetPrivateStaticClass()
{
	using TClass = UCosmosAttributesComponent;
	if (!Z_Registration_Info_UClass_UCosmosAttributesComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("CosmosAttributesComponent"),
			Z_Registration_Info_UClass_UCosmosAttributesComponent.InnerSingleton,
			StaticRegisterNativesUCosmosAttributesComponent,
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
	return Z_Registration_Info_UClass_UCosmosAttributesComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UCosmosAttributesComponent_NoRegister()
{
	return UCosmosAttributesComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UCosmosAttributesComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Echoes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * UCosmosAttributesComponent\n * \n * Advanced EVE-like ship/structure attributes component with resistance system\n * Implements three-layer defense with per-damage-type resistances\n * \n * Architecture:\n * - ActorComponent: Can be attached to ships, stations, structures\n * - Three defense layers: Shield \xe2\x86\x92 Armor \xe2\x86\x92 Structure (each with 4 resistances)\n * - Replicated: All defense layers and physics stats replicate to clients\n * - Server-authoritative: Damage calculations only on server\n * \n * Defense Layers (EVE-like with Resistances):\n * 1. Shield: First line of defense, can have different resistances per damage type\n * 2. Armor: Second layer, different resistance profile than shield\n * 3. Structure: Final layer (hull), last resistance profile\n * \n * Damage Types (ECosmosDamageType):\n * - EM (Electromagnetic): Typically strong vs shields\n * - Thermal: Heat-based damage\n * - Kinetic: Physical projectiles\n * - Explosive: Explosive ordnance\n * - Omni: Pure damage that bypasses all resistances\n * \n * Damage Flow with Resistances:\n * 1. Apply damage to Shield with Shield's resistances\n * 2. If Shield depleted, apply overflow to Armor with Armor's resistances\n * 3. If Armor depleted, apply overflow to Structure with Structure's resistances\n * 4. If Structure depleted, trigger death event\n * \n * Example:\n * - 100 EM damage vs Shield with 50% EM resist = 50 damage taken\n * - If Shield had 30 HP, 20 overflow damage goes to Armor\n * - 20 EM damage vs Armor with 25% EM resist = 15 damage taken\n * \n * Usage:\n * - Attach to ship pawns for combat with resistances\n * - Configure different resistance profiles for different ship types\n * - Server calls ServerOnly_ApplyDamage() when hit\n * - Clients receive updates via replication and update UI\n */" },
#endif
		{ "IncludePath", "Core/Common/Components/CosmosAttributesComponent.h" },
		{ "ModuleRelativePath", "Core/Common/Components/CosmosAttributesComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UCosmosAttributesComponent\n\nAdvanced EVE-like ship/structure attributes component with resistance system\nImplements three-layer defense with per-damage-type resistances\n\nArchitecture:\n- ActorComponent: Can be attached to ships, stations, structures\n- Three defense layers: Shield \xe2\x86\x92 Armor \xe2\x86\x92 Structure (each with 4 resistances)\n- Replicated: All defense layers and physics stats replicate to clients\n- Server-authoritative: Damage calculations only on server\n\nDefense Layers (EVE-like with Resistances):\n1. Shield: First line of defense, can have different resistances per damage type\n2. Armor: Second layer, different resistance profile than shield\n3. Structure: Final layer (hull), last resistance profile\n\nDamage Types (ECosmosDamageType):\n- EM (Electromagnetic): Typically strong vs shields\n- Thermal: Heat-based damage\n- Kinetic: Physical projectiles\n- Explosive: Explosive ordnance\n- Omni: Pure damage that bypasses all resistances\n\nDamage Flow with Resistances:\n1. Apply damage to Shield with Shield's resistances\n2. If Shield depleted, apply overflow to Armor with Armor's resistances\n3. If Armor depleted, apply overflow to Structure with Structure's resistances\n4. If Structure depleted, trigger death event\n\nExample:\n- 100 EM damage vs Shield with 50% EM resist = 50 damage taken\n- If Shield had 30 HP, 20 overflow damage goes to Armor\n- 20 EM damage vs Armor with 25% EM resist = 15 damage taken\n\nUsage:\n- Attach to ship pawns for combat with resistances\n- Configure different resistance profiles for different ship types\n- Server calls ServerOnly_ApplyDamage() when hit\n- Clients receive updates via replication and update UI" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Shield_MetaData[] = {
		{ "Category", "Cosmos|Defense" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Shield defense layer - first line of defense */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/CosmosAttributesComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shield defense layer - first line of defense" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Armor_MetaData[] = {
		{ "Category", "Cosmos|Defense" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Armor defense layer - second line of defense */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/CosmosAttributesComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Armor defense layer - second line of defense" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Structure_MetaData[] = {
		{ "Category", "Cosmos|Defense" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Structure defense layer - final line of defense (hull) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/CosmosAttributesComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Structure defense layer - final line of defense (hull)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Mass_MetaData[] = {
		{ "Category", "Cosmos|Physics" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Ship/structure mass in kilograms */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/CosmosAttributesComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ship/structure mass in kilograms" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InertiaModifier_MetaData[] = {
		{ "Category", "Cosmos|Physics" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Inertia modifier affecting acceleration/deceleration */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/CosmosAttributesComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Inertia modifier affecting acceleration/deceleration" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CargoCapacity_MetaData[] = {
		{ "Category", "Cosmos|Physics" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Cargo bay capacity in cubic meters */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/CosmosAttributesComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cargo bay capacity in cubic meters" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnAttributesChanged_MetaData[] = {
		{ "Category", "Cosmos|Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \n\x09 * Event broadcast when attributes change - used for UI updates\n\x09 * Fires on clients when replicated values update\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/CosmosAttributesComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Event broadcast when attributes change - used for UI updates\nFires on clients when replicated values update" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnDeath_MetaData[] = {
		{ "Category", "Cosmos|Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Event broadcast when the actor dies (Structure depleted)\n\x09 * Only fires on server, then replicates destruction\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/CosmosAttributesComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Event broadcast when the actor dies (Structure depleted)\nOnly fires on server, then replicates destruction" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LastDamageCauser_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Cached reference to last damage causer for death event */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/CosmosAttributesComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cached reference to last damage causer for death event" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Shield;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Armor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Structure;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Mass;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InertiaModifier;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CargoCapacity;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnAttributesChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnDeath;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LastDamageCauser;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCosmosAttributesComponent_ClientOnly_OnRep_Stats, "ClientOnly_OnRep_Stats" }, // 961601882
		{ &Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetArmorPct, "Common_GetArmorPct" }, // 206278476
		{ &Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetHullPct, "Common_GetHullPct" }, // 1516139877
		{ &Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetOverallHealthPct, "Common_GetOverallHealthPct" }, // 4061087313
		{ &Z_Construct_UFunction_UCosmosAttributesComponent_Common_GetShieldPct, "Common_GetShieldPct" }, // 189293937
		{ &Z_Construct_UFunction_UCosmosAttributesComponent_IsAlive, "IsAlive" }, // 1368361550
		{ &Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_ApplyDamage, "ServerOnly_ApplyDamage" }, // 2777386020
		{ &Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_RestoreAll, "ServerOnly_RestoreAll" }, // 2576745099
		{ &Z_Construct_UFunction_UCosmosAttributesComponent_ServerOnly_SetLayerResistances, "ServerOnly_SetLayerResistances" }, // 2718617461
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCosmosAttributesComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCosmosAttributesComponent_Statics::NewProp_Shield = { "Shield", "ClientOnly_OnRep_Stats", (EPropertyFlags)0x0010000100000025, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCosmosAttributesComponent, Shield), Z_Construct_UScriptStruct_FCosmosDefenseLayer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Shield_MetaData), NewProp_Shield_MetaData) }; // 3062971545
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCosmosAttributesComponent_Statics::NewProp_Armor = { "Armor", "ClientOnly_OnRep_Stats", (EPropertyFlags)0x0010000100000025, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCosmosAttributesComponent, Armor), Z_Construct_UScriptStruct_FCosmosDefenseLayer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Armor_MetaData), NewProp_Armor_MetaData) }; // 3062971545
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCosmosAttributesComponent_Statics::NewProp_Structure = { "Structure", "ClientOnly_OnRep_Stats", (EPropertyFlags)0x0010000100000025, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCosmosAttributesComponent, Structure), Z_Construct_UScriptStruct_FCosmosDefenseLayer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Structure_MetaData), NewProp_Structure_MetaData) }; // 3062971545
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCosmosAttributesComponent_Statics::NewProp_Mass = { "Mass", nullptr, (EPropertyFlags)0x0010000000000025, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCosmosAttributesComponent, Mass), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Mass_MetaData), NewProp_Mass_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCosmosAttributesComponent_Statics::NewProp_InertiaModifier = { "InertiaModifier", nullptr, (EPropertyFlags)0x0010000000000025, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCosmosAttributesComponent, InertiaModifier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InertiaModifier_MetaData), NewProp_InertiaModifier_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCosmosAttributesComponent_Statics::NewProp_CargoCapacity = { "CargoCapacity", nullptr, (EPropertyFlags)0x0010000000000025, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCosmosAttributesComponent, CargoCapacity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CargoCapacity_MetaData), NewProp_CargoCapacity_MetaData) };
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UCosmosAttributesComponent_Statics::NewProp_OnAttributesChanged = { "OnAttributesChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCosmosAttributesComponent, OnAttributesChanged), Z_Construct_UDelegateFunction_Echoes_OnAttributesChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnAttributesChanged_MetaData), NewProp_OnAttributesChanged_MetaData) }; // 970582996
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UCosmosAttributesComponent_Statics::NewProp_OnDeath = { "OnDeath", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCosmosAttributesComponent, OnDeath), Z_Construct_UDelegateFunction_Echoes_OnCosmosDeath__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnDeath_MetaData), NewProp_OnDeath_MetaData) }; // 271276580
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCosmosAttributesComponent_Statics::NewProp_LastDamageCauser = { "LastDamageCauser", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCosmosAttributesComponent, LastDamageCauser), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LastDamageCauser_MetaData), NewProp_LastDamageCauser_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCosmosAttributesComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCosmosAttributesComponent_Statics::NewProp_Shield,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCosmosAttributesComponent_Statics::NewProp_Armor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCosmosAttributesComponent_Statics::NewProp_Structure,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCosmosAttributesComponent_Statics::NewProp_Mass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCosmosAttributesComponent_Statics::NewProp_InertiaModifier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCosmosAttributesComponent_Statics::NewProp_CargoCapacity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCosmosAttributesComponent_Statics::NewProp_OnAttributesChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCosmosAttributesComponent_Statics::NewProp_OnDeath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCosmosAttributesComponent_Statics::NewProp_LastDamageCauser,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCosmosAttributesComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UCosmosAttributesComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCosmosAttributesComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCosmosAttributesComponent_Statics::ClassParams = {
	&UCosmosAttributesComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UCosmosAttributesComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UCosmosAttributesComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCosmosAttributesComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UCosmosAttributesComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCosmosAttributesComponent()
{
	if (!Z_Registration_Info_UClass_UCosmosAttributesComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCosmosAttributesComponent.OuterSingleton, Z_Construct_UClass_UCosmosAttributesComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCosmosAttributesComponent.OuterSingleton;
}
#if VALIDATE_CLASS_REPS
void UCosmosAttributesComponent::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static FName Name_Shield(TEXT("Shield"));
	static FName Name_Armor(TEXT("Armor"));
	static FName Name_Structure(TEXT("Structure"));
	static FName Name_Mass(TEXT("Mass"));
	static FName Name_InertiaModifier(TEXT("InertiaModifier"));
	static FName Name_CargoCapacity(TEXT("CargoCapacity"));
	const bool bIsValid = true
		&& Name_Shield == ClassReps[(int32)ENetFields_Private::Shield].Property->GetFName()
		&& Name_Armor == ClassReps[(int32)ENetFields_Private::Armor].Property->GetFName()
		&& Name_Structure == ClassReps[(int32)ENetFields_Private::Structure].Property->GetFName()
		&& Name_Mass == ClassReps[(int32)ENetFields_Private::Mass].Property->GetFName()
		&& Name_InertiaModifier == ClassReps[(int32)ENetFields_Private::InertiaModifier].Property->GetFName()
		&& Name_CargoCapacity == ClassReps[(int32)ENetFields_Private::CargoCapacity].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in UCosmosAttributesComponent"));
}
#endif
DEFINE_VTABLE_PTR_HELPER_CTOR(UCosmosAttributesComponent);
UCosmosAttributesComponent::~UCosmosAttributesComponent() {}
// ********** End Class UCosmosAttributesComponent *************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_CosmosAttributesComponent_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCosmosAttributesComponent, UCosmosAttributesComponent::StaticClass, TEXT("UCosmosAttributesComponent"), &Z_Registration_Info_UClass_UCosmosAttributesComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCosmosAttributesComponent), 3115894097U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_CosmosAttributesComponent_h__Script_Echoes_2877524220(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_CosmosAttributesComponent_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_CosmosAttributesComponent_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
