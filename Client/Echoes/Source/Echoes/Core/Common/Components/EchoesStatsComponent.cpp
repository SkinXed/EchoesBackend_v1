// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesStatsComponent.h"
#include "Net/UnrealNetwork.h"
#include "GameFramework/Actor.h"

UEchoesStatsComponent::UEchoesStatsComponent()
{
	// Enable tick for shield regeneration
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.TickGroup = TG_PrePhysics;

	// Enable replication for this component
	SetIsReplicatedByDefault(true);

	// Initialize default values (can be overridden in editor or at runtime)
	// Shield layer - first line of defense, regenerates
	ShieldMax = 1000.0f;
	ShieldCurrent = 1000.0f;
	ShieldRegenRate = 10.0f;      // 10 HP per second
	ShieldRegenDelay = 10.0f;     // 10 seconds after taking damage

	// Armor layer - second line of defense, no regeneration
	ArmorMax = 1000.0f;
	ArmorCurrent = 1000.0f;

	// Structure layer - final line of defense, death when depleted
	StructureMax = 1000.0f;
	StructureCurrent = 1000.0f;

	// Internal state
	TimeSinceLastDamage = 0.0f;
	LastDamageCauser = nullptr;
}

void UEchoesStatsComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Replicate all Current values (with RepNotify for UI updates)
	DOREPLIFETIME(UEchoesStatsComponent, ShieldCurrent);
	DOREPLIFETIME(UEchoesStatsComponent, ArmorCurrent);
	DOREPLIFETIME(UEchoesStatsComponent, StructureCurrent);

	// Replicate Max values (no RepNotify needed)
	DOREPLIFETIME(UEchoesStatsComponent, ShieldMax);
	DOREPLIFETIME(UEchoesStatsComponent, ArmorMax);
	DOREPLIFETIME(UEchoesStatsComponent, StructureMax);
}

void UEchoesStatsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Only server handles shield regeneration
	if (!GetOwner() || !GetOwner()->HasAuthority())
	{
		return;
	}

	// Shield passive regeneration (EVE-like)
	if (ShieldCurrent < ShieldMax)
	{
		TimeSinceLastDamage += DeltaTime;

		// Check if enough time has passed since last damage
		if (TimeSinceLastDamage >= ShieldRegenDelay)
		{
			// Regenerate shield
			float RegenAmount = ShieldRegenRate * DeltaTime;
			ShieldCurrent = FMath::Min(ShieldCurrent + RegenAmount, ShieldMax);

			// Log shield regeneration (optional, can be disabled in production)
			if (ShieldCurrent >= ShieldMax)
			{
				UE_LOG(LogTemp, Verbose, TEXT("%s: Shield fully regenerated"), *GetOwner()->GetName());
			}
		}
	}
}

void UEchoesStatsComponent::ServerOnly_ApplyDamage(float Amount, AActor* DamageCauser)
{
	// Validation: Only server can apply damage
	if (!GetOwner() || !GetOwner()->HasAuthority())
	{
		UE_LOG(LogTemp, Warning, TEXT("ServerOnly_ApplyDamage called on client - ignoring"));
		return;
	}

	// Validation: Ignore negative or zero damage
	if (Amount <= 0.0f)
	{
		return;
	}

	// Validation: Ignore damage if already dead
	if (!IsAlive())
	{
		return;
	}

	// Cache damage causer for death event
	LastDamageCauser = DamageCauser;

	// Reset shield regeneration timer
	TimeSinceLastDamage = 0.0f;

	// EVE-like damage cascade: Shield → Armor → Structure
	float RemainingDamage = Amount;

	// Phase 1: Apply damage to Shield
	if (ShieldCurrent > 0.0f && RemainingDamage > 0.0f)
	{
		float ShieldDamage = FMath::Min(ShieldCurrent, RemainingDamage);
		ShieldCurrent -= ShieldDamage;
		RemainingDamage -= ShieldDamage;

		UE_LOG(LogTemp, Log, TEXT("%s: Shield took %.1f damage (%.1f/%.1f remaining)"),
			*GetOwner()->GetName(), ShieldDamage, ShieldCurrent, ShieldMax);
	}

	// Phase 2: Apply overflow damage to Armor
	if (ArmorCurrent > 0.0f && RemainingDamage > 0.0f)
	{
		float ArmorDamage = FMath::Min(ArmorCurrent, RemainingDamage);
		ArmorCurrent -= ArmorDamage;
		RemainingDamage -= ArmorDamage;

		UE_LOG(LogTemp, Log, TEXT("%s: Armor took %.1f damage (%.1f/%.1f remaining)"),
			*GetOwner()->GetName(), ArmorDamage, ArmorCurrent, ArmorMax);
	}

	// Phase 3: Apply overflow damage to Structure
	if (StructureCurrent > 0.0f && RemainingDamage > 0.0f)
	{
		float StructureDamage = FMath::Min(StructureCurrent, RemainingDamage);
		StructureCurrent -= StructureDamage;
		RemainingDamage -= StructureDamage;

		UE_LOG(LogTemp, Log, TEXT("%s: Structure took %.1f damage (%.1f/%.1f remaining)"),
			*GetOwner()->GetName(), StructureDamage, StructureCurrent, StructureMax);
	}

	// Check for death (Structure depleted)
	if (StructureCurrent <= 0.0f)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s: DESTROYED by %s"),
			*GetOwner()->GetName(),
			DamageCauser ? *DamageCauser->GetName() : TEXT("Unknown"));

		// Trigger death event
		OnDeath.Broadcast(GetOwner(), DamageCauser);

		// Note: Actual destruction/respawn logic should be handled by game mode or ship controller
		// This component only reports the death event
	}
}

