// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesStationMenuWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "EchoesInventoryComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"

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

void UEchoesStationMenuWidget::OpenPersonalHangar()
{
	if (!bIsInitialized)
	{
		UE_LOG(LogTemp, Warning, TEXT("Station menu not initialized, cannot open hangar"));
		return;
	}

	if (!HangarStorageId.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Invalid hangar storage ID, cannot open hangar"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Opening personal hangar with StorageId: %s"), *HangarStorageId.ToString());

	// Blueprint should handle actual window creation
	// This is a hook for Blueprint to override or bind to
	// Example Blueprint implementation:
	// 1. Create UEchoesWindowBase widget
	// 2. Add UEchoesInventoryWidget to ContentSlot
	// 3. Set inventory widget's StorageId to HangarStorageId
	// 4. Set window title to "Personal Hangar"
	// 5. Add to viewport

	OnInventoryButtonClicked.Broadcast();
}

void UEchoesStationMenuWidget::OpenShipCargo()
{
	if (!bIsInitialized)
	{
		UE_LOG(LogTemp, Warning, TEXT("Station menu not initialized, cannot open ship cargo"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Opening ship cargo"));

	// Get player's pawn to find ship inventory component
	APlayerController* PC = GetOwningPlayer();
	if (!PC)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to get player controller"));
		return;
	}

	APawn* PlayerPawn = PC->GetPawn();
	if (!PlayerPawn)
	{
		UE_LOG(LogTemp, Error, TEXT("Player has no pawn"));
		return;
	}

	// Look for inventory component on pawn (ship)
	UActorComponent* InventoryComp = PlayerPawn->GetComponentByClass(UEchoesInventoryComponent::StaticClass());
	if (!InventoryComp)
	{
		UE_LOG(LogTemp, Error, TEXT("Player pawn has no inventory component"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Found ship inventory component"));

	// Blueprint should handle actual window creation
	// This is a hook for Blueprint to create ship cargo window
}

void UEchoesStationMenuWidget::RequestUndock()
{
	if (!bIsInitialized)
	{
		UE_LOG(LogTemp, Warning, TEXT("Station menu not initialized, cannot undock"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Requesting undock from station '%s'"), *StationName);

	// Broadcast to Blueprint to handle ServerRPC call
	OnUndockButtonClicked.Broadcast();

	// Blueprint should:
	// 1. Find the StationActor that opened this menu
	// 2. Call ServerRPC_RequestUndock on that actor
	// 3. Close this station menu window
}
