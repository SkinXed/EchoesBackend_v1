// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Common/Types/EchoesGameState.h"

#ifdef ECHOES_EchoesGameState_generated_h
#error "EchoesGameState.generated.h already included, missing '#pragma once' in EchoesGameState.h"
#endif
#define ECHOES_EchoesGameState_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FStatModifier *****************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Types_EchoesGameState_h_85_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FStatModifier_Statics; \
	ECHOES_API static class UScriptStruct* StaticStruct();


struct FStatModifier;
// ********** End ScriptStruct FStatModifier *******************************************************

// ********** Begin ScriptStruct FModuleAmmoData ***************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Types_EchoesGameState_h_116_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FModuleAmmoData_Statics; \
	ECHOES_API static class UScriptStruct* StaticStruct();


struct FModuleAmmoData;
// ********** End ScriptStruct FModuleAmmoData *****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Types_EchoesGameState_h

// ********** Begin Enum ENetworkGameState *********************************************************
#define FOREACH_ENUM_ENETWORKGAMESTATE(op) \
	op(ENetworkGameState::Unknown) \
	op(ENetworkGameState::InHangar) \
	op(ENetworkGameState::InSpace) \
	op(ENetworkGameState::InWarp) \
	op(ENetworkGameState::Docking) \
	op(ENetworkGameState::Undocking) \
	op(ENetworkGameState::Dead) 

enum class ENetworkGameState : uint8;
template<> struct TIsUEnumClass<ENetworkGameState> { enum { Value = true }; };
template<> ECHOES_API UEnum* StaticEnum<ENetworkGameState>();
// ********** End Enum ENetworkGameState ***********************************************************

// ********** Begin Enum EModuleActivationResult ***************************************************
#define FOREACH_ENUM_EMODULEACTIVATIONRESULT(op) \
	op(EModuleActivationResult::Success) \
	op(EModuleActivationResult::NotEnoughCapacitor) \
	op(EModuleActivationResult::NotEnoughAmmo) \
	op(EModuleActivationResult::InCooldown) \
	op(EModuleActivationResult::OutOfRange) \
	op(EModuleActivationResult::NoTarget) \
	op(EModuleActivationResult::InvalidModule) \
	op(EModuleActivationResult::ModuleDamaged) \
	op(EModuleActivationResult::ModuleOffline) 

enum class EModuleActivationResult : uint8;
template<> struct TIsUEnumClass<EModuleActivationResult> { enum { Value = true }; };
template<> ECHOES_API UEnum* StaticEnum<EModuleActivationResult>();
// ********** End Enum EModuleActivationResult *****************************************************

// ********** Begin Enum EStatModifierType *********************************************************
#define FOREACH_ENUM_ESTATMODIFIERTYPE(op) \
	op(EStatModifierType::ShieldBoost) \
	op(EStatModifierType::ArmorBoost) \
	op(EStatModifierType::StructureBoost) \
	op(EStatModifierType::CapacitorBoost) \
	op(EStatModifierType::DamageBoost) \
	op(EStatModifierType::ROFBoost) \
	op(EStatModifierType::SpeedBoost) \
	op(EStatModifierType::ScanResolutionBoost) \
	op(EStatModifierType::SignatureRadiusReduction) \
	op(EStatModifierType::ResistanceEM) \
	op(EStatModifierType::ResistanceThermal) \
	op(EStatModifierType::ResistanceKinetic) \
	op(EStatModifierType::ResistanceExplosive) 

enum class EStatModifierType : uint8;
template<> struct TIsUEnumClass<EStatModifierType> { enum { Value = true }; };
template<> ECHOES_API UEnum* StaticEnum<EStatModifierType>();
// ********** End Enum EStatModifierType ***********************************************************

// ********** Begin Enum EModifierApplication ******************************************************
#define FOREACH_ENUM_EMODIFIERAPPLICATION(op) \
	op(EModifierApplication::Additive) \
	op(EModifierApplication::Multiplicative) \
	op(EModifierApplication::Percentage) 

enum class EModifierApplication : uint8;
template<> struct TIsUEnumClass<EModifierApplication> { enum { Value = true }; };
template<> ECHOES_API UEnum* StaticEnum<EModifierApplication>();
// ********** End Enum EModifierApplication ********************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
