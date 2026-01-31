# Map Visualization System - Universe & System Maps

> **Non-Physics Map Rendering for EVE-Style Navigation**  
> UI-layer visualization using Subsystems data with Instanced Static Meshes

---

## Core Principle

**Maps are UI layers**, not physical game spaces. The map visualization system uses data from Subsystems without involving the physics engine, providing a clean separation between gameplay and navigation UI.

```
Subsystems (Data Source) → Map Data Provider → UI Visualization Layer
                                                      ↓
                                              Scene Capture 2D
                                              Instanced Static Meshes
                                              Miniature World Space
```

---

## Architecture Overview

### Design Philosophy

1. **No Physics Interaction**: Maps exist purely in UI space
2. **Data-Driven**: All visualization sourced from backend/subsystems
3. **Performance First**: Use ISM (Instanced Static Meshes) for thousands of objects
4. **Scalable**: Logarithmic distance scaling for usable navigation
5. **Immersive**: Cinematic transitions between map modes

### Map Modes

```
┌─────────────────────────────────────────────────────────────┐
│                     Universe Map                            │
│  - Galactic Cloud: All star systems as points             │
│  - Color coded by security status                          │
│  - ISM rendering (10,000+ systems)                         │
│  - Pan/zoom/rotate controls                                │
└─────────────────────────────────────────────────────────────┘
                        │
                        │ Double-click system
                        │ Zoom animation
                        ↓
┌─────────────────────────────────────────────────────────────┐
│                     System Map                              │
│  - Hierarchical: Star → Planets → Stations                │
│  - Logarithmic distance scaling                            │
│  - Orbital paths visualization                             │
│  - Click to target/warp                                    │
└─────────────────────────────────────────────────────────────┘
```

---

## Universe Map

### Visual Design

**Galactic Cloud Renderer**: Displays all star systems in the universe as a 3D point cloud.

**Key Features:**
- Each star system = 1 instanced mesh point
- Color coding by security status (0.0 to 1.0)
- Real-time filtering (security, region, connectivity)
- Search and focus functionality
- Jump route visualization

### Color Coding by Security Status

```cpp
// Security Status → Color mapping
FLinearColor GetSecurityColor(float SecurityStatus)
{
    if (SecurityStatus >= 0.5f)
    {
        // High-sec: Green to Yellow (0.5 to 1.0)
        float t = (SecurityStatus - 0.5f) / 0.5f;
        return FMath::Lerp(FLinearColor::Yellow, FLinearColor::Green, t);
    }
    else if (SecurityStatus > 0.0f)
    {
        // Low-sec: Orange to Yellow (0.0 to 0.5)
        float t = SecurityStatus / 0.5f;
        return FMath::Lerp(FLinearColor(1.0f, 0.3f, 0.0f), FLinearColor::Yellow, t);
    }
    else
    {
        // Null-sec: Red
        return FLinearColor::Red;
    }
}
```

**Security Zones:**
- **1.0 - 0.5**: High Security (Green → Yellow)
- **0.4 - 0.1**: Low Security (Orange)
- **0.0**: Null Security (Red)
- **-1.0**: Wormhole Space (Purple)

### Instanced Static Mesh Implementation

```cpp
UCLASS()
class AEchoesGalacticCloudRenderer : public AActor
{
    GENERATED_BODY()
    
public:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    UInstancedStaticMeshComponent* SystemPointsISM;
    
    // Data source
    UPROPERTY()
    TArray<FSystemMapData> SystemData;
    
    // Spawn all system points as instances
    void RenderGalacticCloud();
    
    // Update colors based on filters
    void UpdateSystemColors(TFunction<bool(const FSystemMapData&)> FilterFunc);
    
    // Handle click on system point
    void OnSystemClicked(int32 InstanceIndex);
};
```

**Performance:**
- 10,000+ systems rendered with single draw call
- GPU instancing handles all transformations
- Minimal CPU overhead for camera updates

### Universe Map Controls

| Action | Input | Behavior |
|--------|-------|----------|
| **Pan** | Middle Mouse Drag | Move camera across galaxy |
| **Zoom** | Mouse Wheel | Zoom in/out on galaxy |
| **Rotate** | Right Mouse Drag | Rotate view around center |
| **Focus** | Double-click system | Zoom to system, transition to System Map |
| **Search** | Type system name | Highlight and center on system |
| **Filter** | Security slider | Show only systems matching criteria |

---

## System Map

### Visual Design

**System Inspector**: Displays detailed view of a single star system with hierarchical object placement.

**Hierarchy:**
```
Star (Center)
  ↓
Planets (Orbits)
  ↓
Moons (Sub-orbits)
  ↓
Stations (Orbital positions)
  ↓
Stargates (System edges)
  ↓
Asteroid Belts (Orbital rings)
```

