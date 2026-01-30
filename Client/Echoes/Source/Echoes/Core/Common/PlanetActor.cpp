// Copyright Epic Games, Inc. All Rights Reserved.

#include "PlanetActor.h"
#include "Net/UnrealNetwork.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "TimerManager.h"

APlanetActor::APlanetActor()
{
	PrimaryActorTick.bCanEverTick = false;

	// Enable replication
	bReplicates = true;
	bAlwaysRelevant = false; // Planets can be culled based on distance

	// Set network cull distance for regional clusters
	// Large distance to accommodate multiple systems
	// 10 million units = reasonable inter-system visibility range
	NetCullDistanceSquared = 100000000000000.0; // 10 million units squared

	// Create root component
	USceneComponent* RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = RootComp;

	// Create planet mesh component
	PlanetMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlanetMesh"));
	PlanetMeshComponent->SetupAttachment(RootComponent);
	PlanetMeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	PlanetMeshComponent->SetCollisionResponseToAllChannels(ECR_Block);

	// Create cloud layer component (optional)
	CloudLayerComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CloudLayer"));
	CloudLayerComponent->SetupAttachment(PlanetMeshComponent);
	CloudLayerComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	CloudLayerComponent->SetRelativeScale3D(FVector(1.05f)); // Slightly larger than planet

	// Create atmosphere component (optional)
	AtmosphereComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Atmosphere"));
	AtmosphereComponent->SetupAttachment(PlanetMeshComponent);
	AtmosphereComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	AtmosphereComponent->SetRelativeScale3D(FVector(1.1f)); // Larger than planet

	// Create ring component (optional, for gas giants)
	RingComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ring"));
	RingComponent->SetupAttachment(PlanetMeshComponent);
	RingComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void APlanetActor::BeginPlay()
{
	Super::BeginPlay();

	// Apply visual configuration on clients when data is replicated
	if (!HasAuthority())
	{
		ApplyVisualConfiguration();
	}
}

void APlanetActor::InitializePlanet(
	const FGuid& InPlanetId,
	const FString& InName,
	const FString& InType,
	float InRadius,
	int32 InSeed,
	const FPlanetVisualRow& InVisualData)
{
	// Only server should initialize
	if (!HasAuthority())
	{
		UE_LOG(LogTemp, Warning, TEXT("InitializePlanet called on client - ignoring"));
		return;
	}

	// Store data
	PlanetId = InPlanetId;
	PlanetName = InName;
	PlanetType = InType;
	Radius = InRadius;
	Seed = InSeed;
	VisualData = InVisualData;

	UE_LOG(LogTemp, Log, TEXT("Initializing Planet: %s (Type: %s, Radius: %.1f km, Seed: %d)"),
		*PlanetName, *PlanetType, Radius, Seed);

	// Apply visual configuration
	ApplyVisualConfiguration();

	// Apply seed-based variation
	ApplySeedVariation();
}

void APlanetActor::ApplySeedVariation()
{
	if (!HasAuthority())
	{
		return;
	}

	// Initialize random stream with seed for consistent variation
	FRandomStream RandomStream(Seed);

	// Random rotation
	FRotator RandomRotation(
		RandomStream.FRandRange(0.0f, 360.0f),
		RandomStream.FRandRange(0.0f, 360.0f),
		RandomStream.FRandRange(0.0f, 360.0f)
	);
	PlanetMeshComponent->SetRelativeRotation(RandomRotation);

	// Random scale variation (±10%)
	float ScaleVariation = RandomStream.FRandRange(0.9f, 1.1f);
	PlanetMeshComponent->SetRelativeScale3D(FVector(ScaleVariation));

	// Create dynamic material instances for parameter variation
	CreateDynamicMaterials();

	UE_LOG(LogTemp, Verbose, TEXT("Applied seed variation to planet %s: Rotation=(%.1f,%.1f,%.1f), Scale=%.2f"),
		*PlanetName, RandomRotation.Pitch, RandomRotation.Yaw, RandomRotation.Roll, ScaleVariation);
}

void APlanetActor::ApplyVisualConfiguration()
{
	// Set planet mesh (would be loaded async in production)
	// For now, assuming assets are already loaded
	// TODO: Implement async loading with UStreamableManager

	// Select material from array based on seed
	if (VisualData.MaterialInstances.Num() > 0)
	{
		FRandomStream RandomStream(Seed);
		int32 MaterialIndex = RandomStream.RandRange(0, VisualData.MaterialInstances.Num() - 1);
		
		// In production, use async loading:
		// UAssetManager::GetStreamableManager().RequestAsyncLoad(...)
		// For now, materials would be set through data tables
	}

	// Set atmosphere scale
	if (AtmosphereComponent)
	{
		float AtmosphereScale = VisualData.AtmosphereScale;
		AtmosphereComponent->SetRelativeScale3D(FVector(1.1f * AtmosphereScale));
		
		// Hide atmosphere if scale is 0
		if (AtmosphereScale <= 0.0f)
		{
			AtmosphereComponent->SetVisibility(false);
		}
	}

	// Set cloud layer
	if (CloudLayerComponent && VisualData.CloudLayerMesh.IsNull())
	{
		CloudLayerComponent->SetVisibility(false);
	}
	else if (CloudLayerComponent)
	{
		// Start cloud rotation timer
		if (HasAuthority() && VisualData.CloudRotationSpeed > 0.0f)
		{
			GetWorld()->GetTimerManager().SetTimer(
				CloudRotationTimerHandle,
				this,
				&APlanetActor::UpdateCloudRotation,
				0.1f, // Update every 0.1 seconds
				true
			);
		}
	}

	// Set ring mesh for gas giants
	if (RingComponent && VisualData.RingMesh.IsNull())
	{
		RingComponent->SetVisibility(false);
	}
}

void APlanetActor::CreateDynamicMaterials()
{
	// Create dynamic material instances for runtime parameter modification
	UMaterialInterface* CurrentMaterial = PlanetMeshComponent->GetMaterial(0);
	if (CurrentMaterial)
	{
		UMaterialInstanceDynamic* DynMaterial = UMaterialInstanceDynamic::Create(CurrentMaterial, this);
		if (DynMaterial)
		{
			// Initialize random stream
			FRandomStream RandomStream(Seed);

			// Randomize material parameters based on seed
			// Example: Vary emissive intensity for lava planets
			if (VisualData.EmissiveIntensity > 0.0f)
			{
				float EmissiveVariation = RandomStream.FRandRange(0.8f, 1.2f);
				DynMaterial->SetScalarParameterValue(TEXT("EmissiveIntensity"), 
					VisualData.EmissiveIntensity * EmissiveVariation);
			}

			// Example: Vary atmosphere density
			float AtmosphereDensity = RandomStream.FRandRange(0.9f, 1.1f);
			DynMaterial->SetScalarParameterValue(TEXT("AtmosphereDensity"), AtmosphereDensity);

			// Apply to mesh
			PlanetMeshComponent->SetMaterial(0, DynMaterial);
		}
	}
}

void APlanetActor::UpdateCloudRotation()
{
	if (CloudLayerComponent && CloudLayerComponent->IsVisible())
	{
		FRotator CurrentRotation = CloudLayerComponent->GetRelativeRotation();
		CurrentRotation.Yaw += VisualData.CloudRotationSpeed * 0.1f; // 0.1s tick rate
		CloudLayerComponent->SetRelativeRotation(CurrentRotation);
	}
}

void APlanetActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Replicate planet data to all clients
	DOREPLIFETIME(APlanetActor, PlanetId);
	DOREPLIFETIME(APlanetActor, PlanetName);
	DOREPLIFETIME(APlanetActor, PlanetType);
	DOREPLIFETIME(APlanetActor, Radius);
	DOREPLIFETIME(APlanetActor, Seed);
}

void APlanetActor::OnRep_PlanetData()
{
	// When data is replicated, apply visual configuration on client
	ApplyVisualConfiguration();
}
