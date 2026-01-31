// Copyright Epic Games, Inc. All Rights Reserved.

#include "Core/Common/EchoesItemActor.h"
#include "Core/Common/EchoesInventoryComponent.h"
#include "Core/Common/Networking/EchoesInventorySubsystem.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Engine/StaticMesh.h"
#include "Net/UnrealNetwork.h"
#include "TimerManager.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"

AEchoesItemActor::AEchoesItemActor()
{
	PrimaryActorTick.bCanEverTick = false;
	
	// Enable replication
	bReplicates = true;
	bAlwaysRelevant = false;
	NetUpdateFrequency = 1.0f; // Low frequency for static items

	// Create root component (mesh)
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;
	
	// Configure mesh
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	MeshComponent->SetCollisionObjectType(ECollisionChannel::ECC_PhysicsBody);
	MeshComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	MeshComponent->SetSimulatePhysics(false); // Enabled later after mesh load
	MeshComponent->SetEnableGravity(false); // No gravity in space
	MeshComponent->SetLinearDamping(0.0f); // No drag in vacuum
	MeshComponent->SetAngularDamping(0.1f); // Slight rotational damping

	// Create interaction sphere
	InteractionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("InteractionSphere"));
	InteractionSphere->SetupAttachment(RootComponent);
	InteractionSphere->SetSphereRadius(InteractionDistance);
	InteractionSphere->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	InteractionSphere->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	InteractionSphere->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	InteractionSphere->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);

	// Create inventory component
	InventoryComponent = CreateDefaultSubobject<UEchoesInventoryComponent>(TEXT("InventoryComponent"));
	
	// Default settings
	InteractionDistance = 25000.0f; // 250 meters
	Lifetime = 7200.0f; // 2 hours
	bEnablePhysics = true;
	bApplyRandomVelocity = true;
	MaxRandomVelocity = 100.0f;
	bIsContainer = true;
	
	CachedDefinition.Reset();
	bMeshLoaded = false;
}

void AEchoesItemActor::BeginPlay()
{
	Super::BeginPlay();

	// Server-only initialization
	if (HasAuthority())
	{
		// Start lifetime timer if lifetime is set
		if (Lifetime > 0.0f)
		{
			GetWorldTimerManager().SetTimer(
				LifetimeTimerHandle,
				this,
				&AEchoesItemActor::OnLifetimeExpired,
				Lifetime,
				false
			);
			
			UE_LOG(LogTemp, Log, TEXT("EchoesItemActor: Lifetime set to %.0f seconds"), Lifetime);
		}
	}

	// Load item definition if ItemId is already set
	if (!ItemId.IsEmpty())
	{
		LoadItemDefinition();
	}
}

void AEchoesItemActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEchoesItemActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AEchoesItemActor, ItemId);
	DOREPLIFETIME(AEchoesItemActor, InstanceId);
	DOREPLIFETIME(AEchoesItemActor, Quantity);
}

void AEchoesItemActor::ServerOnly_InitializeItem(const FString& InItemId, const FGuid& InInstanceId, int64 InQuantity)
{
	// Validate this is server
	if (!HasAuthority())
	{
		UE_LOG(LogTemp, Error, TEXT("EchoesItemActor: ServerOnly_InitializeItem called on client"));
		return;
	}

	ItemId = InItemId;
	InstanceId = InInstanceId;
	Quantity = InQuantity;

	UE_LOG(LogTemp, Log, TEXT("EchoesItemActor: Initializing item %s (Instance: %s, Qty: %lld)"),
		*ItemId, *InstanceId.ToString(), Quantity);

	// Load item definition and mesh
	LoadItemDefinition();
}

