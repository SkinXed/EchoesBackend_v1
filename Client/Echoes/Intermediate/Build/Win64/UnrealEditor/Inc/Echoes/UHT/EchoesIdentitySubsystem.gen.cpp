// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EchoesIdentitySubsystem.h"
#include "Engine/GameInstance.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesIdentitySubsystem() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FDateTime();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ECHOES_API UClass* Z_Construct_UClass_UEchoesIdentitySubsystem();
ECHOES_API UClass* Z_Construct_UClass_UEchoesIdentitySubsystem_NoRegister();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnCharacterDataFailure__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnCharacterDataReceived__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnCharacterSelected__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnIdentityCharacterCreated__DelegateSignature();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FEchoesCharacter();
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FEchoesCharacter **************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FEchoesCharacter;
class UScriptStruct* FEchoesCharacter::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FEchoesCharacter.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FEchoesCharacter.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FEchoesCharacter, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("EchoesCharacter"));
	}
	return Z_Registration_Info_UScriptStruct_FEchoesCharacter.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FEchoesCharacter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Character structure (mirrors C# CharacterDataDto)\n * Common_ prefix for shared data structures\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesIdentitySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Character structure (mirrors C# CharacterDataDto)\nCommon_ prefix for shared data structures" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterId_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesIdentitySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesIdentitySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AccountId_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesIdentitySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WalletBalance_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesIdentitySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Credits_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesIdentitySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ISK_MetaData[] = {
		{ "Category", "Character" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** ISK balance (alias for WalletBalance for EVE-style naming) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesIdentitySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "ISK balance (alias for WalletBalance for EVE-style naming)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SecurityStatus_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesIdentitySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentShipId_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesIdentitySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CorporationId_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesIdentitySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RaceId_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesIdentitySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalSkillPoints_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesIdentitySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExperiencePoints_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesIdentitySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UnallocatedSkillPoints_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesIdentitySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IsOnline_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesIdentitySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IsDocked_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesIdentitySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InWarp_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesIdentitySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LastLogin_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesIdentitySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PortraitURL_MetaData[] = {
		{ "Category", "Character" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Portrait URL for UI display */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesIdentitySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Portrait URL for UI display" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_CharacterId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AccountId;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_WalletBalance;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_Credits;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_ISK;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SecurityStatus;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_CurrentShipId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CorporationId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_RaceId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_TotalSkillPoints;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ExperiencePoints;
	static const UECodeGen_Private::FIntPropertyParams NewProp_UnallocatedSkillPoints;
	static void NewProp_IsOnline_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_IsOnline;
	static void NewProp_IsDocked_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_IsDocked;
	static void NewProp_InWarp_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_InWarp;
	static const UECodeGen_Private::FStructPropertyParams NewProp_LastLogin;
	static const UECodeGen_Private::FStrPropertyParams NewProp_PortraitURL;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FEchoesCharacter>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FEchoesCharacter_Statics::NewProp_CharacterId = { "CharacterId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesCharacter, CharacterId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterId_MetaData), NewProp_CharacterId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FEchoesCharacter_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesCharacter, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FEchoesCharacter_Statics::NewProp_AccountId = { "AccountId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesCharacter, AccountId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AccountId_MetaData), NewProp_AccountId_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FEchoesCharacter_Statics::NewProp_WalletBalance = { "WalletBalance", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesCharacter, WalletBalance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WalletBalance_MetaData), NewProp_WalletBalance_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FEchoesCharacter_Statics::NewProp_Credits = { "Credits", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesCharacter, Credits), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Credits_MetaData), NewProp_Credits_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FEchoesCharacter_Statics::NewProp_ISK = { "ISK", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesCharacter, ISK), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ISK_MetaData), NewProp_ISK_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FEchoesCharacter_Statics::NewProp_SecurityStatus = { "SecurityStatus", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesCharacter, SecurityStatus), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SecurityStatus_MetaData), NewProp_SecurityStatus_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FEchoesCharacter_Statics::NewProp_CurrentShipId = { "CurrentShipId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesCharacter, CurrentShipId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentShipId_MetaData), NewProp_CurrentShipId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FEchoesCharacter_Statics::NewProp_CorporationId = { "CorporationId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesCharacter, CorporationId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CorporationId_MetaData), NewProp_CorporationId_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FEchoesCharacter_Statics::NewProp_RaceId = { "RaceId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesCharacter, RaceId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RaceId_MetaData), NewProp_RaceId_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FEchoesCharacter_Statics::NewProp_TotalSkillPoints = { "TotalSkillPoints", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesCharacter, TotalSkillPoints), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalSkillPoints_MetaData), NewProp_TotalSkillPoints_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FEchoesCharacter_Statics::NewProp_ExperiencePoints = { "ExperiencePoints", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesCharacter, ExperiencePoints), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExperiencePoints_MetaData), NewProp_ExperiencePoints_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FEchoesCharacter_Statics::NewProp_UnallocatedSkillPoints = { "UnallocatedSkillPoints", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesCharacter, UnallocatedSkillPoints), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UnallocatedSkillPoints_MetaData), NewProp_UnallocatedSkillPoints_MetaData) };
void Z_Construct_UScriptStruct_FEchoesCharacter_Statics::NewProp_IsOnline_SetBit(void* Obj)
{
	((FEchoesCharacter*)Obj)->IsOnline = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FEchoesCharacter_Statics::NewProp_IsOnline = { "IsOnline", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FEchoesCharacter), &Z_Construct_UScriptStruct_FEchoesCharacter_Statics::NewProp_IsOnline_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IsOnline_MetaData), NewProp_IsOnline_MetaData) };
