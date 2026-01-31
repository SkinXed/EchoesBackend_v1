// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Common/StargateActor.h"

#ifdef ECHOES_StargateActor_generated_h
#error "StargateActor.generated.h already included, missing '#pragma once' in StargateActor.h"
#endif
#define ECHOES_StargateActor_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class AActor;
class APlayerController;
class UPrimitiveComponent;
struct FGuid;
struct FHitResult;
struct FStargateVisualRow;

// ********** Begin Class AStargateActor ***********************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_StargateActor_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual bool ServerRPC_RequestJump_Validate(APlayerController* ); \
	virtual void ServerRPC_RequestJump_Implementation(APlayerController* PlayerController); \
	DECLARE_FUNCTION(execOnRep_GateData); \
	DECLARE_FUNCTION(execIsShipReadyToJump); \
	DECLARE_FUNCTION(execServerRPC_RequestJump); \
	DECLARE_FUNCTION(execOnJumpTriggerBeginOverlap); \
	DECLARE_FUNCTION(execGetTargetSystemName); \
	DECLARE_FUNCTION(execIsOperational); \
	DECLARE_FUNCTION(execGetTargetSystemId); \
	DECLARE_FUNCTION(execGetGateName); \
	DECLARE_FUNCTION(execGetGateId); \
	DECLARE_FUNCTION(execInitializeStargate);


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_StargateActor_h_22_CALLBACK_WRAPPERS
ECHOES_API UClass* Z_Construct_UClass_AStargateActor_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_StargateActor_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAStargateActor(); \
	friend struct Z_Construct_UClass_AStargateActor_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_AStargateActor_NoRegister(); \
public: \
	DECLARE_CLASS2(AStargateActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_AStargateActor_NoRegister) \
	DECLARE_SERIALIZER(AStargateActor) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		GateId=NETFIELD_REP_START, \
		GateName, \
		TargetSystemId, \
		TargetSystemName, \
		bIsOperational, \
		NETFIELD_REP_END=bIsOperational	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_StargateActor_h_22_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AStargateActor(AStargateActor&&) = delete; \
	AStargateActor(const AStargateActor&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AStargateActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AStargateActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AStargateActor) \
	NO_API virtual ~AStargateActor();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_StargateActor_h_19_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_StargateActor_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_StargateActor_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_StargateActor_h_22_CALLBACK_WRAPPERS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_StargateActor_h_22_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_StargateActor_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AStargateActor;

// ********** End Class AStargateActor *************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_StargateActor_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
