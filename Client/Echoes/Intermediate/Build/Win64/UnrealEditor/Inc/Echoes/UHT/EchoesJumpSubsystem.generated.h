// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Common/Networking/EchoesJumpSubsystem.h"

#ifdef ECHOES_EchoesJumpSubsystem_generated_h
#error "EchoesJumpSubsystem.generated.h already included, missing '#pragma once' in EchoesJumpSubsystem.h"
#endif
#define ECHOES_EchoesJumpSubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class APawn;
struct FGuid;
struct FJumpResponseData;

// ********** Begin ScriptStruct FJumpRequestData **************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesJumpSubsystem_h_20_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FJumpRequestData_Statics; \
	ECHOES_API static class UScriptStruct* StaticStruct();


struct FJumpRequestData;
// ********** End ScriptStruct FJumpRequestData ****************************************************

// ********** Begin ScriptStruct FJumpResponseData *************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesJumpSubsystem_h_53_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FJumpResponseData_Statics; \
	ECHOES_API static class UScriptStruct* StaticStruct();


struct FJumpResponseData;
// ********** End ScriptStruct FJumpResponseData ***************************************************

// ********** Begin Delegate FOnJumpRequestComplete ************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesJumpSubsystem_h_93_DELEGATE \
ECHOES_API void FOnJumpRequestComplete_DelegateWrapper(const FMulticastScriptDelegate& OnJumpRequestComplete, bool bSuccess, FJumpResponseData const& Response);


// ********** End Delegate FOnJumpRequestComplete **************************************************

// ********** Begin Delegate FOnJumpInitiated ******************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesJumpSubsystem_h_98_DELEGATE \
ECHOES_API void FOnJumpInitiated_DelegateWrapper(const FMulticastScriptDelegate& OnJumpInitiated, const FString& TravelURL, const FString& TicketId);


// ********** End Delegate FOnJumpInitiated ********************************************************

// ********** Begin Class UEchoesJumpSubsystem *****************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesJumpSubsystem_h_116_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void ClientRPC_TravelToSystem_Implementation(const FString& TravelURL, const FString& TicketId, const FString& SystemName); \
	DECLARE_FUNCTION(execClientRPC_TravelToSystem); \
	DECLARE_FUNCTION(execServerOnly_ValidateJumpTicket); \
	DECLARE_FUNCTION(execServerOnly_RequestJump);


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesJumpSubsystem_h_116_CALLBACK_WRAPPERS
ECHOES_API UClass* Z_Construct_UClass_UEchoesJumpSubsystem_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesJumpSubsystem_h_116_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEchoesJumpSubsystem(); \
	friend struct Z_Construct_UClass_UEchoesJumpSubsystem_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UEchoesJumpSubsystem_NoRegister(); \
public: \
	DECLARE_CLASS2(UEchoesJumpSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UEchoesJumpSubsystem_NoRegister) \
	DECLARE_SERIALIZER(UEchoesJumpSubsystem) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesJumpSubsystem_h_116_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UEchoesJumpSubsystem(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UEchoesJumpSubsystem(UEchoesJumpSubsystem&&) = delete; \
	UEchoesJumpSubsystem(const UEchoesJumpSubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEchoesJumpSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEchoesJumpSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UEchoesJumpSubsystem) \
	NO_API virtual ~UEchoesJumpSubsystem();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesJumpSubsystem_h_113_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesJumpSubsystem_h_116_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesJumpSubsystem_h_116_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesJumpSubsystem_h_116_CALLBACK_WRAPPERS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesJumpSubsystem_h_116_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesJumpSubsystem_h_116_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UEchoesJumpSubsystem;

// ********** End Class UEchoesJumpSubsystem *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesJumpSubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
