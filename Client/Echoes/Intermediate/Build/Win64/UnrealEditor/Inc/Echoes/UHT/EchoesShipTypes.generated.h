// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Common/EchoesShipTypes.h"

#ifdef ECHOES_EchoesShipTypes_generated_h
#error "EchoesShipTypes.generated.h already included, missing '#pragma once' in EchoesShipTypes.h"
#endif
#define ECHOES_EchoesShipTypes_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FEchoesShipStats **************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesShipTypes_h_29_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FEchoesShipStats_Statics; \
	ECHOES_API static class UScriptStruct* StaticStruct();


struct FEchoesShipStats;
// ********** End ScriptStruct FEchoesShipStats ****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesShipTypes_h

// ********** Begin Enum EWarpState ****************************************************************
#define FOREACH_ENUM_EWARPSTATE(op) \
	op(EWarpState::Idle) \
	op(EWarpState::Aligning) \
	op(EWarpState::Warping) \
	op(EWarpState::Exiting) 

enum class EWarpState : uint8;
template<> struct TIsUEnumClass<EWarpState> { enum { Value = true }; };
template<> ECHOES_API UEnum* StaticEnum<EWarpState>();
// ********** End Enum EWarpState ******************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
