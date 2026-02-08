// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Common/Networking/EchoesPersistenceSubsystem.h"

#ifdef ECHOES_EchoesPersistenceSubsystem_generated_h
#error "EchoesPersistenceSubsystem.generated.h already included, missing '#pragma once' in EchoesPersistenceSubsystem.h"
#endif
#define ECHOES_EchoesPersistenceSubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

enum class EPersistenceSyncState : uint8;
struct FGuid;
struct FPersistenceCharacterState;

// ********** Begin ScriptStruct FPersistenceCharacterState ****************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesPersistenceSubsystem_h_37_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FPersistenceCharacterState_Statics; \
	ECHOES_API static class UScriptStruct* StaticStruct();


struct FPersistenceCharacterState;
// ********** End ScriptStruct FPersistenceCharacterState ******************************************

// ********** Begin Delegate FOnPersistenceStateSynced *********************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesPersistenceSubsystem_h_67_DELEGATE \
ECHOES_API void FOnPersistenceStateSynced_DelegateWrapper(const FMulticastScriptDelegate& OnPersistenceStateSynced, FPersistenceCharacterState const& State);


// ********** End Delegate FOnPersistenceStateSynced ***********************************************

// ********** Begin Delegate FOnPersistenceSyncFailed **********************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesPersistenceSubsystem_h_70_DELEGATE \
ECHOES_API void FOnPersistenceSyncFailed_DelegateWrapper(const FMulticastScriptDelegate& OnPersistenceSyncFailed, const FString& ErrorMessage);


// ********** End Delegate FOnPersistenceSyncFailed ************************************************

// ********** Begin Delegate FOnWalletBalanceChanged ***********************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesPersistenceSubsystem_h_73_DELEGATE \
ECHOES_API void FOnWalletBalanceChanged_DelegateWrapper(const FMulticastScriptDelegate& OnWalletBalanceChanged, int64 OldBalance, int64 NewBalance);


// ********** End Delegate FOnWalletBalanceChanged *************************************************

// ********** Begin Class UEchoesPersistenceSubsystem **********************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesPersistenceSubsystem_h_97_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandleMarketInventorySync); \
	DECLARE_FUNCTION(execIsStateValid); \
	DECLARE_FUNCTION(execGetTimeSinceLastSync); \
	DECLARE_FUNCTION(execGetSyncState); \
	DECLARE_FUNCTION(execGetCachedState); \
	DECLARE_FUNCTION(execServerOnly_SyncWallet); \
	DECLARE_FUNCTION(execServerOnly_ForceSaveStateForCharacter); \
	DECLARE_FUNCTION(execServerOnly_ForceSaveState);


ECHOES_API UClass* Z_Construct_UClass_UEchoesPersistenceSubsystem_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesPersistenceSubsystem_h_97_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEchoesPersistenceSubsystem(); \
	friend struct Z_Construct_UClass_UEchoesPersistenceSubsystem_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UEchoesPersistenceSubsystem_NoRegister(); \
public: \
	DECLARE_CLASS2(UEchoesPersistenceSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UEchoesPersistenceSubsystem_NoRegister) \
	DECLARE_SERIALIZER(UEchoesPersistenceSubsystem)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesPersistenceSubsystem_h_97_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UEchoesPersistenceSubsystem(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UEchoesPersistenceSubsystem(UEchoesPersistenceSubsystem&&) = delete; \
	UEchoesPersistenceSubsystem(const UEchoesPersistenceSubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEchoesPersistenceSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEchoesPersistenceSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UEchoesPersistenceSubsystem) \
	NO_API virtual ~UEchoesPersistenceSubsystem();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesPersistenceSubsystem_h_94_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesPersistenceSubsystem_h_97_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesPersistenceSubsystem_h_97_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesPersistenceSubsystem_h_97_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesPersistenceSubsystem_h_97_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UEchoesPersistenceSubsystem;

// ********** End Class UEchoesPersistenceSubsystem ************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesPersistenceSubsystem_h

// ********** Begin Enum EPersistenceSyncState *****************************************************
#define FOREACH_ENUM_EPERSISTENCESYNCSTATE(op) \
	op(EPersistenceSyncState::Idle) \
	op(EPersistenceSyncState::Syncing) \
	op(EPersistenceSyncState::Error) 

enum class EPersistenceSyncState : uint8;
template<> struct TIsUEnumClass<EPersistenceSyncState> { enum { Value = true }; };
template<> ECHOES_API UEnum* StaticEnum<EPersistenceSyncState>();
// ********** End Enum EPersistenceSyncState *******************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
