// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Common/EchoesShipMovementComponent.h"

#ifdef ECHOES_EchoesShipMovementComponent_generated_h
#error "EchoesShipMovementComponent.generated.h already included, missing '#pragma once' in EchoesShipMovementComponent.h"
#endif
#define ECHOES_EchoesShipMovementComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

struct FEchoesShipStats;

// ********** Begin Class UEchoesShipMovementComponent *********************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesShipMovementComponent_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execCommon_CalculateAlignTime); \
	DECLARE_FUNCTION(execCanEnterWarp); \
	DECLARE_FUNCTION(execCancelWarp); \
	DECLARE_FUNCTION(execInitiateWarp); \
	DECLARE_FUNCTION(execSetMouseFollowEnabled); \
	DECLARE_FUNCTION(execSetTargetDirection); \
	DECLARE_FUNCTION(execSetMovementInput); \
	DECLARE_FUNCTION(execInitializeShipStats);


ECHOES_API UClass* Z_Construct_UClass_UEchoesShipMovementComponent_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesShipMovementComponent_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEchoesShipMovementComponent(); \
	friend struct Z_Construct_UClass_UEchoesShipMovementComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UEchoesShipMovementComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UEchoesShipMovementComponent, UMovementComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UEchoesShipMovementComponent_NoRegister) \
	DECLARE_SERIALIZER(UEchoesShipMovementComponent)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesShipMovementComponent_h_18_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UEchoesShipMovementComponent(UEchoesShipMovementComponent&&) = delete; \
	UEchoesShipMovementComponent(const UEchoesShipMovementComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEchoesShipMovementComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEchoesShipMovementComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UEchoesShipMovementComponent) \
	NO_API virtual ~UEchoesShipMovementComponent();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesShipMovementComponent_h_15_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesShipMovementComponent_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesShipMovementComponent_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesShipMovementComponent_h_18_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesShipMovementComponent_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UEchoesShipMovementComponent;

// ********** End Class UEchoesShipMovementComponent ***********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesShipMovementComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
