// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesShipMovementComponent.h"
#include "GameFramework/Actor.h"
#include "Components/PrimitiveComponent.h"
#include "Kismet/KismetMathLibrary.h"

UEchoesShipMovementComponent::UEchoesShipMovementComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
    
    // Initialize defaults
    MovementInput = FVector::ZeroVector;
    TargetDirection = FVector::ForwardVector;
    bMouseFollowEnabled = false;
    WarpState = EWarpState::Idle;
    WarpProgress = 0.0f;
    WarpStateTime = 0.0f;
    PrimitiveComponent = nullptr;
}

void UEchoesShipMovementComponent::BeginPlay()
{
    Super::BeginPlay();
    
    // Cache the primitive component for physics operations
    if (UpdatedComponent)
    {
        PrimitiveComponent = Cast<UPrimitiveComponent>(UpdatedComponent);
        
        if (PrimitiveComponent && PrimitiveComponent->IsSimulatingPhysics())
        {
            // Set mass based on ship stats
            PrimitiveComponent->SetMassOverrideInKg(NAME_None, ShipStats.TotalMass, true);
            UE_LOG(LogTemp, Log, TEXT("Ship mass set to: %f kg"), ShipStats.TotalMass);
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("PrimitiveComponent is not simulating physics!"));
        }
    }
}

void UEchoesShipMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (!PrimitiveComponent || !PrimitiveComponent->IsSimulatingPhysics())
    {
        return;
    }

    // Update warp state machine
    Common_UpdateWarp(DeltaTime);

    // Only allow normal movement when not warping
    if (WarpState == EWarpState::Idle)
    {
        // Apply thrust from input
        Common_ApplyThrust(DeltaTime);
        
        // Apply damping when no input
        if (MovementInput.IsNearlyZero())
        {
            Common_ApplyDamping(DeltaTime);
        }

        // Align to mouse direction if enabled
        if (bMouseFollowEnabled)
        {
            Common_AlignToVector(DeltaTime);
        }
    }
}

// ==================== Initialization ====================

void UEchoesShipMovementComponent::InitializeShipStats(const FEchoesShipStats& NewStats)
{
    ShipStats = NewStats;
    
    if (PrimitiveComponent && PrimitiveComponent->IsSimulatingPhysics())
    {
        PrimitiveComponent->SetMassOverrideInKg(NAME_None, ShipStats.TotalMass, true);
        UE_LOG(LogTemp, Log, TEXT("Ship stats updated: Mass=%f, Thrust=%f"), 
            ShipStats.TotalMass, ShipStats.Thrust);
    }
}

// ==================== Input ====================

void UEchoesShipMovementComponent::SetMovementInput(FVector Input)
{
    MovementInput = Input.GetClampedToMaxSize(1.0f);
}

void UEchoesShipMovementComponent::SetTargetDirection(FVector Direction)
{
    if (!Direction.IsNearlyZero())
    {
        TargetDirection = Direction.GetSafeNormal();
    }
}

void UEchoesShipMovementComponent::SetMouseFollowEnabled(bool bEnabled)
{
    bMouseFollowEnabled = bEnabled;
}

// ==================== Physics Movement (Common_) ====================

void UEchoesShipMovementComponent::Common_ApplyThrust(float DeltaTime)
{
    if (!PrimitiveComponent || MovementInput.IsNearlyZero())
    {
        return;
    }

    // Get ship's local axes
    FRotator ShipRotation = UpdatedComponent->GetComponentRotation();
    FVector ForwardVector = ShipRotation.Vector();
    FVector RightVector = FRotationMatrix(ShipRotation).GetScaledAxis(EAxis::Y);
    FVector UpVector = FRotationMatrix(ShipRotation).GetScaledAxis(EAxis::Z);

    // Calculate thrust force in world space
    // X = forward/backward, Y = strafe left/right, Z = up/down
    FVector ThrustDirection = 
        (ForwardVector * MovementInput.X) +
        (RightVector * MovementInput.Y) +
        (UpVector * MovementInput.Z);

    ThrustDirection = ThrustDirection.GetSafeNormal();

    // Apply force based on thrust stat
    FVector Force = ThrustDirection * ShipStats.Thrust;
    
    // Scale by inertia multiplier
    Force *= ShipStats.InertiaMultiplier;

    PrimitiveComponent->AddForce(Force, NAME_None, false);

    // Clamp velocity to max
    FVector CurrentVelocity = PrimitiveComponent->GetPhysicsLinearVelocity();
    if (CurrentVelocity.Size() > ShipStats.MaxVelocity)
    {
        FVector ClampedVelocity = CurrentVelocity.GetSafeNormal() * ShipStats.MaxVelocity;
        PrimitiveComponent->SetPhysicsLinearVelocity(ClampedVelocity);
    }
}

