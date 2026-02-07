# Item Definition System Extension - Implementation Guide

## Overview

This document describes the extended item definition system that supports weapon and equipment fitting with proper data separation between universal item properties and module-specific attributes.

## Architecture

### Two-Table Design

The system uses two separate data tables to avoid bloating:

1. **DT_ItemDefinitions** (`FEchoesItemDefinitionRow`)
   - Contains universal item data (name, icon, volume, mass, etc.)
   - Used for ALL items (ore, minerals, modules, ammo, etc.)
   - Required for every item in the game

2. **DT_WeaponAttributes** (`FWeaponAttributesRow`)
   - Contains weapon/module-specific combat stats
   - Only populated for modules and weapons
   - Optional table - only for combat items

### Data Structures

#### EEchoesSlotType Enum

```cpp
enum class EEchoesSlotType : uint8
{
    High,        // Weapons, offensive modules
    Mid,         // Shields, propulsion, e-war
    Low,         // Armor, damage mods, engine upgrades
    Rig,         // Permanent ship modifications
    Subsystem,   // T3 ship subsystems
    None         // Not fittable
};
```

#### FEchoesItemDefinitionRow (Base Item Data)

**New Fields Added**:
- `FitSlot` (EEchoesSlotType) - Which slot this module fits into
- `PowergridRequired` (float) - Powergrid requirement in MW
- `CPURequired` (float) - CPU requirement in tf

**Existing Fields**:
- `DisplayName` (FText) - Localized item name
- `Description` (FText) - Item description
- `Icon` (TSoftObjectPtr<UTexture2D>) - UI icon
- `WorldMesh` (TSoftObjectPtr<UStaticMesh>) - 3D representation
- `UnitVolume` (float) - Volume per unit in m³
- `UnitMass` (float) - Mass per unit in kg
- `Category` (EEchoesItemCategory) - Item type
- `MarketGroupId` (int32) - Market categorization
- `TechLevel` (int32) - Technology level (0-5)
- `MetaLevel` (int32) - Meta level (0+)
- `bIsStackable` (bool) - Can be stacked
- `MaxStackSize` (int32) - Maximum stack size

#### FWeaponAttributesRow (Combat Stats)

**Core Combat Properties**:
- `Damage` (float) - Base damage per hit/cycle
- `OptimalRange` (float) - Full damage distance (cm/UE units)
- `Falloff` (float) - Damage reduction range (cm)
- `TrackingSpeed` (float) - Tracking ability (radians/sec)
- `ActivationCost` (float) - Capacitor cost per activation (GJ)
- `ActivationTime` (float) - Cycle time between shots (seconds)

**Ammunition Properties**:
- `AmmoTypeId` (int32) - Required ammunition TypeId (0 = energy weapon)
- `AmmoConsumptionPerCycle` (int32) - Ammo used per shot
- `MaxAmmoCapacity` (int32) - Weapon's ammo capacity

**Modifiers**:
- `DamageMultiplier` (float) - Damage modifier for variants
- `RateOfFireMultiplier` (float) - ROF modifier

## Using the System

### 1. Setup (One-Time)

Create the data tables in Unreal Editor:

```
1. Right-click in Content Browser
2. Choose "Miscellaneous → Data Table"
3. Select "EchoesItemDefinitionRow" as struct
4. Name: "DT_ItemDefinitions"
5. Repeat for "WeaponAttributesRow" → "DT_WeaponAttributes"
```

### 2. Initialize Library

Call this during game initialization (e.g., in Game Instance):

```cpp
// Get references to data tables (loaded from project settings or hard-coded)
UDataTable* ItemsTable = LoadObject<UDataTable>(nullptr, TEXT("/Game/Data/DT_ItemDefinitions"));
UDataTable* WeaponsTable = LoadObject<UDataTable>(nullptr, TEXT("/Game/Data/DT_WeaponAttributes"));

// Initialize the library
UEchoesItemDataLibrary::SetDataTableReferences(ItemsTable, WeaponsTable);
```

### 3. Populating Data Tables

#### Item Definitions Table

Row Name = TypeId (as string, e.g., "34", "2048")

