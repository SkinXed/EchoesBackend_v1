# Echoes World Generator System

## Overview

The **AEchoesWorldGenerator** is a sophisticated server-side procedural generation system that builds dynamic star systems in Unreal Engine 5 based on JSON configuration received from the ASP.NET Core backend. This system enables seamless universe construction with data-driven visual variety and seed-based procedural uniqueness.

## Architecture

### Components

1. **Data Table Row Structures** (`EchoesWorldVisualTypes.h`)
   - `FPlanetVisualRow`: Defines planet visuals (meshes, materials, atmospheres, clouds, rings)
   - `FStarVisualRow`: Defines star visuals (corona effects, lighting, post-process)
   - `FStationVisualRow`: Defines station visuals (modular parts, faction decals, lights)
   - `FStargateVisualRow`: Defines stargate visuals (gate mesh, portal VFX, audio)

2. **Celestial Object Actors**
   - `APlanetActor`: Replicated planet with seed-based variation
   - `AStarActor`: Replicated star with temperature-based lighting
   - `AStationActor`: Replicated station with modular construction
   - `AStargateActor`: Replicated stargate with portal effects

3. **World Generator** (`AEchoesWorldGenerator`)
   - Subscribes to `OnServerConfigReceived` delegate
   - Spawns all celestial objects server-side
   - Implements coordinate scaling
   - Manages data table lookups
   - Handles asset streaming (prepared for async loading)

## Setup Instructions

### 1. Create Data Tables

In Unreal Editor, create four Data Tables:

#### Planet Data Table
1. Right-click in Content Browser → Miscellaneous → Data Table
2. Select `FPlanetVisualRow` as the row structure
3. Name it `DT_PlanetVisuals`
4. Add rows for each planet type:
   - **Lava**: Red/orange materials, high emissive, no atmosphere
   - **Oceanic**: Blue materials, thick atmosphere, cloud layers
   - **Barren**: Gray materials, thin atmosphere
   - **Gaseous**: Swirling materials, rings, thick atmosphere
   - **Terrestrial**: Earth-like, moderate atmosphere, clouds
   - **Ice**: White/blue materials, thin atmosphere
   - **Default**: Fallback visuals

#### Star Data Table
1. Create Data Table with `FStarVisualRow` structure
2. Name it `DT_StarVisuals`
3. Add rows for star classes:
   - **G2V**: Sun-like (yellow)
   - **M5**: Red dwarf
   - **K0**: Orange dwarf
   - **F5**: White dwarf
   - **A0**: Blue-white
   - **B5**: Blue
   - **O5**: Hot blue
   - **Default**: Fallback visuals

#### Station Data Table
1. Create Data Table with `FStationVisualRow` structure
2. Name it `DT_StationVisuals`
3. Add rows for station types:
   - **Trading**: Commercial appearance
   - **Military**: Fortified, weapon arrays
   - **Research**: Scientific equipment
   - **Mining**: Industrial, processing facilities
   - **Default**: Generic station

#### Stargate Data Table
1. Create Data Table with `FStargateVisualRow` structure
2. Name it `DT_StargateVisuals`
3. Add rows for gate models:
   - **Standard**: Default ring gate
   - **Ancient**: Old/damaged aesthetic
   - **Advanced**: High-tech appearance
   - **Default**: Fallback visuals

### 2. Configure Actor Classes

#### Create Blueprint Classes
1. Create Blueprint based on `APlanetActor` → Name: `BP_Planet`
2. Create Blueprint based on `AStarActor` → Name: `BP_Star`
3. Create Blueprint based on `AStationActor` → Name: `BP_Station`
4. Create Blueprint based on `AStargateActor` → Name: `BP_Stargate`

#### Assign Meshes and Materials
In each Blueprint:
- Add default meshes (spheres for planets/stars)
- Assign base materials
- Configure components as needed

### 3. Place World Generator in Level

1. Create Blueprint based on `AEchoesWorldGenerator` → Name: `BP_WorldGenerator`
2. Place one instance in your persistent level (e.g., SystemLevel)
3. Configure properties:
   - **UniverseToWorldScale**: Default `0.0001` (1 km = 0.1 cm)
   - **PlanetDataTable**: Reference to `DT_PlanetVisuals`
   - **StarDataTable**: Reference to `DT_StarVisuals`
   - **StationDataTable**: Reference to `DT_StationVisuals`
   - **StargateDataTable**: Reference to `DT_StargateVisuals`
   - **PlanetActorClass**: Reference to `BP_Planet`
   - **StarActorClass**: Reference to `BP_Star`
   - **StationActorClass**: Reference to `BP_Station`
   - **StargateActorClass**: Reference to `BP_Stargate`

### 4. Server Configuration

In `DefaultGame.ini`, ensure server management subsystem is configured:

