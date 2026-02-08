// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Common/Networking/EchoesMarketSubsystem.h"

#ifdef ECHOES_EchoesMarketSubsystem_generated_h
#error "EchoesMarketSubsystem.generated.h already included, missing '#pragma once' in EchoesMarketSubsystem.h"
#endif
#define ECHOES_EchoesMarketSubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

enum class EMarketTransactionState : uint8;
struct FGuid;
struct FMarketFilter;
struct FMarketOrderDto;
struct FMarketTradeResult;

// ********** Begin Delegate FOnMarketDataReceived *************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesMarketSubsystem_h_17_DELEGATE \
ECHOES_API void FOnMarketDataReceived_DelegateWrapper(const FMulticastScriptDelegate& OnMarketDataReceived, TArray<FMarketOrderDto> const& Orders);


// ********** End Delegate FOnMarketDataReceived ***************************************************

// ********** Begin Delegate FOnMarketRequestFailed ************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesMarketSubsystem_h_20_DELEGATE \
ECHOES_API void FOnMarketRequestFailed_DelegateWrapper(const FMulticastScriptDelegate& OnMarketRequestFailed, const FString& ErrorMessage);


// ********** End Delegate FOnMarketRequestFailed **************************************************

// ********** Begin Delegate FOnMarketOrderCreated *************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesMarketSubsystem_h_23_DELEGATE \
ECHOES_API void FOnMarketOrderCreated_DelegateWrapper(const FMulticastScriptDelegate& OnMarketOrderCreated, FGuid const& OrderId);


// ********** End Delegate FOnMarketOrderCreated ***************************************************

// ********** Begin Delegate FOnMarketTradeExecuted ************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesMarketSubsystem_h_26_DELEGATE \
ECHOES_API void FOnMarketTradeExecuted_DelegateWrapper(const FMulticastScriptDelegate& OnMarketTradeExecuted, FGuid const& OrderId, int32 QuantityTraded);


// ********** End Delegate FOnMarketTradeExecuted **************************************************

// ********** Begin Delegate FOnTradeConfirmed *****************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesMarketSubsystem_h_29_DELEGATE \
ECHOES_API void FOnTradeConfirmed_DelegateWrapper(const FMulticastScriptDelegate& OnTradeConfirmed, FMarketTradeResult const& TradeResult);


// ********** End Delegate FOnTradeConfirmed *******************************************************

// ********** Begin Delegate FOnTradeError *********************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesMarketSubsystem_h_32_DELEGATE \
ECHOES_API void FOnTradeError_DelegateWrapper(const FMulticastScriptDelegate& OnTradeError, int32 HttpStatusCode, const FString& ErrorMessage);


// ********** End Delegate FOnTradeError ***********************************************************

// ********** Begin Delegate FOnMarketOrderCancelled ***********************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesMarketSubsystem_h_35_DELEGATE \
ECHOES_API void FOnMarketOrderCancelled_DelegateWrapper(const FMulticastScriptDelegate& OnMarketOrderCancelled, FGuid const& OrderId, double EscrowRefunded);


// ********** End Delegate FOnMarketOrderCancelled *************************************************

// ********** Begin Delegate FOnMarketInventorySyncRequired ****************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesMarketSubsystem_h_38_DELEGATE \
ECHOES_API void FOnMarketInventorySyncRequired_DelegateWrapper(const FMulticastScriptDelegate& OnMarketInventorySyncRequired, FGuid const& CharacterId);


// ********** End Delegate FOnMarketInventorySyncRequired ******************************************

// ********** Begin Class UEchoesMarketSubsystem ***************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesMarketSubsystem_h_56_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execIsCacheValid); \
	DECLARE_FUNCTION(execGetCachedMarketOrders); \
	DECLARE_FUNCTION(execResetTransactionState); \
	DECLARE_FUNCTION(execGetTransactionState); \
	DECLARE_FUNCTION(execServerOnly_CancelOrder); \
	DECLARE_FUNCTION(execServerOnly_CreateOrder); \
	DECLARE_FUNCTION(execServerOnly_ExecuteTrade); \
	DECLARE_FUNCTION(execServerOnly_FetchMarketOrders);


ECHOES_API UClass* Z_Construct_UClass_UEchoesMarketSubsystem_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesMarketSubsystem_h_56_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEchoesMarketSubsystem(); \
	friend struct Z_Construct_UClass_UEchoesMarketSubsystem_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UEchoesMarketSubsystem_NoRegister(); \
public: \
	DECLARE_CLASS2(UEchoesMarketSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UEchoesMarketSubsystem_NoRegister) \
	DECLARE_SERIALIZER(UEchoesMarketSubsystem)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesMarketSubsystem_h_56_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UEchoesMarketSubsystem(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UEchoesMarketSubsystem(UEchoesMarketSubsystem&&) = delete; \
	UEchoesMarketSubsystem(const UEchoesMarketSubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEchoesMarketSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEchoesMarketSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UEchoesMarketSubsystem) \
	NO_API virtual ~UEchoesMarketSubsystem();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesMarketSubsystem_h_53_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesMarketSubsystem_h_56_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesMarketSubsystem_h_56_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesMarketSubsystem_h_56_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesMarketSubsystem_h_56_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UEchoesMarketSubsystem;

// ********** End Class UEchoesMarketSubsystem *****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesMarketSubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
