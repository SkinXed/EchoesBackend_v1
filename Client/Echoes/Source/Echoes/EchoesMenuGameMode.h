// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EchoesMenuGameMode.generated.h"

/**
 * AEchoesMenuGameMode
 * 
 * Game mode for character selection menu
 * Prevents pawn spawning and uses specialized menu player controller
 * 
 * Key Features:
 * - No pawn spawning (DefaultPawnClass = nullptr)
 * - Uses EchoesMenuPlayerController for UI management
 * - Designed for standalone/listen server menu maps
 * 
 * Usage:
 * - Create a Blueprint based on this class
 * - Set as GameMode override in World Settings of CharacterSelectMap
 * - In the Blueprint, ensure PlayerControllerClass is set to EchoesMenuPlayerController
 */
UCLASS()
class ECHOES_API AEchoesMenuGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AEchoesMenuGameMode();

	/**
	 * Override to prevent server from spawning pawn in menu
	 * Players should not have a physical pawn in the character select screen
	 */
	virtual bool ShouldSpawnAtStartSpot(AController* Player) override { return false; }
};
