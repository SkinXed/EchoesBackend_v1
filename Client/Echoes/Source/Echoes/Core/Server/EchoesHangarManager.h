// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Core/Common/Networking/EchoesInventorySubsystem.h"
#include "EchoesHangarManager.generated.h"

class USceneComponent;
class UStaticMeshComponent;

/**
 * Hangar instance structure for spatial isolation
 */
USTRUCT(BlueprintType)
struct FHangarInstance
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Hangar")
	FGuid InstanceId;

	UPROPERTY(BlueprintReadWrite, Category = "Hangar")
	FGuid PlayerId;

	UPROPERTY(BlueprintReadWrite, Category = "Hangar")
	FGuid StationId;

	UPROPERTY(BlueprintReadWrite, Category = "Hangar")
	FVector SpatialOffset;

	UPROPERTY(BlueprintReadWrite, Category = "Hangar")
	AActor* SpawnedShipPawn = nullptr;
};

/**
 * AEchoesHangarManager
 * 
 * Manages the hangar scene, spawning and updating the ship preview.
 * Subscribes to inventory subsystem to react to fitting changes.
 * Implements spatial isolation for each player's hangar instance.
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

	/**
	 * Get or create a hangar instance for a player
	 * @param PlayerId - Character/Player GUID
	 * @param StationId - Station GUID where hangar is located
	 * @param HangarInstanceId - Unique hangar instance ID from backend
	 * @return Spatial offset vector for this player's hangar
	 */
	UFUNCTION(BlueprintCallable, Category = "Hangar")
	FVector GetOrCreateHangarInstance(const FGuid& PlayerId, const FGuid& StationId, const FGuid& HangarInstanceId);

	/**
	 * Bind ship pawn to hangar instance with spatial isolation
	 * @param PlayerId - Character/Player GUID
	 * @param ShipPawn - Ship pawn to bind
	 */
	UFUNCTION(BlueprintCallable, Category = "Hangar")
	void BindShipPawnToHangar(const FGuid& PlayerId, AActor* ShipPawn);

	/** Spawn ship preview mesh at target point */
	UFUNCTION(BlueprintCallable, Category = "Hangar")
	void SpawnShipPreview(const FGuid& ShipId);

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
	UFUNCTION()
	void OnShipFittingReceived(const FEchoesShipFitting& Fitting);

	/** Called when ship fitting fetch fails */
	UFUNCTION()
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
	FGuid CurrentShipId;

	/** Cached inventory subsystem reference */
	UPROPERTY()
	UEchoesInventorySubsystem* InventorySubsystem;

	/** Map of active hangar instances per player */
	UPROPERTY()
	TMap<FGuid, FHangarInstance> HangarInstances;

	/** Spatial separation distance between hangar instances (in cm) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hangar")
	float HangarSpatialSeparation = 1000000.0f; // 10km separation
};
