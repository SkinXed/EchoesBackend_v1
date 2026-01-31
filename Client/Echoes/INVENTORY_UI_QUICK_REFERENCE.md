# Inventory UI Quick Reference

## Class Reference

### UEchoesInventoryItemObject
**Purpose**: Data wrapper for ListView  
**File**: `UI/EchoesInventoryItemObject.h`

```cpp
// Create and initialize
UEchoesInventoryItemObject* Item = NewObject<UEchoesInventoryItemObject>();
Item->InitializeWithData(InventoryItemData);

// Getters
FString Name = Item->GetItemName();
int64 Qty = Item->GetQuantity();
FString Vol = Item->GetFormattedVolume();        // "120.5 m³"
FString TotalVol = Item->GetFormattedTotalVolume(); // "1,205.0 m³"
FGuid AssetId = Item->GetAssetId();
bool Stackable = Item->IsStackable();
```

### UEchoesInventoryEntryWidget
**Purpose**: List item display  
**File**: `UI/EchoesInventoryEntryWidget.h`

```cpp
// Required UMG widgets (must be named exactly):
ItemIcon       (UImage*)
ItemNameText   (UTextBlock*)
QuantityText   (UTextBlock*)
VolumeText     (UTextBlock*)

// Override in Blueprint:
Event UpdateDisplay (ItemObject)
Event OnEntrySelected
Event OnEntryDeselected
```

### UEchoesInventoryWidget
**Purpose**: Main inventory widget  
**File**: `UI/EchoesInventoryWidget.h`

```cpp
// Required UMG widget:
InventoryListView (UListView*)

// Common methods:
void RefreshInventory();
void SetTargetActor(AActor* Target);
UEchoesInventoryItemObject* GetSelectedItem();
void UI_RequestMoveItem(AActor* Target, int64 Quantity);

// Override in Blueprint:
Event OnInventoryRefreshed
Event OnItemSelected (ItemObject)
Event OnMoveRequestFailed (ErrorMessage)
```

## UMG Setup (Quick)

### Step 1: Entry Widget (WBP_InventoryEntry)
```
Parent Class: EchoesInventoryEntryWidget

Hierarchy:
Canvas Panel
└─ Horizontal Box
   ├─ Image "ItemIcon"
   ├─ Vertical Box
   │  ├─ TextBlock "ItemNameText"
   │  └─ TextBlock "QuantityText"
   └─ TextBlock "VolumeText"
```

### Step 2: Main Widget (WBP_Inventory)
```
Parent Class: EchoesInventoryWidget

Hierarchy:
Canvas Panel
└─ ListView "InventoryListView"
   Settings:
   - Entry Widget Class: WBP_InventoryEntry
   - Selection Mode: Single Select
```

## Code Examples

### Display Player Inventory
```cpp
// Auto-binds to pawn's component
UEchoesInventoryWidget* Widget = CreateWidget<UEchoesInventoryWidget>(PC, WidgetClass);
Widget->AddToViewport();
// Automatically finds component and refreshes
```

### Display Station Inventory
```cpp
Widget->SetTargetActor(StationActor);
// Automatically switches and refreshes
```

### Handle Selection
```cpp
// C++
UEchoesInventoryItemObject* Item = Widget->GetSelectedItem();
if (Item)
{
    FGuid AssetId = Item->GetAssetId();
    // Use asset ID
}

// Blueprint
Event OnItemSelected (ItemObject)
{
    ItemNameText->SetText(ItemObject->GetItemName());
}
```

### Move Items
```cpp
// Move selected item to target
Widget->UI_RequestMoveItem(TargetActor, 0);  // 0 = all

// Move partial quantity
Widget->UI_RequestMoveItem(TargetActor, 50); // Move 50 items
```

### Manual Refresh
```cpp
Widget->RefreshInventory();
```

## Event Flow

```
User Action → UI Widget → Component → Backend → Response → Component → UI Update

1. User clicks item
2. Widget: OnItemSelected fires
3. User clicks "Move"
4. Widget: UI_RequestMoveItem()
5. Component: ServerOnly_MoveItem()
6. Backend: POST /api/inventory/operations/move
7. Backend: Updates database
8. Backend: Returns success
9. Component: FetchItems() refreshes
10. Component: OnInventoryUpdated fires
11. Widget: PopulateInventoryList()
12. UI: ListView updates
```

## Common Tasks

### Customize Entry Appearance
```cpp
// In WBP_InventoryEntry Blueprint
Event UpdateDisplay
{
    // Load icon by type ID
    LoadIconTexture(ItemObject->GetTypeId());
    
    // Color by rarity
    if (IsRareItem(ItemObject))
        ItemNameText->SetColorAndOpacity(GoldColor);
}
```

