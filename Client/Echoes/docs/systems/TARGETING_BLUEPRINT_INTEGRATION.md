# Target Lock System - Blueprint Integration Guide

## Overview

The **UTargetingComponent** provides an EVE-like target lock system for ship-to-ship combat with full Blueprint support. This guide explains how to integrate the targeting system with UI widgets and gameplay logic.

## Architecture

**Network Model**: Client-Server
- **Client**: Initiates lock requests, displays UI feedback
- **Server**: Validates requests, manages lock timers, controls state
- **Replication**: TargetLocks array replicates to clients for UI updates

**Lock Formula**: `T = k / (ScanResolution × ln(TargetSize))`
- `T` = Lock time in seconds
- `k` = LockTimeConstant (default: 40000)
- `ScanResolution` = Ship's scan resolution stat (default: 100)
- `TargetSize` = Target's signature radius in meters

## Component Setup

### Adding to Ship Pawn

**In C++**:
```cpp
// In ship pawn constructor
TargetingComp = CreateDefaultSubobject<UTargetingComponent>(TEXT("Targeting"));

// Configure (optional)
TargetingComp->MaxLockRange = 2500000.0f; // 25km
TargetingComp->ScanResolution = 100.0f;
TargetingComp->LockTimeConstant = 40000.0f;
TargetingComp->MaxSimultaneousLocks = 5;
```

**In Blueprint**:
1. Open ship pawn Blueprint
2. Add Component → Search "Targeting Component"
3. Configure properties in Details panel:
   - **Max Lock Range**: 2500000 (25km in cm)
   - **Scan Resolution**: 100
   - **Lock Time Constant**: 40000
   - **Max Simultaneous Locks**: 5

## Blueprint API

### Functions (BlueprintCallable)

#### ServerRPC_StartLock
Request target lock acquisition (client calls, server executes).

**Parameters**:
- `Target` (Actor): The actor to lock onto

**Usage**:
```
Event: On Mouse Click Target
  ↓
Get Targeting Component
  ↓
ServerRPC_StartLock (Target = Clicked Actor)
```

**Example**:
When player clicks on enemy ship, call this to initiate lock.

#### ServerRPC_CancelLock
Cancel an active lock.

**Parameters**:
- `Target` (Actor): The actor to cancel lock on

#### ServerRPC_ClearAllLocks
Clear all active locks.

### Pure Functions (BlueprintPure)

These functions can be used in Blueprint graphs without execution pins.

#### Common_GetLockProgress
Get lock progress for a specific target.

**Returns**: `float` (0.0 to 1.0), or -1.0 if not found

**Usage**:
```
Get Targeting Component
  ↓
Common_GetLockProgress (Target)
  ↓
Set Progress Bar Percent
```

#### Common_GetLockState
Get lock state for a specific target.

**Returns**: `ETargetLockState` (None, Locking, Locked, Lost)

#### Common_IsTargetLocked
Check if target is fully locked.

**Returns**: `bool` (True if locked)

#### Common_GetLockedTargets
Get all currently locked targets.

**Returns**: `Array<Actor>` (All locked targets)

#### Common_GetAvailableLockSlots
Get number of available lock slots.

**Returns**: `int32` (Remaining slots)

#### Common_IsTargetInRange
Check if target is within lock range.

**Returns**: `bool` (True if in range)

#### Common_CalculateLockTime
Calculate required lock time for target.

**Returns**: `float` (Time in seconds)

## Blueprint Events

### OnLockStarted
Fired when lock acquisition begins.

**Parameters**:
- `Target` (Actor): Target being locked

**Usage**:
```
Event OnLockStarted
  ↓
Create Lock Frame Widget
  ↓
Add to Viewport
```

### OnLockCompleted
Fired when lock acquisition completes.

**Parameters**:
- `Target` (Actor): Target that was locked

**Usage**:
```
Event OnLockCompleted
  ↓
Play Lock Sound Effect
  ↓
Update Lock Frame to "Locked" State
```

### OnLockLost
Fired when lock is lost (out of range, target destroyed, etc.).

**Parameters**:
- `Target` (Actor): Target that lost lock

**Usage**:
```
Event OnLockLost
  ↓
Remove Lock Frame Widget
  ↓
Play Warning Sound
```

### OnLockProgress
Fired every tick during lock acquisition with progress update.

**Parameters**:
- `Target` (Actor): Target being locked
- `Progress` (float): Progress from 0.0 to 1.0

**Usage**:
```
Event OnLockProgress
  ↓
Update Progress Bar
  ↓
Update Lock Frame Animation
```

## UI Widget Implementation

### Lock Frame Widget

**Purpose**: Display locking progress on target with animated frame.

#### Widget Structure
```
Canvas Panel
├─ Lock Frame Image (Border)
├─ Progress Ring (Material with progress parameter)
├─ Target Name (Text Block)
├─ Lock Status (Text Block: "Locking..." or "Locked")
└─ Distance (Text Block)
```

#### Blueprint Implementation

