# Rules of Engagement - Iron Rules for Echoes MMO

> **"The Constitution of Echoes Development"**  
> Non-negotiable architectural and security principles that govern all code.

---

## 1. Core Architectural Principles

### 1.1 "Postgres is Truth" - The Golden Rule

**Rule:** PostgreSQL is the **single source of truth** for all persistent game state.

```
Truth Hierarchy:
PostgreSQL (Authority) → Backend API (Calculator) → UE5 Server (Enforcer) → Clients (Display)
```

**Consequences:**
- ✅ All game state must be stored in PostgreSQL
- ✅ Backend calculates all derived values (mass, speed, bonuses)
- ✅ Server validates all operations against backend
- ❌ Clients NEVER manipulate game state directly
- ❌ No "client-side truth" - clients only display and predict

**Example:**
```cpp
// ❌ WRONG - Client deciding ship mass
void AShipPawn::ClientSide_SetMass(float NewMass)
{
    ShipMass = NewMass; // SECURITY VIOLATION!
}

// ✅ CORRECT - Server fetches from backend
void AShipPawn::Server_InitializeShip(FGuid ShipId)
{
    // Server calls backend API
    BackendAPI->GetShipStats(ShipId, [this](FShipStats Stats) {
        // Server receives authoritative data
        ApplyStatsFromBackend(Stats);
        // Stats replicated to clients automatically
    });
}
```

---

## 2. Naming Conventions

### 2.1 Function Prefixes (MANDATORY)

All UE5 functions MUST use standardized prefixes to indicate their execution context:

#### Server Authority Functions
```cpp
// Server-only RPC (called by client, runs on server)
UFUNCTION(Server, Reliable)
void Server_RequestSpawn(FGuid CharacterId);

// Server-only logic (not RPC)
void ServerOnly_CalculateDamage();
void ServerOnly_ValidateAction();
```

#### Client Functions
```cpp
// Client RPC (called by server, runs on client)
UFUNCTION(Client, Reliable)
void Client_ShowNotification(FText Message);

// Client-only logic
void ClientOnly_UpdateUI();
void ClientOnly_PlayEffects();
```

#### Multicast Functions
```cpp
// Multicast RPC (called by server, runs on all clients)
UFUNCTION(NetMulticast, Reliable)
void Multicast_PlayExplosion(FVector Location);
```

#### Common/Shared Functions
```cpp
// Shared logic (runs anywhere, no authority dependency)
float Common_CalculateDistance(FVector A, FVector B);
FVector Common_GetForwardVector();
```

### 2.2 Component Naming

**Pattern:** `Echoes{Purpose}Component` or `Echoes{Purpose}Subsystem`

```cpp
// Movement and physics
UEchoesShipMovementComponent

// Inventory management
UEchoesInventoryComponent

// Game instance subsystems
UEchoesAuthSubsystem
UEchoesInventorySubsystem
UEchoesIdentitySubsystem
```

### 2.3 Data Structure Naming

**Pattern:** `FEchoes{Type}` for structs, `UEchoes{Type}` for UObjects

```cpp
// Structs (Plain data)
USTRUCT()
struct FEchoesShipStats { ... };

USTRUCT()
struct FEchoesInventoryItem { ... };

// UObjects/Components
UCLASS()
class UEchoesShipMovementComponent : public UActorComponent { ... };
```

### 2.4 Backend Naming (.NET)

**Controllers:** `{Entity}Controller`
```csharp
public class ShipController : ControllerBase { }
public class InventoryController : ControllerBase { }
```

**Services:** `{Entity}Service` or `I{Entity}Service`
```csharp
public interface IInventoryService { }
public class InventoryService : IInventoryService { }
```

**DTOs:** `{Entity}Dto` or `{Action}{Entity}Dto`
```csharp
public class ShipStatsDto { }
public class CreateCharacterDto { }
```

---

## 3. Security Rules

### 3.1 Client Prohibition - No Database Writes

**ABSOLUTE RULE:** Clients NEVER write directly to the database.

**All data modifications must flow:**
```
Client → Server RPC → Backend API (JWT Auth) → Database
                         ↓
                    Validation & Calculation
                         ↓
                    Server Response
                         ↓
                    Server Applies Changes
                         ↓
                    Replication to Clients
```

