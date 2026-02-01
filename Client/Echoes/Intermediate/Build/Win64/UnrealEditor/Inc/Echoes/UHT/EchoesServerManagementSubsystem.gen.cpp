// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EchoesServerManagementSubsystem.h"
#include "EchoesServerDiscoveryTypes.h"
#include "Engine/GameInstance.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesServerManagementSubsystem() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ECHOES_API UClass* Z_Construct_UClass_UEchoesServerManagementSubsystem();
ECHOES_API UClass* Z_Construct_UClass_UEchoesServerManagementSubsystem_NoRegister();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnRegionalClusterConfigReceived__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnServerConfigReceived__DelegateSignature();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FServerRegionalClusterConfig();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FServerSystemConfig();
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FOnServerConfigReceived ***********************************************
struct Z_Construct_UDelegateFunction_Echoes_OnServerConfigReceived__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnServerConfigReceived_Parms
	{
		FServerSystemConfig Config;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Delegate for when server configuration is received from backend\n * Used by WorldGenerator to spawn planets, stargates, stations, etc.\n */" },
#endif
		{ "ModuleRelativePath", "Core/Server/Managers/EchoesServerManagementSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Delegate for when server configuration is received from backend\nUsed by WorldGenerator to spawn planets, stargates, stations, etc." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Config_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Config;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_Echoes_OnServerConfigReceived__DelegateSignature_Statics::NewProp_Config = { "Config", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnServerConfigReceived_Parms, Config), Z_Construct_UScriptStruct_FServerSystemConfig, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Config_MetaData), NewProp_Config_MetaData) }; // 1674105224
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnServerConfigReceived__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnServerConfigReceived__DelegateSignature_Statics::NewProp_Config,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnServerConfigReceived__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnServerConfigReceived__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnServerConfigReceived__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnServerConfigReceived__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnServerConfigReceived__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnServerConfigReceived__DelegateSignature_Statics::_Script_Echoes_eventOnServerConfigReceived_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnServerConfigReceived__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnServerConfigReceived__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnServerConfigReceived__DelegateSignature_Statics::_Script_Echoes_eventOnServerConfigReceived_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnServerConfigReceived__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnServerConfigReceived__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnServerConfigReceived_DelegateWrapper(const FMulticastScriptDelegate& OnServerConfigReceived, FServerSystemConfig const& Config)
{
	struct _Script_Echoes_eventOnServerConfigReceived_Parms
	{
		FServerSystemConfig Config;
	};
	_Script_Echoes_eventOnServerConfigReceived_Parms Parms;
	Parms.Config=Config;
	OnServerConfigReceived.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnServerConfigReceived *************************************************

// ********** Begin Delegate FOnRegionalClusterConfigReceived **************************************
struct Z_Construct_UDelegateFunction_Echoes_OnRegionalClusterConfigReceived__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnRegionalClusterConfigReceived_Parms
	{
		FServerRegionalClusterConfig RegionalConfig;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Delegate for when regional cluster configuration is received from backend\n * Used by WorldGenerator to spawn multiple systems with spatial offsets\n */" },
#endif
		{ "ModuleRelativePath", "Core/Server/Managers/EchoesServerManagementSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Delegate for when regional cluster configuration is received from backend\nUsed by WorldGenerator to spawn multiple systems with spatial offsets" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RegionalConfig_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_RegionalConfig;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_Echoes_OnRegionalClusterConfigReceived__DelegateSignature_Statics::NewProp_RegionalConfig = { "RegionalConfig", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnRegionalClusterConfigReceived_Parms, RegionalConfig), Z_Construct_UScriptStruct_FServerRegionalClusterConfig, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RegionalConfig_MetaData), NewProp_RegionalConfig_MetaData) }; // 3659141395
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnRegionalClusterConfigReceived__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnRegionalClusterConfigReceived__DelegateSignature_Statics::NewProp_RegionalConfig,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnRegionalClusterConfigReceived__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnRegionalClusterConfigReceived__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnRegionalClusterConfigReceived__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnRegionalClusterConfigReceived__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnRegionalClusterConfigReceived__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnRegionalClusterConfigReceived__DelegateSignature_Statics::_Script_Echoes_eventOnRegionalClusterConfigReceived_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnRegionalClusterConfigReceived__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnRegionalClusterConfigReceived__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnRegionalClusterConfigReceived__DelegateSignature_Statics::_Script_Echoes_eventOnRegionalClusterConfigReceived_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnRegionalClusterConfigReceived__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnRegionalClusterConfigReceived__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnRegionalClusterConfigReceived_DelegateWrapper(const FMulticastScriptDelegate& OnRegionalClusterConfigReceived, FServerRegionalClusterConfig const& RegionalConfig)
{
	struct _Script_Echoes_eventOnRegionalClusterConfigReceived_Parms
	{
		FServerRegionalClusterConfig RegionalConfig;
	};
	_Script_Echoes_eventOnRegionalClusterConfigReceived_Parms Parms;
	Parms.RegionalConfig=RegionalConfig;
	OnRegionalClusterConfigReceived.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnRegionalClusterConfigReceived ****************************************

// ********** Begin Class UEchoesServerManagementSubsystem Function GetInstanceId ******************
struct Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetInstanceId_Statics
{
	struct EchoesServerManagementSubsystem_eventGetInstanceId_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the unique instance ID for this server\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Server/Managers/EchoesServerManagementSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the unique instance ID for this server" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetInstanceId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesServerManagementSubsystem_eventGetInstanceId_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetInstanceId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetInstanceId_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetInstanceId_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetInstanceId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesServerManagementSubsystem, nullptr, "GetInstanceId", Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetInstanceId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetInstanceId_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetInstanceId_Statics::EchoesServerManagementSubsystem_eventGetInstanceId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetInstanceId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetInstanceId_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetInstanceId_Statics::EchoesServerManagementSubsystem_eventGetInstanceId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetInstanceId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetInstanceId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesServerManagementSubsystem::execGetInstanceId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GetInstanceId();
	P_NATIVE_END;
}
// ********** End Class UEchoesServerManagementSubsystem Function GetInstanceId ********************

// ********** Begin Class UEchoesServerManagementSubsystem Function GetRegionalConfig **************
struct Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetRegionalConfig_Statics
{
	struct EchoesServerManagementSubsystem_eventGetRegionalConfig_Parms
	{
		FServerRegionalClusterConfig ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get cached regional cluster configuration\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Server/Managers/EchoesServerManagementSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get cached regional cluster configuration" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetRegionalConfig_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000008000582, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesServerManagementSubsystem_eventGetRegionalConfig_Parms, ReturnValue), Z_Construct_UScriptStruct_FServerRegionalClusterConfig, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) }; // 3659141395
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetRegionalConfig_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetRegionalConfig_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetRegionalConfig_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetRegionalConfig_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesServerManagementSubsystem, nullptr, "GetRegionalConfig", Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetRegionalConfig_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetRegionalConfig_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetRegionalConfig_Statics::EchoesServerManagementSubsystem_eventGetRegionalConfig_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetRegionalConfig_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetRegionalConfig_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetRegionalConfig_Statics::EchoesServerManagementSubsystem_eventGetRegionalConfig_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetRegionalConfig()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetRegionalConfig_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesServerManagementSubsystem::execGetRegionalConfig)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FServerRegionalClusterConfig*)Z_Param__Result=P_THIS->GetRegionalConfig();
	P_NATIVE_END;
}
// ********** End Class UEchoesServerManagementSubsystem Function GetRegionalConfig ****************

