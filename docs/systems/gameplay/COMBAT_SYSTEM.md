# Combat System - Target Locking and Damage Application

> **EVE-Inspired Combat Mechanics**  
> Signature Radius vs Scan Resolution targeting system

**Status:** Draft  
**Priority:** High  
**Milestone:** 3 - Fitting & Ship Attributes  
**Dependencies:** HUD Framework, Targeting UI, Ship Physics

---

## Overview

The Echoes combat system implements EVE Online-style target locking mechanics where a ship's ability to lock targets depends on the relationship between the target's **Signature Radius** and the attacker's **Scan Resolution**.

---

## Target Locking System

### Core Concept

**Formula:**
```
LockTime (seconds) = (40,000 / ScanResolution) × (SignatureRadius / ShipRadius)^(log(5.5) / log(ScanResolution / SignatureRadius))
```

**Simplified Approximation:**
```
LockTime ≈ (SignatureRadius / ScanResolution) × ScalingFactor

Where ScalingFactor ≈ 10-15 for typical ships
```

### Key Terms

**Signature Radius (Target Property):**
- Represents the ship's "radar cross-section"
- Measured in meters
- Larger ships have larger signatures
- Can be reduced by modules (signature reduction rigs)
- Increased when moving at high speed

**Scan Resolution (Attacker Property):**
- Represents targeting computer quality
- Measured in mm (millimeters)
- Higher values = faster target acquisition
- Improved by modules (sensor boosters)
- Different for each ship class

**Ship Radius (Target Property):**
- Physical size of the ship
- Used in lock time calculation
- Separate from signature radius

---

## Ship Signature Radii

### Default Values by Ship Class

| Ship Class | Signature Radius | Scan Resolution | Lock Range |
|------------|------------------|-----------------|------------|
| **Frigate** | 35-50m | 400-600 mm | 30-50 km |
| **Destroyer** | 60-80m | 300-450 mm | 40-60 km |
| **Cruiser** | 120-150m | 200-350 mm | 60-100 km |
| **Battlecruiser** | 250-300m | 150-250 mm | 80-120 km |
| **Battleship** | 400-500m | 100-200 mm | 100-150 km |
| **Carrier** | 2,800-3,200m | 50-100 mm | 150-250 km |

### Signature Radius Formula

```cpp
float CalculateSignatureRadius()
{
    // Base signature from ship type
    float BaseSignature = ShipStats.BaseSignatureRadius; // meters
    
    // Speed penalty
    float CurrentSpeed = GetPhysicsLinearVelocity().Size() / 100.0f; // m/s
    float MaxSpeed = ShipStats.MaxVelocity; // m/s
    float SpeedRatio = CurrentSpeed / MaxSpeed;
    
    // Signature increases with speed (up to 3x at max speed)
    float SpeedMultiplier = 1.0f + (SpeedRatio * SpeedRatio * 2.0f);
    
    // Module bonuses/penalties
    float ModuleMultiplier = 1.0f;
    ModuleMultiplier *= GetModuleBonus("SignatureRadius");
    
    // Final calculation
    return BaseSignature * SpeedMultiplier * ModuleMultiplier;
}
```

**Key Mechanics:**
- **At Rest:** Signature = Base value
- **At 50% Speed:** Signature = Base × 1.5
- **At 100% Speed:** Signature = Base × 3.0
- **Module Reduction:** -10% to -25% from signature reduction rigs
- **MWD Penalty:** Microwarpdrive increases signature by 500%

---

## Lock Time Calculation

### Implementation

```cpp
USTRUCT(BlueprintType)
struct FTargetLockData
{
    GENERATED_BODY()
    
    UPROPERTY(BlueprintReadOnly)
    AActor* Target;
    
    UPROPERTY(BlueprintReadOnly)
    float LockProgress; // 0.0 to 1.0
    
    UPROPERTY(BlueprintReadOnly)
    float TotalLockTime; // seconds
    
    UPROPERTY(BlueprintReadOnly)
    float ElapsedLockTime; // seconds
    
    UPROPERTY(BlueprintReadOnly)
    bool bIsLocked;
    
    UPROPERTY(BlueprintReadOnly)
    float Distance; // meters
};

float UEchoesCombatSystem::CalculateLockTime(AActor* Target)
{
    // Get ship stats
    float ScanResolution = ShipStats.ScanResolution; // mm
    
    // Get target properties
    auto TargetShip = Cast<AEchoesShipPawn>(Target);
    if (!TargetShip) return 0.0f;
    
    float TargetSignatureRadius = TargetShip->GetCurrentSignatureRadius(); // meters
    float TargetShipRadius = TargetShip->ShipStats.ShipRadius; // meters
    
    // EVE Online formula (simplified)
    float LockTime = (40000.0f / ScanResolution) * 
                     FMath::Pow(TargetSignatureRadius / TargetShipRadius, 
                                FMath::LogX(5.5f, ScanResolution / TargetSignatureRadius));
    
    // Apply module bonuses (Target Painters, Sensor Boosters)
    LockTime *= GetModuleBonus("TargetingSpeed");
    
    // Minimum lock time: 1 second
    return FMath::Max(1.0f, LockTime);
}
```

