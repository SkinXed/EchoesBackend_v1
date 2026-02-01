// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EchoesWorldVisualTypes.h"
#include "StarActor.generated.h"

class UPointLightComponent;
class UParticleSystemComponent;
class UNiagaraComponent;

/**
 * AStarActor
 * 
 * Represents a star in the Echoes universe
 * Central light source for the solar system
 * Spawned by AEchoesWorldGenerator based on backend configuration
 */
UCLASS()
class ECHOES_API AStarActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AStarActor();

protected:
	virtual void BeginPlay() override;

public:
	// ==================== Initialization ====================

	/**
	 * Initialize star from configuration data
	 * 
	 * @param InStarClass - Star classification (e.g., "G2V", "M5", "K0")
	 * @param InTemperature - Surface temperature in Kelvin
	 * @param InLuminosity - Luminosity relative to Sol
	 * @param InRadius - Star radius in km
	 * @param InVisualData - Visual configuration from data table
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Star")
	void InitializeStar(
		const FString& InStarClass,
		float InTemperature,
		float InLuminosity,
		float InRadius,
		const FStarVisualRow& InVisualData);

	// ==================== Getters ====================

	UFUNCTION(BlueprintPure, Category = "Echoes|Star")
	FString GetStarClass() const { return StarClass; }

	UFUNCTION(BlueprintPure, Category = "Echoes|Star")
	float GetTemperature() const { return Temperature; }

	UFUNCTION(BlueprintPure, Category = "Echoes|Star")
	float GetLuminosity() const { return Luminosity; }

protected:
	// ==================== Components ====================

	/** Star mesh component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* StarMeshComponent;

	/** Point light for illumination */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UPointLightComponent* StarLightComponent;

	/** Corona particle system (Legacy Cascade) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UParticleSystemComponent* CoronaParticleComponent;

	/** Corona VFX (Niagara) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UNiagaraComponent* CoronaNiagaraComponent;

	// ==================== Star Data (Replicated) ====================

	/** Star classification (e.g., "G2V" for Sun-like) */
	UPROPERTY(ReplicatedUsing = OnRep_StarData, BlueprintReadOnly, Category = "Star")
	FString StarClass;

	/** Surface temperature in Kelvin */
	UPROPERTY(ReplicatedUsing = OnRep_StarData, BlueprintReadOnly, Category = "Star")
	float Temperature;

	/** Luminosity relative to Sol (1.0 = Sun) */
	UPROPERTY(ReplicatedUsing = OnRep_StarData, BlueprintReadOnly, Category = "Star")
	float Luminosity;

	/** Star radius in km */
	UPROPERTY(ReplicatedUsing = OnRep_StarData, BlueprintReadOnly, Category = "Star")
	float Radius;

	/** Visual configuration data */
	UPROPERTY(BlueprintReadOnly, Category = "Star")
	FStarVisualRow VisualData;

	// ==================== Replication ====================

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION()
	void OnRep_StarData();

private:
	/** Apply visual configuration based on temperature and luminosity */
	void ApplyVisualConfiguration();

	/** Calculate light color from temperature using Wien's displacement law */
	FLinearColor CalculateLightColorFromTemperature(float TempKelvin);
};
