// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Echoes/UI/EchoesCharacterSelectWidget.h"
#include "Echoes/Core/Common/Networking/EchoesAuthSubsystem.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesCharacterSelectWidget() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ECHOES_API UClass* Z_Construct_UClass_UCharacterListItem();
ECHOES_API UClass* Z_Construct_UClass_UCharacterListItem_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UEchoesAuthSubsystem_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UEchoesCharacterSelectWidget();
ECHOES_API UClass* Z_Construct_UClass_UEchoesCharacterSelectWidget_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UEchoesWindowBase();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FCharacterInfo();
SLATECORE_API UEnum* Z_Construct_UEnum_SlateCore_ESelectInfo();
UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
UMG_API UClass* Z_Construct_UClass_UComboBoxString_NoRegister();
UMG_API UClass* Z_Construct_UClass_UEditableTextBox_NoRegister();
UMG_API UClass* Z_Construct_UClass_UListView_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UCharacterListItem *******************************************************
void UCharacterListItem::StaticRegisterNativesUCharacterListItem()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UCharacterListItem;
UClass* UCharacterListItem::GetPrivateStaticClass()
{
	using TClass = UCharacterListItem;
	if (!Z_Registration_Info_UClass_UCharacterListItem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("CharacterListItem"),
			Z_Registration_Info_UClass_UCharacterListItem.InnerSingleton,
			StaticRegisterNativesUCharacterListItem,
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
	return Z_Registration_Info_UClass_UCharacterListItem.InnerSingleton;
}
UClass* Z_Construct_UClass_UCharacterListItem_NoRegister()
{
	return UCharacterListItem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UCharacterListItem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Character list item data\n */" },
#endif
		{ "IncludePath", "UI/EchoesCharacterSelectWidget.h" },
		{ "ModuleRelativePath", "UI/EchoesCharacterSelectWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Character list item data" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterInfo_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "UI/EchoesCharacterSelectWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RaceName_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "UI/EchoesCharacterSelectWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_CharacterInfo;
	static const UECodeGen_Private::FStrPropertyParams NewProp_RaceName;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCharacterListItem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCharacterListItem_Statics::NewProp_CharacterInfo = { "CharacterInfo", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCharacterListItem, CharacterInfo), Z_Construct_UScriptStruct_FCharacterInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterInfo_MetaData), NewProp_CharacterInfo_MetaData) }; // 2611301823
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UCharacterListItem_Statics::NewProp_RaceName = { "RaceName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCharacterListItem, RaceName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RaceName_MetaData), NewProp_RaceName_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCharacterListItem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCharacterListItem_Statics::NewProp_CharacterInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCharacterListItem_Statics::NewProp_RaceName,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCharacterListItem_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UCharacterListItem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCharacterListItem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCharacterListItem_Statics::ClassParams = {
	&UCharacterListItem::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UCharacterListItem_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UCharacterListItem_Statics::PropPointers),
	0,
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCharacterListItem_Statics::Class_MetaDataParams), Z_Construct_UClass_UCharacterListItem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCharacterListItem()
{
	if (!Z_Registration_Info_UClass_UCharacterListItem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCharacterListItem.OuterSingleton, Z_Construct_UClass_UCharacterListItem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCharacterListItem.OuterSingleton;
}
UCharacterListItem::UCharacterListItem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCharacterListItem);
UCharacterListItem::~UCharacterListItem() {}
// ********** End Class UCharacterListItem *********************************************************

// ********** Begin Class UEchoesCharacterSelectWidget Function OnCancelCreateButtonClicked ********
struct Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCancelCreateButtonClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI/EchoesCharacterSelectWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCancelCreateButtonClicked_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesCharacterSelectWidget, nullptr, "OnCancelCreateButtonClicked", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCancelCreateButtonClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCancelCreateButtonClicked_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCancelCreateButtonClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCancelCreateButtonClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesCharacterSelectWidget::execOnCancelCreateButtonClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnCancelCreateButtonClicked();
	P_NATIVE_END;
}
// ********** End Class UEchoesCharacterSelectWidget Function OnCancelCreateButtonClicked **********

