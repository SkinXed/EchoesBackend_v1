// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EchoesMenuPlayerController.h"
#include "EchoesAuthSubsystem.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesMenuPlayerController() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ECHOES_API UClass* Z_Construct_UClass_AEchoesMenuPlayerController();
ECHOES_API UClass* Z_Construct_UClass_AEchoesMenuPlayerController_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UEchoesCharacterSelectWidget_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UEchoesLoginWidget_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UEchoesPreloadWidget_NoRegister();
ECHOES_API UEnum* Z_Construct_UEnum_Echoes_ENextState();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FAuthResponse();
ENGINE_API UClass* Z_Construct_UClass_APlayerController();
UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AEchoesMenuPlayerController Function OnLoginSuccess **********************
struct Z_Construct_UFunction_AEchoesMenuPlayerController_OnLoginSuccess_Statics
{
	struct EchoesMenuPlayerController_eventOnLoginSuccess_Parms
	{
		FAuthResponse AuthResponse;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Handle login success\n\x09 */" },
#endif
		{ "ModuleRelativePath", "EchoesMenuPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handle login success" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AuthResponse_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_AuthResponse;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEchoesMenuPlayerController_OnLoginSuccess_Statics::NewProp_AuthResponse = { "AuthResponse", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMenuPlayerController_eventOnLoginSuccess_Parms, AuthResponse), Z_Construct_UScriptStruct_FAuthResponse, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AuthResponse_MetaData), NewProp_AuthResponse_MetaData) }; // 2780569161
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesMenuPlayerController_OnLoginSuccess_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesMenuPlayerController_OnLoginSuccess_Statics::NewProp_AuthResponse,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesMenuPlayerController_OnLoginSuccess_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesMenuPlayerController_OnLoginSuccess_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesMenuPlayerController, nullptr, "OnLoginSuccess", Z_Construct_UFunction_AEchoesMenuPlayerController_OnLoginSuccess_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesMenuPlayerController_OnLoginSuccess_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesMenuPlayerController_OnLoginSuccess_Statics::EchoesMenuPlayerController_eventOnLoginSuccess_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00480401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesMenuPlayerController_OnLoginSuccess_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesMenuPlayerController_OnLoginSuccess_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesMenuPlayerController_OnLoginSuccess_Statics::EchoesMenuPlayerController_eventOnLoginSuccess_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesMenuPlayerController_OnLoginSuccess()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesMenuPlayerController_OnLoginSuccess_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesMenuPlayerController::execOnLoginSuccess)
{
	P_GET_STRUCT_REF(FAuthResponse,Z_Param_Out_AuthResponse);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnLoginSuccess(Z_Param_Out_AuthResponse);
	P_NATIVE_END;
}
// ********** End Class AEchoesMenuPlayerController Function OnLoginSuccess ************************