**Example:**
```cpp
// ❌ WRONG - Client trying to modify inventory
void UInventoryComponent::Client_AddItem(int32 ItemId)
{
    // This would be a security hole!
    Items.Add(ItemId);
}

// ✅ CORRECT - Client requests, server validates
void UInventoryComponent::Server_RequestAddItem_Implementation(int32 ItemId)
{
    // Server validates with backend
    BackendAPI->ValidateItemAdd(CharacterId, ItemId, [this](bool Success) {
        if (Success) {
            // Only server modifies
            Items.Add(ItemId);
            // Replicated to clients
        }
    });
}
```

### 3.2 Authentication Requirements

**Rule:** All backend API calls MUST be authenticated.

**Authentication Methods:**
1. **JWT Bearer Tokens** - For player actions
2. **X-Server-Secret Header** - For server-to-backend calls

```cpp
// Player authentication (JWT)
Request->SetHeader("Authorization", FString::Printf(TEXT("Bearer %s"), *JWTToken));

// Server authentication (Server Secret)
Request->SetHeader("X-Server-Secret", ServerSecret);
```

### 3.3 Input Validation

**Rule:** Validate ALL inputs at EVERY layer.

**Validation Layers:**
1. **Client:** Basic UI validation (UX only, not security)
2. **Server:** Validate player actions (authority check)
3. **Backend:** Validate all inputs, check permissions
4. **Database:** Constraints and foreign keys

```csharp
// Backend validation example
public async Task<IActionResult> MoveItem(MoveItemDto request)
{
    // 1. Validate input format
    if (request.Quantity <= 0)
        return BadRequest("Invalid quantity");
    
    // 2. Validate ownership
    var item = await _db.Assets.FindAsync(request.AssetId);
    if (item.OwnerId != request.CharacterId)
        return Unauthorized("Not your item");
    
    // 3. Validate capacity
    var targetVolume = await CalculateVolumeAsync(request.TargetContainerId);
    if (targetVolume + itemVolume > targetCapacity)
        return BadRequest("Container full");
    
    // 4. Execute validated action
    await ExecuteMoveAsync(request);
    return Ok();
}
```

### 3.4 Secrets Management

**Rule:** No secrets in code. Use environment variables or secure vaults.

```csharp
// ❌ WRONG
string connectionString = "Host=localhost;Password=secret123";

// ✅ CORRECT
string connectionString = Environment.GetEnvironmentVariable("DB_CONNECTION_STRING");
```

```cpp
// ❌ WRONG
FString ServerSecret = "my-server-secret";

// ✅ CORRECT
FString ServerSecret = FPlatformMisc::GetEnvironmentVariable(TEXT("UE_SERVER_SECRET"));
```

---

## 4. Replication Rules

### 4.1 What to Replicate

**Replicate:**
- ✅ Authoritative game state (health, position, inventory)
- ✅ Visual effects that all players should see
- ✅ Player inputs (for lag compensation)

**Do NOT Replicate:**
- ❌ Temporary UI state
- ❌ Visual-only effects (particles, sounds)
- ❌ Client-side predictions

### 4.2 Replication Patterns

```cpp
// Simple replicated value
UPROPERTY(Replicated)
float CurrentHealth;

// Replicated with notification
UPROPERTY(ReplicatedUsing=OnRep_ShipStats)
FEchoesShipStats ShipStats;

UFUNCTION()
void OnRep_ShipStats()
{
    // Update visuals when stats change
    ApplyStatsToPhysics();
}

// Replicated actor component
void UMyComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(UMyComponent, CurrentHealth);
    DOREPLIFETIME_CONDITION(UMyComponent, OwnerOnly, COND_OwnerOnly);
}
```

---

## 5. Performance Rules

### 5.1 RPC Frequency Limits

**Rule:** Minimize RPC calls. Batch when possible.

```cpp
// ❌ WRONG - RPC spam (60 calls per second)
void Tick(float DeltaTime)
{
    Server_UpdatePosition(GetActorLocation());
}

// ✅ CORRECT - Throttled updates
void Tick(float DeltaTime)
{
    TimeSinceLastUpdate += DeltaTime;
    if (TimeSinceLastUpdate > 0.1f) // 10 Hz max
    {
        Server_UpdatePosition(GetActorLocation());
        TimeSinceLastUpdate = 0.0f;
    }
}

// ✅ BETTER - Batch multiple values
void Tick(float DeltaTime)
{
    TimeSinceLastUpdate += DeltaTime;
    if (TimeSinceLastUpdate > 0.1f)
    {
        FShipState State;
        State.Position = GetActorLocation();
        State.Velocity = GetVelocity();
        State.Rotation = GetActorRotation();
        Server_UpdateShipState(State); // Single RPC
        TimeSinceLastUpdate = 0.0f;
    }
}
```

