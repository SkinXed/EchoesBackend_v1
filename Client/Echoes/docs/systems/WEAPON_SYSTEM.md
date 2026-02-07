# Weapon System - CosmosWeaponComponent & CosmosProjectile

## Overview

The weapon system implements EVE-like ship-mounted weapons with accurate target prediction and ballistic projectile physics. The system consists of two main components:

1. **CosmosWeaponComponent** - USceneComponent attached to weapon mounts
2. **CosmosProjectile** - AActor for ballistic projectiles

## Architecture

**Design Pattern**: Deferred Actor Spawning
- Weapon spawns projectile in deferred mode
- Initializes projectile parameters before finishing spawn
- Allows configuration before actor fully enters world

**Authority**: Server-Authoritative
- Only server can fire weapons
- Only server applies damage on projectile hit
- Clients see replicated projectiles and visual effects

## CosmosProjectile Actor

### Purpose
Ballistic projectile with typed damage and collision detection.

### Components
- **USphereComponent**: Collision detection (5cm radius)
- **UStaticMeshComponent**: Visual representation
- **UProjectileMovementComponent**: Ballistic physics

### Key Features

#### 1. Deferred Initialization
```cpp
// Weapon spawns projectile (deferred)
ACosmosProjectile* Projectile = World->SpawnActorDeferred<ACosmosProjectile>(
    ProjectileClass, SpawnTransform, Owner, Instigator);

// Initialize before finishing spawn
Projectile->InitializeProjectile(150.0f, ECosmosDamageType::Kinetic, 100000.0f);

// Finish spawning
UGameplayStatics::FinishSpawningActor(Projectile, SpawnTransform);
```

#### 2. InitializeProjectile Method
```cpp
void InitializeProjectile(float NewDamage, ECosmosDamageType NewType, float NewSpeed);
```

**Parameters**:
- `NewDamage`: Raw damage before resistance mitigation
- `NewType`: Damage type (EM, Thermal, Kinetic, Explosive, Omni)
- `NewSpeed`: Projectile velocity in cm/s

**Behavior**:
- Sets `RawDamage` and `DamageType` properties
- Updates `ProjectileMovementComponent->InitialSpeed` and `MaxSpeed`
- Sets velocity vector based on forward direction

#### 3. Collision & Damage
On hit (server only):
1. Check if hit valid target (not self, not owner)
2. Try to find `CosmosAttributesComponent` on target
3. If found: Apply typed damage with resistance system
4. If not found: Use generic `ApplyDamage` fallback
5. Destroy projectile

#### 4. Auto-Destruction
- Default lifetime: 10 seconds
- Timer starts on `BeginPlay()`
- Prevents projectiles from accumulating in space

### Configuration

```cpp
// In Blueprint or C++
Projectile->MaxLifetime = 10.0f; // Seconds before auto-destroy
```

### Physics Properties
```cpp
// Default projectile movement settings
ProjectileMovementComponent->InitialSpeed = 100000.0f; // 1000 m/s
ProjectileMovementComponent->MaxSpeed = 100000.0f;
ProjectileMovementComponent->bRotationFollowsVelocity = true;
ProjectileMovementComponent->bShouldBounce = false;
ProjectileMovementComponent->ProjectileGravityScale = 0.0f; // Space!
```

## CosmosWeaponComponent

### Purpose
Ship-mounted weapon that calculates target prediction and fires projectiles.

### Inheritance
`USceneComponent` - Has position/rotation (attached to weapon socket)

### Weapon Statistics

```cpp
// In Blueprint or C++
WeaponComp->BaseDamage = 150.0f;
WeaponComp->DamageType = ECosmosDamageType::Kinetic;
WeaponComp->MuzzleVelocity = 100000.0f; // 1000 m/s = 100000 cm/s
WeaponComp->FireRate = 2.0f; // 2 shots per second
WeaponComp->ProjectileClass = ACosmosProjectile::StaticClass();
```

### Target Prediction System

#### Common_GetPredictionLocation()

**Purpose**: Calculate where to aim to hit a moving target.

**Algorithm**: First-Order Intercept

**Math**:
We need to solve: Where will target be when projectile arrives?

Given:
- Weapon position: `Pw`
- Target position: `Pt`
- Target velocity: `Vt`
- Projectile speed: `Vp`

We want to find time `t` when projectile reaches target:
```
|Pt + Vt*t - Pw| = Vp*t
```

This expands to a quadratic equation:
```
(Vt·Vt - Vp²)*t² + 2*(Pt-Pw)·Vt*t + |Pt-Pw|² = 0
```

Solve using quadratic formula, take smallest positive solution.

**Example Cases**:

1. **Stationary Target**:
   ```
   Target velocity = 0
   → Prediction = Current position
   ```

2. **Approaching Target**:
   ```
   Target moving toward weapon at 500 m/s
   Projectile speed = 1000 m/s
   → Leads slightly ahead
   ```

