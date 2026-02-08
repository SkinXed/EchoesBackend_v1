// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CombatServerSubsystem.h"
#include "EchoesKillmailStructures.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeCombatServerSubsystem() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ECHOES_API UClass* Z_Construct_UClass_UCombatServerSubsystem();
ECHOES_API UClass* Z_Construct_UClass_UCombatServerSubsystem_NoRegister();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnKillmailReported__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnKillmailReportFailed__DelegateSignature();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FKillmailData();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FKillmailItem();
ENGINE_API UClass* Z_Construct_UClass_UWorldSubsystem();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FOnKillmailReported ***************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnKillmailReported__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnKillmailReported_Parms
	{
		FKillmailData Killmail;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Delegate fired when a killmail is successfully reported to backend */" },
#endif
		{ "ModuleRelativePath", "Core/Server/CombatServerSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Delegate fired when a killmail is successfully reported to backend" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Killmail_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Killmail;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_Echoes_OnKillmailReported__DelegateSignature_Statics::NewProp_Killmail = { "Killmail", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnKillmailReported_Parms, Killmail), Z_Construct_UScriptStruct_FKillmailData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Killmail_MetaData), NewProp_Killmail_MetaData) }; // 1177097489
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnKillmailReported__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnKillmailReported__DelegateSignature_Statics::NewProp_Killmail,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnKillmailReported__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnKillmailReported__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnKillmailReported__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnKillmailReported__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnKillmailReported__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnKillmailReported__DelegateSignature_Statics::_Script_Echoes_eventOnKillmailReported_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnKillmailReported__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnKillmailReported__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnKillmailReported__DelegateSignature_Statics::_Script_Echoes_eventOnKillmailReported_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnKillmailReported__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnKillmailReported__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnKillmailReported_DelegateWrapper(const FMulticastScriptDelegate& OnKillmailReported, FKillmailData const& Killmail)
{
	struct _Script_Echoes_eventOnKillmailReported_Parms
	{
		FKillmailData Killmail;
	};
	_Script_Echoes_eventOnKillmailReported_Parms Parms;
	Parms.Killmail=Killmail;
	OnKillmailReported.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnKillmailReported *****************************************************

// ********** Begin Delegate FOnKillmailReportFailed ***********************************************
struct Z_Construct_UDelegateFunction_Echoes_OnKillmailReportFailed__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnKillmailReportFailed_Parms
	{
		FString ErrorMessage;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Delegate fired when a killmail report fails */" },
#endif
		{ "ModuleRelativePath", "Core/Server/CombatServerSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Delegate fired when a killmail report fails" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_Echoes_OnKillmailReportFailed__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnKillmailReportFailed_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ErrorMessage_MetaData), NewProp_ErrorMessage_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnKillmailReportFailed__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnKillmailReportFailed__DelegateSignature_Statics::NewProp_ErrorMessage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnKillmailReportFailed__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnKillmailReportFailed__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnKillmailReportFailed__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnKillmailReportFailed__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnKillmailReportFailed__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnKillmailReportFailed__DelegateSignature_Statics::_Script_Echoes_eventOnKillmailReportFailed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnKillmailReportFailed__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnKillmailReportFailed__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnKillmailReportFailed__DelegateSignature_Statics::_Script_Echoes_eventOnKillmailReportFailed_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnKillmailReportFailed__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnKillmailReportFailed__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnKillmailReportFailed_DelegateWrapper(const FMulticastScriptDelegate& OnKillmailReportFailed, const FString& ErrorMessage)
{
	struct _Script_Echoes_eventOnKillmailReportFailed_Parms
	{
		FString ErrorMessage;
	};
	_Script_Echoes_eventOnKillmailReportFailed_Parms Parms;
	Parms.ErrorMessage=ErrorMessage;
	OnKillmailReportFailed.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnKillmailReportFailed *************************************************

// ********** Begin Class UCombatServerSubsystem Function ServerOnly_ClearDamageMap ****************
struct Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_ClearDamageMap_Statics
{
	struct CombatServerSubsystem_eventServerOnly_ClearDamageMap_Parms
	{
		FGuid VictimId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Combat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Clear damage map for a victim (e.g., when docking or warping safely)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Server/CombatServerSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Clear damage map for a victim (e.g., when docking or warping safely)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VictimId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_VictimId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_ClearDamageMap_Statics::NewProp_VictimId = { "VictimId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CombatServerSubsystem_eventServerOnly_ClearDamageMap_Parms, VictimId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VictimId_MetaData), NewProp_VictimId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_ClearDamageMap_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_ClearDamageMap_Statics::NewProp_VictimId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_ClearDamageMap_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_ClearDamageMap_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCombatServerSubsystem, nullptr, "ServerOnly_ClearDamageMap", Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_ClearDamageMap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_ClearDamageMap_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_ClearDamageMap_Statics::CombatServerSubsystem_eventServerOnly_ClearDamageMap_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_ClearDamageMap_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_ClearDamageMap_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_ClearDamageMap_Statics::CombatServerSubsystem_eventServerOnly_ClearDamageMap_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_ClearDamageMap()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_ClearDamageMap_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCombatServerSubsystem::execServerOnly_ClearDamageMap)
{
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_VictimId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerOnly_ClearDamageMap(Z_Param_Out_VictimId);
	P_NATIVE_END;
}
// ********** End Class UCombatServerSubsystem Function ServerOnly_ClearDamageMap ******************

// ********** Begin Class UCombatServerSubsystem Function ServerOnly_HandleDestruction *************
struct Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_HandleDestruction_Statics
{
	struct CombatServerSubsystem_eventServerOnly_HandleDestruction_Parms
	{
		FGuid VictimId;
		FString VictimName;
		FGuid FinalStrikerId;
		FGuid SolarSystemId;
		FString SolarSystemName;
		int32 ShipTypeId;
		FString ShipTypeName;
		TArray<FKillmailItem> FittedModules;
		TArray<FKillmailItem> CargoItems;
		FVector DestructionLocation;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Combat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Handle ship destruction: generate killmail, calculate drops, spawn wreck\n\x09 * Called when a ship's CurrentHull reaches 0\n\x09 * \n\x09 * @param VictimId - Character ID of the destroyed ship's pilot\n\x09 * @param VictimName - Display name of the victim\n\x09 * @param FinalStrikerId - Character ID of who dealt the killing blow\n\x09 * @param SolarSystemId - Solar system where destruction occurred\n\x09 * @param SolarSystemName - Name of the solar system\n\x09 * @param ShipTypeId - Type ID of the destroyed ship\n\x09 * @param ShipTypeName - Name of the destroyed ship type\n\x09 * @param FittedModules - Modules fitted to the ship at time of destruction\n\x09 * @param CargoItems - Items in the ship's cargo hold\n\x09 * @param DestructionLocation - World location to spawn the wreck\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Server/CombatServerSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handle ship destruction: generate killmail, calculate drops, spawn wreck\nCalled when a ship's CurrentHull reaches 0\n\n@param VictimId - Character ID of the destroyed ship's pilot\n@param VictimName - Display name of the victim\n@param FinalStrikerId - Character ID of who dealt the killing blow\n@param SolarSystemId - Solar system where destruction occurred\n@param SolarSystemName - Name of the solar system\n@param ShipTypeId - Type ID of the destroyed ship\n@param ShipTypeName - Name of the destroyed ship type\n@param FittedModules - Modules fitted to the ship at time of destruction\n@param CargoItems - Items in the ship's cargo hold\n@param DestructionLocation - World location to spawn the wreck" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VictimId_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VictimName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FinalStrikerId_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SolarSystemId_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SolarSystemName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShipTypeName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FittedModules_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CargoItems_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DestructionLocation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_VictimId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_VictimName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_FinalStrikerId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SolarSystemId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SolarSystemName;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ShipTypeId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ShipTypeName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_FittedModules_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_FittedModules;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CargoItems_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_CargoItems;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DestructionLocation;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_HandleDestruction_Statics::NewProp_VictimId = { "VictimId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CombatServerSubsystem_eventServerOnly_HandleDestruction_Parms, VictimId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VictimId_MetaData), NewProp_VictimId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_HandleDestruction_Statics::NewProp_VictimName = { "VictimName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CombatServerSubsystem_eventServerOnly_HandleDestruction_Parms, VictimName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VictimName_MetaData), NewProp_VictimName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_HandleDestruction_Statics::NewProp_FinalStrikerId = { "FinalStrikerId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CombatServerSubsystem_eventServerOnly_HandleDestruction_Parms, FinalStrikerId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FinalStrikerId_MetaData), NewProp_FinalStrikerId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_HandleDestruction_Statics::NewProp_SolarSystemId = { "SolarSystemId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CombatServerSubsystem_eventServerOnly_HandleDestruction_Parms, SolarSystemId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SolarSystemId_MetaData), NewProp_SolarSystemId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_HandleDestruction_Statics::NewProp_SolarSystemName = { "SolarSystemName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CombatServerSubsystem_eventServerOnly_HandleDestruction_Parms, SolarSystemName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SolarSystemName_MetaData), NewProp_SolarSystemName_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_HandleDestruction_Statics::NewProp_ShipTypeId = { "ShipTypeId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CombatServerSubsystem_eventServerOnly_HandleDestruction_Parms, ShipTypeId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_HandleDestruction_Statics::NewProp_ShipTypeName = { "ShipTypeName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CombatServerSubsystem_eventServerOnly_HandleDestruction_Parms, ShipTypeName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShipTypeName_MetaData), NewProp_ShipTypeName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_HandleDestruction_Statics::NewProp_FittedModules_Inner = { "FittedModules", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FKillmailItem, METADATA_PARAMS(0, nullptr) }; // 4119519826
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_HandleDestruction_Statics::NewProp_FittedModules = { "FittedModules", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CombatServerSubsystem_eventServerOnly_HandleDestruction_Parms, FittedModules), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FittedModules_MetaData), NewProp_FittedModules_MetaData) }; // 4119519826
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_HandleDestruction_Statics::NewProp_CargoItems_Inner = { "CargoItems", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FKillmailItem, METADATA_PARAMS(0, nullptr) }; // 4119519826
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_HandleDestruction_Statics::NewProp_CargoItems = { "CargoItems", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CombatServerSubsystem_eventServerOnly_HandleDestruction_Parms, CargoItems), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CargoItems_MetaData), NewProp_CargoItems_MetaData) }; // 4119519826
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_HandleDestruction_Statics::NewProp_DestructionLocation = { "DestructionLocation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CombatServerSubsystem_eventServerOnly_HandleDestruction_Parms, DestructionLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DestructionLocation_MetaData), NewProp_DestructionLocation_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_HandleDestruction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_HandleDestruction_Statics::NewProp_VictimId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_HandleDestruction_Statics::NewProp_VictimName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_HandleDestruction_Statics::NewProp_FinalStrikerId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_HandleDestruction_Statics::NewProp_SolarSystemId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_HandleDestruction_Statics::NewProp_SolarSystemName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_HandleDestruction_Statics::NewProp_ShipTypeId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_HandleDestruction_Statics::NewProp_ShipTypeName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_HandleDestruction_Statics::NewProp_FittedModules_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_HandleDestruction_Statics::NewProp_FittedModules,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_HandleDestruction_Statics::NewProp_CargoItems_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_HandleDestruction_Statics::NewProp_CargoItems,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_HandleDestruction_Statics::NewProp_DestructionLocation,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_HandleDestruction_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_HandleDestruction_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCombatServerSubsystem, nullptr, "ServerOnly_HandleDestruction", Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_HandleDestruction_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_HandleDestruction_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_HandleDestruction_Statics::CombatServerSubsystem_eventServerOnly_HandleDestruction_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_HandleDestruction_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_HandleDestruction_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_HandleDestruction_Statics::CombatServerSubsystem_eventServerOnly_HandleDestruction_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_HandleDestruction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_HandleDestruction_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCombatServerSubsystem::execServerOnly_HandleDestruction)
{
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_VictimId);
	P_GET_PROPERTY(FStrProperty,Z_Param_VictimName);
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_FinalStrikerId);
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_SolarSystemId);
	P_GET_PROPERTY(FStrProperty,Z_Param_SolarSystemName);
	P_GET_PROPERTY(FIntProperty,Z_Param_ShipTypeId);
	P_GET_PROPERTY(FStrProperty,Z_Param_ShipTypeName);
	P_GET_TARRAY_REF(FKillmailItem,Z_Param_Out_FittedModules);
	P_GET_TARRAY_REF(FKillmailItem,Z_Param_Out_CargoItems);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_DestructionLocation);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerOnly_HandleDestruction(Z_Param_Out_VictimId,Z_Param_VictimName,Z_Param_Out_FinalStrikerId,Z_Param_Out_SolarSystemId,Z_Param_SolarSystemName,Z_Param_ShipTypeId,Z_Param_ShipTypeName,Z_Param_Out_FittedModules,Z_Param_Out_CargoItems,Z_Param_Out_DestructionLocation);
	P_NATIVE_END;
}
// ********** End Class UCombatServerSubsystem Function ServerOnly_HandleDestruction ***************

