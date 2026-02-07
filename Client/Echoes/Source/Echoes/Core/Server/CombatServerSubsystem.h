// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Http.h"
#include "EchoesKillmailStructures.h"
#include "CombatServerSubsystem.generated.h"

// Define custom log category for combat
DECLARE_LOG_CATEGORY_EXTERN(LogEchoesCombat, Log, All);

/** Delegate fired when a killmail is successfully reported to backend */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnKillmailReported, const FKillmailData&, Killmail);

/** Delegate fired when a killmail report fails */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnKillmailReportFailed, const FString&, ErrorMessage);

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
 * - Handles destruction logic: damage map, 50/50 drop roll, wreck spawning
 * 
 * Usage:
 * 1. Track damage via ServerOnly_RegisterDamage() during combat
 * 2. When CurrentHull reaches 0, call ServerOnly_HandleDestruction()
 * 3. Subsystem calculates drop, spawns wreck, and reports to backend
 */
UCLASS(Config=Game)
class ECHOES_API UCombatServerSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	// ==================== Subsystem Lifecycle ====================

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// ==================== Damage Tracking ====================

	/**
	 * Register damage dealt by an attacker to a victim
	 * Accumulates in a per-victim damage map for killmail generation
	 * 
	 * @param VictimId - Character ID of the ship taking damage
	 * @param AttackerId - Character ID of the attacker
	 * @param AttackerName - Display name of the attacker
	 * @param AttackerCorporationId - Corporation of the attacker (for loot rights)
	 * @param AttackerShipTypeId - Ship type of the attacker
	 * @param AttackerShipTypeName - Ship type name of the attacker
	 * @param WeaponName - Name of the weapon used
	 * @param DamageAmount - Amount of damage dealt
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Combat")
	void ServerOnly_RegisterDamage(
		const FGuid& VictimId,
		const FGuid& AttackerId,
		const FString& AttackerName,
		const FGuid& AttackerCorporationId,
		int32 AttackerShipTypeId,
		const FString& AttackerShipTypeName,
		const FString& WeaponName,
		double DamageAmount);

	/**
	 * Clear damage map for a victim (e.g., when docking or warping safely)
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Combat")
	void ServerOnly_ClearDamageMap(const FGuid& VictimId);

	// ==================== Ship Destruction ====================

	/**
	 * Handle ship destruction: generate killmail, calculate drops, spawn wreck
	 * Called when a ship's CurrentHull reaches 0
	 * 
	 * @param VictimId - Character ID of the destroyed ship's pilot
	 * @param VictimName - Display name of the victim
	 * @param FinalStrikerId - Character ID of who dealt the killing blow
	 * @param SolarSystemId - Solar system where destruction occurred
	 * @param SolarSystemName - Name of the solar system
	 * @param ShipTypeId - Type ID of the destroyed ship
	 * @param ShipTypeName - Name of the destroyed ship type
	 * @param FittedModules - Modules fitted to the ship at time of destruction
	 * @param CargoItems - Items in the ship's cargo hold
	 * @param DestructionLocation - World location to spawn the wreck
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Combat")
	void ServerOnly_HandleDestruction(
		const FGuid& VictimId,
		const FString& VictimName,
		const FGuid& FinalStrikerId,
		const FGuid& SolarSystemId,
		const FString& SolarSystemName,
		int32 ShipTypeId,
		const FString& ShipTypeName,
		const TArray<FKillmailItem>& FittedModules,
		const TArray<FKillmailItem>& CargoItems,
		const FVector& DestructionLocation);

	// ==================== Legacy Kill Reporting ====================

	/**
	 * Simple kill report (legacy compatibility)
	 * Sends minimal killmail to backend without drop calculation
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Combat")
	void ServerOnly_ReportKill(
		int32 VictimID,
		int32 KillerID,
		int32 SolarSystemID,
		const FString& ShipType);

	// ==================== Delegates ====================

	/** Fired when a killmail is successfully reported */
	UPROPERTY(BlueprintAssignable, Category = "Echoes|Combat")
	FOnKillmailReported OnKillmailReported;

	/** Fired when killmail report fails */
	UPROPERTY(BlueprintAssignable, Category = "Echoes|Combat")
	FOnKillmailReportFailed OnKillmailReportFailed;

protected:
	// ==================== HTTP Response Handlers ====================

	void OnKillmailResponseReceived(
		FHttpRequestPtr Request,
		FHttpResponsePtr Response,
		bool bWasSuccessful,
		FKillmailData KillmailData);

	// ==================== Drop Calculation ====================

	/**
	 * Calculate 50/50 drop for each item
	 * Each item has a 50% chance of surviving (going to wreck) or being destroyed
	 * 
	 * @param AllItems - All items (modules + cargo)
	 * @param OutDroppedItems - Items that survive (go to wreck)
	 * @param OutDestroyedItems - Items that are destroyed
	 */
	void CalculateItemDrops(
		const TArray<FKillmailItem>& AllItems,
		TArray<FKillmailItem>& OutDroppedItems,
		TArray<FKillmailItem>& OutDestroyedItems);

	// ==================== Helper Functions ====================

	FString GetApiBaseUrl() const;
	FString GetServerSecret() const;
	FString GetKillmailEndpoint() const;
	bool IsDedicatedServer() const;

	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> CreateAuthenticatedRequest(
		const FString& Verb,
		const FString& Endpoint);

private:
	// ==================== Configuration (from DefaultGame.ini) ====================

	UPROPERTY(Config)
	FString BackendURL;

	UPROPERTY(Config)
	FString ServerSecret;

	UPROPERTY(Config)
	FString KillmailEndpoint;

	/** HTTP module reference */
	FHttpModule* Http;

	/**
	 * Per-victim damage map
	 * Key: VictimId, Value: map of AttackerId -> DamageMapEntry
	 */
	TMap<FGuid, TMap<FGuid, FDamageMapEntry>> DamageMaps;
};
