// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UI/EchoesWindowBase.h"

#ifdef ECHOES_EchoesWindowBase_generated_h
#error "EchoesWindowBase.generated.h already included, missing '#pragma once' in EchoesWindowBase.h"
#endif
#define ECHOES_EchoesWindowBase_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UEchoesWindowBase ********************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesWindowBase_h_41_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnCloseButtonClicked); \
	DECLARE_FUNCTION(execLoadWindowPosition); \
	DECLARE_FUNCTION(execSaveWindowPosition); \
	DECLARE_FUNCTION(execBringToFront); \
	DECLARE_FUNCTION(execGetWindowSize); \
	DECLARE_FUNCTION(execSetWindowSize); \
	DECLARE_FUNCTION(execGetWindowPosition); \
	DECLARE_FUNCTION(execSetWindowPosition); \
	DECLARE_FUNCTION(execCloseWindow); \
	DECLARE_FUNCTION(execGetWindowTitle); \
	DECLARE_FUNCTION(execSetWindowTitle);


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesWindowBase_h_41_CALLBACK_WRAPPERS
ECHOES_API UClass* Z_Construct_UClass_UEchoesWindowBase_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesWindowBase_h_41_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEchoesWindowBase(); \
	friend struct Z_Construct_UClass_UEchoesWindowBase_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UEchoesWindowBase_NoRegister(); \
public: \
	DECLARE_CLASS2(UEchoesWindowBase, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UEchoesWindowBase_NoRegister) \
	DECLARE_SERIALIZER(UEchoesWindowBase)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesWindowBase_h_41_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UEchoesWindowBase(UEchoesWindowBase&&) = delete; \
	UEchoesWindowBase(const UEchoesWindowBase&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEchoesWindowBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEchoesWindowBase); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UEchoesWindowBase) \
	NO_API virtual ~UEchoesWindowBase();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesWindowBase_h_38_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesWindowBase_h_41_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesWindowBase_h_41_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesWindowBase_h_41_CALLBACK_WRAPPERS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesWindowBase_h_41_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesWindowBase_h_41_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UEchoesWindowBase;

// ********** End Class UEchoesWindowBase **********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesWindowBase_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
