# Windows-Style Draggable and Resizable UI System

## Overview

This document describes the implementation of a Windows-style window system for the Echoes project, providing draggable, resizable, and focusable UI windows that can contain other widgets.

## Architecture

### Base Window Class: UEchoesWindowBase

**Files**:
- `Client/Echoes/Source/Echoes/UI/EchoesWindowBase.h`
- `Client/Echoes/Source/Echoes/UI/EchoesWindowBase.cpp`

**Inherits from**: `UUserWidget`

### Key Features

1. **Draggable Windows**: Click and drag title bar to move window
2. **Resizable Windows**: Drag bottom-right corner to resize
3. **Focus Management**: Click any part of window to bring to front (Z-order)
4. **Close Button**: X button to close/hide window
5. **Content Slot**: Named slot for embedding other widgets
6. **Position Persistence**: Save/load window positions (optional)
7. **Size Constraints**: Minimum and maximum size limits
8. **Screen Bounds**: Windows stay within viewport

## Widget Structure

### Required Widget Bindings

The Blueprint must contain these named widgets:

```
UEchoesWindowBase (Root)
├─ TitleBar (UBorder) - Draggable area
│  ├─ TitleText (UTextBlock) - Window title
│  └─ CloseButton (UButton) - Close button
├─ ContentSlot (UNamedSlot) - Content goes here
└─ ResizeHandle (UImage) - Bottom-right corner resize handle
```

### Widget Hierarchy Example

```
Canvas Panel (Root)
└─ Border (WindowBackground)
   ├─ Vertical Box
   │  ├─ Border (TitleBar) ← Draggable
   │  │  └─ Horizontal Box
   │  │     ├─ Text Block (TitleText)
   │  │     └─ Button (CloseButton) [X]
   │  ├─ Named Slot (ContentSlot) ← Content goes here
   │  └─ Image (ResizeHandle) ← Bottom-right corner
```

## Implementation Details

### Dragging Logic

**Trigger**: `NativeOnMouseButtonDown` + title bar hit test
**Process**:
1. Calculate offset from mouse to window position
2. Store offset in `DragOffset`
3. Set `bIsDragging = true`
4. Capture mouse input

**Update**: `NativeOnMouseMove`
1. Get current mouse position
2. Calculate new window position: `MousePos + DragOffset`
3. Clamp to screen bounds
4. Update `UCanvasPanelSlot::SetPosition()`

**Release**: `NativeOnMouseButtonUp`
1. Set `bIsDragging = false`
2. Release mouse capture

### Resizing Logic

**Trigger**: `NativeOnMouseButtonDown` + resize handle hit test
**Process**:
1. Store initial size in `ResizeStartSize`
2. Store mouse position in `ResizeStartMousePos`
3. Set `bIsResizing = true`
4. Capture mouse input

**Update**: `NativeOnMouseMove`
1. Calculate mouse delta: `MousePos - ResizeStartMousePos`
2. Calculate new size: `ResizeStartSize + MouseDelta`
3. Clamp to min/max size bounds
4. Update `UCanvasPanelSlot::SetSize()`

**Release**: `NativeOnMouseButtonUp`
1. Set `bIsResizing = false`
2. Release mouse capture

### Focus System

**Trigger**: `NativeOnMouseButtonDown` (any part of window)
**Process**:
1. Find highest Z-order among sibling windows
2. Set this window's Z-order to `HighestZOrder + 1`
3. Broadcast `OnWindowFocused` event

**Implementation**:
```cpp
void UEchoesWindowBase::BringToFront()
{
    UPanelWidget* Parent = GetParent();
    int32 HighestZOrder = 0;
    
    // Find highest Z-order
    for (int32 i = 0; i < Parent->GetChildrenCount(); ++i)
    {
        UWidget* Child = Parent->GetChildAt(i);
        if (UCanvasPanelSlot* ChildSlot = Cast<UCanvasPanelSlot>(Child->Slot))
        {
            HighestZOrder = FMath::Max(HighestZOrder, ChildSlot->GetZOrder());
        }
    }
    
    // Set to highest + 1
    CanvasSlot->SetZOrder(HighestZOrder + 1);
}
```

### Size Constraints

**Configuration**:
- `MinWindowSize`: Minimum width and height (default: 300x200)
- `MaxWindowSize`: Maximum width and height (0 = unlimited)