3. **Fleeing Target**:
   ```
   Target moving away at 500 m/s
   Projectile speed = 1000 m/s
   → Leads far ahead
   ```

4. **Perpendicular Target**:
   ```
   Target crossing at 500 m/s
   Projectile speed = 1000 m/s
   → Leads to side based on relative speeds
   ```

5. **Too Fast to Catch**:
   ```
   Target moving away at 1500 m/s
   Projectile speed = 1000 m/s
   → Returns closest approach point (time = 0)
   ```

**Code Example**:
```cpp
AActor* Target = GetTarget();
FVector PredictionPoint = WeaponComp->Common_GetPredictionLocation(Target);
FVector AimDirection = (PredictionPoint - WeaponComp->GetComponentLocation()).GetSafeNormal();
WeaponComp->SetWorldRotation(AimDirection.Rotation());
```

### Firing System

#### ServerOnly_Fire()

**Authority**: Server only

**Process**:
1. Validate server authority
2. Check projectile class is set
3. Check fire rate cooldown (CanFire)
4. Calculate spawn transform:
   - If target provided: Calculate prediction point, aim there
   - If no target: Fire in weapon's forward direction
5. Spawn projectile (deferred)
6. Initialize projectile with weapon stats
7. Finish spawning projectile
8. Set cooldown timer

**Example**:
```cpp
// Fire at target
void AShipPawn::FireWeapon(AActor* Target)
{
    if (HasAuthority())
    {
        WeaponComponent->ServerOnly_Fire(Target);
    }
}
```

#### Fire Rate & Cooldown

**Fire Rate**: Shots per second
- `1.0` = 1 shot per second (1s cooldown)
- `2.0` = 2 shots per second (0.5s cooldown)
- `0.5` = 1 shot per 2 seconds (2s cooldown)

**Cooldown Formula**:
```cpp
CooldownDuration = 1.0 / FireRate
```

**Helper Functions**:
```cpp
// Check if ready to fire
bool CanFire = WeaponComp->CanFire();

// Get remaining cooldown
float Remaining = WeaponComp->GetCooldownRemaining(); // Seconds
```

## Usage Examples

### 1. Setup Weapon on Ship

```cpp
void AShipPawn::SetupWeapon()
{
    // Create weapon component
    WeaponComp = CreateDefaultSubobject<UCosmosWeaponComponent>(TEXT("Weapon01"));
    
    // Attach to weapon socket on ship mesh
    WeaponComp->AttachToComponent(
        ShipMesh, 
        FAttachmentTransformRules::SnapToTargetIncludingScale,
        TEXT("WeaponSocket_01")
    );
    
    // Configure weapon stats (Kinetic autocannon)
    WeaponComp->ProjectileClass = ACosmosProjectile::StaticClass();
    WeaponComp->BaseDamage = 125.0f;
    WeaponComp->DamageType = ECosmosDamageType::Kinetic;
    WeaponComp->MuzzleVelocity = 150000.0f; // 1500 m/s
    WeaponComp->FireRate = 3.0f; // 3 rounds per second
}
```

### 2. Fire at Target with Auto-Targeting

```cpp
void AShipPawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    
    if (HasAuthority() && CurrentTarget)
    {
        // Auto-fire when cooldown ready
        if (WeaponComp->CanFire())
        {
            WeaponComp->ServerOnly_Fire(CurrentTarget);
        }
    }
}
```

### 3. Manual Aiming (NPC/Turret)

```cpp
void ATurretActor::AimAtTarget()
{
    if (!Target)
        return;
    
    // Get prediction point
    FVector PredictionPoint = WeaponComp->Common_GetPredictionLocation(Target);
    
    // Calculate rotation to prediction point
    FVector AimDirection = (PredictionPoint - WeaponComp->GetComponentLocation()).GetSafeNormal();
    FRotator TargetRotation = AimDirection.Rotation();
    
    // Smoothly rotate turret
    FRotator NewRotation = FMath::RInterpTo(
        GetActorRotation(),
        TargetRotation,
        GetWorld()->GetDeltaSeconds(),
        2.0f // Rotation speed
    );
    
    SetActorRotation(NewRotation);
    
    // Fire when aimed
    if (FVector::DotProduct(GetActorForwardVector(), AimDirection) > 0.98f) // ~11 degrees
    {
        WeaponComp->ServerOnly_Fire(Target);
    }
}
```

### 4. Different Weapon Types

#### Rapid-Fire Autocannon (Kinetic)
```cpp
WeaponComp->BaseDamage = 50.0f;
WeaponComp->DamageType = ECosmosDamageType::Kinetic;
WeaponComp->MuzzleVelocity = 200000.0f; // Fast projectiles
WeaponComp->FireRate = 10.0f; // High rate of fire
```

#### Heavy Railgun (Kinetic)
```cpp
WeaponComp->BaseDamage = 500.0f;
WeaponComp->DamageType = ECosmosDamageType::Kinetic;
WeaponComp->MuzzleVelocity = 500000.0f; // Extremely fast
WeaponComp->FireRate = 0.2f; // Slow fire rate
```

