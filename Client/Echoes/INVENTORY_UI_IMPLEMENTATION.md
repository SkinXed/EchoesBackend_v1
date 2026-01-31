# Inventory UI System (ListView) Implementation

## Overview

This document describes the Inventory UI system for Echoes MMO, implemented using UMG ListView for efficient item display and management.

## Architecture

### Component Hierarchy

```
UEchoesInventoryWidget (Main Widget)
    └── UListView (InventoryListView)
        └── UEchoesInventoryEntryWidget (Entry Widget) [Multiple instances]
            ├── UImage (ItemIcon)
            ├── UTextBlock (ItemNameText)
            ├── UTextBlock (QuantityText)
            └── UTextBlock (VolumeText)
```

### Data Flow

```
UEchoesInventoryComponent → OnInventoryUpdated (Delegate)
    ↓
UEchoesInventoryWidget → PopulateInventoryList()
    ↓
FEchoesInventoryItem → UEchoesInventoryItemObject (Wrapper)
    ↓
UListView → AddItem()
    ↓
UEchoesInventoryEntryWidget → SetItemData()
    ↓
Display (Icon, Name, Quantity, Volume)
```

## Classes

### 1. UEchoesInventoryItemObject

**Purpose**: Data wrapper for ListView compatibility

**Location**: `UI/EchoesInventoryItemObject.h/cpp`

**Key Features**:
- Wraps `FEchoesInventoryItem` struct as UObject
- Provides getter methods for UI display
- Formats volume with thousand separators (e.g., "1,205.0 m³")

**Usage**:
```cpp
UEchoesInventoryItemObject* ItemObject = NewObject<UEchoesInventoryItemObject>();
ItemObject->InitializeWithData(InventoryItemData);
ListView->AddItem(ItemObject);
```

### 2. UEchoesInventoryEntryWidget

**Purpose**: Individual list item display widget

**Location**: `UI/EchoesInventoryEntryWidget.h/cpp`

**Key Features**:
- Implements `IUserObjectListEntry` interface
- Auto-binds to widget components via `meta = (BindWidget)`
- Supports Blueprint customization via `UpdateDisplay` event
- Handles selection state

**Required UMG Components**:
- `ItemIcon` (UImage) - Item icon display
- `ItemNameText` (UTextBlock) - Item name
- `QuantityText` (UTextBlock) - Quantity (e.g., "x5")
- `VolumeText` (UTextBlock) - Total volume (e.g., "1,205.0 m³")

**Blueprint Events**:
- `OnEntrySelected` - Called when entry is selected
- `OnEntryDeselected` - Called when entry is deselected
- `UpdateDisplay` - Override for custom display logic

### 3. UEchoesInventoryWidget

**Purpose**: Main inventory management widget

**Location**: `UI/EchoesInventoryWidget.h/cpp`

**Key Features**:
- Event-driven updates (no NativeTick)
- Auto-binding to inventory component
- Selection management
- Move request functionality
- Support for viewing other actors' inventories

**Required UMG Components**:
- `InventoryListView` (UListView) - Main list display

**Blueprint Events**:
- `OnInventoryRefreshed` - Called after list is populated
- `OnItemSelected` - Called when item is selected
- `OnMoveRequestFailed` - Called when move fails

## UMG Setup Guide

### Step 1: Create Entry Widget Blueprint

1. Create new Widget Blueprint: `WBP_InventoryEntry`
2. Set Parent Class to `EchoesInventoryEntryWidget`
3. Add required components:
   ```
   Canvas Panel
   ├── Horizontal Box
   │   ├── Image (Name: "ItemIcon", Size: 64x64)
   │   ├── Vertical Box
   │   │   ├── TextBlock (Name: "ItemNameText")
   │   │   └── TextBlock (Name: "QuantityText")
   │   └── TextBlock (Name: "VolumeText")
   ```
4. Style as desired (colors, fonts, spacing)
5. Compile and save

### Step 2: Create Main Inventory Widget Blueprint

1. Create new Widget Blueprint: `WBP_Inventory`
2. Set Parent Class to `EchoesInventoryWidget`
3. Add ListView component:
   ```
   Canvas Panel
   └── ListView (Name: "InventoryListView")
       Settings:
       - Entry Widget Class: WBP_InventoryEntry
       - Selection Mode: Single Select
   ```
