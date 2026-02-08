// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Server/Managers/ServerDataManager.h"

#ifdef ECHOES_ServerDataManager_generated_h
#error "ServerDataManager.generated.h already included, missing '#pragma once' in ServerDataManager.h"
#endif
#define ECHOES_ServerDataManager_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

enum class ESlotType : uint8;
struct FCommon_ItemSlot;
struct FCommon_ShipFittingData;

// ********** Begin Class AServerDataManager *******************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_Managers_ServerDataManager_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetServerSecret); \
	DECLARE_FUNCTION(execGetAPIBaseURL); \
	DECLARE_FUNCTION(execServerOnly_RequestFittingFromAPI); \
	DECLARE_FUNCTION(execServerOnly_CalculateFinalStats); \
	DECLARE_FUNCTION(execServerOnly_ValidateModuleInstallation); \
	DECLARE_FUNCTION(execServerOnly_ValidateFitting); \
	DECLARE_FUNCTION(execServerOnly_ParseModuleFromJSON); \
	DECLARE_FUNCTION(execServerOnly_ParseFittingDataFromJSON);


ECHOES_API UClass* Z_Construct_UClass_AServerDataManager_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_Managers_ServerDataManager_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAServerDataManager(); \
	friend struct Z_Construct_UClass_AServerDataManager_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_AServerDataManager_NoRegister(); \
public: \
	DECLARE_CLASS2(AServerDataManager, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_AServerDataManager_NoRegister) \
	DECLARE_SERIALIZER(AServerDataManager)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_Managers_ServerDataManager_h_24_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AServerDataManager(AServerDataManager&&) = delete; \
	AServerDataManager(const AServerDataManager&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AServerDataManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AServerDataManager); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AServerDataManager) \
	NO_API virtual ~AServerDataManager();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_Managers_ServerDataManager_h_21_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_Managers_ServerDataManager_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_Managers_ServerDataManager_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_Managers_ServerDataManager_h_24_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_Managers_ServerDataManager_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AServerDataManager;

// ********** End Class AServerDataManager *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_Managers_ServerDataManager_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
