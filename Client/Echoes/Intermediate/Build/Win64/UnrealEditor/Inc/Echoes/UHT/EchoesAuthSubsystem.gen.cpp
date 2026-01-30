// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Echoes/Core/Common/Networking/EchoesAuthSubsystem.h"
#include "Engine/GameInstance.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesAuthSubsystem() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FDateTime();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ECHOES_API UClass* Z_Construct_UClass_UEchoesAuthSubsystem();
ECHOES_API UClass* Z_Construct_UClass_UEchoesAuthSubsystem_NoRegister();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnLoginFailure__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnLoginSuccess__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnRegisterFailure__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnRegisterSuccess__DelegateSignature();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FAuthRequest();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FAuthResponse();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FCharacterData();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FCharacterInfo();
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FAuthRequest ******************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FAuthRequest;
class UScriptStruct* FAuthRequest::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FAuthRequest.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FAuthRequest.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAuthRequest, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("AuthRequest"));
	}
	return Z_Registration_Info_UScriptStruct_FAuthRequest.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FAuthRequest_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Auth request structure (mirrors C# LoginRequestDto)\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Auth request structure (mirrors C# LoginRequestDto)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EmailOrUsername_MetaData[] = {
		{ "Category", "Auth" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Password_MetaData[] = {
		{ "Category", "Auth" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_EmailOrUsername;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Password;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAuthRequest>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAuthRequest_Statics::NewProp_EmailOrUsername = { "EmailOrUsername", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAuthRequest, EmailOrUsername), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EmailOrUsername_MetaData), NewProp_EmailOrUsername_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAuthRequest_Statics::NewProp_Password = { "Password", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAuthRequest, Password), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Password_MetaData), NewProp_Password_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAuthRequest_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAuthRequest_Statics::NewProp_EmailOrUsername,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAuthRequest_Statics::NewProp_Password,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAuthRequest_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAuthRequest_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"AuthRequest",
	Z_Construct_UScriptStruct_FAuthRequest_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAuthRequest_Statics::PropPointers),
	sizeof(FAuthRequest),
	alignof(FAuthRequest),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAuthRequest_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAuthRequest_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FAuthRequest()
{
	if (!Z_Registration_Info_UScriptStruct_FAuthRequest.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FAuthRequest.InnerSingleton, Z_Construct_UScriptStruct_FAuthRequest_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FAuthRequest.InnerSingleton;
}
// ********** End ScriptStruct FAuthRequest ********************************************************

// ********** Begin ScriptStruct FCharacterInfo ****************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FCharacterInfo;
class UScriptStruct* FCharacterInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FCharacterInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FCharacterInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FCharacterInfo, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("CharacterInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FCharacterInfo.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FCharacterInfo_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Character info structure (mirrors C# CharacterInfoDto)\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Character info structure (mirrors C# CharacterInfoDto)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterId_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WalletBalance_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentShipId_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IsMain_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IsOnline_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_CharacterId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_WalletBalance;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_CurrentShipId;
	static void NewProp_IsMain_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_IsMain;
	static void NewProp_IsOnline_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_IsOnline;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCharacterInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCharacterInfo_Statics::NewProp_CharacterId = { "CharacterId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterInfo, CharacterId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterId_MetaData), NewProp_CharacterId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FCharacterInfo_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterInfo, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FCharacterInfo_Statics::NewProp_WalletBalance = { "WalletBalance", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterInfo, WalletBalance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WalletBalance_MetaData), NewProp_WalletBalance_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FCharacterInfo_Statics::NewProp_CurrentShipId = { "CurrentShipId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterInfo, CurrentShipId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentShipId_MetaData), NewProp_CurrentShipId_MetaData) };
void Z_Construct_UScriptStruct_FCharacterInfo_Statics::NewProp_IsMain_SetBit(void* Obj)
{
	((FCharacterInfo*)Obj)->IsMain = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FCharacterInfo_Statics::NewProp_IsMain = { "IsMain", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FCharacterInfo), &Z_Construct_UScriptStruct_FCharacterInfo_Statics::NewProp_IsMain_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IsMain_MetaData), NewProp_IsMain_MetaData) };
