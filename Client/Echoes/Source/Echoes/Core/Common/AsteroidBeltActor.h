// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EchoesWorldVisualTypes.h"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"
#include "AsteroidBeltActor.generated.h"

/**
 * AAsteroidBeltActor
 * 
 * Represents an asteroid belt in a solar system
 * Uses Hierarchical Instanced Static Mesh Component (HISM) for efficient rendering
 * Supports procedural placement based on seed for deterministic generation
 * Individual asteroids have collision for mining gameplay
 * 
 * Key Features:
 * - Optimized rendering with HISM (thousands of asteroids with minimal performance cost)
 * - Procedural distribution using seed from database
 * - Resource information for mining gameplay
 * - Collision detection for asteroid-ship interactions
 * - VFX for dust clouds and ambient effects
 */
UCLASS()
class ECHOES_API AAsteroidBeltActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AAsteroidBeltActor();

protected:
	virtual void BeginPlay() override;

public:
	/**
	 * Initialize asteroid belt from server configuration
	 * 
	 * @param BeltId - Unique identifier of the belt
	 * @param BeltName - Name of the belt
	 * @param Seed - Procedural generation seed (from database)
	 * @param BeltRadius - Radius of the belt in world units
	 * @param AsteroidCount - Number of asteroids to spawn
	 * @param VisualData - Visual configuration from data table
	 */
	UFUNCTION(BlueprintCallable, Category = "AsteroidBelt")
	void InitializeAsteroidBelt(
		const FGuid& BeltId,
		const FString& BeltName,
		int32 Seed,
		float BeltRadius,
		int32 AsteroidCount,
		const FAsteroidBeltVisualRow& VisualData);

	/**
	 * Get the belt's unique ID
	 */
	UFUNCTION(BlueprintPure, Category = "AsteroidBelt")
	FGuid GetBeltId() const { return BeltId; }

	/**
	 * Get the belt's name
	 */
	UFUNCTION(BlueprintPure, Category = "AsteroidBelt")
	FString GetBeltName() const { return BeltName; }

protected:
	/**
	 * Generate procedural asteroid positions within the belt
	 * Uses ring/cloud distribution pattern
	 */
	void GenerateAsteroidPositions(int32 AsteroidCount, float BeltRadius, int32 Seed);

	/**
	 * Setup collision for individual asteroids
	 */
	void SetupAsteroidCollision();

	/**
	 * Spawn environmental effects (dust clouds, etc.)
	 */
	void SpawnEnvironmentalEffects(const FAsteroidBeltVisualRow& VisualData);

private:
	// ==================== Components ====================

	/** Root scene component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* RootSceneComponent;

	/** Hierarchical Instanced Static Mesh Component for asteroids (highly optimized) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UHierarchicalInstancedStaticMeshComponent* AsteroidInstances;

	/** Optional: Niagara component for dust cloud effects */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UNiagaraComponent* DustCloudComponent;

	/** Audio component for ambient sound */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UAudioComponent* AmbientAudioComponent;

	// ==================== Configuration ====================

	/** Unique ID of this asteroid belt */
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = "AsteroidBelt", meta = (AllowPrivateAccess = "true"))
	FGuid BeltId;

	/** Name of the asteroid belt */
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = "AsteroidBelt", meta = (AllowPrivateAccess = "true"))
	FString BeltName;

	/** Procedural generation seed */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AsteroidBelt", meta = (AllowPrivateAccess = "true"))
	int32 GenerationSeed;

	/** Belt radius in world units */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AsteroidBelt", meta = (AllowPrivateAccess = "true"))
	float Radius;

	/** Number of asteroids in the belt */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AsteroidBelt", meta = (AllowPrivateAccess = "true"))
	int32 AsteroidCount;

	// ==================== Replication ====================

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
