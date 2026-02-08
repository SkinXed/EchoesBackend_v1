// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ServerDataManager.h"
#include "ShipFittingInterface.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeServerDataManager() {}

// ********** Begin Cross Module References ********************************************************
ECHOES_API UClass* Z_Construct_UClass_AServerDataManager();
ECHOES_API UClass* Z_Construct_UClass_AServerDataManager_NoRegister();
ECHOES_API UEnum* Z_Construct_UEnum_Echoes_ESlotType();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FCommon_ItemSlot();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FCommon_ShipFittingData();
ENGINE_API UClass* Z_Construct_UClass_AActor();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AServerDataManager Function GetAPIBaseURL ********************************
struct Z_Construct_UFunction_AServerDataManager_GetAPIBaseURL_Statics
{
	struct ServerDataManager_eventGetAPIBaseURL_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Server|Data|HTTP" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get API Base URL from configuration\n\x09 * Returns the configured API base URL or default\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Server/Managers/ServerDataManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get API Base URL from configuration\nReturns the configured API base URL or default" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AServerDataManager_GetAPIBaseURL_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ServerDataManager_eventGetAPIBaseURL_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AServerDataManager_GetAPIBaseURL_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AServerDataManager_GetAPIBaseURL_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AServerDataManager_GetAPIBaseURL_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AServerDataManager_GetAPIBaseURL_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AServerDataManager, nullptr, "GetAPIBaseURL", Z_Construct_UFunction_AServerDataManager_GetAPIBaseURL_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AServerDataManager_GetAPIBaseURL_Statics::PropPointers), sizeof(Z_Construct_UFunction_AServerDataManager_GetAPIBaseURL_Statics::ServerDataManager_eventGetAPIBaseURL_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AServerDataManager_GetAPIBaseURL_Statics::Function_MetaDataParams), Z_Construct_UFunction_AServerDataManager_GetAPIBaseURL_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AServerDataManager_GetAPIBaseURL_Statics::ServerDataManager_eventGetAPIBaseURL_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AServerDataManager_GetAPIBaseURL()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AServerDataManager_GetAPIBaseURL_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AServerDataManager::execGetAPIBaseURL)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GetAPIBaseURL();
	P_NATIVE_END;
}
// ********** End Class AServerDataManager Function GetAPIBaseURL **********************************

// ********** Begin Class AServerDataManager Function GetServerSecret ******************************
struct Z_Construct_UFunction_AServerDataManager_GetServerSecret_Statics
{
	struct ServerDataManager_eventGetServerSecret_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Server|Data|HTTP" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get Server Secret from configuration\n\x09 * Returns the X-Server-Secret header value\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Server/Managers/ServerDataManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get Server Secret from configuration\nReturns the X-Server-Secret header value" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AServerDataManager_GetServerSecret_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ServerDataManager_eventGetServerSecret_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AServerDataManager_GetServerSecret_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AServerDataManager_GetServerSecret_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AServerDataManager_GetServerSecret_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AServerDataManager_GetServerSecret_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AServerDataManager, nullptr, "GetServerSecret", Z_Construct_UFunction_AServerDataManager_GetServerSecret_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AServerDataManager_GetServerSecret_Statics::PropPointers), sizeof(Z_Construct_UFunction_AServerDataManager_GetServerSecret_Statics::ServerDataManager_eventGetServerSecret_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AServerDataManager_GetServerSecret_Statics::Function_MetaDataParams), Z_Construct_UFunction_AServerDataManager_GetServerSecret_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AServerDataManager_GetServerSecret_Statics::ServerDataManager_eventGetServerSecret_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AServerDataManager_GetServerSecret()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AServerDataManager_GetServerSecret_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AServerDataManager::execGetServerSecret)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GetServerSecret();
	P_NATIVE_END;
}
// ********** End Class AServerDataManager Function GetServerSecret ********************************

