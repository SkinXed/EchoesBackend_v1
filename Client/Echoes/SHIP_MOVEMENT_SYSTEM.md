# EVE-like Ship Movement System

This implementation provides a physics-based ship movement system similar to EVE Online, with backend stat management and UE5 client physics.

## Architecture Overview

### Backend (ASP.NET Core)

**Postgres is the source of truth** - All ship statistics are managed on the backend.

#### Models
- **Ship** (Inventory/Ship.cs) - Ship type definitions with movement stats:
  - `BaseMass` - Base mass in kg
  - `Thrust` - Thrust force in Newtons
  - `RotationSpeed` - Degrees per second
  - `WarpSpeed` - AU/s multiplier
  - `InertiaMultiplier` - Affects acceleration
  - `MaxVelocity` - m/s
  - `BaseAgility` - Lower = more agile

- **ShipInstance** - Player-owned ship instances
- **ShipInstanceModule** - Modules fitted to ships (add mass)

#### Service
- **ShipFittingService** - Calculates final ship stats:
  - Formula: `TotalMass = BaseMass + Σ ModuleMass`
  - Returns `ShipStatsDto` for UE5 consumption

#### Controller
- **ShipController** - API endpoints:
  - `GET /api/ship/{id}/stats` - Returns calculated ship stats
  - `POST /api/ship/{id}/modules` - Add module to ship
  - `DELETE /api/ship/modules/{moduleId}` - Remove module

#### Security
- All ship endpoints require `X-Server-Secret` header
- Configure in `appsettings.json`: `"ServerSecret": "your-secret-here"`

### UE5 Client (C++)

**Mirror architecture** - Each backend controller has a corresponding subsystem.

#### Folder Structure
```
Source/Echoes/Core/
├── Common/          # Shared code (physics, movement)
├── Client/          # Client-only (input, camera, UI)
└── Server/          # Server-only (auth, validation)
```

#### Core Types (Common/EchoesShipTypes.h)

**EWarpState Enum:**
- `Idle` - Normal flight
- `Aligning` - Turning toward target, building speed
- `Warping` - High-speed transit
- `Exiting` - Decelerating from warp

**FEchoesShipStats Struct:**
Mirrors the C# `ShipStatsDto` exactly - keep in sync!

#### Movement Component (Common/EchoesShipMovementComponent)

Physics-based movement using `AddForce` and `AddTorqueInRadians`.

**Key Methods:**
- `Common_ApplyThrust()` - WASD movement on local axes (X=forward, Y=strafe, Z=vertical)
- `Common_AlignToVector()` - Smooth rotation using `FMath::RInterpTo`
- `Common_UpdateWarp()` - State machine for warp
- `Common_ApplyDamping()` - Inertia feel when no input

**Warp Logic:**
1. **Aligning Phase:**
   - Ship rotates toward target
   - Accelerates to 75% max speed
   - Checks alignment threshold (5 degrees)

2. **Warping Phase:**
   - Control disabled
   - Velocity = MaxVelocity × WarpSpeedMultiplier × WarpSpeed
   - Monitors distance to target

3. **Exiting Phase:**
   - Strong deceleration (0.9x per frame)
   - Returns control when speed < 110% max velocity

#### Ship Pawn (Client/EchoesShipPawn)

**Components:**
- `ShipMesh` - StaticMeshComponent with physics enabled
- `ShipMovement` - Custom movement component
- `SpringArm` - Provides camera lag for mass feel
- `Camera` - Player view

**Enhanced Input Actions:**
- **MoveAction** - WASD for thrust (Vector input)
- **LookAction** - Mouse for camera rotation (Vector2D input)
- **MouseFollowAction** - Toggle ship follows camera direction
- **WarpAction** - Initiate warp sequence

**Camera Features:**
- **Camera Lag** - Provides sense of mass during acceleration
  - Configure via `CameraLagSpeed` (default: 3.0)
  - Enabled by default with `bEnableCameraLag`
- **Configurable distance and pitch**
- **Smooth interpolation**

## Usage

### Backend Setup

1. Add server secret to `appsettings.json`:
```json
"ServerSecret": "UE5-Server-Secret-Change-Me-In-Production"
```

2. Service is auto-registered in `Program.cs`

3. Create ship instances and modules in database

4. Call API from UE5 server:
```http
GET /api/ship/{guid}/stats
Headers:
  X-Server-Secret: your-secret-here
```

### UE5 Setup

1. **Create Ship Blueprint:**
   - Base class: `AEchoesShipPawn`
   - Add ship mesh to `ShipMesh` component
   - Configure mass and collision

2. **Set Up Input Mapping:**
   - Create Input Mapping Context
   - Create Input Actions for Move, Look, MouseFollow, Warp
   - Assign to pawn's input properties

3. **Initialize Ship Stats:**
```cpp
// Get stats from backend API
FEchoesShipStats Stats;
Stats.TotalMass = 1500000.0f; // From backend
Stats.Thrust = 600000.0f;
Stats.RotationSpeed = 35.0f;
// ... set other fields

// Initialize pawn
ShipPawn->InitializeShipStats(Stats);
```

4. **Configure Camera:**
   - Adjust `CameraDistance` for view
   - Set `CameraLagSpeed` for mass feel (lower = more lag)
   - `CameraPitch` for angle

## Naming Conventions

All code follows these prefixes:

- **Common_** - Shared logic (movement, physics)
- **Client_** - Client-only (input, visuals, camera)
- **Server_** - Server-only (validation, auth)
- **ServerRPC_** - Server RPC functions (not yet implemented)
- **ClientRPC_** - Client RPC functions (not yet implemented)
- **Auth_** - Authentication-related

## Physics Configuration

The system uses Unreal's physics engine for realistic movement:

1. **Mass** - Set from backend `TotalMass`
2. **Thrust** - Applied via `AddForce()`
3. **Rotation** - Applied via `SetPhysicsAngularVelocityInRadians()`
4. **Damping** - Provides space-like inertia
5. **Max Velocity** - Clamped to stat value

## Future Enhancements

- [ ] Add subsystem for backend API communication
- [ ] Implement proper networking (ServerRPC/ClientRPC)
- [ ] Add module effects beyond mass (thrust bonuses, etc.)
- [ ] Visual warp tunnel effect
- [ ] Warp destination selection UI
- [ ] Shield/armor/structure damage system
- [ ] Capacitor management
- [ ] Module activation system

## Testing

### Backend Testing
```bash
# Test API endpoint
curl -X GET http://localhost:5116/api/ship/{guid}/stats \
  -H "X-Server-Secret: UE5-Server-Secret-Change-Me-In-Production"
```

### UE5 Testing
1. Create test ship blueprint
2. Place in level
3. Add player start
4. Play in editor
5. Use WASD to move
6. Right-click to toggle mouse follow
7. Press warp key to test warp system

## Troubleshooting

**Ship doesn't move:**
- Ensure `ShipMesh->SetSimulatePhysics(true)`
- Check mass is set correctly
- Verify movement input is being received

**Camera doesn't lag:**
- Check `SpringArm->bEnableCameraLag = true`
- Increase `CameraLagSpeed` value
- Ensure SpringArm is attached correctly

**Warp doesn't trigger:**
- Check alignment threshold
- Verify speed threshold (75% of max)
- Watch console logs for warp state messages

**Backend returns 401:**
- Verify `X-Server-Secret` header
- Check appsettings.json configuration
- Ensure secret matches between backend and client