// ********** Begin Class UCombatServerSubsystem Function ServerOnly_RegisterDamage ****************
struct Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_RegisterDamage_Statics
{
	struct CombatServerSubsystem_eventServerOnly_RegisterDamage_Parms
	{
		FGuid VictimId;
		FGuid AttackerId;
		FString AttackerName;
		FGuid AttackerCorporationId;
		int32 AttackerShipTypeId;
		FString AttackerShipTypeName;
		FString WeaponName;
		double DamageAmount;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Combat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Register damage dealt by an attacker to a victim\n\x09 * Accumulates in a per-victim damage map for killmail generation\n\x09 * \n\x09 * @param VictimId - Character ID of the ship taking damage\n\x09 * @param AttackerId - Character ID of the attacker\n\x09 * @param AttackerName - Display name of the attacker\n\x09 * @param AttackerCorporationId - Corporation of the attacker (for loot rights)\n\x09 * @param AttackerShipTypeId - Ship type of the attacker\n\x09 * @param AttackerShipTypeName - Ship type name of the attacker\n\x09 * @param WeaponName - Name of the weapon used\n\x09 * @param DamageAmount - Amount of damage dealt\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Server/CombatServerSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Register damage dealt by an attacker to a victim\nAccumulates in a per-victim damage map for killmail generation\n\n@param VictimId - Character ID of the ship taking damage\n@param AttackerId - Character ID of the attacker\n@param AttackerName - Display name of the attacker\n@param AttackerCorporationId - Corporation of the attacker (for loot rights)\n@param AttackerShipTypeId - Ship type of the attacker\n@param AttackerShipTypeName - Ship type name of the attacker\n@param WeaponName - Name of the weapon used\n@param DamageAmount - Amount of damage dealt" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VictimId_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackerId_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackerName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackerCorporationId_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackerShipTypeName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WeaponName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_VictimId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AttackerId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_AttackerName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AttackerCorporationId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_AttackerShipTypeId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_AttackerShipTypeName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_WeaponName;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_DamageAmount;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_RegisterDamage_Statics::NewProp_VictimId = { "VictimId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CombatServerSubsystem_eventServerOnly_RegisterDamage_Parms, VictimId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VictimId_MetaData), NewProp_VictimId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_RegisterDamage_Statics::NewProp_AttackerId = { "AttackerId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CombatServerSubsystem_eventServerOnly_RegisterDamage_Parms, AttackerId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackerId_MetaData), NewProp_AttackerId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_RegisterDamage_Statics::NewProp_AttackerName = { "AttackerName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CombatServerSubsystem_eventServerOnly_RegisterDamage_Parms, AttackerName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackerName_MetaData), NewProp_AttackerName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_RegisterDamage_Statics::NewProp_AttackerCorporationId = { "AttackerCorporationId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CombatServerSubsystem_eventServerOnly_RegisterDamage_Parms, AttackerCorporationId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackerCorporationId_MetaData), NewProp_AttackerCorporationId_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_RegisterDamage_Statics::NewProp_AttackerShipTypeId = { "AttackerShipTypeId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CombatServerSubsystem_eventServerOnly_RegisterDamage_Parms, AttackerShipTypeId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_RegisterDamage_Statics::NewProp_AttackerShipTypeName = { "AttackerShipTypeName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CombatServerSubsystem_eventServerOnly_RegisterDamage_Parms, AttackerShipTypeName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackerShipTypeName_MetaData), NewProp_AttackerShipTypeName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_RegisterDamage_Statics::NewProp_WeaponName = { "WeaponName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CombatServerSubsystem_eventServerOnly_RegisterDamage_Parms, WeaponName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WeaponName_MetaData), NewProp_WeaponName_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_RegisterDamage_Statics::NewProp_DamageAmount = { "DamageAmount", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CombatServerSubsystem_eventServerOnly_RegisterDamage_Parms, DamageAmount), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_RegisterDamage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_RegisterDamage_Statics::NewProp_VictimId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_RegisterDamage_Statics::NewProp_AttackerId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_RegisterDamage_Statics::NewProp_AttackerName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_RegisterDamage_Statics::NewProp_AttackerCorporationId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_RegisterDamage_Statics::NewProp_AttackerShipTypeId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_RegisterDamage_Statics::NewProp_AttackerShipTypeName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_RegisterDamage_Statics::NewProp_WeaponName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_RegisterDamage_Statics::NewProp_DamageAmount,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_RegisterDamage_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_RegisterDamage_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCombatServerSubsystem, nullptr, "ServerOnly_RegisterDamage", Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_RegisterDamage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_RegisterDamage_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_RegisterDamage_Statics::CombatServerSubsystem_eventServerOnly_RegisterDamage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_RegisterDamage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_RegisterDamage_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_RegisterDamage_Statics::CombatServerSubsystem_eventServerOnly_RegisterDamage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_RegisterDamage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_RegisterDamage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCombatServerSubsystem::execServerOnly_RegisterDamage)
{
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_VictimId);
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_AttackerId);
	P_GET_PROPERTY(FStrProperty,Z_Param_AttackerName);
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_AttackerCorporationId);
	P_GET_PROPERTY(FIntProperty,Z_Param_AttackerShipTypeId);
	P_GET_PROPERTY(FStrProperty,Z_Param_AttackerShipTypeName);
	P_GET_PROPERTY(FStrProperty,Z_Param_WeaponName);
	P_GET_PROPERTY(FDoubleProperty,Z_Param_DamageAmount);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerOnly_RegisterDamage(Z_Param_Out_VictimId,Z_Param_Out_AttackerId,Z_Param_AttackerName,Z_Param_Out_AttackerCorporationId,Z_Param_AttackerShipTypeId,Z_Param_AttackerShipTypeName,Z_Param_WeaponName,Z_Param_DamageAmount);
	P_NATIVE_END;
}
// ********** End Class UCombatServerSubsystem Function ServerOnly_RegisterDamage ******************

