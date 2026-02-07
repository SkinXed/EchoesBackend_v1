// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesWreck.h"
#include "Net/UnrealNetwork.h"
#include "TimerManager.h"

DEFINE_LOG_CATEGORY(LogEchoesWreck);

AEchoesWreck::AEchoesWreck()
{
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true;
	bAlwaysRelevant = true;
}

void AEchoesWreck::BeginPlay()
{
	Super::BeginPlay();

	// Start despawn timer on server
	if (HasAuthority() && WreckLifetimeSeconds > 0.0f)
	{
		GetWorldTimerManager().SetTimer(
			DespawnTimerHandle,
			this,
			&AEchoesWreck::OnWreckExpired,
			WreckLifetimeSeconds,
			false);

		UE_LOG(LogEchoesWreck, Log, TEXT("Wreck spawned: KillmailId=%s, Items=%d, Lifetime=%.0fs"),
			*KillmailId.ToString(), DroppedItems.Num(), WreckLifetimeSeconds);
	}
}

void AEchoesWreck::ServerOnly_InitializeWreck(
	const TArray<FKillmailItem>& InDroppedItems,
	const TArray<FWreckAccessEntry>& InAccessList,
	const FGuid& InKillmailId)
{
	if (!HasAuthority()) return;

	DroppedItems = InDroppedItems;
	AccessList = InAccessList;
	KillmailId = InKillmailId;

	UE_LOG(LogEchoesWreck, Log, TEXT("[WRECK INIT] KillmailId=%s, DroppedItems=%d, AccessEntries=%d"),
		*KillmailId.ToString(), DroppedItems.Num(), AccessList.Num());
}

bool AEchoesWreck::ServerOnly_HasLootRights(const FGuid& CharacterId, const FGuid& CorporationId) const
{
	for (const FWreckAccessEntry& Entry : AccessList)
	{
		// Direct character match (attacker)
		if (Entry.CharacterId.IsValid() && Entry.CharacterId == CharacterId)
		{
			return true;
		}

		// Corporation match (corpmate of attacker)
		if (Entry.CorporationId.IsValid() && CorporationId.IsValid() && Entry.CorporationId == CorporationId)
		{
			return true;
		}
	}

	return false;
}

bool AEchoesWreck::ServerOnly_TakeItem(int32 ItemTypeId, int32 Quantity)
{
	if (!HasAuthority()) return false;

	for (int32 i = DroppedItems.Num() - 1; i >= 0; --i)
	{
		if (DroppedItems[i].ItemTypeId == ItemTypeId)
		{
			// Clamp quantity to what's available
			int32 ActualQuantity = FMath::Min(Quantity, DroppedItems[i].Quantity);

			if (ActualQuantity >= DroppedItems[i].Quantity)
			{
				UE_LOG(LogEchoesWreck, Log, TEXT("[WRECK LOOT] Took all %d x %s from wreck %s"),
					DroppedItems[i].Quantity, *DroppedItems[i].ItemName, *KillmailId.ToString());
				DroppedItems.RemoveAt(i);
			}
			else
			{
				DroppedItems[i].Quantity -= ActualQuantity;
				UE_LOG(LogEchoesWreck, Log, TEXT("[WRECK LOOT] Took %d x %s from wreck %s (%d remaining)"),
					ActualQuantity, *DroppedItems[i].ItemName, *KillmailId.ToString(), DroppedItems[i].Quantity);
			}

			// Auto-destroy if empty
			if (DroppedItems.Num() == 0)
			{
				UE_LOG(LogEchoesWreck, Log, TEXT("[WRECK EMPTY] Wreck %s is now empty, scheduling destroy"),
					*KillmailId.ToString());
				SetLifeSpan(5.0f);
			}

			return true;
		}
	}

	return false;
}

void AEchoesWreck::OnWreckExpired()
{
	UE_LOG(LogEchoesWreck, Log, TEXT("[WRECK EXPIRED] Wreck %s despawning after %.0fs, Items remaining: %d"),
		*KillmailId.ToString(), WreckLifetimeSeconds, DroppedItems.Num());
	Destroy();
}

void AEchoesWreck::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AEchoesWreck, DroppedItems);
}
