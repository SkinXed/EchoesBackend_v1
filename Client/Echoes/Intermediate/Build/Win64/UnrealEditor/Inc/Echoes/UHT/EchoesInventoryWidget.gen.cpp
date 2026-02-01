// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UI/EchoesInventoryWidget.h"
#include "Core/Common/EchoesInventoryComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesInventoryWidget() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UEchoesInventoryComponent_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UEchoesInventoryItemObject_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UEchoesInventoryWidget();
ECHOES_API UClass* Z_Construct_UClass_UEchoesInventoryWidget_NoRegister();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FEchoesContainerItems();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
UMG_API UClass* Z_Construct_UClass_UListView_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UEchoesInventoryWidget Function GetInventoryComponent ********************
struct Z_Construct_UFunction_UEchoesInventoryWidget_GetInventoryComponent_Statics
{
	struct EchoesInventoryWidget_eventGetInventoryComponent_Parms
	{
		UEchoesInventoryComponent* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the inventory component we're currently displaying\n\x09 * @return The inventory component, or nullptr if not found\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the inventory component we're currently displaying\n@return The inventory component, or nullptr if not found" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEchoesInventoryWidget_GetInventoryComponent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryWidget_eventGetInventoryComponent_Parms, ReturnValue), Z_Construct_UClass_UEchoesInventoryComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryWidget_GetInventoryComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryWidget_GetInventoryComponent_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryWidget_GetInventoryComponent_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryWidget_GetInventoryComponent_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryWidget, nullptr, "GetInventoryComponent", Z_Construct_UFunction_UEchoesInventoryWidget_GetInventoryComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryWidget_GetInventoryComponent_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryWidget_GetInventoryComponent_Statics::EchoesInventoryWidget_eventGetInventoryComponent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryWidget_GetInventoryComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryWidget_GetInventoryComponent_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryWidget_GetInventoryComponent_Statics::EchoesInventoryWidget_eventGetInventoryComponent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryWidget_GetInventoryComponent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryWidget_GetInventoryComponent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryWidget::execGetInventoryComponent)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UEchoesInventoryComponent**)Z_Param__Result=P_THIS->GetInventoryComponent();
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryWidget Function GetInventoryComponent **********************

// ********** Begin Class UEchoesInventoryWidget Function GetSelectedItem **************************
struct Z_Construct_UFunction_UEchoesInventoryWidget_GetSelectedItem_Statics
{
	struct EchoesInventoryWidget_eventGetSelectedItem_Parms
	{
		UEchoesInventoryItemObject* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the currently selected item\n\x09 * @return Selected inventory item object, or nullptr if none selected\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the currently selected item\n@return Selected inventory item object, or nullptr if none selected" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEchoesInventoryWidget_GetSelectedItem_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryWidget_eventGetSelectedItem_Parms, ReturnValue), Z_Construct_UClass_UEchoesInventoryItemObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryWidget_GetSelectedItem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryWidget_GetSelectedItem_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryWidget_GetSelectedItem_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryWidget_GetSelectedItem_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryWidget, nullptr, "GetSelectedItem", Z_Construct_UFunction_UEchoesInventoryWidget_GetSelectedItem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryWidget_GetSelectedItem_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryWidget_GetSelectedItem_Statics::EchoesInventoryWidget_eventGetSelectedItem_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryWidget_GetSelectedItem_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryWidget_GetSelectedItem_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryWidget_GetSelectedItem_Statics::EchoesInventoryWidget_eventGetSelectedItem_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryWidget_GetSelectedItem()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryWidget_GetSelectedItem_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryWidget::execGetSelectedItem)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UEchoesInventoryItemObject**)Z_Param__Result=P_THIS->GetSelectedItem();
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryWidget Function GetSelectedItem ****************************

// ********** Begin Class UEchoesInventoryWidget Function HandleFetchFailure ***********************
struct Z_Construct_UFunction_UEchoesInventoryWidget_HandleFetchFailure_Statics
{
	struct EchoesInventoryWidget_eventHandleFetchFailure_Parms
	{
		FString Error;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI/EchoesInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Error_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_Error;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEchoesInventoryWidget_HandleFetchFailure_Statics::NewProp_Error = { "Error", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryWidget_eventHandleFetchFailure_Parms, Error), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Error_MetaData), NewProp_Error_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryWidget_HandleFetchFailure_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryWidget_HandleFetchFailure_Statics::NewProp_Error,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryWidget_HandleFetchFailure_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryWidget_HandleFetchFailure_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryWidget, nullptr, "HandleFetchFailure", Z_Construct_UFunction_UEchoesInventoryWidget_HandleFetchFailure_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryWidget_HandleFetchFailure_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryWidget_HandleFetchFailure_Statics::EchoesInventoryWidget_eventHandleFetchFailure_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryWidget_HandleFetchFailure_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryWidget_HandleFetchFailure_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryWidget_HandleFetchFailure_Statics::EchoesInventoryWidget_eventHandleFetchFailure_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryWidget_HandleFetchFailure()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryWidget_HandleFetchFailure_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryWidget::execHandleFetchFailure)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Error);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleFetchFailure(Z_Param_Error);
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryWidget Function HandleFetchFailure *************************

// ********** Begin Class UEchoesInventoryWidget Function HandleMoveFailure ************************
struct Z_Construct_UFunction_UEchoesInventoryWidget_HandleMoveFailure_Statics
{
	struct EchoesInventoryWidget_eventHandleMoveFailure_Parms
	{
		FString Error;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI/EchoesInventoryWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Error_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_Error;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEchoesInventoryWidget_HandleMoveFailure_Statics::NewProp_Error = { "Error", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryWidget_eventHandleMoveFailure_Parms, Error), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Error_MetaData), NewProp_Error_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryWidget_HandleMoveFailure_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryWidget_HandleMoveFailure_Statics::NewProp_Error,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryWidget_HandleMoveFailure_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryWidget_HandleMoveFailure_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryWidget, nullptr, "HandleMoveFailure", Z_Construct_UFunction_UEchoesInventoryWidget_HandleMoveFailure_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryWidget_HandleMoveFailure_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryWidget_HandleMoveFailure_Statics::EchoesInventoryWidget_eventHandleMoveFailure_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryWidget_HandleMoveFailure_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryWidget_HandleMoveFailure_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryWidget_HandleMoveFailure_Statics::EchoesInventoryWidget_eventHandleMoveFailure_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryWidget_HandleMoveFailure()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryWidget_HandleMoveFailure_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryWidget::execHandleMoveFailure)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Error);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleMoveFailure(Z_Param_Error);
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryWidget Function HandleMoveFailure **************************

// ********** Begin Class UEchoesInventoryWidget Function HandleMoveSuccess ************************
struct Z_Construct_UFunction_UEchoesInventoryWidget_HandleMoveSuccess_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI/EchoesInventoryWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryWidget_HandleMoveSuccess_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryWidget, nullptr, "HandleMoveSuccess", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryWidget_HandleMoveSuccess_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryWidget_HandleMoveSuccess_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesInventoryWidget_HandleMoveSuccess()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryWidget_HandleMoveSuccess_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryWidget::execHandleMoveSuccess)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleMoveSuccess();
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryWidget Function HandleMoveSuccess **************************

// ********** Begin Class UEchoesInventoryWidget Function OnInventoryRefreshed *********************
static FName NAME_UEchoesInventoryWidget_OnInventoryRefreshed = FName(TEXT("OnInventoryRefreshed"));
void UEchoesInventoryWidget::OnInventoryRefreshed()
{
	UFunction* Func = FindFunctionChecked(NAME_UEchoesInventoryWidget_OnInventoryRefreshed);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_UEchoesInventoryWidget_OnInventoryRefreshed_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Blueprint event called when inventory is refreshed\n\x09 * Override in Blueprint for custom behavior\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Blueprint event called when inventory is refreshed\nOverride in Blueprint for custom behavior" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryWidget_OnInventoryRefreshed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryWidget, nullptr, "OnInventoryRefreshed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryWidget_OnInventoryRefreshed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryWidget_OnInventoryRefreshed_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesInventoryWidget_OnInventoryRefreshed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryWidget_OnInventoryRefreshed_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UEchoesInventoryWidget Function OnInventoryRefreshed ***********************

// ********** Begin Class UEchoesInventoryWidget Function OnInventoryUpdated ***********************
struct Z_Construct_UFunction_UEchoesInventoryWidget_OnInventoryUpdated_Statics
{
	struct EchoesInventoryWidget_eventOnInventoryUpdated_Parms
	{
		FEchoesContainerItems Items;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Called when inventory is updated from the component\n\x09 * @param Items - New inventory items\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when inventory is updated from the component\n@param Items - New inventory items" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Items_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Items;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesInventoryWidget_OnInventoryUpdated_Statics::NewProp_Items = { "Items", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryWidget_eventOnInventoryUpdated_Parms, Items), Z_Construct_UScriptStruct_FEchoesContainerItems, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Items_MetaData), NewProp_Items_MetaData) }; // 255446170
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryWidget_OnInventoryUpdated_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryWidget_OnInventoryUpdated_Statics::NewProp_Items,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryWidget_OnInventoryUpdated_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryWidget_OnInventoryUpdated_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryWidget, nullptr, "OnInventoryUpdated", Z_Construct_UFunction_UEchoesInventoryWidget_OnInventoryUpdated_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryWidget_OnInventoryUpdated_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryWidget_OnInventoryUpdated_Statics::EchoesInventoryWidget_eventOnInventoryUpdated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00480401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryWidget_OnInventoryUpdated_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryWidget_OnInventoryUpdated_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryWidget_OnInventoryUpdated_Statics::EchoesInventoryWidget_eventOnInventoryUpdated_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryWidget_OnInventoryUpdated()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryWidget_OnInventoryUpdated_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryWidget::execOnInventoryUpdated)
{
	P_GET_STRUCT_REF(FEchoesContainerItems,Z_Param_Out_Items);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnInventoryUpdated(Z_Param_Out_Items);
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryWidget Function OnInventoryUpdated *************************

// ********** Begin Class UEchoesInventoryWidget Function OnItemSelected ***************************
struct EchoesInventoryWidget_eventOnItemSelected_Parms
{
	UEchoesInventoryItemObject* ItemObject;
};
static FName NAME_UEchoesInventoryWidget_OnItemSelected = FName(TEXT("OnItemSelected"));
void UEchoesInventoryWidget::OnItemSelected(UEchoesInventoryItemObject* ItemObject)
{
	EchoesInventoryWidget_eventOnItemSelected_Parms Parms;
	Parms.ItemObject=ItemObject;
	UFunction* Func = FindFunctionChecked(NAME_UEchoesInventoryWidget_OnItemSelected);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UEchoesInventoryWidget_OnItemSelected_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Blueprint event called when an item is selected\n\x09 * Override in Blueprint for custom selection behavior\n\x09 * @param ItemObject - The selected item\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Blueprint event called when an item is selected\nOverride in Blueprint for custom selection behavior\n@param ItemObject - The selected item" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemObject;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEchoesInventoryWidget_OnItemSelected_Statics::NewProp_ItemObject = { "ItemObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryWidget_eventOnItemSelected_Parms, ItemObject), Z_Construct_UClass_UEchoesInventoryItemObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryWidget_OnItemSelected_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryWidget_OnItemSelected_Statics::NewProp_ItemObject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryWidget_OnItemSelected_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryWidget_OnItemSelected_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryWidget, nullptr, "OnItemSelected", Z_Construct_UFunction_UEchoesInventoryWidget_OnItemSelected_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryWidget_OnItemSelected_Statics::PropPointers), sizeof(EchoesInventoryWidget_eventOnItemSelected_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryWidget_OnItemSelected_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryWidget_OnItemSelected_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(EchoesInventoryWidget_eventOnItemSelected_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryWidget_OnItemSelected()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryWidget_OnItemSelected_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UEchoesInventoryWidget Function OnItemSelected *****************************

// ********** Begin Class UEchoesInventoryWidget Function OnItemSelectionChanged *******************
struct Z_Construct_UFunction_UEchoesInventoryWidget_OnItemSelectionChanged_Statics
{
	struct EchoesInventoryWidget_eventOnItemSelectionChanged_Parms
	{
		UObject* ItemObject;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Handle item selection changed\n\x09 * @param ItemObject - Selected item object\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handle item selection changed\n@param ItemObject - Selected item object" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemObject;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEchoesInventoryWidget_OnItemSelectionChanged_Statics::NewProp_ItemObject = { "ItemObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryWidget_eventOnItemSelectionChanged_Parms, ItemObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryWidget_OnItemSelectionChanged_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryWidget_OnItemSelectionChanged_Statics::NewProp_ItemObject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryWidget_OnItemSelectionChanged_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryWidget_OnItemSelectionChanged_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryWidget, nullptr, "OnItemSelectionChanged", Z_Construct_UFunction_UEchoesInventoryWidget_OnItemSelectionChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryWidget_OnItemSelectionChanged_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryWidget_OnItemSelectionChanged_Statics::EchoesInventoryWidget_eventOnItemSelectionChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryWidget_OnItemSelectionChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryWidget_OnItemSelectionChanged_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryWidget_OnItemSelectionChanged_Statics::EchoesInventoryWidget_eventOnItemSelectionChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryWidget_OnItemSelectionChanged()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryWidget_OnItemSelectionChanged_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryWidget::execOnItemSelectionChanged)
{
	P_GET_OBJECT(UObject,Z_Param_ItemObject);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnItemSelectionChanged(Z_Param_ItemObject);
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryWidget Function OnItemSelectionChanged *********************

// ********** Begin Class UEchoesInventoryWidget Function OnMoveRequestFailed **********************
struct EchoesInventoryWidget_eventOnMoveRequestFailed_Parms
{
	FString ErrorMessage;
};
static FName NAME_UEchoesInventoryWidget_OnMoveRequestFailed = FName(TEXT("OnMoveRequestFailed"));
void UEchoesInventoryWidget::OnMoveRequestFailed(const FString& ErrorMessage)
{
	EchoesInventoryWidget_eventOnMoveRequestFailed_Parms Parms;
	Parms.ErrorMessage=ErrorMessage;
	UFunction* Func = FindFunctionChecked(NAME_UEchoesInventoryWidget_OnMoveRequestFailed);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UEchoesInventoryWidget_OnMoveRequestFailed_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Blueprint event called when move request fails\n\x09 * Override in Blueprint to show error message\n\x09 * @param ErrorMessage - Error message to display\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Blueprint event called when move request fails\nOverride in Blueprint to show error message\n@param ErrorMessage - Error message to display" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEchoesInventoryWidget_OnMoveRequestFailed_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryWidget_eventOnMoveRequestFailed_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ErrorMessage_MetaData), NewProp_ErrorMessage_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryWidget_OnMoveRequestFailed_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryWidget_OnMoveRequestFailed_Statics::NewProp_ErrorMessage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryWidget_OnMoveRequestFailed_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryWidget_OnMoveRequestFailed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryWidget, nullptr, "OnMoveRequestFailed", Z_Construct_UFunction_UEchoesInventoryWidget_OnMoveRequestFailed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryWidget_OnMoveRequestFailed_Statics::PropPointers), sizeof(EchoesInventoryWidget_eventOnMoveRequestFailed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryWidget_OnMoveRequestFailed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryWidget_OnMoveRequestFailed_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(EchoesInventoryWidget_eventOnMoveRequestFailed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryWidget_OnMoveRequestFailed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryWidget_OnMoveRequestFailed_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UEchoesInventoryWidget Function OnMoveRequestFailed ************************

// ********** Begin Class UEchoesInventoryWidget Function PopulateInventoryList ********************
struct Z_Construct_UFunction_UEchoesInventoryWidget_PopulateInventoryList_Statics
{
	struct EchoesInventoryWidget_eventPopulateInventoryList_Parms
	{
		FEchoesContainerItems Items;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Populate the list view with inventory items\n\x09 * @param Items - Items to display\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Populate the list view with inventory items\n@param Items - Items to display" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Items_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Items;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesInventoryWidget_PopulateInventoryList_Statics::NewProp_Items = { "Items", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryWidget_eventPopulateInventoryList_Parms, Items), Z_Construct_UScriptStruct_FEchoesContainerItems, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Items_MetaData), NewProp_Items_MetaData) }; // 255446170
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryWidget_PopulateInventoryList_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryWidget_PopulateInventoryList_Statics::NewProp_Items,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryWidget_PopulateInventoryList_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryWidget_PopulateInventoryList_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryWidget, nullptr, "PopulateInventoryList", Z_Construct_UFunction_UEchoesInventoryWidget_PopulateInventoryList_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryWidget_PopulateInventoryList_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryWidget_PopulateInventoryList_Statics::EchoesInventoryWidget_eventPopulateInventoryList_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00480401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryWidget_PopulateInventoryList_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryWidget_PopulateInventoryList_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryWidget_PopulateInventoryList_Statics::EchoesInventoryWidget_eventPopulateInventoryList_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryWidget_PopulateInventoryList()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryWidget_PopulateInventoryList_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryWidget::execPopulateInventoryList)
{
	P_GET_STRUCT_REF(FEchoesContainerItems,Z_Param_Out_Items);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->PopulateInventoryList(Z_Param_Out_Items);
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryWidget Function PopulateInventoryList **********************

// ********** Begin Class UEchoesInventoryWidget Function RefreshInventory *************************
struct Z_Construct_UFunction_UEchoesInventoryWidget_RefreshInventory_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Manually refresh the inventory display\n\x09 * This will fetch items from the component and update the list\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Manually refresh the inventory display\nThis will fetch items from the component and update the list" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryWidget_RefreshInventory_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryWidget, nullptr, "RefreshInventory", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryWidget_RefreshInventory_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryWidget_RefreshInventory_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesInventoryWidget_RefreshInventory()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryWidget_RefreshInventory_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryWidget::execRefreshInventory)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshInventory();
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryWidget Function RefreshInventory ***************************

// ********** Begin Class UEchoesInventoryWidget Function SetTargetActor ***************************
struct Z_Construct_UFunction_UEchoesInventoryWidget_SetTargetActor_Statics
{
	struct EchoesInventoryWidget_eventSetTargetActor_Parms
	{
		AActor* NewTargetActor;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Set the target actor whose inventory to display\n\x09 * If not set, will use the owning player's pawn\n\x09 * @param NewTargetActor - Actor with UEchoesInventoryComponent\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set the target actor whose inventory to display\nIf not set, will use the owning player's pawn\n@param NewTargetActor - Actor with UEchoesInventoryComponent" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NewTargetActor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEchoesInventoryWidget_SetTargetActor_Statics::NewProp_NewTargetActor = { "NewTargetActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryWidget_eventSetTargetActor_Parms, NewTargetActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryWidget_SetTargetActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryWidget_SetTargetActor_Statics::NewProp_NewTargetActor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryWidget_SetTargetActor_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryWidget_SetTargetActor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryWidget, nullptr, "SetTargetActor", Z_Construct_UFunction_UEchoesInventoryWidget_SetTargetActor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryWidget_SetTargetActor_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryWidget_SetTargetActor_Statics::EchoesInventoryWidget_eventSetTargetActor_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryWidget_SetTargetActor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryWidget_SetTargetActor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryWidget_SetTargetActor_Statics::EchoesInventoryWidget_eventSetTargetActor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryWidget_SetTargetActor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryWidget_SetTargetActor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryWidget::execSetTargetActor)
{
	P_GET_OBJECT(AActor,Z_Param_NewTargetActor);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetTargetActor(Z_Param_NewTargetActor);
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryWidget Function SetTargetActor *****************************

// ********** Begin Class UEchoesInventoryWidget Function UI_RequestMoveItem ***********************
struct Z_Construct_UFunction_UEchoesInventoryWidget_UI_RequestMoveItem_Statics
{
	struct EchoesInventoryWidget_eventUI_RequestMoveItem_Parms
	{
		AActor* TargetContainerActor;
		int64 Quantity;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Request to move the selected item to another container\n\x09 * This is a UI stub that should trigger ServerOnly_MoveItem on the component\n\x09 * @param TargetContainerActor - The target actor to move items to\n\x09 * @param Quantity - Amount to move (0 = all)\n\x09 */" },
#endif
		{ "CPP_Default_Quantity", "0" },
		{ "ModuleRelativePath", "UI/EchoesInventoryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Request to move the selected item to another container\nThis is a UI stub that should trigger ServerOnly_MoveItem on the component\n@param TargetContainerActor - The target actor to move items to\n@param Quantity - Amount to move (0 = all)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetContainerActor;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_Quantity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEchoesInventoryWidget_UI_RequestMoveItem_Statics::NewProp_TargetContainerActor = { "TargetContainerActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryWidget_eventUI_RequestMoveItem_Parms, TargetContainerActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UEchoesInventoryWidget_UI_RequestMoveItem_Statics::NewProp_Quantity = { "Quantity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryWidget_eventUI_RequestMoveItem_Parms, Quantity), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryWidget_UI_RequestMoveItem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryWidget_UI_RequestMoveItem_Statics::NewProp_TargetContainerActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryWidget_UI_RequestMoveItem_Statics::NewProp_Quantity,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryWidget_UI_RequestMoveItem_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryWidget_UI_RequestMoveItem_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryWidget, nullptr, "UI_RequestMoveItem", Z_Construct_UFunction_UEchoesInventoryWidget_UI_RequestMoveItem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryWidget_UI_RequestMoveItem_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryWidget_UI_RequestMoveItem_Statics::EchoesInventoryWidget_eventUI_RequestMoveItem_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryWidget_UI_RequestMoveItem_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryWidget_UI_RequestMoveItem_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryWidget_UI_RequestMoveItem_Statics::EchoesInventoryWidget_eventUI_RequestMoveItem_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryWidget_UI_RequestMoveItem()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryWidget_UI_RequestMoveItem_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryWidget::execUI_RequestMoveItem)
{
	P_GET_OBJECT(AActor,Z_Param_TargetContainerActor);
	P_GET_PROPERTY(FInt64Property,Z_Param_Quantity);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UI_RequestMoveItem(Z_Param_TargetContainerActor,Z_Param_Quantity);
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryWidget Function UI_RequestMoveItem *************************

// ********** Begin Class UEchoesInventoryWidget ***************************************************
void UEchoesInventoryWidget::StaticRegisterNativesUEchoesInventoryWidget()
{
	UClass* Class = UEchoesInventoryWidget::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetInventoryComponent", &UEchoesInventoryWidget::execGetInventoryComponent },
		{ "GetSelectedItem", &UEchoesInventoryWidget::execGetSelectedItem },
		{ "HandleFetchFailure", &UEchoesInventoryWidget::execHandleFetchFailure },
		{ "HandleMoveFailure", &UEchoesInventoryWidget::execHandleMoveFailure },
		{ "HandleMoveSuccess", &UEchoesInventoryWidget::execHandleMoveSuccess },
		{ "OnInventoryUpdated", &UEchoesInventoryWidget::execOnInventoryUpdated },
		{ "OnItemSelectionChanged", &UEchoesInventoryWidget::execOnItemSelectionChanged },
		{ "PopulateInventoryList", &UEchoesInventoryWidget::execPopulateInventoryList },
		{ "RefreshInventory", &UEchoesInventoryWidget::execRefreshInventory },
		{ "SetTargetActor", &UEchoesInventoryWidget::execSetTargetActor },
		{ "UI_RequestMoveItem", &UEchoesInventoryWidget::execUI_RequestMoveItem },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UEchoesInventoryWidget;
UClass* UEchoesInventoryWidget::GetPrivateStaticClass()
{
	using TClass = UEchoesInventoryWidget;
	if (!Z_Registration_Info_UClass_UEchoesInventoryWidget.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesInventoryWidget"),
			Z_Registration_Info_UClass_UEchoesInventoryWidget.InnerSingleton,
			StaticRegisterNativesUEchoesInventoryWidget,
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
	return Z_Registration_Info_UClass_UEchoesInventoryWidget.InnerSingleton;
}
UClass* Z_Construct_UClass_UEchoesInventoryWidget_NoRegister()
{
	return UEchoesInventoryWidget::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UEchoesInventoryWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * UEchoesInventoryWidget\n * \n * Main inventory UI widget using ListView\n * Displays contents of a UEchoesInventoryComponent\n * \n * Features:\n * - Automatic binding to owner's or target actor's inventory component\n * - Event-driven updates via OnInventoryUpdated delegate\n * - ListView-based display for efficient rendering\n * - Selection support\n * - Drag-and-drop preparation\n * \n * Usage:\n * - Create widget blueprint based on this class\n * - Add UListView widget (name it \"InventoryListView\")\n * - Set entry widget class in ListView properties\n * - Optionally set TargetActor to view another actor's inventory\n * - Call RefreshInventory() to manually refresh\n */" },
#endif
		{ "IncludePath", "UI/EchoesInventoryWidget.h" },
		{ "ModuleRelativePath", "UI/EchoesInventoryWidget.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UEchoesInventoryWidget\n\nMain inventory UI widget using ListView\nDisplays contents of a UEchoesInventoryComponent\n\nFeatures:\n- Automatic binding to owner's or target actor's inventory component\n- Event-driven updates via OnInventoryUpdated delegate\n- ListView-based display for efficient rendering\n- Selection support\n- Drag-and-drop preparation\n\nUsage:\n- Create widget blueprint based on this class\n- Add UListView widget (name it \"InventoryListView\")\n- Set entry widget class in ListView properties\n- Optionally set TargetActor to view another actor's inventory\n- Call RefreshInventory() to manually refresh" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InventoryListView_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** ListView widget for displaying inventory items */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/EchoesInventoryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "ListView widget for displaying inventory items" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetActor_MetaData[] = {
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional target actor to display inventory from (if not owner) */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional target actor to display inventory from (if not owner)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoRefreshOnConstruct_MetaData[] = {
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether to auto-refresh on construct */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether to auto-refresh on construct" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InventoryComponent_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Cached inventory component reference */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/EchoesInventoryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cached inventory component reference" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentViewedActor_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Actor we're currently viewing inventory from */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Actor we're currently viewing inventory from" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InventoryListView;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetActor;
	static void NewProp_bAutoRefreshOnConstruct_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoRefreshOnConstruct;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InventoryComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentViewedActor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UEchoesInventoryWidget_GetInventoryComponent, "GetInventoryComponent" }, // 2316844330
		{ &Z_Construct_UFunction_UEchoesInventoryWidget_GetSelectedItem, "GetSelectedItem" }, // 173113074
		{ &Z_Construct_UFunction_UEchoesInventoryWidget_HandleFetchFailure, "HandleFetchFailure" }, // 1855805608
		{ &Z_Construct_UFunction_UEchoesInventoryWidget_HandleMoveFailure, "HandleMoveFailure" }, // 2107568726
		{ &Z_Construct_UFunction_UEchoesInventoryWidget_HandleMoveSuccess, "HandleMoveSuccess" }, // 1781289213
		{ &Z_Construct_UFunction_UEchoesInventoryWidget_OnInventoryRefreshed, "OnInventoryRefreshed" }, // 1549495489
		{ &Z_Construct_UFunction_UEchoesInventoryWidget_OnInventoryUpdated, "OnInventoryUpdated" }, // 1356989780
		{ &Z_Construct_UFunction_UEchoesInventoryWidget_OnItemSelected, "OnItemSelected" }, // 30396570
		{ &Z_Construct_UFunction_UEchoesInventoryWidget_OnItemSelectionChanged, "OnItemSelectionChanged" }, // 395295388
		{ &Z_Construct_UFunction_UEchoesInventoryWidget_OnMoveRequestFailed, "OnMoveRequestFailed" }, // 410819925
		{ &Z_Construct_UFunction_UEchoesInventoryWidget_PopulateInventoryList, "PopulateInventoryList" }, // 1475844961
		{ &Z_Construct_UFunction_UEchoesInventoryWidget_RefreshInventory, "RefreshInventory" }, // 4035071541
		{ &Z_Construct_UFunction_UEchoesInventoryWidget_SetTargetActor, "SetTargetActor" }, // 232477453
		{ &Z_Construct_UFunction_UEchoesInventoryWidget_UI_RequestMoveItem, "UI_RequestMoveItem" }, // 1855464797
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEchoesInventoryWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesInventoryWidget_Statics::NewProp_InventoryListView = { "InventoryListView", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesInventoryWidget, InventoryListView), Z_Construct_UClass_UListView_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InventoryListView_MetaData), NewProp_InventoryListView_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesInventoryWidget_Statics::NewProp_TargetActor = { "TargetActor", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesInventoryWidget, TargetActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetActor_MetaData), NewProp_TargetActor_MetaData) };
void Z_Construct_UClass_UEchoesInventoryWidget_Statics::NewProp_bAutoRefreshOnConstruct_SetBit(void* Obj)
{
	((UEchoesInventoryWidget*)Obj)->bAutoRefreshOnConstruct = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UEchoesInventoryWidget_Statics::NewProp_bAutoRefreshOnConstruct = { "bAutoRefreshOnConstruct", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UEchoesInventoryWidget), &Z_Construct_UClass_UEchoesInventoryWidget_Statics::NewProp_bAutoRefreshOnConstruct_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoRefreshOnConstruct_MetaData), NewProp_bAutoRefreshOnConstruct_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesInventoryWidget_Statics::NewProp_InventoryComponent = { "InventoryComponent", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesInventoryWidget, InventoryComponent), Z_Construct_UClass_UEchoesInventoryComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InventoryComponent_MetaData), NewProp_InventoryComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesInventoryWidget_Statics::NewProp_CurrentViewedActor = { "CurrentViewedActor", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesInventoryWidget, CurrentViewedActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentViewedActor_MetaData), NewProp_CurrentViewedActor_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEchoesInventoryWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesInventoryWidget_Statics::NewProp_InventoryListView,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesInventoryWidget_Statics::NewProp_TargetActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesInventoryWidget_Statics::NewProp_bAutoRefreshOnConstruct,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesInventoryWidget_Statics::NewProp_InventoryComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesInventoryWidget_Statics::NewProp_CurrentViewedActor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesInventoryWidget_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UEchoesInventoryWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesInventoryWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEchoesInventoryWidget_Statics::ClassParams = {
	&UEchoesInventoryWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UEchoesInventoryWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesInventoryWidget_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesInventoryWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UEchoesInventoryWidget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEchoesInventoryWidget()
{
	if (!Z_Registration_Info_UClass_UEchoesInventoryWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEchoesInventoryWidget.OuterSingleton, Z_Construct_UClass_UEchoesInventoryWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEchoesInventoryWidget.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UEchoesInventoryWidget);
UEchoesInventoryWidget::~UEchoesInventoryWidget() {}
// ********** End Class UEchoesInventoryWidget *****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesInventoryWidget_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEchoesInventoryWidget, UEchoesInventoryWidget::StaticClass, TEXT("UEchoesInventoryWidget"), &Z_Registration_Info_UClass_UEchoesInventoryWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEchoesInventoryWidget), 2522707317U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesInventoryWidget_h__Script_Echoes_919792143(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesInventoryWidget_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesInventoryWidget_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
