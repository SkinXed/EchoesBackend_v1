// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Common/Types/EchoesItemDefinitions.h"

#ifdef ECHOES_EchoesItemDefinitions_generated_h
#error "EchoesItemDefinitions.generated.h already included, missing '#pragma once' in EchoesItemDefinitions.h"
#endif
#define ECHOES_EchoesItemDefinitions_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FEchoesItemDefinitionRow ******************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Types_EchoesItemDefinitions_h_89_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FEchoesItemDefinitionRow_Statics; \
	static class UScriptStruct* StaticStruct(); \
	typedef FTableRowBase Super;


struct FEchoesItemDefinitionRow;
// ********** End ScriptStruct FEchoesItemDefinitionRow ********************************************

// ********** Begin ScriptStruct FWeaponAttributesRow **********************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Types_EchoesItemDefinitions_h_237_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FWeaponAttributesRow_Statics; \
	static class UScriptStruct* StaticStruct(); \
	typedef FTableRowBase Super;


struct FWeaponAttributesRow;
// ********** End ScriptStruct FWeaponAttributesRow ************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Types_EchoesItemDefinitions_h

// ********** Begin Enum EEchoesSlotType ***********************************************************
#define FOREACH_ENUM_EECHOESSLOTTYPE(op) \
	op(EEchoesSlotType::High) \
	op(EEchoesSlotType::Mid) \
	op(EEchoesSlotType::Low) \
	op(EEchoesSlotType::Rig) \
	op(EEchoesSlotType::Subsystem) \
	op(EEchoesSlotType::None) 

enum class EEchoesSlotType : uint8;
template<> struct TIsUEnumClass<EEchoesSlotType> { enum { Value = true }; };
template<> ECHOES_API UEnum* StaticEnum<EEchoesSlotType>();
// ********** End Enum EEchoesSlotType *************************************************************

// ********** Begin Enum EEchoesItemCategory *******************************************************
#define FOREACH_ENUM_EECHOESITEMCATEGORY(op) \
	op(EEchoesItemCategory::None) \
	op(EEchoesItemCategory::Ore) \
	op(EEchoesItemCategory::Mineral) \
	op(EEchoesItemCategory::Module) \
	op(EEchoesItemCategory::Ammo) \
	op(EEchoesItemCategory::Ship) \
	op(EEchoesItemCategory::Blueprint) \
	op(EEchoesItemCategory::Component) \
	op(EEchoesItemCategory::Commodity) \
	op(EEchoesItemCategory::Implant) \
	op(EEchoesItemCategory::Skill) \
	op(EEchoesItemCategory::Charge) \
	op(EEchoesItemCategory::Drone) \
	op(EEchoesItemCategory::Fighter) \
	op(EEchoesItemCategory::Structure) \
	op(EEchoesItemCategory::Subsystem) \
	op(EEchoesItemCategory::Rig) 

enum class EEchoesItemCategory : uint8;
template<> struct TIsUEnumClass<EEchoesItemCategory> { enum { Value = true }; };
template<> ECHOES_API UEnum* StaticEnum<EEchoesItemCategory>();
// ********** End Enum EEchoesItemCategory *********************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
