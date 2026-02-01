# Architecture Documentation

This directory contains technical architecture documentation for the Echoes UE5 client.

---

## 📚 Available Documentation

- **[Architectural Improvements](ARCHITECTURAL_IMPROVEMENTS.md)** - System architecture and design patterns
- **[Network Security](NETWORK_SECURITY.md)** - Security implementation and best practices
- **[Server Management](SERVER_MANAGEMENT_README.md)** - Dedicated server setup and management

---

## 🏛️ Core Principles

### 1. "Postgres is Truth"

The PostgreSQL database is the single source of truth for all game state.

```
Client → Display only
Server → Validate and replicate
Backend API → Calculate and persist
PostgreSQL → Single source of truth
```

### 2. Function Naming Convention

All functions must use one of these prefixes:

- **`Server_`** - Server-authoritative functions (run on server, replicate to clients)
- **`Client_`** - Client-only functions (visual feedback, UI)
- **`Common_`** - Shared utility functions (both client and server)

**Example:**
```cpp
// Server validates spawn request
UFUNCTION(Server, Reliable, WithValidation)
void Server_RequestSpawn(FVector Location);

// Client shows notification
UFUNCTION(Client, Reliable)
void Client_ShowNotification(const FString& Message);

// Common utility
UFUNCTION(BlueprintCallable)
float Common_CalculateDistance(FVector A, FVector B);
```

### 3. Mirror Architecture

Each backend API controller has a corresponding UE5 subsystem:

| Backend Controller | UE5 Subsystem | Purpose |
|--------------------|---------------|---------|
| `AuthController.cs` | `UEchoesAuthSubsystem` | Authentication |
| `CharacterController.cs` | `UEchoesIdentitySubsystem` | Character management |
| `InventoryController.cs` | `UEchoesInventorySubsystem` | Inventory operations |
| `ShipController.cs` | `UEchoesShipStatsSubsystem` | Ship stats |

### 4. Client-Server Model

Clear separation of responsibilities:

**Server Responsibilities:**
- Authority on game state
- Validation of all actions
- Persistent state management
- Anti-cheat enforcement

**Client Responsibilities:**
- Input handling
- Prediction (for responsiveness)
- Visual feedback
- UI/UX

---

## 🔐 Security

### Key Security Principles

1. **Never trust client data** - Always validate on server
2. **No secrets in code** - Use environment variables
3. **JWT authentication** - All API calls require valid token
4. **Server authority** - Server has final say on all gameplay
5. **Input validation** - Validate at every layer

See [Network Security](NETWORK_SECURITY.md) for details.

---

## 🌐 Network Architecture

### HTTP API Communication

All subsystems communicate with backend via HTTP REST API:

```
UE5 Client
   ↓
Subsystem (e.g., UEchoesInventorySubsystem)
   ↓
HTTP Request with JWT token
   ↓
ASP.NET Core Backend API
   ↓
PostgreSQL Database
```

### Multiplayer Replication

For real-time multiplayer, UE5's built-in replication is used:

```
Client A → Server → Client B
            ↓
         Backend API (for persistence)
            ↓
         PostgreSQL
```

---

## 📂 Code Organization

### Directory Structure

```
Source/Echoes/
├── Core/
│   ├── Common/         # Shared client/server code
│   │   ├── Actors/     # Game actors (Planet, Stargate, etc.)
│   │   ├── Components/ # Reusable components
│   │   ├── Interfaces/ # Abstract interfaces
│   │   ├── Networking/ # Subsystems (Auth, Inventory, etc.)
│   │   ├── Types/      # Data structures, enums
│   │   └── World/      # World generation
│   │
│   ├── Server/         # Server-only code
│   │   ├── GameModes/  # Server game modes
│   │   ├── Managers/   # Server managers
│   │   └── Validation/ # Anti-cheat validation
│   │
│   └── Client/         # Client-only code
│       ├── Pawns/      # Player pawns
│       ├── Controllers/# Player controllers
│       └── Visuals/    # Visual effects
│
└── UI/                 # User interface
    ├── Widgets/        # UMG widgets
    ├── Framework/      # Base classes
    └── Logic/          # UI logic
```

### Component Responsibilities

**Common Components** (shared):
- `UEchoesInventoryComponent` - Inventory logic
- `UEchoesShipMovementComponent` - Physics movement
- `IEchoesInteractableInterface` - Interaction interface

**Server-Only**:
- `AEchoesServerGameMode` - Server game mode
- `UServerManagementSubsystem` - Server lifecycle
- Validation logic

**Client-Only**:
- `AEchoesShipPawn` - Player ship visualization
- `AEchoesPlayerController` - Input handling
- Visual effects (Niagara)

---

## 🛠️ Development Patterns

### Subsystem Pattern

All network-connected systems use `UGameInstanceSubsystem`:

```cpp
UCLASS()
class UEchoesMySubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()
    
public:
    // Initialize subsystem
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    
    // HTTP API call
    void RequestData();
    
private:
    // HTTP response handler
    void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);
};
```

**Benefits:**
- Persists across level transitions
- Accessible from anywhere via `GetGameInstance()->GetSubsystem<T>()`
- Automatic lifecycle management

### Component Pattern

Reusable game logic uses `UActorComponent`:

```cpp
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UEchoesMyComponent : public UActorComponent
{
    GENERATED_BODY()
    
public:
    // Replicated property
    UPROPERTY(Replicated)
    float Value;
    
    // Replication setup
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
```

---

## 📊 Performance Considerations

### Network Optimization

1. **Minimize RPC calls** - Batch updates when possible
2. **Use relevancy** - Only replicate to relevant clients
3. **Throttle updates** - Don't replicate every frame
4. **Compress data** - Use efficient data structures

### Memory Management

1. **Object pooling** - Reuse frequently spawned actors
2. **Garbage collection** - Proper UPROPERTY() usage
3. **Texture streaming** - Use UE5's texture streaming
4. **LOD systems** - Use level of detail for distant objects

---

## 🔄 State Management

### Game State Flow

```
Login → Character Select → World Load → Gameplay
  ↓           ↓                ↓           ↓
Auth      Character      Spawn Player   Game Loop
Token       Data          Position       Updates
```

### Persistent State

Stored in PostgreSQL via backend API:
- Character data
- Inventory contents
- Ship fittings
- Wallet balance
- Skills

### Session State

Stored in UE5 subsystems (cleared on logout):
- JWT token
- Current character ID
- Cached API responses
- UI state

---

## 📖 Related Documentation

- [Network Security](NETWORK_SECURITY.md) - Security details
- [Server Management](SERVER_MANAGEMENT_README.md) - Server setup
- [Complete Inventory System](../systems/COMPLETE_INVENTORY_SYSTEM_SUMMARY.md) - Example system

---

**Last Updated**: 2026-02-01
