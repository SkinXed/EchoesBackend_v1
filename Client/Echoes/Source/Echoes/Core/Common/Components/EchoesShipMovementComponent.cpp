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
    
    // Mass is already applied by physics system, no need to multiply here
    // InertiaMultiplier affects how quickly ship responds
    Force *= ShipStats.InertiaMultiplier;

    PrimitiveComponent->AddForce(Force, NAME_None, false);

    // Natural velocity limiting through linear damping
    // Max velocity is reached when F_thrust = v * Damping
    // Damping is applied automatically via InertiaMultiplier as linear damping
    // No need for hard velocity clamping - let physics handle it naturally
}

float UEchoesShipMovementComponent::Common_CalculateAlignTime() const
{
    // EVE-style formula: (Inertia * Mass) / Constant
    // InertiaMultiplier represents ship's inertia characteristic
    return (ShipStats.InertiaMultiplier * ShipStats.TotalMass) / AlignTimeConstant;
}

void UEchoesShipMovementComponent::Common_AlignToVector(float DeltaTime)
{
    if (!PrimitiveComponent || TargetDirection.IsNearlyZero())
    {
        return;
    }

    // Get current forward vector and angular velocity
    FVector CurrentForward = UpdatedComponent->GetForwardVector();
    FVector CurrentAngularVelocity = PrimitiveComponent->GetPhysicsAngularVelocityInRadians();
    
    // Calculate angle error between current and target direction
    FVector TargetForward = TargetDirection.GetSafeNormal();
    FVector CrossProduct = FVector::CrossProduct(CurrentForward, TargetForward);
    float DotProduct = FVector::DotProduct(CurrentForward, TargetForward);
    float AngleRadians = FMath::Acos(FMath::Clamp(DotProduct, -1.0f, 1.0f));
    
    // Axis of rotation (normalized cross product)
    FVector RotationAxis = CrossProduct.GetSafeNormal();
    
    // PD Controller for torque calculation
    // P (Proportional): Torque proportional to angle error
    FVector ProportionalTorque = RotationAxis * AngleRadians * PDController_kP * ShipStats.RotationSpeed;
    
    // D (Derivative): Damping torque to prevent overshoot
    // Project current angular velocity onto rotation axis
    float AngularVelocityOnAxis = FVector::DotProduct(CurrentAngularVelocity, RotationAxis);
    FVector DerivativeTorque = -RotationAxis * AngularVelocityOnAxis * PDController_kD * ShipStats.RotationSpeed;
    
    // Combined PD torque
    FVector TotalTorque = ProportionalTorque + DerivativeTorque;
    
    // Scale by ship mass for proper physics response
    TotalTorque *= ShipStats.TotalMass * 0.01f; // Scale factor for feel
    
    // Apply torque in radians
    PrimitiveComponent->AddTorqueInRadians(TotalTorque, NAME_None, false);
}

