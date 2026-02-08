// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PersistenceMarketComponent.h"
#include "EchoesMarketStructures.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodePersistenceMarketComponent() {}

// ********** Begin Cross Module References ********************************************************
ECHOES_API UClass* Z_Construct_UClass_UEchoesMarketSubsystem_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UPersistenceMarketComponent();
ECHOES_API UClass* Z_Construct_UClass_UPersistenceMarketComponent_NoRegister();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnTradingAvailabilityChanged__DelegateSignature();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FMarketFilter();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FOnTradingAvailabilityChanged *****************************************
struct Z_Construct_UDelegateFunction_Echoes_OnTradingAvailabilityChanged__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnTradingAvailabilityChanged_Parms
	{
		bool bCanTrade;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when trading availability changes (entered/exited trading hub range) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/PersistenceMarketComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when trading availability changes (entered/exited trading hub range)" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_bCanTrade_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCanTrade;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
void Z_Construct_UDelegateFunction_Echoes_OnTradingAvailabilityChanged__DelegateSignature_Statics::NewProp_bCanTrade_SetBit(void* Obj)
{
	((_Script_Echoes_eventOnTradingAvailabilityChanged_Parms*)Obj)->bCanTrade = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_Echoes_OnTradingAvailabilityChanged__DelegateSignature_Statics::NewProp_bCanTrade = { "bCanTrade", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_Echoes_eventOnTradingAvailabilityChanged_Parms), &Z_Construct_UDelegateFunction_Echoes_OnTradingAvailabilityChanged__DelegateSignature_Statics::NewProp_bCanTrade_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnTradingAvailabilityChanged__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnTradingAvailabilityChanged__DelegateSignature_Statics::NewProp_bCanTrade,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnTradingAvailabilityChanged__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnTradingAvailabilityChanged__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnTradingAvailabilityChanged__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnTradingAvailabilityChanged__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnTradingAvailabilityChanged__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnTradingAvailabilityChanged__DelegateSignature_Statics::_Script_Echoes_eventOnTradingAvailabilityChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnTradingAvailabilityChanged__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnTradingAvailabilityChanged__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnTradingAvailabilityChanged__DelegateSignature_Statics::_Script_Echoes_eventOnTradingAvailabilityChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnTradingAvailabilityChanged__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnTradingAvailabilityChanged__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnTradingAvailabilityChanged_DelegateWrapper(const FMulticastScriptDelegate& OnTradingAvailabilityChanged, bool bCanTrade)
{
	struct _Script_Echoes_eventOnTradingAvailabilityChanged_Parms
	{
		bool bCanTrade;
	};
	_Script_Echoes_eventOnTradingAvailabilityChanged_Parms Parms;
	Parms.bCanTrade=bCanTrade ? true : false;
	OnTradingAvailabilityChanged.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnTradingAvailabilityChanged *******************************************

// ********** Begin Class UPersistenceMarketComponent Function CanTrade ****************************
struct Z_Construct_UFunction_UPersistenceMarketComponent_CanTrade_Statics
{
	struct PersistenceMarketComponent_eventCanTrade_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Market" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check current trading availability\n\x09 * @return True if trading is currently available\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/PersistenceMarketComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check current trading availability\n@return True if trading is currently available" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UPersistenceMarketComponent_CanTrade_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((PersistenceMarketComponent_eventCanTrade_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPersistenceMarketComponent_CanTrade_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PersistenceMarketComponent_eventCanTrade_Parms), &Z_Construct_UFunction_UPersistenceMarketComponent_CanTrade_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPersistenceMarketComponent_CanTrade_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPersistenceMarketComponent_CanTrade_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistenceMarketComponent_CanTrade_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPersistenceMarketComponent_CanTrade_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPersistenceMarketComponent, nullptr, "CanTrade", Z_Construct_UFunction_UPersistenceMarketComponent_CanTrade_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistenceMarketComponent_CanTrade_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPersistenceMarketComponent_CanTrade_Statics::PersistenceMarketComponent_eventCanTrade_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistenceMarketComponent_CanTrade_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPersistenceMarketComponent_CanTrade_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPersistenceMarketComponent_CanTrade_Statics::PersistenceMarketComponent_eventCanTrade_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPersistenceMarketComponent_CanTrade()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPersistenceMarketComponent_CanTrade_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPersistenceMarketComponent::execCanTrade)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->CanTrade();
	P_NATIVE_END;
}
// ********** End Class UPersistenceMarketComponent Function CanTrade ******************************

// ********** Begin Class UPersistenceMarketComponent Function Client_RequestMarketData ************
struct Z_Construct_UFunction_UPersistenceMarketComponent_Client_RequestMarketData_Statics
{
	struct PersistenceMarketComponent_eventClient_RequestMarketData_Parms
	{
		FMarketFilter Filter;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Market" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Request market data from the backend via MarketSubsystem\n\x09 * Only succeeds if bCanTrade is true (player near trading hub)\n\x09 * \n\x09 * @param Filter - Market filter (RegionId, ItemId, display options)\n\x09 * @return True if request was sent, false if not near trading hub\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/PersistenceMarketComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Request market data from the backend via MarketSubsystem\nOnly succeeds if bCanTrade is true (player near trading hub)\n\n@param Filter - Market filter (RegionId, ItemId, display options)\n@return True if request was sent, false if not near trading hub" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Filter_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Filter;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPersistenceMarketComponent_Client_RequestMarketData_Statics::NewProp_Filter = { "Filter", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PersistenceMarketComponent_eventClient_RequestMarketData_Parms, Filter), Z_Construct_UScriptStruct_FMarketFilter, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Filter_MetaData), NewProp_Filter_MetaData) }; // 2889192733
void Z_Construct_UFunction_UPersistenceMarketComponent_Client_RequestMarketData_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((PersistenceMarketComponent_eventClient_RequestMarketData_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPersistenceMarketComponent_Client_RequestMarketData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PersistenceMarketComponent_eventClient_RequestMarketData_Parms), &Z_Construct_UFunction_UPersistenceMarketComponent_Client_RequestMarketData_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPersistenceMarketComponent_Client_RequestMarketData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPersistenceMarketComponent_Client_RequestMarketData_Statics::NewProp_Filter,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPersistenceMarketComponent_Client_RequestMarketData_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistenceMarketComponent_Client_RequestMarketData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPersistenceMarketComponent_Client_RequestMarketData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPersistenceMarketComponent, nullptr, "Client_RequestMarketData", Z_Construct_UFunction_UPersistenceMarketComponent_Client_RequestMarketData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistenceMarketComponent_Client_RequestMarketData_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPersistenceMarketComponent_Client_RequestMarketData_Statics::PersistenceMarketComponent_eventClient_RequestMarketData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistenceMarketComponent_Client_RequestMarketData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPersistenceMarketComponent_Client_RequestMarketData_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPersistenceMarketComponent_Client_RequestMarketData_Statics::PersistenceMarketComponent_eventClient_RequestMarketData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPersistenceMarketComponent_Client_RequestMarketData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPersistenceMarketComponent_Client_RequestMarketData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPersistenceMarketComponent::execClient_RequestMarketData)
{
	P_GET_STRUCT_REF(FMarketFilter,Z_Param_Out_Filter);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->Client_RequestMarketData(Z_Param_Out_Filter);
	P_NATIVE_END;
}
// ********** End Class UPersistenceMarketComponent Function Client_RequestMarketData **************

// ********** Begin Class UPersistenceMarketComponent Function ServerOnly_IsNearTradingHub *********
struct Z_Construct_UFunction_UPersistenceMarketComponent_ServerOnly_IsNearTradingHub_Statics
{
	struct PersistenceMarketComponent_eventServerOnly_IsNearTradingHub_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Market" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if the owning actor is near a trading hub (Station or Stargate)\n\x09 * Uses squared distance comparison for performance\n\x09 * \n\x09 * @return True if within TradingDistance of any trading hub\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/PersistenceMarketComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if the owning actor is near a trading hub (Station or Stargate)\nUses squared distance comparison for performance\n\n@return True if within TradingDistance of any trading hub" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UPersistenceMarketComponent_ServerOnly_IsNearTradingHub_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((PersistenceMarketComponent_eventServerOnly_IsNearTradingHub_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPersistenceMarketComponent_ServerOnly_IsNearTradingHub_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PersistenceMarketComponent_eventServerOnly_IsNearTradingHub_Parms), &Z_Construct_UFunction_UPersistenceMarketComponent_ServerOnly_IsNearTradingHub_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPersistenceMarketComponent_ServerOnly_IsNearTradingHub_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPersistenceMarketComponent_ServerOnly_IsNearTradingHub_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistenceMarketComponent_ServerOnly_IsNearTradingHub_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPersistenceMarketComponent_ServerOnly_IsNearTradingHub_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPersistenceMarketComponent, nullptr, "ServerOnly_IsNearTradingHub", Z_Construct_UFunction_UPersistenceMarketComponent_ServerOnly_IsNearTradingHub_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistenceMarketComponent_ServerOnly_IsNearTradingHub_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPersistenceMarketComponent_ServerOnly_IsNearTradingHub_Statics::PersistenceMarketComponent_eventServerOnly_IsNearTradingHub_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistenceMarketComponent_ServerOnly_IsNearTradingHub_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPersistenceMarketComponent_ServerOnly_IsNearTradingHub_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPersistenceMarketComponent_ServerOnly_IsNearTradingHub_Statics::PersistenceMarketComponent_eventServerOnly_IsNearTradingHub_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPersistenceMarketComponent_ServerOnly_IsNearTradingHub()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPersistenceMarketComponent_ServerOnly_IsNearTradingHub_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPersistenceMarketComponent::execServerOnly_IsNearTradingHub)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ServerOnly_IsNearTradingHub();
	P_NATIVE_END;
}
// ********** End Class UPersistenceMarketComponent Function ServerOnly_IsNearTradingHub ***********

// ********** Begin Class UPersistenceMarketComponent **********************************************
void UPersistenceMarketComponent::StaticRegisterNativesUPersistenceMarketComponent()
{
	UClass* Class = UPersistenceMarketComponent::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "CanTrade", &UPersistenceMarketComponent::execCanTrade },
		{ "Client_RequestMarketData", &UPersistenceMarketComponent::execClient_RequestMarketData },
		{ "ServerOnly_IsNearTradingHub", &UPersistenceMarketComponent::execServerOnly_IsNearTradingHub },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UPersistenceMarketComponent;
UClass* UPersistenceMarketComponent::GetPrivateStaticClass()
{
	using TClass = UPersistenceMarketComponent;
	if (!Z_Registration_Info_UClass_UPersistenceMarketComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("PersistenceMarketComponent"),
			Z_Registration_Info_UClass_UPersistenceMarketComponent.InnerSingleton,
			StaticRegisterNativesUPersistenceMarketComponent,
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
	return Z_Registration_Info_UClass_UPersistenceMarketComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UPersistenceMarketComponent_NoRegister()
{
	return UPersistenceMarketComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UPersistenceMarketComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Echoes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * UPersistenceMarketComponent\n * \n * Actor Component that gates market access based on proximity to trading hubs\n * Attach to player ships to enable market trading when near stations/stargates\n * \n * Architecture:\n * - Uses timer-based proximity check (every 0.5s) instead of Tick for performance\n * - Caches nearby station/stargate references instead of GetAllActorsOfClass each check\n * - Delegates market API calls to UEchoesMarketSubsystem\n * - Client_ prefix: Methods called from client UI\n * - ServerOnly_ prefix: Methods for server-authoritative checks\n */" },
#endif
		{ "IncludePath", "Core/Common/Components/PersistenceMarketComponent.h" },
		{ "ModuleRelativePath", "Core/Common/Components/PersistenceMarketComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UPersistenceMarketComponent\n\nActor Component that gates market access based on proximity to trading hubs\nAttach to player ships to enable market trading when near stations/stargates\n\nArchitecture:\n- Uses timer-based proximity check (every 0.5s) instead of Tick for performance\n- Caches nearby station/stargate references instead of GetAllActorsOfClass each check\n- Delegates market API calls to UEchoesMarketSubsystem\n- Client_ prefix: Methods called from client UI\n- ServerOnly_ prefix: Methods for server-authoritative checks" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TradingDistance_MetaData[] = {
		{ "Category", "Echoes|Market" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum distance to a trading hub for market access (in Unreal units / cm) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/PersistenceMarketComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum distance to a trading hub for market access (in Unreal units / cm)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProximityCheckInterval_MetaData[] = {
		{ "Category", "Echoes|Market" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Interval for proximity check (seconds) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/PersistenceMarketComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Interval for proximity check (seconds)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnTradingAvailabilityChanged_MetaData[] = {
		{ "Category", "Echoes|Market|Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when trading availability changes */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/PersistenceMarketComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when trading availability changes" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CachedTradingHubs_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Cached references to trading hub actors (stations/stargates) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/PersistenceMarketComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cached references to trading hub actors (stations/stargates)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MarketSubsystem_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Reference to market subsystem */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/PersistenceMarketComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Reference to market subsystem" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TradingDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ProximityCheckInterval;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnTradingAvailabilityChanged;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CachedTradingHubs_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_CachedTradingHubs;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MarketSubsystem;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UPersistenceMarketComponent_CanTrade, "CanTrade" }, // 540784188
		{ &Z_Construct_UFunction_UPersistenceMarketComponent_Client_RequestMarketData, "Client_RequestMarketData" }, // 116754894
		{ &Z_Construct_UFunction_UPersistenceMarketComponent_ServerOnly_IsNearTradingHub, "ServerOnly_IsNearTradingHub" }, // 3916891663
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPersistenceMarketComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPersistenceMarketComponent_Statics::NewProp_TradingDistance = { "TradingDistance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPersistenceMarketComponent, TradingDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TradingDistance_MetaData), NewProp_TradingDistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPersistenceMarketComponent_Statics::NewProp_ProximityCheckInterval = { "ProximityCheckInterval", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPersistenceMarketComponent, ProximityCheckInterval), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProximityCheckInterval_MetaData), NewProp_ProximityCheckInterval_MetaData) };
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UPersistenceMarketComponent_Statics::NewProp_OnTradingAvailabilityChanged = { "OnTradingAvailabilityChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPersistenceMarketComponent, OnTradingAvailabilityChanged), Z_Construct_UDelegateFunction_Echoes_OnTradingAvailabilityChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnTradingAvailabilityChanged_MetaData), NewProp_OnTradingAvailabilityChanged_MetaData) }; // 81228426
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPersistenceMarketComponent_Statics::NewProp_CachedTradingHubs_Inner = { "CachedTradingHubs", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UPersistenceMarketComponent_Statics::NewProp_CachedTradingHubs = { "CachedTradingHubs", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPersistenceMarketComponent, CachedTradingHubs), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CachedTradingHubs_MetaData), NewProp_CachedTradingHubs_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPersistenceMarketComponent_Statics::NewProp_MarketSubsystem = { "MarketSubsystem", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPersistenceMarketComponent, MarketSubsystem), Z_Construct_UClass_UEchoesMarketSubsystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MarketSubsystem_MetaData), NewProp_MarketSubsystem_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPersistenceMarketComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPersistenceMarketComponent_Statics::NewProp_TradingDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPersistenceMarketComponent_Statics::NewProp_ProximityCheckInterval,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPersistenceMarketComponent_Statics::NewProp_OnTradingAvailabilityChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPersistenceMarketComponent_Statics::NewProp_CachedTradingHubs_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPersistenceMarketComponent_Statics::NewProp_CachedTradingHubs,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPersistenceMarketComponent_Statics::NewProp_MarketSubsystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPersistenceMarketComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UPersistenceMarketComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPersistenceMarketComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UPersistenceMarketComponent_Statics::ClassParams = {
	&UPersistenceMarketComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UPersistenceMarketComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UPersistenceMarketComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPersistenceMarketComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UPersistenceMarketComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UPersistenceMarketComponent()
{
	if (!Z_Registration_Info_UClass_UPersistenceMarketComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPersistenceMarketComponent.OuterSingleton, Z_Construct_UClass_UPersistenceMarketComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UPersistenceMarketComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UPersistenceMarketComponent);
UPersistenceMarketComponent::~UPersistenceMarketComponent() {}
// ********** End Class UPersistenceMarketComponent ************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_PersistenceMarketComponent_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UPersistenceMarketComponent, UPersistenceMarketComponent::StaticClass, TEXT("UPersistenceMarketComponent"), &Z_Registration_Info_UClass_UPersistenceMarketComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPersistenceMarketComponent), 4138156799U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_PersistenceMarketComponent_h__Script_Echoes_553134947(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_PersistenceMarketComponent_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_PersistenceMarketComponent_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
