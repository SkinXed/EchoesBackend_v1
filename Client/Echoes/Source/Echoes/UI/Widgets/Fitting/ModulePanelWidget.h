// Copyright Epic Games, Inc. All Rights Reserved.
// Echoes - EVE-like MMO
// Module Panel Widget - Active equipment display and activation in space

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Core/Common/Interfaces/ShipFittingInterface.h"
#include "ModulePanelWidget.generated.h"

class UModuleSlotWidget;
class UUniformGridPanel;

/**
 * Module Panel Widget - Displays active modules in space HUD
 * Shows High/Mid/Low slots with activation controls
 * Server-authoritative activation with client-side visual feedback
 */
UCLASS(Blueprintable, BlueprintType)
class ECHOES_API UModulePanelWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UModulePanelWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	// ============================================================================
	// WIDGET REFERENCES (Bind in UMG Designer)
	// ============================================================================

	/** Container for High slots (weapons, utility high) */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UUniformGridPanel* HighSlotsGrid;

	/** Container for Mid slots (shield, ECM, tackle) */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UUniformGridPanel* MidSlotsGrid;

	/** Container for Low slots (armor, damage mods, propulsion) */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UUniformGridPanel* LowSlotsGrid;

	// ============================================================================
	// CONFIGURATION
	// ============================================================================

	/** Widget class for individual module slots */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Module Panel")
	TSubclassOf<UModuleSlotWidget> ModuleSlotWidgetClass;

	/** Number of columns in grid layout */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Module Panel")
	int32 GridColumns = 4;

	/** Update rate for cooldown visuals (Hz) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Module Panel")
	float CooldownUpdateRate = 10.0f;

	// ============================================================================
	// CLIENT-ONLY FUNCTIONS (UI Updates)
	// ============================================================================

	/**
	 * Update cooldown visual for a specific slot
	 * Called periodically to show cooldown progress
	 */
	UFUNCTION(BlueprintCallable, Category = "Module Panel")
	void ClientOnly_UpdateCooldown(ESlotType SlotType, int32 SlotIndex, float CooldownRemaining, float CooldownTotal);

	/**
	 * Update module state visual (Active/Overload/Offline)
	 * Called when server notifies of state change
	 */
	UFUNCTION(BlueprintCallable, Category = "Module Panel")
	void ClientOnly_UpdateModuleState(ESlotType SlotType, int32 SlotIndex, EModuleState NewState);

	/**
	 * Refresh all module displays from ship fitting
	 * Call on init or when fitting changes
	 */
	UFUNCTION(BlueprintCallable, Category = "Module Panel")
	void ClientOnly_RefreshAllModules();

	/**
	 * Update single slot display
	 */
	UFUNCTION(BlueprintCallable, Category = "Module Panel")
	void ClientOnly_UpdateSlot(const FCommon_ItemSlot& SlotData);

	// ============================================================================
	// SERVER RPC (Commands)
	// ============================================================================

	/**
	 * Toggle module activation (on/off)
	 * Server checks capacitor, cooldown, and activates
	 */
	UFUNCTION(BlueprintCallable, Category = "Module Panel")
	void ServerRPC_ToggleModule(ESlotType SlotType, int32 SlotIndex);

	/**
	 * Deactivate all modules (emergency power save)
	 */
	UFUNCTION(BlueprintCallable, Category = "Module Panel")
	void ServerRPC_DeactivateAll();

	// ============================================================================
	// COMMON FUNCTIONS (Pure Calculations)
	// ============================================================================

	/**
	 * Get module slot widget by type and index
	 */
	UFUNCTION(BlueprintPure, Category = "Module Panel")
	UModuleSlotWidget* Common_GetSlotWidget(ESlotType SlotType, int32 SlotIndex) const;

	/**
	 * Check if any modules are active
	 */
	UFUNCTION(BlueprintPure, Category = "Module Panel")
	bool Common_HasActiveModules() const;

	/**
	 * Get ship fitting interface from player's ship
	 */
	UFUNCTION(BlueprintPure, Category = "Module Panel")
	TScriptInterface<IShipFittingInterface> Common_GetShipFittingInterface() const;

	// ============================================================================
	// BLUEPRINT EVENTS
	// ============================================================================

	/** Called when module is activated/deactivated */
	UPROPERTY(BlueprintAssignable, Category = "Module Panel|Events")
	FSimpleMulticastDelegate OnModuleToggled;

	/**
	 * Blueprint event: Module state changed
	 */
	UFUNCTION(BlueprintImplementableEvent, Category = "Module Panel|Events")
	void OnModuleStateChanged(ESlotType SlotType, int32 SlotIndex, EModuleState NewState);

