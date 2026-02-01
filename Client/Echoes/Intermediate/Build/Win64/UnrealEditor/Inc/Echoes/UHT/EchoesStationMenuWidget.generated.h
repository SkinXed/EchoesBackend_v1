// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UI/Widgets/EchoesStationMenuWidget.h"

#ifdef ECHOES_EchoesStationMenuWidget_generated_h
#error "EchoesStationMenuWidget.generated.h already included, missing '#pragma once' in EchoesStationMenuWidget.h"
#endif
#define ECHOES_EchoesStationMenuWidget_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

struct FGuid;

// ********** Begin Delegate FOnInventoryButtonClicked *********************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesStationMenuWidget_h_14_DELEGATE \
ECHOES_API void FOnInventoryButtonClicked_DelegateWrapper(const FMulticastScriptDelegate& OnInventoryButtonClicked);


// ********** End Delegate FOnInventoryButtonClicked ***********************************************

// ********** Begin Delegate FOnUndockButtonClicked ************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesStationMenuWidget_h_15_DELEGATE \
ECHOES_API void FOnUndockButtonClicked_DelegateWrapper(const FMulticastScriptDelegate& OnUndockButtonClicked);


// ********** End Delegate FOnUndockButtonClicked **************************************************

// ********** Begin Delegate FOnRepairButtonClicked ************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesStationMenuWidget_h_16_DELEGATE \
ECHOES_API void FOnRepairButtonClicked_DelegateWrapper(const FMulticastScriptDelegate& OnRepairButtonClicked);


// ********** End Delegate FOnRepairButtonClicked **************************************************

// ********** Begin Class UEchoesStationMenuWidget *************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesStationMenuWidget_h_39_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execRequestUndock); \
	DECLARE_FUNCTION(execOpenShipCargo); \
	DECLARE_FUNCTION(execOpenPersonalHangar); \
	DECLARE_FUNCTION(execOnRepairButtonPressed); \
	DECLARE_FUNCTION(execOnUndockButtonPressed); \
	DECLARE_FUNCTION(execOnInventoryButtonPressed); \
	DECLARE_FUNCTION(execGetHangarStorageId); \
	DECLARE_FUNCTION(execGetStationId); \
	DECLARE_FUNCTION(execInitializeStationMenu);


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesStationMenuWidget_h_39_CALLBACK_WRAPPERS
ECHOES_API UClass* Z_Construct_UClass_UEchoesStationMenuWidget_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesStationMenuWidget_h_39_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEchoesStationMenuWidget(); \
	friend struct Z_Construct_UClass_UEchoesStationMenuWidget_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UEchoesStationMenuWidget_NoRegister(); \
public: \
	DECLARE_CLASS2(UEchoesStationMenuWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UEchoesStationMenuWidget_NoRegister) \
	DECLARE_SERIALIZER(UEchoesStationMenuWidget)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesStationMenuWidget_h_39_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UEchoesStationMenuWidget(UEchoesStationMenuWidget&&) = delete; \
	UEchoesStationMenuWidget(const UEchoesStationMenuWidget&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEchoesStationMenuWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEchoesStationMenuWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UEchoesStationMenuWidget) \
	NO_API virtual ~UEchoesStationMenuWidget();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesStationMenuWidget_h_36_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesStationMenuWidget_h_39_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesStationMenuWidget_h_39_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesStationMenuWidget_h_39_CALLBACK_WRAPPERS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesStationMenuWidget_h_39_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesStationMenuWidget_h_39_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UEchoesStationMenuWidget;

// ********** End Class UEchoesStationMenuWidget ***************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesStationMenuWidget_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
