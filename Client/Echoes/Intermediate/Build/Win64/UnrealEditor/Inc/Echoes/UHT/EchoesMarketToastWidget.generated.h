// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UI/Widgets/EchoesMarketToastWidget.h"

#ifdef ECHOES_EchoesMarketToastWidget_generated_h
#error "EchoesMarketToastWidget.generated.h already included, missing '#pragma once' in EchoesMarketToastWidget.h"
#endif
#define ECHOES_EchoesMarketToastWidget_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

struct FMarketTradeResult;

// ********** Begin Class UEchoesMarketToastWidget *************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMarketToastWidget_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execShowMessage); \
	DECLARE_FUNCTION(execShowTradeConfirmation);


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMarketToastWidget_h_29_CALLBACK_WRAPPERS
ECHOES_API UClass* Z_Construct_UClass_UEchoesMarketToastWidget_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMarketToastWidget_h_29_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEchoesMarketToastWidget(); \
	friend struct Z_Construct_UClass_UEchoesMarketToastWidget_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UEchoesMarketToastWidget_NoRegister(); \
public: \
	DECLARE_CLASS2(UEchoesMarketToastWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UEchoesMarketToastWidget_NoRegister) \
	DECLARE_SERIALIZER(UEchoesMarketToastWidget)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMarketToastWidget_h_29_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UEchoesMarketToastWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UEchoesMarketToastWidget(UEchoesMarketToastWidget&&) = delete; \
	UEchoesMarketToastWidget(const UEchoesMarketToastWidget&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEchoesMarketToastWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEchoesMarketToastWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UEchoesMarketToastWidget) \
	NO_API virtual ~UEchoesMarketToastWidget();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMarketToastWidget_h_26_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMarketToastWidget_h_29_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMarketToastWidget_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMarketToastWidget_h_29_CALLBACK_WRAPPERS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMarketToastWidget_h_29_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMarketToastWidget_h_29_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UEchoesMarketToastWidget;

// ********** End Class UEchoesMarketToastWidget ***************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMarketToastWidget_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
