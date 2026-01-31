# Ship Physics - Damping, PD Controller and Warp Mechanics

> **EVE-Inspired Physics System for Echoes MMO**  
> Authentic space flight with proper physics simulation

---

## Overview

The Echoes ship physics system implements realistic space flight mechanics inspired by EVE Online, using Unreal Engine 5's physics engine with custom controllers for rotation and movement.

---

## Core Physics Principles

### 1. Newton's Laws in Space

**First Law (Inertia):**
- Ships maintain velocity unless acted upon by thrust
- No friction in space - ships don't slow down naturally
- **Damping** must be explicitly applied to simulate pilot control

**Second Law (F = ma):**
- Force (thrust) produces acceleration inversely proportional to mass
- Heavier ships accelerate slower
- Mass calculated from backend: `TotalMass = BaseMass + ΣModuleMass`

**Third Law (Action-Reaction):**
- Thrust applies force to ship
- Visual effects (engine flames) show thrust direction

### 2. Coordinate System

```
Unreal Engine Coordinates:
- X: Forward (ship nose)
- Y: Right (ship starboard)
- Z: Up (ship dorsal)

Thrust Directions:
- Forward: +X (main engines)
- Backward: -X (reverse thrusters)
- Strafe Right: +Y
- Strafe Left: -Y
- Strafe Up: +Z
- Strafe Down: -Z
```

---

## Movement System

### UEchoesShipMovementComponent

**Purpose:** Custom movement component for physics-based ship flight

**Key Properties:**
```cpp
// Ship stats from backend
UPROPERTY(Replicated, BlueprintReadOnly)
FEchoesShipStats ShipStats;

// Current velocity (replicated for prediction)
UPROPERTY(Replicated)
FVector CurrentVelocity;

// Input state
FVector ThrustInput;      // -1 to 1 per axis
FVector2D RotationInput;  // Pitch and Yaw

// Damping settings
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Physics")
float LinearDampingCoefficient = 2.0f;

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Physics")
float AngularDampingCoefficient = 5.0f;

// Rotation control
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Physics")
float RotationPGain = 1.0f;  // Proportional gain

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Physics")
float RotationDGain = 0.5f;  // Derivative gain
```

### Movement Tick

```cpp
void UEchoesShipMovementComponent::TickComponent(float DeltaTime, 
                                                  enum ELevelTick TickType, 
                                                  FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    
    if (!HasAuthority()) return; // Server-authoritative
    
    // 1. Apply thrust forces
    ApplyThrustForces(DeltaTime);
    
    // 2. Apply velocity damping
    ApplyVelocityDamping(DeltaTime);
    
    // 3. Apply rotation (PD controller)
    ApplyRotationControl(DeltaTime);
    
    // 4. Update warp state if active
    UpdateWarpState(DeltaTime);
}
```

---

## Thrust and Acceleration

### Linear Thrust

**Formula:**
```
Force = ThrustInput × MaxThrust
Acceleration = Force / TotalMass
NewVelocity = CurrentVelocity + Acceleration × DeltaTime
```

**Implementation:**
```cpp
void UEchoesShipMovementComponent::ApplyThrustForces(float DeltaTime)
{
    if (!ShipMesh || ThrustInput.IsNearlyZero()) return;
    
    // Get thrust force from ship stats
    float MaxThrust = ShipStats.Thrust;
    
    // Convert input to world space
    FVector WorldThrust = ShipMesh->GetComponentRotation().RotateVector(ThrustInput);
    
    // Calculate force
    FVector Force = WorldThrust * MaxThrust;
    
    // Apply to physics (F = ma)
    ShipMesh->AddForce(Force, NAME_None, false);
}
```

### Max Velocity Limiting

**Concept:** Ships have a maximum velocity (like EVE Online)

**Implementation:**
```cpp
void UEchoesShipMovementComponent::LimitMaxVelocity()
{
    FVector Velocity = ShipMesh->GetPhysicsLinearVelocity();
    float CurrentSpeed = Velocity.Size();
    float MaxSpeed = ShipStats.MaxVelocity * 100.0f; // Convert m/s to cm/s
    
    if (CurrentSpeed > MaxSpeed)
    {
        // Clamp to max speed
        FVector ClampedVelocity = Velocity.GetSafeNormal() * MaxSpeed;
        ShipMesh->SetPhysicsLinearVelocity(ClampedVelocity);
    }
}
```

---

## Velocity Damping

### The Problem

