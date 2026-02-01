// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UI/EchoesContextMenuWidget.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesContextMenuWidget() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ECHOES_API UClass* Z_Construct_UClass_UEchoesContextMenuActionButton();
ECHOES_API UClass* Z_Construct_UClass_UEchoesContextMenuActionButton_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UEchoesContextMenuWidget();
ECHOES_API UClass* Z_Construct_UClass_UEchoesContextMenuWidget_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UEchoesInventoryItemObject_NoRegister();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnContextMenuActionSelected__DelegateSignature();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FContextMenuAction();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
UMG_API UClass* Z_Construct_UClass_UButton();
UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UMG_API UClass* Z_Construct_UClass_UVerticalBox_NoRegister();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UEchoesContextMenuActionButton Function HandleClicked ********************
struct Z_Construct_UFunction_UEchoesContextMenuActionButton_HandleClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI/EchoesContextMenuWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesContextMenuActionButton_HandleClicked_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesContextMenuActionButton, nullptr, "HandleClicked", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesContextMenuActionButton_HandleClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesContextMenuActionButton_HandleClicked_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesContextMenuActionButton_HandleClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesContextMenuActionButton_HandleClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesContextMenuActionButton::execHandleClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleClicked();
	P_NATIVE_END;
}
// ********** End Class UEchoesContextMenuActionButton Function HandleClicked **********************

// ********** Begin Class UEchoesContextMenuActionButton *******************************************
void UEchoesContextMenuActionButton::StaticRegisterNativesUEchoesContextMenuActionButton()
{
	UClass* Class = UEchoesContextMenuActionButton::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "HandleClicked", &UEchoesContextMenuActionButton::execHandleClicked },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UEchoesContextMenuActionButton;