4. Optional: Add header, footer, scrollbar styling
5. Compile and save

### Step 3: Add to Game UI

```cpp
// In PlayerController or HUD class
void AMyPlayerController::ShowInventory()
{
    if (!InventoryWidgetClass)
        return;

    UEchoesInventoryWidget* InventoryWidget = CreateWidget<UEchoesInventoryWidget>(this, InventoryWidgetClass);
    if (InventoryWidget)
    {
        InventoryWidget->AddToViewport();
        // Widget will auto-find and bind to pawn's inventory component
    }
}
```

## Usage Examples

### Basic Inventory Display

```cpp
// Widget auto-binds to owner's pawn inventory
void UMyWidget::NativeConstruct()
{
    Super::NativeConstruct();
    // InventoryWidget automatically finds and binds to UEchoesInventoryComponent
    // Auto-refreshes if bAutoRefreshOnConstruct = true
}
```

### View Another Actor's Inventory

```cpp
// View station inventory
void UMyWidget::ShowStationInventory(AStation* Station)
{
    if (InventoryWidget && Station)
    {
        InventoryWidget->SetTargetActor(Station);
        // Automatically refreshes with station's inventory
    }
}
```

### Handle Item Selection

```cpp
// In Blueprint, override OnItemSelected event
void UMyWidget::OnItemSelected_Implementation(UEchoesInventoryItemObject* ItemObject)
{
    if (ItemObject)
    {
        // Display item details
        FString ItemInfo = FString::Printf(
            TEXT("Selected: %s\nQuantity: %d\nVolume: %s"),
            *ItemObject->GetItemName(),
            ItemObject->GetQuantity(),
            *ItemObject->GetFormattedTotalVolume()
        );
        
        // Show in details panel or tooltip
        ShowItemDetails(ItemInfo);
    }
}
```

### Move Items Between Containers

```cpp
// Move selected item to target container
void UMyWidget::OnMoveButtonClicked()
{
    if (InventoryWidget && TargetContainerActor)
    {
        // Move entire stack
        InventoryWidget->UI_RequestMoveItem(TargetContainerActor, 0);
        
        // Or move partial quantity
        // InventoryWidget->UI_RequestMoveItem(TargetContainerActor, 50);
    }
}
```

### Manual Refresh

```cpp
// Force refresh inventory display
void UMyWidget::RefreshButtonClicked()
{
    if (InventoryWidget)
    {
        InventoryWidget->RefreshInventory();
    }
}
```

## Event-Driven Architecture

The system is fully event-driven for optimal performance:

### No NativeTick Required

The widget does not use `NativeTick()`. All updates are triggered by:
1. `OnInventoryUpdated` delegate from component
2. User interactions (selection, buttons)
3. Explicit `RefreshInventory()` calls

### Delegate Binding

```cpp
// In NativeConstruct
InventoryComponent->OnInventoryUpdated.AddDynamic(this, &UEchoesInventoryWidget::OnInventoryUpdated);

// In NativeDestruct
InventoryComponent->OnInventoryUpdated.RemoveDynamic(this, &UEchoesInventoryWidget::OnInventoryUpdated);
```

## Selection System

### Single Selection

```cpp
// Get currently selected item
UEchoesInventoryItemObject* Selected = InventoryWidget->GetSelectedItem();
if (Selected)
{
    FGuid AssetId = Selected->GetAssetId();
    // Use asset ID for operations
}
```

### Blueprint Selection Events

Override in Blueprint for custom behavior:
```cpp
// OnItemSelected event in WBP_Inventory
Event OnItemSelected (ItemObject)
{
    // Highlight item in 3D world
    // Show item details panel
    // Enable/disable action buttons
}
```

## Item Move Flow

### UI Request → Component → Backend → UI Update

1. **User Action**: Click "Move" button
2. **UI Request**: `InventoryWidget->UI_RequestMoveItem(Target, Quantity)`
3. **Distance Check**: Component validates distance
4. **Backend Request**: Component sends POST to `/api/inventory/operations/move`
5. **Backend Update**: Database updated, response sent
6. **Component Refresh**: Component calls `FetchItems()`
7. **Delegate Broadcast**: `OnInventoryUpdated` triggered
8. **UI Update**: Widget repopulates ListView automatically

