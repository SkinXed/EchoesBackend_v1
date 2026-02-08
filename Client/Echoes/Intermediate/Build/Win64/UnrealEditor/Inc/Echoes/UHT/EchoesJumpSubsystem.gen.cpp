// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EchoesJumpSubsystem.h"
#include "Engine/GameInstance.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesJumpSubsystem() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ECHOES_API UClass* Z_Construct_UClass_UEchoesJumpSubsystem();
ECHOES_API UClass* Z_Construct_UClass_UEchoesJumpSubsystem_NoRegister();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnJumpInitiated__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnJumpRequestComplete__DelegateSignature();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FJumpRequestData();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FJumpResponseData();
ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FJumpRequestData **************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJumpRequestData;
class UScriptStruct* FJumpRequestData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJumpRequestData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJumpRequestData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJumpRequestData, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("JumpRequestData"));
	}
	return Z_Registration_Info_UScriptStruct_FJumpRequestData.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FJumpRequestData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Structure for jump request data\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesJumpSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Structure for jump request data" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterId_MetaData[] = {
		{ "Category", "Jump" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Character ID making the jump */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesJumpSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Character ID making the jump" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StargateId_MetaData[] = {
		{ "Category", "Jump" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Stargate being used */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesJumpSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Stargate being used" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SourceSystemId_MetaData[] = {
		{ "Category", "Jump" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Source system */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesJumpSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Source system" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DestinationSystemId_MetaData[] = {
		{ "Category", "Jump" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Destination system */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesJumpSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Destination system" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_CharacterId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_StargateId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SourceSystemId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DestinationSystemId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJumpRequestData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJumpRequestData_Statics::NewProp_CharacterId = { "CharacterId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJumpRequestData, CharacterId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterId_MetaData), NewProp_CharacterId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJumpRequestData_Statics::NewProp_StargateId = { "StargateId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJumpRequestData, StargateId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StargateId_MetaData), NewProp_StargateId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJumpRequestData_Statics::NewProp_SourceSystemId = { "SourceSystemId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJumpRequestData, SourceSystemId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SourceSystemId_MetaData), NewProp_SourceSystemId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJumpRequestData_Statics::NewProp_DestinationSystemId = { "DestinationSystemId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJumpRequestData, DestinationSystemId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DestinationSystemId_MetaData), NewProp_DestinationSystemId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJumpRequestData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJumpRequestData_Statics::NewProp_CharacterId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJumpRequestData_Statics::NewProp_StargateId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJumpRequestData_Statics::NewProp_SourceSystemId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJumpRequestData_Statics::NewProp_DestinationSystemId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJumpRequestData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJumpRequestData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"JumpRequestData",
	Z_Construct_UScriptStruct_FJumpRequestData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJumpRequestData_Statics::PropPointers),
	sizeof(FJumpRequestData),
	alignof(FJumpRequestData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJumpRequestData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJumpRequestData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJumpRequestData()
{
	if (!Z_Registration_Info_UScriptStruct_FJumpRequestData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJumpRequestData.InnerSingleton, Z_Construct_UScriptStruct_FJumpRequestData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FJumpRequestData.InnerSingleton;
}
// ********** End ScriptStruct FJumpRequestData ****************************************************

// ********** Begin ScriptStruct FJumpResponseData *************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJumpResponseData;
class UScriptStruct* FJumpResponseData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJumpResponseData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJumpResponseData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJumpResponseData, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("JumpResponseData"));
	}
	return Z_Registration_Info_UScriptStruct_FJumpResponseData.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FJumpResponseData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Structure for jump response from backend\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesJumpSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Structure for jump response from backend" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSuccess_MetaData[] = {
		{ "Category", "Jump" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether the jump was approved */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesJumpSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether the jump was approved" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TicketId_MetaData[] = {
		{ "Category", "Jump" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Jump ticket ID */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesJumpSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Jump ticket ID" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DestinationServerAddress_MetaData[] = {
		{ "Category", "Jump" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Destination server address (IP:Port) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesJumpSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Destination server address (IP:Port)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DestinationSystemName_MetaData[] = {
		{ "Category", "Jump" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Destination system name */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesJumpSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Destination system name" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
		{ "Category", "Jump" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Message from server */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesJumpSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Message from server" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DenialReason_MetaData[] = {
		{ "Category", "Jump" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Reason for denial (if not successful) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesJumpSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Reason for denial (if not successful)" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_bSuccess_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FStrPropertyParams NewProp_TicketId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DestinationServerAddress;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DestinationSystemName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Message;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DenialReason;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJumpResponseData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
void Z_Construct_UScriptStruct_FJumpResponseData_Statics::NewProp_bSuccess_SetBit(void* Obj)
{
	((FJumpResponseData*)Obj)->bSuccess = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJumpResponseData_Statics::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJumpResponseData), &Z_Construct_UScriptStruct_FJumpResponseData_Statics::NewProp_bSuccess_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSuccess_MetaData), NewProp_bSuccess_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FJumpResponseData_Statics::NewProp_TicketId = { "TicketId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJumpResponseData, TicketId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TicketId_MetaData), NewProp_TicketId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FJumpResponseData_Statics::NewProp_DestinationServerAddress = { "DestinationServerAddress", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJumpResponseData, DestinationServerAddress), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DestinationServerAddress_MetaData), NewProp_DestinationServerAddress_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FJumpResponseData_Statics::NewProp_DestinationSystemName = { "DestinationSystemName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJumpResponseData, DestinationSystemName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DestinationSystemName_MetaData), NewProp_DestinationSystemName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FJumpResponseData_Statics::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJumpResponseData, Message), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FJumpResponseData_Statics::NewProp_DenialReason = { "DenialReason", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJumpResponseData, DenialReason), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DenialReason_MetaData), NewProp_DenialReason_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJumpResponseData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJumpResponseData_Statics::NewProp_bSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJumpResponseData_Statics::NewProp_TicketId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJumpResponseData_Statics::NewProp_DestinationServerAddress,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJumpResponseData_Statics::NewProp_DestinationSystemName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJumpResponseData_Statics::NewProp_Message,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJumpResponseData_Statics::NewProp_DenialReason,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJumpResponseData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJumpResponseData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"JumpResponseData",
	Z_Construct_UScriptStruct_FJumpResponseData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJumpResponseData_Statics::PropPointers),
	sizeof(FJumpResponseData),
	alignof(FJumpResponseData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJumpResponseData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJumpResponseData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJumpResponseData()
{
	if (!Z_Registration_Info_UScriptStruct_FJumpResponseData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJumpResponseData.InnerSingleton, Z_Construct_UScriptStruct_FJumpResponseData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FJumpResponseData.InnerSingleton;
}
// ********** End ScriptStruct FJumpResponseData ***************************************************

// ********** Begin Delegate FOnJumpRequestComplete ************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnJumpRequestComplete__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnJumpRequestComplete_Parms
	{
		bool bSuccess;
		FJumpResponseData Response;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Delegate for jump request completion\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesJumpSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Delegate for jump request completion" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Response_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static void NewProp_bSuccess_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Response;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
void Z_Construct_UDelegateFunction_Echoes_OnJumpRequestComplete__DelegateSignature_Statics::NewProp_bSuccess_SetBit(void* Obj)
{
	((_Script_Echoes_eventOnJumpRequestComplete_Parms*)Obj)->bSuccess = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_Echoes_OnJumpRequestComplete__DelegateSignature_Statics::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_Echoes_eventOnJumpRequestComplete_Parms), &Z_Construct_UDelegateFunction_Echoes_OnJumpRequestComplete__DelegateSignature_Statics::NewProp_bSuccess_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_Echoes_OnJumpRequestComplete__DelegateSignature_Statics::NewProp_Response = { "Response", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnJumpRequestComplete_Parms, Response), Z_Construct_UScriptStruct_FJumpResponseData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Response_MetaData), NewProp_Response_MetaData) }; // 3893769201
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnJumpRequestComplete__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnJumpRequestComplete__DelegateSignature_Statics::NewProp_bSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnJumpRequestComplete__DelegateSignature_Statics::NewProp_Response,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnJumpRequestComplete__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnJumpRequestComplete__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnJumpRequestComplete__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnJumpRequestComplete__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnJumpRequestComplete__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnJumpRequestComplete__DelegateSignature_Statics::_Script_Echoes_eventOnJumpRequestComplete_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnJumpRequestComplete__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnJumpRequestComplete__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnJumpRequestComplete__DelegateSignature_Statics::_Script_Echoes_eventOnJumpRequestComplete_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnJumpRequestComplete__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnJumpRequestComplete__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnJumpRequestComplete_DelegateWrapper(const FMulticastScriptDelegate& OnJumpRequestComplete, bool bSuccess, FJumpResponseData const& Response)
{
	struct _Script_Echoes_eventOnJumpRequestComplete_Parms
	{
		bool bSuccess;
		FJumpResponseData Response;
	};
	_Script_Echoes_eventOnJumpRequestComplete_Parms Parms;
	Parms.bSuccess=bSuccess ? true : false;
	Parms.Response=Response;
	OnJumpRequestComplete.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnJumpRequestComplete **************************************************

// ********** Begin Delegate FOnJumpInitiated ******************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnJumpInitiated__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnJumpInitiated_Parms
	{
		FString TravelURL;
		FString TicketId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Delegate for jump initiation\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesJumpSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Delegate for jump initiation" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TravelURL_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TicketId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_TravelURL;
	static const UECodeGen_Private::FStrPropertyParams NewProp_TicketId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_Echoes_OnJumpInitiated__DelegateSignature_Statics::NewProp_TravelURL = { "TravelURL", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnJumpInitiated_Parms, TravelURL), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TravelURL_MetaData), NewProp_TravelURL_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_Echoes_OnJumpInitiated__DelegateSignature_Statics::NewProp_TicketId = { "TicketId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnJumpInitiated_Parms, TicketId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TicketId_MetaData), NewProp_TicketId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnJumpInitiated__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnJumpInitiated__DelegateSignature_Statics::NewProp_TravelURL,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnJumpInitiated__DelegateSignature_Statics::NewProp_TicketId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnJumpInitiated__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnJumpInitiated__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnJumpInitiated__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnJumpInitiated__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnJumpInitiated__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnJumpInitiated__DelegateSignature_Statics::_Script_Echoes_eventOnJumpInitiated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnJumpInitiated__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnJumpInitiated__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnJumpInitiated__DelegateSignature_Statics::_Script_Echoes_eventOnJumpInitiated_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnJumpInitiated__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnJumpInitiated__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnJumpInitiated_DelegateWrapper(const FMulticastScriptDelegate& OnJumpInitiated, const FString& TravelURL, const FString& TicketId)
{
	struct _Script_Echoes_eventOnJumpInitiated_Parms
	{
		FString TravelURL;
		FString TicketId;
	};
	_Script_Echoes_eventOnJumpInitiated_Parms Parms;
	Parms.TravelURL=TravelURL;
	Parms.TicketId=TicketId;
	OnJumpInitiated.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnJumpInitiated ********************************************************

// ********** Begin Class UEchoesJumpSubsystem Function ClientRPC_TravelToSystem *******************
struct EchoesJumpSubsystem_eventClientRPC_TravelToSystem_Parms
{
	FString TravelURL;
	FString TicketId;
	FString SystemName;
};
static FName NAME_UEchoesJumpSubsystem_ClientRPC_TravelToSystem = FName(TEXT("ClientRPC_TravelToSystem"));
void UEchoesJumpSubsystem::ClientRPC_TravelToSystem(const FString& TravelURL, const FString& TicketId, const FString& SystemName)
{
	EchoesJumpSubsystem_eventClientRPC_TravelToSystem_Parms Parms;
	Parms.TravelURL=TravelURL;
	Parms.TicketId=TicketId;
	Parms.SystemName=SystemName;
	UFunction* Func = FindFunctionChecked(NAME_UEchoesJumpSubsystem_ClientRPC_TravelToSystem);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UEchoesJumpSubsystem_ClientRPC_TravelToSystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Jump" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Client RPC to initiate travel to destination server\n\x09 * Sends client to new server with jump ticket\n\x09 * \n\x09 * @param TravelURL - Destination server address with ticket\n\x09 * @param TicketId - Jump ticket for authentication\n\x09 * @param SystemName - Destination system name (for UI)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesJumpSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Client RPC to initiate travel to destination server\nSends client to new server with jump ticket\n\n@param TravelURL - Destination server address with ticket\n@param TicketId - Jump ticket for authentication\n@param SystemName - Destination system name (for UI)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TravelURL_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TicketId_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SystemName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_TravelURL;
	static const UECodeGen_Private::FStrPropertyParams NewProp_TicketId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SystemName;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEchoesJumpSubsystem_ClientRPC_TravelToSystem_Statics::NewProp_TravelURL = { "TravelURL", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesJumpSubsystem_eventClientRPC_TravelToSystem_Parms, TravelURL), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TravelURL_MetaData), NewProp_TravelURL_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEchoesJumpSubsystem_ClientRPC_TravelToSystem_Statics::NewProp_TicketId = { "TicketId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesJumpSubsystem_eventClientRPC_TravelToSystem_Parms, TicketId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TicketId_MetaData), NewProp_TicketId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEchoesJumpSubsystem_ClientRPC_TravelToSystem_Statics::NewProp_SystemName = { "SystemName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesJumpSubsystem_eventClientRPC_TravelToSystem_Parms, SystemName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SystemName_MetaData), NewProp_SystemName_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesJumpSubsystem_ClientRPC_TravelToSystem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesJumpSubsystem_ClientRPC_TravelToSystem_Statics::NewProp_TravelURL,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesJumpSubsystem_ClientRPC_TravelToSystem_Statics::NewProp_TicketId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesJumpSubsystem_ClientRPC_TravelToSystem_Statics::NewProp_SystemName,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesJumpSubsystem_ClientRPC_TravelToSystem_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesJumpSubsystem_ClientRPC_TravelToSystem_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesJumpSubsystem, nullptr, "ClientRPC_TravelToSystem", Z_Construct_UFunction_UEchoesJumpSubsystem_ClientRPC_TravelToSystem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesJumpSubsystem_ClientRPC_TravelToSystem_Statics::PropPointers), sizeof(EchoesJumpSubsystem_eventClientRPC_TravelToSystem_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01020CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesJumpSubsystem_ClientRPC_TravelToSystem_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesJumpSubsystem_ClientRPC_TravelToSystem_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(EchoesJumpSubsystem_eventClientRPC_TravelToSystem_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesJumpSubsystem_ClientRPC_TravelToSystem()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesJumpSubsystem_ClientRPC_TravelToSystem_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesJumpSubsystem::execClientRPC_TravelToSystem)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_TravelURL);
	P_GET_PROPERTY(FStrProperty,Z_Param_TicketId);
	P_GET_PROPERTY(FStrProperty,Z_Param_SystemName);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientRPC_TravelToSystem_Implementation(Z_Param_TravelURL,Z_Param_TicketId,Z_Param_SystemName);
	P_NATIVE_END;
}
// ********** End Class UEchoesJumpSubsystem Function ClientRPC_TravelToSystem *********************

// ********** Begin Class UEchoesJumpSubsystem Function ServerOnly_RequestJump *********************
struct Z_Construct_UFunction_UEchoesJumpSubsystem_ServerOnly_RequestJump_Statics
{
	struct EchoesJumpSubsystem_eventServerOnly_RequestJump_Parms
	{
		FGuid CharacterId;
		FGuid StargateId;
		FGuid SourceSystemId;
		FGuid DestinationSystemId;
		APawn* PlayerPawn;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Jump" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Request a jump for a character through a stargate\n\x09 * SERVER ONLY - Called by source game server\n\x09 * \n\x09 * @param CharacterId - Character making the jump\n\x09 * @param StargateId - Stargate being used\n\x09 * @param SourceSystemId - Current system\n\x09 * @param DestinationSystemId - Target system\n\x09 * @param PlayerPawn - Player's pawn for state collection\n\x09 */" },
#endif
		{ "CPP_Default_PlayerPawn", "None" },
		{ "DisplayName", "ServerOnly - Request Jump" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesJumpSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Request a jump for a character through a stargate\nSERVER ONLY - Called by source game server\n\n@param CharacterId - Character making the jump\n@param StargateId - Stargate being used\n@param SourceSystemId - Current system\n@param DestinationSystemId - Target system\n@param PlayerPawn - Player's pawn for state collection" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_CharacterId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_StargateId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SourceSystemId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DestinationSystemId;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerPawn;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesJumpSubsystem_ServerOnly_RequestJump_Statics::NewProp_CharacterId = { "CharacterId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesJumpSubsystem_eventServerOnly_RequestJump_Parms, CharacterId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesJumpSubsystem_ServerOnly_RequestJump_Statics::NewProp_StargateId = { "StargateId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesJumpSubsystem_eventServerOnly_RequestJump_Parms, StargateId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesJumpSubsystem_ServerOnly_RequestJump_Statics::NewProp_SourceSystemId = { "SourceSystemId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesJumpSubsystem_eventServerOnly_RequestJump_Parms, SourceSystemId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesJumpSubsystem_ServerOnly_RequestJump_Statics::NewProp_DestinationSystemId = { "DestinationSystemId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesJumpSubsystem_eventServerOnly_RequestJump_Parms, DestinationSystemId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEchoesJumpSubsystem_ServerOnly_RequestJump_Statics::NewProp_PlayerPawn = { "PlayerPawn", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesJumpSubsystem_eventServerOnly_RequestJump_Parms, PlayerPawn), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesJumpSubsystem_ServerOnly_RequestJump_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesJumpSubsystem_ServerOnly_RequestJump_Statics::NewProp_CharacterId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesJumpSubsystem_ServerOnly_RequestJump_Statics::NewProp_StargateId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesJumpSubsystem_ServerOnly_RequestJump_Statics::NewProp_SourceSystemId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesJumpSubsystem_ServerOnly_RequestJump_Statics::NewProp_DestinationSystemId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesJumpSubsystem_ServerOnly_RequestJump_Statics::NewProp_PlayerPawn,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesJumpSubsystem_ServerOnly_RequestJump_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesJumpSubsystem_ServerOnly_RequestJump_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesJumpSubsystem, nullptr, "ServerOnly_RequestJump", Z_Construct_UFunction_UEchoesJumpSubsystem_ServerOnly_RequestJump_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesJumpSubsystem_ServerOnly_RequestJump_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesJumpSubsystem_ServerOnly_RequestJump_Statics::EchoesJumpSubsystem_eventServerOnly_RequestJump_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesJumpSubsystem_ServerOnly_RequestJump_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesJumpSubsystem_ServerOnly_RequestJump_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesJumpSubsystem_ServerOnly_RequestJump_Statics::EchoesJumpSubsystem_eventServerOnly_RequestJump_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesJumpSubsystem_ServerOnly_RequestJump()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesJumpSubsystem_ServerOnly_RequestJump_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesJumpSubsystem::execServerOnly_RequestJump)
{
	P_GET_STRUCT(FGuid,Z_Param_CharacterId);
	P_GET_STRUCT(FGuid,Z_Param_StargateId);
	P_GET_STRUCT(FGuid,Z_Param_SourceSystemId);
	P_GET_STRUCT(FGuid,Z_Param_DestinationSystemId);
	P_GET_OBJECT(APawn,Z_Param_PlayerPawn);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerOnly_RequestJump(Z_Param_CharacterId,Z_Param_StargateId,Z_Param_SourceSystemId,Z_Param_DestinationSystemId,Z_Param_PlayerPawn);
	P_NATIVE_END;
}
// ********** End Class UEchoesJumpSubsystem Function ServerOnly_RequestJump ***********************

// ********** Begin Class UEchoesJumpSubsystem Function ServerOnly_ValidateJumpTicket **************
struct Z_Construct_UFunction_UEchoesJumpSubsystem_ServerOnly_ValidateJumpTicket_Statics
{
	struct EchoesJumpSubsystem_eventServerOnly_ValidateJumpTicket_Parms
	{
		FString TicketId;
		FGuid CharacterId;
		FGuid SystemId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Jump" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Validate a jump ticket on the destination server\n\x09 * SERVER ONLY - Called when player connects to new server\n\x09 * \n\x09 * @param TicketId - Ticket ID from connection URL\n\x09 * @param CharacterId - Character ID to validate\n\x09 * @param SystemId - Current system ID\n\x09 */" },
#endif
		{ "DisplayName", "ServerOnly - Validate Jump Ticket" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesJumpSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Validate a jump ticket on the destination server\nSERVER ONLY - Called when player connects to new server\n\n@param TicketId - Ticket ID from connection URL\n@param CharacterId - Character ID to validate\n@param SystemId - Current system ID" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TicketId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_TicketId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CharacterId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SystemId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEchoesJumpSubsystem_ServerOnly_ValidateJumpTicket_Statics::NewProp_TicketId = { "TicketId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesJumpSubsystem_eventServerOnly_ValidateJumpTicket_Parms, TicketId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TicketId_MetaData), NewProp_TicketId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesJumpSubsystem_ServerOnly_ValidateJumpTicket_Statics::NewProp_CharacterId = { "CharacterId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesJumpSubsystem_eventServerOnly_ValidateJumpTicket_Parms, CharacterId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesJumpSubsystem_ServerOnly_ValidateJumpTicket_Statics::NewProp_SystemId = { "SystemId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesJumpSubsystem_eventServerOnly_ValidateJumpTicket_Parms, SystemId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesJumpSubsystem_ServerOnly_ValidateJumpTicket_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesJumpSubsystem_ServerOnly_ValidateJumpTicket_Statics::NewProp_TicketId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesJumpSubsystem_ServerOnly_ValidateJumpTicket_Statics::NewProp_CharacterId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesJumpSubsystem_ServerOnly_ValidateJumpTicket_Statics::NewProp_SystemId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesJumpSubsystem_ServerOnly_ValidateJumpTicket_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesJumpSubsystem_ServerOnly_ValidateJumpTicket_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesJumpSubsystem, nullptr, "ServerOnly_ValidateJumpTicket", Z_Construct_UFunction_UEchoesJumpSubsystem_ServerOnly_ValidateJumpTicket_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesJumpSubsystem_ServerOnly_ValidateJumpTicket_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesJumpSubsystem_ServerOnly_ValidateJumpTicket_Statics::EchoesJumpSubsystem_eventServerOnly_ValidateJumpTicket_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesJumpSubsystem_ServerOnly_ValidateJumpTicket_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesJumpSubsystem_ServerOnly_ValidateJumpTicket_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesJumpSubsystem_ServerOnly_ValidateJumpTicket_Statics::EchoesJumpSubsystem_eventServerOnly_ValidateJumpTicket_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesJumpSubsystem_ServerOnly_ValidateJumpTicket()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesJumpSubsystem_ServerOnly_ValidateJumpTicket_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesJumpSubsystem::execServerOnly_ValidateJumpTicket)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_TicketId);
	P_GET_STRUCT(FGuid,Z_Param_CharacterId);
	P_GET_STRUCT(FGuid,Z_Param_SystemId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerOnly_ValidateJumpTicket(Z_Param_TicketId,Z_Param_CharacterId,Z_Param_SystemId);
	P_NATIVE_END;
}
// ********** End Class UEchoesJumpSubsystem Function ServerOnly_ValidateJumpTicket ****************

// ********** Begin Class UEchoesJumpSubsystem *****************************************************
void UEchoesJumpSubsystem::StaticRegisterNativesUEchoesJumpSubsystem()
{
	UClass* Class = UEchoesJumpSubsystem::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ClientRPC_TravelToSystem", &UEchoesJumpSubsystem::execClientRPC_TravelToSystem },
		{ "ServerOnly_RequestJump", &UEchoesJumpSubsystem::execServerOnly_RequestJump },
		{ "ServerOnly_ValidateJumpTicket", &UEchoesJumpSubsystem::execServerOnly_ValidateJumpTicket },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UEchoesJumpSubsystem;
UClass* UEchoesJumpSubsystem::GetPrivateStaticClass()
{
	using TClass = UEchoesJumpSubsystem;
	if (!Z_Registration_Info_UClass_UEchoesJumpSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesJumpSubsystem"),
			Z_Registration_Info_UClass_UEchoesJumpSubsystem.InnerSingleton,
			StaticRegisterNativesUEchoesJumpSubsystem,
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
	return Z_Registration_Info_UClass_UEchoesJumpSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UEchoesJumpSubsystem_NoRegister()
{
	return UEchoesJumpSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UEchoesJumpSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * UEchoesJumpSubsystem\n * \n * Manages interstellar jumps between game systems via stargates.\n * Handles session handover with secure ticket-based authentication.\n * \n * Architecture:\n * 1. Client initiates jump at stargate\n * 2. Server saves character state immediately\n * 3. Server requests jump ticket from backend\n * 4. Client travels to new server with ticket\n * 5. New server validates ticket before spawning character\n */" },
#endif
		{ "IncludePath", "Core/Common/Networking/EchoesJumpSubsystem.h" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesJumpSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UEchoesJumpSubsystem\n\nManages interstellar jumps between game systems via stargates.\nHandles session handover with secure ticket-based authentication.\n\nArchitecture:\n1. Client initiates jump at stargate\n2. Server saves character state immediately\n3. Server requests jump ticket from backend\n4. Client travels to new server with ticket\n5. New server validates ticket before spawning character" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnJumpRequestComplete_MetaData[] = {
		{ "Category", "Echoes|Jump" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Delegate fired when jump request completes */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesJumpSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Delegate fired when jump request completes" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnJumpInitiated_MetaData[] = {
		{ "Category", "Echoes|Jump" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Delegate fired when jump is initiated (client travel starts) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesJumpSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Delegate fired when jump is initiated (client travel starts)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ApiBaseUrl_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** API base URL for jump endpoints */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesJumpSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "API base URL for jump endpoints" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ServerSecret_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Server secret for authentication */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesJumpSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Server secret for authentication" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableDebugLogging_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether to enable verbose logging */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesJumpSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether to enable verbose logging" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnJumpRequestComplete;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnJumpInitiated;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ApiBaseUrl;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ServerSecret;
	static void NewProp_bEnableDebugLogging_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableDebugLogging;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UEchoesJumpSubsystem_ClientRPC_TravelToSystem, "ClientRPC_TravelToSystem" }, // 2719119899
		{ &Z_Construct_UFunction_UEchoesJumpSubsystem_ServerOnly_RequestJump, "ServerOnly_RequestJump" }, // 2523671890
		{ &Z_Construct_UFunction_UEchoesJumpSubsystem_ServerOnly_ValidateJumpTicket, "ServerOnly_ValidateJumpTicket" }, // 2330763528
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEchoesJumpSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEchoesJumpSubsystem_Statics::NewProp_OnJumpRequestComplete = { "OnJumpRequestComplete", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesJumpSubsystem, OnJumpRequestComplete), Z_Construct_UDelegateFunction_Echoes_OnJumpRequestComplete__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnJumpRequestComplete_MetaData), NewProp_OnJumpRequestComplete_MetaData) }; // 2770360659
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEchoesJumpSubsystem_Statics::NewProp_OnJumpInitiated = { "OnJumpInitiated", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesJumpSubsystem, OnJumpInitiated), Z_Construct_UDelegateFunction_Echoes_OnJumpInitiated__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnJumpInitiated_MetaData), NewProp_OnJumpInitiated_MetaData) }; // 1009609316
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UEchoesJumpSubsystem_Statics::NewProp_ApiBaseUrl = { "ApiBaseUrl", nullptr, (EPropertyFlags)0x0020080000004000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesJumpSubsystem, ApiBaseUrl), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ApiBaseUrl_MetaData), NewProp_ApiBaseUrl_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UEchoesJumpSubsystem_Statics::NewProp_ServerSecret = { "ServerSecret", nullptr, (EPropertyFlags)0x0020080000004000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesJumpSubsystem, ServerSecret), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ServerSecret_MetaData), NewProp_ServerSecret_MetaData) };
void Z_Construct_UClass_UEchoesJumpSubsystem_Statics::NewProp_bEnableDebugLogging_SetBit(void* Obj)
{
	((UEchoesJumpSubsystem*)Obj)->bEnableDebugLogging = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UEchoesJumpSubsystem_Statics::NewProp_bEnableDebugLogging = { "bEnableDebugLogging", nullptr, (EPropertyFlags)0x0020080000004000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UEchoesJumpSubsystem), &Z_Construct_UClass_UEchoesJumpSubsystem_Statics::NewProp_bEnableDebugLogging_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableDebugLogging_MetaData), NewProp_bEnableDebugLogging_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEchoesJumpSubsystem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesJumpSubsystem_Statics::NewProp_OnJumpRequestComplete,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesJumpSubsystem_Statics::NewProp_OnJumpInitiated,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesJumpSubsystem_Statics::NewProp_ApiBaseUrl,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesJumpSubsystem_Statics::NewProp_ServerSecret,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesJumpSubsystem_Statics::NewProp_bEnableDebugLogging,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesJumpSubsystem_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UEchoesJumpSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesJumpSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEchoesJumpSubsystem_Statics::ClassParams = {
	&UEchoesJumpSubsystem::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UEchoesJumpSubsystem_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesJumpSubsystem_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesJumpSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UEchoesJumpSubsystem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEchoesJumpSubsystem()
{
	if (!Z_Registration_Info_UClass_UEchoesJumpSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEchoesJumpSubsystem.OuterSingleton, Z_Construct_UClass_UEchoesJumpSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEchoesJumpSubsystem.OuterSingleton;
}
UEchoesJumpSubsystem::UEchoesJumpSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UEchoesJumpSubsystem);
UEchoesJumpSubsystem::~UEchoesJumpSubsystem() {}
// ********** End Class UEchoesJumpSubsystem *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesJumpSubsystem_h__Script_Echoes_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FJumpRequestData::StaticStruct, Z_Construct_UScriptStruct_FJumpRequestData_Statics::NewStructOps, TEXT("JumpRequestData"), &Z_Registration_Info_UScriptStruct_FJumpRequestData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJumpRequestData), 414168960U) },
		{ FJumpResponseData::StaticStruct, Z_Construct_UScriptStruct_FJumpResponseData_Statics::NewStructOps, TEXT("JumpResponseData"), &Z_Registration_Info_UScriptStruct_FJumpResponseData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJumpResponseData), 3893769201U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEchoesJumpSubsystem, UEchoesJumpSubsystem::StaticClass, TEXT("UEchoesJumpSubsystem"), &Z_Registration_Info_UClass_UEchoesJumpSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEchoesJumpSubsystem), 518987000U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesJumpSubsystem_h__Script_Echoes_4121270350(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesJumpSubsystem_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesJumpSubsystem_h__Script_Echoes_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesJumpSubsystem_h__Script_Echoes_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesJumpSubsystem_h__Script_Echoes_Statics::ScriptStructInfo),
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
