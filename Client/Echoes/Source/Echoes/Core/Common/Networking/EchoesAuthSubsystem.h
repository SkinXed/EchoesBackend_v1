// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Http.h"
#include "EchoesCharacterData.h"
#include "EchoesAuthSubsystem.generated.h"

/**
 * Auth request structure (mirrors C# LoginRequestDto)
 */
USTRUCT(BlueprintType)
struct FAuthRequest
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Auth")
	FString EmailOrUsername;

	UPROPERTY(BlueprintReadWrite, Category = "Auth")
	FString Password;
};

/**
 * Character info structure (mirrors C# CharacterInfoDto)
 */
USTRUCT(BlueprintType)
struct FCharacterInfo
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	FGuid CharacterId;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	FString Name;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	int32 RaceId = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	FString RaceName;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	int64 WalletBalance = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	int64 Credits = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	int32 ExperiencePoints = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	int64 CurrentShipId = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	bool IsMain = false;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	bool IsOnline = false;
};

/**
 * Auth response structure (mirrors C# AuthResponseDto)
 */
USTRUCT(BlueprintType)
struct FAuthResponse
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Auth")
	bool Success = false;

	UPROPERTY(BlueprintReadWrite, Category = "Auth")
	FString Token;

	UPROPERTY(BlueprintReadWrite, Category = "Auth")
	FGuid AccountId;

	UPROPERTY(BlueprintReadWrite, Category = "Auth")
	FGuid CharacterId;

	UPROPERTY(BlueprintReadWrite, Category = "Auth")
	FString CharacterName;

	UPROPERTY(BlueprintReadWrite, Category = "Auth")
	FGuid SessionId;

	UPROPERTY(BlueprintReadWrite, Category = "Auth")
	FDateTime ExpiresAt;

	UPROPERTY(BlueprintReadWrite, Category = "Auth")
	TArray<FCharacterInfo> Characters;
};

DECLARE_DYNAMIC_DELEGATE_OneParam(FOnLoginSuccess, const FAuthResponse&, AuthResponse);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnLoginFailure, const FString&, ErrorMessage);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnRegisterSuccess, const FAuthResponse&, AuthResponse);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnRegisterFailure, const FString&, ErrorMessage);

// New delegates for character operations
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCharacterCreated, const FCharacterData&, CharacterData);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCharacterCreationFailed, const FString&, ErrorMessage);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnConnectInfoReceived, const FString&, ServerIP, int32, ServerPort);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnConnectInfoFailed, const FString&, ErrorMessage);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCharacterDeleted, const FGuid&, CharacterId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCharacterDeletionFailed, const FString&, ErrorMessage);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCharacterListUpdated, const TArray<FCharacterInfo>&, Characters);

/**
 * UEchoesAuthSubsystem
 * 
 * Authentication subsystem for Echoes MMO
 * Handles login, registration, and token management
 * 
 * Architecture:
 * - GameInstanceSubsystem: Persists across level transitions
 * - Communicates with ASP.NET Core backend
 * - Stores JWT token securely
 * - Provides token to other subsystems (Inventory, Ship Stats)
 */
