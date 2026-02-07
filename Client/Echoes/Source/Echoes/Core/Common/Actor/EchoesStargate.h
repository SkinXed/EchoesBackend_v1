// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "EchoesStargate.generated.h"

// Forward declarations
class UEchoesJumpSubsystem;

/**
 * AEchoesStargate
 * 
 * Stargate actor that triggers interstellar jumps when ships enter.
 * Handles jump initiation and visual effects.
 * 
 * Setup:
 * 1. Place in level at desired location
 * 2. Configure DestinationSystemId in details panel
 * 3. Set StargateId to match database entry
 * 4. Adjust trigger volume size as needed
 */
UCLASS(Blueprintable, ClassGroup = (Echoes))
class ECHOES_API AEchoesStargate : public AActor
{
	GENERATED_BODY()

public:
	AEchoesStargate();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	/**
	 * Stargate ID (must match database entry)
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stargate")
	FGuid StargateId;

	/**
	 * Source system ID (current system)
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stargate")
	FGuid SourceSystemId;

	/**
	 * Destination system ID (where jumps lead to)
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stargate")
	FGuid DestinationSystemId;

	/**
	 * Whether the stargate is currently operational
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stargate")
	bool bIsOperational;

	/**
	 * Stargate name for display
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stargate")
	FString StargateName;

	/**
	 * Cooldown time between jumps (per ship)
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stargate|Settings")
	float JumpCooldownSeconds;

	/**
	 * Whether to require player confirmation before jump
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stargate|Settings")
	bool bRequireConfirmation;

	/**
	 * Minimum distance to stargate center to allow jump (meters)
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stargate|Settings")
	float MinJumpDistance;

	/**
	 * Maximum distance from stargate center to allow jump (meters)
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stargate|Settings")
	float MaxJumpDistance;

protected:
	/**
	 * Trigger box for detecting ships
	 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UBoxComponent* TriggerVolume;

	/**
	 * Static mesh component for visual representation
	 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* StargateMesh;

	/**
	 * Map of actors and their last jump time (for cooldown)
	 */
	UPROPERTY()
	TMap<AActor*, float> LastJumpTimes;

	/**
	 * Called when an actor enters the trigger volume
	 */
	UFUNCTION()
	void OnTriggerBeginOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	/**
	 * Called when an actor leaves the trigger volume
	 */
	UFUNCTION()
	void OnTriggerEndOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);

	/**
	 * Initiate jump for a ship (SERVER ONLY)
	 * Called when ship enters trigger and meets requirements
	 * 
	 * @param Ship - Ship actor to jump
	 * @param CharacterId - Character ID of the pilot
	 */
	UFUNCTION(BlueprintCallable, Category = "Stargate", meta = (DisplayName = "ServerOnly - Initiate Jump"))
	void ServerOnly_InitiateJump(AActor* Ship, FGuid CharacterId);

	/**
	 * Check if a ship can jump (cooldown, distance, etc.)
	 */
	UFUNCTION(BlueprintCallable, Category = "Stargate")
	bool CanShipJump(AActor* Ship) const;

	/**
	 * Get character ID from ship/pawn
	 * Override in Blueprint or C++ for your specific character system
	 */
	UFUNCTION(BlueprintNativeEvent, Category = "Stargate")
	FGuid GetCharacterIdFromShip(AActor* Ship) const;
	virtual FGuid GetCharacterIdFromShip_Implementation(AActor* Ship) const;

	/**
	 * Visual effect when jump is initiated
	 * Override in Blueprint for custom effects
	 */
	UFUNCTION(BlueprintNativeEvent, Category = "Stargate|Effects")
	void PlayJumpEffect(AActor* Ship);
	virtual void PlayJumpEffect_Implementation(AActor* Ship);

	/**
	 * Visual effect for idle stargate
	 * Override in Blueprint for custom effects
	 */
	UFUNCTION(BlueprintNativeEvent, Category = "Stargate|Effects")
	void PlayIdleEffect();
	virtual void PlayIdleEffect_Implementation();

public:
	/**
	 * Blueprint event called when jump is initiated
	 */
	UFUNCTION(BlueprintImplementableEvent, Category = "Stargate")
	void OnJumpInitiated(AActor* Ship, const FString& DestinationSystemName);

	/**
	 * Blueprint event called when jump fails
	 */
	UFUNCTION(BlueprintImplementableEvent, Category = "Stargate")
	void OnJumpFailed(AActor* Ship, const FString& Reason);

private:
	/**
	 * Cached jump subsystem reference
	 */
	UPROPERTY()
	UEchoesJumpSubsystem* JumpSubsystem;

	/**
	 * Get or cache jump subsystem
	 */
	UEchoesJumpSubsystem* GetJumpSubsystem();
};
