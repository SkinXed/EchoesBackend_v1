// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EchoesMainHUD.h"
#include "ShipStateInterface.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesMainHUD() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ECHOES_API UClass* Z_Construct_UClass_UEchoesMainHUD();
ECHOES_API UClass* Z_Construct_UClass_UEchoesMainHUD_NoRegister();
ECHOES_API UEnum* Z_Construct_UEnum_Echoes_EGameState();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnGameStateChanged__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnShipStatusUpdated__DelegateSignature();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FCommon_ShipDataStruct();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APlayerController_NoRegister();
UMG_API UClass* Z_Construct_UClass_UProgressBar_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
UMG_API UClass* Z_Construct_UClass_UWidgetSwitcher_NoRegister();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EGameState ****************************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EGameState;
static UEnum* EGameState_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EGameState.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EGameState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Echoes_EGameState, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("EGameState"));
	}
	return Z_Registration_Info_UEnum_EGameState.OuterSingleton;
}
template<> ECHOES_API UEnum* StaticEnum<EGameState>()
{
	return EGameState_StaticEnum();
}
struct Z_Construct_UEnum_Echoes_EGameState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Game state enum for HUD mode switching\n */" },
#endif
		{ "InHangar.Comment", "/** In station/hangar - showing fitting, inventory, social UI */" },
		{ "InHangar.DisplayName", "In Hangar" },
		{ "InHangar.Name", "EGameState::InHangar" },
		{ "InHangar.ToolTip", "In station/hangar - showing fitting, inventory, social UI" },
		{ "InSpace.Comment", "/** In space - showing navigation, targeting, overview UI */" },
		{ "InSpace.DisplayName", "In Space" },
		{ "InSpace.Name", "EGameState::InSpace" },
		{ "InSpace.ToolTip", "In space - showing navigation, targeting, overview UI" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesMainHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Game state enum for HUD mode switching" },
#endif
		{ "Unknown.Comment", "/** Unknown or transitioning state */" },
		{ "Unknown.DisplayName", "Unknown" },
		{ "Unknown.Name", "EGameState::Unknown" },
		{ "Unknown.ToolTip", "Unknown or transitioning state" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EGameState::InHangar", (int64)EGameState::InHangar },
		{ "EGameState::InSpace", (int64)EGameState::InSpace },
		{ "EGameState::Unknown", (int64)EGameState::Unknown },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Echoes_EGameState_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	"EGameState",
	"EGameState",
	Z_Construct_UEnum_Echoes_EGameState_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_Echoes_EGameState_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_Echoes_EGameState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_Echoes_EGameState_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_Echoes_EGameState()
{
	if (!Z_Registration_Info_UEnum_EGameState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EGameState.InnerSingleton, Z_Construct_UEnum_Echoes_EGameState_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EGameState.InnerSingleton;
}
// ********** End Enum EGameState ******************************************************************

// ********** Begin Delegate FOnGameStateChanged ***************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnGameStateChanged__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnGameStateChanged_Parms
	{
		EGameState NewState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Delegate for game state changed event\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesMainHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Delegate for game state changed event" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_NewState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NewState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_Echoes_OnGameStateChanged__DelegateSignature_Statics::NewProp_NewState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_Echoes_OnGameStateChanged__DelegateSignature_Statics::NewProp_NewState = { "NewState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnGameStateChanged_Parms, NewState), Z_Construct_UEnum_Echoes_EGameState, METADATA_PARAMS(0, nullptr) }; // 2564242070
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnGameStateChanged__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnGameStateChanged__DelegateSignature_Statics::NewProp_NewState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnGameStateChanged__DelegateSignature_Statics::NewProp_NewState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnGameStateChanged__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnGameStateChanged__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnGameStateChanged__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnGameStateChanged__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnGameStateChanged__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnGameStateChanged__DelegateSignature_Statics::_Script_Echoes_eventOnGameStateChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnGameStateChanged__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnGameStateChanged__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnGameStateChanged__DelegateSignature_Statics::_Script_Echoes_eventOnGameStateChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnGameStateChanged__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnGameStateChanged__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnGameStateChanged_DelegateWrapper(const FMulticastScriptDelegate& OnGameStateChanged, EGameState NewState)
{
	struct _Script_Echoes_eventOnGameStateChanged_Parms
	{
		EGameState NewState;
	};
	_Script_Echoes_eventOnGameStateChanged_Parms Parms;
	Parms.NewState=NewState;
	OnGameStateChanged.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnGameStateChanged *****************************************************

// ********** Begin Delegate FOnShipStatusUpdated **************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnShipStatusUpdated__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnShipStatusUpdated_Parms
	{
		FCommon_ShipDataStruct ShipData;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Delegate for ship status updated event\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesMainHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Delegate for ship status updated event" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShipData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ShipData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_Echoes_OnShipStatusUpdated__DelegateSignature_Statics::NewProp_ShipData = { "ShipData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnShipStatusUpdated_Parms, ShipData), Z_Construct_UScriptStruct_FCommon_ShipDataStruct, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShipData_MetaData), NewProp_ShipData_MetaData) }; // 4016673077
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnShipStatusUpdated__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnShipStatusUpdated__DelegateSignature_Statics::NewProp_ShipData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnShipStatusUpdated__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnShipStatusUpdated__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnShipStatusUpdated__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnShipStatusUpdated__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnShipStatusUpdated__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnShipStatusUpdated__DelegateSignature_Statics::_Script_Echoes_eventOnShipStatusUpdated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnShipStatusUpdated__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnShipStatusUpdated__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnShipStatusUpdated__DelegateSignature_Statics::_Script_Echoes_eventOnShipStatusUpdated_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnShipStatusUpdated__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnShipStatusUpdated__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnShipStatusUpdated_DelegateWrapper(const FMulticastScriptDelegate& OnShipStatusUpdated, FCommon_ShipDataStruct const& ShipData)
{
	struct _Script_Echoes_eventOnShipStatusUpdated_Parms
	{
		FCommon_ShipDataStruct ShipData;
	};
	_Script_Echoes_eventOnShipStatusUpdated_Parms Parms;
	Parms.ShipData=ShipData;
	OnShipStatusUpdated.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnShipStatusUpdated ****************************************************

// ********** Begin Class UEchoesMainHUD Function ClientOnly_RefreshAllDisplays ********************
struct Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_RefreshAllDisplays_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|HUD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Request full ship data update from ship interface\n\x09 * Queries the ship via IShipStateInterface and updates all displays\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesMainHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Request full ship data update from ship interface\nQueries the ship via IShipStateInterface and updates all displays" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_RefreshAllDisplays_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesMainHUD, nullptr, "ClientOnly_RefreshAllDisplays", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_RefreshAllDisplays_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_RefreshAllDisplays_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_RefreshAllDisplays()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_RefreshAllDisplays_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesMainHUD::execClientOnly_RefreshAllDisplays)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientOnly_RefreshAllDisplays();
	P_NATIVE_END;
}
// ********** End Class UEchoesMainHUD Function ClientOnly_RefreshAllDisplays **********************