// ********** Begin Class AServerDataManager Function ServerOnly_CalculateFinalStats ***************
struct Z_Construct_UFunction_AServerDataManager_ServerOnly_CalculateFinalStats_Statics
{
	struct ServerDataManager_eventServerOnly_CalculateFinalStats_Parms
	{
		float BaseShield;
		float BaseArmor;
		float BaseStructure;
		float BaseCapacitor;
		float BaseSpeed;
		FCommon_ShipFittingData FittingData;
		FCommon_ShipFittingData OutFinalStats;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Server|Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Calculate Final Stats\n\x09 * Calculates final ship stats from base stats + all module bonuses\n\x09 * @param BaseShield - Base shield HP\n\x09 * @param BaseArmor - Base armor HP\n\x09 * @param BaseStructure - Base structure HP\n\x09 * @param BaseCapacitor - Base capacitor\n\x09 * @param BaseSpeed - Base max speed\n\x09 * @param FittingData - Current fitting with all modules\n\x09 * @param OutFinalStats - Populated with calculated stats\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Server/Managers/ServerDataManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Calculate Final Stats\nCalculates final ship stats from base stats + all module bonuses\n@param BaseShield - Base shield HP\n@param BaseArmor - Base armor HP\n@param BaseStructure - Base structure HP\n@param BaseCapacitor - Base capacitor\n@param BaseSpeed - Base max speed\n@param FittingData - Current fitting with all modules\n@param OutFinalStats - Populated with calculated stats" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FittingData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BaseShield;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BaseArmor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BaseStructure;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BaseCapacitor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BaseSpeed;
	static const UECodeGen_Private::FStructPropertyParams NewProp_FittingData;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutFinalStats;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AServerDataManager_ServerOnly_CalculateFinalStats_Statics::NewProp_BaseShield = { "BaseShield", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ServerDataManager_eventServerOnly_CalculateFinalStats_Parms, BaseShield), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AServerDataManager_ServerOnly_CalculateFinalStats_Statics::NewProp_BaseArmor = { "BaseArmor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ServerDataManager_eventServerOnly_CalculateFinalStats_Parms, BaseArmor), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AServerDataManager_ServerOnly_CalculateFinalStats_Statics::NewProp_BaseStructure = { "BaseStructure", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ServerDataManager_eventServerOnly_CalculateFinalStats_Parms, BaseStructure), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AServerDataManager_ServerOnly_CalculateFinalStats_Statics::NewProp_BaseCapacitor = { "BaseCapacitor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ServerDataManager_eventServerOnly_CalculateFinalStats_Parms, BaseCapacitor), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AServerDataManager_ServerOnly_CalculateFinalStats_Statics::NewProp_BaseSpeed = { "BaseSpeed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ServerDataManager_eventServerOnly_CalculateFinalStats_Parms, BaseSpeed), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AServerDataManager_ServerOnly_CalculateFinalStats_Statics::NewProp_FittingData = { "FittingData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ServerDataManager_eventServerOnly_CalculateFinalStats_Parms, FittingData), Z_Construct_UScriptStruct_FCommon_ShipFittingData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FittingData_MetaData), NewProp_FittingData_MetaData) }; // 1329122485
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AServerDataManager_ServerOnly_CalculateFinalStats_Statics::NewProp_OutFinalStats = { "OutFinalStats", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ServerDataManager_eventServerOnly_CalculateFinalStats_Parms, OutFinalStats), Z_Construct_UScriptStruct_FCommon_ShipFittingData, METADATA_PARAMS(0, nullptr) }; // 1329122485
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AServerDataManager_ServerOnly_CalculateFinalStats_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AServerDataManager_ServerOnly_CalculateFinalStats_Statics::NewProp_BaseShield,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AServerDataManager_ServerOnly_CalculateFinalStats_Statics::NewProp_BaseArmor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AServerDataManager_ServerOnly_CalculateFinalStats_Statics::NewProp_BaseStructure,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AServerDataManager_ServerOnly_CalculateFinalStats_Statics::NewProp_BaseCapacitor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AServerDataManager_ServerOnly_CalculateFinalStats_Statics::NewProp_BaseSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AServerDataManager_ServerOnly_CalculateFinalStats_Statics::NewProp_FittingData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AServerDataManager_ServerOnly_CalculateFinalStats_Statics::NewProp_OutFinalStats,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AServerDataManager_ServerOnly_CalculateFinalStats_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AServerDataManager_ServerOnly_CalculateFinalStats_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AServerDataManager, nullptr, "ServerOnly_CalculateFinalStats", Z_Construct_UFunction_AServerDataManager_ServerOnly_CalculateFinalStats_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AServerDataManager_ServerOnly_CalculateFinalStats_Statics::PropPointers), sizeof(Z_Construct_UFunction_AServerDataManager_ServerOnly_CalculateFinalStats_Statics::ServerDataManager_eventServerOnly_CalculateFinalStats_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AServerDataManager_ServerOnly_CalculateFinalStats_Statics::Function_MetaDataParams), Z_Construct_UFunction_AServerDataManager_ServerOnly_CalculateFinalStats_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AServerDataManager_ServerOnly_CalculateFinalStats_Statics::ServerDataManager_eventServerOnly_CalculateFinalStats_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AServerDataManager_ServerOnly_CalculateFinalStats()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AServerDataManager_ServerOnly_CalculateFinalStats_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AServerDataManager::execServerOnly_CalculateFinalStats)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_BaseShield);
	P_GET_PROPERTY(FFloatProperty,Z_Param_BaseArmor);
	P_GET_PROPERTY(FFloatProperty,Z_Param_BaseStructure);
	P_GET_PROPERTY(FFloatProperty,Z_Param_BaseCapacitor);
	P_GET_PROPERTY(FFloatProperty,Z_Param_BaseSpeed);
	P_GET_STRUCT_REF(FCommon_ShipFittingData,Z_Param_Out_FittingData);
	P_GET_STRUCT_REF(FCommon_ShipFittingData,Z_Param_Out_OutFinalStats);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerOnly_CalculateFinalStats(Z_Param_BaseShield,Z_Param_BaseArmor,Z_Param_BaseStructure,Z_Param_BaseCapacitor,Z_Param_BaseSpeed,Z_Param_Out_FittingData,Z_Param_Out_OutFinalStats);
	P_NATIVE_END;
}
// ********** End Class AServerDataManager Function ServerOnly_CalculateFinalStats *****************

