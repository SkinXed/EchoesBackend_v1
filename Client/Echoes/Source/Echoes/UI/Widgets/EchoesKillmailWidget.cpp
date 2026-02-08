// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesKillmailWidget.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"

void UEchoesKillmailWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UEchoesKillmailWidget::SetKillmailData(const FKillmailData& InKillmailData)
{
	StoredKillmailData = InKillmailData;

	// Populate header
	if (VictimNameText)
	{
		VictimNameText->SetText(FText::FromString(StoredKillmailData.VictimName));
	}

	if (ShipTypeText)
	{
		ShipTypeText->SetText(FText::FromString(StoredKillmailData.ShipTypeName));
	}

	if (SystemNameText)
	{
		SystemNameText->SetText(FText::FromString(StoredKillmailData.SolarSystemName));
	}

	// Format total loss with ISK suffix
	if (TotalLossText)
	{
		FString LossStr;
		if (StoredKillmailData.TotalLossValue >= 1000000000.0)
		{
			LossStr = FString::Printf(TEXT("%.2fB ISK"), StoredKillmailData.TotalLossValue / 1000000000.0);
		}
		else if (StoredKillmailData.TotalLossValue >= 1000000.0)
		{
			LossStr = FString::Printf(TEXT("%.2fM ISK"), StoredKillmailData.TotalLossValue / 1000000.0);
		}
		else if (StoredKillmailData.TotalLossValue >= 1000.0)
		{
			LossStr = FString::Printf(TEXT("%.2fK ISK"), StoredKillmailData.TotalLossValue / 1000.0);
		}
		else
		{
			LossStr = FString::Printf(TEXT("%.2f ISK"), StoredKillmailData.TotalLossValue);
		}
		TotalLossText->SetText(FText::FromString(LossStr));
	}

	// Format timestamp
	if (TimestampText)
	{
		TimestampText->SetText(FText::FromString(StoredKillmailData.KilledAt.ToString(TEXT("%Y-%m-%d %H:%M"))));
	}

	// Find and display final blow attacker
	if (FinalBlowText)
	{
		FString FinalBlowName = TEXT("Unknown");
		for (const FKillmailAttacker& Att : StoredKillmailData.Attackers)
		{
			if (Att.IsFinalBlow)
			{
				FinalBlowName = Att.CharacterName.IsEmpty() ? TEXT("Unknown") : Att.CharacterName;
				break;
			}
		}
		FinalBlowText->SetText(FText::FromString(FinalBlowName));
	}

	if (AttackerCountText)
	{
		AttackerCountText->SetText(FText::FromString(
			FString::Printf(TEXT("%d"), StoredKillmailData.Attackers.Num())));
	}

	// Populate attacker entries via Blueprint events
	for (const FKillmailAttacker& Attacker : StoredKillmailData.Attackers)
	{
		OnAddAttackerEntry(Attacker);
	}

	// Populate dropped items (green — survived)
	for (const FKillmailItem& Item : StoredKillmailData.DroppedItems)
	{
		OnAddDroppedItemEntry(Item);
	}

	// Populate destroyed items (red — lost)
	for (const FKillmailItem& Item : StoredKillmailData.DestroyedItems)
	{
		OnAddDestroyedItemEntry(Item);
	}

	// Notify Blueprint for any custom formatting
	OnKillmailDataSet(StoredKillmailData);
}
