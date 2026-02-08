// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EchoesPlayerController.h"
#include "EchoesAuthSubsystem.h"
#include "UObject/CoreNet.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesPlayerController() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ECHOES_API UClass* Z_Construct_UClass_AEchoesPlayerController();
ECHOES_API UClass* Z_Construct_UClass_AEchoesPlayerController_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UEchoesCharacterSelectWidget_NoRegister();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FCharacterInfo();
ENGINE_API UClass* Z_Construct_UClass_APlayerController();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AEchoesPlayerController Function Client_ShowCharacterSelection ***********
struct EchoesPlayerController_eventClient_ShowCharacterSelection_Parms
{
	TArray<FCharacterInfo> Characters;
};
static FName NAME_AEchoesPlayerController_Client_ShowCharacterSelection = FName(TEXT("Client_ShowCharacterSelection"));
void AEchoesPlayerController::Client_ShowCharacterSelection(TArray<FCharacterInfo> const& Characters)
{
	EchoesPlayerController_eventClient_ShowCharacterSelection_Parms Parms;
	Parms.Characters=Characters;
	UFunction* Func = FindFunctionChecked(NAME_AEchoesPlayerController_Client_ShowCharacterSelection);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AEchoesPlayerController_Client_ShowCharacterSelection_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Client RPC - show character selection widget and populate it */" },
#endif
		{ "ModuleRelativePath", "EchoesPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Client RPC - show character selection widget and populate it" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Characters_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Characters_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Characters;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEchoesPlayerController_Client_ShowCharacterSelection_Statics::NewProp_Characters_Inner = { "Characters", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FCharacterInfo, METADATA_PARAMS(0, nullptr) }; // 2081289632
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AEchoesPlayerController_Client_ShowCharacterSelection_Statics::NewProp_Characters = { "Characters", nullptr, (EPropertyFlags)0x0010000008000082, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesPlayerController_eventClient_ShowCharacterSelection_Parms, Characters), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Characters_MetaData), NewProp_Characters_MetaData) }; // 2081289632
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesPlayerController_Client_ShowCharacterSelection_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesPlayerController_Client_ShowCharacterSelection_Statics::NewProp_Characters_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesPlayerController_Client_ShowCharacterSelection_Statics::NewProp_Characters,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesPlayerController_Client_ShowCharacterSelection_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesPlayerController_Client_ShowCharacterSelection_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesPlayerController, nullptr, "Client_ShowCharacterSelection", Z_Construct_UFunction_AEchoesPlayerController_Client_ShowCharacterSelection_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesPlayerController_Client_ShowCharacterSelection_Statics::PropPointers), sizeof(EchoesPlayerController_eventClient_ShowCharacterSelection_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01020CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesPlayerController_Client_ShowCharacterSelection_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesPlayerController_Client_ShowCharacterSelection_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(EchoesPlayerController_eventClient_ShowCharacterSelection_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesPlayerController_Client_ShowCharacterSelection()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesPlayerController_Client_ShowCharacterSelection_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesPlayerController::execClient_ShowCharacterSelection)
{
	P_GET_TARRAY(FCharacterInfo,Z_Param_Characters);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Client_ShowCharacterSelection_Implementation(Z_Param_Characters);
	P_NATIVE_END;
}
// ********** End Class AEchoesPlayerController Function Client_ShowCharacterSelection *************

// ********** Begin Class AEchoesPlayerController Function Server_SelectCharacter ******************
struct EchoesPlayerController_eventServer_SelectCharacter_Parms
{
	FGuid CharacterId;
};
static FName NAME_AEchoesPlayerController_Server_SelectCharacter = FName(TEXT("Server_SelectCharacter"));
void AEchoesPlayerController::Server_SelectCharacter(FGuid const& CharacterId)
{
	EchoesPlayerController_eventServer_SelectCharacter_Parms Parms;
	Parms.CharacterId=CharacterId;
	UFunction* Func = FindFunctionChecked(NAME_AEchoesPlayerController_Server_SelectCharacter);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AEchoesPlayerController_Server_SelectCharacter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Server RPC - client selects a character and notifies server */" },
#endif
		{ "ModuleRelativePath", "EchoesPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Server RPC - client selects a character and notifies server" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_CharacterId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEchoesPlayerController_Server_SelectCharacter_Statics::NewProp_CharacterId = { "CharacterId", nullptr, (EPropertyFlags)0x0010000008000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesPlayerController_eventServer_SelectCharacter_Parms, CharacterId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterId_MetaData), NewProp_CharacterId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesPlayerController_Server_SelectCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesPlayerController_Server_SelectCharacter_Statics::NewProp_CharacterId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesPlayerController_Server_SelectCharacter_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesPlayerController_Server_SelectCharacter_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesPlayerController, nullptr, "Server_SelectCharacter", Z_Construct_UFunction_AEchoesPlayerController_Server_SelectCharacter_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesPlayerController_Server_SelectCharacter_Statics::PropPointers), sizeof(EchoesPlayerController_eventServer_SelectCharacter_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80A20CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesPlayerController_Server_SelectCharacter_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesPlayerController_Server_SelectCharacter_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(EchoesPlayerController_eventServer_SelectCharacter_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesPlayerController_Server_SelectCharacter()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesPlayerController_Server_SelectCharacter_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesPlayerController::execServer_SelectCharacter)
{
	P_GET_STRUCT(FGuid,Z_Param_CharacterId);
	P_FINISH;
	P_NATIVE_BEGIN;
	if (!P_THIS->Server_SelectCharacter_Validate(Z_Param_CharacterId))
	{
		RPC_ValidateFailed(TEXT("Server_SelectCharacter_Validate"));
		return;
	}
	P_THIS->Server_SelectCharacter_Implementation(Z_Param_CharacterId);
	P_NATIVE_END;
}
// ********** End Class AEchoesPlayerController Function Server_SelectCharacter ********************

// ********** Begin Class AEchoesPlayerController **************************************************
void AEchoesPlayerController::StaticRegisterNativesAEchoesPlayerController()
{
	UClass* Class = AEchoesPlayerController::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "Client_ShowCharacterSelection", &AEchoesPlayerController::execClient_ShowCharacterSelection },
		{ "Server_SelectCharacter", &AEchoesPlayerController::execServer_SelectCharacter },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_AEchoesPlayerController;
UClass* AEchoesPlayerController::GetPrivateStaticClass()
{
	using TClass = AEchoesPlayerController;
	if (!Z_Registration_Info_UClass_AEchoesPlayerController.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesPlayerController"),
			Z_Registration_Info_UClass_AEchoesPlayerController.InnerSingleton,
			StaticRegisterNativesAEchoesPlayerController,
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
	return Z_Registration_Info_UClass_AEchoesPlayerController.InnerSingleton;
}
UClass* Z_Construct_UClass_AEchoesPlayerController_NoRegister()
{
	return AEchoesPlayerController::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AEchoesPlayerController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "EchoesPlayerController.h" },
		{ "ModuleRelativePath", "EchoesPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterSelectWidgetClass_MetaData[] = {
		{ "Category", "Echoes|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Widget class to use for character selection (set in Blueprint) */" },
#endif
		{ "ModuleRelativePath", "EchoesPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Widget class to use for character selection (set in Blueprint)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterSelectWidgetInstance_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Local reference to spawned widget */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "EchoesPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Local reference to spawned widget" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_CharacterSelectWidgetClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CharacterSelectWidgetInstance;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AEchoesPlayerController_Client_ShowCharacterSelection, "Client_ShowCharacterSelection" }, // 1468249246
		{ &Z_Construct_UFunction_AEchoesPlayerController_Server_SelectCharacter, "Server_SelectCharacter" }, // 2349063428
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEchoesPlayerController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AEchoesPlayerController_Statics::NewProp_CharacterSelectWidgetClass = { "CharacterSelectWidgetClass", nullptr, (EPropertyFlags)0x0014000000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesPlayerController, CharacterSelectWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UEchoesCharacterSelectWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterSelectWidgetClass_MetaData), NewProp_CharacterSelectWidgetClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEchoesPlayerController_Statics::NewProp_CharacterSelectWidgetInstance = { "CharacterSelectWidgetInstance", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesPlayerController, CharacterSelectWidgetInstance), Z_Construct_UClass_UEchoesCharacterSelectWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterSelectWidgetInstance_MetaData), NewProp_CharacterSelectWidgetInstance_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEchoesPlayerController_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesPlayerController_Statics::NewProp_CharacterSelectWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesPlayerController_Statics::NewProp_CharacterSelectWidgetInstance,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEchoesPlayerController_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AEchoesPlayerController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerController,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEchoesPlayerController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AEchoesPlayerController_Statics::ClassParams = {
	&AEchoesPlayerController::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AEchoesPlayerController_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AEchoesPlayerController_Statics::PropPointers),
	0,
	0x009003A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEchoesPlayerController_Statics::Class_MetaDataParams), Z_Construct_UClass_AEchoesPlayerController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AEchoesPlayerController()
{
	if (!Z_Registration_Info_UClass_AEchoesPlayerController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEchoesPlayerController.OuterSingleton, Z_Construct_UClass_AEchoesPlayerController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AEchoesPlayerController.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AEchoesPlayerController);
AEchoesPlayerController::~AEchoesPlayerController() {}
// ********** End Class AEchoesPlayerController ****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesPlayerController_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AEchoesPlayerController, AEchoesPlayerController::StaticClass, TEXT("AEchoesPlayerController"), &Z_Registration_Info_UClass_AEchoesPlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEchoesPlayerController), 3291179981U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesPlayerController_h__Script_Echoes_2461900401(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesPlayerController_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesPlayerController_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
