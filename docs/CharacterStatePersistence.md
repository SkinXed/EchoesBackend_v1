# Character State Persistence System

## Overview

The Character State Persistence System protects player data against loss during server crashes or unexpected disconnections. It saves player position, rotation, and ship stats to the PostgreSQL database at regular intervals and on logout.

## Architecture

### Backend (ASP.NET Core)

**Model:** `CharacterState`
- Stores position (X, Y, Z), rotation (quaternion), and stats (shield, armor, hull, capacitor)
- One state per character (unique constraint on CharacterId)
- Tracks LastUpdated timestamp

**API Endpoints:**
- `PUT /api/persistence/state/{characterId}` - Save character state
- `GET /api/persistence/state/{characterId}` - Retrieve character state

**Security:**
- All endpoints require `X-Server-Secret` header for authentication
- Only UE5 game servers can call these endpoints
- Prevents unauthorized state manipulation

### UE5 Server (C++)

**Component:** `UPersistenceComponent`
- Attaches to ship pawns (AEchoesShipPawn)
- Server-only component (not replicated)
- Handles automatic state saving and HTTP communication

**Save Triggers:**

1. **Logout Save** (Guaranteed)
   - Triggered in `EndPlay()` when player disconnects
   - Saves regardless of dirty flag
   - Ensures no data loss on graceful disconnect

2. **Heartbeat Save** (Auto-save)
   - Timer-based: Default 60 seconds
   - Configurable via `HeartbeatInterval` property
   - Minimizes data loss on server crash (max 60s rollback)

3. **Dirty Flag Optimization**
   - Only saves if position changed >1 meter OR stats changed
   - Reduces unnecessary API calls
   - Configurable via `bEnableDirtyFlag` property

## Installation

### Backend Setup

1. **Apply Database Migration**

Run the SQL migration:
```bash
cd /home/runner/work/EchoesBackend_v1/EchoesBackend_v1
dotnet ef database update
```

Or manually apply the SQL script:
```bash
psql -U postgres -d echoes_universe -f Migrations/AddCharacterStatePersistence.sql
```

2. **Configure Server Secret**

Edit `appsettings.json`:
```json
{
  "ServerSecret": "YOUR-SECRET-KEY-CHANGE-ME-IN-PRODUCTION"
}
```

**Important:** Never use the default secret in production!

### UE5 Setup

1. **Include Component in Build**

The component is already in the source tree:
- Header: `Client/Echoes/Source/Echoes/Core/Common/Components/PersistenceComponent.h`
- Source: `Client/Echoes/Source/Echoes/Core/Common/Components/PersistenceComponent.cpp`

2. **Attach Component to Ship Pawns**

In your spawn logic (e.g., `AEchoesServerGameMode::SpawnPlayerInSpace`):

```cpp
// After spawning pawn
if (APawn* SpawnedPawn = PlayerController->GetPawn())
{
    // Attach persistence component
    UPersistenceComponent* PersistenceComp = NewObject<UPersistenceComponent>(SpawnedPawn);
    PersistenceComp->RegisterComponent();
    PersistenceComp->Common_SetCharacterId(CharacterId);
    
    // Configure if needed
    PersistenceComp->ApiBaseUrl = TEXT("http://localhost:5116/api");
    PersistenceComp->ServerSecret = TEXT("YOUR-SECRET-KEY-CHANGE-ME-IN-PRODUCTION");
}
```

3. **Configure via DefaultGame.ini** (Optional)

```ini
[/Script/Echoes.PersistenceComponent]
ApiBaseUrl=http://localhost:5116/api
ServerSecret=YOUR-SECRET-KEY-CHANGE-ME-IN-PRODUCTION
HeartbeatInterval=60.0
DirtyPositionThreshold=100.0
bEnableHeartbeat=true
bEnableDirtyFlag=true
```

## Configuration

### Backend Configuration

| Setting | Location | Description | Default |
|---------|----------|-------------|---------|
| ServerSecret | appsettings.json | Authentication secret | `UE5-Server-Secret-Change-Me-In-Production` |
| ConnectionString | appsettings.json | PostgreSQL connection | `Host=localhost;Port=7777;...` |

