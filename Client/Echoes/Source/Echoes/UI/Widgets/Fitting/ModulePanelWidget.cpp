// Copyright Epic Games, Inc. All Rights Reserved.
// Echoes - EVE-like MMO
// Module Panel Widget Implementation

#include "ModulePanelWidget.h"
#include "Components/UniformGridPanel.h"
#include "Components/UniformGridSlot.h"
#include "Components/Image.h"
#include "Components/ProgressBar.h"
#include "Components/Border.h"
#include "Components/TextBlock.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"
#include "TimerManager.h"
#include "Engine/World.h"

// ============================================================================
// MODULE PANEL WIDGET
// ============================================================================

UModulePanelWidget::UModulePanelWidget(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
GridColumns = 4;
CooldownUpdateRate = 10.0f;
}

void UModulePanelWidget::NativeConstruct()
{
Super::NativeConstruct();

// Cache references
CachedPlayerController = GetOwningPlayer();
if (CachedPlayerController)
{
CachedShipPawn = CachedPlayerController->GetPawn();
}

// Generate module slots
GenerateModuleSlots();

// Bind to ship events
BindToShipEvents();

// Start cooldown update timer
if (GetWorld())
{
float UpdateInterval = 1.0f / FMath::Max(CooldownUpdateRate, 1.0f);
GetWorld()->GetTimerManager().SetTimer(
CooldownUpdateTimer,
this,
&UModulePanelWidget::UpdateAllCooldowns,
UpdateInterval,
true
);
}

bIsInitialized = true;
}

void UModulePanelWidget::NativeDestruct()
{
UnbindFromShipEvents();

if (GetWorld())
{
GetWorld()->GetTimerManager().ClearTimer(CooldownUpdateTimer);
}

Super::NativeDestruct();
}

void UModulePanelWidget::GenerateModuleSlots()
{
if (!ModuleSlotWidgetClass)
{
UE_LOG(LogTemp, Warning, TEXT("ModulePanelWidget: ModuleSlotWidgetClass not set!"));
return;
}

// Get fitting data
auto FittingInterface = Common_GetShipFittingInterface();
if (!FittingInterface.GetInterface())
{
return;
}

FCommon_ShipFittingData FittingData = FittingInterface->GetFittingData();

// Generate High slots
if (HighSlotsGrid)
{
GenerateSlotsForType(ESlotType::High, HighSlotsGrid, FittingData.HighSlots);
}

// Generate Mid slots
if (MidSlotsGrid)
{
GenerateSlotsForType(ESlotType::Mid, MidSlotsGrid, FittingData.MidSlots);
}

// Generate Low slots
if (LowSlotsGrid)
{
GenerateSlotsForType(ESlotType::Low, LowSlotsGrid, FittingData.LowSlots);
}
}

void UModulePanelWidget::GenerateSlotsForType(ESlotType SlotType, UUniformGridPanel* GridPanel, const TArray<FCommon_ItemSlot>& Slots)
{
if (!GridPanel || !ModuleSlotWidgetClass)
{
return;
}

// Clear existing widgets
GridPanel->ClearChildren();

TArray<UModuleSlotWidget*> TypeSlots;

for (int32 i = 0; i < Slots.Num(); ++i)
{
// Create slot widget
UModuleSlotWidget* SlotWidget = CreateWidget<UModuleSlotWidget>(this, ModuleSlotWidgetClass);
if (!SlotWidget)
{
continue;
}

// Initialize slot
SlotWidget->InitializeSlot(SlotType, i, Slots[i]);

// Bind click event
SlotWidget->OnSlotClicked.AddDynamic(this, &UModulePanelWidget::HandleSlotClicked);

// Add to grid
int32 Row = i / GridColumns;
int32 Column = i % GridColumns;
UUniformGridSlot* GridSlot = GridPanel->AddChildToUniformGrid(SlotWidget, Row, Column);

// Store reference
TypeSlots.Add(SlotWidget);
}

SlotWidgets.Add(SlotType, TypeSlots);
}

