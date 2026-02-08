// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Core/Common/Components/TargetingComponent.h"
#include "Core/Common/Interfaces/ShipStateInterface.h"
#include "TargetPanelWidget.generated.h"

class UVerticalBox;
class UTargetItemWidget;
class UTextBlock;

/**
 * FTargetPanelData
 * 
 * Data structure for a single target in the target panel
 * Contains lock progress and target health information
 */
USTRUCT(BlueprintType)
struct FTargetPanelData
{
GENERATED_BODY()

/** Target actor reference */
UPROPERTY(BlueprintReadWrite, Category = "Target Panel")
AActor* TargetActor;

/** Target name/label */
UPROPERTY(BlueprintReadWrite, Category = "Target Panel")
FString TargetName;

/** Lock state */
UPROPERTY(BlueprintReadWrite, Category = "Target Panel")
ETargetLockState LockState;

/** Lock progress (0.0 to 1.0) */
UPROPERTY(BlueprintReadWrite, Category = "Target Panel")
float LockProgress;

/** Shield percentage (0.0 to 1.0) */
UPROPERTY(BlueprintReadWrite, Category = "Target Panel")
float ShieldPct;

/** Armor percentage (0.0 to 1.0) */
UPROPERTY(BlueprintReadWrite, Category = "Target Panel")
float ArmorPct;

/** Hull percentage (0.0 to 1.0) */
UPROPERTY(BlueprintReadWrite, Category = "Target Panel")
float HullPct;

/** Distance to target in cm */
UPROPERTY(BlueprintReadWrite, Category = "Target Panel")
float Distance;

/** Constructor */
FTargetPanelData()
: TargetActor(nullptr)
, TargetName(TEXT("Unknown"))
, LockState(ETargetLockState::None)
, LockProgress(0.0f)
, ShieldPct(1.0f)
, ArmorPct(1.0f)
, HullPct(1.0f)
, Distance(0.0f)
{
}
};

/**
 * Delegate for target state changed
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTargetStateChanged, AActor*, Target, const FTargetPanelData&, TargetData);

/**
 * Delegate for target selected
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTargetSelected, AActor*, Target);

/**
 * UTargetItemWidget
 * 
 * Individual target display widget
 * Shows lock progress ring and health bars (Shield/Armor/Hull)
 * 
 * Usage:
 * This widget is dynamically created for each locked target
 * and displays in the target panel container
 */
UCLASS(Abstract, Blueprintable)
class ECHOES_API UTargetItemWidget : public UUserWidget
{
GENERATED_BODY()

public:
/**
 * Set the target data for this widget
 * 
 * @param InTargetData The data to display
 */
UFUNCTION(BlueprintCallable, Category = "Target Item")
void SetTargetData(const FTargetPanelData& InTargetData);

/**
 * Get the current target data
 */
UFUNCTION(BlueprintPure, Category = "Target Item")
const FTargetPanelData& GetTargetData() const { return TargetData; }

/**
 * Get the target actor reference
 */
UFUNCTION(BlueprintPure, Category = "Target Item")
AActor* GetTargetActor() const { return TargetData.TargetActor; }

protected:
/**
 * Update the visual display
 * Override in Blueprint to customize appearance
 */
UFUNCTION(BlueprintImplementableEvent, Category = "Target Item")
void UpdateDisplay();

/**
 * Called when lock progress changes
 */
UFUNCTION(BlueprintImplementableEvent, Category = "Target Item")
void OnLockProgressChanged(float Progress);

/**
 * Called when lock state changes
 */
UFUNCTION(BlueprintImplementableEvent, Category = "Target Item")
void OnLockStateChanged(ETargetLockState NewState);

/** The target data being displayed */
UPROPERTY(BlueprintReadOnly, Category = "Target Item")
FTargetPanelData TargetData;

// Widget references (bind in Blueprint)

/** Target name text */
UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
class UTextBlock* TargetNameText;

/** Distance text */
UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
class UTextBlock* DistanceText;

/** Lock progress circular bar */
UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
class UCircularThrobber* LockProgressRing;

/** Shield progress bar */
UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
class UProgressBar* ShieldBar;

/** Armor progress bar */
UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
class UProgressBar* ArmorBar;

/** Hull progress bar */
UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
class UProgressBar* HullBar;

/** Shield text */
UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
class UTextBlock* ShieldText;

/** Armor text */
UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
class UTextBlock* ArmorText;

/** Hull text */
UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
class UTextBlock* HullText;
};

