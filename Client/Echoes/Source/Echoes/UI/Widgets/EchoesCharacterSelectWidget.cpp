// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesCharacterSelectWidget.h"
#include "Components/ListView.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/EditableTextBox.h"
#include "Components/ComboBoxString.h"
#include "Kismet/GameplayStatics.h"

void UEchoesCharacterSelectWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// Set window title
	SetWindowTitle(FText::FromString("Character Selection"));

	// Get auth subsystem
	if (UGameInstance* GameInstance = UGameplayStatics::GetGameInstance(GetWorld()))
	{
		AuthSubsystem = GameInstance->GetSubsystem<UEchoesAuthSubsystem>();
	}

	// Bind button events
	if (SelectButton)
	{
		SelectButton->OnClicked.AddDynamic(this, &UEchoesCharacterSelectWidget::OnSelectButtonClicked);
	}

	if (CreateButton)
	{
		CreateButton->OnClicked.AddDynamic(this, &UEchoesCharacterSelectWidget::OnCreateButtonClicked);
	}

	if (DeleteButton)
	{
		DeleteButton->OnClicked.AddDynamic(this, &UEchoesCharacterSelectWidget::OnDeleteButtonClicked);
	}

	if (LogoutButton)
	{
		LogoutButton->OnClicked.AddDynamic(this, &UEchoesCharacterSelectWidget::OnLogoutButtonClicked);
	}

	if (ConfirmCreateButton)
	{
		ConfirmCreateButton->OnClicked.AddDynamic(this, &UEchoesCharacterSelectWidget::OnConfirmCreateButtonClicked);
	}

	if (CancelCreateButton)
	{
		CancelCreateButton->OnClicked.AddDynamic(this, &UEchoesCharacterSelectWidget::OnCancelCreateButtonClicked);
	}

	// Populate race combo box
	if (RaceComboBox)
	{
		RaceComboBox->AddOption("Caldari");
		RaceComboBox->AddOption("Gallente");
		RaceComboBox->AddOption("Amarr");
		RaceComboBox->AddOption("Minmatar");
		RaceComboBox->SetSelectedIndex(0);
		RaceComboBox->OnSelectionChanged.AddDynamic(this, &UEchoesCharacterSelectWidget::OnRaceSelectionChanged);
	}

	// Hide creation panel initially
	SetCreationPanelVisible(false);

	// Load characters from auth subsystem
	if (AuthSubsystem)
	{
		const TArray<FCharacterInfo>& Characters = AuthSubsystem->Auth_GetCharacters();
		PopulateCharacterList(Characters);
	}

	// Update race info for default selection
	UpdateRaceInfo(1); // Caldari
}

void UEchoesCharacterSelectWidget::NativeDestruct()
{
	// Unbind events
	if (SelectButton)
	{
		SelectButton->OnClicked.RemoveDynamic(this, &UEchoesCharacterSelectWidget::OnSelectButtonClicked);
	}

	if (CreateButton)
	{
		CreateButton->OnClicked.RemoveDynamic(this, &UEchoesCharacterSelectWidget::OnCreateButtonClicked);
	}

	if (DeleteButton)
	{
		DeleteButton->OnClicked.RemoveDynamic(this, &UEchoesCharacterSelectWidget::OnDeleteButtonClicked);
	}

	if (LogoutButton)
	{
		LogoutButton->OnClicked.RemoveDynamic(this, &UEchoesCharacterSelectWidget::OnLogoutButtonClicked);
	}

	if (ConfirmCreateButton)
	{
		ConfirmCreateButton->OnClicked.RemoveDynamic(this, &UEchoesCharacterSelectWidget::OnConfirmCreateButtonClicked);
	}

	if (CancelCreateButton)
	{
		CancelCreateButton->OnClicked.RemoveDynamic(this, &UEchoesCharacterSelectWidget::OnCancelCreateButtonClicked);
	}

	if (RaceComboBox)
	{
		RaceComboBox->OnSelectionChanged.RemoveDynamic(this, &UEchoesCharacterSelectWidget::OnRaceSelectionChanged);
	}

	Super::NativeDestruct();
}

void UEchoesCharacterSelectWidget::OnSelectButtonClicked()
{
	if (!SelectedCharacter)
	{
		SetStatusText("Please select a character", FLinearColor::Yellow);
		return;
	}

	OnCharacterSelected(SelectedCharacter->CharacterInfo.CharacterId);
}

void UEchoesCharacterSelectWidget::OnCreateButtonClicked()
{
	SetCreationPanelVisible(true);
}

void UEchoesCharacterSelectWidget::OnDeleteButtonClicked()
{
	// TODO: Implement character deletion
	SetStatusText("Character deletion not yet implemented", FLinearColor::Yellow);
}

void UEchoesCharacterSelectWidget::OnLogoutButtonClicked()
{
	if (AuthSubsystem)
	{
		AuthSubsystem->Auth_Logout();
	}

	// TODO: Navigate back to login screen
	RemoveFromParent();
}

void UEchoesCharacterSelectWidget::OnConfirmCreateButtonClicked()
{
	if (!CharacterNameInput || !RaceComboBox)
	{
		return;
	}

	FString CharacterName = CharacterNameInput->GetText().ToString();
	
	// Validate name
	if (CharacterName.IsEmpty())
	{
		SetStatusText("Please enter a character name", FLinearColor::Red);
		return;
	}

	if (CharacterName.Len() < 3 || CharacterName.Len() > 50)
	{
		SetStatusText("Character name must be 3-50 characters", FLinearColor::Red);
		return;
	}

	FString SelectedRace = RaceComboBox->GetSelectedOption();
	int32 RaceId = GetRaceIdFromName(SelectedRace);

	CreateCharacter(CharacterName, RaceId);
}