void UModulePanelWidget::HandleSlotClicked(ESlotType SlotType, int32 SlotIndex)
{
// Toggle module activation
ServerRPC_ToggleModule(SlotType, SlotIndex);
}

void UModulePanelWidget::ClientOnly_UpdateCooldown(ESlotType SlotType, int32 SlotIndex, float CooldownRemaining, float CooldownTotal)
{
UModuleSlotWidget* SlotWidget = Common_GetSlotWidget(SlotType, SlotIndex);
if (SlotWidget && CooldownTotal > 0.0f)
{
float Progress = 1.0f - (CooldownRemaining / CooldownTotal);
SlotWidget->UpdateCooldown(Progress);
}
}

void UModulePanelWidget::ClientOnly_UpdateModuleState(ESlotType SlotType, int32 SlotIndex, EModuleState NewState)
{
UModuleSlotWidget* SlotWidget = Common_GetSlotWidget(SlotType, SlotIndex);
if (SlotWidget)
{
SlotWidget->UpdateState(NewState);
OnModuleStateChanged(SlotType, SlotIndex, NewState);
}
}

void UModulePanelWidget::ClientOnly_RefreshAllModules()
{
auto FittingInterface = Common_GetShipFittingInterface();
if (!FittingInterface.GetInterface())
{
return;
}

FCommon_ShipFittingData FittingData = FittingInterface->GetFittingData();

// Update High slots
if (SlotWidgets.Contains(ESlotType::High))
{
for (int32 i = 0; i < FittingData.HighSlots.Num(); ++i)
{
if (i < SlotWidgets[ESlotType::High].Num())
{
SlotWidgets[ESlotType::High][i]->UpdateDisplay(FittingData.HighSlots[i]);
}
}
}

// Update Mid slots
if (SlotWidgets.Contains(ESlotType::Mid))
{
for (int32 i = 0; i < FittingData.MidSlots.Num(); ++i)
{
if (i < SlotWidgets[ESlotType::Mid].Num())
{
SlotWidgets[ESlotType::Mid][i]->UpdateDisplay(FittingData.MidSlots[i]);
}
}
}

// Update Low slots
if (SlotWidgets.Contains(ESlotType::Low))
{
for (int32 i = 0; i < FittingData.LowSlots.Num(); ++i)
{
if (i < SlotWidgets[ESlotType::Low].Num())
{
SlotWidgets[ESlotType::Low][i]->UpdateDisplay(FittingData.LowSlots[i]);
}
}
}
}

void UModulePanelWidget::ClientOnly_UpdateSlot(const FCommon_ItemSlot& SlotData)
{
UModuleSlotWidget* SlotWidget = Common_GetSlotWidget(SlotData.SlotType, SlotData.SlotIndex);
if (SlotWidget)
{
SlotWidget->UpdateDisplay(SlotData);
}
}

void UModulePanelWidget::ServerRPC_ToggleModule(ESlotType SlotType, int32 SlotIndex)
{
// In real implementation, this would be a Server RPC
// For now, just log the action
UE_LOG(LogTemp, Log, TEXT("ServerRPC_ToggleModule: Type=%d, Index=%d"), (int32)SlotType, SlotIndex);

// Broadcast event
OnModuleToggled.Broadcast();
}

void UModulePanelWidget::ServerRPC_DeactivateAll()
{
UE_LOG(LogTemp, Log, TEXT("ServerRPC_DeactivateAll called"));
}

void UModulePanelWidget::UpdateAllCooldowns()
{
auto FittingInterface = Common_GetShipFittingInterface();
if (!FittingInterface.GetInterface())
{
return;
}

FCommon_ShipFittingData FittingData = FittingInterface->GetFittingData();

// Update cooldowns for all slot types
auto UpdateSlotsForType = [&](ESlotType Type, const TArray<FCommon_ItemSlot>& Slots)
{
for (int32 i = 0; i < Slots.Num(); ++i)
{
if (Slots[i].Cooldown > 0.0f)
{
ClientOnly_UpdateCooldown(Type, i, Slots[i].Cooldown, Slots[i].Cooldown + 1.0f);
}
}
};

UpdateSlotsForType(ESlotType::High, FittingData.HighSlots);
UpdateSlotsForType(ESlotType::Mid, FittingData.MidSlots);
UpdateSlotsForType(ESlotType::Low, FittingData.LowSlots);
}

