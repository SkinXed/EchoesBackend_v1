// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EchoesCoreTypes.h"
#include "CosmosAttributesComponent.generated.h"

/**
 * Delegate for attributes changed event - used for UI updates
 * Fires on clients when any replicated attribute changes
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAttributesChanged);

/**
 * Delegate for death event
 * @param Victim - The actor that died (owner of this component)
 * @param Killer - The actor that dealt the killing blow (can be nullptr)
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCosmosDeath, AActor*, Victim, AActor*, Killer);

/**
 * UCosmosAttributesComponent
 * 
 * Advanced EVE-like ship/structure attributes component with resistance system
 * Implements three-layer defense with per-damage-type resistances
 * 
 * Architecture:
 * - ActorComponent: Can be attached to ships, stations, structures
 * - Three defense layers: Shield → Armor → Structure (each with 4 resistances)
 * - Replicated: All defense layers and physics stats replicate to clients
 * - Server-authoritative: Damage calculations only on server
 * 
 * Defense Layers (EVE-like with Resistances):
 * 1. Shield: First line of defense, can have different resistances per damage type
 * 2. Armor: Second layer, different resistance profile than shield
 * 3. Structure: Final layer (hull), last resistance profile
 * 
 * Damage Types (ECosmosDamageType):
 * - EM (Electromagnetic): Typically strong vs shields
 * - Thermal: Heat-based damage
 * - Kinetic: Physical projectiles
 * - Explosive: Explosive ordnance
 * - Omni: Pure damage that bypasses all resistances
 * 
 * Damage Flow with Resistances:
 * 1. Apply damage to Shield with Shield's resistances
 * 2. If Shield depleted, apply overflow to Armor with Armor's resistances
 * 3. If Armor depleted, apply overflow to Structure with Structure's resistances
 * 4. If Structure depleted, trigger death event
 * 
 * Example:
 * - 100 EM damage vs Shield with 50% EM resist = 50 damage taken
 * - If Shield had 30 HP, 20 overflow damage goes to Armor
 * - 20 EM damage vs Armor with 25% EM resist = 15 damage taken
 * 
 * Usage:
 * - Attach to ship pawns for combat with resistances
 * - Configure different resistance profiles for different ship types
 * - Server calls ServerOnly_ApplyDamage() when hit
 * - Clients receive updates via replication and update UI
 */
