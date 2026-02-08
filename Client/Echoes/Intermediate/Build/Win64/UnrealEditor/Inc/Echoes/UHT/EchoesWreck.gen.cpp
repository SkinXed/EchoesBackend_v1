// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EchoesWreck.h"
#include "EchoesKillmailStructures.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesWreck() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ECHOES_API UClass* Z_Construct_UClass_AEchoesWreck();
ECHOES_API UClass* Z_Construct_UClass_AEchoesWreck_NoRegister();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FKillmailItem();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FWreckAccessEntry();
ENGINE_API UClass* Z_Construct_UClass_AActor();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FWreckAccessEntry *************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FWreckAccessEntry;
class UScriptStruct* FWreckAccessEntry::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FWreckAccessEntry.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FWreckAccessEntry.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FWreckAccessEntry, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("WreckAccessEntry"));
	}
	return Z_Registration_Info_UScriptStruct_FWreckAccessEntry.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FWreckAccessEntry_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Loot access right entry */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EchoesWreck.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Loot access right entry" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterId_MetaData[] = {
		{ "Category", "Wreck" },
		{ "ModuleRelativePath", "Core/Common/Actor/EchoesWreck.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CorporationId_MetaData[] = {
		{ "Category", "Wreck" },
		{ "ModuleRelativePath", "Core/Common/Actor/EchoesWreck.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_CharacterId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CorporationId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FWreckAccessEntry>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FWreckAccessEntry_Statics::NewProp_CharacterId = { "CharacterId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWreckAccessEntry, CharacterId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterId_MetaData), NewProp_CharacterId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FWreckAccessEntry_Statics::NewProp_CorporationId = { "CorporationId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWreckAccessEntry, CorporationId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CorporationId_MetaData), NewProp_CorporationId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FWreckAccessEntry_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWreckAccessEntry_Statics::NewProp_CharacterId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWreckAccessEntry_Statics::NewProp_CorporationId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWreckAccessEntry_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FWreckAccessEntry_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"WreckAccessEntry",
	Z_Construct_UScriptStruct_FWreckAccessEntry_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWreckAccessEntry_Statics::PropPointers),
	sizeof(FWreckAccessEntry),
	alignof(FWreckAccessEntry),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWreckAccessEntry_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FWreckAccessEntry_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FWreckAccessEntry()
{
	if (!Z_Registration_Info_UScriptStruct_FWreckAccessEntry.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FWreckAccessEntry.InnerSingleton, Z_Construct_UScriptStruct_FWreckAccessEntry_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FWreckAccessEntry.InnerSingleton;
}
// ********** End ScriptStruct FWreckAccessEntry ***************************************************

// ********** Begin Class AEchoesWreck Function GetContents ****************************************
struct Z_Construct_UFunction_AEchoesWreck_GetContents_Statics
{
	struct EchoesWreck_eventGetContents_Parms
	{
		TArray<FKillmailItem> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Wreck" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ==================== Accessors ====================\n" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EchoesWreck.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "==================== Accessors ====================" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEchoesWreck_GetContents_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FKillmailItem, METADATA_PARAMS(0, nullptr) }; // 4119519826
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AEchoesWreck_GetContents_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesWreck_eventGetContents_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 4119519826
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesWreck_GetContents_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesWreck_GetContents_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesWreck_GetContents_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWreck_GetContents_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesWreck_GetContents_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesWreck, nullptr, "GetContents", Z_Construct_UFunction_AEchoesWreck_GetContents_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWreck_GetContents_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesWreck_GetContents_Statics::EchoesWreck_eventGetContents_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWreck_GetContents_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesWreck_GetContents_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesWreck_GetContents_Statics::EchoesWreck_eventGetContents_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesWreck_GetContents()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesWreck_GetContents_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesWreck::execGetContents)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FKillmailItem>*)Z_Param__Result=P_THIS->GetContents();
	P_NATIVE_END;
}
// ********** End Class AEchoesWreck Function GetContents ******************************************

