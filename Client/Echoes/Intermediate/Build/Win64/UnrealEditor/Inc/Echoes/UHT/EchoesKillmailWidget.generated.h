// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UI/Widgets/EchoesKillmailWidget.h"

#ifdef ECHOES_EchoesKillmailWidget_generated_h
#error "EchoesKillmailWidget.generated.h already included, missing '#pragma once' in EchoesKillmailWidget.h"
#endif
#define ECHOES_EchoesKillmailWidget_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

struct FKillmailAttacker;
struct FKillmailData;
struct FKillmailItem;

// ********** Begin Class UEchoesKillmailWidget ****************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesKillmailWidget_h_35_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSetKillmailData);


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesKillmailWidget_h_35_CALLBACK_WRAPPERS
ECHOES_API UClass* Z_Construct_UClass_UEchoesKillmailWidget_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesKillmailWidget_h_35_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEchoesKillmailWidget(); \
	friend struct Z_Construct_UClass_UEchoesKillmailWidget_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UEchoesKillmailWidget_NoRegister(); \
public: \
	DECLARE_CLASS2(UEchoesKillmailWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UEchoesKillmailWidget_NoRegister) \
	DECLARE_SERIALIZER(UEchoesKillmailWidget)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesKillmailWidget_h_35_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UEchoesKillmailWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UEchoesKillmailWidget(UEchoesKillmailWidget&&) = delete; \
	UEchoesKillmailWidget(const UEchoesKillmailWidget&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEchoesKillmailWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEchoesKillmailWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UEchoesKillmailWidget) \
	NO_API virtual ~UEchoesKillmailWidget();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesKillmailWidget_h_32_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesKillmailWidget_h_35_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesKillmailWidget_h_35_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesKillmailWidget_h_35_CALLBACK_WRAPPERS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesKillmailWidget_h_35_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesKillmailWidget_h_35_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UEchoesKillmailWidget;

// ********** End Class UEchoesKillmailWidget ******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesKillmailWidget_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
