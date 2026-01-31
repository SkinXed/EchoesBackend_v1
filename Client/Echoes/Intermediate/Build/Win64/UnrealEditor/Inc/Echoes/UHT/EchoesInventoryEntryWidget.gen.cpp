// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Echoes/UI/EchoesInventoryEntryWidget.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesInventoryEntryWidget() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ECHOES_API UClass* Z_Construct_UClass_UEchoesContextMenuWidget_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UEchoesInventoryEntryWidget();
ECHOES_API UClass* Z_Construct_UClass_UEchoesInventoryEntryWidget_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UEchoesInventoryItemObject_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UEchoesQuantitySelectorWidget_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
UMG_API UClass* Z_Construct_UClass_UImage_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserObjectListEntry_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UEchoesInventoryEntryWidget Function HandleContextMenuAction *************
struct Z_Construct_UFunction_UEchoesInventoryEntryWidget_HandleContextMenuAction_Statics
{
	struct EchoesInventoryEntryWidget_eventHandleContextMenuAction_Parms
	{
		FString ActionId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Handle context menu action selected\n\x09 * @param ActionId - ID of selected action\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryEntryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handle context menu action selected\n@param ActionId - ID of selected action" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActionId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ActionId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEchoesInventoryEntryWidget_HandleContextMenuAction_Statics::NewProp_ActionId = { "ActionId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryEntryWidget_eventHandleContextMenuAction_Parms, ActionId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActionId_MetaData), NewProp_ActionId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryEntryWidget_HandleContextMenuAction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryEntryWidget_HandleContextMenuAction_Statics::NewProp_ActionId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryEntryWidget_HandleContextMenuAction_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryEntryWidget_HandleContextMenuAction_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryEntryWidget, nullptr, "HandleContextMenuAction", Z_Construct_UFunction_UEchoesInventoryEntryWidget_HandleContextMenuAction_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryEntryWidget_HandleContextMenuAction_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryEntryWidget_HandleContextMenuAction_Statics::EchoesInventoryEntryWidget_eventHandleContextMenuAction_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryEntryWidget_HandleContextMenuAction_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryEntryWidget_HandleContextMenuAction_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryEntryWidget_HandleContextMenuAction_Statics::EchoesInventoryEntryWidget_eventHandleContextMenuAction_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryEntryWidget_HandleContextMenuAction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryEntryWidget_HandleContextMenuAction_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryEntryWidget::execHandleContextMenuAction)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ActionId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleContextMenuAction(Z_Param_ActionId);
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryEntryWidget Function HandleContextMenuAction ***************