// ********** Begin Class UCombatServerSubsystem Function ServerOnly_ReportKill ********************
struct Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_ReportKill_Statics
{
	struct CombatServerSubsystem_eventServerOnly_ReportKill_Parms
	{
		int32 VictimID;
		int32 KillerID;
		int32 SolarSystemID;
		FString ShipType;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Combat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Simple kill report (legacy compatibility)\n\x09 * Sends minimal killmail to backend without drop calculation\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Server/CombatServerSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Simple kill report (legacy compatibility)\nSends minimal killmail to backend without drop calculation" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShipType_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_VictimID;
	static const UECodeGen_Private::FIntPropertyParams NewProp_KillerID;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SolarSystemID;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ShipType;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_ReportKill_Statics::NewProp_VictimID = { "VictimID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CombatServerSubsystem_eventServerOnly_ReportKill_Parms, VictimID), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_ReportKill_Statics::NewProp_KillerID = { "KillerID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CombatServerSubsystem_eventServerOnly_ReportKill_Parms, KillerID), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_ReportKill_Statics::NewProp_SolarSystemID = { "SolarSystemID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CombatServerSubsystem_eventServerOnly_ReportKill_Parms, SolarSystemID), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_ReportKill_Statics::NewProp_ShipType = { "ShipType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CombatServerSubsystem_eventServerOnly_ReportKill_Parms, ShipType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShipType_MetaData), NewProp_ShipType_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_ReportKill_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_ReportKill_Statics::NewProp_VictimID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_ReportKill_Statics::NewProp_KillerID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_ReportKill_Statics::NewProp_SolarSystemID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_ReportKill_Statics::NewProp_ShipType,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_ReportKill_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_ReportKill_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCombatServerSubsystem, nullptr, "ServerOnly_ReportKill", Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_ReportKill_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_ReportKill_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_ReportKill_Statics::CombatServerSubsystem_eventServerOnly_ReportKill_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_ReportKill_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_ReportKill_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_ReportKill_Statics::CombatServerSubsystem_eventServerOnly_ReportKill_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_ReportKill()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_ReportKill_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCombatServerSubsystem::execServerOnly_ReportKill)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_VictimID);
	P_GET_PROPERTY(FIntProperty,Z_Param_KillerID);
	P_GET_PROPERTY(FIntProperty,Z_Param_SolarSystemID);
	P_GET_PROPERTY(FStrProperty,Z_Param_ShipType);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerOnly_ReportKill(Z_Param_VictimID,Z_Param_KillerID,Z_Param_SolarSystemID,Z_Param_ShipType);
	P_NATIVE_END;
}
// ********** End Class UCombatServerSubsystem Function ServerOnly_ReportKill **********************

