// Copyright Epic Games, Inc. All Rights Reserved.

#include "UI/EchoesStationMenuWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Core/Common/EchoesInventoryComponent.h"
#include "Kismet/GameplayStatics.h"

UEchoesStationMenuWidget::UEchoesStationMenuWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UEchoesStationMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// Bind button click events
	if (InventoryButton)
	{
		InventoryButton->OnClicked.AddDynamic(this, &UEchoesStationMenuWidget::OnInventoryButtonPressed);
	}

	if (UndockButton)
	{
		UndockButton->OnClicked.AddDynamic(this, &UEchoesStationMenuWidget::OnUndockButtonPressed);
	}

	if (RepairButton)
	{
		RepairButton->OnClicked.AddDynamic(this, &UEchoesStationMenuWidget::OnRepairButtonPressed);
	}

	UE_LOG(LogTemp, Log, TEXT("Station Menu Widget constructed"));
}

void UEchoesStationMenuWidget::NativeDestruct()
{
	// Unbind button events
	if (InventoryButton)
	{
		InventoryButton->OnClicked.RemoveDynamic(this, &UEchoesStationMenuWidget::OnInventoryButtonPressed);
	}

	if (UndockButton)
	{
		UndockButton->OnClicked.RemoveDynamic(this, &UEchoesStationMenuWidget::OnUndockButtonPressed);
	}

	if (RepairButton)
	{
		RepairButton->OnClicked.RemoveDynamic(this, &UEchoesStationMenuWidget::OnRepairButtonPressed);
	}

	Super::NativeDestruct();
}

void UEchoesStationMenuWidget::InitializeStationMenu(
	const FGuid& InStationId,
	const FString& InStationName,
	const FString& InStationType,
	const FGuid& InHangarStorageId)
{
	StationId = InStationId;
	StationName = InStationName;
	StationType = InStationType;
	HangarStorageId = InHangarStorageId;
	bIsInitialized = true;

	UE_LOG(LogTemp, Log, TEXT("Station Menu initialized:"));
	UE_LOG(LogTemp, Log, TEXT("  Station: %s (Type: %s)"), *StationName, *StationType);
	UE_LOG(LogTemp, Log, TEXT("  Hangar Storage ID: %s"), *HangarStorageId.ToString());

	// Update display
	UpdateStationDisplay();

	// Trigger Blueprint event
	OnStationMenuInitialized();
}

void UEchoesStationMenuWidget::UpdateStationDisplay()
{
	if (StationNameText)
	{
		StationNameText->SetText(FText::FromString(StationName));
	}

	if (StationTypeText)
	{
		StationTypeText->SetText(FText::FromString(StationType));
	}
}

void UEchoesStationMenuWidget::OnInventoryButtonPressed()
{
	if (!bIsInitialized)
	{
		UE_LOG(LogTemp, Warning, TEXT("Station menu not initialized yet"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Inventory button pressed - Opening hangar"));
	
	// Broadcast delegate for Blueprint to handle
	OnInventoryButtonClicked.Broadcast();
}

void UEchoesStationMenuWidget::OnUndockButtonPressed()
{
	if (!bIsInitialized)
	{
		UE_LOG(LogTemp, Warning, TEXT("Station menu not initialized yet"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Undock button pressed - Initiating undocking sequence"));
	
	// Broadcast delegate for Blueprint to handle
	OnUndockButtonClicked.Broadcast();
}

void UEchoesStationMenuWidget::OnRepairButtonPressed()
{
	if (!bIsInitialized)
	{
		UE_LOG(LogTemp, Warning, TEXT("Station menu not initialized yet"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Repair button pressed - Station services (stub)"));
	
	// Broadcast delegate for Blueprint to handle
	OnRepairButtonClicked.Broadcast();
}