// ********** Begin Class UEchoesInventoryEntryWidget Function HandleIconLoaded ********************
struct Z_Construct_UFunction_UEchoesInventoryEntryWidget_HandleIconLoaded_Statics
{
	struct EchoesInventoryEntryWidget_eventHandleIconLoaded_Parms
	{
		UTexture2D* LoadedIcon;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Handle icon loaded callback\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryEntryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handle icon loaded callback" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LoadedIcon;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEchoesInventoryEntryWidget_HandleIconLoaded_Statics::NewProp_LoadedIcon = { "LoadedIcon", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryEntryWidget_eventHandleIconLoaded_Parms, LoadedIcon), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryEntryWidget_HandleIconLoaded_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryEntryWidget_HandleIconLoaded_Statics::NewProp_LoadedIcon,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryEntryWidget_HandleIconLoaded_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryEntryWidget_HandleIconLoaded_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryEntryWidget, nullptr, "HandleIconLoaded", Z_Construct_UFunction_UEchoesInventoryEntryWidget_HandleIconLoaded_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryEntryWidget_HandleIconLoaded_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryEntryWidget_HandleIconLoaded_Statics::EchoesInventoryEntryWidget_eventHandleIconLoaded_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryEntryWidget_HandleIconLoaded_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryEntryWidget_HandleIconLoaded_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryEntryWidget_HandleIconLoaded_Statics::EchoesInventoryEntryWidget_eventHandleIconLoaded_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryEntryWidget_HandleIconLoaded()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryEntryWidget_HandleIconLoaded_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryEntryWidget::execHandleIconLoaded)
{
	P_GET_OBJECT(UTexture2D,Z_Param_LoadedIcon);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleIconLoaded(Z_Param_LoadedIcon);
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryEntryWidget Function HandleIconLoaded **********************

// ********** Begin Class UEchoesInventoryEntryWidget Function OnDragQuantityCancelled *************
struct Z_Construct_UFunction_UEchoesInventoryEntryWidget_OnDragQuantityCancelled_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Handle quantity selection cancelled for drag operation\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryEntryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handle quantity selection cancelled for drag operation" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryEntryWidget_OnDragQuantityCancelled_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryEntryWidget, nullptr, "OnDragQuantityCancelled", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryEntryWidget_OnDragQuantityCancelled_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryEntryWidget_OnDragQuantityCancelled_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesInventoryEntryWidget_OnDragQuantityCancelled()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryEntryWidget_OnDragQuantityCancelled_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryEntryWidget::execOnDragQuantityCancelled)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnDragQuantityCancelled();
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryEntryWidget Function OnDragQuantityCancelled ***************

// ********** Begin Class UEchoesInventoryEntryWidget Function OnDragQuantitySelected **************
struct Z_Construct_UFunction_UEchoesInventoryEntryWidget_OnDragQuantitySelected_Statics
{
	struct EchoesInventoryEntryWidget_eventOnDragQuantitySelected_Parms
	{
		int64 SelectedQuantity;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Handle quantity selected for drag operation\n\x09 * @param SelectedQuantity - Quantity selected by user\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryEntryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handle quantity selected for drag operation\n@param SelectedQuantity - Quantity selected by user" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FInt64PropertyParams NewProp_SelectedQuantity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UEchoesInventoryEntryWidget_OnDragQuantitySelected_Statics::NewProp_SelectedQuantity = { "SelectedQuantity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryEntryWidget_eventOnDragQuantitySelected_Parms, SelectedQuantity), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryEntryWidget_OnDragQuantitySelected_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryEntryWidget_OnDragQuantitySelected_Statics::NewProp_SelectedQuantity,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryEntryWidget_OnDragQuantitySelected_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryEntryWidget_OnDragQuantitySelected_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryEntryWidget, nullptr, "OnDragQuantitySelected", Z_Construct_UFunction_UEchoesInventoryEntryWidget_OnDragQuantitySelected_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryEntryWidget_OnDragQuantitySelected_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryEntryWidget_OnDragQuantitySelected_Statics::EchoesInventoryEntryWidget_eventOnDragQuantitySelected_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryEntryWidget_OnDragQuantitySelected_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryEntryWidget_OnDragQuantitySelected_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryEntryWidget_OnDragQuantitySelected_Statics::EchoesInventoryEntryWidget_eventOnDragQuantitySelected_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryEntryWidget_OnDragQuantitySelected()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryEntryWidget_OnDragQuantitySelected_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryEntryWidget::execOnDragQuantitySelected)
{
	P_GET_PROPERTY(FInt64Property,Z_Param_SelectedQuantity);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnDragQuantitySelected(Z_Param_SelectedQuantity);
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryEntryWidget Function OnDragQuantitySelected ****************

// ********** Begin Class UEchoesInventoryEntryWidget Function OnJettisonQuantityCancelled *********
struct Z_Construct_UFunction_UEchoesInventoryEntryWidget_OnJettisonQuantityCancelled_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Handle quantity selection cancelled for jettison operation\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryEntryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handle quantity selection cancelled for jettison operation" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryEntryWidget_OnJettisonQuantityCancelled_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryEntryWidget, nullptr, "OnJettisonQuantityCancelled", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryEntryWidget_OnJettisonQuantityCancelled_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryEntryWidget_OnJettisonQuantityCancelled_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesInventoryEntryWidget_OnJettisonQuantityCancelled()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryEntryWidget_OnJettisonQuantityCancelled_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryEntryWidget::execOnJettisonQuantityCancelled)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnJettisonQuantityCancelled();
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryEntryWidget Function OnJettisonQuantityCancelled ***********

// ********** Begin Class UEchoesInventoryEntryWidget Function OnJettisonQuantitySelected **********
struct Z_Construct_UFunction_UEchoesInventoryEntryWidget_OnJettisonQuantitySelected_Statics
{
	struct EchoesInventoryEntryWidget_eventOnJettisonQuantitySelected_Parms
	{
		int64 SelectedQuantity;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Handle quantity selected for jettison operation\n\x09 * @param SelectedQuantity - Quantity selected by user\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryEntryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handle quantity selected for jettison operation\n@param SelectedQuantity - Quantity selected by user" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FInt64PropertyParams NewProp_SelectedQuantity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UEchoesInventoryEntryWidget_OnJettisonQuantitySelected_Statics::NewProp_SelectedQuantity = { "SelectedQuantity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryEntryWidget_eventOnJettisonQuantitySelected_Parms, SelectedQuantity), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryEntryWidget_OnJettisonQuantitySelected_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryEntryWidget_OnJettisonQuantitySelected_Statics::NewProp_SelectedQuantity,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryEntryWidget_OnJettisonQuantitySelected_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryEntryWidget_OnJettisonQuantitySelected_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryEntryWidget, nullptr, "OnJettisonQuantitySelected", Z_Construct_UFunction_UEchoesInventoryEntryWidget_OnJettisonQuantitySelected_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryEntryWidget_OnJettisonQuantitySelected_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryEntryWidget_OnJettisonQuantitySelected_Statics::EchoesInventoryEntryWidget_eventOnJettisonQuantitySelected_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryEntryWidget_OnJettisonQuantitySelected_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryEntryWidget_OnJettisonQuantitySelected_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryEntryWidget_OnJettisonQuantitySelected_Statics::EchoesInventoryEntryWidget_eventOnJettisonQuantitySelected_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryEntryWidget_OnJettisonQuantitySelected()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryEntryWidget_OnJettisonQuantitySelected_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryEntryWidget::execOnJettisonQuantitySelected)
{
	P_GET_PROPERTY(FInt64Property,Z_Param_SelectedQuantity);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnJettisonQuantitySelected(Z_Param_SelectedQuantity);
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryEntryWidget Function OnJettisonQuantitySelected ************

// ********** Begin Class UEchoesInventoryEntryWidget Function SetItemData *************************
struct Z_Construct_UFunction_UEchoesInventoryEntryWidget_SetItemData_Statics
{
	struct EchoesInventoryEntryWidget_eventSetItemData_Parms
	{
		UEchoesInventoryItemObject* ItemObject;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Set the item data to display\n\x09 * Called automatically by ListView when item is set\n\x09 * @param ItemObject - The inventory item object to display\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryEntryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set the item data to display\nCalled automatically by ListView when item is set\n@param ItemObject - The inventory item object to display" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemObject;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEchoesInventoryEntryWidget_SetItemData_Statics::NewProp_ItemObject = { "ItemObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryEntryWidget_eventSetItemData_Parms, ItemObject), Z_Construct_UClass_UEchoesInventoryItemObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryEntryWidget_SetItemData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryEntryWidget_SetItemData_Statics::NewProp_ItemObject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryEntryWidget_SetItemData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryEntryWidget_SetItemData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryEntryWidget, nullptr, "SetItemData", Z_Construct_UFunction_UEchoesInventoryEntryWidget_SetItemData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryEntryWidget_SetItemData_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryEntryWidget_SetItemData_Statics::EchoesInventoryEntryWidget_eventSetItemData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryEntryWidget_SetItemData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryEntryWidget_SetItemData_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryEntryWidget_SetItemData_Statics::EchoesInventoryEntryWidget_eventSetItemData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryEntryWidget_SetItemData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryEntryWidget_SetItemData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryEntryWidget::execSetItemData)
{
	P_GET_OBJECT(UEchoesInventoryItemObject,Z_Param_ItemObject);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetItemData(Z_Param_ItemObject);
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryEntryWidget Function SetItemData ***************************

// ********** Begin Class UEchoesInventoryEntryWidget **********************************************
void UEchoesInventoryEntryWidget::StaticRegisterNativesUEchoesInventoryEntryWidget()
{
	UClass* Class = UEchoesInventoryEntryWidget::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "HandleContextMenuAction", &UEchoesInventoryEntryWidget::execHandleContextMenuAction },
		{ "HandleIconLoaded", &UEchoesInventoryEntryWidget::execHandleIconLoaded },
		{ "OnDragQuantityCancelled", &UEchoesInventoryEntryWidget::execOnDragQuantityCancelled },
		{ "OnDragQuantitySelected", &UEchoesInventoryEntryWidget::execOnDragQuantitySelected },
		{ "OnJettisonQuantityCancelled", &UEchoesInventoryEntryWidget::execOnJettisonQuantityCancelled },
		{ "OnJettisonQuantitySelected", &UEchoesInventoryEntryWidget::execOnJettisonQuantitySelected },
		{ "SetItemData", &UEchoesInventoryEntryWidget::execSetItemData },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UEchoesInventoryEntryWidget;
UClass* UEchoesInventoryEntryWidget::GetPrivateStaticClass()
{
	using TClass = UEchoesInventoryEntryWidget;
	if (!Z_Registration_Info_UClass_UEchoesInventoryEntryWidget.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesInventoryEntryWidget"),
			Z_Registration_Info_UClass_UEchoesInventoryEntryWidget.InnerSingleton,
			StaticRegisterNativesUEchoesInventoryEntryWidget,
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
	return Z_Registration_Info_UClass_UEchoesInventoryEntryWidget.InnerSingleton;
}
UClass* Z_Construct_UClass_UEchoesInventoryEntryWidget_NoRegister()
{
	return UEchoesInventoryEntryWidget::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UEchoesInventoryEntryWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * UEchoesInventoryEntryWidget\n * \n * Entry widget for inventory list items\n * Implements IUserObjectListEntry to work with UListView\n * Displays item icon, name, quantity, and volume\n * \n * Usage in UMG:\n * - Create a widget blueprint based on this class\n * - Add UImage for icon (name it \"ItemIcon\")\n * - Add UTextBlock for name (name it \"ItemNameText\")\n * - Add UTextBlock for quantity (name it \"QuantityText\")\n * - Add UTextBlock for volume (name it \"VolumeText\")\n * - Set this blueprint as Entry Widget Class in ListView\n */" },
#endif
		{ "IncludePath", "UI/EchoesInventoryEntryWidget.h" },
		{ "ModuleRelativePath", "UI/EchoesInventoryEntryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UEchoesInventoryEntryWidget\n\nEntry widget for inventory list items\nImplements IUserObjectListEntry to work with UListView\nDisplays item icon, name, quantity, and volume\n\nUsage in UMG:\n- Create a widget blueprint based on this class\n- Add UImage for icon (name it \"ItemIcon\")\n- Add UTextBlock for name (name it \"ItemNameText\")\n- Add UTextBlock for quantity (name it \"QuantityText\")\n- Add UTextBlock for volume (name it \"VolumeText\")\n- Set this blueprint as Entry Widget Class in ListView" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemIcon_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Image widget for item icon */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/EchoesInventoryEntryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Image widget for item icon" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemNameText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Text block for item name */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/EchoesInventoryEntryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Text block for item name" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_QuantityText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Text block for quantity */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/EchoesInventoryEntryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Text block for quantity" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VolumeText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Text block for volume */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/EchoesInventoryEntryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Text block for volume" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlaceholderIcon_MetaData[] = {
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional: Placeholder icon shown while loading */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryEntryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional: Placeholder icon shown while loading" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ContextMenuClass_MetaData[] = {
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Context menu widget class */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryEntryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Context menu widget class" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_QuantitySelectorClass_MetaData[] = {
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Quantity selector widget class */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryEntryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Quantity selector widget class" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentItemObject_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current item object being displayed */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryEntryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current item object being displayed" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemIcon;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemNameText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_QuantityText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_VolumeText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlaceholderIcon;
	static const UECodeGen_Private::FClassPropertyParams NewProp_ContextMenuClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_QuantitySelectorClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentItemObject;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UEchoesInventoryEntryWidget_HandleContextMenuAction, "HandleContextMenuAction" }, // 589391854
		{ &Z_Construct_UFunction_UEchoesInventoryEntryWidget_HandleIconLoaded, "HandleIconLoaded" }, // 3370816314
		{ &Z_Construct_UFunction_UEchoesInventoryEntryWidget_OnDragQuantityCancelled, "OnDragQuantityCancelled" }, // 2729483125
		{ &Z_Construct_UFunction_UEchoesInventoryEntryWidget_OnDragQuantitySelected, "OnDragQuantitySelected" }, // 1161400816
		{ &Z_Construct_UFunction_UEchoesInventoryEntryWidget_OnJettisonQuantityCancelled, "OnJettisonQuantityCancelled" }, // 53401379
		{ &Z_Construct_UFunction_UEchoesInventoryEntryWidget_OnJettisonQuantitySelected, "OnJettisonQuantitySelected" }, // 45606962
		{ &Z_Construct_UFunction_UEchoesInventoryEntryWidget_SetItemData, "SetItemData" }, // 2982626831
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEchoesInventoryEntryWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesInventoryEntryWidget_Statics::NewProp_ItemIcon = { "ItemIcon", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesInventoryEntryWidget, ItemIcon), Z_Construct_UClass_UImage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemIcon_MetaData), NewProp_ItemIcon_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesInventoryEntryWidget_Statics::NewProp_ItemNameText = { "ItemNameText", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesInventoryEntryWidget, ItemNameText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemNameText_MetaData), NewProp_ItemNameText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesInventoryEntryWidget_Statics::NewProp_QuantityText = { "QuantityText", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesInventoryEntryWidget, QuantityText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_QuantityText_MetaData), NewProp_QuantityText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesInventoryEntryWidget_Statics::NewProp_VolumeText = { "VolumeText", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesInventoryEntryWidget, VolumeText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VolumeText_MetaData), NewProp_VolumeText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesInventoryEntryWidget_Statics::NewProp_PlaceholderIcon = { "PlaceholderIcon", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesInventoryEntryWidget, PlaceholderIcon), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlaceholderIcon_MetaData), NewProp_PlaceholderIcon_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UEchoesInventoryEntryWidget_Statics::NewProp_ContextMenuClass = { "ContextMenuClass", nullptr, (EPropertyFlags)0x0024080000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesInventoryEntryWidget, ContextMenuClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UEchoesContextMenuWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ContextMenuClass_MetaData), NewProp_ContextMenuClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UEchoesInventoryEntryWidget_Statics::NewProp_QuantitySelectorClass = { "QuantitySelectorClass", nullptr, (EPropertyFlags)0x0024080000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesInventoryEntryWidget, QuantitySelectorClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UEchoesQuantitySelectorWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_QuantitySelectorClass_MetaData), NewProp_QuantitySelectorClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesInventoryEntryWidget_Statics::NewProp_CurrentItemObject = { "CurrentItemObject", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesInventoryEntryWidget, CurrentItemObject), Z_Construct_UClass_UEchoesInventoryItemObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentItemObject_MetaData), NewProp_CurrentItemObject_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEchoesInventoryEntryWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesInventoryEntryWidget_Statics::NewProp_ItemIcon,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesInventoryEntryWidget_Statics::NewProp_ItemNameText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesInventoryEntryWidget_Statics::NewProp_QuantityText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesInventoryEntryWidget_Statics::NewProp_VolumeText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesInventoryEntryWidget_Statics::NewProp_PlaceholderIcon,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesInventoryEntryWidget_Statics::NewProp_ContextMenuClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesInventoryEntryWidget_Statics::NewProp_QuantitySelectorClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesInventoryEntryWidget_Statics::NewProp_CurrentItemObject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesInventoryEntryWidget_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UEchoesInventoryEntryWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesInventoryEntryWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UEchoesInventoryEntryWidget_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UUserObjectListEntry_NoRegister, (int32)VTABLE_OFFSET(UEchoesInventoryEntryWidget, IUserObjectListEntry), false },  // 1900202470
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEchoesInventoryEntryWidget_Statics::ClassParams = {
	&UEchoesInventoryEntryWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UEchoesInventoryEntryWidget_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesInventoryEntryWidget_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesInventoryEntryWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UEchoesInventoryEntryWidget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEchoesInventoryEntryWidget()
{
	if (!Z_Registration_Info_UClass_UEchoesInventoryEntryWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEchoesInventoryEntryWidget.OuterSingleton, Z_Construct_UClass_UEchoesInventoryEntryWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEchoesInventoryEntryWidget.OuterSingleton;
}
UEchoesInventoryEntryWidget::UEchoesInventoryEntryWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UEchoesInventoryEntryWidget);
UEchoesInventoryEntryWidget::~UEchoesInventoryEntryWidget() {}
// ********** End Class UEchoesInventoryEntryWidget ************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesInventoryEntryWidget_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEchoesInventoryEntryWidget, UEchoesInventoryEntryWidget::StaticClass, TEXT("UEchoesInventoryEntryWidget"), &Z_Registration_Info_UClass_UEchoesInventoryEntryWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEchoesInventoryEntryWidget), 3647344185U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesInventoryEntryWidget_h__Script_Echoes_3249718318(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesInventoryEntryWidget_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesInventoryEntryWidget_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