void Z_Construct_UScriptStruct_FCharacterInfo_Statics::NewProp_IsOnline_SetBit(void* Obj)
{
	((FCharacterInfo*)Obj)->IsOnline = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FCharacterInfo_Statics::NewProp_IsOnline = { "IsOnline", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FCharacterInfo), &Z_Construct_UScriptStruct_FCharacterInfo_Statics::NewProp_IsOnline_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IsOnline_MetaData), NewProp_IsOnline_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCharacterInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterInfo_Statics::NewProp_CharacterId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterInfo_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterInfo_Statics::NewProp_WalletBalance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterInfo_Statics::NewProp_CurrentShipId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterInfo_Statics::NewProp_IsMain,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterInfo_Statics::NewProp_IsOnline,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCharacterInfo_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCharacterInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"CharacterInfo",
	Z_Construct_UScriptStruct_FCharacterInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCharacterInfo_Statics::PropPointers),
	sizeof(FCharacterInfo),
	alignof(FCharacterInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCharacterInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FCharacterInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FCharacterInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FCharacterInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FCharacterInfo.InnerSingleton, Z_Construct_UScriptStruct_FCharacterInfo_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FCharacterInfo.InnerSingleton;
}
// ********** End ScriptStruct FCharacterInfo ******************************************************

