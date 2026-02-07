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
struct FCharacterData;
struct FCharacterInfo;
struct FGuid;

// ********** Begin ScriptStruct FAuthRequest ******************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h_17_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FAuthRequest_Statics; \
	ECHOES_API static class UScriptStruct* StaticStruct();


struct FAuthRequest;
// ********** End ScriptStruct FAuthRequest ********************************************************

// ********** Begin ScriptStruct FCharacterInfo ****************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h_32_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FCharacterInfo_Statics; \
	ECHOES_API static class UScriptStruct* StaticStruct();


struct FCharacterInfo;
// ********** End ScriptStruct FCharacterInfo ******************************************************

// ********** Begin ScriptStruct FAuthResponse *****************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h_71_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FAuthResponse_Statics; \
	ECHOES_API static class UScriptStruct* StaticStruct();


struct FAuthResponse;
// ********** End ScriptStruct FAuthResponse *******************************************************

// ********** Begin Delegate FOnLoginSuccess *******************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h_98_DELEGATE \
ECHOES_API void FOnLoginSuccess_DelegateWrapper(const FScriptDelegate& OnLoginSuccess, FAuthResponse const& AuthResponse);


// ********** End Delegate FOnLoginSuccess *********************************************************

// ********** Begin Delegate FOnLoginFailure *******************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h_99_DELEGATE \
ECHOES_API void FOnLoginFailure_DelegateWrapper(const FScriptDelegate& OnLoginFailure, const FString& ErrorMessage);


// ********** End Delegate FOnLoginFailure *********************************************************

// ********** Begin Delegate FOnRegisterSuccess ****************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h_100_DELEGATE \
ECHOES_API void FOnRegisterSuccess_DelegateWrapper(const FScriptDelegate& OnRegisterSuccess, FAuthResponse const& AuthResponse);


// ********** End Delegate FOnRegisterSuccess ******************************************************

// ********** Begin Delegate FOnRegisterFailure ****************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h_101_DELEGATE \
ECHOES_API void FOnRegisterFailure_DelegateWrapper(const FScriptDelegate& OnRegisterFailure, const FString& ErrorMessage);


// ********** End Delegate FOnRegisterFailure ******************************************************

// ********** Begin Delegate FOnCharacterCreated ***************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h_104_DELEGATE \
ECHOES_API void FOnCharacterCreated_DelegateWrapper(const FMulticastScriptDelegate& OnCharacterCreated, FCharacterData const& CharacterData);


// ********** End Delegate FOnCharacterCreated *****************************************************

// ********** Begin Delegate FOnCharacterCreationFailed ********************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h_105_DELEGATE \
ECHOES_API void FOnCharacterCreationFailed_DelegateWrapper(const FMulticastScriptDelegate& OnCharacterCreationFailed, const FString& ErrorMessage);


// ********** End Delegate FOnCharacterCreationFailed **********************************************

// ********** Begin Delegate FOnConnectInfoReceived ************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h_106_DELEGATE \
ECHOES_API void FOnConnectInfoReceived_DelegateWrapper(const FMulticastScriptDelegate& OnConnectInfoReceived, const FString& ServerIP, int32 ServerPort);


// ********** End Delegate FOnConnectInfoReceived **************************************************

// ********** Begin Delegate FOnConnectInfoFailed **************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h_107_DELEGATE \
ECHOES_API void FOnConnectInfoFailed_DelegateWrapper(const FMulticastScriptDelegate& OnConnectInfoFailed, const FString& ErrorMessage);


// ********** End Delegate FOnConnectInfoFailed ****************************************************

// ********** Begin Delegate FOnCharacterDeleted ***************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h_108_DELEGATE \
ECHOES_API void FOnCharacterDeleted_DelegateWrapper(const FMulticastScriptDelegate& OnCharacterDeleted, FGuid const& CharacterId);


// ********** End Delegate FOnCharacterDeleted *****************************************************

// ********** Begin Delegate FOnCharacterDeletionFailed ********************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h_109_DELEGATE \
ECHOES_API void FOnCharacterDeletionFailed_DelegateWrapper(const FMulticastScriptDelegate& OnCharacterDeletionFailed, const FString& ErrorMessage);


// ********** End Delegate FOnCharacterDeletionFailed **********************************************

// ********** Begin Delegate FOnCharacterListUpdated ***********************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h_110_DELEGATE \
ECHOES_API void FOnCharacterListUpdated_DelegateWrapper(const FMulticastScriptDelegate& OnCharacterListUpdated, TArray<FCharacterInfo> const& Characters);


// ********** End Delegate FOnCharacterListUpdated *************************************************

// ********** Begin Class UEchoesAuthSubsystem *****************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h_127_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execConnectToWorld); \
	DECLARE_FUNCTION(execFetchCharacterList); \
	DECLARE_FUNCTION(execDeleteCharacter); \
	DECLARE_FUNCTION(execCreateCharacter); \
	DECLARE_FUNCTION(execAuth_Logout); \
	DECLARE_FUNCTION(execAuth_GetCharacters); \
	DECLARE_FUNCTION(execAuth_IsLoggedIn); \
	DECLARE_FUNCTION(execAuth_GetCharacterId); \
	DECLARE_FUNCTION(execAuth_GetAccountId); \
	DECLARE_FUNCTION(execAuth_GetToken); \
	DECLARE_FUNCTION(execSaveAuthToken); \
	DECLARE_FUNCTION(execAuth_Register); \
	DECLARE_FUNCTION(execAuth_Login);


ECHOES_API UClass* Z_Construct_UClass_UEchoesAuthSubsystem_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h_127_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEchoesAuthSubsystem(); \
	friend struct Z_Construct_UClass_UEchoesAuthSubsystem_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UEchoesAuthSubsystem_NoRegister(); \
public: \
	DECLARE_CLASS2(UEchoesAuthSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UEchoesAuthSubsystem_NoRegister) \
	DECLARE_SERIALIZER(UEchoesAuthSubsystem)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h_127_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UEchoesAuthSubsystem(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UEchoesAuthSubsystem(UEchoesAuthSubsystem&&) = delete; \
	UEchoesAuthSubsystem(const UEchoesAuthSubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEchoesAuthSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEchoesAuthSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UEchoesAuthSubsystem) \
	NO_API virtual ~UEchoesAuthSubsystem();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h_124_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h_127_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h_127_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h_127_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h_127_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UEchoesAuthSubsystem;

// ********** End Class UEchoesAuthSubsystem *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesAuthSubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
