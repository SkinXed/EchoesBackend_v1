// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Common/Components/EchoesInventoryComponent.h"

#ifdef ECHOES_EchoesInventoryComponent_generated_h
#error "EchoesInventoryComponent.generated.h already included, missing '#pragma once' in EchoesInventoryComponent.h"
#endif
#define ECHOES_EchoesInventoryComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class AActor;
struct FEchoesContainerItems;
struct FGuid;

// ********** Begin ScriptStruct FEchoesInventoryItem **********************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EchoesInventoryComponent_h_17_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FEchoesInventoryItem_Statics; \
	ECHOES_API static class UScriptStruct* StaticStruct();


struct FEchoesInventoryItem;
// ********** End ScriptStruct FEchoesInventoryItem ************************************************

// ********** Begin ScriptStruct FEchoesContainerItems *********************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EchoesInventoryComponent_h_47_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FEchoesContainerItems_Statics; \
	ECHOES_API static class UScriptStruct* StaticStruct();


struct FEchoesContainerItems;
// ********** End ScriptStruct FEchoesContainerItems ***********************************************

// ********** Begin Delegate FOnItemsFetched *******************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EchoesInventoryComponent_h_60_DELEGATE \
ECHOES_API void FOnItemsFetched_DelegateWrapper(const FScriptDelegate& OnItemsFetched, FEchoesContainerItems const& Items);


// ********** End Delegate FOnItemsFetched *********************************************************

// ********** Begin Delegate FOnItemMoveSuccess ****************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EchoesInventoryComponent_h_61_DELEGATE \
ECHOES_API void FOnItemMoveSuccess_DelegateWrapper(const FScriptDelegate& OnItemMoveSuccess);


// ********** End Delegate FOnItemMoveSuccess ******************************************************

// ********** Begin Delegate FOnInventoryOperationFailure ******************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EchoesInventoryComponent_h_62_DELEGATE \
ECHOES_API void FOnInventoryOperationFailure_DelegateWrapper(const FScriptDelegate& OnInventoryOperationFailure, const FString& ErrorMessage);


// ********** End Delegate FOnInventoryOperationFailure ********************************************

// ********** Begin Delegate FOnInventoryUpdated ***************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EchoesInventoryComponent_h_65_DELEGATE \
ECHOES_API void FOnInventoryUpdated_DelegateWrapper(const FMulticastScriptDelegate& OnInventoryUpdated, FEchoesContainerItems const& Items);


// ********** End Delegate FOnInventoryUpdated *****************************************************

// ********** Begin Class UEchoesInventoryComponent ************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EchoesInventoryComponent_h_88_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandleMoveRefreshFailure); \
	DECLARE_FUNCTION(execHandleMoveRefreshSuccess); \
	DECLARE_FUNCTION(execInitializeStorage); \
	DECLARE_FUNCTION(execServerOnly_StackAll); \
	DECLARE_FUNCTION(execServerOnly_JettisonItem); \
	DECLARE_FUNCTION(execServerOnly_MoveItem); \
	DECLARE_FUNCTION(execCanFitItem); \
	DECLARE_FUNCTION(execGetAvailableVolume); \
	DECLARE_FUNCTION(execGetCachedItems); \
	DECLARE_FUNCTION(execFetchItems);


ECHOES_API UClass* Z_Construct_UClass_UEchoesInventoryComponent_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EchoesInventoryComponent_h_88_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEchoesInventoryComponent(); \
	friend struct Z_Construct_UClass_UEchoesInventoryComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UEchoesInventoryComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UEchoesInventoryComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UEchoesInventoryComponent_NoRegister) \
	DECLARE_SERIALIZER(UEchoesInventoryComponent)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EchoesInventoryComponent_h_88_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UEchoesInventoryComponent(UEchoesInventoryComponent&&) = delete; \
	UEchoesInventoryComponent(const UEchoesInventoryComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEchoesInventoryComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEchoesInventoryComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UEchoesInventoryComponent) \
	NO_API virtual ~UEchoesInventoryComponent();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EchoesInventoryComponent_h_85_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EchoesInventoryComponent_h_88_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EchoesInventoryComponent_h_88_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EchoesInventoryComponent_h_88_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EchoesInventoryComponent_h_88_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UEchoesInventoryComponent;

// ********** End Class UEchoesInventoryComponent **************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EchoesInventoryComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
