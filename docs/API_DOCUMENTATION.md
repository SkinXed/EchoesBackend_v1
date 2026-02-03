# Echoes of Imperial - API Documentation

> **Complete RESTful API Reference**  
> All endpoints with authentication requirements and examples

**Version:** 2.0  
**Last Updated:** 2026-02-03  
**Base URL:** `https://api.echoes-imperial.com` (production)  
**Base URL:** `https://localhost:5115` (development)

---

## Table of Contents

1. [Authentication](#authentication)
2. [Authorization Levels](#authorization-levels)
3. [API Endpoints by Category](#api-endpoints-by-category)
4. [Request/Response Formats](#requestresponse-formats)
5. [Error Codes](#error-codes)
6. [Rate Limiting](#rate-limiting)

---

## Authentication

### JWT Token Authentication

All authenticated endpoints require a JWT (JSON Web Token) in the `Authorization` header.

**Header Format:**
```http
Authorization: Bearer <your-jwt-token>
```

**Token Acquisition:**
```http
POST /api/auth/register
Content-Type: application/json

{
  "username": "pilot_name",
  "email": "pilot@echoes.com",
  "password": "SecurePassword123!"
}

Response:
{
  "token": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9...",
  "character": {
    "id": "character-guid",
    "name": "pilot_name",
    "race_id": 1
  }
}
```

**Token Claims:**
```json
{
  "sub": "character-guid",
  "email": "pilot@echoes.com",
  "role": "Pilot",  // or "Admin"
  "iat": 1738540800,
  "exp": 1738627200
}
```

### Server-to-Server Authentication

UE5 game servers use custom header authentication:

```http
X-Server-Secret: <configured-server-secret>
```

---

## Authorization Levels

| Level | Required | Description |
|-------|----------|-------------|
| **Public** | None | No authentication required |
| **[AllowAnonymous]** | None | Explicitly public (overrides controller default auth) |
| **[Authorize]** | JWT Token | Any authenticated user |
| **[Authorize(Roles = "Admin")]** | JWT Token + Admin Role | Admin-only operations |
| **Policy: PlayerAccess** | JWT + Custom Policy | Advanced player operations |
| **X-Server-Secret** | Custom Header | UE5 server-to-backend communication |

---

## API Endpoints by Category

### 🔐 Authentication & Authorization

#### POST /api/auth/register
**Authorization:** Public  
**Description:** Register new account and create character

**Request:**
```json
{
  "username": "pilot_name",
  "email": "pilot@echoes.com",
  "password": "SecurePass123!",
  "confirmPassword": "SecurePass123!",
  "race_id": 1
}
```

**Response:** `200 OK`
```json
{
  "token": "jwt-token-here",
  "character": {
    "id": "character-guid",
    "name": "pilot_name",
    "race_id": 1,
    "wallet_balance": 100000,
    "security_status": 0.0
  }
}
```

---

### 👤 Character Management

#### GET /api/character/me
**Authorization:** `[Authorize]`  
**Description:** Get current character data from JWT token

**Response:** `200 OK`
```json
{
  "id": "character-guid",
  "name": "Pilot Alpha",
  "race_id": 1,
  "race_name": "Caldari",
  "corporation_id": null,
  "intelligence": 20,
  "perception": 20,
  "charisma": 20,
  "willpower": 20,
  "memory": 20,
  "wallet_balance": 500000,
  "total_skill_points": 150000,
  "security_status": 5.2,
  "total_kills": 10,
  "total_deaths": 2,
  "ships_destroyed": 15,
  "ships_lost": 3
}
```

#### GET /api/character/profile
**Authorization:** `[Authorize]`  
**Description:** Get detailed character profile including location and active ship

**Response:** `200 OK`
```json
{
  "id": "character-guid",
  "name": "Pilot Alpha",
  "race_name": "Caldari",
  "corporation": "NPC Corp",
  "security_status": 5.2,
  "attributes": {
    "intelligence": 20,
    "perception": 20,
    "charisma": 20,
    "willpower": 20,
    "memory": 20
  },
  "wallet_balance": 500000,
  "total_isk_earned": 2000000,
  "total_isk_lost": 1500000,
  "total_skill_points": 150000,
  "unallocated_skill_points": 5000,
  "total_kills": 10,
  "total_deaths": 2,
  "ships_destroyed": 15,
  "ships_lost": 3,
  "active_ship_name": "Caldari Frigate",
  "location": {
    "solar_system_name": "Genesis Prime",
    "station_name": "Trade Hub Alpha",
    "is_docked": true
  }
}
```

#### GET /api/pilot/dashboard
**Authorization:** `[Authorize]`  
**Description:** Get pilot dashboard data

---

### 🌌 Universe & Map

#### GET /api/universe/map-data
**Authorization:** Public  
**Caching:** 5 minutes  
**Description:** Get complete universe map (systems + stargates)

**Response:** `200 OK`
```json
{
  "systems": [
    {
      "id": "system-guid",
      "name": "Genesis Prime",
      "security_status": 1.0,
      "position_x": 0,
      "position_y": 0,
      "position_z": 0,
      "constellation_name": "Genesis Core",
      "region_name": "Genesis"
    }
  ],
  "stargates": [
    {
      "id": "gate-guid",
      "source_system_id": "system-guid-1",
      "destination_system_id": "system-guid-2"
    }
  ]
}
```

#### GET /api/universe/systems
**Authorization:** Public  
**Query Parameters:**
- `page` (int, default 1)
- `pageSize` (int, default 100, max 1000)

**Response:** `200 OK`
```json
{
  "systems": [...],
  "total_count": 250,
  "page": 1,
  "page_size": 100
}
```

#### GET /api/universe/systems/{id}
**Authorization:** Public  
**Description:** Get detailed solar system info

**Response:** `200 OK`
```json
{
  "id": "system-guid",
  "name": "Genesis Prime",
  "security_status": 1.0,
  "constellation": {
    "id": "constellation-guid",
    "name": "Genesis Core"
  },
  "region": {
    "id": "region-guid",
    "name": "Genesis"
  },
  "planets": [
    {
      "id": "planet-guid",
      "name": "Genesis I",
      "planet_type": "Terrestrial",
      "radius": 6371.0,
      "position": { "x": 100000, "y": 0, "z": 0 },
      "moons": [
        {
          "id": "moon-guid",
          "name": "Genesis I - Moon 1",
          "radius": 1737.4,
          "position": { "x": 105000, "y": 0, "z": 0 }
        }
      ]
    }
  ],
  "stations": [
    {
      "id": "station-guid",
      "name": "Trade Hub Alpha",
      "station_type": "Station",
      "has_market": true,
      "has_repair": true,
      "position": { "x": 0, "y": 0, "z": 0 }
    }
  ],
  "stargates": [...],
  "asteroid_belts": [...]
}
```

#### GET /api/universe/search
**Authorization:** Public (Rate Limited)  
**Query Parameters:**
- `query` (string, min length 2)

**Response:** `200 OK`
```json
{
  "systems": [
    { "id": "guid", "name": "Genesis Prime", "type": "System" }
  ],
  "stations": [
    { "id": "guid", "name": "Trade Hub Alpha", "type": "Station" }
  ],
  "planets": [...]
}
```

#### GET /api/universe/nearby/{systemId}
**Authorization:** Public  
**Query Parameters:**
- `maxJumps` (int, default 5, max 10)

**Description:** Get systems within X jumps from specified system

#### POST /api/universe/generate
**Authorization:** Public  
**Description:** Start background universe generation task

**Response:** `202 Accepted`
```json
{
  "generation_id": "task-guid",
  "status": "InProgress",
  "message": "Universe generation started"
}
```

#### GET /api/universe/generation-status/{generationId}
**Authorization:** Public

**Response:** `200 OK`
```json
{
  "generation_id": "task-guid",
  "status": "Completed",
  "progress": 100,
  "systems_generated": 250,
  "planets_generated": 1200,
  "error": null
}
```

#### GET /api/universe/stats
**Authorization:** Public  
**Caching:** 5 minutes

**Response:** `200 OK`
```json
{
  "total_regions": 5,
  "total_constellations": 50,
  "total_systems": 250,
  "total_planets": 1200,
  "total_moons": 3500,
  "total_stations": 300,
  "total_stargates": 500
}
```

---

### 🚀 Ship & Fitting

#### GET /api/inventory/ships
**Authorization:** `[Authorize]`  
**Description:** Get all ships owned by current character

**Response:** `200 OK`
```json
{
  "ships": [
    {
      "id": "asset-guid",
      "ship_name": "My Frigate",
      "type_name": "Caldari Frigate",
      "location_type": "Station",
      "station_name": "Trade Hub Alpha",
      "hull_damage": 0,
      "armor_damage": 0,
      "shield_damage": 0,
      "is_active": true
    }
  ]
}
```

#### GET /api/inventory/ship/{id}/fitting
**Authorization:** `[Authorize]`  
**Description:** Get detailed ship fitting info

**Response:** `200 OK`
```json
{
  "ship_id": "asset-guid",
  "ship_name": "My Frigate",
  "type_name": "Caldari Frigate",
  "fitted_modules": [
    {
      "module_id": "module-guid",
      "type_name": "Light Missile Launcher I",
      "slot_index": 0,
      "slot_type": "High",
      "is_online": true
    }
  ],
  "stats": {
    "cpu_output": 200,
    "cpu_used": 35,
    "power_output": 1000,
    "power_used": 150,
    "cargo_capacity": 100.0,
    "max_velocity": 450.0,
    "shield_hp": 500,
    "armor_hp": 400,
    "hull_hp": 300
  }
}
```

#### POST /api/inventory/ship/{id}/activate
**Authorization:** `[Authorize]`  
**Description:** Set ship as active (current ship)

**Response:** `200 OK`

#### PUT /api/inventory/ship/{shipId}/module/{moduleId}/fit
**Authorization:** `[Authorize]`  
**Description:** Fit module to ship slot

**Request:**
```json
{
  "slot_index": 0,
  "slot_type": "High"
}
```

**Response:** `200 OK`
```json
{
  "success": true,
  "message": "Module fitted successfully",
  "updated_stats": { ... }
}
```

#### DELETE /api/inventory/ship/{shipId}/module/{moduleId}/unfit
**Authorization:** `[Authorize]`  
**Description:** Remove module from ship

**Response:** `200 OK`

#### GET /api/ship/{id}/stats
**Authorization:** Custom (X-Server-Secret)  
**Description:** Get calculated ship stats (UE5 server use)

**Response:** `200 OK`
```json
{
  "ship_id": "guid",
  "total_mass": 1500000.0,
  "cpu_used": 35,
  "cpu_output": 200,
  "power_used": 150,
  "power_output": 1000,
  "cargo_used": 50.0,
  "cargo_capacity": 100.0,
  "shield_hp": 500,
  "armor_hp": 400,
  "hull_hp": 300,
  "max_velocity": 450.0,
  "inertia_modifier": 1.0
}
```

---

### 📦 Inventory & Assets

#### GET /api/inventory/hangar/{stationId}
**Authorization:** `[Authorize]`  
**Description:** Get or create personal hangar at station

**Response:** `200 OK`
```json
{
  "hangar_id": "container-guid",
  "station_id": "station-guid",
  "station_name": "Trade Hub Alpha",
  "capacity": 1000000.0,
  "used_volume": 50000.0,
  "items": [
    {
      "asset_id": "asset-guid",
      "type_name": "Caldari Frigate",
      "quantity": 1,
      "volume": 2500.0
    }
  ]
}
```

#### GET /api/inventory/{assetId}
**Authorization:** Policy: PlayerAccess  
**Description:** Get asset by ID

#### GET /api/inventory/owner/{ownerId}
**Authorization:** Policy: PlayerAccess  
**Description:** Get all assets owned by player

#### POST /api/inventory/move
**Authorization:** Policy: PlayerAccess  
**Description:** Move asset to different container

**Request:**
```json
{
  "asset_id": "asset-guid",
  "destination_container_id": "container-guid"
}
```

#### POST /api/inventory/operations/split
**Authorization:** Policy: PlayerAccess  
**Description:** Split item stack into two

**Request:**
```json
{
  "asset_id": "asset-guid",
  "quantity": 50
}
```

#### POST /api/inventory/operations/merge
**Authorization:** Policy: PlayerAccess  
**Description:** Merge multiple stacks of same item

**Request:**
```json
{
  "source_asset_ids": ["guid1", "guid2", "guid3"],
  "destination_asset_id": "guid4"
}
```

---

### 🛒 Shop & Marketplace

#### GET /api/shop
**Authorization:** `[Authorize]`  
**Query Parameters:**
- `category` (string, optional): Equipment, Credits, VIP, Consumables, Cosmetic

**Description:** Get all active shop items

**Response:** `200 OK`
```json
{
  "items": [
    {
      "id": "shop-item-guid",
      "name": "Quantum Drive Module",
      "description": "Advanced propulsion system",
      "price": 500000,
      "image_url": "https://cdn.echoes.com/items/quantum-drive.png",
      "category": "Equipment",
      "is_active": true,
      "is_featured": false,
      "purchases_count": 125
    }
  ]
}
```

#### GET /api/shop/categories
**Authorization:** `[Authorize]`  
**Description:** Get shop categories with item counts

**Response:** `200 OK`
```json
{
  "categories": [
    {
      "name": "Equipment",
      "item_count": 45,
      "featured_count": 5
    },
    {
      "name": "Credits",
      "item_count": 8,
      "featured_count": 2
    }
  ]
}
```

#### GET /api/shop/{id}
**Authorization:** `[Authorize]`  
**Description:** Get specific shop item

#### POST /api/shop
**Authorization:** `[Authorize(Roles = "Admin")]`  
**Description:** Create new shop item (Admin only)

**Request:**
```json
{
  "name": "Quantum Drive Module",
  "description": "Advanced propulsion system for faster travel",
  "price": 500000,
  "image_url": "https://cdn.echoes.com/items/quantum-drive.png",
  "category": "Equipment",
  "item_type_id": "item-type-guid",
  "is_active": true,
  "is_featured": false,
  "stock_quantity": null
}
```

**Response:** `201 Created`

#### PUT /api/shop/{id}
**Authorization:** `[Authorize(Roles = "Admin")]`  
**Description:** Update shop item (Admin only)

#### DELETE /api/shop/{id}
**Authorization:** `[Authorize(Roles = "Admin")]`  
**Description:** Deactivate shop item (Admin only)

#### POST /api/shop/purchase/{id}
**Authorization:** `[Authorize]`  
**Description:** Purchase item with wallet balance

**Response:** `200 OK` (Success)
```json
{
  "success": true,
  "item": {
    "name": "Quantum Drive Module",
    "price": 500000
  },
  "previous_balance": 1000000,
  "new_balance": 500000,
  "transaction_id": 123456789
}
```

**Response:** `400 Bad Request` (Insufficient Funds)
```json
{
  "error": "Imperial Treasury: Insufficient Funds",
  "current_balance": 100000,
  "required_amount": 500000,
  "deficit": 400000
}
```

---

### 📰 News & Edicts

#### GET /api/news
**Authorization:** `[AllowAnonymous]`  
**Description:** Get all published news posts

**Response:** `200 OK`
```json
{
  "news": [
    {
      "id": "news-guid",
      "title": "Imperial Expansion Announced",
      "content": "<p>The Empire is expanding...</p>",
      "image_url": "https://cdn.echoes.com/news/expansion.jpg",
      "author_name": "Imperial Command",
      "created_at": "2026-02-03T10:00:00Z"
    }
  ]
}
```

#### POST /api/news
**Authorization:** `[Authorize(Roles = "Admin")]`  
**Description:** Create new news post (Admin only)

**Request:**
```json
{
  "title": "New System Discovered",
  "content": "<p>Explorers have found...</p>",
  "image_url": "https://cdn.echoes.com/news/discovery.jpg",
  "author_name": "Admiral Smith"
}
```

**Response:** `201 Created`

#### DELETE /api/news/{id}
**Authorization:** `[Authorize(Roles = "Admin")]`  
**Description:** Delete news post (Admin only)

---

### 📚 Wiki & Knowledge Base

#### GET /api/wiki
**Authorization:** `[AllowAnonymous]`  
**Description:** Get all published wiki pages

**Response:** `200 OK`
```json
{
  "pages": [
    {
      "id": "wiki-guid",
      "section_name": "Architecture",
      "title": "System Architecture",
      "content_html": "<h1>Architecture</h1><p>...</p>",
      "last_updated_by": "admin",
      "updated_at": "2026-02-03T12:00:00Z"
    }
  ]
}
```

#### GET /api/wiki/{id}
**Authorization:** `[AllowAnonymous]`  
**Description:** Get single wiki page

#### PUT /api/wiki/{id}
**Authorization:** `[Authorize(Roles = "Admin")]`  
**Description:** Update wiki page (Admin only)

**Request:**
```json
{
  "section_name": "Architecture",
  "title": "System Architecture (Updated)",
  "content_html": "<h1>Updated Content</h1>"
}
```

#### POST /api/wiki
**Authorization:** `[Authorize(Roles = "Admin")]`  
**Description:** Create new wiki page (Admin only)

---

### 🎮 Game Server Management

#### POST /api/server-management/register
**Authorization:** Public (Server-to-Server)  
**Description:** Register new game server instance

**Request:**
```json
{
  "server_name": "Genesis-Prime-01",
  "server_type": "DedicatedSystem",
  "ip_address": "192.168.1.100",
  "port": 7777,
  "solar_system_id": "system-guid",
  "max_players": 100
}
```

**Response:** `201 Created`
```json
{
  "server_id": "server-guid",
  "jwt_token": "server-jwt-token-here",
  "config": { ... }
}
```

#### POST /api/server-management/heartbeat
**Authorization:** Public (Server-to-Server)  
**Description:** Send server heartbeat/status update

**Request:**
```json
{
  "server_id": "server-guid",
  "current_players": 45,
  "status": "Running"
}
```

#### GET /api/server-management/list
**Authorization:** Public  
**Query Parameters:**
- `systemId` (guid, optional)
- `status` (string, optional)

**Description:** List all registered servers

#### POST /api/server-management/config
**Authorization:** Public (Server-to-Server)  
**Description:** Get server configuration (DedicatedSystem or RegionalCluster)

**Request:**
```json
{
  "server_id": "server-guid",
  "server_type": "DedicatedSystem",
  "solar_system_id": "system-guid"
}
```

**Response:** `200 OK`
```json
{
  "system_name": "Genesis Prime",
  "system_id": "system-guid",
  "security_status": 1.0,
  "planets": [
    {
      "id": "planet-guid",
      "name": "Genesis I",
      "position": { "x": 100000, "y": 0, "z": 0 },
      "radius": 6371.0,
      "planet_type": "Terrestrial",
      "moons": [...]
    }
  ],
  "stations": [...],
  "stargates": [...],
  "asteroid_belts": [...]
}
```

#### GET /api/gameserver/for-system/{systemId}
**Authorization:** Public  
**Description:** Get game server connection info for system

**Response:** `200 OK`
```json
{
  "server_id": "server-guid",
  "server_name": "Genesis-Prime-01",
  "ip_address": "game.echoes.com",
  "port": 7777,
  "current_players": 45,
  "max_players": 100,
  "status": "Running"
}
```

---

### 🗺️ Stargate & Travel

#### GET /api/stargate/system/{systemId}
**Authorization:** Public  
**Description:** Get all stargates in system

**Response:** `200 OK`
```json
{
  "stargates": [
    {
      "id": "gate-guid",
      "name": "Stargate (Genesis Prime)",
      "destination_system_id": "dest-system-guid",
      "destination_system_name": "Genesis II",
      "position": { "x": 500000, "y": 0, "z": 0 },
      "activation_range": 5000.0
    }
  ]
}
```

#### POST /api/stargate/jump
**Authorization:** Public  
**Description:** Execute stargate jump

**Request:**
```json
{
  "character_id": "character-guid",
  "stargate_id": "gate-guid"
}
```

**Response:** `200 OK`
```json
{
  "success": true,
  "destination_system_id": "dest-system-guid",
  "destination_system_name": "Genesis II",
  "new_position": { "x": 0, "y": 0, "z": 0 }
}
```

---

### 📊 Item Types & Definitions

#### GET /api/itemtype/categories
**Authorization:** Public  
**Description:** Get all item categories

**Response:** `200 OK`
```json
{
  "categories": [
    {
      "id": 1,
      "name": "Ships",
      "description": "Spaceship hulls",
      "icon": "icon_ships.png"
    },
    {
      "id": 2,
      "name": "Modules",
      "description": "Ship equipment",
      "icon": "icon_modules.png"
    }
  ]
}
```

#### GET /api/itemtype/categories/{categoryId}/groups
**Authorization:** Public  
**Description:** Get item groups in category

#### GET /api/itemtype/{typeId}
**Authorization:** Public  
**Description:** Get item type by ID

**Response:** `200 OK`
```json
{
  "id": "item-type-guid",
  "type_id": 1001,
  "name": "Caldari Frigate",
  "group_id": 100,
  "group_name": "Frigates",
  "category_id": 1,
  "category_name": "Ships",
  "description": "Fast attack frigate",
  "volume": 2500.0,
  "mass": 1000000.0,
  "base_price": 250000,
  "attributes": {
    "cpu_output": 200,
    "power_output": 1000,
    "cargo_capacity": 100.0,
    "max_velocity": 450.0
  }
}
```

#### GET /api/itemtype/search
**Authorization:** Public  
**Query Parameters:**
- `query` (string)
- `page` (int, default 1)
- `pageSize` (int, default 50)

**Description:** Search item types

#### GET /api/itemtype/ships
**Authorization:** Public  
**Query Parameters:**
- `raceId` (int, optional)

**Description:** Get all ship types

#### GET /api/itemtype/modules
**Authorization:** Public  
**Query Parameters:**
- `slotType` (string, optional): High, Medium, Low, Rig
- `category` (string, optional)

**Description:** Get module types

---

### 🏥 System Health

#### GET /api/system/status
**Authorization:** Public  
**Description:** API health check and database connection status

**Response:** `200 OK`
```json
{
  "status": "Healthy",
  "timestamp": "2026-02-03T10:00:00Z",
  "database": "Connected",
  "version": "2.0.0"
}
```

---

## Request/Response Formats

### Content Types

**Request:**
```http
Content-Type: application/json
```

**Response:**
```http
Content-Type: application/json; charset=utf-8
```

### Date Formats

All dates in ISO 8601 format with UTC timezone:
```
2026-02-03T10:00:00Z
```

### GUID Format

All GUIDs as strings with hyphens (lowercase):
```
"550e8400-e29b-41d4-a716-446655440000"
```

### Pagination

Standard pagination parameters:
```
?page=1&pageSize=50
```

Response format:
```json
{
  "data": [...],
  "total_count": 250,
  "page": 1,
  "page_size": 50,
  "total_pages": 5
}
```

---

## Error Codes

### HTTP Status Codes

| Code | Meaning | Description |
|------|---------|-------------|
| 200 | OK | Request succeeded |
| 201 | Created | Resource created successfully |
| 202 | Accepted | Request accepted (async processing) |
| 204 | No Content | Success with no response body |
| 400 | Bad Request | Invalid request data |
| 401 | Unauthorized | Missing or invalid JWT token |
| 403 | Forbidden | Valid token but insufficient permissions |
| 404 | Not Found | Resource doesn't exist |
| 409 | Conflict | Resource conflict (duplicate name, etc.) |
| 429 | Too Many Requests | Rate limit exceeded |
| 500 | Internal Server Error | Server-side error |
| 503 | Service Unavailable | Database connection failed |

### Error Response Format

```json
{
  "error": "Error message here",
  "details": "Additional context if available",
  "status_code": 400
}
```

### Common Error Messages

**Authentication Errors:**
```json
{
  "error": "Imperial Treasury: Authentication required",
  "status_code": 401
}
```

**Authorization Errors:**
```json
{
  "error": "Imperial Command: Access denied. Admin privileges required.",
  "status_code": 403
}
```

**Validation Errors:**
```json
{
  "error": "Validation failed",
  "errors": {
    "username": ["Username must be between 3 and 50 characters"],
    "email": ["Invalid email format"]
  },
  "status_code": 400
}
```

**Insufficient Funds:**
```json
{
  "error": "Imperial Treasury: Insufficient Funds",
  "current_balance": 100000,
  "required_amount": 500000,
  "deficit": 400000,
  "status_code": 400
}
```

---

## Rate Limiting

### Limits by Endpoint Category

| Category | Limit | Window |
|----------|-------|--------|
| Authentication | 10 requests | per minute |
| Universe Search | 60 requests | per minute |
| Shop Operations | 30 requests | per minute |
| General API | 1000 requests | per hour |

### Rate Limit Headers

```http
X-RateLimit-Limit: 60
X-RateLimit-Remaining: 45
X-RateLimit-Reset: 1738540920
```

### Rate Limit Exceeded Response

```json
{
  "error": "Rate limit exceeded",
  "retry_after": 45,
  "status_code": 429
}
```

---

## WebSocket API (Future)

### Planned Real-Time Endpoints

```
ws://api.echoes.com/ws/character/{characterId}
  - Real-time wallet updates
  - Skill training completion
  - Market notifications

ws://api.echoes.com/ws/system/{systemId}
  - Player movement updates
  - Combat events
  - Anomaly spawns
```

---

## API Versioning

### Current Version: 2.0

**URL Format:**
```
https://api.echoes.com/api/v2/endpoint
```

**Backward Compatibility:**
- v1 endpoints deprecated but still functional
- v2 adds new fields, doesn't break existing
- Major version bump (v3) indicates breaking changes

---

## Best Practices

### 1. Always Handle Errors
```csharp
try
{
    var response = await http.GetFromJsonAsync<CharacterDto>("/api/character/me");
}
catch (HttpRequestException ex)
{
    // Handle network errors
}
catch (JsonException ex)
{
    // Handle deserialization errors
}
```

### 2. Use Exponential Backoff for Retries
```csharp
int delay = 100;
for (int i = 0; i < 3; i++)
{
    try
    {
        return await CallAPI();
    }
    catch
    {
        await Task.Delay(delay);
        delay *= 2;  // 100ms, 200ms, 400ms
    }
}
```

### 3. Cache Static Data
```csharp
// Cache universe data (doesn't change often)
var systems = await CacheService.GetOrFetchAsync(
    "universe:systems",
    () => http.GetFromJsonAsync<SystemDto[]>("/api/universe/systems"),
    TimeSpan.FromHours(1)
);
```

### 4. Use Pagination for Large Datasets
```csharp
int page = 1;
while (true)
{
    var response = await http.GetFromJsonAsync<PagedResponse>(
        $"/api/universe/systems?page={page}&pageSize=100"
    );
    
    ProcessSystems(response.Data);
    
    if (page >= response.TotalPages) break;
    page++;
}
```

---

## Conclusion

The Echoes of Imperial API provides:

✅ **90+ endpoints** covering all game systems  
✅ **JWT authentication** with role-based access control  
✅ **RESTful design** with consistent patterns  
✅ **Comprehensive error handling** with Imperial-themed messages  
✅ **Rate limiting** to prevent abuse  
✅ **Pagination** for large datasets  
✅ **Caching** for performance optimization

**Related Documentation:**
- [ARCHITECTURE.md](ARCHITECTURE.md) - System architecture overview
- [DATABASE_SCHEMA.md](DATABASE_SCHEMA.md) - Database structure
- [UE5_INTEGRATION.md](UE5_INTEGRATION.md) - Game server integration
