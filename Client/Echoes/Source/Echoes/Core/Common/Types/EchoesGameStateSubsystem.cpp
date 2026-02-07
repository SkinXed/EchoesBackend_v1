// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesGameStateSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Misc/ConfigCacheIni.h"

// Configuration section name for level paths
static const TCHAR* GameStateConfigSection = TEXT("/Script/Echoes.EchoesGameStateSubsystem");

// Forward declarations of globals defined later in this file so functions above can use them
extern FString LoginLevelPath;
extern FString CharacterSelectLevelPath;
extern FString HangarLevelPath;
extern FString SpaceLevelPath;

void UEchoesGameStateSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	CurrentState = EEchoesGameState::Login;
	
	// Load level paths from configuration
	if (!GConfig->GetString(
		GameStateConfigSection,
		TEXT("LoginLevelPath"),
		LoginLevelPath,
		GGameIni))
	{
		// Fallback to default if not configured
		LoginLevelPath = TEXT("/Game/Maps/L_MainMenu");
		UE_LOG(LogTemp, Warning, TEXT("LoginLevelPath not configured, using default: %s"), *LoginLevelPath);
	}

	if (!GConfig->GetString(
		GameStateConfigSection,
		TEXT("CharacterSelectLevelPath"),
		CharacterSelectLevelPath,
		GGameIni))
	{
		CharacterSelectLevelPath = TEXT("/Game/Maps/L_CharacterSelect");
		UE_LOG(LogTemp, Warning, TEXT("CharacterSelectLevelPath not configured, using default: %s"), *CharacterSelectLevelPath);
	}

	if (!GConfig->GetString(
		GameStateConfigSection,
		TEXT("HangarLevelPath"),
		HangarLevelPath,
		GGameIni))
	{
		HangarLevelPath = TEXT("/Game/Maps/L_Hangar");
		UE_LOG(LogTemp, Warning, TEXT("HangarLevelPath not configured, using default: %s"), *HangarLevelPath);
	}

	if (!GConfig->GetString(
		GameStateConfigSection,
		TEXT("SpaceLevelPath"),
		SpaceLevelPath,
		GGameIni))
	{
		SpaceLevelPath = TEXT("/Game/Maps/L_Space");
		UE_LOG(LogTemp, Warning, TEXT("SpaceLevelPath not configured, using default: %s"), *SpaceLevelPath);
	}
	
	UE_LOG(LogTemp, Log, TEXT("EchoesGameStateSubsystem initialized"));
}

void UEchoesGameStateSubsystem::Deinitialize()
{
	Super::Deinitialize();
	
	UE_LOG(LogTemp, Log, TEXT("EchoesGameStateSubsystem deinitialized"));
}

void UEchoesGameStateSubsystem::TransitionToLogin()
{
	UE_LOG(LogTemp, Log, TEXT("Transitioning to Login"));
	
	CurrentState = EEchoesGameState::Login;
	CurrentCharacterId.Empty();
	CurrentShipId.Empty();

	// Open login level
	UWorld* World = GetWorld();
	if (World)
	{
		if (World->GetNetMode() == NM_DedicatedServer || World->GetNetMode() == NM_ListenServer)
		{
			World->ServerTravel(LoginLevelPath);
		}
		else
		{
			// Use ClientTravel for proper multiplayer support
			if (APlayerController* PC = World->GetFirstPlayerController())
			{
				PC->ClientTravel(LoginLevelPath, TRAVEL_Absolute);
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("TransitionToLogin: Cannot transition - PlayerController is null"));
			}
		}
	}
}

void UEchoesGameStateSubsystem::TransitionToCharacterSelect()
{
	UE_LOG(LogTemp, Log, TEXT("Transitioning to Character Select"));
	
	CurrentState = EEchoesGameState::CharacterSelect;

	// Open character select level
	UWorld* World = GetWorld();
	if (World)
	{
		if (World->GetNetMode() == NM_DedicatedServer || World->GetNetMode() == NM_ListenServer)
		{
			World->ServerTravel(CharacterSelectLevelPath);
		}
		else
		{
			// Use ClientTravel for proper multiplayer support
			if (APlayerController* PC = World->GetFirstPlayerController())
			{
				PC->ClientTravel(CharacterSelectLevelPath, TRAVEL_Absolute);
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("TransitionToCharacterSelect: Cannot transition - PlayerController is null"));
			}
		}
	}
}

void UEchoesGameStateSubsystem::TransitionToHangar(const FString& CharacterId)
{
	UE_LOG(LogTemp, Log, TEXT("Transitioning to Hangar for character: %s"), *CharacterId);
	
	CurrentState = EEchoesGameState::Hangar;
	CurrentCharacterId = CharacterId;

	// Open hangar level
	UWorld* World = GetWorld();
	if (World)
	{
		if (World->GetNetMode() == NM_DedicatedServer || World->GetNetMode() == NM_ListenServer)
		{
			World->ServerTravel(HangarLevelPath);
		}
		else
		{
			// Use ClientTravel for proper multiplayer support
			if (APlayerController* PC = World->GetFirstPlayerController())
			{
				PC->ClientTravel(HangarLevelPath, TRAVEL_Absolute);
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("TransitionToHangar: Cannot transition - PlayerController is null"));
			}
		}
	}
}

void UEchoesGameStateSubsystem::TransitionToSpace(const FString& CharacterId, const FString& ShipId)
{
	UE_LOG(LogTemp, Log, TEXT("Transitioning to Space - Character: %s, Ship: %s"), *CharacterId, *ShipId);
	
	CurrentState = EEchoesGameState::InSpace;
	CurrentCharacterId = CharacterId;
	CurrentShipId = ShipId;

	// Open space level
	UWorld* World = GetWorld();
	if (World)
	{
		if (World->GetNetMode() == NM_DedicatedServer || World->GetNetMode() == NM_ListenServer)
		{
			World->ServerTravel(SpaceLevelPath);
		}
		else
		{
			// Use ClientTravel for proper multiplayer support
			if (APlayerController* PC = World->GetFirstPlayerController())
			{
				PC->ClientTravel(SpaceLevelPath, TRAVEL_Absolute);
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("TransitionToSpace: Cannot transition - PlayerController is null"));
			}
		}
	}
}

FString LoginLevelPath;
FString CharacterSelectLevelPath;
FString HangarLevelPath;
FString SpaceLevelPath;
