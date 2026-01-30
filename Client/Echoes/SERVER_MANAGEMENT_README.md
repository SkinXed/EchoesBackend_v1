# UE5 Dedicated Server Management Subsystem

This document describes the implementation of the `UEchoesServerManagementSubsystem` for managing UE5 Dedicated Server lifecycle and synchronization with the ASP.NET Core backend.

## Overview

The Server Management Subsystem is a `UGameInstanceSubsystem` that handles the complete lifecycle of a UE5 Dedicated Server, including:

- **Server Registration (The Handshake)**: Automatic registration with backend on startup
- **Heartbeat System**: Periodic health checks and metrics reporting (every 30 seconds)
- **Universe Configuration**: Fetching and distributing solar system data from backend
- **Graceful Shutdown**: Proper unregistration when server stops

## Architecture

```
┌─────────────────────────────────────────────────────────────┐
│                   UE5 Dedicated Server                      │
│                                                             │
│  ┌────────────────────────────────────────────────────┐   │
│  │  UEchoesServerManagementSubsystem                  │   │
│  │  (UGameInstanceSubsystem)                          │   │
│  │                                                     │   │
│  │  • Runs only when NetMode == NM_DedicatedServer    │   │
│  │  • Persists across level transitions               │   │
│  │  • Communicates with ASP.NET Core backend          │   │
│  └────────────────────────────────────────────────────┘   │
│                          │                                  │
│                          ▼                                  │
│  ┌────────────────────────────────────────────────────┐   │
│  │  WorldGenerator / Other Server Systems             │   │
│  │  (Subscribes to OnServerConfigReceived)            │   │
│  └────────────────────────────────────────────────────┘   │
└─────────────────────────────────────────────────────────────┘
                          │
                          │ HTTP/JSON (X-Server-Secret)
                          ▼
┌─────────────────────────────────────────────────────────────┐
│              ASP.NET Core Backend (Source of Truth)         │
│                                                             │
│  • ServerManagementController                               │
│  • POST /api/server-management/register                     │
│  • POST /api/server-management/heartbeat                    │
│  • POST /api/server-management/config                       │
│  • DELETE /api/server-management/unregister/{instanceId}    │
└─────────────────────────────────────────────────────────────┘
```

## Files Structure

```
Client/Echoes/Source/Echoes/Core/Server/
├── EchoesServerDiscoveryTypes.h          # Mirror DTOs (C# -> UE5)
├── EchoesServerManagementSubsystem.h     # Subsystem header
└── EchoesServerManagementSubsystem.cpp   # Implementation

Client/Echoes/Config/
└── DefaultGame.ini                        # Configuration
```

## Data Structures

All structures in `EchoesServerDiscoveryTypes.h` mirror their C# counterparts from the backend:

### Server Registration
- `FRegisterServerRequest` ↔ `RegisterServerRequestDto`
- `FRegisterServerResponse` ↔ `RegisterServerResponseDto`

### Heartbeat
- `FHeartbeatRequest` ↔ `HeartbeatRequestDto`
- `FHeartbeatResponse` ↔ `HeartbeatResponseDto`

### Universe Configuration
- `FServerSystemConfig` ↔ `ServerSystemConfigDto`
- `FPlanetConfig` ↔ `PlanetConfigDto`
- `FStargateConfig` ↔ `StargateConfigDto`
- `FStationConfig` ↔ `StationConfigDto`
- `FAsteroidBeltConfig` ↔ `AsteroidBeltConfigDto`
- `FAnomalyConfig` ↔ `AnomalyConfigDto`
- `FWormholeConfig` ↔ `WormholeConfigDto`
- And more...

## Configuration

Edit `Client/Echoes/Config/DefaultGame.ini`:

```ini
[/Script/Echoes.EchoesServerManagementSubsystem]
; Backend API URL - Configure this to point to your ASP.NET Core backend
BackendURL=http://localhost:5000

; Server authentication secret - REQUIRED: Must match the X-Server-Secret expected by the backend
; WARNING: Do not use default values in production! Configure a strong secret key.
ServerSecret=your-production-secret-here
```

