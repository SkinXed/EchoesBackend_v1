// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Core/Common/Networking/EchoesInventorySubsystem.h"
#include "EchoesHangarManager.generated.h"

class USceneComponent;
class UStaticMeshComponent;

/**
 * AEchoesHangarManager
 * 
 * Manages the hangar scene, spawning and updating the ship preview.
 * Subscribes to inventory subsystem to react to fitting changes.
 */
UCLASS()
class ECHOES_API AEchoesHangarManager : public AActor
{
	GENERATED_BODY()
	
public:	
	AEchoesHangarManager();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	/** Initialize hangar for specific character */
	UFUNCTION(BlueprintCallable, Category = "Hangar")
	void InitializeHangar(const FString& CharacterId);

	/** Spawn ship preview mesh at target point */
	UFUNCTION(BlueprintCallable, Category = "Hangar")
	void SpawnShipPreview(const FString& ShipId);

	/** Update ship mesh when fitting changes */
	UFUNCTION(BlueprintCallable, Category = "Hangar")
	void UpdateShipMesh(const FEchoesShipFitting& NewFitting);

	/** Clear current ship preview */
	UFUNCTION(BlueprintCallable, Category = "Hangar")
	void ClearShipPreview();

protected:
	/** Called when fitting changes (from inventory subsystem) */
	UFUNCTION()
	void OnFittingChanged(const FEchoesShipFitting& NewFitting);

	/** Called when ship fitting is successfully fetched */
	void OnShipFittingReceived(const FEchoesShipFitting& Fitting);

	/** Called when ship fitting fetch fails */
	void OnShipFittingFailed(const FString& Error);

public:
	/** Target point where ship preview spawns */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hangar")
	class USceneComponent* ShipSpawnPoint;

	/** Default ship mesh for preview (can be overridden) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hangar")
	class UStaticMesh* DefaultShipMesh;

protected:
	/** Current spawned ship preview actor */
	UPROPERTY()
	AActor* PreviewShipActor;

	/** Current character ID being managed */
	UPROPERTY()
	FString CurrentCharacterId;

	/** Current ship ID being displayed */
	UPROPERTY()
	FString CurrentShipId;

	/** Cached inventory subsystem reference */
	UPROPERTY()
	UEchoesInventorySubsystem* InventorySubsystem;
};
