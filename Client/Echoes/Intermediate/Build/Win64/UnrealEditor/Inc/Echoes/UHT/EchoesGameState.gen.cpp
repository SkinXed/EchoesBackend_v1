// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EchoesGameState.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesGameState() {}

// ********** Begin Cross Module References ********************************************************
ECHOES_API UEnum* Z_Construct_UEnum_Echoes_EModifierApplication();
ECHOES_API UEnum* Z_Construct_UEnum_Echoes_EModuleActivationResult();
ECHOES_API UEnum* Z_Construct_UEnum_Echoes_ENetworkGameState();
ECHOES_API UEnum* Z_Construct_UEnum_Echoes_EStatModifierType();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FModuleAmmoData();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FStatModifier();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum ENetworkGameState *********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ENetworkGameState;
static UEnum* ENetworkGameState_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ENetworkGameState.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ENetworkGameState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Echoes_ENetworkGameState, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("ENetworkGameState"));
	}
	return Z_Registration_Info_UEnum_ENetworkGameState.OuterSingleton;
}
template<> ECHOES_API UEnum* StaticEnum<ENetworkGameState>()
{
	return ENetworkGameState_StaticEnum();
}
struct Z_Construct_UEnum_Echoes_ENetworkGameState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Network Game State\n * Represents the current state of the player in the game world\n */" },
#endif
		{ "Dead.DisplayName", "Dead" },
		{ "Dead.Name", "ENetworkGameState::Dead" },
		{ "Docking.DisplayName", "Docking" },
		{ "Docking.Name", "ENetworkGameState::Docking" },
		{ "InHangar.DisplayName", "In Hangar" },
		{ "InHangar.Name", "ENetworkGameState::InHangar" },
		{ "InSpace.DisplayName", "In Space" },
		{ "InSpace.Name", "ENetworkGameState::InSpace" },
		{ "InWarp.DisplayName", "In Warp" },
		{ "InWarp.Name", "ENetworkGameState::InWarp" },
		{ "ModuleRelativePath", "Core/Common/Types/EchoesGameState.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Network Game State\nRepresents the current state of the player in the game world" },
