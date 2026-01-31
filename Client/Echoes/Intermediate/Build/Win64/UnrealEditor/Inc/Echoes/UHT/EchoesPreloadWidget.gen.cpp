// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UI/EchoesPreloadWidget.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesPreloadWidget() {}

// ********** Begin Cross Module References ********************************************************
ECHOES_API UClass* Z_Construct_UClass_UEchoesAuthSubsystem_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UEchoesPreloadWidget();
ECHOES_API UClass* Z_Construct_UClass_UEchoesPreloadWidget_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UEchoesWindowBase();
ECHOES_API UEnum* Z_Construct_UEnum_Echoes_ENextState();
ECHOES_API UEnum* Z_Construct_UEnum_Echoes_EPreloadState();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnPreloadComplete__DelegateSignature();
UMG_API UClass* Z_Construct_UClass_UProgressBar_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EPreloadState *************************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPreloadState;
static UEnum* EPreloadState_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EPreloadState.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EPreloadState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Echoes_EPreloadState, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("EPreloadState"));
	}
	return Z_Registration_Info_UEnum_EPreloadState.OuterSingleton;
}
template<> ECHOES_API UEnum* StaticEnum<EPreloadState>()
{
	return EPreloadState_StaticEnum();
}
struct Z_Construct_UEnum_Echoes_EPreloadState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "CheckingAPI.Name", "EPreloadState::CheckingAPI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Preload state enum\n */" },
#endif
		{ "Failed.Name", "EPreloadState::Failed" },
		{ "ModuleRelativePath", "UI/EchoesPreloadWidget.h" },
		{ "Success.Name", "EPreloadState::Success" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Preload state enum" },
#endif
		{ "ValidatingToken.Name", "EPreloadState::ValidatingToken" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EPreloadState::CheckingAPI", (int64)EPreloadState::CheckingAPI },
		{ "EPreloadState::ValidatingToken", (int64)EPreloadState::ValidatingToken },
		{ "EPreloadState::Success", (int64)EPreloadState::Success },
		{ "EPreloadState::Failed", (int64)EPreloadState::Failed },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Echoes_EPreloadState_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	"EPreloadState",
	"EPreloadState",
	Z_Construct_UEnum_Echoes_EPreloadState_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_Echoes_EPreloadState_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_Echoes_EPreloadState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_Echoes_EPreloadState_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_Echoes_EPreloadState()
{
	if (!Z_Registration_Info_UEnum_EPreloadState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPreloadState.InnerSingleton, Z_Construct_UEnum_Echoes_EPreloadState_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EPreloadState.InnerSingleton;
}
// ********** End Enum EPreloadState ***************************************************************

// ********** Begin Enum ENextState ****************************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ENextState;
static UEnum* ENextState_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ENextState.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ENextState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Echoes_ENextState, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("ENextState"));
	}
	return Z_Registration_Info_UEnum_ENextState.OuterSingleton;
}
template<> ECHOES_API UEnum* StaticEnum<ENextState>()
{
	return ENextState_StaticEnum();
}
struct Z_Construct_UEnum_Echoes_ENextState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "CharacterSelect.Name", "ENextState::CharacterSelect" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Next state after preload\n */" },
#endif
		{ "Login.Name", "ENextState::Login" },
		{ "ModuleRelativePath", "UI/EchoesPreloadWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Next state after preload" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ENextState::Login", (int64)ENextState::Login },
		{ "ENextState::CharacterSelect", (int64)ENextState::CharacterSelect },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Echoes_ENextState_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	"ENextState",
	"ENextState",
	Z_Construct_UEnum_Echoes_ENextState_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_Echoes_ENextState_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_Echoes_ENextState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_Echoes_ENextState_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_Echoes_ENextState()
{
	if (!Z_Registration_Info_UEnum_ENextState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ENextState.InnerSingleton, Z_Construct_UEnum_Echoes_ENextState_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ENextState.InnerSingleton;
}
// ********** End Enum ENextState ******************************************************************

// ********** Begin Delegate FOnPreloadComplete ****************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnPreloadComplete__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnPreloadComplete_Parms
	{
		ENextState NextState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI/EchoesPreloadWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_NextState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NextState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_Echoes_OnPreloadComplete__DelegateSignature_Statics::NewProp_NextState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_Echoes_OnPreloadComplete__DelegateSignature_Statics::NewProp_NextState = { "NextState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnPreloadComplete_Parms, NextState), Z_Construct_UEnum_Echoes_ENextState, METADATA_PARAMS(0, nullptr) }; // 2333295913
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnPreloadComplete__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnPreloadComplete__DelegateSignature_Statics::NewProp_NextState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnPreloadComplete__DelegateSignature_Statics::NewProp_NextState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnPreloadComplete__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnPreloadComplete__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnPreloadComplete__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnPreloadComplete__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnPreloadComplete__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnPreloadComplete__DelegateSignature_Statics::_Script_Echoes_eventOnPreloadComplete_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnPreloadComplete__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnPreloadComplete__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnPreloadComplete__DelegateSignature_Statics::_Script_Echoes_eventOnPreloadComplete_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnPreloadComplete__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnPreloadComplete__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnPreloadComplete_DelegateWrapper(const FMulticastScriptDelegate& OnPreloadComplete, ENextState NextState)
{
	struct _Script_Echoes_eventOnPreloadComplete_Parms
	{
		ENextState NextState;
	};
	_Script_Echoes_eventOnPreloadComplete_Parms Parms;
	Parms.NextState=NextState;
	OnPreloadComplete.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnPreloadComplete ******************************************************

// ********** Begin Class UEchoesPreloadWidget Function StartPreload *******************************
struct Z_Construct_UFunction_UEchoesPreloadWidget_StartPreload_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Preload" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Start the preload process\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesPreloadWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Start the preload process" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesPreloadWidget_StartPreload_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesPreloadWidget, nullptr, "StartPreload", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesPreloadWidget_StartPreload_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesPreloadWidget_StartPreload_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesPreloadWidget_StartPreload()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesPreloadWidget_StartPreload_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesPreloadWidget::execStartPreload)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StartPreload();
	P_NATIVE_END;
}
// ********** End Class UEchoesPreloadWidget Function StartPreload *********************************

// ********** Begin Class UEchoesPreloadWidget *****************************************************
void UEchoesPreloadWidget::StaticRegisterNativesUEchoesPreloadWidget()
{
	UClass* Class = UEchoesPreloadWidget::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "StartPreload", &UEchoesPreloadWidget::execStartPreload },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UEchoesPreloadWidget;
UClass* UEchoesPreloadWidget::GetPrivateStaticClass()
{
	using TClass = UEchoesPreloadWidget;
	if (!Z_Registration_Info_UClass_UEchoesPreloadWidget.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesPreloadWidget"),
			Z_Registration_Info_UClass_UEchoesPreloadWidget.InnerSingleton,
			StaticRegisterNativesUEchoesPreloadWidget,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UEchoesPreloadWidget.InnerSingleton;
}
UClass* Z_Construct_UClass_UEchoesPreloadWidget_NoRegister()
{
	return UEchoesPreloadWidget::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UEchoesPreloadWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * UEchoesPreloadWidget\n * \n * Preload widget for cold start validation\n * Checks API connectivity and validates saved JWT token\n * \n * Flow:\n * 1. Check API status (/api/system/status)\n * 2. If token exists in LocalPlayerSettings, validate it (/api/auth/validate-token)\n * 3. On success -> Character Select\n * 4. On failure -> Login\n */" },
#endif
		{ "IncludePath", "UI/EchoesPreloadWidget.h" },
		{ "ModuleRelativePath", "UI/EchoesPreloadWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UEchoesPreloadWidget\n\nPreload widget for cold start validation\nChecks API connectivity and validates saved JWT token\n\nFlow:\n1. Check API status (/api/system/status)\n2. If token exists in LocalPlayerSettings, validate it (/api/auth/validate-token)\n3. On success -> Character Select\n4. On failure -> Login" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StatusText_MetaData[] = {
		{ "BindWidget", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Status message text */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/EchoesPreloadWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Status message text" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProgressBar_MetaData[] = {
		{ "BindWidget", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Loading progress bar */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/EchoesPreloadWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Loading progress bar" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnPreloadComplete_MetaData[] = {
		{ "Category", "Echoes|Preload" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Called when preload is complete */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesPreloadWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when preload is complete" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AuthSubsystem_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Reference to auth subsystem */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesPreloadWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Reference to auth subsystem" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StatusText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ProgressBar;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnPreloadComplete;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AuthSubsystem;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UEchoesPreloadWidget_StartPreload, "StartPreload" }, // 1274502945
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEchoesPreloadWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesPreloadWidget_Statics::NewProp_StatusText = { "StatusText", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesPreloadWidget, StatusText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StatusText_MetaData), NewProp_StatusText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesPreloadWidget_Statics::NewProp_ProgressBar = { "ProgressBar", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesPreloadWidget, ProgressBar), Z_Construct_UClass_UProgressBar_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProgressBar_MetaData), NewProp_ProgressBar_MetaData) };
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEchoesPreloadWidget_Statics::NewProp_OnPreloadComplete = { "OnPreloadComplete", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesPreloadWidget, OnPreloadComplete), Z_Construct_UDelegateFunction_Echoes_OnPreloadComplete__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnPreloadComplete_MetaData), NewProp_OnPreloadComplete_MetaData) }; // 2730088595
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesPreloadWidget_Statics::NewProp_AuthSubsystem = { "AuthSubsystem", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesPreloadWidget, AuthSubsystem), Z_Construct_UClass_UEchoesAuthSubsystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AuthSubsystem_MetaData), NewProp_AuthSubsystem_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEchoesPreloadWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesPreloadWidget_Statics::NewProp_StatusText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesPreloadWidget_Statics::NewProp_ProgressBar,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesPreloadWidget_Statics::NewProp_OnPreloadComplete,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesPreloadWidget_Statics::NewProp_AuthSubsystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesPreloadWidget_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UEchoesPreloadWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UEchoesWindowBase,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesPreloadWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEchoesPreloadWidget_Statics::ClassParams = {
	&UEchoesPreloadWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UEchoesPreloadWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesPreloadWidget_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesPreloadWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UEchoesPreloadWidget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEchoesPreloadWidget()
{
	if (!Z_Registration_Info_UClass_UEchoesPreloadWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEchoesPreloadWidget.OuterSingleton, Z_Construct_UClass_UEchoesPreloadWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEchoesPreloadWidget.OuterSingleton;
}
UEchoesPreloadWidget::UEchoesPreloadWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UEchoesPreloadWidget);
UEchoesPreloadWidget::~UEchoesPreloadWidget() {}
// ********** End Class UEchoesPreloadWidget *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesPreloadWidget_h__Script_Echoes_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EPreloadState_StaticEnum, TEXT("EPreloadState"), &Z_Registration_Info_UEnum_EPreloadState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2480900085U) },
		{ ENextState_StaticEnum, TEXT("ENextState"), &Z_Registration_Info_UEnum_ENextState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2333295913U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEchoesPreloadWidget, UEchoesPreloadWidget::StaticClass, TEXT("UEchoesPreloadWidget"), &Z_Registration_Info_UClass_UEchoesPreloadWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEchoesPreloadWidget), 435220248U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesPreloadWidget_h__Script_Echoes_2246214835(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesPreloadWidget_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesPreloadWidget_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesPreloadWidget_h__Script_Echoes_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesPreloadWidget_h__Script_Echoes_Statics::EnumInfo));
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
