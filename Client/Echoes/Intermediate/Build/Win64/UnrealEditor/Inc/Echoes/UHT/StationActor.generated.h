// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Common/Actor/StationActor.h"

#ifdef ECHOES_StationActor_generated_h
#error "StationActor.generated.h already included, missing '#pragma once' in StationActor.h"
#endif
#define ECHOES_StationActor_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class AActor;
class APlayerController;
class UPrimitiveComponent;
struct FGuid;
struct FHitResult;
struct FStationVisualRow;

// ********** Begin Class AStationActor ************************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_StationActor_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual bool ServerRPC_RequestUndock_Validate(APlayerController* ); \
	virtual void ServerRPC_RequestUndock_Implementation(APlayerController* PlayerController); \
	virtual void ClientRPC_OpenStationMenu_Implementation(const FString& InStationName, const FString& InStationType, FGuid const& InHangarStorageId); \
	virtual bool ServerRPC_RequestDocking_Validate(APlayerController* ); \
	virtual void ServerRPC_RequestDocking_Implementation(APlayerController* PlayerController); \
	DECLARE_FUNCTION(execHandleHangarFailure); \
	DECLARE_FUNCTION(execHandleHangarReceived); \
	DECLARE_FUNCTION(execOnRep_StationData); \
	DECLARE_FUNCTION(execServerRPC_RequestUndock); \
	DECLARE_FUNCTION(execClientRPC_OpenStationMenu); \
	DECLARE_FUNCTION(execHasDockingAccess); \
	DECLARE_FUNCTION(execServerRPC_RequestDocking); \
	DECLARE_FUNCTION(execOnDockingZoneBeginOverlap); \
	DECLARE_FUNCTION(execGetStationType); \
	DECLARE_FUNCTION(execGetStationName); \
	DECLARE_FUNCTION(execGetStationId); \
	DECLARE_FUNCTION(execInitializeStation);


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_StationActor_h_21_CALLBACK_WRAPPERS
ECHOES_API UClass* Z_Construct_UClass_AStationActor_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_StationActor_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAStationActor(); \
	friend struct Z_Construct_UClass_AStationActor_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_AStationActor_NoRegister(); \
public: \
	DECLARE_CLASS2(AStationActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_AStationActor_NoRegister) \
	DECLARE_SERIALIZER(AStationActor) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		StationId=NETFIELD_REP_START, \
		StationName, \
		StationType, \
		Seed, \
		NETFIELD_REP_END=Seed	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_StationActor_h_21_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AStationActor(AStationActor&&) = delete; \
	AStationActor(const AStationActor&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AStationActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AStationActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AStationActor) \
	NO_API virtual ~AStationActor();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_StationActor_h_18_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_StationActor_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_StationActor_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_StationActor_h_21_CALLBACK_WRAPPERS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_StationActor_h_21_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_StationActor_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AStationActor;

// ********** End Class AStationActor **************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_StationActor_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