### Add Filtering
```cpp
void FilterByType(int32 TypeId)
{
    TArray<UObject*> Items = ListView->GetListItems();
    TArray<UObject*> Filtered;
    
    for (UObject* Obj : Items)
    {
        UEchoesInventoryItemObject* Item = Cast<UEchoesInventoryItemObject>(Obj);
        if (Item && Item->GetTypeId() == TypeId)
            Filtered.Add(Item);
    }
    
    ListView->SetListItems(Filtered);
}
```

### Add Sorting
```cpp
void SortByVolume()
{
    TArray<UObject*> Items = ListView->GetListItems();
    Items.Sort([](const UObject& A, const UObject& B)
    {
        auto ItemA = Cast<UEchoesInventoryItemObject>(&A);
        auto ItemB = Cast<UEchoesInventoryItemObject>(&B);
        return ItemA->GetItemData().TotalVolume > ItemB->GetItemData().TotalVolume;
    });
    ListView->SetListItems(Items);
}
```

## Debugging

### Enable Logging
```cpp
// In code
UE_LOG(LogTemp, Log, TEXT("Inventory: %s"), *Message);

// In DefaultEngine.ini
[Core.Log]
LogTemp=Verbose
```

### Check Bindings
```cpp
if (!InventoryListView)
    UE_LOG(LogTemp, Error, TEXT("ListView not bound!"));

if (!InventoryComponent)
    UE_LOG(LogTemp, Error, TEXT("Component not found!"));
```

### Verify Widget Names
```
In UMG, widgets MUST be named:
- ItemIcon
- ItemNameText
- QuantityText
- VolumeText
- InventoryListView
```

## Performance Tips

1. **Event-Driven**: No NativeTick required
2. **ListView**: Virtualizes rendering automatically
3. **Async Icons**: Load icons asynchronously
4. **Batch Updates**: Use PopulateInventoryList for bulk updates
5. **Object Pooling**: ListView reuses entry widgets

## Common Errors

| Error | Solution |
|-------|----------|
| "Widget not bound" | Check widget name matches BindWidget |
| "No component found" | Ensure actor has UEchoesInventoryComponent |
| "Items not displaying" | Call RefreshInventory() or FetchItems() |
| "Selection not working" | Set ListView to Single Select mode |
| "Move failed" | Check distance validation |

## Architecture Summary

```
┌─────────────────────────────────────────┐
│ UEchoesInventoryWidget (Main)          │
│  - Manages ListView                     │
│  - Binds to component delegate          │
│  - Handles user actions                 │
└────────────────┬────────────────────────┘
                 │
                 │ Contains
                 ▼
┌─────────────────────────────────────────┐
│ UListView                               │
│  - Displays items                       │
│  - Manages selection                    │
│  - Virtualizes rendering                │
└────────────────┬────────────────────────┘
                 │
                 │ Uses
                 ▼
┌─────────────────────────────────────────┐
│ UEchoesInventoryItemObject (Data)      │
│  - Wraps FEchoesInventoryItem           │
│  - Provides formatted display           │
└────────────────┬────────────────────────┘
                 │
                 │ Displays in
                 ▼
┌─────────────────────────────────────────┐
│ UEchoesInventoryEntryWidget (Entry)    │
│  - IUserObjectListEntry interface       │
│  - Shows icon, name, quantity, volume   │
└─────────────────────────────────────────┘
```

## File Locations

```
Client/Echoes/Source/Echoes/UI/
├── EchoesInventoryItemObject.h/cpp
├── EchoesInventoryEntryWidget.h/cpp
└── EchoesInventoryWidget.h/cpp

Client/Echoes/
├── INVENTORY_UI_IMPLEMENTATION.md
├── INVENTORY_ENTRY_WIDGET_GUIDE.md
└── INVENTORY_UI_QUICK_REFERENCE.md
```

## Requirements Checklist

- [x] Data Wrapper (UEchoesInventoryItemObject)
- [x] Main Widget (UEchoesInventoryWidget)
  - [x] ListView member
  - [x] NativeConstruct binding
  - [x] OnInventoryUpdated subscription
  - [x] Populate list logic
- [x] Entry Widget (UEchoesInventoryEntryWidget)
  - [x] IUserObjectListEntry interface
  - [x] Icon/text display
  - [x] Volume formatting
- [x] Interactivity
  - [x] Selection support
  - [x] UI_RequestMoveItem stub
- [x] Event-Driven
  - [x] No NativeTick
  - [x] Delegate-based updates
- [x] Documentation
  - [x] Usage guide
  - [x] UMG setup
  - [x] Quick reference

## Next Steps

1. **Create Widget Blueprints** in Unreal Editor
2. **Test with Sample Data**
3. **Customize Appearance** (colors, fonts, animations)
4. **Add Icon Loading** (async texture loading)
5. **Implement Drag-Drop** (optional enhancement)
6. **Add Context Menu** (right-click actions)
7. **Add Filtering/Sorting** UI controls
8. **Performance Testing** with large inventories
