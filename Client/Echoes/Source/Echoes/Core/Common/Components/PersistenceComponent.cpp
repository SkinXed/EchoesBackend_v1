// Copyright Epic Games, Inc. All Rights Reserved.

#include "PersistenceComponent.h"
#include "EchoesStatsComponent.h"
#include "Core/Common/Networking/EchoesPersistenceSubsystem.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

UPersistenceComponent::UPersistenceComponent()
{
// Enable tick for heartbeat timer
PrimaryComponentTick.bCanEverTick = true;
PrimaryComponentTick.TickGroup = TG_PrePhysics;

// This is a server-only component
SetIsReplicatedByDefault(false);

// Initialize state
TimeSinceLastHeartbeat = 0.0f;
CachedStatsComponent = nullptr;
PersistenceSubsystem = nullptr;
}

void UPersistenceComponent::BeginPlay()
{
Super::BeginPlay();

// Only run on server
if (!GetWorld() || !GetWorld()->GetAuthGameMode())
{
SetComponentTickEnabled(false);
return;
}

UE_LOG(LogTemp, Log, TEXT("PersistenceComponent: BeginPlay on server for Character %s"), 
*CharacterId.ToString(EGuidFormats::Digits));

// Get persistence subsystem reference
if (UGameInstance* GameInstance = GetWorld()->GetGameInstance())
{
PersistenceSubsystem = GameInstance->GetSubsystem<UEchoesPersistenceSubsystem>();
if (!PersistenceSubsystem)
{
UE_LOG(LogTemp, Error, TEXT("PersistenceComponent: Failed to get EchoesPersistenceSubsystem"));
}
}

// Cache stats component reference
AActor* Owner = GetOwner();
if (Owner)
{
CachedStatsComponent = Owner->FindComponentByClass<UEchoesStatsComponent>();
if (!CachedStatsComponent)
{
UE_LOG(LogTemp, Warning, TEXT("PersistenceComponent: No EchoesStatsComponent found on owner %s"), 
*Owner->GetName());
}
}

// Initial state capture
LastSavedState = ServerOnly_CollectCurrentState();
}

void UPersistenceComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
// NOTE: EndPlay is no longer used for logout save
// PlayerController now handles logout saves via OnUnPossess
// This is more reliable as components can be destroyed unexpectedly

UE_LOG(LogTemp, Verbose, TEXT("PersistenceComponent: EndPlay for Character %s"), 
*CharacterId.ToString(EGuidFormats::Digits));

Super::EndPlay(EndPlayReason);
}

void UPersistenceComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

// Only run on server
if (!GetWorld() || !GetWorld()->GetAuthGameMode())
{
return;
}

// Heartbeat timer
if (bEnableHeartbeat)
{
TimeSinceLastHeartbeat += DeltaTime;
if (TimeSinceLastHeartbeat >= HeartbeatInterval)
{
ServerOnly_OnHeartbeatTimer();
TimeSinceLastHeartbeat = 0.0f;
}
}
}

void UPersistenceComponent::Common_SetCharacterId(const FGuid& InCharacterId)
{
CharacterId = InCharacterId;
UE_LOG(LogTemp, Log, TEXT("PersistenceComponent: Character ID set to %s"), 
*CharacterId.ToString(EGuidFormats::Digits));
}

void UPersistenceComponent::ServerOnly_TriggerSave()
{
if (!GetWorld() || !GetWorld()->GetAuthGameMode())
{
UE_LOG(LogTemp, Warning, TEXT("PersistenceComponent: TriggerSave called on client, ignoring"));
return;
}

if (!PersistenceSubsystem)
{
UE_LOG(LogTemp, Error, TEXT("PersistenceComponent: No persistence subsystem available"));
return;
}

FCommon_StateData CurrentState = ServerOnly_CollectCurrentState();

// Check dirty flag if enabled
if (bEnableDirtyFlag && !ServerOnly_IsDirty(CurrentState))
{
UE_LOG(LogTemp, Verbose, TEXT("PersistenceComponent: State not dirty, skipping save"));
return;
}

// Queue save via subsystem
if (PersistenceSubsystem->ServerOnly_QueueStateSave(CharacterId, CurrentState))
{
LastSavedState = CurrentState;
UE_LOG(LogTemp, Verbose, TEXT("PersistenceComponent: Save queued for Character %s"), 
*CharacterId.ToString(EGuidFormats::Digits));
}
}

FCommon_StateData UPersistenceComponent::ServerOnly_CollectCurrentState()
{
FCommon_StateData State;

AActor* Owner = GetOwner();
if (!Owner)
{
UE_LOG(LogTemp, Error, TEXT("PersistenceComponent: No owner actor, cannot collect state"));
return State;
}

// Collect position and rotation
State.Position = Owner->GetActorLocation();
State.Rotation = Owner->GetActorRotation().Quaternion();

// Collect stats from EchoesStatsComponent
if (CachedStatsComponent)
{
State.CurrentShield = CachedStatsComponent->ShieldCurrent;
State.CurrentArmor = CachedStatsComponent->ArmorCurrent;
State.CurrentHull = CachedStatsComponent->StructureCurrent;

// TODO: Capacitor should come from ship power/capacitor component when available
// For now, using DefaultCapacitorValue which can be configured per ship class
State.CurrentCapacitor = DefaultCapacitorValue;
}
else
{
UE_LOG(LogTemp, Warning, TEXT("PersistenceComponent: No stats component, using default values"));
State.CurrentShield = 0.0f;
State.CurrentArmor = 0.0f;
State.CurrentHull = 0.0f;
State.CurrentCapacitor = 0.0f;
}

// TODO: Get LastSystemId from game mode or world state
// For now, leaving as default (invalid GUID)

return State;
}

bool UPersistenceComponent::ServerOnly_IsDirty(const FCommon_StateData& NewState) const
{
// Check position change
float PositionDelta = FVector::Dist(NewState.Position, LastSavedState.Position);
if (PositionDelta >= DirtyPositionThreshold)
{
return true;
}

// Check stats changes
const float StatEpsilon = 0.1f; // Allow small floating point differences
if (FMath::Abs(NewState.CurrentShield - LastSavedState.CurrentShield) > StatEpsilon ||
FMath::Abs(NewState.CurrentArmor - LastSavedState.CurrentArmor) > StatEpsilon ||
FMath::Abs(NewState.CurrentHull - LastSavedState.CurrentHull) > StatEpsilon ||
FMath::Abs(NewState.CurrentCapacitor - LastSavedState.CurrentCapacitor) > StatEpsilon)
{
return true;
}

return false;
}

void UPersistenceComponent::ServerOnly_OnHeartbeatTimer()
{
UE_LOG(LogTemp, Verbose, TEXT("PersistenceComponent: Heartbeat timer triggered"));

if (!PersistenceSubsystem)
{
UE_LOG(LogTemp, Error, TEXT("PersistenceComponent: No persistence subsystem available"));
return;
}

FCommon_StateData CurrentState = ServerOnly_CollectCurrentState();

// Check dirty flag if enabled
if (bEnableDirtyFlag && !ServerOnly_IsDirty(CurrentState))
{
UE_LOG(LogTemp, Verbose, TEXT("PersistenceComponent: State not dirty, skipping heartbeat save"));
return;
}

UE_LOG(LogTemp, Log, TEXT("PersistenceComponent: Performing heartbeat save"));

// Queue save via subsystem
if (PersistenceSubsystem->ServerOnly_QueueStateSave(CharacterId, CurrentState))
{
LastSavedState = CurrentState;
}
}
