// Copyright Epic Games, Inc. All Rights Reserved.

#include "PlanetActor.h"
#include "Net/UnrealNetwork.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SplineComponent.h"
#include "Components/SplineMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "TimerManager.h"
#include "Engine/StaticMesh.h"

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

	// Create orbit spline component (will be initialized client-only)
	// Note: We create it here but don't attach it yet - it will be set up in ClientOnly_DrawOrbit
	OrbitSplineComponent = nullptr;
	OrbitMeshComponent = nullptr;
}

void APlanetActor::BeginPlay()
{
	Super::BeginPlay();

	// Apply visual configuration on clients when data is replicated
	if (!HasAuthority())
	{
		ApplyVisualConfiguration();
		
		// Draw orbit on client if orbit parameters are set
		if (OrbitDistance > 0.0f && VisualData.bShowOrbit)
		{
			ClientOnly_DrawOrbit();
		}
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
	PlanetMeshComponent->SetRelativeScale3D(VisualData.ActorScale * ScaleVariation);

	// Create dynamic material instances for parameter variation
	CreateDynamicMaterials();

	UE_LOG(LogTemp, Verbose, TEXT("Applied seed variation to planet %s: Rotation=(%.1f,%.1f,%.1f), Scale=%.2f"),
		*PlanetName, RandomRotation.Pitch, RandomRotation.Yaw, RandomRotation.Roll, ScaleVariation);
}

void APlanetActor::ApplyVisualConfiguration()
{
	// Apply base scale from visual data
	if (PlanetMeshComponent)
	{
		PlanetMeshComponent->SetRelativeScale3D(VisualData.ActorScale);
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

	// Start cloud rotation timer
	if (CloudLayerComponent)
	{
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

// ==================== Orbit Visualization ====================

void APlanetActor::SetOrbitParameters(float InOrbitDistance, const FVector& InSystemOffset)
{
	OrbitDistance = InOrbitDistance;
	SystemOffset = InSystemOffset;
	
	UE_LOG(LogTemp, Verbose, TEXT("Planet %s: Orbit parameters set - Distance: %.1f km, SystemOffset: %s"),
		*PlanetName, OrbitDistance, *SystemOffset.ToString());
}

void APlanetActor::ClientOnly_DrawOrbit()
{
	// Only execute on client (not server)
	if (HasAuthority())
	{
		UE_LOG(LogTemp, Warning, TEXT("ClientOnly_DrawOrbit called on server for planet %s - ignoring"), *PlanetName);
		return;
	}

	// Don't draw if orbit is disabled or orbit distance is 0
	if (!VisualData.bShowOrbit || OrbitDistance <= 0.0f)
	{
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Drawing orbit for planet %s (Distance: %.1f km)"), *PlanetName, OrbitDistance);

	// Calculate orbit radius in Unreal Units
	// OrbitDistance is in km, need to convert to cm using UniverseToWorldScale
	// Get the world generator's scale factor (default: 0.0001)
	const float UniverseToWorldScale = 0.0001f; // 1 km = 10 cm
	const double OrbitRadiusUU = static_cast<double>(OrbitDistance) * static_cast<double>(UniverseToWorldScale) * 100000.0; // km to cm

	// Create spline component if not already created
	if (!OrbitSplineComponent)
	{
		OrbitSplineComponent = NewObject<USplineComponent>(this, TEXT("OrbitSpline"));
		OrbitSplineComponent->RegisterComponent();
		OrbitSplineComponent->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
		OrbitSplineComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		OrbitSplineComponent->SetVisibility(true);
	}

	// Clear existing spline points
	OrbitSplineComponent->ClearSplinePoints();

	// Generate orbit circle points
	const int32 NumSegments = VisualData.OrbitSegments;
	const float AngleStep = 360.0f / NumSegments;

	// The orbit center is at the system offset (where the star is)
	// But the planet itself is already positioned at SystemOffset + PlanetPosition
	// So we need to draw the orbit relative to the star (at SystemOffset)
	const FVector OrbitCenter = SystemOffset;

	for (int32 i = 0; i <= NumSegments; ++i)
	{
		const float Angle = FMath::DegreesToRadians(AngleStep * i);
		const float X = FMath::Cos(Angle) * OrbitRadiusUU;
		const float Y = FMath::Sin(Angle) * OrbitRadiusUU;
		const FVector PointLocation = OrbitCenter + FVector(X, Y, 0.0f);
		
		// Add point to spline (in world space, will be converted to local)
		const FVector LocalPoint = GetTransform().InverseTransformPosition(PointLocation);
		OrbitSplineComponent->AddSplinePoint(LocalPoint, ESplineCoordinateSpace::Local, false);
	}

	// Update spline
	OrbitSplineComponent->UpdateSpline();
	OrbitSplineComponent->SetClosedLoop(true);

	// Set spline color and thickness via material
	OrbitSplineComponent->SetDrawDebug(true);
	OrbitSplineComponent->SetUnselectedSplineSegmentColor(FLinearColor(
		VisualData.OrbitColor.R,
		VisualData.OrbitColor.G,
		VisualData.OrbitColor.B,
		VisualData.OrbitColor.A
	));

	UE_LOG(LogTemp, Log, TEXT("✓ Orbit drawn for planet %s: %d segments, Radius: %.1f UU, Center: %s"),
		*PlanetName, NumSegments, OrbitRadiusUU, *OrbitCenter.ToString());
}
