# Universe System Architecture

## Component Hierarchy

```
AEchoesWorldGenerator (Server-Only)
│
├── Subscribes to: UEchoesServerManagementSubsystem::OnServerConfigReceived
│
├── Spawns:
│   ├── AStarActor (1 per system)
│   ├── APlanetActor[] (multiple per system)
│   ├── AStationActor[] (multiple per system)
│   ├── AStargateActor[] (connections to other systems)
│   ├── AAsteroidBeltActor[] ⭐ NEW
│   ├── AAnomalyActor[] ⭐ NEW
│   └── AWormholeActor[] ⭐ NEW
│
└── Uses:
    ├── UDataTable* PlanetDataTable
    ├── UDataTable* StarDataTable
    ├── UDataTable* StationDataTable
    ├── UDataTable* StargateDataTable
    ├── UDataTable* AsteroidBeltDataTable ⭐ NEW
    ├── UDataTable* AnomalyDataTable ⭐ NEW
    └── UDataTable* WormholeDataTable ⭐ NEW
```

## Data Flow

```
Backend (ASP.NET Core)                     UE5 Client
─────────────────────                     ───────────
ServerManagementController                UEchoesServerManagementSubsystem
        │                                         │
        │  GET /api/server-management/config     │
        ├────────────────────────────────────────>│
        │                                         │
        │  ServerSystemConfigDto {               │
        │    Planets[]                            │
        │    Stargates[]                          │
        │    Stations[]                           │
        │    AsteroidBelts[] ⭐                   │
        │    Anomalies[] ⭐                       │
        │    Wormholes[] ⭐                       │
        │  }                                      │
        │<────────────────────────────────────────┤
        │                                         │
                                                  ▼
                                    OnServerConfigReceived.Broadcast()
                                                  │
                                                  ▼
                                    AEchoesWorldGenerator::OnServerConfigReceived()
                                                  │
                                    ┌─────────────┴─────────────┐
                                    ▼                           ▼
                          SpawnStars()                  SpawnPlanets()
                          SpawnStations()               SpawnStargates()
                          SpawnAsteroidBelts() ⭐      
                          SpawnAnomalies() ⭐          
                          SpawnWormholes() ⭐          
```

## Asteroid Belt Architecture

```
AAsteroidBeltActor
│
├── Components:
│   ├── USceneComponent (Root)
│   ├── UHierarchicalInstancedStaticMeshComponent ⭐ (PERFORMANCE KEY)
│   │   └── Instances[1000+] (Single draw call!)
│   ├── UNiagaraComponent (Dust cloud VFX)
│   └── UAudioComponent (Ambient sound)
│
├── Initialization:
│   ├── Load mesh from FAsteroidBeltVisualRow
│   ├── GenerateAsteroidPositions() using Seed
│   │   └── Toroidal distribution pattern
│   ├── SetupAsteroidCollision()
│   └── SpawnEnvironmentalEffects()
│
└── Properties:
    ├── BeltId (Guid) - Replicated
    ├── BeltName (String) - Replicated
    ├── GenerationSeed (int32)
    ├── Radius (float)
    └── AsteroidCount (int32)
```

## Anomaly Actor Architecture

```
AAnomalyActor
│
├── Components:
│   ├── USceneComponent (Root)
│   ├── UStaticMeshComponent (Center structure)
│   ├── UNiagaraComponent (Signature VFX) - Activated on scan
│   ├── UNiagaraComponent (Type-specific VFX) - Always active
│   ├── UAudioComponent (Ambient)
│   ├── UAudioComponent (Warning)
│   └── USphereComponent (Trigger zone)
│
├── Types:
│   ├── Combat (Red) - Combat encounters
│   ├── Data (Blue) - Hacking/scanning
│   ├── Relic (Gold) - Ancient artifacts
│   ├── Gas (Green) - Gas harvesting
│   └── Ore (Gray) - Mineral extraction
│
├── Difficulty Levels:
│   ├── Easy (0.8x scale)
│   ├── Medium (1.0x scale)
│   ├── Hard (1.3x scale)
│   └── Elite (1.6x scale)
│
└── Properties:
    ├── AnomalyId (Guid) - Replicated
    ├── AnomalyName (String) - Replicated
    ├── AnomalyType (String) - Replicated
    ├── AnomalyDifficulty (String) - Replicated
    ├── bSignatureActive (bool) - Replicated
    └── GenerationSeed (int32)
```

