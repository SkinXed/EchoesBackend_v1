// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Server/EchoesServerManagementSubsystem.h"

#ifdef ECHOES_EchoesServerManagementSubsystem_generated_h
#error "EchoesServerManagementSubsystem.generated.h already included, missing '#pragma once' in EchoesServerManagementSubsystem.h"
#endif
#define ECHOES_EchoesServerManagementSubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

struct FGuid;
struct FServerRegionalClusterConfig;
struct FServerSystemConfig;

// ********** Begin Delegate FOnServerConfigReceived ***********************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_EchoesServerManagementSubsystem_h_18_DELEGATE \
ECHOES_API void FOnServerConfigReceived_DelegateWrapper(const FMulticastScriptDelegate& OnServerConfigReceived, FServerSystemConfig const& Config);


// ********** End Delegate FOnServerConfigReceived *************************************************

// ********** Begin Delegate FOnRegionalClusterConfigReceived **************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_EchoesServerManagementSubsystem_h_24_DELEGATE \
ECHOES_API void FOnRegionalClusterConfigReceived_DelegateWrapper(const FMulticastScriptDelegate& OnRegionalClusterConfigReceived, FServerRegionalClusterConfig const& RegionalConfig);


// ********** End Delegate FOnRegionalClusterConfigReceived ****************************************

// ********** Begin Class UEchoesServerManagementSubsystem *****************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_EchoesServerManagementSubsystem_h_48_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetRegionalConfig); \
	DECLARE_FUNCTION(execIsRegionalCluster); \
	DECLARE_FUNCTION(execGetServerType); \
	DECLARE_FUNCTION(execGetServerId); \
	DECLARE_FUNCTION(execIsServerRegistered); \
	DECLARE_FUNCTION(execGetInstanceId); \
	DECLARE_FUNCTION(execServerOnly_Unregister); \
	DECLARE_FUNCTION(execServerOnly_GetConfig); \
	DECLARE_FUNCTION(execServerOnly_Heartbeat); \
	DECLARE_FUNCTION(execServerOnly_Register);


ECHOES_API UClass* Z_Construct_UClass_UEchoesServerManagementSubsystem_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_EchoesServerManagementSubsystem_h_48_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEchoesServerManagementSubsystem(); \
	friend struct Z_Construct_UClass_UEchoesServerManagementSubsystem_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UEchoesServerManagementSubsystem_NoRegister(); \
public: \
	DECLARE_CLASS2(UEchoesServerManagementSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UEchoesServerManagementSubsystem_NoRegister) \
	DECLARE_SERIALIZER(UEchoesServerManagementSubsystem) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_EchoesServerManagementSubsystem_h_48_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UEchoesServerManagementSubsystem(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UEchoesServerManagementSubsystem(UEchoesServerManagementSubsystem&&) = delete; \
	UEchoesServerManagementSubsystem(const UEchoesServerManagementSubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEchoesServerManagementSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEchoesServerManagementSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UEchoesServerManagementSubsystem) \
	NO_API virtual ~UEchoesServerManagementSubsystem();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_EchoesServerManagementSubsystem_h_45_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_EchoesServerManagementSubsystem_h_48_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_EchoesServerManagementSubsystem_h_48_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_EchoesServerManagementSubsystem_h_48_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_EchoesServerManagementSubsystem_h_48_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UEchoesServerManagementSubsystem;

// ********** End Class UEchoesServerManagementSubsystem *******************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_EchoesServerManagementSubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
