# Echoes - Unreal Engine 5 Client

[![Unreal Engine](https://img.shields.io/badge/Unreal-5.6-313131)](https://www.unrealengine.com/)
[![C++](https://img.shields.io/badge/C++-17-00599C)](https://isocpp.org/)
[![License](https://img.shields.io/badge/License-Proprietary-red)]()

**Echoes** is an EVE Online-inspired MMO client built on Unreal Engine 5.6 with C++17. This client connects to the ASP.NET Core backend and provides an immersive space simulation experience.

---

## 📋 Table of Contents

- [Overview](#overview)
- [Getting Started](#getting-started)
- [Project Structure](#project-structure)
- [Documentation](#documentation)
- [Architecture](#architecture)
- [Development](#development)
- [Building](#building)
- [Contributing](#contributing)

---

## 🎮 Overview

The Echoes UE5 client is a multiplayer space simulation game featuring:

- **Authentic Physics**: Real Newtonian physics with PD controllers for ship movement
- **MMO Architecture**: Client-server model with server authority
- **EVE-Inspired Gameplay**: Ship fitting, inventory management, market system
- **Advanced UI**: Draggable windows, inventory system, station services
- **Networked Gameplay**: HTTP API communication with JWT authentication
- **Procedural Universe**: Dynamic galaxy generation with stars, planets, and stargates

---

## 🚀 Getting Started

### Prerequisites

- **Unreal Engine 5.6** or later
- **Visual Studio 2022** with C++ desktop development workload
- **Git** for version control
- **Backend API** running on `http://localhost:5116` (see backend repository)

### Quick Start

1. **Clone the repository:**
   ```bash
   git clone https://github.com/SkinXed/EchoesBackend_v1.git
   cd EchoesBackend_v1/Client/Echoes
   ```

2. **Generate project files:**
   ```bash
   # Right-click on Echoes.uproject → Generate Visual Studio project files
   ```

3. **Open the project:**
   ```bash
   # Double-click Echoes.uproject to open in Unreal Editor
   ```

4. **Configure Backend URL:**
   - Edit `Config/DefaultGame.ini`
   - Set `ApiBaseUrl` to your backend API endpoint

5. **Play in Editor:**
   - Press `Alt+P` or click the Play button

For detailed setup instructions, see [Quick Start Guide](docs/guides/QUICK_START_GUIDE.md)

---

## 📁 Project Structure

```
Echoes/
├── Content/                    # Unreal assets
│   ├── Project/               # Game-specific assets
│   │   ├── Map/              # Level maps
│   │   ├── UI/               # UMG widgets
│   │   └── Materials/        # Visual materials
│   └── ThirdParty/           # External assets
│
├── Source/Echoes/             # C++ source code
│   ├── Core/                 # Core systems
│   │   ├── Common/          # Shared client/server code
│   │   │   ├── Actors/      # Game actors (Stargate, Planet, etc.)
│   │   │   ├── Components/  # Reusable components
│   │   │   ├── Interfaces/  # Abstract interfaces
│   │   │   ├── Networking/  # Subsystems (Auth, Inventory, etc.)
│   │   │   ├── Types/       # Data structures and enums
│   │   │   └── World/       # World generation
│   │   │
│   │   ├── Server/          # Server-only code
│   │   │   ├── GameModes/   # Server game modes
│   │   │   ├── Managers/    # Server managers
│   │   │   └── Validation/  # Anti-cheat validation
│   │   │
│   │   └── Client/          # Client-only code
│   │       ├── Pawns/       # Player ship pawns
│   │       ├── Controllers/ # Player controllers
│   │       └── Visuals/     # Visual effects
│   │
│   └── UI/                  # User interface
│       ├── Widgets/         # UMG widgets
│       ├── Framework/       # UI base classes
│       └── Logic/           # UI logic (drag & drop, etc.)
│
├── docs/                     # 📚 Documentation
│   ├── guides/              # Getting started guides
│   ├── systems/             # System documentation
│   ├── architecture/        # Architecture documentation
│   ├── ui/                  # UI/UX documentation
│   └── world/               # World generation docs
│
├── Config/                   # Configuration files
├── Intermediate/             # Build artifacts (gitignored)
├── Saved/                    # Saved data (gitignored)
├── Plugins/                  # UE5 plugins
└── Echoes.uproject          # Unreal project file
```

---

## 📚 Documentation

### Core Documentation

- **[Quick Start Guide](docs/guides/QUICK_START_GUIDE.md)** - Get up and running quickly
- **[Architecture Overview](docs/architecture/ARCHITECTURAL_IMPROVEMENTS.md)** - System architecture
- **[Network Security](docs/architecture/NETWORK_SECURITY.md)** - Security best practices
- **[Server Management](docs/architecture/SERVER_MANAGEMENT_README.md)** - Dedicated server setup

### System Documentation

#### Inventory System
- **[Inventory Component](docs/systems/INVENTORY_COMPONENT_IMPLEMENTATION.md)** - Core inventory logic
- **[Inventory UI](docs/systems/INVENTORY_UI_IMPLEMENTATION.md)** - User interface
- **[Inventory Summary](docs/systems/COMPLETE_INVENTORY_SYSTEM_SUMMARY.md)** - Complete overview
- **[Item Definitions](docs/systems/ITEM_DEFINITIONS_GUIDE.md)** - Item type definitions
- **[Item Actor Guide](docs/systems/ITEM_ACTOR_GUIDE.md)** - World item actors

#### Ship Systems
- **[Ship Movement System](docs/systems/SHIP_MOVEMENT_SYSTEM.md)** - Physics and movement

#### UI/UX
- **[Inventory UI Quick Reference](docs/systems/INVENTORY_UI_QUICK_REFERENCE.md)** - UI reference
- **[Inventory Entry Widget Guide](docs/systems/INVENTORY_ENTRY_WIDGET_GUIDE.md)** - Widget guide

### World Generation
- **[World Generator README](docs/world/WORLD_GENERATOR_README.md)** - World generation overview
- **[World Generator Implementation](docs/world/WORLD_GENERATOR_IMPLEMENTATION_SUMMARY.md)** - Implementation details

---

## 🏛️ Architecture

### Design Principles

1. **"Postgres is Truth"**
   - PostgreSQL backend is the single source of truth
   - Client displays, server validates, backend calculates
   - Never trust client data

2. **Function Naming Convention**
   - **`Server_`** - Server-authoritative functions (replicated to clients)
   - **`Client_`** - Client-only functions (visual feedback)
   - **`Common_`** - Shared functions (both client and server)

3. **Mirror Architecture**
   - Each backend API controller has a corresponding UE5 subsystem
   - Example: `AuthController.cs` ↔ `UEchoesAuthSubsystem`

4. **Client-Server Model**
   - **Server**: Authority, validation, persistent state
   - **Client**: Prediction, input handling, visual feedback

### Key Subsystems

| Subsystem | Purpose | Location |
|-----------|---------|----------|
| **EchoesAuthSubsystem** | Authentication & session management | `Core/Common/Networking/` |
| **EchoesIdentitySubsystem** | Character management | `Core/Common/Networking/` |
| **EchoesInventorySubsystem** | Inventory operations | `Core/Common/Networking/` |
| **EchoesShipStatsSubsystem** | Ship stats and fitting | `Core/Common/Networking/` |
| **EchoesGameStateSubsystem** | Global game state | `Core/Common/Types/` |

### Component Architecture

```
Player Ship (APawn)
├── EchoesShipMovementComponent     # Physics movement
├── EchoesInventoryComponent        # Ship cargo hold
└── StaticMeshComponent             # Visual representation
```

---

## 🛠️ Development

### Code Style

- Follow Unreal Engine coding standards
- Use `UPROPERTY()` and `UFUNCTION()` macros appropriately
- Prefix member variables with appropriate scope:
  - `b` for booleans (e.g., `bIsInitialized`)
  - `I` for interfaces (e.g., `IEchoesInteractable`)
  - `F` for structs (e.g., `FCharacterInfo`)
  - `U` for UObject classes (e.g., `UEchoesAuthSubsystem`)
  - `A` for Actor classes (e.g., `APlanetActor`)

### Logging

Use UE_LOG with appropriate categories:
```cpp
UE_LOG(LogTemp, Log, TEXT("Normal log message"));
UE_LOG(LogTemp, Warning, TEXT("Warning: %s"), *VariableName);
UE_LOG(LogTemp, Error, TEXT("Error occurred!"));
```

### Network Replication

- Use `UPROPERTY(Replicated)` for replicated variables
- Implement `GetLifetimeReplicatedProps()` for replication setup
- Use Server/Client RPC naming: `Server_FunctionName` and `Client_FunctionName`

### HTTP API Calls

Example HTTP request to backend:
```cpp
UEchoesAuthSubsystem* AuthSubsystem = GetGameInstance()->GetSubsystem<UEchoesAuthSubsystem>();
FString Token = AuthSubsystem->GetAuthToken();

TSharedRef<IHttpRequest> Request = FHttpModule::Get().CreateRequest();
Request->SetURL(ApiBaseUrl + "/api/character/list");
Request->SetVerb("GET");
Request->SetHeader("Authorization", "Bearer " + Token);
Request->SetHeader("Content-Type", "application/json");
Request->OnProcessRequestComplete().BindUObject(this, &UMyClass::OnResponseReceived);
Request->ProcessRequest();
```

---

## 🔨 Building

### Editor Build

1. Open `Echoes.uproject` in Unreal Editor
2. Build → Compile (Ctrl+Alt+F11)

### Standalone Build

1. Open Unreal Editor
2. File → Package Project → Windows (64-bit)
3. Select output directory
4. Wait for packaging to complete

### Dedicated Server Build

1. Open project in Visual Studio
2. Set solution configuration to "Development Server"
3. Build solution
4. Run executable with `-log` flag

For more details, see [Server Management](docs/architecture/SERVER_MANAGEMENT_README.md)

---

## 🧪 Testing

### Play in Editor (PIE)

- **Single Player**: Press `Alt+P`
- **Multiplayer**: Press `Alt+P` with multiple PIE instances
  - Edit → Editor Preferences → Play → Number of Players

### Console Commands

- `stat fps` - Show FPS counter
- `stat unit` - Show frame time breakdown
- `showdebug net` - Show network stats
- `netprofile` - Network profiling
- `r.ScreenPercentage [value]` - Adjust resolution scale

---

## 📈 Performance

### Target Performance

- **Client FPS**: 60+ FPS with 50+ entities
- **Network Latency**: < 150ms server-to-client
- **Memory Usage**: < 4GB RAM
- **Load Time**: < 10 seconds to load into game

### Optimization Tips

1. Use object pooling for frequently spawned actors
2. Batch RPC calls - minimize network traffic
3. Use relevancy filtering for replication
4. Profile with Unreal Insights (`UnrealInsights.exe`)

---

## 🤝 Contributing

### Workflow

1. Create a feature branch from `main`
2. Make your changes following code style
3. Test your changes thoroughly
4. Submit a pull request with detailed description

### Commit Message Format

```
[Category] Brief description

Detailed explanation if necessary

- Related files changed
- Impact on systems
```

**Categories**: `[Feature]`, `[Fix]`, `[Refactor]`, `[Docs]`, `[Test]`, `[Chore]`

---

## 🔐 Security

### Best Practices

1. **Never hardcode secrets** - Use environment variables or secure vaults
2. **Validate all inputs** - Client, server, and backend
3. **Use HTTPS** - Production must use encrypted connections
4. **Implement rate limiting** - Prevent API abuse
5. **Server authority** - Never trust client data

See [Network Security](docs/architecture/NETWORK_SECURITY.md) for details.

---

## 📞 Support

- **Documentation**: See [docs/](docs/) directory
- **Issues**: Report bugs via GitHub Issues
- **Backend API**: See main repository README

---

## 📄 License

Proprietary - All rights reserved

---

## 🏆 Credits

**Development Team**: Echoes Development Team
**Engine**: Unreal Engine 5.6 (Epic Games)
**Inspired by**: EVE Online (CCP Games)

---

**Last Updated**: 2026-02-01  
**Version**: 1.0.0  
**Status**: Active Development
