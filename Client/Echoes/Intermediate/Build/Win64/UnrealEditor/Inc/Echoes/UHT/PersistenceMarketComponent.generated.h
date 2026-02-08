// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Common/Components/PersistenceMarketComponent.h"

#ifdef ECHOES_PersistenceMarketComponent_generated_h
#error "PersistenceMarketComponent.generated.h already included, missing '#pragma once' in PersistenceMarketComponent.h"
#endif
#define ECHOES_PersistenceMarketComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

struct FMarketFilter;

// ********** Begin Delegate FOnTradingAvailabilityChanged *****************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_PersistenceMarketComponent_h_13_DELEGATE \
ECHOES_API void FOnTradingAvailabilityChanged_DelegateWrapper(const FMulticastScriptDelegate& OnTradingAvailabilityChanged, bool bCanTrade);


// ********** End Delegate FOnTradingAvailabilityChanged *******************************************

// ********** Begin Class UPersistenceMarketComponent **********************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_PersistenceMarketComponent_h_31_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execCanTrade); \
	DECLARE_FUNCTION(execClient_RequestMarketData); \
	DECLARE_FUNCTION(execServerOnly_IsNearTradingHub);


ECHOES_API UClass* Z_Construct_UClass_UPersistenceMarketComponent_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_PersistenceMarketComponent_h_31_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPersistenceMarketComponent(); \
	friend struct Z_Construct_UClass_UPersistenceMarketComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UPersistenceMarketComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UPersistenceMarketComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UPersistenceMarketComponent_NoRegister) \
	DECLARE_SERIALIZER(UPersistenceMarketComponent)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_PersistenceMarketComponent_h_31_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPersistenceMarketComponent(UPersistenceMarketComponent&&) = delete; \
	UPersistenceMarketComponent(const UPersistenceMarketComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPersistenceMarketComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPersistenceMarketComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UPersistenceMarketComponent) \
	NO_API virtual ~UPersistenceMarketComponent();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_PersistenceMarketComponent_h_28_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_PersistenceMarketComponent_h_31_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_PersistenceMarketComponent_h_31_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_PersistenceMarketComponent_h_31_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_PersistenceMarketComponent_h_31_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPersistenceMarketComponent;

// ********** End Class UPersistenceMarketComponent ************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_PersistenceMarketComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
