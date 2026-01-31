# Warp Mechanics - Ship States and FTL Travel

> **EVE-Inspired Warp Drive System**  
> Four-state system for faster-than-light travel with alignment mechanics

**Status:** Draft  
**Priority:** High  
**Milestone:** 3 - Fitting & Ship Attributes  
**Dependencies:** Ship Physics, Navigation System

---

## Overview

The warp mechanics system implements EVE Online-style FTL travel through a four-state process that requires ships to align to their destination before entering warp. This creates strategic gameplay around ship agility and travel time.

---

## Warp State Machine

### State Overview

```
┌─────────────────────────────────────────────────────────────┐
│                     Warp State Machine                       │
└─────────────────────────────────────────────────────────────┘

    [Idle] ──────────────────────────────────────────┐
      │                                                │
      │ Player initiates warp                         │
      │ (Double-click destination)                    │
      ↓                                                │
    [Aligning]                                         │
      │                                                │
      │ • Turn toward destination                     │
      │ • Accelerate to 75% max velocity             │
      │ • Check alignment < 5°                        │
      │                                                │
      ├─ [Cancel] ──────────────────────────┐        │
      │                                      ↓        │
      │ Conditions met:                  [Exiting]    │
      │ • Speed ≥ 75% max velocity          │        │
      │ • Angle ≤ 5° to destination         │        │
      ↓                                      │        │
    [Warping]                                │        │
      │                                      │        │
      │ • FTL velocity (10-100x normal)     │        │
      │ • Physics disabled                  │        │
      │ • Tunnel vision effect              │        │
      │                                      │        │
      │ Reach destination                   │        │
      │ (Distance < threshold)               │        │
      ↓                                      │        │
    [Exiting] ←──────────────────────────────┘       │
      │                                                │
      │ • Decelerate to normal velocity               │
      │ • Re-enable physics                           │
      │ • 2-second deceleration                       │
      ↓                                                │
    [Idle] ←────────────────────────────────────────┘
```

---

## State 1: Idle

**Description:** Normal sub-light flight mode

**Characteristics:**
- Full player control (thrust, rotation)
- Physics-based movement
- Can receive damage
- All ship systems active

**Transitions:**
- **To Aligning:** Player initiates warp (double-click destination, press warp hotkey)

**Visual Indicators:**
- Normal ship view
- HUD shows current velocity
- Navigation shows destination (if set)

---

## State 2: Aligning

**Description:** Ship turns toward destination and accelerates to warp-capable speed

### Purpose

Aligning creates strategic gameplay:
- **Agility matters:** Lighter ships align faster
- **Mass matters:** Heavier ships take longer to turn and accelerate
- **Vulnerability:** Ship is predictable and can be targeted
- **Skill factor:** Players must pre-align for quick escapes

### Requirements to Enter Warp

**Two conditions must be met simultaneously:**

1. **Speed Requirement:**
   ```
   CurrentSpeed ≥ 0.75 × MaxVelocity
   ```
   - Ship must reach 75% of maximum velocity
   - Accelerates using maximum thrust
   - Affected by ship mass and inertia

2. **Alignment Requirement:**
   ```
   AngleToDestination ≤ 5.0°
   ```
   - Ship forward vector must point within 5° of destination
   - Uses PD controller for smooth rotation
   - Affected by ship agility and rotation speed

### Behavior During Alignment

**Automatic Control:**
```cpp
void UEchoesWarpSystem::UpdateAligning(float DeltaTime)
{
    // 1. Rotate toward destination
    FVector ToDestination = (WarpDestination - ShipLocation).GetSafeNormal();
    FVector ShipForward = ShipMesh->GetForwardVector();
    
    FQuat TargetRotation = FQuat::FindBetweenVectors(ShipForward, ToDestination);
    float AngleError = FMath::RadiansToDegrees(TargetRotation.GetAngle());
    
    // Apply rotation torque
    ApplyAlignmentRotation(TargetRotation, DeltaTime);
    
    // 2. Accelerate forward
    ApplyMaxThrust(DeltaTime);
    
    // 3. Check if ready to warp
    if (CanEnterWarp())
    {
        EnterWarpState();
    }
}

bool UEchoesWarpSystem::CanEnterWarp()
{
    // Speed check
    float CurrentSpeed = ShipMesh->GetPhysicsLinearVelocity().Size();
    float RequiredSpeed = ShipStats.MaxVelocity * 100.0f * 0.75f; // cm/s
    
    if (CurrentSpeed < RequiredSpeed)
        return false;
    
    // Alignment check
    FVector ToDestination = (WarpDestination - ShipLocation).GetSafeNormal();
    FVector ShipForward = ShipMesh->GetForwardVector();
    
    float DotProduct = FVector::DotProduct(ShipForward, ToDestination);
    float AngleDegrees = FMath::RadiansToDegrees(FMath::Acos(DotProduct));
    
    return AngleDegrees <= 5.0f;
}
```

