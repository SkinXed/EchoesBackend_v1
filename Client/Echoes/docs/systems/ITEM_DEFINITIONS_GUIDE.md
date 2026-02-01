# Item Definitions & Visual Mapping System

## Overview

The Item Definitions system provides a centralized way to map database item IDs (TypeId) to visual assets and metadata in Unreal Engine through Data Tables. This enables proper icon display, 3D mesh representation, and physics calculations for inventory items.

## Architecture

```
Database TypeId (34)
    ↓
Data Table Row ("34")
    ↓
FEchoesItemDefinitionRow
    ├─ DisplayName: "Tritanium"
    ├─ Description: "Common ore..."
    ├─ Icon: T_Icon_Tritanium (Soft Ptr)
    ├─ WorldMesh: SM_Ore_Tritanium (Soft Ptr)
    ├─ UnitVolume: 0.01 m³
    ├─ UnitMass: 0.01 kg
    └─ Category: Ore
```

## Components

### 1. FEchoesItemDefinitionRow

**Location**: `Core/Common/EchoesItemDefinitions.h`

**Purpose**: Data table row structure defining item properties

**Fields**:
```cpp
// Display
FText DisplayName          // Localized name
FText Description          // Localized description

// Visual Assets (Soft References)
TSoftObjectPtr<UTexture2D> Icon        // UI icon (64x64 or 128x128)
TSoftObjectPtr<UStaticMesh> WorldMesh  // 3D mesh for world

// Physics
float UnitVolume = 0.01f   // Volume per unit (m³)
float UnitMass = 0.01f     // Mass per unit (kg)

// Metadata
EEchoesItemCategory Category    // Item category
int32 MarketGroupId            // Market categorization
int32 TechLevel = 1            // Tech level (0-5)
int32 MetaLevel = 0            // Meta level (0+)
bool bIsStackable = true       // Can stack
int32 MaxStackSize = 0         // Max stack (0 = unlimited)
```

### 2. EEchoesItemCategory Enum

Categories for item classification:

- **None** - Uncategorized
- **Ore** - Raw ores
- **Mineral** - Refined minerals
- **Module** - Ship modules
- **Ammo** - Ammunition
- **Ship** - Ship hulls
- **Blueprint** - Manufacturing blueprints
- **Component** - Manufacturing components
- **Commodity** - Trade goods
- **Implant** - Character implants
- **Skill** - Skill books
- **Charge** - Module charges
- **Drone** - Combat drones
- **Fighter** - Fighter craft
- **Structure** - Deployable structures
- **Subsystem** - Ship subsystems
- **Rig** - Ship rigs

### 3. UEchoesInventorySubsystem Integration

**New Methods**:

```cpp
// Get item definition by ID
const FEchoesItemDefinitionRow* GetItemDefinition(const FString& ItemId);
const FEchoesItemDefinitionRow* GetItemDefinitionByTypeId(int32 TypeId);

// Async asset loading (prevents freezes)
void AsyncLoadItemIcon(const FString& ItemId, FOnIconLoaded OnLoaded);
void AsyncLoadItemWorldMesh(const FString& ItemId, FOnWorldMeshLoaded OnLoaded);

// Validation
bool HasItemDefinition(const FString& ItemId);
```

**Internal Components**:
- `ItemDefinitionsTable` - Data table reference
- `FStreamableManager` - Async asset loading
- `DefinitionCache` - Fast lookup cache
- `BuildDefinitionCache()` - Cache initialization

### 4. Updated UEchoesInventoryItemObject

**New Features**:
- Auto-fetches item definition on initialization
- Provides localized display name and description
- Calculates volumes using definition data
- Supports mass calculations

**New Methods**:
```cpp
const FEchoesItemDefinitionRow* GetItemDefinition();
FText GetDisplayName();           // Localized from definition
FText GetDescription();           // Localized from definition
float GetCalculatedTotalVolume(); // Quantity * UnitVolume
float GetUnitVolume();            // From definition
float GetTotalMass();             // Quantity * UnitMass
bool HasDefinition();             // Check if loaded
```

### 5. Updated UEchoesInventoryEntryWidget

**New Features**:
- Async icon loading with placeholder
- Displays localized item names
- Shows calculated volumes from definitions

**New Methods**:
```cpp
void StartAsyncIconLoad();        // Initiates async load
void HandleIconLoaded(UTexture2D*); // Callback
Event OnIconLoaded(UTexture2D*);  // Blueprint event
```