void UEchoesCharacterSelectWidget::OnCancelCreateButtonClicked()
{
	SetCreationPanelVisible(false);
}

void UEchoesCharacterSelectWidget::OnRaceSelectionChanged(FString SelectedItem, ESelectInfo::Type SelectionType)
{
	int32 RaceId = GetRaceIdFromName(SelectedItem);
	UpdateRaceInfo(RaceId);
}

void UEchoesCharacterSelectWidget::OnCharacterSelected(FGuid CharacterId)
{
	// TODO: Load the character and enter game world
	SetStatusText("Loading character...", FLinearColor::Yellow);

	// This should trigger level load or world entry
	// For now, just log it
	UE_LOG(LogTemp, Warning, TEXT("Character selected: %s"), *CharacterId.ToString());
}

void UEchoesCharacterSelectWidget::LoadCharacters()
{
	// Characters are already loaded from AuthSubsystem during login
	// This function can be used to refresh the list if needed
	if (AuthSubsystem)
	{
		const TArray<FCharacterInfo>& Characters = AuthSubsystem->Auth_GetCharacters();
		PopulateCharacterList(Characters);
	}
}

void UEchoesCharacterSelectWidget::CreateCharacter(const FString& Name, int32 RaceId)
{
	// TODO: Implement actual character creation via HTTP request
	// For now, this is a placeholder that would need to:
	// 1. Make HTTP POST to /api/character with Name and RaceId
	// 2. On success, reload character list
	// 3. On failure, show error message

	SetStatusText("Creating character... (Not yet implemented)", FLinearColor::Yellow);
}

void UEchoesCharacterSelectWidget::PopulateCharacterList(const TArray<FCharacterInfo>& Characters)
{
	if (!CharacterList)
	{
		return;
	}

	CharacterList->ClearListItems();

	for (const FCharacterInfo& CharInfo : Characters)
	{
		UCharacterListItem* ListItem = NewObject<UCharacterListItem>(this);
		ListItem->CharacterInfo = CharInfo;
		
		// Determine race name (this should ideally come from backend)
		// For now, using placeholder logic
		ListItem->RaceName = "Unknown";

		CharacterList->AddItem(ListItem);
	}

	SetStatusText(FString::Printf(TEXT("%d character(s) found"), Characters.Num()), FLinearColor::White);
}

void UEchoesCharacterSelectWidget::SetCreationPanelVisible(bool bVisible)
{
	// Toggle visibility of creation panel widgets
	if (CharacterNameInput)
	{
		CharacterNameInput->SetVisibility(bVisible ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
	}

	if (RaceComboBox)
	{
		RaceComboBox->SetVisibility(bVisible ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
	}

	if (RaceDescriptionText)
	{
		RaceDescriptionText->SetVisibility(bVisible ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
	}

	if (RaceBonusesText)
	{
		RaceBonusesText->SetVisibility(bVisible ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
	}

	if (ConfirmCreateButton)
	{
		ConfirmCreateButton->SetVisibility(bVisible ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
	}

	if (CancelCreateButton)
	{
		CancelCreateButton->SetVisibility(bVisible ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
	}

	// Hide/show main buttons
	if (CharacterList)
	{
		CharacterList->SetVisibility(bVisible ? ESlateVisibility::Collapsed : ESlateVisibility::Visible);
	}

	if (SelectButton)
	{
		SelectButton->SetVisibility(bVisible ? ESlateVisibility::Collapsed : ESlateVisibility::Visible);
	}

	if (CreateButton)
	{
		CreateButton->SetVisibility(bVisible ? ESlateVisibility::Collapsed : ESlateVisibility::Visible);
	}

	if (DeleteButton)
	{
		DeleteButton->SetVisibility(bVisible ? ESlateVisibility::Collapsed : ESlateVisibility::Visible);
	}
}

void UEchoesCharacterSelectWidget::UpdateRaceInfo(int32 RaceId)
{
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
	if (RaceName == "Caldari")
		return 1;
	else if (RaceName == "Gallente")
		return 2;
	else if (RaceName == "Amarr")
		return 3;
	else if (RaceName == "Minmatar")
		return 4;
	
	return 1; // Default to Caldari
}

void UEchoesCharacterSelectWidget::GetRaceDescription(int32 RaceId, FString& OutDescription, FString& OutBonuses)
{
	switch (RaceId)
	{
	case 1: // Caldari
		OutDescription = "The Caldari State is ruled by several megacorporations. Ruthless, efficient, and technologically advanced.";
		OutBonuses = "• +5% Shield HP\n• +5% Hybrid Turret damage\n• Strong in electronic warfare";
		break;

	case 2: // Gallente
		OutDescription = "The Gallente Federation is a democracy that values freedom and individual rights above all else.";
		OutBonuses = "• +5% Armor HP\n• +5% Drone damage and hitpoints\n• +10% Scan resolution";
		break;

	case 3: // Amarr
		OutDescription = "The Amarr Empire is the largest and oldest of the four major empires. Religious and traditionalist.";
		OutBonuses = "• +5% Armor HP\n• +5% Energy weapon damage\n• +10% Capacitor capacity";
		break;

	case 4: // Minmatar
		OutDescription = "The Minmatar Republic was formed over a century ago. Tribal and resilient people.";
		OutBonuses = "• +5% Shield HP\n• +5% Projectile weapon damage\n• +10% Ship velocity";
		break;

	default:
		OutDescription = "Unknown race";
		OutBonuses = "";
		break;
	}
}

void UEchoesCharacterSelectWidget::SetStatusText(const FString& Message, const FLinearColor& Color)
{
	if (StatusText)
	{
		StatusText->SetText(FText::FromString(Message));
		StatusText->SetColorAndOpacity(FSlateColor(Color));
	}
}