Without damping, ships would continue moving forever (Newton's First Law). While physically accurate, this makes ships impossible to control.

### The Solution: Damping

**Damping Formula:**
```
DampingForce = -Velocity × DampingCoefficient × Mass
```

This creates a force that opposes motion, simulating pilot corrections.

**Implementation:**
```cpp
void UEchoesShipMovementComponent::ApplyVelocityDamping(float DeltaTime)
{
    if (!ShipMesh) return;
    
    FVector Velocity = ShipMesh->GetPhysicsLinearVelocity();
    float Mass = ShipMesh->GetMass();
    
    // Calculate damping force
    // F_damping = -v × k × m
    // where k is damping coefficient
    FVector DampingForce = -Velocity * LinearDampingCoefficient * Mass;
    
    // Apply force
    ShipMesh->AddForce(DampingForce, NAME_None, false);
    
    // Also apply angular damping to rotation
    FVector AngularVelocity = ShipMesh->GetPhysicsAngularVelocityInRadians();
    FVector AngularDampingTorque = -AngularVelocity * AngularDampingCoefficient * Mass;
    
    ShipMesh->AddTorqueInRadians(AngularDampingTorque, NAME_None, false);
}
```

### Damping Coefficients

**Values:**
- `LinearDampingCoefficient = 2.0` - Stops ship in ~0.5 seconds when thrust released
- `AngularDampingCoefficient = 5.0` - Stops rotation quickly

**Effect of Ship Mass:**
- Heavier ships need more damping force (auto-scaled by mass)
- Feels consistent across all ship sizes

---

## Rotation Control (PD Controller)

### The Problem

Players want to rotate ships to a specific orientation (e.g., "face the mouse cursor"). Simply applying constant torque causes overshoot and oscillation.

### The Solution: PD Controller

**PD = Proportional-Derivative Controller**

**Formula:**
```
Error = DesiredRotation - CurrentRotation
Torque = Kp × Error + Kd × AngularVelocity
```

- **Proportional (P):** Corrects toward target (stronger when farther from target)
- **Derivative (D):** Dampens oscillation (opposes current rotation speed)

### Implementation

```cpp
void UEchoesShipMovementComponent::ApplyRotationControl(float DeltaTime)
{
    if (!ShipMesh || RotationInput.IsNearlyZero()) return;
    
    // Get desired rotation change from input
    float DesiredPitch = RotationInput.Y * ShipStats.RotationSpeed * DeltaTime;
    float DesiredYaw = RotationInput.X * ShipStats.RotationSpeed * DeltaTime;
    
    // Current angular velocity
    FVector AngularVelocity = ShipMesh->GetPhysicsAngularVelocityInRadians();
    
    // Calculate proportional term (error)
    FVector ProportionalTorque = FVector(DesiredPitch, DesiredYaw, 0) * RotationPGain;
    
    // Calculate derivative term (damping)
    FVector DerivativeTorque = -AngularVelocity * RotationDGain;
    
    // Combine PD terms
    FVector TotalTorque = (ProportionalTorque + DerivativeTorque) * ShipStats.RotationTorque;
    
    // Apply torque
    ShipMesh->AddTorqueInRadians(TotalTorque, NAME_None, false);
}
```

### Mouse-Follow Rotation

**Concept:** Right-click to make ship rotate toward camera direction

```cpp
void UEchoesShipMovementComponent::UpdateMouseFollowRotation(float DeltaTime)
{
    if (!bMouseFollowEnabled) return;
    
    // Get camera forward vector
    FVector CameraForward = PlayerController->PlayerCameraManager->GetActorForwardVector();
    FVector ShipForward = ShipMesh->GetForwardVector();
    
    // Calculate rotation needed
    FQuat TargetRotation = FQuat::FindBetweenVectors(ShipForward, CameraForward);
    
    // Get rotation error (angle between current and target)
    float AngleError = FMath::RadiansToDegrees(TargetRotation.GetAngle());
    
    // Apply PD control toward target
    if (AngleError > 1.0f) // Threshold to avoid jitter
    {
        FVector Axis = TargetRotation.GetRotationAxis();
        
        // Proportional term
        FVector PTorque = Axis * AngleError * RotationPGain;
        
        // Derivative term
        FVector AngularVel = ShipMesh->GetPhysicsAngularVelocityInRadians();
        FVector DTorque = -AngularVel * RotationDGain;
        
        // Apply
        FVector Torque = (PTorque + DTorque) * ShipStats.RotationTorque;
        ShipMesh->AddTorqueInRadians(Torque, NAME_None, false);
    }
}
```

---

## Warp Mechanics

### Warp State Machine

```
States:
1. Idle        - Normal flight
2. Aligning    - Turning toward destination + accelerating
3. Warping     - High-speed travel
4. Exiting     - Decelerating to normal speed
```

### State Diagram

```
     Idle
      |
      | [Initiate Warp]
      ↓
   Aligning ----[Cancel]---→ Exiting
      |                         ↓
      | [Aligned + Fast]       Idle
      ↓
   Warping
      |
      | [Reach Destination]
      ↓
   Exiting
      |
      ↓
     Idle
```

### Alignment Requirements

**To enter warp:**
1. **Speed requirement:** > 75% of max velocity
2. **Alignment requirement:** < 5° angle to destination

```cpp
bool UEchoesShipMovementComponent::CanEnterWarp()
{
    // Check speed
    FVector Velocity = ShipMesh->GetPhysicsLinearVelocity();
    float CurrentSpeed = Velocity.Size();
    float RequiredSpeed = ShipStats.MaxVelocity * 100.0f * 0.75f;
    
    if (CurrentSpeed < RequiredSpeed)
        return false;
    
    // Check alignment
    FVector Forward = ShipMesh->GetForwardVector();
    FVector ToDestination = (WarpDestination - ShipMesh->GetComponentLocation()).GetSafeNormal();
    float DotProduct = FVector::DotProduct(Forward, ToDestination);
    float AngleDegrees = FMath::RadiansToDegrees(FMath::Acos(DotProduct));
    
    return AngleDegrees < 5.0f;
}
```

### Warp Speed

**Formula:**
```
WarpSpeed = WarpSpeedMultiplier × MaxVelocity

Example:
- Frigate Max Velocity: 150 m/s
- Warp Multiplier: 10x
- Warp Speed: 1,500 m/s
```

**Implementation:**
```cpp
void UEchoesShipMovementComponent::EnterWarpState()
{
    WarpState = EWarpState::Warping;
    
    // Calculate warp velocity
    FVector Direction = (WarpDestination - ShipMesh->GetComponentLocation()).GetSafeNormal();
    float WarpSpeed = ShipStats.WarpSpeed * ShipStats.MaxVelocity * 100.0f;
    FVector WarpVelocity = Direction * WarpSpeed;
    
    // Set velocity directly (no physics during warp)
    ShipMesh->SetPhysicsLinearVelocity(WarpVelocity);
    
    // Disable control
    bControlsEnabled = false;
    
    // Visual effects
    PlayWarpEffects();
}
```

### Exiting Warp

**Deceleration:**
```cpp
void UEchoesShipMovementComponent::UpdateWarpExit(float DeltaTime)
{
    FVector Velocity = ShipMesh->GetPhysicsLinearVelocity();
    float CurrentSpeed = Velocity.Size();
    float TargetSpeed = ShipStats.MaxVelocity * 100.0f;
    
    // Decelerate over 2 seconds
    float DecelerationRate = (CurrentSpeed - TargetSpeed) / 2.0f;
    float NewSpeed = FMath::Max(CurrentSpeed - DecelerationRate * DeltaTime, TargetSpeed);
    
    FVector NewVelocity = Velocity.GetSafeNormal() * NewSpeed;
    ShipMesh->SetPhysicsLinearVelocity(NewVelocity);
    
    // Exit warp when at normal speed
    if (NewSpeed <= TargetSpeed)
    {
        WarpState = EWarpState::Idle;
        bControlsEnabled = true;
        StopWarpEffects();
    }
}
```

---

## Agility and Inertia

### Agility Modifier

**Concept:** Some ships turn faster than others (frigates vs. battleships)

**Backend Calculation:**
```csharp
// In ShipFittingService
float CalculateAgility(Ship ship, List<Module> modules)
{
    float baseAgility = ship.BaseAgility; // 0.5 to 3.0
    float modifiers = 1.0f;
    
    foreach (var module in modules)
    {
        modifiers *= module.AgilityModifier; // e.g., 0.9 = -10% agility
    }
    
    return baseAgility * modifiers;
}
```

**UE5 Application:**
```cpp
void UEchoesShipMovementComponent::ApplyShipStats(FEchoesShipStats Stats)
{
    ShipStats = Stats;
    
    // Set mass
    ShipMesh->SetMassOverrideInKg(NAME_None, Stats.TotalMass, true);
    
    // Agility affects rotation torque
    float AgilityMultiplier = Stats.Agility;
    float EffectiveRotationTorque = Stats.RotationTorque * AgilityMultiplier;
    
    // Store for use in rotation calculations
    ShipStats.RotationTorque = EffectiveRotationTorque;
}
```

### Inertia Modifier

**Concept:** Mass affects how quickly ships start/stop

**Formula:**
```
Acceleration = Force / (Mass × InertiaModifier)

InertiaModifier examples:
- 1.0 = Normal inertia
- 0.8 = 20% less inertia (faster acceleration)
- 1.2 = 20% more inertia (slower acceleration)
```

**Implementation:**
```cpp
// Inertia modifier scales the effective mass for acceleration
float EffectiveMass = ShipStats.TotalMass * ShipStats.InertiaModifier;
ShipMesh->SetMassOverrideInKg(NAME_None, EffectiveMass, true);
```

---

## Camera System

### Spring Arm Camera

**Purpose:** Camera lags behind ship to show movement

```cpp
UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
USpringArmComponent* SpringArm;

UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
UCameraComponent* Camera;

void AEchoesShipPawn::SetupCamera()
{
    // Spring arm for smooth camera
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    SpringArm->SetupAttachment(RootComponent);
    SpringArm->TargetArmLength = 2000.0f;
    SpringArm->bEnableCameraLag = true;
    SpringArm->CameraLagSpeed = 3.0f;
    SpringArm->bEnableCameraRotationLag = true;
    SpringArm->CameraRotationLagSpeed = 5.0f;
    
    // Camera
    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(SpringArm);
}
```

**Effect:** Camera smoothly follows ship, showing mass and momentum

---

## Performance Optimization

### Physics Substepping

**Problem:** Physics calculations at 60 FPS may miss collisions or be unstable

**Solution:** Substep physics multiple times per frame

```cpp
// In ship mesh component setup
ShipMesh->SetPhysicsMaxAngularVelocityInDegrees(360.0f);
ShipMesh->BodyInstance.bSimulatePhysics = true;
ShipMesh->BodyInstance.bUseCCD = true; // Continuous Collision Detection
```

### Network Optimization

**Client Prediction:**
```cpp
void UEchoesShipMovementComponent::TickComponent(float DeltaTime)
{
    if (HasAuthority())
    {
        // Server: Authoritative physics
        UpdatePhysics(DeltaTime);
    }
    else
    {
        // Client: Predict movement
        PredictMovement(DeltaTime);
    }
}

void UEchoesShipMovementComponent::OnRep_CurrentVelocity()
{
    // Correct prediction when server update arrives
    if (!HasAuthority())
    {
        ShipMesh->SetPhysicsLinearVelocity(CurrentVelocity);
    }
}
```

---

## Debug Visualization

### Debug Commands

```cpp
// Console commands for testing
void UEchoesShipMovementComponent::DebugDrawPhysics()
{
    if (!ShipMesh) return;
    
    FVector Location = ShipMesh->GetComponentLocation();
    FVector Velocity = ShipMesh->GetPhysicsLinearVelocity();
    FVector AngularVelocity = ShipMesh->GetPhysicsAngularVelocityInRadians();
    
    // Draw velocity vector
    DrawDebugLine(GetWorld(), Location, Location + Velocity, 
                  FColor::Green, false, -1, 0, 5.0f);
    
    // Draw thrust direction
    FVector ThrustDir = ShipMesh->GetForwardVector() * ThrustInput.X;
    DrawDebugLine(GetWorld(), Location, Location + ThrustDir * 1000.0f, 
                  FColor::Red, false, -1, 0, 3.0f);
    
    // Print stats
    UE_LOG(LogTemp, Display, TEXT("Speed: %.1f m/s, Mass: %.0f kg"), 
           Velocity.Size() / 100.0f, ShipMesh->GetMass());
}
```

---

## Summary

**Key Components:**
1. **Physics-based movement** using UE5's force/torque system
2. **Velocity damping** for controllability
3. **PD controller** for smooth rotation
4. **Warp mechanics** with alignment and speed requirements
5. **Backend-driven stats** (mass, thrust, agility)

**Design Philosophy:**
- Server-authoritative
- Physics-accurate
- EVE-inspired feel
- Responsive controls

---

**Last Updated:** 2026-01-31  
**Status:** Implemented  
**Version:** 1.0
