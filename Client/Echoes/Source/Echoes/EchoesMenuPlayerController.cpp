// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesMenuPlayerController.h"
#include "UI/Widgets/EchoesCharacterSelectWidget.h"
#include "Blueprint/UserWidget.h"

// Define log category
DEFINE_LOG_CATEGORY(LogEchoesMenu);

void AEchoesMenuPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// Only create UI for local player
	// This prevents creating UI on server or for remote players
	if (IsLocalController() && CharacterSelectWidgetClass)
	{
		// Create character select widget from specified class
		CharacterSelectWidget = CreateWidget<UEchoesCharacterSelectWidget>(this, CharacterSelectWidgetClass);
		if (CharacterSelectWidget)
		{
			// Add widget to viewport
			CharacterSelectWidget->AddToViewport();
			
			// Configure input mode: UI only, mouse cursor visible
			FInputModeUIOnly InputMode;
			InputMode.SetWidgetToFocus(CharacterSelectWidget->TakeWidget());
			InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
			
			SetInputMode(InputMode);
			bShowMouseCursor = true;
		}
		else
		{
			UE_LOG(LogEchoesMenu, Error, TEXT("Failed to create CharacterSelectWidget"));
		}
	}
	else if (!CharacterSelectWidgetClass)
	{
		UE_LOG(LogEchoesMenu, Warning, TEXT("CharacterSelectWidgetClass not set in Blueprint"));
	}
}
