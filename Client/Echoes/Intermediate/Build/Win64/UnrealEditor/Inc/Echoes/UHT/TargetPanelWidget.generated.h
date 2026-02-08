// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UI/Widgets/SpaceHUD/TargetPanelWidget.h"

#ifdef ECHOES_TargetPanelWidget_generated_h
#error "TargetPanelWidget.generated.h already included, missing '#pragma once' in TargetPanelWidget.h"
#endif
#define ECHOES_TargetPanelWidget_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class AActor;
class UTargetingComponent;
class UTargetItemWidget;
enum class ETargetLockState : uint8;
struct FTargetPanelData;

// ********** Begin ScriptStruct FTargetPanelData **************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_TargetPanelWidget_h_24_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FTargetPanelData_Statics; \
	ECHOES_API static class UScriptStruct* StaticStruct();


struct FTargetPanelData;
// ********** End ScriptStruct FTargetPanelData ****************************************************

// ********** Begin Delegate FOnTargetStateChanged *************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_TargetPanelWidget_h_75_DELEGATE \
ECHOES_API void FOnTargetStateChanged_DelegateWrapper(const FMulticastScriptDelegate& OnTargetStateChanged, AActor* Target, FTargetPanelData const& TargetData);


// ********** End Delegate FOnTargetStateChanged ***************************************************

// ********** Begin Delegate FOnTargetSelected *****************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_TargetPanelWidget_h_80_DELEGATE \
ECHOES_API void FOnTargetSelected_DelegateWrapper(const FMulticastScriptDelegate& OnTargetSelected, AActor* Target);


// ********** End Delegate FOnTargetSelected *******************************************************

// ********** Begin Class UTargetItemWidget ********************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_TargetPanelWidget_h_95_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetTargetActor); \
	DECLARE_FUNCTION(execGetTargetData); \
	DECLARE_FUNCTION(execSetTargetData);


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_TargetPanelWidget_h_95_CALLBACK_WRAPPERS
ECHOES_API UClass* Z_Construct_UClass_UTargetItemWidget_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_TargetPanelWidget_h_95_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUTargetItemWidget(); \
	friend struct Z_Construct_UClass_UTargetItemWidget_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UTargetItemWidget_NoRegister(); \
public: \
	DECLARE_CLASS2(UTargetItemWidget, UUserWidget, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UTargetItemWidget_NoRegister) \
	DECLARE_SERIALIZER(UTargetItemWidget)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_TargetPanelWidget_h_95_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UTargetItemWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UTargetItemWidget(UTargetItemWidget&&) = delete; \
	UTargetItemWidget(const UTargetItemWidget&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UTargetItemWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UTargetItemWidget); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UTargetItemWidget) \
	NO_API virtual ~UTargetItemWidget();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_TargetPanelWidget_h_92_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_TargetPanelWidget_h_95_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_TargetPanelWidget_h_95_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_TargetPanelWidget_h_95_CALLBACK_WRAPPERS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_TargetPanelWidget_h_95_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_TargetPanelWidget_h_95_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UTargetItemWidget;

// ********** End Class UTargetItemWidget **********************************************************

// ********** Begin Class UTargetPanelWidget *******************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_TargetPanelWidget_h_206_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandleLockProgress); \
	DECLARE_FUNCTION(execHandleLockLost); \
	DECLARE_FUNCTION(execHandleLockCompleted); \
	DECLARE_FUNCTION(execHandleLockStarted); \
	DECLARE_FUNCTION(execGetTargetItemWidget); \
	DECLARE_FUNCTION(execClearAllTargets); \
	DECLARE_FUNCTION(execClientOnly_UpdateTarget); \
	DECLARE_FUNCTION(execClientOnly_RemoveTarget); \
	DECLARE_FUNCTION(execClientOnly_AddTarget); \
	DECLARE_FUNCTION(execUnbindFromTargetingComponent); \
	DECLARE_FUNCTION(execBindToTargetingComponent);


ECHOES_API UClass* Z_Construct_UClass_UTargetPanelWidget_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_TargetPanelWidget_h_206_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUTargetPanelWidget(); \
	friend struct Z_Construct_UClass_UTargetPanelWidget_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UTargetPanelWidget_NoRegister(); \
public: \
	DECLARE_CLASS2(UTargetPanelWidget, UUserWidget, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UTargetPanelWidget_NoRegister) \
	DECLARE_SERIALIZER(UTargetPanelWidget)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_TargetPanelWidget_h_206_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UTargetPanelWidget(UTargetPanelWidget&&) = delete; \
	UTargetPanelWidget(const UTargetPanelWidget&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UTargetPanelWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UTargetPanelWidget); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UTargetPanelWidget) \
	NO_API virtual ~UTargetPanelWidget();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_TargetPanelWidget_h_203_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_TargetPanelWidget_h_206_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_TargetPanelWidget_h_206_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_TargetPanelWidget_h_206_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_TargetPanelWidget_h_206_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UTargetPanelWidget;

// ********** End Class UTargetPanelWidget *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_TargetPanelWidget_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
