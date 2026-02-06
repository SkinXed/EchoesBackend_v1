// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EchoesServerAuthSubsystem.h"
#include "Engine/GameInstance.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesServerAuthSubsystem() {}

// ********** Begin Cross Module References ********************************************************
ECHOES_API UClass* Z_Construct_UClass_UEchoesServerAuthSubsystem();
ECHOES_API UClass* Z_Construct_UClass_UEchoesServerAuthSubsystem_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UEchoesServerAuthSubsystem ***********************************************
void UEchoesServerAuthSubsystem::StaticRegisterNativesUEchoesServerAuthSubsystem()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UEchoesServerAuthSubsystem;
UClass* UEchoesServerAuthSubsystem::GetPrivateStaticClass()
{
	using TClass = UEchoesServerAuthSubsystem;
	if (!Z_Registration_Info_UClass_UEchoesServerAuthSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesServerAuthSubsystem"),
			Z_Registration_Info_UClass_UEchoesServerAuthSubsystem.InnerSingleton,
			StaticRegisterNativesUEchoesServerAuthSubsystem,
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
	return Z_Registration_Info_UClass_UEchoesServerAuthSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UEchoesServerAuthSubsystem_NoRegister()
{
	return UEchoesServerAuthSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UEchoesServerAuthSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * UEchoesServerAuthSubsystem\n * \n * Server-side subsystem for validating client JWT tokens through Backend API\n * Used by UE Dedicated Server to authenticate connecting players\n * \n * Architecture:\n * - GameInstanceSubsystem: Available on server instance\n * - Validates tokens via HTTP POST to /api/auth/validate-token\n * - Checks AccountSession.IsActive and expiration\n * - Prevents unauthorized access to game servers\n */" },
#endif
		{ "IncludePath", "Core/Server/EchoesServerAuthSubsystem.h" },
		{ "ModuleRelativePath", "Core/Server/EchoesServerAuthSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UEchoesServerAuthSubsystem\n\nServer-side subsystem for validating client JWT tokens through Backend API\nUsed by UE Dedicated Server to authenticate connecting players\n\nArchitecture:\n- GameInstanceSubsystem: Available on server instance\n- Validates tokens via HTTP POST to /api/auth/validate-token\n- Checks AccountSession.IsActive and expiration\n- Prevents unauthorized access to game servers" },
#endif
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEchoesServerAuthSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UEchoesServerAuthSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesServerAuthSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEchoesServerAuthSubsystem_Statics::ClassParams = {
	&UEchoesServerAuthSubsystem::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesServerAuthSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UEchoesServerAuthSubsystem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEchoesServerAuthSubsystem()
{
	if (!Z_Registration_Info_UClass_UEchoesServerAuthSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEchoesServerAuthSubsystem.OuterSingleton, Z_Construct_UClass_UEchoesServerAuthSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEchoesServerAuthSubsystem.OuterSingleton;
}
UEchoesServerAuthSubsystem::UEchoesServerAuthSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UEchoesServerAuthSubsystem);
UEchoesServerAuthSubsystem::~UEchoesServerAuthSubsystem() {}
// ********** End Class UEchoesServerAuthSubsystem *************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_EchoesServerAuthSubsystem_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEchoesServerAuthSubsystem, UEchoesServerAuthSubsystem::StaticClass, TEXT("UEchoesServerAuthSubsystem"), &Z_Registration_Info_UClass_UEchoesServerAuthSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEchoesServerAuthSubsystem), 2141040U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_EchoesServerAuthSubsystem_h__Script_Echoes_3856143764(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_EchoesServerAuthSubsystem_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Server_EchoesServerAuthSubsystem_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
