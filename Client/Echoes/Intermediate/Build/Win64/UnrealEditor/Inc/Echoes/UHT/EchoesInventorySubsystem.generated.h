// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Common/Networking/EchoesInventorySubsystem.h"

#ifdef ECHOES_EchoesInventorySubsystem_generated_h
#error "EchoesInventorySubsystem.generated.h already included, missing '#pragma once' in EchoesInventorySubsystem.h"
#endif
#define ECHOES_EchoesInventorySubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class UStaticMesh;
class UTexture2D;
struct FEchoesItemDefinitionRow;
struct FEchoesShipFitting;
struct FEchoesShipInstance;
struct FEchoesShipList;
struct FGuid;

// ********** Begin ScriptStruct FEchoesShipInstance ***********************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesInventorySubsystem_h_24_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FEchoesShipInstance_Statics; \
	ECHOES_API static class UScriptStruct* StaticStruct();


struct FEchoesShipInstance;
// ********** End ScriptStruct FEchoesShipInstance *************************************************

// ********** Begin ScriptStruct FEchoesShipList ***************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesInventorySubsystem_h_64_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FEchoesShipList_Statics; \
	ECHOES_API static class UScriptStruct* StaticStruct();


struct FEchoesShipList;
// ********** End ScriptStruct FEchoesShipList *****************************************************

// ********** Begin ScriptStruct FEchoesModule *****************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesInventorySubsystem_h_77_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FEchoesModule_Statics; \
	ECHOES_API static class UScriptStruct* StaticStruct();


struct FEchoesModule;
// ********** End ScriptStruct FEchoesModule *******************************************************

// ********** Begin ScriptStruct FEchoesShipFitting ************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesInventorySubsystem_h_120_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FEchoesShipFitting_Statics; \
	ECHOES_API static class UScriptStruct* StaticStruct();


struct FEchoesShipFitting;
// ********** End ScriptStruct FEchoesShipFitting **************************************************

// ********** Begin Delegate FOnIconLoaded *********************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesInventorySubsystem_h_157_DELEGATE \
ECHOES_API void FOnIconLoaded_DelegateWrapper(const FScriptDelegate& OnIconLoaded, UTexture2D* LoadedIcon);


// ********** End Delegate FOnIconLoaded ***********************************************************

// ********** Begin Delegate FOnWorldMeshLoaded ****************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesInventorySubsystem_h_158_DELEGATE \
ECHOES_API void FOnWorldMeshLoaded_DelegateWrapper(const FScriptDelegate& OnWorldMeshLoaded, UStaticMesh* LoadedMesh);


// ********** End Delegate FOnWorldMeshLoaded ******************************************************

// ********** Begin Delegate FOnShipsReceived ******************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesInventorySubsystem_h_160_DELEGATE \
ECHOES_API void FOnShipsReceived_DelegateWrapper(const FScriptDelegate& OnShipsReceived, FEchoesShipList const& ShipList);


// ********** End Delegate FOnShipsReceived ********************************************************

// ********** Begin Delegate FOnShipFittingReceived ************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesInventorySubsystem_h_161_DELEGATE \
ECHOES_API void FOnShipFittingReceived_DelegateWrapper(const FScriptDelegate& OnShipFittingReceived, FEchoesShipFitting const& Fitting);


// ********** End Delegate FOnShipFittingReceived **************************************************

// ********** Begin Delegate FOnInventoryFailure ***************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesInventorySubsystem_h_162_DELEGATE \
ECHOES_API void FOnInventoryFailure_DelegateWrapper(const FScriptDelegate& OnInventoryFailure, const FString& ErrorMessage);


// ********** End Delegate FOnInventoryFailure *****************************************************

// ********** Begin Delegate FOnShipActivated ******************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesInventorySubsystem_h_163_DELEGATE \
ECHOES_API void FOnShipActivated_DelegateWrapper(const FScriptDelegate& OnShipActivated);


// ********** End Delegate FOnShipActivated ********************************************************

// ********** Begin Delegate FOnModuleFitted *******************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesInventorySubsystem_h_164_DELEGATE \
ECHOES_API void FOnModuleFitted_DelegateWrapper(const FScriptDelegate& OnModuleFitted);


// ********** End Delegate FOnModuleFitted *********************************************************

// ********** Begin Delegate FOnModuleUnfitted *****************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesInventorySubsystem_h_165_DELEGATE \
ECHOES_API void FOnModuleUnfitted_DelegateWrapper(const FScriptDelegate& OnModuleUnfitted);


// ********** End Delegate FOnModuleUnfitted *******************************************************

// ********** Begin Delegate FOnHangarReceived *****************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesInventorySubsystem_h_166_DELEGATE \
ECHOES_API void FOnHangarReceived_DelegateWrapper(const FScriptDelegate& OnHangarReceived, FGuid const& HangarStorageId);


// ********** End Delegate FOnHangarReceived *******************************************************

// ********** Begin Class UEchoesInventorySubsystem ************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesInventorySubsystem_h_191_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execUI_UnfitModule); \
	DECLARE_FUNCTION(execUI_FitModule); \
	DECLARE_FUNCTION(execHasItemInRegistry); \
	DECLARE_FUNCTION(execGetItemFromRegistryData); \
	DECLARE_FUNCTION(execHasItemDefinition); \
	DECLARE_FUNCTION(execAsyncLoadItemWorldMesh); \
	DECLARE_FUNCTION(execAsyncLoadItemIcon); \
	DECLARE_FUNCTION(execGetItemDefinitionDataByTypeId); \
	DECLARE_FUNCTION(execGetItemDefinitionData); \
	DECLARE_FUNCTION(execGetPersonalHangarId); \
	DECLARE_FUNCTION(execInventory_RequestPersonalHangar); \
	DECLARE_FUNCTION(execInventory_ClearCache); \
	DECLARE_FUNCTION(execInventory_GetActiveShip); \
	DECLARE_FUNCTION(execInventory_GetCachedFitting); \
	DECLARE_FUNCTION(execInventory_GetCachedShips); \
	DECLARE_FUNCTION(execInventory_SetActiveShip); \
	DECLARE_FUNCTION(execInventory_FetchShipFitting); \
	DECLARE_FUNCTION(execInventory_FetchShips);


ECHOES_API UClass* Z_Construct_UClass_UEchoesInventorySubsystem_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesInventorySubsystem_h_191_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEchoesInventorySubsystem(); \
	friend struct Z_Construct_UClass_UEchoesInventorySubsystem_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UEchoesInventorySubsystem_NoRegister(); \
public: \
	DECLARE_CLASS2(UEchoesInventorySubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UEchoesInventorySubsystem_NoRegister) \
	DECLARE_SERIALIZER(UEchoesInventorySubsystem)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesInventorySubsystem_h_191_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UEchoesInventorySubsystem(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UEchoesInventorySubsystem(UEchoesInventorySubsystem&&) = delete; \
	UEchoesInventorySubsystem(const UEchoesInventorySubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEchoesInventorySubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEchoesInventorySubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UEchoesInventorySubsystem) \
	NO_API virtual ~UEchoesInventorySubsystem();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesInventorySubsystem_h_188_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesInventorySubsystem_h_191_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesInventorySubsystem_h_191_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesInventorySubsystem_h_191_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesInventorySubsystem_h_191_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UEchoesInventorySubsystem;

// ********** End Class UEchoesInventorySubsystem **************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesInventorySubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
