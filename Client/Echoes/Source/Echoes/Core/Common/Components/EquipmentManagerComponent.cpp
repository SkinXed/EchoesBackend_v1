// Copyright Epic Games, Inc. All Rights Reserved.
// Echoes - EVE-like MMO
// Equipment Manager Component Implementation

#include "EquipmentManagerComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "Core/Common/Components/TargetingComponent.h"
#include "Engine/World.h"
#include "TimerManager.h"

UEquipmentManagerComponent::UEquipmentManagerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.TickInterval = 0.1f; // 10 Hz for cooldowns
	SetIsReplicatedByDefault(true);

	MaxCapacitor = 1000.0f;
	CurrentCapacitor = MaxCapacitor;
}

void UEquipmentManagerComponent::BeginPlay()
{
	Super::BeginPlay();

	CachedOwnerPawn = Cast<APawn>(GetOwner());
	if (CachedOwnerPawn)
	{
		CachedPlayerController = Cast<APlayerController>(CachedOwnerPawn->GetController());
	}

	// Initialize capacitor
	CurrentCapacitor = MaxCapacitor;
}

void UEquipmentManagerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Server-only logic
	if (GetOwner() && GetOwner()->HasAuthority())
	{
		ServerOnly_UpdateCooldowns(DeltaTime);
		ServerOnly_RechargeCapacitor(DeltaTime);
	}
}

void UEquipmentManagerComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UEquipmentManagerComponent, CurrentFitting);
	DOREPLIFETIME(UEquipmentManagerComponent, CurrentCapacitor);
	DOREPLIFETIME(UEquipmentManagerComponent, MaxCapacitor);
}

// ============================================================================
// SERVER RPC IMPLEMENTATIONS
// ============================================================================

void UEquipmentManagerComponent::ServerRPC_ToggleModule_Implementation(ESlotType SlotType, int32 SlotIndex)
{
	// Validate server authority
	if (!GetOwner() || !GetOwner()->HasAuthority())
	{
		UE_LOG(LogTemp, Error, TEXT("EquipmentManager: ServerRPC_ToggleModule called without authority"));
		return;
	}

	// Get mutable slot reference
	FCommon_ItemSlot* Slot = GetMutableSlot(SlotType, SlotIndex);
	if (!Slot || !Slot->HasModule())
	{
		UE_LOG(LogTemp, Warning, TEXT("EquipmentManager: Invalid slot or empty slot"));
		ClientRPC_NotifyModuleActivation(SlotType, SlotIndex, EModuleActivationResult::InvalidModule);
		return;
	}

	// If module is active, deactivate it
	if (Slot->bIsActive || Slot->ModuleState == EModuleState::Active)
	{
		ServerOnly_DeactivateModule(*Slot, SlotType, SlotIndex);
		ClientRPC_NotifyModuleActivation(SlotType, SlotIndex, EModuleActivationResult::Success);
		return;
	}

	// Otherwise, try to activate
	EModuleActivationResult Result = ServerOnly_ActivateModule(*Slot, SlotType, SlotIndex);
	
	// Notify client of result
	ClientRPC_NotifyModuleActivation(SlotType, SlotIndex, Result);

	// Log activation attempt
	if (Result == EModuleActivationResult::Success)
	{
		UE_LOG(LogTemp, Log, TEXT("EquipmentManager: Module activated - Type=%d, Index=%d, Module=%s"), 
			(int32)SlotType, SlotIndex, *Slot->ItemName);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("EquipmentManager: Module activation failed - Type=%d, Index=%d, Reason=%d"), 
			(int32)SlotType, SlotIndex, (int32)Result);
	}
}

void UEquipmentManagerComponent::ServerRPC_DeactivateAll_Implementation()
{
	if (!GetOwner() || !GetOwner()->HasAuthority())
	{
		return;
	}

	auto DeactivateSlots = [this](TArray<FCommon_ItemSlot>& Slots, ESlotType Type)
	{
		for (int32 i = 0; i < Slots.Num(); ++i)
		{
			if (Slots[i].bIsActive || Slots[i].ModuleState == EModuleState::Active)
			{
				ServerOnly_DeactivateModule(Slots[i], Type, i);
			}
		}
	};

	DeactivateSlots(CurrentFitting.HighSlots, ESlotType::High);
	DeactivateSlots(CurrentFitting.MidSlots, ESlotType::Mid);
	DeactivateSlots(CurrentFitting.LowSlots, ESlotType::Low);

	UE_LOG(LogTemp, Log, TEXT("EquipmentManager: All modules deactivated"));
}

