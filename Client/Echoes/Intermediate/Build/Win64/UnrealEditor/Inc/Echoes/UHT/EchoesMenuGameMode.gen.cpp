// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EchoesMenuGameMode.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesMenuGameMode() {}

// ********** Begin Cross Module References ********************************************************
ECHOES_API UClass* Z_Construct_UClass_AEchoesMenuGameMode();
ECHOES_API UClass* Z_Construct_UClass_AEchoesMenuGameMode_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AEchoesMenuGameMode ******************************************************
void AEchoesMenuGameMode::StaticRegisterNativesAEchoesMenuGameMode()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_AEchoesMenuGameMode;
UClass* AEchoesMenuGameMode::GetPrivateStaticClass()
{
	using TClass = AEchoesMenuGameMode;
	if (!Z_Registration_Info_UClass_AEchoesMenuGameMode.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesMenuGameMode"),
			Z_Registration_Info_UClass_AEchoesMenuGameMode.InnerSingleton,
			StaticRegisterNativesAEchoesMenuGameMode,
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
	return Z_Registration_Info_UClass_AEchoesMenuGameMode.InnerSingleton;
}
UClass* Z_Construct_UClass_AEchoesMenuGameMode_NoRegister()
{
	return AEchoesMenuGameMode::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AEchoesMenuGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * AEchoesMenuGameMode\n * \n * Game mode for character selection menu\n * Prevents pawn spawning and uses specialized menu player controller\n * \n * Key Features:\n * - No pawn spawning (DefaultPawnClass = nullptr)\n * - Uses EchoesMenuPlayerController for UI management\n * - Designed for standalone/listen server menu maps\n * \n * Usage:\n * - Create a Blueprint based on this class\n * - Set as GameMode override in World Settings of CharacterSelectMap\n * - In the Blueprint, ensure PlayerControllerClass is set to EchoesMenuPlayerController\n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "EchoesMenuGameMode.h" },
		{ "ModuleRelativePath", "EchoesMenuGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "AEchoesMenuGameMode\n\nGame mode for character selection menu\nPrevents pawn spawning and uses specialized menu player controller\n\nKey Features:\n- No pawn spawning (DefaultPawnClass = nullptr)\n- Uses EchoesMenuPlayerController for UI management\n- Designed for standalone/listen server menu maps\n\nUsage:\n- Create a Blueprint based on this class\n- Set as GameMode override in World Settings of CharacterSelectMap\n- In the Blueprint, ensure PlayerControllerClass is set to EchoesMenuPlayerController" },
#endif
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEchoesMenuGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AEchoesMenuGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEchoesMenuGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AEchoesMenuGameMode_Statics::ClassParams = {
	&AEchoesMenuGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009003ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEchoesMenuGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AEchoesMenuGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AEchoesMenuGameMode()
{
	if (!Z_Registration_Info_UClass_AEchoesMenuGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEchoesMenuGameMode.OuterSingleton, Z_Construct_UClass_AEchoesMenuGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AEchoesMenuGameMode.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AEchoesMenuGameMode);
AEchoesMenuGameMode::~AEchoesMenuGameMode() {}
// ********** End Class AEchoesMenuGameMode ********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesMenuGameMode_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AEchoesMenuGameMode, AEchoesMenuGameMode::StaticClass, TEXT("AEchoesMenuGameMode"), &Z_Registration_Info_UClass_AEchoesMenuGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEchoesMenuGameMode), 3725204469U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesMenuGameMode_h__Script_Echoes_1683872036(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesMenuGameMode_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_EchoesMenuGameMode_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
