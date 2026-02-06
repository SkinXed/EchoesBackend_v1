// Copyright Epic Games, Inc. All Rights Reserved.
// Fitting Window Widget Implementation

#include "FittingWindowWidget.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Components/Border.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"

// ============================================================================
// FITTING WINDOW WIDGET
// ============================================================================

UFittingWindowWidget::UFittingWindowWidget(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
}

void UFittingWindowWidget::NativeConstruct()
{
Super::NativeConstruct();

CachedPlayerController = GetOwningPlayer();
if (CachedPlayerController)
{
CachedShipPawn = CachedPlayerController->GetPawn();
}

GenerateFittingSlots();
BindToShipEvents();
UpdateResourceBars();

bIsInitialized = true;
}

void UFittingWindowWidget::NativeDestruct()
{
Super::NativeDestruct();
}

void UFittingWindowWidget::GenerateFittingSlots()
{
if (!FittingSlotWidgetClass)
{
UE_LOG(LogTemp, Warning, TEXT("FittingWindowWidget: FittingSlotWidgetClass not set!"));
return;
}

auto FittingInterface = Common_GetShipFittingInterface();
if (!FittingInterface.GetInterface())
{
return;
}

FCommon_ShipFittingData FittingData = FittingInterface->GetFittingData();

if (HighSlotsContainer)
{
GenerateSlotsForType(ESlotType::High, HighSlotsContainer, FittingData.HighSlots);
}

if (MidSlotsContainer)
{
GenerateSlotsForType(ESlotType::Mid, MidSlotsContainer, FittingData.MidSlots);
}

if (LowSlotsContainer)
{
GenerateSlotsForType(ESlotType::Low, LowSlotsContainer, FittingData.LowSlots);
}
}

void UFittingWindowWidget::GenerateSlotsForType(ESlotType SlotType, UVerticalBox* Container, const TArray<FCommon_ItemSlot>& Slots)
{
if (!Container || !FittingSlotWidgetClass)
{
return;
}

Container->ClearChildren();
TArray<UFittingSlotWidget*> TypeSlots;

for (int32 i = 0; i < Slots.Num(); ++i)
{
UFittingSlotWidget* SlotWidget = CreateWidget<UFittingSlotWidget>(this, FittingSlotWidgetClass);
if (!SlotWidget)
{
continue;
}

SlotWidget->InitializeSlot(SlotType, i, Slots[i]);
SlotWidget->OnModuleDropped.AddDynamic(this, &UFittingWindowWidget::HandleSlotModuleDropped);
SlotWidget->OnModuleRemoved.AddDynamic(this, &UFittingWindowWidget::HandleSlotModuleRemoved);

Container->AddChild(SlotWidget);
TypeSlots.Add(SlotWidget);
}

SlotWidgets.Add(SlotType, TypeSlots);
}

void UFittingWindowWidget::HandleSlotModuleDropped(ESlotType SlotType, int32 SlotIndex, int32 ItemID)
{
if (Common_CanInstallModule(ItemID, SlotType, SlotIndex))
{
ServerRPC_InstallModule(ItemID, SlotType, SlotIndex);
}
}

void UFittingWindowWidget::HandleSlotModuleRemoved(ESlotType SlotType, int32 SlotIndex)
{
ServerRPC_UninstallModule(SlotType, SlotIndex);
}

void UFittingWindowWidget::UpdateResourceBars()
{
auto FittingInterface = Common_GetShipFittingInterface();
if (!FittingInterface.GetInterface())
{
return;
}

FCommon_ShipFittingData FittingData = FittingInterface->GetFittingData();

ClientOnly_UpdatePowergridDisplay(FittingData.PowergridUsed, FittingData.PowergridMax);
ClientOnly_UpdateCPUDisplay(FittingData.CPUUsed, FittingData.CPUMax);
}

void UFittingWindowWidget::BindToShipEvents()
{
// TODO: Bind to IEquipmentObserver when implemented
}

