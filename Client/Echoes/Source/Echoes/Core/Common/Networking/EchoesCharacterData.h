// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EchoesCharacterData.generated.h"

/**
 * Character data structure (mirrors C# CharacterDataDto)
 */
USTRUCT(BlueprintType)
struct FCharacterData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	FGuid CharacterId;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	FString Name;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	FGuid AccountId;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	int64 WalletBalance = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	float SecurityStatus = 0.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	int64 CurrentShipId = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	FGuid CorporationId;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	int32 RaceId = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	int32 TotalSkillPoints = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	int32 UnallocatedSkillPoints = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	bool IsOnline = false;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	bool IsDocked = true;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	bool InWarp = false;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	FDateTime LastLogin;
};
