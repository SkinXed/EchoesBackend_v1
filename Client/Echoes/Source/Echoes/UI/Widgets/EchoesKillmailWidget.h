// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EchoesKillmailStructures.h"
#include "EchoesKillmailWidget.generated.h"

class UTextBlock;
class UVerticalBox;
class UImage;
class UBorder;

/**
 * UEchoesKillmailWidget
 * 
 * Killmail display widget (zkillboard-style)
 * Shows: who killed whom, in what ship, lost items, and total value
 * 
 * Layout:
 * - Header: Victim name + ship type + solar system
 * - Attackers list: who participated, with damage dealt
 * - Items section: dropped (green) and destroyed (red) items
 * - Footer: total ISK lost
 * 
 * Usage:
 * - Create a widget blueprint based on this class
 * - Call SetKillmailData() with a FKillmailData struct
 * - Widget auto-populates all bound text blocks
 */
UCLASS()
class ECHOES_API UEchoesKillmailWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	/**
	 * Populate the widget with killmail data
	 * @param InKillmailData - Full killmail data to display
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Combat|UI")
	void SetKillmailData(const FKillmailData& InKillmailData);

protected:
	virtual void NativeConstruct() override;

	// ==================== Widget Bindings ====================

	/** Victim's character name */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Killmail")
	UTextBlock* VictimNameText;

	/** Ship type that was destroyed */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Killmail")
	UTextBlock* ShipTypeText;

	/** Solar system name */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Killmail")
	UTextBlock* SystemNameText;

	/** Total ISK loss value */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Killmail")
	UTextBlock* TotalLossText;

	/** Timestamp of the kill */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Killmail")
	UTextBlock* TimestampText;

	/** Final blow attacker name */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Killmail")
	UTextBlock* FinalBlowText;

	/** Number of attackers */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Killmail")
	UTextBlock* AttackerCountText;

	/** Container for attacker entries (populated at runtime) */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetOptional), Category = "Killmail")
	UVerticalBox* AttackersBox;

	/** Container for dropped items (populated at runtime) */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetOptional), Category = "Killmail")
	UVerticalBox* DroppedItemsBox;

	/** Container for destroyed items (populated at runtime) */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetOptional), Category = "Killmail")
	UVerticalBox* DestroyedItemsBox;

	// ==================== Blueprint Events ====================

	/** Called after killmail data is set — use for custom BP formatting */
	UFUNCTION(BlueprintImplementableEvent, Category = "Echoes|Combat|UI")
	void OnKillmailDataSet(const FKillmailData& KillmailData);

	/** Called to add an attacker entry to the attackers list */
	UFUNCTION(BlueprintImplementableEvent, Category = "Echoes|Combat|UI")
	void OnAddAttackerEntry(const FKillmailAttacker& Attacker);

	/** Called to add a dropped item entry */
	UFUNCTION(BlueprintImplementableEvent, Category = "Echoes|Combat|UI")
	void OnAddDroppedItemEntry(const FKillmailItem& Item);

	/** Called to add a destroyed item entry */
	UFUNCTION(BlueprintImplementableEvent, Category = "Echoes|Combat|UI")
	void OnAddDestroyedItemEntry(const FKillmailItem& Item);

private:
	/** Stored killmail data */
	FKillmailData StoredKillmailData;
};
