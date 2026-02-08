// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UI/Widgets/Fitting/ModulePanelWidget.h"

#ifdef ECHOES_ModulePanelWidget_generated_h
#error "ModulePanelWidget.generated.h already included, missing '#pragma once' in ModulePanelWidget.h"
#endif
#define ECHOES_ModulePanelWidget_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class IShipFittingInterface;
class UModuleSlotWidget;
enum class EModuleState : uint8;
enum class ESlotType : uint8;
struct FCommon_ItemSlot;

// ********** Begin Delegate FOnModuleToggled ******************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_ModulePanelWidget_h_17_DELEGATE \
ECHOES_API void FOnModuleToggled_DelegateWrapper(const FMulticastScriptDelegate& OnModuleToggled);


// ********** End Delegate FOnModuleToggled ********************************************************

// ********** Begin Class UModulePanelWidget *******************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_ModulePanelWidget_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandleSlotClicked); \
	DECLARE_FUNCTION(execCommon_GetShipFittingInterface); \
	DECLARE_FUNCTION(execCommon_HasActiveModules); \
	DECLARE_FUNCTION(execCommon_GetSlotWidget); \
	DECLARE_FUNCTION(execServerRPC_DeactivateAll); \
	DECLARE_FUNCTION(execServerRPC_ToggleModule); \
	DECLARE_FUNCTION(execClientOnly_UpdateSlot); \
	DECLARE_FUNCTION(execClientOnly_RefreshAllModules); \
	DECLARE_FUNCTION(execClientOnly_UpdateModuleState); \
	DECLARE_FUNCTION(execClientOnly_UpdateCooldown);


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_ModulePanelWidget_h_27_CALLBACK_WRAPPERS
ECHOES_API UClass* Z_Construct_UClass_UModulePanelWidget_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_ModulePanelWidget_h_27_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUModulePanelWidget(); \
	friend struct Z_Construct_UClass_UModulePanelWidget_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UModulePanelWidget_NoRegister(); \
public: \
	DECLARE_CLASS2(UModulePanelWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UModulePanelWidget_NoRegister) \
	DECLARE_SERIALIZER(UModulePanelWidget)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_ModulePanelWidget_h_27_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UModulePanelWidget(UModulePanelWidget&&) = delete; \
	UModulePanelWidget(const UModulePanelWidget&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UModulePanelWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UModulePanelWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UModulePanelWidget) \
	NO_API virtual ~UModulePanelWidget();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_ModulePanelWidget_h_24_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_ModulePanelWidget_h_27_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_ModulePanelWidget_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_ModulePanelWidget_h_27_CALLBACK_WRAPPERS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_ModulePanelWidget_h_27_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_ModulePanelWidget_h_27_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UModulePanelWidget;

// ********** End Class UModulePanelWidget *********************************************************

// ********** Begin Delegate FOnSlotClicked ********************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_ModulePanelWidget_h_265_DELEGATE \
static void FOnSlotClicked_DelegateWrapper(const FMulticastScriptDelegate& OnSlotClicked, ESlotType SlotType, int32 SlotIndex);


// ********** End Delegate FOnSlotClicked **********************************************************

// ********** Begin Class UModuleSlotWidget ********************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_ModulePanelWidget_h_212_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execUpdateState); \
	DECLARE_FUNCTION(execUpdateCooldown); \
	DECLARE_FUNCTION(execUpdateDisplay); \
	DECLARE_FUNCTION(execInitializeSlot);


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_ModulePanelWidget_h_212_CALLBACK_WRAPPERS
ECHOES_API UClass* Z_Construct_UClass_UModuleSlotWidget_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_ModulePanelWidget_h_212_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUModuleSlotWidget(); \
	friend struct Z_Construct_UClass_UModuleSlotWidget_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UModuleSlotWidget_NoRegister(); \
public: \
	DECLARE_CLASS2(UModuleSlotWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UModuleSlotWidget_NoRegister) \
	DECLARE_SERIALIZER(UModuleSlotWidget)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_ModulePanelWidget_h_212_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UModuleSlotWidget(UModuleSlotWidget&&) = delete; \
	UModuleSlotWidget(const UModuleSlotWidget&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UModuleSlotWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UModuleSlotWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UModuleSlotWidget) \
	NO_API virtual ~UModuleSlotWidget();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_ModulePanelWidget_h_209_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_ModulePanelWidget_h_212_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_ModulePanelWidget_h_212_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_ModulePanelWidget_h_212_CALLBACK_WRAPPERS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_ModulePanelWidget_h_212_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_ModulePanelWidget_h_212_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UModuleSlotWidget;

// ********** End Class UModuleSlotWidget **********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_ModulePanelWidget_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
