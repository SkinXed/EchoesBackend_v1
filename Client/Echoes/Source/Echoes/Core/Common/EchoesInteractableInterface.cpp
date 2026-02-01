// Copyright Epic Games, Inc. All Rights Reserved.

#include "Core/Common/EchoesInteractableInterface.h"
#include "GameFramework/Pawn.h"

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
	if (MaxDistance <= 0.0f)
	{
		MaxDistance = 25000.0f;
	}

	return Distance <= MaxDistance;
}
