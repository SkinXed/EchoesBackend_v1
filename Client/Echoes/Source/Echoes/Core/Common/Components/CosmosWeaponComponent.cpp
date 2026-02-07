// Copyright Epic Games, Inc. All Rights Reserved.

#include "CosmosWeaponComponent.h"
#include "CosmosProjectile.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/MovementComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PawnMovementComponent.h"

UCosmosWeaponComponent::UCosmosWeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	// Default weapon stats
	BaseDamage = 100.0f;
	DamageType = ECosmosDamageType::Kinetic;
	MuzzleVelocity = 100000.0f; // 1000 m/s = 100000 cm/s
	FireRate = 1.0f; // 1 shot per second

	// Initialize cooldown
	NextFireTime = 0.0f;
}

void UCosmosWeaponComponent::BeginPlay()
{
	Super::BeginPlay();

	// Validate projectile class
	if (!ProjectileClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("CosmosWeaponComponent: ProjectileClass not set on %s"), 
			*GetOwner()->GetName());
	}
}

FVector UCosmosWeaponComponent::Common_GetPredictionLocation(AActor* Target) const
{
	if (!Target)
	{
		return FVector::ZeroVector;
	}

	// Get weapon position
	FVector WeaponPosition = GetComponentLocation();

	// Get target position
	FVector TargetPosition = Target->GetActorLocation();

	// Get target velocity
	FVector TargetVelocity = FVector::ZeroVector;

	// Try to get velocity from movement component
	UMovementComponent* MovementComp = Target->FindComponentByClass<UMovementComponent>();
	if (MovementComp)
	{
		TargetVelocity = MovementComp->Velocity;
	}
	else
	{
		// Fallback to root component velocity
		UPrimitiveComponent* RootPrim = Cast<UPrimitiveComponent>(Target->GetRootComponent());
		if (RootPrim && RootPrim->IsSimulatingPhysics())
		{
			TargetVelocity = RootPrim->GetPhysicsLinearVelocity();
		}
	}

	// Calculate relative position and velocity
	FVector RelativePosition = TargetPosition - WeaponPosition;
	FVector RelativeVelocity = TargetVelocity; // Weapon velocity assumed to be zero (or ship velocity)

	// If target is not moving or projectile speed is zero, return current position
	if (TargetVelocity.IsNearlyZero() || MuzzleVelocity <= 0.0f)
	{
		return TargetPosition;
	}

	// Calculate intercept time using First-Order Intercept algorithm
	float InterceptTime = CalculateInterceptTime(RelativePosition, RelativeVelocity);

	// If no solution (negative time or invalid), return current position
	if (InterceptTime < 0.0f)
	{
		return TargetPosition;
	}

	// Calculate predicted position
	FVector PredictedPosition = TargetPosition + (TargetVelocity * InterceptTime);

	UE_LOG(LogTemp, Verbose, TEXT("Weapon prediction: Target at %s, velocity %s, intercept in %.2fs, predicted at %s"),
		*TargetPosition.ToString(), *TargetVelocity.ToString(), InterceptTime, *PredictedPosition.ToString());

	return PredictedPosition;
}

float UCosmosWeaponComponent::CalculateInterceptTime(const FVector& RelativePosition, 
	const FVector& RelativeVelocity) const
{
	// First-Order Intercept algorithm
	// We need to solve: |P + V*t| = S*t
	// Where: P = relative position, V = relative velocity, S = projectile speed, t = time
	// 
	// Expanding: (P + V*t)·(P + V*t) = (S*t)²
	// P·P + 2*P·V*t + V·V*t² = S²*t²
	// (V·V - S²)*t² + 2*P·V*t + P·P = 0
	//
	// This is a quadratic equation: a*t² + b*t + c = 0
	// Where: a = V·V - S², b = 2*P·V, c = P·P

	float a = RelativeVelocity.SizeSquared() - (MuzzleVelocity * MuzzleVelocity);
	float b = 2.0f * FVector::DotProduct(RelativePosition, RelativeVelocity);
	float c = RelativePosition.SizeSquared();

	// Calculate discriminant
	float Discriminant = (b * b) - (4.0f * a * c);

	// If discriminant is negative, no real solution (can't intercept)
	if (Discriminant < 0.0f)
	{
		// Target is too fast to intercept, return time to closest approach
		if (FMath::Abs(a) > SMALL_NUMBER)
		{
			float t = -b / (2.0f * a);
			return FMath::Max(0.0f, t);
		}
		return 0.0f;
	}

	// Calculate both solutions
	float SqrtDiscriminant = FMath::Sqrt(Discriminant);
	float t1 = (-b + SqrtDiscriminant) / (2.0f * a);
	float t2 = (-b - SqrtDiscriminant) / (2.0f * a);

	// We want the smallest positive time
	if (t1 > 0.0f && t2 > 0.0f)
	{
		return FMath::Min(t1, t2);
	}
	else if (t1 > 0.0f)
	{
		return t1;
	}
	else if (t2 > 0.0f)
	{
		return t2;
	}

	// Both solutions are negative (target is moving away faster than we can catch)
	return 0.0f;
}

