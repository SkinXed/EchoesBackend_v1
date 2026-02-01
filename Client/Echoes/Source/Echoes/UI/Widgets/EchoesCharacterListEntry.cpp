// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesCharacterListEntry.h"
#include "Widgets/EchoesCharacterSelectWidget.h"

void UEchoesCharacterListEntry::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	UE_LOG(LogTemp, Log, TEXT("CharacterListEntry: NativeOnListItemObjectSet"));
	UCharacterListItem* Item = Cast<UCharacterListItem>(ListItemObject);

	if (Item)
	{
		UE_LOG(LogTemp, Log, TEXT("CharacterListEntry: Item=%s"), *Item->CharacterInfo.Name);
		if (NameText)
		{
			if (Item->CharacterInfo.Name.IsEmpty())
			{
				NameText->SetText(FText::FromString("Unknown Pilot"));
			}
			else
			{
				NameText->SetText(FText::FromString(Item->CharacterInfo.Name));
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("CharacterListEntry: NameText not bound"));
		}

		if (RaceText)
		{
			FString DisplayRace = Item->RaceName.IsEmpty() ? TEXT("Human") : Item->RaceName;
			RaceText->SetText(FText::FromString(DisplayRace));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("CharacterListEntry: RaceText not bound"));
		}

		if (!AvatarImage)
		{
			UE_LOG(LogTemp, Log, TEXT("CharacterListEntry: AvatarImage not bound"));
		}

		UE_LOG(LogTemp, Log, TEXT("UI Entry Updated: %s (%s)"), *Item->CharacterInfo.Name, *Item->RaceName);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("CharacterListEntry: ListItemObject is not UCharacterListItem"));
	}
}