void UEchoesShipMovementComponent::Common_ApplyDamping(float DeltaTime)
{
    if (!PrimitiveComponent)
    {
        return;
    }

    FVector CurrentVelocity = PrimitiveComponent->GetPhysicsLinearVelocity();
    float CurrentSpeed = CurrentVelocity.Size();
    
    // Apply linear damping to simulate space drag and reach terminal velocity
    // F_damping = -v * DampingCoefficient
    // At equilibrium: F_thrust = v * DampingCoefficient, giving us max velocity
    // InertiaMultiplier serves as the damping coefficient
    
    if (CurrentSpeed > MinVelocityForDamping)
    {
        // Calculate damping force opposite to velocity direction
        FVector VelocityDirection = CurrentVelocity.GetSafeNormal();
        float DampingCoefficient = ShipStats.InertiaMultiplier * 10.0f; // Scale for feel
        FVector DampingForce = -VelocityDirection * CurrentSpeed * DampingCoefficient;
        
        PrimitiveComponent->AddForce(DampingForce, NAME_None, false);
    }
    else if (CurrentSpeed <= MinVelocityForDamping)
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

    // Check ship forward alignment with target
    FVector CurrentForward = UpdatedComponent->GetForwardVector();
    FVector ToTarget = (WarpTargetLocation - UpdatedComponent->GetComponentLocation()).GetSafeNormal();
    float ForwardDotProduct = FVector::DotProduct(CurrentForward, ToTarget);
    float AngleDegrees = FMath::RadiansToDegrees(FMath::Acos(FMath::Clamp(ForwardDotProduct, -1.0f, 1.0f)));

    bool bAligned = AngleDegrees <= WarpAlignmentThreshold;

    // Check speed
    FVector CurrentVelocity = PrimitiveComponent->GetPhysicsLinearVelocity();
    float CurrentSpeed = CurrentVelocity.Size();
    float RequiredSpeed = ShipStats.MaxVelocity * WarpSpeedThreshold;
    
    bool bAtSpeed = CurrentSpeed >= RequiredSpeed;

    // EVE-style: Check velocity vector alignment with target direction
    if (CurrentSpeed > 1.0f)
    {
        FVector VelocityDirection = CurrentVelocity.GetSafeNormal();
        float VelocityDotProduct = FVector::DotProduct(VelocityDirection, ToTarget);
        bool bVelocityAligned = VelocityDotProduct >= WarpVelocityAlignmentThreshold;
        
        return bAligned && bAtSpeed && bVelocityAligned;
    }

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
    FVector ForwardThrust = UpdatedComponent->GetForwardVector() * ShipStats.Thrust * ShipStats.InertiaMultiplier;
    PrimitiveComponent->AddForce(ForwardThrust, NAME_None, false);

    // Check if we can enter warp
    if (CanEnterWarp())
    {
        WarpState = EWarpState::Warping;
        WarpStateTime = 0.0f;
        WarpProgress = 0.0f;
        
        // Disable physics simulation for ray-based warp movement
        if (PrimitiveComponent->IsSimulatingPhysics())
        {
            PrimitiveComponent->SetSimulatePhysics(false);
        }
        
        UE_LOG(LogTemp, Log, TEXT("Entering warp state - physics disabled"));
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

    // Ray-based movement (physics disabled)
    FVector CurrentLocation = UpdatedComponent->GetComponentLocation();
    FVector DirectionToTarget = (WarpTargetLocation - CurrentLocation).GetSafeNormal();
    
    // Calculate warp velocity
    float WarpVelocity = ShipStats.MaxVelocity * WarpSpeedMultiplier * ShipStats.WarpSpeed;
    
    // Move along ray
    FVector NewLocation = CurrentLocation + (DirectionToTarget * WarpVelocity * DeltaTime);
    UpdatedComponent->SetWorldLocation(NewLocation, false);

    // Check distance to target
    float DistanceToTarget = FVector::Dist(CurrentLocation, WarpTargetLocation);
    float ExitDistance = WarpVelocity * 2.0f; // Exit distance based on speed

    if (DistanceToTarget <= ExitDistance)
    {
        WarpState = EWarpState::Exiting;
        WarpStateTime = 0.0f;
        
        // Re-enable physics for exit deceleration
        if (!PrimitiveComponent->IsSimulatingPhysics())
        {
            PrimitiveComponent->SetSimulatePhysics(true);
            // Set initial velocity for smooth transition
            PrimitiveComponent->SetPhysicsLinearVelocity(DirectionToTarget * WarpVelocity);
        }
        
        UE_LOG(LogTemp, Log, TEXT("Exiting warp state - physics re-enabled"));
    }
}

void UEchoesShipMovementComponent::HandleExitingState(float DeltaTime)
{
    if (!PrimitiveComponent)
    {
        return;
    }

    // Apply deceleration force opposite to velocity
    FVector CurrentVelocity = PrimitiveComponent->GetPhysicsLinearVelocity();
    float CurrentSpeed = CurrentVelocity.Size();

    if (CurrentSpeed > ShipStats.MaxVelocity * 1.1f)
    {
        // Apply strong braking force
        FVector VelocityDirection = CurrentVelocity.GetSafeNormal();
        FVector BrakingForce = -VelocityDirection * ShipStats.Thrust * 2.0f; // 2x thrust for braking
        PrimitiveComponent->AddForce(BrakingForce, NAME_None, false);
    }

    // Exit warp when speed is low enough
    if (CurrentSpeed <= ShipStats.MaxVelocity * 1.1f)
    {
        WarpState = EWarpState::Idle;
        WarpStateTime = 0.0f;
        SetMouseFollowEnabled(false);
        
        UE_LOG(LogTemp, Log, TEXT("Warp complete"));
    }
}
