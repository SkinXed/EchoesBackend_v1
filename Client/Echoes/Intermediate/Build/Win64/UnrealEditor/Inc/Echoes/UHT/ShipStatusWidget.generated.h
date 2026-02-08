// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UI/Widgets/SpaceHUD/ShipStatusWidget.h"

#ifdef ECHOES_ShipStatusWidget_generated_h
#error "ShipStatusWidget.generated.h already included, missing '#pragma once' in ShipStatusWidget.h"
#endif
#define ECHOES_ShipStatusWidget_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class AActor;
struct FLinearColor;

// ********** Begin Interface UShipStateObserver ***************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_ShipStatusWidget_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void OnCapacitorChanged_Implementation(float CapacitorPct) {}; \
	virtual void OnShipStatsChanged_Implementation(float ShieldPct, float ArmorPct, float HullPct) {}; \
	DECLARE_FUNCTION(execOnCapacitorChanged); \
	DECLARE_FUNCTION(execOnShipStatsChanged);


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_ShipStatusWidget_h_24_CALLBACK_WRAPPERS
ECHOES_API UClass* Z_Construct_UClass_UShipStateObserver_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_ShipStatusWidget_h_24_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	ECHOES_API UShipStateObserver(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UShipStateObserver(UShipStateObserver&&) = delete; \
	UShipStateObserver(const UShipStateObserver&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(ECHOES_API, UShipStateObserver); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UShipStateObserver); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UShipStateObserver) \
	virtual ~UShipStateObserver() = default;


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_ShipStatusWidget_h_24_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUShipStateObserver(); \
	friend struct Z_Construct_UClass_UShipStateObserver_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UShipStateObserver_NoRegister(); \
public: \
	DECLARE_CLASS2(UShipStateObserver, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UShipStateObserver_NoRegister) \
	DECLARE_SERIALIZER(UShipStateObserver)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_ShipStatusWidget_h_24_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_ShipStatusWidget_h_24_GENERATED_UINTERFACE_BODY() \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_ShipStatusWidget_h_24_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_ShipStatusWidget_h_24_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IShipStateObserver() {} \
public: \
	typedef UShipStateObserver UClassType; \
	typedef IShipStateObserver ThisClass; \
	static void Execute_OnCapacitorChanged(UObject* O, float CapacitorPct); \
	static void Execute_OnShipStatsChanged(UObject* O, float ShieldPct, float ArmorPct, float HullPct); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_ShipStatusWidget_h_21_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_ShipStatusWidget_h_29_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_ShipStatusWidget_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_ShipStatusWidget_h_24_CALLBACK_WRAPPERS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_ShipStatusWidget_h_24_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UShipStateObserver;

// ********** End Interface UShipStateObserver *****************************************************

// ********** Begin Class UShipStatusWidget ********************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_ShipStatusWidget_h_91_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandlePeriodicUpdate); \
	DECLARE_FUNCTION(execCommon_GetHealthColor); \
	DECLARE_FUNCTION(execClientOnly_RefreshAllDisplays); \
	DECLARE_FUNCTION(execClientOnly_UpdateCapacitor); \
	DECLARE_FUNCTION(execClientOnly_UpdateHull); \
	DECLARE_FUNCTION(execClientOnly_UpdateArmor); \
	DECLARE_FUNCTION(execClientOnly_UpdateShield); \
	DECLARE_FUNCTION(execUnbindFromShip); \
	DECLARE_FUNCTION(execBindToShip);


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_ShipStatusWidget_h_91_CALLBACK_WRAPPERS
ECHOES_API UClass* Z_Construct_UClass_UShipStatusWidget_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_ShipStatusWidget_h_91_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUShipStatusWidget(); \
	friend struct Z_Construct_UClass_UShipStatusWidget_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UShipStatusWidget_NoRegister(); \
public: \
	DECLARE_CLASS2(UShipStatusWidget, UUserWidget, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UShipStatusWidget_NoRegister) \
	DECLARE_SERIALIZER(UShipStatusWidget) \
	virtual UObject* _getUObject() const override { return const_cast<UShipStatusWidget*>(this); }


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_ShipStatusWidget_h_91_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UShipStatusWidget(UShipStatusWidget&&) = delete; \
	UShipStatusWidget(const UShipStatusWidget&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UShipStatusWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UShipStatusWidget); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UShipStatusWidget) \
	NO_API virtual ~UShipStatusWidget();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_ShipStatusWidget_h_88_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_ShipStatusWidget_h_91_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_ShipStatusWidget_h_91_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_ShipStatusWidget_h_91_CALLBACK_WRAPPERS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_ShipStatusWidget_h_91_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_ShipStatusWidget_h_91_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UShipStatusWidget;

// ********** End Class UShipStatusWidget **********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_ShipStatusWidget_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
