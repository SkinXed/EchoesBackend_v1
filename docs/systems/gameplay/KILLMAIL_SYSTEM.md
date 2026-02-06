# Killmail System Implementation

## Overview

The Killmail system tracks player deaths in the EVE-like MMO by establishing a direct communication channel between the UE5 game server and the ASP.NET Core backend. When a player is destroyed in combat, the game server reports the kill to the backend, which logs it for statistics, leaderboards, and future features like bounties and insurance.

## Architecture

This implementation follows the **Mirror Architecture** principle:
- **UE5 Client/Server**: `UCombatServerSubsystem` (WorldSubsystem)
- **ASP.NET Core Backend**: `CombatController` (API Controller)

Every subsystem in UE5 has a corresponding controller in ASP.NET Core, maintaining architectural consistency across the codebase.

## Components

### 1. ASP.NET Core Backend

#### File: `Controllers/CombatController.cs`

**Purpose**: Receive and validate killmail data from game servers.

**Endpoint**: `POST /api/combat/killmail`

**Security**: 
- Requires `X-Server-Secret` header for authentication
- Returns `401 Unauthorized` if header is missing or invalid
- Returns `200 OK` if killmail is successfully recorded

**DTO**: `KillmailRequest`
```csharp
public class KillmailRequest
{
    public int VictimId { get; set; }      // Killed player's character ID
    public int KillerId { get; set; }      // Attacker's character ID
    public int SolarSystemId { get; set; } // Location of kill
    public string ShipType { get; set; }   // Type of destroyed ship
}
```

**Configuration**:
- The server secret is read from `appsettings.json` under key `"ServerSecret"`
- Default fallback value: `"MySuperSecretKey"`
- **Important**: Change this secret in production!

#### Example Request:

```http
POST /api/combat/killmail HTTP/1.1
Host: localhost:5116
Content-Type: application/json
X-Server-Secret: MySuperSecretKey

{
  "victimId": 12345,
  "killerId": 67890,
  "solarSystemId": 1001,
  "shipType": "Frigate"
}
```

#### Example Responses:

**Success (200 OK)**:
```json
{
  "success": true,
  "message": "Killmail recorded successfully",
  "killmailId": "550e8400-e29b-41d4-a716-446655440000",
  "timestamp": "2026-02-06T18:52:43.406Z"
}
```

**Unauthorized (401)**:
```json
{
  "message": "Invalid server secret"
}
```

### 2. UE5 Client/Server

#### Files:
- `Source/Echoes/Core/Server/CombatServerSubsystem.h`
- `Source/Echoes/Core/Server/CombatServerSubsystem.cpp`

**Purpose**: Send killmail data to backend when players are destroyed.

**Class**: `UCombatServerSubsystem : public UWorldSubsystem`

**Key Function**:
```cpp
void ServerOnly_ReportKill(
    int32 VictimID,
    int32 KillerID,
    int32 SolarSystemID,
    const FString& ShipType);
```

**Workflow**:
1. Game server detects player death
2. Collects victim ID, killer ID, solar system ID, and ship type
3. Creates JSON payload with matching field names
4. Sends HTTP POST to `/api/combat/killmail`
5. Includes `X-Server-Secret` header for authentication
6. Logs response from backend

**Configuration** (DefaultGame.ini):
```ini
[/Script/Echoes.CombatServerSubsystem]
BackendURL=http://localhost:5116
ServerSecret=MySuperSecretKey
KillmailEndpoint=/api/combat/killmail
```

#### Example Usage:

```cpp
// Get subsystem from world
UWorld* World = GetWorld();
UCombatServerSubsystem* CombatSubsystem = 
    World->GetSubsystem<UCombatServerSubsystem>();

// Report a kill
if (CombatSubsystem)
{
    CombatSubsystem->ServerOnly_ReportKill(
        12345,              // Victim ID
        67890,              // Killer ID
        1001,               // Solar System ID
        TEXT("Frigate")     // Ship Type
    );
}
```

## Data Flow

