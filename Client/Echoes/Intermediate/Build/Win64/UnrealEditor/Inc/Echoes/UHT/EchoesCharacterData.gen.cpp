// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EchoesCharacterData.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesCharacterData() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FDateTime();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FCharacterData();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

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
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesCharacterData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Character data structure (mirrors C# CharacterDataDto)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterId_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesCharacterData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesCharacterData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AccountId_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesCharacterData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WalletBalance_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesCharacterData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Credits_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesCharacterData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SecurityStatus_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesCharacterData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentShipId_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesCharacterData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CorporationId_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesCharacterData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RaceId_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesCharacterData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalSkillPoints_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesCharacterData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExperiencePoints_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesCharacterData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UnallocatedSkillPoints_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesCharacterData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IsOnline_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesCharacterData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IsDocked_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesCharacterData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InWarp_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesCharacterData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LastLogin_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesCharacterData.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_CharacterId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AccountId;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_WalletBalance;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_Credits;
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
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_Credits = { "Credits", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterData, Credits), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Credits_MetaData), NewProp_Credits_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_SecurityStatus = { "SecurityStatus", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterData, SecurityStatus), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SecurityStatus_MetaData), NewProp_SecurityStatus_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_CurrentShipId = { "CurrentShipId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterData, CurrentShipId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentShipId_MetaData), NewProp_CurrentShipId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_CorporationId = { "CorporationId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterData, CorporationId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CorporationId_MetaData), NewProp_CorporationId_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_RaceId = { "RaceId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterData, RaceId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RaceId_MetaData), NewProp_RaceId_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_TotalSkillPoints = { "TotalSkillPoints", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterData, TotalSkillPoints), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalSkillPoints_MetaData), NewProp_TotalSkillPoints_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_ExperiencePoints = { "ExperiencePoints", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterData, ExperiencePoints), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExperiencePoints_MetaData), NewProp_ExperiencePoints_MetaData) };
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
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_Credits,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_SecurityStatus,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_CurrentShipId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_CorporationId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_RaceId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_TotalSkillPoints,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_ExperiencePoints,
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

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesCharacterData_h__Script_Echoes_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FCharacterData::StaticStruct, Z_Construct_UScriptStruct_FCharacterData_Statics::NewStructOps, TEXT("CharacterData"), &Z_Registration_Info_UScriptStruct_FCharacterData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FCharacterData), 1874857763U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesCharacterData_h__Script_Echoes_2000845459(TEXT("/Script/Echoes"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesCharacterData_h__Script_Echoes_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesCharacterData_h__Script_Echoes_Statics::ScriptStructInfo),
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