void UFittingWindowWidget::ClientOnly_RefreshFitting()
{
auto FittingInterface = Common_GetShipFittingInterface();
if (!FittingInterface.GetInterface())
{
return;
}

FCommon_ShipFittingData FittingData = FittingInterface->GetFittingData();

// Update all slots
auto UpdateSlotsForType = [&](ESlotType Type, const TArray<FCommon_ItemSlot>& Slots)
{
if (SlotWidgets.Contains(Type))
{
for (int32 i = 0; i < Slots.Num() && i < SlotWidgets[Type].Num(); ++i)
{
SlotWidgets[Type][i]->UpdateDisplay(Slots[i]);
}
}
};

UpdateSlotsForType(ESlotType::High, FittingData.HighSlots);
UpdateSlotsForType(ESlotType::Mid, FittingData.MidSlots);
UpdateSlotsForType(ESlotType::Low, FittingData.LowSlots);

UpdateResourceBars();
}

void UFittingWindowWidget::ClientOnly_UpdatePowergridDisplay(float Used, float Max)
{
if (PowergridBar)
{
PowergridBar->SetPercent(Max > 0.0f ? Used / Max : 0.0f);
}

if (PowergridText)
{
FText DisplayText = FText::FromString(FString::Printf(TEXT("%.1f / %.1f MW"), Used, Max));
PowergridText->SetText(DisplayText);
}
}

void UFittingWindowWidget::ClientOnly_UpdateCPUDisplay(float Used, float Max)
{
if (CPUBar)
{
CPUBar->SetPercent(Max > 0.0f ? Used / Max : 0.0f);
}

if (CPUText)
{
FText DisplayText = FText::FromString(FString::Printf(TEXT("%.1f / %.1f tf"), Used, Max));
CPUText->SetText(DisplayText);
}
}

void UFittingWindowWidget::ClientOnly_UpdateSlot(ESlotType SlotType, int32 SlotIndex, const FCommon_ItemSlot& SlotData)
{
if (SlotWidgets.Contains(SlotType) && SlotIndex >= 0 && SlotIndex < SlotWidgets[SlotType].Num())
{
SlotWidgets[SlotType][SlotIndex]->UpdateDisplay(SlotData);
}
}

void UFittingWindowWidget::ServerRPC_InstallModule(int32 ItemID, ESlotType SlotType, int32 SlotIndex)
{
UE_LOG(LogTemp, Log, TEXT("ServerRPC_InstallModule: ItemID=%d, Type=%d, Index=%d"), ItemID, (int32)SlotType, SlotIndex);
OnFittingChanged.Broadcast();
OnModuleInstalled(SlotType, SlotIndex);
}

void UFittingWindowWidget::ServerRPC_UninstallModule(ESlotType SlotType, int32 SlotIndex)
{
UE_LOG(LogTemp, Log, TEXT("ServerRPC_UninstallModule: Type=%d, Index=%d"), (int32)SlotType, SlotIndex);
OnFittingChanged.Broadcast();
OnModuleUninstalled(SlotType, SlotIndex);
}

void UFittingWindowWidget::ServerRPC_SwapModules(ESlotType FromType, int32 FromIndex, ESlotType ToType, int32 ToIndex)
{
UE_LOG(LogTemp, Log, TEXT("ServerRPC_SwapModules: From(%d,%d) To(%d,%d)"), (int32)FromType, FromIndex, (int32)ToType, ToIndex);
OnFittingChanged.Broadcast();
}

bool UFittingWindowWidget::Common_CanInstallModule(int32 ItemID, ESlotType SlotType, int32 SlotIndex) const
{
auto FittingInterface = Common_GetShipFittingInterface();
if (!FittingInterface.GetInterface())
{
return false;
}

return FittingInterface->CanInstallModule(ItemID, SlotType, SlotIndex);
}

