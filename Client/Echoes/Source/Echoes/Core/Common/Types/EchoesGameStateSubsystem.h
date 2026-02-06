// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "EchoesGameStateSubsystem.generated.h"

/**
 * Game state enum for tracking player progress through the game flow
 */
UENUM(BlueprintType)
enum class EEchoesGameState : uint8
{
	Login UMETA(DisplayName = "Login"),
	CharacterSelect UMETA(DisplayName = "Character Select"),
	Hangar UMETA(DisplayName = "Hangar"),
	InSpace UMETA(DisplayName = "In Space")
};

/**
 * Subsystem for managing game state transitions and level flow
 * Tracks current game state and provides transition functions
 */
UCLASS()
class ECHOES_API UEchoesGameStateSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	// Subsystem lifecycle
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// State management
	UFUNCTION(BlueprintCallable, Category = "Echoes|GameState")
	EEchoesGameState GetCurrentState() const { return CurrentState; }

	UFUNCTION(BlueprintCallable, Category = "Echoes|GameState")
	void SetCurrentState(EEchoesGameState NewState) { CurrentState = NewState; }

	// Transition functions
	UFUNCTION(BlueprintCallable, Category = "Echoes|GameState")
	void TransitionToLogin();

	UFUNCTION(BlueprintCallable, Category = "Echoes|GameState")
	void TransitionToCharacterSelect();

	UFUNCTION(BlueprintCallable, Category = "Echoes|GameState")
	void TransitionToHangar(const FString& CharacterId);

	UFUNCTION(BlueprintCallable, Category = "Echoes|GameState")
	void TransitionToSpace(const FString& CharacterId, const FString& ShipId);

	// Level paths (can be configured)
	// Note: Login and CharacterSelect use the same map (EntryMap) with different UI widgets
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Echoes|GameState")
	FString LoginLevelPath = TEXT("/Game/Project/Map/EntryMap");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Echoes|GameState")
	FString CharacterSelectLevelPath = TEXT("/Game/Project/Map/EntryMap");

	// Note: Hangar and Space use the same map (GameLevel) - hangar is an isolated instance within the game world
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Echoes|GameState")
	FString HangarLevelPath = TEXT("/Game/Project/Map/GameLevel");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Echoes|GameState")
	FString SpaceLevelPath = TEXT("/Game/Project/Map/GameLevel");

	// Current context
	UPROPERTY(BlueprintReadOnly, Category = "Echoes|GameState")
	FString CurrentCharacterId;

	UPROPERTY(BlueprintReadOnly, Category = "Echoes|GameState")
	FString CurrentShipId;

private:
	UPROPERTY()
	EEchoesGameState CurrentState;
};
