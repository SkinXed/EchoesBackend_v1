# Character State Restoration Integration Guide

## Overview
This document describes how to integrate character state restoration into the player spawn flow.

## Backend API Integration

The PersistenceController provides a GET endpoint for retrieving saved character state:
```
GET /api/persistence/state/{characterId}
Headers:
  X-Server-Secret: <server-secret>
```

## UE5 Integration Points

### 1. Modify PerformSpawnWithLocationData

The `AEchoesServerGameMode::PerformSpawnWithLocationData` method should be enhanced to:

1. Query the persistence API for saved state before spawning
2. If saved state exists and is recent, use it to restore:
   - Exact position and rotation
   - Shield, armor, hull values
   - Capacitor energy
3. If no saved state exists, use the CharacterLocation data as before

### 2. Add State Restoration Method

Add new method to `AEchoesServerGameMode`:

```cpp
void QueryCharacterState(
    const FGuid& CharacterId,
    APlayerController* PlayerController,
    const FCharacterLocationData& FallbackLocationData);
```

This method:
- Makes HTTP GET request to `/api/persistence/state/{characterId}`
- Includes X-Server-Secret header
- On success: Spawns player with restored state
- On failure: Falls back to CharacterLocation data

### 3. Apply State to Spawned Pawn

After spawning, apply the restored state:

```cpp
void ApplyRestoredState(
    APawn* SpawnedPawn,
    const FVector& Position,
    const FQuat& Rotation,
    float Shield,
    float Armor,
    float Hull,
    float Capacitor);
```

This method:
- Sets actor location and rotation
- Finds UEchoesStatsComponent
- Sets ShieldCurrent, ArmorCurrent, StructureCurrent
- Sets capacitor (if component exists)

### 4. Attach Persistence Component

When spawning a ship pawn, automatically attach UPersistenceComponent:

```cpp
// In SpawnPlayerInSpace or SpawnPlayerAtStation
UPersistenceComponent* PersistenceComp = NewObject<UPersistenceComponent>(SpawnedPawn);
PersistenceComp->RegisterComponent();
PersistenceComp->Common_SetCharacterId(CharacterId);
```

## State Priority Logic

1. **Persistence API** (highest priority)
   - Recent saves (<5 minutes old)
   - Contains exact position, rotation, stats
   
2. **CharacterLocation API** (fallback)
   - May have stale position data
   - Good for docked/undocked state
   
3. **Safety Fallback** (last resort)
   - Default spawn position (0, 0, 1000)
   - Full health/shields

## Configuration

Both backend and UE5 must use the same ServerSecret:

**Backend:** appsettings.json
```json
{
  "ServerSecret": "UE5-Server-Secret-Change-Me-In-Production"
}
```

**UE5:** DefaultGame.ini or component properties
```ini
[/Script/Echoes.PersistenceComponent]
ServerSecret=UE5-Server-Secret-Change-Me-In-Production
ApiBaseUrl=http://localhost:5116/api
```

## Testing Flow

1. Player logs in → State restored from persistence API
2. Player moves around → Auto-saved every 60 seconds
3. Player disconnects → State saved in EndPlay
4. Player logs back in → Spawns at exact last position with exact stats

## Error Handling

- Network timeout: Fall back to CharacterLocation
- Invalid response: Fall back to CharacterLocation
- No saved state: Use CharacterLocation
- All failed: Safety fallback position

## Future Enhancements

- Track LastSystemId and verify player is in correct game server
- Implement server transfer protocol for cross-server moves
- Add client notification when state is restored
- Expose persistence settings to Blueprint for game designers
