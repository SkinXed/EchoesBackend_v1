// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EchoesServerDiscoveryTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesServerDiscoveryTypes() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FDateTime();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FAnomalyConfig();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FAsteroidBeltConfig();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FHeartbeatRequest();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FHeartbeatResponse();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FMoonConfig();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FPlanetConfig();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FRegisterServerRequest();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FRegisterServerResponse();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FResourceConfig();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FServerConfigRequest();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FServerConfigResponse();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FServerRegionalClusterConfig();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FServerRegionalClusterConfigResponse();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FServerSystemConfig();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FStargateConfig();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FStationConfig();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FWormholeConfig();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FRegisterServerRequest ********************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FRegisterServerRequest;
class UScriptStruct* FRegisterServerRequest::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FRegisterServerRequest.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FRegisterServerRequest.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FRegisterServerRequest, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("RegisterServerRequest"));
	}
	return Z_Registration_Info_UScriptStruct_FRegisterServerRequest.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FRegisterServerRequest_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Server registration request (mirrors C# RegisterServerRequestDto)\n */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Server registration request (mirrors C# RegisterServerRequestDto)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InstanceId_MetaData[] = {
		{ "Category", "Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Unique identifier for this server instance (GUID) */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Unique identifier for this server instance (GUID)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PublicIP_MetaData[] = {
		{ "Category", "Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Public IP address where the game server can be reached by clients */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Public IP address where the game server can be reached by clients" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GamePort_MetaData[] = {
		{ "Category", "Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Port number for game client connections */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Port number for game client connections" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WebPort_MetaData[] = {
		{ "Category", "Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Port number for web/API connections to the game server */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Port number for web/API connections to the game server" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SolarSystemId_MetaData[] = {
		{ "Category", "Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional: Solar System ID if this is a dedicated server for a specific system */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional: Solar System ID if this is a dedicated server for a specific system" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RegionId_MetaData[] = {
		{ "Category", "Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional: Region ID if this is a regional cluster server handling multiple systems */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional: Region ID if this is a regional cluster server handling multiple systems" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ServerType_MetaData[] = {
		{ "Category", "Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Node type: \"DedicatedSystem\" or \"RegionalCluster\" */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Node type: \"DedicatedSystem\" or \"RegionalCluster\"" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxPlayers_MetaData[] = {
		{ "Category", "Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum number of concurrent players this server can handle */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum number of concurrent players this server can handle" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GeoRegion_MetaData[] = {
		{ "Category", "Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Geographic region code for this server (e.g., \"EU\", \"US\", \"ASIA\") */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Geographic region code for this server (e.g., \"EU\", \"US\", \"ASIA\")" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GameVersion_MetaData[] = {
		{ "Category", "Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Game version running on this server */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Game version running on this server" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Hostname_MetaData[] = {
		{ "Category", "Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Hostname of the machine running the server */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Hostname of the machine running the server" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ServerTags_MetaData[] = {
		{ "Category", "Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Comma-separated tags for server filtering and categorization */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Comma-separated tags for server filtering and categorization" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_InstanceId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_PublicIP;
	static const UECodeGen_Private::FIntPropertyParams NewProp_GamePort;
	static const UECodeGen_Private::FIntPropertyParams NewProp_WebPort;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SolarSystemId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RegionId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ServerType;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxPlayers;
	static const UECodeGen_Private::FStrPropertyParams NewProp_GeoRegion;
	static const UECodeGen_Private::FStrPropertyParams NewProp_GameVersion;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Hostname;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ServerTags;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FRegisterServerRequest>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FRegisterServerRequest_Statics::NewProp_InstanceId = { "InstanceId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRegisterServerRequest, InstanceId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InstanceId_MetaData), NewProp_InstanceId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FRegisterServerRequest_Statics::NewProp_PublicIP = { "PublicIP", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRegisterServerRequest, PublicIP), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PublicIP_MetaData), NewProp_PublicIP_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FRegisterServerRequest_Statics::NewProp_GamePort = { "GamePort", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRegisterServerRequest, GamePort), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GamePort_MetaData), NewProp_GamePort_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FRegisterServerRequest_Statics::NewProp_WebPort = { "WebPort", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRegisterServerRequest, WebPort), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WebPort_MetaData), NewProp_WebPort_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FRegisterServerRequest_Statics::NewProp_SolarSystemId = { "SolarSystemId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRegisterServerRequest, SolarSystemId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SolarSystemId_MetaData), NewProp_SolarSystemId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FRegisterServerRequest_Statics::NewProp_RegionId = { "RegionId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRegisterServerRequest, RegionId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RegionId_MetaData), NewProp_RegionId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FRegisterServerRequest_Statics::NewProp_ServerType = { "ServerType", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRegisterServerRequest, ServerType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ServerType_MetaData), NewProp_ServerType_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FRegisterServerRequest_Statics::NewProp_MaxPlayers = { "MaxPlayers", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRegisterServerRequest, MaxPlayers), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxPlayers_MetaData), NewProp_MaxPlayers_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FRegisterServerRequest_Statics::NewProp_GeoRegion = { "GeoRegion", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRegisterServerRequest, GeoRegion), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GeoRegion_MetaData), NewProp_GeoRegion_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FRegisterServerRequest_Statics::NewProp_GameVersion = { "GameVersion", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRegisterServerRequest, GameVersion), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GameVersion_MetaData), NewProp_GameVersion_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FRegisterServerRequest_Statics::NewProp_Hostname = { "Hostname", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRegisterServerRequest, Hostname), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Hostname_MetaData), NewProp_Hostname_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FRegisterServerRequest_Statics::NewProp_ServerTags = { "ServerTags", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRegisterServerRequest, ServerTags), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ServerTags_MetaData), NewProp_ServerTags_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FRegisterServerRequest_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRegisterServerRequest_Statics::NewProp_InstanceId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRegisterServerRequest_Statics::NewProp_PublicIP,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRegisterServerRequest_Statics::NewProp_GamePort,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRegisterServerRequest_Statics::NewProp_WebPort,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRegisterServerRequest_Statics::NewProp_SolarSystemId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRegisterServerRequest_Statics::NewProp_RegionId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRegisterServerRequest_Statics::NewProp_ServerType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRegisterServerRequest_Statics::NewProp_MaxPlayers,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRegisterServerRequest_Statics::NewProp_GeoRegion,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRegisterServerRequest_Statics::NewProp_GameVersion,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRegisterServerRequest_Statics::NewProp_Hostname,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRegisterServerRequest_Statics::NewProp_ServerTags,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRegisterServerRequest_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FRegisterServerRequest_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"RegisterServerRequest",
	Z_Construct_UScriptStruct_FRegisterServerRequest_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRegisterServerRequest_Statics::PropPointers),
	sizeof(FRegisterServerRequest),
	alignof(FRegisterServerRequest),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRegisterServerRequest_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FRegisterServerRequest_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FRegisterServerRequest()
{
	if (!Z_Registration_Info_UScriptStruct_FRegisterServerRequest.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FRegisterServerRequest.InnerSingleton, Z_Construct_UScriptStruct_FRegisterServerRequest_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FRegisterServerRequest.InnerSingleton;
}
// ********** End ScriptStruct FRegisterServerRequest **********************************************

// ********** Begin ScriptStruct FRegisterServerResponse *******************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FRegisterServerResponse;
class UScriptStruct* FRegisterServerResponse::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FRegisterServerResponse.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FRegisterServerResponse.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FRegisterServerResponse, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("RegisterServerResponse"));
	}
	return Z_Registration_Info_UScriptStruct_FRegisterServerResponse.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FRegisterServerResponse_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Server registration response (mirrors C# RegisterServerResponseDto)\n */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Server registration response (mirrors C# RegisterServerResponseDto)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Success_MetaData[] = {
		{ "Category", "Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether registration was successful */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether registration was successful" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ServerId_MetaData[] = {
		{ "Category", "Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Unique server ID assigned by backend */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Unique server ID assigned by backend" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InstanceId_MetaData[] = {
		{ "Category", "Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Instance ID that was registered */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Instance ID that was registered" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NodeType_MetaData[] = {
		{ "Category", "Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Node type: \"DedicatedSystem\" or \"RegionalCluster\" */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Node type: \"DedicatedSystem\" or \"RegionalCluster\"" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
		{ "Category", "Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Response message from backend */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Response message from backend" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_Success_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_Success;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ServerId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_InstanceId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_NodeType;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Message;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FRegisterServerResponse>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
void Z_Construct_UScriptStruct_FRegisterServerResponse_Statics::NewProp_Success_SetBit(void* Obj)
{
	((FRegisterServerResponse*)Obj)->Success = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FRegisterServerResponse_Statics::NewProp_Success = { "Success", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FRegisterServerResponse), &Z_Construct_UScriptStruct_FRegisterServerResponse_Statics::NewProp_Success_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Success_MetaData), NewProp_Success_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FRegisterServerResponse_Statics::NewProp_ServerId = { "ServerId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRegisterServerResponse, ServerId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ServerId_MetaData), NewProp_ServerId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FRegisterServerResponse_Statics::NewProp_InstanceId = { "InstanceId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRegisterServerResponse, InstanceId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InstanceId_MetaData), NewProp_InstanceId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FRegisterServerResponse_Statics::NewProp_NodeType = { "NodeType", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRegisterServerResponse, NodeType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NodeType_MetaData), NewProp_NodeType_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FRegisterServerResponse_Statics::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRegisterServerResponse, Message), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FRegisterServerResponse_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRegisterServerResponse_Statics::NewProp_Success,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRegisterServerResponse_Statics::NewProp_ServerId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRegisterServerResponse_Statics::NewProp_InstanceId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRegisterServerResponse_Statics::NewProp_NodeType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRegisterServerResponse_Statics::NewProp_Message,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRegisterServerResponse_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FRegisterServerResponse_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"RegisterServerResponse",
	Z_Construct_UScriptStruct_FRegisterServerResponse_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRegisterServerResponse_Statics::PropPointers),
	sizeof(FRegisterServerResponse),
	alignof(FRegisterServerResponse),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRegisterServerResponse_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FRegisterServerResponse_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FRegisterServerResponse()
{
	if (!Z_Registration_Info_UScriptStruct_FRegisterServerResponse.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FRegisterServerResponse.InnerSingleton, Z_Construct_UScriptStruct_FRegisterServerResponse_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FRegisterServerResponse.InnerSingleton;
}
// ********** End ScriptStruct FRegisterServerResponse *********************************************

// ********** Begin ScriptStruct FHeartbeatRequest *************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FHeartbeatRequest;
class UScriptStruct* FHeartbeatRequest::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FHeartbeatRequest.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FHeartbeatRequest.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FHeartbeatRequest, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("HeartbeatRequest"));
	}
	return Z_Registration_Info_UScriptStruct_FHeartbeatRequest.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FHeartbeatRequest_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Heartbeat request (mirrors C# HeartbeatRequestDto)\n */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Heartbeat request (mirrors C# HeartbeatRequestDto)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InstanceId_MetaData[] = {
		{ "Category", "Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Unique identifier of the server instance sending the heartbeat */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Unique identifier of the server instance sending the heartbeat" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Status_MetaData[] = {
		{ "Category", "Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current operational status of the game server (0=Starting, 1=Ready, 2=Stopping, 3=Error) */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current operational status of the game server (0=Starting, 1=Ready, 2=Stopping, 3=Error)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnlinePlayers_MetaData[] = {
		{ "Category", "Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Number of players currently connected to the server */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Number of players currently connected to the server" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CPUUsage_MetaData[] = {
		{ "Category", "Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current CPU usage percentage (0-100) */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current CPU usage percentage (0-100)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MemoryUsageMB_MetaData[] = {
		{ "Category", "Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current memory usage in megabytes */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current memory usage in megabytes" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NetworkInKbps_MetaData[] = {
		{ "Category", "Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Incoming network traffic in kilobits per second */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Incoming network traffic in kilobits per second" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NetworkOutKbps_MetaData[] = {
		{ "Category", "Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Outgoing network traffic in kilobits per second */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Outgoing network traffic in kilobits per second" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_InstanceId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Status;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OnlinePlayers;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CPUUsage;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_MemoryUsageMB;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NetworkInKbps;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NetworkOutKbps;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FHeartbeatRequest>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FHeartbeatRequest_Statics::NewProp_InstanceId = { "InstanceId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHeartbeatRequest, InstanceId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InstanceId_MetaData), NewProp_InstanceId_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FHeartbeatRequest_Statics::NewProp_Status = { "Status", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHeartbeatRequest, Status), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Status_MetaData), NewProp_Status_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FHeartbeatRequest_Statics::NewProp_OnlinePlayers = { "OnlinePlayers", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHeartbeatRequest, OnlinePlayers), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnlinePlayers_MetaData), NewProp_OnlinePlayers_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FHeartbeatRequest_Statics::NewProp_CPUUsage = { "CPUUsage", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHeartbeatRequest, CPUUsage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CPUUsage_MetaData), NewProp_CPUUsage_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FHeartbeatRequest_Statics::NewProp_MemoryUsageMB = { "MemoryUsageMB", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHeartbeatRequest, MemoryUsageMB), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MemoryUsageMB_MetaData), NewProp_MemoryUsageMB_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FHeartbeatRequest_Statics::NewProp_NetworkInKbps = { "NetworkInKbps", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHeartbeatRequest, NetworkInKbps), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NetworkInKbps_MetaData), NewProp_NetworkInKbps_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FHeartbeatRequest_Statics::NewProp_NetworkOutKbps = { "NetworkOutKbps", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHeartbeatRequest, NetworkOutKbps), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NetworkOutKbps_MetaData), NewProp_NetworkOutKbps_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FHeartbeatRequest_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHeartbeatRequest_Statics::NewProp_InstanceId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHeartbeatRequest_Statics::NewProp_Status,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHeartbeatRequest_Statics::NewProp_OnlinePlayers,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHeartbeatRequest_Statics::NewProp_CPUUsage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHeartbeatRequest_Statics::NewProp_MemoryUsageMB,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHeartbeatRequest_Statics::NewProp_NetworkInKbps,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHeartbeatRequest_Statics::NewProp_NetworkOutKbps,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHeartbeatRequest_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FHeartbeatRequest_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"HeartbeatRequest",
	Z_Construct_UScriptStruct_FHeartbeatRequest_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHeartbeatRequest_Statics::PropPointers),
	sizeof(FHeartbeatRequest),
	alignof(FHeartbeatRequest),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHeartbeatRequest_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FHeartbeatRequest_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FHeartbeatRequest()
{
	if (!Z_Registration_Info_UScriptStruct_FHeartbeatRequest.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FHeartbeatRequest.InnerSingleton, Z_Construct_UScriptStruct_FHeartbeatRequest_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FHeartbeatRequest.InnerSingleton;
}
// ********** End ScriptStruct FHeartbeatRequest ***************************************************

// ********** Begin ScriptStruct FHeartbeatResponse ************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FHeartbeatResponse;
class UScriptStruct* FHeartbeatResponse::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FHeartbeatResponse.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FHeartbeatResponse.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FHeartbeatResponse, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("HeartbeatResponse"));
	}
	return Z_Registration_Info_UScriptStruct_FHeartbeatResponse.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FHeartbeatResponse_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Heartbeat response (mirrors C# HeartbeatResponseDto)\n */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Heartbeat response (mirrors C# HeartbeatResponseDto)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Success_MetaData[] = {
		{ "Category", "Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether heartbeat was successful */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether heartbeat was successful" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Timestamp_MetaData[] = {
		{ "Category", "Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Timestamp of heartbeat acknowledgment */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Timestamp of heartbeat acknowledgment" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NextHeartbeatInSeconds_MetaData[] = {
		{ "Category", "Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Seconds until next heartbeat should be sent */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Seconds until next heartbeat should be sent" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_Success_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_Success;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Timestamp;
	static const UECodeGen_Private::FIntPropertyParams NewProp_NextHeartbeatInSeconds;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FHeartbeatResponse>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
void Z_Construct_UScriptStruct_FHeartbeatResponse_Statics::NewProp_Success_SetBit(void* Obj)
{
	((FHeartbeatResponse*)Obj)->Success = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FHeartbeatResponse_Statics::NewProp_Success = { "Success", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FHeartbeatResponse), &Z_Construct_UScriptStruct_FHeartbeatResponse_Statics::NewProp_Success_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Success_MetaData), NewProp_Success_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FHeartbeatResponse_Statics::NewProp_Timestamp = { "Timestamp", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHeartbeatResponse, Timestamp), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Timestamp_MetaData), NewProp_Timestamp_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FHeartbeatResponse_Statics::NewProp_NextHeartbeatInSeconds = { "NextHeartbeatInSeconds", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHeartbeatResponse, NextHeartbeatInSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NextHeartbeatInSeconds_MetaData), NewProp_NextHeartbeatInSeconds_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FHeartbeatResponse_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHeartbeatResponse_Statics::NewProp_Success,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHeartbeatResponse_Statics::NewProp_Timestamp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHeartbeatResponse_Statics::NewProp_NextHeartbeatInSeconds,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHeartbeatResponse_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FHeartbeatResponse_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"HeartbeatResponse",
	Z_Construct_UScriptStruct_FHeartbeatResponse_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHeartbeatResponse_Statics::PropPointers),
	sizeof(FHeartbeatResponse),
	alignof(FHeartbeatResponse),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHeartbeatResponse_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FHeartbeatResponse_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FHeartbeatResponse()
{
	if (!Z_Registration_Info_UScriptStruct_FHeartbeatResponse.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FHeartbeatResponse.InnerSingleton, Z_Construct_UScriptStruct_FHeartbeatResponse_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FHeartbeatResponse.InnerSingleton;
}
// ********** End ScriptStruct FHeartbeatResponse **************************************************

// ********** Begin ScriptStruct FResourceConfig ***************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FResourceConfig;
class UScriptStruct* FResourceConfig::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FResourceConfig.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FResourceConfig.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FResourceConfig, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("ResourceConfig"));
	}
	return Z_Registration_Info_UScriptStruct_FResourceConfig.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FResourceConfig_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Resource configuration (mirrors C# ResourceConfigDto)\n */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Resource configuration (mirrors C# ResourceConfigDto)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Id_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ResourceType_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Quantity_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Richness_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Id;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ResourceType;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Quantity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Richness;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FResourceConfig>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FResourceConfig_Statics::NewProp_Id = { "Id", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FResourceConfig, Id), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Id_MetaData), NewProp_Id_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FResourceConfig_Statics::NewProp_ResourceType = { "ResourceType", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FResourceConfig, ResourceType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ResourceType_MetaData), NewProp_ResourceType_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FResourceConfig_Statics::NewProp_Quantity = { "Quantity", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FResourceConfig, Quantity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Quantity_MetaData), NewProp_Quantity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FResourceConfig_Statics::NewProp_Richness = { "Richness", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FResourceConfig, Richness), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Richness_MetaData), NewProp_Richness_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FResourceConfig_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FResourceConfig_Statics::NewProp_Id,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FResourceConfig_Statics::NewProp_ResourceType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FResourceConfig_Statics::NewProp_Quantity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FResourceConfig_Statics::NewProp_Richness,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FResourceConfig_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FResourceConfig_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"ResourceConfig",
	Z_Construct_UScriptStruct_FResourceConfig_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FResourceConfig_Statics::PropPointers),
	sizeof(FResourceConfig),
	alignof(FResourceConfig),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FResourceConfig_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FResourceConfig_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FResourceConfig()
{
	if (!Z_Registration_Info_UScriptStruct_FResourceConfig.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FResourceConfig.InnerSingleton, Z_Construct_UScriptStruct_FResourceConfig_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FResourceConfig.InnerSingleton;
}
// ********** End ScriptStruct FResourceConfig *****************************************************

// ********** Begin ScriptStruct FMoonConfig *******************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FMoonConfig;
class UScriptStruct* FMoonConfig::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FMoonConfig.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FMoonConfig.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FMoonConfig, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("MoonConfig"));
	}
	return Z_Registration_Info_UScriptStruct_FMoonConfig.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FMoonConfig_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Moon configuration (mirrors C# MoonConfigDto)\n */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Moon configuration (mirrors C# MoonConfigDto)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Id_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Radius_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PositionX_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PositionY_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PositionZ_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Id;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_Radius;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_PositionX;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_PositionY;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_PositionZ;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMoonConfig>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMoonConfig_Statics::NewProp_Id = { "Id", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMoonConfig, Id), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Id_MetaData), NewProp_Id_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FMoonConfig_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMoonConfig, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FMoonConfig_Statics::NewProp_Radius = { "Radius", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMoonConfig, Radius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Radius_MetaData), NewProp_Radius_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FMoonConfig_Statics::NewProp_PositionX = { "PositionX", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMoonConfig, PositionX), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PositionX_MetaData), NewProp_PositionX_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FMoonConfig_Statics::NewProp_PositionY = { "PositionY", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMoonConfig, PositionY), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PositionY_MetaData), NewProp_PositionY_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FMoonConfig_Statics::NewProp_PositionZ = { "PositionZ", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMoonConfig, PositionZ), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PositionZ_MetaData), NewProp_PositionZ_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMoonConfig_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMoonConfig_Statics::NewProp_Id,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMoonConfig_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMoonConfig_Statics::NewProp_Radius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMoonConfig_Statics::NewProp_PositionX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMoonConfig_Statics::NewProp_PositionY,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMoonConfig_Statics::NewProp_PositionZ,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMoonConfig_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMoonConfig_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"MoonConfig",
	Z_Construct_UScriptStruct_FMoonConfig_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMoonConfig_Statics::PropPointers),
	sizeof(FMoonConfig),
	alignof(FMoonConfig),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMoonConfig_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FMoonConfig_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FMoonConfig()
{
	if (!Z_Registration_Info_UScriptStruct_FMoonConfig.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FMoonConfig.InnerSingleton, Z_Construct_UScriptStruct_FMoonConfig_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FMoonConfig.InnerSingleton;
}
// ********** End ScriptStruct FMoonConfig *********************************************************

// ********** Begin ScriptStruct FPlanetConfig *****************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FPlanetConfig;
class UScriptStruct* FPlanetConfig::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FPlanetConfig.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FPlanetConfig.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPlanetConfig, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("PlanetConfig"));
	}
	return Z_Registration_Info_UScriptStruct_FPlanetConfig.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FPlanetConfig_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Planet configuration (mirrors C# PlanetConfigDto)\n */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Planet configuration (mirrors C# PlanetConfigDto)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Id_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Type_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OrbitDistance_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Radius_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PositionX_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PositionY_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PositionZ_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Moons_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Resources_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Id;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Type;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OrbitDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Radius;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_PositionX;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_PositionY;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_PositionZ;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Moons_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Moons;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Resources_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Resources;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPlanetConfig>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPlanetConfig_Statics::NewProp_Id = { "Id", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlanetConfig, Id), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Id_MetaData), NewProp_Id_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPlanetConfig_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlanetConfig, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPlanetConfig_Statics::NewProp_Type = { "Type", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlanetConfig, Type), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Type_MetaData), NewProp_Type_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPlanetConfig_Statics::NewProp_OrbitDistance = { "OrbitDistance", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlanetConfig, OrbitDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OrbitDistance_MetaData), NewProp_OrbitDistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPlanetConfig_Statics::NewProp_Radius = { "Radius", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlanetConfig, Radius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Radius_MetaData), NewProp_Radius_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FPlanetConfig_Statics::NewProp_PositionX = { "PositionX", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlanetConfig, PositionX), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PositionX_MetaData), NewProp_PositionX_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FPlanetConfig_Statics::NewProp_PositionY = { "PositionY", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlanetConfig, PositionY), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PositionY_MetaData), NewProp_PositionY_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FPlanetConfig_Statics::NewProp_PositionZ = { "PositionZ", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlanetConfig, PositionZ), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PositionZ_MetaData), NewProp_PositionZ_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPlanetConfig_Statics::NewProp_Moons_Inner = { "Moons", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FMoonConfig, METADATA_PARAMS(0, nullptr) }; // 3436544343
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FPlanetConfig_Statics::NewProp_Moons = { "Moons", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlanetConfig, Moons), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Moons_MetaData), NewProp_Moons_MetaData) }; // 3436544343
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPlanetConfig_Statics::NewProp_Resources_Inner = { "Resources", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FResourceConfig, METADATA_PARAMS(0, nullptr) }; // 3640410924
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FPlanetConfig_Statics::NewProp_Resources = { "Resources", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlanetConfig, Resources), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Resources_MetaData), NewProp_Resources_MetaData) }; // 3640410924
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPlanetConfig_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlanetConfig_Statics::NewProp_Id,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlanetConfig_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlanetConfig_Statics::NewProp_Type,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlanetConfig_Statics::NewProp_OrbitDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlanetConfig_Statics::NewProp_Radius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlanetConfig_Statics::NewProp_PositionX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlanetConfig_Statics::NewProp_PositionY,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlanetConfig_Statics::NewProp_PositionZ,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlanetConfig_Statics::NewProp_Moons_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlanetConfig_Statics::NewProp_Moons,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlanetConfig_Statics::NewProp_Resources_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlanetConfig_Statics::NewProp_Resources,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPlanetConfig_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPlanetConfig_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"PlanetConfig",
	Z_Construct_UScriptStruct_FPlanetConfig_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPlanetConfig_Statics::PropPointers),
	sizeof(FPlanetConfig),
	alignof(FPlanetConfig),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPlanetConfig_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPlanetConfig_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FPlanetConfig()
{
	if (!Z_Registration_Info_UScriptStruct_FPlanetConfig.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FPlanetConfig.InnerSingleton, Z_Construct_UScriptStruct_FPlanetConfig_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FPlanetConfig.InnerSingleton;
}
// ********** End ScriptStruct FPlanetConfig *******************************************************

// ********** Begin ScriptStruct FStargateConfig ***************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FStargateConfig;
class UScriptStruct* FStargateConfig::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FStargateConfig.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FStargateConfig.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FStargateConfig, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("StargateConfig"));
	}
	return Z_Registration_Info_UScriptStruct_FStargateConfig.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FStargateConfig_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Stargate configuration (mirrors C# StargateConfigDto)\n */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Stargate configuration (mirrors C# StargateConfigDto)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Id_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetSystemId_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetSystemName_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PositionX_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PositionY_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PositionZ_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IsOperational_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JumpCost_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Model_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Id;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetSystemId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_TargetSystemName;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PositionX;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PositionY;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PositionZ;
	static void NewProp_IsOperational_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_IsOperational;
	static const UECodeGen_Private::FIntPropertyParams NewProp_JumpCost;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Model;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FStargateConfig>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FStargateConfig_Statics::NewProp_Id = { "Id", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStargateConfig, Id), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Id_MetaData), NewProp_Id_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FStargateConfig_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStargateConfig, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FStargateConfig_Statics::NewProp_TargetSystemId = { "TargetSystemId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStargateConfig, TargetSystemId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetSystemId_MetaData), NewProp_TargetSystemId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FStargateConfig_Statics::NewProp_TargetSystemName = { "TargetSystemName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStargateConfig, TargetSystemName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetSystemName_MetaData), NewProp_TargetSystemName_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FStargateConfig_Statics::NewProp_PositionX = { "PositionX", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStargateConfig, PositionX), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PositionX_MetaData), NewProp_PositionX_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FStargateConfig_Statics::NewProp_PositionY = { "PositionY", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStargateConfig, PositionY), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PositionY_MetaData), NewProp_PositionY_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FStargateConfig_Statics::NewProp_PositionZ = { "PositionZ", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStargateConfig, PositionZ), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PositionZ_MetaData), NewProp_PositionZ_MetaData) };
void Z_Construct_UScriptStruct_FStargateConfig_Statics::NewProp_IsOperational_SetBit(void* Obj)
{
	((FStargateConfig*)Obj)->IsOperational = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FStargateConfig_Statics::NewProp_IsOperational = { "IsOperational", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FStargateConfig), &Z_Construct_UScriptStruct_FStargateConfig_Statics::NewProp_IsOperational_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IsOperational_MetaData), NewProp_IsOperational_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FStargateConfig_Statics::NewProp_JumpCost = { "JumpCost", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStargateConfig, JumpCost), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpCost_MetaData), NewProp_JumpCost_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FStargateConfig_Statics::NewProp_Model = { "Model", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStargateConfig, Model), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Model_MetaData), NewProp_Model_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FStargateConfig_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStargateConfig_Statics::NewProp_Id,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStargateConfig_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStargateConfig_Statics::NewProp_TargetSystemId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStargateConfig_Statics::NewProp_TargetSystemName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStargateConfig_Statics::NewProp_PositionX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStargateConfig_Statics::NewProp_PositionY,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStargateConfig_Statics::NewProp_PositionZ,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStargateConfig_Statics::NewProp_IsOperational,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStargateConfig_Statics::NewProp_JumpCost,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStargateConfig_Statics::NewProp_Model,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStargateConfig_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FStargateConfig_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"StargateConfig",
	Z_Construct_UScriptStruct_FStargateConfig_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStargateConfig_Statics::PropPointers),
	sizeof(FStargateConfig),
	alignof(FStargateConfig),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStargateConfig_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FStargateConfig_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FStargateConfig()
{
	if (!Z_Registration_Info_UScriptStruct_FStargateConfig.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FStargateConfig.InnerSingleton, Z_Construct_UScriptStruct_FStargateConfig_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FStargateConfig.InnerSingleton;
}
// ********** End ScriptStruct FStargateConfig *****************************************************

// ********** Begin ScriptStruct FStationConfig ****************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FStationConfig;
class UScriptStruct* FStationConfig::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FStationConfig.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FStationConfig.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FStationConfig, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("StationConfig"));
	}
	return Z_Registration_Info_UScriptStruct_FStationConfig.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FStationConfig_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Station configuration (mirrors C# StationConfigDto)\n */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Station configuration (mirrors C# StationConfigDto)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Id_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PositionX_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PositionY_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PositionZ_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StationType_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Id;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_PositionX;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_PositionY;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_PositionZ;
	static const UECodeGen_Private::FStrPropertyParams NewProp_StationType;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FStationConfig>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FStationConfig_Statics::NewProp_Id = { "Id", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStationConfig, Id), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Id_MetaData), NewProp_Id_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FStationConfig_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStationConfig, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FStationConfig_Statics::NewProp_PositionX = { "PositionX", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStationConfig, PositionX), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PositionX_MetaData), NewProp_PositionX_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FStationConfig_Statics::NewProp_PositionY = { "PositionY", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStationConfig, PositionY), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PositionY_MetaData), NewProp_PositionY_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FStationConfig_Statics::NewProp_PositionZ = { "PositionZ", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStationConfig, PositionZ), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PositionZ_MetaData), NewProp_PositionZ_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FStationConfig_Statics::NewProp_StationType = { "StationType", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStationConfig, StationType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StationType_MetaData), NewProp_StationType_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FStationConfig_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStationConfig_Statics::NewProp_Id,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStationConfig_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStationConfig_Statics::NewProp_PositionX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStationConfig_Statics::NewProp_PositionY,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStationConfig_Statics::NewProp_PositionZ,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStationConfig_Statics::NewProp_StationType,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStationConfig_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FStationConfig_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"StationConfig",
	Z_Construct_UScriptStruct_FStationConfig_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStationConfig_Statics::PropPointers),
	sizeof(FStationConfig),
	alignof(FStationConfig),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStationConfig_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FStationConfig_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FStationConfig()
{
	if (!Z_Registration_Info_UScriptStruct_FStationConfig.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FStationConfig.InnerSingleton, Z_Construct_UScriptStruct_FStationConfig_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FStationConfig.InnerSingleton;
}
// ********** End ScriptStruct FStationConfig ******************************************************

// ********** Begin ScriptStruct FAsteroidBeltConfig ***********************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FAsteroidBeltConfig;
class UScriptStruct* FAsteroidBeltConfig::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FAsteroidBeltConfig.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FAsteroidBeltConfig.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAsteroidBeltConfig, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("AsteroidBeltConfig"));
	}
	return Z_Registration_Info_UScriptStruct_FAsteroidBeltConfig.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FAsteroidBeltConfig_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Asteroid belt configuration (mirrors C# AsteroidBeltConfigDto)\n */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Asteroid belt configuration (mirrors C# AsteroidBeltConfigDto)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Id_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PositionX_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PositionY_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PositionZ_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Resources_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Id;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_PositionX;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_PositionY;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_PositionZ;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Resources_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Resources;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAsteroidBeltConfig>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAsteroidBeltConfig_Statics::NewProp_Id = { "Id", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAsteroidBeltConfig, Id), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Id_MetaData), NewProp_Id_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAsteroidBeltConfig_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAsteroidBeltConfig, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FAsteroidBeltConfig_Statics::NewProp_PositionX = { "PositionX", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAsteroidBeltConfig, PositionX), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PositionX_MetaData), NewProp_PositionX_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FAsteroidBeltConfig_Statics::NewProp_PositionY = { "PositionY", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAsteroidBeltConfig, PositionY), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PositionY_MetaData), NewProp_PositionY_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FAsteroidBeltConfig_Statics::NewProp_PositionZ = { "PositionZ", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAsteroidBeltConfig, PositionZ), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PositionZ_MetaData), NewProp_PositionZ_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAsteroidBeltConfig_Statics::NewProp_Resources_Inner = { "Resources", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FResourceConfig, METADATA_PARAMS(0, nullptr) }; // 3640410924
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FAsteroidBeltConfig_Statics::NewProp_Resources = { "Resources", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAsteroidBeltConfig, Resources), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Resources_MetaData), NewProp_Resources_MetaData) }; // 3640410924
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAsteroidBeltConfig_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAsteroidBeltConfig_Statics::NewProp_Id,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAsteroidBeltConfig_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAsteroidBeltConfig_Statics::NewProp_PositionX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAsteroidBeltConfig_Statics::NewProp_PositionY,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAsteroidBeltConfig_Statics::NewProp_PositionZ,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAsteroidBeltConfig_Statics::NewProp_Resources_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAsteroidBeltConfig_Statics::NewProp_Resources,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAsteroidBeltConfig_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAsteroidBeltConfig_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"AsteroidBeltConfig",
	Z_Construct_UScriptStruct_FAsteroidBeltConfig_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAsteroidBeltConfig_Statics::PropPointers),
	sizeof(FAsteroidBeltConfig),
	alignof(FAsteroidBeltConfig),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAsteroidBeltConfig_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAsteroidBeltConfig_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FAsteroidBeltConfig()
{
	if (!Z_Registration_Info_UScriptStruct_FAsteroidBeltConfig.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FAsteroidBeltConfig.InnerSingleton, Z_Construct_UScriptStruct_FAsteroidBeltConfig_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FAsteroidBeltConfig.InnerSingleton;
}
// ********** End ScriptStruct FAsteroidBeltConfig *************************************************

// ********** Begin ScriptStruct FAnomalyConfig ****************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FAnomalyConfig;
class UScriptStruct* FAnomalyConfig::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FAnomalyConfig.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FAnomalyConfig.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAnomalyConfig, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("AnomalyConfig"));
	}
	return Z_Registration_Info_UScriptStruct_FAnomalyConfig.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FAnomalyConfig_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Anomaly configuration (mirrors C# AnomalyConfigDto)\n */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Anomaly configuration (mirrors C# AnomalyConfigDto)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Id_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Type_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Difficulty_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PositionX_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PositionY_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PositionZ_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Id;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Type;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Difficulty;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_PositionX;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_PositionY;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_PositionZ;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAnomalyConfig>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnomalyConfig_Statics::NewProp_Id = { "Id", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnomalyConfig, Id), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Id_MetaData), NewProp_Id_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAnomalyConfig_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnomalyConfig, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAnomalyConfig_Statics::NewProp_Type = { "Type", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnomalyConfig, Type), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Type_MetaData), NewProp_Type_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAnomalyConfig_Statics::NewProp_Difficulty = { "Difficulty", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnomalyConfig, Difficulty), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Difficulty_MetaData), NewProp_Difficulty_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FAnomalyConfig_Statics::NewProp_PositionX = { "PositionX", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnomalyConfig, PositionX), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PositionX_MetaData), NewProp_PositionX_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FAnomalyConfig_Statics::NewProp_PositionY = { "PositionY", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnomalyConfig, PositionY), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PositionY_MetaData), NewProp_PositionY_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FAnomalyConfig_Statics::NewProp_PositionZ = { "PositionZ", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnomalyConfig, PositionZ), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PositionZ_MetaData), NewProp_PositionZ_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAnomalyConfig_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnomalyConfig_Statics::NewProp_Id,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnomalyConfig_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnomalyConfig_Statics::NewProp_Type,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnomalyConfig_Statics::NewProp_Difficulty,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnomalyConfig_Statics::NewProp_PositionX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnomalyConfig_Statics::NewProp_PositionY,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnomalyConfig_Statics::NewProp_PositionZ,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnomalyConfig_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAnomalyConfig_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"AnomalyConfig",
	Z_Construct_UScriptStruct_FAnomalyConfig_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnomalyConfig_Statics::PropPointers),
	sizeof(FAnomalyConfig),
	alignof(FAnomalyConfig),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnomalyConfig_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAnomalyConfig_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FAnomalyConfig()
{
	if (!Z_Registration_Info_UScriptStruct_FAnomalyConfig.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FAnomalyConfig.InnerSingleton, Z_Construct_UScriptStruct_FAnomalyConfig_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FAnomalyConfig.InnerSingleton;
}
// ********** End ScriptStruct FAnomalyConfig ******************************************************

// ********** Begin ScriptStruct FWormholeConfig ***************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FWormholeConfig;
class UScriptStruct* FWormholeConfig::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FWormholeConfig.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FWormholeConfig.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FWormholeConfig, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("WormholeConfig"));
	}
	return Z_Registration_Info_UScriptStruct_FWormholeConfig.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FWormholeConfig_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Wormhole configuration (mirrors C# WormholeConfigDto)\n */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Wormhole configuration (mirrors C# WormholeConfigDto)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Id_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetSystemId_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PositionX_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PositionY_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PositionZ_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Id;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetSystemId;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_PositionX;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_PositionY;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_PositionZ;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FWormholeConfig>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FWormholeConfig_Statics::NewProp_Id = { "Id", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWormholeConfig, Id), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Id_MetaData), NewProp_Id_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FWormholeConfig_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWormholeConfig, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FWormholeConfig_Statics::NewProp_TargetSystemId = { "TargetSystemId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWormholeConfig, TargetSystemId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetSystemId_MetaData), NewProp_TargetSystemId_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FWormholeConfig_Statics::NewProp_PositionX = { "PositionX", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWormholeConfig, PositionX), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PositionX_MetaData), NewProp_PositionX_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FWormholeConfig_Statics::NewProp_PositionY = { "PositionY", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWormholeConfig, PositionY), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PositionY_MetaData), NewProp_PositionY_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FWormholeConfig_Statics::NewProp_PositionZ = { "PositionZ", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWormholeConfig, PositionZ), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PositionZ_MetaData), NewProp_PositionZ_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FWormholeConfig_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWormholeConfig_Statics::NewProp_Id,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWormholeConfig_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWormholeConfig_Statics::NewProp_TargetSystemId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWormholeConfig_Statics::NewProp_PositionX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWormholeConfig_Statics::NewProp_PositionY,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWormholeConfig_Statics::NewProp_PositionZ,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWormholeConfig_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FWormholeConfig_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"WormholeConfig",
	Z_Construct_UScriptStruct_FWormholeConfig_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWormholeConfig_Statics::PropPointers),
	sizeof(FWormholeConfig),
	alignof(FWormholeConfig),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWormholeConfig_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FWormholeConfig_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FWormholeConfig()
{
	if (!Z_Registration_Info_UScriptStruct_FWormholeConfig.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FWormholeConfig.InnerSingleton, Z_Construct_UScriptStruct_FWormholeConfig_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FWormholeConfig.InnerSingleton;
}
// ********** End ScriptStruct FWormholeConfig *****************************************************

// ********** Begin ScriptStruct FServerSystemConfig ***********************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FServerSystemConfig;
class UScriptStruct* FServerSystemConfig::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FServerSystemConfig.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FServerSystemConfig.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FServerSystemConfig, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("ServerSystemConfig"));
	}
	return Z_Registration_Info_UScriptStruct_FServerSystemConfig.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FServerSystemConfig_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Solar system configuration (mirrors C# ServerSystemConfigDto)\n */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Solar system configuration (mirrors C# ServerSystemConfigDto)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SystemId_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SystemName_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SolarRadius_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SolarMass_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Temperature_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Luminosity_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SecurityStatus_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StarClass_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ConstellationId_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ConstellationName_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RegionId_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RegionName_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PositionX_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PositionY_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PositionZ_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Planets_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Stargates_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Stations_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AsteroidBelts_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Anomalies_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Wormholes_MetaData[] = {
		{ "Category", "Universe" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_SystemId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SystemName;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SolarRadius;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SolarMass;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Temperature;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Luminosity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SecurityStatus;
	static const UECodeGen_Private::FStrPropertyParams NewProp_StarClass;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ConstellationId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ConstellationName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RegionId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_RegionName;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_PositionX;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_PositionY;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_PositionZ;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Planets_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Planets;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Stargates_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Stargates;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Stations_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Stations;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AsteroidBelts_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_AsteroidBelts;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Anomalies_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Anomalies;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Wormholes_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Wormholes;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FServerSystemConfig>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_SystemId = { "SystemId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FServerSystemConfig, SystemId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SystemId_MetaData), NewProp_SystemId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_SystemName = { "SystemName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FServerSystemConfig, SystemName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SystemName_MetaData), NewProp_SystemName_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_SolarRadius = { "SolarRadius", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FServerSystemConfig, SolarRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SolarRadius_MetaData), NewProp_SolarRadius_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_SolarMass = { "SolarMass", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FServerSystemConfig, SolarMass), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SolarMass_MetaData), NewProp_SolarMass_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_Temperature = { "Temperature", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FServerSystemConfig, Temperature), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Temperature_MetaData), NewProp_Temperature_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_Luminosity = { "Luminosity", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FServerSystemConfig, Luminosity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Luminosity_MetaData), NewProp_Luminosity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_SecurityStatus = { "SecurityStatus", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FServerSystemConfig, SecurityStatus), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SecurityStatus_MetaData), NewProp_SecurityStatus_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_StarClass = { "StarClass", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FServerSystemConfig, StarClass), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StarClass_MetaData), NewProp_StarClass_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_ConstellationId = { "ConstellationId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FServerSystemConfig, ConstellationId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ConstellationId_MetaData), NewProp_ConstellationId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_ConstellationName = { "ConstellationName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FServerSystemConfig, ConstellationName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ConstellationName_MetaData), NewProp_ConstellationName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_RegionId = { "RegionId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FServerSystemConfig, RegionId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RegionId_MetaData), NewProp_RegionId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_RegionName = { "RegionName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FServerSystemConfig, RegionName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RegionName_MetaData), NewProp_RegionName_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_PositionX = { "PositionX", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FServerSystemConfig, PositionX), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PositionX_MetaData), NewProp_PositionX_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_PositionY = { "PositionY", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FServerSystemConfig, PositionY), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PositionY_MetaData), NewProp_PositionY_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_PositionZ = { "PositionZ", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FServerSystemConfig, PositionZ), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PositionZ_MetaData), NewProp_PositionZ_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_Planets_Inner = { "Planets", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FPlanetConfig, METADATA_PARAMS(0, nullptr) }; // 1449517278
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_Planets = { "Planets", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FServerSystemConfig, Planets), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Planets_MetaData), NewProp_Planets_MetaData) }; // 1449517278
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_Stargates_Inner = { "Stargates", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FStargateConfig, METADATA_PARAMS(0, nullptr) }; // 3786179722
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_Stargates = { "Stargates", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FServerSystemConfig, Stargates), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Stargates_MetaData), NewProp_Stargates_MetaData) }; // 3786179722
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_Stations_Inner = { "Stations", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FStationConfig, METADATA_PARAMS(0, nullptr) }; // 4156139141
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_Stations = { "Stations", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FServerSystemConfig, Stations), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Stations_MetaData), NewProp_Stations_MetaData) }; // 4156139141
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_AsteroidBelts_Inner = { "AsteroidBelts", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FAsteroidBeltConfig, METADATA_PARAMS(0, nullptr) }; // 2970304511
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_AsteroidBelts = { "AsteroidBelts", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FServerSystemConfig, AsteroidBelts), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AsteroidBelts_MetaData), NewProp_AsteroidBelts_MetaData) }; // 2970304511
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_Anomalies_Inner = { "Anomalies", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FAnomalyConfig, METADATA_PARAMS(0, nullptr) }; // 1662967207
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_Anomalies = { "Anomalies", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FServerSystemConfig, Anomalies), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Anomalies_MetaData), NewProp_Anomalies_MetaData) }; // 1662967207
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_Wormholes_Inner = { "Wormholes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FWormholeConfig, METADATA_PARAMS(0, nullptr) }; // 4031015292
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_Wormholes = { "Wormholes", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FServerSystemConfig, Wormholes), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Wormholes_MetaData), NewProp_Wormholes_MetaData) }; // 4031015292
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FServerSystemConfig_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_SystemId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_SystemName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_SolarRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_SolarMass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_Temperature,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_Luminosity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_SecurityStatus,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_StarClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_ConstellationId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_ConstellationName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_RegionId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_RegionName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_PositionX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_PositionY,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_PositionZ,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_Planets_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_Planets,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_Stargates_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_Stargates,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_Stations_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_Stations,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_AsteroidBelts_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_AsteroidBelts,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_Anomalies_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_Anomalies,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_Wormholes_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewProp_Wormholes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FServerSystemConfig_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FServerSystemConfig_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"ServerSystemConfig",
	Z_Construct_UScriptStruct_FServerSystemConfig_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FServerSystemConfig_Statics::PropPointers),
	sizeof(FServerSystemConfig),
	alignof(FServerSystemConfig),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FServerSystemConfig_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FServerSystemConfig_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FServerSystemConfig()
{
	if (!Z_Registration_Info_UScriptStruct_FServerSystemConfig.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FServerSystemConfig.InnerSingleton, Z_Construct_UScriptStruct_FServerSystemConfig_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FServerSystemConfig.InnerSingleton;
}
// ********** End ScriptStruct FServerSystemConfig *************************************************

// ********** Begin ScriptStruct FServerRegionalClusterConfig **************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FServerRegionalClusterConfig;
class UScriptStruct* FServerRegionalClusterConfig::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FServerRegionalClusterConfig.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FServerRegionalClusterConfig.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FServerRegionalClusterConfig, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("ServerRegionalClusterConfig"));
	}
	return Z_Registration_Info_UScriptStruct_FServerRegionalClusterConfig.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FServerRegionalClusterConfig_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Regional cluster configuration (mirrors C# ServerRegionalClusterConfigDto)\n * Contains all solar systems within a region for multi-system servers\n */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Regional cluster configuration (mirrors C# ServerRegionalClusterConfigDto)\nContains all solar systems within a region for multi-system servers" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RegionId_MetaData[] = {
		{ "Category", "Region" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Unique identifier of the region */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Unique identifier of the region" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RegionName_MetaData[] = {
		{ "Category", "Region" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Name of the region */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Name of the region" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RegionCode_MetaData[] = {
		{ "Category", "Region" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Region code identifier */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Region code identifier" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AverageSecurity_MetaData[] = {
		{ "Category", "Region" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Average security status across the region */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Average security status across the region" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ConstellationCount_MetaData[] = {
		{ "Category", "Region" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Number of constellations in this region */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Number of constellations in this region" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SystemCount_MetaData[] = {
		{ "Category", "Region" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Number of solar systems in this region */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Number of solar systems in this region" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalPlanets_MetaData[] = {
		{ "Category", "Region" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Total number of planets across all systems in the region */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Total number of planets across all systems in the region" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalStargates_MetaData[] = {
		{ "Category", "Region" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Total number of stargates across all systems in the region */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Total number of stargates across all systems in the region" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalStations_MetaData[] = {
		{ "Category", "Region" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Total number of stations across all systems in the region */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Total number of stations across all systems in the region" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Systems_MetaData[] = {
		{ "Category", "Region" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** List of all solar systems in this region */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "List of all solar systems in this region" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_RegionId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_RegionName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_RegionCode;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AverageSecurity;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ConstellationCount;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SystemCount;
	static const UECodeGen_Private::FIntPropertyParams NewProp_TotalPlanets;
	static const UECodeGen_Private::FIntPropertyParams NewProp_TotalStargates;
	static const UECodeGen_Private::FIntPropertyParams NewProp_TotalStations;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Systems_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Systems;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FServerRegionalClusterConfig>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FServerRegionalClusterConfig_Statics::NewProp_RegionId = { "RegionId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FServerRegionalClusterConfig, RegionId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RegionId_MetaData), NewProp_RegionId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FServerRegionalClusterConfig_Statics::NewProp_RegionName = { "RegionName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FServerRegionalClusterConfig, RegionName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RegionName_MetaData), NewProp_RegionName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FServerRegionalClusterConfig_Statics::NewProp_RegionCode = { "RegionCode", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FServerRegionalClusterConfig, RegionCode), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RegionCode_MetaData), NewProp_RegionCode_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FServerRegionalClusterConfig_Statics::NewProp_AverageSecurity = { "AverageSecurity", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FServerRegionalClusterConfig, AverageSecurity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AverageSecurity_MetaData), NewProp_AverageSecurity_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FServerRegionalClusterConfig_Statics::NewProp_ConstellationCount = { "ConstellationCount", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FServerRegionalClusterConfig, ConstellationCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ConstellationCount_MetaData), NewProp_ConstellationCount_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FServerRegionalClusterConfig_Statics::NewProp_SystemCount = { "SystemCount", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FServerRegionalClusterConfig, SystemCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SystemCount_MetaData), NewProp_SystemCount_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FServerRegionalClusterConfig_Statics::NewProp_TotalPlanets = { "TotalPlanets", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FServerRegionalClusterConfig, TotalPlanets), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalPlanets_MetaData), NewProp_TotalPlanets_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FServerRegionalClusterConfig_Statics::NewProp_TotalStargates = { "TotalStargates", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FServerRegionalClusterConfig, TotalStargates), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalStargates_MetaData), NewProp_TotalStargates_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FServerRegionalClusterConfig_Statics::NewProp_TotalStations = { "TotalStations", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FServerRegionalClusterConfig, TotalStations), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalStations_MetaData), NewProp_TotalStations_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FServerRegionalClusterConfig_Statics::NewProp_Systems_Inner = { "Systems", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FServerSystemConfig, METADATA_PARAMS(0, nullptr) }; // 1674105224
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FServerRegionalClusterConfig_Statics::NewProp_Systems = { "Systems", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FServerRegionalClusterConfig, Systems), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Systems_MetaData), NewProp_Systems_MetaData) }; // 1674105224
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FServerRegionalClusterConfig_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerRegionalClusterConfig_Statics::NewProp_RegionId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerRegionalClusterConfig_Statics::NewProp_RegionName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerRegionalClusterConfig_Statics::NewProp_RegionCode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerRegionalClusterConfig_Statics::NewProp_AverageSecurity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerRegionalClusterConfig_Statics::NewProp_ConstellationCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerRegionalClusterConfig_Statics::NewProp_SystemCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerRegionalClusterConfig_Statics::NewProp_TotalPlanets,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerRegionalClusterConfig_Statics::NewProp_TotalStargates,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerRegionalClusterConfig_Statics::NewProp_TotalStations,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerRegionalClusterConfig_Statics::NewProp_Systems_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerRegionalClusterConfig_Statics::NewProp_Systems,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FServerRegionalClusterConfig_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FServerRegionalClusterConfig_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"ServerRegionalClusterConfig",
	Z_Construct_UScriptStruct_FServerRegionalClusterConfig_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FServerRegionalClusterConfig_Statics::PropPointers),
	sizeof(FServerRegionalClusterConfig),
	alignof(FServerRegionalClusterConfig),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FServerRegionalClusterConfig_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FServerRegionalClusterConfig_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FServerRegionalClusterConfig()
{
	if (!Z_Registration_Info_UScriptStruct_FServerRegionalClusterConfig.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FServerRegionalClusterConfig.InnerSingleton, Z_Construct_UScriptStruct_FServerRegionalClusterConfig_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FServerRegionalClusterConfig.InnerSingleton;
}
// ********** End ScriptStruct FServerRegionalClusterConfig ****************************************

// ********** Begin ScriptStruct FServerConfigRequest **********************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FServerConfigRequest;
class UScriptStruct* FServerConfigRequest::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FServerConfigRequest.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FServerConfigRequest.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FServerConfigRequest, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("ServerConfigRequest"));
	}
	return Z_Registration_Info_UScriptStruct_FServerConfigRequest.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FServerConfigRequest_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Server configuration request (mirrors C# ServerConfigRequestDto)\n */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Server configuration request (mirrors C# ServerConfigRequestDto)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InstanceId_MetaData[] = {
		{ "Category", "Server" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ServerType_MetaData[] = {
		{ "Category", "Server" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SolarSystemId_MetaData[] = {
		{ "Category", "Server" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RegionId_MetaData[] = {
		{ "Category", "Server" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClusterId_MetaData[] = {
		{ "Category", "Server" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GeoRegion_MetaData[] = {
		{ "Category", "Server" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_InstanceId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ServerType;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SolarSystemId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RegionId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ClusterId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_GeoRegion;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FServerConfigRequest>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FServerConfigRequest_Statics::NewProp_InstanceId = { "InstanceId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FServerConfigRequest, InstanceId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InstanceId_MetaData), NewProp_InstanceId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FServerConfigRequest_Statics::NewProp_ServerType = { "ServerType", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FServerConfigRequest, ServerType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ServerType_MetaData), NewProp_ServerType_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FServerConfigRequest_Statics::NewProp_SolarSystemId = { "SolarSystemId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FServerConfigRequest, SolarSystemId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SolarSystemId_MetaData), NewProp_SolarSystemId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FServerConfigRequest_Statics::NewProp_RegionId = { "RegionId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FServerConfigRequest, RegionId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RegionId_MetaData), NewProp_RegionId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FServerConfigRequest_Statics::NewProp_ClusterId = { "ClusterId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FServerConfigRequest, ClusterId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClusterId_MetaData), NewProp_ClusterId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FServerConfigRequest_Statics::NewProp_GeoRegion = { "GeoRegion", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FServerConfigRequest, GeoRegion), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GeoRegion_MetaData), NewProp_GeoRegion_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FServerConfigRequest_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerConfigRequest_Statics::NewProp_InstanceId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerConfigRequest_Statics::NewProp_ServerType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerConfigRequest_Statics::NewProp_SolarSystemId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerConfigRequest_Statics::NewProp_RegionId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerConfigRequest_Statics::NewProp_ClusterId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerConfigRequest_Statics::NewProp_GeoRegion,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FServerConfigRequest_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FServerConfigRequest_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"ServerConfigRequest",
	Z_Construct_UScriptStruct_FServerConfigRequest_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FServerConfigRequest_Statics::PropPointers),
	sizeof(FServerConfigRequest),
	alignof(FServerConfigRequest),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FServerConfigRequest_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FServerConfigRequest_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FServerConfigRequest()
{
	if (!Z_Registration_Info_UScriptStruct_FServerConfigRequest.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FServerConfigRequest.InnerSingleton, Z_Construct_UScriptStruct_FServerConfigRequest_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FServerConfigRequest.InnerSingleton;
}
// ********** End ScriptStruct FServerConfigRequest ************************************************

// ********** Begin ScriptStruct FServerConfigResponse *********************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FServerConfigResponse;
class UScriptStruct* FServerConfigResponse::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FServerConfigResponse.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FServerConfigResponse.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FServerConfigResponse, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("ServerConfigResponse"));
	}
	return Z_Registration_Info_UScriptStruct_FServerConfigResponse.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FServerConfigResponse_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Server configuration response wrapper (mirrors C# ServerConfigResponseDto)\n */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Server configuration response wrapper (mirrors C# ServerConfigResponseDto)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Config_MetaData[] = {
		{ "Category", "Server" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Config;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FServerConfigResponse>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FServerConfigResponse_Statics::NewProp_Config = { "Config", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FServerConfigResponse, Config), Z_Construct_UScriptStruct_FServerSystemConfig, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Config_MetaData), NewProp_Config_MetaData) }; // 1674105224
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FServerConfigResponse_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerConfigResponse_Statics::NewProp_Config,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FServerConfigResponse_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FServerConfigResponse_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"ServerConfigResponse",
	Z_Construct_UScriptStruct_FServerConfigResponse_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FServerConfigResponse_Statics::PropPointers),
	sizeof(FServerConfigResponse),
	alignof(FServerConfigResponse),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FServerConfigResponse_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FServerConfigResponse_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FServerConfigResponse()
{
	if (!Z_Registration_Info_UScriptStruct_FServerConfigResponse.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FServerConfigResponse.InnerSingleton, Z_Construct_UScriptStruct_FServerConfigResponse_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FServerConfigResponse.InnerSingleton;
}
// ********** End ScriptStruct FServerConfigResponse ***********************************************

// ********** Begin ScriptStruct FServerRegionalClusterConfigResponse ******************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FServerRegionalClusterConfigResponse;
class UScriptStruct* FServerRegionalClusterConfigResponse::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FServerRegionalClusterConfigResponse.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FServerRegionalClusterConfigResponse.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FServerRegionalClusterConfigResponse, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("ServerRegionalClusterConfigResponse"));
	}
	return Z_Registration_Info_UScriptStruct_FServerRegionalClusterConfigResponse.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FServerRegionalClusterConfigResponse_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Regional cluster configuration response wrapper (mirrors C# ServerRegionalClusterConfigResponseDto)\n */" },
#endif
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Regional cluster configuration response wrapper (mirrors C# ServerRegionalClusterConfigResponseDto)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Config_MetaData[] = {
		{ "Category", "Server" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerDiscoveryTypes.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Config;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FServerRegionalClusterConfigResponse>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FServerRegionalClusterConfigResponse_Statics::NewProp_Config = { "Config", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FServerRegionalClusterConfigResponse, Config), Z_Construct_UScriptStruct_FServerRegionalClusterConfig, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Config_MetaData), NewProp_Config_MetaData) }; // 3659141395
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FServerRegionalClusterConfigResponse_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerRegionalClusterConfigResponse_Statics::NewProp_Config,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FServerRegionalClusterConfigResponse_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FServerRegionalClusterConfigResponse_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"ServerRegionalClusterConfigResponse",
	Z_Construct_UScriptStruct_FServerRegionalClusterConfigResponse_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FServerRegionalClusterConfigResponse_Statics::PropPointers),
	sizeof(FServerRegionalClusterConfigResponse),
	alignof(FServerRegionalClusterConfigResponse),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FServerRegionalClusterConfigResponse_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FServerRegionalClusterConfigResponse_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FServerRegionalClusterConfigResponse()
{
	if (!Z_Registration_Info_UScriptStruct_FServerRegionalClusterConfigResponse.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FServerRegionalClusterConfigResponse.InnerSingleton, Z_Construct_UScriptStruct_FServerRegionalClusterConfigResponse_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FServerRegionalClusterConfigResponse.InnerSingleton;
}
// ********** End ScriptStruct FServerRegionalClusterConfigResponse ********************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_EchoesServerDiscoveryTypes_h__Script_Echoes_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FRegisterServerRequest::StaticStruct, Z_Construct_UScriptStruct_FRegisterServerRequest_Statics::NewStructOps, TEXT("RegisterServerRequest"), &Z_Registration_Info_UScriptStruct_FRegisterServerRequest, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FRegisterServerRequest), 618894285U) },
		{ FRegisterServerResponse::StaticStruct, Z_Construct_UScriptStruct_FRegisterServerResponse_Statics::NewStructOps, TEXT("RegisterServerResponse"), &Z_Registration_Info_UScriptStruct_FRegisterServerResponse, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FRegisterServerResponse), 1274605200U) },
		{ FHeartbeatRequest::StaticStruct, Z_Construct_UScriptStruct_FHeartbeatRequest_Statics::NewStructOps, TEXT("HeartbeatRequest"), &Z_Registration_Info_UScriptStruct_FHeartbeatRequest, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FHeartbeatRequest), 3968423781U) },
		{ FHeartbeatResponse::StaticStruct, Z_Construct_UScriptStruct_FHeartbeatResponse_Statics::NewStructOps, TEXT("HeartbeatResponse"), &Z_Registration_Info_UScriptStruct_FHeartbeatResponse, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FHeartbeatResponse), 3958755147U) },
		{ FResourceConfig::StaticStruct, Z_Construct_UScriptStruct_FResourceConfig_Statics::NewStructOps, TEXT("ResourceConfig"), &Z_Registration_Info_UScriptStruct_FResourceConfig, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FResourceConfig), 3640410924U) },
		{ FMoonConfig::StaticStruct, Z_Construct_UScriptStruct_FMoonConfig_Statics::NewStructOps, TEXT("MoonConfig"), &Z_Registration_Info_UScriptStruct_FMoonConfig, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FMoonConfig), 3436544343U) },
		{ FPlanetConfig::StaticStruct, Z_Construct_UScriptStruct_FPlanetConfig_Statics::NewStructOps, TEXT("PlanetConfig"), &Z_Registration_Info_UScriptStruct_FPlanetConfig, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPlanetConfig), 1449517278U) },
		{ FStargateConfig::StaticStruct, Z_Construct_UScriptStruct_FStargateConfig_Statics::NewStructOps, TEXT("StargateConfig"), &Z_Registration_Info_UScriptStruct_FStargateConfig, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FStargateConfig), 3786179722U) },
		{ FStationConfig::StaticStruct, Z_Construct_UScriptStruct_FStationConfig_Statics::NewStructOps, TEXT("StationConfig"), &Z_Registration_Info_UScriptStruct_FStationConfig, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FStationConfig), 4156139141U) },
		{ FAsteroidBeltConfig::StaticStruct, Z_Construct_UScriptStruct_FAsteroidBeltConfig_Statics::NewStructOps, TEXT("AsteroidBeltConfig"), &Z_Registration_Info_UScriptStruct_FAsteroidBeltConfig, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAsteroidBeltConfig), 2970304511U) },
		{ FAnomalyConfig::StaticStruct, Z_Construct_UScriptStruct_FAnomalyConfig_Statics::NewStructOps, TEXT("AnomalyConfig"), &Z_Registration_Info_UScriptStruct_FAnomalyConfig, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAnomalyConfig), 1662967207U) },
		{ FWormholeConfig::StaticStruct, Z_Construct_UScriptStruct_FWormholeConfig_Statics::NewStructOps, TEXT("WormholeConfig"), &Z_Registration_Info_UScriptStruct_FWormholeConfig, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FWormholeConfig), 4031015292U) },
		{ FServerSystemConfig::StaticStruct, Z_Construct_UScriptStruct_FServerSystemConfig_Statics::NewStructOps, TEXT("ServerSystemConfig"), &Z_Registration_Info_UScriptStruct_FServerSystemConfig, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FServerSystemConfig), 1674105224U) },
		{ FServerRegionalClusterConfig::StaticStruct, Z_Construct_UScriptStruct_FServerRegionalClusterConfig_Statics::NewStructOps, TEXT("ServerRegionalClusterConfig"), &Z_Registration_Info_UScriptStruct_FServerRegionalClusterConfig, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FServerRegionalClusterConfig), 3659141395U) },
		{ FServerConfigRequest::StaticStruct, Z_Construct_UScriptStruct_FServerConfigRequest_Statics::NewStructOps, TEXT("ServerConfigRequest"), &Z_Registration_Info_UScriptStruct_FServerConfigRequest, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FServerConfigRequest), 929010963U) },
		{ FServerConfigResponse::StaticStruct, Z_Construct_UScriptStruct_FServerConfigResponse_Statics::NewStructOps, TEXT("ServerConfigResponse"), &Z_Registration_Info_UScriptStruct_FServerConfigResponse, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FServerConfigResponse), 1575514423U) },
		{ FServerRegionalClusterConfigResponse::StaticStruct, Z_Construct_UScriptStruct_FServerRegionalClusterConfigResponse_Statics::NewStructOps, TEXT("ServerRegionalClusterConfigResponse"), &Z_Registration_Info_UScriptStruct_FServerRegionalClusterConfigResponse, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FServerRegionalClusterConfigResponse), 636578418U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_EchoesServerDiscoveryTypes_h__Script_Echoes_4236468415(TEXT("/Script/Echoes"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_EchoesServerDiscoveryTypes_h__Script_Echoes_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_EchoesServerDiscoveryTypes_h__Script_Echoes_Statics::ScriptStructInfo),
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