/**
 * UTargetPanelWidget
 * 
 * Panel displaying all currently locked targets
 * Dynamically creates/removes target item widgets
 * 
 * Features:
 * - Dynamic container for target items
 * - Lock progress display with circular progress bar
 * - Shield/Armor/Hull bars updated via ClientRPC
 * - Event-driven updates from TargetingComponent
 * 
 * Architecture:
 * - Vertical/Horizontal box container for target items
 * - Target items created on lock start
 * - Target items removed on lock lost
 * - Updates via TargetingComponent delegates
 * 
 * Usage:
 * // Automatically updates when TargetingComponent fires events
 * TargetPanelWidget->BindToTargetingComponent(TargetingComponent);
 */
UCLASS(Abstract, Blueprintable)
class ECHOES_API UTargetPanelWidget : public UUserWidget
{
GENERATED_BODY()

public:
UTargetPanelWidget(const FObjectInitializer& ObjectInitializer);

//~ Begin UUserWidget Interface
virtual void NativeConstruct() override;
virtual void NativeDestruct() override;
//~ End UUserWidget Interface

// ==================== Public API ====================

/**
 * Bind to a targeting component for automatic updates
 * 
 * @param TargetingComp The targeting component to bind to
 */
UFUNCTION(BlueprintCallable, Category = "Target Panel")
void BindToTargetingComponent(UTargetingComponent* TargetingComp);

/**
 * Unbind from current targeting component
 */
UFUNCTION(BlueprintCallable, Category = "Target Panel")
void UnbindFromTargetingComponent();

/**
 * Add a target to the panel
 * 
 * @param TargetData The target data to add
 */
UFUNCTION(BlueprintCallable, Category = "Target Panel")
void ClientOnly_AddTarget(const FTargetPanelData& TargetData);

/**
 * Remove a target from the panel
 * 
 * @param Target The target actor to remove
 */
UFUNCTION(BlueprintCallable, Category = "Target Panel")
void ClientOnly_RemoveTarget(AActor* Target);

/**
 * Update target data
 * 
 * @param Target The target to update
 * @param NewData The new data for the target
 */
UFUNCTION(BlueprintCallable, Category = "Target Panel")
void ClientOnly_UpdateTarget(AActor* Target, const FTargetPanelData& NewData);

/**
 * Clear all targets
 */
UFUNCTION(BlueprintCallable, Category = "Target Panel")
void ClearAllTargets();

/**
 * Get target item widget for a specific target
 * 
 * @param Target The target actor
 * @return The widget displaying this target, or nullptr if not found
 */
UFUNCTION(BlueprintPure, Category = "Target Panel")
UTargetItemWidget* GetTargetItemWidget(AActor* Target); 

// ==================== Events ====================

/** Fired when target state changes (lock progress, health, etc.) */
UPROPERTY(BlueprintAssignable, Category = "Target Panel Events")
FOnTargetStateChanged OnTargetStateChanged;

/** Fired when a target is selected/clicked */
UPROPERTY(BlueprintAssignable, Category = "Target Panel Events")
FOnTargetSelected OnTargetSelected;

protected:
// ==================== Widget References ====================

/** Container for target item widgets */
UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
UVerticalBox* TargetContainer;

/** Header text showing target count */
UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
UTextBlock* HeaderText;

// ==================== Configuration ====================

/** Target item widget class to spawn */
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target Panel Settings")
TSubclassOf<UTargetItemWidget> TargetItemWidgetClass;

/** Maximum number of targets to display */
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target Panel Settings")
int32 MaxDisplayedTargets;

// ==================== Internal State ====================

/** Map of target actor to widget */
UPROPERTY()
TMap<AActor*, UTargetItemWidget*> TargetWidgets;

/** Current targeting component */
UPROPERTY()
UTargetingComponent* BoundTargetingComponent;

// ==================== Event Handlers ====================

/**
 * Handle lock started from targeting component
 */
UFUNCTION()
void HandleLockStarted(AActor* Target);

/**
 * Handle lock completed from targeting component
 */
UFUNCTION()
void HandleLockCompleted(AActor* Target);

/**
 * Handle lock lost from targeting component
 */
UFUNCTION()
void HandleLockLost(AActor* Target);

/**
 * Handle lock progress from targeting component
 */
UFUNCTION()
void HandleLockProgress(AActor* Target, float Progress);

// ==================== Internal Functions ====================

/**
 * Update header text with target count
 */
void UpdateHeaderText();

/**
 * Query target health data from ship state interface
 */
FTargetPanelData QueryTargetData(AActor* Target, float LockProgress, ETargetLockState LockState) const;
};
