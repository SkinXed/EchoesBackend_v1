// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Engine/Texture2D.h"
#include "Engine/StaticMesh.h"
#include "EchoesItemDefinitions.generated.h"

/**
 * Forward declaration of ESlotType from ShipFittingInterface
 * This enum defines fitting slot types: High, Mid, Low, Rig, Subsystem
 */
UENUM(BlueprintType)
enum class EEchoesSlotType : uint8
{
	/** High slots - Weapons, offensive modules */
	High UMETA(DisplayName = "High Slot"),
	
	/** Medium slots - Shields, propulsion, electronic warfare */
	Mid UMETA(DisplayName = "Mid Slot"),
	
	/** Low slots - Armor, damage mods, engine upgrades */
	Low UMETA(DisplayName = "Low Slot"),
	
	/** Rig slots - Permanent ship modifications */
	Rig UMETA(DisplayName = "Rig Slot"),
	
	/** Subsystem slots - T3 ship subsystems */
	Subsystem UMETA(DisplayName = "Subsystem Slot"),
	
	/** Not fittable / Invalid */
	None UMETA(DisplayName = "None")
};

/**
 * Item category enumeration
 * Categorizes items for filtering and organization
 */
UENUM(BlueprintType)
enum class EEchoesItemCategory : uint8
{
	None = 0 UMETA(DisplayName = "None"),
	Ore UMETA(DisplayName = "Ore"),
	Mineral UMETA(DisplayName = "Mineral"),
	Module UMETA(DisplayName = "Module"),
	Ammo UMETA(DisplayName = "Ammunition"),
	Ship UMETA(DisplayName = "Ship"),
	Blueprint UMETA(DisplayName = "Blueprint"),
	Component UMETA(DisplayName = "Component"),
	Commodity UMETA(DisplayName = "Commodity"),
	Implant UMETA(DisplayName = "Implant"),
	Skill UMETA(DisplayName = "Skill"),
	Charge UMETA(DisplayName = "Charge"),
	Drone UMETA(DisplayName = "Drone"),
	Fighter UMETA(DisplayName = "Fighter"),
	Structure UMETA(DisplayName = "Structure"),
	Subsystem UMETA(DisplayName = "Subsystem"),
	Rig UMETA(DisplayName = "Rig"),
	MAX UMETA(Hidden)
};

/**
 * FEchoesItemDefinitionRow
 * 
 * Data table row structure for item definitions
 * Maps database item IDs to visual assets and metadata
 * 
 * Usage:
 * - Create Data Table asset in Unreal Editor based on this struct
 * - Row names should match database TypeId (as string)
 * - Fill in visual assets (icons, meshes) and metadata
 * - Reference table in UEchoesInventorySubsystem
 * 
 * Example Data Table Setup:
 * Row Name: "34" (Tritanium TypeId)
 * DisplayName: "Tritanium"
 * Description: "The most common ore in space..."
 * Icon: T_Icon_Tritanium
 * WorldMesh: SM_Ore_Tritanium
 * UnitVolume: 0.01
 * UnitMass: 0.01
 * Category: Ore
 */
USTRUCT(BlueprintType)
struct ECHOES_API FEchoesItemDefinitionRow : public FTableRowBase
{
	GENERATED_BODY()