### Logarithmic Distance Scaling

**Problem:** Real astronomical distances make navigation impractical.

**Solution:** Logarithmic scaling compresses distances while maintaining relative positions.

```cpp
FVector CalculateScaledPosition(FVector RealPosition, float ScaleFactor)
{
    float RealDistance = RealPosition.Size();
    
    if (RealDistance < 1000.0f) // Don't scale very close objects
    {
        return RealPosition;
    }
    
    // Logarithmic scaling: log(1 + distance)
    float ScaledDistance = FMath::LogX(10.0f, 1.0f + RealDistance / 1000.0f) * ScaleFactor;
    
    return RealPosition.GetSafeNormal() * ScaledDistance * 1000.0f;
}
```

**Example:**
```
Real Distance       Scaled Distance (ScaleFactor = 1000)
─────────────────────────────────────────────────────────
1 AU (150M km)   →  4,176 km (viewable)
5 AU (750M km)   →  5,869 km (viewable)
20 AU (3B km)    →  7,324 km (viewable)
```

### Hierarchical Object Placement

**Star (Center Point):**
- Always at origin (0, 0, 0)
- Glowing sphere mesh
- Emissive material

**Planets (Primary Orbits):**
- Circular orbits around star
- Scaled distance from star
- Orbital path line visualization
- Planet mesh with texture

**Stations (Orbital Positions):**
- Positioned in orbit around parent (planet or star)
- Station model mesh
- Docking radius indicator
- Services icons

**Stargates:**
- Positioned at system edges
- Connection lines to destination systems
- Active/inactive state visualization

### System Map Controls

| Action | Input | Behavior |
|--------|-------|----------|
| **Pan** | Middle Mouse Drag | Move camera within system |
| **Zoom** | Mouse Wheel | Zoom to objects |
| **Click Object** | Left Click | Select and show info panel |
| **Double-click Station** | Double-click | Set as warp destination |
| **Back to Galaxy** | ESC or M | Return to Universe Map |

---

## Map Data Provider

### Data Structure

```cpp
USTRUCT(BlueprintType)
struct FSystemMapData
{
    GENERATED_BODY()
    
    UPROPERTY(BlueprintReadOnly)
    FGuid SystemId;
    
    UPROPERTY(BlueprintReadOnly)
    FText SystemName;
    
    UPROPERTY(BlueprintReadOnly)
    FVector Position; // Galactic coordinates
    
    UPROPERTY(BlueprintReadOnly)
    float SecurityStatus; // 0.0 to 1.0
    
    UPROPERTY(BlueprintReadOnly)
    FGuid RegionId;
    
    UPROPERTY(BlueprintReadOnly)
    TArray<FGuid> ConnectedSystems; // Stargates
};

USTRUCT(BlueprintType)
struct FSystemObjectData
{
    GENERATED_BODY()
    
    UPROPERTY(BlueprintReadOnly)
    FGuid ObjectId;
    
    UPROPERTY(BlueprintReadOnly)
    FText ObjectName;
    
    UPROPERTY(BlueprintReadOnly)
    ESystemObjectType Type; // Star, Planet, Moon, Station, Stargate, Belt
    
    UPROPERTY(BlueprintReadOnly)
    FVector Location; // System-local coordinates
    
    UPROPERTY(BlueprintReadOnly)
    FGuid ParentId; // For hierarchical relationships
    
    UPROPERTY(BlueprintReadOnly)
    float OrbitRadius; // For planets/moons
};
```

### Data Provider Interface

```cpp
UCLASS()
class UEchoesMapDataProvider : public UGameInstanceSubsystem
{
    GENERATED_BODY()
    
public:
    // Get all systems for universe map
    UFUNCTION(BlueprintCallable)
    TArray<FSystemMapData> GetAllSystems();
    
    // Get filtered systems (e.g., by security, region)
    UFUNCTION(BlueprintCallable)
    TArray<FSystemMapData> GetFilteredSystems(float MinSecurity, float MaxSecurity);
    
    // Get all objects in a specific system
    UFUNCTION(BlueprintCallable)
    TArray<FSystemObjectData> GetSystemObjects(FGuid SystemId);
    
    // Find system by name
    UFUNCTION(BlueprintCallable)
    FSystemMapData FindSystemByName(const FString& SystemName);
    
    // Get jump route between systems
    UFUNCTION(BlueprintCallable)
    TArray<FGuid> CalculateRoute(FGuid FromSystemId, FGuid ToSystemId);
    
private:
    // Cached data from backend
    UPROPERTY()
    TArray<FSystemMapData> CachedSystems;
    
    UPROPERTY()
    TMap<FGuid, TArray<FSystemObjectData>> CachedSystemObjects;
    
    // Fetch from backend API
    void RefreshSystemData();
    void RefreshSystemObjectData(FGuid SystemId);
};
```

