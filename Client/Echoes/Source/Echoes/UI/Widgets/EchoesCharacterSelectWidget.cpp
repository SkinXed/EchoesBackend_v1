// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesCharacterSelectWidget.h"
#include "Components/ListView.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/EditableTextBox.h"
#include "Components/ComboBoxString.h"
#include "Components/Widget.h"
#include "Kismet/GameplayStatics.h"

void UEchoesCharacterSelectWidget::NativeConstruct()
{
	Super::NativeConstruct();
	UE_LOG(LogTemp, Log, TEXT("CharacterSelect: NativeConstruct"));

	if (UGameInstance* GameInstance = GetGameInstance())
	{
		AuthSubsystem = GameInstance->GetSubsystem<UEchoesAuthSubsystem>();
	}
	UE_LOG(LogTemp, Log, TEXT("CharacterSelect: AuthSubsystem=%s"), AuthSubsystem ? TEXT("Valid") : TEXT("Null"));

	if (SelectButton)
	{
		SelectButton->OnClicked.AddDynamic(this, &UEchoesCharacterSelectWidget::OnSelectButtonClicked);
	}
	UE_LOG(LogTemp, Log, TEXT("CharacterSelect: SelectButton=%s"), SelectButton ? TEXT("Bound") : TEXT("Null"));

	if (CreateButton)
	{
		CreateButton->OnClicked.AddDynamic(this, &UEchoesCharacterSelectWidget::OnCreateButtonClicked);
	}
	UE_LOG(LogTemp, Log, TEXT("CharacterSelect: CreateButton=%s"), CreateButton ? TEXT("Bound") : TEXT("Null"));

	if (DeleteButton)
	{
		DeleteButton->OnClicked.AddDynamic(this, &UEchoesCharacterSelectWidget::OnDeleteButtonClicked);
	}
	UE_LOG(LogTemp, Log, TEXT("CharacterSelect: DeleteButton=%s"), DeleteButton ? TEXT("Bound") : TEXT("Null"));

	if (LogoutButton)
	{
		LogoutButton->OnClicked.AddDynamic(this, &UEchoesCharacterSelectWidget::OnLogoutButtonClicked);
	}
	UE_LOG(LogTemp, Log, TEXT("CharacterSelect: LogoutButton=%s"), LogoutButton ? TEXT("Bound") : TEXT("Null"));

	if (ConfirmCreateButton)
	{
		ConfirmCreateButton->OnClicked.AddDynamic(this, &UEchoesCharacterSelectWidget::OnConfirmCreateButtonClicked);
	}
	UE_LOG(LogTemp, Log, TEXT("CharacterSelect: ConfirmCreateButton=%s"), ConfirmCreateButton ? TEXT("Bound") : TEXT("Null"));

	if (CancelCreateButton)
	{
		CancelCreateButton->OnClicked.AddDynamic(this, &UEchoesCharacterSelectWidget::OnCancelCreateButtonClicked);
	}
	UE_LOG(LogTemp, Log, TEXT("CharacterSelect: CancelCreateButton=%s"), CancelCreateButton ? TEXT("Bound") : TEXT("Null"));

	if (RaceComboBox)
	{
		RaceComboBox->OnSelectionChanged.AddDynamic(this, &UEchoesCharacterSelectWidget::OnRaceSelectionChanged);
		if (RaceComboBox->GetOptionCount() == 0)
		{
			RaceComboBox->AddOption(TEXT("Caldari"));
			RaceComboBox->AddOption(TEXT("Gallente"));
			RaceComboBox->AddOption(TEXT("Amarr"));
			RaceComboBox->AddOption(TEXT("Minmatar"));
			RaceComboBox->SetSelectedIndex(0);
		}
	}
	UE_LOG(LogTemp, Log, TEXT("CharacterSelect: RaceComboBox=%s"), RaceComboBox ? TEXT("Bound") : TEXT("Null"));

	if (AuthSubsystem)
	{
		AuthSubsystem->OnCharacterCreated.AddDynamic(this, &UEchoesCharacterSelectWidget::HandleCharacterCreated);
		AuthSubsystem->OnCharacterCreationFailed.AddDynamic(this, &UEchoesCharacterSelectWidget::HandleCharacterCreationFailed);
	}

	SetCreationPanelVisible(false);
	LoadCharacters();
}