protected:
	/** Generate all slot widgets based on fitting */
	void GenerateModuleSlots();

	/** Generate slots for specific slot type */
	void GenerateSlotsForType(ESlotType SlotType, UUniformGridPanel* GridPanel, const TArray<FCommon_ItemSlot>& Slots);

	/** Handle module slot clicked */
	UFUNCTION()
	void HandleSlotClicked(ESlotType SlotType, int32 SlotIndex);

	/** Update cooldowns for all active modules */
	void UpdateAllCooldowns();

	/** Bind to ship fitting events */
	void BindToShipEvents();

	/** Created slot widgets */
	UPROPERTY()
	TMap<ESlotType, TArray<UModuleSlotWidget*>> SlotWidgets;

	/** Cached references */
	UPROPERTY()
	APlayerController* CachedPlayerController;

	UPROPERTY()
	APawn* CachedShipPawn;

	FTimerHandle CooldownUpdateTimer;
	bool bIsInitialized = false;
};


/**
 * Individual Module Slot Widget
 */
UCLASS(Blueprintable, BlueprintType)
class ECHOES_API UModuleSlotWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UModuleSlotWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UImage* ModuleIcon;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UProgressBar* CooldownOverlay;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UBorder* StateBorder;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* SlotNumberText;

	UPROPERTY(BlueprintReadOnly, Category = "Module Slot")
	ESlotType SlotType;

	UPROPERTY(BlueprintReadOnly, Category = "Module Slot")
	int32 SlotIndex;

	UPROPERTY(BlueprintReadOnly, Category = "Module Slot")
	EModuleState CurrentState;

	UPROPERTY(BlueprintReadOnly, Category = "Module Slot")
	FCommon_ItemSlot SlotData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Module Slot|Colors")
	FLinearColor OfflineColor = FLinearColor(0.2f, 0.2f, 0.2f, 1.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Module Slot|Colors")
	FLinearColor ActiveColor = FLinearColor(0.0f, 1.0f, 0.0f, 1.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Module Slot|Colors")
	FLinearColor OverloadColor = FLinearColor(1.0f, 0.5f, 0.0f, 1.0f);

	UFUNCTION(BlueprintCallable, Category = "Module Slot")
	void InitializeSlot(ESlotType InSlotType, int32 InSlotIndex, const FCommon_ItemSlot& InSlotData);

	UFUNCTION(BlueprintCallable, Category = "Module Slot")
	void UpdateDisplay(const FCommon_ItemSlot& InSlotData);

	UFUNCTION(BlueprintCallable, Category = "Module Slot")
	void UpdateCooldown(float Progress);

	UFUNCTION(BlueprintCallable, Category = "Module Slot")
	void UpdateState(EModuleState NewState);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSlotClicked, ESlotType, SlotType, int32, SlotIndex);
	
	UPROPERTY(BlueprintAssignable, Category = "Module Slot|Events")
	FOnSlotClicked OnSlotClicked;

	UFUNCTION(BlueprintImplementableEvent, Category = "Module Slot|Events")
	void OnSlotClickedEvent();

protected:
	void ApplyStateVisual();
};
