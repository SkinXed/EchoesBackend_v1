// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoonActor.generated.h"

/**
 * AMoonActor
 * 
 * Represents a moon/satellite in the Echoes universe
 * Spawned by AEchoesWorldGenerator as children of planets
 * 
 * Features:
 * - Server-side spawning with replication
 * - Orbital visualization around parent planet
 * - Seed-based variation for unique appearance
 */
UCLASS()
class ECHOES_API AMoonActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AMoonActor();

protected:
	virtual void BeginPlay() override;

public:
	// ==================== Initialization ====================

	/**
	 * Initialize moon from configuration data
	 * Called by WorldGenerator after spawning
	 * 
	 * @param InMoonId - Unique moon ID from database
	 * @param InName - Moon name
	 * @param InType - Moon type (e.g., "Rocky", "Ice", "Volcanic")
	 * @param InOrbitRadius - Distance from parent planet in km
	 * @param InSeed - Seed for procedural variation
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Moon")
	void InitializeMoon(
		const FGuid& InMoonId,
		const FString& InName,
		const FString& InType,
		float InOrbitRadius,
		int32 InSeed);

	// ==================== Orbit Visualization ====================

	/**
	 * Set orbit parameters for this moon (called by WorldGenerator)
	 * @param InOrbitRadius - Distance from parent planet in km
	 * @param InParentLocation - Parent planet's world location
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Moon|Orbit")
	void SetOrbitParameters(float InOrbitRadius, const FVector& InParentLocation);

	/**
	 * Create and draw the orbital path around parent planet (client-only)
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Moon|Orbit")
	void ClientOnly_DrawOrbit();

	// ==================== Getters ====================

	UFUNCTION(BlueprintPure, Category = "Echoes|Moon")
	FGuid GetMoonId() const { return MoonId; }

	UFUNCTION(BlueprintPure, Category = "Echoes|Moon")
	FString GetMoonName() const { return MoonName; }

	UFUNCTION(BlueprintPure, Category = "Echoes|Moon")
	FString GetMoonType() const { return MoonType; }

	UFUNCTION(BlueprintPure, Category = "Echoes|Moon")
	float GetOrbitRadius() const { return OrbitRadius; }

protected:
	// ==================== Components ====================

	/** Moon mesh component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* MoonMeshComponent;

	/** Orbit spline component (client-only, for visual orbit path) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components|Orbit")
	class USplineComponent* OrbitSplineComponent;

	// ==================== Moon Data (Replicated) ====================

	/** Unique moon ID from database */
	UPROPERTY(ReplicatedUsing = OnRep_MoonData, BlueprintReadOnly, Category = "Moon")
	FGuid MoonId;

	/** Moon name */
	UPROPERTY(ReplicatedUsing = OnRep_MoonData, BlueprintReadOnly, Category = "Moon")
	FString MoonName;

	/** Moon type (e.g., "Rocky", "Ice", "Volcanic") */
	UPROPERTY(ReplicatedUsing = OnRep_MoonData, BlueprintReadOnly, Category = "Moon")
	FString MoonType;

	/** Orbit radius (distance from parent planet) in km */
	UPROPERTY(ReplicatedUsing = OnRep_MoonData, BlueprintReadOnly, Category = "Moon")
	float OrbitRadius = 0.0f;

	/** Seed for procedural variation */
	UPROPERTY(ReplicatedUsing = OnRep_MoonData, BlueprintReadOnly, Category = "Moon")
	int32 Seed = 0;

	// ==================== Orbit Data ====================

	/** Parent planet's world location (for orbit visualization) */
	UPROPERTY(BlueprintReadOnly, Category = "Moon|Orbit")
	FVector ParentLocation = FVector::ZeroVector;

	// ==================== Replication ====================

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION()
	void OnRep_MoonData();

private:
	/** Apply visual configuration */
	void ApplyVisualConfiguration();
};
