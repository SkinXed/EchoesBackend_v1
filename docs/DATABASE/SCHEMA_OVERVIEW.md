# Database Schema Overview

## Overview

This document provides an overview of the PostgreSQL database schema for the Echoes MMO backend.

## Core Principle: "Postgres is Truth"

The PostgreSQL database is the **single source of truth** for all game state. All authoritative data lives here, including:
- Player accounts and characters
- Ship configurations and stats
- Inventory items
- Universe data (systems, stations, regions)
- Market transactions
- Combat logs

## Schema Organization

### Core Tables

#### Authentication & Users
- **`users`** - Player accounts
  - `id` (UUID, PK)
  - `username` (unique)
  - `email` (unique)
  - `password_hash`
  - `created_at`
  - `last_login`

- **`characters`** - In-game characters
  - `id` (UUID, PK)
  - `user_id` (FK -> users)
  - `name` (unique)
  - `race`
  - `bloodline`
  - `created_at`
  - `wallet_balance`
  - `current_system_id` (FK -> systems)

#### Ship System

- **`ship_types`** - Base ship templates (Frigates, Cruisers, etc.)
  - `id` (INT, PK)
  - `name`
  - `base_mass` (kg)
  - `base_thrust`
  - `base_rotation_speed`
  - `max_velocity`
  - `warp_speed`
  - `agility`
  - `high_slots`
  - `mid_slots`
  - `low_slots`
  - `cargo_capacity`

- **`ship_instances`** - Actual player-owned ships
  - `id` (UUID, PK)
  - `character_id` (FK -> characters)
  - `ship_type_id` (FK -> ship_types)
  - `name` (custom ship name)
  - `location_system_id` (FK -> systems)
  - `location_station_id` (FK -> stations, nullable)
  - `hull_health` (percentage)
  - `armor_health` (percentage)
  - `shield_health` (percentage)
  - `capacitor_charge` (percentage)

- **`ship_instance_modules`** - Fitted modules on ships
  - `id` (UUID, PK)
  - `ship_instance_id` (FK -> ship_instances)
  - `module_type_id` (FK -> module_types)
  - `slot_type` (High/Mid/Low/Rig)
  - `slot_number`
  - `is_active`
  - `created_at`

#### Inventory System

- **`module_types`** - Available modules/items
  - `id` (INT, PK)
  - `name`
  - `category` (Weapon/Shield/Armor/Engineering/etc.)
  - `mass` (kg)
  - `volume` (m³)
  - `power_grid_usage`
  - `cpu_usage`
  - `capacitor_usage`
  - `effect_data` (JSON)

- **`inventory_items`** - Character inventory
  - `id` (UUID, PK)
  - `character_id` (FK -> characters)
  - `module_type_id` (FK -> module_types)
  - `quantity`
  - `location_system_id` (FK -> systems)
  - `location_station_id` (FK -> stations, nullable)

#### Universe Data

- **`regions`** - High-level universe regions
  - `id` (INT, PK)
  - `name`
  - `security_status` (High/Low/Null)

- **`systems`** - Star systems
  - `id` (INT, PK)
  - `region_id` (FK -> regions)
  - `name`
  - `security_rating` (0.0 to 1.0)
  - `position_x`, `position_y`, `position_z`

- **`stations`** - Space stations
  - `id` (INT, PK)
  - `system_id` (FK -> systems)
  - `name`
  - `station_type`
  - `services` (JSON array: market, repair, fitting, etc.)

#### Market System (Future)

- **`market_orders`** - Buy/sell orders
  - `id` (UUID, PK)
  - `character_id` (FK -> characters)
  - `module_type_id` (FK -> module_types)
  - `order_type` (Buy/Sell)
  - `quantity`
  - `price`
  - `station_id` (FK -> stations)
  - `created_at`
  - `expires_at`

## Relationships

```
users (1) -> (*) characters
characters (1) -> (*) ship_instances
ship_instances (*) -> (1) ship_types
ship_instances (1) -> (*) ship_instance_modules
ship_instance_modules (*) -> (1) module_types
characters (1) -> (*) inventory_items
inventory_items (*) -> (1) module_types
systems (*) -> (1) regions
stations (*) -> (1) systems
```