void UEquipmentManagerComponent::ServerRPC_SetOverload_Implementation(ESlotType SlotType, int32 SlotIndex, bool bOverload)
{
	if (!GetOwner() || !GetOwner()->HasAuthority())
	{
		return;
	}

	FCommon_ItemSlot* Slot = GetMutableSlot(SlotType, SlotIndex);
	if (!Slot || !Slot->HasModule())
	{
		return;
	}

	if (bOverload && Slot->ModuleState == EModuleState::Active)
	{
		Slot->ModuleState = EModuleState::Overload;
		ClientRPC_NotifyModuleState(SlotType, SlotIndex, EModuleState::Overload);
		OnModuleStateChanged.Broadcast(SlotType, SlotIndex, EModuleState::Overload);
	}
	else if (!bOverload && Slot->ModuleState == EModuleState::Overload)
	{
		Slot->ModuleState = EModuleState::Active;
		ClientRPC_NotifyModuleState(SlotType, SlotIndex, EModuleState::Active);
		OnModuleStateChanged.Broadcast(SlotType, SlotIndex, EModuleState::Active);
	}
}

// ============================================================================
// CLIENT RPC IMPLEMENTATIONS
// ============================================================================

void UEquipmentManagerComponent::ClientRPC_NotifyModuleActivation_Implementation(
	ESlotType SlotType, 
	int32 SlotIndex, 
	EModuleActivationResult Result)
{
	// This is received on client
	// Can play sounds, show error messages, etc.
	if (Result != EModuleActivationResult::Success)
	{
		// Show error message to player
		FString ErrorMsg;
		switch (Result)
		{
		case EModuleActivationResult::NotEnoughCapacitor:
			ErrorMsg = TEXT("Not enough capacitor energy");
			break;
		case EModuleActivationResult::NotEnoughAmmo:
			ErrorMsg = TEXT("Out of ammunition");
			break;
		case EModuleActivationResult::InCooldown:
			ErrorMsg = TEXT("Module is recharging");
			break;
		case EModuleActivationResult::OutOfRange:
			ErrorMsg = TEXT("Target out of range");
			break;
		case EModuleActivationResult::NoTarget:
			ErrorMsg = TEXT("No target selected");
			break;
		default:
			ErrorMsg = TEXT("Cannot activate module");
			break;
		}

		UE_LOG(LogTemp, Warning, TEXT("Module Activation Failed: %s"), *ErrorMsg);
	}
}

void UEquipmentManagerComponent::ClientRPC_NotifyModuleState_Implementation(
	ESlotType SlotType, 
	int32 SlotIndex, 
	EModuleState NewState)
{
	// Notify UI widgets of state change
	OnModuleStateChanged.Broadcast(SlotType, SlotIndex, NewState);
}

void UEquipmentManagerComponent::ClientRPC_SyncFitting_Implementation(const FCommon_ShipFittingData& FittingData)
{
	// Synchronize fitting data from server
	CurrentFitting = FittingData;
	OnEquipmentChanged.Broadcast();
	
	UE_LOG(LogTemp, Log, TEXT("EquipmentManager: Fitting synchronized from server"));
}

// ============================================================================
// COMMON FUNCTIONS
// ============================================================================

FCommon_ItemSlot UEquipmentManagerComponent::Common_GetModuleSlot(ESlotType SlotType, int32 SlotIndex) const
{
	const TArray<FCommon_ItemSlot>* Slots = nullptr;

	switch (SlotType)
	{
	case ESlotType::High:
		Slots = &CurrentFitting.HighSlots;
		break;
	case ESlotType::Mid:
		Slots = &CurrentFitting.MidSlots;
		break;
	case ESlotType::Low:
		Slots = &CurrentFitting.LowSlots;
		break;
	case ESlotType::Rig:
		Slots = &CurrentFitting.RigSlots;
		break;
	default:
		return FCommon_ItemSlot();
	}

	if (Slots && SlotIndex >= 0 && SlotIndex < Slots->Num())
	{
		return (*Slots)[SlotIndex];
	}

	return FCommon_ItemSlot();
}

EModuleActivationResult UEquipmentManagerComponent::Common_CanActivateModule(ESlotType SlotType, int32 SlotIndex) const
{
	const FCommon_ItemSlot Slot = Common_GetModuleSlot(SlotType, SlotIndex);
	
	if (!Slot.HasModule())
	{
		return EModuleActivationResult::InvalidModule;
	}

	if (Slot.ModuleState == EModuleState::Damaged)
	{
		return EModuleActivationResult::ModuleDamaged;
	}

	if (Slot.Cooldown > 0.0f || Slot.ModuleState == EModuleState::Cooldown)
	{
		return EModuleActivationResult::InCooldown;
	}

	if (CurrentCapacitor < Slot.CapacitorCost)
	{
		return EModuleActivationResult::NotEnoughCapacitor;
	}

	// Check if weapon and needs target/range
	if (ServerOnly_IsWeaponModule(SlotType, Slot))
	{
		AActor* Target = ServerOnly_GetCurrentTarget();
		if (!Target)
		{
			return EModuleActivationResult::NoTarget;
		}
	}

	return EModuleActivationResult::Success;
}