// ********** Begin Class UEchoesServerManagementSubsystem Function GetServerId ********************
struct Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetServerId_Statics
{
	struct EchoesServerManagementSubsystem_eventGetServerId_Parms
	{
		FGuid ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get server ID assigned by backend\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Server/Managers/EchoesServerManagementSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get server ID assigned by backend" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetServerId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesServerManagementSubsystem_eventGetServerId_Parms, ReturnValue), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetServerId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetServerId_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetServerId_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetServerId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesServerManagementSubsystem, nullptr, "GetServerId", Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetServerId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetServerId_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetServerId_Statics::EchoesServerManagementSubsystem_eventGetServerId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetServerId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetServerId_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetServerId_Statics::EchoesServerManagementSubsystem_eventGetServerId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetServerId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetServerId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesServerManagementSubsystem::execGetServerId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGuid*)Z_Param__Result=P_THIS->GetServerId();
	P_NATIVE_END;
}
// ********** End Class UEchoesServerManagementSubsystem Function GetServerId **********************

// ********** Begin Class UEchoesServerManagementSubsystem Function GetServerType ******************
struct Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetServerType_Statics
{
	struct EchoesServerManagementSubsystem_eventGetServerType_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get server type (DedicatedSystem or RegionalCluster)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Server/Managers/EchoesServerManagementSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get server type (DedicatedSystem or RegionalCluster)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetServerType_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesServerManagementSubsystem_eventGetServerType_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetServerType_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetServerType_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetServerType_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetServerType_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesServerManagementSubsystem, nullptr, "GetServerType", Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetServerType_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetServerType_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetServerType_Statics::EchoesServerManagementSubsystem_eventGetServerType_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetServerType_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetServerType_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetServerType_Statics::EchoesServerManagementSubsystem_eventGetServerType_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetServerType()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetServerType_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesServerManagementSubsystem::execGetServerType)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GetServerType();
	P_NATIVE_END;
}
// ********** End Class UEchoesServerManagementSubsystem Function GetServerType ********************

