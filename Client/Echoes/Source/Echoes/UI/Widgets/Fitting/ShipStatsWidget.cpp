// Copyright Epic Games, Inc. All Rights Reserved.
// Ship Statistics Widget Implementation

#include "ShipStatsWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"
#include "TimerManager.h"
#include "Engine/World.h"

UShipStatsWidget::UShipStatsWidget(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
    UpdateRate = 1.0f;
}

void UShipStatsWidget::NativeConstruct()
{
    Super::NativeConstruct();

    CachedPlayerController = GetOwningPlayer();
    if (CachedPlayerController)
    {
        CachedShipPawn = CachedPlayerController->GetPawn();
    }

    BindToShipEvents();
    ClientOnly_RefreshStats();

    // Start update timer
    if (GetWorld() && UpdateRate > 0.0f)
    {
        GetWorld()->GetTimerManager().SetTimer(
            UpdateTimer,
            this,
            &UShipStatsWidget::ClientOnly_RefreshStats,
            1.0f / UpdateRate,
            true
        );
    }

    bIsInitialized = true;
}

void UShipStatsWidget::NativeDestruct()
{
    UnbindFromShipEvents();

    if (GetWorld())
    {
        GetWorld()->GetTimerManager().ClearTimer(UpdateTimer);
    }

    Super::NativeDestruct();
}

void UShipStatsWidget::BindToShipEvents()
{
    // Register as IEquipmentObserver with ship
    // TODO: Ship component needs to maintain list of observers
}

void UShipStatsWidget::UnbindFromShipEvents()
{
    // Unregister from ship component
}

void UShipStatsWidget::ClientOnly_RefreshStats()
{
    FCommon_ShipFittingData Stats = Common_CalculateTotalStats();

    // Update DPS
    float AlphaDPS = 0.0f, SustainedDPS = 0.0f;
    Common_CalculateDPS(Stats, AlphaDPS, SustainedDPS);
    ClientOnly_UpdateDPSDisplay(AlphaDPS, SustainedDPS);

    // Update EHP
    float EHP = Common_CalculateEffectiveHP(Stats);
    ClientOnly_UpdateEHPDisplay(EHP);

    // Update speed
    ClientOnly_UpdateSpeedDisplay(Stats.MaxSpeed, Stats.WarpSpeed);

    // Update scanning
    ClientOnly_UpdateScanningDisplay(Stats.ScanResolution, Stats.SignatureRadius);

    // Update resistances
    UpdateResistanceBars();

    // Broadcast events
    OnStatsUpdated.Broadcast();
    OnStatsCalculated(Stats);
}

void UShipStatsWidget::ClientOnly_UpdateDPSDisplay(float Alpha, float Sustained)
{
    if (AlphaDPSText)
    {
        AlphaDPSText->SetText(FText::FromString(FString::Printf(TEXT("%s"), *Common_FormatNumber(Alpha))));
    }

    if (SustainedDPSText)
    {
        SustainedDPSText->SetText(FText::FromString(FString::Printf(TEXT("%s DPS"), *Common_FormatNumber(Sustained))));
    }
}

void UShipStatsWidget::ClientOnly_UpdateEHPDisplay(float EHP)
{
    if (EffectiveHPText)
    {
        EffectiveHPText->SetText(FText::FromString(FString::Printf(TEXT("%s HP"), *Common_FormatNumber(EHP))));
    }
}

void UShipStatsWidget::ClientOnly_UpdateResistanceDisplay(ECosmosDamageType Type, float Resistance)
{
    float Percentage = Resistance * 100.0f;
    FString ResText = FString::Printf(TEXT("%.1f%%"), Percentage);

    UProgressBar* Bar = nullptr;
    UTextBlock* Text = nullptr;

    switch (Type)
    {
    case ECosmosDamageType::EM:
        Bar = EMResistanceBar;
        Text = EMResistanceText;
        break;
    case ECosmosDamageType::Thermal:
        Bar = ThermalResistanceBar;
        Text = ThermalResistanceText;
        break;
    case ECosmosDamageType::Kinetic:
        Bar = KineticResistanceBar;
        Text = KineticResistanceText;
        break;
    case ECosmosDamageType::Explosive:
        Bar = ExplosiveResistanceBar;
        Text = ExplosiveResistanceText;
        break;
    default:
        break;
    }

    if (Bar)
    {
        Bar->SetPercent(Resistance);
    }

    if (Text)
    {
        Text->SetText(FText::FromString(ResText));
    }
}

void UShipStatsWidget::ClientOnly_UpdateSpeedDisplay(float MaxSpeed, float WarpSpeed)
{
    if (MaxSpeedText)
    {
        MaxSpeedText->SetText(FText::FromString(FString::Printf(TEXT("%.1f m/s"), MaxSpeed)));
    }

    if (WarpSpeedText)
    {
        WarpSpeedText->SetText(FText::FromString(FString::Printf(TEXT("%.1f AU/s"), WarpSpeed)));
    }
}

void UShipStatsWidget::ClientOnly_UpdateScanningDisplay(float ScanResolution, float SignatureRadius)
{
    if (ScanResolutionText)
    {
        ScanResolutionText->SetText(FText::FromString(FString::Printf(TEXT("%.0f mm"), ScanResolution)));
    }

    if (SignatureRadiusText)
    {
        SignatureRadiusText->SetText(FText::FromString(FString::Printf(TEXT("%.0f m"), SignatureRadius)));
    }
}

