# Undocking System Documentation

## Overview

The Undocking System handles the transition of players from a docked state (hidden in their personal hangar) back to open space near the station. This system restores physics, collision, and movement while ensuring safe positioning away from the station.

## Architecture

### Data Flow

```
Client (Undock Button Click)
    ↓ [ServerRPC]
StationActor::ServerRPC_RequestUndock
    ↓
StationActor::InitiateUndocking
    ↓
GameMode::RequestUndock
    ↓ [Find Station & Calculate Exit]
    ↓ [Restore Physics]
    ↓ [Apply Impulse]
    ↓ [Cleanup Hangar]
    ↓ [ClientRPC]
StationActor::ClientRPC_CloseStationMenu
    ↓
Client UI Closes
```

## Key Components

### 1. StationActor (Client Trigger)

**ServerRPC_RequestUndock**
- Entry point for undocking request
- Validates player controller
- Delegates to `InitiateUndocking`

**InitiateUndocking**
- Gets GameMode reference
- Calls `GameMode->RequestUndock(PlayerController)`
- Logs undocking sequence start

**ClientRPC_CloseStationMenu**
- Closes station menu UI on client
- Re-enables game input
- Hides mouse cursor

### 2. EchoesServerGameMode (Core Logic)

**RequestUndock** - Main undocking logic:

#### Step 1: Find Player's Docked Station
```cpp
// Find character ID by pawn
FGuid PlayerCharacterId;
HangarManager->FindCharacterIdByPawn(PlayerPawn, PlayerCharacterId);

// Get hangar instance with station info
FHangarInstance* HangarInstance = HangarManager->GetHangarInstance(PlayerCharacterId);
FGuid StationId = HangarInstance->StationId;
```

#### Step 2: Locate Station Actor
```cpp
// Use TActorIterator to find station in world
AStationActor* FoundStation = nullptr;
for (TActorIterator<AStationActor> It(GetWorld()); It; ++It)
{
    if ((*It)->GetStationId() == StationId)
    {
        FoundStation = *It;
        break;
    }
}
```

#### Step 3: Calculate Safe Exit Point
```cpp
FVector StationLocation = FoundStation->GetActorLocation();
FVector StationForward = FoundStation->GetActorForwardVector();
const float SafeDistance = 50000.0f; // 500m in UE units

FVector UndockLocation = StationLocation + (StationForward * SafeDistance);
FRotator UndockRotation = FoundStation->GetActorRotation();
```

**Why 500m?**
- Ensures ship spawns outside station collision radius
- Prevents immediate re-docking
- Provides visual separation for player feedback

#### Step 4: Physical Activation
```cpp
// 1. Position
PlayerPawn->SetActorLocation(UndockLocation);
PlayerPawn->SetActorRotation(UndockRotation);

// 2. Visibility
PlayerPawn->SetActorHiddenInGame(false);

// 3. Collision
PlayerPawn->SetActorEnableCollision(true);

// 4. Physics
if (UPrimitiveComponent* Root = Cast<UPrimitiveComponent>(PlayerPawn->GetRootComponent()))
{
    Root->SetSimulatePhysics(true);
    Root->SetEnableGravity(false); // Space = no gravity
}

// 5. Movement (if Character)
if (ACharacter* Character = Cast<ACharacter>(PlayerPawn))
{
    Character->GetCharacterMovement()->SetMovementMode(MOVE_Flying);
}
```

#### Step 5: Initial Impulse
```cpp
// Give ship forward momentum away from station
const float ImpulseStrength = 1000.0f;
FVector ForwardImpulse = StationForward * ImpulseStrength;
RootPrimitive->AddImpulse(ForwardImpulse, NAME_None, true);
```

**Impulse Calculation:**
- Direction: Station's forward vector
- Strength: 1000.0f (adjustable based on ship mass)
- Effect: ~10 m/s initial velocity
- Purpose: Smooth exit animation, prevents re-docking

#### Step 6: Cleanup
```cpp
// Remove hangar instance and free resources
HangarManager->RemoveHangarInstance(PlayerCharacterId);
```

#### Step 7: UI Update
```cpp
// Close station menu on client
FoundStation->ClientRPC_CloseStationMenu();
```

### 3. EchoesHangarManager (Resource Management)

**FindCharacterIdByPawn**
- Searches hangar instances by pawn reference
- Returns character GUID for data lookup

**GetHangarInstance**
- Retrieves hangar instance data
- Contains StationId for station lookup

**RemoveHangarInstance**
- Clears ship preview
- Removes instance from tracking map
- Frees resources

## Network Flow

### Server Authority
All undocking logic runs on the server (HasAuthority() checks):
1. ServerRPC validates request
2. Server calculates exit point
3. Server modifies pawn state
4. Server cleans up resources
5. Server notifies client via ClientRPC

### Client Replication
Automatic replication handles:
- Pawn location/rotation
- Hidden state
- Collision state
- Physics state

Client receives:
- Updated transform
- Physics replication
- UI close command (ClientRPC)

## State Transitions

### Docked State → Undocking
| Property | Before (Docked) | After (Undocked) |
|----------|----------------|------------------|
| Location | Hangar Instance (offset from station) | 500m from station |
| Hidden | true | false |
| Collision | false | true |
| Physics | false | true |
| Gravity | N/A | false |
| Movement | Disabled | Flying |
| UI | Station Menu | Game HUD |
| Hangar Instance | Exists | Removed |

## Safety Features

### 1. Collision Prevention
- **Safe Distance**: 500m from station center
- **Forward Vector**: Uses station's orientation
- **Validation**: Checks station exists before spawn

