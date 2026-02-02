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
	PrimaryActorTick.bCanEverTick = true;

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

	// Initialize instability properties
	MassCapacity = 10000000.0f; // 10 million metric tons default
	CurrentMassUsed = 0.0f;
	InitialLifetime = 86400.0f; // 24 hours default
	RemainingLifetime = InitialLifetime;
	bIsCollapsing = false;

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

void AWormholeActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Server-only degradation logic
	if (!HasAuthority())
	{
		return;
	}

	// Decrease remaining lifetime
	if (RemainingLifetime > 0.0f && !bIsCollapsing)
	{
		RemainingLifetime -= DeltaTime;

		// Check if wormhole should collapse
		if (RemainingLifetime <= 0.0f || CurrentMassUsed >= MassCapacity)
		{
			TriggerCollapse();
		}
		// Update instability effects as wormhole degrades
		else if (GetStabilityPercentage() < TICK_INSTABILITY_THRESHOLD)
		{
			UpdateInstabilityEffects();
		}
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

	SetActorScale3D(VisualData.ActorScale);

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

	// Check if wormhole can accommodate the ship
	float ShipMass = DEFAULT_SHIP_MASS_PLACEHOLDER; // TODO: Get actual ship mass from ship actor
	
	if (!CanAccommodateShip(ShipMass))
	{
		UE_LOG(LogTemp, Warning, TEXT("Wormhole cannot accommodate ship (mass: %.0f, remaining capacity: %.0f)"),
			ShipMass, MassCapacity - CurrentMassUsed);
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("╔══════════════════════════════════════════════════════════╗"));
	UE_LOG(LogTemp, Log, TEXT("║    INITIATING WORMHOLE JUMP                             ║"));
	UE_LOG(LogTemp, Log, TEXT("╚══════════════════════════════════════════════════════════╝"));
	UE_LOG(LogTemp, Log, TEXT("Ship: %s"), *Ship->GetName());
	UE_LOG(LogTemp, Log, TEXT("Wormhole: %s"), *WormholeName);
	UE_LOG(LogTemp, Log, TEXT("Target System: %s"), *TargetSystemId.ToString());
	UE_LOG(LogTemp, Log, TEXT("Ship Mass: %.0f tons"), ShipMass);
	UE_LOG(LogTemp, Log, TEXT("Remaining Capacity: %.0f / %.0f tons"), MassCapacity - CurrentMassUsed, MassCapacity);
	UE_LOG(LogTemp, Log, TEXT("Remaining Lifetime: %.0f seconds"), RemainingLifetime);

	// Process ship passage through wormhole
	ProcessShipPassage(Ship, ShipMass);

	// TODO: Add randomness element if configured in DB
	// FRandomStream RandomStream(GenerationSeed);
	// bool bRandomSuccess = RandomStream.FRand() > 0.1f; // 90% success rate

	// TODO: Implement actual jump logic (similar to stargate)
	UE_LOG(LogTemp, Warning, TEXT("⚠ Wormhole jump logic not fully implemented"));
}

void AWormholeActor::ProcessShipPassage(AActor* Ship, float ShipMass)
{
	if (!HasAuthority())
	{
		return;
	}

	// Reduce mass capacity
	CurrentMassUsed += ShipMass;

	// Reduce lifetime proportionally to mass used
	float LifetimeReduction = (ShipMass / MassCapacity) * InitialLifetime * LIFETIME_REDUCTION_FACTOR;
	RemainingLifetime -= LifetimeReduction;

	UE_LOG(LogTemp, Log, TEXT("Wormhole degradation: Mass used: %.0f / %.0f, Lifetime remaining: %.0f seconds"),
		CurrentMassUsed, MassCapacity, RemainingLifetime);

	// Update instability effects
	UpdateInstabilityEffects();

	// Check if should collapse
	if (CurrentMassUsed >= MassCapacity * CRITICAL_MASS_THRESHOLD || RemainingLifetime <= CRITICAL_LIFETIME_THRESHOLD)
	{
		UE_LOG(LogTemp, Warning, TEXT("⚠ Wormhole critically unstable!"));
	}
}

