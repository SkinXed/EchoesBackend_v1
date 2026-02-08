// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EchoesMarketOrderEntryWidget.h"
#include "EchoesMarketStructures.h"
#include "Styling/SlateColor.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesMarketOrderEntryWidget() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
ECHOES_API UClass* Z_Construct_UClass_UEchoesMarketOrderEntryWidget();
ECHOES_API UClass* Z_Construct_UClass_UEchoesMarketOrderEntryWidget_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UEchoesMarketOrderObject_NoRegister();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FMarketOrderDto();
SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FSlateColor();
UMG_API UClass* Z_Construct_UClass_UBorder_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserObjectListEntry_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UEchoesMarketOrderEntryWidget Function GetOrderTypeColor *****************
struct Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_GetOrderTypeColor_Statics
{
	struct EchoesMarketOrderEntryWidget_eventGetOrderTypeColor_Parms
	{
		bool bIsBuyOrder;
		FSlateColor ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Market|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the color for order text based on type\n\x09 * @param bIsBuyOrder - True for buy order, false for sell\n\x09 * @return Green for buy, Red for sell\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesMarketOrderEntryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the color for order text based on type\n@param bIsBuyOrder - True for buy order, false for sell\n@return Green for buy, Red for sell" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_bIsBuyOrder_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsBuyOrder;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_GetOrderTypeColor_Statics::NewProp_bIsBuyOrder_SetBit(void* Obj)
{
	((EchoesMarketOrderEntryWidget_eventGetOrderTypeColor_Parms*)Obj)->bIsBuyOrder = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_GetOrderTypeColor_Statics::NewProp_bIsBuyOrder = { "bIsBuyOrder", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EchoesMarketOrderEntryWidget_eventGetOrderTypeColor_Parms), &Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_GetOrderTypeColor_Statics::NewProp_bIsBuyOrder_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_GetOrderTypeColor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMarketOrderEntryWidget_eventGetOrderTypeColor_Parms, ReturnValue), Z_Construct_UScriptStruct_FSlateColor, METADATA_PARAMS(0, nullptr) }; // 811347535
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_GetOrderTypeColor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_GetOrderTypeColor_Statics::NewProp_bIsBuyOrder,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_GetOrderTypeColor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_GetOrderTypeColor_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_GetOrderTypeColor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesMarketOrderEntryWidget, nullptr, "GetOrderTypeColor", Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_GetOrderTypeColor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_GetOrderTypeColor_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_GetOrderTypeColor_Statics::EchoesMarketOrderEntryWidget_eventGetOrderTypeColor_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14082401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_GetOrderTypeColor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_GetOrderTypeColor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_GetOrderTypeColor_Statics::EchoesMarketOrderEntryWidget_eventGetOrderTypeColor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_GetOrderTypeColor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_GetOrderTypeColor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesMarketOrderEntryWidget::execGetOrderTypeColor)
{
	P_GET_UBOOL(Z_Param_bIsBuyOrder);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FSlateColor*)Z_Param__Result=UEchoesMarketOrderEntryWidget::GetOrderTypeColor(Z_Param_bIsBuyOrder);
	P_NATIVE_END;
}
// ********** End Class UEchoesMarketOrderEntryWidget Function GetOrderTypeColor *******************