**Player Control:**
- Player can cancel warp (ESC key or stop command)
- Ship continues in Aligning state until cancelled or warp achieved
- Cannot activate modules during alignment (future: some modules allowed)

### Alignment Time Formula

**Factors affecting alignment time:**

```
AlignmentTime = RotationTime + AccelerationTime

Where:
  RotationTime = f(Agility, CurrentAngle, AngularDamping)
  AccelerationTime = f(Mass, Thrust, Inertia, CurrentSpeed)
```

**Example Calculations:**

| Ship Type | Mass (kg) | Agility | Thrust (N) | Alignment Time |
|-----------|-----------|---------|------------|----------------|
| Frigate   | 1,000,000 | 3.0     | 650,000    | 3-5 seconds    |
| Cruiser   | 12,000,000| 1.5     | 4,000,000  | 8-12 seconds   |
| Battleship| 100,000,000| 0.3    | 20,000,000 | 30-45 seconds  |

### Visual & Audio Feedback

**Visual:**
- **HUD:** "Aligning to destination..."
- **Destination marker:** Pulsing indicator
- **Ship orientation:** Arrow showing destination direction
- **Speed gauge:** Fills up to 75% threshold
- **Alignment indicator:** Angle meter (5° target)

**Audio:**
- Warp drive charging sound (increasing pitch)
- Thruster audio at maximum
- Computer voice: "Aligning to destination"

**Camera:**
- Slight shake from maximum thrust
- HUD elements pulse in sync with warp charge

---

## State 3: Warping

**Description:** FTL travel at warp speed

### Warp Speed Calculation

```cpp
float CalculateWarpSpeed()
{
    // Base warp speed from ship stats
    float BaseWarpSpeed = ShipStats.WarpSpeed; // AU/s
    
    // Modified by ship skills, modules
    float WarpSpeedModifier = 1.0f;
    WarpSpeedModifier *= SkillBonuses.WarpSpeed;
    WarpSpeedModifier *= ModuleBonuses.WarpSpeed;
    
    return BaseWarpSpeed * WarpSpeedModifier;
}

// Typical values:
// Frigate: 3 AU/s
// Cruiser: 2.5 AU/s  
// Battleship: 2 AU/s
// Interceptor: 8 AU/s
```

**Distance-to-Time:**
```
Time (seconds) = Distance (AU) / WarpSpeed (AU/s)

Example:
- 10 AU at 3 AU/s = 3.33 seconds
- 50 AU at 2 AU/s = 25 seconds
```

### Behavior During Warp

**Physics State:**
- **Physics Simulation:** Disabled
- **Collision:** Disabled (pass through objects)
- **Velocity:** Set directly (no forces applied)
- **Rotation:** Locked to destination

**Movement:**
```cpp
void UEchoesWarpSystem::UpdateWarping(float DeltaTime)
{
    // Calculate warp velocity
    FVector Direction = (WarpDestination - ShipLocation).GetSafeNormal();
    float WarpSpeed = CalculateWarpSpeed() * AU_TO_CM; // Convert to cm/s
    FVector WarpVelocity = Direction * WarpSpeed;
    
    // Set velocity directly (no physics)
    ShipMesh->SetPhysicsLinearVelocity(WarpVelocity, false);
    
    // Check if reached destination
    float DistanceRemaining = FVector::Dist(ShipLocation, WarpDestination);
    float DecelerationDistance = 15000.0f * 100.0f; // 15 km in cm
    
    if (DistanceRemaining <= DecelerationDistance)
    {
        EnterExitingState();
    }
}
```

**Systems State:**
- **Shields:** Active (regenerating)
- **Weapons:** Offline (cannot be activated)
- **Modules:** Offline (except passive)
- **Targeting:** Cleared (cannot lock targets)
- **Navigation:** Destination locked (cannot change mid-warp)

### Visual Effects

**Tunnel Vision:**
- Screen edges blur/distort
- Stars stretch into lines (warp streaks)
- Chromatic aberration effect
- Blue/purple warp field glow

**HUD:**
- "Warping to [Destination]"
- Distance remaining (updating)
- Estimated arrival time
- Cannot interact with most UI elements

**Camera:**
- Locked behind ship
- Gentle shake from warp field
- Zoom out slightly for speed sense

**Audio:**
- Warp tunnel ambient sound
- Muffled ship sounds
- Periodic "pulse" effect
- Radio chatter fades out

---

## State 4: Exiting

**Description:** Deceleration from warp speed to normal velocity

### Purpose

- **Smooth transition:** Prevents jarring instant stop
- **Vulnerability window:** Brief period of limited control
- **Cinematic effect:** Feels like "dropping out" of warp

### Deceleration Process

