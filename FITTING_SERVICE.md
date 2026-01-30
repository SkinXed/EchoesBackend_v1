# Enhanced Ship Fitting Service

## Overview

The Enhanced Ship Fitting Service calculates final ship statistics by applying bonuses from fitted modules. This implements the "Postgres is Truth" principle where the backend authoritatively calculates all ship characteristics.

## Architecture

```
┌─────────────────────────────────────────────────────────────┐
│                    DATABASE (PostgreSQL)                    │
│                                                             │
│  ┌────────────┐         ┌──────────────────┐              │
│  │ ships      │         │ ship_instances   │              │
│  │ (types)    │◄────────│ (player ships)   │              │
│  └────────────┘         └────────┬─────────┘              │
│       │ base stats               │                         │
│       │ - BaseMass               │                         │
│       │ - BaseThrust             │                         │
│       │ - BaseInertia            │                         │
│       │                          │                         │
│       │                 ┌────────▼──────────────────┐      │
│       │                 │ ship_instance_modules     │      │
│       │                 │ (fitted modules)          │      │
│       │                 │ - Mass                    │      │
│       │                 │ - ThrustBonus            │      │
│       │                 │ - InertiaModifier        │      │
│       │                 │ - RotationBonus          │      │
│       │                 │ - MaxVelocityModifier    │      │
│       │                 └───────────────────────────┘      │
│       │                                                    │
└───────┼────────────────────────────────────────────────────┘
        │
        ▼
┌─────────────────────────────────────────────────────────────┐
│              ShipFittingService (C#)                        │
│                                                             │
│  CalculateShipStatsAsync(shipInstanceId)                   │
│  ├─ Load ship instance + modules                           │
│  ├─ Calculate TotalMass = BaseMass + Σ ModuleMass         │
│  ├─ Calculate TotalThrust = BaseThrust + Σ ThrustBonus    │
│  ├─ Calculate TotalInertia = BaseInertia * Π InertiaModifier│
│  ├─ Calculate TotalRotation = BaseRotation + Σ RotationBonus│
│  └─ Calculate TotalMaxVel = BaseMaxVel * Π MaxVelModifier │
│                                                             │
└─────────────────────────────────────────────────────────────┘
        │
        ▼
┌─────────────────────────────────────────────────────────────┐
│              ShipController (API)                           │
│                                                             │
│  GET /api/ship/{id}/stats                                  │
│  └─ Returns ShipStatsDto (mirrors UE5 FEchoesShipStats)    │
│                                                             │
│  POST /api/ship/{id}/modules                               │
│  └─ Add module with bonuses                                │
│                                                             │
│  PUT /api/ship/modules/{id}/bonuses                        │
│  └─ Update module bonuses                                  │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

## Module Bonus System

### Bonus Types

Modules can affect ship stats in two ways:

1. **Additive Bonuses** - Values are summed
   - Mass
   - Thrust
   - Rotation Speed

2. **Multiplicative Modifiers** - Values are multiplied
   - Inertia Multiplier
   - Max Velocity Modifier

### Calculation Formulas

```csharp
// 1. MASS (Additive)
TotalMass = BaseMass + Σ(ModuleMass)
Example: 1,000,000 kg (base) + 500,000 kg (armor plates) = 1,500,000 kg

// 2. THRUST (Additive)
TotalThrust = BaseThrust + Σ(ThrustBonus)
Example: 500,000 N (base) + 100,000 N (afterburner) = 600,000 N

// 3. INERTIA (Multiplicative)
TotalInertia = BaseInertia * Π(InertiaModifier)
Example: 1.0 (base) * 0.9 (nanofiber) * 0.85 (overclocking) = 0.765
Note: Lower inertia = better agility

// 4. ROTATION (Additive)
TotalRotation = BaseRotation + Σ(RotationBonus)
Example: 30 deg/s (base) + 5 deg/s (gyro stabilizer) = 35 deg/s