**New Properties**:
```cpp
UPROPERTY(EditAnywhere)
UTexture2D* PlaceholderIcon;  // Shown while loading
```

## Data Table Setup

### Step 1: Create Data Table Asset

1. In Unreal Editor, right-click in Content Browser
2. Select **Miscellaneous > Data Table**
3. Choose **EchoesItemDefinitionRow** as Row Structure
4. Name it `DT_ItemDefinitions`

### Step 2: Populate Data Table

For each item type in your database:

**Row Name**: TypeId as string (e.g., "34")

**Example Row (Tritanium)**:
```
Row Name: "34"
DisplayName: Tritanium
Description: The most common ore found in space. Essential for ship construction.
Icon: /Game/Textures/Items/Icons/T_Icon_Tritanium
WorldMesh: /Game/Meshes/Items/Ores/SM_Ore_Tritanium
UnitVolume: 0.01
UnitMass: 0.01
Category: Ore
MarketGroupId: 1
TechLevel: 1
MetaLevel: 0
bIsStackable: true
MaxStackSize: 0
```

**Example Row (Ship Module)**:
```
Row Name: "123"
DisplayName: 10MN Afterburner I
Description: Increases ship speed dramatically for short periods.
Icon: /Game/Textures/Items/Icons/T_Icon_Afterburner
WorldMesh: /Game/Meshes/Items/Modules/SM_Afterburner
UnitVolume: 5.0
UnitMass: 1000.0
Category: Module
MarketGroupId: 15
TechLevel: 1
MetaLevel: 0
bIsStackable: false
MaxStackSize: 1
```

### Step 3: Configure Subsystem

1. **Option A: Project Settings**
   - Edit > Project Settings
   - Search for "Item Definitions"
   - Set `ItemDefinitionsTable` to `DT_ItemDefinitions`

2. **Option B: Game Instance**
   ```cpp
   // In your game instance initialization
   UEchoesInventorySubsystem* InvSys = GetSubsystem<UEchoesInventorySubsystem>();
   if (InvSys)
   {
       InvSys->ItemDefinitionsTable = LoadObject<UDataTable>(nullptr, TEXT("/Game/Data/DT_ItemDefinitions"));
   }
   ```

3. **Option C: Blueprint**
   - In Game Instance Blueprint
   - Get Echoes Inventory Subsystem
   - Set Item Definitions Table

## Usage Examples

### Get Item Definition

```cpp
// C++
UEchoesInventorySubsystem* InvSys = GetGameInstance()->GetSubsystem<UEchoesInventorySubsystem>();

// By string ID
const FEchoesItemDefinitionRow* Def = InvSys->GetItemDefinition("34");

// By integer TypeId
const FEchoesItemDefinitionRow* Def2 = InvSys->GetItemDefinitionByTypeId(34);

if (Def)
{
    FText Name = Def->DisplayName;      // "Tritanium"
    float Volume = Def->UnitVolume;     // 0.01
    UTexture2D* Icon = Def->Icon.Get(); // May be null if not loaded
}
```

### Async Load Icon

```cpp
// Prevent UI freeze with async loading
InvSys->AsyncLoadItemIcon("34", FOnIconLoaded::CreateLambda([](UTexture2D* Icon)
{
    if (Icon)
    {
        // Icon loaded, update UI
        MyImageWidget->SetBrushFromTexture(Icon);
    }
}));
```

### In Inventory Item Object

```cpp
// Automatically done in InitializeWithData
UEchoesInventoryItemObject* ItemObj = NewObject<UEchoesInventoryItemObject>();
ItemObj->InitializeWithData(ItemData); // Auto-fetches definition

// Access definition data
FText DisplayName = ItemObj->GetDisplayName();      // Localized
FText Description = ItemObj->GetDescription();      // Localized
float TotalVolume = ItemObj->GetCalculatedTotalVolume(); // Qty * UnitVolume
float TotalMass = ItemObj->GetTotalMass();          // Qty * UnitMass
```

### In Entry Widget

```cpp
// Entry widget automatically loads icons async
void UEchoesInventoryEntryWidget::SetItemData(UEchoesInventoryItemObject* ItemObject)
{
    // Display localized name
    ItemNameText->SetText(ItemObject->GetDisplayName());
    
    // Show placeholder icon
    ItemIcon->SetBrushFromTexture(PlaceholderIcon);
    
    // Start async load (icon updates when ready)
    StartAsyncIconLoad();
}

// Blueprint event fires when icon is loaded
Event OnIconLoaded(UTexture2D* Icon)
{
    // Play animation, update visual state, etc.
}
```