// ********** Begin Class UEchoesMainHUD Function ClientOnly_UpdateCapacitor ***********************
struct Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateCapacitor_Statics
{
	struct EchoesMainHUD_eventClientOnly_UpdateCapacitor_Parms
	{
		float Current;
		float Max;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|HUD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Update capacitor display\n\x09 * \n\x09 * @param Current - Current capacitor value\n\x09 * @param Max - Maximum capacitor value\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesMainHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Update capacitor display\n\n@param Current - Current capacitor value\n@param Max - Maximum capacitor value" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Current;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Max;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateCapacitor_Statics::NewProp_Current = { "Current", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMainHUD_eventClientOnly_UpdateCapacitor_Parms, Current), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateCapacitor_Statics::NewProp_Max = { "Max", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMainHUD_eventClientOnly_UpdateCapacitor_Parms, Max), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateCapacitor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateCapacitor_Statics::NewProp_Current,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateCapacitor_Statics::NewProp_Max,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateCapacitor_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateCapacitor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesMainHUD, nullptr, "ClientOnly_UpdateCapacitor", Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateCapacitor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateCapacitor_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateCapacitor_Statics::EchoesMainHUD_eventClientOnly_UpdateCapacitor_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateCapacitor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateCapacitor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateCapacitor_Statics::EchoesMainHUD_eventClientOnly_UpdateCapacitor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateCapacitor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateCapacitor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesMainHUD::execClientOnly_UpdateCapacitor)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Current);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Max);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientOnly_UpdateCapacitor(Z_Param_Current,Z_Param_Max);
	P_NATIVE_END;
}
// ********** End Class UEchoesMainHUD Function ClientOnly_UpdateCapacitor *************************

// ********** Begin Class UEchoesMainHUD Function ClientOnly_UpdateShipStatus **********************
struct Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateShipStatus_Statics
{
	struct EchoesMainHUD_eventClientOnly_UpdateShipStatus_Parms
	{
		FCommon_ShipDataStruct ShipData;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|HUD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Update ship status display (Shield, Armor, Hull bars)\n\x09 * \n\x09 * @param ShipData - Ship data structure with current stats\n\x09 * \n\x09 * This function:\n\x09 * - Updates progress bars for Shield/Armor/Hull\n\x09 * - Updates text displays with current/max values\n\x09 * - Updates color coding based on health levels\n\x09 * - Broadcasts OnShipStatusUpdated for child widgets\n\x09 * \n\x09 * Note: Called by events, not Tick, for performance\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesMainHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Update ship status display (Shield, Armor, Hull bars)\n\n@param ShipData - Ship data structure with current stats\n\nThis function:\n- Updates progress bars for Shield/Armor/Hull\n- Updates text displays with current/max values\n- Updates color coding based on health levels\n- Broadcasts OnShipStatusUpdated for child widgets\n\nNote: Called by events, not Tick, for performance" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShipData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ShipData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateShipStatus_Statics::NewProp_ShipData = { "ShipData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMainHUD_eventClientOnly_UpdateShipStatus_Parms, ShipData), Z_Construct_UScriptStruct_FCommon_ShipDataStruct, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShipData_MetaData), NewProp_ShipData_MetaData) }; // 4016673077
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateShipStatus_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateShipStatus_Statics::NewProp_ShipData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateShipStatus_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateShipStatus_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesMainHUD, nullptr, "ClientOnly_UpdateShipStatus", Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateShipStatus_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateShipStatus_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateShipStatus_Statics::EchoesMainHUD_eventClientOnly_UpdateShipStatus_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateShipStatus_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateShipStatus_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateShipStatus_Statics::EchoesMainHUD_eventClientOnly_UpdateShipStatus_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateShipStatus()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateShipStatus_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesMainHUD::execClientOnly_UpdateShipStatus)
{
	P_GET_STRUCT_REF(FCommon_ShipDataStruct,Z_Param_Out_ShipData);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientOnly_UpdateShipStatus(Z_Param_Out_ShipData);
	P_NATIVE_END;
}
// ********** End Class UEchoesMainHUD Function ClientOnly_UpdateShipStatus ************************

