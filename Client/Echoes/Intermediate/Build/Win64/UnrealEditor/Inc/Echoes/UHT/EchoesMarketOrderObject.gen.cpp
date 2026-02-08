// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EchoesMarketOrderObject.h"
#include "EchoesMarketStructures.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesMarketOrderObject() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ECHOES_API UClass* Z_Construct_UClass_UEchoesMarketOrderObject();
ECHOES_API UClass* Z_Construct_UClass_UEchoesMarketOrderObject_NoRegister();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FMarketOrderDto();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UEchoesMarketOrderObject Function GetFormattedIssuedTime *****************
struct Z_Construct_UFunction_UEchoesMarketOrderObject_GetFormattedIssuedTime_Statics
{
	struct EchoesMarketOrderObject_eventGetFormattedIssuedTime_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Market|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get formatted time since issued (e.g., \"2h 15m ago\")\n\x09 * @return Formatted time string\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Logic/EchoesMarketOrderObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get formatted time since issued (e.g., \"2h 15m ago\")\n@return Formatted time string" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEchoesMarketOrderObject_GetFormattedIssuedTime_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMarketOrderObject_eventGetFormattedIssuedTime_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesMarketOrderObject_GetFormattedIssuedTime_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMarketOrderObject_GetFormattedIssuedTime_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketOrderObject_GetFormattedIssuedTime_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesMarketOrderObject_GetFormattedIssuedTime_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesMarketOrderObject, nullptr, "GetFormattedIssuedTime", Z_Construct_UFunction_UEchoesMarketOrderObject_GetFormattedIssuedTime_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketOrderObject_GetFormattedIssuedTime_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesMarketOrderObject_GetFormattedIssuedTime_Statics::EchoesMarketOrderObject_eventGetFormattedIssuedTime_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketOrderObject_GetFormattedIssuedTime_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesMarketOrderObject_GetFormattedIssuedTime_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesMarketOrderObject_GetFormattedIssuedTime_Statics::EchoesMarketOrderObject_eventGetFormattedIssuedTime_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesMarketOrderObject_GetFormattedIssuedTime()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesMarketOrderObject_GetFormattedIssuedTime_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesMarketOrderObject::execGetFormattedIssuedTime)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GetFormattedIssuedTime();
	P_NATIVE_END;
}
// ********** End Class UEchoesMarketOrderObject Function GetFormattedIssuedTime *******************

// ********** Begin Class UEchoesMarketOrderObject Function GetFormattedPrice **********************
struct Z_Construct_UFunction_UEchoesMarketOrderObject_GetFormattedPrice_Statics
{
	struct EchoesMarketOrderObject_eventGetFormattedPrice_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Market|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get formatted price string (e.g., \"1,250.50 ISK\")\n\x09 * @return Formatted price string\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Logic/EchoesMarketOrderObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get formatted price string (e.g., \"1,250.50 ISK\")\n@return Formatted price string" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEchoesMarketOrderObject_GetFormattedPrice_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMarketOrderObject_eventGetFormattedPrice_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesMarketOrderObject_GetFormattedPrice_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMarketOrderObject_GetFormattedPrice_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketOrderObject_GetFormattedPrice_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesMarketOrderObject_GetFormattedPrice_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesMarketOrderObject, nullptr, "GetFormattedPrice", Z_Construct_UFunction_UEchoesMarketOrderObject_GetFormattedPrice_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketOrderObject_GetFormattedPrice_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesMarketOrderObject_GetFormattedPrice_Statics::EchoesMarketOrderObject_eventGetFormattedPrice_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketOrderObject_GetFormattedPrice_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesMarketOrderObject_GetFormattedPrice_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesMarketOrderObject_GetFormattedPrice_Statics::EchoesMarketOrderObject_eventGetFormattedPrice_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesMarketOrderObject_GetFormattedPrice()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesMarketOrderObject_GetFormattedPrice_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesMarketOrderObject::execGetFormattedPrice)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GetFormattedPrice();
	P_NATIVE_END;
}
// ********** End Class UEchoesMarketOrderObject Function GetFormattedPrice ************************

