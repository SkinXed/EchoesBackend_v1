// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Core/Common/Interfaces/ShipStateInterface.h"
#include "ShipStatusWidget.generated.h"

class UProgressBar;
class UTextBlock;
class UImage;
class UCanvasPanel;

/**
 * IShipStateObserver
 * 
 * Interface for widgets that observe ship state changes
 * Allows ship components to notify UI of health/capacitor changes
 */
UINTERFACE(MinimalAPI, Blueprintable)
class UShipStateObserver : public UInterface
{
GENERATED_BODY()
};

class ECHOES_API IShipStateObserver
{
GENERATED_BODY()

public:
/**
 * Called when ship stats change (Shield/Armor/Hull)
 * 
 * @param ShieldPct Shield percentage (0-1)
 * @param ArmorPct Armor percentage (0-1)
 * @param HullPct Hull percentage (0-1)
 */
UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ship State Observer")
void OnShipStatsChanged(float ShieldPct, float ArmorPct, float HullPct);

/**
 * Called when capacitor changes
 * 
 * @param CapacitorPct Capacitor percentage (0-1)
 */
UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ship State Observer")
void OnCapacitorChanged(float CapacitorPct);
};

/**
 * UShipStatusWidget
 * 
 * Central radial HUD display showing ship survivability
 * EVE-like circular health bars with capacitor in center
 * 
 * Features:
 * - Radial progress bars: Shield (outer), Armor (middle), Hull (inner)
 * - Central capacitor display with animation
 * - Color-coded health states (green/yellow/red)
 * - Event-driven updates (implements IShipStateObserver)
 * - No Tick function for performance
 * 
 * Visual Layout:
 * ```
 *     ┌─────────────┐
 *     │   Shield    │ Outer ring (blue)
 *     │  ┌───────┐  │
 *     │  │ Armor │  │ Middle ring (yellow/orange)
 *     │  │ ┌───┐ │  │
 *     │  │ │Cap│ │  │ Inner = Hull (red), Center = Capacitor
 *     │  │ └───┘ │  │
 *     │  └───────┘  │
 *     └─────────────┘
 * ```
 * 
 * Implementation Options:
 * 1. Blueprint: Use Progress Bar widgets with custom materials
 * 2. C++: Use UMG Canvas with custom radial drawing
 * 3. Hybrid: C++ logic + Blueprint materials
 * 
 * Usage:
 * // Bind to ship state interface
 * ShipStatusWidget->BindToShip(PlayerShip);
 * 
 * // Updates automatically via IShipStateObserver
 */
