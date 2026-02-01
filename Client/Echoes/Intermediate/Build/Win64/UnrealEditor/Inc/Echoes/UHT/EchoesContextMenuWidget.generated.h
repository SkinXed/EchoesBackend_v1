// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UI/EchoesContextMenuWidget.h"

#ifdef ECHOES_EchoesContextMenuWidget_generated_h
#error "EchoesContextMenuWidget.generated.h already included, missing '#pragma once' in EchoesContextMenuWidget.h"
#endif
#define ECHOES_EchoesContextMenuWidget_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class AActor;
class UEchoesInventoryItemObject;
struct FContextMenuAction;
struct FGuid;

// ********** Begin Class UEchoesContextMenuActionButton *******************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesContextMenuWidget_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandleClicked);


ECHOES_API UClass* Z_Construct_UClass_UEchoesContextMenuActionButton_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesContextMenuWidget_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEchoesContextMenuActionButton(); \
	friend struct Z_Construct_UClass_UEchoesContextMenuActionButton_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UEchoesContextMenuActionButton_NoRegister(); \
public: \
	DECLARE_CLASS2(UEchoesContextMenuActionButton, UButton, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UEchoesContextMenuActionButton_NoRegister) \
	DECLARE_SERIALIZER(UEchoesContextMenuActionButton)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesContextMenuWidget_h_19_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UEchoesContextMenuActionButton(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UEchoesContextMenuActionButton(UEchoesContextMenuActionButton&&) = delete; \
	UEchoesContextMenuActionButton(const UEchoesContextMenuActionButton&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEchoesContextMenuActionButton); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEchoesContextMenuActionButton); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UEchoesContextMenuActionButton) \
	NO_API virtual ~UEchoesContextMenuActionButton();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesContextMenuWidget_h_16_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesContextMenuWidget_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesContextMenuWidget_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesContextMenuWidget_h_19_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesContextMenuWidget_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UEchoesContextMenuActionButton;

// ********** End Class UEchoesContextMenuActionButton *********************************************

// ********** Begin Delegate FOnContextMenuActionSelected ******************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesContextMenuWidget_h_33_DELEGATE \
ECHOES_API void FOnContextMenuActionSelected_DelegateWrapper(const FMulticastScriptDelegate& OnContextMenuActionSelected, const FString& ActionName);


// ********** End Delegate FOnContextMenuActionSelected ********************************************

// ********** Begin ScriptStruct FContextMenuAction ************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesContextMenuWidget_h_41_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FContextMenuAction_Statics; \
	ECHOES_API static class UScriptStruct* StaticStruct();


struct FContextMenuAction;
// ********** End ScriptStruct FContextMenuAction **************************************************

// ********** Begin Class UEchoesContextMenuWidget *************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesContextMenuWidget_h_96_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandleActionButtonClicked); \
	DECLARE_FUNCTION(execGetSourceActor); \
	DECLARE_FUNCTION(execGetSourceStorageId); \
	DECLARE_FUNCTION(execGetItemObject); \
	DECLARE_FUNCTION(execCloseMenu); \
	DECLARE_FUNCTION(execPositionAtMouse); \
	DECLARE_FUNCTION(execInitializeMenu);


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesContextMenuWidget_h_96_CALLBACK_WRAPPERS
ECHOES_API UClass* Z_Construct_UClass_UEchoesContextMenuWidget_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesContextMenuWidget_h_96_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEchoesContextMenuWidget(); \
	friend struct Z_Construct_UClass_UEchoesContextMenuWidget_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UEchoesContextMenuWidget_NoRegister(); \
public: \
	DECLARE_CLASS2(UEchoesContextMenuWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UEchoesContextMenuWidget_NoRegister) \
	DECLARE_SERIALIZER(UEchoesContextMenuWidget)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesContextMenuWidget_h_96_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UEchoesContextMenuWidget(UEchoesContextMenuWidget&&) = delete; \
	UEchoesContextMenuWidget(const UEchoesContextMenuWidget&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEchoesContextMenuWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEchoesContextMenuWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UEchoesContextMenuWidget) \
	NO_API virtual ~UEchoesContextMenuWidget();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesContextMenuWidget_h_93_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesContextMenuWidget_h_96_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesContextMenuWidget_h_96_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesContextMenuWidget_h_96_CALLBACK_WRAPPERS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesContextMenuWidget_h_96_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesContextMenuWidget_h_96_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UEchoesContextMenuWidget;

// ********** End Class UEchoesContextMenuWidget ***************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesContextMenuWidget_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
