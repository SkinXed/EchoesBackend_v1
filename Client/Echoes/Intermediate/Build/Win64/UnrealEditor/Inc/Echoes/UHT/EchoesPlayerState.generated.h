// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Common/Player/EchoesPlayerState.h"

#ifdef ECHOES_EchoesPlayerState_generated_h
#error "EchoesPlayerState.generated.h already included, missing '#pragma once' in EchoesPlayerState.h"
#endif
#define ECHOES_EchoesPlayerState_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AEchoesPlayerState *******************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Player_EchoesPlayerState_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnRep_AuthToken); \
	DECLARE_FUNCTION(execSetAuthToken);


ECHOES_API UClass* Z_Construct_UClass_AEchoesPlayerState_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Player_EchoesPlayerState_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEchoesPlayerState(); \
	friend struct Z_Construct_UClass_AEchoesPlayerState_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_AEchoesPlayerState_NoRegister(); \
public: \
	DECLARE_CLASS2(AEchoesPlayerState, APlayerState, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_AEchoesPlayerState_NoRegister) \
	DECLARE_SERIALIZER(AEchoesPlayerState) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		AuthToken=NETFIELD_REP_START, \
		NETFIELD_REP_END=AuthToken	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Player_EchoesPlayerState_h_17_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AEchoesPlayerState(AEchoesPlayerState&&) = delete; \
	AEchoesPlayerState(const AEchoesPlayerState&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEchoesPlayerState); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEchoesPlayerState); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AEchoesPlayerState) \
	NO_API virtual ~AEchoesPlayerState();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Player_EchoesPlayerState_h_14_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Player_EchoesPlayerState_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Player_EchoesPlayerState_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Player_EchoesPlayerState_h_17_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Player_EchoesPlayerState_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AEchoesPlayerState;

// ********** End Class AEchoesPlayerState *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Player_EchoesPlayerState_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