#endif
		{ "Undocking.DisplayName", "Undocking" },
		{ "Undocking.Name", "ENetworkGameState::Undocking" },
		{ "Unknown.DisplayName", "Unknown" },
		{ "Unknown.Name", "ENetworkGameState::Unknown" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ENetworkGameState::Unknown", (int64)ENetworkGameState::Unknown },
		{ "ENetworkGameState::InHangar", (int64)ENetworkGameState::InHangar },
		{ "ENetworkGameState::InSpace", (int64)ENetworkGameState::InSpace },
		{ "ENetworkGameState::InWarp", (int64)ENetworkGameState::InWarp },
		{ "ENetworkGameState::Docking", (int64)ENetworkGameState::Docking },
		{ "ENetworkGameState::Undocking", (int64)ENetworkGameState::Undocking },
		{ "ENetworkGameState::Dead", (int64)ENetworkGameState::Dead },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Echoes_ENetworkGameState_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	"ENetworkGameState",
	"ENetworkGameState",
	Z_Construct_UEnum_Echoes_ENetworkGameState_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_Echoes_ENetworkGameState_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_Echoes_ENetworkGameState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_Echoes_ENetworkGameState_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_Echoes_ENetworkGameState()
{
	if (!Z_Registration_Info_UEnum_ENetworkGameState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ENetworkGameState.InnerSingleton, Z_Construct_UEnum_Echoes_ENetworkGameState_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ENetworkGameState.InnerSingleton;
}
// ********** End Enum ENetworkGameState ***********************************************************

// ********** Begin Enum EModuleActivationResult ***************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EModuleActivationResult;
static UEnum* EModuleActivationResult_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EModuleActivationResult.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EModuleActivationResult.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Echoes_EModuleActivationResult, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("EModuleActivationResult"));
	}
	return Z_Registration_Info_UEnum_EModuleActivationResult.OuterSingleton;
}
template<> ECHOES_API UEnum* StaticEnum<EModuleActivationResult>()
{
	return EModuleActivationResult_StaticEnum();
}
struct Z_Construct_UEnum_Echoes_EModuleActivationResult_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Module Activation State\n * Represents the current activation state of a ship module\n */" },
#endif
		{ "InCooldown.DisplayName", "In Cooldown" },
		{ "InCooldown.Name", "EModuleActivationResult::InCooldown" },
		{ "InvalidModule.DisplayName", "Invalid Module" },
		{ "InvalidModule.Name", "EModuleActivationResult::InvalidModule" },
		{ "ModuleDamaged.DisplayName", "Module Damaged" },
		{ "ModuleDamaged.Name", "EModuleActivationResult::ModuleDamaged" },
		{ "ModuleOffline.DisplayName", "Module Offline" },
		{ "ModuleOffline.Name", "EModuleActivationResult::ModuleOffline" },
		{ "ModuleRelativePath", "Core/Common/Types/EchoesGameState.h" },
		{ "NoTarget.DisplayName", "No Target" },
		{ "NoTarget.Name", "EModuleActivationResult::NoTarget" },
		{ "NotEnoughAmmo.DisplayName", "Not Enough Ammo" },
		{ "NotEnoughAmmo.Name", "EModuleActivationResult::NotEnoughAmmo" },
		{ "NotEnoughCapacitor.DisplayName", "Not Enough Capacitor" },
		{ "NotEnoughCapacitor.Name", "EModuleActivationResult::NotEnoughCapacitor" },
		{ "OutOfRange.DisplayName", "Out Of Range" },
		{ "OutOfRange.Name", "EModuleActivationResult::OutOfRange" },
		{ "Success.DisplayName", "Success" },
		{ "Success.Name", "EModuleActivationResult::Success" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Module Activation State\nRepresents the current activation state of a ship module" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EModuleActivationResult::Success", (int64)EModuleActivationResult::Success },
		{ "EModuleActivationResult::NotEnoughCapacitor", (int64)EModuleActivationResult::NotEnoughCapacitor },
		{ "EModuleActivationResult::NotEnoughAmmo", (int64)EModuleActivationResult::NotEnoughAmmo },
		{ "EModuleActivationResult::InCooldown", (int64)EModuleActivationResult::InCooldown },
		{ "EModuleActivationResult::OutOfRange", (int64)EModuleActivationResult::OutOfRange },
		{ "EModuleActivationResult::NoTarget", (int64)EModuleActivationResult::NoTarget },
		{ "EModuleActivationResult::InvalidModule", (int64)EModuleActivationResult::InvalidModule },
		{ "EModuleActivationResult::ModuleDamaged", (int64)EModuleActivationResult::ModuleDamaged },
		{ "EModuleActivationResult::ModuleOffline", (int64)EModuleActivationResult::ModuleOffline },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Echoes_EModuleActivationResult_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	"EModuleActivationResult",
	"EModuleActivationResult",
	Z_Construct_UEnum_Echoes_EModuleActivationResult_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_Echoes_EModuleActivationResult_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_Echoes_EModuleActivationResult_Statics::Enum_MetaDataParams), Z_Construct_UEnum_Echoes_EModuleActivationResult_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_Echoes_EModuleActivationResult()
{
	if (!Z_Registration_Info_UEnum_EModuleActivationResult.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EModuleActivationResult.InnerSingleton, Z_Construct_UEnum_Echoes_EModuleActivationResult_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EModuleActivationResult.InnerSingleton;
}
// ********** End Enum EModuleActivationResult *****************************************************

// ********** Begin Enum EStatModifierType *********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EStatModifierType;
static UEnum* EStatModifierType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EStatModifierType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EStatModifierType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Echoes_EStatModifierType, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("EStatModifierType"));
	}
	return Z_Registration_Info_UEnum_EStatModifierType.OuterSingleton;
}
template<> ECHOES_API UEnum* StaticEnum<EStatModifierType>()
{
	return EStatModifierType_StaticEnum();
}
struct Z_Construct_UEnum_Echoes_EStatModifierType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "ArmorBoost.DisplayName", "Armor Boost" },
		{ "ArmorBoost.Name", "EStatModifierType::ArmorBoost" },
		{ "BlueprintType", "true" },
		{ "CapacitorBoost.DisplayName", "Capacitor Boost" },
		{ "CapacitorBoost.Name", "EStatModifierType::CapacitorBoost" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Stat Modifier Type\n * Represents different types of stat modifications from modules\n */" },
#endif
		{ "DamageBoost.DisplayName", "Damage Boost" },
		{ "DamageBoost.Name", "EStatModifierType::DamageBoost" },
		{ "ModuleRelativePath", "Core/Common/Types/EchoesGameState.h" },
		{ "ResistanceEM.DisplayName", "EM Resistance" },
		{ "ResistanceEM.Name", "EStatModifierType::ResistanceEM" },
		{ "ResistanceExplosive.DisplayName", "Explosive Resistance" },
		{ "ResistanceExplosive.Name", "EStatModifierType::ResistanceExplosive" },
		{ "ResistanceKinetic.DisplayName", "Kinetic Resistance" },
		{ "ResistanceKinetic.Name", "EStatModifierType::ResistanceKinetic" },
		{ "ResistanceThermal.DisplayName", "Thermal Resistance" },
		{ "ResistanceThermal.Name", "EStatModifierType::ResistanceThermal" },
		{ "ROFBoost.DisplayName", "Rate of Fire Boost" },
		{ "ROFBoost.Name", "EStatModifierType::ROFBoost" },
		{ "ScanResolutionBoost.DisplayName", "Scan Resolution Boost" },
		{ "ScanResolutionBoost.Name", "EStatModifierType::ScanResolutionBoost" },
		{ "ShieldBoost.DisplayName", "Shield Boost" },
		{ "ShieldBoost.Name", "EStatModifierType::ShieldBoost" },
		{ "SignatureRadiusReduction.DisplayName", "Signature Radius Reduction" },
		{ "SignatureRadiusReduction.Name", "EStatModifierType::SignatureRadiusReduction" },
		{ "SpeedBoost.DisplayName", "Speed Boost" },
		{ "SpeedBoost.Name", "EStatModifierType::SpeedBoost" },
		{ "StructureBoost.DisplayName", "Structure Boost" },
		{ "StructureBoost.Name", "EStatModifierType::StructureBoost" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Stat Modifier Type\nRepresents different types of stat modifications from modules" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EStatModifierType::ShieldBoost", (int64)EStatModifierType::ShieldBoost },
		{ "EStatModifierType::ArmorBoost", (int64)EStatModifierType::ArmorBoost },
		{ "EStatModifierType::StructureBoost", (int64)EStatModifierType::StructureBoost },
		{ "EStatModifierType::CapacitorBoost", (int64)EStatModifierType::CapacitorBoost },
		{ "EStatModifierType::DamageBoost", (int64)EStatModifierType::DamageBoost },
		{ "EStatModifierType::ROFBoost", (int64)EStatModifierType::ROFBoost },
		{ "EStatModifierType::SpeedBoost", (int64)EStatModifierType::SpeedBoost },
		{ "EStatModifierType::ScanResolutionBoost", (int64)EStatModifierType::ScanResolutionBoost },
		{ "EStatModifierType::SignatureRadiusReduction", (int64)EStatModifierType::SignatureRadiusReduction },
		{ "EStatModifierType::ResistanceEM", (int64)EStatModifierType::ResistanceEM },
		{ "EStatModifierType::ResistanceThermal", (int64)EStatModifierType::ResistanceThermal },
		{ "EStatModifierType::ResistanceKinetic", (int64)EStatModifierType::ResistanceKinetic },
		{ "EStatModifierType::ResistanceExplosive", (int64)EStatModifierType::ResistanceExplosive },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Echoes_EStatModifierType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	"EStatModifierType",
	"EStatModifierType",
	Z_Construct_UEnum_Echoes_EStatModifierType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_Echoes_EStatModifierType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_Echoes_EStatModifierType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_Echoes_EStatModifierType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_Echoes_EStatModifierType()
{
	if (!Z_Registration_Info_UEnum_EStatModifierType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EStatModifierType.InnerSingleton, Z_Construct_UEnum_Echoes_EStatModifierType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EStatModifierType.InnerSingleton;
}
// ********** End Enum EStatModifierType ***********************************************************

// ********** Begin Enum EModifierApplication ******************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EModifierApplication;
static UEnum* EModifierApplication_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EModifierApplication.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EModifierApplication.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Echoes_EModifierApplication, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("EModifierApplication"));
	}
	return Z_Registration_Info_UEnum_EModifierApplication.OuterSingleton;
}
template<> ECHOES_API UEnum* StaticEnum<EModifierApplication>()
{
	return EModifierApplication_StaticEnum();
}
struct Z_Construct_UEnum_Echoes_EModifierApplication_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Additive.DisplayName", "Additive (+)" },
		{ "Additive.Name", "EModifierApplication::Additive" },
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Stat Modifier Application Type\n * How the modifier should be applied to the base stat\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesGameState.h" },
		{ "Multiplicative.DisplayName", "Multiplicative (\xc3\x97)" },
		{ "Multiplicative.Name", "EModifierApplication::Multiplicative" },
		{ "Percentage.DisplayName", "Percentage (%)" },
		{ "Percentage.Name", "EModifierApplication::Percentage" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Stat Modifier Application Type\nHow the modifier should be applied to the base stat" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EModifierApplication::Additive", (int64)EModifierApplication::Additive },
		{ "EModifierApplication::Multiplicative", (int64)EModifierApplication::Multiplicative },
		{ "EModifierApplication::Percentage", (int64)EModifierApplication::Percentage },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Echoes_EModifierApplication_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	"EModifierApplication",
	"EModifierApplication",
	Z_Construct_UEnum_Echoes_EModifierApplication_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_Echoes_EModifierApplication_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_Echoes_EModifierApplication_Statics::Enum_MetaDataParams), Z_Construct_UEnum_Echoes_EModifierApplication_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_Echoes_EModifierApplication()
{
	if (!Z_Registration_Info_UEnum_EModifierApplication.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EModifierApplication.InnerSingleton, Z_Construct_UEnum_Echoes_EModifierApplication_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EModifierApplication.InnerSingleton;
}
// ********** End Enum EModifierApplication ********************************************************

// ********** Begin ScriptStruct FStatModifier *****************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FStatModifier;
class UScriptStruct* FStatModifier::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FStatModifier.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FStatModifier.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FStatModifier, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("StatModifier"));
	}
	return Z_Registration_Info_UScriptStruct_FStatModifier.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FStatModifier_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Stat Modifier Structure\n * Represents a single stat modification from a module\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesGameState.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Stat Modifier Structure\nRepresents a single stat modification from a module" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ModifierType_MetaData[] = {
		{ "Category", "Modifier" },
		{ "ModuleRelativePath", "Core/Common/Types/EchoesGameState.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ApplicationType_MetaData[] = {
		{ "Category", "Modifier" },
		{ "ModuleRelativePath", "Core/Common/Types/EchoesGameState.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
		{ "Category", "Modifier" },
		{ "ModuleRelativePath", "Core/Common/Types/EchoesGameState.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_ModifierType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ModifierType;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ApplicationType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ApplicationType;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FStatModifier>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FStatModifier_Statics::NewProp_ModifierType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FStatModifier_Statics::NewProp_ModifierType = { "ModifierType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStatModifier, ModifierType), Z_Construct_UEnum_Echoes_EStatModifierType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ModifierType_MetaData), NewProp_ModifierType_MetaData) }; // 2302846609
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FStatModifier_Statics::NewProp_ApplicationType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FStatModifier_Statics::NewProp_ApplicationType = { "ApplicationType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStatModifier, ApplicationType), Z_Construct_UEnum_Echoes_EModifierApplication, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ApplicationType_MetaData), NewProp_ApplicationType_MetaData) }; // 1670281136
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FStatModifier_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStatModifier, Value), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FStatModifier_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStatModifier_Statics::NewProp_ModifierType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStatModifier_Statics::NewProp_ModifierType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStatModifier_Statics::NewProp_ApplicationType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStatModifier_Statics::NewProp_ApplicationType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStatModifier_Statics::NewProp_Value,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStatModifier_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FStatModifier_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"StatModifier",
	Z_Construct_UScriptStruct_FStatModifier_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStatModifier_Statics::PropPointers),
	sizeof(FStatModifier),
	alignof(FStatModifier),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStatModifier_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FStatModifier_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FStatModifier()
{
	if (!Z_Registration_Info_UScriptStruct_FStatModifier.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FStatModifier.InnerSingleton, Z_Construct_UScriptStruct_FStatModifier_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FStatModifier.InnerSingleton;
}
// ********** End ScriptStruct FStatModifier *******************************************************

// ********** Begin ScriptStruct FModuleAmmoData ***************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FModuleAmmoData;
class UScriptStruct* FModuleAmmoData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FModuleAmmoData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FModuleAmmoData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FModuleAmmoData, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("ModuleAmmoData"));
	}
	return Z_Registration_Info_UScriptStruct_FModuleAmmoData.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FModuleAmmoData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Module Ammunition Data\n * Represents ammunition requirements for a module\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Types/EchoesGameState.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Module Ammunition Data\nRepresents ammunition requirements for a module" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AmmoTypeID_MetaData[] = {
		{ "Category", "Ammo" },
		{ "ModuleRelativePath", "Core/Common/Types/EchoesGameState.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AmmoTypeName_MetaData[] = {
		{ "Category", "Ammo" },
		{ "ModuleRelativePath", "Core/Common/Types/EchoesGameState.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentAmmo_MetaData[] = {
		{ "Category", "Ammo" },
		{ "ModuleRelativePath", "Core/Common/Types/EchoesGameState.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxAmmo_MetaData[] = {
		{ "Category", "Ammo" },
		{ "ModuleRelativePath", "Core/Common/Types/EchoesGameState.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AmmoPerShot_MetaData[] = {
		{ "Category", "Ammo" },
		{ "ModuleRelativePath", "Core/Common/Types/EchoesGameState.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_AmmoTypeID;
	static const UECodeGen_Private::FStrPropertyParams NewProp_AmmoTypeName;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentAmmo;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxAmmo;
	static const UECodeGen_Private::FIntPropertyParams NewProp_AmmoPerShot;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FModuleAmmoData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FModuleAmmoData_Statics::NewProp_AmmoTypeID = { "AmmoTypeID", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FModuleAmmoData, AmmoTypeID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AmmoTypeID_MetaData), NewProp_AmmoTypeID_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FModuleAmmoData_Statics::NewProp_AmmoTypeName = { "AmmoTypeName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FModuleAmmoData, AmmoTypeName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AmmoTypeName_MetaData), NewProp_AmmoTypeName_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FModuleAmmoData_Statics::NewProp_CurrentAmmo = { "CurrentAmmo", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FModuleAmmoData, CurrentAmmo), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentAmmo_MetaData), NewProp_CurrentAmmo_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FModuleAmmoData_Statics::NewProp_MaxAmmo = { "MaxAmmo", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FModuleAmmoData, MaxAmmo), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxAmmo_MetaData), NewProp_MaxAmmo_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FModuleAmmoData_Statics::NewProp_AmmoPerShot = { "AmmoPerShot", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FModuleAmmoData, AmmoPerShot), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AmmoPerShot_MetaData), NewProp_AmmoPerShot_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FModuleAmmoData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModuleAmmoData_Statics::NewProp_AmmoTypeID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModuleAmmoData_Statics::NewProp_AmmoTypeName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModuleAmmoData_Statics::NewProp_CurrentAmmo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModuleAmmoData_Statics::NewProp_MaxAmmo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FModuleAmmoData_Statics::NewProp_AmmoPerShot,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModuleAmmoData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FModuleAmmoData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"ModuleAmmoData",
	Z_Construct_UScriptStruct_FModuleAmmoData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModuleAmmoData_Statics::PropPointers),
	sizeof(FModuleAmmoData),
	alignof(FModuleAmmoData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FModuleAmmoData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FModuleAmmoData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FModuleAmmoData()
{
	if (!Z_Registration_Info_UScriptStruct_FModuleAmmoData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FModuleAmmoData.InnerSingleton, Z_Construct_UScriptStruct_FModuleAmmoData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FModuleAmmoData.InnerSingleton;
}
// ********** End ScriptStruct FModuleAmmoData *****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Types_EchoesGameState_h__Script_Echoes_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ ENetworkGameState_StaticEnum, TEXT("ENetworkGameState"), &Z_Registration_Info_UEnum_ENetworkGameState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2499892647U) },
		{ EModuleActivationResult_StaticEnum, TEXT("EModuleActivationResult"), &Z_Registration_Info_UEnum_EModuleActivationResult, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 664261323U) },
		{ EStatModifierType_StaticEnum, TEXT("EStatModifierType"), &Z_Registration_Info_UEnum_EStatModifierType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2302846609U) },
		{ EModifierApplication_StaticEnum, TEXT("EModifierApplication"), &Z_Registration_Info_UEnum_EModifierApplication, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1670281136U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FStatModifier::StaticStruct, Z_Construct_UScriptStruct_FStatModifier_Statics::NewStructOps, TEXT("StatModifier"), &Z_Registration_Info_UScriptStruct_FStatModifier, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FStatModifier), 1593879294U) },
		{ FModuleAmmoData::StaticStruct, Z_Construct_UScriptStruct_FModuleAmmoData_Statics::NewStructOps, TEXT("ModuleAmmoData"), &Z_Registration_Info_UScriptStruct_FModuleAmmoData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FModuleAmmoData), 4266437735U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Types_EchoesGameState_h__Script_Echoes_1514736895(TEXT("/Script/Echoes"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Types_EchoesGameState_h__Script_Echoes_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Types_EchoesGameState_h__Script_Echoes_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Types_EchoesGameState_h__Script_Echoes_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Types_EchoesGameState_h__Script_Echoes_Statics::EnumInfo));
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