UClass* UEchoesContextMenuActionButton::GetPrivateStaticClass()
{
	using TClass = UEchoesContextMenuActionButton;
	if (!Z_Registration_Info_UClass_UEchoesContextMenuActionButton.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesContextMenuActionButton"),
			Z_Registration_Info_UClass_UEchoesContextMenuActionButton.InnerSingleton,
			StaticRegisterNativesUEchoesContextMenuActionButton,
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
	return Z_Registration_Info_UClass_UEchoesContextMenuActionButton.InnerSingleton;
}
UClass* Z_Construct_UClass_UEchoesContextMenuActionButton_NoRegister()
{
	return UEchoesContextMenuActionButton::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UEchoesContextMenuActionButton_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "UI/EchoesContextMenuWidget.h" },
		{ "ModuleRelativePath", "UI/EchoesContextMenuWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActionId_MetaData[] = {
		{ "ModuleRelativePath", "UI/EchoesContextMenuWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OwnerWidget_MetaData[] = {
		{ "ModuleRelativePath", "UI/EchoesContextMenuWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ActionId;
	static const UECodeGen_Private::FWeakObjectPropertyParams NewProp_OwnerWidget;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UEchoesContextMenuActionButton_HandleClicked, "HandleClicked" }, // 2861169340
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEchoesContextMenuActionButton>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UEchoesContextMenuActionButton_Statics::NewProp_ActionId = { "ActionId", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesContextMenuActionButton, ActionId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActionId_MetaData), NewProp_ActionId_MetaData) };
const UECodeGen_Private::FWeakObjectPropertyParams Z_Construct_UClass_UEchoesContextMenuActionButton_Statics::NewProp_OwnerWidget = { "OwnerWidget", nullptr, (EPropertyFlags)0x0014000000080008, UECodeGen_Private::EPropertyGenFlags::WeakObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesContextMenuActionButton, OwnerWidget), Z_Construct_UClass_UEchoesContextMenuWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OwnerWidget_MetaData), NewProp_OwnerWidget_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEchoesContextMenuActionButton_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesContextMenuActionButton_Statics::NewProp_ActionId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesContextMenuActionButton_Statics::NewProp_OwnerWidget,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesContextMenuActionButton_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UEchoesContextMenuActionButton_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UButton,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesContextMenuActionButton_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEchoesContextMenuActionButton_Statics::ClassParams = {
	&UEchoesContextMenuActionButton::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UEchoesContextMenuActionButton_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesContextMenuActionButton_Statics::PropPointers),
	0,
	0x00B000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesContextMenuActionButton_Statics::Class_MetaDataParams), Z_Construct_UClass_UEchoesContextMenuActionButton_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEchoesContextMenuActionButton()
{
	if (!Z_Registration_Info_UClass_UEchoesContextMenuActionButton.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEchoesContextMenuActionButton.OuterSingleton, Z_Construct_UClass_UEchoesContextMenuActionButton_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEchoesContextMenuActionButton.OuterSingleton;
}
UEchoesContextMenuActionButton::UEchoesContextMenuActionButton(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UEchoesContextMenuActionButton);
UEchoesContextMenuActionButton::~UEchoesContextMenuActionButton() {}
// ********** End Class UEchoesContextMenuActionButton *********************************************

// ********** Begin Delegate FOnContextMenuActionSelected ******************************************
struct Z_Construct_UDelegateFunction_Echoes_OnContextMenuActionSelected__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnContextMenuActionSelected_Parms
	{
		FString ActionName;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Delegate for context menu action\n" },
#endif
		{ "ModuleRelativePath", "UI/EchoesContextMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Delegate for context menu action" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActionName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ActionName;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_Echoes_OnContextMenuActionSelected__DelegateSignature_Statics::NewProp_ActionName = { "ActionName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnContextMenuActionSelected_Parms, ActionName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActionName_MetaData), NewProp_ActionName_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnContextMenuActionSelected__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnContextMenuActionSelected__DelegateSignature_Statics::NewProp_ActionName,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnContextMenuActionSelected__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnContextMenuActionSelected__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnContextMenuActionSelected__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnContextMenuActionSelected__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnContextMenuActionSelected__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnContextMenuActionSelected__DelegateSignature_Statics::_Script_Echoes_eventOnContextMenuActionSelected_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnContextMenuActionSelected__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnContextMenuActionSelected__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnContextMenuActionSelected__DelegateSignature_Statics::_Script_Echoes_eventOnContextMenuActionSelected_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnContextMenuActionSelected__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnContextMenuActionSelected__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnContextMenuActionSelected_DelegateWrapper(const FMulticastScriptDelegate& OnContextMenuActionSelected, const FString& ActionName)
{
	struct _Script_Echoes_eventOnContextMenuActionSelected_Parms
	{
		FString ActionName;
	};
	_Script_Echoes_eventOnContextMenuActionSelected_Parms Parms;
	Parms.ActionName=ActionName;
	OnContextMenuActionSelected.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnContextMenuActionSelected ********************************************

// ********** Begin ScriptStruct FContextMenuAction ************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FContextMenuAction;
class UScriptStruct* FContextMenuAction::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FContextMenuAction.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FContextMenuAction.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FContextMenuAction, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("ContextMenuAction"));
	}
	return Z_Registration_Info_UScriptStruct_FContextMenuAction.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FContextMenuAction_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Context menu action definition\n */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesContextMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Context menu action definition" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DisplayName_MetaData[] = {
		{ "Category", "ContextMenu" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Display name of the action */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesContextMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Display name of the action" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActionId_MetaData[] = {
		{ "Category", "ContextMenu" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Internal action identifier */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesContextMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Internal action identifier" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnabled_MetaData[] = {
		{ "Category", "ContextMenu" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether this action is currently enabled */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesContextMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether this action is currently enabled" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Tooltip_MetaData[] = {
		{ "Category", "ContextMenu" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Tooltip text */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesContextMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Tooltip text" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FTextPropertyParams NewProp_DisplayName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ActionId;
	static void NewProp_bEnabled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Tooltip;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FContextMenuAction>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FContextMenuAction_Statics::NewProp_DisplayName = { "DisplayName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FContextMenuAction, DisplayName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DisplayName_MetaData), NewProp_DisplayName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FContextMenuAction_Statics::NewProp_ActionId = { "ActionId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FContextMenuAction, ActionId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActionId_MetaData), NewProp_ActionId_MetaData) };
void Z_Construct_UScriptStruct_FContextMenuAction_Statics::NewProp_bEnabled_SetBit(void* Obj)
{
	((FContextMenuAction*)Obj)->bEnabled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FContextMenuAction_Statics::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FContextMenuAction), &Z_Construct_UScriptStruct_FContextMenuAction_Statics::NewProp_bEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnabled_MetaData), NewProp_bEnabled_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FContextMenuAction_Statics::NewProp_Tooltip = { "Tooltip", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FContextMenuAction, Tooltip), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Tooltip_MetaData), NewProp_Tooltip_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FContextMenuAction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FContextMenuAction_Statics::NewProp_DisplayName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FContextMenuAction_Statics::NewProp_ActionId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FContextMenuAction_Statics::NewProp_bEnabled,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FContextMenuAction_Statics::NewProp_Tooltip,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FContextMenuAction_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FContextMenuAction_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"ContextMenuAction",
	Z_Construct_UScriptStruct_FContextMenuAction_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FContextMenuAction_Statics::PropPointers),
	sizeof(FContextMenuAction),
	alignof(FContextMenuAction),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FContextMenuAction_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FContextMenuAction_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FContextMenuAction()
{
	if (!Z_Registration_Info_UScriptStruct_FContextMenuAction.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FContextMenuAction.InnerSingleton, Z_Construct_UScriptStruct_FContextMenuAction_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FContextMenuAction.InnerSingleton;
}
// ********** End ScriptStruct FContextMenuAction **************************************************

// ********** Begin Class UEchoesContextMenuWidget Function CloseMenu ******************************
struct Z_Construct_UFunction_UEchoesContextMenuWidget_CloseMenu_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|ContextMenu" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Close the context menu\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesContextMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Close the context menu" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesContextMenuWidget_CloseMenu_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesContextMenuWidget, nullptr, "CloseMenu", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesContextMenuWidget_CloseMenu_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesContextMenuWidget_CloseMenu_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesContextMenuWidget_CloseMenu()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesContextMenuWidget_CloseMenu_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesContextMenuWidget::execCloseMenu)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CloseMenu();
	P_NATIVE_END;
}
// ********** End Class UEchoesContextMenuWidget Function CloseMenu ********************************

// ********** Begin Class UEchoesContextMenuWidget Function GetItemObject **************************
struct Z_Construct_UFunction_UEchoesContextMenuWidget_GetItemObject_Statics
{
	struct EchoesContextMenuWidget_eventGetItemObject_Parms
	{
		UEchoesInventoryItemObject* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|ContextMenu" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the item this menu is for\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesContextMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the item this menu is for" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEchoesContextMenuWidget_GetItemObject_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesContextMenuWidget_eventGetItemObject_Parms, ReturnValue), Z_Construct_UClass_UEchoesInventoryItemObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesContextMenuWidget_GetItemObject_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesContextMenuWidget_GetItemObject_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesContextMenuWidget_GetItemObject_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesContextMenuWidget_GetItemObject_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesContextMenuWidget, nullptr, "GetItemObject", Z_Construct_UFunction_UEchoesContextMenuWidget_GetItemObject_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesContextMenuWidget_GetItemObject_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesContextMenuWidget_GetItemObject_Statics::EchoesContextMenuWidget_eventGetItemObject_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesContextMenuWidget_GetItemObject_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesContextMenuWidget_GetItemObject_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesContextMenuWidget_GetItemObject_Statics::EchoesContextMenuWidget_eventGetItemObject_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesContextMenuWidget_GetItemObject()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesContextMenuWidget_GetItemObject_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesContextMenuWidget::execGetItemObject)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UEchoesInventoryItemObject**)Z_Param__Result=P_THIS->GetItemObject();
	P_NATIVE_END;
}
// ********** End Class UEchoesContextMenuWidget Function GetItemObject ****************************

