# Regional Cluster Infrastructure Implementation Plan

## Overview
Transition from "1 System = 1 Server" to "1 Region = 1 Server" model for massive multiplayer scalability.

## Architecture Changes

### 1. Command Line Initialization
**Location:** `UEchoesServerManagementSubsystem::Initialize()`

**Parameters to Parse:**
- `-RegionId=<GUID>` - Specifies which region this server hosts
- `-ServerType=RegionalCluster` - Activates regional cluster mode
- `-SolarSystemId=<GUID>` - Legacy parameter for dedicated system mode

**Implementation:**
```cpp
FString ServerType = TEXT("DedicatedSystem"); // Default
FGuid RegionId;
FGuid SolarSystemId;

// Parse command line
FString CommandLine = FCommandLine::Get();
FParse::Value(*CommandLine, TEXT("ServerType="), ServerType);
FParse::Value(*CommandLine, TEXT("RegionId="), RegionId);
FParse::Value(*CommandLine, TEXT("SolarSystemId="), SolarSystemId);
```

### 2. Regional Config Structures
**Added:** `FServerRegionalClusterConfig` in `EchoesServerDiscoveryTypes.h`

**Properties:**
- RegionId, RegionName, RegionCode
- AverageSecurity, ConstellationCount, SystemCount
- TotalPlanets, TotalStargates, TotalStations
- `TArray<FServerSystemConfig> Systems` - All systems in region

### 3. Spatial Partitioning

**System Offset Calculation:**
```cpp
// Each system gets massive offset based on DB coordinates
FVector SystemOffset = FVector(
    System.PositionX * REGION_SCALE_FACTOR,
    System.PositionY * REGION_SCALE_FACTOR,
    System.PositionZ * REGION_SCALE_FACTOR
);

// REGION_SCALE_FACTOR = 1,000,000,000.0 (1 billion units)
```

**Large World Coordinates (LWC):**
- UE5 supports double precision for world coordinates
- Prevents floating-point jitter at large distances
- Automatic when using UE 5.0+

### 4. Intelligent Stargate Jumping

**Two Jump Modes:**

**A. Intra-Server Jump (Local):**
```cpp
// Check if target system is on this server
if (IsSystemOnThisServer(TargetSystemId))
{
    // Get target gate location
    FVector TargetLocation = GetTargetGateLocation(TargetSystemId);
    
    // Teleport ship instantly
    Ship->SetActorLocation(TargetLocation);
    
    // Play transition effects
    PlayLocalJumpEffects();
}
```

**B. Inter-Server Jump (External):**
```cpp
else
{
    // Query backend for target server IP/Port
    FString TargetURL = GetServerURLForSystem(TargetSystemId);
    
    // Initiate client travel
    PlayerController->ClientTravel(TargetURL, TRAVEL_Absolute);
}
```

### 5. Optimization Systems

**Tick Management:**
```cpp
// Systems without players enter low-tick mode
if (PlayersInSystem == 0)
{
    SetActorTickInterval(5.0f); // Tick every 5 seconds
}
else
{
    SetActorTickInterval(0.0f); // Normal tick rate
}
```

**Heartbeat Updates:**
```cpp
// Report total players across all systems in region
int32 TotalPlayers = 0;
for (const FSystemState& System : ManagedSystems)
{
    TotalPlayers += System.PlayerCount;
}
HeartbeatRequest.OnlinePlayers = TotalPlayers;
```

## Implementation Steps

### Phase 1: Foundation ✅
- [x] Add FServerRegionalClusterConfig structure
- [ ] Update ServerManagementSubsystem for command line parsing
- [ ] Add regional cluster mode flag

### Phase 2: World Generator
- [ ] Refactor WorldGenerator to handle TArray<FServerSystemConfig>
- [ ] Implement spatial partitioning with large offsets
- [ ] Add system tracking (active/inactive)

### Phase 3: Stargate Intelligence
- [ ] Add system lookup (is system on this server?)
- [ ] Implement intra-server teleportation
- [ ] Maintain inter-server travel for external systems

### Phase 4: Optimization
- [ ] Implement tick management for inactive systems
- [ ] Update heartbeat to report regional totals
- [ ] Add player count tracking per system

### Phase 5: Testing
- [ ] Test regional cluster registration
- [ ] Test multiple system spawning with offsets
- [ ] Test intra-server jumps
- [ ] Test inter-server jumps
- [ ] Test tick optimization

## Configuration Examples

### Dedicated System Server (Legacy)
```
UE5Server.exe -SolarSystemId=abc-123-def-456 -ServerType=DedicatedSystem
```

### Regional Cluster Server (New)
```
UE5Server.exe -RegionId=region-789-xyz-012 -ServerType=RegionalCluster
```

## Database Queries

### Regional Config Endpoint
```
GET /api/server-management/config
Headers:
    X-Server-Secret: <secret>
Body:
{
    "ServerType": "RegionalCluster",
    "RegionId": "region-789-xyz-012"
}
```

### Response
```json
{
    "Config": {
        "RegionId": "...",
        "RegionName": "The Forge",
        "Systems": [
            { "SystemId": "...", "SystemName": "Jita", "PositionX": 0, ... },
            { "SystemId": "...", "SystemName": "Perimeter", "PositionX": 100000000, ... }
        ]
    }
}
```

## Performance Metrics

### System Separation
- Minimum distance between systems: 1 billion units
- Prevents visual/physics interference
- Supports hundreds of systems per region

### Tick Optimization
- Active system: ~60 FPS (normal tick)
- Inactive system: ~0.2 FPS (5 second intervals)
- CPU savings: Up to 99% for inactive systems

### Player Distribution
- Active systems: Full simulation
- Empty systems: Minimal overhead
- Automatic transition on player enter/exit

## Migration Path

### Step 1: Backend Support
- Verify regional cluster endpoints work
- Test multi-system config responses

### Step 2: UE5 Implementation
- Deploy updated ServerManagementSubsystem
- Deploy updated WorldGenerator
- Deploy updated Stargate logic

### Step 3: Server Configuration
- Configure command line parameters
- Test in isolated environment
- Monitor performance metrics

### Step 4: Production Rollout
- Deploy to test region
- Monitor player experience
- Scale to additional regions