## Optimization Features

### ListView Advantages
- **Virtualization**: Only visible entries are rendered
- **Object Pooling**: Entry widgets are reused
- **Efficient Updates**: Only changed entries are updated

### Performance Best Practices
- No NativeTick overhead
- Event-driven updates only
- Efficient text formatting with number separators
- Lazy icon loading (implement in Blueprint)

## Blueprint Customization

### Custom Entry Appearance

Override `UpdateDisplay` in entry widget blueprint:

```cpp
// Event UpdateDisplay (ItemObject)
Event UpdateDisplay
{
    // Custom logic based on item type
    if (ItemObject->GetTypeId() == RareItemType)
    {
        // Gold border
        ItemBorder->SetBrushColor(GoldColor);
    }
    
    // Load icon asynchronously
    LoadItemIconAsync(ItemObject->GetTypeId());
}
```

### Custom Sorting

Implement in Blueprint or C++:

```cpp
// Sort items by name
void UMyWidget::SortByName()
{
    TArray<UObject*> Items = InventoryListView->GetListItems();
    Items.Sort([](const UObject& A, const UObject& B)
    {
        auto ItemA = Cast<UEchoesInventoryItemObject>(&A);
        auto ItemB = Cast<UEchoesInventoryItemObject>(&B);
        return ItemA->GetItemName() < ItemB->GetItemName();
    });
    
    InventoryListView->SetListItems(Items);
}
```

## Drag and Drop Support (Future)

The system is prepared for drag-and-drop:

```cpp
// In UEchoesInventoryEntryWidget, add:
virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
virtual void NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation*& OutOperation) override;

// In UEchoesInventoryWidget, add:
virtual bool NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;
```

## Error Handling

### Common Issues

**InventoryListView not bound**:
- Ensure ListView is named exactly "InventoryListView" in UMG
- Check BindWidget meta tag in code

**No items displaying**:
- Verify inventory component has items
- Check `FetchItems()` is being called
- Ensure entry widget class is set in ListView

**Selection not working**:
- Set ListView Selection Mode to "Single Select"
- Verify OnItemSelectionChanged binding

### Debug Logging

Enable verbose logging:
```cpp
// In code
UE_LOG(LogTemp, Log, TEXT("EchoesInventoryWidget: Populated list with %d items"), Items.Items.Num());

// In config
[Core.Log]
LogTemp=Verbose
```

## Testing Checklist

- [ ] Widget displays items from component
- [ ] Items update when inventory changes
- [ ] Selection works correctly
- [ ] Volume formatting displays correctly
- [ ] Quantity displays for stackable items
- [ ] Move request validates distance
- [ ] Move request updates UI after success
- [ ] Error messages display on failure
- [ ] Can view other actors' inventories
- [ ] Manual refresh works
- [ ] Memory cleanup on widget destruction

## Future Enhancements

1. **Icon System**: Async icon loading from database
2. **Drag and Drop**: Full drag-and-drop support
3. **Filtering**: Filter by item type, name, etc.
4. **Sorting**: Multiple sort options
5. **Search**: Text search functionality
6. **Context Menu**: Right-click actions
7. **Multi-Selection**: Select multiple items
8. **Batch Operations**: Move multiple items at once
9. **Item Preview**: 3D preview on hover
10. **Tooltips**: Detailed item information

## Configuration

### Widget Properties

```cpp
// In UEchoesInventoryWidget
UPROPERTY(EditAnywhere, Category = "Inventory")
bool bAutoRefreshOnConstruct = true;  // Auto-refresh on widget creation

UPROPERTY(EditAnywhere, Category = "Inventory")
AActor* TargetActor;  // Actor to view inventory from
```

### ListView Settings

In UMG:
- **Entry Widget Class**: WBP_InventoryEntry
- **Selection Mode**: Single Select
- **Wheel Scroll Multiplier**: 50.0
- **Navigation Padding**: 10.0

## Conclusion

The Inventory UI system provides a robust, event-driven, and efficient solution for displaying and managing inventory in Echoes MMO. The ListView-based approach ensures excellent performance even with large inventories, while the modular architecture allows for easy customization and extension.
