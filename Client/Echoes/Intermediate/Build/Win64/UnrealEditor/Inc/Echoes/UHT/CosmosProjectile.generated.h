// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Common/Actor/CosmosProjectile.h"

#ifdef ECHOES_CosmosProjectile_generated_h
#error "CosmosProjectile.generated.h already included, missing '#pragma once' in CosmosProjectile.h"
#endif
#define ECHOES_CosmosProjectile_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class AActor;
class UPrimitiveComponent;
enum class ECosmosDamageType : uint8;
struct FHitResult;

// ********** Begin Class ACosmosProjectile ********************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_CosmosProjectile_h_46_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnHit); \
	DECLARE_FUNCTION(execInitializeProjectile);


ECHOES_API UClass* Z_Construct_UClass_ACosmosProjectile_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_CosmosProjectile_h_46_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACosmosProjectile(); \
	friend struct Z_Construct_UClass_ACosmosProjectile_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_ACosmosProjectile_NoRegister(); \
public: \
	DECLARE_CLASS2(ACosmosProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_ACosmosProjectile_NoRegister) \
	DECLARE_SERIALIZER(ACosmosProjectile)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_CosmosProjectile_h_46_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ACosmosProjectile(ACosmosProjectile&&) = delete; \
	ACosmosProjectile(const ACosmosProjectile&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACosmosProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACosmosProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACosmosProjectile) \
	NO_API virtual ~ACosmosProjectile();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_CosmosProjectile_h_43_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_CosmosProjectile_h_46_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_CosmosProjectile_h_46_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_CosmosProjectile_h_46_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_CosmosProjectile_h_46_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ACosmosProjectile;

// ********** End Class ACosmosProjectile **********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_CosmosProjectile_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