// ********** Begin ScriptStruct FAuthResponse *****************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FAuthResponse;
class UScriptStruct* FAuthResponse::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FAuthResponse.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FAuthResponse.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAuthResponse, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("AuthResponse"));
	}
	return Z_Registration_Info_UScriptStruct_FAuthResponse.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FAuthResponse_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Auth response structure (mirrors C# AuthResponseDto)\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Auth response structure (mirrors C# AuthResponseDto)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Success_MetaData[] = {
		{ "Category", "Auth" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Token_MetaData[] = {
		{ "Category", "Auth" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AccountId_MetaData[] = {
		{ "Category", "Auth" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterId_MetaData[] = {
		{ "Category", "Auth" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterName_MetaData[] = {
		{ "Category", "Auth" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SessionId_MetaData[] = {
		{ "Category", "Auth" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExpiresAt_MetaData[] = {
		{ "Category", "Auth" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Characters_MetaData[] = {
		{ "Category", "Auth" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
	};
#endif // WITH_METADATA
	static void NewProp_Success_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_Success;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Token;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AccountId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CharacterId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_CharacterName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SessionId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ExpiresAt;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Characters_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Characters;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAuthResponse>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
void Z_Construct_UScriptStruct_FAuthResponse_Statics::NewProp_Success_SetBit(void* Obj)
{
	((FAuthResponse*)Obj)->Success = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAuthResponse_Statics::NewProp_Success = { "Success", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAuthResponse), &Z_Construct_UScriptStruct_FAuthResponse_Statics::NewProp_Success_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Success_MetaData), NewProp_Success_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAuthResponse_Statics::NewProp_Token = { "Token", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAuthResponse, Token), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Token_MetaData), NewProp_Token_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAuthResponse_Statics::NewProp_AccountId = { "AccountId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAuthResponse, AccountId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AccountId_MetaData), NewProp_AccountId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAuthResponse_Statics::NewProp_CharacterId = { "CharacterId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAuthResponse, CharacterId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterId_MetaData), NewProp_CharacterId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAuthResponse_Statics::NewProp_CharacterName = { "CharacterName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAuthResponse, CharacterName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterName_MetaData), NewProp_CharacterName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAuthResponse_Statics::NewProp_SessionId = { "SessionId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAuthResponse, SessionId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SessionId_MetaData), NewProp_SessionId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAuthResponse_Statics::NewProp_ExpiresAt = { "ExpiresAt", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAuthResponse, ExpiresAt), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExpiresAt_MetaData), NewProp_ExpiresAt_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAuthResponse_Statics::NewProp_Characters_Inner = { "Characters", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FCharacterInfo, METADATA_PARAMS(0, nullptr) }; // 2611301823
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FAuthResponse_Statics::NewProp_Characters = { "Characters", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAuthResponse, Characters), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Characters_MetaData), NewProp_Characters_MetaData) }; // 2611301823
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAuthResponse_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAuthResponse_Statics::NewProp_Success,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAuthResponse_Statics::NewProp_Token,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAuthResponse_Statics::NewProp_AccountId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAuthResponse_Statics::NewProp_CharacterId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAuthResponse_Statics::NewProp_CharacterName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAuthResponse_Statics::NewProp_SessionId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAuthResponse_Statics::NewProp_ExpiresAt,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAuthResponse_Statics::NewProp_Characters_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAuthResponse_Statics::NewProp_Characters,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAuthResponse_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAuthResponse_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"AuthResponse",
	Z_Construct_UScriptStruct_FAuthResponse_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAuthResponse_Statics::PropPointers),
	sizeof(FAuthResponse),
	alignof(FAuthResponse),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAuthResponse_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAuthResponse_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FAuthResponse()
{
	if (!Z_Registration_Info_UScriptStruct_FAuthResponse.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FAuthResponse.InnerSingleton, Z_Construct_UScriptStruct_FAuthResponse_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FAuthResponse.InnerSingleton;
}
// ********** End ScriptStruct FAuthResponse *******************************************************

// ********** Begin Delegate FOnLoginSuccess *******************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnLoginSuccess__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnLoginSuccess_Parms
	{
		FAuthResponse AuthResponse;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AuthResponse_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_AuthResponse;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_Echoes_OnLoginSuccess__DelegateSignature_Statics::NewProp_AuthResponse = { "AuthResponse", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnLoginSuccess_Parms, AuthResponse), Z_Construct_UScriptStruct_FAuthResponse, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AuthResponse_MetaData), NewProp_AuthResponse_MetaData) }; // 3112734285
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnLoginSuccess__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnLoginSuccess__DelegateSignature_Statics::NewProp_AuthResponse,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnLoginSuccess__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnLoginSuccess__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnLoginSuccess__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnLoginSuccess__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnLoginSuccess__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnLoginSuccess__DelegateSignature_Statics::_Script_Echoes_eventOnLoginSuccess_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00520000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnLoginSuccess__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnLoginSuccess__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnLoginSuccess__DelegateSignature_Statics::_Script_Echoes_eventOnLoginSuccess_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnLoginSuccess__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnLoginSuccess__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnLoginSuccess_DelegateWrapper(const FScriptDelegate& OnLoginSuccess, FAuthResponse const& AuthResponse)
{
	struct _Script_Echoes_eventOnLoginSuccess_Parms
	{
		FAuthResponse AuthResponse;
	};
	_Script_Echoes_eventOnLoginSuccess_Parms Parms;
	Parms.AuthResponse=AuthResponse;
	OnLoginSuccess.ProcessDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnLoginSuccess *********************************************************

// ********** Begin Delegate FOnLoginFailure *******************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnLoginFailure__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnLoginFailure_Parms
	{
		FString ErrorMessage;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_Echoes_OnLoginFailure__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnLoginFailure_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ErrorMessage_MetaData), NewProp_ErrorMessage_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnLoginFailure__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnLoginFailure__DelegateSignature_Statics::NewProp_ErrorMessage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnLoginFailure__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnLoginFailure__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnLoginFailure__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnLoginFailure__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnLoginFailure__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnLoginFailure__DelegateSignature_Statics::_Script_Echoes_eventOnLoginFailure_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnLoginFailure__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnLoginFailure__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnLoginFailure__DelegateSignature_Statics::_Script_Echoes_eventOnLoginFailure_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnLoginFailure__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnLoginFailure__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnLoginFailure_DelegateWrapper(const FScriptDelegate& OnLoginFailure, const FString& ErrorMessage)
{
	struct _Script_Echoes_eventOnLoginFailure_Parms
	{
		FString ErrorMessage;
	};
	_Script_Echoes_eventOnLoginFailure_Parms Parms;
	Parms.ErrorMessage=ErrorMessage;
	OnLoginFailure.ProcessDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnLoginFailure *********************************************************

// ********** Begin Delegate FOnRegisterSuccess ****************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnRegisterSuccess__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnRegisterSuccess_Parms
	{
		FAuthResponse AuthResponse;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AuthResponse_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_AuthResponse;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_Echoes_OnRegisterSuccess__DelegateSignature_Statics::NewProp_AuthResponse = { "AuthResponse", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnRegisterSuccess_Parms, AuthResponse), Z_Construct_UScriptStruct_FAuthResponse, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AuthResponse_MetaData), NewProp_AuthResponse_MetaData) }; // 3112734285
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnRegisterSuccess__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnRegisterSuccess__DelegateSignature_Statics::NewProp_AuthResponse,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnRegisterSuccess__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnRegisterSuccess__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnRegisterSuccess__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnRegisterSuccess__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnRegisterSuccess__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnRegisterSuccess__DelegateSignature_Statics::_Script_Echoes_eventOnRegisterSuccess_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00520000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnRegisterSuccess__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnRegisterSuccess__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnRegisterSuccess__DelegateSignature_Statics::_Script_Echoes_eventOnRegisterSuccess_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnRegisterSuccess__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnRegisterSuccess__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnRegisterSuccess_DelegateWrapper(const FScriptDelegate& OnRegisterSuccess, FAuthResponse const& AuthResponse)
{
	struct _Script_Echoes_eventOnRegisterSuccess_Parms
	{
		FAuthResponse AuthResponse;
	};
	_Script_Echoes_eventOnRegisterSuccess_Parms Parms;
	Parms.AuthResponse=AuthResponse;
	OnRegisterSuccess.ProcessDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnRegisterSuccess ******************************************************

// ********** Begin Delegate FOnRegisterFailure ****************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnRegisterFailure__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnRegisterFailure_Parms
	{
		FString ErrorMessage;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_Echoes_OnRegisterFailure__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnRegisterFailure_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ErrorMessage_MetaData), NewProp_ErrorMessage_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnRegisterFailure__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnRegisterFailure__DelegateSignature_Statics::NewProp_ErrorMessage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnRegisterFailure__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnRegisterFailure__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnRegisterFailure__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnRegisterFailure__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnRegisterFailure__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnRegisterFailure__DelegateSignature_Statics::_Script_Echoes_eventOnRegisterFailure_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnRegisterFailure__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnRegisterFailure__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnRegisterFailure__DelegateSignature_Statics::_Script_Echoes_eventOnRegisterFailure_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnRegisterFailure__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnRegisterFailure__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnRegisterFailure_DelegateWrapper(const FScriptDelegate& OnRegisterFailure, const FString& ErrorMessage)
{
	struct _Script_Echoes_eventOnRegisterFailure_Parms
	{
		FString ErrorMessage;
	};
	_Script_Echoes_eventOnRegisterFailure_Parms Parms;
	Parms.ErrorMessage=ErrorMessage;
	OnRegisterFailure.ProcessDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnRegisterFailure ******************************************************

// ********** Begin ScriptStruct FCharacterData ****************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FCharacterData;
class UScriptStruct* FCharacterData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FCharacterData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FCharacterData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FCharacterData, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("CharacterData"));
	}
	return Z_Registration_Info_UScriptStruct_FCharacterData.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FCharacterData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Character data structure (mirrors C# CharacterDataDto)\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Character data structure (mirrors C# CharacterDataDto)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterId_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AccountId_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WalletBalance_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SecurityStatus_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentShipId_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CorporationId_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RaceId_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalSkillPoints_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UnallocatedSkillPoints_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IsOnline_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IsDocked_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InWarp_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LastLogin_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_CharacterId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AccountId;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_WalletBalance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SecurityStatus;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_CurrentShipId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CorporationId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_RaceId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_TotalSkillPoints;
	static const UECodeGen_Private::FIntPropertyParams NewProp_UnallocatedSkillPoints;
	static void NewProp_IsOnline_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_IsOnline;
	static void NewProp_IsDocked_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_IsDocked;
	static void NewProp_InWarp_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_InWarp;
	static const UECodeGen_Private::FStructPropertyParams NewProp_LastLogin;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCharacterData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_CharacterId = { "CharacterId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterData, CharacterId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterId_MetaData), NewProp_CharacterId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterData, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_AccountId = { "AccountId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterData, AccountId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AccountId_MetaData), NewProp_AccountId_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_WalletBalance = { "WalletBalance", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterData, WalletBalance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WalletBalance_MetaData), NewProp_WalletBalance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_SecurityStatus = { "SecurityStatus", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterData, SecurityStatus), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SecurityStatus_MetaData), NewProp_SecurityStatus_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_CurrentShipId = { "CurrentShipId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterData, CurrentShipId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentShipId_MetaData), NewProp_CurrentShipId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_CorporationId = { "CorporationId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterData, CorporationId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CorporationId_MetaData), NewProp_CorporationId_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_RaceId = { "RaceId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterData, RaceId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RaceId_MetaData), NewProp_RaceId_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_TotalSkillPoints = { "TotalSkillPoints", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterData, TotalSkillPoints), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalSkillPoints_MetaData), NewProp_TotalSkillPoints_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_UnallocatedSkillPoints = { "UnallocatedSkillPoints", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterData, UnallocatedSkillPoints), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UnallocatedSkillPoints_MetaData), NewProp_UnallocatedSkillPoints_MetaData) };
void Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_IsOnline_SetBit(void* Obj)
{
	((FCharacterData*)Obj)->IsOnline = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_IsOnline = { "IsOnline", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FCharacterData), &Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_IsOnline_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IsOnline_MetaData), NewProp_IsOnline_MetaData) };
void Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_IsDocked_SetBit(void* Obj)
{
	((FCharacterData*)Obj)->IsDocked = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_IsDocked = { "IsDocked", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FCharacterData), &Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_IsDocked_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IsDocked_MetaData), NewProp_IsDocked_MetaData) };
void Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_InWarp_SetBit(void* Obj)
{
	((FCharacterData*)Obj)->InWarp = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_InWarp = { "InWarp", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FCharacterData), &Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_InWarp_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InWarp_MetaData), NewProp_InWarp_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_LastLogin = { "LastLogin", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterData, LastLogin), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LastLogin_MetaData), NewProp_LastLogin_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCharacterData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_CharacterId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_AccountId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_WalletBalance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_SecurityStatus,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_CurrentShipId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_CorporationId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_RaceId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_TotalSkillPoints,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_UnallocatedSkillPoints,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_IsOnline,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_IsDocked,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_InWarp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_LastLogin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCharacterData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCharacterData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"CharacterData",
	Z_Construct_UScriptStruct_FCharacterData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCharacterData_Statics::PropPointers),
	sizeof(FCharacterData),
	alignof(FCharacterData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCharacterData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FCharacterData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FCharacterData()
{
	if (!Z_Registration_Info_UScriptStruct_FCharacterData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FCharacterData.InnerSingleton, Z_Construct_UScriptStruct_FCharacterData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FCharacterData.InnerSingleton;
}
// ********** End ScriptStruct FCharacterData ******************************************************

// ********** Begin Class UEchoesAuthSubsystem Function Auth_GetAccountId **************************
struct Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetAccountId_Statics
{
	struct EchoesAuthSubsystem_eventAuth_GetAccountId_Parms
	{
		FGuid ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Auth" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get account ID from current session\n\x09 * \n\x09 * @return Account GUID\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get account ID from current session\n\n@return Account GUID" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetAccountId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesAuthSubsystem_eventAuth_GetAccountId_Parms, ReturnValue), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetAccountId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetAccountId_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetAccountId_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetAccountId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesAuthSubsystem, nullptr, "Auth_GetAccountId", Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetAccountId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetAccountId_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetAccountId_Statics::EchoesAuthSubsystem_eventAuth_GetAccountId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetAccountId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetAccountId_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetAccountId_Statics::EchoesAuthSubsystem_eventAuth_GetAccountId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetAccountId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetAccountId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesAuthSubsystem::execAuth_GetAccountId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGuid*)Z_Param__Result=P_THIS->Auth_GetAccountId();
	P_NATIVE_END;
}
// ********** End Class UEchoesAuthSubsystem Function Auth_GetAccountId ****************************

// ********** Begin Class UEchoesAuthSubsystem Function Auth_GetCharacterId ************************
struct Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetCharacterId_Statics
{
	struct EchoesAuthSubsystem_eventAuth_GetCharacterId_Parms
	{
		FGuid ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Auth" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get character ID from current session\n\x09 * \n\x09 * @return Character GUID\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get character ID from current session\n\n@return Character GUID" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetCharacterId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesAuthSubsystem_eventAuth_GetCharacterId_Parms, ReturnValue), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetCharacterId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetCharacterId_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetCharacterId_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetCharacterId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesAuthSubsystem, nullptr, "Auth_GetCharacterId", Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetCharacterId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetCharacterId_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetCharacterId_Statics::EchoesAuthSubsystem_eventAuth_GetCharacterId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetCharacterId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetCharacterId_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetCharacterId_Statics::EchoesAuthSubsystem_eventAuth_GetCharacterId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetCharacterId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetCharacterId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesAuthSubsystem::execAuth_GetCharacterId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGuid*)Z_Param__Result=P_THIS->Auth_GetCharacterId();
	P_NATIVE_END;
}
// ********** End Class UEchoesAuthSubsystem Function Auth_GetCharacterId **************************

// ********** Begin Class UEchoesAuthSubsystem Function Auth_GetCharacters *************************
struct Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetCharacters_Statics
{
	struct EchoesAuthSubsystem_eventAuth_GetCharacters_Parms
	{
		TArray<FCharacterInfo> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Auth" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get list of characters for current account\n\x09 * \n\x09 * @return Array of character info\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get list of characters for current account\n\n@return Array of character info" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetCharacters_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FCharacterInfo, METADATA_PARAMS(0, nullptr) }; // 2611301823
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetCharacters_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesAuthSubsystem_eventAuth_GetCharacters_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 2611301823
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetCharacters_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetCharacters_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetCharacters_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetCharacters_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetCharacters_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesAuthSubsystem, nullptr, "Auth_GetCharacters", Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetCharacters_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetCharacters_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetCharacters_Statics::EchoesAuthSubsystem_eventAuth_GetCharacters_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetCharacters_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetCharacters_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetCharacters_Statics::EchoesAuthSubsystem_eventAuth_GetCharacters_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetCharacters()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetCharacters_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesAuthSubsystem::execAuth_GetCharacters)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FCharacterInfo>*)Z_Param__Result=P_THIS->Auth_GetCharacters();
	P_NATIVE_END;
}
// ********** End Class UEchoesAuthSubsystem Function Auth_GetCharacters ***************************

// ********** Begin Class UEchoesAuthSubsystem Function Auth_GetToken ******************************
struct Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetToken_Statics
{
	struct EchoesAuthSubsystem_eventAuth_GetToken_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Auth" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get current JWT token\n\x09 * Used by other subsystems (Inventory, ShipStats) to authenticate requests\n\x09 * \n\x09 * @return JWT token string\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get current JWT token\nUsed by other subsystems (Inventory, ShipStats) to authenticate requests\n\n@return JWT token string" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetToken_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesAuthSubsystem_eventAuth_GetToken_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetToken_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetToken_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetToken_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetToken_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesAuthSubsystem, nullptr, "Auth_GetToken", Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetToken_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetToken_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetToken_Statics::EchoesAuthSubsystem_eventAuth_GetToken_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetToken_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetToken_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetToken_Statics::EchoesAuthSubsystem_eventAuth_GetToken_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetToken()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetToken_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesAuthSubsystem::execAuth_GetToken)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->Auth_GetToken();
	P_NATIVE_END;
}
// ********** End Class UEchoesAuthSubsystem Function Auth_GetToken ********************************