void AEchoesItemActor::SetLifetime(float LifetimeSeconds)
{
	if (!HasAuthority())
	{
		return;
	}

	Lifetime = LifetimeSeconds;

	// Clear existing timer
	GetWorldTimerManager().ClearTimer(LifetimeTimerHandle);

	// Set new timer if lifetime > 0
	if (Lifetime > 0.0f)
	{
		GetWorldTimerManager().SetTimer(
			LifetimeTimerHandle,
			this,
			&AEchoesItemActor::OnLifetimeExpired,
			Lifetime,
			false
		);
	}
}

bool AEchoesItemActor::CanInteract_Implementation(APawn* Interactor) const
{
	// Check if within interaction range
	if (!IsWithinInteractionRange(Interactor))
	{
		return false;
	}

	// Can interact if this is a container with inventory
	return bIsContainer && InventoryComponent != nullptr;
}

float AEchoesItemActor::GetInteractionDistance_Implementation() const
{
	return InteractionDistance;
}

FText AEchoesItemActor::GetInteractionPrompt_Implementation() const
{
	if (CachedDefinition.IsSet())
	{
		return FText::Format(
			FText::FromString(TEXT("Open {0} [E]")),
			CachedDefinition->DisplayName
		);
	}
	
	return FText::FromString(TEXT("Open Container [E]"));
}

FEchoesInteractionResult AEchoesItemActor::OnInteract_Implementation(APawn* Interactor)
{
	FEchoesInteractionResult Result;

	// Server-side validation
	if (!HasAuthority())
	{
		Result.bSuccess = false;
		Result.Message = TEXT("Must be called on server");
		return Result;
	}

	// Check distance
	if (!IsWithinInteractionRange(Interactor))
	{
		Result.bSuccess = false;
		Result.Message = TEXT("Too far away");
		return Result;
	}

	// Check if container
	if (!bIsContainer || !InventoryComponent)
	{
		Result.bSuccess = false;
		Result.Message = TEXT("Not a container");
		return Result;
	}

	// Success - allow player to open inventory
	Result.bSuccess = true;
	Result.Message = TEXT("Opening container...");
	Result.TargetActor = this;

	UE_LOG(LogTemp, Log, TEXT("EchoesItemActor: Player %s interacted with container %s"),
		*Interactor->GetName(), *GetName());

	// Trigger Blueprint event
	OnPlayerInteracted(Interactor);

	return Result;
}

bool AEchoesItemActor::IsContainer() const
{
	return bIsContainer && InventoryComponent != nullptr;
}

float AEchoesItemActor::GetRemainingLifetime() const
{
	if (!HasAuthority() || Lifetime <= 0.0f)
	{
		return -1.0f; // Infinite lifetime
	}

	return GetWorldTimerManager().GetTimerRemaining(LifetimeTimerHandle);
}

FEchoesItemDefinitionRow AEchoesItemActor::GetItemDefinitionData() const
{
	if (CachedDefinition.IsSet())
	{
		return CachedDefinition.GetValue();
	}

	return FEchoesItemDefinitionRow();
}

void AEchoesItemActor::OnRep_ItemId()
{
	// ItemId was replicated, load definition on client
	UE_LOG(LogTemp, Log, TEXT("EchoesItemActor: ItemId replicated: %s"), *ItemId);
	LoadItemDefinition();
}

