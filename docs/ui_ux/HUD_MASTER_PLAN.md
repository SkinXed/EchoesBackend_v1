# HUD Master Plan - EVE-Like Interface

## Overview

This document outlines the master plan for implementing an EVE Online-inspired HUD system for the Echoes MMO.

## Layout Structure

### Top Bar
- Character name and portrait
- Wallet balance
- Location information
- Server status

### Center HUD
- Target information
- Speed indicator
- Navigation
- Combat interface

### Bottom Bar
- Ship modules and slots (High/Mid/Low)
- Capacitor display
- Shield/Armor/Hull status

### Side Panels

#### Left Panel
- Overview/scanner
- Fleet information
- Selected item window

#### Right Panel
- Inventory
- Ship fitting
- Chat channels

## Technical Architecture

### Components
- **HUD Manager**: Central controller for all HUD elements
- **Module Slots**: Dynamic UI for fitted ship modules
- **Status Display**: Real-time ship status (shields, armor, hull, capacitor)
- **Target Display**: Information about locked targets
- **Overview Panel**: List of nearby entities

### Integration Points
- Backend API for real-time data
- Ship stats subsystem
- Inventory system
- Combat system
- Navigation system

## Implementation Phases

### Phase 1: Core HUD
- [ ] Basic layout structure
- [ ] Ship status display
- [ ] Module slot UI

### Phase 2: Combat HUD
- [ ] Target locking system
- [ ] Module activation UI
- [ ] Damage indicators

### Phase 3: Navigation
- [ ] Destination display
- [ ] Warp UI
- [ ] Scanner/Overview

### Phase 4: Information Panels
- [ ] Inventory integration
- [ ] Ship fitting UI
- [ ] Character information

## Design Principles

1. **Clarity**: Information must be immediately readable
2. **Efficiency**: Minimize clicks to perform actions
3. **Scalability**: Support different screen resolutions
4. **Immersion**: Maintain sci-fi aesthetic without sacrificing usability

## Map Transitions

### Overview

The map system provides EVE-style universe and system navigation without moving the player's ship. It uses a separate visual layer with Scene Capture 2D to render map content.

### Opening the Map

**Hotkey**: `M` key

**Behavior:**
1. Fullscreen map widget opens overtop of game view
2. UI fades to black (0.2s transition)
3. Map camera activates in hidden miniature universe space
4. Scene Capture 2D renders map to texture
5. Map display fades in showing Universe Map (0.3s)

**Map Widget Elements:**
- Map render target (fullscreen image from Scene Capture)
- Search bar (find systems by name)
- Security filter slider (show only certain security zones)
- Current location indicator
- Destination marker (if set)
- Close button (X) or ESC to exit

### Universe Map (Galactic View)

**Display:**
- All star systems rendered as 3D point cloud
- Color-coded by security status:
  - **Green** (1.0): High-sec (safest)
  - **Yellow** (0.5): Border high/low-sec
  - **Orange** (0.2): Low-sec (dangerous)
  - **Red** (0.0): Null-sec (lawless)
  - **Purple** (-1.0): Wormhole space

**Controls:**
- **Pan**: Middle mouse drag
- **Zoom**: Mouse wheel
- **Rotate**: Right mouse drag
- **Search**: Type system name, highlights matching systems
- **Click System**: Show system info tooltip
- **Double-click System**: Zoom to system, transition to System Map

### Transition: Galaxy → System

**Trigger**: Double-click on a system point in Universe Map

**Animation Sequence (1.5s total):**
1. Camera begins zooming toward selected system (0.0s)
2. Galaxy cloud starts fading out (0.3s, duration 0.5s)
3. System objects spawn at scaled positions (0.6s, instant)
4. System view fades in (0.8s, duration 0.5s)
5. Camera settles at system center (1.5s)

**Visual Effect:**
- Smooth ease-in-out camera movement
- Galaxy fades to black then system fades in
- Gives impression of "entering" the system
- No loading screens or hitches

### System Map (Detail View)

**Display:**
- Hierarchical object layout:
  - **Star** at center (glowing sphere)
  - **Planets** in orbital paths (logarithmically scaled)
  - **Moons** orbiting planets
  - **Stations** at orbital positions (with service icons)
  - **Stargates** at system edges (connections to other systems)
  - **Asteroid Belts** as orbital rings

**Controls:**
- **Pan**: Middle mouse drag
- **Zoom**: Mouse wheel to focus on objects
- **Click Object**: Select and show info panel
- **Double-click Station**: Set as warp destination
- **ESC or M**: Return to Universe Map

**Logarithmic Scaling:**
Real astronomical distances compressed for usability:
- 1 AU (150M km) → ~4,000 km (viewable)
- 20 AU (3B km) → ~7,000 km (viewable)
- Maintains relative positions and hierarchy