Example: Tritanium Ore
```
Row Name: "34"
DisplayName: "Tritanium"
Description: "The most basic ore..."
Icon: T_Icon_Tritanium
UnitVolume: 0.01
UnitMass: 0.01
Category: Ore
FitSlot: None  (not fittable)
PowergridRequired: 0
CPURequired: 0
```

Example: Light Neutron Blaster
```
Row Name: "2048"
DisplayName: "Light Neutron Blaster I"
Description: "Short range blaster..."
Icon: T_Icon_LightNeutronBlaster
UnitVolume: 5.0
UnitMass: 1000.0
Category: Module
FitSlot: High  (goes in high slot)
PowergridRequired: 4.5
CPURequired: 35.0
```

#### Weapon Attributes Table

Row Name = TypeId (same as item definitions, only for modules)

Example: Light Neutron Blaster Combat Stats
```
Row Name: "2048"
Damage: 55.0
OptimalRange: 200000.0  (2km in cm)
Falloff: 800000.0       (8km in cm)
TrackingSpeed: 0.4
ActivationCost: 5.0     (5 GJ capacitor)
ActivationTime: 3.0     (3 second cycle)
AmmoTypeId: 256         (Antimatter Charge S)
AmmoConsumptionPerCycle: 1
MaxAmmoCapacity: 100
DamageMultiplier: 1.0
RateOfFireMultiplier: 1.0
```

### 4. Using Helper Functions

#### Get Base Item Data

```cpp
// For any item type (ore, minerals, modules, etc.)
FEchoesItemDefinitionRow ItemDef;
if (UEchoesItemDataLibrary::Common_GetItemDefinition(TypeId, ItemDef))
{
    // Display in UI
    UE_LOG(LogTemp, Log, TEXT("Item: %s"), *ItemDef.DisplayName.ToString());
    UE_LOG(LogTemp, Log, TEXT("Volume: %.2f m³"), ItemDef.UnitVolume);
    UE_LOG(LogTemp, Log, TEXT("Fit Slot: %d"), (int32)ItemDef.FitSlot);
    
    // Load icon
    UTexture2D* Icon = ItemDef.Icon.LoadSynchronous();
}
```

#### Get Weapon Stats

```cpp
// For modules/weapons only
FWeaponAttributesRow WeaponStats;
if (UEchoesItemDataLibrary::Common_GetWeaponAttributes(TypeId, WeaponStats))
{
    // Use combat stats
    UE_LOG(LogTemp, Log, TEXT("Damage: %.2f"), WeaponStats.Damage);
    UE_LOG(LogTemp, Log, TEXT("Optimal: %.0f m"), WeaponStats.OptimalRange / 100.0f);
    UE_LOG(LogTemp, Log, TEXT("Cap Cost: %.2f GJ"), WeaponStats.ActivationCost);
}
```

#### Get Complete Module Data

```cpp
// Get everything at once (best for modules)
FCompleteModuleData ModuleData = UEchoesItemDataLibrary::Common_GetCompleteModuleData(TypeId);

if (ModuleData.bIsCompleteModule)
{
    // Both base and weapon data available
    FText Name = ModuleData.ItemDefinition.DisplayName;
    float Damage = ModuleData.WeaponAttributes.Damage;
    EEchoesSlotType Slot = ModuleData.ItemDefinition.FitSlot;
    
    UE_LOG(LogTemp, Log, TEXT("%s: %.0f damage in %s slot"), 
        *Name.ToString(), Damage, *UEnum::GetValueAsString(Slot));
}
else if (ModuleData.bItemFound)
{
    // Item exists but no weapon data (ore, minerals, etc.)
    UE_LOG(LogTemp, Log, TEXT("Non-combat item: %s"), 
        *ModuleData.ItemDefinition.DisplayName.ToString());
}
```

#### Quick Utility Functions