// ********** Begin Class UEchoesMarketOrderObject Function GetItemId ******************************
struct Z_Construct_UFunction_UEchoesMarketOrderObject_GetItemId_Statics
{
	struct EchoesMarketOrderObject_eventGetItemId_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Market|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the item ID\n\x09 * @return Item type ID\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Logic/EchoesMarketOrderObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the item ID\n@return Item type ID" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UEchoesMarketOrderObject_GetItemId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMarketOrderObject_eventGetItemId_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesMarketOrderObject_GetItemId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMarketOrderObject_GetItemId_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketOrderObject_GetItemId_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesMarketOrderObject_GetItemId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesMarketOrderObject, nullptr, "GetItemId", Z_Construct_UFunction_UEchoesMarketOrderObject_GetItemId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketOrderObject_GetItemId_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesMarketOrderObject_GetItemId_Statics::EchoesMarketOrderObject_eventGetItemId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketOrderObject_GetItemId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesMarketOrderObject_GetItemId_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesMarketOrderObject_GetItemId_Statics::EchoesMarketOrderObject_eventGetItemId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesMarketOrderObject_GetItemId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesMarketOrderObject_GetItemId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesMarketOrderObject::execGetItemId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetItemId();
	P_NATIVE_END;
}
// ********** End Class UEchoesMarketOrderObject Function GetItemId ********************************

// ********** Begin Class UEchoesMarketOrderObject Function GetOrderData ***************************
struct Z_Construct_UFunction_UEchoesMarketOrderObject_GetOrderData_Statics
{
	struct EchoesMarketOrderObject_eventGetOrderData_Parms
	{
		FMarketOrderDto ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Market|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the wrapped market order data\n\x09 * @return The wrapped market order\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Logic/EchoesMarketOrderObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the wrapped market order data\n@return The wrapped market order" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesMarketOrderObject_GetOrderData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMarketOrderObject_eventGetOrderData_Parms, ReturnValue), Z_Construct_UScriptStruct_FMarketOrderDto, METADATA_PARAMS(0, nullptr) }; // 449536635
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesMarketOrderObject_GetOrderData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMarketOrderObject_GetOrderData_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketOrderObject_GetOrderData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesMarketOrderObject_GetOrderData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesMarketOrderObject, nullptr, "GetOrderData", Z_Construct_UFunction_UEchoesMarketOrderObject_GetOrderData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketOrderObject_GetOrderData_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesMarketOrderObject_GetOrderData_Statics::EchoesMarketOrderObject_eventGetOrderData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketOrderObject_GetOrderData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesMarketOrderObject_GetOrderData_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesMarketOrderObject_GetOrderData_Statics::EchoesMarketOrderObject_eventGetOrderData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesMarketOrderObject_GetOrderData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesMarketOrderObject_GetOrderData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesMarketOrderObject::execGetOrderData)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FMarketOrderDto*)Z_Param__Result=P_THIS->GetOrderData();
	P_NATIVE_END;
}
// ********** End Class UEchoesMarketOrderObject Function GetOrderData *****************************

