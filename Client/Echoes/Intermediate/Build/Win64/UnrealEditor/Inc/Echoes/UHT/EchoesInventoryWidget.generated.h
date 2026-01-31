// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UI/EchoesInventoryWidget.h"

#ifdef ECHOES_EchoesInventoryWidget_generated_h
#error "EchoesInventoryWidget.generated.h already included, missing '#pragma once' in EchoesInventoryWidget.h"
#endif
#define ECHOES_EchoesInventoryWidget_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class AActor;
class UEchoesInventoryComponent;
class UEchoesInventoryItemObject;
class UObject;
struct FEchoesContainerItems;

// ********** Begin Class UEchoesInventoryWidget ***************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesInventoryWidget_h_37_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnItemSelectionChanged); \
	DECLARE_FUNCTION(execOnInventoryUpdated); \
	DECLARE_FUNCTION(execGetInventoryComponent); \
	DECLARE_FUNCTION(execUI_RequestMoveItem); \
	DECLARE_FUNCTION(execGetSelectedItem); \
	DECLARE_FUNCTION(execSetTargetActor); \
	DECLARE_FUNCTION(execRefreshInventory);


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesInventoryWidget_h_37_CALLBACK_WRAPPERS
ECHOES_API UClass* Z_Construct_UClass_UEchoesInventoryWidget_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesInventoryWidget_h_37_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEchoesInventoryWidget(); \
	friend struct Z_Construct_UClass_UEchoesInventoryWidget_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UEchoesInventoryWidget_NoRegister(); \
public: \
	DECLARE_CLASS2(UEchoesInventoryWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UEchoesInventoryWidget_NoRegister) \
	DECLARE_SERIALIZER(UEchoesInventoryWidget)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesInventoryWidget_h_37_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UEchoesInventoryWidget(UEchoesInventoryWidget&&) = delete; \
	UEchoesInventoryWidget(const UEchoesInventoryWidget&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEchoesInventoryWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEchoesInventoryWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UEchoesInventoryWidget) \
	NO_API virtual ~UEchoesInventoryWidget();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesInventoryWidget_h_34_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesInventoryWidget_h_37_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesInventoryWidget_h_37_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesInventoryWidget_h_37_CALLBACK_WRAPPERS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesInventoryWidget_h_37_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesInventoryWidget_h_37_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UEchoesInventoryWidget;

// ********** End Class UEchoesInventoryWidget *****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesInventoryWidget_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
