// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EchoesKillmailStructures.generated.h"

/**
 * Single attacker entry in a killmail
 * Represents one player who participated in a ship destruction
 */
USTRUCT(BlueprintType)
struct FKillmailAttacker
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Killmail")
	FGuid CharacterId;

	UPROPERTY(BlueprintReadWrite, Category = "Killmail")
	FString CharacterName;

	UPROPERTY(BlueprintReadWrite, Category = "Killmail")
	FGuid CorporationId;

	UPROPERTY(BlueprintReadWrite, Category = "Killmail")
	int32 ShipTypeId = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Killmail")
	FString ShipTypeName;

	UPROPERTY(BlueprintReadWrite, Category = "Killmail")
	FString WeaponTypeName;

	UPROPERTY(BlueprintReadWrite, Category = "Killmail")
	double DamageDealt = 0.0;

	UPROPERTY(BlueprintReadWrite, Category = "Killmail")
	bool IsFinalBlow = false;
};

/**
 * Single item entry in a killmail (dropped or destroyed)
 * Used for both the 50/50 drop roll results
 */
USTRUCT(BlueprintType)
struct FKillmailItem
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Killmail")
	int32 ItemTypeId = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Killmail")
	FString ItemName;

	UPROPERTY(BlueprintReadWrite, Category = "Killmail")
	int32 Quantity = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Killmail")
	double EstimatedValue = 0.0;

	/** Where this item was: Cargo, HighSlot, MidSlot, LowSlot, RigSlot */
	UPROPERTY(BlueprintReadWrite, Category = "Killmail")
	FString Location;
};

/**
 * Full killmail data for a ship destruction event
 * Mirrors the backend KillmailReportRequest DTO
 */
USTRUCT(BlueprintType)
struct FKillmailData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Killmail")
	FGuid KillmailId;

	UPROPERTY(BlueprintReadWrite, Category = "Killmail")
	FGuid VictimId;

	UPROPERTY(BlueprintReadWrite, Category = "Killmail")
	FString VictimName;

	UPROPERTY(BlueprintReadWrite, Category = "Killmail")
	FGuid FinalStrikerId;

	UPROPERTY(BlueprintReadWrite, Category = "Killmail")
	FString FinalStrikerName;

	UPROPERTY(BlueprintReadWrite, Category = "Killmail")
	FGuid SolarSystemId;

	UPROPERTY(BlueprintReadWrite, Category = "Killmail")
	FString SolarSystemName;

	UPROPERTY(BlueprintReadWrite, Category = "Killmail")
	int32 ShipTypeId = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Killmail")
	FString ShipTypeName;

	UPROPERTY(BlueprintReadWrite, Category = "Killmail")
	double TotalLossValue = 0.0;

	UPROPERTY(BlueprintReadWrite, Category = "Killmail")
	TArray<FKillmailAttacker> Attackers;

	UPROPERTY(BlueprintReadWrite, Category = "Killmail")
	TArray<FKillmailItem> DroppedItems;

	UPROPERTY(BlueprintReadWrite, Category = "Killmail")
	TArray<FKillmailItem> DestroyedItems;

	UPROPERTY(BlueprintReadWrite, Category = "Killmail")
	FDateTime KilledAt;
};

/**
 * Entry in the damage map: tracks how much damage each attacker dealt
 * Used by ServerOnly_HandleDestruction to determine attackers list
 */
USTRUCT(BlueprintType)
struct FDamageMapEntry
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Killmail")
	FGuid AttackerId;

	UPROPERTY(BlueprintReadWrite, Category = "Killmail")
	FString AttackerName;

	UPROPERTY(BlueprintReadWrite, Category = "Killmail")
	FGuid AttackerCorporationId;

	UPROPERTY(BlueprintReadWrite, Category = "Killmail")
	int32 AttackerShipTypeId = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Killmail")
	FString AttackerShipTypeName;

	UPROPERTY(BlueprintReadWrite, Category = "Killmail")
	FString LastWeaponUsed;

	UPROPERTY(BlueprintReadWrite, Category = "Killmail")
	double TotalDamage = 0.0;
};
