// Copyright Epic Games, Inc. All Rights Reserved.

#include "CosmosAttributesComponent.h"
#include "Net/UnrealNetwork.h"
#include "GameFramework/Actor.h"

UCosmosAttributesComponent::UCosmosAttributesComponent()
{
	// Enable replication for this component
	SetIsReplicatedByDefault(true);

	// Initialize Shield layer (default values)
	Shield.Current = 1000.0f;
	Shield.Max = 1000.0f;
	Shield.ResistEM = 0.0f;
	Shield.ResistThermal = 0.0f;
	Shield.ResistKinetic = 0.0f;
	Shield.ResistExplosive = 0.0f;

	// Initialize Armor layer (default values)
	Armor.Current = 1000.0f;
	Armor.Max = 1000.0f;
	Armor.ResistEM = 0.0f;
	Armor.ResistThermal = 0.0f;
	Armor.ResistKinetic = 0.0f;
	Armor.ResistExplosive = 0.0f;

	// Initialize Structure layer (default values)
	Structure.Current = 1000.0f;
	Structure.Max = 1000.0f;
	Structure.ResistEM = 0.0f;
	Structure.ResistThermal = 0.0f;
	Structure.ResistKinetic = 0.0f;
	Structure.ResistExplosive = 0.0f;

	// Initialize Physics stats (default values)
	Mass = 1000000.0f;        // 1,000,000 kg (typical frigate)
	InertiaModifier = 1.0f;   // No modifier
	CargoCapacity = 400.0f;   // 400 m³ (typical frigate cargo)

	// Internal state
	LastDamageCauser = nullptr;
}

void UCosmosAttributesComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Replicate defense layers with RepNotify for UI updates
	DOREPLIFETIME(UCosmosAttributesComponent, Shield);
	DOREPLIFETIME(UCosmosAttributesComponent, Armor);
	DOREPLIFETIME(UCosmosAttributesComponent, Structure);

	// Replicate physics stats (no RepNotify needed)
	DOREPLIFETIME(UCosmosAttributesComponent, Mass);
	DOREPLIFETIME(UCosmosAttributesComponent, InertiaModifier);
	DOREPLIFETIME(UCosmosAttributesComponent, CargoCapacity);
}

