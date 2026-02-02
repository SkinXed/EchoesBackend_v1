// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EchoesCharacterSelectWidget.h"
#include "EchoesAuthSubsystem.h"
#include "EchoesCharacterData.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesCharacterSelectWidget() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ECHOES_API UClass* Z_Construct_UClass_UCharacterListItem();
ECHOES_API UClass* Z_Construct_UClass_UCharacterListItem_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UEchoesAuthSubsystem_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UEchoesCharacterSelectWidget();
ECHOES_API UClass* Z_Construct_UClass_UEchoesCharacterSelectWidget_NoRegister();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FCharacterData();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FCharacterInfo();
SLATECORE_API UEnum* Z_Construct_UEnum_SlateCore_ESelectInfo();
UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
UMG_API UClass* Z_Construct_UClass_UComboBoxString_NoRegister();
UMG_API UClass* Z_Construct_UClass_UEditableTextBox_NoRegister();
UMG_API UClass* Z_Construct_UClass_UListView_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UMG_API UClass* Z_Construct_UClass_UWidget_NoRegister();
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
		{ "IncludePath", "UI/Widgets/EchoesCharacterSelectWidget.h" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesCharacterSelectWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Character list item data" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterInfo_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesCharacterSelectWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RaceName_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesCharacterSelectWidget.h" },
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
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCharacterListItem_Statics::NewProp_CharacterInfo = { "CharacterInfo", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCharacterListItem, CharacterInfo), Z_Construct_UScriptStruct_FCharacterInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterInfo_MetaData), NewProp_CharacterInfo_MetaData) }; // 2252549621
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

// ********** Begin Class UEchoesCharacterSelectWidget Function HandleCharacterCreated *************
struct Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterCreated_Statics
{
	struct EchoesCharacterSelectWidget_eventHandleCharacterCreated_Parms
	{
		FCharacterData CharacterData;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI/Widgets/EchoesCharacterSelectWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_CharacterData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterCreated_Statics::NewProp_CharacterData = { "CharacterData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesCharacterSelectWidget_eventHandleCharacterCreated_Parms, CharacterData), Z_Construct_UScriptStruct_FCharacterData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterData_MetaData), NewProp_CharacterData_MetaData) }; // 1874857763
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterCreated_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterCreated_Statics::NewProp_CharacterData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterCreated_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterCreated_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesCharacterSelectWidget, nullptr, "HandleCharacterCreated", Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterCreated_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterCreated_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterCreated_Statics::EchoesCharacterSelectWidget_eventHandleCharacterCreated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00440401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterCreated_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterCreated_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterCreated_Statics::EchoesCharacterSelectWidget_eventHandleCharacterCreated_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterCreated()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterCreated_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesCharacterSelectWidget::execHandleCharacterCreated)
{
	P_GET_STRUCT_REF(FCharacterData,Z_Param_Out_CharacterData);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleCharacterCreated(Z_Param_Out_CharacterData);
	P_NATIVE_END;
}
// ********** End Class UEchoesCharacterSelectWidget Function HandleCharacterCreated ***************

// ********** Begin Class UEchoesCharacterSelectWidget Function HandleCharacterCreationFailed ******
struct Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterCreationFailed_Statics
{
	struct EchoesCharacterSelectWidget_eventHandleCharacterCreationFailed_Parms
	{
		FString ErrorMessage;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI/Widgets/EchoesCharacterSelectWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterCreationFailed_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesCharacterSelectWidget_eventHandleCharacterCreationFailed_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ErrorMessage_MetaData), NewProp_ErrorMessage_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterCreationFailed_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterCreationFailed_Statics::NewProp_ErrorMessage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterCreationFailed_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterCreationFailed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesCharacterSelectWidget, nullptr, "HandleCharacterCreationFailed", Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterCreationFailed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterCreationFailed_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterCreationFailed_Statics::EchoesCharacterSelectWidget_eventHandleCharacterCreationFailed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterCreationFailed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterCreationFailed_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterCreationFailed_Statics::EchoesCharacterSelectWidget_eventHandleCharacterCreationFailed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterCreationFailed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterCreationFailed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesCharacterSelectWidget::execHandleCharacterCreationFailed)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ErrorMessage);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleCharacterCreationFailed(Z_Param_ErrorMessage);
	P_NATIVE_END;
}
// ********** End Class UEchoesCharacterSelectWidget Function HandleCharacterCreationFailed ********