// ********** Begin Class AServerDataManager Function ServerOnly_ParseFittingDataFromJSON **********
struct Z_Construct_UFunction_AServerDataManager_ServerOnly_ParseFittingDataFromJSON_Statics
{
	struct ServerDataManager_eventServerOnly_ParseFittingDataFromJSON_Parms
	{
		FString JsonString;
		FCommon_ShipFittingData OutFittingData;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Server|Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Parse Fitting Data from JSON\n\x09 * Receives JSON from ASP.NET API and populates ship fitting data\n\x09 * @param JsonString - JSON string from API response\n\x09 * @param OutFittingData - Populated fitting data structure\n\x09 * @return true if parsing succeeded\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Server/Managers/ServerDataManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Parse Fitting Data from JSON\nReceives JSON from ASP.NET API and populates ship fitting data\n@param JsonString - JSON string from API response\n@param OutFittingData - Populated fitting data structure\n@return true if parsing succeeded" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JsonString_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_JsonString;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutFittingData;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AServerDataManager_ServerOnly_ParseFittingDataFromJSON_Statics::NewProp_JsonString = { "JsonString", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ServerDataManager_eventServerOnly_ParseFittingDataFromJSON_Parms, JsonString), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonString_MetaData), NewProp_JsonString_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AServerDataManager_ServerOnly_ParseFittingDataFromJSON_Statics::NewProp_OutFittingData = { "OutFittingData", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ServerDataManager_eventServerOnly_ParseFittingDataFromJSON_Parms, OutFittingData), Z_Construct_UScriptStruct_FCommon_ShipFittingData, METADATA_PARAMS(0, nullptr) }; // 1329122485
void Z_Construct_UFunction_AServerDataManager_ServerOnly_ParseFittingDataFromJSON_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ServerDataManager_eventServerOnly_ParseFittingDataFromJSON_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AServerDataManager_ServerOnly_ParseFittingDataFromJSON_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ServerDataManager_eventServerOnly_ParseFittingDataFromJSON_Parms), &Z_Construct_UFunction_AServerDataManager_ServerOnly_ParseFittingDataFromJSON_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AServerDataManager_ServerOnly_ParseFittingDataFromJSON_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AServerDataManager_ServerOnly_ParseFittingDataFromJSON_Statics::NewProp_JsonString,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AServerDataManager_ServerOnly_ParseFittingDataFromJSON_Statics::NewProp_OutFittingData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AServerDataManager_ServerOnly_ParseFittingDataFromJSON_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AServerDataManager_ServerOnly_ParseFittingDataFromJSON_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AServerDataManager_ServerOnly_ParseFittingDataFromJSON_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AServerDataManager, nullptr, "ServerOnly_ParseFittingDataFromJSON", Z_Construct_UFunction_AServerDataManager_ServerOnly_ParseFittingDataFromJSON_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AServerDataManager_ServerOnly_ParseFittingDataFromJSON_Statics::PropPointers), sizeof(Z_Construct_UFunction_AServerDataManager_ServerOnly_ParseFittingDataFromJSON_Statics::ServerDataManager_eventServerOnly_ParseFittingDataFromJSON_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AServerDataManager_ServerOnly_ParseFittingDataFromJSON_Statics::Function_MetaDataParams), Z_Construct_UFunction_AServerDataManager_ServerOnly_ParseFittingDataFromJSON_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AServerDataManager_ServerOnly_ParseFittingDataFromJSON_Statics::ServerDataManager_eventServerOnly_ParseFittingDataFromJSON_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AServerDataManager_ServerOnly_ParseFittingDataFromJSON()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AServerDataManager_ServerOnly_ParseFittingDataFromJSON_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AServerDataManager::execServerOnly_ParseFittingDataFromJSON)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_JsonString);
	P_GET_STRUCT_REF(FCommon_ShipFittingData,Z_Param_Out_OutFittingData);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ServerOnly_ParseFittingDataFromJSON(Z_Param_JsonString,Z_Param_Out_OutFittingData);
	P_NATIVE_END;
}
// ********** End Class AServerDataManager Function ServerOnly_ParseFittingDataFromJSON ************

