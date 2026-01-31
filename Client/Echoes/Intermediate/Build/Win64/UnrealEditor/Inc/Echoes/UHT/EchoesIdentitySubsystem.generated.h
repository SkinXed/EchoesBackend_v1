// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Common/Networking/EchoesIdentitySubsystem.h"

#ifdef ECHOES_EchoesIdentitySubsystem_generated_h
#error "EchoesIdentitySubsystem.generated.h already included, missing '#pragma once' in EchoesIdentitySubsystem.h"
#endif
#define ECHOES_EchoesIdentitySubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

struct FEchoesCharacter;
struct FGuid;

// ********** Begin ScriptStruct FEchoesCharacter **************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesIdentitySubsystem_h_17_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FEchoesCharacter_Statics; \
	ECHOES_API static class UScriptStruct* StaticStruct();


struct FEchoesCharacter;
// ********** End ScriptStruct FEchoesCharacter ****************************************************

// ********** Begin Delegate FOnCharacterDataReceived **********************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesIdentitySubsystem_h_71_DELEGATE \
ECHOES_API void FOnCharacterDataReceived_DelegateWrapper(const FScriptDelegate& OnCharacterDataReceived, FEchoesCharacter const& CharacterData);


// ********** End Delegate FOnCharacterDataReceived ************************************************

// ********** Begin Delegate FOnCharacterDataFailure ***********************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesIdentitySubsystem_h_72_DELEGATE \
ECHOES_API void FOnCharacterDataFailure_DelegateWrapper(const FScriptDelegate& OnCharacterDataFailure, const FString& ErrorMessage);


// ********** End Delegate FOnCharacterDataFailure *************************************************

// ********** Begin Delegate FOnCharacterSelected **************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesIdentitySubsystem_h_73_DELEGATE \
ECHOES_API void FOnCharacterSelected_DelegateWrapper(const FMulticastScriptDelegate& OnCharacterSelected);


// ********** End Delegate FOnCharacterSelected ****************************************************

// ********** Begin Delegate FOnIdentityCharacterCreated *******************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesIdentitySubsystem_h_74_DELEGATE \
ECHOES_API void FOnIdentityCharacterCreated_DelegateWrapper(const FScriptDelegate& OnIdentityCharacterCreated, FEchoesCharacter const& CharacterData);


// ********** End Delegate FOnIdentityCharacterCreated *********************************************

// ********** Begin Class UEchoesIdentitySubsystem *************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesIdentitySubsystem_h_96_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execUI_CreateCharacter); \
	DECLARE_FUNCTION(execIdentity_ClearSelection); \
	DECLARE_FUNCTION(execIdentity_GetSelectedCharacterId); \
	DECLARE_FUNCTION(execIdentity_HasSelectedCharacter); \
	DECLARE_FUNCTION(execIdentity_GetSelectedCharacter); \
	DECLARE_FUNCTION(execIdentity_SelectCharacter); \
	DECLARE_FUNCTION(execIdentity_FetchCharacter);


ECHOES_API UClass* Z_Construct_UClass_UEchoesIdentitySubsystem_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesIdentitySubsystem_h_96_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEchoesIdentitySubsystem(); \
	friend struct Z_Construct_UClass_UEchoesIdentitySubsystem_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UEchoesIdentitySubsystem_NoRegister(); \
public: \
	DECLARE_CLASS2(UEchoesIdentitySubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UEchoesIdentitySubsystem_NoRegister) \
	DECLARE_SERIALIZER(UEchoesIdentitySubsystem)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesIdentitySubsystem_h_96_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UEchoesIdentitySubsystem(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UEchoesIdentitySubsystem(UEchoesIdentitySubsystem&&) = delete; \
	UEchoesIdentitySubsystem(const UEchoesIdentitySubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEchoesIdentitySubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEchoesIdentitySubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UEchoesIdentitySubsystem) \
	NO_API virtual ~UEchoesIdentitySubsystem();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesIdentitySubsystem_h_93_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesIdentitySubsystem_h_96_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesIdentitySubsystem_h_96_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesIdentitySubsystem_h_96_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesIdentitySubsystem_h_96_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UEchoesIdentitySubsystem;

// ********** End Class UEchoesIdentitySubsystem ***************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesIdentitySubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
