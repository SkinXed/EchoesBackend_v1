// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/MovementComponent.h"
#include "Core/Common/EchoesShipTypes.h"
#include "EchoesShipMovementComponent.generated.h"

/**
 * EVE-like ship movement component
 * Implements physics-based movement with thrust, rotation, and warp mechanics
 * Follows naming convention: Common_ for shared methods, ServerRPC_/ClientRPC_ for network
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ECHOES_API UEchoesShipMovementComponent : public UMovementComponent
{
    GENERATED_BODY()

public:
    UEchoesShipMovementComponent();

protected:
    virtual void BeginPlay() override;

public:
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    // ==================== Ship Statistics ====================
    
    /** Current ship stats loaded from backend */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship Stats")
    FEchoesShipStats ShipStats;

    /** Initialize ship stats (typically from backend API response) */
    UFUNCTION(BlueprintCallable, Category = "Ship Stats")
    void InitializeShipStats(const FEchoesShipStats& NewStats);

    // ==================== Movement Input ====================
    
    /** Current movement input (-1 to 1 for each axis) */
    UPROPERTY(BlueprintReadOnly, Category = "Movement")
    FVector MovementInput;

    /** Target direction vector for alignment (e.g., from mouse cursor) */
    UPROPERTY(BlueprintReadOnly, Category = "Movement")
    FVector TargetDirection;

    /** Whether mouse follow is active */
    UPROPERTY(BlueprintReadOnly, Category = "Movement")
    bool bMouseFollowEnabled;

    /** Set movement input (WASD) */
    UFUNCTION(BlueprintCallable, Category = "Movement")
    void SetMovementInput(FVector Input);

    /** Set target direction for mouse follow */
    UFUNCTION(BlueprintCallable, Category = "Movement")
    void SetTargetDirection(FVector Direction);

    /** Enable/disable mouse follow */
    UFUNCTION(BlueprintCallable, Category = "Movement")
    void SetMouseFollowEnabled(bool bEnabled);

    // ==================== Warp System ====================
    
    /** Current warp state */
    UPROPERTY(BlueprintReadOnly, Category = "Warp")
    EWarpState WarpState;

    /** Target location for warp */
    UPROPERTY(BlueprintReadOnly, Category = "Warp")
    FVector WarpTargetLocation;

    /** Initiate warp to target location */
    UFUNCTION(BlueprintCallable, Category = "Warp")
    void InitiateWarp(FVector TargetLocation);

    /** Cancel current warp */
    UFUNCTION(BlueprintCallable, Category = "Warp")
    void CancelWarp();

    /** Check if ship can warp (alignment threshold) */
    UFUNCTION(BlueprintPure, Category = "Warp")
    bool CanEnterWarp() const;

protected:
    // ==================== Physics Movement (Common_) ====================
    
    /** Apply thrust forces based on input (WASD mechanics) */
    void Common_ApplyThrust(float DeltaTime);

    /** Align ship to target vector (mouse follow) */
    void Common_AlignToVector(float DeltaTime);

    /** Update warp state machine */
    void Common_UpdateWarp(float DeltaTime);

    /** Apply damping to velocity when no input */
    void Common_ApplyDamping(float DeltaTime);

    // ==================== Warp State Handlers ====================
    
    /** Handle aligning phase - turn toward target and build speed */
    void HandleAligningState(float DeltaTime);

    /** Handle warping phase - high speed transit */
    void HandleWarpingState(float DeltaTime);

    /** Handle exit phase - decelerate from warp */
    void HandleExitingState(float DeltaTime);

    // ==================== Configuration ====================
    
    /** Rotation interpolation speed for alignment */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement|Config")
    float RotationInterpSpeed = 2.0f;

    /** Alignment threshold in degrees to enter warp */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Warp|Config")
    float WarpAlignmentThreshold = 5.0f;

    /** Percentage of max speed required before entering warp */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Warp|Config")
    float WarpSpeedThreshold = 0.75f;

    /** Warp speed multiplier when in warp */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Warp|Config")
    float WarpSpeedMultiplier = 10.0f;

    /** Damping factor when no input (0-1) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement|Config")
    float DampingFactor = 0.98f;

    /** Minimum velocity threshold to apply damping */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement|Config")
    float MinVelocityForDamping = 1.0f;

private:
    /** Cached primitive component for physics */
    UPROPERTY()
    UPrimitiveComponent* PrimitiveComponent;

    /** Current warp progress (0-1) */
    float WarpProgress;

    /** Time spent in current warp state */
    float WarpStateTime;
};