// ********** Begin Class UEchoesMainHUD Function ClientOnly_UpdateSpeed ***************************
struct Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateSpeed_Statics
{
	struct EchoesMainHUD_eventClientOnly_UpdateSpeed_Parms
	{
		float Speed;
		float MaxSpeed;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|HUD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Update speed display\n\x09 * \n\x09 * @param Speed - Current speed in m/s\n\x09 * @param MaxSpeed - Maximum speed in m/s\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesMainHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Update speed display\n\n@param Speed - Current speed in m/s\n@param MaxSpeed - Maximum speed in m/s" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Speed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxSpeed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateSpeed_Statics::NewProp_Speed = { "Speed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMainHUD_eventClientOnly_UpdateSpeed_Parms, Speed), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateSpeed_Statics::NewProp_MaxSpeed = { "MaxSpeed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMainHUD_eventClientOnly_UpdateSpeed_Parms, MaxSpeed), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateSpeed_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateSpeed_Statics::NewProp_Speed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateSpeed_Statics::NewProp_MaxSpeed,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateSpeed_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateSpeed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesMainHUD, nullptr, "ClientOnly_UpdateSpeed", Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateSpeed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateSpeed_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateSpeed_Statics::EchoesMainHUD_eventClientOnly_UpdateSpeed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateSpeed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateSpeed_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateSpeed_Statics::EchoesMainHUD_eventClientOnly_UpdateSpeed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateSpeed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateSpeed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesMainHUD::execClientOnly_UpdateSpeed)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Speed);
	P_GET_PROPERTY(FFloatProperty,Z_Param_MaxSpeed);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientOnly_UpdateSpeed(Z_Param_Speed,Z_Param_MaxSpeed);
	P_NATIVE_END;
}
// ********** End Class UEchoesMainHUD Function ClientOnly_UpdateSpeed *****************************

// ********** Begin Class UEchoesMainHUD Function ClientOnly_UpdateTargetCount *********************
struct Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateTargetCount_Statics
{
	struct EchoesMainHUD_eventClientOnly_UpdateTargetCount_Parms
	{
		int32 Current;
		int32 Max;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|HUD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Update target count display\n\x09 * \n\x09 * @param Current - Current number of locked targets\n\x09 * @param Max - Maximum number of lockable targets\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesMainHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Update target count display\n\n@param Current - Current number of locked targets\n@param Max - Maximum number of lockable targets" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_Current;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Max;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateTargetCount_Statics::NewProp_Current = { "Current", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMainHUD_eventClientOnly_UpdateTargetCount_Parms, Current), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateTargetCount_Statics::NewProp_Max = { "Max", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMainHUD_eventClientOnly_UpdateTargetCount_Parms, Max), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateTargetCount_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateTargetCount_Statics::NewProp_Current,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateTargetCount_Statics::NewProp_Max,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateTargetCount_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateTargetCount_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesMainHUD, nullptr, "ClientOnly_UpdateTargetCount", Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateTargetCount_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateTargetCount_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateTargetCount_Statics::EchoesMainHUD_eventClientOnly_UpdateTargetCount_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateTargetCount_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateTargetCount_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateTargetCount_Statics::EchoesMainHUD_eventClientOnly_UpdateTargetCount_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateTargetCount()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateTargetCount_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesMainHUD::execClientOnly_UpdateTargetCount)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_Current);
	P_GET_PROPERTY(FIntProperty,Z_Param_Max);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientOnly_UpdateTargetCount(Z_Param_Current,Z_Param_Max);
	P_NATIVE_END;
}
// ********** End Class UEchoesMainHUD Function ClientOnly_UpdateTargetCount ***********************

// ********** Begin Class UEchoesMainHUD Function Common_FormatDistance ****************************
struct Z_Construct_UFunction_UEchoesMainHUD_Common_FormatDistance_Statics
{
	struct EchoesMainHUD_eventCommon_FormatDistance_Parms
	{
		float DistanceCm;
		FText ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|HUD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Format distance for display (converts cm to km if > 1km)\n\x09 * \n\x09 * @param DistanceCm - Distance in cm\n\x09 * @return Formatted text (e.g., \"2.5 km\" or \"450 m\")\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesMainHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Format distance for display (converts cm to km if > 1km)\n\n@param DistanceCm - Distance in cm\n@return Formatted text (e.g., \"2.5 km\" or \"450 m\")" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DistanceCm;
	static const UECodeGen_Private::FTextPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UEchoesMainHUD_Common_FormatDistance_Statics::NewProp_DistanceCm = { "DistanceCm", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMainHUD_eventCommon_FormatDistance_Parms, DistanceCm), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UEchoesMainHUD_Common_FormatDistance_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMainHUD_eventCommon_FormatDistance_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesMainHUD_Common_FormatDistance_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMainHUD_Common_FormatDistance_Statics::NewProp_DistanceCm,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMainHUD_Common_FormatDistance_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_Common_FormatDistance_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesMainHUD_Common_FormatDistance_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesMainHUD, nullptr, "Common_FormatDistance", Z_Construct_UFunction_UEchoesMainHUD_Common_FormatDistance_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_Common_FormatDistance_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesMainHUD_Common_FormatDistance_Statics::EchoesMainHUD_eventCommon_FormatDistance_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_Common_FormatDistance_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesMainHUD_Common_FormatDistance_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesMainHUD_Common_FormatDistance_Statics::EchoesMainHUD_eventCommon_FormatDistance_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesMainHUD_Common_FormatDistance()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesMainHUD_Common_FormatDistance_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesMainHUD::execCommon_FormatDistance)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_DistanceCm);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FText*)Z_Param__Result=P_THIS->Common_FormatDistance(Z_Param_DistanceCm);
	P_NATIVE_END;
}
// ********** End Class UEchoesMainHUD Function Common_FormatDistance ******************************

// ********** Begin Class UEchoesMainHUD Function Common_FormatSpeed *******************************
struct Z_Construct_UFunction_UEchoesMainHUD_Common_FormatSpeed_Statics
{
	struct EchoesMainHUD_eventCommon_FormatSpeed_Parms
	{
		float SpeedCmPerSec;
		FText ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|HUD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Format speed value for display (converts cm/s to m/s)\n\x09 * \n\x09 * @param SpeedCmPerSec - Speed in cm/s\n\x09 * @return Formatted text (e.g., \"125 m/s\")\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesMainHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Format speed value for display (converts cm/s to m/s)\n\n@param SpeedCmPerSec - Speed in cm/s\n@return Formatted text (e.g., \"125 m/s\")" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SpeedCmPerSec;
	static const UECodeGen_Private::FTextPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UEchoesMainHUD_Common_FormatSpeed_Statics::NewProp_SpeedCmPerSec = { "SpeedCmPerSec", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMainHUD_eventCommon_FormatSpeed_Parms, SpeedCmPerSec), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UEchoesMainHUD_Common_FormatSpeed_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMainHUD_eventCommon_FormatSpeed_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesMainHUD_Common_FormatSpeed_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMainHUD_Common_FormatSpeed_Statics::NewProp_SpeedCmPerSec,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMainHUD_Common_FormatSpeed_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_Common_FormatSpeed_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesMainHUD_Common_FormatSpeed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesMainHUD, nullptr, "Common_FormatSpeed", Z_Construct_UFunction_UEchoesMainHUD_Common_FormatSpeed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_Common_FormatSpeed_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesMainHUD_Common_FormatSpeed_Statics::EchoesMainHUD_eventCommon_FormatSpeed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_Common_FormatSpeed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesMainHUD_Common_FormatSpeed_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesMainHUD_Common_FormatSpeed_Statics::EchoesMainHUD_eventCommon_FormatSpeed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesMainHUD_Common_FormatSpeed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesMainHUD_Common_FormatSpeed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesMainHUD::execCommon_FormatSpeed)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_SpeedCmPerSec);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FText*)Z_Param__Result=P_THIS->Common_FormatSpeed(Z_Param_SpeedCmPerSec);
	P_NATIVE_END;
}
// ********** End Class UEchoesMainHUD Function Common_FormatSpeed *********************************

