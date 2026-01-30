# Quick Start Guide - EVE-like Ship Movement System

## What Was Built

A complete ship movement system inspired by EVE Online with:
- **Backend**: ASP.NET Core 8 API for ship stats and fitting
- **Client**: Unreal Engine 5.6 C++ physics-based movement
- **Integration**: HTTP API with authentication

## File Locations

### Backend (ASP.NET Core)
```
Controllers/Ship/ShipController.cs          - API endpoints
Models/DTOs/ShipStatsDto.cs                 - Response format
Models/Entities/Inventory/Ship.cs           - Ship type with stats
Models/Entities/Inventory/ShipInstance.cs   - Player ships
Models/Entities/Inventory/ShipInstanceModule.cs - Fitted modules
Services/Ship/ShipFittingService.cs         - Mass calculation
```

### UE5 Client
```
Client/Echoes/Source/Echoes/Core/
├── Common/
│   ├── EchoesShipTypes.h                   - Structs and enums
│   ├── EchoesShipMovementComponent.h/cpp   - Physics movement
│   └── EchoesShipStatsSubsystem.h/cpp      - Backend API
└── Client/
    └── EchoesShipPawn.h/cpp                - Player ship
```

## Quick Setup

### 1. Backend Configuration

**appsettings.json:**
```json
{
  "ServerSecret": "your-secret-here",
  "ConnectionStrings": {
    "DefaultConnection": "Host=localhost;Database=echoes;..."
  }
}
```

**Run:**
```bash
cd EchoesBackend_v1
dotnet run
```

### 2. UE5 Configuration

**DefaultGame.ini or Project Settings:**
```ini
[/Script/Echoes.EchoesShipStatsSubsystem]
ApiBaseUrl=http://localhost:5116/api
ServerSecret=your-secret-here
```

**Create Ship Blueprint:**
1. Create Blueprint from `AEchoesShipPawn`
2. Add ship mesh to ShipMesh component
3. Set up Input Mapping Context
4. Create Input Actions (Move, Look, MouseFollow, Warp)

**Initialize Ship:**
```cpp
// Get subsystem
auto Subsystem = GetGameInstance()->GetSubsystem<UEchoesShipStatsSubsystem>();

// Fetch stats from backend
Subsystem->FetchShipStats(ShipId, OnSuccess, OnError);
```

## API Endpoints

### Get Ship Stats
```
GET /api/ship/{guid}/stats
Headers:
  X-Server-Secret: your-secret-here

Response:
{
  "shipId": "...",
  "shipName": "My Frigate",
  "totalMass": 1500000.0,
  "baseMass": 1000000.0,
  "thrust": 600000.0,
  "rotationSpeed": 35.0,
  "warpSpeed": 3.0,
  "inertiaMultiplier": 1.0,
  "maxVelocity": 150.0,
  "agility": 1.5
}
```

### Add Module
```
POST /api/ship/{guid}/modules
Headers:
  X-Server-Secret: your-secret-here
  Content-Type: application/json

Body:
{
  "moduleTypeId": 123,
  "mass": 50000.0,
  "slot": "High"
}
```

## Controls (Default)

- **WASD** - Thrust (Forward/Back/Strafe)
- **Mouse** - Camera rotation
- **Right Click** - Toggle mouse follow (ship aligns to camera)
- **E** (example) - Initiate warp

## Architecture

### Backend: "Postgres is Truth"
All ship stats stored in database. Formula:
```
TotalMass = BaseMass + Σ ModuleMass
```

### UE5: "Mirror Architecture"
Each backend controller has a corresponding subsystem:
- `ShipController` (C#) ↔ `UEchoesShipStatsSubsystem` (C++)

### Naming Conventions
- `Common_` - Shared logic (physics, calculations)
- `Client_` - Client-only (input, camera, UI)
- `Server_` - Server-only (validation, auth)

## Physics System

Movement uses pure UE5 physics:
- `AddForce()` for thrust
- `SetPhysicsAngularVelocityInRadians()` for rotation
- No teleportation, all forces are applied properly
- Camera lag provides sense of mass

## Warp System

State machine:
1. **Idle** - Normal flight
2. **Aligning** - Turn to target + build speed (need 75% max + 5° alignment)
3. **Warping** - High speed (10x) with disabled control
4. **Exiting** - Decelerate back to normal

## Testing

### Test Backend
```bash
curl -X GET "http://localhost:5116/api/ship/{guid}/stats" \
  -H "X-Server-Secret: your-secret-here"
```

### Test UE5
1. Open Echoes.uproject
2. Create ship blueprint
3. Place in level
4. Play and use WASD to move

## Documentation

- **IMPLEMENTATION_SUMMARY.md** - Complete technical overview
- **Client/Echoes/SHIP_MOVEMENT_SYSTEM.md** - Detailed UE5 guide
- **This file** - Quick reference

## Troubleshooting

**Ship doesn't move:**
- Check `ShipMesh->SetSimulatePhysics(true)`
- Verify mass is set from backend stats

**API returns 401:**
- Check X-Server-Secret matches in both configs

**Warp doesn't work:**
- Need alignment < 5° and speed > 75% max

## Next Steps

Implement:
- [ ] Network replication (multiplayer)
- [ ] Module effects beyond mass
- [ ] Visual warp effects
- [ ] UI for ship fitting
- [ ] Capacitor system
- [ ] Damage model

## Support

See full documentation:
- IMPLEMENTATION_SUMMARY.md
- Client/Echoes/SHIP_MOVEMENT_SYSTEM.md
