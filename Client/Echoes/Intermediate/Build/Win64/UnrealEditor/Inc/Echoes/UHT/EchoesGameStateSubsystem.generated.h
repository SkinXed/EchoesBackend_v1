// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Common/EchoesGameStateSubsystem.h"

#ifdef ECHOES_EchoesGameStateSubsystem_generated_h
#error "EchoesGameStateSubsystem.generated.h already included, missing '#pragma once' in EchoesGameStateSubsystem.h"
#endif
#define ECHOES_EchoesGameStateSubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

enum class EEchoesGameState : uint8;

// ********** Begin Class UEchoesGameStateSubsystem ************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesGameStateSubsystem_h_28_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execTransitionToSpace); \
	DECLARE_FUNCTION(execTransitionToHangar); \
	DECLARE_FUNCTION(execTransitionToCharacterSelect); \
	DECLARE_FUNCTION(execTransitionToLogin); \
	DECLARE_FUNCTION(execSetCurrentState); \
	DECLARE_FUNCTION(execGetCurrentState);


ECHOES_API UClass* Z_Construct_UClass_UEchoesGameStateSubsystem_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesGameStateSubsystem_h_28_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEchoesGameStateSubsystem(); \
	friend struct Z_Construct_UClass_UEchoesGameStateSubsystem_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UEchoesGameStateSubsystem_NoRegister(); \
public: \
	DECLARE_CLASS2(UEchoesGameStateSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UEchoesGameStateSubsystem_NoRegister) \
	DECLARE_SERIALIZER(UEchoesGameStateSubsystem)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesGameStateSubsystem_h_28_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UEchoesGameStateSubsystem(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UEchoesGameStateSubsystem(UEchoesGameStateSubsystem&&) = delete; \
	UEchoesGameStateSubsystem(const UEchoesGameStateSubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEchoesGameStateSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEchoesGameStateSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UEchoesGameStateSubsystem) \
	NO_API virtual ~UEchoesGameStateSubsystem();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesGameStateSubsystem_h_25_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesGameStateSubsystem_h_28_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesGameStateSubsystem_h_28_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesGameStateSubsystem_h_28_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesGameStateSubsystem_h_28_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UEchoesGameStateSubsystem;

// ********** End Class UEchoesGameStateSubsystem **************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesGameStateSubsystem_h

// ********** Begin Enum EEchoesGameState **********************************************************
#define FOREACH_ENUM_EECHOESGAMESTATE(op) \
	op(EEchoesGameState::Login) \
	op(EEchoesGameState::CharacterSelect) \
	op(EEchoesGameState::Hangar) \
	op(EEchoesGameState::InSpace) 

enum class EEchoesGameState : uint8;
template<> struct TIsUEnumClass<EEchoesGameState> { enum { Value = true }; };
template<> ECHOES_API UEnum* StaticEnum<EEchoesGameState>();
// ********** End Enum EEchoesGameState ************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