## Async Loading Flow

```
Entry Widget Created
    ↓
SetItemData() Called
    ↓
Show Placeholder Icon
    ↓
StartAsyncIconLoad()
    ↓
InvSys->AsyncLoadItemIcon()
    ↓
FStreamableManager->RequestAsyncLoad()
    ↓
[Background Loading]
    ↓
Callback: HandleIconLoaded()
    ↓
Update ItemIcon Brush
    ↓
Trigger OnIconLoaded Blueprint Event
```

**Benefits**:
- No UI freezes when opening large inventories
- Icons load in background
- Placeholder shown during load
- Automatic cache after first load

## Optimization

### Icon Loading

**Recommended Icon Sizes**:
- ListView Icons: 64x64 or 128x128
- Detail Panel Icons: 256x256
- Tooltip Icons: 128x128

**Format**: PNG with transparency or DDS (compressed)

**Batch Loading**:
```cpp
// Load all icons for visible items
TArray<FString> ItemIds = GetVisibleItemIds();
for (const FString& ItemId : ItemIds)
{
    InvSys->AsyncLoadItemIcon(ItemId, IconLoadedDelegate);
}
```

### World Mesh Loading

**Soft References**: Always use `TSoftObjectPtr<UStaticMesh>`
- Not loaded into memory until needed
- Streamed when item is ejected into space

**HISM (Hierarchical Instanced Static Mesh)**:
```cpp
// For multiple instances of same item in space
UCLASS()
class AEjectedItemsManager : public AActor
{
    UPROPERTY()
    UHierarchicalInstancedStaticMeshComponent* OreInstancedMesh;
    
    void SpawnEjectedItem(const FString& ItemId, FVector Location)
    {
        // Load mesh async
        InvSys->AsyncLoadItemWorldMesh(ItemId, FOnWorldMeshLoaded::CreateLambda(
            [this, Location](UStaticMesh* Mesh)
            {
                if (Mesh)
                {
                    // Add instance to HISM component
                    FTransform Transform(Location);
                    OreInstancedMesh->AddInstance(Transform);
                }
            }
        ));
    }
};
```

**LOD (Level of Detail)**:
```cpp
// In mesh import settings
LOD 0: Full detail (< 1000m)
LOD 1: Medium detail (1000-5000m)
LOD 2: Low detail (5000-10000m)
LOD 3: Billboard (> 10000m)
```

### Memory Management

**Cache Clearing**:
```cpp
// Clear loaded assets when changing regions
void OnRegionChange()
{
    // Soft pointers auto-unload when no longer referenced
    // But you can force cleanup:
    StreamableManager.Unload(IconPath);
}
```

**Definition Cache**:
- Built once on subsystem initialization
- Stored in TMap for O(1) lookups
- Minimal memory overhead (just pointers)

## Localization

### Text Assets

**Localization Workflow**:
1. In Data Table, use `FText` for DisplayName and Description
2. Mark for localization: `LOCTEXT("ItemName_34", "Tritanium")`
3. Generate .pot files
4. Translate to target languages
5. Load appropriate localization at runtime

**Example Localized Entry**:
```cpp
// English
DisplayName: NSLOCTEXT("Items", "Ore_Tritanium", "Tritanium")
Description: NSLOCTEXT("Items", "Ore_Tritanium_Desc", "The most common ore...")

// Russian (auto-loaded based on settings)
DisplayName: "Тританиум"
Description: "Самая распространенная руда..."
```

## Physics Integration

### Ship Mass Calculations

```cpp
// Calculate total cargo mass
float UEchoesInventoryComponent::CalculateCargoMass()
{
    float TotalMass = 0.0f;
    
    for (const FEchoesInventoryItem& Item : CachedItems.Items)
    {
        UEchoesInventoryItemObject* ItemObj = CreateItemObject(Item);
        TotalMass += ItemObj->GetTotalMass();
    }
    
    return TotalMass;
}

// Update ship physics
void APlayerShip::UpdatePhysics()
{
    float CargoMass = InventoryComponent->CalculateCargoMass();
    float TotalMass = BaseMass + CargoMass;
    
    // Apply to physics component
    ShipMeshComponent->SetMassOverrideInKg(NAME_None, TotalMass, true);
}
```

