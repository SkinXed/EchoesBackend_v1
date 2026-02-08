// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Core/Common/EchoesCoreTypes.h"
#include "ShipFittingInterface.generated.h"

/**
 * Slot type enumeration
 * Represents different equipment slot categories
 */
UENUM(BlueprintType)
enum class ESlotType : uint8
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

/** Invalid/unassigned */
None UMETA(DisplayName = "None")
};

/**
 * Module state enumeration
 */
UENUM(BlueprintType)
enum class EModuleState : uint8
{
/** Module is offline/inactive */
Offline UMETA(DisplayName = "Offline"),

/** Module is active/running */
Active UMETA(DisplayName = "Active"),

/** Module is overloaded (increased performance, risk of burnout) */
Overload UMETA(DisplayName = "Overload"),

/** Module is in cooldown */
Cooldown UMETA(DisplayName = "Cooldown"),

/** Module is damaged/burnt out */
Damaged UMETA(DisplayName = "Damaged")
};

/**
 * FCommon_ItemSlot
 * 
 * Represents a single equipment slot on a ship
 * Contains module information and activation state
 */
USTRUCT(BlueprintType)
struct FCommon_ItemSlot
{
GENERATED_BODY()

/** Unique slot identifier (0-based index within slot type) */
UPROPERTY(BlueprintReadWrite, Category = "Item Slot")
int32 SlotIndex;

/** Slot type (High/Mid/Low/Rig/Subsystem) */
UPROPERTY(BlueprintReadWrite, Category = "Item Slot")
ESlotType SlotType;

/** Item/Module ID (0 = empty slot) */
UPROPERTY(BlueprintReadWrite, Category = "Item Slot")
int32 ItemID;

/** Item name for display */
UPROPERTY(BlueprintReadWrite, Category = "Item Slot")
FString ItemName;

/** Icon texture for UI */
UPROPERTY(BlueprintReadWrite, Category = "Item Slot")
UTexture2D* IconTexture;

/** Quantity/charges (for ammo, nanite paste, etc.) */
UPROPERTY(BlueprintReadWrite, Category = "Item Slot")
int32 Quantity;

/** Current cooldown remaining (seconds) */
UPROPERTY(BlueprintReadWrite, Category = "Item Slot")
float Cooldown;

/** Module activation state */
UPROPERTY(BlueprintReadWrite, Category = "Item Slot")
EModuleState ModuleState;

/** Is this module currently active? */
UPROPERTY(BlueprintReadWrite, Category = "Item Slot")
bool bIsActive;

/** Can this module be activated? (has capacitor, not in cooldown) */
UPROPERTY(BlueprintReadWrite, Category = "Item Slot")
bool bCanActivate;

/** Powergrid requirement */
UPROPERTY(BlueprintReadWrite, Category = "Item Slot")
float PowergridRequired;

/** CPU requirement */
UPROPERTY(BlueprintReadWrite, Category = "Item Slot")
float CPURequired;

/** Capacitor cost per activation */
UPROPERTY(BlueprintReadWrite, Category = "Item Slot")
float CapacitorCost;

/** Constructor */
FCommon_ItemSlot()
: SlotIndex(0)
, SlotType(ESlotType::None)
, ItemID(0)
, ItemName(TEXT("Empty"))
, IconTexture(nullptr)
, Quantity(0)
, Cooldown(0.0f)
, ModuleState(EModuleState::Offline)
, bIsActive(false)
, bCanActivate(false)
, PowergridRequired(0.0f)
, CPURequired(0.0f)
, CapacitorCost(0.0f)
{
}

/** Check if slot is empty */
FORCEINLINE bool IsEmpty() const
{
return ItemID == 0;
}

/** Check if slot has a module */
FORCEINLINE bool HasModule() const
{
return ItemID > 0;
}

/** Check if module is in cooldown */
FORCEINLINE bool IsInCooldown() const
{
return Cooldown > 0.0f;
}
};

/**
 * FCommon_ModuleStats
 * 
 * Statistics for a single module
 * Used for display and calculations
 */
