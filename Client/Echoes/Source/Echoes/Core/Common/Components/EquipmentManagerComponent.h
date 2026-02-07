// Copyright Epic Games, Inc. All Rights Reserved.
// Echoes - EVE-like MMO
// Equipment Manager Component - Server-authoritative module activation and management

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Core/Common/Interfaces/ShipFittingInterface.h"
#include "Core/Common/Types/EchoesGameState.h"
#include "Net/UnrealNetwork.h"
#include "EquipmentManagerComponent.generated.h"

/**
 * Equipment Manager Component
 * Server-authoritative component that manages ship equipment activation
 * Handles capacitor costs, ammunition consumption, cooldowns, and targeting requirements
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ECHOES_API UEquipmentManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UEquipmentManagerComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
	virtual void BeginPlay() override;

public:
	// ============================================================================
	// REPLICATED STATE
	// ============================================================================

	/** Current ship fitting data (replicated to clients) */
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Equipment")
	FCommon_ShipFittingData CurrentFitting;

	/** Current capacitor energy */
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Equipment")
	float CurrentCapacitor;

	/** Maximum capacitor energy */
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Equipment")
	float MaxCapacitor;

	// ============================================================================
	// CONFIGURATION
	// ============================================================================

	/** Capacitor recharge rate (per second) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Equipment")
	float CapacitorRechargeRate = 10.0f;

	/** Default weapon range (cm) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Equipment")
	float DefaultWeaponRange = 2500000.0f; // 25km

	// ============================================================================
	// SERVER RPC (Commands from client)
	// ============================================================================

	/**
	 * Toggle Module Activation
	 * Server-authoritative module activation with full validation
	 * Checks: Capacitor, Ammo, Range, Cooldown, Target (if needed)
	 */
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "Equipment")
	void ServerRPC_ToggleModule(ESlotType SlotType, int32 SlotIndex);

	/**
	 * Deactivate All Modules
	 * Emergency stop for all active modules
	 */
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "Equipment")
	void ServerRPC_DeactivateAll();

	/**
	 * Set Module Overload State
	 * Enable/disable overload for a module (increased performance, risk of damage)
	 */
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "Equipment")
	void ServerRPC_SetOverload(ESlotType SlotType, int32 SlotIndex, bool bOverload);

	// ============================================================================
	// CLIENT RPC (Notifications to client)
	// ============================================================================

	/**
	 * Notify Module Activation Result
	 * Informs client of activation success/failure
	 */
	UFUNCTION(Client, Reliable, Category = "Equipment")
	void ClientRPC_NotifyModuleActivation(ESlotType SlotType, int32 SlotIndex, EModuleActivationResult Result);

	/**
	 * Notify Module State Changed
	 * Informs client of module state update
	 */
	UFUNCTION(Client, Reliable, Category = "Equipment")
	void ClientRPC_NotifyModuleState(ESlotType SlotType, int32 SlotIndex, EModuleState NewState);

	/**
	 * Sync Fitting Data
	 * Sends complete fitting data to newly connected client
	 */
	UFUNCTION(Client, Reliable, Category = "Equipment")
	void ClientRPC_SyncFitting(const FCommon_ShipFittingData& FittingData);

	// ============================================================================
	// COMMON FUNCTIONS (Pure helpers)
	// ============================================================================

	/**
	 * Get Module Slot
	 * Returns slot data for a specific module
	 */
	UFUNCTION(BlueprintPure, Category = "Equipment")
	FCommon_ItemSlot Common_GetModuleSlot(ESlotType SlotType, int32 SlotIndex) const;

	/**
	 * Can Activate Module
	 * Checks if a module can be activated (without actually activating it)
	 */
	UFUNCTION(BlueprintPure, Category = "Equipment")
	EModuleActivationResult Common_CanActivateModule(ESlotType SlotType, int32 SlotIndex) const;

	/**
	 * Get Capacitor Percentage
	 */
	UFUNCTION(BlueprintPure, Category = "Equipment")
	float Common_GetCapacitorPercentage() const;

	// ============================================================================
	// DELEGATES
	// ============================================================================

	/** Fired when module state changes */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnModuleStateChanged, ESlotType, SlotType, int32, SlotIndex, EModuleState, NewState);
	UPROPERTY(BlueprintAssignable, Category = "Equipment")
	FOnModuleStateChanged OnModuleStateChanged;

	/** Fired when capacitor changes */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCapacitorChanged, float, Current, float, Max);
	UPROPERTY(BlueprintAssignable, Category = "Equipment")
	FOnCapacitorChanged OnCapacitorChanged;

	/** Fired when equipment changes (for IEquipmentObserver implementations) */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEquipmentChanged);
	UPROPERTY(BlueprintAssignable, Category = "Equipment")
	FOnEquipmentChanged OnEquipmentChanged;

private:
	// ============================================================================
	// INTERNAL IMPLEMENTATION
	// ============================================================================

	/**
	 * Server Only - Activate Module
	 * Internal implementation of module activation
	 */
	EModuleActivationResult ServerOnly_ActivateModule(FCommon_ItemSlot& Slot, ESlotType SlotType, int32 SlotIndex);

	/**
	 * Server Only - Deactivate Module
	 */
	void ServerOnly_DeactivateModule(FCommon_ItemSlot& Slot, ESlotType SlotType, int32 SlotIndex);

	/**
	 * Server Only - Check Capacitor Cost
	 */
	bool ServerOnly_CheckCapacitor(float Cost);

	/**
	 * Server Only - Consume Capacitor
	 */
	void ServerOnly_ConsumeCapacitor(float Amount);

	/**
	 * Server Only - Check Ammunition
	 */
	bool ServerOnly_CheckAmmo(FCommon_ItemSlot& Slot);

	/**
	 * Server Only - Consume Ammunition
	 */
	void ServerOnly_ConsumeAmmo(FCommon_ItemSlot& Slot);

	/**
	 * Server Only - Check Target Range
	 */
	bool ServerOnly_CheckRange(ESlotType SlotType, int32 SlotIndex);

	/**
	 * Server Only - Check if Module is Weapon
	 */
	bool ServerOnly_IsWeaponModule(ESlotType SlotType, const FCommon_ItemSlot& Slot) const;

	/**
	 * Server Only - Get Module Range
	 */
	float ServerOnly_GetModuleRange(const FCommon_ItemSlot& Slot) const;

	/**
	 * Server Only - Get Current Target
	 */
	AActor* ServerOnly_GetCurrentTarget() const;

	/**
	 * Server Only - Update Cooldowns
	 */
	void ServerOnly_UpdateCooldowns(float DeltaTime);

	/**
	 * Server Only - Recharge Capacitor
	 */
	void ServerOnly_RechargeCapacitor(float DeltaTime);

	/**
	 * Get Mutable Slot Reference
	 */
	FCommon_ItemSlot* GetMutableSlot(ESlotType SlotType, int32 SlotIndex);

	/**
	 * Get Slot Array for Type
	 */
	TArray<FCommon_ItemSlot>* GetSlotArray(ESlotType SlotType);

	/** Cached references */
	UPROPERTY()
	APawn* CachedOwnerPawn;

	UPROPERTY()
	APlayerController* CachedPlayerController;
};
