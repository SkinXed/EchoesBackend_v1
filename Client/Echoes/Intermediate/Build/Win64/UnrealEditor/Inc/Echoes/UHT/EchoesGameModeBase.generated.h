// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "EchoesGameModeBase.h"

#ifdef ECHOES_EchoesGameModeBase_generated_h
#error "EchoesGameModeBase.generated.h already included, missing '#pragma once' in EchoesGameModeBase.h"
#endif
#define ECHOES_EchoesGameModeBase_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AEchoesGameModeBase ******************************************************
ECHOES_API UClass* Z_Construct_UClass_AEchoesGameModeBase_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesGameModeBase_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEchoesGameModeBase(); \
	friend struct Z_Construct_UClass_AEchoesGameModeBase_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_AEchoesGameModeBase_NoRegister(); \
public: \
	DECLARE_CLASS2(AEchoesGameModeBase, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_AEchoesGameModeBase_NoRegister) \
	DECLARE_SERIALIZER(AEchoesGameModeBase)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesGameModeBase_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AEchoesGameModeBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	AEchoesGameModeBase(AEchoesGameModeBase&&) = delete; \
	AEchoesGameModeBase(const AEchoesGameModeBase&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEchoesGameModeBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEchoesGameModeBase); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AEchoesGameModeBase) \
	NO_API virtual ~AEchoesGameModeBase();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesGameModeBase_h_12_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesGameModeBase_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesGameModeBase_h_15_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesGameModeBase_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AEchoesGameModeBase;

// ********** End Class AEchoesGameModeBase ********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesGameModeBase_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