USTRUCT(BlueprintType)
struct FCommon_ModuleStats
{
GENERATED_BODY()

/** DPS contribution */
UPROPERTY(BlueprintReadOnly, Category = "Module Stats")
float DPS;

/** Alpha damage (single shot) */
UPROPERTY(BlueprintReadOnly, Category = "Module Stats")
float AlphaDamage;

/** Shield HP bonus */
UPROPERTY(BlueprintReadOnly, Category = "Module Stats")
float ShieldBonus;

/** Armor HP bonus */
UPROPERTY(BlueprintReadOnly, Category = "Module Stats")
float ArmorBonus;

/** Hull HP bonus */
UPROPERTY(BlueprintReadOnly, Category = "Module Stats")
float HullBonus;

/** Speed multiplier (1.0 = no change, 1.1 = +10%) */
UPROPERTY(BlueprintReadOnly, Category = "Module Stats")
float SpeedMultiplier;

/** Scan resolution bonus */
UPROPERTY(BlueprintReadOnly, Category = "Module Stats")
float ScanResolutionBonus;

/** EM resistance bonus */
UPROPERTY(BlueprintReadOnly, Category = "Module Stats")
float EMResistBonus;

/** Thermal resistance bonus */
UPROPERTY(BlueprintReadOnly, Category = "Module Stats")
float ThermalResistBonus;

/** Kinetic resistance bonus */
UPROPERTY(BlueprintReadOnly, Category = "Module Stats")
float KineticResistBonus;

/** Explosive resistance bonus */
UPROPERTY(BlueprintReadOnly, Category = "Module Stats")
float ExplosiveResistBonus;

/** Constructor */
FCommon_ModuleStats()
: DPS(0.0f)
, AlphaDamage(0.0f)
, ShieldBonus(0.0f)
, ArmorBonus(0.0f)
, HullBonus(0.0f)
, SpeedMultiplier(1.0f)
, ScanResolutionBonus(0.0f)
, EMResistBonus(0.0f)
, ThermalResistBonus(0.0f)
, KineticResistBonus(0.0f)
, ExplosiveResistBonus(0.0f)
{
}
};

/**
 * FCommon_ShipFittingData
 * 
 * Complete fitting data for a ship
 * Contains all equipment slots and calculated statistics
 */
USTRUCT(BlueprintType)
struct FCommon_ShipFittingData
{
GENERATED_BODY()

// ==================== Equipment Slots ====================

/** High slots (weapons, utility) */
UPROPERTY(BlueprintReadWrite, Category = "Fitting")
TArray<FCommon_ItemSlot> HighSlots;

/** Medium slots (shields, propulsion, EWAR) */
UPROPERTY(BlueprintReadWrite, Category = "Fitting")
TArray<FCommon_ItemSlot> MidSlots;

/** Low slots (armor, damage mods, engineering) */
UPROPERTY(BlueprintReadWrite, Category = "Fitting")
TArray<FCommon_ItemSlot> LowSlots;

/** Rig slots (permanent modifications) */
UPROPERTY(BlueprintReadWrite, Category = "Fitting")
TArray<FCommon_ItemSlot> RigSlots;

// ==================== Resource Usage ====================

/** Current powergrid usage */
UPROPERTY(BlueprintReadOnly, Category = "Fitting")
float PowergridUsed;

/** Maximum available powergrid */
UPROPERTY(BlueprintReadOnly, Category = "Fitting")
float PowergridMax;

/** Current CPU usage */
UPROPERTY(BlueprintReadOnly, Category = "Fitting")
float CPUUsed;

/** Maximum available CPU */
UPROPERTY(BlueprintReadOnly, Category = "Fitting")
float CPUMax;

// ==================== Calculated Stats ====================

/** Total DPS (all weapons) */
UPROPERTY(BlueprintReadOnly, Category = "Fitting Stats")
float TotalDPS;

/** Alpha strike damage */
UPROPERTY(BlueprintReadOnly, Category = "Fitting Stats")
float AlphaStrike;

/** Effective HP (with resistances) */
UPROPERTY(BlueprintReadOnly, Category = "Fitting Stats")
float EffectiveHP;

/** Maximum speed */
UPROPERTY(BlueprintReadOnly, Category = "Fitting Stats")
float MaxSpeed;

/** Warp speed */
UPROPERTY(BlueprintReadOnly, Category = "Fitting Stats")
float WarpSpeed;

/** Scan resolution */
UPROPERTY(BlueprintReadOnly, Category = "Fitting Stats")
float ScanResolution;

/** Signature radius */
UPROPERTY(BlueprintReadOnly, Category = "Fitting Stats")
float SignatureRadius;

/** Shield layer stats and resistances */
UPROPERTY(BlueprintReadOnly, Category = "Fitting Stats")
FCosmosDefenseLayer ShieldLayer;

/** Armor layer stats and resistances */
UPROPERTY(BlueprintReadOnly, Category = "Fitting Stats")
FCosmosDefenseLayer ArmorLayer;

/** Structure layer stats and resistances */
UPROPERTY(BlueprintReadOnly, Category = "Fitting Stats")
FCosmosDefenseLayer StructureLayer;

/** Constructor */
FCommon_ShipFittingData()
: PowergridUsed(0.0f)
, PowergridMax(100.0f)
, CPUUsed(0.0f)
, CPUMax(100.0f)
, TotalDPS(0.0f)
, AlphaStrike(0.0f)
, EffectiveHP(0.0f)
, MaxSpeed(100.0f)
, WarpSpeed(3.0f)
, ScanResolution(100.0f)
, SignatureRadius(50.0f)
{
}

/** Get slot by type and index */
FCommon_ItemSlot* GetSlot(ESlotType Type, int32 Index)
{
TArray<FCommon_ItemSlot>* SlotArray = GetSlotArray(Type);
if (SlotArray && SlotArray->IsValidIndex(Index))
{
return &(*SlotArray)[Index];
}
return nullptr;
}

/** Get slot array for type */
TArray<FCommon_ItemSlot>* GetSlotArray(ESlotType Type)
{
switch (Type)
{
case ESlotType::High: return &HighSlots;
case ESlotType::Mid: return &MidSlots;
case ESlotType::Low: return &LowSlots;
case ESlotType::Rig: return &RigSlots;
default: return nullptr;
}
}

/** Check if fitting is valid (within PG/CPU limits) */
FORCEINLINE bool IsValid() const
{
return PowergridUsed <= PowergridMax && CPUUsed <= CPUMax;
}

/** Get powergrid percentage used */
FORCEINLINE float GetPowergridPercentage() const
{
return PowergridMax > 0.0f ? (PowergridUsed / PowergridMax) : 0.0f;
}

/** Get CPU percentage used */
FORCEINLINE float GetCPUPercentage() const
{
return CPUMax > 0.0f ? (CPUUsed / CPUMax) : 0.0f;
}
};

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class UShipFittingInterface : public UInterface
{
GENERATED_BODY()
};

