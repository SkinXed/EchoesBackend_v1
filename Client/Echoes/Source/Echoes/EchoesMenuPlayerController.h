// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EchoesMenuPlayerController.generated.h"

class UEchoesCharacterSelectWidget;
class UEchoesLoginWidget;
class UEchoesPreloadWidget;
class UUserWidget;

// Forward declare enum for preload completion (defined in EchoesPreloadWidget.h)
enum class ENextState : uint8;

// Define log category for menu system
DECLARE_LOG_CATEGORY_EXTERN(LogEchoesMenu, Log, All);

/**
 * AEchoesMenuPlayerController
 * 
 * Centralized menu controller for authorization flow
 * Manages widget transitions and input mode
 * 
 * Authorization Chain:
 * Preload (token check) -> Login (credentials) -> CharacterSelect -> ConnectToWorld
 * 
 * Key Features:
 * - ShowLoginScreen() - Display login widget
 * - ShowCharacterSelect() - Display character selection widget
 * - ChangeWidget() - Internal method for widget transitions
 * - Handles bShowMouseCursor = true and FInputModeUIOnly
 * - Only operates on local player controllers
 * 
 * Usage:
 * - Create a Blueprint based on this class
 * - Set widget class properties in Blueprint
 * - Assign this controller in EchoesMenuGameMode
 */
UCLASS()
class ECHOES_API AEchoesMenuPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	/**
	 * Show login screen
	 * Called when player needs to authenticate
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Menu")
	void ShowLoginScreen();

	/**
	 * Show character selection screen
	 * Called after successful login
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Menu")
	void ShowCharacterSelect();

protected:
	/**
	 * Called when controller is ready
	 * Starts authorization flow with preload screen
	 */
	virtual void BeginPlay() override;

	/**
	 * Change active widget
	 * Removes current widget and displays new one
	 * Configures input mode for UI interaction
	 * 
	 * @param NewWidgetClass - Class of widget to display
	 */
	void ChangeWidget(TSubclassOf<UUserWidget> NewWidgetClass);

	/**
	 * Handle preload completion
	 * Transitions to login or character select based on result
	 */
	UFUNCTION()
	void OnPreloadComplete(ENextState NextState);

	// ==================== Widget Classes ====================

	/**
	 * Preload widget class for initial validation
	 * Set this in Blueprint to WBP_Preload or similar
	 */
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UEchoesPreloadWidget> PreloadWidgetClass;

	/**
	 * Login widget class for authentication
	 * Set this in Blueprint to WBP_Login or similar
	 */
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UEchoesLoginWidget> LoginWidgetClass;

	/**
	 * Character select widget class
	 * Set this in Blueprint to WBP_CharacterSelect or similar
	 */
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UEchoesCharacterSelectWidget> CharacterSelectWidgetClass;

	// ==================== Widget Instances ====================

	/**
	 * Currently active widget
	 */
	UPROPERTY()
	UUserWidget* CurrentWidget;
};
