// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UI/Widgets/SpaceHUD/OverviewWidget.h"

#ifdef ECHOES_OverviewWidget_generated_h
#error "OverviewWidget.generated.h already included, missing '#pragma once' in OverviewWidget.h"
#endif
#define ECHOES_OverviewWidget_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class AActor;
class UObject;
enum class EOverviewEntryType : uint8;
enum class EOverviewSortBy : uint8;
struct FOverviewRowData;

// ********** Begin ScriptStruct FOverviewRowData **************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_OverviewWidget_h_75_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOverviewRowData_Statics; \
	ECHOES_API static class UScriptStruct* StaticStruct();


struct FOverviewRowData;
// ********** End ScriptStruct FOverviewRowData ****************************************************

// ********** Begin Class UOverviewRowObject *******************************************************
ECHOES_API UClass* Z_Construct_UClass_UOverviewRowObject_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_OverviewWidget_h_151_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUOverviewRowObject(); \
	friend struct Z_Construct_UClass_UOverviewRowObject_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UOverviewRowObject_NoRegister(); \
public: \
	DECLARE_CLASS2(UOverviewRowObject, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UOverviewRowObject_NoRegister) \
	DECLARE_SERIALIZER(UOverviewRowObject)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_OverviewWidget_h_151_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UOverviewRowObject(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UOverviewRowObject(UOverviewRowObject&&) = delete; \
	UOverviewRowObject(const UOverviewRowObject&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOverviewRowObject); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOverviewRowObject); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOverviewRowObject) \
	NO_API virtual ~UOverviewRowObject();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_OverviewWidget_h_148_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_OverviewWidget_h_151_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_OverviewWidget_h_151_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_OverviewWidget_h_151_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UOverviewRowObject;

// ********** End Class UOverviewRowObject *********************************************************

// ********** Begin Class UOverviewRowWidget *******************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_OverviewWidget_h_170_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetRowData); \
	DECLARE_FUNCTION(execSetRowData);


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_OverviewWidget_h_170_CALLBACK_WRAPPERS
ECHOES_API UClass* Z_Construct_UClass_UOverviewRowWidget_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_OverviewWidget_h_170_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUOverviewRowWidget(); \
	friend struct Z_Construct_UClass_UOverviewRowWidget_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UOverviewRowWidget_NoRegister(); \
public: \
	DECLARE_CLASS2(UOverviewRowWidget, UUserWidget, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UOverviewRowWidget_NoRegister) \
	DECLARE_SERIALIZER(UOverviewRowWidget) \
	virtual UObject* _getUObject() const override { return const_cast<UOverviewRowWidget*>(this); }


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_OverviewWidget_h_170_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UOverviewRowWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UOverviewRowWidget(UOverviewRowWidget&&) = delete; \
	UOverviewRowWidget(const UOverviewRowWidget&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOverviewRowWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOverviewRowWidget); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOverviewRowWidget) \
	NO_API virtual ~UOverviewRowWidget();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_OverviewWidget_h_167_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_OverviewWidget_h_170_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_OverviewWidget_h_170_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_OverviewWidget_h_170_CALLBACK_WRAPPERS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_OverviewWidget_h_170_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_OverviewWidget_h_170_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UOverviewRowWidget;

// ********** End Class UOverviewRowWidget *********************************************************

// ********** Begin Delegate FOnOverviewSelectionChanged *******************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_OverviewWidget_h_223_DELEGATE \
ECHOES_API void FOnOverviewSelectionChanged_DelegateWrapper(const FMulticastScriptDelegate& OnOverviewSelectionChanged, FOverviewRowData const& SelectedRow);


// ********** End Delegate FOnOverviewSelectionChanged *********************************************

// ********** Begin Delegate FOnOverviewItemDoubleClicked ******************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_OverviewWidget_h_228_DELEGATE \
ECHOES_API void FOnOverviewItemDoubleClicked_DelegateWrapper(const FMulticastScriptDelegate& OnOverviewItemDoubleClicked, AActor* SelectedActor);


// ********** End Delegate FOnOverviewItemDoubleClicked ********************************************

// ********** Begin Class UOverviewWidget **********************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_OverviewWidget_h_266_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandleSortTypeClicked); \
	DECLARE_FUNCTION(execHandleSortNameClicked); \
	DECLARE_FUNCTION(execHandleSortDistanceClicked); \
	DECLARE_FUNCTION(execHandleItemDoubleClicked); \
	DECLARE_FUNCTION(execHandleSelectionChanged); \
	DECLARE_FUNCTION(execClientOnly_RefreshEntries); \
	DECLARE_FUNCTION(execSetTypeFilter); \
	DECLARE_FUNCTION(execGetSelectedEntry); \
	DECLARE_FUNCTION(execCommon_FormatVelocity); \
	DECLARE_FUNCTION(execCommon_FormatDistance); \
	DECLARE_FUNCTION(execClientOnly_SortOverview); \
	DECLARE_FUNCTION(execClearAll); \
	DECLARE_FUNCTION(execUpdateEntry); \
	DECLARE_FUNCTION(execRemoveEntry); \
	DECLARE_FUNCTION(execAddEntry);


ECHOES_API UClass* Z_Construct_UClass_UOverviewWidget_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_OverviewWidget_h_266_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUOverviewWidget(); \
	friend struct Z_Construct_UClass_UOverviewWidget_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UOverviewWidget_NoRegister(); \
public: \
	DECLARE_CLASS2(UOverviewWidget, UUserWidget, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UOverviewWidget_NoRegister) \
	DECLARE_SERIALIZER(UOverviewWidget)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_OverviewWidget_h_266_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UOverviewWidget(UOverviewWidget&&) = delete; \
	UOverviewWidget(const UOverviewWidget&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOverviewWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOverviewWidget); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOverviewWidget) \
	NO_API virtual ~UOverviewWidget();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_OverviewWidget_h_263_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_OverviewWidget_h_266_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_OverviewWidget_h_266_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_OverviewWidget_h_266_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_OverviewWidget_h_266_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UOverviewWidget;

// ********** End Class UOverviewWidget ************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_OverviewWidget_h

// ********** Begin Enum EOverviewEntryType ********************************************************
#define FOREACH_ENUM_EOVERVIEWENTRYTYPE(op) \
	op(EOverviewEntryType::Player) \
	op(EOverviewEntryType::Friendly) \
	op(EOverviewEntryType::Neutral) \
	op(EOverviewEntryType::Hostile) \
	op(EOverviewEntryType::Celestial) \
	op(EOverviewEntryType::Structure) \
	op(EOverviewEntryType::Gate) \
	op(EOverviewEntryType::Other) 

enum class EOverviewEntryType : uint8;
template<> struct TIsUEnumClass<EOverviewEntryType> { enum { Value = true }; };
template<> ECHOES_API UEnum* StaticEnum<EOverviewEntryType>();
// ********** End Enum EOverviewEntryType **********************************************************

// ********** Begin Enum EOverviewSortBy ***********************************************************
#define FOREACH_ENUM_EOVERVIEWSORTBY(op) \
	op(EOverviewSortBy::Distance) \
	op(EOverviewSortBy::Name) \
	op(EOverviewSortBy::Type) \
	op(EOverviewSortBy::RadialVelocity) 

enum class EOverviewSortBy : uint8;
template<> struct TIsUEnumClass<EOverviewSortBy> { enum { Value = true }; };
template<> ECHOES_API UEnum* StaticEnum<EOverviewSortBy>();
// ********** End Enum EOverviewSortBy *************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
