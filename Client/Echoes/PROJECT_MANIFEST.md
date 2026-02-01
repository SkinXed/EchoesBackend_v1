# Echoes UE5 Client - Project Manifest

**Version**: 1.0.0  
**Engine**: Unreal Engine 5.6  
**Language**: C++17  
**Date**: 2026-02-01  
**Status**: Active Development

---

## 📋 Executive Summary

Echoes is an EVE Online-inspired MMO client built on Unreal Engine 5.6. The project implements a physics-based space simulation with client-server architecture, HTTP API backend communication, and comprehensive game systems including inventory, ship movement, and world generation.

---

## 🎯 Project Goals

### Primary Objectives

1. **Authentic Space Simulation** - Newtonian physics with realistic ship movement
2. **EVE-Inspired Gameplay** - Ship fitting, inventory management, market economy
3. **Scalable MMO Architecture** - Client-server model with backend persistence
4. **Modern UE5 Technology** - Leverage UE5.6 features and capabilities
5. **Comprehensive Documentation** - Well-documented codebase for team collaboration

### Key Success Metrics

- 60+ FPS with 50+ entities visible
- < 150ms network latency
- < 4GB RAM usage
- < 10 second load times
- 99.9% uptime for backend API

---

## 🏗️ System Architecture

### High-Level Architecture

```
┌─────────────────────────────────────────────────────────┐
│                    UE5 Client                           │
│  ┌──────────────┐  ┌──────────────┐  ┌──────────────┐ │
│  │   UI Layer   │  │  Game Logic  │  │   Rendering  │ │
│  │   Widgets    │  │  Components  │  │   Visuals    │ │
│  └──────┬───────┘  └──────┬───────┘  └──────────────┘ │
│         │                  │                            │
│  ┌──────┴──────────────────┴──────────────┐            │
│  │        Subsystems Layer                 │            │
│  │  (Auth, Identity, Inventory, etc.)      │            │
│  └──────────────────┬──────────────────────┘            │
│                     │ HTTP REST API                     │
└─────────────────────┼───────────────────────────────────┘
                      │
┌─────────────────────┼───────────────────────────────────┐
│                     │  ASP.NET Core Backend             │
│  ┌──────────────────┴──────────────────────┐            │
│  │         API Controllers                  │            │
│  │  (Auth, Character, Inventory, Ship)      │            │
│  └──────────────────┬───────────────────────┘            │
│                     │                                    │
│  ┌──────────────────┴───────────────────────┐           │
│  │      PostgreSQL Database                 │           │
│  │      (Single Source of Truth)            │           │
│  └──────────────────────────────────────────┘           │
└─────────────────────────────────────────────────────────┘
```

### Design Principles

#### 1. "Postgres is Truth"

The PostgreSQL database is the **single source of truth**. All persistent game state resides here.

- **Backend API**: Calculates and persists state
- **Server**: Validates actions and replicates
- **Client**: Displays state and handles input

#### 2. Mirror Architecture

Each backend controller has a corresponding UE5 subsystem:

| Backend | Frontend | Purpose |
|---------|----------|---------|
| `AuthController.cs` | `UEchoesAuthSubsystem` | Authentication |
| `CharacterController.cs` | `UEchoesIdentitySubsystem` | Character management |
| `InventoryController.cs` | `UEchoesInventorySubsystem` | Inventory |
| `ShipController.cs` | `UEchoesShipStatsSubsystem` | Ship stats |

#### 3. Function Naming Convention

**Mandatory prefixes for all functions:**

- `Server_` - Server-authoritative RPC
- `Client_` - Client-only RPC
- `Common_` - Shared utility functions

#### 4. Security First

- Never trust client data
- All API calls require JWT authentication
- Server validates all actions
- Input validation at every layer

---

## 📂 Project Structure

### Directory Layout