---

## Technical Implementation: "Switching Backgrounds"

### The Problem

Opening a map shouldn't:
- Move the player's ship
- Affect game physics
- Load a new level
- Cause network synchronization

### The Solution: Hidden Miniature Universe

**Approach:** Create a miniature representation of the universe in a hidden area of the game world, use Scene Capture 2D to render it to the map UI.

```
Game World (Y = 0)
  ↓ Player's ship at (X, Y, Z)
  
─────────────────────────────── Ground Plane

Hidden Map Space (Y = -100,000)
  ↓ Miniature universe at (X, Y-100000, Z)
  ↓ Map Camera looking at miniature
```

### Scene Capture 2D Setup

```cpp
UCLASS()
class AEchoesMapCameraActor : public AActor
{
    GENERATED_BODY()
    
public:
    AEchoesMapCameraActor();
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    USceneCaptureComponent2D* MapCaptureComponent;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    UTextureRenderTarget2D* MapRenderTarget;
    
    // Switch between Universe and System view
    UFUNCTION(BlueprintCallable)
    void SetViewMode(EMapViewMode Mode);
    
    // Smooth camera transition
    UFUNCTION(BlueprintCallable)
    void TransitionToSystem(FGuid SystemId, float Duration = 1.0f);
    
private:
    FVector UniverseViewPosition;
    FVector SystemViewPosition;
    
    // Animation state
    bool bIsAnimating;
    float AnimationTime;
    FVector StartPosition;
    FVector TargetPosition;
};
```

### Level Instance Approach (Alternative)

**Pros:**
- Complete isolation from main level
- Can unload when not in use
- Easier to manage separate lighting

**Cons:**
- Slightly more complex setup
- Level streaming overhead

```cpp
UCLASS()
class UEchoesMapLevelInstance : public ULevelStreamingDynamic
{
    GENERATED_BODY()
    
public:
    // Load map level instance
    static UEchoesMapLevelInstance* LoadMapLevel(UObject* WorldContextObject);
    
    // Show/hide map level
    void ShowMap(bool bShow);
    
private:
    UPROPERTY()
    AEchoesGalacticCloudRenderer* CloudRenderer;
    
    UPROPERTY()
    AEchoesSystemInspector* SystemInspector;
};
```

### UI Integration

```cpp
UCLASS()
class UEchoesMapWidget : public UUserWidget
{
    GENERATED_BODY()
    
public:
    // Render target image
    UPROPERTY(meta = (BindWidget))
    UImage* MapDisplay;
    
    // Set render target from Scene Capture
    void SetMapRenderTarget(UTextureRenderTarget2D* RenderTarget);
    
    // UI overlay elements
    UPROPERTY(meta = (BindWidget))
    UTextBlock* CurrentSystemName;
    
    UPROPERTY(meta = (BindWidget))
    UTextBlock* SecurityStatus;
    
    UPROPERTY(meta = (BindWidget))
    UButton* BackToGalaxyButton;
    
protected:
    virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, 
                                            const FPointerEvent& InMouseEvent) override;
    
    virtual FReply NativeOnMouseButtonDoubleClick(const FGeometry& InGeometry, 
                                                   const FPointerEvent& InMouseEvent) override;
};
```

---

## Performance Considerations

### Instanced Static Mesh Optimization

**Universe Map:**
- Single ISM component for all systems
- ~10,000 instances = 1 draw call
- GPU handles all transformations
- Dynamic color updates via custom data

**System Map:**
- Separate ISM per object type
  - Planets ISM (10-50 instances)
  - Stations ISM (10-100 instances)
  - Moons ISM (20-200 instances)
- Hierarchical culling by orbit radius

### Culling Strategy

```cpp
// Frustum culling for ISM instances
void UpdateVisibleInstances()
{
    FConvexVolume Frustum;
    GetCameraFrustum(Frustum);
    
    for (int32 i = 0; i < TotalInstances; ++i)
    {
        FVector InstanceLocation = GetInstanceLocation(i);
        bool bVisible = Frustum.IntersectPoint(InstanceLocation);
        
        SystemPointsISM->SetInstanceVisible(i, bVisible);
    }
}
```

### Memory Management

**Data Caching:**
- Universe data: ~100KB for 10,000 systems
- System data: ~10KB per system (loaded on-demand)
- Mesh instances: Minimal memory (GPU-side)

**Texture Budget:**
- Render target: 1920x1080 @ 32bpp = 8MB
- Instance meshes: Simple geometry (<1MB total)

---

## User Experience Flow

### Opening the Map

```
1. Player presses M key
2. UI fades to black (0.2s)
3. Map widget opens fullscreen
4. Scene Capture activates
5. Universe Map renders
6. Fade in map display (0.3s)
```