// 5. MAX VELOCITY (Multiplicative)
TotalMaxVelocity = BaseMaxVelocity * Π(MaxVelocityModifier)
Example: 100 m/s (base) * 1.1 (overdrive) * 1.05 (nanofiber) = 115.5 m/s
```

## API Usage

### Get Ship Stats

**Request:**
```http
GET /api/ship/{guid}/stats
Headers:
  X-Server-Secret: your-secret-here
```

**Response:**
```json
{
  "shipId": "123e4567-e89b-12d3-a456-426614174000",
  "shipName": "My Frigate",
  "shipTypeId": 587,
  "shipTypeName": "Merlin",
  "baseMass": 1000000.0,
  "totalMass": 1500000.0,
  "thrust": 600000.0,
  "rotationSpeed": 35.0,
  "warpSpeed": 3.0,
  "inertiaMultiplier": 0.765,
  "maxVelocity": 115.5,
  "agility": 2.5
}
```

### Add Module with Bonuses

**Request:**
```http
POST /api/ship/{guid}/modules
Headers:
  X-Server-Secret: your-secret-here
  Content-Type: application/json

Body:
{
  "moduleTypeId": 2032,
  "mass": 500000.0,
  "slot": "Low",
  "slotIndex": 0,
  "thrustBonus": 0,
  "inertiaModifier": 0.9,
  "rotationBonus": 0,
  "maxVelocityModifier": 1.0
}
```

**Response:**
```json
{
  "message": "Module added successfully"
}
```

### Update Module Bonuses

**Request:**
```http
PUT /api/ship/modules/{moduleGuid}/bonuses
Headers:
  X-Server-Secret: your-secret-here
  Content-Type: application/json

Body:
{
  "thrustBonus": 100000.0,
  "inertiaModifier": 0.85,
  "rotationBonus": 5.0,
  "maxVelocityModifier": 1.1
}
```

## Example: Fitting a Frigate

### Base Ship (Merlin)
- BaseMass: 1,000,000 kg
- BaseThrust: 500,000 N
- BaseInertia: 1.0
- BaseRotation: 30 deg/s
- BaseMaxVelocity: 100 m/s

### Fitted Modules

1. **1600mm Steel Plates (Armor)**
   - Mass: +500,000 kg
   - InertiaModifier: 1.2 (worse agility)

2. **Afterburner (Propulsion)**
   - Mass: +50,000 kg
   - ThrustBonus: +150,000 N
   - MaxVelocityModifier: 1.2

3. **Nanofiber Internal Structure (Agility)**
   - Mass: +10,000 kg
   - InertiaModifier: 0.9 (better agility)
   - MaxVelocityModifier: 1.05

4. **Gyrostabilizer (Rotation)**
   - Mass: +20,000 kg
   - RotationBonus: +5 deg/s

### Final Stats

```csharp
TotalMass = 1,000,000 + 500,000 + 50,000 + 10,000 + 20,000
          = 1,580,000 kg

TotalThrust = 500,000 + 0 + 150,000 + 0 + 0
            = 650,000 N

TotalInertia = 1.0 * 1.2 * 1.0 * 0.9 * 1.0
             = 1.08 (slightly worse than base)

TotalRotation = 30 + 0 + 0 + 0 + 5
              = 35 deg/s

TotalMaxVelocity = 100 * 1.0 * 1.2 * 1.05 * 1.0
                 = 126 m/s
```

**Effect on Ship:**
- Heavier (58% more mass) → harder to accelerate
- More thrust (30% more) → compensates somewhat
- Slightly worse inertia (8% worse) → slower response
- Better rotation (17% more) → turns faster
- Much faster top speed (26% more) → zooms!

## Integration with UE5

The UE5 ship movement component consumes these stats:

```cpp
// UE Server fetches stats from backend
auto Subsystem = GetGameInstance()->GetSubsystem<UEchoesShipStatsSubsystem>();
Subsystem->FetchShipStats(ShipId, OnSuccess, OnError);

