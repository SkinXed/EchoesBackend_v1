# Network Security Architecture

## Overview

This document outlines the security model for the Echoes ship movement system, designed for networked multiplayer with proper authority separation.

## Architecture Layers

```
┌─────────────────────────────────────────────────────────────┐
│                         CLIENT                              │
│  (UE5 - Player's Machine)                                   │
│                                                             │
│  - Sends input (WASD, mouse, warp commands)                │
│  - Receives replicated state from UE Server                │
│  - NEVER has X-Server-Secret                               │
│  - CANNOT directly call ASP.NET API                        │
└─────────────────┬───────────────────────────────────────────┘
                  │ RPC Calls
                  │ (Authenticated via UE's built-in auth)
                  ▼
┌─────────────────────────────────────────────────────────────┐
│                      UE SERVER                              │
│  (Unreal Engine Dedicated Server)                           │
│                                                             │
│  - Authoritative for gameplay state                         │
│  - Validates all player actions                             │
│  - Has X-Server-Secret for ASP.NET communication           │
│  - Fetches ship stats from backend                         │
│  - Replicates approved state to clients                    │
└─────────────────┬───────────────────────────────────────────┘
                  │ HTTP Requests
                  │ (With X-Server-Secret header)
                  ▼
┌─────────────────────────────────────────────────────────────┐
│                    ASP.NET BACKEND                          │
│  (PostgreSQL + ASP.NET Core)                                │
│                                                             │
│  - "Postgres is Truth" - authoritative for stats           │
│  - Validates X-Server-Secret                               │
│  - Calculates ship stats (mass, thrust, etc.)              │
│  - ONLY responds to authenticated UE Servers               │
└─────────────────────────────────────────────────────────────┘
```

## Request Flow Example: Ship Stats

### 1. Player Spawns Ship

```cpp
// CLIENT CODE (runs on player's machine)
void AMyPlayerController::SpawnMyShip()
{
    // Client sends RPC to server with ship instance ID
    ServerRPC_RequestSpawnShip(MyShipInstanceId);
}
```

### 2. Server Validates and Fetches Stats

```cpp
// SERVER CODE (runs on dedicated server)
void AMyPlayerController::ServerRPC_RequestSpawnShip_Implementation(FGuid ShipInstanceId)
{
    // Validate player owns this ship (check database/cache)
    if (!ValidateShipOwnership(GetPlayerId(), ShipInstanceId))
    {
        return; // Reject unauthorized request
    }

    // Fetch stats from backend using subsystem
    auto Subsystem = GetGameInstance()->GetSubsystem<UEchoesShipStatsSubsystem>();
    
    FOnShipStatsFetched OnSuccess;
    OnSuccess.BindLambda([this, ShipInstanceId](const FEchoesShipStats& Stats) {
        // Server received stats - spawn ship with these stats
        AEchoesShipPawn* Ship = SpawnShipActor(Stats);
        
        // Replicate ship to client
        ClientRPC_ShipSpawned(Ship);
    });
    
    FOnApiError OnError;
    OnError.BindLambda([](const FString& Error) {
        UE_LOG(LogTemp, Error, TEXT("Failed to fetch ship stats: %s"), *Error);
    });
    
    // This call includes X-Server-Secret automatically
    Subsystem->FetchShipStats(ShipInstanceId, OnSuccess, OnError);
}
```

### 3. Backend Validates Request

```csharp
// BACKEND CODE (ASP.NET Core)
[HttpGet("{id}/stats")]
public async Task<IActionResult> GetShipStats(Guid id)
{
    // Validate X-Server-Secret header
    if (!ValidateServerSecret())
    {
        return Unauthorized(new { error = "Invalid server secret" });
    }

    // Calculate and return stats
    var stats = await _fittingService.CalculateShipStatsAsync(id);
    return Ok(stats);
}
```

### 4. Server Replicates to Client

```cpp
// CLIENT CODE (receives replicated data)
void AMyPlayerController::ClientRPC_ShipSpawned_Implementation(AEchoesShipPawn* Ship)
{
    // Client receives spawned ship with stats already applied
    // Stats are replicated via OnRep_ShipStats (automatic)
    MyShip = Ship;
}
```

## Security Principles

### 1. Never Trust the Client

**❌ WRONG:**
```cpp
// CLIENT CODE - NEVER DO THIS
void AEchoesShipPawn::InitializeFromClient()
{
    // Client tries to fetch stats directly
    auto Subsystem = GetGameInstance()->GetSubsystem<UEchoesShipStatsSubsystem>();
    Subsystem->FetchShipStats(...); // Client doesn't have X-Server-Secret!
}
```

**✅ CORRECT:**
```cpp
// CLIENT CODE - Request through server
void AMyPlayerController::RequestShipStats(FGuid ShipId)
{
    ServerRPC_FetchShipStats(ShipId);
}

// SERVER CODE - Actually fetch stats
void AMyPlayerController::ServerRPC_FetchShipStats_Implementation(FGuid ShipId)
{
    // Validate request
    if (!CanAccessShip(ShipId))
        return;
    
    // Fetch with server authority
    auto Subsystem = GetGameInstance()->GetSubsystem<UEchoesShipStatsSubsystem>();
    Subsystem->FetchShipStats(ShipId, ...);
}
```

### 2. Server is Authority

All gameplay-affecting decisions happen on the server:
- Ship spawning
- Warp initiation (server validates alignment/speed)
- Module fitting/removal
- Damage calculation
- Position validation

### 3. Replication Not Prediction

