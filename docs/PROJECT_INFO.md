# Echoes MMO Backend - Comprehensive Project Information

> **Complete technical reference for the EchoesBackend_v1 repository**  
> Generated: 2026-02-03

---

## Table of Contents

1. [Project Overview](#project-overview)
2. [Technology Stack](#technology-stack)
3. [Codebase Statistics](#codebase-statistics)
4. [Architecture Components](#architecture-components)
5. [Backend (C# / ASP.NET Core)](#backend-c--aspnet-core)
6. [Client (C++ / Unreal Engine 5.6)](#client-c--unreal-engine-56)
7. [Build Systems](#build-systems)
8. [Database Schema](#database-schema)
9. [Development Tools](#development-tools)
10. [Key Features](#key-features)

---

## Project Overview

**Echoes** is an EVE Online-inspired MMO backend built with modern technologies:

- **Backend**: ASP.NET Core 8 with PostgreSQL database
- **Client**: Unreal Engine 5.6 with C++ gameplay code
- **Architecture**: RESTful API with JWT authentication
- **Database**: PostgreSQL 16+ with Entity Framework Core migrations
- **Deployment**: Docker-ready, production-capable infrastructure

**Current Status**: Core Systems Development (51% complete)

---

## Technology Stack

### Backend Technologies

| Component | Technology | Version | Purpose |
|-----------|-----------|---------|---------|
| **Framework** | ASP.NET Core | 8.0 | Web API framework |
| **Language** | C# | 12.0 | Backend programming |
| **Database** | PostgreSQL | 16+ | Data persistence |
| **ORM** | Entity Framework Core | 8.0 | Database abstraction |
| **Authentication** | JWT Bearer Tokens | - | Secure API access |
| **OAuth** | Google OAuth 2.0 | - | Social authentication |
| **API Docs** | Swagger/OpenAPI | 8.1.4 | API documentation |
| **Serialization** | Newtonsoft.Json | 13.0.3 | JSON processing |
| **Health Checks** | AspNetCore.HealthChecks | - | Service monitoring |

### Client Technologies

| Component | Technology | Version | Purpose |
|-----------|-----------|---------|---------|
| **Engine** | Unreal Engine | 5.6 | Game engine |
| **Language** | C++ | 20 | Client programming |
| **UI Framework** | UMG (Unreal Motion Graphics) | - | User interface |
| **VFX** | Niagara | - | Visual effects |
| **Input** | Enhanced Input System | - | Input handling |
| **Networking** | HTTP Module | - | REST API communication |
| **Serialization** | UE5 JSON Utilities | - | JSON parsing |

---

## Codebase Statistics

### C# Backend Statistics

```
Total C# Files:        169
Controllers:            17
Services:               29
Entity Models:         ~50
DTOs:                  ~29
Enums:                   8
Data/Context:            4
Migrations:              3
Health/Config:           2
```

**Lines of Code (Estimated)**:
- Backend C# Code: ~15,000 - 20,000 lines
- Configuration Files: ~500 lines
- API Documentation: ~2,000 lines

### C++ Client Statistics

```
Total C++ Files:       ~75 (.cpp + .h)
Subsystems:              6
Components:              4
Actors:                 12
UI Widgets:             14
UI Framework/Logic:      6
World Management:        4
Game Modes/Controllers:  4
Utilities & Types:       5
```

**Lines of Code (Estimated)**:
- Client C++ Code: ~8,000 - 12,000 lines
- Blueprint Classes: ~50 assets
- UI Widgets: ~20 UMG widgets

### Documentation Statistics

```
Total Documentation Files: 70+
Architecture Docs:         15
System Docs:              25
UI/UX Docs:                9
Gameplay Docs:             5
Reports:                  10
README Files:              6+
```

**Documentation Lines**: ~20,000+ lines of markdown documentation

---

## Architecture Components

### High-Level Architecture

```
┌─────────────────┐
│  Game Client    │
│  (UE5.6 C++)    │
└────────┬────────┘
         │ HTTP/REST
         │ JWT Token
         ▼
┌─────────────────┐
│  Backend API    │
│  (ASP.NET C#8)  │
└────────┬────────┘
         │ EF Core
         ▼
┌─────────────────┐
│   PostgreSQL    │
│   Database      │
└─────────────────┘
```

### Mirror Architecture Pattern

Each backend service has a corresponding UE5 subsystem:

| Backend (C#) | Client (C++) | Purpose |
|--------------|--------------|---------|
| `AuthController` | `EchoesAuthSubsystem` | Authentication |
| `CharacterController` | `EchoesIdentitySubsystem` | Character management |
| `InventoryController` | `EchoesInventorySubsystem` | Inventory operations |
| `ShipController` | `EchoesShipStatsSubsystem` | Ship statistics |
| `UniverseController` | `EchoesWorldGenerator` | Universe generation |
| `ServerManagementController` | `EchoesServerManagementSubsystem` | Server coordination |

---

## Backend (C# / ASP.NET Core)

### Project Structure

```
EchoesBackend_v1/
├── Controllers/              # 17 API Controllers
│   ├── Auth/
│   │   ├── AuthController.cs
│   │   ├── GoogleAuthController.cs
│   │   └── TwoFactorAuthController.cs
│   ├── Character/
│   │   ├── CharacterController.cs
│   │   └── CharacterSelectionController.cs
│   ├── Inventory/
│   │   ├── InventoryController.cs
│   │   └── ContainerController.cs
│   ├── Ship/
│   │   ├── ShipController.cs
│   │   └── ShipFittingController.cs
│   ├── Universe/
│   │   ├── UniverseController.cs
│   │   └── UniverseCustomizationController.cs
│   └── ServerManagementController.cs
│
├── Services/                 # 29 Business Logic Services
│   ├── Auth/
│   │   ├── AuthService.cs
│   │   ├── GoogleAuthService.cs
│   │   ├── TwoFactorAuthService.cs
│   │   └── JwtTokenService.cs
│   ├── Inventory/
│   │   ├── InventoryService.cs
│   │   ├── ContainerService.cs
│   │   ├── InventoryMapper.cs
│   │   └── InventoryOperationsService.cs
│   ├── Ship/
│   │   ├── ShipFittingService.cs
│   │   └── IShipFittingService.cs
│   ├── UniverseGeneration/
│   │   ├── UniverseGenerationService.cs
│   │   ├── UniverseGenerator.cs
│   │   ├── BackgroundGenerationService.cs
│   │   ├── SeedManager.cs
│   │   ├── ProgressTracker.cs
│   │   └── StaticDataLoader.cs
│   ├── Email/
│   │   ├── EmailService.cs
│   │   └── IEmailService.cs
│   └── ServerRequests/
│       └── GameServerService.cs
│
├── Models/                   # Data Models
│   ├── Entities/            # 50+ Database Entities
│   │   ├── Account/
│   │   │   ├── Account.cs
│   │   │   ├── AccountSession.cs
│   │   │   └── Character.cs
│   │   ├── Ship/
│   │   │   ├── Ship.cs
│   │   │   └── ShipFitting.cs
│   │   ├── Inventory/
│   │   │   ├── Inventory.cs
│   │   │   ├── InventoryItem.cs
│   │   │   └── Container.cs
│   │   ├── Universe/
│   │   │   ├── Universe.cs
│   │   │   ├── SolarSystem.cs
│   │   │   ├── Planet.cs
│   │   │   ├── Station.cs
│   │   │   └── Stargate.cs
│   │   └── Shop/
│   │       ├── ShopItem.cs
│   │       └── AssetType.cs
│   │
│   ├── DTOs/                # Data Transfer Objects
│   │   ├── Auth/
│   │   ├── Character/
│   │   ├── Inventory/
│   │   ├── Ship/
│   │   └── Universe/
│   │
│   └── Enums/               # 8 Enumeration Types
│       ├── AccountEnums.cs
│       ├── InventoryEnums.cs
│       ├── ItemEnums.cs
│       ├── PlayerEnums.cs
│       └── UniverseEnums.cs
│
├── Data/                    # Database Context
│   ├── DatabaseContext.cs
│   ├── SeedData.cs
│   └── DesignTimeDbContextFactory.cs
│
├── Migrations/              # EF Core Migrations
│   ├── 20240101_Initial.cs
│   ├── 20240115_InventorySystem.cs
│   └── 20240201_UniverseGeneration.cs
│
├── Health/                  # Health Checks
│   └── DatabaseHealthCheck.cs
│
└── Program.cs              # Application Entry Point
```

### Key Backend Components

#### 1. Authentication System
- **JWT Token Service**: Token generation and validation
- **Google OAuth Integration**: Social authentication
- **Two-Factor Authentication**: Enhanced security
- **Password Hashing**: bcrypt-based secure password storage

#### 2. Character Management
- **Multi-Character Support**: Multiple characters per account
- **Character Creation**: Race, bloodline, appearance customization
- **Character Selection**: Active character management
- **Skill Training Queues**: Timed skill progression

#### 3. Inventory System
- **Volume-Based Storage**: Realistic cargo capacity (V = Σ Qty×Vol)
- **Container Management**: Nested container support
- **Item Stacking**: Stackable and singleton items
- **Ship Fitting**: Module installation and fitting management

#### 4. Universe Generation
- **Procedural Generation**: Seed-based universe creation
- **Customizable Universes**: Player-customizable parameters
- **Background Generation**: Async generation with progress tracking
- **Static Data Loading**: Efficient data management

#### 5. Game Server Management
- **Server Registration**: Dynamic server discovery
- **Heartbeat System**: Server health monitoring
- **Configuration Distribution**: Centralized config management
- **Load Balancing**: Server assignment based on load

---

## Client (C++ / Unreal Engine 5.6)

### Project Structure

```
Client/Echoes/Source/Echoes/
├── Core/
│   ├── Common/              # Shared Client/Server Code
│   │   ├── Networking/      # 6 Subsystems
│   │   │   ├── EchoesAuthSubsystem.h/cpp
│   │   │   ├── EchoesIdentitySubsystem.h/cpp
│   │   │   ├── EchoesInventorySubsystem.h/cpp
│   │   │   ├── EchoesShipStatsSubsystem.h/cpp
│   │   │   └── EchoesGameStateSubsystem.h/cpp
│   │   │
│   │   ├── Components/      # 4 Components
│   │   │   ├── EchoesInventoryComponent.h/cpp
│   │   │   └── EchoesShipMovementComponent.h/cpp
│   │   │
│   │   ├── Actor/           # 12 Game Actors
│   │   │   ├── StationActor.h/cpp
│   │   │   ├── PlanetActor.h/cpp
│   │   │   ├── StarActor.h/cpp
│   │   │   ├── MoonActor.h/cpp
│   │   │   ├── StargateActor.h/cpp
│   │   │   ├── WormholeActor.h/cpp
│   │   │   ├── AnomalyActor.h/cpp
│   │   │   ├── AsteroidBeltActor.h/cpp
│   │   │   └── EchoesItemActor.h/cpp
│   │   │
│   │   ├── World/           # World Generation
│   │   │   ├── EchoesWorldGenerator.h/cpp
│   │   │   └── EchoesJumpManager.h/cpp
│   │   │
│   │   ├── Types/           # Data Structures
│   │   │   ├── EchoesShipTypes.h
│   │   │   ├── EchoesItemDefinitions.h
│   │   │   ├── EchoesWorldVisualTypes.h
│   │   │   └── EchoesCharacterData.h
│   │   │
│   │   └── Interfaces/      # Interfaces
│   │       └── EchoesInteractableInterface.h/cpp
│   │
│   ├── Server/              # Server-Only Code
│   │   ├── GameModes/
│   │   │   └── EchoesServerGameMode.h/cpp
│   │   └── Managers/
│   │       └── EchoesServerManagementSubsystem.h/cpp
│   │
│   └── Client/              # Client-Only Code
│       └── Pawns/
│           └── EchoesShipPawn.h/cpp
│
├── UI/                      # User Interface
│   ├── Widgets/             # 14 UMG Widgets
│   │   ├── EchoesLoginWidget.h/cpp
│   │   ├── EchoesPreloadWidget.h/cpp
│   │   ├── EchoesCharacterSelectWidget.h/cpp
│   │   ├── EchoesInventoryWidget.h/cpp
│   │   ├── EchoesStationMenuWidget.h/cpp
│   │   ├── EchoesContextMenuWidget.h/cpp
│   │   └── EchoesQuantitySelectorWidget.h/cpp
│   │
│   ├── Framework/           # UI Framework
│   │   └── EchoesWindowBase.h/cpp
│   │
│   └── Logic/               # UI Logic
│       ├── EchoesInventoryItemObject.h/cpp
│       └── EchoesInventoryDragDrop.h/cpp
│
├── EchoesMenuGameMode.h/cpp        # Menu Game Mode
├── EchoesMenuPlayerController.h/cpp # Menu Controller
├── Echoes.h                         # Module Header
└── Echoes.Build.cs                  # Build Configuration
```

### Key Client Components

#### 1. Subsystem Architecture

**EchoesAuthSubsystem** (GameInstance)
- User login and registration
- JWT token management
- Character connection flow
- Session persistence

**EchoesIdentitySubsystem** (GameInstance)
- Character list retrieval
- Active character management
- Character data caching

**EchoesInventorySubsystem** (World)
- Inventory queries and updates
- Item movement operations
- Container management
- Volume calculations

**EchoesShipStatsSubsystem** (World)
- Ship statistics retrieval
- Fitting data management
- Mass and performance calculations

**EchoesGameStateSubsystem** (World)
- Solar system state
- Nearby entities tracking
- World synchronization

**EchoesServerManagementSubsystem** (GameInstance)
- Server registration
- Heartbeat transmission
- Configuration synchronization

#### 2. Actor System

**Celestial Objects**:
- `AStarActor`: Stars with corona effects
- `APlanetActor`: Planets with rotation
- `AMoonActor`: Moons orbiting planets
- `AAnomalyActor`: Exploration sites
- `AAsteroidBeltActor`: Mining locations

**Infrastructure**:
- `AStationActor`: Player-accessible stations
- `AStargateActor`: Jump gate connections
- `AWormholeActor`: Dynamic connections

**Items**:
- `AEchoesItemActor`: Physical item representation

#### 3. Component System

**EchoesInventoryComponent**:
- Attached to actors with storage
- Volume capacity management
- Item add/remove operations
- Replication support

**EchoesShipMovementComponent**:
- Physics-based ship movement
- Thrust and damping
- Velocity calculations
- Network replication

#### 4. UI System

**Menu Flow**:
```
Preload → Login → Character Select → Game World
```

**In-Game UI**:
- Station Menu (services access)
- Inventory Window (drag-and-drop)
- Context Menus (right-click actions)
- Quantity Selectors (item splits)

**Window System Features**:
- Draggable windows
- Resizable windows
- Z-order management
- Edge snapping

---

## Build Systems

### ASP.NET Core Build (Echoes.API.csproj)

```xml
<Project Sdk="Microsoft.NET.Sdk.Web">
  <PropertyGroup>
    <TargetFramework>net8.0</TargetFramework>
    <Nullable>enable</Nullable>
    <ImplicitUsings>enable</ImplicitUsings>
  </PropertyGroup>

  <ItemGroup>
    <PackageReference Include="Microsoft.EntityFrameworkCore" Version="8.0.0" />
    <PackageReference Include="Npgsql.EntityFrameworkCore.PostgreSQL" Version="8.0.0" />
    <PackageReference Include="Swashbuckle.AspNetCore" Version="8.1.4" />
    <PackageReference Include="Google.Apis.Auth" Version="1.68.0" />
    <PackageReference Include="Newtonsoft.Json" Version="13.0.3" />
  </ItemGroup>
</Project>
```

**Build Commands**:
```bash
# Restore dependencies
dotnet restore

# Build project
dotnet build --configuration Release

# Run migrations
dotnet ef database update

# Run application
dotnet run

# Run tests
dotnet test
```

### Unreal Engine Build (Echoes.Build.cs)

```csharp
public class Echoes : ModuleRules
{
    public Echoes(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "EnhancedInput",
            "HTTP",
            "Json",
            "JsonUtilities",
            "Niagara",
            "UMG",
            "Slate",
            "SlateCore"
        });

        // Auto-discover include paths
        AddAllSubdirectories(PublicIncludePaths, ModuleDirectory + "/Core");
        AddAllSubdirectories(PublicIncludePaths, ModuleDirectory + "/UI");
    }
}
```

**Build Commands**:
```bash
# Generate project files
./GenerateProjectFiles.sh  # Linux/Mac
GenerateProjectFiles.bat   # Windows

# Build from command line
RunUAT BuildCookRun -project=Echoes.uproject \
  -platform=Win64 -configuration=Development

# Package for distribution
RunUAT BuildCookRun -project=Echoes.uproject \
  -platform=Win64 -configuration=Shipping \
  -build -cook -stage -pak -archive
```

---

## Database Schema

### Core Tables

**Account Management** (5 tables):
- `Accounts` - User accounts
- `AccountSessions` - Active sessions
- `Characters` - Character profiles
- `CharacterSkills` - Skill training
- `CharacterWallets` - ISK balances

**Inventory System** (5 tables):
- `Inventories` - Container definitions
- `InventoryItems` - Item instances
- `Containers` - Nested containers
- `ShipFittings` - Ship loadouts
- `AssetTypes` - Item definitions

**Universe Data** (15+ tables):
- `Universes` - Universe instances
- `Regions` - Universe regions
- `Constellations` - Region divisions
- `SolarSystems` - Star systems
- `Planets` - Planetary bodies
- `Moons` - Planet moons
- `Stargates` - Jump gates
- `Stations` - Player stations
- `Wormholes` - Dynamic connections
- `Anomalies` - Exploration sites
- `AsteroidBelts` - Mining locations

**Shop System** (3 tables):
- `ShopItems` - Available items
- `ShopCategories` - Item categories
- `Transactions` - Purchase history

**Total Tables**: ~35 tables
**Database Size**: Small (< 100MB for dev data)
**Indexing**: Primary keys, foreign keys, frequently queried columns

---

## Development Tools

### Backend Tools

```bash
# Entity Framework CLI
dotnet tool install --global dotnet-ef

# Create migration
dotnet ef migrations add MigrationName

# Apply migrations
dotnet ef database update

# Generate SQL script
dotnet ef migrations script

# Swagger UI
http://localhost:5116/swagger
```

### Client Tools

```bash
# Unreal Engine Editor
UnrealEditor.exe Echoes.uproject

# Content Browser
# - Access all Blueprint assets
# - Create widgets, actors, materials

# Live Coding
# - Hot-reload C++ changes without restart

# Visual Studio / Rider
# - Full C++ debugging support
# - IntelliSense / code completion
```

### Version Control

```bash
# GitHub repository
https://github.com/SkinXed/EchoesBackend_v1

# Branch structure
main                    # Production-ready code
develop                 # Development branch
feature/*              # Feature branches
bugfix/*               # Bug fix branches
```

---

## Key Features

### Implemented Features ✅

1. **Authentication System**
   - User registration and login
   - JWT token authentication
   - Google OAuth integration
   - Two-factor authentication
   - Session management

2. **Character System**
   - Character creation with customization
   - Multiple characters per account
   - Character selection
   - Character persistence

3. **Inventory System**
   - Volume-based storage (V = Σ Qty×Vol)
   - Container management
   - Item stacking (stackable vs singleton)
   - Ship fitting
   - Drag-and-drop UI

4. **Universe Generation**
   - Procedural seed-based generation
   - Customizable parameters
   - Background generation with progress
   - Regions, constellations, systems
   - Planets, moons, stars, stargates

5. **Ship Physics**
   - Authentic UE5 physics (AddForce)
   - Mass-based calculations
   - Velocity and acceleration
   - PD controller for rotation
   - Warp mechanics

6. **UI Framework**
   - Menu system (Preload → Login → Character Select)
   - Station menu interface
   - Inventory windows with drag-drop
   - Context menus
   - Window management (drag, resize, snap)

7. **Server Infrastructure**
   - Server registration and discovery
   - Heartbeat monitoring
   - Configuration distribution
   - Health checks

### In Progress 🚧

1. **HUD System** (35% complete)
   - Ship status display ✅
   - Overview panel (partial)
   - 3D tactical radar (planned)
   - Multi-target system (planned)

2. **Fitting System** (15% complete)
   - Mass calculation ✅
   - Module effects (in progress)
   - Fitting UI (planned)
   - Module activation (planned)

### Planned 📋

1. **Combat System**
   - Directional shields
   - Weapon systems
   - Damage application
   - Electronic warfare

2. **Industrial Loop**
   - Mining asteroids
   - Ore refining
   - Manufacturing
   - Market system

3. **Social Systems**
   - Corporations
   - Alliances
   - Fleet mechanics
   - Chat system

---

## Performance Metrics

### Backend API

| Metric | Target | Current Status |
|--------|--------|----------------|
| API Response Time (P95) | < 100ms | ✅ ~50-80ms |
| Database Query Time (P95) | < 50ms | ✅ ~20-40ms |
| Concurrent Users | 100+ | ⚠️ Not tested |
| Request Rate | 1000 req/s | ⚠️ Not tested |

### Client Performance

| Metric | Target | Current Status |
|--------|--------|----------------|
| FPS (50+ entities) | > 60 FPS | ✅ 60-120 FPS |
| Memory Usage | < 2GB | ✅ ~1.2GB |
| Load Time | < 10s | ✅ ~5-8s |
| Network Latency | < 150ms | ✅ ~50-100ms |

---

## Security Features

### Backend Security

1. **Authentication**
   - JWT Bearer tokens with expiration
   - bcrypt password hashing
   - Token refresh mechanism
   - Rate limiting on auth endpoints

2. **Authorization**
   - Role-based access control
   - Resource ownership validation
   - JWT claims verification

3. **Input Validation**
   - DTO validation attributes
   - SQL injection prevention (EF Core parameterization)
   - XSS protection
   - CORS configuration

4. **Data Protection**
   - HTTPS enforcement (production)
   - Secure connection strings (environment variables)
   - No secrets in code
   - Database connection pooling

### Client Security

1. **Network Security**
   - JWT token in HTTP headers
   - Secure token storage
   - HTTPS for API calls

2. **Server Authority**
   - Server-authoritative game state
   - Client prediction with correction
   - Anti-cheat validation

---

## Development Standards

### Code Style

**C# / Backend**:
- PascalCase for classes, methods, properties
- camelCase for local variables
- Async/await for asynchronous operations
- Dependency injection for services
- Interface-based design (I{Service})

**C++ / Client**:
- PascalCase for classes (AEchoesActor, UEchoesComponent)
- Unreal naming prefixes (A for Actor, U for Object, F for struct)
- Function prefixes: `Server_`, `Client_`, `Common_`
- Smart pointers (TWeakPtr, TSharedPtr)
- UPROPERTY for replication and Blueprint exposure

### Git Workflow

```
1. Create feature branch from main
2. Implement changes with atomic commits
3. Write/update tests
4. Update documentation
5. Create pull request
6. Code review and approval
7. Merge to main
```

---

## Contact & Support

- **Repository**: https://github.com/SkinXed/EchoesBackend_v1
- **Documentation**: See `/docs` folder
- **Issues**: Use GitHub issue templates
- **Architecture**: See `docs/architecture/CORE_ARCHITECTURE_BIBLE.md`

---

**Document Version**: 1.0  
**Last Updated**: 2026-02-03  
**Maintained By**: Echoes Development Team
