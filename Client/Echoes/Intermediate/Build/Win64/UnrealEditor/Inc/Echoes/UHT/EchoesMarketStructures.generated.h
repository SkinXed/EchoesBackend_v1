// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Common/Structures/EchoesMarketStructures.h"

#ifdef ECHOES_EchoesMarketStructures_generated_h
#error "EchoesMarketStructures.generated.h already included, missing '#pragma once' in EchoesMarketStructures.h"
#endif
#define ECHOES_EchoesMarketStructures_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FMarketOrderDto ***************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Structures_EchoesMarketStructures_h_15_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FMarketOrderDto_Statics; \
	ECHOES_API static class UScriptStruct* StaticStruct();


struct FMarketOrderDto;
// ********** End ScriptStruct FMarketOrderDto *****************************************************

// ********** Begin ScriptStruct FMarketFilter *****************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Structures_EchoesMarketStructures_h_71_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FMarketFilter_Statics; \
	ECHOES_API static class UScriptStruct* StaticStruct();


struct FMarketFilter;
// ********** End ScriptStruct FMarketFilter *******************************************************

// ********** Begin ScriptStruct FMarketTradeResult ************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Structures_EchoesMarketStructures_h_93_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FMarketTradeResult_Statics; \
	ECHOES_API static class UScriptStruct* StaticStruct();


struct FMarketTradeResult;
// ********** End ScriptStruct FMarketTradeResult **************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Structures_EchoesMarketStructures_h

// ********** Begin Enum EMarketTransactionState ***************************************************
#define FOREACH_ENUM_EMARKETTRANSACTIONSTATE(op) \
	op(EMarketTransactionState::Idle) \
	op(EMarketTransactionState::InFlight) \
	op(EMarketTransactionState::UnknownState) 

enum class EMarketTransactionState : uint8;
template<> struct TIsUEnumClass<EMarketTransactionState> { enum { Value = true }; };
template<> ECHOES_API UEnum* StaticEnum<EMarketTransactionState>();
// ********** End Enum EMarketTransactionState *****************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