// ********** Begin Class UEchoesMarketOrderObject Function GetOrderId *****************************
struct Z_Construct_UFunction_UEchoesMarketOrderObject_GetOrderId_Statics
{
	struct EchoesMarketOrderObject_eventGetOrderId_Parms
	{
		FGuid ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Market|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the order ID\n\x09 * @return Order GUID\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Logic/EchoesMarketOrderObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the order ID\n@return Order GUID" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesMarketOrderObject_GetOrderId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMarketOrderObject_eventGetOrderId_Parms, ReturnValue), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesMarketOrderObject_GetOrderId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMarketOrderObject_GetOrderId_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketOrderObject_GetOrderId_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesMarketOrderObject_GetOrderId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesMarketOrderObject, nullptr, "GetOrderId", Z_Construct_UFunction_UEchoesMarketOrderObject_GetOrderId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketOrderObject_GetOrderId_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesMarketOrderObject_GetOrderId_Statics::EchoesMarketOrderObject_eventGetOrderId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketOrderObject_GetOrderId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesMarketOrderObject_GetOrderId_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesMarketOrderObject_GetOrderId_Statics::EchoesMarketOrderObject_eventGetOrderId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesMarketOrderObject_GetOrderId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesMarketOrderObject_GetOrderId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesMarketOrderObject::execGetOrderId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGuid*)Z_Param__Result=P_THIS->GetOrderId();
	P_NATIVE_END;
}
// ********** End Class UEchoesMarketOrderObject Function GetOrderId *******************************

// ********** Begin Class UEchoesMarketOrderObject Function GetPrice *******************************
struct Z_Construct_UFunction_UEchoesMarketOrderObject_GetPrice_Statics
{
	struct EchoesMarketOrderObject_eventGetPrice_Parms
	{
		double ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Market|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the original price value\n\x09 * @return Price as double\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Logic/EchoesMarketOrderObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the original price value\n@return Price as double" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FDoublePropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UFunction_UEchoesMarketOrderObject_GetPrice_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMarketOrderObject_eventGetPrice_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesMarketOrderObject_GetPrice_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMarketOrderObject_GetPrice_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketOrderObject_GetPrice_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesMarketOrderObject_GetPrice_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesMarketOrderObject, nullptr, "GetPrice", Z_Construct_UFunction_UEchoesMarketOrderObject_GetPrice_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketOrderObject_GetPrice_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesMarketOrderObject_GetPrice_Statics::EchoesMarketOrderObject_eventGetPrice_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketOrderObject_GetPrice_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesMarketOrderObject_GetPrice_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesMarketOrderObject_GetPrice_Statics::EchoesMarketOrderObject_eventGetPrice_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesMarketOrderObject_GetPrice()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesMarketOrderObject_GetPrice_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesMarketOrderObject::execGetPrice)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(double*)Z_Param__Result=P_THIS->GetPrice();
	P_NATIVE_END;
}
// ********** End Class UEchoesMarketOrderObject Function GetPrice *********************************

// ********** Begin Class UEchoesMarketOrderObject Function GetRemainingQuantity *******************
struct Z_Construct_UFunction_UEchoesMarketOrderObject_GetRemainingQuantity_Statics
{
	struct EchoesMarketOrderObject_eventGetRemainingQuantity_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Market|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the remaining quantity\n\x09 * @return Remaining quantity available\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Logic/EchoesMarketOrderObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the remaining quantity\n@return Remaining quantity available" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UEchoesMarketOrderObject_GetRemainingQuantity_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMarketOrderObject_eventGetRemainingQuantity_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesMarketOrderObject_GetRemainingQuantity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMarketOrderObject_GetRemainingQuantity_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketOrderObject_GetRemainingQuantity_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesMarketOrderObject_GetRemainingQuantity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesMarketOrderObject, nullptr, "GetRemainingQuantity", Z_Construct_UFunction_UEchoesMarketOrderObject_GetRemainingQuantity_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketOrderObject_GetRemainingQuantity_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesMarketOrderObject_GetRemainingQuantity_Statics::EchoesMarketOrderObject_eventGetRemainingQuantity_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketOrderObject_GetRemainingQuantity_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesMarketOrderObject_GetRemainingQuantity_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesMarketOrderObject_GetRemainingQuantity_Statics::EchoesMarketOrderObject_eventGetRemainingQuantity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesMarketOrderObject_GetRemainingQuantity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesMarketOrderObject_GetRemainingQuantity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesMarketOrderObject::execGetRemainingQuantity)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetRemainingQuantity();
	P_NATIVE_END;
}
// ********** End Class UEchoesMarketOrderObject Function GetRemainingQuantity *********************

// ********** Begin Class UEchoesMarketOrderObject Function GetStationName *************************
struct Z_Construct_UFunction_UEchoesMarketOrderObject_GetStationName_Statics
{
	struct EchoesMarketOrderObject_eventGetStationName_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Market|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the station name\n\x09 * @return Station name where order is placed\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Logic/EchoesMarketOrderObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the station name\n@return Station name where order is placed" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEchoesMarketOrderObject_GetStationName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMarketOrderObject_eventGetStationName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesMarketOrderObject_GetStationName_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMarketOrderObject_GetStationName_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketOrderObject_GetStationName_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesMarketOrderObject_GetStationName_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesMarketOrderObject, nullptr, "GetStationName", Z_Construct_UFunction_UEchoesMarketOrderObject_GetStationName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketOrderObject_GetStationName_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesMarketOrderObject_GetStationName_Statics::EchoesMarketOrderObject_eventGetStationName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketOrderObject_GetStationName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesMarketOrderObject_GetStationName_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesMarketOrderObject_GetStationName_Statics::EchoesMarketOrderObject_eventGetStationName_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesMarketOrderObject_GetStationName()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesMarketOrderObject_GetStationName_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesMarketOrderObject::execGetStationName)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GetStationName();
	P_NATIVE_END;
}
// ********** End Class UEchoesMarketOrderObject Function GetStationName ***************************

// ********** Begin Class UEchoesMarketOrderObject Function InitializeWithData *********************
struct Z_Construct_UFunction_UEchoesMarketOrderObject_InitializeWithData_Statics
{
	struct EchoesMarketOrderObject_eventInitializeWithData_Parms
	{
		FMarketOrderDto InOrderData;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Market|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Initialize the object with market order data\n\x09 * @param InOrderData - The market order data to wrap\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Logic/EchoesMarketOrderObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Initialize the object with market order data\n@param InOrderData - The market order data to wrap" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InOrderData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_InOrderData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesMarketOrderObject_InitializeWithData_Statics::NewProp_InOrderData = { "InOrderData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMarketOrderObject_eventInitializeWithData_Parms, InOrderData), Z_Construct_UScriptStruct_FMarketOrderDto, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InOrderData_MetaData), NewProp_InOrderData_MetaData) }; // 449536635
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesMarketOrderObject_InitializeWithData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMarketOrderObject_InitializeWithData_Statics::NewProp_InOrderData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketOrderObject_InitializeWithData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesMarketOrderObject_InitializeWithData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesMarketOrderObject, nullptr, "InitializeWithData", Z_Construct_UFunction_UEchoesMarketOrderObject_InitializeWithData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketOrderObject_InitializeWithData_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesMarketOrderObject_InitializeWithData_Statics::EchoesMarketOrderObject_eventInitializeWithData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketOrderObject_InitializeWithData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesMarketOrderObject_InitializeWithData_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesMarketOrderObject_InitializeWithData_Statics::EchoesMarketOrderObject_eventInitializeWithData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesMarketOrderObject_InitializeWithData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesMarketOrderObject_InitializeWithData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesMarketOrderObject::execInitializeWithData)
{
	P_GET_STRUCT_REF(FMarketOrderDto,Z_Param_Out_InOrderData);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializeWithData(Z_Param_Out_InOrderData);
	P_NATIVE_END;
}
// ********** End Class UEchoesMarketOrderObject Function InitializeWithData ***********************