### Example Lock Times

**Frigate locking:**
- Frigate (35m sig): 1.2 seconds
- Cruiser (125m sig): 2.8 seconds
- Battleship (400m sig): 4.5 seconds

**Battleship locking:**
- Frigate (35m sig): 8.5 seconds
- Cruiser (125m sig): 5.2 seconds
- Battleship (400m sig): 3.8 seconds

**Key Insight:** Larger ships struggle to lock smaller ships quickly.

---

## Target Locking Process

### State Machine

```
┌──────────────────────────────────────────────────────┐
│              Target Lock State Machine                │
└──────────────────────────────────────────────────────┘

    [No Target]
        │
        │ Player clicks target
        ↓
    [Locking]
        │
        │ • Lock timer counting
        │ • Progress bar 0% → 100%
        │ • Can be interrupted
        │
        ├─ [Cancel] ────────→ [No Target]
        │
        ├─ [Out of Range] ──→ [Lock Lost]
        │
        ├─ [Target Destroyed] → [No Target]
        │
        │ Lock timer complete
        ↓
    [Locked]
        │
        │ • Can activate weapons
        │ • Target info displayed
        │ • Maintain range check
        │
        ├─ [Unlock Command] ──→ [No Target]
        │
        ├─ [Out of Range] ────→ [Lock Lost]
        │
        └─ [Target Destroyed] → [No Target]
```

### Implementation

```cpp
UCLASS()
class UEchoesTargetingSystem : public UActorComponent
{
    GENERATED_BODY()
    
public:
    // Maximum number of targets
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 MaxTargets = 3; // Frigate default
    
    // Current locked targets
    UPROPERTY(BlueprintReadOnly)
    TArray<FTargetLockData> LockedTargets;
    
    // Currently locking target
    UPROPERTY(BlueprintReadOnly)
    FTargetLockData LockingTarget;
    
    // Initiate target lock
    UFUNCTION(BlueprintCallable)
    bool Server_RequestTargetLock(AActor* Target);
    
    // Cancel lock attempt
    UFUNCTION(BlueprintCallable)
    void CancelTargetLock();
    
    // Unlock specific target
    UFUNCTION(BlueprintCallable)
    void Server_UnlockTarget(AActor* Target);
    
    // Unlock all targets
    UFUNCTION(BlueprintCallable)
    void UnlockAllTargets();
    
    // Update locking progress
    void TickComponent(float DeltaTime, 
                       enum ELevelTick TickType,
                       FActorComponentTickFunction* ThisTickFunction) override;
    
    // Events
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTargetLocked, AActor*, Target, float, LockTime);
    UPROPERTY(BlueprintAssignable)
    FOnTargetLocked OnTargetLocked;
    
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTargetLost, AActor*, Target);
    UPROPERTY(BlueprintAssignable)
    FOnTargetLost OnTargetLost;
    
private:
    void UpdateLockProgress(float DeltaTime);
    void CheckLockedTargetRanges();
    bool IsInLockRange(AActor* Target);
};
```

### Tick Update

```cpp
void UEchoesTargetingSystem::TickComponent(float DeltaTime, 
                                            enum ELevelTick TickType,
                                            FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    
    if (!HasAuthority()) return; // Server-authoritative
    
    // Update locking progress
    if (LockingTarget.Target)
    {
        UpdateLockProgress(DeltaTime);
    }
    
    // Check if locked targets are still in range
    CheckLockedTargetRanges();
}

void UEchoesTargetingSystem::UpdateLockProgress(float DeltaTime)
{
    LockingTarget.ElapsedLockTime += DeltaTime;
    LockingTarget.LockProgress = LockingTarget.ElapsedLockTime / LockingTarget.TotalLockTime;
    
    // Check if lock complete
    if (LockingTarget.LockProgress >= 1.0f)
    {
        // Lock acquired
        LockingTarget.bIsLocked = true;
        LockedTargets.Add(LockingTarget);
        
        // Broadcast event
        OnTargetLocked.Broadcast(LockingTarget.Target, LockingTarget.TotalLockTime);
        
        // Clear locking state
        LockingTarget = FTargetLockData();
    }
    
    // Check if out of range
    if (!IsInLockRange(LockingTarget.Target))
    {
        CancelTargetLock();
    }
}
```

