// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EchoesPlayerState.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesPlayerState() {}

// ********** Begin Cross Module References ********************************************************
ECHOES_API UClass* Z_Construct_UClass_AEchoesPlayerState();
ECHOES_API UClass* Z_Construct_UClass_AEchoesPlayerState_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APlayerState();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AEchoesPlayerState Function OnRep_AuthToken ******************************
struct Z_Construct_UFunction_AEchoesPlayerState_OnRep_AuthToken_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Common/Player/EchoesPlayerState.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesPlayerState_OnRep_AuthToken_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesPlayerState, nullptr, "OnRep_AuthToken", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesPlayerState_OnRep_AuthToken_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesPlayerState_OnRep_AuthToken_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AEchoesPlayerState_OnRep_AuthToken()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesPlayerState_OnRep_AuthToken_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesPlayerState::execOnRep_AuthToken)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_AuthToken();
	P_NATIVE_END;
}
// ********** End Class AEchoesPlayerState Function OnRep_AuthToken ********************************

// ********** Begin Class AEchoesPlayerState Function SetAuthToken *********************************
struct Z_Construct_UFunction_AEchoesPlayerState_SetAuthToken_Statics
{
	struct EchoesPlayerState_eventSetAuthToken_Parms
	{
		FString NewToken;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Auth" },
		{ "ModuleRelativePath", "Core/Common/Player/EchoesPlayerState.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NewToken_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_NewToken;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AEchoesPlayerState_SetAuthToken_Statics::NewProp_NewToken = { "NewToken", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesPlayerState_eventSetAuthToken_Parms, NewToken), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NewToken_MetaData), NewProp_NewToken_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesPlayerState_SetAuthToken_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesPlayerState_SetAuthToken_Statics::NewProp_NewToken,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesPlayerState_SetAuthToken_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesPlayerState_SetAuthToken_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesPlayerState, nullptr, "SetAuthToken", Z_Construct_UFunction_AEchoesPlayerState_SetAuthToken_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesPlayerState_SetAuthToken_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesPlayerState_SetAuthToken_Statics::EchoesPlayerState_eventSetAuthToken_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesPlayerState_SetAuthToken_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesPlayerState_SetAuthToken_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesPlayerState_SetAuthToken_Statics::EchoesPlayerState_eventSetAuthToken_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesPlayerState_SetAuthToken()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesPlayerState_SetAuthToken_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesPlayerState::execSetAuthToken)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_NewToken);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetAuthToken(Z_Param_NewToken);
	P_NATIVE_END;
}
// ********** End Class AEchoesPlayerState Function SetAuthToken ***********************************

// ********** Begin Class AEchoesPlayerState *******************************************************
void AEchoesPlayerState::StaticRegisterNativesAEchoesPlayerState()
{
	UClass* Class = AEchoesPlayerState::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnRep_AuthToken", &AEchoesPlayerState::execOnRep_AuthToken },
		{ "SetAuthToken", &AEchoesPlayerState::execSetAuthToken },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_AEchoesPlayerState;
UClass* AEchoesPlayerState::GetPrivateStaticClass()
{
	using TClass = AEchoesPlayerState;
	if (!Z_Registration_Info_UClass_AEchoesPlayerState.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesPlayerState"),
			Z_Registration_Info_UClass_AEchoesPlayerState.InnerSingleton,
			StaticRegisterNativesAEchoesPlayerState,
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
	return Z_Registration_Info_UClass_AEchoesPlayerState.InnerSingleton;
}
UClass* Z_Construct_UClass_AEchoesPlayerState_NoRegister()
{
	return AEchoesPlayerState::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AEchoesPlayerState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * AEchoesPlayerState\n *\n * Stores per-player server-side data such as authenticated token.\n */" },
#endif
		{ "HideCategories", "Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "Core/Common/Player/EchoesPlayerState.h" },
		{ "ModuleRelativePath", "Core/Common/Player/EchoesPlayerState.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "AEchoesPlayerState\n\nStores per-player server-side data such as authenticated token." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AuthToken_MetaData[] = {
		{ "Category", "Auth" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Store client's auth token for server-side subsystems\n" },
#endif
		{ "ModuleRelativePath", "Core/Common/Player/EchoesPlayerState.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Store client's auth token for server-side subsystems" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_AuthToken;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AEchoesPlayerState_OnRep_AuthToken, "OnRep_AuthToken" }, // 1206646561
		{ &Z_Construct_UFunction_AEchoesPlayerState_SetAuthToken, "SetAuthToken" }, // 1331803542
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEchoesPlayerState>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AEchoesPlayerState_Statics::NewProp_AuthToken = { "AuthToken", nullptr, (EPropertyFlags)0x0010000000000024, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesPlayerState, AuthToken), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AuthToken_MetaData), NewProp_AuthToken_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEchoesPlayerState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesPlayerState_Statics::NewProp_AuthToken,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEchoesPlayerState_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AEchoesPlayerState_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerState,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEchoesPlayerState_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AEchoesPlayerState_Statics::ClassParams = {
	&AEchoesPlayerState::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AEchoesPlayerState_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AEchoesPlayerState_Statics::PropPointers),
	0,
	0x009003A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEchoesPlayerState_Statics::Class_MetaDataParams), Z_Construct_UClass_AEchoesPlayerState_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AEchoesPlayerState()
{
	if (!Z_Registration_Info_UClass_AEchoesPlayerState.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEchoesPlayerState.OuterSingleton, Z_Construct_UClass_AEchoesPlayerState_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AEchoesPlayerState.OuterSingleton;
}
#if VALIDATE_CLASS_REPS
void AEchoesPlayerState::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static FName Name_AuthToken(TEXT("AuthToken"));
	const bool bIsValid = true
		&& Name_AuthToken == ClassReps[(int32)ENetFields_Private::AuthToken].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in AEchoesPlayerState"));
}
#endif
DEFINE_VTABLE_PTR_HELPER_CTOR(AEchoesPlayerState);
AEchoesPlayerState::~AEchoesPlayerState() {}
// ********** End Class AEchoesPlayerState *********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Player_EchoesPlayerState_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AEchoesPlayerState, AEchoesPlayerState::StaticClass, TEXT("AEchoesPlayerState"), &Z_Registration_Info_UClass_AEchoesPlayerState, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEchoesPlayerState), 1337577330U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Player_EchoesPlayerState_h__Script_Echoes_1439891369(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Player_EchoesPlayerState_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Player_EchoesPlayerState_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
