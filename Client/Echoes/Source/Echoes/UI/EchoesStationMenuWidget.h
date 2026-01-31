// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EchoesStationMenuWidget.generated.h"

class UButton;
class UTextBlock;
class UEchoesInventoryComponent;

// Delegates for button actions
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInventoryButtonClicked);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnUndockButtonClicked);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRepairButtonClicked);

/**
 * UEchoesStationMenuWidget
 * 
 * Station menu widget for player interaction with stations
 * Provides access to inventory, undocking, and station services
 * 
 * Features:
 * - Inventory button: Opens personal hangar at current station
 * - Undock button: Initiates undocking sequence
 * - Repair button: Station services (stub for now)
 * - Displays current station info (Name, Type)
 * 
 * Usage:
 * - Create widget blueprint based on this class
 * - Add buttons: InventoryButton, UndockButton, RepairButton
 * - Add text blocks: StationNameText, StationTypeText
 * - Widget is opened via ClientRPC from StationActor upon docking
 */
UCLASS()
class ECHOES_API UEchoesStationMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UEchoesStationMenuWidget(const FObjectInitializer& ObjectInitializer);

	// UUserWidget interface
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	// End of UUserWidget interface

	/**
	 * Initialize the station menu with station data
	 * Called when the menu is opened
	 * 
	 * @param InStationId - Station GUID
	 * @param InStationName - Display name of station
	 * @param InStationType - Type of station (Trading, Military, etc.)
	 * @param InHangarStorageId - Container ID of personal hangar at this station
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Station|UI")
	void InitializeStationMenu(
		const FGuid& InStationId,
		const FString& InStationName,
		const FString& InStationType,
		const FGuid& InHangarStorageId);

	/**
	 * Get the station ID
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Station|UI")
	FGuid GetStationId() const { return StationId; }

	/**
	 * Get the hangar storage ID for inventory operations
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Station|UI")
	FGuid GetHangarStorageId() const { return HangarStorageId; }

	// ==================== Button Click Delegates ====================

	/**
	 * Triggered when Inventory button is clicked
	 * Blueprint should open hangar inventory UI
	 */
	UPROPERTY(BlueprintAssignable, Category = "Echoes|Station|Events")
	FOnInventoryButtonClicked OnInventoryButtonClicked;

	/**
	 * Triggered when Undock button is clicked
	 * Blueprint should initiate undocking sequence
	 */
	UPROPERTY(BlueprintAssignable, Category = "Echoes|Station|Events")
	FOnUndockButtonClicked OnUndockButtonClicked;

	/**
	 * Triggered when Repair button is clicked
	 * Blueprint should open repair/services UI
	 */
	UPROPERTY(BlueprintAssignable, Category = "Echoes|Station|Events")
	FOnRepairButtonClicked OnRepairButtonClicked;

protected:
	/**
	 * Handle Inventory button clicked
	 */
	UFUNCTION()
	void OnInventoryButtonPressed();

	/**
	 * Handle Undock button clicked
	 */
	UFUNCTION()
	void OnUndockButtonPressed();

	/**
	 * Handle Repair button clicked
	 */
	UFUNCTION()
	void OnRepairButtonPressed();

	/**
	 * Blueprint event called when station menu is initialized
	 * Override in Blueprint for custom initialization
	 */
	UFUNCTION(BlueprintImplementableEvent, Category = "Echoes|Station|UI")
	void OnStationMenuInitialized();

	/**
	 * Update the station info display
	 */
	void UpdateStationDisplay();

	// ==================== Widget Bindings ====================

	/** Button to open inventory/hangar */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Echoes|Station|UI")
	UButton* InventoryButton;

	/** Button to undock from station */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Echoes|Station|UI")
	UButton* UndockButton;

	/** Button for repair/services (stub) */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Echoes|Station|UI")
	UButton* RepairButton;

	/** Text block displaying station name */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Echoes|Station|UI")
	UTextBlock* StationNameText;

	/** Text block displaying station type */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Echoes|Station|UI")
	UTextBlock* StationTypeText;

private:
	/** Current station ID */
	UPROPERTY()
	FGuid StationId;

	/** Station name */
	UPROPERTY()
	FString StationName;

	/** Station type */
	UPROPERTY()
	FString StationType;

	/** Personal hangar storage ID at this station */
	UPROPERTY()
	FGuid HangarStorageId;

	/** Whether the widget has been initialized */
	bool bIsInitialized = false;
};
