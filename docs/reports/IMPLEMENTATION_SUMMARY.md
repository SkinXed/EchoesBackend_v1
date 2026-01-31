# EVE-like Ship Movement System - Implementation Summary

## Overview

This implementation provides a complete EVE Online-style ship movement system with:
- **Backend (ASP.NET Core 8)**: Ship statistics management, fitting calculations, and API endpoints
- **UE5 (C++)**: Physics-based movement, camera system, warp mechanics, and backend integration

## Architecture Principles

### 1. "Postgres is Truth"
All ship statistics are stored and calculated on the backend. The backend is the authoritative source for:
- Ship base stats (mass, thrust, rotation speed, warp capability)
- Fitted modules and their effects
- Final calculated stats (TotalMass = BaseMass + Σ ModuleMass)

### 2. "Mirror Architecture" (Зеркальность)
Each backend controller has a corresponding UE5 subsystem:
- `ShipController` (C#) ↔ `UEchoesShipStatsSubsystem` (C++)
- This ensures consistent API usage and clear separation of concerns

### 3. Naming Conventions
All code follows strict prefixes for clarity:
- **Common_**: Shared logic (physics, movement calculations)
- **Client_**: Client-only (input, camera, visuals)
- **Server_**: Server-only (validation, authentication)
- **ServerRPC_** / **ClientRPC_**: Network replication (future)
- **Auth_**: Authentication-related

## What Was Implemented

### Backend (ASP.NET Core)

#### 1. Data Models
- **Ship** (`Models/Entities/Inventory/Ship.cs`)
  - Extended existing ship type with movement properties
  - Added: BaseMass, Thrust, RotationSpeed, WarpSpeed, InertiaMultiplier, MaxVelocity
  
- **ShipInstance** (`Models/Entities/Inventory/ShipInstance.cs`)
  - Player-owned ship instances
  - References ship type, owner character, and location
  
- **ShipInstanceModule** (`Models/Entities/Inventory/ShipInstanceModule.cs`)
  - Modules fitted to ships
  - Each module contributes mass and can be online/offline

#### 2. Service Layer
- **ShipFittingService** (`Services/Ship/ShipFittingService.cs`)
  - Calculates total ship mass: `TotalMass = BaseMass + Σ ModuleMass`
  - Only counts online modules
  - Returns `ShipStatsDto` for UE5 consumption

#### 3. API Controller
- **ShipController** (`Controllers/Ship/ShipController.cs`)
  - `GET /api/ship/{id}/stats` - Returns calculated ship stats
  - `POST /api/ship/{id}/modules` - Add module to ship
  - `DELETE /api/ship/modules/{moduleId}` - Remove module
  - **Security**: All endpoints require `X-Server-Secret` header

#### 4. Configuration
- Added `ServerSecret` to `appsettings.json`
- Service registration in `Program.cs`
- Database context updated with new entities

### UE5 Client (C++)

#### 1. Core Types (`Core/Common/EchoesShipTypes.h`)
- **EWarpState Enum**:
  - `Idle` - Normal flight mode
  - `Aligning` - Turning to target and building speed
  - `Warping` - High-speed transit with disabled control
  - `Exiting` - Deceleration phase

- **FEchoesShipStats Struct**:
  - Exact mirror of C# `ShipStatsDto`
  - All float properties match backend
  - Includes GUID, ship name, type info

#### 2. Movement Component (`Core/Common/EchoesShipMovementComponent`)
Implements all physics-based movement:

**Physics Movement:**
- `Common_ApplyThrust()` - WASD input → Force on local axes
- Uses `AddForce()` for thrust application
- Velocity clamped to `MaxVelocity`

**Mouse Follow:**
- `Common_AlignToVector()` - Smooth rotation to target
- Uses `SetPhysicsAngularVelocityInRadians()` for rotation
- Interpolates with `FMath::RInterpTo()`

**Warp System:**
- `Common_UpdateWarp()` - State machine handler
- `HandleAligningState()` - Checks alignment & speed thresholds
- `HandleWarpingState()` - High-speed movement to target
- `HandleExitingState()` - Controlled deceleration

**Configuration:**
- `RotationInterpSpeed` - Alignment smoothness (default: 2.0)
- `WarpAlignmentThreshold` - Degrees required to warp (default: 5.0)
- `WarpSpeedThreshold` - % of max speed to warp (default: 75%)
- `WarpSpeedMultiplier` - Speed boost in warp (default: 10x)

#### 3. Ship Pawn (`Core/Client/EchoesShipPawn`)
Complete player-controlled ship:

**Components:**
- `ShipMesh` - StaticMeshComponent with physics simulation
- `ShipMovement` - Custom movement component
- `SpringArm` - Camera boom with lag for mass feel
- `Camera` - Third-person camera

**Enhanced Input:**
- `MoveAction` - WASD movement (Vector)
- `LookAction` - Mouse camera rotation (Vector2D)
- `MouseFollowAction` - Toggle alignment mode
- `WarpAction` - Initiate warp sequence

**Camera System:**
- **Camera Lag** enabled by default
- Provides visceral sense of ship mass during acceleration
- Configurable lag speed and distance
- Smooth interpolation for all movements

#### 4. Backend Integration (`Core/Common/EchoesShipStatsSubsystem`)
Game Instance Subsystem for API communication:

**Features:**
- `FetchShipStats()` - HTTP GET with authentication
- `AddModule()` - HTTP POST with JSON body
- Automatic JSON parsing to `FEchoesShipStats`
- Error handling with callbacks
- Configurable via Project Settings

**Configuration:**
- `ApiBaseUrl` - Backend endpoint
- `ServerSecret` - Matches backend configuration

## File Structure

```
EchoesBackend_v1/
├── Backend (ASP.NET Core)
│   ├── Controllers/Ship/ShipController.cs
│   ├── Models/
│   │   ├── DTOs/ShipStatsDto.cs
│   │   └── Entities/Inventory/
│   │       ├── Ship.cs (extended)
│   │       ├── ShipInstance.cs
│   │       └── ShipInstanceModule.cs
│   ├── Services/Ship/ShipFittingService.cs
│   └── Data/DatabaseContext.cs (updated)
│
└── Client/Echoes/ (UE5)
    ├── Source/Echoes/Core/
    │   ├── Common/
    │   │   ├── EchoesShipTypes.h
    │   │   ├── EchoesShipMovementComponent.h/cpp
    │   │   └── EchoesShipStatsSubsystem.h/cpp
    │   ├── Client/
    │   │   └── EchoesShipPawn.h/cpp
    │   └── Server/ (empty, for future)
    └── SHIP_MOVEMENT_SYSTEM.md
```

## How It Works

### 1. Backend Flow
```
1. ShipInstance created in database with ShipTypeId
2. Ship type has BaseMass and other stats
3. Modules fitted to ShipInstance (each adds Mass)
4. UE5 requests stats via GET /api/ship/{id}/stats
5. ShipFittingService calculates: TotalMass = BaseMass + Σ ModuleMass
6. Returns ShipStatsDto as JSON
```

### 2. UE5 Flow
```
1. Game starts, player selects ship
2. Subsystem fetches stats from backend
3. Stats applied to ShipPawn via InitializeShipStats()
4. MovementComponent configures physics (mass, thrust, etc.)
5. Player input → Movement/Rotation forces
6. Camera lag provides mass feel
7. Warp system manages high-speed travel
```

### 3. Warp Sequence
```
1. Player initiates warp (E key or custom)
2. State: Idle → Aligning
   - Ship rotates to target
   - Accelerates to 75% max speed
   - Checks: angle < 5° AND speed > 75%
3. State: Aligning → Warping
   - Control disabled
   - Speed = MaxVelocity × 10 × WarpSpeed
   - Monitors distance to target
4. State: Warping → Exiting
   - Strong deceleration (0.9x per frame)
   - Control returns when speed normalized
5. State: Exiting → Idle
   - Ship at target, ready for normal flight
```

## Testing the System

### Backend Test
```bash
# Start backend
cd EchoesBackend_v1
dotnet run

# Test endpoint (replace GUID and secret)
curl -X GET "http://localhost:5116/api/ship/{guid}/stats" \
  -H "X-Server-Secret: UE5-Server-Secret-Change-Me-In-Production"
```

### UE5 Test
1. Open `Client/Echoes/Echoes.uproject` in UE5.6
2. Create Blueprint based on `AEchoesShipPawn`
3. Add ship mesh and configure
4. Create Input Actions and assign
5. Place in level and test:
   - WASD movement
   - Mouse camera control
   - Right-click mouse follow
   - E for warp (example)

## Key Features Achieved

✅ **Physics-Based Movement**: Real AddForce/AddTorque, no teleportation
✅ **Backend Authority**: All stats from database via API
✅ **EVE-style Inertia**: Camera lag + damping = mass feel
✅ **Warp System**: Alignment → Warping → Exit with state machine
✅ **Modular Fitting**: Modules affect total mass and performance
✅ **Secure API**: Server-to-server authentication
✅ **Mirror Architecture**: Clean separation, clear correspondence
✅ **Naming Conventions**: Common_, Client_, Server_ prefixes
✅ **Full Documentation**: Complete README and inline comments

## What's Not Implemented (Future Work)

- [ ] Network replication (ServerRPC/ClientRPC)
- [ ] Module effects beyond mass (thrust bonuses, etc.)
- [ ] Visual warp effects (tunnel, particles)
- [ ] UI for warp destination selection
- [ ] Capacitor system
- [ ] Shield/Armor/Structure damage
- [ ] Module activation system
- [ ] Skill system integration
- [ ] Navigation/autopilot
- [ ] Fleet/wing mechanics

## Configuration

### Backend (`appsettings.json`)
```json
{
  "ServerSecret": "UE5-Server-Secret-Change-Me-In-Production",
  "ConnectionStrings": {
    "DefaultConnection": "Host=localhost;Database=echoes_universe;..."
  }
}
```

### UE5 (`DefaultGame.ini` or Project Settings)
```ini
[/Script/Echoes.EchoesShipStatsSubsystem]
ApiBaseUrl=http://localhost:5116/api
ServerSecret=UE5-Server-Secret-Change-Me-In-Production
```

## Performance Considerations

- Physics simulation runs on tick (can be throttled if needed)
- HTTP requests are async, don't block game thread
- Camera lag uses smooth interpolation (performance-friendly)
- Warp state machine is lightweight (simple switches)

## Security

- All ship endpoints require `X-Server-Secret` header
- Secret should be changed in production
- Consider additional validation (player ownership, etc.)
- Use HTTPS in production environment

## Conclusion

This implementation provides a solid foundation for an EVE-like ship movement system. The architecture is clean, extensible, and follows best practices for both backend and client development. The "mirror architecture" ensures maintainability, and the naming conventions make the codebase self-documenting.

The physics-based approach with proper inertia and camera lag gives players a real sense of piloting massive starships, while the warp system adds strategic depth to navigation.
