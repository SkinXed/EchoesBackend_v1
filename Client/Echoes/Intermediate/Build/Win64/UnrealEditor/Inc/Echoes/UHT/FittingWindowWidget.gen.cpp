// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FittingWindowWidget.h"
#include "ShipFittingInterface.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeFittingWindowWidget() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ECHOES_API UClass* Z_Construct_UClass_UFittingSlotWidget();
ECHOES_API UClass* Z_Construct_UClass_UFittingSlotWidget_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UFittingWindowWidget();
ECHOES_API UClass* Z_Construct_UClass_UFittingWindowWidget_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UShipFittingInterface_NoRegister();
ECHOES_API UEnum* Z_Construct_UEnum_Echoes_ESlotType();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_UFittingSlotWidget_OnModuleDropped__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_UFittingSlotWidget_OnModuleRemoved__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_UFittingWindowWidget_OnFittingChanged__DelegateSignature();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FCommon_ItemSlot();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FCommon_ShipFittingData();
ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APlayerController_NoRegister();
UMG_API UClass* Z_Construct_UClass_UBorder_NoRegister();
UMG_API UClass* Z_Construct_UClass_UImage_NoRegister();
UMG_API UClass* Z_Construct_UClass_UProgressBar_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UMG_API UClass* Z_Construct_UClass_UVerticalBox_NoRegister();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FOnFittingChanged *****************************************************
struct Z_Construct_UDelegateFunction_UFittingWindowWidget_OnFittingChanged__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Use a dynamic multicast delegate so it can be exposed to Blueprints via UPROPERTY(BlueprintAssignable)\n" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/Fitting/FittingWindowWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Use a dynamic multicast delegate so it can be exposed to Blueprints via UPROPERTY(BlueprintAssignable)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_UFittingWindowWidget_OnFittingChanged__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UFittingWindowWidget, nullptr, "OnFittingChanged__DelegateSignature", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UFittingWindowWidget_OnFittingChanged__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UFittingWindowWidget_OnFittingChanged__DelegateSignature_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UDelegateFunction_UFittingWindowWidget_OnFittingChanged__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UFittingWindowWidget_OnFittingChanged__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void UFittingWindowWidget::FOnFittingChanged_DelegateWrapper(const FMulticastScriptDelegate& OnFittingChanged)
{
	OnFittingChanged.ProcessMulticastDelegate<UObject>(NULL);
}
// ********** End Delegate FOnFittingChanged *******************************************************

// ********** Begin Class UFittingWindowWidget Function ClientOnly_RefreshFitting ******************
struct Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_RefreshFitting_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Fitting Window" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ============================================================================\n// CLIENT-ONLY FUNCTIONS\n// ============================================================================\n" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/Fitting/FittingWindowWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "CLIENT-ONLY FUNCTIONS" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_RefreshFitting_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UFittingWindowWidget, nullptr, "ClientOnly_RefreshFitting", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_RefreshFitting_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_RefreshFitting_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_RefreshFitting()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_RefreshFitting_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFittingWindowWidget::execClientOnly_RefreshFitting)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientOnly_RefreshFitting();
	P_NATIVE_END;
}
// ********** End Class UFittingWindowWidget Function ClientOnly_RefreshFitting ********************

// ********** Begin Class UFittingWindowWidget Function ClientOnly_UpdateCPUDisplay ****************
struct Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdateCPUDisplay_Statics
{
	struct FittingWindowWidget_eventClientOnly_UpdateCPUDisplay_Parms
	{
		float Used;
		float Max;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Fitting Window" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/FittingWindowWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Used;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Max;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdateCPUDisplay_Statics::NewProp_Used = { "Used", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FittingWindowWidget_eventClientOnly_UpdateCPUDisplay_Parms, Used), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdateCPUDisplay_Statics::NewProp_Max = { "Max", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FittingWindowWidget_eventClientOnly_UpdateCPUDisplay_Parms, Max), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdateCPUDisplay_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdateCPUDisplay_Statics::NewProp_Used,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdateCPUDisplay_Statics::NewProp_Max,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdateCPUDisplay_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdateCPUDisplay_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UFittingWindowWidget, nullptr, "ClientOnly_UpdateCPUDisplay", Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdateCPUDisplay_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdateCPUDisplay_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdateCPUDisplay_Statics::FittingWindowWidget_eventClientOnly_UpdateCPUDisplay_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdateCPUDisplay_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdateCPUDisplay_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdateCPUDisplay_Statics::FittingWindowWidget_eventClientOnly_UpdateCPUDisplay_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdateCPUDisplay()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdateCPUDisplay_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFittingWindowWidget::execClientOnly_UpdateCPUDisplay)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Used);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Max);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientOnly_UpdateCPUDisplay(Z_Param_Used,Z_Param_Max);
	P_NATIVE_END;
}
// ********** End Class UFittingWindowWidget Function ClientOnly_UpdateCPUDisplay ******************

// ********** Begin Class UFittingWindowWidget Function ClientOnly_UpdatePowergridDisplay **********
struct Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdatePowergridDisplay_Statics
{
	struct FittingWindowWidget_eventClientOnly_UpdatePowergridDisplay_Parms
	{
		float Used;
		float Max;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Fitting Window" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/FittingWindowWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Used;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Max;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdatePowergridDisplay_Statics::NewProp_Used = { "Used", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FittingWindowWidget_eventClientOnly_UpdatePowergridDisplay_Parms, Used), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdatePowergridDisplay_Statics::NewProp_Max = { "Max", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FittingWindowWidget_eventClientOnly_UpdatePowergridDisplay_Parms, Max), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdatePowergridDisplay_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdatePowergridDisplay_Statics::NewProp_Used,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdatePowergridDisplay_Statics::NewProp_Max,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdatePowergridDisplay_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdatePowergridDisplay_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UFittingWindowWidget, nullptr, "ClientOnly_UpdatePowergridDisplay", Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdatePowergridDisplay_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdatePowergridDisplay_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdatePowergridDisplay_Statics::FittingWindowWidget_eventClientOnly_UpdatePowergridDisplay_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdatePowergridDisplay_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdatePowergridDisplay_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdatePowergridDisplay_Statics::FittingWindowWidget_eventClientOnly_UpdatePowergridDisplay_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdatePowergridDisplay()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdatePowergridDisplay_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFittingWindowWidget::execClientOnly_UpdatePowergridDisplay)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Used);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Max);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientOnly_UpdatePowergridDisplay(Z_Param_Used,Z_Param_Max);
	P_NATIVE_END;
}
// ********** End Class UFittingWindowWidget Function ClientOnly_UpdatePowergridDisplay ************

// ********** Begin Class UFittingWindowWidget Function ClientOnly_UpdateSlot **********************
struct Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdateSlot_Statics
{
	struct FittingWindowWidget_eventClientOnly_UpdateSlot_Parms
	{
		ESlotType SlotType;
		int32 SlotIndex;
		FCommon_ItemSlot SlotData;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Fitting Window" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/FittingWindowWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlotData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_SlotType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SlotType;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SlotData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdateSlot_Statics::NewProp_SlotType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdateSlot_Statics::NewProp_SlotType = { "SlotType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FittingWindowWidget_eventClientOnly_UpdateSlot_Parms, SlotType), Z_Construct_UEnum_Echoes_ESlotType, METADATA_PARAMS(0, nullptr) }; // 780113368
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdateSlot_Statics::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FittingWindowWidget_eventClientOnly_UpdateSlot_Parms, SlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdateSlot_Statics::NewProp_SlotData = { "SlotData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FittingWindowWidget_eventClientOnly_UpdateSlot_Parms, SlotData), Z_Construct_UScriptStruct_FCommon_ItemSlot, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlotData_MetaData), NewProp_SlotData_MetaData) }; // 771062216
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdateSlot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdateSlot_Statics::NewProp_SlotType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdateSlot_Statics::NewProp_SlotType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdateSlot_Statics::NewProp_SlotIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdateSlot_Statics::NewProp_SlotData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdateSlot_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdateSlot_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UFittingWindowWidget, nullptr, "ClientOnly_UpdateSlot", Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdateSlot_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdateSlot_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdateSlot_Statics::FittingWindowWidget_eventClientOnly_UpdateSlot_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdateSlot_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdateSlot_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdateSlot_Statics::FittingWindowWidget_eventClientOnly_UpdateSlot_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdateSlot()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdateSlot_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFittingWindowWidget::execClientOnly_UpdateSlot)
{
	P_GET_ENUM(ESlotType,Z_Param_SlotType);
	P_GET_PROPERTY(FIntProperty,Z_Param_SlotIndex);
	P_GET_STRUCT_REF(FCommon_ItemSlot,Z_Param_Out_SlotData);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientOnly_UpdateSlot(ESlotType(Z_Param_SlotType),Z_Param_SlotIndex,Z_Param_Out_SlotData);
	P_NATIVE_END;
}
// ********** End Class UFittingWindowWidget Function ClientOnly_UpdateSlot ************************

// ********** Begin Class UFittingWindowWidget Function Common_CalculateFitting ********************
struct Z_Construct_UFunction_UFittingWindowWidget_Common_CalculateFitting_Statics
{
	struct FittingWindowWidget_eventCommon_CalculateFitting_Parms
	{
		FCommon_ShipFittingData FittingData;
		float OutPowergrid;
		float OutCPU;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Fitting Window" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/FittingWindowWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FittingData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_FittingData;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OutPowergrid;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OutCPU;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UFittingWindowWidget_Common_CalculateFitting_Statics::NewProp_FittingData = { "FittingData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FittingWindowWidget_eventCommon_CalculateFitting_Parms, FittingData), Z_Construct_UScriptStruct_FCommon_ShipFittingData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FittingData_MetaData), NewProp_FittingData_MetaData) }; // 1329122485
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UFittingWindowWidget_Common_CalculateFitting_Statics::NewProp_OutPowergrid = { "OutPowergrid", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FittingWindowWidget_eventCommon_CalculateFitting_Parms, OutPowergrid), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UFittingWindowWidget_Common_CalculateFitting_Statics::NewProp_OutCPU = { "OutCPU", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FittingWindowWidget_eventCommon_CalculateFitting_Parms, OutCPU), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UFittingWindowWidget_Common_CalculateFitting_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((FittingWindowWidget_eventCommon_CalculateFitting_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UFittingWindowWidget_Common_CalculateFitting_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FittingWindowWidget_eventCommon_CalculateFitting_Parms), &Z_Construct_UFunction_UFittingWindowWidget_Common_CalculateFitting_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFittingWindowWidget_Common_CalculateFitting_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFittingWindowWidget_Common_CalculateFitting_Statics::NewProp_FittingData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFittingWindowWidget_Common_CalculateFitting_Statics::NewProp_OutPowergrid,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFittingWindowWidget_Common_CalculateFitting_Statics::NewProp_OutCPU,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFittingWindowWidget_Common_CalculateFitting_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFittingWindowWidget_Common_CalculateFitting_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFittingWindowWidget_Common_CalculateFitting_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UFittingWindowWidget, nullptr, "Common_CalculateFitting", Z_Construct_UFunction_UFittingWindowWidget_Common_CalculateFitting_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFittingWindowWidget_Common_CalculateFitting_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFittingWindowWidget_Common_CalculateFitting_Statics::FittingWindowWidget_eventCommon_CalculateFitting_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFittingWindowWidget_Common_CalculateFitting_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFittingWindowWidget_Common_CalculateFitting_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UFittingWindowWidget_Common_CalculateFitting_Statics::FittingWindowWidget_eventCommon_CalculateFitting_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFittingWindowWidget_Common_CalculateFitting()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFittingWindowWidget_Common_CalculateFitting_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFittingWindowWidget::execCommon_CalculateFitting)
{
	P_GET_STRUCT_REF(FCommon_ShipFittingData,Z_Param_Out_FittingData);
	P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_OutPowergrid);
	P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_OutCPU);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->Common_CalculateFitting(Z_Param_Out_FittingData,Z_Param_Out_OutPowergrid,Z_Param_Out_OutCPU);
	P_NATIVE_END;
}
// ********** End Class UFittingWindowWidget Function Common_CalculateFitting **********************

