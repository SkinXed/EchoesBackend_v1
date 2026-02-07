# World Object Persistence System

## Overview

The World Object Persistence System manages persistent objects dropped in space, such as containers and debris. These objects survive server restarts and are automatically cleaned up after expiration.

## Architecture

### Backend (ASP.NET Core)

**Database Schema:**
- `world_objects` table stores all persistent world objects
- Fields: Id, TemplateId, SystemId, Position (X/Y/Z), Rotation (quaternion), InventoryJson, ExpirationTime, CreatedAt, LastUpdated
- Foreign key to `solar_systems` for system-based queries
- Indexes on SystemId and ExpirationTime for performance

**API Endpoints:**
1. `POST /api/persistence/world-objects` - Register new world object
2. `GET /api/persistence/world-objects/system/{systemId}` - Get all objects in system
3. `GET /api/persistence/world-objects/{id}` - Get specific object
4. `PUT /api/persistence/world-objects/{id}/inventory` - Update inventory
5. `DELETE /api/persistence/world-objects/{id}` - Delete object

All endpoints require `X-Server-Secret` header for authentication.

**Background Cleanup Service:**
- `WorldObjectCleanupService` runs every 5 minutes
- Automatically deletes objects where `ExpirationTime < now`
- Logs cleanup operations for monitoring

### UE5 Server (C++)

**AEWorldContainer Actor:**
- Server-only actor for containers/debris in space
- Auto-registers to backend on spawn (BeginPlay)
- Real-time inventory sync via `ServerOnly_UpdateInventory()`
- Can be spawned from database or created new
- Supports expiration time

**UWorldObjectManager Component:**
- Attached to GameMode or World State
- Queries backend on startup for existing world objects
- Spawns containers from database
- Tracks all spawned objects
- Configurable container class

## Usage

### Backend Setup

1. **Apply Migration:**
```bash
cd /path/to/EchoesBackend_v1
dotnet ef database update
```

Or manually:
```bash
psql -U postgres -d echoes_universe -f Migrations/AddWorldObjectsPersistence.sql
```

2. **Configure Server Secret:**
In `appsettings.json`:
```json
{
  "ServerSecret": "your-secret-key-here"
}
```

3. **Background Service:**
The cleanup service is automatically registered in `Program.cs` and runs on startup.

### UE5 Setup

#### 1. Add WorldObjectManager to GameMode

```cpp
// In your GameMode's BeginPlay or constructor
UWorldObjectManager* WorldObjectMgr = NewObject<UWorldObjectManager>(this);
WorldObjectMgr->RegisterComponent();
WorldObjectMgr->SystemId = CurrentSystemId;
WorldObjectMgr->ApiBaseUrl = TEXT("http://localhost:5116/api");
WorldObjectMgr->ServerSecret = TEXT("your-secret-key-here");
WorldObjectMgr->ContainerClass = AEWorldContainer::StaticClass();
```

#### 2. Spawn Containers

```cpp
// When player drops items in space
AEWorldContainer* Container = GetWorld()->SpawnActor<AEWorldContainer>(
    AEWorldContainer::StaticClass(),
    DropLocation,
    FRotator::ZeroRotator
);

if (Container)
{
    Container->TemplateId = 1; // Your container type ID
    Container->SystemId = CurrentSystemId;
    Container->ExpirationHours = 24.0f; // Expires in 24 hours
    Container->ServerSecret = ServerSecret;
    Container->ApiBaseUrl = ApiBaseUrl;
    
    // Container will auto-register to backend in BeginPlay
}
```

#### 3. Update Inventory

```cpp
// When items are added/removed from container
FString NewInventoryJson = TEXT("{\"items\": [{\"typeId\": 34, \"quantity\": 5}]}");
Container->ServerOnly_UpdateInventory(NewInventoryJson);
```

## Configuration

### Backend Configuration

| Setting | Location | Description | Default |
|---------|----------|-------------|---------|
| ServerSecret | appsettings.json | Authentication secret | `UE5-Server-Secret-Change-Me-In-Production` |
| CleanupInterval | WorldObjectCleanupService.cs | Cleanup frequency | 5 minutes |

### UE5 Configuration