// ********** Begin Class UEchoesCharacterSelectWidget Function OnCharacterSelected ****************
struct Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCharacterSelected_Statics
{
	struct EchoesCharacterSelectWidget_eventOnCharacterSelected_Parms
	{
		FGuid CharacterId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Character" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Called when a character is selected */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesCharacterSelectWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when a character is selected" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_CharacterId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCharacterSelected_Statics::NewProp_CharacterId = { "CharacterId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesCharacterSelectWidget_eventOnCharacterSelected_Parms, CharacterId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCharacterSelected_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCharacterSelected_Statics::NewProp_CharacterId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCharacterSelected_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCharacterSelected_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesCharacterSelectWidget, nullptr, "OnCharacterSelected", Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCharacterSelected_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCharacterSelected_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCharacterSelected_Statics::EchoesCharacterSelectWidget_eventOnCharacterSelected_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCharacterSelected_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCharacterSelected_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCharacterSelected_Statics::EchoesCharacterSelectWidget_eventOnCharacterSelected_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCharacterSelected()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCharacterSelected_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesCharacterSelectWidget::execOnCharacterSelected)
{
	P_GET_STRUCT(FGuid,Z_Param_CharacterId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnCharacterSelected(Z_Param_CharacterId);
	P_NATIVE_END;
}
// ********** End Class UEchoesCharacterSelectWidget Function OnCharacterSelected ******************

// ********** Begin Class UEchoesCharacterSelectWidget Function OnConfirmCreateButtonClicked *******
struct Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnConfirmCreateButtonClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI/EchoesCharacterSelectWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnConfirmCreateButtonClicked_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesCharacterSelectWidget, nullptr, "OnConfirmCreateButtonClicked", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnConfirmCreateButtonClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnConfirmCreateButtonClicked_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnConfirmCreateButtonClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnConfirmCreateButtonClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesCharacterSelectWidget::execOnConfirmCreateButtonClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnConfirmCreateButtonClicked();
	P_NATIVE_END;
}
// ********** End Class UEchoesCharacterSelectWidget Function OnConfirmCreateButtonClicked *********

// ********** Begin Class UEchoesCharacterSelectWidget Function OnCreateButtonClicked **************
struct Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCreateButtonClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI/EchoesCharacterSelectWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCreateButtonClicked_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesCharacterSelectWidget, nullptr, "OnCreateButtonClicked", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCreateButtonClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCreateButtonClicked_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCreateButtonClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCreateButtonClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesCharacterSelectWidget::execOnCreateButtonClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnCreateButtonClicked();
	P_NATIVE_END;
}
// ********** End Class UEchoesCharacterSelectWidget Function OnCreateButtonClicked ****************

// ********** Begin Class UEchoesCharacterSelectWidget Function OnDeleteButtonClicked **************
struct Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnDeleteButtonClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI/EchoesCharacterSelectWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnDeleteButtonClicked_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesCharacterSelectWidget, nullptr, "OnDeleteButtonClicked", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnDeleteButtonClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnDeleteButtonClicked_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnDeleteButtonClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnDeleteButtonClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesCharacterSelectWidget::execOnDeleteButtonClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnDeleteButtonClicked();
	P_NATIVE_END;
}
// ********** End Class UEchoesCharacterSelectWidget Function OnDeleteButtonClicked ****************

// ********** Begin Class UEchoesCharacterSelectWidget Function OnLogoutButtonClicked **************
struct Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnLogoutButtonClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI/EchoesCharacterSelectWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnLogoutButtonClicked_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesCharacterSelectWidget, nullptr, "OnLogoutButtonClicked", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnLogoutButtonClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnLogoutButtonClicked_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnLogoutButtonClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnLogoutButtonClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesCharacterSelectWidget::execOnLogoutButtonClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnLogoutButtonClicked();
	P_NATIVE_END;
}
// ********** End Class UEchoesCharacterSelectWidget Function OnLogoutButtonClicked ****************