void Z_Construct_UScriptStruct_FEchoesCharacter_Statics::NewProp_IsDocked_SetBit(void* Obj)
{
	((FEchoesCharacter*)Obj)->IsDocked = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FEchoesCharacter_Statics::NewProp_IsDocked = { "IsDocked", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FEchoesCharacter), &Z_Construct_UScriptStruct_FEchoesCharacter_Statics::NewProp_IsDocked_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IsDocked_MetaData), NewProp_IsDocked_MetaData) };
void Z_Construct_UScriptStruct_FEchoesCharacter_Statics::NewProp_InWarp_SetBit(void* Obj)
{
	((FEchoesCharacter*)Obj)->InWarp = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FEchoesCharacter_Statics::NewProp_InWarp = { "InWarp", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FEchoesCharacter), &Z_Construct_UScriptStruct_FEchoesCharacter_Statics::NewProp_InWarp_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InWarp_MetaData), NewProp_InWarp_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FEchoesCharacter_Statics::NewProp_LastLogin = { "LastLogin", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesCharacter, LastLogin), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LastLogin_MetaData), NewProp_LastLogin_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FEchoesCharacter_Statics::NewProp_PortraitURL = { "PortraitURL", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesCharacter, PortraitURL), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PortraitURL_MetaData), NewProp_PortraitURL_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FEchoesCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesCharacter_Statics::NewProp_CharacterId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesCharacter_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesCharacter_Statics::NewProp_AccountId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesCharacter_Statics::NewProp_WalletBalance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesCharacter_Statics::NewProp_Credits,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesCharacter_Statics::NewProp_ISK,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesCharacter_Statics::NewProp_SecurityStatus,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesCharacter_Statics::NewProp_CurrentShipId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesCharacter_Statics::NewProp_CorporationId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesCharacter_Statics::NewProp_RaceId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesCharacter_Statics::NewProp_TotalSkillPoints,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesCharacter_Statics::NewProp_ExperiencePoints,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesCharacter_Statics::NewProp_UnallocatedSkillPoints,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesCharacter_Statics::NewProp_IsOnline,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesCharacter_Statics::NewProp_IsDocked,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesCharacter_Statics::NewProp_InWarp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesCharacter_Statics::NewProp_LastLogin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesCharacter_Statics::NewProp_PortraitURL,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEchoesCharacter_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FEchoesCharacter_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"EchoesCharacter",
	Z_Construct_UScriptStruct_FEchoesCharacter_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEchoesCharacter_Statics::PropPointers),
	sizeof(FEchoesCharacter),
	alignof(FEchoesCharacter),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEchoesCharacter_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FEchoesCharacter_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FEchoesCharacter()
{
	if (!Z_Registration_Info_UScriptStruct_FEchoesCharacter.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FEchoesCharacter.InnerSingleton, Z_Construct_UScriptStruct_FEchoesCharacter_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FEchoesCharacter.InnerSingleton;
}
// ********** End ScriptStruct FEchoesCharacter ****************************************************

// ********** Begin Delegate FOnCharacterDataReceived **********************************************
struct Z_Construct_UDelegateFunction_Echoes_OnCharacterDataReceived__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnCharacterDataReceived_Parms
	{
		FEchoesCharacter CharacterData;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesIdentitySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_CharacterData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_Echoes_OnCharacterDataReceived__DelegateSignature_Statics::NewProp_CharacterData = { "CharacterData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnCharacterDataReceived_Parms, CharacterData), Z_Construct_UScriptStruct_FEchoesCharacter, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterData_MetaData), NewProp_CharacterData_MetaData) }; // 65035307
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnCharacterDataReceived__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnCharacterDataReceived__DelegateSignature_Statics::NewProp_CharacterData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnCharacterDataReceived__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnCharacterDataReceived__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnCharacterDataReceived__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnCharacterDataReceived__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnCharacterDataReceived__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnCharacterDataReceived__DelegateSignature_Statics::_Script_Echoes_eventOnCharacterDataReceived_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00520000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnCharacterDataReceived__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnCharacterDataReceived__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnCharacterDataReceived__DelegateSignature_Statics::_Script_Echoes_eventOnCharacterDataReceived_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnCharacterDataReceived__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnCharacterDataReceived__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnCharacterDataReceived_DelegateWrapper(const FScriptDelegate& OnCharacterDataReceived, FEchoesCharacter const& CharacterData)
{
	struct _Script_Echoes_eventOnCharacterDataReceived_Parms
	{
		FEchoesCharacter CharacterData;
	};
	_Script_Echoes_eventOnCharacterDataReceived_Parms Parms;
	Parms.CharacterData=CharacterData;
	OnCharacterDataReceived.ProcessDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnCharacterDataReceived ************************************************

// ********** Begin Delegate FOnCharacterDataFailure ***********************************************
struct Z_Construct_UDelegateFunction_Echoes_OnCharacterDataFailure__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnCharacterDataFailure_Parms
	{
		FString ErrorMessage;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesIdentitySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_Echoes_OnCharacterDataFailure__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnCharacterDataFailure_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ErrorMessage_MetaData), NewProp_ErrorMessage_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnCharacterDataFailure__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnCharacterDataFailure__DelegateSignature_Statics::NewProp_ErrorMessage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnCharacterDataFailure__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnCharacterDataFailure__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnCharacterDataFailure__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnCharacterDataFailure__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnCharacterDataFailure__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnCharacterDataFailure__DelegateSignature_Statics::_Script_Echoes_eventOnCharacterDataFailure_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnCharacterDataFailure__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnCharacterDataFailure__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnCharacterDataFailure__DelegateSignature_Statics::_Script_Echoes_eventOnCharacterDataFailure_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnCharacterDataFailure__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnCharacterDataFailure__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnCharacterDataFailure_DelegateWrapper(const FScriptDelegate& OnCharacterDataFailure, const FString& ErrorMessage)
{
	struct _Script_Echoes_eventOnCharacterDataFailure_Parms
	{
		FString ErrorMessage;
	};
	_Script_Echoes_eventOnCharacterDataFailure_Parms Parms;
	Parms.ErrorMessage=ErrorMessage;
	OnCharacterDataFailure.ProcessDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnCharacterDataFailure *************************************************

// ********** Begin Delegate FOnCharacterSelected **************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnCharacterSelected__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesIdentitySubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnCharacterSelected__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnCharacterSelected__DelegateSignature", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnCharacterSelected__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnCharacterSelected__DelegateSignature_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UDelegateFunction_Echoes_OnCharacterSelected__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnCharacterSelected__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnCharacterSelected_DelegateWrapper(const FMulticastScriptDelegate& OnCharacterSelected)
{
	OnCharacterSelected.ProcessMulticastDelegate<UObject>(NULL);
}
// ********** End Delegate FOnCharacterSelected ****************************************************

// ********** Begin Delegate FOnIdentityCharacterCreated *******************************************
struct Z_Construct_UDelegateFunction_Echoes_OnIdentityCharacterCreated__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnIdentityCharacterCreated_Parms
	{
		FEchoesCharacter CharacterData;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesIdentitySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_CharacterData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_Echoes_OnIdentityCharacterCreated__DelegateSignature_Statics::NewProp_CharacterData = { "CharacterData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnIdentityCharacterCreated_Parms, CharacterData), Z_Construct_UScriptStruct_FEchoesCharacter, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterData_MetaData), NewProp_CharacterData_MetaData) }; // 65035307
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnIdentityCharacterCreated__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnIdentityCharacterCreated__DelegateSignature_Statics::NewProp_CharacterData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnIdentityCharacterCreated__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnIdentityCharacterCreated__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnIdentityCharacterCreated__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnIdentityCharacterCreated__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnIdentityCharacterCreated__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnIdentityCharacterCreated__DelegateSignature_Statics::_Script_Echoes_eventOnIdentityCharacterCreated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00520000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnIdentityCharacterCreated__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnIdentityCharacterCreated__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnIdentityCharacterCreated__DelegateSignature_Statics::_Script_Echoes_eventOnIdentityCharacterCreated_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnIdentityCharacterCreated__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnIdentityCharacterCreated__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnIdentityCharacterCreated_DelegateWrapper(const FScriptDelegate& OnIdentityCharacterCreated, FEchoesCharacter const& CharacterData)
{
	struct _Script_Echoes_eventOnIdentityCharacterCreated_Parms
	{
		FEchoesCharacter CharacterData;
	};
	_Script_Echoes_eventOnIdentityCharacterCreated_Parms Parms;
	Parms.CharacterData=CharacterData;
	OnIdentityCharacterCreated.ProcessDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnIdentityCharacterCreated *********************************************

// ********** Begin Class UEchoesIdentitySubsystem Function Identity_ClearSelection ****************
struct Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_ClearSelection_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Identity" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Clear selected character (logout)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesIdentitySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Clear selected character (logout)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_ClearSelection_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesIdentitySubsystem, nullptr, "Identity_ClearSelection", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_ClearSelection_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_ClearSelection_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_ClearSelection()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_ClearSelection_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesIdentitySubsystem::execIdentity_ClearSelection)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Identity_ClearSelection();
	P_NATIVE_END;
}
// ********** End Class UEchoesIdentitySubsystem Function Identity_ClearSelection ******************

// ********** Begin Class UEchoesIdentitySubsystem Function Identity_FetchCharacter ****************
struct Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_FetchCharacter_Statics
{
	struct EchoesIdentitySubsystem_eventIdentity_FetchCharacter_Parms
	{
		FScriptDelegate OnSuccess;
		FScriptDelegate OnFailure;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Identity" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Fetch current character data from backend\n\x09 * Sends HTTP GET to /api/character/me with JWT token\n\x09 * \n\x09 * @param OnSuccess - Callback with character data\n\x09 * @param OnFailure - Callback on request failure\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesIdentitySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fetch current character data from backend\nSends HTTP GET to /api/character/me with JWT token\n\n@param OnSuccess - Callback with character data\n@param OnFailure - Callback on request failure" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnSuccess;
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnFailure;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_FetchCharacter_Statics::NewProp_OnSuccess = { "OnSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesIdentitySubsystem_eventIdentity_FetchCharacter_Parms, OnSuccess), Z_Construct_UDelegateFunction_Echoes_OnCharacterDataReceived__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 1680251315
const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_FetchCharacter_Statics::NewProp_OnFailure = { "OnFailure", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesIdentitySubsystem_eventIdentity_FetchCharacter_Parms, OnFailure), Z_Construct_UDelegateFunction_Echoes_OnCharacterDataFailure__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 906501422
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_FetchCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_FetchCharacter_Statics::NewProp_OnSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_FetchCharacter_Statics::NewProp_OnFailure,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_FetchCharacter_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_FetchCharacter_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesIdentitySubsystem, nullptr, "Identity_FetchCharacter", Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_FetchCharacter_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_FetchCharacter_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_FetchCharacter_Statics::EchoesIdentitySubsystem_eventIdentity_FetchCharacter_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_FetchCharacter_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_FetchCharacter_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_FetchCharacter_Statics::EchoesIdentitySubsystem_eventIdentity_FetchCharacter_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_FetchCharacter()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_FetchCharacter_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesIdentitySubsystem::execIdentity_FetchCharacter)
{
	P_GET_PROPERTY(FDelegateProperty,Z_Param_OnSuccess);
	P_GET_PROPERTY(FDelegateProperty,Z_Param_OnFailure);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Identity_FetchCharacter(FOnCharacterDataReceived(Z_Param_OnSuccess),FOnCharacterDataFailure(Z_Param_OnFailure));
	P_NATIVE_END;
}
// ********** End Class UEchoesIdentitySubsystem Function Identity_FetchCharacter ******************

// ********** Begin Class UEchoesIdentitySubsystem Function Identity_GetSelectedCharacter **********
struct Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_GetSelectedCharacter_Statics
{
	struct EchoesIdentitySubsystem_eventIdentity_GetSelectedCharacter_Parms
	{
		FEchoesCharacter ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Identity" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get currently selected character data\n\x09 * \n\x09 * @return Selected character data\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesIdentitySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get currently selected character data\n\n@return Selected character data" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_GetSelectedCharacter_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesIdentitySubsystem_eventIdentity_GetSelectedCharacter_Parms, ReturnValue), Z_Construct_UScriptStruct_FEchoesCharacter, METADATA_PARAMS(0, nullptr) }; // 65035307
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_GetSelectedCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_GetSelectedCharacter_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_GetSelectedCharacter_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_GetSelectedCharacter_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesIdentitySubsystem, nullptr, "Identity_GetSelectedCharacter", Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_GetSelectedCharacter_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_GetSelectedCharacter_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_GetSelectedCharacter_Statics::EchoesIdentitySubsystem_eventIdentity_GetSelectedCharacter_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_GetSelectedCharacter_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_GetSelectedCharacter_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_GetSelectedCharacter_Statics::EchoesIdentitySubsystem_eventIdentity_GetSelectedCharacter_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_GetSelectedCharacter()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_GetSelectedCharacter_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesIdentitySubsystem::execIdentity_GetSelectedCharacter)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FEchoesCharacter*)Z_Param__Result=P_THIS->Identity_GetSelectedCharacter();
	P_NATIVE_END;
}
// ********** End Class UEchoesIdentitySubsystem Function Identity_GetSelectedCharacter ************

// ********** Begin Class UEchoesIdentitySubsystem Function Identity_GetSelectedCharacterId ********
struct Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_GetSelectedCharacterId_Statics
{
	struct EchoesIdentitySubsystem_eventIdentity_GetSelectedCharacterId_Parms
	{
		FGuid ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Identity" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get selected character ID\n\x09 * \n\x09 * @return Selected character GUID\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesIdentitySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get selected character ID\n\n@return Selected character GUID" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_GetSelectedCharacterId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesIdentitySubsystem_eventIdentity_GetSelectedCharacterId_Parms, ReturnValue), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_GetSelectedCharacterId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_GetSelectedCharacterId_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_GetSelectedCharacterId_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_GetSelectedCharacterId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesIdentitySubsystem, nullptr, "Identity_GetSelectedCharacterId", Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_GetSelectedCharacterId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_GetSelectedCharacterId_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_GetSelectedCharacterId_Statics::EchoesIdentitySubsystem_eventIdentity_GetSelectedCharacterId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_GetSelectedCharacterId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_GetSelectedCharacterId_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_GetSelectedCharacterId_Statics::EchoesIdentitySubsystem_eventIdentity_GetSelectedCharacterId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_GetSelectedCharacterId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_GetSelectedCharacterId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesIdentitySubsystem::execIdentity_GetSelectedCharacterId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGuid*)Z_Param__Result=P_THIS->Identity_GetSelectedCharacterId();
	P_NATIVE_END;
}
// ********** End Class UEchoesIdentitySubsystem Function Identity_GetSelectedCharacterId **********

// ********** Begin Class UEchoesIdentitySubsystem Function Identity_HasSelectedCharacter **********
struct Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_HasSelectedCharacter_Statics
{
	struct EchoesIdentitySubsystem_eventIdentity_HasSelectedCharacter_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Identity" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if a character is selected\n\x09 * \n\x09 * @return True if character is selected\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesIdentitySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if a character is selected\n\n@return True if character is selected" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_HasSelectedCharacter_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((EchoesIdentitySubsystem_eventIdentity_HasSelectedCharacter_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_HasSelectedCharacter_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EchoesIdentitySubsystem_eventIdentity_HasSelectedCharacter_Parms), &Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_HasSelectedCharacter_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_HasSelectedCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_HasSelectedCharacter_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_HasSelectedCharacter_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_HasSelectedCharacter_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesIdentitySubsystem, nullptr, "Identity_HasSelectedCharacter", Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_HasSelectedCharacter_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_HasSelectedCharacter_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_HasSelectedCharacter_Statics::EchoesIdentitySubsystem_eventIdentity_HasSelectedCharacter_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_HasSelectedCharacter_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_HasSelectedCharacter_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_HasSelectedCharacter_Statics::EchoesIdentitySubsystem_eventIdentity_HasSelectedCharacter_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_HasSelectedCharacter()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_HasSelectedCharacter_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesIdentitySubsystem::execIdentity_HasSelectedCharacter)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->Identity_HasSelectedCharacter();
	P_NATIVE_END;
}
// ********** End Class UEchoesIdentitySubsystem Function Identity_HasSelectedCharacter ************

// ********** Begin Class UEchoesIdentitySubsystem Function Identity_SelectCharacter ***************
struct Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_SelectCharacter_Statics
{
	struct EchoesIdentitySubsystem_eventIdentity_SelectCharacter_Parms
	{
		FGuid CharacterId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Identity" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Select a character and notify system\n\x09 * Saves selected character ID for future operations\n\x09 * Broadcasts OnCharacterSelected delegate\n\x09 * \n\x09 * @param CharacterId - Character to select\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesIdentitySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Select a character and notify system\nSaves selected character ID for future operations\nBroadcasts OnCharacterSelected delegate\n\n@param CharacterId - Character to select" },
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
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_SelectCharacter_Statics::NewProp_CharacterId = { "CharacterId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesIdentitySubsystem_eventIdentity_SelectCharacter_Parms, CharacterId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterId_MetaData), NewProp_CharacterId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_SelectCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_SelectCharacter_Statics::NewProp_CharacterId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_SelectCharacter_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_SelectCharacter_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesIdentitySubsystem, nullptr, "Identity_SelectCharacter", Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_SelectCharacter_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_SelectCharacter_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_SelectCharacter_Statics::EchoesIdentitySubsystem_eventIdentity_SelectCharacter_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_SelectCharacter_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_SelectCharacter_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_SelectCharacter_Statics::EchoesIdentitySubsystem_eventIdentity_SelectCharacter_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_SelectCharacter()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_SelectCharacter_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesIdentitySubsystem::execIdentity_SelectCharacter)
{
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_CharacterId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Identity_SelectCharacter(Z_Param_Out_CharacterId);
	P_NATIVE_END;
}
// ********** End Class UEchoesIdentitySubsystem Function Identity_SelectCharacter *****************

// ********** Begin Class UEchoesIdentitySubsystem Function UI_CreateCharacter *********************
struct Z_Construct_UFunction_UEchoesIdentitySubsystem_UI_CreateCharacter_Statics
{
	struct EchoesIdentitySubsystem_eventUI_CreateCharacter_Parms
	{
		FString CharacterName;
		FString Race;
		int32 PortraitId;
		FScriptDelegate OnSuccess;
		FScriptDelegate OnFailure;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Identity|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * UI wrapper: Create a new character\n\x09 * Sends HTTP POST to /api/character with JWT token\n\x09 * \n\x09 * @param CharacterName - Name for new character\n\x09 * @param Race - Race selection (Caldari, Gallente, Amarr, Minmatar)\n\x09 * @param PortraitId - Portrait ID for character\n\x09 * @param OnSuccess - Callback with created character data\n\x09 * @param OnFailure - Callback on creation failure\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesIdentitySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UI wrapper: Create a new character\nSends HTTP POST to /api/character with JWT token\n\n@param CharacterName - Name for new character\n@param Race - Race selection (Caldari, Gallente, Amarr, Minmatar)\n@param PortraitId - Portrait ID for character\n@param OnSuccess - Callback with created character data\n@param OnFailure - Callback on creation failure" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Race_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_CharacterName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Race;
	static const UECodeGen_Private::FIntPropertyParams NewProp_PortraitId;
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnSuccess;
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnFailure;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEchoesIdentitySubsystem_UI_CreateCharacter_Statics::NewProp_CharacterName = { "CharacterName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesIdentitySubsystem_eventUI_CreateCharacter_Parms, CharacterName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterName_MetaData), NewProp_CharacterName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEchoesIdentitySubsystem_UI_CreateCharacter_Statics::NewProp_Race = { "Race", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesIdentitySubsystem_eventUI_CreateCharacter_Parms, Race), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Race_MetaData), NewProp_Race_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UEchoesIdentitySubsystem_UI_CreateCharacter_Statics::NewProp_PortraitId = { "PortraitId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesIdentitySubsystem_eventUI_CreateCharacter_Parms, PortraitId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UEchoesIdentitySubsystem_UI_CreateCharacter_Statics::NewProp_OnSuccess = { "OnSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesIdentitySubsystem_eventUI_CreateCharacter_Parms, OnSuccess), Z_Construct_UDelegateFunction_Echoes_OnIdentityCharacterCreated__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 3161926090
const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UEchoesIdentitySubsystem_UI_CreateCharacter_Statics::NewProp_OnFailure = { "OnFailure", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesIdentitySubsystem_eventUI_CreateCharacter_Parms, OnFailure), Z_Construct_UDelegateFunction_Echoes_OnCharacterDataFailure__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 906501422
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesIdentitySubsystem_UI_CreateCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesIdentitySubsystem_UI_CreateCharacter_Statics::NewProp_CharacterName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesIdentitySubsystem_UI_CreateCharacter_Statics::NewProp_Race,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesIdentitySubsystem_UI_CreateCharacter_Statics::NewProp_PortraitId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesIdentitySubsystem_UI_CreateCharacter_Statics::NewProp_OnSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesIdentitySubsystem_UI_CreateCharacter_Statics::NewProp_OnFailure,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesIdentitySubsystem_UI_CreateCharacter_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesIdentitySubsystem_UI_CreateCharacter_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesIdentitySubsystem, nullptr, "UI_CreateCharacter", Z_Construct_UFunction_UEchoesIdentitySubsystem_UI_CreateCharacter_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesIdentitySubsystem_UI_CreateCharacter_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesIdentitySubsystem_UI_CreateCharacter_Statics::EchoesIdentitySubsystem_eventUI_CreateCharacter_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesIdentitySubsystem_UI_CreateCharacter_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesIdentitySubsystem_UI_CreateCharacter_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesIdentitySubsystem_UI_CreateCharacter_Statics::EchoesIdentitySubsystem_eventUI_CreateCharacter_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesIdentitySubsystem_UI_CreateCharacter()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesIdentitySubsystem_UI_CreateCharacter_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesIdentitySubsystem::execUI_CreateCharacter)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_CharacterName);
	P_GET_PROPERTY(FStrProperty,Z_Param_Race);
	P_GET_PROPERTY(FIntProperty,Z_Param_PortraitId);
	P_GET_PROPERTY(FDelegateProperty,Z_Param_OnSuccess);
	P_GET_PROPERTY(FDelegateProperty,Z_Param_OnFailure);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UI_CreateCharacter(Z_Param_CharacterName,Z_Param_Race,Z_Param_PortraitId,FOnIdentityCharacterCreated(Z_Param_OnSuccess),FOnCharacterDataFailure(Z_Param_OnFailure));
	P_NATIVE_END;
}
// ********** End Class UEchoesIdentitySubsystem Function UI_CreateCharacter ***********************

// ********** Begin Class UEchoesIdentitySubsystem *************************************************
void UEchoesIdentitySubsystem::StaticRegisterNativesUEchoesIdentitySubsystem()
{
	UClass* Class = UEchoesIdentitySubsystem::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "Identity_ClearSelection", &UEchoesIdentitySubsystem::execIdentity_ClearSelection },
		{ "Identity_FetchCharacter", &UEchoesIdentitySubsystem::execIdentity_FetchCharacter },
		{ "Identity_GetSelectedCharacter", &UEchoesIdentitySubsystem::execIdentity_GetSelectedCharacter },
		{ "Identity_GetSelectedCharacterId", &UEchoesIdentitySubsystem::execIdentity_GetSelectedCharacterId },
		{ "Identity_HasSelectedCharacter", &UEchoesIdentitySubsystem::execIdentity_HasSelectedCharacter },
		{ "Identity_SelectCharacter", &UEchoesIdentitySubsystem::execIdentity_SelectCharacter },
		{ "UI_CreateCharacter", &UEchoesIdentitySubsystem::execUI_CreateCharacter },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UEchoesIdentitySubsystem;
UClass* UEchoesIdentitySubsystem::GetPrivateStaticClass()
{
	using TClass = UEchoesIdentitySubsystem;
	if (!Z_Registration_Info_UClass_UEchoesIdentitySubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesIdentitySubsystem"),
			Z_Registration_Info_UClass_UEchoesIdentitySubsystem.InnerSingleton,
			StaticRegisterNativesUEchoesIdentitySubsystem,
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
	return Z_Registration_Info_UClass_UEchoesIdentitySubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UEchoesIdentitySubsystem_NoRegister()
{
	return UEchoesIdentitySubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UEchoesIdentitySubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * UEchoesIdentitySubsystem\n * \n * Character management subsystem for Echoes MMO\n * Handles character selection and data retrieval\n * \n * Architecture:\n * - GameInstanceSubsystem: Persists across level transitions\n * - Requires valid JWT token from UEchoesAuthSubsystem\n * - Communicates with ASP.NET Core backend\n * - Provides character data to UI and gameplay systems\n * \n * Naming Conventions:\n * - Identity_ prefix: Character management functions\n * - Common_ prefix: Shared data structures\n * - ServerRPC_ prefix: Server-side notifications\n */" },
#endif
		{ "IncludePath", "Core/Common/Networking/EchoesIdentitySubsystem.h" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesIdentitySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UEchoesIdentitySubsystem\n\nCharacter management subsystem for Echoes MMO\nHandles character selection and data retrieval\n\nArchitecture:\n- GameInstanceSubsystem: Persists across level transitions\n- Requires valid JWT token from UEchoesAuthSubsystem\n- Communicates with ASP.NET Core backend\n- Provides character data to UI and gameplay systems\n\nNaming Conventions:\n- Identity_ prefix: Character management functions\n- Common_ prefix: Shared data structures\n- ServerRPC_ prefix: Server-side notifications" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnCharacterSelected_MetaData[] = {
		{ "Category", "Echoes|Identity" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Broadcast when character is selected */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesIdentitySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Broadcast when character is selected" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectedCharacter_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Currently selected character */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesIdentitySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Currently selected character" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCharacterSelected;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SelectedCharacter;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_ClearSelection, "Identity_ClearSelection" }, // 3967232812
		{ &Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_FetchCharacter, "Identity_FetchCharacter" }, // 4144290907
		{ &Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_GetSelectedCharacter, "Identity_GetSelectedCharacter" }, // 2129426112
		{ &Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_GetSelectedCharacterId, "Identity_GetSelectedCharacterId" }, // 67363804
		{ &Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_HasSelectedCharacter, "Identity_HasSelectedCharacter" }, // 97103536
		{ &Z_Construct_UFunction_UEchoesIdentitySubsystem_Identity_SelectCharacter, "Identity_SelectCharacter" }, // 1684475910
		{ &Z_Construct_UFunction_UEchoesIdentitySubsystem_UI_CreateCharacter, "UI_CreateCharacter" }, // 1054530951
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEchoesIdentitySubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEchoesIdentitySubsystem_Statics::NewProp_OnCharacterSelected = { "OnCharacterSelected", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesIdentitySubsystem, OnCharacterSelected), Z_Construct_UDelegateFunction_Echoes_OnCharacterSelected__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnCharacterSelected_MetaData), NewProp_OnCharacterSelected_MetaData) }; // 4053191214
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEchoesIdentitySubsystem_Statics::NewProp_SelectedCharacter = { "SelectedCharacter", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesIdentitySubsystem, SelectedCharacter), Z_Construct_UScriptStruct_FEchoesCharacter, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectedCharacter_MetaData), NewProp_SelectedCharacter_MetaData) }; // 65035307
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEchoesIdentitySubsystem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesIdentitySubsystem_Statics::NewProp_OnCharacterSelected,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesIdentitySubsystem_Statics::NewProp_SelectedCharacter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesIdentitySubsystem_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UEchoesIdentitySubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesIdentitySubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEchoesIdentitySubsystem_Statics::ClassParams = {
	&UEchoesIdentitySubsystem::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UEchoesIdentitySubsystem_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesIdentitySubsystem_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesIdentitySubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UEchoesIdentitySubsystem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEchoesIdentitySubsystem()
{
	if (!Z_Registration_Info_UClass_UEchoesIdentitySubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEchoesIdentitySubsystem.OuterSingleton, Z_Construct_UClass_UEchoesIdentitySubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEchoesIdentitySubsystem.OuterSingleton;
}
UEchoesIdentitySubsystem::UEchoesIdentitySubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UEchoesIdentitySubsystem);
UEchoesIdentitySubsystem::~UEchoesIdentitySubsystem() {}
// ********** End Class UEchoesIdentitySubsystem ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesIdentitySubsystem_h__Script_Echoes_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FEchoesCharacter::StaticStruct, Z_Construct_UScriptStruct_FEchoesCharacter_Statics::NewStructOps, TEXT("EchoesCharacter"), &Z_Registration_Info_UScriptStruct_FEchoesCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FEchoesCharacter), 65035307U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEchoesIdentitySubsystem, UEchoesIdentitySubsystem::StaticClass, TEXT("UEchoesIdentitySubsystem"), &Z_Registration_Info_UClass_UEchoesIdentitySubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEchoesIdentitySubsystem), 3182227684U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesIdentitySubsystem_h__Script_Echoes_708256702(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesIdentitySubsystem_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesIdentitySubsystem_h__Script_Echoes_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesIdentitySubsystem_h__Script_Echoes_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesIdentitySubsystem_h__Script_Echoes_Statics::ScriptStructInfo),
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