UCLASS(Abstract, Blueprintable)
class ECHOES_API UShipStatusWidget : public UUserWidget, public IShipStateObserver
{
GENERATED_BODY()

public:
UShipStatusWidget(const FObjectInitializer& ObjectInitializer);

//~ Begin UUserWidget Interface
virtual void NativeConstruct() override;
virtual void NativeDestruct() override;
//~ End UUserWidget Interface

//~ Begin IShipStateObserver Interface
virtual void OnShipStatsChanged_Implementation(float ShieldPct, float ArmorPct, float HullPct) override;
virtual void OnCapacitorChanged_Implementation(float CapacitorPct) override;
//~ End IShipStateObserver Interface

// ==================== Public API ====================

/**
 * Bind to a ship for automatic updates
 * 
 * @param Ship The ship actor implementing IShipStateInterface
 */
UFUNCTION(BlueprintCallable, Category = "Ship Status")
void BindToShip(AActor* Ship);

/**
 * Unbind from current ship
 */
UFUNCTION(BlueprintCallable, Category = "Ship Status")
void UnbindFromShip();

/**
 * CLIENT ONLY: Update shield display
 * 
 * @param ShieldPct Shield percentage (0.0 to 1.0)
 * @param ShieldCurrent Current shield HP
 * @param ShieldMax Maximum shield HP
 */
UFUNCTION(BlueprintCallable, Category = "Ship Status")
void ClientOnly_UpdateShield(float ShieldPct, float ShieldCurrent, float ShieldMax);

/**
 * CLIENT ONLY: Update armor display
 * 
 * @param ArmorPct Armor percentage (0.0 to 1.0)
 * @param ArmorCurrent Current armor HP
 * @param ArmorMax Maximum armor HP
 */
UFUNCTION(BlueprintCallable, Category = "Ship Status")
void ClientOnly_UpdateArmor(float ArmorPct, float ArmorCurrent, float ArmorMax);

/**
 * CLIENT ONLY: Update hull display
 * 
 * @param HullPct Hull percentage (0.0 to 1.0)
 * @param HullCurrent Current hull HP
 * @param HullMax Maximum hull HP
 */
UFUNCTION(BlueprintCallable, Category = "Ship Status")
void ClientOnly_UpdateHull(float HullPct, float HullCurrent, float HullMax);

/**
 * CLIENT ONLY: Update capacitor display
 * 
 * @param CapacitorPct Capacitor percentage (0.0 to 1.0)
 * @param CapacitorCurrent Current capacitor energy
 * @param CapacitorMax Maximum capacitor energy
 */
UFUNCTION(BlueprintCallable, Category = "Ship Status")
void ClientOnly_UpdateCapacitor(float CapacitorPct, float CapacitorCurrent, float CapacitorMax);

/**
 * CLIENT ONLY: Refresh all displays from bound ship
 */
UFUNCTION(BlueprintCallable, Category = "Ship Status")
void ClientOnly_RefreshAllDisplays();

/**
 * COMMON (Pure): Get color for health percentage
 * 
 * @param Percentage Health percentage (0-1)
 * @return Color (Green > 66%, Yellow 33-66%, Red < 33%)
 */
UFUNCTION(BlueprintPure, Category = "Ship Status")
static FLinearColor Common_GetHealthColor(float Percentage);

protected:
// ==================== Widget References ====================
// Note: These can be bound in Blueprint or created programmatically

/** Shield progress bar (outer ring) */
UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
UProgressBar* ShieldBar;

/** Armor progress bar (middle ring) */
UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
UProgressBar* ArmorBar;

/** Hull progress bar (inner ring) */
UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
UProgressBar* HullBar;

/** Capacitor progress bar (center) */
UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
UProgressBar* CapacitorBar;

/** Shield value text */
UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
UTextBlock* ShieldText;

/** Armor value text */
UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
UTextBlock* ArmorText;

/** Hull value text */
UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
UTextBlock* HullText;

/** Capacitor value text */
UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
UTextBlock* CapacitorText;

// ==================== Configuration ====================

/** Update interval for polling ship state (seconds) */
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship Status Settings")
float UpdateInterval;

/** Enable smooth animations for value changes */
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship Status Settings")
bool bEnableAnimations;

/** Animation speed for smooth transitions */
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship Status Settings")
float AnimationSpeed;

// ==================== Internal State ====================

/** Current bound ship */
UPROPERTY()
AActor* BoundShip;

/** Timer handle for periodic updates */
FTimerHandle UpdateTimerHandle;

/** Current shield percentage (for interpolation) */
UPROPERTY()
float CurrentShieldPct;

/** Current armor percentage (for interpolation) */
UPROPERTY()
float CurrentArmorPct;

/** Current hull percentage (for interpolation) */
UPROPERTY()
float CurrentHullPct;

/** Current capacitor percentage (for interpolation) */
UPROPERTY()
float CurrentCapacitorPct;

// ==================== Blueprint Events ====================

/**
 * Called when shield changes
 * Override in Blueprint for custom animations
 */
UFUNCTION(BlueprintImplementableEvent, Category = "Ship Status Events")
void OnShieldChanged(float NewPct, float OldPct);

/**
 * Called when armor changes
 * Override in Blueprint for custom animations
 */
UFUNCTION(BlueprintImplementableEvent, Category = "Ship Status Events")
void OnArmorChanged(float NewPct, float OldPct);

/**
 * Called when hull changes (CRITICAL!)
 * Override in Blueprint for warning animations
 */
UFUNCTION(BlueprintImplementableEvent, Category = "Ship Status Events")
void OnHullChanged(float NewPct, float OldPct);

/**
 * Called when capacitor changes
 * Override in Blueprint for pulsing effects
 */
UFUNCTION(BlueprintImplementableEvent, Category = "Ship Status Events")
void OnCapacitorChangedBP(float NewPct, float OldPct);

// ==================== Internal Functions ====================

/**
 * Periodic update function called by timer
 */
UFUNCTION()
void HandlePeriodicUpdate();

/**
 * Update progress bar with color coding
 */
void UpdateProgressBar(UProgressBar* Bar, float Percentage);

/**
 * Format HP values for display (e.g., "1.2k / 3.5k")
 */
static FString FormatHPValue(float Current, float Max);
};