// ********** Begin Class UEchoesAuthSubsystem Function Auth_IsLoggedIn ****************************
struct Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_IsLoggedIn_Statics
{
	struct EchoesAuthSubsystem_eventAuth_IsLoggedIn_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Auth" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if user is logged in\n\x09 * \n\x09 * @return True if valid token exists\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if user is logged in\n\n@return True if valid token exists" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_IsLoggedIn_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((EchoesAuthSubsystem_eventAuth_IsLoggedIn_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_IsLoggedIn_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EchoesAuthSubsystem_eventAuth_IsLoggedIn_Parms), &Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_IsLoggedIn_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_IsLoggedIn_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_IsLoggedIn_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_IsLoggedIn_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_IsLoggedIn_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesAuthSubsystem, nullptr, "Auth_IsLoggedIn", Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_IsLoggedIn_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_IsLoggedIn_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_IsLoggedIn_Statics::EchoesAuthSubsystem_eventAuth_IsLoggedIn_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_IsLoggedIn_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_IsLoggedIn_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_IsLoggedIn_Statics::EchoesAuthSubsystem_eventAuth_IsLoggedIn_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_IsLoggedIn()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_IsLoggedIn_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesAuthSubsystem::execAuth_IsLoggedIn)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->Auth_IsLoggedIn();
	P_NATIVE_END;
}
// ********** End Class UEchoesAuthSubsystem Function Auth_IsLoggedIn ******************************

