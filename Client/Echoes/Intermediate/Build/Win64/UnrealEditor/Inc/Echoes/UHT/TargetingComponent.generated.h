// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Common/Components/TargetingComponent.h"

#ifdef ECHOES_TargetingComponent_generated_h
#error "TargetingComponent.generated.h already included, missing '#pragma once' in TargetingComponent.h"
#endif
#define ECHOES_TargetingComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class AActor;
enum class ETargetLockState : uint8;

// ********** Begin ScriptStruct FTargetLockEntry **************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_TargetingComponent_h_36_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FTargetLockEntry_Statics; \
	ECHOES_API static class UScriptStruct* StaticStruct();


struct FTargetLockEntry;
// ********** End ScriptStruct FTargetLockEntry ****************************************************

// ********** Begin Delegate FOnLockStarted ********************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_TargetingComponent_h_70_DELEGATE \
ECHOES_API void FOnLockStarted_DelegateWrapper(const FMulticastScriptDelegate& OnLockStarted, AActor* Target);


// ********** End Delegate FOnLockStarted **********************************************************

// ********** Begin Delegate FOnLockCompleted ******************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_TargetingComponent_h_71_DELEGATE \
ECHOES_API void FOnLockCompleted_DelegateWrapper(const FMulticastScriptDelegate& OnLockCompleted, AActor* Target);


// ********** End Delegate FOnLockCompleted ********************************************************

// ********** Begin Delegate FOnLockLost ***********************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_TargetingComponent_h_72_DELEGATE \
ECHOES_API void FOnLockLost_DelegateWrapper(const FMulticastScriptDelegate& OnLockLost, AActor* Target);


// ********** End Delegate FOnLockLost *************************************************************

// ********** Begin Delegate FOnLockProgress *******************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_TargetingComponent_h_73_DELEGATE \
ECHOES_API void FOnLockProgress_DelegateWrapper(const FMulticastScriptDelegate& OnLockProgress, AActor* Target, float Progress);


// ********** End Delegate FOnLockProgress *********************************************************

// ********** Begin Class UTargetingComponent ******************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_TargetingComponent_h_113_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void ClientRPC_OnLockLost_Implementation(AActor* Target); \
	virtual void ClientRPC_OnLockCompleted_Implementation(AActor* Target); \
	virtual void ClientRPC_OnLockStarted_Implementation(AActor* Target); \
	virtual void ServerRPC_ClearAllLocks_Implementation(); \
	virtual void ServerRPC_CancelLock_Implementation(AActor* Target); \
	virtual void ServerRPC_StartLock_Implementation(AActor* Target); \
	DECLARE_FUNCTION(execCommon_GetAvailableLockSlots); \
	DECLARE_FUNCTION(execCommon_GetLockedTargets); \
	DECLARE_FUNCTION(execCommon_IsTargetLocked); \
	DECLARE_FUNCTION(execCommon_GetLockState); \
	DECLARE_FUNCTION(execCommon_GetLockProgress); \
	DECLARE_FUNCTION(execCommon_IsTargetInRange); \
	DECLARE_FUNCTION(execCommon_GetTargetSignatureRadius); \
	DECLARE_FUNCTION(execCommon_CalculateLockTime); \
	DECLARE_FUNCTION(execClientRPC_OnLockLost); \
	DECLARE_FUNCTION(execClientRPC_OnLockCompleted); \
	DECLARE_FUNCTION(execClientRPC_OnLockStarted); \
	DECLARE_FUNCTION(execServerRPC_ClearAllLocks); \
	DECLARE_FUNCTION(execServerRPC_CancelLock); \
	DECLARE_FUNCTION(execServerRPC_StartLock);


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_TargetingComponent_h_113_CALLBACK_WRAPPERS
ECHOES_API UClass* Z_Construct_UClass_UTargetingComponent_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_TargetingComponent_h_113_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUTargetingComponent(); \
	friend struct Z_Construct_UClass_UTargetingComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UTargetingComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UTargetingComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UTargetingComponent_NoRegister) \
	DECLARE_SERIALIZER(UTargetingComponent) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		TargetLocks=NETFIELD_REP_START, \
		NETFIELD_REP_END=TargetLocks	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_TargetingComponent_h_113_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UTargetingComponent(UTargetingComponent&&) = delete; \
	UTargetingComponent(const UTargetingComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UTargetingComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UTargetingComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UTargetingComponent) \
	NO_API virtual ~UTargetingComponent();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_TargetingComponent_h_110_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_TargetingComponent_h_113_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_TargetingComponent_h_113_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_TargetingComponent_h_113_CALLBACK_WRAPPERS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_TargetingComponent_h_113_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_TargetingComponent_h_113_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UTargetingComponent;

// ********** End Class UTargetingComponent ********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_TargetingComponent_h

// ********** Begin Enum ETargetLockState **********************************************************
#define FOREACH_ENUM_ETARGETLOCKSTATE(op) \
	op(ETargetLockState::None) \
	op(ETargetLockState::Locking) \
	op(ETargetLockState::Locked) \
	op(ETargetLockState::Lost) 

enum class ETargetLockState : uint8;
template<> struct TIsUEnumClass<ETargetLockState> { enum { Value = true }; };
template<> ECHOES_API UEnum* StaticEnum<ETargetLockState>();
// ********** End Enum ETargetLockState ************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
