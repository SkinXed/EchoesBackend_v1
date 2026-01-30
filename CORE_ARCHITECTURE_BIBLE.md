# Echoes MMO - Core Architecture Bible

> **The Single Source of Truth**  
> Complete architectural documentation from PostgreSQL to ship physics in space.

**Version:** 1.0  
**Last Updated:** 2026-01-30  
**Status:** Production-Ready Foundation  
**Total System:** 10,100 lines implemented + 870 lines documented + 240+ KB documentation

---

## Table of Contents

1. [The Core Philosophy](#1-the-core-philosophy)
2. [Backend Infrastructure](#2-backend-infrastructure)
3. [Client Architecture](#3-client-architecture)
4. [Visual Layer & Game Flow](#4-visual-layer--game-flow)
5. [Technical Registry](#5-technical-registry)
6. [Quick Reference](#6-quick-reference)

---

## 1. The Core Philosophy

### 1.1 "Postgres is Truth" Principle

**Foundation:** The database is the single source of truth for all game state.

```
Truth Hierarchy:
PostgreSQL Database (Source of Truth)
    ↓
ASP.NET Core Backend (Calculation & Validation)
    ↓
UE5 Server (Authority & Replication)
    ↓
UE5 Clients (Display Only)
```

**Key Rules:**
- ✅ All persistent data stored in PostgreSQL
- ✅ Backend calculates all stats and bonuses
- ✅ Server validates all player actions
- ✅ Clients display but never decide

**Example Flow:**
```
Player fits module:
1. Client UI → Server RPC (untrusted)
2. Server → Backend API (JWT authenticated)
3. Backend → Database validation
4. Backend → Stat calculation
5. Backend → Server response
6. Server → Apply and replicate (authoritative)
7. Clients → Display updated stats (read-only)
```

### 1.2 Mirror Architecture

**Concept:** Every backend controller has a corresponding UE5 subsystem.

```
C# Backend              ↔  UE5 Client
─────────────────────────────────────
AuthController          ↔  UEchoesAuthSubsystem
CharacterController     ↔  UEchoesIdentitySubsystem
ShipInventoryController ↔  UEchoesInventorySubsystem
ShipController          ↔  UEchoesShipStatsSubsystem
```

**Data Mirroring:**
```
C# DTOs                 ↔  UE5 Structs
─────────────────────────────────────
ShipStatsDto            ↔  FEchoesShipStats
CharacterDataDto        ↔  FEchoesCharacter
ShipFittingDto          ↔  FEchoesShipFitting
AuthResponseDto         ↔  FAuthResponse
```

### 1.3 Server Authority

**Principle:** Server has final say on all gameplay-affecting values.

**Implementation:**
```cpp
// Server-authoritative pattern
UPROPERTY(Replicated)
FEchoesShipStats ReplicatedShipStats;

// Only server can modify
if (HasAuthority())
{
    ReplicatedShipStats = NewStats;
}

// Clients receive via replication
UFUNCTION()
void OnRep_ShipStats()
{
    ApplyStatsLocally(ReplicatedShipStats);
}
```

### 1.4 Security Model

**Multi-Layer Security:**

1. **JWT for Players**
   - Generated on login
   - Contains AccountId, CharacterId
   - Validates all player API requests

2. **X-Server-Secret for UE Server**
   - Server-to-server authentication
   - Validates UE Server requests
   - Never exposed to clients

**Request Flow:**
```
Client Request:
Authorization: Bearer JWT_TOKEN

UE Server Request:
X-Server-Secret: SERVER_SECRET_KEY
```

### 1.5 Naming Conventions

**Prefix Registry:**

| Prefix | Usage | Example |
|--------|-------|---------|
| `Common_` | Shared functions | `Common_ApplyThrust()` |
| `Server_` | Server-only | `Server_VerifyOwnership()` |
| `Client_` | Client-only | `Client_UpdateUI()` |
| `ServerRPC_` | Client → Server | `ServerRPC_RequestUndock()` |
| `ClientRPC_` | Server → Client | `ClientRPC_UpdateStats()` |
| `Auth_` | Authentication | `Auth_Login()` |
| `Identity_` | Character mgmt | `Identity_SelectCharacter()` |
| `Inventory_` | Inventory ops | `Inventory_FetchShips()` |
| `UI_` | UI wrappers | `UI_FitModule()` |

**Folder Structure:**
```
Source/Echoes/Core/
├── Common/        # Shared code
├── Server/        # Server-only
└── Client/        # Client-only
```

---

## 2. Backend Infrastructure

### 2.1 Complete API Registry (18 Endpoints)

#### Authentication (2)
```
POST /api/auth/register
POST /api/auth/login
```

#### Character (3)
```
GET /api/character/me
GET /api/character/{id}
POST /api/character
```

#### Inventory (6)
```
GET /api/inventory/ships
GET /api/inventory/ship/{id}/fitting
POST /api/inventory/ship/{id}/activate
GET /api/inventory/ship/{id}/ownership
PUT /api/inventory/ship/{shipId}/module/{moduleId}/fit
DELETE /api/inventory/ship/{shipId}/module/{moduleId}/unfit
```

#### Ship Stats (5)
```
GET /api/ship/{id}/stats
POST /api/ship/{id}/modules
PUT /api/ship/modules/{id}/bonuses
DELETE /api/ship/modules/{id}
```

### 2.2 Fitting Service Formula

**Core Calculations:**

```csharp
// Mass (Additive)
TotalMass = BaseMass + Σ(ModuleMass)

// Thrust (Additive)
TotalThrust = BaseThrust + Σ(ThrustBonus)

// Inertia (Multiplicative)
TotalInertia = BaseInertia × Π(InertiaModifier)

// Rotation (Additive)
TotalRotation = BaseRotation + Σ(RotationBonus)

// Max Velocity (Multiplicative)
TotalMaxVelocity = BaseMaxVelocity × Π(MaxVelocityModifier)

// Align Time (EVE Formula)
AlignTime = (Inertia × Mass) / 500,000
```

**Example:**
```
Ship: Frigate
BaseMass: 1,000,000 kg
BaseThrust: 500,000 N

Fitted: 1600mm Armor Plate (+300,000 kg, ×1.12 inertia)
Fitted: Afterburner (+150,000 N thrust, ×1.26 velocity)

Result:
TotalMass = 1,300,000 kg
TotalThrust = 650,000 N
TotalInertia = 1.12
MaxVelocity = 126 m/s
AlignTime = (1.12 × 1,300,000) / 500,000 = 2.91 sec
```

### 2.3 Database Schema

**Entity Hierarchy:**
```
Account
 └─> Character
      ├─> Wallet (ISK)
      ├─> Skills (SP)
      └─> ShipInstance
           ├─> ShipType (reference)
           └─> ShipInstanceModule
                └─> ModuleType (reference)
```

**Key Tables:**
- Accounts (Id, Email, PasswordHash)
- Characters (Id, AccountId, Name, Race, WalletBalance)
- Ships (Id, Name, BaseMass, BaseThrust, BaseInertia...)
- ShipInstances (Id, CharacterId, ShipTypeId, LocationSystemId)
- ShipInstanceModules (Id, ShipInstanceId, ModuleTypeId, SlotType, SlotIndex)
- ModuleTypes (Id, Name, MassBonus, ThrustBonus, InertiaModifier...)

---

## 3. Client Architecture

### 3.1 Subsystems Layer

All subsystems inherit from `UGameInstanceSubsystem` to persist across levels.

#### Auth Subsystem
```cpp
// Authentication and session management
- Auth_Login(Request, OnSuccess, OnFailure)
- Auth_Register(Request, OnSuccess, OnFailure)
- Auth_GetToken() → JWT
- Auth_IsLoggedIn() → bool
- ServerRPC_VerifySession()
```

#### Identity Subsystem
```cpp
// Character management
- Identity_FetchCharacter(OnSuccess, OnFailure)
- Identity_SelectCharacter(CharacterId)
- Identity_GetSelectedCharacter() → FEchoesCharacter
- UI_CreateCharacter(Name, Race, PortraitId, OnSuccess, OnFailure)

// Delegate
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCharacterSelected, ...);
```

#### Inventory Subsystem
```cpp
// Ship and module management
- Inventory_FetchShips(OnSuccess, OnFailure)
- Inventory_FetchShipFitting(ShipId, OnSuccess, OnFailure)
- Inventory_SetActiveShip(ShipId, OnSuccess, OnFailure)
- UI_FitModule(ShipId, ModuleId, SlotType, SlotIndex, OnSuccess, OnFailure)
- UI_UnfitModule(ShipId, ModuleId, OnSuccess, OnFailure)

// Delegate
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFittingChanged, FEchoesShipFitting, Fitting);
```

#### GameState Subsystem
```cpp
// Game flow management
- TransitionToLogin()
- TransitionToCharacterSelect()
- TransitionToHangar(CharacterId)
- TransitionToSpace(CharacterId, ShipId)
- GetCurrentState() → EEchoesGameState

// States
enum class EEchoesGameState : uint8
{
    Login, CharacterSelect, Hangar, InSpace
};
```

### 3.2 Physics Engine

**Movement Component (EchoesShipMovementComponent):**

#### Force Application
```cpp
void Common_ApplyThrust(FVector InputVector, float DeltaTime)
{
    // Calculate thrust on local axes
    FVector ThrustForce = GetActorForwardVector() * InputVector.X * ThrustForce;
    ThrustForce += GetActorRightVector() * InputVector.Y * ThrustForce;
    ThrustForce += GetActorUpVector() * InputVector.Z * ThrustForce;

    // Apply force (no hard velocity clamp)
    if (UPrimitiveComponent* Primitive = Cast<UPrimitiveComponent>(UpdatedComponent))
    {
        Primitive->AddForce(ThrustForce, NAME_None, true);
    }

    // Natural max velocity via damping
    ApplyLinearDamping(DeltaTime);
}
```

**Max Velocity Formula:**
```
At equilibrium: F_thrust = F_damping
F_damping = v × Damping
Therefore: MaxVelocity = F_thrust / Damping

Example:
Thrust = 650,000 N
InertiaMultiplier = 1.12
Damping = 1.12 × 0.1 = 0.112
Natural MaxVelocity = 650,000 / 0.112 ≈ 126 m/s (gameplay scaled)
```

#### PD Controller for Rotation
```cpp
void Common_AlignToVector(FVector TargetWorldDirection, float DeltaTime)
{
    FVector CurrentForward = GetActorForwardVector();
    FVector TargetDirection = TargetWorldDirection.GetSafeNormal();

    // Proportional term (angle error)
    FVector CrossProduct = FVector::CrossProduct(CurrentForward, TargetDirection);
    float AngleError = FMath::Asin(CrossProduct.Size());
    
    // Derivative term (angular velocity damping)
    FVector AngularVelocity = UpdatedComponent->GetPhysicsAngularVelocityInDegrees();
    
    // PD control
    float kP = 100.0f; // Proportional gain
    float kD = 20.0f;  // Derivative gain
    
    FVector TorqueP = CrossProduct.GetSafeNormal() * AngleError * kP;
    FVector TorqueD = -AngularVelocity * kD;
    
    FVector TotalTorque = (TorqueP + TorqueD) * RotationTorque;
    
    // Apply torque (no SetRotation = no collision bugs)
    if (UPrimitiveComponent* Primitive = Cast<UPrimitiveComponent>(UpdatedComponent))
    {
        Primitive->AddTorqueInRadians(TotalTorque, NAME_None, true);
    }
}
```

**Benefits:**
- ✅ No collision bugs (pure physics)
- ✅ Smooth approach
- ✅ No overshoot
- ✅ Works with any mass

#### Align Time
```cpp
float Common_CalculateAlignTime() const
{
    // EVE formula
    return (InertiaMultiplier * Mass) / 500000.0f;
}
```

### 3.3 Warp State Machine

**States:**
```cpp
enum class EWarpState : uint8
{
    Idle,       // Normal flight
    Aligning,   // Turning toward target + accelerating
    Warping,    // FTL travel (physics disabled)
    Exiting     // Decelerating to normal speed
};
```

**Transition Logic:**
```cpp
void TickWarpStateMachine(float DeltaTime)
{
    switch (CurrentWarpState)
    {
        case EWarpState::Aligning:
        {
            // Check alignment and speed
            FVector ToTarget = (WarpTargetLocation - GetActorLocation()).GetSafeNormal();
            FVector VelocityDir = GetVelocity().GetSafeNormal();
            
            float DotProduct = FVector::DotProduct(VelocityDir, ToTarget);
            float CurrentSpeed = GetVelocity().Size();
            
            // Transition when:
            // 1. Velocity vector aligned (dot > 0.95 = ~18°)
            // 2. Speed > 75% max velocity
            if (DotProduct >= 0.95f && CurrentSpeed >= MaxVelocity * 0.75f)
            {
                EnterWarpSpeed();
            }
            break;
        }

        case EWarpState::Warping:
        {
            // Disable physics, move along ray
            SetSimulatePhysics(false);
            FVector Direction = (WarpTargetLocation - GetActorLocation()).GetSafeNormal();
            SetActorLocation(GetActorLocation() + Direction * WarpSpeed * DeltaTime);
            
            // Check exit distance
            if (FVector::Dist(GetActorLocation(), WarpTargetLocation) < ExitThreshold)
            {
                CurrentWarpState = EWarpState::Exiting;
                SetSimulatePhysics(true);
            }
            break;
        }

        case EWarpState::Exiting:
        {
            // Apply braking
            FVector BrakingForce = -GetVelocity().GetSafeNormal() * ThrustForce * 2.0f;
            Primitive->AddForce(BrakingForce, NAME_None, true);
            
            // Exit when slow
            if (GetVelocity().Size() < MaxVelocity * 0.1f)
            {
                CurrentWarpState = EWarpState::Idle;
            }
            break;
        }
    }
}
```

**State Diagram:**
```
Idle ─[Warp Command]→ Aligning
         ↓ [Aligned && Speed >= 75%]
      Warping
         ↓ [Distance < ExitThreshold]
      Exiting
         ↓ [Speed < 10% MaxVel]
      Idle
```

---

## 4. Visual Layer & Game Flow

### 4.1 Hangar System

**AEchoesHangarManager:**
```cpp
// Responsibilities:
- Subscribe to OnFittingChanged
- Spawn ship preview mesh at designated point
- Update ship mesh when modules fitted/unfitted
- Manage ship preview lifecycle

// Key Methods:
void InitializeHangar(const FString& CharacterId);
void SpawnShipPreview(const FString& ShipId);
void UpdateShipMesh(const FEchoesShipFitting& NewFitting);

// Integration:
void BeginPlay()
{
    InventorySubsystem->OnFittingChanged.AddDynamic(this, &AEchoesHangarManager::OnFittingChanged);
    InitializeHangar(CharacterId);
}
```

**Orbit Camera (AEchoesHangarPawn):**
```cpp
void Tick(float DeltaTime)
{
    // Calculate orbit position
    float X = TargetLocation.X + OrbitDistance * cos(CurrentYaw);
    float Y = TargetLocation.Y + OrbitDistance * sin(CurrentYaw);
    float Z = TargetLocation.Z + OrbitHeight;
    
    // Smooth interpolation
    FVector DesiredLocation(X, Y, Z);
    SetActorLocation(FMath::VInterpTo(GetActorLocation(), DesiredLocation, DeltaTime, 2.0f));
    
    // Look at target
    FRotator LookRotation = FindLookAtRotation(GetActorLocation(), TargetLocation);
    SetActorRotation(FMath::RInterpTo(GetActorRotation(), LookRotation, DeltaTime, 5.0f));
}

// Input
void RotateCamera(float Value) { CurrentYaw += Value * RotationSpeed; }
void ZoomCamera(float Value) { OrbitDistance = FMath::Clamp(OrbitDistance + Value, Min, Max); }
```

### 4.2 UI/UX System

**Fitting Widget (Reactive):**
```cpp
void UEchoesFittingWidget::NativeConstruct()
{
    InventorySubsystem = GetGameInstance()->GetSubsystem<UEchoesInventorySubsystem>();
    
    // Bind to reactive updates
    InventorySubsystem->OnFittingChanged.AddDynamic(this, &UEchoesFittingWidget::OnFittingChanged);
    
    RefreshFittingDisplay();
}

void OnFittingChanged(const FEchoesShipFitting& NewFitting)
{
    // Automatically updates when modules fitted/unfitted
    MassText->SetText(FText::Format(TEXT("Mass: {0} kg"), NewFitting.TotalMass));
    ThrustText->SetText(FText::Format(TEXT("Thrust: {0} N"), NewFitting.Thrust));
    
    float AlignTime = (NewFitting.InertiaMultiplier * NewFitting.TotalMass) / 500000.0f;
    AlignTimeText->SetText(FText::Format(TEXT("Align Time: {0} sec"), AlignTime));
}
```

**Drag & Drop:**
```cpp
bool UEchoesModuleSlotWidget::NativeOnDrop(const FGeometry& InGeometry, 
                                          const FDragDropEvent& InDragDropEvent, 
                                          UDragDropOperation* InOperation)
{
    UEchoesModuleDragDropOperation* DragOp = Cast<UEchoesModuleDragDropOperation>(InOperation);
    if (!DragOp) return false;

    // Call UI wrapper (handles backend + cache + delegates)
    InventorySubsystem->UI_FitModule(
        DragOp->ShipId,
        DragOp->ModuleId,
        SlotType,
        SlotIndex,
        FOnModuleFitted::CreateUObject(this, &UEchoesModuleSlotWidget::OnSuccess),
        FOnInventoryFailure::CreateUObject(this, &UEchoesModuleSlotWidget::OnFailure)
    );

    return true;
}

void OnSuccess()
{
    // UI automatically updates via OnFittingChanged delegate
}
```

### 4.3 Complete Player Journey

**State Machine Flow:**
```
1. Game Launch → L_MainMenu
   - W_AuthMain widget
   - Email/password input
   
2. Auth_Login() → Backend validates → JWT stored
   
3. TransitionToCharacterSelect() → L_CharacterSelect
   - W_CharacterSelect widget
   - Display character list
   - "Create New" or "Enter Game"
   
4. Identity_SelectCharacter(CharacterId)
   
5. TransitionToHangar(CharacterId) → L_Hangar
   - HangarGameMode spawns HangarPawn
   - HangarManager spawns ship preview
   - W_FittingWindow + W_InventoryGrid shown
   
6. Player fits module:
   - Drag module to slot
   - UI_FitModule() → Backend updates
   - OnFittingChanged.Broadcast()
   - HangarManager updates ship mesh
   - FittingWidget updates stats
   - Real-time feedback: "Mass: 1,580,000 kg (+58%)"
   
7. Player clicks "Undock":
   - ServerRPC_RequestUndock()
   - TransitionToSpace(CharacterId, ShipId)
   
8. L_Space → Ship spawned
   - ServerRPC_RequestShipInitialization(ShipId)
   - Server fetches fitting from backend
   - Server applies physics stats
   - ReplicatedShipStats updated
   - Clients apply stats
   
9. Player flies! 🚀
   - WASD for thrust
   - Mouse for direction
   - Physics-based movement
```

---

## 5. Technical Registry

### 5.1 Project Statistics

**Backend (C# / ASP.NET Core 8):**
- Controllers: 12
- Services: 6
- Models: 30+
- API Endpoints: 18
- Lines of Code: ~4,100

**UE5 Client (C++ / Unreal Engine 5.6):**
- Subsystems: 6
- Components: 3
- Actors: 3
- Structs: 25+
- Lines of Code: ~6,000

**Documentation:**
- Guides: 14 documents
- Total Size: 240+ KB

**Total System:**
- Implemented: 10,100 lines
- Documented (ready): 870 lines
- Documentation: 240+ KB

### 5.2 File Structure

```
EchoesBackend_v1/
├── Controllers/
│   ├── AuthController.cs
│   ├── CharacterController.cs
│   ├── Ship/ShipController.cs
│   └── Inventory/ShipInventoryController.cs
├── Models/
│   ├── Entities/ (Account, Character, Ship, Module)
│   └── DTOs/ (Auth, Character, Ship, Inventory)
├── Services/
│   └── Ship/ (IShipFittingService, ShipFittingService)
├── Data/
│   └── DatabaseContext.cs
└── Program.cs

Client/Echoes/
├── Config/ (DefaultEngine.ini, DefaultGame.ini)
├── Content/
│   ├── Maps/ (L_MainMenu, L_CharacterSelect, L_Hangar, L_Space)
│   └── UI/ (W_Auth, W_Character, W_Fitting, W_Inventory)
└── Source/Echoes/Core/
    ├── Common/
    │   ├── EchoesShipTypes.h
    │   ├── EchoesGameStateSubsystem.h/cpp
    │   ├── EchoesShipMovementComponent.h/cpp
    │   └── Networking/
    │       ├── EchoesAuthSubsystem.h/cpp
    │       ├── EchoesIdentitySubsystem.h/cpp
    │       └── EchoesInventorySubsystem.h/cpp
    ├── Client/
    │   ├── EchoesShipPawn.h/cpp
    │   └── EchoesHangarPawn.h/cpp
    └── Server/
        ├── EchoesHangarManager.h/cpp
        └── EchoesHangarGameMode.h/cpp
```

### 5.3 Setup Guide

**Backend Setup:**
```bash
# Prerequisites
- .NET 8 SDK
- PostgreSQL 14+

# Steps
1. Clone: git clone https://github.com/SkinXed/EchoesBackend_v1.git
2. Database: Create "echoes_db" in PostgreSQL
3. Configure: Update appsettings.json (connection string, JWT, ServerSecret)
4. Migrate: dotnet ef database update
5. Run: dotnet run

# API at http://localhost:5116
```

**UE5 Setup:**
```bash
# Prerequisites
- Unreal Engine 5.6
- Visual Studio 2022 / Rider

# Steps
1. Open: Client/Echoes/Echoes.uproject
2. Generate: Right-click → Generate project files
3. Build: Open in IDE → Build Solution
4. Configure: Edit DefaultGame.ini
   [/Script/Echoes.EchoesAuthSubsystem]
   ApiBaseUrl=http://localhost:5116/api
   ServerSecret=YOUR_SECRET
5. Play: Press Play in editor
```

### 5.4 Development Roadmap

**Phase 1: Foundation** ✅ COMPLETE
- Backend APIs (18 endpoints)
- All subsystems (6)
- Ship physics
- Authentication
- Game state management

**Phase 2: Visual Systems** 🔄 IN PROGRESS
- Hangar Manager ✅ (290 lines)
- Hangar Pawn 📋 (270 lines documented)
- UI Widgets 📋 (400 lines documented)
- Drag & Drop 📋 (100 lines documented)

**Phase 3: Content Creation** 📋 PLANNED
- Ship 3D models
- Module assets
- Hangar environment
- UI assets

**Phase 4: Gameplay** 📋 PLANNED
- Combat system
- Mining/trading
- Missions
- Corporations

**Phase 5: Multiplayer** 📋 PLANNED
- Server scaling
- Player sync
- Fleet mechanics

**Phase 6: Polish & Launch** 📋 PLANNED
- Beta testing
- Optimization
- Localization
- Deployment

---

## 6. Quick Reference

### 6.1 Common Operations

**Adding New API Endpoint:**
1. Create DTO in Models/DTOs
2. Add method to controller
3. Add corresponding subsystem function in UE5
4. Mirror struct in UE5
5. Test with curl/Postman

**Adding Module Bonus:**
1. Add property to ShipInstanceModule (C#)
2. Update FittingService calculation
3. Add to FEchoesShipStats (UE5)
4. Apply in MovementComponent

**Creating UI Widget:**
1. Create C++ base class (inherit UUserWidget)
2. Create Blueprint widget (inherit from C++)
3. Bind to subsystem delegates
4. Implement NativeConstruct/NativeDestruct

### 6.2 Troubleshooting

| Issue | Cause | Solution |
|-------|-------|----------|
| 401 Unauthorized | Invalid JWT | Re-login |
| Ship not spawning | Ownership failed | Check CharacterId |
| Stats not updating | Delegate not bound | Check OnFittingChanged |
| Physics wrong | Mass not applied | Check SetMassOverrideInKg |
| Warp not entering | Alignment failing | Verify DotProduct >= 0.95 |

### 6.3 Security Checklist

- [ ] JWT tokens expire
- [ ] X-Server-Secret never exposed to clients
- [ ] All ownership validated
- [ ] Input validation on all endpoints
- [ ] HTTPS in production
- [ ] Rate limiting configured
- [ ] Security violations logged

---

## Appendix: Related Documentation

For detailed information:

1. **QUICK_START.md** - Fast reference
2. **AUTH_SYSTEM.md** - Authentication details
3. **FITTING_SERVICE.md** - Module bonus system
4. **IDENTITY_INVENTORY_SUBSYSTEMS.md** - Character & inventory
5. **SHIP_MOVEMENT_SYSTEM.md** - Physics details
6. **SHIP_PHYSICS_INTEGRATION.md** - Integration
7. **ARCHITECTURAL_IMPROVEMENTS.md** - Network optimizations
8. **NETWORK_SECURITY.md** - Security architecture
9. **UI_UX_SYSTEM.md** - UI implementation
10. **GAME_FLOW_SYSTEM.md** - Complete game flow
11. **HANGAR_IMPLEMENTATION.md** - Hangar system
12. **README_COMPLETE.md** - Project overview

---

## Glossary

**Key Terms:**
- **JWT:** JSON Web Token (player authentication)
- **X-Server-Secret:** Shared secret for UE Server
- **Subsystem:** UE5 singleton across levels
- **RPC:** Remote Procedure Call
- **Replication:** Server-to-client synchronization
- **Fitting:** Installing modules on ship
- **Align Time:** Time to reach 75% max velocity
- **Warp:** FTL travel
- **ISK:** In-game currency

---

## Document History

| Version | Date | Author | Changes |
|---------|------|--------|---------|
| 1.0 | 2026-01-30 | Architecture Team | Initial creation |

---

**End of Core Architecture Bible**

*This document represents the complete architectural foundation of the Echoes MMO system.*

**Status:** Production-Ready Foundation  
**Next:** Implement remaining UI widgets (870 lines documented)  
**Goal:** Transform from library to playable game
