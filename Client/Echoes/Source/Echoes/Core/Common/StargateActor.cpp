// Copyright Epic Games, Inc. All Rights Reserved.

#include "StargateActor.h"
#include "Net/UnrealNetwork.h"
#include "Components/StaticMeshComponent.h"
#include "Components/AudioComponent.h"
#include "NiagaraComponent.h"

AStargateActor::AStargateActor()
{
	PrimaryActorTick.bCanEverTick = true;

	// Enable replication
	bReplicates = true;
	bAlwaysRelevant = true;

	// Create root component
	USceneComponent* RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = RootComp;

	// Create gate mesh component
	GateMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GateMesh"));
	GateMeshComponent->SetupAttachment(RootComponent);
	GateMeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	// Create portal VFX component
	PortalVFXComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("PortalVFX"));
	PortalVFXComponent->SetupAttachment(GateMeshComponent);
	PortalVFXComponent->SetAutoActivate(true);

	// Create destination marker VFX
	DestinationFXComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("DestinationFX"));
	DestinationFXComponent->SetupAttachment(GateMeshComponent);
	DestinationFXComponent->SetAutoActivate(true);

	// Create ambient audio component
	AmbientAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("AmbientAudio"));
	AmbientAudioComponent->SetupAttachment(GateMeshComponent);
	AmbientAudioComponent->bAutoActivate = true;

	CurrentRotationAngle = 0.0f;
}

void AStargateActor::BeginPlay()
{
	Super::BeginPlay();

	if (!HasAuthority())
	{
		ApplyVisualConfiguration();
	}
}

void AStargateActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Update ring rotation animation
	if (VisualData.RingRotationSpeed > 0.0f)
	{
		UpdateRingRotation(DeltaTime);
	}
}

void AStargateActor::InitializeStargate(
	const FGuid& InGateId,
	const FString& InName,
	const FGuid& InTargetSystemId,
	const FString& InTargetSystemName,
	bool bInIsOperational,
	const FStargateVisualRow& InVisualData)
{
	if (!HasAuthority())
	{
		UE_LOG(LogTemp, Warning, TEXT("InitializeStargate called on client - ignoring"));
		return;
	}

	GateId = InGateId;
	GateName = InName;
	TargetSystemId = InTargetSystemId;
	TargetSystemName = InTargetSystemName;
	bIsOperational = bInIsOperational;
	VisualData = InVisualData;

	UE_LOG(LogTemp, Log, TEXT("Initializing Stargate: %s -> %s (Operational: %s)"),
		*GateName, *TargetSystemName, bIsOperational ? TEXT("Yes") : TEXT("No"));

	ApplyVisualConfiguration();
}

void AStargateActor::ApplyVisualConfiguration()
{
	// Set gate mesh and materials
	// In production: Load async with UStreamableManager

	// Enable/disable portal VFX based on operational status
	if (PortalVFXComponent)
	{
		if (bIsOperational && !VisualData.PortalVFX.IsNull())
		{
			PortalVFXComponent->SetVisibility(true);
		}
		else
		{
			PortalVFXComponent->SetVisibility(false);
		}
	}

	// Set destination marker VFX
	if (DestinationFXComponent)
	{
		if (bIsOperational && !VisualData.DestinationFX.IsNull())
		{
			DestinationFXComponent->SetVisibility(true);
		}
		else
		{
			DestinationFXComponent->SetVisibility(false);
		}
	}

	// Set ambient audio
	if (AmbientAudioComponent && bIsOperational)
	{
		// In production: Load async
		AmbientAudioComponent->SetActive(true);
	}
	else if (AmbientAudioComponent)
	{
		AmbientAudioComponent->SetActive(false);
	}
}

void AStargateActor::UpdateRingRotation(float DeltaTime)
{
	if (!GateMeshComponent)
	{
		return;
	}

	// Update rotation angle
	CurrentRotationAngle += VisualData.RingRotationSpeed * DeltaTime;
	if (CurrentRotationAngle >= 360.0f)
	{
		CurrentRotationAngle -= 360.0f;
	}

	// Apply rotation to gate mesh
	FRotator NewRotation = GateMeshComponent->GetRelativeRotation();
	NewRotation.Roll = CurrentRotationAngle;
	GateMeshComponent->SetRelativeRotation(NewRotation);
}

void AStargateActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AStargateActor, GateId);
	DOREPLIFETIME(AStargateActor, GateName);
	DOREPLIFETIME(AStargateActor, TargetSystemId);
	DOREPLIFETIME(AStargateActor, TargetSystemName);
	DOREPLIFETIME(AStargateActor, bIsOperational);
}

void AStargateActor::OnRep_GateData()
{
	ApplyVisualConfiguration();
}
