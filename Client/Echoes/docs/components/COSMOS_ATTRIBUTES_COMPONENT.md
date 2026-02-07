# CosmosAttributesComponent - Advanced Resistance-Based Damage System

## Overview

`UCosmosAttributesComponent` is an advanced replicated ActorComponent that implements an EVE Online-inspired three-layer defense system with per-damage-type resistances. This represents a production-ready combat system with sophisticated damage mitigation mechanics.

## Architecture

**Inheritance**: `UActorComponent`  
**Location**: `Source/Echoes/Core/Common/Components/`  
**Dependencies**: `EchoesCoreTypes.h` (damage types and defense layer struct)  
**Replication**: Fully replicated with RepNotify for UI updates  
**Authority**: Server-authoritative damage calculations with client updates

## Damage Type System

### ECosmosDamageType Enum

Five damage types with different characteristics:

| Type | Description | Typical Use |
|------|-------------|-------------|
| **EM** | Electromagnetic | Energy weapons, typically strong vs shields |
| **Thermal** | Heat-based | Lasers, plasma, typically strong vs armor |
| **Kinetic** | Physical projectiles | Railguns, autocannons, physical impact |
| **Explosive** | Explosive ordnance | Missiles, bombs, area damage |
| **Omni** | Pure damage | Special weapons, bypasses ALL resistances |

### Resistance-Based Mitigation

**Formula**: `MitigatedDamage = RawDamage × (1.0 - Resistance)`

**Examples**:
- 100 damage with 0.5 (50%) resistance = 50 damage taken
- 100 damage with 0.75 (75%) resistance = 25 damage taken
- 100 damage with 0.0 (0%) resistance = 100 damage taken
- 100 Omni damage = 100 damage taken (bypasses resistances)

## Defense Layer Structure

### FCosmosDefenseLayer

Each layer (Shield, Armor, Structure) contains:

**Hit Points**:
- `Current`: Current HP
- `Max`: Maximum HP

**Resistances** (0.0 to 1.0):
- `ResistEM`: EM damage resistance
- `ResistThermal`: Thermal damage resistance
- `ResistKinetic`: Kinetic damage resistance
- `ResistExplosive`: Explosive damage resistance

**Helper Functions**:
- `GetResistance(ECosmosDamageType)`: Get resistance for damage type
- `CalculateMitigatedDamage(float, ECosmosDamageType)`: Calculate damage after mitigation
- `GetPercentage()`: Get HP percentage (0.0 to 1.0)
- `IsDepleted()`: Check if layer is depleted
- `Restore()`: Restore to maximum HP

## Three-Layer Defense System

### 1. Shield Layer
**Properties**:
- First line of defense
- Can have high EM resistance, lower against other types
- Typical frigate: 500-1500 HP

**Example Resistance Profile** (Caldari):
```cpp
Shield.ResistEM = 0.5f;        // 50% EM resistance
Shield.ResistThermal = 0.2f;   // 20% Thermal resistance
Shield.ResistKinetic = 0.4f;   // 40% Kinetic resistance
Shield.ResistExplosive = 0.5f; // 50% Explosive resistance
```

### 2. Armor Layer
**Properties**:
- Second line of defense
- Different resistance profile than shield
- Typical frigate: 300-800 HP

**Example Resistance Profile** (Amarr):
```cpp
Armor.ResistEM = 0.5f;         // 50% EM resistance
Armor.ResistThermal = 0.35f;   // 35% Thermal resistance
Armor.ResistKinetic = 0.25f;   // 25% Kinetic resistance
Armor.ResistExplosive = 0.1f;  // 10% Explosive resistance
```

### 3. Structure Layer
**Properties**:
- Final line of defense (hull)
- Death when depleted
- Typically lowest resistances
- Typical frigate: 400-600 HP

**Example Resistance Profile** (Standard):
```cpp
Structure.ResistEM = 0.0f;        // 0% EM resistance
Structure.ResistThermal = 0.0f;   // 0% Thermal resistance
Structure.ResistKinetic = 0.0f;   // 0% Kinetic resistance
Structure.ResistExplosive = 0.0f; // 0% Explosive resistance
```

## Damage Cascade with Resistances

### How Damage Flows Through Layers