	/**
	 * Localized display name for the item
	 * Supports localization for different languages
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Definition")
	FText DisplayName;

	/**
	 * Localized description of the item
	 * Displayed in tooltips and detail panels
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Definition")
	FText Description;

	/**
	 * Icon texture for UI display (ListView, tooltips, etc.)
	 * Soft reference for async loading to prevent freezes
	 * Recommended size: 64x64 or 128x128
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Definition|Visual")
	TSoftObjectPtr<UTexture2D> Icon;

	/**
	 * 3D mesh for world representation
	 * Used when item is ejected into space or displayed in 3D
	 * Soft reference for streaming
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Definition|Visual")
	TSoftObjectPtr<UStaticMesh> WorldMesh;

	/**
	 * Volume of a single unit (in cubic meters)
	 * Used for cargo capacity calculations
	 * TotalVolume = Quantity * UnitVolume
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Definition|Physics")
	float UnitVolume = 0.01f;

	/**
	 * Mass of a single unit (in kilograms)
	 * Used for physics and ship mass calculations
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Definition|Physics")
	float UnitMass = 0.01f;

	/**
	 * Item category for organization and filtering
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Definition")
	EEchoesItemCategory Category = EEchoesItemCategory::None;

	/**
	 * Optional: Market group ID for market categorization
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Definition|Market")
	int32 MarketGroupId = 0;

	/**
	 * Optional: Tech level of the item (0-5, where 5 is highest tech)
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Definition|Meta")
	int32 TechLevel = 1;

	/**
	 * Optional: Meta level (0 = regular, 1+ = special variants)
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Definition|Meta")
	int32 MetaLevel = 0;

	/**
	 * Whether this item can be stacked in inventory
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Definition")
	bool bIsStackable = true;

	/**
	 * Maximum stack size (0 = unlimited)
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Definition")
	int32 MaxStackSize = 0;

	/**
	 * Fitting slot type for modules/equipment
	 * Determines which slot on a ship this module can be fitted to
	 * None = Not a fittable module (ore, minerals, etc.)
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Definition|Fitting")
	EEchoesSlotType FitSlot = EEchoesSlotType::None;

	/**
	 * Powergrid requirement for fitting this module
	 * Only applicable to modules (Category == Module)
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Definition|Fitting")
	float PowergridRequired = 0.0f;

	/**
	 * CPU requirement for fitting this module
	 * Only applicable to modules (Category == Module)
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Definition|Fitting")
	float CPURequired = 0.0f;

	// Constructor
	FEchoesItemDefinitionRow()
		: DisplayName(FText::FromString(TEXT("Unknown Item")))
		, Description(FText::FromString(TEXT("No description available.")))
		, UnitVolume(0.01f)
		, UnitMass(0.01f)
		, Category(EEchoesItemCategory::None)
		, MarketGroupId(0)
		, TechLevel(1)
		, MetaLevel(0)
		, bIsStackable(true)
		, MaxStackSize(0)
		, FitSlot(EEchoesSlotType::None)
		, PowergridRequired(0.0f)
		, CPURequired(0.0f)
	{
	}
};

/**
 * FWeaponAttributesRow
 * 
 * Weapon-specific attributes data table row
 * Separated from main item table to avoid bloating with module-specific data
 * 
 * Usage:
 * - Create separate Data Table for weapon/module attributes
 * - Row names should match TypeId (same as FEchoesItemDefinitionRow)
 * - Only populate rows for modules/weapons
 * - Use Common_GetWeaponAttributes() helper to fetch this data
 * 
 * Example Data Table Setup:
 * Row Name: "2048" (Light Neutron Blaster TypeId)
 * Damage: 55.0
 * OptimalRange: 2000.0 (2km)
 * Falloff: 8000.0 (8km)
 * TrackingSpeed: 0.4
 * ActivationCost: 5.0 (GJ)
 * AmmoTypeId: 256 (Antimatter Charge S)
 */
USTRUCT(BlueprintType)
struct ECHOES_API FWeaponAttributesRow : public FTableRowBase
{
	GENERATED_BODY()

	/**
	 * Base damage per hit/cycle
	 * Actual damage depends on ammo type and target resistances
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Attributes")
	float Damage = 0.0f;

	/**
	 * Optimal range in centimeters (UE units)
	 * Full damage applied up to this distance
	 * Example: 200000.0 = 2km optimal
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Attributes|Range")
	float OptimalRange = 0.0f;

	/**
	 * Falloff range in centimeters (UE units)
	 * Damage decreases from Optimal to Optimal+Falloff
	 * Example: 800000.0 = 8km falloff
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Attributes|Range")
	float Falloff = 0.0f;

	/**
	 * Tracking speed (radians per second)
	 * Affects ability to hit small/fast targets
	 * Higher = better tracking
	 * Example: 0.4 = good tracking for medium weapons
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Attributes|Accuracy")
	float TrackingSpeed = 0.0f;

	/**
	 * Capacitor energy cost per activation (in GJ)
	 * Deducted from ship's capacitor when fired
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Attributes|Activation")
	float ActivationCost = 0.0f;

	/**
	 * Activation time / Cycle time (in seconds)
	 * Time between shots or duration of active cycle
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Attributes|Activation")
	float ActivationTime = 1.0f;

	/**
	 * Ammo type ID required for this weapon
	 * 0 = No ammo required (energy weapons)
	 * >0 = Specific ammo TypeId required
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Attributes|Ammo")
	int32 AmmoTypeId = 0;

	/**
	 * Ammo consumption per shot/cycle
	 * Default: 1 ammo per activation
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Attributes|Ammo")
	int32 AmmoConsumptionPerCycle = 1;

	/**
	 * Maximum ammo capacity in weapon
	 * For weapons that load ammo (missiles, projectiles)
	 * 0 = Uses ship cargo (energy weapons)
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Attributes|Ammo")
	int32 MaxAmmoCapacity = 0;

	/**
	 * Damage multiplier for this weapon
	 * Applied on top of base damage (for special variants)
	 * Default: 1.0 (no modification)
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Attributes|Damage")
	float DamageMultiplier = 1.0f;

	/**
	 * Rate of fire modifier
	 * Values < 1.0 = faster firing, > 1.0 = slower
	 * Default: 1.0 (standard rate)
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Attributes|Activation")
	float RateOfFireMultiplier = 1.0f;

	// Constructor
	FWeaponAttributesRow()
		: Damage(0.0f)
		, OptimalRange(0.0f)
		, Falloff(0.0f)
		, TrackingSpeed(0.0f)
		, ActivationCost(0.0f)
		, ActivationTime(1.0f)
		, AmmoTypeId(0)
		, AmmoConsumptionPerCycle(1)
		, MaxAmmoCapacity(0)
		, DamageMultiplier(1.0f)
		, RateOfFireMultiplier(1.0f)
	{
	}
};
