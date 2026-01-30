// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Client/EchoesShipPawn.h"

#ifdef ECHOES_EchoesShipPawn_generated_h
#error "EchoesShipPawn.generated.h already included, missing '#pragma once' in EchoesShipPawn.h"
#endif
#define ECHOES_EchoesShipPawn_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

struct FEchoesShipStats;

// ********** Begin Class AEchoesShipPawn **********************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Client_EchoesShipPawn_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnFittingReceived); \
	DECLARE_FUNCTION(execOnRep_ShipStats); \
	DECLARE_FUNCTION(execServerRPC_RequestShipInitialization); \
	DECLARE_FUNCTION(execGetShipStats); \
	DECLARE_FUNCTION(execInitializeShipStats); \
	DECLARE_FUNCTION(execCommon_InitializeFromStats);


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Client_EchoesShipPawn_h_25_CALLBACK_WRAPPERS
ECHOES_API UClass* Z_Construct_UClass_AEchoesShipPawn_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Client_EchoesShipPawn_h_25_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEchoesShipPawn(); \
	friend struct Z_Construct_UClass_AEchoesShipPawn_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_AEchoesShipPawn_NoRegister(); \
public: \
	DECLARE_CLASS2(AEchoesShipPawn, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_AEchoesShipPawn_NoRegister) \
	DECLARE_SERIALIZER(AEchoesShipPawn) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		ReplicatedShipStats=NETFIELD_REP_START, \
		NETFIELD_REP_END=ReplicatedShipStats	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Client_EchoesShipPawn_h_25_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AEchoesShipPawn(AEchoesShipPawn&&) = delete; \
	AEchoesShipPawn(const AEchoesShipPawn&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEchoesShipPawn); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEchoesShipPawn); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AEchoesShipPawn) \
	NO_API virtual ~AEchoesShipPawn();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Client_EchoesShipPawn_h_22_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Client_EchoesShipPawn_h_25_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Client_EchoesShipPawn_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Client_EchoesShipPawn_h_25_CALLBACK_WRAPPERS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Client_EchoesShipPawn_h_25_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Client_EchoesShipPawn_h_25_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AEchoesShipPawn;

// ********** End Class AEchoesShipPawn ************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Client_EchoesShipPawn_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