bool AWormholeActor::CanAccommodateShip(float ShipMass) const
{
	// Check if wormhole is already collapsing
	if (bIsCollapsing)
	{
		return false;
	}

	// Check if there's enough mass capacity
	if (CurrentMassUsed + ShipMass > MassCapacity)
	{
		return false;
	}

	// Check if there's enough time
	if (RemainingLifetime <= 0.0f)
	{
		return false;
	}

	return true;
}

float AWormholeActor::GetStabilityPercentage() const
{
	// Prevent division by zero
	if (MassCapacity <= 0.0f || InitialLifetime <= 0.0f)
	{
		return 0.0f;
	}

	// Calculate stability based on mass used and lifetime remaining
	float MassStability = 1.0f - (CurrentMassUsed / MassCapacity);
	float TimeStability = RemainingLifetime / InitialLifetime;

	// Return the lower of the two (worst case)
	return FMath::Min(MassStability, TimeStability);
}

void AWormholeActor::TriggerCollapse()
{
	if (!HasAuthority())
	{
		return;
	}

	if (bIsCollapsing)
	{
		return; // Already collapsing
	}

	UE_LOG(LogTemp, Warning, TEXT("╔══════════════════════════════════════════════════════════╗"));
	UE_LOG(LogTemp, Warning, TEXT("║    WORMHOLE COLLAPSING                                  ║"));
	UE_LOG(LogTemp, Warning, TEXT("╚══════════════════════════════════════════════════════════╝"));
	UE_LOG(LogTemp, Warning, TEXT("Wormhole: %s"), *WormholeName);
	UE_LOG(LogTemp, Warning, TEXT("Mass Used: %.0f / %.0f"), CurrentMassUsed, MassCapacity);
	UE_LOG(LogTemp, Warning, TEXT("Lifetime Remaining: %.0f seconds"), RemainingLifetime);

	bIsCollapsing = true;

	// Activate instability VFX
	if (InstabilityVFXComponent)
	{
		InstabilityVFXComponent->Activate(true);
	}

	// Disable trigger zone to prevent new ships from entering
	if (TriggerSphere)
	{
		TriggerSphere->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}

	// Schedule destruction after collapse animation
	FTimerHandle CollapseTimer;
	FTimerDelegate CollapseDelegate;
	
	// Use weak pointer to safely handle actor destruction
	TWeakObjectPtr<AWormholeActor> WeakThis(this);
	CollapseDelegate.BindLambda([WeakThis]()
	{
		if (WeakThis.IsValid())
		{
			UE_LOG(LogTemp, Log, TEXT("Destroying collapsed wormhole: %s"), *WeakThis->WormholeName);
			WeakThis->Destroy();
		}
	});
	
	GetWorld()->GetTimerManager().SetTimer(CollapseTimer, CollapseDelegate, COLLAPSE_ANIMATION_DURATION, false);
}

void AWormholeActor::UpdateInstabilityEffects()
{
	float Stability = GetStabilityPercentage();

	// Activate instability VFX when stability drops below threshold
	if (Stability < VFX_INSTABILITY_THRESHOLD && InstabilityVFXComponent)
	{
		if (!InstabilityVFXComponent->IsActive())
		{
			InstabilityVFXComponent->Activate();
			UE_LOG(LogTemp, Warning, TEXT("Wormhole '%s' becoming unstable (%.0f%% stability)"),
				*WormholeName, Stability * 100.0f);
		}

		// Increase instability intensity as stability decreases
		float Intensity = 1.0f - Stability;
		InstabilityVFXComponent->SetFloatParameter(FName("Intensity"), Intensity);
	}
}

void AWormholeActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AWormholeActor, WormholeId);
	DOREPLIFETIME(AWormholeActor, WormholeName);
	DOREPLIFETIME(AWormholeActor, TargetSystemId);
	DOREPLIFETIME(AWormholeActor, MassCapacity);
	DOREPLIFETIME(AWormholeActor, CurrentMassUsed);
	DOREPLIFETIME(AWormholeActor, RemainingLifetime);
	DOREPLIFETIME(AWormholeActor, bIsCollapsing);
}