```ini
[/Script/Echoes.EchoesServerManagementSubsystem]
BackendURL=http://your-backend-url:5000
ServerSecret=your-server-secret-here
```

## How It Works

### Generation Flow

1. **Server Startup**
   - `UEchoesServerManagementSubsystem` registers with backend
   - Receives `FServerSystemConfig` with universe data

2. **Delegate Broadcast**
   - Subsystem broadcasts `OnServerConfigReceived`
   - `AEchoesWorldGenerator` receives configuration

3. **World Generation**
   ```cpp
   OnServerConfigReceived(Config)
   ├─ SpawnStar(Config)
   │  ├─ Look up StarVisualRow from DataTable
   │  ├─ Spawn AStarActor at origin
   │  └─ Initialize with temperature, luminosity
   │
   ├─ SpawnPlanets(Config.Planets)
   │  ├─ For each planet:
   │  ├─ Convert coordinates (km → cm)
   │  ├─ Look up PlanetVisualRow by type
   │  ├─ Generate seed from GUID
   │  ├─ Spawn APlanetActor
   │  └─ Apply seed-based variation
   │
   ├─ SpawnStations(Config.Stations)
   │  └─ Similar to planets
   │
   └─ SpawnStargates(Config.Stargates)
      └─ Similar to planets
   ```

4. **Replication**
   - All spawned actors have `bReplicates = true`
   - Clients receive actors automatically
   - Visual data applied on both server and clients

### Coordinate Scaling

**Problem**: Astronomical distances cause floating-point precision issues in UE5.

**Solution**: `UniverseToWorldScale` constant converts database coordinates to manageable Unreal units.

```cpp
// Database: Planet at 150,000,000 km (1 AU from star)
// UniverseToWorldScale = 0.0001
// Result: 150,000,000 km × 0.0001 × 100,000 = 1,500,000 cm (15 km in UE)
```

**Recommended Scales**:
- Small systems: `0.001` (1 km = 1 cm)
- Medium systems: `0.0001` (1 km = 0.1 cm) [Default]
- Large systems: `0.00001` (1 km = 0.01 cm)

### Seed-Based Variation

Each planet uses its GUID to generate a consistent seed:

```cpp
int32 Seed = GenerateSeedFromGuid(PlanetId);
// Seed used for:
// - Material selection from array
// - Rotation randomization
// - Scale variation (±10%)
// - Atmosphere density
// - Cloud speed
// - Texture parameters
```

**Result**: Two "Lava" planets in the same system look different but consistent across server restarts.

## Optimization: Async Asset Loading

The system is **prepared** for async asset loading using `UStreamableManager`:

```cpp
void AEchoesWorldGenerator::AsyncLoadAssetsForConfig(const FServerSystemConfig& Config)
{
    // Collect all TSoftObjectPtr references
    TArray<FSoftObjectPath> AssetsToLoad;
    
    for (const FPlanetConfig& Planet : Config.Planets)
    {
        FPlanetVisualRow* VisualData = GetPlanetVisualData(Planet.Type);
        if (VisualData)
        {
            if (!VisualData->Mesh.IsNull())
                AssetsToLoad.Add(VisualData->Mesh.ToSoftObjectPath());
            
            for (const auto& Material : VisualData->MaterialInstances)
                if (!Material.IsNull())
                    AssetsToLoad.Add(Material.ToSoftObjectPath());
        }
    }
    
    // Request async load
    StreamableManager.RequestAsyncLoad(AssetsToLoad, 
        FStreamableDelegate::CreateUObject(this, &AEchoesWorldGenerator::OnAssetsLoaded));
}
```

**Benefits**:
- Prevents server startup stalls
- Only loads assets for current system
- Memory efficient with `TSoftObjectPtr`

## Network Security

### Server Authority
All generation happens **only** on the server:

```cpp
if (!HasAuthority())
{
    UE_LOG(LogTemp, Warning, TEXT("ServerOnly function called on client - ignoring"));
    return;
}
```

### Replication
```cpp
// In actor constructors:
bReplicates = true;
bAlwaysRelevant = true; // Planets always visible to all clients

// In GetLifetimeReplicatedProps:
DOREPLIFETIME(APlanetActor, PlanetId);
DOREPLIFETIME(APlanetActor, PlanetName);
DOREPLIFETIME(APlanetActor, PlanetType);
// ... etc
```

### OnRep Functions
```cpp
UFUNCTION()
void OnRep_PlanetData()
{
    // When data replicates to client, apply visuals
    ApplyVisualConfiguration();
}
```

## Testing

### Manual Testing (Development)

1. Place `BP_WorldGenerator` in level
2. In PIE (Play In Editor), use console:
   ```
   ServerOnly_GenerateWorld
   ```

3. Verify:
   - Star spawns at origin
   - Planets spawn at correct positions
   - Coordinates scaled properly
   - Seed variation visible

