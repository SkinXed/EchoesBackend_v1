// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EchoesWorldVisualTypes.h"
#include "WormholeActor.generated.h"

/**
 * AWormholeActor
 * 
 * Represents a wormhole connection between solar systems
 * Features spatial distortion effects and jump trigger zones
 * Color and effects vary based on destination system
 * 
 * Key Features:
 * - Unique visual appearance based on TargetSystemId
 * - Trigger zone for initiating jumps to target system
 * - Spatial distortion post-process effects
 * - Entry/exit sound effects
 * - Stability indicators (VFX intensity)
 */
UCLASS()
class ECHOES_API AWormholeActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AWormholeActor();

protected:
	virtual void BeginPlay() override;

public:
	/**
	 * Initialize wormhole from server configuration
	 * 
	 * @param WormholeId - Unique identifier of the wormhole
	 * @param WormholeName - Name of the wormhole
	 * @param TargetSystemId - Destination solar system ID
	 * @param Seed - Procedural generation seed
	 * @param VisualData - Visual configuration from data table
	 */
	UFUNCTION(BlueprintCallable, Category = "Wormhole")
	void InitializeWormhole(
		const FGuid& WormholeId,
		const FString& WormholeName,
		const FGuid& TargetSystemId,
		int32 Seed,
		const FWormholeVisualRow& VisualData);

	/**
	 * Get the wormhole's unique ID
	 */
	UFUNCTION(BlueprintPure, Category = "Wormhole")
	FGuid GetWormholeId() const { return WormholeId; }

	/**
	 * Get the wormhole's name
	 */
	UFUNCTION(BlueprintPure, Category = "Wormhole")
	FString GetWormholeName() const { return WormholeName; }

	/**
	 * Get the target system ID
	 */
	UFUNCTION(BlueprintPure, Category = "Wormhole")
	FGuid GetTargetSystemId() const { return TargetSystemId; }

	/**
	 * Called when a ship enters the wormhole trigger zone
	 * Server will initiate jump to target system
	 */
	UFUNCTION()
	void OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	/**
	 * Initiate jump sequence for a ship
	 */
	UFUNCTION(BlueprintCallable, Category = "Wormhole", meta = (BlueprintAuthorityOnly))
	void InitiateJump(AActor* Ship);

	/**
	 * Process ship passing through wormhole
	 * Reduces remaining mass and lifetime
	 */
	UFUNCTION(BlueprintCallable, Category = "Wormhole")
	void ProcessShipPassage(AActor* Ship, float ShipMass);

	/**
	 * Check if wormhole can accommodate ship of given mass
	 */
	UFUNCTION(BlueprintPure, Category = "Wormhole")
	bool CanAccommodateShip(float ShipMass) const;

	/**
	 * Get stability percentage (0.0 to 1.0)
	 */
	UFUNCTION(BlueprintPure, Category = "Wormhole")
	float GetStabilityPercentage() const;

	/**
	 * Trigger wormhole collapse
	 */
	UFUNCTION(BlueprintCallable, Category = "Wormhole", meta = (BlueprintAuthorityOnly))
	void TriggerCollapse();

protected:
	/**
	 * Generate unique color based on target system ID
	 */
	FLinearColor GenerateWormholeColor(const FGuid& TargetId) const;

	/**
	 * Setup spatial distortion effects
	 */
	void SetupDistortionEffects(const FWormholeVisualRow& VisualData);

	/**
	 * Setup trigger zone for jump detection
	 */
	void SetupTriggerZone();

	/**
	 * Update wormhole degradation over time
	 */
	virtual void Tick(float DeltaTime) override;

	/**
	 * Update instability visual effects based on current state
	 */
	void UpdateInstabilityEffects();

private:
	// ==================== Components ====================

	/** Root scene component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* RootSceneComponent;

	/** Entrance structure mesh (optional) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* EntranceMeshComponent;

	/** Main wormhole VFX (event horizon) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UNiagaraComponent* WormholeVFXComponent;

	/** Instability VFX (for unstable wormholes) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UNiagaraComponent* InstabilityVFXComponent;

	/** Ambient audio component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UAudioComponent* AmbientAudioComponent;

	/** Entrance sound component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UAudioComponent* EntranceSoundComponent;

	/** Trigger sphere for jump detection */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class USphereComponent* TriggerSphere;

	// ==================== Configuration ====================

	/** Unique ID of this wormhole */
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = "Wormhole", meta = (AllowPrivateAccess = "true"))
	FGuid WormholeId;

	/** Name of the wormhole */
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = "Wormhole", meta = (AllowPrivateAccess = "true"))
	FString WormholeName;

	/** Target system ID (where this wormhole leads) */
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = "Wormhole", meta = (AllowPrivateAccess = "true"))
	FGuid TargetSystemId;

	/** Procedural generation seed */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Wormhole", meta = (AllowPrivateAccess = "true"))
	int32 GenerationSeed;

	/** Unique color for this wormhole */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Wormhole", meta = (AllowPrivateAccess = "true"))
	FLinearColor WormholeColor;

	// ==================== Instability & Degradation ====================

	/** Maximum mass capacity (in metric tons) */
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Wormhole|Instability", meta = (AllowPrivateAccess = "true"))
	float MassCapacity;

	/** Current mass that has passed through */
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = "Wormhole|Instability", meta = (AllowPrivateAccess = "true"))
	float CurrentMassUsed;

	/** Remaining lifetime in seconds */
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = "Wormhole|Instability", meta = (AllowPrivateAccess = "true"))
	float RemainingLifetime;

	/** Initial lifetime when wormhole was created */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wormhole|Instability", meta = (AllowPrivateAccess = "true"))
	float InitialLifetime;

	/** Whether wormhole is collapsing */
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = "Wormhole|Instability", meta = (AllowPrivateAccess = "true"))
	bool bIsCollapsing;

	// ==================== Replication ====================

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