// ********** Begin Class UEchoesCharacterSelectWidget Function HandleCharacterDeleted *************
struct Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterDeleted_Statics
{
	struct EchoesCharacterSelectWidget_eventHandleCharacterDeleted_Parms
	{
		FGuid CharacterId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI/Widgets/EchoesCharacterSelectWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_CharacterId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterDeleted_Statics::NewProp_CharacterId = { "CharacterId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesCharacterSelectWidget_eventHandleCharacterDeleted_Parms, CharacterId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterId_MetaData), NewProp_CharacterId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterDeleted_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterDeleted_Statics::NewProp_CharacterId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterDeleted_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterDeleted_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesCharacterSelectWidget, nullptr, "HandleCharacterDeleted", Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterDeleted_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterDeleted_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterDeleted_Statics::EchoesCharacterSelectWidget_eventHandleCharacterDeleted_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C40401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterDeleted_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterDeleted_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterDeleted_Statics::EchoesCharacterSelectWidget_eventHandleCharacterDeleted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterDeleted()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterDeleted_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesCharacterSelectWidget::execHandleCharacterDeleted)
{
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_CharacterId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleCharacterDeleted(Z_Param_Out_CharacterId);
	P_NATIVE_END;
}
// ********** End Class UEchoesCharacterSelectWidget Function HandleCharacterDeleted ***************

// ********** Begin Class UEchoesCharacterSelectWidget Function HandleCharacterDeletionFailed ******
struct Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterDeletionFailed_Statics
{
	struct EchoesCharacterSelectWidget_eventHandleCharacterDeletionFailed_Parms
	{
		FString ErrorMessage;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI/Widgets/EchoesCharacterSelectWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterDeletionFailed_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesCharacterSelectWidget_eventHandleCharacterDeletionFailed_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ErrorMessage_MetaData), NewProp_ErrorMessage_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterDeletionFailed_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterDeletionFailed_Statics::NewProp_ErrorMessage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterDeletionFailed_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterDeletionFailed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesCharacterSelectWidget, nullptr, "HandleCharacterDeletionFailed", Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterDeletionFailed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterDeletionFailed_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterDeletionFailed_Statics::EchoesCharacterSelectWidget_eventHandleCharacterDeletionFailed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterDeletionFailed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterDeletionFailed_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterDeletionFailed_Statics::EchoesCharacterSelectWidget_eventHandleCharacterDeletionFailed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterDeletionFailed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterDeletionFailed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesCharacterSelectWidget::execHandleCharacterDeletionFailed)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ErrorMessage);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleCharacterDeletionFailed(Z_Param_ErrorMessage);
	P_NATIVE_END;
}
// ********** End Class UEchoesCharacterSelectWidget Function HandleCharacterDeletionFailed ********

// ********** Begin Class UEchoesCharacterSelectWidget Function HandleCharacterListUpdated *********
struct Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterListUpdated_Statics
{
	struct EchoesCharacterSelectWidget_eventHandleCharacterListUpdated_Parms
	{
		TArray<FCharacterInfo> Characters;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI/Widgets/EchoesCharacterSelectWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Characters_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Characters_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Characters;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterListUpdated_Statics::NewProp_Characters_Inner = { "Characters", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FCharacterInfo, METADATA_PARAMS(0, nullptr) }; // 2252549621
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterListUpdated_Statics::NewProp_Characters = { "Characters", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesCharacterSelectWidget_eventHandleCharacterListUpdated_Parms, Characters), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Characters_MetaData), NewProp_Characters_MetaData) }; // 2252549621
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterListUpdated_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterListUpdated_Statics::NewProp_Characters_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterListUpdated_Statics::NewProp_Characters,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterListUpdated_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterListUpdated_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesCharacterSelectWidget, nullptr, "HandleCharacterListUpdated", Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterListUpdated_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterListUpdated_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterListUpdated_Statics::EchoesCharacterSelectWidget_eventHandleCharacterListUpdated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00440401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterListUpdated_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterListUpdated_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterListUpdated_Statics::EchoesCharacterSelectWidget_eventHandleCharacterListUpdated_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterListUpdated()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterListUpdated_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesCharacterSelectWidget::execHandleCharacterListUpdated)
{
	P_GET_TARRAY_REF(FCharacterInfo,Z_Param_Out_Characters);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleCharacterListUpdated(Z_Param_Out_Characters);
	P_NATIVE_END;
}
// ********** End Class UEchoesCharacterSelectWidget Function HandleCharacterListUpdated ***********

