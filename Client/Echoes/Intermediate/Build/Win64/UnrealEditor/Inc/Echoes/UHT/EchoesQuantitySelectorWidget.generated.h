// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UI/Widgets/EchoesQuantitySelectorWidget.h"

#ifdef ECHOES_EchoesQuantitySelectorWidget_generated_h
#error "EchoesQuantitySelectorWidget.generated.h already included, missing '#pragma once' in EchoesQuantitySelectorWidget.h"
#endif
#define ECHOES_EchoesQuantitySelectorWidget_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Delegate FOnQuantitySelected ***************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesQuantitySelectorWidget_h_15_DELEGATE \
ECHOES_API void FOnQuantitySelected_DelegateWrapper(const FMulticastScriptDelegate& OnQuantitySelected, int64 SelectedQuantity);


// ********** End Delegate FOnQuantitySelected *****************************************************

// ********** Begin Delegate FOnQuantitySelectionCancelled *****************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesQuantitySelectorWidget_h_16_DELEGATE \
ECHOES_API void FOnQuantitySelectionCancelled_DelegateWrapper(const FMulticastScriptDelegate& OnQuantitySelectionCancelled);


// ********** End Delegate FOnQuantitySelectionCancelled *******************************************

// ********** Begin Class UEchoesQuantitySelectorWidget ********************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesQuantitySelectorWidget_h_39_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnQuantityTextCommitted); \
	DECLARE_FUNCTION(execOnSliderValueChanged); \
	DECLARE_FUNCTION(execOnMaxClicked); \
	DECLARE_FUNCTION(execOnCancelClicked); \
	DECLARE_FUNCTION(execOnConfirmClicked); \
	DECLARE_FUNCTION(execGetSelectedQuantity); \
	DECLARE_FUNCTION(execInitializeSelector);


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesQuantitySelectorWidget_h_39_CALLBACK_WRAPPERS
ECHOES_API UClass* Z_Construct_UClass_UEchoesQuantitySelectorWidget_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesQuantitySelectorWidget_h_39_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEchoesQuantitySelectorWidget(); \
	friend struct Z_Construct_UClass_UEchoesQuantitySelectorWidget_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UEchoesQuantitySelectorWidget_NoRegister(); \
public: \
	DECLARE_CLASS2(UEchoesQuantitySelectorWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UEchoesQuantitySelectorWidget_NoRegister) \
	DECLARE_SERIALIZER(UEchoesQuantitySelectorWidget)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesQuantitySelectorWidget_h_39_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UEchoesQuantitySelectorWidget(UEchoesQuantitySelectorWidget&&) = delete; \
	UEchoesQuantitySelectorWidget(const UEchoesQuantitySelectorWidget&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEchoesQuantitySelectorWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEchoesQuantitySelectorWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UEchoesQuantitySelectorWidget) \
	NO_API virtual ~UEchoesQuantitySelectorWidget();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesQuantitySelectorWidget_h_36_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesQuantitySelectorWidget_h_39_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesQuantitySelectorWidget_h_39_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesQuantitySelectorWidget_h_39_CALLBACK_WRAPPERS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesQuantitySelectorWidget_h_39_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesQuantitySelectorWidget_h_39_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UEchoesQuantitySelectorWidget;

// ********** End Class UEchoesQuantitySelectorWidget **********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesQuantitySelectorWidget_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
