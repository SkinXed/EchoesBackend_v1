// Copyright Epic Games, Inc. All Rights Reserved.
// Echoes - EVE-like MMO
// Fitting Window Widget - Equipment management in hangar

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Core/Common/Interfaces/ShipFittingInterface.h"
#include "FittingWindowWidget.generated.h"

class UVerticalBox;
class UHorizontalBox;
class UFittingSlotWidget;
class UProgressBar;
class UTextBlock;

/**
 * Fitting Window Widget - Ship equipment management in hangar
 * Allows drag & drop installation of modules
 * Validates powergrid and CPU requirements
 */
UCLASS(Blueprintable, BlueprintType)
class ECHOES_API UFittingWindowWidget : public UUserWidget
{
GENERATED_BODY()

public:
UFittingWindowWidget(const FObjectInitializer& ObjectInitializer);

virtual void NativeConstruct() override;
virtual void NativeDestruct() override;

// ============================================================================
// WIDGET REFERENCES
// ============================================================================

UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
UVerticalBox* HighSlotsContainer;

UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
UVerticalBox* MidSlotsContainer;

UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
UVerticalBox* LowSlotsContainer;

UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
UProgressBar* PowergridBar;

UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
UTextBlock* PowergridText;

UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
UProgressBar* CPUBar;

UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
UTextBlock* CPUText;

// ============================================================================
// CONFIGURATION
// ============================================================================

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fitting Window")
TSubclassOf<UFittingSlotWidget> FittingSlotWidgetClass;

// ============================================================================
// CLIENT-ONLY FUNCTIONS
// ============================================================================

UFUNCTION(BlueprintCallable, Category = "Fitting Window")
void ClientOnly_RefreshFitting();

UFUNCTION(BlueprintCallable, Category = "Fitting Window")
void ClientOnly_UpdatePowergridDisplay(float Used, float Max);

UFUNCTION(BlueprintCallable, Category = "Fitting Window")
void ClientOnly_UpdateCPUDisplay(float Used, float Max);

UFUNCTION(BlueprintCallable, Category = "Fitting Window")
void ClientOnly_UpdateSlot(ESlotType SlotType, int32 SlotIndex, const FCommon_ItemSlot& SlotData);

// ============================================================================
// SERVER RPC
// ============================================================================

UFUNCTION(BlueprintCallable, Category = "Fitting Window")
void ServerRPC_InstallModule(int32 ItemID, ESlotType SlotType, int32 SlotIndex);

UFUNCTION(BlueprintCallable, Category = "Fitting Window")
void ServerRPC_UninstallModule(ESlotType SlotType, int32 SlotIndex);

UFUNCTION(BlueprintCallable, Category = "Fitting Window")
void ServerRPC_SwapModules(ESlotType FromType, int32 FromIndex, ESlotType ToType, int32 ToIndex);

// ============================================================================
// COMMON FUNCTIONS
// ============================================================================

UFUNCTION(BlueprintPure, Category = "Fitting Window")
bool Common_CanInstallModule(int32 ItemID, ESlotType SlotType, int32 SlotIndex) const;

UFUNCTION(BlueprintPure, Category = "Fitting Window")
bool Common_CalculateFitting(const FCommon_ShipFittingData& FittingData, float& OutPowergrid, float& OutCPU) const;

UFUNCTION(BlueprintPure, Category = "Fitting Window")
TScriptInterface<IShipFittingInterface> Common_GetShipFittingInterface() const;

// ============================================================================
// EVENTS
// ============================================================================

// Исправление: замените FSimpleMulticastDelegate на DECLARE_MULTICAST_DELEGATE и используйте правильный тип делегата

// Use a dynamic multicast delegate so it can be exposed to Blueprints via UPROPERTY(BlueprintAssignable)
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFittingChanged);

UPROPERTY(BlueprintAssignable, Category = "Fitting Window|Events")
FOnFittingChanged OnFittingChanged;

UFUNCTION(BlueprintImplementableEvent, Category = "Fitting Window|Events")
void OnModuleInstalled(ESlotType SlotType, int32 SlotIndex);

UFUNCTION(BlueprintImplementableEvent, Category = "Fitting Window|Events")
void OnModuleUninstalled(ESlotType SlotType, int32 SlotIndex);

protected:
void GenerateFittingSlots();
void GenerateSlotsForType(ESlotType SlotType, UVerticalBox* Container, const TArray<FCommon_ItemSlot>& Slots);
void HandleSlotModuleDropped(ESlotType SlotType, int32 SlotIndex, int32 ItemID);
void HandleSlotModuleRemoved(ESlotType SlotType, int32 SlotIndex);
void UpdateResourceBars();
void BindToShipEvents();

// Store slot widgets in separate arrays per slot type because UHT doesn't support
// using TArray as the value in a TMap for reflected properties.
UPROPERTY()
TArray<UFittingSlotWidget*> HighSlotWidgets;

UPROPERTY()
TArray<UFittingSlotWidget*> MidSlotWidgets;

UPROPERTY()
TArray<UFittingSlotWidget*> LowSlotWidgets;

FORCEINLINE TArray<UFittingSlotWidget*>* GetSlotWidgetArray(ESlotType SlotType)
{
    switch (SlotType)
    {
    case ESlotType::High: return &HighSlotWidgets;
    case ESlotType::Mid: return &MidSlotWidgets;
    case ESlotType::Low: return &LowSlotWidgets;
    default: return nullptr;
    }
}

UPROPERTY()
APlayerController* CachedPlayerController;

UPROPERTY()
APawn* CachedShipPawn;

bool bIsInitialized = false;
};


/**
 * Individual Fitting Slot Widget
 * Supports drag & drop
 */
UCLASS(Blueprintable, BlueprintType)
class ECHOES_API UFittingSlotWidget : public UUserWidget
{
GENERATED_BODY()

public:
UFittingSlotWidget(const FObjectInitializer& ObjectInitializer);

virtual void NativeConstruct() override;
virtual bool NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;
virtual void NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation*& OutOperation) override;

UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
class UImage* ModuleIcon;

UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
class UBorder* SlotBorder;

UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
class UTextBlock* ModuleNameText;

UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
class UTextBlock* SlotNumberText;

UPROPERTY(BlueprintReadOnly, Category = "Fitting Slot")
ESlotType SlotType;

UPROPERTY(BlueprintReadOnly, Category = "Fitting Slot")
int32 SlotIndex;

UPROPERTY(BlueprintReadOnly, Category = "Fitting Slot")
FCommon_ItemSlot SlotData;

UFUNCTION(BlueprintCallable, Category = "Fitting Slot")
void InitializeSlot(ESlotType InSlotType, int32 InSlotIndex, const FCommon_ItemSlot& InSlotData);

UFUNCTION(BlueprintCallable, Category = "Fitting Slot")
void UpdateDisplay(const FCommon_ItemSlot& InSlotData);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnModuleDropped, ESlotType, SlotType, int32, SlotIndex, int32, ItemID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnModuleRemoved, ESlotType, SlotType, int32, SlotIndex);

UPROPERTY(BlueprintAssignable, Category = "Fitting Slot|Events")
FOnModuleDropped OnModuleDropped;

UPROPERTY(BlueprintAssignable, Category = "Fitting Slot|Events")
FOnModuleRemoved OnModuleRemoved;

UFUNCTION(BlueprintImplementableEvent, Category = "Fitting Slot|Events")
void OnSlotHighlighted(bool bHighlighted);

protected:
void SetHighlighted(bool bHighlighted);
};