```
┌─────────────────────────────────────────────────────────────┐
│                     UE5 Dedicated Server                    │
│                                                             │
│  ┌──────────────────────────────────────────────────────┐  │
│  │         Player Death Event Triggered                 │  │
│  │  • Victim destroyed in combat                        │  │
│  │  • Killer identified                                 │  │
│  │  • Location captured                                 │  │
│  └────────────────────┬─────────────────────────────────┘  │
│                       │                                     │
│                       ▼                                     │
│  ┌──────────────────────────────────────────────────────┐  │
│  │     UCombatServerSubsystem::ServerOnly_ReportKill    │  │
│  │                                                       │  │
│  │  1. Build JSON:                                      │  │
│  │     {                                                │  │
│  │       "victimId": 12345,                            │  │
│  │       "killerId": 67890,                            │  │
│  │       "solarSystemId": 1001,                        │  │
│  │       "shipType": "Frigate"                         │  │
│  │     }                                                │  │
│  │                                                       │  │
│  │  2. Add X-Server-Secret header                       │  │
│  │  3. POST to /api/combat/killmail                     │  │
│  └────────────────────┬─────────────────────────────────┘  │
└────────────────────────┼──────────────────────────────────┘
                         │
                         │ HTTP POST
                         │
                         ▼
┌─────────────────────────────────────────────────────────────┐
│                 ASP.NET Core Backend                        │
│                                                             │
│  ┌──────────────────────────────────────────────────────┐  │
│  │        CombatController::ReportKill                  │  │
│  │                                                       │  │
│  │  1. Validate X-Server-Secret header                  │  │
│  │     ├─ Missing/Invalid → 401 Unauthorized            │  │
│  │     └─ Valid → Continue                              │  │
│  │                                                       │  │
│  │  2. Deserialize KillmailRequest DTO                  │  │
│  │                                                       │  │
│  │  3. Log killmail data                                │  │
│  │                                                       │  │
│  │  4. TODO: Store in database                          │  │
│  │  5. TODO: Broadcast to clients                       │  │
│  │  6. TODO: Update statistics                          │  │
│  │                                                       │  │
│  │  7. Return 200 OK with confirmation                  │  │
│  └────────────────────┬─────────────────────────────────┘  │
└────────────────────────┼──────────────────────────────────┘
                         │
                         │ HTTP 200 OK
                         │
                         ▼
┌─────────────────────────────────────────────────────────────┐
│                     UE5 Dedicated Server                    │
│                                                             │
│  ┌──────────────────────────────────────────────────────┐  │
│  │   UCombatServerSubsystem::OnKillmailResponseReceived │  │
│  │                                                       │  │
│  │  • Log success/failure                               │  │
│  │  • Handle errors (401, 500, etc.)                    │  │
│  │  • Continue game operation                           │  │
│  └──────────────────────────────────────────────────────┘  │
└─────────────────────────────────────────────────────────────┘
```

## Security Considerations

### 1. Server Secret Authentication

**Purpose**: Prevent unauthorized clients from sending fake killmails.

**Implementation**:
- Game servers include `X-Server-Secret` header in all requests
- Backend validates header before processing
- Secret is configured in both `appsettings.json` (backend) and `DefaultGame.ini` (UE5)

**Security Notes**:
- ⚠️ Change the default secret (`MySuperSecretKey`) in production
- Keep the secret confidential - do not commit to public repositories
- Use environment variables for production deployments
- Consider rotating the secret periodically

### 2. Server-Only Execution

**UE5 Side**:
- Functions prefixed with `ServerOnly_` to indicate server-only execution
- `IsDedicatedServer()` check prevents execution on clients
- Only game servers can report kills, not game clients

**Backend Side**:
- Validates that requests come from authenticated game servers
- Prevents players from directly calling the API to fake kills

### 3. Input Validation

**Backend**:
- All DTO fields are marked with `[Required]` attribute
- String length limits prevent oversized data
- Type validation ensures correct data types

## Field Name Mapping

