// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UI/Widgets/Fitting/FittingWindowWidget.h"

#ifdef ECHOES_FittingWindowWidget_generated_h
#error "FittingWindowWidget.generated.h already included, missing '#pragma once' in FittingWindowWidget.h"
#endif
#define ECHOES_FittingWindowWidget_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class IShipFittingInterface;
enum class ESlotType : uint8;
struct FCommon_ItemSlot;
struct FCommon_ShipFittingData;

// ********** Begin Delegate FOnFittingChanged *****************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_FittingWindowWidget_h_115_DELEGATE \
static void FOnFittingChanged_DelegateWrapper(const FMulticastScriptDelegate& OnFittingChanged);


// ********** End Delegate FOnFittingChanged *******************************************************

// ********** Begin Class UFittingWindowWidget *****************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_FittingWindowWidget_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execCommon_GetShipFittingInterface); \
	DECLARE_FUNCTION(execCommon_CalculateFitting); \
	DECLARE_FUNCTION(execCommon_CanInstallModule); \
	DECLARE_FUNCTION(execServerRPC_SwapModules); \
	DECLARE_FUNCTION(execServerRPC_UninstallModule); \
	DECLARE_FUNCTION(execServerRPC_InstallModule); \
	DECLARE_FUNCTION(execClientOnly_UpdateSlot); \
	DECLARE_FUNCTION(execClientOnly_UpdateCPUDisplay); \
	DECLARE_FUNCTION(execClientOnly_UpdatePowergridDisplay); \
	DECLARE_FUNCTION(execClientOnly_RefreshFitting);


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_FittingWindowWidget_h_26_CALLBACK_WRAPPERS
ECHOES_API UClass* Z_Construct_UClass_UFittingWindowWidget_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_FittingWindowWidget_h_26_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUFittingWindowWidget(); \
	friend struct Z_Construct_UClass_UFittingWindowWidget_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UFittingWindowWidget_NoRegister(); \
public: \
	DECLARE_CLASS2(UFittingWindowWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UFittingWindowWidget_NoRegister) \
	DECLARE_SERIALIZER(UFittingWindowWidget)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_FittingWindowWidget_h_26_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UFittingWindowWidget(UFittingWindowWidget&&) = delete; \
	UFittingWindowWidget(const UFittingWindowWidget&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFittingWindowWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFittingWindowWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFittingWindowWidget) \
	NO_API virtual ~UFittingWindowWidget();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_FittingWindowWidget_h_23_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_FittingWindowWidget_h_26_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_FittingWindowWidget_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_FittingWindowWidget_h_26_CALLBACK_WRAPPERS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_FittingWindowWidget_h_26_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_FittingWindowWidget_h_26_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UFittingWindowWidget;

// ********** End Class UFittingWindowWidget *******************************************************

// ********** Begin Delegate FOnModuleDropped ******************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_FittingWindowWidget_h_209_DELEGATE \
static void FOnModuleDropped_DelegateWrapper(const FMulticastScriptDelegate& OnModuleDropped, ESlotType SlotType, int32 SlotIndex, int32 ItemID);


// ********** End Delegate FOnModuleDropped ********************************************************

// ********** Begin Delegate FOnModuleRemoved ******************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_FittingWindowWidget_h_210_DELEGATE \
static void FOnModuleRemoved_DelegateWrapper(const FMulticastScriptDelegate& OnModuleRemoved, ESlotType SlotType, int32 SlotIndex);


// ********** End Delegate FOnModuleRemoved ********************************************************

// ********** Begin Class UFittingSlotWidget *******************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_FittingWindowWidget_h_173_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execUpdateDisplay); \
	DECLARE_FUNCTION(execInitializeSlot);


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_FittingWindowWidget_h_173_CALLBACK_WRAPPERS
ECHOES_API UClass* Z_Construct_UClass_UFittingSlotWidget_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_FittingWindowWidget_h_173_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUFittingSlotWidget(); \
	friend struct Z_Construct_UClass_UFittingSlotWidget_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UFittingSlotWidget_NoRegister(); \
public: \
	DECLARE_CLASS2(UFittingSlotWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UFittingSlotWidget_NoRegister) \
	DECLARE_SERIALIZER(UFittingSlotWidget)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_FittingWindowWidget_h_173_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UFittingSlotWidget(UFittingSlotWidget&&) = delete; \
	UFittingSlotWidget(const UFittingSlotWidget&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFittingSlotWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFittingSlotWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFittingSlotWidget) \
	NO_API virtual ~UFittingSlotWidget();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_FittingWindowWidget_h_170_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_FittingWindowWidget_h_173_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_FittingWindowWidget_h_173_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_FittingWindowWidget_h_173_CALLBACK_WRAPPERS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_FittingWindowWidget_h_173_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_FittingWindowWidget_h_173_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UFittingSlotWidget;

// ********** End Class UFittingSlotWidget *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_FittingWindowWidget_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
