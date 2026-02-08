// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Common/Actor/EchoesStargate.h"

#ifdef ECHOES_EchoesStargate_generated_h
#error "EchoesStargate.generated.h already included, missing '#pragma once' in EchoesStargate.h"
#endif
#define ECHOES_EchoesStargate_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class AActor;
class UPrimitiveComponent;
struct FGuid;
struct FHitResult;

// ********** Begin Class AEchoesStargate **********************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EchoesStargate_h_28_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execPlayIdleEffect); \
	DECLARE_FUNCTION(execPlayJumpEffect); \
	DECLARE_FUNCTION(execGetCharacterIdFromShip); \
	DECLARE_FUNCTION(execCanShipJump); \
	DECLARE_FUNCTION(execServerOnly_InitiateJump); \
	DECLARE_FUNCTION(execOnTriggerEndOverlap); \
	DECLARE_FUNCTION(execOnTriggerBeginOverlap);


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EchoesStargate_h_28_CALLBACK_WRAPPERS
ECHOES_API UClass* Z_Construct_UClass_AEchoesStargate_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EchoesStargate_h_28_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEchoesStargate(); \
	friend struct Z_Construct_UClass_AEchoesStargate_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_AEchoesStargate_NoRegister(); \
public: \
	DECLARE_CLASS2(AEchoesStargate, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_AEchoesStargate_NoRegister) \
	DECLARE_SERIALIZER(AEchoesStargate)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EchoesStargate_h_28_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AEchoesStargate(AEchoesStargate&&) = delete; \
	AEchoesStargate(const AEchoesStargate&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEchoesStargate); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEchoesStargate); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AEchoesStargate) \
	NO_API virtual ~AEchoesStargate();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EchoesStargate_h_25_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EchoesStargate_h_28_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EchoesStargate_h_28_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EchoesStargate_h_28_CALLBACK_WRAPPERS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EchoesStargate_h_28_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EchoesStargate_h_28_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AEchoesStargate;

// ********** End Class AEchoesStargate ************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EchoesStargate_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