void UShipStatsWidget::UpdateResistanceBars()
{
    auto FittingInterface = Common_GetShipFittingInterface();
    if (!FittingInterface.GetInterface())
    {
        return;
    }

    FCommon_ShipFittingData Stats = FittingInterface->GetFittingData();

    // If Shield/Armor/Structure layers exist use them
    float AvgEM = (Stats.ShieldLayer.ResistEM + Stats.ArmorLayer.ResistEM + Stats.StructureLayer.ResistEM) / 3.0f;
    float AvgThermal = (Stats.ShieldLayer.ResistThermal + Stats.ArmorLayer.ResistThermal + Stats.StructureLayer.ResistThermal) / 3.0f;
    float AvgKinetic = (Stats.ShieldLayer.ResistKinetic + Stats.ArmorLayer.ResistKinetic + Stats.StructureLayer.ResistKinetic) / 3.0f;
    float AvgExplosive = (Stats.ShieldLayer.ResistExplosive + Stats.ArmorLayer.ResistExplosive + Stats.StructureLayer.ResistExplosive) / 3.0f;

    ClientOnly_UpdateResistanceDisplay(ECosmosDamageType::EM, AvgEM);
    ClientOnly_UpdateResistanceDisplay(ECosmosDamageType::Thermal, AvgThermal);
    ClientOnly_UpdateResistanceDisplay(ECosmosDamageType::Kinetic, AvgKinetic);
    ClientOnly_UpdateResistanceDisplay(ECosmosDamageType::Explosive, AvgExplosive);
}

FCommon_ShipFittingData UShipStatsWidget::Common_CalculateTotalStats() const
{
    auto FittingInterface = Common_GetShipFittingInterface();
    if (!FittingInterface.GetInterface())
    {
        return FCommon_ShipFittingData();
    }

    // Get base stats from ship
    FCommon_ShipFittingData Stats = FittingInterface->GetFittingData();

    // In real implementation:
    // 1. Start with base hull stats
    // 2. Apply bonuses from all fitted modules
    // 3. Apply skill bonuses
    // 4. Apply active effect bonuses

    // For now, just return the fitting data as-is
    // Server calculates actual stats and replicates them
    return Stats;
}

float UShipStatsWidget::Common_CalculateEffectiveHP(const FCommon_ShipFittingData& FittingData) const
{
    // Calculate EHP considering resistances
    // EHP = RawHP / (1 - AvgResistance)

    float TotalRawHP = FittingData.ShieldLayer.Max + FittingData.ArmorLayer.Max + FittingData.StructureLayer.Max;

    // Calculate average resistance across all damage types and layers
    float AvgResist = (
        Common_GetAverageResistance(FittingData.ShieldLayer) * (FittingData.ShieldLayer.Max / TotalRawHP) +
        Common_GetAverageResistance(FittingData.ArmorLayer) * (FittingData.ArmorLayer.Max / TotalRawHP) +
        Common_GetAverageResistance(FittingData.StructureLayer) * (FittingData.StructureLayer.Max / TotalRawHP)
    );

    float EHP = TotalRawHP / FMath::Max(1.0f - AvgResist, 0.01f);
    return EHP;
}

void UShipStatsWidget::Common_CalculateDPS(const FCommon_ShipFittingData& FittingData, float& OutAlpha, float& OutSustained) const
{
    // Alpha = instant damage from all weapons
    // Sustained = DPS over time considering reload

    OutAlpha = FittingData.AlphaStrike;
    OutSustained = FittingData.TotalDPS;

    // In real implementation:
    // Iterate through high slots
    // For each weapon module:
    //   Alpha += weapon damage
    //   Sustained += weapon damage / (weapon cycle time + reload time)
}

float UShipStatsWidget::Common_GetAverageResistance(const FCosmosDefenseLayer& Layer) const
{
    return (Layer.ResistEM + Layer.ResistThermal + Layer.ResistKinetic + Layer.ResistExplosive) / 4.0f;
}

FString UShipStatsWidget::Common_FormatNumber(float Value) const
{
    if (Value >= 1000000000.0f)
    {
        return FString::Printf(TEXT("%.2fB"), Value / 1000000000.0f);
    }
    else if (Value >= 1000000.0f)
    {
        return FString::Printf(TEXT("%.2fM"), Value / 1000000.0f);
    }
    else if (Value >= 1000.0f)
    {
        return FString::Printf(TEXT("%.1fk"), Value / 1000.0f);
    }
    else
    {
        return FString::Printf(TEXT("%.0f"), Value);
    }
}

TScriptInterface<IShipFittingInterface> UShipStatsWidget::Common_GetShipFittingInterface() const
{
    if (CachedShipPawn && CachedShipPawn->Implements<UShipFittingInterface>())
    {
        return TScriptInterface<IShipFittingInterface>(CachedShipPawn);
    }
    return TScriptInterface<IShipFittingInterface>();
}

// Updated signatures to match interface
void UShipStatsWidget::OnEquipmentChanged_Implementation(ESlotType SlotType, int32 SlotIndex, const FCommon_ItemSlot& NewSlotData)
{
    // Called when equipment changes
    ClientOnly_RefreshStats();
}

void UShipStatsWidget::OnFittingStatsChanged_Implementation(const FCommon_ShipFittingData& NewFittingData)
{
    // Called when fitting stats are recalculated
    ClientOnly_RefreshStats();
}
