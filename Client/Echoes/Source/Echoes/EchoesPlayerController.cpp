// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesPlayerController.h"
#include "UI/Widgets/EchoesCharacterSelectWidget.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "EchoesServerGameMode.h"

AEchoesPlayerController::AEchoesPlayerController()
{
}

void AEchoesPlayerController::Client_ShowCharacterSelection_Implementation(const TArray<FCharacterInfo>& Characters)
{
    if (!IsLocalController())
    {
        UE_LOG(LogTemp, Warning, TEXT("Client_ShowCharacterSelection called on non-local controller"));
        return;
    }

    if (!CharacterSelectWidgetClass)
    {
        UE_LOG(LogTemp, Error, TEXT("CharacterSelectWidgetClass is not set on PlayerController"));
        return;
    }

    CharacterSelectWidgetInstance = CreateWidget<UEchoesCharacterSelectWidget>(this, CharacterSelectWidgetClass);
    if (!CharacterSelectWidgetInstance)
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to create CharacterSelectWidgetInstance"));
        return;
    }

    // Populate character list by passing the array received from server to the widget
    CharacterSelectWidgetInstance->PopulateCharacterList(Characters);

    CharacterSelectWidgetInstance->AddToViewport();

    // Set input mode to UI
    FInputModeUIOnly InputMode;
    InputMode.SetWidgetToFocus(CharacterSelectWidgetInstance->TakeWidget());
    SetInputMode(InputMode);
    bShowMouseCursor = true;
}

void AEchoesPlayerController::Server_SelectCharacter_Implementation(const FGuid& CharacterId)
{
    // Validate on server
    if (!CharacterId.IsValid())
    {
        UE_LOG(LogTemp, Warning, TEXT("Server_SelectCharacter: invalid CharacterId"));
        return;
    }

    // Notify GameMode to spawn player ship
    if (GetWorld() && GetWorld()->GetAuthGameMode())
    {
        AEchoesServerGameMode* GM = Cast<AEchoesServerGameMode>(GetWorld()->GetAuthGameMode());
        if (GM)
        {
            GM->SpawnPlayerShip(this, CharacterId);
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("Server_SelectCharacter: GameMode is not AEchoesServerGameMode"));
        }
    }
}

bool AEchoesPlayerController::Server_SelectCharacter_Validate(const FGuid& CharacterId)
{
    return CharacterId.IsValid();
}