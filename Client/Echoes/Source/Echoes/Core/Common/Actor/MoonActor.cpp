// Copyright Epic Games, Inc. All Rights Reserved.

#include "MoonActor.h"
#include "Net/UnrealNetwork.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SplineComponent.h"

AMoonActor::AMoonActor()
{
	PrimaryActorTick.bCanEverTick = false;

	// Enable replication
	bReplicates = true;
	bAlwaysRelevant = false; // Moons can be culled based on distance

	// Set network cull distance similar to planets
	NetCullDistanceSquared = 100000000000000.0; // 10 million units squared

	// Create root component
	USceneComponent* RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = RootComp;

	// Create moon mesh component
	MoonMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MoonMesh"));
	MoonMeshComponent->SetupAttachment(RootComponent);
	MoonMeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	MoonMeshComponent->SetCollisionResponseToAllChannels(ECR_Block);

	// Orbit spline will be created client-side
	OrbitSplineComponent = nullptr;
}

void AMoonActor::BeginPlay()
{
	Super::BeginPlay();

	// Apply visual configuration on clients when data is replicated
	if (!HasAuthority())
	{
		ApplyVisualConfiguration();
		
		// Draw orbit on client if orbit parameters are set
		if (OrbitRadius > 0.0f)
		{
			ClientOnly_DrawOrbit();
		}
	}
}

void AMoonActor::InitializeMoon(
	const FGuid& InMoonId,
	const FString& InName,
	const FString& InType,
	float InOrbitRadius,
	int32 InSeed)
{
	// Only server should initialize
	if (!HasAuthority())
	{
		UE_LOG(LogTemp, Warning, TEXT("InitializeMoon called on client - ignoring"));
		return;
	}

	// Store data
	MoonId = InMoonId;
	MoonName = InName;
	MoonType = InType;
	OrbitRadius = InOrbitRadius;
	Seed = InSeed;

	UE_LOG(LogTemp, Log, TEXT("Initializing Moon: %s (Type: %s, Orbit: %.1f km, Seed: %d)"),
		*MoonName, *MoonType, OrbitRadius, Seed);

	// Apply visual configuration
	ApplyVisualConfiguration();
}

void AMoonActor::SetOrbitParameters(float InOrbitRadius, const FVector& InParentLocation)
{
	OrbitRadius = InOrbitRadius;
	ParentLocation = InParentLocation;
	
	UE_LOG(LogTemp, Verbose, TEXT("Moon %s: Orbit parameters set - Radius: %.1f km, ParentLocation: %s"),
		*MoonName, OrbitRadius, *ParentLocation.ToString());
}

void AMoonActor::ClientOnly_DrawOrbit()
{
	// Only execute on client (not server)
	if (HasAuthority())
	{
		UE_LOG(LogTemp, Warning, TEXT("ClientOnly_DrawOrbit called on server for moon %s - ignoring"), *MoonName);
		return;
	}

	// Don't draw if orbit radius is 0
	if (OrbitRadius <= 0.0f)
	{
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Drawing orbit for moon %s (Radius: %.1f km)"), *MoonName, OrbitRadius);

	// Calculate orbit radius in Unreal Units
	// OrbitRadius is in km, need to convert to cm using UniverseToWorldScale
	const float UniverseToWorldScale = 0.0001f; // 1 km = 10 cm
	const double OrbitRadiusUU = static_cast<double>(OrbitRadius) * static_cast<double>(UniverseToWorldScale) * 100000.0; // km to cm

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
	const int32 NumSegments = 64; // Moons use fewer segments than planets
	const float AngleStep = 360.0f / NumSegments;

	// The orbit center is at the parent planet location
	const FVector OrbitCenter = ParentLocation;

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

	// Set spline color (lighter/subtle for moons)
	OrbitSplineComponent->SetDrawDebug(true);
	OrbitSplineComponent->SetUnselectedSplineSegmentColor(FLinearColor(0.6f, 0.7f, 0.8f, 0.3f)); // Light gray-blue

	UE_LOG(LogTemp, Log, TEXT("✓ Orbit drawn for moon %s: %d segments, Radius: %.1f UU, Center: %s"),
		*MoonName, NumSegments, OrbitRadiusUU, *OrbitCenter.ToString());
}

void AMoonActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Replicate moon data to all clients
	DOREPLIFETIME(AMoonActor, MoonId);
	DOREPLIFETIME(AMoonActor, MoonName);
	DOREPLIFETIME(AMoonActor, MoonType);
	DOREPLIFETIME(AMoonActor, OrbitRadius);
	DOREPLIFETIME(AMoonActor, Seed);
}

void AMoonActor::OnRep_MoonData()
{
	// When data is replicated, apply visual configuration on client
	ApplyVisualConfiguration();
}

void AMoonActor::ApplyVisualConfiguration()
{
	// Apply basic visual configuration
	// This can be extended to load meshes from a data table similar to planets
	
	if (MoonMeshComponent)
	{
		// Scale based on orbit radius (smaller moons for smaller orbits)
		float Scale = FMath::Clamp(OrbitRadius / 10000.0f, 0.1f, 2.0f);
		MoonMeshComponent->SetRelativeScale3D(FVector(Scale));
	}
}
