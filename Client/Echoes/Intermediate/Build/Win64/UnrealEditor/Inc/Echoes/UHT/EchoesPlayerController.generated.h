// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "EchoesPlayerController.h"

#ifdef ECHOES_EchoesPlayerController_generated_h
#error "EchoesPlayerController.generated.h already included, missing '#pragma once' in EchoesPlayerController.h"
#endif
#define ECHOES_EchoesPlayerController_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AEchoesPlayerController **************************************************
ECHOES_API UClass* Z_Construct_UClass_AEchoesPlayerController_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesPlayerController_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEchoesPlayerController(); \
	friend struct Z_Construct_UClass_AEchoesPlayerController_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_AEchoesPlayerController_NoRegister(); \
public: \
	DECLARE_CLASS2(AEchoesPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_AEchoesPlayerController_NoRegister) \
	DECLARE_SERIALIZER(AEchoesPlayerController)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesPlayerController_h_12_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AEchoesPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	AEchoesPlayerController(AEchoesPlayerController&&) = delete; \
	AEchoesPlayerController(const AEchoesPlayerController&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEchoesPlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEchoesPlayerController); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AEchoesPlayerController) \
	NO_API virtual ~AEchoesPlayerController();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesPlayerController_h_9_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesPlayerController_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesPlayerController_h_12_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesPlayerController_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AEchoesPlayerController;

// ********** End Class AEchoesPlayerController ****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesPlayerController_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