void UEchoesStatsComponent::ClientOnly_OnRep_UpdateUI()
{
	// This function is called on clients when any Current value is replicated
	// Calculate percentages for UI
	float ShieldPct = Common_GetShieldPercentage();
	float ArmorPct = Common_GetArmorPercentage();
	float StructPct = Common_GetStructurePercentage();

	// Broadcast stats changed event for UI widgets to subscribe to
	OnStatsChanged.Broadcast(ShieldPct, ArmorPct, StructPct);

	// Debug log (optional, can be disabled in production)
	UE_LOG(LogTemp, Verbose, TEXT("%s: Stats updated - Shield: %.1f%%, Armor: %.1f%%, Structure: %.1f%%"),
		*GetOwner()->GetName(), ShieldPct * 100.0f, ArmorPct * 100.0f, StructPct * 100.0f);
}

float UEchoesStatsComponent::Common_GetHealthPercentage() const
{
	// Calculate total current and max health
	float TotalCurrent = ShieldCurrent + ArmorCurrent + StructureCurrent;
	float TotalMax = ShieldMax + ArmorMax + StructureMax;

	// Avoid division by zero
	if (TotalMax <= 0.0f)
	{
		return 0.0f;
	}

	// Return percentage (0.0 to 1.0)
	return FMath::Clamp(TotalCurrent / TotalMax, 0.0f, 1.0f);
}

float UEchoesStatsComponent::Common_GetShieldPercentage() const
{
	if (ShieldMax <= 0.0f)
	{
		return 0.0f;
	}
	return FMath::Clamp(ShieldCurrent / ShieldMax, 0.0f, 1.0f);
}

float UEchoesStatsComponent::Common_GetArmorPercentage() const
{
	if (ArmorMax <= 0.0f)
	{
		return 0.0f;
	}
	return FMath::Clamp(ArmorCurrent / ArmorMax, 0.0f, 1.0f);
}

float UEchoesStatsComponent::Common_GetStructurePercentage() const
{
	if (StructureMax <= 0.0f)
	{
		return 0.0f;
	}
	return FMath::Clamp(StructureCurrent / StructureMax, 0.0f, 1.0f);
}

bool UEchoesStatsComponent::IsAlive() const
{
	return StructureCurrent > 0.0f;
}

void UEchoesStatsComponent::ServerOnly_RestoreAll()
{
	// Validation: Only server can restore stats
	if (!GetOwner() || !GetOwner()->HasAuthority())
	{
		UE_LOG(LogTemp, Warning, TEXT("ServerOnly_RestoreAll called on client - ignoring"));
		return;
	}

	// Fully restore all stats
	ShieldCurrent = ShieldMax;
	ArmorCurrent = ArmorMax;
	StructureCurrent = StructureMax;

	// Reset damage timer
	TimeSinceLastDamage = 0.0f;
	LastDamageCauser = nullptr;

	UE_LOG(LogTemp, Log, TEXT("%s: All stats restored to maximum"), *GetOwner()->GetName());
}