**Clamping**:
```cpp
FVector2D ClampSize(const FVector2D& Size)
{
    FVector2D Clamped = Size;
    Clamped.X = FMath::Clamp(Clamped.X, MinWindowSize.X, MaxWindowSize.X);
    Clamped.Y = FMath::Clamp(Clamped.Y, MinWindowSize.Y, MaxWindowSize.Y);
    return Clamped;
}
```

### Position Persistence (Optional)

**Saving**:
```cpp
void SaveWindowPosition()
{
    // Get current position and size
    FVector2D Position = GetWindowPosition();
    FVector2D Size = GetWindowSize();
    
    // Save to player settings/config
    // Implementation depends on your save system:
    // - UGameUserSettings
    // - Custom config file
    // - Player profile database
}
```

**Loading**:
```cpp
void LoadWindowPosition()
{
    // Load from player settings/config
    // Then apply:
    SetWindowPosition(LoadedPosition);
    SetWindowSize(LoadedSize);
}
```

## Blueprint Integration

### Creating a Window Blueprint

1. **Create Blueprint Widget**:
   - Parent Class: `UEchoesWindowBase`
   - Name: `W_WindowBase` or `W_InventoryWindow`

2. **Add Widget Hierarchy**:
   ```
   Canvas Panel
   └─ Border (WindowBackground)
      └─ Vertical Box
         ├─ Border (TitleBar)
         │  └─ Horizontal Box
         │     ├─ Text Block (TitleText)
         │     └─ Button (CloseButton)
         ├─ Named Slot (ContentSlot)
         └─ Image (ResizeHandle)
   ```

3. **Widget Binding**:
   - Ensure widget names match exactly: `TitleBar`, `TitleText`, `CloseButton`, `ResizeHandle`, `ContentSlot`

4. **Styling**:
   - TitleBar: Dark background, 30-40px height
   - ResizeHandle: 16x16px icon in bottom-right corner
   - CloseButton: X icon, red hover state

### Wrapping Existing Widgets

#### Example: Inventory Window

**W_InventoryWindow** (Blueprint):
```
UEchoesWindowBase
├─ TitleBar ← "Inventory"
├─ ContentSlot
│  └─ UEchoesInventoryWidget ← Existing inventory widget
└─ ResizeHandle
```

**Creating in Code**:
```cpp
// Create window
UEchoesWindowBase* InventoryWindow = CreateWidget<UEchoesWindowBase>(
    PlayerController, 
    InventoryWindowClass
);

// Set title
InventoryWindow->SetWindowTitle(FText::FromString("Inventory"));

// Configure
InventoryWindow->SetWindowSize(FVector2D(800, 600));
InventoryWindow->SetWindowPosition(FVector2D(100, 100));

// Add to viewport
InventoryWindow->AddToViewport();
```

#### Example: Station Menu Window

**W_StationMenuWindow** (Blueprint):
```
UEchoesWindowBase
├─ TitleBar ← Station name (dynamic)
├─ ContentSlot
│  └─ UEchoesStationMenuWidget ← Station menu
└─ ResizeHandle
```

**Opening from StationActor**:
```cpp
void AStationActor::ClientRPC_OpenStationMenu_Implementation(...)
{
    // Create window
    UEchoesWindowBase* StationWindow = CreateWidget<UEchoesWindowBase>(
        PC, 
        StationMenuWindowClass
    );
    
    // Set title to station name
    StationWindow->SetWindowTitle(FText::FromString(InStationName));
    
    // Get content widget (station menu)
    UEchoesStationMenuWidget* MenuWidget = Cast<UEchoesStationMenuWidget>(
        StationWindow->ContentSlot->GetChildAt(0)
    );
    
    if (MenuWidget)
    {
        MenuWidget->InitializeStationMenu(
            StationId, 
            InStationName, 
            InStationType, 
            InHangarStorageId
        );
    }
    
    // Add to viewport
    StationWindow->AddToViewport();
}
```

## Configuration Properties

| Property | Type | Default | Description |
|----------|------|---------|-------------|
| `MinWindowSize` | FVector2D | (300, 200) | Minimum window dimensions |
| `MaxWindowSize` | FVector2D | (0, 0) | Maximum dimensions (0 = unlimited) |
| `DefaultWindowSize` | FVector2D | (600, 400) | Initial window size |
| `DefaultWindowPosition` | FVector2D | (100, 100) | Initial window position |
| `bSavePosition` | bool | true | Enable position persistence |
| `WindowId` | FString | Auto | Unique ID for saving (auto-generated) |
| `bCanResize` | bool | true | Allow resizing |
| `bCanDrag` | bool | true | Allow dragging |