// ********** Begin Class UEchoesContextMenuWidget Function GetSourceActor *************************
struct Z_Construct_UFunction_UEchoesContextMenuWidget_GetSourceActor_Statics
{
	struct EchoesContextMenuWidget_eventGetSourceActor_Parms
	{
		AActor* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|ContextMenu" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the source actor\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesContextMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the source actor" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEchoesContextMenuWidget_GetSourceActor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesContextMenuWidget_eventGetSourceActor_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesContextMenuWidget_GetSourceActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesContextMenuWidget_GetSourceActor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesContextMenuWidget_GetSourceActor_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesContextMenuWidget_GetSourceActor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesContextMenuWidget, nullptr, "GetSourceActor", Z_Construct_UFunction_UEchoesContextMenuWidget_GetSourceActor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesContextMenuWidget_GetSourceActor_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesContextMenuWidget_GetSourceActor_Statics::EchoesContextMenuWidget_eventGetSourceActor_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesContextMenuWidget_GetSourceActor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesContextMenuWidget_GetSourceActor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesContextMenuWidget_GetSourceActor_Statics::EchoesContextMenuWidget_eventGetSourceActor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesContextMenuWidget_GetSourceActor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesContextMenuWidget_GetSourceActor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesContextMenuWidget::execGetSourceActor)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AActor**)Z_Param__Result=P_THIS->GetSourceActor();
	P_NATIVE_END;
}
// ********** End Class UEchoesContextMenuWidget Function GetSourceActor ***************************

