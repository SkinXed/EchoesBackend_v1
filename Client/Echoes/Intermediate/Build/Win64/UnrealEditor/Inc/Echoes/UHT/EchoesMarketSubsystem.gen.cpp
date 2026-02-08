// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EchoesMarketSubsystem.h"
#include "EchoesMarketStructures.h"
#include "Engine/GameInstance.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesMarketSubsystem() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ECHOES_API UClass* Z_Construct_UClass_UEchoesMarketSubsystem();
ECHOES_API UClass* Z_Construct_UClass_UEchoesMarketSubsystem_NoRegister();
ECHOES_API UEnum* Z_Construct_UEnum_Echoes_EMarketTransactionState();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnMarketDataReceived__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnMarketInventorySyncRequired__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnMarketOrderCancelled__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnMarketOrderCreated__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnMarketRequestFailed__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnMarketTradeExecuted__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnTradeConfirmed__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnTradeError__DelegateSignature();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FMarketFilter();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FMarketOrderDto();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FMarketTradeResult();
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FOnMarketDataReceived *************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnMarketDataReceived__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnMarketDataReceived_Parms
	{
		TArray<FMarketOrderDto> Orders;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when market order data is received from the backend */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesMarketSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when market order data is received from the backend" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Orders_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Orders_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Orders;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_Echoes_OnMarketDataReceived__DelegateSignature_Statics::NewProp_Orders_Inner = { "Orders", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FMarketOrderDto, METADATA_PARAMS(0, nullptr) }; // 449536635
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UDelegateFunction_Echoes_OnMarketDataReceived__DelegateSignature_Statics::NewProp_Orders = { "Orders", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnMarketDataReceived_Parms, Orders), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Orders_MetaData), NewProp_Orders_MetaData) }; // 449536635
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnMarketDataReceived__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnMarketDataReceived__DelegateSignature_Statics::NewProp_Orders_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnMarketDataReceived__DelegateSignature_Statics::NewProp_Orders,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnMarketDataReceived__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnMarketDataReceived__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnMarketDataReceived__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnMarketDataReceived__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnMarketDataReceived__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnMarketDataReceived__DelegateSignature_Statics::_Script_Echoes_eventOnMarketDataReceived_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnMarketDataReceived__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnMarketDataReceived__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnMarketDataReceived__DelegateSignature_Statics::_Script_Echoes_eventOnMarketDataReceived_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnMarketDataReceived__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnMarketDataReceived__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnMarketDataReceived_DelegateWrapper(const FMulticastScriptDelegate& OnMarketDataReceived, TArray<FMarketOrderDto> const& Orders)
{
	struct _Script_Echoes_eventOnMarketDataReceived_Parms
	{
		TArray<FMarketOrderDto> Orders;
	};
	_Script_Echoes_eventOnMarketDataReceived_Parms Parms;
	Parms.Orders=Orders;
	OnMarketDataReceived.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnMarketDataReceived ***************************************************

// ********** Begin Delegate FOnMarketRequestFailed ************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnMarketRequestFailed__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnMarketRequestFailed_Parms
	{
		FString ErrorMessage;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when a market API request fails */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesMarketSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when a market API request fails" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_Echoes_OnMarketRequestFailed__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnMarketRequestFailed_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ErrorMessage_MetaData), NewProp_ErrorMessage_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnMarketRequestFailed__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnMarketRequestFailed__DelegateSignature_Statics::NewProp_ErrorMessage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnMarketRequestFailed__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnMarketRequestFailed__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnMarketRequestFailed__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnMarketRequestFailed__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnMarketRequestFailed__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnMarketRequestFailed__DelegateSignature_Statics::_Script_Echoes_eventOnMarketRequestFailed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnMarketRequestFailed__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnMarketRequestFailed__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnMarketRequestFailed__DelegateSignature_Statics::_Script_Echoes_eventOnMarketRequestFailed_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnMarketRequestFailed__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnMarketRequestFailed__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnMarketRequestFailed_DelegateWrapper(const FMulticastScriptDelegate& OnMarketRequestFailed, const FString& ErrorMessage)
{
	struct _Script_Echoes_eventOnMarketRequestFailed_Parms
	{
		FString ErrorMessage;
	};
	_Script_Echoes_eventOnMarketRequestFailed_Parms Parms;
	Parms.ErrorMessage=ErrorMessage;
	OnMarketRequestFailed.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnMarketRequestFailed **************************************************

// ********** Begin Delegate FOnMarketOrderCreated *************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnMarketOrderCreated__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnMarketOrderCreated_Parms
	{
		FGuid OrderId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when an order is successfully created */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesMarketSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when an order is successfully created" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OrderId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_OrderId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_Echoes_OnMarketOrderCreated__DelegateSignature_Statics::NewProp_OrderId = { "OrderId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnMarketOrderCreated_Parms, OrderId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OrderId_MetaData), NewProp_OrderId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnMarketOrderCreated__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnMarketOrderCreated__DelegateSignature_Statics::NewProp_OrderId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnMarketOrderCreated__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnMarketOrderCreated__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnMarketOrderCreated__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnMarketOrderCreated__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnMarketOrderCreated__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnMarketOrderCreated__DelegateSignature_Statics::_Script_Echoes_eventOnMarketOrderCreated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnMarketOrderCreated__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnMarketOrderCreated__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnMarketOrderCreated__DelegateSignature_Statics::_Script_Echoes_eventOnMarketOrderCreated_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnMarketOrderCreated__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnMarketOrderCreated__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnMarketOrderCreated_DelegateWrapper(const FMulticastScriptDelegate& OnMarketOrderCreated, FGuid const& OrderId)
{
	struct _Script_Echoes_eventOnMarketOrderCreated_Parms
	{
		FGuid OrderId;
	};
	_Script_Echoes_eventOnMarketOrderCreated_Parms Parms;
	Parms.OrderId=OrderId;
	OnMarketOrderCreated.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnMarketOrderCreated ***************************************************

// ********** Begin Delegate FOnMarketTradeExecuted ************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnMarketTradeExecuted__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnMarketTradeExecuted_Parms
	{
		FGuid OrderId;
		int32 QuantityTraded;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when a trade is successfully executed (detailed result for UI/inventory sync) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesMarketSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when a trade is successfully executed (detailed result for UI/inventory sync)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OrderId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_OrderId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_QuantityTraded;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_Echoes_OnMarketTradeExecuted__DelegateSignature_Statics::NewProp_OrderId = { "OrderId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnMarketTradeExecuted_Parms, OrderId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OrderId_MetaData), NewProp_OrderId_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_Echoes_OnMarketTradeExecuted__DelegateSignature_Statics::NewProp_QuantityTraded = { "QuantityTraded", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnMarketTradeExecuted_Parms, QuantityTraded), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnMarketTradeExecuted__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnMarketTradeExecuted__DelegateSignature_Statics::NewProp_OrderId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnMarketTradeExecuted__DelegateSignature_Statics::NewProp_QuantityTraded,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnMarketTradeExecuted__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnMarketTradeExecuted__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnMarketTradeExecuted__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnMarketTradeExecuted__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnMarketTradeExecuted__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnMarketTradeExecuted__DelegateSignature_Statics::_Script_Echoes_eventOnMarketTradeExecuted_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnMarketTradeExecuted__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnMarketTradeExecuted__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnMarketTradeExecuted__DelegateSignature_Statics::_Script_Echoes_eventOnMarketTradeExecuted_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnMarketTradeExecuted__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnMarketTradeExecuted__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnMarketTradeExecuted_DelegateWrapper(const FMulticastScriptDelegate& OnMarketTradeExecuted, FGuid const& OrderId, int32 QuantityTraded)
{
	struct _Script_Echoes_eventOnMarketTradeExecuted_Parms
	{
		FGuid OrderId;
		int32 QuantityTraded;
	};
	_Script_Echoes_eventOnMarketTradeExecuted_Parms Parms;
	Parms.OrderId=OrderId;
	Parms.QuantityTraded=QuantityTraded;
	OnMarketTradeExecuted.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnMarketTradeExecuted **************************************************

// ********** Begin Delegate FOnTradeConfirmed *****************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnTradeConfirmed__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnTradeConfirmed_Parms
	{
		FMarketTradeResult TradeResult;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when a trade is confirmed with full result data (for toast notification and inventory sync) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesMarketSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when a trade is confirmed with full result data (for toast notification and inventory sync)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TradeResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_TradeResult;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_Echoes_OnTradeConfirmed__DelegateSignature_Statics::NewProp_TradeResult = { "TradeResult", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnTradeConfirmed_Parms, TradeResult), Z_Construct_UScriptStruct_FMarketTradeResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TradeResult_MetaData), NewProp_TradeResult_MetaData) }; // 4107301343
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnTradeConfirmed__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnTradeConfirmed__DelegateSignature_Statics::NewProp_TradeResult,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnTradeConfirmed__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnTradeConfirmed__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnTradeConfirmed__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnTradeConfirmed__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnTradeConfirmed__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnTradeConfirmed__DelegateSignature_Statics::_Script_Echoes_eventOnTradeConfirmed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnTradeConfirmed__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnTradeConfirmed__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnTradeConfirmed__DelegateSignature_Statics::_Script_Echoes_eventOnTradeConfirmed_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnTradeConfirmed__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnTradeConfirmed__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnTradeConfirmed_DelegateWrapper(const FMulticastScriptDelegate& OnTradeConfirmed, FMarketTradeResult const& TradeResult)
{
	struct _Script_Echoes_eventOnTradeConfirmed_Parms
	{
		FMarketTradeResult TradeResult;
	};
	_Script_Echoes_eventOnTradeConfirmed_Parms Parms;
	Parms.TradeResult=TradeResult;
	OnTradeConfirmed.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnTradeConfirmed *******************************************************

// ********** Begin Delegate FOnTradeError *********************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnTradeError__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnTradeError_Parms
	{
		int32 HttpStatusCode;
		FString ErrorMessage;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when a trade fails with error details */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesMarketSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when a trade fails with error details" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_HttpStatusCode;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_Echoes_OnTradeError__DelegateSignature_Statics::NewProp_HttpStatusCode = { "HttpStatusCode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnTradeError_Parms, HttpStatusCode), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_Echoes_OnTradeError__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnTradeError_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ErrorMessage_MetaData), NewProp_ErrorMessage_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnTradeError__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnTradeError__DelegateSignature_Statics::NewProp_HttpStatusCode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnTradeError__DelegateSignature_Statics::NewProp_ErrorMessage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnTradeError__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnTradeError__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnTradeError__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnTradeError__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnTradeError__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnTradeError__DelegateSignature_Statics::_Script_Echoes_eventOnTradeError_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnTradeError__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnTradeError__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnTradeError__DelegateSignature_Statics::_Script_Echoes_eventOnTradeError_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnTradeError__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnTradeError__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnTradeError_DelegateWrapper(const FMulticastScriptDelegate& OnTradeError, int32 HttpStatusCode, const FString& ErrorMessage)
{
	struct _Script_Echoes_eventOnTradeError_Parms
	{
		int32 HttpStatusCode;
		FString ErrorMessage;
	};
	_Script_Echoes_eventOnTradeError_Parms Parms;
	Parms.HttpStatusCode=HttpStatusCode;
	Parms.ErrorMessage=ErrorMessage;
	OnTradeError.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnTradeError ***********************************************************

// ********** Begin Delegate FOnMarketOrderCancelled ***********************************************
struct Z_Construct_UDelegateFunction_Echoes_OnMarketOrderCancelled__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnMarketOrderCancelled_Parms
	{
		FGuid OrderId;
		double EscrowRefunded;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when an order is successfully cancelled */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesMarketSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when an order is successfully cancelled" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OrderId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_OrderId;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_EscrowRefunded;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_Echoes_OnMarketOrderCancelled__DelegateSignature_Statics::NewProp_OrderId = { "OrderId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnMarketOrderCancelled_Parms, OrderId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OrderId_MetaData), NewProp_OrderId_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UDelegateFunction_Echoes_OnMarketOrderCancelled__DelegateSignature_Statics::NewProp_EscrowRefunded = { "EscrowRefunded", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnMarketOrderCancelled_Parms, EscrowRefunded), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnMarketOrderCancelled__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnMarketOrderCancelled__DelegateSignature_Statics::NewProp_OrderId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnMarketOrderCancelled__DelegateSignature_Statics::NewProp_EscrowRefunded,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnMarketOrderCancelled__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnMarketOrderCancelled__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnMarketOrderCancelled__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnMarketOrderCancelled__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnMarketOrderCancelled__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnMarketOrderCancelled__DelegateSignature_Statics::_Script_Echoes_eventOnMarketOrderCancelled_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnMarketOrderCancelled__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnMarketOrderCancelled__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnMarketOrderCancelled__DelegateSignature_Statics::_Script_Echoes_eventOnMarketOrderCancelled_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnMarketOrderCancelled__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnMarketOrderCancelled__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnMarketOrderCancelled_DelegateWrapper(const FMulticastScriptDelegate& OnMarketOrderCancelled, FGuid const& OrderId, double EscrowRefunded)
{
	struct _Script_Echoes_eventOnMarketOrderCancelled_Parms
	{
		FGuid OrderId;
		double EscrowRefunded;
	};
	_Script_Echoes_eventOnMarketOrderCancelled_Parms Parms;
	Parms.OrderId=OrderId;
	Parms.EscrowRefunded=EscrowRefunded;
	OnMarketOrderCancelled.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnMarketOrderCancelled *************************************************

// ********** Begin Delegate FOnMarketInventorySyncRequired ****************************************
struct Z_Construct_UDelegateFunction_Echoes_OnMarketInventorySyncRequired__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnMarketInventorySyncRequired_Parms
	{
		FGuid CharacterId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when inventory/wallet sync is needed after a trade */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesMarketSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when inventory/wallet sync is needed after a trade" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_CharacterId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_Echoes_OnMarketInventorySyncRequired__DelegateSignature_Statics::NewProp_CharacterId = { "CharacterId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnMarketInventorySyncRequired_Parms, CharacterId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterId_MetaData), NewProp_CharacterId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnMarketInventorySyncRequired__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnMarketInventorySyncRequired__DelegateSignature_Statics::NewProp_CharacterId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnMarketInventorySyncRequired__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnMarketInventorySyncRequired__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnMarketInventorySyncRequired__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnMarketInventorySyncRequired__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnMarketInventorySyncRequired__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnMarketInventorySyncRequired__DelegateSignature_Statics::_Script_Echoes_eventOnMarketInventorySyncRequired_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnMarketInventorySyncRequired__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnMarketInventorySyncRequired__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnMarketInventorySyncRequired__DelegateSignature_Statics::_Script_Echoes_eventOnMarketInventorySyncRequired_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnMarketInventorySyncRequired__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnMarketInventorySyncRequired__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnMarketInventorySyncRequired_DelegateWrapper(const FMulticastScriptDelegate& OnMarketInventorySyncRequired, FGuid const& CharacterId)
{
	struct _Script_Echoes_eventOnMarketInventorySyncRequired_Parms
	{
		FGuid CharacterId;
	};
	_Script_Echoes_eventOnMarketInventorySyncRequired_Parms Parms;
	Parms.CharacterId=CharacterId;
	OnMarketInventorySyncRequired.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnMarketInventorySyncRequired ******************************************

// ********** Begin Class UEchoesMarketSubsystem Function GetCachedMarketOrders ********************
struct Z_Construct_UFunction_UEchoesMarketSubsystem_GetCachedMarketOrders_Statics
{
	struct EchoesMarketSubsystem_eventGetCachedMarketOrders_Parms
	{
		TArray<FMarketOrderDto> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Market" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get cached market orders (avoids re-fetching on each UI open)\n\x09 * @return Last fetched array of market orders\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesMarketSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get cached market orders (avoids re-fetching on each UI open)\n@return Last fetched array of market orders" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesMarketSubsystem_GetCachedMarketOrders_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FMarketOrderDto, METADATA_PARAMS(0, nullptr) }; // 449536635
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UEchoesMarketSubsystem_GetCachedMarketOrders_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMarketSubsystem_eventGetCachedMarketOrders_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 449536635
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesMarketSubsystem_GetCachedMarketOrders_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMarketSubsystem_GetCachedMarketOrders_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMarketSubsystem_GetCachedMarketOrders_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketSubsystem_GetCachedMarketOrders_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesMarketSubsystem_GetCachedMarketOrders_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesMarketSubsystem, nullptr, "GetCachedMarketOrders", Z_Construct_UFunction_UEchoesMarketSubsystem_GetCachedMarketOrders_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketSubsystem_GetCachedMarketOrders_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesMarketSubsystem_GetCachedMarketOrders_Statics::EchoesMarketSubsystem_eventGetCachedMarketOrders_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketSubsystem_GetCachedMarketOrders_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesMarketSubsystem_GetCachedMarketOrders_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesMarketSubsystem_GetCachedMarketOrders_Statics::EchoesMarketSubsystem_eventGetCachedMarketOrders_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesMarketSubsystem_GetCachedMarketOrders()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesMarketSubsystem_GetCachedMarketOrders_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesMarketSubsystem::execGetCachedMarketOrders)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FMarketOrderDto>*)Z_Param__Result=P_THIS->GetCachedMarketOrders();
	P_NATIVE_END;
}
// ********** End Class UEchoesMarketSubsystem Function GetCachedMarketOrders **********************

// ********** Begin Class UEchoesMarketSubsystem Function GetTransactionState **********************
struct Z_Construct_UFunction_UEchoesMarketSubsystem_GetTransactionState_Statics
{
	struct EchoesMarketSubsystem_eventGetTransactionState_Parms
	{
		EMarketTransactionState ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Market" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the current trade transaction state\n\x09 * @return Current state (Idle, InFlight, UnknownState)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesMarketSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the current trade transaction state\n@return Current state (Idle, InFlight, UnknownState)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UEchoesMarketSubsystem_GetTransactionState_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UEchoesMarketSubsystem_GetTransactionState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMarketSubsystem_eventGetTransactionState_Parms, ReturnValue), Z_Construct_UEnum_Echoes_EMarketTransactionState, METADATA_PARAMS(0, nullptr) }; // 3706960494
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesMarketSubsystem_GetTransactionState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMarketSubsystem_GetTransactionState_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMarketSubsystem_GetTransactionState_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketSubsystem_GetTransactionState_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesMarketSubsystem_GetTransactionState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesMarketSubsystem, nullptr, "GetTransactionState", Z_Construct_UFunction_UEchoesMarketSubsystem_GetTransactionState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketSubsystem_GetTransactionState_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesMarketSubsystem_GetTransactionState_Statics::EchoesMarketSubsystem_eventGetTransactionState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketSubsystem_GetTransactionState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesMarketSubsystem_GetTransactionState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesMarketSubsystem_GetTransactionState_Statics::EchoesMarketSubsystem_eventGetTransactionState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesMarketSubsystem_GetTransactionState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesMarketSubsystem_GetTransactionState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesMarketSubsystem::execGetTransactionState)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EMarketTransactionState*)Z_Param__Result=P_THIS->GetTransactionState();
	P_NATIVE_END;
}
// ********** End Class UEchoesMarketSubsystem Function GetTransactionState ************************

// ********** Begin Class UEchoesMarketSubsystem Function IsCacheValid *****************************
struct Z_Construct_UFunction_UEchoesMarketSubsystem_IsCacheValid_Statics
{
	struct EchoesMarketSubsystem_eventIsCacheValid_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Market" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if cached data is still valid\n\x09 * @return True if cache exists and has not expired\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesMarketSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if cached data is still valid\n@return True if cache exists and has not expired" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UEchoesMarketSubsystem_IsCacheValid_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((EchoesMarketSubsystem_eventIsCacheValid_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UEchoesMarketSubsystem_IsCacheValid_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EchoesMarketSubsystem_eventIsCacheValid_Parms), &Z_Construct_UFunction_UEchoesMarketSubsystem_IsCacheValid_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesMarketSubsystem_IsCacheValid_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMarketSubsystem_IsCacheValid_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketSubsystem_IsCacheValid_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesMarketSubsystem_IsCacheValid_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesMarketSubsystem, nullptr, "IsCacheValid", Z_Construct_UFunction_UEchoesMarketSubsystem_IsCacheValid_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketSubsystem_IsCacheValid_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesMarketSubsystem_IsCacheValid_Statics::EchoesMarketSubsystem_eventIsCacheValid_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketSubsystem_IsCacheValid_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesMarketSubsystem_IsCacheValid_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesMarketSubsystem_IsCacheValid_Statics::EchoesMarketSubsystem_eventIsCacheValid_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesMarketSubsystem_IsCacheValid()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesMarketSubsystem_IsCacheValid_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesMarketSubsystem::execIsCacheValid)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsCacheValid();
	P_NATIVE_END;
}
// ********** End Class UEchoesMarketSubsystem Function IsCacheValid *******************************

// ********** Begin Class UEchoesMarketSubsystem Function ResetTransactionState ********************
struct Z_Construct_UFunction_UEchoesMarketSubsystem_ResetTransactionState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Market" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Reset transaction state to Idle (use after confirming wallet sync in UnknownState)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesMarketSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Reset transaction state to Idle (use after confirming wallet sync in UnknownState)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesMarketSubsystem_ResetTransactionState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesMarketSubsystem, nullptr, "ResetTransactionState", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketSubsystem_ResetTransactionState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesMarketSubsystem_ResetTransactionState_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesMarketSubsystem_ResetTransactionState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesMarketSubsystem_ResetTransactionState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesMarketSubsystem::execResetTransactionState)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ResetTransactionState();
	P_NATIVE_END;
}
// ********** End Class UEchoesMarketSubsystem Function ResetTransactionState **********************

// ********** Begin Class UEchoesMarketSubsystem Function ServerOnly_CancelOrder *******************
struct Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_CancelOrder_Statics
{
	struct EchoesMarketSubsystem_eventServerOnly_CancelOrder_Parms
	{
		FGuid OrderId;
		FGuid CharacterId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Market" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Cancel an active market order\n\x09 * Sends HTTP DELETE to /api/market/orders/{orderId}?characterId={characterId}\n\x09 * Refunds remaining escrow for buy orders\n\x09 * \n\x09 * @param OrderId - ID of the order to cancel\n\x09 * @param CharacterId - ID of the character who owns the order\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesMarketSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cancel an active market order\nSends HTTP DELETE to /api/market/orders/{orderId}?characterId={characterId}\nRefunds remaining escrow for buy orders\n\n@param OrderId - ID of the order to cancel\n@param CharacterId - ID of the character who owns the order" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OrderId_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_OrderId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CharacterId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_CancelOrder_Statics::NewProp_OrderId = { "OrderId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMarketSubsystem_eventServerOnly_CancelOrder_Parms, OrderId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OrderId_MetaData), NewProp_OrderId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_CancelOrder_Statics::NewProp_CharacterId = { "CharacterId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMarketSubsystem_eventServerOnly_CancelOrder_Parms, CharacterId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterId_MetaData), NewProp_CharacterId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_CancelOrder_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_CancelOrder_Statics::NewProp_OrderId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_CancelOrder_Statics::NewProp_CharacterId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_CancelOrder_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_CancelOrder_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesMarketSubsystem, nullptr, "ServerOnly_CancelOrder", Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_CancelOrder_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_CancelOrder_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_CancelOrder_Statics::EchoesMarketSubsystem_eventServerOnly_CancelOrder_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_CancelOrder_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_CancelOrder_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_CancelOrder_Statics::EchoesMarketSubsystem_eventServerOnly_CancelOrder_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_CancelOrder()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_CancelOrder_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesMarketSubsystem::execServerOnly_CancelOrder)
{
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_OrderId);
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_CharacterId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerOnly_CancelOrder(Z_Param_Out_OrderId,Z_Param_Out_CharacterId);
	P_NATIVE_END;
}
// ********** End Class UEchoesMarketSubsystem Function ServerOnly_CancelOrder *********************

// ********** Begin Class UEchoesMarketSubsystem Function ServerOnly_CreateOrder *******************
struct Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_CreateOrder_Statics
{
	struct EchoesMarketSubsystem_eventServerOnly_CreateOrder_Parms
	{
		FMarketOrderDto NewOrder;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Market" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Create a new market order (buy or sell)\n\x09 * Sends HTTP POST to /api/market/orders\n\x09 * \n\x09 * @param NewOrder - Order details (CharacterId, ItemId, IsBuyOrder, Price, Quantity, StationId)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesMarketSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Create a new market order (buy or sell)\nSends HTTP POST to /api/market/orders\n\n@param NewOrder - Order details (CharacterId, ItemId, IsBuyOrder, Price, Quantity, StationId)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NewOrder_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_NewOrder;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_CreateOrder_Statics::NewProp_NewOrder = { "NewOrder", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMarketSubsystem_eventServerOnly_CreateOrder_Parms, NewOrder), Z_Construct_UScriptStruct_FMarketOrderDto, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NewOrder_MetaData), NewProp_NewOrder_MetaData) }; // 449536635
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_CreateOrder_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_CreateOrder_Statics::NewProp_NewOrder,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_CreateOrder_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_CreateOrder_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesMarketSubsystem, nullptr, "ServerOnly_CreateOrder", Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_CreateOrder_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_CreateOrder_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_CreateOrder_Statics::EchoesMarketSubsystem_eventServerOnly_CreateOrder_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_CreateOrder_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_CreateOrder_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_CreateOrder_Statics::EchoesMarketSubsystem_eventServerOnly_CreateOrder_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_CreateOrder()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_CreateOrder_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesMarketSubsystem::execServerOnly_CreateOrder)
{
	P_GET_STRUCT_REF(FMarketOrderDto,Z_Param_Out_NewOrder);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerOnly_CreateOrder(Z_Param_Out_NewOrder);
	P_NATIVE_END;
}
// ********** End Class UEchoesMarketSubsystem Function ServerOnly_CreateOrder *********************

// ********** Begin Class UEchoesMarketSubsystem Function ServerOnly_ExecuteTrade ******************
struct Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_ExecuteTrade_Statics
{
	struct EchoesMarketSubsystem_eventServerOnly_ExecuteTrade_Parms
	{
		FGuid CharacterId;
		FGuid OrderId;
		int32 Quantity;
		FGuid CurrentStationId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Market" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Execute a trade on an existing market order\n\x09 * Sends HTTP POST to /api/market/execute\n\x09 * Includes CharacterId and CurrentStationId for backend validation\n\x09 * Prevents duplicate requests while a trade is in flight\n\x09 * \n\x09 * @param CharacterId - Character performing the trade\n\x09 * @param OrderId - ID of the order to trade against\n\x09 * @param Quantity - Number of items to buy/sell\n\x09 * @param CurrentStationId - Station where player is currently docked (for location validation)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesMarketSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Execute a trade on an existing market order\nSends HTTP POST to /api/market/execute\nIncludes CharacterId and CurrentStationId for backend validation\nPrevents duplicate requests while a trade is in flight\n\n@param CharacterId - Character performing the trade\n@param OrderId - ID of the order to trade against\n@param Quantity - Number of items to buy/sell\n@param CurrentStationId - Station where player is currently docked (for location validation)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterId_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OrderId_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentStationId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_CharacterId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OrderId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Quantity;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentStationId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_ExecuteTrade_Statics::NewProp_CharacterId = { "CharacterId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMarketSubsystem_eventServerOnly_ExecuteTrade_Parms, CharacterId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterId_MetaData), NewProp_CharacterId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_ExecuteTrade_Statics::NewProp_OrderId = { "OrderId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMarketSubsystem_eventServerOnly_ExecuteTrade_Parms, OrderId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OrderId_MetaData), NewProp_OrderId_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_ExecuteTrade_Statics::NewProp_Quantity = { "Quantity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMarketSubsystem_eventServerOnly_ExecuteTrade_Parms, Quantity), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_ExecuteTrade_Statics::NewProp_CurrentStationId = { "CurrentStationId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMarketSubsystem_eventServerOnly_ExecuteTrade_Parms, CurrentStationId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentStationId_MetaData), NewProp_CurrentStationId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_ExecuteTrade_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_ExecuteTrade_Statics::NewProp_CharacterId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_ExecuteTrade_Statics::NewProp_OrderId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_ExecuteTrade_Statics::NewProp_Quantity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_ExecuteTrade_Statics::NewProp_CurrentStationId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_ExecuteTrade_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_ExecuteTrade_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesMarketSubsystem, nullptr, "ServerOnly_ExecuteTrade", Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_ExecuteTrade_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_ExecuteTrade_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_ExecuteTrade_Statics::EchoesMarketSubsystem_eventServerOnly_ExecuteTrade_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_ExecuteTrade_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_ExecuteTrade_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_ExecuteTrade_Statics::EchoesMarketSubsystem_eventServerOnly_ExecuteTrade_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_ExecuteTrade()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_ExecuteTrade_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesMarketSubsystem::execServerOnly_ExecuteTrade)
{
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_CharacterId);
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_OrderId);
	P_GET_PROPERTY(FIntProperty,Z_Param_Quantity);
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_CurrentStationId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerOnly_ExecuteTrade(Z_Param_Out_CharacterId,Z_Param_Out_OrderId,Z_Param_Quantity,Z_Param_Out_CurrentStationId);
	P_NATIVE_END;
}
// ********** End Class UEchoesMarketSubsystem Function ServerOnly_ExecuteTrade ********************

// ********** Begin Class UEchoesMarketSubsystem Function ServerOnly_FetchMarketOrders *************
struct Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_FetchMarketOrders_Statics
{
	struct EchoesMarketSubsystem_eventServerOnly_FetchMarketOrders_Parms
	{
		FMarketFilter Filter;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Market" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Fetch market orders for a region/item (order book)\n\x09 * Sends HTTP GET to /api/market/region/{regionId}/{itemId}\n\x09 * Results broadcast via OnMarketDataReceived delegate\n\x09 * \n\x09 * @param Filter - Market filter with RegionId, ItemId, and display options\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesMarketSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fetch market orders for a region/item (order book)\nSends HTTP GET to /api/market/region/{regionId}/{itemId}\nResults broadcast via OnMarketDataReceived delegate\n\n@param Filter - Market filter with RegionId, ItemId, and display options" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Filter_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Filter;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_FetchMarketOrders_Statics::NewProp_Filter = { "Filter", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMarketSubsystem_eventServerOnly_FetchMarketOrders_Parms, Filter), Z_Construct_UScriptStruct_FMarketFilter, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Filter_MetaData), NewProp_Filter_MetaData) }; // 2889192733
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_FetchMarketOrders_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_FetchMarketOrders_Statics::NewProp_Filter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_FetchMarketOrders_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_FetchMarketOrders_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesMarketSubsystem, nullptr, "ServerOnly_FetchMarketOrders", Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_FetchMarketOrders_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_FetchMarketOrders_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_FetchMarketOrders_Statics::EchoesMarketSubsystem_eventServerOnly_FetchMarketOrders_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_FetchMarketOrders_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_FetchMarketOrders_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_FetchMarketOrders_Statics::EchoesMarketSubsystem_eventServerOnly_FetchMarketOrders_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_FetchMarketOrders()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_FetchMarketOrders_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesMarketSubsystem::execServerOnly_FetchMarketOrders)
{
	P_GET_STRUCT_REF(FMarketFilter,Z_Param_Out_Filter);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerOnly_FetchMarketOrders(Z_Param_Out_Filter);
	P_NATIVE_END;
}
// ********** End Class UEchoesMarketSubsystem Function ServerOnly_FetchMarketOrders ***************

// ********** Begin Class UEchoesMarketSubsystem ***************************************************
void UEchoesMarketSubsystem::StaticRegisterNativesUEchoesMarketSubsystem()
{
	UClass* Class = UEchoesMarketSubsystem::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetCachedMarketOrders", &UEchoesMarketSubsystem::execGetCachedMarketOrders },
		{ "GetTransactionState", &UEchoesMarketSubsystem::execGetTransactionState },
		{ "IsCacheValid", &UEchoesMarketSubsystem::execIsCacheValid },
		{ "ResetTransactionState", &UEchoesMarketSubsystem::execResetTransactionState },
		{ "ServerOnly_CancelOrder", &UEchoesMarketSubsystem::execServerOnly_CancelOrder },
		{ "ServerOnly_CreateOrder", &UEchoesMarketSubsystem::execServerOnly_CreateOrder },
		{ "ServerOnly_ExecuteTrade", &UEchoesMarketSubsystem::execServerOnly_ExecuteTrade },
		{ "ServerOnly_FetchMarketOrders", &UEchoesMarketSubsystem::execServerOnly_FetchMarketOrders },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UEchoesMarketSubsystem;
UClass* UEchoesMarketSubsystem::GetPrivateStaticClass()
{
	using TClass = UEchoesMarketSubsystem;
	if (!Z_Registration_Info_UClass_UEchoesMarketSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesMarketSubsystem"),
			Z_Registration_Info_UClass_UEchoesMarketSubsystem.InnerSingleton,
			StaticRegisterNativesUEchoesMarketSubsystem,
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
	return Z_Registration_Info_UClass_UEchoesMarketSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UEchoesMarketSubsystem_NoRegister()
{
	return UEchoesMarketSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UEchoesMarketSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * UEchoesMarketSubsystem\n * \n * Market networking subsystem for Echoes MMO (EVE-style market)\n * Communicates with ASP.NET Core MarketController\n * \n * Architecture:\n * - GameInstanceSubsystem: Persists across level transitions\n * - ServerOnly_ prefix: Methods intended for UE5 dedicated server\n * - Reads ApiBaseUrl and X-Server-Secret from config (DefaultGame.ini)\n * - Caches market data to avoid excessive API requests\n * - Tracks transaction state to prevent duplicate requests and handle timeouts\n */" },
#endif
		{ "IncludePath", "Core/Common/Networking/EchoesMarketSubsystem.h" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesMarketSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UEchoesMarketSubsystem\n\nMarket networking subsystem for Echoes MMO (EVE-style market)\nCommunicates with ASP.NET Core MarketController\n\nArchitecture:\n- GameInstanceSubsystem: Persists across level transitions\n- ServerOnly_ prefix: Methods intended for UE5 dedicated server\n- Reads ApiBaseUrl and X-Server-Secret from config (DefaultGame.ini)\n- Caches market data to avoid excessive API requests\n- Tracks transaction state to prevent duplicate requests and handle timeouts" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnMarketDataReceived_MetaData[] = {
		{ "Category", "Echoes|Market" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when market order data is received */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesMarketSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when market order data is received" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnMarketRequestFailed_MetaData[] = {
		{ "Category", "Echoes|Market" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when a market API request fails */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesMarketSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when a market API request fails" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnMarketOrderCreated_MetaData[] = {
		{ "Category", "Echoes|Market" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when an order is created successfully */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesMarketSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when an order is created successfully" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnMarketTradeExecuted_MetaData[] = {
		{ "Category", "Echoes|Market" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when a trade is executed successfully */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesMarketSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when a trade is executed successfully" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnTradeConfirmed_MetaData[] = {
		{ "Category", "Echoes|Market" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when a trade is confirmed with full result data */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesMarketSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when a trade is confirmed with full result data" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnTradeError_MetaData[] = {
		{ "Category", "Echoes|Market" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when a trade fails with detailed error info */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesMarketSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when a trade fails with detailed error info" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnMarketOrderCancelled_MetaData[] = {
		{ "Category", "Echoes|Market" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when an order is cancelled successfully */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesMarketSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when an order is cancelled successfully" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnInventorySyncRequired_MetaData[] = {
		{ "Category", "Echoes|Market" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when inventory/wallet needs to be resynced after a trade */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesMarketSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when inventory/wallet needs to be resynced after a trade" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CachedOrders_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Cached market orders to reduce API calls */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesMarketSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cached market orders to reduce API calls" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnMarketDataReceived;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnMarketRequestFailed;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnMarketOrderCreated;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnMarketTradeExecuted;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnTradeConfirmed;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnTradeError;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnMarketOrderCancelled;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnInventorySyncRequired;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CachedOrders_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_CachedOrders;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UEchoesMarketSubsystem_GetCachedMarketOrders, "GetCachedMarketOrders" }, // 909428135
		{ &Z_Construct_UFunction_UEchoesMarketSubsystem_GetTransactionState, "GetTransactionState" }, // 2928537402
		{ &Z_Construct_UFunction_UEchoesMarketSubsystem_IsCacheValid, "IsCacheValid" }, // 2283677248
		{ &Z_Construct_UFunction_UEchoesMarketSubsystem_ResetTransactionState, "ResetTransactionState" }, // 3713850715
		{ &Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_CancelOrder, "ServerOnly_CancelOrder" }, // 1217603276
		{ &Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_CreateOrder, "ServerOnly_CreateOrder" }, // 2873890940
		{ &Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_ExecuteTrade, "ServerOnly_ExecuteTrade" }, // 3592769784
		{ &Z_Construct_UFunction_UEchoesMarketSubsystem_ServerOnly_FetchMarketOrders, "ServerOnly_FetchMarketOrders" }, // 661377467
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEchoesMarketSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEchoesMarketSubsystem_Statics::NewProp_OnMarketDataReceived = { "OnMarketDataReceived", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesMarketSubsystem, OnMarketDataReceived), Z_Construct_UDelegateFunction_Echoes_OnMarketDataReceived__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnMarketDataReceived_MetaData), NewProp_OnMarketDataReceived_MetaData) }; // 1252499546
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEchoesMarketSubsystem_Statics::NewProp_OnMarketRequestFailed = { "OnMarketRequestFailed", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesMarketSubsystem, OnMarketRequestFailed), Z_Construct_UDelegateFunction_Echoes_OnMarketRequestFailed__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnMarketRequestFailed_MetaData), NewProp_OnMarketRequestFailed_MetaData) }; // 2392662867
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEchoesMarketSubsystem_Statics::NewProp_OnMarketOrderCreated = { "OnMarketOrderCreated", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesMarketSubsystem, OnMarketOrderCreated), Z_Construct_UDelegateFunction_Echoes_OnMarketOrderCreated__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnMarketOrderCreated_MetaData), NewProp_OnMarketOrderCreated_MetaData) }; // 3412316971
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEchoesMarketSubsystem_Statics::NewProp_OnMarketTradeExecuted = { "OnMarketTradeExecuted", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesMarketSubsystem, OnMarketTradeExecuted), Z_Construct_UDelegateFunction_Echoes_OnMarketTradeExecuted__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnMarketTradeExecuted_MetaData), NewProp_OnMarketTradeExecuted_MetaData) }; // 4114330697
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEchoesMarketSubsystem_Statics::NewProp_OnTradeConfirmed = { "OnTradeConfirmed", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesMarketSubsystem, OnTradeConfirmed), Z_Construct_UDelegateFunction_Echoes_OnTradeConfirmed__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnTradeConfirmed_MetaData), NewProp_OnTradeConfirmed_MetaData) }; // 2209632646
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEchoesMarketSubsystem_Statics::NewProp_OnTradeError = { "OnTradeError", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesMarketSubsystem, OnTradeError), Z_Construct_UDelegateFunction_Echoes_OnTradeError__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnTradeError_MetaData), NewProp_OnTradeError_MetaData) }; // 1205962871
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEchoesMarketSubsystem_Statics::NewProp_OnMarketOrderCancelled = { "OnMarketOrderCancelled", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesMarketSubsystem, OnMarketOrderCancelled), Z_Construct_UDelegateFunction_Echoes_OnMarketOrderCancelled__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnMarketOrderCancelled_MetaData), NewProp_OnMarketOrderCancelled_MetaData) }; // 623839470
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEchoesMarketSubsystem_Statics::NewProp_OnInventorySyncRequired = { "OnInventorySyncRequired", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesMarketSubsystem, OnInventorySyncRequired), Z_Construct_UDelegateFunction_Echoes_OnMarketInventorySyncRequired__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnInventorySyncRequired_MetaData), NewProp_OnInventorySyncRequired_MetaData) }; // 1041513082
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEchoesMarketSubsystem_Statics::NewProp_CachedOrders_Inner = { "CachedOrders", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FMarketOrderDto, METADATA_PARAMS(0, nullptr) }; // 449536635
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UEchoesMarketSubsystem_Statics::NewProp_CachedOrders = { "CachedOrders", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesMarketSubsystem, CachedOrders), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CachedOrders_MetaData), NewProp_CachedOrders_MetaData) }; // 449536635
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEchoesMarketSubsystem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMarketSubsystem_Statics::NewProp_OnMarketDataReceived,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMarketSubsystem_Statics::NewProp_OnMarketRequestFailed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMarketSubsystem_Statics::NewProp_OnMarketOrderCreated,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMarketSubsystem_Statics::NewProp_OnMarketTradeExecuted,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMarketSubsystem_Statics::NewProp_OnTradeConfirmed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMarketSubsystem_Statics::NewProp_OnTradeError,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMarketSubsystem_Statics::NewProp_OnMarketOrderCancelled,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMarketSubsystem_Statics::NewProp_OnInventorySyncRequired,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMarketSubsystem_Statics::NewProp_CachedOrders_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesMarketSubsystem_Statics::NewProp_CachedOrders,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesMarketSubsystem_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UEchoesMarketSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesMarketSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEchoesMarketSubsystem_Statics::ClassParams = {
	&UEchoesMarketSubsystem::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UEchoesMarketSubsystem_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesMarketSubsystem_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesMarketSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UEchoesMarketSubsystem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEchoesMarketSubsystem()
{
	if (!Z_Registration_Info_UClass_UEchoesMarketSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEchoesMarketSubsystem.OuterSingleton, Z_Construct_UClass_UEchoesMarketSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEchoesMarketSubsystem.OuterSingleton;
}
UEchoesMarketSubsystem::UEchoesMarketSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UEchoesMarketSubsystem);
UEchoesMarketSubsystem::~UEchoesMarketSubsystem() {}
// ********** End Class UEchoesMarketSubsystem *****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesMarketSubsystem_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEchoesMarketSubsystem, UEchoesMarketSubsystem::StaticClass, TEXT("UEchoesMarketSubsystem"), &Z_Registration_Info_UClass_UEchoesMarketSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEchoesMarketSubsystem), 3924054328U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesMarketSubsystem_h__Script_Echoes_2787606797(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesMarketSubsystem_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesMarketSubsystem_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
