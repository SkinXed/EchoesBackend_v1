// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "EchoesMenuPlayerController.h"

#ifdef ECHOES_EchoesMenuPlayerController_generated_h
#error "EchoesMenuPlayerController.generated.h already included, missing '#pragma once' in EchoesMenuPlayerController.h"
#endif
#define ECHOES_EchoesMenuPlayerController_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

enum class ENextState : uint8;
struct FAuthResponse;

// ********** Begin Class AEchoesMenuPlayerController **********************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesMenuPlayerController_h_45_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnLoginSuccess); \
	DECLARE_FUNCTION(execOnPreloadComplete); \
	DECLARE_FUNCTION(execShowCharacterSelect); \
	DECLARE_FUNCTION(execShowLoginScreen);


ECHOES_API UClass* Z_Construct_UClass_AEchoesMenuPlayerController_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesMenuPlayerController_h_45_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEchoesMenuPlayerController(); \
	friend struct Z_Construct_UClass_AEchoesMenuPlayerController_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_AEchoesMenuPlayerController_NoRegister(); \
public: \
	DECLARE_CLASS2(AEchoesMenuPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_AEchoesMenuPlayerController_NoRegister) \
	DECLARE_SERIALIZER(AEchoesMenuPlayerController)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesMenuPlayerController_h_45_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AEchoesMenuPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	AEchoesMenuPlayerController(AEchoesMenuPlayerController&&) = delete; \
	AEchoesMenuPlayerController(const AEchoesMenuPlayerController&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEchoesMenuPlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEchoesMenuPlayerController); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AEchoesMenuPlayerController) \
	NO_API virtual ~AEchoesMenuPlayerController();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesMenuPlayerController_h_42_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesMenuPlayerController_h_45_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesMenuPlayerController_h_45_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesMenuPlayerController_h_45_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesMenuPlayerController_h_45_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AEchoesMenuPlayerController;

// ********** End Class AEchoesMenuPlayerController ************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesMenuPlayerController_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