// ********** Begin Class UEchoesCharacterSelectWidget Function OnRaceSelectionChanged *************
struct Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnRaceSelectionChanged_Statics
{
	struct EchoesCharacterSelectWidget_eventOnRaceSelectionChanged_Parms
	{
		FString SelectedItem;
		TEnumAsByte<ESelectInfo::Type> SelectionType;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI/EchoesCharacterSelectWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_SelectedItem;
	static const UECodeGen_Private::FBytePropertyParams NewProp_SelectionType;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnRaceSelectionChanged_Statics::NewProp_SelectedItem = { "SelectedItem", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesCharacterSelectWidget_eventOnRaceSelectionChanged_Parms, SelectedItem), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnRaceSelectionChanged_Statics::NewProp_SelectionType = { "SelectionType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesCharacterSelectWidget_eventOnRaceSelectionChanged_Parms, SelectionType), Z_Construct_UEnum_SlateCore_ESelectInfo, METADATA_PARAMS(0, nullptr) }; // 4040429206
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnRaceSelectionChanged_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnRaceSelectionChanged_Statics::NewProp_SelectedItem,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnRaceSelectionChanged_Statics::NewProp_SelectionType,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnRaceSelectionChanged_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnRaceSelectionChanged_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesCharacterSelectWidget, nullptr, "OnRaceSelectionChanged", Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnRaceSelectionChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnRaceSelectionChanged_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnRaceSelectionChanged_Statics::EchoesCharacterSelectWidget_eventOnRaceSelectionChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnRaceSelectionChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnRaceSelectionChanged_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnRaceSelectionChanged_Statics::EchoesCharacterSelectWidget_eventOnRaceSelectionChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnRaceSelectionChanged()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnRaceSelectionChanged_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesCharacterSelectWidget::execOnRaceSelectionChanged)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_SelectedItem);
	P_GET_PROPERTY(FByteProperty,Z_Param_SelectionType);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRaceSelectionChanged(Z_Param_SelectedItem,ESelectInfo::Type(Z_Param_SelectionType));
	P_NATIVE_END;
}
// ********** End Class UEchoesCharacterSelectWidget Function OnRaceSelectionChanged ***************

// ********** Begin Class UEchoesCharacterSelectWidget Function OnSelectButtonClicked **************
struct Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnSelectButtonClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ==================== Button Handlers ====================\n" },
#endif
		{ "ModuleRelativePath", "UI/EchoesCharacterSelectWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "==================== Button Handlers ====================" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnSelectButtonClicked_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesCharacterSelectWidget, nullptr, "OnSelectButtonClicked", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnSelectButtonClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnSelectButtonClicked_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnSelectButtonClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnSelectButtonClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesCharacterSelectWidget::execOnSelectButtonClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnSelectButtonClicked();
	P_NATIVE_END;
}
// ********** End Class UEchoesCharacterSelectWidget Function OnSelectButtonClicked ****************