void UEchoesShipMovementComponent::Common_AlignToVector(float DeltaTime)
{
    if (!PrimitiveComponent || TargetDirection.IsNearlyZero())
    {
        return;
    }

    // Get current forward vector
    FVector CurrentForward = UpdatedComponent->GetForwardVector();
    
    // Calculate target rotation to face the target direction
    FRotator TargetRotation = TargetDirection.Rotation();
    FRotator CurrentRotation = UpdatedComponent->GetComponentRotation();

    // Smoothly interpolate rotation using FMath::VInterpTo equivalent
    // We'll use RInterpTo for rotations
    FRotator NewRotation = FMath::RInterpTo(
        CurrentRotation, 
        TargetRotation, 
        DeltaTime, 
        RotationInterpSpeed
    );

    // Apply torque to rotate ship
    // Convert rotation delta to angular velocity
    FRotator RotationDelta = NewRotation - CurrentRotation;
    FVector AngularVelocity = FVector(
        FMath::DegreesToRadians(RotationDelta.Pitch),
        FMath::DegreesToRadians(RotationDelta.Yaw),
        FMath::DegreesToRadians(RotationDelta.Roll)
    ) / DeltaTime;

    // Scale by rotation speed stat and apply
    AngularVelocity *= ShipStats.RotationSpeed * 0.1f; // Scale factor for feel
    
    PrimitiveComponent->SetPhysicsAngularVelocityInRadians(AngularVelocity, false, NAME_None);
}

void UEchoesShipMovementComponent::Common_ApplyDamping(float DeltaTime)
{
    if (!PrimitiveComponent)
    {
        return;
    }

    FVector CurrentVelocity = PrimitiveComponent->GetPhysicsLinearVelocity();
    
    // Only apply damping if velocity is above minimum threshold
    if (CurrentVelocity.Size() > MinVelocityForDamping)
    {
        FVector DampedVelocity = CurrentVelocity * DampingFactor;
        PrimitiveComponent->SetPhysicsLinearVelocity(DampedVelocity);
    }
    else if (CurrentVelocity.Size() <= MinVelocityForDamping)
    {
        // Stop completely if very slow
        PrimitiveComponent->SetPhysicsLinearVelocity(FVector::ZeroVector);
    }
}

// ==================== Warp System ====================

void UEchoesShipMovementComponent::InitiateWarp(FVector TargetLocation)
{
    if (WarpState != EWarpState::Idle)
    {
        UE_LOG(LogTemp, Warning, TEXT("Cannot initiate warp - already warping"));
        return;
    }

    WarpTargetLocation = TargetLocation;
    WarpState = EWarpState::Aligning;
    WarpProgress = 0.0f;
    WarpStateTime = 0.0f;

    // Set target direction to warp destination
    FVector DirectionToTarget = (TargetLocation - UpdatedComponent->GetComponentLocation()).GetSafeNormal();
    SetTargetDirection(DirectionToTarget);
    SetMouseFollowEnabled(true);

    UE_LOG(LogTemp, Log, TEXT("Warp initiated to: %s"), *TargetLocation.ToString());
}

void UEchoesShipMovementComponent::CancelWarp()
{
    WarpState = EWarpState::Idle;
    WarpProgress = 0.0f;
    WarpStateTime = 0.0f;
    SetMouseFollowEnabled(false);
    
    UE_LOG(LogTemp, Log, TEXT("Warp cancelled"));
}

