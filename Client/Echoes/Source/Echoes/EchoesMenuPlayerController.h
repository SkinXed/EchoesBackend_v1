// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EchoesMenuPlayerController.generated.h"

class UEchoesCharacterSelectWidget;

// Define log category for menu system
DECLARE_LOG_CATEGORY_EXTERN(LogEchoesMenu, Log, All);

/**
 * AEchoesMenuPlayerController
 * 
 * Player controller for character selection menu
 * Handles UI creation and input mode management
 * 
 * Key Features:
 * - Creates and displays character select widget on BeginPlay
 * - Sets input mode to UI-only with visible mouse cursor
 * - Only operates on local player controllers
 * 
 * Usage:
 * - Create a Blueprint based on this class
 * - Set CharacterSelectWidgetClass to your WBP_CharacterSelect blueprint
 * - Assign this controller in EchoesMenuGameMode
 * 
 * Integration:
 * - Widget should call AuthSubsystem->ConnectToWorld() instead of OpenLevel
 * - This enables proper ClientTravel to dedicated servers
 */
UCLASS()
class ECHOES_API AEchoesMenuPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	/**
	 * Called when controller is ready
	 * Creates character select widget and configures input
	 */
	virtual void BeginPlay() override;

	/**
	 * Widget class to instantiate for character selection
	 * Set this in Blueprint to WBP_CharacterSelect or similar
	 */
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UEchoesCharacterSelectWidget> CharacterSelectWidgetClass;

	/**
	 * Instance of the character select widget
	 */
	UPROPERTY()
	UEchoesCharacterSelectWidget* CharacterSelectWidget;
};
