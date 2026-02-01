// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EchoesLocalPlayerSettings.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesLocalPlayerSettings() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FDateTime();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ECHOES_API UClass* Z_Construct_UClass_UEchoesLocalPlayerSettings();
ECHOES_API UClass* Z_Construct_UClass_UEchoesLocalPlayerSettings_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USaveGame();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UEchoesLocalPlayerSettings ***********************************************
void UEchoesLocalPlayerSettings::StaticRegisterNativesUEchoesLocalPlayerSettings()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UEchoesLocalPlayerSettings;
UClass* UEchoesLocalPlayerSettings::GetPrivateStaticClass()
{
	using TClass = UEchoesLocalPlayerSettings;
	if (!Z_Registration_Info_UClass_UEchoesLocalPlayerSettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesLocalPlayerSettings"),
			Z_Registration_Info_UClass_UEchoesLocalPlayerSettings.InnerSingleton,
			StaticRegisterNativesUEchoesLocalPlayerSettings,
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
	return Z_Registration_Info_UClass_UEchoesLocalPlayerSettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UEchoesLocalPlayerSettings_NoRegister()
{
	return UEchoesLocalPlayerSettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UEchoesLocalPlayerSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * UEchoesLocalPlayerSettings\n * \n * Save game class for persistent local player settings\n * Stores JWT token, character selection, and preferences\n * \n * Usage:\n * - AuthSubsystem saves token when \"Remember Me\" is checked\n * - Preload widget loads token on cold start\n * - Persists between game sessions\n */" },
#endif
		{ "IncludePath", "Core/Common/Save/EchoesLocalPlayerSettings.h" },
		{ "ModuleRelativePath", "Core/Common/Save/EchoesLocalPlayerSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UEchoesLocalPlayerSettings\n\nSave game class for persistent local player settings\nStores JWT token, character selection, and preferences\n\nUsage:\n- AuthSubsystem saves token when \"Remember Me\" is checked\n- Preload widget loads token on cold start\n- Persists between game sessions" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SavedAuthToken_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Saved JWT authentication token */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Save/EchoesLocalPlayerSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Saved JWT authentication token" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SavedCharacterId_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Saved character ID (last selected) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Save/EchoesLocalPlayerSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Saved character ID (last selected)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SavedAccountId_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Account ID associated with token */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Save/EchoesLocalPlayerSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Account ID associated with token" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TokenSavedAt_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** When the token was saved */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Save/EchoesLocalPlayerSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "When the token was saved" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TokenExpiresAt_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Token expiration time */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Save/EchoesLocalPlayerSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Token expiration time" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRememberMe_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Remember me flag */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Save/EchoesLocalPlayerSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Remember me flag" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_SavedAuthToken;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SavedCharacterId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SavedAccountId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TokenSavedAt;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TokenExpiresAt;
	static void NewProp_bRememberMe_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRememberMe;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEchoesLocalPlayerSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UEchoesLocalPlayerSettings_Statics::NewProp_SavedAuthToken = { "SavedAuthToken", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesLocalPlayerSettings, SavedAuthToken), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SavedAuthToken_MetaData), NewProp_SavedAuthToken_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEchoesLocalPlayerSettings_Statics::NewProp_SavedCharacterId = { "SavedCharacterId", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesLocalPlayerSettings, SavedCharacterId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SavedCharacterId_MetaData), NewProp_SavedCharacterId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEchoesLocalPlayerSettings_Statics::NewProp_SavedAccountId = { "SavedAccountId", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesLocalPlayerSettings, SavedAccountId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SavedAccountId_MetaData), NewProp_SavedAccountId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEchoesLocalPlayerSettings_Statics::NewProp_TokenSavedAt = { "TokenSavedAt", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesLocalPlayerSettings, TokenSavedAt), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TokenSavedAt_MetaData), NewProp_TokenSavedAt_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEchoesLocalPlayerSettings_Statics::NewProp_TokenExpiresAt = { "TokenExpiresAt", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesLocalPlayerSettings, TokenExpiresAt), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TokenExpiresAt_MetaData), NewProp_TokenExpiresAt_MetaData) };
void Z_Construct_UClass_UEchoesLocalPlayerSettings_Statics::NewProp_bRememberMe_SetBit(void* Obj)
{
	((UEchoesLocalPlayerSettings*)Obj)->bRememberMe = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UEchoesLocalPlayerSettings_Statics::NewProp_bRememberMe = { "bRememberMe", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UEchoesLocalPlayerSettings), &Z_Construct_UClass_UEchoesLocalPlayerSettings_Statics::NewProp_bRememberMe_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRememberMe_MetaData), NewProp_bRememberMe_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEchoesLocalPlayerSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesLocalPlayerSettings_Statics::NewProp_SavedAuthToken,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesLocalPlayerSettings_Statics::NewProp_SavedCharacterId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesLocalPlayerSettings_Statics::NewProp_SavedAccountId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesLocalPlayerSettings_Statics::NewProp_TokenSavedAt,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesLocalPlayerSettings_Statics::NewProp_TokenExpiresAt,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesLocalPlayerSettings_Statics::NewProp_bRememberMe,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesLocalPlayerSettings_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UEchoesLocalPlayerSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_USaveGame,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesLocalPlayerSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEchoesLocalPlayerSettings_Statics::ClassParams = {
	&UEchoesLocalPlayerSettings::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UEchoesLocalPlayerSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesLocalPlayerSettings_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesLocalPlayerSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UEchoesLocalPlayerSettings_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEchoesLocalPlayerSettings()
{
	if (!Z_Registration_Info_UClass_UEchoesLocalPlayerSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEchoesLocalPlayerSettings.OuterSingleton, Z_Construct_UClass_UEchoesLocalPlayerSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEchoesLocalPlayerSettings.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UEchoesLocalPlayerSettings);
UEchoesLocalPlayerSettings::~UEchoesLocalPlayerSettings() {}
// ********** End Class UEchoesLocalPlayerSettings *************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Save_EchoesLocalPlayerSettings_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEchoesLocalPlayerSettings, UEchoesLocalPlayerSettings::StaticClass, TEXT("UEchoesLocalPlayerSettings"), &Z_Registration_Info_UClass_UEchoesLocalPlayerSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEchoesLocalPlayerSettings), 3319453731U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Save_EchoesLocalPlayerSettings_h__Script_Echoes_2666744573(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Save_EchoesLocalPlayerSettings_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Save_EchoesLocalPlayerSettings_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