// ********** Begin Class UEchoesServerManagementSubsystem Function IsRegionalCluster **************
struct Z_Construct_UFunction_UEchoesServerManagementSubsystem_IsRegionalCluster_Statics
{
	struct EchoesServerManagementSubsystem_eventIsRegionalCluster_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if this is a regional cluster server\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Server/Managers/EchoesServerManagementSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if this is a regional cluster server" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UEchoesServerManagementSubsystem_IsRegionalCluster_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((EchoesServerManagementSubsystem_eventIsRegionalCluster_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UEchoesServerManagementSubsystem_IsRegionalCluster_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EchoesServerManagementSubsystem_eventIsRegionalCluster_Parms), &Z_Construct_UFunction_UEchoesServerManagementSubsystem_IsRegionalCluster_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesServerManagementSubsystem_IsRegionalCluster_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesServerManagementSubsystem_IsRegionalCluster_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesServerManagementSubsystem_IsRegionalCluster_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesServerManagementSubsystem_IsRegionalCluster_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesServerManagementSubsystem, nullptr, "IsRegionalCluster", Z_Construct_UFunction_UEchoesServerManagementSubsystem_IsRegionalCluster_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesServerManagementSubsystem_IsRegionalCluster_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesServerManagementSubsystem_IsRegionalCluster_Statics::EchoesServerManagementSubsystem_eventIsRegionalCluster_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesServerManagementSubsystem_IsRegionalCluster_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesServerManagementSubsystem_IsRegionalCluster_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesServerManagementSubsystem_IsRegionalCluster_Statics::EchoesServerManagementSubsystem_eventIsRegionalCluster_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesServerManagementSubsystem_IsRegionalCluster()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesServerManagementSubsystem_IsRegionalCluster_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesServerManagementSubsystem::execIsRegionalCluster)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsRegionalCluster();
	P_NATIVE_END;
}
// ********** End Class UEchoesServerManagementSubsystem Function IsRegionalCluster ****************

// ********** Begin Class UEchoesServerManagementSubsystem Function IsServerRegistered *************
struct Z_Construct_UFunction_UEchoesServerManagementSubsystem_IsServerRegistered_Statics
{
	struct EchoesServerManagementSubsystem_eventIsServerRegistered_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if server is registered with backend\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Server/Managers/EchoesServerManagementSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if server is registered with backend" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UEchoesServerManagementSubsystem_IsServerRegistered_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((EchoesServerManagementSubsystem_eventIsServerRegistered_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UEchoesServerManagementSubsystem_IsServerRegistered_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EchoesServerManagementSubsystem_eventIsServerRegistered_Parms), &Z_Construct_UFunction_UEchoesServerManagementSubsystem_IsServerRegistered_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesServerManagementSubsystem_IsServerRegistered_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesServerManagementSubsystem_IsServerRegistered_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesServerManagementSubsystem_IsServerRegistered_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesServerManagementSubsystem_IsServerRegistered_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesServerManagementSubsystem, nullptr, "IsServerRegistered", Z_Construct_UFunction_UEchoesServerManagementSubsystem_IsServerRegistered_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesServerManagementSubsystem_IsServerRegistered_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesServerManagementSubsystem_IsServerRegistered_Statics::EchoesServerManagementSubsystem_eventIsServerRegistered_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesServerManagementSubsystem_IsServerRegistered_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesServerManagementSubsystem_IsServerRegistered_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesServerManagementSubsystem_IsServerRegistered_Statics::EchoesServerManagementSubsystem_eventIsServerRegistered_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesServerManagementSubsystem_IsServerRegistered()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesServerManagementSubsystem_IsServerRegistered_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesServerManagementSubsystem::execIsServerRegistered)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsServerRegistered();
	P_NATIVE_END;
}
// ********** End Class UEchoesServerManagementSubsystem Function IsServerRegistered ***************

