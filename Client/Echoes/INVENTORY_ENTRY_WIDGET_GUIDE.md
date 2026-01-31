# Visual Structure Guide: W_InventoryEntry (Entry Widget)

## Widget Blueprint Structure

```
┌─────────────────────────────────────────────────────────────────────────┐
│ W_InventoryEntry (UEchoesInventoryEntryWidget)                          │
│                                                                           │
│ Canvas Panel                                                              │
│ └─ Horizontal Box (Fill: 1.0, Padding: 5px)                             │
│     ├─ Image "ItemIcon" (Size: 64x64px)                                 │
│     │   ├─ Size: Fixed 64x64                                            │
│     │   ├─ Brush: Default icon or transparent                           │
│     │   └─ Tint: White (1,1,1,1)                                        │
│     │                                                                     │
│     ├─ Vertical Box (Fill: 1.0, Padding: Left 10px)                     │
│     │   ├─ TextBlock "ItemNameText"                                     │
│     │   │   ├─ Font: Bold, Size 14                                      │
│     │   │   ├─ Color: White                                             │
│     │   │   └─ Text: "Item Name Here"                                   │
│     │   │                                                                 │
│     │   └─ TextBlock "QuantityText"                                     │
│     │       ├─ Font: Regular, Size 12                                   │
│     │       ├─ Color: Light Gray (0.7,0.7,0.7,1)                        │
│     │       └─ Text: "x5"                                                │
│     │                                                                     │
│     └─ TextBlock "VolumeText" (Align: Right)                            │
│         ├─ Font: Regular, Size 12                                       │
│         ├─ Color: Cyan (0,0.8,1,1)                                      │
│         └─ Text: "1,205.0 m³"                                            │
└─────────────────────────────────────────────────────────────────────────┘
```

## Layout Diagram

```
┌──────────────────────────────────────────────────────────┐
│  [Icon]  Item Name                    1,205.0 m³         │
│          x5                                               │
└──────────────────────────────────────────────────────────┘
 64x64px   ← Flexible →                  ← Fixed →
```

## Detailed Component Properties

### 1. Canvas Panel (Root)
- **Size**: Auto (stretches to list view width)
- **Z-Order**: 0

### 2. Horizontal Box (Main Container)
- **Slot**: Fill
- **Padding**: 5px all sides
- **Spacing**: 10px between children
- **Vertical Alignment**: Center

### 3. Image "ItemIcon"
- **Name**: `ItemIcon` (MUST match BindWidget)
- **Size**: Fixed 64x64
- **Appearance**:
  - Brush: Default or placeholder
  - Tint: (1, 1, 1, 1)
  - Draw As: Image
- **Slot Settings**:
  - Auto Size: false
  - Size: 64 x 64

### 4. Vertical Box (Info Container)
- **Slot**: Fill (Horizontal)
- **Vertical Alignment**: Center
- **Spacing**: 2px

### 5. TextBlock "ItemNameText"
- **Name**: `ItemNameText` (MUST match BindWidget)
- **Font**: Bold, 14pt
- **Color**: (1, 1, 1, 1) - White
- **Justification**: Left
- **Auto Wrap**: Yes
- **Slot**: Auto

### 6. TextBlock "QuantityText"
- **Name**: `QuantityText` (MUST match BindWidget)
- **Font**: Regular, 12pt
- **Color**: (0.7, 0.7, 0.7, 1) - Light Gray
- **Justification**: Left
- **Slot**: Auto

### 7. TextBlock "VolumeText"
- **Name**: `VolumeText` (MUST match BindWidget)
- **Font**: Regular, 12pt
- **Color**: (0, 0.8, 1, 1) - Cyan
- **Justification**: Right
- **Slot**: Auto
- **Horizontal Alignment**: Right

## Color Scheme

```
┌─────────────────────────────────────────────────────┐
│ Background:     Transparent or Semi-transparent     │
│                 (0, 0, 0, 0.2) for hover            │
├─────────────────────────────────────────────────────┤
│ Item Name:      White (1, 1, 1, 1)                  │
│ Quantity:       Light Gray (0.7, 0.7, 0.7, 1)       │
│ Volume:         Cyan (0, 0.8, 1, 1)                 │
│ Icon Border:    Dark Gray (0.2, 0.2, 0.2, 1)        │
├─────────────────────────────────────────────────────┤
│ Selected:       Blue Tint (0, 0.5, 1, 0.3)          │
│ Hovered:        Light Blue (0.3, 0.6, 1, 0.2)       │
└─────────────────────────────────────────────────────┘
```

## Selection States

### Normal State
```
┌──────────────────────────────────────────────────────────┐
│  [Icon]  Tritanium                      120.5 m³         │
│          x100                                             │
└──────────────────────────────────────────────────────────┘
Background: Transparent
Border: None
```

### Hovered State
```
┌──────────────────────────────────────────────────────────┐
│  [Icon]  Tritanium                      120.5 m³         │ ← Light blue bg
│          x100                                             │
└──────────────────────────────────────────────────────────┘
Background: (0.3, 0.6, 1, 0.2)
Cursor: Hand
```

### Selected State
```
╔══════════════════════════════════════════════════════════╗ ← Blue border
║  [Icon]  Tritanium                      120.5 m³         ║
║          x100                                             ║
╚══════════════════════════════════════════════════════════╝
Background: (0, 0.5, 1, 0.3)
Border: 2px solid blue
```

## Animation (Optional)

### Hover Animation
```cpp
// Fade in background over 0.1s
Timeline: 0s → 0.1s
Background Alpha: 0 → 0.2
Scale: 1.0 → 1.02
```