bool UFittingWindowWidget::Common_CalculateFitting(const FCommon_ShipFittingData& FittingData, float& OutPowergrid, float& OutCPU) const
{
OutPowergrid = 0.0f;
OutCPU = 0.0f;

auto AddSlotRequirements = [&](const TArray<FCommon_ItemSlot>& Slots)
{
for (const FCommon_ItemSlot& Slot : Slots)
{
if (Slot.HasModule())
{
OutPowergrid += Slot.PowergridRequired;
OutCPU += Slot.CPURequired;
}
}
};

AddSlotRequirements(FittingData.HighSlots);
AddSlotRequirements(FittingData.MidSlots);
AddSlotRequirements(FittingData.LowSlots);

bool bFitsWithinLimits = (OutPowergrid <= FittingData.PowergridMax) && (OutCPU <= FittingData.CPUMax);
return bFitsWithinLimits;
}

TScriptInterface<IShipFittingInterface> UFittingWindowWidget::Common_GetShipFittingInterface() const
{
if (CachedShipPawn && CachedShipPawn->Implements<UShipFittingInterface>())
{
return TScriptInterface<IShipFittingInterface>(CachedShipPawn);
}
return TScriptInterface<IShipFittingInterface>();
}

// ============================================================================
// FITTING SLOT WIDGET
// ============================================================================

UFittingSlotWidget::UFittingSlotWidget(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
SlotIndex = -1;
SlotType = ESlotType::High;
}

void UFittingSlotWidget::NativeConstruct()
{
Super::NativeConstruct();
}

bool UFittingSlotWidget::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
// TODO: Implement proper drag & drop operation handling
// For now, just emit event
int32 ItemID = 12345; // Placeholder - get from drag operation
OnModuleDropped.Broadcast(SlotType, SlotIndex, ItemID);
SetHighlighted(false);
return true;
}

void UFittingSlotWidget::NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation*& OutOperation)
{
// TODO: Implement proper drag operation creation
if (SlotData.HasModule())
{
// Create drag operation for this module
SetHighlighted(true);
}
}

void UFittingSlotWidget::InitializeSlot(ESlotType InSlotType, int32 InSlotIndex, const FCommon_ItemSlot& InSlotData)
{
SlotType = InSlotType;
SlotIndex = InSlotIndex;
SlotData = InSlotData;

UpdateDisplay(InSlotData);

if (SlotNumberText)
{
FString TypePrefix;
switch (SlotType)
{
case ESlotType::High: TypePrefix = TEXT("H"); break;
case ESlotType::Mid: TypePrefix = TEXT("M"); break;
case ESlotType::Low: TypePrefix = TEXT("L"); break;
default: TypePrefix = TEXT("?"); break;
}
SlotNumberText->SetText(FText::FromString(FString::Printf(TEXT("%s%d"), *TypePrefix, InSlotIndex + 1)));
}
}

void UFittingSlotWidget::UpdateDisplay(const FCommon_ItemSlot& InSlotData)
{
SlotData = InSlotData;

if (ModuleIcon)
{
if (InSlotData.IconTexture)
{
ModuleIcon->SetBrushFromTexture(InSlotData.IconTexture);
ModuleIcon->SetVisibility(ESlateVisibility::Visible);
}
else
{
ModuleIcon->SetVisibility(ESlateVisibility::Hidden);
}
}

if (ModuleNameText)
{
if (InSlotData.HasModule())
{
ModuleNameText->SetText(FText::FromString(InSlotData.ItemName));
ModuleNameText->SetVisibility(ESlateVisibility::Visible);
}
else
{
ModuleNameText->SetText(FText::FromString(TEXT("[Empty]")));
ModuleNameText->SetVisibility(ESlateVisibility::Visible);
}
}
}

void UFittingSlotWidget::SetHighlighted(bool bHighlighted)
{
OnSlotHighlighted(bHighlighted);

if (SlotBorder)
{
FLinearColor BorderColor = bHighlighted ? FLinearColor::Yellow : FLinearColor::White;
SlotBorder->SetBrushColor(BorderColor);
}
}