## Wormhole Actor Architecture

```
AWormholeActor
│
├── Components:
│   ├── USceneComponent (Root)
│   ├── UStaticMeshComponent (Entrance ring - optional)
│   ├── UNiagaraComponent (Main wormhole VFX)
│   ├── UNiagaraComponent (Instability VFX - 30% chance)
│   ├── UAudioComponent (Ambient hum)
│   ├── UAudioComponent (Entrance sound)
│   └── USphereComponent (Jump trigger zone)
│
├── Color Generation (Deterministic):
│   ├── Seed from TargetSystemId GUID
│   ├── R: 0.2-0.7, G: 0.3-0.8, B: 0.6-1.0
│   └── Always has strong blue component (space-like)
│
├── Trigger Logic:
│   └── OnTriggerBeginOverlap() → InitiateJump()
│
└── Properties:
    ├── WormholeId (Guid) - Replicated
    ├── WormholeName (String) - Replicated
    ├── TargetSystemId (Guid) - Replicated ⭐
    ├── GenerationSeed (int32)
    └── WormholeColor (FLinearColor)
```

## Performance Optimization Strategy

### Asteroid Belts - HISM
```
Traditional Approach:          HISM Approach:
┌─────────────────┐           ┌─────────────────┐
│ 1000 AActor     │           │ 1 AActor        │
│ 1000 Draw Calls │   VS      │ 1 Draw Call     │
│ High CPU Cost   │           │ Low CPU Cost    │
│ High Memory     │           │ Low Memory      │
└─────────────────┘           └─────────────────┘
    ❌ Bad                         ✅ Good
```

### Replication Strategy
```
All Actors: bReplicates = true, bAlwaysRelevant = true

Server              Client 1          Client 2
  │                    │                 │
  ├─ Spawn ───────────>│                 │
  ├─ Replicate Props ─>│                 │
  ├─ Spawn ───────────────────────────>│
  └─ Replicate Props ─────────────────>│
```

## Integration Points

### Backend Requirements
1. Database must include:
   - `AsteroidBelts` table with position, resources
   - `Anomalies` table with type, difficulty
   - `Wormholes` table with source/target systems

2. ServerManagementController must return:
   - `AsteroidBelts[]` in ServerSystemConfigDto
   - `Anomalies[]` in ServerSystemConfigDto
   - `Wormholes[]` in ServerSystemConfigDto

### UE5 Requirements
1. Create Data Tables:
   - DT_AsteroidBelts (FAsteroidBeltVisualRow)
   - DT_Anomalies (FAnomalyVisualRow)
   - DT_Wormholes (FWormholeVisualRow)

2. Assign in BP_WorldGenerator:
   - AsteroidBeltDataTable → DT_AsteroidBelts
   - AnomalyDataTable → DT_Anomalies
   - WormholeDataTable → DT_Wormholes

3. Create Blueprint Classes:
   - BP_AsteroidBelt (parent: AAsteroidBeltActor)
   - BP_Anomaly (parent: AAnomalyActor)
   - BP_Wormhole (parent: AWormholeActor)

4. Assign in BP_WorldGenerator:
   - AsteroidBeltActorClass → BP_AsteroidBelt
   - AnomalyActorClass → BP_Anomaly
   - WormholeActorClass → BP_Wormhole

## Future Integration: Jump System

```
Player Ship Enters Wormhole
         │
         ▼
AWormholeActor::OnTriggerBeginOverlap()
         │
         ▼
AWormholeActor::InitiateJump(Ship)
         │
         ▼
UEchoesServerManagementSubsystem::RequestSystemJump(TargetSystemId)
         │
         ▼
Backend API: POST /api/travel/jump
         │
         ▼
ServerManagementController::ProcessJump()
         │
         ├─ Validate jump requirements
         ├─ Apply costs/cooldowns
         └─ Initiate server travel
               │
               ▼
         UE5 SeamlessTravel to Target Server
```
