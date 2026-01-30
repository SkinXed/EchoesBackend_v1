// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Engine/Texture2D.h"
#include "Materials/MaterialInstance.h"
#include "Particles/ParticleSystem.h"
#include "NiagaraSystem.h"
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

	/** Planet mesh (sphere or custom model) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	TSoftObjectPtr<UStaticMesh> Mesh;

	/** Array of possible material instances for variation */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	TArray<TSoftObjectPtr<UMaterialInstance>> MaterialInstances;

	/** Atmosphere post-process settings (optional) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Atmosphere")
	TSoftObjectPtr<UMaterialInstance> AtmosphereMaterial;

	/** Atmosphere scale (0 = no atmosphere, 1 = normal, >1 = thick atmosphere) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Atmosphere")
	float AtmosphereScale = 1.0f;

	/** Cloud layer mesh (optional) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Clouds")
	TSoftObjectPtr<UStaticMesh> CloudLayerMesh;

	/** Cloud layer material */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Clouds")
	TSoftObjectPtr<UMaterialInstance> CloudLayerMaterial;

	/** Cloud rotation speed */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Clouds")
	float CloudRotationSpeed = 0.1f;

	/** Array of texture randomizers for surface variation */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variation")
	TArray<TSoftObjectPtr<UTexture2D>> TextureRandomizers;

	/** Emissive intensity for lava/volcanic planets */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	float EmissiveIntensity = 0.0f;

	/** Ring system mesh (optional, for gas giants) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rings")
	TSoftObjectPtr<UStaticMesh> RingMesh;

	/** Ring material */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rings")
	TSoftObjectPtr<UMaterialInstance> RingMaterial;
};

/**
 * Visual configuration for stars
 * Defines corona effects, lighting, and post-process settings
 */
USTRUCT(BlueprintType)
struct FStarVisualRow : public FTableRowBase
{
	GENERATED_BODY()

	/** Star mesh (usually a sphere) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	TSoftObjectPtr<UStaticMesh> Mesh;

	/** Star surface material */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	TSoftObjectPtr<UMaterialInstance> MaterialInstance;

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

	/** Lens flare type */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	TSoftObjectPtr<UTexture2D> FlareTexture;

	/** Post-process material for bloom and glow */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PostProcess")
	TSoftObjectPtr<UMaterialInstance> PostProcessMaterial;

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

	/** Base station mesh */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	TSoftObjectPtr<UStaticMesh> BaseMesh;

	/** Array of modular parts (habitats, docking bays, solar panels, etc.) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Modular")
	TArray<TSoftObjectPtr<UStaticMesh>> ModularParts;

	/** Faction decals (logos, markings) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Faction")
	TArray<TSoftObjectPtr<UMaterialInstance>> FactionDecals;

	/** Navigation lights pattern (Niagara or material) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lighting")
	TSoftObjectPtr<UNiagaraSystem> LightsPattern;

	/** Window emissive material */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	TSoftObjectPtr<UMaterialInstance> WindowMaterial;

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

	/** Gate structure mesh */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	TSoftObjectPtr<UStaticMesh> GateMesh;

	/** Gate material */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	TSoftObjectPtr<UMaterialInstance> GateMaterial;

	/** Portal VFX (wormhole effect) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Portal")
	TSoftObjectPtr<UNiagaraSystem> PortalVFX;

	/** Portal material (event horizon) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Portal")
	TSoftObjectPtr<UMaterialInstance> PortalMaterial;

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