| Property | Component | Description | Default |
|----------|-----------|-------------|---------|
| ApiBaseUrl | AEWorldContainer, UWorldObjectManager | Backend URL | `http://localhost:5116/api` |
| ServerSecret | AEWorldContainer, UWorldObjectManager | Must match backend | `UE5-Server-Secret-Change-Me-In-Production` |
| TemplateId | AEWorldContainer | Object type ID | 1 |
| ExpirationHours | AEWorldContainer | Hours until cleanup (0 = never) | 24.0 |
| SystemId | UWorldObjectManager | Solar system to load | (required) |
| ContainerClass | UWorldObjectManager | Container actor class | AEWorldContainer |
| bAutoLoadOnBeginPlay | UWorldObjectManager | Auto-load on start | true |

## Data Flow

### Container Creation Flow

1. Player drops items in space
2. Server spawns `AEWorldContainer` at location
3. Container's `BeginPlay()` calls `ServerOnly_RegisterToBackend()`
4. HTTP POST to `/api/persistence/world-objects`
5. Backend creates record in `world_objects` table
6. Backend returns object ID
7. Container stores ID for future updates

### Inventory Update Flow

1. Items added/removed from container
2. Game logic calls `Container->ServerOnly_UpdateInventory(newJson)`
3. HTTP PUT to `/api/persistence/world-objects/{id}/inventory`
4. Backend updates `InventoryJson` and `LastUpdated` fields
5. Changes persisted immediately

### Server Restart Flow

1. Server starts, GameMode creates `UWorldObjectManager`
2. Manager's `BeginPlay()` calls `ServerOnly_LoadWorldObjects()`
3. HTTP GET to `/api/persistence/world-objects/system/{systemId}`
4. Backend returns all non-expired objects in system
5. Manager spawns `AEWorldContainer` for each object
6. Containers initialized with saved data via `InitializeFromDatabase()`
7. Containers marked as `bLoadedFromDatabase = true` (no re-registration)

### Cleanup Flow

1. `WorldObjectCleanupService` wakes every 5 minutes
2. Queries for objects where `ExpirationTime <= now`
3. Deletes expired objects from database
4. Logs cleanup count for monitoring

## Security

### Authentication

- All API endpoints require `X-Server-Secret` header
- Only game servers should know this secret
- Clients cannot directly manipulate world objects
- Prevents cheating and unauthorized access

### Validation

- System existence verified before object creation
- Object existence verified before updates
- Only server-spawned actors can call these APIs
- JSON inventory validation can be added as needed

## Performance

### Database Impact

- One INSERT per container spawn
- One UPDATE per inventory change
- One SELECT per system on server startup
- DELETE batch operations every 5 minutes
- Indexes on SystemId and ExpirationTime for fast queries

### Network Impact

- Registration: ~300 bytes JSON (one-time per container)
- Inventory update: Variable size (depends on inventory)
- System query: Scales with number of objects in system
- All operations are async (non-blocking)

### Optimization Tips

1. **Batch Inventory Updates:**
   - Queue multiple inventory changes
   - Send single update with final state
   - Reduces API calls

2. **Expiration Time:**
   - Set realistic expiration (24-48 hours)
   - Prevents database bloat
   - Automatic cleanup

3. **System Partitioning:**
   - Objects are per-system
   - Each system loads only its objects
   - Scales well with multiple systems

4. **Cleanup Frequency:**
   - 5 minutes is reasonable default
   - Can increase for lower database load
   - Can decrease for more aggressive cleanup

## Monitoring

### Backend Logs

```
WorldObjectCleanupService started
Cleaning up 5 expired world objects
Successfully cleaned up 5 expired world objects
```

### UE5 Logs

```
EWorldContainer: BeginPlay on server
EWorldContainer: Sending registration request
EWorldContainer: Registered with ObjectId=12345678-1234-1234-1234-123456789abc
EWorldContainer: Inventory update successful

WorldObjectManager: Loading world objects for system 12345678...
WorldObjectManager: Received 10 world objects
WorldObjectManager: Spawned container at (1000.0, 2000.0, 3000.0)
WorldObjectManager: Finished spawning 10 containers
```

## Troubleshooting

### Common Issues

**"Missing X-Server-Secret header"**
- Ensure `ServerSecret` property is set on container/manager
- Check that secret matches backend configuration

**"Solar system not found"**
- Verify `SystemId` is valid and exists in database
- Check that system was generated/created

