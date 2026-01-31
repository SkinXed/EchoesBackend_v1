# Echoes MMO Backend - Project Hub

[![.NET](https://img.shields.io/badge/.NET-8.0-512BD4)](https://dotnet.microsoft.com/)
[![Unreal Engine](https://img.shields.io/badge/Unreal-5.6-313131)](https://www.unrealengine.com/)
[![PostgreSQL](https://img.shields.io/badge/PostgreSQL-16-336791)](https://www.postgresql.org/)
[![Progress](https://img.shields.io/badge/Progress-51%25-yellow)]()

**Echoes** is an EVE Online-inspired MMO backend built with ASP.NET Core 8, Unreal Engine 5.6, and PostgreSQL. This repository serves as the central hub for backend development, project management, and technical documentation.

## 📊 Project Status

```
Overall Progress: ████████████████████████░░░░░░░░░░░░░░░░░░░░ 51%

Identity & Auth:  ████████████████████████████████ 100% ✅ Complete
Inventory System: ██████████████████████████████░░  90% ✅ Operational  
World Generation: ████████████████████████░░░░░░░░  80% ✅ Operational
Ship Physics:     █████████████████████░░░░░░░░░░░  70% ⚠️ Testing
Fitting System:   ████░░░░░░░░░░░░░░░░░░░░░░░░░░░░  15% ⚠️ In Progress
HUD Framework:    █░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░   5% ❌ Planned
```

**📋 [View Detailed Status](docs/STATUS.md)** | **🗺️ [View Roadmap](ROADMAP.md)**

---

## 🚀 Quick Start

### Prerequisites
- .NET 8.0 SDK
- PostgreSQL 16+
- Unreal Engine 5.6 (for client development)

### Setup
```bash
# Clone repository
git clone https://github.com/SkinXed/EchoesBackend_v1.git
cd EchoesBackend_v1

# Configure database connection
# Edit appsettings.json with your PostgreSQL connection string

# Run migrations
dotnet ef database update

# Start the API
dotnet run
```

**API will be available at:** `http://localhost:5116`

For detailed setup instructions, see [QUICK_START.md](QUICK_START.md)

---

## 📚 Documentation Hub

### 📋 Project Management
- **[📊 STATUS.md](docs/STATUS.md)** - Real-time project health dashboard
- **[🗺️ ROADMAP.md](ROADMAP.md)** - 4-milestone development roadmap
- **[🏛️ CORE_ARCHITECTURE_BIBLE.md](CORE_ARCHITECTURE_BIBLE.md)** - Complete architectural reference

### 🏗️ Architecture
- **[docs/architecture/NETWORKING_FLOW.md](docs/architecture/NETWORKING_FLOW.md)** - API endpoints and data flow
- **[docs/architecture/RULES_OF_ENGAGEMENT.md](docs/architecture/RULES_OF_ENGAGEMENT.md)** - ⚠️ **Iron Rules** (naming, security, replication)
- **[docs/DATABASE/SCHEMA_OVERVIEW.md](docs/DATABASE/SCHEMA_OVERVIEW.md)** - Database schema and design

### 🎮 Gameplay Systems
- **[docs/GAMEPLAY/SHIP_PHYSICS.md](docs/GAMEPLAY/SHIP_PHYSICS.md)** - Physics, damping, PD controller, warp mechanics
- **[docs/systems/inventory/INVENTORY_LOGIC.md](docs/systems/inventory/INVENTORY_LOGIC.md)** - Volume math (V = Σ Qty×Vol), item movement
- **[docs/systems/inventory/INVENTORY_ARCHITECTURE.md](docs/systems/inventory/INVENTORY_ARCHITECTURE.md)** - Inventory system architecture
- **[docs/systems/inventory/INVENTORY_MASTER_MANIFEST.md](docs/systems/inventory/INVENTORY_MASTER_MANIFEST.md)** - Complete inventory implementation
- **[docs/systems/inventory/ITEM_REGISTRY_IMPLEMENTATION.md](docs/systems/inventory/ITEM_REGISTRY_IMPLEMENTATION.md)** - Item types and registry
- **[SHIP_PHYSICS_INTEGRATION.md](SHIP_PHYSICS_INTEGRATION.md)** - Ship stats integration
- **[FITTING_SERVICE.md](FITTING_SERVICE.md)** - Ship fitting and mass calculation

### 🎨 UI/UX
- **[docs/ui_ux/HUD_MASTER_PLAN.md](docs/ui_ux/HUD_MASTER_PLAN.md)** - EVE-style HUD layout and implementation
- **[docs/ui_ux/WINDOW_SYSTEM.md](docs/ui_ux/WINDOW_SYSTEM.md)** - Window snapping, Z-order, dragging
- **[UI_UX_SYSTEM.md](UI_UX_SYSTEM.md)** - UI architecture overview
- **[WINDOW_SYSTEM_IMPLEMENTATION.md](WINDOW_SYSTEM_IMPLEMENTATION.md)** - Window implementation details
- **[CONTEXT_MENU_SYSTEM.md](CONTEXT_MENU_SYSTEM.md)** - Context menu system
- **[HANGAR_IMPLEMENTATION.md](HANGAR_IMPLEMENTATION.md)** - Hangar UI

### 🔐 Authentication & Identity
- **[AUTH_SYSTEM.md](AUTH_SYSTEM.md)** - JWT authentication
- **[AUTHENTICATION_CHARACTER_SYSTEM.md](AUTHENTICATION_CHARACTER_SYSTEM.md)** - Character management
- **[IDENTITY_INVENTORY_SUBSYSTEMS.md](IDENTITY_INVENTORY_SUBSYSTEMS.md)** - Identity subsystems
- **[COMPLETE_LOGIN_FLOW.md](COMPLETE_LOGIN_FLOW.md)** - Login and entry pipeline

### 🌌 Universe & World
- **[UNIVERSE_ARCHITECTURE.md](UNIVERSE_ARCHITECTURE.md)** - Universe generation
- **[REGIONAL_CLUSTER_IMPLEMENTATION.md](REGIONAL_CLUSTER_IMPLEMENTATION.md)** - Regional server architecture

### 📖 Legacy Documentation
- **[ECHOES_V1_ARCHITECTURE.md](ECHOES_V1_ARCHITECTURE.md)** - Original high-level architecture
- **[QUICK_START.md](QUICK_START.md)** - Quick start guide
- **[FINAL_PROJECT_STATUS.md](FINAL_PROJECT_STATUS.md)** - Legacy status (see STATUS.md instead)
- **[TECHNICAL_AUDIT_REPORT.md](TECHNICAL_AUDIT_REPORT.md)** - Technical audit

---

## 🏛️ Iron Rules of Architecture

**⚠️ Non-negotiable principles that govern all code development**

| Rule | Description | Example |
|------|-------------|---------|
| **"Postgres is Truth"** | PostgreSQL is the single source of truth. Backend calculates, Server validates, Clients display. | ✅ Backend API → Database → Calculate Stats<br>❌ Client modifies game state directly |
| **Function Prefixes** | All UE5 functions MUST use prefixes: `Server_`, `Client_`, `Common_` | ✅ `Server_RequestSpawn()`<br>✅ `Client_ShowNotification()`<br>✅ `Common_CalculateDistance()` |
| **No Client DB Writes** | Clients NEVER write to database. All writes go through Backend API with JWT auth. | ✅ Client → Server RPC → Backend API → Database<br>❌ Client → Database |
| **Server Authority** | Server has final say on all gameplay values. Clients predict, server corrects. | ✅ Server validates damage, replicates to clients<br>❌ Client decides damage amount |
| **Input Validation** | Validate ALL inputs at EVERY layer: Client (UX), Server (authority), Backend (security), Database (constraints) | ✅ Check capacity before move<br>❌ Trust client input blindly |
| **No Secrets in Code** | Never hardcode secrets. Use environment variables or secure vaults. | ✅ `Environment.GetEnvironmentVariable()`<br>❌ `password = "secret123"` |
| **Fail Gracefully** | Never crash. Log errors and recover. | ✅ Try-catch with fallback<br>❌ Unhandled exceptions |
| **Minimize RPCs** | Batch RPC calls. Throttle updates. | ✅ Update ship state at 10 Hz<br>❌ RPC every frame (60 Hz) |

**📖 [Read Complete Rules](docs/architecture/RULES_OF_ENGAGEMENT.md)**

---

## 🚢 Deployment Instructions

### Backend Deployment (.NET API)

```bash
# 1. Clone repository
git clone https://github.com/SkinXed/EchoesBackend_v1.git
cd EchoesBackend_v1

# 2. Configure database
# Edit appsettings.json or set environment variable
export ConnectionStrings__DefaultConnection="Host=your-db;Database=echoes;Username=user;Password=pass"

# 3. Apply migrations
dotnet ef database update

# 4. Run backend
dotnet run --configuration Release

# API available at http://localhost:5116
```

### UE5 Server Deployment

```bash
# 1. Build server target
# In Unreal Editor: File → Package Project → Windows (Server)
# Or use command line:
RunUAT BuildCookRun -project=Echoes.uproject -platform=Win64 \
  -serverconfig=Development -server -cook -build -stage -pak

# 2. Configure server
# Edit DefaultGame.ini or set environment variables
[/Script/Echoes.EchoesGameInstance]
ApiBaseUrl="http://your-backend:5116/api"
ServerSecret="your-server-secret"

# 3. Run dedicated server
EchoesServer.exe -log
```

### UE5 Client Deployment

```bash
# 1. Build client target  
# In Unreal Editor: File → Package Project → Windows
# Or use command line:
RunUAT BuildCookRun -project=Echoes.uproject -platform=Win64 \
  -clientconfig=Development -client -cook -build -stage -pak

# 2. Configure client
# Edit DefaultGame.ini
[/Script/Echoes.EchoesAuthSubsystem]
ApiBaseUrl="http://your-backend:5116/api"

# 3. Run client
Echoes.exe -log

# 4. Login
# Use credentials created via backend /api/auth/register
```

### Docker Deployment (Recommended for Production)

```bash
# Backend (API + PostgreSQL)
docker-compose up -d

# Configure UE5 server/client to point to containerized backend
ApiBaseUrl="http://localhost:5116/api"
```

**📖 [Detailed Deployment Guide](QUICK_START.md)**

---

## 🏗️ Project Structure

```
EchoesBackend_v1/
├── Controllers/             # ASP.NET Core API controllers
│   ├── Auth/               # Authentication endpoints
│   ├── Ship/               # Ship management
│   ├── Inventory/          # Inventory operations
│   └── Character/          # Character management
├── Models/                  # Data models
│   ├── DTOs/               # Data transfer objects
│   └── Entities/           # Database entities (EF Core)
├── Services/                # Business logic services
│   ├── Auth/               # Authentication service
│   ├── Ship/               # Ship fitting service
│   └── Inventory/          # Inventory service
├── Data/                    # Database context
├── Migrations/              # EF Core migrations
├── Client/                  # Unreal Engine 5 C++ client
│   └── Echoes/
│       └── Source/Echoes/
│           ├── Core/       # Core game systems
│           │   ├── Common/ # Shared client/server (Common_ prefix)
│           │   ├── Client/ # Client-only (Client_ prefix)
│           │   └── Server/ # Server-only (Server_ prefix)
│           └── UI/         # UI widgets
├── docs/                    # 📚 Documentation hub
│   ├── STATUS.md           # Real-time project status
│   ├── architecture/       # Architecture documentation
│   │   ├── NETWORKING_FLOW.md
│   │   └── RULES_OF_ENGAGEMENT.md ⚠️ Iron Rules
│   ├── systems/            # System-specific docs
│   │   ├── inventory/      # Inventory system docs
│   │   └── world/          # World generation docs
│   ├── ui_ux/              # UI/UX documentation
│   │   ├── HUD_MASTER_PLAN.md
│   │   └── WINDOW_SYSTEM.md
│   ├── GAMEPLAY/           # Gameplay mechanics
│   │   └── SHIP_PHYSICS.md
│   └── DATABASE/           # Database documentation
│       └── SCHEMA_OVERVIEW.md
├── tools/                   # Development tools
│   └── create_labels.sh    # GitHub label creation
├── .github/
│   └── ISSUE_TEMPLATE/     # Issue templates
│       ├── feature_request.yml
│       ├── task.yml
│       ├── 3d_tactical_radar.yml
│       ├── overview_list.yml
│       └── directional_shields.yml
├── ROADMAP.md              # 🗺️ 4-milestone roadmap
├── README.md               # This file
└── appsettings.json        # Backend configuration
```

---

## 🛠️ Development Rules

### Naming Conventions

#### Backend (.NET)
- **Controllers**: `{Entity}Controller.cs` (e.g., `ShipController.cs`)
- **Services**: `{Entity}Service.cs` or `I{Entity}Service.cs` (interface)
- **DTOs**: `{Entity}Dto.cs` or `{Action}{Entity}Dto.cs`
- **Entities**: `{Entity}.cs`

#### Client (C++)
- **Common Components**: `Echoes{Name}Component` (shared client/server)
  - Example: `EchoesShipMovementComponent`
- **Client-Only**: `Echoes{Name}` (client-specific logic)
  - Example: `EchoesShipPawn`, `EchoesPlayerController`
- **Server-Only**: `Echoes{Name}Server` (server authority)
  - Example: `EchoesShipMovementComponentServer`

### File Organization

#### Backend Prefixes
- No specific prefixes required
- Organize by feature/domain (`Controllers/Ship/`, `Services/Ship/`)

#### Unreal Engine Prefixes
- **Common** (`Common_`): Shared between client and server
- **Client** (`Client_`): Client-only functionality
- **Server** (`Server_`): Server-authoritative code

### Commit Message Format

```
[Category] Brief description

Detailed explanation if necessary

- Related files changed
- Impact on systems
```

**Categories**: `[Feature]`, `[Fix]`, `[Refactor]`, `[Docs]`, `[Test]`, `[Chore]`

### Pull Request Rules

1. **Branch Naming**: `feature/{feature-name}`, `bugfix/{bug-name}`, `refactor/{refactor-name}`
2. **PR Title**: Same format as commit messages
3. **Description**: 
   - What changed and why
   - Which systems are affected
   - Testing performed
4. **Reviews**: At least 1 approval required
5. **Tests**: All tests must pass
6. **Documentation**: Update relevant docs with the change

### Security Rules

1. **No Secrets in Code**: Use environment variables or secure key vaults
2. **Validate All Inputs**: Never trust client data
3. **Parameterized Queries**: Always use parameterized SQL/EF queries
4. **Authentication Required**: Protect all endpoints except public health checks
5. **Authorization Checks**: Verify ownership before resource access
6. **HTTPS Only**: Production must use encrypted connections
7. **Password Security**: Use bcrypt/Argon2 for password hashing
8. **JWT Best Practices**: 
   - Short expiration times
   - Refresh token rotation
   - Secure storage client-side

### Code Quality

- **Linting**: Follow .NET conventions and C++ standards
- **Code Reviews**: Mandatory for all changes
- **Testing**: Write unit tests for business logic
- **Documentation**: Comment complex algorithms, update docs

---

## 📋 Issue Templates & Labels

### Creating Issues

Use the provided issue templates:
- **Feature Request** (`.github/ISSUE_TEMPLATE/feature_request.yml`)
- **Task** (`.github/ISSUE_TEMPLATE/task.yml`)

### Label System

Run the label creation script:
```bash
bash tools/create_labels.sh
```

#### Label Categories

**Type Labels:**
- `bug` - Something isn't working
- `feature` - New feature or request
- `task` - Technical task or chore
- `refactor` - Code refactoring

**Layer Labels:**
- `[C++] Engine` - Unreal Engine C++ client code
- `[.NET] Backend` - ASP.NET Core backend API
- `[UI/HUD]` - UI and HUD implementation
- `[DB] Postgres` - Database schema and queries

**Priority Labels:**
- `P0` - Critical priority - immediate attention
- `P1` - High priority - important
- `P2` - Normal priority - backlog

---

## 🧪 Testing

```bash
# Run all tests
dotnet test

# Run specific test project
dotnet test Tests/Echoes.Tests.csproj

# Run with coverage
dotnet test /p:CollectCoverage=true
```

---

## 🏛️ Core Architecture Principles

### 1. "Postgres is Truth"
The PostgreSQL database is the **single source of truth** for all game state. The backend API is a stateless gateway.

### 2. Mirror Architecture
Each backend controller has a corresponding UE5 subsystem:
- `ShipController.cs` ↔ `UEchoesShipStatsSubsystem`
- `AuthController.cs` ↔ `UEchoesAuthSubsystem`

### 3. Physics-First Gameplay
All ship movement uses authentic UE5 physics (`AddForce`, angular velocity). No teleportation.

### 4. Client-Server Model
- **Client**: Optimistic updates, prediction, input handling
- **Server**: Authority, validation, persistent state

---

## 🤝 Contributing

1. Create a feature branch from `main`
2. Make your changes following the development rules
3. Write/update tests as needed
4. Update relevant documentation
5. Submit a pull request
6. Wait for code review and approval

---

## 📊 Project Status

**Current Phase**: Core Systems Development

### Completed ✅
- Ship physics and movement system
- Authentication and character system
- Inventory and fitting system
- Basic UI/HUD components
- Regional cluster architecture

### In Progress 🚧
- Combat system
- Market system
- Corporation/Alliance system

### Planned 📋
- Mission system
- Manufacturing
- Planetary interaction
- Full EVE-like HUD

For detailed status, see [FINAL_PROJECT_STATUS.md](FINAL_PROJECT_STATUS.md)

---

## 📞 Support & Contact

- **Documentation**: This README and linked docs
- **Issues**: Use GitHub issue templates
- **Architecture Questions**: See `CORE_ARCHITECTURE_BIBLE.md`

---

## 📄 License

[Add your license information here]

---

**Last Updated**: 2026-01-31  
**Maintained by**: Echoes Development Team