// ********** Begin Class AServerDataManager Function ServerOnly_ParseModuleFromJSON ***************
struct Z_Construct_UFunction_AServerDataManager_ServerOnly_ParseModuleFromJSON_Statics
{
	struct ServerDataManager_eventServerOnly_ParseModuleFromJSON_Parms
	{
		FString JsonString;
		FCommon_ItemSlot OutSlot;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Server|Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Parse Module Data from JSON\n\x09 * Parses individual module/item data from JSON\n\x09 * @param JsonString - JSON string for a single module\n\x09 * @param OutSlot - Populated slot data\n\x09 * @return true if parsing succeeded\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Server/Managers/ServerDataManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Parse Module Data from JSON\nParses individual module/item data from JSON\n@param JsonString - JSON string for a single module\n@param OutSlot - Populated slot data\n@return true if parsing succeeded" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JsonString_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_JsonString;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutSlot;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AServerDataManager_ServerOnly_ParseModuleFromJSON_Statics::NewProp_JsonString = { "JsonString", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ServerDataManager_eventServerOnly_ParseModuleFromJSON_Parms, JsonString), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonString_MetaData), NewProp_JsonString_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AServerDataManager_ServerOnly_ParseModuleFromJSON_Statics::NewProp_OutSlot = { "OutSlot", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ServerDataManager_eventServerOnly_ParseModuleFromJSON_Parms, OutSlot), Z_Construct_UScriptStruct_FCommon_ItemSlot, METADATA_PARAMS(0, nullptr) }; // 771062216
void Z_Construct_UFunction_AServerDataManager_ServerOnly_ParseModuleFromJSON_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ServerDataManager_eventServerOnly_ParseModuleFromJSON_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AServerDataManager_ServerOnly_ParseModuleFromJSON_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ServerDataManager_eventServerOnly_ParseModuleFromJSON_Parms), &Z_Construct_UFunction_AServerDataManager_ServerOnly_ParseModuleFromJSON_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AServerDataManager_ServerOnly_ParseModuleFromJSON_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AServerDataManager_ServerOnly_ParseModuleFromJSON_Statics::NewProp_JsonString,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AServerDataManager_ServerOnly_ParseModuleFromJSON_Statics::NewProp_OutSlot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AServerDataManager_ServerOnly_ParseModuleFromJSON_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AServerDataManager_ServerOnly_ParseModuleFromJSON_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AServerDataManager_ServerOnly_ParseModuleFromJSON_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AServerDataManager, nullptr, "ServerOnly_ParseModuleFromJSON", Z_Construct_UFunction_AServerDataManager_ServerOnly_ParseModuleFromJSON_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AServerDataManager_ServerOnly_ParseModuleFromJSON_Statics::PropPointers), sizeof(Z_Construct_UFunction_AServerDataManager_ServerOnly_ParseModuleFromJSON_Statics::ServerDataManager_eventServerOnly_ParseModuleFromJSON_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AServerDataManager_ServerOnly_ParseModuleFromJSON_Statics::Function_MetaDataParams), Z_Construct_UFunction_AServerDataManager_ServerOnly_ParseModuleFromJSON_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AServerDataManager_ServerOnly_ParseModuleFromJSON_Statics::ServerDataManager_eventServerOnly_ParseModuleFromJSON_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AServerDataManager_ServerOnly_ParseModuleFromJSON()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AServerDataManager_ServerOnly_ParseModuleFromJSON_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AServerDataManager::execServerOnly_ParseModuleFromJSON)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_JsonString);
	P_GET_STRUCT_REF(FCommon_ItemSlot,Z_Param_Out_OutSlot);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ServerOnly_ParseModuleFromJSON(Z_Param_JsonString,Z_Param_Out_OutSlot);
	P_NATIVE_END;
}
// ********** End Class AServerDataManager Function ServerOnly_ParseModuleFromJSON *****************