For ship stats and configuration:
```cpp
UCLASS()
class AEchoesShipPawn : public APawn
{
    // Replicated from server to clients
    UPROPERTY(ReplicatedUsing=OnRep_ShipStats)
    FEchoesShipStats ShipStats;

    UFUNCTION()
    void OnRep_ShipStats()
    {
        // Apply stats when replicated from server
        if (ShipMovement)
        {
            ShipMovement->InitializeShipStats(ShipStats);
        }
    }
};
```

## Configuration Security

### Server Configuration (Secure)

**UE Server** (`DefaultGame.ini` or environment variables):
```ini
[/Script/Echoes.EchoesShipStatsSubsystem]
ApiBaseUrl=https://api.echoes.game/api
ServerSecret=production-secret-change-me-securely
```

### Client Configuration (Public)

**Client** should NOT have access to:
- `ServerSecret`
- Direct API endpoints
- Backend URLs

Client only needs:
- UE Server IP/Port (for multiplayer connection)
- Game version
- Public configuration (graphics, audio, etc.)

## API Security Best Practices

### 1. Secret Rotation

Change `ServerSecret` regularly:
```bash
# Generate new secret
openssl rand -base64 32

# Update in both:
# - appsettings.json (Backend)
# - DefaultGame.ini (UE Server)
```

### 2. Rate Limiting

Backend should rate-limit requests per server:
```csharp
services.AddRateLimiter(options =>
{
    options.AddPolicy("PerServer", httpContext =>
    {
        var serverSecret = httpContext.Request.Headers["X-Server-Secret"];
        return RateLimitPartition.GetFixedWindowLimiter(
            serverSecret,
            _ => new FixedWindowRateLimiterOptions
            {
                PermitLimit = 100,
                Window = TimeSpan.FromSeconds(1)
            });
    });
});
```

### 3. HTTPS Only (Production)

```csharp
// Backend - Enforce HTTPS
app.UseHttpsRedirection();
app.UseHsts();

// UE Server - Use HTTPS URL
ApiBaseUrl=https://api.echoes.game/api  // Not http://
```

### 4. Request Validation

```csharp
[HttpGet("{id}/stats")]
public async Task<IActionResult> GetShipStats(Guid id)
{
    // 1. Validate secret
    if (!ValidateServerSecret())
        return Unauthorized();
    
    // 2. Validate GUID format
    if (id == Guid.Empty)
        return BadRequest();
    
    // 3. Check if ship exists
    var stats = await _fittingService.CalculateShipStatsAsync(id);
    if (stats == null)
        return NotFound();
    
    // 4. Log for auditing
    _logger.LogInformation("Server {ServerId} fetched stats for ship {ShipId}",
        GetServerId(), id);
    
    return Ok(stats);
}
```

## Network Optimization

### Caching on UE Server

Server should cache ship stats to reduce backend load:

```cpp
UCLASS()
class UShipStatsCache : public UGameInstanceSubsystem
{
private:
    TMap<FGuid, FEchoesShipStats> StatsCache;
    TMap<FGuid, double> CacheTimestamps;
    
    const double CacheLifetimeSeconds = 300.0; // 5 minutes

public:
    void CacheStats(FGuid ShipId, const FEchoesShipStats& Stats)
    {
        StatsCache.Add(ShipId, Stats);
        CacheTimestamps.Add(ShipId, FPlatformTime::Seconds());
    }
    
    bool GetCachedStats(FGuid ShipId, FEchoesShipStats& OutStats)
    {
        if (!StatsCache.Contains(ShipId))
            return false;
        
        double CurrentTime = FPlatformTime::Seconds();
        double CachedTime = CacheTimestamps[ShipId];
        
        if (CurrentTime - CachedTime > CacheLifetimeSeconds)
        {
            // Cache expired
            StatsCache.Remove(ShipId);
            CacheTimestamps.Remove(ShipId);
            return false;
        }
        
        OutStats = StatsCache[ShipId];
        return true;
    }
};
```

### Batch Requests

When spawning multiple ships (e.g., system with 100 players):

```cpp
// Backend - Add batch endpoint
[HttpPost("stats/batch")]
public async Task<IActionResult> GetShipStatsBatch([FromBody] List<Guid> shipIds)
{
    if (!ValidateServerSecret())
        return Unauthorized();
    
    var results = new Dictionary<Guid, ShipStatsDto>();
    foreach (var id in shipIds)
    {
        var stats = await _fittingService.CalculateShipStatsAsync(id);
        if (stats != null)
            results[id] = stats;
    }
    
    return Ok(results);
}
```

## Monitoring and Auditing

### Server-Side Logging

```csharp
_logger.LogInformation(
    "Ship stats request: Server={ServerId}, Ship={ShipId}, Time={Time}ms",
    GetServerId(),
    shipId,
    stopwatch.ElapsedMilliseconds
);
```

### Client Detection

If client somehow gets X-Server-Secret:

```csharp
// Detect suspicious patterns
if (requestsPerMinute > 1000) // UE Server shouldn't make this many
{
    _logger.LogWarning("Suspicious activity from {Secret}", serverSecret);
    // Potentially revoke secret
}
```

## Summary

✅ **DO:**
- Keep X-Server-Secret on UE Server only
- Validate all client inputs on server
- Use HTTPS in production
- Cache frequently accessed data
- Log all backend requests
- Rotate secrets regularly

❌ **DON'T:**
- Give clients X-Server-Secret
- Allow clients to call backend directly
- Trust client-reported stats
- Skip validation on server
- Use HTTP in production
- Hardcode secrets in client builds
