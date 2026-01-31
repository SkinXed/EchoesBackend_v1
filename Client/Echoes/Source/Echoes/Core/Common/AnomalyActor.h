// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EchoesWorldVisualTypes.h"
#include "AnomalyActor.generated.h"

/**
 * AAnomalyActor
 * 
 * Represents a cosmic anomaly in a solar system
 * Supports different types: Combat, Relic, Data, Gas, Ore
 * Features scanning signature system for exploration gameplay
 * Configurable difficulty levels affect visuals and rewards
 * 
 * Key Features:
 * - Type-specific visual configurations (Combat/Relic/Data/Gas)
 * - Scanning signature VFX (visible when scanned)
 * - Difficulty-based icons and effects
 * - Trigger zones for interaction
 * - Support for loot/reward systems
 */
UCLASS()
class ECHOES_API AAnomalyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AAnomalyActor();

protected:
	virtual void BeginPlay() override;

public:
	/**
	 * Initialize anomaly from server configuration
	 * 
	 * @param AnomalyId - Unique identifier of the anomaly
	 * @param AnomalyName - Name of the anomaly
	 * @param AnomalyType - Type (Combat/Relic/Data/Gas/Ore)
	 * @param AnomalyDifficulty - Difficulty level (Easy/Medium/Hard/Elite)
	 * @param Seed - Procedural generation seed
	 * @param VisualData - Visual configuration from data table
	 */
	UFUNCTION(BlueprintCallable, Category = "Anomaly")
	void InitializeAnomaly(
		const FGuid& AnomalyId,
		const FString& AnomalyName,
		const FString& AnomalyType,
		const FString& AnomalyDifficulty,
		int32 Seed,
		const FAnomalyVisualRow& VisualData);

	/**
	 * Get the anomaly's unique ID
	 */
	UFUNCTION(BlueprintPure, Category = "Anomaly")
	FGuid GetAnomalyId() const { return AnomalyId; }

	/**
	 * Get the anomaly's name
	 */
	UFUNCTION(BlueprintPure, Category = "Anomaly")
	FString GetAnomalyName() const { return AnomalyName; }

	/**
	 * Get the anomaly type
	 */
	UFUNCTION(BlueprintPure, Category = "Anomaly")
	FString GetAnomalyType() const { return AnomalyType; }

	/**
	 * Get the anomaly difficulty
	 */
	UFUNCTION(BlueprintPure, Category = "Anomaly")
	FString GetAnomalyDifficulty() const { return AnomalyDifficulty; }

	/**
	 * Activate scanning signature (called when player scans)
	 */
	UFUNCTION(BlueprintCallable, Category = "Anomaly")
	void ActivateScanningSignature();

	/**
	 * Deactivate scanning signature
	 */
	UFUNCTION(BlueprintCallable, Category = "Anomaly")
	void DeactivateScanningSignature();

protected:
	/**
	 * Setup type-specific visuals (Combat/Relic/Data/Gas)
	 */
	void SetupTypeSpecificVisuals(const FString& Type, const FAnomalyVisualRow& VisualData);

	/**
	 * Setup difficulty indicators
	 */
	void SetupDifficultyIndicators(const FString& Difficulty, const FAnomalyVisualRow& VisualData);

	/**
	 * Create interaction trigger zone
	 */
	void SetupTriggerZone();

private:
	// ==================== Components ====================

	/** Root scene component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* RootSceneComponent;

	/** Central structure mesh */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* CenterMeshComponent;

	/** Scanning signature VFX */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UNiagaraComponent* SignatureVFXComponent;

	/** Type-specific VFX (combat beams, data streams, gas clouds) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UNiagaraComponent* TypeVFXComponent;

	/** Ambient audio component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UAudioComponent* AmbientAudioComponent;

	/** Warning audio component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UAudioComponent* WarningAudioComponent;

	/** Trigger sphere for interaction detection */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class USphereComponent* TriggerSphere;

	// ==================== Configuration ====================

	/** Unique ID of this anomaly */
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = "Anomaly", meta = (AllowPrivateAccess = "true"))
	FGuid AnomalyId;

	/** Name of the anomaly */
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = "Anomaly", meta = (AllowPrivateAccess = "true"))
	FString AnomalyName;

	/** Type of anomaly (Combat/Relic/Data/Gas/Ore) */
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = "Anomaly", meta = (AllowPrivateAccess = "true"))
	FString AnomalyType;

	/** Difficulty level (Easy/Medium/Hard/Elite) */
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = "Anomaly", meta = (AllowPrivateAccess = "true"))
	FString AnomalyDifficulty;

	/** Procedural generation seed */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Anomaly", meta = (AllowPrivateAccess = "true"))
	int32 GenerationSeed;

	/** Whether signature is currently visible (scanned) */
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = "Anomaly", meta = (AllowPrivateAccess = "true"))
	bool bSignatureActive;

	// ==================== Replication ====================

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
