// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Common/Components/EchoesStatsComponent.h"

#ifdef ECHOES_EchoesStatsComponent_generated_h
#error "EchoesStatsComponent.generated.h already included, missing '#pragma once' in EchoesStatsComponent.h"
#endif
#define ECHOES_EchoesStatsComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class AActor;

// ********** Begin Delegate FOnStatsChanged *******************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EchoesStatsComponent_h_15_DELEGATE \
ECHOES_API void FOnStatsChanged_DelegateWrapper(const FMulticastScriptDelegate& OnStatsChanged, float ShieldPct, float ArmorPct, float StructPct);


// ********** End Delegate FOnStatsChanged *********************************************************

// ********** Begin Delegate FOnDeath **************************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EchoesStatsComponent_h_22_DELEGATE \
ECHOES_API void FOnDeath_DelegateWrapper(const FMulticastScriptDelegate& OnDeath, AActor* Victim, AActor* Killer);


// ********** End Delegate FOnDeath ****************************************************************

// ********** Begin Class UEchoesStatsComponent ****************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EchoesStatsComponent_h_53_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execClientOnly_OnRep_UpdateUI); \
	DECLARE_FUNCTION(execServerOnly_RestoreAll); \
	DECLARE_FUNCTION(execIsAlive); \
	DECLARE_FUNCTION(execCommon_GetStructurePercentage); \
	DECLARE_FUNCTION(execCommon_GetArmorPercentage); \
	DECLARE_FUNCTION(execCommon_GetShieldPercentage); \
	DECLARE_FUNCTION(execCommon_GetHealthPercentage); \
	DECLARE_FUNCTION(execServerOnly_ApplyDamage);


ECHOES_API UClass* Z_Construct_UClass_UEchoesStatsComponent_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EchoesStatsComponent_h_53_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEchoesStatsComponent(); \
	friend struct Z_Construct_UClass_UEchoesStatsComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UEchoesStatsComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UEchoesStatsComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UEchoesStatsComponent_NoRegister) \
	DECLARE_SERIALIZER(UEchoesStatsComponent) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		ShieldCurrent=NETFIELD_REP_START, \
		ShieldMax, \
		ArmorCurrent, \
		ArmorMax, \
		StructureCurrent, \
		StructureMax, \
		NETFIELD_REP_END=StructureMax	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EchoesStatsComponent_h_53_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UEchoesStatsComponent(UEchoesStatsComponent&&) = delete; \
	UEchoesStatsComponent(const UEchoesStatsComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEchoesStatsComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEchoesStatsComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UEchoesStatsComponent) \
	NO_API virtual ~UEchoesStatsComponent();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EchoesStatsComponent_h_50_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EchoesStatsComponent_h_53_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EchoesStatsComponent_h_53_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EchoesStatsComponent_h_53_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EchoesStatsComponent_h_53_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UEchoesStatsComponent;

// ********** End Class UEchoesStatsComponent ******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EchoesStatsComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
