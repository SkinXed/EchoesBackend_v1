// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Core/Common/Interfaces/ShipStateInterface.h"
#include "NavigationWidget.generated.h"

class UTextBlock;
class UButton;
class UImage;
class UProgressBar;

/**
 * ENavigationCommand
 * 
 * Navigation commands that can be issued to ship
 */
UENUM(BlueprintType)
enum class ENavigationCommand : uint8
{
/** Align ship to target direction */
AlignTo UMETA(DisplayName = "Align To"),

/** Orbit around target at specified range */
Orbit UMETA(DisplayName = "Orbit"),

/** Warp to target location */
WarpTo UMETA(DisplayName = "Warp To"),

/** Approach target */
Approach UMETA(DisplayName = "Approach"),

/** Keep at range from target */
KeepAtRange UMETA(DisplayName = "Keep At Range"),

/** Stop all movement */
Stop UMETA(DisplayName = "Stop")
};

/**
 * Delegate for navigation command issued
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnNavigationCommandIssued, ENavigationCommand, Command, AActor*, Target);

/**
 * UNavigationWidget
 * 
 * Navigation and speed display widget
 * Shows current speed, velocity vector, and navigation commands
 * 
 * Features:
 * - Speedometer with current/max speed
 * - Velocity vector display
 * - Navigation command buttons (Align, Orbit, Warp, etc.)
 * - ServerRPC commands for ship control
 * - Event-driven updates
 * 
 * Usage:
 * NavigationWidget->BindToShip(PlayerShip);
 * NavigationWidget->SetTarget(TargetActor);
 */
UCLASS(Abstract, Blueprintable)
class ECHOES_API UNavigationWidget : public UUserWidget
{
GENERATED_BODY()

public:
UNavigationWidget(const FObjectInitializer& ObjectInitializer);

//~ Begin UUserWidget Interface
virtual void NativeConstruct() override;
virtual void NativeDestruct() override;
//~ End UUserWidget Interface

// ==================== Public API ====================

/**
 * Bind to a ship for automatic updates
 * 
 * @param Ship The ship actor
 */
UFUNCTION(BlueprintCallable, Category = "Navigation")
void BindToShip(AActor* Ship);

/**
 * Unbind from current ship
 */
UFUNCTION(BlueprintCallable, Category = "Navigation")
void UnbindFromShip();

/**
 * Set the current navigation target
 * 
 * @param Target The target actor for navigation commands
 */
UFUNCTION(BlueprintCallable, Category = "Navigation")
void SetNavigationTarget(AActor* Target);

/**
 * CLIENT ONLY: Update speed display
 * 
 * @param CurrentSpeed Current speed in m/s
 * @param MaxSpeed Maximum speed in m/s
 * @param Velocity Current velocity vector
 */
UFUNCTION(BlueprintCallable, Category = "Navigation")
void ClientOnly_UpdateSpeed(float CurrentSpeed, float MaxSpeed, FVector Velocity);

/**
 * CLIENT ONLY: Refresh all displays from bound ship
 */
UFUNCTION(BlueprintCallable, Category = "Navigation")
void ClientOnly_RefreshDisplays();

/**
 * SERVER RPC: Execute navigation command
 * 
 * @param CommandType The navigation command to execute
 * @param Target The target for the command (can be null for Stop)
 */
UFUNCTION(BlueprintCallable, Category = "Navigation", meta = (AutoCreateRefTerm = "Target"))
void ServerRPC_ExecuteNavCommand(ENavigationCommand CommandType, AActor* Target);

/**
 * COMMON (Pure): Format speed value to string
 * 
 * @param SpeedInMps Speed in meters per second
 * @return Formatted string (e.g., "125 m/s", "2.5 km/s")
 */
UFUNCTION(BlueprintPure, Category = "Navigation")
static FString Common_FormatSpeed(float SpeedInMps);

/**
 * COMMON (Pure): Get velocity direction as compass bearing
 * 
 * @param Velocity Velocity vector
 * @return Bearing in degrees (0-360)
 */
UFUNCTION(BlueprintPure, Category = "Navigation")
static float Common_GetVelocityBearing(FVector Velocity);

// ==================== Events ====================

/** Fired when a navigation command is issued */
UPROPERTY(BlueprintAssignable, Category = "Navigation Events")
FOnNavigationCommandIssued OnCommandIssued;

protected:
// ==================== Widget References ====================

/** Speed value text (large display) */
UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
UTextBlock* SpeedText;

/** Max speed text */
UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
UTextBlock* MaxSpeedText;

/** Speed progress bar (0 to max speed) */
UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
UProgressBar* SpeedBar;

/** Velocity direction indicator (arrow/compass) */
UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
UImage* VelocityArrow;

/** Velocity magnitude text */
UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
UTextBlock* VelocityText;

// Navigation command buttons

/** Align To button */
UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
UButton* AlignToButton;

/** Orbit button */
UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
UButton* OrbitButton;

/** Warp To button */
UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
UButton* WarpToButton;

/** Approach button */
UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
UButton* ApproachButton;

/** Keep At Range button */
UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
UButton* KeepAtRangeButton;

/** Stop button */
UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
UButton* StopButton;

// ==================== Configuration ====================

/** Update interval for speed display (seconds) */
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Navigation Settings")
float UpdateInterval;

/** Enable velocity vector display */
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Navigation Settings")
bool bShowVelocityVector;

// ==================== Internal State ====================

/** Current bound ship */
UPROPERTY()
AActor* BoundShip;

/** Current navigation target */
UPROPERTY()
AActor* CurrentTarget;

/** Timer handle for periodic updates */
FTimerHandle UpdateTimerHandle;

/** Current speed (for caching) */
UPROPERTY()
float CurrentSpeed;

/** Current max speed (for caching) */
UPROPERTY()
float CurrentMaxSpeed;

/** Current velocity (for caching) */
UPROPERTY()
FVector CurrentVelocity;

// ==================== Button Click Handlers ====================

UFUNCTION()
void HandleAlignToClicked();

UFUNCTION()
void HandleOrbitClicked();

UFUNCTION()
void HandleWarpToClicked();

UFUNCTION()
void HandleApproachClicked();

UFUNCTION()
void HandleKeepAtRangeClicked();

UFUNCTION()
void HandleStopClicked();

// ==================== Internal Functions ====================

/**
 * Periodic update function called by timer
 */
UFUNCTION()
void HandlePeriodicUpdate();

/**
 * Update button enabled states based on target availability
 */
void UpdateButtonStates();

/**
 * Execute a navigation command (calls ServerRPC if needed)
 */
void ExecuteCommand(ENavigationCommand CommandType);

/**
 * Update velocity arrow rotation based on velocity vector
 */
void UpdateVelocityArrow();

/**
 * Blueprint event called when command is issued
 */
UFUNCTION(BlueprintImplementableEvent, Category = "Navigation Events")
void OnNavigationCommandExecuted(ENavigationCommand Command, AActor* Target);
};