void UEchoesCharacterSelectWidget::NativeDestruct()
{
	UE_LOG(LogTemp, Log, TEXT("CharacterSelect: NativeDestruct"));
	Super::NativeDestruct();
}

void UEchoesCharacterSelectWidget::OnSelectButtonClicked()
{
	UE_LOG(LogTemp, Log, TEXT("CharacterSelect: OnSelectButtonClicked"));
	if (!SelectedCharacter)
	{
		SetStatusText("Please select a character", FLinearColor::Yellow);
		return;
	}

	OnCharacterSelected(SelectedCharacter->CharacterInfo.CharacterId);
}

void UEchoesCharacterSelectWidget::OnCreateButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("BUTTON CLICKED: Create"));
	SetCreationPanelVisible(true);
}

void UEchoesCharacterSelectWidget::OnDeleteButtonClicked()
{
	UE_LOG(LogTemp, Log, TEXT("CharacterSelect: OnDeleteButtonClicked"));
	SetStatusText("Character deletion not yet implemented", FLinearColor::Yellow);
}

void UEchoesCharacterSelectWidget::OnLogoutButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("BUTTON CLICKED: Logout"));
	if (AuthSubsystem)
	{
		AuthSubsystem->Auth_Logout();
	}

	UGameplayStatics::OpenLevel(this, FName("EntryMap"));
}

void UEchoesCharacterSelectWidget::OnConfirmCreateButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("UI: Confirm Create Clicked"));
	if (!CharacterNameInput || !RaceComboBox)
	{
		UE_LOG(LogTemp, Warning, TEXT("CharacterSelect: Missing CharacterNameInput or RaceComboBox"));
		return;
	}

	FString CharacterName = CharacterNameInput->GetText().ToString();
	
	// Validate name
	if (CharacterName.IsEmpty() || CharacterName.Len() < 3)
	{
		SetStatusText("Name too short (min 3 chars)", FLinearColor::Red);
		return;
	}

	FString SelectedRace = RaceComboBox->GetSelectedOption();
	int32 RaceId = GetRaceIdFromName(SelectedRace);

	UE_LOG(LogTemp, Warning, TEXT("UI: Sending Create Request: %s, Race: %d"), *CharacterName, RaceId);
	CreateCharacter(CharacterName, RaceId);
}

void UEchoesCharacterSelectWidget::OnCancelCreateButtonClicked()
{
	UE_LOG(LogTemp, Log, TEXT("CharacterSelect: OnCancelCreateButtonClicked"));
	SetCreationPanelVisible(false);
}

void UEchoesCharacterSelectWidget::OnRaceSelectionChanged(FString SelectedItem, ESelectInfo::Type SelectionType)
{
	UE_LOG(LogTemp, Log, TEXT("CharacterSelect: OnRaceSelectionChanged %s"), *SelectedItem);
	int32 RaceId = GetRaceIdFromName(SelectedItem);
	UpdateRaceInfo(RaceId);
}

void UEchoesCharacterSelectWidget::OnCharacterSelected(FGuid CharacterId)
{
	SetStatusText("Initiating Warp Drive...", FLinearColor::Green);
	
	// Формируем URL параметры для GameMode сервера
	FString Options = "?CharacterId=" + CharacterId.ToString();
	
	UE_LOG(LogTemp, Log, TEXT("UI: Travel to GalaxyMap with Options: %s"), *Options);

	// Абсолютный переход (Travel)
	UGameplayStatics::OpenLevel(this, FName("GalaxyMap"), true, Options);
}