/**
 * IShipFittingInterface
 * 
 * Interface for accessing ship fitting data
 * Implemented by ship pawns or fitting components
 * 
 * Purpose:
 * - Decouple UI from specific fitting implementation
 * - Allow queries for equipment and stats
 * - Support server-authoritative fitting changes
 */
class ECHOES_API IShipFittingInterface
{
GENERATED_BODY()

public:
/**
 * Get complete fitting data for this ship
 * 
 * @return Fitting data with all slots and stats
 */
UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ship Fitting")
FCommon_ShipFittingData GetFittingData() const;

/**
 * Get a specific equipment slot
 * 
 * @param SlotType The type of slot (High/Mid/Low/Rig)
 * @param SlotIndex Index within that slot type
 * @param OutSlot The slot data
 * @return True if slot exists
 */
UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ship Fitting")
bool GetEquipmentSlot(ESlotType SlotType, int32 SlotIndex, FCommon_ItemSlot& OutSlot) const;

/**
 * Check if a module can be installed in a slot
 * 
 * @param ItemID The module to check
 * @param SlotType Target slot type
 * @param SlotIndex Target slot index
 * @return True if module can be installed (PG/CPU available)
 */
UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ship Fitting")
bool CanInstallModule(int32 ItemID, ESlotType SlotType, int32 SlotIndex) const;
};

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class UEquipmentObserver : public UInterface
{
GENERATED_BODY()
};

/**
 * IEquipmentObserver
 * 
 * Interface for widgets that observe fitting changes
 * Allows reactive updates when equipment is modified
 * 
 * Purpose:
 * - Stats widget subscribes to fitting changes
 * - Automatically redraws when modules change
 * - Decouples fitting UI from stats UI
 */
class ECHOES_API IEquipmentObserver
{
GENERATED_BODY()

public:
/**
 * Called when equipment is changed (installed/uninstalled)
 * 
 * @param SlotType The slot type that changed
 * @param SlotIndex The slot index that changed
 * @param NewSlotData The new slot data
 */
UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Equipment Observer")
void OnEquipmentChanged(ESlotType SlotType, int32 SlotIndex, const FCommon_ItemSlot& NewSlotData);

/**
 * Called when fitting stats are recalculated
 * 
 * @param NewFittingData The updated fitting data with new stats
 */
UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Equipment Observer")
void OnFittingStatsChanged(const FCommon_ShipFittingData& NewFittingData);
};
