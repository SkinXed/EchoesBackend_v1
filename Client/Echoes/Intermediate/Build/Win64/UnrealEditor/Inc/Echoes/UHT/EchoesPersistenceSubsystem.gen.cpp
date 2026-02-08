// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EchoesPersistenceSubsystem.h"
#include "Engine/GameInstance.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesPersistenceSubsystem() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FDateTime();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ECHOES_API UClass* Z_Construct_UClass_UEchoesPersistenceSubsystem();
ECHOES_API UClass* Z_Construct_UClass_UEchoesPersistenceSubsystem_NoRegister();
ECHOES_API UEnum* Z_Construct_UEnum_Echoes_EPersistenceSyncState();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnPersistenceStateSynced__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnPersistenceSyncFailed__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnWalletBalanceChanged__DelegateSignature();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FPersistenceCharacterState();
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FPersistenceCharacterState ****************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FPersistenceCharacterState;
class UScriptStruct* FPersistenceCharacterState::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FPersistenceCharacterState.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FPersistenceCharacterState.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPersistenceCharacterState, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("PersistenceCharacterState"));
	}
	return Z_Registration_Info_UScriptStruct_FPersistenceCharacterState.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FPersistenceCharacterState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Snapshot of persisted character state from backend\n * Mirrors the data returned by GET /api/character/me\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesPersistenceSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Snapshot of persisted character state from backend\nMirrors the data returned by GET /api/character/me" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterId_MetaData[] = {
		{ "Category", "Persistence" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesPersistenceSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WalletBalance_MetaData[] = {
		{ "Category", "Persistence" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesPersistenceSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IsDocked_MetaData[] = {
		{ "Category", "Persistence" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesPersistenceSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LastSyncTime_MetaData[] = {
		{ "Category", "Persistence" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesPersistenceSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsValid_MetaData[] = {
		{ "Category", "Persistence" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesPersistenceSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_CharacterId;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_WalletBalance;
	static void NewProp_IsDocked_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_IsDocked;
	static const UECodeGen_Private::FStructPropertyParams NewProp_LastSyncTime;
	static void NewProp_bIsValid_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsValid;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPersistenceCharacterState>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPersistenceCharacterState_Statics::NewProp_CharacterId = { "CharacterId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPersistenceCharacterState, CharacterId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterId_MetaData), NewProp_CharacterId_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FPersistenceCharacterState_Statics::NewProp_WalletBalance = { "WalletBalance", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPersistenceCharacterState, WalletBalance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WalletBalance_MetaData), NewProp_WalletBalance_MetaData) };
void Z_Construct_UScriptStruct_FPersistenceCharacterState_Statics::NewProp_IsDocked_SetBit(void* Obj)
{
	((FPersistenceCharacterState*)Obj)->IsDocked = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FPersistenceCharacterState_Statics::NewProp_IsDocked = { "IsDocked", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FPersistenceCharacterState), &Z_Construct_UScriptStruct_FPersistenceCharacterState_Statics::NewProp_IsDocked_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IsDocked_MetaData), NewProp_IsDocked_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPersistenceCharacterState_Statics::NewProp_LastSyncTime = { "LastSyncTime", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPersistenceCharacterState, LastSyncTime), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LastSyncTime_MetaData), NewProp_LastSyncTime_MetaData) };
void Z_Construct_UScriptStruct_FPersistenceCharacterState_Statics::NewProp_bIsValid_SetBit(void* Obj)
{
	((FPersistenceCharacterState*)Obj)->bIsValid = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FPersistenceCharacterState_Statics::NewProp_bIsValid = { "bIsValid", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FPersistenceCharacterState), &Z_Construct_UScriptStruct_FPersistenceCharacterState_Statics::NewProp_bIsValid_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsValid_MetaData), NewProp_bIsValid_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPersistenceCharacterState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPersistenceCharacterState_Statics::NewProp_CharacterId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPersistenceCharacterState_Statics::NewProp_WalletBalance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPersistenceCharacterState_Statics::NewProp_IsDocked,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPersistenceCharacterState_Statics::NewProp_LastSyncTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPersistenceCharacterState_Statics::NewProp_bIsValid,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPersistenceCharacterState_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPersistenceCharacterState_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"PersistenceCharacterState",
	Z_Construct_UScriptStruct_FPersistenceCharacterState_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPersistenceCharacterState_Statics::PropPointers),
	sizeof(FPersistenceCharacterState),
	alignof(FPersistenceCharacterState),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPersistenceCharacterState_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPersistenceCharacterState_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FPersistenceCharacterState()
{
	if (!Z_Registration_Info_UScriptStruct_FPersistenceCharacterState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FPersistenceCharacterState.InnerSingleton, Z_Construct_UScriptStruct_FPersistenceCharacterState_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FPersistenceCharacterState.InnerSingleton;
}
// ********** End ScriptStruct FPersistenceCharacterState ******************************************

// ********** Begin Enum EPersistenceSyncState *****************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPersistenceSyncState;
static UEnum* EPersistenceSyncState_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EPersistenceSyncState.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EPersistenceSyncState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Echoes_EPersistenceSyncState, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("EPersistenceSyncState"));
	}
	return Z_Registration_Info_UEnum_EPersistenceSyncState.OuterSingleton;
}
template<> ECHOES_API UEnum* StaticEnum<EPersistenceSyncState>()
{
	return EPersistenceSyncState_StaticEnum();
}
struct Z_Construct_UEnum_Echoes_EPersistenceSyncState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sync operation state */" },
#endif
		{ "Error.Name", "EPersistenceSyncState::Error" },
		{ "Idle.Name", "EPersistenceSyncState::Idle" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesPersistenceSubsystem.h" },
		{ "Syncing.Name", "EPersistenceSyncState::Syncing" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sync operation state" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EPersistenceSyncState::Idle", (int64)EPersistenceSyncState::Idle },
		{ "EPersistenceSyncState::Syncing", (int64)EPersistenceSyncState::Syncing },
		{ "EPersistenceSyncState::Error", (int64)EPersistenceSyncState::Error },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Echoes_EPersistenceSyncState_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	"EPersistenceSyncState",
	"EPersistenceSyncState",
	Z_Construct_UEnum_Echoes_EPersistenceSyncState_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_Echoes_EPersistenceSyncState_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_Echoes_EPersistenceSyncState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_Echoes_EPersistenceSyncState_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_Echoes_EPersistenceSyncState()
{
	if (!Z_Registration_Info_UEnum_EPersistenceSyncState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPersistenceSyncState.InnerSingleton, Z_Construct_UEnum_Echoes_EPersistenceSyncState_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EPersistenceSyncState.InnerSingleton;
}
// ********** End Enum EPersistenceSyncState *******************************************************

// ********** Begin Delegate FOnPersistenceStateSynced *********************************************
struct Z_Construct_UDelegateFunction_Echoes_OnPersistenceStateSynced__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnPersistenceStateSynced_Parms
	{
		FPersistenceCharacterState State;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when character state is successfully synced from backend */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesPersistenceSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when character state is successfully synced from backend" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_State_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_State;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_Echoes_OnPersistenceStateSynced__DelegateSignature_Statics::NewProp_State = { "State", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnPersistenceStateSynced_Parms, State), Z_Construct_UScriptStruct_FPersistenceCharacterState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_State_MetaData), NewProp_State_MetaData) }; // 2939598702
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnPersistenceStateSynced__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnPersistenceStateSynced__DelegateSignature_Statics::NewProp_State,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnPersistenceStateSynced__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnPersistenceStateSynced__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnPersistenceStateSynced__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnPersistenceStateSynced__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnPersistenceStateSynced__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnPersistenceStateSynced__DelegateSignature_Statics::_Script_Echoes_eventOnPersistenceStateSynced_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnPersistenceStateSynced__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnPersistenceStateSynced__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnPersistenceStateSynced__DelegateSignature_Statics::_Script_Echoes_eventOnPersistenceStateSynced_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnPersistenceStateSynced__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnPersistenceStateSynced__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnPersistenceStateSynced_DelegateWrapper(const FMulticastScriptDelegate& OnPersistenceStateSynced, FPersistenceCharacterState const& State)
{
	struct _Script_Echoes_eventOnPersistenceStateSynced_Parms
	{
		FPersistenceCharacterState State;
	};
	_Script_Echoes_eventOnPersistenceStateSynced_Parms Parms;
	Parms.State=State;
	OnPersistenceStateSynced.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnPersistenceStateSynced ***********************************************

// ********** Begin Delegate FOnPersistenceSyncFailed **********************************************
struct Z_Construct_UDelegateFunction_Echoes_OnPersistenceSyncFailed__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnPersistenceSyncFailed_Parms
	{
		FString ErrorMessage;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when a persistence sync operation fails */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesPersistenceSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when a persistence sync operation fails" },
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
const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_Echoes_OnPersistenceSyncFailed__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnPersistenceSyncFailed_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ErrorMessage_MetaData), NewProp_ErrorMessage_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnPersistenceSyncFailed__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnPersistenceSyncFailed__DelegateSignature_Statics::NewProp_ErrorMessage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnPersistenceSyncFailed__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnPersistenceSyncFailed__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnPersistenceSyncFailed__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnPersistenceSyncFailed__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnPersistenceSyncFailed__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnPersistenceSyncFailed__DelegateSignature_Statics::_Script_Echoes_eventOnPersistenceSyncFailed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnPersistenceSyncFailed__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnPersistenceSyncFailed__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnPersistenceSyncFailed__DelegateSignature_Statics::_Script_Echoes_eventOnPersistenceSyncFailed_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnPersistenceSyncFailed__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnPersistenceSyncFailed__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnPersistenceSyncFailed_DelegateWrapper(const FMulticastScriptDelegate& OnPersistenceSyncFailed, const FString& ErrorMessage)
{
	struct _Script_Echoes_eventOnPersistenceSyncFailed_Parms
	{
		FString ErrorMessage;
	};
	_Script_Echoes_eventOnPersistenceSyncFailed_Parms Parms;
	Parms.ErrorMessage=ErrorMessage;
	OnPersistenceSyncFailed.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnPersistenceSyncFailed ************************************************

// ********** Begin Delegate FOnWalletBalanceChanged ***********************************************
struct Z_Construct_UDelegateFunction_Echoes_OnWalletBalanceChanged__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnWalletBalanceChanged_Parms
	{
		int64 OldBalance;
		int64 NewBalance;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when wallet balance changes after sync */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesPersistenceSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when wallet balance changes after sync" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FInt64PropertyParams NewProp_OldBalance;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_NewBalance;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UDelegateFunction_Echoes_OnWalletBalanceChanged__DelegateSignature_Statics::NewProp_OldBalance = { "OldBalance", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnWalletBalanceChanged_Parms, OldBalance), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UDelegateFunction_Echoes_OnWalletBalanceChanged__DelegateSignature_Statics::NewProp_NewBalance = { "NewBalance", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnWalletBalanceChanged_Parms, NewBalance), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnWalletBalanceChanged__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnWalletBalanceChanged__DelegateSignature_Statics::NewProp_OldBalance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnWalletBalanceChanged__DelegateSignature_Statics::NewProp_NewBalance,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnWalletBalanceChanged__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnWalletBalanceChanged__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnWalletBalanceChanged__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnWalletBalanceChanged__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnWalletBalanceChanged__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnWalletBalanceChanged__DelegateSignature_Statics::_Script_Echoes_eventOnWalletBalanceChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnWalletBalanceChanged__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnWalletBalanceChanged__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnWalletBalanceChanged__DelegateSignature_Statics::_Script_Echoes_eventOnWalletBalanceChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnWalletBalanceChanged__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnWalletBalanceChanged__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnWalletBalanceChanged_DelegateWrapper(const FMulticastScriptDelegate& OnWalletBalanceChanged, int64 OldBalance, int64 NewBalance)
{
	struct _Script_Echoes_eventOnWalletBalanceChanged_Parms
	{
		int64 OldBalance;
		int64 NewBalance;
	};
	_Script_Echoes_eventOnWalletBalanceChanged_Parms Parms;
	Parms.OldBalance=OldBalance;
	Parms.NewBalance=NewBalance;
	OnWalletBalanceChanged.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnWalletBalanceChanged *************************************************

// ********** Begin Class UEchoesPersistenceSubsystem Function GetCachedState **********************
struct Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetCachedState_Statics
{
	struct EchoesPersistenceSubsystem_eventGetCachedState_Parms
	{
		FPersistenceCharacterState ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Persistence" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the last synced character state\n\x09 * @return Cached persistence state (may be stale if not recently synced)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesPersistenceSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the last synced character state\n@return Cached persistence state (may be stale if not recently synced)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetCachedState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesPersistenceSubsystem_eventGetCachedState_Parms, ReturnValue), Z_Construct_UScriptStruct_FPersistenceCharacterState, METADATA_PARAMS(0, nullptr) }; // 2939598702
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetCachedState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetCachedState_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetCachedState_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetCachedState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesPersistenceSubsystem, nullptr, "GetCachedState", Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetCachedState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetCachedState_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetCachedState_Statics::EchoesPersistenceSubsystem_eventGetCachedState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetCachedState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetCachedState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetCachedState_Statics::EchoesPersistenceSubsystem_eventGetCachedState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetCachedState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetCachedState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesPersistenceSubsystem::execGetCachedState)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FPersistenceCharacterState*)Z_Param__Result=P_THIS->GetCachedState();
	P_NATIVE_END;
}
// ********** End Class UEchoesPersistenceSubsystem Function GetCachedState ************************

// ********** Begin Class UEchoesPersistenceSubsystem Function GetSyncState ************************
struct Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetSyncState_Statics
{
	struct EchoesPersistenceSubsystem_eventGetSyncState_Parms
	{
		EPersistenceSyncState ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Persistence" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the current sync state\n\x09 * @return Current sync operation state\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesPersistenceSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the current sync state\n@return Current sync operation state" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetSyncState_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetSyncState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesPersistenceSubsystem_eventGetSyncState_Parms, ReturnValue), Z_Construct_UEnum_Echoes_EPersistenceSyncState, METADATA_PARAMS(0, nullptr) }; // 1343187979
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetSyncState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetSyncState_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetSyncState_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetSyncState_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetSyncState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesPersistenceSubsystem, nullptr, "GetSyncState", Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetSyncState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetSyncState_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetSyncState_Statics::EchoesPersistenceSubsystem_eventGetSyncState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetSyncState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetSyncState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetSyncState_Statics::EchoesPersistenceSubsystem_eventGetSyncState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetSyncState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetSyncState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesPersistenceSubsystem::execGetSyncState)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EPersistenceSyncState*)Z_Param__Result=P_THIS->GetSyncState();
	P_NATIVE_END;
}
// ********** End Class UEchoesPersistenceSubsystem Function GetSyncState **************************

// ********** Begin Class UEchoesPersistenceSubsystem Function GetTimeSinceLastSync ****************
struct Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetTimeSinceLastSync_Statics
{
	struct EchoesPersistenceSubsystem_eventGetTimeSinceLastSync_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Persistence" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get time since last successful sync\n\x09 * @return Seconds since last sync, or -1 if never synced\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesPersistenceSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get time since last successful sync\n@return Seconds since last sync, or -1 if never synced" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetTimeSinceLastSync_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesPersistenceSubsystem_eventGetTimeSinceLastSync_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetTimeSinceLastSync_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetTimeSinceLastSync_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetTimeSinceLastSync_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetTimeSinceLastSync_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesPersistenceSubsystem, nullptr, "GetTimeSinceLastSync", Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetTimeSinceLastSync_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetTimeSinceLastSync_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetTimeSinceLastSync_Statics::EchoesPersistenceSubsystem_eventGetTimeSinceLastSync_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetTimeSinceLastSync_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetTimeSinceLastSync_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetTimeSinceLastSync_Statics::EchoesPersistenceSubsystem_eventGetTimeSinceLastSync_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetTimeSinceLastSync()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetTimeSinceLastSync_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesPersistenceSubsystem::execGetTimeSinceLastSync)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetTimeSinceLastSync();
	P_NATIVE_END;
}
// ********** End Class UEchoesPersistenceSubsystem Function GetTimeSinceLastSync ******************

// ********** Begin Class UEchoesPersistenceSubsystem Function HandleMarketInventorySync ***********
struct Z_Construct_UFunction_UEchoesPersistenceSubsystem_HandleMarketInventorySync_Statics
{
	struct EchoesPersistenceSubsystem_eventHandleMarketInventorySync_Parms
	{
		FGuid CharacterId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Handler for OnInventorySyncRequired from MarketSubsystem */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesPersistenceSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handler for OnInventorySyncRequired from MarketSubsystem" },
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
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesPersistenceSubsystem_HandleMarketInventorySync_Statics::NewProp_CharacterId = { "CharacterId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesPersistenceSubsystem_eventHandleMarketInventorySync_Parms, CharacterId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterId_MetaData), NewProp_CharacterId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesPersistenceSubsystem_HandleMarketInventorySync_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesPersistenceSubsystem_HandleMarketInventorySync_Statics::NewProp_CharacterId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesPersistenceSubsystem_HandleMarketInventorySync_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesPersistenceSubsystem_HandleMarketInventorySync_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesPersistenceSubsystem, nullptr, "HandleMarketInventorySync", Z_Construct_UFunction_UEchoesPersistenceSubsystem_HandleMarketInventorySync_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesPersistenceSubsystem_HandleMarketInventorySync_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesPersistenceSubsystem_HandleMarketInventorySync_Statics::EchoesPersistenceSubsystem_eventHandleMarketInventorySync_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C40401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesPersistenceSubsystem_HandleMarketInventorySync_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesPersistenceSubsystem_HandleMarketInventorySync_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesPersistenceSubsystem_HandleMarketInventorySync_Statics::EchoesPersistenceSubsystem_eventHandleMarketInventorySync_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesPersistenceSubsystem_HandleMarketInventorySync()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesPersistenceSubsystem_HandleMarketInventorySync_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesPersistenceSubsystem::execHandleMarketInventorySync)
{
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_CharacterId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleMarketInventorySync(Z_Param_Out_CharacterId);
	P_NATIVE_END;
}
// ********** End Class UEchoesPersistenceSubsystem Function HandleMarketInventorySync *************

// ********** Begin Class UEchoesPersistenceSubsystem Function IsStateValid ************************
struct Z_Construct_UFunction_UEchoesPersistenceSubsystem_IsStateValid_Statics
{
	struct EchoesPersistenceSubsystem_eventIsStateValid_Parms
	{
		float MaxAgeSeconds;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Persistence" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if cached state is valid and not stale\n\x09 * @param MaxAgeSeconds - Maximum age in seconds before considered stale (default: 60)\n\x09 * @return True if state is valid and within max age\n\x09 */" },
#endif
		{ "CPP_Default_MaxAgeSeconds", "60.000000" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesPersistenceSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if cached state is valid and not stale\n@param MaxAgeSeconds - Maximum age in seconds before considered stale (default: 60)\n@return True if state is valid and within max age" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxAgeSeconds;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UEchoesPersistenceSubsystem_IsStateValid_Statics::NewProp_MaxAgeSeconds = { "MaxAgeSeconds", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesPersistenceSubsystem_eventIsStateValid_Parms, MaxAgeSeconds), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UEchoesPersistenceSubsystem_IsStateValid_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((EchoesPersistenceSubsystem_eventIsStateValid_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UEchoesPersistenceSubsystem_IsStateValid_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EchoesPersistenceSubsystem_eventIsStateValid_Parms), &Z_Construct_UFunction_UEchoesPersistenceSubsystem_IsStateValid_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesPersistenceSubsystem_IsStateValid_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesPersistenceSubsystem_IsStateValid_Statics::NewProp_MaxAgeSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesPersistenceSubsystem_IsStateValid_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesPersistenceSubsystem_IsStateValid_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesPersistenceSubsystem_IsStateValid_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesPersistenceSubsystem, nullptr, "IsStateValid", Z_Construct_UFunction_UEchoesPersistenceSubsystem_IsStateValid_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesPersistenceSubsystem_IsStateValid_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesPersistenceSubsystem_IsStateValid_Statics::EchoesPersistenceSubsystem_eventIsStateValid_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesPersistenceSubsystem_IsStateValid_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesPersistenceSubsystem_IsStateValid_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesPersistenceSubsystem_IsStateValid_Statics::EchoesPersistenceSubsystem_eventIsStateValid_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesPersistenceSubsystem_IsStateValid()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesPersistenceSubsystem_IsStateValid_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesPersistenceSubsystem::execIsStateValid)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_MaxAgeSeconds);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsStateValid(Z_Param_MaxAgeSeconds);
	P_NATIVE_END;
}
// ********** End Class UEchoesPersistenceSubsystem Function IsStateValid **************************

// ********** Begin Class UEchoesPersistenceSubsystem Function ServerOnly_ForceSaveState ***********
struct Z_Construct_UFunction_UEchoesPersistenceSubsystem_ServerOnly_ForceSaveState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Persistence" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Force synchronize character state from the backend database\n\x09 * Fetches latest wallet balance and character state via GET /api/character/me\n\x09 * Triggers inventory cache refresh via InventorySubsystem\n\x09 * Prevents duplicate requests while a sync is in-flight\n\x09 * \n\x09 * Call this after any operation that mutates server-side state (trades, purchases, etc.)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesPersistenceSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Force synchronize character state from the backend database\nFetches latest wallet balance and character state via GET /api/character/me\nTriggers inventory cache refresh via InventorySubsystem\nPrevents duplicate requests while a sync is in-flight\n\nCall this after any operation that mutates server-side state (trades, purchases, etc.)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesPersistenceSubsystem_ServerOnly_ForceSaveState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesPersistenceSubsystem, nullptr, "ServerOnly_ForceSaveState", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesPersistenceSubsystem_ServerOnly_ForceSaveState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesPersistenceSubsystem_ServerOnly_ForceSaveState_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesPersistenceSubsystem_ServerOnly_ForceSaveState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesPersistenceSubsystem_ServerOnly_ForceSaveState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesPersistenceSubsystem::execServerOnly_ForceSaveState)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerOnly_ForceSaveState();
	P_NATIVE_END;
}
// ********** End Class UEchoesPersistenceSubsystem Function ServerOnly_ForceSaveState *************

// ********** Begin Class UEchoesPersistenceSubsystem Function ServerOnly_ForceSaveStateForCharacter 
struct Z_Construct_UFunction_UEchoesPersistenceSubsystem_ServerOnly_ForceSaveStateForCharacter_Statics
{
	struct EchoesPersistenceSubsystem_eventServerOnly_ForceSaveStateForCharacter_Parms
	{
		FGuid CharacterId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Persistence" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Force sync for a specific character by ID\n\x09 * Used by MarketSubsystem.OnInventorySyncRequired delegate\n\x09 * \n\x09 * @param CharacterId - Character whose state needs syncing\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesPersistenceSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Force sync for a specific character by ID\nUsed by MarketSubsystem.OnInventorySyncRequired delegate\n\n@param CharacterId - Character whose state needs syncing" },
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
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesPersistenceSubsystem_ServerOnly_ForceSaveStateForCharacter_Statics::NewProp_CharacterId = { "CharacterId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesPersistenceSubsystem_eventServerOnly_ForceSaveStateForCharacter_Parms, CharacterId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterId_MetaData), NewProp_CharacterId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesPersistenceSubsystem_ServerOnly_ForceSaveStateForCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesPersistenceSubsystem_ServerOnly_ForceSaveStateForCharacter_Statics::NewProp_CharacterId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesPersistenceSubsystem_ServerOnly_ForceSaveStateForCharacter_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesPersistenceSubsystem_ServerOnly_ForceSaveStateForCharacter_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesPersistenceSubsystem, nullptr, "ServerOnly_ForceSaveStateForCharacter", Z_Construct_UFunction_UEchoesPersistenceSubsystem_ServerOnly_ForceSaveStateForCharacter_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesPersistenceSubsystem_ServerOnly_ForceSaveStateForCharacter_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesPersistenceSubsystem_ServerOnly_ForceSaveStateForCharacter_Statics::EchoesPersistenceSubsystem_eventServerOnly_ForceSaveStateForCharacter_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesPersistenceSubsystem_ServerOnly_ForceSaveStateForCharacter_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesPersistenceSubsystem_ServerOnly_ForceSaveStateForCharacter_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesPersistenceSubsystem_ServerOnly_ForceSaveStateForCharacter_Statics::EchoesPersistenceSubsystem_eventServerOnly_ForceSaveStateForCharacter_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesPersistenceSubsystem_ServerOnly_ForceSaveStateForCharacter()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesPersistenceSubsystem_ServerOnly_ForceSaveStateForCharacter_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesPersistenceSubsystem::execServerOnly_ForceSaveStateForCharacter)
{
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_CharacterId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerOnly_ForceSaveStateForCharacter(Z_Param_Out_CharacterId);
	P_NATIVE_END;
}
// ********** End Class UEchoesPersistenceSubsystem Function ServerOnly_ForceSaveStateForCharacter *

// ********** Begin Class UEchoesPersistenceSubsystem Function ServerOnly_SyncWallet ***************
struct Z_Construct_UFunction_UEchoesPersistenceSubsystem_ServerOnly_SyncWallet_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Persistence" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Sync only the wallet balance (lightweight, no inventory refresh)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesPersistenceSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sync only the wallet balance (lightweight, no inventory refresh)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesPersistenceSubsystem_ServerOnly_SyncWallet_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesPersistenceSubsystem, nullptr, "ServerOnly_SyncWallet", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesPersistenceSubsystem_ServerOnly_SyncWallet_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesPersistenceSubsystem_ServerOnly_SyncWallet_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesPersistenceSubsystem_ServerOnly_SyncWallet()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesPersistenceSubsystem_ServerOnly_SyncWallet_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesPersistenceSubsystem::execServerOnly_SyncWallet)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerOnly_SyncWallet();
	P_NATIVE_END;
}
// ********** End Class UEchoesPersistenceSubsystem Function ServerOnly_SyncWallet *****************

// ********** Begin Class UEchoesPersistenceSubsystem **********************************************
void UEchoesPersistenceSubsystem::StaticRegisterNativesUEchoesPersistenceSubsystem()
{
	UClass* Class = UEchoesPersistenceSubsystem::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetCachedState", &UEchoesPersistenceSubsystem::execGetCachedState },
		{ "GetSyncState", &UEchoesPersistenceSubsystem::execGetSyncState },
		{ "GetTimeSinceLastSync", &UEchoesPersistenceSubsystem::execGetTimeSinceLastSync },
		{ "HandleMarketInventorySync", &UEchoesPersistenceSubsystem::execHandleMarketInventorySync },
		{ "IsStateValid", &UEchoesPersistenceSubsystem::execIsStateValid },
		{ "ServerOnly_ForceSaveState", &UEchoesPersistenceSubsystem::execServerOnly_ForceSaveState },
		{ "ServerOnly_ForceSaveStateForCharacter", &UEchoesPersistenceSubsystem::execServerOnly_ForceSaveStateForCharacter },
		{ "ServerOnly_SyncWallet", &UEchoesPersistenceSubsystem::execServerOnly_SyncWallet },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UEchoesPersistenceSubsystem;
UClass* UEchoesPersistenceSubsystem::GetPrivateStaticClass()
{
	using TClass = UEchoesPersistenceSubsystem;
	if (!Z_Registration_Info_UClass_UEchoesPersistenceSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesPersistenceSubsystem"),
			Z_Registration_Info_UClass_UEchoesPersistenceSubsystem.InnerSingleton,
			StaticRegisterNativesUEchoesPersistenceSubsystem,
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
	return Z_Registration_Info_UClass_UEchoesPersistenceSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UEchoesPersistenceSubsystem_NoRegister()
{
	return UEchoesPersistenceSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UEchoesPersistenceSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * UEchoesPersistenceSubsystem\n * \n * State persistence and synchronization subsystem for Echoes MMO\n * Provides centralized wallet/inventory state refresh from ASP.NET backend\n * \n * Architecture:\n * - GameInstanceSubsystem: Persists across level transitions\n * - ServerOnly_ prefix: Methods intended for UE5 dedicated server\n * - Reads ApiBaseUrl and X-Server-Secret from config (DefaultGame.ini)\n * - Coordinates with IdentitySubsystem (character data), InventorySubsystem (items),\n *   and MarketSubsystem (post-trade sync)\n * \n * Key Features:\n * - ServerOnly_ForceSaveState(): Immediately syncs character state from backend\n * - Auto-subscribes to MarketSubsystem.OnInventorySyncRequired for post-trade sync\n * - Tracks last sync time and wallet delta for UI notifications\n * - Prevents duplicate sync requests while one is in-flight\n */" },
#endif
		{ "IncludePath", "Core/Common/Networking/EchoesPersistenceSubsystem.h" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesPersistenceSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UEchoesPersistenceSubsystem\n\nState persistence and synchronization subsystem for Echoes MMO\nProvides centralized wallet/inventory state refresh from ASP.NET backend\n\nArchitecture:\n- GameInstanceSubsystem: Persists across level transitions\n- ServerOnly_ prefix: Methods intended for UE5 dedicated server\n- Reads ApiBaseUrl and X-Server-Secret from config (DefaultGame.ini)\n- Coordinates with IdentitySubsystem (character data), InventorySubsystem (items),\n  and MarketSubsystem (post-trade sync)\n\nKey Features:\n- ServerOnly_ForceSaveState(): Immediately syncs character state from backend\n- Auto-subscribes to MarketSubsystem.OnInventorySyncRequired for post-trade sync\n- Tracks last sync time and wallet delta for UI notifications\n- Prevents duplicate sync requests while one is in-flight" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnStateSynced_MetaData[] = {
		{ "Category", "Echoes|Persistence" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when character state is synced from backend */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesPersistenceSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when character state is synced from backend" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnSyncFailed_MetaData[] = {
		{ "Category", "Echoes|Persistence" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when sync fails */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesPersistenceSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when sync fails" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnWalletBalanceChanged_MetaData[] = {
		{ "Category", "Echoes|Persistence" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when wallet balance changes */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesPersistenceSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when wallet balance changes" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CachedState_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Cached character persistence state */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesPersistenceSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cached character persistence state" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnStateSynced;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnSyncFailed;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnWalletBalanceChanged;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CachedState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetCachedState, "GetCachedState" }, // 4222731721
		{ &Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetSyncState, "GetSyncState" }, // 2800901209
		{ &Z_Construct_UFunction_UEchoesPersistenceSubsystem_GetTimeSinceLastSync, "GetTimeSinceLastSync" }, // 3387090429
		{ &Z_Construct_UFunction_UEchoesPersistenceSubsystem_HandleMarketInventorySync, "HandleMarketInventorySync" }, // 4064874995
		{ &Z_Construct_UFunction_UEchoesPersistenceSubsystem_IsStateValid, "IsStateValid" }, // 991709492
		{ &Z_Construct_UFunction_UEchoesPersistenceSubsystem_ServerOnly_ForceSaveState, "ServerOnly_ForceSaveState" }, // 3526040146
		{ &Z_Construct_UFunction_UEchoesPersistenceSubsystem_ServerOnly_ForceSaveStateForCharacter, "ServerOnly_ForceSaveStateForCharacter" }, // 117641844
		{ &Z_Construct_UFunction_UEchoesPersistenceSubsystem_ServerOnly_SyncWallet, "ServerOnly_SyncWallet" }, // 2441325143
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEchoesPersistenceSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEchoesPersistenceSubsystem_Statics::NewProp_OnStateSynced = { "OnStateSynced", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesPersistenceSubsystem, OnStateSynced), Z_Construct_UDelegateFunction_Echoes_OnPersistenceStateSynced__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnStateSynced_MetaData), NewProp_OnStateSynced_MetaData) }; // 1808297295
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEchoesPersistenceSubsystem_Statics::NewProp_OnSyncFailed = { "OnSyncFailed", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesPersistenceSubsystem, OnSyncFailed), Z_Construct_UDelegateFunction_Echoes_OnPersistenceSyncFailed__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnSyncFailed_MetaData), NewProp_OnSyncFailed_MetaData) }; // 2322395321
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEchoesPersistenceSubsystem_Statics::NewProp_OnWalletBalanceChanged = { "OnWalletBalanceChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesPersistenceSubsystem, OnWalletBalanceChanged), Z_Construct_UDelegateFunction_Echoes_OnWalletBalanceChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnWalletBalanceChanged_MetaData), NewProp_OnWalletBalanceChanged_MetaData) }; // 2437211413
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEchoesPersistenceSubsystem_Statics::NewProp_CachedState = { "CachedState", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesPersistenceSubsystem, CachedState), Z_Construct_UScriptStruct_FPersistenceCharacterState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CachedState_MetaData), NewProp_CachedState_MetaData) }; // 2939598702
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEchoesPersistenceSubsystem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesPersistenceSubsystem_Statics::NewProp_OnStateSynced,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesPersistenceSubsystem_Statics::NewProp_OnSyncFailed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesPersistenceSubsystem_Statics::NewProp_OnWalletBalanceChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesPersistenceSubsystem_Statics::NewProp_CachedState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesPersistenceSubsystem_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UEchoesPersistenceSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesPersistenceSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEchoesPersistenceSubsystem_Statics::ClassParams = {
	&UEchoesPersistenceSubsystem::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UEchoesPersistenceSubsystem_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesPersistenceSubsystem_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesPersistenceSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UEchoesPersistenceSubsystem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEchoesPersistenceSubsystem()
{
	if (!Z_Registration_Info_UClass_UEchoesPersistenceSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEchoesPersistenceSubsystem.OuterSingleton, Z_Construct_UClass_UEchoesPersistenceSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEchoesPersistenceSubsystem.OuterSingleton;
}
UEchoesPersistenceSubsystem::UEchoesPersistenceSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UEchoesPersistenceSubsystem);
UEchoesPersistenceSubsystem::~UEchoesPersistenceSubsystem() {}
// ********** End Class UEchoesPersistenceSubsystem ************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesPersistenceSubsystem_h__Script_Echoes_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EPersistenceSyncState_StaticEnum, TEXT("EPersistenceSyncState"), &Z_Registration_Info_UEnum_EPersistenceSyncState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1343187979U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FPersistenceCharacterState::StaticStruct, Z_Construct_UScriptStruct_FPersistenceCharacterState_Statics::NewStructOps, TEXT("PersistenceCharacterState"), &Z_Registration_Info_UScriptStruct_FPersistenceCharacterState, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPersistenceCharacterState), 2939598702U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEchoesPersistenceSubsystem, UEchoesPersistenceSubsystem::StaticClass, TEXT("UEchoesPersistenceSubsystem"), &Z_Registration_Info_UClass_UEchoesPersistenceSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEchoesPersistenceSubsystem), 545694121U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesPersistenceSubsystem_h__Script_Echoes_1577704081(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesPersistenceSubsystem_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesPersistenceSubsystem_h__Script_Echoes_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesPersistenceSubsystem_h__Script_Echoes_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesPersistenceSubsystem_h__Script_Echoes_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesPersistenceSubsystem_h__Script_Echoes_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesPersistenceSubsystem_h__Script_Echoes_Statics::EnumInfo));
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
