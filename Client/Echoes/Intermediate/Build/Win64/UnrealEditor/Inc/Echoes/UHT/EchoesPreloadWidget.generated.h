// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UI/Widgets/EchoesPreloadWidget.h"

#ifdef ECHOES_EchoesPreloadWidget_generated_h
#error "EchoesPreloadWidget.generated.h already included, missing '#pragma once' in EchoesPreloadWidget.h"
#endif
#define ECHOES_EchoesPreloadWidget_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

enum class ENextState : uint8;

// ********** Begin Delegate FOnPreloadComplete ****************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesPreloadWidget_h_36_DELEGATE \
ECHOES_API void FOnPreloadComplete_DelegateWrapper(const FMulticastScriptDelegate& OnPreloadComplete, ENextState NextState);


// ********** End Delegate FOnPreloadComplete ******************************************************

// ********** Begin Class UEchoesPreloadWidget *****************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesPreloadWidget_h_53_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execStartPreload);


ECHOES_API UClass* Z_Construct_UClass_UEchoesPreloadWidget_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesPreloadWidget_h_53_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEchoesPreloadWidget(); \
	friend struct Z_Construct_UClass_UEchoesPreloadWidget_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UEchoesPreloadWidget_NoRegister(); \
public: \
	DECLARE_CLASS2(UEchoesPreloadWidget, UEchoesWindowBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UEchoesPreloadWidget_NoRegister) \
	DECLARE_SERIALIZER(UEchoesPreloadWidget)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesPreloadWidget_h_53_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UEchoesPreloadWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UEchoesPreloadWidget(UEchoesPreloadWidget&&) = delete; \
	UEchoesPreloadWidget(const UEchoesPreloadWidget&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEchoesPreloadWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEchoesPreloadWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UEchoesPreloadWidget) \
	NO_API virtual ~UEchoesPreloadWidget();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesPreloadWidget_h_50_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesPreloadWidget_h_53_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesPreloadWidget_h_53_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesPreloadWidget_h_53_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesPreloadWidget_h_53_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UEchoesPreloadWidget;

// ********** End Class UEchoesPreloadWidget *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesPreloadWidget_h

// ********** Begin Enum EPreloadState *************************************************************
#define FOREACH_ENUM_EPRELOADSTATE(op) \
	op(EPreloadState::CheckingAPI) \
	op(EPreloadState::ValidatingToken) \
	op(EPreloadState::Success) \
	op(EPreloadState::Failed) 

enum class EPreloadState : uint8;
template<> struct TIsUEnumClass<EPreloadState> { enum { Value = true }; };
template<> ECHOES_API UEnum* StaticEnum<EPreloadState>();
// ********** End Enum EPreloadState ***************************************************************

// ********** Begin Enum ENextState ****************************************************************
#define FOREACH_ENUM_ENEXTSTATE(op) \
	op(ENextState::Login) \
	op(ENextState::CharacterSelect) 

enum class ENextState : uint8;
template<> struct TIsUEnumClass<ENextState> { enum { Value = true }; };
template<> ECHOES_API UEnum* StaticEnum<ENextState>();
// ********** End Enum ENextState ******************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
