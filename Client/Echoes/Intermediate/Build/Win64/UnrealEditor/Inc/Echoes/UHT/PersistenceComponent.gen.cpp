// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PersistenceComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodePersistenceComponent() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FQuat();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ECHOES_API UClass* Z_Construct_UClass_UEchoesPersistenceSubsystem_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UEchoesStatsComponent_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UPersistenceComponent();
ECHOES_API UClass* Z_Construct_UClass_UPersistenceComponent_NoRegister();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FCommon_StateData();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FCommon_StateData *************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FCommon_StateData;
class UScriptStruct* FCommon_StateData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FCommon_StateData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FCommon_StateData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FCommon_StateData, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("Common_StateData"));
	}
	return Z_Registration_Info_UScriptStruct_FCommon_StateData.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FCommon_StateData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Structure for character state data\n * Common_ prefix indicates it's used on both client and server\n * Mirrors SaveCharacterStateRequest DTO from backend\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/PersistenceComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Structure for character state data\nCommon_ prefix indicates it's used on both client and server\nMirrors SaveCharacterStateRequest DTO from backend" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LastSystemId_MetaData[] = {
		{ "Category", "State" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Last solar system ID (nullable) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/PersistenceComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Last solar system ID (nullable)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Position_MetaData[] = {
		{ "Category", "State" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Position in 3D space */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/PersistenceComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Position in 3D space" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rotation_MetaData[] = {
		{ "Category", "State" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Rotation (quaternion) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/PersistenceComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Rotation (quaternion)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentShield_MetaData[] = {
		{ "Category", "State" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current shield hit points */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/PersistenceComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current shield hit points" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentArmor_MetaData[] = {
		{ "Category", "State" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current armor hit points */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/PersistenceComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current armor hit points" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentHull_MetaData[] = {
		{ "Category", "State" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current hull (structure) hit points */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/PersistenceComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current hull (structure) hit points" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentCapacitor_MetaData[] = {
		{ "Category", "State" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current capacitor energy */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/PersistenceComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current capacitor energy" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_LastSystemId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Position;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Rotation;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentShield;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentArmor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentHull;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentCapacitor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCommon_StateData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCommon_StateData_Statics::NewProp_LastSystemId = { "LastSystemId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_StateData, LastSystemId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LastSystemId_MetaData), NewProp_LastSystemId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCommon_StateData_Statics::NewProp_Position = { "Position", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_StateData, Position), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Position_MetaData), NewProp_Position_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCommon_StateData_Statics::NewProp_Rotation = { "Rotation", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_StateData, Rotation), Z_Construct_UScriptStruct_FQuat, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rotation_MetaData), NewProp_Rotation_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCommon_StateData_Statics::NewProp_CurrentShield = { "CurrentShield", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_StateData, CurrentShield), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentShield_MetaData), NewProp_CurrentShield_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCommon_StateData_Statics::NewProp_CurrentArmor = { "CurrentArmor", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_StateData, CurrentArmor), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentArmor_MetaData), NewProp_CurrentArmor_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCommon_StateData_Statics::NewProp_CurrentHull = { "CurrentHull", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_StateData, CurrentHull), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentHull_MetaData), NewProp_CurrentHull_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCommon_StateData_Statics::NewProp_CurrentCapacitor = { "CurrentCapacitor", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_StateData, CurrentCapacitor), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentCapacitor_MetaData), NewProp_CurrentCapacitor_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCommon_StateData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_StateData_Statics::NewProp_LastSystemId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_StateData_Statics::NewProp_Position,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_StateData_Statics::NewProp_Rotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_StateData_Statics::NewProp_CurrentShield,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_StateData_Statics::NewProp_CurrentArmor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_StateData_Statics::NewProp_CurrentHull,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_StateData_Statics::NewProp_CurrentCapacitor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCommon_StateData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCommon_StateData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"Common_StateData",
	Z_Construct_UScriptStruct_FCommon_StateData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCommon_StateData_Statics::PropPointers),
	sizeof(FCommon_StateData),
	alignof(FCommon_StateData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCommon_StateData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FCommon_StateData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FCommon_StateData()
{
	if (!Z_Registration_Info_UScriptStruct_FCommon_StateData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FCommon_StateData.InnerSingleton, Z_Construct_UScriptStruct_FCommon_StateData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FCommon_StateData.InnerSingleton;
}
// ********** End ScriptStruct FCommon_StateData ***************************************************

// ********** Begin Class UPersistenceComponent Function Common_SetCharacterId *********************
struct Z_Construct_UFunction_UPersistenceComponent_Common_SetCharacterId_Statics
{
	struct PersistenceComponent_eventCommon_SetCharacterId_Parms
	{
		FGuid InCharacterId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Persistence" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Set character ID for this component\n\x09 * Should be called during initialization\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/PersistenceComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set character ID for this component\nShould be called during initialization" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InCharacterId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_InCharacterId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPersistenceComponent_Common_SetCharacterId_Statics::NewProp_InCharacterId = { "InCharacterId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PersistenceComponent_eventCommon_SetCharacterId_Parms, InCharacterId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InCharacterId_MetaData), NewProp_InCharacterId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPersistenceComponent_Common_SetCharacterId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPersistenceComponent_Common_SetCharacterId_Statics::NewProp_InCharacterId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistenceComponent_Common_SetCharacterId_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPersistenceComponent_Common_SetCharacterId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPersistenceComponent, nullptr, "Common_SetCharacterId", Z_Construct_UFunction_UPersistenceComponent_Common_SetCharacterId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistenceComponent_Common_SetCharacterId_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPersistenceComponent_Common_SetCharacterId_Statics::PersistenceComponent_eventCommon_SetCharacterId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistenceComponent_Common_SetCharacterId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPersistenceComponent_Common_SetCharacterId_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPersistenceComponent_Common_SetCharacterId_Statics::PersistenceComponent_eventCommon_SetCharacterId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPersistenceComponent_Common_SetCharacterId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPersistenceComponent_Common_SetCharacterId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPersistenceComponent::execCommon_SetCharacterId)
{
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_InCharacterId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Common_SetCharacterId(Z_Param_Out_InCharacterId);
	P_NATIVE_END;
}
// ********** End Class UPersistenceComponent Function Common_SetCharacterId ***********************

// ********** Begin Class UPersistenceComponent Function ServerOnly_CollectCurrentState ************
struct Z_Construct_UFunction_UPersistenceComponent_ServerOnly_CollectCurrentState_Statics
{
	struct PersistenceComponent_eventServerOnly_CollectCurrentState_Parms
	{
		FCommon_StateData ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Persistence" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Collect current state from owner actor\n\x09 * Public so PlayerController can call it on logout\n\x09 * Gathers: Position (GetActorLocation), Rotation (GetActorRotation), Stats (ShipStateComponent)\n\x09 * @return Current state data\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/PersistenceComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Collect current state from owner actor\nPublic so PlayerController can call it on logout\nGathers: Position (GetActorLocation), Rotation (GetActorRotation), Stats (ShipStateComponent)\n@return Current state data" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPersistenceComponent_ServerOnly_CollectCurrentState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PersistenceComponent_eventServerOnly_CollectCurrentState_Parms, ReturnValue), Z_Construct_UScriptStruct_FCommon_StateData, METADATA_PARAMS(0, nullptr) }; // 260765203
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPersistenceComponent_ServerOnly_CollectCurrentState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPersistenceComponent_ServerOnly_CollectCurrentState_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistenceComponent_ServerOnly_CollectCurrentState_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPersistenceComponent_ServerOnly_CollectCurrentState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPersistenceComponent, nullptr, "ServerOnly_CollectCurrentState", Z_Construct_UFunction_UPersistenceComponent_ServerOnly_CollectCurrentState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistenceComponent_ServerOnly_CollectCurrentState_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPersistenceComponent_ServerOnly_CollectCurrentState_Statics::PersistenceComponent_eventServerOnly_CollectCurrentState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistenceComponent_ServerOnly_CollectCurrentState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPersistenceComponent_ServerOnly_CollectCurrentState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPersistenceComponent_ServerOnly_CollectCurrentState_Statics::PersistenceComponent_eventServerOnly_CollectCurrentState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPersistenceComponent_ServerOnly_CollectCurrentState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPersistenceComponent_ServerOnly_CollectCurrentState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPersistenceComponent::execServerOnly_CollectCurrentState)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FCommon_StateData*)Z_Param__Result=P_THIS->ServerOnly_CollectCurrentState();
	P_NATIVE_END;
}
// ********** End Class UPersistenceComponent Function ServerOnly_CollectCurrentState **************

// ********** Begin Class UPersistenceComponent Function ServerOnly_IsDirty ************************
struct Z_Construct_UFunction_UPersistenceComponent_ServerOnly_IsDirty_Statics
{
	struct PersistenceComponent_eventServerOnly_IsDirty_Parms
	{
		FCommon_StateData NewState;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if state has changed enough to trigger a save (dirty flag logic)\n\x09 * @param NewState - New state to compare against last saved state\n\x09 * @return True if state is dirty and should be saved\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/PersistenceComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if state has changed enough to trigger a save (dirty flag logic)\n@param NewState - New state to compare against last saved state\n@return True if state is dirty and should be saved" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NewState_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_NewState;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPersistenceComponent_ServerOnly_IsDirty_Statics::NewProp_NewState = { "NewState", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PersistenceComponent_eventServerOnly_IsDirty_Parms, NewState), Z_Construct_UScriptStruct_FCommon_StateData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NewState_MetaData), NewProp_NewState_MetaData) }; // 260765203
void Z_Construct_UFunction_UPersistenceComponent_ServerOnly_IsDirty_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((PersistenceComponent_eventServerOnly_IsDirty_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPersistenceComponent_ServerOnly_IsDirty_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PersistenceComponent_eventServerOnly_IsDirty_Parms), &Z_Construct_UFunction_UPersistenceComponent_ServerOnly_IsDirty_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPersistenceComponent_ServerOnly_IsDirty_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPersistenceComponent_ServerOnly_IsDirty_Statics::NewProp_NewState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPersistenceComponent_ServerOnly_IsDirty_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistenceComponent_ServerOnly_IsDirty_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPersistenceComponent_ServerOnly_IsDirty_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPersistenceComponent, nullptr, "ServerOnly_IsDirty", Z_Construct_UFunction_UPersistenceComponent_ServerOnly_IsDirty_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistenceComponent_ServerOnly_IsDirty_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPersistenceComponent_ServerOnly_IsDirty_Statics::PersistenceComponent_eventServerOnly_IsDirty_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x40480401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistenceComponent_ServerOnly_IsDirty_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPersistenceComponent_ServerOnly_IsDirty_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UPersistenceComponent_ServerOnly_IsDirty_Statics::PersistenceComponent_eventServerOnly_IsDirty_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPersistenceComponent_ServerOnly_IsDirty()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPersistenceComponent_ServerOnly_IsDirty_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPersistenceComponent::execServerOnly_IsDirty)
{
	P_GET_STRUCT_REF(FCommon_StateData,Z_Param_Out_NewState);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ServerOnly_IsDirty(Z_Param_Out_NewState);
	P_NATIVE_END;
}
// ********** End Class UPersistenceComponent Function ServerOnly_IsDirty **************************

// ********** Begin Class UPersistenceComponent Function ServerOnly_OnHeartbeatTimer ***************
struct Z_Construct_UFunction_UPersistenceComponent_ServerOnly_OnHeartbeatTimer_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Heartbeat save timer callback\n\x09 * Called every HeartbeatInterval seconds\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/PersistenceComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Heartbeat save timer callback\nCalled every HeartbeatInterval seconds" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPersistenceComponent_ServerOnly_OnHeartbeatTimer_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPersistenceComponent, nullptr, "ServerOnly_OnHeartbeatTimer", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistenceComponent_ServerOnly_OnHeartbeatTimer_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPersistenceComponent_ServerOnly_OnHeartbeatTimer_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UPersistenceComponent_ServerOnly_OnHeartbeatTimer()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPersistenceComponent_ServerOnly_OnHeartbeatTimer_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPersistenceComponent::execServerOnly_OnHeartbeatTimer)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerOnly_OnHeartbeatTimer();
	P_NATIVE_END;
}
// ********** End Class UPersistenceComponent Function ServerOnly_OnHeartbeatTimer *****************

// ********** Begin Class UPersistenceComponent Function ServerOnly_TriggerSave ********************
struct Z_Construct_UFunction_UPersistenceComponent_ServerOnly_TriggerSave_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Persistence" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Manually trigger a state save\n\x09 * Can be called from game logic for explicit save points\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/PersistenceComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Manually trigger a state save\nCan be called from game logic for explicit save points" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPersistenceComponent_ServerOnly_TriggerSave_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UPersistenceComponent, nullptr, "ServerOnly_TriggerSave", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPersistenceComponent_ServerOnly_TriggerSave_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPersistenceComponent_ServerOnly_TriggerSave_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UPersistenceComponent_ServerOnly_TriggerSave()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPersistenceComponent_ServerOnly_TriggerSave_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPersistenceComponent::execServerOnly_TriggerSave)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerOnly_TriggerSave();
	P_NATIVE_END;
}
// ********** End Class UPersistenceComponent Function ServerOnly_TriggerSave **********************

// ********** Begin Class UPersistenceComponent ****************************************************
void UPersistenceComponent::StaticRegisterNativesUPersistenceComponent()
{
	UClass* Class = UPersistenceComponent::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "Common_SetCharacterId", &UPersistenceComponent::execCommon_SetCharacterId },
		{ "ServerOnly_CollectCurrentState", &UPersistenceComponent::execServerOnly_CollectCurrentState },
		{ "ServerOnly_IsDirty", &UPersistenceComponent::execServerOnly_IsDirty },
		{ "ServerOnly_OnHeartbeatTimer", &UPersistenceComponent::execServerOnly_OnHeartbeatTimer },
		{ "ServerOnly_TriggerSave", &UPersistenceComponent::execServerOnly_TriggerSave },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UPersistenceComponent;
UClass* UPersistenceComponent::GetPrivateStaticClass()
{
	using TClass = UPersistenceComponent;
	if (!Z_Registration_Info_UClass_UPersistenceComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("PersistenceComponent"),
			Z_Registration_Info_UClass_UPersistenceComponent.InnerSingleton,
			StaticRegisterNativesUPersistenceComponent,
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
	return Z_Registration_Info_UClass_UPersistenceComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UPersistenceComponent_NoRegister()
{
	return UPersistenceComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UPersistenceComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Echoes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * UPersistenceComponent\n * \n * Lightweight component for collecting character state data\n * Refactored to use UEchoesPersistenceSubsystem for HTTP communication\n * \n * Architecture:\n * - Component: Collects state data (position, rotation, stats)\n * - Subsystem: Handles HTTP requests, queuing, authentication\n * - PlayerController: Triggers final save on logout\n * \n * Features:\n * - Heartbeat Save: Auto-save every 60 seconds (calls subsystem)\n * - Dirty Flag: Only save when position changed >1m or stats changed\n * - Data Collection: Gathers position, rotation, and stats from ship\n * \n * Note: This component NO LONGER handles HTTP requests directly.\n * All network communication goes through UEchoesPersistenceSubsystem.\n * \n * Naming Convention:\n * - ServerOnly_ prefix: Methods that only run on server\n * - Common_ prefix: Data structures/methods that run on any context\n */" },
#endif
		{ "IncludePath", "Core/Common/Components/PersistenceComponent.h" },
		{ "ModuleRelativePath", "Core/Common/Components/PersistenceComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UPersistenceComponent\n\nLightweight component for collecting character state data\nRefactored to use UEchoesPersistenceSubsystem for HTTP communication\n\nArchitecture:\n- Component: Collects state data (position, rotation, stats)\n- Subsystem: Handles HTTP requests, queuing, authentication\n- PlayerController: Triggers final save on logout\n\nFeatures:\n- Heartbeat Save: Auto-save every 60 seconds (calls subsystem)\n- Dirty Flag: Only save when position changed >1m or stats changed\n- Data Collection: Gathers position, rotation, and stats from ship\n\nNote: This component NO LONGER handles HTTP requests directly.\nAll network communication goes through UEchoesPersistenceSubsystem.\n\nNaming Convention:\n- ServerOnly_ prefix: Methods that only run on server\n- Common_ prefix: Data structures/methods that run on any context" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterId_MetaData[] = {
		{ "Category", "Persistence|Config" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Character ID for this persistence instance */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/PersistenceComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Character ID for this persistence instance" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HeartbeatInterval_MetaData[] = {
		{ "Category", "Persistence|Config" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Heartbeat save interval in seconds (auto-save timer) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/PersistenceComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Heartbeat save interval in seconds (auto-save timer)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DirtyPositionThreshold_MetaData[] = {
		{ "Category", "Persistence|Config" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Minimum position change in centimeters to trigger dirty flag */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/PersistenceComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Minimum position change in centimeters to trigger dirty flag" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableHeartbeat_MetaData[] = {
		{ "Category", "Persistence|Config" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether to enable heartbeat auto-save */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/PersistenceComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether to enable heartbeat auto-save" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableDirtyFlag_MetaData[] = {
		{ "Category", "Persistence|Config" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether to enable dirty flag optimization */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/PersistenceComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether to enable dirty flag optimization" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultCapacitorValue_MetaData[] = {
		{ "Category", "Persistence|Config" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Default capacitor value to use when actual capacitor component is not available\n\x09 * This is a temporary fallback until ship power/capacitor component is implemented\n\x09 * Typical values: Frigate ~1000-1500, Cruiser ~2000-3000, Battleship ~5000-7000\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/PersistenceComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Default capacitor value to use when actual capacitor component is not available\nThis is a temporary fallback until ship power/capacitor component is implemented\nTypical values: Frigate ~1000-1500, Cruiser ~2000-3000, Battleship ~5000-7000" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CachedStatsComponent_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Cached reference to ship stats component */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/Components/PersistenceComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cached reference to ship stats component" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PersistenceSubsystem_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Cached reference to persistence subsystem */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/PersistenceComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cached reference to persistence subsystem" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_CharacterId;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HeartbeatInterval;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DirtyPositionThreshold;
	static void NewProp_bEnableHeartbeat_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableHeartbeat;
	static void NewProp_bEnableDirtyFlag_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableDirtyFlag;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DefaultCapacitorValue;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CachedStatsComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PersistenceSubsystem;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UPersistenceComponent_Common_SetCharacterId, "Common_SetCharacterId" }, // 951949380
		{ &Z_Construct_UFunction_UPersistenceComponent_ServerOnly_CollectCurrentState, "ServerOnly_CollectCurrentState" }, // 657511316
		{ &Z_Construct_UFunction_UPersistenceComponent_ServerOnly_IsDirty, "ServerOnly_IsDirty" }, // 602082878
		{ &Z_Construct_UFunction_UPersistenceComponent_ServerOnly_OnHeartbeatTimer, "ServerOnly_OnHeartbeatTimer" }, // 1432761518
		{ &Z_Construct_UFunction_UPersistenceComponent_ServerOnly_TriggerSave, "ServerOnly_TriggerSave" }, // 2780672718
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPersistenceComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPersistenceComponent_Statics::NewProp_CharacterId = { "CharacterId", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPersistenceComponent, CharacterId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterId_MetaData), NewProp_CharacterId_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPersistenceComponent_Statics::NewProp_HeartbeatInterval = { "HeartbeatInterval", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPersistenceComponent, HeartbeatInterval), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HeartbeatInterval_MetaData), NewProp_HeartbeatInterval_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPersistenceComponent_Statics::NewProp_DirtyPositionThreshold = { "DirtyPositionThreshold", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPersistenceComponent, DirtyPositionThreshold), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DirtyPositionThreshold_MetaData), NewProp_DirtyPositionThreshold_MetaData) };
void Z_Construct_UClass_UPersistenceComponent_Statics::NewProp_bEnableHeartbeat_SetBit(void* Obj)
{
	((UPersistenceComponent*)Obj)->bEnableHeartbeat = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPersistenceComponent_Statics::NewProp_bEnableHeartbeat = { "bEnableHeartbeat", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPersistenceComponent), &Z_Construct_UClass_UPersistenceComponent_Statics::NewProp_bEnableHeartbeat_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableHeartbeat_MetaData), NewProp_bEnableHeartbeat_MetaData) };
void Z_Construct_UClass_UPersistenceComponent_Statics::NewProp_bEnableDirtyFlag_SetBit(void* Obj)
{
	((UPersistenceComponent*)Obj)->bEnableDirtyFlag = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPersistenceComponent_Statics::NewProp_bEnableDirtyFlag = { "bEnableDirtyFlag", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPersistenceComponent), &Z_Construct_UClass_UPersistenceComponent_Statics::NewProp_bEnableDirtyFlag_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableDirtyFlag_MetaData), NewProp_bEnableDirtyFlag_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPersistenceComponent_Statics::NewProp_DefaultCapacitorValue = { "DefaultCapacitorValue", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPersistenceComponent, DefaultCapacitorValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultCapacitorValue_MetaData), NewProp_DefaultCapacitorValue_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPersistenceComponent_Statics::NewProp_CachedStatsComponent = { "CachedStatsComponent", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPersistenceComponent, CachedStatsComponent), Z_Construct_UClass_UEchoesStatsComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CachedStatsComponent_MetaData), NewProp_CachedStatsComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPersistenceComponent_Statics::NewProp_PersistenceSubsystem = { "PersistenceSubsystem", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPersistenceComponent, PersistenceSubsystem), Z_Construct_UClass_UEchoesPersistenceSubsystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PersistenceSubsystem_MetaData), NewProp_PersistenceSubsystem_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPersistenceComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPersistenceComponent_Statics::NewProp_CharacterId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPersistenceComponent_Statics::NewProp_HeartbeatInterval,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPersistenceComponent_Statics::NewProp_DirtyPositionThreshold,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPersistenceComponent_Statics::NewProp_bEnableHeartbeat,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPersistenceComponent_Statics::NewProp_bEnableDirtyFlag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPersistenceComponent_Statics::NewProp_DefaultCapacitorValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPersistenceComponent_Statics::NewProp_CachedStatsComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPersistenceComponent_Statics::NewProp_PersistenceSubsystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPersistenceComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UPersistenceComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPersistenceComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UPersistenceComponent_Statics::ClassParams = {
	&UPersistenceComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UPersistenceComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UPersistenceComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPersistenceComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UPersistenceComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UPersistenceComponent()
{
	if (!Z_Registration_Info_UClass_UPersistenceComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPersistenceComponent.OuterSingleton, Z_Construct_UClass_UPersistenceComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UPersistenceComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UPersistenceComponent);
UPersistenceComponent::~UPersistenceComponent() {}
// ********** End Class UPersistenceComponent ******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_PersistenceComponent_h__Script_Echoes_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FCommon_StateData::StaticStruct, Z_Construct_UScriptStruct_FCommon_StateData_Statics::NewStructOps, TEXT("Common_StateData"), &Z_Registration_Info_UScriptStruct_FCommon_StateData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FCommon_StateData), 260765203U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UPersistenceComponent, UPersistenceComponent::StaticClass, TEXT("UPersistenceComponent"), &Z_Registration_Info_UClass_UPersistenceComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPersistenceComponent), 1642700150U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_PersistenceComponent_h__Script_Echoes_2059504217(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_PersistenceComponent_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_PersistenceComponent_h__Script_Echoes_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_PersistenceComponent_h__Script_Echoes_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_PersistenceComponent_h__Script_Echoes_Statics::ScriptStructInfo),
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