### Dedicated Server Testing

1. Package server build
2. Launch with command line:
   ```
   EchoesServer.exe -log -SystemId=<guid>
   ```

3. Check logs:
   ```
   LogEchoesServer: SERVER REGISTRATION SUCCESSFUL
   LogTemp: ECHOES WORLD GENERATOR - SERVER CONFIG RECEIVED
   LogTemp: ✓ Star spawned successfully at origin
   LogTemp: ✓ Planet spawned: Earth (Type: Terrestrial) at (...)
   ```

## Extending the System

### Adding New Celestial Object Types

1. **Create Row Structure**
   ```cpp
   USTRUCT(BlueprintType)
   struct FAsteroidBeltVisualRow : public FTableRowBase
   {
       GENERATED_BODY()
       
       UPROPERTY(EditAnywhere, BlueprintReadWrite)
       TSoftObjectPtr<UNiagaraSystem> AsteroidFieldVFX;
       
       // ... more properties
   };
   ```

2. **Create Actor Class**
   ```cpp
   UCLASS()
   class ECHOES_API AAsteroidBeltActor : public AActor
   {
       GENERATED_BODY()
       // Implement similar to APlanetActor
   };
   ```

3. **Add to World Generator**
   ```cpp
   void SpawnAsteroidBelts(const TArray<FAsteroidBeltConfig>& Belts);
   ```

### Custom Spawn Logic

Override spawn functions for special behavior:

```cpp
void AEchoesWorldGenerator::SpawnPlanets(const TArray<FPlanetConfig>& Planets)
{
    for (const FPlanetConfig& PlanetConfig : Planets)
    {
        // Custom logic here
        if (PlanetConfig.Type == TEXT("Homeworld"))
        {
            // Spawn with special properties
        }
        
        // ... standard spawn
    }
}
```

## Troubleshooting

### Issue: "PlanetDataTable is not set!"
**Solution**: Assign data tables in `BP_WorldGenerator` properties.

### Issue: Actors not spawning
**Check**:
1. Is this a dedicated server? (`NetMode == NM_DedicatedServer`)
2. Is `OnServerConfigReceived` being called? (Check logs)
3. Are actor classes set in generator?

### Issue: Floating-point precision artifacts
**Solution**: Adjust `UniverseToWorldScale` to smaller value (e.g., `0.00001`).

### Issue: Assets not loading
**Solution**: Currently uses direct references. Implement async loading for production.

## Performance Considerations

### Memory
- Use `TSoftObjectPtr` in data tables (lazy loading)
- Clear world between system changes: `ServerOnly_ClearWorld()`

### Network
- Actors replicate only once at spawn
- Use `bAlwaysRelevant` sparingly (planets ok, asteroids maybe not)

### CPU
- Generation happens once per system load
- Cloud rotation uses timer, not Tick
- Stargate ring rotation uses Tick (consider timer)

## Best Practices

1. **Always check `HasAuthority()`** before server-only operations
2. **Use seeds for variation**, not random values (consistency)
3. **Log verbosely during generation** for debugging
4. **Validate data table references** before lookup
5. **Plan coordinate scale** before building system
6. **Test with real backend data** early and often

## API Reference

### AEchoesWorldGenerator

**Properties**:
- `float UniverseToWorldScale`: Coordinate scaling factor
- `UDataTable* PlanetDataTable`: Planet visual mappings
- `UDataTable* StarDataTable`: Star visual mappings
- `UDataTable* StationDataTable`: Station visual mappings
- `UDataTable* StargateDataTable`: Stargate visual mappings

**Methods**:
- `void ServerOnly_GenerateWorld(const FServerSystemConfig& Config)`: Generate world from config
- `void ServerOnly_ClearWorld()`: Destroy all spawned actors
- `FVector ConvertCoordinates(int64 X, int64 Y, int64 Z)`: Convert db coords to world coords

### APlanetActor

**Methods**:
- `void InitializePlanet(...)`: Initialize with config data
- `void ApplySeedVariation()`: Apply procedural uniqueness
- `int32 GetSeed()`: Get variation seed

### AStarActor

**Methods**:
- `void InitializeStar(...)`: Initialize with config data
- `FLinearColor CalculateLightColorFromTemperature(float TempKelvin)`: Wien's approximation

## Future Enhancements

- [ ] Implement full async asset loading pipeline
- [ ] Add asteroid belt instancing for performance
- [ ] Support dynamic system transitions (jump mechanics)
- [ ] Add nebula and gas cloud rendering
- [ ] Implement planetary orbits (optional visual enhancement)
- [ ] Add LOD system for distant objects
- [ ] Support procedural moon generation

## License

Copyright Epic Games, Inc. All Rights Reserved.

---

**Version**: 1.0  
**Author**: Echoes Development Team  
**Last Updated**: January 2026