// ********** Begin Class UEchoesAuthSubsystem Function Auth_Login *********************************
struct Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Login_Statics
{
	struct EchoesAuthSubsystem_eventAuth_Login_Parms
	{
		FAuthRequest Request;
		FScriptDelegate OnSuccess;
		FScriptDelegate OnFailure;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Auth" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Login to backend with email/username and password\n\x09 * Sends HTTP POST to /api/auth/login\n\x09 * \n\x09 * @param Request - Login credentials\n\x09 * @param OnSuccess - Callback on successful login\n\x09 * @param OnFailure - Callback on login failure\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Login to backend with email/username and password\nSends HTTP POST to /api/auth/login\n\n@param Request - Login credentials\n@param OnSuccess - Callback on successful login\n@param OnFailure - Callback on login failure" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Request_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Request;
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnSuccess;
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnFailure;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Login_Statics::NewProp_Request = { "Request", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesAuthSubsystem_eventAuth_Login_Parms, Request), Z_Construct_UScriptStruct_FAuthRequest, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Request_MetaData), NewProp_Request_MetaData) }; // 1202977449
const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Login_Statics::NewProp_OnSuccess = { "OnSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesAuthSubsystem_eventAuth_Login_Parms, OnSuccess), Z_Construct_UDelegateFunction_Echoes_OnLoginSuccess__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 1228660147
const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Login_Statics::NewProp_OnFailure = { "OnFailure", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesAuthSubsystem_eventAuth_Login_Parms, OnFailure), Z_Construct_UDelegateFunction_Echoes_OnLoginFailure__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 3207200495
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Login_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Login_Statics::NewProp_Request,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Login_Statics::NewProp_OnSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Login_Statics::NewProp_OnFailure,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Login_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Login_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesAuthSubsystem, nullptr, "Auth_Login", Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Login_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Login_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Login_Statics::EchoesAuthSubsystem_eventAuth_Login_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Login_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Login_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Login_Statics::EchoesAuthSubsystem_eventAuth_Login_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Login()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Login_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesAuthSubsystem::execAuth_Login)
{
	P_GET_STRUCT_REF(FAuthRequest,Z_Param_Out_Request);
	P_GET_PROPERTY(FDelegateProperty,Z_Param_OnSuccess);
	P_GET_PROPERTY(FDelegateProperty,Z_Param_OnFailure);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Auth_Login(Z_Param_Out_Request,FOnLoginSuccess(Z_Param_OnSuccess),FOnLoginFailure(Z_Param_OnFailure));
	P_NATIVE_END;
}
// ********** End Class UEchoesAuthSubsystem Function Auth_Login ***********************************

