// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Http.h"
#include "EchoesServerAuthSubsystem.generated.h"

/**
 * UEchoesServerAuthSubsystem
 * 
 * Server-side subsystem for validating client JWT tokens through Backend API
 * Used by UE Dedicated Server to authenticate connecting players
 * 
 * Architecture:
 * - GameInstanceSubsystem: Available on server instance
 * - Validates tokens via HTTP POST to /api/auth/validate-token
 * - Checks AccountSession.IsActive and expiration
 * - Prevents unauthorized access to game servers
 */
UCLASS()
class ECHOES_API UEchoesServerAuthSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	// Subsystem lifecycle
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	/**
	 * Validate JWT token from client through Backend API
	 * Makes HTTP POST request to /api/auth/validate-token
	 * 
	 * @param Token - JWT token from connecting client
	 * @param OnSuccess - Callback with CharacterId and AccountId if valid
	 * @param OnFailure - Callback with error message if invalid
	 */
	void ValidateClientToken(
		const FString& Token,
		TFunction<void(const FGuid& CharacterId, const FGuid& AccountId)> OnSuccess,
		TFunction<void(const FString& Error)> OnFailure
	);

protected:
	/**
	 * Handle token validation response from Backend API
	 */
	void OnValidateTokenResponseReceived(
		FHttpRequestPtr Request,
		FHttpResponsePtr Response,
		bool bWasSuccessful,
		TFunction<void(const FGuid&, const FGuid&)> OnSuccess,
		TFunction<void(const FString&)> OnFailure
	);

	/**
	 * Get API base URL from configuration
	 */
	FString GetApiBaseUrl() const;

private:
	/** HTTP module reference */
	FHttpModule* Http;
};