### Selection Animation
```cpp
// Quick flash on selection
Timeline: 0s → 0.05s → 0.1s
Border Alpha: 0 → 1 → 1
Background Alpha: 0 → 0.3 → 0.3
```

## Example Implementations

### Minimal Entry
```
┌─────────────────────────────────────┐
│ ▣ Tritanium                120.5 m³ │
└─────────────────────────────────────┘
```

### Full Entry with Icons
```
┌──────────────────────────────────────────────────┐
│ ┌────┐                                           │
│ │ 🔹 │  Tritanium                     120.5 m³   │
│ └────┘  x100                                     │
└──────────────────────────────────────────────────┘
```

### Stacked Items Entry
```
┌──────────────────────────────────────────────────┐
│ ┌────┐                                           │
│ │ 📦 │  Exotic Ore Crate              1,205.0 m³ │
│ └────┘  x5                                       │
└──────────────────────────────────────────────────┘
```

### Singleton Items (Non-stackable)
```
┌──────────────────────────────────────────────────┐
│ ┌────┐                                           │
│ │ ⚔️ │  Enhanced Weapon Module        50.0 m³    │
│ └────┘  x1                                       │
└──────────────────────────────────────────────────┘
```

## Blueprint Event Graph Setup

### UpdateDisplay Event
```
Event UpdateDisplay (ItemObject)
    │
    ├─→ Branch: IsValid(ItemObject)
    │   │
    │   ├─→ [Yes] Get TypeId
    │   │   │
    │   │   └─→ Load Icon Async (by TypeId)
    │   │       │
    │   │       └─→ On Loaded → Set Brush to ItemIcon
    │   │
    │   └─→ [No] Set Default Icon
    │
    └─→ Branch: IsStackable
        │
        ├─→ [Yes] Show QuantityText
        │
        └─→ [No] Hide QuantityText or show "x1"
```

### OnEntrySelected Event
```
Event OnEntrySelected
    │
    ├─→ Play Animation: "SelectionFlash"
    │
    ├─→ Set Border Brush: BlueBorder
    │
    └─→ Set Background Color: SelectedBlue
```

### OnEntryDeselected Event
```
Event OnEntryDeselected
    │
    ├─→ Stop Animation: "SelectionFlash"
    │
    ├─→ Set Border Brush: NoBorder
    │
    └─→ Set Background Color: Transparent
```

## C++ to UMG Binding

### Required Widget Names
These MUST match exactly in UMG:

```cpp
// In UEchoesInventoryEntryWidget.h
UPROPERTY(meta = (BindWidget))
UImage* ItemIcon;              // Widget name: "ItemIcon"

UPROPERTY(meta = (BindWidget))
UTextBlock* ItemNameText;      // Widget name: "ItemNameText"

UPROPERTY(meta = (BindWidget))
UTextBlock* QuantityText;      // Widget name: "QuantityText"

UPROPERTY(meta = (BindWidget))
UTextBlock* VolumeText;        // Widget name: "VolumeText"
```

### Optional: Make Bindings Optional
```cpp
// Use BindWidgetOptional if widget might not exist
UPROPERTY(meta = (BindWidgetOptional))
UImage* ItemIcon;
```

## Responsive Design

### Small Width (< 300px)
```
┌──────────────────────────┐
│ [I] Item Name            │
│     x5    120.5 m³       │
└──────────────────────────┘
Icon: 32x32
Font: 12pt
```

### Medium Width (300-600px)
```
┌─────────────────────────────────────┐
│ [Icon] Item Name          120.5 m³  │
│        x5                            │
└─────────────────────────────────────┘
Icon: 48x48
Font: 13pt
```

### Large Width (> 600px)
```
┌──────────────────────────────────────────────────┐
│ [Icon]  Item Name                     120.5 m³   │
│         x5                                       │
└──────────────────────────────────────────────────┘
Icon: 64x64
Font: 14pt
```

## Accessibility

### Screen Reader Support
```cpp
// Set accessible text
ItemNameText->SetAccessibleText(FText::FromString("Item: " + ItemName));
VolumeText->SetAccessibleText(FText::FromString("Volume: " + Volume));
```

### Keyboard Navigation
- Tab: Navigate to next item
- Shift+Tab: Navigate to previous item
- Space/Enter: Select item
- Arrow Keys: Navigate list

## Testing Checklist

Widget Creation:
- [ ] All required widgets are named correctly
- [ ] BindWidget properties connect successfully
- [ ] Widget compiles without errors
- [ ] Parent class is set to UEchoesInventoryEntryWidget

Visual Display:
- [ ] Item name displays correctly
- [ ] Quantity shows for stackable items
- [ ] Volume formatting includes "m³" suffix
- [ ] Icon displays (or placeholder shows)
- [ ] Text is readable on background

Interactivity:
- [ ] Entry responds to hover
- [ ] Selection changes appearance
- [ ] OnEntrySelected event fires
- [ ] UpdateDisplay event executes

Performance:
- [ ] No lag with 100+ items in list
- [ ] Scrolling is smooth
- [ ] Memory usage is reasonable

## Common Issues

**"Failed to find widget named 'ItemIcon'"**
- Solution: Ensure widget in UMG is named exactly "ItemIcon"

**Text is cut off**
- Solution: Enable Auto Wrap on text blocks
- Solution: Increase container width

**Icon not showing**
- Solution: Check brush is set correctly
- Solution: Verify icon texture is loaded
- Solution: Check image size constraints

**Selection doesn't work**
- Solution: Implement IUserObjectListEntry interface
- Solution: Override NativeOnListItemObjectSet

## Next Steps

After creating the entry widget:
1. Create main inventory widget (W_Inventory)
2. Add ListView component
3. Set entry widget class
4. Test with sample data
5. Customize appearance
6. Add animations
7. Implement drag-and-drop (optional)
