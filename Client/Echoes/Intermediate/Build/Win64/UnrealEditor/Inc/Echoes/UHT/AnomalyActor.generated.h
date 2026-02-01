// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Common/Actor/AnomalyActor.h"

#ifdef ECHOES_AnomalyActor_generated_h
#error "AnomalyActor.generated.h already included, missing '#pragma once' in AnomalyActor.h"
#endif
#define ECHOES_AnomalyActor_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

struct FAnomalyVisualRow;
struct FGuid;

// ********** Begin Class AAnomalyActor ************************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_AnomalyActor_h_28_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execDeactivateScanningSignature); \
	DECLARE_FUNCTION(execActivateScanningSignature); \
	DECLARE_FUNCTION(execGetAnomalyDifficulty); \
	DECLARE_FUNCTION(execGetAnomalyType); \
	DECLARE_FUNCTION(execGetAnomalyName); \
	DECLARE_FUNCTION(execGetAnomalyId); \
	DECLARE_FUNCTION(execInitializeAnomaly);


ECHOES_API UClass* Z_Construct_UClass_AAnomalyActor_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_AnomalyActor_h_28_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAAnomalyActor(); \
	friend struct Z_Construct_UClass_AAnomalyActor_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_AAnomalyActor_NoRegister(); \
public: \
	DECLARE_CLASS2(AAnomalyActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_AAnomalyActor_NoRegister) \
	DECLARE_SERIALIZER(AAnomalyActor) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		AnomalyId=NETFIELD_REP_START, \
		AnomalyName, \
		AnomalyType, \
		AnomalyDifficulty, \
		bSignatureActive, \
		NETFIELD_REP_END=bSignatureActive	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_AnomalyActor_h_28_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AAnomalyActor(AAnomalyActor&&) = delete; \
	AAnomalyActor(const AAnomalyActor&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AAnomalyActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AAnomalyActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AAnomalyActor) \
	NO_API virtual ~AAnomalyActor();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_AnomalyActor_h_25_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_AnomalyActor_h_28_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_AnomalyActor_h_28_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_AnomalyActor_h_28_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_AnomalyActor_h_28_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AAnomalyActor;

// ********** End Class AAnomalyActor **************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_AnomalyActor_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
