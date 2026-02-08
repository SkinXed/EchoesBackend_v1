// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Server/Managers/WorldObjectManager.h"

#ifdef ECHOES_WorldObjectManager_generated_h
#error "WorldObjectManager.generated.h already included, missing '#pragma once' in WorldObjectManager.h"
#endif
#define ECHOES_WorldObjectManager_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class AEWorldContainer;
struct FWorldObjectData;

// ********** Begin Class UWorldObjectManager ******************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_Managers_WorldObjectManager_h_33_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execServerOnly_SpawnContainer); \
	DECLARE_FUNCTION(execServerOnly_QueryBackend); \
	DECLARE_FUNCTION(execGetContainerCount); \
	DECLARE_FUNCTION(execGetSpawnedContainers); \
	DECLARE_FUNCTION(execServerOnly_LoadWorldObjects);


ECHOES_API UClass* Z_Construct_UClass_UWorldObjectManager_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_Managers_WorldObjectManager_h_33_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUWorldObjectManager(); \
	friend struct Z_Construct_UClass_UWorldObjectManager_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UWorldObjectManager_NoRegister(); \
public: \
	DECLARE_CLASS2(UWorldObjectManager, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UWorldObjectManager_NoRegister) \
	DECLARE_SERIALIZER(UWorldObjectManager)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_Managers_WorldObjectManager_h_33_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UWorldObjectManager(UWorldObjectManager&&) = delete; \
	UWorldObjectManager(const UWorldObjectManager&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UWorldObjectManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UWorldObjectManager); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UWorldObjectManager) \
	NO_API virtual ~UWorldObjectManager();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_Managers_WorldObjectManager_h_30_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_Managers_WorldObjectManager_h_33_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_Managers_WorldObjectManager_h_33_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_Managers_WorldObjectManager_h_33_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_Managers_WorldObjectManager_h_33_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UWorldObjectManager;

// ********** End Class UWorldObjectManager ********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_Managers_WorldObjectManager_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
