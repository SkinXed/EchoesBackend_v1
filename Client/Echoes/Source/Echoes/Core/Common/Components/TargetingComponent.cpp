// Copyright Epic Games, Inc. All Rights Reserved.

#include "TargetingComponent.h"
#include "Net/UnrealNetwork.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Kismet/KismetMathLibrary.h"

UTargetingComponent::UTargetingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.TickGroup = TG_PrePhysics;

	// Enable replication
	SetIsReplicatedByDefault(true);

	// Default configuration values (EVE-like)
	MaxLockRange = 2500000.0f;      // 25km = 25000m = 2500000cm
	ScanResolution = 100.0f;         // Arbitrary scan resolution
	LockTimeConstant = 40000.0f;     // Formula constant k
	MaxSimultaneousLocks = 5;        // Maximum 5 simultaneous locks
}

void UTargetingComponent::BeginPlay()
{
	Super::BeginPlay();
	
	// Clear any existing locks on begin play
	TargetLocks.Empty();
}

void UTargetingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Only server updates lock timers
	if (GetOwner() && GetOwner()->HasAuthority())
	{
		UpdateLockTimers(DeltaTime);
	}
}

void UTargetingComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Replicate target locks array to all clients
	DOREPLIFETIME(UTargetingComponent, TargetLocks);
}

// ==================== Server RPC Functions ====================

void UTargetingComponent::ServerRPC_StartLock_Implementation(AActor* Target)
{
	// Validate server authority
	if (!GetOwner() || !GetOwner()->HasAuthority())
	{
		UE_LOG(LogTemp, Warning, TEXT("ServerRPC_StartLock: Not called on server"));
		return;
	}

	// Validate target exists
	if (!Target || !IsValid(Target))
	{
		UE_LOG(LogTemp, Warning, TEXT("ServerRPC_StartLock: Invalid target"));
		return;
	}

	// Check if already locking/locked
	if (FindLockEntry(Target))
	{
		UE_LOG(LogTemp, Warning, TEXT("ServerRPC_StartLock: Target already being locked/locked"));
		return;
	}

	// Check if we have available lock slots
	if (TargetLocks.Num() >= MaxSimultaneousLocks)
	{
		UE_LOG(LogTemp, Warning, TEXT("ServerRPC_StartLock: No available lock slots (%d/%d)"), 
			TargetLocks.Num(), MaxSimultaneousLocks);
		return;
	}

	// Validate target is in range
	if (!Common_IsTargetInRange(Target))
	{
		float Distance = FVector::Dist(GetOwner()->GetActorLocation(), Target->GetActorLocation());
		UE_LOG(LogTemp, Warning, TEXT("ServerRPC_StartLock: Target out of range (%.1fcm > %.1fcm)"), 
			Distance, MaxLockRange);
		return;
	}

	// Calculate required lock time
	float RequiredTime = Common_CalculateLockTime(Target);
	if (RequiredTime <= 0.0f)
	{
		UE_LOG(LogTemp, Error, TEXT("ServerRPC_StartLock: Invalid lock time calculated"));
		return;
	}

	// Create new lock entry
	FTargetLockEntry NewEntry;
	NewEntry.TargetActor = Target;
	NewEntry.Progress = 0.0f;
	NewEntry.State = ETargetLockState::Locking;
	NewEntry.LockStartTime = GetWorld()->GetTimeSeconds();
	NewEntry.RequiredLockTime = RequiredTime;

	// Add to array
	TargetLocks.Add(NewEntry);

	UE_LOG(LogTemp, Log, TEXT("ServerRPC_StartLock: Started locking %s (%.2fs required)"), 
		*Target->GetName(), RequiredTime);

	// Notify client
	ClientRPC_OnLockStarted(Target);

	// Broadcast event (for server-side listeners)
	OnLockStarted.Broadcast(Target);
}

void UTargetingComponent::ServerRPC_CancelLock_Implementation(AActor* Target)
{
	// Validate server authority
	if (!GetOwner() || !GetOwner()->HasAuthority())
	{
		return;
	}

	// Remove lock entry
	if (RemoveLockEntry(Target))
	{
		UE_LOG(LogTemp, Log, TEXT("ServerRPC_CancelLock: Cancelled lock on %s"), 
			Target ? *Target->GetName() : TEXT("null"));

		// Notify client
		ClientRPC_OnLockLost(Target);

		// Broadcast event
		OnLockLost.Broadcast(Target);
	}
}

