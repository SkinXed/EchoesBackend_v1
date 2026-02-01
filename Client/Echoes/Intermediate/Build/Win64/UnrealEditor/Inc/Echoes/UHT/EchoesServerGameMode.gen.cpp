// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EchoesServerGameMode.h"
#include "EchoesServerDiscoveryTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesServerGameMode() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ECHOES_API UClass* Z_Construct_UClass_AEchoesServerGameMode();
ECHOES_API UClass* Z_Construct_UClass_AEchoesServerGameMode_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_AEchoesWorldGenerator_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UEchoesInventorySubsystem_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UEchoesJumpManager_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UEchoesServerManagementSubsystem_NoRegister();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnEntryFlowComplete__DelegateSignature();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FCharacterLocationData();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FServerSystemConfig();
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FOnEntryFlowComplete **************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnEntryFlowComplete__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Delegate for entry flow completion\n" },
#endif
		{ "ModuleRelativePath", "EchoesServerGameMode.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Delegate for entry flow completion" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnEntryFlowComplete__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnEntryFlowComplete__DelegateSignature", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnEntryFlowComplete__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnEntryFlowComplete__DelegateSignature_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UDelegateFunction_Echoes_OnEntryFlowComplete__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnEntryFlowComplete__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnEntryFlowComplete_DelegateWrapper(const FMulticastScriptDelegate& OnEntryFlowComplete)
{
	OnEntryFlowComplete.ProcessMulticastDelegate<UObject>(NULL);
}
// ********** End Delegate FOnEntryFlowComplete ****************************************************

// ********** Begin ScriptStruct FCharacterLocationData ********************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FCharacterLocationData;
class UScriptStruct* FCharacterLocationData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FCharacterLocationData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FCharacterLocationData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FCharacterLocationData, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("CharacterLocationData"));
	}
	return Z_Registration_Info_UScriptStruct_FCharacterLocationData.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FCharacterLocationData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Character location data structure (mirrors backend CharacterLocationDto)\n */" },
#endif
		{ "ModuleRelativePath", "EchoesServerGameMode.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Character location data structure (mirrors backend CharacterLocationDto)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterId_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "EchoesServerGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IsDocked_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "EchoesServerGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InWarp_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "EchoesServerGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StationId_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "EchoesServerGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StationName_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "EchoesServerGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SolarSystemId_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "EchoesServerGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SolarSystemName_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "EchoesServerGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PositionX_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "EchoesServerGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PositionY_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "EchoesServerGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PositionZ_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "EchoesServerGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActiveShipTypeId_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "EchoesServerGameMode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_CharacterId;
	static void NewProp_IsDocked_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_IsDocked;
	static void NewProp_InWarp_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_InWarp;
	static const UECodeGen_Private::FStructPropertyParams NewProp_StationId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_StationName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SolarSystemId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SolarSystemName;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_PositionX;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_PositionY;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_PositionZ;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ActiveShipTypeId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCharacterLocationData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCharacterLocationData_Statics::NewProp_CharacterId = { "CharacterId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterLocationData, CharacterId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterId_MetaData), NewProp_CharacterId_MetaData) };
void Z_Construct_UScriptStruct_FCharacterLocationData_Statics::NewProp_IsDocked_SetBit(void* Obj)
{
	((FCharacterLocationData*)Obj)->IsDocked = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FCharacterLocationData_Statics::NewProp_IsDocked = { "IsDocked", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FCharacterLocationData), &Z_Construct_UScriptStruct_FCharacterLocationData_Statics::NewProp_IsDocked_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IsDocked_MetaData), NewProp_IsDocked_MetaData) };
