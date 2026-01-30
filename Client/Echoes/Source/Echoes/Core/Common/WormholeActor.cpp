// Copyright Epic Games, Inc. All Rights Reserved.

#include "WormholeActor.h"
#include "Net/UnrealNetwork.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "Components/AudioComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"
#include "Kismet/KismetMathLibrary.h"

AWormholeActor::AWormholeActor()
{
	PrimaryActorTick.bCanEverTick = false;

	// Enable replication
	bReplicates = true;
	bAlwaysRelevant = true;

	// Create root component
	RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = RootSceneComponent;

	// Create entrance mesh component (optional structural ring)
	EntranceMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EntranceMesh"));
	EntranceMeshComponent->SetupAttachment(RootComponent);
	EntranceMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// Create main wormhole VFX component
	WormholeVFXComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("WormholeVFX"));
	WormholeVFXComponent->SetupAttachment(RootComponent);
	WormholeVFXComponent->SetAutoActivate(true);

	// Create instability VFX component
	InstabilityVFXComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("InstabilityVFX"));
	InstabilityVFXComponent->SetupAttachment(RootComponent);
	InstabilityVFXComponent->SetAutoActivate(false);

	// Create ambient audio component
	AmbientAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("AmbientAudio"));
	AmbientAudioComponent->SetupAttachment(RootComponent);
	AmbientAudioComponent->bAutoActivate = false;

	// Create entrance sound component
	EntranceSoundComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("EntranceSound"));
	EntranceSoundComponent->SetupAttachment(RootComponent);
	EntranceSoundComponent->bAutoActivate = false;

	// Create trigger sphere for jump detection
	TriggerSphere = CreateDefaultSubobject<USphereComponent>(TEXT("TriggerSphere"));
	TriggerSphere->SetupAttachment(RootComponent);
	TriggerSphere->SetSphereRadius(2000.0f); // 2000 Unreal Units (20m if 1 UU = 1cm)
	TriggerSphere->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	TriggerSphere->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	TriggerSphere->SetGenerateOverlapEvents(true);

	GenerationSeed = 0;
	WormholeColor = FLinearColor::White;
}

void AWormholeActor::BeginPlay()
{
	Super::BeginPlay();

	// Bind trigger overlap event
	if (HasAuthority())
	{
		TriggerSphere->OnComponentBeginOverlap.AddDynamic(this, &AWormholeActor::OnTriggerBeginOverlap);
		UE_LOG(LogTemp, Log, TEXT("WormholeActor: Trigger overlap bound on server"));
	}
}

void AWormholeActor::InitializeWormhole(
	const FGuid& InWormholeId,
	const FString& InWormholeName,
	const FGuid& InTargetSystemId,
	int32 Seed,
	const FWormholeVisualRow& VisualData)
{
	WormholeId = InWormholeId;
	WormholeName = InWormholeName;
	TargetSystemId = InTargetSystemId;
	GenerationSeed = Seed;

	// Generate unique color based on target system
	WormholeColor = GenerateWormholeColor(TargetSystemId);

	UE_LOG(LogTemp, Log, TEXT("Initializing Wormhole: %s -> System %s (Seed: %d, Color: %s)"),
		*WormholeName, *TargetSystemId.ToString(), GenerationSeed, *WormholeColor.ToString());

	// Load entrance mesh if available
	if (!VisualData.EntranceMesh.IsNull())
	{
		UStaticMesh* EntranceMesh = VisualData.EntranceMesh.LoadSynchronous();
		if (EntranceMesh && EntranceMeshComponent)
		{
			EntranceMeshComponent->SetStaticMesh(EntranceMesh);
			UE_LOG(LogTemp, Log, TEXT("✓ Entrance mesh loaded"));
		}
	}

	// Apply entrance material
	if (!VisualData.EntranceMaterial.IsNull())
	{
		UMaterialInstance* Material = VisualData.EntranceMaterial.LoadSynchronous();
		if (Material && EntranceMeshComponent)
		{
			EntranceMeshComponent->SetMaterial(0, Material);
		}
	}

	// Load and setup wormhole VFX
	if (!VisualData.WormholeVFX.IsNull())
	{
		UNiagaraSystem* WormholeVFX = VisualData.WormholeVFX.LoadSynchronous();
		if (WormholeVFX && WormholeVFXComponent)
		{
			WormholeVFXComponent->SetAsset(WormholeVFX);
			WormholeVFXComponent->SetColorParameter(FName("WormholeColor"), WormholeColor);
			WormholeVFXComponent->Activate();
			UE_LOG(LogTemp, Log, TEXT("✓ Wormhole VFX loaded with color %s"), *WormholeColor.ToString());
		}
	}

	// Setup distortion effects
	SetupDistortionEffects(VisualData);

	// Setup ambient audio
	if (!VisualData.AmbientSound.IsNull())
	{
		USoundBase* AmbientSound = VisualData.AmbientSound.LoadSynchronous();
		if (AmbientSound && AmbientAudioComponent)
		{
			AmbientAudioComponent->SetSound(AmbientSound);
			AmbientAudioComponent->SetVolumeMultiplier(0.5f);
			AmbientAudioComponent->Activate();
		}
	}

	// Setup entrance sound
	if (!VisualData.EntranceSound.IsNull())
	{
		USoundBase* EntranceSound = VisualData.EntranceSound.LoadSynchronous();
		if (EntranceSound && EntranceSoundComponent)
		{
			EntranceSoundComponent->SetSound(EntranceSound);
		}
	}

	// Setup trigger zone
	SetupTriggerZone();

	UE_LOG(LogTemp, Log, TEXT("✓ Wormhole '%s' initialized"), *WormholeName);
}

