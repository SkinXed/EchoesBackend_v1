// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UI/Widgets/EchoesCharacterSelectWidget.h"

#ifdef ECHOES_EchoesCharacterSelectWidget_generated_h
#error "EchoesCharacterSelectWidget.generated.h already included, missing '#pragma once' in EchoesCharacterSelectWidget.h"
#endif
#define ECHOES_EchoesCharacterSelectWidget_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

struct FCharacterData;
struct FGuid;

// ********** Begin Class UCharacterListItem *******************************************************
ECHOES_API UClass* Z_Construct_UClass_UCharacterListItem_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesCharacterSelectWidget_h_25_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCharacterListItem(); \
	friend struct Z_Construct_UClass_UCharacterListItem_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UCharacterListItem_NoRegister(); \
public: \
	DECLARE_CLASS2(UCharacterListItem, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UCharacterListItem_NoRegister) \
	DECLARE_SERIALIZER(UCharacterListItem)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesCharacterSelectWidget_h_25_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCharacterListItem(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UCharacterListItem(UCharacterListItem&&) = delete; \
	UCharacterListItem(const UCharacterListItem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCharacterListItem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCharacterListItem); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCharacterListItem) \
	NO_API virtual ~UCharacterListItem();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesCharacterSelectWidget_h_22_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesCharacterSelectWidget_h_25_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesCharacterSelectWidget_h_25_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesCharacterSelectWidget_h_25_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UCharacterListItem;

// ********** End Class UCharacterListItem *********************************************************

// ********** Begin Class UEchoesCharacterSelectWidget *********************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesCharacterSelectWidget_h_45_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandleCharacterCreationFailed); \
	DECLARE_FUNCTION(execHandleCharacterCreated); \
	DECLARE_FUNCTION(execOnRaceSelectionChanged); \
	DECLARE_FUNCTION(execOnCancelCreateButtonClicked); \
	DECLARE_FUNCTION(execOnConfirmCreateButtonClicked); \
	DECLARE_FUNCTION(execOnLogoutButtonClicked); \
	DECLARE_FUNCTION(execOnDeleteButtonClicked); \
	DECLARE_FUNCTION(execOnCreateButtonClicked); \
	DECLARE_FUNCTION(execOnSelectButtonClicked); \
	DECLARE_FUNCTION(execOnCharacterSelected);


ECHOES_API UClass* Z_Construct_UClass_UEchoesCharacterSelectWidget_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesCharacterSelectWidget_h_45_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEchoesCharacterSelectWidget(); \
	friend struct Z_Construct_UClass_UEchoesCharacterSelectWidget_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UEchoesCharacterSelectWidget_NoRegister(); \
public: \
	DECLARE_CLASS2(UEchoesCharacterSelectWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UEchoesCharacterSelectWidget_NoRegister) \
	DECLARE_SERIALIZER(UEchoesCharacterSelectWidget)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesCharacterSelectWidget_h_45_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UEchoesCharacterSelectWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UEchoesCharacterSelectWidget(UEchoesCharacterSelectWidget&&) = delete; \
	UEchoesCharacterSelectWidget(const UEchoesCharacterSelectWidget&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEchoesCharacterSelectWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEchoesCharacterSelectWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UEchoesCharacterSelectWidget) \
	NO_API virtual ~UEchoesCharacterSelectWidget();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesCharacterSelectWidget_h_42_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesCharacterSelectWidget_h_45_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesCharacterSelectWidget_h_45_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesCharacterSelectWidget_h_45_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesCharacterSelectWidget_h_45_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UEchoesCharacterSelectWidget;

// ********** End Class UEchoesCharacterSelectWidget ***********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesCharacterSelectWidget_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
