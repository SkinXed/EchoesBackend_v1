# Echoes MMO - Development Roadmap

> **Strategic development plan for EVE-inspired MMO backend**  
> Four milestone progression from connectivity to industrial gameplay

**Version:** 1.0  
**Last Updated:** 2026-01-31  
**Status:** Active Development

---

## Overview

This roadmap breaks down the Echoes MMO development into **4 major milestones**, each with clear objectives and success criteria. The project follows an incremental delivery model, with each milestone building upon the previous foundations.

### Current Status

```
Milestone 1: █████████████████████░ 95% Complete
Milestone 2: ███████░░░░░░░░░░░░░░ 35% Complete
Milestone 3: ███░░░░░░░░░░░░░░░░░░ 15% Complete
Milestone 4: ░░░░░░░░░░░░░░░░░░░░░  0% Complete
```

**Overall Progress:** 36% (Weighted by milestone complexity)

---

## Milestone 1: Core Connectivity (95% Complete) ✅

> **Goal:** Establish foundational infrastructure for client-server communication and player identity

### Objectives

1. **Authentication System**
   - User registration and login
   - JWT token generation and validation
   - Session management
   - Password hashing (bcrypt)

2. **Character System**
   - Character creation with race/bloodline
   - Character selection
   - Multiple characters per account
   - Character persistence

3. **Item Registry**
   - AssetTypes table with all item definitions
   - Ship types, modules, resources
   - Item properties (mass, volume, effects)
   - Stackability and singleton logic

4. **Player Spawn System**
   - Spawn character at designated station
   - Load character data from backend
   - Initialize player controller and pawn
   - Camera setup and input mapping

5. **Backend Infrastructure**
   - ASP.NET Core 8 API
   - PostgreSQL database with migrations
   - Entity Framework Core ORM
   - RESTful API endpoints
   - Health checks and monitoring

### Success Criteria

- [x] Player can register, login, and receive JWT token
- [x] Player can create and select characters
- [x] Player spawns in-game at correct station/location
- [x] Backend API responds to authenticated requests
- [x] Database stores all player and character data
- [x] Item registry populated with base items
- [ ] **REMAINING:** Performance testing under load (100+ concurrent users)

### Technical Achievements

```
✅ JWT-based authentication
✅ Entity Framework migrations
✅ UE5 subsystems (Auth, Identity, Inventory)
✅ Mirror architecture (C# ↔ C++)
✅ "Postgres is Truth" principle established
✅ 5,000+ lines of backend code
✅ 3,500+ lines of UE5 code
```

### Known Issues

- Load testing not completed
- Need connection pooling optimization
- Missing rate limiting on API endpoints

---

## Milestone 2: Visual & Tactical HUD (35% Complete) 🚧

> **Goal:** Implement EVE-style HUD for ship status, scanning, and tactical awareness

### Objectives

#### 2.1 Ship Status HUD ✅

- [x] Shield/Armor/Hull bars with percentages
- [x] Capacitor display
- [x] Speed indicator
- [x] Ship name and type display
- [x] Module slot display (High/Mid/Low/Rig)

#### 2.2 Overview Panel (40% Complete)

- [x] List view of nearby entities
- [x] Sort by distance, name, type
- [x] Filter by category (Ships, Stations, Asteroids)
- [ ] **IN PROGRESS:** Column customization
- [ ] **PLANNED:** Custom overview tabs
- [ ] **PLANNED:** Bracket colors on 3D view

#### 2.3 3D Tactical Radar (0% Complete)

- [ ] **PLANNED:** 3D sphere representation of space
- [ ] **PLANNED:** Entity markers with distance scaling
- [ ] **PLANNED:** Friend/Foe color coding
- [ ] **PLANNED:** Click-to-target from radar
- [ ] **PLANNED:** Range rings (5km, 10km, 50km)
- [ ] **PLANNED:** Rotation with camera or fixed North

#### 2.4 Target Management

- [x] Single target lock
- [x] Target info panel (name, distance, ship type)
- [ ] **IN PROGRESS:** Multiple target support (up to 7)
- [ ] **PLANNED:** Target switching hotkeys
- [ ] **PLANNED:** Auto-target nearest hostile

#### 2.5 Window System ✅

- [x] Draggable windows
- [x] Resizable windows
- [x] Z-order (focus) management
- [x] Window snapping to edges/windows
- [x] Close/minimize buttons

### Success Criteria