// ********** Begin Class AEchoesMenuPlayerController Function OnPreloadComplete *******************
struct Z_Construct_UFunction_AEchoesMenuPlayerController_OnPreloadComplete_Statics
{
	struct EchoesMenuPlayerController_eventOnPreloadComplete_Parms
	{
		ENextState NextState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Handle preload completion\n\x09 * Transitions to login or character select based on result\n\x09 */" },
#endif
		{ "ModuleRelativePath", "EchoesMenuPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handle preload completion\nTransitions to login or character select based on result" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_NextState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NextState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_AEchoesMenuPlayerController_OnPreloadComplete_Statics::NewProp_NextState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_AEchoesMenuPlayerController_OnPreloadComplete_Statics::NewProp_NextState = { "NextState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesMenuPlayerController_eventOnPreloadComplete_Parms, NextState), Z_Construct_UEnum_Echoes_ENextState, METADATA_PARAMS(0, nullptr) }; // 3766622234
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesMenuPlayerController_OnPreloadComplete_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesMenuPlayerController_OnPreloadComplete_Statics::NewProp_NextState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesMenuPlayerController_OnPreloadComplete_Statics::NewProp_NextState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesMenuPlayerController_OnPreloadComplete_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesMenuPlayerController_OnPreloadComplete_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesMenuPlayerController, nullptr, "OnPreloadComplete", Z_Construct_UFunction_AEchoesMenuPlayerController_OnPreloadComplete_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesMenuPlayerController_OnPreloadComplete_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesMenuPlayerController_OnPreloadComplete_Statics::EchoesMenuPlayerController_eventOnPreloadComplete_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesMenuPlayerController_OnPreloadComplete_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesMenuPlayerController_OnPreloadComplete_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesMenuPlayerController_OnPreloadComplete_Statics::EchoesMenuPlayerController_eventOnPreloadComplete_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesMenuPlayerController_OnPreloadComplete()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesMenuPlayerController_OnPreloadComplete_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesMenuPlayerController::execOnPreloadComplete)
{
	P_GET_ENUM(ENextState,Z_Param_NextState);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnPreloadComplete(ENextState(Z_Param_NextState));
	P_NATIVE_END;
}
// ********** End Class AEchoesMenuPlayerController Function OnPreloadComplete *********************

// ********** Begin Class AEchoesMenuPlayerController Function ShowCharacterSelect *****************
struct Z_Construct_UFunction_AEchoesMenuPlayerController_ShowCharacterSelect_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Menu" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Show character selection screen\n\x09 * Called after successful login\n\x09 */" },
#endif
		{ "ModuleRelativePath", "EchoesMenuPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Show character selection screen\nCalled after successful login" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesMenuPlayerController_ShowCharacterSelect_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesMenuPlayerController, nullptr, "ShowCharacterSelect", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesMenuPlayerController_ShowCharacterSelect_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesMenuPlayerController_ShowCharacterSelect_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AEchoesMenuPlayerController_ShowCharacterSelect()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesMenuPlayerController_ShowCharacterSelect_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesMenuPlayerController::execShowCharacterSelect)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ShowCharacterSelect();
	P_NATIVE_END;
}
// ********** End Class AEchoesMenuPlayerController Function ShowCharacterSelect *******************

// ********** Begin Class AEchoesMenuPlayerController Function ShowLoginScreen *********************
struct Z_Construct_UFunction_AEchoesMenuPlayerController_ShowLoginScreen_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Menu" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Show login screen\n\x09 * Called when player needs to authenticate\n\x09 */" },
#endif
		{ "ModuleRelativePath", "EchoesMenuPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Show login screen\nCalled when player needs to authenticate" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesMenuPlayerController_ShowLoginScreen_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesMenuPlayerController, nullptr, "ShowLoginScreen", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesMenuPlayerController_ShowLoginScreen_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesMenuPlayerController_ShowLoginScreen_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AEchoesMenuPlayerController_ShowLoginScreen()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesMenuPlayerController_ShowLoginScreen_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesMenuPlayerController::execShowLoginScreen)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ShowLoginScreen();
	P_NATIVE_END;
}
// ********** End Class AEchoesMenuPlayerController Function ShowLoginScreen ***********************

