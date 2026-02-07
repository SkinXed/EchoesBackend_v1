// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Core/Common/Interfaces/ShipStateInterface.h"
#include "EchoesMainHUD.generated.h"

class UWidgetSwitcher;
class UUserWidget;
class UProgressBar;
class UTextBlock;
class UCanvasPanel;
class UOverlay;
class UVerticalBox;
class UHorizontalBox;

/**
 * Game state enum for HUD mode switching
 */
UENUM(BlueprintType)
enum class EGameState : uint8
{
	/** In station/hangar - showing fitting, inventory, social UI */
	InHangar UMETA(DisplayName = "In Hangar"),
	
	/** In space - showing navigation, targeting, overview UI */
	InSpace UMETA(DisplayName = "In Space"),
	
	/** Unknown or transitioning state */
	Unknown UMETA(DisplayName = "Unknown")
};

/**
 * Delegate for game state changed event
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameStateChanged, EGameState, NewState);

/**
 * Delegate for ship status updated event
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnShipStatusUpdated, const FCommon_ShipDataStruct&, ShipData);

/**
 * UEchoesMainHUD
 * 
 * Main HUD widget for EVE-like MMO interface
 * Manages two distinct UI states: Hangar Mode and Space Mode
 * 
 * Architecture:
 * - Widget Switcher: Root container that switches between Hangar and Space layouts
 *   - HangarHUD Widget: Station interface (fitting, inventory, social)
 *   - SpaceHUD Widget: Space interface (navigation, targeting, overview, shields)
 * 
 * State Management:
 * - InHangar: Player is docked at station, shows hangar interface
 * - InSpace: Player is in space, shows space navigation and combat interface
 * - State changes triggered by docking/undocking events
 * 
 * Data Flow:
 * - Ship data obtained via IShipStateInterface from player's ship pawn
 * - Event-driven updates (no Tick) for performance
 * - Invalidation boxes for static elements
 * - Delegates for UI synchronization
 * 
 * Optimization:
 * - No Tick function - uses event-driven updates
 * - Invalidation boxes for static UI elements
 * - Lazy widget creation (spawned on demand)
 * - Cached component references
 * 
 * Usage:
 * // Create and add to viewport
 * UEchoesMainHUD* HUD = CreateWidget<UEchoesMainHUD>(PlayerController, HUDClass);
 * HUD->AddToViewport();
 * 
 * // Switch states
 * HUD->SetGameState(EGameState::InSpace);
 * 
 * // Bind to state changes
 * HUD->OnGameStateChanged.AddDynamic(this, &APlayerController::HandleStateChange);
 */