### Transition: System → Galaxy

**Trigger**: Press ESC, M key, or "Back to Galaxy" button

**Animation Sequence (1.0s total):**
1. System objects fade out (0.0s, duration 0.3s)
2. Camera zooms out from system (0.2s)
3. Galaxy cloud fades in (0.5s, duration 0.5s)
4. Camera reaches galaxy overview position (1.0s)

### Closing the Map

**Trigger**: Press M, ESC, or click Close (X) button

**Behavior:**
1. Map widget fades out (0.2s)
2. Scene Capture 2D deactivates
3. Game view fades back in (0.3s)
4. Player resumes normal gameplay (ship never moved)

### Setting Warp Destination

**From System Map:**
1. Double-click on Station or Stargate
2. System sets destination in Navigation Subsystem
3. Visual indicator shows selected destination (pulsing highlight)
4. Destination remains set when map closes
5. Player can initiate warp in normal gameplay

**From Universe Map:**
1. Right-click system → "Set Destination"
2. Route calculation shows jump path (if multi-jump)
3. First stargate in route becomes destination
4. Autopilot can follow multi-jump routes

### Technical Implementation: "Switching Backgrounds"

**Problem to Solve:**
- Opening map shouldn't move player's ship
- No physics interaction with map objects
- No level loading or network sync
- Instant access, no performance hit

**Solution: Hidden Miniature Universe**

The map exists in a separate space, far from the game world:

```
Game World (Y = 0)
  ↓ Player's ship at (1000, 0, 500)
  ↓ Gameplay happens here
  
─────────────────────────────────── Ground Plane (Y = 0)
  
  (Large vertical separation)
  
Hidden Map Space (Y = -100,000)
  ↓ Miniature universe at (0, -100000, 0)
  ↓ Map camera looking at miniature
  ↓ Never interacts with game world
```

**Scene Capture 2D Setup:**

```cpp
// Map camera actor positioned in hidden space
AEchoesMapCameraActor* MapCamera;
MapCamera->SetActorLocation(FVector(0, -100000, 50000)); // Above miniature

// Scene Capture Component
USceneCaptureComponent2D* Capture = MapCamera->CaptureComponent;
Capture->ProjectionType = ECameraProjectionMode::Orthographic;
Capture->OrthoWidth = 100000.0f; // View entire galaxy
Capture->CaptureSource = ESceneCaptureSource::SCS_SceneColorHDR;

// Render to texture
UTextureRenderTarget2D* RenderTarget;
RenderTarget->InitAutoFormat(1920, 1080);
Capture->TextureTarget = RenderTarget;

// Map widget displays the render target
MapWidget->MapImage->SetBrushFromTexture(RenderTarget);
```

**Benefits:**
- ✅ Zero impact on game physics
- ✅ Player ship never moves
- ✅ No level streaming overhead
- ✅ Instant map access
- ✅ Clean separation of concerns
- ✅ Works perfectly in multiplayer (client-side UI only)

**Alternative: Level Instance**
- Create separate sublevel for map
- Stream in/out when map opens/closes
- Pros: Complete isolation, separate lighting
- Cons: Streaming overhead, more complex setup

### Integration Points

**With Navigation System:**
- Map reads current position from Navigation Subsystem
- Map writes destination to Navigation Subsystem
- Route visualization from Navigation pathfinding

**With Universe Data:**
- Map Data Provider fetches system/object data
- Filters to essential fields (Name, Type, Location, Security)
- Caches for performance (10,000+ systems)

**With HUD:**
- Map is a fullscreen widget overlay
- Shares UI layer with other HUD elements
- Can be opened from Top Bar location display

**With Input System:**
- M key toggles map (bindable)
- Mouse controls for pan/zoom/rotate
- ESC closes map
- All input captured while map is open

### Performance Targets

**Frame Rate:**
- Target: 60 FPS with map open
- Universe Map: 10,000+ systems using ISM (single draw call)
- System Map: 50+ objects per system
- Smooth 60 FPS transitions

**Memory:**
- Universe data: ~100KB cached
- System data: ~10KB per system (lazy loaded)
- Render target: 8MB (1920x1080)
- ISM meshes: <1MB total
- **Total**: ~10-15MB overhead

**Responsiveness:**
- Map opens: <100ms
- Search results: <16ms
- Click response: <16ms
- Transitions: 1-1.5s (cinematic, not loading)

---

## References

- EVE Online HUD design
- EVE Online Star Map and System Map
- Elite Dangerous interface
- Elite Dangerous Galaxy Map
- Star Citizen UI/UX
- Star Citizen Star Map

---

**Status**: Planning Phase  
**Last Updated**: 2026-01-31  
**Owner**: UI/UX Team