**1. Widget Variables**:
```
- TargetActor (Actor)
- TargetingComponent (Targeting Component)
- LockProgress (Float): 0.0 to 1.0
- IsLocked (Bool)
```

**2. Event Construct**:
```
Event Construct
  ↓
Get Owning Player Pawn
  ↓
Get Component By Class (Targeting Component)
  ↓
Store in Variable
  ↓
Bind Events:
  - OnLockStarted → Update UI
  - OnLockCompleted → Set Locked State
  - OnLockLost → Remove Widget
  - OnLockProgress → Update Progress
```

**3. Event Tick**:
```
Event Tick
  ↓
Is Valid? (TargetActor)
  ↓ Yes
Project World to Screen (TargetActor Location)
  ↓
Set Widget Position (Screen Position)
  ↓
Get Lock Progress (TargetActor)
  ↓
Update Progress Ring Material Parameter
  ↓
Update Lock Status Text
```

**4. Update Progress Function**:
```
Function: UpdateProgress
  ↓
Get Lock Progress (Target)
  ↓
Branch: Progress >= 1.0?
  ↓ Yes: Set Status Text = "LOCKED"
  ↓      Set Frame Color = Green
  ↓      Play Lock Complete Animation
  ↓
  ↓ No:  Set Status Text = "LOCKING..."
         Set Frame Color = Yellow
         Update Progress Ring (0.0 to 1.0)
```

### Lock Frame Material

**Material Parameters**:
- `Progress` (Scalar): 0.0 to 1.0 for circular progress
- `Color` (Vector): Frame color (Yellow for locking, Green for locked)
- `Thickness` (Scalar): Frame line thickness

**Material Logic**:
```
UV Coordinates
  ↓
Radial Gradient (Center to Edge)
  ↓
Compare: Angle < (Progress × 360°)
  ↓
Mask for Progress Ring
  ↓
Multiply by Color
```

### Targeting HUD Widget

**Purpose**: Display all active locks and available slots.

#### Widget Structure
```
Vertical Box (Lock List)
├─ For Each Locked Target:
│   ├─ Target Name
│   ├─ Lock Status Icon
│   └─ Distance
└─ Lock Slots Display: "5/5 Locks Available"
```

#### Blueprint Implementation

**Event Tick**:
```
Event Tick
  ↓
Get Targeting Component
  ↓
Get Locked Targets
  ↓
Clear Lock List Widget
  ↓
For Each Target:
  ↓
  Create Lock Entry Widget
  ↓
  Set Target Name
  ↓
  Set Lock Icon (Locked/Locking)
  ↓
  Calculate Distance
  ↓
  Add to Lock List
  ↓
Get Available Lock Slots
  ↓
Update Slots Display: "X/5 Locks"
```

## Usage Examples

### Example 1: Basic Target Lock on Click

**PlayerController Blueprint**:
```
Event: Mouse Left Click
  ↓
Line Trace by Channel (From Camera)
  ↓
Did Hit?
  ↓ Yes
Get Hit Actor
  ↓
Get Targeting Component (From Player Pawn)
  ↓
Is Target In Range? (Hit Actor)
  ↓ Yes
Get Available Lock Slots > 0?
  ↓ Yes
ServerRPC_StartLock (Hit Actor)
  ↓
Create Lock Frame Widget
  ↓
Add to Viewport
```

### Example 2: Lock All Targets in Range

**Blueprint Function**: `LockAllHostiles`
```
Get Targeting Component
  ↓
Get All Actors of Class (Enemy Ships)
  ↓
For Each Enemy:
  ↓
  Is Target In Range? (Enemy)
  ↓ Yes
  Get Available Lock Slots > 0?
  ↓ Yes
  ServerRPC_StartLock (Enemy)
```

### Example 3: Display Lock Progress Bar

**Lock Frame Widget Blueprint**:
```
Event OnLockProgress (Target, Progress)
  ↓
Set Progress Bar Percent (Progress)
  ↓
Format Text: "{0}%" (Progress × 100)
  ↓
Set Text Block Text
  ↓
Update Material Parameter "Progress" (Progress)
```

### Example 4: Cancel Lock on Right Click

**PlayerController Blueprint**:
```
Event: Mouse Right Click
  ↓
Line Trace by Channel (From Camera)
  ↓
Did Hit?
  ↓ Yes
Get Hit Actor
  ↓
Get Targeting Component
  ↓
Is Target Locked? (Hit Actor)
  ↓ Yes
ServerRPC_CancelLock (Hit Actor)
  ↓
Remove Lock Frame Widget
```

### Example 5: Auto-Cancel Locks Out of Range

**Ship Pawn Blueprint** (Event Tick):
```
Event Tick
  ↓
Get Targeting Component
  ↓
Get Locked Targets
  ↓
For Each Target:
  ↓
  Is Target In Range? (Target)
  ↓ No
  ServerRPC_CancelLock (Target)
  ↓
  Display Warning: "Lock Lost - Out of Range"
```