void Z_Construct_UScriptStruct_FCharacterLocationData_Statics::NewProp_InWarp_SetBit(void* Obj)
{
	((FCharacterLocationData*)Obj)->InWarp = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FCharacterLocationData_Statics::NewProp_InWarp = { "InWarp", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FCharacterLocationData), &Z_Construct_UScriptStruct_FCharacterLocationData_Statics::NewProp_InWarp_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InWarp_MetaData), NewProp_InWarp_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCharacterLocationData_Statics::NewProp_StationId = { "StationId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterLocationData, StationId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StationId_MetaData), NewProp_StationId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FCharacterLocationData_Statics::NewProp_StationName = { "StationName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterLocationData, StationName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StationName_MetaData), NewProp_StationName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCharacterLocationData_Statics::NewProp_SolarSystemId = { "SolarSystemId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterLocationData, SolarSystemId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SolarSystemId_MetaData), NewProp_SolarSystemId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FCharacterLocationData_Statics::NewProp_SolarSystemName = { "SolarSystemName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterLocationData, SolarSystemName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SolarSystemName_MetaData), NewProp_SolarSystemName_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FCharacterLocationData_Statics::NewProp_PositionX = { "PositionX", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterLocationData, PositionX), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PositionX_MetaData), NewProp_PositionX_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FCharacterLocationData_Statics::NewProp_PositionY = { "PositionY", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterLocationData, PositionY), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PositionY_MetaData), NewProp_PositionY_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FCharacterLocationData_Statics::NewProp_PositionZ = { "PositionZ", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterLocationData, PositionZ), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PositionZ_MetaData), NewProp_PositionZ_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FCharacterLocationData_Statics::NewProp_ActiveShipTypeId = { "ActiveShipTypeId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterLocationData, ActiveShipTypeId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActiveShipTypeId_MetaData), NewProp_ActiveShipTypeId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCharacterLocationData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterLocationData_Statics::NewProp_CharacterId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterLocationData_Statics::NewProp_IsDocked,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterLocationData_Statics::NewProp_InWarp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterLocationData_Statics::NewProp_StationId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterLocationData_Statics::NewProp_StationName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterLocationData_Statics::NewProp_SolarSystemId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterLocationData_Statics::NewProp_SolarSystemName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterLocationData_Statics::NewProp_PositionX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterLocationData_Statics::NewProp_PositionY,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterLocationData_Statics::NewProp_PositionZ,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterLocationData_Statics::NewProp_ActiveShipTypeId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCharacterLocationData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCharacterLocationData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"CharacterLocationData",
	Z_Construct_UScriptStruct_FCharacterLocationData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCharacterLocationData_Statics::PropPointers),
	sizeof(FCharacterLocationData),
	alignof(FCharacterLocationData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCharacterLocationData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FCharacterLocationData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FCharacterLocationData()
{
	if (!Z_Registration_Info_UScriptStruct_FCharacterLocationData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FCharacterLocationData.InnerSingleton, Z_Construct_UScriptStruct_FCharacterLocationData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FCharacterLocationData.InnerSingleton;
}
// ********** End ScriptStruct FCharacterLocationData **********************************************

// ********** Begin Class AEchoesServerGameMode Function GetJumpManager ****************************
struct Z_Construct_UFunction_AEchoesServerGameMode_GetJumpManager_Statics
{
	struct EchoesServerGameMode_eventGetJumpManager_Parms
	{
		UEchoesJumpManager* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the jump manager (for stargate jumps)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "EchoesServerGameMode.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the jump manager (for stargate jumps)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AEchoesServerGameMode_GetJumpManager_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesServerGameMode_eventGetJumpManager_Parms, ReturnValue), Z_Construct_UClass_UEchoesJumpManager_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesServerGameMode_GetJumpManager_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesServerGameMode_GetJumpManager_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesServerGameMode_GetJumpManager_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesServerGameMode_GetJumpManager_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesServerGameMode, nullptr, "GetJumpManager", Z_Construct_UFunction_AEchoesServerGameMode_GetJumpManager_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesServerGameMode_GetJumpManager_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesServerGameMode_GetJumpManager_Statics::EchoesServerGameMode_eventGetJumpManager_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesServerGameMode_GetJumpManager_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesServerGameMode_GetJumpManager_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesServerGameMode_GetJumpManager_Statics::EchoesServerGameMode_eventGetJumpManager_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesServerGameMode_GetJumpManager()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesServerGameMode_GetJumpManager_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesServerGameMode::execGetJumpManager)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UEchoesJumpManager**)Z_Param__Result=P_THIS->GetJumpManager();
	P_NATIVE_END;
}
// ********** End Class AEchoesServerGameMode Function GetJumpManager ******************************

// ********** Begin Class AEchoesServerGameMode Function IsWorldGenerated **************************
struct Z_Construct_UFunction_AEchoesServerGameMode_IsWorldGenerated_Statics
{
	struct EchoesServerGameMode_eventIsWorldGenerated_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if world has been generated\n\x09 */" },
#endif
		{ "ModuleRelativePath", "EchoesServerGameMode.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if world has been generated" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_AEchoesServerGameMode_IsWorldGenerated_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((EchoesServerGameMode_eventIsWorldGenerated_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AEchoesServerGameMode_IsWorldGenerated_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EchoesServerGameMode_eventIsWorldGenerated_Parms), &Z_Construct_UFunction_AEchoesServerGameMode_IsWorldGenerated_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesServerGameMode_IsWorldGenerated_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesServerGameMode_IsWorldGenerated_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesServerGameMode_IsWorldGenerated_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesServerGameMode_IsWorldGenerated_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesServerGameMode, nullptr, "IsWorldGenerated", Z_Construct_UFunction_AEchoesServerGameMode_IsWorldGenerated_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesServerGameMode_IsWorldGenerated_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesServerGameMode_IsWorldGenerated_Statics::EchoesServerGameMode_eventIsWorldGenerated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesServerGameMode_IsWorldGenerated_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesServerGameMode_IsWorldGenerated_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesServerGameMode_IsWorldGenerated_Statics::EchoesServerGameMode_eventIsWorldGenerated_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesServerGameMode_IsWorldGenerated()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesServerGameMode_IsWorldGenerated_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesServerGameMode::execIsWorldGenerated)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsWorldGenerated();
	P_NATIVE_END;
}
// ********** End Class AEchoesServerGameMode Function IsWorldGenerated ****************************

// ********** Begin Class AEchoesServerGameMode Function OnServerConfigReceived ********************
struct Z_Construct_UFunction_AEchoesServerGameMode_OnServerConfigReceived_Statics
{
	struct EchoesServerGameMode_eventOnServerConfigReceived_Parms
	{
		FServerSystemConfig Config;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Called when server configuration is received from backend\n\x09 * Triggers world generation process\n\x09 */" },
#endif
		{ "ModuleRelativePath", "EchoesServerGameMode.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when server configuration is received from backend\nTriggers world generation process" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Config_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Config;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEchoesServerGameMode_OnServerConfigReceived_Statics::NewProp_Config = { "Config", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesServerGameMode_eventOnServerConfigReceived_Parms, Config), Z_Construct_UScriptStruct_FServerSystemConfig, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Config_MetaData), NewProp_Config_MetaData) }; // 1674105224
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesServerGameMode_OnServerConfigReceived_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesServerGameMode_OnServerConfigReceived_Statics::NewProp_Config,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesServerGameMode_OnServerConfigReceived_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesServerGameMode_OnServerConfigReceived_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesServerGameMode, nullptr, "OnServerConfigReceived", Z_Construct_UFunction_AEchoesServerGameMode_OnServerConfigReceived_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesServerGameMode_OnServerConfigReceived_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesServerGameMode_OnServerConfigReceived_Statics::EchoesServerGameMode_eventOnServerConfigReceived_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00480401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesServerGameMode_OnServerConfigReceived_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesServerGameMode_OnServerConfigReceived_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesServerGameMode_OnServerConfigReceived_Statics::EchoesServerGameMode_eventOnServerConfigReceived_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesServerGameMode_OnServerConfigReceived()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesServerGameMode_OnServerConfigReceived_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesServerGameMode::execOnServerConfigReceived)
{
	P_GET_STRUCT_REF(FServerSystemConfig,Z_Param_Out_Config);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnServerConfigReceived(Z_Param_Out_Config);
	P_NATIVE_END;
}
// ********** End Class AEchoesServerGameMode Function OnServerConfigReceived **********************

// ********** Begin Class AEchoesServerGameMode Function TriggerWorldGeneration ********************
struct Z_Construct_UFunction_AEchoesServerGameMode_TriggerWorldGeneration_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Manually trigger world generation (for testing)\n\x09 */" },
#endif
		{ "DevelopmentOnly", "" },
		{ "ModuleRelativePath", "EchoesServerGameMode.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Manually trigger world generation (for testing)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesServerGameMode_TriggerWorldGeneration_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesServerGameMode, nullptr, "TriggerWorldGeneration", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesServerGameMode_TriggerWorldGeneration_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesServerGameMode_TriggerWorldGeneration_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AEchoesServerGameMode_TriggerWorldGeneration()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesServerGameMode_TriggerWorldGeneration_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesServerGameMode::execTriggerWorldGeneration)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->TriggerWorldGeneration();
	P_NATIVE_END;
}
// ********** End Class AEchoesServerGameMode Function TriggerWorldGeneration **********************

// ********** Begin Class AEchoesServerGameMode ****************************************************
void AEchoesServerGameMode::StaticRegisterNativesAEchoesServerGameMode()
{
	UClass* Class = AEchoesServerGameMode::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetJumpManager", &AEchoesServerGameMode::execGetJumpManager },
		{ "IsWorldGenerated", &AEchoesServerGameMode::execIsWorldGenerated },
		{ "OnServerConfigReceived", &AEchoesServerGameMode::execOnServerConfigReceived },
		{ "TriggerWorldGeneration", &AEchoesServerGameMode::execTriggerWorldGeneration },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_AEchoesServerGameMode;
UClass* AEchoesServerGameMode::GetPrivateStaticClass()
{
	using TClass = AEchoesServerGameMode;
	if (!Z_Registration_Info_UClass_AEchoesServerGameMode.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesServerGameMode"),
			Z_Registration_Info_UClass_AEchoesServerGameMode.InnerSingleton,
			StaticRegisterNativesAEchoesServerGameMode,
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
	return Z_Registration_Info_UClass_AEchoesServerGameMode.InnerSingleton;
}
UClass* Z_Construct_UClass_AEchoesServerGameMode_NoRegister()
{
	return AEchoesServerGameMode::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AEchoesServerGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * AEchoesServerGameMode\n * \n * Server GameMode - The Conductor/Orchestrator\n * Manages world generation and player lifecycle on dedicated servers\n * \n * Architecture:\n * - Server-only execution (HasAuthority())\n * - Coordinates with UEchoesServerManagementSubsystem for configuration\n * - Triggers AEchoesWorldGenerator when config is ready\n * - Handles player login and spawn logic\n * \n * Workflow:\n * 1. BeginPlay: Check if server config is already received\n * 2. PostLogin: Verify world is generated before spawning players\n * 3. If config ready: Trigger world generation\n * 4. Track world generation state\n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "EchoesServerGameMode.h" },
		{ "ModuleRelativePath", "EchoesServerGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "AEchoesServerGameMode\n\nServer GameMode - The Conductor/Orchestrator\nManages world generation and player lifecycle on dedicated servers\n\nArchitecture:\n- Server-only execution (HasAuthority())\n- Coordinates with UEchoesServerManagementSubsystem for configuration\n- Triggers AEchoesWorldGenerator when config is ready\n- Handles player login and spawn logic\n\nWorkflow:\n1. BeginPlay: Check if server config is already received\n2. PostLogin: Verify world is generated before spawning players\n3. If config ready: Trigger world generation\n4. Track world generation state" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnEntryFlowComplete_MetaData[] = {
		{ "Category", "Echoes|Entry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when player is fully spawned and ready to play */" },
#endif
		{ "ModuleRelativePath", "EchoesServerGameMode.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when player is fully spawned and ready to play" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ServerManagementSubsystem_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Reference to server management subsystem */" },
#endif
		{ "ModuleRelativePath", "EchoesServerGameMode.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Reference to server management subsystem" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldGenerator_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Reference to world generator */" },
#endif
		{ "ModuleRelativePath", "EchoesServerGameMode.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Reference to world generator" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JumpManager_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Jump manager for intra-server jumps */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "EchoesServerGameMode.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Jump manager for intra-server jumps" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InventorySubsystem_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Inventory subsystem reference */" },
#endif
		{ "ModuleRelativePath", "EchoesServerGameMode.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Inventory subsystem reference" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bWorldGenerated_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether world has been generated */" },
#endif
		{ "ModuleRelativePath", "EchoesServerGameMode.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether world has been generated" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bWaitingForConfig_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether we're waiting for config */" },
#endif
		{ "ModuleRelativePath", "EchoesServerGameMode.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether we're waiting for config" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSubscribedToConfigDelegate_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether we've subscribed to config delegate */" },
#endif
		{ "ModuleRelativePath", "EchoesServerGameMode.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether we've subscribed to config delegate" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnEntryFlowComplete;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ServerManagementSubsystem;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldGenerator;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpManager;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InventorySubsystem;
	static void NewProp_bWorldGenerated_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bWorldGenerated;
	static void NewProp_bWaitingForConfig_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bWaitingForConfig;
	static void NewProp_bSubscribedToConfigDelegate_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSubscribedToConfigDelegate;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AEchoesServerGameMode_GetJumpManager, "GetJumpManager" }, // 2945978181
		{ &Z_Construct_UFunction_AEchoesServerGameMode_IsWorldGenerated, "IsWorldGenerated" }, // 2592357094
		{ &Z_Construct_UFunction_AEchoesServerGameMode_OnServerConfigReceived, "OnServerConfigReceived" }, // 518115377
		{ &Z_Construct_UFunction_AEchoesServerGameMode_TriggerWorldGeneration, "TriggerWorldGeneration" }, // 2473539558
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEchoesServerGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AEchoesServerGameMode_Statics::NewProp_OnEntryFlowComplete = { "OnEntryFlowComplete", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesServerGameMode, OnEntryFlowComplete), Z_Construct_UDelegateFunction_Echoes_OnEntryFlowComplete__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnEntryFlowComplete_MetaData), NewProp_OnEntryFlowComplete_MetaData) }; // 3171562333
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEchoesServerGameMode_Statics::NewProp_ServerManagementSubsystem = { "ServerManagementSubsystem", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesServerGameMode, ServerManagementSubsystem), Z_Construct_UClass_UEchoesServerManagementSubsystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ServerManagementSubsystem_MetaData), NewProp_ServerManagementSubsystem_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEchoesServerGameMode_Statics::NewProp_WorldGenerator = { "WorldGenerator", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesServerGameMode, WorldGenerator), Z_Construct_UClass_AEchoesWorldGenerator_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldGenerator_MetaData), NewProp_WorldGenerator_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEchoesServerGameMode_Statics::NewProp_JumpManager = { "JumpManager", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesServerGameMode, JumpManager), Z_Construct_UClass_UEchoesJumpManager_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpManager_MetaData), NewProp_JumpManager_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEchoesServerGameMode_Statics::NewProp_InventorySubsystem = { "InventorySubsystem", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesServerGameMode, InventorySubsystem), Z_Construct_UClass_UEchoesInventorySubsystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InventorySubsystem_MetaData), NewProp_InventorySubsystem_MetaData) };
void Z_Construct_UClass_AEchoesServerGameMode_Statics::NewProp_bWorldGenerated_SetBit(void* Obj)
{
	((AEchoesServerGameMode*)Obj)->bWorldGenerated = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AEchoesServerGameMode_Statics::NewProp_bWorldGenerated = { "bWorldGenerated", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AEchoesServerGameMode), &Z_Construct_UClass_AEchoesServerGameMode_Statics::NewProp_bWorldGenerated_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bWorldGenerated_MetaData), NewProp_bWorldGenerated_MetaData) };
void Z_Construct_UClass_AEchoesServerGameMode_Statics::NewProp_bWaitingForConfig_SetBit(void* Obj)
{
	((AEchoesServerGameMode*)Obj)->bWaitingForConfig = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AEchoesServerGameMode_Statics::NewProp_bWaitingForConfig = { "bWaitingForConfig", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AEchoesServerGameMode), &Z_Construct_UClass_AEchoesServerGameMode_Statics::NewProp_bWaitingForConfig_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bWaitingForConfig_MetaData), NewProp_bWaitingForConfig_MetaData) };
