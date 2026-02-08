// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EchoesMarketStructures.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesMarketStructures() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FDateTime();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ECHOES_API UEnum* Z_Construct_UEnum_Echoes_EMarketTransactionState();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FMarketFilter();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FMarketOrderDto();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FMarketTradeResult();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FMarketOrderDto ***************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FMarketOrderDto;
class UScriptStruct* FMarketOrderDto::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FMarketOrderDto.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FMarketOrderDto.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FMarketOrderDto, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("MarketOrderDto"));
	}
	return Z_Registration_Info_UScriptStruct_FMarketOrderDto.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FMarketOrderDto_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Market order DTO (mirrors C# MarketOrderDto from ASP.NET backend)\n * Used to display market orders in the UI order book\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesMarketStructures.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Market order DTO (mirrors C# MarketOrderDto from ASP.NET backend)\nUsed to display market orders in the UI order book" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OrderId_MetaData[] = {
		{ "Category", "Market" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesMarketStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterId_MetaData[] = {
		{ "Category", "Market" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesMarketStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemId_MetaData[] = {
		{ "Category", "Market" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesMarketStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemName_MetaData[] = {
		{ "Category", "Market" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Item display name (resolved client-side from item type registry) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesMarketStructures.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Item display name (resolved client-side from item type registry)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IsBuyOrder_MetaData[] = {
		{ "Category", "Market" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesMarketStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Price_MetaData[] = {
		{ "Category", "Market" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesMarketStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Quantity_MetaData[] = {
		{ "Category", "Market" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesMarketStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RemainingQuantity_MetaData[] = {
		{ "Category", "Market" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesMarketStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StationId_MetaData[] = {
		{ "Category", "Market" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesMarketStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StationName_MetaData[] = {
		{ "Category", "Market" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesMarketStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RegionId_MetaData[] = {
		{ "Category", "Market" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesMarketStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Duration_MetaData[] = {
		{ "Category", "Market" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesMarketStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Status_MetaData[] = {
		{ "Category", "Market" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesMarketStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BrokerFee_MetaData[] = {
		{ "Category", "Market" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesMarketStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IssuedAt_MetaData[] = {
		{ "Category", "Market" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesMarketStructures.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_OrderId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CharacterId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ItemId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ItemName;
	static void NewProp_IsBuyOrder_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_IsBuyOrder;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_Price;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Quantity;
	static const UECodeGen_Private::FIntPropertyParams NewProp_RemainingQuantity;
	static const UECodeGen_Private::FStructPropertyParams NewProp_StationId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_StationName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RegionId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Duration;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Status;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_BrokerFee;
	static const UECodeGen_Private::FStructPropertyParams NewProp_IssuedAt;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMarketOrderDto>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMarketOrderDto_Statics::NewProp_OrderId = { "OrderId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMarketOrderDto, OrderId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OrderId_MetaData), NewProp_OrderId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMarketOrderDto_Statics::NewProp_CharacterId = { "CharacterId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMarketOrderDto, CharacterId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterId_MetaData), NewProp_CharacterId_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FMarketOrderDto_Statics::NewProp_ItemId = { "ItemId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMarketOrderDto, ItemId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemId_MetaData), NewProp_ItemId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FMarketOrderDto_Statics::NewProp_ItemName = { "ItemName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMarketOrderDto, ItemName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemName_MetaData), NewProp_ItemName_MetaData) };
void Z_Construct_UScriptStruct_FMarketOrderDto_Statics::NewProp_IsBuyOrder_SetBit(void* Obj)
{
	((FMarketOrderDto*)Obj)->IsBuyOrder = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FMarketOrderDto_Statics::NewProp_IsBuyOrder = { "IsBuyOrder", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FMarketOrderDto), &Z_Construct_UScriptStruct_FMarketOrderDto_Statics::NewProp_IsBuyOrder_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IsBuyOrder_MetaData), NewProp_IsBuyOrder_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FMarketOrderDto_Statics::NewProp_Price = { "Price", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMarketOrderDto, Price), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Price_MetaData), NewProp_Price_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FMarketOrderDto_Statics::NewProp_Quantity = { "Quantity", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMarketOrderDto, Quantity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Quantity_MetaData), NewProp_Quantity_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FMarketOrderDto_Statics::NewProp_RemainingQuantity = { "RemainingQuantity", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMarketOrderDto, RemainingQuantity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RemainingQuantity_MetaData), NewProp_RemainingQuantity_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMarketOrderDto_Statics::NewProp_StationId = { "StationId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMarketOrderDto, StationId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StationId_MetaData), NewProp_StationId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FMarketOrderDto_Statics::NewProp_StationName = { "StationName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMarketOrderDto, StationName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StationName_MetaData), NewProp_StationName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMarketOrderDto_Statics::NewProp_RegionId = { "RegionId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMarketOrderDto, RegionId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RegionId_MetaData), NewProp_RegionId_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FMarketOrderDto_Statics::NewProp_Duration = { "Duration", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMarketOrderDto, Duration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Duration_MetaData), NewProp_Duration_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FMarketOrderDto_Statics::NewProp_Status = { "Status", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMarketOrderDto, Status), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Status_MetaData), NewProp_Status_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FMarketOrderDto_Statics::NewProp_BrokerFee = { "BrokerFee", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMarketOrderDto, BrokerFee), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BrokerFee_MetaData), NewProp_BrokerFee_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMarketOrderDto_Statics::NewProp_IssuedAt = { "IssuedAt", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMarketOrderDto, IssuedAt), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IssuedAt_MetaData), NewProp_IssuedAt_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMarketOrderDto_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMarketOrderDto_Statics::NewProp_OrderId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMarketOrderDto_Statics::NewProp_CharacterId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMarketOrderDto_Statics::NewProp_ItemId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMarketOrderDto_Statics::NewProp_ItemName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMarketOrderDto_Statics::NewProp_IsBuyOrder,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMarketOrderDto_Statics::NewProp_Price,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMarketOrderDto_Statics::NewProp_Quantity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMarketOrderDto_Statics::NewProp_RemainingQuantity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMarketOrderDto_Statics::NewProp_StationId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMarketOrderDto_Statics::NewProp_StationName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMarketOrderDto_Statics::NewProp_RegionId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMarketOrderDto_Statics::NewProp_Duration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMarketOrderDto_Statics::NewProp_Status,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMarketOrderDto_Statics::NewProp_BrokerFee,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMarketOrderDto_Statics::NewProp_IssuedAt,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMarketOrderDto_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMarketOrderDto_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"MarketOrderDto",
	Z_Construct_UScriptStruct_FMarketOrderDto_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMarketOrderDto_Statics::PropPointers),
	sizeof(FMarketOrderDto),
	alignof(FMarketOrderDto),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMarketOrderDto_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FMarketOrderDto_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FMarketOrderDto()
{
	if (!Z_Registration_Info_UScriptStruct_FMarketOrderDto.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FMarketOrderDto.InnerSingleton, Z_Construct_UScriptStruct_FMarketOrderDto_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FMarketOrderDto.InnerSingleton;
}
// ********** End ScriptStruct FMarketOrderDto *****************************************************

// ********** Begin ScriptStruct FMarketFilter *****************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FMarketFilter;
class UScriptStruct* FMarketFilter::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FMarketFilter.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FMarketFilter.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FMarketFilter, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("MarketFilter"));
	}
	return Z_Registration_Info_UScriptStruct_FMarketFilter.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FMarketFilter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Market filter structure for querying orders\n * Used by UEchoesMarketSubsystem to filter order book requests\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesMarketStructures.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Market filter structure for querying orders\nUsed by UEchoesMarketSubsystem to filter order book requests" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RegionId_MetaData[] = {
		{ "Category", "Market" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesMarketStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemId_MetaData[] = {
		{ "Category", "Market" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesMarketStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowOnlyBuyOrders_MetaData[] = {
		{ "Category", "Market" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesMarketStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowOnlySellOrders_MetaData[] = {
		{ "Category", "Market" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesMarketStructures.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_RegionId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ItemId;
	static void NewProp_bShowOnlyBuyOrders_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowOnlyBuyOrders;
	static void NewProp_bShowOnlySellOrders_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowOnlySellOrders;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMarketFilter>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMarketFilter_Statics::NewProp_RegionId = { "RegionId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMarketFilter, RegionId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RegionId_MetaData), NewProp_RegionId_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FMarketFilter_Statics::NewProp_ItemId = { "ItemId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMarketFilter, ItemId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemId_MetaData), NewProp_ItemId_MetaData) };
void Z_Construct_UScriptStruct_FMarketFilter_Statics::NewProp_bShowOnlyBuyOrders_SetBit(void* Obj)
{
	((FMarketFilter*)Obj)->bShowOnlyBuyOrders = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FMarketFilter_Statics::NewProp_bShowOnlyBuyOrders = { "bShowOnlyBuyOrders", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FMarketFilter), &Z_Construct_UScriptStruct_FMarketFilter_Statics::NewProp_bShowOnlyBuyOrders_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowOnlyBuyOrders_MetaData), NewProp_bShowOnlyBuyOrders_MetaData) };
void Z_Construct_UScriptStruct_FMarketFilter_Statics::NewProp_bShowOnlySellOrders_SetBit(void* Obj)
{
	((FMarketFilter*)Obj)->bShowOnlySellOrders = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FMarketFilter_Statics::NewProp_bShowOnlySellOrders = { "bShowOnlySellOrders", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FMarketFilter), &Z_Construct_UScriptStruct_FMarketFilter_Statics::NewProp_bShowOnlySellOrders_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowOnlySellOrders_MetaData), NewProp_bShowOnlySellOrders_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMarketFilter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMarketFilter_Statics::NewProp_RegionId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMarketFilter_Statics::NewProp_ItemId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMarketFilter_Statics::NewProp_bShowOnlyBuyOrders,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMarketFilter_Statics::NewProp_bShowOnlySellOrders,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMarketFilter_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMarketFilter_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"MarketFilter",
	Z_Construct_UScriptStruct_FMarketFilter_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMarketFilter_Statics::PropPointers),
	sizeof(FMarketFilter),
	alignof(FMarketFilter),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMarketFilter_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FMarketFilter_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FMarketFilter()
{
	if (!Z_Registration_Info_UScriptStruct_FMarketFilter.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FMarketFilter.InnerSingleton, Z_Construct_UScriptStruct_FMarketFilter_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FMarketFilter.InnerSingleton;
}
// ********** End ScriptStruct FMarketFilter *******************************************************

// ********** Begin ScriptStruct FMarketTradeResult ************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FMarketTradeResult;
class UScriptStruct* FMarketTradeResult::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FMarketTradeResult.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FMarketTradeResult.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FMarketTradeResult, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("MarketTradeResult"));
	}
	return Z_Registration_Info_UScriptStruct_FMarketTradeResult.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FMarketTradeResult_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Result of a successful trade execution\n * Used for UI notifications (toast) and inventory sync\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesMarketStructures.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Result of a successful trade execution\nUsed for UI notifications (toast) and inventory sync" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OrderId_MetaData[] = {
		{ "Category", "Market" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesMarketStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TransactionId_MetaData[] = {
		{ "Category", "Market" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesMarketStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_QuantityTraded_MetaData[] = {
		{ "Category", "Market" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesMarketStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalPrice_MetaData[] = {
		{ "Category", "Market" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesMarketStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TransactionTax_MetaData[] = {
		{ "Category", "Market" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesMarketStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemId_MetaData[] = {
		{ "Category", "Market" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesMarketStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemName_MetaData[] = {
		{ "Category", "Market" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesMarketStructures.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
		{ "Category", "Market" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesMarketStructures.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_OrderId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TransactionId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_QuantityTraded;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_TotalPrice;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_TransactionTax;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ItemId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ItemName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Message;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMarketTradeResult>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMarketTradeResult_Statics::NewProp_OrderId = { "OrderId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMarketTradeResult, OrderId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OrderId_MetaData), NewProp_OrderId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMarketTradeResult_Statics::NewProp_TransactionId = { "TransactionId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMarketTradeResult, TransactionId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TransactionId_MetaData), NewProp_TransactionId_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FMarketTradeResult_Statics::NewProp_QuantityTraded = { "QuantityTraded", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMarketTradeResult, QuantityTraded), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_QuantityTraded_MetaData), NewProp_QuantityTraded_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FMarketTradeResult_Statics::NewProp_TotalPrice = { "TotalPrice", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMarketTradeResult, TotalPrice), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalPrice_MetaData), NewProp_TotalPrice_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FMarketTradeResult_Statics::NewProp_TransactionTax = { "TransactionTax", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMarketTradeResult, TransactionTax), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TransactionTax_MetaData), NewProp_TransactionTax_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FMarketTradeResult_Statics::NewProp_ItemId = { "ItemId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMarketTradeResult, ItemId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemId_MetaData), NewProp_ItemId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FMarketTradeResult_Statics::NewProp_ItemName = { "ItemName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMarketTradeResult, ItemName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemName_MetaData), NewProp_ItemName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FMarketTradeResult_Statics::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMarketTradeResult, Message), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMarketTradeResult_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMarketTradeResult_Statics::NewProp_OrderId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMarketTradeResult_Statics::NewProp_TransactionId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMarketTradeResult_Statics::NewProp_QuantityTraded,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMarketTradeResult_Statics::NewProp_TotalPrice,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMarketTradeResult_Statics::NewProp_TransactionTax,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMarketTradeResult_Statics::NewProp_ItemId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMarketTradeResult_Statics::NewProp_ItemName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMarketTradeResult_Statics::NewProp_Message,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMarketTradeResult_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMarketTradeResult_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"MarketTradeResult",
	Z_Construct_UScriptStruct_FMarketTradeResult_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMarketTradeResult_Statics::PropPointers),
	sizeof(FMarketTradeResult),
	alignof(FMarketTradeResult),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMarketTradeResult_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FMarketTradeResult_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FMarketTradeResult()
{
	if (!Z_Registration_Info_UScriptStruct_FMarketTradeResult.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FMarketTradeResult.InnerSingleton, Z_Construct_UScriptStruct_FMarketTradeResult_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FMarketTradeResult.InnerSingleton;
}
// ********** End ScriptStruct FMarketTradeResult **************************************************

// ********** Begin Enum EMarketTransactionState ***************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EMarketTransactionState;
static UEnum* EMarketTransactionState_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EMarketTransactionState.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EMarketTransactionState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Echoes_EMarketTransactionState, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("EMarketTransactionState"));
	}
	return Z_Registration_Info_UEnum_EMarketTransactionState.OuterSingleton;
}
template<> ECHOES_API UEnum* StaticEnum<EMarketTransactionState>()
{
	return EMarketTransactionState_StaticEnum();
}
struct Z_Construct_UEnum_Echoes_EMarketTransactionState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Trade transaction state for timeout/reliability tracking */" },
#endif
		{ "Idle.Name", "EMarketTransactionState::Idle" },
		{ "InFlight.Name", "EMarketTransactionState::InFlight" },
		{ "ModuleRelativePath", "Core/Common/Structures/EchoesMarketStructures.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Trade transaction state for timeout/reliability tracking" },
#endif
		{ "UnknownState.Name", "EMarketTransactionState::UnknownState" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EMarketTransactionState::Idle", (int64)EMarketTransactionState::Idle },
		{ "EMarketTransactionState::InFlight", (int64)EMarketTransactionState::InFlight },
		{ "EMarketTransactionState::UnknownState", (int64)EMarketTransactionState::UnknownState },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Echoes_EMarketTransactionState_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	"EMarketTransactionState",
	"EMarketTransactionState",
	Z_Construct_UEnum_Echoes_EMarketTransactionState_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_Echoes_EMarketTransactionState_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_Echoes_EMarketTransactionState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_Echoes_EMarketTransactionState_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_Echoes_EMarketTransactionState()
{
	if (!Z_Registration_Info_UEnum_EMarketTransactionState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EMarketTransactionState.InnerSingleton, Z_Construct_UEnum_Echoes_EMarketTransactionState_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EMarketTransactionState.InnerSingleton;
}
// ********** End Enum EMarketTransactionState *****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Structures_EchoesMarketStructures_h__Script_Echoes_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EMarketTransactionState_StaticEnum, TEXT("EMarketTransactionState"), &Z_Registration_Info_UEnum_EMarketTransactionState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3706960494U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FMarketOrderDto::StaticStruct, Z_Construct_UScriptStruct_FMarketOrderDto_Statics::NewStructOps, TEXT("MarketOrderDto"), &Z_Registration_Info_UScriptStruct_FMarketOrderDto, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FMarketOrderDto), 449536635U) },
		{ FMarketFilter::StaticStruct, Z_Construct_UScriptStruct_FMarketFilter_Statics::NewStructOps, TEXT("MarketFilter"), &Z_Registration_Info_UScriptStruct_FMarketFilter, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FMarketFilter), 2889192733U) },
		{ FMarketTradeResult::StaticStruct, Z_Construct_UScriptStruct_FMarketTradeResult_Statics::NewStructOps, TEXT("MarketTradeResult"), &Z_Registration_Info_UScriptStruct_FMarketTradeResult, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FMarketTradeResult), 4107301343U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Structures_EchoesMarketStructures_h__Script_Echoes_871176821(TEXT("/Script/Echoes"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Structures_EchoesMarketStructures_h__Script_Echoes_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Structures_EchoesMarketStructures_h__Script_Echoes_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Structures_EchoesMarketStructures_h__Script_Echoes_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Structures_EchoesMarketStructures_h__Script_Echoes_Statics::EnumInfo));
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
