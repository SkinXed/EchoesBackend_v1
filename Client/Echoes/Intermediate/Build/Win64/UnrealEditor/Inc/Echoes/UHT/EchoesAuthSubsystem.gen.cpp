// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EchoesAuthSubsystem.h"
#include "EchoesCharacterData.h"
#include "Engine/GameInstance.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesAuthSubsystem() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FDateTime();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ECHOES_API UClass* Z_Construct_UClass_UEchoesAuthSubsystem();
ECHOES_API UClass* Z_Construct_UClass_UEchoesAuthSubsystem_NoRegister();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnCharacterCreated__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnCharacterCreationFailed__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnCharacterDeleted__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnCharacterDeletionFailed__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnCharacterListUpdated__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnConnectInfoFailed__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnConnectInfoReceived__DelegateSignature();
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RaceId_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RaceName_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WalletBalance_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Credits_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExperiencePoints_MetaData[] = {
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
	static const UECodeGen_Private::FIntPropertyParams NewProp_RaceId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_RaceName;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_WalletBalance;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_Credits;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ExperiencePoints;
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
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FCharacterInfo_Statics::NewProp_RaceId = { "RaceId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterInfo, RaceId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RaceId_MetaData), NewProp_RaceId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FCharacterInfo_Statics::NewProp_RaceName = { "RaceName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterInfo, RaceName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RaceName_MetaData), NewProp_RaceName_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FCharacterInfo_Statics::NewProp_WalletBalance = { "WalletBalance", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterInfo, WalletBalance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WalletBalance_MetaData), NewProp_WalletBalance_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FCharacterInfo_Statics::NewProp_Credits = { "Credits", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterInfo, Credits), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Credits_MetaData), NewProp_Credits_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FCharacterInfo_Statics::NewProp_ExperiencePoints = { "ExperiencePoints", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterInfo, ExperiencePoints), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExperiencePoints_MetaData), NewProp_ExperiencePoints_MetaData) };
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
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterInfo_Statics::NewProp_RaceId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterInfo_Statics::NewProp_RaceName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterInfo_Statics::NewProp_WalletBalance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterInfo_Statics::NewProp_Credits,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterInfo_Statics::NewProp_ExperiencePoints,
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
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAuthResponse_Statics::NewProp_Characters_Inner = { "Characters", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FCharacterInfo, METADATA_PARAMS(0, nullptr) }; // 2252549621
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FAuthResponse_Statics::NewProp_Characters = { "Characters", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAuthResponse, Characters), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Characters_MetaData), NewProp_Characters_MetaData) }; // 2252549621
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
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_Echoes_OnLoginSuccess__DelegateSignature_Statics::NewProp_AuthResponse = { "AuthResponse", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnLoginSuccess_Parms, AuthResponse), Z_Construct_UScriptStruct_FAuthResponse, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AuthResponse_MetaData), NewProp_AuthResponse_MetaData) }; // 2780569161
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
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_Echoes_OnRegisterSuccess__DelegateSignature_Statics::NewProp_AuthResponse = { "AuthResponse", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnRegisterSuccess_Parms, AuthResponse), Z_Construct_UScriptStruct_FAuthResponse, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AuthResponse_MetaData), NewProp_AuthResponse_MetaData) }; // 2780569161
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