```
Echoes/
├── Config/                     # Configuration files
│   ├── DefaultEngine.ini      # Engine configuration
│   ├── DefaultGame.ini        # Game configuration
│   └── DefaultInput.ini       # Input mappings
│
├── Content/                    # Unreal assets
│   ├── Project/               # Game-specific content
│   │   ├── Map/              # Level maps
│   │   │   ├── EntryMap      # Login screen
│   │   │   ├── CharacterSelectMap  # Character selection
│   │   │   └── GalaxyMap     # Main game world
│   │   ├── UI/               # UMG widgets
│   │   ├── Materials/        # Visual materials
│   │   ├── Meshes/           # Static/skeletal meshes
│   │   └── Blueprints/       # Blueprint assets
│   └── ThirdParty/           # External assets
│
├── Source/Echoes/             # C++ source code
│   ├── Echoes.h              # Module header
│   ├── Echoes.cpp            # Module implementation
│   ├── Echoes.Build.cs       # Build configuration
│   │
│   ├── Core/                 # Core game systems
│   │   ├── Common/          # Shared client/server
│   │   │   ├── Actors/      # Game actors
│   │   │   ├── Components/  # Reusable components
│   │   │   ├── Interfaces/  # Abstract interfaces
│   │   │   ├── Networking/  # Subsystems
│   │   │   ├── Types/       # Data structures
│   │   │   └── World/       # World generation
│   │   │
│   │   ├── Server/          # Server-only code
│   │   │   ├── GameModes/   # Server game modes
│   │   │   ├── Managers/    # Server managers
│   │   │   └── Validation/  # Anti-cheat
│   │   │
│   │   └── Client/          # Client-only code
│   │       ├── Pawns/       # Player pawns
│   │       ├── Controllers/ # Player controllers
│   │       └── Visuals/     # Visual effects
│   │
│   └── UI/                  # User interface
│       ├── Widgets/         # UMG widgets
│       ├── Framework/       # UI base classes
│       └── Logic/           # UI logic
│
├── docs/                     # Documentation
│   ├── README.md            # Documentation index
│   ├── guides/              # Getting started
│   ├── systems/             # System docs
│   ├── architecture/        # Technical docs
│   ├── world/               # World generation
│   └── ui/                  # UI/UX docs
│
├── Plugins/                  # UE5 plugins
├── Intermediate/             # Build artifacts (gitignored)
├── Saved/                    # Saved data (gitignored)
├── README.md                # Project README
└── Echoes.uproject          # Unreal project file
```

---

## 🎮 Core Systems

### 1. Authentication System

**Status**: ✅ Complete

**Components**:
- `UEchoesAuthSubsystem` - JWT token management
- `UEchoesLoginWidget` - Login UI
- `UEchoesCharacterSelectWidget` - Character selection UI

**Features**:
- User registration and login
- JWT token authentication
- Token persistence across levels
- Automatic token refresh
- Logout functionality

**Documentation**: [Network Security](docs/architecture/NETWORK_SECURITY.md)

---

### 2. Inventory System

**Status**: ✅ Complete (90%)

**Components**:
- `UEchoesInventoryComponent` - Core inventory logic
- `UEchoesInventorySubsystem` - HTTP API communication
- `UEchoesInventoryWidget` - Inventory UI
- `UEchoesHangarWidget` - Ship hangar UI

**Features**:
- Volume-based inventory (Σ Qty × Volume ≤ Capacity)
- Client-side prediction with server validation
- Drag & drop UI
- Stack splitting
- Container management
- Ship cargo and station hangars
- Item tooltips

**Documentation**: 
- [Complete System Summary](docs/systems/COMPLETE_INVENTORY_SYSTEM_SUMMARY.md)
- [Component Implementation](docs/systems/INVENTORY_COMPONENT_IMPLEMENTATION.md)
- [UI Implementation](docs/systems/INVENTORY_UI_IMPLEMENTATION.md)

---

### 3. Ship Movement System

**Status**: ✅ Functional (70%)

**Components**:
- `UEchoesShipMovementComponent` - Physics movement
- `AEchoesShipPawn` - Player ship
- `AEchoesPlayerController` - Input handling

**Features**:
- Newtonian physics with damping
- PD controller for thrust vectoring
- Warp drive mechanics
- Angular velocity control
- Mass-based acceleration
- Orbit mechanics

**Documentation**: [Ship Movement System](docs/systems/SHIP_MOVEMENT_SYSTEM.md)

---

### 4. World Generation

**Status**: ✅ Functional (80%)

**Components**:
- `UEchoesWorldGenerator` - Procedural generation
- `AStargateActor` - Jump gates
- `APlanetActor` - Planetary bodies
- `AStarActor` - Star systems
- `AStationActor` - Space stations
- `AAsteroidBeltActor` - Asteroid fields