// ********** Begin Class UEchoesMarketOrderEntryWidget Function OnOrderHovered ********************
struct EchoesMarketOrderEntryWidget_eventOnOrderHovered_Parms
{
	FMarketOrderDto OrderData;
};
static FName NAME_UEchoesMarketOrderEntryWidget_OnOrderHovered = FName(TEXT("OnOrderHovered"));
void UEchoesMarketOrderEntryWidget::OnOrderHovered(FMarketOrderDto const& OrderData)
{
	EchoesMarketOrderEntryWidget_eventOnOrderHovered_Parms Parms;
	Parms.OrderData=OrderData;
	UFunction* Func = FindFunctionChecked(NAME_UEchoesMarketOrderEntryWidget_OnOrderHovered);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_OnOrderHovered_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Market|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Blueprint event for showing tooltip with tax/fee details on hover */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesMarketOrderEntryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Blueprint event for showing tooltip with tax/fee details on hover" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OrderData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_OrderData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_OnOrderHovered_Statics::NewProp_OrderData = { "OrderData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMarketOrderEntryWidget_eventOnOrderHovered_Parms, OrderData), Z_Construct_UScriptStruct_FMarketOrderDto, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OrderData_MetaData), NewProp_OrderData_MetaData) }; // 449536635
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_OnOrderHovered_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_OnOrderHovered_Statics::NewProp_OrderData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_OnOrderHovered_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_OnOrderHovered_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesMarketOrderEntryWidget, nullptr, "OnOrderHovered", Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_OnOrderHovered_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_OnOrderHovered_Statics::PropPointers), sizeof(EchoesMarketOrderEntryWidget_eventOnOrderHovered_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08480800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_OnOrderHovered_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_OnOrderHovered_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(EchoesMarketOrderEntryWidget_eventOnOrderHovered_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_OnOrderHovered()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_OnOrderHovered_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UEchoesMarketOrderEntryWidget Function OnOrderHovered **********************

// ********** Begin Class UEchoesMarketOrderEntryWidget Function OnOrderUnhovered ******************
static FName NAME_UEchoesMarketOrderEntryWidget_OnOrderUnhovered = FName(TEXT("OnOrderUnhovered"));
void UEchoesMarketOrderEntryWidget::OnOrderUnhovered()
{
	UFunction* Func = FindFunctionChecked(NAME_UEchoesMarketOrderEntryWidget_OnOrderUnhovered);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_OnOrderUnhovered_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Market|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Blueprint event for hiding tooltip */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesMarketOrderEntryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Blueprint event for hiding tooltip" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_OnOrderUnhovered_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesMarketOrderEntryWidget, nullptr, "OnOrderUnhovered", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_OnOrderUnhovered_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_OnOrderUnhovered_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_OnOrderUnhovered()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_OnOrderUnhovered_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UEchoesMarketOrderEntryWidget Function OnOrderUnhovered ********************

// ********** Begin Class UEchoesMarketOrderEntryWidget Function SetOrderData **********************
struct Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_SetOrderData_Statics
{
	struct EchoesMarketOrderEntryWidget_eventSetOrderData_Parms
	{
		UEchoesMarketOrderObject* OrderObject;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Market|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Set the order data to display\n\x09 * Called automatically by ListView when item is set\n\x09 * @param OrderObject - The market order object to display\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesMarketOrderEntryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set the order data to display\nCalled automatically by ListView when item is set\n@param OrderObject - The market order object to display" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OrderObject;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_SetOrderData_Statics::NewProp_OrderObject = { "OrderObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMarketOrderEntryWidget_eventSetOrderData_Parms, OrderObject), Z_Construct_UClass_UEchoesMarketOrderObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_SetOrderData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_SetOrderData_Statics::NewProp_OrderObject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_SetOrderData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_SetOrderData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesMarketOrderEntryWidget, nullptr, "SetOrderData", Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_SetOrderData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_SetOrderData_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_SetOrderData_Statics::EchoesMarketOrderEntryWidget_eventSetOrderData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_SetOrderData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_SetOrderData_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_SetOrderData_Statics::EchoesMarketOrderEntryWidget_eventSetOrderData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_SetOrderData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_SetOrderData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesMarketOrderEntryWidget::execSetOrderData)
{
	P_GET_OBJECT(UEchoesMarketOrderObject,Z_Param_OrderObject);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetOrderData(Z_Param_OrderObject);
	P_NATIVE_END;
}
// ********** End Class UEchoesMarketOrderEntryWidget Function SetOrderData ************************

// ********** Begin Class UEchoesMarketOrderEntryWidget ********************************************
void UEchoesMarketOrderEntryWidget::StaticRegisterNativesUEchoesMarketOrderEntryWidget()
{
	UClass* Class = UEchoesMarketOrderEntryWidget::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetOrderTypeColor", &UEchoesMarketOrderEntryWidget::execGetOrderTypeColor },
		{ "SetOrderData", &UEchoesMarketOrderEntryWidget::execSetOrderData },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UEchoesMarketOrderEntryWidget;
UClass* UEchoesMarketOrderEntryWidget::GetPrivateStaticClass()
{
	using TClass = UEchoesMarketOrderEntryWidget;
	if (!Z_Registration_Info_UClass_UEchoesMarketOrderEntryWidget.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesMarketOrderEntryWidget"),
			Z_Registration_Info_UClass_UEchoesMarketOrderEntryWidget.InnerSingleton,
			StaticRegisterNativesUEchoesMarketOrderEntryWidget,
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
	return Z_Registration_Info_UClass_UEchoesMarketOrderEntryWidget.InnerSingleton;
}
UClass* Z_Construct_UClass_UEchoesMarketOrderEntryWidget_NoRegister()
{
	return UEchoesMarketOrderEntryWidget::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UEchoesMarketOrderEntryWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * UEchoesMarketOrderEntryWidget\n * \n * Entry widget for market order ListView items (EVE Online-style order book row)\n * Implements IUserObjectListEntry for efficient ListView pooling\n * Displays: Price, Quantity, Station, Time\n * Color-coded: Green for buy orders, Red for sell orders\n * Hover effects for detailed tax/fee information\n * \n * Usage in UMG:\n * - Create a widget blueprint based on this class\n * - Add UTextBlock widgets with matching names (PriceText, QuantityText, etc.)\n * - Add UBorder for RowBackground (hover highlight)\n * - Set this blueprint as Entry Widget Class in ListView\n */" },
#endif
		{ "IncludePath", "UI/Widgets/EchoesMarketOrderEntryWidget.h" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesMarketOrderEntryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UEchoesMarketOrderEntryWidget\n\nEntry widget for market order ListView items (EVE Online-style order book row)\nImplements IUserObjectListEntry for efficient ListView pooling\nDisplays: Price, Quantity, Station, Time\nColor-coded: Green for buy orders, Red for sell orders\nHover effects for detailed tax/fee information\n\nUsage in UMG:\n- Create a widget blueprint based on this class\n- Add UTextBlock widgets with matching names (PriceText, QuantityText, etc.)\n- Add UBorder for RowBackground (hover highlight)\n- Set this blueprint as Entry Widget Class in ListView" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PriceText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Echoes|Market|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Text block for price display */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesMarketOrderEntryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Text block for price display" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_QuantityText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Echoes|Market|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Text block for remaining quantity */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesMarketOrderEntryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Text block for remaining quantity" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StationText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Echoes|Market|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Text block for station name */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesMarketOrderEntryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Text block for station name" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TimeText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Echoes|Market|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Text block for time since issued */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesMarketOrderEntryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Text block for time since issued" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RowBackground_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Echoes|Market|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Background border for hover highlight effect */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesMarketOrderEntryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Background border for hover highlight effect" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NormalBackgroundColor_MetaData[] = {
		{ "Category", "Echoes|Market|UI|Style" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Normal background color */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesMarketOrderEntryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Normal background color" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HoveredBackgroundColor_MetaData[] = {
		{ "Category", "Echoes|Market|UI|Style" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Hovered background color */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesMarketOrderEntryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Hovered background color" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BuyOrderColor_MetaData[] = {
		{ "Category", "Echoes|Market|UI|Style" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Buy order text color (green) */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesMarketOrderEntryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Buy order text color (green)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SellOrderColor_MetaData[] = {
		{ "Category", "Echoes|Market|UI|Style" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sell order text color (red) */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesMarketOrderEntryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sell order text color (red)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentOrderObject_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current order object being displayed */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/EchoesMarketOrderEntryWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current order object being displayed" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PriceText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_QuantityText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StationText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TimeText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RowBackground;
	static const UECodeGen_Private::FStructPropertyParams NewProp_NormalBackgroundColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_HoveredBackgroundColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_BuyOrderColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SellOrderColor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentOrderObject;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_GetOrderTypeColor, "GetOrderTypeColor" }, // 679495959
		{ &Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_OnOrderHovered, "OnOrderHovered" }, // 1633424965
		{ &Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_OnOrderUnhovered, "OnOrderUnhovered" }, // 1995285860
		{ &Z_Construct_UFunction_UEchoesMarketOrderEntryWidget_SetOrderData, "SetOrderData" }, // 1237349960
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEchoesMarketOrderEntryWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesMarketOrderEntryWidget_Statics::NewProp_PriceText = { "PriceText", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesMarketOrderEntryWidget, PriceText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PriceText_MetaData), NewProp_PriceText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesMarketOrderEntryWidget_Statics::NewProp_QuantityText = { "QuantityText", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesMarketOrderEntryWidget, QuantityText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_QuantityText_MetaData), NewProp_QuantityText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesMarketOrderEntryWidget_Statics::NewProp_StationText = { "StationText", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesMarketOrderEntryWidget, StationText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StationText_MetaData), NewProp_StationText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesMarketOrderEntryWidget_Statics::NewProp_TimeText = { "TimeText", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesMarketOrderEntryWidget, TimeText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TimeText_MetaData), NewProp_TimeText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesMarketOrderEntryWidget_Statics::NewProp_RowBackground = { "RowBackground", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesMarketOrderEntryWidget, RowBackground), Z_Construct_UClass_UBorder_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RowBackground_MetaData), NewProp_RowBackground_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEchoesMarketOrderEntryWidget_Statics::NewProp_NormalBackgroundColor = { "NormalBackgroundColor", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesMarketOrderEntryWidget, NormalBackgroundColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NormalBackgroundColor_MetaData), NewProp_NormalBackgroundColor_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEchoesMarketOrderEntryWidget_Statics::NewProp_HoveredBackgroundColor = { "HoveredBackgroundColor", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesMarketOrderEntryWidget, HoveredBackgroundColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HoveredBackgroundColor_MetaData), NewProp_HoveredBackgroundColor_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEchoesMarketOrderEntryWidget_Statics::NewProp_BuyOrderColor = { "BuyOrderColor", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesMarketOrderEntryWidget, BuyOrderColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BuyOrderColor_MetaData), NewProp_BuyOrderColor_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEchoesMarketOrderEntryWidget_Statics::NewProp_SellOrderColor = { "SellOrderColor", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesMarketOrderEntryWidget, SellOrderColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SellOrderColor_MetaData), NewProp_SellOrderColor_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesMarketOrderEntryWidget_Statics::NewProp_CurrentOrderObject = { "CurrentOrderObject", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesMarketOrderEntryWidget, CurrentOrderObject), Z_Construct_UClass_UEchoesMarketOrderObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentOrderObject_MetaData), NewProp_CurrentOrderObject_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEchoesMarketOrderEntryWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMarketOrderEntryWidget_Statics::NewProp_PriceText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMarketOrderEntryWidget_Statics::NewProp_QuantityText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMarketOrderEntryWidget_Statics::NewProp_StationText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMarketOrderEntryWidget_Statics::NewProp_TimeText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMarketOrderEntryWidget_Statics::NewProp_RowBackground,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMarketOrderEntryWidget_Statics::NewProp_NormalBackgroundColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMarketOrderEntryWidget_Statics::NewProp_HoveredBackgroundColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMarketOrderEntryWidget_Statics::NewProp_BuyOrderColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMarketOrderEntryWidget_Statics::NewProp_SellOrderColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMarketOrderEntryWidget_Statics::NewProp_CurrentOrderObject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesMarketOrderEntryWidget_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UEchoesMarketOrderEntryWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesMarketOrderEntryWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UEchoesMarketOrderEntryWidget_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UUserObjectListEntry_NoRegister, (int32)VTABLE_OFFSET(UEchoesMarketOrderEntryWidget, IUserObjectListEntry), false },  // 1900202470
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEchoesMarketOrderEntryWidget_Statics::ClassParams = {
	&UEchoesMarketOrderEntryWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UEchoesMarketOrderEntryWidget_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesMarketOrderEntryWidget_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesMarketOrderEntryWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UEchoesMarketOrderEntryWidget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEchoesMarketOrderEntryWidget()
{
	if (!Z_Registration_Info_UClass_UEchoesMarketOrderEntryWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEchoesMarketOrderEntryWidget.OuterSingleton, Z_Construct_UClass_UEchoesMarketOrderEntryWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEchoesMarketOrderEntryWidget.OuterSingleton;
}
UEchoesMarketOrderEntryWidget::UEchoesMarketOrderEntryWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UEchoesMarketOrderEntryWidget);
UEchoesMarketOrderEntryWidget::~UEchoesMarketOrderEntryWidget() {}
// ********** End Class UEchoesMarketOrderEntryWidget **********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMarketOrderEntryWidget_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEchoesMarketOrderEntryWidget, UEchoesMarketOrderEntryWidget::StaticClass, TEXT("UEchoesMarketOrderEntryWidget"), &Z_Registration_Info_UClass_UEchoesMarketOrderEntryWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEchoesMarketOrderEntryWidget), 3336976208U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMarketOrderEntryWidget_h__Script_Echoes_3635681707(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMarketOrderEntryWidget_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMarketOrderEntryWidget_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