// ********** Begin Delegate FOnCharacterCreated ***************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnCharacterCreated__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnCharacterCreated_Parms
	{
		FCharacterData CharacterData;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// New delegates for character operations\n" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "New delegates for character operations" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_CharacterData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_Echoes_OnCharacterCreated__DelegateSignature_Statics::NewProp_CharacterData = { "CharacterData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnCharacterCreated_Parms, CharacterData), Z_Construct_UScriptStruct_FCharacterData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterData_MetaData), NewProp_CharacterData_MetaData) }; // 1874857763
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnCharacterCreated__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnCharacterCreated__DelegateSignature_Statics::NewProp_CharacterData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnCharacterCreated__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnCharacterCreated__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnCharacterCreated__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnCharacterCreated__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnCharacterCreated__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnCharacterCreated__DelegateSignature_Statics::_Script_Echoes_eventOnCharacterCreated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnCharacterCreated__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnCharacterCreated__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnCharacterCreated__DelegateSignature_Statics::_Script_Echoes_eventOnCharacterCreated_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnCharacterCreated__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnCharacterCreated__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnCharacterCreated_DelegateWrapper(const FMulticastScriptDelegate& OnCharacterCreated, FCharacterData const& CharacterData)
{
	struct _Script_Echoes_eventOnCharacterCreated_Parms
	{
		FCharacterData CharacterData;
	};
	_Script_Echoes_eventOnCharacterCreated_Parms Parms;
	Parms.CharacterData=CharacterData;
	OnCharacterCreated.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnCharacterCreated *****************************************************

// ********** Begin Delegate FOnCharacterCreationFailed ********************************************
struct Z_Construct_UDelegateFunction_Echoes_OnCharacterCreationFailed__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnCharacterCreationFailed_Parms
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
const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_Echoes_OnCharacterCreationFailed__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnCharacterCreationFailed_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ErrorMessage_MetaData), NewProp_ErrorMessage_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnCharacterCreationFailed__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnCharacterCreationFailed__DelegateSignature_Statics::NewProp_ErrorMessage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnCharacterCreationFailed__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnCharacterCreationFailed__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnCharacterCreationFailed__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnCharacterCreationFailed__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnCharacterCreationFailed__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnCharacterCreationFailed__DelegateSignature_Statics::_Script_Echoes_eventOnCharacterCreationFailed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnCharacterCreationFailed__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnCharacterCreationFailed__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnCharacterCreationFailed__DelegateSignature_Statics::_Script_Echoes_eventOnCharacterCreationFailed_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnCharacterCreationFailed__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnCharacterCreationFailed__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnCharacterCreationFailed_DelegateWrapper(const FMulticastScriptDelegate& OnCharacterCreationFailed, const FString& ErrorMessage)
{
	struct _Script_Echoes_eventOnCharacterCreationFailed_Parms
	{
		FString ErrorMessage;
	};
	_Script_Echoes_eventOnCharacterCreationFailed_Parms Parms;
	Parms.ErrorMessage=ErrorMessage;
	OnCharacterCreationFailed.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnCharacterCreationFailed **********************************************

// ********** Begin Delegate FOnConnectInfoReceived ************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnConnectInfoReceived__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnConnectInfoReceived_Parms
	{
		FString ServerIP;
		int32 ServerPort;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ServerIP_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ServerIP;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ServerPort;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_Echoes_OnConnectInfoReceived__DelegateSignature_Statics::NewProp_ServerIP = { "ServerIP", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnConnectInfoReceived_Parms, ServerIP), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ServerIP_MetaData), NewProp_ServerIP_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_Echoes_OnConnectInfoReceived__DelegateSignature_Statics::NewProp_ServerPort = { "ServerPort", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnConnectInfoReceived_Parms, ServerPort), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnConnectInfoReceived__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnConnectInfoReceived__DelegateSignature_Statics::NewProp_ServerIP,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnConnectInfoReceived__DelegateSignature_Statics::NewProp_ServerPort,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnConnectInfoReceived__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnConnectInfoReceived__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnConnectInfoReceived__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnConnectInfoReceived__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnConnectInfoReceived__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnConnectInfoReceived__DelegateSignature_Statics::_Script_Echoes_eventOnConnectInfoReceived_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnConnectInfoReceived__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnConnectInfoReceived__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnConnectInfoReceived__DelegateSignature_Statics::_Script_Echoes_eventOnConnectInfoReceived_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnConnectInfoReceived__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnConnectInfoReceived__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnConnectInfoReceived_DelegateWrapper(const FMulticastScriptDelegate& OnConnectInfoReceived, const FString& ServerIP, int32 ServerPort)
{
	struct _Script_Echoes_eventOnConnectInfoReceived_Parms
	{
		FString ServerIP;
		int32 ServerPort;
	};
	_Script_Echoes_eventOnConnectInfoReceived_Parms Parms;
	Parms.ServerIP=ServerIP;
	Parms.ServerPort=ServerPort;
	OnConnectInfoReceived.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnConnectInfoReceived **************************************************

// ********** Begin Delegate FOnConnectInfoFailed **************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnConnectInfoFailed__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnConnectInfoFailed_Parms
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
const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_Echoes_OnConnectInfoFailed__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnConnectInfoFailed_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ErrorMessage_MetaData), NewProp_ErrorMessage_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnConnectInfoFailed__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnConnectInfoFailed__DelegateSignature_Statics::NewProp_ErrorMessage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnConnectInfoFailed__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnConnectInfoFailed__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnConnectInfoFailed__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnConnectInfoFailed__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnConnectInfoFailed__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnConnectInfoFailed__DelegateSignature_Statics::_Script_Echoes_eventOnConnectInfoFailed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnConnectInfoFailed__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnConnectInfoFailed__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnConnectInfoFailed__DelegateSignature_Statics::_Script_Echoes_eventOnConnectInfoFailed_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnConnectInfoFailed__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnConnectInfoFailed__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnConnectInfoFailed_DelegateWrapper(const FMulticastScriptDelegate& OnConnectInfoFailed, const FString& ErrorMessage)
{
	struct _Script_Echoes_eventOnConnectInfoFailed_Parms
	{
		FString ErrorMessage;
	};
	_Script_Echoes_eventOnConnectInfoFailed_Parms Parms;
	Parms.ErrorMessage=ErrorMessage;
	OnConnectInfoFailed.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnConnectInfoFailed ****************************************************

// ********** Begin Delegate FOnCharacterDeleted ***************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnCharacterDeleted__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnCharacterDeleted_Parms
	{
		FGuid CharacterId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_CharacterId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_Echoes_OnCharacterDeleted__DelegateSignature_Statics::NewProp_CharacterId = { "CharacterId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnCharacterDeleted_Parms, CharacterId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterId_MetaData), NewProp_CharacterId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnCharacterDeleted__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnCharacterDeleted__DelegateSignature_Statics::NewProp_CharacterId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnCharacterDeleted__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnCharacterDeleted__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnCharacterDeleted__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnCharacterDeleted__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnCharacterDeleted__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnCharacterDeleted__DelegateSignature_Statics::_Script_Echoes_eventOnCharacterDeleted_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnCharacterDeleted__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnCharacterDeleted__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnCharacterDeleted__DelegateSignature_Statics::_Script_Echoes_eventOnCharacterDeleted_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnCharacterDeleted__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnCharacterDeleted__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnCharacterDeleted_DelegateWrapper(const FMulticastScriptDelegate& OnCharacterDeleted, FGuid const& CharacterId)
{
	struct _Script_Echoes_eventOnCharacterDeleted_Parms
	{
		FGuid CharacterId;
	};
	_Script_Echoes_eventOnCharacterDeleted_Parms Parms;
	Parms.CharacterId=CharacterId;
	OnCharacterDeleted.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnCharacterDeleted *****************************************************

// ********** Begin Delegate FOnCharacterDeletionFailed ********************************************
struct Z_Construct_UDelegateFunction_Echoes_OnCharacterDeletionFailed__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnCharacterDeletionFailed_Parms
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
const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_Echoes_OnCharacterDeletionFailed__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnCharacterDeletionFailed_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ErrorMessage_MetaData), NewProp_ErrorMessage_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnCharacterDeletionFailed__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnCharacterDeletionFailed__DelegateSignature_Statics::NewProp_ErrorMessage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnCharacterDeletionFailed__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnCharacterDeletionFailed__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnCharacterDeletionFailed__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnCharacterDeletionFailed__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnCharacterDeletionFailed__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnCharacterDeletionFailed__DelegateSignature_Statics::_Script_Echoes_eventOnCharacterDeletionFailed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnCharacterDeletionFailed__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnCharacterDeletionFailed__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnCharacterDeletionFailed__DelegateSignature_Statics::_Script_Echoes_eventOnCharacterDeletionFailed_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnCharacterDeletionFailed__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnCharacterDeletionFailed__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnCharacterDeletionFailed_DelegateWrapper(const FMulticastScriptDelegate& OnCharacterDeletionFailed, const FString& ErrorMessage)
{
	struct _Script_Echoes_eventOnCharacterDeletionFailed_Parms
	{
		FString ErrorMessage;
	};
	_Script_Echoes_eventOnCharacterDeletionFailed_Parms Parms;
	Parms.ErrorMessage=ErrorMessage;
	OnCharacterDeletionFailed.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnCharacterDeletionFailed **********************************************

// ********** Begin Delegate FOnCharacterListUpdated ***********************************************
struct Z_Construct_UDelegateFunction_Echoes_OnCharacterListUpdated__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnCharacterListUpdated_Parms
	{
		TArray<FCharacterInfo> Characters;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Characters_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Characters_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Characters;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_Echoes_OnCharacterListUpdated__DelegateSignature_Statics::NewProp_Characters_Inner = { "Characters", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FCharacterInfo, METADATA_PARAMS(0, nullptr) }; // 2252549621
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UDelegateFunction_Echoes_OnCharacterListUpdated__DelegateSignature_Statics::NewProp_Characters = { "Characters", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnCharacterListUpdated_Parms, Characters), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Characters_MetaData), NewProp_Characters_MetaData) }; // 2252549621
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnCharacterListUpdated__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnCharacterListUpdated__DelegateSignature_Statics::NewProp_Characters_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnCharacterListUpdated__DelegateSignature_Statics::NewProp_Characters,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnCharacterListUpdated__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnCharacterListUpdated__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnCharacterListUpdated__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnCharacterListUpdated__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnCharacterListUpdated__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnCharacterListUpdated__DelegateSignature_Statics::_Script_Echoes_eventOnCharacterListUpdated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnCharacterListUpdated__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnCharacterListUpdated__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnCharacterListUpdated__DelegateSignature_Statics::_Script_Echoes_eventOnCharacterListUpdated_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnCharacterListUpdated__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnCharacterListUpdated__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnCharacterListUpdated_DelegateWrapper(const FMulticastScriptDelegate& OnCharacterListUpdated, TArray<FCharacterInfo> const& Characters)
{
	struct _Script_Echoes_eventOnCharacterListUpdated_Parms
	{
		TArray<FCharacterInfo> Characters;
	};
	_Script_Echoes_eventOnCharacterListUpdated_Parms Parms;
	Parms.Characters=Characters;
	OnCharacterListUpdated.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnCharacterListUpdated *************************************************

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
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetCharacters_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FCharacterInfo, METADATA_PARAMS(0, nullptr) }; // 2252549621
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetCharacters_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesAuthSubsystem_eventAuth_GetCharacters_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 2252549621
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
const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Login_Statics::NewProp_OnSuccess = { "OnSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesAuthSubsystem_eventAuth_Login_Parms, OnSuccess), Z_Construct_UDelegateFunction_Echoes_OnLoginSuccess__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 167529748
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
const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Register_Statics::NewProp_OnSuccess = { "OnSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesAuthSubsystem_eventAuth_Register_Parms, OnSuccess), Z_Construct_UDelegateFunction_Echoes_OnRegisterSuccess__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 2761244133
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

// ********** Begin Class UEchoesAuthSubsystem Function ClearSavedToken ****************************
struct Z_Construct_UFunction_UEchoesAuthSubsystem_ClearSavedToken_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Auth" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Clear saved authentication token\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Clear saved authentication token" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesAuthSubsystem_ClearSavedToken_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesAuthSubsystem, nullptr, "ClearSavedToken", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesAuthSubsystem_ClearSavedToken_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesAuthSubsystem_ClearSavedToken_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesAuthSubsystem_ClearSavedToken()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesAuthSubsystem_ClearSavedToken_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesAuthSubsystem::execClearSavedToken)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClearSavedToken();
	P_NATIVE_END;
}
// ********** End Class UEchoesAuthSubsystem Function ClearSavedToken ******************************

// ********** Begin Class UEchoesAuthSubsystem Function ConnectToWorld *****************************
struct Z_Construct_UFunction_UEchoesAuthSubsystem_ConnectToWorld_Statics
{
	struct EchoesAuthSubsystem_eventConnectToWorld_Parms
	{
		FGuid CharacterId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Character" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Connect to world with selected character\n\x09 * Gets server connection info and initiates ClientTravel\n\x09 * @param CharacterId - Character to connect with\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Connect to world with selected character\nGets server connection info and initiates ClientTravel\n@param CharacterId - Character to connect with" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_CharacterId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesAuthSubsystem_ConnectToWorld_Statics::NewProp_CharacterId = { "CharacterId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesAuthSubsystem_eventConnectToWorld_Parms, CharacterId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterId_MetaData), NewProp_CharacterId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesAuthSubsystem_ConnectToWorld_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesAuthSubsystem_ConnectToWorld_Statics::NewProp_CharacterId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesAuthSubsystem_ConnectToWorld_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesAuthSubsystem_ConnectToWorld_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesAuthSubsystem, nullptr, "ConnectToWorld", Z_Construct_UFunction_UEchoesAuthSubsystem_ConnectToWorld_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesAuthSubsystem_ConnectToWorld_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesAuthSubsystem_ConnectToWorld_Statics::EchoesAuthSubsystem_eventConnectToWorld_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesAuthSubsystem_ConnectToWorld_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesAuthSubsystem_ConnectToWorld_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesAuthSubsystem_ConnectToWorld_Statics::EchoesAuthSubsystem_eventConnectToWorld_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesAuthSubsystem_ConnectToWorld()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesAuthSubsystem_ConnectToWorld_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesAuthSubsystem::execConnectToWorld)
{
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_CharacterId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ConnectToWorld(Z_Param_Out_CharacterId);
	P_NATIVE_END;
}
// ********** End Class UEchoesAuthSubsystem Function ConnectToWorld *******************************

// ********** Begin Class UEchoesAuthSubsystem Function CreateCharacter ****************************
struct Z_Construct_UFunction_UEchoesAuthSubsystem_CreateCharacter_Statics
{
	struct EchoesAuthSubsystem_eventCreateCharacter_Parms
	{
		FString CharacterName;
		int32 RaceId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Character" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Create new character\n\x09 * @param CharacterName - Name for the new character\n\x09 * @param RaceId - Race ID (1=Caldari, 2=Gallente, 3=Amarr, 4=Minmatar)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Create new character\n@param CharacterName - Name for the new character\n@param RaceId - Race ID (1=Caldari, 2=Gallente, 3=Amarr, 4=Minmatar)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_CharacterName;
	static const UECodeGen_Private::FIntPropertyParams NewProp_RaceId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEchoesAuthSubsystem_CreateCharacter_Statics::NewProp_CharacterName = { "CharacterName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesAuthSubsystem_eventCreateCharacter_Parms, CharacterName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterName_MetaData), NewProp_CharacterName_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UEchoesAuthSubsystem_CreateCharacter_Statics::NewProp_RaceId = { "RaceId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesAuthSubsystem_eventCreateCharacter_Parms, RaceId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesAuthSubsystem_CreateCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesAuthSubsystem_CreateCharacter_Statics::NewProp_CharacterName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesAuthSubsystem_CreateCharacter_Statics::NewProp_RaceId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesAuthSubsystem_CreateCharacter_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesAuthSubsystem_CreateCharacter_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesAuthSubsystem, nullptr, "CreateCharacter", Z_Construct_UFunction_UEchoesAuthSubsystem_CreateCharacter_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesAuthSubsystem_CreateCharacter_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesAuthSubsystem_CreateCharacter_Statics::EchoesAuthSubsystem_eventCreateCharacter_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesAuthSubsystem_CreateCharacter_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesAuthSubsystem_CreateCharacter_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesAuthSubsystem_CreateCharacter_Statics::EchoesAuthSubsystem_eventCreateCharacter_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesAuthSubsystem_CreateCharacter()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesAuthSubsystem_CreateCharacter_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesAuthSubsystem::execCreateCharacter)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_CharacterName);
	P_GET_PROPERTY(FIntProperty,Z_Param_RaceId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CreateCharacter(Z_Param_CharacterName,Z_Param_RaceId);
	P_NATIVE_END;
}
// ********** End Class UEchoesAuthSubsystem Function CreateCharacter ******************************

// ********** Begin Class UEchoesAuthSubsystem Function DeleteCharacter ****************************
struct Z_Construct_UFunction_UEchoesAuthSubsystem_DeleteCharacter_Statics
{
	struct EchoesAuthSubsystem_eventDeleteCharacter_Parms
	{
		FGuid CharacterId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_CharacterId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesAuthSubsystem_DeleteCharacter_Statics::NewProp_CharacterId = { "CharacterId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesAuthSubsystem_eventDeleteCharacter_Parms, CharacterId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterId_MetaData), NewProp_CharacterId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesAuthSubsystem_DeleteCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesAuthSubsystem_DeleteCharacter_Statics::NewProp_CharacterId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesAuthSubsystem_DeleteCharacter_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesAuthSubsystem_DeleteCharacter_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesAuthSubsystem, nullptr, "DeleteCharacter", Z_Construct_UFunction_UEchoesAuthSubsystem_DeleteCharacter_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesAuthSubsystem_DeleteCharacter_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesAuthSubsystem_DeleteCharacter_Statics::EchoesAuthSubsystem_eventDeleteCharacter_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesAuthSubsystem_DeleteCharacter_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesAuthSubsystem_DeleteCharacter_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesAuthSubsystem_DeleteCharacter_Statics::EchoesAuthSubsystem_eventDeleteCharacter_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesAuthSubsystem_DeleteCharacter()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesAuthSubsystem_DeleteCharacter_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesAuthSubsystem::execDeleteCharacter)
{
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_CharacterId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DeleteCharacter(Z_Param_Out_CharacterId);
	P_NATIVE_END;
}
// ********** End Class UEchoesAuthSubsystem Function DeleteCharacter ******************************

// ********** Begin Class UEchoesAuthSubsystem Function FetchCharacterList *************************
struct Z_Construct_UFunction_UEchoesAuthSubsystem_FetchCharacterList_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Character" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Fetch character list from backend\n\x09 * Updates CurrentAuthResponse.Characters\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fetch character list from backend\nUpdates CurrentAuthResponse.Characters" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesAuthSubsystem_FetchCharacterList_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesAuthSubsystem, nullptr, "FetchCharacterList", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesAuthSubsystem_FetchCharacterList_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesAuthSubsystem_FetchCharacterList_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesAuthSubsystem_FetchCharacterList()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesAuthSubsystem_FetchCharacterList_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesAuthSubsystem::execFetchCharacterList)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->FetchCharacterList();
	P_NATIVE_END;
}
// ********** End Class UEchoesAuthSubsystem Function FetchCharacterList ***************************

// ********** Begin Class UEchoesAuthSubsystem Function LoadAuthToken ******************************
struct Z_Construct_UFunction_UEchoesAuthSubsystem_LoadAuthToken_Statics
{
	struct EchoesAuthSubsystem_eventLoadAuthToken_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Auth" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Load authentication token from disk\n\x09 * @return True if token was loaded and is valid\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Load authentication token from disk\n@return True if token was loaded and is valid" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UEchoesAuthSubsystem_LoadAuthToken_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((EchoesAuthSubsystem_eventLoadAuthToken_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UEchoesAuthSubsystem_LoadAuthToken_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EchoesAuthSubsystem_eventLoadAuthToken_Parms), &Z_Construct_UFunction_UEchoesAuthSubsystem_LoadAuthToken_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesAuthSubsystem_LoadAuthToken_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesAuthSubsystem_LoadAuthToken_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesAuthSubsystem_LoadAuthToken_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesAuthSubsystem_LoadAuthToken_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesAuthSubsystem, nullptr, "LoadAuthToken", Z_Construct_UFunction_UEchoesAuthSubsystem_LoadAuthToken_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesAuthSubsystem_LoadAuthToken_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesAuthSubsystem_LoadAuthToken_Statics::EchoesAuthSubsystem_eventLoadAuthToken_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesAuthSubsystem_LoadAuthToken_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesAuthSubsystem_LoadAuthToken_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesAuthSubsystem_LoadAuthToken_Statics::EchoesAuthSubsystem_eventLoadAuthToken_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesAuthSubsystem_LoadAuthToken()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesAuthSubsystem_LoadAuthToken_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesAuthSubsystem::execLoadAuthToken)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->LoadAuthToken();
	P_NATIVE_END;
}
// ********** End Class UEchoesAuthSubsystem Function LoadAuthToken ********************************

// ********** Begin Class UEchoesAuthSubsystem Function SaveAuthToken ******************************
struct Z_Construct_UFunction_UEchoesAuthSubsystem_SaveAuthToken_Statics
{
	struct EchoesAuthSubsystem_eventSaveAuthToken_Parms
	{
		bool bRememberMe;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Auth" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Save authentication token to disk\n\x09 * @param bRememberMe - If true, saves token for next session\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Save authentication token to disk\n@param bRememberMe - If true, saves token for next session" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_bRememberMe_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRememberMe;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UEchoesAuthSubsystem_SaveAuthToken_Statics::NewProp_bRememberMe_SetBit(void* Obj)
{
	((EchoesAuthSubsystem_eventSaveAuthToken_Parms*)Obj)->bRememberMe = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UEchoesAuthSubsystem_SaveAuthToken_Statics::NewProp_bRememberMe = { "bRememberMe", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EchoesAuthSubsystem_eventSaveAuthToken_Parms), &Z_Construct_UFunction_UEchoesAuthSubsystem_SaveAuthToken_Statics::NewProp_bRememberMe_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesAuthSubsystem_SaveAuthToken_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesAuthSubsystem_SaveAuthToken_Statics::NewProp_bRememberMe,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesAuthSubsystem_SaveAuthToken_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesAuthSubsystem_SaveAuthToken_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesAuthSubsystem, nullptr, "SaveAuthToken", Z_Construct_UFunction_UEchoesAuthSubsystem_SaveAuthToken_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesAuthSubsystem_SaveAuthToken_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesAuthSubsystem_SaveAuthToken_Statics::EchoesAuthSubsystem_eventSaveAuthToken_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesAuthSubsystem_SaveAuthToken_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesAuthSubsystem_SaveAuthToken_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesAuthSubsystem_SaveAuthToken_Statics::EchoesAuthSubsystem_eventSaveAuthToken_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesAuthSubsystem_SaveAuthToken()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesAuthSubsystem_SaveAuthToken_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesAuthSubsystem::execSaveAuthToken)
{
	P_GET_UBOOL(Z_Param_bRememberMe);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SaveAuthToken(Z_Param_bRememberMe);
	P_NATIVE_END;
}
// ********** End Class UEchoesAuthSubsystem Function SaveAuthToken ********************************

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
		{ "ClearSavedToken", &UEchoesAuthSubsystem::execClearSavedToken },
		{ "ConnectToWorld", &UEchoesAuthSubsystem::execConnectToWorld },
		{ "CreateCharacter", &UEchoesAuthSubsystem::execCreateCharacter },
		{ "DeleteCharacter", &UEchoesAuthSubsystem::execDeleteCharacter },
		{ "FetchCharacterList", &UEchoesAuthSubsystem::execFetchCharacterList },
		{ "LoadAuthToken", &UEchoesAuthSubsystem::execLoadAuthToken },
		{ "SaveAuthToken", &UEchoesAuthSubsystem::execSaveAuthToken },
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnCharacterCreated_MetaData[] = {
		{ "Category", "Echoes|Character" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when character is created successfully */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when character is created successfully" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnCharacterCreationFailed_MetaData[] = {
		{ "Category", "Echoes|Character" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when character creation fails */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when character creation fails" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnConnectInfoReceived_MetaData[] = {
		{ "Category", "Echoes|Character" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when connection info is received */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when connection info is received" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnConnectInfoFailed_MetaData[] = {
		{ "Category", "Echoes|Character" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when connection info request fails */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when connection info request fails" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnCharacterDeleted_MetaData[] = {
		{ "Category", "Echoes|Character" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when character is deleted successfully */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when character is deleted successfully" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnCharacterDeletionFailed_MetaData[] = {
		{ "Category", "Echoes|Character" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when character deletion fails */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when character deletion fails" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnCharacterListUpdated_MetaData[] = {
		{ "Category", "Echoes|Character" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when character list is updated */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesAuthSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when character list is updated" },
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
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCharacterCreated;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCharacterCreationFailed;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnConnectInfoReceived;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnConnectInfoFailed;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCharacterDeleted;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCharacterDeletionFailed;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCharacterListUpdated;
	static const UECodeGen_Private::FStrPropertyParams NewProp_JWTToken;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentAuthResponse;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetAccountId, "Auth_GetAccountId" }, // 1247892163
		{ &Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetCharacterId, "Auth_GetCharacterId" }, // 1847183580
		{ &Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetCharacters, "Auth_GetCharacters" }, // 3870143386
		{ &Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_GetToken, "Auth_GetToken" }, // 633235763
		{ &Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_IsLoggedIn, "Auth_IsLoggedIn" }, // 2846008563
		{ &Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Login, "Auth_Login" }, // 700388799
		{ &Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Logout, "Auth_Logout" }, // 2505138860
		{ &Z_Construct_UFunction_UEchoesAuthSubsystem_Auth_Register, "Auth_Register" }, // 467027317
		{ &Z_Construct_UFunction_UEchoesAuthSubsystem_ClearSavedToken, "ClearSavedToken" }, // 4188288415
		{ &Z_Construct_UFunction_UEchoesAuthSubsystem_ConnectToWorld, "ConnectToWorld" }, // 2338996400
		{ &Z_Construct_UFunction_UEchoesAuthSubsystem_CreateCharacter, "CreateCharacter" }, // 3288174077
		{ &Z_Construct_UFunction_UEchoesAuthSubsystem_DeleteCharacter, "DeleteCharacter" }, // 2915549773
		{ &Z_Construct_UFunction_UEchoesAuthSubsystem_FetchCharacterList, "FetchCharacterList" }, // 1705971706
		{ &Z_Construct_UFunction_UEchoesAuthSubsystem_LoadAuthToken, "LoadAuthToken" }, // 2978226635
		{ &Z_Construct_UFunction_UEchoesAuthSubsystem_SaveAuthToken, "SaveAuthToken" }, // 3110014756
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEchoesAuthSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEchoesAuthSubsystem_Statics::NewProp_OnCharacterCreated = { "OnCharacterCreated", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesAuthSubsystem, OnCharacterCreated), Z_Construct_UDelegateFunction_Echoes_OnCharacterCreated__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnCharacterCreated_MetaData), NewProp_OnCharacterCreated_MetaData) }; // 2190763791
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEchoesAuthSubsystem_Statics::NewProp_OnCharacterCreationFailed = { "OnCharacterCreationFailed", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesAuthSubsystem, OnCharacterCreationFailed), Z_Construct_UDelegateFunction_Echoes_OnCharacterCreationFailed__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnCharacterCreationFailed_MetaData), NewProp_OnCharacterCreationFailed_MetaData) }; // 2495534801
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEchoesAuthSubsystem_Statics::NewProp_OnConnectInfoReceived = { "OnConnectInfoReceived", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesAuthSubsystem, OnConnectInfoReceived), Z_Construct_UDelegateFunction_Echoes_OnConnectInfoReceived__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnConnectInfoReceived_MetaData), NewProp_OnConnectInfoReceived_MetaData) }; // 1090635087
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEchoesAuthSubsystem_Statics::NewProp_OnConnectInfoFailed = { "OnConnectInfoFailed", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesAuthSubsystem, OnConnectInfoFailed), Z_Construct_UDelegateFunction_Echoes_OnConnectInfoFailed__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnConnectInfoFailed_MetaData), NewProp_OnConnectInfoFailed_MetaData) }; // 2135600930
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEchoesAuthSubsystem_Statics::NewProp_OnCharacterDeleted = { "OnCharacterDeleted", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesAuthSubsystem, OnCharacterDeleted), Z_Construct_UDelegateFunction_Echoes_OnCharacterDeleted__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnCharacterDeleted_MetaData), NewProp_OnCharacterDeleted_MetaData) }; // 3242709004
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEchoesAuthSubsystem_Statics::NewProp_OnCharacterDeletionFailed = { "OnCharacterDeletionFailed", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesAuthSubsystem, OnCharacterDeletionFailed), Z_Construct_UDelegateFunction_Echoes_OnCharacterDeletionFailed__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnCharacterDeletionFailed_MetaData), NewProp_OnCharacterDeletionFailed_MetaData) }; // 3050336762
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEchoesAuthSubsystem_Statics::NewProp_OnCharacterListUpdated = { "OnCharacterListUpdated", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesAuthSubsystem, OnCharacterListUpdated), Z_Construct_UDelegateFunction_Echoes_OnCharacterListUpdated__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnCharacterListUpdated_MetaData), NewProp_OnCharacterListUpdated_MetaData) }; // 3401910082
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UEchoesAuthSubsystem_Statics::NewProp_JWTToken = { "JWTToken", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesAuthSubsystem, JWTToken), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JWTToken_MetaData), NewProp_JWTToken_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEchoesAuthSubsystem_Statics::NewProp_CurrentAuthResponse = { "CurrentAuthResponse", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesAuthSubsystem, CurrentAuthResponse), Z_Construct_UScriptStruct_FAuthResponse, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentAuthResponse_MetaData), NewProp_CurrentAuthResponse_MetaData) }; // 2780569161
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEchoesAuthSubsystem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesAuthSubsystem_Statics::NewProp_OnCharacterCreated,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesAuthSubsystem_Statics::NewProp_OnCharacterCreationFailed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesAuthSubsystem_Statics::NewProp_OnConnectInfoReceived,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesAuthSubsystem_Statics::NewProp_OnConnectInfoFailed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesAuthSubsystem_Statics::NewProp_OnCharacterDeleted,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesAuthSubsystem_Statics::NewProp_OnCharacterDeletionFailed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesAuthSubsystem_Statics::NewProp_OnCharacterListUpdated,
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
	0x009000A0u,
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
		{ FCharacterInfo::StaticStruct, Z_Construct_UScriptStruct_FCharacterInfo_Statics::NewStructOps, TEXT("CharacterInfo"), &Z_Registration_Info_UScriptStruct_FCharacterInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FCharacterInfo), 2252549621U) },
		{ FAuthResponse::StaticStruct, Z_Construct_UScriptStruct_FAuthResponse_Statics::NewStructOps, TEXT("AuthResponse"), &Z_Registration_Info_UScriptStruct_FAuthResponse, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAuthResponse), 2780569161U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEchoesAuthSubsystem, UEchoesAuthSubsystem::StaticClass, TEXT("UEchoesAuthSubsystem"), &Z_Registration_Info_UClass_UEchoesAuthSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEchoesAuthSubsystem), 3364659935U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h__Script_Echoes_693184064(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h__Script_Echoes_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h__Script_Echoes_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h__Script_Echoes_Statics::ScriptStructInfo),
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
