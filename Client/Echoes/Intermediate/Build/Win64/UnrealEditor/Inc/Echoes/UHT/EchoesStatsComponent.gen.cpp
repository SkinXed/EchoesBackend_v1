// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EchoesStatsComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesStatsComponent() {}

// ********** Begin Cross Module References ********************************************************
ECHOES_API UClass* Z_Construct_UClass_UEchoesStatsComponent();
ECHOES_API UClass* Z_Construct_UClass_UEchoesStatsComponent_NoRegister();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnDeath__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnStatsChanged__DelegateSignature();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FOnStatsChanged *******************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnStatsChanged__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnStatsChanged_Parms
	{
		float ShieldPct;
		float ArmorPct;
		float StructPct;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Delegate for stats changed event - used for UI updates\n * @param ShieldPct - Shield percentage (0.0 to 1.0)\n * @param ArmorPct - Armor percentage (0.0 to 1.0)\n * @param StructPct - Structure percentage (0.0 to 1.0)\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/EchoesStatsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Delegate for stats changed event - used for UI updates\n@param ShieldPct - Shield percentage (0.0 to 1.0)\n@param ArmorPct - Armor percentage (0.0 to 1.0)\n@param StructPct - Structure percentage (0.0 to 1.0)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ShieldPct;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ArmorPct;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_StructPct;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_Echoes_OnStatsChanged__DelegateSignature_Statics::NewProp_ShieldPct = { "ShieldPct", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnStatsChanged_Parms, ShieldPct), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_Echoes_OnStatsChanged__DelegateSignature_Statics::NewProp_ArmorPct = { "ArmorPct", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnStatsChanged_Parms, ArmorPct), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_Echoes_OnStatsChanged__DelegateSignature_Statics::NewProp_StructPct = { "StructPct", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnStatsChanged_Parms, StructPct), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnStatsChanged__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnStatsChanged__DelegateSignature_Statics::NewProp_ShieldPct,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnStatsChanged__DelegateSignature_Statics::NewProp_ArmorPct,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnStatsChanged__DelegateSignature_Statics::NewProp_StructPct,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnStatsChanged__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnStatsChanged__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnStatsChanged__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnStatsChanged__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnStatsChanged__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnStatsChanged__DelegateSignature_Statics::_Script_Echoes_eventOnStatsChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnStatsChanged__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnStatsChanged__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnStatsChanged__DelegateSignature_Statics::_Script_Echoes_eventOnStatsChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnStatsChanged__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnStatsChanged__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnStatsChanged_DelegateWrapper(const FMulticastScriptDelegate& OnStatsChanged, float ShieldPct, float ArmorPct, float StructPct)
{
	struct _Script_Echoes_eventOnStatsChanged_Parms
	{
		float ShieldPct;
		float ArmorPct;
		float StructPct;
	};
	_Script_Echoes_eventOnStatsChanged_Parms Parms;
	Parms.ShieldPct=ShieldPct;
	Parms.ArmorPct=ArmorPct;
	Parms.StructPct=StructPct;
	OnStatsChanged.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnStatsChanged *********************************************************

// ********** Begin Delegate FOnDeath **************************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnDeath__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnDeath_Parms
	{
		AActor* Victim;
		AActor* Killer;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Delegate for death event\n * @param Victim - The actor that died (owner of this component)\n * @param Killer - The actor that dealt the killing blow (can be nullptr)\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/EchoesStatsComponent.h" },
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
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_Echoes_OnDeath__DelegateSignature_Statics::NewProp_Victim = { "Victim", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnDeath_Parms, Victim), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_Echoes_OnDeath__DelegateSignature_Statics::NewProp_Killer = { "Killer", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnDeath_Parms, Killer), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnDeath__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnDeath__DelegateSignature_Statics::NewProp_Victim,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnDeath__DelegateSignature_Statics::NewProp_Killer,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnDeath__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnDeath__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnDeath__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnDeath__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnDeath__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnDeath__DelegateSignature_Statics::_Script_Echoes_eventOnDeath_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnDeath__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnDeath__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnDeath__DelegateSignature_Statics::_Script_Echoes_eventOnDeath_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnDeath__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnDeath__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnDeath_DelegateWrapper(const FMulticastScriptDelegate& OnDeath, AActor* Victim, AActor* Killer)
{
	struct _Script_Echoes_eventOnDeath_Parms
	{
		AActor* Victim;
		AActor* Killer;
	};
	_Script_Echoes_eventOnDeath_Parms Parms;
	Parms.Victim=Victim;
	Parms.Killer=Killer;
	OnDeath.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnDeath ****************************************************************

// ********** Begin Class UEchoesStatsComponent Function ClientOnly_OnRep_UpdateUI *****************
struct Z_Construct_UFunction_UEchoesStatsComponent_ClientOnly_OnRep_UpdateUI_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Called on clients when any Current stat is replicated\n\x09 * Triggers UI update via OnStatsChanged delegate\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/EchoesStatsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called on clients when any Current stat is replicated\nTriggers UI update via OnStatsChanged delegate" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesStatsComponent_ClientOnly_OnRep_UpdateUI_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesStatsComponent, nullptr, "ClientOnly_OnRep_UpdateUI", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesStatsComponent_ClientOnly_OnRep_UpdateUI_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesStatsComponent_ClientOnly_OnRep_UpdateUI_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesStatsComponent_ClientOnly_OnRep_UpdateUI()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesStatsComponent_ClientOnly_OnRep_UpdateUI_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesStatsComponent::execClientOnly_OnRep_UpdateUI)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientOnly_OnRep_UpdateUI();
	P_NATIVE_END;
}
// ********** End Class UEchoesStatsComponent Function ClientOnly_OnRep_UpdateUI *******************

// ********** Begin Class UEchoesStatsComponent Function Common_GetArmorPercentage *****************
struct Z_Construct_UFunction_UEchoesStatsComponent_Common_GetArmorPercentage_Statics
{
	struct EchoesStatsComponent_eventCommon_GetArmorPercentage_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get armor percentage (Blueprint Pure)\n\x09 * @return Armor percentage from 0.0 to 1.0\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/EchoesStatsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get armor percentage (Blueprint Pure)\n@return Armor percentage from 0.0 to 1.0" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UEchoesStatsComponent_Common_GetArmorPercentage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesStatsComponent_eventCommon_GetArmorPercentage_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesStatsComponent_Common_GetArmorPercentage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesStatsComponent_Common_GetArmorPercentage_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesStatsComponent_Common_GetArmorPercentage_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesStatsComponent_Common_GetArmorPercentage_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesStatsComponent, nullptr, "Common_GetArmorPercentage", Z_Construct_UFunction_UEchoesStatsComponent_Common_GetArmorPercentage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesStatsComponent_Common_GetArmorPercentage_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesStatsComponent_Common_GetArmorPercentage_Statics::EchoesStatsComponent_eventCommon_GetArmorPercentage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesStatsComponent_Common_GetArmorPercentage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesStatsComponent_Common_GetArmorPercentage_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesStatsComponent_Common_GetArmorPercentage_Statics::EchoesStatsComponent_eventCommon_GetArmorPercentage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesStatsComponent_Common_GetArmorPercentage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesStatsComponent_Common_GetArmorPercentage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesStatsComponent::execCommon_GetArmorPercentage)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->Common_GetArmorPercentage();
	P_NATIVE_END;
}
// ********** End Class UEchoesStatsComponent Function Common_GetArmorPercentage *******************

// ********** Begin Class UEchoesStatsComponent Function Common_GetHealthPercentage ****************
struct Z_Construct_UFunction_UEchoesStatsComponent_Common_GetHealthPercentage_Statics
{
	struct EchoesStatsComponent_eventCommon_GetHealthPercentage_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get overall health percentage (Blueprint Pure)\n\x09 * Useful for simplified health bars above enemies\n\x09 * \n\x09 * @return Health percentage from 0.0 to 1.0 (0% to 100%)\n\x09 * \n\x09 * Calculation: (ShieldCurrent + ArmorCurrent + StructureCurrent) / (ShieldMax + ArmorMax + StructureMax)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/EchoesStatsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get overall health percentage (Blueprint Pure)\nUseful for simplified health bars above enemies\n\n@return Health percentage from 0.0 to 1.0 (0% to 100%)\n\nCalculation: (ShieldCurrent + ArmorCurrent + StructureCurrent) / (ShieldMax + ArmorMax + StructureMax)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UEchoesStatsComponent_Common_GetHealthPercentage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesStatsComponent_eventCommon_GetHealthPercentage_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesStatsComponent_Common_GetHealthPercentage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesStatsComponent_Common_GetHealthPercentage_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesStatsComponent_Common_GetHealthPercentage_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesStatsComponent_Common_GetHealthPercentage_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesStatsComponent, nullptr, "Common_GetHealthPercentage", Z_Construct_UFunction_UEchoesStatsComponent_Common_GetHealthPercentage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesStatsComponent_Common_GetHealthPercentage_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesStatsComponent_Common_GetHealthPercentage_Statics::EchoesStatsComponent_eventCommon_GetHealthPercentage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesStatsComponent_Common_GetHealthPercentage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesStatsComponent_Common_GetHealthPercentage_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesStatsComponent_Common_GetHealthPercentage_Statics::EchoesStatsComponent_eventCommon_GetHealthPercentage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesStatsComponent_Common_GetHealthPercentage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesStatsComponent_Common_GetHealthPercentage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesStatsComponent::execCommon_GetHealthPercentage)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->Common_GetHealthPercentage();
	P_NATIVE_END;
}
// ********** End Class UEchoesStatsComponent Function Common_GetHealthPercentage ******************

// ********** Begin Class UEchoesStatsComponent Function Common_GetShieldPercentage ****************
struct Z_Construct_UFunction_UEchoesStatsComponent_Common_GetShieldPercentage_Statics
{
	struct EchoesStatsComponent_eventCommon_GetShieldPercentage_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get shield percentage (Blueprint Pure)\n\x09 * @return Shield percentage from 0.0 to 1.0\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/EchoesStatsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get shield percentage (Blueprint Pure)\n@return Shield percentage from 0.0 to 1.0" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UEchoesStatsComponent_Common_GetShieldPercentage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesStatsComponent_eventCommon_GetShieldPercentage_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesStatsComponent_Common_GetShieldPercentage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesStatsComponent_Common_GetShieldPercentage_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesStatsComponent_Common_GetShieldPercentage_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesStatsComponent_Common_GetShieldPercentage_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesStatsComponent, nullptr, "Common_GetShieldPercentage", Z_Construct_UFunction_UEchoesStatsComponent_Common_GetShieldPercentage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesStatsComponent_Common_GetShieldPercentage_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesStatsComponent_Common_GetShieldPercentage_Statics::EchoesStatsComponent_eventCommon_GetShieldPercentage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesStatsComponent_Common_GetShieldPercentage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesStatsComponent_Common_GetShieldPercentage_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesStatsComponent_Common_GetShieldPercentage_Statics::EchoesStatsComponent_eventCommon_GetShieldPercentage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesStatsComponent_Common_GetShieldPercentage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesStatsComponent_Common_GetShieldPercentage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesStatsComponent::execCommon_GetShieldPercentage)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->Common_GetShieldPercentage();
	P_NATIVE_END;
}
// ********** End Class UEchoesStatsComponent Function Common_GetShieldPercentage ******************

// ********** Begin Class UEchoesStatsComponent Function Common_GetStructurePercentage *************
struct Z_Construct_UFunction_UEchoesStatsComponent_Common_GetStructurePercentage_Statics
{
	struct EchoesStatsComponent_eventCommon_GetStructurePercentage_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get structure percentage (Blueprint Pure)\n\x09 * @return Structure percentage from 0.0 to 1.0\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/EchoesStatsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get structure percentage (Blueprint Pure)\n@return Structure percentage from 0.0 to 1.0" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UEchoesStatsComponent_Common_GetStructurePercentage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesStatsComponent_eventCommon_GetStructurePercentage_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesStatsComponent_Common_GetStructurePercentage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesStatsComponent_Common_GetStructurePercentage_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesStatsComponent_Common_GetStructurePercentage_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesStatsComponent_Common_GetStructurePercentage_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesStatsComponent, nullptr, "Common_GetStructurePercentage", Z_Construct_UFunction_UEchoesStatsComponent_Common_GetStructurePercentage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesStatsComponent_Common_GetStructurePercentage_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesStatsComponent_Common_GetStructurePercentage_Statics::EchoesStatsComponent_eventCommon_GetStructurePercentage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesStatsComponent_Common_GetStructurePercentage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesStatsComponent_Common_GetStructurePercentage_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesStatsComponent_Common_GetStructurePercentage_Statics::EchoesStatsComponent_eventCommon_GetStructurePercentage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesStatsComponent_Common_GetStructurePercentage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesStatsComponent_Common_GetStructurePercentage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesStatsComponent::execCommon_GetStructurePercentage)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->Common_GetStructurePercentage();
	P_NATIVE_END;
}
// ********** End Class UEchoesStatsComponent Function Common_GetStructurePercentage ***************

// ********** Begin Class UEchoesStatsComponent Function IsAlive ***********************************
struct Z_Construct_UFunction_UEchoesStatsComponent_IsAlive_Statics
{
	struct EchoesStatsComponent_eventIsAlive_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if the actor is alive\n\x09 * @return True if Structure > 0\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/EchoesStatsComponent.h" },
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
void Z_Construct_UFunction_UEchoesStatsComponent_IsAlive_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((EchoesStatsComponent_eventIsAlive_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UEchoesStatsComponent_IsAlive_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EchoesStatsComponent_eventIsAlive_Parms), &Z_Construct_UFunction_UEchoesStatsComponent_IsAlive_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesStatsComponent_IsAlive_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesStatsComponent_IsAlive_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesStatsComponent_IsAlive_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesStatsComponent_IsAlive_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesStatsComponent, nullptr, "IsAlive", Z_Construct_UFunction_UEchoesStatsComponent_IsAlive_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesStatsComponent_IsAlive_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesStatsComponent_IsAlive_Statics::EchoesStatsComponent_eventIsAlive_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesStatsComponent_IsAlive_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesStatsComponent_IsAlive_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesStatsComponent_IsAlive_Statics::EchoesStatsComponent_eventIsAlive_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesStatsComponent_IsAlive()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesStatsComponent_IsAlive_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesStatsComponent::execIsAlive)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsAlive();
	P_NATIVE_END;
}
// ********** End Class UEchoesStatsComponent Function IsAlive *************************************

// ********** Begin Class UEchoesStatsComponent Function ServerOnly_ApplyDamage ********************
struct Z_Construct_UFunction_UEchoesStatsComponent_ServerOnly_ApplyDamage_Statics
{
	struct EchoesStatsComponent_eventServerOnly_ApplyDamage_Parms
	{
		float Amount;
		AActor* DamageCauser;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Apply damage to this actor (Server Only)\n\x09 * Implements EVE-like damage cascade: Shield \xe2\x86\x92 Armor \xe2\x86\x92 Structure\n\x09 * \n\x09 * @param Amount - Amount of damage to apply\n\x09 * @param DamageCauser - Optional actor that caused the damage (for kill attribution)\n\x09 * \n\x09 * Behavior:\n\x09 * - Damage first depletes Shield\n\x09 * - Overflow damage goes to Armor\n\x09 * - Overflow from Armor goes to Structure\n\x09 * - When Structure <= 0, triggers OnDeath event\n\x09 * - Resets shield regeneration timer\n\x09 */" },
#endif
		{ "CPP_Default_DamageCauser", "None" },
		{ "ModuleRelativePath", "Core/Common/Components/EchoesStatsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Apply damage to this actor (Server Only)\nImplements EVE-like damage cascade: Shield \xe2\x86\x92 Armor \xe2\x86\x92 Structure\n\n@param Amount - Amount of damage to apply\n@param DamageCauser - Optional actor that caused the damage (for kill attribution)\n\nBehavior:\n- Damage first depletes Shield\n- Overflow damage goes to Armor\n- Overflow from Armor goes to Structure\n- When Structure <= 0, triggers OnDeath event\n- Resets shield regeneration timer" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Amount;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DamageCauser;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UEchoesStatsComponent_ServerOnly_ApplyDamage_Statics::NewProp_Amount = { "Amount", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesStatsComponent_eventServerOnly_ApplyDamage_Parms, Amount), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEchoesStatsComponent_ServerOnly_ApplyDamage_Statics::NewProp_DamageCauser = { "DamageCauser", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesStatsComponent_eventServerOnly_ApplyDamage_Parms, DamageCauser), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesStatsComponent_ServerOnly_ApplyDamage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesStatsComponent_ServerOnly_ApplyDamage_Statics::NewProp_Amount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesStatsComponent_ServerOnly_ApplyDamage_Statics::NewProp_DamageCauser,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesStatsComponent_ServerOnly_ApplyDamage_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesStatsComponent_ServerOnly_ApplyDamage_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesStatsComponent, nullptr, "ServerOnly_ApplyDamage", Z_Construct_UFunction_UEchoesStatsComponent_ServerOnly_ApplyDamage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesStatsComponent_ServerOnly_ApplyDamage_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesStatsComponent_ServerOnly_ApplyDamage_Statics::EchoesStatsComponent_eventServerOnly_ApplyDamage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesStatsComponent_ServerOnly_ApplyDamage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesStatsComponent_ServerOnly_ApplyDamage_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesStatsComponent_ServerOnly_ApplyDamage_Statics::EchoesStatsComponent_eventServerOnly_ApplyDamage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesStatsComponent_ServerOnly_ApplyDamage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesStatsComponent_ServerOnly_ApplyDamage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesStatsComponent::execServerOnly_ApplyDamage)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Amount);
	P_GET_OBJECT(AActor,Z_Param_DamageCauser);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerOnly_ApplyDamage(Z_Param_Amount,Z_Param_DamageCauser);
	P_NATIVE_END;
}
// ********** End Class UEchoesStatsComponent Function ServerOnly_ApplyDamage **********************

// ********** Begin Class UEchoesStatsComponent Function ServerOnly_RestoreAll *********************
struct Z_Construct_UFunction_UEchoesStatsComponent_ServerOnly_RestoreAll_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Fully restore all stats to maximum (Server Only)\n\x09 * Useful for respawn or repair mechanics\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/EchoesStatsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fully restore all stats to maximum (Server Only)\nUseful for respawn or repair mechanics" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesStatsComponent_ServerOnly_RestoreAll_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesStatsComponent, nullptr, "ServerOnly_RestoreAll", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesStatsComponent_ServerOnly_RestoreAll_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesStatsComponent_ServerOnly_RestoreAll_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesStatsComponent_ServerOnly_RestoreAll()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesStatsComponent_ServerOnly_RestoreAll_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesStatsComponent::execServerOnly_RestoreAll)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerOnly_RestoreAll();
	P_NATIVE_END;
}
// ********** End Class UEchoesStatsComponent Function ServerOnly_RestoreAll ***********************

// ********** Begin Class UEchoesStatsComponent ****************************************************
void UEchoesStatsComponent::StaticRegisterNativesUEchoesStatsComponent()
{
	UClass* Class = UEchoesStatsComponent::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ClientOnly_OnRep_UpdateUI", &UEchoesStatsComponent::execClientOnly_OnRep_UpdateUI },
		{ "Common_GetArmorPercentage", &UEchoesStatsComponent::execCommon_GetArmorPercentage },
		{ "Common_GetHealthPercentage", &UEchoesStatsComponent::execCommon_GetHealthPercentage },
		{ "Common_GetShieldPercentage", &UEchoesStatsComponent::execCommon_GetShieldPercentage },
		{ "Common_GetStructurePercentage", &UEchoesStatsComponent::execCommon_GetStructurePercentage },
		{ "IsAlive", &UEchoesStatsComponent::execIsAlive },
		{ "ServerOnly_ApplyDamage", &UEchoesStatsComponent::execServerOnly_ApplyDamage },
		{ "ServerOnly_RestoreAll", &UEchoesStatsComponent::execServerOnly_RestoreAll },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UEchoesStatsComponent;
UClass* UEchoesStatsComponent::GetPrivateStaticClass()
{
	using TClass = UEchoesStatsComponent;
	if (!Z_Registration_Info_UClass_UEchoesStatsComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesStatsComponent"),
			Z_Registration_Info_UClass_UEchoesStatsComponent.InnerSingleton,
			StaticRegisterNativesUEchoesStatsComponent,
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
	return Z_Registration_Info_UClass_UEchoesStatsComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UEchoesStatsComponent_NoRegister()
{
	return UEchoesStatsComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UEchoesStatsComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Echoes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * UEchoesStatsComponent\n * \n * EVE-like ship/structure survivability component for Echoes MMO\n * Manages three-layer protection system with replication for multiplayer\n * \n * Architecture:\n * - ActorComponent: Can be attached to ships, stations, structures\n * - Three protection layers: Shield \xe2\x86\x92 Armor \xe2\x86\x92 Structure\n * - Replicated: All Current values replicate to clients for UI updates\n * - Server-authoritative: Damage calculations only on server\n * \n * Protection Layers (EVE-like):\n * 1. Shield: First line of defense, regenerates passively over time\n * 2. Armor: Second layer, does not regenerate automatically\n * 3. Structure: Final layer (hull), destruction when depleted\n * \n * Damage Flow:\n * Damage \xe2\x86\x92 Shield (if > 0) \xe2\x86\x92 Armor (if shield depleted) \xe2\x86\x92 Structure (if armor depleted) \xe2\x86\x92 Death\n * \n * Usage:\n * - Attach to ship pawns for combat survivability\n * - Attach to station actors for destructible structures\n * - Server calls ServerOnly_ApplyDamage() when hit\n * - Clients receive updates via replication and update UI\n */" },
#endif
		{ "IncludePath", "Core/Common/Components/EchoesStatsComponent.h" },
		{ "ModuleRelativePath", "Core/Common/Components/EchoesStatsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UEchoesStatsComponent\n\nEVE-like ship/structure survivability component for Echoes MMO\nManages three-layer protection system with replication for multiplayer\n\nArchitecture:\n- ActorComponent: Can be attached to ships, stations, structures\n- Three protection layers: Shield \xe2\x86\x92 Armor \xe2\x86\x92 Structure\n- Replicated: All Current values replicate to clients for UI updates\n- Server-authoritative: Damage calculations only on server\n\nProtection Layers (EVE-like):\n1. Shield: First line of defense, regenerates passively over time\n2. Armor: Second layer, does not regenerate automatically\n3. Structure: Final layer (hull), destruction when depleted\n\nDamage Flow:\nDamage \xe2\x86\x92 Shield (if > 0) \xe2\x86\x92 Armor (if shield depleted) \xe2\x86\x92 Structure (if armor depleted) \xe2\x86\x92 Death\n\nUsage:\n- Attach to ship pawns for combat survivability\n- Attach to station actors for destructible structures\n- Server calls ServerOnly_ApplyDamage() when hit\n- Clients receive updates via replication and update UI" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShieldCurrent_MetaData[] = {
		{ "Category", "Stats|Shield" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current shield hit points */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/EchoesStatsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current shield hit points" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShieldMax_MetaData[] = {
		{ "Category", "Stats|Shield" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum shield hit points */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/EchoesStatsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum shield hit points" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShieldRegenRate_MetaData[] = {
		{ "Category", "Stats|Shield" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Shield regeneration rate (HP per second) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/EchoesStatsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shield regeneration rate (HP per second)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShieldRegenDelay_MetaData[] = {
		{ "Category", "Stats|Shield" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Delay before shield starts regenerating after taking damage (seconds) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/EchoesStatsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Delay before shield starts regenerating after taking damage (seconds)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ArmorCurrent_MetaData[] = {
		{ "Category", "Stats|Armor" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current armor hit points */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/EchoesStatsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current armor hit points" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ArmorMax_MetaData[] = {
		{ "Category", "Stats|Armor" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum armor hit points */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/EchoesStatsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum armor hit points" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StructureCurrent_MetaData[] = {
		{ "Category", "Stats|Structure" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current structure (hull) hit points */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/EchoesStatsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current structure (hull) hit points" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StructureMax_MetaData[] = {
		{ "Category", "Stats|Structure" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum structure (hull) hit points */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/EchoesStatsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum structure (hull) hit points" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnStatsChanged_MetaData[] = {
		{ "Category", "Stats|Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \n\x09 * Event broadcast when stats change - used for UI updates\n\x09 * Fires on clients when replicated values update\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/EchoesStatsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Event broadcast when stats change - used for UI updates\nFires on clients when replicated values update" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnDeath_MetaData[] = {
		{ "Category", "Stats|Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Event broadcast when the actor dies (Structure depleted)\n\x09 * Only fires on server, then replicates destruction\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/EchoesStatsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Event broadcast when the actor dies (Structure depleted)\nOnly fires on server, then replicates destruction" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LastDamageCauser_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Cached reference to damage causer for death event */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/EchoesStatsComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cached reference to damage causer for death event" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ShieldCurrent;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ShieldMax;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ShieldRegenRate;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ShieldRegenDelay;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ArmorCurrent;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ArmorMax;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_StructureCurrent;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_StructureMax;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnStatsChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnDeath;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LastDamageCauser;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UEchoesStatsComponent_ClientOnly_OnRep_UpdateUI, "ClientOnly_OnRep_UpdateUI" }, // 2837074412
		{ &Z_Construct_UFunction_UEchoesStatsComponent_Common_GetArmorPercentage, "Common_GetArmorPercentage" }, // 794226366
		{ &Z_Construct_UFunction_UEchoesStatsComponent_Common_GetHealthPercentage, "Common_GetHealthPercentage" }, // 143939972
		{ &Z_Construct_UFunction_UEchoesStatsComponent_Common_GetShieldPercentage, "Common_GetShieldPercentage" }, // 1711444485
		{ &Z_Construct_UFunction_UEchoesStatsComponent_Common_GetStructurePercentage, "Common_GetStructurePercentage" }, // 86706426
		{ &Z_Construct_UFunction_UEchoesStatsComponent_IsAlive, "IsAlive" }, // 4238497304
		{ &Z_Construct_UFunction_UEchoesStatsComponent_ServerOnly_ApplyDamage, "ServerOnly_ApplyDamage" }, // 3919285005
		{ &Z_Construct_UFunction_UEchoesStatsComponent_ServerOnly_RestoreAll, "ServerOnly_RestoreAll" }, // 450450670
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEchoesStatsComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEchoesStatsComponent_Statics::NewProp_ShieldCurrent = { "ShieldCurrent", "ClientOnly_OnRep_UpdateUI", (EPropertyFlags)0x0010000100000034, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesStatsComponent, ShieldCurrent), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShieldCurrent_MetaData), NewProp_ShieldCurrent_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEchoesStatsComponent_Statics::NewProp_ShieldMax = { "ShieldMax", nullptr, (EPropertyFlags)0x0010000000000025, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesStatsComponent, ShieldMax), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShieldMax_MetaData), NewProp_ShieldMax_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEchoesStatsComponent_Statics::NewProp_ShieldRegenRate = { "ShieldRegenRate", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesStatsComponent, ShieldRegenRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShieldRegenRate_MetaData), NewProp_ShieldRegenRate_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEchoesStatsComponent_Statics::NewProp_ShieldRegenDelay = { "ShieldRegenDelay", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesStatsComponent, ShieldRegenDelay), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShieldRegenDelay_MetaData), NewProp_ShieldRegenDelay_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEchoesStatsComponent_Statics::NewProp_ArmorCurrent = { "ArmorCurrent", "ClientOnly_OnRep_UpdateUI", (EPropertyFlags)0x0010000100000034, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesStatsComponent, ArmorCurrent), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ArmorCurrent_MetaData), NewProp_ArmorCurrent_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEchoesStatsComponent_Statics::NewProp_ArmorMax = { "ArmorMax", nullptr, (EPropertyFlags)0x0010000000000025, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesStatsComponent, ArmorMax), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ArmorMax_MetaData), NewProp_ArmorMax_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEchoesStatsComponent_Statics::NewProp_StructureCurrent = { "StructureCurrent", "ClientOnly_OnRep_UpdateUI", (EPropertyFlags)0x0010000100000034, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesStatsComponent, StructureCurrent), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StructureCurrent_MetaData), NewProp_StructureCurrent_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEchoesStatsComponent_Statics::NewProp_StructureMax = { "StructureMax", nullptr, (EPropertyFlags)0x0010000000000025, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesStatsComponent, StructureMax), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StructureMax_MetaData), NewProp_StructureMax_MetaData) };
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEchoesStatsComponent_Statics::NewProp_OnStatsChanged = { "OnStatsChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesStatsComponent, OnStatsChanged), Z_Construct_UDelegateFunction_Echoes_OnStatsChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnStatsChanged_MetaData), NewProp_OnStatsChanged_MetaData) }; // 133900753
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEchoesStatsComponent_Statics::NewProp_OnDeath = { "OnDeath", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesStatsComponent, OnDeath), Z_Construct_UDelegateFunction_Echoes_OnDeath__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnDeath_MetaData), NewProp_OnDeath_MetaData) }; // 612496262
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesStatsComponent_Statics::NewProp_LastDamageCauser = { "LastDamageCauser", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesStatsComponent, LastDamageCauser), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LastDamageCauser_MetaData), NewProp_LastDamageCauser_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEchoesStatsComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesStatsComponent_Statics::NewProp_ShieldCurrent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesStatsComponent_Statics::NewProp_ShieldMax,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesStatsComponent_Statics::NewProp_ShieldRegenRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesStatsComponent_Statics::NewProp_ShieldRegenDelay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesStatsComponent_Statics::NewProp_ArmorCurrent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesStatsComponent_Statics::NewProp_ArmorMax,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesStatsComponent_Statics::NewProp_StructureCurrent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesStatsComponent_Statics::NewProp_StructureMax,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesStatsComponent_Statics::NewProp_OnStatsChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesStatsComponent_Statics::NewProp_OnDeath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesStatsComponent_Statics::NewProp_LastDamageCauser,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesStatsComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UEchoesStatsComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesStatsComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEchoesStatsComponent_Statics::ClassParams = {
	&UEchoesStatsComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UEchoesStatsComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesStatsComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesStatsComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UEchoesStatsComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEchoesStatsComponent()
{
	if (!Z_Registration_Info_UClass_UEchoesStatsComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEchoesStatsComponent.OuterSingleton, Z_Construct_UClass_UEchoesStatsComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEchoesStatsComponent.OuterSingleton;
}
#if VALIDATE_CLASS_REPS
void UEchoesStatsComponent::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static FName Name_ShieldCurrent(TEXT("ShieldCurrent"));
	static FName Name_ShieldMax(TEXT("ShieldMax"));
	static FName Name_ArmorCurrent(TEXT("ArmorCurrent"));
	static FName Name_ArmorMax(TEXT("ArmorMax"));
	static FName Name_StructureCurrent(TEXT("StructureCurrent"));
	static FName Name_StructureMax(TEXT("StructureMax"));
	const bool bIsValid = true
		&& Name_ShieldCurrent == ClassReps[(int32)ENetFields_Private::ShieldCurrent].Property->GetFName()
		&& Name_ShieldMax == ClassReps[(int32)ENetFields_Private::ShieldMax].Property->GetFName()
		&& Name_ArmorCurrent == ClassReps[(int32)ENetFields_Private::ArmorCurrent].Property->GetFName()
		&& Name_ArmorMax == ClassReps[(int32)ENetFields_Private::ArmorMax].Property->GetFName()
		&& Name_StructureCurrent == ClassReps[(int32)ENetFields_Private::StructureCurrent].Property->GetFName()
		&& Name_StructureMax == ClassReps[(int32)ENetFields_Private::StructureMax].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in UEchoesStatsComponent"));
}
#endif
DEFINE_VTABLE_PTR_HELPER_CTOR(UEchoesStatsComponent);
UEchoesStatsComponent::~UEchoesStatsComponent() {}
// ********** End Class UEchoesStatsComponent ******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EchoesStatsComponent_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEchoesStatsComponent, UEchoesStatsComponent::StaticClass, TEXT("UEchoesStatsComponent"), &Z_Registration_Info_UClass_UEchoesStatsComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEchoesStatsComponent), 844436574U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EchoesStatsComponent_h__Script_Echoes_2882511901(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EchoesStatsComponent_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EchoesStatsComponent_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
