// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UI/Widgets/SpaceHUD/NavigationWidget.h"

#ifdef ECHOES_NavigationWidget_generated_h
#error "NavigationWidget.generated.h already included, missing '#pragma once' in NavigationWidget.h"
#endif
#define ECHOES_NavigationWidget_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class AActor;
enum class ENavigationCommand : uint8;

// ********** Begin Delegate FOnNavigationCommandIssued ********************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_NavigationWidget_h_45_DELEGATE \
ECHOES_API void FOnNavigationCommandIssued_DelegateWrapper(const FMulticastScriptDelegate& OnNavigationCommandIssued, ENavigationCommand Command, AActor* Target);


// ********** End Delegate FOnNavigationCommandIssued **********************************************

// ********** Begin Class UNavigationWidget ********************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_NavigationWidget_h_67_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandlePeriodicUpdate); \
	DECLARE_FUNCTION(execHandleStopClicked); \
	DECLARE_FUNCTION(execHandleKeepAtRangeClicked); \
	DECLARE_FUNCTION(execHandleApproachClicked); \
	DECLARE_FUNCTION(execHandleWarpToClicked); \
	DECLARE_FUNCTION(execHandleOrbitClicked); \
	DECLARE_FUNCTION(execHandleAlignToClicked); \
	DECLARE_FUNCTION(execCommon_GetVelocityBearing); \
	DECLARE_FUNCTION(execCommon_FormatSpeed); \
	DECLARE_FUNCTION(execServerRPC_ExecuteNavCommand); \
	DECLARE_FUNCTION(execClientOnly_RefreshDisplays); \
	DECLARE_FUNCTION(execClientOnly_UpdateSpeed); \
	DECLARE_FUNCTION(execSetNavigationTarget); \
	DECLARE_FUNCTION(execUnbindFromShip); \
	DECLARE_FUNCTION(execBindToShip);


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_NavigationWidget_h_67_CALLBACK_WRAPPERS
ECHOES_API UClass* Z_Construct_UClass_UNavigationWidget_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_NavigationWidget_h_67_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUNavigationWidget(); \
	friend struct Z_Construct_UClass_UNavigationWidget_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UNavigationWidget_NoRegister(); \
public: \
	DECLARE_CLASS2(UNavigationWidget, UUserWidget, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UNavigationWidget_NoRegister) \
	DECLARE_SERIALIZER(UNavigationWidget)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_NavigationWidget_h_67_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UNavigationWidget(UNavigationWidget&&) = delete; \
	UNavigationWidget(const UNavigationWidget&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UNavigationWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UNavigationWidget); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UNavigationWidget) \
	NO_API virtual ~UNavigationWidget();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_NavigationWidget_h_64_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_NavigationWidget_h_67_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_NavigationWidget_h_67_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_NavigationWidget_h_67_CALLBACK_WRAPPERS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_NavigationWidget_h_67_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_NavigationWidget_h_67_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UNavigationWidget;

// ********** End Class UNavigationWidget **********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_NavigationWidget_h

// ********** Begin Enum ENavigationCommand ********************************************************
#define FOREACH_ENUM_ENAVIGATIONCOMMAND(op) \
	op(ENavigationCommand::AlignTo) \
	op(ENavigationCommand::Orbit) \
	op(ENavigationCommand::WarpTo) \
	op(ENavigationCommand::Approach) \
	op(ENavigationCommand::KeepAtRange) \
	op(ENavigationCommand::Stop) 

enum class ENavigationCommand : uint8;
template<> struct TIsUEnumClass<ENavigationCommand> { enum { Value = true }; };
template<> ECHOES_API UEnum* StaticEnum<ENavigationCommand>();
// ********** End Enum ENavigationCommand **********************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
