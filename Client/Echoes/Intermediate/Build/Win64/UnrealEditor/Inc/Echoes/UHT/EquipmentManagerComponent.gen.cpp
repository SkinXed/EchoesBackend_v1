// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EquipmentManagerComponent.h"
#include "ShipFittingInterface.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEquipmentManagerComponent() {}

// ********** Begin Cross Module References ********************************************************
ECHOES_API UClass* Z_Construct_UClass_UEquipmentManagerComponent();
ECHOES_API UClass* Z_Construct_UClass_UEquipmentManagerComponent_NoRegister();
ECHOES_API UEnum* Z_Construct_UEnum_Echoes_EModuleActivationResult();
ECHOES_API UEnum* Z_Construct_UEnum_Echoes_EModuleState();
ECHOES_API UEnum* Z_Construct_UEnum_Echoes_ESlotType();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnCapacitorChanged__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnEquipmentChanged__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnModuleStateChanged__DelegateSignature();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FCommon_ItemSlot();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FCommon_ShipFittingData();
ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APlayerController_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FOnModuleStateChanged *************************************************
struct Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnModuleStateChanged__DelegateSignature_Statics
{
	struct EquipmentManagerComponent_eventOnModuleStateChanged_Parms
	{
		ESlotType SlotType;
		int32 SlotIndex;
		EModuleState NewState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when module state changes */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/EquipmentManagerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when module state changes" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_SlotType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SlotType;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static const UECodeGen_Private::FBytePropertyParams NewProp_NewState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NewState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnModuleStateChanged__DelegateSignature_Statics::NewProp_SlotType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnModuleStateChanged__DelegateSignature_Statics::NewProp_SlotType = { "SlotType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EquipmentManagerComponent_eventOnModuleStateChanged_Parms, SlotType), Z_Construct_UEnum_Echoes_ESlotType, METADATA_PARAMS(0, nullptr) }; // 780113368