```cpp
// Check if item can be fitted
if (UEchoesItemDataLibrary::Common_IsFittableModule(TypeId))
{
    EEchoesSlotType Slot = UEchoesItemDataLibrary::Common_GetFitSlot(TypeId);
    float PG = UEchoesItemDataLibrary::Common_GetPowergridRequired(TypeId);
    float CPU = UEchoesItemDataLibrary::Common_GetCPURequired(TypeId);
    
    UE_LOG(LogTemp, Log, TEXT("Fittable: Slot=%d, PG=%.1f, CPU=%.1f"), 
        (int32)Slot, PG, CPU);
}

// Get item name without full structure
FText ItemName = UEchoesItemDataLibrary::Common_GetItemName(TypeId);

// Get icon directly
UTexture2D* Icon = UEchoesItemDataLibrary::Common_GetItemIcon(TypeId);

// Check if item exists
if (!UEchoesItemDataLibrary::Common_ItemExists(TypeId))
{
    UE_LOG(LogTemp, Error, TEXT("Item %d not found in database"), TypeId);
}
```

## Performance Considerations

### Caching System

The library automatically caches queries:
- First query: Reads from data table (slow)
- Subsequent queries: Returns cached data (instant)
- Cache persists for lifetime of play session

### Cache Management

```cpp
// Clear cache when data tables are reloaded
UEchoesItemDataLibrary::ClearCache();

// Cache is automatically cleared when SetDataTableReferences is called
```

### Async Icon Loading

Icons use `TSoftObjectPtr` for async loading:

```cpp
// Synchronous (blocks, use sparingly)
UTexture2D* Icon = ItemDef.Icon.LoadSynchronous();

// Asynchronous (recommended for UI)
TAssetPtr<UTexture2D> IconPtr = ItemDef.Icon;
// Use async loading manager or bind to OnAssetLoaded
```

## Integration Examples

### Fitting System Integration

```cpp
// In FittingWindowWidget::ValidateModulePlacement
bool CanFitModule(int32 TypeId, EEchoesSlotType TargetSlot)
{
    FEchoesItemDefinitionRow ItemDef;
    if (!UEchoesItemDataLibrary::Common_GetItemDefinition(TypeId, ItemDef))
    {
        return false; // Item not found
    }
    
    // Check if item can be fitted
    if (ItemDef.FitSlot == EEchoesSlotType::None)
    {
        return false; // Not fittable
    }
    
    // Check slot compatibility
    if (ItemDef.FitSlot != TargetSlot)
    {
        return false; // Wrong slot type
    }
    
    // Check ship resources
    float ShipPG = GetShipPowergridAvailable();
    float ShipCPU = GetShipCPUAvailable();
    
    if (ItemDef.PowergridRequired > ShipPG || ItemDef.CPURequired > ShipCPU)
    {
        return false; // Insufficient resources
    }
    
    return true;
}
```

### Combat System Integration

```cpp
// In WeaponComponent::CalculateDamage
float CalculateWeaponDamage(int32 WeaponTypeId, float Distance)
{
    FWeaponAttributesRow WeaponStats;
    if (!UEchoesItemDataLibrary::Common_GetWeaponAttributes(WeaponTypeId, WeaponStats))
    {
        return 0.0f; // Not a weapon
    }
    
    float BaseDamage = WeaponStats.Damage * WeaponStats.DamageMultiplier;
    
    // Apply range falloff
    if (Distance <= WeaponStats.OptimalRange)
    {
        return BaseDamage; // Full damage in optimal
    }
    else if (Distance <= WeaponStats.OptimalRange + WeaponStats.Falloff)
    {
        // Linear falloff
        float FalloffDistance = Distance - WeaponStats.OptimalRange;
        float FalloffPercent = 1.0f - (FalloffDistance / WeaponStats.Falloff);
        return BaseDamage * FalloffPercent;
    }
    else
    {
        return 0.0f; // Out of range
    }
}
```

### Inventory UI Integration

```cpp
// In InventoryEntryWidget::UpdateDisplay
void UpdateItemDisplay(int32 TypeId, int32 Quantity)
{
    FEchoesItemDefinitionRow ItemDef;
    if (UEchoesItemDataLibrary::Common_GetItemDefinition(TypeId, ItemDef))
    {
        // Set text
        ItemNameText->SetText(ItemDef.DisplayName);
        ItemVolumeText->SetText(FText::AsNumber(ItemDef.UnitVolume * Quantity));
        
        // Set icon (async)
        if (!ItemDef.Icon.IsNull())
        {
            ItemIconImage->SetBrushFromSoftTexture(ItemDef.Icon);
        }
        
        // Show fitting info if module
        if (ItemDef.FitSlot != EEchoesSlotType::None)
        {
            FittingInfoPanel->SetVisibility(ESlateVisibility::Visible);
            SlotTypeText->SetText(UEnum::GetDisplayValueAsText(ItemDef.FitSlot));
            PowergridText->SetText(FText::AsNumber(ItemDef.PowergridRequired));
            CPUText->SetText(FText::AsNumber(ItemDef.CPURequired));
        }
    }
}
```

