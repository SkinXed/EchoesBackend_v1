// Copyright Epic Games, Inc. All Rights Reserved.

#include "StarActor.h"
#include "Net/UnrealNetwork.h"
#include "Components/StaticMeshComponent.h"
#include "Components/PointLightComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "NiagaraComponent.h"
#include "Materials/MaterialInstanceDynamic.h"

AStarActor::AStarActor()
{
	PrimaryActorTick.bCanEverTick = false;

	// Enable replication
	bReplicates = true;
	bAlwaysRelevant = true;

	// Create root component
	USceneComponent* RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = RootComp;

	// Create star mesh component
	StarMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StarMesh"));
	StarMeshComponent->SetupAttachment(RootComponent);
	StarMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	StarMeshComponent->SetCastShadow(false); // Stars don't cast shadows

	// Create point light component
	StarLightComponent = CreateDefaultSubobject<UPointLightComponent>(TEXT("StarLight"));
	StarLightComponent->SetupAttachment(RootComponent);
	StarLightComponent->SetCastShadows(true);
	StarLightComponent->SetIntensity(10000.0f);
	StarLightComponent->SetAttenuationRadius(1000000.0f); // Very large for system-wide illumination

	// Create corona particle component (Legacy Cascade)
	CoronaParticleComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("CoronaParticles"));
	CoronaParticleComponent->SetupAttachment(StarMeshComponent);
	CoronaParticleComponent->SetAutoActivate(true);

	// Create corona Niagara component
	CoronaNiagaraComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("CoronaNiagara"));
	CoronaNiagaraComponent->SetupAttachment(StarMeshComponent);
	CoronaNiagaraComponent->SetAutoActivate(true);
}

void AStarActor::BeginPlay()
{
	Super::BeginPlay();

	// Apply visual configuration on clients when data is replicated
	if (!HasAuthority())
	{
		ApplyVisualConfiguration();
	}
}

void AStarActor::InitializeStar(
	const FString& InStarClass,
	float InTemperature,
	float InLuminosity,
	float InRadius,
	const FStarVisualRow& InVisualData)
{
	// Only server should initialize
	if (!HasAuthority())
	{
		UE_LOG(LogTemp, Warning, TEXT("InitializeStar called on client - ignoring"));
		return;
	}

	// Store data
	StarClass = InStarClass;
	Temperature = InTemperature;
	Luminosity = InLuminosity;
	Radius = InRadius;
	VisualData = InVisualData;

	UE_LOG(LogTemp, Log, TEXT("Initializing Star: Class=%s, Temp=%.1fK, Luminosity=%.2f, Radius=%.1f km"),
		*StarClass, Temperature, Luminosity, Radius);

	// Apply visual configuration
	ApplyVisualConfiguration();
}

void AStarActor::ApplyVisualConfiguration()
{
	// Scale star mesh based on radius
	if (StarMeshComponent && Radius > 0.0f)
	{
		// Base scale calculation - this would use UniverseToWorldScale in production
		float BaseScale = Radius / 696000.0f; // Normalized to Sun radius
		StarMeshComponent->SetRelativeScale3D(FVector(BaseScale));
	}

	// Configure light based on luminosity and temperature
	if (StarLightComponent)
	{
		// Calculate light intensity from luminosity
		float LightIntensity = VisualData.BaseLightIntensity * Luminosity;
		StarLightComponent->SetIntensity(LightIntensity);

		// Calculate light color from temperature
		FLinearColor LightColor = CalculateLightColorFromTemperature(Temperature);
		StarLightComponent->SetLightColor(LightColor);

		// Set attenuation radius
		StarLightComponent->SetAttenuationRadius(VisualData.AttenuationRadius);

		UE_LOG(LogTemp, Verbose, TEXT("Star Light: Intensity=%.1f, Color=(%f,%f,%f)"),
			LightIntensity, LightColor.R, LightColor.G, LightColor.B);
	}

	// Set corona effects
	if (CoronaNiagaraComponent && !VisualData.CoronaNiagara.IsNull())
	{
		// In production: Load async with UStreamableManager
		// For now, VFX would be set through data tables
		CoronaNiagaraComponent->SetVisibility(true);
	}
	else if (CoronaNiagaraComponent)
	{
		CoronaNiagaraComponent->SetVisibility(false);
	}

	// Set legacy corona particles
	if (CoronaParticleComponent && !VisualData.CoronaParticles.IsNull())
	{
		CoronaParticleComponent->SetVisibility(true);
	}
	else if (CoronaParticleComponent)
	{
		CoronaParticleComponent->SetVisibility(false);
	}

	// Create dynamic material for star surface
	UMaterialInterface* CurrentMaterial = StarMeshComponent->GetMaterial(0);
	if (CurrentMaterial)
	{
		UMaterialInstanceDynamic* DynMaterial = UMaterialInstanceDynamic::Create(CurrentMaterial, this);
		if (DynMaterial)
		{
			// Set material parameters based on temperature and luminosity
			DynMaterial->SetScalarParameterValue(TEXT("Temperature"), Temperature);
			DynMaterial->SetScalarParameterValue(TEXT("Luminosity"), Luminosity);
			DynMaterial->SetVectorParameterValue(TEXT("EmissiveColor"), 
				CalculateLightColorFromTemperature(Temperature));

			StarMeshComponent->SetMaterial(0, DynMaterial);
		}
	}
}

FLinearColor AStarActor::CalculateLightColorFromTemperature(float TempKelvin)
{
	// Simplified Wien's approximation for star color
	// Based on blackbody radiation
	
	if (TempKelvin < 3500.0f) // Red dwarf (M-class)
	{
		return FLinearColor(1.0f, 0.4f, 0.2f);
	}
	else if (TempKelvin < 5000.0f) // Orange (K-class)
	{
		return FLinearColor(1.0f, 0.7f, 0.4f);
	}
	else if (TempKelvin < 6000.0f) // Yellow (G-class, like Sun)
	{
		return FLinearColor(1.0f, 0.95f, 0.8f);
	}
	else if (TempKelvin < 7500.0f) // White (F-class)
	{
		return FLinearColor(1.0f, 1.0f, 0.95f);
	}
	else if (TempKelvin < 10000.0f) // Blue-white (A-class)
	{
		return FLinearColor(0.9f, 0.95f, 1.0f);
	}
	else if (TempKelvin < 30000.0f) // Blue (B-class)
	{
		return FLinearColor(0.7f, 0.8f, 1.0f);
	}
	else // Very hot blue (O-class)
	{
		return FLinearColor(0.6f, 0.7f, 1.0f);
	}
}

void AStarActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Replicate star data to all clients
	DOREPLIFETIME(AStarActor, StarClass);
	DOREPLIFETIME(AStarActor, Temperature);
	DOREPLIFETIME(AStarActor, Luminosity);
	DOREPLIFETIME(AStarActor, Radius);
}

void AStarActor::OnRep_StarData()
{
	// When data is replicated, apply visual configuration on client
	ApplyVisualConfiguration();
}
