// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EchoesWorldVisualTypes.h"
#include "StargateActor.generated.h"

class UNiagaraComponent;
class UAudioComponent;

/**
 * AStargateActor
 * 
 * Represents a stargate in the Echoes universe
 * Provides jump capability to other solar systems
 */
UCLASS()
class ECHOES_API AStargateActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AStargateActor();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

public:
	// ==================== Initialization ====================

	UFUNCTION(BlueprintCallable, Category = "Echoes|Stargate")
	void InitializeStargate(
		const FGuid& InGateId,
		const FString& InName,
		const FGuid& InTargetSystemId,
		const FString& InTargetSystemName,
		bool bInIsOperational,
		const FStargateVisualRow& InVisualData);

	// ==================== Getters ====================

	UFUNCTION(BlueprintPure, Category = "Echoes|Stargate")
	FGuid GetGateId() const { return GateId; }

	UFUNCTION(BlueprintPure, Category = "Echoes|Stargate")
	FString GetGateName() const { return GateName; }

	UFUNCTION(BlueprintPure, Category = "Echoes|Stargate")
	FGuid GetTargetSystemId() const { return TargetSystemId; }

	UFUNCTION(BlueprintPure, Category = "Echoes|Stargate")
	bool IsOperational() const { return bIsOperational; }

	UFUNCTION(BlueprintPure, Category = "Echoes|Stargate")
	FString GetTargetSystemName() const { return TargetSystemName; }

	// ==================== Jump Logic ====================

	/**
	 * Called when ship enters jump trigger zone
	 */
	UFUNCTION()
	void OnJumpTriggerBeginOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	/**
	 * Server RPC to request jump to target system
	 * Validates ship readiness and initiates travel
	 */
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerRPC_RequestJump(APlayerController* PlayerController);

	/**
	 * Check if ship is ready to jump (not in combat, has energy, etc.)
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Stargate")
	bool IsShipReadyToJump(AActor* Ship) const;

	/**
	 * Initiate jump sequence for player
	 * Called after validation on server
	 */
	void InitiateJumpToTarget(APlayerController* PlayerController);

protected:
	// ==================== Components ====================

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* GateMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UNiagaraComponent* PortalVFXComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UNiagaraComponent* DestinationFXComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UAudioComponent* AmbientAudioComponent;

	/** Jump trigger zone - detects ships entering for jump */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UBoxComponent* JumpTriggerZone;

	// ==================== Gate Data (Replicated) ====================

	UPROPERTY(ReplicatedUsing = OnRep_GateData, BlueprintReadOnly, Category = "Stargate")
	FGuid GateId;

	UPROPERTY(ReplicatedUsing = OnRep_GateData, BlueprintReadOnly, Category = "Stargate")
	FString GateName;

	UPROPERTY(ReplicatedUsing = OnRep_GateData, BlueprintReadOnly, Category = "Stargate")
	FGuid TargetSystemId;

	UPROPERTY(ReplicatedUsing = OnRep_GateData, BlueprintReadOnly, Category = "Stargate")
	FString TargetSystemName;

	UPROPERTY(ReplicatedUsing = OnRep_GateData, BlueprintReadOnly, Category = "Stargate")
	bool bIsOperational;

	UPROPERTY(BlueprintReadOnly, Category = "Stargate")
	FStargateVisualRow VisualData;

	// ==================== Replication ====================

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION()
	void OnRep_GateData();

private:
	/** Current rotation angle for ring animation */
	float CurrentRotationAngle;

	void ApplyVisualConfiguration();
	void UpdateRingRotation(float DeltaTime);
};