**Critical**: Field names in JSON (C++) and DTO (C#) **MUST** match exactly for serialization to work.

| UE5 JSON Field      | C# DTO Property  | Type    | Description              |
|---------------------|------------------|---------|--------------------------|
| `victimId`          | `VictimId`       | int32   | Killed player's ID       |
| `killerId`          | `KillerId`       | int32   | Attacker's ID            |
| `solarSystemId`     | `SolarSystemId`  | int32   | Location of kill         |
| `shipType`          | `ShipType`       | string  | Type of destroyed ship   |

**Naming Convention**: 
- JSON uses `camelCase` (victimId, killerId)
- C# uses `PascalCase` (VictimId, KillerId)
- ASP.NET Core automatically handles the case conversion

## Configuration

### Backend (appsettings.json)

```json
{
  "ServerSecret": "MySuperSecretKey",
  "Logging": {
    "LogLevel": {
      "Default": "Information",
      "Echoes.API.Controllers.CombatController": "Debug"
    }
  }
}
```

### UE5 (DefaultGame.ini)

```ini
[/Script/Echoes.CombatServerSubsystem]
; Backend API URL
BackendURL=http://localhost:5116

; Server authentication secret (must match backend)
ServerSecret=MySuperSecretKey

; Killmail endpoint (optional, uses default if not set)
KillmailEndpoint=/api/combat/killmail
```

## Testing

### Manual Testing

1. **Start Backend**:
```bash
cd /home/runner/work/EchoesBackend_v1/EchoesBackend_v1
dotnet run
```

2. **Test Endpoint with curl**:
```bash
curl -X POST http://localhost:5116/api/combat/killmail \
  -H "Content-Type: application/json" \
  -H "X-Server-Secret: MySuperSecretKey" \
  -d '{
    "victimId": 12345,
    "killerId": 67890,
    "solarSystemId": 1001,
    "shipType": "Frigate"
  }'
```

3. **Expected Response**:
```json
{
  "success": true,
  "message": "Killmail recorded successfully",
  "killmailId": "...",
  "timestamp": "..."
}
```

4. **Test Unauthorized (Invalid Secret)**:
```bash
curl -X POST http://localhost:5116/api/combat/killmail \
  -H "Content-Type: application/json" \
  -H "X-Server-Secret: WrongSecret" \
  -d '{
    "victimId": 12345,
    "killerId": 67890,
    "solarSystemId": 1001,
    "shipType": "Frigate"
  }'
```

5. **Expected Response (401)**:
```json
{
  "message": "Invalid server secret"
}
```

### UE5 Testing

1. **In GameMode or Testing Blueprint**:
```cpp
// Get subsystem
UCombatServerSubsystem* CombatSys = GetWorld()->GetSubsystem<UCombatServerSubsystem>();

// Test killmail
CombatSys->ServerOnly_ReportKill(
    12345,              // VictimID
    67890,              // KillerID
    1001,               // SolarSystemID
    TEXT("TestFrigate") // ShipType
);
```

2. **Check UE5 Output Log**:
```
LogEchoesCombat: Reporting kill: Victim=12345, Killer=67890, System=1001, Ship=TestFrigate
LogEchoesCombat: Killmail request sent to: http://localhost:5116/api/combat/killmail
LogEchoesCombat: Killmail response: Code=200, Body={...}
LogEchoesCombat: Killmail recorded: Success=True, Message=Killmail recorded successfully
```

## Future Enhancements

### Short Term (Already TODOs in Code)
- [ ] Store killmails in database (new `Killmails` table)
- [ ] Broadcast killmails to interested clients (SignalR)
- [ ] Update player kill/death statistics
- [ ] Process bounty claims
- [ ] Handle insurance payouts

### Long Term
- [ ] Full killmail details (weapon used, damage breakdown)
- [ ] Multiple attackers (assists)
- [ ] Killmail viewing UI in web portal
- [ ] Leaderboards (most kills, most valuable kills)
- [ ] Killmail notifications (Discord, email)
- [ ] Killmail API for third-party tools

## Logging

### Backend Logs
```
info: Echoes.API.Controllers.CombatController[0]
      Killmail received: Victim=12345, Killer=67890, System=1001, Ship=Frigate
```

### UE5 Logs
```
LogEchoesCombat: Log: CombatServerSubsystem initialized. API: http://localhost:5116
LogEchoesCombat: Log: Combat reporting enabled for dedicated server
LogEchoesCombat: Log: Reporting kill: Victim=12345, Killer=67890, System=1001, Ship=Frigate
LogEchoesCombat: Log: Killmail request sent to: http://localhost:5116/api/combat/killmail
LogEchoesCombat: Log: Killmail response: Code=200, Body={...}
```

## Troubleshooting

### Issue: 401 Unauthorized

**Symptoms**: Backend returns 401, UE5 logs "Killmail request unauthorized"

**Causes**:
1. X-Server-Secret header missing
2. Secret mismatch between UE5 and backend
3. Secret not configured in appsettings.json

**Solutions**:
1. Verify `ServerSecret` in `DefaultGame.ini` matches `appsettings.json`
2. Check that header is being sent in UE5 (`CreateAuthenticatedRequest`)
3. Ensure secret is not empty or default

### Issue: Connection Failed

**Symptoms**: UE5 logs "Killmail request failed - no response"

**Causes**:
1. Backend not running
2. Wrong URL in configuration
3. Firewall blocking connection

**Solutions**:
1. Verify backend is running: `dotnet run`
2. Check `BackendURL` in `DefaultGame.ini`
3. Test with curl to verify backend is accessible

### Issue: JSON Deserialization Failed

**Symptoms**: Backend logs "Request body is required" or null values

**Causes**:
1. Field name mismatch between UE5 and C#
2. JSON serialization failed in UE5
3. Content-Type header missing

**Solutions**:
1. Verify JSON field names match DTO property names (case-insensitive)
2. Check UE5 logs for JSON serialization errors
3. Ensure Content-Type is "application/json"

## Related Documentation

- [COMBAT_SYSTEM.md](../docs/systems/gameplay/COMBAT_SYSTEM.md) - Combat mechanics and damage system
- [CORE_ARCHITECTURE_BIBLE.md](../docs/architecture/CORE_ARCHITECTURE_BIBLE.md) - Overall architecture
- [Mirror Architecture Pattern] - UE5 Subsystem ↔ ASP.NET Controller mapping

## Authors

- Senior Full-Stack Game Developer (UE5 C++ & ASP.NET Core)
- Implementation Date: 2026-02-06

---

**Status**: ✅ Implemented  
**Priority**: High  
**Milestone**: Combat System - Milestone 3
