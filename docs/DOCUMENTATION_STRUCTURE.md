# Documentation Structure

This document explains the organization of documentation files in the Echoes Backend v1 repository.

## Overview

All documentation has been organized into the `/docs/` directory with a clear hierarchical structure to make it easier to find and navigate documentation from mobile devices or desktop.

## Directory Structure

```
docs/
├── architecture/          # System architecture and design documents
├── gameplay/              # Gameplay mechanics and systems
├── systems/               # Specific system implementations
│   ├── inventory/        # Inventory system documentation
│   ├── ship/             # Ship-related systems
│   ├── economy/          # Economy system (future)
│   ├── navigation/       # Navigation system
│   └── gameplay/         # Additional gameplay systems
├── ui_ux/                 # User interface and UX documentation
├── reports/               # Implementation reports and summaries
├── DATABASE/              # Database schema and design
├── GAMEPLAY/              # Additional gameplay documentation
├── STATUS.md              # Current project status
├── QUICK_START.md         # Quick start guide
├── README_COMPLETE.md     # Complete README
└── PROJECT_ECHOES_V1_MANIFEST.md  # Project manifest
```

## Root Directory

The repository root now contains only essential files:

- **README.md** - Main project documentation hub
- **ROADMAP.md** - Development roadmap
- **.gitignore** - Git ignore rules
- **.gitattributes** - Git attributes
- **EchoesBackend.sln** - Solution file
- **Echoes.API.csproj** - Project file
- **Program.cs** - Entry point
- **appsettings.json** - Configuration

## Architecture Documentation

Located in `docs/architecture/`:

- **CORE_ARCHITECTURE_BIBLE.md** - Complete architectural reference
- **AUTH_SYSTEM.md** - JWT authentication system
- **AUTHENTICATION_CHARACTER_SYSTEM.md** - Character management
- **COMPLETE_LOGIN_FLOW.md** - Login and entry pipeline
- **ECHOES_V1_ARCHITECTURE.md** - High-level architecture
- **ENTRY_PIPELINE_COMPLETE.md** - Complete entry pipeline
- **UNIVERSE_ARCHITECTURE.md** - Universe generation architecture
- **NETWORKING_FLOW.md** - API endpoints and data flow
- **RULES_OF_ENGAGEMENT.md** - ⚠️ Iron Rules (naming, security, replication)

## Gameplay Systems

Located in `docs/gameplay/` and `docs/GAMEPLAY/`:

- **SHIP_PHYSICS_INTEGRATION.md** - Ship physics integration
- **GAME_FLOW_SYSTEM.md** - Complete game flow system
- **SHIP_PHYSICS.md** - Physics, damping, PD controller, warp mechanics

## System-Specific Documentation

### Inventory System (`docs/systems/inventory/`)

- **HANGAR_IMPLEMENTATION.md** - Hangar UI and logic
- **IDENTITY_INVENTORY_SUBSYSTEMS.md** - Identity subsystems
- **INVENTORY_ARCHITECTURE.md** - Inventory system architecture
- **INVENTORY_LOGIC.md** - Volume math and item movement
- **INVENTORY_MASTER_MANIFEST.md** - Complete inventory implementation
- **ITEM_REGISTRY_IMPLEMENTATION.md** - Item types and registry

### Ship Systems (`docs/systems/ship/`)

- **FITTING_SERVICE.md** - Ship fitting and mass calculation service

### Regional Systems (`docs/systems/`)

- **REGIONAL_CLUSTER_COMPLETE.md** - Regional cluster completion
- **REGIONAL_CLUSTER_IMPLEMENTATION.md** - Regional cluster architecture

## UI/UX Documentation

Located in `docs/ui_ux/`:

- **HUD_MASTER_PLAN.md** - EVE-style HUD layout and implementation
- **WINDOW_SYSTEM.md** - Window snapping, Z-order, dragging
- **UI_UX_SYSTEM.md** - UI architecture overview
- **WINDOW_SYSTEM_IMPLEMENTATION.md** - Window implementation details
- **CONTEXT_MENU_SYSTEM.md** - Context menu system
- **DRAG_DROP_SYSTEM.md** - Drag and drop system
- **ADVANCED_WINDOW_FEATURES.md** - Advanced window features
- **STATION_MENU_IMPLEMENTATION.md** - Station menu UI

## Reports and Summaries

Located in `docs/reports/`:

- **FINAL_PROJECT_STATUS.md** - Final project status
- **TECHNICAL_AUDIT_REPORT.md** - Technical audit
- **CROSS_LANGUAGE_SYNC_AUDIT.md** - Cross-language sync audit
- **COMPLETE_IMPLEMENTATION_SUMMARY.md** - Complete implementation summary
- **COMPLETE_SYSTEM_SUMMARY.md** - Complete system summary
- **FINAL_ENTRY_PIPELINE_SUMMARY.md** - Entry pipeline summary
- **FINAL_GAMEMODE_INTEGRATION_SUMMARY.md** - Gamemode integration summary
- **FINAL_IMPLEMENTATION_REPORT.md** - Implementation report
- **FINAL_IMPLEMENTATION_SUMMARY.md** - Implementation summary
- **IMPLEMENTATION_COMPLETE.md** - Implementation complete
- **IMPLEMENTATION_COMPLETE_SUMMARY.md** - Implementation complete summary
- **IMPLEMENTATION_SUMMARY.md** - Implementation summary
- **UNIVERSE_COMPLETION_SUMMARY.md** - Universe completion summary

## Fitting System Status

**Important Note**: The fitting service (`FITTING_SERVICE.md`) is **ACTIVE** in the codebase and is located in `docs/systems/ship/`. It has NOT been marked as outdated because:

1. The `ShipFittingService` class exists and is implemented in `Services/Ship/ShipFittingService.cs`
2. The `IShipFittingService` interface exists in `Services/Ship/IShipFittingService.cs`
3. The service is registered in `Program.cs` (line 165)
4. The service is actively used in `Controllers/Ship/ShipController.cs`
5. The fitting models exist in the database schema

## Client Documentation

Client-specific documentation remains in the `Client/Echoes/` directory as it is specific to Unreal Engine implementation:

- Client/README.md
- Client/Echoes/*.md (UE5-specific guides)

## How to Navigate from Mobile

1. Open the main [README.md](../README.md) in GitHub
2. Browse the **Documentation Hub** section with organized links
3. Click any link to jump directly to specific documentation
4. Use GitHub's mobile interface to read markdown files
5. Use the back button to return to the main README

## Future Organization

As the project grows, consider:

- Adding a `docs/api/` directory for API documentation
- Creating a `docs/deployment/` directory for deployment guides
- Organizing `docs/tutorials/` for step-by-step guides
- Separating `docs/design/` for design documents

---

**Last Updated**: 2026-01-31
**Author**: Echoes Documentation Team