// ********** Begin Class UEchoesContextMenuWidget Function GetSourceStorageId *********************
struct Z_Construct_UFunction_UEchoesContextMenuWidget_GetSourceStorageId_Statics
{
	struct EchoesContextMenuWidget_eventGetSourceStorageId_Parms
	{
		FGuid ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|ContextMenu" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the source storage ID\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesContextMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the source storage ID" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesContextMenuWidget_GetSourceStorageId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesContextMenuWidget_eventGetSourceStorageId_Parms, ReturnValue), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesContextMenuWidget_GetSourceStorageId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesContextMenuWidget_GetSourceStorageId_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesContextMenuWidget_GetSourceStorageId_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesContextMenuWidget_GetSourceStorageId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesContextMenuWidget, nullptr, "GetSourceStorageId", Z_Construct_UFunction_UEchoesContextMenuWidget_GetSourceStorageId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesContextMenuWidget_GetSourceStorageId_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesContextMenuWidget_GetSourceStorageId_Statics::EchoesContextMenuWidget_eventGetSourceStorageId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesContextMenuWidget_GetSourceStorageId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesContextMenuWidget_GetSourceStorageId_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesContextMenuWidget_GetSourceStorageId_Statics::EchoesContextMenuWidget_eventGetSourceStorageId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesContextMenuWidget_GetSourceStorageId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesContextMenuWidget_GetSourceStorageId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesContextMenuWidget::execGetSourceStorageId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGuid*)Z_Param__Result=P_THIS->GetSourceStorageId();
	P_NATIVE_END;
}
// ********** End Class UEchoesContextMenuWidget Function GetSourceStorageId ***********************

