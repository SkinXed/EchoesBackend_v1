// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "EchoesCoreTypes.h"
#include "CosmosWeaponComponent.generated.h"

// Forward declarations
class ACosmosProjectile;

/**
 * UCosmosWeaponComponent
 * 
 * EVE-like weapon component for ship-mounted turrets and launchers
 * Handles target prediction, fire rate, and projectile spawning
 * 
 * Architecture:
 * - SceneComponent: Attached to ship at weapon mount point (muzzle socket)
 * - Server-authoritative: Only server can fire weapons
 * - Target prediction: Calculates lead point for moving targets
 * - Deferred spawning: Initializes projectiles before completing spawn
 * 
 * Weapon Stats:
 * - BaseDamage: Raw damage before resistance mitigation
 * - DamageType: Type of damage (EM, Thermal, Kinetic, Explosive, Omni)
 * - MuzzleVelocity: Projectile speed in cm/s (for prediction calculations)
 * - FireRate: Shots per second (cooldown management)
 * 
 * Target Prediction:
 * Uses First-Order Intercept algorithm to calculate where to aim
 * Accounts for target velocity and projectile speed
 * Returns prediction point in world space
 * 
 * Fire Sequence:
 * 1. Check fire rate cooldown
 * 2. Calculate prediction point
 * 3. Spawn projectile (deferred)
 * 4. Initialize projectile with damage/type/speed
 * 5. Finish spawning projectile
 * 6. Start cooldown timer
 * 
 * Usage:
 * // Attach weapon to ship
 * WeaponComp->AttachToComponent(ShipMesh, FAttachmentTransformRules::SnapToTargetIncludingScale, 
 *     TEXT("WeaponSocket_01"));
 * 
 * // Fire at target
 * WeaponComp->ServerOnly_Fire(TargetShip);
 */
UCLASS(ClassGroup=(Echoes), meta=(BlueprintSpawnableComponent))
class ECHOES_API UCosmosWeaponComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	UCosmosWeaponComponent();

protected:
	virtual void BeginPlay() override;

public:
	// ==================== Weapon Statistics ====================

	/** Projectile class to spawn when firing */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Stats")
	TSubclassOf<ACosmosProjectile> ProjectileClass;

	/** Base damage dealt by this weapon (before resistance mitigation) */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Stats")
	float BaseDamage;

	/** Type of damage dealt by this weapon */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Stats")
	ECosmosDamageType DamageType;

	/** Projectile muzzle velocity in cm/s (1000 m/s = 100000 cm/s) */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Stats")
	float MuzzleVelocity;

	/** Rate of fire in shots per second */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Stats", meta = (ClampMin = "0.1", ClampMax = "10.0"))
	float FireRate;

	// ==================== Target Prediction ====================

	/**
	 * Calculate prediction point for target leading (First-Order Intercept)
	 * Pure math function - works on server and client
	 * 
	 * @param Target - Actor to predict position for
	 * @return Predicted world position where target will be when projectile arrives
	 * 
	 * Algorithm:
	 * 1. Get relative position and velocity vectors
	 * 2. Solve quadratic equation for intercept time
	 * 3. Calculate predicted position = current + velocity * time
	 * 4. Return predicted point or current position if no solution
	 * 
	 * Math:
	 * Let t = time to intercept
	 * Target position: Pt = P0 + Vt * t
	 * Projectile travel: |Pt - Pw| = Vp * t
	 * Solve for t, then calculate Pt
	 * 
	 * Example:
	 * FVector PredictionPoint = WeaponComp->Common_GetPredictionLocation(TargetShip);
	 * AimDirection = (PredictionPoint - WeaponComp->GetComponentLocation()).GetSafeNormal();
	 */
	UFUNCTION(BlueprintPure, Category = "Weapon")
	FVector Common_GetPredictionLocation(AActor* Target) const;

	// ==================== Firing ====================

	/**
	 * Fire weapon at target (Server Only)
	 * Checks cooldown, spawns projectile with prediction
	 * 
	 * @param Target - Actor to fire at (can be nullptr for dumbfire)
	 * 
	 * Behavior:
	 * - Validates server authority
	 * - Checks fire rate cooldown
	 * - Calculates prediction point if target provided
	 * - Spawns projectile (deferred)
	 * - Initializes projectile with weapon stats
	 * - Finishes spawning projectile
	 * - Starts cooldown timer
	 * 
	 * Example:
	 * if (HasAuthority())
	 * {
	 *     WeaponComp->ServerOnly_Fire(EnemyShip);
	 * }
	 */
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void ServerOnly_Fire(AActor* Target);

	/**
	 * Check if weapon is ready to fire (cooldown expired)
	 * 
	 * @return True if cooldown has expired
	 */
	UFUNCTION(BlueprintPure, Category = "Weapon")
	bool CanFire() const;

	/**
	 * Get current cooldown remaining in seconds
	 * 
	 * @return Seconds until weapon can fire again (0.0 if ready)
	 */
	UFUNCTION(BlueprintPure, Category = "Weapon")
	float GetCooldownRemaining() const;

protected:
	// ==================== Internal State ====================

	/** Time when weapon can next fire */
	float NextFireTime;

	/**
	 * Calculate time to intercept for target prediction
	 * Helper function for Common_GetPredictionLocation
	 * 
	 * @param RelativePosition - Target position relative to weapon
	 * @param RelativeVelocity - Target velocity relative to weapon
	 * @return Time to intercept in seconds, or -1.0 if no solution
	 */
	float CalculateInterceptTime(const FVector& RelativePosition, const FVector& RelativeVelocity) const;
};
