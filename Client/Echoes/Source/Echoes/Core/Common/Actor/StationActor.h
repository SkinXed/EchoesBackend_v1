// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EchoesWorldVisualTypes.h"
#include "StationActor.generated.h"

class UNiagaraComponent;

/**
 * AStationActor
 * 
 * Represents a space station in the Echoes universe
 * Supports modular construction and faction customization
 */
UCLASS()
class ECHOES_API AStationActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AStationActor();

protected:
	virtual void BeginPlay() override;

public:
	// ==================== Initialization ====================

	UFUNCTION(BlueprintCallable, Category = "Echoes|Station")
	void InitializeStation(
		const FGuid& InStationId,
		const FString& InName,
		const FString& InStationType,
		int32 InSeed,
		const FStationVisualRow& InVisualData);

	// ==================== Getters ====================

	UFUNCTION(BlueprintPure, Category = "Echoes|Station")
	FGuid GetStationId() const { return StationId; }

	UFUNCTION(BlueprintPure, Category = "Echoes|Station")
	FString GetStationName() const { return StationName; }

	UFUNCTION(BlueprintPure, Category = "Echoes|Station")
	FString GetStationType() const { return StationType; }

	// ==================== Docking Logic ====================

	/**
	 * Called when ship enters docking zone
	 */
	UFUNCTION()
	void OnDockingZoneBeginOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	/**
	 * Server RPC to request docking at this station
	 * Validates access rights and initiates docking sequence
	 */
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerRPC_RequestDocking(APlayerController* PlayerController);

	/**
	 * Check if player has access rights to dock at this station
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Station")
	bool HasDockingAccess(APlayerController* PlayerController) const;

	/**
	 * Initiate docking sequence for player
	 * Transitions player state from InSpace to InHangar
	 */
	void InitiateDocking(APlayerController* PlayerController);

	/**
	 * Notify backend about character docking at this station
	 */
	void NotifyBackendDocking(APlayerController* PlayerController);

	/**
	 * Client RPC to open station menu on player's screen
	 * Called after successful docking
	 * 
	 * @param InStationName - Name of the station
	 * @param InStationType - Type of the station
	 * @param InHangarStorageId - Storage ID of player's personal hangar
	 */
	UFUNCTION(Client, Reliable)
	void ClientRPC_OpenStationMenu(
		const FString& InStationName,
		const FString& InStationType,
		const FGuid& InHangarStorageId);

	/**
	 * Client RPC to close station menu on player's screen
	 * Called after successful undocking
	 */
	UFUNCTION(Client, Reliable)
	void ClientRPC_CloseStationMenu();

	/**
	 * Server RPC to request undocking from station
	 * Called from client when player clicks Undock button
	 */
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerRPC_RequestUndock(APlayerController* PlayerController);

	/**
	 * Initiate undocking sequence for player
	 * Spawns player ship in space near station
	 */
	void InitiateUndocking(APlayerController* PlayerController);

protected:
	// ==================== Components ====================

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* BaseMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UNiagaraComponent* LightsComponent;

	/** Docking zone - detects ships requesting to dock */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class USphereComponent* DockingZone;

	// ==================== Station Data (Replicated) ====================

	UPROPERTY(ReplicatedUsing = OnRep_StationData, BlueprintReadOnly, Category = "Station")
	FGuid StationId;

	UPROPERTY(ReplicatedUsing = OnRep_StationData, BlueprintReadOnly, Category = "Station")
	FString StationName;

	UPROPERTY(ReplicatedUsing = OnRep_StationData, BlueprintReadOnly, Category = "Station")
	FString StationType;

	UPROPERTY(ReplicatedUsing = OnRep_StationData, BlueprintReadOnly, Category = "Station")
	int32 Seed;

	UPROPERTY(BlueprintReadOnly, Category = "Station")
	FStationVisualRow VisualData;

	// ==================== Replication ====================

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION()
	void OnRep_StationData();

protected:
	/** Called when ship fitting is successfully fetched */
	UFUNCTION()
	void HandleHangarReceived(const FGuid& HangarStorageId);

	/** Called when ship fitting fetch fails */
	UFUNCTION()
	void HandleHangarFailure(const FString& Error);

private:
	void ApplyVisualConfiguration();
	void ApplySeedVariation();

	TWeakObjectPtr<APlayerController> PendingDockingController;
};
