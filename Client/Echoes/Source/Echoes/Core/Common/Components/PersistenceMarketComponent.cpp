// Copyright Epic Games, Inc. All Rights Reserved.

#include "PersistenceMarketComponent.h"
#include "EchoesMarketSubsystem.h"
#include "StationActor.h"
#include "StargateActor.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

UPersistenceMarketComponent::UPersistenceMarketComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UPersistenceMarketComponent::BeginPlay()
{
	Super::BeginPlay();

	// Get market subsystem reference
	if (UGameInstance* GI = GetWorld()->GetGameInstance())
	{
		MarketSubsystem = GI->GetSubsystem<UEchoesMarketSubsystem>();
	}

	// Cache trading hubs on startup
	CacheTradingHubs();

	// Start periodic proximity check timer (0.5s default)
	if (GetWorld())
	{
		GetWorld()->GetTimerManager().SetTimer(
			ProximityCheckTimerHandle,
			this,
			&UPersistenceMarketComponent::CheckTradingProximity,
			ProximityCheckInterval,
			true);
	}

	UE_LOG(LogTemp, Log, TEXT("PersistenceMarketComponent: Initialized with TradingDistance=%.0f"),
		TradingDistance);
}

void UPersistenceMarketComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	// Clear timer
	if (GetWorld())
	{
		GetWorld()->GetTimerManager().ClearTimer(ProximityCheckTimerHandle);
	}

	Super::EndPlay(EndPlayReason);
}

// ==================== Server-Only Functions ====================

bool UPersistenceMarketComponent::ServerOnly_IsNearTradingHub() const
{
	AActor* Owner = GetOwner();
	if (!Owner)
		return false;

	// Re-cache if needed (e.g. new stations spawned)
	if (!bHubsCached)
	{
		const_cast<UPersistenceMarketComponent*>(this)->CacheTradingHubs();
	}

	const FVector OwnerLocation = Owner->GetActorLocation();
	const float TradingDistanceSq = TradingDistance * TradingDistance;

	for (const AActor* Hub : CachedTradingHubs)
	{
		if (Hub && !Hub->IsPendingKillPending())
		{
			const float DistSq = FVector::DistSquared(OwnerLocation, Hub->GetActorLocation());
			if (DistSq <= TradingDistanceSq)
			{
				return true;
			}
		}
	}

	return false;
}

// ==================== Client Functions ====================

bool UPersistenceMarketComponent::Client_RequestMarketData(const FMarketFilter& Filter)
{
	if (!bCanTrade)
	{
		UE_LOG(LogTemp, Warning, TEXT("PersistenceMarketComponent: Cannot request market data - not near trading hub"));
		return false;
	}

	if (!MarketSubsystem)
	{
		UE_LOG(LogTemp, Error, TEXT("PersistenceMarketComponent: MarketSubsystem not available"));
		return false;
	}

	MarketSubsystem->ServerOnly_FetchMarketOrders(Filter);
	return true;
}

// ==================== Protected Functions ====================

void UPersistenceMarketComponent::CheckTradingProximity()
{
	const bool bWasNearHub = bCanTrade;
	bCanTrade = ServerOnly_IsNearTradingHub();

	// Notify only on state change
	if (bCanTrade != bWasNearHub)
	{
		UE_LOG(LogTemp, Log, TEXT("PersistenceMarketComponent: Trading availability changed: %s"),
			bCanTrade ? TEXT("AVAILABLE") : TEXT("UNAVAILABLE"));
		OnTradingAvailabilityChanged.Broadcast(bCanTrade);
	}
}

void UPersistenceMarketComponent::CacheTradingHubs()
{
	CachedTradingHubs.Empty();

	if (!GetWorld())
		return;

	// Collect all stations
	TArray<AActor*> Stations;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AStationActor::StaticClass(), Stations);
	CachedTradingHubs.Append(Stations);

	// Collect all stargates
	TArray<AActor*> Stargates;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AStargateActor::StaticClass(), Stargates);
	CachedTradingHubs.Append(Stargates);

	bHubsCached = true;

	UE_LOG(LogTemp, Log, TEXT("PersistenceMarketComponent: Cached %d trading hubs (%d stations, %d stargates)"),
		CachedTradingHubs.Num(), Stations.Num(), Stargates.Num());
}
