# Echoes UE5 Client - Documentation Index

Welcome to the Echoes Unreal Engine 5 Client documentation. This index helps you find the information you need quickly.

---

## 📖 Quick Links

- [Main README](../README.md) - Project overview and getting started
- [Quick Start Guide](guides/QUICK_START_GUIDE.md) - Get up and running quickly
- [Architecture Overview](architecture/ARCHITECTURAL_IMPROVEMENTS.md) - System architecture

---

## 🏗️ Architecture

### Core Architecture
- **[Architectural Improvements](architecture/ARCHITECTURAL_IMPROVEMENTS.md)** - System architecture and design patterns
- **[Network Security](architecture/NETWORK_SECURITY.md)** - Security best practices and implementation
- **[Server Management](architecture/SERVER_MANAGEMENT_README.md)** - Dedicated server setup and management

### Design Principles

1. **"Postgres is Truth"** - Backend database is the single source of truth
2. **Function Naming** - `Server_`, `Client_`, `Common_` prefixes
3. **Mirror Architecture** - Backend controllers ↔ UE5 subsystems
4. **Client-Server Model** - Clear separation of responsibilities

---

## 🎮 Game Systems

### Inventory System

The inventory system is the most comprehensive and well-documented system in Echoes.

#### Core Documentation
- **[Complete Inventory System Summary](systems/COMPLETE_INVENTORY_SYSTEM_SUMMARY.md)** - High-level overview of the entire system
- **[Inventory Component Implementation](systems/INVENTORY_COMPONENT_IMPLEMENTATION.md)** - Core inventory logic and component
- **[Inventory UI Implementation](systems/INVENTORY_UI_IMPLEMENTATION.md)** - User interface widgets and interactions
- **[Inventory UI Summary](systems/INVENTORY_UI_SUMMARY.md)** - UI implementation summary

#### Detailed Guides
- **[Inventory UI Quick Reference](systems/INVENTORY_UI_QUICK_REFERENCE.md)** - Quick reference for UI elements
- **[Inventory Entry Widget Guide](systems/INVENTORY_ENTRY_WIDGET_GUIDE.md)** - Detailed widget guide

#### Item System
- **[Item Definitions Guide](systems/ITEM_DEFINITIONS_GUIDE.md)** - Item type definitions and properties
- **[Item Actor Guide](systems/ITEM_ACTOR_GUIDE.md)** - World item actors and interactions

**Key Features:**
- Volume-based inventory (Σ Qty × Volume ≤ Capacity)
- Client-side prediction with server validation
- Drag & drop UI
- Stack splitting
- Container management
- Ship cargo and station hangars

### Ship Systems

- **[Ship Movement System](systems/SHIP_MOVEMENT_SYSTEM.md)** - Physics-based ship movement
  - Newtonian physics with damping
  - PD controller for thrust vectoring
  - Warp drive mechanics
  - Mass and agility calculations

**Key Features:**
- Authentic space physics
- Force-based movement (no teleportation)
- Dynamic mass from fitted modules
- Warp speed travel
- Angular velocity control

---

## 🌌 World Generation

- **[World Generator README](world/WORLD_GENERATOR_README.md)** - World generation system overview
- **[World Generator Implementation Summary](world/WORLD_GENERATOR_IMPLEMENTATION_SUMMARY.md)** - Detailed implementation

**Key Features:**
- Procedural galaxy generation
- Solar systems with stars, planets, moons
- Asteroid belts
- Stargates connecting systems
- Stations and structures

---

## 🎨 UI/UX Systems

### Window System

The Echoes UI uses a window-based system similar to EVE Online.

**Features:**
- Draggable windows
- Resizable panels
- Z-order management (focus)
- Window snapping
- Minimize/close buttons

**Related Documentation:**
- [Inventory UI Implementation](systems/INVENTORY_UI_IMPLEMENTATION.md)
- [Inventory Entry Widget Guide](systems/INVENTORY_ENTRY_WIDGET_GUIDE.md)

### Widget Types

| Widget | Purpose | Location |
|--------|---------|----------|
| **EchoesLoginWidget** | Authentication screen | `UI/Widgets/` |
| **EchoesCharacterSelectWidget** | Character selection | `UI/Widgets/` |
| **EchoesInventoryWidget** | Inventory management | `UI/Widgets/` |
| **EchoesStationMenuWidget** | Station services | `UI/Widgets/` |
| **EchoesHangarWidget** | Ship hangar | `UI/Widgets/` |

---

## 🔌 Networking & Subsystems

### Core Subsystems

All subsystems are `UGameInstanceSubsystem` classes that persist across level transitions.

| Subsystem | Purpose | Documentation |
|-----------|---------|---------------|
| **UEchoesAuthSubsystem** | Authentication and JWT token management | [Network Security](architecture/NETWORK_SECURITY.md) |
| **UEchoesIdentitySubsystem** | Character management and selection | - |
| **UEchoesInventorySubsystem** | Inventory operations and HTTP API | [Inventory Component](systems/INVENTORY_COMPONENT_IMPLEMENTATION.md) |
| **UEchoesShipStatsSubsystem** | Ship stats and fitting | - |
| **UEchoesGameStateSubsystem** | Global game state | - |

### HTTP API Communication

All subsystems communicate with the backend via HTTP REST API:

```
Client Request → Subsystem → HTTP Request → Backend API → PostgreSQL
                                                ↓
Client Update ← Subsystem ← HTTP Response ← Backend API
```

