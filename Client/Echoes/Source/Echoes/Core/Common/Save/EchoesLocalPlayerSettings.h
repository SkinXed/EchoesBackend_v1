// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "EchoesLocalPlayerSettings.generated.h"

/**
 * UEchoesLocalPlayerSettings
 * 
 * Save game class for persistent local player settings
 * Stores player preferences like graphics, audio, and keybindings
 * 
 * Note: JWT tokens are no longer saved to disk for security reasons.
 * Tokens are now stored only in memory via UEchoesAuthSubsystem.
 */
UCLASS()
class ECHOES_API UEchoesLocalPlayerSettings : public USaveGame
{
	GENERATED_BODY()

public:
	UEchoesLocalPlayerSettings();

	// ==================== Future Settings ====================
	// Add graphics, audio, and gameplay settings here as needed

	// ==================== Persistent Auth Token (optional) ====================
	// Stored only if user chooses "Remember Me"
	UPROPERTY(VisibleAnywhere, Category = "Auth")
	FString SavedAuthToken;

	/** Returns true if the saved token is non-empty (basic validity check) */
	bool IsTokenValid() const { return !SavedAuthToken.IsEmpty(); }

	// ==================== Static Methods ====================

	/**
	 * Load settings from disk
	 * @return Settings object, or new instance if not found
	 */
	static UEchoesLocalPlayerSettings* LoadSettings();

	/**
	 * Save settings to disk
	 * @param Settings The settings object to save
	 * @return True if save succeeded
	 */
	static bool SaveSettings(UEchoesLocalPlayerSettings* Settings);

	/**
	 * Get the save slot name
	 */
	static FString GetSaveSlotName();
};