// ********** Begin Class UEchoesContextMenuWidget Function HandleActionButtonClicked **************
struct Z_Construct_UFunction_UEchoesContextMenuWidget_HandleActionButtonClicked_Statics
{
	struct EchoesContextMenuWidget_eventHandleActionButtonClicked_Parms
	{
		FString ActionId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Handle action button clicked\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesContextMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handle action button clicked" },
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
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEchoesContextMenuWidget_HandleActionButtonClicked_Statics::NewProp_ActionId = { "ActionId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesContextMenuWidget_eventHandleActionButtonClicked_Parms, ActionId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActionId_MetaData), NewProp_ActionId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesContextMenuWidget_HandleActionButtonClicked_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesContextMenuWidget_HandleActionButtonClicked_Statics::NewProp_ActionId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesContextMenuWidget_HandleActionButtonClicked_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesContextMenuWidget_HandleActionButtonClicked_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesContextMenuWidget, nullptr, "HandleActionButtonClicked", Z_Construct_UFunction_UEchoesContextMenuWidget_HandleActionButtonClicked_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesContextMenuWidget_HandleActionButtonClicked_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesContextMenuWidget_HandleActionButtonClicked_Statics::EchoesContextMenuWidget_eventHandleActionButtonClicked_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesContextMenuWidget_HandleActionButtonClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesContextMenuWidget_HandleActionButtonClicked_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesContextMenuWidget_HandleActionButtonClicked_Statics::EchoesContextMenuWidget_eventHandleActionButtonClicked_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesContextMenuWidget_HandleActionButtonClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesContextMenuWidget_HandleActionButtonClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesContextMenuWidget::execHandleActionButtonClicked)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ActionId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleActionButtonClicked(Z_Param_ActionId);
	P_NATIVE_END;
}
// ********** End Class UEchoesContextMenuWidget Function HandleActionButtonClicked ****************

// ********** Begin Class UEchoesContextMenuWidget Function InitializeMenu *************************
struct Z_Construct_UFunction_UEchoesContextMenuWidget_InitializeMenu_Statics
{
	struct EchoesContextMenuWidget_eventInitializeMenu_Parms
	{
		UEchoesInventoryItemObject* InItemObject;
		FGuid InSourceStorageId;
		AActor* InSourceActor;
		TArray<FContextMenuAction> InActions;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|ContextMenu" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Initialize context menu with item and actions\n\x09 * @param InItemObject - Item the menu is for\n\x09 * @param InSourceStorageId - Storage ID where item is located\n\x09 * @param InSourceActor - Actor containing the item\n\x09 * @param InActions - Available actions for this item\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesContextMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Initialize context menu with item and actions\n@param InItemObject - Item the menu is for\n@param InSourceStorageId - Storage ID where item is located\n@param InSourceActor - Actor containing the item\n@param InActions - Available actions for this item" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InSourceStorageId_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InActions_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InItemObject;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InSourceStorageId;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InSourceActor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InActions_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_InActions;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEchoesContextMenuWidget_InitializeMenu_Statics::NewProp_InItemObject = { "InItemObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesContextMenuWidget_eventInitializeMenu_Parms, InItemObject), Z_Construct_UClass_UEchoesInventoryItemObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesContextMenuWidget_InitializeMenu_Statics::NewProp_InSourceStorageId = { "InSourceStorageId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesContextMenuWidget_eventInitializeMenu_Parms, InSourceStorageId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InSourceStorageId_MetaData), NewProp_InSourceStorageId_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEchoesContextMenuWidget_InitializeMenu_Statics::NewProp_InSourceActor = { "InSourceActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesContextMenuWidget_eventInitializeMenu_Parms, InSourceActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesContextMenuWidget_InitializeMenu_Statics::NewProp_InActions_Inner = { "InActions", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FContextMenuAction, METADATA_PARAMS(0, nullptr) }; // 2369989439
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UEchoesContextMenuWidget_InitializeMenu_Statics::NewProp_InActions = { "InActions", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesContextMenuWidget_eventInitializeMenu_Parms, InActions), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InActions_MetaData), NewProp_InActions_MetaData) }; // 2369989439
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesContextMenuWidget_InitializeMenu_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesContextMenuWidget_InitializeMenu_Statics::NewProp_InItemObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesContextMenuWidget_InitializeMenu_Statics::NewProp_InSourceStorageId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesContextMenuWidget_InitializeMenu_Statics::NewProp_InSourceActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesContextMenuWidget_InitializeMenu_Statics::NewProp_InActions_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesContextMenuWidget_InitializeMenu_Statics::NewProp_InActions,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesContextMenuWidget_InitializeMenu_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesContextMenuWidget_InitializeMenu_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesContextMenuWidget, nullptr, "InitializeMenu", Z_Construct_UFunction_UEchoesContextMenuWidget_InitializeMenu_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesContextMenuWidget_InitializeMenu_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesContextMenuWidget_InitializeMenu_Statics::EchoesContextMenuWidget_eventInitializeMenu_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesContextMenuWidget_InitializeMenu_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesContextMenuWidget_InitializeMenu_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesContextMenuWidget_InitializeMenu_Statics::EchoesContextMenuWidget_eventInitializeMenu_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesContextMenuWidget_InitializeMenu()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesContextMenuWidget_InitializeMenu_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesContextMenuWidget::execInitializeMenu)
{
	P_GET_OBJECT(UEchoesInventoryItemObject,Z_Param_InItemObject);
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_InSourceStorageId);
	P_GET_OBJECT(AActor,Z_Param_InSourceActor);
	P_GET_TARRAY_REF(FContextMenuAction,Z_Param_Out_InActions);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializeMenu(Z_Param_InItemObject,Z_Param_Out_InSourceStorageId,Z_Param_InSourceActor,Z_Param_Out_InActions);
	P_NATIVE_END;
}
// ********** End Class UEchoesContextMenuWidget Function InitializeMenu ***************************

