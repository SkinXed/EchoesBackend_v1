// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesMenuGameMode.h"
#include "EchoesMenuPlayerController.h"

AEchoesMenuGameMode::AEchoesMenuGameMode()
{
	// Use specialized menu player controller
	PlayerControllerClass = AEchoesMenuPlayerController::StaticClass();
	
	// No pawn needed in menu
	DefaultPawnClass = nullptr;
}
