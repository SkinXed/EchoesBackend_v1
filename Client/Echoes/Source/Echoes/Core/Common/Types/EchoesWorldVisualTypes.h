// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameFramework/Actor.h"
#include "Particles/ParticleSystem.h"
#include "NiagaraSystem.h"
#include "Sound/SoundBase.h"
#include "EchoesWorldVisualTypes.generated.h"

/**
 * Visual configuration for planets
 * Maps planet types from database to Unreal assets
 * Uses TSoftObjectPtr for memory optimization (lazy loading)
 */
USTRUCT(BlueprintType)
struct FPlanetVisualRow : public FTableRowBase
{
	GENERATED_BODY()

	/** Planet blueprint actor */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	TSoftClassPtr<AActor> ActorClass;

	/** Scale applied to the planet actor */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	FVector ActorScale = FVector(1.0f, 1.0f, 1.0f);

	/** Atmosphere scale (0 = no atmosphere, 1 = normal, >1 = thick atmosphere) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Atmosphere")
	float AtmosphereScale = 1.0f;

	/** Cloud rotation speed */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Clouds")
	float CloudRotationSpeed = 0.1f;

	/** Emissive intensity for lava/volcanic planets */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	float EmissiveIntensity = 0.0f;

	// ==================== Orbit Visualization ====================

	/** Whether to display orbital path for this planet type */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orbit")
	bool bShowOrbit = true;

	/** Color of the orbital path line */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orbit")
	FLinearColor OrbitColor = FLinearColor(0.3f, 0.6f, 1.0f, 0.5f);

	/** Thickness of the orbital path line in world units */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orbit")
	float OrbitLineThickness = 10.0f;

	/** Number of segments for orbit circle (higher = smoother) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orbit")
	int32 OrbitSegments = 128;

	/** Material to use for orbit rendering (optional, for advanced effects) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orbit")
	TSoftObjectPtr<UMaterialInterface> OrbitMaterial;
};

/**
 * Visual configuration for stars
 * Defines corona effects, lighting, and post-process settings
 */
USTRUCT(BlueprintType)
struct FStarVisualRow : public FTableRowBase
{
	GENERATED_BODY()

	/** Star blueprint actor */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	TSoftClassPtr<AActor> ActorClass;

	/** Scale applied to the star actor */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	FVector ActorScale = FVector(1.0f, 1.0f, 1.0f);

	/** Corona particle system (Legacy Cascade) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Corona")
	TSoftObjectPtr<UParticleSystem> CoronaParticles;

	/** Corona VFX (Niagara) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Corona")
	TSoftObjectPtr<UNiagaraSystem> CoronaNiagara;

	/** Base light intensity (will be scaled by star luminosity) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lighting")
	float BaseLightIntensity = 10000.0f;

	/** Light color (will be adjusted by star temperature) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lighting")
	FLinearColor LightColor = FLinearColor::White;

	/** Attenuation radius for directional light */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lighting")
	float AttenuationRadius = 1000000.0f;

	/** Bloom intensity */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PostProcess")
	float BloomIntensity = 5.0f;
};

/**
 * Visual configuration for space stations
 * Supports modular construction with faction customization
 */
USTRUCT(BlueprintType)
struct FStationVisualRow : public FTableRowBase
{
	GENERATED_BODY()

	/** Station blueprint actor */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	TSoftClassPtr<AActor> ActorClass;

	/** Scale applied to the station actor */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	FVector ActorScale = FVector(1.0f, 1.0f, 1.0f);

	/** Navigation lights pattern (Niagara or material) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lighting")
	TSoftObjectPtr<UNiagaraSystem> LightsPattern;

	/** Docking bay lights */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lighting")
	FLinearColor DockingLightColor = FLinearColor(0.0f, 1.0f, 0.0f, 1.0f);

	/** Scale variation range (min-max) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variation")
	FVector2D ScaleRange = FVector2D(0.8f, 1.2f);
};

/**
 * Visual configuration for stargates
 * Defines gate structure and portal VFX
 */
USTRUCT(BlueprintType)
struct FStargateVisualRow : public FTableRowBase
{
	GENERATED_BODY()

	/** Stargate blueprint actor */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	TSoftClassPtr<AActor> ActorClass;

	/** Scale applied to the stargate actor */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	FVector ActorScale = FVector(1.0f, 1.0f, 1.0f);

	/** Portal VFX (wormhole effect) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Portal")
	TSoftObjectPtr<UNiagaraSystem> PortalVFX;

	/** Destination marker VFX */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	TSoftObjectPtr<UNiagaraSystem> DestinationFX;

	/** Gate activation sound */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
	TSoftObjectPtr<USoundBase> ActivationSound;

	/** Ambient hum sound */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
	TSoftObjectPtr<USoundBase> AmbientSound;

