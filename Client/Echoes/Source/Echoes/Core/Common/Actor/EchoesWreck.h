// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EchoesKillmailStructures.h"
#include "EchoesWreck.generated.h"

/** Loot access right entry */
USTRUCT(BlueprintType)
struct FWreckAccessEntry
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Wreck")
	FGuid CharacterId;

	UPROPERTY(BlueprintReadWrite, Category = "Wreck")
	FGuid CorporationId;
};

DECLARE_LOG_CATEGORY_EXTERN(LogEchoesWreck, Log, All);

/**
 * AEchoesWreck
 * 
 * Wreck container actor spawned after ship destruction
 * Contains surviving items from the 50/50 drop roll
 * Implements "loot rights" — only kill participants (and corpmates)
 * can loot without getting Suspect flag
 * 
 * Lifetime: Auto-despawns after WreckLifetimeSeconds (default: 2 hours)
 */
UCLASS()
class ECHOES_API AEchoesWreck : public AActor
{
	GENERATED_BODY()

public:
	AEchoesWreck();

	virtual void BeginPlay() override;

	// ==================== Server-Only Functions ====================

	/**
	 * Initialize wreck with loot from a killed ship
	 * @param InDroppedItems - Items that survived the 50/50 roll
	 * @param InAccessList - Characters/corps with loot rights
	 * @param InKillmailId - Associated killmail for tracking
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Wreck")
	void ServerOnly_InitializeWreck(
		const TArray<FKillmailItem>& InDroppedItems,
		const TArray<FWreckAccessEntry>& InAccessList,
		const FGuid& InKillmailId);

	/**
	 * Check if a character has loot rights (participated in kill or is corpmate)
	 * @param CharacterId - Character attempting to loot
	 * @param CorporationId - Corporation of the character
	 * @return True if can loot without Suspect flag
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Wreck")
	bool ServerOnly_HasLootRights(const FGuid& CharacterId, const FGuid& CorporationId) const;

	/**
	 * Remove an item from the wreck (looted by a player)
	 * @param ItemTypeId - Type of item to take
	 * @param Quantity - Amount to take
	 * @return True if item was successfully removed
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Wreck")
	bool ServerOnly_TakeItem(int32 ItemTypeId, int32 Quantity);

	// ==================== Accessors ====================

	UFUNCTION(BlueprintPure, Category = "Echoes|Wreck")
	TArray<FKillmailItem> GetContents() const { return DroppedItems; }

	UFUNCTION(BlueprintPure, Category = "Echoes|Wreck")
	FGuid GetKillmailId() const { return KillmailId; }

	UFUNCTION(BlueprintPure, Category = "Echoes|Wreck")
	bool IsEmpty() const { return DroppedItems.Num() == 0; }

protected:
	/** Items in the wreck (surviving loot) */
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Wreck")
	TArray<FKillmailItem> DroppedItems;

	/** Characters and corporations with loot rights */
	UPROPERTY(BlueprintReadOnly, Category = "Wreck")
	TArray<FWreckAccessEntry> AccessList;

	/** Associated killmail ID */
	UPROPERTY(BlueprintReadOnly, Category = "Wreck")
	FGuid KillmailId;

	/** Wreck auto-despawn time (2 hours default) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wreck|Config")
	float WreckLifetimeSeconds = 7200.0f;

private:
	/** Timer for auto-despawn */
	FTimerHandle DespawnTimerHandle;

	/** Auto-despawn callback */
	void OnWreckExpired();
};
