// Copyright Epic Games, Inc. All Rights Reserved.

#include "CosmosProjectile.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "GameFramework/DamageType.h"
#include "Kismet/GameplayStatics.h"
#include "CosmosAttributesComponent.h"

ACosmosProjectile::ACosmosProjectile()
{
	PrimaryActorTick.bCanEverTick = false;

	// Enable replication
	bReplicates = true;
	bReplicateMovement = true;

	// Create collision component
	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
	CollisionComponent->InitSphereRadius(5.0f);
	CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CollisionComponent->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	CollisionComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Block);
	RootComponent = CollisionComponent;

	// Create mesh component
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(CollisionComponent);
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	MeshComponent->SetCastShadow(false);

	// Create projectile movement component
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->UpdatedComponent = CollisionComponent;
	ProjectileMovementComponent->InitialSpeed = 100000.0f; // 1000 m/s default
	ProjectileMovementComponent->MaxSpeed = 100000.0f;
	ProjectileMovementComponent->bRotationFollowsVelocity = true;
	ProjectileMovementComponent->bShouldBounce = false;
	ProjectileMovementComponent->ProjectileGravityScale = 0.0f; // No gravity in space

	// Default values
	RawDamage = 100.0f;
	DamageType = ECosmosDamageType::Kinetic;
	MaxLifetime = 10.0f; // 10 seconds default
}

void ACosmosProjectile::BeginPlay()
{
	Super::BeginPlay();

	// Bind collision event (server only for damage application)
	if (HasAuthority())
	{
		CollisionComponent->OnComponentHit.AddDynamic(this, &ACosmosProjectile::OnHit);

		// Set auto-destruction timer
		GetWorldTimerManager().SetTimer(
			LifetimeTimerHandle,
			this,
			&ACosmosProjectile::OnLifetimeExpired,
			MaxLifetime,
			false
		);
	}
}

void ACosmosProjectile::InitializeProjectile(float NewDamage, ECosmosDamageType NewType, float NewSpeed)
{
	// Assign damage parameters
	RawDamage = NewDamage;
	DamageType = NewType;

	// Update projectile movement speed
	if (ProjectileMovementComponent)
	{
		ProjectileMovementComponent->InitialSpeed = NewSpeed;
		ProjectileMovementComponent->MaxSpeed = NewSpeed;
		ProjectileMovementComponent->Velocity = GetActorForwardVector() * NewSpeed;
	}

	UE_LOG(LogTemp, Log, TEXT("CosmosProjectile initialized: Damage=%.1f, Type=%d, Speed=%.1f"), 
		RawDamage, (int32)DamageType, NewSpeed);
}

void ACosmosProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only server handles damage
	if (!HasAuthority())
	{
		return;
	}

	// Don't hit ourselves or our owner
	if (!OtherActor || OtherActor == this || OtherActor == GetOwner())
	{
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("CosmosProjectile hit %s with %.1f %d damage"), 
		*OtherActor->GetName(), RawDamage, (int32)DamageType);

	// Try to apply damage via CosmosAttributesComponent
	UCosmosAttributesComponent* AttributesComp = 
		OtherActor->FindComponentByClass<UCosmosAttributesComponent>();

	if (AttributesComp)
	{
		// Apply typed damage with resistance mitigation
		AttributesComp->ServerOnly_ApplyDamage(RawDamage, DamageType, GetInstigator());
	}
	else
	{
		// Fallback to generic damage if no attributes component
		UGameplayStatics::ApplyDamage(
			OtherActor,
			RawDamage,
			GetInstigatorController(),
			this,
			UDamageType::StaticClass()
		);
	}

	// Destroy projectile after hit
	Destroy();
}

void ACosmosProjectile::OnLifetimeExpired()
{
	// Auto-destroy after max lifetime
	UE_LOG(LogTemp, Verbose, TEXT("CosmosProjectile lifetime expired, destroying"));
	Destroy();
}