## Key Indexes

### Performance Optimization
```sql
-- User authentication lookup
CREATE INDEX idx_users_username ON users(username);
CREATE INDEX idx_users_email ON users(email);

-- Character queries
CREATE INDEX idx_characters_user_id ON characters(user_id);
CREATE INDEX idx_characters_name ON characters(name);

-- Ship queries
CREATE INDEX idx_ship_instances_character_id ON ship_instances(character_id);
CREATE INDEX idx_ship_instances_location ON ship_instances(location_system_id, location_station_id);

-- Module lookups
CREATE INDEX idx_ship_instance_modules_ship_id ON ship_instance_modules(ship_instance_id);
CREATE INDEX idx_inventory_items_character_id ON inventory_items(character_id);

-- Universe navigation
CREATE INDEX idx_systems_region_id ON systems(region_id);
CREATE INDEX idx_stations_system_id ON stations(system_id);
```

## Data Types & Conventions

### Identifiers
- **UUID** for user-generated entities (characters, ships, items)
- **INT** for static game data (ship types, module types, systems)

### Naming Convention
- Table names: `snake_case`, plural
- Column names: `snake_case`
- Foreign keys: `{referenced_table}_id`

### Timestamps
- All tables include `created_at` timestamp
- Mutable entities include `updated_at` timestamp
- Stored in UTC

## Migrations

Entity Framework Core Code-First migrations are used:

```bash
# Create new migration
dotnet ef migrations add MigrationName

# Apply migrations
dotnet ef database update

# Rollback
dotnet ef database update PreviousMigrationName
```

## Calculated Fields

Some data is calculated on-the-fly rather than stored:

### Ship Total Mass
```sql
-- Not stored in DB, calculated by ShipFittingService
TotalMass = ship_types.base_mass + SUM(module_types.mass)
```

### Character Total Wealth
```sql
-- Calculated across wallet + inventory value
TotalWealth = wallet_balance + SUM(inventory_value)
```

## Data Validation

### Database Constraints
- `NOT NULL` on required fields
- `UNIQUE` constraints on usernames, emails, character names
- `CHECK` constraints on numeric ranges (0-100 for percentages)
- Foreign key constraints for referential integrity

### Application-Level Validation
- Input sanitization
- Business logic validation
- Authorization checks

## Backup Strategy

### Automated Backups
- **Daily**: Full database backup
- **Hourly**: Incremental backups
- **Real-time**: WAL (Write-Ahead Log) archiving

### Recovery Point Objective (RPO)
- Target: < 1 hour of data loss
- Point-in-time recovery capability

## Scaling Considerations

### Read Replicas
- Deploy read replicas for query-heavy operations
- Inventory searches
- Market data queries
- Universe navigation

### Partitioning Strategy (Future)
- Partition large tables by date/region
- `combat_logs` by month
- `market_transactions` by region

### Sharding (Future)
- Horizontal sharding by character_id
- Each shard handles subset of characters
- Cross-shard queries via aggregation layer

## Security

### Access Control
- Principle of least privilege
- Application uses dedicated DB user with limited permissions
- Secrets stored in environment variables / key vault
- Encrypted connections (SSL/TLS)

### Sensitive Data
- Password hashes use bcrypt/Argon2
- JWT tokens stored securely client-side
- No plaintext passwords ever stored

## Monitoring & Maintenance

### Performance Monitoring
- Query execution time tracking
- Slow query log analysis
- Index usage statistics
- Connection pool monitoring

### Maintenance Tasks
- `VACUUM` and `ANALYZE` for optimization
- Index rebuilding
- Statistics updates
- Archive old data

## Future Schema Enhancements

- [ ] Combat system tables (damage logs, killmails)
- [ ] Corporation/alliance tables
- [ ] Manufacturing/blueprint system
- [ ] Contract system
- [ ] Planetary interaction
- [ ] Skill system
- [ ] Mission/quest system
- [ ] Reputation/standings

---

**Status**: Active Development  
**Last Updated**: 2026-01-31  
**Owner**: Database Architecture Team
