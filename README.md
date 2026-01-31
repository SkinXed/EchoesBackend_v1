# Echoes MMO Backend - Project Hub

[![.NET](https://img.shields.io/badge/.NET-8.0-512BD4)](https://dotnet.microsoft.com/)
[![Unreal Engine](https://img.shields.io/badge/Unreal-5.6-313131)](https://www.unrealengine.com/)
[![PostgreSQL](https://img.shields.io/badge/PostgreSQL-16-336791)](https://www.postgresql.org/)

**Echoes** is an EVE Online-inspired MMO backend built with ASP.NET Core 8, Unreal Engine 5.6, and PostgreSQL. This repository serves as the central hub for backend development, project management, and technical documentation.

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

## 📚 Documentation

### Architecture
- **[ECHOES_V1_ARCHITECTURE.md](ECHOES_V1_ARCHITECTURE.md)** - High-level system architecture
- **[CORE_ARCHITECTURE_BIBLE.md](CORE_ARCHITECTURE_BIBLE.md)** - Core architectural principles
- **[docs/ARCHITECTURAL/NETWORKING_FLOW.md](docs/ARCHITECTURAL/NETWORKING_FLOW.md)** - API and networking documentation

### Systems

#### Ship & Movement
- **[QUICK_START.md](QUICK_START.md)** - EVE-like ship movement quick start
- **[SHIP_PHYSICS_INTEGRATION.md](SHIP_PHYSICS_INTEGRATION.md)** - Physics system details
- **[FITTING_SERVICE.md](FITTING_SERVICE.md)** - Ship fitting and mass calculation

#### Inventory & Items
- **[INVENTORY_ARCHITECTURE.md](INVENTORY_ARCHITECTURE.md)** - Inventory system design
- **[INVENTORY_MASTER_MANIFEST.md](INVENTORY_MASTER_MANIFEST.md)** - Complete inventory manifest
- **[ITEM_REGISTRY_IMPLEMENTATION.md](ITEM_REGISTRY_IMPLEMENTATION.md)** - Item types and registry

#### Authentication & Characters
- **[AUTH_SYSTEM.md](AUTH_SYSTEM.md)** - Authentication system
- **[AUTHENTICATION_CHARACTER_SYSTEM.md](AUTHENTICATION_CHARACTER_SYSTEM.md)** - Character management
- **[IDENTITY_INVENTORY_SUBSYSTEMS.md](IDENTITY_INVENTORY_SUBSYSTEMS.md)** - Identity subsystems

#### UI/UX
- **[UI_UX_SYSTEM.md](UI_UX_SYSTEM.md)** - UI architecture
- **[docs/UI_UX/HUD_MASTER_PLAN.md](docs/UI_UX/HUD_MASTER_PLAN.md)** - HUD design and implementation plan
- **[HANGAR_IMPLEMENTATION.md](HANGAR_IMPLEMENTATION.md)** - Hangar UI
- **[WINDOW_SYSTEM_IMPLEMENTATION.md](WINDOW_SYSTEM_IMPLEMENTATION.md)** - Window management
- **[CONTEXT_MENU_SYSTEM.md](CONTEXT_MENU_SYSTEM.md)** - Context menu system

#### Universe & Regions
- **[UNIVERSE_ARCHITECTURE.md](UNIVERSE_ARCHITECTURE.md)** - Universe generation and structure
- **[REGIONAL_CLUSTER_IMPLEMENTATION.md](REGIONAL_CLUSTER_IMPLEMENTATION.md)** - Regional server architecture

#### Database
- **[docs/DATABASE/SCHEMA_OVERVIEW.md](docs/DATABASE/SCHEMA_OVERVIEW.md)** - Database schema documentation

### Game Flow
- **[GAME_FLOW_SYSTEM.md](GAME_FLOW_SYSTEM.md)** - Game state management
- **[COMPLETE_LOGIN_FLOW.md](COMPLETE_LOGIN_FLOW.md)** - Login and entry pipeline
- **[ENTRY_PIPELINE_COMPLETE.md](ENTRY_PIPELINE_COMPLETE.md)** - Complete entry pipeline

### Project Status
- **[FINAL_PROJECT_STATUS.md](FINAL_PROJECT_STATUS.md)** - Current project status
- **[COMPLETE_SYSTEM_SUMMARY.md](COMPLETE_SYSTEM_SUMMARY.md)** - System summary
- **[TECHNICAL_AUDIT_REPORT.md](TECHNICAL_AUDIT_REPORT.md)** - Technical audit

---

## 🏗️ Project Structure

```
EchoesBackend_v1/
├── Controllers/          # ASP.NET Core API controllers
│   ├── Auth/            # Authentication endpoints
│   ├── Ship/            # Ship management endpoints
│   └── ...
├── Models/              # Data models
│   ├── DTOs/           # Data transfer objects
│   └── Entities/       # Database entities
├── Services/            # Business logic services
│   ├── Ship/           # Ship-related services
│   └── ...
├── Migrations/          # EF Core database migrations
├── Client/              # Unreal Engine 5 C++ client
│   └── Echoes/         # UE5 project
├── EchoesOfImperial.Client/    # Blazor WASM client
├── EchoesOfImperial.Shared/    # Shared DTOs
├── docs/                # Project documentation
│   ├── ARCHITECTURAL/   # Architecture documentation
│   ├── DATABASE/        # Database documentation
│   └── UI_UX/          # UI/UX documentation
└── tools/               # Development tools and scripts
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