void UCosmosWeaponComponent::ServerOnly_Fire(AActor* Target)
{
	// Validation: Only server can fire
	if (!GetOwner() || !GetOwner()->HasAuthority())
	{
		UE_LOG(LogTemp, Warning, TEXT("ServerOnly_Fire called on client - ignoring"));
		return;
	}

	// Validation: Check projectile class
	if (!ProjectileClass)
	{
		UE_LOG(LogTemp, Error, TEXT("ServerOnly_Fire: No ProjectileClass set on %s"), 
			*GetOwner()->GetName());
		return;
	}

	// Check cooldown
	if (!CanFire())
	{
		UE_LOG(LogTemp, Verbose, TEXT("ServerOnly_Fire: Weapon on cooldown (%.2fs remaining)"), 
			GetCooldownRemaining());
		return;
	}

	// Get world
	UWorld* World = GetWorld();
	if (!World)
	{
		return;
	}

	// Calculate spawn transform
	FVector SpawnLocation = GetComponentLocation();
	FRotator SpawnRotation;

	// If we have a target, aim at prediction point
	if (Target)
	{
		FVector PredictionPoint = Common_GetPredictionLocation(Target);
		FVector AimDirection = (PredictionPoint - SpawnLocation).GetSafeNormal();
		SpawnRotation = AimDirection.Rotation();
	}
	else
	{
		// No target, fire in weapon's forward direction
		SpawnRotation = GetComponentRotation();
	}

	FTransform SpawnTransform(SpawnRotation, SpawnLocation);

	// Spawn projectile (deferred)
	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = GetOwner();
	SpawnParams.Instigator = Cast<APawn>(GetOwner());
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	ACosmosProjectile* Projectile = World->SpawnActorDeferred<ACosmosProjectile>(
		ProjectileClass,
		SpawnTransform,
		GetOwner(),
		SpawnParams.Instigator,
		ESpawnActorCollisionHandlingMethod::AlwaysSpawn
	);

	if (Projectile)
	{
		// Initialize projectile with weapon stats
		Projectile->InitializeProjectile(BaseDamage, DamageType, MuzzleVelocity);

		// Finish spawning
		UGameplayStatics::FinishSpawningActor(Projectile, SpawnTransform);

		UE_LOG(LogTemp, Log, TEXT("Weapon fired: Damage=%.1f, Type=%d, Velocity=%.1f at %s"), 
			BaseDamage, (int32)DamageType, MuzzleVelocity, 
			Target ? *Target->GetName() : TEXT("No Target"));
	}

	// Set cooldown
	float CooldownDuration = 1.0f / FMath::Max(0.1f, FireRate);
	NextFireTime = World->GetTimeSeconds() + CooldownDuration;
}

bool UCosmosWeaponComponent::CanFire() const
{
	UWorld* World = GetWorld();
	if (!World)
	{
		return false;
	}

	return World->GetTimeSeconds() >= NextFireTime;
}

float UCosmosWeaponComponent::GetCooldownRemaining() const
{
	UWorld* World = GetWorld();
	if (!World)
	{
		return 0.0f;
	}

	float Remaining = NextFireTime - World->GetTimeSeconds();
	return FMath::Max(0.0f, Remaining);
}
