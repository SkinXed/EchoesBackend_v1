// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EchoesCoreTypes.h"
#include "CosmosProjectile.generated.h"

// Forward declarations
class UProjectileMovementComponent;
class USphereComponent;
class UStaticMeshComponent;

/**
 * ACosmosProjectile
 * 
 * EVE-like projectile actor for ship weapons
 * Handles ballistic physics, damage application, and visual effects
 * 
 * Architecture:
 * - Spawned by weapon components in deferred mode
 * - Initialized with damage, type, and velocity before finishing spawn
 * - Uses ProjectileMovementComponent for realistic ballistics
 * - Applies typed damage to targets on collision
 * - Server-authoritative hit detection
 * 
 * Lifecycle:
 * 1. SpawnActorDeferred() by weapon
 * 2. InitializeProjectile() sets parameters
 * 3. FinishSpawningActor() completes spawn
 * 4. ProjectileMovementComponent handles flight
 * 5. OnHit() applies damage and destroys projectile
 * 
 * Usage:
 * FActorSpawnParameters SpawnParams;
 * SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
 * ACosmosProjectile* Projectile = GetWorld()->SpawnActorDeferred<ACosmosProjectile>(
 *     ProjectileClass, SpawnTransform, Owner, Instigator, ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
 * Projectile->InitializeProjectile(100.0f, ECosmosDamageType::Kinetic, 1000.0f);
 * UGameplayStatics::FinishSpawningActor(Projectile, SpawnTransform);
 */
UCLASS()
class ECHOES_API ACosmosProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	ACosmosProjectile();

protected:
	virtual void BeginPlay() override;

public:
	// ==================== Components ====================

	/** Collision component for hit detection */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USphereComponent* CollisionComponent;

	/** Visual mesh for the projectile */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* MeshComponent;

	/** Projectile movement component for ballistic physics */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UProjectileMovementComponent* ProjectileMovementComponent;

	// ==================== Projectile Data ====================

	/** Raw damage amount before resistance mitigation */
	UPROPERTY(BlueprintReadOnly, Category = "Projectile")
	float RawDamage;

	/** Type of damage dealt (EM, Thermal, Kinetic, Explosive, Omni) */
	UPROPERTY(BlueprintReadOnly, Category = "Projectile")
	ECosmosDamageType DamageType;

	/** Maximum lifetime in seconds before auto-destruction */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Projectile")
	float MaxLifetime;

	// ==================== Initialization ====================

	/**
	 * Initialize projectile parameters before finishing spawn (Deferred Spawn Pattern)
	 * Called by weapon component after SpawnActorDeferred and before FinishSpawningActor
	 * 
	 * @param NewDamage - Raw damage amount to apply on hit
	 * @param NewType - Type of damage (affects resistance mitigation)
	 * @param NewSpeed - Projectile muzzle velocity in cm/s
	 * 
	 * Example:
	 * Projectile->InitializeProjectile(150.0f, ECosmosDamageType::Kinetic, 100000.0f);
	 */
	UFUNCTION(BlueprintCallable, Category = "Projectile")
	void InitializeProjectile(float NewDamage, ECosmosDamageType NewType, float NewSpeed);

protected:
	// ==================== Collision Handling ====================

	/**
	 * Called when projectile hits something
	 * Applies damage to target and destroys projectile
	 */
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
		FVector NormalImpulse, const FHitResult& Hit);

	/**
	 * Timer handle for auto-destruction after lifetime expires
	 */
	FTimerHandle LifetimeTimerHandle;

	/**
	 * Auto-destroy projectile after max lifetime
	 */
	void OnLifetimeExpired();
};