**"Container not spawning from database"**
- Check `WorldObjectManager` is attached to GameMode
- Verify `SystemId` is set correctly
- Check backend logs for API errors

**"Inventory not updating"**
- Ensure container has valid `ObjectId` (registered)
- Check network connectivity to backend
- Verify JSON format is valid

**Cleanup not running**
- Check backend logs for service start message
- Verify no exceptions in cleanup service
- Ensure database connection is working

### Debug Logging

Enable verbose logging in UE5:
```cpp
// In container or manager code
UE_LOG(LogTemp, Verbose, TEXT("Debug message here"));
```

Check backend logs:
```bash
tail -f /var/log/echoes-api.log
```

## Testing

### Manual Testing

#### Test Container Registration

1. Spawn container in UE5 server
2. Check UE5 logs for "Registered with ObjectId"
3. Query database:
```sql
SELECT * FROM world_objects WHERE "SystemId" = 'your-system-guid';
```

#### Test Inventory Update

1. Update container inventory in game
2. Check UE5 logs for "Inventory update successful"
3. Query database:
```sql
SELECT "InventoryJson", "LastUpdated" FROM world_objects WHERE "Id" = 'object-guid';
```

#### Test Server Restart

1. Spawn several containers
2. Note their positions and IDs
3. Restart UE5 server
4. Check WorldObjectManager logs
5. Verify containers spawned at same positions

#### Test Cleanup

1. Spawn container with `ExpirationHours = 0.01` (36 seconds)
2. Wait 6+ minutes
3. Check cleanup service logs
4. Verify container removed from database

### API Testing with curl

```bash
# Register container
curl -X POST http://localhost:5116/api/persistence/world-objects \
  -H "Content-Type: application/json" \
  -H "X-Server-Secret: your-secret" \
  -d '{
    "templateId": 1,
    "systemId": "12345678-1234-1234-1234-123456789abc",
    "posX": 1000.0,
    "posY": 2000.0,
    "posZ": 3000.0,
    "rotW": 1.0,
    "rotX": 0.0,
    "rotY": 0.0,
    "rotZ": 0.0,
    "inventoryJson": "{}",
    "expirationTime": "2026-02-08T00:00:00Z"
  }'

# Get system objects
curl http://localhost:5116/api/persistence/world-objects/system/12345678-1234-1234-1234-123456789abc \
  -H "X-Server-Secret: your-secret"

# Update inventory
curl -X PUT http://localhost:5116/api/persistence/world-objects/{object-id}/inventory \
  -H "Content-Type: application/json" \
  -H "X-Server-Secret: your-secret" \
  -d '{"inventoryJson": "{\"items\": [{\"typeId\": 34, \"quantity\": 5}]}"}'
```

## Integration with Character Persistence

The world object system complements the character state persistence:

- **Character State:** Position, rotation, stats for players
- **World Objects:** Containers, debris, dropped items in space
- **Together:** Complete game state preservation

Both systems use:
- Same authentication mechanism (X-Server-Secret)
- Similar API patterns
- Background cleanup services
- PostgreSQL with EF Core

## Future Enhancements

### Planned Features

- [ ] Object ownership tracking
- [ ] Access control lists (who can access container)
- [ ] Container locking/unlocking
- [ ] Audit log for container access
- [ ] Container name/description
- [ ] Visual indicators for expiring containers
- [ ] Container search/filter API
- [ ] Debris with loot tables
- [ ] Wreck salvaging
- [ ] Container groups/links

### Performance Enhancements

- [ ] Redis caching for hot containers
- [ ] Batch API for multiple operations
- [ ] WebSocket for real-time updates
- [ ] Partial inventory updates (delta)
- [ ] Compression for large inventories

## References

- Backend Entity: `Models/Entities/Universe/WorldObject.cs`
- Backend Controller: `Controllers/WorldObjectsController.cs`
- Background Service: `Services/WorldObjectCleanupService.cs`
- UE5 Container: `Client/Echoes/Source/Echoes/Core/Common/Actor/EWorldContainer.h`
- UE5 Manager: `Client/Echoes/Source/Echoes/Core/Server/Managers/WorldObjectManager.h`
- Migration: `Migrations/AddWorldObjectsPersistence.sql`

## License

Copyright Epic Games, Inc. All Rights Reserved.
