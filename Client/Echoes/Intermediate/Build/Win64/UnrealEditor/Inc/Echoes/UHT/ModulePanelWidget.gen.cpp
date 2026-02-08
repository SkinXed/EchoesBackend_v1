// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ModulePanelWidget.h"
#include "ShipFittingInterface.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeModulePanelWidget() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
ECHOES_API UClass* Z_Construct_UClass_UModulePanelWidget();
ECHOES_API UClass* Z_Construct_UClass_UModulePanelWidget_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UModuleSlotWidget();
ECHOES_API UClass* Z_Construct_UClass_UModuleSlotWidget_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UShipFittingInterface_NoRegister();
ECHOES_API UEnum* Z_Construct_UEnum_Echoes_EModuleState();
ECHOES_API UEnum* Z_Construct_UEnum_Echoes_ESlotType();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnModuleToggled__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_UModuleSlotWidget_OnSlotClicked__DelegateSignature();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FCommon_ItemSlot();
ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APlayerController_NoRegister();
UMG_API UClass* Z_Construct_UClass_UBorder_NoRegister();
UMG_API UClass* Z_Construct_UClass_UImage_NoRegister();
UMG_API UClass* Z_Construct_UClass_UProgressBar_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUniformGridPanel_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FOnModuleToggled ******************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnModuleToggled__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Declare module toggled delegate so it can be used as a UPROPERTY/BlueprintAssignable\n" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Declare module toggled delegate so it can be used as a UPROPERTY/BlueprintAssignable" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnModuleToggled__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnModuleToggled__DelegateSignature", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnModuleToggled__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnModuleToggled__DelegateSignature_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UDelegateFunction_Echoes_OnModuleToggled__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnModuleToggled__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnModuleToggled_DelegateWrapper(const FMulticastScriptDelegate& OnModuleToggled)
{
	OnModuleToggled.ProcessMulticastDelegate<UObject>(NULL);
}
// ********** End Delegate FOnModuleToggled ********************************************************

// ********** Begin Class UModulePanelWidget Function ClientOnly_RefreshAllModules *****************
struct Z_Construct_UFunction_UModulePanelWidget_ClientOnly_RefreshAllModules_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Module Panel" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Refresh all module displays from ship fitting\n\x09 * Call on init or when fitting changes\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Refresh all module displays from ship fitting\nCall on init or when fitting changes" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UModulePanelWidget_ClientOnly_RefreshAllModules_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UModulePanelWidget, nullptr, "ClientOnly_RefreshAllModules", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UModulePanelWidget_ClientOnly_RefreshAllModules_Statics::Function_MetaDataParams), Z_Construct_UFunction_UModulePanelWidget_ClientOnly_RefreshAllModules_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UModulePanelWidget_ClientOnly_RefreshAllModules()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UModulePanelWidget_ClientOnly_RefreshAllModules_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UModulePanelWidget::execClientOnly_RefreshAllModules)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientOnly_RefreshAllModules();
	P_NATIVE_END;
}
// ********** End Class UModulePanelWidget Function ClientOnly_RefreshAllModules *******************