---

## Range Mechanics

### Lock Range

**Formula:**
```
MaxLockRange = BaseLockRange × (1 + ModuleBonuses)

Example:
Frigate base: 50 km
With 2x Sensor Boosters (+25% each): 50 × 1.5 = 75 km
```

**Range Check:**
```cpp
bool UEchoesTargetingSystem::IsInLockRange(AActor* Target)
{
    if (!Target) return false;
    
    float Distance = FVector::Dist(GetOwner()->GetActorLocation(), 
                                   Target->GetActorLocation()) / 100.0f; // to meters
    
    float MaxRange = ShipStats.MaxLockRange; // km
    MaxRange *= GetModuleBonus("TargetingRange"); // Sensor Booster bonus
    
    return Distance <= (MaxRange * 1000.0f); // Convert km to m
}
```

### Optimal and Falloff Range (Weapons)

```cpp
float CalculateHitChance(float Distance, float OptimalRange, float FalloffRange)
{
    if (Distance <= OptimalRange)
    {
        return 1.0f; // 100% hit chance within optimal
    }
    
    float Overshoot = Distance - OptimalRange;
    float ChanceReduction = (Overshoot / FalloffRange) * (Overshoot / FalloffRange);
    
    float HitChance = 1.0f / (1.0f + ChanceReduction);
    
    return FMath::Clamp(HitChance, 0.0f, 1.0f);
}
```

**Example Weapon Ranges:**

| Weapon Type | Optimal Range | Falloff Range |
|-------------|---------------|---------------|
| Blasters | 2 km | 1 km |
| Pulse Lasers | 8 km | 4 km |
| Autocannons | 5 km | 8 km |
| Railguns | 40 km | 25 km |
| Missiles | N/A (always hit if in range) | N/A |

---

## Signature vs Scan Resolution

### Target Painters

**Module:** Increases target's signature radius

```cpp
void ApplyTargetPaint(AActor* Target, float BonusPercentage)
{
    auto TargetShip = Cast<AEchoesShipPawn>(Target);
    if (TargetShip)
    {
        float Multiplier = 1.0f + (BonusPercentage / 100.0f);
        TargetShip->SignatureRadiusMultiplier *= Multiplier;
        
        // Recalculate lock times for all ships locking this target
        UpdateAllLockTimesForTarget(Target);
    }
}
```

**Effect:**
- +25% signature radius = 25% faster locking
- Stacks with other painters (diminishing returns)
- Small ships become easier to lock

### Sensor Boosters

**Module:** Increases scan resolution and lock range

```cpp
USTRUCT(BlueprintType)
struct FSensorBoosterEffect
{
    GENERATED_BODY()
    
    UPROPERTY(EditAnywhere)
    float ScanResolutionBonus = 0.25f; // +25%
    
    UPROPERTY(EditAnywhere)
    float LockRangeBonus = 0.25f; // +25%
    
    UPROPERTY(EditAnywhere)
    bool bRequiresScriptCharge = false; // Optional charge for one bonus
};
```

**Effect:**
- +25% scan resolution = 25% faster locking
- +25% lock range = 25% longer range
- Cannot boost both without charge (choose one)

---

## Damage Application

### To-Hit Calculation

**Formula:**
```
HitChance = BaseAccuracy × RangeModifier × SignatureModifier × TrackingModifier
```

**Components:**

1. **Base Accuracy:** 0.5 (50% baseline)

2. **Range Modifier:**
   ```cpp
   float RangeModifier = CalculateHitChance(Distance, OptimalRange, FalloffRange);
   ```

3. **Signature Modifier:**
   ```cpp
   float SignatureModifier = TargetSignatureRadius / WeaponSignatureResolution;
   // Weapons have signature resolution (like ship scan resolution)
   // Smaller targets (< weapon sig res) are harder to hit
   ```

4. **Tracking Modifier:**
   ```cpp
   float AngularVelocity = CalculateAngularVelocity(Target);
   float TrackingModifier = WeaponTracking / (AngularVelocity + 0.01f);
   ```

### Damage Output

```cpp
float CalculateDamage(AActor* Target)
{
    // Base damage from weapon
    float BaseDamage = WeaponStats.BaseDamage;
    
    // Hit chance calculation
    float HitChance = CalculateHitChance(Target);
    
    // Roll to hit
    bool bHit = FMath::FRand() <= HitChance;
    
    if (!bHit)
    {
        return 0.0f; // Miss
    }
    
    // Apply damage multipliers
    float FinalDamage = BaseDamage;
    FinalDamage *= GetDamageTypeMultiplier(Target); // Shield/Armor/Hull
    FinalDamage *= GetResistanceReduction(Target);
    
    // Random variation (±5%)
    FinalDamage *= FMath::FRandRange(0.95f, 1.05f);
    
    return FinalDamage;
}
```

