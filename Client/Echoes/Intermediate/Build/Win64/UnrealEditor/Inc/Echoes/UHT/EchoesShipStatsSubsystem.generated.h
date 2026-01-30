// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Common/EchoesShipStatsSubsystem.h"

#ifdef ECHOES_EchoesShipStatsSubsystem_generated_h
#error "EchoesShipStatsSubsystem.generated.h already included, missing '#pragma once' in EchoesShipStatsSubsystem.h"
#endif
#define ECHOES_EchoesShipStatsSubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

struct FEchoesShipStats;
struct FGuid;

// ********** Begin Delegate FOnShipStatsFetched ***************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesShipStatsSubsystem_h_11_DELEGATE \
ECHOES_API void FOnShipStatsFetched_DelegateWrapper(const FScriptDelegate& OnShipStatsFetched, FEchoesShipStats const& Stats);


// ********** End Delegate FOnShipStatsFetched *****************************************************

// ********** Begin Delegate FOnModuleAdded ********************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesShipStatsSubsystem_h_12_DELEGATE \
ECHOES_API void FOnModuleAdded_DelegateWrapper(const FScriptDelegate& OnModuleAdded, bool bSuccess);


// ********** End Delegate FOnModuleAdded **********************************************************

// ********** Begin Delegate FOnApiError ***********************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesShipStatsSubsystem_h_13_DELEGATE \
ECHOES_API void FOnApiError_DelegateWrapper(const FScriptDelegate& OnApiError, const FString& ErrorMessage);


// ********** End Delegate FOnApiError *************************************************************

// ********** Begin Class UEchoesShipStatsSubsystem ************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesShipStatsSubsystem_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execAddModule); \
	DECLARE_FUNCTION(execFetchShipStats);


ECHOES_API UClass* Z_Construct_UClass_UEchoesShipStatsSubsystem_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesShipStatsSubsystem_h_25_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEchoesShipStatsSubsystem(); \
	friend struct Z_Construct_UClass_UEchoesShipStatsSubsystem_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UEchoesShipStatsSubsystem_NoRegister(); \
public: \
	DECLARE_CLASS2(UEchoesShipStatsSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UEchoesShipStatsSubsystem_NoRegister) \
	DECLARE_SERIALIZER(UEchoesShipStatsSubsystem) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesShipStatsSubsystem_h_25_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UEchoesShipStatsSubsystem(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UEchoesShipStatsSubsystem(UEchoesShipStatsSubsystem&&) = delete; \
	UEchoesShipStatsSubsystem(const UEchoesShipStatsSubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEchoesShipStatsSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEchoesShipStatsSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UEchoesShipStatsSubsystem) \
	NO_API virtual ~UEchoesShipStatsSubsystem();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesShipStatsSubsystem_h_22_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesShipStatsSubsystem_h_25_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesShipStatsSubsystem_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesShipStatsSubsystem_h_25_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesShipStatsSubsystem_h_25_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UEchoesShipStatsSubsystem;

// ********** End Class UEchoesShipStatsSubsystem **************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesShipStatsSubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
