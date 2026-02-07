// Copyright Epic Games, Inc. All Rights Reserved.
// Echoes - EVE-like MMO
// Game State Types and Enumerations

#pragma once

#include "CoreMinimal.h"
#include "EchoesGameState.generated.h"

/**
 * Network Game State
 * Represents the current state of the player in the game world
 */
UENUM(BlueprintType)
enum class ENetworkGameState : uint8
{
	Unknown UMETA(DisplayName = "Unknown"),
	InHangar UMETA(DisplayName = "In Hangar"),
	InSpace UMETA(DisplayName = "In Space"),
	InWarp UMETA(DisplayName = "In Warp"),
	Docking UMETA(DisplayName = "Docking"),
	Undocking UMETA(DisplayName = "Undocking"),
	Dead UMETA(DisplayName = "Dead")
};

/**
 * Module Activation State
 * Represents the current activation state of a ship module
 */
UENUM(BlueprintType)
enum class EModuleActivationResult : uint8
{
	Success UMETA(DisplayName = "Success"),
	NotEnoughCapacitor UMETA(DisplayName = "Not Enough Capacitor"),
	NotEnoughAmmo UMETA(DisplayName = "Not Enough Ammo"),
	InCooldown UMETA(DisplayName = "In Cooldown"),
	OutOfRange UMETA(DisplayName = "Out Of Range"),
	NoTarget UMETA(DisplayName = "No Target"),
	InvalidModule UMETA(DisplayName = "Invalid Module"),
	ModuleDamaged UMETA(DisplayName = "Module Damaged"),
	ModuleOffline UMETA(DisplayName = "Module Offline")
};

/**
 * Stat Modifier Type
 * Represents different types of stat modifications from modules
 */
UENUM(BlueprintType)
enum class EStatModifierType : uint8
{
	ShieldBoost UMETA(DisplayName = "Shield Boost"),
	ArmorBoost UMETA(DisplayName = "Armor Boost"),
	StructureBoost UMETA(DisplayName = "Structure Boost"),
	CapacitorBoost UMETA(DisplayName = "Capacitor Boost"),
	DamageBoost UMETA(DisplayName = "Damage Boost"),
	ROFBoost UMETA(DisplayName = "Rate of Fire Boost"),
	SpeedBoost UMETA(DisplayName = "Speed Boost"),
	ScanResolutionBoost UMETA(DisplayName = "Scan Resolution Boost"),
	SignatureRadiusReduction UMETA(DisplayName = "Signature Radius Reduction"),
	ResistanceEM UMETA(DisplayName = "EM Resistance"),
	ResistanceThermal UMETA(DisplayName = "Thermal Resistance"),
	ResistanceKinetic UMETA(DisplayName = "Kinetic Resistance"),
	ResistanceExplosive UMETA(DisplayName = "Explosive Resistance")
};

/**
 * Stat Modifier Application Type
 * How the modifier should be applied to the base stat
 */
UENUM(BlueprintType)
enum class EModifierApplication : uint8
{
	Additive UMETA(DisplayName = "Additive (+)"),
	Multiplicative UMETA(DisplayName = "Multiplicative (×)"),
	Percentage UMETA(DisplayName = "Percentage (%)")
};

/**
 * Stat Modifier Structure
 * Represents a single stat modification from a module
 */
USTRUCT(BlueprintType)
struct FStatModifier
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Modifier")
	EStatModifierType ModifierType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Modifier")
	EModifierApplication ApplicationType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Modifier")
	float Value;

	FStatModifier()
		: ModifierType(EStatModifierType::ShieldBoost)
		, ApplicationType(EModifierApplication::Additive)
		, Value(0.0f)
	{}

	FStatModifier(EStatModifierType Type, EModifierApplication Application, float Val)
		: ModifierType(Type)
		, ApplicationType(Application)
		, Value(Val)
	{}
};

/**
 * Module Ammunition Data
 * Represents ammunition requirements for a module
 */
USTRUCT(BlueprintType)
struct FModuleAmmoData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ammo")
	int32 AmmoTypeID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ammo")
	FString AmmoTypeName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ammo")
	int32 CurrentAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ammo")
	int32 MaxAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ammo")
	int32 AmmoPerShot;

	FModuleAmmoData()
		: AmmoTypeID(0)
		, AmmoTypeName(TEXT(""))
		, CurrentAmmo(0)
		, MaxAmmo(0)
		, AmmoPerShot(1)
	{}

	bool HasEnoughAmmo() const
	{
		return CurrentAmmo >= AmmoPerShot;
	}

	void ConsumeAmmo()
	{
		CurrentAmmo = FMath::Max(0, CurrentAmmo - AmmoPerShot);
	}
};