```cpp
void UEchoesWarpSystem::UpdateExiting(float DeltaTime)
{
    const float ExitDuration = 2.0f; // seconds
    
    ExitTimer += DeltaTime;
    float ExitProgress = ExitTimer / ExitDuration;
    
    // Ease out deceleration
    float EasedProgress = 1.0f - FMath::Pow(1.0f - ExitProgress, 3.0f);
    
    // Interpolate velocity
    FVector CurrentVelocity = ShipMesh->GetPhysicsLinearVelocity();
    float CurrentSpeed = CurrentVelocity.Size();
    float TargetSpeed = ShipStats.MaxVelocity * 100.0f; // Normal max speed
    
    float NewSpeed = FMath::Lerp(CurrentSpeed, TargetSpeed, EasedProgress);
    FVector NewVelocity = CurrentVelocity.GetSafeNormal() * NewSpeed;
    
    ShipMesh->SetPhysicsLinearVelocity(NewVelocity, false);
    
    // Re-enable systems gradually
    if (ExitProgress >= 0.5f)
    {
        EnableWeaponSystems();
        EnableTargeting();
    }
    
    // Complete exit
    if (ExitProgress >= 1.0f)
    {
        EnterIdleState();
    }
}
```

**Duration:** Fixed 2.0 seconds

**Systems Reactivation:**
- **0.0s:** Warp ends, exit begins
- **0.5s:** Targeting systems come online
- **1.0s:** Weapon systems available
- **1.5s:** Module activation allowed
- **2.0s:** Full control restored

### Behavior During Exit

**Player Control:**
- **Limited:** Cannot activate warp
- **Rotation:** Allowed (prepare for combat/docking)
- **Thrust:** Partially allowed (minor corrections)
- **Modules:** Gradual reactivation

**Physics:**
- **Physics Simulation:** Re-enabled at 1.0s
- **Collision:** Re-enabled at 1.0s
- **Velocity:** Decreasing exponentially

### Visual Effects

**Warp Exit Animation:**
- Warp tunnel collapses
- Stars return to normal (reverse stretch)
- Destination environment fades in
- Screen flash at exit point

**HUD:**
- "Exiting warp..."
- Systems status indicators (going green)
- Distance to destination (final)
- "Warp drive: Cooling down"

**Camera:**
- Returns to normal follow camera
- Slight zoom in as speed decreases
- Shake diminishes

**Audio:**
- Warp sound fades out
- Ship systems powering up (beeps, whirs)
- Radio chatter returns
- Computer voice: "Warp drive deactivated"

---

## Backend Integration

### API Endpoints

**Initiate Warp:**
```
POST /api/navigation/warp/initiate
Body: {
    "characterId": "guid",
    "shipId": "guid",
    "destinationId": "guid",
    "destinationType": "Station" | "Stargate" | "Bookmark"
}

Response: {
    "success": true,
    "alignmentTimeEstimate": 5.2,
    "warpTimeEstimate": 12.5,
    "totalTimeEstimate": 19.7
}
```

### Database Logging

```sql
CREATE TABLE WarpLogs (
    log_id BIGSERIAL PRIMARY KEY,
    character_id UUID NOT NULL,
    ship_id UUID NOT NULL,
    origin_system_id INT NOT NULL,
    destination_system_id INT NOT NULL,
    warp_initiated_at TIMESTAMP NOT NULL,
    warp_completed_at TIMESTAMP,
    alignment_time_seconds DECIMAL(5,2),
    warp_time_seconds DECIMAL(5,2),
    
    CONSTRAINT fk_character FOREIGN KEY (character_id) 
        REFERENCES Characters(character_id)
);
```

---

## Testing Checklist

### Functional Tests
- [ ] Ship can initiate warp from idle
- [ ] Ship aligns to destination correctly
- [ ] Alignment time scales with mass/agility
- [ ] Ship enters warp at 75% speed and < 5° alignment
- [ ] Warp speed calculated correctly
- [ ] Ship exits warp at destination
- [ ] Systems reactivate in correct order
- [ ] Warp can be cancelled during alignment

### Edge Cases
- [ ] Destination reached before warp entered (short distance)
- [ ] Player disconnects during warp
- [ ] Ship destroyed during alignment
- [ ] Multiple warp commands in quick succession

### Performance Tests
- [ ] 100 ships warping simultaneously
- [ ] Network bandwidth within limits
- [ ] No frame drops during state transitions

---

## Future Enhancements

1. **Warp Disruption**
   - Warp scramblers prevent warp
   - Warp bubbles (area denial)
   - Emergency warp exit

2. **Jump Gates**
   - Instant travel between systems
   - No alignment required
   - Toll fees

3. **Warp-to-Zero**
   - Precision warp landing
   - Skill-based distance reduction

---

**Status:** Draft  
**Last Updated:** 2026-01-31  
**Document Owner:** Physics & Navigation Team  
**Implementation Estimate:** 4-6 weeks
