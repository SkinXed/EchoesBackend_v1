// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Common/EchoesJumpManager.h"

#ifdef ECHOES_EchoesJumpManager_generated_h
#error "EchoesJumpManager.generated.h already included, missing '#pragma once' in EchoesJumpManager.h"
#endif
#define ECHOES_EchoesJumpManager_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class APlayerController;
struct FGuid;

// ********** Begin Class UEchoesJumpManager *******************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesJumpManager_h_45_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void ClientRPC_UpdateJumpProgress_Implementation(float Progress); \
	virtual void ClientRPC_EndJumpSequence_Implementation(); \
	virtual void ClientRPC_StartJumpSequence_Implementation(float TransitionDuration); \
	DECLARE_FUNCTION(execClientRPC_UpdateJumpProgress); \
	DECLARE_FUNCTION(execClientRPC_EndJumpSequence); \
	DECLARE_FUNCTION(execClientRPC_StartJumpSequence); \
	DECLARE_FUNCTION(execInitiateIntraServerJump);


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesJumpManager_h_45_CALLBACK_WRAPPERS
ECHOES_API UClass* Z_Construct_UClass_UEchoesJumpManager_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesJumpManager_h_45_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEchoesJumpManager(); \
	friend struct Z_Construct_UClass_UEchoesJumpManager_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UEchoesJumpManager_NoRegister(); \
public: \
	DECLARE_CLASS2(UEchoesJumpManager, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UEchoesJumpManager_NoRegister) \
	DECLARE_SERIALIZER(UEchoesJumpManager)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesJumpManager_h_45_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UEchoesJumpManager(UEchoesJumpManager&&) = delete; \
	UEchoesJumpManager(const UEchoesJumpManager&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEchoesJumpManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEchoesJumpManager); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UEchoesJumpManager) \
	NO_API virtual ~UEchoesJumpManager();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesJumpManager_h_42_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesJumpManager_h_45_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesJumpManager_h_45_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesJumpManager_h_45_CALLBACK_WRAPPERS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesJumpManager_h_45_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesJumpManager_h_45_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UEchoesJumpManager;

// ********** End Class UEchoesJumpManager *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesJumpManager_h

// ********** Begin Enum EJumpState ****************************************************************
#define FOREACH_ENUM_EJUMPSTATE(op) \
	op(EJumpState::None) \
	op(EJumpState::Initiating) \
	op(EJumpState::Jumping) \
	op(EJumpState::Arriving) 

enum class EJumpState : uint8;
template<> struct TIsUEnumClass<EJumpState> { enum { Value = true }; };
template<> ECHOES_API UEnum* StaticEnum<EJumpState>();
// ********** End Enum EJumpState ******************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
