// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesMenuPlayerController.h"
#include "UI/Widgets/EchoesCharacterSelectWidget.h"
#include "UI/Widgets/EchoesLoginWidget.h"
#include "UI/Widgets/EchoesPreloadWidget.h"
#include "Blueprint/UserWidget.h"

// Define log category
DEFINE_LOG_CATEGORY(LogEchoesMenu);

void AEchoesMenuPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// Only create UI for local player
	// This prevents creating UI on server or for remote players
	if (IsLocalController())
	{
		if (!PreloadWidgetClass)
		{
			UE_LOG(LogEchoesMenu, Warning, TEXT("PreloadWidgetClass not set, falling back to Login"));
			ShowLoginScreen();
			return;
		}

		// Start authorization flow with preload screen
		UEchoesPreloadWidget* PreloadWidget = CreateWidget<UEchoesPreloadWidget>(this, PreloadWidgetClass);
		if (PreloadWidget)
		{
			CurrentWidget = PreloadWidget;
			PreloadWidget->AddToViewport();

			// Bind to preload completion event
			PreloadWidget->OnPreloadComplete.AddDynamic(this, &AEchoesMenuPlayerController::OnPreloadComplete);

			// Configure input mode: UI only, mouse cursor visible
			FInputModeUIOnly InputMode;
			InputMode.SetWidgetToFocus(PreloadWidget->TakeWidget());
			InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

			SetInputMode(InputMode);
			bShowMouseCursor = true;

			UE_LOG(LogEchoesMenu, Log, TEXT("Started authorization flow with preload screen"));
		}
		else
		{
			UE_LOG(LogEchoesMenu, Error, TEXT("Failed to create PreloadWidget"));
		}
	}
}

void AEchoesMenuPlayerController::OnPreloadComplete(ENextState NextState)
{
	UE_LOG(LogEchoesMenu, Log, TEXT("Preload complete, transitioning to next state: %d"), (int32)NextState);

	// Transition to appropriate screen based on preload result
	switch (NextState)
	{
	case ENextState::Login:
		ShowLoginScreen();
		break;

	case ENextState::CharacterSelect:
		ShowCharacterSelect();
		break;

	default:
		UE_LOG(LogEchoesMenu, Warning, TEXT("Unknown next state: %d"), (int32)NextState);
		ShowLoginScreen();
		break;
	}
}

void AEchoesMenuPlayerController::ShowLoginScreen()
{
	if (!IsLocalController())
	{
		return;
	}

	if (!LoginWidgetClass)
	{
		UE_LOG(LogEchoesMenu, Error, TEXT("LoginWidgetClass not set in Blueprint"));
		return;
	}

	UE_LOG(LogEchoesMenu, Log, TEXT("Showing login screen"));
	ChangeWidget(LoginWidgetClass);

	// Bind to login success to transition to character select
	if (UEchoesLoginWidget* LoginWidget = Cast<UEchoesLoginWidget>(CurrentWidget))
	{
		LoginWidget->OnLoginSuccessDelegate.AddDynamic(this, &AEchoesMenuPlayerController::OnLoginSuccess);
	}
}

void AEchoesMenuPlayerController::OnLoginSuccess(const FAuthResponse& AuthResponse)
{
	ShowCharacterSelect();
}

void AEchoesMenuPlayerController::ShowCharacterSelect()
{
	if (!IsLocalController())
	{
		return;
	}

	if (!CharacterSelectWidgetClass)
	{
		UE_LOG(LogEchoesMenu, Error, TEXT("CharacterSelectWidgetClass not set in Blueprint"));
		return;
	}

	UE_LOG(LogEchoesMenu, Log, TEXT("Showing character selection screen"));
	ChangeWidget(CharacterSelectWidgetClass);
}

void AEchoesMenuPlayerController::ChangeWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{
	if (!NewWidgetClass)
	{
		UE_LOG(LogEchoesMenu, Error, TEXT("ChangeWidget called with null widget class"));
		return;
	}

	// Remove current widget if it exists
	if (CurrentWidget)
	{
		CurrentWidget->RemoveFromParent();
		CurrentWidget = nullptr;
	}

	// Create and display new widget
	CurrentWidget = CreateWidget<UUserWidget>(this, NewWidgetClass);
	if (CurrentWidget)
	{
		CurrentWidget->AddToViewport();

		// Configure input mode: UI only, mouse cursor visible
		FInputModeUIOnly InputMode;
		InputMode.SetWidgetToFocus(CurrentWidget->TakeWidget());
		InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

		SetInputMode(InputMode);
		bShowMouseCursor = true;

		UE_LOG(LogEchoesMenu, Log, TEXT("Changed widget to: %s"), *NewWidgetClass->GetName());
	}
	else
	{
		UE_LOG(LogEchoesMenu, Error, TEXT("Failed to create widget: %s"), *NewWidgetClass->GetName());
	}
}
