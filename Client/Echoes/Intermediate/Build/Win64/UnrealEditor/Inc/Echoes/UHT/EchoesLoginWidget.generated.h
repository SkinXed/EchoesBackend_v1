// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UI/EchoesLoginWidget.h"

#ifdef ECHOES_EchoesLoginWidget_generated_h
#error "EchoesLoginWidget.generated.h already included, missing '#pragma once' in EchoesLoginWidget.h"
#endif
#define ECHOES_EchoesLoginWidget_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

struct FAuthResponse;

// ********** Begin Delegate FOnLoginSuccessEvent **************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesLoginWidget_h_9_DELEGATE \
ECHOES_API void FOnLoginSuccessEvent_DelegateWrapper(const FMulticastScriptDelegate& OnLoginSuccessEvent, FAuthResponse const& AuthResponse);


// ********** End Delegate FOnLoginSuccessEvent ****************************************************

// ********** Begin Delegate FOnLoginFailureEvent **************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesLoginWidget_h_10_DELEGATE \
ECHOES_API void FOnLoginFailureEvent_DelegateWrapper(const FMulticastScriptDelegate& OnLoginFailureEvent, const FString& ErrorMessage);


// ********** End Delegate FOnLoginFailureEvent ****************************************************

// ********** Begin Class UEchoesLoginWidget *******************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesLoginWidget_h_30_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnPasswordCommitted); \
	DECLARE_FUNCTION(execOnRegisterButtonClicked); \
	DECLARE_FUNCTION(execOnLoginButtonClicked);


ECHOES_API UClass* Z_Construct_UClass_UEchoesLoginWidget_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesLoginWidget_h_30_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEchoesLoginWidget(); \
	friend struct Z_Construct_UClass_UEchoesLoginWidget_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UEchoesLoginWidget_NoRegister(); \
public: \
	DECLARE_CLASS2(UEchoesLoginWidget, UEchoesWindowBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UEchoesLoginWidget_NoRegister) \
	DECLARE_SERIALIZER(UEchoesLoginWidget)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesLoginWidget_h_30_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UEchoesLoginWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UEchoesLoginWidget(UEchoesLoginWidget&&) = delete; \
	UEchoesLoginWidget(const UEchoesLoginWidget&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEchoesLoginWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEchoesLoginWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UEchoesLoginWidget) \
	NO_API virtual ~UEchoesLoginWidget();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesLoginWidget_h_27_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesLoginWidget_h_30_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesLoginWidget_h_30_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesLoginWidget_h_30_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesLoginWidget_h_30_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UEchoesLoginWidget;

// ********** End Class UEchoesLoginWidget *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesLoginWidget_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
