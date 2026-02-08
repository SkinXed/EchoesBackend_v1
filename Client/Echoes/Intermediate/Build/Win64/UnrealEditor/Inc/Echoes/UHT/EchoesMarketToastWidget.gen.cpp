// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EchoesMarketToastWidget.h"
#include "EchoesMarketStructures.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesMarketToastWidget() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
ECHOES_API UClass* Z_Construct_UClass_UEchoesMarketToastWidget();
ECHOES_API UClass* Z_Construct_UClass_UEchoesMarketToastWidget_NoRegister();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FMarketTradeResult();
UMG_API UClass* Z_Construct_UClass_UBorder_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UEchoesMarketToastWidget Function OnToastFadeOut *************************
static FName NAME_UEchoesMarketToastWidget_OnToastFadeOut = FName(TEXT("OnToastFadeOut"));
void UEchoesMarketToastWidget::OnToastFadeOut()
{
	UFunction* Func = FindFunctionChecked(NAME_UEchoesMarketToastWidget_OnToastFadeOut);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_UEchoesMarketToastWidget_OnToastFadeOut_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Market|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Blueprint event for custom fade-out animation */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesMarketToastWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Blueprint event for custom fade-out animation" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesMarketToastWidget_OnToastFadeOut_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesMarketToastWidget, nullptr, "OnToastFadeOut", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketToastWidget_OnToastFadeOut_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesMarketToastWidget_OnToastFadeOut_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesMarketToastWidget_OnToastFadeOut()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesMarketToastWidget_OnToastFadeOut_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UEchoesMarketToastWidget Function OnToastFadeOut ***************************

// ********** Begin Class UEchoesMarketToastWidget Function ShowMessage ****************************
struct Z_Construct_UFunction_UEchoesMarketToastWidget_ShowMessage_Statics
{
	struct EchoesMarketToastWidget_eventShowMessage_Parms
	{
		FString Message;
		bool bIsError;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Market|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Show a generic market message toast\n\x09 * @param Message - Message text to display\n\x09 * @param bIsError - True for error styling, false for success\n\x09 */" },
#endif
		{ "CPP_Default_bIsError", "false" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesMarketToastWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Show a generic market message toast\n@param Message - Message text to display\n@param bIsError - True for error styling, false for success" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_Message;
	static void NewProp_bIsError_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEchoesMarketToastWidget_ShowMessage_Statics::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMarketToastWidget_eventShowMessage_Parms, Message), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) };
void Z_Construct_UFunction_UEchoesMarketToastWidget_ShowMessage_Statics::NewProp_bIsError_SetBit(void* Obj)
{
	((EchoesMarketToastWidget_eventShowMessage_Parms*)Obj)->bIsError = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UEchoesMarketToastWidget_ShowMessage_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EchoesMarketToastWidget_eventShowMessage_Parms), &Z_Construct_UFunction_UEchoesMarketToastWidget_ShowMessage_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesMarketToastWidget_ShowMessage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMarketToastWidget_ShowMessage_Statics::NewProp_Message,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMarketToastWidget_ShowMessage_Statics::NewProp_bIsError,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketToastWidget_ShowMessage_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesMarketToastWidget_ShowMessage_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesMarketToastWidget, nullptr, "ShowMessage", Z_Construct_UFunction_UEchoesMarketToastWidget_ShowMessage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketToastWidget_ShowMessage_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesMarketToastWidget_ShowMessage_Statics::EchoesMarketToastWidget_eventShowMessage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketToastWidget_ShowMessage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesMarketToastWidget_ShowMessage_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesMarketToastWidget_ShowMessage_Statics::EchoesMarketToastWidget_eventShowMessage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesMarketToastWidget_ShowMessage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesMarketToastWidget_ShowMessage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesMarketToastWidget::execShowMessage)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Message);
	P_GET_UBOOL(Z_Param_bIsError);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ShowMessage(Z_Param_Message,Z_Param_bIsError);
	P_NATIVE_END;
}
// ********** End Class UEchoesMarketToastWidget Function ShowMessage ******************************

