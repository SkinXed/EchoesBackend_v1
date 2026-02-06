// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Http.h"
#include "CombatServerSubsystem.generated.h"

// Define custom log category for combat
DECLARE_LOG_CATEGORY_EXTERN(LogEchoesCombat, Log, All);

/**
 * UCombatServerSubsystem
 * 
 * Combat Server Subsystem for Echoes Dedicated Server
 * Handles combat-related server operations and communication with ASP.NET Core backend
 * Mirrors CombatController on backend
 * 
 * Architecture:
 * - WorldSubsystem: Persists for the world lifetime (server side only)
 * - Only runs when NetMode == NM_DedicatedServer
 * - All requests to backend must include X-Server-Secret header
 * - Reports player deaths (killmails) to backend for tracking and statistics
 * 
 * Usage:
 * When a player is killed, call ServerOnly_ReportKill() with victim/killer info
 * The backend will log the kill, update statistics, and broadcast to interested clients
 */
UCLASS(Config=Game)
class ECHOES_API UCombatServerSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	// ==================== Subsystem Lifecycle ====================

	/** Initialize subsystem */
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	/** Cleanup subsystem */
	virtual void Deinitialize() override;

	// ==================== Kill Reporting ====================

	/**
	 * Report a player kill to the backend (Killmail)
	 * Called when a player is destroyed in combat
	 * 
	 * @param VictimID - Character ID of the killed player
	 * @param KillerID - Character ID of the attacking player
	 * @param SolarSystemID - Solar system ID where the kill occurred
	 * @param ShipType - Type of ship that was destroyed
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Combat")
	void ServerOnly_ReportKill(
		int32 VictimID,
		int32 KillerID,
		int32 SolarSystemID,
		const FString& ShipType);

protected:
	// ==================== HTTP Response Handlers ====================

	/**
	 * Handle killmail response from backend
	 */
	void OnKillmailResponseReceived(
		FHttpRequestPtr Request,
		FHttpResponsePtr Response,
		bool bWasSuccessful);

	// ==================== Helper Functions ====================

	/**
	 * Get API base URL from configuration (DefaultGame.ini)
	 */
	FString GetApiBaseUrl() const;

	/**
	 * Get server secret from configuration (DefaultGame.ini)
	 * Used for X-Server-Secret header authentication
	 */
	FString GetServerSecret() const;

	/**
	 * Get killmail endpoint from configuration with fallback
	 */
	FString GetKillmailEndpoint() const;

	/**
	 * Check if this is a dedicated server
	 */
	bool IsDedicatedServer() const;

	/**
	 * Create HTTP request with server secret header
	 */
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> CreateAuthenticatedRequest(
		const FString& Verb,
		const FString& Endpoint);

private:
	// ==================== Configuration (from DefaultGame.ini) ====================

	/** Backend API base URL */
	UPROPERTY(Config)
	FString BackendURL;

	/** Server secret for authentication (X-Server-Secret header) */
	UPROPERTY(Config)
	FString ServerSecret;

	/** API endpoint for killmail reporting */
	UPROPERTY(Config)
	FString KillmailEndpoint;

	/** HTTP module reference */
	FHttpModule* Http;
};
