// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Common/Networking/EchoesAuthSubsystem.h"

#ifdef ECHOES_EchoesAuthSubsystem_generated_h
#error "EchoesAuthSubsystem.generated.h already included, missing '#pragma once' in EchoesAuthSubsystem.h"
#endif
#define ECHOES_EchoesAuthSubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

struct FAuthRequest;
struct FAuthResponse;
struct FCharacterInfo;
struct FGuid;

// ********** Begin ScriptStruct FAuthRequest ******************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h_16_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FAuthRequest_Statics; \
	ECHOES_API static class UScriptStruct* StaticStruct();


struct FAuthRequest;
// ********** End ScriptStruct FAuthRequest ********************************************************

// ********** Begin ScriptStruct FCharacterInfo ****************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h_31_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FCharacterInfo_Statics; \
	ECHOES_API static class UScriptStruct* StaticStruct();


struct FCharacterInfo;
// ********** End ScriptStruct FCharacterInfo ******************************************************

// ********** Begin ScriptStruct FAuthResponse *****************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h_58_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FAuthResponse_Statics; \
	ECHOES_API static class UScriptStruct* StaticStruct();


struct FAuthResponse;
// ********** End ScriptStruct FAuthResponse *******************************************************

// ********** Begin Delegate FOnLoginSuccess *******************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h_86_DELEGATE \
ECHOES_API void FOnLoginSuccess_DelegateWrapper(const FScriptDelegate& OnLoginSuccess, FAuthResponse const& AuthResponse);


// ********** End Delegate FOnLoginSuccess *********************************************************

// ********** Begin Delegate FOnLoginFailure *******************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h_87_DELEGATE \
ECHOES_API void FOnLoginFailure_DelegateWrapper(const FScriptDelegate& OnLoginFailure, const FString& ErrorMessage);


// ********** End Delegate FOnLoginFailure *********************************************************

// ********** Begin Delegate FOnRegisterSuccess ****************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h_88_DELEGATE \
ECHOES_API void FOnRegisterSuccess_DelegateWrapper(const FScriptDelegate& OnRegisterSuccess, FAuthResponse const& AuthResponse);


// ********** End Delegate FOnRegisterSuccess ******************************************************

// ********** Begin Delegate FOnRegisterFailure ****************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h_89_DELEGATE \
ECHOES_API void FOnRegisterFailure_DelegateWrapper(const FScriptDelegate& OnRegisterFailure, const FString& ErrorMessage);


// ********** End Delegate FOnRegisterFailure ******************************************************

// ********** Begin ScriptStruct FCharacterData ****************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h_97_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FCharacterData_Statics; \
	ECHOES_API static class UScriptStruct* StaticStruct();


struct FCharacterData;
// ********** End ScriptStruct FCharacterData ******************************************************

// ********** Begin Class UEchoesAuthSubsystem *****************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h_157_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execAuth_Logout); \
	DECLARE_FUNCTION(execAuth_GetCharacters); \
	DECLARE_FUNCTION(execAuth_IsLoggedIn); \
	DECLARE_FUNCTION(execAuth_GetCharacterId); \
	DECLARE_FUNCTION(execAuth_GetAccountId); \
	DECLARE_FUNCTION(execAuth_GetToken); \
	DECLARE_FUNCTION(execAuth_Register); \
	DECLARE_FUNCTION(execAuth_Login);


ECHOES_API UClass* Z_Construct_UClass_UEchoesAuthSubsystem_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h_157_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEchoesAuthSubsystem(); \
	friend struct Z_Construct_UClass_UEchoesAuthSubsystem_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UEchoesAuthSubsystem_NoRegister(); \
public: \
	DECLARE_CLASS2(UEchoesAuthSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UEchoesAuthSubsystem_NoRegister) \
	DECLARE_SERIALIZER(UEchoesAuthSubsystem)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h_157_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UEchoesAuthSubsystem(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UEchoesAuthSubsystem(UEchoesAuthSubsystem&&) = delete; \
	UEchoesAuthSubsystem(const UEchoesAuthSubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEchoesAuthSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEchoesAuthSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UEchoesAuthSubsystem) \
	NO_API virtual ~UEchoesAuthSubsystem();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h_154_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h_157_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h_157_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h_157_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h_157_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UEchoesAuthSubsystem;

// ********** End Class UEchoesAuthSubsystem *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