float UEquipmentManagerComponent::Common_GetCapacitorPercentage() const
{
	return MaxCapacitor > 0.0f ? (CurrentCapacitor / MaxCapacitor) : 0.0f;
}

// ============================================================================
// SERVER ONLY IMPLEMENTATION
// ============================================================================

EModuleActivationResult UEquipmentManagerComponent::ServerOnly_ActivateModule(
	FCommon_ItemSlot& Slot, 
	ESlotType SlotType, 
	int32 SlotIndex)
{
	// Check module state
	if (Slot.ModuleState == EModuleState::Damaged)
	{
		return EModuleActivationResult::ModuleDamaged;
	}

	// Check cooldown
	if (Slot.Cooldown > 0.0f || Slot.ModuleState == EModuleState::Cooldown)
	{
		return EModuleActivationResult::InCooldown;
	}

	// Check capacitor
	if (!ServerOnly_CheckCapacitor(Slot.CapacitorCost))
	{
		return EModuleActivationResult::NotEnoughCapacitor;
	}

	// Check ammunition (if module uses ammo)
	if (!ServerOnly_CheckAmmo(Slot))
	{
		return EModuleActivationResult::NotEnoughAmmo;
	}

	// Check range (if weapon module)
	if (ServerOnly_IsWeaponModule(SlotType, Slot))
	{
		AActor* Target = ServerOnly_GetCurrentTarget();
		if (!Target)
		{
			return EModuleActivationResult::NoTarget;
		}

		if (!ServerOnly_CheckRange(SlotType, SlotIndex))
		{
			return EModuleActivationResult::OutOfRange;
		}
	}

	// All checks passed - activate module
	Slot.bIsActive = true;
	Slot.ModuleState = EModuleState::Active;

	// Consume capacitor
	ServerOnly_ConsumeCapacitor(Slot.CapacitorCost);

	// Consume ammo if needed
	ServerOnly_ConsumeAmmo(Slot);

	// Start cooldown (example: 5 seconds)
	Slot.Cooldown = 5.0f;

	// Notify state change
	ClientRPC_NotifyModuleState(SlotType, SlotIndex, EModuleState::Active);
	OnModuleStateChanged.Broadcast(SlotType, SlotIndex, EModuleState::Active);

	return EModuleActivationResult::Success;
}

void UEquipmentManagerComponent::ServerOnly_DeactivateModule(
	FCommon_ItemSlot& Slot, 
	ESlotType SlotType, 
	int32 SlotIndex)
{
	Slot.bIsActive = false;
	Slot.ModuleState = EModuleState::Offline;

	// Notify clients
	ClientRPC_NotifyModuleState(SlotType, SlotIndex, EModuleState::Offline);
	OnModuleStateChanged.Broadcast(SlotType, SlotIndex, EModuleState::Offline);
}

bool UEquipmentManagerComponent::ServerOnly_CheckCapacitor(float Cost)
{
	return CurrentCapacitor >= Cost;
}

void UEquipmentManagerComponent::ServerOnly_ConsumeCapacitor(float Amount)
{
	float OldCapacitor = CurrentCapacitor;
	CurrentCapacitor = FMath::Max(0.0f, CurrentCapacitor - Amount);

	if (FMath::Abs(OldCapacitor - CurrentCapacitor) > 0.1f)
	{
		OnCapacitorChanged.Broadcast(CurrentCapacitor, MaxCapacitor);
	}
}

bool UEquipmentManagerComponent::ServerOnly_CheckAmmo(FCommon_ItemSlot& Slot)
{
	// If module has quantity and it's > 0, we have ammo
	// If quantity is 0 or module doesn't use ammo, return true
	if (Slot.Quantity > 0)
	{
		return true;
	}

	// Modules that don't use ammo will have Quantity = 0
	// Check if this is a weapon that needs ammo
	if (ServerOnly_IsWeaponModule(Slot.SlotType, Slot))
	{
		// Weapon with no ammo
		return Slot.Quantity > 0;
	}

	// Non-weapon modules don't need ammo
	return true;
}

void UEquipmentManagerComponent::ServerOnly_ConsumeAmmo(FCommon_ItemSlot& Slot)
{
	if (Slot.Quantity > 0)
	{
		Slot.Quantity--;
	}
}