```
Incoming Damage (100 Thermal)
      ↓
[Shield: 50 HP, 20% Thermal resist]
  → Mitigated: 100 × (1.0 - 0.2) = 80 damage
  → Shield takes 50 damage (depleted)
  → Overflow: 30 damage
      ↓
[Armor: 200 HP, 35% Thermal resist]
  → Mitigated: 30 × (1.0 - 0.35) = 19.5 damage
  → Armor takes 19.5 damage
  → Armor: 180.5 HP remaining
      ↓
Result: Ship survives with 0/180.5/400 HP
```

### Complex Example with Multiple Hits

**Ship Stats**:
- Shield: 100 HP, 50% EM, 25% Thermal, 40% Kinetic, 50% Explosive
- Armor: 200 HP, 50% EM, 35% Thermal, 25% Kinetic, 10% Explosive
- Structure: 150 HP, 0% all resistances

**Attack Sequence**:

1. **100 EM damage**:
   - Shield: 100 × 0.5 = 50 damage, 50 HP remaining
   
2. **100 Thermal damage**:
   - Shield: 100 × 0.75 = 75 damage, depleted, 25 overflow
   - Armor: 25 × 0.65 = 16.25 damage, 183.75 HP remaining
   
3. **200 Kinetic damage**:
   - Armor: 200 × 0.75 = 150 damage, 33.75 HP remaining
   
4. **100 Explosive damage**:
   - Armor: 100 × 0.9 = 90 damage, depleted, 56.25 overflow
   - Structure: 56.25 × 1.0 = 56.25 damage, 93.75 HP remaining

**Final State**: 0/0/93.75 HP (ship survives)

## Public API

### Core Functions

#### `ServerOnly_ApplyDamage(float RawDamage, ECosmosDamageType DmgType, AActor* Instigator)`

**Authority**: Server only  
**Returns**: `bool` - True if damage was applied

**Parameters**:
- `RawDamage`: Raw damage amount before resistance mitigation
- `DmgType`: Type of damage (EM, Thermal, Kinetic, Explosive, Omni)
- `Instigator`: Actor that caused the damage (for kill attribution)

