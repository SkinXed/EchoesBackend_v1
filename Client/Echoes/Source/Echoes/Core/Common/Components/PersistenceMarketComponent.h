// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EchoesMarketStructures.h"
#include "PersistenceMarketComponent.generated.h"

class UEchoesMarketSubsystem;

/** Fired when trading availability changes (entered/exited trading hub range) */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTradingAvailabilityChanged, bool, bCanTrade);

/**
 * UPersistenceMarketComponent
 * 
 * Actor Component that gates market access based on proximity to trading hubs
 * Attach to player ships to enable market trading when near stations/stargates
 * 
 * Architecture:
 * - Uses timer-based proximity check (every 0.5s) instead of Tick for performance
 * - Caches nearby station/stargate references instead of GetAllActorsOfClass each check
 * - Delegates market API calls to UEchoesMarketSubsystem
 * - Client_ prefix: Methods called from client UI
 * - ServerOnly_ prefix: Methods for server-authoritative checks
 */
UCLASS(ClassGroup=(Echoes), meta=(BlueprintSpawnableComponent))
class ECHOES_API UPersistenceMarketComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPersistenceMarketComponent();

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	// ==================== Properties ====================

	/** Maximum distance to a trading hub for market access (in Unreal units / cm) */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Echoes|Market")
	float TradingDistance = 2000.0f;

	/** Interval for proximity check (seconds) */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Echoes|Market")
	float ProximityCheckInterval = 0.5f;

	// ==================== Server-Only Functions ====================

	/**
	 * Check if the owning actor is near a trading hub (Station or Stargate)
	 * Uses squared distance comparison for performance
	 * 
	 * @return True if within TradingDistance of any trading hub
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Market")
	bool ServerOnly_IsNearTradingHub() const;

	// ==================== Client Functions ====================

	/**
	 * Request market data from the backend via MarketSubsystem
	 * Only succeeds if bCanTrade is true (player near trading hub)
	 * 
	 * @param Filter - Market filter (RegionId, ItemId, display options)
	 * @return True if request was sent, false if not near trading hub
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Market")
	bool Client_RequestMarketData(const FMarketFilter& Filter);

	/**
	 * Check current trading availability
	 * @return True if trading is currently available
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Market")
	bool CanTrade() const { return bCanTrade; }

	// ==================== Delegates ====================

	/** Fired when trading availability changes */
	UPROPERTY(BlueprintAssignable, Category = "Echoes|Market|Events")
	FOnTradingAvailabilityChanged OnTradingAvailabilityChanged;

protected:
	/** Timer callback for proximity checks */
	void CheckTradingProximity();

	/** Cache trading hub actors from the world */
	void CacheTradingHubs();

private:
	/** Current trading availability state */
	bool bCanTrade = false;

	/** Cached references to trading hub actors (stations/stargates) */
	UPROPERTY()
	TArray<AActor*> CachedTradingHubs;

	/** Timer handle for proximity checks */
	FTimerHandle ProximityCheckTimerHandle;

	/** Reference to market subsystem */
	UPROPERTY()
	UEchoesMarketSubsystem* MarketSubsystem = nullptr;

	/** Whether trading hubs have been cached */
	bool bHubsCached = false;
};