// ********** Begin Class UEchoesAuthSubsystem Function Auth_Logout ********************************
struct Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Logout_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Auth" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Logout (clear token and session data)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Logout (clear token and session data)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Logout_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesAuthSubsystem, nullptr, "Auth_Logout", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Logout_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Logout_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Logout()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Logout_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesAuthSubsystem::execAuth_Logout)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Auth_Logout();
	P_NATIVE_END;
}
// ********** End Class UEchoesAuthSubsystem Function Auth_Logout **********************************

// ********** Begin Class UEchoesAuthSubsystem Function Auth_Register ******************************
struct Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Register_Statics
{
	struct EchoesAuthSubsystem_eventAuth_Register_Parms
	{
		FString Username;
		FString Email;
		FString Password;
		FScriptDelegate OnSuccess;
		FScriptDelegate OnFailure;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Auth" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Register new account\n\x09 * Sends HTTP POST to /api/auth/register\n\x09 * \n\x09 * @param Username - Desired username\n\x09 * @param Email - Email address\n\x09 * @param Password - Password\n\x09 * @param OnSuccess - Callback on successful registration\n\x09 * @param OnFailure - Callback on registration failure\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Register new account\nSends HTTP POST to /api/auth/register\n\n@param Username - Desired username\n@param Email - Email address\n@param Password - Password\n@param OnSuccess - Callback on successful registration\n@param OnFailure - Callback on registration failure" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Username_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Email_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Password_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_Username;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Email;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Password;
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnSuccess;
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnFailure;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Register_Statics::NewProp_Username = { "Username", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesAuthSubsystem_eventAuth_Register_Parms, Username), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Username_MetaData), NewProp_Username_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Register_Statics::NewProp_Email = { "Email", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesAuthSubsystem_eventAuth_Register_Parms, Email), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Email_MetaData), NewProp_Email_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Register_Statics::NewProp_Password = { "Password", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesAuthSubsystem_eventAuth_Register_Parms, Password), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Password_MetaData), NewProp_Password_MetaData) };
const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Register_Statics::NewProp_OnSuccess = { "OnSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesAuthSubsystem_eventAuth_Register_Parms, OnSuccess), Z_Construct_UDelegateFunction_Echoes_OnRegisterSuccess__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 874006470
const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Register_Statics::NewProp_OnFailure = { "OnFailure", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesAuthSubsystem_eventAuth_Register_Parms, OnFailure), Z_Construct_UDelegateFunction_Echoes_OnRegisterFailure__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 3695153450
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Register_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Register_Statics::NewProp_Username,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Register_Statics::NewProp_Email,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Register_Statics::NewProp_Password,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Register_Statics::NewProp_OnSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Register_Statics::NewProp_OnFailure,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Register_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Register_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesAuthSubsystem, nullptr, "Auth_Register", Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Register_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Register_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Register_Statics::EchoesAuthSubsystem_eventAuth_Register_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Register_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Register_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Register_Statics::EchoesAuthSubsystem_eventAuth_Register_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Register()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Register_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesAuthSubsystem::execAuth_Register)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Username);
	P_GET_PROPERTY(FStrProperty,Z_Param_Email);
	P_GET_PROPERTY(FStrProperty,Z_Param_Password);
	P_GET_PROPERTY(FDelegateProperty,Z_Param_OnSuccess);
	P_GET_PROPERTY(FDelegateProperty,Z_Param_OnFailure);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Auth_Register(Z_Param_Username,Z_Param_Email,Z_Param_Password,FOnRegisterSuccess(Z_Param_OnSuccess),FOnRegisterFailure(Z_Param_OnFailure));
	P_NATIVE_END;
}
// ********** End Class UEchoesAuthSubsystem Function Auth_Register ********************************