### Volume Calculations

```cpp
// Check if item fits in cargo
bool CanFit(UEchoesInventoryItemObject* Item, int64 Quantity)
{
    float RequiredVolume = Item->GetUnitVolume() * Quantity;
    float AvailableVolume = Capacity - UsedVolume;
    return RequiredVolume <= AvailableVolume;
}
```

## Error Handling

### Missing Definitions

```cpp
// Always check if definition exists
const FEchoesItemDefinitionRow* Def = InvSys->GetItemDefinition(ItemId);
if (!Def)
{
    UE_LOG(LogTemp, Warning, TEXT("No definition for item: %s"), *ItemId);
    
    // Use fallback data from ItemData
    DisplayName = FText::FromString(ItemData.TypeName);
    Volume = ItemData.Volume;
    Icon = DefaultIcon;
}
```

### Missing Assets

```cpp
// Handle missing icons
if (Def->Icon.IsNull())
{
    // Use category default icon
    Icon = GetCategoryDefaultIcon(Def->Category);
}

// Handle failed async load
InvSys->AsyncLoadItemIcon(ItemId, FOnIconLoaded::CreateLambda([](UTexture2D* Icon)
{
    if (!Icon)
    {
        // Use fallback icon
        ItemIcon->SetBrushFromTexture(DefaultIcon);
    }
}));
```

## Testing

### Data Table Validation

```cpp
// Validate all entries have required data
void ValidateItemDefinitions(UDataTable* Table)
{
    TArray<FEchoesItemDefinitionRow*> Rows;
    Table->GetAllRows<FEchoesItemDefinitionRow>("", Rows);
    
    for (FEchoesItemDefinitionRow* Row : Rows)
    {
        if (Row->DisplayName.IsEmpty())
            UE_LOG(LogTemp, Error, TEXT("Row missing DisplayName"));
        
        if (Row->UnitVolume <= 0.0f)
            UE_LOG(LogTemp, Warning, TEXT("Row has invalid UnitVolume"));
        
        if (Row->Icon.IsNull())
            UE_LOG(LogTemp, Warning, TEXT("Row has no icon"));
    }
}
```

### Performance Testing

```cpp
// Test icon loading performance
void TestAsyncIconLoading()
{
    double StartTime = FPlatformTime::Seconds();
    int32 LoadedCount = 0;
    
    for (int32 i = 0; i < 100; i++)
    {
        FString ItemId = FString::FromInt(i);
        InvSys->AsyncLoadItemIcon(ItemId, FOnIconLoaded::CreateLambda(
            [&LoadedCount](UTexture2D* Icon)
            {
                if (Icon) LoadedCount++;
            }
        ));
    }
    
    // Wait for all loads
    FPlatformProcess::Sleep(5.0f);
    
    double EndTime = FPlatformTime::Seconds();
    UE_LOG(LogTemp, Log, TEXT("Loaded %d/100 icons in %.2fs"), 
        LoadedCount, EndTime - StartTime);
}
```

## Best Practices

1. **Always use Soft References** for icons and meshes
2. **Provide Placeholder Icons** for smooth UX
3. **Batch Load** visible items only
4. **Cache Definitions** at subsystem level
5. **Localize** all display text
6. **Validate** data table entries
7. **Use HISM** for multiple instances
8. **Configure LODs** for world meshes
9. **Handle Missing** definitions gracefully
10. **Profile Performance** with large inventories

## Integration Checklist

- [ ] Create FEchoesItemDefinitionRow structure
- [ ] Create EEchoesItemCategory enum
- [ ] Update UEchoesInventorySubsystem
- [ ] Add async loading methods
- [ ] Update UEchoesInventoryItemObject
- [ ] Update UEchoesInventoryEntryWidget
- [ ] Create DT_ItemDefinitions data table
- [ ] Populate with item data
- [ ] Configure subsystem reference
- [ ] Create placeholder icons
- [ ] Test async loading
- [ ] Verify localization
- [ ] Profile performance

## Next Steps

1. **Populate Data Table** with all item types
2. **Create Icon Library** matching TypeIds
3. **Setup Localization** for multiple languages
4. **Optimize World Meshes** with LODs
5. **Implement HISM** for ejected items
6. **Add Physics Integration** for mass/volume
7. **Create Admin Tools** for data table management
8. **Performance Testing** with 1000+ items
