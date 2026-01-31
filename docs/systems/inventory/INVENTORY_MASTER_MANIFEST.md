# INVENTORY MASTER MANIFEST
## The Complete Guide to Echoes MMO Inventory System

**Version**: 1.0
**Date**: 2026-01-31
**Status**: Production Documentation

---

## Table of Contents

1. [System Architecture](#1-system-architecture)
2. [Data Flow: Database to Screen](#2-data-flow-database-to-screen)
3. [Window System Reference](#3-window-system-reference)
4. [Drag & Drop Protocol](#4-drag--drop-protocol)
5. [Item Definitions Guide](#5-item-definitions-guide)
6. [Jettison System](#6-jettison-system)
7. [Server Actions Reference](#7-server-actions-reference)
8. [Configuration Guide](#8-configuration-guide)
9. [Troubleshooting](#9-troubleshooting)
10. [API Quick Reference](#10-api-quick-reference)

---

## 1. System Architecture

### 1.1 High-Level Overview

```
┌──────────────────────────────────────────────────────────────────┐
│                         PRESENTATION LAYER                        │
│  ┌────────────────┐  ┌────────────────┐  ┌────────────────┐     │
│  │   W_Window     │  │  W_Inventory   │  │  W_ContextMenu │     │
│  │   (Blueprint)  │  │  (Blueprint)   │  │  (Blueprint)   │     │
│  └────────┬───────┘  └────────┬───────┘  └────────┬───────┘     │
│           │                   │                    │              │
└───────────┼───────────────────┼────────────────────┼──────────────┘
            │                   │                    │
┌───────────┼───────────────────┼────────────────────┼──────────────┐
│           │        UI FRAMEWORK LAYER              │              │
│  ┌────────▼───────┐  ┌────────▼───────┐  ┌────────▼───────┐     │
│  │ EchoesWindowBase│  │ EchoesInventory│  │ EchoesContext  │     │
│  │    (C++)       │  │   Widget (C++) │  │  Menu (C++)    │     │
│  └────────┬───────┘  └────────┬───────┘  └────────┬───────┘     │
│           │                   │                    │              │
└───────────┼───────────────────┼────────────────────┼──────────────┘
            │                   │                    │
┌───────────┼───────────────────┼────────────────────┼──────────────┐
│           │       COMPONENT LAYER                  │              │
│  ┌────────▼──────────────────────────────┐  ┌─────▼──────┐       │
│  │   UEchoesInventoryComponent (C++)     │  │  Subsystem │       │
│  │  • ServerOnly_MoveItem                │  │  (Cache)   │       │
│  │  • ServerOnly_JettisonItem            │◄─┤            │       │
│  │  • ServerOnly_StackAll                │  │            │       │
│  │  • FetchItems                         │  │            │       │
│  └────────┬──────────────────────────────┘  └────────────┘       │
│           │                                                        │
└───────────┼────────────────────────────────────────────────────────┘
            │ RPC / HTTP
┌───────────▼────────────────────────────────────────────────────────┐
│                         SERVER LAYER                               │
│  ┌──────────────────────────────────────────────────┐             │
│  │         ASP.NET Core Backend (C#)                 │             │
│  │  ┌─────────────────────────────────────────────┐ │             │
│  │  │          InventoryController                │ │             │
│  │  │  • GET /api/inventory/hangar/{id}          │ │             │
│  │  │  • POST /api/inventory/operations/move     │ │             │
│  │  │  • POST /api/inventory/jettison            │ │             │
│  │  │  • POST /api/inventory/stack-all           │ │             │
│  │  └─────────────────┬───────────────────────────┘ │             │
│  │                    │                             │             │
│  │  ┌─────────────────▼───────────────────────────┐ │             │
│  │  │          InventoryService                   │ │             │
│  │  │  • ValidateMove                             │ │             │
│  │  │  • ExecuteMove (Transaction)                │ │             │
│  │  │  • GetOrCreatePersonalHangar               │ │             │
│  │  │  • StackAllItems                            │ │             │
│  │  └─────────────────┬───────────────────────────┘ │             │
│  └────────────────────┼─────────────────────────────┘             │
│                       │                                            │
└───────────────────────┼────────────────────────────────────────────┘
                        │
┌───────────────────────▼────────────────────────────────────────────┐
│                      DATABASE LAYER                                │
│  ┌──────────────────────────────────────────────────┐             │
│  │      PostgreSQL / SQL Server                     │             │
│  │  ┌────────────┐  ┌──────────────┐  ┌──────────┐│             │
│  │  │   Assets   │  │  Containers  │  │Characters││             │
│  │  │            │  │              │  │          ││             │
│  │  │ • AssetId  │  │ • StorageId  │  │ • UserId ││             │
│  │  │ • TypeId   │  │ • OwnerId    │  │ • Name   ││             │
│  │  │ • Quantity │  │ • Capacity   │  │ • ShipId ││             │
│  │  │ • Location │  │ • Location   │  │          ││             │
│  │  └────────────┘  └──────────────┘  └──────────┘│             │
│  └──────────────────────────────────────────────────┘             │
└────────────────────────────────────────────────────────────────────┘
```

### 1.2 Component Responsibilities

**Presentation Layer** (Blueprint):
- Visual styling (colors, fonts, layouts)
- Animations and transitions
- Sound effects
- User feedback (tooltips, highlights)

**UI Framework Layer** (C++):
- Widget lifecycle management
- Input handling (mouse, keyboard)
- Layout calculations
- Event delegation

**Component Layer** (C++):
- Business logic
- Server communication
- Data caching
- Validation

**Server Layer** (C#):
- Authority and validation
- Database operations
- Transaction management
- Broadcasting updates

**Database Layer** (SQL):
- Persistent storage
- Query optimization
- Data integrity
- Backup and recovery

---

## 2. Data Flow: Database to Screen

### 2.1 Complete Journey of an Item

**Step 1: Database Query**
```sql
-- Backend executes query
SELECT 
    a.Id as AssetId,
    a.TypeId,
    t.Name as TypeName,
    a.Quantity,
    t.Volume,
    (a.Quantity * t.Volume) as TotalVolume,
    t.IsStackable
FROM Assets a
JOIN ItemTypes t ON a.TypeId = t.Id
WHERE a.ContainerId = @containerId
AND a.OwnerId = @userId
```

**Step 2: Backend Processing**
```csharp
// C# InventoryService
public async Task<ContainerItemsDto> GetContainerItems(Guid containerId, Guid userId)
{
    var assets = await _context.Assets
        .Where(a => a.ContainerId == containerId && a.OwnerId == userId)
        .Join(_context.ItemTypes, 
            a => a.TypeId, 
            t => t.Id,
            (a, t) => new AssetDto
            {
                AssetId = a.Id,
                TypeId = t.Id,
                TypeName = t.Name,
                Quantity = a.Quantity,
                Volume = t.Volume,
                TotalVolume = a.Quantity * t.Volume,
                IsStackable = t.IsStackable
            })
        .ToListAsync();
    
    return new ContainerItemsDto
    {
        Items = assets,
        TotalCount = assets.Count,
        TotalVolume = assets.Sum(a => a.TotalVolume)
    };
}
```

**Step 3: HTTP Response**
```json
{
    "items": [
        {
            "assetId": "3fa85f64-5717-4562-b3fc-2c963f66afa6",
            "typeId": 123,
            "typeName": "Tritanium Ore",
            "quantity": 1000,
            "volume": 0.01,
            "totalVolume": 10.0,
            "isStackable": true
        }
    ],
    "totalCount": 1,
    "totalVolume": 10.0
}
```

**Step 4: Client Reception (C++)**
```cpp
// UEchoesInventoryComponent::OnItemsFetchResponse
void UEchoesInventoryComponent::OnItemsFetchResponse(
    FHttpRequestPtr Request,
    FHttpResponsePtr Response,
    bool bWasSuccessful,
    FOnItemsFetched OnSuccess,
    FOnInventoryOperationFailure OnFailure)
{
    // Parse JSON response
    TSharedPtr<FJsonObject> JsonObject;
    TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());
    
    if (!FJsonSerializer::Deserialize(Reader, JsonObject))
    {
        OnFailure.ExecuteIfBound(TEXT("Failed to parse response"));
        return;
    }
    
    // Extract items array
    const TArray<TSharedPtr<FJsonValue>>* ItemsArray;
    if (JsonObject->TryGetArrayField(TEXT("items"), ItemsArray))
    {
        FEchoesContainerItems ContainerItems;
        
        for (const TSharedPtr<FJsonValue>& ItemValue : *ItemsArray)
        {
            TSharedPtr<FJsonObject> ItemObject = ItemValue->AsObject();
            
            FEchoesInventoryItem Item;
            Item.AssetId = FGuid();
            FGuid::Parse(ItemObject->GetStringField(TEXT("assetId")), Item.AssetId);
            Item.TypeId = ItemObject->GetIntegerField(TEXT("typeId"));
            Item.TypeName = ItemObject->GetStringField(TEXT("typeName"));
            Item.Quantity = ItemObject->GetNumberField(TEXT("quantity"));
            Item.Volume = ItemObject->GetNumberField(TEXT("volume"));
            Item.TotalVolume = ItemObject->GetNumberField(TEXT("totalVolume"));
            Item.IsStackable = ItemObject->GetBoolField(TEXT("isStackable"));
            
            ContainerItems.Items.Add(Item);
        }
        
        // Cache items
        CachedItems = ContainerItems;
        
        // Broadcast to UI
        OnInventoryUpdated.Broadcast(ContainerItems);
        OnSuccess.ExecuteIfBound(ContainerItems);
    }
}
```

**Step 5: UI Update (C++)**
```cpp
// UEchoesInventoryWidget::OnInventoryUpdated
void UEchoesInventoryWidget::OnInventoryUpdated(const FEchoesContainerItems& Items)
{
    PopulateInventoryList(Items);
    OnInventoryRefreshed(); // Blueprint event
}

void UEchoesInventoryWidget::PopulateInventoryList(const FEchoesContainerItems& Items)
{
    // Clear existing items
    InventoryListView->ClearListItems();
    
    // Create UObjects for ListView
    for (const FEchoesInventoryItem& Item : Items.Items)
    {
        UEchoesInventoryItemObject* ItemObject = NewObject<UEchoesInventoryItemObject>(this);
        ItemObject->InitializeWithData(Item);
        InventoryListView->AddItem(ItemObject);
    }
}
```

**Step 6: ListView Display (UE5)**
```
ListView creates entry widgets for each item:

For each UEchoesInventoryItemObject:
1. Spawn UEchoesInventoryEntryWidget
2. Call NativeOnListItemObjectSet()
3. Widget calls SetItemData()
4. Display item icon, name, quantity, volume
```

**Step 7: Screen Rendering**
```
Final display on screen:

┌────────────────────────────────────┐
│ Inventory - Cargo Hold             │
├────────────────────────────────────┤
│ [Icon] Tritanium Ore    x1000      │
│        10.0 m³                     │
└────────────────────────────────────┘
```

### 2.2 Data Flow Timing

**Typical Latency Breakdown**:
- Database query: 5-20ms
- JSON serialization: 1-5ms
- Network transfer: 20-100ms (depends on ping)
- JSON parsing: 1-5ms
- UI update: 5-10ms
- **Total**: 32-140ms

**Optimization Tips**:
1. Cache frequently accessed data
2. Use compression for large inventories
3. Batch multiple operations
4. Implement delta updates (only changed items)

---

## 3. Window System Reference

### 3.1 Snapping Parameters

**Screen Edge Snapping**:
```cpp
// Configuration
float SnapThreshold = 15.0f;  // Distance in pixels
bool bSnapToScreenEdges = true;

// How it works:
if (abs(WindowX - 0) < SnapThreshold)
{
    WindowX = 0;  // Snap to left edge
}
```

**Window-to-Window Snapping**:
```cpp
// Configuration
bool bSnapToOtherWindows = true;

// Algorithm:
for (UEchoesWindowBase* OtherWindow : GetOtherWindows())
{
    // Check left/right alignment
    if (abs(WindowX - (OtherWindow->X + OtherWindow->Width)) < SnapThreshold)
    {
        WindowX = OtherWindow->X + OtherWindow->Width;  // Snap to right edge
    }
    
    // Check top/bottom alignment
    if (abs(WindowY - OtherWindow->Y) < SnapThreshold)
    {
        WindowY = OtherWindow->Y;  // Snap to same top
    }
}
```

**Configuration Properties**:
```cpp
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Window")
bool bEnableSnapping = true;

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Window")
float SnapThreshold = 15.0f;

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Window")
bool bSnapToScreenEdges = true;

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Window")
bool bSnapToOtherWindows = true;
```

### 3.2 Position Persistence

**Save Location**:
```
GameUserSettings.ini
[Echoes.Windows]
W_Inventory.Position=250,150
W_Inventory.Size=800,600
W_StationMenu.Position=1050,150
W_StationMenu.Size=400,500
```

**Save Logic**:
```cpp
void UEchoesWindowBase::SaveWindowPosition()
{
    if (!bSavePosition)
        return;
    
    // Get position from viewport
    FVector2D Position = GetPositionInViewport();
    FVector2D Size = GetDesiredSize();
    
    // Save to config
    FString SectionName = FString::Printf(TEXT("Echoes.Windows.%s"), *WindowId);
    GConfig->SetString(*SectionName, TEXT("Position"), 
        *FString::Printf(TEXT("%.0f,%.0f"), Position.X, Position.Y), 
        GGameUserSettingsIni);
    GConfig->SetString(*SectionName, TEXT("Size"), 
        *FString::Printf(TEXT("%.0f,%.0f"), Size.X, Size.Y), 
        GGameUserSettingsIni);
    GConfig->Flush(false, GGameUserSettingsIni);
}
```

**Load Logic**:
```cpp
void UEchoesWindowBase::LoadWindowPosition()
{
    if (!bSavePosition)
        return;
    
    // Load from config
    FString SectionName = FString::Printf(TEXT("Echoes.Windows.%s"), *WindowId);
    FString PositionStr, SizeStr;
    
    if (GConfig->GetString(*SectionName, TEXT("Position"), PositionStr, GGameUserSettingsIni))
    {
        // Parse "X,Y"
        FString X, Y;
        if (PositionStr.Split(TEXT(","), &X, &Y))
        {
            FVector2D LoadedPosition(FCString::Atof(*X), FCString::Atof(*Y));
            SetPositionInViewport(LoadedPosition);
        }
    }
}
```

### 3.3 Z-Order Management

**Focus System**:
```cpp
void UEchoesWindowBase::BringToFront()
{
    // Get parent canvas
    UCanvasPanel* Canvas = Cast<UCanvasPanel>(GetParent());
    if (!Canvas)
        return;
    
    // Find highest Z-order
    int32 MaxZOrder = 0;
    for (UWidget* Child : Canvas->GetAllChildren())
    {
        UCanvasPanelSlot* Slot = Cast<UCanvasPanelSlot>(Child->Slot);
        if (Slot)
        {
            MaxZOrder = FMath::Max(MaxZOrder, Slot->GetZOrder());
        }
    }
    
    // Set this window to highest + 1
    UCanvasPanelSlot* MySlot = Cast<UCanvasPanelSlot>(Slot);
    if (MySlot)
    {
        MySlot->SetZOrder(MaxZOrder + 1);
    }
}
```

**Trigger**:
```cpp
FReply UEchoesWindowBase::NativeOnMouseButtonDown(...)
{
    BringToFront();  // Focus on click
    return Super::NativeOnMouseButtonDown(...);
}
```

---

## 4. Drag & Drop Protocol

### 4.1 Normal Drag (No Shift)

**Step-by-Step**:

1. **Mouse Down**:
```cpp
FReply UEchoesInventoryEntryWidget::NativeOnMouseButtonDown(...)
{
    if (InMouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton))
    {
        // Detect drag if pressed
        return Reply.DetectDrag(TakeWidget(), EKeys::LeftMouseButton);
    }
}
```

2. **Drag Detected**:
```cpp
void UEchoesInventoryEntryWidget::NativeOnDragDetected(...)
{
    // Create drag operation
    UEchoesInventoryDragDrop* DragDropOp = NewObject<UEchoesInventoryDragDrop>();
    DragDropOp->InitializeDragOperation(
        CurrentItemObject->GetItemData(),
        SourceStorageId,
        SourceActor,
        TotalQuantity  // Full quantity
    );
    
    // Set visual
    DragDropOp->DefaultDragVisual = CreateDragVisual();
    
    // Return operation
    OutOperation = DragDropOp;
}
```

3. **Drag Over Target**:
```
Visual feedback (Blueprint):
- Green border = valid drop
- Red border = invalid drop
```

4. **Mouse Released (Drop)**:
```cpp
bool UEchoesInventoryWidget::NativeOnDrop(...)
{
    // Cast operation
    UEchoesInventoryDragDrop* DragDropOp = Cast<UEchoesInventoryDragDrop>(InOperation);
    
    // Extract data
    FEchoesInventoryItem ItemData = DragDropOp->GetItemData();
    FGuid SourceStorageId = DragDropOp->GetSourceStorageId();
    int64 Quantity = DragDropOp->GetQuantity();
    
    // Execute move
    SourceComponent->ServerOnly_MoveItem(
        ItemData.AssetId,
        TargetActor,
        SourceActor,
        Quantity,
        OnSuccess,
        OnFailure
    );
    
    return true;
}
```

5. **Server Processing**:
```csharp
// Backend validates and executes
[HttpPost("operations/move")]
public async Task<IActionResult> MoveItem([FromBody] MoveItemRequest request)
{
    // Validate distance, capacity, ownership
    // Execute database transaction
    // Broadcast updates
    return Ok();
}
```

6. **Client Update**:
```cpp
// OnInventoryUpdated delegate fires
// Both source and target inventories refresh automatically
```

### 4.2 Stack Split (Shift+Drag)

**Enhanced Flow**:

1. **Mouse Down with Shift**:
```cpp
FReply UEchoesInventoryEntryWidget::NativeOnMouseButtonDown(...)
{
    bool bIsShiftHeld = InMouseEvent.IsShiftDown();
    // Continue to drag detection...
}
```

2. **Drag Detected with Shift**:
```cpp
void UEchoesInventoryEntryWidget::NativeOnDragDetected(...)
{
    bool bIsShiftHeld = InMouseEvent.IsShiftDown();
    
    if (bIsShiftHeld && bIsStackable && TotalQuantity > 1)
    {
        // Show quantity selector
        UEchoesQuantitySelectorWidget* Selector = CreateWidget<...>();
        Selector->InitializeSelector(TotalQuantity, ItemName);
        
        // Bind delegates
        Selector->OnQuantitySelected.AddDynamic(this, &...::OnDragQuantitySelected);
        
        // Add to viewport (modal)
        Selector->AddToViewport(1000);
        
        // Store pending drag data
        bWaitingForDragQuantity = true;
        return;  // Don't create drag operation yet
    }
}
```

3. **User Selects Quantity**:
```
Quantity Selector Modal:
- User adjusts slider: 1 to 1000
- Or types in input: "500"
- Or clicks "Max" button
- Presses Enter or clicks Confirm
```

4. **Create Drag with Quantity**:
```cpp
void UEchoesInventoryEntryWidget::OnDragQuantitySelected(int64 SelectedQuantity)
{
    // Create drag operation with selected quantity
    CreateDragOperationWithQuantity(
        PendingDragGeometry,
        PendingDragEvent,
        OutOperation,
        SelectedQuantity  // User-selected amount
    );
}
```

5. **Continue Normal Drag Flow**:
```
Same as normal drag, but with SelectedQuantity instead of TotalQuantity
```

### 4.3 Drag Operation Data

**UEchoesInventoryDragDrop Contents**:
```cpp
class UEchoesInventoryDragDrop
{
    FEchoesInventoryItem ItemData;  // Item being moved
    FGuid SourceStorageId;          // Where it came from
    AActor* SourceActor;            // Actor containing source
    int64 Quantity;                 // Amount to move
    
    // Visual feedback
    UUserWidget* DefaultDragVisual;
    EDragPivot::Type Pivot;
};
```

**Validation Chain**:
1. Client: Basic checks (IsStackable, Quantity > 0)
2. Server: Authority check (HasAuthority())
3. Server: Authentication (JWT token)
4. Server: Distance check (< MaxTransferDistance)
5. Server: Capacity check (Target has space)
6. Server: Ownership check (Has access to source)
7. Server: Database transaction (Atomic operation)

---

## 5. Item Definitions Guide

### 5.1 Item Definitions Table Structure

**Database Schema**:
```sql
CREATE TABLE ItemTypes (
    Id INT PRIMARY KEY IDENTITY(1,1),
    Name NVARCHAR(100) NOT NULL,
    Description NVARCHAR(500),
    Category NVARCHAR(50),
    Volume FLOAT NOT NULL DEFAULT 1.0,
    Mass FLOAT NOT NULL DEFAULT 1.0,
    MaxStack INT NOT NULL DEFAULT 999999,
    IsStackable BIT NOT NULL DEFAULT 1,
    IconPath NVARCHAR(255),
    MeshPath NVARCHAR(255),
    Rarity INT NOT NULL DEFAULT 0,
    BaseValue DECIMAL(18,2) DEFAULT 0,
    CreatedAt DATETIME2 DEFAULT GETUTCDATE()
);
```

**Example Data**:
```sql
INSERT INTO ItemTypes (Name, Description, Category, Volume, Mass, MaxStack, IsStackable, IconPath, MeshPath, Rarity, BaseValue)
VALUES 
('Tritanium Ore', 'Common asteroid ore, used in basic construction', 'Ore', 0.01, 0.1, 1000000, 1, '/Game/Icons/Items/Ore_Tritanium', '/Game/Meshes/Items/Ore_Tritanium', 0, 2.50),
('Isogen', 'Valuable ore with unique properties', 'Ore', 0.02, 0.15, 100000, 1, '/Game/Icons/Items/Ore_Isogen', '/Game/Meshes/Items/Ore_Isogen', 2, 50.00),
('Plasma Thruster', 'High-efficiency propulsion module', 'Module', 5.0, 500.0, 1, 0, '/Game/Icons/Items/Module_Thruster', '/Game/Meshes/Items/Module_Thruster', 3, 15000.00);
```

### 5.2 UE5 Item Definitions Data Table

**Create Data Table**:

1. In Content Browser: Right-click → Miscellaneous → Data Table
2. Choose Row Structure: `FEchoesItemDefinitionRow`
3. Name: `DT_ItemDefinitions`

**Data Table Structure** (C++):
```cpp
// EchoesItemDefinitions.h
USTRUCT(BlueprintType)
struct FEchoesItemDefinitionRow : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    int32 TypeId = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    FText DisplayName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    FText Description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    FText Category;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    float UnitVolume = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    float UnitMass = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    int64 MaxStack = 999999;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    bool bIsStackable = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    TSoftObjectPtr<UTexture2D> Icon;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    TSoftObjectPtr<UStaticMesh> Mesh;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    int32 Rarity = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    float BaseValue = 0.0f;
};
```

### 5.3 Asset Organization

**Recommended Folder Structure**:
```
Content/
├─ Items/
│  ├─ Icons/
│  │  ├─ Ore/
│  │  │  ├─ T_Tritanium_Icon.uasset
│  │  │  └─ T_Isogen_Icon.uasset
│  │  ├─ Modules/
│  │  │  └─ T_Thruster_Icon.uasset
│  │  └─ Equipment/
│  ├─ Meshes/
│  │  ├─ Ore/
│  │  │  ├─ SM_Tritanium.uasset
│  │  │  └─ SM_Isogen.uasset
│  │  └─ Modules/
│  │     └─ SM_Thruster.uasset
│  └─ DataTables/
│     └─ DT_ItemDefinitions.uasset
```

### 5.4 Icon Requirements

**Technical Specifications**:
- **Size**: 128x128 or 256x256 pixels
- **Format**: PNG with alpha channel
- **Color Space**: sRGB
- **Compression**: BC7 (recommended)
- **Mip Maps**: Yes

**Style Guide**:
- Clean, recognizable silhouette
- Consistent lighting direction (top-left)
- Subtle drop shadow
- Color-coded by rarity:
  - Common: Gray/White
  - Uncommon: Green
  - Rare: Blue
  - Epic: Purple
  - Legendary: Orange/Gold

### 5.5 Mesh Requirements

**Technical Specifications**:
- **Poly Count**: 500-2000 triangles (LOD0)
- **Materials**: PBR materials (Albedo, Normal, Roughness, Metallic)
- **Pivot Point**: Center of mass
- **Scale**: Real-world scale (meters)
- **Collision**: Simple collision mesh (UCX_)

**LOD Setup**:
- LOD0: Full detail (2000 tris)
- LOD1: Medium detail (1000 tris)
- LOD2: Low detail (500 tris)
- LOD3: Very low detail (100 tris)

### 5.6 Populating Data Table

**In Unreal Editor**:

1. Open `DT_ItemDefinitions`
2. Click "Add" to create new row
3. Set Row Name: `Item_123` (matches TypeId)
4. Fill in properties:
   - TypeId: 123
   - DisplayName: "Tritanium Ore"
   - Description: "Common asteroid ore..."
   - Category: "Ore"
   - UnitVolume: 0.01
   - Icon: Select from Content Browser
   - Mesh: Select from Content Browser
5. Save Data Table

**Bulk Import** (CSV):
```csv
Name,TypeId,DisplayName,Description,Category,UnitVolume,UnitMass,MaxStack,bIsStackable,Rarity,BaseValue
Item_123,123,"Tritanium Ore","Common ore",Ore,0.01,0.1,1000000,true,0,2.50
Item_124,124,"Isogen","Valuable ore",Ore,0.02,0.15,100000,true,2,50.00
```

Import: Data Table → Reimport → Select CSV

---

## 6. Jettison System

### 6.1 Overview

**Jettison** = Drop item from inventory into space

**Key Components**:
1. Client initiates jettison (context menu or keybind)
2. Server validates and removes from inventory
3. Server spawns `AEchoesItemActor` in space
4. Item actor has lifetime and can be picked up

### 6.2 Client-Side Flow

**Trigger Jettison**:
```cpp
// From context menu
Component->ServerOnly_JettisonItem(
    AssetId,
    Quantity,  // 0 = all, or specific amount
    OnSuccess,
    OnFailure
);
```

**Quantity Selection**:
```cpp
// If quantity > 1, show quantity selector
if (CurrentItemObject->IsStackable() && CurrentItemObject->GetQuantity() > 1)
{
    // Show W_QuantitySelector
    // User selects amount
    // Then call ServerOnly_JettisonItem with selected quantity
}
```

### 6.3 Server-Side Processing

**ServerOnly_JettisonItem**:
```cpp
void UEchoesInventoryComponent::ServerOnly_JettisonItem(
    const FGuid& AssetId,
    int64 Quantity,
    FOnItemMoveSuccess OnSuccess,
    FOnInventoryOperationFailure OnFailure)
{
    // 1. Validate authority
    if (GetWorld()->GetNetMode() == NM_Client)
    {
        OnFailure.ExecuteIfBound(TEXT("Server only"));
        return;
    }
    
    // 2. Validate authentication
    FString Token = GetAuthToken();
    if (Token.IsEmpty())
    {
        OnFailure.ExecuteIfBound(TEXT("Authentication required"));
        return;
    }
    
    // 3. Send HTTP request to backend
    FString Url = FString::Printf(TEXT("%s/api/inventory/jettison"), *GetApiBaseUrl());
    
    // Request payload
    {
        "assetId": "guid",
        "quantity": 100
    }
    
    // 4. Backend processes and responds
    // 5. On success, OnSuccess callback fires
    // 6. On failure, OnFailure callback fires
}
```

### 6.4 Backend Processing

**JettisonController**:
```csharp
[HttpPost("jettison")]
[Authorize]
public async Task<IActionResult> JettisonItem([FromBody] JettisonRequest request)
{
    var userId = GetAuthenticatedUserId();
    
    // 1. Find asset
    var asset = await _context.Assets
        .Where(a => a.Id == request.AssetId && a.OwnerId == userId)
        .FirstOrDefaultAsync();
    
    if (asset == null)
        return NotFound("Asset not found");
    
    // 2. Get player ship location
    var character = await _context.Characters
        .Include(c => c.Ship)
        .Where(c => c.UserId == userId)
        .FirstOrDefaultAsync();
    
    if (character?.Ship == null)
        return BadRequest("No active ship");
    
    // 3. Calculate spawn location (near ship)
    var spawnLocation = new Vector3
    {
        X = character.Ship.LocationX + 100,  // 100m away
        Y = character.Ship.LocationY,
        Z = character.Ship.LocationZ
    };
    
    // 4. Execute transaction
    using (var transaction = await _context.Database.BeginTransactionAsync())
    {
        try
        {
            // Remove from inventory (or reduce quantity)
            if (request.Quantity == 0 || request.Quantity >= asset.Quantity)
            {
                _context.Assets.Remove(asset);
            }
            else
            {
                asset.Quantity -= request.Quantity;
            }
            
            // Create item actor in world
            var itemActor = new ItemActor
            {
                Id = Guid.NewGuid(),
                TypeId = asset.TypeId,
                Quantity = request.Quantity > 0 ? request.Quantity : asset.Quantity,
                LocationX = spawnLocation.X,
                LocationY = spawnLocation.Y,
                LocationZ = spawnLocation.Z,
                SpawnedAt = DateTime.UtcNow,
                ExpiresAt = DateTime.UtcNow.AddHours(1)  // 1 hour lifetime
            };
            
            _context.ItemActors.Add(itemActor);
            
            await _context.SaveChangesAsync();
            await transaction.CommitAsync();
            
            // 5. Broadcast to nearby players
            await _hubContext.Clients.Group(character.Ship.SectorId.ToString())
                .SendAsync("ItemSpawned", itemActor);
            
            return Ok(new { success = true, itemActor });
        }
        catch (Exception ex)
        {
            await transaction.RollbackAsync();
            return StatusCode(500, "Failed to jettison item");
        }
    }
}
```

### 6.5 AEchoesItemActor (World Actor)

**Class Definition**:
```cpp
// AEchoesItemActor.h
UCLASS()
class ECHOES_API AEchoesItemActor : public AActor
{
    GENERATED_BODY()

public:
    UPROPERTY(Replicated, BlueprintReadOnly, Category = "Item")
    FGuid InstanceId;

    UPROPERTY(Replicated, BlueprintReadOnly, Category = "Item")
    int32 TypeId;

    UPROPERTY(Replicated, BlueprintReadOnly, Category = "Item")
    int64 Quantity;

    UPROPERTY(Replicated, BlueprintReadOnly, Category = "Item")
    FDateTime SpawnedAt;

    UPROPERTY(Replicated, BlueprintReadOnly, Category = "Item")
    FDateTime ExpiresAt;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item")
    UStaticMeshComponent* MeshComponent;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item")
    USphereComponent* InteractionSphere;

    // Pickup functionality
    UFUNCTION(BlueprintCallable, Category = "Item")
    bool CanPickup(APlayerController* Player);

    UFUNCTION(Server, Reliable, WithValidation, Category = "Item")
    void ServerPickup(APlayerController* Player);

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;
    
    void CheckExpiration();
    void UpdateMesh();
};
```

**Lifetime Management**:
```cpp
void AEchoesItemActor::CheckExpiration()
{
    FDateTime Now = FDateTime::UtcNow();
    if (Now >= ExpiresAt)
    {
        // Item expired, destroy
        Destroy();
    }
}
```

**Pickup**:
```cpp
bool AEchoesItemActor::CanPickup(APlayerController* Player)
{
    // Check distance
    float Distance = FVector::Dist(GetActorLocation(), Player->GetPawn()->GetActorLocation());
    if (Distance > MaxPickupDistance)
        return false;
    
    // Check inventory space
    UEchoesInventoryComponent* Inventory = Player->GetPawn()->FindComponentByClass<UEchoesInventoryComponent>();
    if (!Inventory)
        return false;
    
    // Calculate volume needed
    float VolumeNeeded = GetItemVolume() * Quantity;
    if (!Inventory->CanFitItem(VolumeNeeded))
        return false;
    
    return true;
}

void AEchoesItemActor::ServerPickup_Implementation(APlayerController* Player)
{
    if (!CanPickup(Player))
        return;
    
    // Add to player inventory
    UEchoesInventoryComponent* Inventory = Player->GetPawn()->FindComponentByClass<UEchoesInventoryComponent>();
    
    // Call backend to add item
    // On success, destroy this actor
    Destroy();
}
```

### 6.6 Configuration

**Item Actor Settings**:
```cpp
// DefaultItemLifetime (in seconds)
constexpr float DefaultItemLifetime = 3600.0f;  // 1 hour

// MaxPickupDistance (in cm)
constexpr float MaxPickupDistance = 50000.0f;  // 500 meters

// JettisonDistance (how far from ship)
constexpr float JettisonDistance = 10000.0f;  // 100 meters
```

---

## 7. Server Actions Reference

### 7.1 ServerOnly_MoveItem

**Purpose**: Move item between containers

**Signature**:
```cpp
void ServerOnly_MoveItem(
    const FGuid& AssetId,
    AActor* TargetActor,
    AActor* SourceActor,
    int64 Quantity,
    FOnItemMoveSuccess OnSuccess,
    FOnInventoryOperationFailure OnFailure
);
```

**Validation**:
- ✅ Authority check (server only)
- ✅ Authentication (JWT token)
- ✅ AssetId valid
- ✅ Target/Source actors valid
- ✅ Distance check (< MaxTransferDistance)
- ⚠️ Capacity check (recommended, not enforced)

**Backend Endpoint**: `POST /api/inventory/operations/move`

**Request**:
```json
{
    "assetId": "guid",
    "targetLocationId": "guid",
    "targetFlag": 0,
    "splitQuantity": 100
}
```

**Response**:
```json
{
    "success": true
}
```

### 7.2 ServerOnly_JettisonItem

**Purpose**: Drop item into space

**Signature**:
```cpp
void ServerOnly_JettisonItem(
    const FGuid& AssetId,
    int64 Quantity,
    FOnItemMoveSuccess OnSuccess,
    FOnInventoryOperationFailure OnFailure
);
```

**Validation**:
- ✅ Authority check (server only)
- ✅ Authentication (JWT token)
- ✅ AssetId valid
- ✅ Quantity valid (0 = all)

**Backend Endpoint**: `POST /api/inventory/jettison` ⏳ Pending

**Request**:
```json
{
    "assetId": "guid",
    "quantity": 100
}
```

**Response**:
```json
{
    "success": true,
    "itemActor": {
        "id": "guid",
        "typeId": 123,
        "quantity": 100,
        "location": { "x": 1000, "y": 2000, "z": 3000 }
    }
}
```

### 7.3 ServerOnly_StackAll

**Purpose**: Combine all stacks of same type

**Signature**:
```cpp
void ServerOnly_StackAll(
    int32 TypeId,
    FOnItemMoveSuccess OnSuccess,
    FOnInventoryOperationFailure OnFailure
);
```

**Validation**:
- ✅ Authority check (server only)
- ✅ Authentication (JWT token)
- ✅ StorageId valid
- ✅ TypeId valid (0 = all types)

**Backend Endpoint**: `POST /api/inventory/stack-all` ⏳ Pending

**Request**:
```json
{
    "storageId": "guid",
    "typeId": 123
}
```

**Response**:
```json
{
    "success": true,
    "itemsAffected": 5,
    "stacksCreated": 1,
    "totalQuantity": 5000
}
```

---

## 8. Configuration Guide

### 8.1 Component Configuration

**UEchoesInventoryComponent**:
```cpp
// In Blueprint or C++
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
FGuid StorageId;  // Link to database Container

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
float Capacity = 0.0f;  // 0 = unlimited

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
float MaxTransferDistance = 250000.0f;  // 2500 meters
```

### 8.2 Window Configuration

**UEchoesWindowBase**:
```cpp
// Snapping
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Window")
bool bEnableSnapping = true;

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Window")
float SnapThreshold = 15.0f;

// Size Constraints
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Window")
FVector2D MinSize = FVector2D(300, 200);

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Window")
FVector2D MaxSize = FVector2D(1920, 1080);

// Persistence
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Window")
bool bSavePosition = true;

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Window")
FString WindowId = TEXT("DefaultWindow");
```

### 8.3 Game Settings

**DefaultGame.ini**:
```ini
[/Script/Echoes.EchoesGameSettings]
ApiBaseUrl=http://localhost:5116
MaxTransferDistance=250000.0
DefaultItemLifetime=3600.0
MaxPickupDistance=50000.0
```

---

## 9. Troubleshooting

### 9.1 Common Issues

**Issue**: Items don't appear in inventory
**Solutions**:
1. Check StorageId is valid
2. Verify backend endpoint is accessible
3. Check JWT token is valid
4. Look for errors in Output Log
5. Verify items exist in database

**Issue**: Drag & drop doesn't work
**Solutions**:
1. Check entry widget has mouse input enabled
2. Verify DetectDragIfPressed is called
3. Check drag operation is created
4. Verify drop target has NativeOnDrop implemented
5. Check for null pointer errors

**Issue**: Window won't close
**Solutions**:
1. Check RemoveFromParent() is called
2. Verify delegates are unbound in NativeDestruct
3. Check for circular references
4. Look for exceptions in log

**Issue**: Context menu appears off-screen
**Solutions**:
1. Check CalculateSmartPosition logic
2. Verify viewport size calculation
3. Test at different resolutions
4. Check menu size estimation

### 9.2 Debug Commands

**Console Commands** (add to game):
```cpp
// Show inventory debug info
UFUNCTION(Exec)
void ShowInventoryDebug();

// Force refresh inventory
UFUNCTION(Exec)
void ForceRefreshInventory();

// Clear window positions
UFUNCTION(Exec)
void ClearWindowPositions();

// Toggle snapping
UFUNCTION(Exec)
void ToggleWindowSnapping();
```

---

## 10. API Quick Reference

### 10.1 Client C++ API

**UEchoesInventoryComponent**:
```cpp
// Fetch items
void FetchItems(FOnItemsFetched OnSuccess, FOnInventoryOperationFailure OnFailure);

// Move item
void ServerOnly_MoveItem(FGuid AssetId, AActor* Target, AActor* Source, int64 Qty, ...);

// Jettison item
void ServerOnly_JettisonItem(FGuid AssetId, int64 Qty, ...);

// Stack all
void ServerOnly_StackAll(int32 TypeId, ...);

// Helpers
float GetAvailableVolume() const;
bool CanFitItem(float Volume) const;
```

**UEchoesWindowBase**:
```cpp
// Window control
void CloseWindow();
void BringToFront();

// Position
void SaveWindowPosition();
void LoadWindowPosition();
FVector2D CalculateSmartPosition(...);
```

**UEchoesInventoryWidget**:
```cpp
// Display
void RefreshInventory();
void SetTargetActor(AActor* Actor);

// Selection
UEchoesInventoryItemObject* GetSelectedItem() const;

// Move
void UI_RequestMoveItem(AActor* Target, int64 Qty);
```

### 10.2 Backend C# API

**InventoryController**:
```csharp
// Get hangar
[HttpGet("hangar/{stationId}")]
Task<ActionResult<StorageIdResponse>> GetPersonalHangar(int stationId);

// Move item
[HttpPost("operations/move")]
Task<IActionResult> MoveItem([FromBody] MoveItemRequest request);

// Jettison (pending)
[HttpPost("jettison")]
Task<IActionResult> JettisonItem([FromBody] JettisonRequest request);

// Stack all (pending)
[HttpPost("stack-all")]
Task<IActionResult> StackAll([FromBody] StackAllRequest request);
```

**CharacterController**:
```csharp
// Undock
[HttpPost("undock")]
Task<IActionResult> Undock();
```

---

## 11. Version History

**v1.0** (2026-01-31)
- Initial release
- Complete inventory system
- Window framework
- Drag & drop
- Context menus
- Quantity selector
- Server validation
- Comprehensive documentation

---

*End of Inventory Master Manifest*
