// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Server/EchoesHangarManager.h"

#ifdef ECHOES_EchoesHangarManager_generated_h
#error "EchoesHangarManager.generated.h already included, missing '#pragma once' in EchoesHangarManager.h"
#endif
#define ECHOES_EchoesHangarManager_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

struct FEchoesShipFitting;

// ********** Begin Class AEchoesHangarManager *****************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_EchoesHangarManager_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnFittingChanged); \
	DECLARE_FUNCTION(execClearShipPreview); \
	DECLARE_FUNCTION(execUpdateShipMesh); \
	DECLARE_FUNCTION(execSpawnShipPreview); \
	DECLARE_FUNCTION(execInitializeHangar);


ECHOES_API UClass* Z_Construct_UClass_AEchoesHangarManager_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_EchoesHangarManager_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEchoesHangarManager(); \
	friend struct Z_Construct_UClass_AEchoesHangarManager_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_AEchoesHangarManager_NoRegister(); \
public: \
	DECLARE_CLASS2(AEchoesHangarManager, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_AEchoesHangarManager_NoRegister) \
	DECLARE_SERIALIZER(AEchoesHangarManager)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_EchoesHangarManager_h_22_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AEchoesHangarManager(AEchoesHangarManager&&) = delete; \
	AEchoesHangarManager(const AEchoesHangarManager&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEchoesHangarManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEchoesHangarManager); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AEchoesHangarManager) \
	NO_API virtual ~AEchoesHangarManager();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_EchoesHangarManager_h_19_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_EchoesHangarManager_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_EchoesHangarManager_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_EchoesHangarManager_h_22_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_EchoesHangarManager_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AEchoesHangarManager;

// ********** End Class AEchoesHangarManager *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_EchoesHangarManager_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
