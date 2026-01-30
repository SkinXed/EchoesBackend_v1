// Copyright Epic Games, Inc. All Rights Reserved.

#include "StationActor.h"
#include "Net/UnrealNetwork.h"
#include "Components/StaticMeshComponent.h"
#include "NiagaraComponent.h"

AStationActor::AStationActor()
{
	PrimaryActorTick.bCanEverTick = false;

	// Enable replication
	bReplicates = true;
	bAlwaysRelevant = true;

	// Create root component
	USceneComponent* RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = RootComp;

	// Create base mesh component
	BaseMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	BaseMeshComponent->SetupAttachment(RootComponent);
	BaseMeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	// Create navigation lights component
	LightsComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("NavigationLights"));
	LightsComponent->SetupAttachment(BaseMeshComponent);
	LightsComponent->SetAutoActivate(true);
}

void AStationActor::BeginPlay()
{
	Super::BeginPlay();

	if (!HasAuthority())
	{
		ApplyVisualConfiguration();
	}
}

void AStationActor::InitializeStation(
	const FGuid& InStationId,
	const FString& InName,
	const FString& InStationType,
	int32 InSeed,
	const FStationVisualRow& InVisualData)
{
	if (!HasAuthority())
	{
		UE_LOG(LogTemp, Warning, TEXT("InitializeStation called on client - ignoring"));
		return;
	}

	StationId = InStationId;
	StationName = InName;
	StationType = InStationType;
	Seed = InSeed;
	VisualData = InVisualData;

	UE_LOG(LogTemp, Log, TEXT("Initializing Station: %s (Type: %s, Seed: %d)"),
		*StationName, *StationType, Seed);

	ApplyVisualConfiguration();
	ApplySeedVariation();
}

void AStationActor::ApplyVisualConfiguration()
{
	// Set base mesh and materials
	// In production: Load async with UStreamableManager
	
	// Set navigation lights
	if (LightsComponent && !VisualData.LightsPattern.IsNull())
	{
		LightsComponent->SetVisibility(true);
	}
	else if (LightsComponent)
	{
		LightsComponent->SetVisibility(false);
	}
}

void AStationActor::ApplySeedVariation()
{
	if (!HasAuthority())
	{
		return;
	}

	FRandomStream RandomStream(Seed);

	// Apply scale variation
	float ScaleVariation = RandomStream.FRandRange(VisualData.ScaleRange.X, VisualData.ScaleRange.Y);
	BaseMeshComponent->SetRelativeScale3D(FVector(ScaleVariation));

	// Random rotation
	FRotator RandomRotation(0.0f, RandomStream.FRandRange(0.0f, 360.0f), 0.0f);
	BaseMeshComponent->SetRelativeRotation(RandomRotation);

	UE_LOG(LogTemp, Verbose, TEXT("Applied seed variation to station %s: Rotation=%.1f, Scale=%.2f"),
		*StationName, RandomRotation.Yaw, ScaleVariation);
}

void AStationActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AStationActor, StationId);
	DOREPLIFETIME(AStationActor, StationName);
	DOREPLIFETIME(AStationActor, StationType);
	DOREPLIFETIME(AStationActor, Seed);
}

void AStationActor::OnRep_StationData()
{
	ApplyVisualConfiguration();
}