// ********** Begin Class UEchoesContextMenuWidget Function OnMenuClosed ***************************
static FName NAME_UEchoesContextMenuWidget_OnMenuClosed = FName(TEXT("OnMenuClosed"));
void UEchoesContextMenuWidget::OnMenuClosed()
{
	UFunction* Func = FindFunctionChecked(NAME_UEchoesContextMenuWidget_OnMenuClosed);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_UEchoesContextMenuWidget_OnMenuClosed_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|ContextMenu" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Blueprint event when menu is closed\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesContextMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Blueprint event when menu is closed" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesContextMenuWidget_OnMenuClosed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesContextMenuWidget, nullptr, "OnMenuClosed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesContextMenuWidget_OnMenuClosed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesContextMenuWidget_OnMenuClosed_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesContextMenuWidget_OnMenuClosed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesContextMenuWidget_OnMenuClosed_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UEchoesContextMenuWidget Function OnMenuClosed *****************************

// ********** Begin Class UEchoesContextMenuWidget Function OnMenuInitialized **********************
static FName NAME_UEchoesContextMenuWidget_OnMenuInitialized = FName(TEXT("OnMenuInitialized"));
void UEchoesContextMenuWidget::OnMenuInitialized()
{
	UFunction* Func = FindFunctionChecked(NAME_UEchoesContextMenuWidget_OnMenuInitialized);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_UEchoesContextMenuWidget_OnMenuInitialized_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|ContextMenu" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Blueprint event when menu is initialized\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesContextMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Blueprint event when menu is initialized" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesContextMenuWidget_OnMenuInitialized_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesContextMenuWidget, nullptr, "OnMenuInitialized", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesContextMenuWidget_OnMenuInitialized_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesContextMenuWidget_OnMenuInitialized_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesContextMenuWidget_OnMenuInitialized()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesContextMenuWidget_OnMenuInitialized_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UEchoesContextMenuWidget Function OnMenuInitialized ************************

// ********** Begin Class UEchoesContextMenuWidget Function PositionAtMouse ************************
struct Z_Construct_UFunction_UEchoesContextMenuWidget_PositionAtMouse_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|ContextMenu" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Position the menu at mouse cursor with smart bounds checking\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesContextMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Position the menu at mouse cursor with smart bounds checking" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesContextMenuWidget_PositionAtMouse_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesContextMenuWidget, nullptr, "PositionAtMouse", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesContextMenuWidget_PositionAtMouse_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesContextMenuWidget_PositionAtMouse_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesContextMenuWidget_PositionAtMouse()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesContextMenuWidget_PositionAtMouse_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesContextMenuWidget::execPositionAtMouse)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->PositionAtMouse();
	P_NATIVE_END;
}
// ********** End Class UEchoesContextMenuWidget Function PositionAtMouse **************************

// ********** Begin Class UEchoesContextMenuWidget *************************************************
void UEchoesContextMenuWidget::StaticRegisterNativesUEchoesContextMenuWidget()
{
	UClass* Class = UEchoesContextMenuWidget::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "CloseMenu", &UEchoesContextMenuWidget::execCloseMenu },
		{ "GetItemObject", &UEchoesContextMenuWidget::execGetItemObject },
		{ "GetSourceActor", &UEchoesContextMenuWidget::execGetSourceActor },
		{ "GetSourceStorageId", &UEchoesContextMenuWidget::execGetSourceStorageId },
		{ "HandleActionButtonClicked", &UEchoesContextMenuWidget::execHandleActionButtonClicked },
		{ "InitializeMenu", &UEchoesContextMenuWidget::execInitializeMenu },
		{ "PositionAtMouse", &UEchoesContextMenuWidget::execPositionAtMouse },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UEchoesContextMenuWidget;