bool UCosmosAttributesComponent::ServerOnly_ApplyDamage(float RawDamage, ECosmosDamageType DmgType, AActor* Instigator)
{
	// Validation: Only server can apply damage
	if (!GetOwner() || !GetOwner()->HasAuthority())
	{
		UE_LOG(LogTemp, Warning, TEXT("ServerOnly_ApplyDamage called on client - ignoring"));
		return false;
	}

	// Validation: Ignore negative or zero damage
	if (RawDamage <= 0.0f)
	{
		return false;
	}

	// Validation: Ignore damage if already dead
	if (!IsAlive())
	{
		return false;
	}

	// Cache damage causer for death event
	LastDamageCauser = Instigator;

	// Convert damage type to string for logging
	FString DamageTypeName;
	switch (DmgType)
	{
	case ECosmosDamageType::EM:
		DamageTypeName = TEXT("EM");
		break;
	case ECosmosDamageType::Thermal:
		DamageTypeName = TEXT("Thermal");
		break;
	case ECosmosDamageType::Kinetic:
		DamageTypeName = TEXT("Kinetic");
		break;
	case ECosmosDamageType::Explosive:
		DamageTypeName = TEXT("Explosive");
		break;
	case ECosmosDamageType::Omni:
		DamageTypeName = TEXT("Omni");
		break;
	default:
		DamageTypeName = TEXT("Unknown");
		break;
	}

	UE_LOG(LogTemp, Log, TEXT("%s: Incoming %.1f %s damage"), *GetOwner()->GetName(), RawDamage, *DamageTypeName);

	// ==================== Phase 1: Apply damage to Shield ====================
	float RemainingDamage = RawDamage;

	if (Shield.Current > 0.0f && RemainingDamage > 0.0f)
	{
		// Calculate mitigated damage using Shield's resistances
		float MitigatedDamage = Shield.CalculateMitigatedDamage(RemainingDamage, DmgType);
		float ShieldResistance = Shield.GetResistance(DmgType);

		// Apply damage to shield
		float DamageToShield = FMath::Min(Shield.Current, MitigatedDamage);
		Shield.Current -= DamageToShield;

		// Calculate overflow for next layer (based on mitigated damage, not raw)
		float Overflow = MitigatedDamage - DamageToShield;

		UE_LOG(LogTemp, Log, TEXT("%s: Shield took %.1f damage (%.1f%% resist, %.1f raw → %.1f mitigated), %.1f/%.1f remaining, %.1f overflow"),
			*GetOwner()->GetName(),
			DamageToShield,
			ShieldResistance * 100.0f,
			RemainingDamage,
			MitigatedDamage,
			Shield.Current,
			Shield.Max,
			Overflow);

		// Update remaining damage for next layer (use overflow, not original remaining)
		RemainingDamage = Overflow;
	}

	// ==================== Phase 2: Apply overflow damage to Armor ====================

	if (Armor.Current > 0.0f && RemainingDamage > 0.0f)
	{
		// Calculate mitigated damage using Armor's resistances (different from Shield!)
		float MitigatedDamage = Armor.CalculateMitigatedDamage(RemainingDamage, DmgType);
		float ArmorResistance = Armor.GetResistance(DmgType);

		// Apply damage to armor
		float DamageToArmor = FMath::Min(Armor.Current, MitigatedDamage);
		Armor.Current -= DamageToArmor;

		// Calculate overflow for next layer
		float Overflow = MitigatedDamage - DamageToArmor;

		UE_LOG(LogTemp, Log, TEXT("%s: Armor took %.1f damage (%.1f%% resist, %.1f raw → %.1f mitigated), %.1f/%.1f remaining, %.1f overflow"),
			*GetOwner()->GetName(),
			DamageToArmor,
			ArmorResistance * 100.0f,
			RemainingDamage,
			MitigatedDamage,
			Armor.Current,
			Armor.Max,
			Overflow);

		// Update remaining damage for next layer
		RemainingDamage = Overflow;
	}

	// ==================== Phase 3: Apply overflow damage to Structure ====================

	if (Structure.Current > 0.0f && RemainingDamage > 0.0f)
	{
		// Calculate mitigated damage using Structure's resistances (different from Shield and Armor!)
		float MitigatedDamage = Structure.CalculateMitigatedDamage(RemainingDamage, DmgType);
		float StructureResistance = Structure.GetResistance(DmgType);

		// Apply damage to structure
		float DamageToStructure = FMath::Min(Structure.Current, MitigatedDamage);
		Structure.Current -= DamageToStructure;

		// Calculate final overflow (for logging only)
		float Overflow = MitigatedDamage - DamageToStructure;

		UE_LOG(LogTemp, Log, TEXT("%s: Structure took %.1f damage (%.1f%% resist, %.1f raw → %.1f mitigated), %.1f/%.1f remaining, %.1f overflow"),
			*GetOwner()->GetName(),
			DamageToStructure,
			StructureResistance * 100.0f,
			RemainingDamage,
			MitigatedDamage,
			Structure.Current,
			Structure.Max,
			Overflow);

		// Update remaining damage (should be 0 or close to 0 if structure absorbed it all)
		RemainingDamage = Overflow;
	}

	// ==================== Phase 4: Check for death ====================

	if (Structure.Current <= 0.0f)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s: DESTROYED by %s damage from %s"),
			*GetOwner()->GetName(),
			*DamageTypeName,
			Instigator ? *Instigator->GetName() : TEXT("Unknown"));

		// Trigger death event
		OnDeath.Broadcast(GetOwner(), Instigator);

		// Note: Actual destruction/respawn logic should be handled by game mode or ship controller
		// This component only reports the death event
	}

	return true;
}

void UCosmosAttributesComponent::ClientOnly_OnRep_Stats()
{
	// This function is called on clients when any defense stat is replicated
	// Broadcast attributes changed event for UI widgets to subscribe to
	OnAttributesChanged.Broadcast();

	// Debug log (optional, can be disabled in production)
	UE_LOG(LogTemp, Verbose, TEXT("%s: Attributes updated - Shield: %.1f%%, Armor: %.1f%%, Structure: %.1f%%"),
		*GetOwner()->GetName(),
		Common_GetShieldPct() * 100.0f,
		Common_GetArmorPct() * 100.0f,
		Common_GetHullPct() * 100.0f);
}