- [x] Player can see ship status at a glance
- [x] Player can view Overview list with entities
- [ ] **TARGET:** Player can use 3D radar for spatial awareness
- [ ] **TARGET:** Player can lock multiple targets
- [ ] **TARGET:** All HUD elements responsive and performant (60 FPS)

### Implementation Plan

#### Phase 2A: 3D Tactical Radar (4 weeks)
**Week 1-2:** Core radar widget
- Create UEchoesTacticalRadarWidget
- Implement 3D sphere mesh or material
- Entity marker positioning math
- Distance scaling algorithm

**Week 3:** Entity integration
- Query nearby entities from subsystem
- Filter by range (configurable max range)
- Update marker positions in real-time
- Performance optimization (LOD, culling)

**Week 4:** Polish and features
- Color coding (friendly/neutral/hostile)
- Click-to-target interaction
- Range rings
- Settings menu (range, rotation mode)

#### Phase 2B: Overview Improvements (2 weeks)
**Week 1:** Column customization
- Save/load column configurations
- Drag-and-drop column reordering
- Add/remove columns

**Week 2:** Bracket integration
- Draw 3D brackets for Overview entities
- Synchronize selection between Overview and 3D
- Bracket color inheritance from Overview

#### Phase 2C: Multi-Target System (2 weeks)
**Week 1:** Target slot management
- Multiple target array (max 7)
- Target priority system
- Hotkey binding (F1-F7)

**Week 2:** UI and feedback
- Target list display
- Active target highlighting
- Audio/visual feedback on target lock/lost

### Dependencies

- Entity subsystem for querying nearby objects
- Network replication for multiplayer awareness
- Materials for radar visualization

---

## Milestone 3: Fitting & Ship Attributes (15% Complete) 📋

> **Goal:** Dynamic ship stats based on fitted modules with full module effects

### Objectives

#### 3.1 Module Effects System (20% Complete)

- [x] Mass calculation (Base + Module mass)
- [ ] **IN PROGRESS:** Thrust bonuses from propulsion modules
- [ ] **PLANNED:** Agility modifiers from rigs/nanofibers
- [ ] **PLANNED:** Shield/Armor/Hull bonuses
- [ ] **PLANNED:** Capacitor capacity and regen
- [ ] **PLANNED:** CPU and Power Grid requirements
- [ ] **PLANNED:** Stacking penalties for similar modules

#### 3.2 Ship Fitting Interface (0% Complete)

- [ ] **PLANNED:** Visual fitting window (EVE-style)
- [ ] **PLANNED:** Drag-and-drop module installation
- [ ] **PLANNED:** Real-time stat preview
- [ ] **PLANNED:** Fitting validation (CPU/PG limits)
- [ ] **PLANNED:** Save/load fittings
- [ ] **PLANNED:** Fitting templates library

#### 3.3 Module Activation (0% Complete)

- [ ] **PLANNED:** Module online/offline state
- [ ] **PLANNED:** Activation cooldowns
- [ ] **PLANNED:** Capacitor consumption
- [ ] **PLANNED:** Module effects on target/self
- [ ] **PLANNED:** Visual effects for active modules
- [ ] **PLANNED:** Overheating mechanics

#### 3.4 Advanced Stats (10% Complete)

- [x] Basic physics stats (mass, thrust, velocity)
- [ ] **PLANNED:** Signature radius (for targeting)
- [ ] **PLANNED:** Scan resolution
- [ ] **PLANNED:** Warp acceleration
- [ ] **PLANNED:** Shield/Armor resistances
- [ ] **PLANNED:** Damage output calculations

### Success Criteria

- [ ] **TARGET:** Player can fit modules with CPU/PG constraints
- [ ] **TARGET:** Modules modify ship stats in real-time
- [ ] **TARGET:** Player can activate modules in combat
- [ ] **TARGET:** Ship performance changes based on fitting
- [ ] **TARGET:** Capacitor drains and regenerates
- [ ] **TARGET:** Overheating provides temporary bonuses

### Implementation Plan

#### Phase 3A: Module Effects Backend (3 weeks)
**Week 1:** Effect system architecture
- Define effect types (bonus, multiplier, absolute)
- Effect stacking logic
- SQL schema for module effects

**Week 2:** Stat calculation service
- Aggregate module bonuses
- Apply stacking penalties
- Calculate final ship stats
- Unit tests for all formulas

