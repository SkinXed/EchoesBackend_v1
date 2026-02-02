// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesCharacterListEntry.h"
#include "Widgets/EchoesCharacterSelectWidget.h"
#include "Components/Button.h"
#include "Components/ListView.h"

void UEchoesCharacterListEntry::NativeConstruct()
{
	Super::NativeConstruct();

	if (LoginButton)
	{
		LoginButton->OnClicked.AddDynamic(this, &UEchoesCharacterListEntry::OnLoginButtonClicked);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("CharacterListEntry: LoginButton not bound"));
	}
}

void UEchoesCharacterListEntry::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	UE_LOG(LogTemp, Log, TEXT("CharacterListEntry: NativeOnListItemObjectSet"));
	UCharacterListItem* Item = Cast<UCharacterListItem>(ListItemObject);

	if (Item)
	{
		CachedListItem = Item;
		CachedCharacterId = Item->CharacterInfo.CharacterId;
		UE_LOG(LogTemp, Log, TEXT("CharacterListEntry: Item=%s"), *Item->CharacterInfo.Name);
		if (NameText)
		{
			if (Item->CharacterInfo.Name.IsEmpty())
			{
				NameText->SetText(FText::FromString(" Pilot"));
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

		if (CreditsText)
		{
			CreditsText->SetText(FText::AsNumber(Item->CharacterInfo.Credits));
		}

		if (ExperienceText)
		{
			ExperienceText->SetText(FText::AsNumber(Item->CharacterInfo.ExperiencePoints));
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

void UEchoesCharacterListEntry::OnLoginButtonClicked()
{
	UEchoesCharacterSelectWidget* ParentWidget = GetTypedOuter<UEchoesCharacterSelectWidget>();
	if (ParentWidget)
	{
		if (ParentWidget->CharacterList && CachedListItem)
		{
			UObject* SelectedItem = ParentWidget->CharacterList->GetSelectedItem();
			if (SelectedItem != CachedListItem)
			{
				ParentWidget->CharacterList->SetSelectedItem(CachedListItem);
				return;
			}
		}

		ParentWidget->LaunchCharacter(CachedCharacterId);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Error: ListEntry cannot find parent EchoesCharacterSelectWidget!"));
	}
}