float UCosmosAttributesComponent::Common_GetShieldPct() const
{
	return Shield.GetPercentage();
}

float UCosmosAttributesComponent::Common_GetArmorPct() const
{
	return Armor.GetPercentage();
}

float UCosmosAttributesComponent::Common_GetHullPct() const
{
	return Structure.GetPercentage();
}

float UCosmosAttributesComponent::Common_GetOverallHealthPct() const
{
	// Calculate total current and max health across all layers
	float TotalCurrent = Shield.Current + Armor.Current + Structure.Current;
	float TotalMax = Shield.Max + Armor.Max + Structure.Max;

	// Avoid division by zero
	if (TotalMax <= 0.0f)
	{
		return 0.0f;
	}

	// Return percentage (0.0 to 1.0)
	return FMath::Clamp(TotalCurrent / TotalMax, 0.0f, 1.0f);
}

bool UCosmosAttributesComponent::IsAlive() const
{
	return Structure.Current > 0.0f;
}

void UCosmosAttributesComponent::ServerOnly_RestoreAll()
{
	// Validation: Only server can restore stats
	if (!GetOwner() || !GetOwner()->HasAuthority())
	{
		UE_LOG(LogTemp, Warning, TEXT("ServerOnly_RestoreAll called on client - ignoring"));
		return;
	}

	// Fully restore all defense layers
	Shield.Restore();
	Armor.Restore();
	Structure.Restore();

	// Reset damage causer
	LastDamageCauser = nullptr;

	UE_LOG(LogTemp, Log, TEXT("%s: All attributes restored to maximum"), *GetOwner()->GetName());
}

void UCosmosAttributesComponent::ServerOnly_SetLayerResistances(int32 LayerIndex, float EM, float Thermal, float Kinetic, float Explosive)
{
	// Validation: Only server can set resistances
	if (!GetOwner() || !GetOwner()->HasAuthority())
	{
		UE_LOG(LogTemp, Warning, TEXT("ServerOnly_SetLayerResistances called on client - ignoring"));
		return;
	}

	// Clamp resistance values to valid range
	EM = FMath::Clamp(EM, 0.0f, 1.0f);
	Thermal = FMath::Clamp(Thermal, 0.0f, 1.0f);
	Kinetic = FMath::Clamp(Kinetic, 0.0f, 1.0f);
	Explosive = FMath::Clamp(Explosive, 0.0f, 1.0f);

	// Set resistances for specified layer
	switch (LayerIndex)
	{
	case 0: // Shield
		Shield.ResistEM = EM;
		Shield.ResistThermal = Thermal;
		Shield.ResistKinetic = Kinetic;
		Shield.ResistExplosive = Explosive;
		UE_LOG(LogTemp, Log, TEXT("%s: Shield resistances set - EM:%.1f%% Thermal:%.1f%% Kinetic:%.1f%% Explosive:%.1f%%"),
			*GetOwner()->GetName(), EM * 100.0f, Thermal * 100.0f, Kinetic * 100.0f, Explosive * 100.0f);
		break;

	case 1: // Armor
		Armor.ResistEM = EM;
		Armor.ResistThermal = Thermal;
		Armor.ResistKinetic = Kinetic;
		Armor.ResistExplosive = Explosive;
		UE_LOG(LogTemp, Log, TEXT("%s: Armor resistances set - EM:%.1f%% Thermal:%.1f%% Kinetic:%.1f%% Explosive:%.1f%%"),
			*GetOwner()->GetName(), EM * 100.0f, Thermal * 100.0f, Kinetic * 100.0f, Explosive * 100.0f);
		break;

	case 2: // Structure
		Structure.ResistEM = EM;
		Structure.ResistThermal = Thermal;
		Structure.ResistKinetic = Kinetic;
		Structure.ResistExplosive = Explosive;
		UE_LOG(LogTemp, Log, TEXT("%s: Structure resistances set - EM:%.1f%% Thermal:%.1f%% Kinetic:%.1f%% Explosive:%.1f%%"),
			*GetOwner()->GetName(), EM * 100.0f, Thermal * 100.0f, Kinetic * 100.0f, Explosive * 100.0f);
		break;

	default:
		UE_LOG(LogTemp, Warning, TEXT("ServerOnly_SetLayerResistances: Invalid LayerIndex %d (must be 0-2)"), LayerIndex);
		break;
	}
}