// ********** Begin Class UModulePanelWidget Function ClientOnly_UpdateCooldown ********************
struct Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateCooldown_Statics
{
	struct ModulePanelWidget_eventClientOnly_UpdateCooldown_Parms
	{
		ESlotType SlotType;
		int32 SlotIndex;
		float CooldownRemaining;
		float CooldownTotal;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Module Panel" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Update cooldown visual for a specific slot\n\x09 * Called periodically to show cooldown progress\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Update cooldown visual for a specific slot\nCalled periodically to show cooldown progress" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_SlotType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SlotType;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CooldownRemaining;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CooldownTotal;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateCooldown_Statics::NewProp_SlotType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateCooldown_Statics::NewProp_SlotType = { "SlotType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModulePanelWidget_eventClientOnly_UpdateCooldown_Parms, SlotType), Z_Construct_UEnum_Echoes_ESlotType, METADATA_PARAMS(0, nullptr) }; // 780113368
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateCooldown_Statics::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModulePanelWidget_eventClientOnly_UpdateCooldown_Parms, SlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateCooldown_Statics::NewProp_CooldownRemaining = { "CooldownRemaining", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModulePanelWidget_eventClientOnly_UpdateCooldown_Parms, CooldownRemaining), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateCooldown_Statics::NewProp_CooldownTotal = { "CooldownTotal", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModulePanelWidget_eventClientOnly_UpdateCooldown_Parms, CooldownTotal), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateCooldown_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateCooldown_Statics::NewProp_SlotType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateCooldown_Statics::NewProp_SlotType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateCooldown_Statics::NewProp_SlotIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateCooldown_Statics::NewProp_CooldownRemaining,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateCooldown_Statics::NewProp_CooldownTotal,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateCooldown_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateCooldown_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UModulePanelWidget, nullptr, "ClientOnly_UpdateCooldown", Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateCooldown_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateCooldown_Statics::PropPointers), sizeof(Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateCooldown_Statics::ModulePanelWidget_eventClientOnly_UpdateCooldown_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateCooldown_Statics::Function_MetaDataParams), Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateCooldown_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateCooldown_Statics::ModulePanelWidget_eventClientOnly_UpdateCooldown_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateCooldown()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateCooldown_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UModulePanelWidget::execClientOnly_UpdateCooldown)
{
	P_GET_ENUM(ESlotType,Z_Param_SlotType);
	P_GET_PROPERTY(FIntProperty,Z_Param_SlotIndex);
	P_GET_PROPERTY(FFloatProperty,Z_Param_CooldownRemaining);
	P_GET_PROPERTY(FFloatProperty,Z_Param_CooldownTotal);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientOnly_UpdateCooldown(ESlotType(Z_Param_SlotType),Z_Param_SlotIndex,Z_Param_CooldownRemaining,Z_Param_CooldownTotal);
	P_NATIVE_END;
}
// ********** End Class UModulePanelWidget Function ClientOnly_UpdateCooldown **********************

// ********** Begin Class UModulePanelWidget Function ClientOnly_UpdateModuleState *****************
struct Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateModuleState_Statics
{
	struct ModulePanelWidget_eventClientOnly_UpdateModuleState_Parms
	{
		ESlotType SlotType;
		int32 SlotIndex;
		EModuleState NewState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Module Panel" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Update module state visual (Active/Overload/Offline)\n\x09 * Called when server notifies of state change\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Update module state visual (Active/Overload/Offline)\nCalled when server notifies of state change" },
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
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateModuleState_Statics::NewProp_SlotType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateModuleState_Statics::NewProp_SlotType = { "SlotType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModulePanelWidget_eventClientOnly_UpdateModuleState_Parms, SlotType), Z_Construct_UEnum_Echoes_ESlotType, METADATA_PARAMS(0, nullptr) }; // 780113368
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateModuleState_Statics::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModulePanelWidget_eventClientOnly_UpdateModuleState_Parms, SlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateModuleState_Statics::NewProp_NewState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateModuleState_Statics::NewProp_NewState = { "NewState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModulePanelWidget_eventClientOnly_UpdateModuleState_Parms, NewState), Z_Construct_UEnum_Echoes_EModuleState, METADATA_PARAMS(0, nullptr) }; // 1837800180
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateModuleState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateModuleState_Statics::NewProp_SlotType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateModuleState_Statics::NewProp_SlotType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateModuleState_Statics::NewProp_SlotIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateModuleState_Statics::NewProp_NewState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateModuleState_Statics::NewProp_NewState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateModuleState_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateModuleState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UModulePanelWidget, nullptr, "ClientOnly_UpdateModuleState", Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateModuleState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateModuleState_Statics::PropPointers), sizeof(Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateModuleState_Statics::ModulePanelWidget_eventClientOnly_UpdateModuleState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateModuleState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateModuleState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateModuleState_Statics::ModulePanelWidget_eventClientOnly_UpdateModuleState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateModuleState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateModuleState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UModulePanelWidget::execClientOnly_UpdateModuleState)
{
	P_GET_ENUM(ESlotType,Z_Param_SlotType);
	P_GET_PROPERTY(FIntProperty,Z_Param_SlotIndex);
	P_GET_ENUM(EModuleState,Z_Param_NewState);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientOnly_UpdateModuleState(ESlotType(Z_Param_SlotType),Z_Param_SlotIndex,EModuleState(Z_Param_NewState));
	P_NATIVE_END;
}
// ********** End Class UModulePanelWidget Function ClientOnly_UpdateModuleState *******************

// ********** Begin Class UModulePanelWidget Function ClientOnly_UpdateSlot ************************
struct Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateSlot_Statics
{
	struct ModulePanelWidget_eventClientOnly_UpdateSlot_Parms
	{
		FCommon_ItemSlot SlotData;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Module Panel" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Update single slot display\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Update single slot display" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlotData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_SlotData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateSlot_Statics::NewProp_SlotData = { "SlotData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModulePanelWidget_eventClientOnly_UpdateSlot_Parms, SlotData), Z_Construct_UScriptStruct_FCommon_ItemSlot, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlotData_MetaData), NewProp_SlotData_MetaData) }; // 771062216
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateSlot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateSlot_Statics::NewProp_SlotData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateSlot_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateSlot_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UModulePanelWidget, nullptr, "ClientOnly_UpdateSlot", Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateSlot_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateSlot_Statics::PropPointers), sizeof(Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateSlot_Statics::ModulePanelWidget_eventClientOnly_UpdateSlot_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateSlot_Statics::Function_MetaDataParams), Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateSlot_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateSlot_Statics::ModulePanelWidget_eventClientOnly_UpdateSlot_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateSlot()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateSlot_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UModulePanelWidget::execClientOnly_UpdateSlot)
{
	P_GET_STRUCT_REF(FCommon_ItemSlot,Z_Param_Out_SlotData);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientOnly_UpdateSlot(Z_Param_Out_SlotData);
	P_NATIVE_END;
}
// ********** End Class UModulePanelWidget Function ClientOnly_UpdateSlot **************************

// ********** Begin Class UModulePanelWidget Function Common_GetShipFittingInterface ***************
struct Z_Construct_UFunction_UModulePanelWidget_Common_GetShipFittingInterface_Statics
{
	struct ModulePanelWidget_eventCommon_GetShipFittingInterface_Parms
	{
		TScriptInterface<IShipFittingInterface> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Module Panel" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get ship fitting interface from player's ship\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get ship fitting interface from player's ship" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FInterfacePropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FInterfacePropertyParams Z_Construct_UFunction_UModulePanelWidget_Common_GetShipFittingInterface_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0014000000000580, UECodeGen_Private::EPropertyGenFlags::Interface, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModulePanelWidget_eventCommon_GetShipFittingInterface_Parms, ReturnValue), Z_Construct_UClass_UShipFittingInterface_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UModulePanelWidget_Common_GetShipFittingInterface_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModulePanelWidget_Common_GetShipFittingInterface_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UModulePanelWidget_Common_GetShipFittingInterface_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UModulePanelWidget_Common_GetShipFittingInterface_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UModulePanelWidget, nullptr, "Common_GetShipFittingInterface", Z_Construct_UFunction_UModulePanelWidget_Common_GetShipFittingInterface_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UModulePanelWidget_Common_GetShipFittingInterface_Statics::PropPointers), sizeof(Z_Construct_UFunction_UModulePanelWidget_Common_GetShipFittingInterface_Statics::ModulePanelWidget_eventCommon_GetShipFittingInterface_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UModulePanelWidget_Common_GetShipFittingInterface_Statics::Function_MetaDataParams), Z_Construct_UFunction_UModulePanelWidget_Common_GetShipFittingInterface_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UModulePanelWidget_Common_GetShipFittingInterface_Statics::ModulePanelWidget_eventCommon_GetShipFittingInterface_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModulePanelWidget_Common_GetShipFittingInterface()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UModulePanelWidget_Common_GetShipFittingInterface_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UModulePanelWidget::execCommon_GetShipFittingInterface)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TScriptInterface<IShipFittingInterface>*)Z_Param__Result=P_THIS->Common_GetShipFittingInterface();
	P_NATIVE_END;
}
// ********** End Class UModulePanelWidget Function Common_GetShipFittingInterface *****************

// ********** Begin Class UModulePanelWidget Function Common_GetSlotWidget *************************
struct Z_Construct_UFunction_UModulePanelWidget_Common_GetSlotWidget_Statics
{
	struct ModulePanelWidget_eventCommon_GetSlotWidget_Parms
	{
		ESlotType SlotType;
		int32 SlotIndex;
		UModuleSlotWidget* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Module Panel" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get module slot widget by type and index\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get module slot widget by type and index" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_SlotType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SlotType;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UModulePanelWidget_Common_GetSlotWidget_Statics::NewProp_SlotType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UModulePanelWidget_Common_GetSlotWidget_Statics::NewProp_SlotType = { "SlotType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModulePanelWidget_eventCommon_GetSlotWidget_Parms, SlotType), Z_Construct_UEnum_Echoes_ESlotType, METADATA_PARAMS(0, nullptr) }; // 780113368
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UModulePanelWidget_Common_GetSlotWidget_Statics::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModulePanelWidget_eventCommon_GetSlotWidget_Parms, SlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UModulePanelWidget_Common_GetSlotWidget_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModulePanelWidget_eventCommon_GetSlotWidget_Parms, ReturnValue), Z_Construct_UClass_UModuleSlotWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UModulePanelWidget_Common_GetSlotWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModulePanelWidget_Common_GetSlotWidget_Statics::NewProp_SlotType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModulePanelWidget_Common_GetSlotWidget_Statics::NewProp_SlotType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModulePanelWidget_Common_GetSlotWidget_Statics::NewProp_SlotIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModulePanelWidget_Common_GetSlotWidget_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UModulePanelWidget_Common_GetSlotWidget_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UModulePanelWidget_Common_GetSlotWidget_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UModulePanelWidget, nullptr, "Common_GetSlotWidget", Z_Construct_UFunction_UModulePanelWidget_Common_GetSlotWidget_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UModulePanelWidget_Common_GetSlotWidget_Statics::PropPointers), sizeof(Z_Construct_UFunction_UModulePanelWidget_Common_GetSlotWidget_Statics::ModulePanelWidget_eventCommon_GetSlotWidget_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UModulePanelWidget_Common_GetSlotWidget_Statics::Function_MetaDataParams), Z_Construct_UFunction_UModulePanelWidget_Common_GetSlotWidget_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UModulePanelWidget_Common_GetSlotWidget_Statics::ModulePanelWidget_eventCommon_GetSlotWidget_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModulePanelWidget_Common_GetSlotWidget()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UModulePanelWidget_Common_GetSlotWidget_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UModulePanelWidget::execCommon_GetSlotWidget)
{
	P_GET_ENUM(ESlotType,Z_Param_SlotType);
	P_GET_PROPERTY(FIntProperty,Z_Param_SlotIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UModuleSlotWidget**)Z_Param__Result=P_THIS->Common_GetSlotWidget(ESlotType(Z_Param_SlotType),Z_Param_SlotIndex);
	P_NATIVE_END;
}
// ********** End Class UModulePanelWidget Function Common_GetSlotWidget ***************************

// ********** Begin Class UModulePanelWidget Function Common_HasActiveModules **********************
struct Z_Construct_UFunction_UModulePanelWidget_Common_HasActiveModules_Statics
{
	struct ModulePanelWidget_eventCommon_HasActiveModules_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Module Panel" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if any modules are active\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if any modules are active" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UModulePanelWidget_Common_HasActiveModules_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ModulePanelWidget_eventCommon_HasActiveModules_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UModulePanelWidget_Common_HasActiveModules_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ModulePanelWidget_eventCommon_HasActiveModules_Parms), &Z_Construct_UFunction_UModulePanelWidget_Common_HasActiveModules_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UModulePanelWidget_Common_HasActiveModules_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModulePanelWidget_Common_HasActiveModules_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UModulePanelWidget_Common_HasActiveModules_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UModulePanelWidget_Common_HasActiveModules_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UModulePanelWidget, nullptr, "Common_HasActiveModules", Z_Construct_UFunction_UModulePanelWidget_Common_HasActiveModules_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UModulePanelWidget_Common_HasActiveModules_Statics::PropPointers), sizeof(Z_Construct_UFunction_UModulePanelWidget_Common_HasActiveModules_Statics::ModulePanelWidget_eventCommon_HasActiveModules_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UModulePanelWidget_Common_HasActiveModules_Statics::Function_MetaDataParams), Z_Construct_UFunction_UModulePanelWidget_Common_HasActiveModules_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UModulePanelWidget_Common_HasActiveModules_Statics::ModulePanelWidget_eventCommon_HasActiveModules_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModulePanelWidget_Common_HasActiveModules()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UModulePanelWidget_Common_HasActiveModules_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UModulePanelWidget::execCommon_HasActiveModules)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->Common_HasActiveModules();
	P_NATIVE_END;
}
// ********** End Class UModulePanelWidget Function Common_HasActiveModules ************************

