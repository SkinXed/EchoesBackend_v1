// Copyright Epic Games, Inc. All Rights Reserved.

#include "AsteroidBeltActor.h"
#include "Net/UnrealNetwork.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "Components/AudioComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/World.h"

AAsteroidBeltActor::AAsteroidBeltActor()
{
	PrimaryActorTick.bCanEverTick = false;

	// Enable replication
	bReplicates = true;
	bAlwaysRelevant = true;

	// Create root component
	RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = RootSceneComponent;

	// Create HISM component for asteroids
	AsteroidInstances = CreateDefaultSubobject<UHierarchicalInstancedStaticMeshComponent>(TEXT("AsteroidInstances"));
	AsteroidInstances->SetupAttachment(RootComponent);
	AsteroidInstances->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	AsteroidInstances->SetCollisionProfileName(TEXT("BlockAll"));
	AsteroidInstances->SetGenerateOverlapEvents(true);
	AsteroidInstances->CastShadow = true;

	// Create optional Niagara component for dust clouds
	DustCloudComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("DustCloudComponent"));
	DustCloudComponent->SetupAttachment(RootComponent);
	DustCloudComponent->SetAutoActivate(false);

	// Create audio component for ambient sounds
	AmbientAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("AmbientAudioComponent"));
	AmbientAudioComponent->SetupAttachment(RootComponent);
	AmbientAudioComponent->bAutoActivate = false;

	GenerationSeed = 0;
	Radius = 100000.0f; // Default 100km in world units (before scaling)
	AsteroidCount = 0;
}

void AAsteroidBeltActor::BeginPlay()
{
	Super::BeginPlay();

	// Server-side initialization happens through InitializeAsteroidBelt
	if (!HasAuthority())
	{
		UE_LOG(LogTemp, Verbose, TEXT("AsteroidBeltActor: Running on client"));
	}
}

void AAsteroidBeltActor::InitializeAsteroidBelt(
	const FGuid& InBeltId,
	const FString& InBeltName,
	int32 Seed,
	float BeltRadius,
	int32 InAsteroidCount,
	const FAsteroidBeltVisualRow& VisualData)
{
	BeltId = InBeltId;
	BeltName = InBeltName;
	GenerationSeed = Seed;
	Radius = BeltRadius;
	AsteroidCount = InAsteroidCount;

	UE_LOG(LogTemp, Log, TEXT("Initializing Asteroid Belt: %s (Seed: %d, Radius: %.0f, Count: %d)"),
		*BeltName, GenerationSeed, Radius, AsteroidCount);

	SetActorScale3D(VisualData.ActorScale);

	// Generate procedural asteroid positions
	GenerateAsteroidPositions(AsteroidCount, Radius, GenerationSeed);

	// Setup collision for mining
	SetupAsteroidCollision();

	// Spawn environmental effects
	SpawnEnvironmentalEffects(VisualData);

	UE_LOG(LogTemp, Log, TEXT("✓ Asteroid Belt '%s' initialized with %d asteroids"), *BeltName, AsteroidCount);
}

void AAsteroidBeltActor::GenerateAsteroidPositions(int32 Count, float BeltRadius, int32 Seed)
{
	if (!AsteroidInstances || Count <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Cannot generate asteroids: Invalid parameters"));
		return;
	}

	// Initialize random stream with seed for deterministic generation
	FRandomStream RandomStream(Seed);

	// Belt parameters
	const float InnerRadiusRatio = 0.7f; // Belt starts at 70% of outer radius
	const float BeltThickness = BeltRadius * 0.2f; // Belt is 20% thick vertically

	UE_LOG(LogTemp, Log, TEXT("Generating %d asteroid positions (InnerRadius: %.0f, OuterRadius: %.0f, Thickness: %.0f)"),
		Count, BeltRadius * InnerRadiusRatio, BeltRadius, BeltThickness);

	for (int32 i = 0; i < Count; i++)
	{
		// Generate position in toroidal (donut) shape
		float DistanceFromCenter = RandomStream.FRandRange(BeltRadius * InnerRadiusRatio, BeltRadius);
		float Angle = RandomStream.FRandRange(0.0f, 360.0f);
		float VerticalOffset = RandomStream.FRandRange(-BeltThickness * 0.5f, BeltThickness * 0.5f);

		// Convert to Cartesian coordinates
		float X = DistanceFromCenter * FMath::Cos(FMath::DegreesToRadians(Angle));
		float Y = DistanceFromCenter * FMath::Sin(FMath::DegreesToRadians(Angle));
		float Z = VerticalOffset;

		FVector Position(X, Y, Z);

		// Random rotation for variation
		FRotator Rotation(
			RandomStream.FRandRange(0.0f, 360.0f),
			RandomStream.FRandRange(0.0f, 360.0f),
			RandomStream.FRandRange(0.0f, 360.0f));

		// Random scale for variation (0.5x to 2.0x)
		float Scale = RandomStream.FRandRange(0.5f, 2.0f);
		FVector ScaleVector(Scale, Scale, Scale);

		// Create transform and add instance
		FTransform InstanceTransform(Rotation, Position, ScaleVector);
		AsteroidInstances->AddInstance(InstanceTransform);
	}

	UE_LOG(LogTemp, Log, TEXT("✓ Generated %d asteroid instances"), AsteroidInstances->GetInstanceCount());
}

void AAsteroidBeltActor::SetupAsteroidCollision()
{
	// HISM automatically handles collision for all instances
	// Individual asteroids can be detected via collision queries
	AsteroidInstances->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	AsteroidInstances->SetCollisionObjectType(ECollisionChannel::ECC_WorldStatic);
	AsteroidInstances->SetCollisionResponseToAllChannels(ECR_Block);

	UE_LOG(LogTemp, Verbose, TEXT("✓ Asteroid collision setup complete"));
}

void AAsteroidBeltActor::SpawnEnvironmentalEffects(const FAsteroidBeltVisualRow& VisualData)
{
	// Spawn dust cloud VFX if available
	if (!VisualData.DustCloudVFX.IsNull())
	{
		UNiagaraSystem* DustVFX = VisualData.DustCloudVFX.LoadSynchronous();
		if (DustVFX && DustCloudComponent)
		{
			DustCloudComponent->SetAsset(DustVFX);
			DustCloudComponent->SetWorldScale3D(FVector(Radius / 10000.0f)); // Scale based on belt size
			DustCloudComponent->Activate();
			UE_LOG(LogTemp, Log, TEXT("✓ Dust cloud VFX activated"));
		}
	}

	// Setup ambient sound if available
	if (!VisualData.AmbientSound.IsNull())
	{
		USoundBase* AmbientSound = VisualData.AmbientSound.LoadSynchronous();
		if (AmbientSound && AmbientAudioComponent)
		{
			AmbientAudioComponent->SetSound(AmbientSound);
			AmbientAudioComponent->SetVolumeMultiplier(0.3f); // Subtle ambient sound
			AmbientAudioComponent->Activate();
			UE_LOG(LogTemp, Log, TEXT("✓ Ambient audio activated"));
		}
	}
}

void AAsteroidBeltActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AAsteroidBeltActor, BeltId);
	DOREPLIFETIME(AAsteroidBeltActor, BeltName);
}
