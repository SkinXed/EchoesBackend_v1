// Copyright Epic Games, Inc. All Rights Reserved.

#include "ShipStatusWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "GameFramework/Actor.h"
#include "TimerManager.h"

UShipStatusWidget::UShipStatusWidget(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
, BoundShip(nullptr)
, UpdateInterval(0.1f) // 10 Hz updates
, bEnableAnimations(true)
, AnimationSpeed(5.0f)
, CurrentShieldPct(1.0f)
, CurrentArmorPct(1.0f)
, CurrentHullPct(1.0f)
, CurrentCapacitorPct(1.0f)
{
}

void UShipStatusWidget::NativeConstruct()
{
Super::NativeConstruct();

// Start periodic update timer
if (UWorld* World = GetWorld())
{
World->GetTimerManager().SetTimer(
UpdateTimerHandle,
this,
&UShipStatusWidget::HandlePeriodicUpdate,
UpdateInterval,
true // Loop
);
}
}

void UShipStatusWidget::NativeDestruct()
{
UnbindFromShip();

// Clear timer
if (UWorld* World = GetWorld())
{
World->GetTimerManager().ClearTimer(UpdateTimerHandle);
}

Super::NativeDestruct();
}

void UShipStatusWidget::OnShipStatsChanged_Implementation(float ShieldPct, float ArmorPct, float HullPct)
{
ClientOnly_UpdateShield(ShieldPct, 0.0f, 0.0f);
ClientOnly_UpdateArmor(ArmorPct, 0.0f, 0.0f);
ClientOnly_UpdateHull(HullPct, 0.0f, 0.0f);
}

void UShipStatusWidget::OnCapacitorChanged_Implementation(float CapacitorPct)
{
ClientOnly_UpdateCapacitor(CapacitorPct, 0.0f, 0.0f);
}

void UShipStatusWidget::BindToShip(AActor* Ship)
{
if (!Ship)
{
return;
}

UnbindFromShip();

BoundShip = Ship;

// Initial refresh
ClientOnly_RefreshAllDisplays();
}

void UShipStatusWidget::UnbindFromShip()
{
BoundShip = nullptr;
}

void UShipStatusWidget::ClientOnly_UpdateShield(float ShieldPct, float ShieldCurrent, float ShieldMax)
{
float OldPct = CurrentShieldPct;
CurrentShieldPct = FMath::Clamp(ShieldPct, 0.0f, 1.0f);

// Update progress bar
if (ShieldBar)
{
UpdateProgressBar(ShieldBar, CurrentShieldPct);
}

// Update text
if (ShieldText)
{
if (ShieldMax > 0.0f)
{
FString Text = FormatHPValue(ShieldCurrent, ShieldMax);
ShieldText->SetText(FText::FromString(Text));
}
else
{
ShieldText->SetText(FText::AsPercent(CurrentShieldPct));
}
}

// Call Blueprint event
if (FMath::Abs(CurrentShieldPct - OldPct) > 0.01f)
{
OnShieldChanged(CurrentShieldPct, OldPct);
}
}

void UShipStatusWidget::ClientOnly_UpdateArmor(float ArmorPct, float ArmorCurrent, float ArmorMax)
{
float OldPct = CurrentArmorPct;
CurrentArmorPct = FMath::Clamp(ArmorPct, 0.0f, 1.0f);

if (ArmorBar)
{
UpdateProgressBar(ArmorBar, CurrentArmorPct);
}

if (ArmorText)
{
if (ArmorMax > 0.0f)
{
FString Text = FormatHPValue(ArmorCurrent, ArmorMax);
ArmorText->SetText(FText::FromString(Text));
}
else
{
ArmorText->SetText(FText::AsPercent(CurrentArmorPct));
}
}

if (FMath::Abs(CurrentArmorPct - OldPct) > 0.01f)
{
OnArmorChanged(CurrentArmorPct, OldPct);
}
}

void UShipStatusWidget::ClientOnly_UpdateHull(float HullPct, float HullCurrent, float HullMax)
{
float OldPct = CurrentHullPct;
CurrentHullPct = FMath::Clamp(HullPct, 0.0f, 1.0f);

if (HullBar)
{
UpdateProgressBar(HullBar, CurrentHullPct);
}

if (HullText)
{
if (HullMax > 0.0f)
{
FString Text = FormatHPValue(HullCurrent, HullMax);
HullText->SetText(FText::FromString(Text));
}
else
{
HullText->SetText(FText::AsPercent(CurrentHullPct));
}
}

if (FMath::Abs(CurrentHullPct - OldPct) > 0.01f)
{
OnHullChanged(CurrentHullPct, OldPct);
}
}

void UShipStatusWidget::ClientOnly_UpdateCapacitor(float CapacitorPct, float CapacitorCurrent, float CapacitorMax)
{
float OldPct = CurrentCapacitorPct;
CurrentCapacitorPct = FMath::Clamp(CapacitorPct, 0.0f, 1.0f);

if (CapacitorBar)
{
CapacitorBar->SetPercent(CurrentCapacitorPct);
// Capacitor is always blue/cyan
CapacitorBar->SetFillColorAndOpacity(FLinearColor(0.0f, 0.7f, 1.0f, 1.0f));
}

if (CapacitorText)
{
if (CapacitorMax > 0.0f)
{
FString Text = FormatHPValue(CapacitorCurrent, CapacitorMax);
CapacitorText->SetText(FText::FromString(Text));
}
else
{
CapacitorText->SetText(FText::AsPercent(CurrentCapacitorPct));
}
}

if (FMath::Abs(CurrentCapacitorPct - OldPct) > 0.01f)
{
OnCapacitorChangedBP(CurrentCapacitorPct, OldPct);
}
}

void UShipStatusWidget::ClientOnly_RefreshAllDisplays()
{
if (!BoundShip)
{
return;
}

// Check if ship implements IShipStateInterface
if (BoundShip->Implements<UShipStateInterface>())
{
IShipStateInterface* ShipState = Cast<IShipStateInterface>(BoundShip);
if (ShipState)
{
FCommon_ShipDataStruct ShipData = ShipState->Execute_GetShipData(BoundShip);

// Update all displays
ClientOnly_UpdateShield(ShipData.GetShieldPercentage(), ShipData.ShieldCurrent, ShipData.ShieldMax);
ClientOnly_UpdateArmor(ShipData.GetArmorPercentage(), ShipData.ArmorCurrent, ShipData.ArmorMax);
ClientOnly_UpdateHull(ShipData.GetStructurePercentage(), ShipData.StructureCurrent, ShipData.StructureMax);
ClientOnly_UpdateCapacitor(ShipData.GetCapacitorPercentage(), ShipData.CapacitorCurrent, ShipData.CapacitorMax);
}
}
}

FLinearColor UShipStatusWidget::Common_GetHealthColor(float Percentage)
{
if (Percentage > 0.66f)
{
// Green (healthy)
return FLinearColor(0.0f, 1.0f, 0.0f, 1.0f);
}
else if (Percentage > 0.33f)
{
// Yellow (warning)
return FLinearColor(1.0f, 1.0f, 0.0f, 1.0f);
}
else
{
// Red (critical)
return FLinearColor(1.0f, 0.0f, 0.0f, 1.0f);
}
}

void UShipStatusWidget::HandlePeriodicUpdate()
{
ClientOnly_RefreshAllDisplays();
}

void UShipStatusWidget::UpdateProgressBar(UProgressBar* Bar, float Percentage)
{
if (!Bar)
{
return;
}

Bar->SetPercent(Percentage);

// Set color based on health
FLinearColor Color = Common_GetHealthColor(Percentage);
Bar->SetFillColorAndOpacity(Color);
}

FString UShipStatusWidget::FormatHPValue(float Current, float Max)
{
// Format large numbers with k/M suffix
auto FormatNumber = [](float Value) -> FString
{
if (Value >= 1000000.0f)
{
return FString::Printf(TEXT("%.1fM"), Value / 1000000.0f);
}
else if (Value >= 1000.0f)
{
return FString::Printf(TEXT("%.1fk"), Value / 1000.0f);
}
else
{
return FString::Printf(TEXT("%.0f"), Value);
}
};

return FString::Printf(TEXT("%s / %s"), *FormatNumber(Current), *FormatNumber(Max));
}
