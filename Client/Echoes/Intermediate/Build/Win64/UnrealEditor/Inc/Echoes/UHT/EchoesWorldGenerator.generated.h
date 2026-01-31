// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Common/EchoesWorldGenerator.h"

#ifdef ECHOES_EchoesWorldGenerator_generated_h
#error "EchoesWorldGenerator.generated.h already included, missing '#pragma once' in EchoesWorldGenerator.h"
#endif
#define ECHOES_EchoesWorldGenerator_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

struct FGuid;
struct FServerRegionalClusterConfig;
struct FServerSystemConfig;

// ********** Begin Class AEchoesWorldGenerator ****************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesWorldGenerator_h_49_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execIsRegionalCluster); \
	DECLARE_FUNCTION(execGetSystemGlobalOffset); \
	DECLARE_FUNCTION(execIsSystemOnThisServer); \
	DECLARE_FUNCTION(execConvertCoordinates); \
	DECLARE_FUNCTION(execCalculateSystemGlobalOffset); \
	DECLARE_FUNCTION(execOnRegionalClusterConfigReceived); \
	DECLARE_FUNCTION(execOnServerConfigReceived); \
	DECLARE_FUNCTION(execServerOnly_ClearWorld); \
	DECLARE_FUNCTION(execServerOnly_GenerateRegionalCluster); \
	DECLARE_FUNCTION(execServerOnly_GenerateWorld);


ECHOES_API UClass* Z_Construct_UClass_AEchoesWorldGenerator_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesWorldGenerator_h_49_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEchoesWorldGenerator(); \
	friend struct Z_Construct_UClass_AEchoesWorldGenerator_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_AEchoesWorldGenerator_NoRegister(); \
public: \
	DECLARE_CLASS2(AEchoesWorldGenerator, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_AEchoesWorldGenerator_NoRegister) \
	DECLARE_SERIALIZER(AEchoesWorldGenerator)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesWorldGenerator_h_49_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AEchoesWorldGenerator(AEchoesWorldGenerator&&) = delete; \
	AEchoesWorldGenerator(const AEchoesWorldGenerator&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEchoesWorldGenerator); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEchoesWorldGenerator); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AEchoesWorldGenerator) \
	NO_API virtual ~AEchoesWorldGenerator();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesWorldGenerator_h_46_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesWorldGenerator_h_49_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesWorldGenerator_h_49_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesWorldGenerator_h_49_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesWorldGenerator_h_49_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AEchoesWorldGenerator;

// ********** End Class AEchoesWorldGenerator ******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesWorldGenerator_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