UCLASS()
class ECHOES_API UEchoesMainHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UEchoesMainHUD(const FObjectInitializer& ObjectInitializer);

	// UUserWidget interface
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	// End of UUserWidget interface

	// ==================== State Management ====================

	/**
	 * Set current game state and switch HUD mode
	 * 
	 * @param NewState - New game state (InHangar or InSpace)
	 * 
	 * This function:
	 * - Switches widget switcher to appropriate child widget
	 * - Broadcasts OnGameStateChanged event
	 * - Updates UI visibility and layout
	 * - Initializes state-specific widgets if needed
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|HUD")
	void SetGameState(EGameState NewState);

	/**
	 * Get current game state
	 * 
	 * @return Current game state
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|HUD")
	EGameState GetGameState() const { return CurrentGameState; }

	/**
	 * Check if currently in hangar
	 * 
	 * @return True if in hangar mode
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|HUD")
	bool IsInHangar() const { return CurrentGameState == EGameState::InHangar; }

	/**
	 * Check if currently in space
	 * 
	 * @return True if in space mode
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|HUD")
	bool IsInSpace() const { return CurrentGameState == EGameState::InSpace; }

	// ==================== Ship Status Updates (ClientOnly_) ====================

	/**
	 * Update ship status display (Shield, Armor, Hull bars)
	 * 
	 * @param ShipData - Ship data structure with current stats
	 * 
	 * This function:
	 * - Updates progress bars for Shield/Armor/Hull
	 * - Updates text displays with current/max values
	 * - Updates color coding based on health levels
	 * - Broadcasts OnShipStatusUpdated for child widgets
	 * 
	 * Note: Called by events, not Tick, for performance
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|HUD")
	void ClientOnly_UpdateShipStatus(const FCommon_ShipDataStruct& ShipData);

	/**
	 * Update capacitor display
	 * 
	 * @param Current - Current capacitor value
	 * @param Max - Maximum capacitor value
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|HUD")
	void ClientOnly_UpdateCapacitor(float Current, float Max);

	/**
	 * Update speed display
	 * 
	 * @param Speed - Current speed in m/s
	 * @param MaxSpeed - Maximum speed in m/s
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|HUD")
	void ClientOnly_UpdateSpeed(float Speed, float MaxSpeed);

	/**
	 * Update target count display
	 * 
	 * @param Current - Current number of locked targets
	 * @param Max - Maximum number of lockable targets
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|HUD")
	void ClientOnly_UpdateTargetCount(int32 Current, int32 Max);

	/**
	 * Request full ship data update from ship interface
	 * Queries the ship via IShipStateInterface and updates all displays
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|HUD")
	void ClientOnly_RefreshAllDisplays();

	// ==================== Pure Calculation Functions (Common_) ====================

	/**
	 * Calculate target lead indicator position for aiming
	 * 
	 * @param TargetActor - Target being aimed at
	 * @param ProjectileSpeed - Speed of projectile in cm/s
	 * @return World position where to aim for intercept
	 * 
	 * This uses First-Order Intercept algorithm:
	 * - Calculates where target will be when projectile arrives
	 * - Returns 3D world position for reticle/indicator placement
	 * - Returns target's current position if calculation fails
	 * 
	 * Usage:
	 * FVector LeadPos = HUD->Common_GetTargetLeadIndicator(Enemy, 50000.0f);
	 * ProjectWorldLocationToWidgetPosition(LeadPos, ScreenPos);
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|HUD")
	FVector Common_GetTargetLeadIndicator(AActor* TargetActor, float ProjectileSpeed) const;

	/**
	 * Get ship data from player's ship via interface
	 * 
	 * @return Ship data structure, or default values if no ship
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|HUD")
	FCommon_ShipDataStruct Common_GetShipData() const;

	/**
	 * Check if ship data is available
	 * 
	 * @return True if player has ship with IShipStateInterface
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|HUD")
	bool Common_HasShipData() const;

	/**
	 * Get color for health bar based on percentage
	 * 
	 * @param Percentage - Health percentage (0.0 to 1.0)
	 * @return Color (Green > 50%, Yellow 25-50%, Red < 25%)
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|HUD")
	FLinearColor Common_GetHealthBarColor(float Percentage) const;

	/**
	 * Format speed value for display (converts cm/s to m/s)
	 * 
	 * @param SpeedCmPerSec - Speed in cm/s
	 * @return Formatted text (e.g., "125 m/s")
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|HUD")
	FText Common_FormatSpeed(float SpeedCmPerSec) const;

	/**
	 * Format distance for display (converts cm to km if > 1km)
	 * 
	 * @param DistanceCm - Distance in cm
	 * @return Formatted text (e.g., "2.5 km" or "450 m")
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|HUD")
	FText Common_FormatDistance(float DistanceCm) const;

	// ==================== Blueprint Events ====================

	/**
	 * Called when game state changes (InHangar <-> InSpace)
	 */
	UPROPERTY(BlueprintAssignable, Category = "Echoes|HUD|Events")
	FOnGameStateChanged OnGameStateChanged;

	/**
	 * Called when ship status is updated
	 */
	UPROPERTY(BlueprintAssignable, Category = "Echoes|HUD|Events")
	FOnShipStatusUpdated OnShipStatusUpdated;

	/**
	 * Blueprint event called when entering hangar
	 * Use this to initialize hangar-specific UI
	 */
	UFUNCTION(BlueprintImplementableEvent, Category = "Echoes|HUD|Events")
	void OnEnterHangar();

	/**
	 * Blueprint event called when entering space
	 * Use this to initialize space-specific UI
	 */
	UFUNCTION(BlueprintImplementableEvent, Category = "Echoes|HUD|Events")
	void OnEnterSpace();

	/**
	 * Blueprint event called when ship data changes
	 * Use this for custom UI updates
	 */
	UFUNCTION(BlueprintImplementableEvent, Category = "Echoes|HUD|Events")
	void OnShipDataChanged(const FCommon_ShipDataStruct& NewData);

	// ==================== Widget References (BindWidget) ====================

	/**
	 * Widget switcher for Hangar/Space modes
	 * Index 0 = HangarHUD, Index 1 = SpaceHUD
	 */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetOptional), Category = "Echoes|HUD|Widgets")
	UWidgetSwitcher* ModeSwitcher;

	/**
	 * Hangar HUD widget (index 0 in switcher)
	 * Contains: Fitting screen, Inventory, Social panel, Station services
	 */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetOptional), Category = "Echoes|HUD|Widgets")
	UUserWidget* HangarHUD;

	/**
	 * Space HUD widget (index 1 in switcher)
	 * Contains: Target panel, Overview, Shield/Armor/Hull bars, Navigation
	 */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetOptional), Category = "Echoes|HUD|Widgets")
	UUserWidget* SpaceHUD;

	// ==================== Ship Status Widgets ====================

	/**
	 * Shield progress bar
	 */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetOptional), Category = "Echoes|HUD|Ship Status")
	UProgressBar* ShieldBar;

	/**
	 * Armor progress bar
	 */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetOptional), Category = "Echoes|HUD|Ship Status")
	UProgressBar* ArmorBar;

	/**
	 * Structure/Hull progress bar
	 */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetOptional), Category = "Echoes|HUD|Ship Status")
	UProgressBar* HullBar;

	/**
	 * Capacitor progress bar
	 */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetOptional), Category = "Echoes|HUD|Ship Status")
	UProgressBar* CapacitorBar;

	/**
	 * Shield value text (e.g., "500/1000")
	 */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetOptional), Category = "Echoes|HUD|Ship Status")
	UTextBlock* ShieldText;

	/**
	 * Armor value text
	 */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetOptional), Category = "Echoes|HUD|Ship Status")
	UTextBlock* ArmorText;

	/**
	 * Hull value text
	 */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetOptional), Category = "Echoes|HUD|Ship Status")
	UTextBlock* HullText;

	/**
	 * Speed value text (e.g., "125 m/s")
	 */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetOptional), Category = "Echoes|HUD|Ship Status")
	UTextBlock* SpeedText;

	/**
	 * Target count text (e.g., "3/5")
	 */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetOptional), Category = "Echoes|HUD|Ship Status")
	UTextBlock* TargetCountText;

	// ==================== Configuration ====================

	/**
	 * Update rate for ship status in seconds
	 * Default: 0.1 (10 times per second)
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Echoes|HUD|Config")
	float ShipStatusUpdateRate = 0.1f;

	/**
	 * Enable debug display
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Echoes|HUD|Config")
	bool bShowDebugInfo = false;

	/**
	 * Initial game state
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Echoes|HUD|Config")
	EGameState InitialGameState = EGameState::InHangar;

protected:
	// ==================== Internal Functions ====================

	/**
	 * Initialize widget references and bindings
	 */
	void InitializeWidgets();

	/**
	 * Setup event bindings for ship component updates
	 */
	void BindShipEvents();

	/**
	 * Unbind ship events on destruct
	 */
	void UnbindShipEvents();

	/**
	 * Get player's ship pawn
	 * 
	 * @return Ship pawn, or nullptr if not available
	 */
	APawn* GetPlayerShip() const;

	/**
	 * Get ship state interface from player's ship
	 * 
	 * @return IShipStateInterface implementation, or nullptr
	 */
	IShipStateInterface* GetShipStateInterface() const;

	/**
	 * Update progress bar with value and optional color
	 */
	void UpdateProgressBar(UProgressBar* Bar, float Current, float Max, const FLinearColor& Color);

	/**
	 * Update text block with formatted value
	 */
	void UpdateValueText(UTextBlock* TextBlock, float Current, float Max);

	/**
	 * Switch to hangar mode (internal)
	 */
	void SwitchToHangarMode();

	/**
	 * Switch to space mode (internal)
	 */
	void SwitchToSpaceMode();

	/**
	 * Handle stats changed event from ship component
	 */
	UFUNCTION()
	void OnShipStatsChanged(float ShieldPct, float ArmorPct, float StructPct);

private:
	/** Current game state */
	EGameState CurrentGameState = EGameState::Unknown;

	/** Cached player controller */
	UPROPERTY()
	APlayerController* CachedPlayerController;

	/** Cached ship pawn */
	UPROPERTY()
	APawn* CachedShipPawn;

	/** Timer handle for periodic updates */
	FTimerHandle ShipStatusUpdateTimer;

	/** Last known ship data for change detection */
	FCommon_ShipDataStruct LastShipData;
};