FLinearColor AWormholeActor::GenerateWormholeColor(const FGuid& TargetId) const
{
	// Generate a unique color based on the target system GUID
	// Use the GUID components to create a deterministic color
	
	// Use XOR of GUID components to create seed
	uint32 ColorSeed = TargetId.A ^ TargetId.B ^ TargetId.C ^ TargetId.D;
	
	// Create random stream with seed
	FRandomStream RandomStream(ColorSeed);
	
	// Generate color with bias towards blue/purple/cyan (space-like colors)
	float R = RandomStream.FRandRange(0.2f, 0.7f);
	float G = RandomStream.FRandRange(0.3f, 0.8f);
	float B = RandomStream.FRandRange(0.6f, 1.0f); // Always strong blue component
	
	return FLinearColor(R, G, B, 1.0f);
}

void AWormholeActor::SetupDistortionEffects(const FWormholeVisualRow& VisualData)
{
	// Load instability VFX if available
	if (!VisualData.InstabilityVFX.IsNull())
	{
		UNiagaraSystem* InstabilityVFX = VisualData.InstabilityVFX.LoadSynchronous();
		if (InstabilityVFX && InstabilityVFXComponent)
		{
			InstabilityVFXComponent->SetAsset(InstabilityVFX);
			
			// Randomly activate instability based on seed
			FRandomStream RandomStream(GenerationSeed);
			if (RandomStream.FRand() > 0.7f) // 30% chance of instability
			{
				InstabilityVFXComponent->Activate();
				UE_LOG(LogTemp, Log, TEXT("✓ Wormhole is unstable - instability VFX activated"));
			}
		}
	}

	// Distortion post-process material would be applied via post-process volume
	// This is typically handled by a separate system or blueprint
	UE_LOG(LogTemp, Verbose, TEXT("✓ Distortion effects configured"));
}

void AWormholeActor::SetupTriggerZone()
{
	// Trigger zone is already created and configured in constructor
	// Overlap events are bound in BeginPlay
	UE_LOG(LogTemp, Verbose, TEXT("✓ Trigger zone configured"));
}

void AWormholeActor::OnTriggerBeginOverlap(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	if (!HasAuthority())
	{
		return;
	}

	if (!OtherActor || OtherActor == this)
	{
		return;
	}

	// Check if the actor is a ship/player
	// This is a placeholder - actual ship detection would depend on your ship class
	UE_LOG(LogTemp, Log, TEXT("Actor entered wormhole trigger: %s"), *OtherActor->GetName());

	// Play entrance sound
	if (EntranceSoundComponent && EntranceSoundComponent->Sound)
	{
		EntranceSoundComponent->Play();
	}

	// Initiate jump sequence
	InitiateJump(OtherActor);
}

void AWormholeActor::InitiateJump(AActor* Ship)
{
	if (!HasAuthority() || !Ship)
	{
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Initiating wormhole jump for %s to system %s"),
		*Ship->GetName(), *TargetSystemId.ToString());

	// TODO: Implement actual jump logic
	// This would typically:
	// 1. Notify the server management subsystem
	// 2. Trigger a travel to the target system server
	// 3. Apply jump cooldown/costs
	// 4. Play jump animation/effects
	
	// Placeholder for now
	UE_LOG(LogTemp, Warning, TEXT("⚠ Jump logic not yet implemented - would jump to system: %s"),
		*TargetSystemId.ToString());
}

void AWormholeActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AWormholeActor, WormholeId);
	DOREPLIFETIME(AWormholeActor, WormholeName);
	DOREPLIFETIME(AWormholeActor, TargetSystemId);
}
