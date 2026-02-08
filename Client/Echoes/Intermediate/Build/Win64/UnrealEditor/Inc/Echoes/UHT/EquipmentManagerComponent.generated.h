// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Common/Components/EquipmentManagerComponent.h"

#ifdef ECHOES_EquipmentManagerComponent_generated_h
#error "EquipmentManagerComponent.generated.h already included, missing '#pragma once' in EquipmentManagerComponent.h"
#endif
#define ECHOES_EquipmentManagerComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

enum class EModuleActivationResult : uint8;
enum class EModuleState : uint8;
enum class ESlotType : uint8;
struct FCommon_ItemSlot;
struct FCommon_ShipFittingData;

// ********** Begin Delegate FOnModuleStateChanged *************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EquipmentManagerComponent_h_142_DELEGATE \
static void FOnModuleStateChanged_DelegateWrapper(const FMulticastScriptDelegate& OnModuleStateChanged, ESlotType SlotType, int32 SlotIndex, EModuleState NewState);


// ********** End Delegate FOnModuleStateChanged ***************************************************

// ********** Begin Delegate FOnCapacitorChanged ***************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EquipmentManagerComponent_h_147_DELEGATE \
static void FOnCapacitorChanged_DelegateWrapper(const FMulticastScriptDelegate& OnCapacitorChanged, float Current, float Max);


// ********** End Delegate FOnCapacitorChanged *****************************************************

// ********** Begin Delegate FOnEquipmentChanged ***************************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EquipmentManagerComponent_h_152_DELEGATE \
static void FOnEquipmentChanged_DelegateWrapper(const FMulticastScriptDelegate& OnEquipmentChanged);


// ********** End Delegate FOnEquipmentChanged *****************************************************

// ********** Begin Class UEquipmentManagerComponent ***********************************************
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EquipmentManagerComponent_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void ClientRPC_SyncFitting_Implementation(FCommon_ShipFittingData const& FittingData); \
	virtual void ClientRPC_NotifyModuleState_Implementation(ESlotType SlotType, int32 SlotIndex, EModuleState NewState); \
	virtual void ClientRPC_NotifyModuleActivation_Implementation(ESlotType SlotType, int32 SlotIndex, EModuleActivationResult Result); \
	virtual void ServerRPC_SetOverload_Implementation(ESlotType SlotType, int32 SlotIndex, bool bOverload); \
	virtual void ServerRPC_DeactivateAll_Implementation(); \
	virtual void ServerRPC_ToggleModule_Implementation(ESlotType SlotType, int32 SlotIndex); \
	DECLARE_FUNCTION(execCommon_GetCapacitorPercentage); \
	DECLARE_FUNCTION(execCommon_CanActivateModule); \
	DECLARE_FUNCTION(execCommon_GetModuleSlot); \
	DECLARE_FUNCTION(execClientRPC_SyncFitting); \
	DECLARE_FUNCTION(execClientRPC_NotifyModuleState); \
	DECLARE_FUNCTION(execClientRPC_NotifyModuleActivation); \
	DECLARE_FUNCTION(execServerRPC_SetOverload); \
	DECLARE_FUNCTION(execServerRPC_DeactivateAll); \
	DECLARE_FUNCTION(execServerRPC_ToggleModule);


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EquipmentManagerComponent_h_22_CALLBACK_WRAPPERS
ECHOES_API UClass* Z_Construct_UClass_UEquipmentManagerComponent_NoRegister();

#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EquipmentManagerComponent_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEquipmentManagerComponent(); \
	friend struct Z_Construct_UClass_UEquipmentManagerComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ECHOES_API UClass* Z_Construct_UClass_UEquipmentManagerComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UEquipmentManagerComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Echoes"), Z_Construct_UClass_UEquipmentManagerComponent_NoRegister) \
	DECLARE_SERIALIZER(UEquipmentManagerComponent) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		CurrentFitting=NETFIELD_REP_START, \
		CurrentCapacitor, \
		MaxCapacitor, \
		NETFIELD_REP_END=MaxCapacitor	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API)


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EquipmentManagerComponent_h_22_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UEquipmentManagerComponent(UEquipmentManagerComponent&&) = delete; \
	UEquipmentManagerComponent(const UEquipmentManagerComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEquipmentManagerComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEquipmentManagerComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UEquipmentManagerComponent) \
	NO_API virtual ~UEquipmentManagerComponent();


#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EquipmentManagerComponent_h_19_PROLOG
#define FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EquipmentManagerComponent_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EquipmentManagerComponent_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EquipmentManagerComponent_h_22_CALLBACK_WRAPPERS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EquipmentManagerComponent_h_22_INCLASS_NO_PURE_DECLS \
	FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EquipmentManagerComponent_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UEquipmentManagerComponent;

// ********** End Class UEquipmentManagerComponent *************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_EquipmentManagerComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