**Features**:
- Procedural galaxy generation
- Solar systems with planets and moons
- Stargate network
- Stations and structures
- Deterministic generation (seed-based)

**Documentation**:
- [World Generator README](docs/world/WORLD_GENERATOR_README.md)
- [Implementation Summary](docs/world/WORLD_GENERATOR_IMPLEMENTATION_SUMMARY.md)

---

### 5. UI/UX Framework

**Status**: ⚠️ In Progress (60%)

**Components**:
- `UEchoesWindowBase` - Base window class
- `UEchoesDragDropOperation` - Drag & drop
- Various widget classes

**Features**:
- Draggable windows
- Resizable panels
- Z-order management
- Window snapping
- Context menus
- Tooltips

**Planned**:
- Advanced window features
- HUD master layout
- Overview panel
- 3D tactical radar

---

### 6. Item System

**Status**: ✅ Functional (80%)

**Components**:
- `FEchoesItemDefinition` - Item data structure
- `UEchoesItemRegistry` - Item database
- `AEchoesItemActor` - World items

**Features**:
- Item type definitions
- Ships, modules, resources
- Item properties (mass, volume, effects)
- Stackability and singleton logic
- Item tooltips

**Documentation**:
- [Item Definitions Guide](docs/systems/ITEM_DEFINITIONS_GUIDE.md)
- [Item Actor Guide](docs/systems/ITEM_ACTOR_GUIDE.md)

---

### 7. Character System

**Status**: ✅ Complete

**Components**:
- `UEchoesIdentitySubsystem` - Character management
- `FCharacterInfo` - Character data structure
- `UEchoesCharacterSelectWidget` - Selection UI

**Features**:
- Character creation with race/bloodline
- Character selection
- Multiple characters per account
- Character persistence
- Character data caching

---

## 🔌 Subsystems

### UGameInstanceSubsystem Classes

All subsystems inherit from `UGameInstanceSubsystem` for persistence across levels.

| Subsystem | Purpose | Status |
|-----------|---------|--------|
| **UEchoesAuthSubsystem** | Authentication and JWT tokens | ✅ Complete |
| **UEchoesIdentitySubsystem** | Character management | ✅ Complete |
| **UEchoesInventorySubsystem** | Inventory HTTP API | ✅ Complete |
| **UEchoesShipStatsSubsystem** | Ship stats and fitting | ⚠️ In Progress |
| **UEchoesGameStateSubsystem** | Global game state | ⚠️ In Progress |
| **UServerManagementSubsystem** | Server lifecycle | ⚠️ In Progress |

---

## 🌐 Network Architecture

### HTTP API Communication

All backend communication uses HTTP REST API with JWT authentication:

```cpp
// Example HTTP request
TSharedRef<IHttpRequest> Request = FHttpModule::Get().CreateRequest();
Request->SetURL(ApiBaseUrl + "/api/inventory/move");
Request->SetVerb("POST");
Request->SetHeader("Authorization", "Bearer " + AuthToken);
Request->SetHeader("Content-Type", "application/json");
Request->SetContentAsString(JsonPayload);
Request->OnProcessRequestComplete().BindUObject(this, &UClass::OnResponse);
Request->ProcessRequest();
```

### Multiplayer Replication

For real-time multiplayer, UE5's built-in replication system is used:

- **Server Authority**: Server validates all actions
- **Client Prediction**: Clients predict for responsiveness
- **Replication**: State changes replicate to clients
- **RPC**: Remote procedure calls for client-server communication

---

## 🗺️ Game Flow

### Entry Pipeline

```
1. EntryMap (Login Screen)
   ↓
   User enters credentials
   ↓
   HTTP POST /api/auth/login
   ↓
   JWT token received and stored in AuthSubsystem
   ↓
2. CharacterSelectMap (Character Selection)
   ↓
   HTTP GET /api/character/list
   ↓
   Display character list
   ↓
   User selects/creates character
   ↓
3. GalaxyMap (Main Game World)
   ↓
   Server spawns player ship
   ↓
   Load character data from backend
   ↓
   Gameplay begins
```

### Level Transitions

- `EntryMap` → Login and authentication
- `CharacterSelectMap` → Character selection/creation
- `GalaxyMap` → Main game world
- Level transitions pass data via URL options: `?CharacterId=GUID`

