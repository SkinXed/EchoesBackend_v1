// Copyright Epic Games, Inc. All Rights Reserved.

#include "TargetPanelWidget.h"
#include "Components/VerticalBox.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "Components/CircularThrobber.h"
#include "GameFramework/Actor.h"

// ==================== UTargetItemWidget ====================

void UTargetItemWidget::SetTargetData(const FTargetPanelData& InTargetData)
{
ETargetLockState PreviousState = TargetData.LockState;
float PreviousProgress = TargetData.LockProgress;

TargetData = InTargetData;

// Update widget components
if (TargetNameText)
{
TargetNameText->SetText(FText::FromString(TargetData.TargetName));
}

if (DistanceText)
{
// Format distance (using existing Common_FormatDistance from OverviewWidget)
float Meters = TargetData.Distance / 100.0f;
FString DistanceStr;
if (Meters < 1000.0f)
{
DistanceStr = FString::Printf(TEXT("%.0f m"), Meters);
}
else
{
DistanceStr = FString::Printf(TEXT("%.1f km"), Meters / 1000.0f);
}
DistanceText->SetText(FText::FromString(DistanceStr));
}

// Update progress bars
if (ShieldBar)
{
ShieldBar->SetPercent(TargetData.ShieldPct);
}
if (ArmorBar)
{
ArmorBar->SetPercent(TargetData.ArmorPct);
}
if (HullBar)
{
HullBar->SetPercent(TargetData.HullPct);
}

// Update text displays
if (ShieldText)
{
ShieldText->SetText(FText::AsPercent(TargetData.ShieldPct));
}
if (ArmorText)
{
ArmorText->SetText(FText::AsPercent(TargetData.ArmorPct));
}
if (HullText)
{
HullText->SetText(FText::AsPercent(TargetData.HullPct));
}

// Call Blueprint event
UpdateDisplay();

// Fire specific events if changed
if (TargetData.LockProgress != PreviousProgress)
{
OnLockProgressChanged(TargetData.LockProgress);
}

if (TargetData.LockState != PreviousState)
{
OnLockStateChanged(TargetData.LockState);
}
}

// ==================== UTargetPanelWidget ====================