### Command Line Parameters

The server can accept additional parameters:

```bash
# Start server with specific solar system
UEServer.exe -SystemId=550e8400-e29b-41d4-a716-446655440000 -Port=7777

# Parameters:
# -SystemId=<GUID>  : Solar system this server hosts
# -Port=<number>    : Game port for client connections
```

## Lifecycle Flow

### 1. Server Startup (Initialize)

```cpp
void UEchoesServerManagementSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    // 1. Check if running as dedicated server
    // 2. Generate unique InstanceId (GUID)
    // 3. Parse command line parameters (SystemId, Port)
    // 4. Call ServerOnly_Register()
}
```

### 2. Registration (The Handshake)

```cpp
void ServerOnly_Register(
    const FString& InstanceId,
    int32 GamePort,
    const FGuid& SolarSystemId)
{
    // 1. Validate ServerSecret is configured
    // 2. Create FRegisterServerRequest
    // 3. POST /api/server-management/register
    // 4. Receive FRegisterServerResponse with ServerId
    // 5. Start heartbeat timer
    // 6. Request universe configuration
}
```

**Request:**
```json
{
  "instanceId": "550e8400-e29b-41d4-a716-446655440000",
  "publicIP": "127.0.0.1",
  "gamePort": 7777,
  "webPort": 7778,
  "solarSystemId": "123e4567-e89b-12d3-a456-426614174000",
  "maxPlayers": 100,
  "gameVersion": "1.0.0",
  "hostname": "SERVER01"
}
```

**Response:**
```json
{
  "success": true,
  "serverId": "789e0123-e89b-12d3-a456-426614174111",
  "instanceId": "550e8400-e29b-41d4-a716-446655440000",
  "nodeType": "DedicatedSystem",
  "message": "Server registered successfully"
}
```

### 3. Heartbeat Loop

Runs every 30 seconds:

```cpp
void ServerOnly_Heartbeat()
{
    // 1. Collect server metrics:
    //    - CPU usage (placeholder, returns 0)
    //    - Memory usage (FPlatformMemory)
    //    - Player count (GetNumPlayers())
    // 2. Create FHeartbeatRequest
    // 3. POST /api/server-management/heartbeat
    // 4. If 404 (server not found), trigger re-registration
}
```

**Request:**
```json
{
  "instanceId": "550e8400-e29b-41d4-a716-446655440000",
  "status": 1,
  "onlinePlayers": 42,
  "cpuUsage": 0.0,
  "memoryUsageMB": 2048,
  "networkInKbps": 0.0,
  "networkOutKbps": 0.0
}
```

### 4. Universe Configuration

```cpp
void ServerOnly_GetConfig()
{
    // 1. Create FServerConfigRequest
    // 2. POST /api/server-management/config
    // 3. Receive FServerSystemConfig
    // 4. Broadcast OnServerConfigReceived delegate
}
```

**Request:**
```json
{
  "instanceId": "550e8400-e29b-41d4-a716-446655440000",
  "serverType": "DedicatedSystem",
  "solarSystemId": "123e4567-e89b-12d3-a456-426614174000"
}
```

**Response:**
```json
{
  "config": {
    "systemId": "123e4567-e89b-12d3-a456-426614174000",
    "systemName": "Jita",
    "planets": [...],
    "stargates": [...],
    "stations": [...],
    "anomalies": [...],
    "wormholes": [...]
  }
}
```

### 5. Graceful Shutdown (Deinitialize)

```cpp
void UEchoesServerManagementSubsystem::Deinitialize()
{
    // 1. Stop heartbeat timer
    // 2. Call ServerOnly_Unregister()
    // 3. DELETE /api/server-management/unregister/{instanceId}
    // 4. Clear state
}
```

## Security

### Authentication
All requests include the `X-Server-Secret` header:

```cpp
TSharedRef<IHttpRequest> CreateAuthenticatedRequest(
    const FString& Verb,
    const FString& Endpoint)
{
    HttpRequest->SetHeader(TEXT("X-Server-Secret"), GetServerSecret());
}
```

