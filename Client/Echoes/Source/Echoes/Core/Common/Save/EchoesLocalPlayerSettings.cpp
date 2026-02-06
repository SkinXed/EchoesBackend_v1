// Copyright Epic Games, Inc. All Rights Reserved.

#include "Core/Common/Save/EchoesLocalPlayerSettings.h"
#include "Kismet/GameplayStatics.h"

UEchoesLocalPlayerSettings::UEchoesLocalPlayerSettings()
{
	// Initialize with default values for future settings
}

UEchoesLocalPlayerSettings* UEchoesLocalPlayerSettings::LoadSettings()
{
	FString SlotName = GetSaveSlotName();
	
	if (UGameplayStatics::DoesSaveGameExist(SlotName, 0))
	{
		USaveGame* LoadedGame = UGameplayStatics::LoadGameFromSlot(SlotName, 0);
		UEchoesLocalPlayerSettings* Settings = Cast<UEchoesLocalPlayerSettings>(LoadedGame);
		
		if (Settings)
		{
			UE_LOG(LogTemp, Log, TEXT("Loaded LocalPlayerSettings"));
			return Settings;
		}
	}

	// Create new settings if none exist
	UE_LOG(LogTemp, Log, TEXT("Creating new LocalPlayerSettings"));
	return Cast<UEchoesLocalPlayerSettings>(UGameplayStatics::CreateSaveGameObject(UEchoesLocalPlayerSettings::StaticClass()));
}

bool UEchoesLocalPlayerSettings::SaveSettings(UEchoesLocalPlayerSettings* Settings)
{
	if (!Settings)
	{
		UE_LOG(LogTemp, Error, TEXT("Cannot save null settings"));
		return false;
	}

	FString SlotName = GetSaveSlotName();
	bool bSuccess = UGameplayStatics::SaveGameToSlot(Settings, SlotName, 0);
	
	if (bSuccess)
	{
		UE_LOG(LogTemp, Log, TEXT("Saved LocalPlayerSettings to slot: %s"), *SlotName);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to save LocalPlayerSettings"));
	}

	return bSuccess;
}

FString UEchoesLocalPlayerSettings::GetSaveSlotName()
{
	return TEXT("EchoesLocalPlayerSettings");
}
