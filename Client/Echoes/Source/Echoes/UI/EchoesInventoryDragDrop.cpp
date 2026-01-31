// Copyright Epic Games, Inc. All Rights Reserved.

#include "UI/EchoesInventoryDragDrop.h"

void UEchoesInventoryDragDrop::InitializeDragOperation(
	const FEchoesInventoryItem& InItemData,
	const FGuid& InSourceStorageId,
	AActor* InSourceActor,
	int64 InQuantity)
{
	ItemData = InItemData;
	SourceStorageId = InSourceStorageId;
	SourceActor = InSourceActor;
	
	// If quantity is 0 or greater than available, use full quantity
	if (InQuantity <= 0 || InQuantity > InItemData.Quantity)
	{
		Quantity = InItemData.Quantity;
	}
	else
	{
		Quantity = InQuantity;
	}

	UE_LOG(LogTemp, Log, TEXT("Drag operation initialized: Item=%s, Quantity=%lld/%lld, Source=%s"),
		*InItemData.TypeName, Quantity, InItemData.Quantity, *InSourceStorageId.ToString());
}

void UEchoesInventoryDragDrop::SetQuantity(int64 InQuantity)
{
	// Clamp quantity between 1 and available quantity
	Quantity = FMath::Clamp(InQuantity, (int64)1, ItemData.Quantity);
	
	UE_LOG(LogTemp, Log, TEXT("Drag operation quantity updated: %lld"), Quantity);
}

bool UEchoesInventoryDragDrop::IsPartialStack() const
{
	return Quantity > 0 && Quantity < ItemData.Quantity;
}