// ********** Begin Class UModulePanelWidget Function HandleSlotClicked ****************************
struct Z_Construct_UFunction_UModulePanelWidget_HandleSlotClicked_Statics
{
	struct ModulePanelWidget_eventHandleSlotClicked_Parms
	{
		ESlotType SlotType;
		int32 SlotIndex;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Handle module slot clicked */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handle module slot clicked" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_SlotType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SlotType;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UModulePanelWidget_HandleSlotClicked_Statics::NewProp_SlotType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UModulePanelWidget_HandleSlotClicked_Statics::NewProp_SlotType = { "SlotType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModulePanelWidget_eventHandleSlotClicked_Parms, SlotType), Z_Construct_UEnum_Echoes_ESlotType, METADATA_PARAMS(0, nullptr) }; // 780113368
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UModulePanelWidget_HandleSlotClicked_Statics::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModulePanelWidget_eventHandleSlotClicked_Parms, SlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UModulePanelWidget_HandleSlotClicked_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModulePanelWidget_HandleSlotClicked_Statics::NewProp_SlotType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModulePanelWidget_HandleSlotClicked_Statics::NewProp_SlotType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModulePanelWidget_HandleSlotClicked_Statics::NewProp_SlotIndex,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UModulePanelWidget_HandleSlotClicked_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UModulePanelWidget_HandleSlotClicked_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UModulePanelWidget, nullptr, "HandleSlotClicked", Z_Construct_UFunction_UModulePanelWidget_HandleSlotClicked_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UModulePanelWidget_HandleSlotClicked_Statics::PropPointers), sizeof(Z_Construct_UFunction_UModulePanelWidget_HandleSlotClicked_Statics::ModulePanelWidget_eventHandleSlotClicked_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UModulePanelWidget_HandleSlotClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UModulePanelWidget_HandleSlotClicked_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UModulePanelWidget_HandleSlotClicked_Statics::ModulePanelWidget_eventHandleSlotClicked_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModulePanelWidget_HandleSlotClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UModulePanelWidget_HandleSlotClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UModulePanelWidget::execHandleSlotClicked)
{
	P_GET_ENUM(ESlotType,Z_Param_SlotType);
	P_GET_PROPERTY(FIntProperty,Z_Param_SlotIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleSlotClicked(ESlotType(Z_Param_SlotType),Z_Param_SlotIndex);
	P_NATIVE_END;
}
// ********** End Class UModulePanelWidget Function HandleSlotClicked ******************************

// ********** Begin Class UModulePanelWidget Function OnModuleStateChanged *************************
struct ModulePanelWidget_eventOnModuleStateChanged_Parms
{
	ESlotType SlotType;
	int32 SlotIndex;
	EModuleState NewState;
};
static FName NAME_UModulePanelWidget_OnModuleStateChanged = FName(TEXT("OnModuleStateChanged"));
void UModulePanelWidget::OnModuleStateChanged(ESlotType SlotType, int32 SlotIndex, EModuleState NewState)
{
	ModulePanelWidget_eventOnModuleStateChanged_Parms Parms;
	Parms.SlotType=SlotType;
	Parms.SlotIndex=SlotIndex;
	Parms.NewState=NewState;
	UFunction* Func = FindFunctionChecked(NAME_UModulePanelWidget_OnModuleStateChanged);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UModulePanelWidget_OnModuleStateChanged_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Module Panel|Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Blueprint event: Module state changed\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Blueprint event: Module state changed" },
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
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UModulePanelWidget_OnModuleStateChanged_Statics::NewProp_SlotType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UModulePanelWidget_OnModuleStateChanged_Statics::NewProp_SlotType = { "SlotType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModulePanelWidget_eventOnModuleStateChanged_Parms, SlotType), Z_Construct_UEnum_Echoes_ESlotType, METADATA_PARAMS(0, nullptr) }; // 780113368
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UModulePanelWidget_OnModuleStateChanged_Statics::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModulePanelWidget_eventOnModuleStateChanged_Parms, SlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UModulePanelWidget_OnModuleStateChanged_Statics::NewProp_NewState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UModulePanelWidget_OnModuleStateChanged_Statics::NewProp_NewState = { "NewState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModulePanelWidget_eventOnModuleStateChanged_Parms, NewState), Z_Construct_UEnum_Echoes_EModuleState, METADATA_PARAMS(0, nullptr) }; // 1837800180
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UModulePanelWidget_OnModuleStateChanged_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModulePanelWidget_OnModuleStateChanged_Statics::NewProp_SlotType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModulePanelWidget_OnModuleStateChanged_Statics::NewProp_SlotType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModulePanelWidget_OnModuleStateChanged_Statics::NewProp_SlotIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModulePanelWidget_OnModuleStateChanged_Statics::NewProp_NewState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModulePanelWidget_OnModuleStateChanged_Statics::NewProp_NewState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UModulePanelWidget_OnModuleStateChanged_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UModulePanelWidget_OnModuleStateChanged_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UModulePanelWidget, nullptr, "OnModuleStateChanged", Z_Construct_UFunction_UModulePanelWidget_OnModuleStateChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UModulePanelWidget_OnModuleStateChanged_Statics::PropPointers), sizeof(ModulePanelWidget_eventOnModuleStateChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UModulePanelWidget_OnModuleStateChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UModulePanelWidget_OnModuleStateChanged_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(ModulePanelWidget_eventOnModuleStateChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModulePanelWidget_OnModuleStateChanged()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UModulePanelWidget_OnModuleStateChanged_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UModulePanelWidget Function OnModuleStateChanged ***************************

// ********** Begin Class UModulePanelWidget Function ServerRPC_DeactivateAll **********************
struct Z_Construct_UFunction_UModulePanelWidget_ServerRPC_DeactivateAll_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Module Panel" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Deactivate all modules (emergency power save)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Deactivate all modules (emergency power save)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UModulePanelWidget_ServerRPC_DeactivateAll_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UModulePanelWidget, nullptr, "ServerRPC_DeactivateAll", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UModulePanelWidget_ServerRPC_DeactivateAll_Statics::Function_MetaDataParams), Z_Construct_UFunction_UModulePanelWidget_ServerRPC_DeactivateAll_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UModulePanelWidget_ServerRPC_DeactivateAll()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UModulePanelWidget_ServerRPC_DeactivateAll_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UModulePanelWidget::execServerRPC_DeactivateAll)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerRPC_DeactivateAll();
	P_NATIVE_END;
}
// ********** End Class UModulePanelWidget Function ServerRPC_DeactivateAll ************************

// ********** Begin Class UModulePanelWidget Function ServerRPC_ToggleModule ***********************
struct Z_Construct_UFunction_UModulePanelWidget_ServerRPC_ToggleModule_Statics
{
	struct ModulePanelWidget_eventServerRPC_ToggleModule_Parms
	{
		ESlotType SlotType;
		int32 SlotIndex;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Module Panel" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Toggle module activation (on/off)\n\x09 * Server checks capacitor, cooldown, and activates\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Toggle module activation (on/off)\nServer checks capacitor, cooldown, and activates" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_SlotType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SlotType;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UModulePanelWidget_ServerRPC_ToggleModule_Statics::NewProp_SlotType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UModulePanelWidget_ServerRPC_ToggleModule_Statics::NewProp_SlotType = { "SlotType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModulePanelWidget_eventServerRPC_ToggleModule_Parms, SlotType), Z_Construct_UEnum_Echoes_ESlotType, METADATA_PARAMS(0, nullptr) }; // 780113368
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UModulePanelWidget_ServerRPC_ToggleModule_Statics::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModulePanelWidget_eventServerRPC_ToggleModule_Parms, SlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UModulePanelWidget_ServerRPC_ToggleModule_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModulePanelWidget_ServerRPC_ToggleModule_Statics::NewProp_SlotType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModulePanelWidget_ServerRPC_ToggleModule_Statics::NewProp_SlotType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModulePanelWidget_ServerRPC_ToggleModule_Statics::NewProp_SlotIndex,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UModulePanelWidget_ServerRPC_ToggleModule_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UModulePanelWidget_ServerRPC_ToggleModule_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UModulePanelWidget, nullptr, "ServerRPC_ToggleModule", Z_Construct_UFunction_UModulePanelWidget_ServerRPC_ToggleModule_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UModulePanelWidget_ServerRPC_ToggleModule_Statics::PropPointers), sizeof(Z_Construct_UFunction_UModulePanelWidget_ServerRPC_ToggleModule_Statics::ModulePanelWidget_eventServerRPC_ToggleModule_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UModulePanelWidget_ServerRPC_ToggleModule_Statics::Function_MetaDataParams), Z_Construct_UFunction_UModulePanelWidget_ServerRPC_ToggleModule_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UModulePanelWidget_ServerRPC_ToggleModule_Statics::ModulePanelWidget_eventServerRPC_ToggleModule_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModulePanelWidget_ServerRPC_ToggleModule()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UModulePanelWidget_ServerRPC_ToggleModule_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UModulePanelWidget::execServerRPC_ToggleModule)
{
	P_GET_ENUM(ESlotType,Z_Param_SlotType);
	P_GET_PROPERTY(FIntProperty,Z_Param_SlotIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerRPC_ToggleModule(ESlotType(Z_Param_SlotType),Z_Param_SlotIndex);
	P_NATIVE_END;
}
// ********** End Class UModulePanelWidget Function ServerRPC_ToggleModule *************************

// ********** Begin Class UModulePanelWidget *******************************************************
void UModulePanelWidget::StaticRegisterNativesUModulePanelWidget()
{
	UClass* Class = UModulePanelWidget::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ClientOnly_RefreshAllModules", &UModulePanelWidget::execClientOnly_RefreshAllModules },
		{ "ClientOnly_UpdateCooldown", &UModulePanelWidget::execClientOnly_UpdateCooldown },
		{ "ClientOnly_UpdateModuleState", &UModulePanelWidget::execClientOnly_UpdateModuleState },
		{ "ClientOnly_UpdateSlot", &UModulePanelWidget::execClientOnly_UpdateSlot },
		{ "Common_GetShipFittingInterface", &UModulePanelWidget::execCommon_GetShipFittingInterface },
		{ "Common_GetSlotWidget", &UModulePanelWidget::execCommon_GetSlotWidget },
		{ "Common_HasActiveModules", &UModulePanelWidget::execCommon_HasActiveModules },
		{ "HandleSlotClicked", &UModulePanelWidget::execHandleSlotClicked },
		{ "ServerRPC_DeactivateAll", &UModulePanelWidget::execServerRPC_DeactivateAll },
		{ "ServerRPC_ToggleModule", &UModulePanelWidget::execServerRPC_ToggleModule },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UModulePanelWidget;
UClass* UModulePanelWidget::GetPrivateStaticClass()
{
	using TClass = UModulePanelWidget;
	if (!Z_Registration_Info_UClass_UModulePanelWidget.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ModulePanelWidget"),
			Z_Registration_Info_UClass_UModulePanelWidget.InnerSingleton,
			StaticRegisterNativesUModulePanelWidget,
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
	return Z_Registration_Info_UClass_UModulePanelWidget.InnerSingleton;
}
UClass* Z_Construct_UClass_UModulePanelWidget_NoRegister()
{
	return UModulePanelWidget::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UModulePanelWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Module Panel Widget - Displays active modules in space HUD\n * Shows High/Mid/Low slots with activation controls\n * Server-authoritative activation with client-side visual feedback\n */" },
#endif
		{ "IncludePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Module Panel Widget - Displays active modules in space HUD\nShows High/Mid/Low slots with activation controls\nServer-authoritative activation with client-side visual feedback" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HighSlotsGrid_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "ModulePanelWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Container for High slots (weapons, utility high) */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Container for High slots (weapons, utility high)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MidSlotsGrid_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "ModulePanelWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Container for Mid slots (shield, ECM, tackle) */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Container for Mid slots (shield, ECM, tackle)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LowSlotsGrid_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "ModulePanelWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Container for Low slots (armor, damage mods, propulsion) */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Container for Low slots (armor, damage mods, propulsion)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ModuleSlotWidgetClass_MetaData[] = {
		{ "Category", "Module Panel" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Widget class for individual module slots */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Widget class for individual module slots" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridColumns_MetaData[] = {
		{ "Category", "Module Panel" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Number of columns in grid layout */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Number of columns in grid layout" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CooldownUpdateRate_MetaData[] = {
		{ "Category", "Module Panel" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Update rate for cooldown visuals (Hz) */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Update rate for cooldown visuals (Hz)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnModuleToggled_MetaData[] = {
		{ "Category", "Module Panel|Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Called when module is activated/deactivated */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when module is activated/deactivated" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HighSlotWidgets_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Created slot widgets */// Store slot widgets in separate arrays per slot type because UHT doesn't support\n// using TArray as the value in a TMap within a UCLASS.\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Created slot widgets // Store slot widgets in separate arrays per slot type because UHT doesn't support\n// using TArray as the value in a TMap within a UCLASS." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MidSlotWidgets_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LowSlotWidgets_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CachedPlayerController_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Cached references */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cached references" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CachedShipPawn_MetaData[] = {
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HighSlotsGrid;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MidSlotsGrid;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LowSlotsGrid;
	static const UECodeGen_Private::FClassPropertyParams NewProp_ModuleSlotWidgetClass;
	static const UECodeGen_Private::FIntPropertyParams NewProp_GridColumns;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CooldownUpdateRate;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnModuleToggled;
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
		{ &Z_Construct_UFunction_UModulePanelWidget_ClientOnly_RefreshAllModules, "ClientOnly_RefreshAllModules" }, // 489108424
		{ &Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateCooldown, "ClientOnly_UpdateCooldown" }, // 695711838
		{ &Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateModuleState, "ClientOnly_UpdateModuleState" }, // 4189503426
		{ &Z_Construct_UFunction_UModulePanelWidget_ClientOnly_UpdateSlot, "ClientOnly_UpdateSlot" }, // 3557232380
		{ &Z_Construct_UFunction_UModulePanelWidget_Common_GetShipFittingInterface, "Common_GetShipFittingInterface" }, // 1990157891
		{ &Z_Construct_UFunction_UModulePanelWidget_Common_GetSlotWidget, "Common_GetSlotWidget" }, // 1313630459
		{ &Z_Construct_UFunction_UModulePanelWidget_Common_HasActiveModules, "Common_HasActiveModules" }, // 2203015407
		{ &Z_Construct_UFunction_UModulePanelWidget_HandleSlotClicked, "HandleSlotClicked" }, // 1496008780
		{ &Z_Construct_UFunction_UModulePanelWidget_OnModuleStateChanged, "OnModuleStateChanged" }, // 3304932807
		{ &Z_Construct_UFunction_UModulePanelWidget_ServerRPC_DeactivateAll, "ServerRPC_DeactivateAll" }, // 3398581298
		{ &Z_Construct_UFunction_UModulePanelWidget_ServerRPC_ToggleModule, "ServerRPC_ToggleModule" }, // 3524539061
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UModulePanelWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UModulePanelWidget_Statics::NewProp_HighSlotsGrid = { "HighSlotsGrid", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UModulePanelWidget, HighSlotsGrid), Z_Construct_UClass_UUniformGridPanel_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HighSlotsGrid_MetaData), NewProp_HighSlotsGrid_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UModulePanelWidget_Statics::NewProp_MidSlotsGrid = { "MidSlotsGrid", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UModulePanelWidget, MidSlotsGrid), Z_Construct_UClass_UUniformGridPanel_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MidSlotsGrid_MetaData), NewProp_MidSlotsGrid_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UModulePanelWidget_Statics::NewProp_LowSlotsGrid = { "LowSlotsGrid", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UModulePanelWidget, LowSlotsGrid), Z_Construct_UClass_UUniformGridPanel_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LowSlotsGrid_MetaData), NewProp_LowSlotsGrid_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UModulePanelWidget_Statics::NewProp_ModuleSlotWidgetClass = { "ModuleSlotWidgetClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UModulePanelWidget, ModuleSlotWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UModuleSlotWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ModuleSlotWidgetClass_MetaData), NewProp_ModuleSlotWidgetClass_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UModulePanelWidget_Statics::NewProp_GridColumns = { "GridColumns", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UModulePanelWidget, GridColumns), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridColumns_MetaData), NewProp_GridColumns_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UModulePanelWidget_Statics::NewProp_CooldownUpdateRate = { "CooldownUpdateRate", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UModulePanelWidget, CooldownUpdateRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CooldownUpdateRate_MetaData), NewProp_CooldownUpdateRate_MetaData) };
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UModulePanelWidget_Statics::NewProp_OnModuleToggled = { "OnModuleToggled", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UModulePanelWidget, OnModuleToggled), Z_Construct_UDelegateFunction_Echoes_OnModuleToggled__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnModuleToggled_MetaData), NewProp_OnModuleToggled_MetaData) }; // 1999812972
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UModulePanelWidget_Statics::NewProp_HighSlotWidgets_Inner = { "HighSlotWidgets", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UModuleSlotWidget_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UModulePanelWidget_Statics::NewProp_HighSlotWidgets = { "HighSlotWidgets", nullptr, (EPropertyFlags)0x0020088000000008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UModulePanelWidget, HighSlotWidgets), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HighSlotWidgets_MetaData), NewProp_HighSlotWidgets_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UModulePanelWidget_Statics::NewProp_MidSlotWidgets_Inner = { "MidSlotWidgets", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UModuleSlotWidget_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UModulePanelWidget_Statics::NewProp_MidSlotWidgets = { "MidSlotWidgets", nullptr, (EPropertyFlags)0x0020088000000008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UModulePanelWidget, MidSlotWidgets), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MidSlotWidgets_MetaData), NewProp_MidSlotWidgets_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UModulePanelWidget_Statics::NewProp_LowSlotWidgets_Inner = { "LowSlotWidgets", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UModuleSlotWidget_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UModulePanelWidget_Statics::NewProp_LowSlotWidgets = { "LowSlotWidgets", nullptr, (EPropertyFlags)0x0020088000000008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UModulePanelWidget, LowSlotWidgets), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LowSlotWidgets_MetaData), NewProp_LowSlotWidgets_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UModulePanelWidget_Statics::NewProp_CachedPlayerController = { "CachedPlayerController", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UModulePanelWidget, CachedPlayerController), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CachedPlayerController_MetaData), NewProp_CachedPlayerController_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UModulePanelWidget_Statics::NewProp_CachedShipPawn = { "CachedShipPawn", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UModulePanelWidget, CachedShipPawn), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CachedShipPawn_MetaData), NewProp_CachedShipPawn_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UModulePanelWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModulePanelWidget_Statics::NewProp_HighSlotsGrid,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModulePanelWidget_Statics::NewProp_MidSlotsGrid,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModulePanelWidget_Statics::NewProp_LowSlotsGrid,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModulePanelWidget_Statics::NewProp_ModuleSlotWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModulePanelWidget_Statics::NewProp_GridColumns,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModulePanelWidget_Statics::NewProp_CooldownUpdateRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModulePanelWidget_Statics::NewProp_OnModuleToggled,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModulePanelWidget_Statics::NewProp_HighSlotWidgets_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModulePanelWidget_Statics::NewProp_HighSlotWidgets,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModulePanelWidget_Statics::NewProp_MidSlotWidgets_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModulePanelWidget_Statics::NewProp_MidSlotWidgets,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModulePanelWidget_Statics::NewProp_LowSlotWidgets_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModulePanelWidget_Statics::NewProp_LowSlotWidgets,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModulePanelWidget_Statics::NewProp_CachedPlayerController,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModulePanelWidget_Statics::NewProp_CachedShipPawn,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UModulePanelWidget_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UModulePanelWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UModulePanelWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UModulePanelWidget_Statics::ClassParams = {
	&UModulePanelWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UModulePanelWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UModulePanelWidget_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UModulePanelWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UModulePanelWidget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UModulePanelWidget()
{
	if (!Z_Registration_Info_UClass_UModulePanelWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UModulePanelWidget.OuterSingleton, Z_Construct_UClass_UModulePanelWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UModulePanelWidget.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UModulePanelWidget);
UModulePanelWidget::~UModulePanelWidget() {}
// ********** End Class UModulePanelWidget *********************************************************

// ********** Begin Delegate FOnSlotClicked ********************************************************
struct Z_Construct_UDelegateFunction_UModuleSlotWidget_OnSlotClicked__DelegateSignature_Statics
{
	struct ModuleSlotWidget_eventOnSlotClicked_Parms
	{
		ESlotType SlotType;
		int32 SlotIndex;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_SlotType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SlotType;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_UModuleSlotWidget_OnSlotClicked__DelegateSignature_Statics::NewProp_SlotType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_UModuleSlotWidget_OnSlotClicked__DelegateSignature_Statics::NewProp_SlotType = { "SlotType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModuleSlotWidget_eventOnSlotClicked_Parms, SlotType), Z_Construct_UEnum_Echoes_ESlotType, METADATA_PARAMS(0, nullptr) }; // 780113368
const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_UModuleSlotWidget_OnSlotClicked__DelegateSignature_Statics::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModuleSlotWidget_eventOnSlotClicked_Parms, SlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UModuleSlotWidget_OnSlotClicked__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UModuleSlotWidget_OnSlotClicked__DelegateSignature_Statics::NewProp_SlotType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UModuleSlotWidget_OnSlotClicked__DelegateSignature_Statics::NewProp_SlotType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UModuleSlotWidget_OnSlotClicked__DelegateSignature_Statics::NewProp_SlotIndex,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UModuleSlotWidget_OnSlotClicked__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_UModuleSlotWidget_OnSlotClicked__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UModuleSlotWidget, nullptr, "OnSlotClicked__DelegateSignature", Z_Construct_UDelegateFunction_UModuleSlotWidget_OnSlotClicked__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UModuleSlotWidget_OnSlotClicked__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UModuleSlotWidget_OnSlotClicked__DelegateSignature_Statics::ModuleSlotWidget_eventOnSlotClicked_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UModuleSlotWidget_OnSlotClicked__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UModuleSlotWidget_OnSlotClicked__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_UModuleSlotWidget_OnSlotClicked__DelegateSignature_Statics::ModuleSlotWidget_eventOnSlotClicked_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_UModuleSlotWidget_OnSlotClicked__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UModuleSlotWidget_OnSlotClicked__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void UModuleSlotWidget::FOnSlotClicked_DelegateWrapper(const FMulticastScriptDelegate& OnSlotClicked, ESlotType SlotType, int32 SlotIndex)
{
	struct ModuleSlotWidget_eventOnSlotClicked_Parms
	{
		ESlotType SlotType;
		int32 SlotIndex;
	};
	ModuleSlotWidget_eventOnSlotClicked_Parms Parms;
	Parms.SlotType=SlotType;
	Parms.SlotIndex=SlotIndex;
	OnSlotClicked.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnSlotClicked **********************************************************

// ********** Begin Class UModuleSlotWidget Function InitializeSlot ********************************
struct Z_Construct_UFunction_UModuleSlotWidget_InitializeSlot_Statics
{
	struct ModuleSlotWidget_eventInitializeSlot_Parms
	{
		ESlotType InSlotType;
		int32 InSlotIndex;
		FCommon_ItemSlot InSlotData;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Module Slot" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
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
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UModuleSlotWidget_InitializeSlot_Statics::NewProp_InSlotType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UModuleSlotWidget_InitializeSlot_Statics::NewProp_InSlotType = { "InSlotType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModuleSlotWidget_eventInitializeSlot_Parms, InSlotType), Z_Construct_UEnum_Echoes_ESlotType, METADATA_PARAMS(0, nullptr) }; // 780113368
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UModuleSlotWidget_InitializeSlot_Statics::NewProp_InSlotIndex = { "InSlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModuleSlotWidget_eventInitializeSlot_Parms, InSlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UModuleSlotWidget_InitializeSlot_Statics::NewProp_InSlotData = { "InSlotData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModuleSlotWidget_eventInitializeSlot_Parms, InSlotData), Z_Construct_UScriptStruct_FCommon_ItemSlot, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InSlotData_MetaData), NewProp_InSlotData_MetaData) }; // 771062216
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UModuleSlotWidget_InitializeSlot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModuleSlotWidget_InitializeSlot_Statics::NewProp_InSlotType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModuleSlotWidget_InitializeSlot_Statics::NewProp_InSlotType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModuleSlotWidget_InitializeSlot_Statics::NewProp_InSlotIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModuleSlotWidget_InitializeSlot_Statics::NewProp_InSlotData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UModuleSlotWidget_InitializeSlot_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UModuleSlotWidget_InitializeSlot_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UModuleSlotWidget, nullptr, "InitializeSlot", Z_Construct_UFunction_UModuleSlotWidget_InitializeSlot_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UModuleSlotWidget_InitializeSlot_Statics::PropPointers), sizeof(Z_Construct_UFunction_UModuleSlotWidget_InitializeSlot_Statics::ModuleSlotWidget_eventInitializeSlot_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UModuleSlotWidget_InitializeSlot_Statics::Function_MetaDataParams), Z_Construct_UFunction_UModuleSlotWidget_InitializeSlot_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UModuleSlotWidget_InitializeSlot_Statics::ModuleSlotWidget_eventInitializeSlot_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModuleSlotWidget_InitializeSlot()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UModuleSlotWidget_InitializeSlot_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UModuleSlotWidget::execInitializeSlot)
{
	P_GET_ENUM(ESlotType,Z_Param_InSlotType);
	P_GET_PROPERTY(FIntProperty,Z_Param_InSlotIndex);
	P_GET_STRUCT_REF(FCommon_ItemSlot,Z_Param_Out_InSlotData);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializeSlot(ESlotType(Z_Param_InSlotType),Z_Param_InSlotIndex,Z_Param_Out_InSlotData);
	P_NATIVE_END;
}
// ********** End Class UModuleSlotWidget Function InitializeSlot **********************************

// ********** Begin Class UModuleSlotWidget Function OnSlotClickedEvent ****************************
static FName NAME_UModuleSlotWidget_OnSlotClickedEvent = FName(TEXT("OnSlotClickedEvent"));
void UModuleSlotWidget::OnSlotClickedEvent()
{
	UFunction* Func = FindFunctionChecked(NAME_UModuleSlotWidget_OnSlotClickedEvent);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_UModuleSlotWidget_OnSlotClickedEvent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Module Slot|Events" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UModuleSlotWidget_OnSlotClickedEvent_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UModuleSlotWidget, nullptr, "OnSlotClickedEvent", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UModuleSlotWidget_OnSlotClickedEvent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UModuleSlotWidget_OnSlotClickedEvent_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UModuleSlotWidget_OnSlotClickedEvent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UModuleSlotWidget_OnSlotClickedEvent_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UModuleSlotWidget Function OnSlotClickedEvent ******************************

// ********** Begin Class UModuleSlotWidget Function UpdateCooldown ********************************
struct Z_Construct_UFunction_UModuleSlotWidget_UpdateCooldown_Statics
{
	struct ModuleSlotWidget_eventUpdateCooldown_Parms
	{
		float Progress;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Module Slot" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Progress;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UModuleSlotWidget_UpdateCooldown_Statics::NewProp_Progress = { "Progress", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModuleSlotWidget_eventUpdateCooldown_Parms, Progress), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UModuleSlotWidget_UpdateCooldown_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModuleSlotWidget_UpdateCooldown_Statics::NewProp_Progress,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UModuleSlotWidget_UpdateCooldown_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UModuleSlotWidget_UpdateCooldown_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UModuleSlotWidget, nullptr, "UpdateCooldown", Z_Construct_UFunction_UModuleSlotWidget_UpdateCooldown_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UModuleSlotWidget_UpdateCooldown_Statics::PropPointers), sizeof(Z_Construct_UFunction_UModuleSlotWidget_UpdateCooldown_Statics::ModuleSlotWidget_eventUpdateCooldown_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UModuleSlotWidget_UpdateCooldown_Statics::Function_MetaDataParams), Z_Construct_UFunction_UModuleSlotWidget_UpdateCooldown_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UModuleSlotWidget_UpdateCooldown_Statics::ModuleSlotWidget_eventUpdateCooldown_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModuleSlotWidget_UpdateCooldown()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UModuleSlotWidget_UpdateCooldown_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UModuleSlotWidget::execUpdateCooldown)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Progress);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UpdateCooldown(Z_Param_Progress);
	P_NATIVE_END;
}
// ********** End Class UModuleSlotWidget Function UpdateCooldown **********************************

// ********** Begin Class UModuleSlotWidget Function UpdateDisplay *********************************
struct Z_Construct_UFunction_UModuleSlotWidget_UpdateDisplay_Statics
{
	struct ModuleSlotWidget_eventUpdateDisplay_Parms
	{
		FCommon_ItemSlot InSlotData;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Module Slot" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InSlotData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_InSlotData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UModuleSlotWidget_UpdateDisplay_Statics::NewProp_InSlotData = { "InSlotData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModuleSlotWidget_eventUpdateDisplay_Parms, InSlotData), Z_Construct_UScriptStruct_FCommon_ItemSlot, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InSlotData_MetaData), NewProp_InSlotData_MetaData) }; // 771062216
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UModuleSlotWidget_UpdateDisplay_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModuleSlotWidget_UpdateDisplay_Statics::NewProp_InSlotData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UModuleSlotWidget_UpdateDisplay_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UModuleSlotWidget_UpdateDisplay_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UModuleSlotWidget, nullptr, "UpdateDisplay", Z_Construct_UFunction_UModuleSlotWidget_UpdateDisplay_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UModuleSlotWidget_UpdateDisplay_Statics::PropPointers), sizeof(Z_Construct_UFunction_UModuleSlotWidget_UpdateDisplay_Statics::ModuleSlotWidget_eventUpdateDisplay_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UModuleSlotWidget_UpdateDisplay_Statics::Function_MetaDataParams), Z_Construct_UFunction_UModuleSlotWidget_UpdateDisplay_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UModuleSlotWidget_UpdateDisplay_Statics::ModuleSlotWidget_eventUpdateDisplay_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModuleSlotWidget_UpdateDisplay()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UModuleSlotWidget_UpdateDisplay_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UModuleSlotWidget::execUpdateDisplay)
{
	P_GET_STRUCT_REF(FCommon_ItemSlot,Z_Param_Out_InSlotData);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UpdateDisplay(Z_Param_Out_InSlotData);
	P_NATIVE_END;
}
// ********** End Class UModuleSlotWidget Function UpdateDisplay ***********************************

// ********** Begin Class UModuleSlotWidget Function UpdateState ***********************************
struct Z_Construct_UFunction_UModuleSlotWidget_UpdateState_Statics
{
	struct ModuleSlotWidget_eventUpdateState_Parms
	{
		EModuleState NewState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Module Slot" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_NewState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NewState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UModuleSlotWidget_UpdateState_Statics::NewProp_NewState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UModuleSlotWidget_UpdateState_Statics::NewProp_NewState = { "NewState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ModuleSlotWidget_eventUpdateState_Parms, NewState), Z_Construct_UEnum_Echoes_EModuleState, METADATA_PARAMS(0, nullptr) }; // 1837800180
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UModuleSlotWidget_UpdateState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModuleSlotWidget_UpdateState_Statics::NewProp_NewState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UModuleSlotWidget_UpdateState_Statics::NewProp_NewState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UModuleSlotWidget_UpdateState_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UModuleSlotWidget_UpdateState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UModuleSlotWidget, nullptr, "UpdateState", Z_Construct_UFunction_UModuleSlotWidget_UpdateState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UModuleSlotWidget_UpdateState_Statics::PropPointers), sizeof(Z_Construct_UFunction_UModuleSlotWidget_UpdateState_Statics::ModuleSlotWidget_eventUpdateState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UModuleSlotWidget_UpdateState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UModuleSlotWidget_UpdateState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UModuleSlotWidget_UpdateState_Statics::ModuleSlotWidget_eventUpdateState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModuleSlotWidget_UpdateState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UModuleSlotWidget_UpdateState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UModuleSlotWidget::execUpdateState)
{
	P_GET_ENUM(EModuleState,Z_Param_NewState);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UpdateState(EModuleState(Z_Param_NewState));
	P_NATIVE_END;
}
// ********** End Class UModuleSlotWidget Function UpdateState *************************************

// ********** Begin Class UModuleSlotWidget ********************************************************
void UModuleSlotWidget::StaticRegisterNativesUModuleSlotWidget()
{
	UClass* Class = UModuleSlotWidget::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "InitializeSlot", &UModuleSlotWidget::execInitializeSlot },
		{ "UpdateCooldown", &UModuleSlotWidget::execUpdateCooldown },
		{ "UpdateDisplay", &UModuleSlotWidget::execUpdateDisplay },
		{ "UpdateState", &UModuleSlotWidget::execUpdateState },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UModuleSlotWidget;
UClass* UModuleSlotWidget::GetPrivateStaticClass()
{
	using TClass = UModuleSlotWidget;
	if (!Z_Registration_Info_UClass_UModuleSlotWidget.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ModuleSlotWidget"),
			Z_Registration_Info_UClass_UModuleSlotWidget.InnerSingleton,
			StaticRegisterNativesUModuleSlotWidget,
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
	return Z_Registration_Info_UClass_UModuleSlotWidget.InnerSingleton;
}
UClass* Z_Construct_UClass_UModuleSlotWidget_NoRegister()
{
	return UModuleSlotWidget::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UModuleSlotWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Individual Module Slot Widget\n */" },
#endif
		{ "IncludePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Individual Module Slot Widget" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ModuleIcon_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "ModuleSlotWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CooldownOverlay_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "ModuleSlotWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StateBorder_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "ModuleSlotWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlotNumberText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "ModuleSlotWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlotType_MetaData[] = {
		{ "Category", "Module Slot" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlotIndex_MetaData[] = {
		{ "Category", "Module Slot" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentState_MetaData[] = {
		{ "Category", "Module Slot" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlotData_MetaData[] = {
		{ "Category", "Module Slot" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OfflineColor_MetaData[] = {
		{ "Category", "Module Slot|Colors" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActiveColor_MetaData[] = {
		{ "Category", "Module Slot|Colors" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OverloadColor_MetaData[] = {
		{ "Category", "Module Slot|Colors" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnSlotClicked_MetaData[] = {
		{ "Category", "Module Slot|Events" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ModulePanelWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ModuleIcon;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CooldownOverlay;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StateBorder;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SlotNumberText;
	static const UECodeGen_Private::FBytePropertyParams NewProp_SlotType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SlotType;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CurrentState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_CurrentState;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SlotData;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OfflineColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ActiveColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OverloadColor;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnSlotClicked;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UModuleSlotWidget_InitializeSlot, "InitializeSlot" }, // 2220142867
		{ &Z_Construct_UDelegateFunction_UModuleSlotWidget_OnSlotClicked__DelegateSignature, "OnSlotClicked__DelegateSignature" }, // 3752345208
		{ &Z_Construct_UFunction_UModuleSlotWidget_OnSlotClickedEvent, "OnSlotClickedEvent" }, // 2431095748
		{ &Z_Construct_UFunction_UModuleSlotWidget_UpdateCooldown, "UpdateCooldown" }, // 1913488598
		{ &Z_Construct_UFunction_UModuleSlotWidget_UpdateDisplay, "UpdateDisplay" }, // 2303925098
		{ &Z_Construct_UFunction_UModuleSlotWidget_UpdateState, "UpdateState" }, // 1368644803
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UModuleSlotWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UModuleSlotWidget_Statics::NewProp_ModuleIcon = { "ModuleIcon", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UModuleSlotWidget, ModuleIcon), Z_Construct_UClass_UImage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ModuleIcon_MetaData), NewProp_ModuleIcon_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UModuleSlotWidget_Statics::NewProp_CooldownOverlay = { "CooldownOverlay", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UModuleSlotWidget, CooldownOverlay), Z_Construct_UClass_UProgressBar_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CooldownOverlay_MetaData), NewProp_CooldownOverlay_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UModuleSlotWidget_Statics::NewProp_StateBorder = { "StateBorder", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UModuleSlotWidget, StateBorder), Z_Construct_UClass_UBorder_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StateBorder_MetaData), NewProp_StateBorder_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UModuleSlotWidget_Statics::NewProp_SlotNumberText = { "SlotNumberText", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UModuleSlotWidget, SlotNumberText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlotNumberText_MetaData), NewProp_SlotNumberText_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UModuleSlotWidget_Statics::NewProp_SlotType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UModuleSlotWidget_Statics::NewProp_SlotType = { "SlotType", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UModuleSlotWidget, SlotType), Z_Construct_UEnum_Echoes_ESlotType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlotType_MetaData), NewProp_SlotType_MetaData) }; // 780113368
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UModuleSlotWidget_Statics::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UModuleSlotWidget, SlotIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlotIndex_MetaData), NewProp_SlotIndex_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UModuleSlotWidget_Statics::NewProp_CurrentState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UModuleSlotWidget_Statics::NewProp_CurrentState = { "CurrentState", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UModuleSlotWidget, CurrentState), Z_Construct_UEnum_Echoes_EModuleState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentState_MetaData), NewProp_CurrentState_MetaData) }; // 1837800180
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UModuleSlotWidget_Statics::NewProp_SlotData = { "SlotData", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UModuleSlotWidget, SlotData), Z_Construct_UScriptStruct_FCommon_ItemSlot, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlotData_MetaData), NewProp_SlotData_MetaData) }; // 771062216
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UModuleSlotWidget_Statics::NewProp_OfflineColor = { "OfflineColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UModuleSlotWidget, OfflineColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OfflineColor_MetaData), NewProp_OfflineColor_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UModuleSlotWidget_Statics::NewProp_ActiveColor = { "ActiveColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UModuleSlotWidget, ActiveColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActiveColor_MetaData), NewProp_ActiveColor_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UModuleSlotWidget_Statics::NewProp_OverloadColor = { "OverloadColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UModuleSlotWidget, OverloadColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OverloadColor_MetaData), NewProp_OverloadColor_MetaData) };
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UModuleSlotWidget_Statics::NewProp_OnSlotClicked = { "OnSlotClicked", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UModuleSlotWidget, OnSlotClicked), Z_Construct_UDelegateFunction_UModuleSlotWidget_OnSlotClicked__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnSlotClicked_MetaData), NewProp_OnSlotClicked_MetaData) }; // 3752345208
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UModuleSlotWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModuleSlotWidget_Statics::NewProp_ModuleIcon,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModuleSlotWidget_Statics::NewProp_CooldownOverlay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModuleSlotWidget_Statics::NewProp_StateBorder,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModuleSlotWidget_Statics::NewProp_SlotNumberText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModuleSlotWidget_Statics::NewProp_SlotType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModuleSlotWidget_Statics::NewProp_SlotType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModuleSlotWidget_Statics::NewProp_SlotIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModuleSlotWidget_Statics::NewProp_CurrentState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModuleSlotWidget_Statics::NewProp_CurrentState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModuleSlotWidget_Statics::NewProp_SlotData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModuleSlotWidget_Statics::NewProp_OfflineColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModuleSlotWidget_Statics::NewProp_ActiveColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModuleSlotWidget_Statics::NewProp_OverloadColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UModuleSlotWidget_Statics::NewProp_OnSlotClicked,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UModuleSlotWidget_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UModuleSlotWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UModuleSlotWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UModuleSlotWidget_Statics::ClassParams = {
	&UModuleSlotWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UModuleSlotWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UModuleSlotWidget_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UModuleSlotWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UModuleSlotWidget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UModuleSlotWidget()
{
	if (!Z_Registration_Info_UClass_UModuleSlotWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UModuleSlotWidget.OuterSingleton, Z_Construct_UClass_UModuleSlotWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UModuleSlotWidget.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UModuleSlotWidget);
UModuleSlotWidget::~UModuleSlotWidget() {}
// ********** End Class UModuleSlotWidget **********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_ModulePanelWidget_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UModulePanelWidget, UModulePanelWidget::StaticClass, TEXT("UModulePanelWidget"), &Z_Registration_Info_UClass_UModulePanelWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UModulePanelWidget), 343395512U) },
		{ Z_Construct_UClass_UModuleSlotWidget, UModuleSlotWidget::StaticClass, TEXT("UModuleSlotWidget"), &Z_Registration_Info_UClass_UModuleSlotWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UModuleSlotWidget), 3937508921U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_ModulePanelWidget_h__Script_Echoes_2531998911(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_ModulePanelWidget_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_ModulePanelWidget_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
