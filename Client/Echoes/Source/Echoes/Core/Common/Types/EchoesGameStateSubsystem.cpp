// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesGameStateSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

void UEchoesGameStateSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	CurrentState = EEchoesGameState::Login;
	
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
		}
	}
}