void UModulePanelWidget::BindToShipEvents()
{
// TODO: Bind to IEquipmentObserver events when ship component implements it
}

void UModulePanelWidget::UnbindFromShipEvents()
{
// TODO: Unbind from IEquipmentObserver events
}

UModuleSlotWidget* UModulePanelWidget::Common_GetSlotWidget(ESlotType SlotType, int32 SlotIndex) const
{
if (SlotWidgets.Contains(SlotType))
{
const TArray<UModuleSlotWidget*>& TypeSlots = SlotWidgets[SlotType];
if (SlotIndex >= 0 && SlotIndex < TypeSlots.Num())
{
return TypeSlots[SlotIndex];
}
}
return nullptr;
}

bool UModulePanelWidget::Common_HasActiveModules() const
{
for (const auto& Pair : SlotWidgets)
{
for (UModuleSlotWidget* SlotWidget : Pair.Value)
{
if (SlotWidget && SlotWidget->CurrentState == EModuleState::Active)
{
return true;
}
}
}
return false;
}

TScriptInterface<IShipFittingInterface> UModulePanelWidget::Common_GetShipFittingInterface() const
{
if (CachedShipPawn && CachedShipPawn->Implements<UShipFittingInterface>())
{
return TScriptInterface<IShipFittingInterface>(CachedShipPawn);
}
return TScriptInterface<IShipFittingInterface>();
}

// ============================================================================
// MODULE SLOT WIDGET
// ============================================================================

UModuleSlotWidget::UModuleSlotWidget(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
CurrentState = EModuleState::Offline;
SlotIndex = -1;
SlotType = ESlotType::High;
}

void UModuleSlotWidget::NativeConstruct()
{
Super::NativeConstruct();

ApplyStateVisual();
}

FReply UModuleSlotWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
if (InMouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton))
{
OnSlotClicked.Broadcast(SlotType, SlotIndex);
OnSlotClickedEvent();
return FReply::Handled();
}

return Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);
}

void UModuleSlotWidget::InitializeSlot(ESlotType InSlotType, int32 InSlotIndex, const FCommon_ItemSlot& InSlotData)
{
SlotType = InSlotType;
SlotIndex = InSlotIndex;
SlotData = InSlotData;

UpdateDisplay(InSlotData);

// Set slot number
if (SlotNumberText)
{
SlotNumberText->SetText(FText::AsNumber(InSlotIndex + 1));
}
}

void UModuleSlotWidget::UpdateDisplay(const FCommon_ItemSlot& InSlotData)
{
SlotData = InSlotData;

// Update icon
if (ModuleIcon && InSlotData.IconTexture)
{
ModuleIcon->SetBrushFromTexture(InSlotData.IconTexture);
ModuleIcon->SetVisibility(ESlateVisibility::Visible);
}
else if (ModuleIcon)
{
ModuleIcon->SetVisibility(ESlateVisibility::Hidden);
}

// Update state
UpdateState(InSlotData.ModuleState);
}

void UModuleSlotWidget::UpdateCooldown(float Progress)
{
if (CooldownOverlay)
{
CooldownOverlay->SetPercent(Progress);
CooldownOverlay->SetVisibility(Progress > 0.0f && Progress < 1.0f ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
}
}

void UModuleSlotWidget::UpdateState(EModuleState NewState)
{
CurrentState = NewState;
ApplyStateVisual();
}

void UModuleSlotWidget::ApplyStateVisual()
{
if (!StateBorder)
{
return;
}

FLinearColor BorderColor;
switch (CurrentState)
{
case EModuleState::Active:
BorderColor = ActiveColor;
break;
case EModuleState::Overload:
BorderColor = OverloadColor;
break;
case EModuleState::Offline:
default:
BorderColor = OfflineColor;
break;
}

StateBorder->SetBrushColor(BorderColor);
}
