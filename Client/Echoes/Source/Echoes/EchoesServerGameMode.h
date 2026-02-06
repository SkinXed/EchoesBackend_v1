// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Http.h"
#include "EchoesServerGameMode.generated.h"

class UEchoesServerManagementSubsystem;
class AEchoesWorldGenerator;
class UEchoesInventorySubsystem;

// Delegate for entry flow completion
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEntryFlowComplete);

/**
 * Character location data structure (mirrors backend CharacterLocationDto)
 */
USTRUCT(BlueprintType)
struct FCharacterLocationData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	FGuid CharacterId;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	bool IsDocked = false;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	bool InWarp = false;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	FGuid StationId;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	FString StationName;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	FGuid SolarSystemId;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	FString SolarSystemName;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	double PositionX = 0.0;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	double PositionY = 0.0;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	double PositionZ = 0.0;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	FGuid HangarInstanceId;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	int32 ActiveShipTypeId = 0;
};

/**
 * AEchoesServerGameMode
 * 
 * Server GameMode - The Conductor/Orchestrator
 * Manages world generation and player lifecycle on dedicated servers
 * 
 * Architecture:
 * - Server-only execution (HasAuthority())
 * - Coordinates with UEchoesServerManagementSubsystem for configuration
 * - Triggers AEchoesWorldGenerator when config is ready
 * - Handles player login and spawn logic
 * 
 * Workflow:
 * 1. BeginPlay: Check if server config is already received
 * 2. PostLogin: Verify world is generated before spawning players
 * 3. If config ready: Trigger world generation
 * 4. Track world generation state
 */
UCLASS()
class ECHOES_API AEchoesServerGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AEchoesServerGameMode();

	// ==================== Entry Flow Delegate ====================

	/** Fired when player is fully spawned and ready to play */
	UPROPERTY(BlueprintAssignable, Category = "Echoes|Entry")
	FOnEntryFlowComplete OnEntryFlowComplete;

protected:
	// ==================== GameMode Lifecycle ====================

	virtual void BeginPlay() override;

	/**
	 * Called when player successfully logs in
	 * Verifies world is generated before allowing spawn
	 */
	virtual void PostLogin(APlayerController* NewPlayer) override;

	/**
	 * Called when player logs out
	 */
	virtual void Logout(AController* Exiting) override;

	/**
	 * Override to prevent automatic player spawning until token validation completes
	 * This ensures players stay in loading screen until authenticated
	 */
	virtual void HandleStartingNewPlayer(APlayerController* NewPlayer) override;

public:
	// ==================== World Generation Control ====================

	/**
	 * Check if world has been generated
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Server")
	bool IsWorldGenerated() const { return bWorldGenerated; }

	/**
	 * Get the jump manager (for stargate jumps)
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Server")
	UEchoesJumpManager* GetJumpManager() const { return JumpManager; }

	/**
	 * Manually trigger world generation (for testing)
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Server", meta = (DevelopmentOnly))
	void TriggerWorldGeneration();

	/**
	 * Spawn player at their last known location
	 * Checks character location from API and spawns accordingly
	 */
	void SpawnPlayerAtLocation(APlayerController* PlayerController);

	/**
	 * Query character location from backend API
	 * @param CharacterId - Character GUID to query
	 * @param Token - JWT authentication token
	 * @param PlayerController - Player controller for spawn callback
	 */
	void QueryCharacterLocation(const FGuid& CharacterId, const FString& Token, APlayerController* PlayerController);

	/**
	 * Handle character location response from API
	 */
	void OnCharacterLocationReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful, APlayerController* PlayerController, FString Token);

	/**
	 * Perform spawn after location data is received
	 */
	void PerformSpawnWithLocationData(const FCharacterLocationData& LocationData, APlayerController* PlayerController);

	/**
	 * Extract login options from connection URL
	 * @param Options - URL options string
	 * @param OutToken - Extracted JWT token
	 * @param OutCharacterId - Extracted character ID
	 * @return True if extraction successful
	 */
	bool ExtractLoginOptions(const FString& Options, FString& OutToken, FGuid& OutCharacterId);

	/**
	 * Spawn player at station (docked state)
	 * @param PC - Player controller
	 * @param CharacterId - Character/Player GUID for hangar isolation
	 * @param StationId - Station GUID
	 * @param ShipTypeId - Active ship type ID for mesh lookup
	 * @param HangarInstanceId - Unique hangar instance ID for player isolation
	 */
	void SpawnPlayerAtStation(APlayerController* PC, const FGuid& CharacterId, const FGuid& StationId, int32 ShipTypeId, const FGuid& HangarInstanceId);

	/**
	 * Spawn player in space
	 * @param PC - Player controller
	 * @param Position - World position
	 * @param Rotation - World rotation
	 * @param ShipTypeId - Active ship type ID for mesh lookup
	 */
	void SpawnPlayerInSpace(APlayerController* PC, const FVector& Position, const FRotator& Rotation, int32 ShipTypeId);

	/**
	 * Get API base URL from configuration
	 */
	FString GetApiBaseUrl() const;

	/**
	 * Kick player back to menu map with logging
	 * @param Player - Player controller to kick
	 * @param Reason - Reason for kicking (for logging)
	 */
	void KickPlayerToMenu(APlayerController* Player, const FString& Reason);

	/**
	 * Request player undocking from station
	 * Moves player from hangar instance back to space near station
	 * @param PC - Player controller requesting undock
	 */
	void RequestUndock(APlayerController* PC);

protected:
	// ==================== Internal Logic ====================

	/**
	 * Called when server configuration is received from backend
	 * Triggers world generation process
	 */
	UFUNCTION()
	void OnServerConfigReceived(const struct FServerSystemConfig& Config);

	/**
	 * Initialize world generator and trigger generation
	 */
	void InitializeWorldGeneration();

	/**
	 * Find or spawn world generator actor
	 */
	AEchoesWorldGenerator* GetOrCreateWorldGenerator();

private:
	// ==================== References ====================

	/** Reference to server management subsystem */
	UPROPERTY()
	UEchoesServerManagementSubsystem* ServerManagementSubsystem;

	/** Reference to world generator */
	UPROPERTY()
	AEchoesWorldGenerator* WorldGenerator;

	/** Jump manager for intra-server jumps */
	UPROPERTY()
	class UEchoesJumpManager* JumpManager;

	/** HTTP module reference */
	FHttpModule* Http;

	/** Inventory subsystem reference */
	UPROPERTY()
	UEchoesInventorySubsystem* InventorySubsystem;

	/** Hangar manager for player isolation */
	UPROPERTY()
	class AEchoesHangarManager* HangarManager;

	// ==================== State ====================

	/** Whether world has been generated */
	UPROPERTY()
	bool bWorldGenerated;

	/** Whether we're waiting for config */
	UPROPERTY()
	bool bWaitingForConfig;

	/** Whether we've subscribed to config delegate */
	UPROPERTY()
	bool bSubscribedToConfigDelegate;

	/** Per-player spawn authorization tracking (PlayerController -> bSpawnAllowed) */
	TMap<APlayerController*, bool> PlayerSpawnAuthorization;

	/** Menu map path for kicking unauthenticated players */
	static constexpr const TCHAR* MenuMapPath = TEXT("/Game/Maps/MenuMap");
};
