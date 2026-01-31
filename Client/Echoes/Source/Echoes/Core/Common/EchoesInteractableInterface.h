// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EchoesInteractableInterface.generated.h"

// Forward declarations
class APawn;

/**
 * Interaction result structure
 * Contains information about interaction success/failure
 */
USTRUCT(BlueprintType)
struct FEchoesInteractionResult
{
	GENERATED_BODY()

	/** Whether the interaction was successful */
	UPROPERTY(BlueprintReadWrite, Category = "Interaction")
	bool bSuccess = false;

	/** Message to display to player (error or info) */
	UPROPERTY(BlueprintReadWrite, Category = "Interaction")
	FString Message;

	/** Optional: actor that was interacted with */
	UPROPERTY(BlueprintReadWrite, Category = "Interaction")
	AActor* TargetActor = nullptr;
};

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class UEchoesInteractableInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * IEchoesInteractableInterface
 * 
 * Interface for objects that can be interacted with by players
 * Used for loot containers, stations, gates, etc.
 * 
 * Usage:
 * - Implement in actor classes that need interaction
 * - Override CanInteract to check conditions
 * - Override OnInteract to handle interaction logic
 * - Server validates distance and permissions
 */
class ECHOES_API IEchoesInteractableInterface
{
	GENERATED_BODY()

public:
	/**
	 * Check if the actor can be interacted with
	 * Called on both client and server
	 * 
	 * @param Interactor - Pawn attempting to interact
	 * @return True if interaction is allowed
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Echoes|Interaction")
	bool CanInteract(APawn* Interactor) const;

	/**
	 * Get the interaction distance for this object
	 * 
	 * @return Maximum interaction distance in cm (Unreal units)
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Echoes|Interaction")
	float GetInteractionDistance() const;

	/**
	 * Get the display name for interaction prompt
	 * 
	 * @return Name to show in interaction UI
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Echoes|Interaction")
	FText GetInteractionPrompt() const;

	/**
	 * Server-side interaction handler
	 * Called when player interacts with this object
	 * 
	 * @param Interactor - Pawn that initiated interaction
	 * @return Interaction result
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Echoes|Interaction")
	FEchoesInteractionResult OnInteract(APawn* Interactor);

	/**
	 * Check if interactor is within interaction range
	 * 
	 * @param Interactor - Pawn to check
	 * @return True if within range
	 */
	virtual bool IsWithinInteractionRange(APawn* Interactor) const;
};