void UEchoesCharacterSelectWidget::LoadCharacters()
{
	UE_LOG(LogTemp, Log, TEXT("CharacterSelect: LoadCharacters"));
	if (AuthSubsystem)
	{
		const TArray<FCharacterInfo>& Characters = AuthSubsystem->Auth_GetCharacters();
		UE_LOG(LogTemp, Log, TEXT("CharacterSelect: Auth_GetCharacters=%d"), Characters.Num());
		PopulateCharacterList(Characters);
	}
}

void UEchoesCharacterSelectWidget::CreateCharacter(const FString& Name, int32 RaceId)
{
	UE_LOG(LogTemp, Log, TEXT("CharacterSelect: CreateCharacter Name=%s RaceId=%d"), *Name, RaceId);
	if (bOperationInProgress)
	{
		return;
	}

	if (!AuthSubsystem)
	{
		SetStatusText("Auth subsystem not available", FLinearColor::Red);
		return;
	}

	bOperationInProgress = true;
	SetStatusText("Transmitting neural pattern...", FLinearColor(0.0f, 1.0f, 1.0f, 1.0f));

	AuthSubsystem->CreateCharacter(Name, RaceId);
	SetCreationPanelVisible(false);
}

void UEchoesCharacterSelectWidget::HandleCharacterCreated(const FCharacterData& CharacterData)
{
	UE_LOG(LogTemp, Log, TEXT("CharacterSelect: HandleCharacterCreated %s"), *CharacterData.Name);
	bOperationInProgress = false;
	SetStatusText("Identity confirmed. Neural link established.", FLinearColor::Green);
	SetCreationPanelVisible(false);

	if (CharacterList)
	{
		UCharacterListItem* NewItem = NewObject<UCharacterListItem>(this);
		NewItem->CharacterInfo.CharacterId = CharacterData.CharacterId;
		NewItem->CharacterInfo.Name = CharacterData.Name;
		if (NewItem->CharacterInfo.Name.IsEmpty())
		{
			NewItem->CharacterInfo.Name = "New Pilot";
		}
		NewItem->CharacterInfo.WalletBalance = CharacterData.WalletBalance;

		switch (CharacterData.RaceId)
		{
		case 1:
			NewItem->RaceName = "Caldari";
			break;
		case 2:
			NewItem->RaceName = "Gallente";
			break;
		case 3:
			NewItem->RaceName = "Amarr";
			break;
		case 4:
			NewItem->RaceName = "Minmatar";
			break;
		default:
			NewItem->RaceName = "Unknown";
			break;
		}

		CharacterList->AddItem(NewItem);
		CharacterList->SetSelectedItem(NewItem);
		SelectedCharacter = NewItem;
		UE_LOG(LogTemp, Warning, TEXT("UI: Manually added character %s to list"), *CharacterData.Name);
	}
}

void UEchoesCharacterSelectWidget::HandleCharacterCreationFailed(const FString& ErrorMessage)
{
	UE_LOG(LogTemp, Warning, TEXT("CharacterSelect: HandleCharacterCreationFailed %s"), *ErrorMessage);
	bOperationInProgress = false;
	SetStatusText(ErrorMessage, FLinearColor::Red);
	SetCreationPanelVisible(true);
}

void UEchoesCharacterSelectWidget::PopulateCharacterList(const TArray<FCharacterInfo>& Characters)
{
	UE_LOG(LogTemp, Log, TEXT("CharacterSelect: PopulateCharacterList %d"), Characters.Num());
	if (!CharacterList)
	{
		return;
	}

	CharacterList->ClearListItems();

	for (const FCharacterInfo& CharInfo : Characters)
	{
		UCharacterListItem* ListItem = NewObject<UCharacterListItem>(this);
		ListItem->CharacterInfo = CharInfo;
		ListItem->RaceName = "Unknown";

		CharacterList->AddItem(ListItem);
	}

	SetStatusText(FString::Printf(TEXT("%d character(s) found"), Characters.Num()), FLinearColor::White);
}

