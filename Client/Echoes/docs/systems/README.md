# System Documentation

This directory contains documentation for all major game systems in Echoes.

---

## 📚 Available Documentation

### Inventory System

The inventory system is the most mature and well-documented system.

- **[Complete Inventory System Summary](COMPLETE_INVENTORY_SYSTEM_SUMMARY.md)** - High-level overview
- **[Inventory Component Implementation](INVENTORY_COMPONENT_IMPLEMENTATION.md)** - Core component
- **[Inventory UI Implementation](INVENTORY_UI_IMPLEMENTATION.md)** - User interface
- **[Inventory UI Summary](INVENTORY_UI_SUMMARY.md)** - UI summary
- **[Inventory UI Quick Reference](INVENTORY_UI_QUICK_REFERENCE.md)** - Quick reference
- **[Inventory Entry Widget Guide](INVENTORY_ENTRY_WIDGET_GUIDE.md)** - Widget guide

### Item System

- **[Item Definitions Guide](ITEM_DEFINITIONS_GUIDE.md)** - Item types and properties
- **[Item Actor Guide](ITEM_ACTOR_GUIDE.md)** - World item actors

### Ship Systems

- **[Ship Movement System](SHIP_MOVEMENT_SYSTEM.md)** - Physics-based movement

---

## 🎯 Key Concepts

### Volume-Based Inventory

Echoes uses a volume-based inventory system similar to EVE Online:

```
Total Volume = Σ (Quantity × Volume per Item)
Capacity Check: Total Volume ≤ Container Capacity
```

### Client-Server Architecture

All game systems follow the "Postgres is Truth" principle:

```
Client (Display) → Server (Validate) → Backend API → PostgreSQL (Truth)
```

### Component-Based Design

Systems are implemented as reusable UE5 components:

- `UEchoesInventoryComponent` - Attached to ships, stations, containers
- `UEchoesShipMovementComponent` - Attached to ship pawns

---

## 📖 Reading Guide

### New Developers

Start with these documents:

1. [Complete Inventory System Summary](COMPLETE_INVENTORY_SYSTEM_SUMMARY.md) - Understand the most complete system
2. [Ship Movement System](SHIP_MOVEMENT_SYSTEM.md) - Learn physics implementation
3. [Item Definitions Guide](ITEM_DEFINITIONS_GUIDE.md) - Understand item data

### UI Developers

Focus on UI implementation:

1. [Inventory UI Implementation](INVENTORY_UI_IMPLEMENTATION.md)
2. [Inventory Entry Widget Guide](INVENTORY_ENTRY_WIDGET_GUIDE.md)
3. [Inventory UI Quick Reference](INVENTORY_UI_QUICK_REFERENCE.md)

### Gameplay Programmers

Focus on logic and components:

1. [Inventory Component Implementation](INVENTORY_COMPONENT_IMPLEMENTATION.md)
2. [Ship Movement System](SHIP_MOVEMENT_SYSTEM.md)
3. [Item Actor Guide](ITEM_ACTOR_GUIDE.md)

---

## 🔄 System Status

| System | Implementation | Documentation | Status |
|--------|----------------|---------------|--------|
| **Inventory** | 90% | 95% | ✅ Mature |
| **Ship Movement** | 70% | 80% | ✅ Functional |
| **Items** | 80% | 75% | ✅ Functional |
| **Combat** | 20% | 10% | 🚧 In Progress |
| **Market** | 5% | 0% | 📋 Planned |

---

**Last Updated**: 2026-02-01
