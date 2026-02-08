// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Common/Components/CosmosAttributesComponent.h"

#ifdef ECHOES_CosmosAttributesComponent_generated_h
#error "CosmosAttributesComponent.generated.h already included, missing '#pragma once' in CosmosAttributesComponent.h"
#endif
#define ECHOES_CosmosAttributesComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class AActor;
enum class ECosmosDamageType : uint8;

// ********** Begin Delegate FOnAttributesChanged **************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_CosmosAttributesComponent_h_14_DELEGATE \
ECHOES_API void FOnAttributesChanged_DelegateWrapper(const FMulticastScriptDelegate& OnAttributesChanged);


// ********** End Delegate FOnAttributesChanged ****************************************************

// ********** Begin Delegate FOnCosmosDeath ********************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_CosmosAttributesComponent_h_21_DELEGATE \
ECHOES_API void FOnCosmosDeath_DelegateWrapper(const FMulticastScriptDelegate& OnCosmosDeath, AActor* Victim, AActor* Killer);


// ********** End Delegate FOnCosmosDeath **********************************************************

// ********** Begin Class UCosmosAttributesComponent ***********************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_CosmosAttributesComponent_h_67_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execClientOnly_OnRep_Stats); \
	DECLARE_FUNCTION(execServerOnly_SetLayerResistances); \
	DECLARE_FUNCTION(execServerOnly_RestoreAll); \
	DECLARE_FUNCTION(execIsAlive); \
	DECLARE_FUNCTION(execCommon_GetOverallHealthPct); \
	DECLARE_FUNCTION(execCommon_GetHullPct); \
	DECLARE_FUNCTION(execCommon_GetArmorPct); \
	DECLARE_FUNCTION(execCommon_GetShieldPct); \
	DECLARE_FUNCTION(execServerOnly_ApplyDamage);


ECHOES_API UClass* Z_Construct_UClass_UCosmosAttributesComponent_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_CosmosAttributesComponent_h_67_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCosmosAttributesComponent(); \
	friend struct Z_Construct_UClass_UCosmosAttributesComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UCosmosAttributesComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UCosmosAttributesComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UCosmosAttributesComponent_NoRegister) \
	DECLARE_SERIALIZER(UCosmosAttributesComponent) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		Shield=NETFIELD_REP_START, \
		Armor, \
		Structure, \
		Mass, \
		InertiaModifier, \
		CargoCapacity, \
		NETFIELD_REP_END=CargoCapacity	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_CosmosAttributesComponent_h_67_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UCosmosAttributesComponent(UCosmosAttributesComponent&&) = delete; \
	UCosmosAttributesComponent(const UCosmosAttributesComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCosmosAttributesComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCosmosAttributesComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCosmosAttributesComponent) \
	NO_API virtual ~UCosmosAttributesComponent();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_CosmosAttributesComponent_h_64_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_CosmosAttributesComponent_h_67_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_CosmosAttributesComponent_h_67_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_CosmosAttributesComponent_h_67_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_CosmosAttributesComponent_h_67_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UCosmosAttributesComponent;

// ********** End Class UCosmosAttributesComponent *************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_CosmosAttributesComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