## Blueprint Usage

All functions are exposed to Blueprint:

### Get Item Info

```
[Get Item Definition] (TypeId: 2048)
  ↓ [Out Item Definition]
  ↓ [Return Value: True]
  ↓
[Print String] (String: "DisplayName")
```

### Check if Fittable

```
[Is Fittable Module] (TypeId: 2048)
  ↓ [Return Value: True]
  ↓
[Branch]
  True → [Get Fit Slot] → [Print String]
  False → [Print] "Not a module"
```

### Get Complete Data

```
[Get Complete Module Data] (TypeId: 2048)
  ↓ [Return Value: FCompleteModuleData]
  ↓
[Break FCompleteModuleData]
  → Item Definition (struct)
  → Weapon Attributes (struct)
  → Is Complete Module (bool)
```

## Testing

### Unit Test Example

```cpp
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FItemDataLibraryTest, 
    "Echoes.ItemDataLibrary.BasicFunctionality", 
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FItemDataLibraryTest::RunTest(const FString& Parameters)
{
    // Setup
    UDataTable* ItemsTable = LoadObject<UDataTable>(/*...*/);
    UDataTable* WeaponsTable = LoadObject<UDataTable>(/*...*/);
    UEchoesItemDataLibrary::SetDataTableReferences(ItemsTable, WeaponsTable);
    
    // Test item exists
    TestTrue("Item 34 exists", UEchoesItemDataLibrary::Common_ItemExists(34));
    
    // Test get item definition
    FEchoesItemDefinitionRow ItemDef;
    TestTrue("Get Tritanium", UEchoesItemDataLibrary::Common_GetItemDefinition(34, ItemDef));
    TestEqual("Tritanium name", ItemDef.DisplayName.ToString(), TEXT("Tritanium"));
    
    // Test fittable check
    TestFalse("Ore not fittable", UEchoesItemDataLibrary::Common_IsFittableModule(34));
    TestTrue("Weapon fittable", UEchoesItemDataLibrary::Common_IsFittableModule(2048));
    
    // Test complete module data
    FCompleteModuleData ModuleData = UEchoesItemDataLibrary::Common_GetCompleteModuleData(2048);
    TestTrue("Module found", ModuleData.bItemFound);
    TestTrue("Weapon stats found", ModuleData.bWeaponAttributesFound);
    TestTrue("Complete module", ModuleData.bIsCompleteModule);
    
    return true;
}
```

## Troubleshooting

### Library Not Initialized

**Error**: "EchoesItemDataLibrary: Library not initialized!"

**Solution**: Call `SetDataTableReferences()` during game startup

### Item Not Found

**Warning**: "Item definition not found for TypeId: X"

**Solutions**:
1. Check TypeId is correct
2. Verify row exists in data table with name matching TypeId (as string)
3. Ensure data table is loaded and valid

### Icon Not Loading

**Issue**: Icon shows as null or default

**Solutions**:
1. Check Icon field is set in data table
2. Verify texture asset path is correct
3. Use `LoadSynchronous()` or async loading
4. Check texture is not excluded from build

### Performance Issues

**Issue**: Slow queries or memory issues

**Solutions**:
1. Ensure caching is working (check logs)
2. Call `ClearCache()` if tables are reloaded at runtime
3. Use async icon loading instead of synchronous
4. Profile with Unreal Insights

## Summary

The extended item definition system provides:
- ✅ Clean data separation (base items vs weapon stats)
- ✅ Comprehensive fitting support (slot types, PG/CPU requirements)
- ✅ Rich weapon attributes (damage, range, tracking, ammo)
- ✅ Efficient caching system
- ✅ Common_ prefixed helper functions
- ✅ Full Blueprint support
- ✅ Production-ready error handling

Use `Common_GetCompleteModuleData()` for modules and `Common_GetItemDefinition()` for all other items.