bool UEquipmentManagerComponent::ServerOnly_CheckRange(ESlotType SlotType, int32 SlotIndex)
{
	AActor* Target = ServerOnly_GetCurrentTarget();
	if (!Target || !GetOwner())
	{
		return false;
	}

	const FCommon_ItemSlot Slot = Common_GetModuleSlot(SlotType, SlotIndex);
	float ModuleRange = ServerOnly_GetModuleRange(Slot);

	float Distance = FVector::Dist(GetOwner()->GetActorLocation(), Target->GetActorLocation());
	return Distance <= ModuleRange;
}

bool UEquipmentManagerComponent::ServerOnly_IsWeaponModule(ESlotType SlotType, const FCommon_ItemSlot& Slot) const
{
	// High slots are typically weapons
	if (SlotType == ESlotType::High)
	{
		// Check if module name contains weapon keywords
		return Slot.ItemName.Contains(TEXT("Blaster"), ESearchCase::IgnoreCase) ||
			   Slot.ItemName.Contains(TEXT("Laser"), ESearchCase::IgnoreCase) ||
			   Slot.ItemName.Contains(TEXT("Missile"), ESearchCase::IgnoreCase) ||
			   Slot.ItemName.Contains(TEXT("Torpedo"), ESearchCase::IgnoreCase) ||
			   Slot.ItemName.Contains(TEXT("Gun"), ESearchCase::IgnoreCase);
	}

	return false;
}

float UEquipmentManagerComponent::ServerOnly_GetModuleRange(const FCommon_ItemSlot& Slot) const
{
	// This would normally be pulled from module stats
	// For now, return default range
	return DefaultWeaponRange;
}

AActor* UEquipmentManagerComponent::ServerOnly_GetCurrentTarget() const
{
	if (!CachedOwnerPawn)
	{
		return nullptr;
	}

	// Try to find targeting component
	UTargetingComponent* TargetingComp = CachedOwnerPawn->FindComponentByClass<UTargetingComponent>();
	if (TargetingComp)
	{
		TArray<AActor*> LockedTargets = TargetingComp->Common_GetLockedTargets();
		if (LockedTargets.Num() > 0)
		{
			return LockedTargets[0]; // Return first locked target
		}
	}

	return nullptr;
}

void UEquipmentManagerComponent::ServerOnly_UpdateCooldowns(float DeltaTime)
{
	auto UpdateSlots = [DeltaTime, this](TArray<FCommon_ItemSlot>& Slots, ESlotType Type)
	{
		for (int32 i = 0; i < Slots.Num(); ++i)
		{
			if (Slots[i].Cooldown > 0.0f)
			{
				Slots[i].Cooldown = FMath::Max(0.0f, Slots[i].Cooldown - DeltaTime);

				// If cooldown just finished
				if (Slots[i].Cooldown <= 0.0f && Slots[i].ModuleState == EModuleState::Cooldown)
				{
					Slots[i].ModuleState = EModuleState::Offline;
					ClientRPC_NotifyModuleState(Type, i, EModuleState::Offline);
					OnModuleStateChanged.Broadcast(Type, i, EModuleState::Offline);
				}
			}
		}
	};

	UpdateSlots(CurrentFitting.HighSlots, ESlotType::High);
	UpdateSlots(CurrentFitting.MidSlots, ESlotType::Mid);
	UpdateSlots(CurrentFitting.LowSlots, ESlotType::Low);
}

void UEquipmentManagerComponent::ServerOnly_RechargeCapacitor(float DeltaTime)
{
	if (CurrentCapacitor < MaxCapacitor)
	{
		float OldCapacitor = CurrentCapacitor;
		CurrentCapacitor = FMath::Min(MaxCapacitor, CurrentCapacitor + (CapacitorRechargeRate * DeltaTime));

		// Notify if changed significantly
		if (FMath::Abs(CurrentCapacitor - OldCapacitor) > 1.0f)
		{
			OnCapacitorChanged.Broadcast(CurrentCapacitor, MaxCapacitor);
		}
	}
}

FCommon_ItemSlot* UEquipmentManagerComponent::GetMutableSlot(ESlotType SlotType, int32 SlotIndex)
{
	TArray<FCommon_ItemSlot>* Slots = GetSlotArray(SlotType);
	if (Slots && SlotIndex >= 0 && SlotIndex < Slots->Num())
	{
		return &(*Slots)[SlotIndex];
	}
	return nullptr;
}

TArray<FCommon_ItemSlot>* UEquipmentManagerComponent::GetSlotArray(ESlotType SlotType)
{
	switch (SlotType)
	{
	case ESlotType::High:
		return &CurrentFitting.HighSlots;
	case ESlotType::Mid:
		return &CurrentFitting.MidSlots;
	case ESlotType::Low:
		return &CurrentFitting.LowSlots;
	case ESlotType::Rig:
		return &CurrentFitting.RigSlots;
	default:
		return nullptr;
	}
}