// ********** Begin Class UEchoesServerManagementSubsystem Function ServerOnly_GetConfig ***********
struct Z_Construct_UFunction_UEchoesServerManagementSubsystem_ServerOnly_GetConfig_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Request universe configuration from backend\n\x09 * Called automatically after successful registration\n\x09 * Response triggers OnServerConfigReceived delegate\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Server/Managers/EchoesServerManagementSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Request universe configuration from backend\nCalled automatically after successful registration\nResponse triggers OnServerConfigReceived delegate" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesServerManagementSubsystem_ServerOnly_GetConfig_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesServerManagementSubsystem, nullptr, "ServerOnly_GetConfig", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesServerManagementSubsystem_ServerOnly_GetConfig_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesServerManagementSubsystem_ServerOnly_GetConfig_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesServerManagementSubsystem_ServerOnly_GetConfig()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesServerManagementSubsystem_ServerOnly_GetConfig_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesServerManagementSubsystem::execServerOnly_GetConfig)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerOnly_GetConfig();
	P_NATIVE_END;
}
// ********** End Class UEchoesServerManagementSubsystem Function ServerOnly_GetConfig *************

// ********** Begin Class UEchoesServerManagementSubsystem Function ServerOnly_Heartbeat ***********
struct Z_Construct_UFunction_UEchoesServerManagementSubsystem_ServerOnly_Heartbeat_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Send heartbeat to backend with current metrics\n\x09 * Called automatically every 30 seconds by timer\n\x09 * If backend returns 404 (server not found), triggers re-registration\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Server/Managers/EchoesServerManagementSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Send heartbeat to backend with current metrics\nCalled automatically every 30 seconds by timer\nIf backend returns 404 (server not found), triggers re-registration" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesServerManagementSubsystem_ServerOnly_Heartbeat_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesServerManagementSubsystem, nullptr, "ServerOnly_Heartbeat", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesServerManagementSubsystem_ServerOnly_Heartbeat_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesServerManagementSubsystem_ServerOnly_Heartbeat_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesServerManagementSubsystem_ServerOnly_Heartbeat()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesServerManagementSubsystem_ServerOnly_Heartbeat_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesServerManagementSubsystem::execServerOnly_Heartbeat)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerOnly_Heartbeat();
	P_NATIVE_END;
}
// ********** End Class UEchoesServerManagementSubsystem Function ServerOnly_Heartbeat *************

