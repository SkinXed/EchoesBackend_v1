// Copyright Epic Games, Inc. All Rights Reserved.

#include "UI/EchoesInventoryItemObject.h"
#include "Core/Common/Networking/EchoesInventorySubsystem.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"

void UEchoesInventoryItemObject::InitializeWithData(const FEchoesInventoryItem& InItemData)
{
	ItemData = InItemData;
	CachedDefinition = nullptr;
	
	// Fetch item definition from subsystem
	FetchItemDefinition();
}

FString UEchoesInventoryItemObject::GetFormattedVolume() const
{
	float Vol = GetUnitVolume();
	return FString::Printf(TEXT("%.1f m³"), Vol);
}

FString UEchoesInventoryItemObject::GetFormattedTotalVolume() const
{
	float TotalVol = GetCalculatedTotalVolume();
	
	// Format with thousand separators
	FNumberFormattingOptions NumberFormat;
	NumberFormat.MinimumFractionalDigits = 1;
	NumberFormat.MaximumFractionalDigits = 1;
	
	FText FormattedNumber = FText::AsNumber(TotalVol, &NumberFormat);
	return FString::Printf(TEXT("%s m³"), *FormattedNumber.ToString());
}

FText UEchoesInventoryItemObject::GetDisplayName() const
{
	if (CachedDefinition && !CachedDefinition->DisplayName.IsEmpty())
	{
		return CachedDefinition->DisplayName;
	}
	
	// Fallback to TypeName from ItemData
	return FText::FromString(ItemData.TypeName);
}

FText UEchoesInventoryItemObject::GetDescription() const
{
	if (CachedDefinition)
	{
		return CachedDefinition->Description;
	}
	
	return FText::FromString(TEXT("No description available."));
}

float UEchoesInventoryItemObject::GetCalculatedTotalVolume() const
{
	return GetUnitVolume() * ItemData.Quantity;
}

float UEchoesInventoryItemObject::GetUnitVolume() const
{
	if (CachedDefinition)
	{
		return CachedDefinition->UnitVolume;
	}
	
	// Fallback to volume from ItemData
	return ItemData.Volume;
}

float UEchoesInventoryItemObject::GetTotalMass() const
{
	if (CachedDefinition)
	{
		return CachedDefinition->UnitMass * ItemData.Quantity;
	}
	
	return 0.0f; // No mass data without definition
}

void UEchoesInventoryItemObject::FetchItemDefinition()
{
	// Get game instance
	UWorld* World = GetWorld();
	if (!World)
	{
		UE_LOG(LogTemp, Warning, TEXT("EchoesInventoryItemObject: No world available for item %d"), ItemData.TypeId);
		return;
	}

	UGameInstance* GameInstance = World->GetGameInstance();
	if (!GameInstance)
	{
		UE_LOG(LogTemp, Warning, TEXT("EchoesInventoryItemObject: No game instance for item %d"), ItemData.TypeId);
		return;
	}

	// Get inventory subsystem
	InventorySubsystem = GameInstance->GetSubsystem<UEchoesInventorySubsystem>();
	if (!InventorySubsystem)
	{
		UE_LOG(LogTemp, Warning, TEXT("EchoesInventoryItemObject: No inventory subsystem for item %d"), ItemData.TypeId);
		return;
	}

	// Fetch definition
	FString ItemIdStr = FString::FromInt(ItemData.TypeId);
	CachedDefinition = InventorySubsystem->GetItemDefinition(ItemIdStr);

	if (CachedDefinition)
	{
		UE_LOG(LogTemp, Verbose, TEXT("EchoesInventoryItemObject: Loaded definition for item %d: %s"), 
			ItemData.TypeId, *CachedDefinition->DisplayName.ToString());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("EchoesInventoryItemObject: No definition found for item ID: %d"), ItemData.TypeId);
	}
}
