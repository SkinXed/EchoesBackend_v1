// Copyright Epic Games, Inc. All Rights Reserved.

#include "Core/Common/EchoesInteractableInterface.h"
#include "GameFramework/Pawn.h"

bool IEchoesInteractableInterface::CanInteract_Implementation(APawn* Interactor) const
{
	// Default implementation: check distance
	return IsWithinInteractionRange(Interactor);
}

float IEchoesInteractableInterface::GetInteractionDistance_Implementation() const
{
	// Default: 250 meters (25000 cm)
	return 25000.0f;
}

FText IEchoesInteractableInterface::GetInteractionPrompt_Implementation() const
{
	// Default prompt
	return FText::FromString(TEXT("Interact [E]"));
}

FEchoesInteractionResult IEchoesInteractableInterface::OnInteract_Implementation(APawn* Interactor)
{
	// Default implementation: just return success
	FEchoesInteractionResult Result;
	Result.bSuccess = true;
	Result.Message = TEXT("Interaction successful");
	return Result;
}

bool IEchoesInteractableInterface::IsWithinInteractionRange(APawn* Interactor) const
{
	if (!Interactor)
	{
		return false;
	}

	// Get self as AActor
	const AActor* SelfActor = Cast<AActor>(this);
	if (!SelfActor)
	{
		return false;
	}

	// Calculate distance
	float Distance = FVector::Dist(Interactor->GetActorLocation(), SelfActor->GetActorLocation());
	float MaxDistance = Execute_GetInteractionDistance(SelfActor);

	return Distance <= MaxDistance;
}