void UTargetingComponent::ServerRPC_ClearAllLocks_Implementation()
{
	// Validate server authority
	if (!GetOwner() || !GetOwner()->HasAuthority())
	{
		return;
	}

	// Notify about all lost locks
	for (const FTargetLockEntry& Entry : TargetLocks)
	{
		if (Entry.TargetActor)
		{
			ClientRPC_OnLockLost(Entry.TargetActor);
			OnLockLost.Broadcast(Entry.TargetActor);
		}
	}

	// Clear all locks
	TargetLocks.Empty();

	UE_LOG(LogTemp, Log, TEXT("ServerRPC_ClearAllLocks: Cleared all target locks"));
}

// ==================== Client RPC Functions ====================

void UTargetingComponent::ClientRPC_OnLockStarted_Implementation(AActor* Target)
{
	// Broadcast event for UI
	OnLockStarted.Broadcast(Target);

	UE_LOG(LogTemp, Verbose, TEXT("ClientRPC_OnLockStarted: Lock started on %s"), 
		Target ? *Target->GetName() : TEXT("null"));
}

void UTargetingComponent::ClientRPC_OnLockCompleted_Implementation(AActor* Target)
{
	// Broadcast event for UI
	OnLockCompleted.Broadcast(Target);

	UE_LOG(LogTemp, Log, TEXT("ClientRPC_OnLockCompleted: Lock completed on %s"), 
		Target ? *Target->GetName() : TEXT("null"));
}

void UTargetingComponent::ClientRPC_OnLockLost_Implementation(AActor* Target)
{
	// Broadcast event for UI
	OnLockLost.Broadcast(Target);

	UE_LOG(LogTemp, Verbose, TEXT("ClientRPC_OnLockLost: Lock lost on %s"), 
		Target ? *Target->GetName() : TEXT("null"));
}

// ==================== Common Calculation Functions ====================

float UTargetingComponent::Common_CalculateLockTime(AActor* Target) const
{
	if (!Target || !IsValid(Target))
	{
		return 0.0f;
	}

	// Get target signature radius
	float TargetSize = Common_GetTargetSignatureRadius(Target);

	// Ensure target size is valid (must be > 1.0 for ln() to work properly)
	if (TargetSize <= 1.0f)
	{
		TargetSize = 10.0f; // Minimum signature radius of 10m
	}

	// Ensure scan resolution is valid
	if (ScanResolution <= 0.0f)
	{
		UE_LOG(LogTemp, Error, TEXT("Common_CalculateLockTime: Invalid ScanResolution (%.2f)"), ScanResolution);
		return 5.0f; // Fallback to 5 seconds
	}

	// Calculate lock time using EVE formula: T = k / (ScanResolution × ln(TargetSize))
	// Where:
	// - k = LockTimeConstant (formula constant)
	// - ScanResolution = ship's scan resolution stat
	// - TargetSize = target's signature radius in meters
	float LockTime = LockTimeConstant / (ScanResolution * FMath::Loge(TargetSize));

	// Clamp to reasonable values (0.5s to 60s)
	LockTime = FMath::Clamp(LockTime, 0.5f, 60.0f);

	return LockTime;
}

float UTargetingComponent::Common_GetTargetSignatureRadius(AActor* Target) const
{
	if (!Target || !IsValid(Target))
	{
		return 0.0f;
	}

	// TODO: In a full implementation, this would check for a ship stats component
	// that stores the signature radius. For now, we'll use bounding box size as approximation.
	
	// Try to get from actor's root component bounds
	USceneComponent* RootComp = Target->GetRootComponent();
	if (RootComp)
	{
		FVector Origin, BoxExtent;
		Target->GetActorBounds(false, Origin, BoxExtent);
		
		// Use average of extents as signature radius (in cm, convert to m)
		float AverageExtent = (BoxExtent.X + BoxExtent.Y + BoxExtent.Z) / 3.0f;
		float SignatureRadius = AverageExtent / 100.0f; // Convert cm to m

		// Clamp to reasonable range (5m to 5000m)
		return FMath::Clamp(SignatureRadius, 5.0f, 5000.0f);
	}

	// Fallback to default size
	return 50.0f; // 50 meters default
}

bool UTargetingComponent::Common_IsTargetInRange(AActor* Target) const
{
	if (!Target || !IsValid(Target) || !GetOwner())
	{
		return false;
	}

	float Distance = FVector::Dist(GetOwner()->GetActorLocation(), Target->GetActorLocation());
	return Distance <= MaxLockRange;
}

float UTargetingComponent::Common_GetLockProgress(AActor* Target) const
{
	const FTargetLockEntry* Entry = FindLockEntry(Target);
	if (Entry)
	{
		return Entry->Progress;
	}
	return -1.0f;
}

ETargetLockState UTargetingComponent::Common_GetLockState(AActor* Target) const
{
	const FTargetLockEntry* Entry = FindLockEntry(Target);
	if (Entry)
	{
		return Entry->State;
	}
	return ETargetLockState::None;
}