**Example Flow:**
1. Player moves item in UI
2. UI calls `InventorySubsystem->MoveItem()`
3. Subsystem sends HTTP POST to `/api/inventory/move`
4. Backend validates, updates database
5. Backend returns success/error
6. Subsystem updates local state
7. UI reflects changes

---

## 🛠️ Development Guides

### Getting Started

1. **[Quick Start Guide](guides/QUICK_START_GUIDE.md)** - First-time setup
2. [Main README](../README.md) - Project overview
3. [Architecture Overview](architecture/ARCHITECTURAL_IMPROVEMENTS.md) - Understand the codebase

### Code Organization

```
Source/Echoes/
├── Core/Common/        # Shared client/server code
├── Core/Server/        # Server-only code (game modes, validation)
├── Core/Client/        # Client-only code (pawns, controllers)
└── UI/                 # User interface widgets
```

### Function Naming Convention

**All functions must use one of these prefixes:**

- **`Server_`** - Server-authoritative RPC
  ```cpp
  UFUNCTION(Server, Reliable, WithValidation)
  void Server_RequestSpawn(FVector Location);
  ```

- **`Client_`** - Client-only RPC
  ```cpp
  UFUNCTION(Client, Reliable)
  void Client_ShowNotification(const FString& Message);
  ```

- **`Common_`** - Shared utility function
  ```cpp
  UFUNCTION(BlueprintCallable)
  float Common_CalculateDistance(FVector A, FVector B);
  ```

### Adding New Features

1. **Backend First** - Create API endpoint in C# backend
2. **Subsystem** - Add HTTP call to relevant subsystem
3. **UI** - Create widget for user interaction
4. **Testing** - Test in PIE with multiple clients

---

## 📚 Documentation by Topic

### Authentication & Identity

- [Network Security](architecture/NETWORK_SECURITY.md) - JWT authentication
- [Server Management](architecture/SERVER_MANAGEMENT_README.md) - Server auth

**Key Files:**
- `EchoesAuthSubsystem.h/.cpp` - Authentication logic
- `EchoesLoginWidget.h/.cpp` - Login UI
- `EchoesCharacterSelectWidget.h/.cpp` - Character selection

### Inventory & Items

- [Complete Inventory System Summary](systems/COMPLETE_INVENTORY_SYSTEM_SUMMARY.md)
- [Inventory Component Implementation](systems/INVENTORY_COMPONENT_IMPLEMENTATION.md)
- [Item Definitions Guide](systems/ITEM_DEFINITIONS_GUIDE.md)

**Key Files:**
- `EchoesInventoryComponent.h/.cpp` - Inventory component
- `EchoesInventorySubsystem.h/.cpp` - HTTP API calls
- `EchoesInventoryWidget.h/.cpp` - Inventory UI

### Ship Systems

- [Ship Movement System](systems/SHIP_MOVEMENT_SYSTEM.md)

**Key Files:**
- `EchoesShipMovementComponent.h/.cpp` - Movement physics
- `EchoesShipPawn.h/.cpp` - Player ship
- `EchoesShipStatsSubsystem.h/.cpp` - Ship stats

### World & Universe

- [World Generator README](world/WORLD_GENERATOR_README.md)
- [World Generator Implementation](world/WORLD_GENERATOR_IMPLEMENTATION_SUMMARY.md)

**Key Files:**
- `EchoesWorldGenerator.h/.cpp` - Procedural generation
- `StargateActor.h/.cpp` - Stargate jump gates
- `PlanetActor.h/.cpp` - Planetary bodies
- `StarActor.h/.cpp` - Star systems

---

## 🔍 Troubleshooting

### Common Issues

#### Build Errors

**Problem**: "Cannot find include file"
**Solution**: Regenerate project files (right-click `.uproject` → Generate VS files)

**Problem**: Linker errors
**Solution**: Clean solution, rebuild `Echoes` project

#### Runtime Issues

**Problem**: "Auth token invalid"
**Solution**: Check backend API is running, verify URL in `DefaultGame.ini`

**Problem**: Inventory not syncing
**Solution**: Check network logs, verify JWT token, check API endpoints

#### Performance Issues

**Problem**: Low FPS
**Solution**: Use `stat fps`, `stat unit` to diagnose, check entity count

---

## 📖 Additional Resources

### External Documentation

- [Unreal Engine Documentation](https://docs.unrealengine.com/5.6/)
- [UE5 C++ API Reference](https://docs.unrealengine.com/5.6/en-US/API/)
- [UE5 Networking](https://docs.unrealengine.com/5.6/en-US/networking-and-multiplayer-in-unreal-engine/)

### Backend API

- See main repository README for backend API documentation
- API endpoints: `http://localhost:5116/swagger`

---

## 📝 Contributing to Documentation

When adding new documentation:

1. Place files in appropriate subdirectory:
   - `guides/` - Getting started and tutorials
   - `systems/` - Game system documentation
   - `architecture/` - Technical architecture
   - `ui/` - UI/UX documentation
   - `world/` - World generation

2. Update this index with links to your new documentation
3. Follow markdown best practices
4. Include code examples where relevant
5. Add screenshots for UI documentation

---

## 🎯 Documentation Status

| System | Coverage | Status |
|--------|----------|--------|
| **Inventory** | 95% | ✅ Comprehensive |
| **Ship Movement** | 80% | ✅ Good |
| **World Generation** | 75% | ✅ Good |
| **Authentication** | 70% | ⚠️ Needs expansion |
| **UI Framework** | 60% | ⚠️ Needs expansion |
| **Combat** | 10% | ❌ Incomplete |
| **Market** | 0% | ❌ Not started |

---

**Last Updated**: 2026-02-01  
**Maintained by**: Echoes Development Team
