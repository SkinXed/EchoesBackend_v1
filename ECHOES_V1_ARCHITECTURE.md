# ECHOES V1 ARCHITECTURE - Master Manifest

## Overview
This document provides a comprehensive view of the Echoes MMO system architecture, covering all major systems from authentication to gameplay. It serves as the definitive reference for understanding how all components integrate.

**Last Updated:** 2026-01-31  
**Status:** Production Ready (Phase 1)  
**Version:** 1.0

---

## Table of Contents
1. [Auth & Entry Pipeline](#auth--entry-pipeline)
2. [Inventory & Registry System](#inventory--registry-system)
3. [Windows UI System](#windows-ui-system)
4. [Item Actor System](#item-actor-system)
5. [Server & World Management](#server--world-management)
6. [Integration Patterns](#integration-patterns)

---

## Auth & Entry Pipeline

### Overview
Complete JWT-based authentication system with three-stage entry flow: Preload → Login → Character Select → Spawn.

### Architecture Flow

```
┌─────────────────┐
│ Client Launch   │
└────────┬────────┘
         ↓
┌─────────────────────────┐
│  W_Preload (Cold Start) │
│  - Load saved token     │
│  - Validate with API    │
└────────┬────────────────┘
         ↓
    ┌────┴────┐
    │ Valid?  │
    └─────────┘
     Yes│  No
        │   └→ ┌──────────────────┐
        │      │   W_Login        │
        │      │  - Email/Pass    │
        │      │  - Get JWT       │
        │      │  - Save Token    │
        │      └────────┬─────────┘
        │               │
        └───────────────┘
                ↓
┌──────────────────────────┐
│  W_CharacterSelect       │
│  - List characters       │
│  - Create new (race)     │
│  - Select & Enter World  │
└────────┬─────────────────┘
         ↓
┌──────────────────────────┐
│  ConnectToWorld()        │
│  - GET connect-info      │
│  - Build URL + Token     │
│  - ClientTravel          │
└────────┬─────────────────┘
         ↓
┌──────────────────────────┐
│  Server: PostLogin       │
│  - Extract Token/CharID  │
│  - Query Location (HTTP) │
│  - Use ItemTypeRegistry  │
│  - Spawn (Docked/Space)  │
└────────┬─────────────────┘
         ↓
┌──────────────────────────┐
│  OnEntryFlowComplete     │
│  - Remove entry widgets  │
│  - Switch input mode     │
│  - Game ready            │
└──────────────────────────┘
```

### Components

#### 1. Token Persistence (LocalPlayerSettings)
**File:** `Client/Echoes/Source/Echoes/Core/Common/Save/EchoesLocalPlayerSettings.h/cpp`

**Purpose:** Persistent storage for JWT tokens across game sessions

**Data Saved:**
- `SavedAuthToken` - JWT token string
- `SavedCharacterId` - Last selected character GUID
- `SavedAccountId` - Account GUID
- `TokenSavedAt` - Timestamp when saved
- `TokenExpiresAt` - Token expiration time
- `bRememberMe` - Remember me flag

**Methods:**
```cpp
static UEchoesLocalPlayerSettings* LoadSettings();
static bool SaveSettings(UEchoesLocalPlayerSettings* Settings);
bool IsTokenValid() const;
void Clear();
```

**Usage:**
```cpp
// Save token after login
UEchoesLocalPlayerSettings* Settings = UEchoesLocalPlayerSettings::LoadSettings();
Settings->SavedAuthToken = JWTToken;
Settings->TokenExpiresAt = ExpirationTime;
UEchoesLocalPlayerSettings::SaveSettings(Settings);

// Load token on cold start
UEchoesLocalPlayerSettings* Settings = UEchoesLocalPlayerSettings::LoadSettings();
if (Settings->IsTokenValid())
{
    FString Token = Settings->SavedAuthToken;
    // Validate with API
}
```

#### 2. Authentication Subsystem
**File:** `Client/Echoes/Source/Echoes/Core/Common/Networking/EchoesAuthSubsystem.h/cpp`

**Key Methods:**
```cpp
// Authentication
void Auth_Login(const FAuthRequest& Request, FOnLoginSuccess OnSuccess, FOnLoginFailure OnFailure);
void Auth_Register(const FString& Username, const FString& Email, const FString& Password, ...);
void Auth_Logout();

// Token Management
void SaveAuthToken(bool bRememberMe);
bool LoadAuthToken();
void ClearSavedToken();

// Character Operations
void CreateCharacter(const FString& CharacterName, int32 RaceId);
void FetchCharacterList();
void ConnectToWorld(const FGuid& CharacterId);

// Accessors
FString Auth_GetToken() const;
FGuid Auth_GetCharacterId() const;
TArray<FCharacterInfo> Auth_GetCharacters() const;
```

**Delegates:**
```cpp
FOnCharacterCreated OnCharacterCreated;
FOnCharacterCreationFailed OnCharacterCreationFailed;
FOnConnectInfoReceived OnConnectInfoReceived;
FOnConnectInfoFailed OnConnectInfoFailed;
```

#### 3. Entry Widgets

**W_Preload (EchoesPreloadWidget)**
- Checks `/api/system/status` for API health
- Loads saved token from LocalPlayerSettings
- Validates token via `/api/auth/validate-token`
- Transitions to Login or CharacterSelect

**W_Login (EchoesLoginWidget)**
- Email/password input
- "Remember Me" checkbox
- Calls `AuthSubsystem->Auth_Login()`
- Saves token if Remember Me checked
- Inherits from `UEchoesWindowBase` (draggable)

**W_CharacterSelect (EchoesCharacterSelectWidget)**
- Displays character list from AuthSubsystem
- Race selection for new characters
- Calls `AuthSubsystem->CreateCharacter(Name, RaceId)`
- "Enter World" button calls `ConnectToWorld()`
- Inherits from `UEchoesWindowBase`

#### 4. Server-Side Spawn (GameMode)
**File:** `Client/Echoes/Source/Echoes/EchoesServerGameMode.h/cpp`

**PostLogin Flow:**
```cpp
void PostLogin(APlayerController* NewPlayer)
{
    // Extract from connection URL
    ExtractLoginOptions(Options, Token, CharacterId);
    
    // Query character location
    QueryCharacterLocation(CharacterId, Token, NewPlayer);
}

void OnCharacterLocationReceived(...)
{
    // Parse location data
    FCharacterLocationData LocationData;
    
    // Spawn based on state
    if (LocationData.IsDocked)
        SpawnPlayerAtStation(PC, StationId, ShipTypeId);
    else
        SpawnPlayerInSpace(PC, Position, Rotation, ShipTypeId);
}
```

**Safety System:**
- Triple-layer fallback for API failures
- 10-second HTTP timeout
- Always spawns player, never hangs
- Comprehensive error logging

### API Endpoints

| Endpoint | Method | Purpose | Used By |
|----------|--------|---------|---------|
| `/api/system/status` | GET | Health check | W_Preload |
| `/api/auth/validate-token` | POST | Validate JWT | W_Preload |
| `/api/auth/login` | POST | Get JWT token | W_Login |
| `/api/character/list` | GET | List characters | AuthSubsystem |
| `/api/character` | POST | Create character | AuthSubsystem |
| `/api/character/{id}/connect-info` | GET | Server connection | AuthSubsystem |
| `/api/character/{id}/location` | GET | Spawn location | GameMode |

### Configuration

**DefaultGame.ini:**
```ini
[/Script/Echoes.EchoesAuthSubsystem]
ApiBaseUrl=http://localhost:5116/api
ServerSecret=UE5-Server-Secret-Change-Me
```

**appsettings.json (Backend):**
```json
{
  "Jwt": {
    "Secret": "your-secret-key",
    "Issuer": "EchoesAPI",
    "Audience": "EchoesClient",
    "ExpirationHours": 24
  }
}
```

---

## Inventory & Registry System

### Overview
Type-safe item definition system with registry-based lookups, supporting both integer and string-based access patterns.

### Architecture

```
┌─────────────────────────┐
│  Data Table (Content)   │
│  Row Name: "34"         │
│  DisplayName: Tritanium │
│  Icon: Texture2D        │
│  WorldMesh: StaticMesh  │
└────────┬────────────────┘
         ↓
┌─────────────────────────────┐
│  UEchoesInventorySubsystem  │
│  - BuildDefinitionCache()   │
│  - ItemTypeRegistry         │
│  - DefinitionCache          │
└────────┬────────────────────┘
         ↓
    ┌────┴────┐
    │ Access  │
    └─────────┘
    │         │
    ↓         ↓
Integer    String
TypeId     ItemId
```

### Item Type Registry

**Declaration:**
```cpp
// In UEchoesInventorySubsystem
UPROPERTY()
TMap<int32, FEchoesItemDefinitionRow> ItemTypeRegistry;
```

**Population:**
```cpp
void UEchoesInventorySubsystem::BuildDefinitionCache()
{
    ItemTypeRegistry.Empty();
    
    // Parse data table row names as integers
    for (const FName& RowName : ItemDefinitionsTable->GetRowNames())
    {
        FString RowNameStr = RowName.ToString();
        if (RowNameStr.IsNumeric())
        {
            int32 TypeId = FCString::Atoi(*RowNameStr);
            ItemTypeRegistry.Add(TypeId, *Row);
        }
    }
}
```

**Access Methods:**
```cpp
// Type-safe integer access
const FEchoesItemDefinitionRow* GetItemFromRegistry(int32 TypeId) const;
bool HasItemInRegistry(int32 TypeId) const;

// Legacy string access (maintained for compatibility)
const FEchoesItemDefinitionRow* GetItemDefinition(const FString& ItemId) const;
bool HasItemDefinition(const FString& ItemId) const;
```

**Usage Example:**
```cpp
// In GameMode spawn logic
if (InventorySubsystem)
{
    const FEchoesItemDefinitionRow* ShipDef = InventorySubsystem->GetItemFromRegistry(ShipTypeId);
    if (ShipDef)
    {
        FText ShipName = ShipDef->DisplayName;
        TSoftObjectPtr<UStaticMesh> ShipMesh = ShipDef->WorldMesh;
        float Mass = ShipDef->UnitMass;
        // Apply to ship actor
    }
}
```

### Item Definition Structure

**FEchoesItemDefinitionRow:**
```cpp
USTRUCT(BlueprintType)
struct FEchoesItemDefinitionRow : public FTableRowBase
{
    GENERATED_BODY()
    
    // Display
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText DisplayName;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText Description;
    
    // Visual Assets
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSoftObjectPtr<UTexture2D> Icon;          // UI icon (64x64 or 128x128)
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSoftObjectPtr<UStaticMesh> WorldMesh;    // 3D mesh for world
    
    // Physics
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float UnitVolume = 0.01f;                 // Cubic meters per unit
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float UnitMass = 0.01f;                   // Kilograms per unit
    
    // Metadata
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EEchoesItemCategory Category;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 TechLevel = 1;                      // 0-5
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bIsStackable = true;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 MaxStackSize = 0;                   // 0 = unlimited
};
```

### Async Asset Loading

**For icons:**
```cpp
void AsyncLoadItemIcon(const FString& ItemId, FOnIconLoaded OnLoaded);
```

**For meshes:**
```cpp
void AsyncLoadItemWorldMesh(const FString& ItemId, FOnWorldMeshLoaded OnLoaded);
```

**Usage:**
```cpp
InventorySubsystem->AsyncLoadItemIcon("34", 
    FOnIconLoaded::CreateLambda([this](UTexture2D* LoadedIcon) {
        if (LoadedIcon && IconWidget)
        {
            IconWidget->SetBrushFromTexture(LoadedIcon);
        }
    })
);
```

### Ship Inventory

**Methods:**
```cpp
void Inventory_FetchShips(FOnShipsReceived OnSuccess, FOnInventoryFailure OnFailure);
void Inventory_FetchShipFitting(const FGuid& ShipId, ...);
void Inventory_SetActiveShip(const FGuid& ShipId, ...);
void Inventory_RequestPersonalHangar(int32 StationId, ...);
```

**Cached Data:**
```cpp
TArray<FEchoesShipInstance> Inventory_GetCachedShips() const;
FEchoesShipFitting Inventory_GetCachedFitting() const;
FEchoesShipInstance Inventory_GetActiveShip() const;
```

### Integration with GameMode

```cpp
// In SpawnPlayerInSpace()
const FEchoesItemDefinitionRow* ShipDef = nullptr;
if (InventorySubsystem)
{
    ShipDef = InventorySubsystem->GetItemFromRegistry(ShipTypeId);
    if (ShipDef && !ShipDef->WorldMesh.IsNull())
    {
        // Apply mesh to ship actor
        UStaticMeshComponent* MeshComp = ShipActor->FindComponentByClass<UStaticMeshComponent>();
        if (MeshComp)
        {
            InventorySubsystem->AsyncLoadItemWorldMesh(
                FString::FromInt(ShipTypeId),
                FOnWorldMeshLoaded::CreateLambda([MeshComp](UStaticMesh* LoadedMesh) {
                    if (MeshComp && LoadedMesh)
                    {
                        MeshComp->SetStaticMesh(LoadedMesh);
                    }
                })
            );
        }
    }
}
```

---

## Windows UI System

### Overview
EVE-like windowing system with draggable, resizable, and focusable windows. All game UI inherits from `UEchoesWindowBase`.

### Base Window Class

**File:** `Client/Echoes/Source/Echoes/UI/EchoesWindowBase.h/cpp`

**Features:**
- Draggable via title bar
- Resizable from bottom-right corner
- Z-order focus management
- Minimum size constraints
- Close button
- Position persistence (optional)

**Key Methods:**
```cpp
void SetWindowTitle(const FText& Title);
FText GetWindowTitle() const;
void CloseWindow();
void SetWindowPosition(FVector2D Position);
FVector2D GetWindowPosition() const;
void SetWindowSize(FVector2D Size);
FVector2D GetWindowSize() const;
void BringToFront();
void SetMinimumSize(FVector2D MinSize);
```

**Usage:**
```cpp
// In derived widget class
class ECHOES_API UMyGameWidget : public UEchoesWindowBase
{
    GENERATED_BODY()

public:
    virtual void NativeConstruct() override
    {
        Super::NativeConstruct();
        SetWindowTitle(FText::FromString("My Window"));
        SetMinimumSize(FVector2D(400, 300));
    }
};
```

### Widget Hierarchy

```
UEchoesWindowBase (draggable, resizable)
├── UEchoesLoginWidget
├── UEchoesCharacterSelectWidget
├── UEchoesStationMenuWidget
├── UEchoesInventoryWidget
├── UEchoesMarketWidget
└── ... (all game windows)
```

### Window Management

**Snapping:**
- Edge-to-edge window snapping
- Configurable snap threshold
- Visual snap indicators

**Focus:**
- Click to bring to front
- Modal windows
- Focus stack management

**Persistence:**
- Save window positions
- Restore on next session
- Per-character preferences

### Blueprint Integration

All window methods are BlueprintCallable/BlueprintPure:

```
Event Construct
  ↓
Call: Set Window Title
Call: Set Window Size (800, 600)
Call: Set Window Position (100, 100)
```

---

## Item Actor System

### Overview
Physical item representation in the game world for ejected cargo, loot, and containers.

### Item Actor Base

**File:** `Client/Echoes/Source/Echoes/Actors/EchoesItemActor.h/cpp` (if exists)

**Components:**
- Static Mesh Component (visual)
- Sphere Collision Component (interaction)
- Physics Component (optional, for floating debris)

**Properties:**
```cpp
UPROPERTY(EditAnywhere, BlueprintReadWrite)
int32 ItemTypeId;                    // Links to ItemTypeRegistry

UPROPERTY(EditAnywhere, BlueprintReadWrite)
int32 Quantity;

UPROPERTY(EditAnywhere, BlueprintReadWrite)
FGuid ContainerId;                   // If in a container

UPROPERTY(EditAnywhere, BlueprintReadWrite)
bool bIsLootable = true;
```

### Spawning Items in World

```cpp
void SpawnItemInWorld(int32 ItemTypeId, int32 Quantity, FVector Location)
{
    // Get item definition from registry
    const FEchoesItemDefinitionRow* ItemDef = InventorySubsystem->GetItemFromRegistry(ItemTypeId);
    if (!ItemDef)
        return;
    
    // Spawn actor
    FActorSpawnParameters SpawnParams;
    AEchoesItemActor* ItemActor = GetWorld()->SpawnActor<AEchoesItemActor>(
        AEchoesItemActor::StaticClass(),
        Location,
        FRotator::ZeroRotator,
        SpawnParams
    );
    
    if (ItemActor)
    {
        ItemActor->ItemTypeId = ItemTypeId;
        ItemActor->Quantity = Quantity;
        
        // Load and set mesh asynchronously
        InventorySubsystem->AsyncLoadItemWorldMesh(
            FString::FromInt(ItemTypeId),
            FOnWorldMeshLoaded::CreateLambda([ItemActor](UStaticMesh* LoadedMesh) {
                if (ItemActor && LoadedMesh)
                {
                    UStaticMeshComponent* MeshComp = ItemActor->FindComponentByClass<UStaticMeshComponent>();
                    if (MeshComp)
                    {
                        MeshComp->SetStaticMesh(LoadedMesh);
                    }
                }
            })
        );
    }
}
```

### Interaction System

**Pickup:**
```cpp
void OnItemActorInteract(AEchoesItemActor* ItemActor)
{
    if (!ItemActor)
        return;
    
    int32 TypeId = ItemActor->ItemTypeId;
    int32 Qty = ItemActor->Quantity;
    
    // Add to player inventory
    // TODO: Implement inventory add logic
    
    // Destroy actor
    ItemActor->Destroy();
}
```

**Loot Containers:**
- Floating cargo containers
- Wreckage from destroyed ships
- Station container system

---

## Server & World Management

### Regional Server Architecture

```
┌────────────────────────┐
│  Cluster Manager API   │
│  (ASP.NET Backend)     │
└───────┬────────────────┘
        ↓
   ┌────┴────┐
   │         │
   ↓         ↓
┌──────┐  ┌──────┐  
│ UE5  │  │ UE5  │  ...
│Server│  │Server│
│ #1   │  │ #2   │
└──────┘  └──────┘
```

**Server Management Subsystem:**
- `UEchoesServerManagementSubsystem`
- Registers with cluster manager on startup
- Reports capacity and status
- Receives world generation config

**World Generator:**
- `AEchoesWorldGenerator`
- Spawns solar systems, planets, stations
- Triggered after server registration
- Managed by GameMode

### Server Discovery

**Client Flow:**
```
AuthSubsystem->ConnectToWorld(CharacterId)
    ↓
GET /api/character/{id}/connect-info
    ↓
Response: { serverIP: "...", serverPort: 7777, systemId: "..." }
    ↓
ClientTravel("serverIP:7777?Token=xxx&CharacterId=yyy")
```

**Server Assignment:**
- Based on character's current solar system
- Load balancing across regional servers
- Seamless transfer between systems (future)

---

## Integration Patterns

### 1. Subsystem Communication

**Pattern: Subsystem → Subsystem**
```cpp
// In GameMode
UGameInstance* GI = GetWorld()->GetGameInstance();
UEchoesAuthSubsystem* Auth = GI->GetSubsystem<UEchoesAuthSubsystem>();
UEchoesInventorySubsystem* Inv = GI->GetSubsystem<UEchoesInventorySubsystem>();

if (Auth && Inv)
{
    FString Token = Auth->Auth_GetToken();
    // Use token for inventory requests
}
```

### 2. Widget → Subsystem

**Pattern: Event-Driven**
```cpp
// In Widget
void UMyWidget::OnButtonClicked()
{
    UEchoesAuthSubsystem* Auth = GetGameInstance()->GetSubsystem<UEchoesAuthSubsystem>();
    Auth->OnCharacterCreated.AddDynamic(this, &UMyWidget::OnCharCreated);
    Auth->CreateCharacter("MyChar", 1);
}

void UMyWidget::OnCharCreated(const FCharacterData& Data)
{
    // Handle result
}
```

### 3. GameMode → API

**Pattern: Async HTTP with Callback**
```cpp
void AEchoesServerGameMode::QuerySomething()
{
    TSharedRef<IHttpRequest> Request = Http->CreateRequest();
    Request->SetURL(GetApiBaseUrl() + "/endpoint");
    Request->SetHeader("Authorization", "Bearer " + Token);
    Request->OnProcessRequestComplete().BindUObject(
        this,
        &AEchoesServerGameMode::OnResponseReceived
    );
    Request->ProcessRequest();
}
```

### 4. Registry Lookup Pattern

**Always validate pointers:**
```cpp
// Correct usage
if (InventorySubsystem)
{
    const FEchoesItemDefinitionRow* Def = InventorySubsystem->GetItemFromRegistry(TypeId);
    if (Def)
    {
        // Use definition
    }
    else
    {
        // Handle not found
    }
}
else
{
    // Handle subsystem not available
}
```

---

## Production Checklist

### Before Deployment

**Backend:**
- [ ] Update JWT secret in production config
- [ ] Configure CORS for game client domain
- [ ] Set up database migrations
- [ ] Configure logging and monitoring
- [ ] Load test API endpoints

**Client:**
- [ ] Update ApiBaseUrl in config
- [ ] Test cold start flow
- [ ] Test all entry paths (new player, returning player, expired token)
- [ ] Verify ItemTypeRegistry populated correctly
- [ ] Test timeout/error scenarios

**Server:**
- [ ] Configure server discovery endpoint
- [ ] Test world generation
- [ ] Test player spawn (docked and space)
- [ ] Verify OnEntryFlowComplete handling
- [ ] Load test with multiple concurrent players

### Monitoring

**Key Metrics:**
- Auth subsystem login success rate
- Token validation success rate
- Character location query latency
- Item registry cache hit rate
- Average time from launch to game-ready

**Error Tracking:**
- HTTP timeout occurrences
- Null pointer access attempts
- Item definition not found counts
- Player spawn failures

---

## Future Enhancements

### Phase 2 Features
- Ship fitting visualization
- Real-time inventory updates (WebSocket)
- Station docking animations
- Advanced ship spawning with custom fits
- Multi-system server transitions

### Phase 3 Features
- Market system integration
- Manufacturing UI
- Contract system
- Corporation management
- Advanced item system (charges, drones, fighters)

---

## Quick Reference

### Most Common Operations

**Get Player's Token:**
```cpp
UEchoesAuthSubsystem* Auth = GetGameInstance()->GetSubsystem<UEchoesAuthSubsystem>();
FString Token = Auth->Auth_GetToken();
```

**Get Item Definition:**
```cpp
UEchoesInventorySubsystem* Inv = GetGameInstance()->GetSubsystem<UEchoesInventorySubsystem>();
const FEchoesItemDefinitionRow* Def = Inv->GetItemFromRegistry(34); // Tritanium
```

**Spawn Player:**
```cpp
// In GameMode::PostLogin
QueryCharacterLocation(CharacterId, Token, PlayerController);
// Callback handles spawn based on location
```

**Load Asset Async:**
```cpp
Inv->AsyncLoadItemIcon("34", 
    FOnIconLoaded::CreateLambda([](UTexture2D* Icon) {
        // Use icon
    })
);
```

---

## Conclusion

The Echoes V1 architecture provides a solid foundation for an MMO game with:
- Secure JWT-based authentication
- Type-safe item system with registry
- Flexible UI windowing system
- Server-authoritative gameplay
- Comprehensive error handling
- Production-ready patterns

All systems are designed for scalability, maintainability, and extensibility.

**For questions or contributions, refer to individual component documentation files.**

---

**Document Authors:** Echoes Development Team  
**Document Status:** Living Document - Updated as systems evolve  
**Next Review:** After Phase 2 Feature Implementation