void AEchoesItemActor::LoadItemDefinition()
{
	if (ItemId.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("EchoesItemActor: Cannot load definition - ItemId is empty"));
		return;
	}

	// Get inventory subsystem
	UGameInstance* GameInstance = GetGameInstance();
	if (!GameInstance)
	{
		UE_LOG(LogTemp, Warning, TEXT("EchoesItemActor: No game instance"));
		return;
	}

	UEchoesInventorySubsystem* InvSubsystem = GameInstance->GetSubsystem<UEchoesInventorySubsystem>();
	if (!InvSubsystem)
	{
		UE_LOG(LogTemp, Warning, TEXT("EchoesItemActor: No inventory subsystem"));
		return;
	}

	// Get item definition
	FEchoesItemDefinitionRow Definition;
	if (!InvSubsystem->TryGetItemDefinition(ItemId, Definition))
	{
		UE_LOG(LogTemp, Warning, TEXT("EchoesItemActor: No definition found for item: %s"), *ItemId);
		return;
	}

	CachedDefinition = Definition;

	UE_LOG(LogTemp, Log, TEXT("EchoesItemActor: Loaded definition for %s"), *Definition.DisplayName.ToString());

	// Load world mesh asynchronously
	if (!Definition.WorldMesh.IsNull())
	{
		InvSubsystem->AsyncLoadItemWorldMesh(
			ItemId,
			FOnWorldMeshLoaded::CreateUObject(this, &AEchoesItemActor::OnMeshLoaded)
		);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("EchoesItemActor: Item %s has no world mesh defined"), *ItemId);
	}

	// Initialize inventory component with definition data if this is a container
	if (bIsContainer && InventoryComponent)
	{
		// Use definition volume or default
		float ContainerCapacity = Definition.UnitVolume * Quantity * 100.0f; // Scale for containers
		
		// If this has an InstanceId, it might already be in the database
		if (InstanceId.IsValid())
		{
			InventoryComponent->InitializeStorage(InstanceId, ContainerCapacity);
		}
	}

	// Trigger Blueprint event
	OnItemInitialized();
}

void AEchoesItemActor::OnMeshLoaded(UStaticMesh* LoadedMesh)
{
	if (!LoadedMesh)
	{
		UE_LOG(LogTemp, Warning, TEXT("EchoesItemActor: Failed to load mesh for item %s"), *ItemId);
		return;
	}

	// Set mesh on component
	if (MeshComponent)
	{
		MeshComponent->SetStaticMesh(LoadedMesh);
		bMeshLoaded = true;

		UE_LOG(LogTemp, Log, TEXT("EchoesItemActor: Mesh loaded for item %s"), *ItemId);

		// Setup physics after mesh is loaded
		if (bEnablePhysics)
		{
			SetupPhysicsSimulation();
		}
	}
}

void AEchoesItemActor::SetupPhysicsSimulation()
{
	if (!MeshComponent || !bMeshLoaded)
	{
		return;
	}

	// Enable physics simulation
	MeshComponent->SetSimulatePhysics(true);

	// Set mass based on definition
	if (CachedDefinition.IsSet())
	{
		float TotalMass = CachedDefinition->UnitMass * Quantity;
		MeshComponent->SetMassOverrideInKg(NAME_None, TotalMass, true);
		
		UE_LOG(LogTemp, Log, TEXT("EchoesItemActor: Set mass to %.2f kg"), TotalMass);
	}

	// Apply random initial velocity for realistic drift
	if (bApplyRandomVelocity)
	{
		ApplyRandomVelocity();
	}
}

void AEchoesItemActor::ApplyRandomVelocity()
{
	if (!MeshComponent || !MeshComponent->IsSimulatingPhysics())
	{
		return;
	}

	// Generate random velocity direction
	FVector RandomDirection = FMath::VRand();
	RandomDirection.Normalize();

	// Random magnitude
	float Magnitude = FMath::FRandRange(MaxRandomVelocity * 0.3f, MaxRandomVelocity);
	
	FVector Velocity = RandomDirection * Magnitude;
	
	// Apply velocity
	MeshComponent->SetPhysicsLinearVelocity(Velocity);

	// Also apply small random angular velocity
	FVector AngularVelocity = FMath::VRand() * FMath::FRandRange(0.1f, 0.5f);
	MeshComponent->SetPhysicsAngularVelocityInDegrees(AngularVelocity);

	UE_LOG(LogTemp, Verbose, TEXT("EchoesItemActor: Applied random velocity: %s"), *Velocity.ToString());
}

void AEchoesItemActor::OnLifetimeExpired()
{
	if (!HasAuthority())
	{
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("EchoesItemActor: Lifetime expired for %s, destroying"), *GetName());

	// Destroy the actor
	Destroy();
}
