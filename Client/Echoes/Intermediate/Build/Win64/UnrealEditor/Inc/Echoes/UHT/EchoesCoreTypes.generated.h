// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Common/EchoesCoreTypes.h"

#ifdef ECHOES_EchoesCoreTypes_generated_h
#error "EchoesCoreTypes.generated.h already included, missing '#pragma once' in EchoesCoreTypes.h"
#endif
#define ECHOES_EchoesCoreTypes_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FCosmosDefenseLayer ***********************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesCoreTypes_h_47_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FCosmosDefenseLayer_Statics; \
	ECHOES_API static class UScriptStruct* StaticStruct();


struct FCosmosDefenseLayer;
// ********** End ScriptStruct FCosmosDefenseLayer *************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesCoreTypes_h

// ********** Begin Enum ECosmosDamageType *********************************************************
#define FOREACH_ENUM_ECOSMOSDAMAGETYPE(op) \
	op(ECosmosDamageType::EM) \
	op(ECosmosDamageType::Thermal) \
	op(ECosmosDamageType::Kinetic) \
	op(ECosmosDamageType::Explosive) \
	op(ECosmosDamageType::Omni) 

enum class ECosmosDamageType : uint8;
template<> struct TIsUEnumClass<ECosmosDamageType> { enum { Value = true }; };
template<> ECHOES_API UEnum* StaticEnum<ECosmosDamageType>();
// ********** End Enum ECosmosDamageType ***********************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