UTargetPanelWidget::UTargetPanelWidget(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
, MaxDisplayedTargets(5)
, BoundTargetingComponent(nullptr)
{
}

void UTargetPanelWidget::NativeConstruct()
{
Super::NativeConstruct();

UpdateHeaderText();
}

void UTargetPanelWidget::NativeDestruct()
{
UnbindFromTargetingComponent();

Super::NativeDestruct();
}

void UTargetPanelWidget::BindToTargetingComponent(UTargetingComponent* TargetingComp)
{
if (!TargetingComp)
{
return;
}

// Unbind from previous component
UnbindFromTargetingComponent();

BoundTargetingComponent = TargetingComp;

// Bind to events
TargetingComp->OnLockStarted.AddDynamic(this, &UTargetPanelWidget::HandleLockStarted);
TargetingComp->OnLockCompleted.AddDynamic(this, &UTargetPanelWidget::HandleLockCompleted);
TargetingComp->OnLockLost.AddDynamic(this, &UTargetPanelWidget::HandleLockLost);
TargetingComp->OnLockProgress.AddDynamic(this, &UTargetPanelWidget::HandleLockProgress);
}

void UTargetPanelWidget::UnbindFromTargetingComponent()
{
if (BoundTargetingComponent)
{
BoundTargetingComponent->OnLockStarted.RemoveDynamic(this, &UTargetPanelWidget::HandleLockStarted);
BoundTargetingComponent->OnLockCompleted.RemoveDynamic(this, &UTargetPanelWidget::HandleLockCompleted);
BoundTargetingComponent->OnLockLost.RemoveDynamic(this, &UTargetPanelWidget::HandleLockLost);
BoundTargetingComponent->OnLockProgress.RemoveDynamic(this, &UTargetPanelWidget::HandleLockProgress);

BoundTargetingComponent = nullptr;
}
}

void UTargetPanelWidget::ClientOnly_AddTarget(const FTargetPanelData& TargetData)
{
if (!TargetContainer || !TargetData.TargetActor)
{
return;
}

// Check if already exists
if (TargetWidgets.Contains(TargetData.TargetActor))
{
ClientOnly_UpdateTarget(TargetData.TargetActor, TargetData);
return;
}

// Check max targets
if (MaxDisplayedTargets > 0 && TargetWidgets.Num() >= MaxDisplayedTargets)
{
UE_LOG(LogTemp, Warning, TEXT("Target panel full, cannot add more targets"));
return;
}

// Create widget
if (!TargetItemWidgetClass)
{
UE_LOG(LogTemp, Error, TEXT("TargetItemWidgetClass not set!"));
return;
}

UTargetItemWidget* NewWidget = CreateWidget<UTargetItemWidget>(this, TargetItemWidgetClass);
if (NewWidget)
{
NewWidget->SetTargetData(TargetData);
TargetContainer->AddChild(NewWidget);
TargetWidgets.Add(TargetData.TargetActor, NewWidget);

UpdateHeaderText();
}
}

void UTargetPanelWidget::ClientOnly_RemoveTarget(AActor* Target)
{
if (!Target || !TargetContainer)
{
return;
}

if (UTargetItemWidget** FoundWidget = TargetWidgets.Find(Target))
{
(*FoundWidget)->RemoveFromParent();
TargetWidgets.Remove(Target);

UpdateHeaderText();
}
}

void UTargetPanelWidget::ClientOnly_UpdateTarget(AActor* Target, const FTargetPanelData& NewData)
{
if (!Target)
{
return;
}

if (UTargetItemWidget** FoundWidget = TargetWidgets.Find(Target))
{
(*FoundWidget)->SetTargetData(NewData);

// Broadcast event
OnTargetStateChanged.Broadcast(Target, NewData);
}
}

void UTargetPanelWidget::ClearAllTargets()
{
if (TargetContainer)
{
TargetContainer->ClearChildren();
}

TargetWidgets.Empty();
UpdateHeaderText();
}

UTargetItemWidget* UTargetPanelWidget::GetTargetItemWidget(AActor* Target) const
{
if (const UTargetItemWidget* const* FoundWidget = TargetWidgets.Find(Target))
{
return *FoundWidget;
}
return nullptr;
}

void UTargetPanelWidget::HandleLockStarted(AActor* Target)
{
FTargetPanelData TargetData = QueryTargetData(Target, 0.0f, ETargetLockState::Locking);
ClientOnly_AddTarget(TargetData);
}

void UTargetPanelWidget::HandleLockCompleted(AActor* Target)
{
FTargetPanelData TargetData = QueryTargetData(Target, 1.0f, ETargetLockState::Locked);
ClientOnly_UpdateTarget(Target, TargetData);
}

void UTargetPanelWidget::HandleLockLost(AActor* Target)
{
ClientOnly_RemoveTarget(Target);
}

void UTargetPanelWidget::HandleLockProgress(AActor* Target, float Progress)
{
FTargetPanelData TargetData = QueryTargetData(Target, Progress, ETargetLockState::Locking);
ClientOnly_UpdateTarget(Target, TargetData);
}

void UTargetPanelWidget::UpdateHeaderText()
{
if (HeaderText)
{
int32 TargetCount = TargetWidgets.Num();
FString HeaderString = FString::Printf(TEXT("Targets (%d/%d)"), TargetCount, MaxDisplayedTargets);
HeaderText->SetText(FText::FromString(HeaderString));
}
}

FTargetPanelData UTargetPanelWidget::QueryTargetData(AActor* Target, float LockProgress, ETargetLockState LockState) const
{
FTargetPanelData Data;
Data.TargetActor = Target;
Data.LockProgress = LockProgress;
Data.LockState = LockState;

if (!Target)
{
return Data;
}

// Get target name
Data.TargetName = Target->GetName();

// Get distance
if (APlayerController* PC = GetOwningPlayer())
{
if (APawn* PlayerPawn = PC->GetPawn())
{
Data.Distance = FVector::Dist(PlayerPawn->GetActorLocation(), Target->GetActorLocation());
}
}

// Try to get health data via IShipStateInterface
if (Target->Implements<UShipStateInterface>())
{
IShipStateInterface* ShipState = Cast<IShipStateInterface>(Target);
if (ShipState)
{
FCommon_ShipDataStruct ShipData = ShipState->Execute_GetShipData(Target);
Data.ShieldPct = ShipData.GetShieldPercentage();
Data.ArmorPct = ShipData.GetArmorPercentage();
Data.HullPct = ShipData.GetStructurePercentage();
}
}

return Data;
}