#### Laser Turret (Thermal)
```cpp
WeaponComp->BaseDamage = 150.0f;
WeaponComp->DamageType = ECosmosDamageType::Thermal;
WeaponComp->MuzzleVelocity = 1000000.0f; // Near-instant (speed of light)
WeaponComp->FireRate = 5.0f; // Medium rate
```

#### Missile Launcher (Explosive)
```cpp
WeaponComp->BaseDamage = 300.0f;
WeaponComp->DamageType = ECosmosDamageType::Explosive;
WeaponComp->MuzzleVelocity = 50000.0f; // Slower missiles
WeaponComp->FireRate = 0.5f; // Very slow reload
```

### 5. Integration with Attributes System

The weapon system automatically integrates with `CosmosAttributesComponent`:

```cpp
// In CosmosProjectile::OnHit()
UCosmosAttributesComponent* AttributesComp = 
    OtherActor->FindComponentByClass<UCosmosAttributesComponent>();

if (AttributesComp)
{
    // Apply typed damage with resistance mitigation
    AttributesComp->ServerOnly_ApplyDamage(RawDamage, DamageType, GetInstigator());
}
```

This means:
- Shield resists are automatically applied
- Armor resists are applied on overflow
- Structure resists are applied on further overflow
- Death events fire when structure depletes

### 6. UI Integration (Blueprint)

```cpp
// Health bar widget
void UWeaponWidget::UpdateCooldown()
{
    if (WeaponComp)
    {
        float Remaining = WeaponComp->GetCooldownRemaining();
        float CooldownDuration = 1.0f / WeaponComp->FireRate;
        float Progress = 1.0f - (Remaining / CooldownDuration);
        
        CooldownBar->SetPercent(Progress);
        
        if (WeaponComp->CanFire())
        {
            FireButton->SetIsEnabled(true);
        }
    }
}
```

## Prediction Accuracy

The First-Order Intercept algorithm is mathematically precise for:
- ✅ Constant velocity targets
- ✅ All speeds (subsonic to hypersonic)
- ✅ All angles (head-on, fleeing, perpendicular)
- ✅ Zero-velocity targets (reduces to straight aim)

**Limitations**:
- ❌ Does not account for target acceleration
- ❌ Does not account for projectile drop (but gravity is 0 in space)
- ❌ Does not account for weapon platform velocity (assumes stationary)

**Future Enhancements**:
- Second-Order Intercept for accelerating targets
- Platform velocity compensation
- Lead indicators for UI
- Accuracy falloff with range

## Performance Considerations

**CPU Cost**:
- Prediction calculation: ~50-100 instructions per frame
- One square root operation per prediction
- One quadratic solve per prediction
- Very cheap compared to physics simulation

**Optimization**:
- Prediction is only calculated when firing
- No tick required on weapon component
- Projectiles use built-in ProjectileMovementComponent (highly optimized)

**Network**:
- Projectiles replicate (bReplicates = true)
- Movement replicates (bReplicateMovement = true)
- Damage only applied on server (no double-damage)

## Testing Scenarios

### Test 1: Stationary Target
```
Target: 0 m/s velocity
Expected: Projectile hits exactly where target is
```

### Test 2: Moving Target (Perpendicular)
```
Target: 500 m/s perpendicular
Projectile: 1000 m/s
Expected: Leads target by ~30 degrees
```

### Test 3: Fleeing Target
```
Target: 800 m/s away
Projectile: 1000 m/s
Expected: Leads far ahead, catches target
```

### Test 4: Impossible Intercept
```
Target: 1500 m/s away
Projectile: 1000 m/s
Expected: Fires at closest approach point
```

### Test 5: Fire Rate
```
FireRate = 2.0 (2 shots/second)
Expected: 0.5s cooldown between shots
```

## Troubleshooting

### Issue: Projectiles miss moving targets

**Cause**: Target velocity not being detected

**Solution**:
1. Ensure target has MovementComponent
2. Or ensure root component is simulating physics
3. Check velocity is non-zero in logs

### Issue: Weapon fires too fast/slow

**Cause**: FireRate misconfiguration

**Solution**:
```cpp
// For X shots per second
WeaponComp->FireRate = X;

// For one shot every Y seconds
WeaponComp->FireRate = 1.0f / Y;
```

### Issue: Projectiles don't damage

**Cause**: Target missing CosmosAttributesComponent or collision disabled

**Solution**:
1. Add CosmosAttributesComponent to target
2. Check collision channels on projectile and target
3. Verify server authority (damage only on server)

---

**Status**: ✅ Implemented  
**Priority**: High  
**Milestone**: Combat System - Milestone 3  
**Dependencies**: CosmosAttributesComponent, EchoesCoreTypes.h  
**Last Updated**: 2026-02-06
