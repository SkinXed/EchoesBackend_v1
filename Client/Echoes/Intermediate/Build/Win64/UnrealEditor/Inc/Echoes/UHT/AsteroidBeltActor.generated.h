// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Common/AsteroidBeltActor.h"

#ifdef ECHOES_AsteroidBeltActor_generated_h
#error "AsteroidBeltActor.generated.h already included, missing '#pragma once' in AsteroidBeltActor.h"
#endif
#define ECHOES_AsteroidBeltActor_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

struct FAsteroidBeltVisualRow;
struct FGuid;

// ********** Begin Class AAsteroidBeltActor *******************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_AsteroidBeltActor_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetBeltName); \
	DECLARE_FUNCTION(execGetBeltId); \
	DECLARE_FUNCTION(execInitializeAsteroidBelt);


ECHOES_API UClass* Z_Construct_UClass_AAsteroidBeltActor_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_AsteroidBeltActor_h_29_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAAsteroidBeltActor(); \
	friend struct Z_Construct_UClass_AAsteroidBeltActor_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_AAsteroidBeltActor_NoRegister(); \
public: \
	DECLARE_CLASS2(AAsteroidBeltActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_AAsteroidBeltActor_NoRegister) \
	DECLARE_SERIALIZER(AAsteroidBeltActor) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		BeltId=NETFIELD_REP_START, \
		BeltName, \
		NETFIELD_REP_END=BeltName	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_AsteroidBeltActor_h_29_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AAsteroidBeltActor(AAsteroidBeltActor&&) = delete; \
	AAsteroidBeltActor(const AAsteroidBeltActor&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AAsteroidBeltActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AAsteroidBeltActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AAsteroidBeltActor) \
	NO_API virtual ~AAsteroidBeltActor();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_AsteroidBeltActor_h_26_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_AsteroidBeltActor_h_29_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_AsteroidBeltActor_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_AsteroidBeltActor_h_29_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_AsteroidBeltActor_h_29_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AAsteroidBeltActor;

// ********** End Class AAsteroidBeltActor *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_AsteroidBeltActor_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