// ********** Begin Class UFittingWindowWidget Function Common_CanInstallModule ********************
struct Z_Construct_UFunction_UFittingWindowWidget_Common_CanInstallModule_Statics
{
	struct FittingWindowWidget_eventCommon_CanInstallModule_Parms
	{
		int32 ItemID;
		ESlotType SlotType;
		int32 SlotIndex;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Fitting Window" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ============================================================================\n// COMMON FUNCTIONS\n// ============================================================================\n" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/Fitting/FittingWindowWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "COMMON FUNCTIONS" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ItemID;
	static const UECodeGen_Private::FBytePropertyParams NewProp_SlotType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SlotType;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UFittingWindowWidget_Common_CanInstallModule_Statics::NewProp_ItemID = { "ItemID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FittingWindowWidget_eventCommon_CanInstallModule_Parms, ItemID), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UFittingWindowWidget_Common_CanInstallModule_Statics::NewProp_SlotType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UFittingWindowWidget_Common_CanInstallModule_Statics::NewProp_SlotType = { "SlotType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FittingWindowWidget_eventCommon_CanInstallModule_Parms, SlotType), Z_Construct_UEnum_Echoes_ESlotType, METADATA_PARAMS(0, nullptr) }; // 780113368
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UFittingWindowWidget_Common_CanInstallModule_Statics::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FittingWindowWidget_eventCommon_CanInstallModule_Parms, SlotIndex), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UFittingWindowWidget_Common_CanInstallModule_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((FittingWindowWidget_eventCommon_CanInstallModule_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UFittingWindowWidget_Common_CanInstallModule_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FittingWindowWidget_eventCommon_CanInstallModule_Parms), &Z_Construct_UFunction_UFittingWindowWidget_Common_CanInstallModule_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFittingWindowWidget_Common_CanInstallModule_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFittingWindowWidget_Common_CanInstallModule_Statics::NewProp_ItemID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFittingWindowWidget_Common_CanInstallModule_Statics::NewProp_SlotType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFittingWindowWidget_Common_CanInstallModule_Statics::NewProp_SlotType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFittingWindowWidget_Common_CanInstallModule_Statics::NewProp_SlotIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFittingWindowWidget_Common_CanInstallModule_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFittingWindowWidget_Common_CanInstallModule_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFittingWindowWidget_Common_CanInstallModule_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UFittingWindowWidget, nullptr, "Common_CanInstallModule", Z_Construct_UFunction_UFittingWindowWidget_Common_CanInstallModule_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFittingWindowWidget_Common_CanInstallModule_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFittingWindowWidget_Common_CanInstallModule_Statics::FittingWindowWidget_eventCommon_CanInstallModule_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFittingWindowWidget_Common_CanInstallModule_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFittingWindowWidget_Common_CanInstallModule_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UFittingWindowWidget_Common_CanInstallModule_Statics::FittingWindowWidget_eventCommon_CanInstallModule_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFittingWindowWidget_Common_CanInstallModule()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFittingWindowWidget_Common_CanInstallModule_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFittingWindowWidget::execCommon_CanInstallModule)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_ItemID);
	P_GET_ENUM(ESlotType,Z_Param_SlotType);
	P_GET_PROPERTY(FIntProperty,Z_Param_SlotIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->Common_CanInstallModule(Z_Param_ItemID,ESlotType(Z_Param_SlotType),Z_Param_SlotIndex);
	P_NATIVE_END;
}
// ********** End Class UFittingWindowWidget Function Common_CanInstallModule **********************

