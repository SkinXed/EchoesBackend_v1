// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EchoesCharacterListEntry.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesCharacterListEntry() {}

// ********** Begin Cross Module References ********************************************************
ECHOES_API UClass* Z_Construct_UClass_UEchoesCharacterListEntry();
ECHOES_API UClass* Z_Construct_UClass_UEchoesCharacterListEntry_NoRegister();
UMG_API UClass* Z_Construct_UClass_UImage_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserObjectListEntry_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UEchoesCharacterListEntry ************************************************
void UEchoesCharacterListEntry::StaticRegisterNativesUEchoesCharacterListEntry()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UEchoesCharacterListEntry;
UClass* UEchoesCharacterListEntry::GetPrivateStaticClass()
{
	using TClass = UEchoesCharacterListEntry;
	if (!Z_Registration_Info_UClass_UEchoesCharacterListEntry.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesCharacterListEntry"),
			Z_Registration_Info_UClass_UEchoesCharacterListEntry.InnerSingleton,
			StaticRegisterNativesUEchoesCharacterListEntry,
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
	return Z_Registration_Info_UClass_UEchoesCharacterListEntry.InnerSingleton;
}
UClass* Z_Construct_UClass_UEchoesCharacterListEntry_NoRegister()
{
	return UEchoesCharacterListEntry::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UEchoesCharacterListEntry_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * ?????? ????? ?????? ? ?????? ??????????\n */" },
#endif
		{ "IncludePath", "UI/Widgets/EchoesCharacterListEntry.h" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesCharacterListEntry.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NameText_MetaData[] = {
		{ "BindWidget", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ??????????? UI ????????. ????? ? Blueprint ?????? ?????????!\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesCharacterListEntry.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "??????????? UI ????????. ????? ? Blueprint ?????? ?????????!" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RaceText_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesCharacterListEntry.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AvatarImage_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/EchoesCharacterListEntry.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NameText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RaceText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AvatarImage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEchoesCharacterListEntry>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesCharacterListEntry_Statics::NewProp_NameText = { "NameText", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesCharacterListEntry, NameText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NameText_MetaData), NewProp_NameText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesCharacterListEntry_Statics::NewProp_RaceText = { "RaceText", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesCharacterListEntry, RaceText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RaceText_MetaData), NewProp_RaceText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesCharacterListEntry_Statics::NewProp_AvatarImage = { "AvatarImage", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesCharacterListEntry, AvatarImage), Z_Construct_UClass_UImage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AvatarImage_MetaData), NewProp_AvatarImage_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEchoesCharacterListEntry_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesCharacterListEntry_Statics::NewProp_NameText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesCharacterListEntry_Statics::NewProp_RaceText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesCharacterListEntry_Statics::NewProp_AvatarImage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesCharacterListEntry_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UEchoesCharacterListEntry_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesCharacterListEntry_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UEchoesCharacterListEntry_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UUserObjectListEntry_NoRegister, (int32)VTABLE_OFFSET(UEchoesCharacterListEntry, IUserObjectListEntry), false },  // 1900202470
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEchoesCharacterListEntry_Statics::ClassParams = {
	&UEchoesCharacterListEntry::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UEchoesCharacterListEntry_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesCharacterListEntry_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesCharacterListEntry_Statics::Class_MetaDataParams), Z_Construct_UClass_UEchoesCharacterListEntry_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEchoesCharacterListEntry()
{
	if (!Z_Registration_Info_UClass_UEchoesCharacterListEntry.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEchoesCharacterListEntry.OuterSingleton, Z_Construct_UClass_UEchoesCharacterListEntry_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEchoesCharacterListEntry.OuterSingleton;
}
UEchoesCharacterListEntry::UEchoesCharacterListEntry(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UEchoesCharacterListEntry);
UEchoesCharacterListEntry::~UEchoesCharacterListEntry() {}
// ********** End Class UEchoesCharacterListEntry **************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesCharacterListEntry_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEchoesCharacterListEntry, UEchoesCharacterListEntry::StaticClass, TEXT("UEchoesCharacterListEntry"), &Z_Registration_Info_UClass_UEchoesCharacterListEntry, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEchoesCharacterListEntry), 527395947U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesCharacterListEntry_h__Script_Echoes_3246889015(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesCharacterListEntry_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_EchoesCharacterListEntry_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