### 5.2 Database Query Optimization

**Rule:** Minimize database queries. Use eager loading and caching.

```csharp
// ❌ WRONG - N+1 query problem
var characters = await _db.Characters.ToListAsync();
foreach (var character in characters)
{
    var ships = await _db.Ships.Where(s => s.OwnerId == character.Id).ToListAsync();
}

// ✅ CORRECT - Eager loading
var characters = await _db.Characters
    .Include(c => c.Ships)
    .ToListAsync();
```

---

## 6. Error Handling

### 6.1 Fail Gracefully

**Rule:** Never crash. Log errors and recover.

```cpp
// ❌ WRONG - Unhandled failure
void LoadShip(FGuid ShipId)
{
    auto Stats = BackendAPI->GetShipStats(ShipId); // What if this fails?
    ApplyStats(Stats);
}

// ✅ CORRECT - Handle errors
void LoadShip(FGuid ShipId)
{
    BackendAPI->GetShipStats(ShipId,
        [this](FShipStats Stats) {
            // Success
            ApplyStats(Stats);
        },
        [this](FString Error) {
            // Failure
            UE_LOG(LogEchoes, Error, TEXT("Failed to load ship: %s"), *Error);
            ShowErrorNotification("Failed to load ship");
            ReturnToHangar();
        }
    );
}
```

### 6.2 Logging Standards

**Levels:**
- `Error` - Critical failures requiring immediate attention
- `Warning` - Potential issues, degraded functionality
- `Display` - Important state changes
- `Verbose` - Detailed debug information

```cpp
UE_LOG(LogEchoes, Error, TEXT("Ship spawn failed: %s"), *ErrorMessage);
UE_LOG(LogEchoes, Warning, TEXT("High latency detected: %dms"), Latency);
UE_LOG(LogEchoes, Display, TEXT("Player spawned at %s"), *Location.ToString());
UE_LOG(LogEchoes, Verbose, TEXT("Inventory item added: %d"), ItemId);
```

---

## 7. Testing Requirements

### 7.1 Testing Strategy

**Required Tests:**
- ✅ Backend unit tests (business logic)
- ✅ Backend integration tests (database operations)
- ✅ API endpoint tests (authentication, validation)
- ✅ UE5 multiplayer tests (client-server interaction)

### 7.2 Test Coverage Goals

- **Backend Business Logic:** 80% coverage minimum
- **API Endpoints:** 100% coverage (all paths)
- **Critical Systems:** 100% coverage (authentication, inventory)

---

## 8. Documentation Requirements

### 8.1 Code Documentation

**Rule:** Document WHY, not WHAT.

```cpp
// ❌ WRONG - Obvious comment
// Sets the mass
void SetMass(float NewMass) { Mass = NewMass; }

// ✅ CORRECT - Explains reasoning
// Mass affects both acceleration (F=ma) and inertia tensor for rotation.
// This must be called after module changes to recalculate total mass.
void RecalculateShipMass() { ... }
```

### 8.2 Architecture Documentation

**Required Documentation:**
- System architecture diagrams
- Data flow diagrams
- API endpoint documentation
- Database schema documentation

---

## 9. Version Control Rules

### 9.1 Commit Messages

**Format:**
```
[Category] Brief description

Detailed explanation if necessary

- Related files changed
- Impact on systems
```

**Categories:** `[Feature]`, `[Fix]`, `[Refactor]`, `[Docs]`, `[Test]`, `[Security]`

### 9.2 Branch Strategy

- `main` - Production-ready code
- `feature/{name}` - New features
- `bugfix/{name}` - Bug fixes
- `hotfix/{name}` - Critical production fixes

---

## 10. Code Review Checklist

Before merging ANY code, verify:

- [ ] Follows naming conventions (Server_, Client_, Common_)
- [ ] No client-side database writes
- [ ] All inputs validated
- [ ] Proper authentication on API calls
- [ ] Error handling implemented
- [ ] Replication configured correctly
- [ ] Performance considerations addressed
- [ ] Tests written and passing
- [ ] Documentation updated
- [ ] No secrets in code

---

## Consequences of Violations

**Security Violations:**
- Immediate code rejection
- Security audit of related code
- Required fix before any other work

**Naming Convention Violations:**
- Code review rejection
- Required refactoring

**Performance Violations:**
- Profiling required
- Optimization plan required before merge

---

**This document is LAW. No exceptions without architectural review.**

---

**Last Updated:** 2026-01-31  
**Version:** 1.0  
**Status:** Enforced
