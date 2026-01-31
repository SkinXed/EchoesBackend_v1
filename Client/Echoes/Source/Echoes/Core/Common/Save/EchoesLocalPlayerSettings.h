// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "EchoesLocalPlayerSettings.generated.h"

/**
 * UEchoesLocalPlayerSettings
 * 
 * Save game class for persistent local player settings
 * Stores JWT token, character selection, and preferences
 * 
 * Usage:
 * - AuthSubsystem saves token when "Remember Me" is checked
 * - Preload widget loads token on cold start
 * - Persists between game sessions
 */
UCLASS()
class ECHOES_API UEchoesLocalPlayerSettings : public USaveGame
{
	GENERATED_BODY()

public:
	UEchoesLocalPlayerSettings();

	// ==================== Saved Data ====================

	/** Saved JWT authentication token */
	UPROPERTY()
	FString SavedAuthToken;

	/** Saved character ID (last selected) */
	UPROPERTY()
	FGuid SavedCharacterId;

	/** Account ID associated with token */
	UPROPERTY()
	FGuid SavedAccountId;

	/** When the token was saved */
	UPROPERTY()
	FDateTime TokenSavedAt;

	/** Token expiration time */
	UPROPERTY()
	FDateTime TokenExpiresAt;

	/** Remember me flag */
	UPROPERTY()
	bool bRememberMe;

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

	// ==================== Instance Methods ====================

	/**
	 * Check if saved token is still valid (not expired)
	 */
	bool IsTokenValid() const;

	/**
	 * Clear all saved data
	 */
	void Clear();
};
