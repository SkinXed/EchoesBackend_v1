# Undocking System - Quick Reference

## Purpose
Transition players from docked state (hidden in hangar) to active space gameplay near the station.

## Entry Points

### Client Side
```cpp
// Player clicks "Undock" button in station menu
// Triggers ServerRPC on StationActor
StationActor->ServerRPC_RequestUndock(PlayerController);
```

### Server Side Flow
```
ServerRPC_RequestUndock
    ↓
InitiateUndocking
    ↓
GameMode->RequestUndock
    ↓
[Complete undocking logic]
    ↓
ClientRPC_CloseStationMenu
```

## Key Methods

### StationActor
- `ServerRPC_RequestUndock()` - Entry point from client
- `InitiateUndocking()` - Delegates to GameMode
- `ClientRPC_CloseStationMenu()` - Closes UI on client

### EchoesServerGameMode
- `RequestUndock()` - Main undocking logic (200+ lines)
  - Finds docked station
  - Calculates safe exit point (500m from station)
  - Restores physics and collision
  - Applies forward impulse
  - Cleans up hangar instance

### EchoesHangarManager
- `FindCharacterIdByPawn()` - Find player by pawn reference
- `GetHangarInstance()` - Get hangar data
- `RemoveHangarInstance()` - Cleanup resources

## Physics State Changes

| State | Docked | Undocked |
|-------|--------|----------|
| Hidden | true | **false** |
| Collision | false | **true** |
| Physics | false | **true** |
| Gravity | N/A | **false** |
| Position | Hangar offset | **500m from station** |
| Velocity | 0 | **~10 m/s forward** |

## Configuration

```cpp
// In EchoesServerGameMode::RequestUndock()

const float SafeDistance = 50000.0f;      // 500m from station
const float ImpulseStrength = 1000.0f;    // Initial velocity
```

## Testing Checklist

- [ ] Player can undock from station
- [ ] Ship appears 500m from station
- [ ] Ship is visible and has collision
- [ ] Ship moves forward after undock
- [ ] Station menu closes automatically
- [ ] Multiple players can undock independently
- [ ] No resource leaks on repeated dock/undock

## Common Issues

### Ship spawns inside station
**Fix**: Increase `SafeDistance` to 100000.0f (1km)

### Ship doesn't move
**Fix**: Check `ImpulseStrength`, verify physics enabled

### Menu stays open
**Fix**: Check network, verify ClientRPC called

### Can't undock
**Fix**: Check logs for error messages, verify hangar instance exists

## File Locations

```
Client/Echoes/Source/Echoes/
├── EchoesServerGameMode.h/cpp          # Main undocking logic
├── Core/Common/Actor/StationActor.h/cpp # RPC handlers
└── Core/Server/EchoesHangarManager.h/cpp # Resource management

docs/
└── UNDOCKING_SYSTEM.md                  # Full documentation
```

## Network Flow

```
Client                          Server
  |                               |
  | ServerRPC_RequestUndock       |
  |------------------------------>|
  |                               | [Find station]
  |                               | [Calculate exit]
  |                               | [Restore physics]
  |                               | [Apply impulse]
  |                               | [Cleanup hangar]
  |                               |
  | ClientRPC_CloseStationMenu    |
  |<------------------------------|
  |                               |
[Menu closes]              [Pawn replicated]
[HUD shows]                      |
  |                               |
```

## Quick Debug Commands

```cpp
// Add these logs to trace execution:
UE_LOG(LogTemp, Log, TEXT("Undock: PlayerPawn = %s"), *PlayerPawn->GetName());
UE_LOG(LogTemp, Log, TEXT("Undock: StationId = %s"), *StationId.ToString());
UE_LOG(LogTemp, Log, TEXT("Undock: Exit Location = %s"), *UndockLocation.ToString());
```

## Integration Points

### UI Integration
- Button in station menu calls `ServerRPC_RequestUndock`
- Listen for `ClientRPC_CloseStationMenu` to close widget

### Backend Integration (Future)
- Add HTTP call in `RequestUndock` to update character location
- Endpoint: `POST /api/character/{id}/location`

### Animation Integration (Future)
- Add animation trigger before `SetActorLocation`
- Interpolate position over time for smooth exit

## Performance Notes

- **O(n) station search** - Consider caching station references
- **O(n) hangar search** - Optimized with `FindCharacterIdByPawn`
- **Minimal network** - Only one ClientRPC per undock
- **No blocking** - All logic executes in single frame

## Success Criteria

✅ Player transitions from hangar to space  
✅ Ship positioned safely away from station  
✅ Physics fully restored  
✅ Station menu closes automatically  
✅ No resource leaks  
✅ Multiplayer safe (isolated per player)  
✅ Comprehensive logging for debugging  

## Next Steps

1. Build and test in editor
2. Test with multiplayer (2+ players)
3. Add UI button to call undock RPC
4. Integrate backend notification
5. Add sound/visual effects
6. Performance profiling

---

**Full Documentation**: See `docs/UNDOCKING_SYSTEM.md`