UCLASS()
class ECHOES_API UEchoesAuthSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	// Subsystem lifecycle
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// ==================== Auth Functions ====================

	/**
	 * Login to backend with email/username and password
	 * Sends HTTP POST to /api/auth/login
	 * 
	 * @param Request - Login credentials
	 * @param OnSuccess - Callback on successful login
	 * @param OnFailure - Callback on login failure
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Auth")
	void Auth_Login(
		const FAuthRequest& Request,
		FOnLoginSuccess OnSuccess,
		FOnLoginFailure OnFailure);

	/**
	 * Register new account
	 * Sends HTTP POST to /api/auth/register
	 * 
	 * @param Username - Desired username
	 * @param Email - Email address
	 * @param Password - Password
	 * @param OnSuccess - Callback on successful registration
	 * @param OnFailure - Callback on registration failure
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Auth")
	void Auth_Register(
		const FString& Username,
		const FString& Email,
		const FString& Password,
		FOnRegisterSuccess OnSuccess,
		FOnRegisterFailure OnFailure);

	/**
	 * Save auth token to disk (optional)
	 * @param bRemember - True to remember token across sessions
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Auth")
	void SaveAuthToken(bool bRemember);

	/**
	 * Get current JWT token
	 * Used by other subsystems (Inventory, ShipStats) to authenticate requests
	 * 
	 * @return JWT token string
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Auth")
	FString Auth_GetToken() const { return JWTToken; }

	/**
	 * Get account ID from current session
	 * 
	 * @return Account GUID
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Auth")
	FGuid Auth_GetAccountId() const { return CurrentAuthResponse.AccountId; }

	/**
	 * Get character ID from current session
	 * 
	 * @return Character GUID
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Auth")
	FGuid Auth_GetCharacterId() const { return CurrentAuthResponse.CharacterId; }

	/**
	 * Check if user is logged in
	 * 
	 * @return True if valid token exists
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Auth")
	bool Auth_IsLoggedIn() const { return !JWTToken.IsEmpty(); }

	/**
	 * Get list of characters for current account
	 * 
	 * @return Array of character info
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Auth")
	TArray<FCharacterInfo> Auth_GetCharacters() const { return CurrentAuthResponse.Characters; }

	/**
	 * Logout (clear token and session data from memory)
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Auth")
	void Auth_Logout();

	// ==================== Character Operations ====================

	/**
	 * Create new character
	 * @param CharacterName - Name for the new character
	 * @param RaceId - Race ID (1=Caldari, 2=Gallente, 3=Amarr, 4=Minmatar)
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Character")
	void CreateCharacter(const FString& CharacterName, int32 RaceId);

	UFUNCTION(BlueprintCallable, Category = "Echoes|Character")
	void DeleteCharacter(const FGuid& CharacterId);

	/**
	 * Fetch character list from backend
	 * Updates CurrentAuthResponse.Characters
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Character")
	void FetchCharacterList();

	/**
	 * Connect to world with selected character
	 * 
	 * IMPORTANT: This initiates an ASYNC multi-step authentication flow:
	 * 
	 * STEP 1 (Client-side):
	 *   - Request server connection info from backend API
	 *   - Includes JWT token in Authorization header
	 * 
	 * STEP 2 (Client-side):
	 *   - Receive server IP and port
	 *   - Perform ClientTravel with Token and CharacterId in URL parameters
	 *   - Client begins connecting to dedicated server
	 * 
	 * STEP 3 (Server-side - PostLogin):
	 *   - Dedicated server extracts Token and CharacterId from connection URL
	 *   - Server validates token with backend API
	 *   - If INVALID: Player is kicked back to menu
	 *   - If VALID: Continue to Step 4
	 * 
	 * STEP 4 (Server-side - After validation):
	 *   - Server authorizes player spawn
	 *   - Query character location from backend
	 *   - Spawn player at correct location (space or station)
	 *   - Load character HUD/widget
	 *   - Broadcast OnEntryFlowComplete
	 * 
	 * @param CharacterId - Character to connect with
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Character")
	void ConnectToWorld(const FGuid& CharacterId);

	// ==================== Delegates ====================

	/** Fired when character is created successfully */
	UPROPERTY(BlueprintAssignable, Category = "Echoes|Character")
	FOnCharacterCreated OnCharacterCreated;

	/** Fired when character creation fails */
	UPROPERTY(BlueprintAssignable, Category = "Echoes|Character")
	FOnCharacterCreationFailed OnCharacterCreationFailed;

	/** Fired when connection info is received */
	UPROPERTY(BlueprintAssignable, Category = "Echoes|Character")
	FOnConnectInfoReceived OnConnectInfoReceived;

	/** Fired when connection info request fails */
	UPROPERTY(BlueprintAssignable, Category = "Echoes|Character")
	FOnConnectInfoFailed OnConnectInfoFailed;

	/** Fired when character is deleted successfully */
	UPROPERTY(BlueprintAssignable, Category = "Echoes|Character")
	FOnCharacterDeleted OnCharacterDeleted;

	/** Fired when character deletion fails */
	UPROPERTY(BlueprintAssignable, Category = "Echoes|Character")
	FOnCharacterDeletionFailed OnCharacterDeletionFailed;

	/** Fired when character list is updated */
	UPROPERTY(BlueprintAssignable, Category = "Echoes|Character")
	FOnCharacterListUpdated OnCharacterListUpdated;

	/**
	 * Server RPC: Verify session token
	 * Used by UE Server to validate player session with backend
	 * 
	 * @param CharacterId - Character attempting to connect
	 * @param OnSuccess - Callback with character data
	 * @param OnFailure - Callback on validation failure
	 */
	void ServerRPC_VerifySession(
		const FGuid& CharacterId,
		TFunction<void(const FCharacterData&)> OnSuccess,
		TFunction<void(const FString&)> OnFailure);

	/**
	 * Set auth session data from token validation
	 */
	void SetAuthSession(
		const FString& Token,
		const FGuid& AccountId,
		const FGuid& CharacterId,
		const FString& CharacterName,
		const TArray<FCharacterInfo>& Characters);

