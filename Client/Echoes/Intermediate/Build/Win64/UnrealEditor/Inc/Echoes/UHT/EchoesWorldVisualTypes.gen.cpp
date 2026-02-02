// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EchoesWorldVisualTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesWorldVisualTypes() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FAnomalyVisualRow();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FAsteroidBeltVisualRow();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FPlanetVisualRow();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FStargateVisualRow();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FStarVisualRow();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FStationVisualRow();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FWormholeVisualRow();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UParticleSystem_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTableRowBase();
NIAGARA_API UClass* Z_Construct_UClass_UNiagaraSystem_NoRegister();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FPlanetVisualRow **************************************************
static_assert(std::is_polymorphic<FPlanetVisualRow>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FPlanetVisualRow cannot be polymorphic unless super FTableRowBase is polymorphic");
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FPlanetVisualRow;
class UScriptStruct* FPlanetVisualRow::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FPlanetVisualRow.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FPlanetVisualRow.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPlanetVisualRow, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("PlanetVisualRow"));
	}
	return Z_Registration_Info_UScriptStruct_FPlanetVisualRow.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FPlanetVisualRow_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Visual configuration for planets\n * Maps planet types from database to Unreal assets\n * Uses TSoftObjectPtr for memory optimization (lazy loading)\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Visual configuration for planets\nMaps planet types from database to Unreal assets\nUses TSoftObjectPtr for memory optimization (lazy loading)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActorClass_MetaData[] = {
		{ "Category", "Visual" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Planet blueprint actor */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Planet blueprint actor" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActorScale_MetaData[] = {
		{ "Category", "Visual" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Scale applied to the planet actor */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Scale applied to the planet actor" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AtmosphereScale_MetaData[] = {
		{ "Category", "Atmosphere" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Atmosphere scale (0 = no atmosphere, 1 = normal, >1 = thick atmosphere) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Atmosphere scale (0 = no atmosphere, 1 = normal, >1 = thick atmosphere)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CloudRotationSpeed_MetaData[] = {
		{ "Category", "Clouds" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Cloud rotation speed */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cloud rotation speed" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EmissiveIntensity_MetaData[] = {
		{ "Category", "Visual" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Emissive intensity for lava/volcanic planets */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Emissive intensity for lava/volcanic planets" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FSoftClassPropertyParams NewProp_ActorClass;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ActorScale;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AtmosphereScale;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CloudRotationSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_EmissiveIntensity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPlanetVisualRow>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FSoftClassPropertyParams Z_Construct_UScriptStruct_FPlanetVisualRow_Statics::NewProp_ActorClass = { "ActorClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftClass, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlanetVisualRow, ActorClass), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActorClass_MetaData), NewProp_ActorClass_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPlanetVisualRow_Statics::NewProp_ActorScale = { "ActorScale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlanetVisualRow, ActorScale), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActorScale_MetaData), NewProp_ActorScale_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPlanetVisualRow_Statics::NewProp_AtmosphereScale = { "AtmosphereScale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlanetVisualRow, AtmosphereScale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AtmosphereScale_MetaData), NewProp_AtmosphereScale_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPlanetVisualRow_Statics::NewProp_CloudRotationSpeed = { "CloudRotationSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlanetVisualRow, CloudRotationSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CloudRotationSpeed_MetaData), NewProp_CloudRotationSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPlanetVisualRow_Statics::NewProp_EmissiveIntensity = { "EmissiveIntensity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlanetVisualRow, EmissiveIntensity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EmissiveIntensity_MetaData), NewProp_EmissiveIntensity_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPlanetVisualRow_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlanetVisualRow_Statics::NewProp_ActorClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlanetVisualRow_Statics::NewProp_ActorScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlanetVisualRow_Statics::NewProp_AtmosphereScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlanetVisualRow_Statics::NewProp_CloudRotationSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlanetVisualRow_Statics::NewProp_EmissiveIntensity,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPlanetVisualRow_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPlanetVisualRow_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	Z_Construct_UScriptStruct_FTableRowBase,
	&NewStructOps,
	"PlanetVisualRow",
	Z_Construct_UScriptStruct_FPlanetVisualRow_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPlanetVisualRow_Statics::PropPointers),
	sizeof(FPlanetVisualRow),
	alignof(FPlanetVisualRow),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPlanetVisualRow_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPlanetVisualRow_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FPlanetVisualRow()
{
	if (!Z_Registration_Info_UScriptStruct_FPlanetVisualRow.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FPlanetVisualRow.InnerSingleton, Z_Construct_UScriptStruct_FPlanetVisualRow_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FPlanetVisualRow.InnerSingleton;
}
// ********** End ScriptStruct FPlanetVisualRow ****************************************************

// ********** Begin ScriptStruct FStarVisualRow ****************************************************
static_assert(std::is_polymorphic<FStarVisualRow>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FStarVisualRow cannot be polymorphic unless super FTableRowBase is polymorphic");
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FStarVisualRow;
class UScriptStruct* FStarVisualRow::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FStarVisualRow.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FStarVisualRow.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FStarVisualRow, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("StarVisualRow"));
	}
	return Z_Registration_Info_UScriptStruct_FStarVisualRow.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FStarVisualRow_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Visual configuration for stars\n * Defines corona effects, lighting, and post-process settings\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Visual configuration for stars\nDefines corona effects, lighting, and post-process settings" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActorClass_MetaData[] = {
		{ "Category", "Visual" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Star blueprint actor */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Star blueprint actor" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActorScale_MetaData[] = {
		{ "Category", "Visual" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Scale applied to the star actor */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Scale applied to the star actor" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CoronaParticles_MetaData[] = {
		{ "Category", "Corona" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Corona particle system (Legacy Cascade) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Corona particle system (Legacy Cascade)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CoronaNiagara_MetaData[] = {
		{ "Category", "Corona" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Corona VFX (Niagara) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Corona VFX (Niagara)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BaseLightIntensity_MetaData[] = {
		{ "Category", "Lighting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Base light intensity (will be scaled by star luminosity) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Base light intensity (will be scaled by star luminosity)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LightColor_MetaData[] = {
		{ "Category", "Lighting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Light color (will be adjusted by star temperature) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Light color (will be adjusted by star temperature)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttenuationRadius_MetaData[] = {
		{ "Category", "Lighting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Attenuation radius for directional light */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Attenuation radius for directional light" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BloomIntensity_MetaData[] = {
		{ "Category", "PostProcess" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Bloom intensity */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Bloom intensity" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FSoftClassPropertyParams NewProp_ActorClass;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ActorScale;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_CoronaParticles;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_CoronaNiagara;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BaseLightIntensity;
	static const UECodeGen_Private::FStructPropertyParams NewProp_LightColor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AttenuationRadius;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BloomIntensity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FStarVisualRow>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FSoftClassPropertyParams Z_Construct_UScriptStruct_FStarVisualRow_Statics::NewProp_ActorClass = { "ActorClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftClass, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStarVisualRow, ActorClass), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActorClass_MetaData), NewProp_ActorClass_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FStarVisualRow_Statics::NewProp_ActorScale = { "ActorScale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStarVisualRow, ActorScale), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActorScale_MetaData), NewProp_ActorScale_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FStarVisualRow_Statics::NewProp_CoronaParticles = { "CoronaParticles", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStarVisualRow, CoronaParticles), Z_Construct_UClass_UParticleSystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CoronaParticles_MetaData), NewProp_CoronaParticles_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FStarVisualRow_Statics::NewProp_CoronaNiagara = { "CoronaNiagara", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStarVisualRow, CoronaNiagara), Z_Construct_UClass_UNiagaraSystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CoronaNiagara_MetaData), NewProp_CoronaNiagara_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FStarVisualRow_Statics::NewProp_BaseLightIntensity = { "BaseLightIntensity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStarVisualRow, BaseLightIntensity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BaseLightIntensity_MetaData), NewProp_BaseLightIntensity_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FStarVisualRow_Statics::NewProp_LightColor = { "LightColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStarVisualRow, LightColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LightColor_MetaData), NewProp_LightColor_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FStarVisualRow_Statics::NewProp_AttenuationRadius = { "AttenuationRadius", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStarVisualRow, AttenuationRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttenuationRadius_MetaData), NewProp_AttenuationRadius_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FStarVisualRow_Statics::NewProp_BloomIntensity = { "BloomIntensity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStarVisualRow, BloomIntensity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BloomIntensity_MetaData), NewProp_BloomIntensity_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FStarVisualRow_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStarVisualRow_Statics::NewProp_ActorClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStarVisualRow_Statics::NewProp_ActorScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStarVisualRow_Statics::NewProp_CoronaParticles,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStarVisualRow_Statics::NewProp_CoronaNiagara,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStarVisualRow_Statics::NewProp_BaseLightIntensity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStarVisualRow_Statics::NewProp_LightColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStarVisualRow_Statics::NewProp_AttenuationRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStarVisualRow_Statics::NewProp_BloomIntensity,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStarVisualRow_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FStarVisualRow_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	Z_Construct_UScriptStruct_FTableRowBase,
	&NewStructOps,
	"StarVisualRow",
	Z_Construct_UScriptStruct_FStarVisualRow_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStarVisualRow_Statics::PropPointers),
	sizeof(FStarVisualRow),
	alignof(FStarVisualRow),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStarVisualRow_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FStarVisualRow_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FStarVisualRow()
{
	if (!Z_Registration_Info_UScriptStruct_FStarVisualRow.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FStarVisualRow.InnerSingleton, Z_Construct_UScriptStruct_FStarVisualRow_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FStarVisualRow.InnerSingleton;
}
// ********** End ScriptStruct FStarVisualRow ******************************************************

// ********** Begin ScriptStruct FStationVisualRow *************************************************
static_assert(std::is_polymorphic<FStationVisualRow>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FStationVisualRow cannot be polymorphic unless super FTableRowBase is polymorphic");
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FStationVisualRow;
class UScriptStruct* FStationVisualRow::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FStationVisualRow.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FStationVisualRow.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FStationVisualRow, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("StationVisualRow"));
	}
	return Z_Registration_Info_UScriptStruct_FStationVisualRow.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FStationVisualRow_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Visual configuration for space stations\n * Supports modular construction with faction customization\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Visual configuration for space stations\nSupports modular construction with faction customization" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActorClass_MetaData[] = {
		{ "Category", "Visual" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Station blueprint actor */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Station blueprint actor" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActorScale_MetaData[] = {
		{ "Category", "Visual" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Scale applied to the station actor */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Scale applied to the station actor" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LightsPattern_MetaData[] = {
		{ "Category", "Lighting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Navigation lights pattern (Niagara or material) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Navigation lights pattern (Niagara or material)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DockingLightColor_MetaData[] = {
		{ "Category", "Lighting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Docking bay lights */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Docking bay lights" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScaleRange_MetaData[] = {
		{ "Category", "Variation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Scale variation range (min-max) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Scale variation range (min-max)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FSoftClassPropertyParams NewProp_ActorClass;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ActorScale;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_LightsPattern;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DockingLightColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ScaleRange;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FStationVisualRow>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FSoftClassPropertyParams Z_Construct_UScriptStruct_FStationVisualRow_Statics::NewProp_ActorClass = { "ActorClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftClass, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStationVisualRow, ActorClass), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActorClass_MetaData), NewProp_ActorClass_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FStationVisualRow_Statics::NewProp_ActorScale = { "ActorScale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStationVisualRow, ActorScale), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActorScale_MetaData), NewProp_ActorScale_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FStationVisualRow_Statics::NewProp_LightsPattern = { "LightsPattern", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStationVisualRow, LightsPattern), Z_Construct_UClass_UNiagaraSystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LightsPattern_MetaData), NewProp_LightsPattern_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FStationVisualRow_Statics::NewProp_DockingLightColor = { "DockingLightColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStationVisualRow, DockingLightColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DockingLightColor_MetaData), NewProp_DockingLightColor_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FStationVisualRow_Statics::NewProp_ScaleRange = { "ScaleRange", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStationVisualRow, ScaleRange), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScaleRange_MetaData), NewProp_ScaleRange_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FStationVisualRow_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStationVisualRow_Statics::NewProp_ActorClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStationVisualRow_Statics::NewProp_ActorScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStationVisualRow_Statics::NewProp_LightsPattern,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStationVisualRow_Statics::NewProp_DockingLightColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStationVisualRow_Statics::NewProp_ScaleRange,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStationVisualRow_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FStationVisualRow_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	Z_Construct_UScriptStruct_FTableRowBase,
	&NewStructOps,
	"StationVisualRow",
	Z_Construct_UScriptStruct_FStationVisualRow_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStationVisualRow_Statics::PropPointers),
	sizeof(FStationVisualRow),
	alignof(FStationVisualRow),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStationVisualRow_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FStationVisualRow_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FStationVisualRow()
{
	if (!Z_Registration_Info_UScriptStruct_FStationVisualRow.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FStationVisualRow.InnerSingleton, Z_Construct_UScriptStruct_FStationVisualRow_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FStationVisualRow.InnerSingleton;
}
// ********** End ScriptStruct FStationVisualRow ***************************************************

// ********** Begin ScriptStruct FStargateVisualRow ************************************************
static_assert(std::is_polymorphic<FStargateVisualRow>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FStargateVisualRow cannot be polymorphic unless super FTableRowBase is polymorphic");
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FStargateVisualRow;
class UScriptStruct* FStargateVisualRow::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FStargateVisualRow.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FStargateVisualRow.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FStargateVisualRow, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("StargateVisualRow"));
	}
	return Z_Registration_Info_UScriptStruct_FStargateVisualRow.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FStargateVisualRow_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Visual configuration for stargates\n * Defines gate structure and portal VFX\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Visual configuration for stargates\nDefines gate structure and portal VFX" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActorClass_MetaData[] = {
		{ "Category", "Visual" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Stargate blueprint actor */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Stargate blueprint actor" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActorScale_MetaData[] = {
		{ "Category", "Visual" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Scale applied to the stargate actor */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Scale applied to the stargate actor" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PortalVFX_MetaData[] = {
		{ "Category", "Portal" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Portal VFX (wormhole effect) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Portal VFX (wormhole effect)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DestinationFX_MetaData[] = {
		{ "Category", "Visual" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Destination marker VFX */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Destination marker VFX" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActivationSound_MetaData[] = {
		{ "Category", "Audio" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Gate activation sound */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Gate activation sound" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AmbientSound_MetaData[] = {
		{ "Category", "Audio" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Ambient hum sound */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ambient hum sound" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RingRotationSpeed_MetaData[] = {
		{ "Category", "Animation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Ring rotation speed (for spinning gates) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ring rotation speed (for spinning gates)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GateLightColor_MetaData[] = {
		{ "Category", "Lighting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Light color for gate */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Light color for gate" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FSoftClassPropertyParams NewProp_ActorClass;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ActorScale;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_PortalVFX;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_DestinationFX;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_ActivationSound;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_AmbientSound;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RingRotationSpeed;
	static const UECodeGen_Private::FStructPropertyParams NewProp_GateLightColor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FStargateVisualRow>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FSoftClassPropertyParams Z_Construct_UScriptStruct_FStargateVisualRow_Statics::NewProp_ActorClass = { "ActorClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftClass, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStargateVisualRow, ActorClass), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActorClass_MetaData), NewProp_ActorClass_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FStargateVisualRow_Statics::NewProp_ActorScale = { "ActorScale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStargateVisualRow, ActorScale), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActorScale_MetaData), NewProp_ActorScale_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FStargateVisualRow_Statics::NewProp_PortalVFX = { "PortalVFX", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStargateVisualRow, PortalVFX), Z_Construct_UClass_UNiagaraSystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PortalVFX_MetaData), NewProp_PortalVFX_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FStargateVisualRow_Statics::NewProp_DestinationFX = { "DestinationFX", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStargateVisualRow, DestinationFX), Z_Construct_UClass_UNiagaraSystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DestinationFX_MetaData), NewProp_DestinationFX_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FStargateVisualRow_Statics::NewProp_ActivationSound = { "ActivationSound", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStargateVisualRow, ActivationSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActivationSound_MetaData), NewProp_ActivationSound_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FStargateVisualRow_Statics::NewProp_AmbientSound = { "AmbientSound", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStargateVisualRow, AmbientSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AmbientSound_MetaData), NewProp_AmbientSound_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FStargateVisualRow_Statics::NewProp_RingRotationSpeed = { "RingRotationSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStargateVisualRow, RingRotationSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RingRotationSpeed_MetaData), NewProp_RingRotationSpeed_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FStargateVisualRow_Statics::NewProp_GateLightColor = { "GateLightColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStargateVisualRow, GateLightColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GateLightColor_MetaData), NewProp_GateLightColor_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FStargateVisualRow_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStargateVisualRow_Statics::NewProp_ActorClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStargateVisualRow_Statics::NewProp_ActorScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStargateVisualRow_Statics::NewProp_PortalVFX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStargateVisualRow_Statics::NewProp_DestinationFX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStargateVisualRow_Statics::NewProp_ActivationSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStargateVisualRow_Statics::NewProp_AmbientSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStargateVisualRow_Statics::NewProp_RingRotationSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStargateVisualRow_Statics::NewProp_GateLightColor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStargateVisualRow_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FStargateVisualRow_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	Z_Construct_UScriptStruct_FTableRowBase,
	&NewStructOps,
	"StargateVisualRow",
	Z_Construct_UScriptStruct_FStargateVisualRow_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStargateVisualRow_Statics::PropPointers),
	sizeof(FStargateVisualRow),
	alignof(FStargateVisualRow),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStargateVisualRow_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FStargateVisualRow_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FStargateVisualRow()
{
	if (!Z_Registration_Info_UScriptStruct_FStargateVisualRow.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FStargateVisualRow.InnerSingleton, Z_Construct_UScriptStruct_FStargateVisualRow_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FStargateVisualRow.InnerSingleton;
}
// ********** End ScriptStruct FStargateVisualRow **************************************************

// ********** Begin ScriptStruct FAsteroidBeltVisualRow ********************************************
static_assert(std::is_polymorphic<FAsteroidBeltVisualRow>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FAsteroidBeltVisualRow cannot be polymorphic unless super FTableRowBase is polymorphic");
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FAsteroidBeltVisualRow;
class UScriptStruct* FAsteroidBeltVisualRow::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FAsteroidBeltVisualRow.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FAsteroidBeltVisualRow.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAsteroidBeltVisualRow, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("AsteroidBeltVisualRow"));
	}
	return Z_Registration_Info_UScriptStruct_FAsteroidBeltVisualRow.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FAsteroidBeltVisualRow_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Visual configuration for asteroid belts\n * Defines individual asteroid meshes and environmental effects\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Visual configuration for asteroid belts\nDefines individual asteroid meshes and environmental effects" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActorClass_MetaData[] = {
		{ "Category", "Visual" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Asteroid belt blueprint actor */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Asteroid belt blueprint actor" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActorScale_MetaData[] = {
		{ "Category", "Visual" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Scale applied to the asteroid belt actor */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Scale applied to the asteroid belt actor" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DustCloudVFX_MetaData[] = {
		{ "Category", "Environment" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Cloud/Dust particle effects (Niagara) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cloud/Dust particle effects (Niagara)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AmbientSound_MetaData[] = {
		{ "Category", "Audio" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Ambient audio loop for the belt */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ambient audio loop for the belt" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DensityMultiplier_MetaData[] = {
		{ "Category", "Distribution" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Density multiplier for asteroid distribution (0.1 to 2.0) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Density multiplier for asteroid distribution (0.1 to 2.0)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AsteroidScaleRange_MetaData[] = {
		{ "Category", "Distribution" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Scale range for asteroids (min-max) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Scale range for asteroids (min-max)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MineralTint_MetaData[] = {
		{ "Category", "Visual" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Color tint for mineral-rich asteroids */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Color tint for mineral-rich asteroids" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FSoftClassPropertyParams NewProp_ActorClass;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ActorScale;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_DustCloudVFX;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_AmbientSound;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DensityMultiplier;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AsteroidScaleRange;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MineralTint;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAsteroidBeltVisualRow>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FSoftClassPropertyParams Z_Construct_UScriptStruct_FAsteroidBeltVisualRow_Statics::NewProp_ActorClass = { "ActorClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftClass, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAsteroidBeltVisualRow, ActorClass), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActorClass_MetaData), NewProp_ActorClass_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAsteroidBeltVisualRow_Statics::NewProp_ActorScale = { "ActorScale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAsteroidBeltVisualRow, ActorScale), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActorScale_MetaData), NewProp_ActorScale_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FAsteroidBeltVisualRow_Statics::NewProp_DustCloudVFX = { "DustCloudVFX", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAsteroidBeltVisualRow, DustCloudVFX), Z_Construct_UClass_UNiagaraSystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DustCloudVFX_MetaData), NewProp_DustCloudVFX_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FAsteroidBeltVisualRow_Statics::NewProp_AmbientSound = { "AmbientSound", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAsteroidBeltVisualRow, AmbientSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AmbientSound_MetaData), NewProp_AmbientSound_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAsteroidBeltVisualRow_Statics::NewProp_DensityMultiplier = { "DensityMultiplier", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAsteroidBeltVisualRow, DensityMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DensityMultiplier_MetaData), NewProp_DensityMultiplier_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAsteroidBeltVisualRow_Statics::NewProp_AsteroidScaleRange = { "AsteroidScaleRange", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAsteroidBeltVisualRow, AsteroidScaleRange), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AsteroidScaleRange_MetaData), NewProp_AsteroidScaleRange_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAsteroidBeltVisualRow_Statics::NewProp_MineralTint = { "MineralTint", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAsteroidBeltVisualRow, MineralTint), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MineralTint_MetaData), NewProp_MineralTint_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAsteroidBeltVisualRow_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAsteroidBeltVisualRow_Statics::NewProp_ActorClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAsteroidBeltVisualRow_Statics::NewProp_ActorScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAsteroidBeltVisualRow_Statics::NewProp_DustCloudVFX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAsteroidBeltVisualRow_Statics::NewProp_AmbientSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAsteroidBeltVisualRow_Statics::NewProp_DensityMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAsteroidBeltVisualRow_Statics::NewProp_AsteroidScaleRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAsteroidBeltVisualRow_Statics::NewProp_MineralTint,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAsteroidBeltVisualRow_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAsteroidBeltVisualRow_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	Z_Construct_UScriptStruct_FTableRowBase,
	&NewStructOps,
	"AsteroidBeltVisualRow",
	Z_Construct_UScriptStruct_FAsteroidBeltVisualRow_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAsteroidBeltVisualRow_Statics::PropPointers),
	sizeof(FAsteroidBeltVisualRow),
	alignof(FAsteroidBeltVisualRow),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAsteroidBeltVisualRow_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAsteroidBeltVisualRow_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FAsteroidBeltVisualRow()
{
	if (!Z_Registration_Info_UScriptStruct_FAsteroidBeltVisualRow.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FAsteroidBeltVisualRow.InnerSingleton, Z_Construct_UScriptStruct_FAsteroidBeltVisualRow_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FAsteroidBeltVisualRow.InnerSingleton;
}
// ********** End ScriptStruct FAsteroidBeltVisualRow **********************************************

// ********** Begin ScriptStruct FAnomalyVisualRow *************************************************
static_assert(std::is_polymorphic<FAnomalyVisualRow>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FAnomalyVisualRow cannot be polymorphic unless super FTableRowBase is polymorphic");
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FAnomalyVisualRow;
class UScriptStruct* FAnomalyVisualRow::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FAnomalyVisualRow.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FAnomalyVisualRow.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAnomalyVisualRow, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("AnomalyVisualRow"));
	}
	return Z_Registration_Info_UScriptStruct_FAnomalyVisualRow.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FAnomalyVisualRow_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Visual configuration for anomalies\n * Defines site visuals based on anomaly type and difficulty\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Visual configuration for anomalies\nDefines site visuals based on anomaly type and difficulty" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActorClass_MetaData[] = {
		{ "Category", "Structure" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Anomaly blueprint actor */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Anomaly blueprint actor" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActorScale_MetaData[] = {
		{ "Category", "Structure" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Scale applied to the anomaly actor */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Scale applied to the anomaly actor" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SignatureVFX_MetaData[] = {
		{ "Category", "Scanning" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Scanning signature VFX (visible when scanned) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Scanning signature VFX (visible when scanned)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TypeSpecificVFX_MetaData[] = {
		{ "Category", "TypeEffects" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Type-specific particle effects (combat beams, data streams, gas clouds, etc.) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Type-specific particle effects (combat beams, data streams, gas clouds, etc.)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AmbientSound_MetaData[] = {
		{ "Category", "Audio" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Ambient sound for the anomaly */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ambient sound for the anomaly" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WarningSound_MetaData[] = {
		{ "Category", "Audio" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Warning sound when entering danger zone */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Warning sound when entering danger zone" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SignatureColor_MetaData[] = {
		{ "Category", "Visual" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Glow color for anomaly signature */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Glow color for anomaly signature" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DetectionRadiusMultiplier_MetaData[] = {
		{ "Category", "Scanning" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Detection radius multiplier */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Detection radius multiplier" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FSoftClassPropertyParams NewProp_ActorClass;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ActorScale;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_SignatureVFX;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_TypeSpecificVFX;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_AmbientSound;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_WarningSound;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SignatureColor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DetectionRadiusMultiplier;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAnomalyVisualRow>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FSoftClassPropertyParams Z_Construct_UScriptStruct_FAnomalyVisualRow_Statics::NewProp_ActorClass = { "ActorClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftClass, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnomalyVisualRow, ActorClass), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActorClass_MetaData), NewProp_ActorClass_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnomalyVisualRow_Statics::NewProp_ActorScale = { "ActorScale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnomalyVisualRow, ActorScale), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActorScale_MetaData), NewProp_ActorScale_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FAnomalyVisualRow_Statics::NewProp_SignatureVFX = { "SignatureVFX", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnomalyVisualRow, SignatureVFX), Z_Construct_UClass_UNiagaraSystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SignatureVFX_MetaData), NewProp_SignatureVFX_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FAnomalyVisualRow_Statics::NewProp_TypeSpecificVFX = { "TypeSpecificVFX", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnomalyVisualRow, TypeSpecificVFX), Z_Construct_UClass_UNiagaraSystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TypeSpecificVFX_MetaData), NewProp_TypeSpecificVFX_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FAnomalyVisualRow_Statics::NewProp_AmbientSound = { "AmbientSound", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnomalyVisualRow, AmbientSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AmbientSound_MetaData), NewProp_AmbientSound_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FAnomalyVisualRow_Statics::NewProp_WarningSound = { "WarningSound", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnomalyVisualRow, WarningSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WarningSound_MetaData), NewProp_WarningSound_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAnomalyVisualRow_Statics::NewProp_SignatureColor = { "SignatureColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnomalyVisualRow, SignatureColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SignatureColor_MetaData), NewProp_SignatureColor_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnomalyVisualRow_Statics::NewProp_DetectionRadiusMultiplier = { "DetectionRadiusMultiplier", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnomalyVisualRow, DetectionRadiusMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DetectionRadiusMultiplier_MetaData), NewProp_DetectionRadiusMultiplier_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAnomalyVisualRow_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnomalyVisualRow_Statics::NewProp_ActorClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnomalyVisualRow_Statics::NewProp_ActorScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnomalyVisualRow_Statics::NewProp_SignatureVFX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnomalyVisualRow_Statics::NewProp_TypeSpecificVFX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnomalyVisualRow_Statics::NewProp_AmbientSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnomalyVisualRow_Statics::NewProp_WarningSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnomalyVisualRow_Statics::NewProp_SignatureColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnomalyVisualRow_Statics::NewProp_DetectionRadiusMultiplier,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnomalyVisualRow_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAnomalyVisualRow_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	Z_Construct_UScriptStruct_FTableRowBase,
	&NewStructOps,
	"AnomalyVisualRow",
	Z_Construct_UScriptStruct_FAnomalyVisualRow_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnomalyVisualRow_Statics::PropPointers),
	sizeof(FAnomalyVisualRow),
	alignof(FAnomalyVisualRow),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnomalyVisualRow_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAnomalyVisualRow_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FAnomalyVisualRow()
{
	if (!Z_Registration_Info_UScriptStruct_FAnomalyVisualRow.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FAnomalyVisualRow.InnerSingleton, Z_Construct_UScriptStruct_FAnomalyVisualRow_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FAnomalyVisualRow.InnerSingleton;
}
// ********** End ScriptStruct FAnomalyVisualRow ***************************************************

// ********** Begin ScriptStruct FWormholeVisualRow ************************************************
static_assert(std::is_polymorphic<FWormholeVisualRow>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FWormholeVisualRow cannot be polymorphic unless super FTableRowBase is polymorphic");
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FWormholeVisualRow;
class UScriptStruct* FWormholeVisualRow::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FWormholeVisualRow.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FWormholeVisualRow.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FWormholeVisualRow, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("WormholeVisualRow"));
	}
	return Z_Registration_Info_UScriptStruct_FWormholeVisualRow.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FWormholeVisualRow_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Visual configuration for wormholes\n * Defines unique effects and distortions for wormhole entrances\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Visual configuration for wormholes\nDefines unique effects and distortions for wormhole entrances" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActorClass_MetaData[] = {
		{ "Category", "Structure" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Wormhole blueprint actor */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Wormhole blueprint actor" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActorScale_MetaData[] = {
		{ "Category", "Structure" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Scale applied to the wormhole actor */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Scale applied to the wormhole actor" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WormholeVFX_MetaData[] = {
		{ "Category", "Portal" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Main wormhole VFX (event horizon, spatial distortion) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Main wormhole VFX (event horizon, spatial distortion)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EntranceSound_MetaData[] = {
		{ "Category", "Audio" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Entrance activation sound */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Entrance activation sound" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExitSound_MetaData[] = {
		{ "Category", "Audio" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Exit/jump sound */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Exit/jump sound" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AmbientSound_MetaData[] = {
		{ "Category", "Audio" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Ambient hum/rumble loop */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ambient hum/rumble loop" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BaseColor_MetaData[] = {
		{ "Category", "Visual" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Base color for the wormhole (will be modified by TargetSystemId) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Base color for the wormhole (will be modified by TargetSystemId)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InstabilityVFX_MetaData[] = {
		{ "Category", "Portal" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Instability VFX (for unstable wormholes) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Instability VFX (for unstable wormholes)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DistortionIntensity_MetaData[] = {
		{ "Category", "Distortion" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Intensity of spatial distortion (0.0 to 1.0) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesWorldVisualTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Intensity of spatial distortion (0.0 to 1.0)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FSoftClassPropertyParams NewProp_ActorClass;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ActorScale;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_WormholeVFX;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_EntranceSound;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_ExitSound;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_AmbientSound;
	static const UECodeGen_Private::FStructPropertyParams NewProp_BaseColor;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_InstabilityVFX;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DistortionIntensity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FWormholeVisualRow>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FSoftClassPropertyParams Z_Construct_UScriptStruct_FWormholeVisualRow_Statics::NewProp_ActorClass = { "ActorClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftClass, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWormholeVisualRow, ActorClass), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActorClass_MetaData), NewProp_ActorClass_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FWormholeVisualRow_Statics::NewProp_ActorScale = { "ActorScale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWormholeVisualRow, ActorScale), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActorScale_MetaData), NewProp_ActorScale_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FWormholeVisualRow_Statics::NewProp_WormholeVFX = { "WormholeVFX", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWormholeVisualRow, WormholeVFX), Z_Construct_UClass_UNiagaraSystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WormholeVFX_MetaData), NewProp_WormholeVFX_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FWormholeVisualRow_Statics::NewProp_EntranceSound = { "EntranceSound", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWormholeVisualRow, EntranceSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EntranceSound_MetaData), NewProp_EntranceSound_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FWormholeVisualRow_Statics::NewProp_ExitSound = { "ExitSound", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWormholeVisualRow, ExitSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExitSound_MetaData), NewProp_ExitSound_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FWormholeVisualRow_Statics::NewProp_AmbientSound = { "AmbientSound", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWormholeVisualRow, AmbientSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AmbientSound_MetaData), NewProp_AmbientSound_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FWormholeVisualRow_Statics::NewProp_BaseColor = { "BaseColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWormholeVisualRow, BaseColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BaseColor_MetaData), NewProp_BaseColor_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FWormholeVisualRow_Statics::NewProp_InstabilityVFX = { "InstabilityVFX", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWormholeVisualRow, InstabilityVFX), Z_Construct_UClass_UNiagaraSystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InstabilityVFX_MetaData), NewProp_InstabilityVFX_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FWormholeVisualRow_Statics::NewProp_DistortionIntensity = { "DistortionIntensity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWormholeVisualRow, DistortionIntensity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DistortionIntensity_MetaData), NewProp_DistortionIntensity_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FWormholeVisualRow_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWormholeVisualRow_Statics::NewProp_ActorClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWormholeVisualRow_Statics::NewProp_ActorScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWormholeVisualRow_Statics::NewProp_WormholeVFX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWormholeVisualRow_Statics::NewProp_EntranceSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWormholeVisualRow_Statics::NewProp_ExitSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWormholeVisualRow_Statics::NewProp_AmbientSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWormholeVisualRow_Statics::NewProp_BaseColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWormholeVisualRow_Statics::NewProp_InstabilityVFX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWormholeVisualRow_Statics::NewProp_DistortionIntensity,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWormholeVisualRow_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FWormholeVisualRow_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	Z_Construct_UScriptStruct_FTableRowBase,
	&NewStructOps,
	"WormholeVisualRow",
	Z_Construct_UScriptStruct_FWormholeVisualRow_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWormholeVisualRow_Statics::PropPointers),
	sizeof(FWormholeVisualRow),
	alignof(FWormholeVisualRow),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWormholeVisualRow_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FWormholeVisualRow_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FWormholeVisualRow()
{
	if (!Z_Registration_Info_UScriptStruct_FWormholeVisualRow.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FWormholeVisualRow.InnerSingleton, Z_Construct_UScriptStruct_FWormholeVisualRow_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FWormholeVisualRow.InnerSingleton;
}
// ********** End ScriptStruct FWormholeVisualRow **************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Types_EchoesWorldVisualTypes_h__Script_Echoes_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FPlanetVisualRow::StaticStruct, Z_Construct_UScriptStruct_FPlanetVisualRow_Statics::NewStructOps, TEXT("PlanetVisualRow"), &Z_Registration_Info_UScriptStruct_FPlanetVisualRow, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPlanetVisualRow), 3120595805U) },
		{ FStarVisualRow::StaticStruct, Z_Construct_UScriptStruct_FStarVisualRow_Statics::NewStructOps, TEXT("StarVisualRow"), &Z_Registration_Info_UScriptStruct_FStarVisualRow, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FStarVisualRow), 3346617476U) },
		{ FStationVisualRow::StaticStruct, Z_Construct_UScriptStruct_FStationVisualRow_Statics::NewStructOps, TEXT("StationVisualRow"), &Z_Registration_Info_UScriptStruct_FStationVisualRow, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FStationVisualRow), 3921162257U) },
		{ FStargateVisualRow::StaticStruct, Z_Construct_UScriptStruct_FStargateVisualRow_Statics::NewStructOps, TEXT("StargateVisualRow"), &Z_Registration_Info_UScriptStruct_FStargateVisualRow, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FStargateVisualRow), 3791110868U) },
		{ FAsteroidBeltVisualRow::StaticStruct, Z_Construct_UScriptStruct_FAsteroidBeltVisualRow_Statics::NewStructOps, TEXT("AsteroidBeltVisualRow"), &Z_Registration_Info_UScriptStruct_FAsteroidBeltVisualRow, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAsteroidBeltVisualRow), 3102877830U) },
		{ FAnomalyVisualRow::StaticStruct, Z_Construct_UScriptStruct_FAnomalyVisualRow_Statics::NewStructOps, TEXT("AnomalyVisualRow"), &Z_Registration_Info_UScriptStruct_FAnomalyVisualRow, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAnomalyVisualRow), 1127289124U) },
		{ FWormholeVisualRow::StaticStruct, Z_Construct_UScriptStruct_FWormholeVisualRow_Statics::NewStructOps, TEXT("WormholeVisualRow"), &Z_Registration_Info_UScriptStruct_FWormholeVisualRow, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FWormholeVisualRow), 429817243U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Types_EchoesWorldVisualTypes_h__Script_Echoes_3699972880(TEXT("/Script/Echoes"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Types_EchoesWorldVisualTypes_h__Script_Echoes_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Types_EchoesWorldVisualTypes_h__Script_Echoes_Statics::ScriptStructInfo),
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
