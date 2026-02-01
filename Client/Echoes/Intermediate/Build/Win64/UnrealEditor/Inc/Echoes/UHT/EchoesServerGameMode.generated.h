// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "EchoesServerGameMode.h"

#ifdef ECHOES_EchoesServerGameMode_generated_h
#error "EchoesServerGameMode.generated.h already included, missing '#pragma once' in EchoesServerGameMode.h"
#endif
#define ECHOES_EchoesServerGameMode_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class UEchoesJumpManager;
struct FServerSystemConfig;

// ********** Begin Delegate FOnEntryFlowComplete **************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesServerGameMode_h_15_DELEGATE \
ECHOES_API void FOnEntryFlowComplete_DelegateWrapper(const FMulticastScriptDelegate& OnEntryFlowComplete);


// ********** End Delegate FOnEntryFlowComplete ****************************************************

// ********** Begin ScriptStruct FCharacterLocationData ********************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesServerGameMode_h_23_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FCharacterLocationData_Statics; \
	ECHOES_API static class UScriptStruct* StaticStruct();


struct FCharacterLocationData;
// ********** End ScriptStruct FCharacterLocationData **********************************************

// ********** Begin Class AEchoesServerGameMode ****************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesServerGameMode_h_80_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnServerConfigReceived); \
	DECLARE_FUNCTION(execTriggerWorldGeneration); \
	DECLARE_FUNCTION(execGetJumpManager); \
	DECLARE_FUNCTION(execIsWorldGenerated);


ECHOES_API UClass* Z_Construct_UClass_AEchoesServerGameMode_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesServerGameMode_h_80_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEchoesServerGameMode(); \
	friend struct Z_Construct_UClass_AEchoesServerGameMode_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_AEchoesServerGameMode_NoRegister(); \
public: \
	DECLARE_CLASS2(AEchoesServerGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_AEchoesServerGameMode_NoRegister) \
	DECLARE_SERIALIZER(AEchoesServerGameMode)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesServerGameMode_h_80_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AEchoesServerGameMode(AEchoesServerGameMode&&) = delete; \
	AEchoesServerGameMode(const AEchoesServerGameMode&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEchoesServerGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEchoesServerGameMode); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AEchoesServerGameMode) \
	NO_API virtual ~AEchoesServerGameMode();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesServerGameMode_h_77_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesServerGameMode_h_80_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesServerGameMode_h_80_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesServerGameMode_h_80_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesServerGameMode_h_80_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AEchoesServerGameMode;

// ********** End Class AEchoesServerGameMode ******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesServerGameMode_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