// ********** Begin Class AServerDataManager Function ServerOnly_RequestFittingFromAPI *************
struct Z_Construct_UFunction_AServerDataManager_ServerOnly_RequestFittingFromAPI_Statics
{
	struct ServerDataManager_eventServerOnly_RequestFittingFromAPI_Parms
	{
		FString CharacterID;
		FString APIBaseURLOverride;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Server|Data|HTTP" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Request Fitting Data from ASP.NET API\n\x09 * Makes HTTP GET request to backend to fetch character's fitting data\n\x09 * @param CharacterID - Character ID to fetch fitting for\n\x09 * @param APIBaseURLOverride - Optional API base URL override\n\x09 */" },
#endif
		{ "CPP_Default_APIBaseURLOverride", "" },
		{ "ModuleRelativePath", "Core/Server/Managers/ServerDataManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Request Fitting Data from ASP.NET API\nMakes HTTP GET request to backend to fetch character's fitting data\n@param CharacterID - Character ID to fetch fitting for\n@param APIBaseURLOverride - Optional API base URL override" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterID_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_APIBaseURLOverride_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_CharacterID;
	static const UECodeGen_Private::FStrPropertyParams NewProp_APIBaseURLOverride;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AServerDataManager_ServerOnly_RequestFittingFromAPI_Statics::NewProp_CharacterID = { "CharacterID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ServerDataManager_eventServerOnly_RequestFittingFromAPI_Parms, CharacterID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterID_MetaData), NewProp_CharacterID_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AServerDataManager_ServerOnly_RequestFittingFromAPI_Statics::NewProp_APIBaseURLOverride = { "APIBaseURLOverride", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ServerDataManager_eventServerOnly_RequestFittingFromAPI_Parms, APIBaseURLOverride), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_APIBaseURLOverride_MetaData), NewProp_APIBaseURLOverride_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AServerDataManager_ServerOnly_RequestFittingFromAPI_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AServerDataManager_ServerOnly_RequestFittingFromAPI_Statics::NewProp_CharacterID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AServerDataManager_ServerOnly_RequestFittingFromAPI_Statics::NewProp_APIBaseURLOverride,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AServerDataManager_ServerOnly_RequestFittingFromAPI_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AServerDataManager_ServerOnly_RequestFittingFromAPI_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AServerDataManager, nullptr, "ServerOnly_RequestFittingFromAPI", Z_Construct_UFunction_AServerDataManager_ServerOnly_RequestFittingFromAPI_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AServerDataManager_ServerOnly_RequestFittingFromAPI_Statics::PropPointers), sizeof(Z_Construct_UFunction_AServerDataManager_ServerOnly_RequestFittingFromAPI_Statics::ServerDataManager_eventServerOnly_RequestFittingFromAPI_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AServerDataManager_ServerOnly_RequestFittingFromAPI_Statics::Function_MetaDataParams), Z_Construct_UFunction_AServerDataManager_ServerOnly_RequestFittingFromAPI_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AServerDataManager_ServerOnly_RequestFittingFromAPI_Statics::ServerDataManager_eventServerOnly_RequestFittingFromAPI_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AServerDataManager_ServerOnly_RequestFittingFromAPI()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AServerDataManager_ServerOnly_RequestFittingFromAPI_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AServerDataManager::execServerOnly_RequestFittingFromAPI)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_CharacterID);
	P_GET_PROPERTY(FStrProperty,Z_Param_APIBaseURLOverride);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerOnly_RequestFittingFromAPI(Z_Param_CharacterID,Z_Param_APIBaseURLOverride);
	P_NATIVE_END;
}
// ********** End Class AServerDataManager Function ServerOnly_RequestFittingFromAPI ***************

// ********** Begin Class AServerDataManager Function ServerOnly_ValidateFitting *******************
struct Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateFitting_Statics
{
	struct ServerDataManager_eventServerOnly_ValidateFitting_Parms
	{
		FCommon_ShipFittingData FittingData;
		float ShipBaseCPU;
		float ShipBasePowergrid;
		FString OutErrorMessage;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Server|Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Validate Fitting Requirements\n\x09 * Validates that a fitting meets ship requirements (CPU, Powergrid)\n\x09 * @param FittingData - The fitting to validate\n\x09 * @param ShipBaseCPU - Ship's base CPU capacity\n\x09 * @param ShipBasePowergrid - Ship's base powergrid capacity\n\x09 * @param OutErrorMessage - Error message if validation fails\n\x09 * @return true if fitting is valid\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Server/Managers/ServerDataManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Validate Fitting Requirements\nValidates that a fitting meets ship requirements (CPU, Powergrid)\n@param FittingData - The fitting to validate\n@param ShipBaseCPU - Ship's base CPU capacity\n@param ShipBasePowergrid - Ship's base powergrid capacity\n@param OutErrorMessage - Error message if validation fails\n@return true if fitting is valid" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FittingData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_FittingData;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ShipBaseCPU;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ShipBasePowergrid;
	static const UECodeGen_Private::FStrPropertyParams NewProp_OutErrorMessage;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateFitting_Statics::NewProp_FittingData = { "FittingData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ServerDataManager_eventServerOnly_ValidateFitting_Parms, FittingData), Z_Construct_UScriptStruct_FCommon_ShipFittingData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FittingData_MetaData), NewProp_FittingData_MetaData) }; // 1329122485
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateFitting_Statics::NewProp_ShipBaseCPU = { "ShipBaseCPU", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ServerDataManager_eventServerOnly_ValidateFitting_Parms, ShipBaseCPU), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateFitting_Statics::NewProp_ShipBasePowergrid = { "ShipBasePowergrid", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ServerDataManager_eventServerOnly_ValidateFitting_Parms, ShipBasePowergrid), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateFitting_Statics::NewProp_OutErrorMessage = { "OutErrorMessage", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ServerDataManager_eventServerOnly_ValidateFitting_Parms, OutErrorMessage), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateFitting_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ServerDataManager_eventServerOnly_ValidateFitting_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateFitting_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ServerDataManager_eventServerOnly_ValidateFitting_Parms), &Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateFitting_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateFitting_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateFitting_Statics::NewProp_FittingData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateFitting_Statics::NewProp_ShipBaseCPU,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateFitting_Statics::NewProp_ShipBasePowergrid,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateFitting_Statics::NewProp_OutErrorMessage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateFitting_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateFitting_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateFitting_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AServerDataManager, nullptr, "ServerOnly_ValidateFitting", Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateFitting_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateFitting_Statics::PropPointers), sizeof(Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateFitting_Statics::ServerDataManager_eventServerOnly_ValidateFitting_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateFitting_Statics::Function_MetaDataParams), Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateFitting_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateFitting_Statics::ServerDataManager_eventServerOnly_ValidateFitting_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateFitting()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateFitting_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AServerDataManager::execServerOnly_ValidateFitting)
{
	P_GET_STRUCT_REF(FCommon_ShipFittingData,Z_Param_Out_FittingData);
	P_GET_PROPERTY(FFloatProperty,Z_Param_ShipBaseCPU);
	P_GET_PROPERTY(FFloatProperty,Z_Param_ShipBasePowergrid);
	P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_OutErrorMessage);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ServerOnly_ValidateFitting(Z_Param_Out_FittingData,Z_Param_ShipBaseCPU,Z_Param_ShipBasePowergrid,Z_Param_Out_OutErrorMessage);
	P_NATIVE_END;
}
// ********** End Class AServerDataManager Function ServerOnly_ValidateFitting *********************

// ********** Begin Class AServerDataManager Function ServerOnly_ValidateModuleInstallation ********
struct Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateModuleInstallation_Statics
{
	struct ServerDataManager_eventServerOnly_ValidateModuleInstallation_Parms
	{
		FCommon_ItemSlot Module;
		ESlotType SlotType;
		FCommon_ShipFittingData CurrentFitting;
		float ShipBaseCPU;
		float ShipBasePowergrid;
		FString OutErrorMessage;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Server|Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Validate Module Installation\n\x09 * Validates that a module can be installed in a specific slot\n\x09 * @param Module - The module to install\n\x09 * @param SlotType - The target slot type\n\x09 * @param CurrentFitting - Current ship fitting\n\x09 * @param ShipBaseCPU - Ship's base CPU\n\x09 * @param ShipBasePowergrid - Ship's base powergrid\n\x09 * @param OutErrorMessage - Error message if validation fails\n\x09 * @return true if module can be installed\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Server/Managers/ServerDataManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Validate Module Installation\nValidates that a module can be installed in a specific slot\n@param Module - The module to install\n@param SlotType - The target slot type\n@param CurrentFitting - Current ship fitting\n@param ShipBaseCPU - Ship's base CPU\n@param ShipBasePowergrid - Ship's base powergrid\n@param OutErrorMessage - Error message if validation fails\n@return true if module can be installed" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Module_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentFitting_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Module;
	static const UECodeGen_Private::FBytePropertyParams NewProp_SlotType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SlotType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentFitting;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ShipBaseCPU;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ShipBasePowergrid;
	static const UECodeGen_Private::FStrPropertyParams NewProp_OutErrorMessage;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateModuleInstallation_Statics::NewProp_Module = { "Module", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ServerDataManager_eventServerOnly_ValidateModuleInstallation_Parms, Module), Z_Construct_UScriptStruct_FCommon_ItemSlot, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Module_MetaData), NewProp_Module_MetaData) }; // 771062216
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateModuleInstallation_Statics::NewProp_SlotType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateModuleInstallation_Statics::NewProp_SlotType = { "SlotType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ServerDataManager_eventServerOnly_ValidateModuleInstallation_Parms, SlotType), Z_Construct_UEnum_Echoes_ESlotType, METADATA_PARAMS(0, nullptr) }; // 780113368
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateModuleInstallation_Statics::NewProp_CurrentFitting = { "CurrentFitting", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ServerDataManager_eventServerOnly_ValidateModuleInstallation_Parms, CurrentFitting), Z_Construct_UScriptStruct_FCommon_ShipFittingData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentFitting_MetaData), NewProp_CurrentFitting_MetaData) }; // 1329122485
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateModuleInstallation_Statics::NewProp_ShipBaseCPU = { "ShipBaseCPU", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ServerDataManager_eventServerOnly_ValidateModuleInstallation_Parms, ShipBaseCPU), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateModuleInstallation_Statics::NewProp_ShipBasePowergrid = { "ShipBasePowergrid", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ServerDataManager_eventServerOnly_ValidateModuleInstallation_Parms, ShipBasePowergrid), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateModuleInstallation_Statics::NewProp_OutErrorMessage = { "OutErrorMessage", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ServerDataManager_eventServerOnly_ValidateModuleInstallation_Parms, OutErrorMessage), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateModuleInstallation_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ServerDataManager_eventServerOnly_ValidateModuleInstallation_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateModuleInstallation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ServerDataManager_eventServerOnly_ValidateModuleInstallation_Parms), &Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateModuleInstallation_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateModuleInstallation_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateModuleInstallation_Statics::NewProp_Module,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateModuleInstallation_Statics::NewProp_SlotType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateModuleInstallation_Statics::NewProp_SlotType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateModuleInstallation_Statics::NewProp_CurrentFitting,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateModuleInstallation_Statics::NewProp_ShipBaseCPU,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateModuleInstallation_Statics::NewProp_ShipBasePowergrid,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateModuleInstallation_Statics::NewProp_OutErrorMessage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateModuleInstallation_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateModuleInstallation_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateModuleInstallation_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AServerDataManager, nullptr, "ServerOnly_ValidateModuleInstallation", Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateModuleInstallation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateModuleInstallation_Statics::PropPointers), sizeof(Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateModuleInstallation_Statics::ServerDataManager_eventServerOnly_ValidateModuleInstallation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateModuleInstallation_Statics::Function_MetaDataParams), Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateModuleInstallation_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateModuleInstallation_Statics::ServerDataManager_eventServerOnly_ValidateModuleInstallation_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateModuleInstallation()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateModuleInstallation_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AServerDataManager::execServerOnly_ValidateModuleInstallation)
{
	P_GET_STRUCT_REF(FCommon_ItemSlot,Z_Param_Out_Module);
	P_GET_ENUM(ESlotType,Z_Param_SlotType);
	P_GET_STRUCT_REF(FCommon_ShipFittingData,Z_Param_Out_CurrentFitting);
	P_GET_PROPERTY(FFloatProperty,Z_Param_ShipBaseCPU);
	P_GET_PROPERTY(FFloatProperty,Z_Param_ShipBasePowergrid);
	P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_OutErrorMessage);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ServerOnly_ValidateModuleInstallation(Z_Param_Out_Module,ESlotType(Z_Param_SlotType),Z_Param_Out_CurrentFitting,Z_Param_ShipBaseCPU,Z_Param_ShipBasePowergrid,Z_Param_Out_OutErrorMessage);
	P_NATIVE_END;
}
// ********** End Class AServerDataManager Function ServerOnly_ValidateModuleInstallation **********