**Week 3:** API endpoints
- GET /api/ship/{id}/fitting (with calculated stats)
- POST /api/ship/{id}/modules (install module)
- DELETE /api/ship/{id}/modules/{moduleId} (remove)
- PUT /api/ship/{id}/modules/{moduleId}/state (online/offline)

#### Phase 3B: Fitting UI (4 weeks)
**Week 1-2:** Core fitting window
- Layout design (EVE-inspired)
- Ship visualization
- Module slot grid (High/Mid/Low/Rig)
- Drag-and-drop framework

**Week 3:** Real-time stat display
- Stat comparison (before/after)
- CPU/PG usage bars
- Capacitor simulation
- EHP (Effective Hit Points) calculation

**Week 4:** Fitting management
- Save fitting to database
- Load fitting
- Share fitting (export/import)
- Fitting browser

#### Phase 3C: Module Activation (3 weeks)
**Week 1:** Activation system
- Module state machine (Offline → Online → Active → Cooldown)
- Capacitor consumption
- Server-authoritative activation
- Replication

**Week 2:** Module effects
- Shield booster (heal shields)
- Armor repairer (heal armor)
- Weapons (damage)
- Propulsion modules (speed/agility boost)

**Week 3:** Overheating
- Heat damage accumulation
- Nanite paste repairs
- Visual heat indicators
- Balancing

### Dependencies

- Completed inventory system
- Module effects database
- Combat system (for weapon modules)

---

## Milestone 4: Industrial Loop (0% Complete) 🏭

> **Goal:** Economic gameplay through mining, refining, manufacturing, and trade

### Objectives

#### 4.1 Mining System

- [ ] **PLANNED:** Asteroid spawning in belts
- [ ] **PLANNED:** Mining laser activation
- [ ] **PLANNED:** Ore extraction mechanics
- [ ] **PLANNED:** Cargo hold fills with ore
- [ ] **PLANNED:** Mining yield calculations
- [ ] **PLANNED:** Different ore types (Veldspar, Scordite, etc.)
- [ ] **PLANNED:** Asteroid depletion and respawn

#### 4.2 Refining System

- [ ] **PLANNED:** Station refining services
- [ ] **PLANNED:** Ore → Minerals conversion
- [ ] **PLANNED:** Refining efficiency (skills, station type)
- [ ] **PLANNED:** Batch refining
- [ ] **PLANNED:** Reprocessing fees

#### 4.3 Manufacturing

- [ ] **PLANNED:** Blueprint system
- [ ] **PLANNED:** Material requirements
- [ ] **PLANNED:** Manufacturing jobs
- [ ] **PLANNED:** Job completion time
- [ ] **PLANNED:** Production queues
- [ ] **PLANNED:** T1/T2 item production

#### 4.4 Market System

- [ ] **PLANNED:** Buy/sell orders
- [ ] **PLANNED:** Market browser interface
- [ ] **PLANNED:** Price history charts
- [ ] **PLANNED:** Order fulfillment
- [ ] **PLANNED:** Regional markets
- [ ] **PLANNED:** Market transactions

#### 4.5 Hauling & Logistics

- [ ] **PLANNED:** Cargo ships with large holds
- [ ] **PLANNED:** Item contracts
- [ ] **PLANNED:** Courier missions
- [ ] **PLANNED:** Trade routes

### Success Criteria

- [ ] **TARGET:** Player can mine asteroids for ore
- [ ] **TARGET:** Player can refine ore into minerals
- [ ] **TARGET:** Player can manufacture items from blueprints
- [ ] **TARGET:** Player can buy/sell on market
- [ ] **TARGET:** Economic loop is self-sustaining

### Implementation Plan

#### Phase 4A: Mining (6 weeks)
**Week 1-2:** Asteroid system
- Procedural asteroid belt generation
- Asteroid actor with health and ore type
- Collision and physics

**Week 3-4:** Mining mechanics
- Mining laser module
- Beam visual effects
- Ore extraction algorithm
- Cargo hold integration

**Week 5:** Ore types and yields
- 10+ ore types
- Rarity and distribution
- Mining yield formulas
- Mining efficiency bonuses

**Week 6:** Polish
- Audio feedback
- Particle effects
- Asteroid respawn system
- Performance optimization

#### Phase 4B: Refining (3 weeks)
**Week 1:** Refining service
- Station refining interface
- Ore selection
- Refining efficiency calculation

**Week 2:** Backend
- Refining API endpoints
- Ore → Mineral conversion tables
- Transaction processing