// ********** Begin Class UEchoesServerManagementSubsystem Function ServerOnly_Register ************
struct Z_Construct_UFunction_UEchoesServerManagementSubsystem_ServerOnly_Register_Statics
{
	struct EchoesServerManagementSubsystem_eventServerOnly_Register_Parms
	{
		FString InstanceId;
		int32 InGamePort;
		FGuid SolarSystemId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Register this server with the backend (The Handshake)\n\x09 * Called automatically during Initialize() if running as dedicated server\n\x09 * Can also be triggered manually from GameMode\n\x09 * \n\x09 * @param InstanceId - Unique GUID for this server instance\n\x09 * @param GamePort - Port for game connections\n\x09 * @param SolarSystemId - Solar system this server hosts (for DedicatedSystem mode)\n\x09 */" },
#endif
		{ "CPP_Default_InGamePort", "7777" },
		{ "CPP_Default_SolarSystemId", "()" },
		{ "ModuleRelativePath", "Core/Server/Managers/EchoesServerManagementSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Register this server with the backend (The Handshake)\nCalled automatically during Initialize() if running as dedicated server\nCan also be triggered manually from GameMode\n\n@param InstanceId - Unique GUID for this server instance\n@param GamePort - Port for game connections\n@param SolarSystemId - Solar system this server hosts (for DedicatedSystem mode)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InstanceId_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SolarSystemId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_InstanceId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_InGamePort;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SolarSystemId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEchoesServerManagementSubsystem_ServerOnly_Register_Statics::NewProp_InstanceId = { "InstanceId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesServerManagementSubsystem_eventServerOnly_Register_Parms, InstanceId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InstanceId_MetaData), NewProp_InstanceId_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UEchoesServerManagementSubsystem_ServerOnly_Register_Statics::NewProp_InGamePort = { "InGamePort", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesServerManagementSubsystem_eventServerOnly_Register_Parms, InGamePort), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesServerManagementSubsystem_ServerOnly_Register_Statics::NewProp_SolarSystemId = { "SolarSystemId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesServerManagementSubsystem_eventServerOnly_Register_Parms, SolarSystemId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SolarSystemId_MetaData), NewProp_SolarSystemId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesServerManagementSubsystem_ServerOnly_Register_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesServerManagementSubsystem_ServerOnly_Register_Statics::NewProp_InstanceId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesServerManagementSubsystem_ServerOnly_Register_Statics::NewProp_InGamePort,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesServerManagementSubsystem_ServerOnly_Register_Statics::NewProp_SolarSystemId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesServerManagementSubsystem_ServerOnly_Register_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesServerManagementSubsystem_ServerOnly_Register_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesServerManagementSubsystem, nullptr, "ServerOnly_Register", Z_Construct_UFunction_UEchoesServerManagementSubsystem_ServerOnly_Register_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesServerManagementSubsystem_ServerOnly_Register_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesServerManagementSubsystem_ServerOnly_Register_Statics::EchoesServerManagementSubsystem_eventServerOnly_Register_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesServerManagementSubsystem_ServerOnly_Register_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesServerManagementSubsystem_ServerOnly_Register_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesServerManagementSubsystem_ServerOnly_Register_Statics::EchoesServerManagementSubsystem_eventServerOnly_Register_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesServerManagementSubsystem_ServerOnly_Register()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesServerManagementSubsystem_ServerOnly_Register_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesServerManagementSubsystem::execServerOnly_Register)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InstanceId);
	P_GET_PROPERTY(FIntProperty,Z_Param_InGamePort);
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_SolarSystemId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerOnly_Register(Z_Param_InstanceId,Z_Param_InGamePort,Z_Param_Out_SolarSystemId);
	P_NATIVE_END;
}
// ********** End Class UEchoesServerManagementSubsystem Function ServerOnly_Register **************

// ********** Begin Class UEchoesServerManagementSubsystem Function ServerOnly_Unregister **********
struct Z_Construct_UFunction_UEchoesServerManagementSubsystem_ServerOnly_Unregister_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Unregister server from backend (graceful shutdown)\n\x09 * Called automatically during Deinitialize()\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Server/Managers/EchoesServerManagementSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Unregister server from backend (graceful shutdown)\nCalled automatically during Deinitialize()" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesServerManagementSubsystem_ServerOnly_Unregister_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesServerManagementSubsystem, nullptr, "ServerOnly_Unregister", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesServerManagementSubsystem_ServerOnly_Unregister_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesServerManagementSubsystem_ServerOnly_Unregister_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesServerManagementSubsystem_ServerOnly_Unregister()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesServerManagementSubsystem_ServerOnly_Unregister_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesServerManagementSubsystem::execServerOnly_Unregister)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerOnly_Unregister();
	P_NATIVE_END;
}
// ********** End Class UEchoesServerManagementSubsystem Function ServerOnly_Unregister ************

// ********** Begin Class UEchoesServerManagementSubsystem *****************************************
void UEchoesServerManagementSubsystem::StaticRegisterNativesUEchoesServerManagementSubsystem()
{
	UClass* Class = UEchoesServerManagementSubsystem::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetInstanceId", &UEchoesServerManagementSubsystem::execGetInstanceId },
		{ "GetRegionalConfig", &UEchoesServerManagementSubsystem::execGetRegionalConfig },
		{ "GetServerId", &UEchoesServerManagementSubsystem::execGetServerId },
		{ "GetServerType", &UEchoesServerManagementSubsystem::execGetServerType },
		{ "IsRegionalCluster", &UEchoesServerManagementSubsystem::execIsRegionalCluster },
		{ "IsServerRegistered", &UEchoesServerManagementSubsystem::execIsServerRegistered },
		{ "ServerOnly_GetConfig", &UEchoesServerManagementSubsystem::execServerOnly_GetConfig },
		{ "ServerOnly_Heartbeat", &UEchoesServerManagementSubsystem::execServerOnly_Heartbeat },
		{ "ServerOnly_Register", &UEchoesServerManagementSubsystem::execServerOnly_Register },
		{ "ServerOnly_Unregister", &UEchoesServerManagementSubsystem::execServerOnly_Unregister },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UEchoesServerManagementSubsystem;
UClass* UEchoesServerManagementSubsystem::GetPrivateStaticClass()
{
	using TClass = UEchoesServerManagementSubsystem;
	if (!Z_Registration_Info_UClass_UEchoesServerManagementSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesServerManagementSubsystem"),
			Z_Registration_Info_UClass_UEchoesServerManagementSubsystem.InnerSingleton,
			StaticRegisterNativesUEchoesServerManagementSubsystem,
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
	return Z_Registration_Info_UClass_UEchoesServerManagementSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UEchoesServerManagementSubsystem_NoRegister()
{
	return UEchoesServerManagementSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UEchoesServerManagementSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * UEchoesServerManagementSubsystem\n * \n * Server Management Subsystem for Echoes Dedicated Server\n * Handles server lifecycle, registration, heartbeat, and configuration sync with ASP.NET Core backend\n * \n * Architecture:\n * - GameInstanceSubsystem: Persists across level transitions (server side only)\n * - Only runs when NetMode == NM_DedicatedServer\n * - All requests to backend must include X-Server-Secret header\n * - Backend is the source of truth for all server state\n * \n * Lifecycle:\n * 1. Initialize() - Called on server startup, triggers registration\n * 2. ServerOnly_Register() - The Handshake with backend\n * 3. ServerOnly_StartHeartbeat() - Begin 30-second heartbeat timer\n * 4. ServerOnly_GetConfig() - Fetch universe configuration from backend\n * 5. Deinitialize() - Graceful shutdown, unregister from backend\n */" },
#endif
		{ "IncludePath", "Core/Server/Managers/EchoesServerManagementSubsystem.h" },
		{ "ModuleRelativePath", "Core/Server/Managers/EchoesServerManagementSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UEchoesServerManagementSubsystem\n\nServer Management Subsystem for Echoes Dedicated Server\nHandles server lifecycle, registration, heartbeat, and configuration sync with ASP.NET Core backend\n\nArchitecture:\n- GameInstanceSubsystem: Persists across level transitions (server side only)\n- Only runs when NetMode == NM_DedicatedServer\n- All requests to backend must include X-Server-Secret header\n- Backend is the source of truth for all server state\n\nLifecycle:\n1. Initialize() - Called on server startup, triggers registration\n2. ServerOnly_Register() - The Handshake with backend\n3. ServerOnly_StartHeartbeat() - Begin 30-second heartbeat timer\n4. ServerOnly_GetConfig() - Fetch universe configuration from backend\n5. Deinitialize() - Graceful shutdown, unregister from backend" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnServerConfigReceived_MetaData[] = {
		{ "Category", "Echoes|Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Broadcast when server configuration is received (WorldGenerator subscribes to this) */" },
#endif
		{ "ModuleRelativePath", "Core/Server/Managers/EchoesServerManagementSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Broadcast when server configuration is received (WorldGenerator subscribes to this)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnRegionalClusterConfigReceived_MetaData[] = {
		{ "Category", "Echoes|Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Broadcast when regional cluster configuration is received (WorldGenerator subscribes to this) */" },
#endif
		{ "ModuleRelativePath", "Core/Server/Managers/EchoesServerManagementSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Broadcast when regional cluster configuration is received (WorldGenerator subscribes to this)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BackendURL_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Backend API base URL */" },
#endif
		{ "ModuleRelativePath", "Core/Server/Managers/EchoesServerManagementSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Backend API base URL" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ServerSecret_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Server secret for authentication (X-Server-Secret header) */" },
#endif
		{ "ModuleRelativePath", "Core/Server/Managers/EchoesServerManagementSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Server secret for authentication (X-Server-Secret header)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ServerInstanceId_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Unique instance ID for this server (GUID) */" },
#endif
		{ "ModuleRelativePath", "Core/Server/Managers/EchoesServerManagementSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Unique instance ID for this server (GUID)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ServerId_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Server ID assigned by backend after registration */" },
#endif
		{ "ModuleRelativePath", "Core/Server/Managers/EchoesServerManagementSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Server ID assigned by backend after registration" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsRegistered_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether server is registered with backend */" },
#endif
		{ "ModuleRelativePath", "Core/Server/Managers/EchoesServerManagementSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether server is registered with backend" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentSolarSystemId_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Solar system ID this server hosts (for DedicatedSystem mode) */" },
#endif
		{ "ModuleRelativePath", "Core/Server/Managers/EchoesServerManagementSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Solar system ID this server hosts (for DedicatedSystem mode)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GamePort_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Game port for client connections */" },
#endif
		{ "ModuleRelativePath", "Core/Server/Managers/EchoesServerManagementSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Game port for client connections" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ServerType_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Node type: \"DedicatedSystem\" or \"RegionalCluster\" */" },
#endif
		{ "ModuleRelativePath", "Core/Server/Managers/EchoesServerManagementSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Node type: \"DedicatedSystem\" or \"RegionalCluster\"" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentRegionId_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Region ID this server hosts (for RegionalCluster mode) */" },
#endif
		{ "ModuleRelativePath", "Core/Server/Managers/EchoesServerManagementSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Region ID this server hosts (for RegionalCluster mode)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CachedConfig_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Cached server configuration received from backend (DedicatedSystem mode) */" },
#endif
		{ "ModuleRelativePath", "Core/Server/Managers/EchoesServerManagementSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cached server configuration received from backend (DedicatedSystem mode)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CachedRegionalConfig_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Cached regional cluster configuration received from backend (RegionalCluster mode) */" },
#endif
		{ "ModuleRelativePath", "Core/Server/Managers/EchoesServerManagementSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cached regional cluster configuration received from backend (RegionalCluster mode)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnServerConfigReceived;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnRegionalClusterConfigReceived;
	static const UECodeGen_Private::FStrPropertyParams NewProp_BackendURL;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ServerSecret;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ServerInstanceId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ServerId;
	static void NewProp_bIsRegistered_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsRegistered;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentSolarSystemId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_GamePort;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ServerType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentRegionId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CachedConfig;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CachedRegionalConfig;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetInstanceId, "GetInstanceId" }, // 1067278714
		{ &Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetRegionalConfig, "GetRegionalConfig" }, // 7635550
		{ &Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetServerId, "GetServerId" }, // 1107558125
		{ &Z_Construct_UFunction_UEchoesServerManagementSubsystem_GetServerType, "GetServerType" }, // 3359078857
		{ &Z_Construct_UFunction_UEchoesServerManagementSubsystem_IsRegionalCluster, "IsRegionalCluster" }, // 3722830661
		{ &Z_Construct_UFunction_UEchoesServerManagementSubsystem_IsServerRegistered, "IsServerRegistered" }, // 428410746
		{ &Z_Construct_UFunction_UEchoesServerManagementSubsystem_ServerOnly_GetConfig, "ServerOnly_GetConfig" }, // 1797996127
		{ &Z_Construct_UFunction_UEchoesServerManagementSubsystem_ServerOnly_Heartbeat, "ServerOnly_Heartbeat" }, // 3719494717
		{ &Z_Construct_UFunction_UEchoesServerManagementSubsystem_ServerOnly_Register, "ServerOnly_Register" }, // 3576710583
		{ &Z_Construct_UFunction_UEchoesServerManagementSubsystem_ServerOnly_Unregister, "ServerOnly_Unregister" }, // 508875178
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEchoesServerManagementSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEchoesServerManagementSubsystem_Statics::NewProp_OnServerConfigReceived = { "OnServerConfigReceived", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesServerManagementSubsystem, OnServerConfigReceived), Z_Construct_UDelegateFunction_Echoes_OnServerConfigReceived__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnServerConfigReceived_MetaData), NewProp_OnServerConfigReceived_MetaData) }; // 2367962766
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEchoesServerManagementSubsystem_Statics::NewProp_OnRegionalClusterConfigReceived = { "OnRegionalClusterConfigReceived", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesServerManagementSubsystem, OnRegionalClusterConfigReceived), Z_Construct_UDelegateFunction_Echoes_OnRegionalClusterConfigReceived__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnRegionalClusterConfigReceived_MetaData), NewProp_OnRegionalClusterConfigReceived_MetaData) }; // 711187048
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UEchoesServerManagementSubsystem_Statics::NewProp_BackendURL = { "BackendURL", nullptr, (EPropertyFlags)0x0040000000004000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesServerManagementSubsystem, BackendURL), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BackendURL_MetaData), NewProp_BackendURL_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UEchoesServerManagementSubsystem_Statics::NewProp_ServerSecret = { "ServerSecret", nullptr, (EPropertyFlags)0x0040000000004000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesServerManagementSubsystem, ServerSecret), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ServerSecret_MetaData), NewProp_ServerSecret_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UEchoesServerManagementSubsystem_Statics::NewProp_ServerInstanceId = { "ServerInstanceId", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesServerManagementSubsystem, ServerInstanceId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ServerInstanceId_MetaData), NewProp_ServerInstanceId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEchoesServerManagementSubsystem_Statics::NewProp_ServerId = { "ServerId", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesServerManagementSubsystem, ServerId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ServerId_MetaData), NewProp_ServerId_MetaData) };
void Z_Construct_UClass_UEchoesServerManagementSubsystem_Statics::NewProp_bIsRegistered_SetBit(void* Obj)
{
	((UEchoesServerManagementSubsystem*)Obj)->bIsRegistered = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UEchoesServerManagementSubsystem_Statics::NewProp_bIsRegistered = { "bIsRegistered", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UEchoesServerManagementSubsystem), &Z_Construct_UClass_UEchoesServerManagementSubsystem_Statics::NewProp_bIsRegistered_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsRegistered_MetaData), NewProp_bIsRegistered_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEchoesServerManagementSubsystem_Statics::NewProp_CurrentSolarSystemId = { "CurrentSolarSystemId", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesServerManagementSubsystem, CurrentSolarSystemId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentSolarSystemId_MetaData), NewProp_CurrentSolarSystemId_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UEchoesServerManagementSubsystem_Statics::NewProp_GamePort = { "GamePort", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesServerManagementSubsystem, GamePort), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GamePort_MetaData), NewProp_GamePort_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UEchoesServerManagementSubsystem_Statics::NewProp_ServerType = { "ServerType", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesServerManagementSubsystem, ServerType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ServerType_MetaData), NewProp_ServerType_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEchoesServerManagementSubsystem_Statics::NewProp_CurrentRegionId = { "CurrentRegionId", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesServerManagementSubsystem, CurrentRegionId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentRegionId_MetaData), NewProp_CurrentRegionId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEchoesServerManagementSubsystem_Statics::NewProp_CachedConfig = { "CachedConfig", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesServerManagementSubsystem, CachedConfig), Z_Construct_UScriptStruct_FServerSystemConfig, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CachedConfig_MetaData), NewProp_CachedConfig_MetaData) }; // 1674105224
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEchoesServerManagementSubsystem_Statics::NewProp_CachedRegionalConfig = { "CachedRegionalConfig", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesServerManagementSubsystem, CachedRegionalConfig), Z_Construct_UScriptStruct_FServerRegionalClusterConfig, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CachedRegionalConfig_MetaData), NewProp_CachedRegionalConfig_MetaData) }; // 3659141395
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEchoesServerManagementSubsystem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesServerManagementSubsystem_Statics::NewProp_OnServerConfigReceived,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesServerManagementSubsystem_Statics::NewProp_OnRegionalClusterConfigReceived,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesServerManagementSubsystem_Statics::NewProp_BackendURL,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesServerManagementSubsystem_Statics::NewProp_ServerSecret,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesServerManagementSubsystem_Statics::NewProp_ServerInstanceId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesServerManagementSubsystem_Statics::NewProp_ServerId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesServerManagementSubsystem_Statics::NewProp_bIsRegistered,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesServerManagementSubsystem_Statics::NewProp_CurrentSolarSystemId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesServerManagementSubsystem_Statics::NewProp_GamePort,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesServerManagementSubsystem_Statics::NewProp_ServerType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesServerManagementSubsystem_Statics::NewProp_CurrentRegionId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesServerManagementSubsystem_Statics::NewProp_CachedConfig,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesServerManagementSubsystem_Statics::NewProp_CachedRegionalConfig,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesServerManagementSubsystem_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UEchoesServerManagementSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesServerManagementSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEchoesServerManagementSubsystem_Statics::ClassParams = {
	&UEchoesServerManagementSubsystem::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UEchoesServerManagementSubsystem_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesServerManagementSubsystem_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesServerManagementSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UEchoesServerManagementSubsystem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEchoesServerManagementSubsystem()
{
	if (!Z_Registration_Info_UClass_UEchoesServerManagementSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEchoesServerManagementSubsystem.OuterSingleton, Z_Construct_UClass_UEchoesServerManagementSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEchoesServerManagementSubsystem.OuterSingleton;
}
UEchoesServerManagementSubsystem::UEchoesServerManagementSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UEchoesServerManagementSubsystem);
UEchoesServerManagementSubsystem::~UEchoesServerManagementSubsystem() {}
// ********** End Class UEchoesServerManagementSubsystem *******************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_Managers_EchoesServerManagementSubsystem_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEchoesServerManagementSubsystem, UEchoesServerManagementSubsystem::StaticClass, TEXT("UEchoesServerManagementSubsystem"), &Z_Registration_Info_UClass_UEchoesServerManagementSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEchoesServerManagementSubsystem), 3911746889U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_Managers_EchoesServerManagementSubsystem_h__Script_Echoes_3867458592(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_Managers_EchoesServerManagementSubsystem_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_Managers_EchoesServerManagementSubsystem_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
