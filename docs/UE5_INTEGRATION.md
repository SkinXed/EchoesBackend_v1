# Echoes of Imperial - UE5 Server Integration

> **Unreal Engine 5 Game Server Architecture**  
> Complete guide to server registration, world generation, and hangar system

**Version:** 2.0  
**Last Updated:** 2026-02-03  
**UE5 Version:** 5.3+  
**Server Type:** Dedicated Server (Authority Mode)

---

## Table of Contents

1. [Server Architecture Overview](#server-architecture-overview)
2. [Server Registration Flow](#server-registration-flow)
3. [World Generation System](#world-generation-system)
4. [Hangar Instance System](#hangar-instance-system)
5. [Server-to-Backend Communication](#server-to-backend-communication)
6. [Launch Scripts & Configuration](#launch-scripts--configuration)
7. [Performance & Optimization](#performance--optimization)

---

## Server Architecture Overview

### Server Types

**1. DedicatedSystem Server**
- One server per solar system
- Example: Genesis Prime Server handles only Genesis Prime system
- Players in different systems connect to different servers
- Optimal for high-population systems

**2. RegionalCluster Server**
- One server handles multiple systems in a region
- Example: Genesis Region Server handles all Genesis systems
- Players can travel between systems without server changes
- Optimal for low-population areas

### Architecture Diagram

```
┌─────────────────────────────────────────────────────────────┐
│  Unreal Engine 5 Dedicated Server                           │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│  ┌─────────────────────────────────────────────────────┐  │
│  │  AEchoesServerGameMode (Game Mode)                  │  │
│  │  ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━   │  │
│  │  • Entry point for server logic                     │  │
│  │  • Initializes subsystems                           │  │
│  │  • Spawns world generator                           │  │
│  │  • Manages player connections                       │  │
│  └─────────────────────────────────────────────────────┘  │
│                        │                                    │
│         ┌──────────────┼──────────────┐                    │
│         │              │              │                    │
│         ▼              ▼              ▼                    │
│  ┌────────────┐ ┌────────────┐ ┌────────────┐            │
│  │ServerMgmt  │ │   World    │ │  Hangar    │            │
│  │ Subsystem  │ │ Generator  │ │  Instance  │            │
│  └────────────┘ └────────────┘ └────────────┘            │
│        │              │              │                    │
│        │              │              │                    │
│        ▼              ▼              ▼                    │
│  ┌─────────────────────────────────────────────────────┐  │
│  │       ASP.NET Core Backend API                      │  │
│  │       (PostgreSQL Database)                         │  │
│  └─────────────────────────────────────────────────────┘  │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

### Key Components

| Component | Type | Purpose |
|-----------|------|---------|
| **AEchoesServerGameMode** | Game Mode | Orchestrates server initialization |
| **UEchoesServerManagementSubsystem** | Game Instance Subsystem | Handles server registration & config |
| **AEchoesWorldGenerator** | Actor | Spawns universe objects (planets, moons, stations) |
| **AEchoesHangarInstance** | Actor | Personal isolated hangar for each player |
| **UEchoesInventorySubsystem** | Game Instance Subsystem | Manages inventory and fitting |

---

## Server Registration Flow

### 1. Server Startup

```
Server Launch (Launch.bat/ps1)
    │
    ▼
Command Line Parameters:
  -server                         // Run as dedicated server
  -log                            // Enable logging
  -Port=7777                      // Listen port
  -ServerType=DedicatedSystem     // or RegionalCluster
  -SystemId=<guid>                // For DedicatedSystem
  -RegionId=<guid>                // For RegionalCluster
  -ApiUrl=https://api.echoes.com  // Backend URL
    │
    ▼
Load GameLevel Map
    │
    ▼
AEchoesServerGameMode::BeginPlay()
```

### 2. Subsystem Initialization

```cpp
// UEchoesServerManagementSubsystem::Initialize()

void UEchoesServerManagementSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    
    // 1. Parse command line arguments
    FString ServerType, SystemId, RegionId, ApiUrl;
    FParse::Value(FCommandLine::Get(), TEXT("ServerType="), ServerType);
    FParse::Value(FCommandLine::Get(), TEXT("SystemId="), SystemId);
    FParse::Value(FCommandLine::Get(), TEXT("RegionId="), RegionId);
    FParse::Value(FCommandLine::Get(), TEXT("ApiUrl="), ApiUrl);
    
    // 2. Build registration payload
    FServerRegistrationRequest Request;
    Request.ServerName = FString::Printf(TEXT("%s-%d"), *SystemId, FMath::Rand());
    Request.ServerType = ServerType;
    Request.IpAddress = GetPublicIP();
    Request.Port = GetListenPort();
    Request.SystemId = SystemId;  // or RegionId for RegionalCluster
    
    // 3. Send HTTP POST to /api/server-management/register
    RegisterWithBackend(Request);
}
```

### 3. Backend Registration

**HTTP Request:**
```http
POST /api/server-management/register
Content-Type: application/json

{
  "server_name": "Genesis-Prime-7777",
  "server_type": "DedicatedSystem",
  "ip_address": "192.168.1.100",
  "port": 7777,
  "solar_system_id": "550e8400-e29b-41d4-a716-446655440000",
  "max_players": 100
}
```

**Backend Response:**
```json
{
  "server_id": "server-guid-here",
  "jwt_token": "server-jwt-token",
  "config": {
    "system_name": "Genesis Prime",
    "system_id": "550e8400-e29b-41d4-a716-446655440000",
    "security_status": 1.0,
    "planets": [
      {
        "id": "planet-guid",
        "name": "Genesis I",
        "planet_type": "Terrestrial",
        "position": { "x": 100000000, "y": 0, "z": 0 },
        "radius": 6371000,
        "moons": [
          {
            "id": "moon-guid",
            "name": "Genesis I - Moon 1",
            "position": { "x": 105000000, "y": 0, "z": 0 },
            "radius": 1737400
          }
        ]
      }
    ],
    "stations": [...],
    "stargates": [...],
    "asteroid_belts": [...]
  }
}
```

### 4. Store Configuration

```cpp
// Cache configuration for world generation
ServerConfig = Response.Config;
ServerJWT = Response.JwtToken;
ServerId = Response.ServerId;

// Broadcast delegate for WorldGenerator to subscribe
OnServerConfigReceived.Broadcast(ServerConfig);
```

### 5. Heartbeat System

```cpp
// Send heartbeat every 30 seconds
void UEchoesServerManagementSubsystem::SendHeartbeat()
{
    FServerHeartbeatRequest Request;
    Request.ServerId = ServerId;
    Request.CurrentPlayers = GetNumPlayers();
    Request.Status = "Running";  // Running, Starting, Stopping
    
    // POST /api/server-management/heartbeat
    // Include JWT token in Authorization header
    SendHeartbeatToBackend(Request);
}
```

---

## World Generation System

### Overview

The world generator spawns all celestial objects based on backend configuration.

**Key Features:**
- **72 objects** in Genesis Prime (8 planets, 64 moons)
- **Procedural placement** based on database coordinates
- **Double precision** for large-scale positions (up to 1 billion units)
- **Network replication** to all clients

### Generation Flow

```
Server Registered
    │
    ▼
OnServerConfigReceived Delegate Fires
    │
    ▼
AEchoesWorldGenerator::OnServerConfigReceived()
    │
    ▼
Parse Config & Spawn Objects:
    ├─→ Spawn Planets (8)
    │   ├─→ Spawn Moons per Planet (0-12 each)
    │   └─→ Set Orbital Parameters
    ├─→ Spawn Stations (3-5)
    ├─→ Spawn Stargates (1-4)
    ├─→ Spawn Asteroid Belts (0-3)
    └─→ Spawn Anomalies (random)
    │
    ▼
World Generation Complete
    │
    ▼
Server Ready for Player Connections
```

### Code Example: Planet Spawning

```cpp
// AEchoesWorldGenerator::SpawnPlanet()

AEchoesPlanet* AEchoesWorldGenerator::SpawnPlanet(const FPlanetConfig& Config)
{
    // 1. Calculate spawn transform with double precision
    FVector SpawnLocation(Config.PositionX, Config.PositionY, Config.PositionZ);
    FRotator SpawnRotation = FRotator::ZeroRotator;
    FActorSpawnParameters SpawnParams;
    SpawnParams.Owner = this;
    SpawnParams.SpawnCollisionHandlingOverride = 
        ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
    
    // 2. Spawn planet actor
    AEchoesPlanet* Planet = GetWorld()->SpawnActor<AEchoesPlanet>(
        PlanetActorClass,
        SpawnLocation,
        SpawnRotation,
        SpawnParams
    );
    
    // 3. Configure planet properties
    Planet->PlanetId = Config.Id;
    Planet->PlanetName = Config.Name;
    Planet->PlanetType = Config.PlanetType;
    Planet->Radius = Config.Radius;
    Planet->SetActorScale3D(FVector(Config.Radius / 100000.0));
    
    // 4. Setup network replication
    Planet->bReplicates = true;
    Planet->bAlwaysRelevant = true;
    
    // 5. Spawn moons for this planet
    for (const FMoonConfig& MoonConfig : Config.Moons)
    {
        AEchoesMoon* Moon = SpawnMoon(MoonConfig, Planet);
        Planet->Moons.Add(Moon);
    }
    
    return Planet;
}
```

### Genesis System Example

**Genesis Prime System (72 Objects):**

| Planet | Moons | Total |
|--------|-------|-------|
| Genesis I | 1 | 2 |
| Genesis II | 4 | 5 |
| Genesis III | 12 | 13 |
| Genesis IV | 7 | 8 |
| Genesis V | 15 | 16 |
| Genesis VI | 8 | 9 |
| Genesis VII | 10 | 11 |
| Genesis VIII | 7 | 8 |
| **Total** | **64** | **72** |

Additional Objects:
- 4 Stations
- 3 Stargates
- 2 Asteroid Belts

**Total:** 81 actors spawned

### Coordinate Scale

```cpp
// UE5 uses centimeters as base unit
// Real-world astronomical distances are huge

// Example: Earth-Moon distance
const double EarthMoonDistance = 384400.0 * 1000.0 * 100.0;  // 384,400 km → cm
// = 38,440,000,000 cm (38.4 billion centimeters)

// UE5 double precision supports up to 2^53 (~9 quadrillion)
// More than enough for solar system scale
```

### Regional Clustering

For RegionalCluster servers, offset each system:

```cpp
// Genesis Region with 10 systems
// Offset each system by 1 billion units

SystemOffset = FVector(
    SystemIndex * 1000000000.0,  // 1 billion X offset
    0,
    0
);

// Genesis Prime: (0, 0, 0)
// Genesis II: (1B, 0, 0)
// Genesis III: (2B, 0, 0)
// etc.
```

---

## Hangar Instance System

### Concept: Personal Hangar

Each player has a **personal isolated hangar** when docked at a station.

**Key Features:**
- **Spatial Isolation**: Players in same station but different hangar instances
- **Private Space**: Other players cannot see your hangar
- **Persistent**: Hangar state saved in database
- **Dynamic Loading**: Spawned on-demand when player docks

### Hangar Flow

```
Player Docks at Station
    │
    ▼
Check if Hangar Instance Exists
    │
    ├─→ YES: Teleport player to existing instance
    │
    └─→ NO: Create new hangar instance
            │
            ▼
        Spawn AEchoesHangarInstance
            │
            ├─→ Offset position by PlayerIndex * 100000 units
            ├─→ Load player's ships from database
            ├─→ Spawn ship actors in hangar
            └─→ Teleport player into hangar
```

### Code Example: Hangar Creation

```cpp
// AEchoesServerGameMode::CreateHangarForPlayer()

AEchoesHangarInstance* AEchoesServerGameMode::CreateHangarForPlayer(
    APlayerController* Player,
    const FString& StationId
)
{
    // 1. Get player's character ID from JWT token
    FString CharacterId = GetCharacterIdFromPlayer(Player);
    
    // 2. Calculate isolated hangar position
    // Offset by 100km per player to prevent overlap
    int32 PlayerIndex = GetPlayerIndex(CharacterId);
    FVector HangarOffset(
        PlayerIndex * 10000000.0,  // 100km in cm
        0,
        0
    );
    FVector HangarLocation = StationLocation + HangarOffset;
    
    // 3. Spawn hangar instance
    AEchoesHangarInstance* Hangar = GetWorld()->SpawnActor<AEchoesHangarInstance>(
        HangarInstanceClass,
        HangarLocation,
        FRotator::ZeroRotator
    );
    
    // 4. Configure hangar
    Hangar->OwnerId = CharacterId;
    Hangar->StationId = StationId;
    Hangar->bReplicates = true;
    
    // 5. Load player's ships from backend API
    TArray<FShipData> Ships = LoadPlayerShips(CharacterId);
    for (const FShipData& ShipData : Ships)
    {
        AEchoesShipPawn* Ship = Hangar->SpawnShip(ShipData);
        Ship->SetOwner(Player);
    }
    
    // 6. Teleport player into hangar
    Player->GetPawn()->SetActorLocation(HangarLocation);
    
    // 7. Store hangar reference
    ActiveHangars.Add(CharacterId, Hangar);
    
    return Hangar;
}
```

### Hangar Cleanup

```cpp
// Destroy hangar when player undocks or disconnects
void AEchoesServerGameMode::DestroyHangar(const FString& CharacterId)
{
    if (AEchoesHangarInstance* Hangar = ActiveHangars.FindRef(CharacterId))
    {
        // Save ship states to database
        for (AEchoesShipPawn* Ship : Hangar->Ships)
        {
            SaveShipState(Ship);
        }
        
        // Destroy hangar actor
        Hangar->Destroy();
        ActiveHangars.Remove(CharacterId);
    }
}
```

---

## Server-to-Backend Communication

### Authentication

All server-to-backend requests use JWT token from registration:

```cpp
// Add Authorization header
FString AuthHeader = FString::Printf(TEXT("Bearer %s"), *ServerJWT);
Request->SetHeader(TEXT("Authorization"), AuthHeader);
```

### Common API Calls

#### 1. Fetch Ship Stats

```cpp
// GET /api/ship/{shipId}/stats
// Returns calculated stats with module bonuses

TSharedRef<IHttpRequest> Request = HttpModule->CreateRequest();
Request->SetVerb("GET");
Request->SetURL(FString::Printf(TEXT("%s/api/ship/%s/stats"), 
    *ApiUrl, *ShipId));
Request->SetHeader("Authorization", FString::Printf(TEXT("Bearer %s"), *ServerJWT));
Request->SetHeader("X-Server-Secret", *ServerSecret);
Request->OnProcessRequestComplete().BindUObject(
    this, &UMySubsystem::OnShipStatsReceived);
Request->ProcessRequest();
```

#### 2. Validate Module Fit

```cpp
// POST /api/ship/{shipId}/modules
// Backend validates: ownership, CPU/power requirements, slot compatibility

FString JsonPayload = FString::Printf(TEXT(R"({
    "module_id": "%s",
    "slot_index": %d,
    "slot_type": "%s"
})"), *ModuleId, SlotIndex, *SlotType);

Request->SetContentAsString(JsonPayload);
Request->SetVerb("POST");
Request->SetHeader("Content-Type", "application/json");
```

#### 3. Save Character Location

```cpp
// PUT /api/character/{characterId}/location
// Update player position in database

FString JsonPayload = FString::Printf(TEXT(R"({
    "solar_system_id": "%s",
    "station_id": "%s",
    "position_x": %.2f,
    "position_y": %.2f,
    "position_z": %.2f,
    "is_docked": %s
})"), *SystemId, *StationId, PosX, PosY, PosZ, IsDocked ? TEXT("true") : TEXT("false"));
```

### Error Handling

```cpp
void UMySubsystem::OnHttpRequestComplete(
    FHttpRequestPtr Request,
    FHttpResponsePtr Response,
    bool bWasSuccessful
)
{
    if (!bWasSuccessful || !Response.IsValid())
    {
        UE_LOG(LogEchoes, Error, TEXT("HTTP request failed: Network error"));
        return;
    }
    
    int32 ResponseCode = Response->GetResponseCode();
    if (ResponseCode == 200)
    {
        // Success - parse JSON
        FString ResponseContent = Response->GetContentAsString();
        TSharedPtr<FJsonObject> JsonObject;
        TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(ResponseContent);
        
        if (FJsonSerializer::Deserialize(Reader, JsonObject))
        {
            // Process data
        }
    }
    else if (ResponseCode == 401)
    {
        UE_LOG(LogEchoes, Error, TEXT("Unauthorized - JWT token expired"));
        // Re-register server
    }
    else if (ResponseCode == 400)
    {
        // Parse error message
        FString ErrorMsg = Response->GetContentAsString();
        UE_LOG(LogEchoes, Warning, TEXT("Bad request: %s"), *ErrorMsg);
    }
}
```

---

## Launch Scripts & Configuration

### Windows Batch Script (Launch.bat)

```batch
@echo off
SET UE_EDITOR="C:\Program Files\Epic Games\UE_5.3\Engine\Binaries\Win64\UnrealEditor.exe"
SET PROJECT="D:\Echoes\Client\Echoes\Echoes.uproject"
SET MAP="GameLevel"
SET PORT=7777
SET SERVER_TYPE="DedicatedSystem"
SET SYSTEM_ID="550e8400-e29b-41d4-a716-446655440000"
SET API_URL="https://api.echoes-imperial.com"

%UE_EDITOR% %PROJECT% %MAP% ^
    -server ^
    -log ^
    -Port=%PORT% ^
    -ServerType=%SERVER_TYPE% ^
    -SystemId=%SYSTEM_ID% ^
    -ApiUrl=%API_URL%
```

### PowerShell Script (Launch.ps1)

```powershell
param(
    [string]$ServerType = "DedicatedSystem",
    [string]$SystemId = "",
    [string]$RegionId = "",
    [int]$Port = 7777,
    [string]$ApiUrl = "https://api.echoes-imperial.com"
)

$UEEditor = "C:\Program Files\Epic Games\UE_5.3\Engine\Binaries\Win64\UnrealEditor.exe"
$Project = "D:\Echoes\Client\Echoes\Echoes.uproject"
$Map = "GameLevel"

$Arguments = @(
    $Project,
    $Map,
    "-server",
    "-log",
    "-Port=$Port",
    "-ServerType=$ServerType",
    "-ApiUrl=$ApiUrl"
)

if ($ServerType -eq "DedicatedSystem") {
    $Arguments += "-SystemId=$SystemId"
} elseif ($ServerType -eq "RegionalCluster") {
    $Arguments += "-RegionId=$RegionId"
}

& $UEEditor $Arguments
```

### Linux Shell Script (launch.sh)

```bash
#!/bin/bash

UE_EDITOR="/opt/UnrealEngine/Engine/Binaries/Linux/UnrealEditor"
PROJECT="/home/gameserver/Echoes/Echoes.uproject"
MAP="GameLevel"
PORT=7777
SERVER_TYPE="DedicatedSystem"
SYSTEM_ID="550e8400-e29b-41d4-a716-446655440000"
API_URL="https://api.echoes-imperial.com"

$UE_EDITOR $PROJECT $MAP \
    -server \
    -log \
    -Port=$PORT \
    -ServerType=$SERVER_TYPE \
    -SystemId=$SYSTEM_ID \
    -ApiUrl=$API_URL
```

---

## Performance & Optimization

### Best Practices

#### 1. Object Pooling

```cpp
// Reuse actors instead of spawning/destroying
TArray<AEchoesProjectile*> ProjectilePool;

AEchoesProjectile* GetPooledProjectile()
{
    for (AEchoesProjectile* Projectile : ProjectilePool)
    {
        if (!Projectile->IsActive())
        {
            Projectile->Reset();
            return Projectile;
        }
    }
    
    // Pool exhausted - spawn new
    AEchoesProjectile* NewProjectile = SpawnProjectile();
    ProjectilePool.Add(NewProjectile);
    return NewProjectile;
}
```

#### 2. Network Relevancy

```cpp
// Only replicate actors near players
bool AEchoesPlanet::IsNetRelevantFor(
    const AActor* RealViewer,
    const AActor* ViewTarget,
    const FVector& SrcLocation
) const
{
    // Planets always relevant (static landmarks)
    return true;
}

bool AEchoesShipPawn::IsNetRelevantFor(
    const AActor* RealViewer,
    const AActor* ViewTarget,
    const FVector& SrcLocation
) const
{
    // Only replicate ships within 100km
    return FVector::Dist(GetActorLocation(), SrcLocation) < 10000000.0;
}
```

#### 3. Conditional Replication

```cpp
// Only replicate changed properties
UPROPERTY(ReplicatedUsing = OnRep_ShipStats)
FEchoesShipStats ReplicatedShipStats;

void AEchoesShipPawn::GetLifetimeReplicatedProps(
    TArray<FLifetimeProperty>& OutLifetimeProps
) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    // Only replicate to owner (not all clients)
    DOREPLIFETIME_CONDITION(AEchoesShipPawn, ReplicatedShipStats, COND_OwnerOnly);
}
```

#### 4. Batch API Calls

```cpp
// Don't call API for every player action
// Batch updates every 5 seconds

void UEchoesLocationTracker::Tick(float DeltaTime)
{
    TimeSinceLastSync += DeltaTime;
    
    if (TimeSinceLastSync >= 5.0f)
    {
        // Batch all player location updates
        TArray<FPlayerLocationUpdate> Updates;
        for (APlayerController* PC : GetWorld()->GetPlayerControllerIterator())
        {
            Updates.Add(GetPlayerLocationUpdate(PC));
        }
        
        // Single API call with array
        SendBatchLocationUpdate(Updates);
        TimeSinceLastSync = 0.0f;
    }
}
```

#### 5. Caching

```cpp
// Cache frequently accessed data
TMap<FString, FItemTypeData> ItemTypeCache;

FItemTypeData GetItemType(const FString& TypeId)
{
    if (FItemTypeData* Cached = ItemTypeCache.Find(TypeId))
    {
        return *Cached;
    }
    
    // Not cached - fetch from API
    FItemTypeData Data = FetchItemTypeFromAPI(TypeId);
    ItemTypeCache.Add(TypeId, Data);
    return Data;
}
```

### Performance Metrics

| Metric | Target | Notes |
|--------|--------|-------|
| **Tick Rate** | 60 FPS | Server simulation rate |
| **Player Capacity** | 100 players | Per DedicatedSystem server |
| **World Generation** | < 5 seconds | 72 objects in Genesis Prime |
| **Network Bandwidth** | < 1 Mbps per player | Average |
| **Memory Usage** | < 4GB RAM | Including world |
| **API Response Time** | < 100ms | Backend calls |

---

## Troubleshooting

### Common Issues

#### Issue 1: Server Not Registering

**Symptoms:** Server starts but world doesn't generate

**Causes:**
- API URL incorrect in command line
- Backend server not running
- Network firewall blocking outbound HTTPS

**Solution:**
```cpp
// Check logs for registration error
UE_LOG(LogEchoes, Error, TEXT("Failed to register: %s"), *ErrorMsg);

// Verify command line parsing
FString ApiUrl;
if (FParse::Value(FCommandLine::Get(), TEXT("ApiUrl="), ApiUrl))
{
    UE_LOG(LogEchoes, Log, TEXT("API URL: %s"), *ApiUrl);
}
else
{
    UE_LOG(LogEchoes, Error, TEXT("No ApiUrl in command line!"));
}
```

#### Issue 2: World Generation Race Condition

**Symptoms:** Sometimes world generates, sometimes doesn't

**Cause:** WorldGenerator BeginPlay() called after config arrives

**Solution:** Check cached config
```cpp
// In WorldGenerator::BeginPlay()
if (ServerManagementSubsystem->HasCachedConfig())
{
    // Config already arrived - use it immediately
    const FServerSystemConfig& Config = ServerManagementSubsystem->GetSystemConfig();
    OnServerConfigReceived(Config);
}
```

#### Issue 3: Hangar Overlap

**Symptoms:** Players see each other's hangars

**Cause:** Insufficient hangar offset

**Solution:** Increase offset distance
```cpp
// Use 100km offset instead of 10km
FVector HangarOffset(PlayerIndex * 10000000.0, 0, 0);  // 100km in cm
```

---

## Conclusion

The Echoes of Imperial UE5 server integration provides:

✅ **Automatic server registration** with backend API  
✅ **Dynamic world generation** (72+ objects from database config)  
✅ **Personal hangar instances** (spatial isolation for docked players)  
✅ **Server-authoritative gameplay** (prevents cheating)  
✅ **RESTful API communication** (ship stats, inventory, locations)  
✅ **Scalable architecture** (DedicatedSystem or RegionalCluster)  
✅ **Performance optimization** (pooling, relevancy, caching)

**Related Documentation:**
- [ARCHITECTURE.md](ARCHITECTURE.md) - System architecture overview
- [DATABASE_SCHEMA.md](DATABASE_SCHEMA.md) - Database structure
- [API_DOCUMENTATION.md](API_DOCUMENTATION.md) - API endpoint reference
