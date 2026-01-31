// Copyright Epic Games, Inc. All Rights Reserved.

#include "AnomalyActor.h"
#include "Net/UnrealNetwork.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "Components/AudioComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"

AAnomalyActor::AAnomalyActor()
{
	PrimaryActorTick.bCanEverTick = false;

	// Enable replication
	bReplicates = true;
	bAlwaysRelevant = true;

	// Create root component
	RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = RootSceneComponent;

	// Create center mesh component
	CenterMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CenterMesh"));
	CenterMeshComponent->SetupAttachment(RootComponent);
	CenterMeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CenterMeshComponent->SetCollisionProfileName(TEXT("OverlapAllDynamic"));

	// Create signature VFX component
	SignatureVFXComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("SignatureVFX"));
	SignatureVFXComponent->SetupAttachment(RootComponent);
	SignatureVFXComponent->SetAutoActivate(false);

	// Create type-specific VFX component
	TypeVFXComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("TypeVFX"));
	TypeVFXComponent->SetupAttachment(RootComponent);
	TypeVFXComponent->SetAutoActivate(true);

	// Create ambient audio component
	AmbientAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("AmbientAudio"));
	AmbientAudioComponent->SetupAttachment(RootComponent);
	AmbientAudioComponent->bAutoActivate = false;

	// Create warning audio component
	WarningAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("WarningAudio"));
	WarningAudioComponent->SetupAttachment(RootComponent);
	WarningAudioComponent->bAutoActivate = false;

	// Create trigger sphere for interaction
	TriggerSphere = CreateDefaultSubobject<USphereComponent>(TEXT("TriggerSphere"));
	TriggerSphere->SetupAttachment(RootComponent);
	TriggerSphere->SetSphereRadius(5000.0f); // 5000 Unreal Units (50m if 1 UU = 1cm)
	TriggerSphere->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	TriggerSphere->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	TriggerSphere->SetGenerateOverlapEvents(true);

	GenerationSeed = 0;
	bSignatureActive = false;
}

void AAnomalyActor::BeginPlay()
{
	Super::BeginPlay();

	if (!HasAuthority())
	{
		UE_LOG(LogTemp, Verbose, TEXT("AnomalyActor: Running on client"));
	}
}

void AAnomalyActor::InitializeAnomaly(
	const FGuid& InAnomalyId,
	const FString& InAnomalyName,
	const FString& InAnomalyType,
	const FString& InAnomalyDifficulty,
	int32 Seed,
	const FAnomalyVisualRow& VisualData)
{
	AnomalyId = InAnomalyId;
	AnomalyName = InAnomalyName;
	AnomalyType = InAnomalyType;
	AnomalyDifficulty = InAnomalyDifficulty;
	GenerationSeed = Seed;

	UE_LOG(LogTemp, Log, TEXT("Initializing Anomaly: %s (Type: %s, Difficulty: %s, Seed: %d)"),
		*AnomalyName, *AnomalyType, *AnomalyDifficulty, GenerationSeed);

	// Load center mesh from visual data
	if (!VisualData.CenterMesh.IsNull())
	{
		UStaticMesh* CenterMesh = VisualData.CenterMesh.LoadSynchronous();
		if (CenterMesh && CenterMeshComponent)
		{
			CenterMeshComponent->SetStaticMesh(CenterMesh);
			UE_LOG(LogTemp, Log, TEXT("✓ Center mesh loaded"));
		}
	}

	// Apply center material
	if (!VisualData.CenterMaterial.IsNull())
	{
		UMaterialInstance* Material = VisualData.CenterMaterial.LoadSynchronous();
		if (Material && CenterMeshComponent)
		{
			CenterMeshComponent->SetMaterial(0, Material);
		}
	}

	// Setup type-specific visuals
	SetupTypeSpecificVisuals(AnomalyType, VisualData);

	// Load signature VFX (for scanning)
	if (!VisualData.SignatureVFX.IsNull())
	{
		UNiagaraSystem* SignatureVFX = VisualData.SignatureVFX.LoadSynchronous();
		if (SignatureVFX && SignatureVFXComponent)
		{
			SignatureVFXComponent->SetAsset(SignatureVFX);
			// Don't activate yet - will be activated when scanned
			UE_LOG(LogTemp, Log, TEXT("✓ Signature VFX loaded"));
		}
	}

	// Setup difficulty indicators
	SetupDifficultyIndicators(AnomalyDifficulty, VisualData);

	// Setup trigger zone
	SetupTriggerZone();

	// Setup ambient audio
	if (!VisualData.AmbientSound.IsNull())
	{
		USoundBase* AmbientSound = VisualData.AmbientSound.LoadSynchronous();
		if (AmbientSound && AmbientAudioComponent)
		{
			AmbientAudioComponent->SetSound(AmbientSound);
			AmbientAudioComponent->SetVolumeMultiplier(0.4f);
			AmbientAudioComponent->Activate();
		}
	}

	UE_LOG(LogTemp, Log, TEXT("✓ Anomaly '%s' initialized"), *AnomalyName);
}

