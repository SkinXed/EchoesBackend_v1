// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UI/Widgets/EchoesMarketOrderEntryWidget.h"

#ifdef ECHOES_EchoesMarketOrderEntryWidget_generated_h
#error "EchoesMarketOrderEntryWidget.generated.h already included, missing '#pragma once' in EchoesMarketOrderEntryWidget.h"
#endif
#define ECHOES_EchoesMarketOrderEntryWidget_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class UEchoesMarketOrderObject;
struct FMarketOrderDto;
struct FSlateColor;

// ********** Begin Class UEchoesMarketOrderEntryWidget ********************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMarketOrderEntryWidget_h_33_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetOrderTypeColor); \
	DECLARE_FUNCTION(execSetOrderData);


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMarketOrderEntryWidget_h_33_CALLBACK_WRAPPERS
ECHOES_API UClass* Z_Construct_UClass_UEchoesMarketOrderEntryWidget_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMarketOrderEntryWidget_h_33_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEchoesMarketOrderEntryWidget(); \
	friend struct Z_Construct_UClass_UEchoesMarketOrderEntryWidget_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UEchoesMarketOrderEntryWidget_NoRegister(); \
public: \
	DECLARE_CLASS2(UEchoesMarketOrderEntryWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UEchoesMarketOrderEntryWidget_NoRegister) \
	DECLARE_SERIALIZER(UEchoesMarketOrderEntryWidget) \
	virtual UObject* _getUObject() const override { return const_cast<UEchoesMarketOrderEntryWidget*>(this); }


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMarketOrderEntryWidget_h_33_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UEchoesMarketOrderEntryWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UEchoesMarketOrderEntryWidget(UEchoesMarketOrderEntryWidget&&) = delete; \
	UEchoesMarketOrderEntryWidget(const UEchoesMarketOrderEntryWidget&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEchoesMarketOrderEntryWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEchoesMarketOrderEntryWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UEchoesMarketOrderEntryWidget) \
	NO_API virtual ~UEchoesMarketOrderEntryWidget();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMarketOrderEntryWidget_h_30_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMarketOrderEntryWidget_h_33_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMarketOrderEntryWidget_h_33_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMarketOrderEntryWidget_h_33_CALLBACK_WRAPPERS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMarketOrderEntryWidget_h_33_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMarketOrderEntryWidget_h_33_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UEchoesMarketOrderEntryWidget;

// ********** End Class UEchoesMarketOrderEntryWidget **********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMarketOrderEntryWidget_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
