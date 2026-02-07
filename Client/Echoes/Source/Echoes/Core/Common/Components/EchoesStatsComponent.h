// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EchoesStatsComponent.generated.h"

/**
 * Delegate for stats changed event - used for UI updates
 * @param ShieldPct - Shield percentage (0.0 to 1.0)
 * @param ArmorPct - Armor percentage (0.0 to 1.0)
 * @param StructPct - Structure percentage (0.0 to 1.0)
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnStatsChanged, float, ShieldPct, float, ArmorPct, float, StructPct);

/**
 * Delegate for death event
 * @param Victim - The actor that died (owner of this component)
 * @param Killer - The actor that dealt the killing blow (can be nullptr)
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDeath, AActor*, Victim, AActor*, Killer);

/**
 * UEchoesStatsComponent
 * 
 * EVE-like ship/structure survivability component for Echoes MMO
 * Manages three-layer protection system with replication for multiplayer
 * 
 * Architecture:
 * - ActorComponent: Can be attached to ships, stations, structures
 * - Three protection layers: Shield → Armor → Structure
 * - Replicated: All Current values replicate to clients for UI updates
 * - Server-authoritative: Damage calculations only on server
 * 
 * Protection Layers (EVE-like):
 * 1. Shield: First line of defense, regenerates passively over time
 * 2. Armor: Second layer, does not regenerate automatically
 * 3. Structure: Final layer (hull), destruction when depleted
 * 
 * Damage Flow:
 * Damage → Shield (if > 0) → Armor (if shield depleted) → Structure (if armor depleted) → Death
 * 
 * Usage:
 * - Attach to ship pawns for combat survivability
 * - Attach to station actors for destructible structures
 * - Server calls ServerOnly_ApplyDamage() when hit
 * - Clients receive updates via replication and update UI
 */
UCLASS(ClassGroup=(Echoes), meta=(BlueprintSpawnableComponent))
class ECHOES_API UEchoesStatsComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// ==================== Component Lifecycle ====================
	
	UEchoesStatsComponent();
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// ==================== Replication ====================
	
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// ==================== Shield Layer ====================

	/** Current shield hit points */
	UPROPERTY(ReplicatedUsing = ClientOnly_OnRep_UpdateUI, BlueprintReadOnly, Category = "Stats|Shield")
	float ShieldCurrent;

	/** Maximum shield hit points */
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Stats|Shield")
	float ShieldMax;

	/** Shield regeneration rate (HP per second) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats|Shield")
	float ShieldRegenRate;

	/** Delay before shield starts regenerating after taking damage (seconds) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats|Shield")
	float ShieldRegenDelay;

	// ==================== Armor Layer ====================

	/** Current armor hit points */
	UPROPERTY(ReplicatedUsing = ClientOnly_OnRep_UpdateUI, BlueprintReadOnly, Category = "Stats|Armor")
	float ArmorCurrent;

	/** Maximum armor hit points */
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Stats|Armor")
	float ArmorMax;

	// ==================== Structure Layer ====================

	/** Current structure (hull) hit points */
	UPROPERTY(ReplicatedUsing = ClientOnly_OnRep_UpdateUI, BlueprintReadOnly, Category = "Stats|Structure")
	float StructureCurrent;

	/** Maximum structure (hull) hit points */
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Stats|Structure")
	float StructureMax;

	// ==================== Delegates ====================

	/** 
	 * Event broadcast when stats change - used for UI updates
	 * Fires on clients when replicated values update
	 */
	UPROPERTY(BlueprintAssignable, Category = "Stats|Events")
	FOnStatsChanged OnStatsChanged;

	/**
	 * Event broadcast when the actor dies (Structure depleted)
	 * Only fires on server, then replicates destruction
	 */
	UPROPERTY(BlueprintAssignable, Category = "Stats|Events")
	FOnDeath OnDeath;

	// ==================== Public Interface ====================

	/**
	 * Apply damage to this actor (Server Only)
	 * Implements EVE-like damage cascade: Shield → Armor → Structure
	 * 
	 * @param Amount - Amount of damage to apply
	 * @param DamageCauser - Optional actor that caused the damage (for kill attribution)
	 * 
	 * Behavior:
	 * - Damage first depletes Shield
	 * - Overflow damage goes to Armor
	 * - Overflow from Armor goes to Structure
	 * - When Structure <= 0, triggers OnDeath event
	 * - Resets shield regeneration timer
	 */
	UFUNCTION(BlueprintCallable, Category = "Stats")
	void ServerOnly_ApplyDamage(float Amount, AActor* DamageCauser = nullptr);

	/**
	 * Get overall health percentage (Blueprint Pure)
	 * Useful for simplified health bars above enemies
	 * 
	 * @return Health percentage from 0.0 to 1.0 (0% to 100%)
	 * 
	 * Calculation: (ShieldCurrent + ArmorCurrent + StructureCurrent) / (ShieldMax + ArmorMax + StructureMax)
	 */
	UFUNCTION(BlueprintPure, Category = "Stats")
	float Common_GetHealthPercentage() const;

	/**
	 * Get shield percentage (Blueprint Pure)
	 * @return Shield percentage from 0.0 to 1.0
	 */
	UFUNCTION(BlueprintPure, Category = "Stats")
	float Common_GetShieldPercentage() const;

	/**
	 * Get armor percentage (Blueprint Pure)
	 * @return Armor percentage from 0.0 to 1.0
	 */
	UFUNCTION(BlueprintPure, Category = "Stats")
	float Common_GetArmorPercentage() const;

	/**
	 * Get structure percentage (Blueprint Pure)
	 * @return Structure percentage from 0.0 to 1.0
	 */
	UFUNCTION(BlueprintPure, Category = "Stats")
	float Common_GetStructurePercentage() const;

	/**
	 * Check if the actor is alive
	 * @return True if Structure > 0
	 */
	UFUNCTION(BlueprintPure, Category = "Stats")
	bool IsAlive() const;

	/**
	 * Fully restore all stats to maximum (Server Only)
	 * Useful for respawn or repair mechanics
	 */
	UFUNCTION(BlueprintCallable, Category = "Stats")
	void ServerOnly_RestoreAll();

protected:
	// ==================== Replication Callbacks ====================

	/**
	 * Called on clients when any Current stat is replicated
	 * Triggers UI update via OnStatsChanged delegate
	 */
	UFUNCTION()
	void ClientOnly_OnRep_UpdateUI();

	// ==================== Internal State ====================

	/** Time since last damage taken (for shield regeneration) */
	float TimeSinceLastDamage;

	/** Cached reference to damage causer for death event */
	UPROPERTY()
	AActor* LastDamageCauser;
};