### Configuration Validation
- Server will refuse to start if `ServerSecret` is not configured
- No insecure defaults in production
- Clear error messages in logs

## Usage for Other Systems

### WorldGenerator Example

```cpp
// In your WorldGenerator class
void AWorldGenerator::BeginPlay()
{
    Super::BeginPlay();
    
    // Get server management subsystem
    UGameInstance* GameInstance = GetGameInstance();
    UEchoesServerManagementSubsystem* ServerSubsystem = 
        GameInstance->GetSubsystem<UEchoesServerManagementSubsystem>();
    
    if (ServerSubsystem)
    {
        // Subscribe to configuration events
        ServerSubsystem->OnServerConfigReceived.AddDynamic(
            this, 
            &AWorldGenerator::OnConfigReceived
        );
    }
}

void AWorldGenerator::OnConfigReceived(const FServerSystemConfig& Config)
{
    // Spawn planets
    for (const FPlanetConfig& Planet : Config.Planets)
    {
        SpawnPlanet(Planet);
    }
    
    // Spawn stargates
    for (const FStargateConfig& Gate : Config.Stargates)
    {
        SpawnStargate(Gate);
    }
    
    // ... etc
}
```

## Logging

Custom log category `LogEchoesServer` is used throughout:

```
LogEchoesServer: EchoesServerManagementSubsystem initialized
LogEchoesServer: Starting server registration handshake...
LogEchoesServer:   InstanceId: 550e8400-e29b-41d4-a716-446655440000
LogEchoesServer:   GamePort: 7777
LogEchoesServer: ✓ SERVER REGISTRATION SUCCESSFUL
LogEchoesServer:   ServerId: 789e0123-e89b-12d3-a456-426614174111
LogEchoesServer:   NodeType: DedicatedSystem
LogEchoesServer: Heartbeat timer started (30 second interval)
LogEchoesServer: ✓ UNIVERSE CONFIGURATION RECEIVED
LogEchoesServer:   System: Jita
LogEchoesServer:   Planets: 8
LogEchoesServer:   Stargates: 4
```

## Known Limitations & TODOs

1. **Public IP Detection**: Currently uses `127.0.0.1`. Need to implement:
   - Query external service (e.g., ipify.org)
   - Or use UPnP for local network discovery
   - Or accept IP as command line parameter

2. **CPU Usage Monitoring**: Returns 0 (unknown). Need platform-specific implementation:
   - Windows: Use Performance Counters or `GetSystemTimes()`
   - Linux: Parse `/proc/stat`
   - Consider using UE5 profiling APIs

3. **WebPort Configuration**: Currently `GamePort + 1`. Should be independently configurable.

4. **Async Shutdown**: Unregister is async, may not complete before process exit. Consider synchronous shutdown.

5. **Retry Logic**: No automatic retry for registration failures. Should implement exponential backoff.

## Testing

### Manual Testing

1. Configure backend URL and server secret in `DefaultGame.ini`
2. Start backend server
3. Launch UE5 dedicated server:
   ```bash
   UEServer.exe -log -SystemId=<GUID> -Port=7777
   ```
4. Check logs for registration success
5. Verify heartbeat in backend logs (every 30 seconds)
6. Check backend API `/api/server-management/list` for registered server

### Integration Testing

Test the complete flow:
1. Server registration → Check backend database
2. Heartbeat → Verify metrics are updated
3. Config fetch → Verify WorldGenerator spawns objects
4. Graceful shutdown → Verify server unregistered

## Dependencies

- **Modules** (already in Echoes.Build.cs):
  - `HTTP` - HTTP requests
  - `Json` - JSON parsing
  - `JsonUtilities` - JSON serialization/deserialization

- **Backend APIs**:
  - `ServerManagementController` - All endpoints must be implemented

## References

- Backend Controller: `Controllers/Management/ServerManagementController.cs`
- Backend DTOs: `Models/DTOs/Server/`
- Problem Statement: Master Prompt for UE5 Server Management & Handshake Implementation
