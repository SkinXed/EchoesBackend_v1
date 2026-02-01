// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Common/Actor/StarActor.h"

#ifdef ECHOES_StarActor_generated_h
#error "StarActor.generated.h already included, missing '#pragma once' in StarActor.h"
#endif
#define ECHOES_StarActor_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

struct FStarVisualRow;

// ********** Begin Class AStarActor ***************************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_StarActor_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnRep_StarData); \
	DECLARE_FUNCTION(execGetLuminosity); \
	DECLARE_FUNCTION(execGetTemperature); \
	DECLARE_FUNCTION(execGetStarClass); \
	DECLARE_FUNCTION(execInitializeStar);


ECHOES_API UClass* Z_Construct_UClass_AStarActor_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_StarActor_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAStarActor(); \
	friend struct Z_Construct_UClass_AStarActor_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_AStarActor_NoRegister(); \
public: \
	DECLARE_CLASS2(AStarActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_AStarActor_NoRegister) \
	DECLARE_SERIALIZER(AStarActor) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		StarClass=NETFIELD_REP_START, \
		Temperature, \
		Luminosity, \
		Radius, \
		NETFIELD_REP_END=Radius	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_StarActor_h_24_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AStarActor(AStarActor&&) = delete; \
	AStarActor(const AStarActor&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AStarActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AStarActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AStarActor) \
	NO_API virtual ~AStarActor();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_StarActor_h_21_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_StarActor_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_StarActor_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_StarActor_h_24_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_StarActor_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AStarActor;

// ********** End Class AStarActor *****************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_StarActor_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