// ********** Begin Class UEchoesMarketOrderObject Function IsBuyOrder *****************************
struct Z_Construct_UFunction_UEchoesMarketOrderObject_IsBuyOrder_Statics
{
	struct EchoesMarketOrderObject_eventIsBuyOrder_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Market|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if this is a buy order\n\x09 * @return True if buy order, false if sell\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Logic/EchoesMarketOrderObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if this is a buy order\n@return True if buy order, false if sell" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UEchoesMarketOrderObject_IsBuyOrder_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((EchoesMarketOrderObject_eventIsBuyOrder_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UEchoesMarketOrderObject_IsBuyOrder_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EchoesMarketOrderObject_eventIsBuyOrder_Parms), &Z_Construct_UFunction_UEchoesMarketOrderObject_IsBuyOrder_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesMarketOrderObject_IsBuyOrder_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMarketOrderObject_IsBuyOrder_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketOrderObject_IsBuyOrder_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesMarketOrderObject_IsBuyOrder_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesMarketOrderObject, nullptr, "IsBuyOrder", Z_Construct_UFunction_UEchoesMarketOrderObject_IsBuyOrder_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketOrderObject_IsBuyOrder_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesMarketOrderObject_IsBuyOrder_Statics::EchoesMarketOrderObject_eventIsBuyOrder_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketOrderObject_IsBuyOrder_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesMarketOrderObject_IsBuyOrder_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesMarketOrderObject_IsBuyOrder_Statics::EchoesMarketOrderObject_eventIsBuyOrder_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesMarketOrderObject_IsBuyOrder()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesMarketOrderObject_IsBuyOrder_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesMarketOrderObject::execIsBuyOrder)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsBuyOrder();
	P_NATIVE_END;
}
// ********** End Class UEchoesMarketOrderObject Function IsBuyOrder *******************************

