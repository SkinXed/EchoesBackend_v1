# World Generation Documentation

This directory contains documentation for the Echoes procedural world generation system.

---

## 📚 Available Documentation

- **[World Generator README](WORLD_GENERATOR_README.md)** - World generation system overview
- **[World Generator Implementation Summary](WORLD_GENERATOR_IMPLEMENTATION_SUMMARY.md)** - Detailed implementation

---

## 🌌 Overview

The Echoes world generation system creates a procedural universe similar to EVE Online, with:

- **Galaxy** - Multiple regions and constellations
- **Solar Systems** - Stars, planets, moons, asteroid belts
- **Connections** - Stargates linking systems
- **Structures** - Stations, outposts, and player structures

---

## 🎯 Key Features

### Procedural Generation

- **Deterministic** - Same seed produces same universe
- **Scalable** - Can generate thousands of systems
- **Persistent** - Generated systems are saved to database
- **Dynamic** - Can add new systems at runtime

### System Types

1. **High-Security (HighSec)** - Safe starting areas
2. **Low-Security (LowSec)** - Moderate danger
3. **Null-Security (NullSec)** - Player-controlled territory
4. **Wormhole Space** - Isolated systems with special properties

---

## 🏗️ Architecture

### Generation Pipeline

```
Seed Input
   ↓
Galaxy Structure (regions, constellations)
   ↓
Solar System Generation (stars, planets)
   ↓
Asset Placement (stations, gates)
   ↓
Database Persistence
   ↓
Runtime Loading
```

### Key Classes

| Class | Purpose | Location |
|-------|---------|----------|
| `UEchoesWorldGenerator` | Main generation logic | `Core/Common/World/` |
| `AStargateActor` | Jump gate connections | `Core/Common/Actors/` |
| `APlanetActor` | Planetary bodies | `Core/Common/Actors/` |
| `AStarActor` | Star systems | `Core/Common/Actors/` |
| `AStationActor` | Space stations | `Core/Common/Actors/` |
| `AAsteroidBeltActor` | Asteroid belts | `Core/Common/Actors/` |

---

## 🌍 World Structure

### Hierarchy

```
Universe
└── Galaxy
    └── Region (e.g., "The Forge")
        └── Constellation (e.g., "Kimotoro")
            └── Solar System (e.g., "Jita")
                ├── Star (central body)
                ├── Planets (orbiting star)
                │   └── Moons (orbiting planets)
                ├── Asteroid Belts
                ├── Stations
                └── Stargates (to other systems)
```

### Coordinate System

- **Global Coordinates** - Universe-wide position (used in database)
- **Local Coordinates** - Position within solar system (used in UE5)
- **Grid System** - Sector-based organization for large-scale operations

---

## 🔧 Generation Parameters

### Solar System Generation

```cpp
// System configuration
struct FSolarSystemConfig
{
    int32 Seed;                    // Random seed
    float SecurityStatus;          // 0.0 (null) to 1.0 (high sec)
    int32 MinPlanets;              // Minimum planets
    int32 MaxPlanets;              // Maximum planets
    float AsteroidBeltChance;      // Probability of asteroid belt
    int32 StationCount;            // Number of stations
};
```

### Planet Generation

- **Size** - Random within range based on planet type
- **Orbit** - Distance from star (based on order)
- **Moons** - Random number based on planet size
- **Resources** - Ore availability for mining

---

## 🎮 Runtime Loading

### Streaming Strategy

1. **Pre-load** - Load current system on player spawn
2. **Adjacent Systems** - Pre-load connected systems (via stargates)
3. **Unload** - Unload systems when player leaves region
4. **Persistence** - Save changes (destroyed asteroids, etc.)

### Performance Optimization

- **LOD System** - Detailed close, simplified far
- **Instanced Rendering** - Asteroid fields use instanced static meshes
- **Occlusion Culling** - Don't render hidden objects
- **Async Loading** - Load assets asynchronously

---

## 🚪 Stargate System

### Jump Mechanics

1. **Activation** - Player clicks stargate or uses jump command
2. **Align** - Ship aligns to stargate
3. **Animation** - Jump animation (wormhole effect)
4. **Level Transition** - Load destination system
5. **Spawn** - Appear at destination stargate

### Network Flow

```
Client: Request Jump
   ↓
Server: Validate (distance, restrictions)
   ↓
Server: Initiate Jump Animation
   ↓
Server: Transfer to Destination System
   ↓
Client: Load New System
```

---

## 📊 Database Schema

### Tables

```sql
-- Solar systems
CREATE TABLE SolarSystems (
    SystemId UUID PRIMARY KEY,
    Name VARCHAR(100),
    SecurityStatus FLOAT,
    StarType INT,
    Position_X FLOAT,
    Position_Y FLOAT,
    Position_Z FLOAT
);

-- Stargates
CREATE TABLE Stargates (
    GateId UUID PRIMARY KEY,
    SystemId UUID REFERENCES SolarSystems,
    DestinationGateId UUID REFERENCES Stargates,
    Position_X FLOAT,
    Position_Y FLOAT,
    Position_Z FLOAT
);

-- Celestial bodies (planets, moons)
CREATE TABLE Celestials (
    CelestialId UUID PRIMARY KEY,
    SystemId UUID REFERENCES SolarSystems,
    Type INT,
    Name VARCHAR(100),
    OrbitRadius FLOAT,
    Size FLOAT
);
```

---

## 🎨 Visual Design

### Asset Types

1. **Stars**
   - Main sequence (yellow, white, red)
   - Giants (red giants, supergiants)
   - Neutron stars, black holes (rare)

2. **Planets**
   - Rocky (Mars-like)
   - Gas giants (Jupiter-like)
   - Ice worlds
   - Lava planets

3. **Moons**
   - Barren
   - Icy
   - Volcanic (Io-like)

4. **Stations**
   - Trading stations
   - Industrial complexes
   - Military outposts

---

## 🔮 Future Enhancements

### Planned Features

- [ ] Wormhole space generation
- [ ] Anomalies and exploration sites
- [ ] Player-built structures
- [ ] Territory control mechanics
- [ ] Sovereignty system
- [ ] Resource distribution balancing

---

## 📖 Related Documentation

- [Ship Movement System](../systems/SHIP_MOVEMENT_SYSTEM.md) - Travel mechanics
- [Architecture Overview](../architecture/ARCHITECTURAL_IMPROVEMENTS.md) - System architecture

---

**Last Updated**: 2026-02-01