// ********** Begin Class UFittingWindowWidget Function Common_GetShipFittingInterface *************
struct Z_Construct_UFunction_UFittingWindowWidget_Common_GetShipFittingInterface_Statics
{
	struct FittingWindowWidget_eventCommon_GetShipFittingInterface_Parms
	{
		TScriptInterface<IShipFittingInterface> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Fitting Window" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/FittingWindowWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FInterfacePropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FInterfacePropertyParams Z_Construct_UFunction_UFittingWindowWidget_Common_GetShipFittingInterface_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0014000000000580, UECodeGen_Private::EPropertyGenFlags::Interface, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FittingWindowWidget_eventCommon_GetShipFittingInterface_Parms, ReturnValue), Z_Construct_UClass_UShipFittingInterface_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFittingWindowWidget_Common_GetShipFittingInterface_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFittingWindowWidget_Common_GetShipFittingInterface_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFittingWindowWidget_Common_GetShipFittingInterface_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFittingWindowWidget_Common_GetShipFittingInterface_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UFittingWindowWidget, nullptr, "Common_GetShipFittingInterface", Z_Construct_UFunction_UFittingWindowWidget_Common_GetShipFittingInterface_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFittingWindowWidget_Common_GetShipFittingInterface_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFittingWindowWidget_Common_GetShipFittingInterface_Statics::FittingWindowWidget_eventCommon_GetShipFittingInterface_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFittingWindowWidget_Common_GetShipFittingInterface_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFittingWindowWidget_Common_GetShipFittingInterface_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UFittingWindowWidget_Common_GetShipFittingInterface_Statics::FittingWindowWidget_eventCommon_GetShipFittingInterface_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFittingWindowWidget_Common_GetShipFittingInterface()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFittingWindowWidget_Common_GetShipFittingInterface_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFittingWindowWidget::execCommon_GetShipFittingInterface)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TScriptInterface<IShipFittingInterface>*)Z_Param__Result=P_THIS->Common_GetShipFittingInterface();
	P_NATIVE_END;
}
// ********** End Class UFittingWindowWidget Function Common_GetShipFittingInterface ***************

// ********** Begin Class UFittingWindowWidget Function OnModuleInstalled **************************
struct FittingWindowWidget_eventOnModuleInstalled_Parms
{
	ESlotType SlotType;
	int32 SlotIndex;
};
static FName NAME_UFittingWindowWidget_OnModuleInstalled = FName(TEXT("OnModuleInstalled"));
void UFittingWindowWidget::OnModuleInstalled(ESlotType SlotType, int32 SlotIndex)
{
	FittingWindowWidget_eventOnModuleInstalled_Parms Parms;
	Parms.SlotType=SlotType;
	Parms.SlotIndex=SlotIndex;
	UFunction* Func = FindFunctionChecked(NAME_UFittingWindowWidget_OnModuleInstalled);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UFittingWindowWidget_OnModuleInstalled_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Fitting Window|Events" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/FittingWindowWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_SlotType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SlotType;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UFittingWindowWidget_OnModuleInstalled_Statics::NewProp_SlotType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UFittingWindowWidget_OnModuleInstalled_Statics::NewProp_SlotType = { "SlotType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FittingWindowWidget_eventOnModuleInstalled_Parms, SlotType), Z_Construct_UEnum_Echoes_ESlotType, METADATA_PARAMS(0, nullptr) }; // 780113368
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UFittingWindowWidget_OnModuleInstalled_Statics::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FittingWindowWidget_eventOnModuleInstalled_Parms, SlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFittingWindowWidget_OnModuleInstalled_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFittingWindowWidget_OnModuleInstalled_Statics::NewProp_SlotType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFittingWindowWidget_OnModuleInstalled_Statics::NewProp_SlotType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFittingWindowWidget_OnModuleInstalled_Statics::NewProp_SlotIndex,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFittingWindowWidget_OnModuleInstalled_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFittingWindowWidget_OnModuleInstalled_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UFittingWindowWidget, nullptr, "OnModuleInstalled", Z_Construct_UFunction_UFittingWindowWidget_OnModuleInstalled_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFittingWindowWidget_OnModuleInstalled_Statics::PropPointers), sizeof(FittingWindowWidget_eventOnModuleInstalled_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFittingWindowWidget_OnModuleInstalled_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFittingWindowWidget_OnModuleInstalled_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(FittingWindowWidget_eventOnModuleInstalled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFittingWindowWidget_OnModuleInstalled()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFittingWindowWidget_OnModuleInstalled_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UFittingWindowWidget Function OnModuleInstalled ****************************

// ********** Begin Class UFittingWindowWidget Function OnModuleUninstalled ************************
struct FittingWindowWidget_eventOnModuleUninstalled_Parms
{
	ESlotType SlotType;
	int32 SlotIndex;
};
static FName NAME_UFittingWindowWidget_OnModuleUninstalled = FName(TEXT("OnModuleUninstalled"));
void UFittingWindowWidget::OnModuleUninstalled(ESlotType SlotType, int32 SlotIndex)
{
	FittingWindowWidget_eventOnModuleUninstalled_Parms Parms;
	Parms.SlotType=SlotType;
	Parms.SlotIndex=SlotIndex;
	UFunction* Func = FindFunctionChecked(NAME_UFittingWindowWidget_OnModuleUninstalled);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UFittingWindowWidget_OnModuleUninstalled_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Fitting Window|Events" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/FittingWindowWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_SlotType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SlotType;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UFittingWindowWidget_OnModuleUninstalled_Statics::NewProp_SlotType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UFittingWindowWidget_OnModuleUninstalled_Statics::NewProp_SlotType = { "SlotType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FittingWindowWidget_eventOnModuleUninstalled_Parms, SlotType), Z_Construct_UEnum_Echoes_ESlotType, METADATA_PARAMS(0, nullptr) }; // 780113368
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UFittingWindowWidget_OnModuleUninstalled_Statics::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FittingWindowWidget_eventOnModuleUninstalled_Parms, SlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFittingWindowWidget_OnModuleUninstalled_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFittingWindowWidget_OnModuleUninstalled_Statics::NewProp_SlotType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFittingWindowWidget_OnModuleUninstalled_Statics::NewProp_SlotType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFittingWindowWidget_OnModuleUninstalled_Statics::NewProp_SlotIndex,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFittingWindowWidget_OnModuleUninstalled_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFittingWindowWidget_OnModuleUninstalled_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UFittingWindowWidget, nullptr, "OnModuleUninstalled", Z_Construct_UFunction_UFittingWindowWidget_OnModuleUninstalled_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFittingWindowWidget_OnModuleUninstalled_Statics::PropPointers), sizeof(FittingWindowWidget_eventOnModuleUninstalled_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFittingWindowWidget_OnModuleUninstalled_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFittingWindowWidget_OnModuleUninstalled_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(FittingWindowWidget_eventOnModuleUninstalled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFittingWindowWidget_OnModuleUninstalled()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFittingWindowWidget_OnModuleUninstalled_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UFittingWindowWidget Function OnModuleUninstalled **************************

// ********** Begin Class UFittingWindowWidget Function ServerRPC_InstallModule ********************
struct Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_InstallModule_Statics
{
	struct FittingWindowWidget_eventServerRPC_InstallModule_Parms
	{
		int32 ItemID;
		ESlotType SlotType;
		int32 SlotIndex;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Fitting Window" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ============================================================================\n// SERVER RPC\n// ============================================================================\n" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/Fitting/FittingWindowWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "SERVER RPC" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ItemID;
	static const UECodeGen_Private::FBytePropertyParams NewProp_SlotType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SlotType;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_InstallModule_Statics::NewProp_ItemID = { "ItemID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FittingWindowWidget_eventServerRPC_InstallModule_Parms, ItemID), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_InstallModule_Statics::NewProp_SlotType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_InstallModule_Statics::NewProp_SlotType = { "SlotType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FittingWindowWidget_eventServerRPC_InstallModule_Parms, SlotType), Z_Construct_UEnum_Echoes_ESlotType, METADATA_PARAMS(0, nullptr) }; // 780113368
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_InstallModule_Statics::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FittingWindowWidget_eventServerRPC_InstallModule_Parms, SlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_InstallModule_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_InstallModule_Statics::NewProp_ItemID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_InstallModule_Statics::NewProp_SlotType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_InstallModule_Statics::NewProp_SlotType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_InstallModule_Statics::NewProp_SlotIndex,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_InstallModule_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_InstallModule_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UFittingWindowWidget, nullptr, "ServerRPC_InstallModule", Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_InstallModule_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_InstallModule_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_InstallModule_Statics::FittingWindowWidget_eventServerRPC_InstallModule_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_InstallModule_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_InstallModule_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_InstallModule_Statics::FittingWindowWidget_eventServerRPC_InstallModule_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_InstallModule()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_InstallModule_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFittingWindowWidget::execServerRPC_InstallModule)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_ItemID);
	P_GET_ENUM(ESlotType,Z_Param_SlotType);
	P_GET_PROPERTY(FIntProperty,Z_Param_SlotIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerRPC_InstallModule(Z_Param_ItemID,ESlotType(Z_Param_SlotType),Z_Param_SlotIndex);
	P_NATIVE_END;
}
// ********** End Class UFittingWindowWidget Function ServerRPC_InstallModule **********************

// ********** Begin Class UFittingWindowWidget Function ServerRPC_SwapModules **********************
struct Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_SwapModules_Statics
{
	struct FittingWindowWidget_eventServerRPC_SwapModules_Parms
	{
		ESlotType FromType;
		int32 FromIndex;
		ESlotType ToType;
		int32 ToIndex;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Fitting Window" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/FittingWindowWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_FromType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_FromType;
	static const UECodeGen_Private::FIntPropertyParams NewProp_FromIndex;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ToType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ToType;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ToIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_SwapModules_Statics::NewProp_FromType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_SwapModules_Statics::NewProp_FromType = { "FromType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FittingWindowWidget_eventServerRPC_SwapModules_Parms, FromType), Z_Construct_UEnum_Echoes_ESlotType, METADATA_PARAMS(0, nullptr) }; // 780113368
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_SwapModules_Statics::NewProp_FromIndex = { "FromIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FittingWindowWidget_eventServerRPC_SwapModules_Parms, FromIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_SwapModules_Statics::NewProp_ToType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_SwapModules_Statics::NewProp_ToType = { "ToType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FittingWindowWidget_eventServerRPC_SwapModules_Parms, ToType), Z_Construct_UEnum_Echoes_ESlotType, METADATA_PARAMS(0, nullptr) }; // 780113368
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_SwapModules_Statics::NewProp_ToIndex = { "ToIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FittingWindowWidget_eventServerRPC_SwapModules_Parms, ToIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_SwapModules_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_SwapModules_Statics::NewProp_FromType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_SwapModules_Statics::NewProp_FromType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_SwapModules_Statics::NewProp_FromIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_SwapModules_Statics::NewProp_ToType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_SwapModules_Statics::NewProp_ToType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_SwapModules_Statics::NewProp_ToIndex,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_SwapModules_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_SwapModules_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UFittingWindowWidget, nullptr, "ServerRPC_SwapModules", Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_SwapModules_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_SwapModules_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_SwapModules_Statics::FittingWindowWidget_eventServerRPC_SwapModules_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_SwapModules_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_SwapModules_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_SwapModules_Statics::FittingWindowWidget_eventServerRPC_SwapModules_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_SwapModules()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_SwapModules_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFittingWindowWidget::execServerRPC_SwapModules)
{
	P_GET_ENUM(ESlotType,Z_Param_FromType);
	P_GET_PROPERTY(FIntProperty,Z_Param_FromIndex);
	P_GET_ENUM(ESlotType,Z_Param_ToType);
	P_GET_PROPERTY(FIntProperty,Z_Param_ToIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerRPC_SwapModules(ESlotType(Z_Param_FromType),Z_Param_FromIndex,ESlotType(Z_Param_ToType),Z_Param_ToIndex);
	P_NATIVE_END;
}
// ********** End Class UFittingWindowWidget Function ServerRPC_SwapModules ************************

// ********** Begin Class UFittingWindowWidget Function ServerRPC_UninstallModule ******************
struct Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_UninstallModule_Statics
{
	struct FittingWindowWidget_eventServerRPC_UninstallModule_Parms
	{
		ESlotType SlotType;
		int32 SlotIndex;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Fitting Window" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/FittingWindowWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_SlotType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SlotType;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_UninstallModule_Statics::NewProp_SlotType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_UninstallModule_Statics::NewProp_SlotType = { "SlotType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FittingWindowWidget_eventServerRPC_UninstallModule_Parms, SlotType), Z_Construct_UEnum_Echoes_ESlotType, METADATA_PARAMS(0, nullptr) }; // 780113368
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_UninstallModule_Statics::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FittingWindowWidget_eventServerRPC_UninstallModule_Parms, SlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_UninstallModule_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_UninstallModule_Statics::NewProp_SlotType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_UninstallModule_Statics::NewProp_SlotType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_UninstallModule_Statics::NewProp_SlotIndex,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_UninstallModule_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_UninstallModule_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UFittingWindowWidget, nullptr, "ServerRPC_UninstallModule", Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_UninstallModule_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_UninstallModule_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_UninstallModule_Statics::FittingWindowWidget_eventServerRPC_UninstallModule_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_UninstallModule_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_UninstallModule_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_UninstallModule_Statics::FittingWindowWidget_eventServerRPC_UninstallModule_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_UninstallModule()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_UninstallModule_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFittingWindowWidget::execServerRPC_UninstallModule)
{
	P_GET_ENUM(ESlotType,Z_Param_SlotType);
	P_GET_PROPERTY(FIntProperty,Z_Param_SlotIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerRPC_UninstallModule(ESlotType(Z_Param_SlotType),Z_Param_SlotIndex);
	P_NATIVE_END;
}
// ********** End Class UFittingWindowWidget Function ServerRPC_UninstallModule ********************

// ********** Begin Class UFittingWindowWidget *****************************************************
void UFittingWindowWidget::StaticRegisterNativesUFittingWindowWidget()
{
	UClass* Class = UFittingWindowWidget::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ClientOnly_RefreshFitting", &UFittingWindowWidget::execClientOnly_RefreshFitting },
		{ "ClientOnly_UpdateCPUDisplay", &UFittingWindowWidget::execClientOnly_UpdateCPUDisplay },
		{ "ClientOnly_UpdatePowergridDisplay", &UFittingWindowWidget::execClientOnly_UpdatePowergridDisplay },
		{ "ClientOnly_UpdateSlot", &UFittingWindowWidget::execClientOnly_UpdateSlot },
		{ "Common_CalculateFitting", &UFittingWindowWidget::execCommon_CalculateFitting },
		{ "Common_CanInstallModule", &UFittingWindowWidget::execCommon_CanInstallModule },
		{ "Common_GetShipFittingInterface", &UFittingWindowWidget::execCommon_GetShipFittingInterface },
		{ "ServerRPC_InstallModule", &UFittingWindowWidget::execServerRPC_InstallModule },
		{ "ServerRPC_SwapModules", &UFittingWindowWidget::execServerRPC_SwapModules },
		{ "ServerRPC_UninstallModule", &UFittingWindowWidget::execServerRPC_UninstallModule },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UFittingWindowWidget;
UClass* UFittingWindowWidget::GetPrivateStaticClass()
{
	using TClass = UFittingWindowWidget;
	if (!Z_Registration_Info_UClass_UFittingWindowWidget.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("FittingWindowWidget"),
			Z_Registration_Info_UClass_UFittingWindowWidget.InnerSingleton,
			StaticRegisterNativesUFittingWindowWidget,
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
	return Z_Registration_Info_UClass_UFittingWindowWidget.InnerSingleton;
}
UClass* Z_Construct_UClass_UFittingWindowWidget_NoRegister()
{
	return UFittingWindowWidget::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UFittingWindowWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Fitting Window Widget - Ship equipment management in hangar\n * Allows drag & drop installation of modules\n * Validates powergrid and CPU requirements\n */" },
#endif
		{ "IncludePath", "UI/Widgets/Fitting/FittingWindowWidget.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/FittingWindowWidget.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fitting Window Widget - Ship equipment management in hangar\nAllows drag & drop installation of modules\nValidates powergrid and CPU requirements" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HighSlotsContainer_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "FittingWindowWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ============================================================================\n// WIDGET REFERENCES\n// ============================================================================\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/FittingWindowWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "WIDGET REFERENCES" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MidSlotsContainer_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "FittingWindowWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/FittingWindowWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LowSlotsContainer_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "FittingWindowWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/FittingWindowWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PowergridBar_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "FittingWindowWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/FittingWindowWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PowergridText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "FittingWindowWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/FittingWindowWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CPUBar_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "FittingWindowWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/FittingWindowWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CPUText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "FittingWindowWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/FittingWindowWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FittingSlotWidgetClass_MetaData[] = {
		{ "Category", "Fitting Window" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ============================================================================\n// CONFIGURATION\n// ============================================================================\n" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/Fitting/FittingWindowWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "CONFIGURATION" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnFittingChanged_MetaData[] = {
		{ "Category", "Fitting Window|Events" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/FittingWindowWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HighSlotWidgets_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Store slot widgets in separate arrays per slot type because UHT doesn't support\n// using TArray as the value in a TMap for reflected properties.\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/FittingWindowWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Store slot widgets in separate arrays per slot type because UHT doesn't support\nusing TArray as the value in a TMap for reflected properties." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MidSlotWidgets_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/FittingWindowWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LowSlotWidgets_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/FittingWindowWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CachedPlayerController_MetaData[] = {
		{ "ModuleRelativePath", "UI/Widgets/Fitting/FittingWindowWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CachedShipPawn_MetaData[] = {
		{ "ModuleRelativePath", "UI/Widgets/Fitting/FittingWindowWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HighSlotsContainer;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MidSlotsContainer;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LowSlotsContainer;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PowergridBar;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PowergridText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CPUBar;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CPUText;
	static const UECodeGen_Private::FClassPropertyParams NewProp_FittingSlotWidgetClass;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnFittingChanged;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HighSlotWidgets_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_HighSlotWidgets;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MidSlotWidgets_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_MidSlotWidgets;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LowSlotWidgets_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_LowSlotWidgets;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CachedPlayerController;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CachedShipPawn;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_RefreshFitting, "ClientOnly_RefreshFitting" }, // 715917237
		{ &Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdateCPUDisplay, "ClientOnly_UpdateCPUDisplay" }, // 3916894761
		{ &Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdatePowergridDisplay, "ClientOnly_UpdatePowergridDisplay" }, // 3580691261
		{ &Z_Construct_UFunction_UFittingWindowWidget_ClientOnly_UpdateSlot, "ClientOnly_UpdateSlot" }, // 1575876113
		{ &Z_Construct_UFunction_UFittingWindowWidget_Common_CalculateFitting, "Common_CalculateFitting" }, // 3488351073
		{ &Z_Construct_UFunction_UFittingWindowWidget_Common_CanInstallModule, "Common_CanInstallModule" }, // 2135637020
		{ &Z_Construct_UFunction_UFittingWindowWidget_Common_GetShipFittingInterface, "Common_GetShipFittingInterface" }, // 337623498
		{ &Z_Construct_UDelegateFunction_UFittingWindowWidget_OnFittingChanged__DelegateSignature, "OnFittingChanged__DelegateSignature" }, // 615334367
		{ &Z_Construct_UFunction_UFittingWindowWidget_OnModuleInstalled, "OnModuleInstalled" }, // 4281645983
		{ &Z_Construct_UFunction_UFittingWindowWidget_OnModuleUninstalled, "OnModuleUninstalled" }, // 738410275
		{ &Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_InstallModule, "ServerRPC_InstallModule" }, // 3398073721
		{ &Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_SwapModules, "ServerRPC_SwapModules" }, // 2393198210
		{ &Z_Construct_UFunction_UFittingWindowWidget_ServerRPC_UninstallModule, "ServerRPC_UninstallModule" }, // 3681694807
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFittingWindowWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFittingWindowWidget_Statics::NewProp_HighSlotsContainer = { "HighSlotsContainer", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFittingWindowWidget, HighSlotsContainer), Z_Construct_UClass_UVerticalBox_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HighSlotsContainer_MetaData), NewProp_HighSlotsContainer_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFittingWindowWidget_Statics::NewProp_MidSlotsContainer = { "MidSlotsContainer", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFittingWindowWidget, MidSlotsContainer), Z_Construct_UClass_UVerticalBox_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MidSlotsContainer_MetaData), NewProp_MidSlotsContainer_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFittingWindowWidget_Statics::NewProp_LowSlotsContainer = { "LowSlotsContainer", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFittingWindowWidget, LowSlotsContainer), Z_Construct_UClass_UVerticalBox_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LowSlotsContainer_MetaData), NewProp_LowSlotsContainer_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFittingWindowWidget_Statics::NewProp_PowergridBar = { "PowergridBar", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFittingWindowWidget, PowergridBar), Z_Construct_UClass_UProgressBar_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PowergridBar_MetaData), NewProp_PowergridBar_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFittingWindowWidget_Statics::NewProp_PowergridText = { "PowergridText", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFittingWindowWidget, PowergridText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PowergridText_MetaData), NewProp_PowergridText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFittingWindowWidget_Statics::NewProp_CPUBar = { "CPUBar", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFittingWindowWidget, CPUBar), Z_Construct_UClass_UProgressBar_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CPUBar_MetaData), NewProp_CPUBar_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFittingWindowWidget_Statics::NewProp_CPUText = { "CPUText", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFittingWindowWidget, CPUText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CPUText_MetaData), NewProp_CPUText_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UFittingWindowWidget_Statics::NewProp_FittingSlotWidgetClass = { "FittingSlotWidgetClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFittingWindowWidget, FittingSlotWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UFittingSlotWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FittingSlotWidgetClass_MetaData), NewProp_FittingSlotWidgetClass_MetaData) };
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UFittingWindowWidget_Statics::NewProp_OnFittingChanged = { "OnFittingChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFittingWindowWidget, OnFittingChanged), Z_Construct_UDelegateFunction_UFittingWindowWidget_OnFittingChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnFittingChanged_MetaData), NewProp_OnFittingChanged_MetaData) }; // 615334367
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFittingWindowWidget_Statics::NewProp_HighSlotWidgets_Inner = { "HighSlotWidgets", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UFittingSlotWidget_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UFittingWindowWidget_Statics::NewProp_HighSlotWidgets = { "HighSlotWidgets", nullptr, (EPropertyFlags)0x0020088000000008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFittingWindowWidget, HighSlotWidgets), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HighSlotWidgets_MetaData), NewProp_HighSlotWidgets_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFittingWindowWidget_Statics::NewProp_MidSlotWidgets_Inner = { "MidSlotWidgets", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UFittingSlotWidget_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UFittingWindowWidget_Statics::NewProp_MidSlotWidgets = { "MidSlotWidgets", nullptr, (EPropertyFlags)0x0020088000000008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFittingWindowWidget, MidSlotWidgets), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MidSlotWidgets_MetaData), NewProp_MidSlotWidgets_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFittingWindowWidget_Statics::NewProp_LowSlotWidgets_Inner = { "LowSlotWidgets", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UFittingSlotWidget_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UFittingWindowWidget_Statics::NewProp_LowSlotWidgets = { "LowSlotWidgets", nullptr, (EPropertyFlags)0x0020088000000008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFittingWindowWidget, LowSlotWidgets), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LowSlotWidgets_MetaData), NewProp_LowSlotWidgets_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFittingWindowWidget_Statics::NewProp_CachedPlayerController = { "CachedPlayerController", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFittingWindowWidget, CachedPlayerController), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CachedPlayerController_MetaData), NewProp_CachedPlayerController_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFittingWindowWidget_Statics::NewProp_CachedShipPawn = { "CachedShipPawn", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFittingWindowWidget, CachedShipPawn), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CachedShipPawn_MetaData), NewProp_CachedShipPawn_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UFittingWindowWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFittingWindowWidget_Statics::NewProp_HighSlotsContainer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFittingWindowWidget_Statics::NewProp_MidSlotsContainer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFittingWindowWidget_Statics::NewProp_LowSlotsContainer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFittingWindowWidget_Statics::NewProp_PowergridBar,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFittingWindowWidget_Statics::NewProp_PowergridText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFittingWindowWidget_Statics::NewProp_CPUBar,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFittingWindowWidget_Statics::NewProp_CPUText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFittingWindowWidget_Statics::NewProp_FittingSlotWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFittingWindowWidget_Statics::NewProp_OnFittingChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFittingWindowWidget_Statics::NewProp_HighSlotWidgets_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFittingWindowWidget_Statics::NewProp_HighSlotWidgets,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFittingWindowWidget_Statics::NewProp_MidSlotWidgets_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFittingWindowWidget_Statics::NewProp_MidSlotWidgets,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFittingWindowWidget_Statics::NewProp_LowSlotWidgets_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFittingWindowWidget_Statics::NewProp_LowSlotWidgets,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFittingWindowWidget_Statics::NewProp_CachedPlayerController,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFittingWindowWidget_Statics::NewProp_CachedShipPawn,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UFittingWindowWidget_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UFittingWindowWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UFittingWindowWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UFittingWindowWidget_Statics::ClassParams = {
	&UFittingWindowWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UFittingWindowWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UFittingWindowWidget_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UFittingWindowWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UFittingWindowWidget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UFittingWindowWidget()
{
	if (!Z_Registration_Info_UClass_UFittingWindowWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UFittingWindowWidget.OuterSingleton, Z_Construct_UClass_UFittingWindowWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UFittingWindowWidget.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UFittingWindowWidget);
UFittingWindowWidget::~UFittingWindowWidget() {}
// ********** End Class UFittingWindowWidget *******************************************************

// ********** Begin Delegate FOnModuleDropped ******************************************************
struct Z_Construct_UDelegateFunction_UFittingSlotWidget_OnModuleDropped__DelegateSignature_Statics
{
	struct FittingSlotWidget_eventOnModuleDropped_Parms
	{
		ESlotType SlotType;
		int32 SlotIndex;
		int32 ItemID;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI/Widgets/Fitting/FittingWindowWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_SlotType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SlotType;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ItemID;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_UFittingSlotWidget_OnModuleDropped__DelegateSignature_Statics::NewProp_SlotType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_UFittingSlotWidget_OnModuleDropped__DelegateSignature_Statics::NewProp_SlotType = { "SlotType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FittingSlotWidget_eventOnModuleDropped_Parms, SlotType), Z_Construct_UEnum_Echoes_ESlotType, METADATA_PARAMS(0, nullptr) }; // 780113368
const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_UFittingSlotWidget_OnModuleDropped__DelegateSignature_Statics::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FittingSlotWidget_eventOnModuleDropped_Parms, SlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_UFittingSlotWidget_OnModuleDropped__DelegateSignature_Statics::NewProp_ItemID = { "ItemID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FittingSlotWidget_eventOnModuleDropped_Parms, ItemID), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UFittingSlotWidget_OnModuleDropped__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UFittingSlotWidget_OnModuleDropped__DelegateSignature_Statics::NewProp_SlotType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UFittingSlotWidget_OnModuleDropped__DelegateSignature_Statics::NewProp_SlotType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UFittingSlotWidget_OnModuleDropped__DelegateSignature_Statics::NewProp_SlotIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UFittingSlotWidget_OnModuleDropped__DelegateSignature_Statics::NewProp_ItemID,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UFittingSlotWidget_OnModuleDropped__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_UFittingSlotWidget_OnModuleDropped__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UFittingSlotWidget, nullptr, "OnModuleDropped__DelegateSignature", Z_Construct_UDelegateFunction_UFittingSlotWidget_OnModuleDropped__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UFittingSlotWidget_OnModuleDropped__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UFittingSlotWidget_OnModuleDropped__DelegateSignature_Statics::FittingSlotWidget_eventOnModuleDropped_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UFittingSlotWidget_OnModuleDropped__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UFittingSlotWidget_OnModuleDropped__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_UFittingSlotWidget_OnModuleDropped__DelegateSignature_Statics::FittingSlotWidget_eventOnModuleDropped_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_UFittingSlotWidget_OnModuleDropped__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UFittingSlotWidget_OnModuleDropped__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void UFittingSlotWidget::FOnModuleDropped_DelegateWrapper(const FMulticastScriptDelegate& OnModuleDropped, ESlotType SlotType, int32 SlotIndex, int32 ItemID)
{
	struct FittingSlotWidget_eventOnModuleDropped_Parms
	{
		ESlotType SlotType;
		int32 SlotIndex;
		int32 ItemID;
	};
	FittingSlotWidget_eventOnModuleDropped_Parms Parms;
	Parms.SlotType=SlotType;
	Parms.SlotIndex=SlotIndex;
	Parms.ItemID=ItemID;
	OnModuleDropped.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnModuleDropped ********************************************************

// ********** Begin Delegate FOnModuleRemoved ******************************************************
struct Z_Construct_UDelegateFunction_UFittingSlotWidget_OnModuleRemoved__DelegateSignature_Statics
{
	struct FittingSlotWidget_eventOnModuleRemoved_Parms
	{
		ESlotType SlotType;
		int32 SlotIndex;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI/Widgets/Fitting/FittingWindowWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_SlotType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SlotType;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_UFittingSlotWidget_OnModuleRemoved__DelegateSignature_Statics::NewProp_SlotType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_UFittingSlotWidget_OnModuleRemoved__DelegateSignature_Statics::NewProp_SlotType = { "SlotType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FittingSlotWidget_eventOnModuleRemoved_Parms, SlotType), Z_Construct_UEnum_Echoes_ESlotType, METADATA_PARAMS(0, nullptr) }; // 780113368
const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_UFittingSlotWidget_OnModuleRemoved__DelegateSignature_Statics::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FittingSlotWidget_eventOnModuleRemoved_Parms, SlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UFittingSlotWidget_OnModuleRemoved__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UFittingSlotWidget_OnModuleRemoved__DelegateSignature_Statics::NewProp_SlotType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UFittingSlotWidget_OnModuleRemoved__DelegateSignature_Statics::NewProp_SlotType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UFittingSlotWidget_OnModuleRemoved__DelegateSignature_Statics::NewProp_SlotIndex,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UFittingSlotWidget_OnModuleRemoved__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_UFittingSlotWidget_OnModuleRemoved__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UFittingSlotWidget, nullptr, "OnModuleRemoved__DelegateSignature", Z_Construct_UDelegateFunction_UFittingSlotWidget_OnModuleRemoved__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UFittingSlotWidget_OnModuleRemoved__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UFittingSlotWidget_OnModuleRemoved__DelegateSignature_Statics::FittingSlotWidget_eventOnModuleRemoved_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UFittingSlotWidget_OnModuleRemoved__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UFittingSlotWidget_OnModuleRemoved__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_UFittingSlotWidget_OnModuleRemoved__DelegateSignature_Statics::FittingSlotWidget_eventOnModuleRemoved_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_UFittingSlotWidget_OnModuleRemoved__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UFittingSlotWidget_OnModuleRemoved__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void UFittingSlotWidget::FOnModuleRemoved_DelegateWrapper(const FMulticastScriptDelegate& OnModuleRemoved, ESlotType SlotType, int32 SlotIndex)
{
	struct FittingSlotWidget_eventOnModuleRemoved_Parms
	{
		ESlotType SlotType;
		int32 SlotIndex;
	};
	FittingSlotWidget_eventOnModuleRemoved_Parms Parms;
	Parms.SlotType=SlotType;
	Parms.SlotIndex=SlotIndex;
	OnModuleRemoved.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnModuleRemoved ********************************************************

// ********** Begin Class UFittingSlotWidget Function InitializeSlot *******************************
struct Z_Construct_UFunction_UFittingSlotWidget_InitializeSlot_Statics
{
	struct FittingSlotWidget_eventInitializeSlot_Parms
	{
		ESlotType InSlotType;
		int32 InSlotIndex;
		FCommon_ItemSlot InSlotData;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Fitting Slot" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/FittingWindowWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InSlotData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_InSlotType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InSlotType;
	static const UECodeGen_Private::FIntPropertyParams NewProp_InSlotIndex;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InSlotData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UFittingSlotWidget_InitializeSlot_Statics::NewProp_InSlotType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UFittingSlotWidget_InitializeSlot_Statics::NewProp_InSlotType = { "InSlotType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FittingSlotWidget_eventInitializeSlot_Parms, InSlotType), Z_Construct_UEnum_Echoes_ESlotType, METADATA_PARAMS(0, nullptr) }; // 780113368
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UFittingSlotWidget_InitializeSlot_Statics::NewProp_InSlotIndex = { "InSlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FittingSlotWidget_eventInitializeSlot_Parms, InSlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UFittingSlotWidget_InitializeSlot_Statics::NewProp_InSlotData = { "InSlotData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FittingSlotWidget_eventInitializeSlot_Parms, InSlotData), Z_Construct_UScriptStruct_FCommon_ItemSlot, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InSlotData_MetaData), NewProp_InSlotData_MetaData) }; // 771062216
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFittingSlotWidget_InitializeSlot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFittingSlotWidget_InitializeSlot_Statics::NewProp_InSlotType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFittingSlotWidget_InitializeSlot_Statics::NewProp_InSlotType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFittingSlotWidget_InitializeSlot_Statics::NewProp_InSlotIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFittingSlotWidget_InitializeSlot_Statics::NewProp_InSlotData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFittingSlotWidget_InitializeSlot_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFittingSlotWidget_InitializeSlot_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UFittingSlotWidget, nullptr, "InitializeSlot", Z_Construct_UFunction_UFittingSlotWidget_InitializeSlot_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFittingSlotWidget_InitializeSlot_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFittingSlotWidget_InitializeSlot_Statics::FittingSlotWidget_eventInitializeSlot_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFittingSlotWidget_InitializeSlot_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFittingSlotWidget_InitializeSlot_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UFittingSlotWidget_InitializeSlot_Statics::FittingSlotWidget_eventInitializeSlot_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFittingSlotWidget_InitializeSlot()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFittingSlotWidget_InitializeSlot_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFittingSlotWidget::execInitializeSlot)
{
	P_GET_ENUM(ESlotType,Z_Param_InSlotType);
	P_GET_PROPERTY(FIntProperty,Z_Param_InSlotIndex);
	P_GET_STRUCT_REF(FCommon_ItemSlot,Z_Param_Out_InSlotData);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializeSlot(ESlotType(Z_Param_InSlotType),Z_Param_InSlotIndex,Z_Param_Out_InSlotData);
	P_NATIVE_END;
}
// ********** End Class UFittingSlotWidget Function InitializeSlot *********************************

// ********** Begin Class UFittingSlotWidget Function OnSlotHighlighted ****************************
struct FittingSlotWidget_eventOnSlotHighlighted_Parms
{
	bool bHighlighted;
};
static FName NAME_UFittingSlotWidget_OnSlotHighlighted = FName(TEXT("OnSlotHighlighted"));
void UFittingSlotWidget::OnSlotHighlighted(bool bHighlighted)
{
	FittingSlotWidget_eventOnSlotHighlighted_Parms Parms;
	Parms.bHighlighted=bHighlighted ? true : false;
	UFunction* Func = FindFunctionChecked(NAME_UFittingSlotWidget_OnSlotHighlighted);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UFittingSlotWidget_OnSlotHighlighted_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Fitting Slot|Events" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/FittingWindowWidget.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bHighlighted_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHighlighted;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UFittingSlotWidget_OnSlotHighlighted_Statics::NewProp_bHighlighted_SetBit(void* Obj)
{
	((FittingSlotWidget_eventOnSlotHighlighted_Parms*)Obj)->bHighlighted = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UFittingSlotWidget_OnSlotHighlighted_Statics::NewProp_bHighlighted = { "bHighlighted", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FittingSlotWidget_eventOnSlotHighlighted_Parms), &Z_Construct_UFunction_UFittingSlotWidget_OnSlotHighlighted_Statics::NewProp_bHighlighted_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFittingSlotWidget_OnSlotHighlighted_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFittingSlotWidget_OnSlotHighlighted_Statics::NewProp_bHighlighted,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFittingSlotWidget_OnSlotHighlighted_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFittingSlotWidget_OnSlotHighlighted_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UFittingSlotWidget, nullptr, "OnSlotHighlighted", Z_Construct_UFunction_UFittingSlotWidget_OnSlotHighlighted_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFittingSlotWidget_OnSlotHighlighted_Statics::PropPointers), sizeof(FittingSlotWidget_eventOnSlotHighlighted_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFittingSlotWidget_OnSlotHighlighted_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFittingSlotWidget_OnSlotHighlighted_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(FittingSlotWidget_eventOnSlotHighlighted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFittingSlotWidget_OnSlotHighlighted()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFittingSlotWidget_OnSlotHighlighted_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UFittingSlotWidget Function OnSlotHighlighted ******************************

// ********** Begin Class UFittingSlotWidget Function UpdateDisplay ********************************
struct Z_Construct_UFunction_UFittingSlotWidget_UpdateDisplay_Statics
{
	struct FittingSlotWidget_eventUpdateDisplay_Parms
	{
		FCommon_ItemSlot InSlotData;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Fitting Slot" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/FittingWindowWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InSlotData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_InSlotData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UFittingSlotWidget_UpdateDisplay_Statics::NewProp_InSlotData = { "InSlotData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FittingSlotWidget_eventUpdateDisplay_Parms, InSlotData), Z_Construct_UScriptStruct_FCommon_ItemSlot, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InSlotData_MetaData), NewProp_InSlotData_MetaData) }; // 771062216
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFittingSlotWidget_UpdateDisplay_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFittingSlotWidget_UpdateDisplay_Statics::NewProp_InSlotData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFittingSlotWidget_UpdateDisplay_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFittingSlotWidget_UpdateDisplay_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UFittingSlotWidget, nullptr, "UpdateDisplay", Z_Construct_UFunction_UFittingSlotWidget_UpdateDisplay_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFittingSlotWidget_UpdateDisplay_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFittingSlotWidget_UpdateDisplay_Statics::FittingSlotWidget_eventUpdateDisplay_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFittingSlotWidget_UpdateDisplay_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFittingSlotWidget_UpdateDisplay_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UFittingSlotWidget_UpdateDisplay_Statics::FittingSlotWidget_eventUpdateDisplay_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFittingSlotWidget_UpdateDisplay()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFittingSlotWidget_UpdateDisplay_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFittingSlotWidget::execUpdateDisplay)
{
	P_GET_STRUCT_REF(FCommon_ItemSlot,Z_Param_Out_InSlotData);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UpdateDisplay(Z_Param_Out_InSlotData);
	P_NATIVE_END;
}
// ********** End Class UFittingSlotWidget Function UpdateDisplay **********************************

// ********** Begin Class UFittingSlotWidget *******************************************************
void UFittingSlotWidget::StaticRegisterNativesUFittingSlotWidget()
{
	UClass* Class = UFittingSlotWidget::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "InitializeSlot", &UFittingSlotWidget::execInitializeSlot },
		{ "UpdateDisplay", &UFittingSlotWidget::execUpdateDisplay },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UFittingSlotWidget;
UClass* UFittingSlotWidget::GetPrivateStaticClass()
{
	using TClass = UFittingSlotWidget;
	if (!Z_Registration_Info_UClass_UFittingSlotWidget.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("FittingSlotWidget"),
			Z_Registration_Info_UClass_UFittingSlotWidget.InnerSingleton,
			StaticRegisterNativesUFittingSlotWidget,
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
	return Z_Registration_Info_UClass_UFittingSlotWidget.InnerSingleton;
}
UClass* Z_Construct_UClass_UFittingSlotWidget_NoRegister()
{
	return UFittingSlotWidget::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UFittingSlotWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Individual Fitting Slot Widget\n * Supports drag & drop\n */" },
#endif
		{ "IncludePath", "UI/Widgets/Fitting/FittingWindowWidget.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/FittingWindowWidget.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Individual Fitting Slot Widget\nSupports drag & drop" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ModuleIcon_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "FittingSlotWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/FittingWindowWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlotBorder_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "FittingSlotWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/FittingWindowWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ModuleNameText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "FittingSlotWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/FittingWindowWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlotNumberText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "FittingSlotWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/FittingWindowWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlotType_MetaData[] = {
		{ "Category", "Fitting Slot" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/FittingWindowWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlotIndex_MetaData[] = {
		{ "Category", "Fitting Slot" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/FittingWindowWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlotData_MetaData[] = {
		{ "Category", "Fitting Slot" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/FittingWindowWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnModuleDropped_MetaData[] = {
		{ "Category", "Fitting Slot|Events" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/FittingWindowWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnModuleRemoved_MetaData[] = {
		{ "Category", "Fitting Slot|Events" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/FittingWindowWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ModuleIcon;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SlotBorder;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ModuleNameText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SlotNumberText;
	static const UECodeGen_Private::FBytePropertyParams NewProp_SlotType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SlotType;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SlotData;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnModuleDropped;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnModuleRemoved;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UFittingSlotWidget_InitializeSlot, "InitializeSlot" }, // 2925915275
		{ &Z_Construct_UDelegateFunction_UFittingSlotWidget_OnModuleDropped__DelegateSignature, "OnModuleDropped__DelegateSignature" }, // 313521861
		{ &Z_Construct_UDelegateFunction_UFittingSlotWidget_OnModuleRemoved__DelegateSignature, "OnModuleRemoved__DelegateSignature" }, // 4058110961
		{ &Z_Construct_UFunction_UFittingSlotWidget_OnSlotHighlighted, "OnSlotHighlighted" }, // 639651717
		{ &Z_Construct_UFunction_UFittingSlotWidget_UpdateDisplay, "UpdateDisplay" }, // 717984565
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFittingSlotWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFittingSlotWidget_Statics::NewProp_ModuleIcon = { "ModuleIcon", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFittingSlotWidget, ModuleIcon), Z_Construct_UClass_UImage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ModuleIcon_MetaData), NewProp_ModuleIcon_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFittingSlotWidget_Statics::NewProp_SlotBorder = { "SlotBorder", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFittingSlotWidget, SlotBorder), Z_Construct_UClass_UBorder_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlotBorder_MetaData), NewProp_SlotBorder_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFittingSlotWidget_Statics::NewProp_ModuleNameText = { "ModuleNameText", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFittingSlotWidget, ModuleNameText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ModuleNameText_MetaData), NewProp_ModuleNameText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFittingSlotWidget_Statics::NewProp_SlotNumberText = { "SlotNumberText", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFittingSlotWidget, SlotNumberText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlotNumberText_MetaData), NewProp_SlotNumberText_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UFittingSlotWidget_Statics::NewProp_SlotType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UFittingSlotWidget_Statics::NewProp_SlotType = { "SlotType", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFittingSlotWidget, SlotType), Z_Construct_UEnum_Echoes_ESlotType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlotType_MetaData), NewProp_SlotType_MetaData) }; // 780113368
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UFittingSlotWidget_Statics::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFittingSlotWidget, SlotIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlotIndex_MetaData), NewProp_SlotIndex_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UFittingSlotWidget_Statics::NewProp_SlotData = { "SlotData", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFittingSlotWidget, SlotData), Z_Construct_UScriptStruct_FCommon_ItemSlot, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlotData_MetaData), NewProp_SlotData_MetaData) }; // 771062216
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UFittingSlotWidget_Statics::NewProp_OnModuleDropped = { "OnModuleDropped", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFittingSlotWidget, OnModuleDropped), Z_Construct_UDelegateFunction_UFittingSlotWidget_OnModuleDropped__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnModuleDropped_MetaData), NewProp_OnModuleDropped_MetaData) }; // 313521861
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UFittingSlotWidget_Statics::NewProp_OnModuleRemoved = { "OnModuleRemoved", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFittingSlotWidget, OnModuleRemoved), Z_Construct_UDelegateFunction_UFittingSlotWidget_OnModuleRemoved__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnModuleRemoved_MetaData), NewProp_OnModuleRemoved_MetaData) }; // 4058110961
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UFittingSlotWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFittingSlotWidget_Statics::NewProp_ModuleIcon,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFittingSlotWidget_Statics::NewProp_SlotBorder,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFittingSlotWidget_Statics::NewProp_ModuleNameText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFittingSlotWidget_Statics::NewProp_SlotNumberText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFittingSlotWidget_Statics::NewProp_SlotType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFittingSlotWidget_Statics::NewProp_SlotType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFittingSlotWidget_Statics::NewProp_SlotIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFittingSlotWidget_Statics::NewProp_SlotData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFittingSlotWidget_Statics::NewProp_OnModuleDropped,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFittingSlotWidget_Statics::NewProp_OnModuleRemoved,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UFittingSlotWidget_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UFittingSlotWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UFittingSlotWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UFittingSlotWidget_Statics::ClassParams = {
	&UFittingSlotWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UFittingSlotWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UFittingSlotWidget_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UFittingSlotWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UFittingSlotWidget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UFittingSlotWidget()
{
	if (!Z_Registration_Info_UClass_UFittingSlotWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UFittingSlotWidget.OuterSingleton, Z_Construct_UClass_UFittingSlotWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UFittingSlotWidget.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UFittingSlotWidget);
UFittingSlotWidget::~UFittingSlotWidget() {}
// ********** End Class UFittingSlotWidget *********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_FittingWindowWidget_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UFittingWindowWidget, UFittingWindowWidget::StaticClass, TEXT("UFittingWindowWidget"), &Z_Registration_Info_UClass_UFittingWindowWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UFittingWindowWidget), 3434468333U) },
		{ Z_Construct_UClass_UFittingSlotWidget, UFittingSlotWidget::StaticClass, TEXT("UFittingSlotWidget"), &Z_Registration_Info_UClass_UFittingSlotWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UFittingSlotWidget), 2301161958U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_FittingWindowWidget_h__Script_Echoes_3153132774(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_FittingWindowWidget_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_FittingWindowWidget_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
