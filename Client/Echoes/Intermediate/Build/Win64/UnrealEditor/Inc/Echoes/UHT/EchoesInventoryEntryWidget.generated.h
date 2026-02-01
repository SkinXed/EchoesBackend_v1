// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UI/EchoesInventoryEntryWidget.h"

#ifdef ECHOES_EchoesInventoryEntryWidget_generated_h
#error "EchoesInventoryEntryWidget.generated.h already included, missing '#pragma once' in EchoesInventoryEntryWidget.h"
#endif
#define ECHOES_EchoesInventoryEntryWidget_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class UEchoesInventoryItemObject;
class UTexture2D;

// ********** Begin Class UEchoesInventoryEntryWidget **********************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesInventoryEntryWidget_h_34_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandleStackAllFailure); \
	DECLARE_FUNCTION(execHandleStackAllSuccess); \
	DECLARE_FUNCTION(execHandleJettisonFailure); \
	DECLARE_FUNCTION(execHandleJettisonSuccess); \
	DECLARE_FUNCTION(execOnJettisonQuantityCancelled); \
	DECLARE_FUNCTION(execOnJettisonQuantitySelected); \
	DECLARE_FUNCTION(execOnDragQuantityCancelled); \
	DECLARE_FUNCTION(execOnDragQuantitySelected); \
	DECLARE_FUNCTION(execHandleContextMenuAction); \
	DECLARE_FUNCTION(execHandleIconLoaded); \
	DECLARE_FUNCTION(execSetItemData);


ECHOES_API UClass* Z_Construct_UClass_UEchoesInventoryEntryWidget_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesInventoryEntryWidget_h_34_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEchoesInventoryEntryWidget(); \
	friend struct Z_Construct_UClass_UEchoesInventoryEntryWidget_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UEchoesInventoryEntryWidget_NoRegister(); \
public: \
	DECLARE_CLASS2(UEchoesInventoryEntryWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UEchoesInventoryEntryWidget_NoRegister) \
	DECLARE_SERIALIZER(UEchoesInventoryEntryWidget) \
	virtual UObject* _getUObject() const override { return const_cast<UEchoesInventoryEntryWidget*>(this); }


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesInventoryEntryWidget_h_34_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UEchoesInventoryEntryWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UEchoesInventoryEntryWidget(UEchoesInventoryEntryWidget&&) = delete; \
	UEchoesInventoryEntryWidget(const UEchoesInventoryEntryWidget&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEchoesInventoryEntryWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEchoesInventoryEntryWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UEchoesInventoryEntryWidget) \
	NO_API virtual ~UEchoesInventoryEntryWidget();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesInventoryEntryWidget_h_31_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesInventoryEntryWidget_h_34_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesInventoryEntryWidget_h_34_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesInventoryEntryWidget_h_34_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesInventoryEntryWidget_h_34_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UEchoesInventoryEntryWidget;

// ********** End Class UEchoesInventoryEntryWidget ************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesInventoryEntryWidget_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