// ********** Begin Class UEchoesMainHUD Function Common_GetHealthBarColor *************************
struct Z_Construct_UFunction_UEchoesMainHUD_Common_GetHealthBarColor_Statics
{
	struct EchoesMainHUD_eventCommon_GetHealthBarColor_Parms
	{
		float Percentage;
		FLinearColor ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|HUD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get color for health bar based on percentage\n\x09 * \n\x09 * @param Percentage - Health percentage (0.0 to 1.0)\n\x09 * @return Color (Green > 50%, Yellow 25-50%, Red < 25%)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesMainHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get color for health bar based on percentage\n\n@param Percentage - Health percentage (0.0 to 1.0)\n@return Color (Green > 50%, Yellow 25-50%, Red < 25%)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Percentage;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UEchoesMainHUD_Common_GetHealthBarColor_Statics::NewProp_Percentage = { "Percentage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMainHUD_eventCommon_GetHealthBarColor_Parms, Percentage), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesMainHUD_Common_GetHealthBarColor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMainHUD_eventCommon_GetHealthBarColor_Parms, ReturnValue), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesMainHUD_Common_GetHealthBarColor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMainHUD_Common_GetHealthBarColor_Statics::NewProp_Percentage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMainHUD_Common_GetHealthBarColor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_Common_GetHealthBarColor_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesMainHUD_Common_GetHealthBarColor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesMainHUD, nullptr, "Common_GetHealthBarColor", Z_Construct_UFunction_UEchoesMainHUD_Common_GetHealthBarColor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_Common_GetHealthBarColor_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesMainHUD_Common_GetHealthBarColor_Statics::EchoesMainHUD_eventCommon_GetHealthBarColor_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_Common_GetHealthBarColor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesMainHUD_Common_GetHealthBarColor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesMainHUD_Common_GetHealthBarColor_Statics::EchoesMainHUD_eventCommon_GetHealthBarColor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesMainHUD_Common_GetHealthBarColor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesMainHUD_Common_GetHealthBarColor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesMainHUD::execCommon_GetHealthBarColor)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Percentage);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FLinearColor*)Z_Param__Result=P_THIS->Common_GetHealthBarColor(Z_Param_Percentage);
	P_NATIVE_END;
}
// ********** End Class UEchoesMainHUD Function Common_GetHealthBarColor ***************************

// ********** Begin Class UEchoesMainHUD Function Common_GetShipData *******************************
struct Z_Construct_UFunction_UEchoesMainHUD_Common_GetShipData_Statics
{
	struct EchoesMainHUD_eventCommon_GetShipData_Parms
	{
		FCommon_ShipDataStruct ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|HUD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get ship data from player's ship via interface\n\x09 * \n\x09 * @return Ship data structure, or default values if no ship\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesMainHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get ship data from player's ship via interface\n\n@return Ship data structure, or default values if no ship" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesMainHUD_Common_GetShipData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMainHUD_eventCommon_GetShipData_Parms, ReturnValue), Z_Construct_UScriptStruct_FCommon_ShipDataStruct, METADATA_PARAMS(0, nullptr) }; // 4016673077
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesMainHUD_Common_GetShipData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMainHUD_Common_GetShipData_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_Common_GetShipData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesMainHUD_Common_GetShipData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesMainHUD, nullptr, "Common_GetShipData", Z_Construct_UFunction_UEchoesMainHUD_Common_GetShipData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_Common_GetShipData_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesMainHUD_Common_GetShipData_Statics::EchoesMainHUD_eventCommon_GetShipData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_Common_GetShipData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesMainHUD_Common_GetShipData_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesMainHUD_Common_GetShipData_Statics::EchoesMainHUD_eventCommon_GetShipData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesMainHUD_Common_GetShipData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesMainHUD_Common_GetShipData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesMainHUD::execCommon_GetShipData)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FCommon_ShipDataStruct*)Z_Param__Result=P_THIS->Common_GetShipData();
	P_NATIVE_END;
}
// ********** End Class UEchoesMainHUD Function Common_GetShipData *********************************

// ********** Begin Class UEchoesMainHUD Function Common_GetTargetLeadIndicator ********************
struct Z_Construct_UFunction_UEchoesMainHUD_Common_GetTargetLeadIndicator_Statics
{
	struct EchoesMainHUD_eventCommon_GetTargetLeadIndicator_Parms
	{
		AActor* TargetActor;
		float ProjectileSpeed;
		FVector ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|HUD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Calculate target lead indicator position for aiming\n\x09 * \n\x09 * @param TargetActor - Target being aimed at\n\x09 * @param ProjectileSpeed - Speed of projectile in cm/s\n\x09 * @return World position where to aim for intercept\n\x09 * \n\x09 * This uses First-Order Intercept algorithm:\n\x09 * - Calculates where target will be when projectile arrives\n\x09 * - Returns 3D world position for reticle/indicator placement\n\x09 * - Returns target's current position if calculation fails\n\x09 * \n\x09 * Usage:\n\x09 * FVector LeadPos = HUD->Common_GetTargetLeadIndicator(Enemy, 50000.0f);\n\x09 * ProjectWorldLocationToWidgetPosition(LeadPos, ScreenPos);\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesMainHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Calculate target lead indicator position for aiming\n\n@param TargetActor - Target being aimed at\n@param ProjectileSpeed - Speed of projectile in cm/s\n@return World position where to aim for intercept\n\nThis uses First-Order Intercept algorithm:\n- Calculates where target will be when projectile arrives\n- Returns 3D world position for reticle/indicator placement\n- Returns target's current position if calculation fails\n\nUsage:\nFVector LeadPos = HUD->Common_GetTargetLeadIndicator(Enemy, 50000.0f);\nProjectWorldLocationToWidgetPosition(LeadPos, ScreenPos);" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetActor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ProjectileSpeed;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEchoesMainHUD_Common_GetTargetLeadIndicator_Statics::NewProp_TargetActor = { "TargetActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMainHUD_eventCommon_GetTargetLeadIndicator_Parms, TargetActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UEchoesMainHUD_Common_GetTargetLeadIndicator_Statics::NewProp_ProjectileSpeed = { "ProjectileSpeed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMainHUD_eventCommon_GetTargetLeadIndicator_Parms, ProjectileSpeed), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesMainHUD_Common_GetTargetLeadIndicator_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMainHUD_eventCommon_GetTargetLeadIndicator_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesMainHUD_Common_GetTargetLeadIndicator_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMainHUD_Common_GetTargetLeadIndicator_Statics::NewProp_TargetActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMainHUD_Common_GetTargetLeadIndicator_Statics::NewProp_ProjectileSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMainHUD_Common_GetTargetLeadIndicator_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_Common_GetTargetLeadIndicator_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesMainHUD_Common_GetTargetLeadIndicator_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesMainHUD, nullptr, "Common_GetTargetLeadIndicator", Z_Construct_UFunction_UEchoesMainHUD_Common_GetTargetLeadIndicator_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_Common_GetTargetLeadIndicator_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesMainHUD_Common_GetTargetLeadIndicator_Statics::EchoesMainHUD_eventCommon_GetTargetLeadIndicator_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_Common_GetTargetLeadIndicator_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesMainHUD_Common_GetTargetLeadIndicator_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesMainHUD_Common_GetTargetLeadIndicator_Statics::EchoesMainHUD_eventCommon_GetTargetLeadIndicator_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesMainHUD_Common_GetTargetLeadIndicator()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesMainHUD_Common_GetTargetLeadIndicator_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesMainHUD::execCommon_GetTargetLeadIndicator)
{
	P_GET_OBJECT(AActor,Z_Param_TargetActor);
	P_GET_PROPERTY(FFloatProperty,Z_Param_ProjectileSpeed);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector*)Z_Param__Result=P_THIS->Common_GetTargetLeadIndicator(Z_Param_TargetActor,Z_Param_ProjectileSpeed);
	P_NATIVE_END;
}
// ********** End Class UEchoesMainHUD Function Common_GetTargetLeadIndicator **********************

// ********** Begin Class UEchoesMainHUD Function Common_HasShipData *******************************
struct Z_Construct_UFunction_UEchoesMainHUD_Common_HasShipData_Statics
{
	struct EchoesMainHUD_eventCommon_HasShipData_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|HUD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if ship data is available\n\x09 * \n\x09 * @return True if player has ship with IShipStateInterface\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesMainHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if ship data is available\n\n@return True if player has ship with IShipStateInterface" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UEchoesMainHUD_Common_HasShipData_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((EchoesMainHUD_eventCommon_HasShipData_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UEchoesMainHUD_Common_HasShipData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EchoesMainHUD_eventCommon_HasShipData_Parms), &Z_Construct_UFunction_UEchoesMainHUD_Common_HasShipData_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesMainHUD_Common_HasShipData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMainHUD_Common_HasShipData_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_Common_HasShipData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesMainHUD_Common_HasShipData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesMainHUD, nullptr, "Common_HasShipData", Z_Construct_UFunction_UEchoesMainHUD_Common_HasShipData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_Common_HasShipData_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesMainHUD_Common_HasShipData_Statics::EchoesMainHUD_eventCommon_HasShipData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_Common_HasShipData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesMainHUD_Common_HasShipData_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesMainHUD_Common_HasShipData_Statics::EchoesMainHUD_eventCommon_HasShipData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesMainHUD_Common_HasShipData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesMainHUD_Common_HasShipData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesMainHUD::execCommon_HasShipData)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->Common_HasShipData();
	P_NATIVE_END;
}
// ********** End Class UEchoesMainHUD Function Common_HasShipData *********************************

// ********** Begin Class UEchoesMainHUD Function GetGameState *************************************
struct Z_Construct_UFunction_UEchoesMainHUD_GetGameState_Statics
{
	struct EchoesMainHUD_eventGetGameState_Parms
	{
		EGameState ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|HUD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get current game state\n\x09 * \n\x09 * @return Current game state\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesMainHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get current game state\n\n@return Current game state" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UEchoesMainHUD_GetGameState_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UEchoesMainHUD_GetGameState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMainHUD_eventGetGameState_Parms, ReturnValue), Z_Construct_UEnum_Echoes_EGameState, METADATA_PARAMS(0, nullptr) }; // 2564242070
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesMainHUD_GetGameState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMainHUD_GetGameState_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMainHUD_GetGameState_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_GetGameState_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesMainHUD_GetGameState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesMainHUD, nullptr, "GetGameState", Z_Construct_UFunction_UEchoesMainHUD_GetGameState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_GetGameState_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesMainHUD_GetGameState_Statics::EchoesMainHUD_eventGetGameState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_GetGameState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesMainHUD_GetGameState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesMainHUD_GetGameState_Statics::EchoesMainHUD_eventGetGameState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesMainHUD_GetGameState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesMainHUD_GetGameState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesMainHUD::execGetGameState)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EGameState*)Z_Param__Result=P_THIS->GetGameState();
	P_NATIVE_END;
}
// ********** End Class UEchoesMainHUD Function GetGameState ***************************************

// ********** Begin Class UEchoesMainHUD Function IsInHangar ***************************************
struct Z_Construct_UFunction_UEchoesMainHUD_IsInHangar_Statics
{
	struct EchoesMainHUD_eventIsInHangar_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|HUD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if currently in hangar\n\x09 * \n\x09 * @return True if in hangar mode\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesMainHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if currently in hangar\n\n@return True if in hangar mode" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UEchoesMainHUD_IsInHangar_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((EchoesMainHUD_eventIsInHangar_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UEchoesMainHUD_IsInHangar_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EchoesMainHUD_eventIsInHangar_Parms), &Z_Construct_UFunction_UEchoesMainHUD_IsInHangar_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesMainHUD_IsInHangar_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMainHUD_IsInHangar_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_IsInHangar_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesMainHUD_IsInHangar_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesMainHUD, nullptr, "IsInHangar", Z_Construct_UFunction_UEchoesMainHUD_IsInHangar_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_IsInHangar_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesMainHUD_IsInHangar_Statics::EchoesMainHUD_eventIsInHangar_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_IsInHangar_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesMainHUD_IsInHangar_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesMainHUD_IsInHangar_Statics::EchoesMainHUD_eventIsInHangar_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesMainHUD_IsInHangar()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesMainHUD_IsInHangar_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesMainHUD::execIsInHangar)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsInHangar();
	P_NATIVE_END;
}
// ********** End Class UEchoesMainHUD Function IsInHangar *****************************************

// ********** Begin Class UEchoesMainHUD Function IsInSpace ****************************************
struct Z_Construct_UFunction_UEchoesMainHUD_IsInSpace_Statics
{
	struct EchoesMainHUD_eventIsInSpace_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|HUD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if currently in space\n\x09 * \n\x09 * @return True if in space mode\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesMainHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if currently in space\n\n@return True if in space mode" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UEchoesMainHUD_IsInSpace_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((EchoesMainHUD_eventIsInSpace_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UEchoesMainHUD_IsInSpace_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EchoesMainHUD_eventIsInSpace_Parms), &Z_Construct_UFunction_UEchoesMainHUD_IsInSpace_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesMainHUD_IsInSpace_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMainHUD_IsInSpace_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_IsInSpace_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesMainHUD_IsInSpace_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesMainHUD, nullptr, "IsInSpace", Z_Construct_UFunction_UEchoesMainHUD_IsInSpace_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_IsInSpace_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesMainHUD_IsInSpace_Statics::EchoesMainHUD_eventIsInSpace_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_IsInSpace_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesMainHUD_IsInSpace_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesMainHUD_IsInSpace_Statics::EchoesMainHUD_eventIsInSpace_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesMainHUD_IsInSpace()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesMainHUD_IsInSpace_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesMainHUD::execIsInSpace)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsInSpace();
	P_NATIVE_END;
}
// ********** End Class UEchoesMainHUD Function IsInSpace ******************************************

// ********** Begin Class UEchoesMainHUD Function OnEnterHangar ************************************
static FName NAME_UEchoesMainHUD_OnEnterHangar = FName(TEXT("OnEnterHangar"));
void UEchoesMainHUD::OnEnterHangar()
{
	UFunction* Func = FindFunctionChecked(NAME_UEchoesMainHUD_OnEnterHangar);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_UEchoesMainHUD_OnEnterHangar_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|HUD|Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Blueprint event called when entering hangar\n\x09 * Use this to initialize hangar-specific UI\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesMainHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Blueprint event called when entering hangar\nUse this to initialize hangar-specific UI" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesMainHUD_OnEnterHangar_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesMainHUD, nullptr, "OnEnterHangar", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_OnEnterHangar_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesMainHUD_OnEnterHangar_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesMainHUD_OnEnterHangar()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesMainHUD_OnEnterHangar_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UEchoesMainHUD Function OnEnterHangar **************************************

// ********** Begin Class UEchoesMainHUD Function OnEnterSpace *************************************
static FName NAME_UEchoesMainHUD_OnEnterSpace = FName(TEXT("OnEnterSpace"));
void UEchoesMainHUD::OnEnterSpace()
{
	UFunction* Func = FindFunctionChecked(NAME_UEchoesMainHUD_OnEnterSpace);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_UEchoesMainHUD_OnEnterSpace_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|HUD|Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Blueprint event called when entering space\n\x09 * Use this to initialize space-specific UI\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesMainHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Blueprint event called when entering space\nUse this to initialize space-specific UI" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesMainHUD_OnEnterSpace_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesMainHUD, nullptr, "OnEnterSpace", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_OnEnterSpace_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesMainHUD_OnEnterSpace_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesMainHUD_OnEnterSpace()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesMainHUD_OnEnterSpace_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UEchoesMainHUD Function OnEnterSpace ***************************************

// ********** Begin Class UEchoesMainHUD Function OnShipDataChanged ********************************
struct EchoesMainHUD_eventOnShipDataChanged_Parms
{
	FCommon_ShipDataStruct NewData;
};
static FName NAME_UEchoesMainHUD_OnShipDataChanged = FName(TEXT("OnShipDataChanged"));
void UEchoesMainHUD::OnShipDataChanged(FCommon_ShipDataStruct const& NewData)
{
	EchoesMainHUD_eventOnShipDataChanged_Parms Parms;
	Parms.NewData=NewData;
	UFunction* Func = FindFunctionChecked(NAME_UEchoesMainHUD_OnShipDataChanged);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UEchoesMainHUD_OnShipDataChanged_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|HUD|Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Blueprint event called when ship data changes\n\x09 * Use this for custom UI updates\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesMainHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Blueprint event called when ship data changes\nUse this for custom UI updates" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NewData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_NewData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesMainHUD_OnShipDataChanged_Statics::NewProp_NewData = { "NewData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMainHUD_eventOnShipDataChanged_Parms, NewData), Z_Construct_UScriptStruct_FCommon_ShipDataStruct, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NewData_MetaData), NewProp_NewData_MetaData) }; // 4016673077
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesMainHUD_OnShipDataChanged_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMainHUD_OnShipDataChanged_Statics::NewProp_NewData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_OnShipDataChanged_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesMainHUD_OnShipDataChanged_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesMainHUD, nullptr, "OnShipDataChanged", Z_Construct_UFunction_UEchoesMainHUD_OnShipDataChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_OnShipDataChanged_Statics::PropPointers), sizeof(EchoesMainHUD_eventOnShipDataChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_OnShipDataChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesMainHUD_OnShipDataChanged_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(EchoesMainHUD_eventOnShipDataChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesMainHUD_OnShipDataChanged()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesMainHUD_OnShipDataChanged_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UEchoesMainHUD Function OnShipDataChanged **********************************

// ********** Begin Class UEchoesMainHUD Function OnShipStatsChanged *******************************
struct Z_Construct_UFunction_UEchoesMainHUD_OnShipStatsChanged_Statics
{
	struct EchoesMainHUD_eventOnShipStatsChanged_Parms
	{
		float ShieldPct;
		float ArmorPct;
		float StructPct;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Handle stats changed event from ship component\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesMainHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handle stats changed event from ship component" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ShieldPct;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ArmorPct;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_StructPct;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UEchoesMainHUD_OnShipStatsChanged_Statics::NewProp_ShieldPct = { "ShieldPct", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMainHUD_eventOnShipStatsChanged_Parms, ShieldPct), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UEchoesMainHUD_OnShipStatsChanged_Statics::NewProp_ArmorPct = { "ArmorPct", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMainHUD_eventOnShipStatsChanged_Parms, ArmorPct), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UEchoesMainHUD_OnShipStatsChanged_Statics::NewProp_StructPct = { "StructPct", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMainHUD_eventOnShipStatsChanged_Parms, StructPct), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesMainHUD_OnShipStatsChanged_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMainHUD_OnShipStatsChanged_Statics::NewProp_ShieldPct,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMainHUD_OnShipStatsChanged_Statics::NewProp_ArmorPct,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMainHUD_OnShipStatsChanged_Statics::NewProp_StructPct,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_OnShipStatsChanged_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesMainHUD_OnShipStatsChanged_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesMainHUD, nullptr, "OnShipStatsChanged", Z_Construct_UFunction_UEchoesMainHUD_OnShipStatsChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_OnShipStatsChanged_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesMainHUD_OnShipStatsChanged_Statics::EchoesMainHUD_eventOnShipStatsChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_OnShipStatsChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesMainHUD_OnShipStatsChanged_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesMainHUD_OnShipStatsChanged_Statics::EchoesMainHUD_eventOnShipStatsChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesMainHUD_OnShipStatsChanged()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesMainHUD_OnShipStatsChanged_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesMainHUD::execOnShipStatsChanged)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_ShieldPct);
	P_GET_PROPERTY(FFloatProperty,Z_Param_ArmorPct);
	P_GET_PROPERTY(FFloatProperty,Z_Param_StructPct);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnShipStatsChanged(Z_Param_ShieldPct,Z_Param_ArmorPct,Z_Param_StructPct);
	P_NATIVE_END;
}
// ********** End Class UEchoesMainHUD Function OnShipStatsChanged *********************************

// ********** Begin Class UEchoesMainHUD Function SetGameState *************************************
struct Z_Construct_UFunction_UEchoesMainHUD_SetGameState_Statics
{
	struct EchoesMainHUD_eventSetGameState_Parms
	{
		EGameState NewState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|HUD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Set current game state and switch HUD mode\n\x09 * \n\x09 * @param NewState - New game state (InHangar or InSpace)\n\x09 * \n\x09 * This function:\n\x09 * - Switches widget switcher to appropriate child widget\n\x09 * - Broadcasts OnGameStateChanged event\n\x09 * - Updates UI visibility and layout\n\x09 * - Initializes state-specific widgets if needed\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesMainHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set current game state and switch HUD mode\n\n@param NewState - New game state (InHangar or InSpace)\n\nThis function:\n- Switches widget switcher to appropriate child widget\n- Broadcasts OnGameStateChanged event\n- Updates UI visibility and layout\n- Initializes state-specific widgets if needed" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_NewState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NewState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UEchoesMainHUD_SetGameState_Statics::NewProp_NewState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UEchoesMainHUD_SetGameState_Statics::NewProp_NewState = { "NewState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMainHUD_eventSetGameState_Parms, NewState), Z_Construct_UEnum_Echoes_EGameState, METADATA_PARAMS(0, nullptr) }; // 2564242070
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesMainHUD_SetGameState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMainHUD_SetGameState_Statics::NewProp_NewState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMainHUD_SetGameState_Statics::NewProp_NewState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_SetGameState_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesMainHUD_SetGameState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesMainHUD, nullptr, "SetGameState", Z_Construct_UFunction_UEchoesMainHUD_SetGameState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_SetGameState_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesMainHUD_SetGameState_Statics::EchoesMainHUD_eventSetGameState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMainHUD_SetGameState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesMainHUD_SetGameState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesMainHUD_SetGameState_Statics::EchoesMainHUD_eventSetGameState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesMainHUD_SetGameState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesMainHUD_SetGameState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesMainHUD::execSetGameState)
{
	P_GET_ENUM(EGameState,Z_Param_NewState);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetGameState(EGameState(Z_Param_NewState));
	P_NATIVE_END;
}
// ********** End Class UEchoesMainHUD Function SetGameState ***************************************

// ********** Begin Class UEchoesMainHUD ***********************************************************
void UEchoesMainHUD::StaticRegisterNativesUEchoesMainHUD()
{
	UClass* Class = UEchoesMainHUD::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ClientOnly_RefreshAllDisplays", &UEchoesMainHUD::execClientOnly_RefreshAllDisplays },
		{ "ClientOnly_UpdateCapacitor", &UEchoesMainHUD::execClientOnly_UpdateCapacitor },
		{ "ClientOnly_UpdateShipStatus", &UEchoesMainHUD::execClientOnly_UpdateShipStatus },
		{ "ClientOnly_UpdateSpeed", &UEchoesMainHUD::execClientOnly_UpdateSpeed },
		{ "ClientOnly_UpdateTargetCount", &UEchoesMainHUD::execClientOnly_UpdateTargetCount },
		{ "Common_FormatDistance", &UEchoesMainHUD::execCommon_FormatDistance },
		{ "Common_FormatSpeed", &UEchoesMainHUD::execCommon_FormatSpeed },
		{ "Common_GetHealthBarColor", &UEchoesMainHUD::execCommon_GetHealthBarColor },
		{ "Common_GetShipData", &UEchoesMainHUD::execCommon_GetShipData },
		{ "Common_GetTargetLeadIndicator", &UEchoesMainHUD::execCommon_GetTargetLeadIndicator },
		{ "Common_HasShipData", &UEchoesMainHUD::execCommon_HasShipData },
		{ "GetGameState", &UEchoesMainHUD::execGetGameState },
		{ "IsInHangar", &UEchoesMainHUD::execIsInHangar },
		{ "IsInSpace", &UEchoesMainHUD::execIsInSpace },
		{ "OnShipStatsChanged", &UEchoesMainHUD::execOnShipStatsChanged },
		{ "SetGameState", &UEchoesMainHUD::execSetGameState },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UEchoesMainHUD;
UClass* UEchoesMainHUD::GetPrivateStaticClass()
{
	using TClass = UEchoesMainHUD;
	if (!Z_Registration_Info_UClass_UEchoesMainHUD.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesMainHUD"),
			Z_Registration_Info_UClass_UEchoesMainHUD.InnerSingleton,
			StaticRegisterNativesUEchoesMainHUD,
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
	return Z_Registration_Info_UClass_UEchoesMainHUD.InnerSingleton;
}
UClass* Z_Construct_UClass_UEchoesMainHUD_NoRegister()
{
	return UEchoesMainHUD::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UEchoesMainHUD_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * UEchoesMainHUD\n * \n * Main HUD widget for EVE-like MMO interface\n * Manages two distinct UI states: Hangar Mode and Space Mode\n * \n * Architecture:\n * - Widget Switcher: Root container that switches between Hangar and Space layouts\n *   - HangarHUD Widget: Station interface (fitting, inventory, social)\n *   - SpaceHUD Widget: Space interface (navigation, targeting, overview, shields)\n * \n * State Management:\n * - InHangar: Player is docked at station, shows hangar interface\n * - InSpace: Player is in space, shows space navigation and combat interface\n * - State changes triggered by docking/undocking events\n * \n * Data Flow:\n * - Ship data obtained via IShipStateInterface from player's ship pawn\n * - Event-driven updates (no Tick) for performance\n * - Invalidation boxes for static elements\n * - Delegates for UI synchronization\n * \n * Optimization:\n * - No Tick function - uses event-driven updates\n * - Invalidation boxes for static UI elements\n * - Lazy widget creation (spawned on demand)\n * - Cached component references\n * \n * Usage:\n * // Create and add to viewport\n * UEchoesMainHUD* HUD = CreateWidget<UEchoesMainHUD>(PlayerController, HUDClass);\n * HUD->AddToViewport();\n * \n * // Switch states\n * HUD->SetGameState(EGameState::InSpace);\n * \n * // Bind to state changes\n * HUD->OnGameStateChanged.AddDynamic(this, &APlayerController::HandleStateChange);\n */" },
#endif
		{ "IncludePath", "UI/Widgets/EchoesMainHUD.h" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesMainHUD.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UEchoesMainHUD\n\nMain HUD widget for EVE-like MMO interface\nManages two distinct UI states: Hangar Mode and Space Mode\n\nArchitecture:\n- Widget Switcher: Root container that switches between Hangar and Space layouts\n  - HangarHUD Widget: Station interface (fitting, inventory, social)\n  - SpaceHUD Widget: Space interface (navigation, targeting, overview, shields)\n\nState Management:\n- InHangar: Player is docked at station, shows hangar interface\n- InSpace: Player is in space, shows space navigation and combat interface\n- State changes triggered by docking/undocking events\n\nData Flow:\n- Ship data obtained via IShipStateInterface from player's ship pawn\n- Event-driven updates (no Tick) for performance\n- Invalidation boxes for static elements\n- Delegates for UI synchronization\n\nOptimization:\n- No Tick function - uses event-driven updates\n- Invalidation boxes for static UI elements\n- Lazy widget creation (spawned on demand)\n- Cached component references\n\nUsage:\n// Create and add to viewport\nUEchoesMainHUD* HUD = CreateWidget<UEchoesMainHUD>(PlayerController, HUDClass);\nHUD->AddToViewport();\n\n// Switch states\nHUD->SetGameState(EGameState::InSpace);\n\n// Bind to state changes\nHUD->OnGameStateChanged.AddDynamic(this, &APlayerController::HandleStateChange);" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnGameStateChanged_MetaData[] = {
		{ "Category", "Echoes|HUD|Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Called when game state changes (InHangar <-> InSpace)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesMainHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when game state changes (InHangar <-> InSpace)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnShipStatusUpdated_MetaData[] = {
		{ "Category", "Echoes|HUD|Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Called when ship status is updated\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesMainHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when ship status is updated" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ModeSwitcher_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "Echoes|HUD|Widgets" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Widget switcher for Hangar/Space modes\n\x09 * Index 0 = HangarHUD, Index 1 = SpaceHUD\n\x09 */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesMainHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Widget switcher for Hangar/Space modes\nIndex 0 = HangarHUD, Index 1 = SpaceHUD" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HangarHUD_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "Echoes|HUD|Widgets" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Hangar HUD widget (index 0 in switcher)\n\x09 * Contains: Fitting screen, Inventory, Social panel, Station services\n\x09 */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesMainHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Hangar HUD widget (index 0 in switcher)\nContains: Fitting screen, Inventory, Social panel, Station services" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpaceHUD_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "Echoes|HUD|Widgets" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Space HUD widget (index 1 in switcher)\n\x09 * Contains: Target panel, Overview, Shield/Armor/Hull bars, Navigation\n\x09 */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesMainHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Space HUD widget (index 1 in switcher)\nContains: Target panel, Overview, Shield/Armor/Hull bars, Navigation" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShieldBar_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "Echoes|HUD|Ship Status" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Shield progress bar\n\x09 */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesMainHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shield progress bar" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ArmorBar_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "Echoes|HUD|Ship Status" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Armor progress bar\n\x09 */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesMainHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Armor progress bar" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HullBar_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "Echoes|HUD|Ship Status" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Structure/Hull progress bar\n\x09 */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesMainHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Structure/Hull progress bar" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CapacitorBar_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "Echoes|HUD|Ship Status" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Capacitor progress bar\n\x09 */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesMainHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Capacitor progress bar" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShieldText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "Echoes|HUD|Ship Status" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Shield value text (e.g., \"500/1000\")\n\x09 */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesMainHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shield value text (e.g., \"500/1000\")" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ArmorText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "Echoes|HUD|Ship Status" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Armor value text\n\x09 */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesMainHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Armor value text" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HullText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "Echoes|HUD|Ship Status" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Hull value text\n\x09 */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesMainHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Hull value text" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpeedText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "Echoes|HUD|Ship Status" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Speed value text (e.g., \"125 m/s\")\n\x09 */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesMainHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Speed value text (e.g., \"125 m/s\")" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetCountText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "Echoes|HUD|Ship Status" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Target count text (e.g., \"3/5\")\n\x09 */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesMainHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Target count text (e.g., \"3/5\")" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShipStatusUpdateRate_MetaData[] = {
		{ "Category", "Echoes|HUD|Config" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Update rate for ship status in seconds\n\x09 * Default: 0.1 (10 times per second)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesMainHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Update rate for ship status in seconds\nDefault: 0.1 (10 times per second)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowDebugInfo_MetaData[] = {
		{ "Category", "Echoes|HUD|Config" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Enable debug display\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesMainHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Enable debug display" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InitialGameState_MetaData[] = {
		{ "Category", "Echoes|HUD|Config" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Initial game state\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesMainHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Initial game state" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CachedPlayerController_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Cached player controller */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesMainHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cached player controller" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CachedShipPawn_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Cached ship pawn */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesMainHUD.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cached ship pawn" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnGameStateChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnShipStatusUpdated;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ModeSwitcher;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HangarHUD;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpaceHUD;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ShieldBar;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ArmorBar;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HullBar;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CapacitorBar;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ShieldText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ArmorText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HullText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpeedText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetCountText;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ShipStatusUpdateRate;
	static void NewProp_bShowDebugInfo_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowDebugInfo;
	static const UECodeGen_Private::FBytePropertyParams NewProp_InitialGameState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InitialGameState;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CachedPlayerController;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CachedShipPawn;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_RefreshAllDisplays, "ClientOnly_RefreshAllDisplays" }, // 746298649
		{ &Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateCapacitor, "ClientOnly_UpdateCapacitor" }, // 2469146801
		{ &Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateShipStatus, "ClientOnly_UpdateShipStatus" }, // 1373796732
		{ &Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateSpeed, "ClientOnly_UpdateSpeed" }, // 748390456
		{ &Z_Construct_UFunction_UEchoesMainHUD_ClientOnly_UpdateTargetCount, "ClientOnly_UpdateTargetCount" }, // 2006642460
		{ &Z_Construct_UFunction_UEchoesMainHUD_Common_FormatDistance, "Common_FormatDistance" }, // 3885438717
		{ &Z_Construct_UFunction_UEchoesMainHUD_Common_FormatSpeed, "Common_FormatSpeed" }, // 3121579741
		{ &Z_Construct_UFunction_UEchoesMainHUD_Common_GetHealthBarColor, "Common_GetHealthBarColor" }, // 1784871240
		{ &Z_Construct_UFunction_UEchoesMainHUD_Common_GetShipData, "Common_GetShipData" }, // 1459057751
		{ &Z_Construct_UFunction_UEchoesMainHUD_Common_GetTargetLeadIndicator, "Common_GetTargetLeadIndicator" }, // 2892596685
		{ &Z_Construct_UFunction_UEchoesMainHUD_Common_HasShipData, "Common_HasShipData" }, // 1413262648
		{ &Z_Construct_UFunction_UEchoesMainHUD_GetGameState, "GetGameState" }, // 483264211
		{ &Z_Construct_UFunction_UEchoesMainHUD_IsInHangar, "IsInHangar" }, // 449774152
		{ &Z_Construct_UFunction_UEchoesMainHUD_IsInSpace, "IsInSpace" }, // 138539539
		{ &Z_Construct_UFunction_UEchoesMainHUD_OnEnterHangar, "OnEnterHangar" }, // 1141202850
		{ &Z_Construct_UFunction_UEchoesMainHUD_OnEnterSpace, "OnEnterSpace" }, // 3755525738
		{ &Z_Construct_UFunction_UEchoesMainHUD_OnShipDataChanged, "OnShipDataChanged" }, // 2498672052
		{ &Z_Construct_UFunction_UEchoesMainHUD_OnShipStatsChanged, "OnShipStatsChanged" }, // 1556640440
		{ &Z_Construct_UFunction_UEchoesMainHUD_SetGameState, "SetGameState" }, // 1536044324
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEchoesMainHUD>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEchoesMainHUD_Statics::NewProp_OnGameStateChanged = { "OnGameStateChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesMainHUD, OnGameStateChanged), Z_Construct_UDelegateFunction_Echoes_OnGameStateChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnGameStateChanged_MetaData), NewProp_OnGameStateChanged_MetaData) }; // 3631291439
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEchoesMainHUD_Statics::NewProp_OnShipStatusUpdated = { "OnShipStatusUpdated", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesMainHUD, OnShipStatusUpdated), Z_Construct_UDelegateFunction_Echoes_OnShipStatusUpdated__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnShipStatusUpdated_MetaData), NewProp_OnShipStatusUpdated_MetaData) }; // 4031724149
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesMainHUD_Statics::NewProp_ModeSwitcher = { "ModeSwitcher", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesMainHUD, ModeSwitcher), Z_Construct_UClass_UWidgetSwitcher_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ModeSwitcher_MetaData), NewProp_ModeSwitcher_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesMainHUD_Statics::NewProp_HangarHUD = { "HangarHUD", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesMainHUD, HangarHUD), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HangarHUD_MetaData), NewProp_HangarHUD_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesMainHUD_Statics::NewProp_SpaceHUD = { "SpaceHUD", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesMainHUD, SpaceHUD), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpaceHUD_MetaData), NewProp_SpaceHUD_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesMainHUD_Statics::NewProp_ShieldBar = { "ShieldBar", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesMainHUD, ShieldBar), Z_Construct_UClass_UProgressBar_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShieldBar_MetaData), NewProp_ShieldBar_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesMainHUD_Statics::NewProp_ArmorBar = { "ArmorBar", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesMainHUD, ArmorBar), Z_Construct_UClass_UProgressBar_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ArmorBar_MetaData), NewProp_ArmorBar_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesMainHUD_Statics::NewProp_HullBar = { "HullBar", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesMainHUD, HullBar), Z_Construct_UClass_UProgressBar_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HullBar_MetaData), NewProp_HullBar_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesMainHUD_Statics::NewProp_CapacitorBar = { "CapacitorBar", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesMainHUD, CapacitorBar), Z_Construct_UClass_UProgressBar_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CapacitorBar_MetaData), NewProp_CapacitorBar_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesMainHUD_Statics::NewProp_ShieldText = { "ShieldText", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesMainHUD, ShieldText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShieldText_MetaData), NewProp_ShieldText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesMainHUD_Statics::NewProp_ArmorText = { "ArmorText", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesMainHUD, ArmorText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ArmorText_MetaData), NewProp_ArmorText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesMainHUD_Statics::NewProp_HullText = { "HullText", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesMainHUD, HullText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HullText_MetaData), NewProp_HullText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesMainHUD_Statics::NewProp_SpeedText = { "SpeedText", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesMainHUD, SpeedText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpeedText_MetaData), NewProp_SpeedText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesMainHUD_Statics::NewProp_TargetCountText = { "TargetCountText", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesMainHUD, TargetCountText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetCountText_MetaData), NewProp_TargetCountText_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEchoesMainHUD_Statics::NewProp_ShipStatusUpdateRate = { "ShipStatusUpdateRate", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesMainHUD, ShipStatusUpdateRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShipStatusUpdateRate_MetaData), NewProp_ShipStatusUpdateRate_MetaData) };
void Z_Construct_UClass_UEchoesMainHUD_Statics::NewProp_bShowDebugInfo_SetBit(void* Obj)
{
	((UEchoesMainHUD*)Obj)->bShowDebugInfo = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UEchoesMainHUD_Statics::NewProp_bShowDebugInfo = { "bShowDebugInfo", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UEchoesMainHUD), &Z_Construct_UClass_UEchoesMainHUD_Statics::NewProp_bShowDebugInfo_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowDebugInfo_MetaData), NewProp_bShowDebugInfo_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UEchoesMainHUD_Statics::NewProp_InitialGameState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UEchoesMainHUD_Statics::NewProp_InitialGameState = { "InitialGameState", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesMainHUD, InitialGameState), Z_Construct_UEnum_Echoes_EGameState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InitialGameState_MetaData), NewProp_InitialGameState_MetaData) }; // 2564242070
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesMainHUD_Statics::NewProp_CachedPlayerController = { "CachedPlayerController", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesMainHUD, CachedPlayerController), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CachedPlayerController_MetaData), NewProp_CachedPlayerController_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesMainHUD_Statics::NewProp_CachedShipPawn = { "CachedShipPawn", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesMainHUD, CachedShipPawn), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CachedShipPawn_MetaData), NewProp_CachedShipPawn_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEchoesMainHUD_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMainHUD_Statics::NewProp_OnGameStateChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMainHUD_Statics::NewProp_OnShipStatusUpdated,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMainHUD_Statics::NewProp_ModeSwitcher,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMainHUD_Statics::NewProp_HangarHUD,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMainHUD_Statics::NewProp_SpaceHUD,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMainHUD_Statics::NewProp_ShieldBar,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMainHUD_Statics::NewProp_ArmorBar,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMainHUD_Statics::NewProp_HullBar,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMainHUD_Statics::NewProp_CapacitorBar,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMainHUD_Statics::NewProp_ShieldText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMainHUD_Statics::NewProp_ArmorText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMainHUD_Statics::NewProp_HullText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMainHUD_Statics::NewProp_SpeedText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMainHUD_Statics::NewProp_TargetCountText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMainHUD_Statics::NewProp_ShipStatusUpdateRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMainHUD_Statics::NewProp_bShowDebugInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMainHUD_Statics::NewProp_InitialGameState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMainHUD_Statics::NewProp_InitialGameState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMainHUD_Statics::NewProp_CachedPlayerController,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMainHUD_Statics::NewProp_CachedShipPawn,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesMainHUD_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UEchoesMainHUD_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesMainHUD_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEchoesMainHUD_Statics::ClassParams = {
	&UEchoesMainHUD::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UEchoesMainHUD_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesMainHUD_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesMainHUD_Statics::Class_MetaDataParams), Z_Construct_UClass_UEchoesMainHUD_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEchoesMainHUD()
{
	if (!Z_Registration_Info_UClass_UEchoesMainHUD.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEchoesMainHUD.OuterSingleton, Z_Construct_UClass_UEchoesMainHUD_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEchoesMainHUD.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UEchoesMainHUD);
UEchoesMainHUD::~UEchoesMainHUD() {}
// ********** End Class UEchoesMainHUD *************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMainHUD_h__Script_Echoes_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EGameState_StaticEnum, TEXT("EGameState"), &Z_Registration_Info_UEnum_EGameState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2564242070U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEchoesMainHUD, UEchoesMainHUD::StaticClass, TEXT("UEchoesMainHUD"), &Z_Registration_Info_UClass_UEchoesMainHUD, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEchoesMainHUD), 79208251U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMainHUD_h__Script_Echoes_3781525235(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMainHUD_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMainHUD_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMainHUD_h__Script_Echoes_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMainHUD_h__Script_Echoes_Statics::EnumInfo));
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