void UEchoesCharacterSelectWidget::SetCreationPanelVisible(bool bVisible)
{
	UE_LOG(LogTemp, Log, TEXT("CharacterSelect: SetCreationPanelVisible %s"), bVisible ? TEXT("true") : TEXT("false"));
	if (CreationPanel)
	{
		CreationPanel->SetVisibility(bVisible ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("UI Error: CreationPanel widget not bound!"));
	}

	ESlateVisibility MenuVis = bVisible ? ESlateVisibility::Collapsed : ESlateVisibility::Visible;

	if (CharacterList)
	{
		CharacterList->SetVisibility(MenuVis);
	}

	if (SelectButton)
	{
		SelectButton->SetVisibility(MenuVis);
	}

	if (CreateButton)
	{
		CreateButton->SetVisibility(MenuVis);
	}

	if (DeleteButton)
	{
		DeleteButton->SetVisibility(MenuVis);
	}

	if (LogoutButton)
	{
		LogoutButton->SetVisibility(MenuVis);
	}

	if (bVisible && CharacterNameInput)
	{
		CharacterNameInput->SetText(FText::GetEmpty());
	}
}

void UEchoesCharacterSelectWidget::UpdateRaceInfo(int32 RaceId)
{
	UE_LOG(LogTemp, Log, TEXT("CharacterSelect: UpdateRaceInfo %d"), RaceId);
	FString Description, Bonuses;
	GetRaceDescription(RaceId, Description, Bonuses);

	if (RaceDescriptionText)
	{
		RaceDescriptionText->SetText(FText::FromString(Description));
	}

	if (RaceBonusesText)
	{
		RaceBonusesText->SetText(FText::FromString(Bonuses));
	}
}

int32 UEchoesCharacterSelectWidget::GetRaceIdFromName(const FString& RaceName)
{
	UE_LOG(LogTemp, Log, TEXT("CharacterSelect: GetRaceIdFromName %s"), *RaceName);
	if (RaceName == "Caldari")
		return 1;
	else if (RaceName == "Gallente")
		return 2;
	else if (RaceName == "Amarr")
		return 3;
	else if (RaceName == "Minmatar")
		return 4;
	
	return 1;
}

void UEchoesCharacterSelectWidget::GetRaceDescription(int32 RaceId, FString& OutDescription, FString& OutBonuses)
{
	UE_LOG(LogTemp, Log, TEXT("CharacterSelect: GetRaceDescription %d"), RaceId);
	switch (RaceId)
	{
	case 1:
		OutDescription = "The Caldari State is ruled by several megacorporations. Ruthless, efficient, and technologically advanced.";
		OutBonuses = "- +5% Shield HP\n- +5% Hybrid Turret damage\n- Strong in electronic warfare";
		break;

	case 2:
		OutDescription = "The Gallente Federation is a democracy that values freedom and individual rights above all else.";
		OutBonuses = "- +5% Armor HP\n- +5% Drone damage and hitpoints\n- +10% Scan resolution";
		break;

	case 3:
		OutDescription = "The Amarr Empire is the largest and oldest of the four major empires. Religious and traditionalist.";
		OutBonuses = "- +5% Armor HP\n- +5% Energy weapon damage\n- +10% Capacitor capacity";
		break;

	case 4:
		OutDescription = "The Minmatar Republic was formed over a century ago. Tribal and resilient people.";
		OutBonuses = "- +5% Shield HP\n- +5% Projectile weapon damage\n- +10% Ship velocity";
		break;

	default:
		OutDescription = "Unknown race";
		OutBonuses = "";
		break;
	}
}

void UEchoesCharacterSelectWidget::SetStatusText(const FString& Message, const FLinearColor& Color)
{
	UE_LOG(LogTemp, Log, TEXT("CharacterSelect: SetStatusText %s"), *Message);
	if (StatusText)
	{
		StatusText->SetText(FText::FromString(Message));
		StatusText->SetColorAndOpacity(FSlateColor(Color));
	}
}
