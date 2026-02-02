// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Components/Button.h"
#include "Widgets/EchoesCharacterSelectWidget.h"
#include "EchoesCharacterListEntry.generated.h"

/**
 * ?????? ????? ?????? ? ?????? ??????????
 */
UCLASS()
class ECHOES_API UEchoesCharacterListEntry : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;
	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;

protected:
	// ??????????? UI ????????. ????? ? Blueprint ?????? ?????????!
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* NameText;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* RaceText;

	UPROPERTY(meta = (BindWidgetOptional))
	class UTextBlock* CreditsText;

	UPROPERTY(meta = (BindWidgetOptional))
	class UTextBlock* ExperienceText;

	UPROPERTY(meta = (BindWidgetOptional))
	class UImage* AvatarImage;

	UPROPERTY(meta = (BindWidget))	
	class UButton* LoginButton;

	FGuid CachedCharacterId;
	UCharacterListItem* CachedListItem = nullptr;

private:
	UFUNCTION()
	void OnLoginButtonClicked();
};
