// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UI/EchoesQuantitySelectorWidget.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesQuantitySelectorWidget() {}

// ********** Begin Cross Module References ********************************************************
ECHOES_API UClass* Z_Construct_UClass_UEchoesQuantitySelectorWidget();
ECHOES_API UClass* Z_Construct_UClass_UEchoesQuantitySelectorWidget_NoRegister();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnQuantitySelected__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnQuantitySelectionCancelled__DelegateSignature();
SLATECORE_API UEnum* Z_Construct_UEnum_SlateCore_ETextCommit();
UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
UMG_API UClass* Z_Construct_UClass_UEditableTextBox_NoRegister();
UMG_API UClass* Z_Construct_UClass_USlider_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FOnQuantitySelected ***************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnQuantitySelected__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnQuantitySelected_Parms
	{
		int64 SelectedQuantity;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Delegate for quantity selection\n" },
#endif
		{ "ModuleRelativePath", "UI/EchoesQuantitySelectorWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Delegate for quantity selection" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FInt64PropertyParams NewProp_SelectedQuantity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UDelegateFunction_Echoes_OnQuantitySelected__DelegateSignature_Statics::NewProp_SelectedQuantity = { "SelectedQuantity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnQuantitySelected_Parms, SelectedQuantity), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnQuantitySelected__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnQuantitySelected__DelegateSignature_Statics::NewProp_SelectedQuantity,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnQuantitySelected__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnQuantitySelected__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnQuantitySelected__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnQuantitySelected__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnQuantitySelected__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnQuantitySelected__DelegateSignature_Statics::_Script_Echoes_eventOnQuantitySelected_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnQuantitySelected__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnQuantitySelected__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnQuantitySelected__DelegateSignature_Statics::_Script_Echoes_eventOnQuantitySelected_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnQuantitySelected__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnQuantitySelected__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnQuantitySelected_DelegateWrapper(const FMulticastScriptDelegate& OnQuantitySelected, int64 SelectedQuantity)
{
	struct _Script_Echoes_eventOnQuantitySelected_Parms
	{
		int64 SelectedQuantity;
	};
	_Script_Echoes_eventOnQuantitySelected_Parms Parms;
	Parms.SelectedQuantity=SelectedQuantity;
	OnQuantitySelected.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnQuantitySelected *****************************************************

// ********** Begin Delegate FOnQuantitySelectionCancelled *****************************************
struct Z_Construct_UDelegateFunction_Echoes_OnQuantitySelectionCancelled__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI/EchoesQuantitySelectorWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnQuantitySelectionCancelled__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnQuantitySelectionCancelled__DelegateSignature", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnQuantitySelectionCancelled__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnQuantitySelectionCancelled__DelegateSignature_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UDelegateFunction_Echoes_OnQuantitySelectionCancelled__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnQuantitySelectionCancelled__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnQuantitySelectionCancelled_DelegateWrapper(const FMulticastScriptDelegate& OnQuantitySelectionCancelled)
{
	OnQuantitySelectionCancelled.ProcessMulticastDelegate<UObject>(NULL);
}
// ********** End Delegate FOnQuantitySelectionCancelled *******************************************

// ********** Begin Class UEchoesQuantitySelectorWidget Function GetSelectedQuantity ***************
struct Z_Construct_UFunction_UEchoesQuantitySelectorWidget_GetSelectedQuantity_Statics
{
	struct EchoesQuantitySelectorWidget_eventGetSelectedQuantity_Parms
	{
		int64 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the currently selected quantity\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesQuantitySelectorWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the currently selected quantity" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FInt64PropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UEchoesQuantitySelectorWidget_GetSelectedQuantity_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesQuantitySelectorWidget_eventGetSelectedQuantity_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesQuantitySelectorWidget_GetSelectedQuantity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesQuantitySelectorWidget_GetSelectedQuantity_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesQuantitySelectorWidget_GetSelectedQuantity_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesQuantitySelectorWidget_GetSelectedQuantity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesQuantitySelectorWidget, nullptr, "GetSelectedQuantity", Z_Construct_UFunction_UEchoesQuantitySelectorWidget_GetSelectedQuantity_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesQuantitySelectorWidget_GetSelectedQuantity_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesQuantitySelectorWidget_GetSelectedQuantity_Statics::EchoesQuantitySelectorWidget_eventGetSelectedQuantity_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesQuantitySelectorWidget_GetSelectedQuantity_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesQuantitySelectorWidget_GetSelectedQuantity_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesQuantitySelectorWidget_GetSelectedQuantity_Statics::EchoesQuantitySelectorWidget_eventGetSelectedQuantity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesQuantitySelectorWidget_GetSelectedQuantity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesQuantitySelectorWidget_GetSelectedQuantity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesQuantitySelectorWidget::execGetSelectedQuantity)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int64*)Z_Param__Result=P_THIS->GetSelectedQuantity();
	P_NATIVE_END;
}
// ********** End Class UEchoesQuantitySelectorWidget Function GetSelectedQuantity *****************

// ********** Begin Class UEchoesQuantitySelectorWidget Function InitializeSelector ****************
struct Z_Construct_UFunction_UEchoesQuantitySelectorWidget_InitializeSelector_Statics
{
	struct EchoesQuantitySelectorWidget_eventInitializeSelector_Parms
	{
		int64 InMaxQuantity;
		FString InItemName;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Initialize the selector with max quantity\n\x09 * @param InMaxQuantity - Maximum quantity available\n\x09 * @param InItemName - Name of item being split\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesQuantitySelectorWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Initialize the selector with max quantity\n@param InMaxQuantity - Maximum quantity available\n@param InItemName - Name of item being split" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InItemName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FInt64PropertyParams NewProp_InMaxQuantity;
	static const UECodeGen_Private::FStrPropertyParams NewProp_InItemName;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UEchoesQuantitySelectorWidget_InitializeSelector_Statics::NewProp_InMaxQuantity = { "InMaxQuantity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesQuantitySelectorWidget_eventInitializeSelector_Parms, InMaxQuantity), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEchoesQuantitySelectorWidget_InitializeSelector_Statics::NewProp_InItemName = { "InItemName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesQuantitySelectorWidget_eventInitializeSelector_Parms, InItemName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InItemName_MetaData), NewProp_InItemName_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesQuantitySelectorWidget_InitializeSelector_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesQuantitySelectorWidget_InitializeSelector_Statics::NewProp_InMaxQuantity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesQuantitySelectorWidget_InitializeSelector_Statics::NewProp_InItemName,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesQuantitySelectorWidget_InitializeSelector_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesQuantitySelectorWidget_InitializeSelector_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesQuantitySelectorWidget, nullptr, "InitializeSelector", Z_Construct_UFunction_UEchoesQuantitySelectorWidget_InitializeSelector_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesQuantitySelectorWidget_InitializeSelector_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesQuantitySelectorWidget_InitializeSelector_Statics::EchoesQuantitySelectorWidget_eventInitializeSelector_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesQuantitySelectorWidget_InitializeSelector_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesQuantitySelectorWidget_InitializeSelector_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesQuantitySelectorWidget_InitializeSelector_Statics::EchoesQuantitySelectorWidget_eventInitializeSelector_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesQuantitySelectorWidget_InitializeSelector()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesQuantitySelectorWidget_InitializeSelector_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesQuantitySelectorWidget::execInitializeSelector)
{
	P_GET_PROPERTY(FInt64Property,Z_Param_InMaxQuantity);
	P_GET_PROPERTY(FStrProperty,Z_Param_InItemName);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializeSelector(Z_Param_InMaxQuantity,Z_Param_InItemName);
	P_NATIVE_END;
}
// ********** End Class UEchoesQuantitySelectorWidget Function InitializeSelector ******************

// ********** Begin Class UEchoesQuantitySelectorWidget Function OnCancelClicked *******************
struct Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnCancelClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Handle cancel button clicked\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesQuantitySelectorWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handle cancel button clicked" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnCancelClicked_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesQuantitySelectorWidget, nullptr, "OnCancelClicked", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnCancelClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnCancelClicked_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnCancelClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnCancelClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesQuantitySelectorWidget::execOnCancelClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnCancelClicked();
	P_NATIVE_END;
}
// ********** End Class UEchoesQuantitySelectorWidget Function OnCancelClicked *********************

// ********** Begin Class UEchoesQuantitySelectorWidget Function OnConfirmClicked ******************
struct Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnConfirmClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Handle confirm button clicked\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesQuantitySelectorWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handle confirm button clicked" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnConfirmClicked_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesQuantitySelectorWidget, nullptr, "OnConfirmClicked", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnConfirmClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnConfirmClicked_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnConfirmClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnConfirmClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesQuantitySelectorWidget::execOnConfirmClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnConfirmClicked();
	P_NATIVE_END;
}
// ********** End Class UEchoesQuantitySelectorWidget Function OnConfirmClicked ********************

// ********** Begin Class UEchoesQuantitySelectorWidget Function OnMaxClicked **********************
struct Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnMaxClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Handle max button clicked (sets quantity to maximum)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesQuantitySelectorWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handle max button clicked (sets quantity to maximum)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnMaxClicked_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesQuantitySelectorWidget, nullptr, "OnMaxClicked", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnMaxClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnMaxClicked_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnMaxClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnMaxClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesQuantitySelectorWidget::execOnMaxClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnMaxClicked();
	P_NATIVE_END;
}
// ********** End Class UEchoesQuantitySelectorWidget Function OnMaxClicked ************************

// ********** Begin Class UEchoesQuantitySelectorWidget Function OnQuantityTextCommitted ***********
struct Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnQuantityTextCommitted_Statics
{
	struct EchoesQuantitySelectorWidget_eventOnQuantityTextCommitted_Parms
	{
		FText Text;
		TEnumAsByte<ETextCommit::Type> CommitMethod;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Handle text committed in quantity input\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesQuantitySelectorWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handle text committed in quantity input" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Text_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FTextPropertyParams NewProp_Text;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CommitMethod;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnQuantityTextCommitted_Statics::NewProp_Text = { "Text", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesQuantitySelectorWidget_eventOnQuantityTextCommitted_Parms, Text), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Text_MetaData), NewProp_Text_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnQuantityTextCommitted_Statics::NewProp_CommitMethod = { "CommitMethod", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesQuantitySelectorWidget_eventOnQuantityTextCommitted_Parms, CommitMethod), Z_Construct_UEnum_SlateCore_ETextCommit, METADATA_PARAMS(0, nullptr) }; // 1817921380
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnQuantityTextCommitted_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnQuantityTextCommitted_Statics::NewProp_Text,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnQuantityTextCommitted_Statics::NewProp_CommitMethod,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnQuantityTextCommitted_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnQuantityTextCommitted_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesQuantitySelectorWidget, nullptr, "OnQuantityTextCommitted", Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnQuantityTextCommitted_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnQuantityTextCommitted_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnQuantityTextCommitted_Statics::EchoesQuantitySelectorWidget_eventOnQuantityTextCommitted_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00480401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnQuantityTextCommitted_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnQuantityTextCommitted_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnQuantityTextCommitted_Statics::EchoesQuantitySelectorWidget_eventOnQuantityTextCommitted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnQuantityTextCommitted()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnQuantityTextCommitted_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesQuantitySelectorWidget::execOnQuantityTextCommitted)
{
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_Text);
	P_GET_PROPERTY(FByteProperty,Z_Param_CommitMethod);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnQuantityTextCommitted(Z_Param_Out_Text,ETextCommit::Type(Z_Param_CommitMethod));
	P_NATIVE_END;
}
// ********** End Class UEchoesQuantitySelectorWidget Function OnQuantityTextCommitted *************

// ********** Begin Class UEchoesQuantitySelectorWidget Function OnSelectorInitialized *************
static FName NAME_UEchoesQuantitySelectorWidget_OnSelectorInitialized = FName(TEXT("OnSelectorInitialized"));
void UEchoesQuantitySelectorWidget::OnSelectorInitialized()
{
	UFunction* Func = FindFunctionChecked(NAME_UEchoesQuantitySelectorWidget_OnSelectorInitialized);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnSelectorInitialized_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Blueprint event called when selector is initialized\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesQuantitySelectorWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Blueprint event called when selector is initialized" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnSelectorInitialized_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesQuantitySelectorWidget, nullptr, "OnSelectorInitialized", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnSelectorInitialized_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnSelectorInitialized_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnSelectorInitialized()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnSelectorInitialized_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UEchoesQuantitySelectorWidget Function OnSelectorInitialized ***************

// ********** Begin Class UEchoesQuantitySelectorWidget Function OnSliderValueChanged **************
struct Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnSliderValueChanged_Statics
{
	struct EchoesQuantitySelectorWidget_eventOnSliderValueChanged_Parms
	{
		float Value;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Handle slider value changed\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesQuantitySelectorWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handle slider value changed" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnSliderValueChanged_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesQuantitySelectorWidget_eventOnSliderValueChanged_Parms, Value), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnSliderValueChanged_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnSliderValueChanged_Statics::NewProp_Value,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnSliderValueChanged_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnSliderValueChanged_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesQuantitySelectorWidget, nullptr, "OnSliderValueChanged", Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnSliderValueChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnSliderValueChanged_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnSliderValueChanged_Statics::EchoesQuantitySelectorWidget_eventOnSliderValueChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnSliderValueChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnSliderValueChanged_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnSliderValueChanged_Statics::EchoesQuantitySelectorWidget_eventOnSliderValueChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnSliderValueChanged()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnSliderValueChanged_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesQuantitySelectorWidget::execOnSliderValueChanged)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnSliderValueChanged(Z_Param_Value);
	P_NATIVE_END;
}
// ********** End Class UEchoesQuantitySelectorWidget Function OnSliderValueChanged ****************

// ********** Begin Class UEchoesQuantitySelectorWidget ********************************************
void UEchoesQuantitySelectorWidget::StaticRegisterNativesUEchoesQuantitySelectorWidget()
{
	UClass* Class = UEchoesQuantitySelectorWidget::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetSelectedQuantity", &UEchoesQuantitySelectorWidget::execGetSelectedQuantity },
		{ "InitializeSelector", &UEchoesQuantitySelectorWidget::execInitializeSelector },
		{ "OnCancelClicked", &UEchoesQuantitySelectorWidget::execOnCancelClicked },
		{ "OnConfirmClicked", &UEchoesQuantitySelectorWidget::execOnConfirmClicked },
		{ "OnMaxClicked", &UEchoesQuantitySelectorWidget::execOnMaxClicked },
		{ "OnQuantityTextCommitted", &UEchoesQuantitySelectorWidget::execOnQuantityTextCommitted },
		{ "OnSliderValueChanged", &UEchoesQuantitySelectorWidget::execOnSliderValueChanged },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UEchoesQuantitySelectorWidget;
UClass* UEchoesQuantitySelectorWidget::GetPrivateStaticClass()
{
	using TClass = UEchoesQuantitySelectorWidget;
	if (!Z_Registration_Info_UClass_UEchoesQuantitySelectorWidget.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesQuantitySelectorWidget"),
			Z_Registration_Info_UClass_UEchoesQuantitySelectorWidget.InnerSingleton,
			StaticRegisterNativesUEchoesQuantitySelectorWidget,
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
	return Z_Registration_Info_UClass_UEchoesQuantitySelectorWidget.InnerSingleton;
}
UClass* Z_Construct_UClass_UEchoesQuantitySelectorWidget_NoRegister()
{
	return UEchoesQuantitySelectorWidget::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UEchoesQuantitySelectorWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * UEchoesQuantitySelectorWidget\n * \n * Modal widget for selecting quantity when splitting item stacks\n * Displays when Shift+Drag is used on stackable items\n * \n * Features:\n * - Slider for quick selection\n * - Text input for precise amount\n * - Min: 1, Max: item quantity\n * - Confirm/Cancel buttons\n * \n * Usage:\n * - Create when Shift held during drag start\n * - Set max quantity from item\n * - Wait for user confirmation or cancellation\n * - Use selected quantity in drag operation\n */" },
#endif
		{ "IncludePath", "UI/EchoesQuantitySelectorWidget.h" },
		{ "ModuleRelativePath", "UI/EchoesQuantitySelectorWidget.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UEchoesQuantitySelectorWidget\n\nModal widget for selecting quantity when splitting item stacks\nDisplays when Shift+Drag is used on stackable items\n\nFeatures:\n- Slider for quick selection\n- Text input for precise amount\n- Min: 1, Max: item quantity\n- Confirm/Cancel buttons\n\nUsage:\n- Create when Shift held during drag start\n- Set max quantity from item\n- Wait for user confirmation or cancellation\n- Use selected quantity in drag operation" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnQuantitySelected_MetaData[] = {
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Called when quantity is confirmed\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesQuantitySelectorWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when quantity is confirmed" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnQuantitySelectionCancelled_MetaData[] = {
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Called when selection is cancelled\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesQuantitySelectorWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when selection is cancelled" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ConfirmButton_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Confirm button */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/EchoesQuantitySelectorWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Confirm button" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CancelButton_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Cancel button */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/EchoesQuantitySelectorWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cancel button" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxButton_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Max button (sets quantity to maximum) */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/EchoesQuantitySelectorWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Max button (sets quantity to maximum)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_QuantitySlider_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Quantity slider */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/EchoesQuantitySelectorWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Quantity slider" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_QuantityInput_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Quantity text input */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/EchoesQuantitySelectorWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Quantity text input" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectedQuantityText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Display for selected quantity */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/EchoesQuantitySelectorWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Display for selected quantity" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxQuantityText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Display for max quantity */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/EchoesQuantitySelectorWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Display for max quantity" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemNameText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Display for item name */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/EchoesQuantitySelectorWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Display for item name" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnQuantitySelected;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnQuantitySelectionCancelled;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ConfirmButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CancelButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MaxButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_QuantitySlider;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_QuantityInput;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SelectedQuantityText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MaxQuantityText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemNameText;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UEchoesQuantitySelectorWidget_GetSelectedQuantity, "GetSelectedQuantity" }, // 2433366242
		{ &Z_Construct_UFunction_UEchoesQuantitySelectorWidget_InitializeSelector, "InitializeSelector" }, // 3980089014
		{ &Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnCancelClicked, "OnCancelClicked" }, // 201294588
		{ &Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnConfirmClicked, "OnConfirmClicked" }, // 2718895111
		{ &Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnMaxClicked, "OnMaxClicked" }, // 2265883696
		{ &Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnQuantityTextCommitted, "OnQuantityTextCommitted" }, // 1625699557
		{ &Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnSelectorInitialized, "OnSelectorInitialized" }, // 2519910695
		{ &Z_Construct_UFunction_UEchoesQuantitySelectorWidget_OnSliderValueChanged, "OnSliderValueChanged" }, // 1506785327
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEchoesQuantitySelectorWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEchoesQuantitySelectorWidget_Statics::NewProp_OnQuantitySelected = { "OnQuantitySelected", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesQuantitySelectorWidget, OnQuantitySelected), Z_Construct_UDelegateFunction_Echoes_OnQuantitySelected__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnQuantitySelected_MetaData), NewProp_OnQuantitySelected_MetaData) }; // 4013708809
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEchoesQuantitySelectorWidget_Statics::NewProp_OnQuantitySelectionCancelled = { "OnQuantitySelectionCancelled", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesQuantitySelectorWidget, OnQuantitySelectionCancelled), Z_Construct_UDelegateFunction_Echoes_OnQuantitySelectionCancelled__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnQuantitySelectionCancelled_MetaData), NewProp_OnQuantitySelectionCancelled_MetaData) }; // 1971856612
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesQuantitySelectorWidget_Statics::NewProp_ConfirmButton = { "ConfirmButton", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesQuantitySelectorWidget, ConfirmButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ConfirmButton_MetaData), NewProp_ConfirmButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesQuantitySelectorWidget_Statics::NewProp_CancelButton = { "CancelButton", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesQuantitySelectorWidget, CancelButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CancelButton_MetaData), NewProp_CancelButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesQuantitySelectorWidget_Statics::NewProp_MaxButton = { "MaxButton", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesQuantitySelectorWidget, MaxButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxButton_MetaData), NewProp_MaxButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesQuantitySelectorWidget_Statics::NewProp_QuantitySlider = { "QuantitySlider", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesQuantitySelectorWidget, QuantitySlider), Z_Construct_UClass_USlider_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_QuantitySlider_MetaData), NewProp_QuantitySlider_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesQuantitySelectorWidget_Statics::NewProp_QuantityInput = { "QuantityInput", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesQuantitySelectorWidget, QuantityInput), Z_Construct_UClass_UEditableTextBox_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_QuantityInput_MetaData), NewProp_QuantityInput_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesQuantitySelectorWidget_Statics::NewProp_SelectedQuantityText = { "SelectedQuantityText", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesQuantitySelectorWidget, SelectedQuantityText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectedQuantityText_MetaData), NewProp_SelectedQuantityText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesQuantitySelectorWidget_Statics::NewProp_MaxQuantityText = { "MaxQuantityText", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesQuantitySelectorWidget, MaxQuantityText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxQuantityText_MetaData), NewProp_MaxQuantityText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesQuantitySelectorWidget_Statics::NewProp_ItemNameText = { "ItemNameText", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesQuantitySelectorWidget, ItemNameText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemNameText_MetaData), NewProp_ItemNameText_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEchoesQuantitySelectorWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesQuantitySelectorWidget_Statics::NewProp_OnQuantitySelected,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesQuantitySelectorWidget_Statics::NewProp_OnQuantitySelectionCancelled,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesQuantitySelectorWidget_Statics::NewProp_ConfirmButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesQuantitySelectorWidget_Statics::NewProp_CancelButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesQuantitySelectorWidget_Statics::NewProp_MaxButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesQuantitySelectorWidget_Statics::NewProp_QuantitySlider,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesQuantitySelectorWidget_Statics::NewProp_QuantityInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesQuantitySelectorWidget_Statics::NewProp_SelectedQuantityText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesQuantitySelectorWidget_Statics::NewProp_MaxQuantityText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesQuantitySelectorWidget_Statics::NewProp_ItemNameText,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesQuantitySelectorWidget_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UEchoesQuantitySelectorWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesQuantitySelectorWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEchoesQuantitySelectorWidget_Statics::ClassParams = {
	&UEchoesQuantitySelectorWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UEchoesQuantitySelectorWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesQuantitySelectorWidget_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesQuantitySelectorWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UEchoesQuantitySelectorWidget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEchoesQuantitySelectorWidget()
{
	if (!Z_Registration_Info_UClass_UEchoesQuantitySelectorWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEchoesQuantitySelectorWidget.OuterSingleton, Z_Construct_UClass_UEchoesQuantitySelectorWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEchoesQuantitySelectorWidget.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UEchoesQuantitySelectorWidget);
UEchoesQuantitySelectorWidget::~UEchoesQuantitySelectorWidget() {}
// ********** End Class UEchoesQuantitySelectorWidget **********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesQuantitySelectorWidget_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEchoesQuantitySelectorWidget, UEchoesQuantitySelectorWidget::StaticClass, TEXT("UEchoesQuantitySelectorWidget"), &Z_Registration_Info_UClass_UEchoesQuantitySelectorWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEchoesQuantitySelectorWidget), 2134500597U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesQuantitySelectorWidget_h__Script_Echoes_3064003455(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesQuantitySelectorWidget_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesQuantitySelectorWidget_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
