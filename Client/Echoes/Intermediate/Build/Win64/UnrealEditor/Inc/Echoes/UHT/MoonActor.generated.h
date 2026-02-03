// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Common/Actor/MoonActor.h"

#ifdef ECHOES_MoonActor_generated_h
#error "MoonActor.generated.h already included, missing '#pragma once' in MoonActor.h"
#endif
#define ECHOES_MoonActor_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

struct FGuid;

// ********** Begin Class AMoonActor ***************************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_MoonActor_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnRep_MoonData); \
	DECLARE_FUNCTION(execGetOrbitRadius); \
	DECLARE_FUNCTION(execGetMoonType); \
	DECLARE_FUNCTION(execGetMoonName); \
	DECLARE_FUNCTION(execGetMoonId); \
	DECLARE_FUNCTION(execClientOnly_DrawOrbit); \
	DECLARE_FUNCTION(execSetOrbitParameters); \
	DECLARE_FUNCTION(execInitializeMoon);


ECHOES_API UClass* Z_Construct_UClass_AMoonActor_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_MoonActor_h_23_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMoonActor(); \
	friend struct Z_Construct_UClass_AMoonActor_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_AMoonActor_NoRegister(); \
public: \
	DECLARE_CLASS2(AMoonActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_AMoonActor_NoRegister) \
	DECLARE_SERIALIZER(AMoonActor) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		MoonId=NETFIELD_REP_START, \
		MoonName, \
		MoonType, \
		OrbitRadius, \
		Seed, \
		NETFIELD_REP_END=Seed	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_MoonActor_h_23_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AMoonActor(AMoonActor&&) = delete; \
	AMoonActor(const AMoonActor&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMoonActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMoonActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMoonActor) \
	NO_API virtual ~AMoonActor();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_MoonActor_h_20_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_MoonActor_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_MoonActor_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_MoonActor_h_23_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_MoonActor_h_23_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AMoonActor;

// ********** End Class AMoonActor *****************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_MoonActor_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
