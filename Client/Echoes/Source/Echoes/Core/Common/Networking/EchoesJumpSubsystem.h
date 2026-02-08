// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Http.h"
#include "EchoesJumpSubsystem.generated.h"

// Forward declarations
class UEchoesPersistenceSubsystem;
class APawn;

/**
 * Structure for jump request data
 */
USTRUCT(BlueprintType)
struct FJumpRequestData
{
	GENERATED_BODY()

	/** Character ID making the jump */
	UPROPERTY(BlueprintReadWrite, Category = "Jump")
	FGuid CharacterId;

	/** Stargate being used */
	UPROPERTY(BlueprintReadWrite, Category = "Jump")
	FGuid StargateId;

	/** Source system */
	UPROPERTY(BlueprintReadWrite, Category = "Jump")
	FGuid SourceSystemId;

	/** Destination system */
	UPROPERTY(BlueprintReadWrite, Category = "Jump")
	FGuid DestinationSystemId;

	FJumpRequestData()
		: CharacterId(FGuid())
		, StargateId(FGuid())
		, SourceSystemId(FGuid())
		, DestinationSystemId(FGuid())
	{
	}
};

/**
 * Structure for jump response from backend
 */
USTRUCT(BlueprintType)
struct FJumpResponseData
{
	GENERATED_BODY()

	/** Whether the jump was approved */
	UPROPERTY(BlueprintReadWrite, Category = "Jump")
	bool bSuccess;

	/** Jump ticket ID */
	UPROPERTY(BlueprintReadWrite, Category = "Jump")
	FString TicketId;

	/** Destination server address (IP:Port) */
	UPROPERTY(BlueprintReadWrite, Category = "Jump")
	FString DestinationServerAddress;

	/** Destination system name */
	UPROPERTY(BlueprintReadWrite, Category = "Jump")
	FString DestinationSystemName;

	/** Message from server */
	UPROPERTY(BlueprintReadWrite, Category = "Jump")
	FString Message;

	/** Reason for denial (if not successful) */
	UPROPERTY(BlueprintReadWrite, Category = "Jump")
	FString DenialReason;

	FJumpResponseData()
		: bSuccess(false)
		, TicketId(TEXT(""))
		, DestinationServerAddress(TEXT(""))
		, DestinationSystemName(TEXT(""))
		, Message(TEXT(""))
		, DenialReason(TEXT(""))
	{
	}
};

/**
 * Delegate for jump request completion
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnJumpRequestComplete, bool, bSuccess, const FJumpResponseData&, Response);

/**
 * Delegate for jump initiation
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnJumpInitiated, const FString&, TravelURL, const FString&, TicketId);

/**
 * UEchoesJumpSubsystem
 * 
 * Manages interstellar jumps between game systems via stargates.
 * Handles session handover with secure ticket-based authentication.
 * 
 * Architecture:
 * 1. Client initiates jump at stargate
 * 2. Server saves character state immediately
 * 3. Server requests jump ticket from backend
 * 4. Client travels to new server with ticket
 * 5. New server validates ticket before spawning character
 */
UCLASS(Config=Game)
class ECHOES_API UEchoesJumpSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	// USubsystem interface
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	/**
	 * Request a jump for a character through a stargate
	 * SERVER ONLY - Called by source game server
	 * 
	 * @param CharacterId - Character making the jump
	 * @param StargateId - Stargate being used
	 * @param SourceSystemId - Current system
	 * @param DestinationSystemId - Target system
	 * @param PlayerPawn - Player's pawn for state collection
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Jump", meta = (DisplayName = "ServerOnly - Request Jump"))
	void ServerOnly_RequestJump(
		FGuid CharacterId,
		FGuid StargateId,
		FGuid SourceSystemId,
		FGuid DestinationSystemId,
		APawn* PlayerPawn = nullptr);

	/**
	 * Validate a jump ticket on the destination server
	 * SERVER ONLY - Called when player connects to new server
	 * 
	 * @param TicketId - Ticket ID from connection URL
	 * @param CharacterId - Character ID to validate
	 * @param SystemId - Current system ID
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Jump", meta = (DisplayName = "ServerOnly - Validate Jump Ticket"))
	void ServerOnly_ValidateJumpTicket(
		const FString& TicketId,
		FGuid CharacterId,
		FGuid SystemId);

	// C++ overload that accepts a delegate callback (not exposed to Blueprints)
	void ServerOnly_ValidateJumpTicket(
		const FString& TicketId,
		FGuid CharacterId,
		FGuid SystemId,
		FOnJumpRequestComplete& OnComplete);

	/**
	 * Client RPC to initiate travel to destination server
	 * Sends client to new server with jump ticket
	 * 
	 * @param TravelURL - Destination server address with ticket
	 * @param TicketId - Jump ticket for authentication
	 * @param SystemName - Destination system name (for UI)
	 */
	UFUNCTION(Client, Reliable, Category = "Echoes|Jump")
	void ClientRPC_TravelToSystem(const FString& TravelURL, const FString& TicketId, const FString& SystemName);

	/** Delegate fired when jump request completes */
	UPROPERTY(BlueprintAssignable, Category = "Echoes|Jump")
	FOnJumpRequestComplete OnJumpRequestComplete;

	/** Delegate fired when jump is initiated (client travel starts) */
	UPROPERTY(BlueprintAssignable, Category = "Echoes|Jump")
	FOnJumpInitiated OnJumpInitiated;

protected:
	/** API base URL for jump endpoints */
	UPROPERTY(Config)
	FString ApiBaseUrl;

	/** Server secret for authentication */
	UPROPERTY(Config)
	FString ServerSecret;

	/** Whether to enable verbose logging */
	UPROPERTY(Config)
	bool bEnableDebugLogging;

private:
	/**
	 * Send HTTP request to backend for jump ticket
	 */
	void SendJumpRequest(const FJumpRequestData& RequestData, APawn* PlayerPawn);

	/**
	 * Handle jump request response from backend
	 */
	void OnJumpRequestComplete_Internal(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful, APawn* PlayerPawn);

	/**
	 * Send HTTP request to validate jump ticket
	 */
	void SendTicketValidationRequest(const FString& TicketId, FGuid CharacterId, FGuid SystemId, FOnJumpRequestComplete Callback);

	/**
	 * Handle ticket validation response
	 */
	void OnTicketValidationComplete_Internal(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful, FOnJumpRequestComplete Callback);

	/**
	 * Build travel URL with ticket parameter
	 */
	FString BuildTravelURL(const FString& ServerAddress, const FString& TicketId) const;

	/**
	 * Save character state immediately before jump
	 */
	bool SaveCharacterStateBeforeJump(FGuid CharacterId, APawn* PlayerPawn);
};