void Z_Construct_UClass_AEchoesServerGameMode_Statics::NewProp_bSubscribedToConfigDelegate_SetBit(void* Obj)
{
	((AEchoesServerGameMode*)Obj)->bSubscribedToConfigDelegate = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AEchoesServerGameMode_Statics::NewProp_bSubscribedToConfigDelegate = { "bSubscribedToConfigDelegate", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AEchoesServerGameMode), &Z_Construct_UClass_AEchoesServerGameMode_Statics::NewProp_bSubscribedToConfigDelegate_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSubscribedToConfigDelegate_MetaData), NewProp_bSubscribedToConfigDelegate_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEchoesServerGameMode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesServerGameMode_Statics::NewProp_OnEntryFlowComplete,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesServerGameMode_Statics::NewProp_ServerManagementSubsystem,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesServerGameMode_Statics::NewProp_WorldGenerator,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesServerGameMode_Statics::NewProp_JumpManager,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesServerGameMode_Statics::NewProp_InventorySubsystem,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesServerGameMode_Statics::NewProp_bWorldGenerated,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesServerGameMode_Statics::NewProp_bWaitingForConfig,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesServerGameMode_Statics::NewProp_bSubscribedToConfigDelegate,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEchoesServerGameMode_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AEchoesServerGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEchoesServerGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AEchoesServerGameMode_Statics::ClassParams = {
	&AEchoesServerGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AEchoesServerGameMode_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AEchoesServerGameMode_Statics::PropPointers),
	0,
	0x009003ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEchoesServerGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AEchoesServerGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AEchoesServerGameMode()
{
	if (!Z_Registration_Info_UClass_AEchoesServerGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEchoesServerGameMode.OuterSingleton, Z_Construct_UClass_AEchoesServerGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AEchoesServerGameMode.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AEchoesServerGameMode);
AEchoesServerGameMode::~AEchoesServerGameMode() {}
// ********** End Class AEchoesServerGameMode ******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesServerGameMode_h__Script_Echoes_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FCharacterLocationData::StaticStruct, Z_Construct_UScriptStruct_FCharacterLocationData_Statics::NewStructOps, TEXT("CharacterLocationData"), &Z_Registration_Info_UScriptStruct_FCharacterLocationData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FCharacterLocationData), 4259181453U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AEchoesServerGameMode, AEchoesServerGameMode::StaticClass, TEXT("AEchoesServerGameMode"), &Z_Registration_Info_UClass_AEchoesServerGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEchoesServerGameMode), 4217501391U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesServerGameMode_h__Script_Echoes_565899276(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesServerGameMode_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesServerGameMode_h__Script_Echoes_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesServerGameMode_h__Script_Echoes_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesServerGameMode_h__Script_Echoes_Statics::ScriptStructInfo),
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