## API Reference

### Public Methods

#### Window Management
```cpp
// Close window
void CloseWindow();

// Set window title
void SetWindowTitle(const FText& Title);

// Get window title
FText GetWindowTitle() const;
```

#### Position & Size
```cpp
// Set/Get window position
void SetWindowPosition(FVector2D Position);
FVector2D GetWindowPosition() const;

// Set/Get window size
void SetWindowSize(FVector2D Size);
FVector2D GetWindowSize() const;
```

#### Focus
```cpp
// Bring window to front
void BringToFront();
```

#### Persistence
```cpp
// Save/Load window position
void SaveWindowPosition();
void LoadWindowPosition();
```

### Blueprint Events

```cpp
// Called when window is closed
UFUNCTION(BlueprintImplementableEvent)
void OnWindowClosed();

// Called when window gains focus
UFUNCTION(BlueprintImplementableEvent)
void OnWindowFocused();
```

## Advanced Usage

### Multi-Window Management

Create a window manager to track all open windows:

```cpp
UCLASS()
class UEchoesWindowManager : public UObject
{
    GENERATED_BODY()
    
public:
    // Track open windows
    TArray<UEchoesWindowBase*> OpenWindows;
    
    // Open window
    UEchoesWindowBase* OpenWindow(TSubclassOf<UEchoesWindowBase> WindowClass)
    {
        UEchoesWindowBase* Window = CreateWidget<UEchoesWindowBase>(
            GetWorld()->GetFirstPlayerController(), 
            WindowClass
        );
        
        OpenWindows.Add(Window);
        Window->AddToViewport();
        
        return Window;
    }
    
    // Close all windows
    void CloseAllWindows()
    {
        for (UEchoesWindowBase* Window : OpenWindows)
        {
            if (Window)
            {
                Window->CloseWindow();
            }
        }
        OpenWindows.Empty();
    }
};
```

### Custom Window Styles

Create derived classes for specific window types:

```cpp
UCLASS()
class UEchoesDialogWindow : public UEchoesWindowBase
{
    GENERATED_BODY()
    
public:
    UEchoesDialogWindow(const FObjectInitializer& ObjectInitializer)
        : Super(ObjectInitializer)
    {
        // Dialogs can't be resized
        bCanResize = false;
        
        // Fixed size
        MinWindowSize = FVector2D(400, 200);
        MaxWindowSize = FVector2D(400, 200);
        DefaultWindowSize = FVector2D(400, 200);
    }
};
```

### Keyboard Shortcuts

Add keyboard shortcuts in Blueprint:

```
Event OnKeyDown
├─ Key: Escape → CloseWindow()
├─ Key: F → BringToFront()
```

## Performance Considerations

- **Canvas Panel Required**: Window must be child of UCanvasPanel for position/size manipulation
- **Mouse Capture**: Mouse is captured during drag/resize to prevent losing input
- **Z-Order Updates**: Only recalculated on window click, not every frame
- **Geometry Caching**: Widget geometries are cached and reused

## Troubleshooting

### Window Won't Drag
- Ensure window is in a Canvas Panel
- Check TitleBar widget is bound correctly
- Verify bCanDrag = true

### Window Won't Resize
- Ensure ResizeHandle widget is visible
- Check bCanResize = true
- Verify MinWindowSize allows resizing

### Window Goes Off-Screen
- Check ClampPositionToScreen() is working
- Verify viewport size is being calculated correctly
- Use SetWindowPosition() with valid coordinates

### Z-Order Not Working
- Ensure all windows are children of same Canvas Panel
- Check GetParent() returns valid panel
- Verify Canvas Panel Slots are valid

## Future Enhancements

- [ ] Snap-to-edge functionality
- [ ] Window minimize/maximize
- [ ] Multi-monitor support
- [ ] Window groups/tabs
- [ ] Animation on open/close
- [ ] Custom resize cursors
- [ ] Window shadows
- [ ] Title bar double-click to maximize
- [ ] Alt+drag to move from anywhere
- [ ] Window memory system (remember all windows)

## Example Implementations

See the following files for complete examples:
- `W_InventoryWindow.uasset` - Inventory wrapped in window
- `W_StationMenuWindow.uasset` - Station menu in window
- `BP_WindowManager.uasset` - Window manager implementation
