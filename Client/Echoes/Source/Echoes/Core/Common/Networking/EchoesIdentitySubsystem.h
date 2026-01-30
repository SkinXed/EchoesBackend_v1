// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Http.h"
#include "EchoesIdentitySubsystem.generated.h"

/**
 * Character structure (mirrors C# CharacterDataDto)
 * Common_ prefix for shared data structures
 */
USTRUCT(BlueprintType)
struct FEchoesCharacter
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	FGuid CharacterId;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	FString Name;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	FGuid AccountId;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	int64 WalletBalance = 0;

	/** ISK balance (alias for WalletBalance for EVE-style naming) */
	UPROPERTY(BlueprintReadWrite, Category = "Character")
	int64 ISK = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	float SecurityStatus = 0.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	int64 CurrentShipId = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	FGuid CorporationId;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	int32 RaceId = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	int32 TotalSkillPoints = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	int32 UnallocatedSkillPoints = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	bool IsOnline = false;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	bool IsDocked = true;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	bool InWarp = false;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	FDateTime LastLogin;

	/** Portrait URL for UI display */
	UPROPERTY(BlueprintReadWrite, Category = "Character")
	FString PortraitURL;
};


DECLARE_DYNAMIC_DELEGATE_OneParam(FOnCharacterDataReceived, const FEchoesCharacter&, CharacterData);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnCharacterDataFailure, const FString&, ErrorMessage);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCharacterSelected);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnCharacterCreated, const FEchoesCharacter&, CharacterData);

/**
 * UEchoesIdentitySubsystem
 * 
 * Character management subsystem for Echoes MMO
 * Handles character selection and data retrieval
 * 
 * Architecture:
 * - GameInstanceSubsystem: Persists across level transitions
 * - Requires valid JWT token from UEchoesAuthSubsystem
 * - Communicates with ASP.NET Core backend
 * - Provides character data to UI and gameplay systems
 * 
 * Naming Conventions:
 * - Identity_ prefix: Character management functions
 * - Common_ prefix: Shared data structures
 * - ServerRPC_ prefix: Server-side notifications
 */
UCLASS()
class ECHOES_API UEchoesIdentitySubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	// Subsystem lifecycle
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// ==================== Identity Functions ====================

	/**
	 * Fetch current character data from backend
	 * Sends HTTP GET to /api/character/me with JWT token
	 * 
	 * @param OnSuccess - Callback with character data
	 * @param OnFailure - Callback on request failure
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Identity")
	void Identity_FetchCharacter(
		FOnCharacterDataReceived OnSuccess,
		FOnCharacterDataFailure OnFailure);

	/**
	 * Select a character and notify system
	 * Saves selected character ID for future operations
	 * Broadcasts OnCharacterSelected delegate
	 * 
	 * @param CharacterId - Character to select
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Identity")
	void Identity_SelectCharacter(const FGuid& CharacterId);

	/**
	 * Get currently selected character data
	 * 
	 * @return Selected character data
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Identity")
	FEchoesCharacter Identity_GetSelectedCharacter() const { return SelectedCharacter; }

	/**
	 * Check if a character is selected
	 * 
	 * @return True if character is selected
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Identity")
	bool Identity_HasSelectedCharacter() const { return SelectedCharacter.CharacterId.IsValid(); }

	/**
	 * Get selected character ID
	 * 
	 * @return Selected character GUID
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Identity")
	FGuid Identity_GetSelectedCharacterId() const { return SelectedCharacter.CharacterId; }

	/**
	 * Clear selected character (logout)
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Identity")
	void Identity_ClearSelection();

	// ==================== UI Wrapper Functions ====================

	/**
	 * UI wrapper: Create a new character
	 * Sends HTTP POST to /api/character with JWT token
	 * 
	 * @param CharacterName - Name for new character
	 * @param Race - Race selection (Caldari, Gallente, Amarr, Minmatar)
	 * @param PortraitId - Portrait ID for character
	 * @param OnSuccess - Callback with created character data
	 * @param OnFailure - Callback on creation failure
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Identity|UI")
	void UI_CreateCharacter(
		const FString& CharacterName,
		const FString& Race,
		int32 PortraitId,
		FOnCharacterCreated OnSuccess,
		FOnCharacterDataFailure OnFailure);

	/**
	 * Server RPC: Notify server that character is ready to enter world
	 * Used by UE Server to validate character before spawning
	 * 
	 * @param CharacterId - Character entering world
	 * @param OnSuccess - Callback on successful validation
	 * @param OnFailure - Callback on validation failure
	 */
	void ServerRPC_NotifyCharacterReady(
		const FGuid& CharacterId,
		TFunction<void()> OnSuccess,
		TFunction<void(const FString&)> OnFailure);

	// ==================== Delegates ====================

	/** Broadcast when character is selected */
	UPROPERTY(BlueprintAssignable, Category = "Echoes|Identity")
	FOnCharacterSelected OnCharacterSelected;

protected:
	// ==================== HTTP Request Handlers ====================

	/**
	 * Handle character data response from backend
	 */
	void OnCharacterDataReceived(
		FHttpRequestPtr Request,
		FHttpResponsePtr Response,
		bool bWasSuccessful,
		FOnCharacterDataReceived OnSuccess,
		FOnCharacterDataFailure OnFailure);

	/**
	 * Handle character ready notification response
	 */
	void OnCharacterReadyResponseReceived(
		FHttpRequestPtr Request,
		FHttpResponsePtr Response,
		bool bWasSuccessful,
		TFunction<void()> OnSuccess,
		TFunction<void(const FString&)> OnFailure);

	/**
	 * Handle character creation response from backend
	 */
	void OnCharacterCreationReceived(
		FHttpRequestPtr Request,
		FHttpResponsePtr Response,
		bool bWasSuccessful,
		FOnCharacterCreated OnSuccess,
		FOnCharacterDataFailure OnFailure);

	// ==================== Helper Functions ====================

	/**
	 * Parse character data JSON from backend
	 */
	bool ParseCharacterData(const FString& JsonString, FEchoesCharacter& OutCharacter);

	/**
	 * Get JWT token from Auth subsystem
	 */
	FString GetAuthToken() const;

	/**
	 * Get API base URL from configuration
	 */
	FString GetApiBaseUrl() const;

private:
	// ==================== Private Members ====================

	/** Currently selected character */
	UPROPERTY()
	FEchoesCharacter SelectedCharacter;

	/** HTTP module reference */
	FHttpModule* Http;
};
