// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Core/Common/Networking/EchoesAuthSubsystem.h"
#include "EchoesPlayerController.generated.h"

class UEchoesCharacterSelectWidget;

UCLASS()
class ECHOES_API AEchoesPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    AEchoesPlayerController();

    /** Widget class to use for character selection (set in Blueprint) */
    UPROPERTY(EditDefaultsOnly, Category = "Echoes|UI")
    TSubclassOf<UEchoesCharacterSelectWidget> CharacterSelectWidgetClass;

    /** Client RPC - show character selection widget and populate it */
    UFUNCTION(Client, Reliable)
    void Client_ShowCharacterSelection(const TArray<FCharacterInfo>& Characters);

    /** Server RPC - client selects a character and notifies server */
    UFUNCTION(Server, Reliable, WithValidation)
    void Server_SelectCharacter(const FGuid& CharacterId);

protected:
    /** Local reference to spawned widget */
    UPROPERTY()
    UEchoesCharacterSelectWidget* CharacterSelectWidgetInstance;
};