// ********** Begin Class UEchoesMarketOrderObject *************************************************
void UEchoesMarketOrderObject::StaticRegisterNativesUEchoesMarketOrderObject()
{
	UClass* Class = UEchoesMarketOrderObject::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetFormattedIssuedTime", &UEchoesMarketOrderObject::execGetFormattedIssuedTime },
		{ "GetFormattedPrice", &UEchoesMarketOrderObject::execGetFormattedPrice },
		{ "GetItemId", &UEchoesMarketOrderObject::execGetItemId },
		{ "GetOrderData", &UEchoesMarketOrderObject::execGetOrderData },
		{ "GetOrderId", &UEchoesMarketOrderObject::execGetOrderId },
		{ "GetPrice", &UEchoesMarketOrderObject::execGetPrice },
		{ "GetRemainingQuantity", &UEchoesMarketOrderObject::execGetRemainingQuantity },
		{ "GetStationName", &UEchoesMarketOrderObject::execGetStationName },
		{ "InitializeWithData", &UEchoesMarketOrderObject::execInitializeWithData },
		{ "IsBuyOrder", &UEchoesMarketOrderObject::execIsBuyOrder },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UEchoesMarketOrderObject;
UClass* UEchoesMarketOrderObject::GetPrivateStaticClass()
{
	using TClass = UEchoesMarketOrderObject;
	if (!Z_Registration_Info_UClass_UEchoesMarketOrderObject.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesMarketOrderObject"),
			Z_Registration_Info_UClass_UEchoesMarketOrderObject.InnerSingleton,
			StaticRegisterNativesUEchoesMarketOrderObject,
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
	return Z_Registration_Info_UClass_UEchoesMarketOrderObject.InnerSingleton;
}
UClass* Z_Construct_UClass_UEchoesMarketOrderObject_NoRegister()
{
	return UEchoesMarketOrderObject::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UEchoesMarketOrderObject_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * UEchoesMarketOrderObject\n * \n * Data wrapper for FMarketOrderDto to be used with UListView\n * Wraps the market order struct so it can be used with UMG ListView (Entry Widget pooling)\n * Allows displaying thousands of orders without FPS drops\n * \n * Usage:\n * - Create instances for each order in the order book\n * - Add to ListView as items\n * - OrderEntryWidget retrieves data via getter methods\n */" },
#endif
		{ "IncludePath", "UI/Logic/EchoesMarketOrderObject.h" },
		{ "ModuleRelativePath", "UI/Logic/EchoesMarketOrderObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UEchoesMarketOrderObject\n\nData wrapper for FMarketOrderDto to be used with UListView\nWraps the market order struct so it can be used with UMG ListView (Entry Widget pooling)\nAllows displaying thousands of orders without FPS drops\n\nUsage:\n- Create instances for each order in the order book\n- Add to ListView as items\n- OrderEntryWidget retrieves data via getter methods" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OrderData_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The wrapped market order data */" },
#endif
		{ "ModuleRelativePath", "UI/Logic/EchoesMarketOrderObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The wrapped market order data" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_OrderData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UEchoesMarketOrderObject_GetFormattedIssuedTime, "GetFormattedIssuedTime" }, // 1079029277
		{ &Z_Construct_UFunction_UEchoesMarketOrderObject_GetFormattedPrice, "GetFormattedPrice" }, // 2115885225
		{ &Z_Construct_UFunction_UEchoesMarketOrderObject_GetItemId, "GetItemId" }, // 1979121247
		{ &Z_Construct_UFunction_UEchoesMarketOrderObject_GetOrderData, "GetOrderData" }, // 3446335162
		{ &Z_Construct_UFunction_UEchoesMarketOrderObject_GetOrderId, "GetOrderId" }, // 2581256271
		{ &Z_Construct_UFunction_UEchoesMarketOrderObject_GetPrice, "GetPrice" }, // 2265124468
		{ &Z_Construct_UFunction_UEchoesMarketOrderObject_GetRemainingQuantity, "GetRemainingQuantity" }, // 802795624
		{ &Z_Construct_UFunction_UEchoesMarketOrderObject_GetStationName, "GetStationName" }, // 2275126119
		{ &Z_Construct_UFunction_UEchoesMarketOrderObject_InitializeWithData, "InitializeWithData" }, // 1567416524
		{ &Z_Construct_UFunction_UEchoesMarketOrderObject_IsBuyOrder, "IsBuyOrder" }, // 3686447130
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEchoesMarketOrderObject>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEchoesMarketOrderObject_Statics::NewProp_OrderData = { "OrderData", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesMarketOrderObject, OrderData), Z_Construct_UScriptStruct_FMarketOrderDto, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OrderData_MetaData), NewProp_OrderData_MetaData) }; // 449536635
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEchoesMarketOrderObject_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMarketOrderObject_Statics::NewProp_OrderData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesMarketOrderObject_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UEchoesMarketOrderObject_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesMarketOrderObject_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEchoesMarketOrderObject_Statics::ClassParams = {
	&UEchoesMarketOrderObject::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UEchoesMarketOrderObject_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesMarketOrderObject_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesMarketOrderObject_Statics::Class_MetaDataParams), Z_Construct_UClass_UEchoesMarketOrderObject_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEchoesMarketOrderObject()
{
	if (!Z_Registration_Info_UClass_UEchoesMarketOrderObject.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEchoesMarketOrderObject.OuterSingleton, Z_Construct_UClass_UEchoesMarketOrderObject_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEchoesMarketOrderObject.OuterSingleton;
}
UEchoesMarketOrderObject::UEchoesMarketOrderObject(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UEchoesMarketOrderObject);
UEchoesMarketOrderObject::~UEchoesMarketOrderObject() {}
// ********** End Class UEchoesMarketOrderObject ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Logic_EchoesMarketOrderObject_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEchoesMarketOrderObject, UEchoesMarketOrderObject::StaticClass, TEXT("UEchoesMarketOrderObject"), &Z_Registration_Info_UClass_UEchoesMarketOrderObject, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEchoesMarketOrderObject), 3308213681U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Logic_EchoesMarketOrderObject_h__Script_Echoes_4263674073(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Logic_EchoesMarketOrderObject_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Logic_EchoesMarketOrderObject_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