void AAnomalyActor::SetupTypeSpecificVisuals(const FString& Type, const FAnomalyVisualRow& VisualData)
{
	// Load type-specific VFX
	if (!VisualData.TypeSpecificVFX.IsNull())
	{
		UNiagaraSystem* TypeVFX = VisualData.TypeSpecificVFX.LoadSynchronous();
		if (TypeVFX && TypeVFXComponent)
		{
			TypeVFXComponent->SetAsset(TypeVFX);
			TypeVFXComponent->Activate();
			UE_LOG(LogTemp, Log, TEXT("✓ Type-specific VFX loaded for %s"), *Type);
		}
	}

	// Apply signature color based on type
	FLinearColor SignatureColor = VisualData.SignatureColor;
	
	// Override color based on type if needed
	if (Type.Equals(TEXT("Combat"), ESearchCase::IgnoreCase))
	{
		SignatureColor = FLinearColor(1.0f, 0.0f, 0.0f, 1.0f); // Red for combat
	}
	else if (Type.Equals(TEXT("Data"), ESearchCase::IgnoreCase))
	{
		SignatureColor = FLinearColor(0.0f, 0.5f, 1.0f, 1.0f); // Blue for data
	}
	else if (Type.Equals(TEXT("Relic"), ESearchCase::IgnoreCase))
	{
		SignatureColor = FLinearColor(1.0f, 0.8f, 0.0f, 1.0f); // Gold for relics
	}
	else if (Type.Equals(TEXT("Gas"), ESearchCase::IgnoreCase))
	{
		SignatureColor = FLinearColor(0.5f, 1.0f, 0.5f, 1.0f); // Green for gas
	}

	// Apply color to VFX if available
	if (TypeVFXComponent)
	{
		TypeVFXComponent->SetColorParameter(FName("SignatureColor"), SignatureColor);
	}
}

void AAnomalyActor::SetupDifficultyIndicators(const FString& Difficulty, const FAnomalyVisualRow& VisualData)
{
	// Scale effects based on difficulty
	float ScaleMultiplier = 1.0f;
	
	if (Difficulty.Equals(TEXT("Easy"), ESearchCase::IgnoreCase))
	{
		ScaleMultiplier = 0.8f;
	}
	else if (Difficulty.Equals(TEXT("Medium"), ESearchCase::IgnoreCase))
	{
		ScaleMultiplier = 1.0f;
	}
	else if (Difficulty.Equals(TEXT("Hard"), ESearchCase::IgnoreCase))
	{
		ScaleMultiplier = 1.3f;
	}
	else if (Difficulty.Equals(TEXT("Elite"), ESearchCase::IgnoreCase))
	{
		ScaleMultiplier = 1.6f;
	}

	// Apply scale to center mesh
	if (CenterMeshComponent)
	{
		CenterMeshComponent->SetWorldScale3D(FVector(ScaleMultiplier));
	}

	// Adjust trigger radius based on difficulty
	if (TriggerSphere)
	{
		TriggerSphere->SetSphereRadius(5000.0f * ScaleMultiplier);
	}

	UE_LOG(LogTemp, Verbose, TEXT("✓ Difficulty indicators set for %s (Scale: %.2f)"), *Difficulty, ScaleMultiplier);
}

void AAnomalyActor::SetupTriggerZone()
{
	// Trigger zone is already created in constructor
	// Can be extended with gameplay logic here
	UE_LOG(LogTemp, Verbose, TEXT("✓ Trigger zone configured"));
}

void AAnomalyActor::ActivateScanningSignature()
{
	if (bSignatureActive)
	{
		return;
	}

	bSignatureActive = true;

	// Activate signature VFX
	if (SignatureVFXComponent && SignatureVFXComponent->GetAsset())
	{
		SignatureVFXComponent->Activate();
		UE_LOG(LogTemp, Log, TEXT("✓ Scanning signature activated for %s"), *AnomalyName);
	}
}

void AAnomalyActor::DeactivateScanningSignature()
{
	if (!bSignatureActive)
	{
		return;
	}

	bSignatureActive = false;

	// Deactivate signature VFX
	if (SignatureVFXComponent)
	{
		SignatureVFXComponent->Deactivate();
		UE_LOG(LogTemp, Log, TEXT("✓ Scanning signature deactivated for %s"), *AnomalyName);
	}
}

void AAnomalyActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AAnomalyActor, AnomalyId);
	DOREPLIFETIME(AAnomalyActor, AnomalyName);
	DOREPLIFETIME(AAnomalyActor, AnomalyType);
	DOREPLIFETIME(AAnomalyActor, AnomalyDifficulty);
	DOREPLIFETIME(AAnomalyActor, bSignatureActive);
}