UClass* UEchoesContextMenuWidget::GetPrivateStaticClass()
{
	using TClass = UEchoesContextMenuWidget;
	if (!Z_Registration_Info_UClass_UEchoesContextMenuWidget.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesContextMenuWidget"),
			Z_Registration_Info_UClass_UEchoesContextMenuWidget.InnerSingleton,
			StaticRegisterNativesUEchoesContextMenuWidget,
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
	return Z_Registration_Info_UClass_UEchoesContextMenuWidget.InnerSingleton;
}
UClass* Z_Construct_UClass_UEchoesContextMenuWidget_NoRegister()
{
	return UEchoesContextMenuWidget::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UEchoesContextMenuWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * UEchoesContextMenuWidget\n * \n * Dynamic context menu for inventory items\n * Displays available actions based on item type\n * \n * Features:\n * - Dynamic action button generation\n * - Smart positioning (stays within screen bounds)\n * - Auto-closes on focus loss or outside click\n * - Server-validated actions\n * - Singleton-like behavior (one menu at a time)\n * \n * Usage:\n * - Create when right-clicking inventory item\n * - Initialize with item data and available actions\n * - Position at mouse cursor\n * - Handle action callbacks\n */" },
#endif
		{ "IncludePath", "UI/EchoesContextMenuWidget.h" },
		{ "ModuleRelativePath", "UI/EchoesContextMenuWidget.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UEchoesContextMenuWidget\n\nDynamic context menu for inventory items\nDisplays available actions based on item type\n\nFeatures:\n- Dynamic action button generation\n- Smart positioning (stays within screen bounds)\n- Auto-closes on focus loss or outside click\n- Server-validated actions\n- Singleton-like behavior (one menu at a time)\n\nUsage:\n- Create when right-clicking inventory item\n- Initialize with item data and available actions\n- Position at mouse cursor\n- Handle action callbacks" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnActionSelected_MetaData[] = {
		{ "Category", "Echoes|ContextMenu" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Delegate called when an action is selected\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesContextMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Delegate called when an action is selected" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActionsContainer_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Echoes|ContextMenu" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Container for action buttons */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/EchoesContextMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Container for action buttons" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TitleText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Echoes|ContextMenu" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Title text showing item name */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/EchoesContextMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Title text showing item name" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActionButtonClass_MetaData[] = {
		{ "Category", "Echoes|ContextMenu" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Button class to use for actions */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesContextMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Button class to use for actions" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ButtonSpacing_MetaData[] = {
		{ "Category", "Echoes|ContextMenu" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Margin between action buttons */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesContextMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Margin between action buttons" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemObject_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Item object this menu is for */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesContextMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Item object this menu is for" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SourceStorageId_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Source storage ID */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesContextMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Source storage ID" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SourceActor_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Source actor containing the item */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesContextMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Source actor containing the item" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Actions_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Available actions */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesContextMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Available actions" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnActionSelected;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ActionsContainer;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TitleText;
	static const UECodeGen_Private::FClassPropertyParams NewProp_ActionButtonClass;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ButtonSpacing;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemObject;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SourceStorageId;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SourceActor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Actions_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Actions;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UEchoesContextMenuWidget_CloseMenu, "CloseMenu" }, // 3921183156
		{ &Z_Construct_UFunction_UEchoesContextMenuWidget_GetItemObject, "GetItemObject" }, // 2378664621
		{ &Z_Construct_UFunction_UEchoesContextMenuWidget_GetSourceActor, "GetSourceActor" }, // 2140620926
		{ &Z_Construct_UFunction_UEchoesContextMenuWidget_GetSourceStorageId, "GetSourceStorageId" }, // 3072815231
		{ &Z_Construct_UFunction_UEchoesContextMenuWidget_HandleActionButtonClicked, "HandleActionButtonClicked" }, // 2125682825
		{ &Z_Construct_UFunction_UEchoesContextMenuWidget_InitializeMenu, "InitializeMenu" }, // 3270031374
		{ &Z_Construct_UFunction_UEchoesContextMenuWidget_OnMenuClosed, "OnMenuClosed" }, // 1339726811
		{ &Z_Construct_UFunction_UEchoesContextMenuWidget_OnMenuInitialized, "OnMenuInitialized" }, // 2649430440
		{ &Z_Construct_UFunction_UEchoesContextMenuWidget_PositionAtMouse, "PositionAtMouse" }, // 4167901612
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEchoesContextMenuWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEchoesContextMenuWidget_Statics::NewProp_OnActionSelected = { "OnActionSelected", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesContextMenuWidget, OnActionSelected), Z_Construct_UDelegateFunction_Echoes_OnContextMenuActionSelected__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnActionSelected_MetaData), NewProp_OnActionSelected_MetaData) }; // 1284405335
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesContextMenuWidget_Statics::NewProp_ActionsContainer = { "ActionsContainer", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesContextMenuWidget, ActionsContainer), Z_Construct_UClass_UVerticalBox_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActionsContainer_MetaData), NewProp_ActionsContainer_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesContextMenuWidget_Statics::NewProp_TitleText = { "TitleText", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesContextMenuWidget, TitleText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TitleText_MetaData), NewProp_TitleText_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UEchoesContextMenuWidget_Statics::NewProp_ActionButtonClass = { "ActionButtonClass", nullptr, (EPropertyFlags)0x0024080000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesContextMenuWidget, ActionButtonClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActionButtonClass_MetaData), NewProp_ActionButtonClass_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEchoesContextMenuWidget_Statics::NewProp_ButtonSpacing = { "ButtonSpacing", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesContextMenuWidget, ButtonSpacing), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ButtonSpacing_MetaData), NewProp_ButtonSpacing_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesContextMenuWidget_Statics::NewProp_ItemObject = { "ItemObject", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesContextMenuWidget, ItemObject), Z_Construct_UClass_UEchoesInventoryItemObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemObject_MetaData), NewProp_ItemObject_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEchoesContextMenuWidget_Statics::NewProp_SourceStorageId = { "SourceStorageId", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesContextMenuWidget, SourceStorageId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SourceStorageId_MetaData), NewProp_SourceStorageId_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesContextMenuWidget_Statics::NewProp_SourceActor = { "SourceActor", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesContextMenuWidget, SourceActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SourceActor_MetaData), NewProp_SourceActor_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEchoesContextMenuWidget_Statics::NewProp_Actions_Inner = { "Actions", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FContextMenuAction, METADATA_PARAMS(0, nullptr) }; // 2369989439
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UEchoesContextMenuWidget_Statics::NewProp_Actions = { "Actions", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesContextMenuWidget, Actions), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Actions_MetaData), NewProp_Actions_MetaData) }; // 2369989439
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEchoesContextMenuWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesContextMenuWidget_Statics::NewProp_OnActionSelected,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesContextMenuWidget_Statics::NewProp_ActionsContainer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesContextMenuWidget_Statics::NewProp_TitleText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesContextMenuWidget_Statics::NewProp_ActionButtonClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesContextMenuWidget_Statics::NewProp_ButtonSpacing,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesContextMenuWidget_Statics::NewProp_ItemObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesContextMenuWidget_Statics::NewProp_SourceStorageId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesContextMenuWidget_Statics::NewProp_SourceActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesContextMenuWidget_Statics::NewProp_Actions_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesContextMenuWidget_Statics::NewProp_Actions,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesContextMenuWidget_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UEchoesContextMenuWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesContextMenuWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEchoesContextMenuWidget_Statics::ClassParams = {
	&UEchoesContextMenuWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UEchoesContextMenuWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesContextMenuWidget_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesContextMenuWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UEchoesContextMenuWidget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEchoesContextMenuWidget()
{
	if (!Z_Registration_Info_UClass_UEchoesContextMenuWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEchoesContextMenuWidget.OuterSingleton, Z_Construct_UClass_UEchoesContextMenuWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEchoesContextMenuWidget.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UEchoesContextMenuWidget);
UEchoesContextMenuWidget::~UEchoesContextMenuWidget() {}
// ********** End Class UEchoesContextMenuWidget ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesContextMenuWidget_h__Script_Echoes_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FContextMenuAction::StaticStruct, Z_Construct_UScriptStruct_FContextMenuAction_Statics::NewStructOps, TEXT("ContextMenuAction"), &Z_Registration_Info_UScriptStruct_FContextMenuAction, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FContextMenuAction), 2369989439U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEchoesContextMenuActionButton, UEchoesContextMenuActionButton::StaticClass, TEXT("UEchoesContextMenuActionButton"), &Z_Registration_Info_UClass_UEchoesContextMenuActionButton, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEchoesContextMenuActionButton), 1119669276U) },
		{ Z_Construct_UClass_UEchoesContextMenuWidget, UEchoesContextMenuWidget::StaticClass, TEXT("UEchoesContextMenuWidget"), &Z_Registration_Info_UClass_UEchoesContextMenuWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEchoesContextMenuWidget), 2273259366U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesContextMenuWidget_h__Script_Echoes_1088118868(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesContextMenuWidget_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesContextMenuWidget_h__Script_Echoes_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesContextMenuWidget_h__Script_Echoes_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesContextMenuWidget_h__Script_Echoes_Statics::ScriptStructInfo),
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