// ********** Begin Class UEchoesMarketToastWidget Function ShowTradeConfirmation ******************
struct Z_Construct_UFunction_UEchoesMarketToastWidget_ShowTradeConfirmation_Statics
{
	struct EchoesMarketToastWidget_eventShowTradeConfirmation_Parms
	{
		FMarketTradeResult TradeResult;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Market|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Show a trade confirmation toast\n\x09 * @param TradeResult - Result of the executed trade\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesMarketToastWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Show a trade confirmation toast\n@param TradeResult - Result of the executed trade" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TradeResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_TradeResult;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesMarketToastWidget_ShowTradeConfirmation_Statics::NewProp_TradeResult = { "TradeResult", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMarketToastWidget_eventShowTradeConfirmation_Parms, TradeResult), Z_Construct_UScriptStruct_FMarketTradeResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TradeResult_MetaData), NewProp_TradeResult_MetaData) }; // 4107301343
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesMarketToastWidget_ShowTradeConfirmation_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMarketToastWidget_ShowTradeConfirmation_Statics::NewProp_TradeResult,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketToastWidget_ShowTradeConfirmation_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesMarketToastWidget_ShowTradeConfirmation_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesMarketToastWidget, nullptr, "ShowTradeConfirmation", Z_Construct_UFunction_UEchoesMarketToastWidget_ShowTradeConfirmation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketToastWidget_ShowTradeConfirmation_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesMarketToastWidget_ShowTradeConfirmation_Statics::EchoesMarketToastWidget_eventShowTradeConfirmation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketToastWidget_ShowTradeConfirmation_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesMarketToastWidget_ShowTradeConfirmation_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesMarketToastWidget_ShowTradeConfirmation_Statics::EchoesMarketToastWidget_eventShowTradeConfirmation_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesMarketToastWidget_ShowTradeConfirmation()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesMarketToastWidget_ShowTradeConfirmation_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesMarketToastWidget::execShowTradeConfirmation)
{
	P_GET_STRUCT_REF(FMarketTradeResult,Z_Param_Out_TradeResult);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ShowTradeConfirmation(Z_Param_Out_TradeResult);
	P_NATIVE_END;
}
// ********** End Class UEchoesMarketToastWidget Function ShowTradeConfirmation ********************

// ********** Begin Class UEchoesMarketToastWidget *************************************************
void UEchoesMarketToastWidget::StaticRegisterNativesUEchoesMarketToastWidget()
{
	UClass* Class = UEchoesMarketToastWidget::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ShowMessage", &UEchoesMarketToastWidget::execShowMessage },
		{ "ShowTradeConfirmation", &UEchoesMarketToastWidget::execShowTradeConfirmation },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UEchoesMarketToastWidget;
UClass* UEchoesMarketToastWidget::GetPrivateStaticClass()
{
	using TClass = UEchoesMarketToastWidget;
	if (!Z_Registration_Info_UClass_UEchoesMarketToastWidget.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesMarketToastWidget"),
			Z_Registration_Info_UClass_UEchoesMarketToastWidget.InnerSingleton,
			StaticRegisterNativesUEchoesMarketToastWidget,
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
	return Z_Registration_Info_UClass_UEchoesMarketToastWidget.InnerSingleton;
}
UClass* Z_Construct_UClass_UEchoesMarketToastWidget_NoRegister()
{
	return UEchoesMarketToastWidget::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UEchoesMarketToastWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * UEchoesMarketToastWidget\n * \n * Toast notification widget for market trade confirmations\n * Shows \"Bought [Quantity] x [ItemName] for [Price] ISK\" popup\n * Auto-fades after a configurable duration\n * \n * Usage:\n * - Create a widget blueprint based on this class\n * - Bind text blocks (MessageText) and background (ToastBackground)\n * - Call ShowTradeConfirmation() with a FMarketTradeResult\n * - Widget auto-removes after DisplayDuration seconds\n */" },
#endif
		{ "IncludePath", "UI/Widgets/EchoesMarketToastWidget.h" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesMarketToastWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UEchoesMarketToastWidget\n\nToast notification widget for market trade confirmations\nShows \"Bought [Quantity] x [ItemName] for [Price] ISK\" popup\nAuto-fades after a configurable duration\n\nUsage:\n- Create a widget blueprint based on this class\n- Bind text blocks (MessageText) and background (ToastBackground)\n- Call ShowTradeConfirmation() with a FMarketTradeResult\n- Widget auto-removes after DisplayDuration seconds" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DisplayDuration_MetaData[] = {
		{ "Category", "Echoes|Market|UI|Style" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Duration the toast stays visible (seconds) */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesMarketToastWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Duration the toast stays visible (seconds)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MessageText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Echoes|Market|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Main message text */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesMarketToastWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Main message text" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ToastBackground_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Echoes|Market|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Background border for color styling */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesMarketToastWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Background border for color styling" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SuccessColor_MetaData[] = {
		{ "Category", "Echoes|Market|UI|Style" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Success background color */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesMarketToastWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Success background color" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ErrorColor_MetaData[] = {
		{ "Category", "Echoes|Market|UI|Style" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Error background color */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesMarketToastWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Error background color" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DisplayDuration;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MessageText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ToastBackground;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SuccessColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ErrorColor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UEchoesMarketToastWidget_OnToastFadeOut, "OnToastFadeOut" }, // 556999547
		{ &Z_Construct_UFunction_UEchoesMarketToastWidget_ShowMessage, "ShowMessage" }, // 178462265
		{ &Z_Construct_UFunction_UEchoesMarketToastWidget_ShowTradeConfirmation, "ShowTradeConfirmation" }, // 2817477292
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEchoesMarketToastWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEchoesMarketToastWidget_Statics::NewProp_DisplayDuration = { "DisplayDuration", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesMarketToastWidget, DisplayDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DisplayDuration_MetaData), NewProp_DisplayDuration_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesMarketToastWidget_Statics::NewProp_MessageText = { "MessageText", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesMarketToastWidget, MessageText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MessageText_MetaData), NewProp_MessageText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesMarketToastWidget_Statics::NewProp_ToastBackground = { "ToastBackground", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesMarketToastWidget, ToastBackground), Z_Construct_UClass_UBorder_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ToastBackground_MetaData), NewProp_ToastBackground_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEchoesMarketToastWidget_Statics::NewProp_SuccessColor = { "SuccessColor", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesMarketToastWidget, SuccessColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SuccessColor_MetaData), NewProp_SuccessColor_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEchoesMarketToastWidget_Statics::NewProp_ErrorColor = { "ErrorColor", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesMarketToastWidget, ErrorColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ErrorColor_MetaData), NewProp_ErrorColor_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEchoesMarketToastWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMarketToastWidget_Statics::NewProp_DisplayDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMarketToastWidget_Statics::NewProp_MessageText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMarketToastWidget_Statics::NewProp_ToastBackground,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMarketToastWidget_Statics::NewProp_SuccessColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMarketToastWidget_Statics::NewProp_ErrorColor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesMarketToastWidget_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UEchoesMarketToastWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesMarketToastWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEchoesMarketToastWidget_Statics::ClassParams = {
	&UEchoesMarketToastWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UEchoesMarketToastWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesMarketToastWidget_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesMarketToastWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UEchoesMarketToastWidget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEchoesMarketToastWidget()
{
	if (!Z_Registration_Info_UClass_UEchoesMarketToastWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEchoesMarketToastWidget.OuterSingleton, Z_Construct_UClass_UEchoesMarketToastWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEchoesMarketToastWidget.OuterSingleton;
}
UEchoesMarketToastWidget::UEchoesMarketToastWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UEchoesMarketToastWidget);
UEchoesMarketToastWidget::~UEchoesMarketToastWidget() {}
// ********** End Class UEchoesMarketToastWidget ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMarketToastWidget_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEchoesMarketToastWidget, UEchoesMarketToastWidget::StaticClass, TEXT("UEchoesMarketToastWidget"), &Z_Registration_Info_UClass_UEchoesMarketToastWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEchoesMarketToastWidget), 3097403535U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMarketToastWidget_h__Script_Echoes_1701105296(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMarketToastWidget_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMarketToastWidget_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