// ********** Begin Class UEchoesCharacterSelectWidget *********************************************
void UEchoesCharacterSelectWidget::StaticRegisterNativesUEchoesCharacterSelectWidget()
{
	UClass* Class = UEchoesCharacterSelectWidget::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnCancelCreateButtonClicked", &UEchoesCharacterSelectWidget::execOnCancelCreateButtonClicked },
		{ "OnCharacterSelected", &UEchoesCharacterSelectWidget::execOnCharacterSelected },
		{ "OnConfirmCreateButtonClicked", &UEchoesCharacterSelectWidget::execOnConfirmCreateButtonClicked },
		{ "OnCreateButtonClicked", &UEchoesCharacterSelectWidget::execOnCreateButtonClicked },
		{ "OnDeleteButtonClicked", &UEchoesCharacterSelectWidget::execOnDeleteButtonClicked },
		{ "OnLogoutButtonClicked", &UEchoesCharacterSelectWidget::execOnLogoutButtonClicked },
		{ "OnRaceSelectionChanged", &UEchoesCharacterSelectWidget::execOnRaceSelectionChanged },
		{ "OnSelectButtonClicked", &UEchoesCharacterSelectWidget::execOnSelectButtonClicked },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UEchoesCharacterSelectWidget;
UClass* UEchoesCharacterSelectWidget::GetPrivateStaticClass()
{
	using TClass = UEchoesCharacterSelectWidget;
	if (!Z_Registration_Info_UClass_UEchoesCharacterSelectWidget.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesCharacterSelectWidget"),
			Z_Registration_Info_UClass_UEchoesCharacterSelectWidget.InnerSingleton,
			StaticRegisterNativesUEchoesCharacterSelectWidget,
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
	return Z_Registration_Info_UClass_UEchoesCharacterSelectWidget.InnerSingleton;
}
UClass* Z_Construct_UClass_UEchoesCharacterSelectWidget_NoRegister()
{
	return UEchoesCharacterSelectWidget::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * UEchoesCharacterSelectWidget\n * \n * Character selection UI widget for Echoes MMO\n * Displays list of player's characters and allows creation of new characters\n * Inherits from UEchoesWindowBase for drag/focus support\n */" },
#endif
		{ "IncludePath", "UI/EchoesCharacterSelectWidget.h" },
		{ "ModuleRelativePath", "UI/EchoesCharacterSelectWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UEchoesCharacterSelectWidget\n\nCharacter selection UI widget for Echoes MMO\nDisplays list of player's characters and allows creation of new characters\nInherits from UEchoesWindowBase for drag/focus support" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterList_MetaData[] = {
		{ "BindWidget", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** List view for characters */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/EchoesCharacterSelectWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "List view for characters" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectButton_MetaData[] = {
		{ "BindWidget", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Select character button */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/EchoesCharacterSelectWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Select character button" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CreateButton_MetaData[] = {
		{ "BindWidget", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Create new character button */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/EchoesCharacterSelectWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Create new character button" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DeleteButton_MetaData[] = {
		{ "BindWidget", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Delete character button */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/EchoesCharacterSelectWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Delete character button" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LogoutButton_MetaData[] = {
		{ "BindWidget", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Logout button */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/EchoesCharacterSelectWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Logout button" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StatusText_MetaData[] = {
		{ "BindWidget", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Status text */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/EchoesCharacterSelectWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Status text" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterNameInput_MetaData[] = {
		{ "BindWidget", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Character creation panel widgets\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/EchoesCharacterSelectWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Character creation panel widgets" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RaceComboBox_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/EchoesCharacterSelectWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RaceDescriptionText_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/EchoesCharacterSelectWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RaceBonusesText_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/EchoesCharacterSelectWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ConfirmCreateButton_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/EchoesCharacterSelectWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CancelCreateButton_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/EchoesCharacterSelectWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AuthSubsystem_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Reference to auth subsystem */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesCharacterSelectWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Reference to auth subsystem" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectedCharacter_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Currently selected character */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesCharacterSelectWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Currently selected character" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CharacterList;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SelectButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CreateButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DeleteButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LogoutButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StatusText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CharacterNameInput;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RaceComboBox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RaceDescriptionText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RaceBonusesText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ConfirmCreateButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CancelCreateButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AuthSubsystem;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SelectedCharacter;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCancelCreateButtonClicked, "OnCancelCreateButtonClicked" }, // 1584637404
		{ &Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCharacterSelected, "OnCharacterSelected" }, // 2307171806
		{ &Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnConfirmCreateButtonClicked, "OnConfirmCreateButtonClicked" }, // 1811059387
		{ &Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCreateButtonClicked, "OnCreateButtonClicked" }, // 1082346214
		{ &Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnDeleteButtonClicked, "OnDeleteButtonClicked" }, // 2683603242
		{ &Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnLogoutButtonClicked, "OnLogoutButtonClicked" }, // 257671726
		{ &Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnRaceSelectionChanged, "OnRaceSelectionChanged" }, // 1597709346
		{ &Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnSelectButtonClicked, "OnSelectButtonClicked" }, // 3965066683
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEchoesCharacterSelectWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::NewProp_CharacterList = { "CharacterList", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesCharacterSelectWidget, CharacterList), Z_Construct_UClass_UListView_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterList_MetaData), NewProp_CharacterList_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::NewProp_SelectButton = { "SelectButton", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesCharacterSelectWidget, SelectButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectButton_MetaData), NewProp_SelectButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::NewProp_CreateButton = { "CreateButton", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesCharacterSelectWidget, CreateButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CreateButton_MetaData), NewProp_CreateButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::NewProp_DeleteButton = { "DeleteButton", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesCharacterSelectWidget, DeleteButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DeleteButton_MetaData), NewProp_DeleteButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::NewProp_LogoutButton = { "LogoutButton", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesCharacterSelectWidget, LogoutButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LogoutButton_MetaData), NewProp_LogoutButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::NewProp_StatusText = { "StatusText", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesCharacterSelectWidget, StatusText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StatusText_MetaData), NewProp_StatusText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::NewProp_CharacterNameInput = { "CharacterNameInput", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesCharacterSelectWidget, CharacterNameInput), Z_Construct_UClass_UEditableTextBox_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterNameInput_MetaData), NewProp_CharacterNameInput_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::NewProp_RaceComboBox = { "RaceComboBox", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesCharacterSelectWidget, RaceComboBox), Z_Construct_UClass_UComboBoxString_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RaceComboBox_MetaData), NewProp_RaceComboBox_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::NewProp_RaceDescriptionText = { "RaceDescriptionText", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesCharacterSelectWidget, RaceDescriptionText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RaceDescriptionText_MetaData), NewProp_RaceDescriptionText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::NewProp_RaceBonusesText = { "RaceBonusesText", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesCharacterSelectWidget, RaceBonusesText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RaceBonusesText_MetaData), NewProp_RaceBonusesText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::NewProp_ConfirmCreateButton = { "ConfirmCreateButton", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesCharacterSelectWidget, ConfirmCreateButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ConfirmCreateButton_MetaData), NewProp_ConfirmCreateButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::NewProp_CancelCreateButton = { "CancelCreateButton", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesCharacterSelectWidget, CancelCreateButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CancelCreateButton_MetaData), NewProp_CancelCreateButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::NewProp_AuthSubsystem = { "AuthSubsystem", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesCharacterSelectWidget, AuthSubsystem), Z_Construct_UClass_UEchoesAuthSubsystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AuthSubsystem_MetaData), NewProp_AuthSubsystem_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::NewProp_SelectedCharacter = { "SelectedCharacter", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesCharacterSelectWidget, SelectedCharacter), Z_Construct_UClass_UCharacterListItem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectedCharacter_MetaData), NewProp_SelectedCharacter_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::NewProp_CharacterList,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::NewProp_SelectButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::NewProp_CreateButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::NewProp_DeleteButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::NewProp_LogoutButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::NewProp_StatusText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::NewProp_CharacterNameInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::NewProp_RaceComboBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::NewProp_RaceDescriptionText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::NewProp_RaceBonusesText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::NewProp_ConfirmCreateButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::NewProp_CancelCreateButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::NewProp_AuthSubsystem,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::NewProp_SelectedCharacter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UEchoesWindowBase,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::ClassParams = {
	&UEchoesCharacterSelectWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEchoesCharacterSelectWidget()
{
	if (!Z_Registration_Info_UClass_UEchoesCharacterSelectWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEchoesCharacterSelectWidget.OuterSingleton, Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEchoesCharacterSelectWidget.OuterSingleton;
}
UEchoesCharacterSelectWidget::UEchoesCharacterSelectWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UEchoesCharacterSelectWidget);
UEchoesCharacterSelectWidget::~UEchoesCharacterSelectWidget() {}
// ********** End Class UEchoesCharacterSelectWidget ***********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesCharacterSelectWidget_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCharacterListItem, UCharacterListItem::StaticClass, TEXT("UCharacterListItem"), &Z_Registration_Info_UClass_UCharacterListItem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCharacterListItem), 174844967U) },
		{ Z_Construct_UClass_UEchoesCharacterSelectWidget, UEchoesCharacterSelectWidget::StaticClass, TEXT("UEchoesCharacterSelectWidget"), &Z_Registration_Info_UClass_UEchoesCharacterSelectWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEchoesCharacterSelectWidget), 3266696874U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesCharacterSelectWidget_h__Script_Echoes_3705254717(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesCharacterSelectWidget_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesCharacterSelectWidget_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