**Week 3:** UI Polish
- Refining calculator
- Batch processing
- Result preview

#### Phase 4C: Market (8 weeks)
**Week 1-2:** Database schema
- Orders table
- Transactions table
- Price history table

**Week 3-4:** Backend API
- Create/cancel orders
- Order matching engine
- Transaction processing

**Week 5-6:** Market UI
- Market browser
- Item search and filters
- Order placement
- Price charts

**Week 7-8:** Polish and testing
- Regional markets
- Market manipulation prevention
- Performance optimization

#### Phase 4D: Manufacturing (6 weeks)
**Week 1-2:** Blueprint system
- Blueprint database
- Material requirements
- Production time calculations

**Week 3-4:** Manufacturing jobs
- Job submission
- Job queue management
- Completion logic

**Week 5-6:** UI
- Manufacturing interface
- Blueprint browser
- Job tracking

### Dependencies

- Completed inventory and fitting systems
- Station services framework
- Economy balancing data

---

## Beyond Milestone 4: Future Roadmap

### Phase 5: Combat & PvP
- Directional shields (4-vector damage)
- Weapon types and damage application
- Electronic warfare
- Fleet mechanics
- Kill mails and bounties

### Phase 6: Corporations & Alliances
- Corp creation and management
- Shared hangars
- Corp roles and permissions
- Alliance diplomacy
- Sovereignty mechanics

### Phase 7: Exploration & PvE
- Cosmic anomalies
- Exploration sites
- NPC enemies and AI
- Mission system
- Loot drops

### Phase 8: Advanced Economy
- Planetary interaction
- Moon mining
- Reactions and T2 manufacturing
- Market speculation tools
- Economic statistics

---

## Resource Allocation

### Current Team Focus

| Role | Current Assignment | Next Assignment |
|------|-------------------|-----------------|
| Backend Developer | Milestone 2 (Overview API) | Milestone 3 (Module effects) |
| UE5 Developer | Milestone 2 (3D Radar) | Milestone 2 (Multi-target) |
| UI/UX Designer | Milestone 2 (HUD polish) | Milestone 3 (Fitting window) |
| Database Engineer | Milestone 1 (Optimization) | Milestone 3 (Effects schema) |

### Development Velocity

**Current Sprint Velocity:** ~40 story points / 2-week sprint

**Estimated Completion:**
- **Milestone 2:** 6 weeks (3 sprints)
- **Milestone 3:** 10 weeks (5 sprints)
- **Milestone 4:** 24 weeks (12 sprints)

**Total Time to Milestone 4 Completion:** ~10 months

---

## Risk Assessment

### High-Priority Risks

1. **Performance Bottlenecks**
   - **Risk:** Database queries slow under load
   - **Mitigation:** Connection pooling, caching, query optimization
   - **Status:** Monitoring

2. **Network Replication**
   - **Risk:** High bandwidth with many players
   - **Mitigation:** Spatial replication, relevancy filtering
   - **Status:** To be addressed in Milestone 2

3. **Scope Creep**
   - **Risk:** Feature requests expanding milestones
   - **Mitigation:** Strict milestone definitions, backlog discipline
   - **Status:** Managed

4. **Balancing Complexity**
   - **Risk:** Game balance requires extensive testing
   - **Mitigation:** Configurable parameters, analytics, community feedback
   - **Status:** Future concern (Milestone 3+)

---

## Metrics & KPIs

### Technical Metrics
- **API Response Time:** < 100ms (P95)
- **Database Query Time:** < 50ms (P95)
- **Client FPS:** > 60 FPS (with 50+ entities visible)
- **Network Latency:** < 150ms (server to client)

### User Engagement (Post-Launch)
- **Daily Active Users (DAU)**
- **Average Session Length**
- **Feature Adoption Rate**
- **Bug Report Frequency**

---

## Version History

| Version | Date | Changes |
|---------|------|---------|
| 1.0 | 2026-01-31 | Initial roadmap created |

---

## Conclusion

This roadmap provides a clear path from core infrastructure to a fully-featured EVE-inspired MMO. Each milestone builds upon the last, creating a stable foundation for increasingly complex features.

**Key Success Factors:**
1. Maintain "Postgres is Truth" architecture
2. Incremental delivery with working software at each milestone
3. Focus on one milestone at a time
4. Regular performance testing
5. Community feedback integration

---

**Next Review:** 2026-02-28  
**Document Owner:** Technical Project Manager  
**Status:** Living Document (Updated Monthly)