// Apply to movement component
void OnSuccess(const FEchoesShipStats& Stats)
{
    ShipPawn->GetShipMovement()->InitializeShipStats(Stats);
    
    // Physics automatically applies:
    // - AddForce() uses Thrust
    // - Mass affects acceleration (F=ma)
    // - InertiaMultiplier affects damping
    // - MaxVelocity limits speed
}
```

## Module Effect Examples

### Propulsion Modules
```
Afterburner I:
  Mass: +50,000 kg
  ThrustBonus: +100,000 N
  MaxVelocityModifier: 1.15

Microwarpdrive:
  Mass: +100,000 kg
  ThrustBonus: +300,000 N
  MaxVelocityModifier: 5.0  (massive speed boost)
  InertiaModifier: 1.5  (worse handling)
```

### Armor Modules
```
400mm Steel Plates:
  Mass: +200,000 kg
  InertiaModifier: 1.1

1600mm Steel Plates:
  Mass: +800,000 kg
  InertiaModifier: 1.3
```

### Agility Modules
```
Nanofiber Internal Structure I:
  Mass: +10,000 kg
  InertiaModifier: 0.9  (10% better agility)
  MaxVelocityModifier: 1.05

Overdrive Injector:
  ThrustBonus: +50,000 N
  InertiaModifier: 0.85  (15% better agility)
  MaxVelocityModifier: 1.1
```

### Rotation Modules
```
Gyrostabilizer I:
  Mass: +20,000 kg
  RotationBonus: +3 deg/s

Auxiliary Thrusters:
  Mass: +30,000 kg
  RotationBonus: +8 deg/s
```

## Testing

### Test Ship Fitting

```csharp
// Create test ship instance
var shipInstance = new ShipInstance
{
    Id = Guid.NewGuid(),
    Name = "Test Frigate",
    ShipTypeId = 587,  // Merlin
    IsActive = true
};

// Add armor plate
await fittingService.AddModuleAsync(
    shipInstance.Id,
    moduleTypeId: 2032,
    mass: 500000f,
    slot: "Low",
    slotIndex: 0,
    thrustBonus: 0,
    inertiaModifier: 1.2f,
    rotationBonus: 0,
    maxVelocityModifier: 1.0f
);

// Add afterburner
await fittingService.AddModuleAsync(
    shipInstance.Id,
    moduleTypeId: 2048,
    mass: 50000f,
    slot: "Mid",
    slotIndex: 0,
    thrustBonus: 150000f,
    inertiaModifier: 1.0f,
    rotationBonus: 0,
    maxVelocityModifier: 1.2f
);

// Calculate final stats
var stats = await fittingService.CalculateShipStatsAsync(shipInstance.Id);

// Verify calculations
Assert.Equal(1550000f, stats.TotalMass);  // 1M + 500k + 50k
Assert.Equal(650000f, stats.Thrust);      // 500k + 150k
Assert.Equal(1.2f, stats.InertiaMultiplier);  // 1.0 * 1.2 * 1.0
```

## Performance Considerations

- Stats are calculated on-demand (not cached)
- For 100+ players, consider:
  - Caching recently calculated stats
  - Batch requests from UE Server
  - Database indexes on ship_instance_id

## Security

- All endpoints require `X-Server-Secret` header
- Only UE Server should have the secret
- Clients cannot directly fetch or modify ship stats
- See NETWORK_SECURITY.md for architecture details

## Future Enhancements

- [ ] Skill bonuses (character skills affect module effectiveness)
- [ ] CPU/Powergrid limitations (can't fit modules if insufficient)
- [ ] Module activation effects (temporary bonuses when activated)
- [ ] Rig slots (permanent modifications)
- [ ] Subsystems (strategic cruisers)
- [ ] Implants (character-level bonuses)
