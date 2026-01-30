// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Http.h"
#include "EchoesServerDiscoveryTypes.h"
#include "EchoesServerManagementSubsystem.generated.h"

// Define custom log category
DECLARE_LOG_CATEGORY_EXTERN(LogEchoesServer, Log, All);

/**
 * Delegate for when server configuration is received from backend
 * Used by WorldGenerator to spawn planets, stargates, stations, etc.
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnServerConfigReceived, const FServerSystemConfig&, Config);

/**
 * UEchoesServerManagementSubsystem
 * 
 * Server Management Subsystem for Echoes Dedicated Server
 * Handles server lifecycle, registration, heartbeat, and configuration sync with ASP.NET Core backend
 * 
 * Architecture:
 * - GameInstanceSubsystem: Persists across level transitions (server side only)
 * - Only runs when NetMode == NM_DedicatedServer
 * - All requests to backend must include X-Server-Secret header
 * - Backend is the source of truth for all server state
 * 
 * Lifecycle:
 * 1. Initialize() - Called on server startup, triggers registration
 * 2. ServerOnly_Register() - The Handshake with backend
 * 3. ServerOnly_StartHeartbeat() - Begin 30-second heartbeat timer
 * 4. ServerOnly_GetConfig() - Fetch universe configuration from backend
 * 5. Deinitialize() - Graceful shutdown, unregister from backend
 */
UCLASS(Config=Game)
class ECHOES_API UEchoesServerManagementSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	// ==================== Subsystem Lifecycle ====================

	/** Initialize subsystem on server startup */
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	/** Graceful shutdown and unregister from backend */
	virtual void Deinitialize() override;

	// ==================== Public Delegates ====================

	/** Broadcast when server configuration is received (WorldGenerator subscribes to this) */
	UPROPERTY(BlueprintAssignable, Category = "Echoes|Server")
	FOnServerConfigReceived OnServerConfigReceived;

	// ==================== Server Registration ====================

	/**
	 * Register this server with the backend (The Handshake)
	 * Called automatically during Initialize() if running as dedicated server
	 * Can also be triggered manually from GameMode
	 * 
	 * @param InstanceId - Unique GUID for this server instance
	 * @param GamePort - Port for game connections
	 * @param SolarSystemId - Solar system this server hosts (for DedicatedSystem mode)
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Server")
	void ServerOnly_Register(
		const FString& InstanceId,
		int32 GamePort = 7777,
		const FGuid& SolarSystemId = FGuid());

	/**
	 * Send heartbeat to backend with current metrics
	 * Called automatically every 30 seconds by timer
	 * If backend returns 404 (server not found), triggers re-registration
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Server")
	void ServerOnly_Heartbeat();

	/**
	 * Request universe configuration from backend
	 * Called automatically after successful registration
	 * Response triggers OnServerConfigReceived delegate
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Server")
	void ServerOnly_GetConfig();

	/**
	 * Unregister server from backend (graceful shutdown)
	 * Called automatically during Deinitialize()
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Server")
	void ServerOnly_Unregister();

	// ==================== Getters ====================

	/**
	 * Get the unique instance ID for this server
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Server")
	FString GetInstanceId() const { return ServerInstanceId; }

	/**
	 * Check if server is registered with backend
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Server")
	bool IsServerRegistered() const { return bIsRegistered; }

	/**
	 * Get server ID assigned by backend
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Server")
	FGuid GetServerId() const { return ServerId; }

protected:
	// ==================== HTTP Response Handlers ====================

	/**
	 * Handle registration response from backend
	 */
	void OnRegisterResponseReceived(
		FHttpRequestPtr Request,
		FHttpResponsePtr Response,
		bool bWasSuccessful);

	/**
	 * Handle heartbeat response from backend
	 */
	void OnHeartbeatResponseReceived(
		FHttpRequestPtr Request,
		FHttpResponsePtr Response,
		bool bWasSuccessful);

	/**
	 * Handle configuration response from backend
	 */
	void OnConfigResponseReceived(
		FHttpRequestPtr Request,
		FHttpResponsePtr Response,
		bool bWasSuccessful);

	/**
	 * Handle unregister response from backend
	 */
	void OnUnregisterResponseReceived(
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
	 * Check if this is a dedicated server
	 */
	bool IsDedicatedServer() const;

	/**
	 * Collect current server metrics for heartbeat
	 */
	void Auth_CollectServerMetrics(
		float& OutCPUUsage,
		int64& OutMemoryUsageMB,
		int32& OutPlayersCount);

	/**
	 * Start heartbeat timer (30 seconds interval)
	 */
	void ServerOnly_StartHeartbeat();

	/**
	 * Stop heartbeat timer
	 */
	void ServerOnly_StopHeartbeat();

	/**
	 * Create HTTP request with server secret header
	 */
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Auth_CreateAuthenticatedRequest(
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

	// ==================== Server State ====================

	/** Unique instance ID for this server (GUID) */
	UPROPERTY()
	FString ServerInstanceId;

	/** Server ID assigned by backend after registration */
	UPROPERTY()
	FGuid ServerId;

	/** Whether server is registered with backend */
	UPROPERTY()
	bool bIsRegistered = false;

	/** Solar system ID this server hosts (for DedicatedSystem mode) */
	UPROPERTY()
	FGuid CurrentSolarSystemId;

	/** Game port for client connections */
	UPROPERTY()
	int32 GamePort = 7777;

	/** Node type: "DedicatedSystem" or "RegionalCluster" */
	UPROPERTY()
	FString NodeType;

	/** Cached server configuration received from backend */
	UPROPERTY()
	FServerSystemConfig CachedConfig;

	// ==================== Heartbeat Timer ====================

	/** Timer handle for heartbeat loop */
	FTimerHandle HeartbeatTimerHandle;

	/** HTTP module reference */
	FHttpModule* Http;
};