const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnModuleStateChanged__DelegateSignature_Statics::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EquipmentManagerComponent_eventOnModuleStateChanged_Parms, SlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnModuleStateChanged__DelegateSignature_Statics::NewProp_NewState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnModuleStateChanged__DelegateSignature_Statics::NewProp_NewState = { "NewState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EquipmentManagerComponent_eventOnModuleStateChanged_Parms, NewState), Z_Construct_UEnum_Echoes_EModuleState, METADATA_PARAMS(0, nullptr) }; // 1837800180
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnModuleStateChanged__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnModuleStateChanged__DelegateSignature_Statics::NewProp_SlotType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnModuleStateChanged__DelegateSignature_Statics::NewProp_SlotType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnModuleStateChanged__DelegateSignature_Statics::NewProp_SlotIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnModuleStateChanged__DelegateSignature_Statics::NewProp_NewState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnModuleStateChanged__DelegateSignature_Statics::NewProp_NewState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnModuleStateChanged__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnModuleStateChanged__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEquipmentManagerComponent, nullptr, "OnModuleStateChanged__DelegateSignature", Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnModuleStateChanged__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnModuleStateChanged__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnModuleStateChanged__DelegateSignature_Statics::EquipmentManagerComponent_eventOnModuleStateChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnModuleStateChanged__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnModuleStateChanged__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnModuleStateChanged__DelegateSignature_Statics::EquipmentManagerComponent_eventOnModuleStateChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnModuleStateChanged__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnModuleStateChanged__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void UEquipmentManagerComponent::FOnModuleStateChanged_DelegateWrapper(const FMulticastScriptDelegate& OnModuleStateChanged, ESlotType SlotType, int32 SlotIndex, EModuleState NewState)
{
	struct EquipmentManagerComponent_eventOnModuleStateChanged_Parms
	{
		ESlotType SlotType;
		int32 SlotIndex;
		EModuleState NewState;
	};
	EquipmentManagerComponent_eventOnModuleStateChanged_Parms Parms;
	Parms.SlotType=SlotType;
	Parms.SlotIndex=SlotIndex;
	Parms.NewState=NewState;
	OnModuleStateChanged.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnModuleStateChanged ***************************************************

// ********** Begin Delegate FOnCapacitorChanged ***************************************************
struct Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnCapacitorChanged__DelegateSignature_Statics
{
	struct EquipmentManagerComponent_eventOnCapacitorChanged_Parms
	{
		float Current;
		float Max;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when capacitor changes */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/EquipmentManagerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when capacitor changes" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Current;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Max;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnCapacitorChanged__DelegateSignature_Statics::NewProp_Current = { "Current", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EquipmentManagerComponent_eventOnCapacitorChanged_Parms, Current), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnCapacitorChanged__DelegateSignature_Statics::NewProp_Max = { "Max", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EquipmentManagerComponent_eventOnCapacitorChanged_Parms, Max), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnCapacitorChanged__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnCapacitorChanged__DelegateSignature_Statics::NewProp_Current,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnCapacitorChanged__DelegateSignature_Statics::NewProp_Max,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnCapacitorChanged__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnCapacitorChanged__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEquipmentManagerComponent, nullptr, "OnCapacitorChanged__DelegateSignature", Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnCapacitorChanged__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnCapacitorChanged__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnCapacitorChanged__DelegateSignature_Statics::EquipmentManagerComponent_eventOnCapacitorChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnCapacitorChanged__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnCapacitorChanged__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnCapacitorChanged__DelegateSignature_Statics::EquipmentManagerComponent_eventOnCapacitorChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnCapacitorChanged__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnCapacitorChanged__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void UEquipmentManagerComponent::FOnCapacitorChanged_DelegateWrapper(const FMulticastScriptDelegate& OnCapacitorChanged, float Current, float Max)
{
	struct EquipmentManagerComponent_eventOnCapacitorChanged_Parms
	{
		float Current;
		float Max;
	};
	EquipmentManagerComponent_eventOnCapacitorChanged_Parms Parms;
	Parms.Current=Current;
	Parms.Max=Max;
	OnCapacitorChanged.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnCapacitorChanged *****************************************************

// ********** Begin Delegate FOnEquipmentChanged ***************************************************
struct Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnEquipmentChanged__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when equipment changes (for IEquipmentObserver implementations) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/EquipmentManagerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when equipment changes (for IEquipmentObserver implementations)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnEquipmentChanged__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEquipmentManagerComponent, nullptr, "OnEquipmentChanged__DelegateSignature", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnEquipmentChanged__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnEquipmentChanged__DelegateSignature_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnEquipmentChanged__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnEquipmentChanged__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void UEquipmentManagerComponent::FOnEquipmentChanged_DelegateWrapper(const FMulticastScriptDelegate& OnEquipmentChanged)
{
	OnEquipmentChanged.ProcessMulticastDelegate<UObject>(NULL);
}
// ********** End Delegate FOnEquipmentChanged *****************************************************

// ********** Begin Class UEquipmentManagerComponent Function ClientRPC_NotifyModuleActivation *****
struct EquipmentManagerComponent_eventClientRPC_NotifyModuleActivation_Parms
{
	ESlotType SlotType;
	int32 SlotIndex;
	EModuleActivationResult Result;
};
static FName NAME_UEquipmentManagerComponent_ClientRPC_NotifyModuleActivation = FName(TEXT("ClientRPC_NotifyModuleActivation"));
void UEquipmentManagerComponent::ClientRPC_NotifyModuleActivation(ESlotType SlotType, int32 SlotIndex, EModuleActivationResult Result)
{
	EquipmentManagerComponent_eventClientRPC_NotifyModuleActivation_Parms Parms;
	Parms.SlotType=SlotType;
	Parms.SlotIndex=SlotIndex;
	Parms.Result=Result;
	UFunction* Func = FindFunctionChecked(NAME_UEquipmentManagerComponent_ClientRPC_NotifyModuleActivation);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_NotifyModuleActivation_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Equipment" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Notify Module Activation Result\n\x09 * Informs client of activation success/failure\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/EquipmentManagerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Notify Module Activation Result\nInforms client of activation success/failure" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_SlotType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SlotType;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Result_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Result;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_NotifyModuleActivation_Statics::NewProp_SlotType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_NotifyModuleActivation_Statics::NewProp_SlotType = { "SlotType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EquipmentManagerComponent_eventClientRPC_NotifyModuleActivation_Parms, SlotType), Z_Construct_UEnum_Echoes_ESlotType, METADATA_PARAMS(0, nullptr) }; // 780113368
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_NotifyModuleActivation_Statics::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EquipmentManagerComponent_eventClientRPC_NotifyModuleActivation_Parms, SlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_NotifyModuleActivation_Statics::NewProp_Result_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_NotifyModuleActivation_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EquipmentManagerComponent_eventClientRPC_NotifyModuleActivation_Parms, Result), Z_Construct_UEnum_Echoes_EModuleActivationResult, METADATA_PARAMS(0, nullptr) }; // 664261323
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_NotifyModuleActivation_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_NotifyModuleActivation_Statics::NewProp_SlotType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_NotifyModuleActivation_Statics::NewProp_SlotType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_NotifyModuleActivation_Statics::NewProp_SlotIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_NotifyModuleActivation_Statics::NewProp_Result_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_NotifyModuleActivation_Statics::NewProp_Result,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_NotifyModuleActivation_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_NotifyModuleActivation_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEquipmentManagerComponent, nullptr, "ClientRPC_NotifyModuleActivation", Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_NotifyModuleActivation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_NotifyModuleActivation_Statics::PropPointers), sizeof(EquipmentManagerComponent_eventClientRPC_NotifyModuleActivation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01020CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_NotifyModuleActivation_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_NotifyModuleActivation_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(EquipmentManagerComponent_eventClientRPC_NotifyModuleActivation_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_NotifyModuleActivation()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_NotifyModuleActivation_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEquipmentManagerComponent::execClientRPC_NotifyModuleActivation)
{
	P_GET_ENUM(ESlotType,Z_Param_SlotType);
	P_GET_PROPERTY(FIntProperty,Z_Param_SlotIndex);
	P_GET_ENUM(EModuleActivationResult,Z_Param_Result);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientRPC_NotifyModuleActivation_Implementation(ESlotType(Z_Param_SlotType),Z_Param_SlotIndex,EModuleActivationResult(Z_Param_Result));
	P_NATIVE_END;
}
// ********** End Class UEquipmentManagerComponent Function ClientRPC_NotifyModuleActivation *******

// ********** Begin Class UEquipmentManagerComponent Function ClientRPC_NotifyModuleState **********
struct EquipmentManagerComponent_eventClientRPC_NotifyModuleState_Parms
{
	ESlotType SlotType;
	int32 SlotIndex;
	EModuleState NewState;
};
static FName NAME_UEquipmentManagerComponent_ClientRPC_NotifyModuleState = FName(TEXT("ClientRPC_NotifyModuleState"));
void UEquipmentManagerComponent::ClientRPC_NotifyModuleState(ESlotType SlotType, int32 SlotIndex, EModuleState NewState)
{
	EquipmentManagerComponent_eventClientRPC_NotifyModuleState_Parms Parms;
	Parms.SlotType=SlotType;
	Parms.SlotIndex=SlotIndex;
	Parms.NewState=NewState;
	UFunction* Func = FindFunctionChecked(NAME_UEquipmentManagerComponent_ClientRPC_NotifyModuleState);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_NotifyModuleState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Equipment" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Notify Module State Changed\n\x09 * Informs client of module state update\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/EquipmentManagerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Notify Module State Changed\nInforms client of module state update" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_SlotType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SlotType;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static const UECodeGen_Private::FBytePropertyParams NewProp_NewState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NewState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_NotifyModuleState_Statics::NewProp_SlotType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_NotifyModuleState_Statics::NewProp_SlotType = { "SlotType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EquipmentManagerComponent_eventClientRPC_NotifyModuleState_Parms, SlotType), Z_Construct_UEnum_Echoes_ESlotType, METADATA_PARAMS(0, nullptr) }; // 780113368
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_NotifyModuleState_Statics::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EquipmentManagerComponent_eventClientRPC_NotifyModuleState_Parms, SlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_NotifyModuleState_Statics::NewProp_NewState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_NotifyModuleState_Statics::NewProp_NewState = { "NewState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EquipmentManagerComponent_eventClientRPC_NotifyModuleState_Parms, NewState), Z_Construct_UEnum_Echoes_EModuleState, METADATA_PARAMS(0, nullptr) }; // 1837800180
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_NotifyModuleState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_NotifyModuleState_Statics::NewProp_SlotType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_NotifyModuleState_Statics::NewProp_SlotType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_NotifyModuleState_Statics::NewProp_SlotIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_NotifyModuleState_Statics::NewProp_NewState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_NotifyModuleState_Statics::NewProp_NewState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_NotifyModuleState_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_NotifyModuleState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEquipmentManagerComponent, nullptr, "ClientRPC_NotifyModuleState", Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_NotifyModuleState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_NotifyModuleState_Statics::PropPointers), sizeof(EquipmentManagerComponent_eventClientRPC_NotifyModuleState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01020CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_NotifyModuleState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_NotifyModuleState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(EquipmentManagerComponent_eventClientRPC_NotifyModuleState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_NotifyModuleState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_NotifyModuleState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEquipmentManagerComponent::execClientRPC_NotifyModuleState)
{
	P_GET_ENUM(ESlotType,Z_Param_SlotType);
	P_GET_PROPERTY(FIntProperty,Z_Param_SlotIndex);
	P_GET_ENUM(EModuleState,Z_Param_NewState);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientRPC_NotifyModuleState_Implementation(ESlotType(Z_Param_SlotType),Z_Param_SlotIndex,EModuleState(Z_Param_NewState));
	P_NATIVE_END;
}
// ********** End Class UEquipmentManagerComponent Function ClientRPC_NotifyModuleState ************

// ********** Begin Class UEquipmentManagerComponent Function ClientRPC_SyncFitting ****************
struct EquipmentManagerComponent_eventClientRPC_SyncFitting_Parms
{
	FCommon_ShipFittingData FittingData;
};
static FName NAME_UEquipmentManagerComponent_ClientRPC_SyncFitting = FName(TEXT("ClientRPC_SyncFitting"));
void UEquipmentManagerComponent::ClientRPC_SyncFitting(FCommon_ShipFittingData const& FittingData)
{
	EquipmentManagerComponent_eventClientRPC_SyncFitting_Parms Parms;
	Parms.FittingData=FittingData;
	UFunction* Func = FindFunctionChecked(NAME_UEquipmentManagerComponent_ClientRPC_SyncFitting);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_SyncFitting_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Equipment" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Sync Fitting Data\n\x09 * Sends complete fitting data to newly connected client\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/EquipmentManagerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sync Fitting Data\nSends complete fitting data to newly connected client" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FittingData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_FittingData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_SyncFitting_Statics::NewProp_FittingData = { "FittingData", nullptr, (EPropertyFlags)0x0010000008000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EquipmentManagerComponent_eventClientRPC_SyncFitting_Parms, FittingData), Z_Construct_UScriptStruct_FCommon_ShipFittingData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FittingData_MetaData), NewProp_FittingData_MetaData) }; // 1329122485
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_SyncFitting_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_SyncFitting_Statics::NewProp_FittingData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_SyncFitting_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_SyncFitting_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEquipmentManagerComponent, nullptr, "ClientRPC_SyncFitting", Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_SyncFitting_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_SyncFitting_Statics::PropPointers), sizeof(EquipmentManagerComponent_eventClientRPC_SyncFitting_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01020CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_SyncFitting_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_SyncFitting_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(EquipmentManagerComponent_eventClientRPC_SyncFitting_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_SyncFitting()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_SyncFitting_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEquipmentManagerComponent::execClientRPC_SyncFitting)
{
	P_GET_STRUCT(FCommon_ShipFittingData,Z_Param_FittingData);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientRPC_SyncFitting_Implementation(Z_Param_FittingData);
	P_NATIVE_END;
}
// ********** End Class UEquipmentManagerComponent Function ClientRPC_SyncFitting ******************

// ********** Begin Class UEquipmentManagerComponent Function Common_CanActivateModule *************
struct Z_Construct_UFunction_UEquipmentManagerComponent_Common_CanActivateModule_Statics
{
	struct EquipmentManagerComponent_eventCommon_CanActivateModule_Parms
	{
		ESlotType SlotType;
		int32 SlotIndex;
		EModuleActivationResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Equipment" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Can Activate Module\n\x09 * Checks if a module can be activated (without actually activating it)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/EquipmentManagerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Can Activate Module\nChecks if a module can be activated (without actually activating it)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_SlotType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SlotType;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UEquipmentManagerComponent_Common_CanActivateModule_Statics::NewProp_SlotType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UEquipmentManagerComponent_Common_CanActivateModule_Statics::NewProp_SlotType = { "SlotType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EquipmentManagerComponent_eventCommon_CanActivateModule_Parms, SlotType), Z_Construct_UEnum_Echoes_ESlotType, METADATA_PARAMS(0, nullptr) }; // 780113368
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UEquipmentManagerComponent_Common_CanActivateModule_Statics::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EquipmentManagerComponent_eventCommon_CanActivateModule_Parms, SlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UEquipmentManagerComponent_Common_CanActivateModule_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UEquipmentManagerComponent_Common_CanActivateModule_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EquipmentManagerComponent_eventCommon_CanActivateModule_Parms, ReturnValue), Z_Construct_UEnum_Echoes_EModuleActivationResult, METADATA_PARAMS(0, nullptr) }; // 664261323
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEquipmentManagerComponent_Common_CanActivateModule_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentManagerComponent_Common_CanActivateModule_Statics::NewProp_SlotType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentManagerComponent_Common_CanActivateModule_Statics::NewProp_SlotType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentManagerComponent_Common_CanActivateModule_Statics::NewProp_SlotIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentManagerComponent_Common_CanActivateModule_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentManagerComponent_Common_CanActivateModule_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEquipmentManagerComponent_Common_CanActivateModule_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEquipmentManagerComponent_Common_CanActivateModule_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEquipmentManagerComponent, nullptr, "Common_CanActivateModule", Z_Construct_UFunction_UEquipmentManagerComponent_Common_CanActivateModule_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEquipmentManagerComponent_Common_CanActivateModule_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEquipmentManagerComponent_Common_CanActivateModule_Statics::EquipmentManagerComponent_eventCommon_CanActivateModule_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEquipmentManagerComponent_Common_CanActivateModule_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEquipmentManagerComponent_Common_CanActivateModule_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEquipmentManagerComponent_Common_CanActivateModule_Statics::EquipmentManagerComponent_eventCommon_CanActivateModule_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEquipmentManagerComponent_Common_CanActivateModule()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEquipmentManagerComponent_Common_CanActivateModule_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEquipmentManagerComponent::execCommon_CanActivateModule)
{
	P_GET_ENUM(ESlotType,Z_Param_SlotType);
	P_GET_PROPERTY(FIntProperty,Z_Param_SlotIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EModuleActivationResult*)Z_Param__Result=P_THIS->Common_CanActivateModule(ESlotType(Z_Param_SlotType),Z_Param_SlotIndex);
	P_NATIVE_END;
}
// ********** End Class UEquipmentManagerComponent Function Common_CanActivateModule ***************

// ********** Begin Class UEquipmentManagerComponent Function Common_GetCapacitorPercentage ********
struct Z_Construct_UFunction_UEquipmentManagerComponent_Common_GetCapacitorPercentage_Statics
{
	struct EquipmentManagerComponent_eventCommon_GetCapacitorPercentage_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Equipment" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get Capacitor Percentage\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/EquipmentManagerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get Capacitor Percentage" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UEquipmentManagerComponent_Common_GetCapacitorPercentage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EquipmentManagerComponent_eventCommon_GetCapacitorPercentage_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEquipmentManagerComponent_Common_GetCapacitorPercentage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentManagerComponent_Common_GetCapacitorPercentage_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEquipmentManagerComponent_Common_GetCapacitorPercentage_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEquipmentManagerComponent_Common_GetCapacitorPercentage_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEquipmentManagerComponent, nullptr, "Common_GetCapacitorPercentage", Z_Construct_UFunction_UEquipmentManagerComponent_Common_GetCapacitorPercentage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEquipmentManagerComponent_Common_GetCapacitorPercentage_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEquipmentManagerComponent_Common_GetCapacitorPercentage_Statics::EquipmentManagerComponent_eventCommon_GetCapacitorPercentage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEquipmentManagerComponent_Common_GetCapacitorPercentage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEquipmentManagerComponent_Common_GetCapacitorPercentage_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEquipmentManagerComponent_Common_GetCapacitorPercentage_Statics::EquipmentManagerComponent_eventCommon_GetCapacitorPercentage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEquipmentManagerComponent_Common_GetCapacitorPercentage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEquipmentManagerComponent_Common_GetCapacitorPercentage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEquipmentManagerComponent::execCommon_GetCapacitorPercentage)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->Common_GetCapacitorPercentage();
	P_NATIVE_END;
}
// ********** End Class UEquipmentManagerComponent Function Common_GetCapacitorPercentage **********

// ********** Begin Class UEquipmentManagerComponent Function Common_GetModuleSlot *****************
struct Z_Construct_UFunction_UEquipmentManagerComponent_Common_GetModuleSlot_Statics
{
	struct EquipmentManagerComponent_eventCommon_GetModuleSlot_Parms
	{
		ESlotType SlotType;
		int32 SlotIndex;
		FCommon_ItemSlot ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Equipment" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get Module Slot\n\x09 * Returns slot data for a specific module\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/EquipmentManagerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get Module Slot\nReturns slot data for a specific module" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_SlotType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SlotType;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UEquipmentManagerComponent_Common_GetModuleSlot_Statics::NewProp_SlotType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UEquipmentManagerComponent_Common_GetModuleSlot_Statics::NewProp_SlotType = { "SlotType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EquipmentManagerComponent_eventCommon_GetModuleSlot_Parms, SlotType), Z_Construct_UEnum_Echoes_ESlotType, METADATA_PARAMS(0, nullptr) }; // 780113368
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UEquipmentManagerComponent_Common_GetModuleSlot_Statics::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EquipmentManagerComponent_eventCommon_GetModuleSlot_Parms, SlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEquipmentManagerComponent_Common_GetModuleSlot_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EquipmentManagerComponent_eventCommon_GetModuleSlot_Parms, ReturnValue), Z_Construct_UScriptStruct_FCommon_ItemSlot, METADATA_PARAMS(0, nullptr) }; // 771062216
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEquipmentManagerComponent_Common_GetModuleSlot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentManagerComponent_Common_GetModuleSlot_Statics::NewProp_SlotType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentManagerComponent_Common_GetModuleSlot_Statics::NewProp_SlotType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentManagerComponent_Common_GetModuleSlot_Statics::NewProp_SlotIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentManagerComponent_Common_GetModuleSlot_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEquipmentManagerComponent_Common_GetModuleSlot_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEquipmentManagerComponent_Common_GetModuleSlot_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEquipmentManagerComponent, nullptr, "Common_GetModuleSlot", Z_Construct_UFunction_UEquipmentManagerComponent_Common_GetModuleSlot_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEquipmentManagerComponent_Common_GetModuleSlot_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEquipmentManagerComponent_Common_GetModuleSlot_Statics::EquipmentManagerComponent_eventCommon_GetModuleSlot_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEquipmentManagerComponent_Common_GetModuleSlot_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEquipmentManagerComponent_Common_GetModuleSlot_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEquipmentManagerComponent_Common_GetModuleSlot_Statics::EquipmentManagerComponent_eventCommon_GetModuleSlot_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEquipmentManagerComponent_Common_GetModuleSlot()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEquipmentManagerComponent_Common_GetModuleSlot_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEquipmentManagerComponent::execCommon_GetModuleSlot)
{
	P_GET_ENUM(ESlotType,Z_Param_SlotType);
	P_GET_PROPERTY(FIntProperty,Z_Param_SlotIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FCommon_ItemSlot*)Z_Param__Result=P_THIS->Common_GetModuleSlot(ESlotType(Z_Param_SlotType),Z_Param_SlotIndex);
	P_NATIVE_END;
}
// ********** End Class UEquipmentManagerComponent Function Common_GetModuleSlot *******************

// ********** Begin Class UEquipmentManagerComponent Function ServerRPC_DeactivateAll **************
static FName NAME_UEquipmentManagerComponent_ServerRPC_DeactivateAll = FName(TEXT("ServerRPC_DeactivateAll"));
void UEquipmentManagerComponent::ServerRPC_DeactivateAll()
{
	UFunction* Func = FindFunctionChecked(NAME_UEquipmentManagerComponent_ServerRPC_DeactivateAll);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_UEquipmentManagerComponent_ServerRPC_DeactivateAll_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Equipment" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Deactivate All Modules\n\x09 * Emergency stop for all active modules\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/EquipmentManagerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Deactivate All Modules\nEmergency stop for all active modules" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEquipmentManagerComponent_ServerRPC_DeactivateAll_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEquipmentManagerComponent, nullptr, "ServerRPC_DeactivateAll", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEquipmentManagerComponent_ServerRPC_DeactivateAll_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEquipmentManagerComponent_ServerRPC_DeactivateAll_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEquipmentManagerComponent_ServerRPC_DeactivateAll()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEquipmentManagerComponent_ServerRPC_DeactivateAll_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEquipmentManagerComponent::execServerRPC_DeactivateAll)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerRPC_DeactivateAll_Implementation();
	P_NATIVE_END;
}
// ********** End Class UEquipmentManagerComponent Function ServerRPC_DeactivateAll ****************

// ********** Begin Class UEquipmentManagerComponent Function ServerRPC_SetOverload ****************
struct EquipmentManagerComponent_eventServerRPC_SetOverload_Parms
{
	ESlotType SlotType;
	int32 SlotIndex;
	bool bOverload;
};
static FName NAME_UEquipmentManagerComponent_ServerRPC_SetOverload = FName(TEXT("ServerRPC_SetOverload"));
void UEquipmentManagerComponent::ServerRPC_SetOverload(ESlotType SlotType, int32 SlotIndex, bool bOverload)
{
	EquipmentManagerComponent_eventServerRPC_SetOverload_Parms Parms;
	Parms.SlotType=SlotType;
	Parms.SlotIndex=SlotIndex;
	Parms.bOverload=bOverload ? true : false;
	UFunction* Func = FindFunctionChecked(NAME_UEquipmentManagerComponent_ServerRPC_SetOverload);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UEquipmentManagerComponent_ServerRPC_SetOverload_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Equipment" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Set Module Overload State\n\x09 * Enable/disable overload for a module (increased performance, risk of damage)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/EquipmentManagerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set Module Overload State\nEnable/disable overload for a module (increased performance, risk of damage)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_SlotType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SlotType;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static void NewProp_bOverload_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOverload;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UEquipmentManagerComponent_ServerRPC_SetOverload_Statics::NewProp_SlotType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UEquipmentManagerComponent_ServerRPC_SetOverload_Statics::NewProp_SlotType = { "SlotType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EquipmentManagerComponent_eventServerRPC_SetOverload_Parms, SlotType), Z_Construct_UEnum_Echoes_ESlotType, METADATA_PARAMS(0, nullptr) }; // 780113368
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UEquipmentManagerComponent_ServerRPC_SetOverload_Statics::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EquipmentManagerComponent_eventServerRPC_SetOverload_Parms, SlotIndex), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UEquipmentManagerComponent_ServerRPC_SetOverload_Statics::NewProp_bOverload_SetBit(void* Obj)
{
	((EquipmentManagerComponent_eventServerRPC_SetOverload_Parms*)Obj)->bOverload = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UEquipmentManagerComponent_ServerRPC_SetOverload_Statics::NewProp_bOverload = { "bOverload", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EquipmentManagerComponent_eventServerRPC_SetOverload_Parms), &Z_Construct_UFunction_UEquipmentManagerComponent_ServerRPC_SetOverload_Statics::NewProp_bOverload_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEquipmentManagerComponent_ServerRPC_SetOverload_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentManagerComponent_ServerRPC_SetOverload_Statics::NewProp_SlotType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentManagerComponent_ServerRPC_SetOverload_Statics::NewProp_SlotType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentManagerComponent_ServerRPC_SetOverload_Statics::NewProp_SlotIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentManagerComponent_ServerRPC_SetOverload_Statics::NewProp_bOverload,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEquipmentManagerComponent_ServerRPC_SetOverload_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEquipmentManagerComponent_ServerRPC_SetOverload_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEquipmentManagerComponent, nullptr, "ServerRPC_SetOverload", Z_Construct_UFunction_UEquipmentManagerComponent_ServerRPC_SetOverload_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEquipmentManagerComponent_ServerRPC_SetOverload_Statics::PropPointers), sizeof(EquipmentManagerComponent_eventServerRPC_SetOverload_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEquipmentManagerComponent_ServerRPC_SetOverload_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEquipmentManagerComponent_ServerRPC_SetOverload_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(EquipmentManagerComponent_eventServerRPC_SetOverload_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEquipmentManagerComponent_ServerRPC_SetOverload()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEquipmentManagerComponent_ServerRPC_SetOverload_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEquipmentManagerComponent::execServerRPC_SetOverload)
{
	P_GET_ENUM(ESlotType,Z_Param_SlotType);
	P_GET_PROPERTY(FIntProperty,Z_Param_SlotIndex);
	P_GET_UBOOL(Z_Param_bOverload);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerRPC_SetOverload_Implementation(ESlotType(Z_Param_SlotType),Z_Param_SlotIndex,Z_Param_bOverload);
	P_NATIVE_END;
}
// ********** End Class UEquipmentManagerComponent Function ServerRPC_SetOverload ******************

// ********** Begin Class UEquipmentManagerComponent Function ServerRPC_ToggleModule ***************
struct EquipmentManagerComponent_eventServerRPC_ToggleModule_Parms
{
	ESlotType SlotType;
	int32 SlotIndex;
};
static FName NAME_UEquipmentManagerComponent_ServerRPC_ToggleModule = FName(TEXT("ServerRPC_ToggleModule"));
void UEquipmentManagerComponent::ServerRPC_ToggleModule(ESlotType SlotType, int32 SlotIndex)
{
	EquipmentManagerComponent_eventServerRPC_ToggleModule_Parms Parms;
	Parms.SlotType=SlotType;
	Parms.SlotIndex=SlotIndex;
	UFunction* Func = FindFunctionChecked(NAME_UEquipmentManagerComponent_ServerRPC_ToggleModule);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UEquipmentManagerComponent_ServerRPC_ToggleModule_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Equipment" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Toggle Module Activation\n\x09 * Server-authoritative module activation with full validation\n\x09 * Checks: Capacitor, Ammo, Range, Cooldown, Target (if needed)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/EquipmentManagerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Toggle Module Activation\nServer-authoritative module activation with full validation\nChecks: Capacitor, Ammo, Range, Cooldown, Target (if needed)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_SlotType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SlotType;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UEquipmentManagerComponent_ServerRPC_ToggleModule_Statics::NewProp_SlotType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UEquipmentManagerComponent_ServerRPC_ToggleModule_Statics::NewProp_SlotType = { "SlotType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EquipmentManagerComponent_eventServerRPC_ToggleModule_Parms, SlotType), Z_Construct_UEnum_Echoes_ESlotType, METADATA_PARAMS(0, nullptr) }; // 780113368
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UEquipmentManagerComponent_ServerRPC_ToggleModule_Statics::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EquipmentManagerComponent_eventServerRPC_ToggleModule_Parms, SlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEquipmentManagerComponent_ServerRPC_ToggleModule_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentManagerComponent_ServerRPC_ToggleModule_Statics::NewProp_SlotType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentManagerComponent_ServerRPC_ToggleModule_Statics::NewProp_SlotType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentManagerComponent_ServerRPC_ToggleModule_Statics::NewProp_SlotIndex,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEquipmentManagerComponent_ServerRPC_ToggleModule_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEquipmentManagerComponent_ServerRPC_ToggleModule_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEquipmentManagerComponent, nullptr, "ServerRPC_ToggleModule", Z_Construct_UFunction_UEquipmentManagerComponent_ServerRPC_ToggleModule_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEquipmentManagerComponent_ServerRPC_ToggleModule_Statics::PropPointers), sizeof(EquipmentManagerComponent_eventServerRPC_ToggleModule_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEquipmentManagerComponent_ServerRPC_ToggleModule_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEquipmentManagerComponent_ServerRPC_ToggleModule_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(EquipmentManagerComponent_eventServerRPC_ToggleModule_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEquipmentManagerComponent_ServerRPC_ToggleModule()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEquipmentManagerComponent_ServerRPC_ToggleModule_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEquipmentManagerComponent::execServerRPC_ToggleModule)
{
	P_GET_ENUM(ESlotType,Z_Param_SlotType);
	P_GET_PROPERTY(FIntProperty,Z_Param_SlotIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerRPC_ToggleModule_Implementation(ESlotType(Z_Param_SlotType),Z_Param_SlotIndex);
	P_NATIVE_END;
}
// ********** End Class UEquipmentManagerComponent Function ServerRPC_ToggleModule *****************

// ********** Begin Class UEquipmentManagerComponent ***********************************************
void UEquipmentManagerComponent::StaticRegisterNativesUEquipmentManagerComponent()
{
	UClass* Class = UEquipmentManagerComponent::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ClientRPC_NotifyModuleActivation", &UEquipmentManagerComponent::execClientRPC_NotifyModuleActivation },
		{ "ClientRPC_NotifyModuleState", &UEquipmentManagerComponent::execClientRPC_NotifyModuleState },
		{ "ClientRPC_SyncFitting", &UEquipmentManagerComponent::execClientRPC_SyncFitting },
		{ "Common_CanActivateModule", &UEquipmentManagerComponent::execCommon_CanActivateModule },
		{ "Common_GetCapacitorPercentage", &UEquipmentManagerComponent::execCommon_GetCapacitorPercentage },
		{ "Common_GetModuleSlot", &UEquipmentManagerComponent::execCommon_GetModuleSlot },
		{ "ServerRPC_DeactivateAll", &UEquipmentManagerComponent::execServerRPC_DeactivateAll },
		{ "ServerRPC_SetOverload", &UEquipmentManagerComponent::execServerRPC_SetOverload },
		{ "ServerRPC_ToggleModule", &UEquipmentManagerComponent::execServerRPC_ToggleModule },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UEquipmentManagerComponent;
UClass* UEquipmentManagerComponent::GetPrivateStaticClass()
{
	using TClass = UEquipmentManagerComponent;
	if (!Z_Registration_Info_UClass_UEquipmentManagerComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EquipmentManagerComponent"),
			Z_Registration_Info_UClass_UEquipmentManagerComponent.InnerSingleton,
			StaticRegisterNativesUEquipmentManagerComponent,
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
	return Z_Registration_Info_UClass_UEquipmentManagerComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UEquipmentManagerComponent_NoRegister()
{
	return UEquipmentManagerComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UEquipmentManagerComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Equipment Manager Component\n * Server-authoritative component that manages ship equipment activation\n * Handles capacitor costs, ammunition consumption, cooldowns, and targeting requirements\n */" },
#endif
		{ "IncludePath", "Core/Common/Components/EquipmentManagerComponent.h" },
		{ "ModuleRelativePath", "Core/Common/Components/EquipmentManagerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Equipment Manager Component\nServer-authoritative component that manages ship equipment activation\nHandles capacitor costs, ammunition consumption, cooldowns, and targeting requirements" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentFitting_MetaData[] = {
		{ "Category", "Equipment" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current ship fitting data (replicated to clients) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/EquipmentManagerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current ship fitting data (replicated to clients)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentCapacitor_MetaData[] = {
		{ "Category", "Equipment" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current capacitor energy */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/EquipmentManagerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current capacitor energy" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxCapacitor_MetaData[] = {
		{ "Category", "Equipment" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum capacitor energy */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/EquipmentManagerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum capacitor energy" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CapacitorRechargeRate_MetaData[] = {
		{ "Category", "Equipment" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Capacitor recharge rate (per second) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/EquipmentManagerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Capacitor recharge rate (per second)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultWeaponRange_MetaData[] = {
		{ "Category", "Equipment" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Default weapon range (cm) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/EquipmentManagerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Default weapon range (cm)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnModuleStateChanged_MetaData[] = {
		{ "Category", "Equipment" },
		{ "ModuleRelativePath", "Core/Common/Components/EquipmentManagerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnCapacitorChanged_MetaData[] = {
		{ "Category", "Equipment" },
		{ "ModuleRelativePath", "Core/Common/Components/EquipmentManagerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnEquipmentChanged_MetaData[] = {
		{ "Category", "Equipment" },
		{ "ModuleRelativePath", "Core/Common/Components/EquipmentManagerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CachedOwnerPawn_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Cached references */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/EquipmentManagerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cached references" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CachedPlayerController_MetaData[] = {
		{ "ModuleRelativePath", "Core/Common/Components/EquipmentManagerComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentFitting;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentCapacitor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxCapacitor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CapacitorRechargeRate;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DefaultWeaponRange;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnModuleStateChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCapacitorChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnEquipmentChanged;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CachedOwnerPawn;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CachedPlayerController;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_NotifyModuleActivation, "ClientRPC_NotifyModuleActivation" }, // 4218654469
		{ &Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_NotifyModuleState, "ClientRPC_NotifyModuleState" }, // 2478296419
		{ &Z_Construct_UFunction_UEquipmentManagerComponent_ClientRPC_SyncFitting, "ClientRPC_SyncFitting" }, // 2081793548
		{ &Z_Construct_UFunction_UEquipmentManagerComponent_Common_CanActivateModule, "Common_CanActivateModule" }, // 254548185
		{ &Z_Construct_UFunction_UEquipmentManagerComponent_Common_GetCapacitorPercentage, "Common_GetCapacitorPercentage" }, // 1986935292
		{ &Z_Construct_UFunction_UEquipmentManagerComponent_Common_GetModuleSlot, "Common_GetModuleSlot" }, // 2615204556
		{ &Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnCapacitorChanged__DelegateSignature, "OnCapacitorChanged__DelegateSignature" }, // 945776760
		{ &Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnEquipmentChanged__DelegateSignature, "OnEquipmentChanged__DelegateSignature" }, // 1453785468
		{ &Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnModuleStateChanged__DelegateSignature, "OnModuleStateChanged__DelegateSignature" }, // 1084080381
		{ &Z_Construct_UFunction_UEquipmentManagerComponent_ServerRPC_DeactivateAll, "ServerRPC_DeactivateAll" }, // 72073704
		{ &Z_Construct_UFunction_UEquipmentManagerComponent_ServerRPC_SetOverload, "ServerRPC_SetOverload" }, // 2840652750
		{ &Z_Construct_UFunction_UEquipmentManagerComponent_ServerRPC_ToggleModule, "ServerRPC_ToggleModule" }, // 3060957787
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEquipmentManagerComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEquipmentManagerComponent_Statics::NewProp_CurrentFitting = { "CurrentFitting", nullptr, (EPropertyFlags)0x0010000000000034, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEquipmentManagerComponent, CurrentFitting), Z_Construct_UScriptStruct_FCommon_ShipFittingData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentFitting_MetaData), NewProp_CurrentFitting_MetaData) }; // 1329122485
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEquipmentManagerComponent_Statics::NewProp_CurrentCapacitor = { "CurrentCapacitor", nullptr, (EPropertyFlags)0x0010000000000034, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEquipmentManagerComponent, CurrentCapacitor), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentCapacitor_MetaData), NewProp_CurrentCapacitor_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEquipmentManagerComponent_Statics::NewProp_MaxCapacitor = { "MaxCapacitor", nullptr, (EPropertyFlags)0x0010000000000034, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEquipmentManagerComponent, MaxCapacitor), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxCapacitor_MetaData), NewProp_MaxCapacitor_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEquipmentManagerComponent_Statics::NewProp_CapacitorRechargeRate = { "CapacitorRechargeRate", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEquipmentManagerComponent, CapacitorRechargeRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CapacitorRechargeRate_MetaData), NewProp_CapacitorRechargeRate_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEquipmentManagerComponent_Statics::NewProp_DefaultWeaponRange = { "DefaultWeaponRange", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEquipmentManagerComponent, DefaultWeaponRange), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultWeaponRange_MetaData), NewProp_DefaultWeaponRange_MetaData) };
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEquipmentManagerComponent_Statics::NewProp_OnModuleStateChanged = { "OnModuleStateChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEquipmentManagerComponent, OnModuleStateChanged), Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnModuleStateChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnModuleStateChanged_MetaData), NewProp_OnModuleStateChanged_MetaData) }; // 1084080381
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEquipmentManagerComponent_Statics::NewProp_OnCapacitorChanged = { "OnCapacitorChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEquipmentManagerComponent, OnCapacitorChanged), Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnCapacitorChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnCapacitorChanged_MetaData), NewProp_OnCapacitorChanged_MetaData) }; // 945776760
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEquipmentManagerComponent_Statics::NewProp_OnEquipmentChanged = { "OnEquipmentChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEquipmentManagerComponent, OnEquipmentChanged), Z_Construct_UDelegateFunction_UEquipmentManagerComponent_OnEquipmentChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnEquipmentChanged_MetaData), NewProp_OnEquipmentChanged_MetaData) }; // 1453785468
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEquipmentManagerComponent_Statics::NewProp_CachedOwnerPawn = { "CachedOwnerPawn", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEquipmentManagerComponent, CachedOwnerPawn), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CachedOwnerPawn_MetaData), NewProp_CachedOwnerPawn_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEquipmentManagerComponent_Statics::NewProp_CachedPlayerController = { "CachedPlayerController", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEquipmentManagerComponent, CachedPlayerController), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CachedPlayerController_MetaData), NewProp_CachedPlayerController_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEquipmentManagerComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEquipmentManagerComponent_Statics::NewProp_CurrentFitting,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEquipmentManagerComponent_Statics::NewProp_CurrentCapacitor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEquipmentManagerComponent_Statics::NewProp_MaxCapacitor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEquipmentManagerComponent_Statics::NewProp_CapacitorRechargeRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEquipmentManagerComponent_Statics::NewProp_DefaultWeaponRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEquipmentManagerComponent_Statics::NewProp_OnModuleStateChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEquipmentManagerComponent_Statics::NewProp_OnCapacitorChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEquipmentManagerComponent_Statics::NewProp_OnEquipmentChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEquipmentManagerComponent_Statics::NewProp_CachedOwnerPawn,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEquipmentManagerComponent_Statics::NewProp_CachedPlayerController,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEquipmentManagerComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UEquipmentManagerComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEquipmentManagerComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEquipmentManagerComponent_Statics::ClassParams = {
	&UEquipmentManagerComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UEquipmentManagerComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UEquipmentManagerComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEquipmentManagerComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UEquipmentManagerComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEquipmentManagerComponent()
{
	if (!Z_Registration_Info_UClass_UEquipmentManagerComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEquipmentManagerComponent.OuterSingleton, Z_Construct_UClass_UEquipmentManagerComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEquipmentManagerComponent.OuterSingleton;
}
#if VALIDATE_CLASS_REPS
void UEquipmentManagerComponent::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static FName Name_CurrentFitting(TEXT("CurrentFitting"));
	static FName Name_CurrentCapacitor(TEXT("CurrentCapacitor"));
	static FName Name_MaxCapacitor(TEXT("MaxCapacitor"));
	const bool bIsValid = true
		&& Name_CurrentFitting == ClassReps[(int32)ENetFields_Private::CurrentFitting].Property->GetFName()
		&& Name_CurrentCapacitor == ClassReps[(int32)ENetFields_Private::CurrentCapacitor].Property->GetFName()
		&& Name_MaxCapacitor == ClassReps[(int32)ENetFields_Private::MaxCapacitor].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in UEquipmentManagerComponent"));
}
#endif
DEFINE_VTABLE_PTR_HELPER_CTOR(UEquipmentManagerComponent);
UEquipmentManagerComponent::~UEquipmentManagerComponent() {}
// ********** End Class UEquipmentManagerComponent *************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EquipmentManagerComponent_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEquipmentManagerComponent, UEquipmentManagerComponent::StaticClass, TEXT("UEquipmentManagerComponent"), &Z_Registration_Info_UClass_UEquipmentManagerComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEquipmentManagerComponent), 4180363908U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EquipmentManagerComponent_h__Script_Echoes_864089700(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EquipmentManagerComponent_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EquipmentManagerComponent_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