bool UTargetingComponent::Common_IsTargetLocked(AActor* Target) const
{
	const FTargetLockEntry* Entry = FindLockEntry(Target);
	return Entry && Entry->State == ETargetLockState::Locked;
}

TArray<AActor*> UTargetingComponent::Common_GetLockedTargets() const
{
	TArray<AActor*> LockedTargets;
	
	for (const FTargetLockEntry& Entry : TargetLocks)
	{
		if (Entry.State == ETargetLockState::Locked && Entry.TargetActor)
		{
			LockedTargets.Add(Entry.TargetActor);
		}
	}
	
	return LockedTargets;
}

int32 UTargetingComponent::Common_GetAvailableLockSlots() const
{
	return FMath::Max(0, MaxSimultaneousLocks - TargetLocks.Num());
}

// ==================== Internal Functions ====================

void UTargetingComponent::UpdateLockTimers(float DeltaTime)
{
	UWorld* World = GetWorld();
	if (!World)
	{
		return;
	}

	float CurrentTime = World->GetTimeSeconds();

	// Iterate through all lock entries
	for (int32 i = TargetLocks.Num() - 1; i >= 0; --i)
	{
		FTargetLockEntry& Entry = TargetLocks[i];

		// Skip if already locked
		if (Entry.State == ETargetLockState::Locked)
		{
			// Validate target is still in range
			if (!ValidateTarget(Entry.TargetActor))
			{
				// Target lost, remove entry
				AActor* LostTarget = Entry.TargetActor;
				TargetLocks.RemoveAt(i);

				// Notify client
				ClientRPC_OnLockLost(LostTarget);
				OnLockLost.Broadcast(LostTarget);

				UE_LOG(LogTemp, Log, TEXT("UpdateLockTimers: Lock lost on %s (out of range)"), 
					LostTarget ? *LostTarget->GetName() : TEXT("null"));
			}
			continue;
		}

		// Skip if not in locking state
		if (Entry.State != ETargetLockState::Locking)
		{
			continue;
		}

		// Validate target is still lockable
		if (!ValidateTarget(Entry.TargetActor))
		{
			// Target no longer valid, remove entry
			AActor* LostTarget = Entry.TargetActor;
			TargetLocks.RemoveAt(i);

			// Notify client
			ClientRPC_OnLockLost(LostTarget);
			OnLockLost.Broadcast(LostTarget);

			UE_LOG(LogTemp, Log, TEXT("UpdateLockTimers: Lock acquisition failed on %s (target invalid)"), 
				LostTarget ? *LostTarget->GetName() : TEXT("null"));
			continue;
		}

		// Calculate elapsed time
		float ElapsedTime = CurrentTime - Entry.LockStartTime;

		// Update progress
		Entry.Progress = FMath::Clamp(ElapsedTime / Entry.RequiredLockTime, 0.0f, 1.0f);

		// Broadcast progress update
		OnLockProgress.Broadcast(Entry.TargetActor, Entry.Progress);

		// Check if lock completed
		if (Entry.Progress >= 1.0f)
		{
			Entry.State = ETargetLockState::Locked;

			// Notify client
			ClientRPC_OnLockCompleted(Entry.TargetActor);
			OnLockCompleted.Broadcast(Entry.TargetActor);

			UE_LOG(LogTemp, Log, TEXT("UpdateLockTimers: Lock completed on %s (%.2fs elapsed)"), 
				*Entry.TargetActor->GetName(), ElapsedTime);
		}
	}
}

FTargetLockEntry* UTargetingComponent::FindLockEntry(AActor* Target)
{
	for (FTargetLockEntry& Entry : TargetLocks)
	{
		if (Entry.TargetActor == Target)
		{
			return &Entry;
		}
	}
	return nullptr;
}

const FTargetLockEntry* UTargetingComponent::FindLockEntry(AActor* Target) const
{
	for (const FTargetLockEntry& Entry : TargetLocks)
	{
		if (Entry.TargetActor == Target)
		{
			return &Entry;
		}
	}
	return nullptr;
}

bool UTargetingComponent::RemoveLockEntry(AActor* Target)
{
	for (int32 i = 0; i < TargetLocks.Num(); ++i)
	{
		if (TargetLocks[i].TargetActor == Target)
		{
			TargetLocks.RemoveAt(i);
			return true;
		}
	}
	return false;
}

bool UTargetingComponent::ValidateTarget(AActor* Target) const
{
	// Check target exists and is valid
	if (!Target || !IsValid(Target))
	{
		return false;
	}

	// Check target is not destroyed
	if (Target->IsActorBeingDestroyed())
	{
		return false;
	}

	// Check target is in range
	if (!Common_IsTargetInRange(Target))
	{
		return false;
	}

	// Target is valid
	return true;
}