bool UEchoesShipMovementComponent::CanEnterWarp() const
{
    if (!PrimitiveComponent)
    {
        return false;
    }

    // Check alignment
    FVector CurrentForward = UpdatedComponent->GetForwardVector();
    FVector ToTarget = (WarpTargetLocation - UpdatedComponent->GetComponentLocation()).GetSafeNormal();
    float DotProduct = FVector::DotProduct(CurrentForward, ToTarget);
    float AngleDegrees = FMath::RadiansToDegrees(FMath::Acos(DotProduct));

    bool bAligned = AngleDegrees <= WarpAlignmentThreshold;

    // Check speed
    FVector CurrentVelocity = PrimitiveComponent->GetPhysicsLinearVelocity();
    float CurrentSpeed = CurrentVelocity.Size();
    float RequiredSpeed = ShipStats.MaxVelocity * WarpSpeedThreshold;
    
    bool bAtSpeed = CurrentSpeed >= RequiredSpeed;

    return bAligned && bAtSpeed;
}

void UEchoesShipMovementComponent::Common_UpdateWarp(float DeltaTime)
{
    WarpStateTime += DeltaTime;

    switch (WarpState)
    {
        case EWarpState::Aligning:
            HandleAligningState(DeltaTime);
            break;
            
        case EWarpState::Warping:
            HandleWarpingState(DeltaTime);
            break;
            
        case EWarpState::Exiting:
            HandleExitingState(DeltaTime);
            break;
            
        case EWarpState::Idle:
        default:
            break;
    }
}

void UEchoesShipMovementComponent::HandleAligningState(float DeltaTime)
{
    if (!PrimitiveComponent)
    {
        return;
    }

    // Continue aligning to target
    Common_AlignToVector(DeltaTime);

    // Apply forward thrust to build speed
    FVector ForwardThrust = UpdatedComponent->GetForwardVector() * ShipStats.Thrust;
    PrimitiveComponent->AddForce(ForwardThrust, NAME_None, false);

    // Check if we can enter warp
    if (CanEnterWarp())
    {
        WarpState = EWarpState::Warping;
        WarpStateTime = 0.0f;
        WarpProgress = 0.0f;
        
        UE_LOG(LogTemp, Log, TEXT("Entering warp state"));
    }

    // Timeout after 30 seconds
    if (WarpStateTime > 30.0f)
    {
        UE_LOG(LogTemp, Warning, TEXT("Warp alignment timeout"));
        CancelWarp();
    }
}

void UEchoesShipMovementComponent::HandleWarpingState(float DeltaTime)
{
    if (!PrimitiveComponent)
    {
        return;
    }

    // Disable normal control input during warp
    // Apply high-speed movement toward target
    FVector CurrentLocation = UpdatedComponent->GetComponentLocation();
    FVector DirectionToTarget = (WarpTargetLocation - CurrentLocation).GetSafeNormal();
    
    // Apply warp speed
    float WarpVelocity = ShipStats.MaxVelocity * WarpSpeedMultiplier * ShipStats.WarpSpeed;
    FVector WarpSpeed = DirectionToTarget * WarpVelocity;
    
    PrimitiveComponent->SetPhysicsLinearVelocity(WarpSpeed);

    // Check distance to target
    float DistanceToTarget = FVector::Dist(CurrentLocation, WarpTargetLocation);
    float ExitDistance = WarpVelocity * 2.0f; // Exit distance based on speed

    if (DistanceToTarget <= ExitDistance)
    {
        WarpState = EWarpState::Exiting;
        WarpStateTime = 0.0f;
        
        UE_LOG(LogTemp, Log, TEXT("Exiting warp state"));
    }
}

void UEchoesShipMovementComponent::HandleExitingState(float DeltaTime)
{
    if (!PrimitiveComponent)
    {
        return;
    }

    // Gradually decelerate
    FVector CurrentVelocity = PrimitiveComponent->GetPhysicsLinearVelocity();
    float CurrentSpeed = CurrentVelocity.Size();

    // Apply strong damping to slow down
    FVector DeceleratedVelocity = CurrentVelocity * 0.9f;
    PrimitiveComponent->SetPhysicsLinearVelocity(DeceleratedVelocity);

    // Exit warp when speed is low enough
    if (CurrentSpeed <= ShipStats.MaxVelocity * 1.1f)
    {
        WarpState = EWarpState::Idle;
        WarpStateTime = 0.0f;
        SetMouseFollowEnabled(false);
        
        UE_LOG(LogTemp, Log, TEXT("Warp complete"));
    }
}
