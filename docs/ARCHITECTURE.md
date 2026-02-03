# Echoes of Imperial - System Architecture

> **4-Layer Architecture Documentation**  
> Complete system design from PostgreSQL to Unreal Engine 5 clients

**Version:** 2.0  
**Last Updated:** 2026-02-03  
**Status:** Production Ready

---

## Table of Contents

1. [Architecture Overview](#architecture-overview)
2. [Layer 1: PostgreSQL Database](#layer-1-postgresql-database)
3. [Layer 2: ASP.NET Core API](#layer-2-aspnet-core-api)
4. [Layer 3: Unreal Engine 5 Server](#layer-3-unreal-engine-5-server)
5. [Layer 4: Client Applications](#layer-4-client-applications)
6. [Core Principles](#core-principles)
7. [Data Flow Examples](#data-flow-examples)

---

## Architecture Overview

### The Four-Layer Stack

```
┌─────────────────────────────────────────────────────────┐
│  Layer 4: CLIENT APPLICATIONS                           │
│  ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━  │
│  • Blazor WebAssembly (Web Dashboard)                   │
│  • Unreal Engine 5 Game Clients (3D Gameplay)           │
│  • Display only - no game logic                         │
└─────────────────────────────────────────────────────────┘
                         ▲
                         │ HTTPS/REST API + WebSocket
                         │ JWT Authentication
                         ▼
┌─────────────────────────────────────────────────────────┐
│  Layer 3: UNREAL ENGINE 5 SERVER                        │
│  ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━  │
│  • Server-authoritative gameplay                        │
│  • Physics simulation & collision                       │
│  • Player action validation                             │
│  • Network replication to clients                       │
└─────────────────────────────────────────────────────────┘
                         ▲
                         │ REST API (HTTPS)
                         │ JWT Server Token
                         ▼
┌─────────────────────────────────────────────────────────┐
│  Layer 2: ASP.NET CORE API (.NET 8)                     │
│  ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━  │
│  • Business logic & calculations                        │
│  • JWT authentication & authorization                   │
│  • RESTful API endpoints                                │
│  • Entity Framework Core ORM                            │
└─────────────────────────────────────────────────────────┘
                         ▲
                         │ SQL/TCP
                         │ Connection Pooling
                         ▼
┌─────────────────────────────────────────────────────────┐
│  Layer 1: POSTGRESQL DATABASE                           │
│  ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━  │
│  • Single Source of Truth                               │
│  • ACID transactions                                    │
│  • All persistent game state                            │
│  • 50+ tables (characters, universe, inventory)         │
└─────────────────────────────────────────────────────────┘
```

---

## Layer 1: PostgreSQL Database

### Purpose
**The Single Source of Truth** - All persistent game state lives here.

### Key Characteristics
- **ACID Compliance**: All transactions are atomic, consistent, isolated, durable
- **Relational Model**: Foreign keys enforce data integrity
- **50+ Tables**: Complete game world data structure
- **Connection Pooling**: High-performance multi-client access

### Core Table Groups

#### 1. Character & Account System
```sql
accounts              -- User login credentials
├── characters        -- Player pilots (1:many with accounts)
│   ├── character_locations      -- Position in space
│   ├── character_skills         -- Skill training
│   ├── character_wallets        -- Currency balances
│   └── wallet_transactions      -- Financial history
└── account_sessions  -- JWT refresh tokens
```

#### 2. Universe Generation
```sql
regions               -- Top-level universe structure
├── constellations    -- Group of solar systems
│   └── solar_systems -- Individual star systems
│       ├── planets   -- Celestial bodies
│       │   └── moons -- Planet satellites
│       ├── stations  -- Docking locations
│       ├── stargates -- System connections
│       ├── asteroid_belts
│       ├── anomalies
│       └── wormholes
```

#### 3. Inventory & Items
```sql
item_categories       -- Top-level (Ships, Modules, etc.)
├── item_groups       -- Sub-categories
│   └── item_types_inventory -- Specific items
│       ├── ships           -- Ship hulls
│       ├── modules         -- Ship equipment
│       └── assets          -- Player-owned items
```

#### 4. Economy & Trading
```sql
shop_items            -- Marketplace catalog
├── player_inventory_items  -- Web purchase queue
└── wallet_transactions     -- All ISK transfers
```

### The "GUID as String" Principle

**Problem:** Unreal Engine 5 and C# serialize GUIDs differently.
- **C#**: `xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx` (lowercase, with hyphens)
- **UE5**: `XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX` (uppercase, no hyphens)

**Solution:** All API communication uses GUID as STRING format.

```csharp
// API Layer (C#)
public class CharacterDataDto
{
    public string Id { get; set; }  // ✅ STRING, not Guid
}

// Database Layer (C#)
public class Character
{
    public Guid Id { get; set; }  // ✅ Guid for DB efficiency
}

// Mapping Layer
var dto = new CharacterDataDto 
{ 
    Id = character.Id.ToString()  // ✅ Convert to string
};
```

```cpp
// UE5 Layer (C++)
USTRUCT(BlueprintType)
struct FEchoesCharacter
{
    UPROPERTY(BlueprintReadWrite)
    FString CharacterId;  // ✅ FString, not FGuid
};
```

**Benefits:**
- ✅ No deserialization mismatches
- ✅ Works across all platforms
- ✅ Human-readable in logs
- ✅ Copy-paste friendly for debugging

---

## Layer 2: ASP.NET Core API

### Purpose
**Business Logic Hub** - Calculates, validates, and orchestrates all game operations.

### Key Components

#### 1. Controllers (API Endpoints)
```
/api/auth              - Login, registration, JWT tokens
/api/character         - Character data, stats, location
/api/pilot             - Pilot-specific operations
/api/universe          - Universe data (systems, planets, stations)
/api/shop              - Marketplace (buy items, manage catalog)
/api/inventory         - Character inventory management
/api/ship              - Ship fitting and stats
/api/news              - News/edict system
/api/wiki              - Knowledge base
/api/gameserver        - UE5 server registration
```

#### 2. Authorization Layers
```csharp
[AllowAnonymous]                // Public access
[Authorize]                     // Requires JWT token
[Authorize(Roles = "Admin")]    // Admin-only operations
[Authorize(Roles = "GameServer")] // UE5 server-only
```

#### 3. Entity Framework Core
- **ORM**: Object-Relational Mapping for database access
- **Migrations**: Version-controlled schema changes
- **LINQ**: Type-safe SQL queries in C#
- **Change Tracking**: Automatic dirty detection

#### 4. JWT Authentication
```
Flow:
1. Client sends username/password
2. API validates credentials
3. API generates JWT token with claims (user_id, role)
4. Client includes token in Authorization header
5. API validates token on each request
```

**Token Structure:**
```json
{
  "sub": "character-guid-here",
  "email": "pilot@echoes.com",
  "role": "Admin",
  "exp": 1738627200
}
```

### Calculation Examples

#### Ship Stats Calculation
```csharp
[HttpGet("ship/stats/{shipId}")]
public async Task<ShipStatsDto> GetShipStats(Guid shipId)
{
    // 1. Load ship from database
    var ship = await _context.Ships
        .Include(s => s.FittedModules)
        .FirstOrDefaultAsync(s => s.Id == shipId);
    
    // 2. Calculate base stats
    var baseStats = GetBaseStats(ship.TypeId);
    
    // 3. Apply module bonuses
    foreach (var module in ship.FittedModules)
    {
        baseStats.ApplyModuleBonus(module);
    }
    
    // 4. Apply character skills
    var character = await GetCharacterForShip(shipId);
    baseStats.ApplySkillBonuses(character.Skills);
    
    // 5. Return calculated result
    return baseStats.ToDto();
}
```

### Database Transaction Example
```csharp
[HttpPost("shop/purchase/{itemId}")]
public async Task<IActionResult> PurchaseItem(Guid itemId)
{
    using var transaction = await _context.Database.BeginTransactionAsync();
    try
    {
        // 1. Deduct wallet balance
        character.WalletBalance -= item.Price;
        
        // 2. Create inventory item
        await _context.PlayerInventoryItems.AddAsync(newItem);
        
        // 3. Log transaction
        await _context.WalletTransactions.AddAsync(log);
        
        // 4. Commit all changes atomically
        await _context.SaveChangesAsync();
        await transaction.CommitAsync();
        
        return Ok();
    }
    catch
    {
        await transaction.RollbackAsync();
        throw;
    }
}
```

---

## Layer 3: Unreal Engine 5 Server

### Purpose
**Authority & Physics** - Validates player actions and simulates the game world.

### Key Responsibilities

#### 1. Server Authority
- **Final Decision**: Server has authoritative say on all gameplay values
- **Validation**: Checks all player inputs before accepting
- **Anti-Cheat**: Rejects impossible actions (speed hacks, teleportation)

#### 2. Physics Simulation
```cpp
// Server-side physics (60 FPS)
void AEchoesShipPawn::Tick(float DeltaTime)
{
    if (HasAuthority())  // Only on server
    {
        // Apply thrust
        FVector Acceleration = GetForwardVector() * ThrustPower;
        Velocity += Acceleration * DeltaTime;
        
        // Apply drag
        Velocity *= (1.0f - DragCoefficient * DeltaTime);
        
        // Update position
        AddActorWorldOffset(Velocity * DeltaTime);
        
        // Replicate to clients
        ReplicatedTransform = GetActorTransform();
    }
}
```

#### 3. Network Replication
```cpp
UPROPERTY(Replicated)
FTransform ReplicatedTransform;

UPROPERTY(Replicated)
FEchoesShipStats ReplicatedShipStats;

// Server sets value → Automatically sent to clients
```

#### 4. Backend API Integration
```cpp
// Server calls backend API
UEchoesInventorySubsystem* InventorySubsystem = GetGameInstance()->GetSubsystem<UEchoesInventorySubsystem>();

// Async HTTP request
InventorySubsystem->FitModuleToShip(ShipId, ModuleId, SlotIndex,
    FOnFitModuleComplete::CreateLambda([this](bool Success, const FEchoesShipStats& NewStats)
    {
        if (Success && HasAuthority())
        {
            // Apply backend-calculated stats
            ReplicatedShipStats = NewStats;
        }
    })
);
```

### World Generation
The UE5 server generates the universe on startup:

```cpp
// AEchoesWorldGenerator::GenerateWorld()
void AEchoesWorldGenerator::GenerateWorld(const FServerSystemConfig& Config)
{
    // Example: Genesis system with 72 celestial objects
    for (const FPlanetConfig& PlanetConfig : Config.Planets)
    {
        // Spawn planet actor
        AEchoesPlanet* Planet = SpawnPlanet(PlanetConfig);
        
        // Spawn moons
        for (const FMoonConfig& MoonConfig : PlanetConfig.Moons)
        {
            AEchoesMoon* Moon = SpawnMoon(MoonConfig, Planet);
        }
    }
    
    // Spawn stations, stargates, asteroid belts...
}
```

**Key Features:**
- **Server Registration**: UE5 server registers with API on startup
- **Config Fetch**: Downloads universe generation config from API
- **Procedural Generation**: Creates all celestial objects based on config
- **Network Replication**: All objects visible to connected clients

---

## Layer 4: Client Applications

### 1. Blazor WebAssembly (Web Dashboard)

**Purpose:** Pilot management, marketplace, wiki, character profile

**Technology Stack:**
- **.NET 8 Blazor WebAssembly**
- **C# in browser** (compiled to WebAssembly)
- **Component-based UI** (Razor components)
- **JWT Authentication**

**Key Pages:**
```
/                    - Home page
/login               - Authentication
/register            - Account creation
/character/profile   - Character stats viewer
/shop                - Imperial Store
/news                - Edicts & announcements
/wiki                - Knowledge base
```

**Communication:**
```csharp
// HttpClient with JWT token
@inject HttpClient Http

protected override async Task OnInitializedAsync()
{
    // Fetch character data from API
    character = await Http.GetFromJsonAsync<CharacterDetailsDto>(
        "/api/character/profile"
    );
}
```

### 2. Unreal Engine 5 Game Client

**Purpose:** 3D space combat and exploration

**Responsibilities:**
- **Display Only**: Renders replicated data from server
- **Input Handling**: Sends player inputs to server
- **Prediction**: Locally predicts movement for responsiveness
- **Interpolation**: Smooths network updates

**Communication:**
```cpp
// Client-side RPC to server
UFUNCTION(Server, Reliable, WithValidation)
void ServerRequestFitModule(const FString& ShipId, const FString& ModuleId, int32 SlotIndex);

// Server calls backend, then replicates result
void AEchoesShipPawn::OnRep_ShipStats()
{
    // Update UI with new stats
    UpdateHUDStats(ReplicatedShipStats);
}
```

**Client Never:**
- ❌ Calculates ship stats
- ❌ Validates fitting legality
- ❌ Processes purchases
- ❌ Spawns universe objects
- ❌ Determines damage/death

**Client Only:**
- ✅ Renders 3D world
- ✅ Plays sound effects
- ✅ Shows UI elements
- ✅ Sends input to server
- ✅ Interpolates movement

---

## Core Principles

### 1. "PostgreSQL is Truth"

**Rule:** The database is the authoritative source for all persistent state.

**Implications:**
- All game-affecting decisions stored in DB
- Backend reads DB to calculate results
- UE5 server reads DB to spawn universe
- Clients display DB-derived data

**Example:**
```
Player fits module to ship:
1. Client → Server RPC (untrusted input)
2. Server → Backend API /api/ship/fit-module
3. Backend → Check DB: Does player own module?
4. Backend → Check DB: Does module fit ship?
5. Backend → Calculate new ship stats
6. Backend → Save to DB: fitted_modules table
7. Backend → Return: New ship stats
8. Server → Apply stats (authoritative)
9. Server → Replicate to clients
```

### 2. "Backend Validates"

**Rule:** All business logic lives in the ASP.NET Core API.

**Why:**
- **Security**: Can't hack C# DLL on server
- **Consistency**: Same validation for web and game
- **Updates**: Change logic without UE5 recompile
- **Testing**: Unit test C# code easily

**Example:**
```csharp
// Backend validation
[HttpPost("shop/purchase/{itemId}")]
public async Task<IActionResult> PurchaseItem(Guid itemId)
{
    // Extract character from JWT
    var characterId = User.FindFirst(ClaimTypes.NameIdentifier)?.Value;
    
    // Validate: Character exists
    var character = await _context.Characters.FindAsync(Guid.Parse(characterId));
    if (character == null) return NotFound("Character not found");
    
    // Validate: Item exists and active
    var item = await _context.ShopItems.FindAsync(itemId);
    if (item == null || !item.IsActive) return NotFound("Item not available");
    
    // Validate: Sufficient funds
    if (character.WalletBalance < item.Price)
        return BadRequest(new { 
            error = "Imperial Treasury: Insufficient Funds",
            deficit = item.Price - character.WalletBalance
        });
    
    // Process purchase...
}
```

### 3. "Server is Authority"

**Rule:** The UE5 server has final say on physics and player actions.

**Why:**
- **Anti-Cheat**: Client can't fake position/health
- **Physics**: Server simulates collisions
- **Consistency**: All players see same world state

**Pattern:**
```cpp
// Server-authoritative replication
UPROPERTY(Replicated)
float Health;

void AEchoesShipPawn::TakeDamage(float Damage)
{
    if (HasAuthority())  // Only server can modify
    {
        Health -= Damage;
        
        if (Health <= 0.0f)
        {
            OnShipDestroyed();
        }
    }
}

// Clients automatically receive updated Health
```

### 4. "Clients Display"

**Rule:** Game clients are dumb terminals - they display but don't decide.

**Why:**
- **Security**: Prevents cheating
- **Performance**: Server does heavy lifting
- **Simplicity**: Clients are easier to develop

**Client Code:**
```cpp
// Client-side display only
void UEchoesHUDWidget::UpdateShipStats()
{
    // Read replicated value (read-only)
    const FEchoesShipStats& Stats = ShipPawn->GetReplicatedStats();
    
    // Update UI widgets
    SpeedText->SetText(FText::AsNumber(Stats.MaxSpeed));
    ArmorBar->SetPercent(Stats.ArmorHP / Stats.MaxArmorHP);
    
    // NEVER modify stats here - server controls them
}
```

---

## Data Flow Examples

### Example 1: Player Login

```
1. [Client] User enters credentials in Blazor login page
   ↓
2. [Blazor] POST /api/auth/login { username, password }
   ↓
3. [API] Validate credentials against accounts table
   ↓
4. [PostgreSQL] SELECT * FROM accounts WHERE username = ?
   ↓
5. [API] Generate JWT token with character_id claim
   ↓
6. [Blazor] Store token in localStorage
   ↓
7. [Blazor] Include token in Authorization header for future requests
```

### Example 2: Character Data Fetch

```
1. [Blazor] GET /api/character/profile (with JWT token)
   ↓
2. [API] Extract character_id from JWT claims
   ↓
3. [API] Query database with Entity Framework:
   var character = await _context.Characters
       .Include(c => c.CharacterLocation)
       .Include(c => c.Skills)
       .FirstOrDefaultAsync(c => c.Id == characterId);
   ↓
4. [PostgreSQL] Execute JOIN query across multiple tables
   ↓
5. [API] Map entity to DTO (convert Guid to string)
   ↓
6. [API] Return JSON response
   ↓
7. [Blazor] Deserialize and display in UI
```

### Example 3: Item Purchase

```
1. [Blazor] Click "PURCHASE" button on shop item
   ↓
2. [Blazor] POST /api/shop/purchase/{itemId} (with JWT token)
   ↓
3. [API] Extract character_id from JWT
   ↓
4. [API] Begin database transaction
   ↓
5. [PostgreSQL] Lock character and shop_item rows
   ↓
6. [API] Validate: sufficient wallet balance
   ↓
7. [API] Deduct price from wallet_balance
   ↓
8. [API] Create player_inventory_item record
   ↓
9. [API] Create wallet_transaction log entry
   ↓
10. [PostgreSQL] Commit transaction (atomic)
    ↓
11. [API] Return success with new balance
    ↓
12. [Blazor] Update UI wallet display
```

### Example 4: Ship Movement (UE5)

```
1. [UE5 Client] Player presses W key
   ↓
2. [UE5 Client] RPC to server: ServerRequestMoveForward()
   ↓
3. [UE5 Server] Validate input (is ship alive? sufficient energy?)
   ↓
4. [UE5 Server] Apply thrust force to ship physics
   ↓
5. [UE5 Server] Update replicated transform
   ↓
6. [UE5 Clients] OnRep_Transform() → Interpolate to new position
   ↓
7. [UE5 Clients] Render ship at new location
```

### Example 5: Module Fitting

```
1. [UE5 Client] Player drags module to ship slot
   ↓
2. [UE5 Client] RPC: ServerFitModule(ShipId, ModuleId, SlotIndex)
   ↓
3. [UE5 Server] Forward to backend API:
   POST /api/ship/fit-module { shipId, moduleId, slotIndex }
   ↓
4. [API] Validate:
   - Player owns ship
   - Player owns module
   - Module fits slot type
   - Ship has CPU/Power for module
   ↓
5. [PostgreSQL] Update fitted_modules table
   ↓
6. [API] Calculate new ship stats (all modules + skills)
   ↓
7. [API] Return ShipStatsDto
   ↓
8. [UE5 Server] Apply stats: ReplicatedShipStats = newStats
   ↓
9. [UE5 Clients] OnRep_ShipStats() → Update HUD display
```

---

## Technology Stack Summary

| Layer | Technology | Purpose |
|-------|-----------|---------|
| **Database** | PostgreSQL 15+ | Persistent storage |
| **Backend API** | .NET 8 / ASP.NET Core | Business logic |
| **ORM** | Entity Framework Core 8 | Database access |
| **Authentication** | JWT (JSON Web Tokens) | Secure API access |
| **Game Server** | Unreal Engine 5.3+ | Physics & authority |
| **Web Client** | Blazor WebAssembly | Dashboard UI |
| **Game Client** | Unreal Engine 5.3+ | 3D gameplay |

---

## Deployment Architecture

```
┌─────────────────────────────────────────────────────┐
│  PRODUCTION ENVIRONMENT                             │
│                                                     │
│  ┌──────────────┐                                  │
│  │  Nginx       │  ← HTTPS/TLS                     │
│  │  Reverse     │                                  │
│  │  Proxy       │                                  │
│  └──────┬───────┘                                  │
│         │                                           │
│    ┌────┴─────┬─────────────┬──────────────┐      │
│    │          │             │              │      │
│    ▼          ▼             ▼              ▼      │
│  ┌────┐   ┌────┐       ┌────┐         ┌────┐    │
│  │API │   │API │  ...  │API │         │UE5 │    │
│  │ #1 │   │ #2 │       │ #N │         │Srvr│    │
│  └─┬──┘   └─┬──┘       └─┬──┘         └─┬──┘    │
│    │        │            │              │        │
│    └────────┴────────────┴──────────────┘        │
│                    │                              │
│                    ▼                              │
│            ┌──────────────┐                       │
│            │  PostgreSQL  │                       │
│            │  Primary DB  │                       │
│            └──────────────┘                       │
│                                                   │
└───────────────────────────────────────────────────┘
```

**Key Points:**
- **Load Balancing**: Multiple API instances behind nginx
- **Database Pool**: Connection pooling for performance
- **Horizontal Scaling**: Add more API servers as needed
- **Single DB**: PostgreSQL is single source of truth

---

## Security Model

### Authentication Flow
```
1. Player registers → account + character created in DB
2. Player logs in → API validates credentials
3. API generates JWT token with claims (character_id, role)
4. JWT token sent to client (stored in localStorage/cookies)
5. Client includes token in Authorization header
6. API validates token signature on each request
7. API extracts character_id from token claims
8. API uses character_id for all operations
```

### Authorization Roles
```csharp
// Public endpoints (no auth)
[AllowAnonymous]
public IActionResult GetNews() { }

// Authenticated pilots
[Authorize]
public IActionResult GetCharacterProfile() { }

// Admin-only operations
[Authorize(Roles = "Admin")]
public IActionResult CreateNewsPost() { }

// Game server-only
[Authorize(Roles = "GameServer")]
public IActionResult RegisterServer() { }
```

### Token Structure
```json
{
  "sub": "character-guid-string",
  "email": "pilot@echoes.com",
  "role": "Pilot",
  "iat": 1738540800,
  "exp": 1738627200
}
```

---

## Conclusion

The Echoes of Imperial architecture follows a clear separation of concerns:

1. **PostgreSQL** - Truth
2. **ASP.NET Core** - Logic
3. **UE5 Server** - Authority
4. **Clients** - Display

This design provides:
- ✅ Security (server authority, validation)
- ✅ Scalability (stateless API, load balancing)
- ✅ Flexibility (update backend without client patch)
- ✅ Performance (C++ physics, database indexing)
- ✅ Maintainability (clear responsibilities)

**Next Steps:**
- See [DATABASE_SCHEMA.md](DATABASE_SCHEMA.md) for detailed table structure
- See [API_DOCUMENTATION.md](API_DOCUMENTATION.md) for endpoint reference
- See [UE5_INTEGRATION.md](UE5_INTEGRATION.md) for game server details
