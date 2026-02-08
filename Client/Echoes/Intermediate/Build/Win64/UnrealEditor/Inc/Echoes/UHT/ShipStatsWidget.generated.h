// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UI/Widgets/Fitting/ShipStatsWidget.h"

#ifdef ECHOES_ShipStatsWidget_generated_h
#error "ShipStatsWidget.generated.h already included, missing '#pragma once' in ShipStatsWidget.h"
#endif
#define ECHOES_ShipStatsWidget_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class IShipFittingInterface;
enum class ECosmosDamageType : uint8;
struct FCommon_ShipFittingData;
struct FCosmosDefenseLayer;

// ********** Begin Class UShipStatsWidget *********************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_ShipStatsWidget_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execCommon_GetShipFittingInterface); \
	DECLARE_FUNCTION(execCommon_FormatNumber); \
	DECLARE_FUNCTION(execCommon_GetAverageResistance); \
	DECLARE_FUNCTION(execCommon_CalculateDPS); \
	DECLARE_FUNCTION(execCommon_CalculateEffectiveHP); \
	DECLARE_FUNCTION(execCommon_CalculateTotalStats); \
	DECLARE_FUNCTION(execClientOnly_UpdateScanningDisplay); \
	DECLARE_FUNCTION(execClientOnly_UpdateSpeedDisplay); \
	DECLARE_FUNCTION(execClientOnly_UpdateResistanceDisplay); \
	DECLARE_FUNCTION(execClientOnly_UpdateEHPDisplay); \
	DECLARE_FUNCTION(execClientOnly_UpdateDPSDisplay); \
	DECLARE_FUNCTION(execClientOnly_RefreshStats);


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_ShipStatsWidget_h_29_CALLBACK_WRAPPERS
ECHOES_API UClass* Z_Construct_UClass_UShipStatsWidget_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_ShipStatsWidget_h_29_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUShipStatsWidget(); \
	friend struct Z_Construct_UClass_UShipStatsWidget_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UShipStatsWidget_NoRegister(); \
public: \
	DECLARE_CLASS2(UShipStatsWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UShipStatsWidget_NoRegister) \
	DECLARE_SERIALIZER(UShipStatsWidget) \
	virtual UObject* _getUObject() const override { return const_cast<UShipStatsWidget*>(this); }


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_ShipStatsWidget_h_29_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UShipStatsWidget(UShipStatsWidget&&) = delete; \
	UShipStatsWidget(const UShipStatsWidget&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UShipStatsWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UShipStatsWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UShipStatsWidget) \
	NO_API virtual ~UShipStatsWidget();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_ShipStatsWidget_h_26_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_ShipStatsWidget_h_29_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_ShipStatsWidget_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_ShipStatsWidget_h_29_CALLBACK_WRAPPERS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_ShipStatsWidget_h_29_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_ShipStatsWidget_h_29_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UShipStatsWidget;

// ********** End Class UShipStatsWidget ***********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_ShipStatsWidget_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
