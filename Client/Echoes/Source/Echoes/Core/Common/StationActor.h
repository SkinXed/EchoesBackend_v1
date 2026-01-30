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

protected:
	// ==================== Components ====================

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* BaseMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UNiagaraComponent* LightsComponent;

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

private:
	void ApplyVisualConfiguration();
	void ApplySeedVariation();
};