**Behavior**:
1. Validate server authority and actor state
2. Calculate mitigated damage for Shield layer
3. Apply to Shield, calculate overflow
4. If overflow > 0, calculate mitigated damage for Armor (with Armor's resistances)
5. Apply to Armor, calculate overflow
6. If overflow > 0, calculate mitigated damage for Structure (with Structure's resistances)
7. Apply to Structure
8. If Structure <= 0, trigger OnDeath event

**Example**:
```cpp
UCosmosAttributesComponent* AttrComp = 
    Target->FindComponentByClass<UCosmosAttributesComponent>();

if (AttrComp && AttrComp->IsAlive())
{
    // Apply 100 thermal damage
    AttrComp->ServerOnly_ApplyDamage(100.0f, ECosmosDamageType::Thermal, WeaponOwner);
}
```

#### `ServerOnly_SetLayerResistances(int32 LayerIndex, float EM, float Thermal, float Kinetic, float Explosive)`

**Authority**: Server only  
**Purpose**: Set resistances for a specific layer at runtime

**Parameters**:
- `LayerIndex`: 0=Shield, 1=Armor, 2=Structure
- `EM`, `Thermal`, `Kinetic`, `Explosive`: Resistance values (0.0 to 1.0)

**Example**:
```cpp
// Set shield resistances to Caldari profile
AttrComp->ServerOnly_SetLayerResistances(0, 0.5f, 0.2f, 0.4f, 0.5f);

// Set armor resistances to Amarr profile
AttrComp->ServerOnly_SetLayerResistances(1, 0.5f, 0.35f, 0.25f, 0.1f);
```

### Getter Functions

All getters are `BlueprintPure` and work on both server and client:

- `Common_GetShieldPct()`: Shield percentage (0.0 to 1.0)
- `Common_GetArmorPct()`: Armor percentage (0.0 to 1.0)
- `Common_GetHullPct()`: Structure percentage (0.0 to 1.0)
- `Common_GetOverallHealthPct()`: Overall health percentage (all layers combined)
- `IsAlive()`: True if Structure > 0

### Utility Functions

- `ServerOnly_RestoreAll()`: Fully restore all layers to maximum (server only)

## Delegates

### `FOnAttributesChanged` (BlueprintAssignable)

**Signature**: `void ()`  
**Fires**: On clients when any replicated attribute changes  
**Purpose**: Update UI widgets

### `FOnCosmosDeath` (BlueprintAssignable)

**Signature**: `void (AActor* Victim, AActor* Killer)`  
**Fires**: On server when Structure depletes  
**Purpose**: Trigger death logic

## Configuration Examples

### Caldari Frigate (Shield Tank)

```cpp
// High shield HP, good EM/Explosive shield resists
AttrComp->Shield.Max = 1200.0f;
AttrComp->Shield.Current = 1200.0f;
AttrComp->Shield.ResistEM = 0.5f;
AttrComp->Shield.ResistThermal = 0.2f;
AttrComp->Shield.ResistKinetic = 0.4f;
AttrComp->Shield.ResistExplosive = 0.5f;

// Low armor
AttrComp->Armor.Max = 400.0f;
AttrComp->Armor.Current = 400.0f;

// Standard structure
AttrComp->Structure.Max = 500.0f;
AttrComp->Structure.Current = 500.0f;
```

### Amarr Frigate (Armor Tank)

```cpp
// Moderate shield
AttrComp->Shield.Max = 600.0f;
AttrComp->Shield.Current = 600.0f;

// High armor HP, good EM/Thermal armor resists
AttrComp->Armor.Max = 1000.0f;
AttrComp->Armor.Current = 1000.0f;
AttrComp->Armor.ResistEM = 0.5f;
AttrComp->Armor.ResistThermal = 0.35f;
AttrComp->Armor.ResistKinetic = 0.25f;
AttrComp->Armor.ResistExplosive = 0.1f;

// Standard structure
AttrComp->Structure.Max = 500.0f;
AttrComp->Structure.Current = 500.0f;
```

### Minmatar Frigate (Speed Tank - Low Resists)

```cpp
// Low shield with minimal resists
AttrComp->Shield.Max = 500.0f;
AttrComp->Shield.Current = 500.0f;
AttrComp->Shield.ResistEM = 0.0f;
AttrComp->Shield.ResistThermal = 0.0f;
AttrComp->Shield.ResistKinetic = 0.0f;
AttrComp->Shield.ResistExplosive = 0.0f;

// Moderate armor with some explosive resist
AttrComp->Armor.Max = 600.0f;
AttrComp->Armor.Current = 600.0f;
AttrComp->Armor.ResistExplosive = 0.3f;

// High structure (relies on not getting hit)
AttrComp->Structure.Max = 600.0f;
AttrComp->Structure.Current = 600.0f;
```

## Physics Stats

The component also stores physics-related attributes:

```cpp
// Mass in kilograms (affects acceleration)
AttrComp->Mass = 1250000.0f; // 1,250 tons

// Inertia modifier (affects turning)
AttrComp->InertiaModifier = 1.2f;

// Cargo capacity in cubic meters
AttrComp->CargoCapacity = 400.0f; // 400 m³
```

These stats are replicated but don't affect damage calculations directly.

## Usage Examples

### 1. Configure Ship at Spawn

```cpp
void AShipPawn::BeginPlay()
{
    Super::BeginPlay();
    
    if (HasAuthority())
    {
        UCosmosAttributesComponent* AttrComp = 
            FindComponentByClass<UCosmosAttributesComponent>();
        
        if (AttrComp)
        {
            // Configure Caldari shield tanking frigate
            AttrComp->Shield.Max = 1200.0f;
            AttrComp->Shield.Current = 1200.0f;
            AttrComp->ServerOnly_SetLayerResistances(
                0, // Shield
                0.5f,  // EM
                0.2f,  // Thermal
                0.4f,  // Kinetic
                0.5f   // Explosive
            );
            
            AttrComp->Armor.Max = 400.0f;
            AttrComp->Armor.Current = 400.0f;
            
            AttrComp->Structure.Max = 500.0f;
            AttrComp->Structure.Current = 500.0f;
            
            // Bind death event
            AttrComp->OnDeath.AddDynamic(this, &AShipPawn::OnShipDestroyed);
        }
    }
}
```

### 2. Apply Weapon Damage

```cpp
void AWeaponActor::FireWeapon(AActor* Target)
{
    if (!HasAuthority()) return;
    
    UCosmosAttributesComponent* AttrComp = 
        Target->FindComponentByClass<UCosmosAttributesComponent>();
    
    if (AttrComp && AttrComp->IsAlive())
    {
        // Fire thermal laser for 150 damage
        bool bApplied = AttrComp->ServerOnly_ApplyDamage(
            150.0f,
            ECosmosDamageType::Thermal,
            GetOwner()
        );
        
        if (bApplied)
        {
            UE_LOG(LogTemp, Log, TEXT("Hit! Target health: %.1f%%"),
                AttrComp->Common_GetOverallHealthPct() * 100.0f);
        }
    }
}
```

### 3. Update UI Widget

```cpp
void UShipHealthWidget::NativeConstruct()
{
    Super::NativeConstruct();
    
    if (TargetShip)
    {
        UCosmosAttributesComponent* AttrComp = 
            TargetShip->FindComponentByClass<UCosmosAttributesComponent>();
        
        if (AttrComp)
        {
            // Bind to attributes changed event
            AttrComp->OnAttributesChanged.AddDynamic(
                this, &UShipHealthWidget::UpdateHealthBars);
            
            // Initial update
            UpdateHealthBars();
        }
    }
}

void UShipHealthWidget::UpdateHealthBars()
{
    if (!TargetShip) return;
    
    UCosmosAttributesComponent* AttrComp = 
        TargetShip->FindComponentByClass<UCosmosAttributesComponent>();
    
    if (AttrComp)
    {
        ShieldBar->SetPercent(AttrComp->Common_GetShieldPct());
        ArmorBar->SetPercent(AttrComp->Common_GetArmorPct());
        HullBar->SetPercent(AttrComp->Common_GetHullPct());
        
        // Update resistance displays
        UpdateResistanceDisplay(AttrComp->Shield);
    }
}
```

## Comparison with EchoesStatsComponent

| Feature | EchoesStatsComponent | CosmosAttributesComponent |
|---------|---------------------|---------------------------|
| Damage Types | None (uniform) | 5 types with resistances |
| Resistances | No | Yes (per layer, per type) |
| Damage Mitigation | No | Yes (resistance-based) |
| Shield Regen | Yes (passive) | No (must be added separately) |
| Complexity | Simple | Advanced |
| Use Case | Basic combat | Production EVE-like combat |

**Recommendation**: Use `CosmosAttributesComponent` for production systems requiring sophisticated damage mechanics. Use `EchoesStatsComponent` for simpler game modes or as a learning example.

## Testing Scenarios

### Test 1: Basic Damage Application

```cpp
// Setup
AttrComp->Shield.Current = 100.0f;
AttrComp->Shield.ResistThermal = 0.5f;

// Test
AttrComp->ServerOnly_ApplyDamage(100.0f, ECosmosDamageType::Thermal, nullptr);

// Expected: Shield = 50 HP (100 damage × 50% mitigation)
```

### Test 2: Damage Cascade

```cpp
// Setup
AttrComp->Shield.Current = 50.0f;
AttrComp->Shield.ResistKinetic = 0.0f;
AttrComp->Armor.Current = 200.0f;
AttrComp->Armor.ResistKinetic = 0.5f;

// Test
AttrComp->ServerOnly_ApplyDamage(100.0f, ECosmosDamageType::Kinetic, nullptr);

// Expected:
// - Shield: 0 HP (took 50, depleted)
// - Armor: 175 HP (50 overflow × 50% mitigation = 25 damage taken)
```

### Test 3: Omni Damage Bypass

```cpp
// Setup
AttrComp->Shield.Current = 100.0f;
AttrComp->Shield.ResistEM = 0.75f; // 75% resist means nothing for Omni

// Test
AttrComp->ServerOnly_ApplyDamage(100.0f, ECosmosDamageType::Omni, nullptr);

// Expected: Shield = 0 HP (Omni bypasses all resistances)
```

---

**Status**: ✅ Implemented  
**Priority**: High  
**Milestone**: Combat System - Milestone 3  
**Dependencies**: EchoesCoreTypes.h, Net/UnrealNetwork.h  
**Last Updated**: 2026-02-06