// ********** Begin Class AEchoesMenuPlayerController **********************************************
void AEchoesMenuPlayerController::StaticRegisterNativesAEchoesMenuPlayerController()
{
	UClass* Class = AEchoesMenuPlayerController::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnLoginSuccess", &AEchoesMenuPlayerController::execOnLoginSuccess },
		{ "OnPreloadComplete", &AEchoesMenuPlayerController::execOnPreloadComplete },
		{ "ShowCharacterSelect", &AEchoesMenuPlayerController::execShowCharacterSelect },
		{ "ShowLoginScreen", &AEchoesMenuPlayerController::execShowLoginScreen },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_AEchoesMenuPlayerController;
UClass* AEchoesMenuPlayerController::GetPrivateStaticClass()
{
	using TClass = AEchoesMenuPlayerController;
	if (!Z_Registration_Info_UClass_AEchoesMenuPlayerController.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesMenuPlayerController"),
			Z_Registration_Info_UClass_AEchoesMenuPlayerController.InnerSingleton,
			StaticRegisterNativesAEchoesMenuPlayerController,
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
	return Z_Registration_Info_UClass_AEchoesMenuPlayerController.InnerSingleton;
}
UClass* Z_Construct_UClass_AEchoesMenuPlayerController_NoRegister()
{
	return AEchoesMenuPlayerController::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AEchoesMenuPlayerController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * AEchoesMenuPlayerController\n * \n * Centralized menu controller for authorization flow\n * Manages widget transitions and input mode\n * \n * Authorization Chain:\n * Preload (token check) -> Login (credentials) -> CharacterSelect -> ConnectToWorld\n * \n * Key Features:\n * - ShowLoginScreen() - Display login widget\n * - ShowCharacterSelect() - Display character selection widget\n * - ChangeWidget() - Internal method for widget transitions\n * - Handles bShowMouseCursor = true and FInputModeUIOnly\n * - Only operates on local player controllers\n * \n * Usage:\n * - Create a Blueprint based on this class\n * - Set widget class properties in Blueprint\n * - Assign this controller in EchoesMenuGameMode\n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "EchoesMenuPlayerController.h" },
		{ "ModuleRelativePath", "EchoesMenuPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "AEchoesMenuPlayerController\n\nCentralized menu controller for authorization flow\nManages widget transitions and input mode\n\nAuthorization Chain:\nPreload (token check) -> Login (credentials) -> CharacterSelect -> ConnectToWorld\n\nKey Features:\n- ShowLoginScreen() - Display login widget\n- ShowCharacterSelect() - Display character selection widget\n- ChangeWidget() - Internal method for widget transitions\n- Handles bShowMouseCursor = true and FInputModeUIOnly\n- Only operates on local player controllers\n\nUsage:\n- Create a Blueprint based on this class\n- Set widget class properties in Blueprint\n- Assign this controller in EchoesMenuGameMode" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreloadWidgetClass_MetaData[] = {
		{ "Category", "UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Preload widget class for initial validation\n\x09 * Set this in Blueprint to WBP_Preload or similar\n\x09 */" },
#endif
		{ "ModuleRelativePath", "EchoesMenuPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Preload widget class for initial validation\nSet this in Blueprint to WBP_Preload or similar" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LoginWidgetClass_MetaData[] = {
		{ "Category", "UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Login widget class for authentication\n\x09 * Set this in Blueprint to WBP_Login or similar\n\x09 */" },
#endif
		{ "ModuleRelativePath", "EchoesMenuPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Login widget class for authentication\nSet this in Blueprint to WBP_Login or similar" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterSelectWidgetClass_MetaData[] = {
		{ "Category", "UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Character select widget class\n\x09 * Set this in Blueprint to WBP_CharacterSelect or similar\n\x09 */" },
#endif
		{ "ModuleRelativePath", "EchoesMenuPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Character select widget class\nSet this in Blueprint to WBP_CharacterSelect or similar" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentWidget_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Currently active widget\n\x09 */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "EchoesMenuPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Currently active widget" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_PreloadWidgetClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_LoginWidgetClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_CharacterSelectWidgetClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentWidget;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AEchoesMenuPlayerController_OnLoginSuccess, "OnLoginSuccess" }, // 3475076115
		{ &Z_Construct_UFunction_AEchoesMenuPlayerController_OnPreloadComplete, "OnPreloadComplete" }, // 2576847637
		{ &Z_Construct_UFunction_AEchoesMenuPlayerController_ShowCharacterSelect, "ShowCharacterSelect" }, // 276579878
		{ &Z_Construct_UFunction_AEchoesMenuPlayerController_ShowLoginScreen, "ShowLoginScreen" }, // 1192766696
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEchoesMenuPlayerController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AEchoesMenuPlayerController_Statics::NewProp_PreloadWidgetClass = { "PreloadWidgetClass", nullptr, (EPropertyFlags)0x0024080000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesMenuPlayerController, PreloadWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UEchoesPreloadWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreloadWidgetClass_MetaData), NewProp_PreloadWidgetClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AEchoesMenuPlayerController_Statics::NewProp_LoginWidgetClass = { "LoginWidgetClass", nullptr, (EPropertyFlags)0x0024080000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesMenuPlayerController, LoginWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UEchoesLoginWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LoginWidgetClass_MetaData), NewProp_LoginWidgetClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AEchoesMenuPlayerController_Statics::NewProp_CharacterSelectWidgetClass = { "CharacterSelectWidgetClass", nullptr, (EPropertyFlags)0x0024080000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesMenuPlayerController, CharacterSelectWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UEchoesCharacterSelectWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterSelectWidgetClass_MetaData), NewProp_CharacterSelectWidgetClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEchoesMenuPlayerController_Statics::NewProp_CurrentWidget = { "CurrentWidget", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesMenuPlayerController, CurrentWidget), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentWidget_MetaData), NewProp_CurrentWidget_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEchoesMenuPlayerController_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesMenuPlayerController_Statics::NewProp_PreloadWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesMenuPlayerController_Statics::NewProp_LoginWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesMenuPlayerController_Statics::NewProp_CharacterSelectWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesMenuPlayerController_Statics::NewProp_CurrentWidget,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEchoesMenuPlayerController_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AEchoesMenuPlayerController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerController,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEchoesMenuPlayerController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AEchoesMenuPlayerController_Statics::ClassParams = {
	&AEchoesMenuPlayerController::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AEchoesMenuPlayerController_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AEchoesMenuPlayerController_Statics::PropPointers),
	0,
	0x009003A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEchoesMenuPlayerController_Statics::Class_MetaDataParams), Z_Construct_UClass_AEchoesMenuPlayerController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AEchoesMenuPlayerController()
{
	if (!Z_Registration_Info_UClass_AEchoesMenuPlayerController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEchoesMenuPlayerController.OuterSingleton, Z_Construct_UClass_AEchoesMenuPlayerController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AEchoesMenuPlayerController.OuterSingleton;
}
AEchoesMenuPlayerController::AEchoesMenuPlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(AEchoesMenuPlayerController);
AEchoesMenuPlayerController::~AEchoesMenuPlayerController() {}
// ********** End Class AEchoesMenuPlayerController ************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesMenuPlayerController_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AEchoesMenuPlayerController, AEchoesMenuPlayerController::StaticClass, TEXT("AEchoesMenuPlayerController"), &Z_Registration_Info_UClass_AEchoesMenuPlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEchoesMenuPlayerController), 1866731552U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesMenuPlayerController_h__Script_Echoes_2247123271(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesMenuPlayerController_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesMenuPlayerController_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
