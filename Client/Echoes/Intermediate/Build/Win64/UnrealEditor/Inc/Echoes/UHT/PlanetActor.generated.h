// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Common/PlanetActor.h"

#ifdef ECHOES_PlanetActor_generated_h
#error "PlanetActor.generated.h already included, missing '#pragma once' in PlanetActor.h"
#endif
#define ECHOES_PlanetActor_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

struct FGuid;
struct FPlanetVisualRow;

// ********** Begin Class APlanetActor *************************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_PlanetActor_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnRep_PlanetData); \
	DECLARE_FUNCTION(execGetSeed); \
	DECLARE_FUNCTION(execGetRadius); \
	DECLARE_FUNCTION(execGetPlanetType); \
	DECLARE_FUNCTION(execGetPlanetName); \
	DECLARE_FUNCTION(execGetPlanetId); \
	DECLARE_FUNCTION(execApplySeedVariation); \
	DECLARE_FUNCTION(execInitializePlanet);


ECHOES_API UClass* Z_Construct_UClass_APlanetActor_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_PlanetActor_h_27_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPlanetActor(); \
	friend struct Z_Construct_UClass_APlanetActor_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_APlanetActor_NoRegister(); \
public: \
	DECLARE_CLASS2(APlanetActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_APlanetActor_NoRegister) \
	DECLARE_SERIALIZER(APlanetActor) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		PlanetId=NETFIELD_REP_START, \
		PlanetName, \
		PlanetType, \
		Radius, \
		Seed, \
		NETFIELD_REP_END=Seed	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_PlanetActor_h_27_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	APlanetActor(APlanetActor&&) = delete; \
	APlanetActor(const APlanetActor&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlanetActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlanetActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APlanetActor) \
	NO_API virtual ~APlanetActor();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_PlanetActor_h_24_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_PlanetActor_h_27_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_PlanetActor_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_PlanetActor_h_27_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_PlanetActor_h_27_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class APlanetActor;

// ********** End Class APlanetActor ***************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_PlanetActor_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
