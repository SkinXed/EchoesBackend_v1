# EchoesStatsComponent - Ship Survivability System

## Overview

`UEchoesStatsComponent` is a replicated ActorComponent that implements an EVE Online-inspired three-layer protection system for ships and structures in the Echoes MMO. The component provides server-authoritative damage handling with client-side UI updates through replication.

## Architecture

**Inheritance**: `UActorComponent`  
**Location**: `Source/Echoes/Core/Common/Components/`  
**Replication**: Fully replicated with RepNotify for UI updates  
**Authority**: Server-authoritative damage, client receives updates

## Three-Layer Protection System

The component implements EVE's signature three-layer defense system:

### 1. Shield (Щит)
- **First line of defense**
- **Passive regeneration**: Regenerates over time after taking damage
- **Properties**:
  - `ShieldCurrent`: Current shield HP (Replicated with RepNotify)
  - `ShieldMax`: Maximum shield HP (Replicated)
  - `ShieldRegenRate`: HP regenerated per second (default: 10 HP/s)
  - `ShieldRegenDelay`: Seconds before regeneration starts after damage (default: 10s)

### 2. Armor (Броня)
- **Second line of defense**
- **No automatic regeneration**: Must be repaired manually
- **Properties**:
  - `ArmorCurrent`: Current armor HP (Replicated with RepNotify)
  - `ArmorMax`: Maximum armor HP (Replicated)

### 3. Structure (Корпус)
- **Final line of defense**
- **Death when depleted**: Actor is destroyed when Structure reaches 0
- **Properties**:
  - `StructureCurrent`: Current structure HP (Replicated with RepNotify)
  - `StructureMax`: Maximum structure HP (Replicated)

## Damage Flow (EVE-like Cascade)

```
Incoming Damage
      ↓
[Shield > 0?] → Yes → Damage Shield → Overflow?
      ↓                                    ↓
      No ← ← ← ← ← ← ← ← ← ← ← ← ← ← ← ← Yes
      ↓
[Armor > 0?] → Yes → Damage Armor → Overflow?
      ↓                                   ↓
      No ← ← ← ← ← ← ← ← ← ← ← ← ← ← ← ← Yes
      ↓
[Structure > 0?] → Yes → Damage Structure
      ↓
[Structure <= 0?] → Yes → DEATH EVENT
```

## Public API

### Core Functions

#### `ServerOnly_ApplyDamage(float Amount, AActor* DamageCauser = nullptr)`
Apply damage using EVE-style cascade (Server only)

#### `Common_GetHealthPercentage() const`
Get overall health percentage for simplified UI (0.0 to 1.0)

#### `ClientOnly_OnRep_UpdateUI()`
Update UI when stats replicate (Called automatically by replication)

### Helper Functions

- `Common_GetShieldPercentage() const`
- `Common_GetArmorPercentage() const`
- `Common_GetStructurePercentage() const`
- `IsAlive() const`
- `ServerOnly_RestoreAll()`

## Delegates

### `FOnStatsChanged`
Fires on clients when stats replicate for UI updates

### `FOnDeath`
Fires on server when Structure <= 0

## Configuration

Default values (can be overridden):

```cpp
ShieldMax = 1000.0f;
ShieldRegenRate = 10.0f;
ShieldRegenDelay = 10.0f;
ArmorMax = 1000.0f;
StructureMax = 1000.0f;
```

## Usage Examples

### Attach to Ship

```cpp
StatsComponent = CreateDefaultSubobject<UEchoesStatsComponent>(TEXT("StatsComponent"));
StatsComponent->ShieldMax = 500.0f;
StatsComponent->ArmorMax = 300.0f;
StatsComponent->StructureMax = 200.0f;
```

### Apply Damage

```cpp
UEchoesStatsComponent* StatsComp = Target->FindComponentByClass<UEchoesStatsComponent>();
if (StatsComp)
{
    StatsComp->ServerOnly_ApplyDamage(WeaponDamage, InstigatorActor);
}
```

### Handle Death

```cpp
StatsComp->OnDeath.AddDynamic(this, &AShipPawn::OnShipDestroyed);
```

---

**Status**: ✅ Implemented  
**Last Updated**: 2026-02-06