### 2. State Validation
```cpp
// Multiple validation checks
if (!PC) { return; }
if (!HasAuthority()) { return; }
if (!PlayerPawn) { return; }
if (!HangarManager) { return; }
if (!FoundStation) { return; }
```

### 3. Resource Cleanup
- Clears ship preview
- Removes hangar instance
- Logs all actions for debugging

### 4. Physics Restoration
- Enables physics simulation
- Disables gravity (space environment)
- Restores collision
- Sets flying movement mode

## Edge Cases

### No Hangar Instance
**Scenario**: Player has no hangar instance  
**Handling**: Log error, abort undocking  
**Reason**: Player might not be properly docked

### Station Not Found
**Scenario**: Station ID doesn't match any world actor  
**Handling**: Log error, abort undocking  
**Reason**: World generation incomplete or station destroyed

### No Player Pawn
**Scenario**: Player controller has no pawn  
**Handling**: Log error, abort undocking  
**Reason**: Pawn destroyed or not spawned

### Multiple Players
**Scenario**: Multiple players undocking simultaneously  
**Handling**: Each processed independently  
**Reason**: Hangar instances are isolated per player

## Performance Considerations

### Complexity
- **Station Lookup**: O(n) where n = number of stations in world
- **Hangar Lookup**: O(n) where n = number of docked players
- **Physics Activation**: O(1) per pawn

### Optimization Opportunities
1. **Cache Station References**: Store station ID → actor mapping
2. **Player State**: Store CharacterId in player state for direct lookup
3. **Spatial Indexing**: Use spatial hash for faster station search

### Network Bandwidth
- **Minimal**: Only ClientRPC for UI (small packet)
- **Replication**: Standard pawn replication (existing traffic)
- **No Extra Data**: Uses existing network infrastructure

## Configuration

### Adjustable Parameters

**EchoesServerGameMode.cpp**
```cpp
// Safe distance from station (in cm)
const float SafeDistance = 50000.0f; // 500m

// Initial impulse strength
const float ImpulseStrength = 1000.0f; // Adjust for ship mass
```

### Tuning Guidelines

| Ship Type | Mass | Recommended Impulse |
|-----------|------|---------------------|
| Frigate | 1000 kg | 1000.0f |
| Cruiser | 10000 kg | 5000.0f |
| Battleship | 100000 kg | 10000.0f |

**Formula**: `Impulse = DesiredVelocity * Mass`

## Testing Scenarios

### Test Case 1: Single Player Undock
1. Player docks at station
2. Player opens station menu
3. Player clicks "Undock" button
4. Ship appears 500m from station
5. Ship moves forward smoothly
6. Menu closes

**Expected**: Smooth transition to space

### Test Case 2: Multiple Players Same Station
1. Player A docks at Station X
2. Player B docks at Station X
3. Both players in separate hangar instances
4. Player A undocks
5. Player B still docked

**Expected**: Players don't interfere with each other

### Test Case 3: Rapid Dock/Undock
1. Player docks
2. Player immediately undocks
3. Repeat 5 times

**Expected**: No resource leaks, smooth transitions

### Test Case 4: Station Destruction (Future)
1. Player docked at station
2. Station is destroyed (event)
3. Player should be ejected safely

**Expected**: Graceful handling, no crash

## Troubleshooting

### Issue: Ship spawns inside station
**Cause**: SafeDistance too small  
**Fix**: Increase SafeDistance to 100000.0f (1km)

### Issue: Ship doesn't move after undock
**Cause**: Physics not enabled or impulse too weak  
**Fix**: Verify SetSimulatePhysics(true) called, increase ImpulseStrength

### Issue: Menu doesn't close
**Cause**: ClientRPC not received  
**Fix**: Check network connectivity, verify RPC declaration

### Issue: Player can't undock
**Cause**: No hangar instance found  
**Fix**: Verify docking created hangar instance, check logs

### Issue: Collision still disabled
**Cause**: SetActorEnableCollision not called  
**Fix**: Check pawn type, verify method reaches physics code

## Future Enhancements

### Potential Improvements
1. **Animated Exit**: Smooth camera transition during undock
2. **Docking Bay Assignment**: Multiple exit points based on bay
3. **Queue System**: Handle multiple simultaneous undocks
4. **Backend Notification**: Update character location in database
5. **Sound Effects**: Undocking sound and station comms
6. **Visual Effects**: Particle effects for airlock/bay doors

### Backend Integration
```cpp
// TODO: Notify backend about undocking
// POST /api/character/{characterId}/location
// Body: {
//   "locationType": "InSpace",
//   "stationId": null,
//   "position": { x, y, z },
//   "timestamp": "2026-02-03T05:00:00Z"
// }
```

## References

- `EchoesServerGameMode.h/cpp` - Main undocking logic
- `StationActor.h/cpp` - RPC handlers and triggers
- `EchoesHangarManager.h/cpp` - Resource management
- `docs/HANGAR_SPATIAL_ISOLATION.md` - Docking system documentation

## Conclusion

The Undocking System provides a robust, network-safe way to transition players from docked state to active space gameplay. By separating concerns (UI → Station → GameMode → Resources), the system maintains clean architecture and handles edge cases gracefully.

Key benefits:
- ✅ **Safe Positioning**: 500m safe distance prevents collision
- ✅ **Physics Restoration**: Complete state restoration
- ✅ **Resource Cleanup**: Proper hangar instance management
- ✅ **Network Safe**: Server authoritative with client replication
- ✅ **Scalable**: Handles multiple simultaneous undocks
- ✅ **Maintainable**: Clear separation of concerns
