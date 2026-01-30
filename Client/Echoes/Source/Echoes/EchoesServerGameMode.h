// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EchoesServerGameMode.generated.h"

class UEchoesServerManagementSubsystem;
class AEchoesWorldGenerator;

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
};