// ********** Begin Class AServerDataManager *******************************************************
void AServerDataManager::StaticRegisterNativesAServerDataManager()
{
	UClass* Class = AServerDataManager::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetAPIBaseURL", &AServerDataManager::execGetAPIBaseURL },
		{ "GetServerSecret", &AServerDataManager::execGetServerSecret },
		{ "ServerOnly_CalculateFinalStats", &AServerDataManager::execServerOnly_CalculateFinalStats },
		{ "ServerOnly_ParseFittingDataFromJSON", &AServerDataManager::execServerOnly_ParseFittingDataFromJSON },
		{ "ServerOnly_ParseModuleFromJSON", &AServerDataManager::execServerOnly_ParseModuleFromJSON },
		{ "ServerOnly_RequestFittingFromAPI", &AServerDataManager::execServerOnly_RequestFittingFromAPI },
		{ "ServerOnly_ValidateFitting", &AServerDataManager::execServerOnly_ValidateFitting },
		{ "ServerOnly_ValidateModuleInstallation", &AServerDataManager::execServerOnly_ValidateModuleInstallation },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_AServerDataManager;
UClass* AServerDataManager::GetPrivateStaticClass()
{
	using TClass = AServerDataManager;
	if (!Z_Registration_Info_UClass_AServerDataManager.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ServerDataManager"),
			Z_Registration_Info_UClass_AServerDataManager.InnerSingleton,
			StaticRegisterNativesAServerDataManager,
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
	return Z_Registration_Info_UClass_AServerDataManager.InnerSingleton;
}
UClass* Z_Construct_UClass_AServerDataManager_NoRegister()
{
	return AServerDataManager::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AServerDataManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Server Data Manager\n * Handles data synchronization from ASP.NET Core backend to UE Server\n * Parses JSON responses and populates game data structures\n */" },
#endif
		{ "IncludePath", "Core/Server/Managers/ServerDataManager.h" },
		{ "ModuleRelativePath", "Core/Server/Managers/ServerDataManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Server Data Manager\nHandles data synchronization from ASP.NET Core backend to UE Server\nParses JSON responses and populates game data structures" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_APIBaseURL_MetaData[] = {
		{ "Category", "Server|Configuration" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** API Base URL (configurable) */" },
#endif
		{ "ModuleRelativePath", "Core/Server/Managers/ServerDataManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "API Base URL (configurable)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ServerSecret_MetaData[] = {
		{ "Category", "Server|Configuration" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Server Secret for API authentication */" },
#endif
		{ "ModuleRelativePath", "Core/Server/Managers/ServerDataManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Server Secret for API authentication" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_APIBaseURL;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ServerSecret;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AServerDataManager_GetAPIBaseURL, "GetAPIBaseURL" }, // 3600818041
		{ &Z_Construct_UFunction_AServerDataManager_GetServerSecret, "GetServerSecret" }, // 1273924947
		{ &Z_Construct_UFunction_AServerDataManager_ServerOnly_CalculateFinalStats, "ServerOnly_CalculateFinalStats" }, // 2508606948
		{ &Z_Construct_UFunction_AServerDataManager_ServerOnly_ParseFittingDataFromJSON, "ServerOnly_ParseFittingDataFromJSON" }, // 1253688470
		{ &Z_Construct_UFunction_AServerDataManager_ServerOnly_ParseModuleFromJSON, "ServerOnly_ParseModuleFromJSON" }, // 2405405198
		{ &Z_Construct_UFunction_AServerDataManager_ServerOnly_RequestFittingFromAPI, "ServerOnly_RequestFittingFromAPI" }, // 3333713906
		{ &Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateFitting, "ServerOnly_ValidateFitting" }, // 1061939390
		{ &Z_Construct_UFunction_AServerDataManager_ServerOnly_ValidateModuleInstallation, "ServerOnly_ValidateModuleInstallation" }, // 891387789
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AServerDataManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AServerDataManager_Statics::NewProp_APIBaseURL = { "APIBaseURL", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AServerDataManager, APIBaseURL), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_APIBaseURL_MetaData), NewProp_APIBaseURL_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AServerDataManager_Statics::NewProp_ServerSecret = { "ServerSecret", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AServerDataManager, ServerSecret), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ServerSecret_MetaData), NewProp_ServerSecret_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AServerDataManager_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AServerDataManager_Statics::NewProp_APIBaseURL,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AServerDataManager_Statics::NewProp_ServerSecret,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AServerDataManager_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AServerDataManager_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AServerDataManager_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AServerDataManager_Statics::ClassParams = {
	&AServerDataManager::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AServerDataManager_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AServerDataManager_Statics::PropPointers),
	0,
	0x009001A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AServerDataManager_Statics::Class_MetaDataParams), Z_Construct_UClass_AServerDataManager_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AServerDataManager()
{
	if (!Z_Registration_Info_UClass_AServerDataManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AServerDataManager.OuterSingleton, Z_Construct_UClass_AServerDataManager_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AServerDataManager.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AServerDataManager);
AServerDataManager::~AServerDataManager() {}
// ********** End Class AServerDataManager *********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_Managers_ServerDataManager_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AServerDataManager, AServerDataManager::StaticClass, TEXT("AServerDataManager"), &Z_Registration_Info_UClass_AServerDataManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AServerDataManager), 2422968078U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_Managers_ServerDataManager_h__Script_Echoes_3436784127(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_Managers_ServerDataManager_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_Managers_ServerDataManager_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
