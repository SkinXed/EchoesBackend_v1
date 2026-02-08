// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Common/Components/CosmosWeaponComponent.h"

#ifdef ECHOES_CosmosWeaponComponent_generated_h
#error "CosmosWeaponComponent.generated.h already included, missing '#pragma once' in CosmosWeaponComponent.h"
#endif
#define ECHOES_CosmosWeaponComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class AActor;

// ********** Begin Class UCosmosWeaponComponent ***************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_CosmosWeaponComponent_h_55_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetCooldownRemaining); \
	DECLARE_FUNCTION(execCanFire); \
	DECLARE_FUNCTION(execServerOnly_Fire); \
	DECLARE_FUNCTION(execCommon_GetPredictionLocation);


ECHOES_API UClass* Z_Construct_UClass_UCosmosWeaponComponent_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_CosmosWeaponComponent_h_55_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCosmosWeaponComponent(); \
	friend struct Z_Construct_UClass_UCosmosWeaponComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UCosmosWeaponComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UCosmosWeaponComponent, USceneComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UCosmosWeaponComponent_NoRegister) \
	DECLARE_SERIALIZER(UCosmosWeaponComponent)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_CosmosWeaponComponent_h_55_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UCosmosWeaponComponent(UCosmosWeaponComponent&&) = delete; \
	UCosmosWeaponComponent(const UCosmosWeaponComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCosmosWeaponComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCosmosWeaponComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCosmosWeaponComponent) \
	NO_API virtual ~UCosmosWeaponComponent();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_CosmosWeaponComponent_h_52_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_CosmosWeaponComponent_h_55_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_CosmosWeaponComponent_h_55_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_CosmosWeaponComponent_h_55_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_CosmosWeaponComponent_h_55_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UCosmosWeaponComponent;

// ********** End Class UCosmosWeaponComponent *****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_CosmosWeaponComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
