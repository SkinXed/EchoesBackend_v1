// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Common/WormholeActor.h"

#ifdef ECHOES_WormholeActor_generated_h
#error "WormholeActor.generated.h already included, missing '#pragma once' in WormholeActor.h"
#endif
#define ECHOES_WormholeActor_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class AActor;
class UPrimitiveComponent;
struct FGuid;
struct FHitResult;
struct FWormholeVisualRow;

// ********** Begin Class AWormholeActor ***********************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_WormholeActor_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execTriggerCollapse); \
	DECLARE_FUNCTION(execGetStabilityPercentage); \
	DECLARE_FUNCTION(execCanAccommodateShip); \
	DECLARE_FUNCTION(execProcessShipPassage); \
	DECLARE_FUNCTION(execInitiateJump); \
	DECLARE_FUNCTION(execOnTriggerBeginOverlap); \
	DECLARE_FUNCTION(execGetTargetSystemId); \
	DECLARE_FUNCTION(execGetWormholeName); \
	DECLARE_FUNCTION(execGetWormholeId); \
	DECLARE_FUNCTION(execInitializeWormhole);


ECHOES_API UClass* Z_Construct_UClass_AWormholeActor_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_WormholeActor_h_27_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAWormholeActor(); \
	friend struct Z_Construct_UClass_AWormholeActor_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_AWormholeActor_NoRegister(); \
public: \
	DECLARE_CLASS2(AWormholeActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_AWormholeActor_NoRegister) \
	DECLARE_SERIALIZER(AWormholeActor) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		WormholeId=NETFIELD_REP_START, \
		WormholeName, \
		TargetSystemId, \
		MassCapacity, \
		CurrentMassUsed, \
		RemainingLifetime, \
		bIsCollapsing, \
		NETFIELD_REP_END=bIsCollapsing	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_WormholeActor_h_27_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AWormholeActor(AWormholeActor&&) = delete; \
	AWormholeActor(const AWormholeActor&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AWormholeActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AWormholeActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AWormholeActor) \
	NO_API virtual ~AWormholeActor();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_WormholeActor_h_24_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_WormholeActor_h_27_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_WormholeActor_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_WormholeActor_h_27_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_WormholeActor_h_27_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AWormholeActor;

// ********** End Class AWormholeActor *************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_WormholeActor_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
