# Echoes of Imperial - Database Schema Documentation

> **Complete PostgreSQL Database Structure**  
> All tables, relationships, constraints, and CASCADE rules

**Version:** 2.0  
**Last Updated:** 2026-02-03  
**Database:** PostgreSQL 15+  
**Total Tables:** 50+

---

## Table of Contents

1. [Schema Overview](#schema-overview)
2. [Character & Account System](#character--account-system)
3. [Universe Generation](#universe-generation)
4. [Inventory & Items](#inventory--items)
5. [Economy & Trading](#economy--trading)
6. [Game Server Management](#game-server-management)
7. [Content Management](#content-management)
8. [Cascade & Restrict Rules](#cascade--restrict-rules)
9. [Indexes & Performance](#indexes--performance)

---

## Schema Overview

### Database Hierarchy

```
echoes_database
├── Character System (9 tables)
├── Universe System (15 tables)
├── Inventory System (15 tables)
├── Economy System (4 tables)
├── Game Server (1 table)
└── Content Management (3 tables)
```

### Key Relationships

```
accounts (1) ─→ (N) characters
    │
    └─→ (N) account_sessions
    
characters (1) ─→ (1) character_locations
           (1) ─→ (N) character_skills
           (1) ─→ (N) assets (inventory)
           (1) ─→ (N) wallet_transactions
           
regions (1) ─→ (N) constellations
    │
    └─→ constellations (1) ─→ (N) solar_systems
            │
            ├─→ (N) planets ─→ (N) moons
            ├─→ (N) stations
            ├─→ (N) stargates
            ├─→ (N) asteroid_belts
            ├─→ (N) anomalies
            └─→ (N) wormholes
```

---

## Character & Account System

### 1. `accounts` Table

**Purpose:** User authentication and account management

```sql
CREATE TABLE accounts (
    id                  UUID PRIMARY KEY DEFAULT gen_random_uuid(),
    username            VARCHAR(50) UNIQUE NOT NULL,
    email               VARCHAR(255) UNIQUE NOT NULL,
    password_hash       TEXT NOT NULL,
    is_admin            BOOLEAN DEFAULT FALSE,
    created_at          TIMESTAMP DEFAULT NOW(),
    last_login          TIMESTAMP,
    is_active           BOOLEAN DEFAULT TRUE,
    
    CONSTRAINT chk_email_format CHECK (email ~* '^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Z|a-z]{2,}$')
);

CREATE INDEX idx_accounts_username ON accounts(username);
CREATE INDEX idx_accounts_email ON accounts(email);
```

**Key Fields:**
- `password_hash`: Hashed with bcrypt/PBKDF2 (never plain text)
- `is_admin`: Admin role flag (for [Authorize(Roles = "Admin")])
- `is_active`: Soft delete flag (bans don't delete data)

---

### 2. `characters` Table

**Purpose:** Player pilot profiles (game characters)

```sql
CREATE TABLE characters (
    id                      UUID PRIMARY KEY DEFAULT gen_random_uuid(),
    account_id              UUID NOT NULL REFERENCES accounts(id) ON DELETE CASCADE,
    name                    VARCHAR(100) UNIQUE NOT NULL,
    race_id                 INTEGER NOT NULL,  -- 1=Caldari, 2=Gallente, 3=Amarr, 4=Minmatar
    corporation_id          UUID,
    
    -- Attributes
    intelligence            INTEGER DEFAULT 20,
    perception              INTEGER DEFAULT 20,
    charisma                INTEGER DEFAULT 20,
    willpower               INTEGER DEFAULT 20,
    memory                  INTEGER DEFAULT 20,
    
    -- Financial
    wallet_balance          BIGINT DEFAULT 100000,  -- Starting credits: 100,000
    total_credits_earned    BIGINT DEFAULT 0,
    total_credits_lost      BIGINT DEFAULT 0,
    
    -- Skills
    total_skill_points      BIGINT DEFAULT 0,
    unallocated_skill_points BIGINT DEFAULT 50000,  -- Starting SP: 50,000
    
    -- Combat stats
    total_kills             INTEGER DEFAULT 0,
    total_deaths            INTEGER DEFAULT 0,
    ships_destroyed         INTEGER DEFAULT 0,
    ships_lost              INTEGER DEFAULT 0,
    
    -- Security & reputation
    security_status         FLOAT DEFAULT 0.0,  -- Range: -10.0 to +10.0
    
    -- Current state
    active_ship_item_id     UUID REFERENCES assets(id) ON DELETE SET NULL,
    
    created_at              TIMESTAMP DEFAULT NOW(),
    
    CONSTRAINT chk_attributes CHECK (
        intelligence BETWEEN 20 AND 50 AND
        perception BETWEEN 20 AND 50 AND
        charisma BETWEEN 20 AND 50 AND
        willpower BETWEEN 20 AND 50 AND
        memory BETWEEN 20 AND 50
    ),
    CONSTRAINT chk_security_status CHECK (security_status BETWEEN -10.0 AND 10.0)
);

CREATE INDEX idx_characters_account_id ON characters(account_id);
CREATE INDEX idx_characters_name ON characters(name);
CREATE INDEX idx_characters_active_ship ON characters(active_ship_item_id);
```

**Key Features:**
- One account can have multiple characters
- Attributes range: 20-50 (default 20)
- Wallet balance in credits (integer for precision)
- Security status: -10 (criminal) to +10 (lawful)
- Active ship reference (nullable)

---

### 3. `character_locations` Table

**Purpose:** Character position in 3D space

```sql
CREATE TABLE character_locations (
    id                  UUID PRIMARY KEY DEFAULT gen_random_uuid(),
    character_id        UUID UNIQUE NOT NULL REFERENCES characters(id) ON DELETE CASCADE,
    solar_system_id     UUID REFERENCES solar_systems(id) ON DELETE SET NULL,
    station_id          UUID REFERENCES stations(id) ON DELETE SET NULL,
    
    position_x          DOUBLE PRECISION DEFAULT 0,
    position_y          DOUBLE PRECISION DEFAULT 0,
    position_z          DOUBLE PRECISION DEFAULT 0,
    
    rotation_pitch      FLOAT DEFAULT 0,
    rotation_yaw        FLOAT DEFAULT 0,
    rotation_roll       FLOAT DEFAULT 0,
    
    is_docked           BOOLEAN DEFAULT TRUE,  -- True = in station, False = in space
    
    updated_at          TIMESTAMP DEFAULT NOW()
);

CREATE INDEX idx_character_locations_character_id ON character_locations(character_id);
CREATE INDEX idx_character_locations_system ON character_locations(solar_system_id);
CREATE INDEX idx_character_locations_station ON character_locations(station_id);
```

**Key Features:**
- One location per character (UNIQUE constraint)
- DOUBLE PRECISION for large coordinate values (UE5 world scale)
- `is_docked` determines if player is in station or space
- `station_id` null when in space

---

### 4. `account_sessions` Table

**Purpose:** JWT refresh token storage

```sql
CREATE TABLE account_sessions (
    id                  UUID PRIMARY KEY DEFAULT gen_random_uuid(),
    account_id          UUID NOT NULL REFERENCES accounts(id) ON DELETE CASCADE,
    refresh_token       TEXT UNIQUE NOT NULL,
    expires_at          TIMESTAMP NOT NULL,
    created_at          TIMESTAMP DEFAULT NOW(),
    ip_address          VARCHAR(45),  -- IPv4 or IPv6
    user_agent          TEXT
);

CREATE INDEX idx_account_sessions_account_id ON account_sessions(account_id);
CREATE INDEX idx_account_sessions_token ON account_sessions(refresh_token);
CREATE INDEX idx_account_sessions_expires ON account_sessions(expires_at);
```

**Usage:**
- Store refresh tokens for "remember me" functionality
- Clean up expired tokens with scheduled job
- Track login devices/IPs for security

---

### 5. `character_skills` Table

**Purpose:** Skills trained by characters

```sql
CREATE TABLE character_skills (
    id                  UUID PRIMARY KEY DEFAULT gen_random_uuid(),
    character_id        UUID NOT NULL REFERENCES characters(id) ON DELETE CASCADE,
    skill_id            UUID NOT NULL REFERENCES skills(id) ON DELETE CASCADE,
    level               INTEGER NOT NULL DEFAULT 1,
    skill_points        BIGINT NOT NULL DEFAULT 0,
    
    CONSTRAINT chk_skill_level CHECK (level BETWEEN 1 AND 5),
    CONSTRAINT uq_character_skill UNIQUE(character_id, skill_id)
);

CREATE INDEX idx_character_skills_character_id ON character_skills(character_id);
CREATE INDEX idx_character_skills_skill_id ON character_skills(skill_id);
```

---

### 6. `character_wallets` Table

**Purpose:** Multi-currency wallet system (future Credits + PLEX support)

```sql
CREATE TABLE character_wallets (
    id                  UUID PRIMARY KEY DEFAULT gen_random_uuid(),
    character_id        UUID UNIQUE NOT NULL REFERENCES characters(id) ON DELETE CASCADE,
    isk_balance         BIGINT DEFAULT 0,
    plex_balance        INTEGER DEFAULT 0,
    loyalty_points      INTEGER DEFAULT 0,
    
    updated_at          TIMESTAMP DEFAULT NOW()
);

CREATE INDEX idx_character_wallets_character_id ON character_wallets(character_id);
```

**Note:** Currently wallet_balance on `characters` table is primary. This table for future multi-currency expansion.

---

### 7. `wallet_transactions` Table

**Purpose:** Complete financial audit trail

```sql
CREATE TABLE wallet_transactions (
    id                  BIGSERIAL PRIMARY KEY,
    character_id        UUID NOT NULL REFERENCES characters(id) ON DELETE CASCADE,
    transaction_type    VARCHAR(50) NOT NULL,  -- See enum below
    amount              BIGINT NOT NULL,  -- Positive = credit, Negative = debit
    balance_after       BIGINT NOT NULL,
    reference_id        UUID,  -- Shop item, contract, etc.
    description         TEXT,
    created_at          TIMESTAMP DEFAULT NOW()
);

CREATE INDEX idx_wallet_transactions_character_id ON wallet_transactions(character_id);
CREATE INDEX idx_wallet_transactions_type ON wallet_transactions(transaction_type);
CREATE INDEX idx_wallet_transactions_created ON wallet_transactions(created_at DESC);
```

**Transaction Types:**
```
MarketBuy, MarketSell, ContractReward, MissionReward, 
Bounty, Insurance, Refund, AdminCredit, AdminDebit, 
Transfer, Fee, Tax, Donation
```

**Example Records:**
```sql
-- Purchase from shop
INSERT INTO wallet_transactions VALUES (
    character_id: 'abc-123',
    transaction_type: 'MarketBuy',
    amount: -500000,  -- Negative = debit
    balance_after: 500000,
    reference_id: 'shop-item-guid',
    description: 'Purchased Quantum Drive Module'
);
```

---

## Universe Generation

### 8. `regions` Table

**Purpose:** Top-level universe structure (e.g., "Genesis Region")

```sql
CREATE TABLE regions (
    id                  UUID PRIMARY KEY DEFAULT gen_random_uuid(),
    name                VARCHAR(100) UNIQUE NOT NULL,
    description         TEXT,
    
    x_offset            DOUBLE PRECISION DEFAULT 0,
    y_offset            DOUBLE PRECISION DEFAULT 0,
    z_offset            DOUBLE PRECISION DEFAULT 0,
    
    created_at          TIMESTAMP DEFAULT NOW()
);

CREATE INDEX idx_regions_name ON regions(name);
```

---

### 9. `constellations` Table

**Purpose:** Group of solar systems within a region

```sql
CREATE TABLE constellations (
    id                  UUID PRIMARY KEY DEFAULT gen_random_uuid(),
    region_id           UUID NOT NULL REFERENCES regions(id) ON DELETE CASCADE,
    name                VARCHAR(100) NOT NULL,
    description         TEXT,
    
    x_offset            DOUBLE PRECISION DEFAULT 0,
    y_offset            DOUBLE PRECISION DEFAULT 0,
    z_offset            DOUBLE PRECISION DEFAULT 0,
    
    created_at          TIMESTAMP DEFAULT NOW(),
    
    CONSTRAINT uq_constellation_name_per_region UNIQUE(region_id, name)
);

CREATE INDEX idx_constellations_region_id ON constellations(region_id);
CREATE INDEX idx_constellations_name ON constellations(name);
```

---

### 10. `solar_systems` Table

**Purpose:** Individual star systems (e.g., "Genesis Prime")

```sql
CREATE TABLE solar_systems (
    id                  UUID PRIMARY KEY DEFAULT gen_random_uuid(),
    constellation_id    UUID NOT NULL REFERENCES constellations(id) ON DELETE CASCADE,
    name                VARCHAR(100) NOT NULL,
    security_status     FLOAT NOT NULL DEFAULT 1.0,  -- 0.0=Null, 0.1-0.4=Low, 0.5-1.0=High
    
    position_x          DOUBLE PRECISION NOT NULL,
    position_y          DOUBLE PRECISION NOT NULL,
    position_z          DOUBLE PRECISION NOT NULL,
    
    star_type           VARCHAR(50),  -- O, B, A, F, G, K, M
    star_temperature    INTEGER,
    star_radius         DOUBLE PRECISION,
    
    has_station         BOOLEAN DEFAULT FALSE,
    has_stargate        BOOLEAN DEFAULT FALSE,
    
    created_at          TIMESTAMP DEFAULT NOW(),
    
    CONSTRAINT chk_security_status CHECK (security_status BETWEEN 0.0 AND 1.0),
    CONSTRAINT uq_system_name_per_constellation UNIQUE(constellation_id, name)
);

CREATE INDEX idx_solar_systems_constellation_id ON solar_systems(constellation_id);
CREATE INDEX idx_solar_systems_name ON solar_systems(name);
CREATE INDEX idx_solar_systems_security ON solar_systems(security_status);
```

**Security Levels:**
- **1.0-0.5**: High-sec (CONCORD protection, safe for newbies)
- **0.4-0.1**: Low-sec (limited protection, PvP allowed)
- **0.0**: Null-sec (lawless, full PvP, player sovereignty)

---

### 11. `planets` Table

**Purpose:** Celestial bodies in solar systems

```sql
CREATE TABLE planets (
    id                  UUID PRIMARY KEY DEFAULT gen_random_uuid(),
    solar_system_id     UUID NOT NULL REFERENCES solar_systems(id) ON DELETE CASCADE,
    name                VARCHAR(100) NOT NULL,
    planet_type         VARCHAR(50) NOT NULL,  -- Terrestrial, Gas Giant, Ice, Lava
    
    position_x          DOUBLE PRECISION NOT NULL,
    position_y          DOUBLE PRECISION NOT NULL,
    position_z          DOUBLE PRECISION NOT NULL,
    
    radius              DOUBLE PRECISION NOT NULL,  -- In kilometers
    mass                DOUBLE PRECISION,
    orbital_period      DOUBLE PRECISION,  -- Days
    
    temperature         INTEGER,  -- Kelvin
    has_atmosphere      BOOLEAN DEFAULT FALSE,
    
    created_at          TIMESTAMP DEFAULT NOW(),
    
    CONSTRAINT uq_planet_name_per_system UNIQUE(solar_system_id, name)
);

CREATE INDEX idx_planets_solar_system_id ON planets(solar_system_id);
CREATE INDEX idx_planets_name ON planets(name);
CREATE INDEX idx_planets_type ON planets(planet_type);
```

**Example:** Genesis Prime system has 8 planets (Genesis I through Genesis VIII)

---

### 12. `moons` Table

**Purpose:** Satellites orbiting planets

```sql
CREATE TABLE moons (
    id                  UUID PRIMARY KEY DEFAULT gen_random_uuid(),
    planet_id           UUID NOT NULL REFERENCES planets(id) ON DELETE CASCADE,
    name                VARCHAR(100) NOT NULL,
    moon_index          INTEGER NOT NULL,  -- 1, 2, 3... for naming (Planet I - Moon 1)
    
    position_x          DOUBLE PRECISION NOT NULL,
    position_y          DOUBLE PRECISION NOT NULL,
    position_z          DOUBLE PRECISION NOT NULL,
    
    radius              DOUBLE PRECISION NOT NULL,
    orbital_period      DOUBLE PRECISION,
    
    has_resources       BOOLEAN DEFAULT FALSE,
    
    created_at          TIMESTAMP DEFAULT NOW(),
    
    CONSTRAINT uq_moon_index_per_planet UNIQUE(planet_id, moon_index)
);

CREATE INDEX idx_moons_planet_id ON moons(planet_id);
CREATE INDEX idx_moons_name ON moons(name);
```

**Example:** "Genesis III - Moon 7" (7th moon of 3rd planet in Genesis)

---

### 13. `stations` Table

**Purpose:** Docking locations for players (space stations)

```sql
CREATE TABLE stations (
    id                  UUID PRIMARY KEY DEFAULT gen_random_uuid(),
    solar_system_id     UUID NOT NULL REFERENCES solar_systems(id) ON DELETE CASCADE,
    planet_id           UUID REFERENCES planets(id) ON DELETE SET NULL,
    name                VARCHAR(100) NOT NULL,
    station_type        VARCHAR(50) NOT NULL,  -- Station, Outpost, Citadel
    
    position_x          DOUBLE PRECISION NOT NULL,
    position_y          DOUBLE PRECISION NOT NULL,
    position_z          DOUBLE PRECISION NOT NULL,
    
    has_market          BOOLEAN DEFAULT TRUE,
    has_repair          BOOLEAN DEFAULT TRUE,
    has_reprocessing    BOOLEAN DEFAULT FALSE,
    has_manufacturing   BOOLEAN DEFAULT FALSE,
    
    docking_range       DOUBLE PRECISION DEFAULT 5000.0,  -- Meters
    
    owner_corporation   UUID,
    
    created_at          TIMESTAMP DEFAULT NOW(),
    
    CONSTRAINT uq_station_name_per_system UNIQUE(solar_system_id, name)
);

CREATE INDEX idx_stations_solar_system_id ON stations(solar_system_id);
CREATE INDEX idx_stations_name ON stations(name);
CREATE INDEX idx_stations_planet_id ON stations(planet_id);
```

**Station Types:**
- **Station**: NPC-owned, full services
- **Outpost**: Player-owned, limited services
- **Citadel**: Large player structure

---

### 14. `stargates` Table

**Purpose:** Jump gates connecting solar systems

```sql
CREATE TABLE stargates (
    id                  UUID PRIMARY KEY DEFAULT gen_random_uuid(),
    solar_system_id     UUID NOT NULL REFERENCES solar_systems(id) ON DELETE CASCADE,
    destination_system_id UUID NOT NULL REFERENCES solar_systems(id) ON DELETE CASCADE,
    name                VARCHAR(100) NOT NULL,
    
    position_x          DOUBLE PRECISION NOT NULL,
    position_y          DOUBLE PRECISION NOT NULL,
    position_z          DOUBLE PRECISION NOT NULL,
    
    activation_range    DOUBLE PRECISION DEFAULT 5000.0,  -- Meters
    jump_delay          FLOAT DEFAULT 3.0,  -- Seconds
    
    created_at          TIMESTAMP DEFAULT NOW(),
    
    CONSTRAINT chk_no_self_gate CHECK (solar_system_id != destination_system_id),
    CONSTRAINT uq_stargate_name_per_system UNIQUE(solar_system_id, name)
);

CREATE INDEX idx_stargates_solar_system_id ON stargates(solar_system_id);
CREATE INDEX idx_stargates_destination_id ON stargates(destination_system_id);
```

**Key Feature:** Bidirectional links - if gate A→B exists, gate B→A also exists.

---

### 15. `asteroid_belts` Table

**Purpose:** Mining locations

```sql
CREATE TABLE asteroid_belts (
    id                  UUID PRIMARY KEY DEFAULT gen_random_uuid(),
    solar_system_id     UUID NOT NULL REFERENCES solar_systems(id) ON DELETE CASCADE,
    name                VARCHAR(100) NOT NULL,
    belt_index          INTEGER NOT NULL,
    
    position_x          DOUBLE PRECISION NOT NULL,
    position_y          DOUBLE PRECISION NOT NULL,
    position_z          DOUBLE PRECISION NOT NULL,
    
    radius              DOUBLE PRECISION DEFAULT 50000.0,  -- Meters
    
    ore_type            VARCHAR(50),  -- Veldspar, Scordite, Pyroxeres, etc.
    respawn_time        INTEGER DEFAULT 3600,  -- Seconds
    
    created_at          TIMESTAMP DEFAULT NOW(),
    
    CONSTRAINT uq_asteroid_belt_per_system UNIQUE(solar_system_id, belt_index)
);

CREATE INDEX idx_asteroid_belts_solar_system_id ON asteroid_belts(solar_system_id);
```

---

### 16. `anomalies` Table

**Purpose:** PvE combat sites

```sql
CREATE TABLE anomalies (
    id                  UUID PRIMARY KEY DEFAULT gen_random_uuid(),
    solar_system_id     UUID NOT NULL REFERENCES solar_systems(id) ON DELETE CASCADE,
    anomaly_type        VARCHAR(50) NOT NULL,  -- Combat, Data, Relic, Gas
    difficulty          VARCHAR(20),  -- Easy, Medium, Hard, Elite
    
    position_x          DOUBLE PRECISION NOT NULL,
    position_y          DOUBLE PRECISION NOT NULL,
    position_z          DOUBLE PRECISION NOT NULL,
    
    is_completed        BOOLEAN DEFAULT FALSE,
    respawn_time        INTEGER,  -- Seconds until respawn
    
    created_at          TIMESTAMP DEFAULT NOW(),
    completed_at        TIMESTAMP
);

CREATE INDEX idx_anomalies_solar_system_id ON anomalies(solar_system_id);
CREATE INDEX idx_anomalies_type ON anomalies(anomaly_type);
CREATE INDEX idx_anomalies_completed ON anomalies(is_completed);
```

---

### 17. `wormholes` Table

**Purpose:** Temporary unstable connections

```sql
CREATE TABLE wormholes (
    id                  UUID PRIMARY KEY DEFAULT gen_random_uuid(),
    source_system_id    UUID NOT NULL REFERENCES solar_systems(id) ON DELETE CASCADE,
    destination_system_id UUID NOT NULL REFERENCES solar_systems(id) ON DELETE CASCADE,
    
    position_x          DOUBLE PRECISION NOT NULL,
    position_y          DOUBLE PRECISION NOT NULL,
    position_z          DOUBLE PRECISION NOT NULL,
    
    stability           FLOAT DEFAULT 100.0,  -- 0-100%, decreases with use
    max_mass_per_jump   DOUBLE PRECISION,  -- Kg
    total_mass_limit    DOUBLE PRECISION,  -- Kg (collapses when exceeded)
    
    expires_at          TIMESTAMP NOT NULL,
    created_at          TIMESTAMP DEFAULT NOW(),
    
    CONSTRAINT chk_stability CHECK (stability BETWEEN 0 AND 100)
);

CREATE INDEX idx_wormholes_source_system ON wormholes(source_system_id);
CREATE INDEX idx_wormholes_destination_system ON wormholes(destination_system_id);
CREATE INDEX idx_wormholes_expires ON wormholes(expires_at);
```

---

## Inventory & Items

### 18. `item_categories` Table

**Purpose:** Top-level item classification

```sql
CREATE TABLE item_categories (
    id                  INTEGER PRIMARY KEY,
    name                VARCHAR(100) UNIQUE NOT NULL,
    description         TEXT,
    icon                VARCHAR(255),
    published           BOOLEAN DEFAULT TRUE
);

INSERT INTO item_categories VALUES
(1, 'Ships', 'Spaceship hulls', 'icon_ships.png', true),
(2, 'Modules', 'Ship equipment', 'icon_modules.png', true),
(3, 'Ammunition', 'Weapon charges', 'icon_ammo.png', true),
(4, 'Blueprints', 'Manufacturing plans', 'icon_blueprints.png', true),
(5, 'Resources', 'Ores and minerals', 'icon_resources.png', true);
```

---

### 19. `item_groups` Table

**Purpose:** Sub-categories

```sql
CREATE TABLE item_groups (
    id                  INTEGER PRIMARY KEY,
    category_id         INTEGER NOT NULL REFERENCES item_categories(id),
    name                VARCHAR(100) NOT NULL,
    description         TEXT,
    published           BOOLEAN DEFAULT TRUE,
    
    CONSTRAINT uq_group_name_per_category UNIQUE(category_id, name)
);

INSERT INTO item_groups VALUES
(100, 1, 'Frigates', 'Small fast ships', true),
(101, 1, 'Cruisers', 'Medium combat ships', true),
(102, 1, 'Battleships', 'Large combat ships', true),
(200, 2, 'Weapons', 'Turrets and launchers', true),
(201, 2, 'Shield Modules', 'Shield boosters and hardeners', true);
```

---

### 20. `item_types_inventory` Table

**Purpose:** Specific item definitions

```sql
CREATE TABLE item_types_inventory (
    id                  UUID PRIMARY KEY DEFAULT gen_random_uuid(),
    type_id             INTEGER UNIQUE NOT NULL,  -- Static reference ID
    name                VARCHAR(200) UNIQUE NOT NULL,
    group_id            INTEGER NOT NULL REFERENCES item_groups(id),
    description         TEXT,
    
    volume              DOUBLE PRECISION DEFAULT 0,  -- m³
    mass                DOUBLE PRECISION DEFAULT 0,  -- kg
    base_price          BIGINT DEFAULT 0,  -- Credits
    
    icon                VARCHAR(255),
    published           BOOLEAN DEFAULT TRUE,
    
    -- Ship-specific
    cpu_output          INTEGER,
    power_output        INTEGER,
    cargo_capacity      DOUBLE PRECISION,
    max_velocity        DOUBLE PRECISION,
    
    -- Module-specific
    cpu_requirement     INTEGER,
    power_requirement   INTEGER,
    activation_cost     INTEGER,
    
    created_at          TIMESTAMP DEFAULT NOW()
);

CREATE INDEX idx_item_types_group_id ON item_types_inventory(group_id);
CREATE INDEX idx_item_types_name ON item_types_inventory(name);
CREATE INDEX idx_item_types_type_id ON item_types_inventory(type_id);
```

---

### 21. `assets` Table

**Purpose:** Player-owned item instances

```sql
CREATE TABLE assets (
    id                  UUID PRIMARY KEY DEFAULT gen_random_uuid(),
    character_id        UUID NOT NULL REFERENCES characters(id) ON DELETE CASCADE,
    item_type_id        UUID NOT NULL REFERENCES item_types_inventory(id),
    
    quantity            INTEGER DEFAULT 1,
    location_type       VARCHAR(50) NOT NULL,  -- Station, Ship, Space
    location_id         UUID,  -- Station ID or Ship ID
    
    is_fitted           BOOLEAN DEFAULT FALSE,  -- Is module fitted to ship?
    fitted_ship_id      UUID REFERENCES assets(id) ON DELETE CASCADE,
    slot_index          INTEGER,
    
    is_singleton        BOOLEAN DEFAULT FALSE,  -- True for ships, false for stackables
    
    created_at          TIMESTAMP DEFAULT NOW(),
    
    CONSTRAINT chk_quantity_positive CHECK (quantity > 0)
);

CREATE INDEX idx_assets_character_id ON assets(character_id);
CREATE INDEX idx_assets_item_type_id ON assets(item_type_id);
CREATE INDEX idx_assets_location_id ON assets(location_id);
CREATE INDEX idx_assets_fitted_ship ON assets(fitted_ship_id);
```

**Key Concepts:**
- **Singleton**: Ships are unique instances (quantity=1 always)
- **Stackable**: Ammo/resources can stack (quantity>1)
- **Fitted**: Modules on ships have `is_fitted=true` and reference `fitted_ship_id`

---

### 22. `ships` Table

**Purpose:** Player ship instances (extends assets)

```sql
CREATE TABLE ships (
    id                  UUID PRIMARY KEY REFERENCES assets(id) ON DELETE CASCADE,
    ship_name           VARCHAR(100),  -- Player-given name (e.g., "My Frigate")
    
    hull_damage         FLOAT DEFAULT 0,  -- 0-100%
    armor_damage        FLOAT DEFAULT 0,
    shield_damage       FLOAT DEFAULT 0,
    
    capacitor_charge    FLOAT DEFAULT 100,  -- 0-100%
    fuel_remaining      INTEGER DEFAULT 0,
    
    CONSTRAINT chk_damage_percent CHECK (
        hull_damage BETWEEN 0 AND 100 AND
        armor_damage BETWEEN 0 AND 100 AND
        shield_damage BETWEEN 0 AND 100
    )
);

CREATE INDEX idx_ships_ship_name ON ships(ship_name);
```

---

### 23. `player_inventory_items` Table

**Purpose:** Web purchase queue (items bought on website, redeemable in-game)

```sql
CREATE TABLE player_inventory_items (
    id                  UUID PRIMARY KEY DEFAULT gen_random_uuid(),
    player_id           UUID NOT NULL REFERENCES characters(id) ON DELETE CASCADE,
    shop_item_id        UUID NOT NULL REFERENCES shop_items(id),
    
    is_redeemed         BOOLEAN DEFAULT FALSE,
    redeemed_at         TIMESTAMP,
    
    created_at          TIMESTAMP DEFAULT NOW()
);

CREATE INDEX idx_player_inventory_items_player_id ON player_inventory_items(player_id);
CREATE INDEX idx_player_inventory_items_shop_item ON player_inventory_items(shop_item_id);
CREATE INDEX idx_player_inventory_items_redeemed ON player_inventory_items(is_redeemed);
```

**Flow:**
1. Player buys item on web shop
2. Record created with `is_redeemed = false`
3. Player logs into game
4. Game client calls `/api/inventory/redeem/{id}`
5. API creates asset in player's hangar
6. Set `is_redeemed = true`

---

## Economy & Trading

### 24. `shop_items` Table

**Purpose:** Marketplace catalog (Imperial Store)

```sql
CREATE TABLE shop_items (
    id                  UUID PRIMARY KEY DEFAULT gen_random_uuid(),
    name                VARCHAR(200) NOT NULL,
    description         TEXT,
    price               BIGINT NOT NULL,  -- Credits cost
    
    image_url           VARCHAR(500),
    category            VARCHAR(50),  -- Equipment, Credits, VIP, Consumables, Cosmetic
    
    item_type_id        UUID REFERENCES item_types_inventory(id),  -- Link to actual item
    
    is_active           BOOLEAN DEFAULT TRUE,
    is_featured         BOOLEAN DEFAULT FALSE,
    
    stock_quantity      INTEGER,  -- NULL = unlimited
    purchases_count     INTEGER DEFAULT 0,
    
    created_at          TIMESTAMP DEFAULT NOW(),
    updated_at          TIMESTAMP DEFAULT NOW(),
    
    CONSTRAINT chk_price_positive CHECK (price > 0)
);

CREATE INDEX idx_shop_items_category ON shop_items(category);
CREATE INDEX idx_shop_items_active ON shop_items(is_active);
CREATE INDEX idx_shop_items_featured ON shop_items(is_featured);
CREATE INDEX idx_shop_items_item_type ON shop_items(item_type_id);
```

**Categories:**
- **Equipment**: Ships, modules, ammo
- **Credits**: Credit bundles
- **VIP**: Subscription packs
- **Consumables**: Boosters, skill extractors
- **Cosmetic**: Ship skins

---

## Game Server Management

### 25. `game_servers` Table

**Purpose:** UE5 dedicated server registration

```sql
CREATE TABLE game_servers (
    id                  UUID PRIMARY KEY DEFAULT gen_random_uuid(),
    server_name         VARCHAR(100) UNIQUE NOT NULL,
    server_type         VARCHAR(50) NOT NULL,  -- DedicatedSystem, RegionalCluster
    
    ip_address          VARCHAR(45) NOT NULL,
    port                INTEGER NOT NULL,
    
    solar_system_id     UUID REFERENCES solar_systems(id),  -- For DedicatedSystem
    region_id           UUID REFERENCES regions(id),  -- For RegionalCluster
    
    status              VARCHAR(20) DEFAULT 'Starting',  -- Starting, Running, Stopping, Crashed
    current_players     INTEGER DEFAULT 0,
    max_players         INTEGER DEFAULT 100,
    
    jwt_token           TEXT,  -- Server's JWT token for API calls
    
    last_heartbeat      TIMESTAMP DEFAULT NOW(),
    created_at          TIMESTAMP DEFAULT NOW(),
    
    CONSTRAINT chk_port_range CHECK (port BETWEEN 1024 AND 65535)
);

CREATE INDEX idx_game_servers_server_name ON game_servers(server_name);
CREATE INDEX idx_game_servers_status ON game_servers(status);
CREATE INDEX idx_game_servers_solar_system ON game_servers(solar_system_id);
CREATE INDEX idx_game_servers_heartbeat ON game_servers(last_heartbeat);
```

**Server Types:**
- **DedicatedSystem**: One server per solar system (e.g., Genesis Prime server)
- **RegionalCluster**: One server handles multiple systems in a region

---

## Content Management

### 26. `news_posts` Table

**Purpose:** News & edicts system

```sql
CREATE TABLE news_posts (
    id                  UUID PRIMARY KEY DEFAULT gen_random_uuid(),
    title               VARCHAR(200) NOT NULL,
    content             TEXT NOT NULL,
    image_url           VARCHAR(500),
    
    author_name         VARCHAR(100),
    
    created_at          TIMESTAMP DEFAULT NOW(),
    updated_at          TIMESTAMP DEFAULT NOW()
);

CREATE INDEX idx_news_posts_created ON news_posts(created_at DESC);
```

---

### 27. `wiki_pages` Table

**Purpose:** Knowledge base articles

```sql
CREATE TABLE wiki_pages (
    id                  UUID PRIMARY KEY DEFAULT gen_random_uuid(),
    section_name        VARCHAR(100) NOT NULL,
    title               VARCHAR(200) NOT NULL,
    content_html        TEXT NOT NULL,
    
    last_updated_by     VARCHAR(100),
    
    created_at          TIMESTAMP DEFAULT NOW(),
    updated_at          TIMESTAMP DEFAULT NOW(),
    
    CONSTRAINT uq_wiki_page_section_title UNIQUE(section_name, title)
);

CREATE INDEX idx_wiki_pages_section ON wiki_pages(section_name);
CREATE INDEX idx_wiki_pages_title ON wiki_pages(title);
```

---

## Cascade & Restrict Rules

### Universe Cleanup (CASCADE)

**Problem:** When wiping/regenerating universe, need to clean all related data.

**Solution:** CASCADE deletions

```sql
-- Delete region → cascades to constellations, systems, planets, moons, stations
DELETE FROM regions WHERE id = 'genesis-region-id';

-- Cascade chain:
regions
  └→ constellations (CASCADE)
      └→ solar_systems (CASCADE)
          ├→ planets (CASCADE)
          │   └→ moons (CASCADE)
          ├→ stations (CASCADE)
          ├→ stargates (CASCADE)
          ├→ asteroid_belts (CASCADE)
          ├→ anomalies (CASCADE)
          └→ wormholes (CASCADE)
```

### Character Protection (RESTRICT)

**Problem:** Don't want to accidentally delete characters when deleting other entities.

**Solution:** RESTRICT or SET NULL

```sql
-- Can't delete station if characters are docked there
-- character_locations.station_id → stations.id ON DELETE RESTRICT

-- Can delete solar system, characters stay but location nullified
-- character_locations.solar_system_id → solar_systems.id ON DELETE SET NULL
```

### Account Deletion (CASCADE)

**Problem:** When deleting account, remove all associated data.

**Solution:** Full CASCADE chain

```sql
DELETE FROM accounts WHERE id = 'account-id';

-- Cascade chain:
accounts
  ├→ characters (CASCADE)
  │   ├→ character_locations (CASCADE)
  │   ├→ character_skills (CASCADE)
  │   ├→ wallet_transactions (CASCADE)
  │   ├→ assets (CASCADE)
  │   │   └→ ships (CASCADE)
  │   └→ player_inventory_items (CASCADE)
  └→ account_sessions (CASCADE)
```

### Referential Integrity Summary

| Parent Table | Child Table | Delete Rule | Reason |
|--------------|-------------|-------------|---------|
| accounts | characters | CASCADE | Delete pilot with account |
| characters | assets | CASCADE | Delete items with pilot |
| characters | character_locations | CASCADE | Delete location with pilot |
| characters | wallet_transactions | CASCADE | Keep full history with pilot |
| regions | constellations | CASCADE | Universe regeneration |
| solar_systems | planets | CASCADE | Universe regeneration |
| planets | moons | CASCADE | Universe regeneration |
| stations | character_locations | SET NULL | Don't delete pilots if station removed |
| assets | ships | CASCADE | Ship data linked to asset |
| shop_items | player_inventory_items | RESTRICT | Can't delete item if purchased |

---

## Indexes & Performance

### Critical Indexes

```sql
-- Authentication lookups (high frequency)
CREATE INDEX idx_accounts_username ON accounts(username);
CREATE INDEX idx_accounts_email ON accounts(email);

-- Character queries (very high frequency)
CREATE INDEX idx_characters_account_id ON characters(account_id);
CREATE INDEX idx_characters_name ON characters(name);

-- Spatial queries (game world)
CREATE INDEX idx_character_locations_system ON character_locations(solar_system_id);
CREATE INDEX idx_stargates_destination ON stargates(destination_system_id);

-- Inventory lookups (high frequency)
CREATE INDEX idx_assets_character_id ON assets(character_id);
CREATE INDEX idx_assets_location_id ON assets(location_id);

-- Financial queries
CREATE INDEX idx_wallet_transactions_character ON wallet_transactions(character_id);
CREATE INDEX idx_wallet_transactions_created ON wallet_transactions(created_at DESC);

-- Server management
CREATE INDEX idx_game_servers_heartbeat ON game_servers(last_heartbeat);
```

### Query Optimization Tips

**1. Use EXPLAIN ANALYZE for slow queries**
```sql
EXPLAIN ANALYZE
SELECT * FROM characters WHERE account_id = 'abc-123';
```

**2. Partial indexes for filtered queries**
```sql
-- Only index active shop items
CREATE INDEX idx_shop_items_active_category 
ON shop_items(category) 
WHERE is_active = TRUE;
```

**3. Composite indexes for multi-column queries**
```sql
-- For queries filtering by both character and location
CREATE INDEX idx_assets_character_location 
ON assets(character_id, location_id);
```

---

## Database Maintenance

### Scheduled Jobs

**1. Clean Expired Sessions**
```sql
DELETE FROM account_sessions 
WHERE expires_at < NOW();
```

**2. Clean Completed Anomalies**
```sql
DELETE FROM anomalies 
WHERE is_completed = TRUE 
  AND completed_at < NOW() - INTERVAL '1 hour';
```

**3. Vacuum & Analyze (Weekly)**
```sql
VACUUM ANALYZE;
```

### Backup Strategy

```bash
# Daily full backup
pg_dump echoes_database > backup_$(date +%Y%m%d).sql

# Continuous WAL archiving for point-in-time recovery
archive_mode = on
archive_command = 'cp %p /backup/archive/%f'
```

---

## Schema Version History

| Version | Date | Changes |
|---------|------|---------|
| 1.0 | 2026-01-15 | Initial schema |
| 1.5 | 2026-01-28 | Added shop_items, player_inventory_items |
| 1.8 | 2026-02-01 | Added news_posts, wiki_pages |
| 2.0 | 2026-02-03 | Added character attributes, combat stats |

---

## Conclusion

The Echoes of Imperial database schema provides:

✅ **50+ tables** covering all game systems  
✅ **ACID transactions** for financial operations  
✅ **Referential integrity** with CASCADE/RESTRICT rules  
✅ **Optimized indexes** for high-frequency queries  
✅ **Universe generation** with hierarchical structure  
✅ **Flexible inventory** supporting fits, stacks, locations  
✅ **Audit trails** for financial and administrative actions

**Next Steps:**
- See [ARCHITECTURE.md](ARCHITECTURE.md) for system architecture
- See [API_DOCUMENTATION.md](API_DOCUMENTATION.md) for endpoint reference
- See [FIX_LOG.md](FIX_LOG.md) for critical bug fixes history