// ********** Begin Class UCombatServerSubsystem ***************************************************
void UCombatServerSubsystem::StaticRegisterNativesUCombatServerSubsystem()
{
	UClass* Class = UCombatServerSubsystem::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ServerOnly_ClearDamageMap", &UCombatServerSubsystem::execServerOnly_ClearDamageMap },
		{ "ServerOnly_HandleDestruction", &UCombatServerSubsystem::execServerOnly_HandleDestruction },
		{ "ServerOnly_RegisterDamage", &UCombatServerSubsystem::execServerOnly_RegisterDamage },
		{ "ServerOnly_ReportKill", &UCombatServerSubsystem::execServerOnly_ReportKill },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UCombatServerSubsystem;
UClass* UCombatServerSubsystem::GetPrivateStaticClass()
{
	using TClass = UCombatServerSubsystem;
	if (!Z_Registration_Info_UClass_UCombatServerSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("CombatServerSubsystem"),
			Z_Registration_Info_UClass_UCombatServerSubsystem.InnerSingleton,
			StaticRegisterNativesUCombatServerSubsystem,
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
	return Z_Registration_Info_UClass_UCombatServerSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UCombatServerSubsystem_NoRegister()
{
	return UCombatServerSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UCombatServerSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * UCombatServerSubsystem\n * \n * Combat Server Subsystem for Echoes Dedicated Server\n * Handles combat-related server operations and communication with ASP.NET Core backend\n * Mirrors CombatController on backend\n * \n * Architecture:\n * - WorldSubsystem: Persists for the world lifetime (server side only)\n * - Only runs when NetMode == NM_DedicatedServer\n * - All requests to backend must include X-Server-Secret header\n * - Reports player deaths (killmails) to backend for tracking and statistics\n * - Handles destruction logic: damage map, 50/50 drop roll, wreck spawning\n * \n * Usage:\n * 1. Track damage via ServerOnly_RegisterDamage() during combat\n * 2. When CurrentHull reaches 0, call ServerOnly_HandleDestruction()\n * 3. Subsystem calculates drop, spawns wreck, and reports to backend\n */" },
#endif
		{ "IncludePath", "Core/Server/CombatServerSubsystem.h" },
		{ "ModuleRelativePath", "Core/Server/CombatServerSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UCombatServerSubsystem\n\nCombat Server Subsystem for Echoes Dedicated Server\nHandles combat-related server operations and communication with ASP.NET Core backend\nMirrors CombatController on backend\n\nArchitecture:\n- WorldSubsystem: Persists for the world lifetime (server side only)\n- Only runs when NetMode == NM_DedicatedServer\n- All requests to backend must include X-Server-Secret header\n- Reports player deaths (killmails) to backend for tracking and statistics\n- Handles destruction logic: damage map, 50/50 drop roll, wreck spawning\n\nUsage:\n1. Track damage via ServerOnly_RegisterDamage() during combat\n2. When CurrentHull reaches 0, call ServerOnly_HandleDestruction()\n3. Subsystem calculates drop, spawns wreck, and reports to backend" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnKillmailReported_MetaData[] = {
		{ "Category", "Echoes|Combat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when a killmail is successfully reported */" },
#endif
		{ "ModuleRelativePath", "Core/Server/CombatServerSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when a killmail is successfully reported" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnKillmailReportFailed_MetaData[] = {
		{ "Category", "Echoes|Combat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when killmail report fails */" },
#endif
		{ "ModuleRelativePath", "Core/Server/CombatServerSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when killmail report fails" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BackendURL_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ==================== Configuration (from DefaultGame.ini) ====================\n" },
#endif
		{ "ModuleRelativePath", "Core/Server/CombatServerSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "==================== Configuration (from DefaultGame.ini) ====================" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ServerSecret_MetaData[] = {
		{ "ModuleRelativePath", "Core/Server/CombatServerSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_KillmailEndpoint_MetaData[] = {
		{ "ModuleRelativePath", "Core/Server/CombatServerSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnKillmailReported;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnKillmailReportFailed;
	static const UECodeGen_Private::FStrPropertyParams NewProp_BackendURL;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ServerSecret;
	static const UECodeGen_Private::FStrPropertyParams NewProp_KillmailEndpoint;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_ClearDamageMap, "ServerOnly_ClearDamageMap" }, // 2815414074
		{ &Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_HandleDestruction, "ServerOnly_HandleDestruction" }, // 1750122473
		{ &Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_RegisterDamage, "ServerOnly_RegisterDamage" }, // 629496150
		{ &Z_Construct_UFunction_UCombatServerSubsystem_ServerOnly_ReportKill, "ServerOnly_ReportKill" }, // 3606190417
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCombatServerSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UCombatServerSubsystem_Statics::NewProp_OnKillmailReported = { "OnKillmailReported", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCombatServerSubsystem, OnKillmailReported), Z_Construct_UDelegateFunction_Echoes_OnKillmailReported__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnKillmailReported_MetaData), NewProp_OnKillmailReported_MetaData) }; // 3664210653
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UCombatServerSubsystem_Statics::NewProp_OnKillmailReportFailed = { "OnKillmailReportFailed", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCombatServerSubsystem, OnKillmailReportFailed), Z_Construct_UDelegateFunction_Echoes_OnKillmailReportFailed__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnKillmailReportFailed_MetaData), NewProp_OnKillmailReportFailed_MetaData) }; // 3387539703
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UCombatServerSubsystem_Statics::NewProp_BackendURL = { "BackendURL", nullptr, (EPropertyFlags)0x0040000000004000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCombatServerSubsystem, BackendURL), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BackendURL_MetaData), NewProp_BackendURL_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UCombatServerSubsystem_Statics::NewProp_ServerSecret = { "ServerSecret", nullptr, (EPropertyFlags)0x0040000000004000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCombatServerSubsystem, ServerSecret), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ServerSecret_MetaData), NewProp_ServerSecret_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UCombatServerSubsystem_Statics::NewProp_KillmailEndpoint = { "KillmailEndpoint", nullptr, (EPropertyFlags)0x0040000000004000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCombatServerSubsystem, KillmailEndpoint), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_KillmailEndpoint_MetaData), NewProp_KillmailEndpoint_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCombatServerSubsystem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatServerSubsystem_Statics::NewProp_OnKillmailReported,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatServerSubsystem_Statics::NewProp_OnKillmailReportFailed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatServerSubsystem_Statics::NewProp_BackendURL,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatServerSubsystem_Statics::NewProp_ServerSecret,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCombatServerSubsystem_Statics::NewProp_KillmailEndpoint,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCombatServerSubsystem_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UCombatServerSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UWorldSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCombatServerSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCombatServerSubsystem_Statics::ClassParams = {
	&UCombatServerSubsystem::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UCombatServerSubsystem_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UCombatServerSubsystem_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCombatServerSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UCombatServerSubsystem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCombatServerSubsystem()
{
	if (!Z_Registration_Info_UClass_UCombatServerSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCombatServerSubsystem.OuterSingleton, Z_Construct_UClass_UCombatServerSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCombatServerSubsystem.OuterSingleton;
}
UCombatServerSubsystem::UCombatServerSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCombatServerSubsystem);
UCombatServerSubsystem::~UCombatServerSubsystem() {}
// ********** End Class UCombatServerSubsystem *****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_CombatServerSubsystem_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCombatServerSubsystem, UCombatServerSubsystem::StaticClass, TEXT("UCombatServerSubsystem"), &Z_Registration_Info_UClass_UCombatServerSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCombatServerSubsystem), 3794594555U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_CombatServerSubsystem_h__Script_Echoes_987387542(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_CombatServerSubsystem_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_CombatServerSubsystem_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