// ********** Begin Class UEchoesCharacterSelectWidget Function LaunchCharacter ********************
struct Z_Construct_UFunction_UEchoesCharacterSelectWidget_LaunchCharacter_Statics
{
	struct EchoesCharacterSelectWidget_eventLaunchCharacter_Parms
	{
		FGuid CharacterId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Character" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesCharacterSelectWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_CharacterId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesCharacterSelectWidget_LaunchCharacter_Statics::NewProp_CharacterId = { "CharacterId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesCharacterSelectWidget_eventLaunchCharacter_Parms, CharacterId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesCharacterSelectWidget_LaunchCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesCharacterSelectWidget_LaunchCharacter_Statics::NewProp_CharacterId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesCharacterSelectWidget_LaunchCharacter_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesCharacterSelectWidget_LaunchCharacter_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesCharacterSelectWidget, nullptr, "LaunchCharacter", Z_Construct_UFunction_UEchoesCharacterSelectWidget_LaunchCharacter_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesCharacterSelectWidget_LaunchCharacter_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesCharacterSelectWidget_LaunchCharacter_Statics::EchoesCharacterSelectWidget_eventLaunchCharacter_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesCharacterSelectWidget_LaunchCharacter_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesCharacterSelectWidget_LaunchCharacter_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesCharacterSelectWidget_LaunchCharacter_Statics::EchoesCharacterSelectWidget_eventLaunchCharacter_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesCharacterSelectWidget_LaunchCharacter()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesCharacterSelectWidget_LaunchCharacter_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesCharacterSelectWidget::execLaunchCharacter)
{
	P_GET_STRUCT(FGuid,Z_Param_CharacterId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->LaunchCharacter(Z_Param_CharacterId);
	P_NATIVE_END;
}
// ********** End Class UEchoesCharacterSelectWidget Function LaunchCharacter **********************

// ********** Begin Class UEchoesCharacterSelectWidget Function OnCancelCreateButtonClicked ********
struct Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCancelCreateButtonClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI/Widgets/EchoesCharacterSelectWidget.h" },
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

// ********** Begin Class UEchoesCharacterSelectWidget Function OnCharacterListSelectionChanged ****
struct Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCharacterListSelectionChanged_Statics
{
	struct EchoesCharacterSelectWidget_eventOnCharacterListSelectionChanged_Parms
	{
		UObject* SelectedItem;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI/Widgets/EchoesCharacterSelectWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SelectedItem;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCharacterListSelectionChanged_Statics::NewProp_SelectedItem = { "SelectedItem", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesCharacterSelectWidget_eventOnCharacterListSelectionChanged_Parms, SelectedItem), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCharacterListSelectionChanged_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCharacterListSelectionChanged_Statics::NewProp_SelectedItem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCharacterListSelectionChanged_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCharacterListSelectionChanged_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesCharacterSelectWidget, nullptr, "OnCharacterListSelectionChanged", Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCharacterListSelectionChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCharacterListSelectionChanged_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCharacterListSelectionChanged_Statics::EchoesCharacterSelectWidget_eventOnCharacterListSelectionChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCharacterListSelectionChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCharacterListSelectionChanged_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCharacterListSelectionChanged_Statics::EchoesCharacterSelectWidget_eventOnCharacterListSelectionChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCharacterListSelectionChanged()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCharacterListSelectionChanged_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesCharacterSelectWidget::execOnCharacterListSelectionChanged)
{
	P_GET_OBJECT(UObject,Z_Param_SelectedItem);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnCharacterListSelectionChanged(Z_Param_SelectedItem);
	P_NATIVE_END;
}
// ********** End Class UEchoesCharacterSelectWidget Function OnCharacterListSelectionChanged ******

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
		{ "ModuleRelativePath", "UI/Widgets/EchoesCharacterSelectWidget.h" },
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
		{ "ModuleRelativePath", "UI/Widgets/EchoesCharacterSelectWidget.h" },
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
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ==================== Button Handlers ====================\n" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesCharacterSelectWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "==================== Button Handlers ====================" },
#endif
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
		{ "ModuleRelativePath", "UI/Widgets/EchoesCharacterSelectWidget.h" },
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
		{ "ModuleRelativePath", "UI/Widgets/EchoesCharacterSelectWidget.h" },
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
		{ "ModuleRelativePath", "UI/Widgets/EchoesCharacterSelectWidget.h" },
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

// ********** Begin Class UEchoesCharacterSelectWidget *********************************************
void UEchoesCharacterSelectWidget::StaticRegisterNativesUEchoesCharacterSelectWidget()
{
	UClass* Class = UEchoesCharacterSelectWidget::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "HandleCharacterCreated", &UEchoesCharacterSelectWidget::execHandleCharacterCreated },
		{ "HandleCharacterCreationFailed", &UEchoesCharacterSelectWidget::execHandleCharacterCreationFailed },
		{ "HandleCharacterDeleted", &UEchoesCharacterSelectWidget::execHandleCharacterDeleted },
		{ "HandleCharacterDeletionFailed", &UEchoesCharacterSelectWidget::execHandleCharacterDeletionFailed },
		{ "HandleCharacterListUpdated", &UEchoesCharacterSelectWidget::execHandleCharacterListUpdated },
		{ "LaunchCharacter", &UEchoesCharacterSelectWidget::execLaunchCharacter },
		{ "OnCancelCreateButtonClicked", &UEchoesCharacterSelectWidget::execOnCancelCreateButtonClicked },
		{ "OnCharacterListSelectionChanged", &UEchoesCharacterSelectWidget::execOnCharacterListSelectionChanged },
		{ "OnCharacterSelected", &UEchoesCharacterSelectWidget::execOnCharacterSelected },
		{ "OnConfirmCreateButtonClicked", &UEchoesCharacterSelectWidget::execOnConfirmCreateButtonClicked },
		{ "OnCreateButtonClicked", &UEchoesCharacterSelectWidget::execOnCreateButtonClicked },
		{ "OnDeleteButtonClicked", &UEchoesCharacterSelectWidget::execOnDeleteButtonClicked },
		{ "OnLogoutButtonClicked", &UEchoesCharacterSelectWidget::execOnLogoutButtonClicked },
		{ "OnRaceSelectionChanged", &UEchoesCharacterSelectWidget::execOnRaceSelectionChanged },
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
		{ "IncludePath", "UI/Widgets/EchoesCharacterSelectWidget.h" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesCharacterSelectWidget.h" },
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
		{ "ModuleRelativePath", "UI/Widgets/EchoesCharacterSelectWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "List view for characters" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CreateButton_MetaData[] = {
		{ "BindWidget", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Create new character button */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesCharacterSelectWidget.h" },
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
		{ "ModuleRelativePath", "UI/Widgets/EchoesCharacterSelectWidget.h" },
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
		{ "ModuleRelativePath", "UI/Widgets/EchoesCharacterSelectWidget.h" },
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
		{ "ModuleRelativePath", "UI/Widgets/EchoesCharacterSelectWidget.h" },
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
		{ "ModuleRelativePath", "UI/Widgets/EchoesCharacterSelectWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Character creation panel widgets" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RaceComboBox_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesCharacterSelectWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RaceDescriptionText_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesCharacterSelectWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RaceBonusesText_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesCharacterSelectWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ConfirmCreateButton_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesCharacterSelectWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CancelCreateButton_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesCharacterSelectWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CreationPanel_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesCharacterSelectWidget.h" },
		{ "OptionalWidget", "TRUE" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AuthSubsystem_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Reference to auth subsystem */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesCharacterSelectWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Reference to auth subsystem" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectedCharacter_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Currently selected character */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesCharacterSelectWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Currently selected character" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CharacterList;
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
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CreationPanel;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AuthSubsystem;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SelectedCharacter;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterCreated, "HandleCharacterCreated" }, // 4159767706
		{ &Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterCreationFailed, "HandleCharacterCreationFailed" }, // 200844842
		{ &Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterDeleted, "HandleCharacterDeleted" }, // 2545990866
		{ &Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterDeletionFailed, "HandleCharacterDeletionFailed" }, // 2486526509
		{ &Z_Construct_UFunction_UEchoesCharacterSelectWidget_HandleCharacterListUpdated, "HandleCharacterListUpdated" }, // 653994529
		{ &Z_Construct_UFunction_UEchoesCharacterSelectWidget_LaunchCharacter, "LaunchCharacter" }, // 60974106
		{ &Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCancelCreateButtonClicked, "OnCancelCreateButtonClicked" }, // 1138692661
		{ &Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCharacterListSelectionChanged, "OnCharacterListSelectionChanged" }, // 2534137099
		{ &Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCharacterSelected, "OnCharacterSelected" }, // 3305172017
		{ &Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnConfirmCreateButtonClicked, "OnConfirmCreateButtonClicked" }, // 3982875008
		{ &Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnCreateButtonClicked, "OnCreateButtonClicked" }, // 3599184037
		{ &Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnDeleteButtonClicked, "OnDeleteButtonClicked" }, // 2368296363
		{ &Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnLogoutButtonClicked, "OnLogoutButtonClicked" }, // 3530194877
		{ &Z_Construct_UFunction_UEchoesCharacterSelectWidget_OnRaceSelectionChanged, "OnRaceSelectionChanged" }, // 3884670524
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEchoesCharacterSelectWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::NewProp_CharacterList = { "CharacterList", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesCharacterSelectWidget, CharacterList), Z_Construct_UClass_UListView_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterList_MetaData), NewProp_CharacterList_MetaData) };
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
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::NewProp_CreationPanel = { "CreationPanel", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesCharacterSelectWidget, CreationPanel), Z_Construct_UClass_UWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CreationPanel_MetaData), NewProp_CreationPanel_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::NewProp_AuthSubsystem = { "AuthSubsystem", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesCharacterSelectWidget, AuthSubsystem), Z_Construct_UClass_UEchoesAuthSubsystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AuthSubsystem_MetaData), NewProp_AuthSubsystem_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::NewProp_SelectedCharacter = { "SelectedCharacter", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesCharacterSelectWidget, SelectedCharacter), Z_Construct_UClass_UCharacterListItem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectedCharacter_MetaData), NewProp_SelectedCharacter_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::NewProp_CharacterList,
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
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::NewProp_CreationPanel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::NewProp_AuthSubsystem,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::NewProp_SelectedCharacter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
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
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesCharacterSelectWidget_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCharacterListItem, UCharacterListItem::StaticClass, TEXT("UCharacterListItem"), &Z_Registration_Info_UClass_UCharacterListItem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCharacterListItem), 2993493031U) },
		{ Z_Construct_UClass_UEchoesCharacterSelectWidget, UEchoesCharacterSelectWidget::StaticClass, TEXT("UEchoesCharacterSelectWidget"), &Z_Registration_Info_UClass_UEchoesCharacterSelectWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEchoesCharacterSelectWidget), 3738749681U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesCharacterSelectWidget_h__Script_Echoes_1074520297(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesCharacterSelectWidget_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesCharacterSelectWidget_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
