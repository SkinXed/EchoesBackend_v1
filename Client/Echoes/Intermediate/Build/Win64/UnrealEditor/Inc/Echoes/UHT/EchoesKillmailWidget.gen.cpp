// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EchoesKillmailWidget.h"
#include "EchoesKillmailStructures.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesKillmailWidget() {}

// ********** Begin Cross Module References ********************************************************
ECHOES_API UClass* Z_Construct_UClass_UEchoesKillmailWidget();
ECHOES_API UClass* Z_Construct_UClass_UEchoesKillmailWidget_NoRegister();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FKillmailAttacker();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FKillmailData();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FKillmailItem();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UMG_API UClass* Z_Construct_UClass_UVerticalBox_NoRegister();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UEchoesKillmailWidget Function OnAddAttackerEntry ************************
struct EchoesKillmailWidget_eventOnAddAttackerEntry_Parms
{
	FKillmailAttacker Attacker;
};
static FName NAME_UEchoesKillmailWidget_OnAddAttackerEntry = FName(TEXT("OnAddAttackerEntry"));
void UEchoesKillmailWidget::OnAddAttackerEntry(FKillmailAttacker const& Attacker)
{
	EchoesKillmailWidget_eventOnAddAttackerEntry_Parms Parms;
	Parms.Attacker=Attacker;
	UFunction* Func = FindFunctionChecked(NAME_UEchoesKillmailWidget_OnAddAttackerEntry);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UEchoesKillmailWidget_OnAddAttackerEntry_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Combat|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Called to add an attacker entry to the attackers list */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesKillmailWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called to add an attacker entry to the attackers list" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Attacker_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Attacker;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesKillmailWidget_OnAddAttackerEntry_Statics::NewProp_Attacker = { "Attacker", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesKillmailWidget_eventOnAddAttackerEntry_Parms, Attacker), Z_Construct_UScriptStruct_FKillmailAttacker, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Attacker_MetaData), NewProp_Attacker_MetaData) }; // 996054030
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesKillmailWidget_OnAddAttackerEntry_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesKillmailWidget_OnAddAttackerEntry_Statics::NewProp_Attacker,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesKillmailWidget_OnAddAttackerEntry_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesKillmailWidget_OnAddAttackerEntry_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesKillmailWidget, nullptr, "OnAddAttackerEntry", Z_Construct_UFunction_UEchoesKillmailWidget_OnAddAttackerEntry_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesKillmailWidget_OnAddAttackerEntry_Statics::PropPointers), sizeof(EchoesKillmailWidget_eventOnAddAttackerEntry_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08480800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesKillmailWidget_OnAddAttackerEntry_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesKillmailWidget_OnAddAttackerEntry_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(EchoesKillmailWidget_eventOnAddAttackerEntry_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesKillmailWidget_OnAddAttackerEntry()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesKillmailWidget_OnAddAttackerEntry_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UEchoesKillmailWidget Function OnAddAttackerEntry **************************

// ********** Begin Class UEchoesKillmailWidget Function OnAddDestroyedItemEntry *******************
struct EchoesKillmailWidget_eventOnAddDestroyedItemEntry_Parms
{
	FKillmailItem Item;
};
static FName NAME_UEchoesKillmailWidget_OnAddDestroyedItemEntry = FName(TEXT("OnAddDestroyedItemEntry"));
void UEchoesKillmailWidget::OnAddDestroyedItemEntry(FKillmailItem const& Item)
{
	EchoesKillmailWidget_eventOnAddDestroyedItemEntry_Parms Parms;
	Parms.Item=Item;
	UFunction* Func = FindFunctionChecked(NAME_UEchoesKillmailWidget_OnAddDestroyedItemEntry);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UEchoesKillmailWidget_OnAddDestroyedItemEntry_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Combat|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Called to add a destroyed item entry */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesKillmailWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called to add a destroyed item entry" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Item_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Item;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesKillmailWidget_OnAddDestroyedItemEntry_Statics::NewProp_Item = { "Item", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesKillmailWidget_eventOnAddDestroyedItemEntry_Parms, Item), Z_Construct_UScriptStruct_FKillmailItem, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Item_MetaData), NewProp_Item_MetaData) }; // 4119519826
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesKillmailWidget_OnAddDestroyedItemEntry_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesKillmailWidget_OnAddDestroyedItemEntry_Statics::NewProp_Item,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesKillmailWidget_OnAddDestroyedItemEntry_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesKillmailWidget_OnAddDestroyedItemEntry_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesKillmailWidget, nullptr, "OnAddDestroyedItemEntry", Z_Construct_UFunction_UEchoesKillmailWidget_OnAddDestroyedItemEntry_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesKillmailWidget_OnAddDestroyedItemEntry_Statics::PropPointers), sizeof(EchoesKillmailWidget_eventOnAddDestroyedItemEntry_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08480800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesKillmailWidget_OnAddDestroyedItemEntry_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesKillmailWidget_OnAddDestroyedItemEntry_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(EchoesKillmailWidget_eventOnAddDestroyedItemEntry_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesKillmailWidget_OnAddDestroyedItemEntry()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesKillmailWidget_OnAddDestroyedItemEntry_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UEchoesKillmailWidget Function OnAddDestroyedItemEntry *********************

// ********** Begin Class UEchoesKillmailWidget Function OnAddDroppedItemEntry *********************
struct EchoesKillmailWidget_eventOnAddDroppedItemEntry_Parms
{
	FKillmailItem Item;
};
static FName NAME_UEchoesKillmailWidget_OnAddDroppedItemEntry = FName(TEXT("OnAddDroppedItemEntry"));
void UEchoesKillmailWidget::OnAddDroppedItemEntry(FKillmailItem const& Item)
{
	EchoesKillmailWidget_eventOnAddDroppedItemEntry_Parms Parms;
	Parms.Item=Item;
	UFunction* Func = FindFunctionChecked(NAME_UEchoesKillmailWidget_OnAddDroppedItemEntry);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UEchoesKillmailWidget_OnAddDroppedItemEntry_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Combat|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Called to add a dropped item entry */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesKillmailWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called to add a dropped item entry" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Item_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Item;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesKillmailWidget_OnAddDroppedItemEntry_Statics::NewProp_Item = { "Item", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesKillmailWidget_eventOnAddDroppedItemEntry_Parms, Item), Z_Construct_UScriptStruct_FKillmailItem, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Item_MetaData), NewProp_Item_MetaData) }; // 4119519826
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesKillmailWidget_OnAddDroppedItemEntry_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesKillmailWidget_OnAddDroppedItemEntry_Statics::NewProp_Item,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesKillmailWidget_OnAddDroppedItemEntry_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesKillmailWidget_OnAddDroppedItemEntry_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesKillmailWidget, nullptr, "OnAddDroppedItemEntry", Z_Construct_UFunction_UEchoesKillmailWidget_OnAddDroppedItemEntry_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesKillmailWidget_OnAddDroppedItemEntry_Statics::PropPointers), sizeof(EchoesKillmailWidget_eventOnAddDroppedItemEntry_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08480800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesKillmailWidget_OnAddDroppedItemEntry_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesKillmailWidget_OnAddDroppedItemEntry_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(EchoesKillmailWidget_eventOnAddDroppedItemEntry_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesKillmailWidget_OnAddDroppedItemEntry()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesKillmailWidget_OnAddDroppedItemEntry_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UEchoesKillmailWidget Function OnAddDroppedItemEntry ***********************

// ********** Begin Class UEchoesKillmailWidget Function OnKillmailDataSet *************************
struct EchoesKillmailWidget_eventOnKillmailDataSet_Parms
{
	FKillmailData KillmailData;
};
static FName NAME_UEchoesKillmailWidget_OnKillmailDataSet = FName(TEXT("OnKillmailDataSet"));
void UEchoesKillmailWidget::OnKillmailDataSet(FKillmailData const& KillmailData)
{
	EchoesKillmailWidget_eventOnKillmailDataSet_Parms Parms;
	Parms.KillmailData=KillmailData;
	UFunction* Func = FindFunctionChecked(NAME_UEchoesKillmailWidget_OnKillmailDataSet);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UEchoesKillmailWidget_OnKillmailDataSet_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Combat|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Called after killmail data is set \xe2\x80\x94 use for custom BP formatting */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesKillmailWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called after killmail data is set \xe2\x80\x94 use for custom BP formatting" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_KillmailData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_KillmailData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesKillmailWidget_OnKillmailDataSet_Statics::NewProp_KillmailData = { "KillmailData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesKillmailWidget_eventOnKillmailDataSet_Parms, KillmailData), Z_Construct_UScriptStruct_FKillmailData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_KillmailData_MetaData), NewProp_KillmailData_MetaData) }; // 1177097489
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesKillmailWidget_OnKillmailDataSet_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesKillmailWidget_OnKillmailDataSet_Statics::NewProp_KillmailData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesKillmailWidget_OnKillmailDataSet_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesKillmailWidget_OnKillmailDataSet_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesKillmailWidget, nullptr, "OnKillmailDataSet", Z_Construct_UFunction_UEchoesKillmailWidget_OnKillmailDataSet_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesKillmailWidget_OnKillmailDataSet_Statics::PropPointers), sizeof(EchoesKillmailWidget_eventOnKillmailDataSet_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08480800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesKillmailWidget_OnKillmailDataSet_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesKillmailWidget_OnKillmailDataSet_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(EchoesKillmailWidget_eventOnKillmailDataSet_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesKillmailWidget_OnKillmailDataSet()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesKillmailWidget_OnKillmailDataSet_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UEchoesKillmailWidget Function OnKillmailDataSet ***************************

// ********** Begin Class UEchoesKillmailWidget Function SetKillmailData ***************************
struct Z_Construct_UFunction_UEchoesKillmailWidget_SetKillmailData_Statics
{
	struct EchoesKillmailWidget_eventSetKillmailData_Parms
	{
		FKillmailData InKillmailData;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Combat|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Populate the widget with killmail data\n\x09 * @param InKillmailData - Full killmail data to display\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesKillmailWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Populate the widget with killmail data\n@param InKillmailData - Full killmail data to display" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InKillmailData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_InKillmailData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesKillmailWidget_SetKillmailData_Statics::NewProp_InKillmailData = { "InKillmailData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesKillmailWidget_eventSetKillmailData_Parms, InKillmailData), Z_Construct_UScriptStruct_FKillmailData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InKillmailData_MetaData), NewProp_InKillmailData_MetaData) }; // 1177097489
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesKillmailWidget_SetKillmailData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesKillmailWidget_SetKillmailData_Statics::NewProp_InKillmailData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesKillmailWidget_SetKillmailData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesKillmailWidget_SetKillmailData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesKillmailWidget, nullptr, "SetKillmailData", Z_Construct_UFunction_UEchoesKillmailWidget_SetKillmailData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesKillmailWidget_SetKillmailData_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesKillmailWidget_SetKillmailData_Statics::EchoesKillmailWidget_eventSetKillmailData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesKillmailWidget_SetKillmailData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesKillmailWidget_SetKillmailData_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesKillmailWidget_SetKillmailData_Statics::EchoesKillmailWidget_eventSetKillmailData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesKillmailWidget_SetKillmailData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesKillmailWidget_SetKillmailData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesKillmailWidget::execSetKillmailData)
{
	P_GET_STRUCT_REF(FKillmailData,Z_Param_Out_InKillmailData);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetKillmailData(Z_Param_Out_InKillmailData);
	P_NATIVE_END;
}
// ********** End Class UEchoesKillmailWidget Function SetKillmailData *****************************

// ********** Begin Class UEchoesKillmailWidget ****************************************************
void UEchoesKillmailWidget::StaticRegisterNativesUEchoesKillmailWidget()
{
	UClass* Class = UEchoesKillmailWidget::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "SetKillmailData", &UEchoesKillmailWidget::execSetKillmailData },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UEchoesKillmailWidget;
UClass* UEchoesKillmailWidget::GetPrivateStaticClass()
{
	using TClass = UEchoesKillmailWidget;
	if (!Z_Registration_Info_UClass_UEchoesKillmailWidget.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesKillmailWidget"),
			Z_Registration_Info_UClass_UEchoesKillmailWidget.InnerSingleton,
			StaticRegisterNativesUEchoesKillmailWidget,
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
	return Z_Registration_Info_UClass_UEchoesKillmailWidget.InnerSingleton;
}
UClass* Z_Construct_UClass_UEchoesKillmailWidget_NoRegister()
{
	return UEchoesKillmailWidget::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UEchoesKillmailWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * UEchoesKillmailWidget\n * \n * Killmail display widget (zkillboard-style)\n * Shows: who killed whom, in what ship, lost items, and total value\n * \n * Layout:\n * - Header: Victim name + ship type + solar system\n * - Attackers list: who participated, with damage dealt\n * - Items section: dropped (green) and destroyed (red) items\n * - Footer: total ISK lost\n * \n * Usage:\n * - Create a widget blueprint based on this class\n * - Call SetKillmailData() with a FKillmailData struct\n * - Widget auto-populates all bound text blocks\n */" },
#endif
		{ "IncludePath", "UI/Widgets/EchoesKillmailWidget.h" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesKillmailWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UEchoesKillmailWidget\n\nKillmail display widget (zkillboard-style)\nShows: who killed whom, in what ship, lost items, and total value\n\nLayout:\n- Header: Victim name + ship type + solar system\n- Attackers list: who participated, with damage dealt\n- Items section: dropped (green) and destroyed (red) items\n- Footer: total ISK lost\n\nUsage:\n- Create a widget blueprint based on this class\n- Call SetKillmailData() with a FKillmailData struct\n- Widget auto-populates all bound text blocks" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VictimNameText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Killmail" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Victim's character name */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesKillmailWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Victim's character name" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShipTypeText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Killmail" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Ship type that was destroyed */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesKillmailWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ship type that was destroyed" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SystemNameText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Killmail" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Solar system name */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesKillmailWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Solar system name" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalLossText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Killmail" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Total ISK loss value */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesKillmailWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Total ISK loss value" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TimestampText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Killmail" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Timestamp of the kill */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesKillmailWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Timestamp of the kill" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FinalBlowText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Killmail" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Final blow attacker name */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesKillmailWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Final blow attacker name" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackerCountText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Killmail" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Number of attackers */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesKillmailWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Number of attackers" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackersBox_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "Killmail" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Container for attacker entries (populated at runtime) */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesKillmailWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Container for attacker entries (populated at runtime)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DroppedItemsBox_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "Killmail" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Container for dropped items (populated at runtime) */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesKillmailWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Container for dropped items (populated at runtime)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DestroyedItemsBox_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "Killmail" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Container for destroyed items (populated at runtime) */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesKillmailWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Container for destroyed items (populated at runtime)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_VictimNameText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ShipTypeText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SystemNameText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TotalLossText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TimestampText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FinalBlowText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AttackerCountText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AttackersBox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DroppedItemsBox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DestroyedItemsBox;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UEchoesKillmailWidget_OnAddAttackerEntry, "OnAddAttackerEntry" }, // 2626263091
		{ &Z_Construct_UFunction_UEchoesKillmailWidget_OnAddDestroyedItemEntry, "OnAddDestroyedItemEntry" }, // 756228164
		{ &Z_Construct_UFunction_UEchoesKillmailWidget_OnAddDroppedItemEntry, "OnAddDroppedItemEntry" }, // 3401502202
		{ &Z_Construct_UFunction_UEchoesKillmailWidget_OnKillmailDataSet, "OnKillmailDataSet" }, // 2511586254
		{ &Z_Construct_UFunction_UEchoesKillmailWidget_SetKillmailData, "SetKillmailData" }, // 911403542
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEchoesKillmailWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesKillmailWidget_Statics::NewProp_VictimNameText = { "VictimNameText", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesKillmailWidget, VictimNameText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VictimNameText_MetaData), NewProp_VictimNameText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesKillmailWidget_Statics::NewProp_ShipTypeText = { "ShipTypeText", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesKillmailWidget, ShipTypeText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShipTypeText_MetaData), NewProp_ShipTypeText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesKillmailWidget_Statics::NewProp_SystemNameText = { "SystemNameText", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesKillmailWidget, SystemNameText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SystemNameText_MetaData), NewProp_SystemNameText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesKillmailWidget_Statics::NewProp_TotalLossText = { "TotalLossText", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesKillmailWidget, TotalLossText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalLossText_MetaData), NewProp_TotalLossText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesKillmailWidget_Statics::NewProp_TimestampText = { "TimestampText", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesKillmailWidget, TimestampText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TimestampText_MetaData), NewProp_TimestampText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesKillmailWidget_Statics::NewProp_FinalBlowText = { "FinalBlowText", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesKillmailWidget, FinalBlowText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FinalBlowText_MetaData), NewProp_FinalBlowText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesKillmailWidget_Statics::NewProp_AttackerCountText = { "AttackerCountText", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesKillmailWidget, AttackerCountText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackerCountText_MetaData), NewProp_AttackerCountText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesKillmailWidget_Statics::NewProp_AttackersBox = { "AttackersBox", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesKillmailWidget, AttackersBox), Z_Construct_UClass_UVerticalBox_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackersBox_MetaData), NewProp_AttackersBox_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesKillmailWidget_Statics::NewProp_DroppedItemsBox = { "DroppedItemsBox", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesKillmailWidget, DroppedItemsBox), Z_Construct_UClass_UVerticalBox_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DroppedItemsBox_MetaData), NewProp_DroppedItemsBox_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesKillmailWidget_Statics::NewProp_DestroyedItemsBox = { "DestroyedItemsBox", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesKillmailWidget, DestroyedItemsBox), Z_Construct_UClass_UVerticalBox_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DestroyedItemsBox_MetaData), NewProp_DestroyedItemsBox_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEchoesKillmailWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesKillmailWidget_Statics::NewProp_VictimNameText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesKillmailWidget_Statics::NewProp_ShipTypeText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesKillmailWidget_Statics::NewProp_SystemNameText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesKillmailWidget_Statics::NewProp_TotalLossText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesKillmailWidget_Statics::NewProp_TimestampText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesKillmailWidget_Statics::NewProp_FinalBlowText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesKillmailWidget_Statics::NewProp_AttackerCountText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesKillmailWidget_Statics::NewProp_AttackersBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesKillmailWidget_Statics::NewProp_DroppedItemsBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesKillmailWidget_Statics::NewProp_DestroyedItemsBox,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesKillmailWidget_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UEchoesKillmailWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesKillmailWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEchoesKillmailWidget_Statics::ClassParams = {
	&UEchoesKillmailWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UEchoesKillmailWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesKillmailWidget_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesKillmailWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UEchoesKillmailWidget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEchoesKillmailWidget()
{
	if (!Z_Registration_Info_UClass_UEchoesKillmailWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEchoesKillmailWidget.OuterSingleton, Z_Construct_UClass_UEchoesKillmailWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEchoesKillmailWidget.OuterSingleton;
}
UEchoesKillmailWidget::UEchoesKillmailWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UEchoesKillmailWidget);
UEchoesKillmailWidget::~UEchoesKillmailWidget() {}
// ********** End Class UEchoesKillmailWidget ******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesKillmailWidget_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEchoesKillmailWidget, UEchoesKillmailWidget::StaticClass, TEXT("UEchoesKillmailWidget"), &Z_Registration_Info_UClass_UEchoesKillmailWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEchoesKillmailWidget), 1333926419U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesKillmailWidget_h__Script_Echoes_4262282755(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesKillmailWidget_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesKillmailWidget_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