### UE5 Configuration

| Property | Type | Description | Default |
|----------|------|-------------|---------|
| ApiBaseUrl | String | Backend API URL | `http://localhost:5116/api` |
| ServerSecret | String | Must match backend | `UE5-Server-Secret-Change-Me-In-Production` |
| HeartbeatInterval | Float | Auto-save interval (seconds) | 60.0 |
| DirtyPositionThreshold | Float | Min position change (cm) | 100.0 (1m) |
| bEnableHeartbeat | Bool | Enable auto-save | true |
| bEnableDirtyFlag | Bool | Enable dirty check | true |

## Usage

### Automatic Operation

Once configured, the system works automatically:

1. Player logs in → State restored (if available)
2. Player plays → State auto-saved every 60 seconds (if changed)
3. Player disconnects → State saved immediately
4. Player logs back in → Spawns at exact last position

### Manual Save

You can trigger a save manually from Blueprint or C++:

```cpp
UPersistenceComponent* PersistenceComp = Pawn->FindComponentByClass<UPersistenceComponent>();
if (PersistenceComp)
{
    PersistenceComp->ServerOnly_TriggerSave();
}
```

### Monitoring

The component logs all operations:

```
LogTemp: PersistenceComponent: BeginPlay on server for Character 12345678...
LogTemp: PersistenceComponent: Heartbeat timer triggered
LogTemp: PersistenceComponent: State saved successfully (Total: 1)
LogTemp: PersistenceComponent: EndPlay triggered, performing logout save
```

## State Recovery

### Implementation Status

State restoration is designed but not yet implemented in the game mode spawn logic. See [CharacterStateRestoration.md](docs/CharacterStateRestoration.md) for integration guide.

### Planned Flow

1. Server receives player login
2. Query persistence API: `GET /api/persistence/state/{characterId}`
3. If state found: Spawn at saved position with saved stats
4. If not found: Fall back to CharacterLocation API
5. Attach PersistenceComponent to start saving

## Database Schema

```sql
CREATE TABLE character_states (
    "Id" UUID PRIMARY KEY,
    "CharacterId" UUID NOT NULL UNIQUE,
    "LastSystemId" UUID,
    "PosX" DOUBLE PRECISION NOT NULL,
    "PosY" DOUBLE PRECISION NOT NULL,
    "PosZ" DOUBLE PRECISION NOT NULL,
    "RotW" REAL NOT NULL DEFAULT 1.0,
    "RotX" REAL NOT NULL DEFAULT 0.0,
    "RotY" REAL NOT NULL DEFAULT 0.0,
    "RotZ" REAL NOT NULL DEFAULT 0.0,
    "CurrentShield" REAL NOT NULL DEFAULT 0.0,
    "CurrentArmor" REAL NOT NULL DEFAULT 0.0,
    "CurrentHull" REAL NOT NULL DEFAULT 0.0,
    "CurrentCapacitor" REAL NOT NULL DEFAULT 0.0,
    "LastUpdated" TIMESTAMP WITH TIME ZONE NOT NULL,
    
    FOREIGN KEY ("CharacterId") REFERENCES characters("character_id") ON DELETE CASCADE,
    FOREIGN KEY ("LastSystemId") REFERENCES solar_systems("system_id") ON DELETE SET NULL
);
```

## Security

### Authentication

- All API endpoints require `X-Server-Secret` header
- Backend validates secret against configuration
- Prevents client-side state manipulation
- Blocks unauthorized servers from accessing data

### Validation

- Character existence verified before save
- Invalid GUIDs rejected
- Stat values must be non-negative
- SQL injection protected by Entity Framework

### Best Practices

1. **Never commit secrets to source control**
2. **Use different secrets for dev/staging/production**
3. **Rotate secrets periodically**
4. **Monitor failed authentication attempts**
5. **Use HTTPS in production**

## Performance

### Database Impact

- One INSERT/UPDATE per save (upsert pattern)
- Unique constraint prevents duplicate entries
- Indexed on CharacterId for fast lookups
- Minimal storage: ~100 bytes per character