UCLASS(ClassGroup=(Echoes), meta=(BlueprintSpawnableComponent))
class ECHOES_API UCosmosAttributesComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// ==================== Component Lifecycle ====================
	
	UCosmosAttributesComponent();

	// ==================== Replication ====================
	
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// ==================== Defense Stats (Replicated) ====================

	/** Shield defense layer - first line of defense */
	UPROPERTY(ReplicatedUsing = ClientOnly_OnRep_Stats, EditAnywhere, BlueprintReadWrite, Category = "Cosmos|Defense")
	FCosmosDefenseLayer Shield;

	/** Armor defense layer - second line of defense */
	UPROPERTY(ReplicatedUsing = ClientOnly_OnRep_Stats, EditAnywhere, BlueprintReadWrite, Category = "Cosmos|Defense")
	FCosmosDefenseLayer Armor;

	/** Structure defense layer - final line of defense (hull) */
	UPROPERTY(ReplicatedUsing = ClientOnly_OnRep_Stats, EditAnywhere, BlueprintReadWrite, Category = "Cosmos|Defense")
	FCosmosDefenseLayer Structure;

	// ==================== Physics Stats (Replicated) ====================

	/** Ship/structure mass in kilograms */
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Cosmos|Physics")
	float Mass;

	/** Inertia modifier affecting acceleration/deceleration */
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Cosmos|Physics")
	float InertiaModifier;

	/** Cargo bay capacity in cubic meters */
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Cosmos|Physics")
	float CargoCapacity;

	// ==================== Delegates ====================

	/** 
	 * Event broadcast when attributes change - used for UI updates
	 * Fires on clients when replicated values update
	 */
	UPROPERTY(BlueprintAssignable, Category = "Cosmos|Events")
	FOnAttributesChanged OnAttributesChanged;

	/**
	 * Event broadcast when the actor dies (Structure depleted)
	 * Only fires on server, then replicates destruction
	 */
	UPROPERTY(BlueprintAssignable, Category = "Cosmos|Events")
	FOnCosmosDeath OnDeath;

	// ==================== Public Interface ====================

	/**
	 * Apply damage to this actor with resistance mitigation (Server Only)
	 * Implements EVE-like damage cascade with per-layer resistances
	 * 
	 * @param RawDamage - Raw damage amount before mitigation
	 * @param DmgType - Type of damage (EM, Thermal, Kinetic, Explosive, Omni)
	 * @param Instigator - Actor that caused the damage (for kill attribution)
	 * @return True if damage was applied, false if invalid or actor already dead
	 * 
	 * Damage Mitigation Process:
	 * 1. Calculate mitigated damage for Shield: RawDamage * (1.0 - Shield.ResistEM/Thermal/etc)
	 * 2. Apply to Shield, calculate overflow
	 * 3. If overflow > 0, calculate mitigated damage for Armor with Armor's resistances
	 * 4. Apply to Armor, calculate overflow
	 * 5. If overflow > 0, calculate mitigated damage for Structure with Structure's resistances
	 * 6. Apply to Structure
	 * 7. If Structure <= 0, trigger OnDeath event
	 * 
	 * Example:
	 * - 100 Thermal damage
	 * - Shield: 50 HP, 25% Thermal resist → Takes 75 damage (100 * 0.75), depleted, 25 overflow
	 * - Armor: 100 HP, 50% Thermal resist → Takes 12.5 damage (25 * 0.5), 87.5 HP remaining
	 */
	UFUNCTION(BlueprintCallable, Category = "Cosmos")
	bool ServerOnly_ApplyDamage(float RawDamage, ECosmosDamageType DmgType, AActor* Instigator);

	/**
	 * Get shield percentage (Blueprint Pure)
	 * @return Shield percentage from 0.0 to 1.0
	 */
	UFUNCTION(BlueprintPure, Category = "Cosmos")
	float Common_GetShieldPct() const;

	/**
	 * Get armor percentage (Blueprint Pure)
	 * @return Armor percentage from 0.0 to 1.0
	 */
	UFUNCTION(BlueprintPure, Category = "Cosmos")
	float Common_GetArmorPct() const;

	/**
	 * Get structure/hull percentage (Blueprint Pure)
	 * @return Structure percentage from 0.0 to 1.0
	 */
	UFUNCTION(BlueprintPure, Category = "Cosmos")
	float Common_GetHullPct() const;

	/**
	 * Get overall health percentage (all layers combined)
	 * @return Overall health percentage from 0.0 to 1.0
	 */
	UFUNCTION(BlueprintPure, Category = "Cosmos")
	float Common_GetOverallHealthPct() const;

	/**
	 * Check if the actor is alive
	 * @return True if Structure > 0
	 */
	UFUNCTION(BlueprintPure, Category = "Cosmos")
	bool IsAlive() const;

	/**
	 * Fully restore all defense layers to maximum (Server Only)
	 * Useful for respawn or repair mechanics
	 */
	UFUNCTION(BlueprintCallable, Category = "Cosmos")
	void ServerOnly_RestoreAll();

	/**
	 * Set resistances for a specific layer (Server Only)
	 * Useful for module-based resistance bonuses
	 * 
	 * @param LayerIndex - 0=Shield, 1=Armor, 2=Structure
	 * @param EM - EM resistance (0.0 to 1.0)
	 * @param Thermal - Thermal resistance (0.0 to 1.0)
	 * @param Kinetic - Kinetic resistance (0.0 to 1.0)
	 * @param Explosive - Explosive resistance (0.0 to 1.0)
	 */
	UFUNCTION(BlueprintCallable, Category = "Cosmos")
	void ServerOnly_SetLayerResistances(int32 LayerIndex, float EM, float Thermal, float Kinetic, float Explosive);

protected:
	// ==================== Replication Callbacks ====================

	/**
	 * Called on clients when any defense stat is replicated
	 * Triggers UI update via OnAttributesChanged delegate
	 */
	UFUNCTION()
	void ClientOnly_OnRep_Stats();

	// ==================== Internal State ====================

	/** Cached reference to last damage causer for death event */
	UPROPERTY()
	AActor* LastDamageCauser;
};
