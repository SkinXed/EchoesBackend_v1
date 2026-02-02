// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "../Core/Common/Networking/EchoesAuthSubsystem.h"
#include "EchoesCharacterSelectWidget.generated.h"

class UListView;
class UButton;
class UTextBlock;
class UEditableTextBox;
class UComboBoxString;
class UProgressBar;
class UEchoesAuthSubsystem;
class UWidget;

/**
 * Character list item data
 */
UCLASS(BlueprintType)
class UCharacterListItem : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category = "Character")
	FCharacterInfo CharacterInfo;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	FString RaceName;
};

/**
 * UEchoesCharacterSelectWidget
 * 
 * Character selection UI widget for Echoes MMO
 * Displays list of player's characters and allows creation of new characters
 * Inherits from UEchoesWindowBase for drag/focus support
 */
UCLASS()
class ECHOES_API UEchoesCharacterSelectWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	// ==================== Widget Lifecycle ====================

	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	// ==================== UI Bindings ====================

	/** List view for characters */
	UPROPERTY(meta = (BindWidget))
	UListView* CharacterList;

	/** Create new character button */
	UPROPERTY(meta = (BindWidget))
	UButton* CreateButton;

	/** Delete character button */
	UPROPERTY(meta = (BindWidget))
	UButton* DeleteButton;

	/** Logout button */
	UPROPERTY(meta = (BindWidget))
	UButton* LogoutButton;

	/** Status text */
	UPROPERTY(meta = (BindWidget))
	UTextBlock* StatusText;

	// Character creation panel widgets
	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* CharacterNameInput;

	UPROPERTY(meta = (BindWidget))
	UComboBoxString* RaceComboBox;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* RaceDescriptionText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* RaceBonusesText;

	UPROPERTY(meta = (BindWidget))
	UButton* ConfirmCreateButton;

	UPROPERTY(meta = (BindWidget))
	UButton* CancelCreateButton;

	UPROPERTY(meta = (BindWidget, OptionalWidget = true))
	UWidget* CreationPanel;

	// ==================== Blueprint Events ====================

	/** Called when a character is selected */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Character")
	void OnCharacterSelected(FGuid CharacterId);

	UFUNCTION(BlueprintCallable, Category = "Echoes|Character")
	void LaunchCharacter(FGuid CharacterId);

protected:
	// ==================== Button Handlers ====================

	UFUNCTION()
	void OnCreateButtonClicked();

	UFUNCTION()
	void OnDeleteButtonClicked();

	UFUNCTION()
	void OnLogoutButtonClicked();

	UFUNCTION()
	void OnConfirmCreateButtonClicked();

	UFUNCTION()
	void OnCancelCreateButtonClicked();

	UFUNCTION()
	void OnRaceSelectionChanged(FString SelectedItem, ESelectInfo::Type SelectionType);

	UFUNCTION()
	void OnCharacterListSelectionChanged(UObject* SelectedItem);

	// ==================== API Functions ====================

	/**
	 * Load character list from backend
	 */
	void LoadCharacters();

	/**
	 * Create a new character
	 */
	void CreateCharacter(const FString& Name, int32 RaceId);

	// ==================== Helper Functions ====================

	/**
	 * Populate character list UI
	 */
	void PopulateCharacterList(const TArray<FCharacterInfo>& Characters);

	/**
	 * Show/hide character creation panel
	 */
	void SetCreationPanelVisible(bool bVisible);

	/**
	 * Update race information display
	 */
	void UpdateRaceInfo(int32 RaceId);

	/**
	 * Get race ID from race name
	 */
	int32 GetRaceIdFromName(const FString& RaceName);

	/**
	 * Get race information
	 */
	void GetRaceDescription(int32 RaceId, FString& OutDescription, FString& OutBonuses);

	/**
	 * Set status text
	 */
	void SetStatusText(const FString& Message, const FLinearColor& Color);

	void UpdateCreateButtonState(int32 CharacterCount);
	FString GetRaceNameFromId(int32 RaceId) const;

private:
	/** Reference to auth subsystem */
	UPROPERTY()
	UEchoesAuthSubsystem* AuthSubsystem;

	/** Currently selected character */
	UPROPERTY()
	UCharacterListItem* SelectedCharacter;

	/** Is operation in progress? */
	bool bOperationInProgress = false;

	UFUNCTION()
	void HandleCharacterCreated(const FCharacterData& CharacterData);

	UFUNCTION()
	void HandleCharacterCreationFailed(const FString& ErrorMessage);

	UFUNCTION()
	void HandleCharacterDeleted(const FGuid& CharacterId);

	UFUNCTION()
	void HandleCharacterDeletionFailed(const FString& ErrorMessage);

	UFUNCTION()
	void HandleCharacterListUpdated(const TArray<FCharacterInfo>& Characters);
};