// ********** Begin Class AEchoesWreck Function GetKillmailId **************************************
struct Z_Construct_UFunction_AEchoesWreck_GetKillmailId_Statics
{
	struct EchoesWreck_eventGetKillmailId_Parms
	{
		FGuid ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Wreck" },
		{ "ModuleRelativePath", "Core/Common/Actor/EchoesWreck.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEchoesWreck_GetKillmailId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesWreck_eventGetKillmailId_Parms, ReturnValue), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesWreck_GetKillmailId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesWreck_GetKillmailId_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWreck_GetKillmailId_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesWreck_GetKillmailId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesWreck, nullptr, "GetKillmailId", Z_Construct_UFunction_AEchoesWreck_GetKillmailId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWreck_GetKillmailId_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesWreck_GetKillmailId_Statics::EchoesWreck_eventGetKillmailId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWreck_GetKillmailId_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesWreck_GetKillmailId_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesWreck_GetKillmailId_Statics::EchoesWreck_eventGetKillmailId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesWreck_GetKillmailId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesWreck_GetKillmailId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesWreck::execGetKillmailId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGuid*)Z_Param__Result=P_THIS->GetKillmailId();
	P_NATIVE_END;
}
// ********** End Class AEchoesWreck Function GetKillmailId ****************************************

// ********** Begin Class AEchoesWreck Function IsEmpty ********************************************
struct Z_Construct_UFunction_AEchoesWreck_IsEmpty_Statics
{
	struct EchoesWreck_eventIsEmpty_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Wreck" },
		{ "ModuleRelativePath", "Core/Common/Actor/EchoesWreck.h" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_AEchoesWreck_IsEmpty_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((EchoesWreck_eventIsEmpty_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AEchoesWreck_IsEmpty_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EchoesWreck_eventIsEmpty_Parms), &Z_Construct_UFunction_AEchoesWreck_IsEmpty_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesWreck_IsEmpty_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesWreck_IsEmpty_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWreck_IsEmpty_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesWreck_IsEmpty_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesWreck, nullptr, "IsEmpty", Z_Construct_UFunction_AEchoesWreck_IsEmpty_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWreck_IsEmpty_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesWreck_IsEmpty_Statics::EchoesWreck_eventIsEmpty_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWreck_IsEmpty_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesWreck_IsEmpty_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesWreck_IsEmpty_Statics::EchoesWreck_eventIsEmpty_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesWreck_IsEmpty()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesWreck_IsEmpty_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesWreck::execIsEmpty)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsEmpty();
	P_NATIVE_END;
}
// ********** End Class AEchoesWreck Function IsEmpty **********************************************

// ********** Begin Class AEchoesWreck Function ServerOnly_HasLootRights ***************************
struct Z_Construct_UFunction_AEchoesWreck_ServerOnly_HasLootRights_Statics
{
	struct EchoesWreck_eventServerOnly_HasLootRights_Parms
	{
		FGuid CharacterId;
		FGuid CorporationId;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Wreck" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if a character has loot rights (participated in kill or is corpmate)\n\x09 * @param CharacterId - Character attempting to loot\n\x09 * @param CorporationId - Corporation of the character\n\x09 * @return True if can loot without Suspect flag\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EchoesWreck.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if a character has loot rights (participated in kill or is corpmate)\n@param CharacterId - Character attempting to loot\n@param CorporationId - Corporation of the character\n@return True if can loot without Suspect flag" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterId_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CorporationId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_CharacterId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CorporationId;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEchoesWreck_ServerOnly_HasLootRights_Statics::NewProp_CharacterId = { "CharacterId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesWreck_eventServerOnly_HasLootRights_Parms, CharacterId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterId_MetaData), NewProp_CharacterId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEchoesWreck_ServerOnly_HasLootRights_Statics::NewProp_CorporationId = { "CorporationId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesWreck_eventServerOnly_HasLootRights_Parms, CorporationId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CorporationId_MetaData), NewProp_CorporationId_MetaData) };
void Z_Construct_UFunction_AEchoesWreck_ServerOnly_HasLootRights_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((EchoesWreck_eventServerOnly_HasLootRights_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AEchoesWreck_ServerOnly_HasLootRights_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EchoesWreck_eventServerOnly_HasLootRights_Parms), &Z_Construct_UFunction_AEchoesWreck_ServerOnly_HasLootRights_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesWreck_ServerOnly_HasLootRights_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesWreck_ServerOnly_HasLootRights_Statics::NewProp_CharacterId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesWreck_ServerOnly_HasLootRights_Statics::NewProp_CorporationId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesWreck_ServerOnly_HasLootRights_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWreck_ServerOnly_HasLootRights_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesWreck_ServerOnly_HasLootRights_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesWreck, nullptr, "ServerOnly_HasLootRights", Z_Construct_UFunction_AEchoesWreck_ServerOnly_HasLootRights_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWreck_ServerOnly_HasLootRights_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesWreck_ServerOnly_HasLootRights_Statics::EchoesWreck_eventServerOnly_HasLootRights_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWreck_ServerOnly_HasLootRights_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesWreck_ServerOnly_HasLootRights_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesWreck_ServerOnly_HasLootRights_Statics::EchoesWreck_eventServerOnly_HasLootRights_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesWreck_ServerOnly_HasLootRights()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesWreck_ServerOnly_HasLootRights_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesWreck::execServerOnly_HasLootRights)
{
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_CharacterId);
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_CorporationId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ServerOnly_HasLootRights(Z_Param_Out_CharacterId,Z_Param_Out_CorporationId);
	P_NATIVE_END;
}
// ********** End Class AEchoesWreck Function ServerOnly_HasLootRights *****************************

// ********** Begin Class AEchoesWreck Function ServerOnly_InitializeWreck *************************
struct Z_Construct_UFunction_AEchoesWreck_ServerOnly_InitializeWreck_Statics
{
	struct EchoesWreck_eventServerOnly_InitializeWreck_Parms
	{
		TArray<FKillmailItem> InDroppedItems;
		TArray<FWreckAccessEntry> InAccessList;
		FGuid InKillmailId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Wreck" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Initialize wreck with loot from a killed ship\n\x09 * @param InDroppedItems - Items that survived the 50/50 roll\n\x09 * @param InAccessList - Characters/corps with loot rights\n\x09 * @param InKillmailId - Associated killmail for tracking\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EchoesWreck.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Initialize wreck with loot from a killed ship\n@param InDroppedItems - Items that survived the 50/50 roll\n@param InAccessList - Characters/corps with loot rights\n@param InKillmailId - Associated killmail for tracking" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InDroppedItems_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InAccessList_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InKillmailId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_InDroppedItems_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_InDroppedItems;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InAccessList_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_InAccessList;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InKillmailId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEchoesWreck_ServerOnly_InitializeWreck_Statics::NewProp_InDroppedItems_Inner = { "InDroppedItems", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FKillmailItem, METADATA_PARAMS(0, nullptr) }; // 4119519826
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AEchoesWreck_ServerOnly_InitializeWreck_Statics::NewProp_InDroppedItems = { "InDroppedItems", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesWreck_eventServerOnly_InitializeWreck_Parms, InDroppedItems), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InDroppedItems_MetaData), NewProp_InDroppedItems_MetaData) }; // 4119519826
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEchoesWreck_ServerOnly_InitializeWreck_Statics::NewProp_InAccessList_Inner = { "InAccessList", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FWreckAccessEntry, METADATA_PARAMS(0, nullptr) }; // 2373375999
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AEchoesWreck_ServerOnly_InitializeWreck_Statics::NewProp_InAccessList = { "InAccessList", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesWreck_eventServerOnly_InitializeWreck_Parms, InAccessList), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InAccessList_MetaData), NewProp_InAccessList_MetaData) }; // 2373375999
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEchoesWreck_ServerOnly_InitializeWreck_Statics::NewProp_InKillmailId = { "InKillmailId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesWreck_eventServerOnly_InitializeWreck_Parms, InKillmailId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InKillmailId_MetaData), NewProp_InKillmailId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesWreck_ServerOnly_InitializeWreck_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesWreck_ServerOnly_InitializeWreck_Statics::NewProp_InDroppedItems_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesWreck_ServerOnly_InitializeWreck_Statics::NewProp_InDroppedItems,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesWreck_ServerOnly_InitializeWreck_Statics::NewProp_InAccessList_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesWreck_ServerOnly_InitializeWreck_Statics::NewProp_InAccessList,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesWreck_ServerOnly_InitializeWreck_Statics::NewProp_InKillmailId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWreck_ServerOnly_InitializeWreck_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesWreck_ServerOnly_InitializeWreck_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesWreck, nullptr, "ServerOnly_InitializeWreck", Z_Construct_UFunction_AEchoesWreck_ServerOnly_InitializeWreck_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWreck_ServerOnly_InitializeWreck_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesWreck_ServerOnly_InitializeWreck_Statics::EchoesWreck_eventServerOnly_InitializeWreck_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWreck_ServerOnly_InitializeWreck_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesWreck_ServerOnly_InitializeWreck_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesWreck_ServerOnly_InitializeWreck_Statics::EchoesWreck_eventServerOnly_InitializeWreck_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesWreck_ServerOnly_InitializeWreck()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesWreck_ServerOnly_InitializeWreck_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesWreck::execServerOnly_InitializeWreck)
{
	P_GET_TARRAY_REF(FKillmailItem,Z_Param_Out_InDroppedItems);
	P_GET_TARRAY_REF(FWreckAccessEntry,Z_Param_Out_InAccessList);
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_InKillmailId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerOnly_InitializeWreck(Z_Param_Out_InDroppedItems,Z_Param_Out_InAccessList,Z_Param_Out_InKillmailId);
	P_NATIVE_END;
}
// ********** End Class AEchoesWreck Function ServerOnly_InitializeWreck ***************************

// ********** Begin Class AEchoesWreck Function ServerOnly_TakeItem ********************************
struct Z_Construct_UFunction_AEchoesWreck_ServerOnly_TakeItem_Statics
{
	struct EchoesWreck_eventServerOnly_TakeItem_Parms
	{
		int32 ItemTypeId;
		int32 Quantity;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Wreck" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Remove an item from the wreck (looted by a player)\n\x09 * @param ItemTypeId - Type of item to take\n\x09 * @param Quantity - Amount to take\n\x09 * @return True if item was successfully removed\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EchoesWreck.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Remove an item from the wreck (looted by a player)\n@param ItemTypeId - Type of item to take\n@param Quantity - Amount to take\n@return True if item was successfully removed" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ItemTypeId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Quantity;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AEchoesWreck_ServerOnly_TakeItem_Statics::NewProp_ItemTypeId = { "ItemTypeId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesWreck_eventServerOnly_TakeItem_Parms, ItemTypeId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AEchoesWreck_ServerOnly_TakeItem_Statics::NewProp_Quantity = { "Quantity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesWreck_eventServerOnly_TakeItem_Parms, Quantity), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AEchoesWreck_ServerOnly_TakeItem_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((EchoesWreck_eventServerOnly_TakeItem_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AEchoesWreck_ServerOnly_TakeItem_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EchoesWreck_eventServerOnly_TakeItem_Parms), &Z_Construct_UFunction_AEchoesWreck_ServerOnly_TakeItem_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesWreck_ServerOnly_TakeItem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesWreck_ServerOnly_TakeItem_Statics::NewProp_ItemTypeId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesWreck_ServerOnly_TakeItem_Statics::NewProp_Quantity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesWreck_ServerOnly_TakeItem_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWreck_ServerOnly_TakeItem_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesWreck_ServerOnly_TakeItem_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesWreck, nullptr, "ServerOnly_TakeItem", Z_Construct_UFunction_AEchoesWreck_ServerOnly_TakeItem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWreck_ServerOnly_TakeItem_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesWreck_ServerOnly_TakeItem_Statics::EchoesWreck_eventServerOnly_TakeItem_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesWreck_ServerOnly_TakeItem_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesWreck_ServerOnly_TakeItem_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesWreck_ServerOnly_TakeItem_Statics::EchoesWreck_eventServerOnly_TakeItem_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesWreck_ServerOnly_TakeItem()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesWreck_ServerOnly_TakeItem_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesWreck::execServerOnly_TakeItem)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_ItemTypeId);
	P_GET_PROPERTY(FIntProperty,Z_Param_Quantity);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ServerOnly_TakeItem(Z_Param_ItemTypeId,Z_Param_Quantity);
	P_NATIVE_END;
}
// ********** End Class AEchoesWreck Function ServerOnly_TakeItem **********************************

// ********** Begin Class AEchoesWreck *************************************************************
void AEchoesWreck::StaticRegisterNativesAEchoesWreck()
{
	UClass* Class = AEchoesWreck::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetContents", &AEchoesWreck::execGetContents },
		{ "GetKillmailId", &AEchoesWreck::execGetKillmailId },
		{ "IsEmpty", &AEchoesWreck::execIsEmpty },
		{ "ServerOnly_HasLootRights", &AEchoesWreck::execServerOnly_HasLootRights },
		{ "ServerOnly_InitializeWreck", &AEchoesWreck::execServerOnly_InitializeWreck },
		{ "ServerOnly_TakeItem", &AEchoesWreck::execServerOnly_TakeItem },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_AEchoesWreck;
UClass* AEchoesWreck::GetPrivateStaticClass()
{
	using TClass = AEchoesWreck;
	if (!Z_Registration_Info_UClass_AEchoesWreck.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesWreck"),
			Z_Registration_Info_UClass_AEchoesWreck.InnerSingleton,
			StaticRegisterNativesAEchoesWreck,
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
	return Z_Registration_Info_UClass_AEchoesWreck.InnerSingleton;
}
UClass* Z_Construct_UClass_AEchoesWreck_NoRegister()
{
	return AEchoesWreck::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AEchoesWreck_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * AEchoesWreck\n * \n * Wreck container actor spawned after ship destruction\n * Contains surviving items from the 50/50 drop roll\n * Implements \"loot rights\" \xe2\x80\x94 only kill participants (and corpmates)\n * can loot without getting Suspect flag\n * \n * Lifetime: Auto-despawns after WreckLifetimeSeconds (default: 2 hours)\n */" },
#endif
		{ "IncludePath", "Core/Common/Actor/EchoesWreck.h" },
		{ "ModuleRelativePath", "Core/Common/Actor/EchoesWreck.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "AEchoesWreck\n\nWreck container actor spawned after ship destruction\nContains surviving items from the 50/50 drop roll\nImplements \"loot rights\" \xe2\x80\x94 only kill participants (and corpmates)\ncan loot without getting Suspect flag\n\nLifetime: Auto-despawns after WreckLifetimeSeconds (default: 2 hours)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DroppedItems_MetaData[] = {
		{ "Category", "Wreck" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Items in the wreck (surviving loot) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EchoesWreck.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Items in the wreck (surviving loot)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AccessList_MetaData[] = {
		{ "Category", "Wreck" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Characters and corporations with loot rights */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EchoesWreck.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Characters and corporations with loot rights" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_KillmailId_MetaData[] = {
		{ "Category", "Wreck" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Associated killmail ID */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EchoesWreck.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Associated killmail ID" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WreckLifetimeSeconds_MetaData[] = {
		{ "Category", "Wreck|Config" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Wreck auto-despawn time (2 hours default) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EchoesWreck.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Wreck auto-despawn time (2 hours default)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_DroppedItems_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_DroppedItems;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AccessList_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_AccessList;
	static const UECodeGen_Private::FStructPropertyParams NewProp_KillmailId;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WreckLifetimeSeconds;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AEchoesWreck_GetContents, "GetContents" }, // 2718637764
		{ &Z_Construct_UFunction_AEchoesWreck_GetKillmailId, "GetKillmailId" }, // 2447157335
		{ &Z_Construct_UFunction_AEchoesWreck_IsEmpty, "IsEmpty" }, // 704780522
		{ &Z_Construct_UFunction_AEchoesWreck_ServerOnly_HasLootRights, "ServerOnly_HasLootRights" }, // 3660380306
		{ &Z_Construct_UFunction_AEchoesWreck_ServerOnly_InitializeWreck, "ServerOnly_InitializeWreck" }, // 1305032477
		{ &Z_Construct_UFunction_AEchoesWreck_ServerOnly_TakeItem, "ServerOnly_TakeItem" }, // 1013729097
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEchoesWreck>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AEchoesWreck_Statics::NewProp_DroppedItems_Inner = { "DroppedItems", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FKillmailItem, METADATA_PARAMS(0, nullptr) }; // 4119519826
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AEchoesWreck_Statics::NewProp_DroppedItems = { "DroppedItems", nullptr, (EPropertyFlags)0x0020080000000034, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesWreck, DroppedItems), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DroppedItems_MetaData), NewProp_DroppedItems_MetaData) }; // 4119519826
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AEchoesWreck_Statics::NewProp_AccessList_Inner = { "AccessList", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FWreckAccessEntry, METADATA_PARAMS(0, nullptr) }; // 2373375999
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AEchoesWreck_Statics::NewProp_AccessList = { "AccessList", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesWreck, AccessList), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AccessList_MetaData), NewProp_AccessList_MetaData) }; // 2373375999
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AEchoesWreck_Statics::NewProp_KillmailId = { "KillmailId", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesWreck, KillmailId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_KillmailId_MetaData), NewProp_KillmailId_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEchoesWreck_Statics::NewProp_WreckLifetimeSeconds = { "WreckLifetimeSeconds", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesWreck, WreckLifetimeSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WreckLifetimeSeconds_MetaData), NewProp_WreckLifetimeSeconds_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEchoesWreck_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesWreck_Statics::NewProp_DroppedItems_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesWreck_Statics::NewProp_DroppedItems,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesWreck_Statics::NewProp_AccessList_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesWreck_Statics::NewProp_AccessList,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesWreck_Statics::NewProp_KillmailId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesWreck_Statics::NewProp_WreckLifetimeSeconds,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEchoesWreck_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AEchoesWreck_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEchoesWreck_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AEchoesWreck_Statics::ClassParams = {
	&AEchoesWreck::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AEchoesWreck_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AEchoesWreck_Statics::PropPointers),
	0,
	0x009001A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEchoesWreck_Statics::Class_MetaDataParams), Z_Construct_UClass_AEchoesWreck_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AEchoesWreck()
{
	if (!Z_Registration_Info_UClass_AEchoesWreck.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEchoesWreck.OuterSingleton, Z_Construct_UClass_AEchoesWreck_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AEchoesWreck.OuterSingleton;
}
#if VALIDATE_CLASS_REPS
void AEchoesWreck::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static FName Name_DroppedItems(TEXT("DroppedItems"));
	const bool bIsValid = true
		&& Name_DroppedItems == ClassReps[(int32)ENetFields_Private::DroppedItems].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in AEchoesWreck"));
}
#endif
DEFINE_VTABLE_PTR_HELPER_CTOR(AEchoesWreck);
AEchoesWreck::~AEchoesWreck() {}
// ********** End Class AEchoesWreck ***************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EchoesWreck_h__Script_Echoes_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FWreckAccessEntry::StaticStruct, Z_Construct_UScriptStruct_FWreckAccessEntry_Statics::NewStructOps, TEXT("WreckAccessEntry"), &Z_Registration_Info_UScriptStruct_FWreckAccessEntry, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FWreckAccessEntry), 2373375999U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AEchoesWreck, AEchoesWreck::StaticClass, TEXT("AEchoesWreck"), &Z_Registration_Info_UClass_AEchoesWreck, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEchoesWreck), 1335365479U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EchoesWreck_h__Script_Echoes_1870120966(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EchoesWreck_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EchoesWreck_h__Script_Echoes_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EchoesWreck_h__Script_Echoes_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EchoesWreck_h__Script_Echoes_Statics::ScriptStructInfo),
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