---

## Backend Integration

### API Endpoints

**Lock Target:**
```
POST /api/combat/target/lock
Body: {
    "characterId": "guid",
    "shipId": "guid",
    "targetId": "guid"
}

Response: {
    "success": true,
    "lockTime": 2.5,
    "targetSignatureRadius": 125.0,
    "distance": 45.2
}
```

**Get Target Info:**
```
GET /api/combat/target/{targetId}/info

Response: {
    "targetId": "guid",
    "targetName": "Enemy Cruiser",
    "shipType": "Cruiser",
    "signatureRadius": 125.0,
    "currentShield": 8500,
    "maxShield": 10000,
    "corporation": "Hostile Corp"
}
```

### Database Schema

```sql
CREATE TABLE CombatLogs (
    log_id BIGSERIAL PRIMARY KEY,
    attacker_id UUID NOT NULL,
    target_id UUID NOT NULL,
    weapon_type_id INT NOT NULL,
    damage_dealt DECIMAL(10,2),
    damage_type VARCHAR(50), -- Thermal, Kinetic, EM, Explosive
    hit_chance DECIMAL(5,4),
    was_hit BOOLEAN,
    distance_meters DECIMAL(10,2),
    timestamp TIMESTAMP DEFAULT NOW(),
    
    CONSTRAINT fk_attacker FOREIGN KEY (attacker_id) 
        REFERENCES Characters(character_id),
    CONSTRAINT fk_target FOREIGN KEY (target_id) 
        REFERENCES Characters(character_id)
);
```

---

## UI/UX

### Target Lock UI

**HUD Display:**
```
┌──────────────────────────────────────┐
│  Target: Enemy Cruiser               │
│  Distance: 45.2 km                   │
│  ┌─────────────────────┐             │
│  │ Locking... [████░░░░] 60%        │
│  └─────────────────────┘             │
│  Shield: ████████████░░░ 85%         │
│  Armor:  ████████████████ 100%       │
│  Hull:   ████████████████ 100%       │
└──────────────────────────────────────┘
```

**Multiple Targets:**
```
┌──────────────────┐  ┌──────────────────┐  ┌──────────────────┐
│ Target 1         │  │ Target 2         │  │ Target 3         │
│ Frigate          │  │ Cruiser          │  │ Locked [████]    │
│ 12.5 km          │  │ Locking... 45%   │  │ 28.3 km          │
│ Shield: 90%      │  │ Distance: 34 km  │  │ Shield: 60%      │
└──────────────────┘  └──────────────────┘  └──────────────────┘
```

### Hotkeys

| Key | Action |
|-----|--------|
| **Ctrl + Click** | Lock/unlock target |
| **F1-F7** | Select locked target slot |
| **Ctrl + Shift + E** | Unlock all targets |
| **Tab** | Cycle through targets |

---

## Testing Checklist

### Functional Tests
- [ ] Lock time calculated correctly for each ship class
- [ ] Target lock progress updates smoothly
- [ ] Lock completes when progress reaches 100%
- [ ] Out-of-range targets auto-unlock
- [ ] Maximum target limit enforced (3 for frigates)
- [ ] Signature radius changes with speed
- [ ] Module bonuses apply correctly

### Combat Tests
- [ ] Damage calculation accurate
- [ ] Hit/miss determination works
- [ ] Range modifiers apply correctly
- [ ] Signature modifier affects small targets
- [ ] Combat logs recorded in database

### Performance Tests
- [ ] 50 ships locking targets simultaneously
- [ ] No frame drops during target updates
- [ ] Network replication smooth with 150ms latency

---

## Future Enhancements

1. **Electronic Warfare**
   - ECM (Electronic Counter Measures) - breaks target locks
   - ECCM (Electronic Counter-Counter Measures) - resists ECM
   - Sensor dampeners - reduce lock range/scan resolution

2. **Advanced Targeting**
   - Target prediction for moving targets
   - Lead indicators for projectile weapons
   - Auto-targeting hostile ships

3. **Fleet Targeting**
   - Shared target locks
   - Fleet commander broadcast targets
   - Target priority system

---

**Status:** Draft  
**Last Updated:** 2026-01-31  
**Document Owner:** Combat Systems Team  
**Implementation Estimate:** 6-8 weeks
