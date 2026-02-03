// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EchoesWorldVisualTypes.h"
#include "PlanetActor.generated.h"

/**
 * APlanetActor
 * 
 * Represents a planet in the Echoes universe
 * Spawned by AEchoesWorldGenerator based on backend configuration
 * Supports seed-based visual variation and procedural generation
 * 
 * Features:
 * - Server-side spawning with replication
 * - Seed-based variation for unique appearance
 * - Async asset loading for optimization
 * - Atmosphere and cloud layers
 * - Material parameter randomization
 */
UCLASS()
class ECHOES_API APlanetActor : public AActor
{
	GENERATED_BODY()
	
public:	
	APlanetActor();

protected:
	virtual void BeginPlay() override;

public:
	// ==================== Initialization ====================

	/**
	 * Initialize planet from configuration data
	 * Called by WorldGenerator after spawning
	 * 
	 * @param InPlanetId - Unique planet ID from database
	 * @param InName - Planet name
	 * @param InType - Planet type (e.g., "Lava", "Oceanic", "Barren")
	 * @param InRadius - Planet radius in km
	 * @param InSeed - Seed for procedural variation
	 * @param InVisualData - Visual configuration from data table
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Planet")
	void InitializePlanet(
		const FGuid& InPlanetId,
		const FString& InName,
		const FString& InType,
		float InRadius,
		int32 InSeed,
		const FPlanetVisualRow& InVisualData);

	/**
	 * Apply seed-based variation to visual appearance
	 * Uses the seed to:
	 * - Select one material from the array
	 * - Adjust rotation
	 * - Modify atmosphere intensity
	 * - Randomize texture parameters
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Planet")
	void ApplySeedVariation();

	// ==================== Orbit Visualization ====================

	/**
	 * Set orbit parameters for this planet (called by WorldGenerator)
	 * @param InOrbitDistance - Distance from star in km
	 * @param InSystemOffset - Global offset for regional cluster mode
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Planet|Orbit")
	void SetOrbitParameters(float InOrbitDistance, const FVector& InSystemOffset);

	/**
	 * Create and draw the orbital path (client-only)
	 * Should be called after SetOrbitParameters
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Planet|Orbit")
	void ClientOnly_DrawOrbit();

	// ==================== Getters ====================

	UFUNCTION(BlueprintPure, Category = "Echoes|Planet")
	FGuid GetPlanetId() const { return PlanetId; }

	UFUNCTION(BlueprintPure, Category = "Echoes|Planet")
	FString GetPlanetName() const { return PlanetName; }

	UFUNCTION(BlueprintPure, Category = "Echoes|Planet")
	FString GetPlanetType() const { return PlanetType; }

	UFUNCTION(BlueprintPure, Category = "Echoes|Planet")
	float GetRadius() const { return Radius; }

	UFUNCTION(BlueprintPure, Category = "Echoes|Planet")
	int32 GetSeed() const { return Seed; }

protected:
	// ==================== Components ====================

	/** Planet mesh component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* PlanetMeshComponent;

	/** Cloud layer mesh component (optional) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* CloudLayerComponent;

	/** Atmosphere mesh component (optional) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* AtmosphereComponent;

	/** Ring mesh component (optional, for gas giants) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* RingComponent;

	/** Orbit spline component (client-only, for visual orbit path) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components|Orbit")
	class USplineComponent* OrbitSplineComponent;

	/** Orbit mesh component (renders the orbit spline, client-only) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components|Orbit")
	class USplineMeshComponent* OrbitMeshComponent;

	// ==================== Planet Data (Replicated) ====================

	/** Unique planet ID from database */
	UPROPERTY(ReplicatedUsing = OnRep_PlanetData, BlueprintReadOnly, Category = "Planet")
	FGuid PlanetId;

	/** Planet name */
	UPROPERTY(ReplicatedUsing = OnRep_PlanetData, BlueprintReadOnly, Category = "Planet")
	FString PlanetName;

	/** Planet type (e.g., "Lava", "Oceanic", "Barren") */
	UPROPERTY(ReplicatedUsing = OnRep_PlanetData, BlueprintReadOnly, Category = "Planet")
	FString PlanetType;

	/** Planet radius in km */
	UPROPERTY(ReplicatedUsing = OnRep_PlanetData, BlueprintReadOnly, Category = "Planet")
	float Radius;

	/** Seed for procedural variation */
	UPROPERTY(ReplicatedUsing = OnRep_PlanetData, BlueprintReadOnly, Category = "Planet")
	int32 Seed;

	/** Visual configuration data */
	UPROPERTY(BlueprintReadOnly, Category = "Planet")
	FPlanetVisualRow VisualData;

	// ==================== Orbit Data ====================

	/** Distance from star (orbit radius) in km */
	UPROPERTY(BlueprintReadOnly, Category = "Planet|Orbit")
	float OrbitDistance = 0.0f;

	/** System global offset (for regional cluster mode) */
	UPROPERTY(BlueprintReadOnly, Category = "Planet|Orbit")
	FVector SystemOffset = FVector::ZeroVector;

	// ==================== Replication ====================

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION()
	void OnRep_PlanetData();

private:
	/** Cloud layer rotation timer */
	FTimerHandle CloudRotationTimerHandle;

	/** Update cloud layer rotation */
	void UpdateCloudRotation();

	/** Apply visual configuration */
	void ApplyVisualConfiguration();

	/** Create dynamic material instances for seed-based variation */
	void CreateDynamicMaterials();
};
