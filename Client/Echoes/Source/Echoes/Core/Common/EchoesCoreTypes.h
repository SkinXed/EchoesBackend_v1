// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EchoesCoreTypes.generated.h"

/**
 * Cosmos damage type enum
 * Represents the five damage types in EVE-like combat system
 * Each type can have different resistances on defense layers
 */
UENUM(BlueprintType)
enum class ECosmosDamageType : uint8
{
	/** Electromagnetic damage - typically effective against shields */
	EM UMETA(DisplayName = "Electromagnetic"),
	
	/** Thermal damage - heat-based damage */
	Thermal UMETA(DisplayName = "Thermal"),
	
	/** Kinetic damage - physical projectile damage */
	Kinetic UMETA(DisplayName = "Kinetic"),
	
	/** Explosive damage - explosive ordnance damage */
	Explosive UMETA(DisplayName = "Explosive"),
	
	/** Omni damage - pure damage that bypasses all resistances */
	Omni UMETA(DisplayName = "Omni (Pure)")
};

/**
 * Cosmos defense layer structure
 * Represents a single defense layer (Shield, Armor, or Structure) with resistances
 * 
 * Damage Mitigation Formula:
 * MitigatedDamage = RawDamage * (1.0 - Resistance)
 * 
 * Example: 100 damage with 0.5 (50%) resistance = 100 * (1.0 - 0.5) = 50 damage taken
 * 
 * Resistance Range: 0.0 (0% mitigation) to 1.0 (100% mitigation, immune)
 * Typical EVE values: 0.0 to 0.75 (0% to 75% mitigation)
 */
USTRUCT(BlueprintType)
struct FCosmosDefenseLayer
{
	GENERATED_BODY()

	// ==================== Hit Points ====================

	/** Current hit points for this layer */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Defense Layer")
	float Current = 1000.0f;

	/** Maximum hit points for this layer */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Defense Layer")
	float Max = 1000.0f;

	// ==================== Resistances (0.0 = 0%, 1.0 = 100%) ====================

	/** Electromagnetic damage resistance (0.0 to 1.0) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Defense Layer|Resistances", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float ResistEM = 0.0f;

	/** Thermal damage resistance (0.0 to 1.0) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Defense Layer|Resistances", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float ResistThermal = 0.0f;

	/** Kinetic damage resistance (0.0 to 1.0) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Defense Layer|Resistances", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float ResistKinetic = 0.0f;

	/** Explosive damage resistance (0.0 to 1.0) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Defense Layer|Resistances", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float ResistExplosive = 0.0f;

	// ==================== Helper Functions ====================

	/**
	 * Get resistance value for a specific damage type
	 * 
	 * @param Type - Damage type to query
	 * @return Resistance value (0.0 to 1.0), or 0.0 for Omni damage
	 */
	FORCEINLINE float GetResistance(ECosmosDamageType Type) const
	{
		switch (Type)
		{
		case ECosmosDamageType::EM:
			return ResistEM;
		case ECosmosDamageType::Thermal:
			return ResistThermal;
		case ECosmosDamageType::Kinetic:
			return ResistKinetic;
		case ECosmosDamageType::Explosive:
			return ResistExplosive;
		case ECosmosDamageType::Omni:
			return 0.0f; // Omni damage bypasses all resistances
		default:
			return 0.0f;
		}
	}

	/**
	 * Calculate damage after resistance mitigation
	 * 
	 * @param RawDamage - Incoming damage amount
	 * @param Type - Damage type
	 * @return Mitigated damage amount
	 */
	FORCEINLINE float CalculateMitigatedDamage(float RawDamage, ECosmosDamageType Type) const
	{
		if (RawDamage <= 0.0f)
		{
			return 0.0f;
		}

		float Resistance = GetResistance(Type);
		float MitigatedDamage = RawDamage * (1.0f - Resistance);
		
		return FMath::Max(0.0f, MitigatedDamage);
	}

	/**
	 * Get percentage of current HP relative to max HP
	 * 
	 * @return Percentage (0.0 to 1.0)
	 */
	FORCEINLINE float GetPercentage() const
	{
		if (Max <= 0.0f)
		{
			return 0.0f;
		}
		return FMath::Clamp(Current / Max, 0.0f, 1.0f);
	}

	/**
	 * Check if this layer is depleted
	 * 
	 * @return True if Current <= 0
	 */
	FORCEINLINE bool IsDepleted() const
	{
		return Current <= 0.0f;
	}

	/**
	 * Restore this layer to maximum hit points
	 */
	FORCEINLINE void Restore()
	{
		Current = Max;
	}

	// Default constructor
	FCosmosDefenseLayer()
		: Current(1000.0f)
		, Max(1000.0f)
		, ResistEM(0.0f)
		, ResistThermal(0.0f)
		, ResistKinetic(0.0f)
		, ResistExplosive(0.0f)
	{
	}
};