## Advanced Features

### Lock Priority System

Implement lock priority based on threat level:

**Blueprint Function**: `SortTargetsByThreat`
```
Get Locked Targets
  ↓
For Each Target:
  ↓
  Calculate Threat Score:
    - Distance (closer = higher threat)
    - Ship Size (larger = higher threat)
    - DPS (higher = higher threat)
  ↓
Sort by Threat Score (Descending)
  ↓
Return Sorted Array
```

### Lock Target Cycling

Implement Tab key to cycle through locked targets:

**Input Action**: `CycleTarget`
```
Event: Tab Key Pressed
  ↓
Get Locked Targets
  ↓
Get Current Target Index
  ↓
Increment Index (Wrap around)
  ↓
Set Selected Target (New Index)
  ↓
Update Camera Focus
```

### Lock Sound Effects

Add audio feedback for lock events:

**Event OnLockStarted**:
```
Event OnLockStarted
  ↓
Play Sound 2D (Lock Start Beep)
```

**Event OnLockCompleted**:
```
Event OnLockCompleted
  ↓
Play Sound 2D (Lock Complete Tone)
```

**Event OnLockProgress** (Optional - Pitch Increase):
```
Event OnLockProgress (Target, Progress)
  ↓
Calculate Pitch: 1.0 + (Progress × 0.5)
  ↓
Play Sound 2D (Lock Progress Beep, Pitch)
```

## Lock Frame Visual Styles

### Style 1: EVE Online Style
- Circular rotating frame
- Progress ring fills clockwise
- Yellow during lock, green when locked
- Target name and distance in center

### Style 2: X-Wing Style
- Square brackets at corners
- Brackets animate inward during lock
- Target lead indicator
- Lock tone increases in frequency

### Style 3: Modern Sci-Fi
- Hexagonal frame
- Holographic material
- Scan lines animation
- Glitch effect during acquisition

## Performance Considerations

### Optimization Tips

1. **Widget Pooling**: Reuse lock frame widgets instead of creating/destroying
2. **Update Frequency**: Update UI at 30 FPS instead of 60 FPS for lock frames
3. **Distance Checks**: Only update visible lock frames (on screen)
4. **Material Instances**: Use dynamic material instances for progress rings
5. **Event Throttling**: Throttle OnLockProgress events to reduce widget updates

### Best Practices

1. **Null Checks**: Always validate TargetActor before accessing
2. **Component Validation**: Cache Targeting Component reference on construct
3. **Widget Cleanup**: Remove widgets on OnLockLost event
4. **Memory Management**: Clear references when widgets are removed
5. **Network Bandwidth**: Don't spam StartLock requests (add local cooldown)

## Debugging

### Common Issues

**Issue**: Lock frame doesn't appear
**Solution**: Check OnLockStarted event is bound and widget is added to viewport

**Issue**: Progress doesn't update
**Solution**: Ensure OnLockProgress event is bound and updating material parameter

**Issue**: Lock completes instantly
**Solution**: Check LockTimeConstant and ScanResolution values are reasonable

**Issue**: Can't lock target
**Solution**: Verify target is in range (MaxLockRange) and validate logs for error messages

### Debug Commands

Add these console commands for testing:

**ForceInstantLock**: Complete lock immediately
```
Get Targeting Component
  ↓
For Each Lock Entry:
  ↓
  Set Progress = 1.0
  ↓
  Set State = Locked
```

**DrawLockRange**: Visualize lock range sphere
```
Draw Debug Sphere
  - Center: Ship Location
  - Radius: MaxLockRange
  - Color: Green
```

## Example Complete UI Implementation

### Targeting HUD Widget Blueprint

**Variables**:
```
- TargetingComponent (Targeting Component Reference)
- LockFrameWidgetClass (Widget Class)
- ActiveLockFrames (Map: Actor → Widget)
```

**Event Construct**:
```
Get Owning Player Pawn
  ↓
Get Component (Targeting Component)
  ↓
Store Reference
  ↓
Bind Events:
  - OnLockStarted → CreateLockFrame
  - OnLockCompleted → UpdateLockFrameState
  - OnLockLost → RemoveLockFrame
  - OnLockProgress → UpdateLockFrameProgress
```

**Function: CreateLockFrame** (Target):
```
Create Widget (LockFrameWidgetClass)
  ↓
Set Target Actor
  ↓
Add to Viewport
  ↓
Store in ActiveLockFrames Map (Target → Widget)
```

**Function: RemoveLockFrame** (Target):
```
Find in ActiveLockFrames Map (Target)
  ↓
Remove from Parent
  ↓
Remove from Map
```

**Event Tick**:
```
For Each ActiveLockFrame:
  ↓
  Update Screen Position (Project World to Screen)
  ↓
  Update Distance Text
  ↓
  Check if On Screen (Cull off-screen frames)
```

---

**Status**: ✅ Implemented  
**Last Updated**: 2026-02-06  
**Dependencies**: UTargetingComponent, Blueprint UI Framework