### Zooming to System

```
1. Player double-clicks system point
2. Camera animates toward system (1.0s easing)
3. Galaxy fades out (0.5s)
4. System objects spawn (0.2s delay)
5. System fades in (0.5s)
6. System Map fully visible
```

### Returning to Game

```
1. Player presses M or ESC
2. Map widget fades out (0.2s)
3. Scene Capture deactivates
4. Return to game view (0.3s)
5. Resume normal gameplay
```

---

## Integration with Game Systems

### Navigation System

**Setting Destination:**
```cpp
void OnMapObjectDoubleClicked(FGuid ObjectId, ESystemObjectType Type)
{
    if (Type == ESystemObjectType::Station || Type == ESystemObjectType::Stargate)
    {
        // Set as warp destination
        auto NavSubsystem = GetGameInstance()->GetSubsystem<UEchoesNavigationSubsystem>();
        NavSubsystem->SetDestination(ObjectId);
        
        // Close map and initiate warp
        CloseMap();
        InitiateWarp();
    }
}
```

### Autopilot Integration

**Multi-Jump Routes:**
```cpp
void SetAutopilotRoute(TArray<FGuid> SystemRoute)
{
    auto NavSubsystem = GetGameInstance()->GetSubsystem<UEchoesNavigationSubsystem>();
    NavSubsystem->SetAutopilotRoute(SystemRoute);
    
    // Visualize route on map
    DrawRouteOnMap(SystemRoute);
}
```

### Intel and Reconnaissance

**Recent Activity:**
- Show player kills in last hour
- Display NPC activity
- Mark systems with recent combat

**Player Bookmarks:**
- Save custom waypoints
- Name and categorize locations
- Share bookmarks with corporation

---

## Visual Polish

### Animations

**Zoom Transitions:**
```cpp
FVector EaseInOutCubic(FVector Start, FVector End, float t)
{
    float EasedT = t < 0.5f 
        ? 4.0f * t * t * t 
        : 1.0f - FMath::Pow(-2.0f * t + 2.0f, 3.0f) / 2.0f;
    
    return FMath::Lerp(Start, End, EasedT);
}
```

**Particle Effects:**
- Subtle stars/nebulae in background
- Glow on hovered systems
- Pulse animation on selected system
- Trail effect during transitions

### Audio

**Sound Design:**
- Ambient space drone
- Click sounds for selections
- Whoosh for zoom transitions
- Confirmation beep for destination set

---

## Future Enhancements

### Planned Features

1. **3D Holographic Mode**
   - Full 3D navigation in VR-style
   - Hand gestures for manipulation
   - Immersive "bridge" experience

2. **Real-Time Updates**
   - Live player positions (fleet members)
   - Dynamic system security changes
   - Active war zones highlighted

3. **Strategic Overlays**
   - Sovereignty map (territory control)
   - Resource distribution
   - NPC faction influence
   - Trade route efficiency

4. **Customization**
   - User-defined color schemes
   - Filter presets
   - Custom info panels
   - Hotkey configuration

---

## Development Checklist

### Backend Requirements
- [ ] API endpoint: `GET /api/universe/systems` (all systems)
- [ ] API endpoint: `GET /api/universe/system/{id}/objects` (system objects)
- [ ] API endpoint: `GET /api/navigation/route?from={id}&to={id}` (pathfinding)
- [ ] Security status calculation and storage
- [ ] System connectivity graph (stargates)

### UE5 Implementation
- [ ] `UEchoesMapDataProvider` subsystem
- [ ] `AEchoesGalacticCloudRenderer` actor
- [ ] `AEchoesSystemInspector` actor
- [ ] `AEchoesMapCameraActor` with Scene Capture 2D
- [ ] `UEchoesMapWidget` fullscreen UI
- [ ] Map controls (pan, zoom, rotate)
- [ ] Click/double-click handling
- [ ] Zoom animation system

### Testing
- [ ] Load 10,000+ systems without performance drop
- [ ] Verify color coding accuracy
- [ ] Test click detection on instance meshes
- [ ] Validate route pathfinding
- [ ] Ensure smooth transitions
- [ ] Multiplayer: Map state synchronization

---

## References

**EVE Online:**
- Star Map with sovereignty overlays
- System map with celestial objects
- Jump route visualization

**Elite Dangerous:**
- Galaxy map with realistic star distribution
- System map with orbital mechanics
- Hyperspace jump effects

**Star Citizen:**
- Holographic star map
- System maps with planet details
- Quantum travel visualization

---

**Status:** Design Phase  
**Priority:** High (Milestone 2)  
**Estimated Duration:** 6-8 weeks  
**Dependencies:** Map Data Provider, Universe data backend

**Last Updated:** 2026-01-31  
**Document Owner:** Navigation Team
