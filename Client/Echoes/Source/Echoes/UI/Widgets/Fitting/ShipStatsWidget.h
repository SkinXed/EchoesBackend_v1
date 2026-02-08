// Copyright Epic Games, Inc. All Rights Reserved.
// Ship Statistics Widget - Total ship stats display

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Core/Common/Interfaces/ShipFittingInterface.h"
#include "Core/Common/EchoesCoreTypes.h"
#include "Delegates/DelegateCombinations.h" // Добавьте этот include в начало файла
#include "ShipStatsWidget.generated.h"

class UVerticalBox;
class UProgressBar;
class UTextBlock;

/**
 * Ship Statistics Widget - Displays calculated ship stats
 * Shows DPS, EHP, resistances, speed, and other attributes
 * Updates reactively via IEquipmentObserver
 */

// Declare the multicast delegate type outside the class
DECLARE_MULTICAST_DELEGATE(FOnStatsUpdated);

UCLASS(Blueprintable, BlueprintType)
class ECHOES_API UShipStatsWidget : public UUserWidget, public IEquipmentObserver
{
    GENERATED_BODY()

public:
    UShipStatsWidget(const FObjectInitializer& ObjectInitializer);

    virtual void NativeConstruct() override;
    virtual void NativeDestruct() override;

    // ============================================================================
    // WIDGET REFERENCES
    // ============================================================================

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    UTextBlock* AlphaDPSText;

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    UTextBlock* SustainedDPSText;

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    UTextBlock* EffectiveHPText;

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    UTextBlock* MaxSpeedText;

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    UTextBlock* WarpSpeedText;

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    UTextBlock* ScanResolutionText;

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    UTextBlock* SignatureRadiusText;

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    UTextBlock* CapacitorText;

    // Resistance bars
    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    UProgressBar* EMResistanceBar;

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    UTextBlock* EMResistanceText;

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    UProgressBar* ThermalResistanceBar;

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    UTextBlock* ThermalResistanceText;

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    UProgressBar* KineticResistanceBar;

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    UTextBlock* KineticResistanceText;

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    UProgressBar* ExplosiveResistanceBar;

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    UTextBlock* ExplosiveResistanceText;

    // ============================================================================
    // CONFIGURATION
    // ============================================================================

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship Stats")
    float UpdateRate = 1.0f;

    // ============================================================================
    // CLIENT-ONLY FUNCTIONS
    // ============================================================================

    UFUNCTION(BlueprintCallable, Category = "Ship Stats")
    void ClientOnly_RefreshStats();

    UFUNCTION(BlueprintCallable, Category = "Ship Stats")
    void ClientOnly_UpdateDPSDisplay(float Alpha, float Sustained);

    UFUNCTION(BlueprintCallable, Category = "Ship Stats")
    void ClientOnly_UpdateEHPDisplay(float EHP);

    UFUNCTION(BlueprintCallable, Category = "Ship Stats")
    void ClientOnly_UpdateResistanceDisplay(ECosmosDamageType Type, float Resistance);

    UFUNCTION(BlueprintCallable, Category = "Ship Stats")
    void ClientOnly_UpdateSpeedDisplay(float MaxSpeed, float WarpSpeed);

    UFUNCTION(BlueprintCallable, Category = "Ship Stats")
    void ClientOnly_UpdateScanningDisplay(float ScanResolution, float SignatureRadius);

    // ============================================================================
    // COMMON FUNCTIONS (Calculations)
    // ============================================================================

    /**
     * Calculate total ship statistics from fitting
     * This is the core stat calculation function
     */
    UFUNCTION(BlueprintPure, Category = "Ship Stats")
    FCommon_ShipFittingData Common_CalculateTotalStats() const;

    /**
     * Calculate effective HP considering resistances
     */
    UFUNCTION(BlueprintPure, Category = "Ship Stats")
    float Common_CalculateEffectiveHP(const FCommon_ShipFittingData& FittingData) const;

    /**
     * Calculate DPS (Alpha and Sustained)
     */
    UFUNCTION(BlueprintPure, Category = "Ship Stats")
    void Common_CalculateDPS(const FCommon_ShipFittingData& FittingData, float& OutAlpha, float& OutSustained) const;

    /**
     * Get average resistance across all damage types
     */
    UFUNCTION(BlueprintPure, Category = "Ship Stats")
    float Common_GetAverageResistance(const FCosmosDefenseLayer& Layer) const;

    /**
     * Format large numbers with k/M/B suffixes
     */
    UFUNCTION(BlueprintPure, Category = "Ship Stats")
    FString Common_FormatNumber(float Value) const;

    /**
     * Get ship fitting interface
     */
    UFUNCTION(BlueprintPure, Category = "Ship Stats")
    TScriptInterface<IShipFittingInterface> Common_GetShipFittingInterface() const;

    // ============================================================================
    // IEQUIPMENT OBSERVER INTERFACE
    // ============================================================================

    // Corrected signatures to match the interface declarations
    virtual void OnEquipmentChanged_Implementation(ESlotType SlotType, int32 SlotIndex, const FCommon_ItemSlot& NewSlotData) override;
    virtual void OnFittingStatsChanged_Implementation(const FCommon_ShipFittingData& NewFittingData) override;

    // ============================================================================
    // EVENTS
    // ============================================================================

    UFUNCTION(BlueprintImplementableEvent, Category = "Ship Stats|Events")
    void OnStatsCalculated(const FCommon_ShipFittingData& Stats);

protected:
    void BindToShipEvents();
    void UnbindFromShipEvents();
    void UpdateAllDisplays();
    void UpdateResistanceBars();

    UPROPERTY()
    APlayerController* CachedPlayerController;

    UPROPERTY()
    APawn* CachedShipPawn;

    FTimerHandle UpdateTimer;
    bool bIsInitialized = false;

public:
    // Instance of the multicast delegate
    FOnStatsUpdated OnStatsUpdated;
};