// ********** Begin Class UEchoesAuthSubsystem *****************************************************
void UEchoesAuthSubsystem::StaticRegisterNativesUEchoesAuthSubsystem()
{
	UClass* Class = UEchoesAuthSubsystem::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "Auth_GetAccountId", &UEchoesAuthSubsystem::execAuth_GetAccountId },
		{ "Auth_GetCharacterId", &UEchoesAuthSubsystem::execAuth_GetCharacterId },
		{ "Auth_GetCharacters", &UEchoesAuthSubsystem::execAuth_GetCharacters },
		{ "Auth_GetToken", &UEchoesAuthSubsystem::execAuth_GetToken },
		{ "Auth_IsLoggedIn", &UEchoesAuthSubsystem::execAuth_IsLoggedIn },
		{ "Auth_Login", &UEchoesAuthSubsystem::execAuth_Login },
		{ "Auth_Logout", &UEchoesAuthSubsystem::execAuth_Logout },
		{ "Auth_Register", &UEchoesAuthSubsystem::execAuth_Register },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UEchoesAuthSubsystem;
UClass* UEchoesAuthSubsystem::GetPrivateStaticClass()
{
	using TClass = UEchoesAuthSubsystem;
	if (!Z_Registration_Info_UClass_UEchoesAuthSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesAuthSubsystem"),
			Z_Registration_Info_UClass_UEchoesAuthSubsystem.InnerSingleton,
			StaticRegisterNativesUEchoesAuthSubsystem,
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
	return Z_Registration_Info_UClass_UEchoesAuthSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UEchoesAuthSubsystem_NoRegister()
{
	return UEchoesAuthSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UEchoesAuthSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * UEchoesAuthSubsystem\n * \n * Authentication subsystem for Echoes MMO\n * Handles login, registration, and token management\n * \n * Architecture:\n * - GameInstanceSubsystem: Persists across level transitions\n * - Communicates with ASP.NET Core backend\n * - Stores JWT token securely\n * - Provides token to other subsystems (Inventory, Ship Stats)\n */" },
#endif
		{ "IncludePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UEchoesAuthSubsystem\n\nAuthentication subsystem for Echoes MMO\nHandles login, registration, and token management\n\nArchitecture:\n- GameInstanceSubsystem: Persists across level transitions\n- Communicates with ASP.NET Core backend\n- Stores JWT token securely\n- Provides token to other subsystems (Inventory, Ship Stats)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JWTToken_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current JWT token */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current JWT token" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentAuthResponse_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current auth response (includes account info, character list) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current auth response (includes account info, character list)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_JWTToken;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentAuthResponse;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetAccountId, "Auth_GetAccountId" }, // 1247892163
		{ &Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetCharacterId, "Auth_GetCharacterId" }, // 1847183580
		{ &Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetCharacters, "Auth_GetCharacters" }, // 1234715314
		{ &Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetToken, "Auth_GetToken" }, // 633235763
		{ &Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_IsLoggedIn, "Auth_IsLoggedIn" }, // 2846008563
		{ &Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Login, "Auth_Login" }, // 4153009158
		{ &Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Logout, "Auth_Logout" }, // 2505138860
		{ &Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Register, "Auth_Register" }, // 1645962522
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEchoesAuthSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UEchoesAuthSubsystem_Statics::NewProp_JWTToken = { "JWTToken", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesAuthSubsystem, JWTToken), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JWTToken_MetaData), NewProp_JWTToken_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEchoesAuthSubsystem_Statics::NewProp_CurrentAuthResponse = { "CurrentAuthResponse", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesAuthSubsystem, CurrentAuthResponse), Z_Construct_UScriptStruct_FAuthResponse, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentAuthResponse_MetaData), NewProp_CurrentAuthResponse_MetaData) }; // 3112734285
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEchoesAuthSubsystem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesAuthSubsystem_Statics::NewProp_JWTToken,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesAuthSubsystem_Statics::NewProp_CurrentAuthResponse,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesAuthSubsystem_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UEchoesAuthSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesAuthSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEchoesAuthSubsystem_Statics::ClassParams = {
	&UEchoesAuthSubsystem::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UEchoesAuthSubsystem_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesAuthSubsystem_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesAuthSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UEchoesAuthSubsystem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEchoesAuthSubsystem()
{
	if (!Z_Registration_Info_UClass_UEchoesAuthSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEchoesAuthSubsystem.OuterSingleton, Z_Construct_UClass_UEchoesAuthSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEchoesAuthSubsystem.OuterSingleton;
}
UEchoesAuthSubsystem::UEchoesAuthSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UEchoesAuthSubsystem);
UEchoesAuthSubsystem::~UEchoesAuthSubsystem() {}
// ********** End Class UEchoesAuthSubsystem *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h__Script_Echoes_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FAuthRequest::StaticStruct, Z_Construct_UScriptStruct_FAuthRequest_Statics::NewStructOps, TEXT("AuthRequest"), &Z_Registration_Info_UScriptStruct_FAuthRequest, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAuthRequest), 1202977449U) },
		{ FCharacterInfo::StaticStruct, Z_Construct_UScriptStruct_FCharacterInfo_Statics::NewStructOps, TEXT("CharacterInfo"), &Z_Registration_Info_UScriptStruct_FCharacterInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FCharacterInfo), 2611301823U) },
		{ FAuthResponse::StaticStruct, Z_Construct_UScriptStruct_FAuthResponse_Statics::NewStructOps, TEXT("AuthResponse"), &Z_Registration_Info_UScriptStruct_FAuthResponse, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAuthResponse), 3112734285U) },
		{ FCharacterData::StaticStruct, Z_Construct_UScriptStruct_FCharacterData_Statics::NewStructOps, TEXT("CharacterData"), &Z_Registration_Info_UScriptStruct_FCharacterData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FCharacterData), 2418886937U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEchoesAuthSubsystem, UEchoesAuthSubsystem::StaticClass, TEXT("UEchoesAuthSubsystem"), &Z_Registration_Info_UClass_UEchoesAuthSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEchoesAuthSubsystem), 2559076142U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h__Script_Echoes_1192370907(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h__Script_Echoes_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h__Script_Echoes_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h__Script_Echoes_Statics::ScriptStructInfo),
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