protected:
	// ==================== HTTP Request Handlers ====================

	/**
	 * Handle login response from backend
	 */
	void OnLoginResponseReceived(
		FHttpRequestPtr Request,
		FHttpResponsePtr Response,
		bool bWasSuccessful,
		FOnLoginSuccess OnSuccess,
		FOnLoginFailure OnFailure);

	/**
	 * Handle registration response from backend
	 */
	void OnRegisterResponseReceived(
		FHttpRequestPtr Request,
		FHttpResponsePtr Response,
		bool bWasSuccessful,
		FOnRegisterSuccess OnSuccess,
		FOnRegisterFailure OnFailure);

	/**
	 * Handle session verification response
	 */
	void OnVerifySessionResponseReceived(
		FHttpRequestPtr Request,
		FHttpResponsePtr Response,
		bool bWasSuccessful,
		TFunction<void(const FCharacterData&)> OnSuccess,
		TFunction<void(const FString&)> OnFailure);

	/**
	 * Handle character creation response
	 */
	void OnCreateCharacterResponseReceived(
		FHttpRequestPtr Request,
		FHttpResponsePtr Response,
		bool bWasSuccessful);

	void OnDeleteCharacterResponseReceived(
		FHttpRequestPtr Request,
		FHttpResponsePtr Response,
		bool bWasSuccessful,
		FGuid CharacterId);

	/**
	 * Handle character list fetch response
	 */
	void OnFetchCharacterListResponseReceived(
		FHttpRequestPtr Request,
		FHttpResponsePtr Response,
		bool bWasSuccessful);

	/**
	 * Handle connect info response
	 */
	void OnConnectInfoResponseReceived(
		FHttpRequestPtr Request,
		FHttpResponsePtr Response,
		bool bWasSuccessful,
		FGuid CharacterId);

	// ==================== Helper Functions ====================

	/**
	 * Parse auth response JSON from backend
	 */
	bool ParseAuthResponse(const FString& JsonString, FAuthResponse& OutResponse);

	/**
	 * Parse character data JSON from backend
	 */
	bool ParseCharacterData(const FString& JsonString, FCharacterData& OutData);

	/**
	 * Get API base URL from configuration
	 */
	FString GetApiBaseUrl() const;

	/**
	 * Get server secret from configuration
	 */
	FString GetServerSecret() const;

private:
	// ==================== Protected Members ====================

	/** Current JWT token */
	UPROPERTY()
	FString JWTToken;

	/** Current auth response (includes account info, character list) */
	UPROPERTY()
	FAuthResponse CurrentAuthResponse;

	/** HTTP module reference */
	FHttpModule* Http;
};
