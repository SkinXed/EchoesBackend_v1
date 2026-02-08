// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UI/Widgets/EchoesMainHUD.h"

#ifdef ECHOES_EchoesMainHUD_generated_h
#error "EchoesMainHUD.generated.h already included, missing '#pragma once' in EchoesMainHUD.h"
#endif
#define ECHOES_EchoesMainHUD_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class AActor;
enum class EGameState : uint8;
struct FCommon_ShipDataStruct;
struct FLinearColor;

// ********** Begin Delegate FOnGameStateChanged ***************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMainHUD_h_38_DELEGATE \
ECHOES_API void FOnGameStateChanged_DelegateWrapper(const FMulticastScriptDelegate& OnGameStateChanged, EGameState NewState);


// ********** End Delegate FOnGameStateChanged *****************************************************

// ********** Begin Delegate FOnShipStatusUpdated **************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMainHUD_h_43_DELEGATE \
ECHOES_API void FOnShipStatusUpdated_DelegateWrapper(const FMulticastScriptDelegate& OnShipStatusUpdated, FCommon_ShipDataStruct const& ShipData);


// ********** End Delegate FOnShipStatusUpdated ****************************************************

// ********** Begin Class UEchoesMainHUD ***********************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMainHUD_h_87_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnShipStatsChanged); \
	DECLARE_FUNCTION(execCommon_FormatDistance); \
	DECLARE_FUNCTION(execCommon_FormatSpeed); \
	DECLARE_FUNCTION(execCommon_GetHealthBarColor); \
	DECLARE_FUNCTION(execCommon_HasShipData); \
	DECLARE_FUNCTION(execCommon_GetShipData); \
	DECLARE_FUNCTION(execCommon_GetTargetLeadIndicator); \
	DECLARE_FUNCTION(execClientOnly_RefreshAllDisplays); \
	DECLARE_FUNCTION(execClientOnly_UpdateTargetCount); \
	DECLARE_FUNCTION(execClientOnly_UpdateSpeed); \
	DECLARE_FUNCTION(execClientOnly_UpdateCapacitor); \
	DECLARE_FUNCTION(execClientOnly_UpdateShipStatus); \
	DECLARE_FUNCTION(execIsInSpace); \
	DECLARE_FUNCTION(execIsInHangar); \
	DECLARE_FUNCTION(execGetGameState); \
	DECLARE_FUNCTION(execSetGameState);


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMainHUD_h_87_CALLBACK_WRAPPERS
ECHOES_API UClass* Z_Construct_UClass_UEchoesMainHUD_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMainHUD_h_87_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEchoesMainHUD(); \
	friend struct Z_Construct_UClass_UEchoesMainHUD_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UEchoesMainHUD_NoRegister(); \
public: \
	DECLARE_CLASS2(UEchoesMainHUD, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UEchoesMainHUD_NoRegister) \
	DECLARE_SERIALIZER(UEchoesMainHUD)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMainHUD_h_87_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UEchoesMainHUD(UEchoesMainHUD&&) = delete; \
	UEchoesMainHUD(const UEchoesMainHUD&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEchoesMainHUD); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEchoesMainHUD); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UEchoesMainHUD) \
	NO_API virtual ~UEchoesMainHUD();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMainHUD_h_84_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMainHUD_h_87_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMainHUD_h_87_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMainHUD_h_87_CALLBACK_WRAPPERS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMainHUD_h_87_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMainHUD_h_87_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UEchoesMainHUD;

// ********** End Class UEchoesMainHUD *************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesMainHUD_h

// ********** Begin Enum EGameState ****************************************************************
#define FOREACH_ENUM_EGAMESTATE(op) \
	op(EGameState::InHangar) \
	op(EGameState::InSpace) \
	op(EGameState::Unknown) 

enum class EGameState : uint8;
template<> struct TIsUEnumClass<EGameState> { enum { Value = true }; };
template<> ECHOES_API UEnum* StaticEnum<EGameState>();
// ********** End Enum EGameState ******************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