### Network Impact

- Dirty flag reduces unnecessary saves
- Typical payload: ~200 bytes JSON
- Async HTTP requests (non-blocking)
- Failed requests logged but don't crash server

### Optimization Tips

1. Increase `HeartbeatInterval` for less frequent saves
2. Increase `DirtyPositionThreshold` to reduce position-based saves
3. Enable `bEnableDirtyFlag` to skip unchanged state
4. Monitor `SaveCount` and `FailCount` for tuning

## Troubleshooting

### Common Issues

**"Missing X-Server-Secret header"**
- Solution: Ensure ServerSecret is set in UPersistenceComponent
- Check: Component properties or DefaultGame.ini

**"Invalid server secret"**
- Solution: Ensure ServerSecret matches between backend and UE5
- Check: appsettings.json vs component properties

**"Character not found"**
- Solution: Character must exist in database before state can be saved
- Check: Character created during registration/auth flow

**"HTTP request failed"**
- Solution: Check backend is running and URL is correct
- Check: ApiBaseUrl in component matches backend address

**State not restoring on login**
- Status: State restoration not yet implemented in spawn logic
- Solution: Implement state recovery flow (see CharacterStateRestoration.md)

### Debug Logging

Enable verbose logging to see all operations:

```cpp
// In PersistenceComponent.cpp, change LogTemp to LogVerbosity::Verbose
UE_LOG(LogTemp, Verbose, TEXT("..."));
```

## Testing

### Test Scenarios

1. **Normal Logout**
   - Log in → Move around → Log out → Log back in
   - Expected: Spawn at last position

2. **Server Crash Simulation**
   - Log in → Move around → Wait 60s → Kill server
   - Expected: State saved by heartbeat, max 60s rollback

3. **Dirty Flag**
   - Log in → Stand still for 61s → Check logs
   - Expected: "State not dirty, skipping save"

4. **Stats Change**
   - Log in → Take damage → Wait 1s → Check logs
   - Expected: State saved due to stats change

### Manual Testing

Test the API with curl:

```bash
# Save state
curl -X PUT http://localhost:5116/api/persistence/state/12345678-1234-1234-1234-123456789abc \
  -H "Content-Type: application/json" \
  -H "X-Server-Secret: YOUR-SECRET" \
  -d '{
    "posX": 1000.0,
    "posY": 2000.0,
    "posZ": 3000.0,
    "rotW": 1.0,
    "rotX": 0.0,
    "rotY": 0.0,
    "rotZ": 0.0,
    "currentShield": 500.0,
    "currentArmor": 750.0,
    "currentHull": 900.0,
    "currentCapacitor": 800.0
  }'

# Get state
curl http://localhost:5116/api/persistence/state/12345678-1234-1234-1234-123456789abc \
  -H "X-Server-Secret: YOUR-SECRET"
```

## Future Enhancements

### Planned Features

- [ ] State restoration in spawn flow
- [ ] LastSystemId validation and server transfer
- [ ] Client RPC notification when state is saved
- [ ] Blueprint events for save success/failure
- [ ] Admin tools to view/edit saved states
- [ ] State history/audit log
- [ ] Compression for large state data
- [ ] Redis caching for frequently accessed states

### Integration Opportunities

- Combine with backup/snapshot system
- Integrate with server clustering
- Add to monitoring/alerting system
- Export to analytics pipeline

## References

- Backend Code: `Controllers/PersistenceController.cs`
- Backend Model: `Models/Entities/Character/CharacterState.cs`
- UE5 Component: `Client/Echoes/Source/Echoes/Core/Common/Components/PersistenceComponent.h`
- Integration Guide: `Client/Echoes/docs/CharacterStateRestoration.md`
- Migration: `Migrations/AddCharacterStatePersistence.sql`

## Support

For issues or questions:
1. Check logs on both backend and UE5
2. Verify configuration matches on both sides
3. Test API endpoints with curl
4. Review this documentation
5. Check GitHub issues

## License

Copyright Epic Games, Inc. All Rights Reserved.