---

## 🔧 Build Configuration

### Compilation Targets

- **Development Editor** - Development builds in editor
- **Development** - Standalone development client
- **Development Server** - Dedicated server build
- **Shipping** - Release builds

### Build Settings

```cpp
// Echoes.Build.cs
PublicDependencyModuleNames.AddRange(new string[] {
    "Core",
    "CoreUObject",
    "Engine",
    "InputCore",
    "HTTP",
    "Json",
    "JsonUtilities",
    "UMG",
    "Slate",
    "SlateCore"
});
```

### Configuration Files

- **DefaultEngine.ini** - Engine settings, rendering, physics
- **DefaultGame.ini** - Game settings, API URL, subsystem config
- **DefaultInput.ini** - Input mappings

---

## 🧪 Testing Strategy

### Unit Testing

- Component logic testing
- Subsystem API testing
- Data structure validation

### Integration Testing

- Full entry pipeline test
- Inventory operation test
- Ship movement test
- World generation test

### Performance Testing

- FPS benchmarks
- Memory profiling
- Network latency tests
- Load testing (concurrent users)

---

## 📊 Performance Targets

### Frame Rate

- **Target**: 60 FPS minimum
- **Conditions**: 50+ entities visible
- **Settings**: High graphics settings

### Network

- **Latency**: < 150ms server-to-client
- **Bandwidth**: < 100 KB/s per client
- **API Response**: < 100ms (P95)

### Memory

- **Client**: < 4GB RAM usage
- **Server**: < 8GB RAM per instance
- **Database**: Optimized queries < 50ms

### Load Times

- **Initial Load**: < 15 seconds
- **Level Transition**: < 10 seconds
- **Respawn**: < 3 seconds

---

## 🔐 Security

### Authentication

- JWT token-based authentication
- Secure token storage
- Automatic token refresh
- Logout functionality

### Authorization

- Server validates all actions
- Ownership checks before operations
- Role-based access control (planned)

### Data Validation

- Client input validation
- Server-side validation
- Backend validation
- Database constraints

### Anti-Cheat

- Server authority for game state
- Input validation and rate limiting
- Anomaly detection (planned)
- Replay system (planned)

---

## 📈 Development Status

### Completed Systems ✅

- Authentication system
- Character management
- Inventory system
- Ship movement
- World generation
- Basic UI framework

### In Progress 🚧

- Ship fitting system
- Combat system
- HUD framework
- Overview panel
- Tactical radar

### Planned 📋

- Market system
- Manufacturing
- Mining
- Corporation system
- Mission system

---

## 🚀 Deployment

### Client Deployment

1. Package project for target platform
2. Configure backend API URL
3. Distribute client executable
4. Auto-updater (planned)

### Server Deployment

1. Build server target
2. Configure environment variables
3. Deploy to cloud/dedicated hardware
4. Monitor and scale

---

## 📚 Documentation

### Available Documentation

- **[README](README.md)** - Project overview
- **[Documentation Index](docs/README.md)** - All documentation
- **[Quick Start Guide](docs/guides/QUICK_START_GUIDE.md)** - Getting started
- **[Architecture](docs/architecture/README.md)** - Technical architecture
- **[Systems](docs/systems/README.md)** - System documentation
- **[World Generation](docs/world/README.md)** - World generation
- **[Guides](docs/guides/README.md)** - Development guides

---

## 🤝 Contributing

### Development Workflow

1. Create feature branch
2. Implement changes
3. Follow naming conventions
4. Write tests
5. Update documentation
6. Submit pull request

### Code Standards

- Follow Unreal Engine conventions
- Use UPROPERTY/UFUNCTION macros
- Comment complex logic
- Write clear commit messages

---

## 📞 Support

- **Issues**: GitHub issue tracker
- **Documentation**: See docs/ directory
- **Backend**: See main repository

---

## 📄 License

Proprietary - All rights reserved

---

## 🏆 Credits

**Development Team**: Echoes Development Team  
**Engine**: Unreal Engine 5.6 (Epic Games)  
**Inspired by**: EVE Online (CCP Games)

---

**Document Version**: 1.0.0  
**Last Updated**: 2026-02-01  
**Status**: Living Document