	/** Ring rotation speed (for spinning gates) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	float RingRotationSpeed = 10.0f;

	/** Light color for gate */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lighting")
	FLinearColor GateLightColor = FLinearColor(0.0f, 0.5f, 1.0f, 1.0f);
};

/**
 * Visual configuration for asteroid belts
 * Defines individual asteroid meshes and environmental effects
 */
USTRUCT(BlueprintType)
struct FAsteroidBeltVisualRow : public FTableRowBase
{
	GENERATED_BODY()

	/** Asteroid belt blueprint actor */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	TSoftClassPtr<AActor> ActorClass;

	/** Scale applied to the asteroid belt actor */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	FVector ActorScale = FVector(1.0f, 1.0f, 1.0f);

	/** Cloud/Dust particle effects (Niagara) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Environment")
	TSoftObjectPtr<UNiagaraSystem> DustCloudVFX;

	/** Ambient audio loop for the belt */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
	TSoftObjectPtr<USoundBase> AmbientSound;

	/** Density multiplier for asteroid distribution (0.1 to 2.0) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Distribution")
	float DensityMultiplier = 1.0f;

	/** Scale range for asteroids (min-max) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Distribution")
	FVector2D AsteroidScaleRange = FVector2D(0.5f, 2.0f);

	/** Color tint for mineral-rich asteroids */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	FLinearColor MineralTint = FLinearColor::White;
};

/**
 * Visual configuration for anomalies
 * Defines site visuals based on anomaly type and difficulty
 */
USTRUCT(BlueprintType)
struct FAnomalyVisualRow : public FTableRowBase
{
	GENERATED_BODY()

	/** Anomaly blueprint actor */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Structure")
	TSoftClassPtr<AActor> ActorClass;

	/** Scale applied to the anomaly actor */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Structure")
	FVector ActorScale = FVector(1.0f, 1.0f, 1.0f);

	/** Scanning signature VFX (visible when scanned) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scanning")
	TSoftObjectPtr<UNiagaraSystem> SignatureVFX;

	/** Type-specific particle effects (combat beams, data streams, gas clouds, etc.) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TypeEffects")
	TSoftObjectPtr<UNiagaraSystem> TypeSpecificVFX;

	/** Ambient sound for the anomaly */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
	TSoftObjectPtr<USoundBase> AmbientSound;

	/** Warning sound when entering danger zone */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
	TSoftObjectPtr<USoundBase> WarningSound;

	/** Glow color for anomaly signature */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	FLinearColor SignatureColor = FLinearColor(1.0f, 0.5f, 0.0f, 1.0f);

	/** Detection radius multiplier */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scanning")
	float DetectionRadiusMultiplier = 1.0f;
};

/**
 * Visual configuration for wormholes
 * Defines unique effects and distortions for wormhole entrances
 */
USTRUCT(BlueprintType)
struct FWormholeVisualRow : public FTableRowBase
{
	GENERATED_BODY()

	/** Wormhole blueprint actor */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Structure")
	TSoftClassPtr<AActor> ActorClass;

	/** Scale applied to the wormhole actor */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Structure")
	FVector ActorScale = FVector(1.0f, 1.0f, 1.0f);

	/** Main wormhole VFX (event horizon, spatial distortion) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Portal")
	TSoftObjectPtr<UNiagaraSystem> WormholeVFX;

	/** Entrance activation sound */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
	TSoftObjectPtr<USoundBase> EntranceSound;

	/** Exit/jump sound */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
	TSoftObjectPtr<USoundBase> ExitSound;

	/** Ambient hum/rumble loop */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
	TSoftObjectPtr<USoundBase> AmbientSound;

	/** Base color for the wormhole (will be modified by TargetSystemId) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	FLinearColor BaseColor = FLinearColor(0.2f, 0.6f, 1.0f, 1.0f);

	/** Instability VFX (for unstable wormholes) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Portal")
	TSoftObjectPtr<UNiagaraSystem> InstabilityVFX;

	/** Intensity of spatial distortion (0.0 to 1.0) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Distortion")
	float DistortionIntensity = 0.5f;
};

/**
 * Visual configuration for moons
 * Maps moon types from database to Unreal assets
 */
USTRUCT(BlueprintType)
struct FMoonVisualRow : public FTableRowBase
{
	GENERATED_BODY()

	/** Moon blueprint actor */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	TSoftClassPtr<AActor> ActorClass;

	/** Scale applied to the moon actor */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	FVector ActorScale = FVector(0.5f, 0.5f, 0.5f); // Smaller than planets by default

	/** Whether to display orbital path for this moon type */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orbit")
	bool bShowOrbit = true;

	/** Color of the orbital path line */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orbit")
	FLinearColor OrbitColor = FLinearColor(0.6f, 0.7f, 0.8f, 0.3f); // Subtle gray-blue

	/** Thickness of the orbital path line in world units */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orbit")
	float OrbitLineThickness = 5.0f; // Thinner than planet orbits

	/** Number of segments for orbit circle (higher = smoother) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orbit")
	int32 OrbitSegments = 64; // Fewer segments than planets

	/** Material to use for orbit rendering (optional, for advanced effects) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orbit")
	TSoftObjectPtr<UMaterialInterface> OrbitMaterial;
};
