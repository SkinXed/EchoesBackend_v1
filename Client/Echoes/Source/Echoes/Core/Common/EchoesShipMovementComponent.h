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

    /** Align ship to target vector using PD controller for torque */
    void Common_AlignToVector(float DeltaTime);

    /** Update warp state machine */
    void Common_UpdateWarp(float DeltaTime);

    /** Apply linear damping based on velocity and InertiaMultiplier */
    void Common_ApplyDamping(float DeltaTime);

    /** Calculate alignment time using EVE formula: (Inertia * Mass) / 500,000 */
    UFUNCTION(BlueprintPure, Category = "Ship Stats")
    float Common_CalculateAlignTime() const;

    // ==================== Warp State Handlers ====================
    
    /** Handle aligning phase - turn toward target and build speed */
    void HandleAligningState(float DeltaTime);

    /** Handle warping phase - high speed transit */
    void HandleWarpingState(float DeltaTime);

    /** Handle exit phase - decelerate from warp */
    void HandleExitingState(float DeltaTime);

    // ==================== Configuration ====================
    
    /** PD Controller Proportional gain for alignment torque */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement|Config|PD Controller")
    float PDController_kP = 5.0f;

    /** PD Controller Derivative gain for damping */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement|Config|PD Controller")
    float PDController_kD = 2.0f;

    /** Rotation interpolation speed for alignment (deprecated, use PD controller) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement|Config")
    float RotationInterpSpeed = 2.0f;

    /** Alignment threshold in degrees to enter warp */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Warp|Config")
    float WarpAlignmentThreshold = 5.0f;

    /** Percentage of max speed required before entering warp */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Warp|Config")
    float WarpSpeedThreshold = 0.75f;

    /** Velocity vector alignment threshold (dot product) for warp entry */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Warp|Config")
    float WarpVelocityAlignmentThreshold = 0.95f;

    /** Warp speed multiplier when in warp */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Warp|Config")
    float WarpSpeedMultiplier = 10.0f;

    /** Damping factor when no input (0-1) - DEPRECATED, use linear damping */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement|Config")
    float DampingFactor = 0.98f;

    /** Minimum velocity threshold to apply damping */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement|Config")
    float MinVelocityForDamping = 1.0f;

    /** Constant for align time calculation (EVE formula) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement|Config")
    float AlignTimeConstant = 500000.0f;

private:
    /** Cached primitive component for physics */
    UPROPERTY()
    UPrimitiveComponent* PrimitiveComponent;

    /** Current warp progress (0-1) */
    float WarpProgress;

    /** Time spent in current warp state */
    float WarpStateTime;
};
